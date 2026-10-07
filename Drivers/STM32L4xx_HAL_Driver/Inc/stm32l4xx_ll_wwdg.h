/**
  ******************************************************************************
  * @file    stm32l4xx_ll_wwdg.h
  * @author  MCD Application Team
  * @brief   Header file of WWDG LL module.
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

                                                                                
#ifndef STM32L4xx_LL_WWDG_H
#define STM32L4xx_LL_WWDG_H

#ifdef __cplusplus
extern "C" {
#endif

                                                                                
#include "stm32l4xx.h"

                                   
      
    

#if defined (WWDG)

                          
      
    

                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                
      
    

                                      
                                                                                               
      
    
#define LL_WWDG_CFR_EWI                     WWDG_CFR_EWI
   
      
    

                                             
      
    
#define LL_WWDG_PRESCALER_1                 0x00000000u                                                                                          
#define LL_WWDG_PRESCALER_2                 WWDG_CFR_WDGTB_0                                                                                     
#define LL_WWDG_PRESCALER_4                 WWDG_CFR_WDGTB_1                                                                                     
#define LL_WWDG_PRESCALER_8                 (WWDG_CFR_WDGTB_0 | WWDG_CFR_WDGTB_1)                                                                
   
      
    

   
      
    

                                                                                
                                                          
      
    
                                                                          
      
    
   
                                          
                                      
                                          
                                                         
                
    
#define LL_WWDG_WriteReg(__INSTANCE__, __REG__, __VALUE__) WRITE_REG(__INSTANCE__->__REG__, (__VALUE__))

   
                                         
                                      
                                       
                          
    
#define LL_WWDG_ReadReg(__INSTANCE__, __REG__) READ_REG(__INSTANCE__->__REG__)
   
      
    

   
      
    

                                                                                
                                                                
      
    

                                                    
      
    
   
                                                                                  
                                                                          
                                                               
                                                                                   
                                                             
                                                     
                               
                
    
__STATIC_INLINE void LL_WWDG_Enable(WWDG_TypeDef *WWDGx)
{
  SET_BIT(WWDGx->CR, WWDG_CR_WDGA);
}

   
                                                
                                                        
                               
                                  
    
__STATIC_INLINE uint32_t LL_WWDG_IsEnabled(WWDG_TypeDef *WWDGx)
{
  return ((READ_BIT(WWDGx->CR, WWDG_CR_WDGA) == (WWDG_CR_WDGA)) ? 1UL : 0UL);
}

   
                                                                            
                                                                                                                     
                                                                            
                                                                                             
                                                                                           
                                                         
                               
                                                 
                
    
__STATIC_INLINE void LL_WWDG_SetCounter(WWDG_TypeDef *WWDGx, uint32_t Counter)
{
  MODIFY_REG(WWDGx->CR, WWDG_CR_T, Counter);
}

   
                                                                        
                                                         
                               
                                        
    
__STATIC_INLINE uint32_t LL_WWDG_GetCounter(WWDG_TypeDef *WWDGx)
{
  return (READ_BIT(WWDGx->CR, WWDG_CR_T));
}

   
                                                       
                                                                                    
                                                               
                                                           
                               
                                                                        
                                         
                                         
                                         
                                         
                
    
__STATIC_INLINE void LL_WWDG_SetPrescaler(WWDG_TypeDef *WWDGx, uint32_t Prescaler)
{
  MODIFY_REG(WWDGx->CFR, WWDG_CFR_WDGTB, Prescaler);
}

   
                                                   
                                                           
                               
                                                              
                                         
                                         
                                         
                                         
    
__STATIC_INLINE uint32_t LL_WWDG_GetPrescaler(WWDG_TypeDef *WWDGx)
{
  return (READ_BIT(WWDGx->CFR, WWDG_CFR_WDGTB));
}

   
                                                                                            
                                                                        
                                                   
                                                                                
                                                             
                                                                                   
                                                                                     
                                               
                                                                                               
                                                                                              
                                                        
                               
                                                  
                
    
__STATIC_INLINE void LL_WWDG_SetWindow(WWDG_TypeDef *WWDGx, uint32_t Window)
{
  MODIFY_REG(WWDGx->CFR, WWDG_CFR_W, Window);
}

   
                                                               
                                                        
                               
                                       
    
__STATIC_INLINE uint32_t LL_WWDG_GetWindow(WWDG_TypeDef *WWDGx)
{
  return (READ_BIT(WWDGx->CFR, WWDG_CFR_W));
}

   
      
    

                                                        
      
    
   
                                                                            
                                                                                    
                                                        
                                                                                             
                                                                 
                               
                                  
    
__STATIC_INLINE uint32_t LL_WWDG_IsActiveFlag_EWKUP(WWDG_TypeDef *WWDGx)
{
  return ((READ_BIT(WWDGx->SR, WWDG_SR_EWIF) == (WWDG_SR_EWIF)) ? 1UL : 0UL);
}

   
                                                         
                                                              
                               
                
    
__STATIC_INLINE void LL_WWDG_ClearFlag_EWKUP(WWDG_TypeDef *WWDGx)
{
  WRITE_REG(WWDGx->SR, ~WWDG_SR_EWIF);
}

   
      
    

                                                    
      
    
   
                                              
                                                                                  
                                                                    
                                                             
                               
                
    
__STATIC_INLINE void LL_WWDG_EnableIT_EWKUP(WWDG_TypeDef *WWDGx)
{
  SET_BIT(WWDGx->CFR, WWDG_CFR_EWI);
}

   
                                                      
                                                                
                               
                                  
    
__STATIC_INLINE uint32_t LL_WWDG_IsEnabledIT_EWKUP(WWDG_TypeDef *WWDGx)
{
  return ((READ_BIT(WWDGx->CFR, WWDG_CFR_EWI) == (WWDG_CFR_EWI)) ? 1UL : 0UL);
}

   
      
    

   
      
    

   
      
    

#endif           

   
      
    

#ifdef __cplusplus
}
#endif

#endif                          
