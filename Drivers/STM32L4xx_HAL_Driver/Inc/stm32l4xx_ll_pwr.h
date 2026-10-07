/**
  ******************************************************************************
  * @file    stm32l4xx_ll_pwr.h
  * @author  MCD Application Team
  * @brief   Header file of PWR LL module.
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

                                                                                
#ifndef STM32L4xx_LL_PWR_H
#define STM32L4xx_LL_PWR_H

#ifdef __cplusplus
extern "C" {
#endif

                                                                                
#include "stm32l4xx.h"

                                   
      
    

#if defined(PWR)

                        
      
    

                                                                                
                                                                                

                                                                                

                                                                                

                                                                                
                                                                                
                                                              
      
    

                                                      
                                                                           
      
    
#define LL_PWR_SCR_CSBF                    PWR_SCR_CSBF
#define LL_PWR_SCR_CWUF                    PWR_SCR_CWUF
#define LL_PWR_SCR_CWUF5                   PWR_SCR_CWUF5
#define LL_PWR_SCR_CWUF4                   PWR_SCR_CWUF4
#define LL_PWR_SCR_CWUF3                   PWR_SCR_CWUF3
#define LL_PWR_SCR_CWUF2                   PWR_SCR_CWUF2
#define LL_PWR_SCR_CWUF1                   PWR_SCR_CWUF1
   
      
    

                                                  
                                                                          
      
    
#define LL_PWR_SR1_WUFI                    PWR_SR1_WUFI
#if defined(PWR_SR1_EXT_SMPS_RDY)
#define LL_PWR_SR1_EXT_SMPS_RDY            PWR_SR1_EXT_SMPS_RDY
#endif                           
#define LL_PWR_SR1_SBF                     PWR_SR1_SBF
#define LL_PWR_SR1_WUF5                    PWR_SR1_WUF5
#define LL_PWR_SR1_WUF4                    PWR_SR1_WUF4
#define LL_PWR_SR1_WUF3                    PWR_SR1_WUF3
#define LL_PWR_SR1_WUF2                    PWR_SR1_WUF2
#define LL_PWR_SR1_WUF1                    PWR_SR1_WUF1
#if defined(PWR_SR2_PVMO4)
#define LL_PWR_SR2_PVMO4                   PWR_SR2_PVMO4
#endif                    
#if defined(PWR_SR2_PVMO3)
#define LL_PWR_SR2_PVMO3                   PWR_SR2_PVMO3
#endif                    
#if defined(PWR_SR2_PVMO2)
#define LL_PWR_SR2_PVMO2                   PWR_SR2_PVMO2
#endif                    
#if defined(PWR_SR2_PVMO1)
#define LL_PWR_SR2_PVMO1                   PWR_SR2_PVMO1
#endif                    
#define LL_PWR_SR2_PVDO                    PWR_SR2_PVDO
#define LL_PWR_SR2_VOSF                    PWR_SR2_VOSF
#define LL_PWR_SR2_REGLPF                  PWR_SR2_REGLPF
#define LL_PWR_SR2_REGLPS                  PWR_SR2_REGLPS
   
      
    

                                                 
      
    
#define LL_PWR_REGU_VOLTAGE_SCALE1         (PWR_CR1_VOS_0)
#define LL_PWR_REGU_VOLTAGE_SCALE2         (PWR_CR1_VOS_1)
   
      
    

                                         
      
    
#define LL_PWR_MODE_STOP0                  (PWR_CR1_LPMS_STOP0)
#define LL_PWR_MODE_STOP1                  (PWR_CR1_LPMS_STOP1)
#define LL_PWR_MODE_STOP2                  (PWR_CR1_LPMS_STOP2)
#define LL_PWR_MODE_STANDBY                (PWR_CR1_LPMS_STANDBY)
#define LL_PWR_MODE_SHUTDOWN               (PWR_CR1_LPMS_SHUTDOWN)
   
      
    

                                                                  
      
    
#if defined(PWR_CR2_PVME1)
#define LL_PWR_PVM_VDDUSB_1_2V             (PWR_CR2_PVME1)                                     
#endif
#if defined(PWR_CR2_PVME2)
#define LL_PWR_PVM_VDDIO2_0_9V             (PWR_CR2_PVME2)                                     
#endif
#if defined(PWR_CR2_PVME3)
#define LL_PWR_PVM_VDDA_1_62V              (PWR_CR2_PVME3)                                     
#endif
#if defined(PWR_CR2_PVME4)
#define LL_PWR_PVM_VDDA_2_2V               (PWR_CR2_PVME4)                                     
#endif
   
      
    

                                         
      
    
#define LL_PWR_PVDLEVEL_0                  (PWR_CR2_PLS_LEV0)                          
#define LL_PWR_PVDLEVEL_1                  (PWR_CR2_PLS_LEV1)                          
#define LL_PWR_PVDLEVEL_2                  (PWR_CR2_PLS_LEV2)                          
#define LL_PWR_PVDLEVEL_3                  (PWR_CR2_PLS_LEV3)                          
#define LL_PWR_PVDLEVEL_4                  (PWR_CR2_PLS_LEV4)                          
#define LL_PWR_PVDLEVEL_5                  (PWR_CR2_PLS_LEV5)                          
#define LL_PWR_PVDLEVEL_6                  (PWR_CR2_PLS_LEV6)                          
#define LL_PWR_PVDLEVEL_7                  (PWR_CR2_PLS_LEV7)                                                                       
   
      
    

                                     
      
    
#define LL_PWR_WAKEUP_PIN1                 (PWR_CR3_EWUP1)
#define LL_PWR_WAKEUP_PIN2                 (PWR_CR3_EWUP2)
#define LL_PWR_WAKEUP_PIN3                 (PWR_CR3_EWUP3)
#define LL_PWR_WAKEUP_PIN4                 (PWR_CR3_EWUP4)
#define LL_PWR_WAKEUP_PIN5                 (PWR_CR3_EWUP5)
   
      
    

                                                               
      
    
#define LL_PWR_BATT_CHARG_RESISTOR_5K      (0x00000000U)
#define LL_PWR_BATT_CHARGRESISTOR_1_5K     (PWR_CR4_VBRS)
   
      
    

                                                                       
      
    
#define LL_PWR_NO_SRAM2_RETENTION        (0x00000000U)
#if defined(PWR_CR3_RRS_1)
#define LL_PWR_FULL_SRAM2_RETENTION      PWR_CR3_RRS_0
#define LL_PWR_4KBYTES_SRAM2_RETENTION   PWR_CR3_RRS_1
#else
#define LL_PWR_FULL_SRAM2_RETENTION      PWR_CR3_RRS
#endif                    
   
      
    

                                 
      
    
#define LL_PWR_GPIO_A                      ((uint32_t)(&(PWR->PUCRA)))
#define LL_PWR_GPIO_B                      ((uint32_t)(&(PWR->PUCRB)))
#define LL_PWR_GPIO_C                      ((uint32_t)(&(PWR->PUCRC)))
#define LL_PWR_GPIO_D                      ((uint32_t)(&(PWR->PUCRD)))
#define LL_PWR_GPIO_E                      ((uint32_t)(&(PWR->PUCRE)))
#if defined(GPIOF)
#define LL_PWR_GPIO_F                      ((uint32_t)(&(PWR->PUCRF)))
#endif
#if defined(GPIOG)
#define LL_PWR_GPIO_G                      ((uint32_t)(&(PWR->PUCRG)))
#endif
#if defined(GPIOH)
#define LL_PWR_GPIO_H                      ((uint32_t)(&(PWR->PUCRH)))
#endif
#if defined(GPIOI)
#define LL_PWR_GPIO_I                      ((uint32_t)(&(PWR->PUCRI)))
#endif
   
      
    

                                         
      
    
#define LL_PWR_GPIO_BIT_0                  (0x00000001U)
#define LL_PWR_GPIO_BIT_1                  (0x00000002U)
#define LL_PWR_GPIO_BIT_2                  (0x00000004U)
#define LL_PWR_GPIO_BIT_3                  (0x00000008U)
#define LL_PWR_GPIO_BIT_4                  (0x00000010U)
#define LL_PWR_GPIO_BIT_5                  (0x00000020U)
#define LL_PWR_GPIO_BIT_6                  (0x00000040U)
#define LL_PWR_GPIO_BIT_7                  (0x00000080U)
#define LL_PWR_GPIO_BIT_8                  (0x00000100U)
#define LL_PWR_GPIO_BIT_9                  (0x00000200U)
#define LL_PWR_GPIO_BIT_10                 (0x00000400U)
#define LL_PWR_GPIO_BIT_11                 (0x00000800U)
#define LL_PWR_GPIO_BIT_12                 (0x00001000U)
#define LL_PWR_GPIO_BIT_13                 (0x00002000U)
#define LL_PWR_GPIO_BIT_14                 (0x00004000U)
#define LL_PWR_GPIO_BIT_15                 (0x00008000U)
   
      
    

   
      
    

                                                                                
                                                        
      
    

                                                                         
      
    

   
                                         
                                          
                                                         
                
    
#define LL_PWR_WriteReg(__REG__, __VALUE__) WRITE_REG(PWR->__REG__, (__VALUE__))

   
                                        
                                       
                          
    
#define LL_PWR_ReadReg(__REG__) READ_REG(PWR->__REG__)
   
      
    

   
      
    


                                                                                
                                                              
      
    

                                                   
      
    

   
                                                                 
                                                                   
                
    
__STATIC_INLINE void LL_PWR_EnableLowPowerRunMode(void)
{
  SET_BIT(PWR->CR1, PWR_CR1_LPR);
}

   
                                                                 
                                                                    
                
    
__STATIC_INLINE void LL_PWR_DisableLowPowerRunMode(void)
{
  CLEAR_BIT(PWR->CR1, PWR_CR1_LPR);
}

   
                                                            
                                                                  
                
    
__STATIC_INLINE void LL_PWR_EnterLowPowerRunMode(void)
{
  LL_PWR_EnableLowPowerRunMode();
}

   
                                                        
                                                                 
                
    
__STATIC_INLINE void LL_PWR_ExitLowPowerRunMode(void)
{
  LL_PWR_DisableLowPowerRunMode();
}

   
                                                       
                                                                      
                                  
    
__STATIC_INLINE uint32_t LL_PWR_IsEnabledLowPowerRunMode(void)
{
  return ((READ_BIT(PWR->CR1, PWR_CR1_LPR) == (PWR_CR1_LPR)) ? 1UL : 0UL);
}

   
                                                          
                                                                                                                   
                                                                    
                                                                             
                                                
                                                
                
    
__STATIC_INLINE void LL_PWR_SetRegulVoltageScaling(uint32_t VoltageScaling)
{
  MODIFY_REG(PWR->CR1, PWR_CR1_VOS, VoltageScaling);
}

   
                                                          
                                                                    
                                                              
                                                
                                                
    
__STATIC_INLINE uint32_t LL_PWR_GetRegulVoltageScaling(void)
{
  return (uint32_t)(READ_BIT(PWR->CR1, PWR_CR1_VOS));
}

#if defined(PWR_CR5_R1MODE)
   
                                                            
                                                                   
                
    
__STATIC_INLINE void LL_PWR_EnableRange1BoostMode(void)
{
  CLEAR_BIT(PWR->CR5, PWR_CR5_R1MODE);
}

   
                                                             
                                                                    
                
    
__STATIC_INLINE void LL_PWR_DisableRange1BoostMode(void)
{
  SET_BIT(PWR->CR5, PWR_CR5_R1MODE);
}

   
                                                                             
                                                                      
                                           
    
__STATIC_INLINE uint32_t LL_PWR_IsEnabledRange1BoostMode(void)
{
  return ((READ_BIT(PWR->CR5, PWR_CR5_R1MODE) == 0x0U) ? 1UL : 0UL);
}
#endif                     

   
                                              
                                                              
                
    
__STATIC_INLINE void LL_PWR_EnableBkUpAccess(void)
{
  SET_BIT(PWR->CR1, PWR_CR1_DBP);
}

   
                                               
                                                               
                
    
__STATIC_INLINE void LL_PWR_DisableBkUpAccess(void)
{
  CLEAR_BIT(PWR->CR1, PWR_CR1_DBP);
}

   
                                                 
                                                                 
                                  
    
__STATIC_INLINE uint32_t LL_PWR_IsEnabledBkUpAccess(void)
{
  return ((READ_BIT(PWR->CR1, PWR_CR1_DBP) == (PWR_CR1_DBP)) ? 1UL : 0UL);
}

   
                              
                                                          
                                                                           
                                       
                                       
                                       
                                         
                                          
                
    
__STATIC_INLINE void LL_PWR_SetPowerMode(uint32_t LowPowerMode)
{
  MODIFY_REG(PWR->CR1, PWR_CR1_LPMS, LowPowerMode);
}

   
                              
                                                          
                                                              
                                       
                                       
                                       
                                         
                                          
    
__STATIC_INLINE uint32_t LL_PWR_GetPowerMode(void)
{
  return (uint32_t)(READ_BIT(PWR->CR1, PWR_CR1_LPMS));
}

#if defined(PWR_CR1_RRSTP)
   
                                                       
                                                                    
                
    
__STATIC_INLINE void LL_PWR_EnableSRAM3Retention(void)
{
  SET_BIT(PWR->CR1, PWR_CR1_RRSTP);
}

   
                                                        
                                                                     
                
    
__STATIC_INLINE void LL_PWR_DisableSRAM3Retention(void)
{
  CLEAR_BIT(PWR->CR1, PWR_CR1_RRSTP);
}

   
                                                                    
                                                                       
                                  
    
__STATIC_INLINE uint32_t LL_PWR_IsEnabledSRAM3Retention(void)
{
  return ((READ_BIT(PWR->CR1, PWR_CR1_RRSTP) == (PWR_CR1_RRSTP)) ? 1UL : 0UL);
}
#endif                    

#if defined(PWR_CR3_DSIPDEN)
   
                                                   
                                                                           
                
    
__STATIC_INLINE void LL_PWR_EnableDSIPinsPDActivation(void)
{
  SET_BIT(PWR->CR3, PWR_CR3_DSIPDEN);
}

   
                                                    
                                                                            
                
    
__STATIC_INLINE void LL_PWR_DisableDSIPinsPDActivation(void)
{
  CLEAR_BIT(PWR->CR3, PWR_CR3_DSIPDEN);
}

   
                                                                
                                                                              
                                  
    
__STATIC_INLINE uint32_t LL_PWR_IsEnabledDSIPinsPDActivation(void)
{
  return ((READ_BIT(PWR->CR3, PWR_CR3_DSIPDEN) == (PWR_CR3_DSIPDEN)) ? 1UL : 0UL);
}
#endif                      

#if defined(PWR_CR2_USV)
   
                                
                                                          
                
    
__STATIC_INLINE void LL_PWR_EnableVddUSB(void)
{
  SET_BIT(PWR->CR2, PWR_CR2_USV);
}

   
                                 
                                                           
                
    
__STATIC_INLINE void LL_PWR_DisableVddUSB(void)
{
  CLEAR_BIT(PWR->CR2, PWR_CR2_USV);
}

   
                                             
                                                             
                                  
    
__STATIC_INLINE uint32_t LL_PWR_IsEnabledVddUSB(void)
{
  return ((READ_BIT(PWR->CR2, PWR_CR2_USV) == (PWR_CR2_USV)) ? 1UL : 0UL);
}
#endif

#if defined(PWR_CR2_IOSV)
   
                                
                                                          
                
    
__STATIC_INLINE void LL_PWR_EnableVddIO2(void)
{
  SET_BIT(PWR->CR2, PWR_CR2_IOSV);
}

   
                                 
                                                           
                
    
__STATIC_INLINE void LL_PWR_DisableVddIO2(void)
{
  CLEAR_BIT(PWR->CR2, PWR_CR2_IOSV);
}

   
                                             
                                                             
                                  
    
__STATIC_INLINE uint32_t LL_PWR_IsEnabledVddIO2(void)
{
  return ((READ_BIT(PWR->CR2, PWR_CR2_IOSV) == (PWR_CR2_IOSV)) ? 1UL : 0UL);
}
#endif

   
                                                               
                                                         
                                                         
                                                         
                                                       
                                                                            
                                                
                                                
                                           
                                          
   
                                                
                
    
__STATIC_INLINE void LL_PWR_EnablePVM(uint32_t PeriphVoltage)
{
  SET_BIT(PWR->CR2, PeriphVoltage);
}

   
                                                                
                                                          
                                                          
                                                          
                                                        
                                                                            
                                                
                                                
                                           
                                          
   
                                                
                
    
__STATIC_INLINE void LL_PWR_DisablePVM(uint32_t PeriphVoltage)
{
  CLEAR_BIT(PWR->CR2, PeriphVoltage);
}

   
                                                                        
                                                            
                                                            
                                                            
                                                          
                                                                            
                                                
                                                
                                           
                                          
   
                                                
                                  
    
__STATIC_INLINE uint32_t LL_PWR_IsEnabledPVM(uint32_t PeriphVoltage)
{
  return ((READ_BIT(PWR->CR2, PeriphVoltage) == (PeriphVoltage)) ? 1UL : 0UL);
}

   
                                                                                  
                                                         
                                                                       
                                       
                                       
                                       
                                       
                                       
                                       
                                       
                                       
                
    
__STATIC_INLINE void LL_PWR_SetPVDLevel(uint32_t PVDLevel)
{
  MODIFY_REG(PWR->CR2, PWR_CR2_PLS, PVDLevel);
}

   
                                               
                                                         
                                                              
                                       
                                       
                                       
                                       
                                       
                                       
                                       
                                       
    
__STATIC_INLINE uint32_t LL_PWR_GetPVDLevel(void)
{
  return (uint32_t)(READ_BIT(PWR->CR2, PWR_CR2_PLS));
}

   
                                         
                                                       
                
    
__STATIC_INLINE void LL_PWR_EnablePVD(void)
{
  SET_BIT(PWR->CR2, PWR_CR2_PVDE);
}

   
                                          
                                                        
                
    
__STATIC_INLINE void LL_PWR_DisablePVD(void)
{
  CLEAR_BIT(PWR->CR2, PWR_CR2_PVDE);
}

   
                                                      
                                                          
                                  
    
__STATIC_INLINE uint32_t LL_PWR_IsEnabledPVD(void)
{
  return ((READ_BIT(PWR->CR2, PWR_CR2_PVDE) == (PWR_CR2_PVDE)) ? 1UL : 0UL);
}

   
                                        
                                                            
                
    
__STATIC_INLINE void LL_PWR_EnableInternWU(void)
{
  SET_BIT(PWR->CR3, PWR_CR3_EIWF);
}

   
                                         
                                                             
                
    
__STATIC_INLINE void LL_PWR_DisableInternWU(void)
{
  CLEAR_BIT(PWR->CR3, PWR_CR3_EIWF);
}

   
                                                     
                                                               
                                  
    
__STATIC_INLINE uint32_t LL_PWR_IsEnabledInternWU(void)
{
  return ((READ_BIT(PWR->CR3, PWR_CR3_EIWF) == (PWR_CR3_EIWF)) ? 1UL : 0UL);
}

   
                                                      
                                                           
                
    
__STATIC_INLINE void LL_PWR_EnablePUPDCfg(void)
{
  SET_BIT(PWR->CR3, PWR_CR3_APC);
}

   
                                                       
                                                            
                
    
__STATIC_INLINE void LL_PWR_DisablePUPDCfg(void)
{
  CLEAR_BIT(PWR->CR3, PWR_CR3_APC);
}

   
                                                                   
                                                              
                                  
    
__STATIC_INLINE uint32_t LL_PWR_IsEnabledPUPDCfg(void)
{
  return ((READ_BIT(PWR->CR3, PWR_CR3_APC) == (PWR_CR3_APC)) ? 1UL : 0UL);
}

#if defined(PWR_CR3_DSIPDEN)
   
                                                   
                                                               
                
    
__STATIC_INLINE void LL_PWR_EnableDSIPullDown(void)
{
  SET_BIT(PWR->CR3, PWR_CR3_DSIPDEN);
}

   
                                                    
                                                                
                
    
__STATIC_INLINE void LL_PWR_DisableDSIPullDown(void)
{
  CLEAR_BIT(PWR->CR3, PWR_CR3_DSIPDEN);
}

   
                                                                
                                                                  
                                  
    
__STATIC_INLINE uint32_t LL_PWR_IsEnabledDSIPullDown(void)
{
  return ((READ_BIT(PWR->CR3, PWR_CR3_DSIPDEN) == (PWR_CR3_DSIPDEN)) ? 1UL : 0UL);
}
#endif                      

#if defined(PWR_CR3_ENULP)
   
                                                                                 
                                                             
                
    
__STATIC_INLINE void LL_PWR_EnableBORPVD_ULP(void)
{
  SET_BIT(PWR->CR3, PWR_CR3_ENULP);
}

   
                                                                                  
                                                              
                
    
__STATIC_INLINE void LL_PWR_DisableBORPVD_ULP(void)
{
  CLEAR_BIT(PWR->CR3, PWR_CR3_ENULP);
}

   
                                                                                              
                                                                
                                  
    
__STATIC_INLINE uint32_t LL_PWR_IsEnabledBORPVD_ULP(void)
{
  return ((READ_BIT(PWR->CR3, PWR_CR3_ENULP) == (PWR_CR3_ENULP)) ? 1UL : 0UL);
}
#endif                    

   
                                                               
                                                                  
                
    
__STATIC_INLINE void LL_PWR_EnableSRAM2Retention(void)
{
  MODIFY_REG(PWR->CR3, PWR_CR3_RRS, LL_PWR_FULL_SRAM2_RETENTION);
}

   
                                                           
                                                                   
                
    
__STATIC_INLINE void LL_PWR_DisableSRAM2Retention(void)
{
  CLEAR_BIT(PWR->CR3, PWR_CR3_RRS);
}

   
                                                                            
                                                                     
                                  
    
__STATIC_INLINE uint32_t LL_PWR_IsEnabledSRAM2Retention(void)
{
  return ((READ_BIT(PWR->CR3, PWR_CR3_RRS) == (LL_PWR_FULL_SRAM2_RETENTION)) ? 1UL : 0UL);
}

   
                                                       
                                                                     
                                                                        
                                               
                                                 
                                                    
                                                                                   
                                                                                              
                                                                                               
                
    
__STATIC_INLINE void LL_PWR_SetSRAM2ContentRetention(uint32_t SRAM2Size)
{
  MODIFY_REG(PWR->CR3, PWR_CR3_RRS, SRAM2Size);
}

   
                                                       
                                                                     
                                                              
                                               
                                                 
                                                    
                                                                                   
    
__STATIC_INLINE uint32_t LL_PWR_GetSRAM2ContentRetention(void)
{
  return (uint32_t)(READ_BIT(PWR->CR3, PWR_CR3_RRS));
}

   
                                                
                                                               
                                                               
                                                               
                                                               
                                                               
                                                                        
                                        
                                        
                                        
                                        
                                        
                
    
__STATIC_INLINE void LL_PWR_EnableWakeUpPin(uint32_t WakeUpPin)
{
  SET_BIT(PWR->CR3, WakeUpPin);
}

   
                                                 
                                                                
                                                                
                                                                
                                                                
                                                                
                                                                        
                                        
                                        
                                        
                                        
                                        
                
    
__STATIC_INLINE void LL_PWR_DisableWakeUpPin(uint32_t WakeUpPin)
{
  CLEAR_BIT(PWR->CR3, WakeUpPin);
}

   
                                                             
                                                                  
                                                                  
                                                                  
                                                                  
                                                                  
                                                                        
                                        
                                        
                                        
                                        
                                        
                                  
    
__STATIC_INLINE uint32_t LL_PWR_IsEnabledWakeUpPin(uint32_t WakeUpPin)
{
  return ((READ_BIT(PWR->CR3, WakeUpPin) == (WakeUpPin)) ? 1UL : 0UL);
}

#if defined(PWR_CR4_EXT_SMPS_ON)
   
                                           
                                                                                                
                                                  
                                                                
                
    
__STATIC_INLINE void LL_PWR_EnableExtSMPS_0V95(void)
{
  SET_BIT(PWR->CR4, PWR_CR4_EXT_SMPS_ON);
}

   
                                             
                                                                                                
                                                  
                                                                 
                
    
__STATIC_INLINE void LL_PWR_DisableExtSMPS_0V95(void)
{
  CLEAR_BIT(PWR->CR4, PWR_CR4_EXT_SMPS_ON);
}

   
                                             
                                                                                                
                                                  
                                                                   
                                  
    
__STATIC_INLINE uint32_t LL_PWR_IsEnabledExtSMPS_0V95(void)
{
  return ((READ_BIT(PWR->CR4, PWR_CR4_EXT_SMPS_ON) == (PWR_CR4_EXT_SMPS_ON)) ? 1UL : 0UL);
}
#endif                          

   
                                      
                                                                  
                                                                       
                                                   
                                                    
                
    
__STATIC_INLINE void LL_PWR_SetBattChargResistor(uint32_t Resistor)
{
  MODIFY_REG(PWR->CR4, PWR_CR4_VBRS, Resistor);
}

   
                                      
                                                                  
                                                              
                                                   
                                                    
    
__STATIC_INLINE uint32_t LL_PWR_GetBattChargResistor(void)
{
  return (uint32_t)(READ_BIT(PWR->CR4, PWR_CR4_VBRS));
}

   
                                   
                                                                   
                
    
__STATIC_INLINE void LL_PWR_EnableBatteryCharging(void)
{
  SET_BIT(PWR->CR4, PWR_CR4_VBE);
}

   
                                    
                                                                    
                
    
__STATIC_INLINE void LL_PWR_DisableBatteryCharging(void)
{
  CLEAR_BIT(PWR->CR4, PWR_CR4_VBE);
}

   
                                                
                                                                      
                                  
    
__STATIC_INLINE uint32_t LL_PWR_IsEnabledBatteryCharging(void)
{
  return ((READ_BIT(PWR->CR4, PWR_CR4_VBE) == (PWR_CR4_VBE)) ? 1UL : 0UL);
}

   
                                                                    
                                                                       
                                                                       
                                                                       
                                                                       
                                                                     
                                                                        
                                        
                                        
                                        
                                        
                                        
                
    
__STATIC_INLINE void LL_PWR_SetWakeUpPinPolarityLow(uint32_t WakeUpPin)
{
  SET_BIT(PWR->CR4, WakeUpPin);
}

   
                                                                     
                                                                        
                                                                        
                                                                        
                                                                        
                                                                      
                                                                        
                                        
                                        
                                        
                                        
                                        
                
    
__STATIC_INLINE void LL_PWR_SetWakeUpPinPolarityHigh(uint32_t WakeUpPin)
{
  CLEAR_BIT(PWR->CR4, WakeUpPin);
}

   
                                                                
                                                                      
                                                                      
                                                                      
                                                                      
                                                                    
                                                                        
                                        
                                        
                                        
                                        
                                        
                                  
    
__STATIC_INLINE uint32_t LL_PWR_IsWakeUpPinPolarityLow(uint32_t WakeUpPin)
{
  return ((READ_BIT(PWR->CR4, WakeUpPin) == (WakeUpPin)) ? 1UL : 0UL);
}

   
                                                                   
                                                                
                                                                
                                                                
                                                                
                                                                
                                                                
                                                                
                                                                
                                                              
                                                                   
                                   
                                   
                                   
                                   
                                   
                                       
                                       
                                   
                                       
   
                                                
                                                                         
                                       
                                       
                                       
                                       
                                       
                                       
                                       
                                       
                                       
                                       
                                        
                                        
                                        
                                        
                                        
                                        
                
    
__STATIC_INLINE void LL_PWR_EnableGPIOPullUp(uint32_t GPIO, uint32_t GPIONumber)
{
  SET_BIT(*((__IO uint32_t *)GPIO), GPIONumber);
}

   
                                                                    
                                                                 
                                                                 
                                                                 
                                                                 
                                                                 
                                                                 
                                                                 
                                                                 
                                                               
                                                                   
                                   
                                   
                                   
                                   
                                   
                                       
                                       
                                   
                                       
   
                                                
                                                                         
                                       
                                       
                                       
                                       
                                       
                                       
                                       
                                       
                                       
                                       
                                        
                                        
                                        
                                        
                                        
                                        
                
    
__STATIC_INLINE void LL_PWR_DisableGPIOPullUp(uint32_t GPIO, uint32_t GPIONumber)
{
  CLEAR_BIT(*((__IO uint32_t *)GPIO), GPIONumber);
}

   
                                                  
                                                                   
                                                                   
                                                                   
                                                                   
                                                                   
                                                                   
                                                                   
                                                                   
                                                                 
                                                                   
                                   
                                   
                                   
                                   
                                   
                                       
                                       
                                   
                                       
   
                                                
                                                                         
                                       
                                       
                                       
                                       
                                       
                                       
                                       
                                       
                                       
                                       
                                        
                                        
                                        
                                        
                                        
                                        
                                  
    
__STATIC_INLINE uint32_t LL_PWR_IsEnabledGPIOPullUp(uint32_t GPIO, uint32_t GPIONumber)
{
  return ((READ_BIT(*((__IO uint32_t *)GPIO), GPIONumber) == (GPIONumber)) ? 1UL : 0UL);
}

   
                                                                     
                                                                  
                                                                  
                                                                  
                                                                  
                                                                  
                                                                  
                                                                  
                                                                  
                                                                
                                                                   
                                   
                                   
                                   
                                   
                                   
                                       
                                       
                                   
                                       
   
                                                
                                                                         
                                       
                                       
                                       
                                       
                                       
                                       
                                       
                                       
                                       
                                       
                                        
                                        
                                        
                                        
                                        
                                        
                
    
__STATIC_INLINE void LL_PWR_EnableGPIOPullDown(uint32_t GPIO, uint32_t GPIONumber)
{
  SET_BIT(*((__IO uint32_t *)(GPIO + 4U)), GPIONumber);
}

   
                                                                      
                                                                   
                                                                   
                                                                   
                                                                   
                                                                   
                                                                   
                                                                   
                                                                   
                                                                 
                                                                   
                                   
                                   
                                   
                                   
                                   
                                       
                                       
                                   
                                       
   
                                                
                                                                         
                                       
                                       
                                       
                                       
                                       
                                       
                                       
                                       
                                       
                                       
                                        
                                        
                                        
                                        
                                        
                                        
                
    
__STATIC_INLINE void LL_PWR_DisableGPIOPullDown(uint32_t GPIO, uint32_t GPIONumber)
{
  CLEAR_BIT(*((__IO uint32_t *)(GPIO + 4U)), GPIONumber);
}

   
                                                    
                                                                     
                                                                     
                                                                     
                                                                     
                                                                     
                                                                     
                                                                     
                                                                     
                                                                   
                                                                   
                                   
                                   
                                   
                                   
                                   
                                       
                                       
                                   
                                       
   
                                                
                                                                         
                                       
                                       
                                       
                                       
                                       
                                       
                                       
                                       
                                       
                                       
                                        
                                        
                                        
                                        
                                        
                                        
                                  
    
__STATIC_INLINE uint32_t LL_PWR_IsEnabledGPIOPullDown(uint32_t GPIO, uint32_t GPIONumber)
{
  return ((READ_BIT(*((__IO uint32_t *)(GPIO + 4U)), GPIONumber) == (GPIONumber)) ? 1UL : 0UL);
}

   
      
    

                                                       
      
    

   
                                          
                                                                   
                                  
    
__STATIC_INLINE uint32_t LL_PWR_IsActiveFlag_InternWU(void)
{
  return ((READ_BIT(PWR->SR1, PWR_SR1_WUFI) == (PWR_SR1_WUFI)) ? 1UL : 0UL);
}

#if defined(PWR_SR1_EXT_SMPS_RDY)
   
                                                         
                                                                       
                                  
    
__STATIC_INLINE uint32_t LL_PWR_IsActiveFlag_ExtSMPSReady(void)
{
  return ((READ_BIT(PWR->SR1, PWR_SR1_EXT_SMPS_RDY) == (PWR_SR1_EXT_SMPS_RDY)) ? 1UL : 0UL);
}
#endif                           

   
                             
                                                             
                                  
    
__STATIC_INLINE uint32_t LL_PWR_IsActiveFlag_SB(void)
{
  return ((READ_BIT(PWR->SR1, PWR_SR1_SBF) == (PWR_SR1_SBF)) ? 1UL : 0UL);
}

   
                              
                                                              
                                  
    
__STATIC_INLINE uint32_t LL_PWR_IsActiveFlag_WU5(void)
{
  return ((READ_BIT(PWR->SR1, PWR_SR1_WUF5) == (PWR_SR1_WUF5)) ? 1UL : 0UL);
}

   
                              
                                                              
                                  
    
__STATIC_INLINE uint32_t LL_PWR_IsActiveFlag_WU4(void)
{
  return ((READ_BIT(PWR->SR1, PWR_SR1_WUF4) == (PWR_SR1_WUF4)) ? 1UL : 0UL);
}

   
                              
                                                              
                                  
    
__STATIC_INLINE uint32_t LL_PWR_IsActiveFlag_WU3(void)
{
  return ((READ_BIT(PWR->SR1, PWR_SR1_WUF3) == (PWR_SR1_WUF3)) ? 1UL : 0UL);
}

   
                              
                                                              
                                  
    
__STATIC_INLINE uint32_t LL_PWR_IsActiveFlag_WU2(void)
{
  return ((READ_BIT(PWR->SR1, PWR_SR1_WUF2) == (PWR_SR1_WUF2)) ? 1UL : 0UL);
}

   
                              
                                                              
                                  
    
__STATIC_INLINE uint32_t LL_PWR_IsActiveFlag_WU1(void)
{
  return ((READ_BIT(PWR->SR1, PWR_SR1_WUF1) == (PWR_SR1_WUF1)) ? 1UL : 0UL);
}

   
                               
                                                          
                
    
__STATIC_INLINE void LL_PWR_ClearFlag_SB(void)
{
  WRITE_REG(PWR->SCR, PWR_SCR_CSBF);
}

   
                               
                                                          
                
    
__STATIC_INLINE void LL_PWR_ClearFlag_WU(void)
{
  WRITE_REG(PWR->SCR, PWR_SCR_CWUF);
}

   
                                
                                                           
                
    
__STATIC_INLINE void LL_PWR_ClearFlag_WU5(void)
{
  WRITE_REG(PWR->SCR, PWR_SCR_CWUF5);
}

   
                                
                                                           
                
    
__STATIC_INLINE void LL_PWR_ClearFlag_WU4(void)
{
  WRITE_REG(PWR->SCR, PWR_SCR_CWUF4);
}

   
                                
                                                           
                
    
__STATIC_INLINE void LL_PWR_ClearFlag_WU3(void)
{
  WRITE_REG(PWR->SCR, PWR_SCR_CWUF3);
}

   
                                
                                                           
                
    
__STATIC_INLINE void LL_PWR_ClearFlag_WU2(void)
{
  WRITE_REG(PWR->SCR, PWR_SCR_CWUF2);
}

   
                                
                                                           
                
    
__STATIC_INLINE void LL_PWR_ClearFlag_WU1(void)
{
  WRITE_REG(PWR->SCR, PWR_SCR_CWUF1);
}

   
                                                                          
                                                                
                                  
    
__STATIC_INLINE uint32_t LL_PWR_IsActiveFlag_PVMO4(void)
{
  return ((READ_BIT(PWR->SR2, PWR_SR2_PVMO4) == (PWR_SR2_PVMO4)) ? 1UL : 0UL);
}

   
                                                                          
                                                                
                                  
    
__STATIC_INLINE uint32_t LL_PWR_IsActiveFlag_PVMO3(void)
{
  return ((READ_BIT(PWR->SR2, PWR_SR2_PVMO3) == (PWR_SR2_PVMO3)) ? 1UL : 0UL);
}

#if defined(PWR_SR2_PVMO2)
   
                                                                            
                                                                
                                  
    
__STATIC_INLINE uint32_t LL_PWR_IsActiveFlag_PVMO2(void)
{
  return ((READ_BIT(PWR->SR2, PWR_SR2_PVMO2) == (PWR_SR2_PVMO2)) ? 1UL : 0UL);
}
#endif                    

#if defined(PWR_SR2_PVMO1)
   
                                                                            
                                                                
                                  
    
__STATIC_INLINE uint32_t LL_PWR_IsActiveFlag_PVMO1(void)
{
  return ((READ_BIT(PWR->SR2, PWR_SR2_PVMO1) == (PWR_SR2_PVMO1)) ? 1UL : 0UL);
}
#endif                    

   
                                                                                     
                                                               
                                  
    
__STATIC_INLINE uint32_t LL_PWR_IsActiveFlag_PVDO(void)
{
  return ((READ_BIT(PWR->SR2, PWR_SR2_PVDO) == (PWR_SR2_PVDO)) ? 1UL : 0UL);
}

   
                                                                                                                                                          
                                                              
                                  
    
__STATIC_INLINE uint32_t LL_PWR_IsActiveFlag_VOS(void)
{
  return ((READ_BIT(PWR->SR2, PWR_SR2_VOSF) == (PWR_SR2_VOSF)) ? 1UL : 0UL);
}

   
                                                                                        
                                                                                                                                        
                                                                 
                                  
    
__STATIC_INLINE uint32_t LL_PWR_IsActiveFlag_REGLPF(void)
{
  return ((READ_BIT(PWR->SR2, PWR_SR2_REGLPF) == (PWR_SR2_REGLPF)) ? 1UL : 0UL);
}

   
                                                                    
                                                                 
                                  
    
__STATIC_INLINE uint32_t LL_PWR_IsActiveFlag_REGLPS(void)
{
  return ((READ_BIT(PWR->SR2, PWR_SR2_REGLPS) == (PWR_SR2_REGLPS)) ? 1UL : 0UL);
}

   
      
    

#if defined(USE_FULL_LL_DRIVER)
                                                       
      
    
ErrorStatus LL_PWR_DeInit(void);
   
      
    
#endif                         

                                                              
      
    
                                                                                
                                                                                
#define LL_PWR_IsActiveFlag_VOSF  LL_PWR_IsActiveFlag_VOS
   
      
    

   
      
    

   
      
    

#endif                   

   
      
    

#ifdef __cplusplus
}
#endif

#endif                         
