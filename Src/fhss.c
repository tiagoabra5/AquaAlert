/**
  * @file    fhss.c
  * @brief   Salto de frequencia (FHSS) do AquaAlert. Ver fhss.h.
  */
#include "fhss.h"
#include "aquaalert_rf.h"

#if AA_FHSS_CHANNELS < 50
#error "Regra de salto (20 dB BW < 250 kHz) exige pelo menos 50 canais"
#endif

#define DWELL_LOG_LEN  16U

typedef struct
{
  uint32_t start;   /* HAL_GetTick() do inicio da varredura */
  uint32_t dwell;   /* ms ocupados em cada canal por essa varredura */
} DwellEntry;

static uint8_t    sHop[AA_FHSS_CHANNELS];
static uint32_t   sRng = 1;
static DwellEntry sLog[DWELL_LOG_LEN];
static uint8_t    sLogNext = 0;

/* xorshift32: suficiente para ordem de canais (nao e uso criptografico). */
static uint32_t Rand(void)
{
  sRng ^= sRng << 13;
  sRng ^= sRng >> 17;
  sRng ^= sRng << 5;
  return sRng;
}

void FHSS_Init(uint32_t seed)
{
  sRng = (seed != 0U) ? seed : 0x2545F491UL;

  for (uint8_t i = 0; i < AA_FHSS_CHANNELS; i++)
  {
    sHop[i] = i;
  }
  /* Fisher-Yates */
  for (uint8_t i = AA_FHSS_CHANNELS - 1U; i > 0U; i--)
  {
    uint8_t j = (uint8_t)(Rand() % (uint32_t)(i + 1U));
    uint8_t t = sHop[i];
    sHop[i] = sHop[j];
    sHop[j] = t;
  }

  for (uint8_t i = 0; i < DWELL_LOG_LEN; i++)
  {
    sLog[i].start = 0;
    sLog[i].dwell = 0;
  }
}

uint8_t FHSS_SweepChannel(uint8_t start, uint8_t i)
{
  return sHop[(uint8_t)((start + i) % AA_FHSS_CHANNELS)];
}

uint8_t FHSS_RandomChannel(void)
{
  return (uint8_t)(Rand() % AA_FHSS_CHANNELS);
}

uint32_t FHSS_AirtimeMs(uint8_t payloadLen)
{
  /* Campo de comprimento (1 byte) + payload + CRC. */
  uint32_t crcBytes = (AA_CRC_MODE == PKT_CRC_MODE_8BITS) ? 1U
                    : (AA_CRC_MODE == PKT_NO_CRC) ? 0U : 2U;
  uint32_t body = 1U + payloadLen + crcBytes;

  if (AA_FEC == S_ENABLE)
  {
    /* Taxa 1/2 + terminacao da trelica, arredondado ao bloco do interleaver. */
    body = ((2U * body + 4U) + 3U) & ~3U;
  }

  uint32_t bits = 8U * (AA_PREAMBLE_BYTES + AA_SYNC_BYTES + body);
  uint32_t ms = (bits * 1000U + AA_DATARATE - 1U) / AA_DATARATE;

  /* +20 % de margem e +5 ms de comutacao do sintetizador/FEM. */
  return ms + ms / 5U + 5U;
}

uint8_t FHSS_SweepAllowed(uint32_t nowMs, uint32_t dwellMs)
{
  uint32_t used = 0;

  for (uint8_t i = 0; i < DWELL_LOG_LEN; i++)
  {
    if (sLog[i].dwell != 0U && (nowMs - sLog[i].start) < AA_FHSS_WINDOW_MS)
    {
      used += sLog[i].dwell;
    }
  }
  return (used + dwellMs <= AA_FHSS_MAX_DWELL_MS) ? 1U : 0U;
}

void FHSS_RecordSweep(uint32_t nowMs, uint32_t dwellMs)
{
  sLog[sLogNext].start = nowMs;
  sLog[sLogNext].dwell = dwellMs;
  sLogNext = (uint8_t)((sLogNext + 1U) % DWELL_LOG_LEN);
}
