/**
  ******************************************************************************
  * @file    stm32l4xx_hal_sd.h
  * @author  MCD Application Team
  * @brief   Header file of SD HAL module.
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

                                                                                
#ifndef STM32L4xx_HAL_SD_H
#define STM32L4xx_HAL_SD_H

#ifdef __cplusplus
extern "C" {
#endif

#if defined(SDMMC1)

                                                                                
#include "stm32l4xx_hal_def.h"
#include "stm32l4xx_ll_sdmmc.h"

                                    
      
    

                   
                               
      
    

                                                                                
                                                 
      
    

                                                                     
      
    
typedef enum
{
  HAL_SD_STATE_RESET                  = 0x00000000U,                                             
  HAL_SD_STATE_READY                  = 0x00000001U,                                             
  HAL_SD_STATE_TIMEOUT                = 0x00000002U,                                             
  HAL_SD_STATE_BUSY                   = 0x00000003U,                                             
  HAL_SD_STATE_PROGRAMMING            = 0x00000004U,                                             
  HAL_SD_STATE_RECEIVING              = 0x00000005U,                                             
  HAL_SD_STATE_TRANSFER               = 0x00000006U,                                            
  HAL_SD_STATE_ERROR                  = 0x0000000FU                                              
} HAL_SD_StateTypeDef;
   
      
    

                                                                          
      
    
typedef uint32_t HAL_SD_CardStateTypeDef;

#define HAL_SD_CARD_READY          0x00000001U                                                 
#define HAL_SD_CARD_IDENTIFICATION 0x00000002U                                                 
#define HAL_SD_CARD_STANDBY        0x00000003U                                                 
#define HAL_SD_CARD_TRANSFER       0x00000004U                                                 
#define HAL_SD_CARD_SENDING        0x00000005U                                                 
#define HAL_SD_CARD_RECEIVING      0x00000006U                                                 
#define HAL_SD_CARD_PROGRAMMING    0x00000007U                                                 
#define HAL_SD_CARD_DISCONNECTED   0x00000008U                                                 
#define HAL_SD_CARD_ERROR          0x000000FFU                                                 
   
      
    

                                                                     
      
    
#define SD_InitTypeDef      SDMMC_InitTypeDef
#define SD_TypeDef          SDMMC_TypeDef

   
                                                    
    
typedef struct
{
  uint32_t CardType;                                                                            

  uint32_t CardVersion;                                                                         

  uint32_t Class;                                                                               

  uint32_t RelCardAdd;                                                                          

  uint32_t BlockNbr;                                                                            

  uint32_t BlockSize;                                                                           

  uint32_t LogBlockNbr;                                                                         

  uint32_t LogBlockSize;                                                                        

#if defined(STM32L4P5xx) || defined(STM32L4Q5xx) || defined(STM32L4R5xx) || defined(STM32L4R7xx) || defined(STM32L4R9xx) || defined(STM32L4S5xx) || defined(STM32L4S7xx) || defined(STM32L4S9xx)

  uint32_t CardSpeed;                                                                           

#endif                                                                                                                           
} HAL_SD_CardInfoTypeDef;

   
                                          
    
#if defined (USE_HAL_SD_REGISTER_CALLBACKS) && (USE_HAL_SD_REGISTER_CALLBACKS == 1U)
typedef struct __SD_HandleTypeDef
#else
typedef struct
#endif                                    
{
  SD_TypeDef                   *Instance;                                                   

  SD_InitTypeDef               Init;                                                        

  HAL_LockTypeDef              Lock;                                                        

  uint8_t                      *pTxBuffPtr;                                                 

  uint32_t                     TxXferSize;                                                  

  uint8_t                      *pRxBuffPtr;                                                 

  uint32_t                     RxXferSize;                                                  

  __IO uint32_t                Context;                                                     

  __IO HAL_SD_StateTypeDef     State;                                                       

  __IO uint32_t                ErrorCode;                                                   

#if !defined(STM32L4P5xx) && !defined(STM32L4Q5xx) && !defined(STM32L4R5xx) && !defined(STM32L4R7xx) && !defined(STM32L4R9xx) && !defined(STM32L4S5xx) && !defined(STM32L4S7xx) && !defined(STM32L4S9xx)

  DMA_HandleTypeDef            *hdmatx;                                                     

  DMA_HandleTypeDef            *hdmarx;                                                     

#endif                                                                                                                                   

  HAL_SD_CardInfoTypeDef       SdCard;                                                      

  uint32_t                     CSD[4];                                                      

  uint32_t                     CID[4];                                                      

#if defined (USE_HAL_SD_REGISTER_CALLBACKS) && (USE_HAL_SD_REGISTER_CALLBACKS == 1U)
  void (* TxCpltCallback)(struct __SD_HandleTypeDef *hsd);
  void (* RxCpltCallback)(struct __SD_HandleTypeDef *hsd);
  void (* ErrorCallback)(struct __SD_HandleTypeDef *hsd);
  void (* AbortCpltCallback)(struct __SD_HandleTypeDef *hsd);
#if defined(STM32L4P5xx) || defined(STM32L4Q5xx) || defined(STM32L4R5xx) || defined(STM32L4R7xx) || defined(STM32L4R9xx) || defined(STM32L4S5xx) || defined(STM32L4S7xx) || defined(STM32L4S9xx)
  void (* Read_DMADblBuf0CpltCallback)(struct __SD_HandleTypeDef *hsd);
  void (* Read_DMADblBuf1CpltCallback)(struct __SD_HandleTypeDef *hsd);
  void (* Write_DMADblBuf0CpltCallback)(struct __SD_HandleTypeDef *hsd);
  void (* Write_DMADblBuf1CpltCallback)(struct __SD_HandleTypeDef *hsd);

  void (* DriveTransceiver_1_8V_Callback)(FlagStatus status);
#endif                                                                                                                           

  void (* MspInitCallback)(struct __SD_HandleTypeDef *hsd);
  void (* MspDeInitCallback)(struct __SD_HandleTypeDef *hsd);
#endif                                    
} SD_HandleTypeDef;

   
      
    

                                                                       
      
    
typedef struct
{
  __IO uint8_t  CSDStruct;                                                         
  __IO uint8_t  SysSpecVersion;                                                    
  __IO uint8_t  Reserved1;                                                         
  __IO uint8_t  TAAC;                                                              
  __IO uint8_t  NSAC;                                                              
  __IO uint8_t  MaxBusClkFrec;                                                     
  __IO uint16_t CardComdClasses;                                                   
  __IO uint8_t  RdBlockLen;                                                        
  __IO uint8_t  PartBlockRead;                                                     
  __IO uint8_t  WrBlockMisalign;                                                   
  __IO uint8_t  RdBlockMisalign;                                                   
  __IO uint8_t  DSRImpl;                                                           
  __IO uint8_t  Reserved2;                                                         
  __IO uint32_t DeviceSize;                                                        
  __IO uint8_t  MaxRdCurrentVDDMin;                                                
  __IO uint8_t  MaxRdCurrentVDDMax;                                                
  __IO uint8_t  MaxWrCurrentVDDMin;                                                
  __IO uint8_t  MaxWrCurrentVDDMax;                                                
  __IO uint8_t  DeviceSizeMul;                                                     
  __IO uint8_t  EraseGrSize;                                                       
  __IO uint8_t  EraseGrMul;                                                        
  __IO uint8_t  WrProtectGrSize;                                                   
  __IO uint8_t  WrProtectGrEnable;                                                 
  __IO uint8_t  ManDeflECC;                                                        
  __IO uint8_t  WrSpeedFact;                                                       
  __IO uint8_t  MaxWrBlockLen;                                                     
  __IO uint8_t  WriteBlockPaPartial;                                               
  __IO uint8_t  Reserved3;                                                         
  __IO uint8_t  ContentProtectAppli;                                               
  __IO uint8_t  FileFormatGroup;                                                   
  __IO uint8_t  CopyFlag;                                                          
  __IO uint8_t  PermWrProtect;                                                     
  __IO uint8_t  TempWrProtect;                                                     
  __IO uint8_t  FileFormat;                                                        
  __IO uint8_t  ECC;                                                               
  __IO uint8_t  CSD_CRC;                                                           
  __IO uint8_t  Reserved4;                                                         
} HAL_SD_CardCSDTypeDef;
   
      
    

                                                                             
      
    
typedef struct
{
  __IO uint8_t  ManufacturerID;                               
  __IO uint16_t OEM_AppliID;                                  
  __IO uint32_t ProdName1;                                    
  __IO uint8_t  ProdName2;                                    
  __IO uint8_t  ProdRev;                                      
  __IO uint32_t ProdSN;                                       
  __IO uint8_t  Reserved1;                                    
  __IO uint16_t ManufactDate;                                 
  __IO uint8_t  CID_CRC;                                      
  __IO uint8_t  Reserved2;                                    

} HAL_SD_CardCIDTypeDef;
   
      
    

                                                                        
      
    
typedef struct
{
  __IO uint8_t  DataBusWidth;                                                                             
  __IO uint8_t  SecuredMode;                                                                              
  __IO uint16_t CardType;                                                                                 
  __IO uint32_t ProtectedAreaSize;                                                                        
  __IO uint8_t  SpeedClass;                                                                               
  __IO uint8_t  PerformanceMove;                                                                          
  __IO uint8_t  AllocationUnitSize;                                                                       
  __IO uint16_t EraseSize;                                                                                
  __IO uint8_t  EraseTimeout;                                                                             
  __IO uint8_t  EraseOffset;                                                                              
#if defined(STM32L4P5xx) || defined(STM32L4Q5xx) || defined(STM32L4R5xx) || defined(STM32L4R7xx) || defined(STM32L4R9xx) || defined(STM32L4S5xx) || defined(STM32L4S7xx) || defined(STM32L4S9xx)
  __IO uint8_t  UhsSpeedGrade;                                                                            
  __IO uint8_t  UhsAllocationUnitSize;                                                                        
  __IO uint8_t  VideoSpeedClass;                                                                              
#endif                                                                                                                           

} HAL_SD_CardStatusTypeDef;
   
      
    

#if defined (USE_HAL_SD_REGISTER_CALLBACKS) && (USE_HAL_SD_REGISTER_CALLBACKS == 1U)
                                                                            
      
    
typedef enum
{
  HAL_SD_TX_CPLT_CB_ID                 = 0x00U,                                                        
  HAL_SD_RX_CPLT_CB_ID                 = 0x01U,                                                        
  HAL_SD_ERROR_CB_ID                   = 0x02U,                                                        
  HAL_SD_ABORT_CB_ID                   = 0x03U,                                                        
#if defined(STM32L4P5xx) || defined(STM32L4Q5xx) || defined(STM32L4R5xx) || defined(STM32L4R7xx) || defined(STM32L4R9xx) || defined(STM32L4S5xx) || defined(STM32L4S7xx) || defined(STM32L4S9xx)
  HAL_SD_READ_DMA_DBL_BUF0_CPLT_CB_ID  = 0x04U,                                                        
  HAL_SD_READ_DMA_DBL_BUF1_CPLT_CB_ID  = 0x05U,                                                        
  HAL_SD_WRITE_DMA_DBL_BUF0_CPLT_CB_ID = 0x06U,                                                        
  HAL_SD_WRITE_DMA_DBL_BUF1_CPLT_CB_ID = 0x07U,                                                        
#endif                                                                                                                           

  HAL_SD_MSP_INIT_CB_ID                = 0x10U,                                                        
  HAL_SD_MSP_DEINIT_CB_ID              = 0x11U                                                         
} HAL_SD_CallbackIDTypeDef;
   
      
    

                                                                     
      
    
typedef void (*pSD_CallbackTypeDef)(SD_HandleTypeDef *hsd);
#if defined(STM32L4P5xx) || defined(STM32L4Q5xx) || defined(STM32L4R5xx) || defined(STM32L4R7xx) || defined(STM32L4R9xx) || defined(STM32L4S5xx) || defined(STM32L4S7xx) || defined(STM32L4S9xx)
typedef void (*pSD_TransceiverCallbackTypeDef)(FlagStatus status);
#endif                                                                                                                           
   
      
    
#endif                                    
   
      
    

                                                                                
                                                      
      
    

#define BLOCKSIZE   512U                                

                                                                                            
      
    
#define HAL_SD_ERROR_NONE                     SDMMC_ERROR_NONE                                                                                         
#define HAL_SD_ERROR_CMD_CRC_FAIL             SDMMC_ERROR_CMD_CRC_FAIL                                                                                 
#define HAL_SD_ERROR_DATA_CRC_FAIL            SDMMC_ERROR_DATA_CRC_FAIL                                                                                
#define HAL_SD_ERROR_CMD_RSP_TIMEOUT          SDMMC_ERROR_CMD_RSP_TIMEOUT                                                                              
#define HAL_SD_ERROR_DATA_TIMEOUT             SDMMC_ERROR_DATA_TIMEOUT                                                                                 
#define HAL_SD_ERROR_TX_UNDERRUN              SDMMC_ERROR_TX_UNDERRUN                                                                                  
#define HAL_SD_ERROR_RX_OVERRUN               SDMMC_ERROR_RX_OVERRUN                                                                                   
#define HAL_SD_ERROR_ADDR_MISALIGNED          SDMMC_ERROR_ADDR_MISALIGNED                                                                              
#define HAL_SD_ERROR_BLOCK_LEN_ERR            SDMMC_ERROR_BLOCK_LEN_ERR                                                                            
                                                                                                                                                       
#define HAL_SD_ERROR_ERASE_SEQ_ERR            SDMMC_ERROR_ERASE_SEQ_ERR                                                                                
#define HAL_SD_ERROR_BAD_ERASE_PARAM          SDMMC_ERROR_BAD_ERASE_PARAM                                                                              
#define HAL_SD_ERROR_WRITE_PROT_VIOLATION     SDMMC_ERROR_WRITE_PROT_VIOLATION                                                                         
#define HAL_SD_ERROR_LOCK_UNLOCK_FAILED       SDMMC_ERROR_LOCK_UNLOCK_FAILED                                                                  
                                                                                                                                                       
#define HAL_SD_ERROR_COM_CRC_FAILED           SDMMC_ERROR_COM_CRC_FAILED                                                                               
#define HAL_SD_ERROR_ILLEGAL_CMD              SDMMC_ERROR_ILLEGAL_CMD                                                                                  
#define HAL_SD_ERROR_CARD_ECC_FAILED          SDMMC_ERROR_CARD_ECC_FAILED                                                                              
#define HAL_SD_ERROR_CC_ERR                   SDMMC_ERROR_CC_ERR                                                                                       
#define HAL_SD_ERROR_GENERAL_UNKNOWN_ERR      SDMMC_ERROR_GENERAL_UNKNOWN_ERR                                                                          
#define HAL_SD_ERROR_STREAM_READ_UNDERRUN     SDMMC_ERROR_STREAM_READ_UNDERRUN                                                                         
#define HAL_SD_ERROR_STREAM_WRITE_OVERRUN     SDMMC_ERROR_STREAM_WRITE_OVERRUN                                                                         
#define HAL_SD_ERROR_CID_CSD_OVERWRITE        SDMMC_ERROR_CID_CSD_OVERWRITE                                                                            
#define HAL_SD_ERROR_WP_ERASE_SKIP            SDMMC_ERROR_WP_ERASE_SKIP                                                                                
#define HAL_SD_ERROR_CARD_ECC_DISABLED        SDMMC_ERROR_CARD_ECC_DISABLED                                                                            
#define HAL_SD_ERROR_ERASE_RESET              SDMMC_ERROR_ERASE_RESET                                                                             
                                                                                                                                                       
#define HAL_SD_ERROR_AKE_SEQ_ERR              SDMMC_ERROR_AKE_SEQ_ERR                                                                                  
#define HAL_SD_ERROR_INVALID_VOLTRANGE        SDMMC_ERROR_INVALID_VOLTRANGE                                                                            
#define HAL_SD_ERROR_ADDR_OUT_OF_RANGE        SDMMC_ERROR_ADDR_OUT_OF_RANGE                                                                            
#define HAL_SD_ERROR_REQUEST_NOT_APPLICABLE   SDMMC_ERROR_REQUEST_NOT_APPLICABLE                                                                       
#define HAL_SD_ERROR_PARAM                    SDMMC_ERROR_INVALID_PARAMETER                                                                            
#define HAL_SD_ERROR_UNSUPPORTED_FEATURE      SDMMC_ERROR_UNSUPPORTED_FEATURE                                                                          
#define HAL_SD_ERROR_BUSY                     SDMMC_ERROR_BUSY                                                                                         
#define HAL_SD_ERROR_DMA                      SDMMC_ERROR_DMA                                                                                          
#define HAL_SD_ERROR_TIMEOUT                  SDMMC_ERROR_TIMEOUT                                                                                      

#if defined (USE_HAL_SD_REGISTER_CALLBACKS) && (USE_HAL_SD_REGISTER_CALLBACKS == 1U)
#define HAL_SD_ERROR_INVALID_CALLBACK         SDMMC_ERROR_INVALID_PARAMETER                                                                            
#endif                                    
   
      
    

                                                                  
      
    
#define SD_CONTEXT_NONE                            0x00000000U                                           
#define SD_CONTEXT_READ_SINGLE_BLOCK               0x00000001U                                           
#define SD_CONTEXT_READ_MULTIPLE_BLOCK             0x00000002U                                           
#define SD_CONTEXT_WRITE_SINGLE_BLOCK              0x00000010U                                           
#define SD_CONTEXT_WRITE_MULTIPLE_BLOCK            0x00000020U                                           
#define SD_CONTEXT_IT                              0x00000008U                                           
#define SD_CONTEXT_DMA                             0x00000080U                                           

   
      
    

                                                                     
      
    
#if defined(STM32L4P5xx) || defined(STM32L4Q5xx) || defined(STM32L4R5xx) || defined(STM32L4R7xx) || defined(STM32L4R9xx) || defined(STM32L4S5xx) || defined(STM32L4S7xx) || defined(STM32L4S9xx)
#define CARD_NORMAL_SPEED          0x00000000U                                                              
#define CARD_HIGH_SPEED            0x00000100U                                                              
#define CARD_ULTRA_HIGH_SPEED      0x00000200U                                                    
                                                                                                                       
#endif                                                                                                                           
#define CARD_SDSC                  0x00000000U                                                            
#define CARD_SDHC_SDXC             0x00000001U                                                            
#define CARD_SECURED               0x00000003U

   
      
    

                                                                
      
    
#define CARD_V1_X                  0x00000000U
#define CARD_V2_X                  0x00000001U
   
      
    

   
      
    

                                                                                
                                                   
                                                                         
      
    
                                 
                                   
                
    
#if defined (USE_HAL_SD_REGISTER_CALLBACKS) && (USE_HAL_SD_REGISTER_CALLBACKS == 1U)
#define __HAL_SD_RESET_HANDLE_STATE(__HANDLE__)           do {                                              \
                                                               (__HANDLE__)->State = HAL_SD_STATE_RESET; \
                                                               (__HANDLE__)->MspInitCallback = NULL;       \
                                                               (__HANDLE__)->MspDeInitCallback = NULL;     \
                                                             } while(0)
#else
#define __HAL_SD_RESET_HANDLE_STATE(__HANDLE__)           ((__HANDLE__)->State = HAL_SD_STATE_RESET)
#endif                                    

#if !defined(STM32L4P5xx) && !defined(STM32L4Q5xx) && !defined(STM32L4R5xx) && !defined(STM32L4R7xx) && !defined(STM32L4R9xx) && !defined(STM32L4S5xx) && !defined(STM32L4S7xx) && !defined(STM32L4S9xx)
   
                                 
                
    
#define __HAL_SD_ENABLE(__HANDLE__) __SDMMC_ENABLE((__HANDLE__)->Instance)

   
                                  
                
    
#define __HAL_SD_DISABLE(__HANDLE__) __SDMMC_DISABLE((__HANDLE__)->Instance)

   
                                          
                
    
#define __HAL_SD_DMA_ENABLE(__HANDLE__) __SDMMC_DMA_ENABLE((__HANDLE__)->Instance)

   
                                           
                
    
#define __HAL_SD_DMA_DISABLE(__HANDLE__)  __SDMMC_DMA_DISABLE((__HANDLE__)->Instance)
#endif                                                                                                                                   

   
                                           
                                 
                                                                               
                                                                               
                                                                                             
                                                                                            
                                                                         
                                                             
                                                                             
                                                                            
                                                                                             
                                                                                    
                                                                                            
                                                                     
                                                                                            
                                                                                 
                                                                             
                                                                          
                                                                         
                                                                         
                                                                       
                                                                   
                                                                  
                                                                    
                                                                   
                                                                                
                                                                               
                                                                                                         
                                                                        
                                                                               
                                                                              
                                                                                                    
                                                                                               
                                                                                
                
    
#define __HAL_SD_ENABLE_IT(__HANDLE__, __INTERRUPT__) __SDMMC_ENABLE_IT((__HANDLE__)->Instance, (__INTERRUPT__))

   
                                            
                                 
                                                                                
                                                                               
                                                                                             
                                                                                            
                                                                         
                                                             
                                                                             
                                                                            
                                                                                             
                                                                                    
                                                                                            
                                                                     
                                                                                            
                                                                                 
                                                                             
                                                                          
                                                                         
                                                                         
                                                                       
                                                                   
                                                                  
                                                                    
                                                                   
                                                                                
                                                                               
                                                                                                         
                                                                        
                                                                               
                                                                              
                                                                                                    
                                                                                               
                                                                                
                
    
#define __HAL_SD_DISABLE_IT(__HANDLE__, __INTERRUPT__) __SDMMC_DISABLE_IT((__HANDLE__)->Instance, (__INTERRUPT__))

   
                                                              
                                 
                                                  
                                                               
                                                                                     
                                                                                    
                                                                 
                                                     
                                                                     
                                                                    
                                                                                     
                                                                            
                                                                                    
                                                             
                                                                                    
                                                                         
                                                                         
                                                                            
                                                                     
                                                                  
                                                                 
                                                                 
                                                               
                                                           
                                                          
                                                            
                                                           
                                                                                 
                                                                                                 
                                                                        
                                                                       
                                                                
                                                                       
                                                                      
                                                                                            
                                                                                       
                                                              
                                                                        
                                                    
    
#define __HAL_SD_GET_FLAG(__HANDLE__, __FLAG__) __SDMMC_GET_FLAG((__HANDLE__)->Instance, (__FLAG__))

   
                                         
                                 
                                                  
                                                                                
                                                                                     
                                                                                    
                                                                 
                                                     
                                                                     
                                                                    
                                                                                     
                                                                            
                                                                                    
                                                             
                                                                                    
                                                                         
                                                                                                 
                                                                
                                                                       
                                                                      
                                                                                            
                                                                                       
                                                              
                                                                        
                
    
#define __HAL_SD_CLEAR_FLAG(__HANDLE__, __FLAG__) __SDMMC_CLEAR_FLAG((__HANDLE__)->Instance, (__FLAG__))

   
                                                                         
                                 
                                                                         
                                                               
                                                                                             
                                                                                            
                                                                         
                                                             
                                                                             
                                                                            
                                                                                             
                                                                                    
                                                                                            
                                                                     
                                                                                            
                                                                                 
                                                                             
                                                                          
                                                                         
                                                                         
                                                                       
                                                                   
                                                                  
                                                                    
                                                                   
                                                                                
                                                                               
                                                                                                         
                                                                        
                                                                               
                                                                              
                                                                                                    
                                                                                               
                                                                                
                                                  
    
#define __HAL_SD_GET_IT(__HANDLE__, __INTERRUPT__) __SDMMC_GET_IT((__HANDLE__)->Instance, (__INTERRUPT__))

   
                                                  
                                 
                                                                        
                                                                                
                                                                                             
                                                                                            
                                                                         
                                                             
                                                                             
                                                                            
                                                                                             
                                                                                    
                                                                                            
                                                                     
                                                                                              
                                                                                 
                                                                                                         
                                                                        
                                                                               
                                                                              
                                                                                                    
                                                                                               
                                                                                
                
    
#define __HAL_SD_CLEAR_IT(__HANDLE__, __INTERRUPT__) __SDMMC_CLEAR_IT((__HANDLE__)->Instance, (__INTERRUPT__))

   
      
    

#if defined(STM32L4P5xx) || defined(STM32L4Q5xx) || defined(STM32L4R5xx) || defined(STM32L4R7xx) || defined(STM32L4R9xx) || defined(STM32L4S5xx) || defined(STM32L4S7xx) || defined(STM32L4S9xx)
                                     
#include "stm32l4xx_hal_sd_ex.h"
#endif                                                                                                                           

                                                                                
                                                         
      
    

                                                                                         
      
    
HAL_StatusTypeDef HAL_SD_Init(SD_HandleTypeDef *hsd);
HAL_StatusTypeDef HAL_SD_InitCard(SD_HandleTypeDef *hsd);
HAL_StatusTypeDef HAL_SD_DeInit(SD_HandleTypeDef *hsd);
void HAL_SD_MspInit(SD_HandleTypeDef *hsd);
void HAL_SD_MspDeInit(SD_HandleTypeDef *hsd);
   
      
    

                                                                               
      
    
                            
HAL_StatusTypeDef HAL_SD_ReadBlocks(SD_HandleTypeDef *hsd, uint8_t *pData, uint32_t BlockAdd, uint32_t NumberOfBlocks,
                                    uint32_t Timeout);
HAL_StatusTypeDef HAL_SD_WriteBlocks(SD_HandleTypeDef *hsd, const uint8_t *pData, uint32_t BlockAdd,
                                     uint32_t NumberOfBlocks, uint32_t Timeout);
HAL_StatusTypeDef HAL_SD_Erase(SD_HandleTypeDef *hsd, uint32_t BlockStartAdd, uint32_t BlockEndAdd);
                           
HAL_StatusTypeDef HAL_SD_ReadBlocks_IT(SD_HandleTypeDef *hsd, uint8_t *pData, uint32_t BlockAdd,
                                       uint32_t NumberOfBlocks);
HAL_StatusTypeDef HAL_SD_WriteBlocks_IT(SD_HandleTypeDef *hsd, uint8_t *pData, uint32_t BlockAdd,
                                        uint32_t NumberOfBlocks);
                            
HAL_StatusTypeDef HAL_SD_ReadBlocks_DMA(SD_HandleTypeDef *hsd, uint8_t *pData, uint32_t BlockAdd,
                                        uint32_t NumberOfBlocks);
HAL_StatusTypeDef HAL_SD_WriteBlocks_DMA(SD_HandleTypeDef *hsd, uint8_t *pData, uint32_t BlockAdd,
                                         uint32_t NumberOfBlocks);

void HAL_SD_IRQHandler(SD_HandleTypeDef *hsd);

                                          
void HAL_SD_TxCpltCallback(SD_HandleTypeDef *hsd);
void HAL_SD_RxCpltCallback(SD_HandleTypeDef *hsd);
void HAL_SD_ErrorCallback(SD_HandleTypeDef *hsd);
void HAL_SD_AbortCallback(SD_HandleTypeDef *hsd);

#if defined (USE_HAL_SD_REGISTER_CALLBACKS) && (USE_HAL_SD_REGISTER_CALLBACKS == 1U)
                                           
HAL_StatusTypeDef HAL_SD_RegisterCallback(SD_HandleTypeDef *hsd, HAL_SD_CallbackIDTypeDef CallbackId,
                                          pSD_CallbackTypeDef pCallback);
HAL_StatusTypeDef HAL_SD_UnRegisterCallback(SD_HandleTypeDef *hsd, HAL_SD_CallbackIDTypeDef CallbackId);

#if defined(STM32L4P5xx) || defined(STM32L4Q5xx) || defined(STM32L4R5xx) || defined(STM32L4R7xx) || defined(STM32L4R9xx) || defined(STM32L4S5xx) || defined(STM32L4S7xx) || defined(STM32L4S9xx)
HAL_StatusTypeDef HAL_SD_RegisterTransceiverCallback(SD_HandleTypeDef *hsd, pSD_TransceiverCallbackTypeDef pCallback);
HAL_StatusTypeDef HAL_SD_UnRegisterTransceiverCallback(SD_HandleTypeDef *hsd);
#endif                                                                                                                           
#endif                                    

   
      
    

                                                                       
      
    
HAL_StatusTypeDef HAL_SD_ConfigWideBusOperation(SD_HandleTypeDef *hsd, uint32_t WideMode);
HAL_StatusTypeDef HAL_SD_ConfigSpeedBusOperation(SD_HandleTypeDef *hsd, uint32_t SpeedMode);
   
      
    

                                                                    
      
    
HAL_StatusTypeDef       HAL_SD_SendSDStatus(SD_HandleTypeDef *hsd, uint32_t *pSDstatus);
HAL_SD_CardStateTypeDef HAL_SD_GetCardState(SD_HandleTypeDef *hsd);
HAL_StatusTypeDef       HAL_SD_GetCardCID(SD_HandleTypeDef *hsd, HAL_SD_CardCIDTypeDef *pCID);
HAL_StatusTypeDef       HAL_SD_GetCardCSD(SD_HandleTypeDef *hsd, HAL_SD_CardCSDTypeDef *pCSD);
HAL_StatusTypeDef       HAL_SD_GetCardStatus(SD_HandleTypeDef *hsd, HAL_SD_CardStatusTypeDef *pStatus);
HAL_StatusTypeDef       HAL_SD_GetCardInfo(SD_HandleTypeDef *hsd, HAL_SD_CardInfoTypeDef *pCardInfo);
   
      
    

                                                                                
      
    
HAL_SD_StateTypeDef HAL_SD_GetState(const SD_HandleTypeDef *hsd);
uint32_t HAL_SD_GetError(const SD_HandleTypeDef *hsd);
   
      
    

                                                                      
      
    
HAL_StatusTypeDef HAL_SD_Abort(SD_HandleTypeDef *hsd);
HAL_StatusTypeDef HAL_SD_Abort_IT(SD_HandleTypeDef *hsd);
   
      
    

                                                                                
                                               
      
    

   
      
    

                                                                                
                                                   
      
    

   
      
    

                                                                                
                                                       
      
    

   
      
    

                                                                                
                                                       
      
    

   
      
    

                                                                                
                                                 
      
    

   
      
    

                                                                                
                                                                             
      
    

   
      
    

                                                                                
                                                       
      
    

#if defined(STM32L4P5xx) || defined(STM32L4Q5xx) || defined(STM32L4R5xx) || defined(STM32L4R7xx) || defined(STM32L4R9xx) || defined(STM32L4S5xx) || defined(STM32L4S7xx) || defined(STM32L4S9xx)
uint32_t SD_HighSpeed(SD_HandleTypeDef *hsd);
#endif                                                                                                                           
   
      
    


   
      
    

   
      
    

   
      
    

#endif             

#ifdef __cplusplus
}
#endif


#endif                         
