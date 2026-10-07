/**
  ******************************************************************************
  * @file    stm32l4xx_hal_dfsdm.h
  * @author  MCD Application Team
  * @brief   Header file of DFSDM HAL module.
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

                                                                                
#ifndef STM32L4xx_HAL_DFSDM_H
#define STM32L4xx_HAL_DFSDM_H

#ifdef __cplusplus
extern "C" {
#endif

#if defined(STM32L451xx) || defined(STM32L452xx) || defined(STM32L462xx) || \
    defined(STM32L471xx) || defined(STM32L475xx) || defined(STM32L476xx) || defined(STM32L485xx) || defined(STM32L486xx) || \
    defined(STM32L496xx) || defined(STM32L4A6xx) || \
    defined(STM32L4R5xx) || defined(STM32L4R7xx) || defined(STM32L4R9xx) || defined(STM32L4S5xx) || defined(STM32L4S7xx) || defined(STM32L4S9xx) || \
    defined(STM32L4P5xx) || defined(STM32L4Q5xx)

                                                                                
#include "stm32l4xx_hal_def.h"

                                    
      
    

                     
      
    

                                                                                
                                                       
      
    

   
                                               
    
typedef enum
{
  HAL_DFSDM_CHANNEL_STATE_RESET = 0x00U,                                      
  HAL_DFSDM_CHANNEL_STATE_READY = 0x01U,                                                    
  HAL_DFSDM_CHANNEL_STATE_ERROR = 0xFFU                                   
} HAL_DFSDM_Channel_StateTypeDef;

   
                                                           
    
typedef struct
{
  FunctionalState Activation;                                    
  uint32_t        Selection;                                                   
                                                                                                    
  uint32_t        Divider;                              
                                                                                                             
} DFSDM_Channel_OutputClockTypeDef;

   
                                                    
    
typedef struct
{
  uint32_t Multiplexer;                                                                       
                                                                                                   
                                                                                             
                                                                                                         
                                                                                                    
  uint32_t DataPacking;                                                               
                                                                                               
  uint32_t Pins;                                                                 
                                                                                             
} DFSDM_Channel_InputTypeDef;

   
                                                               
    
typedef struct
{
  uint32_t Type;                                  
                                                                                                    
  uint32_t SpiClock;                                                                            
                                                                                         
} DFSDM_Channel_SerialInterfaceTypeDef;

   
                                                              
    
typedef struct
{
  uint32_t FilterOrder;                                         
                                                                                                   
  uint32_t Oversampling;                                                
                                                                                                       
} DFSDM_Channel_AwdTypeDef;

   
                                                   
    
typedef struct
{
  DFSDM_Channel_OutputClockTypeDef     OutputClock;                                                  
  DFSDM_Channel_InputTypeDef           Input;                                                 
  DFSDM_Channel_SerialInterfaceTypeDef SerialInterface;                                                  
  DFSDM_Channel_AwdTypeDef             Awd;                                                             
  int32_t                              Offset;                                    
                                                                                                                                                  
  uint32_t                             RightBitShift;                                      
                                                                                                                                           
} DFSDM_Channel_InitTypeDef;

   
                                                     
    
#if (USE_HAL_DFSDM_REGISTER_CALLBACKS == 1)
typedef struct __DFSDM_Channel_HandleTypeDef
#else
typedef struct
#endif                                       
{
  DFSDM_Channel_TypeDef          *Instance;                               
  DFSDM_Channel_InitTypeDef      Init;                                           
  HAL_DFSDM_Channel_StateTypeDef State;                                
#if (USE_HAL_DFSDM_REGISTER_CALLBACKS == 1)
  void (*CkabCallback)(struct __DFSDM_Channel_HandleTypeDef *hdfsdm_channel);                                                             
  void (*ScdCallback)(struct __DFSDM_Channel_HandleTypeDef *hdfsdm_channel);                                                              
  void (*MspInitCallback)(struct __DFSDM_Channel_HandleTypeDef *hdfsdm_channel);                                           
  void (*MspDeInitCallback)(struct __DFSDM_Channel_HandleTypeDef *hdfsdm_channel);                                            
#endif
} DFSDM_Channel_HandleTypeDef;

#if (USE_HAL_DFSDM_REGISTER_CALLBACKS == 1)
   
                                                            
    
typedef enum
{
  HAL_DFSDM_CHANNEL_CKAB_CB_ID      = 0x00U,                                                          
  HAL_DFSDM_CHANNEL_SCD_CB_ID       = 0x01U,                                                          
  HAL_DFSDM_CHANNEL_MSPINIT_CB_ID   = 0x02U,                                           
  HAL_DFSDM_CHANNEL_MSPDEINIT_CB_ID = 0x03U                                               
} HAL_DFSDM_Channel_CallbackIDTypeDef;

   
                                                     
    
typedef void (*pDFSDM_Channel_CallbackTypeDef)(DFSDM_Channel_HandleTypeDef *hdfsdm_channel);
#endif

   
                                              
    
typedef enum
{
  HAL_DFSDM_FILTER_STATE_RESET   = 0x00U,                                     
  HAL_DFSDM_FILTER_STATE_READY   = 0x01U,                                                   
  HAL_DFSDM_FILTER_STATE_REG     = 0x02U,                                                    
  HAL_DFSDM_FILTER_STATE_INJ     = 0x03U,                                                     
  HAL_DFSDM_FILTER_STATE_REG_INJ = 0x04U,                                                                  
  HAL_DFSDM_FILTER_STATE_ERROR   = 0xFFU                                  
} HAL_DFSDM_Filter_StateTypeDef;

   
                                                                           
    
typedef struct
{
  uint32_t        Trigger;                                                                         
                                                                                              
  FunctionalState FastMode;                                                        
  FunctionalState DmaMode;                                                   
} DFSDM_Filter_RegularParamTypeDef;

   
                                                                            
    
typedef struct
{
  uint32_t        Trigger;                                                                                          
                                                                                                    
  FunctionalState ScanMode;                                                                   
  FunctionalState DmaMode;                                                          
  uint32_t        ExtTrigger;                           
                                                                                                       
  uint32_t        ExtTriggerEdge;                                                     
                                                                                                           
} DFSDM_Filter_InjectedParamTypeDef;

   
                                                        
    
typedef struct
{
  uint32_t SincOrder;                              
                                                                                                
  uint32_t Oversampling;                                   
                                                                                                            
  uint32_t IntOversampling;                                    
                                                                                                           
} DFSDM_Filter_FilterParamTypeDef;

   
                                                  
    
typedef struct
{
  DFSDM_Filter_RegularParamTypeDef  RegularParam;                                             
  DFSDM_Filter_InjectedParamTypeDef InjectedParam;                                             
  DFSDM_Filter_FilterParamTypeDef   FilterParam;                                  
} DFSDM_Filter_InitTypeDef;

   
                                                    
    
#if (USE_HAL_DFSDM_REGISTER_CALLBACKS == 1)
typedef struct __DFSDM_Filter_HandleTypeDef
#else
typedef struct
#endif                                       
{
  DFSDM_Filter_TypeDef          *Instance;                                        
  DFSDM_Filter_InitTypeDef      Init;                                                    
  DMA_HandleTypeDef             *hdmaReg;                                                                  
  DMA_HandleTypeDef             *hdmaInj;                                                                   
  uint32_t                      RegularContMode;                                               
  uint32_t                      RegularTrigger;                                                 
  uint32_t                      InjectedTrigger;                                                 
  uint32_t                      ExtTriggerEdge;                                                    
  FunctionalState               InjectedScanMode;                                  
  uint32_t                      InjectedChannelsNbr;                                                
  uint32_t                      InjConvRemaining;                                          
  HAL_DFSDM_Filter_StateTypeDef State;                                         
  uint32_t                      ErrorCode;                                          
#if (USE_HAL_DFSDM_REGISTER_CALLBACKS == 1)
  void (*AwdCallback)(struct __DFSDM_Filter_HandleTypeDef *hdfsdm_filter,
                      uint32_t Channel, uint32_t Threshold);                                                                         
  void (*RegConvCpltCallback)(struct __DFSDM_Filter_HandleTypeDef *hdfsdm_filter);                                                               
  void (*RegConvHalfCpltCallback)(struct __DFSDM_Filter_HandleTypeDef *hdfsdm_filter);                                                                
  void (*InjConvCpltCallback)(struct __DFSDM_Filter_HandleTypeDef *hdfsdm_filter);                                                                
  void (*InjConvHalfCpltCallback)(struct __DFSDM_Filter_HandleTypeDef *hdfsdm_filter);                                                                 
  void (*ErrorCallback)(struct __DFSDM_Filter_HandleTypeDef *hdfsdm_filter);                                               
  void (*MspInitCallback)(struct __DFSDM_Filter_HandleTypeDef *hdfsdm_filter);                                                
  void (*MspDeInitCallback)(struct __DFSDM_Filter_HandleTypeDef *hdfsdm_filter);                                                 
#endif
} DFSDM_Filter_HandleTypeDef;

   
                                                                        
    
typedef struct
{
  uint32_t DataSource;                                                                      
                                                                                                    
  uint32_t Channel;                                                
                                                                                                              
  int32_t  HighThreshold;                                               
                                                                                                                      
  int32_t  LowThreshold;                                               
                                                                                                                      
  uint32_t HighBreakSignal;                                                                    
                                                                                                         
  uint32_t LowBreakSignal;                                                                    
                                                                                                         
} DFSDM_Filter_AwdParamTypeDef;

#if (USE_HAL_DFSDM_REGISTER_CALLBACKS == 1)
   
                                                           
    
typedef enum
{
  HAL_DFSDM_FILTER_REGCONV_COMPLETE_CB_ID     = 0x00U,                                                             
  HAL_DFSDM_FILTER_REGCONV_HALFCOMPLETE_CB_ID = 0x01U,                                                                  
  HAL_DFSDM_FILTER_INJCONV_COMPLETE_CB_ID     = 0x02U,                                                              
  HAL_DFSDM_FILTER_INJCONV_HALFCOMPLETE_CB_ID = 0x03U,                                                                   
  HAL_DFSDM_FILTER_ERROR_CB_ID                = 0x04U,                                       
  HAL_DFSDM_FILTER_MSPINIT_CB_ID              = 0x05U,                                          
  HAL_DFSDM_FILTER_MSPDEINIT_CB_ID            = 0x06U                                              
} HAL_DFSDM_Filter_CallbackIDTypeDef;

   
                                                    
    
typedef void (*pDFSDM_Filter_CallbackTypeDef)(DFSDM_Filter_HandleTypeDef *hdfsdm_filter);
typedef void (*pDFSDM_Filter_AwdCallbackTypeDef)(DFSDM_Filter_HandleTypeDef *hdfsdm_filter, uint32_t Channel, uint32_t Threshold);
#endif

   
      
    
                                                                                

                                                                                
                                                               
      
    

                                                                           
      
    
#define DFSDM_CHANNEL_OUTPUT_CLOCK_SYSTEM    0x00000000U                                                            
#define DFSDM_CHANNEL_OUTPUT_CLOCK_AUDIO     DFSDM_CHCFGR1_CKOUTSRC                                                
   
      
    

                                                                            
      
    
#define DFSDM_CHANNEL_EXTERNAL_INPUTS    0x00000000U                                                        
#if defined(STM32L451xx) || defined(STM32L452xx) || defined(STM32L462xx) || \
    defined(STM32L496xx) || defined(STM32L4A6xx) || \
    defined(STM32L4R5xx) || defined(STM32L4R7xx) || defined(STM32L4R9xx) || defined(STM32L4S5xx) || defined(STM32L4S7xx) || defined(STM32L4S9xx) || \
    defined(STM32L4P5xx) || defined(STM32L4Q5xx)
#define DFSDM_CHANNEL_ADC_OUTPUT         DFSDM_CHCFGR1_DATMPX_0                                        
#endif                                                                                                                                                                                                      
#define DFSDM_CHANNEL_INTERNAL_REGISTER  DFSDM_CHCFGR1_DATMPX_1                                               
   
      
    

                                                                        
      
    
#define DFSDM_CHANNEL_STANDARD_MODE         0x00000000U                                               
#define DFSDM_CHANNEL_INTERLEAVED_MODE      DFSDM_CHCFGR1_DATPACK_0                                      
#define DFSDM_CHANNEL_DUAL_MODE             DFSDM_CHCFGR1_DATPACK_1                               
   
      
    

                                                              
      
    
#define DFSDM_CHANNEL_SAME_CHANNEL_PINS      0x00000000U                                                    
#define DFSDM_CHANNEL_FOLLOWING_CHANNEL_PINS DFSDM_CHCFGR1_CHINSEL                                               
   
      
    

                                                                                   
      
    
#define DFSDM_CHANNEL_SPI_RISING         0x00000000U                                         
#define DFSDM_CHANNEL_SPI_FALLING        DFSDM_CHCFGR1_SITP_0                                 
#define DFSDM_CHANNEL_MANCHESTER_RISING  DFSDM_CHCFGR1_SITP_1                                       
#define DFSDM_CHANNEL_MANCHESTER_FALLING DFSDM_CHCFGR1_SITP                                          
   
      
    

                                                                      
      
    
#define DFSDM_CHANNEL_SPI_CLOCK_EXTERNAL              0x00000000U                                        
#define DFSDM_CHANNEL_SPI_CLOCK_INTERNAL              DFSDM_CHCFGR1_SPICKSEL_0                           
#define DFSDM_CHANNEL_SPI_CLOCK_INTERNAL_DIV2_FALLING DFSDM_CHCFGR1_SPICKSEL_1                                                      
#define DFSDM_CHANNEL_SPI_CLOCK_INTERNAL_DIV2_RISING  DFSDM_CHCFGR1_SPICKSEL                                                       
   
      
    

                                                                                     
      
    
#define DFSDM_CHANNEL_FASTSINC_ORDER 0x00000000U                                         
#define DFSDM_CHANNEL_SINC1_ORDER    DFSDM_CHAWSCDR_AWFORD_0                           
#define DFSDM_CHANNEL_SINC2_ORDER    DFSDM_CHAWSCDR_AWFORD_1                           
#define DFSDM_CHANNEL_SINC3_ORDER    DFSDM_CHAWSCDR_AWFORD                             
   
      
    

                                                                  
      
    
#define DFSDM_FILTER_SW_TRIGGER   0x00000000U                         
#define DFSDM_FILTER_SYNC_TRIGGER 0x00000001U                                    
#define DFSDM_FILTER_EXT_TRIGGER  0x00000002U                                                        
   
      
    

                                                                   
      
    
#if defined(STM32L451xx) || defined(STM32L452xx) || defined(STM32L462xx)
#define DFSDM_FILTER_EXT_TRIG_TIM1_TRGO  0x00000000U                                                                             
#define DFSDM_FILTER_EXT_TRIG_TIM1_TRGO2 DFSDM_FLTCR1_JEXTSEL_0                                                                  
#define DFSDM_FILTER_EXT_TRIG_TIM3_TRGO  DFSDM_FLTCR1_JEXTSEL_1                                                                  
#define DFSDM_FILTER_EXT_TRIG_TIM16_OC1  (DFSDM_FLTCR1_JEXTSEL_0 | DFSDM_FLTCR1_JEXTSEL_1)                                    
#define DFSDM_FILTER_EXT_TRIG_TIM6_TRGO  (DFSDM_FLTCR1_JEXTSEL_0 | DFSDM_FLTCR1_JEXTSEL_2)                                 
#define DFSDM_FILTER_EXT_TRIG_EXTI11     (DFSDM_FLTCR1_JEXTSEL_1 | DFSDM_FLTCR1_JEXTSEL_2)                                       
#define DFSDM_FILTER_EXT_TRIG_EXTI15     DFSDM_FLTCR1_JEXTSEL                                                                    
#elif defined(STM32L4R5xx) || defined(STM32L4R7xx) || defined(STM32L4R9xx) || defined(STM32L4S5xx) || defined(STM32L4S7xx) || defined(STM32L4S9xx) || \
      defined(STM32L4P5xx) || defined(STM32L4Q5xx)
#define DFSDM_FILTER_EXT_TRIG_TIM1_TRGO  0x00000000U                                                                    
#define DFSDM_FILTER_EXT_TRIG_TIM1_TRGO2 DFSDM_FLTCR1_JEXTSEL_0                                                         
#define DFSDM_FILTER_EXT_TRIG_TIM8_TRGO  DFSDM_FLTCR1_JEXTSEL_1                                                         
#define DFSDM_FILTER_EXT_TRIG_TIM8_TRGO2 (DFSDM_FLTCR1_JEXTSEL_0 | DFSDM_FLTCR1_JEXTSEL_1)                              
#define DFSDM_FILTER_EXT_TRIG_TIM3_TRGO  DFSDM_FLTCR1_JEXTSEL_2                                                         
#define DFSDM_FILTER_EXT_TRIG_TIM4_TRGO  (DFSDM_FLTCR1_JEXTSEL_0 | DFSDM_FLTCR1_JEXTSEL_2)                              
#define DFSDM_FILTER_EXT_TRIG_TIM16_OC1  (DFSDM_FLTCR1_JEXTSEL_1 | DFSDM_FLTCR1_JEXTSEL_2)                              
#define DFSDM_FILTER_EXT_TRIG_TIM6_TRGO  (DFSDM_FLTCR1_JEXTSEL_0 | DFSDM_FLTCR1_JEXTSEL_1 | \
                                          DFSDM_FLTCR1_JEXTSEL_2)                                                       
#define DFSDM_FILTER_EXT_TRIG_TIM7_TRGO  DFSDM_FLTCR1_JEXTSEL_3                                                         
#define DFSDM_FILTER_EXT_TRIG_EXTI11     (DFSDM_FLTCR1_JEXTSEL_3 | DFSDM_FLTCR1_JEXTSEL_4)                              
#define DFSDM_FILTER_EXT_TRIG_EXTI15     (DFSDM_FLTCR1_JEXTSEL_0 | DFSDM_FLTCR1_JEXTSEL_3 | \
                                          DFSDM_FLTCR1_JEXTSEL_4)                                                       
#define DFSDM_FILTER_EXT_TRIG_LPTIM1_OUT (DFSDM_FLTCR1_JEXTSEL_1 | DFSDM_FLTCR1_JEXTSEL_3 | \
                                          DFSDM_FLTCR1_JEXTSEL_4)                                                       
#else
#define DFSDM_FILTER_EXT_TRIG_TIM1_TRGO  0x00000000U                                                                             
#define DFSDM_FILTER_EXT_TRIG_TIM1_TRGO2 DFSDM_FLTCR1_JEXTSEL_0                                                                  
#define DFSDM_FILTER_EXT_TRIG_TIM8_TRGO  DFSDM_FLTCR1_JEXTSEL_1                                                                  
#define DFSDM_FILTER_EXT_TRIG_TIM8_TRGO2 (DFSDM_FLTCR1_JEXTSEL_0 | DFSDM_FLTCR1_JEXTSEL_1)                                    
#define DFSDM_FILTER_EXT_TRIG_TIM3_TRGO  (DFSDM_FLTCR1_JEXTSEL_0 | DFSDM_FLTCR1_JEXTSEL_1)                           
#define DFSDM_FILTER_EXT_TRIG_TIM4_TRGO  DFSDM_FLTCR1_JEXTSEL_2                                                               
#define DFSDM_FILTER_EXT_TRIG_TIM16_OC1  DFSDM_FLTCR1_JEXTSEL_2                                                      
#define DFSDM_FILTER_EXT_TRIG_TIM6_TRGO  (DFSDM_FLTCR1_JEXTSEL_0 | DFSDM_FLTCR1_JEXTSEL_2)                                 
#define DFSDM_FILTER_EXT_TRIG_TIM7_TRGO  (DFSDM_FLTCR1_JEXTSEL_0 | DFSDM_FLTCR1_JEXTSEL_2)                                 
#define DFSDM_FILTER_EXT_TRIG_EXTI11     (DFSDM_FLTCR1_JEXTSEL_1 | DFSDM_FLTCR1_JEXTSEL_2)                                       
#define DFSDM_FILTER_EXT_TRIG_EXTI15     DFSDM_FLTCR1_JEXTSEL                                                                    
#endif                                                
   
      
    

                                                                            
      
    
#define DFSDM_FILTER_EXT_TRIG_RISING_EDGE  DFSDM_FLTCR1_JEXTEN_0                             
#define DFSDM_FILTER_EXT_TRIG_FALLING_EDGE DFSDM_FLTCR1_JEXTEN_1                              
#define DFSDM_FILTER_EXT_TRIG_BOTH_EDGES   DFSDM_FLTCR1_JEXTEN                                            
   
      
    

                                                            
      
    
#define DFSDM_FILTER_FASTSINC_ORDER 0x00000000U                                                             
#define DFSDM_FILTER_SINC1_ORDER    DFSDM_FLTFCR_FORD_0                                                   
#define DFSDM_FILTER_SINC2_ORDER    DFSDM_FLTFCR_FORD_1                                                   
#define DFSDM_FILTER_SINC3_ORDER    (DFSDM_FLTFCR_FORD_0 | DFSDM_FLTFCR_FORD_1)                           
#define DFSDM_FILTER_SINC4_ORDER    DFSDM_FLTFCR_FORD_2                                                   
#define DFSDM_FILTER_SINC5_ORDER    (DFSDM_FLTFCR_FORD_0 | DFSDM_FLTFCR_FORD_2)                           
   
      
    

                                                                                 
      
    
#define DFSDM_FILTER_AWD_FILTER_DATA  0x00000000U                                        
#define DFSDM_FILTER_AWD_CHANNEL_DATA DFSDM_FLTCR1_AWFSEL                                         
   
      
    

                                                            
      
    
#define DFSDM_FILTER_ERROR_NONE             0x00000000U                 
#define DFSDM_FILTER_ERROR_REGULAR_OVERRUN  0x00000001U                                                 
#define DFSDM_FILTER_ERROR_INJECTED_OVERRUN 0x00000002U                                                  
#define DFSDM_FILTER_ERROR_DMA              0x00000003U                         
#if (USE_HAL_DFSDM_REGISTER_CALLBACKS == 1)
#define DFSDM_FILTER_ERROR_INVALID_CALLBACK 0x00000004U                                      
#endif
   
      
    

                                                    
      
    
#define DFSDM_NO_BREAK_SIGNAL 0x00000000U                        
#define DFSDM_BREAK_SIGNAL_0  0x00000001U                       
#define DFSDM_BREAK_SIGNAL_1  0x00000002U                       
#define DFSDM_BREAK_SIGNAL_2  0x00000004U                       
#define DFSDM_BREAK_SIGNAL_3  0x00000008U                       
   
      
    

                                                             
      
    
                                                                                
                                             
                                          
                                            
                                 
                                                       
                                            
                                                                                         
#if defined(STM32L451xx) || defined(STM32L452xx) || defined(STM32L462xx) || \
    defined(STM32L4P5xx) || defined(STM32L4Q5xx)
#define DFSDM_CHANNEL_0                              0x00000001U
#define DFSDM_CHANNEL_1                              0x00010002U
#define DFSDM_CHANNEL_2                              0x00020004U
#define DFSDM_CHANNEL_3                              0x00030008U
#else
#define DFSDM_CHANNEL_0                              0x00000001U
#define DFSDM_CHANNEL_1                              0x00010002U
#define DFSDM_CHANNEL_2                              0x00020004U
#define DFSDM_CHANNEL_3                              0x00030008U
#define DFSDM_CHANNEL_4                              0x00040010U
#define DFSDM_CHANNEL_5                              0x00050020U
#define DFSDM_CHANNEL_6                              0x00060040U
#define DFSDM_CHANNEL_7                              0x00070080U
#endif                                                                              
   
      
    

                                                        
      
    
#define DFSDM_CONTINUOUS_CONV_OFF            0x00000000U                                      
#define DFSDM_CONTINUOUS_CONV_ON             0x00000001U                                  
   
      
    

                                                                
      
    
#define DFSDM_AWD_HIGH_THRESHOLD            0x00000000U                                       
#define DFSDM_AWD_LOW_THRESHOLD             0x00000001U                                      
   
      
    

   
      
    
                                                                                

                                                                                
                                                         
     
   

                                             
                                            
                
    
#if (USE_HAL_DFSDM_REGISTER_CALLBACKS == 1)
#define __HAL_DFSDM_CHANNEL_RESET_HANDLE_STATE(__HANDLE__) do{                                                      \
                                                               (__HANDLE__)->State = HAL_DFSDM_CHANNEL_STATE_RESET; \
                                                               (__HANDLE__)->MspInitCallback = NULL;                \
                                                               (__HANDLE__)->MspDeInitCallback = NULL;              \
                                                             } while(0)
#else
#define __HAL_DFSDM_CHANNEL_RESET_HANDLE_STATE(__HANDLE__) ((__HANDLE__)->State = HAL_DFSDM_CHANNEL_STATE_RESET)
#endif

                                            
                                           
                
    
#if (USE_HAL_DFSDM_REGISTER_CALLBACKS == 1)
#define __HAL_DFSDM_FILTER_RESET_HANDLE_STATE(__HANDLE__) do{                                                     \
                                                              (__HANDLE__)->State = HAL_DFSDM_FILTER_STATE_RESET; \
                                                              (__HANDLE__)->MspInitCallback = NULL;               \
                                                              (__HANDLE__)->MspDeInitCallback = NULL;             \
                                                            } while(0)
#else
#define __HAL_DFSDM_FILTER_RESET_HANDLE_STATE(__HANDLE__) ((__HANDLE__)->State = HAL_DFSDM_FILTER_STATE_RESET)
#endif

   
      
    
                                                                                

#if defined(STM32L4R5xx) || defined(STM32L4R7xx) || defined(STM32L4R9xx) || defined(STM32L4S5xx) || defined(STM32L4S7xx) || defined(STM32L4S9xx) || \
    defined(STM32L4P5xx) || defined(STM32L4Q5xx)
                                        
#include "stm32l4xx_hal_dfsdm_ex.h"
#endif                                                                                                                           

                                                                                
                                                                 
      
    

                                                                                                              
      
    
                                                                                
HAL_StatusTypeDef HAL_DFSDM_ChannelInit(DFSDM_Channel_HandleTypeDef *hdfsdm_channel);
HAL_StatusTypeDef HAL_DFSDM_ChannelDeInit(DFSDM_Channel_HandleTypeDef *hdfsdm_channel);
void HAL_DFSDM_ChannelMspInit(DFSDM_Channel_HandleTypeDef *hdfsdm_channel);
void HAL_DFSDM_ChannelMspDeInit(DFSDM_Channel_HandleTypeDef *hdfsdm_channel);

#if (USE_HAL_DFSDM_REGISTER_CALLBACKS == 1)
                                                                                
HAL_StatusTypeDef HAL_DFSDM_Channel_RegisterCallback(DFSDM_Channel_HandleTypeDef        *hdfsdm_channel,
                                                     HAL_DFSDM_Channel_CallbackIDTypeDef CallbackID,
                                                     pDFSDM_Channel_CallbackTypeDef      pCallback);
HAL_StatusTypeDef HAL_DFSDM_Channel_UnRegisterCallback(DFSDM_Channel_HandleTypeDef        *hdfsdm_channel,
                                                       HAL_DFSDM_Channel_CallbackIDTypeDef CallbackID);
#endif
   
      
    

                                                                                   
      
    
                                                                                
HAL_StatusTypeDef HAL_DFSDM_ChannelCkabStart(DFSDM_Channel_HandleTypeDef *hdfsdm_channel);
HAL_StatusTypeDef HAL_DFSDM_ChannelCkabStart_IT(DFSDM_Channel_HandleTypeDef *hdfsdm_channel);
HAL_StatusTypeDef HAL_DFSDM_ChannelCkabStop(DFSDM_Channel_HandleTypeDef *hdfsdm_channel);
HAL_StatusTypeDef HAL_DFSDM_ChannelCkabStop_IT(DFSDM_Channel_HandleTypeDef *hdfsdm_channel);

HAL_StatusTypeDef HAL_DFSDM_ChannelScdStart(DFSDM_Channel_HandleTypeDef *hdfsdm_channel, uint32_t Threshold, uint32_t BreakSignal);
HAL_StatusTypeDef HAL_DFSDM_ChannelScdStart_IT(DFSDM_Channel_HandleTypeDef *hdfsdm_channel, uint32_t Threshold, uint32_t BreakSignal);
HAL_StatusTypeDef HAL_DFSDM_ChannelScdStop(DFSDM_Channel_HandleTypeDef *hdfsdm_channel);
HAL_StatusTypeDef HAL_DFSDM_ChannelScdStop_IT(DFSDM_Channel_HandleTypeDef *hdfsdm_channel);

int16_t           HAL_DFSDM_ChannelGetAwdValue(const DFSDM_Channel_HandleTypeDef *hdfsdm_channel);
HAL_StatusTypeDef HAL_DFSDM_ChannelModifyOffset(DFSDM_Channel_HandleTypeDef *hdfsdm_channel, int32_t Offset);

HAL_StatusTypeDef HAL_DFSDM_ChannelPollForCkab(const DFSDM_Channel_HandleTypeDef *hdfsdm_channel, uint32_t Timeout);
HAL_StatusTypeDef HAL_DFSDM_ChannelPollForScd(const DFSDM_Channel_HandleTypeDef *hdfsdm_channel, uint32_t Timeout);

void HAL_DFSDM_ChannelCkabCallback(DFSDM_Channel_HandleTypeDef *hdfsdm_channel);
void HAL_DFSDM_ChannelScdCallback(DFSDM_Channel_HandleTypeDef *hdfsdm_channel);
   
      
    

                                                                            
      
    
                                                                                
HAL_DFSDM_Channel_StateTypeDef HAL_DFSDM_ChannelGetState(const DFSDM_Channel_HandleTypeDef *hdfsdm_channel);
   
      
    

                                                                                                            
      
    
                                                                               
HAL_StatusTypeDef HAL_DFSDM_FilterInit(DFSDM_Filter_HandleTypeDef *hdfsdm_filter);
HAL_StatusTypeDef HAL_DFSDM_FilterDeInit(DFSDM_Filter_HandleTypeDef *hdfsdm_filter);
void HAL_DFSDM_FilterMspInit(DFSDM_Filter_HandleTypeDef *hdfsdm_filter);
void HAL_DFSDM_FilterMspDeInit(DFSDM_Filter_HandleTypeDef *hdfsdm_filter);

#if (USE_HAL_DFSDM_REGISTER_CALLBACKS == 1)
                                                                               
HAL_StatusTypeDef HAL_DFSDM_Filter_RegisterCallback(DFSDM_Filter_HandleTypeDef        *hdfsdm_filter,
                                                    HAL_DFSDM_Filter_CallbackIDTypeDef CallbackID,
                                                    pDFSDM_Filter_CallbackTypeDef      pCallback);
HAL_StatusTypeDef HAL_DFSDM_Filter_UnRegisterCallback(DFSDM_Filter_HandleTypeDef        *hdfsdm_filter,
                                                      HAL_DFSDM_Filter_CallbackIDTypeDef CallbackID);
HAL_StatusTypeDef HAL_DFSDM_Filter_RegisterAwdCallback(DFSDM_Filter_HandleTypeDef      *hdfsdm_filter,
                                                       pDFSDM_Filter_AwdCallbackTypeDef pCallback);
HAL_StatusTypeDef HAL_DFSDM_Filter_UnRegisterAwdCallback(DFSDM_Filter_HandleTypeDef *hdfsdm_filter);
#endif
   
      
    

                                                                               
      
    
                                                  
HAL_StatusTypeDef HAL_DFSDM_FilterConfigRegChannel(DFSDM_Filter_HandleTypeDef *hdfsdm_filter,
                                                   uint32_t                    Channel,
                                                   uint32_t                    ContinuousMode);
HAL_StatusTypeDef HAL_DFSDM_FilterConfigInjChannel(DFSDM_Filter_HandleTypeDef *hdfsdm_filter,
                                                   uint32_t                    Channel);
   
      
    

                                                                                 
      
    
                                                    
HAL_StatusTypeDef HAL_DFSDM_FilterRegularStart(DFSDM_Filter_HandleTypeDef *hdfsdm_filter);
HAL_StatusTypeDef HAL_DFSDM_FilterRegularStart_IT(DFSDM_Filter_HandleTypeDef *hdfsdm_filter);
HAL_StatusTypeDef HAL_DFSDM_FilterRegularStart_DMA(DFSDM_Filter_HandleTypeDef *hdfsdm_filter, int32_t *pData, uint32_t Length);
HAL_StatusTypeDef HAL_DFSDM_FilterRegularMsbStart_DMA(DFSDM_Filter_HandleTypeDef *hdfsdm_filter, int16_t *pData, uint32_t Length);
HAL_StatusTypeDef HAL_DFSDM_FilterRegularStop(DFSDM_Filter_HandleTypeDef *hdfsdm_filter);
HAL_StatusTypeDef HAL_DFSDM_FilterRegularStop_IT(DFSDM_Filter_HandleTypeDef *hdfsdm_filter);
HAL_StatusTypeDef HAL_DFSDM_FilterRegularStop_DMA(DFSDM_Filter_HandleTypeDef *hdfsdm_filter);
HAL_StatusTypeDef HAL_DFSDM_FilterInjectedStart(DFSDM_Filter_HandleTypeDef *hdfsdm_filter);
HAL_StatusTypeDef HAL_DFSDM_FilterInjectedStart_IT(DFSDM_Filter_HandleTypeDef *hdfsdm_filter);
HAL_StatusTypeDef HAL_DFSDM_FilterInjectedStart_DMA(DFSDM_Filter_HandleTypeDef *hdfsdm_filter, int32_t *pData, uint32_t Length);
HAL_StatusTypeDef HAL_DFSDM_FilterInjectedMsbStart_DMA(DFSDM_Filter_HandleTypeDef *hdfsdm_filter, int16_t *pData, uint32_t Length);
HAL_StatusTypeDef HAL_DFSDM_FilterInjectedStop(DFSDM_Filter_HandleTypeDef *hdfsdm_filter);
HAL_StatusTypeDef HAL_DFSDM_FilterInjectedStop_IT(DFSDM_Filter_HandleTypeDef *hdfsdm_filter);
HAL_StatusTypeDef HAL_DFSDM_FilterInjectedStop_DMA(DFSDM_Filter_HandleTypeDef *hdfsdm_filter);
HAL_StatusTypeDef HAL_DFSDM_FilterAwdStart_IT(DFSDM_Filter_HandleTypeDef *hdfsdm_filter,
                                              const DFSDM_Filter_AwdParamTypeDef *awdParam);
HAL_StatusTypeDef HAL_DFSDM_FilterAwdStop_IT(DFSDM_Filter_HandleTypeDef *hdfsdm_filter);
HAL_StatusTypeDef HAL_DFSDM_FilterExdStart(DFSDM_Filter_HandleTypeDef *hdfsdm_filter, uint32_t Channel);
HAL_StatusTypeDef HAL_DFSDM_FilterExdStop(DFSDM_Filter_HandleTypeDef *hdfsdm_filter);

int32_t  HAL_DFSDM_FilterGetRegularValue(const DFSDM_Filter_HandleTypeDef *hdfsdm_filter, uint32_t *Channel);
int32_t  HAL_DFSDM_FilterGetInjectedValue(const DFSDM_Filter_HandleTypeDef *hdfsdm_filter, uint32_t *Channel);
int32_t  HAL_DFSDM_FilterGetExdMaxValue(const DFSDM_Filter_HandleTypeDef *hdfsdm_filter, uint32_t *Channel);
int32_t  HAL_DFSDM_FilterGetExdMinValue(const DFSDM_Filter_HandleTypeDef *hdfsdm_filter, uint32_t *Channel);
uint32_t HAL_DFSDM_FilterGetConvTimeValue(const DFSDM_Filter_HandleTypeDef *hdfsdm_filter);

void HAL_DFSDM_IRQHandler(DFSDM_Filter_HandleTypeDef *hdfsdm_filter);

HAL_StatusTypeDef HAL_DFSDM_FilterPollForRegConversion(DFSDM_Filter_HandleTypeDef *hdfsdm_filter, uint32_t Timeout);
HAL_StatusTypeDef HAL_DFSDM_FilterPollForInjConversion(DFSDM_Filter_HandleTypeDef *hdfsdm_filter, uint32_t Timeout);

void HAL_DFSDM_FilterRegConvCpltCallback(DFSDM_Filter_HandleTypeDef *hdfsdm_filter);
void HAL_DFSDM_FilterRegConvHalfCpltCallback(DFSDM_Filter_HandleTypeDef *hdfsdm_filter);
void HAL_DFSDM_FilterInjConvCpltCallback(DFSDM_Filter_HandleTypeDef *hdfsdm_filter);
void HAL_DFSDM_FilterInjConvHalfCpltCallback(DFSDM_Filter_HandleTypeDef *hdfsdm_filter);
void HAL_DFSDM_FilterAwdCallback(DFSDM_Filter_HandleTypeDef *hdfsdm_filter, uint32_t Channel, uint32_t Threshold);
void HAL_DFSDM_FilterErrorCallback(DFSDM_Filter_HandleTypeDef *hdfsdm_filter);
   
      
    

                                                                           
      
    
                                                                                
HAL_DFSDM_Filter_StateTypeDef HAL_DFSDM_FilterGetState(const DFSDM_Filter_HandleTypeDef *hdfsdm_filter);
uint32_t                      HAL_DFSDM_FilterGetError(const DFSDM_Filter_HandleTypeDef *hdfsdm_filter);
   
      
    

   
      
    
                                                                                

                                                                                
                                                       
    
  
#define IS_DFSDM_CHANNEL_OUTPUT_CLOCK(CLOCK)          (((CLOCK) == DFSDM_CHANNEL_OUTPUT_CLOCK_SYSTEM) || \
                                                       ((CLOCK) == DFSDM_CHANNEL_OUTPUT_CLOCK_AUDIO))
#define IS_DFSDM_CHANNEL_OUTPUT_CLOCK_DIVIDER(DIVIDER) ((2U <= (DIVIDER)) && ((DIVIDER) <= 256U))
#if defined(STM32L451xx) || defined(STM32L452xx) || defined(STM32L462xx) || \
    defined(STM32L496xx) || defined(STM32L4A6xx) || \
    defined(STM32L4R5xx) || defined(STM32L4R7xx) || defined(STM32L4R9xx) || defined(STM32L4S5xx) || defined(STM32L4S7xx) || defined(STM32L4S9xx) || \
    defined(STM32L4P5xx) || defined(STM32L4Q5xx)
#define IS_DFSDM_CHANNEL_INPUT(INPUT)                 (((INPUT) == DFSDM_CHANNEL_EXTERNAL_INPUTS) || \
                                                       ((INPUT) == DFSDM_CHANNEL_ADC_OUTPUT) || \
                                                       ((INPUT) == DFSDM_CHANNEL_INTERNAL_REGISTER))
#else
#define IS_DFSDM_CHANNEL_INPUT(INPUT)                 (((INPUT) == DFSDM_CHANNEL_EXTERNAL_INPUTS) || \
                                                       ((INPUT) == DFSDM_CHANNEL_INTERNAL_REGISTER))
#endif                                                   
                                   
                                                                                               
                                   
#define IS_DFSDM_CHANNEL_DATA_PACKING(MODE)           (((MODE) == DFSDM_CHANNEL_STANDARD_MODE) || \
                                                       ((MODE) == DFSDM_CHANNEL_INTERLEAVED_MODE) || \
                                                       ((MODE) == DFSDM_CHANNEL_DUAL_MODE))
#define IS_DFSDM_CHANNEL_INPUT_PINS(PINS)             (((PINS) == DFSDM_CHANNEL_SAME_CHANNEL_PINS) || \
                                                       ((PINS) == DFSDM_CHANNEL_FOLLOWING_CHANNEL_PINS))
#define IS_DFSDM_CHANNEL_SERIAL_INTERFACE_TYPE(MODE)  (((MODE) == DFSDM_CHANNEL_SPI_RISING) || \
                                                       ((MODE) == DFSDM_CHANNEL_SPI_FALLING) || \
                                                       ((MODE) == DFSDM_CHANNEL_MANCHESTER_RISING) || \
                                                       ((MODE) == DFSDM_CHANNEL_MANCHESTER_FALLING))
#define IS_DFSDM_CHANNEL_SPI_CLOCK(TYPE)              (((TYPE) == DFSDM_CHANNEL_SPI_CLOCK_EXTERNAL) || \
                                                       ((TYPE) == DFSDM_CHANNEL_SPI_CLOCK_INTERNAL) || \
                                                       ((TYPE) == DFSDM_CHANNEL_SPI_CLOCK_INTERNAL_DIV2_FALLING) || \
                                                       ((TYPE) == DFSDM_CHANNEL_SPI_CLOCK_INTERNAL_DIV2_RISING))
#define IS_DFSDM_CHANNEL_FILTER_ORDER(ORDER)          (((ORDER) == DFSDM_CHANNEL_FASTSINC_ORDER) || \
                                                       ((ORDER) == DFSDM_CHANNEL_SINC1_ORDER) || \
                                                       ((ORDER) == DFSDM_CHANNEL_SINC2_ORDER) || \
                                                       ((ORDER) == DFSDM_CHANNEL_SINC3_ORDER))
#define IS_DFSDM_CHANNEL_FILTER_OVS_RATIO(RATIO)       ((1U <= (RATIO)) && ((RATIO) <= 32U))
#define IS_DFSDM_CHANNEL_OFFSET(VALUE)                 ((-8388608 <= (VALUE)) && ((VALUE) <= 8388607))
#define IS_DFSDM_CHANNEL_RIGHT_BIT_SHIFT(VALUE)        ((VALUE) <= 0x1FU)
#define IS_DFSDM_CHANNEL_SCD_THRESHOLD(VALUE)          ((VALUE) <= 0xFFU)
#define IS_DFSDM_FILTER_REG_TRIGGER(TRIG)             (((TRIG) == DFSDM_FILTER_SW_TRIGGER) || \
                                                       ((TRIG) == DFSDM_FILTER_SYNC_TRIGGER))
#define IS_DFSDM_FILTER_INJ_TRIGGER(TRIG)             (((TRIG) == DFSDM_FILTER_SW_TRIGGER) || \
                                                       ((TRIG) == DFSDM_FILTER_SYNC_TRIGGER) || \
                                                       ((TRIG) == DFSDM_FILTER_EXT_TRIGGER))
#if defined(STM32L451xx) || defined(STM32L452xx) || defined(STM32L462xx)
#define IS_DFSDM_FILTER_EXT_TRIG(TRIG)                (((TRIG) == DFSDM_FILTER_EXT_TRIG_TIM1_TRGO) || \
                                                       ((TRIG) == DFSDM_FILTER_EXT_TRIG_TIM1_TRGO2) || \
                                                       ((TRIG) == DFSDM_FILTER_EXT_TRIG_TIM3_TRGO) || \
                                                       ((TRIG) == DFSDM_FILTER_EXT_TRIG_TIM16_OC1) || \
                                                       ((TRIG) == DFSDM_FILTER_EXT_TRIG_TIM6_TRGO) || \
                                                       ((TRIG) == DFSDM_FILTER_EXT_TRIG_EXTI11) || \
                                                       ((TRIG) == DFSDM_FILTER_EXT_TRIG_EXTI15))
#elif defined(STM32L4R5xx) || defined(STM32L4R7xx) || defined(STM32L4R9xx) || defined(STM32L4S5xx) || defined(STM32L4S7xx) || defined(STM32L4S9xx) || \
      defined(STM32L4P5xx) || defined(STM32L4Q5xx)
#define IS_DFSDM_FILTER_EXT_TRIG(TRIG)                (((TRIG) == DFSDM_FILTER_EXT_TRIG_TIM1_TRGO) || \
                                                       ((TRIG) == DFSDM_FILTER_EXT_TRIG_TIM1_TRGO2) || \
                                                       ((TRIG) == DFSDM_FILTER_EXT_TRIG_TIM8_TRGO) || \
                                                       ((TRIG) == DFSDM_FILTER_EXT_TRIG_TIM8_TRGO2) || \
                                                       ((TRIG) == DFSDM_FILTER_EXT_TRIG_TIM3_TRGO) || \
                                                       ((TRIG) == DFSDM_FILTER_EXT_TRIG_TIM4_TRGO) || \
                                                       ((TRIG) == DFSDM_FILTER_EXT_TRIG_TIM16_OC1) || \
                                                       ((TRIG) == DFSDM_FILTER_EXT_TRIG_TIM6_TRGO) || \
                                                       ((TRIG) == DFSDM_FILTER_EXT_TRIG_TIM7_TRGO) || \
                                                       ((TRIG) == DFSDM_FILTER_EXT_TRIG_EXTI11) || \
                                                       ((TRIG) == DFSDM_FILTER_EXT_TRIG_EXTI15) || \
                                                       ((TRIG) == DFSDM_FILTER_EXT_TRIG_LPTIM1_OUT))
#else
#define IS_DFSDM_FILTER_EXT_TRIG(TRIG)                (((TRIG) == DFSDM_FILTER_EXT_TRIG_TIM1_TRGO) || \
                                                       ((TRIG) == DFSDM_FILTER_EXT_TRIG_TIM1_TRGO2) || \
                                                       ((TRIG) == DFSDM_FILTER_EXT_TRIG_TIM8_TRGO) || \
                                                       ((TRIG) == DFSDM_FILTER_EXT_TRIG_TIM8_TRGO2) || \
                                                       ((TRIG) == DFSDM_FILTER_EXT_TRIG_TIM3_TRGO) || \
                                                       ((TRIG) == DFSDM_FILTER_EXT_TRIG_TIM4_TRGO) || \
                                                       ((TRIG) == DFSDM_FILTER_EXT_TRIG_TIM16_OC1) || \
                                                       ((TRIG) == DFSDM_FILTER_EXT_TRIG_TIM6_TRGO) || \
                                                       ((TRIG) == DFSDM_FILTER_EXT_TRIG_TIM7_TRGO) || \
                                                       ((TRIG) == DFSDM_FILTER_EXT_TRIG_EXTI11) || \
                                                       ((TRIG) == DFSDM_FILTER_EXT_TRIG_EXTI15))
#endif                                                
#define IS_DFSDM_FILTER_EXT_TRIG_EDGE(EDGE)           (((EDGE) == DFSDM_FILTER_EXT_TRIG_RISING_EDGE)  || \
                                                       ((EDGE) == DFSDM_FILTER_EXT_TRIG_FALLING_EDGE)  || \
                                                       ((EDGE) == DFSDM_FILTER_EXT_TRIG_BOTH_EDGES))
#define IS_DFSDM_FILTER_SINC_ORDER(ORDER)             (((ORDER) == DFSDM_FILTER_FASTSINC_ORDER) || \
                                                       ((ORDER) == DFSDM_FILTER_SINC1_ORDER) || \
                                                       ((ORDER) == DFSDM_FILTER_SINC2_ORDER) || \
                                                       ((ORDER) == DFSDM_FILTER_SINC3_ORDER) || \
                                                       ((ORDER) == DFSDM_FILTER_SINC4_ORDER) || \
                                                       ((ORDER) == DFSDM_FILTER_SINC5_ORDER))
#define IS_DFSDM_FILTER_OVS_RATIO(RATIO)               ((1U <= (RATIO)) && ((RATIO) <= 1024U))
#define IS_DFSDM_FILTER_INTEGRATOR_OVS_RATIO(RATIO)    ((1U <= (RATIO)) && ((RATIO) <= 256U))
#define IS_DFSDM_FILTER_AWD_DATA_SOURCE(DATA)         (((DATA) == DFSDM_FILTER_AWD_FILTER_DATA)  || \
                                                       ((DATA) == DFSDM_FILTER_AWD_CHANNEL_DATA))
#define IS_DFSDM_FILTER_AWD_THRESHOLD(VALUE)           ((-8388608 <= (VALUE)) && ((VALUE) <= 8388607))
#define IS_DFSDM_BREAK_SIGNALS(VALUE)                  ((VALUE) <= 0xFU)
#if defined(STM32L451xx) || defined(STM32L452xx) || defined(STM32L462xx) || \
    defined(STM32L4P5xx) || defined(STM32L4Q5xx)
#define IS_DFSDM_REGULAR_CHANNEL(CHANNEL)             (((CHANNEL) == DFSDM_CHANNEL_0)  || \
                                                       ((CHANNEL) == DFSDM_CHANNEL_1)  || \
                                                       ((CHANNEL) == DFSDM_CHANNEL_2)  || \
                                                       ((CHANNEL) == DFSDM_CHANNEL_3))
#define IS_DFSDM_INJECTED_CHANNEL(CHANNEL)            (((CHANNEL) != 0U) && ((CHANNEL) <= 0x0003000FU))
#else
#define IS_DFSDM_REGULAR_CHANNEL(CHANNEL)             (((CHANNEL) == DFSDM_CHANNEL_0)  || \
                                                       ((CHANNEL) == DFSDM_CHANNEL_1)  || \
                                                       ((CHANNEL) == DFSDM_CHANNEL_2)  || \
                                                       ((CHANNEL) == DFSDM_CHANNEL_3)  || \
                                                       ((CHANNEL) == DFSDM_CHANNEL_4)  || \
                                                       ((CHANNEL) == DFSDM_CHANNEL_5)  || \
                                                       ((CHANNEL) == DFSDM_CHANNEL_6)  || \
                                                       ((CHANNEL) == DFSDM_CHANNEL_7))
#define IS_DFSDM_INJECTED_CHANNEL(CHANNEL)            (((CHANNEL) != 0U) && ((CHANNEL) <= 0x000F00FFU))
#endif                                                                              
#define IS_DFSDM_CONTINUOUS_MODE(MODE)                (((MODE) == DFSDM_CONTINUOUS_CONV_OFF)  || \
                                                       ((MODE) == DFSDM_CONTINUOUS_CONV_ON))
   
      
    
                                                                                

   
      
    

   
      
    
#endif                                                   
                                                                                
                                   
                                                                                               
                                

#ifdef __cplusplus
}
#endif

#endif                            
