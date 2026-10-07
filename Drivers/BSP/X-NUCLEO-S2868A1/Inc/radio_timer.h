/**
* @file    SDK_EVAL_Timers.c
* @author  AMG - RF Application team
* @version 3.2.1
* @date    26-September-2016
* @brief   SDK EVAL timers configuration.
* @details
*
* This module allows the user to easily configure the STM32L timers.
* The functions that are provided are limited to the generation of an
* IRQ every time the timer elapses.
*
* <b>Example:</b>
* @code
*
*   ...
*
*   RadioTimersTimConfig_ms(TIM2,60.0);
*
*   ...
*
*   RadioTimersState(TIM2, ENABLE);          // the timer starts counting here
*
*   ...
*
*   RadioTimersState(TIM2, DISABLE);         // timer stopped
*
*   ...
*
* @endcode
*
* THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
* WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
* TIME. AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY
* DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
* FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
* CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
*
* THIS SOURCE CODE IS PROTECTED BY A LICENSE.
* FOR MORE INFORMATION PLEASE CAREFULLY READ THE LICENSE AGREEMENT FILE LOCATED
* IN THE ROOT DIRECTORY OF THIS FIRMWARE PACKAGE.
*
* <h2><center>&copy; COPYRIGHT 2016 STMicroelectronics</center></h2>
*/

                                                                                
#ifndef __SDK_EVAL_TIMERS_H
#define __SDK_EVAL_TIMERS_H

                                                                                

#include "cube_hal.h"


#ifdef __cplusplus
 extern "C" {
#endif

   
                              
     
   

   
                                                       
                                      
                                                                        
     
   




   
                                                                                          
     
   

   
                                             
   
#define CLOCK_FREQUENCY         32000

   
    
   


   
                                                                                       
     
   

   
                                                                              
                                  
                                                               
                                      
                                      
               
   
#define RadioTimersTimConfig_ms(TIM_HANDLER_P , TIME)      {\
                                                        uint32_t n = (uint32_t)(TIME*CLOCK_FREQUENCY);\
                                                        uint16_t a,b;\
                                                        RadioTimersFindFactors(n,&a,&b);\
                                                        RadioTimersTimConfig(TIM_HANDLER_P,a-1,b-1);\
                                                      }

   
                                                             
                                  
                                                               
                                                                        
                                      
               
   
#define RadioTimersState(TIM_HANDLER_P , NEWSTATE)      {((uint8_t)NEWSTATE)?(HAL_TIM_Base_Start_IT(TIM_HANDLER_P)):(HAL_TIM_Base_Stop_IT(TIM_HANDLER_P));}


   
                                                  
                                  
                                                               
                                              
                                         
               
   
#define RadioTimersSetCounter(TIM_HANDLER_P,VALUE)   {__HAL_TIM_SET_COUNTER(TIM_HANDLER_P,VALUE);}


   
                                                  
                                  
                                                               
               
   
#define RadioTimersGetCounter(TIM_HANDLER_P)   __HAL_TIM_GET_COUNTER(TIM_HANDLER_P)

   
                                                  
                                    
                                                               
               
   
#define RadioTimersResetCounter(TIM_HANDLER_P)      {__HAL_TIM_SET_COUNTER(TIM_HANDLER_P,0);}


   
    
   


   
                                                                                          
     
   
   
#ifdef USE_SYSTICK_DELAY
void SysTick_Handler(void);
void SdkDelayMs(volatile uint32_t lTimeMs);
uint32_t SdkGetCurrentSysTick(void);
void SdkStartSysTick(void);
#endif

void RadioTimersFindFactors(uint32_t n, uint16_t *pnPrescaler, uint16_t *pnCounter);
void RadioTimersTimConfig(TIM_HandleTypeDef*  TIM_TimeBaseStructure, uint16_t nPrescaler, uint16_t nPeriod);


   
    
   

   
    
   

   
    
   

#ifdef __cplusplus
}
#endif

#endif

/******************* (C) COPYRIGHT 2016 STMicroelectronics *****END OF FILE****/
