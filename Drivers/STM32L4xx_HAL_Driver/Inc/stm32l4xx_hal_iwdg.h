/**
  ******************************************************************************
  * @file    stm32l4xx_hal_iwdg.h
  * @author  MCD Application Team
  * @brief   Header file of IWDG HAL module.
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

                                                                                
#ifndef STM32L4xx_HAL_IWDG_H
#define STM32L4xx_HAL_IWDG_H

#ifdef __cplusplus
extern "C" {
#endif

                                                                                
#include "stm32l4xx_hal_def.h"

                                    
      
    

                       
      
    

                                                                                
                                                     
      
    

   
                                          
    
typedef struct
{
  uint32_t Prescaler;                                        
                                                                                   

  uint32_t Reload;                                                       
                                                                                                         

  uint32_t Window;                                                                        
                                                                                                         

} IWDG_InitTypeDef;

   
                                            
    
typedef struct
{
  IWDG_TypeDef                 *Instance;                                  

  IWDG_InitTypeDef             Init;                                       
} IWDG_HandleTypeDef;


   
      
    

                                                                                
                                                             
      
    

                                           
      
    
#define IWDG_PRESCALER_4                0x00000000u                                                                      
#define IWDG_PRESCALER_8                IWDG_PR_PR_0                                                                     
#define IWDG_PRESCALER_16               IWDG_PR_PR_1                                                                     
#define IWDG_PRESCALER_32               (IWDG_PR_PR_1 | IWDG_PR_PR_0)                                                    
#define IWDG_PRESCALER_64               IWDG_PR_PR_2                                                                     
#define IWDG_PRESCALER_128              (IWDG_PR_PR_2 | IWDG_PR_PR_0)                                                    
#define IWDG_PRESCALER_256              (IWDG_PR_PR_2 | IWDG_PR_PR_1)                                                    
   
      
    

                                                   
      
    
#define IWDG_WINDOW_DISABLE             IWDG_WINR_WIN
   
      
    

   
      
    

                                                                                
                                                       
      
    

   
                                       
                                   
                
    
#define __HAL_IWDG_START(__HANDLE__)                WRITE_REG((__HANDLE__)->Instance->KR, IWDG_KEY_ENABLE)

   
                                                                         
                                                                                 
                                   
                
    
#define __HAL_IWDG_RELOAD_COUNTER(__HANDLE__)       WRITE_REG((__HANDLE__)->Instance->KR, IWDG_KEY_RELOAD)

   
      
    

                                                                                
                                                              
      
    

                                                                               
      
    
                                                                                
HAL_StatusTypeDef     HAL_IWDG_Init(IWDG_HandleTypeDef *hiwdg);
   
      
    

                                                                   
      
    
                                                                                
HAL_StatusTypeDef     HAL_IWDG_Refresh(IWDG_HandleTypeDef *hiwdg);
   
      
    

   
      
    

                                                                                
                                                           
      
    

   
                                     
    
#define IWDG_KEY_RELOAD                 0x0000AAAAu                                      
#define IWDG_KEY_ENABLE                 0x0000CCCCu                                      
#define IWDG_KEY_WRITE_ACCESS_ENABLE    0x00005555u                                      
#define IWDG_KEY_WRITE_ACCESS_DISABLE   0x00000000u                                      

   
      
    

                                                                                
                                                     
      
    

   
                                                                             
                                   
                
    
#define IWDG_ENABLE_WRITE_ACCESS(__HANDLE__)  WRITE_REG((__HANDLE__)->Instance->KR, IWDG_KEY_WRITE_ACCESS_ENABLE)

   
                                                                              
                                   
                
    
#define IWDG_DISABLE_WRITE_ACCESS(__HANDLE__) WRITE_REG((__HANDLE__)->Instance->KR, IWDG_KEY_WRITE_ACCESS_DISABLE)

   
                                       
                                               
                
    
#define IS_IWDG_PRESCALER(__PRESCALER__)      (((__PRESCALER__) == IWDG_PRESCALER_4)  || \
                                               ((__PRESCALER__) == IWDG_PRESCALER_8)  || \
                                               ((__PRESCALER__) == IWDG_PRESCALER_16) || \
                                               ((__PRESCALER__) == IWDG_PRESCALER_32) || \
                                               ((__PRESCALER__) == IWDG_PRESCALER_64) || \
                                               ((__PRESCALER__) == IWDG_PRESCALER_128)|| \
                                               ((__PRESCALER__) == IWDG_PRESCALER_256))

   
                                    
                                         
                
    
#define IS_IWDG_RELOAD(__RELOAD__)            ((__RELOAD__) <= IWDG_RLR_RL)

   
                                    
                                         
                
    
#define IS_IWDG_WINDOW(__WINDOW__)            ((__WINDOW__) <= IWDG_WINR_WIN)


   
      
    

   
      
    

   
      
    


#ifdef __cplusplus
}
#endif

#endif                           
