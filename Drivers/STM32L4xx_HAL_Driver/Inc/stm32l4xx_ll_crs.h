/**
  ******************************************************************************
  * @file    stm32l4xx_ll_crs.h
  * @author  MCD Application Team
  * @brief   Header file of CRS LL module.
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

                                                                                
#ifndef STM32L4xx_LL_CRS_H
#define STM32L4xx_LL_CRS_H

#ifdef __cplusplus
extern "C" {
#endif

                                                                                
#include "stm32l4xx.h"

                                   
      
    

#if defined(CRS)

                        
      
    

                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                              
      
    

                                                  
                                                                          
      
    
#define LL_CRS_ISR_SYNCOKF                 CRS_ISR_SYNCOKF
#define LL_CRS_ISR_SYNCWARNF               CRS_ISR_SYNCWARNF
#define LL_CRS_ISR_ERRF                    CRS_ISR_ERRF
#define LL_CRS_ISR_ESYNCF                  CRS_ISR_ESYNCF
#define LL_CRS_ISR_SYNCERR                 CRS_ISR_SYNCERR
#define LL_CRS_ISR_SYNCMISS                CRS_ISR_SYNCMISS
#define LL_CRS_ISR_TRIMOVF                 CRS_ISR_TRIMOVF
   
      
    

                                     
                                                                                             
      
    
#define LL_CRS_CR_SYNCOKIE                 CRS_CR_SYNCOKIE
#define LL_CRS_CR_SYNCWARNIE               CRS_CR_SYNCWARNIE
#define LL_CRS_CR_ERRIE                    CRS_CR_ERRIE
#define LL_CRS_CR_ESYNCIE                  CRS_CR_ESYNCIE
   
      
    

                                                               
      
    
#define LL_CRS_SYNC_DIV_1                  0x00000000U                                                                           
#define LL_CRS_SYNC_DIV_2                  CRS_CFGR_SYNCDIV_0                                                           
#define LL_CRS_SYNC_DIV_4                  CRS_CFGR_SYNCDIV_1                                                           
#define LL_CRS_SYNC_DIV_8                  (CRS_CFGR_SYNCDIV_1 | CRS_CFGR_SYNCDIV_0)                                    
#define LL_CRS_SYNC_DIV_16                 CRS_CFGR_SYNCDIV_2                                                            
#define LL_CRS_SYNC_DIV_32                 (CRS_CFGR_SYNCDIV_2 | CRS_CFGR_SYNCDIV_0)                                     
#define LL_CRS_SYNC_DIV_64                 (CRS_CFGR_SYNCDIV_2 | CRS_CFGR_SYNCDIV_1)                                     
#define LL_CRS_SYNC_DIV_128                CRS_CFGR_SYNCDIV                                                               
   
      
    

                                                                 
      
    
#define LL_CRS_SYNC_SOURCE_GPIO            0x00000000U                                               
#define LL_CRS_SYNC_SOURCE_LSE             CRS_CFGR_SYNCSRC_0                                       
#define LL_CRS_SYNC_SOURCE_USB             CRS_CFGR_SYNCSRC_1                                                    
   
      
    

                                                                     
      
    
#define LL_CRS_SYNC_POLARITY_RISING        0x00000000U                                                          
#define LL_CRS_SYNC_POLARITY_FALLING       CRS_CFGR_SYNCPOL                                            
   
      
    

                                                              
      
    
#define LL_CRS_FREQ_ERROR_DIR_UP           0x00000000U                                                                               
#define LL_CRS_FREQ_ERROR_DIR_DOWN         CRS_ISR_FEDIR                                                                               
   
      
    

                                                    
      
    
   
                                          
                                                                                         
                                                                               
    
#define LL_CRS_RELOADVALUE_DEFAULT         0x0000BB7FU

   
                                                
    
#define LL_CRS_ERRORLIMIT_DEFAULT          0x00000022U

   
                                                     
                                                                       
                                                                   
                                                                  
                                                                       
    
#if defined(STM32L412xx) || defined(STM32L422xx)
#define LL_CRS_HSI48CALIBRATION_DEFAULT    0x00000040U
#else
#define LL_CRS_HSI48CALIBRATION_DEFAULT    0x00000020U
#endif                                 
   
      
    

   
      
    

                                                                                
                                                        
      
    

                                                                         
      
    

   
                                         
                                     
                                          
                                                         
                
    
#define LL_CRS_WriteReg(__INSTANCE__, __REG__, __VALUE__) WRITE_REG(__INSTANCE__->__REG__, (__VALUE__))

   
                                        
                                     
                                       
                          
    
#define LL_CRS_ReadReg(__INSTANCE__, __REG__) READ_REG(__INSTANCE__->__REG__)
   
      
    

                                                                                         
      
    

   
                                                                                                              
                                                                              
                                                                                      
                                                                                  
                                                                            
                                              
                                                      
                                                                    
                                
    
#define __LL_CRS_CALC_CALCULATE_RELOADVALUE(__FTARGET__, __FSYNC__) (((__FTARGET__) / (__FSYNC__)) - 1U)

   
      
    

   
      
    

                                                                                
                                                              
      
    

                                                   
      
    

   
                                          
                                                                                               
                                                                    
                
    
__STATIC_INLINE void LL_CRS_EnableFreqErrorCounter(void)
{
  SET_BIT(CRS->CR, CRS_CR_CEN);
}

   
                                           
                                                                     
                
    
__STATIC_INLINE void LL_CRS_DisableFreqErrorCounter(void)
{
  CLEAR_BIT(CRS->CR, CRS_CR_CEN);
}

   
                                                              
                                                                       
                                  
    
__STATIC_INLINE uint32_t LL_CRS_IsEnabledFreqErrorCounter(void)
{
  return ((READ_BIT(CRS->CR, CRS_CR_CEN) == (CRS_CR_CEN)) ? 1UL : 0UL);
}

   
                                             
                                                                
                
    
__STATIC_INLINE void LL_CRS_EnableAutoTrimming(void)
{
  SET_BIT(CRS->CR, CRS_CR_AUTOTRIMEN);
}

   
                                              
                                                                 
                
    
__STATIC_INLINE void LL_CRS_DisableAutoTrimming(void)
{
  CLEAR_BIT(CRS->CR, CRS_CR_AUTOTRIMEN);
}

   
                                                         
                                                                   
                                  
    
__STATIC_INLINE uint32_t LL_CRS_IsEnabledAutoTrimming(void)
{
  return ((READ_BIT(CRS->CR, CRS_CR_AUTOTRIMEN) == (CRS_CR_AUTOTRIMEN)) ? 1UL : 0UL);
}

   
                                                
                                                                                                 
                                                                    
                                                                                                     
                                                                                   
                
    
__STATIC_INLINE void LL_CRS_SetHSI48SmoothTrimming(uint32_t Value)
{
  MODIFY_REG(CRS->CR, CRS_CR_TRIM, Value << CRS_CR_TRIM_Pos);
}

   
                                                
                                                                    
                                                                                               
    
__STATIC_INLINE uint32_t LL_CRS_GetHSI48SmoothTrimming(void)
{
  return (uint32_t)(READ_BIT(CRS->CR, CRS_CR_TRIM) >> CRS_CR_TRIM_Pos);
}

   
                                    
                                                              
                                                                     
                                                                              
                                                                                                                       
                
    
__STATIC_INLINE void LL_CRS_SetReloadCounter(uint32_t Value)
{
  MODIFY_REG(CRS->CFGR, CRS_CFGR_RELOAD, Value);
}

   
                                    
                                                              
                                                               
    
__STATIC_INLINE uint32_t LL_CRS_GetReloadCounter(void)
{
  return (uint32_t)(READ_BIT(CRS->CFGR, CRS_CFGR_RELOAD));
}

   
                                     
                                                               
                                                                  
                                                                             
                
    
__STATIC_INLINE void LL_CRS_SetFreqErrorLimit(uint32_t Value)
{
  MODIFY_REG(CRS->CFGR, CRS_CFGR_FELIM, Value << CRS_CFGR_FELIM_Pos);
}

   
                                     
                                                               
                                                            
    
__STATIC_INLINE uint32_t LL_CRS_GetFreqErrorLimit(void)
{
  return (uint32_t)(READ_BIT(CRS->CFGR, CRS_CFGR_FELIM) >> CRS_CFGR_FELIM_Pos);
}

   
                                               
                                                            
                                                                      
                                       
                                       
                                       
                                       
                                        
                                        
                                        
                                         
                
    
__STATIC_INLINE void LL_CRS_SetSyncDivider(uint32_t Divider)
{
  MODIFY_REG(CRS->CFGR, CRS_CFGR_SYNCDIV, Divider);
}

   
                                               
                                                            
                                                              
                                       
                                       
                                       
                                       
                                        
                                        
                                        
                                         
    
__STATIC_INLINE uint32_t LL_CRS_GetSyncDivider(void)
{
  return (uint32_t)(READ_BIT(CRS->CFGR, CRS_CFGR_SYNCDIV));
}

   
                                  
                                                                 
                                                                     
                                             
                                            
                                            
                
    
__STATIC_INLINE void LL_CRS_SetSyncSignalSource(uint32_t Source)
{
  MODIFY_REG(CRS->CFGR, CRS_CFGR_SYNCSRC, Source);
}

   
                                  
                                                                 
                                                              
                                             
                                            
                                            
    
__STATIC_INLINE uint32_t LL_CRS_GetSyncSignalSource(void)
{
  return (uint32_t)(READ_BIT(CRS->CFGR, CRS_CFGR_SYNCSRC));
}

   
                                                         
                                                             
                                                                       
                                                 
                                                  
                
    
__STATIC_INLINE void LL_CRS_SetSyncPolarity(uint32_t Polarity)
{
  MODIFY_REG(CRS->CFGR, CRS_CFGR_SYNCPOL, Polarity);
}

   
                                                         
                                                             
                                                              
                                                 
                                                  
    
__STATIC_INLINE uint32_t LL_CRS_GetSyncPolarity(void)
{
  return (uint32_t)(READ_BIT(CRS->CFGR, CRS_CFGR_SYNCPOL));
}

   
                                                 
                                                                     
                                                                     
                                                                     
                                                                     
                                                                     
                                                                   
                                                                                                                     
                                                                               
                                                                        
                                                                                 
                                                                                            
                                                                                                
                                                                       
                                                                                                           
                                                                                      
                
    
__STATIC_INLINE void LL_CRS_ConfigSynchronization(uint32_t HSI48CalibrationValue, uint32_t ErrorLimitValue,
                                                  uint32_t ReloadValue, uint32_t Settings)
{
  MODIFY_REG(CRS->CR, CRS_CR_TRIM, HSI48CalibrationValue << CRS_CR_TRIM_Pos);

  MODIFY_REG(CRS->CFGR,
             CRS_CFGR_RELOAD | CRS_CFGR_FELIM | CRS_CFGR_SYNCDIV | CRS_CFGR_SYNCSRC | CRS_CFGR_SYNCPOL,
             ReloadValue | (ErrorLimitValue << CRS_CFGR_FELIM_Pos) | Settings);
}

   
      
    

                                                     
      
    

   
                                        
                                                                  
                
    
__STATIC_INLINE void LL_CRS_GenerateEvent_SWSYNC(void)
{
  SET_BIT(CRS->CR, CRS_CR_SWSYNC);
}

   
                                                                             
              
                                                                   
                                                              
                                              
                                                
    
__STATIC_INLINE uint32_t LL_CRS_GetFreqErrorDirection(void)
{
  return (uint32_t)(READ_BIT(CRS->ISR, CRS_ISR_FEDIR));
}

   
                                                                                            
                                                                 
                                                                    
    
__STATIC_INLINE uint32_t LL_CRS_GetFreqErrorCapture(void)
{
  return (uint32_t)(READ_BIT(CRS->ISR, CRS_ISR_FECAP) >> CRS_ISR_FECAP_Pos);
}

   
      
    

                                                       
      
    

   
                                                         
                                                                 
                                  
    
__STATIC_INLINE uint32_t LL_CRS_IsActiveFlag_SYNCOK(void)
{
  return ((READ_BIT(CRS->ISR, CRS_ISR_SYNCOKF) == (CRS_ISR_SYNCOKF)) ? 1UL : 0UL);
}

   
                                                        
                                                                   
                                  
    
__STATIC_INLINE uint32_t LL_CRS_IsActiveFlag_SYNCWARN(void)
{
  return ((READ_BIT(CRS->ISR, CRS_ISR_SYNCWARNF) == (CRS_ISR_SYNCWARNF)) ? 1UL : 0UL);
}

   
                                                                             
                                                              
                                  
    
__STATIC_INLINE uint32_t LL_CRS_IsActiveFlag_ERR(void)
{
  return ((READ_BIT(CRS->ISR, CRS_ISR_ERRF) == (CRS_ISR_ERRF)) ? 1UL : 0UL);
}

   
                                                         
                                                                
                                  
    
__STATIC_INLINE uint32_t LL_CRS_IsActiveFlag_ESYNC(void)
{
  return ((READ_BIT(CRS->ISR, CRS_ISR_ESYNCF) == (CRS_ISR_ESYNCF)) ? 1UL : 0UL);
}

   
                                                      
                                                                  
                                  
    
__STATIC_INLINE uint32_t LL_CRS_IsActiveFlag_SYNCERR(void)
{
  return ((READ_BIT(CRS->ISR, CRS_ISR_SYNCERR) == (CRS_ISR_SYNCERR)) ? 1UL : 0UL);
}

   
                                                             
                                                                   
                                  
    
__STATIC_INLINE uint32_t LL_CRS_IsActiveFlag_SYNCMISS(void)
{
  return ((READ_BIT(CRS->ISR, CRS_ISR_SYNCMISS) == (CRS_ISR_SYNCMISS)) ? 1UL : 0UL);
}

   
                                                                   
                                                                  
                                  
    
__STATIC_INLINE uint32_t LL_CRS_IsActiveFlag_TRIMOVF(void)
{
  return ((READ_BIT(CRS->ISR, CRS_ISR_TRIMOVF) == (CRS_ISR_TRIMOVF)) ? 1UL : 0UL);
}

   
                                        
                                                              
                
    
__STATIC_INLINE void LL_CRS_ClearFlag_SYNCOK(void)
{
  WRITE_REG(CRS->ICR, CRS_ICR_SYNCOKC);
}

   
                                        
                                                                
                
    
__STATIC_INLINE void LL_CRS_ClearFlag_SYNCWARN(void)
{
  WRITE_REG(CRS->ICR, CRS_ICR_SYNCWARNC);
}

   
                                                                          
                
                                                           
                
    
__STATIC_INLINE void LL_CRS_ClearFlag_ERR(void)
{
  WRITE_REG(CRS->ICR, CRS_ICR_ERRC);
}

   
                                    
                                                             
                
    
__STATIC_INLINE void LL_CRS_ClearFlag_ESYNC(void)
{
  WRITE_REG(CRS->ICR, CRS_ICR_ESYNCC);
}

   
      
    

                                                   
      
    

   
                                          
                                                             
                
    
__STATIC_INLINE void LL_CRS_EnableIT_SYNCOK(void)
{
  SET_BIT(CRS->CR, CRS_CR_SYNCOKIE);
}

   
                                           
                                                              
                
    
__STATIC_INLINE void LL_CRS_DisableIT_SYNCOK(void)
{
  CLEAR_BIT(CRS->CR, CRS_CR_SYNCOKIE);
}

   
                                                              
                                                                
                                  
    
__STATIC_INLINE uint32_t LL_CRS_IsEnabledIT_SYNCOK(void)
{
  return ((READ_BIT(CRS->CR, CRS_CR_SYNCOKIE) == (CRS_CR_SYNCOKIE)) ? 1UL : 0UL);
}

   
                                         
                                                               
                
    
__STATIC_INLINE void LL_CRS_EnableIT_SYNCWARN(void)
{
  SET_BIT(CRS->CR, CRS_CR_SYNCWARNIE);
}

   
                                          
                                                                
                
    
__STATIC_INLINE void LL_CRS_DisableIT_SYNCWARN(void)
{
  CLEAR_BIT(CRS->CR, CRS_CR_SYNCWARNIE);
}

   
                                                             
                                                                  
                                  
    
__STATIC_INLINE uint32_t LL_CRS_IsEnabledIT_SYNCWARN(void)
{
  return ((READ_BIT(CRS->CR, CRS_CR_SYNCWARNIE) == (CRS_CR_SYNCWARNIE)) ? 1UL : 0UL);
}

   
                                                              
                                                          
                
    
__STATIC_INLINE void LL_CRS_EnableIT_ERR(void)
{
  SET_BIT(CRS->CR, CRS_CR_ERRIE);
}

   
                                                               
                                                           
                
    
__STATIC_INLINE void LL_CRS_DisableIT_ERR(void)
{
  CLEAR_BIT(CRS->CR, CRS_CR_ERRIE);
}

   
                                                                                  
                                                             
                                  
    
__STATIC_INLINE uint32_t LL_CRS_IsEnabledIT_ERR(void)
{
  return ((READ_BIT(CRS->CR, CRS_CR_ERRIE) == (CRS_CR_ERRIE)) ? 1UL : 0UL);
}

   
                                          
                                                            
                
    
__STATIC_INLINE void LL_CRS_EnableIT_ESYNC(void)
{
  SET_BIT(CRS->CR, CRS_CR_ESYNCIE);
}

   
                                           
                                                             
                
    
__STATIC_INLINE void LL_CRS_DisableIT_ESYNC(void)
{
  CLEAR_BIT(CRS->CR, CRS_CR_ESYNCIE);
}

   
                                                              
                                                               
                                  
    
__STATIC_INLINE uint32_t LL_CRS_IsEnabledIT_ESYNC(void)
{
  return ((READ_BIT(CRS->CR, CRS_CR_ESYNCIE) == (CRS_CR_ESYNCIE)) ? 1UL : 0UL);
}

   
      
    

#if defined(USE_FULL_LL_DRIVER)
                                                                           
      
    

ErrorStatus LL_CRS_DeInit(void);

   
      
    
#endif                         

   
      
    

   
      
    

#endif                   

   
      
    

#ifdef __cplusplus
}
#endif

#endif                         
