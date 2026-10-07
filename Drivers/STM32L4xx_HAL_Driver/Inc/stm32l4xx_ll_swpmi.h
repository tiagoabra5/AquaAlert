/**
  ******************************************************************************
  * @file    stm32l4xx_ll_swpmi.h
  * @author  MCD Application Team
  * @brief   Header file of SWPMI LL module.
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

                                                                                
#ifndef STM32L4xx_LL_SWPMI_H
#define STM32L4xx_LL_SWPMI_H

#ifdef __cplusplus
extern "C" {
#endif

                                                                                
#include "stm32l4xx.h"

                                   
      
    

#if defined(SWPMI1)

                            
      
    

                                                                                
                                                                                
                                                                                
                                                                                
#if defined(USE_FULL_LL_DRIVER)
                                                          
      
    
   
      
    
#endif                       

                                                                                
#if defined(USE_FULL_LL_DRIVER)
                                                            
      
    

   
                                            
    
typedef struct
{
  uint32_t VoltageClass;                                                
                                                                                                       

                                                                                             
                                                                                  

  uint32_t BitRatePrescaler;                                                  
                                                                                          
                                                         

                                                                                    
                                                                                    

                                                                                             
                                                                                      

  uint32_t TxBufferingMode;                                                       
                                                                                                      

                                                                                     
                                                                                              

  uint32_t RxBufferingMode;                                                    
                                                                                                      

                                                                                     
                                                                                           
} LL_SWPMI_InitTypeDef;

   
      
    
#endif                         

                                                                                
                                                                  
      
    

                                                        
                                                                             
      
    
#define LL_SWPMI_ICR_CRXBFF                SWPMI_ICR_CRXBFF                                            
#define LL_SWPMI_ICR_CTXBEF                SWPMI_ICR_CTXBEF                                            
#define LL_SWPMI_ICR_CRXBERF               SWPMI_ICR_CRXBERF                                           
#define LL_SWPMI_ICR_CRXOVRF               SWPMI_ICR_CRXOVRF                                           
#define LL_SWPMI_ICR_CTXUNRF               SWPMI_ICR_CTXUNRF                                           
#define LL_SWPMI_ICR_CTCF                  SWPMI_ICR_CTCF                                              
#define LL_SWPMI_ICR_CSRF                  SWPMI_ICR_CSRF                                              
   
      
    

                                                    
                                                                            
      
    
#define LL_SWPMI_ISR_RXBFF                 SWPMI_ISR_RXBFF                                             
#define LL_SWPMI_ISR_TXBEF                 SWPMI_ISR_TXBEF                                             
#define LL_SWPMI_ISR_RXBERF                SWPMI_ISR_RXBERF                                            
#define LL_SWPMI_ISR_RXOVRF                SWPMI_ISR_RXOVRF                                            
#define LL_SWPMI_ISR_TXUNRF                SWPMI_ISR_TXUNRF                                            
#define LL_SWPMI_ISR_RXNE                  SWPMI_ISR_RXNE                                              
#define LL_SWPMI_ISR_TXE                   SWPMI_ISR_TXE                                               
#define LL_SWPMI_ISR_TCF                   SWPMI_ISR_TCF                                               
#define LL_SWPMI_ISR_SRF                   SWPMI_ISR_SRF                                               
#define LL_SWPMI_ISR_SUSP                  SWPMI_ISR_SUSP                                              
#define LL_SWPMI_ISR_DEACTF                SWPMI_ISR_DEACTF                                            
   
      
    

                                       
                                                                                                 
      
    
#define LL_SWPMI_IER_SRIE                  SWPMI_IER_SRIE                                                    
#define LL_SWPMI_IER_TCIE                  SWPMI_IER_TCIE                                                    
#define LL_SWPMI_IER_TIE                   SWPMI_IER_TIE                                                     
#define LL_SWPMI_IER_RIE                   SWPMI_IER_RIE                                                     
#define LL_SWPMI_IER_TXUNRIE               SWPMI_IER_TXUNRIE                                                 
#define LL_SWPMI_IER_RXOVRIE               SWPMI_IER_RXOVRIE                                                 
#define LL_SWPMI_IER_RXBERIE               SWPMI_IER_RXBERIE                                                 
#define LL_SWPMI_IER_TXBEIE                SWPMI_IER_TXBEIE                                                  
#define LL_SWPMI_IER_RXBFIE                SWPMI_IER_RXBFIE                                                  
   
      
    

                                                   
      
    
#define LL_SWPMI_SW_BUFFER_RX_SINGLE ((uint32_t)0x00000000)                                                   
#define LL_SWPMI_SW_BUFFER_RX_MULTI  SWPMI_CR_RXMODE                                                          
   
      
    

                                                   
      
    
#define LL_SWPMI_SW_BUFFER_TX_SINGLE ((uint32_t)0x00000000)                                                      
#define LL_SWPMI_SW_BUFFER_TX_MULTI  SWPMI_CR_TXMODE                                                             
   
      
    

                                                     
      
    
#define LL_SWPMI_VOLTAGE_CLASS_C     ((uint32_t)0x00000000)                                                                           
#define LL_SWPMI_VOLTAGE_CLASS_B     SWPMI_OR_CLASS                                                                                   
   
      
    

                                                        
      
    
#define LL_SWPMI_DMA_REG_DATA_TRANSMIT     (uint32_t)0                                                                 
#define LL_SWPMI_DMA_REG_DATA_RECEIVE      (uint32_t)1                                                                 
   
      
    

   
      
    

                                                                                
                                                            
      
    

                                                                           
      
    

   
                                           
                                       
                                          
                                                         
                
    
#define LL_SWPMI_WriteReg(__INSTANCE__, __REG__, __VALUE__) WRITE_REG(__INSTANCE__->__REG__, (__VALUE__))

   
                                          
                                       
                                       
                          
    
#define LL_SWPMI_ReadReg(__INSTANCE__, __REG__) READ_REG(__INSTANCE__->__REG__)
   
      
    

                                                                    
      
    

   
                                                                                                                        
                                                                        
                                                                                         
                                                     
                                            
    
#define __LL_SWPMI_CALC_BITRATE_PRESCALER(__FSWP__, __FSWPCLK__)   ((uint32_t)(((__FSWPCLK__) / ((__FSWP__) * 4)) - 1))

   
      
    

   
      
    

                                                                                
                                                                  
      
    

                                                     
      
    

   
                                        
                                                                                 
                                                                
                                 
                                                                              
                                                  
                                                 
                
    
__STATIC_INLINE void LL_SWPMI_SetReceptionMode(SWPMI_TypeDef *SWPMIx, uint32_t RxBufferingMode)
{
  MODIFY_REG(SWPMIx->CR, SWPMI_CR_RXMODE, RxBufferingMode);
}

   
                                        
                                                                
                                 
                                                              
                                                  
                                                 
    
__STATIC_INLINE uint32_t LL_SWPMI_GetReceptionMode(const SWPMI_TypeDef *SWPMIx)
{
  return (uint32_t)(READ_BIT(SWPMIx->CR, SWPMI_CR_RXMODE));
}

   
                                           
                                                                                 
                                                                   
                                 
                                                                              
                                                  
                                                 
                
    
__STATIC_INLINE void LL_SWPMI_SetTransmissionMode(SWPMI_TypeDef *SWPMIx, uint32_t TxBufferingMode)
{
  MODIFY_REG(SWPMIx->CR, SWPMI_CR_TXMODE, TxBufferingMode);
}

   
                                           
                                                                   
                                 
                                                              
                                                  
                                                 
    
__STATIC_INLINE uint32_t LL_SWPMI_GetTransmissionMode(const SWPMI_TypeDef *SWPMIx)
{
  return (uint32_t)(READ_BIT(SWPMIx->CR, SWPMI_CR_TXMODE));
}

   
                                
                                                              
                                 
                
    
__STATIC_INLINE void LL_SWPMI_EnableLoopback(SWPMI_TypeDef *SWPMIx)
{
  SET_BIT(SWPMIx->CR, SWPMI_CR_LPBK);
}

   
                                 
                                                               
                                 
                
    
__STATIC_INLINE void LL_SWPMI_DisableLoopback(SWPMI_TypeDef *SWPMIx)
{
  CLEAR_BIT(SWPMIx->CR, SWPMI_CR_LPBK);
}

   
                                                                            
                                                                                    
                                                                                             
                                                                                        
                                        
                                                        
                                 
                
    
__STATIC_INLINE void LL_SWPMI_Activate(SWPMI_TypeDef *SWPMIx)
{
                                                                        
  CLEAR_BIT(SWPMIx->CR, SWPMI_CR_DEACT);

                     
  SET_BIT(SWPMIx->CR, SWPMI_CR_SWPACT);
}

   
                                                                    
                                                        
                                 
                                  
    
__STATIC_INLINE uint32_t LL_SWPMI_IsActivated(const SWPMI_TypeDef *SWPMIx)
{
  return ((READ_BIT(SWPMIx->CR, SWPMI_CR_SWPACT) == (SWPMI_CR_SWPACT)) ? 1UL : 0UL);
}

   
                                                                                    
                              
                                                          
                                 
                
    
__STATIC_INLINE void LL_SWPMI_Deactivate(SWPMI_TypeDef *SWPMIx)
{
  CLEAR_BIT(SWPMIx->CR, SWPMI_CR_SWPACT);
}

   
                                                                                            
                                          
                                                                   
                                 
                
    
__STATIC_INLINE void LL_SWPMI_RequestDeactivation(SWPMI_TypeDef *SWPMIx)
{
  SET_BIT(SWPMIx->CR, SWPMI_CR_DEACT);
}

   
                                                                                 
                                                                   
                                 
                                                                         
                
    
__STATIC_INLINE void LL_SWPMI_SetBitRatePrescaler(SWPMI_TypeDef *SWPMIx, uint32_t BitRatePrescaler)
{
  WRITE_REG(SWPMIx->BRR, BitRatePrescaler);
}

   
                                 
                                                                   
                                 
                                                        
    
__STATIC_INLINE uint32_t LL_SWPMI_GetBitRatePrescaler(const SWPMI_TypeDef *SWPMIx)
{
  return (uint32_t)(READ_BIT(SWPMIx->BRR, SWPMI_BRR_BR));
}

   
                                 
                                                               
                                 
                                                                           
                                              
                                              
                
    
__STATIC_INLINE void LL_SWPMI_SetVoltageClass(SWPMI_TypeDef *SWPMIx, uint32_t VoltageClass)
{
  MODIFY_REG(SWPMIx->OR, SWPMI_OR_CLASS, VoltageClass);
}

   
                                 
                                                               
                                 
                                                              
                                              
                                              
    
__STATIC_INLINE uint32_t LL_SWPMI_GetVoltageClass(const SWPMI_TypeDef *SWPMIx)
{
  return (uint32_t)(READ_BIT(SWPMIx->OR, SWPMI_OR_CLASS));
}

   
      
    

                                                         
      
    

   
                                                                                         
                                                                 
                                 
                                  
    
__STATIC_INLINE uint32_t LL_SWPMI_IsActiveFlag_RXBF(const SWPMI_TypeDef *SWPMIx)
{
  return ((READ_BIT(SWPMIx->ISR, SWPMI_ISR_RXBFF) == (SWPMI_ISR_RXBFF)) ? 1UL : 0UL);
}

   
                                                               
                                                                 
                                 
                                  
    
__STATIC_INLINE uint32_t LL_SWPMI_IsActiveFlag_TXBE(const SWPMI_TypeDef *SWPMIx)
{
  return ((READ_BIT(SWPMIx->ISR, SWPMI_ISR_TXBEF) == (SWPMI_ISR_TXBEF)) ? 1UL : 0UL);
}

   
                                                             
                                                                  
                                 
                                  
    
__STATIC_INLINE uint32_t LL_SWPMI_IsActiveFlag_RXBER(const SWPMI_TypeDef *SWPMIx)
{
  return ((READ_BIT(SWPMIx->ISR, SWPMI_ISR_RXBERF) == (SWPMI_ISR_RXBERF)) ? 1UL : 0UL);
}

   
                                                           
                                                                  
                                 
                                  
    
__STATIC_INLINE uint32_t LL_SWPMI_IsActiveFlag_RXOVR(const SWPMI_TypeDef *SWPMIx)
{
  return ((READ_BIT(SWPMIx->ISR, SWPMI_ISR_RXOVRF) == (SWPMI_ISR_RXOVRF)) ? 1UL : 0UL);
}

   
                                                                     
                                                                  
                                 
                                  
    
__STATIC_INLINE uint32_t LL_SWPMI_IsActiveFlag_TXUNR(const SWPMI_TypeDef *SWPMIx)
{
  return ((READ_BIT(SWPMIx->ISR, SWPMI_ISR_TXUNRF) == (SWPMI_ISR_TXUNRF)) ? 1UL : 0UL);
}

   
                                                                                          
                                                 
                                                                 
                                 
                                  
    
__STATIC_INLINE uint32_t LL_SWPMI_IsActiveFlag_RXNE(const SWPMI_TypeDef *SWPMIx)
{
  return ((READ_BIT(SWPMIx->ISR, SWPMI_ISR_RXNE) == (SWPMI_ISR_RXNE)) ? 1UL : 0UL);
}

   
                                                                                            
                                                                                               
                                                                
                                 
                                  
    
__STATIC_INLINE uint32_t LL_SWPMI_IsActiveFlag_TXE(const SWPMI_TypeDef *SWPMIx)
{
  return ((READ_BIT(SWPMIx->ISR, SWPMI_ISR_TXE) == (SWPMI_ISR_TXE)) ? 1UL : 0UL);
}

   
                                                                                         
                               
                                                               
                                 
                                  
    
__STATIC_INLINE uint32_t LL_SWPMI_IsActiveFlag_TC(const SWPMI_TypeDef *SWPMIx)
{
  return ((READ_BIT(SWPMIx->ISR, SWPMI_ISR_TCF) == (SWPMI_ISR_TCF)) ? 1UL : 0UL);
}

   
                                                                                           
                 
                                                               
                                 
                                  
    
__STATIC_INLINE uint32_t LL_SWPMI_IsActiveFlag_SR(const SWPMI_TypeDef *SWPMIx)
{
  return ((READ_BIT(SWPMIx->ISR, SWPMI_ISR_SRF) == (SWPMI_ISR_SRF)) ? 1UL : 0UL);
}

   
                                                                 
                                                                 
                                 
                                  
    
__STATIC_INLINE uint32_t LL_SWPMI_IsActiveFlag_SUSP(const SWPMI_TypeDef *SWPMIx)
{
  return ((READ_BIT(SWPMIx->ISR, SWPMI_ISR_SUSP) == (SWPMI_ISR_SUSP)) ? 1UL : 0UL);
}

   
                                                    
                                                                  
                                 
                                  
    
__STATIC_INLINE uint32_t LL_SWPMI_IsActiveFlag_DEACT(const SWPMI_TypeDef *SWPMIx)
{
  return ((READ_BIT(SWPMIx->ISR, SWPMI_ISR_DEACTF) == (SWPMI_ISR_DEACTF)) ? 1UL : 0UL);
}

   
                                          
                                                              
                                 
                
    
__STATIC_INLINE void LL_SWPMI_ClearFlag_RXBF(SWPMI_TypeDef *SWPMIx)
{
  WRITE_REG(SWPMIx->ICR, SWPMI_ICR_CRXBFF);
}

   
                                            
                                                              
                                 
                
    
__STATIC_INLINE void LL_SWPMI_ClearFlag_TXBE(SWPMI_TypeDef *SWPMIx)
{
  WRITE_REG(SWPMIx->ICR, SWPMI_ICR_CTXBEF);
}

   
                                        
                                                               
                                 
                
    
__STATIC_INLINE void LL_SWPMI_ClearFlag_RXBER(SWPMI_TypeDef *SWPMIx)
{
  WRITE_REG(SWPMIx->ICR, SWPMI_ICR_CRXBERF);
}

   
                                            
                                                               
                                 
                
    
__STATIC_INLINE void LL_SWPMI_ClearFlag_RXOVR(SWPMI_TypeDef *SWPMIx)
{
  WRITE_REG(SWPMIx->ICR, SWPMI_ICR_CRXOVRF);
}

   
                                              
                                                               
                                 
                
    
__STATIC_INLINE void LL_SWPMI_ClearFlag_TXUNR(SWPMI_TypeDef *SWPMIx)
{
  WRITE_REG(SWPMIx->ICR, SWPMI_ICR_CTXUNRF);
}

   
                                        
                                                            
                                 
                
    
__STATIC_INLINE void LL_SWPMI_ClearFlag_TC(SWPMI_TypeDef *SWPMIx)
{
  WRITE_REG(SWPMIx->ICR, SWPMI_ICR_CTCF);
}

   
                                   
                                                            
                                 
                
    
__STATIC_INLINE void LL_SWPMI_ClearFlag_SR(SWPMI_TypeDef *SWPMIx)
{
  WRITE_REG(SWPMIx->ICR, SWPMI_ICR_CSRF);
}

   
      
    

                                                     
      
    

   
                                         
                                                           
                                 
                
    
__STATIC_INLINE void LL_SWPMI_EnableIT_SR(SWPMI_TypeDef *SWPMIx)
{
  SET_BIT(SWPMIx->IER, SWPMI_IER_SRIE);
}

   
                                              
                                                           
                                 
                
    
__STATIC_INLINE void LL_SWPMI_EnableIT_TC(SWPMI_TypeDef *SWPMIx)
{
  SET_BIT(SWPMIx->IER, SWPMI_IER_TCIE);
}

   
                                     
                                                           
                                 
                
    
__STATIC_INLINE void LL_SWPMI_EnableIT_TX(SWPMI_TypeDef *SWPMIx)
{
  SET_BIT(SWPMIx->IER, SWPMI_IER_TIE);
}

   
                                    
                                                           
                                 
                
    
__STATIC_INLINE void LL_SWPMI_EnableIT_RX(SWPMI_TypeDef *SWPMIx)
{
  SET_BIT(SWPMIx->IER, SWPMI_IER_RIE);
}

   
                                                    
                                                              
                                 
                
    
__STATIC_INLINE void LL_SWPMI_EnableIT_TXUNR(SWPMI_TypeDef *SWPMIx)
{
  SET_BIT(SWPMIx->IER, SWPMI_IER_TXUNRIE);
}

   
                                                  
                                                              
                                 
                
    
__STATIC_INLINE void LL_SWPMI_EnableIT_RXOVR(SWPMI_TypeDef *SWPMIx)
{
  SET_BIT(SWPMIx->IER, SWPMI_IER_RXOVRIE);
}

   
                                              
                                                              
                                 
                
    
__STATIC_INLINE void LL_SWPMI_EnableIT_RXBER(SWPMI_TypeDef *SWPMIx)
{
  SET_BIT(SWPMIx->IER, SWPMI_IER_RXBERIE);
}

   
                                                  
                                                             
                                 
                
    
__STATIC_INLINE void LL_SWPMI_EnableIT_TXBE(SWPMI_TypeDef *SWPMIx)
{
  SET_BIT(SWPMIx->IER, SWPMI_IER_TXBEIE);
}

   
                                                
                                                             
                                 
                
    
__STATIC_INLINE void LL_SWPMI_EnableIT_RXBF(SWPMI_TypeDef *SWPMIx)
{
  SET_BIT(SWPMIx->IER, SWPMI_IER_RXBFIE);
}

   
                                          
                                                            
                                 
                
    
__STATIC_INLINE void LL_SWPMI_DisableIT_SR(SWPMI_TypeDef *SWPMIx)
{
  CLEAR_BIT(SWPMIx->IER, SWPMI_IER_SRIE);
}

   
                                               
                                                            
                                 
                
    
__STATIC_INLINE void LL_SWPMI_DisableIT_TC(SWPMI_TypeDef *SWPMIx)
{
  CLEAR_BIT(SWPMIx->IER, SWPMI_IER_TCIE);
}

   
                                      
                                                            
                                 
                
    
__STATIC_INLINE void LL_SWPMI_DisableIT_TX(SWPMI_TypeDef *SWPMIx)
{
  CLEAR_BIT(SWPMIx->IER, SWPMI_IER_TIE);
}

   
                                     
                                                            
                                 
                
    
__STATIC_INLINE void LL_SWPMI_DisableIT_RX(SWPMI_TypeDef *SWPMIx)
{
  CLEAR_BIT(SWPMIx->IER, SWPMI_IER_RIE);
}

   
                                                     
                                                               
                                 
                
    
__STATIC_INLINE void LL_SWPMI_DisableIT_TXUNR(SWPMI_TypeDef *SWPMIx)
{
  CLEAR_BIT(SWPMIx->IER, SWPMI_IER_TXUNRIE);
}

   
                                                   
                                                               
                                 
                
    
__STATIC_INLINE void LL_SWPMI_DisableIT_RXOVR(SWPMI_TypeDef *SWPMIx)
{
  CLEAR_BIT(SWPMIx->IER, SWPMI_IER_RXOVRIE);
}

   
                                               
                                                               
                                 
                
    
__STATIC_INLINE void LL_SWPMI_DisableIT_RXBER(SWPMI_TypeDef *SWPMIx)
{
  CLEAR_BIT(SWPMIx->IER, SWPMI_IER_RXBERIE);
}

   
                                                   
                                                              
                                 
                
    
__STATIC_INLINE void LL_SWPMI_DisableIT_TXBE(SWPMI_TypeDef *SWPMIx)
{
  CLEAR_BIT(SWPMIx->IER, SWPMI_IER_TXBEIE);
}

   
                                                 
                                                              
                                 
                
    
__STATIC_INLINE void LL_SWPMI_DisableIT_RXBF(SWPMI_TypeDef *SWPMIx)
{
  CLEAR_BIT(SWPMIx->IER, SWPMI_IER_RXBFIE);
}

   
                                                      
                                                              
                                 
                                  
    
__STATIC_INLINE uint32_t LL_SWPMI_IsEnabledIT_SR(const SWPMI_TypeDef *SWPMIx)
{
  return ((READ_BIT(SWPMIx->IER, SWPMI_IER_SRIE) == (SWPMI_IER_SRIE)) ? 1UL : 0UL);
}

   
                                                           
                                                              
                                 
                                  
    
__STATIC_INLINE uint32_t LL_SWPMI_IsEnabledIT_TC(const SWPMI_TypeDef *SWPMIx)
{
  return ((READ_BIT(SWPMIx->IER, SWPMI_IER_TCIE) == (SWPMI_IER_TCIE)) ? 1UL : 0UL);
}

   
                                                  
                                                              
                                 
                                  
    
__STATIC_INLINE uint32_t LL_SWPMI_IsEnabledIT_TX(const SWPMI_TypeDef *SWPMIx)
{
  return ((READ_BIT(SWPMIx->IER, SWPMI_IER_TIE) == (SWPMI_IER_TIE)) ? 1UL : 0UL);
}

   
                                                 
                                                              
                                 
                                  
    
__STATIC_INLINE uint32_t LL_SWPMI_IsEnabledIT_RX(const SWPMI_TypeDef *SWPMIx)
{
  return ((READ_BIT(SWPMIx->IER, SWPMI_IER_RIE) == (SWPMI_IER_RIE)) ? 1UL : 0UL);
}

   
                                                                 
                                                                 
                                 
                                  
    
__STATIC_INLINE uint32_t LL_SWPMI_IsEnabledIT_TXUNR(const SWPMI_TypeDef *SWPMIx)
{
  return ((READ_BIT(SWPMIx->IER, SWPMI_IER_TXUNRIE) == (SWPMI_IER_TXUNRIE)) ? 1UL : 0UL);
}

   
                                                               
                                                                 
                                 
                                  
    
__STATIC_INLINE uint32_t LL_SWPMI_IsEnabledIT_RXOVR(const SWPMI_TypeDef *SWPMIx)
{
  return ((READ_BIT(SWPMIx->IER, SWPMI_IER_RXOVRIE) == (SWPMI_IER_RXOVRIE)) ? 1UL : 0UL);
}

   
                                                           
                                                                 
                                 
                                  
    
__STATIC_INLINE uint32_t LL_SWPMI_IsEnabledIT_RXBER(const SWPMI_TypeDef *SWPMIx)
{
  return ((READ_BIT(SWPMIx->IER, SWPMI_IER_RXBERIE) == (SWPMI_IER_RXBERIE)) ? 1UL : 0UL);
}

   
                                                               
                                                                
                                 
                                  
    
__STATIC_INLINE uint32_t LL_SWPMI_IsEnabledIT_TXBE(const SWPMI_TypeDef *SWPMIx)
{
  return ((READ_BIT(SWPMIx->IER, SWPMI_IER_TXBEIE) == (SWPMI_IER_TXBEIE)) ? 1UL : 0UL);
}

   
                                                             
                                                                
                                 
                                  
    
__STATIC_INLINE uint32_t LL_SWPMI_IsEnabledIT_RXBF(const SWPMI_TypeDef *SWPMIx)
{
  return ((READ_BIT(SWPMIx->IER, SWPMI_IER_RXBFIE) == (SWPMI_IER_RXBFIE)) ? 1UL : 0UL);
}

   
      
    

                                                       
      
    

   
                                         
                                                               
                                 
                
    
__STATIC_INLINE void LL_SWPMI_EnableDMAReq_RX(SWPMI_TypeDef *SWPMIx)
{
  SET_BIT(SWPMIx->CR, SWPMI_CR_RXDMA);
}

   
                                          
                                                                
                                 
                
    
__STATIC_INLINE void LL_SWPMI_DisableDMAReq_RX(SWPMI_TypeDef *SWPMIx)
{
  CLEAR_BIT(SWPMIx->CR, SWPMI_CR_RXDMA);
}

   
                                                      
                                                                  
                                 
                                  
    
__STATIC_INLINE uint32_t LL_SWPMI_IsEnabledDMAReq_RX(const SWPMI_TypeDef *SWPMIx)
{
  return ((READ_BIT(SWPMIx->CR, SWPMI_CR_RXDMA) == (SWPMI_CR_RXDMA)) ? 1UL : 0UL);
}

   
                                            
                                                               
                                 
                
    
__STATIC_INLINE void LL_SWPMI_EnableDMAReq_TX(SWPMI_TypeDef *SWPMIx)
{
  SET_BIT(SWPMIx->CR, SWPMI_CR_TXDMA);
}

   
                                             
                                                                
                                 
                
    
__STATIC_INLINE void LL_SWPMI_DisableDMAReq_TX(SWPMI_TypeDef *SWPMIx)
{
  CLEAR_BIT(SWPMIx->CR, SWPMI_CR_TXDMA);
}

   
                                                         
                                                                  
                                 
                                  
    
__STATIC_INLINE uint32_t LL_SWPMI_IsEnabledDMAReq_TX(const SWPMI_TypeDef *SWPMIx)
{
  return ((READ_BIT(SWPMIx->CR, SWPMI_CR_TXDMA) == (SWPMI_CR_TXDMA)) ? 1UL : 0UL);
}

   
                                                               
                                                                
                                                              
                                 
                                                                        
                                                    
                                                   
                                    
    
__STATIC_INLINE uint32_t LL_SWPMI_DMA_GetRegAddr(const SWPMI_TypeDef *SWPMIx, uint32_t Direction)
{
  uint32_t data_reg_addr;

  if (Direction == LL_SWPMI_DMA_REG_DATA_TRANSMIT)
  {
                                        
    data_reg_addr = (uint32_t) &(SWPMIx->TDR);
  }
  else
  {
                                        
    data_reg_addr = (uint32_t) &(SWPMIx->RDR);
  }

  return data_reg_addr;
}

   
      
    

                                                         
      
    

   
                                                                              
                                                                     
                                 
                                                         
    
__STATIC_INLINE uint32_t LL_SWPMI_GetReceiveFrameLength(const SWPMI_TypeDef *SWPMIx)
{
  return (uint32_t)(READ_BIT(SWPMIx->RFL, SWPMI_RFL_RFL));
}

   
                                  
                                                              
                                 
                                                                            
                
    
__STATIC_INLINE void LL_SWPMI_TransmitData32(SWPMI_TypeDef *SWPMIx, uint32_t TxData)
{
  WRITE_REG(SWPMIx->TDR, TxData);
}

   
                                 
                                                             
                                 
                                                                     
    
__STATIC_INLINE uint32_t LL_SWPMI_ReceiveData32(SWPMI_TypeDef *SWPMIx)
{
  return (uint32_t)(READ_BIT(SWPMIx->RDR, SWPMI_RDR_RD));
}

   
                                         
                                                        
                                                                                     
                                                              
                                 
                
    
__STATIC_INLINE void LL_SWPMI_EnableTXBypass(SWPMI_TypeDef *SWPMIx)
{
  CLEAR_BIT(SWPMIx->OR, SWPMI_OR_TBYP);
}

   
                                          
                                                                                   
                                                                                                
                                                               
                                 
                
    
__STATIC_INLINE void LL_SWPMI_DisableTXBypass(SWPMI_TypeDef *SWPMIx)
{
  SET_BIT(SWPMIx->OR, SWPMI_OR_TBYP);
}

   
      
    

#if defined(USE_FULL_LL_DRIVER)
                                                                             
      
    

ErrorStatus LL_SWPMI_DeInit(const SWPMI_TypeDef *SWPMIx);
ErrorStatus LL_SWPMI_Init(SWPMI_TypeDef *SWPMIx, const LL_SWPMI_InitTypeDef *SWPMI_InitStruct);
void        LL_SWPMI_StructInit(LL_SWPMI_InitTypeDef *SWPMI_InitStruct);

   
      
    
#endif                       

   
      
    

   
      
    

#endif             

   
      
    

#ifdef __cplusplus
}
#endif

#endif                           
