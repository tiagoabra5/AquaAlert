/**
 * @file    S2LP_Timer.c
 * @author  LowPower RF BU - AMG
 * @version 1.3.0
 * @date    10-July-2017
 * @brief   Configuration and management of S2-LP timers.
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; COPYRIGHT(c) 2019 STMicroelectronics</center></h2>
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
 * <h2><center>&copy; COPYRIGHT 2019 STMicroelectronics</center></h2>
 */


                                                                                

#include "S2LP_Config.h"
#include "MCU_Interface.h"


   
                             
     
   


   
                         
     
   


   
                                                                                       
     
   

   
    
   


   
                                                                             
     
   

#define LDC_FREQ_CLK            S2LPTimerGetRcoFrequency()


   
    
   


   
                                                                            
     
   

#define IS_RX_TIMEOUT_STOP_CONDITION(COND)  ( COND == NO_TIMEOUT_STOP || \
                                                COND == TIMEOUT_ALWAYS_STOPPED || \
                                                COND == RSSI_ABOVE_THRESHOLD || \
                                                COND == SQI_ABOVE_THRESHOLD || \
                                                COND == PQI_ABOVE_THRESHOLD || \
                                                COND == RSSI_AND_SQI_ABOVE_THRESHOLD || \
                                                COND == RSSI_AND_PQI_ABOVE_THRESHOLD || \
                                                COND == SQI_AND_PQI_ABOVE_THRESHOLD || \
                                                COND == ALL_ABOVE_THRESHOLD || \
                                                COND == RSSI_OR_SQI_ABOVE_THRESHOLD || \
                                                COND == RSSI_OR_PQI_ABOVE_THRESHOLD || \
                                                COND == SQI_OR_PQI_ABOVE_THRESHOLD || \
                                                COND == ANY_ABOVE_THRESHOLD )

   
    
   


   
                                                                               
     
   

   
    
   


   
                                                                                          
     
   

void S2LPTimerComputeWakeupTimerValues(uint32_t* plWakeUpUsec , uint8_t cCounter , uint8_t cPrescaler, uint8_t cMulti);
void S2LPTimerComputeRxTimerValues(uint32_t* plDesiredUsec, uint8_t pcCounter, uint8_t pcPrescaler);
void S2LPTimerComputeRxTimerRegValues(uint32_t plDesiredUsec , uint8_t* pcCounter , uint8_t* pcPrescaler);
void S2LPTimerComputeWakeupTimerRegValues(uint32_t plDesiredUsec , uint8_t* pcCounter , uint8_t* pcPrescaler, uint8_t* pcMulti);


   
    
   


   
                                                                               
     
   

   
                                      
                                                                                                           
                            
                                 
                              
                
   
void S2LPTimerComputeWakeupTimerValues(uint32_t* plWakeUpUsec , uint8_t cCounter , uint8_t cPrescaler, uint8_t cMulti)
{
  (*plWakeUpUsec) = (uint32_t)((uint64_t)1000000*(cCounter+1)*(cPrescaler+1)/LDC_FREQ_CLK*cMulti);
}

   
                                                                                                                     
                                                                                               
                                                                                                              
                                                               
                                                                          
                                                          
                                                                                                              
                                             
                                                                                                                  
                                              
               
   
void S2LPTimerComputeWakeupTimerRegValues(uint32_t lDesiredUsec, uint8_t* pcCounter , uint8_t* pcPrescaler, uint8_t* pcMulti)
{
  uint32_t n;
  uint8_t i;
  
  for(i=0;i<4;i++)
  {
    if(lDesiredUsec<(((uint32_t)((uint64_t)1000000*65536/LDC_FREQ_CLK))<<i))
      break;
  }
  (*pcMulti)=i;
  

                                             
                                          
                                                               
    
  n = (uint32_t)((uint64_t)lDesiredUsec*(LDC_FREQ_CLK>>i)/1000000);
    
                                                                                       
  if(n/0xFF>0xFD) {
                                                  
    (*pcCounter) = 0xFF;
    (*pcPrescaler) = 0xFF;
    return;
  }
  
                                          
  (*pcPrescaler) = (n/0xFF)+2;
  (*pcCounter) = n / (*pcPrescaler);
  
                                       
                                                                            
    
                           
                                                                                 
                                      
     
    
                                                                                    
  (*pcPrescaler)--;
  if((*pcCounter)>1)
    (*pcCounter)--;
  else
    (*pcCounter)=1;
}

   
                                                                                                                         
                                                                                               
                                                                                                              
                                                        
                                                                                                          
                                                          
                                                                                                            
                                             
                                                                                                                
                                              
               
   
void S2LPTimerComputeRxTimerRegValues(uint32_t lDesiredUsec , uint8_t* pcCounter , uint8_t* pcPrescaler)
{
  uint32_t f_dig = S2LPRadioGetXtalFrequency();
  uint32_t n;
  uint64_t tgt,tgt1,tgt2;
  
                                         
  if(f_dig>DIG_DOMAIN_XTAL_THRESH) {
    f_dig >>= 1;
  }
  
                                             
                                       
                                                               
    
  tgt=(uint64_t)lDesiredUsec*f_dig;
  n=(uint32_t)(tgt/1210000000);
  tgt1=(uint64_t)1210000000*n;
  tgt2=(uint64_t)1210000000*(n+1);
  
  n=((tgt2-tgt)<(tgt-tgt1))?(n+1):(n);
  
                                                                                       
  if(n/0xFF>0xFD) {
                                                  
    (*pcCounter) = 0xFF;
    (*pcPrescaler) = 0xFF;
    return;
  }
  
                                          
  (*pcPrescaler)=(n/0xFF)+2;
  (*pcCounter) = n / (*pcPrescaler);
  
  
                                                                                     
  (*pcPrescaler)--;
  
  if((*pcCounter)==0)
    (*pcCounter)=1;
}

   
                                                                                       
                                                             
                                                                          
                                                          
                                               
                                            
                                                   
                                             
               
   
void S2LPTimerComputeRxTimerValues(uint32_t* pulDesiredUsec, uint8_t cCounter, uint8_t cPrescaler)
{
  uint32_t f_dig = S2LPRadioGetXtalFrequency();
  
                                         
  if(f_dig>DIG_DOMAIN_XTAL_THRESH) {
    f_dig >>= 1;
  }
  
  (*pulDesiredUsec) = (uint32_t)((uint64_t)1000000*(cPrescaler+1)*cCounter*1210/f_dig);
  
}

   
    
   


   
                                                                             
     
   


   
                                             
                                             
                                                        
                
   
void S2LPTimerLdcrMode(SFunctionalState xNewState)
{
  uint8_t tmp;
  s_assert_param(IS_SFUNCTIONAL_STATE(xNewState));
  
  S2LPSpiReadRegisters(PROTOCOL1_ADDR, 1, &tmp);
  if(xNewState==S_ENABLE) {
    tmp |= LDC_MODE_REGMASK;
  }
  else {
    tmp &= ~LDC_MODE_REGMASK;
  }
  g_xStatus = S2LPSpiWriteRegisters(PROTOCOL1_ADDR, 1, &tmp);
}


   
                                                                                                           
                                                  
                                                        
                
   
void S2LPTimerLdcrAutoReload(SFunctionalState xNewState)
{
  uint8_t tmp;
  s_assert_param(IS_SFUNCTIONAL_STATE(xNewState));

  S2LPSpiReadRegisters(PROTOCOL1_ADDR, 1, &tmp);
  if(xNewState==S_ENABLE) {
    tmp |= LDC_RELOAD_ON_SYNC_REGMASK;
  }
  else {
    tmp &= ~LDC_RELOAD_ON_SYNC_REGMASK;
  }
  g_xStatus = S2LPSpiWriteRegisters(PROTOCOL1_ADDR, 1, &tmp);
}


   
                                            
                
                                                     
   
SFunctionalState S2LPTimerLdcrGetAutoReload(void)
{
  uint8_t tmp;
  g_xStatus = S2LPSpiReadRegisters(PROTOCOL1_ADDR, 1, &tmp);
  return (SFunctionalState)((tmp & LDC_RELOAD_ON_SYNC_REGMASK)!=0);
}

   
                                                                                                                                                          
                                                                                                                                              
                                                
                                             
                                                    
                                             
                
   
void S2LPTimerSetRxTimer(uint8_t cCounter , uint8_t cPrescaler)
{
  uint8_t tmpBuffer[2] = {cCounter, cPrescaler};
  g_xStatus = S2LPSpiWriteRegisters(TIMERS5_ADDR, 2, tmpBuffer);
}


   
                                                                                                                               
                                                                          
                                            
                                             
               
   
void S2LPTimerSetRxTimerUs(uint32_t lDesiredUsec)
{
  uint8_t tmpBuffer[2];
  S2LPTimerComputeRxTimerRegValues(lDesiredUsec , &tmpBuffer[0] , &tmpBuffer[1]);
  g_xStatus = S2LPSpiWriteRegisters(TIMERS5_ADDR, 2, tmpBuffer);
}


   
                                                                                         
                                                
                                             
                
   
void S2LPTimerSetRxTimerCounter(uint8_t cCounter)
{
  g_xStatus = S2LPSpiWriteRegisters(TIMERS5_ADDR, 1, &cCounter);
}


   
                                                                                           
                                                    
                                             
               
   
void S2LPTimerSetRxTimerPrescaler(uint8_t cPrescaler)
{
  g_xStatus = S2LPSpiWriteRegisters(TIMERS4_ADDR, 1, &cPrescaler);
}


   
                                       
                                                                                                                 
                                                                                
                                              
                                                                                         
                                              
                                                                                             
                                              
                
   
void S2LPTimerGetRxTimerUs(uint32_t* plTimeoutUsec, uint8_t* pcCounter , uint8_t* pcPrescaler)
{
  uint8_t tmpBuffer[2];
  
  g_xStatus = S2LPSpiReadRegisters(TIMERS5_ADDR, 2, tmpBuffer);
  
  (*pcCounter) = tmpBuffer[0];
  (*pcPrescaler) = tmpBuffer[1];
  S2LPTimerComputeRxTimerValues(plTimeoutUsec, tmpBuffer[0], tmpBuffer[1]);
}

   
                                                                                 
                                                                                                    
                                                                                             
                                                                                                   
                   
                                                
                                             
                                                    
                                             
                
   
void S2LPTimerSetWakeUpTimer(uint8_t cCounter , uint8_t cPrescaler)
{
  uint8_t tmpBuffer[2] = {cPrescaler, cCounter};
  g_xStatus = S2LPSpiWriteRegisters(TIMERS3_ADDR, 2, tmpBuffer);
}


   
                                                                                         
                                                                                               
                                                                                                 
                                                                                       
                                            
                                          
                
   
void S2LPTimerSetWakeUpTimerUs(uint32_t lDesiredUsec)
{
  uint8_t tmpBuffer[2], multi, tmp;

                                      
  S2LPTimerComputeWakeupTimerRegValues(lDesiredUsec , &tmpBuffer[1] , &tmpBuffer[0], &multi);

  S2LPSpiReadRegisters(PROTOCOL2_ADDR, 1, &tmp);
  tmp &= ~LDC_TIMER_MULT_REGMASK;
  tmp |= multi;
  S2LPSpiWriteRegisters(PROTOCOL2_ADDR, 1, &tmp);

  g_xStatus = S2LPSpiWriteRegisters(TIMERS3_ADDR, 2, tmpBuffer);

}


   
                                                                                                                   
                                                                    
                                                
                                             
                
   
void S2LPTimerSetWakeUpTimerCounter(uint8_t cCounter)
{
  g_xStatus = S2LPSpiWriteRegisters(TIMERS2_ADDR, 1, &cCounter);
}


   
                                                                                                                     
                                                                    
                                                    
                                             
                
   
void S2LPTimerSetWakeUpTimerPrescaler(uint8_t cPrescaler)
{
  g_xStatus = S2LPSpiWriteRegisters(TIMERS3_ADDR, 1, &cPrescaler);
}


   
                                                                                                                              
                                                                                                                     
                                              
                                                                                         
                                              
                                                                                             
                                              
                
   
void S2LPTimerGetWakeUpTimerUs(uint32_t* plWakeUpUsec, uint8_t* pcCounter, uint8_t* pcPrescaler, uint8_t* pcMulti)
{
  uint8_t tmpBuffer[2], tmp;
  
  S2LPSpiReadRegisters(PROTOCOL2_ADDR, 1, &tmp);
  tmp &= LDC_TIMER_MULT_REGMASK;
  *pcMulti = tmp;

  g_xStatus = S2LPSpiReadRegisters(TIMERS3_ADDR, 2, tmpBuffer);
  *pcCounter = tmpBuffer[1];
  *pcPrescaler = tmpBuffer[0];

  S2LPTimerComputeWakeupTimerValues(plWakeUpUsec, tmpBuffer[0], tmpBuffer[1], tmp);
}


   
                                                                            
                                                                                                    
                                                                                             
                                                                                                   
                   
                                                       
                                             
                                                           
                                             
                
   
void S2LPTimerSetWakeUpTimerReload(uint8_t cCounter , uint8_t cPrescaler, uint8_t cMulti)
{
  uint8_t tmpBuffer[2] = {cPrescaler, cCounter}, tmp;

  S2LPSpiReadRegisters(PROTOCOL2_ADDR, 1, &tmp);
  tmp &= (~LDC_TIMER_MULT_REGMASK);
  tmp |= cMulti;
  S2LPSpiWriteRegisters(PROTOCOL2_ADDR, 1, &tmp);

  g_xStatus = S2LPSpiWriteRegisters(TIMERS1_ADDR, 2, tmpBuffer);
}


   
                                                                                                
                                                                                               
                                                                                                 
                                                                                       
                                                  
                
   
void S2LPTimerSetWakeUpTimerReloadUs(uint32_t lDesiredUsec)
{
  uint8_t tmpBuffer[2], multi, tmp;

                                      
  S2LPTimerComputeWakeupTimerRegValues(lDesiredUsec , &tmpBuffer[1] , &tmpBuffer[0], &multi);

  S2LPSpiReadRegisters(PROTOCOL2_ADDR, 1, &tmp);
  tmp &= ~LDC_TIMER_MULT_REGMASK;
  tmp |= multi;
  S2LPSpiWriteRegisters(PROTOCOL2_ADDR, 1, &tmp);

  g_xStatus = S2LPSpiWriteRegisters(TIMERS1_ADDR, 2, tmpBuffer);
}


   
                                                                                                                          
                                                                    
                                                
                                             
               
   
void S2LPTimerSetWakeUpTimerReloadCounter(uint8_t cCounter)
{
  g_xStatus = S2LPSpiWriteRegisters(TIMERS0_ADDR, 1, &cCounter);
}


   
                                                                                                                            
                                                                    
                                                    
                                             
               
   
void S2LPTimerSetWakeUpTimerReloadPrescaler(uint8_t cPrescaler)
{
  g_xStatus = S2LPSpiWriteRegisters(TIMERS1_ADDR, 1, &cPrescaler);
}


   
                                                                                                                                     
                                                                                                                                  
                                              
                                                                                         
                                              
                                                                                             
                                              
                
   
void S2LPTimerGetWakeUpTimerReloadUs(uint32_t* plWakeUpReloadUsec, uint8_t* pcCounter, uint8_t* pcPrescaler, uint8_t* pcMulti)
{
  uint8_t tmpBuffer[2], tmp;
  
  S2LPSpiReadRegisters(PROTOCOL2_ADDR, 1, &tmp);
  tmp &= LDC_TIMER_MULT_REGMASK;
  *pcMulti = tmp;

  g_xStatus = S2LPSpiReadRegisters(TIMERS3_ADDR, 2, tmpBuffer);
  *pcCounter = tmpBuffer[1];
  *pcPrescaler = tmpBuffer[0];

  S2LPTimerComputeWakeupTimerValues(plWakeUpReloadUsec, tmpBuffer[1], tmpBuffer[0], tmp);
}


   
                                              
                                             
                                                                          
               
   
void S2LPTimerSetRxTimerStopCondition(RxTimeoutStopCondition xStopCondition)
{
  uint8_t tmp;
  s_assert_param(IS_RX_TIMEOUT_STOP_CONDITION(xStopCondition));

  S2LPSpiReadRegisters(PROTOCOL2_ADDR, 1, &tmp);
  tmp &= ~(CS_TIMEOUT_MASK_REGMASK | SQI_TIMEOUT_MASK_REGMASK | PQI_TIMEOUT_MASK_REGMASK);
  tmp |= (((uint8_t)xStopCondition) << 5);
  S2LPSpiWriteRegisters(PROTOCOL2_ADDR, 1, &tmp);

  S2LPSpiReadRegisters(PCKT_FLT_OPTIONS_ADDR, 1, &tmp);
  tmp &= ~RX_TIMEOUT_AND_OR_SEL_REGMASK;
  tmp |= (((uint8_t)xStopCondition) >> 1);
  g_xStatus = S2LPSpiWriteRegisters(PCKT_FLT_OPTIONS_ADDR, 1, &tmp);
}


   
                                                  
                                                                                          
                                              
   
uint16_t S2LPTimerGetRcoFrequency(void)
{
  uint32_t xtal=S2LPRadioGetXtalFrequency();
  
  switch(xtal)
  {
  case 24000000:
  case 48000000:
    return 32000;
  case 25000000:
  case 50000000:
    return 33300;
  }
  return 34700;
}


   
                                                 
               
               
   
void S2LpTimerFastRxTermTimer(SFunctionalState xNewState)
{
  uint8_t tmp;
  s_assert_param(IS_SFUNCTIONAL_STATE(xNewState));

  S2LPSpiReadRegisters(PROTOCOL1_ADDR, 1, &tmp);
  if(xNewState == S_ENABLE) {
    tmp |= FAST_CS_TERM_EN_REGMASK;
  }
  else {
    tmp &= ~FAST_CS_TERM_EN_REGMASK;
  }
  g_xStatus = S2LPSpiWriteRegisters(PROTOCOL1_ADDR, 1, &tmp);  
}


   
                                                                                               
                                  
                                                                             
                                                                       
               
   
void S2LpSetTimerFastRxTermTimer(uint8_t fast_rx_word)
{
  g_xStatus = S2LPSpiWriteRegisters(FAST_RX_TIMER_ADDR, 1, &fast_rx_word);  
}


   
                                                                           
                                                                            
                                                               
               
                                                                                           
   
void S2LpSetTimerFastRxTermTimerUs(uint32_t fast_rx_us)
{
  uint8_t tmp,fast_rx_word;
  
  S2LPSpiReadRegisters(CHFLT_ADDR, 1, &tmp);
    
  uint32_t f_dig=S2LPRadioGetXtalFrequency();
  if(f_dig > DIG_DOMAIN_XTAL_THRESH) {
    f_dig = f_dig/2;
  }
     
  s_assert_param(fast_rx_us<(1000000*0xff)/(f_dig/24/(1<<(tmp&0x0F))));
  
  
  fast_rx_word=((f_dig/24/(1<<(tmp&0x0F)))*fast_rx_us)/1000000;
  g_xStatus = S2LPSpiWriteRegisters(FAST_RX_TIMER_ADDR, 1, &fast_rx_word);  
}


   
                                                                                              
              
                                                              
                                                                
               
   
void S2LPTimerCalibrationRco(SFunctionalState xCalibration)
{
  uint8_t tmp;
  
  s_assert_param(IS_SFUNCTIONAL_STATE(xCalibration));
  
  S2LPSpiReadRegisters(XO_RCO_CONF0_ADDR, 1, &tmp);
  
  if(xCalibration == S_ENABLE) {
    tmp |= RCO_CALIBRATION_REGMASK;
  } else {
    tmp &= ~RCO_CALIBRATION_REGMASK;
  }
  g_xStatus = S2LPSpiWriteRegisters(XO_RCO_CONF0_ADDR, 1, &tmp);  
}

   
                                                                               
              
                                                      
                                                       
               
   
void S2LPTimerSleepB(SFunctionalState en)
{
  uint8_t tmp;
  
  s_assert_param(IS_SFUNCTIONAL_STATE(en));
  
  S2LPSpiReadRegisters(PM_CONF0_ADDR, 1, &tmp);
  
  if(en == S_ENABLE) {
    tmp |= SLEEP_MODE_SEL_REGMASK;
  } else {
    tmp &= ~SLEEP_MODE_SEL_REGMASK;
  }
  g_xStatus = S2LPSpiWriteRegisters(PM_CONF0_ADDR, 1, &tmp); 
}

void S2LPTimerLdcIrqWa(SFunctionalState en)
{
  uint8_t tmp[2]={0x00,0x60};

  if(en)
  {
    tmp[0]=0x01; tmp[1]=0x64;
    
    do
    {
      S2LPRefreshStatus();
    }
    while(g_xStatus.MC_STATE!=0x7C);
  }

  g_xStatus = S2LPSpiWriteRegisters(0x7B, 1, &tmp[1]); 
  g_xStatus = S2LPSpiWriteRegisters(0x7A, 1, &tmp[0]); 
}


   
    
   


   
    
   


   
    
   



/******************* (C) COPYRIGHT 2016 STMicroelectronics *****END OF FILE****/
