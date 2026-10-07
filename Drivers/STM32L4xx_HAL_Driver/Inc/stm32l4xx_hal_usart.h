/**
  ******************************************************************************
  * @file    stm32l4xx_hal_usart.h
  * @author  MCD Application Team
  * @brief   Header file of USART HAL module.
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

                                                                                
#ifndef STM32L4xx_HAL_USART_H
#define STM32L4xx_HAL_USART_H

#ifdef __cplusplus
extern "C" {
#endif

                                                                                
#include "stm32l4xx_hal_def.h"

                                    
      
    

                     
      
    

                                                                                
                                                       
      
    

   
                                          
    
typedef struct
{
  uint32_t BaudRate;                                                                                
                                                                                                 
                                                                                           
                                                                             
                                                                          
                                                                                             
                                                                                  
                                                                                                       
                                                                                    
                                                                                                
                                                                             

  uint32_t WordLength;                                                                                          
                                                                                                        

  uint32_t StopBits;                                                                     
                                                                                                    

  uint32_t Parity;                                                  
                                                                                             
                                                                                                        
                                                                                                          
                                                                                                        
                                                                                       

  uint32_t Mode;                                                                                                 
                                                                                               

  uint32_t CLKPolarity;                                                                   
                                                                                                         

  uint32_t CLKPhase;                                                                                       
                                                                                                      

  uint32_t CLKLastBit;                                                                                            
                                                                                                               
                                                                                                   

#if defined(USART_PRESC_PRESCALER)
  uint32_t ClockPrescaler;                                                                                     
                                                                                                         
#endif                            
} USART_InitTypeDef;

   
                                                
    
typedef enum
{
  HAL_USART_STATE_RESET             = 0x00U,                                                          
  HAL_USART_STATE_READY             = 0x01U,                                                          
  HAL_USART_STATE_BUSY              = 0x02U,                                                          
  HAL_USART_STATE_BUSY_TX           = 0x12U,                                                          
  HAL_USART_STATE_BUSY_RX           = 0x22U,                                                          
  HAL_USART_STATE_BUSY_TX_RX        = 0x32U,                                                          
  HAL_USART_STATE_TIMEOUT           = 0x03U,                                                          
  HAL_USART_STATE_ERROR             = 0x04U                                                           
} HAL_USART_StateTypeDef;

   
                                           
    
typedef enum
{
  USART_CLOCKSOURCE_PCLK1      = 0x00U,                                  
  USART_CLOCKSOURCE_PCLK2      = 0x01U,                                  
  USART_CLOCKSOURCE_HSI        = 0x02U,                                  
  USART_CLOCKSOURCE_SYSCLK     = 0x04U,                                  
  USART_CLOCKSOURCE_LSE        = 0x08U,                                  
  USART_CLOCKSOURCE_UNDEFINED  = 0x10U                                   
} USART_ClockSourceTypeDef;

   
                                             
    
typedef struct __USART_HandleTypeDef
{
  USART_TypeDef                 *Instance;                                                          

  USART_InitTypeDef             Init;                                                               

  const uint8_t                 *pTxBuffPtr;                                                        

  uint16_t                      TxXferSize;                                                         

  __IO uint16_t                 TxXferCount;                                                        

  uint8_t                       *pRxBuffPtr;                                                        

  uint16_t                      RxXferSize;                                                         

  __IO uint16_t                 RxXferCount;                                                        

  uint16_t                      Mask;                                                               

#if defined(USART_CR1_FIFOEN)
  uint16_t                      NbRxDataToProcess;                                                                

  uint16_t                      NbTxDataToProcess;                                                                

#endif                       
#if defined(USART_CR2_SLVEN)
  uint32_t                      SlaveMode;                                                                                      
                                                                                           

#endif                      
#if defined(USART_CR1_FIFOEN)
  uint32_t                      FifoMode;                                                                                           
                                                                                           

#endif                       
  void (*RxISR)(struct __USART_HandleTypeDef *husart);                                              

  void (*TxISR)(struct __USART_HandleTypeDef *husart);                                              

  DMA_HandleTypeDef             *hdmatx;                                                            

  DMA_HandleTypeDef             *hdmarx;                                                            

  HAL_LockTypeDef               Lock;                                                               

  __IO HAL_USART_StateTypeDef   State;                                                              

  __IO uint32_t                 ErrorCode;                                                          

#if (USE_HAL_USART_REGISTER_CALLBACKS == 1)
  void (* TxHalfCpltCallback)(struct __USART_HandleTypeDef *husart);                                                      
  void (* TxCpltCallback)(struct __USART_HandleTypeDef *husart);                                                          
  void (* RxHalfCpltCallback)(struct __USART_HandleTypeDef *husart);                                                      
  void (* RxCpltCallback)(struct __USART_HandleTypeDef *husart);                                                          
  void (* TxRxCpltCallback)(struct __USART_HandleTypeDef *husart);                                                        
  void (* ErrorCallback)(struct __USART_HandleTypeDef *husart);                                                           
  void (* AbortCpltCallback)(struct __USART_HandleTypeDef *husart);                                                       
#if defined(USART_CR1_FIFOEN)
  void (* RxFifoFullCallback)(struct __USART_HandleTypeDef *husart);                                                      
  void (* TxFifoEmptyCallback)(struct __USART_HandleTypeDef *husart);                                                     
#endif                       

  void (* MspInitCallback)(struct __USART_HandleTypeDef *husart);                                                         
  void (* MspDeInitCallback)(struct __USART_HandleTypeDef *husart);                                                       
#endif                                        

} USART_HandleTypeDef;

#if (USE_HAL_USART_REGISTER_CALLBACKS == 1)
   
                                                        
    
typedef enum
{
  HAL_USART_TX_HALFCOMPLETE_CB_ID         = 0x00U,                                                     
  HAL_USART_TX_COMPLETE_CB_ID             = 0x01U,                                                     
  HAL_USART_RX_HALFCOMPLETE_CB_ID         = 0x02U,                                                     
  HAL_USART_RX_COMPLETE_CB_ID             = 0x03U,                                                     
  HAL_USART_TX_RX_COMPLETE_CB_ID          = 0x04U,                                                     
  HAL_USART_ERROR_CB_ID                   = 0x05U,                                                     
  HAL_USART_ABORT_COMPLETE_CB_ID          = 0x06U,                                                     
#if defined(USART_CR1_FIFOEN)
  HAL_USART_RX_FIFO_FULL_CB_ID            = 0x07U,                                                     
  HAL_USART_TX_FIFO_EMPTY_CB_ID           = 0x08U,                                                     
#endif                       

  HAL_USART_MSPINIT_CB_ID                 = 0x09U,                                                     
  HAL_USART_MSPDEINIT_CB_ID               = 0x0AU                                                      

} HAL_USART_CallbackIDTypeDef;

   
                                                 
    
typedef  void (*pUSART_CallbackTypeDef)(USART_HandleTypeDef *husart);                                               

#endif                                       

   
      
    

                                                                                
                                                               
      
    

                                                             
      
    
#define HAL_USART_ERROR_NONE             (0x00000000U)                                     
#define HAL_USART_ERROR_PE               (0x00000001U)                                     
#define HAL_USART_ERROR_NE               (0x00000002U)                                     
#define HAL_USART_ERROR_FE               (0x00000004U)                                     
#define HAL_USART_ERROR_ORE              (0x00000008U)                                     
#define HAL_USART_ERROR_DMA              (0x00000010U)                                     
#if defined(USART_CR2_SLVEN)
#define HAL_USART_ERROR_UDR              (0x00000020U)                                     
#endif                      
#if (USE_HAL_USART_REGISTER_CALLBACKS == 1)
#define HAL_USART_ERROR_INVALID_CALLBACK (0x00000040U)                                     
#endif                                       
#define  HAL_USART_ERROR_RTO              (0x00000080U)                                   
   
      
    

                                                        
      
    
#define USART_STOPBITS_0_5                   USART_CR2_STOP_0                                                           
#define USART_STOPBITS_1                     0x00000000U                                                                
#define USART_STOPBITS_1_5                  (USART_CR2_STOP_0 | USART_CR2_STOP_1)                                       
#define USART_STOPBITS_2                     USART_CR2_STOP_1                                                           
   
      
    

                                          
      
    
#define USART_PARITY_NONE                   0x00000000U                                         
#define USART_PARITY_EVEN                   USART_CR1_PCE                                       
#define USART_PARITY_ODD                    (USART_CR1_PCE | USART_CR1_PS)                      
   
      
    

                                     
      
    
#define USART_MODE_RX                       USART_CR1_RE                                          
#define USART_MODE_TX                       USART_CR1_TE                                          
#define USART_MODE_TX_RX                    (USART_CR1_TE |USART_CR1_RE)                          
   
      
    

                                      
      
    
#define USART_CLOCK_DISABLE                 0x00000000U                                  
#define USART_CLOCK_ENABLE                  USART_CR2_CLKEN                              
   
      
    

                                                        
      
    
#define USART_POLARITY_LOW                  0x00000000U                                                 
#define USART_POLARITY_HIGH                 USART_CR2_CPOL                                              
   
      
    

                                                   
      
    
#define USART_PHASE_1EDGE                   0x00000000U                                                          
#define USART_PHASE_2EDGE                   USART_CR2_CPHA                                                       
   
      
    

                                            
      
    
#define USART_LASTBIT_DISABLE               0x00000000U                                                                          
#define USART_LASTBIT_ENABLE                USART_CR2_LBCL                                                                       
   
      
    

#if defined(USART_PRESC_PRESCALER)
                                                         
      
    
#define USART_PRESCALER_DIV1    0x00000000U                              
#define USART_PRESCALER_DIV2    0x00000001U                              
#define USART_PRESCALER_DIV4    0x00000002U                              
#define USART_PRESCALER_DIV6    0x00000003U                              
#define USART_PRESCALER_DIV8    0x00000004U                              
#define USART_PRESCALER_DIV10   0x00000005U                              
#define USART_PRESCALER_DIV12   0x00000006U                              
#define USART_PRESCALER_DIV16   0x00000007U                              
#define USART_PRESCALER_DIV32   0x00000008U                              
#define USART_PRESCALER_DIV64   0x00000009U                              
#define USART_PRESCALER_DIV128  0x0000000AU                              
#define USART_PRESCALER_DIV256  0x0000000BU                              

   
      
    
#endif                            

                                                                
      
    
#define USART_RXDATA_FLUSH_REQUEST        USART_RQR_RXFRQ                                           
#define USART_TXDATA_FLUSH_REQUEST        USART_RQR_TXFRQ                                           
   
      
    

                                          
                                             
                                                       
      
    
#if defined(USART_CR1_FIFOEN)
#define USART_FLAG_TXFT                     USART_ISR_TXFT                                                            
#define USART_FLAG_RXFT                     USART_ISR_RXFT                                                            
#define USART_FLAG_RXFF                     USART_ISR_RXFF                                                            
#define USART_FLAG_TXFE                     USART_ISR_TXFE                                                            
#endif                       
#define USART_FLAG_REACK                    USART_ISR_REACK                                                           
#define USART_FLAG_TEACK                    USART_ISR_TEACK                                                           
#define USART_FLAG_BUSY                     USART_ISR_BUSY                                                            
#if defined(USART_CR2_SLVEN)
#define USART_FLAG_UDR                      USART_ISR_UDR                                                             
#endif                      
#if defined(USART_CR1_FIFOEN)
#define USART_FLAG_TXE                      USART_ISR_TXE_TXFNF                                                       
#define USART_FLAG_TXFNF                    USART_ISR_TXE_TXFNF                                                       
#else
#define USART_FLAG_TXE                      USART_ISR_TXE                                                             
#endif                       
#define USART_FLAG_RTOF                     USART_ISR_RTOF                                                            
#define USART_FLAG_TC                       USART_ISR_TC                                                              
#if defined(USART_CR1_FIFOEN)
#define USART_FLAG_RXNE                     USART_ISR_RXNE_RXFNE                                                      
#define USART_FLAG_RXFNE                    USART_ISR_RXNE_RXFNE                                                      
#else
#define USART_FLAG_RXNE                     USART_ISR_RXNE                                                            
#endif                       
#define USART_FLAG_IDLE                     USART_ISR_IDLE                                                            
#define USART_FLAG_ORE                      USART_ISR_ORE                                                             
#define USART_FLAG_NE                       USART_ISR_NE                                                              
#define USART_FLAG_FE                       USART_ISR_FE                                                              
#define USART_FLAG_PE                       USART_ISR_PE                                                              
   
      
    

                                                                    
                                                        
                                                                             
                                                       
                                      
                                      
                                      
                                                                
      
    

#define USART_IT_PE                          0x0028U                                                            
#define USART_IT_TXE                         0x0727U                                                            
#if defined(USART_CR1_FIFOEN)
#define USART_IT_TXFNF                       0x0727U                                                            
#endif                       
#define USART_IT_TC                          0x0626U                                                            
#define USART_IT_RXNE                        0x0525U                                                            
#if defined(USART_CR1_FIFOEN)
#define USART_IT_RXFNE                       0x0525U                                                            
#endif                       
#define USART_IT_IDLE                        0x0424U                                                            
#define USART_IT_ERR                         0x0060U                                                            
#define USART_IT_ORE                         0x0300U                                                            
#define USART_IT_NE                          0x0200U                                                            
#define USART_IT_FE                          0x0100U                                                            
#if defined(USART_CR1_FIFOEN)
#define USART_IT_RXFF                        0x183FU                                                            
#define USART_IT_TXFE                        0x173EU                                                            
#define USART_IT_RXFT                        0x1A7CU                                                            
#define USART_IT_TXFT                        0x1B77U                                                            
#endif                       

   
      
    

                                                                    
      
    
#define USART_CLEAR_PEF                       USART_ICR_PECF                                                       
#define USART_CLEAR_FEF                       USART_ICR_FECF                                                       
#define USART_CLEAR_NEF                       USART_ICR_NECF                                                       
#define USART_CLEAR_OREF                      USART_ICR_ORECF                                                      
#define USART_CLEAR_IDLEF                     USART_ICR_IDLECF                                                     
#define USART_CLEAR_TCF                       USART_ICR_TCCF                                                       
#if defined(USART_CR2_SLVEN)
#define USART_CLEAR_UDRF                      USART_ICR_UDRCF                                                      
#endif                      
#if defined(USART_CR1_FIFOEN)
#define USART_CLEAR_TXFECF                    USART_ICR_TXFECF                                                     
#endif                       
#define USART_CLEAR_RTOF                      USART_ICR_RTOCF                                                     
   
      
    

                                                                      
      
    
#define USART_IT_MASK                             0x001FU                                           
#define USART_CR_MASK                             0x00E0U                                        
#define USART_CR_POS                              5U                                                 
#define USART_ISR_MASK                            0x1F00U                                            
#define USART_ISR_POS                             8U                                                 
   
      
    

   
      
    

                                                                                
                                                         
      
    

                                    
                                    
                
    
#if (USE_HAL_USART_REGISTER_CALLBACKS == 1)
#define __HAL_USART_RESET_HANDLE_STATE(__HANDLE__)  do{                                            \
                                                        (__HANDLE__)->State = HAL_USART_STATE_RESET; \
                                                        (__HANDLE__)->MspInitCallback = NULL;        \
                                                        (__HANDLE__)->MspDeInitCallback = NULL;      \
                                                      } while(0U)
#else
#define __HAL_USART_RESET_HANDLE_STATE(__HANDLE__)  ((__HANDLE__)->State = HAL_USART_STATE_RESET)
#endif                                       

                                                                 
                                                 
                                                 
                                                             
                                                               
                                                               
                                                          
                                                           
                                                                         
                                                                          
                                                   
                                                                       
                                                                           
                                                              
                                                                    
                                                                              
                                                               
                                                               
                                                                  
                                                            
                                                          
                                                            
                                                           
                                                      
    
#define __HAL_USART_GET_FLAG(__HANDLE__, __FLAG__) (((__HANDLE__)->Instance->ISR & (__FLAG__)) == (__FLAG__))

                                                   
                                                  
                                                 
                                                                           
                                                                     
                                                                      
                                                                       
                                                                      
                                                                           
                                                                     
                                                                              
                                                                         
                                                                                 
                
    
#define __HAL_USART_CLEAR_FLAG(__HANDLE__, __FLAG__) ((__HANDLE__)->Instance->ICR = (__FLAG__))

                                            
                                                  
                
    
#define __HAL_USART_CLEAR_PEFLAG(__HANDLE__)   __HAL_USART_CLEAR_FLAG((__HANDLE__), USART_CLEAR_PEF)

                                            
                                                  
                
    
#define __HAL_USART_CLEAR_FEFLAG(__HANDLE__)   __HAL_USART_CLEAR_FLAG((__HANDLE__), USART_CLEAR_FEF)

                                            
                                                  
                
    
#define __HAL_USART_CLEAR_NEFLAG(__HANDLE__)  __HAL_USART_CLEAR_FLAG((__HANDLE__), USART_CLEAR_NEF)

                                             
                                                  
                
    
#define __HAL_USART_CLEAR_OREFLAG(__HANDLE__)   __HAL_USART_CLEAR_FLAG((__HANDLE__), USART_CLEAR_OREF)

                                              
                                                  
                
    
#define __HAL_USART_CLEAR_IDLEFLAG(__HANDLE__)   __HAL_USART_CLEAR_FLAG((__HANDLE__), USART_CLEAR_IDLEF)

#if defined(USART_CR1_FIFOEN)
                                                     
                                                  
                
    
#define __HAL_USART_CLEAR_TXFECF(__HANDLE__)   __HAL_USART_CLEAR_FLAG((__HANDLE__), USART_CLEAR_TXFECF)
#endif                       

#if defined(USART_CR2_SLVEN)
                                                
                                                  
                
    
#define __HAL_USART_CLEAR_UDRFLAG(__HANDLE__)   __HAL_USART_CLEAR_FLAG((__HANDLE__), USART_CLEAR_UDRF)

#endif                      
                                                 
                                                  
                                                                         
                                                               
                                                             
                                                              
                                                                  
                                                                  
                                                                              
                                                                  
                                                                       
                                                                                 
                                                                  
                                                                     
                                                              
                                                                                                
                
    
#define __HAL_USART_ENABLE_IT(__HANDLE__, __INTERRUPT__)\
  (((((__INTERRUPT__) & USART_CR_MASK) >> USART_CR_POS) == 1U)?\
   ((__HANDLE__)->Instance->CR1 |= (1UL << ((__INTERRUPT__) & USART_IT_MASK))): \
   ((((__INTERRUPT__) & USART_CR_MASK) >> USART_CR_POS) == 2U)?\
   ((__HANDLE__)->Instance->CR2 |= (1UL << ((__INTERRUPT__) & USART_IT_MASK))): \
   ((__HANDLE__)->Instance->CR3 |= (1UL << ((__INTERRUPT__) & USART_IT_MASK))))

                                                  
                                                  
                                                                          
                                                               
                                                             
                                                              
                                                                  
                                                                  
                                                                              
                                                                  
                                                                       
                                                                                 
                                                                  
                                                                     
                                                              
                                                                                                
                
    
#define __HAL_USART_DISABLE_IT(__HANDLE__, __INTERRUPT__)\
  (((((__INTERRUPT__) & USART_CR_MASK) >> USART_CR_POS) == 1U)?\
   ((__HANDLE__)->Instance->CR1 &= ~ (1UL << ((__INTERRUPT__) & USART_IT_MASK))): \
   ((((__INTERRUPT__) & USART_CR_MASK) >> USART_CR_POS) == 2U)?\
   ((__HANDLE__)->Instance->CR2 &= ~ (1UL << ((__INTERRUPT__) & USART_IT_MASK))): \
   ((__HANDLE__)->Instance->CR3 &= ~ (1UL << ((__INTERRUPT__) & USART_IT_MASK))))

                                                                            
                                                  
                                                                        
                                                               
                                                             
                                                              
                                                                  
                                                                  
                                                                              
                                                                  
                                                                       
                                                                                 
                                                                  
                                                                     
                                                               
                                                             
                                                               
                                                              
                                                          
    
#define __HAL_USART_GET_IT(__HANDLE__, __INTERRUPT__) ((((__HANDLE__)->Instance->ISR\
                                                         & (0x01U << (((__INTERRUPT__) & USART_ISR_MASK)>>\
                                                                      USART_ISR_POS))) != 0U) ? SET : RESET)

                                                                                 
                                                  
                                                                        
                                                               
                                                             
                                                              
                                                                  
                                                                  
                                                                              
                                                                  
                                                                       
                                                                                 
                                                                  
                                                                     
                                                               
                                                             
                                                               
                                                              
                                                          
    
#define __HAL_USART_GET_IT_SOURCE(__HANDLE__, __INTERRUPT__) ((((((((uint8_t)(__INTERRUPT__)) >> 0x05U) == 0x01U) ?\
                                                                 (__HANDLE__)->Instance->CR1 : \
                                                                 (((((uint8_t)(__INTERRUPT__)) >> 0x05U) == 0x02U) ?\
                                                                  (__HANDLE__)->Instance->CR2 : \
                                                                  (__HANDLE__)->Instance->CR3)) & (0x01U <<\
                                                                      (((uint16_t)(__INTERRUPT__)) &\
                                                                       USART_IT_MASK)))  != 0U) ? SET : RESET)

                                                                                        
                                                  
                                                                                         
                                                               
                                                               
                                                                     
                                                                      
                                                                       
                                                                      
                                                                           
                                                                         
                                                                     
                                                                              
                
    
#define __HAL_USART_CLEAR_IT(__HANDLE__, __IT_CLEAR__) ((__HANDLE__)->Instance->ICR = (uint32_t)(__IT_CLEAR__))

                                              
                                                  
                                                      
                                                               
                                                                              
                                                                               
   
                
    
#define __HAL_USART_SEND_REQ(__HANDLE__, __REQ__)      ((__HANDLE__)->Instance->RQR |= (uint16_t)(__REQ__))

                                                   
                                                  
                
    
#define __HAL_USART_ONE_BIT_SAMPLE_ENABLE(__HANDLE__) ((__HANDLE__)->Instance->CR3|= USART_CR3_ONEBIT)

                                                    
                                                  
                
    
#define __HAL_USART_ONE_BIT_SAMPLE_DISABLE(__HANDLE__) ((__HANDLE__)->Instance->CR3 &= ~USART_CR3_ONEBIT)

                         
                                                  
                
    
#define __HAL_USART_ENABLE(__HANDLE__)                 ((__HANDLE__)->Instance->CR1 |= USART_CR1_UE)

                          
                                                  
                
    
#define __HAL_USART_DISABLE(__HANDLE__)                ((__HANDLE__)->Instance->CR1 &= ~USART_CR1_UE)

   
      
    

                                                                            
                                                         
      
    

#if defined(USART_PRESC_PRESCALER)
                                                                       
                                                     
                                       
    
#define USART_GET_DIV_FACTOR(__CLOCKPRESCALER__) \
  (((__CLOCKPRESCALER__) == USART_PRESCALER_DIV1)   ? 1U :       \
   ((__CLOCKPRESCALER__) == USART_PRESCALER_DIV2)   ? 2U :       \
   ((__CLOCKPRESCALER__) == USART_PRESCALER_DIV4)   ? 4U :       \
   ((__CLOCKPRESCALER__) == USART_PRESCALER_DIV6)   ? 6U :       \
   ((__CLOCKPRESCALER__) == USART_PRESCALER_DIV8)   ? 8U :       \
   ((__CLOCKPRESCALER__) == USART_PRESCALER_DIV10)  ? 10U :      \
   ((__CLOCKPRESCALER__) == USART_PRESCALER_DIV12)  ? 12U :      \
   ((__CLOCKPRESCALER__) == USART_PRESCALER_DIV16)  ? 16U :      \
   ((__CLOCKPRESCALER__) == USART_PRESCALER_DIV32)  ? 32U :      \
   ((__CLOCKPRESCALER__) == USART_PRESCALER_DIV64)  ? 64U :      \
   ((__CLOCKPRESCALER__) == USART_PRESCALER_DIV128) ? 128U : 256U)

                                                                                  
                                 
                                               
                                                     
                           
    
#define USART_DIV_SAMPLING8(__PCLK__, __BAUD__, __CLOCKPRESCALER__)\
  (((((__PCLK__)/USART_GET_DIV_FACTOR(__CLOCKPRESCALER__))*2U)\
    + ((__BAUD__)/2U)) / (__BAUD__))
#else
                                                                                  
                                 
                                               
                           
    
#define USART_DIV_SAMPLING8(__PCLK__, __BAUD__)   ((((__PCLK__)*2U) + ((__BAUD__)/2U)) / (__BAUD__))
#endif                            

                                  
                                                        
                                                                         
                                                                           
                                                               
                                                                          
    
#if defined(STM32L4R5xx) || defined(STM32L4R7xx) || defined(STM32L4R9xx) || defined(STM32L4S5xx) || defined(STM32L4S7xx) || defined(STM32L4S9xx)
#define IS_USART_BAUDRATE(__BAUDRATE__) ((__BAUDRATE__) <= 15000000U)
#else
#define IS_USART_BAUDRATE(__BAUDRATE__) ((__BAUDRATE__) <= 10000000U)
#endif                                                                                             

   
                                                                
                                                        
                                                                          
    
#define IS_USART_STOPBITS(__STOPBITS__) (((__STOPBITS__) == USART_STOPBITS_0_5) || \
                                         ((__STOPBITS__) == USART_STOPBITS_1)   || \
                                         ((__STOPBITS__) == USART_STOPBITS_1_5) || \
                                         ((__STOPBITS__) == USART_STOPBITS_2))

   
                                                   
                                         
                                                                      
    
#define IS_USART_PARITY(__PARITY__) (((__PARITY__) == USART_PARITY_NONE) || \
                                     ((__PARITY__) == USART_PARITY_EVEN) || \
                                     ((__PARITY__) == USART_PARITY_ODD))

   
                                                         
                                             
                                                                  
    
#define IS_USART_MODE(__MODE__) ((((__MODE__) & 0xFFFFFFF3U) == 0x00U) && ((__MODE__) != 0x00U))

   
                                                  
                                       
                                                                    
    
#define IS_USART_CLOCK(__CLOCK__) (((__CLOCK__) == USART_CLOCK_DISABLE) || \
                                   ((__CLOCK__) == USART_CLOCK_ENABLE))

   
                                                     
                                         
                                                                  
    
#define IS_USART_POLARITY(__CPOL__) (((__CPOL__) == USART_POLARITY_LOW) || ((__CPOL__) == USART_POLARITY_HIGH))

   
                                                  
                                      
                                                                  
    
#define IS_USART_PHASE(__CPHA__) (((__CPHA__) == USART_PHASE_1EDGE) || ((__CPHA__) == USART_PHASE_2EDGE))

   
                                                                         
                                                                
                                                                        
    
#define IS_USART_LASTBIT(__LASTBIT__) (((__LASTBIT__) == USART_LASTBIT_DISABLE) || \
                                       ((__LASTBIT__) == USART_LASTBIT_ENABLE))

   
                                                        
                                             
                                                                    
    
#define IS_USART_REQUEST_PARAMETER(__PARAM__) (((__PARAM__) == USART_RXDATA_FLUSH_REQUEST) || \
                                               ((__PARAM__) == USART_TXDATA_FLUSH_REQUEST))

#if defined(USART_PRESC_PRESCALER)
   
                                                
                                                    
                                                                                      
    
#define IS_USART_PRESCALER(__CLOCKPRESCALER__) (((__CLOCKPRESCALER__) == USART_PRESCALER_DIV1) || \
                                                ((__CLOCKPRESCALER__) == USART_PRESCALER_DIV2) || \
                                                ((__CLOCKPRESCALER__) == USART_PRESCALER_DIV4) || \
                                                ((__CLOCKPRESCALER__) == USART_PRESCALER_DIV6) || \
                                                ((__CLOCKPRESCALER__) == USART_PRESCALER_DIV8) || \
                                                ((__CLOCKPRESCALER__) == USART_PRESCALER_DIV10) || \
                                                ((__CLOCKPRESCALER__) == USART_PRESCALER_DIV12) || \
                                                ((__CLOCKPRESCALER__) == USART_PRESCALER_DIV16) || \
                                                ((__CLOCKPRESCALER__) == USART_PRESCALER_DIV32) || \
                                                ((__CLOCKPRESCALER__) == USART_PRESCALER_DIV64) || \
                                                ((__CLOCKPRESCALER__) == USART_PRESCALER_DIV128) || \
                                                ((__CLOCKPRESCALER__) == USART_PRESCALER_DIV256))

#endif                            
   
      
    

                                       
#include "stm32l4xx_hal_usart_ex.h"

                                                                                
                                                                 
      
    

                                                                                              
      
    

                                                                                
HAL_StatusTypeDef HAL_USART_Init(USART_HandleTypeDef *husart);
HAL_StatusTypeDef HAL_USART_DeInit(USART_HandleTypeDef *husart);
void HAL_USART_MspInit(USART_HandleTypeDef *husart);
void HAL_USART_MspDeInit(USART_HandleTypeDef *husart);

                                                                                
#if (USE_HAL_USART_REGISTER_CALLBACKS == 1)
HAL_StatusTypeDef HAL_USART_RegisterCallback(USART_HandleTypeDef *husart, HAL_USART_CallbackIDTypeDef CallbackID,
                                             pUSART_CallbackTypeDef pCallback);
HAL_StatusTypeDef HAL_USART_UnRegisterCallback(USART_HandleTypeDef *husart, HAL_USART_CallbackIDTypeDef CallbackID);
#endif                                       

   
      
    

                                                                      
      
    

                                                                                
HAL_StatusTypeDef HAL_USART_Transmit(USART_HandleTypeDef *husart, const uint8_t *pTxData, uint16_t Size,
                                     uint32_t Timeout);
HAL_StatusTypeDef HAL_USART_Receive(USART_HandleTypeDef *husart, uint8_t *pRxData, uint16_t Size, uint32_t Timeout);
HAL_StatusTypeDef HAL_USART_TransmitReceive(USART_HandleTypeDef *husart, const uint8_t *pTxData, uint8_t *pRxData,
                                            uint16_t Size, uint32_t Timeout);
HAL_StatusTypeDef HAL_USART_Transmit_IT(USART_HandleTypeDef *husart, const uint8_t *pTxData, uint16_t Size);
HAL_StatusTypeDef HAL_USART_Receive_IT(USART_HandleTypeDef *husart, uint8_t *pRxData, uint16_t Size);
HAL_StatusTypeDef HAL_USART_TransmitReceive_IT(USART_HandleTypeDef *husart, const uint8_t *pTxData, uint8_t *pRxData,
                                               uint16_t Size);
HAL_StatusTypeDef HAL_USART_Transmit_DMA(USART_HandleTypeDef *husart, const uint8_t *pTxData, uint16_t Size);
HAL_StatusTypeDef HAL_USART_Receive_DMA(USART_HandleTypeDef *husart, uint8_t *pRxData, uint16_t Size);
HAL_StatusTypeDef HAL_USART_TransmitReceive_DMA(USART_HandleTypeDef *husart, const uint8_t *pTxData, uint8_t *pRxData,
                                                uint16_t Size);
HAL_StatusTypeDef HAL_USART_DMAPause(USART_HandleTypeDef *husart);
HAL_StatusTypeDef HAL_USART_DMAResume(USART_HandleTypeDef *husart);
HAL_StatusTypeDef HAL_USART_DMAStop(USART_HandleTypeDef *husart);
                              
HAL_StatusTypeDef HAL_USART_Abort(USART_HandleTypeDef *husart);
HAL_StatusTypeDef HAL_USART_Abort_IT(USART_HandleTypeDef *husart);

void HAL_USART_IRQHandler(USART_HandleTypeDef *husart);
void HAL_USART_TxHalfCpltCallback(USART_HandleTypeDef *husart);
void HAL_USART_TxCpltCallback(USART_HandleTypeDef *husart);
void HAL_USART_RxCpltCallback(USART_HandleTypeDef *husart);
void HAL_USART_RxHalfCpltCallback(USART_HandleTypeDef *husart);
void HAL_USART_TxRxCpltCallback(USART_HandleTypeDef *husart);
void HAL_USART_ErrorCallback(USART_HandleTypeDef *husart);
void HAL_USART_AbortCpltCallback(USART_HandleTypeDef *husart);

   
      
    

                                                                                    
      
    

                                                                                
HAL_USART_StateTypeDef HAL_USART_GetState(const USART_HandleTypeDef *husart);
uint32_t               HAL_USART_GetError(const USART_HandleTypeDef *husart);

   
      
    

   
      
    

   
      
    

   
      
    

#ifdef __cplusplus
}
#endif

#endif                            

