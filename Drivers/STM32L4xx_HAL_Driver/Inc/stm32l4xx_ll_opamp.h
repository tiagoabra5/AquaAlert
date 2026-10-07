/**
  ******************************************************************************
  * @file    stm32l4xx_ll_opamp.h
  * @author  MCD Application Team
  * @brief   Header file of OPAMP LL module.
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

                                                                                
#ifndef STM32L4xx_LL_OPAMP_H
#define STM32L4xx_LL_OPAMP_H

#ifdef __cplusplus
extern "C" {
#endif

                                                                                
#include "stm32l4xx.h"

                                   
      
    

#if defined (OPAMP1) || defined (OPAMP2)

                            
      
    

                                                                                
                                                                                

                                                                                
                                                                
      
    

                                                                                
                                                                                
                                                                                
                                                                                

                                                               
#define OPAMP_POWERMODE_OTR_REGOFFSET       0x00000000U
#define OPAMP_POWERMODE_LPOTR_REGOFFSET     0x00000001U
#define OPAMP_POWERMODE_OTR_REGOFFSET_MASK  (OPAMP_POWERMODE_OTR_REGOFFSET | OPAMP_POWERMODE_LPOTR_REGOFFSET)

                                                     
#define OPAMP_POWERMODE_CSR_BIT_MASK        (OPAMP_CSR_OPALPM)

                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
#define OPAMP_TRIMMING_SELECT_MASK          (OPAMP1_CSR_CALSEL)
#define OPAMP_TRIMMING_VALUE_MASK           (OPAMP_OTR_TRIMOFFSETP | OPAMP_OTR_TRIMOFFSETN)

   
      
    


                                                                                
                                                          
      
    

   
                                                                    
                                                                 
                       
                                                                    
                                                                            
                            
  
#define __OPAMP_PTR_REG_OFFSET(__REG__, __REG_OFFSET__)                        \
 ((uint32_t *)((uint32_t) ((uint32_t)(&(__REG__)) + ((__REG_OFFSET__) << 2U))))




   
      
    


                                                                                
#if defined(USE_FULL_LL_DRIVER)
                                                            
      
    

   
                                                                    
    
typedef struct
{
  uint32_t PowerMode;                                             
                                                                                                        

                                                                                                                                            

  uint32_t FunctionalMode;                                                                                                                          
                                                                                                              
                                                                                                                                                            

                                                                                                                                                 

  uint32_t InputNonInverting;                                                         
                                                                                                                 

                                                                                                                                                    

  uint32_t InputInverting;                                                        
                                                                                                              
                                                                                                                                                                                                                                                                                                     

                                                                                                                                                 

} LL_OPAMP_InitTypeDef;

   
      
    
#endif                         

                                                                                
                                                                  
      
    

                                                                    
      
    
#define LL_OPAMP_POWERSUPPLY_RANGE_LOW   0x00000000U                                                                                    
#define LL_OPAMP_POWERSUPPLY_RANGE_HIGH (OPAMP1_CSR_OPARANGE)                                                                             
   
      
    

                                                    
      
    
#define LL_OPAMP_POWERMODE_NORMALPOWER  (OPAMP_POWERMODE_OTR_REGOFFSET)                                                     
#define LL_OPAMP_POWERMODE_LOWPOWER     (OPAMP_POWERMODE_LPOTR_REGOFFSET | OPAMP_CSR_OPALPM)                                   

#define LL_OPAMP_POWERMODE_NORMAL       LL_OPAMP_POWERMODE_NORMALPOWER                                                                                     

   
      
    

                                                                    
      
    
#define LL_OPAMP_MODE_FUNCTIONAL         0x00000000U                                                               
#define LL_OPAMP_MODE_CALIBRATION       (OPAMP_CSR_CALON)                                                         
   
      
    

                                                               
      
    
#define LL_OPAMP_MODE_STANDALONE        0x00000000U                                                                                             
#define LL_OPAMP_MODE_FOLLOWER          (OPAMP_CSR_OPAMODE_1 | OPAMP_CSR_OPAMODE_0)                                                           
#define LL_OPAMP_MODE_PGA               (OPAMP_CSR_OPAMODE_1)                                                                            
   
      
    

                                                                                                      
      
    
#define LL_OPAMP_PGA_GAIN_2             0x00000000U                                                        
#define LL_OPAMP_PGA_GAIN_4             (OPAMP_CSR_PGGAIN_0)                                               
#define LL_OPAMP_PGA_GAIN_8             (OPAMP_CSR_PGGAIN_1)                                               
#define LL_OPAMP_PGA_GAIN_16            (OPAMP_CSR_PGGAIN_1 | OPAMP_CSR_PGGAIN_0 )                          
   
      
    

                                                                      
      
    
#define LL_OPAMP_INPUT_NONINVERT_IO0       0x00000000U                                                                                                             
#define LL_OPAMP_INPUT_NONINV_DAC1_CH1    (OPAMP1_CSR_VPSEL)                                                                         
   
      
    

                                                               
      
    
#define LL_OPAMP_INPUT_INVERT_IO0        0x00000000U                                                                                                                                                                                                                                                                                                                                    
#define LL_OPAMP_INPUT_INVERT_IO1        (OPAMP_CSR_VMSEL_0)                                                                                                                                                                                                                                                                                                                                            
#define LL_OPAMP_INPUT_INVERT_CONNECT_NO (OPAMP_CSR_VMSEL_1)                                                                                                                                                  
   
      
    

                                                                        
      
    
#define LL_OPAMP_NONINVERTINGINPUT_IO0      LL_OPAMP_INPUT_NONINVERT_IO0
#define LL_OPAMP_NONINVERTINGINPUT_DAC_CH   LL_OPAMP_INPUT_NONINV_DAC1_CH1

#define LL_OPAMP_INVERTINGINPUT_IO0         LL_OPAMP_INPUT_INVERT_IO0
#define LL_OPAMP_INVERTINGINPUT_IO1         LL_OPAMP_INPUT_INVERT_IO1
#define LL_OPAMP_INVERTINGINPUT_CONNECT_NO  LL_OPAMP_INPUT_INVERT_CONNECT_NO

#define LL_OPAMP_INPUT_NONINVERT_DAC1_CH1   LL_OPAMP_INPUT_NONINV_DAC1_CH1
   
      
    

                                                           
      
    
#define LL_OPAMP_TRIMMING_FACTORY       0x00000000U                                                                 
#define LL_OPAMP_TRIMMING_USER          (OPAMP_CSR_USERTRIM)                                                     
   
      
    

                                                                                                                     
      
    
#define LL_OPAMP_TRIMMING_NMOS          (OPAMP_OTR_TRIMOFFSETN)                                                                                 
#define LL_OPAMP_TRIMMING_PMOS          (OPAMP_OTR_TRIMOFFSETP | OPAMP1_CSR_CALSEL)                                                             
   
      
    

                                                                                     
                                                                                  
                               
                                                                              
                                          
      
    

                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
#define LL_OPAMP_DELAY_STARTUP_US         ((uint32_t) 30U)                                      

   
      
    

   
      
    

                                                                                
                                                            
      
    
                                                                          
      
    
   
                                           
                                       
                                          
                                                         
                
    
#define LL_OPAMP_WriteReg(__INSTANCE__, __REG__, __VALUE__) WRITE_REG((__INSTANCE__)->__REG__, (__VALUE__))

   
                                          
                                       
                                       
                          
    
#define LL_OPAMP_ReadReg(__INSTANCE__, __REG__) READ_REG((__INSTANCE__)->__REG__)
   
      
    

                                                         
      
    

   
                                                            
                                                              
                                                         
                                                             
                                                                             
                                     
                                 
    
#if defined(OPAMP1) && defined(OPAMP2)
#define __LL_OPAMP_COMMON_INSTANCE(__OPAMPx__)                                 \
  (OPAMP12_COMMON)
#else
#define __LL_OPAMP_COMMON_INSTANCE(__OPAMPx__)                                 \
  (OPAMP1_COMMON)
#endif

   
                                                                         
                                               
                                                                           
                        
                                                                           
                                                                             
                                                                         
                            
                                                                                 
                         
    
#if defined(OPAMP1) && defined(OPAMP2)
#define __LL_OPAMP_IS_ENABLED_ALL_COMMON_INSTANCE()                            \
  (LL_OPAMP_IsEnabled(OPAMP1) |                                                \
   LL_OPAMP_IsEnabled(OPAMP2)  )
#else
#define __LL_OPAMP_IS_ENABLED_ALL_COMMON_INSTANCE()                            \
  (LL_OPAMP_IsEnabled(OPAMP1))
#endif

   
      
    

   
      
    

                                                                                
                                                                  
      
    

                                                                                                                                 
      
    

   
                                  
                                                                    
                                                                          
                                                                           
                        
                                                                           
                                                                                   
                                                   
                                                             
                                                                
                                                
                                                                                                                   
                                                                         
                                                    
                                                     
                
    
__STATIC_INLINE void LL_OPAMP_SetCommonPowerRange(OPAMP_Common_TypeDef *OPAMPxy_COMMON, uint32_t PowerRange)
{
                                        
  (void)(*OPAMPxy_COMMON);
  
  MODIFY_REG(OPAMP1->CSR, OPAMP1_CSR_OPARANGE, PowerRange);
}

   
                                  
                                                                    
                                                                          
                                                                
                                                
                                                                                                                   
                                                              
                                                    
                                                     
    
__STATIC_INLINE uint32_t LL_OPAMP_GetCommonPowerRange(OPAMP_Common_TypeDef *OPAMPxy_COMMON)
{
                                        
  (void)(*OPAMPxy_COMMON);
  
  return (uint32_t)(READ_BIT(OPAMP1->CSR, OPAMP1_CSR_OPARANGE));
}

   
      
    

                                                                                                                
      
    

   
                                 
                                                                    
                                                         
                                 
                                                                        
                                                    
                                                 
                
    
__STATIC_INLINE void LL_OPAMP_SetPowerMode(OPAMP_TypeDef *OPAMPx, uint32_t PowerMode)
{
  MODIFY_REG(OPAMPx->CSR, OPAMP_CSR_OPALPM, (PowerMode & OPAMP_POWERMODE_CSR_BIT_MASK));
}

   
                                 
                                                         
                                 
                                                              
                                                    
                                                 
    
__STATIC_INLINE uint32_t LL_OPAMP_GetPowerMode(OPAMP_TypeDef *OPAMPx)
{
  uint32_t power_mode = (READ_BIT(OPAMPx->CSR, OPAMP_CSR_OPALPM));

  return (uint32_t)(power_mode | (power_mode >> (OPAMP_CSR_OPALPM_Pos)));
}

   
                                                     
                                                                     
                                                                            
                                                 
                                                 
                                                                   
                                                          
                                                                      
                                                           
                                                               
                         
                                                                
                                                    
                                 
                                                                   
                                              
                                               
                
    
__STATIC_INLINE void LL_OPAMP_SetMode(OPAMP_TypeDef *OPAMPx, uint32_t Mode)
{
  MODIFY_REG(OPAMPx->CSR, OPAMP_CSR_CALON, Mode);
}

   
                                                     
                                                                     
                                                                            
                                                 
                                                 
                                                                   
                                                          
                                                    
                                 
                                                              
                                              
                                               
    
__STATIC_INLINE uint32_t LL_OPAMP_GetMode(OPAMP_TypeDef *OPAMPx)
{
  return (uint32_t)(READ_BIT(OPAMPx->CSR, OPAMP_CSR_CALON));
}

   
                                                                      
                                                        
                                                                 
                                                                       
                                                                         
                            
                                                              
                                 
                                                                             
                                              
                                            
                                       
                
    
__STATIC_INLINE void LL_OPAMP_SetFunctionalMode(OPAMP_TypeDef *OPAMPx, uint32_t FunctionalMode)
{
                                                                          
  MODIFY_REG(OPAMPx->CSR, OPAMP_CSR_OPAMODE | OPAMP_CSR_CALON, FunctionalMode);
}

   
                                                                           
                                                        
                                                              
                                 
                                                              
                                              
                                            
                                       
    
__STATIC_INLINE uint32_t LL_OPAMP_GetFunctionalMode(OPAMP_TypeDef *OPAMPx)
{
  return (uint32_t)(READ_BIT(OPAMPx->CSR, OPAMP_CSR_OPAMODE));
}

   
                               
                                                        
                                                             
                                                       
                                 
                                                                      
                                         
                                         
                                         
                                          
                
    
__STATIC_INLINE void LL_OPAMP_SetPGAGain(OPAMP_TypeDef *OPAMPx, uint32_t PGAGain)
{
  MODIFY_REG(OPAMPx->CSR, OPAMP_CSR_PGGAIN, PGAGain);
}

   
                               
                                                        
                                                             
                                                       
                                 
                                                              
                                         
                                         
                                         
                                          
    
__STATIC_INLINE uint32_t LL_OPAMP_GetPGAGain(OPAMP_TypeDef *OPAMPx)
{
  return (uint32_t)(READ_BIT(OPAMPx->CSR, OPAMP_CSR_PGGAIN));
}

   
      
    

                                                                            
      
    

   
                                                     
                                                                 
                                 
                                                                                
                                                  
                                                    
                
    
__STATIC_INLINE void LL_OPAMP_SetInputNonInverting(OPAMP_TypeDef *OPAMPx, uint32_t InputNonInverting)
{
  MODIFY_REG(OPAMPx->CSR, OPAMP_CSR_VPSEL, InputNonInverting);
}

   
                                                     
                                                                 
                                 
                                                              
                                                  
                                                    
    
__STATIC_INLINE uint32_t LL_OPAMP_GetInputNonInverting(OPAMP_TypeDef *OPAMPx)
{
  return (uint32_t)(READ_BIT(OPAMPx->CSR, OPAMP_CSR_VPSEL));
}

   
                                                 
                                                                       
                                                                  
                                                                     
                                                    
                                                              
                                 
                                                                             
                                               
                                               
                                                      
                
    
__STATIC_INLINE void LL_OPAMP_SetInputInverting(OPAMP_TypeDef *OPAMPx, uint32_t InputInverting)
{
  MODIFY_REG(OPAMPx->CSR, OPAMP_CSR_VMSEL, InputInverting);
}

   
                                                 
                                                              
                                 
                                                              
                                               
                                               
                                                      
    
__STATIC_INLINE uint32_t LL_OPAMP_GetInputInverting(OPAMP_TypeDef *OPAMPx)
{
  return (uint32_t)(READ_BIT(OPAMPx->CSR, OPAMP_CSR_VMSEL));
}

   
      
    

                                                                                                      
      
    
                                                                                
                                                                                
__STATIC_INLINE void LL_OPAMP_SetNonInvertingInput(OPAMP_TypeDef *OPAMPx, uint32_t NonInvertingInput)
{
  LL_OPAMP_SetInputNonInverting(OPAMPx, NonInvertingInput);
}

__STATIC_INLINE void LL_OPAMP_SetInvertingInput(OPAMP_TypeDef *OPAMPx, uint32_t InvertingInput)
{
  LL_OPAMP_SetInputInverting(OPAMPx, InvertingInput);
}

   
      
    

                                                                                      
      
    

   
                                    
                                                            
                                 
                                                                           
                                               
                                            
                
    
__STATIC_INLINE void LL_OPAMP_SetTrimmingMode(OPAMP_TypeDef *OPAMPx, uint32_t TrimmingMode)
{
  MODIFY_REG(OPAMPx->CSR, OPAMP_CSR_USERTRIM, TrimmingMode);
}

   
                                    
                                                            
                                 
                                                              
                                               
                                            
    
__STATIC_INLINE uint32_t LL_OPAMP_GetTrimmingMode(OPAMP_TypeDef *OPAMPx)
{
  return (uint32_t)(READ_BIT(OPAMPx->CSR, OPAMP_CSR_USERTRIM));
}

   
                                                                  
                                           
                                                                
                                                   
                                                                    
                                 
                                                                                  
                                            
                                            
                
    
__STATIC_INLINE void LL_OPAMP_SetCalibrationSelection(OPAMP_TypeDef *OPAMPx, uint32_t TransistorsDiffPair)
{
                                                                                
                                                                                
  MODIFY_REG(OPAMPx->CSR, OPAMP_CSR_CALSEL, (TransistorsDiffPair & OPAMP_TRIMMING_SELECT_MASK));
}

   
                                                                  
                                           
                                                                
                                                   
                                                                    
                                 
                                                              
                                            
                                            
    
__STATIC_INLINE uint32_t LL_OPAMP_GetCalibrationSelection(OPAMP_TypeDef *OPAMPx)
{
  uint32_t CalibrationSelection = (uint32_t)(READ_BIT(OPAMPx->CSR, OPAMP_CSR_CALSEL));

  return (CalibrationSelection |
          (((CalibrationSelection & OPAMP_CSR_CALSEL) == 0UL) ? OPAMP_OTR_TRIMOFFSETN : OPAMP_OTR_TRIMOFFSETP));
}

   
                                                            
                                   
                                                  
                                                
                                                                   
                                 
                                  
    
__STATIC_INLINE uint32_t LL_OPAMP_IsCalibrationOutputSet(OPAMP_TypeDef *OPAMPx)
{
  return ((READ_BIT(OPAMPx->CSR, OPAMP_CSR_CALOUT) == OPAMP_CSR_CALOUT) ? 1UL : 0UL);
}

   
                                                                  
                                                                         
                       
                                                               
                                                               
                                                               
                                                             
                                 
                                                                        
                                                    
                                                 
                                                                                  
                                            
                                            
                                     
                
    
__STATIC_INLINE void LL_OPAMP_SetTrimmingValue(OPAMP_TypeDef* OPAMPx, uint32_t PowerMode, uint32_t TransistorsDiffPair, uint32_t TrimmingValue)
{
  __IO uint32_t *preg = __OPAMP_PTR_REG_OFFSET(OPAMPx->OTR, (PowerMode & OPAMP_POWERMODE_OTR_REGOFFSET_MASK));

                                                                                
                                                                                
                                                                                
                                                                                
  MODIFY_REG(*preg,
           (TransistorsDiffPair & OPAMP_TRIMMING_VALUE_MASK),
             TrimmingValue << ((TransistorsDiffPair == LL_OPAMP_TRIMMING_NMOS) ? OPAMP_OTR_TRIMOFFSETN_Pos : OPAMP_OTR_TRIMOFFSETP_Pos));
}

   
                                                                  
                                                                         
                       
                                                               
                                                               
                                                               
                                                             
                                 
                                                                        
                                                    
                                                 
                                                                                  
                                            
                                            
                      
    
__STATIC_INLINE uint32_t LL_OPAMP_GetTrimmingValue(OPAMP_TypeDef* OPAMPx, uint32_t PowerMode, uint32_t TransistorsDiffPair)
{
  const __IO uint32_t *preg = __OPAMP_PTR_REG_OFFSET(OPAMPx->OTR, (PowerMode & OPAMP_POWERMODE_OTR_REGOFFSET_MASK));

                                                                                
                                                                                
                                                                                
                                                                                
  return (uint32_t)(READ_BIT(*preg, (TransistorsDiffPair & OPAMP_TRIMMING_VALUE_MASK))
                    >> ((TransistorsDiffPair == LL_OPAMP_TRIMMING_NMOS) ? OPAMP_OTR_TRIMOFFSETN_Pos : OPAMP_OTR_TRIMOFFSETP_Pos));
}

   
      
    

                                                               
      
    
   
                                  
                                                               
                                                  
                                                           
                                                   
                                 
                
    
__STATIC_INLINE void LL_OPAMP_Enable(OPAMP_TypeDef *OPAMPx)
{
  SET_BIT(OPAMPx->CSR, OPAMP_CSR_OPAMPxEN);
}

   
                                   
                                                    
                                 
                
    
__STATIC_INLINE void LL_OPAMP_Disable(OPAMP_TypeDef *OPAMPx)
{
  CLEAR_BIT(OPAMPx->CSR, OPAMP_CSR_OPAMPxEN);
}

   
                                           
                                                       
                                                      
                                 
                                  
    
__STATIC_INLINE uint32_t LL_OPAMP_IsEnabled(OPAMP_TypeDef *OPAMPx)
{
  return ((READ_BIT(OPAMPx->CSR, OPAMP_CSR_OPAMPxEN) == (OPAMP_CSR_OPAMPxEN)) ? 1UL : 0UL);
}

   
      
    

#if defined(USE_FULL_LL_DRIVER)
                                                                             
      
    

ErrorStatus LL_OPAMP_DeInit(OPAMP_TypeDef *OPAMPx);
ErrorStatus LL_OPAMP_Init(OPAMP_TypeDef *OPAMPx, LL_OPAMP_InitTypeDef *OPAMP_InitStruct);
void        LL_OPAMP_StructInit(LL_OPAMP_InitTypeDef *OPAMP_InitStruct);

   
      
    
#endif                         

   
      
    

   
      
    

#endif                       

   
      
    

#ifdef __cplusplus
}
#endif

#endif                           
