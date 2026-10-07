/**
  ******************************************************************************
  * @file    stm32l4xx_hal_gfxmmu.h
  * @author  MCD Application Team
  * @brief   Header file of GFXMMU HAL module.
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

                                                                                
#ifndef STM32L4xx_HAL_GFXMMU_H
#define STM32L4xx_HAL_GFXMMU_H

#ifdef __cplusplus
 extern "C" {
#endif

                                                                                
#include "stm32l4xx_hal_def.h"

#if defined(GFXMMU)

                                    
      
    

                      
      
     

                                                                                
                                                         
      
    

    
                                        
    
typedef enum
{
  HAL_GFXMMU_STATE_RESET = 0x00U,                               
  HAL_GFXMMU_STATE_READY = 0x01U,                                             
}HAL_GFXMMU_StateTypeDef;

    
                                               
    
typedef struct
{
  uint32_t Buf0Address;                                      
  uint32_t Buf1Address;                                      
  uint32_t Buf2Address;                                      
  uint32_t Buf3Address;                                      
}GFXMMU_BuffersTypeDef;

    
                                                  
    
typedef struct
{
  FunctionalState Activation;                                      
  uint32_t        UsedInterrupts;                      
                                                                                                            
                                                                                         
}GFXMMU_InterruptsTypeDef;

    
                                            
    
typedef struct
{
  uint32_t                    BlocksPerLine;                                            
                                                                                                                
  uint32_t                    DefaultValue;                                                                            
  GFXMMU_BuffersTypeDef       Buffers;                                          
  GFXMMU_InterruptsTypeDef    Interrupts;                                  
}GFXMMU_InitTypeDef;

    
                                              
    
#if (USE_HAL_GFXMMU_REGISTER_CALLBACKS == 1)
typedef struct __GFXMMU_HandleTypeDef
#else
typedef struct
#endif
{
  GFXMMU_TypeDef          *Instance;                        
  GFXMMU_InitTypeDef      Init;                                    
  HAL_GFXMMU_StateTypeDef State;                         
  __IO uint32_t           ErrorCode;                          
#if (USE_HAL_GFXMMU_REGISTER_CALLBACKS == 1)
  void (*ErrorCallback)     (struct __GFXMMU_HandleTypeDef *hgfxmmu);                              
  void (*MspInitCallback)   (struct __GFXMMU_HandleTypeDef *hgfxmmu);                                 
  void (*MspDeInitCallback) (struct __GFXMMU_HandleTypeDef *hgfxmmu);                                    
#endif
}GFXMMU_HandleTypeDef;

    
                                                
    
typedef struct
{
  uint32_t LineNumber;                             
                                                                                                               
  uint32_t LineStatus;                                     
                                                                                                 
  uint32_t FirstVisibleBlock;                                       
                                                                                                              
  uint32_t LastVisibleBlock;                                       
                                                                                                              
  int32_t  LineOffset;                                                                      
                                                                                                                   
                                                                                                    
                                                                                                                  
}GFXMMU_LutLineTypeDef;

#if (USE_HAL_GFXMMU_REGISTER_CALLBACKS == 1)
   
                                                     
    
typedef enum
{
  HAL_GFXMMU_ERROR_CB_ID     = 0x00U,                                 
  HAL_GFXMMU_MSPINIT_CB_ID   = 0x01U,                                    
  HAL_GFXMMU_MSPDEINIT_CB_ID = 0x02U                                        
}HAL_GFXMMU_CallbackIDTypeDef;

   
                                              
    
typedef void (*pGFXMMU_CallbackTypeDef)(GFXMMU_HandleTypeDef *hgfxmmu);
#endif

   
      
     
                                                                                

                                                                                
                                                                 
      
    

                                                         
      
    
#define GFXMMU_256BLOCKS 0x00000000U                                            
#define GFXMMU_192BLOCKS GFXMMU_CR_192BM                                        
   
      
    

                                                 
      
    
#define GFXMMU_AHB_MASTER_ERROR_IT GFXMMU_CR_AMEIE                                   
#define GFXMMU_BUFFER0_OVERFLOW_IT GFXMMU_CR_B0OIE                                    
#define GFXMMU_BUFFER1_OVERFLOW_IT GFXMMU_CR_B1OIE                                    
#define GFXMMU_BUFFER2_OVERFLOW_IT GFXMMU_CR_B2OIE                                    
#define GFXMMU_BUFFER3_OVERFLOW_IT GFXMMU_CR_B3OIE                                    
   
      
    

                                                 
      
    
#define GFXMMU_ERROR_NONE             0x00000000U                    
#define GFXMMU_ERROR_BUFFER0_OVERFLOW GFXMMU_SR_B0OF                          
#define GFXMMU_ERROR_BUFFER1_OVERFLOW GFXMMU_SR_B1OF                          
#define GFXMMU_ERROR_BUFFER2_OVERFLOW GFXMMU_SR_B2OF                          
#define GFXMMU_ERROR_BUFFER3_OVERFLOW GFXMMU_SR_B3OF                          
#define GFXMMU_ERROR_AHB_MASTER       GFXMMU_SR_AMEF                         
#if (USE_HAL_GFXMMU_REGISTER_CALLBACKS == 1)
#define GFXMMU_ERROR_INVALID_CALLBACK 0x00000100U                                  
#endif
   
      
    

                                                         
      
    
#define GFXMMU_LUT_LINE_DISABLE 0x00000000U                              
#define GFXMMU_LUT_LINE_ENABLE  GFXMMU_LUTxL_EN                         
   
      
    

   
      
     
                                                                                

                                                                                
                                                           
     
   

                                      
                                     
                
    
#if (USE_HAL_GFXMMU_REGISTER_CALLBACKS == 1)
#define __HAL_GFXMMU_RESET_HANDLE_STATE(__HANDLE__) do{                                               \
                                                        (__HANDLE__)->State = HAL_GFXMMU_STATE_RESET; \
                                                        (__HANDLE__)->MspInitCallback = NULL;         \
                                                        (__HANDLE__)->MspDeInitCallback = NULL;       \
                                                      } while(0)
#else
#define __HAL_GFXMMU_RESET_HANDLE_STATE(__HANDLE__) ((__HANDLE__)->State = HAL_GFXMMU_STATE_RESET)
#endif

   
      
    
                                                                                

                                                                                
                                                                   
      
    

                                                                                               
      
    
                                                                                
HAL_StatusTypeDef HAL_GFXMMU_Init(GFXMMU_HandleTypeDef *hgfxmmu);
HAL_StatusTypeDef HAL_GFXMMU_DeInit(GFXMMU_HandleTypeDef *hgfxmmu);
void HAL_GFXMMU_MspInit(GFXMMU_HandleTypeDef *hgfxmmu);
void HAL_GFXMMU_MspDeInit(GFXMMU_HandleTypeDef *hgfxmmu);
#if (USE_HAL_GFXMMU_REGISTER_CALLBACKS == 1)
                                                                                
HAL_StatusTypeDef HAL_GFXMMU_RegisterCallback(GFXMMU_HandleTypeDef        *hgfxmmu,
                                              HAL_GFXMMU_CallbackIDTypeDef CallbackID,
                                              pGFXMMU_CallbackTypeDef      pCallback);
HAL_StatusTypeDef HAL_GFXMMU_UnRegisterCallback(GFXMMU_HandleTypeDef        *hgfxmmu,
                                                HAL_GFXMMU_CallbackIDTypeDef CallbackID);
#endif
   
      
    

                                                                     
      
    
                                                                                
HAL_StatusTypeDef HAL_GFXMMU_ConfigLut(GFXMMU_HandleTypeDef *hgfxmmu,
                                       uint32_t FirstLine,
                                       uint32_t LinesNumber,
                                       uint32_t Address);

HAL_StatusTypeDef HAL_GFXMMU_DisableLutLines(GFXMMU_HandleTypeDef *hgfxmmu,
                                             uint32_t FirstLine,
                                             uint32_t LinesNumber);

HAL_StatusTypeDef HAL_GFXMMU_ConfigLutLine(GFXMMU_HandleTypeDef *hgfxmmu, GFXMMU_LutLineTypeDef *lutLine);

HAL_StatusTypeDef HAL_GFXMMU_ModifyBuffers(GFXMMU_HandleTypeDef *hgfxmmu, GFXMMU_BuffersTypeDef *Buffers);

void HAL_GFXMMU_IRQHandler(GFXMMU_HandleTypeDef *hgfxmmu);

void HAL_GFXMMU_ErrorCallback(GFXMMU_HandleTypeDef *hgfxmmu);
   
      
    

                                                              
      
    
                                                                                
HAL_GFXMMU_StateTypeDef HAL_GFXMMU_GetState(GFXMMU_HandleTypeDef *hgfxmmu);

uint32_t HAL_GFXMMU_GetError(GFXMMU_HandleTypeDef *hgfxmmu);
   
      
    

   
      
    
                                                                                

                                                                                
                                                         
    
  
#define IS_GFXMMU_BLOCKS_PER_LINE(VALUE) (((VALUE) == GFXMMU_256BLOCKS) || \
                                          ((VALUE) == GFXMMU_192BLOCKS))

#define IS_GFXMMU_BUFFER_ADDRESS(VALUE) (((VALUE) & 0xFU) == 0U)

#define IS_GFXMMU_INTERRUPTS(VALUE) (((VALUE) & 0x1FU) != 0U)

#define IS_GFXMMU_LUT_LINE(VALUE) ((VALUE) < 1024U)

#define IS_GFXMMU_LUT_LINES_NUMBER(VALUE) (((VALUE) > 0U) && ((VALUE) <= 1024U))

#define IS_GFXMMU_LUT_LINE_STATUS(VALUE) (((VALUE) == GFXMMU_LUT_LINE_DISABLE) || \
                                          ((VALUE) == GFXMMU_LUT_LINE_ENABLE))

#define IS_GFXMMU_LUT_BLOCK(VALUE) ((VALUE) < 256U)

#define IS_GFXMMU_LUT_LINE_OFFSET(VALUE) (((VALUE) >= -4080) && ((VALUE) <= 4190208))
   
      
     
                                                                                

   
      
     

   
      
    
#endif             
#ifdef __cplusplus
}
#endif

#endif                             

