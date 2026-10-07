/**
  ******************************************************************************
  * @file    stm32l4xx_hal_dfsdm_ex.h
  * @author  MCD Application Team
  * @brief   Header file of DFSDM HAL extended module.
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

                                                                                
#ifndef STM32L4xx_HAL_DFSDM_EX_H
#define STM32L4xx_HAL_DFSDM_EX_H

#ifdef __cplusplus
extern "C" {
#endif

#if defined(STM32L4R5xx) || defined(STM32L4R7xx) || defined(STM32L4R9xx) || defined(STM32L4S5xx) || defined(STM32L4S7xx) || defined(STM32L4S9xx) || \
    defined(STM32L4P5xx) || defined(STM32L4Q5xx)

                                                                                
#include "stm32l4xx_hal_def.h"

                                    
      
    

                       
      
    

                                                                                
                                                                                
                                                                                
                                                                                

                                                                            
      
    

                                                                                              
      
    

HAL_StatusTypeDef HAL_DFDSMEx_ChannelSetPulsesSkipping(DFSDM_Channel_HandleTypeDef *hdfsdm_channel, uint32_t PulsesValue);
HAL_StatusTypeDef HAL_DFDSMEx_ChannelGetPulsesSkipping(const DFSDM_Channel_HandleTypeDef *hdfsdm_channel, uint32_t *PulsesValue);

   
      
    

   
      
    

                                                                                

                                                                    
      
    

#define IS_DFSDM_CHANNEL_SKIPPING_VALUE(VALUE)   ((VALUE) < 64U)

   
      
    

   
      
    

   
      
    

#endif                                                                                                                           

#ifdef __cplusplus
}
#endif

#endif                               
