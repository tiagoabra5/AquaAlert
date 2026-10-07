/**
  ******************************************************************************
  * @file    stm32l4xx_hal_pwr_ex.h
  * @author  MCD Application Team
  * @brief   Header file of PWR HAL Extended module.
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

                                                                                
#ifndef STM32L4xx_HAL_PWR_EX_H
#define STM32L4xx_HAL_PWR_EX_H

#ifdef __cplusplus
 extern "C" {
#endif

                                                                                
#include "stm32l4xx_hal_def.h"

                                    
      
    

                     
      
    


                                                                                

                                                              
      
    


   
                                                      
    
typedef struct
{
  uint32_t PVMType;                                                                                  
                                                                                
                                                                                                                                                      
               
                                                                                                                                                         
      
                                                                                                          
                                                                                                            

  uint32_t Mode;                                                                    
                                                                                   
}PWR_PVMTypeDef;

   
      
    

                                                                                

                                                                       
      
    

                                                                                                                   
      
    
#define PWR_WUP_POLARITY_SHIFT                  0x05                                                                 
   
      
    


                                                 
      
    
#define PWR_WAKEUP_PIN1                 PWR_CR3_EWUP1                                                 
#define PWR_WAKEUP_PIN2                 PWR_CR3_EWUP2                                                 
#define PWR_WAKEUP_PIN3                 PWR_CR3_EWUP3                                                 
#define PWR_WAKEUP_PIN4                 PWR_CR3_EWUP4                                                 
#define PWR_WAKEUP_PIN5                 PWR_CR3_EWUP5                                                 
#define PWR_WAKEUP_PIN1_HIGH            PWR_CR3_EWUP1                                                 
#define PWR_WAKEUP_PIN2_HIGH            PWR_CR3_EWUP2                                                 
#define PWR_WAKEUP_PIN3_HIGH            PWR_CR3_EWUP3                                                 
#define PWR_WAKEUP_PIN4_HIGH            PWR_CR3_EWUP4                                                 
#define PWR_WAKEUP_PIN5_HIGH            PWR_CR3_EWUP5                                                 
#define PWR_WAKEUP_PIN1_LOW             (uint32_t)((PWR_CR4_WP1<<PWR_WUP_POLARITY_SHIFT) | PWR_CR3_EWUP1)                                               
#define PWR_WAKEUP_PIN2_LOW             (uint32_t)((PWR_CR4_WP2<<PWR_WUP_POLARITY_SHIFT) | PWR_CR3_EWUP2)                                               
#define PWR_WAKEUP_PIN3_LOW             (uint32_t)((PWR_CR4_WP3<<PWR_WUP_POLARITY_SHIFT) | PWR_CR3_EWUP3)                                               
#define PWR_WAKEUP_PIN4_LOW             (uint32_t)((PWR_CR4_WP4<<PWR_WUP_POLARITY_SHIFT) | PWR_CR3_EWUP4)                                               
#define PWR_WAKEUP_PIN5_LOW             (uint32_t)((PWR_CR4_WP5<<PWR_WUP_POLARITY_SHIFT) | PWR_CR3_EWUP5)                                               
   
      
    

                                                               
      
    
#if defined(PWR_CR2_PVME1)
#define PWR_PVM_1                  PWR_CR2_PVME1                                                                                                                
#endif                    
#if defined(PWR_CR2_PVME2)
#define PWR_PVM_2                  PWR_CR2_PVME2                                                                                                                   
#endif                    
#define PWR_PVM_3                  PWR_CR2_PVME3                                                                    
#define PWR_PVM_4                  PWR_CR2_PVME4                                                                    
   
      
    

                                                              
      
    
#define PWR_PVM_MODE_NORMAL                 ((uint32_t)0x00000000)                             
#define PWR_PVM_MODE_IT_RISING              ((uint32_t)0x00010001)                                                                     
#define PWR_PVM_MODE_IT_FALLING             ((uint32_t)0x00010002)                                                                      
#define PWR_PVM_MODE_IT_RISING_FALLING      ((uint32_t)0x00010003)                                                                             
#define PWR_PVM_MODE_EVENT_RISING           ((uint32_t)0x00020001)                                                        
#define PWR_PVM_MODE_EVENT_FALLING          ((uint32_t)0x00020002)                                                         
#define PWR_PVM_MODE_EVENT_RISING_FALLING   ((uint32_t)0x00020003)                                                                
   
      
    



                                                                        
      
    
#if defined(PWR_CR5_R1MODE)
#define PWR_REGULATOR_VOLTAGE_SCALE1_BOOST  ((uint32_t)0x00000000)                                             
#endif
#define PWR_REGULATOR_VOLTAGE_SCALE1        PWR_CR1_VOS_0                                                      
#define PWR_REGULATOR_VOLTAGE_SCALE2        PWR_CR1_VOS_1                                                      
   
      
    


                                                                                           
      
    
#define PWR_BATTERY_CHARGING_RESISTOR_5          ((uint32_t)0x00000000)                                                   
#define PWR_BATTERY_CHARGING_RESISTOR_1_5         PWR_CR4_VBRS                                                            
   
      
    

                                                              
      
    
#define PWR_BATTERY_CHARGING_DISABLE        ((uint32_t)0x00000000)
#define PWR_BATTERY_CHARGING_ENABLE         PWR_CR4_VBE
   
      
    

                                                                                            
      
    
#define PWR_GPIO_BIT_0   PWR_PUCRA_PA0                                
#define PWR_GPIO_BIT_1   PWR_PUCRA_PA1                                
#define PWR_GPIO_BIT_2   PWR_PUCRA_PA2                                
#define PWR_GPIO_BIT_3   PWR_PUCRA_PA3                                
#define PWR_GPIO_BIT_4   PWR_PUCRA_PA4                                
#define PWR_GPIO_BIT_5   PWR_PUCRA_PA5                                
#define PWR_GPIO_BIT_6   PWR_PUCRA_PA6                                
#define PWR_GPIO_BIT_7   PWR_PUCRA_PA7                                
#define PWR_GPIO_BIT_8   PWR_PUCRA_PA8                                
#define PWR_GPIO_BIT_9   PWR_PUCRA_PA9                                
#define PWR_GPIO_BIT_10  PWR_PUCRA_PA10                               
#define PWR_GPIO_BIT_11  PWR_PUCRA_PA11                               
#define PWR_GPIO_BIT_12  PWR_PUCRA_PA12                               
#define PWR_GPIO_BIT_13  PWR_PUCRA_PA13                               
#define PWR_GPIO_BIT_14  PWR_PDCRA_PA14                               
#define PWR_GPIO_BIT_15  PWR_PUCRA_PA15                               
   
      
    

                                  
      
    
#define PWR_GPIO_A   0x00000000U                         
#define PWR_GPIO_B   0x00000001U                         
#define PWR_GPIO_C   0x00000002U                         
#if defined(GPIOD_BASE)
#define PWR_GPIO_D   0x00000003U                         
#endif
#if defined(GPIOE_BASE)
#define PWR_GPIO_E   0x00000004U                         
#endif
#if defined(GPIOF_BASE)
#define PWR_GPIO_F   0x00000005U                         
#endif
#if defined(GPIOG_BASE)
#define PWR_GPIO_G   0x00000006U                         
#endif
#define PWR_GPIO_H   0x00000007U                         
#if defined(GPIOI_BASE)
#define PWR_GPIO_I   0x00000008U                         
#endif
   
      
    

                                                                   
      
    
#if defined(PWR_CR2_PVME1)
#define PWR_EXTI_LINE_PVM1  ((uint32_t)0x00000008)                                                                      
#endif                    
#if defined(PWR_CR2_PVME2)
#define PWR_EXTI_LINE_PVM2  ((uint32_t)0x00000010)                                                                      
#endif                    
#define PWR_EXTI_LINE_PVM3  ((uint32_t)0x00000020)                                                                      
#define PWR_EXTI_LINE_PVM4  ((uint32_t)0x00000040)                                                                      
   
      
    

                                                      
      
    
#if defined(PWR_CR2_PVME1)
#define PWR_EVENT_LINE_PVM1 ((uint32_t)0x00000008)                                                       
#endif                    
#if defined(PWR_CR2_PVME2)
#define PWR_EVENT_LINE_PVM2 ((uint32_t)0x00000010)                                                       
#endif                    
#define PWR_EVENT_LINE_PVM3 ((uint32_t)0x00000020)                                                       
#define PWR_EVENT_LINE_PVM4 ((uint32_t)0x00000040)                                                       
   
      
    

                                          
                                                           
                                                                   
                                              
                                      
                                      
                                                              
                                                
      
    
#define PWR_FLAG_WUF1                       ((uint32_t)0x0020)                                       
#define PWR_FLAG_WUF2                       ((uint32_t)0x0021)                                       
#define PWR_FLAG_WUF3                       ((uint32_t)0x0022)                                       
#define PWR_FLAG_WUF4                       ((uint32_t)0x0023)                                       
#define PWR_FLAG_WUF5                       ((uint32_t)0x0024)                                       
#define PWR_FLAG_WU                         PWR_SR1_WUF                                                           
#define PWR_FLAG_SB                         ((uint32_t)0x0028)                       
#if defined(PWR_SR1_EXT_SMPS_RDY)
#define PWR_FLAG_EXT_SMPS                   ((uint32_t)0x002D)                                                
#endif                           
#define PWR_FLAG_WUFI                       ((uint32_t)0x002F)                                         

#define PWR_FLAG_REGLPS                     ((uint32_t)0x0048)                                         
#define PWR_FLAG_REGLPF                     ((uint32_t)0x0049)                                   
#define PWR_FLAG_VOSF                       ((uint32_t)0x004A)                               
#define PWR_FLAG_PVDO                       ((uint32_t)0x004B)                                             
#if defined(PWR_CR2_PVME1)
#define PWR_FLAG_PVMO1                      ((uint32_t)0x004C)                                                 
#endif                    
#if defined(PWR_CR2_PVME2)
#define PWR_FLAG_PVMO2                      ((uint32_t)0x004D)                                                 
#endif                    
#define PWR_FLAG_PVMO3                      ((uint32_t)0x004E)                                                 
#define PWR_FLAG_PVMO4                      ((uint32_t)0x004F)                                                 
   
      
    

                                                                       
      
    
#define PWR_NO_SRAM2_RETENTION         ((uint32_t)0x00000000)                                                                        
#if defined(PWR_CR3_RRS_1)
#define PWR_FULL_SRAM2_RETENTION       PWR_CR3_RRS_0                                                                              
#define PWR_4KBYTES_SRAM2_RETENTION    PWR_CR3_RRS_1                                                                                          
#else
#define PWR_FULL_SRAM2_RETENTION       PWR_CR3_RRS                                                                                
#endif                    
   
      
    

   
      
    

                                                                                
                                                                
     
   

#if defined(PWR_CR2_PVME1)
   
                                                   
                
    
#define __HAL_PWR_PVM1_EXTI_ENABLE_IT()   SET_BIT(EXTI->IMR2, PWR_EXTI_LINE_PVM1)

   
                                                    
                
    
#define __HAL_PWR_PVM1_EXTI_DISABLE_IT()  CLEAR_BIT(EXTI->IMR2, PWR_EXTI_LINE_PVM1)

   
                                      
                
    
#define __HAL_PWR_PVM1_EXTI_ENABLE_EVENT()   SET_BIT(EXTI->EMR2, PWR_EVENT_LINE_PVM1)

   
                                       
                
    
#define __HAL_PWR_PVM1_EXTI_DISABLE_EVENT()  CLEAR_BIT(EXTI->EMR2, PWR_EVENT_LINE_PVM1)

   
                                                             
                
    
#define __HAL_PWR_PVM1_EXTI_ENABLE_RISING_EDGE()   SET_BIT(EXTI->RTSR2, PWR_EXTI_LINE_PVM1)

   
                                                              
                
    
#define __HAL_PWR_PVM1_EXTI_DISABLE_RISING_EDGE()  CLEAR_BIT(EXTI->RTSR2, PWR_EXTI_LINE_PVM1)

   
                                                              
                
    
#define __HAL_PWR_PVM1_EXTI_ENABLE_FALLING_EDGE()   SET_BIT(EXTI->FTSR2, PWR_EXTI_LINE_PVM1)


   
                                                               
                
    
#define __HAL_PWR_PVM1_EXTI_DISABLE_FALLING_EDGE()  CLEAR_BIT(EXTI->FTSR2, PWR_EXTI_LINE_PVM1)


   
                                                                            
                
    
#define __HAL_PWR_PVM1_EXTI_ENABLE_RISING_FALLING_EDGE()  \
  do {                                                    \
    __HAL_PWR_PVM1_EXTI_ENABLE_RISING_EDGE();             \
    __HAL_PWR_PVM1_EXTI_ENABLE_FALLING_EDGE();            \
  } while(0)

   
                                                                        
                
    
#define __HAL_PWR_PVM1_EXTI_DISABLE_RISING_FALLING_EDGE()  \
  do {                                                     \
    __HAL_PWR_PVM1_EXTI_DISABLE_RISING_EDGE();             \
    __HAL_PWR_PVM1_EXTI_DISABLE_FALLING_EDGE();            \
  } while(0)

   
                                                                
                
    
#define __HAL_PWR_PVM1_EXTI_GENERATE_SWIT() SET_BIT(EXTI->SWIER2, PWR_EXTI_LINE_PVM1)

   
                                                                              
                                  
    
#define __HAL_PWR_PVM1_EXTI_GET_FLAG()  (EXTI->PR2 & PWR_EXTI_LINE_PVM1)

   
                                    
                
    
#define __HAL_PWR_PVM1_EXTI_CLEAR_FLAG()  WRITE_REG(EXTI->PR2, PWR_EXTI_LINE_PVM1)

#endif                    


#if defined(PWR_CR2_PVME2)
   
                                                   
                
    
#define __HAL_PWR_PVM2_EXTI_ENABLE_IT()   SET_BIT(EXTI->IMR2, PWR_EXTI_LINE_PVM2)

   
                                                    
                
    
#define __HAL_PWR_PVM2_EXTI_DISABLE_IT()  CLEAR_BIT(EXTI->IMR2, PWR_EXTI_LINE_PVM2)

   
                                      
                
    
#define __HAL_PWR_PVM2_EXTI_ENABLE_EVENT()   SET_BIT(EXTI->EMR2, PWR_EVENT_LINE_PVM2)

   
                                       
                
    
#define __HAL_PWR_PVM2_EXTI_DISABLE_EVENT()  CLEAR_BIT(EXTI->EMR2, PWR_EVENT_LINE_PVM2)

   
                                                             
                
    
#define __HAL_PWR_PVM2_EXTI_ENABLE_RISING_EDGE()   SET_BIT(EXTI->RTSR2, PWR_EXTI_LINE_PVM2)

   
                                                              
                
    
#define __HAL_PWR_PVM2_EXTI_DISABLE_RISING_EDGE()  CLEAR_BIT(EXTI->RTSR2, PWR_EXTI_LINE_PVM2)

   
                                                              
                
    
#define __HAL_PWR_PVM2_EXTI_ENABLE_FALLING_EDGE()   SET_BIT(EXTI->FTSR2, PWR_EXTI_LINE_PVM2)


   
                                                               
                
    
#define __HAL_PWR_PVM2_EXTI_DISABLE_FALLING_EDGE()  CLEAR_BIT(EXTI->FTSR2, PWR_EXTI_LINE_PVM2)


   
                                                                            
                
    
#define __HAL_PWR_PVM2_EXTI_ENABLE_RISING_FALLING_EDGE()  \
  do {                                                    \
    __HAL_PWR_PVM2_EXTI_ENABLE_RISING_EDGE();             \
    __HAL_PWR_PVM2_EXTI_ENABLE_FALLING_EDGE();            \
  } while(0)

   
                                                                        
                
    
#define __HAL_PWR_PVM2_EXTI_DISABLE_RISING_FALLING_EDGE()  \
  do {                                                     \
    __HAL_PWR_PVM2_EXTI_DISABLE_RISING_EDGE();             \
    __HAL_PWR_PVM2_EXTI_DISABLE_FALLING_EDGE();            \
  } while(0)

   
                                                                
                
    
#define __HAL_PWR_PVM2_EXTI_GENERATE_SWIT() SET_BIT(EXTI->SWIER2, PWR_EXTI_LINE_PVM2)

   
                                                                              
                                  
    
#define __HAL_PWR_PVM2_EXTI_GET_FLAG()  (EXTI->PR2 & PWR_EXTI_LINE_PVM2)

   
                                    
                
    
#define __HAL_PWR_PVM2_EXTI_CLEAR_FLAG()  WRITE_REG(EXTI->PR2, PWR_EXTI_LINE_PVM2)

#endif                    


   
                                                   
                
    
#define __HAL_PWR_PVM3_EXTI_ENABLE_IT()   SET_BIT(EXTI->IMR2, PWR_EXTI_LINE_PVM3)

   
                                                    
                
    
#define __HAL_PWR_PVM3_EXTI_DISABLE_IT()  CLEAR_BIT(EXTI->IMR2, PWR_EXTI_LINE_PVM3)

   
                                      
                
    
#define __HAL_PWR_PVM3_EXTI_ENABLE_EVENT()   SET_BIT(EXTI->EMR2, PWR_EVENT_LINE_PVM3)

   
                                       
                
    
#define __HAL_PWR_PVM3_EXTI_DISABLE_EVENT()  CLEAR_BIT(EXTI->EMR2, PWR_EVENT_LINE_PVM3)

   
                                                             
                
    
#define __HAL_PWR_PVM3_EXTI_ENABLE_RISING_EDGE()   SET_BIT(EXTI->RTSR2, PWR_EXTI_LINE_PVM3)

   
                                                              
                
    
#define __HAL_PWR_PVM3_EXTI_DISABLE_RISING_EDGE()  CLEAR_BIT(EXTI->RTSR2, PWR_EXTI_LINE_PVM3)

   
                                                              
                
    
#define __HAL_PWR_PVM3_EXTI_ENABLE_FALLING_EDGE()   SET_BIT(EXTI->FTSR2, PWR_EXTI_LINE_PVM3)


   
                                                               
                
    
#define __HAL_PWR_PVM3_EXTI_DISABLE_FALLING_EDGE()  CLEAR_BIT(EXTI->FTSR2, PWR_EXTI_LINE_PVM3)


   
                                                                            
                
    
#define __HAL_PWR_PVM3_EXTI_ENABLE_RISING_FALLING_EDGE()  \
  do {                                                    \
    __HAL_PWR_PVM3_EXTI_ENABLE_RISING_EDGE();             \
    __HAL_PWR_PVM3_EXTI_ENABLE_FALLING_EDGE();            \
  } while(0)

   
                                                                        
                
    
#define __HAL_PWR_PVM3_EXTI_DISABLE_RISING_FALLING_EDGE()  \
  do {                                                     \
    __HAL_PWR_PVM3_EXTI_DISABLE_RISING_EDGE();             \
    __HAL_PWR_PVM3_EXTI_DISABLE_FALLING_EDGE();            \
  } while(0)

   
                                                                
                
    
#define __HAL_PWR_PVM3_EXTI_GENERATE_SWIT() SET_BIT(EXTI->SWIER2, PWR_EXTI_LINE_PVM3)

   
                                                                              
                                  
    
#define __HAL_PWR_PVM3_EXTI_GET_FLAG()  (EXTI->PR2 & PWR_EXTI_LINE_PVM3)

   
                                    
                
    
#define __HAL_PWR_PVM3_EXTI_CLEAR_FLAG()  WRITE_REG(EXTI->PR2, PWR_EXTI_LINE_PVM3)




   
                                                   
                
    
#define __HAL_PWR_PVM4_EXTI_ENABLE_IT()   SET_BIT(EXTI->IMR2, PWR_EXTI_LINE_PVM4)

   
                                                    
                
    
#define __HAL_PWR_PVM4_EXTI_DISABLE_IT()  CLEAR_BIT(EXTI->IMR2, PWR_EXTI_LINE_PVM4)

   
                                      
                
    
#define __HAL_PWR_PVM4_EXTI_ENABLE_EVENT()   SET_BIT(EXTI->EMR2, PWR_EVENT_LINE_PVM4)

   
                                       
                
    
#define __HAL_PWR_PVM4_EXTI_DISABLE_EVENT()  CLEAR_BIT(EXTI->EMR2, PWR_EVENT_LINE_PVM4)

   
                                                             
                
    
#define __HAL_PWR_PVM4_EXTI_ENABLE_RISING_EDGE()   SET_BIT(EXTI->RTSR2, PWR_EXTI_LINE_PVM4)

   
                                                              
                
    
#define __HAL_PWR_PVM4_EXTI_DISABLE_RISING_EDGE()  CLEAR_BIT(EXTI->RTSR2, PWR_EXTI_LINE_PVM4)

   
                                                              
                
    
#define __HAL_PWR_PVM4_EXTI_ENABLE_FALLING_EDGE()   SET_BIT(EXTI->FTSR2, PWR_EXTI_LINE_PVM4)


   
                                                               
                
    
#define __HAL_PWR_PVM4_EXTI_DISABLE_FALLING_EDGE()  CLEAR_BIT(EXTI->FTSR2, PWR_EXTI_LINE_PVM4)


   
                                                                            
                
    
#define __HAL_PWR_PVM4_EXTI_ENABLE_RISING_FALLING_EDGE()  \
  do {                                                    \
    __HAL_PWR_PVM4_EXTI_ENABLE_RISING_EDGE();             \
    __HAL_PWR_PVM4_EXTI_ENABLE_FALLING_EDGE();            \
  } while(0)

   
                                                                        
                
    
#define __HAL_PWR_PVM4_EXTI_DISABLE_RISING_FALLING_EDGE()  \
  do {                                                     \
    __HAL_PWR_PVM4_EXTI_DISABLE_RISING_EDGE();             \
    __HAL_PWR_PVM4_EXTI_DISABLE_FALLING_EDGE();            \
  } while(0)

   
                                                                
                
    
#define __HAL_PWR_PVM4_EXTI_GENERATE_SWIT() SET_BIT(EXTI->SWIER2, PWR_EXTI_LINE_PVM4)

   
                                                                              
                                  
    
#define __HAL_PWR_PVM4_EXTI_GET_FLAG()  (EXTI->PR2 & PWR_EXTI_LINE_PVM4)

   
                                    
                
    
#define __HAL_PWR_PVM4_EXTI_CLEAR_FLAG()  WRITE_REG(EXTI->PR2, PWR_EXTI_LINE_PVM4)


   
                                                                
                                                                           
                                                                 
                                                               
                                                                                             
                                                                                   
                                                                                 
                                                                                             
                                                                                   
                                                                                 
                                                                                           
                                                                                        
                                                                                
                
    
#define __HAL_PWR_VOLTAGESCALING_CONFIG(__REGULATOR__) do {                                                     \
                                                            __IO uint32_t tmpreg;                               \
                                                            MODIFY_REG(PWR->CR1, PWR_CR1_VOS, (__REGULATOR__)); \
                                                                                                                \
                                                            tmpreg = READ_BIT(PWR->CR1, PWR_CR1_VOS);           \
                                                            UNUSED(tmpreg);                                     \
                                                          } while(0)

   
      
    

                                                                            
                                                                   
      
    

#define IS_PWR_WAKEUP_PIN(PIN) (((PIN) == PWR_WAKEUP_PIN1) || \
                                ((PIN) == PWR_WAKEUP_PIN2) || \
                                ((PIN) == PWR_WAKEUP_PIN3) || \
                                ((PIN) == PWR_WAKEUP_PIN4) || \
                                ((PIN) == PWR_WAKEUP_PIN5) || \
                                ((PIN) == PWR_WAKEUP_PIN1_HIGH) || \
                                ((PIN) == PWR_WAKEUP_PIN2_HIGH) || \
                                ((PIN) == PWR_WAKEUP_PIN3_HIGH) || \
                                ((PIN) == PWR_WAKEUP_PIN4_HIGH) || \
                                ((PIN) == PWR_WAKEUP_PIN5_HIGH) || \
                                ((PIN) == PWR_WAKEUP_PIN1_LOW) || \
                                ((PIN) == PWR_WAKEUP_PIN2_LOW) || \
                                ((PIN) == PWR_WAKEUP_PIN3_LOW) || \
                                ((PIN) == PWR_WAKEUP_PIN4_LOW) || \
                                ((PIN) == PWR_WAKEUP_PIN5_LOW))

#if defined (STM32L475xx) || defined (STM32L476xx) || defined (STM32L485xx) || defined (STM32L486xx) || \
    defined (STM32L496xx) || defined (STM32L4A6xx)                                                   || \
    defined (STM32L4P5xx) || defined (STM32L4Q5xx)                                                   || \
    defined (STM32L4R5xx) || defined (STM32L4R7xx) || defined (STM32L4R9xx) || defined (STM32L4S5xx) || defined (STM32L4S7xx) || defined (STM32L4S9xx)
#define IS_PWR_PVM_TYPE(TYPE) (((TYPE) == PWR_PVM_1) ||\
                               ((TYPE) == PWR_PVM_2) ||\
                               ((TYPE) == PWR_PVM_3) ||\
                               ((TYPE) == PWR_PVM_4))
#elif defined (STM32L471xx)
#define IS_PWR_PVM_TYPE(TYPE) (((TYPE) == PWR_PVM_2) ||\
                               ((TYPE) == PWR_PVM_3) ||\
                               ((TYPE) == PWR_PVM_4))
#endif

#if defined (STM32L412xx) || defined (STM32L422xx) || defined (STM32L433xx) || defined (STM32L443xx) || defined (STM32L452xx) || defined (STM32L462xx)
#define IS_PWR_PVM_TYPE(TYPE) (((TYPE) == PWR_PVM_1) ||\
                               ((TYPE) == PWR_PVM_3) ||\
                               ((TYPE) == PWR_PVM_4))
#elif defined (STM32L431xx) || defined (STM32L432xx) || defined (STM32L442xx) || defined (STM32L451xx)
#define IS_PWR_PVM_TYPE(TYPE) (((TYPE) == PWR_PVM_3) ||\
                               ((TYPE) == PWR_PVM_4))
#endif

#define IS_PWR_PVM_MODE(MODE)  (((MODE) == PWR_PVM_MODE_NORMAL)              ||\
                                ((MODE) == PWR_PVM_MODE_IT_RISING)           ||\
                                ((MODE) == PWR_PVM_MODE_IT_FALLING)          ||\
                                ((MODE) == PWR_PVM_MODE_IT_RISING_FALLING)   ||\
                                ((MODE) == PWR_PVM_MODE_EVENT_RISING)        ||\
                                ((MODE) == PWR_PVM_MODE_EVENT_FALLING)       ||\
                                ((MODE) == PWR_PVM_MODE_EVENT_RISING_FALLING))

#if defined(PWR_CR5_R1MODE)
#define IS_PWR_VOLTAGE_SCALING_RANGE(RANGE) (((RANGE) == PWR_REGULATOR_VOLTAGE_SCALE1_BOOST) || \
                                             ((RANGE) == PWR_REGULATOR_VOLTAGE_SCALE1)       || \
                                             ((RANGE) == PWR_REGULATOR_VOLTAGE_SCALE2))
#else
#define IS_PWR_VOLTAGE_SCALING_RANGE(RANGE) (((RANGE) == PWR_REGULATOR_VOLTAGE_SCALE1) || \
                                             ((RANGE) == PWR_REGULATOR_VOLTAGE_SCALE2))
#endif


#define IS_PWR_BATTERY_RESISTOR_SELECT(RESISTOR) (((RESISTOR) == PWR_BATTERY_CHARGING_RESISTOR_5) ||\
                                                  ((RESISTOR) == PWR_BATTERY_CHARGING_RESISTOR_1_5))

#define IS_PWR_BATTERY_CHARGING(CHARGING) (((CHARGING) == PWR_BATTERY_CHARGING_DISABLE) ||\
                                           ((CHARGING) == PWR_BATTERY_CHARGING_ENABLE))

#define IS_PWR_GPIO_BIT_NUMBER(BIT_NUMBER) (((BIT_NUMBER) & GPIO_PIN_MASK) != (uint32_t)0x00)


#if defined (STM32L412xx) || defined (STM32L422xx)
#define IS_PWR_GPIO(GPIO) (((GPIO) == PWR_GPIO_A) ||\
                           ((GPIO) == PWR_GPIO_B) ||\
                           ((GPIO) == PWR_GPIO_C) ||\
                           ((GPIO) == PWR_GPIO_D) ||\
                           ((GPIO) == PWR_GPIO_H))
#elif defined (STM32L431xx) || defined (STM32L433xx) || defined (STM32L443xx) || \
      defined (STM32L451xx) || defined (STM32L452xx) || defined (STM32L462xx)
#define IS_PWR_GPIO(GPIO) (((GPIO) == PWR_GPIO_A) ||\
                           ((GPIO) == PWR_GPIO_B) ||\
                           ((GPIO) == PWR_GPIO_C) ||\
                           ((GPIO) == PWR_GPIO_D) ||\
                           ((GPIO) == PWR_GPIO_E) ||\
                           ((GPIO) == PWR_GPIO_H))
#elif defined (STM32L432xx) || defined (STM32L442xx)
#define IS_PWR_GPIO(GPIO) (((GPIO) == PWR_GPIO_A) ||\
                           ((GPIO) == PWR_GPIO_B) ||\
                           ((GPIO) == PWR_GPIO_C) ||\
                           ((GPIO) == PWR_GPIO_H))
#elif defined (STM32L471xx) || defined (STM32L475xx) || defined (STM32L476xx) || defined (STM32L485xx) || defined (STM32L486xx)
#define IS_PWR_GPIO(GPIO) (((GPIO) == PWR_GPIO_A) ||\
                           ((GPIO) == PWR_GPIO_B) ||\
                           ((GPIO) == PWR_GPIO_C) ||\
                           ((GPIO) == PWR_GPIO_D) ||\
                           ((GPIO) == PWR_GPIO_E) ||\
                           ((GPIO) == PWR_GPIO_F) ||\
                           ((GPIO) == PWR_GPIO_G) ||\
                           ((GPIO) == PWR_GPIO_H))
#elif defined (STM32L496xx) || defined (STM32L4A6xx) || \
      defined (STM32L4P5xx) || defined (STM32L4Q5xx) || \
      defined (STM32L4R5xx) || defined (STM32L4R7xx) || defined (STM32L4R9xx) || defined (STM32L4S5xx) || defined (STM32L4S7xx) || defined (STM32L4S9xx)
#define IS_PWR_GPIO(GPIO) (((GPIO) == PWR_GPIO_A) ||\
                           ((GPIO) == PWR_GPIO_B) ||\
                           ((GPIO) == PWR_GPIO_C) ||\
                           ((GPIO) == PWR_GPIO_D) ||\
                           ((GPIO) == PWR_GPIO_E) ||\
                           ((GPIO) == PWR_GPIO_F) ||\
                           ((GPIO) == PWR_GPIO_G) ||\
                           ((GPIO) == PWR_GPIO_H) ||\
                           ((GPIO) == PWR_GPIO_I))
#endif

#if defined (STM32L4P5xx) || defined (STM32L4Q5xx)
#define IS_PWR_SRAM2_RETENTION(SRAM2) (((SRAM2) == PWR_NO_SRAM2_RETENTION)   ||\
                                       ((SRAM2) == PWR_FULL_SRAM2_RETENTION) ||\
                                       ((SRAM2) == PWR_4KBYTES_SRAM2_RETENTION))
#else
#define IS_PWR_SRAM2_RETENTION(SRAM2) (((SRAM2) == PWR_NO_SRAM2_RETENTION)   ||\
                                       ((SRAM2) == PWR_FULL_SRAM2_RETENTION))
#endif

   
      
    


                                                                        
      
    

                                                                                     
      
    


                                                                                
uint32_t HAL_PWREx_GetVoltageRange(void);
HAL_StatusTypeDef HAL_PWREx_ControlVoltageScaling(uint32_t VoltageScaling);
void HAL_PWREx_EnableBatteryCharging(uint32_t ResistorSelection);
void HAL_PWREx_DisableBatteryCharging(void);
#if defined(PWR_CR2_USV)
void HAL_PWREx_EnableVddUSB(void);
void HAL_PWREx_DisableVddUSB(void);
#endif                  
#if defined(PWR_CR2_IOSV)
void HAL_PWREx_EnableVddIO2(void);
void HAL_PWREx_DisableVddIO2(void);
#endif                   
void HAL_PWREx_EnableInternalWakeUpLine(void);
void HAL_PWREx_DisableInternalWakeUpLine(void);
HAL_StatusTypeDef HAL_PWREx_EnableGPIOPullUp(uint32_t GPIO, uint32_t GPIONumber);
HAL_StatusTypeDef HAL_PWREx_DisableGPIOPullUp(uint32_t GPIO, uint32_t GPIONumber);
HAL_StatusTypeDef HAL_PWREx_EnableGPIOPullDown(uint32_t GPIO, uint32_t GPIONumber);
HAL_StatusTypeDef HAL_PWREx_DisableGPIOPullDown(uint32_t GPIO, uint32_t GPIONumber);
void HAL_PWREx_EnablePullUpPullDownConfig(void);
void HAL_PWREx_DisablePullUpPullDownConfig(void);
void HAL_PWREx_EnableSRAM2ContentRetention(void);
void HAL_PWREx_DisableSRAM2ContentRetention(void);
HAL_StatusTypeDef HAL_PWREx_SetSRAM2ContentRetention(uint32_t SRAM2Size);
#if defined(PWR_CR1_RRSTP)
void HAL_PWREx_EnableSRAM3ContentRetention(void);
void HAL_PWREx_DisableSRAM3ContentRetention(void);
#endif                    
#if defined(PWR_CR3_DSIPDEN)
void HAL_PWREx_EnableDSIPinsPDActivation(void);
void HAL_PWREx_DisableDSIPinsPDActivation(void);
#endif                      
#if defined(PWR_CR2_PVME1)
void HAL_PWREx_EnablePVM1(void);
void HAL_PWREx_DisablePVM1(void);
#endif                    
#if defined(PWR_CR2_PVME2)
void HAL_PWREx_EnablePVM2(void);
void HAL_PWREx_DisablePVM2(void);
#endif                    
void HAL_PWREx_EnablePVM3(void);
void HAL_PWREx_DisablePVM3(void);
void HAL_PWREx_EnablePVM4(void);
void HAL_PWREx_DisablePVM4(void);
HAL_StatusTypeDef HAL_PWREx_ConfigPVM(PWR_PVMTypeDef *sConfigPVM);
#if defined(PWR_CR3_ENULP)
void HAL_PWREx_EnableBORPVD_ULP(void);
void HAL_PWREx_DisableBORPVD_ULP(void);
#endif                    
#if defined(PWR_CR4_EXT_SMPS_ON)
void HAL_PWREx_EnableExtSMPS_0V95(void);
void HAL_PWREx_DisableExtSMPS_0V95(void);
#endif                          


                                                                                
void HAL_PWREx_EnableLowPowerRunMode(void);
HAL_StatusTypeDef HAL_PWREx_DisableLowPowerRunMode(void);
void HAL_PWREx_EnterSTOP0Mode(uint8_t STOPEntry);
void HAL_PWREx_EnterSTOP1Mode(uint8_t STOPEntry);
void HAL_PWREx_EnterSTOP2Mode(uint8_t STOPEntry);
void HAL_PWREx_EnterSHUTDOWNMode(void);

void HAL_PWREx_PVD_PVM_IRQHandler(void);
#if defined(PWR_CR2_PVME1)
void HAL_PWREx_PVM1Callback(void);
#endif                    
#if defined(PWR_CR2_PVME2)
void HAL_PWREx_PVM2Callback(void);
#endif                    
void HAL_PWREx_PVM3Callback(void);
void HAL_PWREx_PVM4Callback(void);

   
      
    

   
      
    

   
      
    

   
      
    

#ifdef __cplusplus
}
#endif


#endif                             
