/**
  ******************************************************************************
  * @file    stm32l4xx_hal_nor.h
  * @author  MCD Application Team
  * @brief   Header file of NOR HAL module.
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

                                                                                
#ifndef STM32L4xx_HAL_NOR_H
#define STM32L4xx_HAL_NOR_H

#ifdef __cplusplus
extern "C" {
#endif

#if defined(FMC_BANK1)

                                                                                
#include "stm32l4xx_ll_fmc.h"

                                    
      
    

                   
      
    

                                                                                
                                                   
      
    

   
                                                
    
typedef enum
{
  HAL_NOR_STATE_RESET             = 0x00U,                                              
  HAL_NOR_STATE_READY             = 0x01U,                                              
  HAL_NOR_STATE_BUSY              = 0x02U,                                              
  HAL_NOR_STATE_ERROR             = 0x03U,                                              
  HAL_NOR_STATE_PROTECTED         = 0x04U                                               
} HAL_NOR_StateTypeDef;

   
                                  
    
typedef enum
{
  HAL_NOR_STATUS_SUCCESS  = 0U,
  HAL_NOR_STATUS_ONGOING,
  HAL_NOR_STATUS_ERROR,
  HAL_NOR_STATUS_TIMEOUT
} HAL_NOR_StatusTypeDef;

   
                              
    
typedef struct
{
  uint16_t Manufacturer_Code;                                                                                  

  uint16_t Device_Code1;

  uint16_t Device_Code2;

  uint16_t Device_Code3;                                                                   
                                                                                                           
                                                                                                          
                                                                                                               
} NOR_IDTypeDef;

   
                               
    
typedef struct
{
                                                                            
                                                                                
                                                                                     

  uint16_t CFI_1;

  uint16_t CFI_2;

  uint16_t CFI_3;

  uint16_t CFI_4;
} NOR_CFITypeDef;

   
                                           
    
#if (USE_HAL_NOR_REGISTER_CALLBACKS == 1)
typedef struct __NOR_HandleTypeDef
#else
typedef struct
#endif                                      

{
  FMC_NORSRAM_TypeDef           *Instance;                                                        

  FMC_NORSRAM_EXTENDED_TypeDef  *Extended;                                                        

  FMC_NORSRAM_InitTypeDef       Init;                                                             

  HAL_LockTypeDef               Lock;                                                             

  __IO HAL_NOR_StateTypeDef     State;                                                            

  uint32_t                      CommandSet;                                                       

#if (USE_HAL_NOR_REGISTER_CALLBACKS == 1)
  void (* MspInitCallback)(struct __NOR_HandleTypeDef *hnor);                                                         
  void (* MspDeInitCallback)(struct __NOR_HandleTypeDef *hnor);                                                       
#endif                                     
} NOR_HandleTypeDef;

#if (USE_HAL_NOR_REGISTER_CALLBACKS == 1)
   
                                                      
    
typedef enum
{
  HAL_NOR_MSP_INIT_CB_ID       = 0x00U,                                          
  HAL_NOR_MSP_DEINIT_CB_ID     = 0x01U                                           
} HAL_NOR_CallbackIDTypeDef;

   
                                               
    
typedef void (*pNOR_CallbackTypeDef)(NOR_HandleTypeDef *hnor);
#endif                                     
   
      
    

                                                                                
                                                                                
                                                     
      
    
                                 
                                                
                
    
#if (USE_HAL_NOR_REGISTER_CALLBACKS == 1)
#define __HAL_NOR_RESET_HANDLE_STATE(__HANDLE__)          do {                                             \
                                                               (__HANDLE__)->State = HAL_NOR_STATE_RESET;  \
                                                               (__HANDLE__)->MspInitCallback = NULL;       \
                                                               (__HANDLE__)->MspDeInitCallback = NULL;     \
                                                             } while(0)
#else
#define __HAL_NOR_RESET_HANDLE_STATE(__HANDLE__) ((__HANDLE__)->State = HAL_NOR_STATE_RESET)
#endif                                     
   
      
    

                                                                                
                                                             
      
    

                                                                                            
      
    

                                                                                
HAL_StatusTypeDef HAL_NOR_Init(NOR_HandleTypeDef *hnor, FMC_NORSRAM_TimingTypeDef *Timing,
                               FMC_NORSRAM_TimingTypeDef *ExtTiming);
HAL_StatusTypeDef HAL_NOR_DeInit(NOR_HandleTypeDef *hnor);
void HAL_NOR_MspInit(NOR_HandleTypeDef *hnor);
void HAL_NOR_MspDeInit(NOR_HandleTypeDef *hnor);
void HAL_NOR_MspWait(NOR_HandleTypeDef *hnor, uint32_t Timeout);
   
      
    

                                                                        
      
    

                                                                                
HAL_StatusTypeDef HAL_NOR_Read_ID(NOR_HandleTypeDef *hnor, NOR_IDTypeDef *pNOR_ID);
HAL_StatusTypeDef HAL_NOR_ReturnToReadMode(NOR_HandleTypeDef *hnor);
HAL_StatusTypeDef HAL_NOR_Read(NOR_HandleTypeDef *hnor, uint32_t *pAddress, uint16_t *pData);
HAL_StatusTypeDef HAL_NOR_Program(NOR_HandleTypeDef *hnor, uint32_t *pAddress, uint16_t *pData);

HAL_StatusTypeDef HAL_NOR_ReadBuffer(NOR_HandleTypeDef *hnor, uint32_t uwAddress, uint16_t *pData,
                                     uint32_t uwBufferSize);
HAL_StatusTypeDef HAL_NOR_ProgramBuffer(NOR_HandleTypeDef *hnor, uint32_t uwAddress, uint16_t *pData,
                                        uint32_t uwBufferSize);

HAL_StatusTypeDef HAL_NOR_Erase_Block(NOR_HandleTypeDef *hnor, uint32_t BlockAddress, uint32_t Address);
HAL_StatusTypeDef HAL_NOR_Erase_Chip(NOR_HandleTypeDef *hnor, uint32_t Address);
HAL_StatusTypeDef HAL_NOR_Read_CFI(NOR_HandleTypeDef *hnor, NOR_CFITypeDef *pNOR_CFI);

#if (USE_HAL_NOR_REGISTER_CALLBACKS == 1)
                                            
HAL_StatusTypeDef HAL_NOR_RegisterCallback(NOR_HandleTypeDef *hnor, HAL_NOR_CallbackIDTypeDef CallbackId,
                                           pNOR_CallbackTypeDef pCallback);
HAL_StatusTypeDef HAL_NOR_UnRegisterCallback(NOR_HandleTypeDef *hnor, HAL_NOR_CallbackIDTypeDef CallbackId);
#endif                                     
   
      
    

                                                                   
      
    

                                                                                
HAL_StatusTypeDef HAL_NOR_WriteOperation_Enable(NOR_HandleTypeDef *hnor);
HAL_StatusTypeDef HAL_NOR_WriteOperation_Disable(NOR_HandleTypeDef *hnor);
   
      
    

                                                                 
      
    

                                                                                
HAL_NOR_StateTypeDef  HAL_NOR_GetState(const NOR_HandleTypeDef *hnor);
HAL_NOR_StatusTypeDef HAL_NOR_GetStatus(NOR_HandleTypeDef *hnor, uint32_t Address, uint32_t Timeout);
   
      
    

   
      
    

                                                                                
                                                                                
                                                                                
                                                         
      
    
                              
#define MC_ADDRESS               ((uint16_t)0x0000)
#define DEVICE_CODE1_ADDR        ((uint16_t)0x0001)
#define DEVICE_CODE2_ADDR        ((uint16_t)0x000E)
#define DEVICE_CODE3_ADDR        ((uint16_t)0x000F)

                           
#define CFI1_ADDRESS             ((uint16_t)0x0061)
#define CFI2_ADDRESS             ((uint16_t)0x0062)
#define CFI3_ADDRESS             ((uint16_t)0x0063)
#define CFI4_ADDRESS             ((uint16_t)0x0064)

                                
#define NOR_TMEOUT               ((uint16_t)0xFFFF)

                           
#define NOR_MEMORY_8B            ((uint8_t)0x00)
#define NOR_MEMORY_16B           ((uint8_t)0x01)

                                                
#define NOR_MEMORY_ADRESS1       (0x60000000U)
#define NOR_MEMORY_ADRESS2       (0x64000000U)
#define NOR_MEMORY_ADRESS3       (0x68000000U)
#define NOR_MEMORY_ADRESS4       (0x6C000000U)
   
      
    

                                                                                
                                                   
      
    
   
                                        
                                          
                                                
                                          
                                     
    
#define NOR_ADDR_SHIFT(__NOR_ADDRESS, __NOR_MEMORY_WIDTH_, __ADDRESS__)         \
  ((uint32_t)(((__NOR_MEMORY_WIDTH_) == NOR_MEMORY_16B)?            \
              ((uint32_t)((__NOR_ADDRESS) + (2U * (__ADDRESS__)))):              \
              ((uint32_t)((__NOR_ADDRESS) + (__ADDRESS__)))))

   
                                                       
                                          
                                  
                
    
#define NOR_WRITE(__ADDRESS__, __DATA__)   do{                                                             \
                                               (*(__IO uint16_t *)((uint32_t)(__ADDRESS__)) = (__DATA__)); \
                                               __DSB();                                                    \
                                             } while(0)

   
      
    

   
      
    

   
      
    

#endif                

#ifdef __cplusplus
}
#endif

#endif                          
