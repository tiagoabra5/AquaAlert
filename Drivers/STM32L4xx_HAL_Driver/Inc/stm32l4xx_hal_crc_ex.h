/**
  ******************************************************************************
  * @file    stm32l4xx_hal_crc_ex.h
  * @author  MCD Application Team
  * @brief   Header file of CRC HAL extended module.
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

                                                                                
#ifndef STM32L4xx_HAL_CRC_EX_H
#define STM32L4xx_HAL_CRC_EX_H

#ifdef __cplusplus
extern "C" {
#endif

                                                                                
#include "stm32l4xx_hal_def.h"

                                    
      
    

                     
      
    

                                                                                
                                                                                
                                                                      
      
    

                                                                   
      
    
#define CRC_INPUTDATA_INVERSION_NONE               0x00000000U                                               
#define CRC_INPUTDATA_INVERSION_BYTE               CRC_CR_REV_IN_0                                           
#define CRC_INPUTDATA_INVERSION_HALFWORD           CRC_CR_REV_IN_1                                           
#define CRC_INPUTDATA_INVERSION_WORD               CRC_CR_REV_IN                                             
   
      
    

                                                                     
      
    
#define CRC_OUTPUTDATA_INVERSION_DISABLE         0x00000000U                                             
#define CRC_OUTPUTDATA_INVERSION_ENABLE          CRC_CR_REV_OUT                                          
   
      
    

   
      
    

                                                                                
                                                                
      
    

   
                                   
                                 
                
    
#define  __HAL_CRC_OUTPUTREVERSAL_ENABLE(__HANDLE__) ((__HANDLE__)->Instance->CR |= CRC_CR_REV_OUT)

   
                                     
                                 
                
    
#define __HAL_CRC_OUTPUTREVERSAL_DISABLE(__HANDLE__) ((__HANDLE__)->Instance->CR &= ~(CRC_CR_REV_OUT))

   
                                          
                                 
                                                        
                
    
#define __HAL_CRC_POLYNOMIAL_CONFIG(__HANDLE__, __POLYNOMIAL__) ((__HANDLE__)->Instance->POL = (__POLYNOMIAL__))

   
      
    

                                                                            
                                                              
      
    

#define IS_CRC_INPUTDATA_INVERSION_MODE(MODE)     (((MODE) == CRC_INPUTDATA_INVERSION_NONE)     || \
                                                   ((MODE) == CRC_INPUTDATA_INVERSION_BYTE)     || \
                                                   ((MODE) == CRC_INPUTDATA_INVERSION_HALFWORD) || \
                                                   ((MODE) == CRC_INPUTDATA_INVERSION_WORD))

#define IS_CRC_OUTPUTDATA_INVERSION_MODE(MODE)    (((MODE) == CRC_OUTPUTDATA_INVERSION_DISABLE) || \
                                                   ((MODE) == CRC_OUTPUTDATA_INVERSION_ENABLE))

   
      
    

                                                                                

                                        
      
    

                                               
      
    
                                                                                
HAL_StatusTypeDef HAL_CRCEx_Polynomial_Set(CRC_HandleTypeDef *hcrc, uint32_t Pol, uint32_t PolyLength);
HAL_StatusTypeDef HAL_CRCEx_Input_Data_Reverse(CRC_HandleTypeDef *hcrc, uint32_t InputReverseMode);
HAL_StatusTypeDef HAL_CRCEx_Output_Data_Reverse(CRC_HandleTypeDef *hcrc, uint32_t OutputReverseMode);

   
      
    

   
      
    

   
      
    

   
      
    

#ifdef __cplusplus
}
#endif

#endif                             
