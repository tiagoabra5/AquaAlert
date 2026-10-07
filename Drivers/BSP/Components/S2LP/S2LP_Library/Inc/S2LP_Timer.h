/**
 * @file    S2LP_Timer.h
 * @author  LowPower RF BU - AMG
 * @version 1.3.0
 * @date    10-July-2017
 * @brief   Configuration and management of S2-LP Timers.
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
 * This module provides API to configure the S2-LP timing mechanisms.
 * They allow the user to set the timer registers using raw values or
 * compute them since the desired timer value is expressed in ms.
 * Moreover the management of the S2-LP LDCR mode can be done using
 * these API.
 *
 * <b>Example:</b>
 * @code
 *   ...
 *
 *   S2LPTimerSetRxTimeoutMs(50.0);
 *   S2LPTimerSetWakeUpTimerUs(150000);
 * 
 *   // IRQ configuration for RX_TIMEOUT and WAKEUP_TIMEOUT
 *   ...
 *
 *   S2LPTimerLdcrMode(S_ENABLE);
 *
 *   ...
 *
 * @endcode
 *
 *
 * <h2><center>&copy; COPYRIGHT 2019 STMicroelectronics</center></h2>
 */


                                                                                
#ifndef __S2LP1_TIMER_H
#define __S2LP1_TIMER_H


                                                                                
#include "S2LP_Regs.h"
#include "S2LP_Types.h"


#ifdef __cplusplus
 extern "C" {
#endif

   
                             
     
   


   
                                           
                                                      
                                                                   
     
   


   
                                                            
     
   

   
                                                                   
   
typedef enum {
     NO_TIMEOUT_STOP = 0x00,                                             
     PQI_ABOVE_THRESHOLD = 0x01,                                                          
     SQI_ABOVE_THRESHOLD = 0x02,                                                          
     SQI_AND_PQI_ABOVE_THRESHOLD = 0x03,                                                               
     RSSI_ABOVE_THRESHOLD = 0x04,                                                          
     RSSI_AND_PQI_ABOVE_THRESHOLD = 0x05,                                                               
     RSSI_AND_SQI_ABOVE_THRESHOLD = 0x06,                                                               
     ALL_ABOVE_THRESHOLD = 0x07,                                                                                 
     TIMEOUT_ALWAYS_STOPPED = 0x08,                                                 
     SQI_OR_PQI_ABOVE_THRESHOLD = 0x0B,                                                                          
     RSSI_OR_PQI_ABOVE_THRESHOLD = 0x0D,                                                                          
     RSSI_OR_SQI_ABOVE_THRESHOLD = 0x0E,                                                                          
     ANY_ABOVE_THRESHOLD = 0x0F                                                                                      
} RxTimeoutStopCondition;


   
     
   


   
                                                                
     
   


   
     
   


   
                                                                     
     
   

#define SET_INFINITE_RX_TIMEOUT()     S2LPTimerSetRxTimerCounter(0)

   
     
   


   
                                                                        
     
   

void S2LPTimerSetRxTimerStopCondition(RxTimeoutStopCondition xStopCondition);

void S2LPTimerLdcrMode(SFunctionalState xNewState);
void S2LPTimerLdcrAutoReload(SFunctionalState xNewState);
SFunctionalState S2LPTimerLdcrGetAutoReload(void);
void S2LpTimerFastRxTermTimer(SFunctionalState xNewState);
void S2LpSetTimerFastRxTermTimer(uint8_t fast_rx_word);
void S2LpSetTimerFastRxTermTimerUs(uint32_t fast_rx_us);

void S2LPTimerLdcrMode(SFunctionalState xNewState);
void S2LPTimerLdcrAutoReload(SFunctionalState xNewState);
SFunctionalState S2LPTimerLdcrGetAutoReload(void);

void S2LPTimerSetRxTimer(uint8_t cCounter , uint8_t cPrescaler);
void S2LPTimerSetRxTimerUs(uint32_t lDesiredUsec);
void S2LPTimerSetRxTimerCounter(uint8_t cCounter);
void S2LPTimerSetRxTimerPrescaler(uint8_t cPrescaler);
void S2LPTimerGetRxTimerUs(uint32_t* plTimeoutUsec, uint8_t* pcCounter , uint8_t* pcPrescaler);

void S2LPTimerSetWakeUpTimer(uint8_t cCounter , uint8_t cPrescaler);
void S2LPTimerSetWakeUpTimerUs(uint32_t lDesiredUsec);
void S2LPTimerSetWakeUpTimerCounter(uint8_t cCounter);
void S2LPTimerSetWakeUpTimerPrescaler(uint8_t cPrescaler);
void S2LPTimerSetWakeUpTimerReloadUs(uint32_t lDesiredUsec);
void S2LPTimerGetWakeUpTimerUs(uint32_t* plWakeUpUsec, uint8_t* pcCounter, uint8_t* pcPrescaler, uint8_t* pcMulti);
void S2LPTimerSetWakeUpTimerReload(uint8_t cCounter , uint8_t cPrescaler, uint8_t cMulti);
void S2LPTimerSetWakeUpTimerReloadCounter(uint8_t cCounter);
void S2LPTimerSetWakeUpTimerReloadPrescaler(uint8_t cPrescaler);
void S2LPTimerGetWakeUpTimerReloadUs(uint32_t* plWakeUpReloadUsec, uint8_t* pcCounter, uint8_t* pcPrescaler, uint8_t* pcMulti);

uint16_t S2LPTimerGetRcoFrequency(void);
void S2LPTimerCalibrationRco(SFunctionalState xCalibration);
void S2LPTimerSleepB(SFunctionalState en);
void S2LPTimerLdcIrqWa(SFunctionalState en);
   
     
   

   
     
   


   
     
   

#ifdef __cplusplus
}
#endif

#endif

/******************* (C) COPYRIGHT 2016 STMicroelectronics *****END OF FILE****/
