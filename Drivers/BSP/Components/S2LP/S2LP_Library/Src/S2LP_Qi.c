/**
 * @file    S2LP_Qi.c
 * @author  LowPower RF BU - AMG
 * @version 1.3.0
 * @date    10-July-2017
 * @brief   Configuration and management of S2-LP QI.
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


                                                                                
#include "S2LP_Qi.h"
#include "MCU_Interface.h"



   
                             
     
   


   
                      
     
   


   
                                                                            
     
   

   
    
   


   
                                                                  
     
   

   
    
   


   
                                                                 
     
   

#define IS_RSSI_MODE(MODE)            (MODE<=3)
#define IS_RSSI_DBM(VAL)              ((VAL>=-146) && (VAL<=-2))
#define IS_RSSI_FLT(VAL)              (VAL<=15)
#define IS_PQI_LVL_CHECK(VAL)         (VAL<=15)
#define S2LPRadioRegToRssidBm(VAL)    (VAL - 146)
#define S2LPRadioRssidBmToReg(VAL)    (uint8_t)(VAL+146)

   
    
   


   
                                                                    
     
   

   
    
   


   
                                                                              
     
   

   
    
   


   
                                                                    
     
   

   
                                   
                
                              
   
int32_t S2LPRadioGetRssidBm(void)
{
  uint8_t tmp;
  g_xStatus = S2LPSpiReadRegisters(RSSI_LEVEL_ADDR, 1, &tmp);  
  return S2LPRadioRegToRssidBm((int32_t)tmp);
}

   
                                                         
                
                              
   
int32_t S2LPRadioGetRssidBmRun(void)
{
  uint8_t tmpBuffer[2];
  
                                                                                       
                                                       
  g_xStatus = S2LPSpiReadRegisters(RSSI_LEVEL_RUN_ADDR, 2, tmpBuffer);  
  
  return S2LPRadioRegToRssidBm((int32_t)tmpBuffer[1]);
}



   
                                         
                                
                
   
void S2LPRadioSetRssiThreshdBm(int32_t wRssiThrehsold)
{
  uint8_t tmp;
  s_assert_param(IS_RSSI_DBM(wRssiThrehsold));
  
  tmp = S2LPRadioRssidBmToReg(wRssiThrehsold);
  g_xStatus = S2LPSpiWriteRegisters(RSSI_TH_ADDR, 1, &tmp);  
}



   
                                          
                                                                        
               
  
void S2LPRadioRssiInit(SRssiInit* xSRssiInit)
{
  uint8_t tmpBuffer[2];

  s_assert_param(IS_RSSI_MODE(xSRssiInit->xRssiMode));
  s_assert_param(IS_RSSI_DBM(xSRssiInit->cRssiThreshdBm));
  s_assert_param(IS_RSSI_FLT(xSRssiInit->cRssiFlt));
  
                                           
  S2LPSpiReadRegisters(RSSI_FLT_ADDR, 1, &tmpBuffer[0]);
  
                                                   
  tmpBuffer[0] &= ~(RSSI_FLT_REGMASK | CS_MODE_REGMASK);
  tmpBuffer[0] |= (xSRssiInit->cRssiFlt<<4);
  tmpBuffer[0] |= (xSRssiInit->xRssiMode<<2);
  
  tmpBuffer[1] = S2LPRadioRssidBmToReg(xSRssiInit->cRssiThreshdBm);
    
  g_xStatus = S2LPSpiWriteRegisters(RSSI_FLT_ADDR, 2, tmpBuffer);
}


   
                                                                                     
                                          
                                                                                            
               
  
void S2LPRadioGetRssiInfo(SRssiInit* xSRssiInit)
{
  uint8_t tmpBuffer[2];

  S2LPSpiReadRegisters(RSSI_FLT_ADDR, 2, tmpBuffer);
  
  xSRssiInit->xRssiMode = (SRssiMode)((tmpBuffer[0]&CS_MODE_REGMASK)>>2);
  xSRssiInit->cRssiFlt = (tmpBuffer[0]&RSSI_FLT_REGMASK)>>4;
  xSRssiInit->cRssiThreshdBm = S2LPRadioRegToRssidBm(tmpBuffer[1]);
  
}


   
                                             
                                     
               
  
void S2LPRadioCsBlanking(SFunctionalState xCsBlank)
{
  uint8_t tmp;
  
  s_assert_param(IS_SFUNCTIONAL_STATE(xCsBlank));
  
  S2LPSpiReadRegisters(ANT_SELECT_CONF_ADDR, 1, &tmp);
  
  if(xCsBlank == S_ENABLE) {
    tmp |= CS_BLANKING_REGMASK;
  } else {
    tmp &= ~CS_BLANKING_REGMASK;
  }
  g_xStatus = S2LPSpiWriteRegisters(ANT_SELECT_CONF_ADDR, 1, &tmp);
  
}


   
                                                  
                                           
               
  
void S2LPRadioAntennaSwitching(SFunctionalState xAntennaSwitch)
{
  uint8_t tmp;
  
  s_assert_param(IS_SFUNCTIONAL_STATE(xAntennaSwitch));
  
  S2LPSpiReadRegisters(ANT_SELECT_CONF_ADDR, 1, &tmp);
  
  if(xAntennaSwitch == S_ENABLE) {
    tmp |= AS_ENABLE_REGMASK;
  } else {
    tmp &= ~AS_ENABLE_REGMASK;
  }
  g_xStatus = S2LPSpiWriteRegisters(ANT_SELECT_CONF_ADDR, 1, &tmp);
  
}


   
                            
                    
               
  
void S2LPRadioSetPqiCheck(uint8_t cPqiLevel)
{
  uint8_t tmp;
  s_assert_param(IS_PQI_LVL_CHECK(cPqiLevel));

  S2LPSpiReadRegisters(QI_ADDR, 1, &tmp);
  tmp &= ~PQI_TH_REGMASK;
  tmp |= (((uint8_t)cPqiLevel)<<1);
  S2LPSpiWriteRegisters(QI_ADDR, 1, &tmp);
  
}

   
                                                                                                
                                                                                                               
                                             
                                                        
                
   
void S2LPQiSqiCheck(SFunctionalState xNewState)
{
  uint8_t tmp;

                            
  s_assert_param(IS_S2LP_FUNCTIONAL_STATE(xNewState));

                                   
   S2LPSpiReadRegisters(QI_ADDR, 1, &tmp);

                                                                     
  if(xNewState == S_ENABLE)
  {
    tmp |= SQI_EN_REGMASK;
  }
  else
  {
    tmp &= ~SQI_EN_REGMASK;
  }

                                       
  S2LPSpiWriteRegisters(QI_ADDR, 1, &tmp);

}


   
                                                              
                                                                                                                               
                                                                                                                                
                   
                                                  
                                             
                
   
void S2LPQiSetSqiThreshold(SqiThreshold xSqiThr)
{
  uint8_t tmp;

                            
  s_assert_param(IS_SQI_THR(xSqiThr));

                                   
  S2LPSpiReadRegisters(QI_ADDR, 1, &tmp);

                                                   
  tmp &= ~SQI_TH_REGMASK;
  tmp |= ((uint8_t)xSqiThr);

                                               

  S2LPSpiWriteRegisters(QI_ADDR, 1, &tmp);
}


   
                                                   
               
                        
  
SFlagStatus S2LPQiGetCs(void)
{
  uint8_t tmp;

  S2LPSpiReadRegisters(LINK_QUALIF1_ADDR, 1, &tmp);
  tmp = (tmp&CS_REGMASK)>>7;
  return (SFlagStatus)tmp;
}



   
    
   

   
    
   


   
    
   



/******************* (C) COPYRIGHT 2016 STMicroelectronics *****END OF FILE****/
