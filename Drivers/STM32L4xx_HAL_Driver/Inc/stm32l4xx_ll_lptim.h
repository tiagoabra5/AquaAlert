/**
  ******************************************************************************
  * @file    stm32l4xx_ll_lptim.h
  * @author  MCD Application Team
  * @brief   Header file of LPTIM LL module.
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

                                                                                
#ifndef STM32L4xx_LL_LPTIM_H
#define STM32L4xx_LL_LPTIM_H

#ifdef __cplusplus
extern "C" {
#endif

                                                                                
#include "stm32l4xx.h"

                                   
      
    

#if defined (LPTIM1) || defined (LPTIM2)

                            
      
    

                                                                                
                                                                                

                                                                                

                                                                                
#if defined(USE_FULL_LL_DRIVER)
                                                          
      
    
   
      
    
#endif                       

                                                                                
#if defined(USE_FULL_LL_DRIVER)
                                                            
      
    

   
                                           
    
typedef struct
{
  uint32_t ClockSource;                                                                      
                                                                                             

                                                                                     
                                                                          

  uint32_t Prescaler;                                                  
                                                                                            

                                                                                           
                                                                        

  uint32_t Waveform;                                         
                                                                                                  

                                                                                     
                                                                        

  uint32_t Polarity;                                        
                                                                                                  

                                                                                     
                                                                        
} LL_LPTIM_InitTypeDef;

   
      
    
#endif                         

                                                                                
                                                                  
      
    

                                                    
                                                                            
      
    
#define LL_LPTIM_ISR_CMPM                     LPTIM_ISR_CMPM                          
#define LL_LPTIM_ISR_CMPOK                    LPTIM_ISR_CMPOK                                      
#define LL_LPTIM_ISR_ARRM                     LPTIM_ISR_ARRM                             
#define LL_LPTIM_ISR_EXTTRIG                  LPTIM_ISR_EXTTRIG                                     
#define LL_LPTIM_ISR_ARROK                    LPTIM_ISR_ARROK                                         
#define LL_LPTIM_ISR_UP                       LPTIM_ISR_UP                                                  
#define LL_LPTIM_ISR_DOWN                     LPTIM_ISR_DOWN                                                
#if defined(LPTIM_RCR_REP)
#define LL_LPTIM_ISR_UE                       LPTIM_ISR_UE                           
#define LL_LPTIM_ISR_REPOK                    LPTIM_ISR_REPOK                                         
#endif
   
      
    

                                       
                                                                                                 
      
    
#define LL_LPTIM_IER_CMPMIE                   LPTIM_IER_CMPMIE                          
#define LL_LPTIM_IER_CMPOKIE                  LPTIM_IER_CMPOKIE                                      
#define LL_LPTIM_IER_ARRMIE                   LPTIM_IER_ARRMIE                             
#define LL_LPTIM_IER_EXTTRIGIE                LPTIM_IER_EXTTRIGIE                                     
#define LL_LPTIM_IER_ARROKIE                  LPTIM_IER_ARROKIE                                         
#define LL_LPTIM_IER_UPIE                     LPTIM_IER_UPIE                                                  
#define LL_LPTIM_IER_DOWNIE                   LPTIM_IER_DOWNIE                                                
#if defined(LPTIM_RCR_REP)
#define LL_LPTIM_IER_UEIE                     LPTIM_IER_UEIE                           
#define LL_LPTIM_IER_REPOKIE                  LPTIM_IER_REPOKIE                                         
#endif
   
      
    

                                                       
      
    
#define LL_LPTIM_OPERATING_MODE_CONTINUOUS    LPTIM_CR_CNTSTRT                                         
#define LL_LPTIM_OPERATING_MODE_ONESHOT       LPTIM_CR_SNGSTRT                                      
   
      
    

                                                 
      
    
#define LL_LPTIM_UPDATE_MODE_IMMEDIATE        0x00000000U                                                                                        
#define LL_LPTIM_UPDATE_MODE_ENDOFPERIOD      LPTIM_CFGR_PRELOAD                                                                                       
   
      
    

                                                   
      
    
#define LL_LPTIM_COUNTER_MODE_INTERNAL        0x00000000U                                                                              
#define LL_LPTIM_COUNTER_MODE_EXTERNAL        LPTIM_CFGR_COUNTMODE                                                                                               
   
      
    

                                                              
      
    
#define LL_LPTIM_OUTPUT_WAVEFORM_PWM          0x00000000U                                                                                                                                 
#define LL_LPTIM_OUTPUT_WAVEFORM_SETONCE      LPTIM_CFGR_WAVE                                           
   
      
    

                                                         
      
    
#define LL_LPTIM_OUTPUT_POLARITY_REGULAR      0x00000000U                                                                                                            
#define LL_LPTIM_OUTPUT_POLARITY_INVERSE      LPTIM_CFGR_WAVPOL                                                                                                                     
   
      
    

                                                   
      
    
#define LL_LPTIM_PRESCALER_DIV1               0x00000000U                                                                          
#define LL_LPTIM_PRESCALER_DIV2               LPTIM_CFGR_PRESC_0                                                                   
#define LL_LPTIM_PRESCALER_DIV4               LPTIM_CFGR_PRESC_1                                                                   
#define LL_LPTIM_PRESCALER_DIV8               (LPTIM_CFGR_PRESC_1 | LPTIM_CFGR_PRESC_0)                                            
#define LL_LPTIM_PRESCALER_DIV16              LPTIM_CFGR_PRESC_2                                                                    
#define LL_LPTIM_PRESCALER_DIV32              (LPTIM_CFGR_PRESC_2 | LPTIM_CFGR_PRESC_0)                                             
#define LL_LPTIM_PRESCALER_DIV64              (LPTIM_CFGR_PRESC_2 | LPTIM_CFGR_PRESC_1)                                             
#define LL_LPTIM_PRESCALER_DIV128             LPTIM_CFGR_PRESC                                                                       
   
      
    

                                                    
      
    
#define LL_LPTIM_TRIG_SOURCE_GPIO             0x00000000U                                                                                                                     
#define LL_LPTIM_TRIG_SOURCE_RTCALARMA        LPTIM_CFGR_TRIGSEL_0                                                                                                         
#define LL_LPTIM_TRIG_SOURCE_RTCALARMB        LPTIM_CFGR_TRIGSEL_1                                                                                                         
#define LL_LPTIM_TRIG_SOURCE_RTCTAMP1         (LPTIM_CFGR_TRIGSEL_1 | LPTIM_CFGR_TRIGSEL_0)                                                                                 
#define LL_LPTIM_TRIG_SOURCE_RTCTAMP2         LPTIM_CFGR_TRIGSEL_2                                                                                                          
#define LL_LPTIM_TRIG_SOURCE_RTCTAMP3         (LPTIM_CFGR_TRIGSEL_2 | LPTIM_CFGR_TRIGSEL_0)                                                                                 
#define LL_LPTIM_TRIG_SOURCE_COMP1            (LPTIM_CFGR_TRIGSEL_2 | LPTIM_CFGR_TRIGSEL_1)                                                                                 
#define LL_LPTIM_TRIG_SOURCE_COMP2            LPTIM_CFGR_TRIGSEL                                                                                                            
   
      
    

                                                    
      
    
#define LL_LPTIM_TRIG_FILTER_NONE             0x00000000U                                                                               
#define LL_LPTIM_TRIG_FILTER_2                LPTIM_CFGR_TRGFLT_0                                                                                                                       
#define LL_LPTIM_TRIG_FILTER_4                LPTIM_CFGR_TRGFLT_1                                                                                                                       
#define LL_LPTIM_TRIG_FILTER_8                LPTIM_CFGR_TRGFLT                                                                                                                         
   
      
    

                                                        
      
    
#define LL_LPTIM_TRIG_POLARITY_RISING         LPTIM_CFGR_TRIGEN_0                                                          
#define LL_LPTIM_TRIG_POLARITY_FALLING        LPTIM_CFGR_TRIGEN_1                                                           
#define LL_LPTIM_TRIG_POLARITY_RISING_FALLING LPTIM_CFGR_TRIGEN                                                                         
   
      
    

                                                 
      
    
#define LL_LPTIM_CLK_SOURCE_INTERNAL          0x00000000U                                                                                                    
#define LL_LPTIM_CLK_SOURCE_EXTERNAL          LPTIM_CFGR_CKSEL                                                                                     
   
      
    

                                                 
      
    
#define LL_LPTIM_CLK_FILTER_NONE              0x00000000U                                                                                        
#define LL_LPTIM_CLK_FILTER_2                 LPTIM_CFGR_CKFLT_0                                                                                                                                 
#define LL_LPTIM_CLK_FILTER_4                 LPTIM_CFGR_CKFLT_1                                                                                                                                 
#define LL_LPTIM_CLK_FILTER_8                 LPTIM_CFGR_CKFLT                                                                                                                                   
   
      
    

                                                     
      
    
#define LL_LPTIM_CLK_POLARITY_RISING          0x00000000U                                                                   
#define LL_LPTIM_CLK_POLARITY_FALLING         LPTIM_CFGR_CKPOL_0                                                             
#define LL_LPTIM_CLK_POLARITY_RISING_FALLING  LPTIM_CFGR_CKPOL_1                                   
   
      
    

                                                   
      
    
#define LL_LPTIM_ENCODER_MODE_RISING          0x00000000U                                                                   
#define LL_LPTIM_ENCODER_MODE_FALLING         LPTIM_CFGR_CKPOL_0                                                             
#define LL_LPTIM_ENCODER_MODE_RISING_FALLING  LPTIM_CFGR_CKPOL_1                                   
   
      
    

                                               
      
    
#define LL_LPTIM_INPUT1_SRC_GPIO         0x00000000U                                         
#define LL_LPTIM_INPUT1_SRC_COMP1        LPTIM_OR_OR_0                                       
#define LL_LPTIM_INPUT1_SRC_COMP2        LPTIM_OR_OR_1                            
#define LL_LPTIM_INPUT1_SRC_COMP1_COMP2  LPTIM_OR_OR                              
   
      
    

                                               
      
    
#define LL_LPTIM_INPUT2_SRC_GPIO         0x00000000U                                     
#define LL_LPTIM_INPUT2_SRC_COMP2        LPTIM_OR_OR_1                                   
   
      
    

   
      
    

                                                                                
                                                            
      
    

                                                                           
      
    

   
                                           
                                       
                                          
                                                         
                
    
#define LL_LPTIM_WriteReg(__INSTANCE__, __REG__, __VALUE__) WRITE_REG((__INSTANCE__)->__REG__, (__VALUE__))

   
                                          
                                       
                                       
                          
    
#define LL_LPTIM_ReadReg(__INSTANCE__, __REG__) READ_REG((__INSTANCE__)->__REG__)
   
      
    

   
      
    

                                                                                
                                                                  
      
    

                                                
       
    
#define LL_LPTIM_ClearFLAG_CMPM  LL_LPTIM_ClearFlag_CMPM
#define LL_LPTIM_ClearFLAG_CC1   LL_LPTIM_ClearFlag_CC1
#define LL_LPTIM_ClearFLAG_CC2   LL_LPTIM_ClearFlag_CC2
#define LL_LPTIM_ClearFLAG_CC1O  LL_LPTIM_ClearFlag_CC1O
#define LL_LPTIM_ClearFLAG_CC2O  LL_LPTIM_ClearFlag_CC2O
#define LL_LPTIM_ClearFLAG_ARRM  LL_LPTIM_ClearFlag_ARRM
   
        
    

#if defined(USE_FULL_LL_DRIVER)
                                                                            
      
    

ErrorStatus LL_LPTIM_DeInit(const LPTIM_TypeDef *LPTIMx);
void LL_LPTIM_StructInit(LL_LPTIM_InitTypeDef *LPTIM_InitStruct);
ErrorStatus LL_LPTIM_Init(LPTIM_TypeDef *LPTIMx, const LL_LPTIM_InitTypeDef *LPTIM_InitStruct);
void LL_LPTIM_Disable(LPTIM_TypeDef *LPTIMx);
   
      
    
#endif                         

                                                                 
      
    

   
                                     
                                                                              
                                                        
                                                      
                                           
                
    
__STATIC_INLINE void LL_LPTIM_Enable(LPTIM_TypeDef *LPTIMx)
{
  SET_BIT(LPTIMx->CR, LPTIM_CR_ENABLE);
}

   
                                                            
                                                         
                                           
                                  
    
__STATIC_INLINE uint32_t LL_LPTIM_IsEnabled(const LPTIM_TypeDef *LPTIMx)
{
  return (((READ_BIT(LPTIMx->CR, LPTIM_CR_ENABLE) == LPTIM_CR_ENABLE) ? 1UL : 0UL));
}

   
                                                         
                                                                     
                                                                   
                          
                                                              
                                                            
                                           
                                                                            
                                                        
                                                     
                
    
__STATIC_INLINE void LL_LPTIM_StartCounter(LPTIM_TypeDef *LPTIMx, uint32_t OperatingMode)
{
  MODIFY_REG(LPTIMx->CR, LPTIM_CR_CNTSTRT | LPTIM_CR_SNGSTRT, OperatingMode);
}

#if defined(LPTIM_CR_RSTARE)
   
                                    
                                                                  
                                                                             
                                                                    
                                           
                
    
__STATIC_INLINE void LL_LPTIM_EnableResetAfterRead(LPTIM_TypeDef *LPTIMx)
{
  SET_BIT(LPTIMx->CR, LPTIM_CR_RSTARE);
}

   
                                     
                                                                     
                                           
                
    
__STATIC_INLINE void LL_LPTIM_DisableResetAfterRead(LPTIM_TypeDef *LPTIMx)
{
  CLEAR_BIT(LPTIMx->CR, LPTIM_CR_RSTARE);
}

   
                                                                     
                                                                       
                                           
                                  
    
__STATIC_INLINE uint32_t LL_LPTIM_IsEnabledResetAfterRead(const LPTIM_TypeDef *LPTIMx)
{
  return (((READ_BIT(LPTIMx->CR, LPTIM_CR_RSTARE) == LPTIM_CR_RSTARE) ? 1UL : 0UL));
}
#endif

#if defined(LPTIM_CR_COUNTRST)
   
                                                                  
                                                                    
                                                                          
                                                            
                                                       
                                                               
                                           
                
    
__STATIC_INLINE void LL_LPTIM_ResetCounter(LPTIM_TypeDef *LPTIMx)
{
  SET_BIT(LPTIMx->CR, LPTIM_CR_COUNTRST);
}
#endif

   
                                                                                 
                                                                           
                                                             
                                           
                                                                         
                                                    
                                                      
                
    
__STATIC_INLINE void LL_LPTIM_SetUpdateMode(LPTIM_TypeDef *LPTIMx, uint32_t UpdateMode)
{
  MODIFY_REG(LPTIMx->CFGR, LPTIM_CFGR_PRELOAD, UpdateMode);
}

   
                                               
                                                             
                                           
                                                              
                                                    
                                                      
    
__STATIC_INLINE uint32_t LL_LPTIM_GetUpdateMode(const LPTIM_TypeDef *LPTIMx)
{
  return (uint32_t)(READ_BIT(LPTIMx->CFGR, LPTIM_CFGR_PRELOAD));
}

   
                                     
                                                                                         
                                                                               
                                                                               
                                                                                
                                        
                                                                      
                                                             
                                           
                                                                        
                
    
__STATIC_INLINE void LL_LPTIM_SetAutoReload(LPTIM_TypeDef *LPTIMx, uint32_t AutoReload)
{
  MODIFY_REG(LPTIMx->ARR, LPTIM_ARR_ARR, AutoReload);
}

   
                                        
                                                             
                                           
                                                                        
    
__STATIC_INLINE uint32_t LL_LPTIM_GetAutoReload(const LPTIM_TypeDef *LPTIMx)
{
  return (uint32_t)(READ_BIT(LPTIMx->ARR, LPTIM_ARR_ARR));
}

#if defined(LPTIM_RCR_REP)
   
                                    
                                                                                         
                                                             
                                           
                                                                    
                
    
__STATIC_INLINE void LL_LPTIM_SetRepetition(LPTIM_TypeDef *LPTIMx, uint32_t Repetition)
{
  MODIFY_REG(LPTIMx->RCR, LPTIM_RCR_REP, Repetition);
}

   
                                    
                                                             
                                           
                                                                    
    
__STATIC_INLINE uint32_t LL_LPTIM_GetRepetition(const LPTIM_TypeDef *LPTIMx)
{
  return (uint32_t)(READ_BIT(LPTIMx->RCR, LPTIM_RCR_REP));
}
#endif

   
                                 
                                                                               
                                                                               
                                                                               
                                        
                                                          
                                           
                                                                        
                
    
__STATIC_INLINE void LL_LPTIM_SetCompare(LPTIM_TypeDef *LPTIMx, uint32_t CompareValue)
{
  MODIFY_REG(LPTIMx->CMP, LPTIM_CMP_CMP, CompareValue);
}

   
                                    
                                                          
                                           
                                                                        
    
__STATIC_INLINE uint32_t LL_LPTIM_GetCompare(const LPTIM_TypeDef *LPTIMx)
{
  return (uint32_t)(READ_BIT(LPTIMx->CMP, LPTIM_CMP_CMP));
}

   
                                    
                                                                                
                                                                               
                                                                             
                                                     
                                                          
                                           
                         
    
__STATIC_INLINE uint32_t LL_LPTIM_GetCounter(const LPTIM_TypeDef *LPTIMx)
{
  return (uint32_t)(READ_BIT(LPTIMx->CNT, LPTIM_CNT_CNT));
}

   
                                                                               
                                                                               
                                                              
                                           
                                                                          
                                                    
                                                    
                
    
__STATIC_INLINE void LL_LPTIM_SetCounterMode(LPTIM_TypeDef *LPTIMx, uint32_t CounterMode)
{
  MODIFY_REG(LPTIMx->CFGR, LPTIM_CFGR_COUNTMODE, CounterMode);
}

   
                                
                                                              
                                           
                                                              
                                                    
                                                    
    
__STATIC_INLINE uint32_t LL_LPTIM_GetCounterMode(const LPTIM_TypeDef *LPTIMx)
{
  return (uint32_t)(READ_BIT(LPTIMx->CFGR, LPTIM_CFGR_COUNTMODE));
}

   
                                                            
                                                                           
                                                                     
                                                                                
                                                                          
                                                              
                                                            
                                           
                                                                       
                                                  
                                                      
                                                                       
                                                      
                                                      
                
    
__STATIC_INLINE void LL_LPTIM_ConfigOutput(LPTIM_TypeDef *LPTIMx, uint32_t Waveform, uint32_t Polarity)
{
  MODIFY_REG(LPTIMx->CFGR, LPTIM_CFGR_WAVE | LPTIM_CFGR_WAVPOL, Waveform | Polarity);
}

   
                               
                                                           
                                           
                                                                       
                                                  
                                                      
                
    
__STATIC_INLINE void LL_LPTIM_SetWaveform(LPTIM_TypeDef *LPTIMx, uint32_t Waveform)
{
  MODIFY_REG(LPTIMx->CFGR, LPTIM_CFGR_WAVE, Waveform);
}

   
                                     
                                                           
                                           
                                                              
                                                  
                                                      
    
__STATIC_INLINE uint32_t LL_LPTIM_GetWaveform(const LPTIM_TypeDef *LPTIMx)
{
  return (uint32_t)(READ_BIT(LPTIMx->CFGR, LPTIM_CFGR_WAVE));
}

   
                                
                                                           
                                           
                                                                       
                                                      
                                                      
                
    
__STATIC_INLINE void LL_LPTIM_SetPolarity(LPTIM_TypeDef *LPTIMx, uint32_t Polarity)
{
  MODIFY_REG(LPTIMx->CFGR, LPTIM_CFGR_WAVPOL, Polarity);
}

   
                                      
                                                           
                                           
                                                              
                                                      
                                                      
    
__STATIC_INLINE uint32_t LL_LPTIM_GetPolarity(const LPTIM_TypeDef *LPTIMx)
{
  return (uint32_t)(READ_BIT(LPTIMx->CFGR, LPTIM_CFGR_WAVPOL));
}

   
                                                
                                                                           
                                                                                
                                                                           
                                                                               
                                             
                                                            
                                           
                                                                        
                                             
                                             
                                             
                                             
                                              
                                              
                                              
                                               
                
    
__STATIC_INLINE void LL_LPTIM_SetPrescaler(LPTIM_TypeDef *LPTIMx, uint32_t Prescaler)
{
  MODIFY_REG(LPTIMx->CFGR, LPTIM_CFGR_PRESC, Prescaler);
}

   
                                                
                                                            
                                           
                                                              
                                             
                                             
                                             
                                             
                                              
                                              
                                              
                                               
    
__STATIC_INLINE uint32_t LL_LPTIM_GetPrescaler(const LPTIM_TypeDef *LPTIMx)
{
  return (uint32_t)(READ_BIT(LPTIMx->CFGR, LPTIM_CFGR_PRESC));
}

   
                                                    
                                                  
                                           
                                                                  
                                              
                                               
                                               
                                                     
                
    
__STATIC_INLINE void LL_LPTIM_SetInput1Src(LPTIM_TypeDef *LPTIMx, uint32_t Src)
{
  MODIFY_REG(LPTIMx->OR, LPTIM_OR_OR, Src);
}

   
                                                    
                                                  
                                           
                                                                  
                                              
                                               
                
    
__STATIC_INLINE void LL_LPTIM_SetInput2Src(LPTIM_TypeDef *LPTIMx, uint32_t Src)
{
  MODIFY_REG(LPTIMx->OR, LPTIM_OR_OR, Src);
}

   
      
    

                                                                     
      
    

   
                                       
                                                                           
                                                                              
                                                                  
                                                                           
                                                                           
                              
                                                             
                                           
                
    
__STATIC_INLINE void LL_LPTIM_EnableTimeout(LPTIM_TypeDef *LPTIMx)
{
  SET_BIT(LPTIMx->CFGR, LPTIM_CFGR_TIMOUT);
}

   
                                        
                                                                           
                                                                            
                  
                                                              
                                           
                
    
__STATIC_INLINE void LL_LPTIM_DisableTimeout(LPTIM_TypeDef *LPTIMx)
{
  CLEAR_BIT(LPTIMx->CFGR, LPTIM_CFGR_TIMOUT);
}

   
                                                             
                                                                
                                           
                                  
    
__STATIC_INLINE uint32_t LL_LPTIM_IsEnabledTimeout(const LPTIM_TypeDef *LPTIMx)
{
  return (((READ_BIT(LPTIMx->CFGR, LPTIM_CFGR_TIMOUT) == LPTIM_CFGR_TIMOUT) ? 1UL : 0UL));
}

   
                                   
                                                                           
                                                      
                                           
                
    
__STATIC_INLINE void LL_LPTIM_TrigSw(LPTIM_TypeDef *LPTIMx)
{
  CLEAR_BIT(LPTIMx->CFGR, LPTIM_CFGR_TRIGEN);
}

   
                                                                                 
                                                                           
                                                                           
                                   
                                                               
                                                               
                                                             
                                           
                                                                     
                                               
                                                    
                                                    
                                                   
                                                   
                                                   
                                                
                                                
                                                                     
                                               
                                            
                                            
                                            
                                                                       
                                                   
                                                    
                                                           
                
    
__STATIC_INLINE void LL_LPTIM_ConfigTrigger(LPTIM_TypeDef *LPTIMx, uint32_t Source, uint32_t Filter, uint32_t Polarity)
{
  MODIFY_REG(LPTIMx->CFGR, LPTIM_CFGR_TRIGSEL | LPTIM_CFGR_TRGFLT | LPTIM_CFGR_TRIGEN, Source | Filter | Polarity);
}

   
                                               
                                                                
                                           
                                                              
                                               
                                                    
                                                    
                                                   
                                                   
                                                   
                                                
                                                
    
__STATIC_INLINE uint32_t LL_LPTIM_GetTriggerSource(const LPTIM_TypeDef *LPTIMx)
{
  return (uint32_t)(READ_BIT(LPTIMx->CFGR, LPTIM_CFGR_TRIGSEL));
}

   
                                               
                                                                
                                           
                                                              
                                               
                                            
                                            
                                            
    
__STATIC_INLINE uint32_t LL_LPTIM_GetTriggerFilter(const LPTIM_TypeDef *LPTIMx)
{
  return (uint32_t)(READ_BIT(LPTIMx->CFGR, LPTIM_CFGR_TRGFLT));
}

   
                                                 
                                                                  
                                           
                                                              
                                                   
                                                    
                                                           
    
__STATIC_INLINE uint32_t LL_LPTIM_GetTriggerPolarity(const LPTIM_TypeDef *LPTIMx)
{
  return (uint32_t)(READ_BIT(LPTIMx->CFGR, LPTIM_CFGR_TRIGEN));
}

   
      
    

                                                                 
      
    

   
                                                                   
                                                                           
                                                              
                                           
                                                                          
                                                  
                                                  
                
    
__STATIC_INLINE void LL_LPTIM_SetClockSource(LPTIM_TypeDef *LPTIMx, uint32_t ClockSource)
{
  MODIFY_REG(LPTIMx->CFGR, LPTIM_CFGR_CKSEL, ClockSource);
}

   
                                                   
                                                              
                                           
                                                              
                                                  
                                                  
    
__STATIC_INLINE uint32_t LL_LPTIM_GetClockSource(const LPTIM_TypeDef *LPTIMx)
{
  return (uint32_t)(READ_BIT(LPTIMx->CFGR, LPTIM_CFGR_CKSEL));
}

   
                                                                       
                                                             
                                                                           
                                                                           
                                                                           
                                                                              
                                                                           
                                      
                                                             
                                                           
                                           
                                                                          
                                              
                                           
                                           
                                           
                                                                            
                                                  
                                                   
                                                          
                
    
__STATIC_INLINE void LL_LPTIM_ConfigClock(LPTIM_TypeDef *LPTIMx, uint32_t ClockFilter, uint32_t ClockPolarity)
{
  MODIFY_REG(LPTIMx->CFGR, LPTIM_CFGR_CKFLT | LPTIM_CFGR_CKPOL, ClockFilter | ClockPolarity);
}

   
                                     
                                                                
                                           
                                                              
                                                  
                                                   
                                                          
    
__STATIC_INLINE uint32_t LL_LPTIM_GetClockPolarity(const LPTIM_TypeDef *LPTIMx)
{
  return (uint32_t)(READ_BIT(LPTIMx->CFGR, LPTIM_CFGR_CKPOL));
}

   
                                           
                                                              
                                           
                                                              
                                              
                                           
                                           
                                           
    
__STATIC_INLINE uint32_t LL_LPTIM_GetClockFilter(const LPTIM_TypeDef *LPTIMx)
{
  return (uint32_t)(READ_BIT(LPTIMx->CFGR, LPTIM_CFGR_CKFLT));
}

   
      
    

                                                   
      
    

   
                                       
                                                                           
                                                              
                                           
                                                                          
                                                  
                                                   
                                                          
                
    
__STATIC_INLINE void LL_LPTIM_SetEncoderMode(LPTIM_TypeDef *LPTIMx, uint32_t EncoderMode)
{
  MODIFY_REG(LPTIMx->CFGR, LPTIM_CFGR_CKPOL, EncoderMode);
}

   
                                    
                                                              
                                           
                                                              
                                                  
                                                   
                                                          
    
__STATIC_INLINE uint32_t LL_LPTIM_GetEncoderMode(const LPTIM_TypeDef *LPTIMx)
{
  return (uint32_t)(READ_BIT(LPTIMx->CFGR, LPTIM_CFGR_CKPOL));
}

   
                                   
                                                                           
                                                                              
                                                                        
                                                                             
                           
                                                                 
                                           
                
    
__STATIC_INLINE void LL_LPTIM_EnableEncoderMode(LPTIM_TypeDef *LPTIMx)
{
  SET_BIT(LPTIMx->CFGR, LPTIM_CFGR_ENC);
}

   
                                    
                                                                           
                                                                  
                                           
                
    
__STATIC_INLINE void LL_LPTIM_DisableEncoderMode(LPTIM_TypeDef *LPTIMx)
{
  CLEAR_BIT(LPTIMx->CFGR, LPTIM_CFGR_ENC);
}

   
                                                                 
                                                                    
                                           
                                  
    
__STATIC_INLINE uint32_t LL_LPTIM_IsEnabledEncoderMode(const LPTIM_TypeDef *LPTIMx)
{
  return (((READ_BIT(LPTIMx->CFGR, LPTIM_CFGR_ENC) == LPTIM_CFGR_ENC) ? 1UL : 0UL));
}

   
      
    

                                                         
      
    


   
                                                 
                                                              
                                           
                
    
__STATIC_INLINE void LL_LPTIM_ClearFlag_CMPM(LPTIM_TypeDef *LPTIMx)
{
  SET_BIT(LPTIMx->ICR, LPTIM_ICR_CMPMCF);
}

   
                                                                              
                                                                 
                                           
                                  
    
__STATIC_INLINE uint32_t LL_LPTIM_IsActiveFlag_CMPM(const LPTIM_TypeDef *LPTIMx)
{
  return (((READ_BIT(LPTIMx->ISR, LPTIM_ISR_CMPM) == LPTIM_ISR_CMPM) ? 1UL : 0UL));
}

   
                                                    
                                                              
                                           
                
    
__STATIC_INLINE void LL_LPTIM_ClearFlag_ARRM(LPTIM_TypeDef *LPTIMx)
{
  SET_BIT(LPTIMx->ICR, LPTIM_ICR_ARRMCF);
}

   
                                                                                 
                                                                 
                                           
                                  
    
__STATIC_INLINE uint32_t LL_LPTIM_IsActiveFlag_ARRM(const LPTIM_TypeDef *LPTIMx)
{
  return (((READ_BIT(LPTIMx->ISR, LPTIM_ISR_ARRM) == LPTIM_ISR_ARRM) ? 1UL : 0UL));
}

   
                                                                  
                                                                 
                                           
                
    
__STATIC_INLINE void LL_LPTIM_ClearFlag_EXTTRIG(LPTIM_TypeDef *LPTIMx)
{
  SET_BIT(LPTIMx->ICR, LPTIM_ICR_EXTTRIGCF);
}

   
                                                                                                        
                                                                    
                                           
                                  
    
__STATIC_INLINE uint32_t LL_LPTIM_IsActiveFlag_EXTTRIG(const LPTIM_TypeDef *LPTIMx)
{
  return (((READ_BIT(LPTIMx->ISR, LPTIM_ISR_EXTTRIG) == LPTIM_ISR_EXTTRIG) ? 1UL : 0UL));
}

   
                                                                       
                                                               
                                           
                
    
__STATIC_INLINE void LL_LPTIM_ClearFlag_CMPOK(LPTIM_TypeDef *LPTIMx)
{
  SET_BIT(LPTIMx->ICR, LPTIM_ICR_CMPOKCF);
}

   
                                                                                                                    
                                                         
                                                                  
                                           
                                  
    
__STATIC_INLINE uint32_t LL_LPTIM_IsActiveFlag_CMPOK(const LPTIM_TypeDef *LPTIMx)
{
  return (((READ_BIT(LPTIMx->ISR, LPTIM_ISR_CMPOK) == LPTIM_ISR_CMPOK) ? 1UL : 0UL));
}

   
                                                                          
                                                               
                                           
                
    
__STATIC_INLINE void LL_LPTIM_ClearFlag_ARROK(LPTIM_TypeDef *LPTIMx)
{
  SET_BIT(LPTIMx->ICR, LPTIM_ICR_ARROKCF);
}

   
                                                                                                                    
                                                         
                                                                  
                                           
                                  
    
__STATIC_INLINE uint32_t LL_LPTIM_IsActiveFlag_ARROK(const LPTIM_TypeDef *LPTIMx)
{
  return (((READ_BIT(LPTIMx->ISR, LPTIM_ISR_ARROK) == LPTIM_ISR_ARROK) ? 1UL : 0UL));
}

   
                                                                           
                                                            
                                           
                
    
__STATIC_INLINE void LL_LPTIM_ClearFlag_UP(LPTIM_TypeDef *LPTIMx)
{
  SET_BIT(LPTIMx->ICR, LPTIM_ICR_UPCF);
}

   
                                                                                                                      
                                      
                                                               
                                           
                                  
    
__STATIC_INLINE uint32_t LL_LPTIM_IsActiveFlag_UP(const LPTIM_TypeDef *LPTIMx)
{
  return (((READ_BIT(LPTIMx->ISR, LPTIM_ISR_UP) == LPTIM_ISR_UP) ? 1UL : 0UL));
}

   
                                                                               
                                                              
                                           
                
    
__STATIC_INLINE void LL_LPTIM_ClearFlag_DOWN(LPTIM_TypeDef *LPTIMx)
{
  SET_BIT(LPTIMx->ICR, LPTIM_ICR_DOWNCF);
}

   
                                                                                                                      
                                      
                                                                 
                                           
                                  
    
__STATIC_INLINE uint32_t LL_LPTIM_IsActiveFlag_DOWN(const LPTIM_TypeDef *LPTIMx)
{
  return (((READ_BIT(LPTIMx->ISR, LPTIM_ISR_DOWN) == LPTIM_ISR_DOWN) ? 1UL : 0UL));
}

#if defined(LPTIM_RCR_REP)
   
                                                                          
                                                               
                                           
                
    
__STATIC_INLINE void LL_LPTIM_ClearFlag_REPOK(LPTIM_TypeDef *LPTIMx)
{
  SET_BIT(LPTIMx->ICR, LPTIM_ICR_REPOKCF);
}

   
                                                                                                                    
                                                         
                                                                  
                                           
                                  
    
__STATIC_INLINE uint32_t LL_LPTIM_IsActiveFlag_REPOK(const LPTIM_TypeDef *LPTIMx)
{
  return ((READ_BIT(LPTIMx->ISR, LPTIM_ISR_REPOK) == (LPTIM_ISR_REPOK)) ? 1UL : 0UL);
}

   
                                               
                                                            
                                           
                
    
__STATIC_INLINE void LL_LPTIM_ClearFlag_UE(LPTIM_TypeDef *LPTIMx)
{
  SET_BIT(LPTIMx->ICR, LPTIM_ICR_UECF);
}

   
                                                                             
                                                               
                                           
                                  
    
__STATIC_INLINE uint32_t LL_LPTIM_IsActiveFlag_UE(const LPTIM_TypeDef *LPTIMx)
{
  return ((READ_BIT(LPTIMx->ISR, LPTIM_ISR_UE) == (LPTIM_ISR_UE)) ? 1UL : 0UL);
}
#endif

   
      
    

                                                            
      
    

   
                                                    
                                                             
                                           
                
    
__STATIC_INLINE void LL_LPTIM_EnableIT_CMPM(LPTIM_TypeDef *LPTIMx)
{
  SET_BIT(LPTIMx->IER, LPTIM_IER_CMPMIE);
}

   
                                                     
                                                              
                                           
                
    
__STATIC_INLINE void LL_LPTIM_DisableIT_CMPM(LPTIM_TypeDef *LPTIMx)
{
  CLEAR_BIT(LPTIMx->IER, LPTIM_IER_CMPMIE);
}

   
                                                                              
                                                                
                                           
                                  
    
__STATIC_INLINE uint32_t LL_LPTIM_IsEnabledIT_CMPM(const LPTIM_TypeDef *LPTIMx)
{
  return (((READ_BIT(LPTIMx->IER, LPTIM_IER_CMPMIE) == LPTIM_IER_CMPMIE) ? 1UL : 0UL));
}

   
                                                       
                                                             
                                           
                
    
__STATIC_INLINE void LL_LPTIM_EnableIT_ARRM(LPTIM_TypeDef *LPTIMx)
{
  SET_BIT(LPTIMx->IER, LPTIM_IER_ARRMIE);
}

   
                                                        
                                                              
                                           
                
    
__STATIC_INLINE void LL_LPTIM_DisableIT_ARRM(LPTIM_TypeDef *LPTIMx)
{
  CLEAR_BIT(LPTIMx->IER, LPTIM_IER_ARRMIE);
}

   
                                                                                 
                                                                
                                           
                                  
    
__STATIC_INLINE uint32_t LL_LPTIM_IsEnabledIT_ARRM(const LPTIM_TypeDef *LPTIMx)
{
  return (((READ_BIT(LPTIMx->IER, LPTIM_IER_ARRMIE) == LPTIM_IER_ARRMIE) ? 1UL : 0UL));
}

   
                                                                     
                                                                
                                           
                
    
__STATIC_INLINE void LL_LPTIM_EnableIT_EXTTRIG(LPTIM_TypeDef *LPTIMx)
{
  SET_BIT(LPTIMx->IER, LPTIM_IER_EXTTRIGIE);
}

   
                                                                      
                                                                 
                                           
                
    
__STATIC_INLINE void LL_LPTIM_DisableIT_EXTTRIG(LPTIM_TypeDef *LPTIMx)
{
  CLEAR_BIT(LPTIMx->IER, LPTIM_IER_EXTTRIGIE);
}

   
                                                                                   
                                                                   
                                           
                                  
    
__STATIC_INLINE uint32_t LL_LPTIM_IsEnabledIT_EXTTRIG(const LPTIM_TypeDef *LPTIMx)
{
  return (((READ_BIT(LPTIMx->IER, LPTIM_IER_EXTTRIGIE) == LPTIM_IER_EXTTRIGIE) ? 1UL : 0UL));
}

   
                                                                        
                                                              
                                           
                
    
__STATIC_INLINE void LL_LPTIM_EnableIT_CMPOK(LPTIM_TypeDef *LPTIMx)
{
  SET_BIT(LPTIMx->IER, LPTIM_IER_CMPOKIE);
}

   
                                                                         
                                                               
                                           
                
    
__STATIC_INLINE void LL_LPTIM_DisableIT_CMPOK(LPTIM_TypeDef *LPTIMx)
{
  CLEAR_BIT(LPTIMx->IER, LPTIM_IER_CMPOKIE);
}

   
                                                                                                  
                                                                 
                                           
                                  
    
__STATIC_INLINE uint32_t LL_LPTIM_IsEnabledIT_CMPOK(const LPTIM_TypeDef *LPTIMx)
{
  return (((READ_BIT(LPTIMx->IER, LPTIM_IER_CMPOKIE) == LPTIM_IER_CMPOKIE) ? 1UL : 0UL));
}

   
                                                                           
                                                             
                                           
                
    
__STATIC_INLINE void LL_LPTIM_EnableIT_ARROK(LPTIM_TypeDef *LPTIMx)
{
  SET_BIT(LPTIMx->IER, LPTIM_IER_ARROKIE);
}

   
                                                                            
                                                              
                                           
                
    
__STATIC_INLINE void LL_LPTIM_DisableIT_ARROK(LPTIM_TypeDef *LPTIMx)
{
  CLEAR_BIT(LPTIMx->IER, LPTIM_IER_ARROKIE);
}

   
                                                                                                     
                                                                
                                           
                                 
    
__STATIC_INLINE uint32_t LL_LPTIM_IsEnabledIT_ARROK(const LPTIM_TypeDef *LPTIMx)
{
  return (((READ_BIT(LPTIMx->IER, LPTIM_IER_ARROKIE) == LPTIM_IER_ARROKIE) ? 1UL : 0UL));
}

   
                                                           
                                                          
                                           
                
    
__STATIC_INLINE void LL_LPTIM_EnableIT_UP(LPTIM_TypeDef *LPTIMx)
{
  SET_BIT(LPTIMx->IER, LPTIM_IER_UPIE);
}

   
                                                            
                                                           
                                           
                
    
__STATIC_INLINE void LL_LPTIM_DisableIT_UP(LPTIM_TypeDef *LPTIMx)
{
  CLEAR_BIT(LPTIMx->IER, LPTIM_IER_UPIE);
}

   
                                                                                     
                                                             
                                           
                                 
    
__STATIC_INLINE uint32_t LL_LPTIM_IsEnabledIT_UP(const LPTIM_TypeDef *LPTIMx)
{
  return (((READ_BIT(LPTIMx->IER, LPTIM_IER_UPIE) == LPTIM_IER_UPIE) ? 1UL : 0UL));
}

   
                                                               
                                                            
                                           
                
    
__STATIC_INLINE void LL_LPTIM_EnableIT_DOWN(LPTIM_TypeDef *LPTIMx)
{
  SET_BIT(LPTIMx->IER, LPTIM_IER_DOWNIE);
}

   
                                                                
                                                             
                                           
                
    
__STATIC_INLINE void LL_LPTIM_DisableIT_DOWN(LPTIM_TypeDef *LPTIMx)
{
  CLEAR_BIT(LPTIMx->IER, LPTIM_IER_DOWNIE);
}

   
                                                                                         
                                                               
                                           
                                 
    
__STATIC_INLINE uint32_t LL_LPTIM_IsEnabledIT_DOWN(const LPTIM_TypeDef *LPTIMx)
{
  return ((READ_BIT(LPTIMx->IER, LPTIM_IER_DOWNIE) == LPTIM_IER_DOWNIE) ? 1UL : 0UL);
}

#if defined(LPTIM_RCR_REP)
   
                                                                                         
                                                             
                                           
                
    
__STATIC_INLINE void LL_LPTIM_EnableIT_REPOK(LPTIM_TypeDef *LPTIMx)
{
  SET_BIT(LPTIMx->IER, LPTIM_IER_REPOKIE);
}

   
                                                                                          
                                                              
                                           
                
    
__STATIC_INLINE void LL_LPTIM_DisableIT_REPOK(LPTIM_TypeDef *LPTIMx)
{
  CLEAR_BIT(LPTIMx->IER, LPTIM_IER_REPOKIE);
}

   
                                                                                                                   
                                                                
                                           
                                 
    
__STATIC_INLINE uint32_t LL_LPTIM_IsEnabledIT_REPOK(const LPTIM_TypeDef *LPTIMx)
{
  return ((READ_BIT(LPTIMx->IER, LPTIM_IER_REPOKIE) == (LPTIM_IER_REPOKIE)) ? 1UL : 0UL);
}

   
                                                 
                                                          
                                           
                
    
__STATIC_INLINE void LL_LPTIM_EnableIT_UE(LPTIM_TypeDef *LPTIMx)
{
  SET_BIT(LPTIMx->IER, LPTIM_IER_UEIE);
}

   
                                                  
                                                           
                                           
                
    
__STATIC_INLINE void LL_LPTIM_DisableIT_UE(LPTIM_TypeDef *LPTIMx)
{
  CLEAR_BIT(LPTIMx->IER, LPTIM_IER_UEIE);
}

   
                                                                           
                                                             
                                           
                                 
    
__STATIC_INLINE uint32_t LL_LPTIM_IsEnabledIT_UE(const LPTIM_TypeDef *LPTIMx)
{
  return ((READ_BIT(LPTIMx->IER, LPTIM_IER_UEIE) == (LPTIM_IER_UEIE)) ? 1UL : 0UL);
}
#endif
   
      
    

   
      
    

   
      
    

#endif                       

   
      
    

#ifdef __cplusplus
}
#endif

#endif                           
