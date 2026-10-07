/**
  ******************************************************************************
  * @file    stm32l4xx_hal_dma.h
  * @author  MCD Application Team
  * @brief   Header file of DMA HAL module.
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

                                                                                
#ifndef STM32L4xx_HAL_DMA_H
#define STM32L4xx_HAL_DMA_H

#ifdef __cplusplus
extern "C" {
#endif

                                                                                
#include "stm32l4xx_hal_def.h"
#include "stm32l4xx_ll_dma.h"

                                    
      
    

                   
      
    

                                                                                
                                                   
      
    

   
                                                  
    
typedef struct
{
  uint32_t Request;                                                                             
                                                                                           

  uint32_t Direction;                                                                                      
                                                                                          
                                                                                                           

  uint32_t PeriphInc;                                                                                                 
                                                                                                               

  uint32_t MemInc;                                                                                                
                                                                                                           

  uint32_t PeriphDataAlignment;                                            
                                                                                                        

  uint32_t MemDataAlignment;                                           
                                                                                                    

  uint32_t Mode;                                                                         
                                                                                     
                                                                                                            
                                                                                                   

  uint32_t Priority;                                                                         
                                                                                                  
} DMA_InitTypeDef;

   
                                               
    
typedef enum
{
  HAL_DMA_STATE_RESET             = 0x00U,                                                
  HAL_DMA_STATE_READY             = 0x01U,                                                
  HAL_DMA_STATE_BUSY              = 0x02U,                                                
  HAL_DMA_STATE_TIMEOUT           = 0x03U,                                                
} HAL_DMA_StateTypeDef;

   
                                                   
    
typedef enum
{
  HAL_DMA_FULL_TRANSFER           = 0x00U,                           
  HAL_DMA_HALF_TRANSFER           = 0x01U                            
} HAL_DMA_LevelCompleteTypeDef;

   
                                                    
    
typedef enum
{
  HAL_DMA_XFER_CPLT_CB_ID          = 0x00U,                          
  HAL_DMA_XFER_HALFCPLT_CB_ID      = 0x01U,                          
  HAL_DMA_XFER_ERROR_CB_ID         = 0x02U,                          
  HAL_DMA_XFER_ABORT_CB_ID         = 0x03U,                          
  HAL_DMA_XFER_ALL_CB_ID           = 0x04U                           

} HAL_DMA_CallbackIDTypeDef;

   
                                           
    
typedef struct __DMA_HandleTypeDef
{
  DMA_Channel_TypeDef             *Instance;                                                                       

  DMA_InitTypeDef                 Init;                                                                            

  HAL_LockTypeDef                 Lock;                                                                            

  __IO HAL_DMA_StateTypeDef       State;                                                                           

  void   *Parent;                                                                                                  

  void (* XferCpltCallback)(struct __DMA_HandleTypeDef *hdma);                                                     

  void (* XferHalfCpltCallback)(struct __DMA_HandleTypeDef *hdma);                                                 

  void (* XferErrorCallback)(struct __DMA_HandleTypeDef *hdma);                                                    

  void (* XferAbortCallback)(struct __DMA_HandleTypeDef *hdma);                                                    

  __IO uint32_t                   ErrorCode;                                                                       

  DMA_TypeDef            *DmaBaseAddress;                                                                          

  uint32_t                        ChannelIndex;                                                                    

#if defined(DMAMUX1)
  DMAMUX_Channel_TypeDef           *DMAmuxChannel;                                                                 

  DMAMUX_ChannelStatus_TypeDef     *DMAmuxChannelStatus;                                                           

  uint32_t                         DMAmuxChannelStatusMask;                                                        

  DMAMUX_RequestGen_TypeDef        *DMAmuxRequestGen;                                                              

  DMAMUX_RequestGenStatus_TypeDef  *DMAmuxRequestGenStatus;                                                        

  uint32_t                         DMAmuxRequestGenStatusMask;                                                     
#endif              
} DMA_HandleTypeDef;
   
      
    

                                                                                

                                                           
      
    

                                           
      
    
#define HAL_DMA_ERROR_NONE           0x00000000U                                                      
#define HAL_DMA_ERROR_TE             0x00000001U                                                      
#define HAL_DMA_ERROR_NO_XFER        0x00000004U                                                      
#define HAL_DMA_ERROR_TIMEOUT        0x00000020U                                                      
#define HAL_DMA_ERROR_PARAM          0x00000040U                                                      
#define HAL_DMA_ERROR_BUSY           0x00000080U                                                      
#define HAL_DMA_ERROR_NOT_SUPPORTED  0x00000100U                                                      
#define HAL_DMA_ERROR_SYNC           0x00000200U                                                      
#define HAL_DMA_ERROR_REQGEN         0x00000400U                                                      

   
      
    

                                     
      
    
#if !defined (DMAMUX1)

#define DMA_REQUEST_0                     0U
#define DMA_REQUEST_1                     1U
#define DMA_REQUEST_2                     2U
#define DMA_REQUEST_3                     3U
#define DMA_REQUEST_4                     4U
#define DMA_REQUEST_5                     5U
#define DMA_REQUEST_6                     6U
#define DMA_REQUEST_7                     7U

#endif

#if defined(DMAMUX1)

#define DMA_REQUEST_MEM2MEM          LL_DMAMUX_REQ_MEM2MEM                                        

#define DMA_REQUEST_GENERATOR0       LL_DMAMUX_REQ_GENERATOR0                                     
#define DMA_REQUEST_GENERATOR1       LL_DMAMUX_REQ_GENERATOR1                                     
#define DMA_REQUEST_GENERATOR2       LL_DMAMUX_REQ_GENERATOR2                                     
#define DMA_REQUEST_GENERATOR3       LL_DMAMUX_REQ_GENERATOR3                                     

#define DMA_REQUEST_ADC1             LL_DMAMUX_REQ_ADC1                                         

#if defined (STM32L4P5xx) || defined (STM32L4Q5xx)
#define DMA_REQUEST_ADC2             LL_DMAMUX_REQ_ADC2                                         
#endif

#define DMA_REQUEST_DAC1_CH1         LL_DMAMUX_REQ_DAC1_CH1                                     
#define DMA_REQUEST_DAC1_CH2         LL_DMAMUX_REQ_DAC1_CH2                                     

#define DMA_REQUEST_TIM6_UP          LL_DMAMUX_REQ_TIM6_UP                                      
#define DMA_REQUEST_TIM7_UP          LL_DMAMUX_REQ_TIM7_UP                                      

#define DMA_REQUEST_SPI1_RX          LL_DMAMUX_REQ_SPI1_RX                                      
#define DMA_REQUEST_SPI1_TX          LL_DMAMUX_REQ_SPI1_TX                                      
#define DMA_REQUEST_SPI2_RX          LL_DMAMUX_REQ_SPI2_RX                                      
#define DMA_REQUEST_SPI2_TX          LL_DMAMUX_REQ_SPI2_TX                                      
#define DMA_REQUEST_SPI3_RX          LL_DMAMUX_REQ_SPI3_RX                                      
#define DMA_REQUEST_SPI3_TX          LL_DMAMUX_REQ_SPI3_TX                                      

#define DMA_REQUEST_I2C1_RX          LL_DMAMUX_REQ_I2C1_RX                                      
#define DMA_REQUEST_I2C1_TX          LL_DMAMUX_REQ_I2C1_TX                                      
#define DMA_REQUEST_I2C2_RX          LL_DMAMUX_REQ_I2C2_RX                                      
#define DMA_REQUEST_I2C2_TX          LL_DMAMUX_REQ_I2C2_TX                                      
#define DMA_REQUEST_I2C3_RX          LL_DMAMUX_REQ_I2C3_RX                                      
#define DMA_REQUEST_I2C3_TX          LL_DMAMUX_REQ_I2C3_TX                                      
#define DMA_REQUEST_I2C4_RX          LL_DMAMUX_REQ_I2C4_RX                                      
#define DMA_REQUEST_I2C4_TX          LL_DMAMUX_REQ_I2C4_TX                                      

#define DMA_REQUEST_USART1_RX        LL_DMAMUX_REQ_USART1_RX                                    
#define DMA_REQUEST_USART1_TX        LL_DMAMUX_REQ_USART1_TX                                    
#define DMA_REQUEST_USART2_RX        LL_DMAMUX_REQ_USART2_RX                                    
#define DMA_REQUEST_USART2_TX        LL_DMAMUX_REQ_USART2_TX                                    
#define DMA_REQUEST_USART3_RX        LL_DMAMUX_REQ_USART3_RX                                    
#define DMA_REQUEST_USART3_TX        LL_DMAMUX_REQ_USART3_TX                                    

#define DMA_REQUEST_UART4_RX         LL_DMAMUX_REQ_UART4_RX                                     
#define DMA_REQUEST_UART4_TX         LL_DMAMUX_REQ_UART4_TX                                     
#define DMA_REQUEST_UART5_RX         LL_DMAMUX_REQ_UART5_RX                                     
#define DMA_REQUEST_UART5_TX         LL_DMAMUX_REQ_UART5_TX                                     

#define DMA_REQUEST_LPUART1_RX       LL_DMAMUX_REQ_LPUART1_RX                                     
#define DMA_REQUEST_LPUART1_TX       LL_DMAMUX_REQ_LPUART1_TX                                     

#define DMA_REQUEST_SAI1_A           LL_DMAMUX_REQ_SAI1_A                                       
#define DMA_REQUEST_SAI1_B           LL_DMAMUX_REQ_SAI1_B                                       
#define DMA_REQUEST_SAI2_A           LL_DMAMUX_REQ_SAI2_A                                       
#define DMA_REQUEST_SAI2_B           LL_DMAMUX_REQ_SAI2_B                                       

#define DMA_REQUEST_OCTOSPI1         LL_DMAMUX_REQ_OSPI1                                        
#define DMA_REQUEST_OCTOSPI2         LL_DMAMUX_REQ_OSPI2                                        

#define DMA_REQUEST_TIM1_CH1         LL_DMAMUX_REQ_TIM1_CH1                                     
#define DMA_REQUEST_TIM1_CH2         LL_DMAMUX_REQ_TIM1_CH2                                     
#define DMA_REQUEST_TIM1_CH3         LL_DMAMUX_REQ_TIM1_CH3                                     
#define DMA_REQUEST_TIM1_CH4         LL_DMAMUX_REQ_TIM1_CH4                                     
#define DMA_REQUEST_TIM1_UP          LL_DMAMUX_REQ_TIM1_UP                                      
#define DMA_REQUEST_TIM1_TRIG        LL_DMAMUX_REQ_TIM1_TRIG                                    
#define DMA_REQUEST_TIM1_COM         LL_DMAMUX_REQ_TIM1_COM                                     

#define DMA_REQUEST_TIM8_CH1         LL_DMAMUX_REQ_TIM8_CH1                                     
#define DMA_REQUEST_TIM8_CH2         LL_DMAMUX_REQ_TIM8_CH2                                     
#define DMA_REQUEST_TIM8_CH3         LL_DMAMUX_REQ_TIM8_CH3                                     
#define DMA_REQUEST_TIM8_CH4         LL_DMAMUX_REQ_TIM8_CH4                                     
#define DMA_REQUEST_TIM8_UP          LL_DMAMUX_REQ_TIM8_UP                                      
#define DMA_REQUEST_TIM8_TRIG        LL_DMAMUX_REQ_TIM8_TRIG                                    
#define DMA_REQUEST_TIM8_COM         LL_DMAMUX_REQ_TIM8_COM                                     

#define DMA_REQUEST_TIM2_CH1         LL_DMAMUX_REQ_TIM2_CH1                                     
#define DMA_REQUEST_TIM2_CH2         LL_DMAMUX_REQ_TIM2_CH2                                     
#define DMA_REQUEST_TIM2_CH3         LL_DMAMUX_REQ_TIM2_CH3                                     
#define DMA_REQUEST_TIM2_CH4         LL_DMAMUX_REQ_TIM2_CH4                                     
#define DMA_REQUEST_TIM2_UP          LL_DMAMUX_REQ_TIM2_UP                                      

#define DMA_REQUEST_TIM3_CH1         LL_DMAMUX_REQ_TIM3_CH1                                     
#define DMA_REQUEST_TIM3_CH2         LL_DMAMUX_REQ_TIM3_CH2                                     
#define DMA_REQUEST_TIM3_CH3         LL_DMAMUX_REQ_TIM3_CH3                                     
#define DMA_REQUEST_TIM3_CH4         LL_DMAMUX_REQ_TIM3_CH4                                     
#define DMA_REQUEST_TIM3_UP          LL_DMAMUX_REQ_TIM3_UP                                      
#define DMA_REQUEST_TIM3_TRIG        LL_DMAMUX_REQ_TIM3_TRIG                                    

#define DMA_REQUEST_TIM4_CH1         LL_DMAMUX_REQ_TIM4_CH1                                     
#define DMA_REQUEST_TIM4_CH2         LL_DMAMUX_REQ_TIM4_CH2                                     
#define DMA_REQUEST_TIM4_CH3         LL_DMAMUX_REQ_TIM4_CH3                                     
#define DMA_REQUEST_TIM4_CH4         LL_DMAMUX_REQ_TIM4_CH4                                     
#define DMA_REQUEST_TIM4_UP          LL_DMAMUX_REQ_TIM4_UP                                      

#define DMA_REQUEST_TIM5_CH1         LL_DMAMUX_REQ_TIM5_CH1                                     
#define DMA_REQUEST_TIM5_CH2         LL_DMAMUX_REQ_TIM5_CH2                                     
#define DMA_REQUEST_TIM5_CH3         LL_DMAMUX_REQ_TIM5_CH3                                     
#define DMA_REQUEST_TIM5_CH4         LL_DMAMUX_REQ_TIM5_CH4                                     
#define DMA_REQUEST_TIM5_UP          LL_DMAMUX_REQ_TIM5_UP                                      
#define DMA_REQUEST_TIM5_TRIG        LL_DMAMUX_REQ_TIM5_TRIG                                    

#define DMA_REQUEST_TIM15_CH1        LL_DMAMUX_REQ_TIM15_CH1                                    
#define DMA_REQUEST_TIM15_UP         LL_DMAMUX_REQ_TIM15_UP                                     
#define DMA_REQUEST_TIM15_TRIG       LL_DMAMUX_REQ_TIM15_TRIG                                    
#define DMA_REQUEST_TIM15_COM        LL_DMAMUX_REQ_TIM15_COM                                    

#define DMA_REQUEST_TIM16_CH1        LL_DMAMUX_REQ_TIM16_CH1                                    
#define DMA_REQUEST_TIM16_UP         LL_DMAMUX_REQ_TIM16_UP                                     
#define DMA_REQUEST_TIM17_CH1        LL_DMAMUX_REQ_TIM17_CH1                                    
#define DMA_REQUEST_TIM17_UP         LL_DMAMUX_REQ_TIM17_UP                                     

#define DMA_REQUEST_DFSDM1_FLT0      LL_DMAMUX_REQ_DFSDM1_FLT0                                       
#define DMA_REQUEST_DFSDM1_FLT1      LL_DMAMUX_REQ_DFSDM1_FLT1                                       
#define DMA_REQUEST_DFSDM1_FLT2      LL_DMAMUX_REQ_DFSDM1_FLT2                                       
#define DMA_REQUEST_DFSDM1_FLT3      LL_DMAMUX_REQ_DFSDM1_FLT3                                       

#define DMA_REQUEST_DCMI             LL_DMAMUX_REQ_DCMI                                         
#if defined(PSSI)
#define DMA_REQUEST_DCMI_PSSI        LL_DMAMUX_REQ_DCMI_PSSI                                    
#endif

#define DMA_REQUEST_AES_IN           LL_DMAMUX_REQ_AES_IN                                       
#define DMA_REQUEST_AES_OUT          LL_DMAMUX_REQ_AES_OUT                                      

#define DMA_REQUEST_HASH_IN          LL_DMAMUX_REQ_HASH_IN                                      

#endif              

#define DMA_MAX_REQUEST              LL_DMAMUX_MAX_REQ
   
      
    

                                                                     
      
    
#define DMA_PERIPH_TO_MEMORY         LL_DMA_DIRECTION_PERIPH_TO_MEMORY                                        
#define DMA_MEMORY_TO_PERIPH         LL_DMA_DIRECTION_MEMORY_TO_PERIPH                                        
#define DMA_MEMORY_TO_MEMORY         LL_DMA_DIRECTION_MEMORY_TO_MEMORY                                        

   
      
    

                                                                             
      
    
#define DMA_PINC_ENABLE              LL_DMA_PERIPH_INCREMENT                                                     
#define DMA_PINC_DISABLE             LL_DMA_PERIPH_NOINCREMENT                                                   
   
      
    

                                                                     
      
    
#define DMA_MINC_ENABLE              LL_DMA_MEMORY_INCREMENT                                                 
#define DMA_MINC_DISABLE             LL_DMA_MEMORY_NOINCREMENT                                               
   
      
    

                                                               
      
    
#define DMA_PDATAALIGN_BYTE          LL_DMA_PDATAALIGN_BYTE                                                         
#define DMA_PDATAALIGN_HALFWORD      LL_DMA_PDATAALIGN_HALFWORD                                                     
#define DMA_PDATAALIGN_WORD          LL_DMA_PDATAALIGN_WORD                                                         
   
      
    

                                                       
      
    
#define DMA_MDATAALIGN_BYTE          LL_DMA_MDATAALIGN_BYTE                                                     
#define DMA_MDATAALIGN_HALFWORD      LL_DMA_MDATAALIGN_HALFWORD                                                 
#define DMA_MDATAALIGN_WORD          LL_DMA_MDATAALIGN_WORD                                                     
   
      
    

                               
      
    
#define DMA_NORMAL                   LL_DMA_MODE_NORMAL                                       
#define DMA_CIRCULAR                 LL_DMA_MODE_CIRCULAR                                     
   
      
    

                                                   
      
    
#define DMA_PRIORITY_LOW             LL_DMA_PRIORITY_LOW                                                  
#define DMA_PRIORITY_MEDIUM          LL_DMA_PRIORITY_MEDIUM                                               
#define DMA_PRIORITY_HIGH            LL_DMA_PRIORITY_HIGH                                                 
#define DMA_PRIORITY_VERY_HIGH       LL_DMA_PRIORITY_VERYHIGH                                             
   
      
    

                                                                               
      
    
#define DMA_IT_TC                    DMA_CCR_TCIE                                                               
#define DMA_IT_HT                    DMA_CCR_HTIE                                                               
#define DMA_IT_TE                    DMA_CCR_TEIE                                                               
   
      
    

                                                       
      
    

#define DMA_FLAG_GI1                 DMA_ISR_GIF1                                                                   
#define DMA_FLAG_TC1                 DMA_ISR_TCIF1                                                                  
#define DMA_FLAG_HT1                 DMA_ISR_HTIF1                                                                  
#define DMA_FLAG_TE1                 DMA_ISR_TEIF1                                                                  
#define DMA_FLAG_GI2                 DMA_ISR_GIF2                                                                   
#define DMA_FLAG_TC2                 DMA_ISR_TCIF2                                                                  
#define DMA_FLAG_HT2                 DMA_ISR_HTIF2                                                                  
#define DMA_FLAG_TE2                 DMA_ISR_TEIF2                                                                  
#define DMA_FLAG_GI3                 DMA_ISR_GIF3                                                                   
#define DMA_FLAG_TC3                 DMA_ISR_TCIF3                                                                  
#define DMA_FLAG_HT3                 DMA_ISR_HTIF3                                                                  
#define DMA_FLAG_TE3                 DMA_ISR_TEIF3                                                                  
#define DMA_FLAG_GI4                 DMA_ISR_GIF4                                                                   
#define DMA_FLAG_TC4                 DMA_ISR_TCIF4                                                                  
#define DMA_FLAG_HT4                 DMA_ISR_HTIF4                                                                  
#define DMA_FLAG_TE4                 DMA_ISR_TEIF4                                                                  
#define DMA_FLAG_GI5                 DMA_ISR_GIF5                                                                   
#define DMA_FLAG_TC5                 DMA_ISR_TCIF5                                                                  
#define DMA_FLAG_HT5                 DMA_ISR_HTIF5                                                                  
#define DMA_FLAG_TE5                 DMA_ISR_TEIF5                                                                  
#define DMA_FLAG_GI6                 DMA_ISR_GIF6                                                                   
#define DMA_FLAG_TC6                 DMA_ISR_TCIF6                                                                  
#define DMA_FLAG_HT6                 DMA_ISR_HTIF6                                                                  
#define DMA_FLAG_TE6                 DMA_ISR_TEIF6                                                                  
#define DMA_FLAG_GI7                 DMA_ISR_GIF7                                                                   
#define DMA_FLAG_TC7                 DMA_ISR_TCIF7                                                                  
#define DMA_FLAG_HT7                 DMA_ISR_HTIF7                                                                  
#define DMA_FLAG_TE7                 DMA_ISR_TEIF7                                                                  
   
      
    

   
      
    

                                                                                
                                                     
      
    

                                  
                                
                
    
#define __HAL_DMA_RESET_HANDLE_STATE(__HANDLE__) ((__HANDLE__)->State = HAL_DMA_STATE_RESET)

   
                                             
                                
                
    
#define __HAL_DMA_ENABLE(__HANDLE__)        ((__HANDLE__)->Instance->CCR |=  DMA_CCR_EN)

   
                                              
                                
                
    
#define __HAL_DMA_DISABLE(__HANDLE__)       ((__HANDLE__)->Instance->CCR &=  ~DMA_CCR_EN)

   
                                                                  
                                
                                                       
    
#define __HAL_DMA_GET_TC_FLAG_INDEX(__HANDLE__) \
(((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA1_Channel1))? DMA_FLAG_TC1 :\
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA2_Channel1))? DMA_FLAG_TC1 :\
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA1_Channel2))? DMA_FLAG_TC2 :\
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA2_Channel2))? DMA_FLAG_TC2 :\
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA1_Channel3))? DMA_FLAG_TC3 :\
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA2_Channel3))? DMA_FLAG_TC3 :\
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA1_Channel4))? DMA_FLAG_TC4 :\
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA2_Channel4))? DMA_FLAG_TC4 :\
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA1_Channel5))? DMA_FLAG_TC5 :\
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA2_Channel5))? DMA_FLAG_TC5 :\
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA1_Channel6))? DMA_FLAG_TC6 :\
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA2_Channel6))? DMA_FLAG_TC6 :\
   DMA_FLAG_TC7)

   
                                                                       
                                
                                                            
    
#define __HAL_DMA_GET_HT_FLAG_INDEX(__HANDLE__) \
(((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA1_Channel1))? DMA_FLAG_HT1 :\
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA2_Channel1))? DMA_FLAG_HT1 :\
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA1_Channel2))? DMA_FLAG_HT2 :\
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA2_Channel2))? DMA_FLAG_HT2 :\
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA1_Channel3))? DMA_FLAG_HT3 :\
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA2_Channel3))? DMA_FLAG_HT3 :\
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA1_Channel4))? DMA_FLAG_HT4 :\
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA2_Channel4))? DMA_FLAG_HT4 :\
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA1_Channel5))? DMA_FLAG_HT5 :\
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA2_Channel5))? DMA_FLAG_HT5 :\
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA1_Channel6))? DMA_FLAG_HT6 :\
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA2_Channel6))? DMA_FLAG_HT6 :\
   DMA_FLAG_HT7)

   
                                                               
                                 
                                                    
    
#define __HAL_DMA_GET_TE_FLAG_INDEX(__HANDLE__) \
(((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA1_Channel1))? DMA_FLAG_TE1 :\
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA2_Channel1))? DMA_FLAG_TE1 :\
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA1_Channel2))? DMA_FLAG_TE2 :\
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA2_Channel2))? DMA_FLAG_TE2 :\
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA1_Channel3))? DMA_FLAG_TE3 :\
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA2_Channel3))? DMA_FLAG_TE3 :\
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA1_Channel4))? DMA_FLAG_TE4 :\
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA2_Channel4))? DMA_FLAG_TE4 :\
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA1_Channel5))? DMA_FLAG_TE5 :\
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA2_Channel5))? DMA_FLAG_TE5 :\
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA1_Channel6))? DMA_FLAG_TE6 :\
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA2_Channel6))? DMA_FLAG_TE6 :\
   DMA_FLAG_TE7)

   
                                                                 
                                 
                                                    
    
#define __HAL_DMA_GET_GI_FLAG_INDEX(__HANDLE__) \
(((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA1_Channel1))? DMA_FLAG_GI1 :\
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA2_Channel1))? DMA_FLAG_GI1 :\
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA1_Channel2))? DMA_FLAG_GI2 :\
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA2_Channel2))? DMA_FLAG_GI2 :\
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA1_Channel3))? DMA_FLAG_GI3 :\
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA2_Channel3))? DMA_FLAG_GI3 :\
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA1_Channel4))? DMA_FLAG_GI4 :\
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA2_Channel4))? DMA_FLAG_GI4 :\
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA1_Channel5))? DMA_FLAG_GI5 :\
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA2_Channel5))? DMA_FLAG_GI5 :\
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA1_Channel6))? DMA_FLAG_GI6 :\
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA2_Channel6))? DMA_FLAG_GI6 :\
   DMA_FLAG_GI7)

   
                                              
                                 
                                            
                                                                           
                                                         
                                                              
                                                      
                                                        
                                                                                                    
                                             
    
#define __HAL_DMA_GET_FLAG(__HANDLE__, __FLAG__) (((uint32_t)((__HANDLE__)->Instance) > ((uint32_t)DMA1_Channel7))? \
                                                  (DMA2->ISR & (__FLAG__)) : (DMA1->ISR & (__FLAG__)))

   
                                                
                                 
                                                 
                                                                           
                                                         
                                                              
                                                      
                                                        
                                                                                                    
                
    
#define __HAL_DMA_CLEAR_FLAG(__HANDLE__, __FLAG__) (((uint32_t)((__HANDLE__)->Instance) > ((uint32_t)DMA1_Channel7))? \
                                                    (DMA2->IFCR = (__FLAG__)) : (DMA1->IFCR = (__FLAG__)))

   
                                                        
                                 
                                                                                       
                                                                           
                                                                
                                                                     
                                                             
                
    
#define __HAL_DMA_ENABLE_IT(__HANDLE__, __INTERRUPT__)   ((__HANDLE__)->Instance->CCR |= (__INTERRUPT__))

   
                                                         
                                 
                                                                                       
                                                                           
                                                                
                                                                     
                                                             
                
    
#define __HAL_DMA_DISABLE_IT(__HANDLE__, __INTERRUPT__)  ((__HANDLE__)->Instance->CCR &= ~(__INTERRUPT__))

   
                                                                                     
                                 
                                                                      
                                                               
                                                                
                                                                     
                                                             
                                               
    
#define __HAL_DMA_GET_IT_SOURCE(__HANDLE__, __INTERRUPT__)  (((__HANDLE__)->Instance->CCR & (__INTERRUPT__)))

   
                                                                                           
                                 
                                                                                   
    
#define __HAL_DMA_GET_COUNTER(__HANDLE__) ((__HANDLE__)->Instance->CNDTR)

   
      
    

#if defined(DMAMUX1)
                                      
#include "stm32l4xx_hal_dma_ex.h"

#endif              
                                                                                

                                      
      
    

                                             
      
    
                                                                                
HAL_StatusTypeDef HAL_DMA_Init(DMA_HandleTypeDef *hdma);
HAL_StatusTypeDef HAL_DMA_DeInit(DMA_HandleTypeDef *hdma);
   
      
    

                                             
      
    
                                                                                
HAL_StatusTypeDef HAL_DMA_Start(DMA_HandleTypeDef *hdma, uint32_t SrcAddress, uint32_t DstAddress, uint32_t DataLength);
HAL_StatusTypeDef HAL_DMA_Start_IT(DMA_HandleTypeDef *hdma, uint32_t SrcAddress, uint32_t DstAddress,
                                   uint32_t DataLength);
HAL_StatusTypeDef HAL_DMA_Abort(DMA_HandleTypeDef *hdma);
HAL_StatusTypeDef HAL_DMA_Abort_IT(DMA_HandleTypeDef *hdma);
HAL_StatusTypeDef HAL_DMA_PollForTransfer(DMA_HandleTypeDef *hdma, HAL_DMA_LevelCompleteTypeDef CompleteLevel,
                                          uint32_t Timeout);
void HAL_DMA_IRQHandler(DMA_HandleTypeDef *hdma);
HAL_StatusTypeDef HAL_DMA_RegisterCallback(DMA_HandleTypeDef *hdma, HAL_DMA_CallbackIDTypeDef CallbackID, void (* pCallback)(DMA_HandleTypeDef *_hdma));
HAL_StatusTypeDef HAL_DMA_UnRegisterCallback(DMA_HandleTypeDef *hdma, HAL_DMA_CallbackIDTypeDef CallbackID);

   
      
    

                                             
      
    
                                                                                
HAL_DMA_StateTypeDef HAL_DMA_GetState(DMA_HandleTypeDef *hdma);
uint32_t             HAL_DMA_GetError(DMA_HandleTypeDef *hdma);
   
      
    

   
      
    

                                                                                
                                                   
      
    

#define IS_DMA_DIRECTION(DIRECTION)             (((DIRECTION) == DMA_PERIPH_TO_MEMORY ) || \
                                                 ((DIRECTION) == DMA_MEMORY_TO_PERIPH)  || \
                                                 ((DIRECTION) == DMA_MEMORY_TO_MEMORY))

#define IS_DMA_BUFFER_SIZE(SIZE)                (((SIZE) >= 0x1U) && ((SIZE) < DMA_CNDTR_NDT))

#define IS_DMA_PERIPHERAL_INC_STATE(STATE)      (((STATE) == DMA_PINC_ENABLE) || \
                                                 ((STATE) == DMA_PINC_DISABLE))

#define IS_DMA_MEMORY_INC_STATE(STATE)          (((STATE) == DMA_MINC_ENABLE)  || \
                                                 ((STATE) == DMA_MINC_DISABLE))

#if defined(DMAMUX1)
#define IS_DMA_ALL_REQUEST(REQUEST)             ((REQUEST) <= DMA_MAX_REQUEST)
#else
#define IS_DMA_ALL_REQUEST(REQUEST)             (((REQUEST) == DMA_REQUEST_0) || \
                                                 ((REQUEST) == DMA_REQUEST_1) || \
                                                 ((REQUEST) == DMA_REQUEST_2) || \
                                                 ((REQUEST) == DMA_REQUEST_3) || \
                                                 ((REQUEST) == DMA_REQUEST_4) || \
                                                 ((REQUEST) == DMA_REQUEST_5) || \
                                                 ((REQUEST) == DMA_REQUEST_6) || \
                                                 ((REQUEST) == DMA_REQUEST_7))
#endif              

#define IS_DMA_PERIPHERAL_DATA_SIZE(SIZE)       (((SIZE) == DMA_PDATAALIGN_BYTE)     || \
                                                 ((SIZE) == DMA_PDATAALIGN_HALFWORD) || \
                                                 ((SIZE) == DMA_PDATAALIGN_WORD))

#define IS_DMA_MEMORY_DATA_SIZE(SIZE)           (((SIZE) == DMA_MDATAALIGN_BYTE)     || \
                                                 ((SIZE) == DMA_MDATAALIGN_HALFWORD) || \
                                                 ((SIZE) == DMA_MDATAALIGN_WORD ))

#define IS_DMA_MODE(MODE)                       (((MODE) == DMA_NORMAL )  || \
                                                 ((MODE) == DMA_CIRCULAR))

#define IS_DMA_PRIORITY(PRIORITY)               (((PRIORITY) == DMA_PRIORITY_LOW )   || \
                                                 ((PRIORITY) == DMA_PRIORITY_MEDIUM) || \
                                                 ((PRIORITY) == DMA_PRIORITY_HIGH)   || \
                                                 ((PRIORITY) == DMA_PRIORITY_VERY_HIGH))

   
      
    

                                                                                

   
      
    

   
      
    

#ifdef __cplusplus
}
#endif

#endif                          

