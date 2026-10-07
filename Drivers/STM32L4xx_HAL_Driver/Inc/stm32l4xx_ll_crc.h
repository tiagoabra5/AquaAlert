/**
  ******************************************************************************
  * @file    stm32l4xx_ll_crc.h
  * @author  MCD Application Team
  * @brief   Header file of CRC LL module.
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

                                                                                
#ifndef STM32L4xx_LL_CRC_H
#define STM32L4xx_LL_CRC_H

#ifdef __cplusplus
extern "C" {
#endif

                                                                                
#include "stm32l4xx.h"

                                   
      
    

#if defined(CRC)

                        
      
    

                                                                                
                                                                                
                                                                                
                                                                                

                                                                                
                                                                                
                                                              
      
    

                                                    
      
    
#define LL_CRC_POLYLENGTH_32B              0x00000000U                                                             
#define LL_CRC_POLYLENGTH_16B              CRC_CR_POLYSIZE_0                                                       
#define LL_CRC_POLYLENGTH_8B               CRC_CR_POLYSIZE_1                                                      
#define LL_CRC_POLYLENGTH_7B               (CRC_CR_POLYSIZE_1 | CRC_CR_POLYSIZE_0)                                
   
      
    

                                                         
      
    
#define LL_CRC_INDATA_REVERSE_NONE         0x00000000U                                                                       
#define LL_CRC_INDATA_REVERSE_BYTE         CRC_CR_REV_IN_0                                                                      
#define LL_CRC_INDATA_REVERSE_HALFWORD     CRC_CR_REV_IN_1                                                                           
#define LL_CRC_INDATA_REVERSE_WORD         (CRC_CR_REV_IN_1 | CRC_CR_REV_IN_0)                                                  
   
      
    

                                                           
      
    
#define LL_CRC_OUTDATA_REVERSE_NONE        0x00000000U                                                                         
#define LL_CRC_OUTDATA_REVERSE_BIT         CRC_CR_REV_OUT                                                                        
   
      
    

                                                                                           
                                                               
                                                                                                          
      
    
#define LL_CRC_DEFAULT_CRC32_POLY          0x04C11DB7U                                                                              
   
      
    

                                                                                         
      
    
#define LL_CRC_DEFAULT_CRC_INITVALUE       0xFFFFFFFFU                                                                                   
   
      
    

   
      
    

                                                                                
                                                        
      
    

                                                                         
      
    

   
                                         
                                     
                                          
                                                         
                
    
#define LL_CRC_WriteReg(__INSTANCE__, __REG__, __VALUE__) WRITE_REG(__INSTANCE__->__REG__, __VALUE__)

   
                                        
                                     
                                       
                          
    
#define LL_CRC_ReadReg(__INSTANCE__, __REG__) READ_REG(__INSTANCE__->__REG__)
   
      
    

   
      
    


                                                                                
                                                              
      
    

                                                                 
      
    

   
                                           
                                                     
                                                                               
                                                                                   
                                                                     
                             
                
    
__STATIC_INLINE void LL_CRC_ResetCRCCalculationUnit(CRC_TypeDef *CRCx)
{
  SET_BIT(CRCx->CR, CRC_CR_RESET);
}

   
                                             
                                                               
                             
                                                                       
                                           
                                           
                                          
                                          
                
    
__STATIC_INLINE void LL_CRC_SetPolynomialSize(CRC_TypeDef *CRCx, uint32_t PolySize)
{
  MODIFY_REG(CRCx->CR, CRC_CR_POLYSIZE, PolySize);
}

   
                                          
                                                               
                             
                                                              
                                           
                                           
                                          
                                          
    
__STATIC_INLINE uint32_t LL_CRC_GetPolynomialSize(const CRC_TypeDef *CRCx)
{
  return (uint32_t)(READ_BIT(CRCx->CR, CRC_CR_POLYSIZE));
}

   
                                                                     
                                                                     
                             
                                                                          
                                                
                                                
                                                    
                                                
                
    
__STATIC_INLINE void LL_CRC_SetInputDataReverseMode(CRC_TypeDef *CRCx, uint32_t ReverseMode)
{
  MODIFY_REG(CRCx->CR, CRC_CR_REV_IN, ReverseMode);
}

   
                                                            
                                                                     
                             
                                                              
                                                
                                                
                                                    
                                                
    
__STATIC_INLINE uint32_t LL_CRC_GetInputDataReverseMode(const CRC_TypeDef *CRCx)
{
  return (uint32_t)(READ_BIT(CRCx->CR, CRC_CR_REV_IN));
}

   
                                                                      
                                                                      
                             
                                                                          
                                                 
                                                
                
    
__STATIC_INLINE void LL_CRC_SetOutputDataReverseMode(CRC_TypeDef *CRCx, uint32_t ReverseMode)
{
  MODIFY_REG(CRCx->CR, CRC_CR_REV_OUT, ReverseMode);
}

   
                                                                       
                                                                      
                             
                                                              
                                                 
                                                
    
__STATIC_INLINE uint32_t LL_CRC_GetOutputDataReverseMode(const CRC_TypeDef *CRCx)
{
  return (uint32_t)(READ_BIT(CRCx->CR, CRC_CR_REV_OUT));
}

   
                                                          
                                                                            
                                               
                                                                                      
                                                            
                             
                                                                                     
                
    
__STATIC_INLINE void LL_CRC_SetInitialData(CRC_TypeDef *CRCx, uint32_t InitCrc)
{
  WRITE_REG(CRCx->INIT, InitCrc);
}

   
                                             
                                                                            
                                              
                                                            
                             
                                                                       
    
__STATIC_INLINE uint32_t LL_CRC_GetInitialData(const CRC_TypeDef *CRCx)
{
  return (uint32_t)(READ_REG(CRCx->INIT));
}

   
                                                        
                                                                            
                                                                                       
                                                                     
                                                                       
                                                                                                
                                                               
                             
                                                                                        
                
    
__STATIC_INLINE void LL_CRC_SetPolynomialCoef(CRC_TypeDef *CRCx, uint32_t PolynomCoef)
{
  WRITE_REG(CRCx->POL, PolynomCoef);
}

   
                                                        
                                                                     
                                                                       
                                                                                                
                                                               
                             
                                                                      
    
__STATIC_INLINE uint32_t LL_CRC_GetPolynomialCoef(const CRC_TypeDef *CRCx)
{
  return (uint32_t)(READ_REG(CRCx->POL));
}

   
      
    

                                                       
      
    

   
                                                         
                                                        
                             
                                                                                                            
                
    
__STATIC_INLINE void LL_CRC_FeedData32(CRC_TypeDef *CRCx, uint32_t InData)
{
  WRITE_REG(CRCx->DR, InData);
}

   
                                                         
                                                        
                             
                                                                                                               
                
    
__STATIC_INLINE void LL_CRC_FeedData16(CRC_TypeDef *CRCx, uint16_t InData)
{
  __IO uint16_t *pReg;

  pReg = (__IO uint16_t *)(__IO void *)(&CRCx->DR);                                                               
  *pReg = InData;
}

   
                                                        
                                                       
                             
                                                                                                            
                
    
__STATIC_INLINE void LL_CRC_FeedData8(CRC_TypeDef *CRCx, uint8_t InData)
{
  *(uint8_t __IO *)(&CRCx->DR) = (uint8_t) InData;
}

   
                                                                             
                                                        
                             
                                                                                  
    
__STATIC_INLINE uint32_t LL_CRC_ReadData32(const CRC_TypeDef *CRCx)
{
  return (uint32_t)(READ_REG(CRCx->DR));
}

   
                                                                             
                                                                                          
                                                        
                             
                                                                                  
    
__STATIC_INLINE uint16_t LL_CRC_ReadData16(const CRC_TypeDef *CRCx)
{
  return (uint16_t)READ_REG(CRCx->DR);
}

   
                                                                            
                                                                                         
                                                       
                             
                                                                                 
    
__STATIC_INLINE uint8_t LL_CRC_ReadData8(const CRC_TypeDef *CRCx)
{
  return (uint8_t)READ_REG(CRCx->DR);
}

   
                                                                            
                                                                                         
                                                       
                             
                                                                                 
    
__STATIC_INLINE uint8_t LL_CRC_ReadData7(const CRC_TypeDef *CRCx)
{
  return (uint8_t)(READ_REG(CRCx->DR) & 0x7FU);
}

   
                                                                     
                                                                      
                                                                                    
                                                      
                             
                                            
    
__STATIC_INLINE uint32_t LL_CRC_Read_IDR(const CRC_TypeDef *CRCx)
{
  return (uint32_t)(READ_REG(CRCx->IDR));
}

   
                                                             
                                                                      
                                                                                    
                                                       
                             
                                                         
                
    
__STATIC_INLINE void LL_CRC_Write_IDR(CRC_TypeDef *CRCx, uint32_t InData)
{
#if (CRC_IDR_IDR == 0x0FFU)
  *((uint8_t __IO *)(&CRCx->IDR)) = (uint8_t) InData;
#else
  WRITE_REG(CRCx->IDR, InData);
#endif
}
   
      
    

#if defined(USE_FULL_LL_DRIVER)
                                                                           
      
    

ErrorStatus LL_CRC_DeInit(const CRC_TypeDef *CRCx);

   
      
    
#endif                         

   
      
    

   
      
    

#endif                   

   
      
    

#ifdef __cplusplus
}
#endif

#endif                         
