#include "cube_hal.h"
#include "radio_shield_config.h"
#include "radio_appli.h"
#include "radio_gpio.h"
#include "s2lp_interface.h"
#include "secure_link.h"


#define TRIGGER_BYTE        0xAA
#define TX_PAYLOAD_LEN       SL_FRAME_LEN(1)
#define RX_BUFFER_SIZE       128   /* tamanho da FIFO RX do S2-LP */


static SRadioInit xAppRadioInit = {
  BASE_FREQUENCY,
  MODULATION_SELECT,
  DATARATE,
  FREQ_DEVIATION,
  BANDWIDTH
};

static PktBasicInit xAppBasicInit = {
  .xPreambleLength = PREAMBLE_LENGTH,
  .xSyncLength = SYNC_LENGTH,
  .lSyncWords = SYNC_WORD,
  .xFixVarLength = VARIABLE_LENGTH,
  .cExtendedPktLenField = S_DISABLE,
  .xCrcMode = CRC_MODE,
  .xAddressField = S_DISABLE,
  .xFec = EN_FEC,
  .xDataWhitening = EN_WHITENING
};

static SGpioInit xAppGpioIrq = {
  S2LP_GPIO_3,
  S2LP_GPIO_MODE_DIGITAL_OUTPUT_LP,
  S2LP_GPIO_DIG_OUT_IRQ
};

static uint8_t aTxBuffer[SL_FRAME_MAX] = { 0 };
static uint8_t aRxBuffer[RX_BUFFER_SIZE] = { 0 };


volatile uint8_t gButtonPressed = 0;
volatile uint8_t gRadioIrq      = 0;


static void RadioInitAll(void);
static void EnterRxMode(void);
static void HandleRadioIrq(void);
static void TransmitTrigger(void);
static void SecurityFault(SL_Status code);
static void RadioToReady(void);
static void ConfigureRxPath(void);

#define RADIO_CHECK_MS       250   /* periodo da verificacao de seguranca do radio */

/* Diagnostico do radio: adicione em Live Expressions no depurador. */
volatile uint32_t  gTxOk = 0;        /* quadros enviados */
volatile uint32_t  gTxFail = 0;      /* envio nao concluido (canal ocupado/timeout) */
volatile uint32_t  gRxOk = 0;        /* quadros aceitos */
volatile uint32_t  gRxRejected = 0;  /* quadros recusados pelo secure_link */
volatile SL_Status gLastRxStatus = SL_OK;
volatile uint32_t  gRxRearm = 0;     /* vezes que o radio teve de ser recolocado em RX */

/* Diagnostico do front-end (FEM): adicione em Live Expressions no depurador.
 * gRangeExt : 3 = SKY66420 reconhecido; 0 = nenhum extensor de alcance detectado.
 * gHasEeprom: 1 = EEPROM da placa de radio foi lida; 0 = nao foi lida.
 * 0xFF = ainda nao preenchido (S2LPInterfaceInit ainda nao rodou). */
volatile uint8_t   gRangeExt  = 0xFF;
volatile uint8_t   gHasEeprom = 0xFF;


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


  S2LPInterfaceInit();

  /* Diagnostico: registra o que a identificacao da placa de radio encontrou. */
  gRangeExt  = (uint8_t)S2LPManagementGetRangeExtender();
  gHasEeprom = (uint8_t)RadioGetHasEeprom();

  xAppRadioInit.lFrequencyBase = (uint32_t)BASE_FREQUENCY + S2LPManagementGetOffset();


  RadioInitAll();


  EnterRxMode();

  uint32_t lastRadioCheck = HAL_GetTick();
  while (1)
  {
    if (gButtonPressed)
    {
      gButtonPressed = 0;
      TransmitTrigger();
      EnterRxMode();
    }

    if (gRadioIrq)
    {
      gRadioIrq = 0;
      HandleRadioIrq();
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


static void RadioInitAll(void)
{
  S2LPGpioInit(&xAppGpioIrq);
  S2LPRadioInit(&xAppRadioInit);
  S2LPRadioSetChannelSpace(CHANNEL_SPACE);
  S2LPRadioSetChannel(CHANNEL_NUMBER);
  S2LPRadioSetMaxPALevel(S_DISABLE);
  if (S2LPManagementGetRangeExtender() == RANGE_EXT_NONE)
  {
    S2LPRadioSetPALeveldBm(POWER_INDEX, POWER_DBM);
  }
  else
  {
    uint8_t paLevelValue = 0x25;
    S2LPSpiWriteRegisters(PA_POWER8_ADDR, 1, &paLevelValue);
  }
  S2LPRadioSetPALevelMaxIndex(POWER_INDEX);

  S2LPPktBasicInit(&xAppBasicInit);
  ConfigureRxPath();


  S2LPGpioIrqClearStatus();
  S2LP_EnableRxIrq();
  S2LP_EnableTxIrq();
  S2LPGpioIrqConfig(MAX_BO_CCA_REACH, S_ENABLE);   /* CSMA desistiu: canal ocupado */
}

/* Leva o S2-LP ao estado READY (sai de RX/TX), necessario antes de limpar FIFOs. */
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


static void EnterRxMode(void)
{
  RadioToReady();
  S2LPCmdStrobeFlushRxFifo();
  S2LP_SetPayloadlength(TX_PAYLOAD_LEN);
  /* Limpa IRQs pendentes para o pino voltar ao nivel alto e a proxima
   * IRQ gerar uma nova borda de descida na EXTI. */
  S2LPGpioIrqClearStatus();
  S2LPCmdStrobeRx();
}


static void TransmitTrigger(void)
{
  const uint8_t command = TRIGGER_BYTE;
  uint8_t frameLen = 0;

  /* Um quadro por no permitido, cada um cifrado com a chave ECDH do par. */
  for (uint8_t dst = 1; dst <= SL_GetNodeCount(); dst++)
  {
    if (dst == SL_GetNodeId()
        || SL_Seal(dst, &command, sizeof(command), aTxBuffer, &frameLen) != SL_OK)
    {
      continue;
    }

    RadioToReady();
    S2LP_SetPayloadlength(frameLen);
    S2LPGpioIrqClearStatus();
    S2LP_StartTx(aTxBuffer, frameLen);   /* liga CSMA, carrega a FIFO e transmite */

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
        break;
      }
    } while ((HAL_GetTick() - start) < 500U);

    if (sent)
    {
      gTxOk++;
    }
    else
    {
      gTxFail++;
    }

    /* Sai do TX (ou do CSMA que desistiu) e restaura a configuracao de RX. */
    RadioToReady();
    ConfigureRxPath();
  }
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
  gButtonPressed = 1;
}


void APP_RadioIrqCallback(void)
{
  gRadioIrq = 1;
}

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
