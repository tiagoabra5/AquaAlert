/**
  ******************************************************************************
  * @file    stm32l4xx_hal_sai_ex.h
  * @author  MCD Application Team
  * @brief   Header file of SAI HAL extended module.
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

                                                                                
#ifndef STM32L4xx_HAL_SAI_EX_H
#define STM32L4xx_HAL_SAI_EX_H

#ifdef __cplusplus
extern "C" {
#endif

#if defined(STM32L4R5xx) || defined(STM32L4R7xx) || defined(STM32L4R9xx) || defined(STM32L4S5xx) || defined(STM32L4S7xx) || defined(STM32L4S9xx) || \
    defined(STM32L4P5xx) || defined(STM32L4Q5xx)

                                                                                
#include "stm32l4xx_hal_def.h"

                                    
      
    

                     
      
    

                                                                                
                                                       
      
    

   
                                                     
    
typedef struct
{
  uint32_t MicPair;                                                          
                                                                                                      

  uint32_t LeftDelay;                                                                          
                                                                                                      

  uint32_t RightDelay;                                                                          
                                                                                                      
} SAIEx_PdmMicDelayParamTypeDef;

   
      
    

                                                                                
                                                                                
                                                                                
                                                                          
      
    

                                                                            
      
    
HAL_StatusTypeDef HAL_SAIEx_ConfigPdmMicDelay(const SAI_HandleTypeDef *hsai,
                                              const SAIEx_PdmMicDelayParamTypeDef *pdmMicDelay);
   
      
    

   
      
    

                                                                                
                                                                  
      
    
#define IS_SAI_PDM_MIC_DELAY(VALUE)   ((VALUE) <= 7U)
   
      
    

   
      
    

   
      
    

#endif                                                                                                
                                

#ifdef __cplusplus
}
#endif

#endif                             

