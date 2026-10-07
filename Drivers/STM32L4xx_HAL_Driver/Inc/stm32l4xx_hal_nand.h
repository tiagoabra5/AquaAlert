/**
  ******************************************************************************
  * @file    stm32l4xx_hal_nand.h
  * @author  MCD Application Team
  * @brief   Header file of NAND HAL module.
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

                                                                                
#ifndef STM32L4xx_HAL_NAND_H
#define STM32L4xx_HAL_NAND_H

#ifdef __cplusplus
extern "C" {
#endif

#if defined(FMC_BANK3)

                                                                                
#include "stm32l4xx_ll_fmc.h"

                                    
      
    

                    
      
    

                                                                                
                                                                                
                                                     
      
    

   
                                                
    
typedef enum
{
  HAL_NAND_STATE_RESET     = 0x00U,                                              
  HAL_NAND_STATE_READY     = 0x01U,                                              
  HAL_NAND_STATE_BUSY      = 0x02U,                                              
  HAL_NAND_STATE_ERROR     = 0x03U                                               
} HAL_NAND_StateTypeDef;

   
                                                                 
    
typedef struct
{
                                                               

  uint8_t Maker_Id;

  uint8_t Device_Id;

  uint8_t Third_Id;

  uint8_t Fourth_Id;
} NAND_IDTypeDef;

   
                                                    
    
typedef struct
{
  uint16_t Page;                                    

  uint16_t Plane;                                    

  uint16_t Block;                                   

} NAND_AddressTypeDef;

   
                                                 
    
typedef struct
{
  uint32_t        PageSize;                                                                               
                                                                                                                  

  uint32_t        SpareAreaSize;                                                           
                                                                                                                  

  uint32_t        BlockSize;                                                                                     

  uint32_t        BlockNbr;                                                                                      

  uint32_t        PlaneNbr;                                                                                      

  uint32_t        PlaneSize;                                                                                     

  FunctionalState ExtraCommandEnable;                                                              
                                                                                                       
                                                                                                             
                                                                                       
                                                                                                                 
} NAND_DeviceConfigTypeDef;

   
                                            
    
#if (USE_HAL_NAND_REGISTER_CALLBACKS == 1)
typedef struct __NAND_HandleTypeDef
#else
typedef struct
#endif                                       
{
  FMC_NAND_TypeDef               *Instance;                                                               

  FMC_NAND_InitTypeDef           Init;                                                                    

  HAL_LockTypeDef                Lock;                                                                    

  __IO HAL_NAND_StateTypeDef     State;                                                                   

  NAND_DeviceConfigTypeDef       Config;                                                                  

#if (USE_HAL_NAND_REGISTER_CALLBACKS == 1)
  void (* MspInitCallback)(struct __NAND_HandleTypeDef *hnand);                                                          
  void (* MspDeInitCallback)(struct __NAND_HandleTypeDef *hnand);                                                        
  void (* ItCallback)(struct __NAND_HandleTypeDef *hnand);                                                               
#endif                                      
} NAND_HandleTypeDef;

#if (USE_HAL_NAND_REGISTER_CALLBACKS == 1)
   
                                                       
    
typedef enum
{
  HAL_NAND_MSP_INIT_CB_ID       = 0x00U,                                           
  HAL_NAND_MSP_DEINIT_CB_ID     = 0x01U,                                           
  HAL_NAND_IT_CB_ID             = 0x02U                                            
} HAL_NAND_CallbackIDTypeDef;

   
                                                
    
typedef void (*pNAND_CallbackTypeDef)(NAND_HandleTypeDef *hnand);
#endif                                      

   
      
    

                                                                                
                                                                                
                                                       
      
    

                                  
                                                 
                
    
#if (USE_HAL_NAND_REGISTER_CALLBACKS == 1)
#define __HAL_NAND_RESET_HANDLE_STATE(__HANDLE__)         do {                                             \
                                                               (__HANDLE__)->State = HAL_NAND_STATE_RESET; \
                                                               (__HANDLE__)->MspInitCallback = NULL;       \
                                                               (__HANDLE__)->MspDeInitCallback = NULL;     \
                                                             } while(0)
#else
#define __HAL_NAND_RESET_HANDLE_STATE(__HANDLE__) ((__HANDLE__)->State = HAL_NAND_STATE_RESET)
#endif                                      

   
      
    

                                                                                
                                                               
      
    

                                                                                             
      
    

                                                                                
HAL_StatusTypeDef  HAL_NAND_Init(NAND_HandleTypeDef *hnand, FMC_NAND_PCC_TimingTypeDef *ComSpace_Timing,
                                 FMC_NAND_PCC_TimingTypeDef *AttSpace_Timing);
HAL_StatusTypeDef  HAL_NAND_DeInit(NAND_HandleTypeDef *hnand);

HAL_StatusTypeDef  HAL_NAND_ConfigDevice(NAND_HandleTypeDef *hnand, const NAND_DeviceConfigTypeDef *pDeviceConfig);

HAL_StatusTypeDef  HAL_NAND_Read_ID(NAND_HandleTypeDef *hnand, NAND_IDTypeDef *pNAND_ID);

void               HAL_NAND_MspInit(NAND_HandleTypeDef *hnand);
void               HAL_NAND_MspDeInit(NAND_HandleTypeDef *hnand);
void               HAL_NAND_IRQHandler(NAND_HandleTypeDef *hnand);
void               HAL_NAND_ITCallback(NAND_HandleTypeDef *hnand);

   
      
    

                                                                         
      
    

                                                                                
HAL_StatusTypeDef  HAL_NAND_Reset(NAND_HandleTypeDef *hnand);

HAL_StatusTypeDef  HAL_NAND_Read_Page_8b(NAND_HandleTypeDef *hnand, const NAND_AddressTypeDef *pAddress,
                                         uint8_t *pBuffer, uint32_t NumPageToRead);
HAL_StatusTypeDef  HAL_NAND_Write_Page_8b(NAND_HandleTypeDef *hnand, const NAND_AddressTypeDef *pAddress,
                                          const uint8_t *pBuffer, uint32_t NumPageToWrite);
HAL_StatusTypeDef  HAL_NAND_Read_SpareArea_8b(NAND_HandleTypeDef *hnand, const NAND_AddressTypeDef *pAddress,
                                              uint8_t *pBuffer, uint32_t NumSpareAreaToRead);
HAL_StatusTypeDef  HAL_NAND_Write_SpareArea_8b(NAND_HandleTypeDef *hnand, const NAND_AddressTypeDef *pAddress,
                                               const uint8_t *pBuffer, uint32_t NumSpareAreaTowrite);

HAL_StatusTypeDef  HAL_NAND_Read_Page_16b(NAND_HandleTypeDef *hnand, const NAND_AddressTypeDef *pAddress,
                                          uint16_t *pBuffer, uint32_t NumPageToRead);
HAL_StatusTypeDef  HAL_NAND_Write_Page_16b(NAND_HandleTypeDef *hnand, const NAND_AddressTypeDef *pAddress,
                                           const uint16_t *pBuffer, uint32_t NumPageToWrite);
HAL_StatusTypeDef  HAL_NAND_Read_SpareArea_16b(NAND_HandleTypeDef *hnand, const NAND_AddressTypeDef *pAddress,
                                               uint16_t *pBuffer, uint32_t NumSpareAreaToRead);
HAL_StatusTypeDef  HAL_NAND_Write_SpareArea_16b(NAND_HandleTypeDef *hnand, const NAND_AddressTypeDef *pAddress,
                                                const uint16_t *pBuffer, uint32_t NumSpareAreaTowrite);

HAL_StatusTypeDef  HAL_NAND_Erase_Block(NAND_HandleTypeDef *hnand, const NAND_AddressTypeDef *pAddress);

uint32_t           HAL_NAND_Address_Inc(const NAND_HandleTypeDef *hnand, NAND_AddressTypeDef *pAddress);

#if (USE_HAL_NAND_REGISTER_CALLBACKS == 1)
                                             
HAL_StatusTypeDef  HAL_NAND_RegisterCallback(NAND_HandleTypeDef *hnand, HAL_NAND_CallbackIDTypeDef CallbackId,
                                             pNAND_CallbackTypeDef pCallback);
HAL_StatusTypeDef  HAL_NAND_UnRegisterCallback(NAND_HandleTypeDef *hnand, HAL_NAND_CallbackIDTypeDef CallbackId);
#endif                                      

   
      
    

                                                                           
      
    

                                                                                
HAL_StatusTypeDef  HAL_NAND_ECC_Enable(NAND_HandleTypeDef *hnand);
HAL_StatusTypeDef  HAL_NAND_ECC_Disable(NAND_HandleTypeDef *hnand);
HAL_StatusTypeDef  HAL_NAND_GetECC(NAND_HandleTypeDef *hnand, uint32_t *ECCval, uint32_t Timeout);

   
      
    

                                                                         
      
    
                                                                                
HAL_NAND_StateTypeDef HAL_NAND_GetState(const NAND_HandleTypeDef *hnand);
uint32_t              HAL_NAND_Read_Status(const NAND_HandleTypeDef *hnand);
   
      
    

   
      
    

                                                                                
                                                                                
                                                                                
                                                           
      
    
#define NAND_DEVICE                0x80000000UL
#define NAND_WRITE_TIMEOUT         0x01000000UL

#define CMD_AREA                   (1UL<<16U)                      
#define ADDR_AREA                  (1UL<<17U)                      

#define NAND_CMD_AREA_A            ((uint8_t)0x00)
#define NAND_CMD_AREA_B            ((uint8_t)0x01)
#define NAND_CMD_AREA_C            ((uint8_t)0x50)
#define NAND_CMD_AREA_TRUE1        ((uint8_t)0x30)

#define NAND_CMD_WRITE0            ((uint8_t)0x80)
#define NAND_CMD_WRITE_TRUE1       ((uint8_t)0x10)
#define NAND_CMD_ERASE0            ((uint8_t)0x60)
#define NAND_CMD_ERASE1            ((uint8_t)0xD0)
#define NAND_CMD_READID            ((uint8_t)0x90)
#define NAND_CMD_STATUS            ((uint8_t)0x70)
#define NAND_CMD_LOCK_STATUS       ((uint8_t)0x7A)
#define NAND_CMD_RESET             ((uint8_t)0xFF)

                        
#define NAND_VALID_ADDRESS         0x00000100UL
#define NAND_INVALID_ADDRESS       0x00000200UL
#define NAND_TIMEOUT_ERROR         0x00000400UL
#define NAND_BUSY                  0x00000000UL
#define NAND_ERROR                 0x00000001UL
#define NAND_READY                 0x00000040UL
   
      
    

                                                                                
                                                     
      
    

   
                                            
                                            
                                    
                                  
    
#define ARRAY_ADDRESS(__ADDRESS__ , __HANDLE__) ((__ADDRESS__)->Page + \
                                                 (((__ADDRESS__)->Block + \
                                                   (((__ADDRESS__)->Plane) * \
                                                    ((__HANDLE__)->Config.PlaneSize))) * \
                                                  ((__HANDLE__)->Config.BlockSize)))

   
                                                   
                                   
                                  
    
#define COLUMN_ADDRESS( __HANDLE__) ((__HANDLE__)->Config.PageSize)

   
                                        
                                            
                                       
    
#define ADDR_1ST_CYCLE(__ADDRESS__)       (uint8_t)(__ADDRESS__)                                        
#define ADDR_2ND_CYCLE(__ADDRESS__)       (uint8_t)((__ADDRESS__) >> 8)                                 
#define ADDR_3RD_CYCLE(__ADDRESS__)       (uint8_t)((__ADDRESS__) >> 16)                                
#define ADDR_4TH_CYCLE(__ADDRESS__)       (uint8_t)((__ADDRESS__) >> 24)                                

   
                                        
                                            
                                              
    
#define COLUMN_1ST_CYCLE(__ADDRESS__)       (uint8_t)((__ADDRESS__) & 0xFFU)                                     
#define COLUMN_2ND_CYCLE(__ADDRESS__)       (uint8_t)((__ADDRESS__) >> 8)                                        

   
      
    

   
      
    

   
      
    

   
      
    

#endif                

#ifdef __cplusplus
}
#endif

#endif                           
