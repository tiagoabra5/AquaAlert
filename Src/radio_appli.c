/**
******************************************************************************
* @file    radio_appli.c
* @author  CLAB
* @version V1.0.0
* @date    03-March-2017
* @brief   user file to configure S2LP transceiver.
*         
@verbatim
===============================================================================
##### How to use this driver #####
===============================================================================
[..]
This file is generated automatically by STM32CubeMX and eventually modified 
by the user

@endverbatim
******************************************************************************
* @attention
*
* <h2><center>&copy; COPYRIGHT(c) 2014 STMicroelectronics</center></h2>
*
* Redistribution and use in source and binary forms, with or without modification,
* are permitted provided that the following conditions are met:
*   1. Redistributions of source code must retain the above copyright notice,
*      this list of conditions and the following disclaimer.
*   2. Redistributions in binary form must reproduce the above copyright notice,
*      this list of conditions and the following disclaimer in the documentation
*      and/or other materials provided with the distribution.
*   3. Neither the name of STMicroelectronics nor the names of its contributors
*      may be used to endorse or promote products derived from this software
*      without specific prior written permission.
*
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
* AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
* IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
* DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
* FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
* DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
* SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
* CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
* OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
* OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*
******************************************************************************
*/ 

                                                                                
#include "radio_appli.h"
#include "cube_hal.h"
#include "MCU_Interface.h" 
#include "p2p_lib.h" 
#include "radio_gpio.h" 

#if defined(X_NUCLEO_IDS01A4) || defined(X_NUCLEO_IDS01A5)
#include "SPIRIT1_Util.h"
#endif
#if defined(X_NUCLEO_S2868A1) || defined(X_NUCLEO_S2915A1)
#include "S2LP_Util.h"
#include "S2LP_Timer_ex.h"
#endif


                    
    
  

                        
                                                                           
           
    
  

                                                                                

   
                                        
  

RadioDriver_t radio_cb =
{
#if defined(X_NUCLEO_IDS01A4) || defined(X_NUCLEO_IDS01A5)
  .Init = RadioInterfaceInit, 
  .GpioIrq = RadioGpioIrqInit,
  .RadioInit = RadioRadioInit,
  .SetRadioPower = RadioSetPower,
#endif
  .PacketConfig = RadioPacketConfig,
  .SetPayloadLen = RadioSetPayloadlength,
  .SetDestinationAddress = RadioSetDestinationAddress,
  .EnableTxIrq = RadioEnableTxIrq,
  .EnableRxIrq = RadioEnableRxIrq,
#if defined(X_NUCLEO_IDS01A4) || defined(X_NUCLEO_IDS01A5) 
  .DisableIrq = RadioDisableIrq,
#endif
  .SetRxTimeout = RadioSetRxTimeout,
  .EnableSQI = RadioEnableSQI,
#if defined(X_NUCLEO_IDS01A4) || defined(X_NUCLEO_IDS01A5)
  .SetRssiThreshold = RadioSetRssiTH,
  .ClearIrqStatus = RadioClearIRQ,
#endif
  .StartRx = RadioStartRx,
  .StartTx = RadioStartTx,
  .GetRxPacket = RadioGetRxPacket
};





   
                                            
  
MCULowPowerMode_t MCU_LPM_cb =
{
  .McuStopMode = MCU_Enter_StopMode,
  .McuStandbyMode = MCU_Enter_StandbyMode,
  .McuSleepMode = MCU_Enter_SleepMode
}; 

   
                                              
  
RadioLowPowerMode_t Radio_LPM_cb =
{
  .RadioShutDown = RadioPowerOFF,
  .RadioStandBy = RadioStandBy,
  .RadioSleep = RadioSleep,
  .RadioPowerON = RadioPowerON
};

   
                               
  
SGpioInit xGpioIRQ={
#if defined(X_NUCLEO_IDS01A4) || defined(X_NUCLEO_IDS01A5)
  SPIRIT_GPIO_IRQ,
#endif
#if defined(X_NUCLEO_S2868A1) || defined(X_NUCLEO_S2915A1)
  S2LP_GPIO_3,
#endif
  
  RADIO_GPIO_MODE_DIGITAL_OUTPUT_LP,
  RADIO_GPIO_DIG_OUT_IRQ
    
};

   
                                
  
SRadioInit xRadioInit = {
#if defined(X_NUCLEO_IDS01A4) || defined(X_NUCLEO_IDS01A5)
  XTAL_OFFSET_PPM,
#endif
  BASE_FREQUENCY,
#if defined(X_NUCLEO_IDS01A4) || defined(X_NUCLEO_IDS01A5) 
  CHANNEL_SPACE,
  CHANNEL_NUMBER,
#endif  
  MODULATION_SELECT,
  DATARATE,
  FREQ_DEVIATION,
  BANDWIDTH
};



#if defined(USE_STack_PROTOCOL)
   
                                       
  
PktStackInit xStackInit={
  PREAMBLE_LENGTH,
  SYNC_LENGTH,
  SYNC_WORD,
  LENGTH_TYPE,
  LENGTH_WIDTH,
  CRC_MODE,
  CONTROL_LENGTH,
  EN_FEC,
  EN_WHITENING
};

                           
PktStackLlpInit xStackLLPInit ={
  EN_AUTOACK,
  EN_PIGGYBACKING,
  MAX_RETRANSMISSIONS
};

   
                                  
  
PktStackAddressesInit xAddressInit={
  EN_FILT_MY_ADDRESS,
  MY_ADDRESS,
  EN_FILT_MULTICAST_ADDRESS,
  MULTICAST_ADDRESS,
  EN_FILT_BROADCAST_ADDRESS,
  BROADCAST_ADDRESS
};

#elif defined(USE_BASIC_PROTOCOL)

   
                                       
  

PktBasicInit xBasicInit={
  
  PREAMBLE_LENGTH,
  SYNC_LENGTH,
  SYNC_WORD,
#if defined(X_NUCLEO_IDS01A4) || defined(X_NUCLEO_IDS01A5)
  LENGTH_TYPE,
  LENGTH_WIDTH,
#endif
#if defined(X_NUCLEO_S2868A1) || defined(X_NUCLEO_S2915A1)
  VARIABLE_LENGTH,
  EXTENDED_LENGTH_FIELD,
#endif
  CRC_MODE,
#if defined(X_NUCLEO_IDS01A4) || defined(X_NUCLEO_IDS01A5)
  CONTROL_LENGTH,
#endif
  EN_ADDRESS,
  EN_FEC,
  EN_WHITENING
};

   
                                  
  
PktBasicAddressesInit xAddressInit={
  EN_FILT_MY_ADDRESS,
  MY_ADDRESS,
  EN_FILT_MULTICAST_ADDRESS,
  MULTICAST_ADDRESS,
  EN_FILT_BROADCAST_ADDRESS,
  BROADCAST_ADDRESS
};

#endif

#ifdef CSMA_ENABLE
   
                               
  
RadioCsmaInit xCsmaInit={
  
  PERSISTENT_MODE_EN,                                                        
                                                                           
                                                 
                                                                              
                                                                     
                                                                           
                                                                              
                                                       
                                                                   
                                                                      
                                                                           
    
  CS_PERIOD,
  CS_TIMEOUT,
  MAX_NB,
  BU_COUNTER_SEED,
  CU_PRESCALER
};
#endif 

                                                                                
#define TIME_UP                                         0x01

                                                                                

                                                                                
RadioDriver_t *pRadioDriver;
MCULowPowerMode_t *pMCU_LPM_Comm;
RadioLowPowerMode_t  *pRadio_LPM_Comm;
                      
volatile FlagStatus xRxDoneFlag = RESET, xTxDoneFlag=RESET, cmdFlag=RESET;
volatile FlagStatus xStartRx=RESET, rx_timeout=RESET, exitTime=RESET;
volatile FlagStatus PushButtonStatusWakeup=RESET;
volatile FlagStatus PushButtonStatusData=RESET;
                                 
RadioIrqs xIrqStatus;

__IO uint32_t KEYStatusData = 0x00;
static AppliFrame_t xTxFrame, xRxFrame;
#if defined(X_NUCLEO_IDS01A4) || defined(X_NUCLEO_IDS01A5)
uint8_t DestinationAddr;
#endif
uint8_t TxFrameBuff[MAX_BUFFER_LEN] = {0x00};
uint16_t exitCounter = 0;
uint16_t txCounter = 0;
uint16_t wakeupCounter = 0;
uint16_t dataSendCounter = 0x00;

                                                                                

#if defined(X_NUCLEO_S2868A1) || defined(X_NUCLEO_S2915A1)

void HAL_S2LP_Init(void);
void Enter_LP_mode(void);
void Exit_LP_mode(void);
void MCU_Enter_StopMode(void);
void MCU_Enter_StandbyMode(void);
void MCU_Enter_SleepMode(void);
void RadioPowerON(void);
void RadioPowerOFF(void);
void RadioStandBy(void);
void RadioSleep(void);
void AppliSendBuff(AppliFrame_t *xTxFrame, uint8_t cTxlen);
void AppliReceiveBuff(uint8_t *RxFrameBuff, uint8_t cRxlen);
void P2P_Init(void);
void STackProtocolInit(void);
void BasicProtocolInit(void);
void P2PInterruptHandler(void);
void Set_KeyStatus(FlagStatus val);
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin);
void HAL_SYSTICK_Callback(void);
#endif

                                                                                

                                          
    
  

   
                                           
              
               
  
void HAL_Radio_Init(void)
{
  pRadioDriver = &radio_cb;
#if defined(X_NUCLEO_IDS01A4) || defined(X_NUCLEO_IDS01A5)
  pRadioDriver->Init( ); 
#endif
#if defined(X_NUCLEO_S2868A1) || defined(X_NUCLEO_S2915A1)
  S2LPInterfaceInit(); 
#endif
}



SM_State_t SM_State = SM_STATE_START_RX;                              

   
                                        
                                                        
                                                     
                                                      
                                                  
               
  
void P2P_Process(uint8_t *pTxBuff, uint8_t cTxlen, uint8_t* pRxBuff, uint8_t cRxlen)
{
  uint8_t xIndex = 0;
  uint8_t ledToggleCtr = 0;
  uint8_t  dest_addr;
                           
  
  switch(SM_State)
  {
  case SM_STATE_START_RX:
    {      
      AppliReceiveBuff(pRxBuff, cRxlen);
                                                            
      SM_State = SM_STATE_WAIT_FOR_RX_DONE;    
    }
    break;
    
  case SM_STATE_WAIT_FOR_RX_DONE:
    if((RESET != xRxDoneFlag)||(RESET != rx_timeout)||(SET != exitTime))
    {
      if((rx_timeout==SET)||(exitTime==RESET))
      {
        rx_timeout = RESET;
#if defined(X_NUCLEO_IDS01A4) || defined(X_NUCLEO_IDS01A5)
        BSP_LED_Toggle(LED2);
#endif
        SM_State = SM_STATE_START_RX;
      }
      else if(xRxDoneFlag) 
      {
        xRxDoneFlag=RESET;
        SM_State = SM_STATE_DATA_RECEIVED;
      }
    }
    break;
    
  case SM_STATE_DATA_RECEIVED:
    {
#if defined(X_NUCLEO_S2868A1) || defined(X_NUCLEO_S2915A1)
      pRadioDriver = &radio_cb; 
#endif
      
      pRadioDriver->GetRxPacket(pRxBuff,&cRxlen); 
                                          
                                       
      xRxFrame.Cmd = pRxBuff[0];
      xRxFrame.CmdLen = pRxBuff[1];
      xRxFrame.Cmdtag = pRxBuff[2];
      xRxFrame.CmdType = pRxBuff[3];
      xRxFrame.DataLen = pRxBuff[4];
      
      for (xIndex = 5; xIndex < cRxlen; xIndex++)
      {
        xRxFrame.DataBuff[xIndex] = pRxBuff[xIndex];
      }
      if(xRxFrame.Cmd == LED_TOGGLE)
      {
        SM_State = SM_STATE_TOGGLE_LED; 
      } 
      if(xRxFrame.Cmd == ACK_OK)
      {
#if defined(X_NUCLEO_IDS01A4) || defined(X_NUCLEO_IDS01A5)
        HAL_Delay(DELAY_TX_LED_GLOW); 
#endif
        SM_State = SM_STATE_ACK_RECEIVED;
      }
    }
    break;
    
  case SM_STATE_SEND_ACK:
    {
      xTxFrame.Cmd = ACK_OK;
      xTxFrame.CmdLen = 0x01;
      xTxFrame.Cmdtag = xRxFrame.Cmdtag;
      xTxFrame.CmdType = APPLI_CMD;
      xTxFrame.DataBuff = pTxBuff;
      xTxFrame.DataLen = cTxlen;
      
      HAL_Delay(DELAY_TX_LED_GLOW);        
      AppliSendBuff(&xTxFrame, xTxFrame.DataLen);   
      SM_State = SM_STATE_WAIT_FOR_TX_DONE;
    }
    break;   
    
  case SM_STATE_SEND_DATA:
    {
      xTxFrame.Cmd = LED_TOGGLE;
      xTxFrame.CmdLen = 0x01;
      xTxFrame.Cmdtag = txCounter++;
      xTxFrame.CmdType = APPLI_CMD;
      xTxFrame.DataBuff = pTxBuff;
      xTxFrame.DataLen = cTxlen;
      AppliSendBuff(&xTxFrame, xTxFrame.DataLen);
      SM_State = SM_STATE_WAIT_FOR_TX_DONE;
    }
    break;
    
  case SM_STATE_WAIT_FOR_TX_DONE:
                              
    if(xTxDoneFlag)
    {
      xTxDoneFlag = RESET;
      
      if(xTxFrame.Cmd == LED_TOGGLE)
      {
        SM_State = SM_STATE_START_RX;
      }
      else if(xTxFrame.Cmd == ACK_OK)
      {
        SM_State = SM_STATE_IDLE;  
      }
    }
    break;
    
  case SM_STATE_ACK_RECEIVED:
    for(; ledToggleCtr<5; ledToggleCtr++)
    {
#if defined(X_NUCLEO_IDS01A4) || defined(X_NUCLEO_IDS01A5)
      RadioShieldLedToggle(RADIO_SHIELD_LED);
#endif
#if defined(X_NUCLEO_S2868A1) || defined(X_NUCLEO_S2915A1)
                                               
      BSP_LED_Toggle(LED2);
#endif
      
      HAL_Delay(DELAY_RX_LED_TOGGLE);
    }
    SM_State = SM_STATE_IDLE;   
    break;
    
  case SM_STATE_TOGGLE_LED:
#if defined(X_NUCLEO_IDS01A4) || defined(X_NUCLEO_IDS01A5)
    RadioShieldLedOn(RADIO_SHIELD_LED);
#endif
#if defined(X_NUCLEO_S2868A1) || defined(X_NUCLEO_S2915A1)
                                         
    BSP_LED_On(LED2);
#endif
    dest_addr = RadioGetReceivedDestinationAddress();
    
    if ((dest_addr == MULTICAST_ADDRESS) || (dest_addr == BROADCAST_ADDRESS))
    {
                                                                                               
      HAL_Delay(DELAY_TX_LED_GLOW);
      SM_State = SM_STATE_IDLE;   
    }
    else
    {
      SM_State = SM_STATE_SEND_ACK;  
    }
    break;
    
  case SM_STATE_IDLE:
#if defined(X_NUCLEO_IDS01A4) || defined(X_NUCLEO_IDS01A5)
    RadioShieldLedOff(RADIO_SHIELD_LED);
#endif
#if defined(X_NUCLEO_S2868A1) || defined(X_NUCLEO_S2915A1)
                                          
#endif
    BSP_LED_Off(LED2); 
    SM_State = SM_STATE_START_RX;
    
#if defined(USE_LOW_POWER_MODE)
    Enter_LP_mode();
#endif     
    break;
  }
}

   
                                                                      
                                                                     
                                                    
              
  
void AppliSendBuff(AppliFrame_t *xTxFrame, uint8_t cTxlen)
{
  uint8_t xIndex = 0;
  uint8_t trxLength = 0;
#if defined(X_NUCLEO_S2868A1) || defined(X_NUCLEO_S2915A1)
  pRadioDriver = &radio_cb; 
#endif
  
#ifdef USE_STack_PROTOCOL
  
  PktStackAddressesInit xAddressInit=
  {
    .xFilterOnMyAddress = S_ENABLE,
    .cMyAddress = MY_ADDRESS,
    .xFilterOnMulticastAddress = S_DISABLE,
    .cMulticastAddress = MULTICAST_ADDRESS,
    .xFilterOnBroadcastAddress = S_ENABLE,
    .cBroadcastAddress = BROADCAST_ADDRESS
  };
  Radio_PktStackAddressesInit(&xAddressInit);
  
  
  
#ifdef USE_STack_LLP
  
                             
  PktStackLlpInit xStackLLPInit=
  {
    .xAutoAck = S_DISABLE,                
    .xPiggybacking = S_DISABLE,              
    .xNMaxRetx = PKT_N_RETX_2
  }; 
  
#else
  
                             
  PktStackLlpInit xStackLLPInit=
  {
    .xAutoAck = S_DISABLE,                
    .xPiggybacking = S_DISABLE,              
    .xNMaxRetx = PKT_DISABLE_RETX
  }; 
#endif
  
  Radio_PktStackLlpInit(&xStackLLPInit);
  
  
#endif
  
#ifdef USE_BASIC_PROTOCOL
  RadioPktBasicAddressesInit(&xAddressInit);
#endif  
  
  TxFrameBuff[0] = xTxFrame->Cmd;
  TxFrameBuff[1] = xTxFrame->CmdLen;
  TxFrameBuff[2] = xTxFrame->Cmdtag;
  TxFrameBuff[3] = xTxFrame->CmdType;
  TxFrameBuff[4] = xTxFrame->DataLen;
                                                               
  for(; xIndex < xTxFrame->DataLen; xIndex++)
            
                                                                
                                        
            
    
  {
    TxFrameBuff[xIndex+5] =  xTxFrame->DataBuff[xIndex];
  }
  
  
  trxLength = (xIndex+5);
#if defined(X_NUCLEO_IDS01A4) || defined(X_NUCLEO_IDS01A5)
                           
  pRadioDriver->DisableIrq();
                          
#endif
#if defined(X_NUCLEO_S2868A1) || defined(X_NUCLEO_S2915A1)
  S2LPGpioIrqDeInit(NULL);
#endif
  
  pRadioDriver->EnableTxIrq();
                             
  pRadioDriver->SetPayloadLen(trxLength);  
                         
  pRadioDriver->SetRxTimeout(RECEIVE_TIMEOUT);
                              
#if defined(X_NUCLEO_IDS01A4) || defined(X_NUCLEO_IDS01A5)
  pRadioDriver->ClearIrqStatus();
                           
  pRadioDriver->SetDestinationAddress(DestinationAddr);
#endif
#if defined(X_NUCLEO_S2868A1) || defined(X_NUCLEO_S2915A1)
  S2LPGpioIrqClearStatus();
                           
  pRadioDriver->SetDestinationAddress(DESTINATION_ADDRESS);
#endif  
                           
  pRadioDriver->StartTx(TxFrameBuff, trxLength);
}


   
                                                                   
                                                         
                                                  
              
  
void AppliReceiveBuff(uint8_t *RxFrameBuff, uint8_t cRxlen)
{
                           
  exitTime = SET;
  exitCounter = TIME_TO_EXIT_RX;
  
#ifdef USE_STack_PROTOCOL
  
#ifdef USE_STack_LLP
                             
  PktStackLlpInit xStackLLPInit=
  {
    .xAutoAck = S_ENABLE,                
    .xPiggybacking = S_ENABLE,              
    .xNMaxRetx = PKT_DISABLE_RETX
  }; 
#else
                             
  PktStackLlpInit xStackLLPInit=
  {
    .xAutoAck = S_DISABLE,                
    .xPiggybacking = S_DISABLE,              
    .xNMaxRetx = PKT_DISABLE_RETX
  }; 
#endif
  
  Radio_PktStackLlpInit(&xStackLLPInit);
  
  PktStackAddressesInit xAddressInit=
  {
    .xFilterOnMyAddress = S_ENABLE,
    .cMyAddress = MY_ADDRESS,
    .xFilterOnMulticastAddress = S_DISABLE,
    .cMulticastAddress = MULTICAST_ADDRESS,
    .xFilterOnBroadcastAddress = S_ENABLE,
    .cBroadcastAddress = BROADCAST_ADDRESS
  };
  
  Radio_PktStackAddressesInit(&xAddressInit);
  if(EN_FILT_SOURCE_ADDRESS)
  {
    Radio_PktStackFilterOnSourceAddress(S_ENABLE);
    Radio_PktStackSetRxSourceMask(SOURCE_ADDR_MASK);
    Radio_PktStackSetSourceReferenceAddress (SOURCE_ADDR_REF);
    
    
    
  }
  else
  {
    RadioPktStackFilterOnSourceAddress(S_DISABLE);    
  }
#endif
  
  RadioPktBasicAddressesInit(&xAddressInit);
#if defined(X_NUCLEO_IDS01A4) || defined(X_NUCLEO_IDS01A5)
  pRadioDriver->DisableIrq();
#endif
#if defined(X_NUCLEO_S2868A1) || defined(X_NUCLEO_S2915A1)
  pRadioDriver = &radio_cb;  
                         
  S2LPGpioIrqDeInit(NULL);
                        
#endif
  pRadioDriver->EnableRxIrq();
                             
  pRadioDriver->SetPayloadLen(PAYLOAD_LEN);
                         
#if defined(X_NUCLEO_IDS01A4) || defined(X_NUCLEO_IDS01A5)
  pRadioDriver->SetRxTimeout(RECEIVE_TIMEOUT);
#endif
  
#if defined(X_NUCLEO_S2868A1) || defined(X_NUCLEO_S2915A1)
  S2LPTimerSetRxTimerMs(700.0);
  SET_INFINITE_RX_TIMEOUT();  
#endif
#if defined(X_NUCLEO_IDS01A4) || defined(X_NUCLEO_IDS01A5)
                           
  pRadioDriver->SetDestinationAddress(DestinationAddr);  
                              
  pRadioDriver->ClearIrqStatus(); 
                  
#endif
#if defined(X_NUCLEO_S2868A1) || defined(X_NUCLEO_S2915A1)
                           
  pRadioDriver->SetDestinationAddress(DESTINATION_ADDRESS);
                              
  S2LPGpioIrqClearStatus(); 
#endif
                   
  pRadioDriver->StartRx(); 
}

   
                                                                    
               
              
              
  
void P2P_Init(void)
{
#if defined(X_NUCLEO_IDS01A4) || defined(X_NUCLEO_IDS01A5)
  DestinationAddr=DESTINATION_ADDRESS;
  pRadioDriver->GpioIrq(&xGpioIRQ);
  pRadioDriver->RadioInit(&xRadioInit);
  pRadioDriver->SetRadioPower(POWER_INDEX, POWER_DBM);  
#endif
#if defined(X_NUCLEO_S2868A1) || defined(X_NUCLEO_S2915A1)
  pRadioDriver = &radio_cb;
  
                       
  S2LPGpioInit(&xGpioIRQ);
  
                             
  S2LPRadioInit(&xRadioInit);
  
  
                            
  S2LPRadioSetMaxPALevel(S_DISABLE);  
  
  if(!S2LPManagementGetRangeExtender())
  {
                                                                
    S2LPRadioSetPALeveldBm(POWER_INDEX,POWER_DBM);
  }
  else
  { 
                                                                                                    
                                                                                 
                            
    uint8_t paLevelValue=0x25;                                                    
    S2LPSpiWriteRegisters(PA_POWER8_ADDR, 1, &paLevelValue);
  }
  S2LPRadioSetPALevelMaxIndex(POWER_INDEX); 
#endif
  
  
                            
  pRadioDriver->PacketConfig();
  
  pRadioDriver->EnableSQI();
#if defined(X_NUCLEO_IDS01A4) || defined(X_NUCLEO_IDS01A5)
  pRadioDriver->SetRssiThreshold(RSSI_THRESHOLD);
#endif
#if defined(X_NUCLEO_S2868A1) || defined(X_NUCLEO_S2915A1)
  S2LPRadioSetRssiThreshdBm(RSSI_THRESHOLD);
#endif
  
}

   
                                                                    
              
              
  
void STackProtocolInit(void)
{ 
  
  
  PktStackInit xStackInit=
  {
    .xPreambleLength = PREAMBLE_LENGTH,
    .xSyncLength = SYNC_LENGTH,
    .lSyncWords = SYNC_WORD,
#if defined(X_NUCLEO_IDS01A4) || defined(X_NUCLEO_IDS01A5)
    .xFixVarLength = LENGTH_TYPE,
    .cPktLengthWidth = 8, 
#endif   
#if defined(X_NUCLEO_S2868A1) || defined(X_NUCLEO_S2915A1)
    .xFixVarLength = S_ENABLE,
    .cExtendedPktLenField = S_DISABLE,
#endif
    .xCrcMode = CRC_MODE,
#if defined(X_NUCLEO_IDS01A4) || defined(X_NUCLEO_IDS01A5)
    .xControlLength = CONTROL_LENGTH,
#endif   
    .xFec = EN_FEC,
    .xDataWhitening = EN_WHITENING
  };  
                           
  RadioPktStackInit (&xStackInit);
}  


                    
                                                                    
              
              
  
void BasicProtocolInit(void)
{
                           
  RadioPktBasicInit(&xBasicInit);
}

   
                                                        
              
              
  
void Enter_LP_mode(void)
{  
  pMCU_LPM_Comm = &MCU_LPM_cb;
  pRadio_LPM_Comm = &Radio_LPM_cb;
  
#if defined(MCU_SLEEP_MODE)&&defined(RF_SHUTDOWN) 
  {
    pRadio_LPM_Comm->RadioShutDown(); 
    pMCU_LPM_Comm->McuSleepMode();
  }
#elif defined(MCU_SLEEP_MODE)&&defined(RF_STANDBY) 
  {
    pRadio_LPM_Comm->RadioStandBy(); 
    pMCU_LPM_Comm->McuSleepMode();
  }
#elif defined(MCU_SLEEP_MODE)&&defined(RF_SLEEP) 
  {
    pRadio_LPM_Comm->RadioSleep();
    pMCU_LPM_Comm->McuSleepMode();
  }
#elif defined(MCU_STOP_MODE)&&defined(RF_SHUTDOWN) 
  {
    pRadio_LPM_Comm->RadioShutDown(); 
    pMCU_LPM_Comm->McuStopMode();
  }
#elif defined(MCU_STOP_MODE)&&defined(RF_STANDBY) 
  {
    pRadio_LPM_Comm->RadioStandBy(); 
    pMCU_LPM_Comm->McuStopMode();
  }
#elif defined(MCU_STOP_MODE)&&defined(RF_SLEEP) 
  {
    pRadio_LPM_Comm->RadioSleep();
    pMCU_LPM_Comm->McuStopMode();
  }
#else
  pMCU_LPM_Comm->McuSleepMode();
#endif
}

   
                                                         
              
              
  
void Exit_LP_mode(void)
{
  pRadio_LPM_Comm = &Radio_LPM_cb;      
  pRadio_LPM_Comm->RadioPowerON();  
}

   
                                                
              
              
  
void MCU_Enter_StopMode(void)
{
  APPLI_EnterSTOPMode();
}

   
                                                   
              
              
  
void MCU_Enter_StandbyMode(void)
{
  APPLI_EnterSTANDBYMode();
}

   
                                                 
              
              
  
void MCU_Enter_SleepMode(void)
{
                                                                   
                                                                                      
  
  APPLI_EnterSLEEPMode();
}

   
                                                                                        
                      
              
                        
  
void RadioPowerON(void)
{
  RadioCmdStrobeReady();   
  
  do{
                                    
    for(volatile uint8_t i=0; i!=0xFF; i++);
    
                                      
    
    RadioRefreshStatus();
    
    
  }
  while(g_xStatus.MC_STATE!=MC_STATE_READY);
}


   
                                                 
                      
              
                        
  
void RadioPowerOFF(void)
{
  RadioEnterShutdown();
  
  
}


   
                                                            
                
              
                        
  
void RadioStandBy(void)
{
  RadioCmdStrobeStandby();  
}

   
                                                          
                
              
                        
  
void RadioSleep(void)
{
  RadioCmdStrobeSleep(); 
}

   
                                                                   
              
              
  
void Set_KeyStatus(FlagStatus val)
{
  if(val==SET)
  {
    SM_State = SM_STATE_SEND_DATA;
  }
}

   
                                                                                          
                                                                              
              
              
  
void P2PInterruptHandler(void)
{
  RadioGpioIrqGetStatus(&xIrqStatus);
  
  
                                            
  if(
     (xIrqStatus.IRQ_TX_DATA_SENT) 
       
#ifdef CSMA_ENABLE
       ||(xIrqStatus.IRQ_MAX_BO_CCA_REACH)
#endif
         )
  {
#ifdef CSMA_ENABLE
    RadioCsma(S_DISABLE);  
    RadioRadioPersistenRx(S_ENABLE);
    RadioRadioCsBlanking(S_ENABLE);
    
    if(xIrqStatus.IRQ_MAX_BO_CCA_REACH)
    {
      RadioCmdStrobeSabort();
      
      
    }
    RadioQiSetRssiThresholddBm(RSSI_THRESHOLD);
    
    
#endif
    
    xTxDoneFlag = SET;
  }
  
                                             
  if((xIrqStatus.IRQ_RX_DATA_READY))
  {
    xRxDoneFlag = SET;   
  }
  
                                            
  if (xIrqStatus.IRQ_RX_TIMEOUT)
  {
    rx_timeout = SET; 
    RadioCmdStrobeRx();
    
  }
  
                                            
  if(xIrqStatus.IRQ_RX_DATA_DISC)
  {      
                                                                                
    RadioCmdStrobeRx();
    
  }  
}

   
                           
              
              
  
void HAL_SYSTICK_Callback(void)
{
  if(exitTime)
  {
                                                                         
    exitCounter--;
                                  
    if(exitCounter <= TIME_UP)
    {
      exitTime = RESET;
    }
  }
#if defined(RF_STANDBY)
                                                             
  if(PushButtonStatusWakeup)
  {
                                                                         
    wakeupCounter--;
    
                                 
    if(wakeupCounter<=TIME_UP)
    {
                                        
      Exit_LP_mode();
      PushButtonStatusWakeup = RESET;
      PushButtonStatusData = SET;
    }
  }
  else if(PushButtonStatusData)
  {
    dataSendCounter--;
    if(dataSendCounter<=TIME_UP)
    {
      Set_KeyStatus(SET);
      PushButtonStatusWakeup = RESET;
      PushButtonStatusData = RESET;
    }
  }
#endif
}
   
    
  

   
                           
                          
              
  

#if defined(X_NUCLEO_S2868A1) || defined(X_NUCLEO_S2915A1)
extern uint16_t M2S_GPIO_PIN_IRQ;
#endif
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
  
#if defined(RF_STANDBY)                         
#if defined(MCU_STOP_MODE)                                  
  
                          
  __HAL_PWR_CLEAR_FLAG(PWR_FLAG_WU);
  
                                                                                
                                                                       
  SystemClockConfig_ExitSTOPMode(); 
#endif
#if defined(MCU_SLEEP_MODE) 
                                                                  
  HAL_ResumeTick();
#endif 
  
                      
#if defined(X_NUCLEO_IDS01A4) || defined(X_NUCLEO_IDS01A5)
  RadioShieldLedInit(RADIO_SHIELD_LED);
#endif
#if defined(X_NUCLEO_S2868A1) || defined(X_NUCLEO_S2915A1)
                                          
#endif
  BSP_LED_Init(LED2);
  
  PushButtonStatusWakeup = SET;
  PushButtonStatusData = RESET;
  wakeupCounter = LPM_WAKEUP_TIME; 
  dataSendCounter = DATA_SEND_TIME;
  dataSendCounter++;
#endif
  if(GPIO_Pin==USER_BUTTON_PIN)
  {
    Set_KeyStatus(SET);
  } 
#if defined(X_NUCLEO_IDS01A4) || defined(X_NUCLEO_IDS01A5)
  else 
    if(GPIO_Pin==RADIO_GPIO_3_EXTI_LINE)
    {
      P2PInterruptHandler();
    }
  
#endif
  
}
   
    
  

   
    
  

   
    
  

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
