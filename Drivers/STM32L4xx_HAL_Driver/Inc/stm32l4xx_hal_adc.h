/**
  ******************************************************************************
  * @file    stm32l4xx_hal_adc.h
  * @author  MCD Application Team
  * @brief   Header file of ADC HAL module.
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

                                                                                
#ifndef STM32L4xx_HAL_ADC_H
#define STM32L4xx_HAL_ADC_H

#ifdef __cplusplus
extern "C" {
#endif

                                                                                
#include "stm32l4xx_hal_def.h"

                              
#include "stm32l4xx_ll_adc.h"

                                    
      
    

                   
      
    

                                                                                
                                                   
      
    

   
                                                               
    
typedef struct
{
  uint32_t Ratio;                                                                
                                                                                                            

  uint32_t RightBitShift;                                                                              
                                                                                                            

  uint32_t TriggeredMode;                                                                      
                                                                                                                   

  uint32_t OversamplingStopReset;                                                    
                                                                                                                     
                                                                     
                                                                                                                   
                                                                                           
                                                                                                                    
                                                                          
                                                                                                                

} ADC_OversamplingTypeDef;

   
                                                                       
                                                                    
                                                                                                                 
                                                            
                                                                                                                        
                                                                                                                      
                                                                                                   
                                    
                                               
                                                                                                                    
                                                            
                                                                                                                     
                                              
                                                                                                                  
                                                                                                                    
                                                                           
    
typedef struct
{
  uint32_t ClockPrescaler;                                                                                              
                                                                                                                    
                                                                              
                                                                                                            
                                                                                                        
                                                                                                                    
                                                                                                            
                                                                                                     
                                                                                                     
                                                                                                                      
                                                                                                                
                                                                                                                       
                                                                                                    
                                                                                                               
                                                                                    
                                                                                                                      

  uint32_t Resolution;                                              
                                                                                                     

  uint32_t DataAlign;                                                                                         
                                                                                                           
                                                                                                     

  uint32_t ScanConvMode;                                                                          
                                                                                                                    
                                                                                    
                                                                                                                      
                                                                                                            
                                                                                                                     
                                                                                                                      
                                                                                                                      
                                                                                                                   
                                                             
                                                                                             

  uint32_t EOCSelection;                                                                                               
                                                                                                              
                                                                                                 

  FunctionalState LowPowerAutoWait;                                                                                 
                                                                                                                      
                                                                                                                       
                                                                       
                                                                                                                     
                                                                                                                 
                                                                              
                                                                                      
                                                                                                                       
                                                                                                                     
                                                                                                   
                                                                                                                    
                                                                                                                     
                                                                             
                                                                                                                        
                                                                                
                                                                                                                       
                                                                                                              
                                                                                                               
                                                                                            
                                                                                   

  FunctionalState ContinuousConvMode;                                                                                 
                                                                                                                   
                                                                                                                      
                                                                              

  uint32_t NbrOfConversion;                                                                                       
                                                 
                                                                                   
                                                                                     
                                                                                                                    
                                                                                                                    
                                                                                                                        
                                                                                                              
                                                                                                                   
                                                                                                                        
                                                                                         
                                                                                                                      
                                                                                    
                                                                                                             
                                                                                                                      
                                                                                                                    
                                                                                        

  FunctionalState DiscontinuousConvMode;                                                                                
                                                                                                                      
                                                                
                                                                                                                
                                                                                                                     
                                                                                                                    
                                                                                                                 
                                                                                             
                                                                                                                   
                                                                                              

  uint32_t NbrOfDiscConversion;                                                                                    
                                                                                                           
                                                                                                                     
                                                                                                                

  uint32_t ExternalTrigConv;                                                                                        
                                             
                                                                                                                        
                                                       
                                                                                                                 
                                                                                                          

  uint32_t ExternalTrigConvEdge;                                                                                        
                                                                                                                   
                                                                                                                 

  FunctionalState DMAContinuousRequests;                                                                          
                                                                                                                    
                                                                                                            
                                                                                             
                                                                                                                
                                                                                                                  
                                                                          

  uint32_t Overrun;                                                                                                    
                                                                                        
                                                                                                              
                                                                                                                      
                                                                                                                    
                                                                                                                 
                                                                                                                   
                                                                                                                      
                                                                                                 
                                                                                                                       
                                                                                                                      
                                                                                                                    
                                                                                           
                                                                                                                   
                                                                                                                   

  FunctionalState OversamplingMode;                                                                            
                                                                                              
                                                                                                                     
                                                                                                  

  ADC_OversamplingTypeDef Oversampling;                                            
                                                                                                                       
                                                                                              

#if defined(ADC_CFGR_DFSDMCFG) &&defined(DFSDM1_Channel0)
  uint32_t DFSDMConfig;                                                                              
                                                                                                           
                                                                                                                     
                                                                                    

#endif                        
} ADC_InitTypeDef;

   
                                                                 
                                                                                                            
                                    
                                                                                                                      
                                                                                                                 
                                         
                                                                                                                  
                                           
                                                                                                                  
                                                                                                                    
                                                                           
    
typedef struct
{
  uint32_t Channel;                                                                             
                                                                                                
                                                                                                                        
                                                                                                            
                                                              

  uint32_t Rank;                                                                        
                                                                                                      
                                                                                                                
                                                                                                                   
                                                                                                

  uint32_t SamplingTime;                                                                       
                                                              
                                                                                                            
                                                                                                                 
                                                                                    
                                                                                                             
                                                                                                                  
                                                                                                       
                                                                                                                     
                                                                                                                        
                                                                                                            
                                                                                              

  uint32_t SingleDiff;                                                            
                                                                                                                 
                                                                                                                 
                                                                                                                        
                                                                                                                    
                                                                                                                  
                                                                       
                                                                                
                                                                                                                      
                                                                
                                                                                                                       
                                                                    
                                                                                                                    
                                                                                       
                                                                                                                 
                                                                                                                        
                                                                   

  uint32_t OffsetNumber;                                        
                                                                                                  
                                                                                                                      
                                                                 

  uint32_t Offset;                                                                                     
                                                                               
                                                                                                                  
                                                                                                       
                                                                         
                                                                                                                    
                                                                                                               
                                                                                                                     

} ADC_ChannelConfTypeDef;

   
                                                       
                                                                                                              
                                    
                                                                                                                    
                        
    
typedef struct
{
  uint32_t WatchdogNumber;                                                                             
                                                                                                                       
                                                                                              
                                                                                                                      
                                                                                                                
                                                                                                  

  uint32_t WatchdogMode;                                                                            
                                                                                                                       
                                                                                                       
                                                                                                             
                                                                                                                    
                                                                                                                      
                                                                                                                  
                                                                                                                      
                                                                                                                     
                                                                        
                                                                                                     

  uint32_t Channel;                                                                       
                                                                                                                       
                                                                                                                
                                                                     
                                                                                                                       
                                                                                                                        
                                                                                                                   
                                                                                           
                                                                                               

  FunctionalState ITMode;                                                                                         
                                                                                    

  uint32_t HighThreshold;                                                                 
                                                                                                                       
                                                                                                            
                                                
                                                                                                              
                                                                                                                        
                                                         
                                                                                                           
                                                                                                          
                                                                                                            
                                                                                                         

  uint32_t LowThreshold;                                                                  
                                                                                                                       
                                                                                                            
                                                
                                                                                                              
                                                                                                                        
                                                         
                                                                                                           
                                                                                                          
                                                                                                            
                                                                                                        
} ADC_AnalogWDGConfTypeDef;

   
                                                           
                                                                                    
    
typedef struct
{
  uint32_t ContextQueue;                                                                                
                                                                                                          
                                                                                                             

  uint32_t ChannelCount;                                                                    
} ADC_InjectionConfigTypeDef;

                                   
      
    

   
                                                                    
                                                                             
                            
                        
                                                                                
                                                                            
    
                                
#define HAL_ADC_STATE_RESET             (0x00000000UL)                                              
#define HAL_ADC_STATE_READY             (0x00000001UL)                                       
#define HAL_ADC_STATE_BUSY_INTERNAL     (0x00000002UL)                                                               
                                                                                  
#define HAL_ADC_STATE_TIMEOUT           (0x00000004UL)                             

                          
#define HAL_ADC_STATE_ERROR_INTERNAL    (0x00000010UL)                                    
#define HAL_ADC_STATE_ERROR_CONFIG      (0x00000020UL)                                         
#define HAL_ADC_STATE_ERROR_DMA         (0x00000040UL)                               

                                 
#define HAL_ADC_STATE_REG_BUSY          (0x00000100UL)                                                                 
                                                                                                                     
                                                                                                                        
                                                                                                
#define HAL_ADC_STATE_REG_EOC           (0x00000200UL)                                                     
#define HAL_ADC_STATE_REG_OVR           (0x00000400UL)                             
#define HAL_ADC_STATE_REG_EOSMP         (0x00000800UL)                                                                
                                                                        

                                  
#define HAL_ADC_STATE_INJ_BUSY          (0x00001000UL)                                                                  
                                                                                                                   
                                                                                                                   
                                                                                                           
#define HAL_ADC_STATE_INJ_EOC           (0x00002000UL)                                                      
#define HAL_ADC_STATE_INJ_JQOVF         (0x00004000UL)                                             

                                    
#define HAL_ADC_STATE_AWD1              (0x00010000UL)                                                            
#define HAL_ADC_STATE_AWD2              (0x00020000UL)                                                            
#define HAL_ADC_STATE_AWD3              (0x00040000UL)                                                            

                              
#define HAL_ADC_STATE_MULTIMODE_SLAVE   (0x00100000UL)                                                               
                                                                                                

   
      
    

   
                                           
    
#if (USE_HAL_ADC_REGISTER_CALLBACKS == 1)
typedef struct __ADC_HandleTypeDef
#else
typedef struct
#endif                                     
{
  ADC_TypeDef                   *Instance;                                                  
  ADC_InitTypeDef               Init;                                                                        
                                                                                          
  DMA_HandleTypeDef             *DMA_Handle;                                              
  HAL_LockTypeDef               Lock;                                                    
  __IO uint32_t                 State;                                                                               
  __IO uint32_t                 ErrorCode;                                           
  ADC_InjectionConfigTypeDef    InjectionConfig ;                                                              
                                                                              
#if (USE_HAL_ADC_REGISTER_CALLBACKS == 1)
  void (* ConvCpltCallback)(struct __ADC_HandleTypeDef *hadc);                                                      
  void (* ConvHalfCpltCallback)(struct __ADC_HandleTypeDef *hadc);                                               
                                                                                            
  void (* LevelOutOfWindowCallback)(struct __ADC_HandleTypeDef *hadc);                                            
  void (* ErrorCallback)(struct __ADC_HandleTypeDef *hadc);                                           
  void (* InjectedConvCpltCallback)(struct __ADC_HandleTypeDef *hadc);                                                 
                                                                                            
  void (* InjectedQueueOverflowCallback)(struct __ADC_HandleTypeDef *hadc);                                      
                                                                                                     
  void (* LevelOutOfWindow2Callback)(struct __ADC_HandleTypeDef *hadc);                                           
  void (* LevelOutOfWindow3Callback)(struct __ADC_HandleTypeDef *hadc);                                           
  void (* EndOfSamplingCallback)(struct __ADC_HandleTypeDef *hadc);                                             
  void (* MspInitCallback)(struct __ADC_HandleTypeDef *hadc);                                            
  void (* MspDeInitCallback)(struct __ADC_HandleTypeDef *hadc);                                            
#endif                                     
} ADC_HandleTypeDef;

#if (USE_HAL_ADC_REGISTER_CALLBACKS == 1)
   
                                                      
    
typedef enum
{
  HAL_ADC_CONVERSION_COMPLETE_CB_ID     = 0x00U,                                             
  HAL_ADC_CONVERSION_HALF_CB_ID         = 0x01U,                                                      
  HAL_ADC_LEVEL_OUT_OF_WINDOW_1_CB_ID   = 0x02U,                                           
  HAL_ADC_ERROR_CB_ID                   = 0x03U,                               
  HAL_ADC_INJ_CONVERSION_COMPLETE_CB_ID = 0x04U,                                                            
  HAL_ADC_INJ_QUEUE_OVEFLOW_CB_ID       = 0x05U,                                                               
  HAL_ADC_LEVEL_OUT_OF_WINDOW_2_CB_ID   = 0x06U,                                           
  HAL_ADC_LEVEL_OUT_OF_WINDOW_3_CB_ID   = 0x07U,                                           
  HAL_ADC_END_OF_SAMPLING_CB_ID         = 0x08U,                                         
  HAL_ADC_MSPINIT_CB_ID                 = 0x09U,                                           
  HAL_ADC_MSPDEINIT_CB_ID               = 0x0AU                                            
} HAL_ADC_CallbackIDTypeDef;

   
                                               
    
typedef  void (*pADC_CallbackTypeDef)(ADC_HandleTypeDef *hadc);                                           

#endif                                     

   
      
    


                                                                                

                                                           
      
    

                                           
      
    
#define HAL_ADC_ERROR_NONE              (0x00U)                                                      
#define HAL_ADC_ERROR_INTERNAL          (0x01U)                                                           
                                                                                                     
#define HAL_ADC_ERROR_OVR               (0x02U)                                                      
#define HAL_ADC_ERROR_DMA               (0x04U)                                                      
#define HAL_ADC_ERROR_JQOVF             (0x08U)                                                      
#if (USE_HAL_ADC_REGISTER_CALLBACKS == 1)
#define HAL_ADC_ERROR_INVALID_CALLBACK  (0x10U)                                 
#endif                                     
   
      
    

                                                                       
      
    

#define ADC_CLOCK_SYNC_PCLK_DIV1           (LL_ADC_CLOCK_SYNC_PCLK_DIV1)                                           
                                                               
#define ADC_CLOCK_SYNC_PCLK_DIV2           (LL_ADC_CLOCK_SYNC_PCLK_DIV2)                                           
                                                                          
#define ADC_CLOCK_SYNC_PCLK_DIV4           (LL_ADC_CLOCK_SYNC_PCLK_DIV4)                                           
                                                                          
#define ADC_CLOCK_ASYNC_DIV1               (LL_ADC_CLOCK_ASYNC_DIV1)                                         
                                                       
#define ADC_CLOCK_ASYNC_DIV2               (LL_ADC_CLOCK_ASYNC_DIV2)                                                
                                                             
#define ADC_CLOCK_ASYNC_DIV4               (LL_ADC_CLOCK_ASYNC_DIV4)                                                
                                                             
#define ADC_CLOCK_ASYNC_DIV6               (LL_ADC_CLOCK_ASYNC_DIV6)                                                
                                                             
#define ADC_CLOCK_ASYNC_DIV8               (LL_ADC_CLOCK_ASYNC_DIV8)                                                
                                                             
#define ADC_CLOCK_ASYNC_DIV10              (LL_ADC_CLOCK_ASYNC_DIV10)                                               
                                                             
#define ADC_CLOCK_ASYNC_DIV12              (LL_ADC_CLOCK_ASYNC_DIV12)                                               
                                                             
#define ADC_CLOCK_ASYNC_DIV16              (LL_ADC_CLOCK_ASYNC_DIV16)                                               
                                                             
#define ADC_CLOCK_ASYNC_DIV32              (LL_ADC_CLOCK_ASYNC_DIV32)                                               
                                                             
#define ADC_CLOCK_ASYNC_DIV64              (LL_ADC_CLOCK_ASYNC_DIV64)                                               
                                                             
#define ADC_CLOCK_ASYNC_DIV128             (LL_ADC_CLOCK_ASYNC_DIV128)                                              
                                                             
#define ADC_CLOCK_ASYNC_DIV256             (LL_ADC_CLOCK_ASYNC_DIV256)                                              
                                                             
   
      
    

                                                              
      
    
#define ADC_RESOLUTION_12B                 (LL_ADC_RESOLUTION_12B)                                
#define ADC_RESOLUTION_10B                 (LL_ADC_RESOLUTION_10B)                                
#define ADC_RESOLUTION_8B                  (LL_ADC_RESOLUTION_8B)                                 
#define ADC_RESOLUTION_6B                  (LL_ADC_RESOLUTION_6B)                                 
   
      
    

                                                                 
      
    
#define ADC_DATAALIGN_RIGHT                (LL_ADC_DATA_ALIGN_RIGHT)                                                  
                                                                                   
#define ADC_DATAALIGN_LEFT                 (LL_ADC_DATA_ALIGN_LEFT)                                                  
                                                                                    
   
      
    

                                                   
      
    
#define ADC_SCAN_DISABLE         (0x00000000UL)                                 
#define ADC_SCAN_ENABLE          (0x00000001UL)                                 
   
      
    

                                                                                  
      
    
                                                             
#define ADC_SOFTWARE_START            (LL_ADC_REG_TRIG_SOFTWARE)                                                   
                                                               
#define ADC_EXTERNALTRIG_T1_TRGO      (LL_ADC_REG_TRIG_EXT_TIM1_TRGO)                                              
                                                                                     
#define ADC_EXTERNALTRIG_T1_TRGO2     (LL_ADC_REG_TRIG_EXT_TIM1_TRGO2)                                             
                                                                                      
#define ADC_EXTERNALTRIG_T1_CC1       (LL_ADC_REG_TRIG_EXT_TIM1_CH1)                                               
                                                                                                                  
#define ADC_EXTERNALTRIG_T1_CC2       (LL_ADC_REG_TRIG_EXT_TIM1_CH2)                                               
                                                                                                                  
#define ADC_EXTERNALTRIG_T1_CC3       (LL_ADC_REG_TRIG_EXT_TIM1_CH3)                                               
                                                                                                                  
#define ADC_EXTERNALTRIG_T2_TRGO      (LL_ADC_REG_TRIG_EXT_TIM2_TRGO)                                              
                                                                                     
#define ADC_EXTERNALTRIG_T2_CC2       (LL_ADC_REG_TRIG_EXT_TIM2_CH2)                                               
                                                                                                                  
#define ADC_EXTERNALTRIG_T3_TRGO      (LL_ADC_REG_TRIG_EXT_TIM3_TRGO)                                              
                                                                                     
#define ADC_EXTERNALTRIG_T3_CC4       (LL_ADC_REG_TRIG_EXT_TIM3_CH4)                                               
                                                                                                                  
#define ADC_EXTERNALTRIG_T4_TRGO      (LL_ADC_REG_TRIG_EXT_TIM4_TRGO)                                              
                                                                                     
#define ADC_EXTERNALTRIG_T4_CC4       (LL_ADC_REG_TRIG_EXT_TIM4_CH4)                                               
                                                                                                                  
#define ADC_EXTERNALTRIG_T6_TRGO      (LL_ADC_REG_TRIG_EXT_TIM6_TRGO)                                              
                                                                                     
#define ADC_EXTERNALTRIG_T8_TRGO      (LL_ADC_REG_TRIG_EXT_TIM8_TRGO)                                              
                                                                                     
#define ADC_EXTERNALTRIG_T8_TRGO2     (LL_ADC_REG_TRIG_EXT_TIM8_TRGO2)                                             
                                                                                      
#define ADC_EXTERNALTRIG_T15_TRGO     (LL_ADC_REG_TRIG_EXT_TIM15_TRGO)                                             
                                                                                      
#define ADC_EXTERNALTRIG_EXT_IT11     (LL_ADC_REG_TRIG_EXT_EXTI_LINE11)                                            
                                                                                                      
   
      
    

                                                                                                                  
      
    
#define ADC_EXTERNALTRIGCONVEDGE_NONE           (0x00000000UL)                                                    
                                                                     
#define ADC_EXTERNALTRIGCONVEDGE_RISING         (LL_ADC_REG_TRIG_EXT_RISING)                                         
                                                                                      
#define ADC_EXTERNALTRIGCONVEDGE_FALLING        (LL_ADC_REG_TRIG_EXT_FALLING)                                        
                                                                                       
#define ADC_EXTERNALTRIGCONVEDGE_RISINGFALLING  (LL_ADC_REG_TRIG_EXT_RISINGFALLING)                                  
                                                                                                        
   
      
    

                                                                                              
      
    
#define ADC_EOC_SINGLE_CONV         (ADC_ISR_EOC)                                                        
#define ADC_EOC_SEQ_CONV            (ADC_ISR_EOS)                                                            
   
      
    

                                                                                                       
      
    
#define ADC_OVR_DATA_PRESERVED             (LL_ADC_REG_OVR_DATA_PRESERVED)                                           
                                                                        
#define ADC_OVR_DATA_OVERWRITTEN           (LL_ADC_REG_OVR_DATA_OVERWRITTEN)                                         
                                                                          
   
      
    

                                                                           
      
    
#define ADC_REGULAR_RANK_1                 (LL_ADC_REG_RANK_1)                                            
#define ADC_REGULAR_RANK_2                 (LL_ADC_REG_RANK_2)                                            
#define ADC_REGULAR_RANK_3                 (LL_ADC_REG_RANK_3)                                            
#define ADC_REGULAR_RANK_4                 (LL_ADC_REG_RANK_4)                                            
#define ADC_REGULAR_RANK_5                 (LL_ADC_REG_RANK_5)                                            
#define ADC_REGULAR_RANK_6                 (LL_ADC_REG_RANK_6)                                            
#define ADC_REGULAR_RANK_7                 (LL_ADC_REG_RANK_7)                                            
#define ADC_REGULAR_RANK_8                 (LL_ADC_REG_RANK_8)                                            
#define ADC_REGULAR_RANK_9                 (LL_ADC_REG_RANK_9)                                            
#define ADC_REGULAR_RANK_10                (LL_ADC_REG_RANK_10)                                            
#define ADC_REGULAR_RANK_11                (LL_ADC_REG_RANK_11)                                            
#define ADC_REGULAR_RANK_12                (LL_ADC_REG_RANK_12)                                            
#define ADC_REGULAR_RANK_13                (LL_ADC_REG_RANK_13)                                            
#define ADC_REGULAR_RANK_14                (LL_ADC_REG_RANK_14)                                            
#define ADC_REGULAR_RANK_15                (LL_ADC_REG_RANK_15)                                            
#define ADC_REGULAR_RANK_16                (LL_ADC_REG_RANK_16)                                            
   
      
    

                                                                      
      
    
#define ADC_SAMPLETIME_2CYCLES_5         (LL_ADC_SAMPLINGTIME_2CYCLES_5)                                              
#define ADC_SAMPLETIME_6CYCLES_5         (LL_ADC_SAMPLINGTIME_6CYCLES_5)                                              
#define ADC_SAMPLETIME_12CYCLES_5        (LL_ADC_SAMPLINGTIME_12CYCLES_5)                                              
#define ADC_SAMPLETIME_24CYCLES_5        (LL_ADC_SAMPLINGTIME_24CYCLES_5)                                              
#define ADC_SAMPLETIME_47CYCLES_5        (LL_ADC_SAMPLINGTIME_47CYCLES_5)                                              
#define ADC_SAMPLETIME_92CYCLES_5        (LL_ADC_SAMPLINGTIME_92CYCLES_5)                                              
#define ADC_SAMPLETIME_247CYCLES_5       (LL_ADC_SAMPLINGTIME_247CYCLES_5)                                              
#define ADC_SAMPLETIME_640CYCLES_5       (LL_ADC_SAMPLINGTIME_640CYCLES_5)                                              
#if defined(ADC_SMPR1_SMPPLUS)
#define ADC_SAMPLETIME_3CYCLES_5         (ADC_SMPR1_SMPPLUS | LL_ADC_SAMPLINGTIME_2CYCLES_5)                       
                                                                                                                 
                                                                                                                       
#endif                        
   
      
    

                                                               
      
    
                                                                                
                                                                                
#define ADC_CHANNEL_0                      (LL_ADC_CHANNEL_0)                                                           
#define ADC_CHANNEL_1                      (LL_ADC_CHANNEL_1)                                                           
#define ADC_CHANNEL_2                      (LL_ADC_CHANNEL_2)                                                           
#define ADC_CHANNEL_3                      (LL_ADC_CHANNEL_3)                                                           
#define ADC_CHANNEL_4                      (LL_ADC_CHANNEL_4)                                                           
#define ADC_CHANNEL_5                      (LL_ADC_CHANNEL_5)                                                           
#define ADC_CHANNEL_6                      (LL_ADC_CHANNEL_6)                                                           
#define ADC_CHANNEL_7                      (LL_ADC_CHANNEL_7)                                                           
#define ADC_CHANNEL_8                      (LL_ADC_CHANNEL_8)                                                           
#define ADC_CHANNEL_9                      (LL_ADC_CHANNEL_9)                                                           
#define ADC_CHANNEL_10                     (LL_ADC_CHANNEL_10)                                                          
#define ADC_CHANNEL_11                     (LL_ADC_CHANNEL_11)                                                          
#define ADC_CHANNEL_12                     (LL_ADC_CHANNEL_12)                                                          
#define ADC_CHANNEL_13                     (LL_ADC_CHANNEL_13)                                                          
#define ADC_CHANNEL_14                     (LL_ADC_CHANNEL_14)                                                          
#define ADC_CHANNEL_15                     (LL_ADC_CHANNEL_15)                                                          
#define ADC_CHANNEL_16                     (LL_ADC_CHANNEL_16)                                                          
#define ADC_CHANNEL_17                     (LL_ADC_CHANNEL_17)                                                          
#define ADC_CHANNEL_18                     (LL_ADC_CHANNEL_18)                                                          
#define ADC_CHANNEL_VREFINT                (LL_ADC_CHANNEL_VREFINT)                                               
                                                                
#define ADC_CHANNEL_TEMPSENSOR             (LL_ADC_CHANNEL_TEMPSENSOR)                                                 
#define ADC_CHANNEL_VBAT                   (LL_ADC_CHANNEL_VBAT)                                                     
                                                                                                                      
                                                   
#if defined(ADC1) && !defined(ADC2)
#define ADC_CHANNEL_DAC1CH1                (LL_ADC_CHANNEL_DAC1CH1)                                             
                                                                                                                     
                                                                                   
                                                                                    
#define ADC_CHANNEL_DAC1CH2                (LL_ADC_CHANNEL_DAC1CH2)                                             
                                                                                                               
                                                                                                                     
#elif defined(ADC2)
#define ADC_CHANNEL_DAC1CH1_ADC2           (LL_ADC_CHANNEL_DAC1CH1_ADC2)                                        
                                                                      
#define ADC_CHANNEL_DAC1CH2_ADC2           (LL_ADC_CHANNEL_DAC1CH2_ADC2)                                        
                                                                      
#if defined(ADC3)
#define ADC_CHANNEL_DAC1CH1_ADC3           (LL_ADC_CHANNEL_DAC1CH1_ADC3)                                        
                                                                      
#define ADC_CHANNEL_DAC1CH2_ADC3           (LL_ADC_CHANNEL_DAC1CH2_ADC3)                                        
                                                                      
#endif           
#endif                    
   
      
    

                                                                                      
      
    
#define ADC_ANALOGWATCHDOG_1               (LL_ADC_AWD1)                                     
#define ADC_ANALOGWATCHDOG_2               (LL_ADC_AWD2)                                     
#define ADC_ANALOGWATCHDOG_3               (LL_ADC_AWD3)                                     
   
      
    

                                                                     
      
    
#define ADC_ANALOGWATCHDOG_NONE                 (0x00000000UL)                                                     
#define ADC_ANALOGWATCHDOG_SINGLE_REG           (ADC_CFGR_AWD1SGL | ADC_CFGR_AWD1EN)                                    
                                                                       
#define ADC_ANALOGWATCHDOG_SINGLE_INJEC         (ADC_CFGR_AWD1SGL | ADC_CFGR_JAWD1EN)                            
                                                                                
#define ADC_ANALOGWATCHDOG_SINGLE_REGINJEC      (ADC_CFGR_AWD1SGL | ADC_CFGR_AWD1EN\
                                                 | ADC_CFGR_JAWD1EN)                                                     
                                                                                     
#define ADC_ANALOGWATCHDOG_ALL_REG              (ADC_CFGR_AWD1EN)                                                     
                                                                     
#define ADC_ANALOGWATCHDOG_ALL_INJEC            (ADC_CFGR_JAWD1EN)                                                     
                                                                     
#define ADC_ANALOGWATCHDOG_ALL_REGINJEC         (ADC_CFGR_AWD1EN | ADC_CFGR_JAWD1EN)                                  
                                                                                   
   
      
    

                                                        
      
    
   
                                                                                                                      
                                                                                    
    
#define ADC_OVERSAMPLING_RATIO_2           (LL_ADC_OVS_RATIO_2)                                       
#define ADC_OVERSAMPLING_RATIO_4           (LL_ADC_OVS_RATIO_4)                                       
#define ADC_OVERSAMPLING_RATIO_8           (LL_ADC_OVS_RATIO_8)                                       
#define ADC_OVERSAMPLING_RATIO_16          (LL_ADC_OVS_RATIO_16)                                      
#define ADC_OVERSAMPLING_RATIO_32          (LL_ADC_OVS_RATIO_32)                                      
#define ADC_OVERSAMPLING_RATIO_64          (LL_ADC_OVS_RATIO_64)                                      
#define ADC_OVERSAMPLING_RATIO_128         (LL_ADC_OVS_RATIO_128)                                     
#define ADC_OVERSAMPLING_RATIO_256         (LL_ADC_OVS_RATIO_256)                                     
   
      
    

                                                             
      
    
   
                                                                                                                    
                          
    
#define ADC_RIGHTBITSHIFT_NONE             (LL_ADC_OVS_SHIFT_NONE)                                       
#define ADC_RIGHTBITSHIFT_1                (LL_ADC_OVS_SHIFT_RIGHT_1)                                                
#define ADC_RIGHTBITSHIFT_2                (LL_ADC_OVS_SHIFT_RIGHT_2)                                                
#define ADC_RIGHTBITSHIFT_3                (LL_ADC_OVS_SHIFT_RIGHT_3)                                                
#define ADC_RIGHTBITSHIFT_4                (LL_ADC_OVS_SHIFT_RIGHT_4)                                                
#define ADC_RIGHTBITSHIFT_5                (LL_ADC_OVS_SHIFT_RIGHT_5)                                                
#define ADC_RIGHTBITSHIFT_6                (LL_ADC_OVS_SHIFT_RIGHT_6)                                                
#define ADC_RIGHTBITSHIFT_7                (LL_ADC_OVS_SHIFT_RIGHT_7)                                                
#define ADC_RIGHTBITSHIFT_8                (LL_ADC_OVS_SHIFT_RIGHT_8)                                                
   
      
    

                                                                            
      
    
#define ADC_TRIGGEREDMODE_SINGLE_TRIGGER   (LL_ADC_OVS_REG_CONT)                                                   
                                                                                                                    
#define ADC_TRIGGEREDMODE_MULTI_TRIGGER    (LL_ADC_OVS_REG_DISCONT)                                                
                                                                                                               
   
      
    

                                                                                               
      
    
#define ADC_REGOVERSAMPLING_CONTINUED_MODE (LL_ADC_OVS_GRP_REGULAR_CONTINUED)                                    
                                                                       
#define ADC_REGOVERSAMPLING_RESUMED_MODE   (LL_ADC_OVS_GRP_REGULAR_RESUMED)                                         
                                                                
   
      
    

                                           
      
    
   
                                                            
                                                                 
    
#define ADC_EOSMP_EVENT          (ADC_FLAG_EOSMP)                                  
#define ADC_AWD1_EVENT           (ADC_FLAG_AWD1)                                                                  
#define ADC_AWD2_EVENT           (ADC_FLAG_AWD2)                                                                  
#define ADC_AWD3_EVENT           (ADC_FLAG_AWD3)                                                                  
#define ADC_OVR_EVENT            (ADC_FLAG_OVR)                            
#define ADC_JQOVF_EVENT          (ADC_FLAG_JQOVF)                                                  
   
      
    
#define ADC_AWD_EVENT            ADC_AWD1_EVENT                                                                
                                                                                                                     

                                                                 
      
    
#define ADC_IT_RDY           ADC_IER_ADRDYIE                                      
#define ADC_IT_EOSMP         ADC_IER_EOSMPIE                                                
#define ADC_IT_EOC           ADC_IER_EOCIE                                                            
#define ADC_IT_EOS           ADC_IER_EOSIE                                                                         
#define ADC_IT_OVR           ADC_IER_OVRIE                                          
#define ADC_IT_JEOC          ADC_IER_JEOCIE                                                            
#define ADC_IT_JEOS          ADC_IER_JEOSIE                                                                         
#define ADC_IT_AWD1          ADC_IER_AWD1IE                                                                          
#define ADC_IT_AWD2          ADC_IER_AWD2IE                                                                   
                                         
#define ADC_IT_AWD3          ADC_IER_AWD3IE                                                                   
                                         
#define ADC_IT_JQOVF         ADC_IER_JQOVFIE                                                                

#define ADC_IT_AWD           ADC_IT_AWD1                                                                         
                                                                                                                 

   
      
    

                                                       
      
    
#define ADC_FLAG_RDY           ADC_ISR_ADRDY                          
#define ADC_FLAG_EOSMP         ADC_ISR_EOSMP                                    
#define ADC_FLAG_EOC           ADC_ISR_EOC                                                
#define ADC_FLAG_EOS           ADC_ISR_EOS                                                             
#define ADC_FLAG_OVR           ADC_ISR_OVR                              
#define ADC_FLAG_JEOC          ADC_ISR_JEOC                                                
#define ADC_FLAG_JEOS          ADC_ISR_JEOS                                                             
#define ADC_FLAG_AWD1          ADC_ISR_AWD1                                                              
#define ADC_FLAG_AWD2          ADC_ISR_AWD2                                                                    
#define ADC_FLAG_AWD3          ADC_ISR_AWD3                                                                    
#define ADC_FLAG_JQOVF         ADC_ISR_JQOVF                                                    

#define ADC_FLAG_AWD           ADC_FLAG_AWD1                                                                        
                                                                                                    

#define ADC_FLAG_ALL    (ADC_FLAG_RDY | ADC_FLAG_EOSMP | ADC_FLAG_EOC | ADC_FLAG_EOS |  \
                         ADC_FLAG_JEOC | ADC_FLAG_JEOS | ADC_FLAG_OVR | ADC_FLAG_AWD1 | \
                         ADC_FLAG_AWD2 | ADC_FLAG_AWD3 | ADC_FLAG_JQOVF)                        

                                                                                         
#define ADC_FLAG_POSTCONV_ALL (ADC_FLAG_EOC | ADC_FLAG_EOS  | ADC_FLAG_JEOC | ADC_FLAG_JEOS | \
                               ADC_FLAG_OVR | ADC_FLAG_AWD1 | ADC_FLAG_AWD2 | ADC_FLAG_AWD3 | \
                               ADC_FLAG_JQOVF)                                                                  

   
      
    

   
      
    

                                                                                

                                                   
      
    
                                                                                
                                                                                

   
                                                                  
                                
                                                   
    
#define ADC_GET_RESOLUTION(__HANDLE__)                                         \
  (LL_ADC_GetResolution((__HANDLE__)->Instance))

   
                                                                               
                                
                
    
#define ADC_CLEAR_ERRORCODE(__HANDLE__) ((__HANDLE__)->ErrorCode = HAL_ADC_ERROR_NONE)

   
                                                          
                                
                                                     
    
#define ADC_IS_ENABLE(__HANDLE__)                                                     \
  ((((((__HANDLE__)->Instance->CR) & (ADC_CR_ADEN | ADC_CR_ADDIS)) == ADC_CR_ADEN) && \
    ((((__HANDLE__)->Instance->ISR) & ADC_FLAG_RDY) == ADC_FLAG_RDY)                  \
   ) ? SET : RESET)

   
                                                            
                                
                                                                                       
    
#define ADC_IS_CONVERSION_ONGOING_REGULAR(__HANDLE__)                          \
  (LL_ADC_REG_IsConversionOngoing((__HANDLE__)->Instance))

   
                                                                          
                                                                                     
                                                                                   
                                                                                    
                
    
#define ADC_STATE_CLR_SET MODIFY_REG

   
                                                                              
                                                               
                                                              
                                                                                                                    
    
#define IS_ADC_RANGE(__RESOLUTION__, __ADC_VALUE__) \
  ((__ADC_VALUE__) <= __LL_ADC_DIGITAL_SCALE(__RESOLUTION__))

   
                                                                        
                                                       
                                                                                                      
                                                      
    
#define IS_ADC_REGULAR_NB_CONV(__LENGTH__) (((__LENGTH__) >= (1UL)) && ((__LENGTH__) <= (16UL)))


   
                                                                                    
                                                                                
                                                                                                  
                                                  
    
#define IS_ADC_REGULAR_DISCONT_NUMBER(NUMBER) (((NUMBER) >= (1UL)) && ((NUMBER) <= (8UL)))


   
                                        
                                              
                                                                                    
    
#define IS_ADC_CLOCKPRESCALER(__ADC_CLOCK__) (((__ADC_CLOCK__) == ADC_CLOCK_SYNC_PCLK_DIV1) || \
                                              ((__ADC_CLOCK__) == ADC_CLOCK_SYNC_PCLK_DIV2) || \
                                              ((__ADC_CLOCK__) == ADC_CLOCK_SYNC_PCLK_DIV4) || \
                                              ((__ADC_CLOCK__) == ADC_CLOCK_ASYNC_DIV1)     || \
                                              ((__ADC_CLOCK__) == ADC_CLOCK_ASYNC_DIV2)     || \
                                              ((__ADC_CLOCK__) == ADC_CLOCK_ASYNC_DIV4)     || \
                                              ((__ADC_CLOCK__) == ADC_CLOCK_ASYNC_DIV6)     || \
                                              ((__ADC_CLOCK__) == ADC_CLOCK_ASYNC_DIV8)     || \
                                              ((__ADC_CLOCK__) == ADC_CLOCK_ASYNC_DIV10)    || \
                                              ((__ADC_CLOCK__) == ADC_CLOCK_ASYNC_DIV12)    || \
                                              ((__ADC_CLOCK__) == ADC_CLOCK_ASYNC_DIV16)    || \
                                              ((__ADC_CLOCK__) == ADC_CLOCK_ASYNC_DIV32)    || \
                                              ((__ADC_CLOCK__) == ADC_CLOCK_ASYNC_DIV64)    || \
                                              ((__ADC_CLOCK__) == ADC_CLOCK_ASYNC_DIV128)   || \
                                              ((__ADC_CLOCK__) == ADC_CLOCK_ASYNC_DIV256) )

   
                                             
                                                    
                                                                                      
    
#define IS_ADC_RESOLUTION(__RESOLUTION__) (((__RESOLUTION__) == ADC_RESOLUTION_12B) || \
                                           ((__RESOLUTION__) == ADC_RESOLUTION_10B) || \
                                           ((__RESOLUTION__) == ADC_RESOLUTION_8B)  || \
                                           ((__RESOLUTION__) == ADC_RESOLUTION_6B)    )

   
                                                                         
                                                                                
                                                                                      
    
#define IS_ADC_RESOLUTION_8_6_BITS(__RESOLUTION__) (((__RESOLUTION__) == ADC_RESOLUTION_8B) || \
                                                    ((__RESOLUTION__) == ADC_RESOLUTION_6B)   )

   
                                                   
                                                             
                                                                            
    
#define IS_ADC_DATA_ALIGN(__ALIGN__) (((__ALIGN__) == ADC_DATAALIGN_RIGHT) || \
                                      ((__ALIGN__) == ADC_DATAALIGN_LEFT)    )

   
                                    
                                                  
                                                                            
    
#define IS_ADC_SCAN_MODE(__SCAN_MODE__) (((__SCAN_MODE__) == ADC_SCAN_DISABLE) || \
                                         ((__SCAN_MODE__) == ADC_SCAN_ENABLE)    )

   
                                                                 
                                                        
                                                                          
    
#define IS_ADC_EXTTRIG_EDGE(__EDGE__) (((__EDGE__) == ADC_EXTERNALTRIGCONVEDGE_NONE)         || \
                                       ((__EDGE__) == ADC_EXTERNALTRIGCONVEDGE_RISING)       || \
                                       ((__EDGE__) == ADC_EXTERNALTRIGCONVEDGE_FALLING)      || \
                                       ((__EDGE__) == ADC_EXTERNALTRIGCONVEDGE_RISINGFALLING)  )

   
                                                               
                                
                                                                           
                                                                                
    
#define IS_ADC_EXTTRIG(__HANDLE__, __REGTRIG__) (((__REGTRIG__) == ADC_EXTERNALTRIG_T1_CC1)   || \
                                                 ((__REGTRIG__) == ADC_EXTERNALTRIG_T1_CC2)   || \
                                                 ((__REGTRIG__) == ADC_EXTERNALTRIG_T1_CC3)   || \
                                                 ((__REGTRIG__) == ADC_EXTERNALTRIG_T2_CC2)   || \
                                                 ((__REGTRIG__) == ADC_EXTERNALTRIG_T3_TRGO)  || \
                                                 ((__REGTRIG__) == ADC_EXTERNALTRIG_T4_CC4)   || \
                                                 ((__REGTRIG__) == ADC_EXTERNALTRIG_EXT_IT11) || \
                                                 ((__REGTRIG__) == ADC_EXTERNALTRIG_T8_TRGO)  || \
                                                 ((__REGTRIG__) == ADC_EXTERNALTRIG_T8_TRGO2) || \
                                                 ((__REGTRIG__) == ADC_EXTERNALTRIG_T1_TRGO)  || \
                                                 ((__REGTRIG__) == ADC_EXTERNALTRIG_T1_TRGO2) || \
                                                 ((__REGTRIG__) == ADC_EXTERNALTRIG_T2_TRGO)  || \
                                                 ((__REGTRIG__) == ADC_EXTERNALTRIG_T4_TRGO)  || \
                                                 ((__REGTRIG__) == ADC_EXTERNALTRIG_T6_TRGO)  || \
                                                 ((__REGTRIG__) == ADC_EXTERNALTRIG_T15_TRGO) || \
                                                 ((__REGTRIG__) == ADC_EXTERNALTRIG_T3_CC4)   || \
                                                 ((__REGTRIG__) == ADC_SOFTWARE_START)           )

   
                                                                                    
                                                               
                                                                                            
    
#define IS_ADC_EOC_SELECTION(__EOC_SELECTION__) (((__EOC_SELECTION__) == ADC_EOC_SINGLE_CONV)    || \
                                                 ((__EOC_SELECTION__) == ADC_EOC_SEQ_CONV)  )

   
                                                               
                                                            
                                                                        
    
#define IS_ADC_OVERRUN(__OVR__) (((__OVR__) == ADC_OVR_DATA_PRESERVED)  || \
                                 ((__OVR__) == ADC_OVR_DATA_OVERWRITTEN)  )

   
                                                    
                                                  
                                                                          
    
#if defined(ADC_SMPR1_SMPPLUS)
#define IS_ADC_SAMPLE_TIME(__TIME__) (((__TIME__) == ADC_SAMPLETIME_2CYCLES_5)   || \
                                      ((__TIME__) == ADC_SAMPLETIME_3CYCLES_5)   || \
                                      ((__TIME__) == ADC_SAMPLETIME_6CYCLES_5)   || \
                                      ((__TIME__) == ADC_SAMPLETIME_12CYCLES_5)  || \
                                      ((__TIME__) == ADC_SAMPLETIME_24CYCLES_5)  || \
                                      ((__TIME__) == ADC_SAMPLETIME_47CYCLES_5)  || \
                                      ((__TIME__) == ADC_SAMPLETIME_92CYCLES_5)  || \
                                      ((__TIME__) == ADC_SAMPLETIME_247CYCLES_5) || \
                                      ((__TIME__) == ADC_SAMPLETIME_640CYCLES_5)   )
#else
#define IS_ADC_SAMPLE_TIME(__TIME__) (((__TIME__) == ADC_SAMPLETIME_2CYCLES_5)   || \
                                      ((__TIME__) == ADC_SAMPLETIME_6CYCLES_5)   || \
                                      ((__TIME__) == ADC_SAMPLETIME_12CYCLES_5)  || \
                                      ((__TIME__) == ADC_SAMPLETIME_24CYCLES_5)  || \
                                      ((__TIME__) == ADC_SAMPLETIME_47CYCLES_5)  || \
                                      ((__TIME__) == ADC_SAMPLETIME_92CYCLES_5)  || \
                                      ((__TIME__) == ADC_SAMPLETIME_247CYCLES_5) || \
                                      ((__TIME__) == ADC_SAMPLETIME_640CYCLES_5)   )
#endif                        

   
                                                  
                                                       
                                                                        
    
#define IS_ADC_REGULAR_RANK(__CHANNEL__) (((__CHANNEL__) == ADC_REGULAR_RANK_1 ) || \
                                          ((__CHANNEL__) == ADC_REGULAR_RANK_2 ) || \
                                          ((__CHANNEL__) == ADC_REGULAR_RANK_3 ) || \
                                          ((__CHANNEL__) == ADC_REGULAR_RANK_4 ) || \
                                          ((__CHANNEL__) == ADC_REGULAR_RANK_5 ) || \
                                          ((__CHANNEL__) == ADC_REGULAR_RANK_6 ) || \
                                          ((__CHANNEL__) == ADC_REGULAR_RANK_7 ) || \
                                          ((__CHANNEL__) == ADC_REGULAR_RANK_8 ) || \
                                          ((__CHANNEL__) == ADC_REGULAR_RANK_9 ) || \
                                          ((__CHANNEL__) == ADC_REGULAR_RANK_10) || \
                                          ((__CHANNEL__) == ADC_REGULAR_RANK_11) || \
                                          ((__CHANNEL__) == ADC_REGULAR_RANK_12) || \
                                          ((__CHANNEL__) == ADC_REGULAR_RANK_13) || \
                                          ((__CHANNEL__) == ADC_REGULAR_RANK_14) || \
                                          ((__CHANNEL__) == ADC_REGULAR_RANK_15) || \
                                          ((__CHANNEL__) == ADC_REGULAR_RANK_16)   )

   
      
    


                                                                                

                                                         
      
    

                                                                              
                                                                              
                                                                              
                                                                              
                                                                              
                                                                              
                                                                              
#define ADC_STOP_CONVERSION_TIMEOUT     ( 5UL)                                    

                                                                              
                                                                              
                                                                              
#define ADC_TEMPSENSOR_DELAY_US         (LL_ADC_DELAY_TEMPSENSOR_STAB_US)

   
      
    

                                                                                

                                                     
      
    
                                                                                
                                                                                

                                                                                             
      
    

                                   
                                
                
    
#if (USE_HAL_ADC_REGISTER_CALLBACKS == 1)
#define __HAL_ADC_RESET_HANDLE_STATE(__HANDLE__)                               \
  do{                                                                          \
    (__HANDLE__)->State = HAL_ADC_STATE_RESET;                                 \
    (__HANDLE__)->MspInitCallback = NULL;                                      \
    (__HANDLE__)->MspDeInitCallback = NULL;                                    \
  } while(0)
#else
#define __HAL_ADC_RESET_HANDLE_STATE(__HANDLE__)                               \
  ((__HANDLE__)->State = HAL_ADC_STATE_RESET)
#endif                                     

   
                                
                                
                                      
                                                             
                                                                 
                                                                           
                                                                                     
                                                                                                  
                                                                   
                                                                                      
                                                                                                   
                                                                                                    
                                                                                                          
                                                                                                          
                                                                                            
                
    
#define __HAL_ADC_ENABLE_IT(__HANDLE__, __INTERRUPT__)                         \
  (((__HANDLE__)->Instance->IER) |= (__INTERRUPT__))

   
                                 
                                
                                      
                                                             
                                                                 
                                                                           
                                                                                     
                                                                                                  
                                                                   
                                                                                      
                                                                                                   
                                                                                                    
                                                                                                          
                                                                                                          
                                                                                            
                
    
#define __HAL_ADC_DISABLE_IT(__HANDLE__, __INTERRUPT__)                        \
  (((__HANDLE__)->Instance->IER) &= ~(__INTERRUPT__))

                                                                                
                                
                                                      
                                                               
                                                                 
                                                                           
                                                                                     
                                                                                                  
                                                                   
                                                                                      
                                                                                                   
                                                                                                    
                                                                                                          
                                                                                                          
                                                                                            
                                                
    
#define __HAL_ADC_GET_IT_SOURCE(__HANDLE__, __INTERRUPT__)                     \
  (((__HANDLE__)->Instance->IER & (__INTERRUPT__)) == (__INTERRUPT__))

   
                                                              
                                
                            
                                                             
                                                        
                                                                  
                                                                            
                                                                                         
                                                          
                                                                             
                                                                                          
                                                                                           
                                                                                                 
                                                                                                 
                                                                                   
                                          
    
#define __HAL_ADC_GET_FLAG(__HANDLE__, __FLAG__)                               \
  ((((__HANDLE__)->Instance->ISR) & (__FLAG__)) == (__FLAG__))

   
                                        
                                
                            
                                                             
                                                        
                                                                  
                                                                            
                                                                                         
                                                          
                                                                             
                                                                                          
                                                                                           
                                                                                                 
                                                                                                 
                                                                                   
                
    
                                                                                             
#define __HAL_ADC_CLEAR_FLAG(__HANDLE__, __FLAG__)                             \
  (((__HANDLE__)->Instance->ISR) = (__FLAG__))

   
      
    

                                                          
      
    

   
                                                                    
                                        
                    
                                                            
                                             
                                                                   
                                                          
                                                        
                                                                          
                                   
                                                  
                                                  
                                                  
                                                  
                                                  
                                   
                                   
                                   
                                   
                                    
                                    
                                    
                                    
                                    
                                    
                                    
                                    
                                    
                                                  
                                                  
                                                  
                                                     
                                                     
                                                     
                                                     
                                                     
                                                     
   
                                                                             
                                                                             
                                                                             
                                                                                    
                                                                                      
                                                                                        
                                                                                                                
                                                                                                                        
                                                    
    
#define __HAL_ADC_CHANNEL_TO_DECIMAL_NB(__CHANNEL__)                           \
  __LL_ADC_CHANNEL_TO_DECIMAL_NB((__CHANNEL__))

   
                                                                           
                                          
                    
                                                
                                                               
                                                                   
                                                              
                                   
                                                  
                                                  
                                                  
                                                  
                                                  
                                   
                                   
                                   
                                   
                                    
                                    
                                    
                                    
                                    
                                    
                                    
                                    
                                    
                                                  
                                                  
                                                  
                                                     
                                                     
                                                     
                                                     
                                                     
                                                     
   
                                                                             
                                                                             
                                                                             
                                                                                    
                                                                                      
                                                                                        
                                                                                                                
                                                                                                           
                              
                                                                     
                                                                              
                                                                                         
    
#define __HAL_ADC_DECIMAL_NB_TO_CHANNEL(__DECIMAL_NB__)                        \
  __LL_ADC_DECIMAL_NB_TO_CHANNEL((__DECIMAL_NB__))

   
                                                                  
                                                         
                                                                  
                                   
                                                              
                                                                     
                                               
                                                                      
                                                                      
                                         
                                                                     
                                                                        
                                        
                                                                         
                                                                          
                                             
                                                                          
                                   
                                                  
                                                  
                                                  
                                                  
                                                  
                                   
                                   
                                   
                                   
                                    
                                    
                                    
                                    
                                    
                                    
                                    
                                    
                                    
                                                  
                                                  
                                                  
                                                     
                                                     
                                                     
                                                     
                                                     
                                                     
   
                                                                             
                                                                             
                                                                             
                                                                                    
                                                                                      
                                                                                        
                                                                                                                
                                                                                                                        
                                                                                                             
                                     
                                                                                                     
    
#define __HAL_ADC_IS_CHANNEL_INTERNAL(__CHANNEL__)                             \
  __LL_ADC_IS_CHANNEL_INTERNAL((__CHANNEL__))

   
                                                                    
                                                                      
                                         
                                                                            
                                                
                                                                 
                                                                       
                                                               
                                                        
                                                                    
                                                                        
                               
                                                                          
                                   
                                                  
                                                  
                                                  
                                                  
                                                  
                                   
                                   
                                   
                                   
                                    
                                    
                                    
                                    
                                    
                                    
                                    
                                    
                                    
                                                  
                                                  
                                                  
                                                     
                                                     
                                                     
                                                     
                                                     
                                                     
   
                                                                             
                                                                             
                                                                             
                                                                                    
                                                                                      
                                                                                        
                                                                                                                
                                                                                                                        
                                                              
                                   
                                   
                                   
                                   
                                   
                                   
                                   
                                   
                                   
                                   
                                    
                                    
                                    
                                    
                                    
                                    
                                    
                                    
                                    
    
#define __HAL_ADC_CHANNEL_INTERNAL_TO_EXTERNAL(__CHANNEL__)                    \
  __LL_ADC_CHANNEL_INTERNAL_TO_EXTERNAL((__CHANNEL__))

   
                                                                  
                                                               
                                                                        
                                                                      
                                         
                                                                    
                                                                    
                                                               
                                        
                                                                         
                                                                          
                                             
                                         
                                                                          
                                                  
                                                  
                                                  
                                                     
                                                     
                                                     
                                                     
                                                     
                                                     
   
                                                                             
                                                                             
                                                                             
                                                                                    
                                                                                      
                                                                                      
                                                                                                     
                                                                                                 
    
#define __HAL_ADC_IS_CHANNEL_INTERNAL_AVAILABLE(__ADC_INSTANCE__, __CHANNEL__)  \
  __LL_ADC_IS_CHANNEL_INTERNAL_AVAILABLE((__ADC_INSTANCE__), (__CHANNEL__))

#if defined(ADC_MULTIMODE_SUPPORT)
   
                                                                               
                                                                                   
                                                                            
                                                                            
                                                                               
                                                                        
                                                                                         
                                         
                                        
                                                                                   
                                                           
    
#define __HAL_ADC_MULTI_CONV_DATA_MASTER_SLAVE(__ADC_MULTI_MASTER_SLAVE__, __ADC_MULTI_CONV_DATA__)  \
  __LL_ADC_MULTI_CONV_DATA_MASTER_SLAVE((__ADC_MULTI_MASTER_SLAVE__), (__ADC_MULTI_CONV_DATA__))
#endif                            

   
                                                          
                                                            
                                                         
                                                            
                                                                
                                                                           
                                 
                                        
    
#define __HAL_ADC_COMMON_INSTANCE(__ADCx__)                                    \
  __LL_ADC_COMMON_INSTANCE((__ADCx__))

   
                                                                       
                                             
                                                                           
                      
                                                                       
                                                                           
                                                                               
                                                                           
                                                                 
                                                
                                                                                                                 
                                                                               
                         
                                                                                       
                       
    
#define __HAL_ADC_IS_ENABLED_ALL_COMMON_INSTANCE(__ADCXY_COMMON__)              \
  __LL_ADC_IS_ENABLED_ALL_COMMON_INSTANCE((__ADCXY_COMMON__))

   
                                                                             
                                                               
                                                                       
                                                                   
                                        
                                                                                 
                                        
                                        
                                       
                                       
                                                        
    
#define __HAL_ADC_DIGITAL_SCALE(__ADC_RESOLUTION__)                             \
  __LL_ADC_DIGITAL_SCALE((__ADC_RESOLUTION__))

   
                                                                
                                               
                                                        
                                                                                
                                                              
                                        
                                        
                                       
                                       
                                                                             
                                                              
                                        
                                        
                                       
                                       
                                                           
    
#define __HAL_ADC_CONVERT_DATA_RESOLUTION(__DATA__,\
                                          __ADC_RESOLUTION_CURRENT__,\
                                          __ADC_RESOLUTION_TARGET__) \
__LL_ADC_CONVERT_DATA_RESOLUTION((__DATA__),\
                                 (__ADC_RESOLUTION_CURRENT__),\
                                 (__ADC_RESOLUTION_TARGET__))

   
                                                               
                                                                         
                                                                      
                                                                             
                                                                         
                                                                      
                                                                 
                                                
                                                                                 
                                        
                                        
                                       
                                       
                                                                      
    
#define __HAL_ADC_CALC_DATA_TO_VOLTAGE(__VREFANALOG_VOLTAGE__,\
                                       __ADC_DATA__,\
                                       __ADC_RESOLUTION__) \
__LL_ADC_CALC_DATA_TO_VOLTAGE((__VREFANALOG_VOLTAGE__),\
                              (__ADC_DATA__),\
                              (__ADC_RESOLUTION__))

   
                                                                      
                                                                      
                              
                                                          
                                                                      
                                                                         
                                   
                                                                       
                                              
                                                                                
                                                           
                                                                        
                                               
                                                                  
                                           
                                                                         
                                                                        
                                                                                 
                                        
                                        
                                       
                                       
                                               
    
#define __HAL_ADC_CALC_VREFANALOG_VOLTAGE(__VREFINT_ADC_DATA__,\
                                          __ADC_RESOLUTION__) \
__LL_ADC_CALC_VREFANALOG_VOLTAGE((__VREFINT_ADC_DATA__),\
                                 (__ADC_RESOLUTION__))

   
                                                                            
                                                                    
                                                                      
                                                                      
                                
                                                    
                                                              
                                                                
                                                                            
                                                  
                                                              
                                                                    
                                                                     
                                                                    
                                                                     
                                                                         
                                                               
                                                                      
                                                                             
                                                           
                                                                                  
                                                                              
                                                                 
                                                                      
                                                                             
                                                                         
                                                                        
                                                   
                                                                        
                               
                                                                  
                                           
                                                                       
                                                                   
                                                                             
                                                                                
                                                                     
                                                              
                                        
                                        
                                       
                                       
                                              
    
#define __HAL_ADC_CALC_TEMPERATURE(__VREFANALOG_VOLTAGE__,\
                                   __TEMPSENSOR_ADC_DATA__,\
                                   __ADC_RESOLUTION__) \
__LL_ADC_CALC_TEMPERATURE((__VREFANALOG_VOLTAGE__),\
                          (__TEMPSENSOR_ADC_DATA__),\
                          (__ADC_RESOLUTION__))

   
                                                                            
                                                                    
                                                                  
                                        
                                
                                                                                
                                                   
                                                                                 
                                                           
                                                              
                                                               
                                                                         
                                                                      
                                                                               
                                                                           
                                              
                                                                              
                                                                                    
                                                                        
                                                                   
                                                                              
                                                                 
                                                                      
                                                                             
                                                                         
                                                                          
                                                                              
                                                                          
                                                                                                        
                                                                 
                                                                                                       
                                                                                                              
                                                                                                         
                                                                                                
                                                                      
                                                                                                                     
                                                                                                             
                                                                                             
                                                                                                                   
                                                                                                                        
                                                              
                                        
                                        
                                       
                                       
                                              
    
#define __HAL_ADC_CALC_TEMPERATURE_TYP_PARAMS(__TEMPSENSOR_TYP_AVGSLOPE__,\
                                              __TEMPSENSOR_TYP_CALX_V__,\
                                              __TEMPSENSOR_CALX_TEMP__,\
                                              __VREFANALOG_VOLTAGE__,\
                                              __TEMPSENSOR_ADC_DATA__,\
                                              __ADC_RESOLUTION__) \
__LL_ADC_CALC_TEMPERATURE_TYP_PARAMS((__TEMPSENSOR_TYP_AVGSLOPE__),\
                                     (__TEMPSENSOR_TYP_CALX_V__),\
                                     (__TEMPSENSOR_CALX_TEMP__),\
                                     (__VREFANALOG_VOLTAGE__),\
                                     (__TEMPSENSOR_ADC_DATA__),\
                                     (__ADC_RESOLUTION__))

   
      
    

   
      
    

                                     
#include "stm32l4xx_hal_adc_ex.h"

                                                                                
                                      
      
    

                                             
                                                        
      
    
                                                                                
HAL_StatusTypeDef       HAL_ADC_Init(ADC_HandleTypeDef *hadc);
HAL_StatusTypeDef       HAL_ADC_DeInit(ADC_HandleTypeDef *hadc);
void                    HAL_ADC_MspInit(ADC_HandleTypeDef *hadc);
void                    HAL_ADC_MspDeInit(ADC_HandleTypeDef *hadc);

#if (USE_HAL_ADC_REGISTER_CALLBACKS == 1)
                                                                                
HAL_StatusTypeDef HAL_ADC_RegisterCallback(ADC_HandleTypeDef *hadc, HAL_ADC_CallbackIDTypeDef CallbackID,
                                           pADC_CallbackTypeDef pCallback);
HAL_StatusTypeDef HAL_ADC_UnRegisterCallback(ADC_HandleTypeDef *hadc, HAL_ADC_CallbackIDTypeDef CallbackID);
#endif                                     
   
      
    

                                             
                                    
      
    
                                                                                 

                            
HAL_StatusTypeDef       HAL_ADC_Start(ADC_HandleTypeDef *hadc);
HAL_StatusTypeDef       HAL_ADC_Stop(ADC_HandleTypeDef *hadc);
HAL_StatusTypeDef       HAL_ADC_PollForConversion(ADC_HandleTypeDef *hadc, uint32_t Timeout);
HAL_StatusTypeDef       HAL_ADC_PollForEvent(ADC_HandleTypeDef *hadc, uint32_t EventType, uint32_t Timeout);

                                     
HAL_StatusTypeDef       HAL_ADC_Start_IT(ADC_HandleTypeDef *hadc);
HAL_StatusTypeDef       HAL_ADC_Stop_IT(ADC_HandleTypeDef *hadc);

                            
HAL_StatusTypeDef       HAL_ADC_Start_DMA(ADC_HandleTypeDef *hadc, uint32_t *pData, uint32_t Length);
HAL_StatusTypeDef       HAL_ADC_Stop_DMA(ADC_HandleTypeDef *hadc);

                                                                                    
uint32_t                HAL_ADC_GetValue(const ADC_HandleTypeDef *hadc);

                                                                                    
void                    HAL_ADC_IRQHandler(ADC_HandleTypeDef *hadc);
void                    HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef *hadc);
void                    HAL_ADC_ConvHalfCpltCallback(ADC_HandleTypeDef *hadc);
void                    HAL_ADC_LevelOutOfWindowCallback(ADC_HandleTypeDef *hadc);
void                    HAL_ADC_ErrorCallback(ADC_HandleTypeDef *hadc);
   
      
    

                                                                          
                                           
      
    
                                                                                
HAL_StatusTypeDef       HAL_ADC_ConfigChannel(ADC_HandleTypeDef *hadc, const ADC_ChannelConfTypeDef *pConfig);
HAL_StatusTypeDef       HAL_ADC_AnalogWDGConfig(ADC_HandleTypeDef *hadc,
                                                const ADC_AnalogWDGConfTypeDef *pAnalogWDGConfig);

   
      
    

                                                                                
                                             
      
    
uint32_t                HAL_ADC_GetState(const ADC_HandleTypeDef *hadc);
uint32_t                HAL_ADC_GetError(const ADC_HandleTypeDef *hadc);

   
      
    

   
      
    

                                                                                
                                                           
      
    
HAL_StatusTypeDef ADC_ConversionStop(ADC_HandleTypeDef *hadc, uint32_t ConversionGroup);
HAL_StatusTypeDef ADC_Enable(ADC_HandleTypeDef *hadc);
HAL_StatusTypeDef ADC_Disable(ADC_HandleTypeDef *hadc);
void ADC_DMAConvCplt(DMA_HandleTypeDef *hdma);
void ADC_DMAHalfConvCplt(DMA_HandleTypeDef *hdma);
void ADC_DMAError(DMA_HandleTypeDef *hdma);

   
      
    

   
      
    

   
      
    

#ifdef __cplusplus
}
#endif


#endif                          
