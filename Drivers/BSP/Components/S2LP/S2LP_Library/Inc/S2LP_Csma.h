/**
 * @file    S2LP_Csma.h
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
*
* <b>Example:</b>
* @code
*
* CsmaInit csmaInit={
*   S_DISABLE,         // persistent mode
*   TBIT_TIME_64,      // Tbit time
*   TCCA_TIME_3,       // Tcca time
*   5,                 // max number of backoffs
*   0xFA21,            // BU counter seed
*   32                 // CU prescaler
* };
*
* ...
*
* S2LPCsmaInit(&csmaInit);
* S2LPCsma(S_ENABLE);
*
*
* @endcode
*
* @note The CS status depends of the RSSI threshold set. Please see the S2LP_Qi
* module for details.
* <h2><center>&copy; COPYRIGHT 2019 STMicroelectronics</center></h2>
*/


                                                                                
#ifndef __S2LP_CSMA_H
#define __S2LP_CSMA_H


                                                                                
#include "S2LP_Types.h"
#include "S2LP_Regs.h"


#ifdef __cplusplus
 extern "C" {
#endif


   
                             
     
   


   
                                  
                                                    
                                                                  
     
   

   
                                                           
     
   


   
                                                                         
   
   
typedef enum {
  CSMA_PERIOD_64TBIT,                                                 
  CSMA_PERIOD_128TBIT,                                                
  CSMA_PERIOD_256TBIT,                                                
  CSMA_PERIOD_512TBIT                                                
}SCsmaPeriod;


   
                                               
    
typedef struct {
  SFunctionalState  xCsmaPersistentMode;                                           
  SCsmaPeriod       xMultiplierTbit;                                                                          
  uint8_t           xCcaLength;                                                                                      
  uint8_t           cMaxNb;                                                                                 
  uint16_t          nBuCounterSeed;                                               
  uint8_t           cBuPrescaler;                                                            
} SCsmaInit;


   
    
   


   
                                                               
     
   

   
                                                       
     
   


   
    
   

   
    
   


   
                                                            
     
   


   
    
   


   
                                                               
     
   

void S2LPCsmaInit(SCsmaInit* pxSCsmaInit);
void S2LPCsmaGetInfo(SCsmaInit* pxSCsmaInit);
void S2LPCsma(SFunctionalState xNewState);
SFunctionalState S2LPCsmaGetCsma(void);
void S2LPCsmaPersistentMode(SFunctionalState xNewState);
SFunctionalState S2LPCsmaGetPersistentMode(void);
void S2LPCsmaSeedReloadMode(SFunctionalState xNewState);
SFunctionalState S2LPCsmaGetSeedReloadMode(void);
void S2LPCsmaSetBuCounterSeed(uint16_t nBuCounterSeed);
uint16_t S2LPCsmaGetBuCounterSeed(void);
void S2LPCsmaSetBuPrescaler(uint8_t cBuPrescaler);
uint8_t S2LPCsmaGetBuPrescaler(void);
void S2LPCsmaSetCcaPeriod(SCsmaPeriod xMultiplierTbit);
uint8_t S2LPCsmaGetCcaPeriod(void);
void S2LPCsmaSetCcaLength(uint8_t xCcaLength);
uint8_t S2LPCsmaGetCcaLength(void);
void S2LPCsmaSetMaxNumberBackoff(uint8_t cMaxNb);
uint8_t S2LPCsmaGetMaxNumberBackoff(void);

   
    
   

   
    
   


   
    
   

#ifdef __cplusplus
}
#endif

#endif

/******************* (C) COPYRIGHT 2016 STMicroelectronics *****END OF FILE****/
