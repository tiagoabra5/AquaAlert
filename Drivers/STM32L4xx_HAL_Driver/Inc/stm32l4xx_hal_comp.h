/**
  ******************************************************************************
  * @file    stm32l4xx_hal_comp.h
  * @author  MCD Application Team
  * @brief   Header file of COMP HAL module.
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

                                                                                
#ifndef STM32L4xx_HAL_COMP_H
#define STM32L4xx_HAL_COMP_H

#ifdef __cplusplus
extern "C" {
#endif

                                                                                
#include "stm32l4xx_hal_def.h"
#include "stm32l4xx_ll_exti.h"

                                    
      
    
#if defined (COMP1) || defined (COMP2)

                    
      
    

                                                                                
                                                     
      
    

   
                                          
    
typedef struct
{

#if defined(COMP2)
  uint32_t WindowMode;                                                                
                                                                                                 
                                                                                                 
                                                                                                 
                                                                                            
#endif            

  uint32_t Mode;                                                                            
                                                                                           
                                                                                                               
                                                                                           

  uint32_t NonInvertingInput;                                                       
                                                                                           

  uint32_t InvertingInput;                                                       
                                                                                            

  uint32_t Hysteresis;                                                                
                                                                                            

  uint32_t OutputPol;                                              
                                                                                                

  uint32_t BlankingSrce;                                           
                                                                                              

  uint32_t TriggerMode;                                                                                 
                                                                                                  

} COMP_InitTypeDef;

   
                                                              
    
#define COMP_STATE_BITFIELD_LOCK  (0x10U)
typedef enum
{
  HAL_COMP_STATE_RESET             = 0x00U,                                                                                                         
  HAL_COMP_STATE_RESET_LOCKED      = (HAL_COMP_STATE_RESET | COMP_STATE_BITFIELD_LOCK),                                                             
  HAL_COMP_STATE_READY             = 0x01U,                                                                                                         
  HAL_COMP_STATE_READY_LOCKED      = (HAL_COMP_STATE_READY | COMP_STATE_BITFIELD_LOCK),                                                             
  HAL_COMP_STATE_BUSY              = 0x02U,                                                                                                         
  HAL_COMP_STATE_BUSY_LOCKED       = (HAL_COMP_STATE_BUSY | COMP_STATE_BITFIELD_LOCK)                                                               
} HAL_COMP_StateTypeDef;

   
                                            
    
#if (USE_HAL_COMP_REGISTER_CALLBACKS == 1)
typedef struct __COMP_HandleTypeDef
#else
typedef struct
#endif                                      
{
  COMP_TypeDef       *Instance;                                       
  COMP_InitTypeDef   Init;                                            
  HAL_LockTypeDef    Lock;                                            
  __IO HAL_COMP_StateTypeDef  State;                                  
  __IO uint32_t      ErrorCode;                              
#if (USE_HAL_COMP_REGISTER_CALLBACKS == 1)
  void (* TriggerCallback)(struct __COMP_HandleTypeDef *hcomp);                                
  void (* MspInitCallback)(struct __COMP_HandleTypeDef *hcomp);                                 
  void (* MspDeInitCallback)(struct __COMP_HandleTypeDef *hcomp);                                 
#endif                                      
} COMP_HandleTypeDef;

#if (USE_HAL_COMP_REGISTER_CALLBACKS == 1)
   
                                                       
    
typedef enum
{
  HAL_COMP_TRIGGER_CB_ID                = 0x00U,                                  
  HAL_COMP_MSPINIT_CB_ID                = 0x01U,                                   
  HAL_COMP_MSPDEINIT_CB_ID              = 0x02U                                      
} HAL_COMP_CallbackIDTypeDef;

   
                                                
    
typedef  void (*pCOMP_CallbackTypeDef)(COMP_HandleTypeDef *hcomp);                                            

#endif                                      

   
      
    

                                                                                
                                                             
      
    

                                             
      
    
#define HAL_COMP_ERROR_NONE             (0x00UL)                  
#if (USE_HAL_COMP_REGISTER_CALLBACKS == 1)
#define HAL_COMP_ERROR_INVALID_CALLBACK (0x01UL)                                
#endif                                      
   
      
    


#if defined(COMP2)
                                              
      
    
#define COMP_WINDOWMODE_DISABLE                 (0x00000000UL)                                                 
                                                                                                                 
                                                                                             
#define COMP_WINDOWMODE_COMP1_INPUT_PLUS_COMMON (COMP_CSR_WINMODE)                                                      
                                                                                                                    
                                                                                                       
                                                                                                                   
                                                                                                                        
                                                                                 
   
      
    
#endif            



                                            
      
    
                                                                                
                                                                                
                                                                                
#define COMP_POWERMODE_HIGHSPEED       (0x00000000UL)                           
#define COMP_POWERMODE_MEDIUMSPEED     (COMP_CSR_PWRMODE_0)                       
#define COMP_POWERMODE_ULTRALOWPOWER   (COMP_CSR_PWRMODE)                                 
   
      
    

                                                                  
      
    
#define COMP_INPUT_PLUS_IO1            (0x00000000UL)                                                                                              
#define COMP_INPUT_PLUS_IO2            (COMP_CSR_INPSEL_0)                                                                                         
#if defined(COMP_CSR_INPSEL_1)
#define COMP_INPUT_PLUS_IO3            (COMP_CSR_INPSEL_1)                                                                                         
#endif
   
      
    

                                                                
      
    
#define COMP_INPUT_MINUS_1_4VREFINT    (                                                            COMP_CSR_SCALEN | COMP_CSR_BRGEN)                                                               
#define COMP_INPUT_MINUS_1_2VREFINT    (                                        COMP_CSR_INMSEL_0 | COMP_CSR_SCALEN | COMP_CSR_BRGEN)                                                               
#define COMP_INPUT_MINUS_3_4VREFINT    (                    COMP_CSR_INMSEL_1                     | COMP_CSR_SCALEN | COMP_CSR_BRGEN)                                                               
#define COMP_INPUT_MINUS_VREFINT       (                    COMP_CSR_INMSEL_1 | COMP_CSR_INMSEL_0 | COMP_CSR_SCALEN                 )                                                           
#define COMP_INPUT_MINUS_DAC1_CH1      (COMP_CSR_INMSEL_2                                        )                                                                                                                
#if defined(DAC_CHANNEL2_SUPPORT)
#define COMP_INPUT_MINUS_DAC1_CH2      (COMP_CSR_INMSEL_2                     | COMP_CSR_INMSEL_0)                                                                                                                
#endif                           
#define COMP_INPUT_MINUS_IO1           (COMP_CSR_INMSEL_2 | COMP_CSR_INMSEL_1                    )                                                                                                                                 
#define COMP_INPUT_MINUS_IO2           (COMP_CSR_INMSEL_2 | COMP_CSR_INMSEL_1 | COMP_CSR_INMSEL_0)                                                                                                                                 
#if defined(COMP_CSR_INMESEL_1)
#define COMP_INPUT_MINUS_IO3           (                     COMP_CSR_INMESEL_0 | COMP_CSR_INMSEL_2 | COMP_CSR_INMSEL_1 | COMP_CSR_INMSEL_0)                                                                                       
#define COMP_INPUT_MINUS_IO4           (COMP_CSR_INMESEL_1                      | COMP_CSR_INMSEL_2 | COMP_CSR_INMSEL_1 | COMP_CSR_INMSEL_0)                                                                                       
#define COMP_INPUT_MINUS_IO5           (COMP_CSR_INMESEL_1 | COMP_CSR_INMESEL_0 | COMP_CSR_INMSEL_2 | COMP_CSR_INMSEL_1 | COMP_CSR_INMSEL_0)                                                                                       
#endif                         
   
      
    

                                             
      
    
#define COMP_HYSTERESIS_NONE           (0x00000000UL)                                            
#define COMP_HYSTERESIS_LOW            (                  COMP_CSR_HYST_0)                              
#define COMP_HYSTERESIS_MEDIUM         (COMP_CSR_HYST_1                  )                                 
#define COMP_HYSTERESIS_HIGH           (COMP_CSR_HYST_1 | COMP_CSR_HYST_0)                               
   
      
    

                                                      
      
    
#define COMP_OUTPUTPOL_NONINVERTED     (0x00000000UL)                                                                                                                                              
#define COMP_OUTPUTPOL_INVERTED        (COMP_CSR_POLARITY)                                                                                                                                         
   
      
    

                                                     
      
    
#define COMP_BLANKINGSRC_NONE            (0x00000000UL)                                                   
#define COMP_BLANKINGSRC_TIM1_OC5_COMP1  (COMP_CSR_BLANKING_0)                                                                                        
#define COMP_BLANKINGSRC_TIM2_OC3_COMP1  (COMP_CSR_BLANKING_1)                                                                                        
#define COMP_BLANKINGSRC_TIM3_OC3_COMP1  (COMP_CSR_BLANKING_2)                                                                                        
#define COMP_BLANKINGSRC_TIM3_OC4_COMP2  (COMP_CSR_BLANKING_0)                                                                                        
#define COMP_BLANKINGSRC_TIM8_OC5_COMP2  (COMP_CSR_BLANKING_1)                                                                                        
#define COMP_BLANKINGSRC_TIM15_OC1_COMP2 (COMP_CSR_BLANKING_2)                                                                                         
   
      
    

                                                
      
    
                                                                                
                                                                                
                                                                                

                                                                      
                                                               
#define COMP_OUTPUT_LEVEL_LOW              (0x00000000UL)
                                                                       
                                                                
#define COMP_OUTPUT_LEVEL_HIGH             (0x00000001UL)
   
      
    

                                                       
      
    
#define COMP_TRIGGERMODE_NONE                 (0x00000000UL)                                                                                                           
#define COMP_TRIGGERMODE_IT_RISING            (COMP_EXTI_IT | COMP_EXTI_RISING)                                                                                                                             
#define COMP_TRIGGERMODE_IT_FALLING           (COMP_EXTI_IT | COMP_EXTI_FALLING)                                                                                                                             
#define COMP_TRIGGERMODE_IT_RISING_FALLING    (COMP_EXTI_IT | COMP_EXTI_RISING | COMP_EXTI_FALLING)                                                                                                                           
#define COMP_TRIGGERMODE_EVENT_RISING         (COMP_EXTI_EVENT | COMP_EXTI_RISING)                                                                                                                                    
#define COMP_TRIGGERMODE_EVENT_FALLING        (COMP_EXTI_EVENT | COMP_EXTI_FALLING)                                                                                                                                    
#define COMP_TRIGGERMODE_EVENT_RISING_FALLING (COMP_EXTI_EVENT | COMP_EXTI_RISING | COMP_EXTI_FALLING)                                                                                                                                  
   
      
    

   
      
    

                                                                                
                                                       
      
    

                                                            
      
    

                                    
                                   
                
    
#if (USE_HAL_COMP_REGISTER_CALLBACKS == 1)
#define __HAL_COMP_RESET_HANDLE_STATE(__HANDLE__) do{                                                  \
                                                      (__HANDLE__)->State = HAL_COMP_STATE_RESET;      \
                                                      (__HANDLE__)->MspInitCallback = NULL;            \
                                                      (__HANDLE__)->MspDeInitCallback = NULL;          \
                                                    } while(0)
#else
#define __HAL_COMP_RESET_HANDLE_STATE(__HANDLE__) ((__HANDLE__)->State = HAL_COMP_STATE_RESET)
#endif                                      

   
                                                                                 
                                 
                
    
#define COMP_CLEAR_ERRORCODE(__HANDLE__) ((__HANDLE__)->ErrorCode = HAL_COMP_ERROR_NONE)

   
                                            
                                   
                
    
#define __HAL_COMP_ENABLE(__HANDLE__)       SET_BIT((__HANDLE__)->Instance->CSR, COMP_CSR_EN)

   
                                             
                                   
                
    
#define __HAL_COMP_DISABLE(__HANDLE__)      CLEAR_BIT((__HANDLE__)->Instance->CSR, COMP_CSR_EN)

   
                                                        
                                                                          
                                                  
                                                                            
                                              
                                   
                
    
#define __HAL_COMP_LOCK(__HANDLE__)         SET_BIT((__HANDLE__)->Instance->CSR, COMP_CSR_LOCK)

   
                                                             
                                   
                                                                                      
    
#define __HAL_COMP_IS_LOCKED(__HANDLE__)    (READ_BIT((__HANDLE__)->Instance->CSR, COMP_CSR_LOCK) == COMP_CSR_LOCK)

   
      
    

                                                                           
      
    
   
                                                           
                
    
#define __HAL_COMP_COMP1_EXTI_ENABLE_RISING_EDGE()    LL_EXTI_EnableRisingTrig_0_31(COMP_EXTI_LINE_COMP1)

   
                                                            
                
    
#define __HAL_COMP_COMP1_EXTI_DISABLE_RISING_EDGE()   LL_EXTI_DisableRisingTrig_0_31(COMP_EXTI_LINE_COMP1)

   
                                                            
                
    
#define __HAL_COMP_COMP1_EXTI_ENABLE_FALLING_EDGE()   LL_EXTI_EnableFallingTrig_0_31(COMP_EXTI_LINE_COMP1)

   
                                                             
                
    
#define __HAL_COMP_COMP1_EXTI_DISABLE_FALLING_EDGE()  LL_EXTI_DisableFallingTrig_0_31(COMP_EXTI_LINE_COMP1)

   
                                                                     
                
    
#define __HAL_COMP_COMP1_EXTI_ENABLE_RISING_FALLING_EDGE() do {                                                        \
                                                                LL_EXTI_EnableRisingTrig_0_31(COMP_EXTI_LINE_COMP1);   \
                                                                LL_EXTI_EnableFallingTrig_0_31(COMP_EXTI_LINE_COMP1);  \
                                                              } while(0)

   
                                                                      
                
    
#define __HAL_COMP_COMP1_EXTI_DISABLE_RISING_FALLING_EDGE() do {                                                       \
                                                                 LL_EXTI_DisableRisingTrig_0_31(COMP_EXTI_LINE_COMP1); \
                                                                 LL_EXTI_DisableFallingTrig_0_31(COMP_EXTI_LINE_COMP1);\
                                                               } while(0)

   
                                                         
                
    
#define __HAL_COMP_COMP1_EXTI_ENABLE_IT()             LL_EXTI_EnableIT_0_31(COMP_EXTI_LINE_COMP1)

   
                                                          
                
    
#define __HAL_COMP_COMP1_EXTI_DISABLE_IT()            LL_EXTI_DisableIT_0_31(COMP_EXTI_LINE_COMP1)

   
                                                                 
                
    
#define __HAL_COMP_COMP1_EXTI_GENERATE_SWIT()         LL_EXTI_GenerateSWI_0_31(COMP_EXTI_LINE_COMP1)

   
                                                     
                
    
#define __HAL_COMP_COMP1_EXTI_ENABLE_EVENT()          LL_EXTI_EnableEvent_0_31(COMP_EXTI_LINE_COMP1)

   
                                                      
                
    
#define __HAL_COMP_COMP1_EXTI_DISABLE_EVENT()         LL_EXTI_DisableEvent_0_31(COMP_EXTI_LINE_COMP1)

   
                                                          
                        
    
#define __HAL_COMP_COMP1_EXTI_GET_FLAG()              LL_EXTI_IsActiveFlag_0_31(COMP_EXTI_LINE_COMP1)

   
                                      
                
    
#define __HAL_COMP_COMP1_EXTI_CLEAR_FLAG()            LL_EXTI_ClearFlag_0_31(COMP_EXTI_LINE_COMP1)

#if defined(COMP2)
   
                                                           
                
    
#define __HAL_COMP_COMP2_EXTI_ENABLE_RISING_EDGE()    LL_EXTI_EnableRisingTrig_0_31(COMP_EXTI_LINE_COMP2)

   
                                                            
                
    
#define __HAL_COMP_COMP2_EXTI_DISABLE_RISING_EDGE()   LL_EXTI_DisableRisingTrig_0_31(COMP_EXTI_LINE_COMP2)

   
                                                            
                
    
#define __HAL_COMP_COMP2_EXTI_ENABLE_FALLING_EDGE()   LL_EXTI_EnableFallingTrig_0_31(COMP_EXTI_LINE_COMP2)

   
                                                             
                
    
#define __HAL_COMP_COMP2_EXTI_DISABLE_FALLING_EDGE()  LL_EXTI_DisableFallingTrig_0_31(COMP_EXTI_LINE_COMP2)

   
                                                                     
                
    
#define __HAL_COMP_COMP2_EXTI_ENABLE_RISING_FALLING_EDGE() do {                                                        \
                                                                LL_EXTI_EnableRisingTrig_0_31(COMP_EXTI_LINE_COMP2);   \
                                                                LL_EXTI_EnableFallingTrig_0_31(COMP_EXTI_LINE_COMP2);  \
                                                              } while(0)

   
                                                                      
                
    
#define __HAL_COMP_COMP2_EXTI_DISABLE_RISING_FALLING_EDGE() do {                                                       \
                                                                 LL_EXTI_DisableRisingTrig_0_31(COMP_EXTI_LINE_COMP2); \
                                                                 LL_EXTI_DisableFallingTrig_0_31(COMP_EXTI_LINE_COMP2);\
                                                               } while(0)

   
                                                         
                
    
#define __HAL_COMP_COMP2_EXTI_ENABLE_IT()             LL_EXTI_EnableIT_0_31(COMP_EXTI_LINE_COMP2)

   
                                                          
                
    
#define __HAL_COMP_COMP2_EXTI_DISABLE_IT()            LL_EXTI_DisableIT_0_31(COMP_EXTI_LINE_COMP2)

   
                                                                 
                
    
#define __HAL_COMP_COMP2_EXTI_GENERATE_SWIT()         LL_EXTI_GenerateSWI_0_31(COMP_EXTI_LINE_COMP2)

   
                                                     
                
    
#define __HAL_COMP_COMP2_EXTI_ENABLE_EVENT()          LL_EXTI_EnableEvent_0_31(COMP_EXTI_LINE_COMP2)

   
                                                      
                
    
#define __HAL_COMP_COMP2_EXTI_DISABLE_EVENT()         LL_EXTI_DisableEvent_0_31(COMP_EXTI_LINE_COMP2)

   
                                                          
                        
    
#define __HAL_COMP_COMP2_EXTI_GET_FLAG()              LL_EXTI_IsActiveFlag_0_31(COMP_EXTI_LINE_COMP2)

   
                                      
                
    
#define __HAL_COMP_COMP2_EXTI_CLEAR_FLAG()            LL_EXTI_ClearFlag_0_31(COMP_EXTI_LINE_COMP2)

#endif            
   
      
    

   
      
    


                                                                                
                                                                                
                                                           
      
    

                                           
      
    
#define COMP_EXTI_LINE_COMP1           (LL_EXTI_LINE_21)                                                
#if defined(COMP2)
#define COMP_EXTI_LINE_COMP2           (LL_EXTI_LINE_22)                                                
#endif            
   
      
    

                                           
      
    
#define COMP_EXTI_IT                        (0x00000001UL)                                           
#define COMP_EXTI_EVENT                     (0x00000002UL)                                                     
#define COMP_EXTI_RISING                    (0x00000010UL)                                        
#define COMP_EXTI_FALLING                   (0x00000020UL)                                         
   
      
    

   
      
    

                                                                                
                                                     
      
    

                                                                                                 
      
    
   
                                                                  
                                                      
                                       
    
#if defined(COMP2)
#define COMP_GET_EXTI_LINE(__INSTANCE__)    (((__INSTANCE__) == COMP1) ? COMP_EXTI_LINE_COMP1  \
                                             : COMP_EXTI_LINE_COMP2)
#else
#define COMP_GET_EXTI_LINE(__INSTANCE__)    COMP_EXTI_LINE_COMP1
#endif            
   
      
    

                                                                                            
      
    
#if defined(COMP2)
#define IS_COMP_WINDOWMODE(__WINDOWMODE__)  (((__WINDOWMODE__) == COMP_WINDOWMODE_DISABLE)                || \
                                             ((__WINDOWMODE__) == COMP_WINDOWMODE_COMP1_INPUT_PLUS_COMMON)  )
#endif            

#define IS_COMP_POWERMODE(__POWERMODE__)    (((__POWERMODE__) == COMP_POWERMODE_HIGHSPEED)    || \
                                             ((__POWERMODE__) == COMP_POWERMODE_MEDIUMSPEED)  || \
                                             ((__POWERMODE__) == COMP_POWERMODE_ULTRALOWPOWER)  )

#if defined(COMP_CSR_INPSEL_1)
#define IS_COMP_INPUT_PLUS(__COMP_INSTANCE__, __INPUT_PLUS__) (((__INPUT_PLUS__) == COMP_INPUT_PLUS_IO1) || \
                                                               ((__INPUT_PLUS__) == COMP_INPUT_PLUS_IO2) || \
                                                               ((__INPUT_PLUS__) == COMP_INPUT_PLUS_IO3))
#else
#define IS_COMP_INPUT_PLUS(__COMP_INSTANCE__, __INPUT_PLUS__) (((__INPUT_PLUS__) == COMP_INPUT_PLUS_IO1) || \
                                                               ((__INPUT_PLUS__) == COMP_INPUT_PLUS_IO2))
#endif

                                                                                
                                                                                
                                                                                
                                                                                
#if defined(COMP_CSR_INMESEL_1) && defined(DAC_CHANNEL2_SUPPORT)
#define IS_COMP_INPUT_MINUS(__COMP_INSTANCE__, __INPUT_MINUS__) (((__INPUT_MINUS__) == COMP_INPUT_MINUS_1_4VREFINT)  || \
                                                                 ((__INPUT_MINUS__) == COMP_INPUT_MINUS_1_2VREFINT)  || \
                                                                 ((__INPUT_MINUS__) == COMP_INPUT_MINUS_3_4VREFINT)  || \
                                                                 ((__INPUT_MINUS__) == COMP_INPUT_MINUS_VREFINT)     || \
                                                                 ((__INPUT_MINUS__) == COMP_INPUT_MINUS_DAC1_CH1)    || \
                                                                 ((__INPUT_MINUS__) == COMP_INPUT_MINUS_DAC1_CH2)    || \
                                                                 ((__INPUT_MINUS__) == COMP_INPUT_MINUS_IO1)         || \
                                                                 ((__INPUT_MINUS__) == COMP_INPUT_MINUS_IO2)         || \
                                                                 ((__INPUT_MINUS__) == COMP_INPUT_MINUS_IO3)         || \
                                                                 ((__INPUT_MINUS__) == COMP_INPUT_MINUS_IO4)         || \
                                                                 ((__INPUT_MINUS__) == COMP_INPUT_MINUS_IO5))
#elif defined(COMP_CSR_INMESEL_1)
#define IS_COMP_INPUT_MINUS(__COMP_INSTANCE__, __INPUT_MINUS__) (((__INPUT_MINUS__) == COMP_INPUT_MINUS_1_4VREFINT)  || \
                                                                 ((__INPUT_MINUS__) == COMP_INPUT_MINUS_1_2VREFINT)  || \
                                                                 ((__INPUT_MINUS__) == COMP_INPUT_MINUS_3_4VREFINT)  || \
                                                                 ((__INPUT_MINUS__) == COMP_INPUT_MINUS_VREFINT)     || \
                                                                 ((__INPUT_MINUS__) == COMP_INPUT_MINUS_DAC1_CH1)    || \
                                                                 ((__INPUT_MINUS__) == COMP_INPUT_MINUS_IO1)         || \
                                                                 ((__INPUT_MINUS__) == COMP_INPUT_MINUS_IO2)         || \
                                                                 ((__INPUT_MINUS__) == COMP_INPUT_MINUS_IO3)         || \
                                                                 ((__INPUT_MINUS__) == COMP_INPUT_MINUS_IO4)         || \
                                                                 ((__INPUT_MINUS__) == COMP_INPUT_MINUS_IO5))
#elif defined(DAC_CHANNEL2_SUPPORT)
#define IS_COMP_INPUT_MINUS(__COMP_INSTANCE__, __INPUT_MINUS__) (((__INPUT_MINUS__) == COMP_INPUT_MINUS_1_4VREFINT)  || \
                                                                 ((__INPUT_MINUS__) == COMP_INPUT_MINUS_1_2VREFINT)  || \
                                                                 ((__INPUT_MINUS__) == COMP_INPUT_MINUS_3_4VREFINT)  || \
                                                                 ((__INPUT_MINUS__) == COMP_INPUT_MINUS_VREFINT)     || \
                                                                 ((__INPUT_MINUS__) == COMP_INPUT_MINUS_DAC1_CH1)    || \
                                                                 ((__INPUT_MINUS__) == COMP_INPUT_MINUS_DAC1_CH2)    || \
                                                                 ((__INPUT_MINUS__) == COMP_INPUT_MINUS_IO1)         || \
                                                                 ((__INPUT_MINUS__) == COMP_INPUT_MINUS_IO2))
#else
#define IS_COMP_INPUT_MINUS(__COMP_INSTANCE__, __INPUT_MINUS__) (((__INPUT_MINUS__) == COMP_INPUT_MINUS_1_4VREFINT)  || \
                                                                 ((__INPUT_MINUS__) == COMP_INPUT_MINUS_1_2VREFINT)  || \
                                                                 ((__INPUT_MINUS__) == COMP_INPUT_MINUS_3_4VREFINT)  || \
                                                                 ((__INPUT_MINUS__) == COMP_INPUT_MINUS_VREFINT)     || \
                                                                 ((__INPUT_MINUS__) == COMP_INPUT_MINUS_DAC1_CH1)    || \
                                                                 ((__INPUT_MINUS__) == COMP_INPUT_MINUS_IO1)         || \
                                                                 ((__INPUT_MINUS__) == COMP_INPUT_MINUS_IO2))
#endif                                                 

#define IS_COMP_HYSTERESIS(__HYSTERESIS__)  (((__HYSTERESIS__) == COMP_HYSTERESIS_NONE)   || \
                                             ((__HYSTERESIS__) == COMP_HYSTERESIS_LOW)    || \
                                             ((__HYSTERESIS__) == COMP_HYSTERESIS_MEDIUM) || \
                                             ((__HYSTERESIS__) == COMP_HYSTERESIS_HIGH))

#define IS_COMP_OUTPUTPOL(__POL__)          (((__POL__) == COMP_OUTPUTPOL_NONINVERTED) || \
                                             ((__POL__) == COMP_OUTPUTPOL_INVERTED))

#if defined(COMP2)
#define IS_COMP_BLANKINGSRCE(__OUTPUT_BLANKING_SOURCE__)                    \
  (((__OUTPUT_BLANKING_SOURCE__) == COMP_BLANKINGSRC_NONE)                  \
   || ((__OUTPUT_BLANKING_SOURCE__) == COMP_BLANKINGSRC_TIM1_OC5_COMP1)     \
   || ((__OUTPUT_BLANKING_SOURCE__) == COMP_BLANKINGSRC_TIM2_OC3_COMP1)     \
   || ((__OUTPUT_BLANKING_SOURCE__) == COMP_BLANKINGSRC_TIM3_OC3_COMP1)     \
   || ((__OUTPUT_BLANKING_SOURCE__) == COMP_BLANKINGSRC_TIM3_OC4_COMP2)     \
   || ((__OUTPUT_BLANKING_SOURCE__) == COMP_BLANKINGSRC_TIM8_OC5_COMP2)     \
   || ((__OUTPUT_BLANKING_SOURCE__) == COMP_BLANKINGSRC_TIM15_OC1_COMP2)    \
  )
#else
#if defined(TIM3)
#define IS_COMP_BLANKINGSRCE(__OUTPUT_BLANKING_SOURCE__)                    \
  (((__OUTPUT_BLANKING_SOURCE__) == COMP_BLANKINGSRC_NONE)                  \
   || ((__OUTPUT_BLANKING_SOURCE__) == COMP_BLANKINGSRC_TIM1_OC5_COMP1)     \
   || ((__OUTPUT_BLANKING_SOURCE__) == COMP_BLANKINGSRC_TIM2_OC3_COMP1)     \
   || ((__OUTPUT_BLANKING_SOURCE__) == COMP_BLANKINGSRC_TIM3_OC3_COMP1)     \
  )
#else
#define IS_COMP_BLANKINGSRCE(__OUTPUT_BLANKING_SOURCE__)                    \
  (((__OUTPUT_BLANKING_SOURCE__) == COMP_BLANKINGSRC_NONE)                  \
   || ((__OUTPUT_BLANKING_SOURCE__) == COMP_BLANKINGSRC_TIM1_OC5_COMP1)     \
   || ((__OUTPUT_BLANKING_SOURCE__) == COMP_BLANKINGSRC_TIM2_OC3_COMP1)     \
  )
#endif           
#endif            

#if defined(COMP2)
#define IS_COMP_BLANKINGSRC_INSTANCE(__INSTANCE__, __OUTPUT_BLANKING_SOURCE__)  \
  ((((__INSTANCE__) == COMP1) &&                                                \
    (((__OUTPUT_BLANKING_SOURCE__) == COMP_BLANKINGSRC_NONE)            ||      \
     ((__OUTPUT_BLANKING_SOURCE__) == COMP_BLANKINGSRC_TIM1_OC5_COMP1)  ||      \
     ((__OUTPUT_BLANKING_SOURCE__) == COMP_BLANKINGSRC_TIM2_OC3_COMP1)  ||      \
     ((__OUTPUT_BLANKING_SOURCE__) == COMP_BLANKINGSRC_TIM3_OC3_COMP1)))        \
   ||                                                                           \
   (((__INSTANCE__) == COMP2) &&                                                \
    (((__OUTPUT_BLANKING_SOURCE__) == COMP_BLANKINGSRC_NONE)           ||       \
     ((__OUTPUT_BLANKING_SOURCE__) == COMP_BLANKINGSRC_TIM3_OC4_COMP2) ||       \
     ((__OUTPUT_BLANKING_SOURCE__) == COMP_BLANKINGSRC_TIM8_OC5_COMP2) ||       \
     ((__OUTPUT_BLANKING_SOURCE__) == COMP_BLANKINGSRC_TIM15_OC1_COMP2))))
#else
#if defined(TIM3)
#define IS_COMP_BLANKINGSRC_INSTANCE(__INSTANCE__, __OUTPUT_BLANKING_SOURCE__)  \
  (((__INSTANCE__) == COMP1) &&                                                 \
   (((__OUTPUT_BLANKING_SOURCE__) == COMP_BLANKINGSRC_NONE)            ||       \
    ((__OUTPUT_BLANKING_SOURCE__) == COMP_BLANKINGSRC_TIM1_OC5_COMP1)  ||       \
    ((__OUTPUT_BLANKING_SOURCE__) == COMP_BLANKINGSRC_TIM2_OC3_COMP1)  ||       \
    ((__OUTPUT_BLANKING_SOURCE__) == COMP_BLANKINGSRC_TIM3_OC3_COMP1)))
#else
#define IS_COMP_BLANKINGSRC_INSTANCE(__INSTANCE__, __OUTPUT_BLANKING_SOURCE__)  \
  (((__INSTANCE__) == COMP1) &&                                                 \
   (((__OUTPUT_BLANKING_SOURCE__) == COMP_BLANKINGSRC_NONE)            ||       \
    ((__OUTPUT_BLANKING_SOURCE__) == COMP_BLANKINGSRC_TIM1_OC5_COMP1)  ||       \
    ((__OUTPUT_BLANKING_SOURCE__) == COMP_BLANKINGSRC_TIM2_OC3_COMP1)  ))
#endif           
#endif            

#define IS_COMP_TRIGGERMODE(__MODE__)       (((__MODE__) == COMP_TRIGGERMODE_NONE)                 || \
                                             ((__MODE__) == COMP_TRIGGERMODE_IT_RISING)            || \
                                             ((__MODE__) == COMP_TRIGGERMODE_IT_FALLING)           || \
                                             ((__MODE__) == COMP_TRIGGERMODE_IT_RISING_FALLING)    || \
                                             ((__MODE__) == COMP_TRIGGERMODE_EVENT_RISING)         || \
                                             ((__MODE__) == COMP_TRIGGERMODE_EVENT_FALLING)        || \
                                             ((__MODE__) == COMP_TRIGGERMODE_EVENT_RISING_FALLING))

#define IS_COMP_OUTPUT_LEVEL(__OUTPUT_LEVEL__) (((__OUTPUT_LEVEL__) == COMP_OUTPUT_LEVEL_LOW)     || \
                                                ((__OUTPUT_LEVEL__) == COMP_OUTPUT_LEVEL_HIGH))

   
      
    

   
      
    


                                                                                
                                       
      
    

                                              
      
    

                                                                                      
HAL_StatusTypeDef HAL_COMP_Init(COMP_HandleTypeDef *hcomp);
HAL_StatusTypeDef HAL_COMP_DeInit(COMP_HandleTypeDef *hcomp);
void              HAL_COMP_MspInit(COMP_HandleTypeDef *hcomp);
void              HAL_COMP_MspDeInit(COMP_HandleTypeDef *hcomp);

#if (USE_HAL_COMP_REGISTER_CALLBACKS == 1)
                                                                                
HAL_StatusTypeDef HAL_COMP_RegisterCallback(COMP_HandleTypeDef *hcomp, HAL_COMP_CallbackIDTypeDef CallbackID,
                                            pCOMP_CallbackTypeDef pCallback);
HAL_StatusTypeDef HAL_COMP_UnRegisterCallback(COMP_HandleTypeDef *hcomp, HAL_COMP_CallbackIDTypeDef CallbackID);
#endif                                      
   
      
    

                                                                                 
                                              
      
    
HAL_StatusTypeDef HAL_COMP_Start(COMP_HandleTypeDef *hcomp);
HAL_StatusTypeDef HAL_COMP_Stop(COMP_HandleTypeDef *hcomp);
void              HAL_COMP_IRQHandler(COMP_HandleTypeDef *hcomp);
   
      
    

                                                                                  
                                              
      
    
HAL_StatusTypeDef HAL_COMP_Lock(COMP_HandleTypeDef *hcomp);
uint32_t          HAL_COMP_GetOutputLevel(const COMP_HandleTypeDef *hcomp);
                                
void              HAL_COMP_TriggerCallback(COMP_HandleTypeDef *hcomp);
   
      
    

                                                                                  
                                              
      
    
HAL_COMP_StateTypeDef HAL_COMP_GetState(const COMP_HandleTypeDef *hcomp);
uint32_t              HAL_COMP_GetError(const COMP_HandleTypeDef *hcomp);
   
      
    

   
      
    

   
      
    
#endif                     
   
      
    

#ifdef __cplusplus
}
#endif

#endif                           
