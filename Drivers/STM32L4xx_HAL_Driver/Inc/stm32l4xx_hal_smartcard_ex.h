/**
  ******************************************************************************
  * @file    stm32l4xx_hal_smartcard_ex.h
  * @author  MCD Application Team
  * @brief   Header file of SMARTCARD HAL Extended module.
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

                                                                                
#ifndef STM32L4xx_HAL_SMARTCARD_EX_H
#define STM32L4xx_HAL_SMARTCARD_EX_H

#ifdef __cplusplus
extern "C" {
#endif

                                                                                
#include "stm32l4xx_hal_def.h"

                                    
      
    

                           
      
    

                                                                                
                                                                                

                                                                                     
      
    

                                                                                                         
      
    
#if defined(USART_TCBGT_SUPPORT)
#define SMARTCARD_TCBGT      SMARTCARD_IT_TCBGT                                                          
#endif                          
#define SMARTCARD_TC         SMARTCARD_IT_TC                                                                                     
   
      
    

                                                                                                              
      
    
#define SMARTCARD_ADVFEATURE_NO_INIT                 0x00000000U                                                               
#define SMARTCARD_ADVFEATURE_TXINVERT_INIT           0x00000001U                                                               
#define SMARTCARD_ADVFEATURE_RXINVERT_INIT           0x00000002U                                                               
#define SMARTCARD_ADVFEATURE_DATAINVERT_INIT         0x00000004U                                                               
#define SMARTCARD_ADVFEATURE_SWAP_INIT               0x00000008U                                                               
#define SMARTCARD_ADVFEATURE_RXOVERRUNDISABLE_INIT   0x00000010U                                                               
#define SMARTCARD_ADVFEATURE_DMADISABLEONERROR_INIT  0x00000020U                                                               
#define SMARTCARD_ADVFEATURE_MSBFIRST_INIT           0x00000080U                                                               
#if defined(USART_TCBGT_SUPPORT)
#define SMARTCARD_ADVFEATURE_TXCOMPLETION            0x00000100U                                                               
#endif                          
   
      
    

#if defined(USART_CR1_FIFOEN)
                                                       
                                 
      
    
#define SMARTCARD_FIFOMODE_DISABLE        0x00000000U                                            
#define SMARTCARD_FIFOMODE_ENABLE         USART_CR1_FIFOEN                                       
   
      
    

                                                                                 
                                    
      
    
#define SMARTCARD_TXFIFO_THRESHOLD_1_8    0x00000000U                                                                      
#define SMARTCARD_TXFIFO_THRESHOLD_1_4   USART_CR3_TXFTCFG_0                                                               
#define SMARTCARD_TXFIFO_THRESHOLD_1_2   USART_CR3_TXFTCFG_1                                                               
#define SMARTCARD_TXFIFO_THRESHOLD_3_4   (USART_CR3_TXFTCFG_0|USART_CR3_TXFTCFG_1)                                         
#define SMARTCARD_TXFIFO_THRESHOLD_7_8   USART_CR3_TXFTCFG_2                                                               
#define SMARTCARD_TXFIFO_THRESHOLD_8_8   (USART_CR3_TXFTCFG_2|USART_CR3_TXFTCFG_0)                                         
   
      
    

                                                                                 
                                    
      
    
#define SMARTCARD_RXFIFO_THRESHOLD_1_8   0x00000000U                                                                            
#define SMARTCARD_RXFIFO_THRESHOLD_1_4   USART_CR3_RXFTCFG_0                                                                    
#define SMARTCARD_RXFIFO_THRESHOLD_1_2   USART_CR3_RXFTCFG_1                                                                    
#define SMARTCARD_RXFIFO_THRESHOLD_3_4   (USART_CR3_RXFTCFG_0|USART_CR3_RXFTCFG_1)                                              
#define SMARTCARD_RXFIFO_THRESHOLD_7_8   USART_CR3_RXFTCFG_2                                                                    
#define SMARTCARD_RXFIFO_THRESHOLD_8_8   (USART_CR3_RXFTCFG_2|USART_CR3_RXFTCFG_0)                                              
   
      
    

#endif                       
                                               
                                             
                                                       
      
    
#if defined(USART_TCBGT_SUPPORT)
#define SMARTCARD_FLAG_TCBGT          USART_ISR_TCBGT                                                                             
#endif                          
#define SMARTCARD_FLAG_REACK          USART_ISR_REACK                                                           
#define SMARTCARD_FLAG_TEACK          USART_ISR_TEACK                                                           
#define SMARTCARD_FLAG_BUSY           USART_ISR_BUSY                                                            
#define SMARTCARD_FLAG_EOBF           USART_ISR_EOBF                                                            
#define SMARTCARD_FLAG_RTOF           USART_ISR_RTOF                                                            
#if defined(USART_CR1_FIFOEN)
#define SMARTCARD_FLAG_TXE            USART_ISR_TXE_TXFNF                                                       
#define SMARTCARD_FLAG_TXFNF          USART_ISR_TXE_TXFNF                                                       
#else
#define SMARTCARD_FLAG_TXE            USART_ISR_TXE                                                             
#endif                       
#define SMARTCARD_FLAG_TC             USART_ISR_TC                                                              
#if defined(USART_CR1_FIFOEN)
#define SMARTCARD_FLAG_RXNE           USART_ISR_RXNE_RXFNE                                                      
#define SMARTCARD_FLAG_RXFNE          USART_ISR_RXNE_RXFNE                                                      
#else
#define SMARTCARD_FLAG_RXNE           USART_ISR_RXNE                                                            
#endif                       
#define SMARTCARD_FLAG_IDLE           USART_ISR_IDLE                                                            
#define SMARTCARD_FLAG_ORE            USART_ISR_ORE                                                             
#define SMARTCARD_FLAG_NE             USART_ISR_NE                                                              
#define SMARTCARD_FLAG_FE             USART_ISR_FE                                                              
#define SMARTCARD_FLAG_PE             USART_ISR_PE                                                              
#if defined(USART_CR1_FIFOEN)
#define SMARTCARD_FLAG_TXFE           USART_ISR_TXFE                                                            
#define SMARTCARD_FLAG_RXFF           USART_ISR_RXFF                                                            
#define SMARTCARD_FLAG_RXFT           USART_ISR_RXFT                                                            
#define SMARTCARD_FLAG_TXFT           USART_ISR_TXFT                                                            
#endif                       
   
      
    

                                                                              
                                                        
                                                                              
                                                        
                                      
                                      
                                      
                                                                  
      
    
#define SMARTCARD_IT_PE                     0x0028U                                                                      
#define SMARTCARD_IT_TXE                    0x0727U                                                                      
#if defined(USART_CR1_FIFOEN)
#define SMARTCARD_IT_TXFNF                  0x0727U                                                                      
#endif                       
#define SMARTCARD_IT_TC                     0x0626U                                                                      
#define SMARTCARD_IT_RXNE                   0x0525U                                                                      
#if defined(USART_CR1_FIFOEN)
#define SMARTCARD_IT_RXFNE                  0x0525U                                                                      
#endif                       
#define SMARTCARD_IT_IDLE                   0x0424U                                                                      

#define SMARTCARD_IT_ERR                    0x0060U                                                       
#define SMARTCARD_IT_ORE                    0x0300U                                                       
#define SMARTCARD_IT_NE                     0x0200U                                                       
#define SMARTCARD_IT_FE                     0x0100U                                                       

#define SMARTCARD_IT_EOB                    0x0C3BU                                                          
#define SMARTCARD_IT_RTO                    0x0B3AU                                                          
#if defined(USART_TCBGT_SUPPORT)
#define SMARTCARD_IT_TCBGT                  0x1978U                                                                                            
#endif                          

#if defined(USART_CR1_FIFOEN)
#define SMARTCARD_IT_RXFF                    0x183FU                                                                     
#define SMARTCARD_IT_TXFE                    0x173EU                                                                     
#define SMARTCARD_IT_RXFT                    0x1A7CU                                                                     
#define SMARTCARD_IT_TXFT                    0x1B77U                                                                     
#endif                       
   
      
    

                                                                           
      
    
#define SMARTCARD_CLEAR_PEF                 USART_ICR_PECF                                                      
#define SMARTCARD_CLEAR_FEF                 USART_ICR_FECF                                                      
#define SMARTCARD_CLEAR_NEF                 USART_ICR_NECF                                                      
#define SMARTCARD_CLEAR_OREF                USART_ICR_ORECF                                                     
#define SMARTCARD_CLEAR_IDLEF               USART_ICR_IDLECF                                                    
#if defined(USART_CR1_FIFOEN)
#define SMARTCARD_CLEAR_TXFECF              USART_ICR_TXFECF                                                    
#endif                       
#define SMARTCARD_CLEAR_TCF                 USART_ICR_TCCF                                                      
#if defined(USART_TCBGT_SUPPORT)
#define SMARTCARD_CLEAR_TCBGTF              USART_ICR_TCBGTCF                                                                                
#endif                          
#define SMARTCARD_CLEAR_RTOF                USART_ICR_RTOCF                                                     
#define SMARTCARD_CLEAR_EOBF                USART_ICR_EOBCF                                                     
   
      
    

   
      
    
                                                                                
                                                                                
                                                                          
      
    

                                                
                                                      
                                                                                         
                                                                                          
                                                                                            
                
    
#if defined(USART_TCBGT_SUPPORT)
#define SMARTCARD_TRANSMISSION_COMPLETION_SETTING(__HANDLE__)                                                \
  do {                                                                                                       \
    if (HAL_IS_BIT_CLR((__HANDLE__)->AdvancedInit.AdvFeatureInit, SMARTCARD_ADVFEATURE_TXCOMPLETION))        \
    {                                                                                                        \
      (__HANDLE__)->AdvancedInit.TxCompletionIndication = SMARTCARD_TC;                                      \
    }                                                                                                        \
    else                                                                                                     \
    {                                                                                                        \
      assert_param(IS_SMARTCARD_TRANSMISSION_COMPLETION((__HANDLE__)->AdvancedInit.TxCompletionIndication)); \
    }                                                                                                        \
  } while(0U)
#else
#define SMARTCARD_TRANSMISSION_COMPLETION_SETTING(__HANDLE__)         \
  do {                                                                \
    (__HANDLE__)->AdvancedInit.TxCompletionIndication = SMARTCARD_TC; \
  } while(0U)
#endif                          

                                                    
                                                      
                                                                                         
                                                                                                 
                    
                                        
    
#if defined(USART_TCBGT_SUPPORT)
#define SMARTCARD_TRANSMISSION_COMPLETION_FLAG(__HANDLE__)  \
  (((__HANDLE__)->AdvancedInit.TxCompletionIndication == SMARTCARD_TC) ? (SMARTCARD_FLAG_TC) :  (SMARTCARD_FLAG_TCBGT))
#else
#define SMARTCARD_TRANSMISSION_COMPLETION_FLAG(__HANDLE__)    (SMARTCARD_FLAG_TC)
#endif                          


                                                                                  
                                                                            
                                                                              
    
#if defined(USART_TCBGT_SUPPORT)
#define IS_SMARTCARD_TRANSMISSION_COMPLETION(__TXCOMPLETE__) (((__TXCOMPLETE__) == SMARTCARD_TCBGT) || \
                                                              ((__TXCOMPLETE__) == SMARTCARD_TC))
#else
#define IS_SMARTCARD_TRANSMISSION_COMPLETION(__TXCOMPLETE__) ((__TXCOMPLETE__) == SMARTCARD_TC)
#endif                          

#if defined(USART_CR1_FIFOEN)
                                                    
                                         
                                                                    
    
#define IS_SMARTCARD_FIFOMODE_STATE(__STATE__) (((__STATE__) == SMARTCARD_FIFOMODE_DISABLE ) || \
                                                ((__STATE__) == SMARTCARD_FIFOMODE_ENABLE))

                                                                 
                                                          
                                                                            
    
#define IS_SMARTCARD_TXFIFO_THRESHOLD(__THRESHOLD__) (((__THRESHOLD__) == SMARTCARD_TXFIFO_THRESHOLD_1_8) || \
                                                      ((__THRESHOLD__) == SMARTCARD_TXFIFO_THRESHOLD_1_4) || \
                                                      ((__THRESHOLD__) == SMARTCARD_TXFIFO_THRESHOLD_1_2) || \
                                                      ((__THRESHOLD__) == SMARTCARD_TXFIFO_THRESHOLD_3_4) || \
                                                      ((__THRESHOLD__) == SMARTCARD_TXFIFO_THRESHOLD_7_8) || \
                                                      ((__THRESHOLD__) == SMARTCARD_TXFIFO_THRESHOLD_8_8))

                                                                 
                                                          
                                                                            
    
#define IS_SMARTCARD_RXFIFO_THRESHOLD(__THRESHOLD__) (((__THRESHOLD__) == SMARTCARD_RXFIFO_THRESHOLD_1_8) || \
                                                      ((__THRESHOLD__) == SMARTCARD_RXFIFO_THRESHOLD_1_4) || \
                                                      ((__THRESHOLD__) == SMARTCARD_RXFIFO_THRESHOLD_1_2) || \
                                                      ((__THRESHOLD__) == SMARTCARD_RXFIFO_THRESHOLD_3_4) || \
                                                      ((__THRESHOLD__) == SMARTCARD_RXFIFO_THRESHOLD_7_8) || \
                                                      ((__THRESHOLD__) == SMARTCARD_RXFIFO_THRESHOLD_8_8))

#endif                       
   
      
    

                                                                                
                                              
      
    

                                                                                
                                                                                

                                                     
      
    

                                                                                
void              HAL_SMARTCARDEx_BlockLength_Config(SMARTCARD_HandleTypeDef *hsmartcard, uint8_t BlockLength);
void              HAL_SMARTCARDEx_TimeOut_Config(SMARTCARD_HandleTypeDef *hsmartcard, uint32_t TimeOutValue);
HAL_StatusTypeDef HAL_SMARTCARDEx_EnableReceiverTimeOut(SMARTCARD_HandleTypeDef *hsmartcard);
HAL_StatusTypeDef HAL_SMARTCARDEx_DisableReceiverTimeOut(SMARTCARD_HandleTypeDef *hsmartcard);

   
      
    

                                                                                
                                                     
      
    

                                                                                
#if defined(USART_CR1_FIFOEN)
void HAL_SMARTCARDEx_RxFifoFullCallback(SMARTCARD_HandleTypeDef *hsmartcard);
void HAL_SMARTCARDEx_TxFifoEmptyCallback(SMARTCARD_HandleTypeDef *hsmartcard);
#endif                       

   
      
    

                                                     
      
    

                                                                                
#if defined(USART_CR1_FIFOEN)
HAL_StatusTypeDef HAL_SMARTCARDEx_EnableFifoMode(SMARTCARD_HandleTypeDef *hsmartcard);
HAL_StatusTypeDef HAL_SMARTCARDEx_DisableFifoMode(SMARTCARD_HandleTypeDef *hsmartcard);
HAL_StatusTypeDef HAL_SMARTCARDEx_SetTxFifoThreshold(SMARTCARD_HandleTypeDef *hsmartcard, uint32_t Threshold);
HAL_StatusTypeDef HAL_SMARTCARDEx_SetRxFifoThreshold(SMARTCARD_HandleTypeDef *hsmartcard, uint32_t Threshold);
#endif                       

   
      
    

   
      
    

                                                                                

   
      
    

   
      
    

#ifdef __cplusplus
}
#endif

#endif                                   

