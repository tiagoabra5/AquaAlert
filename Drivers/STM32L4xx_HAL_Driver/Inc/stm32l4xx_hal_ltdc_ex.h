/**
  ******************************************************************************
  * @file    stm32l4xx_hal_ltdc_ex.h
  * @author  MCD Application Team
  * @brief   Header file of LTDC HAL Extension module.
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

                                                                                
#ifndef STM32L4xx_HAL_LTDC_EX_H
#define STM32L4xx_HAL_LTDC_EX_H

#ifdef __cplusplus
extern "C" {
#endif

                                                                                
#include "stm32l4xx_hal_def.h"

#if defined(HAL_LTDC_MODULE_ENABLED) && defined(HAL_DSI_MODULE_ENABLED)

#if defined (LTDC) && defined (DSI)

#include "stm32l4xx_hal_dsi.h"

                                    
      
    

                      
      
    

                                                                                
                                                                                
                                                                                
                                                                                
                                         
      
    

                                                
      
    
HAL_StatusTypeDef HAL_LTDCEx_StructInitFromVideoConfig(LTDC_HandleTypeDef *hltdc, DSI_VidCfgTypeDef *VidCfg);
HAL_StatusTypeDef HAL_LTDCEx_StructInitFromAdaptedCommandConfig(LTDC_HandleTypeDef *hltdc, DSI_CmdCfgTypeDef *CmdCfg);
   
      
    

   
      
    

                                                                                
                                                                                
                                                                                
                                                                                
                                                                                

   
      
    

   
      
    

#endif                  

#endif                                                        

#ifdef __cplusplus
}
#endif

#endif                              
