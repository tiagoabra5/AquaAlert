/**
  ******************************************************************************
  * @file    stm32l4xx_ll_rng.h
  * @author  MCD Application Team
  * @brief   Header file of RNG LL module.
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

                                                                                
#ifndef STM32L4xx_LL_RNG_H
#define STM32L4xx_LL_RNG_H

#ifdef __cplusplus
extern "C" {
#endif

                                                                                
#include "stm32l4xx.h"

                                   
      
    

#if defined (RNG)

                        
      
    

                                                                                
                                                                                
                                                        
      
    
                                                                       
#define LL_RNG_HTCFG   0x17590ABCU                     
   
      
    
                                                                                
                                                                                
                                                                                

                                                                                
#if defined(RNG_CR_CED)
#if defined(USE_FULL_LL_DRIVER)
                                                                
      
    


   
                                           
    
typedef struct
{
  uint32_t         ClockErrorDetection;                            
                                                                                         
                                                                                  
                                                                                      
} LL_RNG_InitTypeDef;

   
      
    
#endif                         
#endif                 
                                                                                
                                                              
      
    

#if defined(RNG_CR_CED)
                                              
      
    
#define LL_RNG_CED_ENABLE         0x00000000U                                                    
#define LL_RNG_CED_DISABLE        RNG_CR_CED                                                     
   
      
    
#endif                 

#if defined(RNG_CR_CONDRST)
                                                                              
                                                                    
      
    
#define LL_RNG_CLKDIV_BY_1       (0x00000000UL)                                                                                                                
#define LL_RNG_CLKDIV_BY_2       (RNG_CR_CLKDIV_0)                                                                                                             
#define LL_RNG_CLKDIV_BY_4       (RNG_CR_CLKDIV_1)                                                                                                             
#define LL_RNG_CLKDIV_BY_8       (RNG_CR_CLKDIV_1 | RNG_CR_CLKDIV_0)                                                                                           
#define LL_RNG_CLKDIV_BY_16      (RNG_CR_CLKDIV_2)                                                                                                             
#define LL_RNG_CLKDIV_BY_32      (RNG_CR_CLKDIV_2 | RNG_CR_CLKDIV_0)                                                                                           
#define LL_RNG_CLKDIV_BY_64      (RNG_CR_CLKDIV_2 | RNG_CR_CLKDIV_1)                                                                                           
#define LL_RNG_CLKDIV_BY_128     (RNG_CR_CLKDIV_2 | RNG_CR_CLKDIV_1 | RNG_CR_CLKDIV_0)                                                                         
#define LL_RNG_CLKDIV_BY_256     (RNG_CR_CLKDIV_3)                                                                                                             
#define LL_RNG_CLKDIV_BY_512     (RNG_CR_CLKDIV_3 | RNG_CR_CLKDIV_0)                                                                                           
#define LL_RNG_CLKDIV_BY_1024    (RNG_CR_CLKDIV_3 | RNG_CR_CLKDIV_1)                                                                                           
#define LL_RNG_CLKDIV_BY_2048    (RNG_CR_CLKDIV_3 | RNG_CR_CLKDIV_1 | RNG_CR_CLKDIV_0)                                                                         
#define LL_RNG_CLKDIV_BY_4096    (RNG_CR_CLKDIV_3 | RNG_CR_CLKDIV_2)                                                                                           
#define LL_RNG_CLKDIV_BY_8192    (RNG_CR_CLKDIV_3 | RNG_CR_CLKDIV_2 | RNG_CR_CLKDIV_0)                                                                         
#define LL_RNG_CLKDIV_BY_16384   (RNG_CR_CLKDIV_3 | RNG_CR_CLKDIV_2 | RNG_CR_CLKDIV_1)                                                                         
#define LL_RNG_CLKDIV_BY_32768   (RNG_CR_CLKDIV_3 | RNG_CR_CLKDIV_2 | RNG_CR_CLKDIV_1 | RNG_CR_CLKDIV_0)                                                       
   
      
    

                                                                   
      
    
#define LL_RNG_NIST_COMPLIANT     (0x00000000UL)                                            
#define LL_RNG_CUSTOM_NIST        (RNG_CR_NISTC)                                  

                  
#define LL_RNG_NOTNIST_COMPLIANT LL_RNG_CUSTOM_NIST
   
      
    

#endif                     
                                                  
                                                                          
      
    
#define LL_RNG_SR_DRDY RNG_SR_DRDY                                               
#define LL_RNG_SR_CECS RNG_SR_CECS                                      
#define LL_RNG_SR_SECS RNG_SR_SECS                                     
#define LL_RNG_SR_CEIS RNG_SR_CEIS                                        
#define LL_RNG_SR_SEIS RNG_SR_SEIS                                       
   
      
    

                                     
                                                                                          
      
    
#define LL_RNG_CR_IE   RNG_CR_IE                                  
   
      
    

   
      
    

                                                                                
                                                        
      
    

                                                                         
      
    

   
                                         
                                     
                                          
                                                         
                
    
#define LL_RNG_WriteReg(__INSTANCE__, __REG__, __VALUE__) WRITE_REG(__INSTANCE__->__REG__, (__VALUE__))

   
                                        
                                     
                                       
                          
    
#define LL_RNG_ReadReg(__INSTANCE__, __REG__) READ_REG(__INSTANCE__->__REG__)
   
      
    

   
      
    


                                                                                
                                                              
      
    
#if defined(RNG_CR_CONDRST)
                                                
       
    
#define LL_RNG_SetConditioningResetBit            LL_RNG_EnableCondReset
#define LL_RNG_ResetConditioningResetBit          LL_RNG_DisableCondReset
#define LL_RNG_IsResetConditioningBitSet          LL_RNG_IsEnabledCondReset
#define LL_RNG_IsNistComplianceEnabled            LL_RNG_IsEnabledNistCompliance
#endif                     

#if defined(RNG_VER_3_2)
#define LL_RNG_SetHealthconfiguration             LL_RNG_SetHealthConfig
#define LL_RNG_GetHealthconfiguration             LL_RNG_GetHealthConfig
#endif                   
   
        
    
                                                                 
      
    

   
                                           
                                                    
                             
                
    
__STATIC_INLINE void LL_RNG_Enable(RNG_TypeDef *RNGx)
{
  SET_BIT(RNGx->CR, RNG_CR_RNGEN);
}

   
                                            
                                                     
                             
                
    
__STATIC_INLINE void LL_RNG_Disable(RNG_TypeDef *RNGx)
{
  CLEAR_BIT(RNGx->CR, RNG_CR_RNGEN);
}

   
                                                       
                                                       
                             
                                  
    
__STATIC_INLINE uint32_t LL_RNG_IsEnabled(const RNG_TypeDef *RNGx)
{
  return ((READ_BIT(RNGx->CR, RNG_CR_RNGEN) == (RNG_CR_RNGEN)) ? 1UL : 0UL);
}

#if defined(RNG_CR_CED)
   
                                        
                                                                  
                             
                
    
__STATIC_INLINE void LL_RNG_EnableClkErrorDetect(RNG_TypeDef *RNGx)
{
#if defined(RNG_CR_CONDRST)
  MODIFY_REG(RNGx->CR, RNG_CR_CED | RNG_CR_CONDRST, LL_RNG_CED_ENABLE | RNG_CR_CONDRST);
  CLEAR_BIT(RNGx->CR, RNG_CR_CONDRST);
#else
  CLEAR_BIT(RNGx->CR, RNG_CR_CED);
#endif                    
}

   
                                             
                                                                 
                             
                
    
__STATIC_INLINE void LL_RNG_DisableClkErrorDetect(RNG_TypeDef *RNGx)
{
#if defined(RNG_CR_CONDRST)
  MODIFY_REG(RNGx->CR, RNG_CR_CED | RNG_CR_CONDRST, LL_RNG_CED_DISABLE | RNG_CR_CONDRST);
  CLEAR_BIT(RNGx->CR, RNG_CR_CONDRST);
#else
  SET_BIT(RNGx->CR, RNG_CR_CED);
#endif                    
}

   
                                                         
                                                                   
                             
                                  
    
__STATIC_INLINE uint32_t LL_RNG_IsEnabledClkErrorDetect(const RNG_TypeDef *RNGx)
{
  return ((READ_BIT(RNGx->CR, RNG_CR_CED) != (RNG_CR_CED)) ? 1UL : 0UL);
}

#if defined(RNG_CR_CONDRST)
   
                                               
                                                                
                             
                
    
__STATIC_INLINE void LL_RNG_EnableCondReset(RNG_TypeDef *RNGx)
{
  SET_BIT(RNGx->CR, RNG_CR_CONDRST);
}

   
                                                  
                                                                
                             
                
    
__STATIC_INLINE void LL_RNG_DisableCondReset(RNG_TypeDef *RNGx)
{
  CLEAR_BIT(RNGx->CR, RNG_CR_CONDRST);
}

   
                                                           
                                                                  
                             
                                  
    
__STATIC_INLINE uint32_t LL_RNG_IsEnabledCondReset(const RNG_TypeDef *RNGx)
{
  return ((READ_BIT(RNGx->CR, RNG_CR_CONDRST) == (RNG_CR_CONDRST)) ? 1UL : 0UL);
}

   
                                  
                                                              
                             
                
    
__STATIC_INLINE void LL_RNG_ConfigLock(RNG_TypeDef *RNGx)
{
  SET_BIT(RNGx->CR, RNG_CR_CONFIGLOCK);
}

   
                                               
                                                                 
                             
                                  
    
__STATIC_INLINE uint32_t LL_RNG_IsConfigLocked(const RNG_TypeDef *RNGx)
{
  return ((READ_BIT(RNGx->CR, RNG_CR_CONFIGLOCK) == (RNG_CR_CONFIGLOCK)) ? 1UL : 0UL);
}

   
                                  
                                                                   
                             
                
    
__STATIC_INLINE void LL_RNG_EnableNistCompliance(RNG_TypeDef *RNGx)
{
  MODIFY_REG(RNGx->CR, RNG_CR_NISTC | RNG_CR_CONDRST, LL_RNG_NIST_COMPLIANT | RNG_CR_CONDRST);
  CLEAR_BIT(RNGx->CR, RNG_CR_CONDRST);
}

   
                                   
                                                                   
                             
                
    
__STATIC_INLINE void LL_RNG_DisableNistCompliance(RNG_TypeDef *RNGx)
{
  MODIFY_REG(RNGx->CR, RNG_CR_NISTC | RNG_CR_CONDRST, LL_RNG_CUSTOM_NIST | RNG_CR_CONDRST);
  CLEAR_BIT(RNGx->CR, RNG_CR_CONDRST);
}

   
                                               
                                                                     
                             
                                  
    
__STATIC_INLINE uint32_t LL_RNG_IsEnabledNistCompliance(const RNG_TypeDef *RNGx)
{
  return ((READ_BIT(RNGx->CR, RNG_CR_NISTC) != (RNG_CR_NISTC)) ? 1UL : 0UL);
}

   
                                                      
                                                              
                             
                                            
                
    
__STATIC_INLINE void LL_RNG_SetConfig1(RNG_TypeDef *RNGx, uint32_t Config1)
{
  MODIFY_REG(RNGx->CR, RNG_CR_RNG_CONFIG1 | RNG_CR_CONDRST, (Config1 << RNG_CR_RNG_CONFIG1_Pos) | RNG_CR_CONDRST);
  CLEAR_BIT(RNGx->CR, RNG_CR_CONDRST);
}

   
                                                      
                                                              
                             
                                                                         
    
__STATIC_INLINE uint32_t LL_RNG_GetConfig1(const RNG_TypeDef *RNGx)
{
  return (uint32_t)(READ_BIT(RNGx->CR, RNG_CR_RNG_CONFIG1) >> RNG_CR_RNG_CONFIG1_Pos);
}

   
                                                      
                                                              
                             
                                           
                
    
__STATIC_INLINE void LL_RNG_SetConfig2(RNG_TypeDef *RNGx, uint32_t Config2)
{
  MODIFY_REG(RNGx->CR, RNG_CR_RNG_CONFIG2 | RNG_CR_CONDRST, (Config2 << RNG_CR_RNG_CONFIG2_Pos) | RNG_CR_CONDRST);
  CLEAR_BIT(RNGx->CR, RNG_CR_CONDRST);
}

   
                                                      
                                                              
                             
                                                                        
    
__STATIC_INLINE uint32_t LL_RNG_GetConfig2(const RNG_TypeDef *RNGx)
{
  return (uint32_t)(READ_BIT(RNGx->CR, RNG_CR_RNG_CONFIG2) >> RNG_CR_RNG_CONFIG2_Pos);
}

   
                                                      
                                                              
                             
                                           
                
    
__STATIC_INLINE void LL_RNG_SetConfig3(RNG_TypeDef *RNGx, uint32_t Config3)
{
  MODIFY_REG(RNGx->CR, RNG_CR_RNG_CONFIG3 | RNG_CR_CONDRST, (Config3 << RNG_CR_RNG_CONFIG3_Pos) | RNG_CR_CONDRST);
  CLEAR_BIT(RNGx->CR, RNG_CR_CONDRST);
}

   
                                                      
                                                              
                             
                                                                        
    
__STATIC_INLINE uint32_t LL_RNG_GetConfig3(const RNG_TypeDef *RNGx)
{
  return (uint32_t)(READ_BIT(RNGx->CR, RNG_CR_RNG_CONFIG3) >> RNG_CR_RNG_CONFIG3_Pos);
}

   
                                         
                                                              
                             
                                                       
                                        
                                        
                                        
                                        
                                         
                                         
                                         
                                          
                                          
                                          
                                           
                                           
                                           
                                           
                                            
                                            
                
    
__STATIC_INLINE void LL_RNG_SetClockDivider(RNG_TypeDef *RNGx, uint32_t Divider)
{
  MODIFY_REG(RNGx->CR, RNG_CR_CLKDIV | RNG_CR_CONDRST, Divider | RNG_CR_CONDRST);
  CLEAR_BIT(RNGx->CR, RNG_CR_CONDRST);
}

   
                                         
                                                              
                             
                                                              
                                        
                                        
                                        
                                        
                                         
                                         
                                         
                                          
                                          
                                          
                                           
                                           
                                           
                                           
                                            
                                            
    
__STATIC_INLINE uint32_t LL_RNG_GetClockDivider(const RNG_TypeDef *RNGx)
{
  return (uint32_t)READ_BIT(RNGx->CR, RNG_CR_CLKDIV);
}
#endif                     
#endif                 
   
      
    

                                                       
      
    

   
                                                             
                                                               
                             
                                  
    
__STATIC_INLINE uint32_t LL_RNG_IsActiveFlag_DRDY(const RNG_TypeDef *RNGx)
{
  return ((READ_BIT(RNGx->SR, RNG_SR_DRDY) == (RNG_SR_DRDY)) ? 1UL : 0UL);
}

   
                                                                         
                                                               
                             
                                  
    
__STATIC_INLINE uint32_t LL_RNG_IsActiveFlag_CECS(const RNG_TypeDef *RNGx)
{
  return ((READ_BIT(RNGx->SR, RNG_SR_CECS) == (RNG_SR_CECS)) ? 1UL : 0UL);
}

   
                                                                        
                                                               
                             
                                  
    
__STATIC_INLINE uint32_t LL_RNG_IsActiveFlag_SECS(const RNG_TypeDef *RNGx)
{
  return ((READ_BIT(RNGx->SR, RNG_SR_SECS) == (RNG_SR_SECS)) ? 1UL : 0UL);
}

   
                                                                           
                                                               
                             
                                  
    
__STATIC_INLINE uint32_t LL_RNG_IsActiveFlag_CEIS(const RNG_TypeDef *RNGx)
{
  return ((READ_BIT(RNGx->SR, RNG_SR_CEIS) == (RNG_SR_CEIS)) ? 1UL : 0UL);
}

   
                                                                          
                                                               
                             
                                  
    
__STATIC_INLINE uint32_t LL_RNG_IsActiveFlag_SEIS(const RNG_TypeDef *RNGx)
{
  return ((READ_BIT(RNGx->SR, RNG_SR_SEIS) == (RNG_SR_SEIS)) ? 1UL : 0UL);
}

   
                                                          
                                                            
                             
                
    
__STATIC_INLINE void LL_RNG_ClearFlag_CEIS(RNG_TypeDef *RNGx)
{
  WRITE_REG(RNGx->SR, ~RNG_SR_CEIS);
}

   
                                                         
                                                            
                             
                
    
__STATIC_INLINE void LL_RNG_ClearFlag_SEIS(RNG_TypeDef *RNGx)
{
  WRITE_REG(RNGx->SR, ~RNG_SR_SEIS);
}

   
      
    

                                                   
      
    

   
                                                    
                                                                                 
                                                      
                             
                
    
__STATIC_INLINE void LL_RNG_EnableIT(RNG_TypeDef *RNGx)
{
  SET_BIT(RNGx->CR, RNG_CR_IE);
}

   
                                                     
                                                                                 
                                                       
                             
                
    
__STATIC_INLINE void LL_RNG_DisableIT(RNG_TypeDef *RNGx)
{
  CLEAR_BIT(RNGx->CR, RNG_CR_IE);
}

   
                                                                 
                                                                                 
                                                         
                             
                                  
    
__STATIC_INLINE uint32_t LL_RNG_IsEnabledIT(const RNG_TypeDef *RNGx)
{
  return ((READ_BIT(RNGx->CR, RNG_CR_IE) == (RNG_CR_IE)) ? 1UL : 0UL);
}

   
      
    

                                                       
      
    

   
                                            
                                                            
                             
                                         
    
__STATIC_INLINE uint32_t LL_RNG_ReadRandData32(const RNG_TypeDef *RNGx)
{
  return (uint32_t)(READ_REG(RNGx->DR));
}

   
      
    

#if defined(RNG_VER_3_2)
                                                               
      
    

   
                                       
                                                         
                             
                                          
                
    
__STATIC_INLINE void LL_RNG_SetHealthConfig(RNG_TypeDef *RNGx, uint32_t HTCFG)
{
                                                                      
  WRITE_REG(RNGx->HTCR, RNG_HTCFG_1);

                                                                                            
  WRITE_REG(RNGx->HTCR, RNG_HTCFG);
}

   
                                       
                                                            
                             
                                                       
    
__STATIC_INLINE uint32_t LL_RNG_GetHealthConfig(RNG_TypeDef *RNGx)
{
                                                                           
  WRITE_REG(RNGx->HTCR, RNG_HTCFG_1);
  return (uint32_t)READ_REG(RNGx->HTCR);
}
#else
   
      
    
#endif                  
#if defined(USE_FULL_LL_DRIVER)
                                                                           
      
    
#if defined(RNG_CR_CED)
ErrorStatus LL_RNG_Init(RNG_TypeDef *RNGx, const LL_RNG_InitTypeDef *RNG_InitStruct);
void LL_RNG_StructInit(LL_RNG_InitTypeDef *RNG_InitStruct);
#endif                  
ErrorStatus LL_RNG_DeInit(const RNG_TypeDef *RNGx);

   
      
    
#endif                         

   
      
    

   
      
    

#endif          

   
      
    

#ifdef __cplusplus
}
#endif

#endif                           

