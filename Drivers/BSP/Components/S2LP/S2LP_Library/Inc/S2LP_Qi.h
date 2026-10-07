/**
 * @file    S2LP_Qi.h
 * @author  LowPower RF BU - AMG
 * @version 1.3.0
 * @date    10-July-2017
 * @brief   Configuration and management of S2LP QI.
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
 * This module can be used to configure and read some quality indicators
 * used by S2-LP.
 * API to set thresholds and to read values in raw mode or in dBm are
 * provided.
 *
 * <b>Example:</b>
 * @code
 *
 *   int32_t rssiValuedBm;
 *   uint8_t pqiValue, sqiValue;
 *
 *   S2LPQiPqiCheck(S_ENABLE);
 *   S2LPQiSqiCheck(S_ENABLE);
 *
 *   ...
 *
 *   rssiValueDbm = S2LPQiGetRssidBm();
 *   pqiValue = S2LPQiGetPqi();
 *   sqiValue = S2LPQiGetSqi();
 *
 *   ...
 *
 * @endcode
 *
 *
 * <h2><center>&copy; COPYRIGHT 2019 STMicroelectronics</center></h2>
 */


                                                                                
#ifndef __S2LP_QI_H
#define __S2LP_QI_H


                                                                                

#include "S2LP_Regs.h"
#include "S2LP_Types.h"


#ifdef __cplusplus
 extern "C" {
#endif


   
                             
     
   


   
                                
                                                  
                                                                
     
   

   
                                                 
     
   

   
                                     
   
typedef enum {
  RSSI_STATIC_MODE = 0,                          
  RSSI_DYNAMIC_6DB_STEP_MODE,                                         
  RSSI_DYNAMIC_12DB_STEP_MODE,                                          
  RSSI_DYNAMIC_18DB_STEP_MODE                                           
} SRssiMode;


   
                                              
   
typedef struct {
  uint8_t      cRssiFlt;                                                      
  SRssiMode    xRssiMode;                                                 
  int32_t        cRssiThreshdBm;                                                              
} SRssiInit;

   
                                      
   
typedef enum
{
   SQI_TH_0=0x00,
   SQI_TH_1=0x40,
   SQI_TH_2=0x80,
   SQI_TH_3=0xC0

} SqiThreshold;

   
     
    


   
                                                             
     
   


   
     
    


   
                                                          
     
   


   
    
   


   
                                                              
     
   

int32_t S2LPRadioGetRssidBm(void);
int32_t S2LPRadioGetRssidBmRun(void);
void S2LPRadioSetRssiThreshdBm(int32_t wRssiThrehsold);
void S2LPRadioCsBlanking(SFunctionalState xCsBlank);
void S2LPRadioRssiInit(SRssiInit* xSRssiInit);
void S2LPRadioGetRssiInfo(SRssiInit* xSRssiInit);
void S2LPRadioAntennaSwitching(SFunctionalState xAntennaSwitch);
void S2LPRadioSetPqiCheck(uint8_t cPqiLevel);
SFlagStatus S2LPQiGetCs(void);
void S2LPQiSetSqiThreshold(SqiThreshold xSqiThr);
void S2LPQiSqiCheck(SFunctionalState xNewState);

   
    
   

   
    
   


   
    
   


#ifdef __cplusplus
}
#endif

#endif

/******************* (C) COPYRIGHT 2016 STMicroelectronics *****END OF FILE****/
