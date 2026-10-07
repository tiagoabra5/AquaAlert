/**
  ******************************************************************************
  * @file    stm32l4xx_hal_lcd.h
  * @author  MCD Application Team
  * @brief   Header file of LCD Controller HAL module.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2017 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file in
  * the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  ******************************************************************************
  */

                                                                                
#ifndef STM32L4xx_HAL_LCD_H
#define STM32L4xx_HAL_LCD_H

#ifdef __cplusplus
extern "C" {
#endif

#if defined(STM32L433xx) || defined(STM32L443xx) || defined(STM32L476xx) || defined(STM32L486xx) || defined(STM32L496xx) || defined(STM32L4A6xx)

                                                                                
#include "stm32l4xx_hal_def.h"

                                    
      
    

                   
      
    

                                                                                
                                                   
      
    

   
                                        
    

typedef struct
{
  uint32_t Prescaler;                                         
                                                                                         
  uint32_t Divider;                                         
                                                                                       
  uint32_t Duty;                                         
                                                                                    
  uint32_t Bias;                                         
                                                                                    
  uint32_t VoltageSource;                                       
                                                                                              
  uint32_t Contrast;                                         
                                                                                        
  uint32_t DeadTime;                                          
                                                                                        
  uint32_t PulseOnDuration;                                           
                                                                                               
  uint32_t HighDrive;                                                         
                                                                                         
  uint32_t BlinkMode;                                          
                                                                                         
  uint32_t BlinkFrequency;                                          
                                                                                              
  uint32_t MuxSegment;                                         
                                                                                          
} LCD_InitTypeDef;

   
                                              
    
typedef enum
{
  HAL_LCD_STATE_RESET             = 0x00,                                             
  HAL_LCD_STATE_READY             = 0x01,                                                    
  HAL_LCD_STATE_BUSY              = 0x02,                                          
  HAL_LCD_STATE_TIMEOUT           = 0x03,                         
  HAL_LCD_STATE_ERROR             = 0x04                  
} HAL_LCD_StateTypeDef;

   
                                            
    
typedef struct
{
  LCD_TypeDef                   *Instance;                                  

  LCD_InitTypeDef               Init;                                         

  HAL_LockTypeDef               Lock;                           

  __IO HAL_LCD_StateTypeDef     State;                                   

  __IO uint32_t                 ErrorCode;                      

} LCD_HandleTypeDef;
   
      
    

                                                                                
                                                           
      
    

                                           
      
    
#define HAL_LCD_ERROR_NONE       (0x00000000U)                    
#define HAL_LCD_ERROR_FCRSF      (0x00000001U)                                      
#define HAL_LCD_ERROR_UDR        (0x00000002U)                                                     
#define HAL_LCD_ERROR_UDD        (0x00000004U)                                                  
#define HAL_LCD_ERROR_ENS        (0x00000008U)                                                 
#define HAL_LCD_ERROR_RDY        (0x00000010U)                                           
   
      
    

                                         
      
    
#define LCD_PRESCALER_1        (0x00000000U)                               
#define LCD_PRESCALER_2        (0x00400000U)                               
#define LCD_PRESCALER_4        (0x00800000U)                               
#define LCD_PRESCALER_8        (0x00C00000U)                               
#define LCD_PRESCALER_16       (0x01000000U)                               
#define LCD_PRESCALER_32       (0x01400000U)                               
#define LCD_PRESCALER_64       (0x01800000U)                               
#define LCD_PRESCALER_128      (0x01C00000U)                               
#define LCD_PRESCALER_256      (0x02000000U)                               
#define LCD_PRESCALER_512      (0x02400000U)                               
#define LCD_PRESCALER_1024     (0x02800000U)                               
#define LCD_PRESCALER_2048     (0x02C00000U)                               
#define LCD_PRESCALER_4096     (0x03000000U)                               
#define LCD_PRESCALER_8192     (0x03400000U)                               
#define LCD_PRESCALER_16384    (0x03800000U)                               
#define LCD_PRESCALER_32768    (0x03C00000U)                               
   
      
    

                                     
      
    
#define LCD_DIVIDER_16    (0x00000000U)                                  
#define LCD_DIVIDER_17    (0x00040000U)                                  
#define LCD_DIVIDER_18    (0x00080000U)                                  
#define LCD_DIVIDER_19    (0x000C0000U)                                  
#define LCD_DIVIDER_20    (0x00100000U)                                  
#define LCD_DIVIDER_21    (0x00140000U)                                  
#define LCD_DIVIDER_22    (0x00180000U)                                  
#define LCD_DIVIDER_23    (0x001C0000U)                                  
#define LCD_DIVIDER_24    (0x00200000U)                                  
#define LCD_DIVIDER_25    (0x00240000U)                                  
#define LCD_DIVIDER_26    (0x00280000U)                                  
#define LCD_DIVIDER_27    (0x002C0000U)                                  
#define LCD_DIVIDER_28    (0x00300000U)                                  
#define LCD_DIVIDER_29    (0x00340000U)                                  
#define LCD_DIVIDER_30    (0x00380000U)                                  
#define LCD_DIVIDER_31    (0x003C0000U)                                  
   
      
    


                               
      
    
#define LCD_DUTY_STATIC                 (0x00000000U)                                        
#define LCD_DUTY_1_2                    (LCD_CR_DUTY_0)                                      
#define LCD_DUTY_1_3                    (LCD_CR_DUTY_1)                                      
#define LCD_DUTY_1_4                    ((LCD_CR_DUTY_1 | LCD_CR_DUTY_0))                    
#define LCD_DUTY_1_8                    (LCD_CR_DUTY_2)                                      
   
      
    


                               
      
    
#define LCD_BIAS_1_4                    (0x00000000U)                 
#define LCD_BIAS_1_2                    LCD_CR_BIAS_0                 
#define LCD_BIAS_1_3                    LCD_CR_BIAS_1                 
   
      
    

                                                   
      
    
#define LCD_VOLTAGESOURCE_INTERNAL      (0x00000000U)                                             
#define LCD_VOLTAGESOURCE_EXTERNAL      LCD_CR_VSEL                                               
   
      
    

                                           
      
    
#define LCD_IT_SOF                      LCD_FCR_SOFIE
#define LCD_IT_UDD                      LCD_FCR_UDDIE
   
      
    

                                                       
      
    
#define LCD_PULSEONDURATION_0           (0x00000000U)                                                       
#define LCD_PULSEONDURATION_1           (LCD_FCR_PON_0)                                                     
#define LCD_PULSEONDURATION_2           (LCD_FCR_PON_1)                                                     
#define LCD_PULSEONDURATION_3           (LCD_FCR_PON_1 | LCD_FCR_PON_0)                                     
#define LCD_PULSEONDURATION_4           (LCD_FCR_PON_2)                                                     
#define LCD_PULSEONDURATION_5           (LCD_FCR_PON_2 | LCD_FCR_PON_0)                                     
#define LCD_PULSEONDURATION_6           (LCD_FCR_PON_2 | LCD_FCR_PON_1)                                     
#define LCD_PULSEONDURATION_7           (LCD_FCR_PON)                                                       
   
      
    


                                        
      
    
#define LCD_DEADTIME_0                  (0x00000000U)                                                                          
#define LCD_DEADTIME_1                  (LCD_FCR_DEAD_0)                                                                       
#define LCD_DEADTIME_2                  (LCD_FCR_DEAD_1)                                                                       
#define LCD_DEADTIME_3                  (LCD_FCR_DEAD_1 | LCD_FCR_DEAD_0)                                                      
#define LCD_DEADTIME_4                  (LCD_FCR_DEAD_2)                                                                       
#define LCD_DEADTIME_5                  (LCD_FCR_DEAD_2 | LCD_FCR_DEAD_0)                                                      
#define LCD_DEADTIME_6                  (LCD_FCR_DEAD_2 | LCD_FCR_DEAD_1)                                                      
#define LCD_DEADTIME_7                  (LCD_FCR_DEAD)                                                                         
   
      
    

                                          
      
    
#define LCD_BLINKMODE_OFF               (0x00000000U)                                                                     
#define LCD_BLINKMODE_SEG0_COM0         (LCD_FCR_BLINK_0)                                                                 
#define LCD_BLINKMODE_SEG0_ALLCOM       (LCD_FCR_BLINK_1)                                                   
                                                                                                                          
#define LCD_BLINKMODE_ALLSEG_ALLCOM     (LCD_FCR_BLINK)                                                                   
   
      
    

                                                    
      
    
#define LCD_BLINKFREQUENCY_DIV8         (0x00000000U)                                                                
#define LCD_BLINKFREQUENCY_DIV16        (LCD_FCR_BLINKF_0)                                                           
#define LCD_BLINKFREQUENCY_DIV32        (LCD_FCR_BLINKF_1)                                                           
#define LCD_BLINKFREQUENCY_DIV64        (LCD_FCR_BLINKF_1 | LCD_FCR_BLINKF_0)                                        
#define LCD_BLINKFREQUENCY_DIV128       (LCD_FCR_BLINKF_2)                                                           
#define LCD_BLINKFREQUENCY_DIV256       (LCD_FCR_BLINKF_2 |LCD_FCR_BLINKF_0)                                         
#define LCD_BLINKFREQUENCY_DIV512       (LCD_FCR_BLINKF_2 |LCD_FCR_BLINKF_1)                                         
#define LCD_BLINKFREQUENCY_DIV1024      (LCD_FCR_BLINKF)                                                             
   
      
    

                                       
      
    
#define LCD_CONTRASTLEVEL_0               (0x00000000U)                                                   
#define LCD_CONTRASTLEVEL_1               (LCD_FCR_CC_0)                                                  
#define LCD_CONTRASTLEVEL_2               (LCD_FCR_CC_1)                                                  
#define LCD_CONTRASTLEVEL_3               (LCD_FCR_CC_1 | LCD_FCR_CC_0)                                   
#define LCD_CONTRASTLEVEL_4               (LCD_FCR_CC_2)                                                  
#define LCD_CONTRASTLEVEL_5               (LCD_FCR_CC_2 | LCD_FCR_CC_0)                                   
#define LCD_CONTRASTLEVEL_6               (LCD_FCR_CC_2 | LCD_FCR_CC_1)                                   
#define LCD_CONTRASTLEVEL_7               (LCD_FCR_CC)                                                    
   
      
    

                                             
      
    
#define LCD_RAM_REGISTER0               (0x00000000U)                            
#define LCD_RAM_REGISTER1               (0x00000001U)                            
#define LCD_RAM_REGISTER2               (0x00000002U)                            
#define LCD_RAM_REGISTER3               (0x00000003U)                            
#define LCD_RAM_REGISTER4               (0x00000004U)                            
#define LCD_RAM_REGISTER5               (0x00000005U)                            
#define LCD_RAM_REGISTER6               (0x00000006U)                            
#define LCD_RAM_REGISTER7               (0x00000007U)                            
#define LCD_RAM_REGISTER8               (0x00000008U)                            
#define LCD_RAM_REGISTER9               (0x00000009U)                            
#define LCD_RAM_REGISTER10              (0x0000000AU)                            
#define LCD_RAM_REGISTER11              (0x0000000BU)                            
#define LCD_RAM_REGISTER12              (0x0000000CU)                            
#define LCD_RAM_REGISTER13              (0x0000000DU)                            
#define LCD_RAM_REGISTER14              (0x0000000EU)                            
#define LCD_RAM_REGISTER15              (0x0000000FU)                            
   
      
    

                                          
      
    

#define LCD_HIGHDRIVE_DISABLE             ((uint32_t)0x00000000)                                   
#define LCD_HIGHDRIVE_ENABLE              (LCD_FCR_HD)                                             
   
      
    

                                            
      
    

#define LCD_MUXSEGMENT_DISABLE            (0x00000000U)                                                                      
#define LCD_MUXSEGMENT_ENABLE             (LCD_CR_MUX_SEG)                                                                   
   
      
    

                                                      
      
    
#define LCD_FLAG_ENS                    LCD_SR_ENS                             
#define LCD_FLAG_SOF                    LCD_SR_SOF                              
#define LCD_FLAG_UDR                    LCD_SR_UDR                                 
#define LCD_FLAG_UDD                    LCD_SR_UDD                              
#define LCD_FLAG_RDY                    LCD_SR_RDY                     
#define LCD_FLAG_FCRSF                  LCD_SR_FCRSR                                                        
   
      
    

   
      
    

                                                                                
                                                     
      
    

                                  
                                               
                
    
#define __HAL_LCD_RESET_HANDLE_STATE(__HANDLE__)  ((__HANDLE__)->State = HAL_LCD_STATE_RESET)

                                      
                                               
                
    
#define __HAL_LCD_ENABLE(__HANDLE__)              SET_BIT((__HANDLE__)->Instance->CR, LCD_CR_LCDEN)

                                       
                                               
                
    
#define __HAL_LCD_DISABLE(__HANDLE__)             CLEAR_BIT((__HANDLE__)->Instance->CR, LCD_CR_LCDEN)

                                              
                                               
                                                                                  
                                                                                  
                                                               
                                                                            
                                                          
                
    
#define __HAL_LCD_HIGHDRIVER_ENABLE(__HANDLE__)                       \
                  do {                                                \
                    SET_BIT((__HANDLE__)->Instance->FCR, LCD_FCR_HD); \
                    LCD_WaitForSynchro(__HANDLE__);                   \
                  } while(0)

                                               
                                               
                
    
#define __HAL_LCD_HIGHDRIVER_DISABLE(__HANDLE__)                        \
                  do {                                                  \
                    CLEAR_BIT((__HANDLE__)->Instance->FCR, LCD_FCR_HD); \
                    LCD_WaitForSynchro(__HANDLE__);                     \
                  } while(0)

                                                                           
                                               
                
    
#define __HAL_LCD_VOLTAGE_BUFFER_ENABLE(__HANDLE__)   SET_BIT((__HANDLE__)->Instance->CR, LCD_CR_BUFEN)

                                                                            
                                               
                
    
#define __HAL_LCD_VOLTAGE_BUFFER_DISABLE(__HANDLE__)  CLEAR_BIT((__HANDLE__)->Instance->CR, LCD_CR_BUFEN)

   
                                                
                                               
                                                                       
                                                      
                                                        
                                           
                                                               
                                                               
                                                               
                                                               
                                                               
                                                               
                                                               
                
    
#define __HAL_LCD_PULSEONDURATION_CONFIG(__HANDLE__, __DURATION__)                        \
                  do {                                                                    \
                    MODIFY_REG((__HANDLE__)->Instance->FCR, LCD_FCR_PON, (__DURATION__)); \
                    LCD_WaitForSynchro(__HANDLE__);                                       \
                  } while(0)

   
                                        
                                               
                                                    
                                                        
                                         
                                                                        
                                                                        
                                                                          
                                                                         
                                                                         
                                                                        
                                                                          
                
    
#define __HAL_LCD_DEADTIME_CONFIG(__HANDLE__, __DEADTIME__)                                \
                  do {                                                                     \
                    MODIFY_REG((__HANDLE__)->Instance->FCR, LCD_FCR_DEAD, (__DEADTIME__)); \
                    LCD_WaitForSynchro(__HANDLE__);                                        \
                  } while(0)

   
                                       
                                               
                                                   
                                                        
                                                         
                                                         
                                                         
                                                         
                                                         
                                                         
                                                         
                                                         
                
    
#define __HAL_LCD_CONTRAST_CONFIG(__HANDLE__, __CONTRAST__)                           \
              do {                                                                    \
                MODIFY_REG((__HANDLE__)->Instance->FCR, LCD_FCR_CC, (__CONTRAST__));  \
                LCD_WaitForSynchro(__HANDLE__);                                       \
              } while(0)

   
                                                             
                                               
                                                      
                                                        
                                                        
                                                                                   
                                                                                   
                                                                                  
                                                                              
                                                      
                                                                
                                                                     
                                                                      
                                                                      
                                                                      
                                                                       
                                                                       
                                                                       
                                                                        
                
    
#define __HAL_LCD_BLINK_CONFIG(__HANDLE__, __BLINKMODE__, __BLINKFREQUENCY__)         \
              do {                                                                    \
                MODIFY_REG((__HANDLE__)->Instance->FCR, (LCD_FCR_BLINKF | LCD_FCR_BLINK), ((__BLINKMODE__) | (__BLINKFREQUENCY__))); \
                LCD_WaitForSynchro(__HANDLE__);                                       \
              } while(0)

                                               
                                               
                                                                          
                                                               
                                                 
                                                      
                
    
#define __HAL_LCD_ENABLE_IT(__HANDLE__, __INTERRUPT__)                      \
                  do {                                                      \
                    SET_BIT((__HANDLE__)->Instance->FCR, (__INTERRUPT__));  \
                    LCD_WaitForSynchro(__HANDLE__);                         \
                  } while(0)

                                                
                                               
                                                                           
                                                               
                                                 
                                                      
                
    
#define __HAL_LCD_DISABLE_IT(__HANDLE__, __INTERRUPT__)                      \
                  do {                                                       \
                    CLEAR_BIT((__HANDLE__)->Instance->FCR, (__INTERRUPT__)); \
                    LCD_WaitForSynchro(__HANDLE__);                          \
                  } while(0)

                                                                               
                                               
                                                              
                                                             
                                                    
                                                          
                                                                        
                                                     
                                                                              
                                                
    
#define __HAL_LCD_GET_IT_SOURCE(__HANDLE__, __IT__) (((__HANDLE__)->Instance->FCR) & (__IT__))

                                                               
                                               
                                                
                                                             
                                                                                       
                                                                          
                                                                                
                                                                           
                                                                                  
                                                                                     
                        
                                                          
                                                       
                                                                                   
                                         
                                                                                
                                                                                      
                                     
                                                      
    
#define __HAL_LCD_GET_FLAG(__HANDLE__, __FLAG__)    (((__HANDLE__)->Instance->SR & (__FLAG__)) == (__FLAG__))

                                                 
                                               
                                                
                                                                         
                                                      
                                                           
                
    
#define __HAL_LCD_CLEAR_FLAG(__HANDLE__, __FLAG__)  WRITE_REG((__HANDLE__)->Instance->CLR, (__FLAG__))

   
      
    

                                                                                
                                      
      
    

                                                                                
                                             
      
    
HAL_StatusTypeDef    HAL_LCD_DeInit(LCD_HandleTypeDef *hlcd);
HAL_StatusTypeDef    HAL_LCD_Init(LCD_HandleTypeDef *hlcd);
void                 HAL_LCD_MspInit(LCD_HandleTypeDef *hlcd);
void                 HAL_LCD_MspDeInit(LCD_HandleTypeDef *hlcd);
   
      
    

                                                                                
                                             
      
    
HAL_StatusTypeDef    HAL_LCD_Write(LCD_HandleTypeDef *hlcd, uint32_t RAMRegisterIndex, uint32_t RAMRegisterMask, uint32_t Data);
HAL_StatusTypeDef    HAL_LCD_Clear(LCD_HandleTypeDef *hlcd);
HAL_StatusTypeDef    HAL_LCD_UpdateDisplayRequest(LCD_HandleTypeDef *hlcd);
   
      
    

                                                                                
                                             
      
    
HAL_LCD_StateTypeDef HAL_LCD_GetState(LCD_HandleTypeDef *hlcd);
uint32_t             HAL_LCD_GetError(LCD_HandleTypeDef *hlcd);
   
      
    

   
      
    

                                                                                
                                                                                
                                                                                
                                                                                
                                                   
      
    

#define IS_LCD_PRESCALER(__PRESCALER__) (((__PRESCALER__) == LCD_PRESCALER_1)     || \
                                         ((__PRESCALER__) == LCD_PRESCALER_2)     || \
                                         ((__PRESCALER__) == LCD_PRESCALER_4)     || \
                                         ((__PRESCALER__) == LCD_PRESCALER_8)     || \
                                         ((__PRESCALER__) == LCD_PRESCALER_16)    || \
                                         ((__PRESCALER__) == LCD_PRESCALER_32)    || \
                                         ((__PRESCALER__) == LCD_PRESCALER_64)    || \
                                         ((__PRESCALER__) == LCD_PRESCALER_128)   || \
                                         ((__PRESCALER__) == LCD_PRESCALER_256)   || \
                                         ((__PRESCALER__) == LCD_PRESCALER_512)   || \
                                         ((__PRESCALER__) == LCD_PRESCALER_1024)  || \
                                         ((__PRESCALER__) == LCD_PRESCALER_2048)  || \
                                         ((__PRESCALER__) == LCD_PRESCALER_4096)  || \
                                         ((__PRESCALER__) == LCD_PRESCALER_8192)  || \
                                         ((__PRESCALER__) == LCD_PRESCALER_16384) || \
                                         ((__PRESCALER__) == LCD_PRESCALER_32768))

#define IS_LCD_DIVIDER(__DIVIDER__) (((__DIVIDER__) == LCD_DIVIDER_16) || \
                                     ((__DIVIDER__) == LCD_DIVIDER_17) || \
                                     ((__DIVIDER__) == LCD_DIVIDER_18) || \
                                     ((__DIVIDER__) == LCD_DIVIDER_19) || \
                                     ((__DIVIDER__) == LCD_DIVIDER_20) || \
                                     ((__DIVIDER__) == LCD_DIVIDER_21) || \
                                     ((__DIVIDER__) == LCD_DIVIDER_22) || \
                                     ((__DIVIDER__) == LCD_DIVIDER_23) || \
                                     ((__DIVIDER__) == LCD_DIVIDER_24) || \
                                     ((__DIVIDER__) == LCD_DIVIDER_25) || \
                                     ((__DIVIDER__) == LCD_DIVIDER_26) || \
                                     ((__DIVIDER__) == LCD_DIVIDER_27) || \
                                     ((__DIVIDER__) == LCD_DIVIDER_28) || \
                                     ((__DIVIDER__) == LCD_DIVIDER_29) || \
                                     ((__DIVIDER__) == LCD_DIVIDER_30) || \
                                     ((__DIVIDER__) == LCD_DIVIDER_31))

#define IS_LCD_DUTY(__DUTY__) (((__DUTY__) == LCD_DUTY_STATIC)  || \
                               ((__DUTY__) == LCD_DUTY_1_2)     || \
                               ((__DUTY__) == LCD_DUTY_1_3)     || \
                               ((__DUTY__) == LCD_DUTY_1_4)     || \
                               ((__DUTY__) == LCD_DUTY_1_8))

#define IS_LCD_BIAS(__BIAS__) (((__BIAS__) == LCD_BIAS_1_4) || \
                               ((__BIAS__) == LCD_BIAS_1_2) || \
                               ((__BIAS__) == LCD_BIAS_1_3))

#define IS_LCD_VOLTAGE_SOURCE(SOURCE) (((SOURCE) == LCD_VOLTAGESOURCE_INTERNAL) || \
                                       ((SOURCE) == LCD_VOLTAGESOURCE_EXTERNAL))


#define IS_LCD_PULSE_ON_DURATION(__DURATION__) (((__DURATION__) == LCD_PULSEONDURATION_0) || \
                                                ((__DURATION__) == LCD_PULSEONDURATION_1) || \
                                                ((__DURATION__) == LCD_PULSEONDURATION_2) || \
                                                ((__DURATION__) == LCD_PULSEONDURATION_3) || \
                                                ((__DURATION__) == LCD_PULSEONDURATION_4) || \
                                                ((__DURATION__) == LCD_PULSEONDURATION_5) || \
                                                ((__DURATION__) == LCD_PULSEONDURATION_6) || \
                                                ((__DURATION__) == LCD_PULSEONDURATION_7))

#define IS_LCD_DEAD_TIME(__TIME__) (((__TIME__) == LCD_DEADTIME_0) || \
                                    ((__TIME__) == LCD_DEADTIME_1) || \
                                    ((__TIME__) == LCD_DEADTIME_2) || \
                                    ((__TIME__) == LCD_DEADTIME_3) || \
                                    ((__TIME__) == LCD_DEADTIME_4) || \
                                    ((__TIME__) == LCD_DEADTIME_5) || \
                                    ((__TIME__) == LCD_DEADTIME_6) || \
                                    ((__TIME__) == LCD_DEADTIME_7))

#define IS_LCD_BLINK_MODE(__MODE__) (((__MODE__) == LCD_BLINKMODE_OFF)            || \
                                     ((__MODE__) == LCD_BLINKMODE_SEG0_COM0)      || \
                                     ((__MODE__) == LCD_BLINKMODE_SEG0_ALLCOM)    || \
                                     ((__MODE__) == LCD_BLINKMODE_ALLSEG_ALLCOM))

#define IS_LCD_BLINK_FREQUENCY(__FREQUENCY__) (((__FREQUENCY__) == LCD_BLINKFREQUENCY_DIV8)   || \
                                               ((__FREQUENCY__) == LCD_BLINKFREQUENCY_DIV16)  || \
                                               ((__FREQUENCY__) == LCD_BLINKFREQUENCY_DIV32)  || \
                                               ((__FREQUENCY__) == LCD_BLINKFREQUENCY_DIV64)  || \
                                               ((__FREQUENCY__) == LCD_BLINKFREQUENCY_DIV128) || \
                                               ((__FREQUENCY__) == LCD_BLINKFREQUENCY_DIV256) || \
                                               ((__FREQUENCY__) == LCD_BLINKFREQUENCY_DIV512) || \
                                               ((__FREQUENCY__) == LCD_BLINKFREQUENCY_DIV1024))

#define IS_LCD_CONTRAST(__CONTRAST__) (((__CONTRAST__) == LCD_CONTRASTLEVEL_0) || \
                                       ((__CONTRAST__) == LCD_CONTRASTLEVEL_1) || \
                                       ((__CONTRAST__) == LCD_CONTRASTLEVEL_2) || \
                                       ((__CONTRAST__) == LCD_CONTRASTLEVEL_3) || \
                                       ((__CONTRAST__) == LCD_CONTRASTLEVEL_4) || \
                                       ((__CONTRAST__) == LCD_CONTRASTLEVEL_5) || \
                                       ((__CONTRAST__) == LCD_CONTRASTLEVEL_6) || \
                                       ((__CONTRAST__) == LCD_CONTRASTLEVEL_7))

#define IS_LCD_RAM_REGISTER(__REGISTER__) (((__REGISTER__) == LCD_RAM_REGISTER0)  || \
                                           ((__REGISTER__) == LCD_RAM_REGISTER1)  || \
                                           ((__REGISTER__) == LCD_RAM_REGISTER2)  || \
                                           ((__REGISTER__) == LCD_RAM_REGISTER3)  || \
                                           ((__REGISTER__) == LCD_RAM_REGISTER4)  || \
                                           ((__REGISTER__) == LCD_RAM_REGISTER5)  || \
                                           ((__REGISTER__) == LCD_RAM_REGISTER6)  || \
                                           ((__REGISTER__) == LCD_RAM_REGISTER7)  || \
                                           ((__REGISTER__) == LCD_RAM_REGISTER8)  || \
                                           ((__REGISTER__) == LCD_RAM_REGISTER9)  || \
                                           ((__REGISTER__) == LCD_RAM_REGISTER10) || \
                                           ((__REGISTER__) == LCD_RAM_REGISTER11) || \
                                           ((__REGISTER__) == LCD_RAM_REGISTER12) || \
                                           ((__REGISTER__) == LCD_RAM_REGISTER13) || \
                                           ((__REGISTER__) == LCD_RAM_REGISTER14) || \
                                           ((__REGISTER__) == LCD_RAM_REGISTER15))

#define IS_LCD_HIGH_DRIVE(__VALUE__) (((__VALUE__) == LCD_HIGHDRIVE_DISABLE) || \
                                      ((__VALUE__) == LCD_HIGHDRIVE_ENABLE))

#define IS_LCD_MUX_SEGMENT(__VALUE__) (((__VALUE__) == LCD_MUXSEGMENT_ENABLE) || \
                                       ((__VALUE__) == LCD_MUXSEGMENT_DISABLE))

   
      
    

                                                                                
                                     
      
    

HAL_StatusTypeDef     LCD_WaitForSynchro(LCD_HandleTypeDef *hlcd);

   
      
    

   
      
    

   
      
    

#endif                                                                                             

#ifdef __cplusplus
}
#endif

#endif                          
