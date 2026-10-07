/**
  ******************************************************************************
  * @file    stm32l4xx_hal_tim_ex.h
  * @author  MCD Application Team
  * @brief   Header file of TIM HAL Extended module.
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

                                                                                
#ifndef STM32L4xx_HAL_TIM_EX_H
#define STM32L4xx_HAL_TIM_EX_H

#ifdef __cplusplus
extern "C" {
#endif

                                                                                
#include "stm32l4xx_hal_def.h"

                                    
      
    

                     
      
    

                                                                                
                                                              
      
    

   
                                                              
    

typedef struct
{
  uint32_t IC1Polarity;                                                            
                                                                                                        

  uint32_t IC1Prescaler;                                                   
                                                                                                         

  uint32_t IC1Filter;                                                   
                                                                                                                

  uint32_t Commutation_Delay;                                                                                 
                                                                                                                      
} TIM_HallSensor_InitTypeDef;

   
                                                
    
typedef struct
{
  uint32_t Source;                                                            
                                                                                                 
  uint32_t Enable;                                                                         
                                                                                                        
  uint32_t Polarity;                                                      
                                                                                                       
                                                                                                                    
} TIMEx_BreakInputConfigTypeDef;

   
      
    
                                                                                

                                                                                
                                                                      
      
    

                                                
      
    
#define TIM_TIM1_ETR_ADC1_NONE      0x00000000U                                                                                                        
#define TIM_TIM1_ETR_ADC1_AWD1      TIM1_OR1_ETR_ADC1_RMP_0                                                                         
#define TIM_TIM1_ETR_ADC1_AWD2      TIM1_OR1_ETR_ADC1_RMP_1                                                                         
#define TIM_TIM1_ETR_ADC1_AWD3      (TIM1_OR1_ETR_ADC1_RMP_1 | TIM1_OR1_ETR_ADC1_RMP_0)                                             
#if defined (ADC3)
#define TIM_TIM1_ETR_ADC3_NONE      0x00000000U                                                                                                        
#define TIM_TIM1_ETR_ADC3_AWD1      TIM1_OR1_ETR_ADC3_RMP_0                                                                         
#define TIM_TIM1_ETR_ADC3_AWD2      TIM1_OR1_ETR_ADC3_RMP_1                                                                         
#define TIM_TIM1_ETR_ADC3_AWD3      (TIM1_OR1_ETR_ADC3_RMP_1 | TIM1_OR1_ETR_ADC3_RMP_0)                                             
#endif           
#define TIM_TIM1_TI1_GPIO           0x00000000U                                                                                
#define TIM_TIM1_TI1_COMP1          TIM1_OR1_TI1_RMP                                                                            
#define TIM_TIM1_ETR_GPIO           0x00000000U                                                                                
#define TIM_TIM1_ETR_COMP1          TIM1_OR2_ETRSEL_0                                                                                  
#if defined(COMP2)
#define TIM_TIM1_ETR_COMP2          TIM1_OR2_ETRSEL_1                                                                                  
#endif            

#if defined (USB_OTG_FS)
#define TIM_TIM2_ITR1_TIM8_TRGO     0x00000000U                                                                                      
#define TIM_TIM2_ITR1_OTG_FS_SOF    TIM2_OR1_ITR1_RMP                                                                                 
#else
#if defined(STM32L471xx)
#define TIM_TIM2_ITR1_TIM8_TRGO     0x00000000U                                                                                      
#define TIM_TIM2_ITR1_NONE          TIM2_OR1_ITR1_RMP                                                                             
#else
#define TIM_TIM2_ITR1_NONE          0x00000000U                                                                                   
#define TIM_TIM2_ITR1_USB_SOF       TIM2_OR1_ITR1_RMP                                                                              
#endif                  
#endif                 
#define TIM_TIM2_ETR_GPIO           0x00000000U                                                                                
#define TIM_TIM2_ETR_LSE            TIM2_OR1_ETR1_RMP                                                                         
#define TIM_TIM2_ETR_COMP1          TIM2_OR2_ETRSEL_0                                                                                  
#if defined(COMP2)
#define TIM_TIM2_ETR_COMP2          TIM2_OR2_ETRSEL_1                                                                                  
#endif            
#define TIM_TIM2_TI4_GPIO           0x00000000U                                                                                
#define TIM_TIM2_TI4_COMP1          TIM2_OR1_TI4_RMP_0                                                                                 
#if defined(COMP2)
#define TIM_TIM2_TI4_COMP2          TIM2_OR1_TI4_RMP_1                                                                                 
#define TIM_TIM2_TI4_COMP1_COMP2    (TIM2_OR1_TI4_RMP_1| TIM2_OR1_TI4_RMP_0)                                                                                         
#endif            

#if defined (TIM3)
#define TIM_TIM3_TI1_GPIO           0x00000000U                                                                                
#define TIM_TIM3_TI1_COMP1          TIM3_OR1_TI1_RMP_0                                                                                 
#define TIM_TIM3_TI1_COMP2          TIM3_OR1_TI1_RMP_1                                                                                 
#define TIM_TIM3_TI1_COMP1_COMP2    (TIM3_OR1_TI1_RMP_1 | TIM3_OR1_TI1_RMP_0)                                                                                        
#define TIM_TIM3_ETR_GPIO           0x00000000U                                                                                
#define TIM_TIM3_ETR_COMP1          TIM3_OR2_ETRSEL_0                                                                                  
#endif           

#if defined (TIM8)
#if defined(ADC2) && defined(ADC3)
#define TIM_TIM8_ETR_ADC2_NONE      0x00000000U                                                                                                        
#define TIM_TIM8_ETR_ADC2_AWD1      TIM8_OR1_ETR_ADC2_RMP_0                                                                         
#define TIM_TIM8_ETR_ADC2_AWD2      TIM8_OR1_ETR_ADC2_RMP_1                                                                         
#define TIM_TIM8_ETR_ADC2_AWD3      (TIM8_OR1_ETR_ADC2_RMP_1 | TIM8_OR1_ETR_ADC2_RMP_0)                                             
#define TIM_TIM8_ETR_ADC3_NONE      0x00000000U                                                                                                        
#define TIM_TIM8_ETR_ADC3_AWD1      TIM8_OR1_ETR_ADC3_RMP_0                                                                         
#define TIM_TIM8_ETR_ADC3_AWD2      TIM8_OR1_ETR_ADC3_RMP_1                                                                         
#define TIM_TIM8_ETR_ADC3_AWD3      (TIM8_OR1_ETR_ADC3_RMP_1 | TIM8_OR1_ETR_ADC3_RMP_0)                                             
#endif                   

#define TIM_TIM8_TI1_GPIO           0x00000000U                                                                                
#define TIM_TIM8_TI1_COMP2          TIM8_OR1_TI1_RMP                                                                            
#define TIM_TIM8_ETR_GPIO           0x00000000U                                                                                
#define TIM_TIM8_ETR_COMP1          TIM8_OR2_ETRSEL_0                                                                                  
#define TIM_TIM8_ETR_COMP2          TIM8_OR2_ETRSEL_1                                                                                  
#endif           

#define TIM_TIM15_TI1_GPIO          0x00000000U                                                                                 
#define TIM_TIM15_TI1_LSE           TIM15_OR1_TI1_RMP                                                                          
#define TIM_TIM15_ENCODERMODE_NONE  0x00000000U                                                                 
#define TIM_TIM15_ENCODERMODE_TIM2  TIM15_OR1_ENCODER_MODE_0                                                                                                                 
#if defined (TIM3)
#define TIM_TIM15_ENCODERMODE_TIM3  TIM15_OR1_ENCODER_MODE_1                                                                                                                 
#endif           
#if defined (TIM4)
#define TIM_TIM15_ENCODERMODE_TIM4  (TIM15_OR1_ENCODER_MODE_1 | TIM15_OR1_ENCODER_MODE_0)                                                                                    
#endif           

#define TIM_TIM16_TI1_GPIO          0x00000000U                                                                                 
#define TIM_TIM16_TI1_LSI           TIM16_OR1_TI1_RMP_0                                                                        
#define TIM_TIM16_TI1_LSE           TIM16_OR1_TI1_RMP_1                                                                        
#define TIM_TIM16_TI1_RTC           (TIM16_OR1_TI1_RMP_1 | TIM16_OR1_TI1_RMP_0)                                                                 
#if defined (TIM16_OR1_TI1_RMP_2)
#define TIM_TIM16_TI1_MSI           TIM16_OR1_TI1_RMP_2                                                                        
#define TIM_TIM16_TI1_HSE_32        (TIM16_OR1_TI1_RMP_2 | TIM16_OR1_TI1_RMP_0)                                                       
#define TIM_TIM16_TI1_MCO           (TIM16_OR1_TI1_RMP_2 | TIM16_OR1_TI1_RMP_1)                                                
#endif                          

#if defined (TIM17)
#define TIM_TIM17_TI1_GPIO          0x00000000U                                                                                 
#define TIM_TIM17_TI1_MSI           TIM17_OR1_TI1_RMP_0                                                                        
#define TIM_TIM17_TI1_HSE_32        TIM17_OR1_TI1_RMP_1                                                                               
#define TIM_TIM17_TI1_MCO           (TIM17_OR1_TI1_RMP_1 | TIM17_OR1_TI1_RMP_0)                                                
#endif            
   
      
    

                                                        
      
    
#define TIM_BREAKINPUT_BRK     0x00000001U                                                                
#define TIM_BREAKINPUT_BRK2    0x00000002U                                                                
   
      
    

                                                                      
      
    
#define TIM_BREAKINPUTSOURCE_BKIN     0x00000001U                                                                                              
#define TIM_BREAKINPUTSOURCE_COMP1    0x00000002U                                                                                       
#define TIM_BREAKINPUTSOURCE_COMP2    0x00000004U                                                                                       
#if defined (DFSDM1_Channel0)
#define TIM_BREAKINPUTSOURCE_DFSDM1   0x00000008U                                                                                                                          
#endif                      
   
      
    

                                                                                      
      
    
#define TIM_BREAKINPUTSOURCE_DISABLE     0x00000000U                                                                  
#define TIM_BREAKINPUTSOURCE_ENABLE      0x00000001U                                                                 
   
      
    

                                                                                 
      
    
#define TIM_BREAKINPUTSOURCE_POLARITY_LOW     0x00000001U                                                               
#define TIM_BREAKINPUTSOURCE_POLARITY_HIGH    0x00000000U                                                                
   
      
    

   
      
    
                                                                                

                                                                                
                                                                
      
    

   
      
    
                                                                                

                                                                                
                                                              
      
    
#define IS_TIM_REMAP(__REMAP__)    (((__REMAP__) <= (uint32_t)0x0001C01F))

#define IS_TIM_BREAKINPUT(__BREAKINPUT__)  (((__BREAKINPUT__) == TIM_BREAKINPUT_BRK)  || \
                                            ((__BREAKINPUT__) == TIM_BREAKINPUT_BRK2))

#if defined (DFSDM1_Channel0)
#define IS_TIM_BREAKINPUTSOURCE(__SOURCE__)  (((__SOURCE__) == TIM_BREAKINPUTSOURCE_BKIN)  || \
                                              ((__SOURCE__) == TIM_BREAKINPUTSOURCE_COMP1) || \
                                              ((__SOURCE__) == TIM_BREAKINPUTSOURCE_COMP2) || \
                                              ((__SOURCE__) == TIM_BREAKINPUTSOURCE_DFSDM1))
#else
#define IS_TIM_BREAKINPUTSOURCE(__SOURCE__)  (((__SOURCE__) == TIM_BREAKINPUTSOURCE_BKIN)  || \
                                              ((__SOURCE__) == TIM_BREAKINPUTSOURCE_COMP1) || \
                                              ((__SOURCE__) == TIM_BREAKINPUTSOURCE_COMP2))
#endif                      

#define IS_TIM_BREAKINPUTSOURCE_STATE(__STATE__)  (((__STATE__) == TIM_BREAKINPUTSOURCE_DISABLE)  || \
                                                   ((__STATE__) == TIM_BREAKINPUTSOURCE_ENABLE))

#define IS_TIM_BREAKINPUTSOURCE_POLARITY(__POLARITY__)  (((__POLARITY__) == TIM_BREAKINPUTSOURCE_POLARITY_LOW)  || \
                                                         ((__POLARITY__) == TIM_BREAKINPUTSOURCE_POLARITY_HIGH))

   
      
    
                                                                                

                                                                                
                                                                        
      
    

                                                                                    
                                          
      
    
                                                                                
HAL_StatusTypeDef HAL_TIMEx_HallSensor_Init(TIM_HandleTypeDef *htim, const TIM_HallSensor_InitTypeDef *sConfig);
HAL_StatusTypeDef HAL_TIMEx_HallSensor_DeInit(TIM_HandleTypeDef *htim);

void HAL_TIMEx_HallSensor_MspInit(TIM_HandleTypeDef *htim);
void HAL_TIMEx_HallSensor_MspDeInit(TIM_HandleTypeDef *htim);

                            
HAL_StatusTypeDef HAL_TIMEx_HallSensor_Start(TIM_HandleTypeDef *htim);
HAL_StatusTypeDef HAL_TIMEx_HallSensor_Stop(TIM_HandleTypeDef *htim);
                                  
HAL_StatusTypeDef HAL_TIMEx_HallSensor_Start_IT(TIM_HandleTypeDef *htim);
HAL_StatusTypeDef HAL_TIMEx_HallSensor_Stop_IT(TIM_HandleTypeDef *htim);
                            
HAL_StatusTypeDef HAL_TIMEx_HallSensor_Start_DMA(TIM_HandleTypeDef *htim, uint32_t *pData, uint16_t Length);
HAL_StatusTypeDef HAL_TIMEx_HallSensor_Stop_DMA(TIM_HandleTypeDef *htim);
   
      
    

                                                                                                     
                                                          
      
    
                                                                                
                            
HAL_StatusTypeDef HAL_TIMEx_OCN_Start(TIM_HandleTypeDef *htim, uint32_t Channel);
HAL_StatusTypeDef HAL_TIMEx_OCN_Stop(TIM_HandleTypeDef *htim, uint32_t Channel);

                                  
HAL_StatusTypeDef HAL_TIMEx_OCN_Start_IT(TIM_HandleTypeDef *htim, uint32_t Channel);
HAL_StatusTypeDef HAL_TIMEx_OCN_Stop_IT(TIM_HandleTypeDef *htim, uint32_t Channel);

                            
HAL_StatusTypeDef HAL_TIMEx_OCN_Start_DMA(TIM_HandleTypeDef *htim, uint32_t Channel, const uint32_t *pData,
                                          uint16_t Length);
HAL_StatusTypeDef HAL_TIMEx_OCN_Stop_DMA(TIM_HandleTypeDef *htim, uint32_t Channel);
   
      
    

                                                                                          
                                                
      
    
                                                                                
                            
HAL_StatusTypeDef HAL_TIMEx_PWMN_Start(TIM_HandleTypeDef *htim, uint32_t Channel);
HAL_StatusTypeDef HAL_TIMEx_PWMN_Stop(TIM_HandleTypeDef *htim, uint32_t Channel);

                                  
HAL_StatusTypeDef HAL_TIMEx_PWMN_Start_IT(TIM_HandleTypeDef *htim, uint32_t Channel);
HAL_StatusTypeDef HAL_TIMEx_PWMN_Stop_IT(TIM_HandleTypeDef *htim, uint32_t Channel);
                            
HAL_StatusTypeDef HAL_TIMEx_PWMN_Start_DMA(TIM_HandleTypeDef *htim, uint32_t Channel, const uint32_t *pData,
                                           uint16_t Length);
HAL_StatusTypeDef HAL_TIMEx_PWMN_Stop_DMA(TIM_HandleTypeDef *htim, uint32_t Channel);
   
      
    

                                                                                                
                                                      
      
    
                                                                                
                            
HAL_StatusTypeDef HAL_TIMEx_OnePulseN_Start(TIM_HandleTypeDef *htim, uint32_t OutputChannel);
HAL_StatusTypeDef HAL_TIMEx_OnePulseN_Stop(TIM_HandleTypeDef *htim, uint32_t OutputChannel);

                                  
HAL_StatusTypeDef HAL_TIMEx_OnePulseN_Start_IT(TIM_HandleTypeDef *htim, uint32_t OutputChannel);
HAL_StatusTypeDef HAL_TIMEx_OnePulseN_Stop_IT(TIM_HandleTypeDef *htim, uint32_t OutputChannel);
   
      
    

                                                                                     
                                           
      
    
                                                                                
HAL_StatusTypeDef HAL_TIMEx_ConfigCommutEvent(TIM_HandleTypeDef *htim, uint32_t  InputTrigger,
                                              uint32_t  CommutationSource);
HAL_StatusTypeDef HAL_TIMEx_ConfigCommutEvent_IT(TIM_HandleTypeDef *htim, uint32_t  InputTrigger,
                                                 uint32_t  CommutationSource);
HAL_StatusTypeDef HAL_TIMEx_ConfigCommutEvent_DMA(TIM_HandleTypeDef *htim, uint32_t  InputTrigger,
                                                  uint32_t  CommutationSource);
HAL_StatusTypeDef HAL_TIMEx_MasterConfigSynchronization(TIM_HandleTypeDef *htim,
                                                        const TIM_MasterConfigTypeDef *sMasterConfig);
HAL_StatusTypeDef HAL_TIMEx_ConfigBreakDeadTime(TIM_HandleTypeDef *htim,
                                                const TIM_BreakDeadTimeConfigTypeDef *sBreakDeadTimeConfig);
HAL_StatusTypeDef HAL_TIMEx_ConfigBreakInput(TIM_HandleTypeDef *htim, uint32_t BreakInput,
                                             const TIMEx_BreakInputConfigTypeDef *sBreakInputConfig);
HAL_StatusTypeDef HAL_TIMEx_GroupChannel5(TIM_HandleTypeDef *htim, uint32_t Channels);
HAL_StatusTypeDef HAL_TIMEx_RemapConfig(TIM_HandleTypeDef *htim, uint32_t Remap);
   
      
    

                                                                            
                                          
      
    
                                                                                
void HAL_TIMEx_CommutCallback(TIM_HandleTypeDef *htim);
void HAL_TIMEx_CommutHalfCpltCallback(TIM_HandleTypeDef *htim);
void HAL_TIMEx_BreakCallback(TIM_HandleTypeDef *htim);
void HAL_TIMEx_Break2Callback(TIM_HandleTypeDef *htim);
   
      
    

                                                                                   
                                                 
      
    
                                                                                
HAL_TIM_StateTypeDef HAL_TIMEx_HallSensor_GetState(const TIM_HandleTypeDef *htim);
HAL_TIM_ChannelStateTypeDef HAL_TIMEx_GetChannelNState(const TIM_HandleTypeDef *htim,  uint32_t ChannelN);
   
      
    

   
      
    
                                                                                

                                                                                
                                                                      
      
    
void TIMEx_DMACommutationCplt(DMA_HandleTypeDef *hdma);
void TIMEx_DMACommutationHalfCplt(DMA_HandleTypeDef *hdma);
   
      
    
                                                                                

   
      
    

   
      
    

#ifdef __cplusplus
}
#endif


#endif                             
