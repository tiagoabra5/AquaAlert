/**
  ******************************************************************************
  * @file    stm32l4xx_ll_lpuart.h
  * @author  MCD Application Team
  * @brief   Header file of LPUART LL module.
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

                                                                                
#ifndef STM32L4xx_LL_LPUART_H
#define STM32L4xx_LL_LPUART_H

#ifdef __cplusplus
extern "C" {
#endif

                                                                                
#include "stm32l4xx.h"

                                   
      
    

#if defined (LPUART1)

                              
      
    

                                                                                
                                                                                
#if defined(USART_PRESC_PRESCALER)
                                                                  
      
    
                                                                                                              
static const uint16_t LPUART_PRESCALER_TAB[] =
{
  (uint16_t)1,
  (uint16_t)2,
  (uint16_t)4,
  (uint16_t)6,
  (uint16_t)8,
  (uint16_t)10,
  (uint16_t)12,
  (uint16_t)16,
  (uint16_t)32,
  (uint16_t)64,
  (uint16_t)128,
  (uint16_t)256,
  (uint16_t)256,
  (uint16_t)256,
  (uint16_t)256,
  (uint16_t)256
};
   
      
    
#endif                            

                                                                                
                                                                  
      
    
                                                                                             
#define LPUART_LPUARTDIV_FREQ_MUL     256U
#define LPUART_BRR_MASK               0x000FFFFFU
#define LPUART_BRR_MIN_VALUE          0x00000300U
   
      
    


                                                                                
#if defined(USE_FULL_LL_DRIVER)
                                                            
      
    
   
      
    
#endif                       

                                                                                
#if defined(USE_FULL_LL_DRIVER)
                                                               
      
    

   
                                              
    
typedef struct
{
#if defined(USART_PRESC_PRESCALER)
  uint32_t PrescalerValue;                                                                                
                                                                                                        

                                                                                                
                                                                                    

#endif                            
  uint32_t BaudRate;                                                                                  

                                                                                                
                                                                                   

  uint32_t DataWidth;                                                                                           
                                                                                                        

                                                                                                
                                                                                    

  uint32_t StopBits;                                                                     
                                                                                                       

                                                                                                
                                                                                         

  uint32_t Parity;                                                   
                                                                                                     

                                                                                                
                                                                                 

  uint32_t TransferDirection;                                                                                        
                                                                                                        

                                                                                                
                                                                                            

  uint32_t HardwareFlowControl;                                                                                    
                                                                                                        

                                                                                                
                                                                                     

} LL_LPUART_InitTypeDef;

   
      
    
#endif                         

                                                                                
                                                                    
      
    

                                                         
                                                                              
      
    
#define LL_LPUART_ICR_PECF                 USART_ICR_PECF                                               
#define LL_LPUART_ICR_FECF                 USART_ICR_FECF                                                
#define LL_LPUART_ICR_NCF                  USART_ICR_NECF                                                       
#define LL_LPUART_ICR_ORECF                USART_ICR_ORECF                                               
#define LL_LPUART_ICR_IDLECF               USART_ICR_IDLECF                                                   
#define LL_LPUART_ICR_TCCF                 USART_ICR_TCCF                                                        
#define LL_LPUART_ICR_CTSCF                USART_ICR_CTSCF                                     
#define LL_LPUART_ICR_CMCF                 USART_ICR_CMCF                                                  
#define LL_LPUART_ICR_WUCF                 USART_ICR_WUCF                                                        
   
      
    

                                                     
                                                                             
      
    
#define LL_LPUART_ISR_PE               USART_ISR_PE                                  
#define LL_LPUART_ISR_FE               USART_ISR_FE                                   
#define LL_LPUART_ISR_NE               USART_ISR_NE                                    
#define LL_LPUART_ISR_ORE              USART_ISR_ORE                                  
#define LL_LPUART_ISR_IDLE             USART_ISR_IDLE                                      
#if defined(USART_CR1_FIFOEN)
#define LL_LPUART_ISR_RXNE_RXFNE       USART_ISR_RXNE_RXFNE                                                     
#else
#define LL_LPUART_ISR_RXNE             USART_ISR_RXNE                                                
#endif                       
#define LL_LPUART_ISR_TC               USART_ISR_TC                                           
#if defined(USART_CR1_FIFOEN)
#define LL_LPUART_ISR_TXE_TXFNF        USART_ISR_TXE_TXFNF                                                              
#else
#define LL_LPUART_ISR_TXE              USART_ISR_TXE                                                 
#endif                       
#define LL_LPUART_ISR_CTSIF            USART_ISR_CTSIF                                
#define LL_LPUART_ISR_CTS              USART_ISR_CTS                        
#define LL_LPUART_ISR_BUSY             USART_ISR_BUSY                        
#define LL_LPUART_ISR_CMF              USART_ISR_CMF                                    
#define LL_LPUART_ISR_SBKF             USART_ISR_SBKF                              
#define LL_LPUART_ISR_RWU              USART_ISR_RWU                                                   
#define LL_LPUART_ISR_WUF              USART_ISR_WUF                                          
#define LL_LPUART_ISR_TEACK            USART_ISR_TEACK                                              
#define LL_LPUART_ISR_REACK            USART_ISR_REACK                                             
#if defined(USART_CR1_FIFOEN)
#define LL_LPUART_ISR_TXFE             USART_ISR_TXFE                                 
#define LL_LPUART_ISR_RXFF             USART_ISR_RXFF                                
#define LL_LPUART_ISR_RXFT             USART_ISR_RXFT                                     
#define LL_LPUART_ISR_TXFT             USART_ISR_TXFT                                     
#endif                       
   
      
    

                                        
                                                                                                   
      
    
#define LL_LPUART_CR1_IDLEIE         USART_CR1_IDLEIE                                      
#if defined(USART_CR1_FIFOEN)
#define LL_LPUART_CR1_RXNEIE_RXFNEIE USART_CR1_RXNEIE_RXFNEIE                                             
                                                                                      
#else
#define LL_LPUART_CR1_RXNEIE         USART_CR1_RXNEIE                                                              
#endif                       
#define LL_LPUART_CR1_TCIE           USART_CR1_TCIE                                                         
#if defined(USART_CR1_FIFOEN)
#define LL_LPUART_CR1_TXEIE_TXFNFIE  USART_CR1_TXEIE_TXFNFIE                                               
                                                                                               
#else
#define LL_LPUART_CR1_TXEIE          USART_CR1_TXEIE                                                               
#endif                       
#define LL_LPUART_CR1_PEIE           USART_CR1_PEIE                               
#define LL_LPUART_CR1_CMIE           USART_CR1_CMIE                                                   
#if defined(USART_CR1_FIFOEN)
#define LL_LPUART_CR1_TXFEIE         USART_CR1_TXFEIE                                               
#define LL_LPUART_CR1_RXFFIE         USART_CR1_RXFFIE                                              
#endif                       
#define LL_LPUART_CR3_EIE            USART_CR3_EIE                                          
#define LL_LPUART_CR3_CTSIE          USART_CR3_CTSIE                                      
#define LL_LPUART_CR3_WUFIE          USART_CR3_WUFIE                                                        
#if defined(USART_CR1_FIFOEN)
#define LL_LPUART_CR3_TXFTIE         USART_CR3_TXFTIE                                                   
#define LL_LPUART_CR3_RXFTIE         USART_CR3_RXFTIE                                                   
#endif                       
   
      
    
#if defined(USART_CR1_FIFOEN)

                                                       
      
    
#define LL_LPUART_FIFOTHRESHOLD_1_8        0x00000000U                                      
#define LL_LPUART_FIFOTHRESHOLD_1_4        0x00000001U                                      
#define LL_LPUART_FIFOTHRESHOLD_1_2        0x00000002U                                      
#define LL_LPUART_FIFOTHRESHOLD_3_4        0x00000003U                                      
#define LL_LPUART_FIFOTHRESHOLD_7_8        0x00000004U                                      
#define LL_LPUART_FIFOTHRESHOLD_8_8        0x00000005U                                                  
   
      
    
#endif                       

                                              
      
    
#define LL_LPUART_DIRECTION_NONE  0x00000000U                                                                         
#define LL_LPUART_DIRECTION_RX    USART_CR1_RE                                                                        
#define LL_LPUART_DIRECTION_TX    USART_CR1_TE                                                                        
#define LL_LPUART_DIRECTION_TX_RX (USART_CR1_TE |USART_CR1_RE)                                                        
   
      
    

                                                
      
    
#define LL_LPUART_PARITY_NONE 0x00000000U                                                                              
#define LL_LPUART_PARITY_EVEN USART_CR1_PCE                                                                            
#define LL_LPUART_PARITY_ODD  (USART_CR1_PCE | USART_CR1_PS)                                                           
   
      
    

                                        
      
    
#define LL_LPUART_WAKEUP_IDLELINE    0x00000000U                                                          
#define LL_LPUART_WAKEUP_ADDRESSMARK USART_CR1_WAKE                                                       
   
      
    

                                              
      
    
#define LL_LPUART_DATAWIDTH_7B USART_CR1_M1                                                                 
#define LL_LPUART_DATAWIDTH_8B 0x00000000U                                                                  
#define LL_LPUART_DATAWIDTH_9B USART_CR1_M0                                                                 
   
      
    
#if defined(USART_PRESC_PRESCALER)

                                                           
      
    
#define LL_LPUART_PRESCALER_DIV1   0x00000000U                                                     
#define LL_LPUART_PRESCALER_DIV2   (USART_PRESC_PRESCALER_0)                                       
#define LL_LPUART_PRESCALER_DIV4   (USART_PRESC_PRESCALER_1)                                       
#define LL_LPUART_PRESCALER_DIV6   (USART_PRESC_PRESCALER_1 |\
                                    USART_PRESC_PRESCALER_0)                                       
#define LL_LPUART_PRESCALER_DIV8   (USART_PRESC_PRESCALER_2)                                       
#define LL_LPUART_PRESCALER_DIV10  (USART_PRESC_PRESCALER_2 |\
                                    USART_PRESC_PRESCALER_0)                                       
#define LL_LPUART_PRESCALER_DIV12  (USART_PRESC_PRESCALER_2 |\
                                    USART_PRESC_PRESCALER_1)                                       
#define LL_LPUART_PRESCALER_DIV16  (USART_PRESC_PRESCALER_2 |\
                                    USART_PRESC_PRESCALER_1 |\
                                    USART_PRESC_PRESCALER_0)                                       
#define LL_LPUART_PRESCALER_DIV32  (USART_PRESC_PRESCALER_3)                                       
#define LL_LPUART_PRESCALER_DIV64  (USART_PRESC_PRESCALER_3 |\
                                    USART_PRESC_PRESCALER_0)                                       
#define LL_LPUART_PRESCALER_DIV128 (USART_PRESC_PRESCALER_3 |\
                                    USART_PRESC_PRESCALER_1)                                        
#define LL_LPUART_PRESCALER_DIV256 (USART_PRESC_PRESCALER_3 |\
                                    USART_PRESC_PRESCALER_1 |\
                                    USART_PRESC_PRESCALER_0)                                        
   
      
    
#endif                            

                                             
      
    
#define LL_LPUART_STOPBITS_1         0x00000000U                               
#define LL_LPUART_STOPBITS_2         USART_CR2_STOP_1                           
   
      
    

                                               
      
    
#define LL_LPUART_TXRX_STANDARD      0x00000000U                                                                 
#define LL_LPUART_TXRX_SWAPPED       (USART_CR2_SWAP)                                                            
   
      
    

                                                                    
      
    
#define LL_LPUART_RXPIN_LEVEL_STANDARD   0x00000000U                                                                  
#define LL_LPUART_RXPIN_LEVEL_INVERTED   (USART_CR2_RXINV)                                                            
   
      
    

                                                                    
      
    
#define LL_LPUART_TXPIN_LEVEL_STANDARD  0x00000000U                                                                  
#define LL_LPUART_TXPIN_LEVEL_INVERTED  (USART_CR2_TXINV)                                                            
   
      
    

                                                             
      
    
#define LL_LPUART_BINARY_LOGIC_POSITIVE 0x00000000U                                                                 
                                                                                                                       
#define LL_LPUART_BINARY_LOGIC_NEGATIVE USART_CR2_DATAINV                                                           
                                                                                                     
                                                                                                                       
   
      
    

                                             
      
    
#define LL_LPUART_BITORDER_LSBFIRST 0x00000000U                                                                
                                                                                      
#define LL_LPUART_BITORDER_MSBFIRST USART_CR2_MSBFIRST                                                      
                                                                                      
   
      
    

                                                                  
      
    
#define LL_LPUART_ADDRESS_DETECT_4B 0x00000000U                                                    
#define LL_LPUART_ADDRESS_DETECT_7B USART_CR2_ADDM7                                                                     
   
      
    

                                                     
      
    
#define LL_LPUART_HWCONTROL_NONE    0x00000000U                                                                         
#define LL_LPUART_HWCONTROL_RTS     USART_CR3_RTSE                                                                   
                                                                                                                        
#define LL_LPUART_HWCONTROL_CTS     USART_CR3_CTSE                                                                   
                                                                                                                        
#define LL_LPUART_HWCONTROL_RTS_CTS (USART_CR3_RTSE | USART_CR3_CTSE)                                                   
   
      
    

                                                      
      
    
#define LL_LPUART_WAKEUP_ON_ADDRESS   0x00000000U                                                                 
#define LL_LPUART_WAKEUP_ON_STARTBIT  USART_CR3_WUS_1                                                                   
#define LL_LPUART_WAKEUP_ON_RXNE      (USART_CR3_WUS_0 | USART_CR3_WUS_1)                                
   
      
    

                                                             
      
    
#define LL_LPUART_DE_POLARITY_HIGH         0x00000000U                                    
#define LL_LPUART_DE_POLARITY_LOW          USART_CR3_DEP                                 
   
      
    

                                                         
      
    
#define LL_LPUART_DMA_REG_DATA_TRANSMIT    0x00000000U                                                              
#define LL_LPUART_DMA_REG_DATA_RECEIVE     0x00000001U                                                           
   
      
    

   
      
    

                                                                                
                                                              
      
    

                                                                            
      
    

   
                                            
                                        
                                          
                                                         
                
    
#define LL_LPUART_WriteReg(__INSTANCE__, __REG__, __VALUE__) WRITE_REG(__INSTANCE__->__REG__, (__VALUE__))

   
                                           
                                        
                                       
                          
    
#define LL_LPUART_ReadReg(__INSTANCE__, __REG__) READ_REG(__INSTANCE__->__REG__)
   
      
    

                                                               
      
    

   
                                                                     
                                                                      
                                                                             
                           
                                                                            
                                              
                                              
                                              
                                              
                                              
                                               
                                               
                                               
                                               
                                               
                                                
                                                
        
                                                   
                                                               
    
#if defined(USART_PRESC_PRESCALER)
#define __LL_LPUART_DIV(__PERIPHCLK__, __PRESCALER__, __BAUDRATE__) (uint32_t)\
  ((((((uint64_t)(__PERIPHCLK__)/(uint64_t)(LPUART_PRESCALER_TAB[(uint16_t)(__PRESCALER__)]))\
      * LPUART_LPUARTDIV_FREQ_MUL) + (uint32_t)((__BAUDRATE__)/2U))/(__BAUDRATE__)) & LPUART_BRR_MASK)
#else
#define __LL_LPUART_DIV(__PERIPHCLK__, __BAUDRATE__) (uint32_t)\
  (((((uint64_t)(__PERIPHCLK__)*LPUART_LPUARTDIV_FREQ_MUL) + (uint32_t)((__BAUDRATE__)/2U))/(__BAUDRATE__)) \
   & LPUART_BRR_MASK)
#endif                            

   
      
    

   
      
    

                                                                                
                                                                    
      
    

                                                                
      
    

   
                         
                                                       
                                   
                
    
__STATIC_INLINE void LL_LPUART_Enable(USART_TypeDef *LPUARTx)
{
  SET_BIT(LPUARTx->CR1, USART_CR1_UE);
}

   
                          
                                                                                           
                                                                                                             
                                                                      
                                                                                     
                                                                      
                                                                                   
                                                                               
                                                    
                                                        
                                   
                
    
__STATIC_INLINE void LL_LPUART_Disable(USART_TypeDef *LPUARTx)
{
  CLEAR_BIT(LPUARTx->CR1, USART_CR1_UE);
}

   
                                         
                                                          
                                   
                                  
    
__STATIC_INLINE uint32_t LL_LPUART_IsEnabled(const USART_TypeDef *LPUARTx)
{
  return ((READ_BIT(LPUARTx->CR1, USART_CR1_UE) == (USART_CR1_UE)) ? 1UL : 0UL);
}

#if defined(USART_CR1_FIFOEN)
   
                            
                                                           
                                   
                
    
__STATIC_INLINE void LL_LPUART_EnableFIFO(USART_TypeDef *LPUARTx)
{
  SET_BIT(LPUARTx->CR1, USART_CR1_FIFOEN);
}

   
                             
                                                            
                                   
                
    
__STATIC_INLINE void LL_LPUART_DisableFIFO(USART_TypeDef *LPUARTx)
{
  CLEAR_BIT(LPUARTx->CR1, USART_CR1_FIFOEN);
}

   
                                            
                                                              
                                   
                                  
    
__STATIC_INLINE uint32_t LL_LPUART_IsEnabledFIFO(const USART_TypeDef *LPUARTx)
{
  return ((READ_BIT(LPUARTx->CR1, USART_CR1_FIFOEN) == (USART_CR1_FIFOEN)) ? 1UL : 0UL);
}

   
                                       
                                                                   
                                   
                                                                        
                                                 
                                                 
                                                 
                                                 
                                                 
                                                 
                
    
__STATIC_INLINE void LL_LPUART_SetTXFIFOThreshold(USART_TypeDef *LPUARTx, uint32_t Threshold)
{
  ATOMIC_MODIFY_REG(LPUARTx->CR3, USART_CR3_TXFTCFG, Threshold << USART_CR3_TXFTCFG_Pos);
}

   
                                                  
                                                                   
                                   
                                                              
                                                 
                                                 
                                                 
                                                 
                                                 
                                                 
    
__STATIC_INLINE uint32_t LL_LPUART_GetTXFIFOThreshold(const USART_TypeDef *LPUARTx)
{
  return (uint32_t)(READ_BIT(LPUARTx->CR3, USART_CR3_TXFTCFG) >> USART_CR3_TXFTCFG_Pos);
}

   
                                       
                                                                   
                                   
                                                                        
                                                 
                                                 
                                                 
                                                 
                                                 
                                                 
                
    
__STATIC_INLINE void LL_LPUART_SetRXFIFOThreshold(USART_TypeDef *LPUARTx, uint32_t Threshold)
{
  ATOMIC_MODIFY_REG(LPUARTx->CR3, USART_CR3_RXFTCFG, Threshold << USART_CR3_RXFTCFG_Pos);
}

   
                                                  
                                                                   
                                   
                                                              
                                                 
                                                 
                                                 
                                                 
                                                 
                                                 
    
__STATIC_INLINE uint32_t LL_LPUART_GetRXFIFOThreshold(const USART_TypeDef *LPUARTx)
{
  return (uint32_t)(READ_BIT(LPUARTx->CR3, USART_CR3_RXFTCFG) >> USART_CR3_RXFTCFG_Pos);
}

   
                                               
                                                                       
                                                                     
                                   
                                                                          
                                                 
                                                 
                                                 
                                                 
                                                 
                                                 
                                                                          
                                                 
                                                 
                                                 
                                                 
                                                 
                                                 
                
    
__STATIC_INLINE void LL_LPUART_ConfigFIFOsThreshold(USART_TypeDef *LPUARTx, uint32_t TXThreshold, uint32_t RXThreshold)
{
  ATOMIC_MODIFY_REG(LPUARTx->CR3, USART_CR3_TXFTCFG | USART_CR3_RXFTCFG, (TXThreshold << USART_CR3_TXFTCFG_Pos) | \
                    (RXThreshold << USART_CR3_RXFTCFG_Pos));
}
#endif                       

   
                                       
                                                                                                          
                                                        
                                                                 
                                   
                
    
__STATIC_INLINE void LL_LPUART_EnableInStopMode(USART_TypeDef *LPUARTx)
{
  ATOMIC_SET_BIT(LPUARTx->CR1, USART_CR1_UESM);
}

   
                                        
                                                                                                
                                                                  
                                   
                
    
__STATIC_INLINE void LL_LPUART_DisableInStopMode(USART_TypeDef *LPUARTx)
{
  ATOMIC_CLEAR_BIT(LPUARTx->CR1, USART_CR1_UESM);
}

   
                                                      
                                                       
                                                                    
                                   
                                  
    
__STATIC_INLINE uint32_t LL_LPUART_IsEnabledInStopMode(const USART_TypeDef *LPUARTx)
{
  return ((READ_BIT(LPUARTx->CR1, USART_CR1_UESM) == (USART_CR1_UESM)) ? 1UL : 0UL);
}

#if defined(USART_CR3_UCESM)
   
                                             
                                                                                    
                                                                      
                                   
                
    
__STATIC_INLINE void LL_LPUART_EnableClockInStopMode(USART_TypeDef *LPUARTx)
{
  ATOMIC_SET_BIT(LPUARTx->CR3, USART_CR3_UCESM);
}

   
                                              
                                                                                     
                                                                       
                                   
                
    
__STATIC_INLINE void LL_LPUART_DisableClockInStopMode(USART_TypeDef *LPUARTx)
{
  ATOMIC_CLEAR_BIT(LPUARTx->CR3, USART_CR3_UCESM);
}

   
                                                            
                                                                         
                                   
                                  
    
__STATIC_INLINE uint32_t LL_LPUART_IsClockEnabledInStopMode(const USART_TypeDef *LPUARTx)
{
  return ((READ_BIT(LPUARTx->CR3, USART_CR3_UCESM) == (USART_CR3_UCESM)) ? 1UL : 0UL);
}

#endif                      
   
                                                                                      
                                                                  
                                   
                
    
__STATIC_INLINE void LL_LPUART_EnableDirectionRx(USART_TypeDef *LPUARTx)
{
  ATOMIC_SET_BIT(LPUARTx->CR1, USART_CR1_RE);
}

   
                            
                                                                   
                                   
                
    
__STATIC_INLINE void LL_LPUART_DisableDirectionRx(USART_TypeDef *LPUARTx)
{
  ATOMIC_CLEAR_BIT(LPUARTx->CR1, USART_CR1_RE);
}

   
                              
                                                                  
                                   
                
    
__STATIC_INLINE void LL_LPUART_EnableDirectionTx(USART_TypeDef *LPUARTx)
{
  ATOMIC_SET_BIT(LPUARTx->CR1, USART_CR1_TE);
}

   
                               
                                                                   
                                   
                
    
__STATIC_INLINE void LL_LPUART_DisableDirectionTx(USART_TypeDef *LPUARTx)
{
  ATOMIC_CLEAR_BIT(LPUARTx->CR1, USART_CR1_TE);
}

   
                                                            
                                       
                                                                       
                                                                     
                                   
                                                                                
                                              
                                            
                                            
                                               
                
    
__STATIC_INLINE void LL_LPUART_SetTransferDirection(USART_TypeDef *LPUARTx, uint32_t TransferDirection)
{
  ATOMIC_MODIFY_REG(LPUARTx->CR1, USART_CR1_RE | USART_CR1_TE, TransferDirection);
}

   
                                                                      
                                                                       
                                                                     
                                   
                                                              
                                              
                                            
                                            
                                               
    
__STATIC_INLINE uint32_t LL_LPUART_GetTransferDirection(const USART_TypeDef *LPUARTx)
{
  return (uint32_t)(READ_BIT(LPUARTx->CR1, USART_CR1_RE | USART_CR1_TE));
}

   
                                                                          
                                                                                                               
                                                                                                                 
                                                                                 
                                                            
                                                          
                                   
                                                                     
                                           
                                           
                                          
                
    
__STATIC_INLINE void LL_LPUART_SetParity(USART_TypeDef *LPUARTx, uint32_t Parity)
{
  MODIFY_REG(LPUARTx->CR1, USART_CR1_PS | USART_CR1_PCE, Parity);
}

   
                                                                                     
                                                            
                                                          
                                   
                                                              
                                           
                                           
                                          
    
__STATIC_INLINE uint32_t LL_LPUART_GetParity(const USART_TypeDef *LPUARTx)
{
  return (uint32_t)(READ_BIT(LPUARTx->CR1, USART_CR1_PS | USART_CR1_PCE));
}

   
                                                       
                                                                
                                   
                                                                     
                                               
                                                  
                
    
__STATIC_INLINE void LL_LPUART_SetWakeUpMethod(USART_TypeDef *LPUARTx, uint32_t Method)
{
  MODIFY_REG(LPUARTx->CR1, USART_CR1_WAKE, Method);
}

   
                                                         
                                                                
                                   
                                                              
                                               
                                                  
    
__STATIC_INLINE uint32_t LL_LPUART_GetWakeUpMethod(const USART_TypeDef *LPUARTx)
{
  return (uint32_t)(READ_BIT(LPUARTx->CR1, USART_CR1_WAKE));
}

   
                                                                            
                                                             
                                   
                                                                        
                                            
                                            
                                            
                
    
__STATIC_INLINE void LL_LPUART_SetDataWidth(USART_TypeDef *LPUARTx, uint32_t DataWidth)
{
  MODIFY_REG(LPUARTx->CR1, USART_CR1_M, DataWidth);
}

   
                                                                                    
                                                             
                                   
                                                              
                                            
                                            
                                            
    
__STATIC_INLINE uint32_t LL_LPUART_GetDataWidth(const USART_TypeDef *LPUARTx)
{
  return (uint32_t)(READ_BIT(LPUARTx->CR1, USART_CR1_M));
}

   
                                                          
                                                               
                                   
                
    
__STATIC_INLINE void LL_LPUART_EnableMuteMode(USART_TypeDef *LPUARTx)
{
  ATOMIC_SET_BIT(LPUARTx->CR1, USART_CR1_MME);
}

   
                                                                           
                                                                
                                   
                
    
__STATIC_INLINE void LL_LPUART_DisableMuteMode(USART_TypeDef *LPUARTx)
{
  ATOMIC_CLEAR_BIT(LPUARTx->CR1, USART_CR1_MME);
}

   
                                                                           
                                                                  
                                   
                                  
    
__STATIC_INLINE uint32_t LL_LPUART_IsEnabledMuteMode(const USART_TypeDef *LPUARTx)
{
  return ((READ_BIT(LPUARTx->CR1, USART_CR1_MME) == (USART_CR1_MME)) ? 1UL : 0UL);
}

#if defined(USART_PRESC_PRESCALER)
   
                                                                                    
                                                             
                                   
                                                                             
                                              
                                              
                                              
                                              
                                              
                                               
                                               
                                               
                                               
                                               
                                                
                                                
                
    
__STATIC_INLINE void LL_LPUART_SetPrescaler(USART_TypeDef *LPUARTx, uint32_t PrescalerValue)
{
  MODIFY_REG(LPUARTx->PRESC, USART_PRESC_PRESCALER, (uint16_t)PrescalerValue);
}

   
                                                                                       
                                                             
                                   
                                                              
                                              
                                              
                                              
                                              
                                              
                                               
                                               
                                               
                                               
                                               
                                                
                                                
    
__STATIC_INLINE uint32_t LL_LPUART_GetPrescaler(const USART_TypeDef *LPUARTx)
{
  return (uint32_t)(READ_BIT(LPUARTx->PRESC, USART_PRESC_PRESCALER));
}
#endif                            

   
                                           
                                                                  
                                   
                                                                       
                                          
                                          
                
    
__STATIC_INLINE void LL_LPUART_SetStopBitsLength(USART_TypeDef *LPUARTx, uint32_t StopBits)
{
  MODIFY_REG(LPUARTx->CR2, USART_CR2_STOP, StopBits);
}

   
                                                
                                                                  
                                   
                                                              
                                          
                                          
    
__STATIC_INLINE uint32_t LL_LPUART_GetStopBitsLength(const USART_TypeDef *LPUARTx)
{
  return (uint32_t)(READ_BIT(LPUARTx->CR2, USART_CR2_STOP));
}

   
                                                                                   
                                                                                     
                                                                                   
                                                                                             
                                                                                       
                                                                  
                                                                  
                                                                  
                                                                
                                   
                                                                        
                                            
                                            
                                            
                                                                     
                                           
                                           
                                          
                                                                       
                                          
                                          
                
    
__STATIC_INLINE void LL_LPUART_ConfigCharacter(USART_TypeDef *LPUARTx, uint32_t DataWidth, uint32_t Parity,
                                               uint32_t StopBits)
{
  MODIFY_REG(LPUARTx->CR1, USART_CR1_PS | USART_CR1_PCE | USART_CR1_M, Parity | DataWidth);
  MODIFY_REG(LPUARTx->CR2, USART_CR2_STOP, StopBits);
}

   
                                                  
                                                            
                                   
                                                                         
                                             
                                            
                
    
__STATIC_INLINE void LL_LPUART_SetTXRXSwap(USART_TypeDef *LPUARTx, uint32_t SwapConfig)
{
  MODIFY_REG(LPUARTx->CR2, USART_CR2_SWAP, SwapConfig);
}

   
                                                       
                                                            
                                   
                                                              
                                             
                                            
    
__STATIC_INLINE uint32_t LL_LPUART_GetTXRXSwap(const USART_TypeDef *LPUARTx)
{
  return (uint32_t)(READ_BIT(LPUARTx->CR2, USART_CR2_SWAP));
}

   
                                               
                                                              
                                   
                                                                           
                                                    
                                                    
                
    
__STATIC_INLINE void LL_LPUART_SetRXPinLevel(USART_TypeDef *LPUARTx, uint32_t PinInvMethod)
{
  MODIFY_REG(LPUARTx->CR2, USART_CR2_RXINV, PinInvMethod);
}

   
                                                            
                                                              
                                   
                                                              
                                                    
                                                    
    
__STATIC_INLINE uint32_t LL_LPUART_GetRXPinLevel(const USART_TypeDef *LPUARTx)
{
  return (uint32_t)(READ_BIT(LPUARTx->CR2, USART_CR2_RXINV));
}

   
                                               
                                                              
                                   
                                                                           
                                                    
                                                    
                
    
__STATIC_INLINE void LL_LPUART_SetTXPinLevel(USART_TypeDef *LPUARTx, uint32_t PinInvMethod)
{
  MODIFY_REG(LPUARTx->CR2, USART_CR2_TXINV, PinInvMethod);
}

   
                                                            
                                                              
                                   
                                                              
                                                    
                                                    
    
__STATIC_INLINE uint32_t LL_LPUART_GetTXPinLevel(const USART_TypeDef *LPUARTx)
{
  return (uint32_t)(READ_BIT(LPUARTx->CR2, USART_CR2_TXINV));
}

   
                                        
   
                                                                                       
                                                                                              
                                                                   
                                   
                                                                        
                                                     
                                                     
                
    
__STATIC_INLINE void LL_LPUART_SetBinaryDataLogic(USART_TypeDef *LPUARTx, uint32_t DataLogic)
{
  MODIFY_REG(LPUARTx->CR2, USART_CR2_DATAINV, DataLogic);
}

   
                                              
                                                                   
                                   
                                                              
                                                     
                                                     
    
__STATIC_INLINE uint32_t LL_LPUART_GetBinaryDataLogic(const USART_TypeDef *LPUARTx)
{
  return (uint32_t)(READ_BIT(LPUARTx->CR2, USART_CR2_DATAINV));
}

   
                                                                                    
                                                                                                     
                                                                                                        
                                                                    
                                   
                                                                       
                                                 
                                                 
                
    
__STATIC_INLINE void LL_LPUART_SetTransferBitOrder(USART_TypeDef *LPUARTx, uint32_t BitOrder)
{
  MODIFY_REG(LPUARTx->CR2, USART_CR2_MSBFIRST, BitOrder);
}

   
                                                                                 
                                                                                                     
                                                                                                        
                                                                    
                                   
                                                              
                                                 
                                                 
    
__STATIC_INLINE uint32_t LL_LPUART_GetTransferBitOrder(const USART_TypeDef *LPUARTx)
{
  return (uint32_t)(READ_BIT(LPUARTx->CR2, USART_CR2_MSBFIRST));
}

   
                                           
                                                                                       
                                                    
                                                                                         
                                      
                                                                                         
                                                                                        
                                                          
                                                                                  
                                                                                
                                                                                        
                                                                                          
                                               
                                                                    
                                                                  
                                   
                                                                         
                                                 
                                                 
                                                              
                
    
__STATIC_INLINE void LL_LPUART_ConfigNodeAddress(USART_TypeDef *LPUARTx, uint32_t AddressLen, uint32_t NodeAddress)
{
  MODIFY_REG(LPUARTx->CR2, USART_CR2_ADD | USART_CR2_ADDM7,
             (uint32_t)(AddressLen | (NodeAddress << USART_CR2_ADD_Pos)));
}

   
                                                                               
                                                            
                                                                                       
                                                            
                                                                                       
                                                               
                                   
                                                                                  
    
__STATIC_INLINE uint32_t LL_LPUART_GetNodeAddress(const USART_TypeDef *LPUARTx)
{
  return (uint32_t)(READ_BIT(LPUARTx->CR2, USART_CR2_ADD) >> USART_CR2_ADD_Pos);
}

   
                                                                                         
                                                                  
                                   
                                                              
                                                 
                                                 
    
__STATIC_INLINE uint32_t LL_LPUART_GetNodeAddressLen(const USART_TypeDef *LPUARTx)
{
  return (uint32_t)(READ_BIT(LPUARTx->CR2, USART_CR2_ADDM7));
}

   
                                      
                                                                    
                                   
                
    
__STATIC_INLINE void LL_LPUART_EnableRTSHWFlowCtrl(USART_TypeDef *LPUARTx)
{
  SET_BIT(LPUARTx->CR3, USART_CR3_RTSE);
}

   
                                       
                                                                     
                                   
                
    
__STATIC_INLINE void LL_LPUART_DisableRTSHWFlowCtrl(USART_TypeDef *LPUARTx)
{
  CLEAR_BIT(LPUARTx->CR3, USART_CR3_RTSE);
}

   
                                      
                                                                    
                                   
                
    
__STATIC_INLINE void LL_LPUART_EnableCTSHWFlowCtrl(USART_TypeDef *LPUARTx)
{
  SET_BIT(LPUARTx->CR3, USART_CR3_CTSE);
}

   
                                       
                                                                     
                                   
                
    
__STATIC_INLINE void LL_LPUART_DisableCTSHWFlowCtrl(USART_TypeDef *LPUARTx)
{
  CLEAR_BIT(LPUARTx->CR3, USART_CR3_CTSE);
}

   
                                                             
                                                                
                                                              
                                   
                                                                                  
                                              
                                             
                                             
                                                 
                
    
__STATIC_INLINE void LL_LPUART_SetHWFlowCtrl(USART_TypeDef *LPUARTx, uint32_t HardwareFlowControl)
{
  MODIFY_REG(LPUARTx->CR3, USART_CR3_RTSE | USART_CR3_CTSE, HardwareFlowControl);
}

   
                                                                   
                                                                
                                                              
                                   
                                                              
                                              
                                             
                                             
                                                 
    
__STATIC_INLINE uint32_t LL_LPUART_GetHWFlowCtrl(const USART_TypeDef *LPUARTx)
{
  return (uint32_t)(READ_BIT(LPUARTx->CR3, USART_CR3_RTSE | USART_CR3_CTSE));
}

   
                                    
                                                                    
                                   
                
    
__STATIC_INLINE void LL_LPUART_EnableOverrunDetect(USART_TypeDef *LPUARTx)
{
  CLEAR_BIT(LPUARTx->CR3, USART_CR3_OVRDIS);
}

   
                                     
                                                                     
                                   
                
    
__STATIC_INLINE void LL_LPUART_DisableOverrunDetect(USART_TypeDef *LPUARTx)
{
  SET_BIT(LPUARTx->CR3, USART_CR3_OVRDIS);
}

   
                                                    
                                                                       
                                   
                                  
    
__STATIC_INLINE uint32_t LL_LPUART_IsEnabledOverrunDetect(const USART_TypeDef *LPUARTx)
{
  return ((READ_BIT(LPUARTx->CR3, USART_CR3_OVRDIS) != USART_CR3_OVRDIS) ? 1UL : 0UL);
}

   
                                                                        
                                                            
                                   
                                                                   
                                                 
                                                  
                                              
                
    
__STATIC_INLINE void LL_LPUART_SetWKUPType(USART_TypeDef *LPUARTx, uint32_t Type)
{
  MODIFY_REG(LPUARTx->CR3, USART_CR3_WUS, Type);
}

   
                                                                        
                                                            
                                   
                                                              
                                                 
                                                  
                                              
    
__STATIC_INLINE uint32_t LL_LPUART_GetWKUPType(const USART_TypeDef *LPUARTx)
{
  return (uint32_t)(READ_BIT(LPUARTx->CR3, USART_CR3_WUS));
}

   
                                                                                 
   
                                                                              
                                                                            
                                                                                                 
                                   
                                                                                 
                                                                                       
                                                                                   
                                                            
                                   
                                      
                           
                                                                             
                                              
                                              
                                              
                                              
                                              
                                               
                                               
                                               
                                               
                                               
                                                
                                                
        
                              
                
    
#if defined(USART_PRESC_PRESCALER)
__STATIC_INLINE void LL_LPUART_SetBaudRate(USART_TypeDef *LPUARTx, uint32_t PeriphClk, uint32_t PrescalerValue,
                                           uint32_t BaudRate)
#else
__STATIC_INLINE void LL_LPUART_SetBaudRate(USART_TypeDef *LPUARTx, uint32_t PeriphClk, uint32_t BaudRate)
#endif                            
{
#if defined(USART_PRESC_PRESCALER)
  if (BaudRate != 0U)
  {
    LPUARTx->BRR = __LL_LPUART_DIV(PeriphClk, PrescalerValue, BaudRate);
  }
#else
  if (BaudRate != 0U)
  {
    LPUARTx->BRR = __LL_LPUART_DIV(PeriphClk, BaudRate);
  }
#endif                            
}

   
                                                                                          
                                                                   
                                                                                                         
                                                            
                                   
                                      
                           
                                                                             
                                              
                                              
                                              
                                              
                                              
                                               
                                               
                                               
                                               
                                               
                                                
                                                
        
                     
    
#if defined(USART_PRESC_PRESCALER)
__STATIC_INLINE uint32_t LL_LPUART_GetBaudRate(const USART_TypeDef *LPUARTx, uint32_t PeriphClk,
                                               uint32_t PrescalerValue)
#else
__STATIC_INLINE uint32_t LL_LPUART_GetBaudRate(const USART_TypeDef *LPUARTx, uint32_t PeriphClk)
#endif                            
{
  uint32_t lpuartdiv;
  uint32_t brrresult;
#if defined(USART_PRESC_PRESCALER)
  uint32_t periphclkpresc = (uint32_t)(PeriphClk / (LPUART_PRESCALER_TAB[(uint16_t)PrescalerValue]));
#endif                            

  lpuartdiv = LPUARTx->BRR & LPUART_BRR_MASK;

  if (lpuartdiv >= LPUART_BRR_MIN_VALUE)
  {
#if defined(USART_PRESC_PRESCALER)
    brrresult = (uint32_t)(((uint64_t)(periphclkpresc) * LPUART_LPUARTDIV_FREQ_MUL) / lpuartdiv);
#else
    brrresult = (uint32_t)(((uint64_t)(PeriphClk) * LPUART_LPUARTDIV_FREQ_MUL) / lpuartdiv);
#endif                            
  }
  else
  {
    brrresult = 0x0UL;
  }

  return (brrresult);
}

   
      
    

                                                                                                          
      
    

   
                                               
                                                                 
                                   
                
    
__STATIC_INLINE void LL_LPUART_EnableHalfDuplex(USART_TypeDef *LPUARTx)
{
  SET_BIT(LPUARTx->CR3, USART_CR3_HDSEL);
}

   
                                                
                                                                  
                                   
                
    
__STATIC_INLINE void LL_LPUART_DisableHalfDuplex(USART_TypeDef *LPUARTx)
{
  CLEAR_BIT(LPUARTx->CR3, USART_CR3_HDSEL);
}

   
                                                               
                                                                    
                                   
                                  
    
__STATIC_INLINE uint32_t LL_LPUART_IsEnabledHalfDuplex(const USART_TypeDef *LPUARTx)
{
  return ((READ_BIT(LPUARTx->CR3, USART_CR3_HDSEL) == (USART_CR3_HDSEL)) ? 1UL : 0UL);
}

   
      
    

                                                                                                    
      
    

   
                                                                                                    
                                                                     
                                   
                                                         
                
    
__STATIC_INLINE void LL_LPUART_SetDEDeassertionTime(USART_TypeDef *LPUARTx, uint32_t Time)
{
  MODIFY_REG(LPUARTx->CR1, USART_CR1_DEDT, Time << USART_CR1_DEDT_Pos);
}

   
                                                         
                                                                     
                                   
                                                           
    
__STATIC_INLINE uint32_t LL_LPUART_GetDEDeassertionTime(const USART_TypeDef *LPUARTx)
{
  return (uint32_t)(READ_BIT(LPUARTx->CR1, USART_CR1_DEDT) >> USART_CR1_DEDT_Pos);
}

   
                                                                                                 
                                                                   
                                   
                                                         
                
    
__STATIC_INLINE void LL_LPUART_SetDEAssertionTime(USART_TypeDef *LPUARTx, uint32_t Time)
{
  MODIFY_REG(LPUARTx->CR1, USART_CR1_DEAT, Time << USART_CR1_DEAT_Pos);
}

   
                                                      
                                                                   
                                   
                                                                                                       
    
__STATIC_INLINE uint32_t LL_LPUART_GetDEAssertionTime(const USART_TypeDef *LPUARTx)
{
  return (uint32_t)(READ_BIT(LPUARTx->CR1, USART_CR1_DEAT) >> USART_CR1_DEAT_Pos);
}

   
                                          
                                                             
                                   
                
    
__STATIC_INLINE void LL_LPUART_EnableDEMode(USART_TypeDef *LPUARTx)
{
  SET_BIT(LPUARTx->CR3, USART_CR3_DEM);
}

   
                                           
                                                              
                                   
                
    
__STATIC_INLINE void LL_LPUART_DisableDEMode(USART_TypeDef *LPUARTx)
{
  CLEAR_BIT(LPUARTx->CR3, USART_CR3_DEM);
}

   
                                                          
                                                                
                                   
                                  
    
__STATIC_INLINE uint32_t LL_LPUART_IsEnabledDEMode(const USART_TypeDef *LPUARTx)
{
  return ((READ_BIT(LPUARTx->CR3, USART_CR3_DEM) == (USART_CR3_DEM)) ? 1UL : 0UL);
}

   
                                         
                                                                    
                                   
                                                                       
                                                
                                               
                
    
__STATIC_INLINE void LL_LPUART_SetDESignalPolarity(USART_TypeDef *LPUARTx, uint32_t Polarity)
{
  MODIFY_REG(LPUARTx->CR3, USART_CR3_DEP, Polarity);
}

   
                                         
                                                                    
                                   
                                                              
                                                
                                               
    
__STATIC_INLINE uint32_t LL_LPUART_GetDESignalPolarity(const USART_TypeDef *LPUARTx)
{
  return (uint32_t)(READ_BIT(LPUARTx->CR3, USART_CR3_DEP));
}

   
      
    

                                                          
      
    

   
                                                               
                                                                
                                   
                                  
    
__STATIC_INLINE uint32_t LL_LPUART_IsActiveFlag_PE(const USART_TypeDef *LPUARTx)
{
  return ((READ_BIT(LPUARTx->ISR, USART_ISR_PE) == (USART_ISR_PE)) ? 1UL : 0UL);
}

   
                                                                
                                                                
                                   
                                  
    
__STATIC_INLINE uint32_t LL_LPUART_IsActiveFlag_FE(const USART_TypeDef *LPUARTx)
{
  return ((READ_BIT(LPUARTx->ISR, USART_ISR_FE) == (USART_ISR_FE)) ? 1UL : 0UL);
}

   
                                                                       
                                                                
                                   
                                  
    
__STATIC_INLINE uint32_t LL_LPUART_IsActiveFlag_NE(const USART_TypeDef *LPUARTx)
{
  return ((READ_BIT(LPUARTx->ISR, USART_ISR_NE) == (USART_ISR_NE)) ? 1UL : 0UL);
}

   
                                                                
                                                                 
                                   
                                  
    
__STATIC_INLINE uint32_t LL_LPUART_IsActiveFlag_ORE(const USART_TypeDef *LPUARTx)
{
  return ((READ_BIT(LPUARTx->ISR, USART_ISR_ORE) == (USART_ISR_ORE)) ? 1UL : 0UL);
}

   
                                                                     
                                                                  
                                   
                                  
    
__STATIC_INLINE uint32_t LL_LPUART_IsActiveFlag_IDLE(const USART_TypeDef *LPUARTx)
{
  return ((READ_BIT(LPUARTx->ISR, USART_ISR_IDLE) == (USART_ISR_IDLE)) ? 1UL : 0UL);
}

#if defined(USART_CR1_FIFOEN)
#define LL_LPUART_IsActiveFlag_RXNE  LL_LPUART_IsActiveFlag_RXNE_RXFNE                                      

   
                                                                                                 
                                                                        
                                   
                                  
    
__STATIC_INLINE uint32_t LL_LPUART_IsActiveFlag_RXNE_RXFNE(const USART_TypeDef *LPUARTx)
{
  return ((READ_BIT(LPUARTx->ISR, USART_ISR_RXNE_RXFNE) == (USART_ISR_RXNE_RXFNE)) ? 1UL : 0UL);
}
#else
   
                                                                               
                                                                  
                                   
                                  
    
__STATIC_INLINE uint32_t LL_LPUART_IsActiveFlag_RXNE(const USART_TypeDef *LPUARTx)
{
  return ((READ_BIT(LPUARTx->ISR, USART_ISR_RXNE) == (USART_ISR_RXNE)) ? 1UL : 0UL);
}
#endif                       

   
                                                                        
                                                                
                                   
                                  
    
__STATIC_INLINE uint32_t LL_LPUART_IsActiveFlag_TC(const USART_TypeDef *LPUARTx)
{
  return ((READ_BIT(LPUARTx->ISR, USART_ISR_TC) == (USART_ISR_TC)) ? 1UL : 0UL);
}

#if defined(USART_CR1_FIFOEN)
#define LL_LPUART_IsActiveFlag_TXE  LL_LPUART_IsActiveFlag_TXE_TXFNF                                      

   
                                                                                                          
                                                                       
                                   
                                  
    
__STATIC_INLINE uint32_t LL_LPUART_IsActiveFlag_TXE_TXFNF(const USART_TypeDef *LPUARTx)
{
  return ((READ_BIT(LPUARTx->ISR, USART_ISR_TXE_TXFNF) == (USART_ISR_TXE_TXFNF)) ? 1UL : 0UL);
}
#else
   
                                                                               
                                                                 
                                   
                                  
    
__STATIC_INLINE uint32_t LL_LPUART_IsActiveFlag_TXE(const USART_TypeDef *LPUARTx)
{
  return ((READ_BIT(LPUARTx->ISR, USART_ISR_TXE) == (USART_ISR_TXE)) ? 1UL : 0UL);
}
#endif                       

   
                                                                
                                                                  
                                   
                                  
    
__STATIC_INLINE uint32_t LL_LPUART_IsActiveFlag_nCTS(const USART_TypeDef *LPUARTx)
{
  return ((READ_BIT(LPUARTx->ISR, USART_ISR_CTSIF) == (USART_ISR_CTSIF)) ? 1UL : 0UL);
}

   
                                                      
                                                                 
                                   
                                  
    
__STATIC_INLINE uint32_t LL_LPUART_IsActiveFlag_CTS(const USART_TypeDef *LPUARTx)
{
  return ((READ_BIT(LPUARTx->ISR, USART_ISR_CTS) == (USART_ISR_CTS)) ? 1UL : 0UL);
}

   
                                                       
                                                                  
                                   
                                  
    
__STATIC_INLINE uint32_t LL_LPUART_IsActiveFlag_BUSY(const USART_TypeDef *LPUARTx)
{
  return ((READ_BIT(LPUARTx->ISR, USART_ISR_BUSY) == (USART_ISR_BUSY)) ? 1UL : 0UL);
}

   
                                                                  
                                                                
                                   
                                  
    
__STATIC_INLINE uint32_t LL_LPUART_IsActiveFlag_CM(const USART_TypeDef *LPUARTx)
{
  return ((READ_BIT(LPUARTx->ISR, USART_ISR_CMF) == (USART_ISR_CMF)) ? 1UL : 0UL);
}

   
                                                             
                                                                 
                                   
                                  
    
__STATIC_INLINE uint32_t LL_LPUART_IsActiveFlag_SBK(const USART_TypeDef *LPUARTx)
{
  return ((READ_BIT(LPUARTx->ISR, USART_ISR_SBKF) == (USART_ISR_SBKF)) ? 1UL : 0UL);
}

   
                                                                                 
                                                                 
                                   
                                  
    
__STATIC_INLINE uint32_t LL_LPUART_IsActiveFlag_RWU(const USART_TypeDef *LPUARTx)
{
  return ((READ_BIT(LPUARTx->ISR, USART_ISR_RWU) == (USART_ISR_RWU)) ? 1UL : 0UL);
}

   
                                                                         
                                                                  
                                   
                                  
    
__STATIC_INLINE uint32_t LL_LPUART_IsActiveFlag_WKUP(const USART_TypeDef *LPUARTx)
{
  return ((READ_BIT(LPUARTx->ISR, USART_ISR_WUF) == (USART_ISR_WUF)) ? 1UL : 0UL);
}

   
                                                                              
                                                                   
                                   
                                  
    
__STATIC_INLINE uint32_t LL_LPUART_IsActiveFlag_TEACK(const USART_TypeDef *LPUARTx)
{
  return ((READ_BIT(LPUARTx->ISR, USART_ISR_TEACK) == (USART_ISR_TEACK)) ? 1UL : 0UL);
}

   
                                                                             
                                                                   
                                   
                                  
    
__STATIC_INLINE uint32_t LL_LPUART_IsActiveFlag_REACK(const USART_TypeDef *LPUARTx)
{
  return ((READ_BIT(LPUARTx->ISR, USART_ISR_REACK) == (USART_ISR_REACK)) ? 1UL : 0UL);
}

#if defined(USART_CR1_FIFOEN)
   
                                                                
                                                                  
                                   
                                  
    
__STATIC_INLINE uint32_t LL_LPUART_IsActiveFlag_TXFE(const USART_TypeDef *LPUARTx)
{
  return ((READ_BIT(LPUARTx->ISR, USART_ISR_TXFE) == (USART_ISR_TXFE)) ? 1UL : 0UL);
}

   
                                                               
                                                                  
                                   
                                  
    
__STATIC_INLINE uint32_t LL_LPUART_IsActiveFlag_RXFF(const USART_TypeDef *LPUARTx)
{
  return ((READ_BIT(LPUARTx->ISR, USART_ISR_RXFF) == (USART_ISR_RXFF)) ? 1UL : 0UL);
}

   
                                                                    
                                                                  
                                   
                                  
    
__STATIC_INLINE uint32_t LL_LPUART_IsActiveFlag_TXFT(const USART_TypeDef *LPUARTx)
{
  return ((READ_BIT(LPUARTx->ISR, USART_ISR_TXFT) == (USART_ISR_TXFT)) ? 1UL : 0UL);
}

   
                                                                    
                                                                  
                                   
                                  
    
__STATIC_INLINE uint32_t LL_LPUART_IsActiveFlag_RXFT(const USART_TypeDef *LPUARTx)
{
  return ((READ_BIT(LPUARTx->ISR, USART_ISR_RXFT) == (USART_ISR_RXFT)) ? 1UL : 0UL);
}
#endif                       

   
                                   
                                                             
                                   
                
    
__STATIC_INLINE void LL_LPUART_ClearFlag_PE(USART_TypeDef *LPUARTx)
{
  WRITE_REG(LPUARTx->ICR, USART_ICR_PECF);
}

   
                                    
                                                             
                                   
                
    
__STATIC_INLINE void LL_LPUART_ClearFlag_FE(USART_TypeDef *LPUARTx)
{
  WRITE_REG(LPUARTx->ICR, USART_ICR_FECF);
}

   
                                     
                                                             
                                   
                
    
__STATIC_INLINE void LL_LPUART_ClearFlag_NE(USART_TypeDef *LPUARTx)
{
  WRITE_REG(LPUARTx->ICR, USART_ICR_NECF);
}

   
                                    
                                                              
                                   
                
    
__STATIC_INLINE void LL_LPUART_ClearFlag_ORE(USART_TypeDef *LPUARTx)
{
  WRITE_REG(LPUARTx->ICR, USART_ICR_ORECF);
}

   
                                         
                                                               
                                   
                
    
__STATIC_INLINE void LL_LPUART_ClearFlag_IDLE(USART_TypeDef *LPUARTx)
{
  WRITE_REG(LPUARTx->ICR, USART_ICR_IDLECF);
}

   
                                            
                                                             
                                   
                
    
__STATIC_INLINE void LL_LPUART_ClearFlag_TC(USART_TypeDef *LPUARTx)
{
  WRITE_REG(LPUARTx->ICR, USART_ICR_TCCF);
}

   
                                    
                                                               
                                   
                
    
__STATIC_INLINE void LL_LPUART_ClearFlag_nCTS(USART_TypeDef *LPUARTx)
{
  WRITE_REG(LPUARTx->ICR, USART_ICR_CTSCF);
}

   
                                      
                                                             
                                   
                
    
__STATIC_INLINE void LL_LPUART_ClearFlag_CM(USART_TypeDef *LPUARTx)
{
  WRITE_REG(LPUARTx->ICR, USART_ICR_CMCF);
}

   
                                             
                                                               
                                   
                
    
__STATIC_INLINE void LL_LPUART_ClearFlag_WKUP(USART_TypeDef *LPUARTx)
{
  WRITE_REG(LPUARTx->ICR, USART_ICR_WUCF);
}

   
      
    

                                                      
      
    

   
                                 
                                                              
                                   
                
    
__STATIC_INLINE void LL_LPUART_EnableIT_IDLE(USART_TypeDef *LPUARTx)
{
  ATOMIC_SET_BIT(LPUARTx->CR1, USART_CR1_IDLEIE);
}

#if defined(USART_CR1_FIFOEN)
#define LL_LPUART_EnableIT_RXNE  LL_LPUART_EnableIT_RXNE_RXFNE                                      

   
                                                               
                                                                    
                                   
                
    
__STATIC_INLINE void LL_LPUART_EnableIT_RXNE_RXFNE(USART_TypeDef *LPUARTx)
{
  ATOMIC_SET_BIT(LPUARTx->CR1, USART_CR1_RXNEIE_RXFNEIE);
}
#else

   
                                         
                                                              
                                   
                
    
__STATIC_INLINE void LL_LPUART_EnableIT_RXNE(USART_TypeDef *LPUARTx)
{
  ATOMIC_SET_BIT(LPUARTx->CR1, USART_CR1_RXNEIE);
}
#endif                       

   
                                                  
                                                            
                                   
                
    
__STATIC_INLINE void LL_LPUART_EnableIT_TC(USART_TypeDef *LPUARTx)
{
  ATOMIC_SET_BIT(LPUARTx->CR1, USART_CR1_TCIE);
}

#if defined(USART_CR1_FIFOEN)
#define LL_LPUART_EnableIT_TXE  LL_LPUART_EnableIT_TXE_TXFNF                                      

   
                                                          
                                                                   
                                   
                
    
__STATIC_INLINE void LL_LPUART_EnableIT_TXE_TXFNF(USART_TypeDef *LPUARTx)
{
  ATOMIC_SET_BIT(LPUARTx->CR1, USART_CR1_TXEIE_TXFNFIE);
}
#else

   
                                     
                                                             
                                   
                
    
__STATIC_INLINE void LL_LPUART_EnableIT_TXE(USART_TypeDef *LPUARTx)
{
  ATOMIC_SET_BIT(LPUARTx->CR1, USART_CR1_TXEIE);
}
#endif                       

   
                                         
                                                            
                                   
                
    
__STATIC_INLINE void LL_LPUART_EnableIT_PE(USART_TypeDef *LPUARTx)
{
  ATOMIC_SET_BIT(LPUARTx->CR1, USART_CR1_PEIE);
}

   
                                            
                                                            
                                   
                
    
__STATIC_INLINE void LL_LPUART_EnableIT_CM(USART_TypeDef *LPUARTx)
{
  ATOMIC_SET_BIT(LPUARTx->CR1, USART_CR1_CMIE);
}

#if defined(USART_CR1_FIFOEN)
   
                                          
                                                              
                                   
                
    
__STATIC_INLINE void LL_LPUART_EnableIT_TXFE(USART_TypeDef *LPUARTx)
{
  ATOMIC_SET_BIT(LPUARTx->CR1, USART_CR1_TXFEIE);
}

   
                                         
                                                              
                                   
                
    
__STATIC_INLINE void LL_LPUART_EnableIT_RXFF(USART_TypeDef *LPUARTx)
{
  ATOMIC_SET_BIT(LPUARTx->CR1, USART_CR1_RXFFIE);
}
#endif                       

   
                                  
                                                                                                      
                                                                                                   
                                       
                                                                                                  
                                                               
                                   
                
    
__STATIC_INLINE void LL_LPUART_EnableIT_ERROR(USART_TypeDef *LPUARTx)
{
  ATOMIC_SET_BIT(LPUARTx->CR3, USART_CR3_EIE);
}

   
                                
                                                             
                                   
                
    
__STATIC_INLINE void LL_LPUART_EnableIT_CTS(USART_TypeDef *LPUARTx)
{
  ATOMIC_SET_BIT(LPUARTx->CR3, USART_CR3_CTSIE);
}

   
                                                   
                                                              
                                   
                
    
__STATIC_INLINE void LL_LPUART_EnableIT_WKUP(USART_TypeDef *LPUARTx)
{
  ATOMIC_SET_BIT(LPUARTx->CR3, USART_CR3_WUFIE);
}

#if defined(USART_CR1_FIFOEN)
   
                                              
                                                              
                                   
                
    
__STATIC_INLINE void LL_LPUART_EnableIT_TXFT(USART_TypeDef *LPUARTx)
{
  ATOMIC_SET_BIT(LPUARTx->CR3, USART_CR3_TXFTIE);
}

   
                                              
                                                              
                                   
                
    
__STATIC_INLINE void LL_LPUART_EnableIT_RXFT(USART_TypeDef *LPUARTx)
{
  ATOMIC_SET_BIT(LPUARTx->CR3, USART_CR3_RXFTIE);
}
#endif                       

   
                                  
                                                               
                                   
                
    
__STATIC_INLINE void LL_LPUART_DisableIT_IDLE(USART_TypeDef *LPUARTx)
{
  ATOMIC_CLEAR_BIT(LPUARTx->CR1, USART_CR1_IDLEIE);
}

#if defined(USART_CR1_FIFOEN)
#define LL_LPUART_DisableIT_RXNE  LL_LPUART_DisableIT_RXNE_RXFNE                                      

   
                                                                
                                                                     
                                   
                
    
__STATIC_INLINE void LL_LPUART_DisableIT_RXNE_RXFNE(USART_TypeDef *LPUARTx)
{
  ATOMIC_CLEAR_BIT(LPUARTx->CR1, USART_CR1_RXNEIE_RXFNEIE);
}
#else

   
                                          
                                                               
                                   
                
    
__STATIC_INLINE void LL_LPUART_DisableIT_RXNE(USART_TypeDef *LPUARTx)
{
  ATOMIC_CLEAR_BIT(LPUARTx->CR1, USART_CR1_RXNEIE);
}
#endif                       

   
                                                   
                                                             
                                   
                
    
__STATIC_INLINE void LL_LPUART_DisableIT_TC(USART_TypeDef *LPUARTx)
{
  ATOMIC_CLEAR_BIT(LPUARTx->CR1, USART_CR1_TCIE);
}

#if defined(USART_CR1_FIFOEN)
#define LL_LPUART_DisableIT_TXE  LL_LPUART_DisableIT_TXE_TXFNF                                      

   
                                                           
                                                                   
                                   
                
    
__STATIC_INLINE void LL_LPUART_DisableIT_TXE_TXFNF(USART_TypeDef *LPUARTx)
{
  ATOMIC_CLEAR_BIT(LPUARTx->CR1, USART_CR1_TXEIE_TXFNFIE);
}
#else

   
                                      
                                                              
                                   
                
    
__STATIC_INLINE void LL_LPUART_DisableIT_TXE(USART_TypeDef *LPUARTx)
{
  ATOMIC_CLEAR_BIT(LPUARTx->CR1, USART_CR1_TXEIE);
}
#endif                       

   
                                          
                                                             
                                   
                
    
__STATIC_INLINE void LL_LPUART_DisableIT_PE(USART_TypeDef *LPUARTx)
{
  ATOMIC_CLEAR_BIT(LPUARTx->CR1, USART_CR1_PEIE);
}

   
                                             
                                                             
                                   
                
    
__STATIC_INLINE void LL_LPUART_DisableIT_CM(USART_TypeDef *LPUARTx)
{
  ATOMIC_CLEAR_BIT(LPUARTx->CR1, USART_CR1_CMIE);
}

#if defined(USART_CR1_FIFOEN)
   
                                           
                                                               
                                   
                
    
__STATIC_INLINE void LL_LPUART_DisableIT_TXFE(USART_TypeDef *LPUARTx)
{
  ATOMIC_CLEAR_BIT(LPUARTx->CR1, USART_CR1_TXFEIE);
}

   
                                          
                                                               
                                   
                
    
__STATIC_INLINE void LL_LPUART_DisableIT_RXFF(USART_TypeDef *LPUARTx)
{
  ATOMIC_CLEAR_BIT(LPUARTx->CR1, USART_CR1_RXFFIE);
}
#endif                       

   
                                   
                                                                                                      
                                                                                                   
                                       
                                                                                                  
                                                                
                                   
                
    
__STATIC_INLINE void LL_LPUART_DisableIT_ERROR(USART_TypeDef *LPUARTx)
{
  ATOMIC_CLEAR_BIT(LPUARTx->CR3, USART_CR3_EIE);
}

   
                                 
                                                              
                                   
                
    
__STATIC_INLINE void LL_LPUART_DisableIT_CTS(USART_TypeDef *LPUARTx)
{
  ATOMIC_CLEAR_BIT(LPUARTx->CR3, USART_CR3_CTSIE);
}

   
                                                    
                                                               
                                   
                
    
__STATIC_INLINE void LL_LPUART_DisableIT_WKUP(USART_TypeDef *LPUARTx)
{
  ATOMIC_CLEAR_BIT(LPUARTx->CR3, USART_CR3_WUFIE);
}

#if defined(USART_CR1_FIFOEN)
   
                                               
                                                               
                                   
                
    
__STATIC_INLINE void LL_LPUART_DisableIT_TXFT(USART_TypeDef *LPUARTx)
{
  ATOMIC_CLEAR_BIT(LPUARTx->CR3, USART_CR3_TXFTIE);
}

   
                                               
                                                               
                                   
                
    
__STATIC_INLINE void LL_LPUART_DisableIT_RXFT(USART_TypeDef *LPUARTx)
{
  ATOMIC_CLEAR_BIT(LPUARTx->CR3, USART_CR3_RXFTIE);
}
#endif                       

   
                                                                              
                                                                 
                                   
                                  
    
__STATIC_INLINE uint32_t LL_LPUART_IsEnabledIT_IDLE(const USART_TypeDef *LPUARTx)
{
  return ((READ_BIT(LPUARTx->CR1, USART_CR1_IDLEIE) == (USART_CR1_IDLEIE)) ? 1UL : 0UL);
}

#if defined(USART_CR1_FIFOEN)
#define LL_LPUART_IsEnabledIT_RXNE  LL_LPUART_IsEnabledIT_RXNE_RXFNE                                      

   
                                                                                                           
                                                                       
                                   
                                  
    
__STATIC_INLINE uint32_t LL_LPUART_IsEnabledIT_RXNE_RXFNE(const USART_TypeDef *LPUARTx)
{
  return ((READ_BIT(LPUARTx->CR1, USART_CR1_RXNEIE_RXFNEIE) == (USART_CR1_RXNEIE_RXFNEIE)) ? 1UL : 0UL);
}
#else

   
                                                                              
                                                                 
                                   
                                  
    
__STATIC_INLINE uint32_t LL_LPUART_IsEnabledIT_RXNE(const USART_TypeDef *LPUARTx)
{
  return ((READ_BIT(LPUARTx->CR1, USART_CR1_RXNEIE) == (USART_CR1_RXNEIE)) ? 1UL : 0UL);
}
#endif                       

   
                                                                                       
                                                               
                                   
                                  
    
__STATIC_INLINE uint32_t LL_LPUART_IsEnabledIT_TC(const USART_TypeDef *LPUARTx)
{
  return ((READ_BIT(LPUARTx->CR1, USART_CR1_TCIE) == (USART_CR1_TCIE)) ? 1UL : 0UL);
}

#if defined(USART_CR1_FIFOEN)
#define LL_LPUART_IsEnabledIT_TXE  LL_LPUART_IsEnabledIT_TXE_TXFNF                                      

   
                                                                                                     
                                                                      
                                   
                                  
    
__STATIC_INLINE uint32_t LL_LPUART_IsEnabledIT_TXE_TXFNF(const USART_TypeDef *LPUARTx)
{
  return ((READ_BIT(LPUARTx->CR1, USART_CR1_TXEIE_TXFNFIE) == (USART_CR1_TXEIE_TXFNFIE)) ? 1UL : 0UL);
}
#else

   
                                                                          
                                                                
                                   
                                  
    
__STATIC_INLINE uint32_t LL_LPUART_IsEnabledIT_TXE(const USART_TypeDef *LPUARTx)
{
  return ((READ_BIT(LPUARTx->CR1, USART_CR1_TXEIE) == (USART_CR1_TXEIE)) ? 1UL : 0UL);
}
#endif                       

   
                                                                              
                                                               
                                   
                                  
    
__STATIC_INLINE uint32_t LL_LPUART_IsEnabledIT_PE(const USART_TypeDef *LPUARTx)
{
  return ((READ_BIT(LPUARTx->CR1, USART_CR1_PEIE) == (USART_CR1_PEIE)) ? 1UL : 0UL);
}

   
                                                                                 
                                                               
                                   
                                  
    
__STATIC_INLINE uint32_t LL_LPUART_IsEnabledIT_CM(const USART_TypeDef *LPUARTx)
{
  return ((READ_BIT(LPUARTx->CR1, USART_CR1_CMIE) == (USART_CR1_CMIE)) ? 1UL : 0UL);
}

#if defined(USART_CR1_FIFOEN)
   
                                                                              
                                                                 
                                   
                                  
    
__STATIC_INLINE uint32_t LL_LPUART_IsEnabledIT_TXFE(const USART_TypeDef *LPUARTx)
{
  return ((READ_BIT(LPUARTx->CR1, USART_CR1_TXFEIE) == (USART_CR1_TXFEIE)) ? 1UL : 0UL);
}

   
                                                                             
                                                                 
                                   
                                  
    
__STATIC_INLINE uint32_t LL_LPUART_IsEnabledIT_RXFF(const USART_TypeDef *LPUARTx)
{
  return ((READ_BIT(LPUARTx->CR1, USART_CR1_RXFFIE) == (USART_CR1_RXFFIE)) ? 1UL : 0UL);
}
#endif                       

   
                                                                       
                                                                  
                                   
                                  
    
__STATIC_INLINE uint32_t LL_LPUART_IsEnabledIT_ERROR(const USART_TypeDef *LPUARTx)
{
  return ((READ_BIT(LPUARTx->CR3, USART_CR3_EIE) == (USART_CR3_EIE)) ? 1UL : 0UL);
}

   
                                                                     
                                                                
                                   
                                  
    
__STATIC_INLINE uint32_t LL_LPUART_IsEnabledIT_CTS(const USART_TypeDef *LPUARTx)
{
  return ((READ_BIT(LPUARTx->CR3, USART_CR3_CTSIE) == (USART_CR3_CTSIE)) ? 1UL : 0UL);
}

   
                                                                                        
                                                                 
                                   
                                  
    
__STATIC_INLINE uint32_t LL_LPUART_IsEnabledIT_WKUP(const USART_TypeDef *LPUARTx)
{
  return ((READ_BIT(LPUARTx->CR3, USART_CR3_WUFIE) == (USART_CR3_WUFIE)) ? 1UL : 0UL);
}

#if defined(USART_CR1_FIFOEN)
   
                                                                              
                                                                 
                                   
                                  
    
__STATIC_INLINE uint32_t LL_LPUART_IsEnabledIT_TXFT(const USART_TypeDef *LPUARTx)
{
  return ((READ_BIT(LPUARTx->CR3, USART_CR3_TXFTIE) == (USART_CR3_TXFTIE)) ? 1UL : 0UL);
}

   
                                                                              
                                                                 
                                   
                                  
    
__STATIC_INLINE uint32_t LL_LPUART_IsEnabledIT_RXFT(const USART_TypeDef *LPUARTx)
{
  return ((READ_BIT(LPUARTx->CR3, USART_CR3_RXFTIE) == (USART_CR3_RXFTIE)) ? 1UL : 0UL);
}
#endif                       

   
      
    

                                                        
      
    

   
                                         
                                                                
                                   
                
    
__STATIC_INLINE void LL_LPUART_EnableDMAReq_RX(USART_TypeDef *LPUARTx)
{
  ATOMIC_SET_BIT(LPUARTx->CR3, USART_CR3_DMAR);
}

   
                                          
                                                                 
                                   
                
    
__STATIC_INLINE void LL_LPUART_DisableDMAReq_RX(USART_TypeDef *LPUARTx)
{
  ATOMIC_CLEAR_BIT(LPUARTx->CR3, USART_CR3_DMAR);
}

   
                                                      
                                                                   
                                   
                                  
    
__STATIC_INLINE uint32_t LL_LPUART_IsEnabledDMAReq_RX(const USART_TypeDef *LPUARTx)
{
  return ((READ_BIT(LPUARTx->CR3, USART_CR3_DMAR) == (USART_CR3_DMAR)) ? 1UL : 0UL);
}

   
                                            
                                                                
                                   
                
    
__STATIC_INLINE void LL_LPUART_EnableDMAReq_TX(USART_TypeDef *LPUARTx)
{
  ATOMIC_SET_BIT(LPUARTx->CR3, USART_CR3_DMAT);
}

   
                                             
                                                                 
                                   
                
    
__STATIC_INLINE void LL_LPUART_DisableDMAReq_TX(USART_TypeDef *LPUARTx)
{
  ATOMIC_CLEAR_BIT(LPUARTx->CR3, USART_CR3_DMAT);
}

   
                                                         
                                                                   
                                   
                                  
    
__STATIC_INLINE uint32_t LL_LPUART_IsEnabledDMAReq_TX(const USART_TypeDef *LPUARTx)
{
  return ((READ_BIT(LPUARTx->CR3, USART_CR3_DMAT) == (USART_CR3_DMAT)) ? 1UL : 0UL);
}

   
                                                   
                                                                      
                                   
                
    
__STATIC_INLINE void LL_LPUART_EnableDMADeactOnRxErr(USART_TypeDef *LPUARTx)
{
  SET_BIT(LPUARTx->CR3, USART_CR3_DDRE);
}

   
                                                    
                                                                       
                                   
                
    
__STATIC_INLINE void LL_LPUART_DisableDMADeactOnRxErr(USART_TypeDef *LPUARTx)
{
  CLEAR_BIT(LPUARTx->CR3, USART_CR3_DDRE);
}

   
                                                                    
                                                                         
                                   
                                  
    
__STATIC_INLINE uint32_t LL_LPUART_IsEnabledDMADeactOnRxErr(const USART_TypeDef *LPUARTx)
{
  return ((READ_BIT(LPUARTx->CR3, USART_CR3_DDRE) == (USART_CR3_DDRE)) ? 1UL : 0UL);
}

   
                                                                      
                                                                 
                                                               
                                   
                                                                        
                                                     
                                                    
                                    
    
__STATIC_INLINE uint32_t LL_LPUART_DMA_GetRegAddr(const USART_TypeDef *LPUARTx, uint32_t Direction)
{
  uint32_t data_reg_addr;

  if (Direction == LL_LPUART_DMA_REG_DATA_TRANSMIT)
  {
                                        
    data_reg_addr = (uint32_t) &(LPUARTx->TDR);
  }
  else
  {
                                        
    data_reg_addr = (uint32_t) &(LPUARTx->RDR);
  }

  return data_reg_addr;
}

   
      
    

                                                          
      
    

   
                                                                    
                                                             
                                   
                                                              
    
__STATIC_INLINE uint8_t LL_LPUART_ReceiveData8(const USART_TypeDef *LPUARTx)
{
  return (uint8_t)(READ_BIT(LPUARTx->RDR, USART_RDR_RDR) & 0xFFU);
}

   
                                                                    
                                                             
                                   
                                                               
    
__STATIC_INLINE uint16_t LL_LPUART_ReceiveData9(const USART_TypeDef *LPUARTx)
{
  return (uint16_t)(READ_BIT(LPUARTx->RDR, USART_RDR_RDR));
}

   
                                                                            
                                                              
                                   
                                                         
                
    
__STATIC_INLINE void LL_LPUART_TransmitData8(USART_TypeDef *LPUARTx, uint8_t Value)
{
  LPUARTx->TDR = Value;
}

   
                                                                            
                                                              
                                   
                                                          
                
    
__STATIC_INLINE void LL_LPUART_TransmitData9(USART_TypeDef *LPUARTx, uint16_t Value)
{
  LPUARTx->TDR = Value & 0x1FFUL;
}

   
      
    

                                              
      
    

   
                                 
                                                                    
                                   
                
    
__STATIC_INLINE void LL_LPUART_RequestBreakSending(USART_TypeDef *LPUARTx)
{
  SET_BIT(LPUARTx->RQR, (uint16_t)USART_RQR_SBKRQ);
}

   
                                                        
                                                                     
                                   
                
    
__STATIC_INLINE void LL_LPUART_RequestEnterMuteMode(USART_TypeDef *LPUARTx)
{
  SET_BIT(LPUARTx->RQR, (uint16_t)USART_RQR_MMRQ);
}

   
                      
                                                 
                                                                                          
                      
       
                                        
        
                                                                   
                                   
                
    
__STATIC_INLINE void LL_LPUART_RequestRxDataFlush(USART_TypeDef *LPUARTx)
{
  SET_BIT(LPUARTx->RQR, (uint16_t)USART_RQR_RXFRQ);
}

#if defined(USART_CR1_FIFOEN)
   
                                              
                                                                                    
                                                                                  
                                                                                   
                                                                  
                                                                   
                                   
                
    
__STATIC_INLINE void LL_LPUART_RequestTxDataFlush(USART_TypeDef *LPUARTx)
{
  SET_BIT(LPUARTx->RQR, (uint16_t)USART_RQR_TXFRQ);
}

#endif                       
   
      
    

#if defined(USE_FULL_LL_DRIVER)
                                                                              
      
    
ErrorStatus LL_LPUART_DeInit(const USART_TypeDef *LPUARTx);
ErrorStatus LL_LPUART_Init(USART_TypeDef *LPUARTx, const LL_LPUART_InitTypeDef *LPUART_InitStruct);
void        LL_LPUART_StructInit(LL_LPUART_InitTypeDef *LPUART_InitStruct);
   
      
    
#endif                         

   
      
    

   
      
    

#endif              

   
      
    

#ifdef __cplusplus
}
#endif

#endif                            

