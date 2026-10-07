/**
  ******************************************************************************
  * @file    stm32l4xx_hal_firewall.h
  * @author  MCD Application Team
  * @brief   Header file of FIREWALL HAL module.
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

                                                                                
#ifndef STM32L4xx_HAL_FIREWALL_H
#define STM32L4xx_HAL_FIREWALL_H

#ifdef __cplusplus
 extern "C" {
#endif

                                                                                
#include "stm32l4xx_hal_def.h"

                                    
      
    

                                  
      
    

                                                                                
                                                             
      
    

   
                                                       
    
typedef struct
{
  uint32_t CodeSegmentStartAddress;                                                                                                
                                                                                                                     

  uint32_t CodeSegmentLength;                                                                                                        
                                                                                                                         

  uint32_t NonVDataSegmentStartAddress;                                                                                                
                                                                                                                              

  uint32_t NonVDataSegmentLength;                                                                                                        
                                                                                                                                  

  uint32_t VDataSegmentStartAddress;                                                                                                    
                                                                                                                        

  uint32_t VDataSegmentLength;                                                                                                       
                                                                                                                                 

  uint32_t VolatileDataExecution;                                                                                               
                                                                                                                            
                                                                                                                         

  uint32_t VolatileDataShared;                                                                                                         
                                                                               
                                                                                                                     

}FIREWALL_InitTypeDef;


   
      
    


                                                                                
                                                                     
      
    

                                                                                                
      
    
#define FIREWALL_VOLATILEDATA_NOT_EXECUTABLE                 ((uint32_t)0x0000)
#define FIREWALL_VOLATILEDATA_EXECUTABLE                     ((uint32_t)FW_CR_VDE)
   
      
    

                                                                                       
      
    
#define FIREWALL_VOLATILEDATA_NOT_SHARED                ((uint32_t)0x0000)
#define FIREWALL_VOLATILEDATA_SHARED                    ((uint32_t)FW_CR_VDS)
   
      
    

                                                      
      
    
#define FIREWALL_PRE_ARM_RESET                 ((uint32_t)0x0000)
#define FIREWALL_PRE_ARM_SET                   ((uint32_t)FW_CR_FPA)

   
      
    

   
      
    

                                                                            
                                                               
      
    
#define IS_FIREWALL_CODE_SEGMENT_ADDRESS(ADDRESS)        (((ADDRESS) >= FLASH_BASE) && ((ADDRESS) < (FLASH_BASE + FLASH_SIZE)))
#define IS_FIREWALL_CODE_SEGMENT_LENGTH(ADDRESS, LENGTH) (((ADDRESS) + (LENGTH)) <= (FLASH_BASE + FLASH_SIZE))

#define IS_FIREWALL_NONVOLATILEDATA_SEGMENT_ADDRESS(ADDRESS)        (((ADDRESS) >= FLASH_BASE) && ((ADDRESS) < (FLASH_BASE + FLASH_SIZE)))
#define IS_FIREWALL_NONVOLATILEDATA_SEGMENT_LENGTH(ADDRESS, LENGTH) (((ADDRESS) + (LENGTH)) <= (FLASH_BASE + FLASH_SIZE))

#define IS_FIREWALL_VOLATILEDATA_SEGMENT_ADDRESS(ADDRESS)        (((ADDRESS) >= SRAM1_BASE) && ((ADDRESS) < (SRAM1_BASE + SRAM1_SIZE_MAX)))
#define IS_FIREWALL_VOLATILEDATA_SEGMENT_LENGTH(ADDRESS, LENGTH) (((ADDRESS) + (LENGTH)) <= (SRAM1_BASE + SRAM1_SIZE_MAX))


#define IS_FIREWALL_VOLATILEDATA_SHARE(SHARE) (((SHARE) == FIREWALL_VOLATILEDATA_NOT_SHARED) || \
                                               ((SHARE) == FIREWALL_VOLATILEDATA_SHARED))

#define IS_FIREWALL_VOLATILEDATA_EXECUTE(EXECUTE) (((EXECUTE) == FIREWALL_VOLATILEDATA_NOT_EXECUTABLE) || \
                                                   ((EXECUTE) == FIREWALL_VOLATILEDATA_EXECUTABLE))
   
      
    


                                                                                
                                                               
      
    

                                                         
                                                     
    
#define  __HAL_FIREWALL_IS_ENABLED()  HAL_IS_BIT_CLR(SYSCFG->CFGR1, SYSCFG_CFGR1_FWDIS)


                                   
                                                                              
                                                                     
                                                                                     
                                                                           
                                                                                        
                                                                                        
                                                                                      
                                                    
    
#define __HAL_FIREWALL_PREARM_ENABLE()                                                 \
             do {                                                                      \
                  __IO uint32_t tmpreg;                                                \
                  SET_BIT(FIREWALL->CR, FW_CR_FPA) ;                                   \
                                                                                       \
                                                                                       \
                  tmpreg = READ_BIT(FIREWALL->CR, FW_CR_FPA) ;                         \
                  UNUSED(tmpreg);                                                      \
                } while(0)



                                    
                                                                              
                                                                      
                                                                                      
                                                                           
                                                                                        
                                                                                        
                                                                                      
                                                    
    
#define __HAL_FIREWALL_PREARM_DISABLE()                                                \
             do {                                                                      \
                  __IO uint32_t tmpreg;                                                \
                  CLEAR_BIT(FIREWALL->CR, FW_CR_FPA) ;                                 \
                                                                                       \
                                                                                       \
                  tmpreg = READ_BIT(FIREWALL->CR, FW_CR_FPA) ;                         \
                  UNUSED(tmpreg);                                                      \
                } while(0)

                                                           
                                                                                     
                                                                                              
                                                                                  
                                                                                        
                                                                                        
                                                                                      
                                                    
    
#define __HAL_FIREWALL_VOLATILEDATA_SHARED_ENABLE()                                    \
             do {                                                                      \
                  __IO uint32_t tmpreg;                                                \
                  SET_BIT(FIREWALL->CR, FW_CR_VDS) ;                                   \
                                                                                       \
                                                                                       \
                  tmpreg = READ_BIT(FIREWALL->CR, FW_CR_VDS) ;                         \
                  UNUSED(tmpreg);                                                      \
                } while(0)

                                                              
                                                                                      
                                                                                      
                                                                                    
                                                                                  
                                                                                        
                                                                                        
                                                                                      
                                                    
    
#define __HAL_FIREWALL_VOLATILEDATA_SHARED_DISABLE()                                   \
             do {                                                                      \
                  __IO uint32_t tmpreg;                                                \
                  CLEAR_BIT(FIREWALL->CR, FW_CR_VDS) ;                                 \
                                                                                       \
                                                                                       \
                  tmpreg = READ_BIT(FIREWALL->CR, FW_CR_VDS) ;                         \
                  UNUSED(tmpreg);                                                      \
                } while(0)

                                                             
                                                                                          
                                              
                                                                                           
                                                                                        
                             
                                                                                  
                                                                                        
                                                                                        
                                                                                      
                                                    
    
#define __HAL_FIREWALL_VOLATILEDATA_EXECUTION_ENABLE()                                 \
             do {                                                                      \
                  __IO uint32_t tmpreg;                                                \
                  SET_BIT(FIREWALL->CR, FW_CR_VDE) ;                                   \
                                                                                       \
                                                                                       \
                  tmpreg = READ_BIT(FIREWALL->CR, FW_CR_VDE) ;                         \
                  UNUSED(tmpreg);                                                      \
                } while(0)

                                                                
                                                                                          
                                              
                                                                                              
                                                                                  
                                                                                        
                                                                                        
                                                                                      
                                                    
    
#define __HAL_FIREWALL_VOLATILEDATA_EXECUTION_DISABLE()                                \
             do {                                                                      \
                  __IO uint32_t tmpreg;                                                \
                  CLEAR_BIT(FIREWALL->CR, FW_CR_VDE) ;                                 \
                                                                                       \
                                                                                       \
                  tmpreg = READ_BIT(FIREWALL->CR, FW_CR_VDE) ;                         \
                  UNUSED(tmpreg);                                                      \
                } while(0)


                                                                    
                                                                                  
                                                                                        
                                                                                        
                                                                                      
                                                    
                                                   
    
#define __HAL_FIREWALL_GET_VOLATILEDATA_SHARED() ((FIREWALL->CR & FW_CR_VDS) == FW_CR_VDS)

                                                                                 
                                                                                  
                                                                                        
                                                                                        
                                                                                      
                                                    
                                                   
    
#define __HAL_FIREWALL_GET_VOLATILEDATA_EXECUTION() ((FIREWALL->CR & FW_CR_VDE) == FW_CR_VDE)

                                                                
                                                                                  
                                                                                        
                                                                                        
                                                                                      
                                                    
                                                   
    
#define __HAL_FIREWALL_GET_PREARM() ((FIREWALL->CR & FW_CR_FPA) == FW_CR_FPA)


   
      
    

                                                                                

                                                                       
      
    

                                                                           
                                                        
      
    

                                                              
HAL_StatusTypeDef HAL_FIREWALL_Config(FIREWALL_InitTypeDef * fw_init);
void HAL_FIREWALL_GetConfig(FIREWALL_InitTypeDef * fw_config);
void HAL_FIREWALL_EnableFirewall(void);
void HAL_FIREWALL_EnablePreArmFlag(void);
void HAL_FIREWALL_DisablePreArmFlag(void);

   
      
    

   
      
    

   
      
    

   
      
    

#ifdef __cplusplus
}
#endif

#endif                               
