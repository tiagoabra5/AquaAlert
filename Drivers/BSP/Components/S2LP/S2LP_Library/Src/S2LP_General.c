/**
 * @file    S2LP_General.c
 * @author  LowPower RF BU - AMG
 * @version 1.3.0
 * @date    10-July-2017
 * @brief   Configuration and management of S2-LP General functionalities.
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

                                                                                
#include "S2LP_General.h"
#include "MCU_Interface.h"


   
                             
     
   


   
                           
     
   


   
                                                                                 
     
   

   
    
   


   
                                                                       
     
   

   
    
   


   
                                                                      
     
   

#define IS_MODE_EXT(MODE)   (MODE == MODE_EXT_XO || \
                             MODE == MODE_EXT_XIN)
   
    
   


   
                                                                         
     
   

   
    
   


   
                                                                                           
     
   

   
    
   


   
                                                                                         
     
   


   
                                  
                                                         
                                                              
                
   
void S2LPGeneralSetExtRef(ModeExtRef xExtMode)
{
  uint8_t tmp;
  s_assert_param(IS_MODE_EXT(xExtMode));

  S2LPSpiReadRegisters(XO_RCO_CONF0_ADDR, 1, &tmp);
  if(xExtMode == MODE_EXT_XO) {
    tmp &= ~EXT_REF_REGMASK;
  }
  else {
    tmp |= EXT_REF_REGMASK;
  }
  g_xStatus = S2LPSpiWriteRegisters(XO_RCO_CONF0_ADDR, 1, &tmp);

}


   
                                     
                
                                                 
                                                              
   
ModeExtRef S2LPGeneralGetExtRef(void)
{
  uint8_t tmp;
  g_xStatus = S2LPSpiReadRegisters(XO_RCO_CONF0_ADDR, 1, &tmp);
  return (ModeExtRef)(tmp & EXT_REF_REGMASK);
}


   
                                     
                
                              
   
uint8_t S2LPGeneralGetDevicePN(void)
{
  uint8_t tmp;
  g_xStatus = S2LPSpiReadRegisters(DEVICE_INFO1_ADDR, 1, &tmp);
  return tmp;
}

   
                               
                
                        
   
uint8_t S2LPGeneralGetVersion(void)
{
  uint8_t tmp;
  S2LPSpiReadRegisters(DEVICE_INFO0_ADDR, 1, &tmp);
  return tmp;
}


   
                                              
                                                                                                                        
                                                                
               
  
void S2LPRadioSetExternalSmpsMode(SFunctionalState xNewState)
{
  uint8_t tmp;
  s_assert_param(IS_SFUNCTIONAL_STATE(xNewState));
  
  S2LPSpiReadRegisters(PM_CONF4_ADDR, 1, &tmp);
  
  if(xNewState == S_ENABLE) {
    tmp |= EXT_SMPS_REGMASK;
  } else {
    tmp &= ~EXT_SMPS_REGMASK;
  }
  g_xStatus = S2LPSpiWriteRegisters(PM_CONF4_ADDR, 1, &tmp);
}

   
    
   


   
    
   


   
    
   


/******************* (C) COPYRIGHT 2016 STMicroelectronics *****END OF FILE****/
