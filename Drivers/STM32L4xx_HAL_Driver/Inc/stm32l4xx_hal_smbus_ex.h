/**
  ******************************************************************************
  * @file    stm32l4xx_hal_smbus_ex.h
  * @author  MCD Application Team
  * @brief   Header file of SMBUS HAL Extended module.
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

                                                                                
#ifndef STM32L4xx_HAL_SMBUS_EX_H
#define STM32L4xx_HAL_SMBUS_EX_H

#ifdef __cplusplus
extern "C" {
#endif

                                                                                
#include "stm32l4xx_hal_def.h"

                                    
      
    

                       
      
    

                                                                                
                                                                                
                                                                          
      
    

                                                                
      
    
#define SMBUS_FMP_NOT_SUPPORTED           0xAAAA0000U                                                                               
#define SMBUS_FASTMODEPLUS_PB6            SYSCFG_CFGR1_I2C_PB6_FMP                                                                  
#define SMBUS_FASTMODEPLUS_PB7            SYSCFG_CFGR1_I2C_PB7_FMP                                                                  
#if defined(SYSCFG_CFGR1_I2C_PB8_FMP)
#define SMBUS_FASTMODEPLUS_PB8            SYSCFG_CFGR1_I2C_PB8_FMP                                                                  
#define SMBUS_FASTMODEPLUS_PB9            SYSCFG_CFGR1_I2C_PB9_FMP                                                                  
#else
#define SMBUS_FASTMODEPLUS_PB8            (uint32_t)(0x00000010U | SMBUS_FMP_NOT_SUPPORTED)                                           
#define SMBUS_FASTMODEPLUS_PB9            (uint32_t)(0x00000012U | SMBUS_FMP_NOT_SUPPORTED)                                           
#endif                               
#define SMBUS_FASTMODEPLUS_I2C1           SYSCFG_CFGR1_I2C1_FMP                                                                     
#if defined(SYSCFG_CFGR1_I2C2_FMP)
#define SMBUS_FASTMODEPLUS_I2C2           SYSCFG_CFGR1_I2C2_FMP                                                                     
#else
#define SMBUS_FASTMODEPLUS_I2C2           (uint32_t)(0x00000200U | SMBUS_FMP_NOT_SUPPORTED)                                           
#endif                            
#define SMBUS_FASTMODEPLUS_I2C3           SYSCFG_CFGR1_I2C3_FMP                                                                     
#if defined(SYSCFG_CFGR1_I2C4_FMP)
#define SMBUS_FASTMODEPLUS_I2C4           SYSCFG_CFGR1_I2C4_FMP                                                                     
#else
#define SMBUS_FASTMODEPLUS_I2C4           (uint32_t)(0x00000800U | SMBUS_FMP_NOT_SUPPORTED)                                           
#endif                            
   
      
    

   
      
    

                                                                                
                                                                    
      
    

   
      
    

                                                                                
                                                                            
      
    

                                                                       
      
    
                                                                                  
HAL_StatusTypeDef HAL_SMBUSEx_EnableWakeUp(SMBUS_HandleTypeDef *hsmbus);
HAL_StatusTypeDef HAL_SMBUSEx_DisableWakeUp(SMBUS_HandleTypeDef *hsmbus);
   
      
    

                                                                          
      
    
void HAL_SMBUSEx_EnableFastModePlus(uint32_t ConfigFastModePlus);
void HAL_SMBUSEx_DisableFastModePlus(uint32_t ConfigFastModePlus);
   
      
    

   
      
    

                                                                                
                                                                        
      
    

   
      
    

                                                                                
                                                                 
      
    
#define IS_SMBUS_FASTMODEPLUS(__CONFIG__) ((((__CONFIG__) & SMBUS_FMP_NOT_SUPPORTED) != SMBUS_FMP_NOT_SUPPORTED) && \
                                           ((((__CONFIG__) & (SMBUS_FASTMODEPLUS_PB6))  == SMBUS_FASTMODEPLUS_PB6)  || \
                                            (((__CONFIG__) & (SMBUS_FASTMODEPLUS_PB7))  == SMBUS_FASTMODEPLUS_PB7)  || \
                                            (((__CONFIG__) & (SMBUS_FASTMODEPLUS_PB8))  == SMBUS_FASTMODEPLUS_PB8)  || \
                                            (((__CONFIG__) & (SMBUS_FASTMODEPLUS_PB9))  == SMBUS_FASTMODEPLUS_PB9)  || \
                                            (((__CONFIG__) & (SMBUS_FASTMODEPLUS_I2C1)) == SMBUS_FASTMODEPLUS_I2C1) || \
                                            (((__CONFIG__) & (SMBUS_FASTMODEPLUS_I2C2)) == SMBUS_FASTMODEPLUS_I2C2) || \
                                            (((__CONFIG__) & (SMBUS_FASTMODEPLUS_I2C3)) == SMBUS_FASTMODEPLUS_I2C3) || \
                                            (((__CONFIG__) & (SMBUS_FASTMODEPLUS_I2C4)) == SMBUS_FASTMODEPLUS_I2C4)))
   
      
    

                                                                                
                                                                        
      
    
                                                                    
   
      
    

   
      
    

   
      
    

#ifdef __cplusplus
}
#endif

#endif                               
