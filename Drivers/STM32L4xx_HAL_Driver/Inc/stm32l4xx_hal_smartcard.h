/**
  ******************************************************************************
  * @file    stm32l4xx_hal_smartcard.h
  * @author  MCD Application Team
  * @brief   Header file of SMARTCARD HAL module.
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

                                                                                
#ifndef STM32L4xx_HAL_SMARTCARD_H
#define STM32L4xx_HAL_SMARTCARD_H

#ifdef __cplusplus
extern "C" {
#endif

                                                                                
#include "stm32l4xx_hal_def.h"

                                    
      
    

                         
      
    

                                                                                
                                                               
      
    

   
                                              
    
typedef struct
{
  uint32_t BaudRate;                                                                        
                                                                                                          
                                                                                                                       
                                                                                                                    

  uint32_t WordLength;                                                                                          
                                                                                                
                                                                                

  uint32_t StopBits;                                                         
                                                                                                        

  uint16_t Parity;                                                   
                                                                                                 
                                                                                                       
                                                                                                        
                                                                                                  

  uint16_t Mode;                                                                                                 
                                                                                                  

  uint16_t CLKPolarity;                                                                   
                                                                                                            

  uint16_t CLKPhase;                                                                                       
                                                                                                         

  uint16_t CLKLastBit;                                                                                            
                                                                                                               
                                                                                                      

  uint16_t OneBitSampling;                                                                                  
                                                                                                    
                                                                                                                    
                                                                                

  uint8_t  Prescaler;                                                        
                                                                                                                
                                                                                                                       

  uint8_t  GuardTime;                                                                                    

  uint16_t NACKEnable;                                                                                 
                                                                   
                                                                                                         

  uint32_t TimeOutEnable;                                                                    
                                                                                                            

  uint32_t TimeOutValue;                                                                                  
                                                                                                    
                                                                                              

  uint8_t BlockLength;                                                                                
                                                                                              

  uint8_t AutoRetryCount;                                                                                
                                                                                                        
                                                                                                          
                                                        

#if defined(USART_PRESC_PRESCALER)
  uint32_t ClockPrescaler;                                                                                     
                                                                                                             

#endif                            
} SMARTCARD_InitTypeDef;

   
                                                                           
    
typedef struct
{
  uint32_t AdvFeatureInit;                                                                                    
                                                                                                                
                                                                                                                      

  uint32_t TxPinLevelInvert;                                                                     
                                                                                                     

  uint32_t RxPinLevelInvert;                                                                     
                                                                                                     

  uint32_t DataInvert;                                                                               
                                                                       
                                                                                                      

  uint32_t Swap;                                                                        
                                                                                                        

  uint32_t OverrunDisable;                                                                               
                                                                                                             

  uint32_t DMADisableonRxError;                                                                             
                                                                                                                     

  uint32_t MSBFirst;                                                                        
                                                                                                       

  uint16_t TxCompletionIndication;                                                                                 
                                                                                                             
                                                                        
                                                                                                     
} SMARTCARD_AdvFeatureInitTypeDef;

   
                                         
                                                                               
                                                                    
                                                                                            
                                                           
                                                                
                                     
                             
                               
                            
                          
                                                    
                                                       
                                                                                                   
                              
                                        
                                           
                          
                                                                                          
                              
                                       
                            
                                                    
                                                
                                                                   
                                                                 
                              
                                        
                                                    
                                                       
                                                       
                              
                                         
                            
                                                    
                                                
                              
                                        
    
typedef uint32_t HAL_SMARTCARD_StateTypeDef;

   
                                                 
    
typedef struct __SMARTCARD_HandleTypeDef
{
  USART_TypeDef                     *Instance;                                                                          

  SMARTCARD_InitTypeDef             Init;                                                                               

  SMARTCARD_AdvFeatureInitTypeDef   AdvancedInit;                                                                       

  const uint8_t                     *pTxBuffPtr;                                                                        

  uint16_t                          TxXferSize;                                                                         

  __IO uint16_t                     TxXferCount;                                                                        

  uint8_t                           *pRxBuffPtr;                                                                        

  uint16_t                          RxXferSize;                                                                         

  __IO uint16_t                     RxXferCount;                                                                        

#if defined(USART_CR1_FIFOEN)
  uint16_t                          NbRxDataToProcess;                                                                  

  uint16_t                          NbTxDataToProcess;                                                                  

  uint32_t                          FifoMode;                                                           
                                                                                                
                                                                                                                        
#endif                       

  void (*RxISR)(struct __SMARTCARD_HandleTypeDef *huart);                                                               

  void (*TxISR)(struct __SMARTCARD_HandleTypeDef *huart);                                                               

  DMA_HandleTypeDef                 *hdmatx;                                                                            

  DMA_HandleTypeDef                 *hdmarx;                                                                            

  HAL_LockTypeDef                   Lock;                                                                               

  __IO HAL_SMARTCARD_StateTypeDef   gState;                                                                  
                                                                                                                    
                                                                                             
                                                                                                                        

  __IO HAL_SMARTCARD_StateTypeDef   RxState;                                                                         
                                                                                             
                                                                                                                        

  __IO uint32_t                     ErrorCode;                                                                          

#if (USE_HAL_SMARTCARD_REGISTER_CALLBACKS == 1)
  void (* TxCpltCallback)(struct __SMARTCARD_HandleTypeDef *hsmartcard);                                                              

  void (* RxCpltCallback)(struct __SMARTCARD_HandleTypeDef *hsmartcard);                                                              

  void (* ErrorCallback)(struct __SMARTCARD_HandleTypeDef *hsmartcard);                                                               

  void (* AbortCpltCallback)(struct __SMARTCARD_HandleTypeDef *hsmartcard);                                                           

  void (* AbortTransmitCpltCallback)(struct __SMARTCARD_HandleTypeDef *hsmartcard);                                                   

  void (* AbortReceiveCpltCallback)(struct __SMARTCARD_HandleTypeDef *hsmartcard);                                                    

#if defined(USART_CR1_FIFOEN)
  void (* RxFifoFullCallback)(struct __SMARTCARD_HandleTypeDef *hsmartcard);                                                          

  void (* TxFifoEmptyCallback)(struct __SMARTCARD_HandleTypeDef *hsmartcard);                                                         

#endif                       
  void (* MspInitCallback)(struct __SMARTCARD_HandleTypeDef *hsmartcard);                                                             

  void (* MspDeInitCallback)(struct __SMARTCARD_HandleTypeDef *hsmartcard);                                                           
#endif                                            

} SMARTCARD_HandleTypeDef;

#if (USE_HAL_SMARTCARD_REGISTER_CALLBACKS == 1)
   
                                                            
    
typedef enum
{
  HAL_SMARTCARD_TX_COMPLETE_CB_ID             = 0x00U,                                                         
  HAL_SMARTCARD_RX_COMPLETE_CB_ID             = 0x01U,                                                         
  HAL_SMARTCARD_ERROR_CB_ID                   = 0x02U,                                                         
  HAL_SMARTCARD_ABORT_COMPLETE_CB_ID          = 0x03U,                                                         
  HAL_SMARTCARD_ABORT_TRANSMIT_COMPLETE_CB_ID = 0x04U,                                                         
  HAL_SMARTCARD_ABORT_RECEIVE_COMPLETE_CB_ID  = 0x05U,                                                         
#if defined(USART_CR1_FIFOEN)
  HAL_SMARTCARD_RX_FIFO_FULL_CB_ID            = 0x06U,                                                         
  HAL_SMARTCARD_TX_FIFO_EMPTY_CB_ID           = 0x07U,                                                         
#endif                       

  HAL_SMARTCARD_MSPINIT_CB_ID                 = 0x08U,                                                         
  HAL_SMARTCARD_MSPDEINIT_CB_ID               = 0x09U                                                          

} HAL_SMARTCARD_CallbackIDTypeDef;

   
                                                     
    
typedef  void (*pSMARTCARD_CallbackTypeDef)(SMARTCARD_HandleTypeDef *hsmartcard);                                                   

#endif                                           

   
                                   
    
typedef enum
{
  SMARTCARD_CLOCKSOURCE_PCLK1     = 0x00U,                                   
  SMARTCARD_CLOCKSOURCE_PCLK2     = 0x01U,                                   
  SMARTCARD_CLOCKSOURCE_HSI       = 0x02U,                                   
  SMARTCARD_CLOCKSOURCE_SYSCLK    = 0x04U,                                   
  SMARTCARD_CLOCKSOURCE_LSE       = 0x08U,                                   
  SMARTCARD_CLOCKSOURCE_UNDEFINED = 0x10U                                    
} SMARTCARD_ClockSourceTypeDef;

   
      
    

                                                                                
                                                                        
      
    

                                                                        
      
    
#define HAL_SMARTCARD_STATE_RESET            0x00000000U                                                              
                                                                                                                      
#define HAL_SMARTCARD_STATE_READY            0x00000020U                                                              
                                                                                                                  
                                                                                                                      
#define HAL_SMARTCARD_STATE_BUSY             0x00000024U                                                        
                                                                                                                      
#define HAL_SMARTCARD_STATE_BUSY_TX          0x00000021U                                                              
                                                                                                                      
#define HAL_SMARTCARD_STATE_BUSY_RX          0x00000022U                                                           
                                                                                                                      
#define HAL_SMARTCARD_STATE_BUSY_TX_RX       0x00000023U                                                         
                                                                                                                       
                                                                                                             
                                                                                                                     
                                                                                                                      
#define HAL_SMARTCARD_STATE_TIMEOUT          0x000000A0U                                       
                                                                                                                      
#define HAL_SMARTCARD_STATE_ERROR            0x000000E0U                               
                                                                                                                      
   
      
    

                                                                        
      
    
#define HAL_SMARTCARD_ERROR_NONE             (0x00000000U)                                        
#define HAL_SMARTCARD_ERROR_PE               (0x00000001U)                                        
#define HAL_SMARTCARD_ERROR_NE               (0x00000002U)                                        
#define HAL_SMARTCARD_ERROR_FE               (0x00000004U)                                        
#define HAL_SMARTCARD_ERROR_ORE              (0x00000008U)                                        
#define HAL_SMARTCARD_ERROR_DMA              (0x00000010U)                                        
#define HAL_SMARTCARD_ERROR_RTO              (0x00000020U)                                        
#if (USE_HAL_SMARTCARD_REGISTER_CALLBACKS == 1)
#define HAL_SMARTCARD_ERROR_INVALID_CALLBACK (0x00000040U)                                        
#endif                                           
   
      
    

                                                         
      
    
#define SMARTCARD_WORDLENGTH_9B             USART_CR1_M0                                                  
   
      
    

                                                               
      
    
#define SMARTCARD_STOPBITS_0_5              USART_CR2_STOP_0                                                          
#define SMARTCARD_STOPBITS_1_5              USART_CR2_STOP                                                            
   
      
    

                                               
      
    
#define SMARTCARD_PARITY_EVEN               USART_CR1_PCE                                                      
#define SMARTCARD_PARITY_ODD                (USART_CR1_PCE | USART_CR1_PS)                                     
   
      
    

                                                    
      
    
#define SMARTCARD_MODE_RX                   USART_CR1_RE                                                    
#define SMARTCARD_MODE_TX                   USART_CR1_TE                                                    
#define SMARTCARD_MODE_TX_RX                (USART_CR1_TE |USART_CR1_RE)                                    
   
      
    

                                                               
      
    
#define SMARTCARD_POLARITY_LOW              0x00000000U                                                          
#define SMARTCARD_POLARITY_HIGH             USART_CR2_CPOL                                                       
   
      
    

                                                         
      
    
#define SMARTCARD_PHASE_1EDGE               0x00000000U                                                                             
#define SMARTCARD_PHASE_2EDGE               USART_CR2_CPHA                                                                          
   
      
    

                                                   
      
    
#define SMARTCARD_LASTBIT_DISABLE           0x00000000U                                                                                             
#define SMARTCARD_LASTBIT_ENABLE            USART_CR2_LBCL                                                                                          
   
      
    

                                                                         
      
    
#define SMARTCARD_ONE_BIT_SAMPLE_DISABLE    0x00000000U                                                                    
#define SMARTCARD_ONE_BIT_SAMPLE_ENABLE     USART_CR3_ONEBIT                                                               
   
      
    

                                                         
      
    
#define SMARTCARD_NACK_DISABLE              0x00000000U                                                                  
#define SMARTCARD_NACK_ENABLE               USART_CR3_NACK                                                             
   
      
    

                                                               
      
    
#define SMARTCARD_TIMEOUT_DISABLE           0x00000000U                                                                
#define SMARTCARD_TIMEOUT_ENABLE            USART_CR2_RTOEN                                                            
   
      
    

#if defined(USART_PRESC_PRESCALER)
                                                                 
      
    
#define SMARTCARD_PRESCALER_DIV1    0x00000000U                              
#define SMARTCARD_PRESCALER_DIV2    0x00000001U                              
#define SMARTCARD_PRESCALER_DIV4    0x00000002U                              
#define SMARTCARD_PRESCALER_DIV6    0x00000003U                              
#define SMARTCARD_PRESCALER_DIV8    0x00000004U                              
#define SMARTCARD_PRESCALER_DIV10   0x00000005U                              
#define SMARTCARD_PRESCALER_DIV12   0x00000006U                              
#define SMARTCARD_PRESCALER_DIV16   0x00000007U                              
#define SMARTCARD_PRESCALER_DIV32   0x00000008U                              
#define SMARTCARD_PRESCALER_DIV64   0x00000009U                              
#define SMARTCARD_PRESCALER_DIV128  0x0000000AU                              
#define SMARTCARD_PRESCALER_DIV256  0x0000000BU                              
   
      
    

#endif                            
                                                                                       
      
    
#define SMARTCARD_ADVFEATURE_TXINV_DISABLE  0x00000000U                                                               
#define SMARTCARD_ADVFEATURE_TXINV_ENABLE   USART_CR2_TXINV                                                           
   
      
    

                                                                                       
      
    
#define SMARTCARD_ADVFEATURE_RXINV_DISABLE  0x00000000U                                                               
#define SMARTCARD_ADVFEATURE_RXINV_ENABLE   USART_CR2_RXINV                                                           
   
      
    

                                                                                 
      
    
#define SMARTCARD_ADVFEATURE_DATAINV_DISABLE  0x00000000U                                                     
#define SMARTCARD_ADVFEATURE_DATAINV_ENABLE   USART_CR2_DATAINV                                               
   
      
    

                                                                             
      
    
#define SMARTCARD_ADVFEATURE_SWAP_DISABLE   0x00000000U                                                 
#define SMARTCARD_ADVFEATURE_SWAP_ENABLE    USART_CR2_SWAP                                              
   
      
    

                                                                                  
      
    
#define SMARTCARD_ADVFEATURE_OVERRUN_ENABLE   0x00000000U                                          
#define SMARTCARD_ADVFEATURE_OVERRUN_DISABLE  USART_CR3_OVRDIS                                     
   
      
    

                                                                                                  
      
    
#define SMARTCARD_ADVFEATURE_DMA_ENABLEONRXERROR   0x00000000U                                                 
#define SMARTCARD_ADVFEATURE_DMA_DISABLEONRXERROR  USART_CR3_DDRE                                              
   
      
    

                                                                        
      
    
#define SMARTCARD_ADVFEATURE_MSBFIRST_DISABLE      0x00000000U                                                                   
#define SMARTCARD_ADVFEATURE_MSBFIRST_ENABLE       USART_CR2_MSBFIRST                                                            
   
      
    

                                                                       
      
    
#define SMARTCARD_RXDATA_FLUSH_REQUEST      USART_RQR_RXFRQ                                                
#define SMARTCARD_TXDATA_FLUSH_REQUEST      USART_RQR_TXFRQ                                                 
   
      
    

                                                                            
      
    
#define SMARTCARD_IT_MASK                   0x001FU                                              
#define SMARTCARD_CR_MASK                   0x00E0U                                              
#define SMARTCARD_CR_POS                    5U                                                   
#define SMARTCARD_ISR_MASK                  0x1F00U                                              
#define SMARTCARD_ISR_POS                   8U                                                   
   
      
    

   
      
    

                                                                                
                                                                  
      
    

                                          
                                        
                
    
#if USE_HAL_SMARTCARD_REGISTER_CALLBACKS == 1
#define __HAL_SMARTCARD_RESET_HANDLE_STATE(__HANDLE__)  do{                                                       \
                                                            (__HANDLE__)->gState = HAL_SMARTCARD_STATE_RESET;     \
                                                            (__HANDLE__)->RxState = HAL_SMARTCARD_STATE_RESET;    \
                                                            (__HANDLE__)->MspInitCallback = NULL;                 \
                                                            (__HANDLE__)->MspDeInitCallback = NULL;               \
                                                          } while(0U)
#else
#define __HAL_SMARTCARD_RESET_HANDLE_STATE(__HANDLE__)  do{                                                       \
                                                            (__HANDLE__)->gState = HAL_SMARTCARD_STATE_RESET;     \
                                                            (__HANDLE__)->RxState = HAL_SMARTCARD_STATE_RESET;    \
                                                          } while(0U)
#endif                                           

                                               
                                                      
                
    
#define __HAL_SMARTCARD_FLUSH_DRREGISTER(__HANDLE__)                      \
  do{                                                                     \
    SET_BIT((__HANDLE__)->Instance->RQR, SMARTCARD_RXDATA_FLUSH_REQUEST); \
    SET_BIT((__HANDLE__)->Instance->RQR, SMARTCARD_TXDATA_FLUSH_REQUEST); \
  } while(0U)

                                                       
                                                      
                                                 
                                                                           
                                                                       
                                                                        
                                                                         
                                                                        
                                                                             
                                                                                
                                                                                                  
                                                                           
                                                                       
                             
                                                                       
      
                
    
#define __HAL_SMARTCARD_CLEAR_FLAG(__HANDLE__, __FLAG__) ((__HANDLE__)->Instance->ICR = (__FLAG__))

                                                
                                                      
                
    
#define __HAL_SMARTCARD_CLEAR_PEFLAG(__HANDLE__)   __HAL_SMARTCARD_CLEAR_FLAG((__HANDLE__), SMARTCARD_CLEAR_PEF)

                                                
                                                      
                
    
#define __HAL_SMARTCARD_CLEAR_FEFLAG(__HANDLE__)   __HAL_SMARTCARD_CLEAR_FLAG((__HANDLE__), SMARTCARD_CLEAR_FEF)

                                                
                                                      
                
    
#define __HAL_SMARTCARD_CLEAR_NEFLAG(__HANDLE__)   __HAL_SMARTCARD_CLEAR_FLAG((__HANDLE__), SMARTCARD_CLEAR_NEF)

                                                 
                                                      
                
    
#define __HAL_SMARTCARD_CLEAR_OREFLAG(__HANDLE__)   __HAL_SMARTCARD_CLEAR_FLAG((__HANDLE__), SMARTCARD_CLEAR_OREF)

                                                  
                                                      
                
    
#define __HAL_SMARTCARD_CLEAR_IDLEFLAG(__HANDLE__)   __HAL_SMARTCARD_CLEAR_FLAG((__HANDLE__), SMARTCARD_CLEAR_IDLEF)

                                                                     
                                                      
                                                 
                                                             
                                                                                                                
                                                                             
                                                                              
                                                       
                                                               
                                                                   
                                                                               
                                                                        
                                                                                  
                                                                      
                                                                
                                                              
                                                                
                                                               
                                                                  
                                                                   
                                                               
                                                              
                                                                             
                                                                             
                                                      
    
#define __HAL_SMARTCARD_GET_FLAG(__HANDLE__, __FLAG__) (((__HANDLE__)->Instance->ISR & (__FLAG__)) == (__FLAG__))

                                                     
                                                      
                                                                      
                                                               
                                                                   
                                                                      
                                                                                   
                                                                            
                                                                         
                                                                                               
                                                                                      
                                                                          
                                                                   
                                                                                                     
                                                                          
                                                                          
                                                                     
                                                                      
                                                                                  
                                                                                  
                
    
#define __HAL_SMARTCARD_ENABLE_IT(__HANDLE__, __INTERRUPT__)   (((((__INTERRUPT__) & SMARTCARD_CR_MASK) >>\
                                                                  SMARTCARD_CR_POS) == 1U)?\
                                                                ((__HANDLE__)->Instance->CR1 |= (1UL <<\
                                                                    ((__INTERRUPT__) & SMARTCARD_IT_MASK))):\
                                                                ((((__INTERRUPT__) & SMARTCARD_CR_MASK) >>\
                                                                  SMARTCARD_CR_POS) == 2U)?\
                                                                ((__HANDLE__)->Instance->CR2 |= (1UL <<\
                                                                    ((__INTERRUPT__) & SMARTCARD_IT_MASK))): \
                                                                ((__HANDLE__)->Instance->CR3 |= (1UL <<\
                                                                    ((__INTERRUPT__) & SMARTCARD_IT_MASK))))

                                                      
                                                      
                                                                       
                                                               
                                                                   
                                                                      
                                                                                   
                                                                            
                                                                               
                                                                                         
                                                                                      
                                                                          
                                                                   
                                                                                                     
                                                                          
                                                                          
                                                                     
                                                                      
                                                                                  
                                                                                  
                
    
#define __HAL_SMARTCARD_DISABLE_IT(__HANDLE__, __INTERRUPT__)  (((((__INTERRUPT__) & SMARTCARD_CR_MASK) >>\
                                                                  SMARTCARD_CR_POS) == 1U)?\
                                                                ((__HANDLE__)->Instance->CR1 &= ~ (1UL <<\
                                                                    ((__INTERRUPT__) & SMARTCARD_IT_MASK))): \
                                                                ((((__INTERRUPT__) & SMARTCARD_CR_MASK) >>\
                                                                  SMARTCARD_CR_POS) == 2U)?\
                                                                ((__HANDLE__)->Instance->CR2 &= ~ (1UL <<\
                                                                    ((__INTERRUPT__) & SMARTCARD_IT_MASK))): \
                                                                ((__HANDLE__)->Instance->CR3 &= ~ (1UL <<\
                                                                    ((__INTERRUPT__) & SMARTCARD_IT_MASK))))

                                                                                
                                                      
                                                                     
                                                               
                                                                   
                                                                      
                                                                                   
                                                                            
                                                                                    
                                                                                    
                                                                                      
                                                                          
                                                                   
                                                                                                     
                                                                          
                                                                          
                                                                     
                                                                      
                                                                                  
                                                                                  
                                                          
    
#define __HAL_SMARTCARD_GET_IT(__HANDLE__, __INTERRUPT__) (\
                                                           (((__HANDLE__)->Instance->ISR & (0x01UL << (((__INTERRUPT__)\
                                                               & SMARTCARD_ISR_MASK)>> SMARTCARD_ISR_POS)))!= 0U)\
                                                           ? SET : RESET)

                                                                                     
                                                      
                                                                            
                                                               
                                                                   
                                                                      
                                                                                   
                                                                            
                                                                                    
                                                                                    
                                                                                      
                                                                          
                                                                   
                                                                                                     
                                                                          
                                                                          
                                                                     
                                                                      
                                                                                  
                                                                                  
                                                          
    
#define __HAL_SMARTCARD_GET_IT_SOURCE(__HANDLE__, __INTERRUPT__) ((((((((__INTERRUPT__) & SMARTCARD_CR_MASK) >>\
                                                                       SMARTCARD_CR_POS) == 0x01U)?\
                                                                     (__HANDLE__)->Instance->CR1 : \
                                                                     (((((__INTERRUPT__) & SMARTCARD_CR_MASK) >>\
                                                                        SMARTCARD_CR_POS) == 0x02U)?\
                                                                      (__HANDLE__)->Instance->CR2 : \
                                                                      (__HANDLE__)->Instance->CR3)) &\
                                                                    (0x01UL << (((uint16_t)(__INTERRUPT__))\
                                                                                & SMARTCARD_IT_MASK)))  != 0U)\
                                                                  ? SET : RESET)

                                                                                            
                                                      
                                                                                         
                                                               
                                                               
                                                                       
                                                                        
                                                                         
                                                                        
                                                                              
                                                                       
                                                                                
                                                                                                                        
                                                                           
                                                                       
                
    
#define __HAL_SMARTCARD_CLEAR_IT(__HANDLE__, __IT_CLEAR__) ((__HANDLE__)->Instance->ICR |= (uint32_t)(__IT_CLEAR__))

                                                  
                                                      
                                                     
                                                               
                                                                                  
                                                                                   
                
    
#define __HAL_SMARTCARD_SEND_REQ(__HANDLE__, __REQ__) ((__HANDLE__)->Instance->RQR |= (uint16_t)(__REQ__))

                                                       
                                                      
                
    
#define __HAL_SMARTCARD_ONE_BIT_SAMPLE_ENABLE(__HANDLE__) ((__HANDLE__)->Instance->CR3|= USART_CR3_ONEBIT)

                                                        
                                                      
                
    
#define __HAL_SMARTCARD_ONE_BIT_SAMPLE_DISABLE(__HANDLE__) ((__HANDLE__)->Instance->CR3\
                                                            &= (uint32_t)~((uint32_t)USART_CR3_ONEBIT))

                                                                
                                                      
                
    
#define __HAL_SMARTCARD_ENABLE(__HANDLE__)               ((__HANDLE__)->Instance->CR1 |=  USART_CR1_UE)

                                                                
                                                      
                
    
#define __HAL_SMARTCARD_DISABLE(__HANDLE__)              ((__HANDLE__)->Instance->CR1 &=  ~USART_CR1_UE)

   
      
    

                                                                                 
                                                               
      
    

                                              
                                                      
                                            
                                                                      
    
#if defined (STM32L432xx) || defined (STM32L442xx)
#define SMARTCARD_GETCLOCKSOURCE(__HANDLE__,__CLOCKSOURCE__)   \
  do {                                                         \
    if((__HANDLE__)->Instance == USART1)                       \
    {                                                          \
      switch(__HAL_RCC_GET_USART1_SOURCE())                    \
      {                                                        \
        case RCC_USART1CLKSOURCE_PCLK2:                        \
          (__CLOCKSOURCE__) = SMARTCARD_CLOCKSOURCE_PCLK2;     \
          break;                                               \
        case RCC_USART1CLKSOURCE_HSI:                          \
          (__CLOCKSOURCE__) = SMARTCARD_CLOCKSOURCE_HSI;       \
          break;                                               \
        case RCC_USART1CLKSOURCE_SYSCLK:                       \
          (__CLOCKSOURCE__) = SMARTCARD_CLOCKSOURCE_SYSCLK;    \
          break;                                               \
        case RCC_USART1CLKSOURCE_LSE:                          \
          (__CLOCKSOURCE__) = SMARTCARD_CLOCKSOURCE_LSE;       \
          break;                                               \
        default:                                               \
          (__CLOCKSOURCE__) = SMARTCARD_CLOCKSOURCE_UNDEFINED; \
          break;                                               \
      }                                                        \
    }                                                          \
    else if((__HANDLE__)->Instance == USART2)                  \
    {                                                          \
      switch(__HAL_RCC_GET_USART2_SOURCE())                    \
      {                                                        \
        case RCC_USART2CLKSOURCE_PCLK1:                        \
          (__CLOCKSOURCE__) = SMARTCARD_CLOCKSOURCE_PCLK1;     \
          break;                                               \
        case RCC_USART2CLKSOURCE_HSI:                          \
          (__CLOCKSOURCE__) = SMARTCARD_CLOCKSOURCE_HSI;       \
          break;                                               \
        case RCC_USART2CLKSOURCE_SYSCLK:                       \
          (__CLOCKSOURCE__) = SMARTCARD_CLOCKSOURCE_SYSCLK;    \
          break;                                               \
        case RCC_USART2CLKSOURCE_LSE:                          \
          (__CLOCKSOURCE__) = SMARTCARD_CLOCKSOURCE_LSE;       \
          break;                                               \
        default:                                               \
          (__CLOCKSOURCE__) = SMARTCARD_CLOCKSOURCE_UNDEFINED; \
          break;                                               \
      }                                                        \
    }                                                          \
    else                                                       \
    {                                                          \
      (__CLOCKSOURCE__) = SMARTCARD_CLOCKSOURCE_UNDEFINED;     \
    }                                                          \
  } while(0)
#else
#define SMARTCARD_GETCLOCKSOURCE(__HANDLE__,__CLOCKSOURCE__)   \
  do {                                                         \
    if((__HANDLE__)->Instance == USART1)                       \
    {                                                          \
      switch(__HAL_RCC_GET_USART1_SOURCE())                    \
      {                                                        \
        case RCC_USART1CLKSOURCE_PCLK2:                        \
          (__CLOCKSOURCE__) = SMARTCARD_CLOCKSOURCE_PCLK2;     \
          break;                                               \
        case RCC_USART1CLKSOURCE_HSI:                          \
          (__CLOCKSOURCE__) = SMARTCARD_CLOCKSOURCE_HSI;       \
          break;                                               \
        case RCC_USART1CLKSOURCE_SYSCLK:                       \
          (__CLOCKSOURCE__) = SMARTCARD_CLOCKSOURCE_SYSCLK;    \
          break;                                               \
        case RCC_USART1CLKSOURCE_LSE:                          \
          (__CLOCKSOURCE__) = SMARTCARD_CLOCKSOURCE_LSE;       \
          break;                                               \
        default:                                               \
          (__CLOCKSOURCE__) = SMARTCARD_CLOCKSOURCE_UNDEFINED; \
          break;                                               \
      }                                                        \
    }                                                          \
    else if((__HANDLE__)->Instance == USART2)                  \
    {                                                          \
      switch(__HAL_RCC_GET_USART2_SOURCE())                    \
      {                                                        \
        case RCC_USART2CLKSOURCE_PCLK1:                        \
          (__CLOCKSOURCE__) = SMARTCARD_CLOCKSOURCE_PCLK1;     \
          break;                                               \
        case RCC_USART2CLKSOURCE_HSI:                          \
          (__CLOCKSOURCE__) = SMARTCARD_CLOCKSOURCE_HSI;       \
          break;                                               \
        case RCC_USART2CLKSOURCE_SYSCLK:                       \
          (__CLOCKSOURCE__) = SMARTCARD_CLOCKSOURCE_SYSCLK;    \
          break;                                               \
        case RCC_USART2CLKSOURCE_LSE:                          \
          (__CLOCKSOURCE__) = SMARTCARD_CLOCKSOURCE_LSE;       \
          break;                                               \
        default:                                               \
          (__CLOCKSOURCE__) = SMARTCARD_CLOCKSOURCE_UNDEFINED; \
          break;                                               \
      }                                                        \
    }                                                          \
    else if((__HANDLE__)->Instance == USART3)                  \
    {                                                          \
      switch(__HAL_RCC_GET_USART3_SOURCE())                    \
      {                                                        \
        case RCC_USART3CLKSOURCE_PCLK1:                        \
          (__CLOCKSOURCE__) = SMARTCARD_CLOCKSOURCE_PCLK1;     \
          break;                                               \
        case RCC_USART3CLKSOURCE_HSI:                          \
          (__CLOCKSOURCE__) = SMARTCARD_CLOCKSOURCE_HSI;       \
          break;                                               \
        case RCC_USART3CLKSOURCE_SYSCLK:                       \
          (__CLOCKSOURCE__) = SMARTCARD_CLOCKSOURCE_SYSCLK;    \
          break;                                               \
        case RCC_USART3CLKSOURCE_LSE:                          \
          (__CLOCKSOURCE__) = SMARTCARD_CLOCKSOURCE_LSE;       \
          break;                                               \
        default:                                               \
          (__CLOCKSOURCE__) = SMARTCARD_CLOCKSOURCE_UNDEFINED; \
          break;                                               \
      }                                                        \
    }                                                          \
    else                                                       \
    {                                                          \
      (__CLOCKSOURCE__) = SMARTCARD_CLOCKSOURCE_UNDEFINED;     \
    }                                                          \
  } while(0)
#endif                                 

                                      
                                                                                   
                                                                        
                                                                     
                                       
    
#define IS_SMARTCARD_BAUDRATE(__BAUDRATE__) ((__BAUDRATE__) < 7500001U)

                                         
                                                       
                                    
                                       
    
#define IS_SMARTCARD_BLOCKLENGTH(__LENGTH__) ((__LENGTH__) <= 0xFFU)

                                             
                                                                     
                                                    
                                       
    
#define IS_SMARTCARD_TIMEOUT_VALUE(__TIMEOUTVALUE__)    ((__TIMEOUTVALUE__) <= 0xFFFFFFU)

                                                        
                                                         
                                                
                                       
    
#define IS_SMARTCARD_AUTORETRY_COUNT(__COUNT__)         ((__COUNT__) <= 0x7U)

                                                       
                                             
                                                                      
    
#define IS_SMARTCARD_WORD_LENGTH(__LENGTH__) ((__LENGTH__) == SMARTCARD_WORDLENGTH_9B)

                                                                    
                                                            
                                                                          
    
#define IS_SMARTCARD_STOPBITS(__STOPBITS__) (((__STOPBITS__) == SMARTCARD_STOPBITS_0_5) ||\
                                             ((__STOPBITS__) == SMARTCARD_STOPBITS_1_5))

                                                       
                                             
                                                                      
    
#define IS_SMARTCARD_PARITY(__PARITY__) (((__PARITY__) == SMARTCARD_PARITY_EVEN) || \
                                         ((__PARITY__) == SMARTCARD_PARITY_ODD))

                                                             
                                                 
                                                                  
    
#define IS_SMARTCARD_MODE(__MODE__) ((((__MODE__) & 0xFFF3U) == 0x00U) && ((__MODE__) != 0x00U))

                                                         
                                             
                                                                  
    
#define IS_SMARTCARD_POLARITY(__CPOL__) (((__CPOL__) == SMARTCARD_POLARITY_LOW)\
                                         || ((__CPOL__) == SMARTCARD_POLARITY_HIGH))

                                                      
                                          
                                                                  
    
#define IS_SMARTCARD_PHASE(__CPHA__) (((__CPHA__) == SMARTCARD_PHASE_1EDGE) || ((__CPHA__) == SMARTCARD_PHASE_2EDGE))

                                                                             
                                                                    
                                                                        
    
#define IS_SMARTCARD_LASTBIT(__LASTBIT__) (((__LASTBIT__) == SMARTCARD_LASTBIT_DISABLE) || \
                                           ((__LASTBIT__) == SMARTCARD_LASTBIT_ENABLE))

                                                         
                                               
                                                                      
    
#define IS_SMARTCARD_ONE_BIT_SAMPLE(__ONEBIT__) (((__ONEBIT__) == SMARTCARD_ONE_BIT_SAMPLE_DISABLE) || \
                                                 ((__ONEBIT__) == SMARTCARD_ONE_BIT_SAMPLE_ENABLE))

                                                                    
                                                        
                                                                  
    
#define IS_SMARTCARD_NACK(__NACK__) (((__NACK__) == SMARTCARD_NACK_ENABLE) || \
                                     ((__NACK__) == SMARTCARD_NACK_DISABLE))

                                                                   
                                                          
                                                                        
    
#define IS_SMARTCARD_TIMEOUT(__TIMEOUT__) (((__TIMEOUT__) == SMARTCARD_TIMEOUT_DISABLE) || \
                                           ((__TIMEOUT__) == SMARTCARD_TIMEOUT_ENABLE))

#if defined(USART_PRESC_PRESCALER)
                                                          
                                                              
                                                                                      
    
#define IS_SMARTCARD_CLOCKPRESCALER(__CLOCKPRESCALER__) (((__CLOCKPRESCALER__) == SMARTCARD_PRESCALER_DIV1)   || \
                                                         ((__CLOCKPRESCALER__) == SMARTCARD_PRESCALER_DIV2)   || \
                                                         ((__CLOCKPRESCALER__) == SMARTCARD_PRESCALER_DIV4)   || \
                                                         ((__CLOCKPRESCALER__) == SMARTCARD_PRESCALER_DIV6)   || \
                                                         ((__CLOCKPRESCALER__) == SMARTCARD_PRESCALER_DIV8)   || \
                                                         ((__CLOCKPRESCALER__) == SMARTCARD_PRESCALER_DIV10)  || \
                                                         ((__CLOCKPRESCALER__) == SMARTCARD_PRESCALER_DIV12)  || \
                                                         ((__CLOCKPRESCALER__) == SMARTCARD_PRESCALER_DIV16)  || \
                                                         ((__CLOCKPRESCALER__) == SMARTCARD_PRESCALER_DIV32)  || \
                                                         ((__CLOCKPRESCALER__) == SMARTCARD_PRESCALER_DIV64)  || \
                                                         ((__CLOCKPRESCALER__) == SMARTCARD_PRESCALER_DIV128) || \
                                                         ((__CLOCKPRESCALER__) == SMARTCARD_PRESCALER_DIV256))

#endif                            
                                                                           
                                                               
                                                                  
    
#define IS_SMARTCARD_ADVFEATURE_INIT(__INIT__) ((__INIT__) <= (SMARTCARD_ADVFEATURE_NO_INIT                | \
                                                               SMARTCARD_ADVFEATURE_TXINVERT_INIT          | \
                                                               SMARTCARD_ADVFEATURE_RXINVERT_INIT          | \
                                                               SMARTCARD_ADVFEATURE_DATAINVERT_INIT        | \
                                                               SMARTCARD_ADVFEATURE_SWAP_INIT              | \
                                                               SMARTCARD_ADVFEATURE_RXOVERRUNDISABLE_INIT  | \
                                                               SMARTCARD_ADVFEATURE_DMADISABLEONERROR_INIT | \
                                                               SMARTCARD_ADVFEATURE_MSBFIRST_INIT))

                                                                     
                                                          
                                                                    
    
#define IS_SMARTCARD_ADVFEATURE_TXINV(__TXINV__) (((__TXINV__) == SMARTCARD_ADVFEATURE_TXINV_DISABLE) || \
                                                  ((__TXINV__) == SMARTCARD_ADVFEATURE_TXINV_ENABLE))

                                                                     
                                                          
                                                                    
    
#define IS_SMARTCARD_ADVFEATURE_RXINV(__RXINV__) (((__RXINV__) == SMARTCARD_ADVFEATURE_RXINV_DISABLE) || \
                                                  ((__RXINV__) == SMARTCARD_ADVFEATURE_RXINV_ENABLE))

                                                                       
                                                              
                                                                        
    
#define IS_SMARTCARD_ADVFEATURE_DATAINV(__DATAINV__) (((__DATAINV__) == SMARTCARD_ADVFEATURE_DATAINV_DISABLE) || \
                                                      ((__DATAINV__) == SMARTCARD_ADVFEATURE_DATAINV_ENABLE))

                                                                        
                                                            
                                                                  
    
#define IS_SMARTCARD_ADVFEATURE_SWAP(__SWAP__) (((__SWAP__) == SMARTCARD_ADVFEATURE_SWAP_DISABLE) || \
                                                ((__SWAP__) == SMARTCARD_ADVFEATURE_SWAP_ENABLE))

                                                                
                                                       
                                                                        
    
#define IS_SMARTCARD_OVERRUN(__OVERRUN__) (((__OVERRUN__) == SMARTCARD_ADVFEATURE_OVERRUN_ENABLE) || \
                                           ((__OVERRUN__) == SMARTCARD_ADVFEATURE_OVERRUN_DISABLE))

                                                                                     
                                                                        
                                                                
    
#define IS_SMARTCARD_ADVFEATURE_DMAONRXERROR(__DMA__) (((__DMA__) == SMARTCARD_ADVFEATURE_DMA_ENABLEONRXERROR) || \
                                                       ((__DMA__) == SMARTCARD_ADVFEATURE_DMA_DISABLEONRXERROR))

                                                                  
                                                          
                                                                          
    
#define IS_SMARTCARD_ADVFEATURE_MSBFIRST(__MSBFIRST__) (((__MSBFIRST__) == SMARTCARD_ADVFEATURE_MSBFIRST_DISABLE) || \
                                                        ((__MSBFIRST__) == SMARTCARD_ADVFEATURE_MSBFIRST_ENABLE))

                                                            
                                                 
                                                                    
    
#define IS_SMARTCARD_REQUEST_PARAMETER(__PARAM__) (((__PARAM__) == SMARTCARD_RXDATA_FLUSH_REQUEST) || \
                                                   ((__PARAM__) == SMARTCARD_TXDATA_FLUSH_REQUEST))

   
      
    

                                           
#include "stm32l4xx_hal_smartcard_ex.h"

                                                                                
                                            
      
    

                                                                                
                                                   
      
    

HAL_StatusTypeDef HAL_SMARTCARD_Init(SMARTCARD_HandleTypeDef *hsmartcard);
HAL_StatusTypeDef HAL_SMARTCARD_DeInit(SMARTCARD_HandleTypeDef *hsmartcard);
void HAL_SMARTCARD_MspInit(SMARTCARD_HandleTypeDef *hsmartcard);
void HAL_SMARTCARD_MspDeInit(SMARTCARD_HandleTypeDef *hsmartcard);

#if (USE_HAL_SMARTCARD_REGISTER_CALLBACKS == 1)
                                                                                
HAL_StatusTypeDef HAL_SMARTCARD_RegisterCallback(SMARTCARD_HandleTypeDef *hsmartcard,
                                                 HAL_SMARTCARD_CallbackIDTypeDef CallbackID,
                                                 pSMARTCARD_CallbackTypeDef pCallback);
HAL_StatusTypeDef HAL_SMARTCARD_UnRegisterCallback(SMARTCARD_HandleTypeDef *hsmartcard,
                                                   HAL_SMARTCARD_CallbackIDTypeDef CallbackID);
#endif                                           

   
      
    

                                                                                
                                                   
      
    

HAL_StatusTypeDef HAL_SMARTCARD_Transmit(SMARTCARD_HandleTypeDef *hsmartcard, const uint8_t *pData, uint16_t Size,
                                         uint32_t Timeout);
HAL_StatusTypeDef HAL_SMARTCARD_Receive(SMARTCARD_HandleTypeDef *hsmartcard, uint8_t *pData, uint16_t Size,
                                        uint32_t Timeout);
HAL_StatusTypeDef HAL_SMARTCARD_Transmit_IT(SMARTCARD_HandleTypeDef *hsmartcard, const uint8_t *pData, uint16_t Size);
HAL_StatusTypeDef HAL_SMARTCARD_Receive_IT(SMARTCARD_HandleTypeDef *hsmartcard, uint8_t *pData, uint16_t Size);
HAL_StatusTypeDef HAL_SMARTCARD_Transmit_DMA(SMARTCARD_HandleTypeDef *hsmartcard, const uint8_t *pData, uint16_t Size);
HAL_StatusTypeDef HAL_SMARTCARD_Receive_DMA(SMARTCARD_HandleTypeDef *hsmartcard, uint8_t *pData, uint16_t Size);
                              
HAL_StatusTypeDef HAL_SMARTCARD_Abort(SMARTCARD_HandleTypeDef *hsmartcard);
HAL_StatusTypeDef HAL_SMARTCARD_AbortTransmit(SMARTCARD_HandleTypeDef *hsmartcard);
HAL_StatusTypeDef HAL_SMARTCARD_AbortReceive(SMARTCARD_HandleTypeDef *hsmartcard);
HAL_StatusTypeDef HAL_SMARTCARD_Abort_IT(SMARTCARD_HandleTypeDef *hsmartcard);
HAL_StatusTypeDef HAL_SMARTCARD_AbortTransmit_IT(SMARTCARD_HandleTypeDef *hsmartcard);
HAL_StatusTypeDef HAL_SMARTCARD_AbortReceive_IT(SMARTCARD_HandleTypeDef *hsmartcard);

void HAL_SMARTCARD_IRQHandler(SMARTCARD_HandleTypeDef *hsmartcard);
void HAL_SMARTCARD_TxCpltCallback(SMARTCARD_HandleTypeDef *hsmartcard);
void HAL_SMARTCARD_RxCpltCallback(SMARTCARD_HandleTypeDef *hsmartcard);
void HAL_SMARTCARD_ErrorCallback(SMARTCARD_HandleTypeDef *hsmartcard);
void HAL_SMARTCARD_AbortCpltCallback(SMARTCARD_HandleTypeDef *hsmartcard);
void HAL_SMARTCARD_AbortTransmitCpltCallback(SMARTCARD_HandleTypeDef *hsmartcard);
void HAL_SMARTCARD_AbortReceiveCpltCallback(SMARTCARD_HandleTypeDef *hsmartcard);

   
      
    

                                                                                
                                                   
      
    

HAL_SMARTCARD_StateTypeDef HAL_SMARTCARD_GetState(const SMARTCARD_HandleTypeDef *hsmartcard);
uint32_t                   HAL_SMARTCARD_GetError(const SMARTCARD_HandleTypeDef *hsmartcard);

   
      
    

   
      
    

   
      
    

   
      
    

#ifdef __cplusplus
}
#endif

#endif                                

