/**
  ******************************************************************************
  * @file    stm32l4xx_hal_pwr_ex.c
  * @author  MCD Application Team
  * @brief   Extended PWR HAL module driver.
  *          This file provides firmware functions to manage the following
  *          functionalities of the Power Controller (PWR) peripheral:
  *           + Extended Initialization and de-initialization functions
  *           + Extended Peripheral Control functions
  *
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

                                                                                
#include "stm32l4xx_hal.h"

                                    
      
    

                         
                                         
      
    

#ifdef HAL_PWR_MODULE_ENABLED

                                                                                
                                                                                

#if defined (STM32L412xx) || defined (STM32L422xx) || defined (STM32L431xx) || defined (STM32L432xx) || defined (STM32L433xx) || defined (STM32L442xx) || defined (STM32L443xx)
#define PWR_PORTH_AVAILABLE_PINS   ((uint32_t)0x0000000B)                  
#elif defined (STM32L451xx) || defined (STM32L452xx) || defined (STM32L462xx)
#define PWR_PORTH_AVAILABLE_PINS   ((uint32_t)0x0000000B)                  
#elif defined (STM32L471xx) || defined (STM32L475xx) || defined (STM32L476xx) || defined (STM32L485xx) || defined (STM32L486xx)
#define PWR_PORTH_AVAILABLE_PINS   ((uint32_t)0x00000003)              
#elif defined (STM32L496xx) || defined (STM32L4A6xx) || defined (STM32L4P5xx) || defined (STM32L4Q5xx) || defined (STM32L4R5xx) || defined (STM32L4R7xx) || defined (STM32L4R9xx) || defined (STM32L4S5xx) || defined (STM32L4S7xx) || defined (STM32L4S9xx)
#define PWR_PORTH_AVAILABLE_PINS   ((uint32_t)0x0000FFFF)                
#endif

#if defined (STM32L496xx) || defined (STM32L4A6xx) || defined (STM32L4P5xx) || defined (STM32L4Q5xx) || defined (STM32L4R5xx) || defined (STM32L4R7xx) || defined (STM32L4R9xx) || defined (STM32L4S5xx) || defined (STM32L4S7xx) || defined (STM32L4S9xx)
#define PWR_PORTI_AVAILABLE_PINS   ((uint32_t)0x00000FFF)                
#endif

                                                                       
      
    

                                                   
      
    
#define PVM_MODE_IT               ((uint32_t)0x00010000)                                                                 
#define PVM_MODE_EVT              ((uint32_t)0x00020000)                                                                 
#define PVM_RISING_EDGE           ((uint32_t)0x00000001)                                                                 
#define PVM_FALLING_EDGE          ((uint32_t)0x00000002)                                                                 
   
      
    

                                                                          
      
    
#define PWR_FLAG_SETTING_DELAY_US                      50UL                                                           
   
      
    



   
      
    



                                                                                
                                                                                
                                                                                
                                                                                

                                                                      
      
    

                                                                                   
                                                   
   
         
                                                                                
                                                                                            
                                                                                
        

            
      
    


   
                                        
                                                                                       
                                                                  
    
uint32_t HAL_PWREx_GetVoltageRange(void)
{
#if defined(PWR_CR5_R1MODE)
    if (READ_BIT(PWR->CR1, PWR_CR1_VOS) == PWR_REGULATOR_VOLTAGE_SCALE2)
    {
      return PWR_REGULATOR_VOLTAGE_SCALE2;
    }
    else if (READ_BIT(PWR->CR5, PWR_CR5_R1MODE) == PWR_CR5_R1MODE)
    {
                                                                       
      return PWR_REGULATOR_VOLTAGE_SCALE1;
    }
    else
    {
      return PWR_REGULATOR_VOLTAGE_SCALE1_BOOST;
    }
#else
  return  (PWR->CR1 & PWR_CR1_VOS);
#endif
}



   
                                                                
                                                                            
                                                                 
                                                               
                 
                                                                                                                        
                                                                                   
                                                                                  
        
                                                                                            
                                                                                   
                                                                                 
                                                                                            
                                                                                   
                                                                                 
                                                                                         
                                                                                     
                                                                                        
                                                                                        
                                                                             
                                                                                 
                                                                                 
                                                           
                      
    
HAL_StatusTypeDef HAL_PWREx_ControlVoltageScaling(uint32_t VoltageScaling)
{
  uint32_t wait_loop_index;

  assert_param(IS_PWR_VOLTAGE_SCALING_RANGE(VoltageScaling));

#if defined(PWR_CR5_R1MODE)
  if (VoltageScaling == PWR_REGULATOR_VOLTAGE_SCALE1_BOOST)
  {
                                     
    if (READ_BIT(PWR->CR1, PWR_CR1_VOS) == PWR_REGULATOR_VOLTAGE_SCALE2)
    {
                                              
      CLEAR_BIT(PWR->CR5, PWR_CR5_R1MODE);

                       
      MODIFY_REG(PWR->CR1, PWR_CR1_VOS, PWR_REGULATOR_VOLTAGE_SCALE1);

                                      
      wait_loop_index = ((PWR_FLAG_SETTING_DELAY_US * SystemCoreClock) / 1000000U) + 1;
      while ((HAL_IS_BIT_SET(PWR->SR2, PWR_SR2_VOSF)) && (wait_loop_index != 0U))
      {
        wait_loop_index--;
      }
      if (HAL_IS_BIT_SET(PWR->SR2, PWR_SR2_VOSF))
      {
        return HAL_TIMEOUT;
      }
    }
                                                          
    else
    {
                                                                
      CLEAR_BIT(PWR->CR5, PWR_CR5_R1MODE);
    }
  }
  else if (VoltageScaling == PWR_REGULATOR_VOLTAGE_SCALE1)
  {
                                     
    if (READ_BIT(PWR->CR1, PWR_CR1_VOS) == PWR_REGULATOR_VOLTAGE_SCALE2)
    {
                                               
      SET_BIT(PWR->CR5, PWR_CR5_R1MODE);

                       
      MODIFY_REG(PWR->CR1, PWR_CR1_VOS, PWR_REGULATOR_VOLTAGE_SCALE1);

                                      
      wait_loop_index = ((PWR_FLAG_SETTING_DELAY_US * SystemCoreClock) / 1000000U) + 1;
      while ((HAL_IS_BIT_SET(PWR->SR2, PWR_SR2_VOSF)) && (wait_loop_index != 0U))
      {
        wait_loop_index--;
      }
      if (HAL_IS_BIT_SET(PWR->SR2, PWR_SR2_VOSF))
      {
        return HAL_TIMEOUT;
      }
    }
                                                           
    else
    {
                                                               
      SET_BIT(PWR->CR5, PWR_CR5_R1MODE);
    }
  }
  else
  {
                     
    MODIFY_REG(PWR->CR1, PWR_CR1_VOS, PWR_REGULATOR_VOLTAGE_SCALE2);
                                                                    
                                                                    
  }

#else

                      
  if (VoltageScaling == PWR_REGULATOR_VOLTAGE_SCALE1)
  {
    if (READ_BIT(PWR->CR1, PWR_CR1_VOS) != PWR_REGULATOR_VOLTAGE_SCALE1)
    {
                       
      MODIFY_REG(PWR->CR1, PWR_CR1_VOS, PWR_REGULATOR_VOLTAGE_SCALE1);

                                      
      wait_loop_index = ((PWR_FLAG_SETTING_DELAY_US * SystemCoreClock) / 1000000U) + 1U;
      while ((HAL_IS_BIT_SET(PWR->SR2, PWR_SR2_VOSF)) && (wait_loop_index != 0U))
      {
        wait_loop_index--;
      }
      if (HAL_IS_BIT_SET(PWR->SR2, PWR_SR2_VOSF))
      {
        return HAL_TIMEOUT;
      }
    }
  }
  else
  {
    if (READ_BIT(PWR->CR1, PWR_CR1_VOS) != PWR_REGULATOR_VOLTAGE_SCALE2)
    {
                       
      MODIFY_REG(PWR->CR1, PWR_CR1_VOS, PWR_REGULATOR_VOLTAGE_SCALE2);
                                                                      
    }
  }
#endif

  return HAL_OK;
}


   
                                   
                                                                                                 
                                                               
                                                               
                                                                             
                                                                             
                
    
void HAL_PWREx_EnableBatteryCharging(uint32_t ResistorSelection)
{
  assert_param(IS_PWR_BATTERY_RESISTOR_SELECT(ResistorSelection));

                                  
  MODIFY_REG(PWR->CR4, PWR_CR4_VBRS, ResistorSelection);

                               
  SET_BIT(PWR->CR4, PWR_CR4_VBE);
}


   
                                    
                
    
void HAL_PWREx_DisableBatteryCharging(void)
{
  CLEAR_BIT(PWR->CR4, PWR_CR4_VBE);
}


#if defined(PWR_CR2_USV)
   
                                
                                                                                         
                
    
void HAL_PWREx_EnableVddUSB(void)
{
  SET_BIT(PWR->CR2, PWR_CR2_USV);
}


   
                                 
                
    
void HAL_PWREx_DisableVddUSB(void)
{
  CLEAR_BIT(PWR->CR2, PWR_CR2_USV);
}
#endif                  

#if defined(PWR_CR2_IOSV)
   
                                
                                                                                         
                
    
void HAL_PWREx_EnableVddIO2(void)
{
  SET_BIT(PWR->CR2, PWR_CR2_IOSV);
}


   
                                 
                
    
void HAL_PWREx_DisableVddIO2(void)
{
  CLEAR_BIT(PWR->CR2, PWR_CR2_IOSV);
}
#endif                   


   
                                        
                
    
void HAL_PWREx_EnableInternalWakeUpLine(void)
{
  SET_BIT(PWR->CR3, PWR_CR3_EIWF);
}


   
                                         
                
    
void HAL_PWREx_DisableInternalWakeUpLine(void)
{
  CLEAR_BIT(PWR->CR3, PWR_CR3_EIWF);
}



   
                                                                   
                                                                                  
                                                       
                                                                                
                                                                     
                                                                              
                                                                    
                                                                                       
                                                                          
                                                                                    
                                              
                                                                                       
                                                                                   
                                                    
                                                              
                                                                                
                                                                               
                                                               
                      
    
HAL_StatusTypeDef HAL_PWREx_EnableGPIOPullUp(uint32_t GPIO, uint32_t GPIONumber)
{
  HAL_StatusTypeDef status = HAL_OK;

  assert_param(IS_PWR_GPIO(GPIO));
  assert_param(IS_PWR_GPIO_BIT_NUMBER(GPIONumber));

  switch (GPIO)
  {
    case PWR_GPIO_A:
       SET_BIT(PWR->PUCRA, (GPIONumber & (~(PWR_GPIO_BIT_14))));
       CLEAR_BIT(PWR->PDCRA, (GPIONumber & (~(PWR_GPIO_BIT_13|PWR_GPIO_BIT_15))));
       break;
    case PWR_GPIO_B:
       SET_BIT(PWR->PUCRB, GPIONumber);
       CLEAR_BIT(PWR->PDCRB, (GPIONumber & (~(PWR_GPIO_BIT_4))));
       break;
    case PWR_GPIO_C:
       SET_BIT(PWR->PUCRC, GPIONumber);
       CLEAR_BIT(PWR->PDCRC, GPIONumber);
       break;
#if defined(GPIOD)
    case PWR_GPIO_D:
       SET_BIT(PWR->PUCRD, GPIONumber);
       CLEAR_BIT(PWR->PDCRD, GPIONumber);
       break;
#endif
#if defined(GPIOE)
    case PWR_GPIO_E:
       SET_BIT(PWR->PUCRE, GPIONumber);
       CLEAR_BIT(PWR->PDCRE, GPIONumber);
       break;
#endif
#if defined(GPIOF)
    case PWR_GPIO_F:
       SET_BIT(PWR->PUCRF, GPIONumber);
       CLEAR_BIT(PWR->PDCRF, GPIONumber);
       break;
#endif
#if defined(GPIOG)
    case PWR_GPIO_G:
       SET_BIT(PWR->PUCRG, GPIONumber);
       CLEAR_BIT(PWR->PDCRG, GPIONumber);
       break;
#endif
    case PWR_GPIO_H:
       SET_BIT(PWR->PUCRH, (GPIONumber & PWR_PORTH_AVAILABLE_PINS));
#if defined (STM32L496xx) || defined (STM32L4A6xx)
       CLEAR_BIT(PWR->PDCRH, ((GPIONumber & PWR_PORTH_AVAILABLE_PINS) & (~(PWR_GPIO_BIT_3))));
#else
       CLEAR_BIT(PWR->PDCRH, (GPIONumber & PWR_PORTH_AVAILABLE_PINS));
#endif
       break;
#if defined(GPIOI)
    case PWR_GPIO_I:
       SET_BIT(PWR->PUCRI, (GPIONumber & PWR_PORTI_AVAILABLE_PINS));
       CLEAR_BIT(PWR->PDCRI, (GPIONumber & PWR_PORTI_AVAILABLE_PINS));
       break;
#endif
    default:
      status = HAL_ERROR;
      break;
  }

  return status;
}


   
                                                                         
                                                                                      
                                                          
                                                                                      
                                                
                                                                                         
                                                                                    
                                                    
                                                              
                                                                                
                                                                                 
                                                               
                      
    
HAL_StatusTypeDef HAL_PWREx_DisableGPIOPullUp(uint32_t GPIO, uint32_t GPIONumber)
{
  HAL_StatusTypeDef status = HAL_OK;

  assert_param(IS_PWR_GPIO(GPIO));
  assert_param(IS_PWR_GPIO_BIT_NUMBER(GPIONumber));

  switch (GPIO)
  {
    case PWR_GPIO_A:
       CLEAR_BIT(PWR->PUCRA, (GPIONumber & (~(PWR_GPIO_BIT_14))));
       break;
    case PWR_GPIO_B:
       CLEAR_BIT(PWR->PUCRB, GPIONumber);
       break;
    case PWR_GPIO_C:
       CLEAR_BIT(PWR->PUCRC, GPIONumber);
       break;
#if defined(GPIOD)
    case PWR_GPIO_D:
       CLEAR_BIT(PWR->PUCRD, GPIONumber);
       break;
#endif
#if defined(GPIOE)
    case PWR_GPIO_E:
       CLEAR_BIT(PWR->PUCRE, GPIONumber);
       break;
#endif
#if defined(GPIOF)
    case PWR_GPIO_F:
       CLEAR_BIT(PWR->PUCRF, GPIONumber);
       break;
#endif
#if defined(GPIOG)
    case PWR_GPIO_G:
       CLEAR_BIT(PWR->PUCRG, GPIONumber);
       break;
#endif
    case PWR_GPIO_H:
       CLEAR_BIT(PWR->PUCRH, (GPIONumber & PWR_PORTH_AVAILABLE_PINS));
       break;
#if defined(GPIOI)
    case PWR_GPIO_I:
       CLEAR_BIT(PWR->PUCRI, (GPIONumber & PWR_PORTI_AVAILABLE_PINS));
       break;
#endif
    default:
       status = HAL_ERROR;
       break;
  }

  return status;
}



   
                                                                     
                                                                                  
                                                         
                                                                                
                                                                     
                                                                              
                                                                    
                                                                                       
                                                                          
                                                                                    
                                              
                                                                                  
                                                                                   
                                                    
                                                              
                                                                                
                                                                               
                                                               
                      
    
HAL_StatusTypeDef HAL_PWREx_EnableGPIOPullDown(uint32_t GPIO, uint32_t GPIONumber)
{
  HAL_StatusTypeDef status = HAL_OK;

  assert_param(IS_PWR_GPIO(GPIO));
  assert_param(IS_PWR_GPIO_BIT_NUMBER(GPIONumber));

  switch (GPIO)
  {
    case PWR_GPIO_A:
       SET_BIT(PWR->PDCRA, (GPIONumber & (~(PWR_GPIO_BIT_13|PWR_GPIO_BIT_15))));
       CLEAR_BIT(PWR->PUCRA, (GPIONumber & (~(PWR_GPIO_BIT_14))));
       break;
    case PWR_GPIO_B:
       SET_BIT(PWR->PDCRB, (GPIONumber & (~(PWR_GPIO_BIT_4))));
       CLEAR_BIT(PWR->PUCRB, GPIONumber);
       break;
    case PWR_GPIO_C:
       SET_BIT(PWR->PDCRC, GPIONumber);
       CLEAR_BIT(PWR->PUCRC, GPIONumber);
       break;
#if defined(GPIOD)
    case PWR_GPIO_D:
       SET_BIT(PWR->PDCRD, GPIONumber);
       CLEAR_BIT(PWR->PUCRD, GPIONumber);
       break;
#endif
#if defined(GPIOE)
    case PWR_GPIO_E:
       SET_BIT(PWR->PDCRE, GPIONumber);
       CLEAR_BIT(PWR->PUCRE, GPIONumber);
       break;
#endif
#if defined(GPIOF)
    case PWR_GPIO_F:
       SET_BIT(PWR->PDCRF, GPIONumber);
       CLEAR_BIT(PWR->PUCRF, GPIONumber);
       break;
#endif
#if defined(GPIOG)
    case PWR_GPIO_G:
       SET_BIT(PWR->PDCRG, GPIONumber);
       CLEAR_BIT(PWR->PUCRG, GPIONumber);
       break;
#endif
    case PWR_GPIO_H:
#if defined (STM32L496xx) || defined (STM32L4A6xx)
       SET_BIT(PWR->PDCRH, ((GPIONumber & PWR_PORTH_AVAILABLE_PINS) & (~(PWR_GPIO_BIT_3))));
#else
       SET_BIT(PWR->PDCRH, (GPIONumber & PWR_PORTH_AVAILABLE_PINS));
#endif
       CLEAR_BIT(PWR->PUCRH, (GPIONumber & PWR_PORTH_AVAILABLE_PINS));
       break;
#if defined(GPIOI)
    case PWR_GPIO_I:
       SET_BIT(PWR->PDCRI, (GPIONumber & PWR_PORTI_AVAILABLE_PINS));
       CLEAR_BIT(PWR->PUCRI, (GPIONumber & PWR_PORTI_AVAILABLE_PINS));
       break;
#endif
    default:
      status = HAL_ERROR;
      break;
  }

  return status;
}


   
                                                                      
                                                                                      
                                                            
                                                                                      
                                                
                                                                                    
                                                                                   
                                                    
                                                              
                                                                                
                                                                                 
                                                               
                      
    
HAL_StatusTypeDef HAL_PWREx_DisableGPIOPullDown(uint32_t GPIO, uint32_t GPIONumber)
{
  HAL_StatusTypeDef status = HAL_OK;

  assert_param(IS_PWR_GPIO(GPIO));
  assert_param(IS_PWR_GPIO_BIT_NUMBER(GPIONumber));

  switch (GPIO)
  {
    case PWR_GPIO_A:
       CLEAR_BIT(PWR->PDCRA, (GPIONumber & (~(PWR_GPIO_BIT_13|PWR_GPIO_BIT_15))));
       break;
    case PWR_GPIO_B:
       CLEAR_BIT(PWR->PDCRB, (GPIONumber & (~(PWR_GPIO_BIT_4))));
       break;
    case PWR_GPIO_C:
       CLEAR_BIT(PWR->PDCRC, GPIONumber);
       break;
#if defined(GPIOD)
    case PWR_GPIO_D:
       CLEAR_BIT(PWR->PDCRD, GPIONumber);
       break;
#endif
#if defined(GPIOE)
    case PWR_GPIO_E:
       CLEAR_BIT(PWR->PDCRE, GPIONumber);
       break;
#endif
#if defined(GPIOF)
    case PWR_GPIO_F:
       CLEAR_BIT(PWR->PDCRF, GPIONumber);
       break;
#endif
#if defined(GPIOG)
    case PWR_GPIO_G:
       CLEAR_BIT(PWR->PDCRG, GPIONumber);
       break;
#endif
    case PWR_GPIO_H:
#if defined (STM32L496xx) || defined (STM32L4A6xx)
       CLEAR_BIT(PWR->PDCRH, ((GPIONumber & PWR_PORTH_AVAILABLE_PINS) & (~(PWR_GPIO_BIT_3))));
#else
       CLEAR_BIT(PWR->PDCRH, (GPIONumber & PWR_PORTH_AVAILABLE_PINS));
#endif
       break;
#if defined(GPIOI)
    case PWR_GPIO_I:
       CLEAR_BIT(PWR->PDCRI, (GPIONumber & PWR_PORTI_AVAILABLE_PINS));
       break;
#endif
    default:
      status = HAL_ERROR;
      break;
  }

  return status;
}



   
                                                      
                                                                                       
                                                                                       
                                                                                             
                                                                                                  
                                                                                             
                                                      
                
    
void HAL_PWREx_EnablePullUpPullDownConfig(void)
{
  SET_BIT(PWR->CR3, PWR_CR3_APC);
}


   
                                                       
                                                                                           
                                                                                           
                
    
void HAL_PWREx_DisablePullUpPullDownConfig(void)
{
  CLEAR_BIT(PWR->CR3, PWR_CR3_APC);
}



   
                                                               
                
    
void HAL_PWREx_EnableSRAM2ContentRetention(void)
{
  (void) HAL_PWREx_SetSRAM2ContentRetention(PWR_FULL_SRAM2_RETENTION);
}

   
                                                           
                
    
void HAL_PWREx_DisableSRAM2ContentRetention(void)
{
  (void) HAL_PWREx_SetSRAM2ContentRetention(PWR_NO_SRAM2_RETENTION);
}

   
                                                          
                                                                    
                                                               
                                                                                                                   
                                                                                                                       
                                                                                                                                   
                                                                                
                      
    
HAL_StatusTypeDef HAL_PWREx_SetSRAM2ContentRetention(uint32_t SRAM2Size)
{
  assert_param(IS_PWR_SRAM2_RETENTION(SRAM2Size));

  if (SRAM2Size == PWR_NO_SRAM2_RETENTION)
  {
    CLEAR_BIT(PWR->CR3, PWR_CR3_RRS);
  }
  else if (SRAM2Size == PWR_FULL_SRAM2_RETENTION)
  {
    MODIFY_REG(PWR->CR3, PWR_CR3_RRS, PWR_FULL_SRAM2_RETENTION);
  }
#if defined(PWR_CR3_RRS_1)
  else if (SRAM2Size == PWR_4KBYTES_SRAM2_RETENTION)
  {
    MODIFY_REG(PWR->CR3, PWR_CR3_RRS, PWR_4KBYTES_SRAM2_RETENTION);
  }
#endif                    
  else {
    return HAL_ERROR;
  }

  return HAL_OK;
}


#if defined(PWR_CR3_ENULP)
   
                                                                                 
                                                            
                
    
void HAL_PWREx_EnableBORPVD_ULP(void)
{
  SET_BIT(PWR->CR3, PWR_CR3_ENULP);
}


   
                                                                                  
                                                           
                
    
void HAL_PWREx_DisableBORPVD_ULP(void)
{
  CLEAR_BIT(PWR->CR3, PWR_CR3_ENULP);
}
#endif                    


#if defined(PWR_CR4_EXT_SMPS_ON)
   
                                            
                                                                                                
                                                  
                
    
void HAL_PWREx_EnableExtSMPS_0V95(void)
{
  SET_BIT(PWR->CR4, PWR_CR4_EXT_SMPS_ON);
}

   
                                            
                                                                    
                                                
                                                            
                
    
void HAL_PWREx_DisableExtSMPS_0V95(void)
{
  CLEAR_BIT(PWR->CR4, PWR_CR4_EXT_SMPS_ON);
}
#endif                          


#if defined(PWR_CR1_RRSTP)
   
                                                         
                                                                                
                                               
                
    
void HAL_PWREx_EnableSRAM3ContentRetention(void)
{
  SET_BIT(PWR->CR1, PWR_CR1_RRSTP);
}


   
                                                          
                                                                       
                                   
                
    
void HAL_PWREx_DisableSRAM3ContentRetention(void)
{
  CLEAR_BIT(PWR->CR1, PWR_CR1_RRSTP);
}
#endif                    

#if defined(PWR_CR3_DSIPDEN)
   
                                                   
                
    
void HAL_PWREx_EnableDSIPinsPDActivation(void)
{
  SET_BIT(PWR->CR3, PWR_CR3_DSIPDEN);
}


   
                                                    
                
    
void HAL_PWREx_DisableDSIPinsPDActivation(void)
{
  CLEAR_BIT(PWR->CR3, PWR_CR3_DSIPDEN);
}
#endif                      

#if defined(PWR_CR2_PVME1)
   
                                                                     
                
    
void HAL_PWREx_EnablePVM1(void)
{
  SET_BIT(PWR->CR2, PWR_PVM_1);
}

   
                                                                      
                
    
void HAL_PWREx_DisablePVM1(void)
{
  CLEAR_BIT(PWR->CR2, PWR_PVM_1);
}
#endif                    


#if defined(PWR_CR2_PVME2)
   
                                                                     
                
    
void HAL_PWREx_EnablePVM2(void)
{
  SET_BIT(PWR->CR2, PWR_PVM_2);
}

   
                                                                      
                
    
void HAL_PWREx_DisablePVM2(void)
{
  CLEAR_BIT(PWR->CR2, PWR_PVM_2);
}
#endif                    


   
                                                                    
                
    
void HAL_PWREx_EnablePVM3(void)
{
  SET_BIT(PWR->CR2, PWR_PVM_3);
}

   
                                                                     
                
    
void HAL_PWREx_DisablePVM3(void)
{
  CLEAR_BIT(PWR->CR2, PWR_PVM_3);
}


   
                                                                    
                
    
void HAL_PWREx_EnablePVM4(void)
{
  SET_BIT(PWR->CR2, PWR_PVM_4);
}

   
                                                                     
                
    
void HAL_PWREx_DisablePVM4(void)
{
  CLEAR_BIT(PWR->CR2, PWR_PVM_4);
}




   
                                                             
                                                                              
                                         
                                                                                
                                                                                   
                                   
                                                                              
                                                                           
                                                         
                      
    
HAL_StatusTypeDef HAL_PWREx_ConfigPVM(PWR_PVMTypeDef *sConfigPVM)
{
  HAL_StatusTypeDef status = HAL_OK;

                            
  assert_param(IS_PWR_PVM_TYPE(sConfigPVM->PVMType));
  assert_param(IS_PWR_PVM_MODE(sConfigPVM->Mode));


                                                       
                                                         
                                                          
  switch (sConfigPVM->PVMType)
  {
#if defined(PWR_CR2_PVME1)
    case PWR_PVM_1:
                                                                                       
      __HAL_PWR_PVM1_EXTI_DISABLE_EVENT();
      __HAL_PWR_PVM1_EXTI_DISABLE_IT();
      __HAL_PWR_PVM1_EXTI_DISABLE_FALLING_EDGE();
      __HAL_PWR_PVM1_EXTI_DISABLE_RISING_EDGE();

                                    
      if((sConfigPVM->Mode & PVM_MODE_IT) == PVM_MODE_IT)
      {
        __HAL_PWR_PVM1_EXTI_ENABLE_IT();
      }

                                
      if((sConfigPVM->Mode & PVM_MODE_EVT) == PVM_MODE_EVT)
      {
        __HAL_PWR_PVM1_EXTI_ENABLE_EVENT();
      }

                              
      if((sConfigPVM->Mode & PVM_RISING_EDGE) == PVM_RISING_EDGE)
      {
        __HAL_PWR_PVM1_EXTI_ENABLE_RISING_EDGE();
      }

      if((sConfigPVM->Mode & PVM_FALLING_EDGE) == PVM_FALLING_EDGE)
      {
        __HAL_PWR_PVM1_EXTI_ENABLE_FALLING_EDGE();
      }
      break;
#endif                    

#if defined(PWR_CR2_PVME2)
    case PWR_PVM_2:
                                                                                       
      __HAL_PWR_PVM2_EXTI_DISABLE_EVENT();
      __HAL_PWR_PVM2_EXTI_DISABLE_IT();
      __HAL_PWR_PVM2_EXTI_DISABLE_FALLING_EDGE();
      __HAL_PWR_PVM2_EXTI_DISABLE_RISING_EDGE();

                                    
      if((sConfigPVM->Mode & PVM_MODE_IT) == PVM_MODE_IT)
      {
        __HAL_PWR_PVM2_EXTI_ENABLE_IT();
      }

                                
      if((sConfigPVM->Mode & PVM_MODE_EVT) == PVM_MODE_EVT)
      {
        __HAL_PWR_PVM2_EXTI_ENABLE_EVENT();
      }

                              
      if((sConfigPVM->Mode & PVM_RISING_EDGE) == PVM_RISING_EDGE)
      {
        __HAL_PWR_PVM2_EXTI_ENABLE_RISING_EDGE();
      }

      if((sConfigPVM->Mode & PVM_FALLING_EDGE) == PVM_FALLING_EDGE)
      {
        __HAL_PWR_PVM2_EXTI_ENABLE_FALLING_EDGE();
      }
      break;
#endif                    

    case PWR_PVM_3:
                                                                                       
      __HAL_PWR_PVM3_EXTI_DISABLE_EVENT();
      __HAL_PWR_PVM3_EXTI_DISABLE_IT();
      __HAL_PWR_PVM3_EXTI_DISABLE_FALLING_EDGE();
      __HAL_PWR_PVM3_EXTI_DISABLE_RISING_EDGE();

                                    
      if((sConfigPVM->Mode & PVM_MODE_IT) == PVM_MODE_IT)
      {
        __HAL_PWR_PVM3_EXTI_ENABLE_IT();
      }

                                
      if((sConfigPVM->Mode & PVM_MODE_EVT) == PVM_MODE_EVT)
      {
        __HAL_PWR_PVM3_EXTI_ENABLE_EVENT();
      }

                              
      if((sConfigPVM->Mode & PVM_RISING_EDGE) == PVM_RISING_EDGE)
      {
        __HAL_PWR_PVM3_EXTI_ENABLE_RISING_EDGE();
      }

      if((sConfigPVM->Mode & PVM_FALLING_EDGE) == PVM_FALLING_EDGE)
      {
        __HAL_PWR_PVM3_EXTI_ENABLE_FALLING_EDGE();
      }
      break;

    case PWR_PVM_4:
                                                                                       
      __HAL_PWR_PVM4_EXTI_DISABLE_EVENT();
      __HAL_PWR_PVM4_EXTI_DISABLE_IT();
      __HAL_PWR_PVM4_EXTI_DISABLE_FALLING_EDGE();
      __HAL_PWR_PVM4_EXTI_DISABLE_RISING_EDGE();

                                    
      if((sConfigPVM->Mode & PVM_MODE_IT) == PVM_MODE_IT)
      {
        __HAL_PWR_PVM4_EXTI_ENABLE_IT();
      }

                                
      if((sConfigPVM->Mode & PVM_MODE_EVT) == PVM_MODE_EVT)
      {
        __HAL_PWR_PVM4_EXTI_ENABLE_EVENT();
      }

                              
      if((sConfigPVM->Mode & PVM_RISING_EDGE) == PVM_RISING_EDGE)
      {
        __HAL_PWR_PVM4_EXTI_ENABLE_RISING_EDGE();
      }

      if((sConfigPVM->Mode & PVM_FALLING_EDGE) == PVM_FALLING_EDGE)
      {
        __HAL_PWR_PVM4_EXTI_ENABLE_FALLING_EDGE();
      }
      break;

    default:
      status = HAL_ERROR;
      break;
  }

  return status;
}



   
                                   
                                                                                  
                                                                                                   
                                                                                     
                                                                         
                                                                                           
                                                                        
                
    
void HAL_PWREx_EnableLowPowerRunMode(void)
{
                               
  SET_BIT(PWR->CR1, PWR_CR1_LPR);
}


   
                                   
                                                                                         
                                                                                      
                                                                              
                                 
                      
    
HAL_StatusTypeDef HAL_PWREx_DisableLowPowerRunMode(void)
{
  uint32_t wait_loop_index;

                     
  CLEAR_BIT(PWR->CR1, PWR_CR1_LPR);

                                  
  wait_loop_index = ((PWR_FLAG_SETTING_DELAY_US * SystemCoreClock) / 1000000U) + 1U;
  while ((HAL_IS_BIT_SET(PWR->SR2, PWR_SR2_REGLPF)) && (wait_loop_index != 0U))
  {
    wait_loop_index--;
  }
  if (HAL_IS_BIT_SET(PWR->SR2, PWR_SR2_REGLPF))
  {
    return HAL_TIMEOUT;
  }

  return HAL_OK;
}


   
                             
                                                                  
                                                                           
                                                                        
                                                                                                    
                                                                                                     
                                                                                                           
                                                
                                                            
                                
                                                                              
                                                                                                  
                                                                          
                                                                                   
                                                           
                                                                                    
                                                               
                                                                                
                                                                                
                
    
void HAL_PWREx_EnterSTOP0Mode(uint8_t STOPEntry)
{
                            
  assert_param(IS_PWR_STOP_ENTRY(STOPEntry));

                                       
  MODIFY_REG(PWR->CR1, PWR_CR1_LPMS, PWR_CR1_LPMS_STOP0);

                                                           
  SET_BIT(SCB->SCR, ((uint32_t)SCB_SCR_SLEEPDEEP_Msk));

                                                                                
  if(STOPEntry == PWR_STOPENTRY_WFI)
  {
                                    
    __WFI();
  }
  else
  {
                                
    __SEV();
    __WFE();
    __WFE();
  }

                                                             
  CLEAR_BIT(SCB->SCR, ((uint32_t)SCB_SCR_SLEEPDEEP_Msk));
}


   
                             
                                                                  
                                                                           
                                                                        
                                                                                                    
                                                                                                     
                                                                                                           
                                                
                                                            
                                
                                                                              
                                                                                                  
                                                                          
                                                                                                          
                                                                                    
                                                               
                                                                                
                                                                                
                
    
void HAL_PWREx_EnterSTOP1Mode(uint8_t STOPEntry)
{
                            
  assert_param(IS_PWR_STOP_ENTRY(STOPEntry));

                                            
  MODIFY_REG(PWR->CR1, PWR_CR1_LPMS, PWR_CR1_LPMS_STOP1);

                                                           
  SET_BIT(SCB->SCR, ((uint32_t)SCB_SCR_SLEEPDEEP_Msk));

                                                                                
  if(STOPEntry == PWR_STOPENTRY_WFI)
  {
                                    
    __WFI();
  }
  else
  {
                                
    __SEV();
    __WFE();
    __WFE();
  }

                                                             
  CLEAR_BIT(SCB->SCR, ((uint32_t)SCB_SCR_SLEEPDEEP_Msk));
}


   
                             
                                                                  
                                                                           
                                                                        
                                                                                                
                                                                                                                
                                                                                                         
                                           
                                                            
                                                                                                    
                                
                                                                                                           
                                             
                                                                              
                                                                                                  
                                                                          
                                                                                    
                                                               
                                                                                
                                                                                
                
    
void HAL_PWREx_EnterSTOP2Mode(uint8_t STOPEntry)
{
                           
  assert_param(IS_PWR_STOP_ENTRY(STOPEntry));

                       
  MODIFY_REG(PWR->CR1, PWR_CR1_LPMS, PWR_CR1_LPMS_STOP2);

                                                           
  SET_BIT(SCB->SCR, ((uint32_t)SCB_SCR_SLEEPDEEP_Msk));

                                                                                
  if(STOPEntry == PWR_STOPENTRY_WFI)
  {
                                    
    __WFI();
  }
  else
  {
                                
    __SEV();
    __WFE();
    __WFE();
  }

                                                             
  CLEAR_BIT(SCB->SCR, ((uint32_t)SCB_SCR_SLEEPDEEP_Msk));
}





   
                               
                                                                                                    
                                                                                  
                                                                                                  
                                    
                                                                                                        
                
    
void HAL_PWREx_EnterSHUTDOWNMode(void)
{

                         
  MODIFY_REG(PWR->CR1, PWR_CR1_LPMS, PWR_CR1_LPMS_SHUTDOWN);

                                                           
  SET_BIT(SCB->SCR, ((uint32_t)SCB_SCR_SLEEPDEEP_Msk));

                                                                       
#if defined ( __CC_ARM)
  __force_stores();
#endif
                                  
  __WFI();
}




   
                                                                    
                                                                   
                
    
void HAL_PWREx_PVD_PVM_IRQHandler(void)
{
                           
  if(__HAL_PWR_PVD_EXTI_GET_FLAG() != 0x0U)
  {
                                         
    HAL_PWR_PVDCallback();

                                    
    __HAL_PWR_PVD_EXTI_CLEAR_FLAG();
  }
                                                
#if defined(PWR_CR2_PVME1)
  if(__HAL_PWR_PVM1_EXTI_GET_FLAG() != 0x0U)
  {
                                          
    HAL_PWREx_PVM1Callback();

                                     
    __HAL_PWR_PVM1_EXTI_CLEAR_FLAG();
  }
#endif                    
#if defined(PWR_CR2_PVME2)
  if(__HAL_PWR_PVM2_EXTI_GET_FLAG() != 0x0U)
  {
                                          
    HAL_PWREx_PVM2Callback();

                                     
    __HAL_PWR_PVM2_EXTI_CLEAR_FLAG();
  }
#endif                    
  if(__HAL_PWR_PVM3_EXTI_GET_FLAG() != 0x0U)
  {
                                          
    HAL_PWREx_PVM3Callback();

                                     
    __HAL_PWR_PVM3_EXTI_CLEAR_FLAG();
  }
  if(__HAL_PWR_PVM4_EXTI_GET_FLAG() != 0x0U)
  {
                                          
    HAL_PWREx_PVM4Callback();

                                     
    __HAL_PWR_PVM4_EXTI_CLEAR_FLAG();
  }
}


#if defined(PWR_CR2_PVME1)
   
                                      
                
    
__weak void HAL_PWREx_PVM1Callback(void)
{
                                                                              
                                                                            
     
}
#endif                    

#if defined(PWR_CR2_PVME2)
   
                                      
                
    
__weak void HAL_PWREx_PVM2Callback(void)
{
                                                                              
                                                                            
     
}
#endif                    

   
                                      
                
    
__weak void HAL_PWREx_PVM3Callback(void)
{
                                                                              
                                                                            
     
}

   
                                      
                
    
__weak void HAL_PWREx_PVM4Callback(void)
{
                                                                              
                                                                            
     
}


   
      
    

   
      
    

#endif                             
   
      
    

   
      
    
