/**
* @file    SDK_EVAL_Timers.c
* @author  VMA division - AMS
* @version 3.2.0
* @date    May 1, 2016
* @brief   SDK EVAL timers configuration.
* @details
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


                                                                                
#include "radio_timer.h"


   
                             
    
  

   
                             
    
  


   
                                                                                                        
    
  

   
   
  


   
                                                                                              
    
  

   
   
  


   
                                                                                             
    
  

   
                               
                                                   
              
  
#ifndef ABS
#define ABS(x)  (((x) < 0) ? -(x) : (x))
#endif        

   
   
  

   
                                                                                                
    
  

volatile uint32_t lSystickCounter=0;

   
   
  

   
                                                                                                          
    
  

   
   
  


   
                                                                                                
    
  



   
                                                                                                
                                                                   
                                       
                                  
               
  
void RadioTimersFindFactors(uint32_t lCycles, uint16_t *pnPrescaler, uint16_t *pnCounter)
{
  uint16_t b0;
  uint16_t a0;
  long err, err_min=lCycles;
  
  *pnPrescaler = a0 = ((lCycles-1)/0xffff) + 1;
  *pnCounter = b0 = lCycles / *pnPrescaler;
  
  for (; *pnPrescaler < 0xffff-1; (*pnPrescaler)++) {
    *pnCounter = lCycles / *pnPrescaler;
    err = (long)*pnPrescaler * (long)*pnCounter - (long)lCycles;
    if (ABS(err) > (*pnPrescaler / 2)) {
      (*pnCounter)++;
      err = (long)*pnPrescaler * (long)*pnCounter - (long)lCycles;
    }
    if (ABS(err) < ABS(err_min)) {
      err_min = err;
      a0 = *pnPrescaler;
      b0 = *pnCounter;
      if (err == 0) break;
    }
  }
  
  *pnPrescaler = a0;
  *pnCounter = b0;
}


   
                                                                                     
                                                                            
                                                            
                                                                     
                                                                      
                                      
                                
               
  
void RadioTimersTimConfig(TIM_HandleTypeDef* TIM_TimeBaseStructure, uint16_t nPrescaler, uint16_t nPeriod)
{
  TIM_TypeDef *xTim=TIM_TimeBaseStructure->Instance;
  
                         
  __HAL_TIM_DISABLE(TIM_TimeBaseStructure);
  
                                          
  __HAL_TIM_DISABLE_IT(TIM_TimeBaseStructure, TIM_IT_UPDATE);
  
                              
  if(xTim == TIM2) {
    __HAL_RCC_TIM2_CLK_ENABLE();
  }
  
#ifdef USE_STM32F4XX_NUCLEO
  else if(xTim==TIM3) {
    __HAL_RCC_TIM3_CLK_ENABLE();
  }
  else if(xTim==TIM4) {
    __HAL_RCC_TIM4_CLK_ENABLE();
  }
#endif
  
#ifdef USE_STM32L1XX_NUCLEO
  else if(xTim==TIM3) {
    __HAL_RCC_TIM3_CLK_ENABLE();
  }
  else if(xTim==TIM4) {
    __HAL_RCC_TIM4_CLK_ENABLE();
  }
  else if(xTim==TIM6) {
    __HAL_RCC_TIM6_CLK_ENABLE();
  }
  else if(xTim==TIM7) {
    __HAL_RCC_TIM7_CLK_ENABLE();
  }
#endif
  
#ifdef USE_STM32L0XX_NUCLEO
  if(xTim==TIM6) {
    __HAL_RCC_TIM6_CLK_ENABLE();
  }
#endif
  
                               
  TIM_TimeBaseStructure->Init.Prescaler         = nPrescaler;
  TIM_TimeBaseStructure->Init.Period            = nPeriod;
  TIM_TimeBaseStructure->Init.ClockDivision     = TIM_CLOCKDIVISION_DIV1;
  TIM_TimeBaseStructure->Init.CounterMode       = TIM_COUNTERMODE_UP;
  
                                    
  HAL_TIM_Base_Init(TIM_TimeBaseStructure);
  
  
                          
  if(xTim == TIM2) {
    HAL_NVIC_SetPriority(TIM2_IRQn, NUCLEO_TIMx_PRIORITY, 0);
    HAL_NVIC_EnableIRQ(TIM2_IRQn);
  }
  
#ifdef USE_STM32F4XX_NUCLEO
  else if(xTim == TIM3) {
    HAL_NVIC_SetPriority(TIM3_IRQn, 0x09, 0);
    HAL_NVIC_EnableIRQ(TIM3_IRQn);
  }
  else if(xTim == TIM4) {
    HAL_NVIC_SetPriority(TIM4_IRQn, 0x09, 0);
    HAL_NVIC_EnableIRQ(TIM4_IRQn);
  }
#endif  
  
#ifdef USE_STM32L1XX_NUCLEO
  else if(xTim == TIM3) {
    HAL_NVIC_SetPriority(TIM3_IRQn, NUCLEO_TIMx_PRIORITY, 0);
    HAL_NVIC_EnableIRQ(TIM3_IRQn);
  }
  else if(xTim == TIM4) {
    HAL_NVIC_SetPriority(TIM4_IRQn, NUCLEO_TIMx_PRIORITY, 0);
    HAL_NVIC_EnableIRQ(TIM4_IRQn);
  }
  else if(xTim == TIM6) {
    HAL_NVIC_SetPriority(TIM6_IRQn, NUCLEO_TIMx_PRIORITY, 0);
    HAL_NVIC_EnableIRQ(TIM6_IRQn);
  }
  else if(xTim == TIM7) {
    HAL_NVIC_SetPriority(TIM7_IRQn, NUCLEO_TIMx_PRIORITY, 0);
    HAL_NVIC_EnableIRQ(TIM7_IRQn);
  }
#endif  
  
#ifdef USE_STM32L0XX_NUCLEO
  if(xTim == TIM6) {
    HAL_NVIC_SetPriority(TIM6_IRQn, 0x09, 0);
    HAL_NVIC_EnableIRQ(TIM6_IRQn);
  }
#endif
  
                                   
  __HAL_TIM_CLEAR_FLAG(TIM_TimeBaseStructure, TIM_FLAG_UPDATE);
  
}

#ifdef USE_SYSTICK_DELAY
   
                                                
              
              
  
#if 0                           
void SysTick_Handler(void)
{
  lSystickCounter++;
#ifdef S2LP_SUPPORT
  HAL_IncTick();
  HAL_SYSTICK_IRQHandler();
#endif  
}
#endif

   
                                                     
                                      
                                                
              
  
uint32_t SdkGetCurrentSysTick(void)
{
  return lSystickCounter;
  
}

void SdkStartSysTick(void)
{
  SysTick_Config(32000);
  lSystickCounter = 0;
  
}

   
                                                                    
                                      
                                                
              
  
void SdkDelayMs(volatile uint32_t lTimeMs)
{
  uint32_t nWaitPeriod = ~lSystickCounter;
  
  if(nWaitPeriod<lTimeMs) {
    while( lSystickCounter != 0xFFFFFFFF);
    nWaitPeriod = lTimeMs-nWaitPeriod;
  }
  else
    nWaitPeriod = lTimeMs+ ~nWaitPeriod;
  
  while( lSystickCounter != nWaitPeriod ) ;
  
}
#endif
   
   
  


   
   
  


   
   
  


/******************* (C) COPYRIGHT 2016 STMicroelectronics *****END OF FILE****/
