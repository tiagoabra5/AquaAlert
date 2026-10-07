/**
  ******************************************************************************
  * @file    stm32l4xx_hal_mmc_ex.h
  * @author  MCD Application Team
  * @brief   Header file of SD HAL extended module.
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

                                                                                
#ifndef STM32L4xx_HAL_MMC_EX_H
#define STM32L4xx_HAL_MMC_EX_H

#ifdef __cplusplus
extern "C" {
#endif

#if defined(STM32L4P5xx) || defined(STM32L4Q5xx) || defined(STM32L4R5xx) || defined(STM32L4R7xx) || defined(STM32L4R9xx) || defined(STM32L4S5xx) || defined(STM32L4S7xx) || defined(STM32L4S9xx)

                                                                                
#include "stm32l4xx_hal_def.h"

                                    
      
    

                     
                                        
      
    

                                                                                
                                    
      
    

                                           
      
    
typedef enum
{
  MMC_DMA_BUFFER0      = 0x00U,                                                 
  MMC_DMA_BUFFER1      = 0x01U,                                                 

} HAL_MMCEx_DMABuffer_MemoryTypeDef;


   
      
    

   
      
    
                                                                                
                                                                                
                                                                                
                                                               
      
    

                                                                   
      
    
HAL_StatusTypeDef HAL_MMCEx_ConfigDMAMultiBuffer(MMC_HandleTypeDef *hmmc, uint32_t *pDataBuffer0,
                                                 uint32_t *pDataBuffer1, uint32_t BufferSize);
HAL_StatusTypeDef HAL_MMCEx_ReadBlocksDMAMultiBuffer(MMC_HandleTypeDef *hmmc, uint32_t BlockAdd,
                                                     uint32_t NumberOfBlocks);
HAL_StatusTypeDef HAL_MMCEx_WriteBlocksDMAMultiBuffer(MMC_HandleTypeDef *hmmc, uint32_t BlockAdd,
                                                      uint32_t NumberOfBlocks);
HAL_StatusTypeDef HAL_MMCEx_ChangeDMABuffer(MMC_HandleTypeDef *hmmc, HAL_MMCEx_DMABuffer_MemoryTypeDef Buffer,
                                            uint32_t *pDataBuffer);

void HAL_MMCEx_Read_DMADoubleBuffer0CpltCallback(MMC_HandleTypeDef *hmmc);
void HAL_MMCEx_Read_DMADoubleBuffer1CpltCallback(MMC_HandleTypeDef *hmmc);
void HAL_MMCEx_Write_DMADoubleBuffer0CpltCallback(MMC_HandleTypeDef *hmmc);
void HAL_MMCEx_Write_DMADoubleBuffer1CpltCallback(MMC_HandleTypeDef *hmmc);

   
      
    

   
      
    

                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                

   
      
    

   
      
    
#endif                                                                                                                           

#ifdef __cplusplus
}
#endif


#endif                            
