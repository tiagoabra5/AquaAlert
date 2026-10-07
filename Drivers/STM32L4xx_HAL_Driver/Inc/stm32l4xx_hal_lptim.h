/**
  ******************************************************************************
  * @file    stm32l4xx_hal_lptim.h
  * @author  MCD Application Team
  * @brief   Header file of LPTIM HAL module.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2017 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */

                                                                                
#ifndef STM32L4xx_HAL_LPTIM_H
#define STM32L4xx_HAL_LPTIM_H

#ifdef __cplusplus
extern "C" {
#endif

                                                                                
#include "stm32l4xx_hal_def.h"

                                    
      
    

#if defined (LPTIM1) || defined (LPTIM2)

                     
      
    

                                                                                
                                                       
      
    
#define LPTIM_EXTI_LINE_LPTIM1  EXTI_IMR2_IM32                                                                      
#define LPTIM_EXTI_LINE_LPTIM2  EXTI_IMR2_IM33                                                                      

   
                                                
    
typedef struct
{
  uint32_t Source;                                       
                                                                                        

  uint32_t Prescaler;                                                 
                                                                                         

} LPTIM_ClockConfigTypeDef;

   
                                                
    
typedef struct
{
  uint32_t Polarity;                                                                       
                                                           
                                                                                                       
                                                                                                  
                                                                            
                                                                                        

  uint32_t SampleTime;                                                                               
                                                                                                       
                                                                                           

} LPTIM_ULPClockConfigTypeDef;

   
                                                  
    
typedef struct
{
  uint32_t Source;                                        
                                                                                       

  uint32_t ActiveEdge;                                         
                                                                                             
                                                                                                  

  uint32_t SampleTime;                                                                                
                                                                                             
                                                                                             
} LPTIM_TriggerConfigTypeDef;

   
                                                     
    
typedef struct
{
  LPTIM_ClockConfigTypeDef     Clock;                                                   

  LPTIM_ULPClockConfigTypeDef  UltraLowPowerClock;                                                      

  LPTIM_TriggerConfigTypeDef   Trigger;                                                   

  uint32_t                     OutputPolarity;                                       
                                                                                                                

  uint32_t                     UpdateMode;                                                                           
                                                                                                                
                                                                                                              

  uint32_t                     CounterSource;                                                                          
                                                                         
                                                                                                               

  uint32_t                     Input1Source;                                                                            
                                                                                                              

  uint32_t                     Input2Source;                                                                            
                                                                                                                       
                                                                      
                                                                                                              

#if defined(LPTIM_RCR_REP)
  uint32_t                     RepetitionCounter;                                            
                                                                                                                
                                                                                                         
                                                                                                                  
                                                                                                               
                                                                           
                                                                                                             
                                                                     
#endif
} LPTIM_InitTypeDef;

   
                                                
    
typedef enum
{
  HAL_LPTIM_STATE_RESET            = 0x00U,                                                       
  HAL_LPTIM_STATE_READY            = 0x01U,                                                       
  HAL_LPTIM_STATE_BUSY             = 0x02U,                                                       
  HAL_LPTIM_STATE_TIMEOUT          = 0x03U,                                                       
  HAL_LPTIM_STATE_ERROR            = 0x04U                                                        
} HAL_LPTIM_StateTypeDef;

   
                                             
    
#if (USE_HAL_LPTIM_REGISTER_CALLBACKS == 1)
typedef struct __LPTIM_HandleTypeDef
#else
typedef struct
#endif                                       
{
  LPTIM_TypeDef                 *Instance;                                          

  LPTIM_InitTypeDef              Init;                                              

  HAL_StatusTypeDef              Status;                                            

  HAL_LockTypeDef                Lock;                                              

  __IO  HAL_LPTIM_StateTypeDef   State;                                             

#if (USE_HAL_LPTIM_REGISTER_CALLBACKS == 1)
  void (* MspInitCallback)(struct __LPTIM_HandleTypeDef *hlptim);                                                                
  void (* MspDeInitCallback)(struct __LPTIM_HandleTypeDef *hlptim);                                                              
  void (* CompareMatchCallback)(struct __LPTIM_HandleTypeDef *hlptim);                                                           
  void (* AutoReloadMatchCallback)(struct __LPTIM_HandleTypeDef *hlptim);                                                        
  void (* TriggerCallback)(struct __LPTIM_HandleTypeDef *hlptim);                                                                
  void (* CompareWriteCallback)(struct __LPTIM_HandleTypeDef *hlptim);                                                           
  void (* AutoReloadWriteCallback)(struct __LPTIM_HandleTypeDef *hlptim);                                                        
  void (* DirectionUpCallback)(struct __LPTIM_HandleTypeDef *hlptim);                                                            
  void (* DirectionDownCallback)(struct __LPTIM_HandleTypeDef *hlptim);                                                          
#if defined(LPTIM_RCR_REP)
  void (* UpdateEventCallback)(struct __LPTIM_HandleTypeDef *hlptim);                                                            
  void (* RepCounterWriteCallback)(struct __LPTIM_HandleTypeDef *hlptim);                                                               
#endif
#endif                                       
} LPTIM_HandleTypeDef;

#if (USE_HAL_LPTIM_REGISTER_CALLBACKS == 1)
   
                                                        
    
typedef enum
{
  HAL_LPTIM_MSPINIT_CB_ID          = 0x00U,                                                            
  HAL_LPTIM_MSPDEINIT_CB_ID        = 0x01U,                                                            
  HAL_LPTIM_COMPARE_MATCH_CB_ID    = 0x02U,                                                            
  HAL_LPTIM_AUTORELOAD_MATCH_CB_ID = 0x03U,                                                            
  HAL_LPTIM_TRIGGER_CB_ID          = 0x04U,                                                            
  HAL_LPTIM_COMPARE_WRITE_CB_ID    = 0x05U,                                                            
  HAL_LPTIM_AUTORELOAD_WRITE_CB_ID = 0x06U,                                                            
  HAL_LPTIM_DIRECTION_UP_CB_ID     = 0x07U,                                                            
  HAL_LPTIM_DIRECTION_DOWN_CB_ID   = 0x08U,                                                            
#if defined(LPTIM_RCR_REP)
  HAL_LPTIM_UPDATE_EVENT_CB_ID      = 0x09U,                                                           
  HAL_LPTIM_REP_COUNTER_WRITE_CB_ID = 0x0AU,                                                                 
#endif
} HAL_LPTIM_CallbackIDTypeDef;

   
                                               
    
typedef  void (*pLPTIM_CallbackTypeDef)(LPTIM_HandleTypeDef *hlptim);                                                

#endif                                       
   
      
    

                                                                                
                                                               
      
    

                                                   
      
    
#define LPTIM_CLOCKSOURCE_APBCLOCK_LPOSC        0x00000000U
#define LPTIM_CLOCKSOURCE_ULPTIM                LPTIM_CFGR_CKSEL
   
      
    

                                                         
      
    
#define LPTIM_PRESCALER_DIV1                    0x00000000U
#define LPTIM_PRESCALER_DIV2                    LPTIM_CFGR_PRESC_0
#define LPTIM_PRESCALER_DIV4                    LPTIM_CFGR_PRESC_1
#define LPTIM_PRESCALER_DIV8                    (LPTIM_CFGR_PRESC_0 | LPTIM_CFGR_PRESC_1)
#define LPTIM_PRESCALER_DIV16                   LPTIM_CFGR_PRESC_2
#define LPTIM_PRESCALER_DIV32                   (LPTIM_CFGR_PRESC_0 | LPTIM_CFGR_PRESC_2)
#define LPTIM_PRESCALER_DIV64                   (LPTIM_CFGR_PRESC_1 | LPTIM_CFGR_PRESC_2)
#define LPTIM_PRESCALER_DIV128                  LPTIM_CFGR_PRESC
   
      
    

                                                         
      
    

#define LPTIM_OUTPUTPOLARITY_HIGH               0x00000000U
#define LPTIM_OUTPUTPOLARITY_LOW                LPTIM_CFGR_WAVPOL
   
      
    

                                                             
      
    
#define LPTIM_CLOCKSAMPLETIME_DIRECTTRANSITION  0x00000000U
#define LPTIM_CLOCKSAMPLETIME_2TRANSITIONS      LPTIM_CFGR_CKFLT_0
#define LPTIM_CLOCKSAMPLETIME_4TRANSITIONS      LPTIM_CFGR_CKFLT_1
#define LPTIM_CLOCKSAMPLETIME_8TRANSITIONS      LPTIM_CFGR_CKFLT
   
      
    

                                                       
      
    
#define LPTIM_CLOCKPOLARITY_RISING              0x00000000U
#define LPTIM_CLOCKPOLARITY_FALLING             LPTIM_CFGR_CKPOL_0
#define LPTIM_CLOCKPOLARITY_RISING_FALLING      LPTIM_CFGR_CKPOL_1
   
      
    

                                                       
      
    
#define LPTIM_TRIGSOURCE_SOFTWARE               0x0000FFFFU
#define LPTIM_TRIGSOURCE_0                      0x00000000U
#define LPTIM_TRIGSOURCE_1                      LPTIM_CFGR_TRIGSEL_0
#define LPTIM_TRIGSOURCE_2                      LPTIM_CFGR_TRIGSEL_1
#define LPTIM_TRIGSOURCE_3                      (LPTIM_CFGR_TRIGSEL_0 | LPTIM_CFGR_TRIGSEL_1)
#define LPTIM_TRIGSOURCE_4                      LPTIM_CFGR_TRIGSEL_2
#define LPTIM_TRIGSOURCE_5                      (LPTIM_CFGR_TRIGSEL_0 | LPTIM_CFGR_TRIGSEL_2)
#define LPTIM_TRIGSOURCE_6                      (LPTIM_CFGR_TRIGSEL_1 | LPTIM_CFGR_TRIGSEL_2)
#define LPTIM_TRIGSOURCE_7                      LPTIM_CFGR_TRIGSEL
   
      
    

                                                                             
      
    
#define LPTIM_ACTIVEEDGE_RISING                LPTIM_CFGR_TRIGEN_0
#define LPTIM_ACTIVEEDGE_FALLING               LPTIM_CFGR_TRIGEN_1
#define LPTIM_ACTIVEEDGE_RISING_FALLING        LPTIM_CFGR_TRIGEN
   
      
    

                                                                 
      
    
#define LPTIM_TRIGSAMPLETIME_DIRECTTRANSITION  0x00000000U
#define LPTIM_TRIGSAMPLETIME_2TRANSITIONS      LPTIM_CFGR_TRGFLT_0
#define LPTIM_TRIGSAMPLETIME_4TRANSITIONS      LPTIM_CFGR_TRGFLT_1
#define LPTIM_TRIGSAMPLETIME_8TRANSITIONS      LPTIM_CFGR_TRGFLT
   
      
    

                                                     
      
    

#define LPTIM_UPDATE_IMMEDIATE                  0x00000000U
#define LPTIM_UPDATE_ENDOFPERIOD                LPTIM_CFGR_PRELOAD
   
      
    

                                                       
      
    

#define LPTIM_COUNTERSOURCE_INTERNAL            0x00000000U
#define LPTIM_COUNTERSOURCE_EXTERNAL            LPTIM_CFGR_COUNTMODE
   
      
    

                                                     
      
    

#define LPTIM_INPUT1SOURCE_GPIO          0x00000000U                                
#define LPTIM_INPUT1SOURCE_COMP1         LPTIM_OR_OR_0                              
#define LPTIM_INPUT1SOURCE_COMP2         LPTIM_OR_OR_1                   
#define LPTIM_INPUT1SOURCE_COMP1_COMP2   LPTIM_OR_OR                     
   
      
    

                                                     
      
    

#define LPTIM_INPUT2SOURCE_GPIO         0x00000000U                                      
#define LPTIM_INPUT2SOURCE_COMP2        LPTIM_OR_OR_1                                    
   
      
    

                                                          
      
    

#if defined(LPTIM_RCR_REP)
#define LPTIM_FLAG_REPOK                         LPTIM_ISR_REPOK
#define LPTIM_FLAG_UPDATE                        LPTIM_ISR_UE
#endif
#define LPTIM_FLAG_DOWN                          LPTIM_ISR_DOWN
#define LPTIM_FLAG_UP                            LPTIM_ISR_UP
#define LPTIM_FLAG_ARROK                         LPTIM_ISR_ARROK
#define LPTIM_FLAG_CMPOK                         LPTIM_ISR_CMPOK
#define LPTIM_FLAG_EXTTRIG                       LPTIM_ISR_EXTTRIG
#define LPTIM_FLAG_ARRM                          LPTIM_ISR_ARRM
#define LPTIM_FLAG_CMPM                          LPTIM_ISR_CMPM
   
      
    

                                                                     
      
    
#if defined(LPTIM_RCR_REP)
#define LPTIM_IT_REPOK                           LPTIM_IER_REPOKIE
#define LPTIM_IT_UPDATE                          LPTIM_IER_UEIE
#endif
#define LPTIM_IT_DOWN                            LPTIM_IER_DOWNIE
#define LPTIM_IT_UP                              LPTIM_IER_UPIE
#define LPTIM_IT_ARROK                           LPTIM_IER_ARROKIE
#define LPTIM_IT_CMPOK                           LPTIM_IER_CMPOKIE
#define LPTIM_IT_EXTTRIG                         LPTIM_IER_EXTTRIGIE
#define LPTIM_IT_ARRM                            LPTIM_IER_ARRMIE
#define LPTIM_IT_CMPM                            LPTIM_IER_CMPMIE
   
      
    

   
      
    

                                                                                
                                                         
      
    

                                    
                                   
                
    
#if (USE_HAL_LPTIM_REGISTER_CALLBACKS == 1)
#define __HAL_LPTIM_RESET_HANDLE_STATE(__HANDLE__) do {                                                        \
                                                        (__HANDLE__)->State             = HAL_LPTIM_STATE_RESET; \
                                                        (__HANDLE__)->MspInitCallback   = NULL;                  \
                                                        (__HANDLE__)->MspDeInitCallback = NULL;                  \
                                                      } while(0)
#else
#define __HAL_LPTIM_RESET_HANDLE_STATE(__HANDLE__) ((__HANDLE__)->State = HAL_LPTIM_STATE_RESET)
#endif                                       

   
                                        
                                   
                
    
#define __HAL_LPTIM_ENABLE(__HANDLE__)   ((__HANDLE__)->Instance->CR |= (LPTIM_CR_ENABLE))

   
                                         
                                   
                                                                                    
                                                                                   
                                                                      
                                                                                        
                              
                
    
#define __HAL_LPTIM_DISABLE(__HANDLE__)   LPTIM_Disable(__HANDLE__)

   
                                                          
                                   
                
    
#define __HAL_LPTIM_START_CONTINUOUS(__HANDLE__)  ((__HANDLE__)->Instance->CR |=  LPTIM_CR_CNTSTRT)
   
                                                      
                                   
                
    
#define __HAL_LPTIM_START_SINGLE(__HANDLE__)      ((__HANDLE__)->Instance->CR |=  LPTIM_CR_SNGSTRT)

#if defined(LPTIM_CR_COUNTRST)
   
                                                                 
                                   
                
    
#define __HAL_LPTIM_RESET_COUNTER(__HANDLE__)      ((__HANDLE__)->Instance->CR |=  LPTIM_CR_COUNTRST)
#endif                        

#if defined(LPTIM_CR_RSTARE)
   
                                                                                
                                   
                
    
#define __HAL_LPTIM_RESET_COUNTER_AFTERREAD(__HANDLE__)      ((__HANDLE__)->Instance->CR |=  LPTIM_CR_RSTARE)
#endif                      

   
                                                                  
                                   
                                      
                                                                                           
                
                                                                                     
    
#define __HAL_LPTIM_AUTORELOAD_SET(__HANDLE__ , __VALUE__)  ((__HANDLE__)->Instance->ARR =  (__VALUE__))

   
                                                               
                                   
                                   
                
                                                                                     
    
#define __HAL_LPTIM_COMPARE_SET(__HANDLE__ , __VALUE__)     ((__HANDLE__)->Instance->CMP =  (__VALUE__))

#if defined(LPTIM_RCR_REP)
   
                                                                  
                                   
                                      
                
    
#define __HAL_LPTIM_REPETITIONCOUNTER_SET(__HANDLE__ , __VALUE__)  ((__HANDLE__)->Instance->RCR =  (__VALUE__))

   
                                                
                                   
                                     
                                                                                     
    
#define __HAL_LPTIM_REPETITIONCOUNTER_GET(__HANDLE__)  ((__HANDLE__)->Instance->RCR)
#endif

   
                                                                 
                                   
                                        
                                                
                                                                                             
                                                                            
                                                                          
                                                                                  
                                                                            
                                                                         
                                                                          
                                                               
                                                            
                                                           
    
#define __HAL_LPTIM_GET_FLAG(__HANDLE__, __FLAG__)          (((__HANDLE__)->Instance->ISR &(__FLAG__)) == (__FLAG__))

   
                                           
                                    
                                         
                                                
                                                                                             
                                                                            
                                                                          
                                                                                  
                                                                            
                                                                         
                                                                          
                                                               
                                                            
                 
    
#define __HAL_LPTIM_CLEAR_FLAG(__HANDLE__, __FLAG__)        ((__HANDLE__)->Instance->ICR  = (__FLAG__))

   
                                                 
                                    
                                                 
                                                
                                                                                                
                                                                                        
                                                                             
                                                                                     
                                                                               
                                                                            
                                                                             
                                                                  
                                                               
                 
                                                                                         
    
#define __HAL_LPTIM_ENABLE_IT(__HANDLE__, __INTERRUPT__)    ((__HANDLE__)->Instance->IER  |= (__INTERRUPT__))

   
                                                  
                                    
                                                 
                                                
                                                                                                
                                                                                        
                                                                             
                                                                                     
                                                                               
                                                                            
                                                                             
                                                                  
                                                               
                 
                                                                                          
    
#define __HAL_LPTIM_DISABLE_IT(__HANDLE__, __INTERRUPT__)   ((__HANDLE__)->Instance->IER  &= (~(__INTERRUPT__)))

   
                                                                                 
                                    
                                                   
                                                
                                                                                                
                                                                                        
                                                                             
                                                                                     
                                                                               
                                                                            
                                                                             
                                                                  
                                                               
                             
    

#define __HAL_LPTIM_GET_IT_SOURCE(__HANDLE__, __INTERRUPT__) ((((__HANDLE__)->Instance->IER\
                                                                & (__INTERRUPT__)) == (__INTERRUPT__)) ? SET : RESET)

   
                                                          
                
    
#define __HAL_LPTIM_LPTIM1_EXTI_ENABLE_IT()            (EXTI->IMR2 |= LPTIM_EXTI_LINE_LPTIM1)

   
                                                           
                
    
#define __HAL_LPTIM_LPTIM1_EXTI_DISABLE_IT()           (EXTI->IMR2\
                                                        &= ~(LPTIM_EXTI_LINE_LPTIM1))

   
                                                      
                
    
#define __HAL_LPTIM_LPTIM1_EXTI_ENABLE_EVENT()         (EXTI->EMR2 |= LPTIM_EXTI_LINE_LPTIM1)

   
                                                       
                
    
#define __HAL_LPTIM_LPTIM1_EXTI_DISABLE_EVENT()        (EXTI->EMR2\
                                                        &= ~(LPTIM_EXTI_LINE_LPTIM1))

   
                                                          
                
    
#define __HAL_LPTIM_LPTIM2_EXTI_ENABLE_IT()            (EXTI->IMR2 |= LPTIM_EXTI_LINE_LPTIM2)

   
                                                           
                
    
#define __HAL_LPTIM_LPTIM2_EXTI_DISABLE_IT()           (EXTI->IMR2\
                                                        &= ~(LPTIM_EXTI_LINE_LPTIM2))

   
                                                      
                
    
#define __HAL_LPTIM_LPTIM2_EXTI_ENABLE_EVENT()         (EXTI->EMR2 |= LPTIM_EXTI_LINE_LPTIM2)

   
                                                       
                
    
#define __HAL_LPTIM_LPTIM2_EXTI_DISABLE_EVENT()        (EXTI->EMR2\
                                                        &= ~(LPTIM_EXTI_LINE_LPTIM2))

   
      
    

                                                                                
                                                               
      
    

                                               
                                                          
      
    
                                                                                
HAL_StatusTypeDef HAL_LPTIM_Init(LPTIM_HandleTypeDef *hlptim);
HAL_StatusTypeDef HAL_LPTIM_DeInit(LPTIM_HandleTypeDef *hlptim);

                                                                                
void HAL_LPTIM_MspInit(LPTIM_HandleTypeDef *hlptim);
void HAL_LPTIM_MspDeInit(LPTIM_HandleTypeDef *hlptim);
   
      
    

                                               
                                             
      
    
                                                                                 
                                                                                
                            
HAL_StatusTypeDef HAL_LPTIM_PWM_Start(LPTIM_HandleTypeDef *hlptim, uint32_t Period, uint32_t Pulse);
HAL_StatusTypeDef HAL_LPTIM_PWM_Stop(LPTIM_HandleTypeDef *hlptim);
                                  
HAL_StatusTypeDef HAL_LPTIM_PWM_Start_IT(LPTIM_HandleTypeDef *hlptim, uint32_t Period, uint32_t Pulse);
HAL_StatusTypeDef HAL_LPTIM_PWM_Stop_IT(LPTIM_HandleTypeDef *hlptim);

                                                                                
                            
HAL_StatusTypeDef HAL_LPTIM_OnePulse_Start(LPTIM_HandleTypeDef *hlptim, uint32_t Period, uint32_t Pulse);
HAL_StatusTypeDef HAL_LPTIM_OnePulse_Stop(LPTIM_HandleTypeDef *hlptim);
                                  
HAL_StatusTypeDef HAL_LPTIM_OnePulse_Start_IT(LPTIM_HandleTypeDef *hlptim, uint32_t Period, uint32_t Pulse);
HAL_StatusTypeDef HAL_LPTIM_OnePulse_Stop_IT(LPTIM_HandleTypeDef *hlptim);

                                                                                
                            
HAL_StatusTypeDef HAL_LPTIM_SetOnce_Start(LPTIM_HandleTypeDef *hlptim, uint32_t Period, uint32_t Pulse);
HAL_StatusTypeDef HAL_LPTIM_SetOnce_Stop(LPTIM_HandleTypeDef *hlptim);
                                  
HAL_StatusTypeDef HAL_LPTIM_SetOnce_Start_IT(LPTIM_HandleTypeDef *hlptim, uint32_t Period, uint32_t Pulse);
HAL_StatusTypeDef HAL_LPTIM_SetOnce_Stop_IT(LPTIM_HandleTypeDef *hlptim);

                                                                                
                            
HAL_StatusTypeDef HAL_LPTIM_Encoder_Start(LPTIM_HandleTypeDef *hlptim, uint32_t Period);
HAL_StatusTypeDef HAL_LPTIM_Encoder_Stop(LPTIM_HandleTypeDef *hlptim);
                                  
HAL_StatusTypeDef HAL_LPTIM_Encoder_Start_IT(LPTIM_HandleTypeDef *hlptim, uint32_t Period);
HAL_StatusTypeDef HAL_LPTIM_Encoder_Stop_IT(LPTIM_HandleTypeDef *hlptim);

                                                                                
                            
HAL_StatusTypeDef HAL_LPTIM_TimeOut_Start(LPTIM_HandleTypeDef *hlptim, uint32_t Period, uint32_t Timeout);
HAL_StatusTypeDef HAL_LPTIM_TimeOut_Stop(LPTIM_HandleTypeDef *hlptim);
                                  
HAL_StatusTypeDef HAL_LPTIM_TimeOut_Start_IT(LPTIM_HandleTypeDef *hlptim, uint32_t Period, uint32_t Timeout);
HAL_StatusTypeDef HAL_LPTIM_TimeOut_Stop_IT(LPTIM_HandleTypeDef *hlptim);

                                                                                
                            
HAL_StatusTypeDef HAL_LPTIM_Counter_Start(LPTIM_HandleTypeDef *hlptim, uint32_t Period);
HAL_StatusTypeDef HAL_LPTIM_Counter_Stop(LPTIM_HandleTypeDef *hlptim);
                                  
HAL_StatusTypeDef HAL_LPTIM_Counter_Start_IT(LPTIM_HandleTypeDef *hlptim, uint32_t Period);
HAL_StatusTypeDef HAL_LPTIM_Counter_Stop_IT(LPTIM_HandleTypeDef *hlptim);
   
      
    

                                               
                                      
      
    
                                                                                
uint32_t HAL_LPTIM_ReadCounter(const LPTIM_HandleTypeDef *hlptim);
uint32_t HAL_LPTIM_ReadAutoReload(const LPTIM_HandleTypeDef *hlptim);
uint32_t HAL_LPTIM_ReadCompare(const LPTIM_HandleTypeDef *hlptim);
   
      
    

                                               
                                                      
      
    
                                                                                
void HAL_LPTIM_IRQHandler(LPTIM_HandleTypeDef *hlptim);

                                                                                
void HAL_LPTIM_CompareMatchCallback(LPTIM_HandleTypeDef *hlptim);
void HAL_LPTIM_AutoReloadMatchCallback(LPTIM_HandleTypeDef *hlptim);
void HAL_LPTIM_TriggerCallback(LPTIM_HandleTypeDef *hlptim);
void HAL_LPTIM_CompareWriteCallback(LPTIM_HandleTypeDef *hlptim);
void HAL_LPTIM_AutoReloadWriteCallback(LPTIM_HandleTypeDef *hlptim);
void HAL_LPTIM_DirectionUpCallback(LPTIM_HandleTypeDef *hlptim);
void HAL_LPTIM_DirectionDownCallback(LPTIM_HandleTypeDef *hlptim);
#if defined(LPTIM_RCR_REP)
void HAL_LPTIM_UpdateEventCallback(LPTIM_HandleTypeDef *hlptim);
void HAL_LPTIM_RepCounterWriteCallback(LPTIM_HandleTypeDef *hlptim);
#endif

                                                                                
#if (USE_HAL_LPTIM_REGISTER_CALLBACKS == 1)
HAL_StatusTypeDef HAL_LPTIM_RegisterCallback(LPTIM_HandleTypeDef *hlptim, HAL_LPTIM_CallbackIDTypeDef CallbackID,
                                             pLPTIM_CallbackTypeDef pCallback);
HAL_StatusTypeDef HAL_LPTIM_UnRegisterCallback(LPTIM_HandleTypeDef *hlptim, HAL_LPTIM_CallbackIDTypeDef CallbackID);
#endif                                       
   
      
    

                            
                                         
      
    
                                                                                
HAL_LPTIM_StateTypeDef HAL_LPTIM_GetState(const LPTIM_HandleTypeDef *hlptim);
   
      
    

   
      
    

                                                                                
                                                     
      
    

   
      
    

                                                                                
                                                             
      
    

   
      
    

                                                                                
                                                             
      
    

   
      
    

                                                                                
                                                       
      
    

#define IS_LPTIM_CLOCK_SOURCE(__SOURCE__)       (((__SOURCE__) == LPTIM_CLOCKSOURCE_ULPTIM) || \
                                                 ((__SOURCE__) == LPTIM_CLOCKSOURCE_APBCLOCK_LPOSC))


#define IS_LPTIM_CLOCK_PRESCALER(__PRESCALER__) (((__PRESCALER__) ==  LPTIM_PRESCALER_DIV1  ) || \
                                                 ((__PRESCALER__) ==  LPTIM_PRESCALER_DIV2  ) || \
                                                 ((__PRESCALER__) ==  LPTIM_PRESCALER_DIV4  ) || \
                                                 ((__PRESCALER__) ==  LPTIM_PRESCALER_DIV8  ) || \
                                                 ((__PRESCALER__) ==  LPTIM_PRESCALER_DIV16 ) || \
                                                 ((__PRESCALER__) ==  LPTIM_PRESCALER_DIV32 ) || \
                                                 ((__PRESCALER__) ==  LPTIM_PRESCALER_DIV64 ) || \
                                                 ((__PRESCALER__) ==  LPTIM_PRESCALER_DIV128))

#define IS_LPTIM_CLOCK_PRESCALERDIV1(__PRESCALER__) ((__PRESCALER__) ==  LPTIM_PRESCALER_DIV1)

#define IS_LPTIM_OUTPUT_POLARITY(__POLARITY__)  (((__POLARITY__) == LPTIM_OUTPUTPOLARITY_LOW ) || \
                                                 ((__POLARITY__) == LPTIM_OUTPUTPOLARITY_HIGH))

#define IS_LPTIM_CLOCK_SAMPLE_TIME(__SAMPLETIME__) (((__SAMPLETIME__) == LPTIM_CLOCKSAMPLETIME_DIRECTTRANSITION) || \
                                                    ((__SAMPLETIME__) == LPTIM_CLOCKSAMPLETIME_2TRANSITIONS)     || \
                                                    ((__SAMPLETIME__) == LPTIM_CLOCKSAMPLETIME_4TRANSITIONS)     || \
                                                    ((__SAMPLETIME__) == LPTIM_CLOCKSAMPLETIME_8TRANSITIONS))

#define IS_LPTIM_CLOCK_POLARITY(__POLARITY__)   (((__POLARITY__) == LPTIM_CLOCKPOLARITY_RISING)  || \
                                                 ((__POLARITY__) == LPTIM_CLOCKPOLARITY_FALLING) || \
                                                 ((__POLARITY__) == LPTIM_CLOCKPOLARITY_RISING_FALLING))

#define IS_LPTIM_TRG_SOURCE(__TRIG__)           (((__TRIG__) == LPTIM_TRIGSOURCE_SOFTWARE) || \
                                                 ((__TRIG__) == LPTIM_TRIGSOURCE_0) || \
                                                 ((__TRIG__) == LPTIM_TRIGSOURCE_1) || \
                                                 ((__TRIG__) == LPTIM_TRIGSOURCE_2) || \
                                                 ((__TRIG__) == LPTIM_TRIGSOURCE_3) || \
                                                 ((__TRIG__) == LPTIM_TRIGSOURCE_4) || \
                                                 ((__TRIG__) == LPTIM_TRIGSOURCE_5) || \
                                                 ((__TRIG__) == LPTIM_TRIGSOURCE_6) || \
                                                 ((__TRIG__) == LPTIM_TRIGSOURCE_7))

#define IS_LPTIM_EXT_TRG_POLARITY(__POLARITY__) (((__POLARITY__) == LPTIM_ACTIVEEDGE_RISING         ) || \
                                                 ((__POLARITY__) == LPTIM_ACTIVEEDGE_FALLING        ) || \
                                                 ((__POLARITY__) == LPTIM_ACTIVEEDGE_RISING_FALLING ))

#define IS_LPTIM_TRIG_SAMPLE_TIME(__SAMPLETIME__) (((__SAMPLETIME__) == LPTIM_TRIGSAMPLETIME_DIRECTTRANSITION) || \
                                                   ((__SAMPLETIME__) == LPTIM_TRIGSAMPLETIME_2TRANSITIONS    ) || \
                                                   ((__SAMPLETIME__) == LPTIM_TRIGSAMPLETIME_4TRANSITIONS    ) || \
                                                   ((__SAMPLETIME__) == LPTIM_TRIGSAMPLETIME_8TRANSITIONS    ))

#define IS_LPTIM_UPDATE_MODE(__MODE__)          (((__MODE__) == LPTIM_UPDATE_IMMEDIATE) || \
                                                 ((__MODE__) == LPTIM_UPDATE_ENDOFPERIOD))

#define IS_LPTIM_COUNTER_SOURCE(__SOURCE__)     (((__SOURCE__) == LPTIM_COUNTERSOURCE_INTERNAL) || \
                                                 ((__SOURCE__) == LPTIM_COUNTERSOURCE_EXTERNAL))

#define IS_LPTIM_COMPARE(__COMPARE__)           ((__COMPARE__) <= 0x0000FFFFUL)

#define IS_LPTIM_PERIOD(__PERIOD__)             ((0x00000001UL <= (__PERIOD__)) &&\
                                                 ((__PERIOD__) <= 0x0000FFFFUL))

#define IS_LPTIM_PULSE(__PULSE__)               ((__PULSE__) <= 0x0000FFFFUL)

#if defined(LPTIM_RCR_REP)
#define IS_LPTIM_REPETITION(__REPETITION__)     ((__REPETITION__) <= 0x000000FFUL)
#endif

#define IS_LPTIM_INPUT1_SOURCE(__INSTANCE__, __SOURCE__)  \
  ((((__INSTANCE__) == LPTIM1) &&                       \
    (((__SOURCE__) == LPTIM_INPUT1SOURCE_GPIO) ||        \
     ((__SOURCE__) == LPTIM_INPUT1SOURCE_COMP1)))        \
   ||                                                   \
   (((__INSTANCE__) == LPTIM2) &&                       \
    (((__SOURCE__) == LPTIM_INPUT1SOURCE_GPIO) ||        \
     ((__SOURCE__) == LPTIM_INPUT1SOURCE_COMP1) ||       \
     ((__SOURCE__) == LPTIM_INPUT1SOURCE_COMP2) ||       \
     ((__SOURCE__) == LPTIM_INPUT1SOURCE_COMP1_COMP2))))

#define IS_LPTIM_INPUT2_SOURCE(__INSTANCE__, __SOURCE__)  \
  (((__INSTANCE__) == LPTIM1) &&                       \
   (((__SOURCE__) == LPTIM_INPUT2SOURCE_GPIO) ||        \
    ((__SOURCE__) == LPTIM_INPUT2SOURCE_COMP2)))

   
      
    

                                                                                
                                                             
      
    
void LPTIM_Disable(LPTIM_HandleTypeDef *hlptim);
   
      
    

   
      
    

#endif                       
   
      
    

#ifdef __cplusplus
}
#endif

#endif                            
