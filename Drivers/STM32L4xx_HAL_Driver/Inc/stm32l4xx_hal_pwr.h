/**
  ******************************************************************************
  * @file    stm32l4xx_hal_pwr.h
  * @author  MCD Application Team
  * @brief   Header file of PWR HAL module.
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

                                                                                
#ifndef STM32L4xx_HAL_PWR_H
#define STM32L4xx_HAL_PWR_H

#ifdef __cplusplus
 extern "C" {
#endif

                                                                                
#include "stm32l4xx_hal_def.h"

                                    
      
    

                   
      
    

                                                                                

                                                   
      
    

   
                                                      
    
typedef struct
{
  uint32_t PVDLevel;                                                    
                                                                                             

  uint32_t Mode;                                                                    
                                                                                 
}PWR_PVDTypeDef;


   
      
    

                                                                                

                                                           
      
    


                                                                           
      
    
#define PWR_PVDLEVEL_0                  PWR_CR2_PLS_LEV0                                    
#define PWR_PVDLEVEL_1                  PWR_CR2_PLS_LEV1                                    
#define PWR_PVDLEVEL_2                  PWR_CR2_PLS_LEV2                                    
#define PWR_PVDLEVEL_3                  PWR_CR2_PLS_LEV3                                    
#define PWR_PVDLEVEL_4                  PWR_CR2_PLS_LEV4                                    
#define PWR_PVDLEVEL_5                  PWR_CR2_PLS_LEV5                                    
#define PWR_PVDLEVEL_6                  PWR_CR2_PLS_LEV6                                    
#define PWR_PVDLEVEL_7                  PWR_CR2_PLS_LEV7                                                                        
   
      
    

                                                            
      
    
#define PWR_PVD_MODE_NORMAL                 ((uint32_t)0x00000000)                             
#define PWR_PVD_MODE_IT_RISING              ((uint32_t)0x00010001)                                                                     
#define PWR_PVD_MODE_IT_FALLING             ((uint32_t)0x00010002)                                                                      
#define PWR_PVD_MODE_IT_RISING_FALLING      ((uint32_t)0x00010003)                                                                             
#define PWR_PVD_MODE_EVENT_RISING           ((uint32_t)0x00020001)                                                        
#define PWR_PVD_MODE_EVENT_FALLING          ((uint32_t)0x00020002)                                                         
#define PWR_PVD_MODE_EVENT_RISING_FALLING   ((uint32_t)0x00020003)                                                                
   
      
    




                                                                        
      
    
#define PWR_MAINREGULATOR_ON            ((uint32_t)0x00000000)                                    
#define PWR_LOWPOWERREGULATOR_ON        PWR_CR1_LPR                                               
   
      
    

                                                        
      
    
#define PWR_SLEEPENTRY_WFI              ((uint8_t)0x01)                                                                     
#define PWR_SLEEPENTRY_WFE              ((uint8_t)0x02)                                                                     
   
      
    

                                                      
      
    
#define PWR_STOPENTRY_WFI               ((uint8_t)0x01)                                                                   
#define PWR_STOPENTRY_WFE               ((uint8_t)0x02)                                                                   
   
      
    


                                                                
      
    
#define PWR_EXTI_LINE_PVD  ((uint32_t)0x00010000)                                                                    
   
      
    

                                                    
      
    
#define PWR_EVENT_LINE_PVD  ((uint32_t)0x00010000)                                                       
   
      
    

   
      
    

                                                                                
                                                      
      
    

                                                            
                                                 
                                                                
                                                                                    
                                                      
                                                                                    
                                                      
                                                                                    
                                                      
                                                                                    
                                                      
                                                                                    
                                                      
                                                                            
                                          
                                                                                                        
                                                                                                        
                                                   
                                                                                              
                                             
                                                                                                  
                                                 
                                                                                        
                                                                            
                                                                                                     
                                                                                                     
                                                                                                      
                                                               
                                                                                                                   
                                                                                                 
                 
                                                                                                                   
                                                                                                    
        
                                                                                                                 
                                                      
                                                                                                                 
                                                      
   
                                                      
    
#define __HAL_PWR_GET_FLAG(__FLAG__)  ( ((((uint8_t)(__FLAG__)) >> 5U) == 1)  ?\
                                      (PWR->SR1 & (1U << ((__FLAG__) & 31U))) :\
                                      (PWR->SR2 & (1U << ((__FLAG__) & 31U))) )

                                      
                                                 
                                                               
                                                                                    
                                                      
                                                                                    
                                                      
                                                                                    
                                                      
                                                                                    
                                                      
                                                                                    
                                                      
                                                                        
                                                                            
                                          
                
    
#define __HAL_PWR_CLEAR_FLAG(__FLAG__)   ( (((uint8_t)(__FLAG__)) == PWR_FLAG_WU) ?\
                                         (PWR->SCR  = (__FLAG__)) :\
                                         (PWR->SCR = (1U << ((__FLAG__) & 31U))) )
   
                                                  
                
    
#define __HAL_PWR_PVD_EXTI_ENABLE_IT()   SET_BIT(EXTI->IMR1, PWR_EXTI_LINE_PVD)

   
                                                   
                
    
#define __HAL_PWR_PVD_EXTI_DISABLE_IT()  CLEAR_BIT(EXTI->IMR1, PWR_EXTI_LINE_PVD)

   
                                     
                
    
#define __HAL_PWR_PVD_EXTI_ENABLE_EVENT()   SET_BIT(EXTI->EMR1, PWR_EVENT_LINE_PVD)

   
                                      
                
    
#define __HAL_PWR_PVD_EXTI_DISABLE_EVENT()  CLEAR_BIT(EXTI->EMR1, PWR_EVENT_LINE_PVD)

   
                                                            
                
    
#define __HAL_PWR_PVD_EXTI_ENABLE_RISING_EDGE()   SET_BIT(EXTI->RTSR1, PWR_EXTI_LINE_PVD)

   
                                                             
                
    
#define __HAL_PWR_PVD_EXTI_DISABLE_RISING_EDGE()  CLEAR_BIT(EXTI->RTSR1, PWR_EXTI_LINE_PVD)

   
                                                             
                
    
#define __HAL_PWR_PVD_EXTI_ENABLE_FALLING_EDGE()   SET_BIT(EXTI->FTSR1, PWR_EXTI_LINE_PVD)


   
                                                              
                
    
#define __HAL_PWR_PVD_EXTI_DISABLE_FALLING_EDGE()  CLEAR_BIT(EXTI->FTSR1, PWR_EXTI_LINE_PVD)


   
                                                                       
                
    
#define __HAL_PWR_PVD_EXTI_ENABLE_RISING_FALLING_EDGE()  \
  do {                                                   \
    __HAL_PWR_PVD_EXTI_ENABLE_RISING_EDGE();             \
    __HAL_PWR_PVD_EXTI_ENABLE_FALLING_EDGE();            \
  } while(0)

   
                                                                       
                
    
#define __HAL_PWR_PVD_EXTI_DISABLE_RISING_FALLING_EDGE()  \
  do {                                                    \
    __HAL_PWR_PVD_EXTI_DISABLE_RISING_EDGE();             \
    __HAL_PWR_PVD_EXTI_DISABLE_FALLING_EDGE();            \
  } while(0)

   
                                                                
                
    
#define __HAL_PWR_PVD_EXTI_GENERATE_SWIT() SET_BIT(EXTI->SWIER1, PWR_EXTI_LINE_PVD)

   
                                                                   
                                 
    
#define __HAL_PWR_PVD_EXTI_GET_FLAG()  (EXTI->PR1 & PWR_EXTI_LINE_PVD)

   
                                             
                
    
#define __HAL_PWR_PVD_EXTI_CLEAR_FLAG()  WRITE_REG(EXTI->PR1, PWR_EXTI_LINE_PVD)

   
      
    


                                                                            
                                                        
      
    

#define IS_PWR_PVD_LEVEL(LEVEL) (((LEVEL) == PWR_PVDLEVEL_0) || ((LEVEL) == PWR_PVDLEVEL_1)|| \
                                 ((LEVEL) == PWR_PVDLEVEL_2) || ((LEVEL) == PWR_PVDLEVEL_3)|| \
                                 ((LEVEL) == PWR_PVDLEVEL_4) || ((LEVEL) == PWR_PVDLEVEL_5)|| \
                                 ((LEVEL) == PWR_PVDLEVEL_6) || ((LEVEL) == PWR_PVDLEVEL_7))

#define IS_PWR_PVD_MODE(MODE)  (((MODE) == PWR_PVD_MODE_NORMAL)              ||\
                                ((MODE) == PWR_PVD_MODE_IT_RISING)           ||\
                                ((MODE) == PWR_PVD_MODE_IT_FALLING)          ||\
                                ((MODE) == PWR_PVD_MODE_IT_RISING_FALLING)   ||\
                                ((MODE) == PWR_PVD_MODE_EVENT_RISING)        ||\
                                ((MODE) == PWR_PVD_MODE_EVENT_FALLING)       ||\
                                ((MODE) == PWR_PVD_MODE_EVENT_RISING_FALLING))

#define IS_PWR_REGULATOR(REGULATOR)      (((REGULATOR) == PWR_MAINREGULATOR_ON) || \
                                          ((REGULATOR) == PWR_LOWPOWERREGULATOR_ON))

#define IS_PWR_SLEEP_ENTRY(ENTRY) (((ENTRY) == PWR_SLEEPENTRY_WFI) || ((ENTRY) == PWR_SLEEPENTRY_WFE))

#define IS_PWR_STOP_ENTRY(ENTRY) (((ENTRY) == PWR_STOPENTRY_WFI) || ((ENTRY) == PWR_STOPENTRY_WFE) )

   
      
    

                                     
#include "stm32l4xx_hal_pwr_ex.h"

                                                                                

                                                             
      
    

                                                                                            
      
    

                                                                                  
void HAL_PWR_DeInit(void);
void HAL_PWR_EnableBkUpAccess(void);
void HAL_PWR_DisableBkUpAccess(void);

   
      
    

                                                                          
      
    

                                                                                  
HAL_StatusTypeDef HAL_PWR_ConfigPVD(PWR_PVDTypeDef *sConfigPVD);
void HAL_PWR_EnablePVD(void);
void HAL_PWR_DisablePVD(void);


                                                                                
void HAL_PWR_EnableWakeUpPin(uint32_t WakeUpPinPolarity);
void HAL_PWR_DisableWakeUpPin(uint32_t WakeUpPinx);

                                                                                
void HAL_PWR_EnterSLEEPMode(uint32_t Regulator, uint8_t SLEEPEntry);
void HAL_PWR_EnterSTOPMode(uint32_t Regulator, uint8_t STOPEntry);
void HAL_PWR_EnterSTANDBYMode(void);

void HAL_PWR_EnableSleepOnExit(void);
void HAL_PWR_DisableSleepOnExit(void);
void HAL_PWR_EnableSEVOnPend(void);
void HAL_PWR_DisableSEVOnPend(void);

void HAL_PWR_PVDCallback(void);


   
      
    

   
      
    

   
      
    

   
      
    

#ifdef __cplusplus
}
#endif


#endif                          
