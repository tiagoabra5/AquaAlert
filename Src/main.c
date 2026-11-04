#include "cube_hal.h"
#include "radio_shield_config.h"
#include "radio_appli.h"
#include "radio_gpio.h"
#include "s2lp_interface.h"
#include "secure_link.h"
#include "aquaalert_rf.h"
#include "fhss.h"


#define TRIGGER_BYTE        0xAA
#define TX_PAYLOAD_LEN       SL_FRAME_LEN(1)
#define RX_BUFFER_SIZE       128   /* tamanho da FIFO RX do S2-LP */

#define RADIO_CHECK_MS       250   /* periodo da verificacao de seguranca do radio */
#define BUTTON_RELEASE_MS    150   /* botao solto por este tempo para rearmar (debounce) */

/* Preambulo em pares de bits e sync em bits, como o S2-LP espera. */
#define PREAMBLE_PAIRS(bytes)  ((bytes) * 4U)
#define SYNC_BITS(bytes)       ((bytes) * 8U)


static SRadioInit xAppRadioInit = {
  AA_FHSS_BASE_HZ,
  AA_MODULATION,
  AA_DATARATE,
  AA_FREQ_DEV,
  AA_CHANNEL_BW
};

static PktBasicInit xAppBasicInit = {
  .xPreambleLength = PREAMBLE_PAIRS(AA_PREAMBLE_BYTES),
  .xSyncLength = SYNC_BITS(AA_SYNC_BYTES),
  .lSyncWords = AA_SYNC_WORD,
  .xFixVarLength = S_ENABLE,          /* comprimento variavel */
  .cExtendedPktLenField = S_DISABLE,
  .xCrcMode = AA_CRC_MODE,
  .xAddressField = S_DISABLE,
  .xFec = AA_FEC,
  .xDataWhitening = AA_WHITENING
};

static SGpioInit xAppGpioIrq = {
  S2LP_GPIO_3,
  S2LP_GPIO_MODE_DIGITAL_OUTPUT_LP,
  S2LP_GPIO_DIG_OUT_IRQ
};

static uint8_t aTxBuffer[SL_FRAME_MAX] = { 0 };
static uint8_t aRxBuffer[RX_BUFFER_SIZE] = { 0 };


volatile uint8_t  gButtonPressed = 0;
volatile uint32_t gButtonTick    = 0;   /* HAL_GetTick() da ultima borda do botao */
volatile uint8_t  gRadioIrq      = 0;

/* Contador de boot do secure_link (Src/secure_link.c), usado so como semente. */
extern volatile uint32_t gSlBootCounter;


static void RadioInitAll(void);
static void EnterRxMode(void);
static void HandleRadioIrq(void);
static void TransmitTrigger(void);
static void TransmitOnChannel(uint8_t channel, uint8_t *frame, uint8_t len);
static void SecurityFault(SL_Status code);
static void RadioToReady(void);
static void ConfigureRxPath(void);
static void ProcessButton(uint32_t now);
static void ParkOnNewChannel(uint32_t now);
static uint32_t AlertDwellMs(void);

/* Diagnostico do radio: adicione em Live Expressions no depurador. */
volatile uint32_t  gTxOk = 0;        /* copias enviadas (uma por canal por destino) */
volatile uint32_t  gTxFail = 0;      /* copia nao enviada (canal ocupado/timeout) */
volatile uint32_t  gRxOk = 0;        /* quadros aceitos */
volatile uint32_t  gRxRejected = 0;  /* quadros recusados pelo secure_link (inclui copias repetidas) */
volatile SL_Status gLastRxStatus = SL_OK;
volatile uint32_t  gRxRearm = 0;     /* vezes que o radio teve de ser recolocado em RX */
volatile uint32_t  gSweeps = 0;      /* alertas enviados (varreduras completas) */
volatile uint32_t  gSweepDeferred = 0; /* alertas adiados pelo limite de ocupacao do canal */
volatile uint8_t   gParkChannel = 0; /* canal em que este no esta escutando */
volatile int32_t   gLastRssi = 0;    /* RSSI (dBm, na entrada do S2-LP) do ultimo quadro aceito */
volatile uint32_t  gTxTimeout = 0;
volatile uint32_t  gTxCcaBusy = 0;
volatile uint32_t  gTxFifoError = 0;

/* Diagnostico do front-end (FEM): adicione em Live Expressions no depurador.
 * gRangeExt : 3 = SKY66420 reconhecido; 0 = nenhum extensor de alcance detectado.
 * gHasEeprom: 1 = EEPROM da placa de radio foi lida; 0 = nao foi lida.
 * 0xFF = ainda nao preenchido (S2LPInterfaceInit ainda nao rodou). */
volatile uint8_t   gRangeExt  = 0xFF;
volatile uint8_t   gHasEeprom = 0xFF;

static uint8_t  sAlertPending = 0;
static uint8_t  sButtonArmed = 1;
static uint8_t  sButtonReleased = 0;
static uint32_t sReleasedSince = 0;
static uint32_t sArmedAt = 0;
static uint32_t sParkSince = 0;


int main(void)
{
  HAL_Init();


  SystemClock_Config();


  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();
  __HAL_RCC_GPIOC_CLK_ENABLE();


  BSP_LED_Init(LED2);
  BSP_LED_Off(LED2);
  BSP_PB_Init(BUTTON_KEY, BUTTON_MODE_EXTI);

  /* Auto-teste e derivacao das chaves ECC (LD2 aceso enquanto calcula). */
  BSP_LED_On(LED2);
  SL_Status slStatus = SL_Init();
  if (slStatus != SL_OK)
  {
    SecurityFault(slStatus);
  }
  BSP_LED_Off(LED2);

  /* Semente da ordem dos canais: ID unico do chip + contador de boot, para
   * que cada placa (e cada boot) use uma sequencia diferente. */
  const volatile uint32_t *uid = (const volatile uint32_t *)UID_BASE;
  FHSS_Init(uid[0] ^ (uid[1] * 2654435761UL) ^ uid[2] ^ (gSlBootCounter << 16) ^ SL_GetNodeId());


  S2LPInterfaceInit();

  /* Diagnostico: registra o que a identificacao da placa de radio encontrou. */
  gRangeExt  = (uint8_t)S2LPManagementGetRangeExtender();
  gHasEeprom = (uint8_t)RadioGetHasEeprom();

  xAppRadioInit.lFrequencyBase = AA_FHSS_BASE_HZ + S2LPManagementGetOffset();


  RadioInitAll();

  ParkOnNewChannel(HAL_GetTick());
  sArmedAt = HAL_GetTick();

  uint32_t lastRadioCheck = HAL_GetTick();
  while (1)
  {
    uint32_t now = HAL_GetTick();

    ProcessButton(now);

    if (sAlertPending)
    {
      if (FHSS_SweepAllowed(now, AlertDwellMs()))
      {
        sAlertPending = 0;
        TransmitTrigger();
        EnterRxMode();
      }
      /* Senao, espera a janela de ocupacao liberar (o alerta nao se perde). */
    }

    if (gRadioIrq)
    {
      gRadioIrq = 0;
      HandleRadioIrq();
    }

    if ((now - sParkSince) >= AA_FHSS_PARK_MS)
    {
      ParkOnNewChannel(now);
    }

    if ((HAL_GetTick() - lastRadioCheck) >= RADIO_CHECK_MS)
    {
      lastRadioCheck = HAL_GetTick();
      HandleRadioIrq();
      S2LPRefreshStatus();
      if (g_xStatus.MC_STATE != MC_STATE_RX)
      {
        gRxRearm++;
        EnterRxMode();
      }
    }
  }
}


/* Botao com debounce: aceita uma borda so se o botao estava armado, e so
 * rearma depois de ficar solto por BUTTON_RELEASE_MS. Repiques ao apertar e
 * ao soltar (inclusive os que chegam durante uma varredura) sao ignorados. */
static void ProcessButton(uint32_t now)
{
  if (gButtonPressed)
  {
    gButtonPressed = 0;
    if (sButtonArmed && (int32_t)(gButtonTick - sArmedAt) >= 0)
    {
      sButtonArmed = 0;
      sButtonReleased = 0;
      if (!sAlertPending)
      {
        sAlertPending = 1;
        if (!FHSS_SweepAllowed(now, AlertDwellMs()))
        {
          gSweepDeferred++;
        }
      }
    }
  }

  if (!sButtonArmed)
  {
    if (BSP_PB_GetState(BUTTON_KEY) == GPIO_PIN_SET)   /* B1 solto (ativo em nivel baixo) */
    {
      if (!sButtonReleased)
      {
        sButtonReleased = 1;
        sReleasedSince = now;
      }
      else if ((now - sReleasedSince) >= BUTTON_RELEASE_MS)
      {
        sButtonArmed = 1;
        sArmedAt = now;
      }
    }
    else
    {
      sButtonReleased = 0;
    }
  }
}

/* Ocupacao de cada canal causada por um alerta: uma copia por destino. */
static uint32_t AlertDwellMs(void)
{
  return (uint32_t)(SL_GetNodeCount() - 1U) * FHSS_AirtimeMs(TX_PAYLOAD_LEN);
}


static void RadioInitAll(void)
{
  S2LPGpioInit(&xAppGpioIrq);
  S2LPRadioInit(&xAppRadioInit);
  S2LPRadioSetChannelSpace(AA_FHSS_SPACING_HZ);
  S2LPRadioSetChannel(0);

  /* Potencia do perfil ativo em aquaalert_rf.h. Sem FEM, usa o S2-LP sozinho. */
  S2LPRadioSetMaxPALevel(S_DISABLE);
  if (S2LPManagementGetRangeExtender() == RANGE_EXT_NONE)
  {
    S2LPRadioSetPALeveldBm(AA_PA_INDEX, AA_PA_DBM_NO_FEM);
  }
  else
  {
    S2LPRadioSetPALeveldBm(AA_PA_INDEX, AA_FEM_DRIVE_DBM);
  }
  S2LPRadioSetPALevelMaxIndex(AA_PA_INDEX);

  S2LPPktBasicInit(&xAppBasicInit);
  /* O endereco e autenticado pelo secure_link; o pacote de RF nao tem
   * campo de endereco. Nao deixar filtros de endereco do chip ativos. */
  uint8_t filters;
  S2LPSpiReadRegisters(PCKT_FLT_OPTIONS_ADDR, 1, &filters);
  filters &= ~(SOURCE_ADDR_FLT_REGMASK | DEST_VS_BROADCAST_ADDR_REGMASK
               | DEST_VS_MULTICAST_ADDR_REGMASK | DEST_VS_SOURCE_ADDR_REGMASK);
  S2LPSpiWriteRegisters(PCKT_FLT_OPTIONS_ADDR, 1, &filters);
  /* Com FEC, o S2-LP transmite o sync secundario automaticamente. O RX
   * precisa reconhecer esse sync para ativar o decodificador de FEC. */
  if (AA_FEC == S_ENABLE)
  {
    S2LPSetDualSyncWords(~AA_SYNC_WORD);
    S2LPPacketHandlerSelectSecondarySync(S_ENABLE);
  }
  ConfigureRxPath();


  S2LPGpioIrqClearStatus();
  S2LP_EnableRxIrq();
  S2LP_EnableTxIrq();
  S2LPGpioIrqConfig(MAX_BO_CCA_REACH, S_ENABLE);   /* CSMA desistiu: canal ocupado */
}

/* Leva o S2-LP ao estado READY (sai de RX/TX), necessario antes de limpar FIFOs
 * e de trocar de canal. */
static void RadioToReady(void)
{
  uint32_t start = HAL_GetTick();
  S2LPCmdStrobeSabort();
  do
  {
    S2LPRefreshStatus();
  } while (g_xStatus.MC_STATE != MC_STATE_READY && (HAL_GetTick() - start) < 5U);
}

/* Configuracao de recepcao. S2LP_StartTx liga o CSMA e altera estes ajustes;
 * eles precisam ser restaurados depois de cada envio (como no exemplo da ST). */
static void ConfigureRxPath(void)
{
  S2LPCsma(S_DISABLE);
  S2LPPacketHandlerSetRxPersistentMode(S_ENABLE);
  S2LPRadioCsBlanking(S_ENABLE);
  S2LPRadioSetRssiThreshdBm(RSSI_THRESHOLD);
  S2LP_SetRxTimeout(0);   /* RX sem timeout */
}

/* Sorteia um novo canal de escuta e volta a receber nele. */
static void ParkOnNewChannel(uint32_t now)
{
  gParkChannel = FHSS_RandomChannel();
  sParkSince = now;
  EnterRxMode();
}


static void EnterRxMode(void)
{
  RadioToReady();
  S2LPRadioSetChannel(gParkChannel);
  S2LPCmdStrobeFlushRxFifo();
  S2LP_SetPayloadlength(TX_PAYLOAD_LEN);
  /* Limpa IRQs pendentes para o pino voltar ao nivel alto e a proxima
   * IRQ gerar uma nova borda de descida na EXTI. */
  S2LPGpioIrqClearStatus();
  S2LPCmdStrobeRx();
}


/* Envia uma copia do quadro num canal e espera o fim (ou desistencia do CSMA). */
static void TransmitOnChannel(uint8_t channel, uint8_t *frame, uint8_t len)
{
  RadioToReady();
  S2LPRadioSetChannel(channel);
  S2LP_SetPayloadlength(len);
  S2LPGpioIrqClearStatus();
  S2LP_StartTx(frame, len);   /* liga CSMA, carrega a FIFO e transmite (FEM em TX) */

  uint32_t start = HAL_GetTick();
  uint8_t sent = 0;
  S2LPIrqs xIrqStatus;
  do
  {
    S2LPGpioIrqGetStatus(&xIrqStatus);
    if (xIrqStatus.IRQ_TX_DATA_SENT)
    {
      sent = 1;
      break;
    }
    if (xIrqStatus.IRQ_MAX_BO_CCA_REACH)
    {
      gTxCcaBusy++;
      break;
    }
    if (xIrqStatus.IRQ_TX_FIFO_ERROR)
    {
      gTxFifoError++;
      break;
    }
  } while ((HAL_GetTick() - start) < AA_TX_TIMEOUT_MS);

  if (sent)
  {
    gTxOk++;
  }
  else
  {
    gTxFail++;
    if (!xIrqStatus.IRQ_MAX_BO_CCA_REACH && !xIrqStatus.IRQ_TX_FIFO_ERROR)
    {
      gTxTimeout++;
    }
  }
}


/* Alerta com salto de frequencia: para cada destino, sela o quadro UMA vez
 * (mesmo contador) e envia uma copia em cada um dos AA_FHSS_CHANNELS canais,
 * numa ordem pseudoaleatoria. O destino, escutando em algum desses canais,
 * recebe a sua copia; as demais copias que ele vier a ouvir sao recusadas
 * como repetidas pelo anti-replay. */
static void TransmitTrigger(void)
{
  const uint8_t command = TRIGGER_BYTE;
  uint8_t frameLen = 0;

  FHSS_RecordSweep(HAL_GetTick(), AlertDwellMs());
  gSweeps++;

  for (uint8_t dst = 1; dst <= SL_GetNodeCount(); dst++)
  {
    if (dst == SL_GetNodeId()
        || SL_Seal(dst, &command, sizeof(command), aTxBuffer, &frameLen) != SL_OK)
    {
      continue;
    }

    uint8_t startIdx = FHSS_RandomChannel();
    for (uint8_t i = 0; i < AA_FHSS_CHANNELS; i++)
    {
      TransmitOnChannel(FHSS_SweepChannel(startIdx, i), aTxBuffer, frameLen);
    }
  }

  /* Sai do TX (ou do CSMA que desistiu) e restaura a configuracao de RX. */
  RadioToReady();
  ConfigureRxPath();
}


static void HandleRadioIrq(void)
{
  S2LPIrqs xIrqStatus;
  S2LPGpioIrqGetStatus(&xIrqStatus);

  if (xIrqStatus.IRQ_RX_DATA_READY)
  {
    uint8_t rxLen = 0;
    uint8_t src = 0;
    uint8_t plain[SL_PLAINTEXT_MAX];
    uint8_t plainLen = 0;
    S2LP_GetRxPacket(aRxBuffer, &rxLen);

    /* Quadros nao autenticados (no desconhecido, adulterado, repetido) sao descartados. */
    gLastRxStatus = SL_Open(aRxBuffer, rxLen, &src, plain, &plainLen);
    if (gLastRxStatus == SL_OK)
    {
      gRxOk++;
      gLastRssi = S2LPRadioGetRssidBm();
      if (plainLen >= 1 && plain[0] == TRIGGER_BYTE)
      {
        BSP_LED_Toggle(LED2);
      }
    }
    else
    {
      gRxRejected++;
    }
    ecc_wipe(plain, sizeof(plain));

    EnterRxMode();
  }
  else if (xIrqStatus.IRQ_RX_DATA_DISC || xIrqStatus.IRQ_RX_TIMEOUT)
  {
    EnterRxMode();
  }
}


/* Falha na inicializacao criptografica: nao usa o radio e pisca o codigo do
 * erro no LD2 (N piscadas, pausa): 1 = auto-teste, 2 = chaves, 3 = flash. */
static void SecurityFault(SL_Status code)
{
  while (1)
  {
    for (uint32_t i = 0; i < (uint32_t)code; i++)
    {
      BSP_LED_On(LED2);
      HAL_Delay(250);
      BSP_LED_Off(LED2);
      HAL_Delay(250);
    }
    HAL_Delay(1500);
  }
}

void APP_ButtonPressedCallback(void)
{
  gButtonTick = HAL_GetTick();
  gButtonPressed = 1;
}


void APP_RadioIrqCallback(void)
{
  gRadioIrq = 1;
}

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
