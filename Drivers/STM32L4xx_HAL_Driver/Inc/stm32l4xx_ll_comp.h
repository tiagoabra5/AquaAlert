/**
  ******************************************************************************
  * @file    stm32l4xx_ll_comp.h
  * @author  MCD Application Team
  * @brief   Header file of COMP LL module.
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

                                                                                
#ifndef STM32L4xx_LL_COMP_H
#define STM32L4xx_LL_COMP_H

#ifdef __cplusplus
extern "C" {
#endif

                                                                                
#include "stm32l4xx.h"

                                   
      
    

#if defined (COMP1) || defined (COMP2)

                          
      
    

                                                                                
                                                                                
                                                                                
                                                              
      
    

                                   
#define LL_COMP_OUTPUT_LEVEL_BITOFFSET_POS (30UL)                                                       

   
      
    

                                                                                
                                                        
      
    

   
      
    

                                                                                
#if defined(USE_FULL_LL_DRIVER)
                                                          
      
    

   
                                                                   
    
typedef struct
{
  uint32_t PowerMode;                                                                                
                                                                                                       
                                                                                                  
                                                                                     

  uint32_t InputPlus;                                                                        
                                                                                                        
                                                                                                           
                                                                            

  uint32_t InputMinus;                                                                    
                                                                                                         
                                                                                                           
                                                                              

  uint32_t InputHysteresis;                                                                    
                                                                                                              
                                                                                                           
                                                                                  

  uint32_t OutputPolarity;                                                  
                                                                                                             
                                                                                                           
                                                                                 

  uint32_t OutputBlankingSource;                                            
                                                                                                                    
                                                                                                           
                                                                                       

} LL_COMP_InitTypeDef;

   
      
    
#endif                         

                                                                                
                                                                
      
    


                                                                                
      
    
#if defined(COMP2)
#define LL_COMP_WINDOWMODE_DISABLE                 (0x00000000UL)                                                                          
#define LL_COMP_WINDOWMODE_COMP1_INPUT_PLUS_COMMON (COMP_CSR_WINMODE)                                                                                                                                                                                                     
#endif            
   
      
    



                                                                
      
    
#define LL_COMP_POWERMODE_HIGHSPEED     (0x00000000UL)                                                                 
#define LL_COMP_POWERMODE_MEDIUMSPEED   (COMP_CSR_PWRMODE_0)                                                             
#define LL_COMP_POWERMODE_ULTRALOWPOWER (COMP_CSR_PWRMODE_1 | COMP_CSR_PWRMODE_0)                                           
   
      
    

                                                                                                  
      
    
#define LL_COMP_INPUT_PLUS_IO1          (0x00000000UL)                                                                                                               
#define LL_COMP_INPUT_PLUS_IO2          (COMP_CSR_INPSEL_0)                                                                                                          
#if defined(COMP_CSR_INPSEL_1)
#define LL_COMP_INPUT_PLUS_IO3          (COMP_CSR_INPSEL_1)                                                                                                          
#endif                        
   
      
    

                                                                                                
      
    
#define LL_COMP_INPUT_MINUS_1_4VREFINT  (                                                            COMP_CSR_SCALEN | COMP_CSR_BRGEN)                                                                
#define LL_COMP_INPUT_MINUS_1_2VREFINT  (                                        COMP_CSR_INMSEL_0 | COMP_CSR_SCALEN | COMP_CSR_BRGEN)                                                                
#define LL_COMP_INPUT_MINUS_3_4VREFINT  (                    COMP_CSR_INMSEL_1                     | COMP_CSR_SCALEN | COMP_CSR_BRGEN)                                                                
#define LL_COMP_INPUT_MINUS_VREFINT     (                    COMP_CSR_INMSEL_1 | COMP_CSR_INMSEL_0 | COMP_CSR_SCALEN                 )                                                           
#define LL_COMP_INPUT_MINUS_DAC1_CH1    (COMP_CSR_INMSEL_2                                        )                                                                                                                 
#define LL_COMP_INPUT_MINUS_DAC1_CH2    (COMP_CSR_INMSEL_2                     | COMP_CSR_INMSEL_0)                                                                                                                 
#define LL_COMP_INPUT_MINUS_IO1         (COMP_CSR_INMSEL_2 | COMP_CSR_INMSEL_1                    )                                                                                                                                 
#define LL_COMP_INPUT_MINUS_IO2         (COMP_CSR_INMSEL_2 | COMP_CSR_INMSEL_1 | COMP_CSR_INMSEL_0)                                                                                                                                 
#if defined(COMP_CSR_INMESEL_1)
#define LL_COMP_INPUT_MINUS_IO3         (                     COMP_CSR_INMESEL_0 | COMP_CSR_INMSEL_2 | COMP_CSR_INMSEL_1 | COMP_CSR_INMSEL_0)                                                                                       
#define LL_COMP_INPUT_MINUS_IO4         (COMP_CSR_INMESEL_1                      | COMP_CSR_INMSEL_2 | COMP_CSR_INMSEL_1 | COMP_CSR_INMSEL_0)                                                                                       
#define LL_COMP_INPUT_MINUS_IO5         (COMP_CSR_INMESEL_1 | COMP_CSR_INMESEL_0 | COMP_CSR_INMSEL_2 | COMP_CSR_INMSEL_1 | COMP_CSR_INMSEL_0)                                                                                       
#endif
   
      
    

                                                                            
      
    
#define LL_COMP_WINDOWMODE_ENABLE         LL_COMP_WINDOWMODE_COMP1_INPUT_PLUS_COMMON

#define LL_COMP_INVERTINGINPUT_1_4VREFINT LL_COMP_INPUT_MINUS_1_4VREFINT
#define LL_COMP_INVERTINGINPUT_1_2VREFINT LL_COMP_INPUT_MINUS_1_2VREFINT
#define LL_COMP_INVERTINGINPUT_3_4VREFINT LL_COMP_INPUT_MINUS_3_4VREFINT
#define LL_COMP_INVERTINGINPUT_VREFINT    LL_COMP_INPUT_MINUS_VREFINT
#define LL_COMP_INVERTINGINPUT_DAC1       LL_COMP_INPUT_MINUS_DAC1_CH1
#define LL_COMP_INVERTINGINPUT_DAC2       LL_COMP_INPUT_MINUS_DAC1_CH2
#define LL_COMP_INVERTINGINPUT_IO1        LL_COMP_INPUT_MINUS_IO1
#define LL_COMP_INVERTINGINPUT_IO2        LL_COMP_INPUT_MINUS_IO2
#if defined(COMP_CSR_INMESEL_1)
#define LL_COMP_INVERTINGINPUT_IO3        LL_COMP_INPUT_MINUS_IO3
#define LL_COMP_INVERTINGINPUT_IO4        LL_COMP_INPUT_MINUS_IO4
#define LL_COMP_INVERTINGINPUT_IO5        LL_COMP_INPUT_MINUS_IO5
#endif                         

#define LL_COMP_NONINVERTINGINPUT_IO1     LL_COMP_INPUT_PLUS_IO1
#define LL_COMP_NONINVERTINGINPUT_IO2     LL_COMP_INPUT_PLUS_IO2
#if defined(COMP_CSR_INPSEL_1)
#define LL_COMP_NONINVERTINGINPUT_IO3     LL_COMP_INPUT_PLUS_IO3
#endif                        
   
      
    

                                                                       
      
    
#define LL_COMP_HYSTERESIS_NONE         (0x00000000UL)                                           
#define LL_COMP_HYSTERESIS_LOW          (                  COMP_CSR_HYST_0)                             
#define LL_COMP_HYSTERESIS_MEDIUM       (COMP_CSR_HYST_1                  )                                
#define LL_COMP_HYSTERESIS_HIGH         (COMP_CSR_HYST_1 | COMP_CSR_HYST_0)                              
   
      
    

                                                                            
      
    
#define LL_COMP_OUTPUTPOL_NONINVERTED   (0x00000000UL)                                                                                                                                                                             
#define LL_COMP_OUTPUTPOL_INVERTED      (COMP_CSR_POLARITY)                                                                                                                                                                  
   
      
    

                                                                                   
      
    
#define LL_COMP_BLANKINGSRC_NONE            (0x00000000UL)                                                   
#define LL_COMP_BLANKINGSRC_TIM1_OC5_COMP1  (COMP_CSR_BLANKING_0)                                                                                        
#define LL_COMP_BLANKINGSRC_TIM2_OC3_COMP1  (COMP_CSR_BLANKING_1)                                                                                        
#define LL_COMP_BLANKINGSRC_TIM3_OC3_COMP1  (COMP_CSR_BLANKING_2)                                                                                        
#define LL_COMP_BLANKINGSRC_TIM3_OC4_COMP2  (COMP_CSR_BLANKING_0)                                                                                        
#define LL_COMP_BLANKINGSRC_TIM8_OC5_COMP2  (COMP_CSR_BLANKING_1)                                                                                        
#define LL_COMP_BLANKINGSRC_TIM15_OC1_COMP2 (COMP_CSR_BLANKING_2)                                                                                         
   
      
    

                                                                                                             
      
    
#define LL_COMP_BLANKINGSRC_TIM1_OC5    (LL_COMP_BLANKINGSRC_TIM1_OC5_COMP1)
#define LL_COMP_BLANKINGSRC_TIM2_OC3    (LL_COMP_BLANKINGSRC_TIM2_OC3_COMP1)
#define LL_COMP_BLANKINGSRC_TIM3_OC3    (LL_COMP_BLANKINGSRC_TIM3_OC3_COMP1)

#define LL_COMP_BLANKINGSRC_TIM3_OC4    (LL_COMP_BLANKINGSRC_TIM3_OC4_COMP2)
#define LL_COMP_BLANKINGSRC_TIM8_OC5    (LL_COMP_BLANKINGSRC_TIM8_OC5_COMP2)
#define LL_COMP_BLANKINGSRC_TIM15_OC1   (LL_COMP_BLANKINGSRC_TIM15_OC1_COMP2)
   
      
    

                                                                      
      
    
#define LL_COMP_OUTPUT_LEVEL_LOW        (0x00000000UL)                                                                                                             
#define LL_COMP_OUTPUT_LEVEL_HIGH       (0x00000001UL)                                                                                                              
   
      
    

                                                                                   
                                                                                
                               
                                                                              
                                          
      
    

                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
#define LL_COMP_DELAY_STARTUP_US          ( 80UL)                                    

                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
#define LL_COMP_DELAY_VOLTAGE_SCALER_STAB_US ( 200UL)                                                         

   
      
    

   
      
    

                                                                                
                                                          
      
    
                                                                         
      
    

   
                                          
                                            
                                          
                                                         
                
    
#define LL_COMP_WriteReg(__INSTANCE__, __REG__, __VALUE__) WRITE_REG((__INSTANCE__)->__REG__, (__VALUE__))

   
                                         
                                            
                                       
                          
    
#define LL_COMP_ReadReg(__INSTANCE__, __REG__) READ_REG((__INSTANCE__)->__REG__)
   
      
    

                                                       
      
    

   
                                                           
                                                             
                                                        
                                                            
                                                                            
                                   
                                                                                  
    
#define __LL_COMP_COMMON_INSTANCE(__COMPx__)          (COMP12_COMMON)

   
      
    

   
      
    

                                                                                
                                                                
      
    

#if defined(COMP2)
                                                                                                  
                                              
      
    

   
                                                              
                                                                 
                                                               
                                                    
                                                                                                                  
                                                                         
                                                
                                                                
                
    
__STATIC_INLINE void LL_COMP_SetCommonWindowMode(COMP_Common_TypeDef *COMPxy_COMMON, uint32_t WindowMode)
{
                                                                                
                                                                                
  MODIFY_REG(COMPxy_COMMON->CSR, COMP_CSR_WINMODE, WindowMode);
}

   
                                                              
                                                                 
                                                               
                                                    
                                                                                                                  
                                                              
                                                
                                                                
    
__STATIC_INLINE uint32_t LL_COMP_GetCommonWindowMode(const COMP_Common_TypeDef *COMPxy_COMMON)
{
  return (uint32_t)(READ_BIT(COMPxy_COMMON->CSR, COMP_CSR_WINMODE));
}

   
      
    

#endif            
                                                                                         
      
    

   
                                                                             
                                                        
                                     
                                                                        
                                                 
                                                   
                                                     
                
    
__STATIC_INLINE void LL_COMP_SetPowerMode(COMP_TypeDef *COMPx, uint32_t PowerMode)
{
  MODIFY_REG(COMPx->CSR, COMP_CSR_PWRMODE, PowerMode);
}

   
                                                                             
                                                        
                                     
                                                              
                                                 
                                                   
                                                     
    
__STATIC_INLINE uint32_t LL_COMP_GetPowerMode(const COMP_TypeDef *COMPx)
{
  return (uint32_t)(READ_BIT(COMPx->CSR, COMP_CSR_PWRMODE));
}

   
      
    

                                                                                           
      
    

   
                                                                             
                                                                       
                                                               
                                                                      
                                                                
                                                                    
                                                    
                                                                         
                                    
                                                         
                                                                  
                                                                        
                                                                   
                                                                   
                                                                  
                                                                 
                                                          
                                                          
                                                          
                                                        
                                     
                                                                         
                                                    
                                                    
                                                    
                                                 
                                                  
                                                      
                                             
                                             
                                                 
                                                 
                                                 
   
                                                       
                                                                        
                                            
                                            
                                                
   
                                                       
                
    
__STATIC_INLINE void LL_COMP_ConfigInputs(COMP_TypeDef *COMPx, uint32_t InputMinus, uint32_t InputPlus)
{
#if defined(COMP_CSR_INMESEL_1)
  MODIFY_REG(COMPx->CSR,
             COMP_CSR_INMESEL | COMP_CSR_INMSEL | COMP_CSR_INPSEL | COMP_CSR_SCALEN | COMP_CSR_BRGEN,
             InputMinus | InputPlus);
#else
  MODIFY_REG(COMPx->CSR,
             COMP_CSR_INMSEL | COMP_CSR_INPSEL | COMP_CSR_SCALEN | COMP_CSR_BRGEN,
             InputMinus | InputPlus);
#endif
}

   
                                                      
                                                                       
                                                               
                                                                      
                                                        
                                     
                                                                        
                                            
                                            
                                                
   
                                                       
                
    
__STATIC_INLINE void LL_COMP_SetInputPlus(COMP_TypeDef *COMPx, uint32_t InputPlus)
{
  MODIFY_REG(COMPx->CSR, COMP_CSR_INPSEL, InputPlus);
}

   
                                                      
                                                                       
                                                               
                                                                      
                                                        
                                     
                                                              
                                            
                                            
                                                
   
                                                       
    
__STATIC_INLINE uint32_t LL_COMP_GetInputPlus(const COMP_TypeDef *COMPx)
{
  return (uint32_t)(READ_BIT(COMPx->CSR, COMP_CSR_INPSEL));
}

   
                                                   
                                                                       
                                                               
                                                                      
                                                                
                                                                    
                                                    
                                                                         
                                    
                                                         
                                                                  
                                                                        
                                                                   
                                                                   
                                                                  
                                                                 
                                                           
                                                           
                                                         
                                     
                                                                         
                                                    
                                                    
                                                    
                                                 
                                                  
                                                      
                                             
                                             
                                                 
                                                 
                                                 
   
                                                       
                
    
__STATIC_INLINE void LL_COMP_SetInputMinus(COMP_TypeDef *COMPx, uint32_t InputMinus)
{
#if defined(COMP_CSR_INMESEL_1)
  MODIFY_REG(COMPx->CSR, COMP_CSR_INMESEL | COMP_CSR_INMSEL | COMP_CSR_SCALEN | COMP_CSR_BRGEN, InputMinus);
#else
  MODIFY_REG(COMPx->CSR, COMP_CSR_INMSEL | COMP_CSR_SCALEN | COMP_CSR_BRGEN, InputMinus);
#endif                         
}

   
                                                   
                                                                       
                                                               
                                                                      
                                                           
                                                           
                                                         
                                     
                                                              
                                                    
                                                    
                                                    
                                                 
                                                  
                                                      
                                             
                                             
                                                 
                                                 
                                                 
   
                                                       
    
__STATIC_INLINE uint32_t LL_COMP_GetInputMinus(const COMP_TypeDef *COMPx)
{
#if defined(COMP_CSR_INMESEL_1)
  return (uint32_t)(READ_BIT(COMPx->CSR, COMP_CSR_INMESEL | COMP_CSR_INMSEL | COMP_CSR_SCALEN | COMP_CSR_BRGEN));
#else
  return (uint32_t)(READ_BIT(COMPx->CSR, COMP_CSR_INMSEL | COMP_CSR_SCALEN | COMP_CSR_BRGEN));
#endif                         
}

   
                                                                                         
                                                              
                                     
                                                                              
                                             
                                            
                                               
                                             
                
    
__STATIC_INLINE void LL_COMP_SetInputHysteresis(COMP_TypeDef *COMPx, uint32_t InputHysteresis)
{
  MODIFY_REG(COMPx->CSR, COMP_CSR_HYST, InputHysteresis);
}

   
                                                                                   
                                                              
                                     
                                                              
                                             
                                            
                                               
                                             
    
__STATIC_INLINE uint32_t LL_COMP_GetInputHysteresis(const COMP_TypeDef *COMPx)
{
  return (uint32_t)(READ_BIT(COMPx->CSR, COMP_CSR_HYST));
}

   
      
    

                                                                                           
      
    

   
                                                    
                                                             
                                     
                                                                             
                                                   
                                                
                
    
__STATIC_INLINE void LL_COMP_SetOutputPolarity(COMP_TypeDef *COMPx, uint32_t OutputPolarity)
{
  MODIFY_REG(COMPx->CSR, COMP_CSR_POLARITY, OutputPolarity);
}

   
                                                    
                                                             
                                     
                                                              
                                                   
                                                
    
__STATIC_INLINE uint32_t LL_COMP_GetOutputPolarity(const COMP_TypeDef *COMPx)
{
  return (uint32_t)(READ_BIT(COMPx->CSR, COMP_CSR_POLARITY));
}

   
                                                    
                                                                        
                                                                      
                                                                    
                                                                  
                                                                   
                                     
                                                                             
                                              
                                                                
                                                                
                                                                
                                                                
                                                                
                                                                
   
                                                                      
                                       
                                                                                   
                                                                                   
                
    
__STATIC_INLINE void LL_COMP_SetOutputBlankingSource(COMP_TypeDef *COMPx, uint32_t BlankingSource)
{
  MODIFY_REG(COMPx->CSR, COMP_CSR_BLANKING, BlankingSource);
}

   
                                                    
                                                                    
                                                                  
                                                                        
                                                                      
                                                                   
                                     
                                                              
                                              
                                                                
                                                                
                                                                
                                                                
                                                                
                                                                
   
                                                                      
                                       
                                                                                   
                                                                                   
    
__STATIC_INLINE uint32_t LL_COMP_GetOutputBlankingSource(const COMP_TypeDef *COMPx)
{
  return (uint32_t)(READ_BIT(COMPx->CSR, COMP_CSR_BLANKING));
}

   
      
    

                                                                                                    
      
    
                                                                                
                                                                                
__STATIC_INLINE void LL_COMP_SetInputNonInverting(COMP_TypeDef *COMPx, uint32_t InputNonInverting)
{
  LL_COMP_SetInputPlus(COMPx, InputNonInverting);
}
__STATIC_INLINE uint32_t LL_COMP_GetInputNonInverting(const COMP_TypeDef *COMPx)
{
  return LL_COMP_GetInputPlus(COMPx);
}

__STATIC_INLINE void LL_COMP_SetInputInverting(COMP_TypeDef *COMPx, uint32_t InputInverting)
{
  LL_COMP_SetInputMinus(COMPx, InputInverting);
}
__STATIC_INLINE uint32_t LL_COMP_GetInputInverting(const COMP_TypeDef *COMPx)
{
  return LL_COMP_GetInputMinus(COMPx);
}

   
      
    

                                                                   
      
    

   
                                       
                                                                    
                                                           
                                                          
                                                  
                                     
                
    
__STATIC_INLINE void LL_COMP_Enable(COMP_TypeDef *COMPx)
{
  SET_BIT(COMPx->CSR, COMP_CSR_EN);
}

   
                                        
                                                   
                                     
                
    
__STATIC_INLINE void LL_COMP_Disable(COMP_TypeDef *COMPx)
{
  CLEAR_BIT(COMPx->CSR, COMP_CSR_EN);
}

   
                                       
                                                     
                                                     
                                     
                                  
    
__STATIC_INLINE uint32_t LL_COMP_IsEnabled(const COMP_TypeDef *COMPx)
{
  return ((READ_BIT(COMPx->CSR, COMP_CSR_EN) == (COMP_CSR_EN)) ? 1UL : 0UL);
}

   
                                     
                                                                               
                                                                             
                                                
                                     
                
    
__STATIC_INLINE void LL_COMP_Lock(COMP_TypeDef *COMPx)
{
  SET_BIT(COMPx->CSR, COMP_CSR_LOCK);
}

   
                                     
                                                     
                                                                               
                                                                             
                                                    
                                     
                                  
    
__STATIC_INLINE uint32_t LL_COMP_IsLocked(const COMP_TypeDef *COMPx)
{
  return ((READ_BIT(COMPx->CSR, COMP_CSR_LOCK) == (COMP_CSR_LOCK)) ? 1UL : 0UL);
}

   
                                                  
                                                                        
                                                                 
                                                       
                                                           
                                                         
                                                            
                                                          
                                                   
                                                            
                                                         
                                                           
                                                          
                                                           
                                     
                                                              
                                              
                                               
    
__STATIC_INLINE uint32_t LL_COMP_ReadOutputLevel(const COMP_TypeDef *COMPx)
{
  return (uint32_t)(READ_BIT(COMPx->CSR, COMP_CSR_VALUE)
                    >> LL_COMP_OUTPUT_LEVEL_BITOFFSET_POS);
}

   
      
    

#if defined(USE_FULL_LL_DRIVER)
                                                                            
      
    

ErrorStatus LL_COMP_DeInit(COMP_TypeDef *COMPx);
ErrorStatus LL_COMP_Init(COMP_TypeDef *COMPx, const LL_COMP_InitTypeDef *COMP_InitStruct);
void        LL_COMP_StructInit(LL_COMP_InitTypeDef *COMP_InitStruct);

   
      
    
#endif                         

   
      
    

   
      
    

   
      
    

#endif                     

   
      
    

#ifdef __cplusplus
}
#endif

#endif                          
