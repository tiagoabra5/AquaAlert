/**
  ******************************************************************************
  * @file    stm32l4xx_ll_utils.h
  * @author  MCD Application Team
  * @brief   Header file of UTILS LL module.
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
  @verbatim
  ==============================================================================
                     ##### How to use this driver #####
  ==============================================================================
    [..]
    The LL UTILS driver contains a set of generic APIs that can be
    used by user:
      (+) Device electronic signature
      (+) Timing functions
      (+) PLL configuration functions

  @endverbatim
  ******************************************************************************
  */

                                                                                
#ifndef STM32L4xx_LL_UTILS_H
#define STM32L4xx_LL_UTILS_H

#ifdef __cplusplus
extern "C" {
#endif

                                                                                
#include "stm32l4xx.h"

                                   
      
    

                            
      
    

                                                                                
                                                                                

                                                                                
                                                                
      
    

                                        
#define LL_MAX_DELAY                  0xFFFFFFFFU

   
                                                
   
#define UID_BASE_ADDRESS              UID_BASE

   
                                               
   
#define FLASHSIZE_BASE_ADDRESS        FLASHSIZE_BASE

   
                                            
   
#define PACKAGE_BASE_ADDRESS          PACKAGE_BASE

   
      
    

                                                                                
                                                          
      
    
   
      
    
                                                                                
                                                        
      
    
   
                                          
    
typedef struct
{
  uint32_t PLLM;                                                
                                                                                

                                                                                      
                                                              

  uint32_t PLLN;                                                       
                                                                                              

                                                                                      
                                                              

  uint32_t PLLR;                                           
                                                                                

                                                                                      
                                                              
} LL_UTILS_PLLInitTypeDef;

   
                                                                                    
    
typedef struct
{
  uint32_t AHBCLKDivider;                                                                                                 
                                                                                                 

                                                                                                     
                                                                        

  uint32_t APB1CLKDivider;                                                                                             
                                                                                               

                                                                                                     
                                                                         

  uint32_t APB2CLKDivider;                                                                                             
                                                                                               

                                                                                                     
                                                                         

} LL_UTILS_ClkInitTypeDef;

   
      
    

                                                                                
                                                                  
      
    

                                                       
      
    
#define LL_UTILS_HSEBYPASS_OFF        0x00000000U                                                       
#define LL_UTILS_HSEBYPASS_ON         0x00000001U                                                       
   
      
    

                                               
      
    
#define LL_UTILS_PACKAGETYPE_LQFP64          0x00000000U                                                 
#define LL_UTILS_PACKAGETYPE_WLCSP64         0x00000001U                                                 
#define LL_UTILS_PACKAGETYPE_LQFP100         0x00000002U                                                 
#define LL_UTILS_PACKAGETYPE_BGA132          0x00000003U                                                 
#define LL_UTILS_PACKAGETYPE_LQFP144_CSP72   0x00000004U                                                 
#define LL_UTILS_PACKAGETYPE_UFQFPN32        0x00000008U                                                 
#define LL_UTILS_PACKAGETYPE_UFQFPN48        0x0000000AU                                                 
#define LL_UTILS_PACKAGETYPE_LQFP48          0x0000000BU                                                 
#define LL_UTILS_PACKAGETYPE_WLCSP49         0x0000000CU                                                 
#define LL_UTILS_PACKAGETYPE_UFBGA64         0x0000000DU                                                 
#define LL_UTILS_PACKAGETYPE_UFBGA100        0x0000000EU                                                 
#define LL_UTILS_PACKAGETYPE_UFBGA169_CSP115 0x00000010U                                                 
#define LL_UTILS_PACKAGETYPE_LQFP100_DSI     0x00000012U                                                 
#define LL_UTILS_PACKAGETYPE_WLCSP144_DSI    0x00000013U                                                 
#define LL_UTILS_PACKAGETYPE_UFBGA144_DSI    0x00000013U                                                 
#define LL_UTILS_PACKAGETYPE_UFBGA169_DSI    0x00000014U                                                 
#define LL_UTILS_PACKAGETYPE_LQFP144_DSI     0x00000015U                                                 
   
      
    

   
      
    

                                                                                

                                                                                
                                                                  
      
    

                                                                              
      
    

   
                                                                            
                                                                               
    
__STATIC_INLINE uint32_t LL_GetUID_Word0(void)
{
  return (uint32_t)(READ_REG(*((uint32_t *)UID_BASE_ADDRESS)));
}

   
                                                                            
                                                                              
    
__STATIC_INLINE uint32_t LL_GetUID_Word1(void)
{
  return (uint32_t)(READ_REG(*((uint32_t *)(UID_BASE_ADDRESS + 4U))));
}

   
                                                                            
                                                                   
    
__STATIC_INLINE uint32_t LL_GetUID_Word2(void)
{
  return (uint32_t)(READ_REG(*((uint32_t *)(UID_BASE_ADDRESS + 8U))));
}

   
                                 
                                                                                    
                                                                  
                                               
    
__STATIC_INLINE uint32_t LL_GetFlashSize(void)
{
  return (uint32_t)(READ_REG(*((uint32_t *)FLASHSIZE_BASE_ADDRESS)) & 0xFFFFU);
}

   
                            
                                                              
                                                     
                                                      
                                                     
                                                            
                                                       
                                                       
                                                     
                                                      
                                                      
                                                       
                                                       
                                                          
                                                           
                                                           
                                                           
                                                          
   
                                                 
    
__STATIC_INLINE uint32_t LL_GetPackageType(void)
{
  return (uint32_t)(READ_REG(*((uint32_t *)PACKAGE_BASE_ADDRESS)) & 0x1FU);
}

   
      
    

                                     
      
    

   
                                                                                  
                                                                                             
                                                                                
                                                                                                
                                         
                
    
__STATIC_INLINE void LL_InitTick(uint32_t HCLKFrequency, uint32_t Ticks)
{
                                                                
  SysTick->LOAD  = (uint32_t)((HCLKFrequency / Ticks) - 1UL);                           
  SysTick->VAL   = 0UL;                                                                           
  SysTick->CTRL  = SysTick_CTRL_CLKSOURCE_Msk |
                   SysTick_CTRL_ENABLE_Msk;                                                 
}

void        LL_Init1msTick(uint32_t HCLKFrequency);
void        LL_mDelay(uint32_t Delay);

   
      
    

                                    
      
    

void        LL_SetSystemCoreClock(uint32_t HCLKFrequency);
ErrorStatus LL_SetFlashLatency(uint32_t HCLKFrequency);
ErrorStatus LL_PLL_ConfigSystemClock_MSI(LL_UTILS_PLLInitTypeDef *UTILS_PLLInitStruct,
                                         LL_UTILS_ClkInitTypeDef *UTILS_ClkInitStruct);
ErrorStatus LL_PLL_ConfigSystemClock_HSI(LL_UTILS_PLLInitTypeDef *UTILS_PLLInitStruct,
                                         LL_UTILS_ClkInitTypeDef *UTILS_ClkInitStruct);
ErrorStatus LL_PLL_ConfigSystemClock_HSE(uint32_t HSEFrequency, uint32_t HSEBypass,
                                         LL_UTILS_PLLInitTypeDef *UTILS_PLLInitStruct, LL_UTILS_ClkInitTypeDef *UTILS_ClkInitStruct);

   
      
    

   
      
    

   
      
    

   
      
    

#ifdef __cplusplus
}
#endif

#endif                           
