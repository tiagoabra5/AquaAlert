/**
  ******************************************************************************
  * @file    stm32l4xx_hal_irda.h
  * @author  MCD Application Team
  * @brief   Header file of IRDA HAL module.
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

                                                                                
#ifndef STM32L4xx_HAL_IRDA_H
#define STM32L4xx_HAL_IRDA_H

#ifdef __cplusplus
extern "C" {
#endif

                                                                                
#include "stm32l4xx_hal_def.h"

                                    
      
    

                    
      
    

                                                                                
                                                     
      
    

   
                                         
    
typedef struct
{
  uint32_t BaudRate;                                                                               
                                                                                                          
                                                                                                                  
                                                                                                                   

  uint32_t WordLength;                                                                                          
                                                                                                      

  uint32_t Parity;                                                   
                                                                                            
                                                                                                        
                                                                                                          
                                                                                                        
                                                                                       

  uint32_t Mode;                                                                                                 
                                                                                                      

  uint8_t  Prescaler;                                                                                            
                                                                          
                                                                                  

  uint16_t PowerMode;                                                    
                                                                                                  

#if defined(USART_PRESC_PRESCALER)
  uint32_t ClockPrescaler;                                                                                    
                                                                                                        

#endif                            
} IRDA_InitTypeDef;

   
                                    
                                                                          
                                                               
                                                                                       
                                                           
                                                                
                                     
                             
                               
                            
                          
                                                    
                                                       
                                                                                              
                              
                                        
                                           
                          
                                                                                          
                              
                                       
                            
                                                    
                                                
                                                                   
                                                                 
                              
                                        
                                                    
                                                       
                                                       
                              
                                         
                            
                                                    
                                                
                              
                                        
    
typedef uint32_t HAL_IRDA_StateTypeDef;

   
                                        
    
typedef enum
{
  IRDA_CLOCKSOURCE_PCLK1      = 0x00U,                                      
  IRDA_CLOCKSOURCE_PCLK2      = 0x01U,                                      
  IRDA_CLOCKSOURCE_HSI        = 0x02U,                                      
  IRDA_CLOCKSOURCE_SYSCLK     = 0x04U,                                      
  IRDA_CLOCKSOURCE_LSE        = 0x10U,                                      
  IRDA_CLOCKSOURCE_UNDEFINED  = 0x20U                                       
} IRDA_ClockSourceTypeDef;

   
                                            
    
#if (USE_HAL_IRDA_REGISTER_CALLBACKS == 1)
typedef struct __IRDA_HandleTypeDef
#else
typedef struct
#endif                                       
{
  USART_TypeDef            *Instance;                                                  

  IRDA_InitTypeDef         Init;                                                       

  const uint8_t            *pTxBuffPtr;                                                

  uint16_t                 TxXferSize;                                                 

  __IO uint16_t            TxXferCount;                                                

  uint8_t                  *pRxBuffPtr;                                                

  uint16_t                 RxXferSize;                                                 

  __IO uint16_t            RxXferCount;                                                

  uint16_t                 Mask;                                                       

  DMA_HandleTypeDef        *hdmatx;                                                    

  DMA_HandleTypeDef        *hdmarx;                                                    

  HAL_LockTypeDef          Lock;                                                       

  __IO HAL_IRDA_StateTypeDef    gState;                                                                     
                                                                                    
                                                                                                                

  __IO HAL_IRDA_StateTypeDef    RxState;                                                          
                                                                                                                

  __IO uint32_t            ErrorCode;                                                  

#if (USE_HAL_IRDA_REGISTER_CALLBACKS == 1)
  void (* TxHalfCpltCallback)(struct __IRDA_HandleTypeDef *hirda);                                                     

  void (* TxCpltCallback)(struct __IRDA_HandleTypeDef *hirda);                                                         

  void (* RxHalfCpltCallback)(struct __IRDA_HandleTypeDef *hirda);                                                     

  void (* RxCpltCallback)(struct __IRDA_HandleTypeDef *hirda);                                                         

  void (* ErrorCallback)(struct __IRDA_HandleTypeDef *hirda);                                                          

  void (* AbortCpltCallback)(struct __IRDA_HandleTypeDef *hirda);                                                      

  void (* AbortTransmitCpltCallback)(struct __IRDA_HandleTypeDef *hirda);                                              

  void (* AbortReceiveCpltCallback)(struct __IRDA_HandleTypeDef *hirda);                                               


  void (* MspInitCallback)(struct __IRDA_HandleTypeDef *hirda);                                                        

  void (* MspDeInitCallback)(struct __IRDA_HandleTypeDef *hirda);                                                      
#endif                                       

} IRDA_HandleTypeDef;

#if (USE_HAL_IRDA_REGISTER_CALLBACKS == 1)
   
                                                       
    
typedef enum
{
  HAL_IRDA_TX_HALFCOMPLETE_CB_ID         = 0x00U,                                                    
  HAL_IRDA_TX_COMPLETE_CB_ID             = 0x01U,                                                    
  HAL_IRDA_RX_HALFCOMPLETE_CB_ID         = 0x02U,                                                    
  HAL_IRDA_RX_COMPLETE_CB_ID             = 0x03U,                                                    
  HAL_IRDA_ERROR_CB_ID                   = 0x04U,                                                    
  HAL_IRDA_ABORT_COMPLETE_CB_ID          = 0x05U,                                                    
  HAL_IRDA_ABORT_TRANSMIT_COMPLETE_CB_ID = 0x06U,                                                    
  HAL_IRDA_ABORT_RECEIVE_COMPLETE_CB_ID  = 0x07U,                                                    

  HAL_IRDA_MSPINIT_CB_ID                 = 0x08U,                                                    
  HAL_IRDA_MSPDEINIT_CB_ID               = 0x09U                                                     

} HAL_IRDA_CallbackIDTypeDef;

   
                                                
    
typedef  void (*pIRDA_CallbackTypeDef)(IRDA_HandleTypeDef *hirda);                                              

#endif                                      

   
      
    

                                                                                
                                                             
      
    

                                                              
      
    
#define HAL_IRDA_STATE_RESET                0x00000000U                                     
                                                                                                         
#define HAL_IRDA_STATE_READY                0x00000020U                                                
                                                                                                         
#define HAL_IRDA_STATE_BUSY                 0x00000024U                                      
                                                                                                  
#define HAL_IRDA_STATE_BUSY_TX              0x00000021U                                            
                                                                                                  
#define HAL_IRDA_STATE_BUSY_RX              0x00000022U                                         
                                                                                                   
#define HAL_IRDA_STATE_BUSY_TX_RX           0x00000023U                                                          
                                                                                                             
                                                                                                          
                                                                                           
#define HAL_IRDA_STATE_TIMEOUT              0x000000A0U                     
                                                                                                  
#define HAL_IRDA_STATE_ERROR                0x000000E0U             
                                                                                                  
   
      
    

                                                              
      
    
#define HAL_IRDA_ERROR_NONE                 (0x00000000U)                                         
#define HAL_IRDA_ERROR_PE                   (0x00000001U)                                         
#define HAL_IRDA_ERROR_NE                   (0x00000002U)                                         
#define HAL_IRDA_ERROR_FE                   (0x00000004U)                                         
#define HAL_IRDA_ERROR_ORE                  (0x00000008U)                                         
#define HAL_IRDA_ERROR_DMA                  (0x00000010U)                                         
#define HAL_IRDA_ERROR_BUSY                 (0x00000020U)                                         
#if (USE_HAL_IRDA_REGISTER_CALLBACKS == 1)
#define HAL_IRDA_ERROR_INVALID_CALLBACK     (0x00000040U)                                         
#endif                                      
   
      
    

                                     
      
    
#define IRDA_PARITY_NONE                    0x00000000U                                         
#define IRDA_PARITY_EVEN                    USART_CR1_PCE                                       
#define IRDA_PARITY_ODD                     (USART_CR1_PCE | USART_CR1_PS)                      
   
      
    

                                                   
      
    
#define IRDA_MODE_RX                        USART_CR1_RE                                         
#define IRDA_MODE_TX                        USART_CR1_TE                                         
#define IRDA_MODE_TX_RX                     (USART_CR1_TE |USART_CR1_RE)                         
   
      
    

                                           
      
    
#define IRDA_POWERMODE_NORMAL               0x00000000U                                     
#define IRDA_POWERMODE_LOWPOWER             USART_CR3_IRLP                                  
   
      
    

#if defined(USART_PRESC_PRESCALER)
                                                      
      
    
#define IRDA_PRESCALER_DIV1    0x00000000U                              
#define IRDA_PRESCALER_DIV2    0x00000001U                              
#define IRDA_PRESCALER_DIV4    0x00000002U                              
#define IRDA_PRESCALER_DIV6    0x00000003U                              
#define IRDA_PRESCALER_DIV8    0x00000004U                              
#define IRDA_PRESCALER_DIV10   0x00000005U                              
#define IRDA_PRESCALER_DIV12   0x00000006U                              
#define IRDA_PRESCALER_DIV16   0x00000007U                              
#define IRDA_PRESCALER_DIV32   0x00000008U                              
#define IRDA_PRESCALER_DIV64   0x00000009U                              
#define IRDA_PRESCALER_DIV128  0x0000000AU                              
#define IRDA_PRESCALER_DIV256  0x0000000BU                              
   
      
    

#endif                            
                                   
      
    
#define IRDA_STATE_DISABLE                  0x00000000U                           
#define IRDA_STATE_ENABLE                   USART_CR1_UE                          
   
      
    

                                 
      
    
#define IRDA_MODE_DISABLE                   0x00000000U                                                   
#define IRDA_MODE_ENABLE                    USART_CR3_IREN                                                
   
      
    

                                                
      
    
#define IRDA_ONE_BIT_SAMPLE_DISABLE         0x00000000U                                        
#define IRDA_ONE_BIT_SAMPLE_ENABLE          USART_CR3_ONEBIT                                   
   
      
    

                                     
      
    
#define IRDA_DMA_TX_DISABLE                 0x00000000U                                   
#define IRDA_DMA_TX_ENABLE                  USART_CR3_DMAT                                
   
      
    

                                     
      
    
#define IRDA_DMA_RX_DISABLE                 0x00000000U                                   
#define IRDA_DMA_RX_ENABLE                  USART_CR3_DMAR                                
   
      
    

                                                             
      
    
#define IRDA_AUTOBAUD_REQUEST            USART_RQR_ABRRQ                                           
#define IRDA_RXDATA_FLUSH_REQUEST        USART_RQR_RXFRQ                                           
#define IRDA_TXDATA_FLUSH_REQUEST        USART_RQR_TXFRQ                                           
   
      
    

                                   
                                             
                                                       
      
    
#define IRDA_FLAG_REACK                     USART_ISR_REACK                                                          
#define IRDA_FLAG_TEACK                     USART_ISR_TEACK                                                          
#define IRDA_FLAG_BUSY                      USART_ISR_BUSY                                                           
#define IRDA_FLAG_ABRF                      USART_ISR_ABRF                                                           
#define IRDA_FLAG_ABRE                      USART_ISR_ABRE                                                           
#if defined(USART_CR1_FIFOEN)
#define IRDA_FLAG_TXE                       USART_ISR_TXE_TXFNF                                                      
#else
#define IRDA_FLAG_TXE                       USART_ISR_TXE                                                            
#endif                       
#define IRDA_FLAG_TC                        USART_ISR_TC                                                             
#if defined(USART_CR1_FIFOEN)
#define IRDA_FLAG_RXNE                      USART_ISR_RXNE_RXFNE                                                     
#else
#define IRDA_FLAG_RXNE                      USART_ISR_RXNE                                                           
#endif                       
#define IRDA_FLAG_ORE                       USART_ISR_ORE                                                            
#define IRDA_FLAG_NE                        USART_ISR_NE                                                             
#define IRDA_FLAG_FE                        USART_ISR_FE                                                             
#define IRDA_FLAG_PE                        USART_ISR_PE                                                             
   
      
    

                                                                  
                                                        
                                                                             
                                                       
                                      
                                      
                                      
                                                                
      
    
#define IRDA_IT_PE                          0x0028U                                                           
#define IRDA_IT_TXE                         0x0727U                                                           
#define IRDA_IT_TC                          0x0626U                                                           
#define IRDA_IT_RXNE                        0x0525U                                                           
#define IRDA_IT_IDLE                        0x0424U                                                           

                                                      
                                                                            
                                                      
                                     
                                     
                                        
#define IRDA_IT_ERR                         0x0060U                                             

                                                      
                                                                  
#define IRDA_IT_ORE                         0x0300U                                             
#define IRDA_IT_NE                          0x0200U                                             
#define IRDA_IT_FE                          0x0100U                                             
   
      
    

                                                               
      
    
#define IRDA_CLEAR_PEF                       USART_ICR_PECF                                                    
#define IRDA_CLEAR_FEF                       USART_ICR_FECF                                                    
#define IRDA_CLEAR_NEF                       USART_ICR_NECF                                                    
#define IRDA_CLEAR_OREF                      USART_ICR_ORECF                                                   
#define IRDA_CLEAR_IDLEF                     USART_ICR_IDLECF                                                  
#define IRDA_CLEAR_TCF                       USART_ICR_TCCF                                                    
   
      
    

                                                                  
      
    
#define IRDA_IT_MASK  0x001FU                                        
#define IRDA_CR_MASK  0x00E0U                                        
#define IRDA_CR_POS   5U                                             
#define IRDA_ISR_MASK 0x1F00U                                        
#define IRDA_ISR_POS  8U                                             
   
      
    

   
      
    

                                                                                
                                                       
      
    

                                    
                                   
                
    
#if USE_HAL_IRDA_REGISTER_CALLBACKS == 1
#define __HAL_IRDA_RESET_HANDLE_STATE(__HANDLE__)  do{                                                   \
                                                       (__HANDLE__)->gState = HAL_IRDA_STATE_RESET;      \
                                                       (__HANDLE__)->RxState = HAL_IRDA_STATE_RESET;     \
                                                       (__HANDLE__)->MspInitCallback = NULL;             \
                                                       (__HANDLE__)->MspDeInitCallback = NULL;           \
                                                     } while(0U)
#else
#define __HAL_IRDA_RESET_HANDLE_STATE(__HANDLE__)  do{                                                   \
                                                       (__HANDLE__)->gState = HAL_IRDA_STATE_RESET;      \
                                                       (__HANDLE__)->RxState = HAL_IRDA_STATE_RESET;     \
                                                     } while(0U)
#endif                                      

                                       
                                                 
                
    
#define __HAL_IRDA_FLUSH_DRREGISTER(__HANDLE__)                            \
  do{                                                                    \
    SET_BIT((__HANDLE__)->Instance->RQR, IRDA_RXDATA_FLUSH_REQUEST); \
    SET_BIT((__HANDLE__)->Instance->RQR, IRDA_TXDATA_FLUSH_REQUEST); \
  } while(0U)

                                                  
                                                 
                                                 
                                                                           
                                       
                                       
                                       
                                        
                                       
                                         
                
    
#define __HAL_IRDA_CLEAR_FLAG(__HANDLE__, __FLAG__) ((__HANDLE__)->Instance->ICR = (__FLAG__))

                                           
                                                 
                
    
#define __HAL_IRDA_CLEAR_PEFLAG(__HANDLE__)    __HAL_IRDA_CLEAR_FLAG((__HANDLE__), IRDA_CLEAR_PEF)


                                           
                                                 
                
    
#define __HAL_IRDA_CLEAR_FEFLAG(__HANDLE__)    __HAL_IRDA_CLEAR_FLAG((__HANDLE__), IRDA_CLEAR_FEF)

                                           
                                                 
                
    
#define __HAL_IRDA_CLEAR_NEFLAG(__HANDLE__)    __HAL_IRDA_CLEAR_FLAG((__HANDLE__), IRDA_CLEAR_NEF)

                                            
                                                 
                
    
#define __HAL_IRDA_CLEAR_OREFLAG(__HANDLE__)    __HAL_IRDA_CLEAR_FLAG((__HANDLE__), IRDA_CLEAR_OREF)

                                             
                                                 
                
    
#define __HAL_IRDA_CLEAR_IDLEFLAG(__HANDLE__)   __HAL_IRDA_CLEAR_FLAG((__HANDLE__), IRDA_CLEAR_IDLEF)

                                                                
                                                 
                                                 
                                                             
                                                                        
                                                                         
                                                  
                                                                      
                                                                            
                                                                          
                                                                   
                                                                             
                                                           
                                                         
                                                           
                                                          
                                                      
    
#define __HAL_IRDA_GET_FLAG(__HANDLE__, __FLAG__) (((__HANDLE__)->Instance->ISR & (__FLAG__)) == (__FLAG__))


                                                
                                                 
                                                                        
                                                               
                                                                            
                                                                     
                                                                               
                                                                   
                                                            
                                                                                              
                
    
#define __HAL_IRDA_ENABLE_IT(__HANDLE__, __INTERRUPT__)   (((((__INTERRUPT__) & IRDA_CR_MASK) >> IRDA_CR_POS) == 1U)? \
                                                           ((__HANDLE__)->Instance->CR1 |= (1U << \
                                                               ((__INTERRUPT__) & IRDA_IT_MASK))):\
                                                           ((((__INTERRUPT__) & IRDA_CR_MASK) >> IRDA_CR_POS) == 2U)? \
                                                           ((__HANDLE__)->Instance->CR2 |= (1U << \
                                                               ((__INTERRUPT__) & IRDA_IT_MASK))):\
                                                           ((__HANDLE__)->Instance->CR3 |= (1U << \
                                                               ((__INTERRUPT__) & IRDA_IT_MASK))))

                                                 
                                                 
                                                                         
                                                               
                                                                            
                                                                     
                                                                               
                                                                   
                                                            
                                                                                              
                
    
#define __HAL_IRDA_DISABLE_IT(__HANDLE__, __INTERRUPT__)  (((((__INTERRUPT__) & IRDA_CR_MASK) >> IRDA_CR_POS) == 1U)? \
                                                           ((__HANDLE__)->Instance->CR1 &= ~ (1U << \
                                                               ((__INTERRUPT__) & IRDA_IT_MASK))): \
                                                           ((((__INTERRUPT__) & IRDA_CR_MASK) >> IRDA_CR_POS) == 2U)? \
                                                           ((__HANDLE__)->Instance->CR2 &= ~ (1U << \
                                                               ((__INTERRUPT__) & IRDA_IT_MASK))): \
                                                           ((__HANDLE__)->Instance->CR3 &= ~ (1U << \
                                                               ((__INTERRUPT__) & IRDA_IT_MASK))))

                                                                           
                                                 
                                                                       
                                                               
                                                                           
                                                                    
                                                                               
                                                                   
                                                            
                                                         
                                                           
                                                          
                                                   
    
#define __HAL_IRDA_GET_IT(__HANDLE__, __INTERRUPT__) \
  ((((__HANDLE__)->Instance->ISR& (0x01U << (((__INTERRUPT__) & IRDA_ISR_MASK)>>IRDA_ISR_POS))) != 0U) ? SET : RESET)

                                                                                
                                                 
                                                                       
                                                               
                                                                           
                                                                    
                                                                               
                                                                   
                                                                              
                                                          
                                                   
    
#define __HAL_IRDA_GET_IT_SOURCE(__HANDLE__, __INTERRUPT__)                                                          \
  ((((((((__INTERRUPT__) & IRDA_CR_MASK) >>IRDA_CR_POS) == 0x01U)? (__HANDLE__)->Instance->CR1 :(((((__INTERRUPT__)  \
      & IRDA_CR_MASK) >> IRDA_CR_POS)== 0x02U)? (__HANDLE__)->Instance->CR2 :(__HANDLE__)->Instance->CR3))           \
     & (0x01U <<(((uint16_t)(__INTERRUPT__)) & IRDA_IT_MASK))) != 0U) ? SET : RESET)

                                                                                       
                                                 
                                                                                         
                                                              
                                                               
                                                               
                                                                
                                                                 
                                                                 
                                                                        
                
    
#define __HAL_IRDA_CLEAR_IT(__HANDLE__, __IT_CLEAR__) ((__HANDLE__)->Instance->ICR = (uint32_t)(__IT_CLEAR__))


                                             
                                                 
                                                     
                                                               
                                                                     
                                                                             
                                                                              
                
    
#define __HAL_IRDA_SEND_REQ(__HANDLE__, __REQ__) ((__HANDLE__)->Instance->RQR |= (uint16_t)(__REQ__))

                                                  
                                                 
                
    
#define __HAL_IRDA_ONE_BIT_SAMPLE_ENABLE(__HANDLE__) ((__HANDLE__)->Instance->CR3|= USART_CR3_ONEBIT)

                                                   
                                                 
                
    
#define __HAL_IRDA_ONE_BIT_SAMPLE_DISABLE(__HANDLE__) ((__HANDLE__)->Instance->CR3\
                                                       &= (uint32_t)~((uint32_t)USART_CR3_ONEBIT))

                                                        
                                                 
                
    
#define __HAL_IRDA_ENABLE(__HANDLE__)                   ((__HANDLE__)->Instance->CR1 |=  USART_CR1_UE)

                                                         
                                                 
                
    
#define __HAL_IRDA_DISABLE(__HANDLE__)                  ((__HANDLE__)->Instance->CR1 &=  ~USART_CR1_UE)

   
      
    

                                                                            
                                   
      
    

                                                                         
                                                                     
                         
    
#define IS_IRDA_BAUDRATE(__BAUDRATE__) ((__BAUDRATE__) < 115201U)

                                                                       
                                                                             
                         
    
#define IS_IRDA_PRESCALER(__PRESCALER__) ((__PRESCALER__) > 0U)

                                                  
                                        
                                                                      
    
#define IS_IRDA_PARITY(__PARITY__) (((__PARITY__) == IRDA_PARITY_NONE) || \
                                    ((__PARITY__) == IRDA_PARITY_EVEN) || \
                                    ((__PARITY__) == IRDA_PARITY_ODD))

                                                        
                                            
                                                                  
    
#define IS_IRDA_TX_RX_MODE(__MODE__) ((((__MODE__)\
                                        & (~((uint32_t)(IRDA_MODE_TX_RX)))) == 0x00U) && ((__MODE__) != 0x00U))

                                                
                                    
                                                                  
    
#define IS_IRDA_POWERMODE(__MODE__) (((__MODE__) == IRDA_POWERMODE_LOWPOWER) || \
                                     ((__MODE__) == IRDA_POWERMODE_NORMAL))

#if defined(USART_PRESC_PRESCALER)
                                                     
                                                         
                                                                                      
    
#define IS_IRDA_CLOCKPRESCALER(__CLOCKPRESCALER__) (((__CLOCKPRESCALER__) == IRDA_PRESCALER_DIV1) || \
                                                    ((__CLOCKPRESCALER__) == IRDA_PRESCALER_DIV2)   || \
                                                    ((__CLOCKPRESCALER__) == IRDA_PRESCALER_DIV4)   || \
                                                    ((__CLOCKPRESCALER__) == IRDA_PRESCALER_DIV6)   || \
                                                    ((__CLOCKPRESCALER__) == IRDA_PRESCALER_DIV8)   || \
                                                    ((__CLOCKPRESCALER__) == IRDA_PRESCALER_DIV10)  || \
                                                    ((__CLOCKPRESCALER__) == IRDA_PRESCALER_DIV12)  || \
                                                    ((__CLOCKPRESCALER__) == IRDA_PRESCALER_DIV16)  || \
                                                    ((__CLOCKPRESCALER__) == IRDA_PRESCALER_DIV32)  || \
                                                    ((__CLOCKPRESCALER__) == IRDA_PRESCALER_DIV64)  || \
                                                    ((__CLOCKPRESCALER__) == IRDA_PRESCALER_DIV128) || \
                                                    ((__CLOCKPRESCALER__) == IRDA_PRESCALER_DIV256))

#endif                            
                                           
                                     
                                                                    
    
#define IS_IRDA_STATE(__STATE__) (((__STATE__) == IRDA_STATE_DISABLE) || \
                                  ((__STATE__) == IRDA_STATE_ENABLE))

                                                                
                                                    
                                                                  
    
#define IS_IRDA_MODE(__MODE__)  (((__MODE__) == IRDA_MODE_DISABLE) || \
                                 ((__MODE__) == IRDA_MODE_ENABLE))

                                                   
                                         
                                                                      
    
#define IS_IRDA_ONE_BIT_SAMPLE(__ONEBIT__)      (((__ONEBIT__) == IRDA_ONE_BIT_SAMPLE_DISABLE) || \
                                                 ((__ONEBIT__) == IRDA_ONE_BIT_SAMPLE_ENABLE))

                                                 
                                      
                                                                    
    
#define IS_IRDA_DMA_TX(__DMATX__)     (((__DMATX__) == IRDA_DMA_TX_DISABLE) || \
                                       ((__DMATX__) == IRDA_DMA_TX_ENABLE))

                                                 
                                      
                                                                    
    
#define IS_IRDA_DMA_RX(__DMARX__) (((__DMARX__) == IRDA_DMA_RX_DISABLE) || \
                                   ((__DMARX__) == IRDA_DMA_RX_ENABLE))

                                             
                                  
                                                                    
    
#define IS_IRDA_REQUEST_PARAMETER(__PARAM__) (((__PARAM__) == IRDA_AUTOBAUD_REQUEST) || \
                                              ((__PARAM__) == IRDA_RXDATA_FLUSH_REQUEST) || \
                                              ((__PARAM__) == IRDA_TXDATA_FLUSH_REQUEST))
   
      
    

                                      
#include "stm32l4xx_hal_irda_ex.h"

                                                                                
                                                               
      
    

                                                                                             
      
    

                                                                                
HAL_StatusTypeDef HAL_IRDA_Init(IRDA_HandleTypeDef *hirda);
HAL_StatusTypeDef HAL_IRDA_DeInit(IRDA_HandleTypeDef *hirda);
void HAL_IRDA_MspInit(IRDA_HandleTypeDef *hirda);
void HAL_IRDA_MspDeInit(IRDA_HandleTypeDef *hirda);

#if (USE_HAL_IRDA_REGISTER_CALLBACKS == 1)
                                                                                
HAL_StatusTypeDef HAL_IRDA_RegisterCallback(IRDA_HandleTypeDef *hirda, HAL_IRDA_CallbackIDTypeDef CallbackID,
                                            pIRDA_CallbackTypeDef pCallback);
HAL_StatusTypeDef HAL_IRDA_UnRegisterCallback(IRDA_HandleTypeDef *hirda, HAL_IRDA_CallbackIDTypeDef CallbackID);
#endif                                      

   
      
    

                                                                     
      
    

                                                                                
HAL_StatusTypeDef HAL_IRDA_Transmit(IRDA_HandleTypeDef *hirda, const uint8_t *pData, uint16_t Size, uint32_t Timeout);
HAL_StatusTypeDef HAL_IRDA_Receive(IRDA_HandleTypeDef *hirda, uint8_t *pData, uint16_t Size, uint32_t Timeout);
HAL_StatusTypeDef HAL_IRDA_Transmit_IT(IRDA_HandleTypeDef *hirda, const uint8_t *pData, uint16_t Size);
HAL_StatusTypeDef HAL_IRDA_Receive_IT(IRDA_HandleTypeDef *hirda, uint8_t *pData, uint16_t Size);
HAL_StatusTypeDef HAL_IRDA_Transmit_DMA(IRDA_HandleTypeDef *hirda, const uint8_t *pData, uint16_t Size);
HAL_StatusTypeDef HAL_IRDA_Receive_DMA(IRDA_HandleTypeDef *hirda, uint8_t *pData, uint16_t Size);
HAL_StatusTypeDef HAL_IRDA_DMAPause(IRDA_HandleTypeDef *hirda);
HAL_StatusTypeDef HAL_IRDA_DMAResume(IRDA_HandleTypeDef *hirda);
HAL_StatusTypeDef HAL_IRDA_DMAStop(IRDA_HandleTypeDef *hirda);
                              
HAL_StatusTypeDef HAL_IRDA_Abort(IRDA_HandleTypeDef *hirda);
HAL_StatusTypeDef HAL_IRDA_AbortTransmit(IRDA_HandleTypeDef *hirda);
HAL_StatusTypeDef HAL_IRDA_AbortReceive(IRDA_HandleTypeDef *hirda);
HAL_StatusTypeDef HAL_IRDA_Abort_IT(IRDA_HandleTypeDef *hirda);
HAL_StatusTypeDef HAL_IRDA_AbortTransmit_IT(IRDA_HandleTypeDef *hirda);
HAL_StatusTypeDef HAL_IRDA_AbortReceive_IT(IRDA_HandleTypeDef *hirda);

void HAL_IRDA_IRQHandler(IRDA_HandleTypeDef *hirda);
void HAL_IRDA_TxCpltCallback(IRDA_HandleTypeDef *hirda);
void HAL_IRDA_RxCpltCallback(IRDA_HandleTypeDef *hirda);
void HAL_IRDA_TxHalfCpltCallback(IRDA_HandleTypeDef *hirda);
void HAL_IRDA_RxHalfCpltCallback(IRDA_HandleTypeDef *hirda);
void HAL_IRDA_ErrorCallback(IRDA_HandleTypeDef *hirda);
void HAL_IRDA_AbortCpltCallback(IRDA_HandleTypeDef *hirda);
void HAL_IRDA_AbortTransmitCpltCallback(IRDA_HandleTypeDef *hirda);
void HAL_IRDA_AbortReceiveCpltCallback(IRDA_HandleTypeDef *hirda);

   
      
    

                                                                                  

                                                                                   
      
    

                                                                                
HAL_IRDA_StateTypeDef HAL_IRDA_GetState(const IRDA_HandleTypeDef *hirda);
uint32_t              HAL_IRDA_GetError(const IRDA_HandleTypeDef *hirda);

   
      
    

   
      
    

   
      
    

   
      
    

#ifdef __cplusplus
}
#endif

#endif                           

