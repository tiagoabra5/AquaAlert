

                                                                                
#include "s2lp_interface.h"
#include "radio_appli.h"
#include "radio_gpio.h"

#include "S2LP_Timer_ex.h"
   
                     
    
  


   
                            
    
  


   
                                                                                                  
    
  

   
    
  


   
                                                                                        
    
  

   
    
  


   
                                                                                       
    
  
#define IRQ_PREEMPTION_PRIORITY         0x03
   
    
  


   
                                                                                          
    
  

/* Forca o uso do FEM SKY66420 da X-NUCLEO-S2915A1 mesmo quando a EEPROM da placa
 * de radio nao e lida (gHasEeprom = 0). Comente a linha abaixo para voltar a
 * deteccao automatica pela EEPROM. */
#define FORCE_FEM_SKY66420

/* Definida em S2LP_Util.c, mas sem prototipo no S2LP_Util.h. */
void S2LPManagementSetRangeExtender(RangeExtType xRangeType);

static RangeExtType xRangeExtType = RANGE_EXT_NONE;
static uint8_t s_RfModuleBand = 0;
                                   
extern SRadioInit xRadioInit;
   
    
  

   
                                                                                                    
    
  

   
    
  


   
                                                                                          
    
  

   
                                   
              
                
  
void S2LPInterfaceInit(void)
{ 
  RangeExtType rangeExtType; 
                                         
  RadioGpioInit(RADIO_GPIO_SDN,RADIO_MODE_GPIO_OUT);
  
  S2LPSpiInit();
  
  EepromSpiInitialization();
  
               
  S2LPEnterShutdown();
  S2LPExitShutdown();  
  
  S2LPManagementIdentificationRFBoard();

#ifdef FORCE_FEM_SKY66420
  /* Sobrescreve o que a EEPROM informou (ou nao conseguiu informar): a partir
   * daqui o firmware sempre configura os pinos do FEM e o usa em TX e RX. */
  S2LPManagementSetRangeExtender(RANGE_EXT_SKYWORKS_SKY66420);
#endif
  
                                                                                          
                                                      
  xRadioInit.lFrequencyBase = (uint32_t) BASE_FREQUENCY + S2LPManagementGetOffset();
  
                                                       
  S2LPManagementRangeExtInit();
  
  rangeExtType = S2LPManagementGetRangeExtender();
  if(rangeExtType == RANGE_EXT_SKYWORKS_SKY66420)
  {
    RangeExtGpioInit();
  }
#if 0        
                                                            
  S2LPManagementTcxoInit();
#endif  
                            
  RadioGpioInit(RADIO_GPIO_3,RADIO_MODE_EXTI_IN);
                                                    
  
                       
                              
  
                     
  RadioGpioInterruptCmd(RADIO_GPIO_3,IRQ_PREEMPTION_PRIORITY,0,ENABLE);  
  
}


   
                                      
                                     
              
  
void S2LP_ManagementSetBand(uint8_t value)
{
  s_RfModuleBand = value;
}


   
                                         
              
                                     
  
uint8_t S2LP_ManagementGetBand(void)
{
  return s_RfModuleBand;
}

   
                                                                                                    
    
  
void S2LP_ManagementRangeExtInit(void)
{
  RangeExtType range_type = S2LP_ManagementGetRangeExtender();
#if 0  
                                               
         
                                                   
                                              
                                                                  
          
                           
                                                                                                                  
          
                               
                                                                                                                
          
                             
                                                                                                                
         
         
#endif  
  if(range_type==RANGE_EXT_SKYWORKS_868) {   
                     
    S2LPGpioInit(&(SGpioInit){S2LP_GPIO_0, S2LP_GPIO_MODE_DIGITAL_OUTPUT_HP, S2LP_GPIO_DIG_OUT_TX_RX_MODE});
    
                         
    S2LPGpioInit(&(SGpioInit){S2LP_GPIO_1, S2LP_GPIO_MODE_DIGITAL_OUTPUT_HP, S2LP_GPIO_DIG_OUT_RX_STATE});
    
                       
    S2LPGpioInit(&(SGpioInit){S2LP_GPIO_2, S2LP_GPIO_MODE_DIGITAL_OUTPUT_HP, S2LP_GPIO_DIG_OUT_TX_STATE});
  }
}

   
                                              
              
                      
  
RangeExtType S2LP_ManagementGetRangeExtender(void)
{
  return xRangeExtType;
}

   
                                           
                      
              
  
void S2LP_ManagementSetRangeExtender(RangeExtType xRangeType)
{
  xRangeExtType = xRangeType;
}


   
                                            
                                         
              
  
void S2LP_SetPower(uint8_t cIndex, float fPowerdBm)
{
                            
  S2LPRadioSetPALeveldBm(cIndex,(int32_t)fPowerdBm);
                                               
  S2LPRadioSetPALevelMaxIndex(cIndex);
}

   
                                                                                    
              
              
  
void S2LP_PacketConfig(void)
{
#if defined(USE_STack_PROTOCOL)
  
  STackProtocolInit();
  
#elif defined(USE_BASIC_PROTOCOL)
  
  BasicProtocolInit();
  
#endif
}

   
                                               
                        
              
  
void S2LP_SetPayloadlength(uint8_t length)
{
#if defined(USE_STack_PROTOCOL)
                             
  S2LP_PktStackSetPayloadLength(length);
  
#elif defined(USE_BASIC_PROTOCOL)
                             
  S2LPPktBasicSetPayloadLength(length);
#endif
}

   
                                                    
                        
              
  
void S2LP_SetDestinationAddress(uint8_t address)
{
#if defined(USE_STack_PROTOCOL)
                           
  S2LP_PktStackSetDestinationAddress(address);
#elif defined(USE_BASIC_PROTOCOL)
                           
  S2LPSetRxSourceReferenceAddress(address);
#endif
}

   
                                          
              
              
  
void S2LP_EnableTxIrq(void)
{
                        
  S2LPGpioIrqConfig(TX_DATA_SENT, S_ENABLE); 
#if defined(USE_STack_LLP)
  S2LPGpioIrqConfig(MAX_RE_TX_REACH, S_ENABLE);
#endif  
}

   
                                          
              
              
  
void S2LP_EnableRxIrq(void)
{
                        
  S2LPGpioIrqConfig(RX_DATA_READY, S_ENABLE);
  S2LPGpioIrqConfig(RX_DATA_DISC, S_ENABLE); 
  S2LPGpioIrqConfig(RX_TIMEOUT, S_ENABLE);
}


   
                                                      
              
              
  
void S2LP_SetRxTimeout(float cRxTimeOut)
{
  if(cRxTimeOut == 0)
  {
                           
    SET_INFINITE_RX_TIMEOUT();
    S2LPTimerSetRxTimerStopCondition(ANY_ABOVE_THRESHOLD);
  }
  else
  {
                           
    S2LPTimerSetRxTimerMs(cRxTimeOut);   
    S2LP_EnableSQI();
    S2LPTimerSetRxTimerStopCondition(RSSI_AND_SQI_ABOVE_THRESHOLD);     
  }
}


   
                                               
                      
              
  
float S2LP_GetRssiTH(void)
{
  float dbmValue=0;
  dbmValue = S2LPRadioGetRssidBm();
  return dbmValue;
}

   
                                         
              
              
  
void S2LP_EnableSQI(void)
{
                        
  S2LPQiSetSqiThreshold(SQI_TH_0);
  S2LPQiSqiCheck(S_ENABLE);
}

   
                                             
              
              
  
void S2LP_StartRx(void)
{
  if(g_xStatus.MC_STATE==MC_STATE_RX)
  {
    S2LPCmdStrobeSabort();
  }
                  
  S2LPCmdStrobeRx();
}

   
                                         
              
              
  
void S2LP_GetRxPacket(uint8_t *buffer, uint8_t *cRxData )
{
  uint8_t noofbytes = 0;
                                                            
  *cRxData=S2LPFifoReadNumberBytesRxFifo();
  noofbytes = *cRxData;
                        
  S2LPSpiReadFifo(noofbytes, buffer);
  
  S2LPCmdStrobeFlushRxFifo();
}

   
                                             
              
              
  
void S2LP_StartTx(uint8_t *buffer, uint8_t size )
{
  if(g_xStatus.MC_STATE==MC_STATE_RX)
  {
    S2LPCmdStrobeSabort();
  }
  
#ifdef CSMA_ENABLE
  
                   
  S2LPPacketHandlerSetRxPersistentMode(S_DISABLE);
  S2LPRadioCsBlanking(S_DISABLE);
  
  S2LPCsmaInit(&xCsmaInit);
  S2LPCsma(S_ENABLE);
  S2LPRadioSetRssiThreshdBm(CSMA_RSSI_THRESHOLD);
  
#endif 
  
                       
  S2LPCmdStrobeFlushTxFifo();
  
  S2LPSpiWriteFifo(size, buffer);
  
  
                           
  S2LPCmdStrobeTx();
}






   
    
  

   
    
  


/******************* (C) COPYRIGHT 2015 STMicroelectronics *****END OF FILE****/
