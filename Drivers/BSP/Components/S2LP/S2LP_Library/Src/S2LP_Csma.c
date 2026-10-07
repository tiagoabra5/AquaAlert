/**
 * @file    S2LP_Csma.c
 * @author  LowPower RF BU - AMG
 * @version 1.3.0
 * @date    10-July-2017
 * @brief   Configuration and management of S2-LP CSMA.
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


                                                                                
#include "S2LP_Csma.h"
#include "MCU_Interface.h"


   
                             
     
   


   
                        
     
   


   
                                                                             
     
   


   
    
   


   
                                                                    
     
   

   
    
   

   
                                                                  
     
   
#define IS_CCA_PERIOD(PERIOD)   (PERIOD == CSMA_PERIOD_64TBIT || \
				 PERIOD == CSMA_PERIOD_128TBIT || \
				 PERIOD == CSMA_PERIOD_256TBIT || \
				 PERIOD == CSMA_PERIOD_512TBIT)

#define IS_CSMA_LENGTH(LENGTH)	     (LENGTH < 16)

#define IS_BU_COUNTER_SEED(SEED)	   (SEED!=0)
#define IS_BU_PRESCALER(PRESCALER)	 (PRESCALER<64)
#define IS_CMAX_NB(NB)			         (NB<8)

   
    
   


   
                                                                      
     
   

   
    
   



   
                                                                               
     
   

   
    
   


   
                                                                      
     
   


   
                                                                                           
                                          
                                                         
                
   
void S2LPCsmaInit(SCsmaInit* pxCsmaInit)
{
  uint8_t tmpBuffer[4];

                            
  s_assert_param(IS_SFUNCTIONAL_STATE(pxCsmaInit->xCsmaPersistentMode));
  s_assert_param(IS_CCA_PERIOD(pxCsmaInit->xMultiplierTbit));
  s_assert_param(IS_CSMA_LENGTH(pxCsmaInit->xCcaLength));
  s_assert_param(IS_BU_COUNTER_SEED(pxCsmaInit->nBuCounterSeed));
  s_assert_param(IS_BU_PRESCALER(pxCsmaInit->cBuPrescaler));
  s_assert_param(IS_CMAX_NB(pxCsmaInit->cMaxNb));

                                         
  tmpBuffer[0] = (uint8_t)(pxCsmaInit->nBuCounterSeed >> 8);

                                         
  tmpBuffer[1] = (uint8_t) pxCsmaInit->nBuCounterSeed;

                                                      
  tmpBuffer[2] = (pxCsmaInit->cBuPrescaler << 2) | pxCsmaInit->xMultiplierTbit;

                                                         
  tmpBuffer[3] = (pxCsmaInit->xCcaLength<<4) | pxCsmaInit->cMaxNb;

                                                                                                 
  S2LPSpiWriteRegisters(CSMA_CONF3_ADDR, 4, tmpBuffer);

  S2LPSpiReadRegisters(PROTOCOL1_ADDR, 1, &tmpBuffer[0]);
  
                                                
  if(pxCsmaInit->xCsmaPersistentMode==S_ENABLE) {
    tmpBuffer[0] |= CSMA_PERS_ON_REGMASK;
  }
  else {
    tmpBuffer[0] &= ~CSMA_PERS_ON_REGMASK;
  }

                                      
  g_xStatus = S2LPSpiWriteRegisters(PROTOCOL1_ADDR, 1, &tmpBuffer[0]);


}


    
                                                                                     
                                                   
                                                          
                 
    
void S2LPCsmaGetInfo(SCsmaInit* pxSCsmaInit)
{
   uint8_t tmpBuffer[4];

                                      
   S2LPSpiReadRegisters(PROTOCOL1_ADDR, 1, &tmpBuffer[0]);

                                             
   pxSCsmaInit->xCsmaPersistentMode = (SFunctionalState)((tmpBuffer[0]&CSMA_PERS_ON_REGMASK) >> 1);

                                          
   g_xStatus = S2LPSpiReadRegisters(CSMA_CONF3_ADDR, 4, tmpBuffer);

                                  
   pxSCsmaInit->nBuCounterSeed = (((uint16_t)tmpBuffer[0]) << 8) | (uint16_t)tmpBuffer[1];

                               
   pxSCsmaInit->cBuPrescaler = tmpBuffer[2]>>2;

                             
   pxSCsmaInit->xMultiplierTbit = (SCsmaPeriod)(tmpBuffer[2] & CCA_PERIOD_REGMASK);

                             
   pxSCsmaInit->xCcaLength = (tmpBuffer[3]&CCA_LEN_REGMASK)>>4;

                                         
   pxSCsmaInit->cMaxNb = tmpBuffer[3] & NBACKOFF_MAX_REGMASK;

}


   
                                       
                                                
                                                        
                
   
void S2LPCsma(SFunctionalState xNewState)
{
  uint8_t tmp, tmp2;
  s_assert_param(IS_SFUNCTIONAL_STATE(xNewState));

  S2LPSpiReadRegisters(PROTOCOL1_ADDR, 1, &tmp);

                                        
  if(xNewState==S_ENABLE)
  {
    tmp |= CSMA_ON_REGMASK;
    
    S2LPSpiReadRegisters(PM_CONF0_ADDR, 1, &tmp2);
    tmp2 |= SLEEP_MODE_SEL_REGMASK;
    S2LPSpiWriteRegisters(PM_CONF0_ADDR, 1, &tmp2);
  }
  else
  {
    tmp &= ~CSMA_ON_REGMASK;
  }

  g_xStatus = S2LPSpiWriteRegisters(PROTOCOL1_ADDR, 1, &tmp);

}

   
                                                                 
                
                                       
   
SFunctionalState S2LPCsmaGetCsma(void)
{
  uint8_t tmp;

                                          
  g_xStatus = S2LPSpiReadRegisters(PROTOCOL1_ADDR, 1, &tmp);

                              
  if(tmp & CSMA_ON_REGMASK) {
    return S_ENABLE;
  }
  else {
    return S_DISABLE;
  }

}

   
                                                        
                                                           
                                                        
                
   
void S2LPCsmaPersistentMode(SFunctionalState xNewState)
{
  uint8_t tmp;
  s_assert_param(IS_SFUNCTIONAL_STATE(xNewState));

  S2LPSpiReadRegisters(PROTOCOL1_ADDR, 1, &tmp);

                                                 
  if(xNewState==S_ENABLE) {
    tmp |= CSMA_PERS_ON_REGMASK;
  }
  else {
    tmp &= ~CSMA_PERS_ON_REGMASK;
  }

  g_xStatus = S2LPSpiWriteRegisters(PROTOCOL1_ADDR, 1, &tmp);

}


   
                                         
                
                                                  
   
SFunctionalState S2LPCsmaGetPersistentMode(void)
{
  uint8_t tmp;

  g_xStatus = S2LPSpiReadRegisters(PROTOCOL1_ADDR, 1, &tmp);

  if(tmp & CSMA_PERS_ON_REGMASK) {
    return S_ENABLE;
  }
  else {
    return S_DISABLE;
  }

}


   
                                                                                                                                                                
                                                       
                                                   
                
   
void S2LPCsmaSeedReloadMode(SFunctionalState xNewState)
{
  uint8_t tmp;
  s_assert_param(IS_SFUNCTIONAL_STATE(xNewState));

  S2LPSpiReadRegisters(PROTOCOL1_ADDR, 1, &tmp);

                                             
  if(xNewState==S_ENABLE) {
    tmp |= SEED_RELOAD_REGMASK;
  }
  else {
    tmp &= ~SEED_RELOAD_REGMASK;
  }

  g_xStatus = S2LPSpiWriteRegisters(PROTOCOL1_ADDR, 1, &tmp);

}


   
                                     
                
                                                   
   
SFunctionalState S2LPCsmaGetSeedReloadMode(void)
{
  uint8_t tmp;

  g_xStatus = S2LPSpiReadRegisters(PROTOCOL1_ADDR, 1, &tmp);

                              
  if(tmp & SEED_RELOAD_REGMASK) {
    return S_ENABLE;
  }
  else {
    return S_DISABLE;
  }
}


   
                                                                                                                                  
                                                                                              
                                    
                
   
void S2LPCsmaSetBuCounterSeed(uint16_t nBuCounterSeed)
{
  uint8_t tmpBuffer[2];
  s_assert_param(IS_BU_COUNTER_SEED(nBuCounterSeed));

  tmpBuffer[0] = (uint8_t)(nBuCounterSeed>>8);
  tmpBuffer[1] = (uint8_t)nBuCounterSeed;

  g_xStatus = S2LPSpiWriteRegisters(CSMA_CONF3_ADDR, 2, tmpBuffer);

}

   
                                                                 
                
                                                                                        
   
uint16_t S2LPCsmaGetBuCounterSeed(void)
{
  uint8_t tmpBuffer[2];

  g_xStatus = S2LPSpiReadRegisters(CSMA_CONF3_ADDR, 2, tmpBuffer);

  return ((((uint16_t)tmpBuffer[0])<<8) + (uint16_t)tmpBuffer[1]);
}


   
                                                                                                    
                                                             
                                    
                
   
void S2LPCsmaSetBuPrescaler(uint8_t cBuPrescaler)
{
  uint8_t tmp;
  s_assert_param(IS_BU_PRESCALER(cBuPrescaler));

  S2LPSpiReadRegisters(CSMA_CONF1_ADDR, 1, &tmp);

  tmp &= ~BU_PRSC_REGMASK;
  tmp |= (cBuPrescaler<<2);

  g_xStatus = S2LPSpiWriteRegisters(CSMA_CONF1_ADDR, 1, &tmp);
}


   
                                   
                
                                            
   
uint8_t S2LPCsmaGetBuPrescaler(void)
{
  uint8_t tmp;

  g_xStatus = S2LPSpiReadRegisters(CSMA_CONF1_ADDR, 1, &tmp);

  return (tmp >> 2);
}


   
                              
                                                        
                                                       
                
   
void S2LPCsmaSetCcaPeriod(SCsmaPeriod xMultiplierTbit)
{
  uint8_t tmp;
  s_assert_param(IS_CCA_PERIOD(xMultiplierTbit));

  S2LPSpiReadRegisters(CSMA_CONF1_ADDR, 1, &tmp);

  tmp &= ~CCA_PERIOD_REGMASK;
  tmp |= xMultiplierTbit;

  g_xStatus = S2LPSpiWriteRegisters(CSMA_CONF1_ADDR, 1, &tmp);

}


   
                                 
                
                                
   
uint8_t S2LPCsmaGetCcaPeriod(void)
{
  uint8_t tmp;

  g_xStatus = S2LPSpiReadRegisters(CSMA_CONF1_ADDR, 1, &tmp);

  return (SCsmaPeriod)(tmp & CCA_PERIOD_REGMASK);
}


   
                              
                                                                                               
                                                         
                
   
void S2LPCsmaSetCcaLength(uint8_t xCcaLength)
{
  uint8_t tmp;
  s_assert_param(IS_CSMA_LENGTH(xCcaLength));

  S2LPSpiReadRegisters(CSMA_CONF0_ADDR, 1, &tmp);

  tmp &= ~CCA_LEN_REGMASK;
  tmp |= xCcaLength;

  g_xStatus = S2LPSpiWriteRegisters(CSMA_CONF0_ADDR, 1, &tmp);

}


   
                                 
                
                              
   
uint8_t S2LPCsmaGetCcaLength(void)
{
  uint8_t tmp;

  g_xStatus = S2LPSpiReadRegisters(CSMA_CONF0_ADDR, 1, &tmp);

  return (tmp >> 4);
}


   
                                                                                  
                                             
                                        
                
   
void S2LPCsmaSetMaxNumberBackoff(uint8_t cMaxNb)
{
  uint8_t tmp;
  s_assert_param(IS_CMAX_NB(cMaxNb));

  S2LPSpiReadRegisters(CSMA_CONF0_ADDR, 1, &tmp);

  tmp &= ~NBACKOFF_MAX_REGMASK;
  tmp |= cMaxNb;

  g_xStatus = S2LPSpiWriteRegisters(CSMA_CONF0_ADDR, 1, &tmp);
}

   
                                             
                
                                          
   
uint8_t S2LPCsmaGetMaxNumberBackoff(void)
{
  uint8_t tmp;

  g_xStatus = S2LPSpiReadRegisters(CSMA_CONF0_ADDR, 1, &tmp);

  return (tmp & NBACKOFF_MAX_REGMASK);

}


   
    
   

   
    
   


   
    
   



/******************* (C) COPYRIGHT 2016 STMicroelectronics *****END OF FILE****/
