/**
  ******************************************************************************
  * @file    stm32l4xx_ll_spi.h
  * @author  MCD Application Team
  * @brief   Header file of SPI LL module.
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

                                                                                
#ifndef STM32L4xx_LL_SPI_H
#define STM32L4xx_LL_SPI_H

#ifdef __cplusplus
extern "C" {
#endif

                                                                                
#include "stm32l4xx.h"

                                   
      
    

#if defined (SPI1) || defined (SPI2) || defined (SPI3)

                        
      
    

                                                                                
                                                                                
                                                                                

                                                                                
#if defined(USE_FULL_LL_DRIVER)
                                                        
      
    

   
                                          
    
typedef struct
{
  uint32_t TransferDirection;                                                                        
                                                                                                       

                                                                                              
                                                                                       

  uint32_t Mode;                                                               
                                                                                              

                                                                                              
                                                                          

  uint32_t DataWidth;                                                 
                                                                                                   

                                                                                              
                                                                               

  uint32_t ClockPolarity;                                                        
                                                                                                  

                                                                                              
                                                                                   

  uint32_t ClockPhase;                                                                       
                                                                                               

                                                                                              
                                                                                

  uint32_t NSS;                                                                                           
                                                                          
                                                                                                  

                                                                                              
                                                                             

  uint32_t BaudRate;                                                                              
                                                                                         
                                                                                                           
                                                                                                        
                                                                                       

                                                                                              
                                                                                       

  uint32_t BitOrder;                                                                                
                                                                                                   

                                                                                              
                                                                                      

  uint32_t CRCCalculation;                                                                  
                                                                                                         

                                                                                              
                                                                                                          

  uint32_t CRCPoly;                                                                            
                                                                                                                       

                                                                                              
                                                                                   

} LL_SPI_InitTypeDef;

   
      
    
#endif                         

                                                                                
                                                              
      
    

                                                  
                                                                          
      
    
#define LL_SPI_SR_RXNE                     SPI_SR_RXNE                                                       
#define LL_SPI_SR_TXE                      SPI_SR_TXE                                                        
#define LL_SPI_SR_BSY                      SPI_SR_BSY                                                        
#define LL_SPI_SR_CRCERR                   SPI_SR_CRCERR                                                     
#define LL_SPI_SR_MODF                     SPI_SR_MODF                                                       
#define LL_SPI_SR_OVR                      SPI_SR_OVR                                                        
#define LL_SPI_SR_FRE                      SPI_SR_FRE                                                        
   
      
    

                                     
                                                                                             
      
    
#define LL_SPI_CR2_RXNEIE                  SPI_CR2_RXNEIE                                                        
#define LL_SPI_CR2_TXEIE                   SPI_CR2_TXEIE                                                         
#define LL_SPI_CR2_ERRIE                   SPI_CR2_ERRIE                                                         
   
      
    

                                           
      
    
#define LL_SPI_MODE_MASTER                 (SPI_CR1_MSTR | SPI_CR1_SSI)                                 
#define LL_SPI_MODE_SLAVE                  0x00000000U                                                  
   
      
    

                                                
      
    
#define LL_SPI_PROTOCOL_MOTOROLA           0x00000000U                                                           
#define LL_SPI_PROTOCOL_TI                 (SPI_CR2_FRF)                                                         
   
      
    

                                         
      
    
#define LL_SPI_PHASE_1EDGE                 0x00000000U                                                                             
#define LL_SPI_PHASE_2EDGE                 (SPI_CR1_CPHA)                                                                          
   
      
    

                                               
      
    
#define LL_SPI_POLARITY_LOW                0x00000000U                                           
#define LL_SPI_POLARITY_HIGH               (SPI_CR1_CPOL)                                        
   
      
    

                                                             
      
    
#define LL_SPI_BAUDRATEPRESCALER_DIV2      0x00000000U                                                                               
#define LL_SPI_BAUDRATEPRESCALER_DIV4      (SPI_CR1_BR_0)                                                                            
#define LL_SPI_BAUDRATEPRESCALER_DIV8      (SPI_CR1_BR_1)                                                                            
#define LL_SPI_BAUDRATEPRESCALER_DIV16     (SPI_CR1_BR_1 | SPI_CR1_BR_0)                                                             
#define LL_SPI_BAUDRATEPRESCALER_DIV32     (SPI_CR1_BR_2)                                                                            
#define LL_SPI_BAUDRATEPRESCALER_DIV64     (SPI_CR1_BR_2 | SPI_CR1_BR_0)                                                             
#define LL_SPI_BAUDRATEPRESCALER_DIV128    (SPI_CR1_BR_2 | SPI_CR1_BR_1)                                                             
#define LL_SPI_BAUDRATEPRESCALER_DIV256    (SPI_CR1_BR_2 | SPI_CR1_BR_1 | SPI_CR1_BR_0)                                              
   
      
    

                                                        
      
    
#define LL_SPI_LSB_FIRST                   (SPI_CR1_LSBFIRST)                                                               
#define LL_SPI_MSB_FIRST                   0x00000000U                                                                      
   
      
    

                                                   
      
    
#define LL_SPI_FULL_DUPLEX                 0x00000000U                                                                                 
#define LL_SPI_SIMPLEX_RX                  (SPI_CR1_RXONLY)                                                                            
#define LL_SPI_HALF_DUPLEX_RX              (SPI_CR1_BIDIMODE)                                                                          
#define LL_SPI_HALF_DUPLEX_TX              (SPI_CR1_BIDIMODE | SPI_CR1_BIDIOE)                                                         
   
      
    

                                                      
      
    
#define LL_SPI_NSS_SOFT                    (SPI_CR1_SSM)                                                                                           
#define LL_SPI_NSS_HARD_INPUT              0x00000000U                                                                                             
#define LL_SPI_NSS_HARD_OUTPUT             (((uint32_t)SPI_CR2_SSOE << 16U))                                                                       
   
      
    

                                           
      
    
#define LL_SPI_DATAWIDTH_4BIT              (SPI_CR2_DS_0 | SPI_CR2_DS_1)                                                                            
#define LL_SPI_DATAWIDTH_5BIT              (SPI_CR2_DS_2)                                                                                           
#define LL_SPI_DATAWIDTH_6BIT              (SPI_CR2_DS_2 | SPI_CR2_DS_0)                                                                            
#define LL_SPI_DATAWIDTH_7BIT              (SPI_CR2_DS_2 | SPI_CR2_DS_1)                                                                            
#define LL_SPI_DATAWIDTH_8BIT              (SPI_CR2_DS_2 | SPI_CR2_DS_1 | SPI_CR2_DS_0)                                                             
#define LL_SPI_DATAWIDTH_9BIT              (SPI_CR2_DS_3)                                                                                           
#define LL_SPI_DATAWIDTH_10BIT             (SPI_CR2_DS_3 | SPI_CR2_DS_0)                                                                            
#define LL_SPI_DATAWIDTH_11BIT             (SPI_CR2_DS_3 | SPI_CR2_DS_1)                                                                            
#define LL_SPI_DATAWIDTH_12BIT             (SPI_CR2_DS_3 | SPI_CR2_DS_1 | SPI_CR2_DS_0)                                                             
#define LL_SPI_DATAWIDTH_13BIT             (SPI_CR2_DS_3 | SPI_CR2_DS_2)                                                                            
#define LL_SPI_DATAWIDTH_14BIT             (SPI_CR2_DS_3 | SPI_CR2_DS_2 | SPI_CR2_DS_0)                                                             
#define LL_SPI_DATAWIDTH_15BIT             (SPI_CR2_DS_3 | SPI_CR2_DS_2 | SPI_CR2_DS_1)                                                             
#define LL_SPI_DATAWIDTH_16BIT             (SPI_CR2_DS_3 | SPI_CR2_DS_2 | SPI_CR2_DS_1 | SPI_CR2_DS_0)                                              
   
      
    
#if defined(USE_FULL_LL_DRIVER)

                                                       
      
    
#define LL_SPI_CRCCALCULATION_DISABLE      0x00000000U                                               
#define LL_SPI_CRCCALCULATION_ENABLE       (SPI_CR1_CRCEN)                                           
   
      
    
#endif                         

                                             
      
    
#define LL_SPI_CRC_8BIT                    0x00000000U                                        
#define LL_SPI_CRC_16BIT                   (SPI_CR1_CRCL)                                     
   
      
    

                                                    
      
    
#define LL_SPI_RX_FIFO_TH_HALF             0x00000000U                                                                                                     
#define LL_SPI_RX_FIFO_TH_QUARTER          (SPI_CR2_FRXTH)                                                                                                 
   
      
    

                                             
      
    
#define LL_SPI_RX_FIFO_EMPTY               0x00000000U                                                   
#define LL_SPI_RX_FIFO_QUARTER_FULL        (SPI_SR_FRLVL_0)                                              
#define LL_SPI_RX_FIFO_HALF_FULL           (SPI_SR_FRLVL_1)                                              
#define LL_SPI_RX_FIFO_FULL                (SPI_SR_FRLVL_1 | SPI_SR_FRLVL_0)                             
   
      
    

                                             
      
    
#define LL_SPI_TX_FIFO_EMPTY               0x00000000U                                                      
#define LL_SPI_TX_FIFO_QUARTER_FULL        (SPI_SR_FTLVL_0)                                                 
#define LL_SPI_TX_FIFO_HALF_FULL           (SPI_SR_FTLVL_1)                                                 
#define LL_SPI_TX_FIFO_FULL                (SPI_SR_FTLVL_1 | SPI_SR_FTLVL_0)                                
   
      
    

                                             
      
    
#define LL_SPI_DMA_PARITY_EVEN             0x00000000U                                 
#define LL_SPI_DMA_PARITY_ODD              0x00000001U                                 

   
      
    

   
      
    

                                                                                
                                                        
      
    

                                                                         
      
    

   
                                         
                                     
                                          
                                                         
                
    
#define LL_SPI_WriteReg(__INSTANCE__, __REG__, __VALUE__) WRITE_REG(__INSTANCE__->__REG__, (__VALUE__))

   
                                        
                                     
                                       
                          
    
#define LL_SPI_ReadReg(__INSTANCE__, __REG__) READ_REG(__INSTANCE__->__REG__)
   
      
    

   
      
    

                                                                                
                                                              
      
    

                                                   
      
    

   
                                 
                                                    
                             
                
    
__STATIC_INLINE void LL_SPI_Enable(SPI_TypeDef *SPIx)
{
  SET_BIT(SPIx->CR1, SPI_CR1_SPE);
}

   
                                  
                                                                                           
                                                     
                             
                
    
__STATIC_INLINE void LL_SPI_Disable(SPI_TypeDef *SPIx)
{
  CLEAR_BIT(SPIx->CR1, SPI_CR1_SPE);
}

   
                                              
                                                       
                             
                                  
    
__STATIC_INLINE uint32_t LL_SPI_IsEnabled(const SPI_TypeDef *SPIx)
{
  return ((READ_BIT(SPIx->CR1, SPI_CR1_SPE) == (SPI_CR1_SPE)) ? 1UL : 0UL);
}

   
                                                     
                                                                         
                                                       
                                                     
                             
                                                                   
                                        
                                       
                
    
__STATIC_INLINE void LL_SPI_SetMode(SPI_TypeDef *SPIx, uint32_t Mode)
{
  MODIFY_REG(SPIx->CR1, SPI_CR1_MSTR | SPI_CR1_SSI, Mode);
}

   
                                                    
                                                       
                                                     
                             
                                                              
                                        
                                       
    
__STATIC_INLINE uint32_t LL_SPI_GetMode(const SPI_TypeDef *SPIx)
{
  return (uint32_t)(READ_BIT(SPIx->CR1, SPI_CR1_MSTR | SPI_CR1_SSI));
}

   
                                    
                                                                                                 
                                                         
                             
                                                                       
                                              
                                        
                
    
__STATIC_INLINE void LL_SPI_SetStandard(SPI_TypeDef *SPIx, uint32_t Standard)
{
  MODIFY_REG(SPIx->CR2, SPI_CR2_FRF, Standard);
}

   
                                    
                                                         
                             
                                                              
                                              
                                        
    
__STATIC_INLINE uint32_t LL_SPI_GetStandard(const SPI_TypeDef *SPIx)
{
  return (uint32_t)(READ_BIT(SPIx->CR2, SPI_CR2_FRF));
}

   
                           
                                                                         
                                                
                                                           
                             
                                                                         
                                        
                                        
                
    
__STATIC_INLINE void LL_SPI_SetClockPhase(SPI_TypeDef *SPIx, uint32_t ClockPhase)
{
  MODIFY_REG(SPIx->CR1, SPI_CR1_CPHA, ClockPhase);
}

   
                           
                                                           
                             
                                                              
                                        
                                        
    
__STATIC_INLINE uint32_t LL_SPI_GetClockPhase(const SPI_TypeDef *SPIx)
{
  return (uint32_t)(READ_BIT(SPIx->CR1, SPI_CR1_CPHA));
}

   
                              
                                                                         
                                                
                                                              
                             
                                                                            
                                         
                                          
                
    
__STATIC_INLINE void LL_SPI_SetClockPolarity(SPI_TypeDef *SPIx, uint32_t ClockPolarity)
{
  MODIFY_REG(SPIx->CR1, SPI_CR1_CPOL, ClockPolarity);
}

   
                              
                                                              
                             
                                                              
                                         
                                          
    
__STATIC_INLINE uint32_t LL_SPI_GetClockPolarity(const SPI_TypeDef *SPIx)
{
  return (uint32_t)(READ_BIT(SPIx->CR1, SPI_CR1_CPOL));
}

   
                                   
                                                                                                           
                                                                  
                             
                                                                       
                                                   
                                                   
                                                   
                                                    
                                                    
                                                    
                                                     
                                                     
                
    
__STATIC_INLINE void LL_SPI_SetBaudRatePrescaler(SPI_TypeDef *SPIx, uint32_t BaudRate)
{
  MODIFY_REG(SPIx->CR1, SPI_CR1_BR, BaudRate);
}

   
                                   
                                                                  
                             
                                                              
                                                   
                                                   
                                                   
                                                    
                                                    
                                                    
                                                     
                                                     
    
__STATIC_INLINE uint32_t LL_SPI_GetBaudRatePrescaler(const SPI_TypeDef *SPIx)
{
  return (uint32_t)(READ_BIT(SPIx->CR1, SPI_CR1_BR));
}

   
                                  
                                                                                                              
                                                                 
                             
                                                                       
                                      
                                      
                
    
__STATIC_INLINE void LL_SPI_SetTransferBitOrder(SPI_TypeDef *SPIx, uint32_t BitOrder)
{
  MODIFY_REG(SPIx->CR1, SPI_CR1_LSBFIRST, BitOrder);
}

   
                                  
                                                                 
                             
                                                              
                                      
                                      
    
__STATIC_INLINE uint32_t LL_SPI_GetTransferBitOrder(const SPI_TypeDef *SPIx)
{
  return (uint32_t)(READ_BIT(SPIx->CR1, SPI_CR1_LSBFIRST));
}

   
                                       
                                                                 
                                                                                                         
                                                                    
                                                                    
                                                                  
                             
                                                                                
                                        
                                       
                                           
                                           
                
    
__STATIC_INLINE void LL_SPI_SetTransferDirection(SPI_TypeDef *SPIx, uint32_t TransferDirection)
{
  MODIFY_REG(SPIx->CR1, SPI_CR1_RXONLY | SPI_CR1_BIDIMODE | SPI_CR1_BIDIOE, TransferDirection);
}

   
                                       
                                                                    
                                                                    
                                                                  
                             
                                                              
                                        
                                       
                                           
                                           
    
__STATIC_INLINE uint32_t LL_SPI_GetTransferDirection(const SPI_TypeDef *SPIx)
{
  return (uint32_t)(READ_BIT(SPIx->CR1, SPI_CR1_RXONLY | SPI_CR1_BIDIMODE | SPI_CR1_BIDIOE));
}

   
                                
                                                          
                             
                                                                        
                                           
                                           
                                           
                                           
                                           
                                           
                                            
                                            
                                            
                                            
                                            
                                            
                                            
                
    
__STATIC_INLINE void LL_SPI_SetDataWidth(SPI_TypeDef *SPIx, uint32_t DataWidth)
{
  MODIFY_REG(SPIx->CR2, SPI_CR2_DS, DataWidth);
}

   
                                
                                                          
                             
                                                              
                                           
                                           
                                           
                                           
                                           
                                           
                                            
                                            
                                            
                                            
                                            
                                            
                                            
    
__STATIC_INLINE uint32_t LL_SPI_GetDataWidth(const SPI_TypeDef *SPIx)
{
  return (uint32_t)(READ_BIT(SPIx->CR2, SPI_CR2_DS));
}

   
                                                               
                                                                
                             
                                                                        
                                            
                                               
                
    
__STATIC_INLINE void LL_SPI_SetRxFIFOThreshold(SPI_TypeDef *SPIx, uint32_t Threshold)
{
  MODIFY_REG(SPIx->CR2, SPI_CR2_FRXTH, Threshold);
}

   
                                                               
                                                                
                             
                                                              
                                            
                                               
    
__STATIC_INLINE uint32_t LL_SPI_GetRxFIFOThreshold(const SPI_TypeDef *SPIx)
{
  return (uint32_t)(READ_BIT(SPIx->CR2, SPI_CR2_FRXTH));
}

   
      
    

                                                     
      
    

   
                      
                                                                                                 
                                                       
                             
                
    
__STATIC_INLINE void LL_SPI_EnableCRC(SPI_TypeDef *SPIx)
{
  SET_BIT(SPIx->CR1, SPI_CR1_CRCEN);
}

   
                       
                                                                                                 
                                                        
                             
                
    
__STATIC_INLINE void LL_SPI_DisableCRC(SPI_TypeDef *SPIx)
{
  CLEAR_BIT(SPIx->CR1, SPI_CR1_CRCEN);
}

   
                                   
                                                                                                 
                                                          
                             
                                  
    
__STATIC_INLINE uint32_t LL_SPI_IsEnabledCRC(const SPI_TypeDef *SPIx)
{
  return ((READ_BIT(SPIx->CR1, SPI_CR1_CRCEN) == (SPI_CR1_CRCEN)) ? 1UL : 0UL);
}

   
                          
                                                                                                 
                                                         
                             
                                                                        
                                     
                                      
                
    
__STATIC_INLINE void LL_SPI_SetCRCWidth(SPI_TypeDef *SPIx, uint32_t CRCLength)
{
  MODIFY_REG(SPIx->CR1, SPI_CR1_CRCL, CRCLength);
}

   
                          
                                                         
                             
                                                              
                                     
                                      
    
__STATIC_INLINE uint32_t LL_SPI_GetCRCWidth(const SPI_TypeDef *SPIx)
{
  return (uint32_t)(READ_BIT(SPIx->CR1, SPI_CR1_CRCL));
}

   
                                                   
                                                                                                   
                                                        
                             
                
    
__STATIC_INLINE void LL_SPI_SetCRCNext(SPI_TypeDef *SPIx)
{
  SET_BIT(SPIx->CR1, SPI_CR1_CRCNEXT);
}

   
                                              
                                                              
                             
                                                                                                 
                
    
__STATIC_INLINE void LL_SPI_SetCRCPolynomial(SPI_TypeDef *SPIx, uint32_t CRCPoly)
{
  WRITE_REG(SPIx->CRCPR, (uint16_t)CRCPoly);
}

   
                                              
                                                              
                             
                                                                                    
    
__STATIC_INLINE uint32_t LL_SPI_GetCRCPolynomial(const SPI_TypeDef *SPIx)
{
  return (uint32_t)(READ_REG(SPIx->CRCPR));
}

   
                      
                                                      
                             
                                                                                    
    
__STATIC_INLINE uint32_t LL_SPI_GetRxCRC(const SPI_TypeDef *SPIx)
{
  return (uint32_t)(READ_REG(SPIx->RXCRCR));
}

   
                      
                                                      
                             
                                                                                    
    
__STATIC_INLINE uint32_t LL_SPI_GetTxCRC(const SPI_TypeDef *SPIx)
{
  return (uint32_t)(READ_REG(SPIx->TXCRCR));
}

   
      
    

                                                                  
      
    

   
                        
                                                            
                                                          
                                                        
                             
                                                                  
                                     
                                           
                                            
                
    
__STATIC_INLINE void LL_SPI_SetNSSMode(SPI_TypeDef *SPIx, uint32_t NSS)
{
  MODIFY_REG(SPIx->CR1, SPI_CR1_SSM,  NSS);
  MODIFY_REG(SPIx->CR2, SPI_CR2_SSOE, ((uint32_t)(NSS >> 16U)));
}

   
                        
                                                          
                                                        
                             
                                                              
                                     
                                           
                                            
    
__STATIC_INLINE uint32_t LL_SPI_GetNSSMode(const SPI_TypeDef *SPIx)
{
  uint32_t Ssm  = (READ_BIT(SPIx->CR1, SPI_CR1_SSM));
  uint32_t Ssoe = (READ_BIT(SPIx->CR2,  SPI_CR2_SSOE) << 16U);
  return (Ssm | Ssoe);
}

   
                                       
                                                                                                              
                                                               
                             
                
    
__STATIC_INLINE void LL_SPI_EnableNSSPulseMgt(SPI_TypeDef *SPIx)
{
  SET_BIT(SPIx->CR2, SPI_CR2_NSSP);
}

   
                                        
                                                                                                              
                                                                
                             
                
    
__STATIC_INLINE void LL_SPI_DisableNSSPulseMgt(SPI_TypeDef *SPIx)
{
  CLEAR_BIT(SPIx->CR2, SPI_CR2_NSSP);
}

   
                                         
                                                                                                              
                                                               
                             
                                  
    
__STATIC_INLINE uint32_t LL_SPI_IsEnabledNSSPulse(const SPI_TypeDef *SPIx)
{
  return ((READ_BIT(SPIx->CR2, SPI_CR2_NSSP) == (SPI_CR2_NSSP)) ? 1UL : 0UL);
}

   
      
    

                                                       
      
    

   
                                           
                                                               
                             
                                  
    
__STATIC_INLINE uint32_t LL_SPI_IsActiveFlag_RXNE(const SPI_TypeDef *SPIx)
{
  return ((READ_BIT(SPIx->SR, SPI_SR_RXNE) == (SPI_SR_RXNE)) ? 1UL : 0UL);
}

   
                                       
                                                              
                             
                                  
    
__STATIC_INLINE uint32_t LL_SPI_IsActiveFlag_TXE(const SPI_TypeDef *SPIx)
{
  return ((READ_BIT(SPIx->SR, SPI_SR_TXE) == (SPI_SR_TXE)) ? 1UL : 0UL);
}

   
                              
                                                                 
                             
                                  
    
__STATIC_INLINE uint32_t LL_SPI_IsActiveFlag_CRCERR(const SPI_TypeDef *SPIx)
{
  return ((READ_BIT(SPIx->SR, SPI_SR_CRCERR) == (SPI_SR_CRCERR)) ? 1UL : 0UL);
}

   
                                     
                                                               
                             
                                  
    
__STATIC_INLINE uint32_t LL_SPI_IsActiveFlag_MODF(const SPI_TypeDef *SPIx)
{
  return ((READ_BIT(SPIx->SR, SPI_SR_MODF) == (SPI_SR_MODF)) ? 1UL : 0UL);
}

   
                                  
                                                              
                             
                                  
    
__STATIC_INLINE uint32_t LL_SPI_IsActiveFlag_OVR(const SPI_TypeDef *SPIx)
{
  return ((READ_BIT(SPIx->SR, SPI_SR_OVR) == (SPI_SR_OVR)) ? 1UL : 0UL);
}

   
                         
                                                                              
                                       
                                                                
                                                                                        
        
                                                                                            
                       
                                                              
                             
                                  
    
__STATIC_INLINE uint32_t LL_SPI_IsActiveFlag_BSY(const SPI_TypeDef *SPIx)
{
  return ((READ_BIT(SPIx->SR, SPI_SR_BSY) == (SPI_SR_BSY)) ? 1UL : 0UL);
}

   
                                       
                                                              
                             
                                  
    
__STATIC_INLINE uint32_t LL_SPI_IsActiveFlag_FRE(const SPI_TypeDef *SPIx)
{
  return ((READ_BIT(SPIx->SR, SPI_SR_FRE) == (SPI_SR_FRE)) ? 1UL : 0UL);
}

   
                                    
                                                            
                             
                                                              
                                          
                                                 
                                              
                                         
    
__STATIC_INLINE uint32_t LL_SPI_GetRxFIFOLevel(const SPI_TypeDef *SPIx)
{
  return (uint32_t)(READ_BIT(SPIx->SR, SPI_SR_FRLVL));
}

   
                                       
                                                            
                             
                                                              
                                          
                                                 
                                              
                                         
    
__STATIC_INLINE uint32_t LL_SPI_GetTxFIFOLevel(const SPI_TypeDef *SPIx)
{
  return (uint32_t)(READ_BIT(SPIx->SR, SPI_SR_FTLVL));
}

   
                                
                                                              
                             
                
    
__STATIC_INLINE void LL_SPI_ClearFlag_CRCERR(SPI_TypeDef *SPIx)
{
  CLEAR_BIT(SPIx->SR, SPI_SR_CRCERR);
}

   
                                       
                                                                      
                                                                        
                                                            
                             
                
    
__STATIC_INLINE void LL_SPI_ClearFlag_MODF(SPI_TypeDef *SPIx)
{
  __IO uint32_t tmpreg_sr;
  tmpreg_sr = SPIx->SR;
  (void) tmpreg_sr;
  CLEAR_BIT(SPIx->CR1, SPI_CR1_SPE);
}

   
                                    
                                                                      
                                                                      
                                                           
                             
                
    
__STATIC_INLINE void LL_SPI_ClearFlag_OVR(const SPI_TypeDef *SPIx)
{
  __IO uint32_t tmpreg;
  tmpreg = SPIx->DR;
  (void) tmpreg;
  tmpreg = SPIx->SR;
  (void) tmpreg;
}

   
                                         
                                                                  
                                                           
                             
                
    
__STATIC_INLINE void LL_SPI_ClearFlag_FRE(const SPI_TypeDef *SPIx)
{
  __IO uint32_t tmpreg;
  tmpreg = SPIx->SR;
  (void) tmpreg;
}

   
      
    

                                                          
      
    

   
                                  
                                                                                    
                                                                   
                                                          
                             
                
    
__STATIC_INLINE void LL_SPI_EnableIT_ERR(SPI_TypeDef *SPIx)
{
  SET_BIT(SPIx->CR2, SPI_CR2_ERRIE);
}

   
                                                
                                                           
                             
                
    
__STATIC_INLINE void LL_SPI_EnableIT_RXNE(SPI_TypeDef *SPIx)
{
  SET_BIT(SPIx->CR2, SPI_CR2_RXNEIE);
}

   
                                            
                                                          
                             
                
    
__STATIC_INLINE void LL_SPI_EnableIT_TXE(SPI_TypeDef *SPIx)
{
  SET_BIT(SPIx->CR2, SPI_CR2_TXEIE);
}

   
                                   
                                                                                    
                                                                   
                                                           
                             
                
    
__STATIC_INLINE void LL_SPI_DisableIT_ERR(SPI_TypeDef *SPIx)
{
  CLEAR_BIT(SPIx->CR2, SPI_CR2_ERRIE);
}

   
                                                 
                                                            
                             
                
    
__STATIC_INLINE void LL_SPI_DisableIT_RXNE(SPI_TypeDef *SPIx)
{
  CLEAR_BIT(SPIx->CR2, SPI_CR2_RXNEIE);
}

   
                                             
                                                           
                             
                
    
__STATIC_INLINE void LL_SPI_DisableIT_TXE(SPI_TypeDef *SPIx)
{
  CLEAR_BIT(SPIx->CR2, SPI_CR2_TXEIE);
}

   
                                               
                                                             
                             
                                  
    
__STATIC_INLINE uint32_t LL_SPI_IsEnabledIT_ERR(const SPI_TypeDef *SPIx)
{
  return ((READ_BIT(SPIx->CR2, SPI_CR2_ERRIE) == (SPI_CR2_ERRIE)) ? 1UL : 0UL);
}

   
                                                             
                                                              
                             
                                  
    
__STATIC_INLINE uint32_t LL_SPI_IsEnabledIT_RXNE(const SPI_TypeDef *SPIx)
{
  return ((READ_BIT(SPIx->CR2, SPI_CR2_RXNEIE) == (SPI_CR2_RXNEIE)) ? 1UL : 0UL);
}

   
                                              
                                                             
                             
                                  
    
__STATIC_INLINE uint32_t LL_SPI_IsEnabledIT_TXE(const SPI_TypeDef *SPIx)
{
  return ((READ_BIT(SPIx->CR2, SPI_CR2_TXEIE) == (SPI_CR2_TXEIE)) ? 1UL : 0UL);
}

   
      
    

                                                     
      
    

   
                         
                                                             
                             
                
    
__STATIC_INLINE void LL_SPI_EnableDMAReq_RX(SPI_TypeDef *SPIx)
{
  SET_BIT(SPIx->CR2, SPI_CR2_RXDMAEN);
}

   
                          
                                                              
                             
                
    
__STATIC_INLINE void LL_SPI_DisableDMAReq_RX(SPI_TypeDef *SPIx)
{
  CLEAR_BIT(SPIx->CR2, SPI_CR2_RXDMAEN);
}

   
                                      
                                                                
                             
                                  
    
__STATIC_INLINE uint32_t LL_SPI_IsEnabledDMAReq_RX(const SPI_TypeDef *SPIx)
{
  return ((READ_BIT(SPIx->CR2, SPI_CR2_RXDMAEN) == (SPI_CR2_RXDMAEN)) ? 1UL : 0UL);
}

   
                         
                                                             
                             
                
    
__STATIC_INLINE void LL_SPI_EnableDMAReq_TX(SPI_TypeDef *SPIx)
{
  SET_BIT(SPIx->CR2, SPI_CR2_TXDMAEN);
}

   
                          
                                                              
                             
                
    
__STATIC_INLINE void LL_SPI_DisableDMAReq_TX(SPI_TypeDef *SPIx)
{
  CLEAR_BIT(SPIx->CR2, SPI_CR2_TXDMAEN);
}

   
                                      
                                                                
                             
                                  
    
__STATIC_INLINE uint32_t LL_SPI_IsEnabledDMAReq_TX(const SPI_TypeDef *SPIx)
{
  return ((READ_BIT(SPIx->CR2, SPI_CR2_TXDMAEN) == (SPI_CR2_TXDMAEN)) ? 1UL : 0UL);
}

   
                                             
                                                             
                             
                                                                     
                                           
                                            
                
    
__STATIC_INLINE void LL_SPI_SetDMAParity_RX(SPI_TypeDef *SPIx, uint32_t Parity)
{
  MODIFY_REG(SPIx->CR2, SPI_CR2_LDMARX, (Parity << SPI_CR2_LDMARX_Pos));
}

   
                                                            
                                                             
                             
                                                              
                                           
                                            
    
__STATIC_INLINE uint32_t LL_SPI_GetDMAParity_RX(const SPI_TypeDef *SPIx)
{
  return (uint32_t)(READ_BIT(SPIx->CR2, SPI_CR2_LDMARX) >> SPI_CR2_LDMARX_Pos);
}

   
                                                
                                                             
                             
                                                                     
                                           
                                            
                
    
__STATIC_INLINE void LL_SPI_SetDMAParity_TX(SPI_TypeDef *SPIx, uint32_t Parity)
{
  MODIFY_REG(SPIx->CR2, SPI_CR2_LDMATX, (Parity << SPI_CR2_LDMATX_Pos));
}

   
                                                              
                                                             
                             
                                                              
                                           
                                            
    
__STATIC_INLINE uint32_t LL_SPI_GetDMAParity_TX(const SPI_TypeDef *SPIx)
{
  return (uint32_t)(READ_BIT(SPIx->CR2, SPI_CR2_LDMATX) >> SPI_CR2_LDMATX_Pos);
}

   
                                                               
                                                            
                             
                                    
    
__STATIC_INLINE uint32_t LL_SPI_DMA_GetRegAddr(const SPI_TypeDef *SPIx)
{
  return (uint32_t) &(SPIx->DR);
}

   
      
    

                                                       
      
    

   
                                            
                                                          
                             
                                                                
    
__STATIC_INLINE uint8_t LL_SPI_ReceiveData8(SPI_TypeDef *SPIx)
{
  return (*((__IO uint8_t *)&SPIx->DR));
}

   
                                             
                                                           
                             
                                                                  
    
__STATIC_INLINE uint16_t LL_SPI_ReceiveData16(SPI_TypeDef *SPIx)
{
  return (uint16_t)(READ_REG(SPIx->DR));
}

   
                                             
                                                           
                             
                                                                
                
    
__STATIC_INLINE void LL_SPI_TransmitData8(SPI_TypeDef *SPIx, uint8_t TxData)
{
#if defined (__GNUC__)
  __IO uint8_t *spidr = ((__IO uint8_t *)&SPIx->DR);
  *spidr = TxData;
#else
  *((__IO uint8_t *)&SPIx->DR) = TxData;
#endif               
}

   
                                              
                                                            
                             
                                                                  
                
    
__STATIC_INLINE void LL_SPI_TransmitData16(SPI_TypeDef *SPIx, uint16_t TxData)
{
#if defined (__GNUC__)
  __IO uint16_t *spidr = ((__IO uint16_t *)&SPIx->DR);
  *spidr = TxData;
#else
  SPIx->DR = TxData;
#endif               
}

   
      
    
#if defined(USE_FULL_LL_DRIVER)
                                                                           
      
    

ErrorStatus LL_SPI_DeInit(const SPI_TypeDef *SPIx);
ErrorStatus LL_SPI_Init(SPI_TypeDef *SPIx, LL_SPI_InitTypeDef *SPI_InitStruct);
void        LL_SPI_StructInit(LL_SPI_InitTypeDef *SPI_InitStruct);

   
      
    
#endif                         
   
      
    

   
      
    

#endif                                                         

   
      
    

#ifdef __cplusplus
}
#endif

#endif                         

