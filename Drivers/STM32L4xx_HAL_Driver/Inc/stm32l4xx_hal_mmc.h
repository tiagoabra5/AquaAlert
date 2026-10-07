/**
  ******************************************************************************
  * @file    stm32l4xx_hal_mmc.h
  * @author  MCD Application Team
  * @brief   Header file of MMC HAL module.
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

                                                                                
#ifndef STM32L4xx_HAL_MMC_H
#define STM32L4xx_HAL_MMC_H

#if defined(SDMMC1)

#ifdef __cplusplus
extern "C" {
#endif

                                                                                
#include "stm32l4xx_hal_def.h"
#include "stm32l4xx_ll_sdmmc.h"

                                    
      
    

                   
      
    

                                                                                
                                                   
      
    

                                                                       
      
    
typedef enum
{
  HAL_MMC_STATE_RESET                  = 0x00000000U,                                              
  HAL_MMC_STATE_READY                  = 0x00000001U,                                              
  HAL_MMC_STATE_TIMEOUT                = 0x00000002U,                                              
  HAL_MMC_STATE_BUSY                   = 0x00000003U,                                              
  HAL_MMC_STATE_PROGRAMMING            = 0x00000004U,                                              
  HAL_MMC_STATE_RECEIVING              = 0x00000005U,                                              
  HAL_MMC_STATE_TRANSFER               = 0x00000006U,                                             
  HAL_MMC_STATE_ERROR                  = 0x0000000FU                                               
} HAL_MMC_StateTypeDef;
   
      
    

                                                                            
      
    
typedef uint32_t HAL_MMC_CardStateTypeDef;

#define HAL_MMC_CARD_IDLE           0x00000000U                                                                     
#define HAL_MMC_CARD_READY          0x00000001U                                                                     
#define HAL_MMC_CARD_IDENTIFICATION 0x00000002U                                                                     
#define HAL_MMC_CARD_STANDBY        0x00000003U                                                                     
#define HAL_MMC_CARD_TRANSFER       0x00000004U                                                                     
#define HAL_MMC_CARD_SENDING        0x00000005U                                                                     
#define HAL_MMC_CARD_RECEIVING      0x00000006U                                                                     
#define HAL_MMC_CARD_PROGRAMMING    0x00000007U                                                                     
#define HAL_MMC_CARD_DISCONNECTED   0x00000008U                                                                     
#define HAL_MMC_CARD_BUSTEST        0x00000009U                                                                     
#define HAL_MMC_CARD_SLEEP          0x0000000AU                                                                     
#define HAL_MMC_CARD_ERROR          0x000000FFU                                                                     
   
      
    

                                                                       
      
    
#define MMC_InitTypeDef      SDMMC_InitTypeDef
#define MMC_TypeDef          SDMMC_TypeDef

   
                                                     
    
typedef struct
{
  uint32_t CardType;                                                                            

  uint32_t Class;                                                                               

  uint32_t RelCardAdd;                                                                          

  uint32_t BlockNbr;                                                                            

  uint32_t BlockSize;                                                                           

  uint32_t LogBlockNbr;                                                                         

  uint32_t LogBlockSize;                                                                        

} HAL_MMC_CardInfoTypeDef;

   
                                           
    
#if defined (USE_HAL_MMC_REGISTER_CALLBACKS) && (USE_HAL_MMC_REGISTER_CALLBACKS == 1U)
typedef struct __MMC_HandleTypeDef
#else
typedef struct
#endif                                     
{
  MMC_TypeDef                  *Instance;                                                    

  MMC_InitTypeDef              Init;                                                         

  HAL_LockTypeDef              Lock;                                                         

  uint8_t                      *pTxBuffPtr;                                                  

  uint32_t                     TxXferSize;                                                   

  uint8_t                      *pRxBuffPtr;                                                  

  uint32_t                     RxXferSize;                                                   

  __IO uint32_t                Context;                                                      

  __IO HAL_MMC_StateTypeDef    State;                                                        

  __IO uint32_t                ErrorCode;                                                    

#if !defined(STM32L4P5xx) && !defined(STM32L4Q5xx) && !defined(STM32L4R5xx) && !defined(STM32L4R7xx) && !defined(STM32L4R9xx) && !defined(STM32L4S5xx) && !defined(STM32L4S7xx) && !defined(STM32L4S9xx)
  DMA_HandleTypeDef            *hdmarx;                                                      

  DMA_HandleTypeDef            *hdmatx;                                                      
#endif                                                                                                                                   

  HAL_MMC_CardInfoTypeDef      MmcCard;                                                      

  uint32_t                     CSD[4U];                                                      

  uint32_t                     CID[4U];                                                      

  uint32_t                     Ext_CSD[128];

#if defined (USE_HAL_MMC_REGISTER_CALLBACKS) && (USE_HAL_MMC_REGISTER_CALLBACKS == 1U)
  void (* TxCpltCallback)(struct __MMC_HandleTypeDef *hmmc);
  void (* RxCpltCallback)(struct __MMC_HandleTypeDef *hmmc);
  void (* ErrorCallback)(struct __MMC_HandleTypeDef *hmmc);
  void (* AbortCpltCallback)(struct __MMC_HandleTypeDef *hmmc);
#if defined(STM32L4P5xx) || defined(STM32L4Q5xx) || defined(STM32L4R5xx) || defined(STM32L4R7xx) || defined(STM32L4R9xx) || defined(STM32L4S5xx) || defined(STM32L4S7xx) || defined(STM32L4S9xx)
  void (* Read_DMADblBuf0CpltCallback)(struct __MMC_HandleTypeDef *hmmc);
  void (* Read_DMADblBuf1CpltCallback)(struct __MMC_HandleTypeDef *hmmc);
  void (* Write_DMADblBuf0CpltCallback)(struct __MMC_HandleTypeDef *hmmc);
  void (* Write_DMADblBuf1CpltCallback)(struct __MMC_HandleTypeDef *hmmc);
#endif                                                                                                                           

  void (* MspInitCallback)(struct __MMC_HandleTypeDef *hmmc);
  void (* MspDeInitCallback)(struct __MMC_HandleTypeDef *hmmc);
#endif
} MMC_HandleTypeDef;

   
      
    

                                                                        
      
    
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

} HAL_MMC_CardCSDTypeDef;
   
      
    

                                                                              
      
    
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

} HAL_MMC_CardCIDTypeDef;
   
      
    

#if defined (USE_HAL_MMC_REGISTER_CALLBACKS) && (USE_HAL_MMC_REGISTER_CALLBACKS == 1U)
                                                                              
      
    
typedef enum
{
  HAL_MMC_TX_CPLT_CB_ID                 = 0x00U,                                                         
  HAL_MMC_RX_CPLT_CB_ID                 = 0x01U,                                                         
  HAL_MMC_ERROR_CB_ID                   = 0x02U,                                                         
  HAL_MMC_ABORT_CB_ID                   = 0x03U,                                                         
#if defined(STM32L4P5xx) || defined(STM32L4Q5xx) || defined(STM32L4R5xx) || defined(STM32L4R7xx) || defined(STM32L4R9xx) || defined(STM32L4S5xx) || defined(STM32L4S7xx) || defined(STM32L4S9xx)
  HAL_MMC_READ_DMA_DBL_BUF0_CPLT_CB_ID  = 0x04U,                                                         
  HAL_MMC_READ_DMA_DBL_BUF1_CPLT_CB_ID  = 0x05U,                                                         
  HAL_MMC_WRITE_DMA_DBL_BUF0_CPLT_CB_ID = 0x06U,                                                         
  HAL_MMC_WRITE_DMA_DBL_BUF1_CPLT_CB_ID = 0x07U,                                                         
#endif                                                                                                                           

  HAL_MMC_MSP_INIT_CB_ID                = 0x10U,                                                         
  HAL_MMC_MSP_DEINIT_CB_ID              = 0x11U                                                          
} HAL_MMC_CallbackIDTypeDef;
   
      
    

                                                                       
      
    
typedef void (*pMMC_CallbackTypeDef)(MMC_HandleTypeDef *hmmc);
   
      
    
#endif
   
      
    

                                                                                
                                                       
      
    

#define MMC_BLOCKSIZE              512U                                 

                                                                                              
      
    
#define HAL_MMC_ERROR_NONE                     SDMMC_ERROR_NONE                                                                                         
#define HAL_MMC_ERROR_CMD_CRC_FAIL             SDMMC_ERROR_CMD_CRC_FAIL                                                                                 
#define HAL_MMC_ERROR_DATA_CRC_FAIL            SDMMC_ERROR_DATA_CRC_FAIL                                                                                
#define HAL_MMC_ERROR_CMD_RSP_TIMEOUT          SDMMC_ERROR_CMD_RSP_TIMEOUT                                                                              
#define HAL_MMC_ERROR_DATA_TIMEOUT             SDMMC_ERROR_DATA_TIMEOUT                                                                                 
#define HAL_MMC_ERROR_TX_UNDERRUN              SDMMC_ERROR_TX_UNDERRUN                                                                                  
#define HAL_MMC_ERROR_RX_OVERRUN               SDMMC_ERROR_RX_OVERRUN                                                                                   
#define HAL_MMC_ERROR_ADDR_MISALIGNED          SDMMC_ERROR_ADDR_MISALIGNED                                                                              
#define HAL_MMC_ERROR_BLOCK_LEN_ERR            SDMMC_ERROR_BLOCK_LEN_ERR                                                                            
                                                                                                                                                       
#define HAL_MMC_ERROR_ERASE_SEQ_ERR            SDMMC_ERROR_ERASE_SEQ_ERR                                                                                
#define HAL_MMC_ERROR_BAD_ERASE_PARAM          SDMMC_ERROR_BAD_ERASE_PARAM                                                                              
#define HAL_MMC_ERROR_WRITE_PROT_VIOLATION     SDMMC_ERROR_WRITE_PROT_VIOLATION                                                                         
#define HAL_MMC_ERROR_LOCK_UNLOCK_FAILED       SDMMC_ERROR_LOCK_UNLOCK_FAILED                                                                  
                                                                                                                                                       
#define HAL_MMC_ERROR_COM_CRC_FAILED           SDMMC_ERROR_COM_CRC_FAILED                                                                               
#define HAL_MMC_ERROR_ILLEGAL_CMD              SDMMC_ERROR_ILLEGAL_CMD                                                                                  
#define HAL_MMC_ERROR_CARD_ECC_FAILED          SDMMC_ERROR_CARD_ECC_FAILED                                                                              
#define HAL_MMC_ERROR_CC_ERR                   SDMMC_ERROR_CC_ERR                                                                                       
#define HAL_MMC_ERROR_GENERAL_UNKNOWN_ERR      SDMMC_ERROR_GENERAL_UNKNOWN_ERR                                                                          
#define HAL_MMC_ERROR_STREAM_READ_UNDERRUN     SDMMC_ERROR_STREAM_READ_UNDERRUN                                                                         
#define HAL_MMC_ERROR_STREAM_WRITE_OVERRUN     SDMMC_ERROR_STREAM_WRITE_OVERRUN                                                                         
#define HAL_MMC_ERROR_CID_CSD_OVERWRITE        SDMMC_ERROR_CID_CSD_OVERWRITE                                                                            
#define HAL_MMC_ERROR_WP_ERASE_SKIP            SDMMC_ERROR_WP_ERASE_SKIP                                                                                
#define HAL_MMC_ERROR_CARD_ECC_DISABLED        SDMMC_ERROR_CARD_ECC_DISABLED                                                                            
#define HAL_MMC_ERROR_ERASE_RESET              SDMMC_ERROR_ERASE_RESET                                                                             
                                                                                                                                                       
#define HAL_MMC_ERROR_AKE_SEQ_ERR              SDMMC_ERROR_AKE_SEQ_ERR                                                                                  
#define HAL_MMC_ERROR_INVALID_VOLTRANGE        SDMMC_ERROR_INVALID_VOLTRANGE                                                                            
#define HAL_MMC_ERROR_ADDR_OUT_OF_RANGE        SDMMC_ERROR_ADDR_OUT_OF_RANGE                                                                            
#define HAL_MMC_ERROR_REQUEST_NOT_APPLICABLE   SDMMC_ERROR_REQUEST_NOT_APPLICABLE                                                                       
#define HAL_MMC_ERROR_PARAM                    SDMMC_ERROR_INVALID_PARAMETER                                                                            
#define HAL_MMC_ERROR_UNSUPPORTED_FEATURE      SDMMC_ERROR_UNSUPPORTED_FEATURE                                                                          
#define HAL_MMC_ERROR_BUSY                     SDMMC_ERROR_BUSY                                                                                         
#define HAL_MMC_ERROR_DMA                      SDMMC_ERROR_DMA                                                                                          
#define HAL_MMC_ERROR_TIMEOUT                  SDMMC_ERROR_TIMEOUT                                                                                      

#if defined (USE_HAL_MMC_REGISTER_CALLBACKS) && (USE_HAL_MMC_REGISTER_CALLBACKS == 1U)
#define HAL_MMC_ERROR_INVALID_CALLBACK         SDMMC_ERROR_INVALID_PARAMETER                                                                            
#endif
   
      
    

                                                                    
      
    
#define   MMC_CONTEXT_NONE                            0x00000000U                                           
#define   MMC_CONTEXT_READ_SINGLE_BLOCK               0x00000001U                                           
#define   MMC_CONTEXT_READ_MULTIPLE_BLOCK             0x00000002U                                           
#define   MMC_CONTEXT_WRITE_SINGLE_BLOCK              0x00000010U                                           
#define   MMC_CONTEXT_WRITE_MULTIPLE_BLOCK            0x00000020U                                           
#define   MMC_CONTEXT_IT                              0x00000008U                                           
#define   MMC_CONTEXT_DMA                             0x00000080U                                           

   
      
    

                                                             
      
    
   
          
    
#define MMC_HIGH_VOLTAGE_RANGE         0x80FF8000U                                      
#define MMC_DUAL_VOLTAGE_RANGE         0x80FF8080U                                      
#define MMC_LOW_VOLTAGE_RANGE          0x80000080U                                      
#define EMMC_HIGH_VOLTAGE_RANGE        0xC0FF8000U                                      
#define EMMC_DUAL_VOLTAGE_RANGE        0xC0FF8080U                                      
#define EMMC_LOW_VOLTAGE_RANGE         0xC0000080U                                      
#define MMC_INVALID_VOLTAGE_RANGE      0x0001FF01U
   
      
    

                                                             
      
    
#define  MMC_LOW_CAPACITY_CARD                0x00000000U                                         
#define  MMC_HIGH_CAPACITY_CARD               0x00000001U                                                     

   
      
    

#if defined(STM32L4P5xx) || defined(STM32L4Q5xx) || defined(STM32L4R5xx) || defined(STM32L4R7xx) || defined(STM32L4R9xx) || defined(STM32L4S5xx) || defined(STM32L4S7xx) || defined(STM32L4S9xx)
                                                           
      
    
#define HAL_MMC_ERASE             0x00000000U                                                                                           
#define HAL_MMC_TRIM              0x00000001U                                                                                           
#define HAL_MMC_DISCARD           0x00000003U                                                                                           
#define HAL_MMC_SECURE_ERASE      0x80000000U                                                                                           
#define HAL_MMC_SECURE_TRIM_STEP1 0x80000001U                                                                                           
#define HAL_MMC_SECURE_TRIM_STEP2 0x80008000U                                                                                           

#define IS_MMC_ERASE_TYPE(TYPE) (((TYPE) == HAL_MMC_ERASE)             || \
                                 ((TYPE) == HAL_MMC_TRIM)              || \
                                 ((TYPE) == HAL_MMC_DISCARD)           || \
                                 ((TYPE) == HAL_MMC_SECURE_ERASE)      || \
                                 ((TYPE) == HAL_MMC_SECURE_TRIM_STEP1) || \
                                 ((TYPE) == HAL_MMC_SECURE_TRIM_STEP2))
   
      
    

                                                                    
      
    
#define HAL_MMC_SRT_ERASE                   0x00000001U                                                                                                        
#define HAL_MMC_SRT_WRITE_CHAR_ERASE        0x00000002U                                                                                                        
#define HAL_MMC_SRT_WRITE_CHAR_COMPL_RANDOM 0x00000004U                                                                                                        
#define HAL_MMC_SRT_VENDOR_DEFINED          0x00000008U                                                                                                        


#define IS_MMC_SRT_TYPE(TYPE) (((TYPE) == HAL_MMC_SRT_ERASE)                   || \
                               ((TYPE) == HAL_MMC_SRT_WRITE_CHAR_ERASE)        || \
                               ((TYPE) == HAL_MMC_SRT_WRITE_CHAR_COMPL_RANDOM) || \
                               ((TYPE) == HAL_MMC_SRT_VENDOR_DEFINED))
   
      
    
#endif                                                                                                                                                                                                   

   
      
    

                                                                                
                                                     
                                                                         
      
    
                                  
                                    
                
    
#if defined (USE_HAL_MMC_REGISTER_CALLBACKS) && (USE_HAL_MMC_REGISTER_CALLBACKS == 1U)
#define __HAL_MMC_RESET_HANDLE_STATE(__HANDLE__)           do {                                              \
                                                                (__HANDLE__)->State = HAL_MMC_STATE_RESET; \
                                                                (__HANDLE__)->MspInitCallback = NULL;       \
                                                                (__HANDLE__)->MspDeInitCallback = NULL;     \
                                                              } while(0)
#else
#define __HAL_MMC_RESET_HANDLE_STATE(__HANDLE__)           ((__HANDLE__)->State = HAL_MMC_STATE_RESET)
#endif

#if !defined(STM32L4P5xx) && !defined(STM32L4Q5xx) && !defined(STM32L4R5xx) && !defined(STM32L4R7xx) && !defined(STM32L4R9xx) && !defined(STM32L4S5xx) && !defined(STM32L4S7xx) && !defined(STM32L4S9xx)
   
                                  
                
    
#define __HAL_MMC_ENABLE(__HANDLE__) __SDMMC_ENABLE((__HANDLE__)->Instance)

   
                                   
                
    
#define __HAL_MMC_DISABLE(__HANDLE__) __SDMMC_DISABLE((__HANDLE__)->Instance)

   
                                          
                
    
#define __HAL_MMC_DMA_ENABLE(__HANDLE__) __SDMMC_DMA_ENABLE((__HANDLE__)->Instance)

   
                                           
                
    
#define __HAL_MMC_DMA_DISABLE(__HANDLE__)  __SDMMC_DMA_DISABLE((__HANDLE__)->Instance)
#endif

   
                                            
                                  
                                                                               
                                                                               
                                                                                             
                                                                                            
                                                                         
                                                             
                                                                             
                                                                            
                                                                                             
                                                                                    
                                                                                            
                                                                     
                                                                                            
                                                                                 
                                                                             
                                                                          
                                                                         
                                                                         
                                                                       
                                                                   
                                                                  
                                                                    
                                                                   
                                                                                
                                                                               
                                                                                                         
                                                                          
                                                                               
                                                                              
                                                                                                    
                                                                                               
                                                                                
                
    
#define __HAL_MMC_ENABLE_IT(__HANDLE__, __INTERRUPT__) __SDMMC_ENABLE_IT((__HANDLE__)->Instance, (__INTERRUPT__))

   
                                             
                                  
                                                                                
                                                                               
                                                                                             
                                                                                            
                                                                         
                                                             
                                                                             
                                                                            
                                                                                             
                                                                                    
                                                                                            
                                                                     
                                                                                            
                                                                                 
                                                                             
                                                                          
                                                                         
                                                                         
                                                                       
                                                                   
                                                                  
                                                                    
                                                                   
                                                                                
                                                                               
                                                                                                         
                                                                          
                                                                               
                                                                              
                                                                                                    
                                                                                               
                                                                                
                
    
#define __HAL_MMC_DISABLE_IT(__HANDLE__, __INTERRUPT__) __SDMMC_DISABLE_IT((__HANDLE__)->Instance, (__INTERRUPT__))

   
                                                               
                                  
                                                  
                                                               
                                                                                     
                                                                                    
                                                                 
                                                     
                                                                     
                                                                    
                                                                                     
                                                                            
                                                                                    
                                                             
                                                                                    
                                                                         
                                                                         
                                                                            
                                                                     
                                                                  
                                                                 
                                                                 
                                                               
                                                           
                                                          
                                                            
                                                           
                                                                                 
                                                                                                 
                                                                        
                                                                       
                                                                  
                                                                       
                                                                      
                                                                                            
                                                                                       
                                                              
                                                                        
                                                     
    
#define __HAL_MMC_GET_FLAG(__HANDLE__, __FLAG__) __SDMMC_GET_FLAG((__HANDLE__)->Instance, (__FLAG__))

   
                                          
                                  
                                                  
                                                                                
                                                                                     
                                                                                    
                                                                 
                                                     
                                                                     
                                                                    
                                                                                     
                                                                            
                                                                                    
                                                             
                                                                                    
                                                                         
                                                                                                 
                                                                  
                                                                       
                                                                      
                                                                                            
                                                                                       
                                                              
                                                                        
                
    
#define __HAL_MMC_CLEAR_FLAG(__HANDLE__, __FLAG__) __SDMMC_CLEAR_FLAG((__HANDLE__)->Instance, (__FLAG__))

   
                                                                          
                                  
                                                                         
                                                               
                                                                                             
                                                                                            
                                                                         
                                                             
                                                                             
                                                                            
                                                                                             
                                                                                    
                                                                                            
                                                                     
                                                                                            
                                                                                 
                                                                             
                                                                          
                                                                         
                                                                         
                                                                       
                                                                   
                                                                  
                                                                    
                                                                   
                                                                                
                                                                               
                                                                                                         
                                                                          
                                                                               
                                                                              
                                                                                                    
                                                                                               
                                                                                
                                                   
    
#define __HAL_MMC_GET_IT(__HANDLE__, __INTERRUPT__) __SDMMC_GET_IT((__HANDLE__)->Instance, (__INTERRUPT__))

   
                                                   
                                  
                                                                        
                                                                                
                                                                                             
                                                                                            
                                                                         
                                                             
                                                                             
                                                                            
                                                                                             
                                                                                    
                                                                                            
                                                                     
                                                                                              
                                                                                 
                                                                           
                                                                         
                                                                    
                                                                      
                                                                                                         
                                                                          
                                                                               
                                                                              
                                                                                                    
                                                                                               
                                                                                
                
    
#define __HAL_MMC_CLEAR_IT(__HANDLE__, __INTERRUPT__) __SDMMC_CLEAR_IT((__HANDLE__)->Instance, (__INTERRUPT__))

   
      
    

#if defined(STM32L4P5xx) || defined(STM32L4Q5xx) || defined(STM32L4R5xx) || defined(STM32L4R7xx) || defined(STM32L4R9xx) || defined(STM32L4S5xx) || defined(STM32L4S7xx) || defined(STM32L4S9xx)
                                      
#include "stm32l4xx_hal_mmc_ex.h"
#endif                                                                                                                           

                                                                                
                                                           
      
    

                                                                                          
      
    
HAL_StatusTypeDef HAL_MMC_Init(MMC_HandleTypeDef *hmmc);
HAL_StatusTypeDef HAL_MMC_InitCard(MMC_HandleTypeDef *hmmc);
HAL_StatusTypeDef HAL_MMC_DeInit(MMC_HandleTypeDef *hmmc);
void HAL_MMC_MspInit(MMC_HandleTypeDef *hmmc);
void HAL_MMC_MspDeInit(MMC_HandleTypeDef *hmmc);

   
      
    

                                                                                
      
    
                            
HAL_StatusTypeDef HAL_MMC_ReadBlocks(MMC_HandleTypeDef *hmmc, uint8_t *pData, uint32_t BlockAdd,
                                     uint32_t NumberOfBlocks, uint32_t Timeout);
HAL_StatusTypeDef HAL_MMC_WriteBlocks(MMC_HandleTypeDef *hmmc, const uint8_t *pData, uint32_t BlockAdd,
                                      uint32_t NumberOfBlocks, uint32_t Timeout);
HAL_StatusTypeDef HAL_MMC_Erase(MMC_HandleTypeDef *hmmc, uint32_t BlockStartAdd, uint32_t BlockEndAdd);
                           
HAL_StatusTypeDef HAL_MMC_ReadBlocks_IT(MMC_HandleTypeDef *hmmc, uint8_t *pData, uint32_t BlockAdd,
                                        uint32_t NumberOfBlocks);
HAL_StatusTypeDef HAL_MMC_WriteBlocks_IT(MMC_HandleTypeDef *hmmc, uint8_t *pData, uint32_t BlockAdd,
                                         uint32_t NumberOfBlocks);
                            
HAL_StatusTypeDef HAL_MMC_ReadBlocks_DMA(MMC_HandleTypeDef *hmmc, uint8_t *pData, uint32_t BlockAdd,
                                         uint32_t NumberOfBlocks);
HAL_StatusTypeDef HAL_MMC_WriteBlocks_DMA(MMC_HandleTypeDef *hmmc, uint8_t *pData, uint32_t BlockAdd,
                                          uint32_t NumberOfBlocks);

void HAL_MMC_IRQHandler(MMC_HandleTypeDef *hmmc);

                                          
void HAL_MMC_TxCpltCallback(MMC_HandleTypeDef *hmmc);
void HAL_MMC_RxCpltCallback(MMC_HandleTypeDef *hmmc);
void HAL_MMC_ErrorCallback(MMC_HandleTypeDef *hmmc);
void HAL_MMC_AbortCallback(MMC_HandleTypeDef *hmmc);

#if defined (USE_HAL_MMC_REGISTER_CALLBACKS) && (USE_HAL_MMC_REGISTER_CALLBACKS == 1U)
                                            
HAL_StatusTypeDef HAL_MMC_RegisterCallback(MMC_HandleTypeDef *hmmc, HAL_MMC_CallbackIDTypeDef CallbackId,
                                           pMMC_CallbackTypeDef pCallback);
HAL_StatusTypeDef HAL_MMC_UnRegisterCallback(MMC_HandleTypeDef *hmmc, HAL_MMC_CallbackIDTypeDef CallbackId);
#endif
   
      
    

                                                                        
      
    
HAL_StatusTypeDef HAL_MMC_ConfigWideBusOperation(MMC_HandleTypeDef *hmmc, uint32_t WideMode);
#if defined(STM32L4P5xx) || defined(STM32L4Q5xx) || defined(STM32L4R5xx) || defined(STM32L4R7xx) || defined(STM32L4R9xx) || defined(STM32L4S5xx) || defined(STM32L4S7xx) || defined(STM32L4S9xx)
HAL_StatusTypeDef HAL_MMC_ConfigSpeedBusOperation(MMC_HandleTypeDef *hmmc, uint32_t SpeedMode);
#endif                                                                                                                           
   
      
    

                                                                      
      
    
HAL_MMC_CardStateTypeDef HAL_MMC_GetCardState(MMC_HandleTypeDef *hmmc);
HAL_StatusTypeDef HAL_MMC_GetCardCID(MMC_HandleTypeDef *hmmc, HAL_MMC_CardCIDTypeDef *pCID);
HAL_StatusTypeDef HAL_MMC_GetCardCSD(MMC_HandleTypeDef *hmmc, HAL_MMC_CardCSDTypeDef *pCSD);
HAL_StatusTypeDef HAL_MMC_GetCardInfo(MMC_HandleTypeDef *hmmc, HAL_MMC_CardInfoTypeDef *pCardInfo);
HAL_StatusTypeDef HAL_MMC_GetCardExtCSD(MMC_HandleTypeDef *hmmc, uint32_t *pExtCSD, uint32_t Timeout);
   
      
    

                                                                                 
      
    
HAL_MMC_StateTypeDef HAL_MMC_GetState(const MMC_HandleTypeDef *hmmc);
uint32_t HAL_MMC_GetError(const MMC_HandleTypeDef *hmmc);
   
      
    

                                                                       
      
    
HAL_StatusTypeDef HAL_MMC_Abort(MMC_HandleTypeDef *hmmc);
HAL_StatusTypeDef HAL_MMC_Abort_IT(MMC_HandleTypeDef *hmmc);
   
      
    
#if defined(STM32L4P5xx) || defined(STM32L4Q5xx) || defined(STM32L4R5xx) || defined(STM32L4R7xx) || defined(STM32L4R9xx) || defined(STM32L4S5xx) || defined(STM32L4S7xx) || defined(STM32L4S9xx)
                                                                       
      
    
HAL_StatusTypeDef HAL_MMC_EraseSequence(MMC_HandleTypeDef *hmmc, uint32_t EraseType, uint32_t BlockStartAdd,
                                        uint32_t BlockEndAdd);
HAL_StatusTypeDef HAL_MMC_Sanitize(MMC_HandleTypeDef *hmmc);
HAL_StatusTypeDef HAL_MMC_ConfigSecRemovalType(MMC_HandleTypeDef *hmmc, uint32_t SRTMode);
HAL_StatusTypeDef HAL_MMC_GetSupportedSecRemovalType(MMC_HandleTypeDef *hmmc, uint32_t *SupportedSRT);
   
      
    

                                                                       
      
    
HAL_StatusTypeDef HAL_MMC_SleepDevice(MMC_HandleTypeDef *hmmc);
HAL_StatusTypeDef HAL_MMC_AwakeDevice(MMC_HandleTypeDef *hmmc);
   
      
    
#endif                                                                                                                                                                                                   

   
      
    
                                                                                
                                                 
      
    

   
      
    

                                                                                
                                                     
      
    
#define MMC_EXT_CSD_DATA_SEC_SIZE_INDEX 61
#define MMC_EXT_CSD_DATA_SEC_SIZE_POS   8
   
      
    

                                                                                
                                                         
      
    

   
      
    

                                                                                
                                                         
      
    

   
      
    

                                                                                
                                                   
      
    

   
      
    

                                                                                
                                                                               
      
    

   
      
    

                                                                                
                                                         
      
    

   
      
    


   
      
    

   
      
    

   
      
    

#ifdef __cplusplus
}
#endif

#endif             

#endif                          
