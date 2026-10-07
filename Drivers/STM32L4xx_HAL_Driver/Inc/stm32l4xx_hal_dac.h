/**
  ******************************************************************************
  * @file    stm32l4xx_hal_dac.h
  * @author  MCD Application Team
  * @brief   Header file of DAC HAL module.
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

                                                                                
#ifndef STM32L4xx_HAL_DAC_H
#define STM32L4xx_HAL_DAC_H

#ifdef __cplusplus
 extern "C" {
#endif

                                    
      
    

                                                                                
#include "stm32l4xx_hal_def.h"

#if defined(DAC1)

                   
      
    

                                                                                

                                                   
      
    

   
                                           
    
typedef enum
{
  HAL_DAC_STATE_RESET             = 0x00U,                                              
  HAL_DAC_STATE_READY             = 0x01U,                                              
  HAL_DAC_STATE_BUSY              = 0x02U,                                              
  HAL_DAC_STATE_TIMEOUT           = 0x03U,                                              
  HAL_DAC_STATE_ERROR             = 0x04U                                               

} HAL_DAC_StateTypeDef;

   
                                           
    
#if (USE_HAL_DAC_REGISTER_CALLBACKS == 1)
typedef struct __DAC_HandleTypeDef
#else
typedef struct
#endif
{
  DAC_TypeDef                 *Instance;                                              

  __IO HAL_DAC_StateTypeDef   State;                                                  

  HAL_LockTypeDef             Lock;                                                   

  DMA_HandleTypeDef           *DMA_Handle1;                                           

  DMA_HandleTypeDef           *DMA_Handle2;                                           

  __IO uint32_t               ErrorCode;                                              

#if (USE_HAL_DAC_REGISTER_CALLBACKS == 1)
  void (* ConvCpltCallbackCh1)            (struct __DAC_HandleTypeDef *hdac);
  void (* ConvHalfCpltCallbackCh1)        (struct __DAC_HandleTypeDef *hdac);
  void (* ErrorCallbackCh1)               (struct __DAC_HandleTypeDef *hdac);
  void (* DMAUnderrunCallbackCh1)         (struct __DAC_HandleTypeDef *hdac);
  void (* ConvCpltCallbackCh2)            (struct __DAC_HandleTypeDef *hdac);
  void (* ConvHalfCpltCallbackCh2)        (struct __DAC_HandleTypeDef *hdac);
  void (* ErrorCallbackCh2)               (struct __DAC_HandleTypeDef *hdac);
  void (* DMAUnderrunCallbackCh2)         (struct __DAC_HandleTypeDef *hdac);

  void (* MspInitCallback)                (struct __DAC_HandleTypeDef *hdac);
  void (* MspDeInitCallback )             (struct __DAC_HandleTypeDef *hdac);
#endif                                     

} DAC_HandleTypeDef;

   
                                                                           
    
typedef struct
{
  uint32_t DAC_SampleTime ;                                                                  
                                                                                                                    
                                                                                                                     

  uint32_t DAC_HoldTime ;                                                                 
                                                                                                                    
                                                                                                                     

  uint32_t DAC_RefreshTime ;                                                                 
                                                                                                                    
                                                                                                                    
} DAC_SampleAndHoldConfTypeDef;

   
                                                                   
    
typedef struct
{
#if defined (STM32L4P5xx) || defined (STM32L4Q5xx) || defined (STM32L4R5xx) || defined (STM32L4R7xx) || defined (STM32L4R9xx) || defined (STM32L4S5xx) || defined (STM32L4S7xx) || defined(STM32L4S9xx)
  uint32_t DAC_HighFrequency;                                                       
                                                                                                        
#endif                                                                                                      

  uint32_t DAC_SampleAndHold;                                                
                                                                                                        

  uint32_t DAC_Trigger;                                                                                   
                                                                                                            

  uint32_t DAC_OutputBuffer;                                                                                         
                                                                                                         

  uint32_t DAC_ConnectOnChipPeripheral ;                                                                                  
                                                                                                                  

  uint32_t DAC_UserTrimming;                                             
                                                                                                     
                                                                                                    

  uint32_t DAC_TrimmingValue;                                                     
                                                                                                
                                                                                                                        

  DAC_SampleAndHoldConfTypeDef  DAC_SampleAndHoldConfig;                                  

} DAC_ChannelConfTypeDef;

#if (USE_HAL_DAC_REGISTER_CALLBACKS == 1)
   
                                                      
    
typedef enum
{
  HAL_DAC_CH1_COMPLETE_CB_ID                 = 0x00U,                                           
  HAL_DAC_CH1_HALF_COMPLETE_CB_ID            = 0x01U,                                           
  HAL_DAC_CH1_ERROR_ID                       = 0x02U,                                           
  HAL_DAC_CH1_UNDERRUN_CB_ID                 = 0x03U,                                           
  HAL_DAC_CH2_COMPLETE_CB_ID                 = 0x04U,                                           
  HAL_DAC_CH2_HALF_COMPLETE_CB_ID            = 0x05U,                                           
  HAL_DAC_CH2_ERROR_ID                       = 0x06U,                                           
  HAL_DAC_CH2_UNDERRUN_CB_ID                 = 0x07U,                                           
  HAL_DAC_MSPINIT_CB_ID                      = 0x08U,                                           
  HAL_DAC_MSPDEINIT_CB_ID                    = 0x09U,                                           
  HAL_DAC_ALL_CB_ID                          = 0x0AU                                            
} HAL_DAC_CallbackIDTypeDef;

   
                                               
    
typedef void (*pDAC_CallbackTypeDef)(DAC_HandleTypeDef *hdac);
#endif                                     

   
      
    

                                                                                

                                                           
      
    

                                           
      
    
#define  HAL_DAC_ERROR_NONE              0x00U                                             
#define  HAL_DAC_ERROR_DMAUNDERRUNCH1    0x01U                                             
#define  HAL_DAC_ERROR_DMAUNDERRUNCH2    0x02U                                             
#define  HAL_DAC_ERROR_DMA               0x04U                                             
#define  HAL_DAC_ERROR_TIMEOUT           0x08U                                             
#if (USE_HAL_DAC_REGISTER_CALLBACKS == 1)
#define HAL_DAC_ERROR_INVALID_CALLBACK   0x10U                                             
#endif                                     

   
      
    

                                                         
      
    

#if defined (STM32L431xx) || defined (STM32L432xx) || defined (STM32L433xx) || defined (STM32L442xx) || defined (STM32L443xx)
#define DAC_TRIGGER_NONE        0x00000000U                                                                                                
                                                                                                                                     
#define DAC_TRIGGER_T2_TRGO     (DAC_CR_TSEL1_2                  | DAC_CR_TEN1)                                                                           
#define DAC_TRIGGER_T6_TRGO     (                                  DAC_CR_TEN1)                                                                           
#define DAC_TRIGGER_T7_TRGO     (                 DAC_CR_TSEL1_1 | DAC_CR_TEN1)                                                                           
#define DAC_TRIGGER_EXT_IT9     (DAC_CR_TSEL1_2 | DAC_CR_TSEL1_1 | DAC_CR_TEN1)                                                                                  
#define DAC_TRIGGER_SOFTWARE    (                 DAC_CR_TSEL1   | DAC_CR_TEN1)                                                                
#endif                                                                      

#if defined (STM32L451xx) || defined (STM32L452xx) || defined (STM32L462xx)
#define DAC_TRIGGER_NONE        0x00000000U                                                                                                
                                                                                                                                     
#define DAC_TRIGGER_T2_TRGO     (DAC_CR_TSEL1_2                  | DAC_CR_TEN1)                                                                           
#define DAC_TRIGGER_T6_TRGO     (                                  DAC_CR_TEN1)                                                                           
#define DAC_TRIGGER_EXT_IT9     (DAC_CR_TSEL1_2 | DAC_CR_TSEL1_1 | DAC_CR_TEN1)                                                                                  
#define DAC_TRIGGER_SOFTWARE    (                   DAC_CR_TSEL1 | DAC_CR_TEN1)                                                                
#endif                                                                      

#if defined (STM32L471xx) || defined (STM32L475xx) || defined (STM32L476xx) || defined (STM32L485xx) || defined (STM32L486xx) || defined (STM32L496xx) || defined (STM32L4A6xx)
#define DAC_TRIGGER_NONE        0x00000000U                                                                                                                
                                                                                                                                                     
#define DAC_TRIGGER_T2_TRGO     (DAC_CR_TSEL1_2                                   | DAC_CR_TEN1)                                                                          
#define DAC_TRIGGER_T4_TRGO     (DAC_CR_TSEL1_2 | DAC_CR_TSEL1_0                  | DAC_CR_TEN1)                                                                          
#define DAC_TRIGGER_T5_TRGO     (                 DAC_CR_TSEL1_1 | DAC_CR_TSEL1_0 | DAC_CR_TEN1)                                                                          
#define DAC_TRIGGER_T6_TRGO     (                                                   DAC_CR_TEN1)                                                                          
#define DAC_TRIGGER_T7_TRGO     (                 DAC_CR_TSEL1_1                  | DAC_CR_TEN1)                                                                          
#define DAC_TRIGGER_T8_TRGO     (                                  DAC_CR_TSEL1_0 | DAC_CR_TEN1)                                                                          
#define DAC_TRIGGER_EXT_IT9     (DAC_CR_TSEL1_2 | DAC_CR_TSEL1_1                  | DAC_CR_TEN1)                                                                                 
#define DAC_TRIGGER_SOFTWARE    (                                  DAC_CR_TSEL1   | DAC_CR_TEN1)                                                               
#endif                                                                                             


#if defined (STM32L4P5xx) || defined (STM32L4Q5xx) || defined (STM32L4R5xx) || defined (STM32L4R7xx) || defined (STM32L4R9xx) || defined (STM32L4S5xx) || defined (STM32L4S7xx) || defined(STM32L4S9xx)
#define DAC_TRIGGER_NONE        0x00000000U                                                                                                                                                                                 
#define DAC_TRIGGER_SOFTWARE    (                                                                    DAC_CR_TEN1)                                                               
#define DAC_TRIGGER_T1_TRGO     (                                                   DAC_CR_TSEL1_0 | DAC_CR_TEN1)                                                                           
#define DAC_TRIGGER_T2_TRGO     (                                DAC_CR_TSEL1_1                    | DAC_CR_TEN1)                                                                          
#define DAC_TRIGGER_T4_TRGO     (                                DAC_CR_TSEL1_1   | DAC_CR_TSEL1_0 | DAC_CR_TEN1)                                                                          
#define DAC_TRIGGER_T5_TRGO     (                 DAC_CR_TSEL1_2                                   | DAC_CR_TEN1)                                                                          
#define DAC_TRIGGER_T6_TRGO     (                 DAC_CR_TSEL1_2                  | DAC_CR_TSEL1_0 | DAC_CR_TEN1)                                                                          
#define DAC_TRIGGER_T7_TRGO     (                 DAC_CR_TSEL1_2 | DAC_CR_TSEL1_1                  | DAC_CR_TEN1)                                                                          
#define DAC_TRIGGER_T8_TRGO     (                 DAC_CR_TSEL1_2 | DAC_CR_TSEL1_1 | DAC_CR_TSEL1_0 | DAC_CR_TEN1)                                                                          
#define DAC_TRIGGER_T15_TRGO    (DAC_CR_TSEL1_3                                                    | DAC_CR_TEN1)                                                                           
#define DAC_TRIGGER_LPTIM1_OUT  (DAC_CR_TSEL1_3 |                  DAC_CR_TSEL1_1 | DAC_CR_TSEL1_0 | DAC_CR_TEN1)                                                                                
#define DAC_TRIGGER_LPTIM2_OUT  (DAC_CR_TSEL1_3 | DAC_CR_TSEL1_2                                   | DAC_CR_TEN1)                                                                                
#define DAC_TRIGGER_EXT_IT9     (DAC_CR_TSEL1_3 | DAC_CR_TSEL1_2                  | DAC_CR_TSEL1_0 | DAC_CR_TEN1)                                                                                 

#endif                                                                                                       


   
      
    

                                                 
      
    
#define DAC_OUTPUTBUFFER_ENABLE            0x00000000U
#define DAC_OUTPUTBUFFER_DISABLE           (DAC_MCR_MODE1_1)

   
      
    

                                                         
      
    
#define DAC_CHANNEL_1                      0x00000000U
#if defined (STM32L431xx) || defined (STM32L432xx) || defined (STM32L433xx) || defined (STM32L442xx) || defined (STM32L443xx) || \
    defined (STM32L471xx) || defined (STM32L475xx) || defined (STM32L476xx) || defined (STM32L485xx) || defined (STM32L486xx) || defined (STM32L496xx) || defined (STM32L4A6xx) || \
    defined (STM32L4P5xx) || defined (STM32L4Q5xx) || \
    defined (STM32L4R5xx) || defined (STM32L4R7xx) || defined (STM32L4R9xx) || defined (STM32L4S5xx) || defined (STM32L4S7xx) || defined(STM32L4S9xx)
#define DAC_CHANNEL_2                      0x00000010U
#endif                                                                                           
                                                                                                 
                                                                                                 
                                                                                                 

   
      
    

                                                   
      
    
#define DAC_ALIGN_12B_R                    0x00000000U
#define DAC_ALIGN_12B_L                    0x00000004U
#define DAC_ALIGN_8B_R                     0x00000008U

   
      
    

                                                       
      
    
#define DAC_FLAG_DMAUDR1                   (DAC_SR_DMAUDR1)
#define DAC_FLAG_DMAUDR2                   (DAC_SR_DMAUDR2)

   
      
    

                                                  
      
    
#define DAC_IT_DMAUDR1                   (DAC_SR_DMAUDR1)
#define DAC_IT_DMAUDR2                   (DAC_SR_DMAUDR2)

   
      
    

                                                                     
      
    
#define DAC_CHIPCONNECT_DISABLE    0x00000000U
#define DAC_CHIPCONNECT_ENABLE     (DAC_MCR_MODE1_0)

   
      
    

                                                  
      
    
#define DAC_TRIMMING_FACTORY        0x00000000U                                   
#define DAC_TRIMMING_USER           0x00000001U                                

   
      
    

                                              
      
    
#define DAC_SAMPLEANDHOLD_DISABLE     0x00000000U
#define DAC_SAMPLEANDHOLD_ENABLE      (DAC_MCR_MODE1_2)

   
      
    
#if defined (STM32L4P5xx) || defined (STM32L4Q5xx) || defined (STM32L4R5xx) || defined (STM32L4R7xx) || defined (STM32L4R9xx) || defined (STM32L4S5xx) || defined (STM32L4S7xx) || defined(STM32L4S9xx)
                                                                 
      
    
#define DAC_HIGH_FREQUENCY_INTERFACE_MODE_DISABLE        0x00000000U                                                      
#define DAC_HIGH_FREQUENCY_INTERFACE_MODE_ABOVE_80MHZ    (DAC_CR_HFSEL)                                                                          
#define DAC_HIGH_FREQUENCY_INTERFACE_MODE_AUTOMATIC      0x00000002U                                                       

   
      
    
#endif                                                                                                      

   
      
    

                                                                                

                                                     
      
    

                                  
                                                
                
    
#if (USE_HAL_DAC_REGISTER_CALLBACKS == 1)
#define __HAL_DAC_RESET_HANDLE_STATE(__HANDLE__) do {                                                        \
                                                      (__HANDLE__)->State             = HAL_DAC_STATE_RESET; \
                                                      (__HANDLE__)->MspInitCallback   = NULL;                \
                                                      (__HANDLE__)->MspDeInitCallback = NULL;                \
                                                               } while(0)
#else
#define __HAL_DAC_RESET_HANDLE_STATE(__HANDLE__) ((__HANDLE__)->State = HAL_DAC_STATE_RESET)
#endif                                     

                                  
                                                
                                                     
                
    
#define __HAL_DAC_ENABLE(__HANDLE__, __DAC_Channel__) \
((__HANDLE__)->Instance->CR |=  (DAC_CR_EN1 << ((__DAC_Channel__) & 0x10UL)))

                                   
                                               
                                                      
                
    
#define __HAL_DAC_DISABLE(__HANDLE__, __DAC_Channel__) \
((__HANDLE__)->Instance->CR &=  ~(DAC_CR_EN1 << ((__DAC_Channel__) & 0x10UL)))

                                 
                                                     
                
    
#define DAC_DHR12R1_ALIGNMENT(__ALIGNMENT__) (0x00000008U + (__ALIGNMENT__))

                                  
                                                     
                
    
#define DAC_DHR12R2_ALIGNMENT(__ALIGNMENT__) (0x00000014U + (__ALIGNMENT__))

                                  
                                                     
                
    
#define DAC_DHR12RD_ALIGNMENT(__ALIGNMENT__) (0x00000020U + (__ALIGNMENT__))

                                    
                                               
                                                      
                                                                           
                                                                        
                                                                        
                
    
#define __HAL_DAC_ENABLE_IT(__HANDLE__, __INTERRUPT__) (((__HANDLE__)->Instance->CR) |= (__INTERRUPT__))

                                     
                                               
                                                      
                                                                           
                                                                        
                                                                        
                
    
#define __HAL_DAC_DISABLE_IT(__HANDLE__, __INTERRUPT__) (((__HANDLE__)->Instance->CR) &= ~(__INTERRUPT__))

                                                                               
                                
                                                      
                                                                           
                                                                        
                                                                        
                                                
    
#define __HAL_DAC_GET_IT_SOURCE(__HANDLE__, __INTERRUPT__) (((__HANDLE__)->Instance->CR & (__INTERRUPT__)) == (__INTERRUPT__))

                                               
                                                
                                                   
                                                                           
                                                                     
                                                                     
                
    
#define __HAL_DAC_GET_FLAG(__HANDLE__, __FLAG__) ((((__HANDLE__)->Instance->SR) & (__FLAG__)) == (__FLAG__))

                                 
                                                
                                                     
                                                                           
                                                                     
                                                                     
                
    
#define __HAL_DAC_CLEAR_FLAG(__HANDLE__, __FLAG__) (((__HANDLE__)->Instance->SR) = (__FLAG__))

   
      
    

                                                                                

                                                   
      
    
#define IS_DAC_OUTPUT_BUFFER_STATE(STATE) (((STATE) == DAC_OUTPUTBUFFER_ENABLE) || \
                                           ((STATE) == DAC_OUTPUTBUFFER_DISABLE))

#if defined (STM32L431xx) || defined (STM32L432xx) || defined (STM32L433xx) || defined (STM32L442xx) || defined (STM32L443xx) || \
    defined (STM32L471xx) || defined (STM32L475xx) || defined (STM32L476xx) || defined (STM32L485xx) || defined (STM32L486xx) || defined (STM32L496xx) || defined (STM32L4A6xx) || \
    defined (STM32L4P5xx) || defined (STM32L4Q5xx) || \
    defined (STM32L4R5xx) || defined (STM32L4R7xx) || defined (STM32L4R9xx) || defined (STM32L4S5xx) || defined (STM32L4S7xx) || defined(STM32L4S9xx)
#define IS_DAC_CHANNEL(CHANNEL) (((CHANNEL) == DAC_CHANNEL_1) || \
                                ((CHANNEL) == DAC_CHANNEL_2))
#endif                                                                                           
                                                                                                 
                                                                                                 
                                                                                                 

#if defined (STM32L451xx) || defined (STM32L452xx) || defined (STM32L462xx)
#define IS_DAC_CHANNEL(CHANNEL) ((CHANNEL) == DAC_CHANNEL_1)
#endif                                          

#define IS_DAC_ALIGN(ALIGN) (((ALIGN) == DAC_ALIGN_12B_R) || \
                             ((ALIGN) == DAC_ALIGN_12B_L) || \
                             ((ALIGN) == DAC_ALIGN_8B_R))

#define IS_DAC_DATA(DATA) ((DATA) <= 0xFFF0U)

#define IS_DAC_REFRESHTIME(TIME)   ((TIME) <= 0x000000FFU)

   
      
    

                                     
#include "stm32l4xx_hal_dac_ex.h"

                                                                                

                                      
      
    

                                             
      
    
                                                                                
HAL_StatusTypeDef HAL_DAC_Init(DAC_HandleTypeDef *hdac);
HAL_StatusTypeDef HAL_DAC_DeInit(DAC_HandleTypeDef *hdac);
void HAL_DAC_MspInit(DAC_HandleTypeDef *hdac);
void HAL_DAC_MspDeInit(DAC_HandleTypeDef *hdac);

   
      
    

                                             
     
   
                                                                                
HAL_StatusTypeDef HAL_DAC_Start(DAC_HandleTypeDef *hdac, uint32_t Channel);
HAL_StatusTypeDef HAL_DAC_Stop(DAC_HandleTypeDef *hdac, uint32_t Channel);
HAL_StatusTypeDef HAL_DAC_Start_DMA(DAC_HandleTypeDef *hdac, uint32_t Channel, uint32_t *pData, uint32_t Length,
                                    uint32_t Alignment);
HAL_StatusTypeDef HAL_DAC_Stop_DMA(DAC_HandleTypeDef *hdac, uint32_t Channel);

void HAL_DAC_IRQHandler(DAC_HandleTypeDef *hdac);

HAL_StatusTypeDef HAL_DAC_SetValue(DAC_HandleTypeDef *hdac, uint32_t Channel, uint32_t Alignment, uint32_t Data);

void HAL_DAC_ConvCpltCallbackCh1(DAC_HandleTypeDef *hdac);
void HAL_DAC_ConvHalfCpltCallbackCh1(DAC_HandleTypeDef *hdac);
void HAL_DAC_ErrorCallbackCh1(DAC_HandleTypeDef *hdac);
void HAL_DAC_DMAUnderrunCallbackCh1(DAC_HandleTypeDef *hdac);

#if (USE_HAL_DAC_REGISTER_CALLBACKS == 1)
                                            
HAL_StatusTypeDef     HAL_DAC_RegisterCallback(DAC_HandleTypeDef *hdac, HAL_DAC_CallbackIDTypeDef CallbackID,
                                               pDAC_CallbackTypeDef pCallback);
HAL_StatusTypeDef     HAL_DAC_UnRegisterCallback(DAC_HandleTypeDef *hdac, HAL_DAC_CallbackIDTypeDef CallbackID);
#endif                                     

   
      
    

                                             
      
    
                                                                                
uint32_t HAL_DAC_GetValue(DAC_HandleTypeDef *hdac, uint32_t Channel);

HAL_StatusTypeDef HAL_DAC_ConfigChannel(DAC_HandleTypeDef *hdac, DAC_ChannelConfTypeDef *sConfig, uint32_t Channel);
   
      
    

                                             
      
    
                                                                                
HAL_DAC_StateTypeDef HAL_DAC_GetState(DAC_HandleTypeDef *hdac);
uint32_t HAL_DAC_GetError(DAC_HandleTypeDef *hdac);

   
      
    

   
      
    

                                                         
      
    
void DAC_DMAConvCpltCh1(DMA_HandleTypeDef *hdma);
void DAC_DMAErrorCh1(DMA_HandleTypeDef *hdma);
void DAC_DMAHalfConvCpltCh1(DMA_HandleTypeDef *hdma);
   
      
    

   
      
    

#endif           

   
      
    

#ifdef __cplusplus
}
#endif


#endif                         


