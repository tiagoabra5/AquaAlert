/**
  ******************************************************************************
  * @file    stm32l4xx_hal_sram.h
  * @author  MCD Application Team
  * @brief   Header file of SRAM HAL module.
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

                                                                                
#ifndef STM32L4xx_HAL_SRAM_H
#define STM32L4xx_HAL_SRAM_H

#ifdef __cplusplus
extern "C" {
#endif

#if defined(FMC_BANK1)

                                                                                
#include "stm32l4xx_ll_fmc.h"

                                    
      
    
                    
      
    

                                                                                

                                                     
      
    
   
                                                
    
typedef enum
{
  HAL_SRAM_STATE_RESET     = 0x00U,                                                        
  HAL_SRAM_STATE_READY     = 0x01U,                                                        
  HAL_SRAM_STATE_BUSY      = 0x02U,                                                        
  HAL_SRAM_STATE_ERROR     = 0x03U,                                                        
  HAL_SRAM_STATE_PROTECTED = 0x04U                                                         

} HAL_SRAM_StateTypeDef;

   
                                            
    
#if (USE_HAL_SRAM_REGISTER_CALLBACKS == 1)
typedef struct __SRAM_HandleTypeDef
#else
typedef struct
#endif                                       
{
  FMC_NORSRAM_TypeDef           *Instance;                                                      

  FMC_NORSRAM_EXTENDED_TypeDef  *Extended;                                                      

  FMC_NORSRAM_InitTypeDef       Init;                                                           

  HAL_LockTypeDef               Lock;                                                           

  __IO HAL_SRAM_StateTypeDef    State;                                                          

  DMA_HandleTypeDef             *hdma;                                                          

#if (USE_HAL_SRAM_REGISTER_CALLBACKS == 1)
  void (* MspInitCallback)(struct __SRAM_HandleTypeDef *hsram);                                                          
  void (* MspDeInitCallback)(struct __SRAM_HandleTypeDef *hsram);                                                        
  void (* DmaXferCpltCallback)(DMA_HandleTypeDef *hdma);                                                                 
  void (* DmaXferErrorCallback)(DMA_HandleTypeDef *hdma);                                                                
#endif                                       
} SRAM_HandleTypeDef;

#if (USE_HAL_SRAM_REGISTER_CALLBACKS == 1)
   
                                                       
    
typedef enum
{
  HAL_SRAM_MSP_INIT_CB_ID       = 0x00U,                                            
  HAL_SRAM_MSP_DEINIT_CB_ID     = 0x01U,                                            
  HAL_SRAM_DMA_XFER_CPLT_CB_ID  = 0x02U,                                            
  HAL_SRAM_DMA_XFER_ERR_CB_ID   = 0x03U                                             
} HAL_SRAM_CallbackIDTypeDef;

   
                                                
    
typedef void (*pSRAM_CallbackTypeDef)(SRAM_HandleTypeDef *hsram);
typedef void (*pSRAM_DmaCallbackTypeDef)(DMA_HandleTypeDef *hdma);
#endif                                       
   
      
    

                                                                                
                                                                                

                                                       
      
    

                                  
                                  
                
    
#if (USE_HAL_SRAM_REGISTER_CALLBACKS == 1)
#define __HAL_SRAM_RESET_HANDLE_STATE(__HANDLE__)         do {                                             \
                                                               (__HANDLE__)->State = HAL_SRAM_STATE_RESET; \
                                                               (__HANDLE__)->MspInitCallback = NULL;       \
                                                               (__HANDLE__)->MspDeInitCallback = NULL;     \
                                                             } while(0)
#else
#define __HAL_SRAM_RESET_HANDLE_STATE(__HANDLE__) ((__HANDLE__)->State = HAL_SRAM_STATE_RESET)
#endif                                       

   
      
    

                                                                                
                                                               
      
    

                                                                                             
      
    

                                                                                
HAL_StatusTypeDef HAL_SRAM_Init(SRAM_HandleTypeDef *hsram, FMC_NORSRAM_TimingTypeDef *Timing,
                                FMC_NORSRAM_TimingTypeDef *ExtTiming);
HAL_StatusTypeDef HAL_SRAM_DeInit(SRAM_HandleTypeDef *hsram);
void HAL_SRAM_MspInit(SRAM_HandleTypeDef *hsram);
void HAL_SRAM_MspDeInit(SRAM_HandleTypeDef *hsram);

   
      
    

                                                                                        
      
    

                                                                                
HAL_StatusTypeDef HAL_SRAM_Read_8b(SRAM_HandleTypeDef *hsram, uint32_t *pAddress, uint8_t *pDstBuffer,
                                   uint32_t BufferSize);
HAL_StatusTypeDef HAL_SRAM_Write_8b(SRAM_HandleTypeDef *hsram, uint32_t *pAddress, uint8_t *pSrcBuffer,
                                    uint32_t BufferSize);
HAL_StatusTypeDef HAL_SRAM_Read_16b(SRAM_HandleTypeDef *hsram, uint32_t *pAddress, uint16_t *pDstBuffer,
                                    uint32_t BufferSize);
HAL_StatusTypeDef HAL_SRAM_Write_16b(SRAM_HandleTypeDef *hsram, uint32_t *pAddress, uint16_t *pSrcBuffer,
                                     uint32_t BufferSize);
HAL_StatusTypeDef HAL_SRAM_Read_32b(SRAM_HandleTypeDef *hsram, uint32_t *pAddress, uint32_t *pDstBuffer,
                                    uint32_t BufferSize);
HAL_StatusTypeDef HAL_SRAM_Write_32b(SRAM_HandleTypeDef *hsram, uint32_t *pAddress, uint32_t *pSrcBuffer,
                                     uint32_t BufferSize);
HAL_StatusTypeDef HAL_SRAM_Read_DMA(SRAM_HandleTypeDef *hsram, uint32_t *pAddress, uint32_t *pDstBuffer,
                                    uint32_t BufferSize);
HAL_StatusTypeDef HAL_SRAM_Write_DMA(SRAM_HandleTypeDef *hsram, uint32_t *pAddress, uint32_t *pSrcBuffer,
                                     uint32_t BufferSize);

void HAL_SRAM_DMA_XferCpltCallback(DMA_HandleTypeDef *hdma);
void HAL_SRAM_DMA_XferErrorCallback(DMA_HandleTypeDef *hdma);

#if (USE_HAL_SRAM_REGISTER_CALLBACKS == 1)
                                             
HAL_StatusTypeDef HAL_SRAM_RegisterCallback(SRAM_HandleTypeDef *hsram, HAL_SRAM_CallbackIDTypeDef CallbackId,
                                            pSRAM_CallbackTypeDef pCallback);
HAL_StatusTypeDef HAL_SRAM_UnRegisterCallback(SRAM_HandleTypeDef *hsram, HAL_SRAM_CallbackIDTypeDef CallbackId);
HAL_StatusTypeDef HAL_SRAM_RegisterDmaCallback(SRAM_HandleTypeDef *hsram, HAL_SRAM_CallbackIDTypeDef CallbackId,
                                               pSRAM_DmaCallbackTypeDef pCallback);
#endif                                       

   
      
    

                                                                
      
    

                                                                                
HAL_StatusTypeDef HAL_SRAM_WriteOperation_Enable(SRAM_HandleTypeDef *hsram);
HAL_StatusTypeDef HAL_SRAM_WriteOperation_Disable(SRAM_HandleTypeDef *hsram);

   
      
    

                                                                         
      
    

                                                                                
HAL_SRAM_StateTypeDef HAL_SRAM_GetState(const SRAM_HandleTypeDef *hsram);

   
      
    

   
      
    

   
      
    

   
      
    

#endif                

#ifdef __cplusplus
}
#endif

#endif                           
