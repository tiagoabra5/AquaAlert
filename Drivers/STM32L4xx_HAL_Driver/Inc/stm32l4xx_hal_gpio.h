/**
  ******************************************************************************
  * @file    stm32l4xx_hal_gpio.h
  * @author  MCD Application Team
  * @brief   Header file of GPIO HAL module.
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

                                                                                
#ifndef STM32L4xx_HAL_GPIO_H
#define STM32L4xx_HAL_GPIO_H

#ifdef __cplusplus
 extern "C" {
#endif

                                                                                
#include "stm32l4xx_hal_def.h"

                                    
      
    

                    
      
    

                                                                                

                                                     
      
    
   
                                           
    
typedef struct
{
  uint32_t Pin;                                                      
                                                                               

  uint32_t Mode;                                                               
                                                                             

  uint32_t Pull;                                                                                
                                                                             

  uint32_t Speed;                                                     
                                                                              

  uint32_t Alternate;                                                      
                                                                                                        
} GPIO_InitTypeDef;

   
                                                  
    
typedef enum
{
  GPIO_PIN_RESET = 0U,
  GPIO_PIN_SET
} GPIO_PinState;
   
      
    

                                                                                
                                                             
      
    
                                 
      
    
#define GPIO_PIN_0                 ((uint16_t)0x0001)                         
#define GPIO_PIN_1                 ((uint16_t)0x0002)                         
#define GPIO_PIN_2                 ((uint16_t)0x0004)                         
#define GPIO_PIN_3                 ((uint16_t)0x0008)                         
#define GPIO_PIN_4                 ((uint16_t)0x0010)                         
#define GPIO_PIN_5                 ((uint16_t)0x0020)                         
#define GPIO_PIN_6                 ((uint16_t)0x0040)                         
#define GPIO_PIN_7                 ((uint16_t)0x0080)                         
#define GPIO_PIN_8                 ((uint16_t)0x0100)                         
#define GPIO_PIN_9                 ((uint16_t)0x0200)                         
#define GPIO_PIN_10                ((uint16_t)0x0400)                         
#define GPIO_PIN_11                ((uint16_t)0x0800)                         
#define GPIO_PIN_12                ((uint16_t)0x1000)                         
#define GPIO_PIN_13                ((uint16_t)0x2000)                         
#define GPIO_PIN_14                ((uint16_t)0x4000)                         
#define GPIO_PIN_15                ((uint16_t)0x8000)                         
#define GPIO_PIN_All               ((uint16_t)0xFFFF)                         

#define GPIO_PIN_MASK              ((uint32_t)0x0000FFFF)                               
   
      
    

                                 
                                  
                                                 
                                                     
                                                      
                                                                   
                                                                             
      
    
#define GPIO_MODE_INPUT                 MODE_INPUT                                                                                                                            
#define GPIO_MODE_OUTPUT_PP             (MODE_OUTPUT | OUTPUT_PP)                                                                                                             
#define GPIO_MODE_OUTPUT_OD             (MODE_OUTPUT | OUTPUT_OD)                                                                                                             
#define GPIO_MODE_AF_PP                 (MODE_AF | OUTPUT_PP)                                                                                                                 
#define GPIO_MODE_AF_OD                 (MODE_AF | OUTPUT_OD)                                                                                                                 
#define GPIO_MODE_ANALOG                MODE_ANALOG                                                                                                                           
#define GPIO_MODE_ANALOG_ADC_CONTROL    (MODE_ANALOG | 0x8uL)                                                                                          
#define GPIO_MODE_IT_RISING             (MODE_INPUT | EXTI_IT | TRIGGER_RISING)                                                                                               
#define GPIO_MODE_IT_FALLING            (MODE_INPUT | EXTI_IT | TRIGGER_FALLING)                                                                                              
#define GPIO_MODE_IT_RISING_FALLING     (MODE_INPUT | EXTI_IT | TRIGGER_RISING | TRIGGER_FALLING)                                                                             
#define GPIO_MODE_EVT_RISING            (MODE_INPUT | EXTI_EVT | TRIGGER_RISING)                                                                                              
#define GPIO_MODE_EVT_FALLING           (MODE_INPUT | EXTI_EVT | TRIGGER_FALLING)                                                                                             
#define GPIO_MODE_EVT_RISING_FALLING    (MODE_INPUT | EXTI_EVT | TRIGGER_RISING | TRIGGER_FALLING)                                                                            
   
      
    

                                   
                                        
      
    
#define GPIO_SPEED_FREQ_LOW             0x00000000u                         
#define GPIO_SPEED_FREQ_MEDIUM          0x00000001u                         
#define GPIO_SPEED_FREQ_HIGH            0x00000002u                         
#define GPIO_SPEED_FREQ_VERY_HIGH       0x00000003u                         
   
      
    

                                 
                                               
      
    
#define GPIO_NOPULL                     0x00000000u                                              
#define GPIO_PULLUP                     0x00000001u                                              
#define GPIO_PULLDOWN                   0x00000002u                                              
   
      
    

   
      
    

                                                                                
                                                       
      
    

   
                                                                     
                                                                
                                                                  
                                                          
    
#define __HAL_GPIO_EXTI_GET_FLAG(__EXTI_LINE__)       (EXTI->PR1 & (__EXTI_LINE__))

   
                                                
                                                                  
                                                                                      
                
    
#define __HAL_GPIO_EXTI_CLEAR_FLAG(__EXTI_LINE__)     (EXTI->PR1 = (__EXTI_LINE__))

   
                                                                     
                                                           
                                                                   
                                                          
    
#define __HAL_GPIO_EXTI_GET_IT(__EXTI_LINE__)         (EXTI->PR1 & (__EXTI_LINE__))

   
                                               
                                                            
                                                                                       
                
    
#define __HAL_GPIO_EXTI_CLEAR_IT(__EXTI_LINE__)       (EXTI->PR1 = (__EXTI_LINE__))

   
                                                                
                                                           
                                                                   
                
    
#define __HAL_GPIO_EXTI_GENERATE_SWIT(__EXTI_LINE__)  (EXTI->SWIER1 |= (__EXTI_LINE__))

   
      
    

                                                                                
                                                           
      
    
#define GPIO_MODE_Pos                           0u
#define GPIO_MODE                               (0x3uL << GPIO_MODE_Pos)
#define MODE_INPUT                              (0x0uL << GPIO_MODE_Pos)
#define MODE_OUTPUT                             (0x1uL << GPIO_MODE_Pos)
#define MODE_AF                                 (0x2uL << GPIO_MODE_Pos)
#define MODE_ANALOG                             (0x3uL << GPIO_MODE_Pos)
#define OUTPUT_TYPE_Pos                         4u
#define OUTPUT_TYPE                             (0x1uL << OUTPUT_TYPE_Pos)
#define OUTPUT_PP                               (0x0uL << OUTPUT_TYPE_Pos)
#define OUTPUT_OD                               (0x1uL << OUTPUT_TYPE_Pos)
#define EXTI_MODE_Pos                           16u
#define EXTI_MODE                               (0x3uL << EXTI_MODE_Pos)
#define EXTI_IT                                 (0x1uL << EXTI_MODE_Pos)
#define EXTI_EVT                                (0x2uL << EXTI_MODE_Pos)
#define TRIGGER_MODE_Pos                         20u
#define TRIGGER_MODE                            (0x7uL << TRIGGER_MODE_Pos)
#define TRIGGER_RISING                          (0x1uL << TRIGGER_MODE_Pos)
#define TRIGGER_FALLING                         (0x2uL << TRIGGER_MODE_Pos)

   
      
    

                                                       
      
    
#define IS_GPIO_PIN_ACTION(ACTION)  (((ACTION) == GPIO_PIN_RESET) || ((ACTION) == GPIO_PIN_SET))

#define IS_GPIO_PIN(__PIN__)        ((((uint32_t)(__PIN__) & GPIO_PIN_MASK) != 0x00U) &&\
                                     (((uint32_t)(__PIN__) & ~GPIO_PIN_MASK) == 0x00U))

#define IS_GPIO_MODE(__MODE__)      (((__MODE__) == GPIO_MODE_INPUT)              ||\
                                     ((__MODE__) == GPIO_MODE_OUTPUT_PP)          ||\
                                     ((__MODE__) == GPIO_MODE_OUTPUT_OD)          ||\
                                     ((__MODE__) == GPIO_MODE_AF_PP)              ||\
                                     ((__MODE__) == GPIO_MODE_AF_OD)              ||\
                                     ((__MODE__) == GPIO_MODE_IT_RISING)          ||\
                                     ((__MODE__) == GPIO_MODE_IT_FALLING)         ||\
                                     ((__MODE__) == GPIO_MODE_IT_RISING_FALLING)  ||\
                                     ((__MODE__) == GPIO_MODE_EVT_RISING)         ||\
                                     ((__MODE__) == GPIO_MODE_EVT_FALLING)        ||\
                                     ((__MODE__) == GPIO_MODE_EVT_RISING_FALLING) ||\
                                     ((__MODE__) == GPIO_MODE_ANALOG)             ||\
                                     ((__MODE__) == GPIO_MODE_ANALOG_ADC_CONTROL))

#define IS_GPIO_SPEED(__SPEED__)    (((__SPEED__) == GPIO_SPEED_FREQ_LOW)       ||\
                                     ((__SPEED__) == GPIO_SPEED_FREQ_MEDIUM)    ||\
                                     ((__SPEED__) == GPIO_SPEED_FREQ_HIGH)      ||\
                                     ((__SPEED__) == GPIO_SPEED_FREQ_VERY_HIGH))

#define IS_GPIO_PULL(__PULL__)      (((__PULL__) == GPIO_NOPULL)   ||\
                                     ((__PULL__) == GPIO_PULLUP)   || \
                                     ((__PULL__) == GPIO_PULLDOWN))
   
      
    

                                      
#include "stm32l4xx_hal_gpio_ex.h"

                                                                                
                                                               
      
    

                                                                                         
                                                        
     
   

                                                                                
void              HAL_GPIO_Init(GPIO_TypeDef  *GPIOx, GPIO_InitTypeDef *GPIO_Init);
void              HAL_GPIO_DeInit(GPIO_TypeDef  *GPIOx, uint32_t GPIO_Pin);

   
      
    

                                                                     
     
   

                                                                                
GPIO_PinState     HAL_GPIO_ReadPin(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin);
void              HAL_GPIO_WritePin(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin, GPIO_PinState PinState);
void              HAL_GPIO_TogglePin(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin);
HAL_StatusTypeDef HAL_GPIO_LockPin(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin);
void              HAL_GPIO_EXTI_IRQHandler(uint16_t GPIO_Pin);
void              HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin);

   
      
    

   
      
    

   
      
    

   
      
    

#ifdef __cplusplus
}
#endif

#endif                           

