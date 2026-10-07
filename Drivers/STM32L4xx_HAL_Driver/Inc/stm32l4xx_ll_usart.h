/**
  ******************************************************************************
  * @file    stm32l4xx_ll_usart.h
  * @author  MCD Application Team
  * @brief   Header file of USART LL module.
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

                                                                                
#ifndef STM32L4xx_LL_USART_H
#define STM32L4xx_LL_USART_H

#ifdef __cplusplus
extern "C" {
#endif

                                                                                
#include "stm32l4xx.h"

                                   
      
    

#if defined(USART1) || defined(USART2) || defined(USART3) || defined(UART4) || defined(UART5)

                            
      
    

                                                                                
                                                                                
#if defined(USART_PRESC_PRESCALER)
                                                                
      
    
                                                                                                            
static const uint32_t USART_PRESCALER_TAB[] =
{
  1UL,
  2UL,
  4UL,
  6UL,
  8UL,
  10UL,
  12UL,
  16UL,
  32UL,
  64UL,
  128UL,
  256UL,
  256UL,
  256UL,
  256UL,
  256UL
};
   
      
    
#endif                            

                                                                                
                                                                
      
    
   
      
    
                                                                                
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
                                                                                                       

                                                                                                
                                                                                    

  uint32_t OverSampling;                                                                        
                                                                                                          

                                                                                                
                                                                                      

} LL_USART_InitTypeDef;

   
                                                   
    
typedef struct
{
  uint32_t ClockOutput;                                                                             
                                                                                                   

                                                                                                                    
                                                                                                                 
                                                                                                      

  uint32_t ClockPolarity;                                                                 
                                                                                                      

                                                                                                          
                                                                                      
                                                                                                      

  uint32_t ClockPhase;                                                                                     
                                                                                                   

                                                                                                          
                                                                                   
                                                                                                      

  uint32_t LastBitClockPulse;                                                                                     
                                                                                                               
                                                                                                          

                                                                                                          
                                                                                           
                                                                                                      

} LL_USART_ClockInitTypeDef;

   
      
    
#endif                         

                                                                                
                                                                  
      
    

                                                        
                                                                             
      
    
#define LL_USART_ICR_PECF                       USART_ICR_PECF                                               
#define LL_USART_ICR_FECF                       USART_ICR_FECF                                                
#define LL_USART_ICR_NECF                       USART_ICR_NECF                                                       
#define LL_USART_ICR_ORECF                      USART_ICR_ORECF                                               
#define LL_USART_ICR_IDLECF                     USART_ICR_IDLECF                                                   
#if defined(USART_CR1_FIFOEN)
#define LL_USART_ICR_TXFECF                     USART_ICR_TXFECF                                              
#endif                       
#define LL_USART_ICR_TCCF                       USART_ICR_TCCF                                                        
#if defined(USART_TCBGT_SUPPORT)
#define LL_USART_ICR_TCBGTCF                    USART_ICR_TCBGTCF                                                                        
#endif                          
#define LL_USART_ICR_LBDCF                      USART_ICR_LBDCF                                                     
#define LL_USART_ICR_CTSCF                      USART_ICR_CTSCF                                     
#define LL_USART_ICR_RTOCF                      USART_ICR_RTOCF                                                  
#define LL_USART_ICR_EOBCF                      USART_ICR_EOBCF                                              
#if defined(USART_CR2_SLVEN)
#define LL_USART_ICR_UDRCF                      USART_ICR_UDRCF                                                    
#endif                      
#define LL_USART_ICR_CMCF                       USART_ICR_CMCF                                                  
#define LL_USART_ICR_WUCF                       USART_ICR_WUCF                                                        
   
      
    

                                                    
                                                                            
      
    
#define LL_USART_ISR_PE                         USART_ISR_PE                                           
#define LL_USART_ISR_FE                         USART_ISR_FE                                            
#define LL_USART_ISR_NE                         USART_ISR_NE                                             
#define LL_USART_ISR_ORE                        USART_ISR_ORE                                           
#define LL_USART_ISR_IDLE                       USART_ISR_IDLE                                               
#if defined(USART_CR1_FIFOEN)
#define LL_USART_ISR_RXNE_RXFNE                 USART_ISR_RXNE_RXFNE                                                              
#else
#define LL_USART_ISR_RXNE                       USART_ISR_RXNE                                                         
#endif                       
#define LL_USART_ISR_TC                         USART_ISR_TC                                                    
#if defined(USART_CR1_FIFOEN)
#define LL_USART_ISR_TXE_TXFNF                  USART_ISR_TXE_TXFNF                                                                       
#else
#define LL_USART_ISR_TXE                        USART_ISR_TXE                                                          
#endif                       
#define LL_USART_ISR_LBDF                       USART_ISR_LBDF                                                
#define LL_USART_ISR_CTSIF                      USART_ISR_CTSIF                                         
#define LL_USART_ISR_CTS                        USART_ISR_CTS                                 
#define LL_USART_ISR_RTOF                       USART_ISR_RTOF                                             
#define LL_USART_ISR_EOBF                       USART_ISR_EOBF                                         
#if defined(USART_CR2_SLVEN)
#define LL_USART_ISR_UDR                        USART_ISR_UDR                                                      
#endif                      
#define LL_USART_ISR_ABRE                       USART_ISR_ABRE                                                 
#define LL_USART_ISR_ABRF                       USART_ISR_ABRF                                           
#define LL_USART_ISR_BUSY                       USART_ISR_BUSY                                 
#define LL_USART_ISR_CMF                        USART_ISR_CMF                                             
#define LL_USART_ISR_SBKF                       USART_ISR_SBKF                                       
#define LL_USART_ISR_RWU                        USART_ISR_RWU                                                            
#define LL_USART_ISR_WUF                        USART_ISR_WUF                                                   
#define LL_USART_ISR_TEACK                      USART_ISR_TEACK                                                       
#define LL_USART_ISR_REACK                      USART_ISR_REACK                                                      
#if defined(USART_CR1_FIFOEN)
#define LL_USART_ISR_TXFE                       USART_ISR_TXFE                                          
#define LL_USART_ISR_RXFF                       USART_ISR_RXFF                                         
#endif                       
#if defined(USART_TCBGT_SUPPORT)
#define LL_USART_ISR_TCBGT                      USART_ISR_TCBGT                                                                              
#endif                          
#if defined(USART_CR1_FIFOEN)
#define LL_USART_ISR_RXFT                       USART_ISR_RXFT                                              
#define LL_USART_ISR_TXFT                       USART_ISR_TXFT                                              
#endif                       
   
      
    

                                       
                                                                                                 
      
    
#define LL_USART_CR1_IDLEIE                     USART_CR1_IDLEIE                                           
#if defined(USART_CR1_FIFOEN)
#define LL_USART_CR1_RXNEIE_RXFNEIE             USART_CR1_RXNEIE_RXFNEIE                                                                      
#else
#define LL_USART_CR1_RXNEIE                     USART_CR1_RXNEIE                                                                   
#endif                       
#define LL_USART_CR1_TCIE                       USART_CR1_TCIE                                                              
#if defined(USART_CR1_FIFOEN)
#define LL_USART_CR1_TXEIE_TXFNFIE              USART_CR1_TXEIE_TXFNFIE                                                                                 
#else
#define LL_USART_CR1_TXEIE                      USART_CR1_TXEIE                                                                    
#endif                       
#define LL_USART_CR1_PEIE                       USART_CR1_PEIE                                    
#define LL_USART_CR1_CMIE                       USART_CR1_CMIE                                                        
#define LL_USART_CR1_RTOIE                      USART_CR1_RTOIE                                                        
#define LL_USART_CR1_EOBIE                      USART_CR1_EOBIE                                                    
#if defined(USART_CR1_FIFOEN)
#define LL_USART_CR1_TXFEIE                     USART_CR1_TXFEIE                                                    
#define LL_USART_CR1_RXFFIE                     USART_CR1_RXFFIE                                                   
#endif                       
#define LL_USART_CR2_LBDIE                      USART_CR2_LBDIE                                                           
#define LL_USART_CR3_EIE                        USART_CR3_EIE                                               
#define LL_USART_CR3_CTSIE                      USART_CR3_CTSIE                                           
#define LL_USART_CR3_WUFIE                      USART_CR3_WUFIE                                                             
#if defined(USART_CR1_FIFOEN)
#define LL_USART_CR3_TXFTIE                     USART_CR3_TXFTIE                                                        
#endif                       
#if defined(USART_TCBGT_SUPPORT)
#define LL_USART_CR3_TCBGTIE                    USART_CR3_TCBGTIE                                                                             
#endif                          
#if defined(USART_CR1_FIFOEN)
#define LL_USART_CR3_RXFTIE                     USART_CR3_RXFTIE                                                        
#endif                       
   
      
    

#if defined(USART_CR1_FIFOEN)
                                                      
      
    
#define LL_USART_FIFOTHRESHOLD_1_8              0x00000000U                                      
#define LL_USART_FIFOTHRESHOLD_1_4              0x00000001U                                      
#define LL_USART_FIFOTHRESHOLD_1_2              0x00000002U                                      
#define LL_USART_FIFOTHRESHOLD_3_4              0x00000003U                                      
#define LL_USART_FIFOTHRESHOLD_7_8              0x00000004U                                      
#define LL_USART_FIFOTHRESHOLD_8_8              0x00000005U                                                  
   
      
    

#endif                       
                                                           
      
    
#define LL_USART_DIRECTION_NONE                 0x00000000U                                                                     
#define LL_USART_DIRECTION_RX                   USART_CR1_RE                                                                              
#define LL_USART_DIRECTION_TX                   USART_CR1_TE                                                                              
#define LL_USART_DIRECTION_TX_RX                (USART_CR1_TE |USART_CR1_RE)                                                   
   
      
    

                                               
      
    
#define LL_USART_PARITY_NONE                    0x00000000U                                                         
#define LL_USART_PARITY_EVEN                    USART_CR1_PCE                                                                                  
#define LL_USART_PARITY_ODD                     (USART_CR1_PCE | USART_CR1_PS)                                                                
   
      
    

                                       
      
    
#define LL_USART_WAKEUP_IDLELINE                0x00000000U                                                             
#define LL_USART_WAKEUP_ADDRESSMARK             USART_CR1_WAKE                                                             
   
      
    

                                             
      
    
#define LL_USART_DATAWIDTH_7B                   USART_CR1_M1                                                                            
#define LL_USART_DATAWIDTH_8B                   0x00000000U                                                                             
#define LL_USART_DATAWIDTH_9B                   USART_CR1_M0                                                                            
   
      
    

                                                   
      
    
#define LL_USART_OVERSAMPLING_16                0x00000000U                                      
#define LL_USART_OVERSAMPLING_8                 USART_CR1_OVER8                                 
   
      
    

#if defined(USE_FULL_LL_DRIVER)
                                            
      
    

#define LL_USART_CLOCK_DISABLE                  0x00000000U                                             
#define LL_USART_CLOCK_ENABLE                   USART_CR2_CLKEN                                     
   
      
    
#endif                       

                                                       
      
    
#define LL_USART_LASTCLKPULSE_NO_OUTPUT         0x00000000U                                                                                     
#define LL_USART_LASTCLKPULSE_OUTPUT            USART_CR2_LBCL                                                                              
   
      
    

                                           
      
    
#define LL_USART_PHASE_1EDGE                    0x00000000U                                                                            
#define LL_USART_PHASE_2EDGE                    USART_CR2_CPHA                                                                          
   
      
    

                                                 
      
    
#define LL_USART_POLARITY_LOW                   0x00000000U                                                                          
#define LL_USART_POLARITY_HIGH                  USART_CR2_CPOL                                                                         
   
      
    

#if defined(USART_PRESC_PRESCALER)
                                                          
      
    
#define LL_USART_PRESCALER_DIV1                 0x00000000U                                                                                                    
#define LL_USART_PRESCALER_DIV2                 (USART_PRESC_PRESCALER_0)                                                                                      
#define LL_USART_PRESCALER_DIV4                 (USART_PRESC_PRESCALER_1)                                                                                      
#define LL_USART_PRESCALER_DIV6                 (USART_PRESC_PRESCALER_1 | USART_PRESC_PRESCALER_0)                                                            
#define LL_USART_PRESCALER_DIV8                 (USART_PRESC_PRESCALER_2)                                                                                      
#define LL_USART_PRESCALER_DIV10                (USART_PRESC_PRESCALER_2 | USART_PRESC_PRESCALER_0)                                                            
#define LL_USART_PRESCALER_DIV12                (USART_PRESC_PRESCALER_2 | USART_PRESC_PRESCALER_1)                                                            
#define LL_USART_PRESCALER_DIV16                (USART_PRESC_PRESCALER_2 | USART_PRESC_PRESCALER_1 | USART_PRESC_PRESCALER_0)                                  
#define LL_USART_PRESCALER_DIV32                (USART_PRESC_PRESCALER_3)                                                                                      
#define LL_USART_PRESCALER_DIV64                (USART_PRESC_PRESCALER_3 | USART_PRESC_PRESCALER_0)                                                            
#define LL_USART_PRESCALER_DIV128               (USART_PRESC_PRESCALER_3 | USART_PRESC_PRESCALER_1)                                                             
#define LL_USART_PRESCALER_DIV256               (USART_PRESC_PRESCALER_3 | USART_PRESC_PRESCALER_1 | USART_PRESC_PRESCALER_0)                                   
   
      
    

#endif                            
                                            
      
    
#define LL_USART_STOPBITS_0_5                   USART_CR2_STOP_0                                               
#define LL_USART_STOPBITS_1                     0x00000000U                                                  
#define LL_USART_STOPBITS_1_5                   (USART_CR2_STOP_0 | USART_CR2_STOP_1)                           
#define LL_USART_STOPBITS_2                     USART_CR2_STOP_1                                              
   
      
    

                                              
      
    
#define LL_USART_TXRX_STANDARD                  0x00000000U                                                                    
#define LL_USART_TXRX_SWAPPED                   (USART_CR2_SWAP)                                                               
   
      
    

                                                                   
      
    
#define LL_USART_RXPIN_LEVEL_STANDARD           0x00000000U                                                                      
#define LL_USART_RXPIN_LEVEL_INVERTED           (USART_CR2_RXINV)                                                                
   
      
    

                                                                   
      
    
#define LL_USART_TXPIN_LEVEL_STANDARD           0x00000000U                                                                      
#define LL_USART_TXPIN_LEVEL_INVERTED           (USART_CR2_TXINV)                                                                
   
      
    

                                                            
      
    
#define LL_USART_BINARY_LOGIC_POSITIVE          0x00000000U                                                                                                             
#define LL_USART_BINARY_LOGIC_NEGATIVE          USART_CR2_DATAINV                                                                                                                                          
   
      
    

                                            
      
    
#define LL_USART_BITORDER_LSBFIRST              0x00000000U                                                                                              
#define LL_USART_BITORDER_MSBFIRST              USART_CR2_MSBFIRST                                                                                    
   
      
    

                                                               
      
    
#define LL_USART_AUTOBAUD_DETECT_ON_STARTBIT    0x00000000U                                                                                                     
#define LL_USART_AUTOBAUD_DETECT_ON_FALLINGEDGE USART_CR2_ABRMODE_0                                                                                                                                                   
#define LL_USART_AUTOBAUD_DETECT_ON_7F_FRAME    USART_CR2_ABRMODE_1                                                     
#define LL_USART_AUTOBAUD_DETECT_ON_55_FRAME    (USART_CR2_ABRMODE_1 | USART_CR2_ABRMODE_0)                             
   
      
    

                                                                 
      
    
#define LL_USART_ADDRESS_DETECT_4B              0x00000000U                                                          
#define LL_USART_ADDRESS_DETECT_7B              USART_CR2_ADDM7                                                                           
   
      
    

                                                    
      
    
#define LL_USART_HWCONTROL_NONE                 0x00000000U                                                                            
#define LL_USART_HWCONTROL_RTS                  USART_CR3_RTSE                                                                                                                   
#define LL_USART_HWCONTROL_CTS                  USART_CR3_CTSE                                                                                                                     
#define LL_USART_HWCONTROL_RTS_CTS              (USART_CR3_RTSE | USART_CR3_CTSE)                                                     
   
      
    

                                                     
      
    
#define LL_USART_WAKEUP_ON_ADDRESS              0x00000000U                                                                    
#define LL_USART_WAKEUP_ON_STARTBIT             USART_CR3_WUS_1                                                                      
#define LL_USART_WAKEUP_ON_RXNE                 (USART_CR3_WUS_0 | USART_CR3_WUS_1)                                   
   
      
    

                                               
      
    
#define LL_USART_IRDA_POWER_NORMAL              0x00000000U                                         
#define LL_USART_IRDA_POWER_LOW                 USART_CR3_IRLP                                   
   
      
    

                                                                    
      
    
#define LL_USART_LINBREAK_DETECT_10B            0x00000000U                                                         
#define LL_USART_LINBREAK_DETECT_11B            USART_CR2_LBDL                                                      
   
      
    

                                                            
      
    
#define LL_USART_DE_POLARITY_HIGH               0x00000000U                                           
#define LL_USART_DE_POLARITY_LOW                USART_CR3_DEP                                        
   
      
    

                                                        
      
    
#define LL_USART_DMA_REG_DATA_TRANSMIT          0x00000000U                                                                    
#define LL_USART_DMA_REG_DATA_RECEIVE           0x00000001U                                                                 
   
      
    

   
      
    

                                                                                
                                                            
      
    

                                                                           
      
    

   
                                           
                                       
                                          
                                                         
                
    
#define LL_USART_WriteReg(__INSTANCE__, __REG__, __VALUE__) WRITE_REG(__INSTANCE__->__REG__, (__VALUE__))

   
                                          
                                       
                                       
                          
    
#define LL_USART_ReadReg(__INSTANCE__, __REG__) READ_REG(__INSTANCE__->__REG__)
   
      
    

                                                                       
      
    

   
                                                                    
                                                                                              
                                                                            
                           
                                                                            
                                             
                                             
                                             
                                             
                                             
                                              
                                              
                                              
                                              
                                              
                                               
                                               
        
                                                   
                                                                                     
    
#if defined(USART_PRESC_PRESCALER)
#define __LL_USART_DIV_SAMPLING8(__PERIPHCLK__, __PRESCALER__, __BAUDRATE__) \
  (((((__PERIPHCLK__)/(USART_PRESCALER_TAB[(__PRESCALER__)]))*2U)\
    + ((__BAUDRATE__)/2U))/(__BAUDRATE__))
#else
#define __LL_USART_DIV_SAMPLING8(__PERIPHCLK__, __BAUDRATE__) ((((__PERIPHCLK__)*2U)\
                                                                + ((__BAUDRATE__)/2U))/(__BAUDRATE__))
#endif                            

   
                                                                    
                                                                                               
                                                                            
                           
                                                                            
                                             
                                             
                                             
                                             
                                             
                                              
                                              
                                              
                                              
                                              
                                               
                                               
        
                                                   
                                                                                      
    
#if defined(USART_PRESC_PRESCALER)
#define __LL_USART_DIV_SAMPLING16(__PERIPHCLK__, __PRESCALER__, __BAUDRATE__) \
  ((((__PERIPHCLK__)/(USART_PRESCALER_TAB[(__PRESCALER__)]))\
    + ((__BAUDRATE__)/2U))/(__BAUDRATE__))
#else
#define __LL_USART_DIV_SAMPLING16(__PERIPHCLK__, __BAUDRATE__) (((__PERIPHCLK__) + ((__BAUDRATE__)/2U))/(__BAUDRATE__))
#endif                            

   
      
    

   
      
    

                                                                                

                                                                  
      
    

                                                               
      
    

   
                        
                                                      
                                 
                
    
__STATIC_INLINE void LL_USART_Enable(USART_TypeDef *USARTx)
{
  SET_BIT(USARTx->CR1, USART_CR1_UE);
}

   
                                                                         
                                                                                         
                                                                                                            
                                                                     
                                                       
                                 
                
    
__STATIC_INLINE void LL_USART_Disable(USART_TypeDef *USARTx)
{
  CLEAR_BIT(USARTx->CR1, USART_CR1_UE);
}

   
                                        
                                                         
                                 
                                  
    
__STATIC_INLINE uint32_t LL_USART_IsEnabled(const USART_TypeDef *USARTx)
{
  return ((READ_BIT(USARTx->CR1, USART_CR1_UE) == (USART_CR1_UE)) ? 1UL : 0UL);
}

#if defined(USART_CR1_FIFOEN)
   
                            
                                                                                   
                                                                  
                                                          
                                 
                
    
__STATIC_INLINE void LL_USART_EnableFIFO(USART_TypeDef *USARTx)
{
  SET_BIT(USARTx->CR1, USART_CR1_FIFOEN);
}

   
                             
                                                                                   
                                                                  
                                                           
                                 
                
    
__STATIC_INLINE void LL_USART_DisableFIFO(USART_TypeDef *USARTx)
{
  CLEAR_BIT(USARTx->CR1, USART_CR1_FIFOEN);
}

   
                                            
                                                                                   
                                                                  
                                                             
                                 
                                  
    
__STATIC_INLINE uint32_t LL_USART_IsEnabledFIFO(const USART_TypeDef *USARTx)
{
  return ((READ_BIT(USARTx->CR1, USART_CR1_FIFOEN) == (USART_CR1_FIFOEN)) ? 1UL : 0UL);
}

   
                                       
                                                                                   
                                                                  
                                                                  
                                 
                                                                        
                                                
                                                
                                                
                                                
                                                
                                                
                
    
__STATIC_INLINE void LL_USART_SetTXFIFOThreshold(USART_TypeDef *USARTx, uint32_t Threshold)
{
  ATOMIC_MODIFY_REG(USARTx->CR3, USART_CR3_TXFTCFG, Threshold << USART_CR3_TXFTCFG_Pos);
}

   
                                                  
                                                                                   
                                                                  
                                                                  
                                 
                                                              
                                                
                                                
                                                
                                                
                                                
                                                
    
__STATIC_INLINE uint32_t LL_USART_GetTXFIFOThreshold(const USART_TypeDef *USARTx)
{
  return (uint32_t)(READ_BIT(USARTx->CR3, USART_CR3_TXFTCFG) >> USART_CR3_TXFTCFG_Pos);
}

   
                                       
                                                                                   
                                                                  
                                                                  
                                 
                                                                        
                                                
                                                
                                                
                                                
                                                
                                                
                
    
__STATIC_INLINE void LL_USART_SetRXFIFOThreshold(USART_TypeDef *USARTx, uint32_t Threshold)
{
  ATOMIC_MODIFY_REG(USARTx->CR3, USART_CR3_RXFTCFG, Threshold << USART_CR3_RXFTCFG_Pos);
}

   
                                                  
                                                                                   
                                                                  
                                                                  
                                 
                                                              
                                                
                                                
                                                
                                                
                                                
                                                
    
__STATIC_INLINE uint32_t LL_USART_GetRXFIFOThreshold(const USART_TypeDef *USARTx)
{
  return (uint32_t)(READ_BIT(USARTx->CR3, USART_CR3_RXFTCFG) >> USART_CR3_RXFTCFG_Pos);
}

   
                                               
                                                                                   
                                                                  
                                                                      
                                                                    
                                 
                                                                          
                                                
                                                
                                                
                                                
                                                
                                                
                                                                          
                                                
                                                
                                                
                                                
                                                
                                                
                
    
__STATIC_INLINE void LL_USART_ConfigFIFOsThreshold(USART_TypeDef *USARTx, uint32_t TXThreshold, uint32_t RXThreshold)
{
  ATOMIC_MODIFY_REG(USARTx->CR3, USART_CR3_TXFTCFG | USART_CR3_RXFTCFG, (TXThreshold << USART_CR3_TXFTCFG_Pos) |
                    (RXThreshold << USART_CR3_RXFTCFG_Pos));
}

#endif                       
   
                                       
                                                                                                         
                                                       
                                                                                              
                                                                               
                                                                
                                 
                
    
__STATIC_INLINE void LL_USART_EnableInStopMode(USART_TypeDef *USARTx)
{
  ATOMIC_SET_BIT(USARTx->CR1, USART_CR1_UESM);
}

   
                                        
                                                                                               
                                                                                              
                                                                               
                                                                 
                                 
                
    
__STATIC_INLINE void LL_USART_DisableInStopMode(USART_TypeDef *USARTx)
{
  ATOMIC_CLEAR_BIT(USARTx->CR1, USART_CR1_UESM);
}

   
                                                                                                 
                                                                                              
                                                                               
                                                                   
                                 
                                  
    
__STATIC_INLINE uint32_t LL_USART_IsEnabledInStopMode(const USART_TypeDef *USARTx)
{
  return ((READ_BIT(USARTx->CR1, USART_CR1_UESM) == (USART_CR1_UESM)) ? 1UL : 0UL);
}

#if defined(USART_CR3_UCESM)
   
                                            
                                                                                   
                                                                     
                                 
                
    
__STATIC_INLINE void LL_USART_EnableClockInStopMode(USART_TypeDef *USARTx)
{
  ATOMIC_SET_BIT(USARTx->CR3, USART_CR3_UCESM);
}

   
                                             
                                                                                    
                                                                      
                                 
                
    
__STATIC_INLINE void LL_USART_DisableClockInStopMode(USART_TypeDef *USARTx)
{
  ATOMIC_CLEAR_BIT(USARTx->CR3, USART_CR3_UCESM);
}

   
                                                           
                                                                        
                                 
                                  
    
__STATIC_INLINE uint32_t LL_USART_IsClockEnabledInStopMode(const USART_TypeDef *USARTx)
{
  return (READ_BIT(USARTx->CR3, USART_CR3_UCESM) == (USART_CR3_UCESM));
}

#endif                      
   
                                                                                      
                                                                 
                                 
                
    
__STATIC_INLINE void LL_USART_EnableDirectionRx(USART_TypeDef *USARTx)
{
  ATOMIC_SET_BIT(USARTx->CR1, USART_CR1_RE);
}

   
                            
                                                                  
                                 
                
    
__STATIC_INLINE void LL_USART_DisableDirectionRx(USART_TypeDef *USARTx)
{
  ATOMIC_CLEAR_BIT(USARTx->CR1, USART_CR1_RE);
}

   
                              
                                                                 
                                 
                
    
__STATIC_INLINE void LL_USART_EnableDirectionTx(USART_TypeDef *USARTx)
{
  ATOMIC_SET_BIT(USARTx->CR1, USART_CR1_TE);
}

   
                               
                                                                  
                                 
                
    
__STATIC_INLINE void LL_USART_DisableDirectionTx(USART_TypeDef *USARTx)
{
  ATOMIC_CLEAR_BIT(USARTx->CR1, USART_CR1_TE);
}

   
                                                            
                                       
                                                                      
                                                                    
                                 
                                                                                
                                             
                                           
                                           
                                              
                
    
__STATIC_INLINE void LL_USART_SetTransferDirection(USART_TypeDef *USARTx, uint32_t TransferDirection)
{
  ATOMIC_MODIFY_REG(USARTx->CR1, USART_CR1_RE | USART_CR1_TE, TransferDirection);
}

   
                                                                      
                                                                      
                                                                    
                                 
                                                              
                                             
                                           
                                           
                                              
    
__STATIC_INLINE uint32_t LL_USART_GetTransferDirection(const USART_TypeDef *USARTx)
{
  return (uint32_t)(READ_BIT(USARTx->CR1, USART_CR1_RE | USART_CR1_TE));
}

   
                                                                           
                                                                                                               
                                                                                                                 
                                                                                                
                                                           
                                                         
                                 
                                                                     
                                          
                                          
                                         
                
    
__STATIC_INLINE void LL_USART_SetParity(USART_TypeDef *USARTx, uint32_t Parity)
{
  MODIFY_REG(USARTx->CR1, USART_CR1_PS | USART_CR1_PCE, Parity);
}

   
                                                                                     
                                                           
                                                         
                                 
                                                              
                                          
                                          
                                         
    
__STATIC_INLINE uint32_t LL_USART_GetParity(const USART_TypeDef *USARTx)
{
  return (uint32_t)(READ_BIT(USARTx->CR1, USART_CR1_PS | USART_CR1_PCE));
}

   
                                                       
                                                               
                                 
                                                                     
                                              
                                                 
                
    
__STATIC_INLINE void LL_USART_SetWakeUpMethod(USART_TypeDef *USARTx, uint32_t Method)
{
  MODIFY_REG(USARTx->CR1, USART_CR1_WAKE, Method);
}

   
                                                         
                                                               
                                 
                                                              
                                              
                                                 
    
__STATIC_INLINE uint32_t LL_USART_GetWakeUpMethod(const USART_TypeDef *USARTx)
{
  return (uint32_t)(READ_BIT(USARTx->CR1, USART_CR1_WAKE));
}

   
                                                                                 
                                                              
                                                            
                                 
                                                                        
                                           
                                           
                                           
                
    
__STATIC_INLINE void LL_USART_SetDataWidth(USART_TypeDef *USARTx, uint32_t DataWidth)
{
  MODIFY_REG(USARTx->CR1, USART_CR1_M, DataWidth);
}

   
                                                                                    
                                                              
                                                            
                                 
                                                              
                                           
                                           
                                           
    
__STATIC_INLINE uint32_t LL_USART_GetDataWidth(const USART_TypeDef *USARTx)
{
  return (uint32_t)(READ_BIT(USARTx->CR1, USART_CR1_M));
}

   
                                                          
                                                              
                                 
                
    
__STATIC_INLINE void LL_USART_EnableMuteMode(USART_TypeDef *USARTx)
{
  ATOMIC_SET_BIT(USARTx->CR1, USART_CR1_MME);
}

   
                                                                           
                                                               
                                 
                
    
__STATIC_INLINE void LL_USART_DisableMuteMode(USART_TypeDef *USARTx)
{
  ATOMIC_CLEAR_BIT(USARTx->CR1, USART_CR1_MME);
}

   
                                                                           
                                                                 
                                 
                                  
    
__STATIC_INLINE uint32_t LL_USART_IsEnabledMuteMode(const USART_TypeDef *USARTx)
{
  return ((READ_BIT(USARTx->CR1, USART_CR1_MME) == (USART_CR1_MME)) ? 1UL : 0UL);
}

   
                                                    
                                                               
                                 
                                                                           
                                              
                                             
                
    
__STATIC_INLINE void LL_USART_SetOverSampling(USART_TypeDef *USARTx, uint32_t OverSampling)
{
  MODIFY_REG(USARTx->CR1, USART_CR1_OVER8, OverSampling);
}

   
                                    
                                                               
                                 
                                                              
                                              
                                             
    
__STATIC_INLINE uint32_t LL_USART_GetOverSampling(const USART_TypeDef *USARTx)
{
  return (uint32_t)(READ_BIT(USARTx->CR1, USART_CR1_OVER8));
}

   
                                                                                          
                                                                               
                                                                 
                                                                     
                                 
                                                                                
                                                     
                                                  
                
    
__STATIC_INLINE void LL_USART_SetLastClkPulseOutput(USART_TypeDef *USARTx, uint32_t LastBitClockPulse)
{
  MODIFY_REG(USARTx->CR2, USART_CR2_LBCL, LastBitClockPulse);
}

   
                                                                          
                                                                
                                                                               
                                                                 
                                                                     
                                 
                                                              
                                                     
                                                  
    
__STATIC_INLINE uint32_t LL_USART_GetLastClkPulseOutput(const USART_TypeDef *USARTx)
{
  return (uint32_t)(READ_BIT(USARTx->CR2, USART_CR2_LBCL));
}

   
                                                                                    
                                                                               
                                                                 
                                                             
                                 
                                                                         
                                          
                                          
                
    
__STATIC_INLINE void LL_USART_SetClockPhase(USART_TypeDef *USARTx, uint32_t ClockPhase)
{
  MODIFY_REG(USARTx->CR2, USART_CR2_CPHA, ClockPhase);
}

   
                                                                                
                                                                               
                                                                 
                                                             
                                 
                                                              
                                          
                                          
    
__STATIC_INLINE uint32_t LL_USART_GetClockPhase(const USART_TypeDef *USARTx)
{
  return (uint32_t)(READ_BIT(USARTx->CR2, USART_CR2_CPHA));
}

   
                                                                                       
                                                                               
                                                                 
                                                                
                                 
                                                                            
                                           
                                            
                
    
__STATIC_INLINE void LL_USART_SetClockPolarity(USART_TypeDef *USARTx, uint32_t ClockPolarity)
{
  MODIFY_REG(USARTx->CR2, USART_CR2_CPOL, ClockPolarity);
}

   
                                                                                   
                                                                               
                                                                 
                                                                
                                 
                                                              
                                           
                                            
    
__STATIC_INLINE uint32_t LL_USART_GetClockPolarity(const USART_TypeDef *USARTx)
{
  return (uint32_t)(READ_BIT(USARTx->CR2, USART_CR2_CPOL));
}

   
                                                                                                          
                                                                               
                                                                 
                                                                                     
                                                                                    
                                                                                          
                                                                                                               
                                                             
                                                             
                                                           
                                 
                                                                    
                                          
                                          
                                                                       
                                           
                                            
                                                                         
                                                     
                                                  
                
    
__STATIC_INLINE void LL_USART_ConfigClock(USART_TypeDef *USARTx, uint32_t Phase, uint32_t Polarity, uint32_t LBCPOutput)
{
  MODIFY_REG(USARTx->CR2, USART_CR2_CPHA | USART_CR2_CPOL | USART_CR2_LBCL, Phase | Polarity | LBCPOutput);
}

#if defined(USART_PRESC_PRESCALER)
   
                                                                                    
                                                                                   
                                                                  
                                                            
                                 
                                                                             
                                             
                                             
                                             
                                             
                                             
                                              
                                              
                                              
                                              
                                              
                                               
                                               
                
    
__STATIC_INLINE void LL_USART_SetPrescaler(USART_TypeDef *USARTx, uint32_t PrescalerValue)
{
  MODIFY_REG(USARTx->PRESC, USART_PRESC_PRESCALER, (uint16_t)PrescalerValue);
}

   
                                                                                       
                                                                                   
                                                                  
                                                            
                                 
                                                              
                                             
                                             
                                             
                                             
                                             
                                              
                                              
                                              
                                              
                                              
                                               
                                               
    
__STATIC_INLINE uint32_t LL_USART_GetPrescaler(const USART_TypeDef *USARTx)
{
  return (uint32_t)(READ_BIT(USARTx->PRESC, USART_PRESC_PRESCALER));
}

#endif                            
   
                                           
                                                                               
                                                                 
                                                                
                                 
                
    
__STATIC_INLINE void LL_USART_EnableSCLKOutput(USART_TypeDef *USARTx)
{
  SET_BIT(USARTx->CR2, USART_CR2_CLKEN);
}

   
                                            
                                                                               
                                                                 
                                                                 
                                 
                
    
__STATIC_INLINE void LL_USART_DisableSCLKOutput(USART_TypeDef *USARTx)
{
  CLEAR_BIT(USARTx->CR2, USART_CR2_CLKEN);
}

   
                                                           
                                                                               
                                                                 
                                                                   
                                 
                                  
    
__STATIC_INLINE uint32_t LL_USART_IsEnabledSCLKOutput(const USART_TypeDef *USARTx)
{
  return ((READ_BIT(USARTx->CR2, USART_CR2_CLKEN) == (USART_CR2_CLKEN)) ? 1UL : 0UL);
}

   
                                           
                                                                 
                                 
                                                                       
                                           
                                         
                                           
                                         
                
    
__STATIC_INLINE void LL_USART_SetStopBitsLength(USART_TypeDef *USARTx, uint32_t StopBits)
{
  MODIFY_REG(USARTx->CR2, USART_CR2_STOP, StopBits);
}

   
                                                
                                                                 
                                 
                                                              
                                           
                                         
                                           
                                         
    
__STATIC_INLINE uint32_t LL_USART_GetStopBitsLength(const USART_TypeDef *USARTx)
{
  return (uint32_t)(READ_BIT(USARTx->CR2, USART_CR2_STOP));
}

   
                                                                                   
                                                                                     
                                                                                  
                                                                                            
                                                                                      
                                                                 
                                                                 
                                                                 
                                                                 
                                                               
                                 
                                                                        
                                           
                                           
                                           
                                                                     
                                          
                                          
                                         
                                                                       
                                           
                                         
                                           
                                         
                
    
__STATIC_INLINE void LL_USART_ConfigCharacter(USART_TypeDef *USARTx, uint32_t DataWidth, uint32_t Parity,
                                              uint32_t StopBits)
{
  MODIFY_REG(USARTx->CR1, USART_CR1_PS | USART_CR1_PCE | USART_CR1_M, Parity | DataWidth);
  MODIFY_REG(USARTx->CR2, USART_CR2_STOP, StopBits);
}

   
                                                  
                                                           
                                 
                                                                         
                                            
                                           
                
    
__STATIC_INLINE void LL_USART_SetTXRXSwap(USART_TypeDef *USARTx, uint32_t SwapConfig)
{
  MODIFY_REG(USARTx->CR2, USART_CR2_SWAP, SwapConfig);
}

   
                                                       
                                                           
                                 
                                                              
                                            
                                           
    
__STATIC_INLINE uint32_t LL_USART_GetTXRXSwap(const USART_TypeDef *USARTx)
{
  return (uint32_t)(READ_BIT(USARTx->CR2, USART_CR2_SWAP));
}

   
                                               
                                                             
                                 
                                                                           
                                                   
                                                   
                
    
__STATIC_INLINE void LL_USART_SetRXPinLevel(USART_TypeDef *USARTx, uint32_t PinInvMethod)
{
  MODIFY_REG(USARTx->CR2, USART_CR2_RXINV, PinInvMethod);
}

   
                                                            
                                                             
                                 
                                                              
                                                   
                                                   
    
__STATIC_INLINE uint32_t LL_USART_GetRXPinLevel(const USART_TypeDef *USARTx)
{
  return (uint32_t)(READ_BIT(USARTx->CR2, USART_CR2_RXINV));
}

   
                                               
                                                             
                                 
                                                                           
                                                   
                                                   
                
    
__STATIC_INLINE void LL_USART_SetTXPinLevel(USART_TypeDef *USARTx, uint32_t PinInvMethod)
{
  MODIFY_REG(USARTx->CR2, USART_CR2_TXINV, PinInvMethod);
}

   
                                                            
                                                             
                                 
                                                              
                                                   
                                                   
    
__STATIC_INLINE uint32_t LL_USART_GetTXPinLevel(const USART_TypeDef *USARTx)
{
  return (uint32_t)(READ_BIT(USARTx->CR2, USART_CR2_TXINV));
}

   
                                        
                                                                                       
                                                                                              
                                                                  
                                 
                                                                        
                                                    
                                                    
                
    
__STATIC_INLINE void LL_USART_SetBinaryDataLogic(USART_TypeDef *USARTx, uint32_t DataLogic)
{
  MODIFY_REG(USARTx->CR2, USART_CR2_DATAINV, DataLogic);
}

   
                                              
                                                                  
                                 
                                                              
                                                    
                                                    
    
__STATIC_INLINE uint32_t LL_USART_GetBinaryDataLogic(const USART_TypeDef *USARTx)
{
  return (uint32_t)(READ_BIT(USARTx->CR2, USART_CR2_DATAINV));
}

   
                                                                                    
                                                                                                     
                                                                                                        
                                                                   
                                 
                                                                       
                                                
                                                
                
    
__STATIC_INLINE void LL_USART_SetTransferBitOrder(USART_TypeDef *USARTx, uint32_t BitOrder)
{
  MODIFY_REG(USARTx->CR2, USART_CR2_MSBFIRST, BitOrder);
}

   
                                                                                 
                                                                                                     
                                                                                                        
                                                                   
                                 
                                                              
                                                
                                                
    
__STATIC_INLINE uint32_t LL_USART_GetTransferBitOrder(const USART_TypeDef *USARTx)
{
  return (uint32_t)(READ_BIT(USARTx->CR2, USART_CR2_MSBFIRST));
}

   
                                           
                                                                                                      
                                                                                 
                                                                  
                                 
                
    
__STATIC_INLINE void LL_USART_EnableAutoBaudRate(USART_TypeDef *USARTx)
{
  SET_BIT(USARTx->CR2, USART_CR2_ABREN);
}

   
                                            
                                                                                                      
                                                                                 
                                                                   
                                 
                
    
__STATIC_INLINE void LL_USART_DisableAutoBaudRate(USART_TypeDef *USARTx)
{
  CLEAR_BIT(USARTx->CR2, USART_CR2_ABREN);
}

   
                                                                     
                                                                                                      
                                                                                 
                                                                 
                                 
                                  
    
__STATIC_INLINE uint32_t LL_USART_IsEnabledAutoBaud(const USART_TypeDef *USARTx)
{
  return ((READ_BIT(USARTx->CR2, USART_CR2_ABREN) == (USART_CR2_ABREN)) ? 1UL : 0UL);
}

   
                                        
                                                                                                      
                                                                                 
                                                                   
                                 
                                                                               
                                                          
                                                             
                                                          
                                                          
                
    
__STATIC_INLINE void LL_USART_SetAutoBaudRateMode(USART_TypeDef *USARTx, uint32_t AutoBaudRateMode)
{
  MODIFY_REG(USARTx->CR2, USART_CR2_ABRMODE, AutoBaudRateMode);
}

   
                                      
                                                                                                      
                                                                                 
                                                                   
                                 
                                                              
                                                          
                                                             
                                                          
                                                          
    
__STATIC_INLINE uint32_t LL_USART_GetAutoBaudRateMode(const USART_TypeDef *USARTx)
{
  return (uint32_t)(READ_BIT(USARTx->CR2, USART_CR2_ABRMODE));
}

   
                                   
                                                               
                                 
                
    
__STATIC_INLINE void LL_USART_EnableRxTimeout(USART_TypeDef *USARTx)
{
  SET_BIT(USARTx->CR2, USART_CR2_RTOEN);
}

   
                                    
                                                                
                                 
                
    
__STATIC_INLINE void LL_USART_DisableRxTimeout(USART_TypeDef *USARTx)
{
  CLEAR_BIT(USARTx->CR2, USART_CR2_RTOEN);
}

   
                                                           
                                                                  
                                 
                                  
    
__STATIC_INLINE uint32_t LL_USART_IsEnabledRxTimeout(const USART_TypeDef *USARTx)
{
  return ((READ_BIT(USARTx->CR2, USART_CR2_RTOEN) == (USART_CR2_RTOEN)) ? 1UL : 0UL);
}

   
                                          
                                                                                       
                                                    
                                                                                         
                                      
                                                                                         
                                                                                        
                                                          
                                                                                  
                                                                                
                                                                                        
                                                                                          
                                               
                                                                   
                                                                 
                                 
                                                                         
                                                
                                                
                                                             
                
    
__STATIC_INLINE void LL_USART_ConfigNodeAddress(USART_TypeDef *USARTx, uint32_t AddressLen, uint32_t NodeAddress)
{
  MODIFY_REG(USARTx->CR2, USART_CR2_ADD | USART_CR2_ADDM7,
             (uint32_t)(AddressLen | (NodeAddress << USART_CR2_ADD_Pos)));
}

   
                                                                              
                                                            
                                                                                       
                                                            
                                                                                       
                                                              
                                 
                                                                                 
    
__STATIC_INLINE uint32_t LL_USART_GetNodeAddress(const USART_TypeDef *USARTx)
{
  return (uint32_t)(READ_BIT(USARTx->CR2, USART_CR2_ADD) >> USART_CR2_ADD_Pos);
}

   
                                                                                         
                                                                 
                                 
                                                              
                                                
                                                
    
__STATIC_INLINE uint32_t LL_USART_GetNodeAddressLen(const USART_TypeDef *USARTx)
{
  return (uint32_t)(READ_BIT(USARTx->CR2, USART_CR2_ADDM7));
}

   
                                      
                                                                                     
                                                                              
                                                                   
                                 
                
    
__STATIC_INLINE void LL_USART_EnableRTSHWFlowCtrl(USART_TypeDef *USARTx)
{
  SET_BIT(USARTx->CR3, USART_CR3_RTSE);
}

   
                                       
                                                                                     
                                                                              
                                                                    
                                 
                
    
__STATIC_INLINE void LL_USART_DisableRTSHWFlowCtrl(USART_TypeDef *USARTx)
{
  CLEAR_BIT(USARTx->CR3, USART_CR3_RTSE);
}

   
                                      
                                                                                     
                                                                              
                                                                   
                                 
                
    
__STATIC_INLINE void LL_USART_EnableCTSHWFlowCtrl(USART_TypeDef *USARTx)
{
  SET_BIT(USARTx->CR3, USART_CR3_CTSE);
}

   
                                       
                                                                                     
                                                                              
                                                                    
                                 
                
    
__STATIC_INLINE void LL_USART_DisableCTSHWFlowCtrl(USART_TypeDef *USARTx)
{
  CLEAR_BIT(USARTx->CR3, USART_CR3_CTSE);
}

   
                                                             
                                                                                     
                                                                              
                                                               
                                                             
                                 
                                                                                  
                                             
                                            
                                            
                                                
                
    
__STATIC_INLINE void LL_USART_SetHWFlowCtrl(USART_TypeDef *USARTx, uint32_t HardwareFlowControl)
{
  MODIFY_REG(USARTx->CR3, USART_CR3_RTSE | USART_CR3_CTSE, HardwareFlowControl);
}

   
                                                                   
                                                                                     
                                                                              
                                                               
                                                             
                                 
                                                              
                                             
                                            
                                            
                                                
    
__STATIC_INLINE uint32_t LL_USART_GetHWFlowCtrl(const USART_TypeDef *USARTx)
{
  return (uint32_t)(READ_BIT(USARTx->CR3, USART_CR3_RTSE | USART_CR3_CTSE));
}

   
                                          
                                                                
                                 
                
    
__STATIC_INLINE void LL_USART_EnableOneBitSamp(USART_TypeDef *USARTx)
{
  SET_BIT(USARTx->CR3, USART_CR3_ONEBIT);
}

   
                                           
                                                                 
                                 
                
    
__STATIC_INLINE void LL_USART_DisableOneBitSamp(USART_TypeDef *USARTx)
{
  CLEAR_BIT(USARTx->CR3, USART_CR3_ONEBIT);
}

   
                                                          
                                                                   
                                 
                                  
    
__STATIC_INLINE uint32_t LL_USART_IsEnabledOneBitSamp(const USART_TypeDef *USARTx)
{
  return ((READ_BIT(USARTx->CR3, USART_CR3_ONEBIT) == (USART_CR3_ONEBIT)) ? 1UL : 0UL);
}

   
                                    
                                                                   
                                 
                
    
__STATIC_INLINE void LL_USART_EnableOverrunDetect(USART_TypeDef *USARTx)
{
  CLEAR_BIT(USARTx->CR3, USART_CR3_OVRDIS);
}

   
                                     
                                                                    
                                 
                
    
__STATIC_INLINE void LL_USART_DisableOverrunDetect(USART_TypeDef *USARTx)
{
  SET_BIT(USARTx->CR3, USART_CR3_OVRDIS);
}

   
                                                    
                                                                      
                                 
                                  
    
__STATIC_INLINE uint32_t LL_USART_IsEnabledOverrunDetect(const USART_TypeDef *USARTx)
{
  return ((READ_BIT(USARTx->CR3, USART_CR3_OVRDIS) != USART_CR3_OVRDIS) ? 1UL : 0UL);
}

   
                                                                        
                                                                                              
                                                                               
                                                           
                                 
                                                                   
                                                
                                                 
                                             
                
    
__STATIC_INLINE void LL_USART_SetWKUPType(USART_TypeDef *USARTx, uint32_t Type)
{
  MODIFY_REG(USARTx->CR3, USART_CR3_WUS, Type);
}

   
                                                                        
                                                                                              
                                                                               
                                                           
                                 
                                                              
                                                
                                                 
                                             
    
__STATIC_INLINE uint32_t LL_USART_GetWKUPType(const USART_TypeDef *USARTx)
{
  return (uint32_t)(READ_BIT(USARTx->CR3, USART_CR3_WUS));
}

   
                                                                                
                                                                             
                                                                                                
                                                                                                 
                                  
                                                                                                  
                                                           
                                 
                                      
                           
                                                                             
                                             
                                             
                                             
                                             
                                             
                                              
                                              
                                              
                                              
                                              
                                               
                                               
        
                                                                           
                                              
                                             
                              
                
    
#if defined(USART_PRESC_PRESCALER)
__STATIC_INLINE void LL_USART_SetBaudRate(USART_TypeDef *USARTx, uint32_t PeriphClk, uint32_t PrescalerValue,
                                          uint32_t OverSampling,
                                          uint32_t BaudRate)
#else
__STATIC_INLINE void LL_USART_SetBaudRate(USART_TypeDef *USARTx, uint32_t PeriphClk, uint32_t OverSampling,
                                          uint32_t BaudRate)
#endif                            
{
  uint32_t usartdiv;
  uint32_t brrtemp;

#if defined(USART_PRESC_PRESCALER)
  if (PrescalerValue > LL_USART_PRESCALER_DIV256)
  {
                                                         
  }
  else if (BaudRate == 0U)
  {
                              
  }
  else if (OverSampling == LL_USART_OVERSAMPLING_8)
#else
  if (OverSampling == LL_USART_OVERSAMPLING_8)
#endif                            
  {
#if defined(USART_PRESC_PRESCALER)
    usartdiv = (uint16_t)(__LL_USART_DIV_SAMPLING8(PeriphClk, (uint8_t)PrescalerValue, BaudRate));
#else
    usartdiv = (uint16_t)(__LL_USART_DIV_SAMPLING8(PeriphClk, BaudRate));
#endif                            
    brrtemp = usartdiv & 0xFFF0U;
    brrtemp |= (uint16_t)((usartdiv & (uint16_t)0x000FU) >> 1U);
    USARTx->BRR = brrtemp;
  }
  else
  {
#if defined(USART_PRESC_PRESCALER)
    USARTx->BRR = (uint16_t)(__LL_USART_DIV_SAMPLING16(PeriphClk, (uint8_t)PrescalerValue, BaudRate));
#else
    USARTx->BRR = (uint16_t)(__LL_USART_DIV_SAMPLING16(PeriphClk, BaudRate));
#endif                            
  }
}

   
                                                                                         
                                                                                         
                                                                                                         
                                                                                                  
                                                           
                                 
                                      
                           
                                                                             
                                             
                                             
                                             
                                             
                                             
                                              
                                              
                                              
                                              
                                              
                                               
                                               
        
                                                                           
                                              
                                             
                     
    
#if defined(USART_PRESC_PRESCALER)
__STATIC_INLINE uint32_t LL_USART_GetBaudRate(const USART_TypeDef *USARTx, uint32_t PeriphClk, uint32_t PrescalerValue,
                                              uint32_t OverSampling)
#else
__STATIC_INLINE uint32_t LL_USART_GetBaudRate(const USART_TypeDef *USARTx, uint32_t PeriphClk, uint32_t OverSampling)
#endif                            
{
  uint32_t usartdiv;
  uint32_t brrresult = 0x0U;
#if defined(USART_PRESC_PRESCALER)
  uint32_t periphclkpresc = (uint32_t)(PeriphClk / (USART_PRESCALER_TAB[(uint8_t)PrescalerValue]));
#endif                            

  usartdiv = USARTx->BRR;

  if (usartdiv == 0U)
  {
                                        
  }
  else if (OverSampling == LL_USART_OVERSAMPLING_8)
  {
    usartdiv = (uint16_t)((usartdiv & 0xFFF0U) | ((usartdiv & 0x0007U) << 1U)) ;
    if (usartdiv != 0U)
    {
#if defined(USART_PRESC_PRESCALER)
      brrresult = (periphclkpresc * 2U) / usartdiv;
#else
      brrresult = (PeriphClk * 2U) / usartdiv;
#endif                            
    }
  }
  else
  {
    if ((usartdiv & 0xFFFFU) != 0U)
    {
#if defined(USART_PRESC_PRESCALER)
      brrresult = periphclkpresc / usartdiv;
#else
      brrresult = PeriphClk / usartdiv;
#endif                            
    }
  }
  return (brrresult);
}

   
                                                                          
                                                            
                                 
                                                                       
                
    
__STATIC_INLINE void LL_USART_SetRxTimeout(USART_TypeDef *USARTx, uint32_t Timeout)
{
  MODIFY_REG(USARTx->RTOR, USART_RTOR_RTO, Timeout);
}

   
                                                                          
                                                            
                                 
                                                               
    
__STATIC_INLINE uint32_t LL_USART_GetRxTimeout(const USART_TypeDef *USARTx)
{
  return (uint32_t)(READ_BIT(USARTx->RTOR, USART_RTOR_RTO));
}

   
                                               
                                                              
                                 
                                                                     
                
    
__STATIC_INLINE void LL_USART_SetBlockLength(USART_TypeDef *USARTx, uint32_t BlockLength)
{
  MODIFY_REG(USARTx->RTOR, USART_RTOR_BLEN, BlockLength << USART_RTOR_BLEN_Pos);
}

   
                                               
                                                              
                                 
                                                         
    
__STATIC_INLINE uint32_t LL_USART_GetBlockLength(const USART_TypeDef *USARTx)
{
  return (uint32_t)(READ_BIT(USARTx->RTOR, USART_RTOR_BLEN) >> USART_RTOR_BLEN_Pos);
}

   
      
    

                                                                                            
      
    

   
                            
                                                                              
                                                             
                                                          
                                 
                
    
__STATIC_INLINE void LL_USART_EnableIrda(USART_TypeDef *USARTx)
{
  SET_BIT(USARTx->CR3, USART_CR3_IREN);
}

   
                             
                                                                              
                                                             
                                                           
                                 
                
    
__STATIC_INLINE void LL_USART_DisableIrda(USART_TypeDef *USARTx)
{
  CLEAR_BIT(USARTx->CR3, USART_CR3_IREN);
}

   
                                            
                                                                              
                                                             
                                                             
                                 
                                  
    
__STATIC_INLINE uint32_t LL_USART_IsEnabledIrda(const USART_TypeDef *USARTx)
{
  return ((READ_BIT(USARTx->CR3, USART_CR3_IREN) == (USART_CR3_IREN)) ? 1UL : 0UL);
}

   
                                                           
                                                                              
                                                             
                                                                
                                 
                                                                        
                                                
                                             
                
    
__STATIC_INLINE void LL_USART_SetIrdaPowerMode(USART_TypeDef *USARTx, uint32_t PowerMode)
{
  MODIFY_REG(USARTx->CR3, USART_CR3_IRLP, PowerMode);
}

   
                                                                        
                                                                              
                                                             
                                                                
                                 
                                                              
                                                
                                          
    
__STATIC_INLINE uint32_t LL_USART_GetIrdaPowerMode(const USART_TypeDef *USARTx)
{
  return (uint32_t)(READ_BIT(USARTx->CR3, USART_CR3_IRLP));
}

   
                                                                              
                                                                  
                                                                              
                                                             
                                                                
                                 
                                                                        
                
    
__STATIC_INLINE void LL_USART_SetIrdaPrescaler(USART_TypeDef *USARTx, uint32_t PrescalerValue)
{
  MODIFY_REG(USARTx->GTPR, USART_GTPR_PSC, (uint16_t)PrescalerValue);
}

   
                                                                                 
                                                                  
                                                                              
                                                             
                                                                
                                 
                                                                                
    
__STATIC_INLINE uint32_t LL_USART_GetIrdaPrescaler(const USART_TypeDef *USARTx)
{
  return (uint32_t)(READ_BIT(USARTx->GTPR, USART_GTPR_PSC));
}

   
      
    

                                                                                                      
      
    

   
                                              
                                                                                   
                                                                  
                                                                   
                                 
                
    
__STATIC_INLINE void LL_USART_EnableSmartcardNACK(USART_TypeDef *USARTx)
{
  SET_BIT(USARTx->CR3, USART_CR3_NACK);
}

   
                                               
                                                                                   
                                                                  
                                                                    
                                 
                
    
__STATIC_INLINE void LL_USART_DisableSmartcardNACK(USART_TypeDef *USARTx)
{
  CLEAR_BIT(USARTx->CR3, USART_CR3_NACK);
}

   
                                                              
                                                                                   
                                                                  
                                                                      
                                 
                                  
    
__STATIC_INLINE uint32_t LL_USART_IsEnabledSmartcardNACK(const USART_TypeDef *USARTx)
{
  return ((READ_BIT(USARTx->CR3, USART_CR3_NACK) == (USART_CR3_NACK)) ? 1UL : 0UL);
}

   
                                 
                                                                                   
                                                                  
                                                               
                                 
                
    
__STATIC_INLINE void LL_USART_EnableSmartcard(USART_TypeDef *USARTx)
{
  SET_BIT(USARTx->CR3, USART_CR3_SCEN);
}

   
                                  
                                                                                   
                                                                  
                                                                
                                 
                
    
__STATIC_INLINE void LL_USART_DisableSmartcard(USART_TypeDef *USARTx)
{
  CLEAR_BIT(USARTx->CR3, USART_CR3_SCEN);
}

   
                                                 
                                                                                   
                                                                  
                                                                  
                                 
                                  
    
__STATIC_INLINE uint32_t LL_USART_IsEnabledSmartcard(const USART_TypeDef *USARTx)
{
  return ((READ_BIT(USARTx->CR3, USART_CR3_SCEN) == (USART_CR3_SCEN)) ? 1UL : 0UL);
}

   
                                                                    
                                                                                   
                                                                  
                                                                                                      
                                                                                                     
                                                         
                                                                                                         
                                                  
                                                                          
                                 
                                                                  
                
    
__STATIC_INLINE void LL_USART_SetSmartcardAutoRetryCount(USART_TypeDef *USARTx, uint32_t AutoRetryCount)
{
  MODIFY_REG(USARTx->CR3, USART_CR3_SCARCNT, AutoRetryCount << USART_CR3_SCARCNT_Pos);
}

   
                                                                       
                                                                                   
                                                                  
                                                                          
                                 
                                                                                      
    
__STATIC_INLINE uint32_t LL_USART_GetSmartcardAutoRetryCount(const USART_TypeDef *USARTx)
{
  return (uint32_t)(READ_BIT(USARTx->CR3, USART_CR3_SCARCNT) >> USART_CR3_SCARCNT_Pos);
}

   
                                                                            
                                                                
                                                                                   
                                                                  
                                                                     
                                 
                                                                   
                
    
__STATIC_INLINE void LL_USART_SetSmartcardPrescaler(USART_TypeDef *USARTx, uint32_t PrescalerValue)
{
  MODIFY_REG(USARTx->GTPR, USART_GTPR_PSC, (uint16_t)PrescalerValue);
}

   
                                                                               
                                                                
                                                                                   
                                                                  
                                                                     
                                 
                                                                                
    
__STATIC_INLINE uint32_t LL_USART_GetSmartcardPrescaler(const USART_TypeDef *USARTx)
{
  return (uint32_t)(READ_BIT(USARTx->GTPR, USART_GTPR_PSC));
}

   
                                                                                  
                                             
                                                                                   
                                                                  
                                                                     
                                 
                                                                   
                
    
__STATIC_INLINE void LL_USART_SetSmartcardGuardTime(USART_TypeDef *USARTx, uint32_t GuardTime)
{
  MODIFY_REG(USARTx->GTPR, USART_GTPR_GT, (uint16_t)(GuardTime << USART_GTPR_GT_Pos));
}

   
                                                                                     
                                             
                                                                                   
                                                                  
                                                                     
                                 
                                                                                      
    
__STATIC_INLINE uint32_t LL_USART_GetSmartcardGuardTime(const USART_TypeDef *USARTx)
{
  return (uint32_t)(READ_BIT(USARTx->GTPR, USART_GTPR_GT) >> USART_GTPR_GT_Pos);
}

   
      
    

                                                                                                         
      
    

   
                                               
                                                                                         
                                                                 
                                                                
                                 
                
    
__STATIC_INLINE void LL_USART_EnableHalfDuplex(USART_TypeDef *USARTx)
{
  SET_BIT(USARTx->CR3, USART_CR3_HDSEL);
}

   
                                                
                                                                                         
                                                                 
                                                                 
                                 
                
    
__STATIC_INLINE void LL_USART_DisableHalfDuplex(USART_TypeDef *USARTx)
{
  CLEAR_BIT(USARTx->CR3, USART_CR3_HDSEL);
}

   
                                                               
                                                                                         
                                                                 
                                                                   
                                 
                                  
    
__STATIC_INLINE uint32_t LL_USART_IsEnabledHalfDuplex(const USART_TypeDef *USARTx)
{
  return ((READ_BIT(USARTx->CR3, USART_CR3_HDSEL) == (USART_CR3_HDSEL)) ? 1UL : 0UL);
}

   
      
    

#if defined(USART_CR2_SLVEN)
                                                                                                      
      
    
   
                                             
                                                                                        
                                                                       
                                                              
                                 
                
    
__STATIC_INLINE void LL_USART_EnableSPISlave(USART_TypeDef *USARTx)
{
  SET_BIT(USARTx->CR2, USART_CR2_SLVEN);
}

   
                                              
                                                                                        
                                                                       
                                                               
                                 
                
    
__STATIC_INLINE void LL_USART_DisableSPISlave(USART_TypeDef *USARTx)
{
  CLEAR_BIT(USARTx->CR2, USART_CR2_SLVEN);
}

   
                                                              
                                                                                        
                                                                       
                                                                 
                                 
                                  
    
__STATIC_INLINE uint32_t LL_USART_IsEnabledSPISlave(const USART_TypeDef *USARTx)
{
  return ((READ_BIT(USARTx->CR2, USART_CR2_SLVEN) == (USART_CR2_SLVEN)) ? 1UL : 0UL);
}

   
                                                          
                                                                                        
                                                                       
                                                        
                                                                                    
                                                                    
                                 
                
    
__STATIC_INLINE void LL_USART_EnableSPISlaveSelect(USART_TypeDef *USARTx)
{
  CLEAR_BIT(USARTx->CR2, USART_CR2_DIS_NSS);
}

   
                                                           
                                                                                        
                                                                       
                                                                                
                                                                     
                                 
                
    
__STATIC_INLINE void LL_USART_DisableSPISlaveSelect(USART_TypeDef *USARTx)
{
  SET_BIT(USARTx->CR2, USART_CR2_DIS_NSS);
}

   
                                                                     
                                                                                        
                                                                       
                                                                       
                                 
                                  
    
__STATIC_INLINE uint32_t LL_USART_IsEnabledSPISlaveSelect(const USART_TypeDef *USARTx)
{
  return ((READ_BIT(USARTx->CR2, USART_CR2_DIS_NSS) != (USART_CR2_DIS_NSS)) ? 1UL : 0UL);
}

   
      
    

#endif                      
                                                                                          
      
    

   
                                          
                                                                                  
                                                            
                                                                     
                                 
                                                                          
                                                  
                                                  
                
    
__STATIC_INLINE void LL_USART_SetLINBrkDetectionLen(USART_TypeDef *USARTx, uint32_t LINBDLength)
{
  MODIFY_REG(USARTx->CR2, USART_CR2_LBDL, LINBDLength);
}

   
                                             
                                                                                  
                                                            
                                                                     
                                 
                                                              
                                                  
                                                  
    
__STATIC_INLINE uint32_t LL_USART_GetLINBrkDetectionLen(const USART_TypeDef *USARTx)
{
  return (uint32_t)(READ_BIT(USARTx->CR2, USART_CR2_LBDL));
}

   
                           
                                                                                  
                                                            
                                                         
                                 
                
    
__STATIC_INLINE void LL_USART_EnableLIN(USART_TypeDef *USARTx)
{
  SET_BIT(USARTx->CR2, USART_CR2_LINEN);
}

   
                            
                                                                                  
                                                            
                                                          
                                 
                
    
__STATIC_INLINE void LL_USART_DisableLIN(USART_TypeDef *USARTx)
{
  CLEAR_BIT(USARTx->CR2, USART_CR2_LINEN);
}

   
                                           
                                                                                  
                                                            
                                                            
                                 
                                  
    
__STATIC_INLINE uint32_t LL_USART_IsEnabledLIN(const USART_TypeDef *USARTx)
{
  return ((READ_BIT(USARTx->CR2, USART_CR2_LINEN) == (USART_CR2_LINEN)) ? 1UL : 0UL);
}

   
      
    

                                                                                                   
      
    

   
                                                                                                    
                                                                                            
                                                                      
                                                                    
                                 
                                                         
                
    
__STATIC_INLINE void LL_USART_SetDEDeassertionTime(USART_TypeDef *USARTx, uint32_t Time)
{
  MODIFY_REG(USARTx->CR1, USART_CR1_DEDT, Time << USART_CR1_DEDT_Pos);
}

   
                                                         
                                                                                            
                                                                      
                                                                    
                                 
                                                                                                  
    
__STATIC_INLINE uint32_t LL_USART_GetDEDeassertionTime(const USART_TypeDef *USARTx)
{
  return (uint32_t)(READ_BIT(USARTx->CR1, USART_CR1_DEDT) >> USART_CR1_DEDT_Pos);
}

   
                                                                                                 
                                                                                            
                                                                      
                                                                  
                                 
                                                         
                
    
__STATIC_INLINE void LL_USART_SetDEAssertionTime(USART_TypeDef *USARTx, uint32_t Time)
{
  MODIFY_REG(USARTx->CR1, USART_CR1_DEAT, Time << USART_CR1_DEAT_Pos);
}

   
                                                      
                                                                                            
                                                                      
                                                                  
                                 
                                                                                                  
    
__STATIC_INLINE uint32_t LL_USART_GetDEAssertionTime(const USART_TypeDef *USARTx)
{
  return (uint32_t)(READ_BIT(USARTx->CR1, USART_CR1_DEAT) >> USART_CR1_DEAT_Pos);
}

   
                                          
                                                                                            
                                                                      
                                                            
                                 
                
    
__STATIC_INLINE void LL_USART_EnableDEMode(USART_TypeDef *USARTx)
{
  SET_BIT(USARTx->CR3, USART_CR3_DEM);
}

   
                                           
                                                                                            
                                                                      
                                                             
                                 
                
    
__STATIC_INLINE void LL_USART_DisableDEMode(USART_TypeDef *USARTx)
{
  CLEAR_BIT(USARTx->CR3, USART_CR3_DEM);
}

   
                                                          
                                                                                            
                                                                      
                                                               
                                 
                                  
    
__STATIC_INLINE uint32_t LL_USART_IsEnabledDEMode(const USART_TypeDef *USARTx)
{
  return ((READ_BIT(USARTx->CR3, USART_CR3_DEM) == (USART_CR3_DEM)) ? 1UL : 0UL);
}

   
                                         
                                                                                            
                                                                      
                                                                   
                                 
                                                                       
                                               
                                              
                
    
__STATIC_INLINE void LL_USART_SetDESignalPolarity(USART_TypeDef *USARTx, uint32_t Polarity)
{
  MODIFY_REG(USARTx->CR3, USART_CR3_DEP, Polarity);
}

   
                                         
                                                                                            
                                                                      
                                                                   
                                 
                                                              
                                               
                                              
    
__STATIC_INLINE uint32_t LL_USART_GetDESignalPolarity(const USART_TypeDef *USARTx)
{
  return (uint32_t)(READ_BIT(USARTx->CR3, USART_CR3_DEP));
}

   
      
    

                                                                                
      
    

   
                                                                                             
                                                                  
                                                    
                                                    
                                                   
                                                   
                                                    
                                                                                     
                                                                          
                                                                                 
                                                                               
                                                                          
                                                                                 
                                                                             
                                                                        
                               
                                                                 
                                                                 
                                                                 
                                                                 
                                                               
                                 
                
    
__STATIC_INLINE void LL_USART_ConfigAsyncMode(USART_TypeDef *USARTx)
{
                                                                   
                                                
                                                        
    
  CLEAR_BIT(USARTx->CR2, (USART_CR2_LINEN | USART_CR2_CLKEN));
  CLEAR_BIT(USARTx->CR3, (USART_CR3_SCEN | USART_CR3_IREN | USART_CR3_HDSEL));
}

   
                                                                                     
                                                                         
                                                    
                                                   
                                                   
                                                    
                                                                  
                                                                               
                                                                 
                                                                                     
                                                                          
                                                                          
                                                                               
                                                                                 
                                                                              
                                                                            
                                                                                        
                               
                                                                
                                                                
                                                                
                                                                
                                                              
                                 
                
    
__STATIC_INLINE void LL_USART_ConfigSyncMode(USART_TypeDef *USARTx)
{
                                                                  
                                        
                                                        
    
  CLEAR_BIT(USARTx->CR2, (USART_CR2_LINEN));
  CLEAR_BIT(USARTx->CR3, (USART_CR3_SCEN | USART_CR3_IREN | USART_CR3_HDSEL));
                                              
  SET_BIT(USARTx->CR2, USART_CR2_CLKEN);
}

   
                                                                             
                                                                 
                                                              
                                                   
                                                   
                                                    
                                                              
                                                                                  
                                                            
                                                                                     
                                                                                 
                                                                                
                                                                               
                                                                          
                                                                                 
                                                                       
                                                                    
                                                                                            
                               
                                                               
                                                               
                                                               
                                                               
                                                               
                                                             
                                 
                
    
__STATIC_INLINE void LL_USART_ConfigLINMode(USART_TypeDef *USARTx)
{
                                                          
                                                  
                                                        
    
  CLEAR_BIT(USARTx->CR2, (USART_CR2_CLKEN | USART_CR2_STOP));
  CLEAR_BIT(USARTx->CR3, (USART_CR3_IREN | USART_CR3_SCEN | USART_CR3_HDSEL));
                                      
  SET_BIT(USARTx->CR2, USART_CR2_LINEN);
}

   
                                                                                     
                                                                         
                                                    
                                                    
                                                   
                                                   
                                                                       
                                                                                         
                                                                 
                                                                                     
                                                                          
                                                                                 
                                                                               
                                                                          
                                                                              
                                                                            
                                                                        
                               
                                                                      
                                                                      
                                                                      
                                                                      
                                                                    
                                 
                
    
__STATIC_INLINE void LL_USART_ConfigHalfDuplexMode(USART_TypeDef *USARTx)
{
                                                                  
                                                   
                                                 
    
  CLEAR_BIT(USARTx->CR2, (USART_CR2_LINEN | USART_CR2_CLKEN));
  CLEAR_BIT(USARTx->CR3, (USART_CR3_SCEN | USART_CR3_IREN));
                                              
  SET_BIT(USARTx->CR3, USART_CR3_HDSEL);
}

   
                                                                                   
                                                                       
                                                    
                                                   
                                                    
                                                                   
                                                        
                                                 
                                                                                   
                                                                  
                                                                                     
                                                                          
                                                                          
                                                                                 
                                                                                    
                                                                              
                                                                            
                                                                          
                                                                        
                               
                                                                     
                                                                     
                                                                     
                                                                     
                                                                   
                                 
                
    
__STATIC_INLINE void LL_USART_ConfigSmartcardMode(USART_TypeDef *USARTx)
{
                                                                
                                        
                                                  
    
  CLEAR_BIT(USARTx->CR2, (USART_CR2_LINEN));
  CLEAR_BIT(USARTx->CR3, (USART_CR3_IREN | USART_CR3_HDSEL));
                                       
                                                
  SET_BIT(USARTx->CR2, (USART_CR2_STOP_0 | USART_CR2_STOP_1 | USART_CR2_CLKEN));
                                            
  SET_BIT(USARTx->CR3, USART_CR3_SCEN);
}

   
                                                                              
                                                                  
                                                    
                                                              
                                                   
                                                    
                                                                           
                                                                              
                                                             
                                                                                     
                                                                          
                                                                                 
                                                                               
                                                                                 
                                                                                    
                                                                       
                                                                     
                                                                            
                               
                                                                
                                                                
                                                                
                                                                
                                                                
                                                              
                                 
                
    
__STATIC_INLINE void LL_USART_ConfigIrdaMode(USART_TypeDef *USARTx)
{
                                                           
                                                         
                                                  
    
  CLEAR_BIT(USARTx->CR2, (USART_CR2_LINEN | USART_CR2_CLKEN | USART_CR2_STOP));
  CLEAR_BIT(USARTx->CR3, (USART_CR3_SCEN | USART_CR3_HDSEL));
                                       
  SET_BIT(USARTx->CR3, USART_CR3_IREN);
}

   
                                                                                         
                                                                                        
                                                                                 
                                                                            
                                                    
                                                    
                                                   
                                                   
                                                    
                                                                                     
                                                                          
                                                                                 
                                                                               
                                                                          
                                                                                 
                                                                                
                                                                                 
                               
                                                                        
                                                                        
                                                                        
                                                                        
                                                                      
                                 
                
    
__STATIC_INLINE void LL_USART_ConfigMultiProcessMode(USART_TypeDef *USARTx)
{
                                                                      
                                                   
                                                        
    
  CLEAR_BIT(USARTx->CR2, (USART_CR2_LINEN | USART_CR2_CLKEN));
  CLEAR_BIT(USARTx->CR3, (USART_CR3_SCEN | USART_CR3_HDSEL | USART_CR3_IREN));
}

   
      
    

                                                         
      
    

   
                                                              
                                                               
                                 
                                  
    
__STATIC_INLINE uint32_t LL_USART_IsActiveFlag_PE(const USART_TypeDef *USARTx)
{
  return ((READ_BIT(USARTx->ISR, USART_ISR_PE) == (USART_ISR_PE)) ? 1UL : 0UL);
}

   
                                                               
                                                               
                                 
                                  
    
__STATIC_INLINE uint32_t LL_USART_IsActiveFlag_FE(const USART_TypeDef *USARTx)
{
  return ((READ_BIT(USARTx->ISR, USART_ISR_FE) == (USART_ISR_FE)) ? 1UL : 0UL);
}

   
                                                                      
                                                               
                                 
                                  
    
__STATIC_INLINE uint32_t LL_USART_IsActiveFlag_NE(const USART_TypeDef *USARTx)
{
  return ((READ_BIT(USARTx->ISR, USART_ISR_NE) == (USART_ISR_NE)) ? 1UL : 0UL);
}

   
                                                               
                                                                
                                 
                                  
    
__STATIC_INLINE uint32_t LL_USART_IsActiveFlag_ORE(const USART_TypeDef *USARTx)
{
  return ((READ_BIT(USARTx->ISR, USART_ISR_ORE) == (USART_ISR_ORE)) ? 1UL : 0UL);
}

   
                                                                    
                                                                 
                                 
                                  
    
__STATIC_INLINE uint32_t LL_USART_IsActiveFlag_IDLE(const USART_TypeDef *USARTx)
{
  return ((READ_BIT(USARTx->ISR, USART_ISR_IDLE) == (USART_ISR_IDLE)) ? 1UL : 0UL);
}

#if defined(USART_CR1_FIFOEN)
#define LL_USART_IsActiveFlag_RXNE  LL_USART_IsActiveFlag_RXNE_RXFNE                                      

   
                                                                                               
                                                                                   
                                                                  
                                                                       
                                 
                                  
    
__STATIC_INLINE uint32_t LL_USART_IsActiveFlag_RXNE_RXFNE(const USART_TypeDef *USARTx)
{
  return ((READ_BIT(USARTx->ISR, USART_ISR_RXNE_RXFNE) == (USART_ISR_RXNE_RXFNE)) ? 1UL : 0UL);
}

#else
   
                                                                              
                                                                 
                                 
                                  
    
__STATIC_INLINE uint32_t LL_USART_IsActiveFlag_RXNE(const USART_TypeDef *USARTx)
{
  return ((READ_BIT(USARTx->ISR, USART_ISR_RXNE) == (USART_ISR_RXNE)) ? 1UL : 0UL);
}

#endif                       
   
                                                                       
                                                               
                                 
                                  
    
__STATIC_INLINE uint32_t LL_USART_IsActiveFlag_TC(const USART_TypeDef *USARTx)
{
  return ((READ_BIT(USARTx->ISR, USART_ISR_TC) == (USART_ISR_TC)) ? 1UL : 0UL);
}

#if defined(USART_CR1_FIFOEN)
#define LL_USART_IsActiveFlag_TXE  LL_USART_IsActiveFlag_TXE_TXFNF                                      

   
                                                                                                        
                                                                                   
                                                                  
                                                                      
                                 
                                  
    
__STATIC_INLINE uint32_t LL_USART_IsActiveFlag_TXE_TXFNF(const USART_TypeDef *USARTx)
{
  return ((READ_BIT(USARTx->ISR, USART_ISR_TXE_TXFNF) == (USART_ISR_TXE_TXFNF)) ? 1UL : 0UL);
}

#else
   
                                                                              
                                                                
                                 
                                  
    
__STATIC_INLINE uint32_t LL_USART_IsActiveFlag_TXE(const USART_TypeDef *USARTx)
{
  return ((READ_BIT(USARTx->ISR, USART_ISR_TXE) == (USART_ISR_TXE)) ? 1UL : 0UL);
}

#endif                       
   
                                                                     
                                                                                  
                                                            
                                                                
                                 
                                  
    
__STATIC_INLINE uint32_t LL_USART_IsActiveFlag_LBD(const USART_TypeDef *USARTx)
{
  return ((READ_BIT(USARTx->ISR, USART_ISR_LBDF) == (USART_ISR_LBDF)) ? 1UL : 0UL);
}

   
                                                               
                                                                                     
                                                                              
                                                                 
                                 
                                  
    
__STATIC_INLINE uint32_t LL_USART_IsActiveFlag_nCTS(const USART_TypeDef *USARTx)
{
  return ((READ_BIT(USARTx->ISR, USART_ISR_CTSIF) == (USART_ISR_CTSIF)) ? 1UL : 0UL);
}

   
                                                     
                                                                                     
                                                                              
                                                                
                                 
                                  
    
__STATIC_INLINE uint32_t LL_USART_IsActiveFlag_CTS(const USART_TypeDef *USARTx)
{
  return ((READ_BIT(USARTx->ISR, USART_ISR_CTS) == (USART_ISR_CTS)) ? 1UL : 0UL);
}

   
                                                                   
                                                                
                                 
                                  
    
__STATIC_INLINE uint32_t LL_USART_IsActiveFlag_RTO(const USART_TypeDef *USARTx)
{
  return ((READ_BIT(USARTx->ISR, USART_ISR_RTOF) == (USART_ISR_RTOF)) ? 1UL : 0UL);
}

   
                                                              
                                                                                   
                                                                  
                                                                
                                 
                                  
    
__STATIC_INLINE uint32_t LL_USART_IsActiveFlag_EOB(const USART_TypeDef *USARTx)
{
  return ((READ_BIT(USARTx->ISR, USART_ISR_EOBF) == (USART_ISR_EOBF)) ? 1UL : 0UL);
}

#if defined(USART_CR2_SLVEN)
   
                                                                    
                                                                                        
                                                                       
                                                                
                                 
                                  
    
__STATIC_INLINE uint32_t LL_USART_IsActiveFlag_UDR(const USART_TypeDef *USARTx)
{
  return ((READ_BIT(USARTx->ISR, USART_ISR_UDR) == (USART_ISR_UDR)) ? 1UL : 0UL);
}

#endif                      
   
                                                                      
                                                                                                      
                                                                                 
                                                                 
                                 
                                  
    
__STATIC_INLINE uint32_t LL_USART_IsActiveFlag_ABRE(const USART_TypeDef *USARTx)
{
  return ((READ_BIT(USARTx->ISR, USART_ISR_ABRE) == (USART_ISR_ABRE)) ? 1UL : 0UL);
}

   
                                                                
                                                                                                      
                                                                                 
                                                                
                                 
                                  
    
__STATIC_INLINE uint32_t LL_USART_IsActiveFlag_ABR(const USART_TypeDef *USARTx)
{
  return ((READ_BIT(USARTx->ISR, USART_ISR_ABRF) == (USART_ISR_ABRF)) ? 1UL : 0UL);
}

   
                                                      
                                                                 
                                 
                                  
    
__STATIC_INLINE uint32_t LL_USART_IsActiveFlag_BUSY(const USART_TypeDef *USARTx)
{
  return ((READ_BIT(USARTx->ISR, USART_ISR_BUSY) == (USART_ISR_BUSY)) ? 1UL : 0UL);
}

   
                                                                 
                                                               
                                 
                                  
    
__STATIC_INLINE uint32_t LL_USART_IsActiveFlag_CM(const USART_TypeDef *USARTx)
{
  return ((READ_BIT(USARTx->ISR, USART_ISR_CMF) == (USART_ISR_CMF)) ? 1UL : 0UL);
}

   
                                                            
                                                                
                                 
                                  
    
__STATIC_INLINE uint32_t LL_USART_IsActiveFlag_SBK(const USART_TypeDef *USARTx)
{
  return ((READ_BIT(USARTx->ISR, USART_ISR_SBKF) == (USART_ISR_SBKF)) ? 1UL : 0UL);
}

   
                                                                                
                                                                
                                 
                                  
    
__STATIC_INLINE uint32_t LL_USART_IsActiveFlag_RWU(const USART_TypeDef *USARTx)
{
  return ((READ_BIT(USARTx->ISR, USART_ISR_RWU) == (USART_ISR_RWU)) ? 1UL : 0UL);
}

   
                                                                        
                                                                                              
                                                                               
                                                                 
                                 
                                  
    
__STATIC_INLINE uint32_t LL_USART_IsActiveFlag_WKUP(const USART_TypeDef *USARTx)
{
  return ((READ_BIT(USARTx->ISR, USART_ISR_WUF) == (USART_ISR_WUF)) ? 1UL : 0UL);
}

   
                                                                             
                                                                  
                                 
                                  
    
__STATIC_INLINE uint32_t LL_USART_IsActiveFlag_TEACK(const USART_TypeDef *USARTx)
{
  return ((READ_BIT(USARTx->ISR, USART_ISR_TEACK) == (USART_ISR_TEACK)) ? 1UL : 0UL);
}

   
                                                                            
                                                                  
                                 
                                  
    
__STATIC_INLINE uint32_t LL_USART_IsActiveFlag_REACK(const USART_TypeDef *USARTx)
{
  return ((READ_BIT(USARTx->ISR, USART_ISR_REACK) == (USART_ISR_REACK)) ? 1UL : 0UL);
}

#if defined(USART_CR1_FIFOEN)
   
                                                               
                                                                                   
                                                                  
                                                                 
                                 
                                  
    
__STATIC_INLINE uint32_t LL_USART_IsActiveFlag_TXFE(const USART_TypeDef *USARTx)
{
  return ((READ_BIT(USARTx->ISR, USART_ISR_TXFE) == (USART_ISR_TXFE)) ? 1UL : 0UL);
}

   
                                                              
                                                                                   
                                                                  
                                                                 
                                 
                                  
    
__STATIC_INLINE uint32_t LL_USART_IsActiveFlag_RXFF(const USART_TypeDef *USARTx)
{
  return ((READ_BIT(USARTx->ISR, USART_ISR_RXFF) == (USART_ISR_RXFF)) ? 1UL : 0UL);
}

#endif                       
#if defined(USART_TCBGT_SUPPORT)
                                                                                               
   
                                                                                             
                                                                  
                                 
                                  
    
__STATIC_INLINE uint32_t LL_USART_IsActiveFlag_TCBGT(const USART_TypeDef *USARTx)
{
  return ((READ_BIT(USARTx->ISR, USART_ISR_TCBGT) == (USART_ISR_TCBGT)) ? 1UL : 0UL);
}

#endif                          
#if defined(USART_CR1_FIFOEN)
   
                                                                   
                                                                                   
                                                                  
                                                                 
                                 
                                  
    
__STATIC_INLINE uint32_t LL_USART_IsActiveFlag_TXFT(const USART_TypeDef *USARTx)
{
  return ((READ_BIT(USARTx->ISR, USART_ISR_TXFT) == (USART_ISR_TXFT)) ? 1UL : 0UL);
}

   
                                                                   
                                                                                   
                                                                  
                                                                 
                                 
                                  
    
__STATIC_INLINE uint32_t LL_USART_IsActiveFlag_RXFT(const USART_TypeDef *USARTx)
{
  return ((READ_BIT(USARTx->ISR, USART_ISR_RXFT) == (USART_ISR_RXFT)) ? 1UL : 0UL);
}

#endif                       
   
                                   
                                                            
                                 
                
    
__STATIC_INLINE void LL_USART_ClearFlag_PE(USART_TypeDef *USARTx)
{
  WRITE_REG(USARTx->ICR, USART_ICR_PECF);
}

   
                                    
                                                            
                                 
                
    
__STATIC_INLINE void LL_USART_ClearFlag_FE(USART_TypeDef *USARTx)
{
  WRITE_REG(USARTx->ICR, USART_ICR_FECF);
}

   
                                           
                                                            
                                 
                
    
__STATIC_INLINE void LL_USART_ClearFlag_NE(USART_TypeDef *USARTx)
{
  WRITE_REG(USARTx->ICR, USART_ICR_NECF);
}

   
                                    
                                                             
                                 
                
    
__STATIC_INLINE void LL_USART_ClearFlag_ORE(USART_TypeDef *USARTx)
{
  WRITE_REG(USARTx->ICR, USART_ICR_ORECF);
}

   
                                         
                                                              
                                 
                
    
__STATIC_INLINE void LL_USART_ClearFlag_IDLE(USART_TypeDef *USARTx)
{
  WRITE_REG(USARTx->ICR, USART_ICR_IDLECF);
}

#if defined(USART_CR1_FIFOEN)
   
                                    
                                                                                   
                                                                  
                                                              
                                 
                
    
__STATIC_INLINE void LL_USART_ClearFlag_TXFE(USART_TypeDef *USARTx)
{
  WRITE_REG(USARTx->ICR, USART_ICR_TXFECF);
}

#endif                       
   
                                            
                                                            
                                 
                
    
__STATIC_INLINE void LL_USART_ClearFlag_TC(USART_TypeDef *USARTx)
{
  WRITE_REG(USARTx->ICR, USART_ICR_TCCF);
}

#if defined(USART_TCBGT_SUPPORT)
                                                                                               
   
                                                                        
                                                               
                                 
                
    
__STATIC_INLINE void LL_USART_ClearFlag_TCBGT(USART_TypeDef *USARTx)
{
  WRITE_REG(USARTx->ICR, USART_ICR_TCBGTCF);
}
#endif                          

   
                                          
                                                                                  
                                                            
                                                             
                                 
                
    
__STATIC_INLINE void LL_USART_ClearFlag_LBD(USART_TypeDef *USARTx)
{
  WRITE_REG(USARTx->ICR, USART_ICR_LBDCF);
}

   
                                    
                                                                                     
                                                                              
                                                              
                                 
                
    
__STATIC_INLINE void LL_USART_ClearFlag_nCTS(USART_TypeDef *USARTx)
{
  WRITE_REG(USARTx->ICR, USART_ICR_CTSCF);
}

   
                                        
                                                             
                                 
                
    
__STATIC_INLINE void LL_USART_ClearFlag_RTO(USART_TypeDef *USARTx)
{
  WRITE_REG(USARTx->ICR, USART_ICR_RTOCF);
}

   
                                   
                                                                                   
                                                                  
                                                             
                                 
                
    
__STATIC_INLINE void LL_USART_ClearFlag_EOB(USART_TypeDef *USARTx)
{
  WRITE_REG(USARTx->ICR, USART_ICR_EOBCF);
}

#if defined(USART_CR2_SLVEN)
   
                                         
                                                                                        
                                                                       
                                                             
                                 
                
    
__STATIC_INLINE void LL_USART_ClearFlag_UDR(USART_TypeDef *USARTx)
{
  WRITE_REG(USARTx->ICR, USART_ICR_UDRCF);
}

#endif                      
   
                                      
                                                            
                                 
                
    
__STATIC_INLINE void LL_USART_ClearFlag_CM(USART_TypeDef *USARTx)
{
  WRITE_REG(USARTx->ICR, USART_ICR_CMCF);
}

   
                                             
                                                                                              
                                                                               
                                                              
                                 
                
    
__STATIC_INLINE void LL_USART_ClearFlag_WKUP(USART_TypeDef *USARTx)
{
  WRITE_REG(USARTx->ICR, USART_ICR_WUCF);
}

   
      
    

                                                     
      
    

   
                                 
                                                             
                                 
                
    
__STATIC_INLINE void LL_USART_EnableIT_IDLE(USART_TypeDef *USARTx)
{
  ATOMIC_SET_BIT(USARTx->CR1, USART_CR1_IDLEIE);
}

#if defined(USART_CR1_FIFOEN)
#define LL_USART_EnableIT_RXNE  LL_USART_EnableIT_RXNE_RXFNE                                      

   
                                                               
                                                                                   
                                                                  
                                                                   
                                 
                
    
__STATIC_INLINE void LL_USART_EnableIT_RXNE_RXFNE(USART_TypeDef *USARTx)
{
  ATOMIC_SET_BIT(USARTx->CR1, USART_CR1_RXNEIE_RXFNEIE);
}

#else
   
                                         
                                                             
                                 
                
    
__STATIC_INLINE void LL_USART_EnableIT_RXNE(USART_TypeDef *USARTx)
{
  ATOMIC_SET_BIT(USARTx->CR1, USART_CR1_RXNEIE);
}

#endif                       
   
                                                  
                                                           
                                 
                
    
__STATIC_INLINE void LL_USART_EnableIT_TC(USART_TypeDef *USARTx)
{
  ATOMIC_SET_BIT(USARTx->CR1, USART_CR1_TCIE);
}

#if defined(USART_CR1_FIFOEN)
#define LL_USART_EnableIT_TXE  LL_USART_EnableIT_TXE_TXFNF                                      

   
                                                          
                                                                                   
                                                                  
                                                                  
                                 
                
    
__STATIC_INLINE void LL_USART_EnableIT_TXE_TXFNF(USART_TypeDef *USARTx)
{
  ATOMIC_SET_BIT(USARTx->CR1, USART_CR1_TXEIE_TXFNFIE);
}

#else
   
                                     
                                                            
                                 
                
    
__STATIC_INLINE void LL_USART_EnableIT_TXE(USART_TypeDef *USARTx)
{
  ATOMIC_SET_BIT(USARTx->CR1, USART_CR1_TXEIE);
}

#endif                       
   
                                         
                                                           
                                 
                
    
__STATIC_INLINE void LL_USART_EnableIT_PE(USART_TypeDef *USARTx)
{
  ATOMIC_SET_BIT(USARTx->CR1, USART_CR1_PEIE);
}

   
                                            
                                                           
                                 
                
    
__STATIC_INLINE void LL_USART_EnableIT_CM(USART_TypeDef *USARTx)
{
  ATOMIC_SET_BIT(USARTx->CR1, USART_CR1_CMIE);
}

   
                                             
                                                            
                                 
                
    
__STATIC_INLINE void LL_USART_EnableIT_RTO(USART_TypeDef *USARTx)
{
  ATOMIC_SET_BIT(USARTx->CR1, USART_CR1_RTOIE);
}

   
                                         
                                                                                   
                                                                  
                                                            
                                 
                
    
__STATIC_INLINE void LL_USART_EnableIT_EOB(USART_TypeDef *USARTx)
{
  ATOMIC_SET_BIT(USARTx->CR1, USART_CR1_EOBIE);
}

#if defined(USART_CR1_FIFOEN)
   
                                          
                                                                                   
                                                                  
                                                             
                                 
                
    
__STATIC_INLINE void LL_USART_EnableIT_TXFE(USART_TypeDef *USARTx)
{
  ATOMIC_SET_BIT(USARTx->CR1, USART_CR1_TXFEIE);
}

   
                                         
                                                             
                                 
                
    
__STATIC_INLINE void LL_USART_EnableIT_RXFF(USART_TypeDef *USARTx)
{
  ATOMIC_SET_BIT(USARTx->CR1, USART_CR1_RXFFIE);
}

#endif                       
   
                                                
                                                                                  
                                                            
                                                            
                                 
                
    
__STATIC_INLINE void LL_USART_EnableIT_LBD(USART_TypeDef *USARTx)
{
  SET_BIT(USARTx->CR2, USART_CR2_LBDIE);
}

   
                                  
                                                                                                      
                                                                                                  
                                       
                                                                                                 
                                                              
                                 
                
    
__STATIC_INLINE void LL_USART_EnableIT_ERROR(USART_TypeDef *USARTx)
{
  ATOMIC_SET_BIT(USARTx->CR3, USART_CR3_EIE);
}

   
                                
                                                                                     
                                                                              
                                                            
                                 
                
    
__STATIC_INLINE void LL_USART_EnableIT_CTS(USART_TypeDef *USARTx)
{
  ATOMIC_SET_BIT(USARTx->CR3, USART_CR3_CTSIE);
}

   
                                                   
                                                                                              
                                                                               
                                                             
                                 
                
    
__STATIC_INLINE void LL_USART_EnableIT_WKUP(USART_TypeDef *USARTx)
{
  ATOMIC_SET_BIT(USARTx->CR3, USART_CR3_WUFIE);
}

#if defined(USART_CR1_FIFOEN)
   
                                              
                                                                                   
                                                                  
                                                             
                                 
                
    
__STATIC_INLINE void LL_USART_EnableIT_TXFT(USART_TypeDef *USARTx)
{
  ATOMIC_SET_BIT(USARTx->CR3, USART_CR3_TXFTIE);
}

#endif                       
#if defined(USART_TCBGT_SUPPORT)
                                                                                               
   
                                                                              
                                                                                   
                                                                  
                                                              
                                 
                
    
__STATIC_INLINE void LL_USART_EnableIT_TCBGT(USART_TypeDef *USARTx)
{
  ATOMIC_SET_BIT(USARTx->CR3, USART_CR3_TCBGTIE);
}
#endif                          

#if defined(USART_CR1_FIFOEN)
   
                                              
                                                                                   
                                                                  
                                                             
                                 
                
    
__STATIC_INLINE void LL_USART_EnableIT_RXFT(USART_TypeDef *USARTx)
{
  ATOMIC_SET_BIT(USARTx->CR3, USART_CR3_RXFTIE);
}

#endif                       
   
                                  
                                                              
                                 
                
    
__STATIC_INLINE void LL_USART_DisableIT_IDLE(USART_TypeDef *USARTx)
{
  ATOMIC_CLEAR_BIT(USARTx->CR1, USART_CR1_IDLEIE);
}

#if defined(USART_CR1_FIFOEN)
#define LL_USART_DisableIT_RXNE  LL_USART_DisableIT_RXNE_RXFNE                                      

   
                                                                
                                                                                   
                                                                  
                                                                    
                                 
                
    
__STATIC_INLINE void LL_USART_DisableIT_RXNE_RXFNE(USART_TypeDef *USARTx)
{
  ATOMIC_CLEAR_BIT(USARTx->CR1, USART_CR1_RXNEIE_RXFNEIE);
}

#else
   
                                          
                                                              
                                 
                
    
__STATIC_INLINE void LL_USART_DisableIT_RXNE(USART_TypeDef *USARTx)
{
  ATOMIC_CLEAR_BIT(USARTx->CR1, USART_CR1_RXNEIE);
}

#endif                       
   
                                                   
                                                            
                                 
                
    
__STATIC_INLINE void LL_USART_DisableIT_TC(USART_TypeDef *USARTx)
{
  ATOMIC_CLEAR_BIT(USARTx->CR1, USART_CR1_TCIE);
}

#if defined(USART_CR1_FIFOEN)
#define LL_USART_DisableIT_TXE  LL_USART_DisableIT_TXE_TXFNF                                      

   
                                                           
                                                                                   
                                                                  
                                                                  
                                 
                
    
__STATIC_INLINE void LL_USART_DisableIT_TXE_TXFNF(USART_TypeDef *USARTx)
{
  ATOMIC_CLEAR_BIT(USARTx->CR1, USART_CR1_TXEIE_TXFNFIE);
}

#else
   
                                      
                                                             
                                 
                
    
__STATIC_INLINE void LL_USART_DisableIT_TXE(USART_TypeDef *USARTx)
{
  ATOMIC_CLEAR_BIT(USARTx->CR1, USART_CR1_TXEIE);
}

#endif                       
   
                                          
                                                            
                                 
                
    
__STATIC_INLINE void LL_USART_DisableIT_PE(USART_TypeDef *USARTx)
{
  ATOMIC_CLEAR_BIT(USARTx->CR1, USART_CR1_PEIE);
}

   
                                             
                                                            
                                 
                
    
__STATIC_INLINE void LL_USART_DisableIT_CM(USART_TypeDef *USARTx)
{
  ATOMIC_CLEAR_BIT(USARTx->CR1, USART_CR1_CMIE);
}

   
                                              
                                                             
                                 
                
    
__STATIC_INLINE void LL_USART_DisableIT_RTO(USART_TypeDef *USARTx)
{
  ATOMIC_CLEAR_BIT(USARTx->CR1, USART_CR1_RTOIE);
}

   
                                          
                                                                                   
                                                                  
                                                             
                                 
                
    
__STATIC_INLINE void LL_USART_DisableIT_EOB(USART_TypeDef *USARTx)
{
  ATOMIC_CLEAR_BIT(USARTx->CR1, USART_CR1_EOBIE);
}

#if defined(USART_CR1_FIFOEN)
   
                                           
                                                                                   
                                                                  
                                                              
                                 
                
    
__STATIC_INLINE void LL_USART_DisableIT_TXFE(USART_TypeDef *USARTx)
{
  ATOMIC_CLEAR_BIT(USARTx->CR1, USART_CR1_TXFEIE);
}

   
                                          
                                                                                   
                                                                  
                                                              
                                 
                
    
__STATIC_INLINE void LL_USART_DisableIT_RXFF(USART_TypeDef *USARTx)
{
  ATOMIC_CLEAR_BIT(USARTx->CR1, USART_CR1_RXFFIE);
}

#endif                       
   
                                                 
                                                                                  
                                                            
                                                             
                                 
                
    
__STATIC_INLINE void LL_USART_DisableIT_LBD(USART_TypeDef *USARTx)
{
  CLEAR_BIT(USARTx->CR2, USART_CR2_LBDIE);
}

   
                                   
                                                                                                      
                                                                                                  
                                       
                                                                                                 
                                                               
                                 
                
    
__STATIC_INLINE void LL_USART_DisableIT_ERROR(USART_TypeDef *USARTx)
{
  ATOMIC_CLEAR_BIT(USARTx->CR3, USART_CR3_EIE);
}

   
                                 
                                                                                     
                                                                              
                                                             
                                 
                
    
__STATIC_INLINE void LL_USART_DisableIT_CTS(USART_TypeDef *USARTx)
{
  ATOMIC_CLEAR_BIT(USARTx->CR3, USART_CR3_CTSIE);
}

   
                                                    
                                                                                              
                                                                               
                                                              
                                 
                
    
__STATIC_INLINE void LL_USART_DisableIT_WKUP(USART_TypeDef *USARTx)
{
  ATOMIC_CLEAR_BIT(USARTx->CR3, USART_CR3_WUFIE);
}

#if defined(USART_CR1_FIFOEN)
   
                                               
                                                                                   
                                                                  
                                                              
                                 
                
    
__STATIC_INLINE void LL_USART_DisableIT_TXFT(USART_TypeDef *USARTx)
{
  ATOMIC_CLEAR_BIT(USARTx->CR3, USART_CR3_TXFTIE);
}

#endif                       
#if defined(USART_TCBGT_SUPPORT)
                                                                                               
   
                                                                               
                                                                                   
                                                                  
                                                               
                                 
                
    
__STATIC_INLINE void LL_USART_DisableIT_TCBGT(USART_TypeDef *USARTx)
{
  ATOMIC_CLEAR_BIT(USARTx->CR3, USART_CR3_TCBGTIE);
}
#endif                          

#if defined(USART_CR1_FIFOEN)
   
                                               
                                                                                   
                                                                  
                                                              
                                 
                
    
__STATIC_INLINE void LL_USART_DisableIT_RXFT(USART_TypeDef *USARTx)
{
  ATOMIC_CLEAR_BIT(USARTx->CR3, USART_CR3_RXFTIE);
}

#endif                       
   
                                                                             
                                                                
                                 
                                  
    
__STATIC_INLINE uint32_t LL_USART_IsEnabledIT_IDLE(const USART_TypeDef *USARTx)
{
  return ((READ_BIT(USARTx->CR1, USART_CR1_IDLEIE) == (USART_CR1_IDLEIE)) ? 1UL : 0UL);
}

#if defined(USART_CR1_FIFOEN)
#define LL_USART_IsEnabledIT_RXNE  LL_USART_IsEnabledIT_RXNE_RXFNE                                      

   
                                                                                                         
                                                                                   
                                                                  
                                                                      
                                 
                                  
    
__STATIC_INLINE uint32_t LL_USART_IsEnabledIT_RXNE_RXFNE(const USART_TypeDef *USARTx)
{
  return ((READ_BIT(USARTx->CR1, USART_CR1_RXNEIE_RXFNEIE) == (USART_CR1_RXNEIE_RXFNEIE)) ? 1UL : 0UL);
}

#else
   
                                                                             
                                                                
                                 
                                  
    
__STATIC_INLINE uint32_t LL_USART_IsEnabledIT_RXNE(const USART_TypeDef *USARTx)
{
  return ((READ_BIT(USARTx->CR1, USART_CR1_RXNEIE) == (USART_CR1_RXNEIE)) ? 1U : 0U);
}

#endif                       
   
                                                                                      
                                                              
                                 
                                  
    
__STATIC_INLINE uint32_t LL_USART_IsEnabledIT_TC(const USART_TypeDef *USARTx)
{
  return ((READ_BIT(USARTx->CR1, USART_CR1_TCIE) == (USART_CR1_TCIE)) ? 1UL : 0UL);
}

#if defined(USART_CR1_FIFOEN)
#define LL_USART_IsEnabledIT_TXE  LL_USART_IsEnabledIT_TXE_TXFNF                                      

   
                                                                                                   
                                                                                   
                                                                  
                                                                     
                                 
                                  
    
__STATIC_INLINE uint32_t LL_USART_IsEnabledIT_TXE_TXFNF(const USART_TypeDef *USARTx)
{
  return ((READ_BIT(USARTx->CR1, USART_CR1_TXEIE_TXFNFIE) == (USART_CR1_TXEIE_TXFNFIE)) ? 1UL : 0UL);
}

#else
   
                                                                         
                                                               
                                 
                                  
    
__STATIC_INLINE uint32_t LL_USART_IsEnabledIT_TXE(const USART_TypeDef *USARTx)
{
  return ((READ_BIT(USARTx->CR1, USART_CR1_TXEIE) == (USART_CR1_TXEIE)) ? 1U : 0U);
}

#endif                       
   
                                                                             
                                                              
                                 
                                  
    
__STATIC_INLINE uint32_t LL_USART_IsEnabledIT_PE(const USART_TypeDef *USARTx)
{
  return ((READ_BIT(USARTx->CR1, USART_CR1_PEIE) == (USART_CR1_PEIE)) ? 1UL : 0UL);
}

   
                                                                                
                                                              
                                 
                                  
    
__STATIC_INLINE uint32_t LL_USART_IsEnabledIT_CM(const USART_TypeDef *USARTx)
{
  return ((READ_BIT(USARTx->CR1, USART_CR1_CMIE) == (USART_CR1_CMIE)) ? 1UL : 0UL);
}

   
                                                                                 
                                                               
                                 
                                  
    
__STATIC_INLINE uint32_t LL_USART_IsEnabledIT_RTO(const USART_TypeDef *USARTx)
{
  return ((READ_BIT(USARTx->CR1, USART_CR1_RTOIE) == (USART_CR1_RTOIE)) ? 1UL : 0UL);
}

   
                                                                             
                                                                                   
                                                                  
                                                               
                                 
                                  
    
__STATIC_INLINE uint32_t LL_USART_IsEnabledIT_EOB(const USART_TypeDef *USARTx)
{
  return ((READ_BIT(USARTx->CR1, USART_CR1_EOBIE) == (USART_CR1_EOBIE)) ? 1UL : 0UL);
}

#if defined(USART_CR1_FIFOEN)
   
                                                                             
                                                                                   
                                                                  
                                                                
                                 
                                  
    
__STATIC_INLINE uint32_t LL_USART_IsEnabledIT_TXFE(const USART_TypeDef *USARTx)
{
  return ((READ_BIT(USARTx->CR1, USART_CR1_TXFEIE) == (USART_CR1_TXFEIE)) ? 1UL : 0UL);
}

   
                                                                            
                                                                                   
                                                                  
                                                                
                                 
                                  
    
__STATIC_INLINE uint32_t LL_USART_IsEnabledIT_RXFF(const USART_TypeDef *USARTx)
{
  return ((READ_BIT(USARTx->CR1, USART_CR1_RXFFIE) == (USART_CR1_RXFFIE)) ? 1UL : 0UL);
}

#endif                       
   
                                                                                    
                                                                                  
                                                            
                                                               
                                 
                                  
    
__STATIC_INLINE uint32_t LL_USART_IsEnabledIT_LBD(const USART_TypeDef *USARTx)
{
  return ((READ_BIT(USARTx->CR2, USART_CR2_LBDIE) == (USART_CR2_LBDIE)) ? 1UL : 0UL);
}

   
                                                                      
                                                                 
                                 
                                  
    
__STATIC_INLINE uint32_t LL_USART_IsEnabledIT_ERROR(const USART_TypeDef *USARTx)
{
  return ((READ_BIT(USARTx->CR3, USART_CR3_EIE) == (USART_CR3_EIE)) ? 1UL : 0UL);
}

   
                                                                    
                                                                                     
                                                                              
                                                               
                                 
                                  
    
__STATIC_INLINE uint32_t LL_USART_IsEnabledIT_CTS(const USART_TypeDef *USARTx)
{
  return ((READ_BIT(USARTx->CR3, USART_CR3_CTSIE) == (USART_CR3_CTSIE)) ? 1UL : 0UL);
}

   
                                                                                       
                                                                                              
                                                                               
                                                                
                                 
                                  
    
__STATIC_INLINE uint32_t LL_USART_IsEnabledIT_WKUP(const USART_TypeDef *USARTx)
{
  return ((READ_BIT(USARTx->CR3, USART_CR3_WUFIE) == (USART_CR3_WUFIE)) ? 1UL : 0UL);
}

#if defined(USART_CR1_FIFOEN)
   
                                                                             
                                                                                   
                                                                  
                                                                
                                 
                                  
    
__STATIC_INLINE uint32_t LL_USART_IsEnabledIT_TXFT(const USART_TypeDef *USARTx)
{
  return ((READ_BIT(USARTx->CR3, USART_CR3_TXFTIE) == (USART_CR3_TXFTIE)) ? 1UL : 0UL);
}

#endif                       
#if defined(USART_TCBGT_SUPPORT)
                                                                                               
   
                                                                                                            
                                                                                   
                                                                  
                                                                 
                                 
                                  
    
__STATIC_INLINE uint32_t LL_USART_IsEnabledIT_TCBGT(const USART_TypeDef *USARTx)
{
  return ((READ_BIT(USARTx->CR3, USART_CR3_TCBGTIE) == (USART_CR3_TCBGTIE)) ? 1UL : 0UL);
}
#endif                          

#if defined(USART_CR1_FIFOEN)
   
                                                                             
                                                                                   
                                                                  
                                                                
                                 
                                  
    
__STATIC_INLINE uint32_t LL_USART_IsEnabledIT_RXFT(const USART_TypeDef *USARTx)
{
  return ((READ_BIT(USARTx->CR3, USART_CR3_RXFTIE) == (USART_CR3_RXFTIE)) ? 1UL : 0UL);
}

#endif                       
   
      
    

                                                       
      
    

   
                                         
                                                               
                                 
                
    
__STATIC_INLINE void LL_USART_EnableDMAReq_RX(USART_TypeDef *USARTx)
{
  ATOMIC_SET_BIT(USARTx->CR3, USART_CR3_DMAR);
}

   
                                          
                                                                
                                 
                
    
__STATIC_INLINE void LL_USART_DisableDMAReq_RX(USART_TypeDef *USARTx)
{
  ATOMIC_CLEAR_BIT(USARTx->CR3, USART_CR3_DMAR);
}

   
                                                      
                                                                  
                                 
                                  
    
__STATIC_INLINE uint32_t LL_USART_IsEnabledDMAReq_RX(const USART_TypeDef *USARTx)
{
  return ((READ_BIT(USARTx->CR3, USART_CR3_DMAR) == (USART_CR3_DMAR)) ? 1UL : 0UL);
}

   
                                            
                                                               
                                 
                
    
__STATIC_INLINE void LL_USART_EnableDMAReq_TX(USART_TypeDef *USARTx)
{
  ATOMIC_SET_BIT(USARTx->CR3, USART_CR3_DMAT);
}

   
                                             
                                                                
                                 
                
    
__STATIC_INLINE void LL_USART_DisableDMAReq_TX(USART_TypeDef *USARTx)
{
  ATOMIC_CLEAR_BIT(USARTx->CR3, USART_CR3_DMAT);
}

   
                                                         
                                                                  
                                 
                                  
    
__STATIC_INLINE uint32_t LL_USART_IsEnabledDMAReq_TX(const USART_TypeDef *USARTx)
{
  return ((READ_BIT(USARTx->CR3, USART_CR3_DMAT) == (USART_CR3_DMAT)) ? 1UL : 0UL);
}

   
                                                   
                                                                     
                                 
                
    
__STATIC_INLINE void LL_USART_EnableDMADeactOnRxErr(USART_TypeDef *USARTx)
{
  SET_BIT(USARTx->CR3, USART_CR3_DDRE);
}

   
                                                    
                                                                      
                                 
                
    
__STATIC_INLINE void LL_USART_DisableDMADeactOnRxErr(USART_TypeDef *USARTx)
{
  CLEAR_BIT(USARTx->CR3, USART_CR3_DDRE);
}

   
                                                                    
                                                                        
                                 
                                  
    
__STATIC_INLINE uint32_t LL_USART_IsEnabledDMADeactOnRxErr(const USART_TypeDef *USARTx)
{
  return ((READ_BIT(USARTx->CR3, USART_CR3_DDRE) == (USART_CR3_DDRE)) ? 1UL : 0UL);
}

   
                                                               
                                                                
                                                              
                                 
                                                                        
                                                    
                                                   
                                    
    
__STATIC_INLINE uint32_t LL_USART_DMA_GetRegAddr(const USART_TypeDef *USARTx, uint32_t Direction)
{
  uint32_t data_reg_addr;

  if (Direction == LL_USART_DMA_REG_DATA_TRANSMIT)
  {
                                        
    data_reg_addr = (uint32_t) &(USARTx->TDR);
  }
  else
  {
                                        
    data_reg_addr = (uint32_t) &(USARTx->RDR);
  }

  return data_reg_addr;
}

   
      
    

                                                         
      
    

   
                                                                    
                                                            
                                 
                                                         
    
__STATIC_INLINE uint8_t LL_USART_ReceiveData8(const USART_TypeDef *USARTx)
{
  return (uint8_t)(READ_BIT(USARTx->RDR, USART_RDR_RDR) & 0xFFU);
}

   
                                                                    
                                                            
                                 
                                                          
    
__STATIC_INLINE uint16_t LL_USART_ReceiveData9(const USART_TypeDef *USARTx)
{
  return (uint16_t)(READ_BIT(USARTx->RDR, USART_RDR_RDR));
}

   
                                                                            
                                                             
                                 
                                                         
                
    
__STATIC_INLINE void LL_USART_TransmitData8(USART_TypeDef *USARTx, uint8_t Value)
{
  USARTx->TDR = Value;
}

   
                                                                            
                                                             
                                 
                                                          
                
    
__STATIC_INLINE void LL_USART_TransmitData9(USART_TypeDef *USARTx, uint16_t Value)
{
  USARTx->TDR = (uint16_t)(Value & 0x1FFUL);
}

   
      
    

                                             
      
    

   
                                                                                  
                                                                                                      
                                                                                 
                                                                   
                                 
                
    
__STATIC_INLINE void LL_USART_RequestAutoBaudRate(USART_TypeDef *USARTx)
{
  SET_BIT(USARTx->RQR, (uint16_t)USART_RQR_ABRRQ);
}

   
                                 
                                                                   
                                 
                
    
__STATIC_INLINE void LL_USART_RequestBreakSending(USART_TypeDef *USARTx)
{
  SET_BIT(USARTx->RQR, (uint16_t)USART_RQR_SBKRQ);
}

   
                                                       
                                                                    
                                 
                
    
__STATIC_INLINE void LL_USART_RequestEnterMuteMode(USART_TypeDef *USARTx)
{
  SET_BIT(USARTx->RQR, (uint16_t)USART_RQR_MMRQ);
}

   
                      
                                                 
                                                                                   
                                                                  
                                                                                          
                      
       
                                        
        
                                                                  
                                 
                
    
__STATIC_INLINE void LL_USART_RequestRxDataFlush(USART_TypeDef *USARTx)
{
  SET_BIT(USARTx->RQR, (uint16_t)USART_RQR_RXFRQ);
}

   
                      
                                                  
                                                                                   
                                                                  
       
                                         
        
                                                                  
                                 
                
    
__STATIC_INLINE void LL_USART_RequestTxDataFlush(USART_TypeDef *USARTx)
{
  SET_BIT(USARTx->RQR, (uint16_t)USART_RQR_TXFRQ);
}

   
      
    

#if defined(USE_FULL_LL_DRIVER)
                                                                             
      
    
ErrorStatus LL_USART_DeInit(const USART_TypeDef *USARTx);
ErrorStatus LL_USART_Init(USART_TypeDef *USARTx, const LL_USART_InitTypeDef *USART_InitStruct);
void        LL_USART_StructInit(LL_USART_InitTypeDef *USART_InitStruct);
ErrorStatus LL_USART_ClockInit(USART_TypeDef *USARTx, const LL_USART_ClockInitTypeDef *USART_ClockInitStruct);
void        LL_USART_ClockStructInit(LL_USART_ClockInitTypeDef *USART_ClockInitStruct);
   
      
    
#endif                         

   
      
    

   
      
    

#endif                                                   

   
      
    

#ifdef __cplusplus
}
#endif

#endif                           

