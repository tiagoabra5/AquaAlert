/**
  ******************************************************************************
  * @file    stm32l4xx_ll_pka.h
  * @author  MCD Application Team
  * @brief   Header file of PKA LL module.
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

                                                                                
#ifndef STM32L4xx_LL_PKA_H
#define STM32L4xx_LL_PKA_H

#ifdef __cplusplus
extern "C" {
#endif

                                                                                
#include "stm32l4xx.h"

                                   
      
    

#if defined(PKA)

                        
      
    

                                                                                

                                                                                
#if defined(USE_FULL_LL_DRIVER)
                                                        
      
    

   
                                          
    
typedef struct
{
  uint32_t Mode;                                                
                                                                                    

                                                                                                                       
} LL_PKA_InitTypeDef;

   
      
    
#endif                         

                                                                                
                                                              
      
    

                                                  
                                                                          
      
    
#define LL_PKA_SR_ADDRERRF                 PKA_SR_ADDRERRF
#define LL_PKA_SR_RAMERRF                  PKA_SR_RAMERRF
#define LL_PKA_SR_PROCENDF                 PKA_SR_PROCENDF
#define LL_PKA_SR_BUSY                     PKA_SR_BUSY
   
      
    

                                     
                                                                                             
      
    
#define LL_PKA_CR_ADDRERRIE                PKA_CR_ADDRERRIE
#define LL_PKA_CR_RAMERRIE                 PKA_CR_RAMERRIE
#define LL_PKA_CR_PROCENDIE                PKA_CR_PROCENDIE
#define LL_PKA_CLRFR_PROCENDFC             PKA_CLRFR_PROCENDFC
#define LL_PKA_CLRFR_RAMERRFC              PKA_CLRFR_RAMERRFC
#define LL_PKA_CLRFR_ADDRERRFC             PKA_CLRFR_ADDRERRFC
   
      
    

                                           
                                     
      
    
#define LL_PKA_MODE_MONTGOMERY_PARAM_MOD_EXP ((uint32_t)0x00000000U)                                                                
#define LL_PKA_MODE_MONTGOMERY_PARAM         ((uint32_t)0x00000001U)                                          
#define LL_PKA_MODE_MODULAR_EXP              ((uint32_t)0x00000002U)                                                                                    
#define LL_PKA_MODE_MONTGOMERY_PARAM_ECC     ((uint32_t)0x00000020U)                                                                  
#define LL_PKA_MODE_ECC_KP_PRIMITIVE         ((uint32_t)0x00000022U)                                                                                  
#define LL_PKA_MODE_ECDSA_SIGNATURE          ((uint32_t)0x00000024U)                        
#define LL_PKA_MODE_ECDSA_VERIFICATION       ((uint32_t)0x00000026U)                           
#define LL_PKA_MODE_POINT_CHECK              ((uint32_t)0x00000028U)                    
#define LL_PKA_MODE_RSA_CRT_EXP              ((uint32_t)0x00000007U)                               
#define LL_PKA_MODE_MODULAR_INV              ((uint32_t)0x00000008U)                          
#define LL_PKA_MODE_ARITHMETIC_ADD           ((uint32_t)0x00000009U)                            
#define LL_PKA_MODE_ARITHMETIC_SUB           ((uint32_t)0x0000000AU)                               
#define LL_PKA_MODE_ARITHMETIC_MUL           ((uint32_t)0x0000000BU)                                  
#define LL_PKA_MODE_COMPARISON               ((uint32_t)0x0000000CU)                   
#define LL_PKA_MODE_MODULAR_REDUC            ((uint32_t)0x0000000DU)                          
#define LL_PKA_MODE_MODULAR_ADD              ((uint32_t)0x0000000EU)                         
#define LL_PKA_MODE_MODULAR_SUB              ((uint32_t)0x0000000FU)                            
#define LL_PKA_MODE_MONTGOMERY_MUL           ((uint32_t)0x00000010U)                                  

   
      
    

   
      
    

                                                                                
                                                        
      
    

                                                                         
      
    

   
                                         
                                     
                                          
                                                         
                
    
#define LL_PKA_WriteReg(__INSTANCE__, __REG__, __VALUE__) WRITE_REG(__INSTANCE__->__REG__, (__VALUE__))

   
                                        
                                     
                                       
                          
    
#define LL_PKA_ReadReg(__INSTANCE__, __REG__) READ_REG(__INSTANCE__->__REG__)
   
      
    

   
      
    

                                                                                
                                                              
      
    

                                                   
      
    

   
                                     
                                   
                                                    
                              
                                                                   
                                                          
                                                      
                                                  
                                             
                                                  
                                                 
                                                    
                                             
                                             
                                             
                                                
                                                
                                                
                                            
                                               
                                             
                                             
                                                
    
__STATIC_INLINE void LL_PKA_Config(PKA_TypeDef *PKAx, uint32_t Mode)
{
  MODIFY_REG(PKAx->CR, (PKA_CR_MODE), (Mode << PKA_CR_MODE_Pos));
}

   
                                  
                                                    
                              
                
    
__STATIC_INLINE void LL_PKA_Enable(PKA_TypeDef *PKAx)
{
  SET_BIT(PKAx->CR, PKA_CR_EN);
}

   
                                   
                                                     
                              
                
    
__STATIC_INLINE void LL_PKA_Disable(PKA_TypeDef *PKAx)
{
  CLEAR_BIT(PKAx->CR, PKA_CR_EN);
}

   
                                                               
                                                       
                              
                                  
    
__STATIC_INLINE uint32_t LL_PKA_IsEnabled(const PKA_TypeDef *PKAx)
{
  return ((READ_BIT(PKAx->CR, PKA_CR_EN) == (PKA_CR_EN)) ? 1UL : 0UL);
}

   
                                   
                                                     
                              
                                                                   
                                                          
                                                      
                                                  
                                             
                                                  
                                                 
                                                    
                                             
                                             
                                             
                                                
                                                
                                                
                                            
                                               
                                             
                                             
                                                
                
    
__STATIC_INLINE void LL_PKA_SetMode(PKA_TypeDef *PKAx, uint32_t Mode)
{
  MODIFY_REG(PKAx->CR, PKA_CR_MODE, Mode << PKA_CR_MODE_Pos);
}

   
                                   
                                                     
                              
                                                              
                                                          
                                                      
                                                  
                                             
                                                  
                                                 
                                                    
                                             
                                             
                                             
                                                
                                                
                                                
                                            
                                               
                                             
                                             
                                                
    
__STATIC_INLINE uint32_t LL_PKA_GetMode(const PKA_TypeDef *PKAx)
{
  return (uint32_t)(READ_BIT(PKAx->CR, PKA_CR_MODE) >> PKA_CR_MODE_Pos);
}

   
                                                              
                                                   
                              
                
    
__STATIC_INLINE void LL_PKA_Start(PKA_TypeDef *PKAx)
{
  SET_BIT(PKAx->CR, PKA_CR_START);
}

   
      
    

                                                   
      
    

   
                                           
                                                              
                              
                
    
__STATIC_INLINE void LL_PKA_EnableIT_ADDRERR(PKA_TypeDef *PKAx)
{
  SET_BIT(PKAx->CR, PKA_CR_ADDRERRIE);
}

   
                                       
                                                             
                              
                
    
__STATIC_INLINE void LL_PKA_EnableIT_RAMERR(PKA_TypeDef *PKAx)
{
  SET_BIT(PKAx->CR, PKA_CR_RAMERRIE);
}


   
                                              
                                                              
                              
                
    
__STATIC_INLINE void LL_PKA_EnableIT_PROCEND(PKA_TypeDef *PKAx)
{
  SET_BIT(PKAx->CR, PKA_CR_PROCENDIE);
}

   
                                            
                                                              
                              
                
    
__STATIC_INLINE void LL_PKA_DisableIT_ADDERR(PKA_TypeDef *PKAx)
{
  CLEAR_BIT(PKAx->CR, PKA_CR_ADDRERRIE);
}

   
                                        
                                                              
                              
                
    
__STATIC_INLINE void LL_PKA_DisableIT_RAMERR(PKA_TypeDef *PKAx)
{
  CLEAR_BIT(PKAx->CR, PKA_CR_RAMERRIE);
}

   
                                               
                                                               
                              
                
    
__STATIC_INLINE void LL_PKA_DisableIT_PROCEND(PKA_TypeDef *PKAx)
{
  CLEAR_BIT(PKAx->CR, PKA_CR_PROCENDIE);
}

   
                                                        
                                                                 
                              
                                  
    
__STATIC_INLINE uint32_t LL_PKA_IsEnabledIT_ADDRERR(const PKA_TypeDef *PKAx)
{
  return ((READ_BIT(PKAx->CR, PKA_CR_ADDRERRIE) == (PKA_CR_ADDRERRIE)) ? 1UL : 0UL);
}

   
                                                    
                                                                
                              
                                  
    
__STATIC_INLINE uint32_t LL_PKA_IsEnabledIT_RAMERR(const PKA_TypeDef *PKAx)
{
  return ((READ_BIT(PKAx->CR, PKA_CR_RAMERRIE) == (PKA_CR_RAMERRIE)) ? 1UL : 0UL);
}


   
                                                           
                                                                 
                              
                                  
    
__STATIC_INLINE uint32_t LL_PKA_IsEnabledIT_PROCEND(const PKA_TypeDef *PKAx)
{
  return ((READ_BIT(PKAx->CR, PKA_CR_PROCENDIE) == (PKA_CR_PROCENDIE)) ? 1UL : 0UL);
}

   
      
    

                                                           
      
    

   
                                       
                                                                  
                              
                                  
    
__STATIC_INLINE uint32_t LL_PKA_IsActiveFlag_ADDRERR(const PKA_TypeDef *PKAx)
{
  return ((READ_BIT(PKAx->SR, PKA_SR_ADDRERRF) == (PKA_SR_ADDRERRF)) ? 1UL : 0UL);
}

   
                                   
                                                                 
                              
                                  
    
__STATIC_INLINE uint32_t LL_PKA_IsActiveFlag_RAMERR(const PKA_TypeDef *PKAx)
{
  return ((READ_BIT(PKAx->SR, PKA_SR_RAMERRF) == (PKA_SR_RAMERRF)) ? 1UL : 0UL);
}


   
                                          
                                                                  
                              
                                  
    
__STATIC_INLINE uint32_t LL_PKA_IsActiveFlag_PROCEND(const PKA_TypeDef *PKAx)
{
  return ((READ_BIT(PKAx->SR, PKA_SR_PROCENDF) == (PKA_SR_PROCENDF)) ? 1UL : 0UL);
}

   
                              
                                                               
                              
                                  
    
__STATIC_INLINE uint32_t LL_PKA_IsActiveFlag_BUSY(const PKA_TypeDef *PKAx)
{
  return ((READ_BIT(PKAx->SR, PKA_SR_BUSY) == (PKA_SR_BUSY)) ? 1UL : 0UL);
}
#if defined(PKA_SR_INITOK)
   
                                 
                                                                   
                              
                                  
    
__STATIC_INLINE uint32_t LL_PKA_IsActiveFlag_INITOK(const PKA_TypeDef *PKAx)
{
  return ((READ_BIT(PKAx->SR, PKA_SR_INITOK) == (PKA_SR_INITOK)) ? 1UL : 0UL);
}
#endif                    
   
                                         
                                                              
                              
                
    
__STATIC_INLINE void LL_PKA_ClearFlag_ADDERR(PKA_TypeDef *PKAx)
{
  SET_BIT(PKAx->CLRFR, PKA_CLRFR_ADDRERRFC);
}

   
                                     
                                                              
                              
                
    
__STATIC_INLINE void LL_PKA_ClearFlag_RAMERR(PKA_TypeDef *PKAx)
{
  SET_BIT(PKAx->CLRFR, PKA_CLRFR_RAMERRFC);
}


   
                                            
                                                               
                              
                
    
__STATIC_INLINE void LL_PKA_ClearFlag_PROCEND(PKA_TypeDef *PKAx)
{
  SET_BIT(PKAx->CLRFR, PKA_CLRFR_PROCENDFC);
}

   
      
    

#if defined(USE_FULL_LL_DRIVER)

                                                                           
      
    

ErrorStatus LL_PKA_DeInit(const PKA_TypeDef *PKAx);
ErrorStatus LL_PKA_Init(PKA_TypeDef *PKAx, LL_PKA_InitTypeDef *PKA_InitStruct);
void LL_PKA_StructInit(LL_PKA_InitTypeDef *PKA_InitStruct);

   
      
    

#endif                         
   
      
    

   
      
    

#endif                   

   
      
    

#ifdef __cplusplus
}
#endif

#endif                         
