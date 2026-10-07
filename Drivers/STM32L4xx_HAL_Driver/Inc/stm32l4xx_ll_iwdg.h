/**
  ******************************************************************************
  * @file    stm32l4xx_ll_iwdg.h
  * @author  MCD Application Team
  * @brief   Header file of IWDG LL module.
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

                                                                                
#ifndef STM32L4xx_LL_IWDG_H
#define STM32L4xx_LL_IWDG_H

#ifdef __cplusplus
extern "C" {
#endif

                                                                                
#include "stm32l4xx.h"

                                   
      
    

#if defined(IWDG)

                          
      
    

                                                                                
                                                                                

                                                                                
                                                              
      
    
#define LL_IWDG_KEY_RELOAD                 0x0000AAAAU                                                   
#define LL_IWDG_KEY_ENABLE                 0x0000CCCCU                                                   
#define LL_IWDG_KEY_WR_ACCESS_ENABLE       0x00005555U                                                   
#define LL_IWDG_KEY_WR_ACCESS_DISABLE      0x00000000U                                                   
   
      
    

                                                                                

                                                                                
                                                                                
                                                                
      
    

                                                   
                                                                           
      
    
#define LL_IWDG_SR_PVU                     IWDG_SR_PVU                                                                  
#define LL_IWDG_SR_RVU                     IWDG_SR_RVU                                                                       
#define LL_IWDG_SR_WVU                     IWDG_SR_WVU                                                                       
   
      
    

                                                     
      
    
#define LL_IWDG_PRESCALER_4                0x00000000U                                                 
#define LL_IWDG_PRESCALER_8                (IWDG_PR_PR_0)                                              
#define LL_IWDG_PRESCALER_16               (IWDG_PR_PR_1)                                              
#define LL_IWDG_PRESCALER_32               (IWDG_PR_PR_1 | IWDG_PR_PR_0)                               
#define LL_IWDG_PRESCALER_64               (IWDG_PR_PR_2)                                              
#define LL_IWDG_PRESCALER_128              (IWDG_PR_PR_2 | IWDG_PR_PR_0)                               
#define LL_IWDG_PRESCALER_256              (IWDG_PR_PR_2 | IWDG_PR_PR_1)                               
   
      
    

   
      
    

                                                                                
                                                          
      
    

                                                                          
      
    

   
                                          
                                      
                                          
                                                         
                
    
#define LL_IWDG_WriteReg(__INSTANCE__, __REG__, __VALUE__) WRITE_REG(__INSTANCE__->__REG__, (__VALUE__))

   
                                         
                                      
                                       
                          
    
#define LL_IWDG_ReadReg(__INSTANCE__, __REG__) READ_REG(__INSTANCE__->__REG__)
   
      
    

   
      
    


                                                                                
                                                                
      
    
                                                    
      
    

   
                                          
                                                              
                                                     
                               
                
    
__STATIC_INLINE void LL_IWDG_Enable(IWDG_TypeDef *IWDGx)
{
  WRITE_REG(IWDGx->KR, LL_IWDG_KEY_ENABLE);
}

   
                                                                          
                                                            
                               
                
    
__STATIC_INLINE void LL_IWDG_ReloadCounter(IWDG_TypeDef *IWDGx)
{
  WRITE_REG(IWDGx->KR, LL_IWDG_KEY_RELOAD);
}

   
                                                                            
                                                                
                               
                
    
__STATIC_INLINE void LL_IWDG_EnableWriteAccess(IWDG_TypeDef *IWDGx)
{
  WRITE_REG(IWDGx->KR, LL_IWDG_KEY_WR_ACCESS_ENABLE);
}

   
                                                                             
                                                                 
                               
                
    
__STATIC_INLINE void LL_IWDG_DisableWriteAccess(IWDG_TypeDef *IWDGx)
{
  WRITE_REG(IWDGx->KR, LL_IWDG_KEY_WR_ACCESS_DISABLE);
}

   
                                            
                                                           
                               
                                                                        
                                         
                                         
                                          
                                          
                                          
                                           
                                           
                
    
__STATIC_INLINE void LL_IWDG_SetPrescaler(IWDG_TypeDef *IWDGx, uint32_t Prescaler)
{
  WRITE_REG(IWDGx->PR, IWDG_PR_PR & Prescaler);
}

   
                                                  
                                                           
                               
                                                              
                                         
                                         
                                          
                                          
                                          
                                           
                                           
    
__STATIC_INLINE uint32_t LL_IWDG_GetPrescaler(const IWDG_TypeDef *IWDGx)
{
  return (READ_REG(IWDGx->PR));
}

   
                                                      
                                                               
                               
                                                                
                
    
__STATIC_INLINE void LL_IWDG_SetReloadCounter(IWDG_TypeDef *IWDGx, uint32_t Counter)
{
  WRITE_REG(IWDGx->RLR, IWDG_RLR_RL & Counter);
}

   
                                                            
                                                               
                               
                                                        
    
__STATIC_INLINE uint32_t LL_IWDG_GetReloadCounter(const IWDG_TypeDef *IWDGx)
{
  return (READ_REG(IWDGx->RLR));
}

   
                                                                                      
                                                        
                               
                                                               
                
    
__STATIC_INLINE void LL_IWDG_SetWindow(IWDG_TypeDef *IWDGx, uint32_t Window)
{
  WRITE_REG(IWDGx->WINR, IWDG_WINR_WIN & Window);
}

   
                                                             
                                                        
                               
                                                        
    
__STATIC_INLINE uint32_t LL_IWDG_GetWindow(const IWDG_TypeDef *IWDGx)
{
  return (READ_REG(IWDGx->WINR));
}

   
      
    

                                                        
      
    

   
                                                              
                                                               
                               
                                  
    
__STATIC_INLINE uint32_t LL_IWDG_IsActiveFlag_PVU(const IWDG_TypeDef *IWDGx)
{
  return ((READ_BIT(IWDGx->SR, IWDG_SR_PVU) == (IWDG_SR_PVU)) ? 1UL : 0UL);
}

   
                                                           
                                                               
                               
                                  
    
__STATIC_INLINE uint32_t LL_IWDG_IsActiveFlag_RVU(const IWDG_TypeDef *IWDGx)
{
  return ((READ_BIT(IWDGx->SR, IWDG_SR_RVU) == (IWDG_SR_RVU)) ? 1UL : 0UL);
}

   
                                                           
                                                               
                               
                                  
    
__STATIC_INLINE uint32_t LL_IWDG_IsActiveFlag_WVU(const IWDG_TypeDef *IWDGx)
{
  return ((READ_BIT(IWDGx->SR, IWDG_SR_WVU) == (IWDG_SR_WVU)) ? 1UL : 0UL);
}

   
                                                                                       
                                                        
                                                        
                                                      
                               
                                   
    
__STATIC_INLINE uint32_t LL_IWDG_IsReady(const IWDG_TypeDef *IWDGx)
{
  return ((READ_BIT(IWDGx->SR, IWDG_SR_PVU | IWDG_SR_RVU | IWDG_SR_WVU) == 0U) ? 1UL : 0UL);
}

   
      
    

   
      
    

   
      
    

#endif           

   
      
    

#ifdef __cplusplus
}
#endif

#endif                          
