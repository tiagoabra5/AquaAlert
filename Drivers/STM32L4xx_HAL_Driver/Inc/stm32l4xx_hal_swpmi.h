/**
  ******************************************************************************
  * @file    stm32l4xx_hal_swpmi.h
  * @author  MCD Application Team
  * @brief   Header file of SWPMI HAL module.
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

                                                                                
#ifndef STM32L4xx_HAL_SWPMI_H
#define STM32L4xx_HAL_SWPMI_H

#ifdef __cplusplus
extern "C" {
#endif

                                                                                
#include "stm32l4xx_hal_def.h"

                                    
      
    

#if defined(SWPMI1)

                     
      
    

                                                                                
                                                       
      
    

   
                                          
    
typedef struct
{
  uint32_t VoltageClass;                                                  
                                                                                                      

  uint32_t BitRate;                                                   
                                                                                            
                                                                                              
                                                                                         
                                            

  uint32_t TxBufferingMode;                                                         
                                                                                                          

  uint32_t RxBufferingMode;                                                      
                                                                                                          

} SWPMI_InitTypeDef;


   
                                                
    
typedef enum
{
  HAL_SWPMI_STATE_RESET             = 0x00,                                                              
  HAL_SWPMI_STATE_READY             = 0x01,                                                              
  HAL_SWPMI_STATE_BUSY              = 0x02,                                                              
  HAL_SWPMI_STATE_BUSY_TX           = 0x12,                                                              
  HAL_SWPMI_STATE_BUSY_RX           = 0x22,                                                              
  HAL_SWPMI_STATE_BUSY_TX_RX        = 0x32,                                                              
  HAL_SWPMI_STATE_TIMEOUT           = 0x03,                                                              
  HAL_SWPMI_STATE_ERROR             = 0x04                                                               
} HAL_SWPMI_StateTypeDef;

   
                                             
    
#if (USE_HAL_SWPMI_REGISTER_CALLBACKS == 1)
typedef struct __SWPMI_HandleTypeDef
#else
typedef struct
#endif                                       
{
  SWPMI_TypeDef                  *Instance;                                                 

  SWPMI_InitTypeDef              Init;                                                      

  const uint32_t                 *pTxBuffPtr;                                               

  uint32_t                       TxXferSize;                                                

  uint32_t                       TxXferCount;                                               

  uint32_t                       *pRxBuffPtr;                                               

  uint32_t                       RxXferSize;                                                

  uint32_t                       RxXferCount;                                               

  DMA_HandleTypeDef              *hdmatx;                                                   

  DMA_HandleTypeDef              *hdmarx;                                                   

  HAL_LockTypeDef                Lock;                                                      

  __IO HAL_SWPMI_StateTypeDef    State;                                                     

  __IO uint32_t                  ErrorCode;                                                 

#if (USE_HAL_SWPMI_REGISTER_CALLBACKS == 1)
  void (*RxCpltCallback)(struct __SWPMI_HandleTypeDef *hswpmi);                                             
  void (*RxHalfCpltCallback)(struct __SWPMI_HandleTypeDef *hswpmi);                                              
  void (*TxCpltCallback)(struct __SWPMI_HandleTypeDef *hswpmi);                                              
  void (*TxHalfCpltCallback)(struct __SWPMI_HandleTypeDef *hswpmi);                                               
  void (*ErrorCallback)(struct __SWPMI_HandleTypeDef *hswpmi);                                   
  void (*MspInitCallback)(struct __SWPMI_HandleTypeDef *hswpmi);                                    
  void (*MspDeInitCallback)(struct __SWPMI_HandleTypeDef *hswpmi);                                     
#endif                                       

} SWPMI_HandleTypeDef;

#if (USE_HAL_SWPMI_REGISTER_CALLBACKS == 1)
   
                                                    
    
typedef enum
{
  HAL_SWPMI_RX_COMPLETE_CB_ID     = 0x00U,                                           
  HAL_SWPMI_RX_HALFCOMPLETE_CB_ID = 0x01U,                                                
  HAL_SWPMI_TX_COMPLETE_CB_ID     = 0x02U,                                            
  HAL_SWPMI_TX_HALFCOMPLETE_CB_ID = 0x03U,                                                 
  HAL_SWPMI_ERROR_CB_ID           = 0x04U,                                
  HAL_SWPMI_MSPINIT_CB_ID         = 0x05U,                                   
  HAL_SWPMI_MSPDEINIT_CB_ID       = 0x06U                                       
} HAL_SWPMI_CallbackIDTypeDef;

   
                                             
    
typedef void (*pSWPMI_CallbackTypeDef)(SWPMI_HandleTypeDef *hswpmi);
#endif                                       

   
      
    

                                                                                
                                                               
      
    

   
                                                      
      
    
#define HAL_SWPMI_ERROR_NONE                  ((uint32_t)0x00000000)                              
#define HAL_SWPMI_ERROR_UDR                   ((uint32_t)0x00000002)                              
#define HAL_SWPMI_ERROR_CRC                   ((uint32_t)0x00000004)                              
#define HAL_SWPMI_ERROR_OVR                   ((uint32_t)0x00000008)                              
#define HAL_SWPMI_ERROR_DMA                   ((uint32_t)0x00000010)                              
#define HAL_SWPMI_ERROR_TIMEOUT               ((uint32_t)0x00000020)                              
#define HAL_SWPMI_ERROR_TXBEF_TIMEOUT         ((uint32_t)0x00000040)                              
#if (USE_HAL_SWPMI_REGISTER_CALLBACKS == 1)
#define HAL_SWPMI_ERROR_INVALID_CALLBACK      ((uint32_t)0x00000100)                               
#endif                                       
   
      
    

                                                     
      
    
#define SWPMI_VOLTAGE_CLASS_C                ((uint32_t)0x00000000)
#define SWPMI_VOLTAGE_CLASS_B                SWPMI_OR_CLASS
   
      
    

                                                             
      
    
#define SWPMI_TX_NO_SOFTWAREBUFFER           ((uint32_t)0x00000000)
#define SWPMI_TX_SINGLE_SOFTWAREBUFFER       ((uint32_t)0x00000000)
#define SWPMI_TX_MULTI_SOFTWAREBUFFER        SWPMI_CR_TXMODE
   
      
    

                                                             
      
    
#define SWPMI_RX_NO_SOFTWAREBUFFER           ((uint32_t)0x00000000)
#define SWPMI_RX_SINGLE_SOFTWAREBUFFER       ((uint32_t)0x00000000)
#define SWPMI_RX_MULTI_SOFTWAREBUFFER        SWPMI_CR_RXMODE
   
      
    

                                            
                                                 
                                                           
      
    
#define SWPMI_FLAG_RXBFF                 SWPMI_ISR_RXBFF
#define SWPMI_FLAG_TXBEF                 SWPMI_ISR_TXBEF
#define SWPMI_FLAG_RXBERF                SWPMI_ISR_RXBERF
#define SWPMI_FLAG_RXOVRF                SWPMI_ISR_RXOVRF
#define SWPMI_FLAG_TXUNRF                SWPMI_ISR_TXUNRF
#define SWPMI_FLAG_RXNE                  SWPMI_ISR_RXNE
#define SWPMI_FLAG_TXE                   SWPMI_ISR_TXE
#define SWPMI_FLAG_TCF                   SWPMI_ISR_TCF
#define SWPMI_FLAG_SRF                   SWPMI_ISR_SRF
#define SWPMI_FLAG_SUSP                  SWPMI_ISR_SUSP
#define SWPMI_FLAG_DEACTF                SWPMI_ISR_DEACTF
   
      
    

                                                                    
                                             
                                                       
      
    
#define SWPMI_IT_SRIE                    SWPMI_IER_SRIE
#define SWPMI_IT_TCIE                    SWPMI_IER_TCIE
#define SWPMI_IT_TIE                     SWPMI_IER_TIE
#define SWPMI_IT_RIE                     SWPMI_IER_RIE
#define SWPMI_IT_TXUNRIE                 SWPMI_IER_TXUNRIE
#define SWPMI_IT_RXOVRIE                 SWPMI_IER_RXOVRIE
#define SWPMI_IT_RXBERIE                 SWPMI_IER_RXBERIE
#define SWPMI_IT_TXBEIE                  SWPMI_IER_TXBEIE
#define SWPMI_IT_RXBFIE                  SWPMI_IER_RXBFIE
   
      
    

   
      
    

                                                                                
                                                         
      
    

                                    
                                                  
                
    
#if (USE_HAL_SWPMI_REGISTER_CALLBACKS == 1)
#define __HAL_SWPMI_RESET_HANDLE_STATE(__HANDLE__) do{                                              \
                                                       (__HANDLE__)->State = HAL_SWPMI_STATE_RESET; \
                                                       (__HANDLE__)->MspInitCallback = NULL;        \
                                                       (__HANDLE__)->MspDeInitCallback = NULL;      \
                                                     } while(0)
#else
#define __HAL_SWPMI_RESET_HANDLE_STATE(__HANDLE__) ((__HANDLE__)->State = HAL_SWPMI_STATE_RESET)
#endif                                       

   
                                        
                                   
                
    
#define __HAL_SWPMI_ENABLE(__HANDLE__)   SET_BIT((__HANDLE__)->Instance->CR, SWPMI_CR_SWPACT)

   
                                         
                                   
                
    
#define __HAL_SWPMI_DISABLE(__HANDLE__)  CLEAR_BIT((__HANDLE__)->Instance->CR, SWPMI_CR_SWPACT)

                                                                 
                                                  
                                                 
                                                             
                                                               
                                                                 
                                                              
                                                                  
                                                                    
                                                                     
                                                                 
                                                           
                                                      
                                                  
                                                        
                                                      
    
#define __HAL_SWPMI_GET_FLAG(__HANDLE__, __FLAG__) (READ_BIT((__HANDLE__)->Instance->ISR, (__FLAG__)) == (__FLAG__))

                                               
                                                  
                                                 
                                                             
                                                               
                                                                 
                                                              
                                                                  
                                                                    
                                                           
                                                      
                
    
#define __HAL_SWPMI_CLEAR_FLAG(__HANDLE__, __FLAG__) WRITE_REG((__HANDLE__)->Instance->ICR, (__FLAG__))

                                                 
                                                  
                                                                         
                                                               
                                                          
                                                               
                                                      
                                                     
                                                                        
                                                                      
                                                                 
                                                                      
                                                                    
                
    
#define __HAL_SWPMI_ENABLE_IT(__HANDLE__, __INTERRUPT__)   SET_BIT((__HANDLE__)->Instance->IER, (__INTERRUPT__))

                                                  
                                                  
                                                                          
                                                               
                                                          
                                                               
                                                      
                                                     
                                                                        
                                                                      
                                                                 
                                                                      
                                                                    
                
    
#define __HAL_SWPMI_DISABLE_IT(__HANDLE__, __INTERRUPT__)  CLEAR_BIT((__HANDLE__)->Instance->IER, (__INTERRUPT__))

                                                                            
                                                  
                                                          
                                                               
                                                          
                                                               
                                                      
                                                     
                                                                        
                                                                      
                                                                  
                                                                      
                                                                    
                                                    
    
#define __HAL_SWPMI_GET_IT(__HANDLE__, __IT__)  (READ_BIT((__HANDLE__)->Instance->ISR,(__IT__)) == (__IT__))

                                                                                 
                                                  
                                                                 
                                                               
                                                          
                                                               
                                                      
                                                     
                                                                        
                                                                      
                                                                  
                                                                      
                                                                    
                                                    
    
#define __HAL_SWPMI_GET_IT_SOURCE(__HANDLE__, __IT__) ((READ_BIT((__HANDLE__)->Instance->IER, (__IT__))\
                                                        == (__IT__)) ? SET : RESET)

   
      
    

                                                                                
                                                               
      
    
                                                                                
HAL_StatusTypeDef HAL_SWPMI_Init(SWPMI_HandleTypeDef *hswpmi);
HAL_StatusTypeDef HAL_SWPMI_DeInit(SWPMI_HandleTypeDef *hswpmi);
void              HAL_SWPMI_MspInit(SWPMI_HandleTypeDef *hswpmi);
void              HAL_SWPMI_MspDeInit(SWPMI_HandleTypeDef *hswpmi);

#if (USE_HAL_SWPMI_REGISTER_CALLBACKS == 1)
                                                                                  
HAL_StatusTypeDef HAL_SWPMI_RegisterCallback(SWPMI_HandleTypeDef        *hswpmi,
                                             HAL_SWPMI_CallbackIDTypeDef CallbackID,
                                             pSWPMI_CallbackTypeDef      pCallback);
HAL_StatusTypeDef HAL_SWPMI_UnRegisterCallback(SWPMI_HandleTypeDef        *hswpmi,
                                               HAL_SWPMI_CallbackIDTypeDef CallbackID);
#endif                                       

                                                                                
HAL_StatusTypeDef HAL_SWPMI_Transmit(SWPMI_HandleTypeDef *hswpmi, const uint32_t *pData, uint16_t Size,
                                     uint32_t Timeout);
HAL_StatusTypeDef HAL_SWPMI_Receive(SWPMI_HandleTypeDef *hswpmi, uint32_t *pData, uint16_t Size, uint32_t Timeout);
HAL_StatusTypeDef HAL_SWPMI_Transmit_IT(SWPMI_HandleTypeDef *hswpmi, const uint32_t *pData, uint16_t Size);
HAL_StatusTypeDef HAL_SWPMI_Receive_IT(SWPMI_HandleTypeDef *hswpmi, uint32_t *pData, uint16_t Size);
HAL_StatusTypeDef HAL_SWPMI_Transmit_DMA(SWPMI_HandleTypeDef *hswpmi, const uint32_t *pData, uint16_t Size);
HAL_StatusTypeDef HAL_SWPMI_Receive_DMA(SWPMI_HandleTypeDef *hswpmi, uint32_t *pData, uint16_t Size);
HAL_StatusTypeDef HAL_SWPMI_DMAStop(SWPMI_HandleTypeDef *hswpmi);
HAL_StatusTypeDef HAL_SWPMI_EnableLoopback(SWPMI_HandleTypeDef *hswpmi);
HAL_StatusTypeDef HAL_SWPMI_DisableLoopback(SWPMI_HandleTypeDef *hswpmi);
void              HAL_SWPMI_IRQHandler(SWPMI_HandleTypeDef *hswpmi);
void              HAL_SWPMI_TxCpltCallback(SWPMI_HandleTypeDef *hswpmi);
void              HAL_SWPMI_TxHalfCpltCallback(SWPMI_HandleTypeDef *hswpmi);
void              HAL_SWPMI_RxCpltCallback(SWPMI_HandleTypeDef *hswpmi);
void              HAL_SWPMI_RxHalfCpltCallback(SWPMI_HandleTypeDef *hswpmi);
void              HAL_SWPMI_ErrorCallback(SWPMI_HandleTypeDef *hswpmi);

                                                                                
HAL_SWPMI_StateTypeDef HAL_SWPMI_GetState(const SWPMI_HandleTypeDef *hswpmi);
uint32_t               HAL_SWPMI_GetError(const SWPMI_HandleTypeDef *hswpmi);

   
      
    

                                                                                
                                                     
      
    

   
      
    

                                                                                
                                                             
      
    

   
      
    

                                                                                
                                                             
      
    

   
      
    

                                                                                
                                                       
      
    


#define IS_SWPMI_VOLTAGE_CLASS(__CLASS__)    (((__CLASS__) == SWPMI_VOLTAGE_CLASS_C) || \
                                              ((__CLASS__) == SWPMI_VOLTAGE_CLASS_B))

#define IS_SWPMI_BITRATE_VALUE(__VALUE__)    (((__VALUE__) <= 63U))


#define IS_SWPMI_TX_BUFFERING_MODE(__MODE__) (((__MODE__) == SWPMI_TX_NO_SOFTWAREBUFFER) || \
                                              ((__MODE__) == SWPMI_TX_MULTI_SOFTWAREBUFFER))


#define IS_SWPMI_RX_BUFFERING_MODE(__MODE__) (((__MODE__) == SWPMI_RX_NO_SOFTWAREBUFFER) || \
                                              ((__MODE__) == SWPMI_RX_MULTI_SOFTWAREBUFFER))

   
      
    

   
      
    

#endif             

   
      
    

#ifdef __cplusplus
}
#endif

#endif                            
