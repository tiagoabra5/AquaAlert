/**
  ******************************************************************************
  * @file    stm32l4xx_hal_dma_ex.h
  * @author  MCD Application Team
  * @brief   Header file of DMA HAL extension module.
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

                                                                                
#ifndef STM32L4xx_HAL_DMA_EX_H
#define STM32L4xx_HAL_DMA_EX_H

#ifdef __cplusplus
extern "C" {
#endif

#if defined(DMAMUX1)
                                                                                
#include "stm32l4xx_hal_def.h"
#include "stm32l4xx_ll_dmamux.h"

                                    
      
    

                     
      
    

                                                                                
                                                       
      
    

   
                                                                         
    
typedef struct
{
  uint32_t SyncSignalID;                                                                                          
                                                                                                              

  uint32_t SyncPolarity;                                                                                           
                                                                                                              

  FunctionalState SyncEnable;                                                                     
                                                                                        

  FunctionalState EventEnable;                                                                                  
                                                                                        

  uint32_t RequestNumber;                                                                                          
                                                                                                           


} HAL_DMA_MuxSyncConfigTypeDef;


   
                                                                        
    
typedef struct
{
  uint32_t SignalID;                                                                                 
                                                                                                                   

  uint32_t Polarity;                                                                                        
                                                                                                                            

  uint32_t RequestNumber;                                                                                           
                                                                                                           

} HAL_DMA_MuxRequestGeneratorConfigTypeDef;

   
      
    

                                                                                
                                                               
      
    

                                                                               
      
    
#define HAL_DMAMUX1_SYNC_EXTI0            LL_DMAMUX_SYNC_EXTI_LINE0                                                          
#define HAL_DMAMUX1_SYNC_EXTI1            LL_DMAMUX_SYNC_EXTI_LINE1                                                          
#define HAL_DMAMUX1_SYNC_EXTI2            LL_DMAMUX_SYNC_EXTI_LINE2                                                          
#define HAL_DMAMUX1_SYNC_EXTI3            LL_DMAMUX_SYNC_EXTI_LINE3                                                          
#define HAL_DMAMUX1_SYNC_EXTI4            LL_DMAMUX_SYNC_EXTI_LINE4                                                          
#define HAL_DMAMUX1_SYNC_EXTI5            LL_DMAMUX_SYNC_EXTI_LINE5                                                          
#define HAL_DMAMUX1_SYNC_EXTI6            LL_DMAMUX_SYNC_EXTI_LINE6                                                          
#define HAL_DMAMUX1_SYNC_EXTI7            LL_DMAMUX_SYNC_EXTI_LINE7                                                          
#define HAL_DMAMUX1_SYNC_EXTI8            LL_DMAMUX_SYNC_EXTI_LINE8                                                          
#define HAL_DMAMUX1_SYNC_EXTI9            LL_DMAMUX_SYNC_EXTI_LINE9                                                          
#define HAL_DMAMUX1_SYNC_EXTI10           LL_DMAMUX_SYNC_EXTI_LINE10                                                         
#define HAL_DMAMUX1_SYNC_EXTI11           LL_DMAMUX_SYNC_EXTI_LINE11                                                         
#define HAL_DMAMUX1_SYNC_EXTI12           LL_DMAMUX_SYNC_EXTI_LINE12                                                         
#define HAL_DMAMUX1_SYNC_EXTI13           LL_DMAMUX_SYNC_EXTI_LINE13                                                         
#define HAL_DMAMUX1_SYNC_EXTI14           LL_DMAMUX_SYNC_EXTI_LINE14                                                         
#define HAL_DMAMUX1_SYNC_EXTI15           LL_DMAMUX_SYNC_EXTI_LINE15                                                         
#define HAL_DMAMUX1_SYNC_DMAMUX1_CH0_EVT  LL_DMAMUX_SYNC_DMAMUX_CH0                                                                      
#define HAL_DMAMUX1_SYNC_DMAMUX1_CH1_EVT  LL_DMAMUX_SYNC_DMAMUX_CH1                                                                      
#define HAL_DMAMUX1_SYNC_DMAMUX1_CH2_EVT  LL_DMAMUX_SYNC_DMAMUX_CH2                                                                      
#define HAL_DMAMUX1_SYNC_DMAMUX1_CH3_EVT  LL_DMAMUX_SYNC_DMAMUX_CH3                                                                      
#define HAL_DMAMUX1_SYNC_LPTIM1_OUT       LL_DMAMUX_SYNC_LPTIM1_OUT                                                         
#define HAL_DMAMUX1_SYNC_LPTIM2_OUT       LL_DMAMUX_SYNC_LPTIM2_OUT                                                         
#if defined (STM32L4R5xx) || defined (STM32L4R7xx) || defined (STM32L4R9xx) || defined (STM32L4S5xx) || defined (STM32L4S7xx) || defined (STM32L4S9xx)
#define HAL_DMAMUX1_SYNC_DSI_TE           LL_DMAMUX_SYNC_DSI_TE                                                                          
#define HAL_DMAMUX1_SYNC_DSI_EOT          LL_DMAMUX_SYNC_DSI_REFRESH_END                                                                 
#endif                                                                                             
#define HAL_DMAMUX1_SYNC_DMA2D_EOT        LL_DMAMUX_SYNC_DMA2D_TX_END                                                                    
#define HAL_DMAMUX1_SYNC_LDTC_IT          LL_DMAMUX_SYNC_LTDC_LINE_IT                                                       

#define HAL_DMAMUX1_MAX_SYNC              HAL_DMAMUX1_SYNC_LDTC_IT
   
      
    

                                                                               
      
    
#define HAL_DMAMUX_SYNC_NO_EVENT          LL_DMAMUX_SYNC_NO_EVENT                                                                         
#define HAL_DMAMUX_SYNC_RISING            LL_DMAMUX_SYNC_POL_RISING                                                                       
#define HAL_DMAMUX_SYNC_FALLING           LL_DMAMUX_SYNC_POL_FALLING                                                                      
#define HAL_DMAMUX_SYNC_RISING_FALLING    LL_DMAMUX_SYNC_POL_RISING_FALLING                                                               

   
      
    

                                                                                         
      
    
#define HAL_DMAMUX1_REQ_GEN_EXTI0            LL_DMAMUX_REQ_GEN_EXTI_LINE0                                                        
#define HAL_DMAMUX1_REQ_GEN_EXTI1            LL_DMAMUX_REQ_GEN_EXTI_LINE1                                                        
#define HAL_DMAMUX1_REQ_GEN_EXTI2            LL_DMAMUX_REQ_GEN_EXTI_LINE2                                                        
#define HAL_DMAMUX1_REQ_GEN_EXTI3            LL_DMAMUX_REQ_GEN_EXTI_LINE3                                                        
#define HAL_DMAMUX1_REQ_GEN_EXTI4            LL_DMAMUX_REQ_GEN_EXTI_LINE4                                                        
#define HAL_DMAMUX1_REQ_GEN_EXTI5            LL_DMAMUX_REQ_GEN_EXTI_LINE5                                                        
#define HAL_DMAMUX1_REQ_GEN_EXTI6            LL_DMAMUX_REQ_GEN_EXTI_LINE6                                                        
#define HAL_DMAMUX1_REQ_GEN_EXTI7            LL_DMAMUX_REQ_GEN_EXTI_LINE7                                                        
#define HAL_DMAMUX1_REQ_GEN_EXTI8            LL_DMAMUX_REQ_GEN_EXTI_LINE8                                                        
#define HAL_DMAMUX1_REQ_GEN_EXTI9            LL_DMAMUX_REQ_GEN_EXTI_LINE9                                                        
#define HAL_DMAMUX1_REQ_GEN_EXTI10           LL_DMAMUX_REQ_GEN_EXTI_LINE10                                                       
#define HAL_DMAMUX1_REQ_GEN_EXTI11           LL_DMAMUX_REQ_GEN_EXTI_LINE11                                                       
#define HAL_DMAMUX1_REQ_GEN_EXTI12           LL_DMAMUX_REQ_GEN_EXTI_LINE12                                                       
#define HAL_DMAMUX1_REQ_GEN_EXTI13           LL_DMAMUX_REQ_GEN_EXTI_LINE13                                                       
#define HAL_DMAMUX1_REQ_GEN_EXTI14           LL_DMAMUX_REQ_GEN_EXTI_LINE14                                                       
#define HAL_DMAMUX1_REQ_GEN_EXTI15           LL_DMAMUX_REQ_GEN_EXTI_LINE15                                                       
#define HAL_DMAMUX1_REQ_GEN_DMAMUX1_CH0_EVT  LL_DMAMUX_REQ_GEN_DMAMUX_CH0                                                                   
#define HAL_DMAMUX1_REQ_GEN_DMAMUX1_CH1_EVT  LL_DMAMUX_REQ_GEN_DMAMUX_CH1                                                                   
#define HAL_DMAMUX1_REQ_GEN_DMAMUX1_CH2_EVT  LL_DMAMUX_REQ_GEN_DMAMUX_CH2                                                                   
#define HAL_DMAMUX1_REQ_GEN_DMAMUX1_CH3_EVT  LL_DMAMUX_REQ_GEN_DMAMUX_CH3                                                                   
#define HAL_DMAMUX1_REQ_GEN_LPTIM1_OUT       LL_DMAMUX_REQ_GEN_LPTIM1_OUT                                                        
#define HAL_DMAMUX1_REQ_GEN_LPTIM2_OUT       LL_DMAMUX_REQ_GEN_LPTIM2_OUT                                                        
#if defined (STM32L4R5xx) || defined (STM32L4R7xx) || defined (STM32L4R9xx) || defined (STM32L4S5xx) || defined (STM32L4S7xx) || defined (STM32L4S9xx)
#define HAL_DMAMUX1_REQ_GEN_DSI_TE           LL_DMAMUX_REQ_GEN_DSI_TE                                                                        
#define HAL_DMAMUX1_REQ_GEN_DSI_EOT          LL_DMAMUX_REQ_GEN_DSI_REFRESH_END                                                               
#endif                                                                                             
#define HAL_DMAMUX1_REQ_GEN_DMA2D_EOT        LL_DMAMUX_REQ_GEN_DMA2D_TX_END                                                                  
#define HAL_DMAMUX1_REQ_GEN_LTDC_IT          LL_DMAMUX_REQ_GEN_LTDC_LINE_IT                                                      

#define HAL_DMAMUX1_MAX_REQ_GEN              HAL_DMAMUX1_REQ_GEN_LTDC_IT
   
      
    

                                                                                                           
      
    
#define HAL_DMAMUX_REQ_GEN_NO_EVENT       LL_DMAMUX_REQ_GEN_NO_EVENT                                                                      
#define HAL_DMAMUX_REQ_GEN_RISING         LL_DMAMUX_REQ_GEN_POL_RISING                                                                    
#define HAL_DMAMUX_REQ_GEN_FALLING        LL_DMAMUX_REQ_GEN_POL_FALLING                                                                   
#define HAL_DMAMUX_REQ_GEN_RISING_FALLING LL_DMAMUX_REQ_GEN_POL_RISING_FALLING                                                            

   
      
    

   
      
    

                                                                                

                                                                                
                                        
      
    

                                                                                
                                               
      
    

                                                                                
HAL_StatusTypeDef HAL_DMAEx_ConfigMuxRequestGenerator(DMA_HandleTypeDef *hdma,
                                                      HAL_DMA_MuxRequestGeneratorConfigTypeDef *pRequestGeneratorConfig);
HAL_StatusTypeDef HAL_DMAEx_EnableMuxRequestGenerator(DMA_HandleTypeDef *hdma);
HAL_StatusTypeDef HAL_DMAEx_DisableMuxRequestGenerator(DMA_HandleTypeDef *hdma);
                                                                                

                                                                                
HAL_StatusTypeDef HAL_DMAEx_ConfigMuxSync(DMA_HandleTypeDef *hdma, HAL_DMA_MuxSyncConfigTypeDef *pSyncConfig);
                                                                                

void              HAL_DMAEx_MUX_IRQHandler(DMA_HandleTypeDef *hdma);

   
      
    

   
      
    


                                                                                
                                                       
                                  
      
    

#define IS_DMAMUX_SYNC_SIGNAL_ID(SIGNAL_ID)             (((SIGNAL_ID) == HAL_DMAMUX1_SYNC_EXTI0) || \
                                                         (((SIGNAL_ID) >= HAL_DMAMUX1_SYNC_EXTI1) && \
                                                          ((SIGNAL_ID) <= HAL_DMAMUX1_MAX_SYNC)))

#define IS_DMAMUX_SYNC_REQUEST_NUMBER(REQUEST_NUMBER)   (((REQUEST_NUMBER) > 0U) && ((REQUEST_NUMBER) <= 32U))

#define IS_DMAMUX_SYNC_POLARITY(POLARITY)               (((POLARITY) == HAL_DMAMUX_SYNC_NO_EVENT) || \
                                                         ((POLARITY) == HAL_DMAMUX_SYNC_RISING)   || \
                                                         ((POLARITY) == HAL_DMAMUX_SYNC_FALLING)  || \
                                                         ((POLARITY) == HAL_DMAMUX_SYNC_RISING_FALLING))

#define IS_DMAMUX_SYNC_STATE(SYNC)                      (((SYNC) == DISABLE)   || ((SYNC) == ENABLE))

#define IS_DMAMUX_SYNC_EVENT(EVENT)                     (((EVENT) == DISABLE)   || \
                                                         ((EVENT) == ENABLE))

#define IS_DMAMUX_REQUEST_GEN_SIGNAL_ID(SIGNAL_ID)      (((SIGNAL_ID) == HAL_DMAMUX1_REQ_GEN_EXTI0) || \
                                                         (((SIGNAL_ID) >= HAL_DMAMUX1_REQ_GEN_EXTI1) && \
                                                          ((SIGNAL_ID) <= HAL_DMAMUX1_MAX_REQ_GEN)))

#define IS_DMAMUX_REQUEST_GEN_REQUEST_NUMBER(REQUEST_NUMBER) (((REQUEST_NUMBER) > 0U) && ((REQUEST_NUMBER) <= 32U))

#define IS_DMAMUX_REQUEST_GEN_POLARITY(POLARITY)        (((POLARITY) == HAL_DMAMUX_REQ_GEN_NO_EVENT)|| \
                                                         ((POLARITY) == HAL_DMAMUX_REQ_GEN_RISING)  || \
                                                         ((POLARITY) == HAL_DMAMUX_REQ_GEN_FALLING) || \
                                                         ((POLARITY) == HAL_DMAMUX_REQ_GEN_RISING_FALLING))

   
      
    


   
      
    

   
      
    

#endif              
#ifdef __cplusplus
}
#endif

#endif                             

