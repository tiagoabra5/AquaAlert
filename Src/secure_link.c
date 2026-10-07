/**
  * @file    secure_link.c
  * @brief   Enlace de radio cifrado (ECDH X25519 + XSalsa20-Poly1305).
  */
#include "secure_link.h"
#include "ecc_keys.h"
#include "cube_hal.h"
#include <string.h>

#if (ECC_NUM_NODES < 2) || (ECC_NUM_NODES > 254)
#error "ECC_NUM_NODES deve estar entre 2 e 254"
#endif
#if (NODE_ID < 1) || (NODE_ID > ECC_NUM_NODES)
#error "NODE_ID fora da faixa 1..ECC_NUM_NODES"
#endif

/* Contador de boot persistente: duas ultimas paginas (2 x 2 KB) do banco 2,
 * reservadas no linker script. Cada boot grava um registro de 64 bits
 * (contador | ~contador << 32); as paginas sao usadas alternadamente para que
 * uma queda de energia durante o apagamento nao perca o ultimo valor. */
#define BOOTCTR_BANK        FLASH_BANK_2
#define BOOTCTR_FIRST_PAGE  254U
#define BOOTCTR_PAGES       2U
#define BOOTCTR_BASE        (FLASH_BASE + 0x100000UL - BOOTCTR_PAGES * FLASH_PAGE_SIZE)
#define BOOTCTR_SLOTS       (FLASH_PAGE_SIZE / 8U)
#define BOOTCTR_ERASED      0xFFFFFFFFFFFFFFFFULL

/* Diagnostico: adicione em Window > Show View > Live Expressions no depurador. */
volatile SL_Status gSlInitStatus = SL_OK;
volatile int32_t   gSlSelfTestCode = 0;  /* retorno de ecc_self_test() */
volatile uint32_t  gSlFlashStep = 0;     /* 1 = apagar, 2 = gravar, 3 = conferir */
volatile uint32_t  gSlFlashError = 0;    /* HAL_FLASH_GetError() */
volatile uint32_t  gSlBootCounter = 0;

static uint8_t  sReady = 0;
static uint32_t sBootCounter = 0;
static uint32_t sMsgCounter = 0;
static uint8_t  sPeerKey[ECC_NUM_NODES][ECC_KEY_LEN];
static uint64_t sPeerLastRx[ECC_NUM_NODES];

static const volatile uint64_t *BootCtrSlot(uint32_t page, uint32_t slot)
{
  return (const volatile uint64_t *)(BOOTCTR_BASE + page * FLASH_PAGE_SIZE + slot * 8U);
}

static int BootCtrDecode(uint64_t v, uint32_t *value)
{
  uint32_t lo = (uint32_t)v;
  uint32_t hi = (uint32_t)(v >> 32);
  if (v == BOOTCTR_ERASED || hi != (uint32_t)~lo)
  {
    return 0;
  }
  *value = lo;
  return 1;
}

static SL_Status BootCtrWrite(uint32_t page, uint32_t slot, int erasePage)
{
  HAL_StatusTypeDef st = HAL_OK;
  uint32_t value = 0;
  uint64_t rec = (uint64_t)sBootCounter | ((uint64_t)(uint32_t)~sBootCounter << 32);

  HAL_FLASH_Unlock();
  __HAL_FLASH_CLEAR_FLAG(FLASH_FLAG_ALL_ERRORS);

  if (erasePage)
  {
    FLASH_EraseInitTypeDef erase = {0};
    uint32_t pageError = 0;
    erase.TypeErase = FLASH_TYPEERASE_PAGES;
    erase.Banks = BOOTCTR_BANK;
    erase.Page = BOOTCTR_FIRST_PAGE + page;
    erase.NbPages = 1;
    gSlFlashStep = 1;
    st = HAL_FLASHEx_Erase(&erase, &pageError);
  }
  if (st == HAL_OK)
  {
    gSlFlashStep = 2;
    st = HAL_FLASH_Program(FLASH_TYPEPROGRAM_DOUBLEWORD, (uint32_t)BootCtrSlot(page, slot), rec);
  }
  if (st != HAL_OK)
  {
    gSlFlashError = HAL_FLASH_GetError();
  }
  HAL_FLASH_Lock();

  if (st != HAL_OK)
  {
    return SL_ERR_FLASH;
  }
  gSlFlashStep = 3;
  if (!BootCtrDecode(*BootCtrSlot(page, slot), &value) || value != sBootCounter)
  {
    return SL_ERR_FLASH;
  }
  gSlFlashStep = 0;
  return SL_OK;
}

static SL_Status BootCounterAdvance(void)
{
  uint32_t last = 0, value, lastPage = 0;
  uint32_t freeSlot[BOOTCTR_PAGES];

  for (uint32_t p = 0; p < BOOTCTR_PAGES; p++)
  {
    freeSlot[p] = BOOTCTR_SLOTS;
    for (uint32_t s = 0; s < BOOTCTR_SLOTS; s++)
    {
      uint64_t v = *BootCtrSlot(p, s);
      if (v == BOOTCTR_ERASED)
      {
        freeSlot[p] = s;
        break;
      }
      if (BootCtrDecode(v, &value) && value > last)
      {
        last = value;
        lastPage = p;
      }
    }
  }

  if (last >= 0xFFFFFFFEUL)
  {
    return SL_ERR_FLASH;
  }
  sBootCounter = last + 1U;
  gSlBootCounter = sBootCounter;

  uint32_t page = lastPage;
  uint32_t slot = freeSlot[page];

  if (slot < BOOTCTR_SLOTS && BootCtrWrite(page, slot, 0) == SL_OK)
  {
    return SL_OK;
  }
  /* Pagina atual cheia (ou slot com falha): apaga a outra pagina e grava nela.
   * O valor mais alto continua preservado na pagina atual ate la. */
  return BootCtrWrite((page + 1U) % BOOTCTR_PAGES, 0, 1);
}

static void BuildNonce(uint8_t nonce[ECC_NONCE_LEN], const uint8_t *header)
{
  memset(nonce, 0, ECC_NONCE_LEN);
  memcpy(nonce, header, SL_HEADER_LEN);
}

static SL_Status InitSteps(void)
{
  sReady = 0;
  gSlSelfTestCode = ecc_self_test();
  if (gSlSelfTestCode != 0)
  {
    return SL_ERR_SELFTEST;
  }

  for (uint8_t i = 0; i < ECC_NUM_NODES; i++)
  {
    sPeerLastRx[i] = 0;
    if (i == NODE_ID - 1)
    {
      memset(sPeerKey[i], 0, ECC_KEY_LEN);
      continue;
    }
    if (ecc_shared_key(sPeerKey[i], ECC_NODE_PRIVATE_KEY, ECC_NODE_PUBLIC_KEYS[i]) != 0)
    {
      return SL_ERR_KEY;
    }
  }

  return BootCounterAdvance();
}

SL_Status SL_Init(void)
{
  SL_Status status = InitSteps();
  gSlInitStatus = status;
  if (status == SL_OK)
  {
    sMsgCounter = 0;
    sReady = 1;
  }
  return status;
}

uint8_t SL_GetNodeId(void)
{
  return NODE_ID;
}

uint8_t SL_GetNodeCount(void)
{
  return ECC_NUM_NODES;
}

SL_Status SL_Seal(uint8_t dst, const uint8_t *pt, uint8_t ptLen,
                  uint8_t *frame, uint8_t *frameLen)
{
  uint8_t nonce[ECC_NONCE_LEN];
  uint64_t counter;

  if (!sReady || dst < 1 || dst > ECC_NUM_NODES || dst == NODE_ID
      || ptLen == 0 || ptLen > SL_PLAINTEXT_MAX)
  {
    return SL_ERR_PARAM;
  }
  if (sMsgCounter == 0xFFFFFFFFUL)
  {
    return SL_ERR_COUNTER;
  }
  sMsgCounter++;
  counter = ((uint64_t)sBootCounter << 32) | sMsgCounter;

  frame[0] = SL_MAGIC;
  frame[1] = SL_VERSION;
  frame[2] = NODE_ID;
  frame[3] = dst;
  for (int i = 0; i < 8; i++)
  {
    frame[4 + i] = (uint8_t)(counter >> (8 * i));
  }

  BuildNonce(nonce, frame);
  ecc_seal(&frame[SL_HEADER_LEN], &frame[SL_HEADER_LEN + ptLen], pt, ptLen,
           nonce, sPeerKey[dst - 1]);
  *frameLen = (uint8_t)SL_FRAME_LEN(ptLen);
  return SL_OK;
}

SL_Status SL_Open(const uint8_t *frame, uint8_t frameLen,
                  uint8_t *src, uint8_t *pt, uint8_t *ptLen)
{
  uint8_t nonce[ECC_NONCE_LEN];
  uint64_t counter = 0;
  uint8_t from, len;

  if (!sReady)
  {
    return SL_ERR_PARAM;
  }
  if (frameLen < SL_FRAME_LEN(1) || frameLen > SL_FRAME_MAX
      || frame[0] != SL_MAGIC || frame[1] != SL_VERSION)
  {
    return SL_ERR_FORMAT;
  }
  if (frame[3] != NODE_ID)
  {
    return SL_ERR_NOT_FOR_ME;
  }
  from = frame[2];
  if (from < 1 || from > ECC_NUM_NODES || from == NODE_ID)
  {
    return SL_ERR_UNKNOWN_PEER;
  }
  for (int i = 0; i < 8; i++)
  {
    counter |= (uint64_t)frame[4 + i] << (8 * i);
  }
  if (counter <= sPeerLastRx[from - 1])
  {
    return SL_ERR_REPLAY;
  }

  len = (uint8_t)(frameLen - SL_FRAME_LEN(0));
  BuildNonce(nonce, frame);
  if (ecc_open(pt, &frame[SL_HEADER_LEN], len, &frame[SL_HEADER_LEN + len],
               nonce, sPeerKey[from - 1]) != 0)
  {
    return SL_ERR_AUTH;
  }

  /* So atualiza a janela anti-replay depois que o quadro foi autenticado. */
  sPeerLastRx[from - 1] = counter;
  *src = from;
  *ptLen = len;
  return SL_OK;
}
