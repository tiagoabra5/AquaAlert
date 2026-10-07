/**
  ******************************************************************************
  * @file    stm32l4xx_hal_qspi.h
  * @author  MCD Application Team
  * @brief   Header file of QSPI HAL module.
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

                                                                                
#ifndef STM32L4xx_HAL_QSPI_H
#define STM32L4xx_HAL_QSPI_H

#ifdef __cplusplus
 extern "C" {
#endif

                                                                                
#include "stm32l4xx_hal_def.h"

#if defined(QUADSPI)

                                    
      
    

                    
      
    

                                                                                
                                                     
      
    

   
                                          
    
typedef struct
{
  uint32_t ClockPrescaler;                                                                                   
                                                                                     
  uint32_t FifoThreshold;                                                                                         
                                                                                   
  uint32_t SampleShifting;                                                                                      
                                                                                                                              
                                                                                              
  uint32_t FlashSize;                                                                                            
                                                                                                           
                                                                                                          
                                                                        
                                                                                    
  uint32_t ChipSelectHighTime;                                                                                        
                                                                                                          
                                                                                                  
  uint32_t ClockMode;                                                                                                
                                                                                         
#if defined(QUADSPI_CR_DFM)
  uint32_t FlashID;                                                      
                                                                                            
  uint32_t DualFlash;                                                
                                                                                              
#endif
}QSPI_InitTypeDef;

   
                                               
    
typedef enum
{
  HAL_QSPI_STATE_RESET             = 0x00U,                                                                 
  HAL_QSPI_STATE_READY             = 0x01U,                                                                 
  HAL_QSPI_STATE_BUSY              = 0x02U,                                                                 
  HAL_QSPI_STATE_BUSY_INDIRECT_TX  = 0x12U,                                                                 
  HAL_QSPI_STATE_BUSY_INDIRECT_RX  = 0x22U,                                                                 
  HAL_QSPI_STATE_BUSY_AUTO_POLLING = 0x42U,                                                                 
  HAL_QSPI_STATE_BUSY_MEM_MAPPED   = 0x82U,                                                                 
  HAL_QSPI_STATE_ABORT             = 0x08U,                                                                 
  HAL_QSPI_STATE_ERROR             = 0x04U                                                                  
}HAL_QSPI_StateTypeDef;

   
                                            
    
#if (USE_HAL_QSPI_REGISTER_CALLBACKS == 1)
typedef struct __QSPI_HandleTypeDef
#else
typedef struct
#endif
{
  QUADSPI_TypeDef            *Instance;                                                
  QSPI_InitTypeDef           Init;                                                     
  uint8_t                    *pTxBuffPtr;                                              
  __IO uint32_t              TxXferSize;                                               
  __IO uint32_t              TxXferCount;                                              
  uint8_t                    *pRxBuffPtr;                                              
  __IO uint32_t              RxXferSize;                                               
  __IO uint32_t              RxXferCount;                                              
  DMA_HandleTypeDef          *hdma;                                                    
  __IO HAL_LockTypeDef       Lock;                                                     
  __IO HAL_QSPI_StateTypeDef State;                                                    
  __IO uint32_t              ErrorCode;                                                
  uint32_t                   Timeout;                                                  
#if (USE_HAL_QSPI_REGISTER_CALLBACKS == 1)
  void (* ErrorCallback)        (struct __QSPI_HandleTypeDef *hqspi);
  void (* AbortCpltCallback)    (struct __QSPI_HandleTypeDef *hqspi);
  void (* FifoThresholdCallback)(struct __QSPI_HandleTypeDef *hqspi);
  void (* CmdCpltCallback)      (struct __QSPI_HandleTypeDef *hqspi);
  void (* RxCpltCallback)       (struct __QSPI_HandleTypeDef *hqspi);
  void (* TxCpltCallback)       (struct __QSPI_HandleTypeDef *hqspi);
  void (* RxHalfCpltCallback)   (struct __QSPI_HandleTypeDef *hqspi);
  void (* TxHalfCpltCallback)   (struct __QSPI_HandleTypeDef *hqspi);
  void (* StatusMatchCallback)  (struct __QSPI_HandleTypeDef *hqspi);
  void (* TimeOutCallback)      (struct __QSPI_HandleTypeDef *hqspi);

  void (* MspInitCallback)      (struct __QSPI_HandleTypeDef *hqspi);
  void (* MspDeInitCallback)    (struct __QSPI_HandleTypeDef *hqspi);
#endif
}QSPI_HandleTypeDef;

   
                                             
    
typedef struct
{
  uint32_t Instruction;                                               
                                                                                                
  uint32_t Address;                                                                                              
                                                                                                       
  uint32_t AlternateBytes;                                                                                                      
                                                                                                       
  uint32_t AddressSize;                                     
                                                                                           
  uint32_t AlternateBytesSize;                                      
                                                                                                  
  uint32_t DummyCycles;                                                
                                                                                    
  uint32_t InstructionMode;                                     
                                                                                               
  uint32_t AddressMode;                                     
                                                                                           
  uint32_t AlternateByteMode;                                       
                                                                                                  
  uint32_t DataMode;                                                                             
                                                                                        
  uint32_t NbData;                                                                                       
                                                                                                                    
                                                        
  uint32_t DdrMode;                                                                                             
                                                                                       
  uint32_t DdrHoldHalfCycle;                                                                           
                                                                                 
                                                               
                                                                                                
  uint32_t SIOOMode;                                                           
                                                                                        
}QSPI_CommandTypeDef;

   
                                                                     
    
typedef struct
{
  uint32_t Match;                                                                                                   
                                                                                             
  uint32_t Mask;                                                                                
                                                                                             
  uint32_t Interval;                                                                                                    
                                                                                         
  uint32_t StatusBytesSize;                                                       
                                                                                    
  uint32_t MatchMode;                                                               
                                                                                         
  uint32_t AutomaticStop;                                                                 
                                                                                             
}QSPI_AutoPollingTypeDef;

   
                                                                      
    
typedef struct
{
  uint32_t TimeOutPeriod;                                                                                                       
                                                                                         
  uint32_t TimeOutActivation;                                                                            
                                                                                                 
}QSPI_MemoryMappedTypeDef;

#if (USE_HAL_QSPI_REGISTER_CALLBACKS == 1)
   
                                                       
    
typedef enum
{
  HAL_QSPI_ERROR_CB_ID          = 0x00U,                                           
  HAL_QSPI_ABORT_CB_ID          = 0x01U,                                           
  HAL_QSPI_FIFO_THRESHOLD_CB_ID = 0x02U,                                           
  HAL_QSPI_CMD_CPLT_CB_ID       = 0x03U,                                           
  HAL_QSPI_RX_CPLT_CB_ID        = 0x04U,                                           
  HAL_QSPI_TX_CPLT_CB_ID        = 0x05U,                                           
  HAL_QSPI_RX_HALF_CPLT_CB_ID   = 0x06U,                                           
  HAL_QSPI_TX_HALF_CPLT_CB_ID   = 0x07U,                                           
  HAL_QSPI_STATUS_MATCH_CB_ID   = 0x08U,                                           
  HAL_QSPI_TIMEOUT_CB_ID        = 0x09U,                                           

  HAL_QSPI_MSP_INIT_CB_ID       = 0x0AU,                                           
  HAL_QSPI_MSP_DEINIT_CB_ID     = 0x0B0                                            
}HAL_QSPI_CallbackIDTypeDef;

   
                                                
    
typedef void (*pQSPI_CallbackTypeDef)(QSPI_HandleTypeDef *hqspi);
#endif
   
      
    

                                                                                
                                                             
      
    

                                            
      
    
#define HAL_QSPI_ERROR_NONE             0x00000000U                                 
#define HAL_QSPI_ERROR_TIMEOUT          0x00000001U                                 
#define HAL_QSPI_ERROR_TRANSFER         0x00000002U                                 
#define HAL_QSPI_ERROR_DMA              0x00000004U                                 
#define HAL_QSPI_ERROR_INVALID_PARAM    0x00000008U                                 
#if (USE_HAL_QSPI_REGISTER_CALLBACKS == 1)
#define HAL_QSPI_ERROR_INVALID_CALLBACK 0x00000010U                                 
#endif
   
      
    

                                                      
      
    
#define QSPI_SAMPLE_SHIFTING_NONE      0x00000000U                                                            
#define QSPI_SAMPLE_SHIFTING_HALFCYCLE ((uint32_t)QUADSPI_CR_SSHIFT)                                           
   
      
    

                                                               
      
    
#define QSPI_CS_HIGH_TIME_1_CYCLE      0x00000000U                                                                                                        
#define QSPI_CS_HIGH_TIME_2_CYCLE      ((uint32_t)QUADSPI_DCR_CSHT_0)                                                                                      
#define QSPI_CS_HIGH_TIME_3_CYCLE      ((uint32_t)QUADSPI_DCR_CSHT_1)                                                                                      
#define QSPI_CS_HIGH_TIME_4_CYCLE      ((uint32_t)QUADSPI_DCR_CSHT_0 | QUADSPI_DCR_CSHT_1)                                                                 
#define QSPI_CS_HIGH_TIME_5_CYCLE      ((uint32_t)QUADSPI_DCR_CSHT_2)                                                                                      
#define QSPI_CS_HIGH_TIME_6_CYCLE      ((uint32_t)QUADSPI_DCR_CSHT_2 | QUADSPI_DCR_CSHT_0)                                                                 
#define QSPI_CS_HIGH_TIME_7_CYCLE      ((uint32_t)QUADSPI_DCR_CSHT_2 | QUADSPI_DCR_CSHT_1)                                                                 
#define QSPI_CS_HIGH_TIME_8_CYCLE      ((uint32_t)QUADSPI_DCR_CSHT)                                                                                        
   
      
    

                                            
      
    
#define QSPI_CLOCK_MODE_0              0x00000000U                                                             
#define QSPI_CLOCK_MODE_3              ((uint32_t)QUADSPI_DCR_CKMODE)                                          
   
      
    

#if defined(QUADSPI_CR_DFM)
                                                 
      
    
#define QSPI_FLASH_ID_1                0x00000000U                                       
#define QSPI_FLASH_ID_2                ((uint32_t)QUADSPI_CR_FSEL)                       
   
      
    

                                                        
      
    
#define QSPI_DUALFLASH_ENABLE          ((uint32_t)QUADSPI_CR_DFM)                              
#define QSPI_DUALFLASH_DISABLE         0x00000000U                                              
   
      
    

#endif
                                                
      
    
#define QSPI_ADDRESS_8_BITS            0x00000000U                                         
#define QSPI_ADDRESS_16_BITS           ((uint32_t)QUADSPI_CCR_ADSIZE_0)                     
#define QSPI_ADDRESS_24_BITS           ((uint32_t)QUADSPI_CCR_ADSIZE_1)                     
#define QSPI_ADDRESS_32_BITS           ((uint32_t)QUADSPI_CCR_ADSIZE)                       
   
      
    

                                                               
      
    
#define QSPI_ALTERNATE_BYTES_8_BITS    0x00000000U                                                 
#define QSPI_ALTERNATE_BYTES_16_BITS   ((uint32_t)QUADSPI_CCR_ABSIZE_0)                             
#define QSPI_ALTERNATE_BYTES_24_BITS   ((uint32_t)QUADSPI_CCR_ABSIZE_1)                             
#define QSPI_ALTERNATE_BYTES_32_BITS   ((uint32_t)QUADSPI_CCR_ABSIZE)                               
   
      
    

                                                        
    
  
#define QSPI_INSTRUCTION_NONE          0x00000000U                                         
#define QSPI_INSTRUCTION_1_LINE        ((uint32_t)QUADSPI_CCR_IMODE_0)                                   
#define QSPI_INSTRUCTION_2_LINES       ((uint32_t)QUADSPI_CCR_IMODE_1)                               
#define QSPI_INSTRUCTION_4_LINES       ((uint32_t)QUADSPI_CCR_IMODE)                                  
   
      
    

                                                
    
  
#define QSPI_ADDRESS_NONE              0x00000000U                                      
#define QSPI_ADDRESS_1_LINE            ((uint32_t)QUADSPI_CCR_ADMODE_0)                               
#define QSPI_ADDRESS_2_LINES           ((uint32_t)QUADSPI_CCR_ADMODE_1)                           
#define QSPI_ADDRESS_4_LINES           ((uint32_t)QUADSPI_CCR_ADMODE)                              
   
      
    

                                                               
    
  
#define QSPI_ALTERNATE_BYTES_NONE      0x00000000U                                              
#define QSPI_ALTERNATE_BYTES_1_LINE    ((uint32_t)QUADSPI_CCR_ABMODE_0)                                       
#define QSPI_ALTERNATE_BYTES_2_LINES   ((uint32_t)QUADSPI_CCR_ABMODE_1)                                   
#define QSPI_ALTERNATE_BYTES_4_LINES   ((uint32_t)QUADSPI_CCR_ABMODE)                                      
   
      
    

                                          
      
    
#define QSPI_DATA_NONE                 0x00000000U                                  
#define QSPI_DATA_1_LINE               ((uint32_t)QUADSPI_CCR_DMODE_0)                            
#define QSPI_DATA_2_LINES              ((uint32_t)QUADSPI_CCR_DMODE_1)                        
#define QSPI_DATA_4_LINES              ((uint32_t)QUADSPI_CCR_DMODE)                           
   
      
    

                                        
      
    
#define QSPI_DDR_MODE_DISABLE          0x00000000U                                                      
#define QSPI_DDR_MODE_ENABLE           ((uint32_t)QUADSPI_CCR_DDRM)                                    
   
      
    

                                                              
      
    
#define QSPI_DDR_HHC_ANALOG_DELAY      0x00000000U                                                                            
#if defined(QUADSPI_CCR_DHHC)
#define QSPI_DDR_HHC_HALF_CLK_DELAY    ((uint32_t)QUADSPI_CCR_DHHC)                                                                    
#endif
   
      
    

                                                      
      
    
#define QSPI_SIOO_INST_EVERY_CMD       0x00000000U                                                             
#define QSPI_SIOO_INST_ONLY_FIRST_CMD  ((uint32_t)QUADSPI_CCR_SIOO)                                                  
   
      
    

                                            
      
    
#define QSPI_MATCH_MODE_AND            0x00000000U                                                          
#define QSPI_MATCH_MODE_OR             ((uint32_t)QUADSPI_CR_PMM)                                          
   
      
    

                                                    
      
    
#define QSPI_AUTOMATIC_STOP_DISABLE    0x00000000U                                                                          
#define QSPI_AUTOMATIC_STOP_ENABLE     ((uint32_t)QUADSPI_CR_APMS)                                                    
   
      
    

                                                            
      
    
#define QSPI_TIMEOUT_COUNTER_DISABLE   0x00000000U                                                                   
#define QSPI_TIMEOUT_COUNTER_ENABLE    ((uint32_t)QUADSPI_CR_TCEN)                                                                 
   
      
    

                                   
      
    
#define QSPI_FLAG_BUSY                 QUADSPI_SR_BUSY                                      
#define QSPI_FLAG_TO                   QUADSPI_SR_TOF                                                          
#define QSPI_FLAG_SM                   QUADSPI_SR_SMF                                                                    
#define QSPI_FLAG_FT                   QUADSPI_SR_FTF                                                                                                   
#define QSPI_FLAG_TC                   QUADSPI_SR_TCF                                                                                                                
#define QSPI_FLAG_TE                   QUADSPI_SR_TEF                                                              
   
      
    

                                             
      
    
#define QSPI_IT_TO                     QUADSPI_CR_TOIE                                    
#define QSPI_IT_SM                     QUADSPI_CR_SMIE                                         
#define QSPI_IT_FT                     QUADSPI_CR_FTIE                                           
#define QSPI_IT_TC                     QUADSPI_CR_TCIE                                              
#define QSPI_IT_TE                     QUADSPI_CR_TEIE                                           
   
      
    

                                                             
                                  
      
    
#define HAL_QSPI_TIMEOUT_DEFAULT_VALUE 5000U          
   
      
    

   
      
    

                                                                                
                                                       
      
    
                                   
                                   
                
    
#if (USE_HAL_QSPI_REGISTER_CALLBACKS == 1)
#define __HAL_QSPI_RESET_HANDLE_STATE(__HANDLE__)           do {                                              \
                                                                  (__HANDLE__)->State = HAL_QSPI_STATE_RESET; \
                                                                  (__HANDLE__)->MspInitCallback = NULL;       \
                                                                  (__HANDLE__)->MspDeInitCallback = NULL;     \
                                                               } while(0)
#else
#define __HAL_QSPI_RESET_HANDLE_STATE(__HANDLE__)           ((__HANDLE__)->State = HAL_QSPI_STATE_RESET)
#endif

                                       
                                                 
                
    
#define __HAL_QSPI_ENABLE(__HANDLE__)                       SET_BIT((__HANDLE__)->Instance->CR, QUADSPI_CR_EN)

                                        
                                                 
                
    
#define __HAL_QSPI_DISABLE(__HANDLE__)                      CLEAR_BIT((__HANDLE__)->Instance->CR, QUADSPI_CR_EN)

                                                
                                                 
                                                                        
                                                               
                                                      
                                                           
                                                             
                                                                
                                                             
                
    
#define __HAL_QSPI_ENABLE_IT(__HANDLE__, __INTERRUPT__)     SET_BIT((__HANDLE__)->Instance->CR, (__INTERRUPT__))


                                                 
                                                 
                                                                         
                                                               
                                                      
                                                           
                                                             
                                                                
                                                             
                
    
#define __HAL_QSPI_DISABLE_IT(__HANDLE__, __INTERRUPT__)    CLEAR_BIT((__HANDLE__)->Instance->CR, (__INTERRUPT__))

                                                                                
                                                 
                                                                       
                                                               
                                                      
                                                           
                                                             
                                                                
                                                             
                                                           
    
#define __HAL_QSPI_GET_IT_SOURCE(__HANDLE__, __INTERRUPT__) (READ_BIT((__HANDLE__)->Instance->CR, (__INTERRUPT__)) == (__INTERRUPT__))

   
                                                               
                                                 
                                                      
                                                               
                                                  
                                                     
                                                          
                                                            
                                                               
                                                            
                
    
#define __HAL_QSPI_GET_FLAG(__HANDLE__, __FLAG__)           ((READ_BIT((__HANDLE__)->Instance->SR, (__FLAG__)) != 0U) ? SET : RESET)

                                                    
                                                 
                                                                                
                                                               
                                                   
                                                        
                                                             
                                                          
                
    
#define __HAL_QSPI_CLEAR_FLAG(__HANDLE__, __FLAG__)         WRITE_REG((__HANDLE__)->Instance->FCR, (__FLAG__))
   
      
    

                                                                                
                                       
      
    

                                              
      
    
                                                                                
HAL_StatusTypeDef     HAL_QSPI_Init     (QSPI_HandleTypeDef *hqspi);
HAL_StatusTypeDef     HAL_QSPI_DeInit   (QSPI_HandleTypeDef *hqspi);
void                  HAL_QSPI_MspInit  (QSPI_HandleTypeDef *hqspi);
void                  HAL_QSPI_MspDeInit(QSPI_HandleTypeDef *hqspi);
   
      
    

                                              
      
    
                                                                                
                             
void                  HAL_QSPI_IRQHandler(QSPI_HandleTypeDef *hqspi);

                        
HAL_StatusTypeDef     HAL_QSPI_Command      (QSPI_HandleTypeDef *hqspi, QSPI_CommandTypeDef *cmd, uint32_t Timeout);
HAL_StatusTypeDef     HAL_QSPI_Transmit     (QSPI_HandleTypeDef *hqspi, uint8_t *pData, uint32_t Timeout);
HAL_StatusTypeDef     HAL_QSPI_Receive      (QSPI_HandleTypeDef *hqspi, uint8_t *pData, uint32_t Timeout);
HAL_StatusTypeDef     HAL_QSPI_Command_IT   (QSPI_HandleTypeDef *hqspi, QSPI_CommandTypeDef *cmd);
HAL_StatusTypeDef     HAL_QSPI_Transmit_IT  (QSPI_HandleTypeDef *hqspi, uint8_t *pData);
HAL_StatusTypeDef     HAL_QSPI_Receive_IT   (QSPI_HandleTypeDef *hqspi, uint8_t *pData);
HAL_StatusTypeDef     HAL_QSPI_Transmit_DMA (QSPI_HandleTypeDef *hqspi, uint8_t *pData);
HAL_StatusTypeDef     HAL_QSPI_Receive_DMA  (QSPI_HandleTypeDef *hqspi, uint8_t *pData);

                                   
HAL_StatusTypeDef     HAL_QSPI_AutoPolling   (QSPI_HandleTypeDef *hqspi, QSPI_CommandTypeDef *cmd, QSPI_AutoPollingTypeDef *cfg, uint32_t Timeout);
HAL_StatusTypeDef     HAL_QSPI_AutoPolling_IT(QSPI_HandleTypeDef *hqspi, QSPI_CommandTypeDef *cmd, QSPI_AutoPollingTypeDef *cfg);

                             
HAL_StatusTypeDef     HAL_QSPI_MemoryMapped(QSPI_HandleTypeDef *hqspi, QSPI_CommandTypeDef *cmd, QSPI_MemoryMappedTypeDef *cfg);

                                                                                
void                  HAL_QSPI_ErrorCallback        (QSPI_HandleTypeDef *hqspi);
void                  HAL_QSPI_AbortCpltCallback    (QSPI_HandleTypeDef *hqspi);
void                  HAL_QSPI_FifoThresholdCallback(QSPI_HandleTypeDef *hqspi);

                        
void                  HAL_QSPI_CmdCpltCallback      (QSPI_HandleTypeDef *hqspi);
void                  HAL_QSPI_RxCpltCallback       (QSPI_HandleTypeDef *hqspi);
void                  HAL_QSPI_TxCpltCallback       (QSPI_HandleTypeDef *hqspi);
void                  HAL_QSPI_RxHalfCpltCallback   (QSPI_HandleTypeDef *hqspi);
void                  HAL_QSPI_TxHalfCpltCallback   (QSPI_HandleTypeDef *hqspi);

                                   
void                  HAL_QSPI_StatusMatchCallback  (QSPI_HandleTypeDef *hqspi);

                             
void                  HAL_QSPI_TimeOutCallback      (QSPI_HandleTypeDef *hqspi);

#if (USE_HAL_QSPI_REGISTER_CALLBACKS == 1)
                                             
HAL_StatusTypeDef     HAL_QSPI_RegisterCallback     (QSPI_HandleTypeDef *hqspi, HAL_QSPI_CallbackIDTypeDef CallbackId, pQSPI_CallbackTypeDef pCallback);
HAL_StatusTypeDef     HAL_QSPI_UnRegisterCallback   (QSPI_HandleTypeDef *hqspi, HAL_QSPI_CallbackIDTypeDef CallbackId);
#endif
   
      
    

                                              
      
    
                                                                                
HAL_QSPI_StateTypeDef HAL_QSPI_GetState        (const QSPI_HandleTypeDef *hqspi);
uint32_t              HAL_QSPI_GetError        (const QSPI_HandleTypeDef *hqspi);
HAL_StatusTypeDef     HAL_QSPI_Abort           (QSPI_HandleTypeDef *hqspi);
HAL_StatusTypeDef     HAL_QSPI_Abort_IT        (QSPI_HandleTypeDef *hqspi);
void                  HAL_QSPI_SetTimeout      (QSPI_HandleTypeDef *hqspi, uint32_t Timeout);
HAL_StatusTypeDef     HAL_QSPI_SetFifoThreshold(QSPI_HandleTypeDef *hqspi, uint32_t Threshold);
uint32_t              HAL_QSPI_GetFifoThreshold(const QSPI_HandleTypeDef *hqspi);
#if defined(QUADSPI_CR_DFM)
HAL_StatusTypeDef     HAL_QSPI_SetFlashID      (QSPI_HandleTypeDef *hqspi, uint32_t FlashID);
#endif
   
      
    

   
      
    
                                                                                

                                                                                
                                                     
      
    
#define IS_QSPI_CLOCK_PRESCALER(PRESCALER) ((PRESCALER) <= 0xFFU)

#define IS_QSPI_FIFO_THRESHOLD(THR)        (((THR) > 0U) && ((THR) <= 16U))

#define IS_QSPI_SSHIFT(SSHIFT)             (((SSHIFT) == QSPI_SAMPLE_SHIFTING_NONE) || \
                                            ((SSHIFT) == QSPI_SAMPLE_SHIFTING_HALFCYCLE))

#define IS_QSPI_FLASH_SIZE(FSIZE)          (((FSIZE) <= 31U))

#define IS_QSPI_CS_HIGH_TIME(CSHTIME)      (((CSHTIME) == QSPI_CS_HIGH_TIME_1_CYCLE) || \
                                            ((CSHTIME) == QSPI_CS_HIGH_TIME_2_CYCLE) || \
                                            ((CSHTIME) == QSPI_CS_HIGH_TIME_3_CYCLE) || \
                                            ((CSHTIME) == QSPI_CS_HIGH_TIME_4_CYCLE) || \
                                            ((CSHTIME) == QSPI_CS_HIGH_TIME_5_CYCLE) || \
                                            ((CSHTIME) == QSPI_CS_HIGH_TIME_6_CYCLE) || \
                                            ((CSHTIME) == QSPI_CS_HIGH_TIME_7_CYCLE) || \
                                            ((CSHTIME) == QSPI_CS_HIGH_TIME_8_CYCLE))

#define IS_QSPI_CLOCK_MODE(CLKMODE)        (((CLKMODE) == QSPI_CLOCK_MODE_0) || \
                                            ((CLKMODE) == QSPI_CLOCK_MODE_3))

#if defined(QUADSPI_CR_DFM)
#define IS_QSPI_FLASH_ID(FLASH_ID)         (((FLASH_ID) == QSPI_FLASH_ID_1) || \
                                            ((FLASH_ID) == QSPI_FLASH_ID_2))

#define IS_QSPI_DUAL_FLASH_MODE(MODE)      (((MODE) == QSPI_DUALFLASH_ENABLE) || \
                                            ((MODE) == QSPI_DUALFLASH_DISABLE))

#endif
#define IS_QSPI_INSTRUCTION(INSTRUCTION)   ((INSTRUCTION) <= 0xFFU)

#define IS_QSPI_ADDRESS_SIZE(ADDR_SIZE)    (((ADDR_SIZE) == QSPI_ADDRESS_8_BITS)  || \
                                            ((ADDR_SIZE) == QSPI_ADDRESS_16_BITS) || \
                                            ((ADDR_SIZE) == QSPI_ADDRESS_24_BITS) || \
                                            ((ADDR_SIZE) == QSPI_ADDRESS_32_BITS))

#define IS_QSPI_ALTERNATE_BYTES_SIZE(SIZE) (((SIZE) == QSPI_ALTERNATE_BYTES_8_BITS)  || \
                                            ((SIZE) == QSPI_ALTERNATE_BYTES_16_BITS) || \
                                            ((SIZE) == QSPI_ALTERNATE_BYTES_24_BITS) || \
                                            ((SIZE) == QSPI_ALTERNATE_BYTES_32_BITS))

#define IS_QSPI_DUMMY_CYCLES(DCY)          ((DCY) <= 31U)

#define IS_QSPI_INSTRUCTION_MODE(MODE)     (((MODE) == QSPI_INSTRUCTION_NONE)    || \
                                            ((MODE) == QSPI_INSTRUCTION_1_LINE)  || \
                                            ((MODE) == QSPI_INSTRUCTION_2_LINES) || \
                                            ((MODE) == QSPI_INSTRUCTION_4_LINES))

#define IS_QSPI_ADDRESS_MODE(MODE)         (((MODE) == QSPI_ADDRESS_NONE)    || \
                                            ((MODE) == QSPI_ADDRESS_1_LINE)  || \
                                            ((MODE) == QSPI_ADDRESS_2_LINES) || \
                                            ((MODE) == QSPI_ADDRESS_4_LINES))

#define IS_QSPI_ALTERNATE_BYTES_MODE(MODE) (((MODE) == QSPI_ALTERNATE_BYTES_NONE)    || \
                                            ((MODE) == QSPI_ALTERNATE_BYTES_1_LINE)  || \
                                            ((MODE) == QSPI_ALTERNATE_BYTES_2_LINES) || \
                                            ((MODE) == QSPI_ALTERNATE_BYTES_4_LINES))

#define IS_QSPI_DATA_MODE(MODE)            (((MODE) == QSPI_DATA_NONE)    || \
                                            ((MODE) == QSPI_DATA_1_LINE)  || \
                                            ((MODE) == QSPI_DATA_2_LINES) || \
                                            ((MODE) == QSPI_DATA_4_LINES))

#define IS_QSPI_DDR_MODE(DDR_MODE)         (((DDR_MODE) == QSPI_DDR_MODE_DISABLE) || \
                                            ((DDR_MODE) == QSPI_DDR_MODE_ENABLE))

#if defined(QUADSPI_CCR_DHHC)
#define IS_QSPI_DDR_HHC(DDR_HHC)           (((DDR_HHC) == QSPI_DDR_HHC_ANALOG_DELAY) || \
                                            ((DDR_HHC) == QSPI_DDR_HHC_HALF_CLK_DELAY))

#else
#define IS_QSPI_DDR_HHC(DDR_HHC)           (((DDR_HHC) == QSPI_DDR_HHC_ANALOG_DELAY))

#endif
#define IS_QSPI_SIOO_MODE(SIOO_MODE)       (((SIOO_MODE) == QSPI_SIOO_INST_EVERY_CMD) || \
                                            ((SIOO_MODE) == QSPI_SIOO_INST_ONLY_FIRST_CMD))

#define IS_QSPI_INTERVAL(INTERVAL)         ((INTERVAL) <= QUADSPI_PIR_INTERVAL)

#define IS_QSPI_STATUS_BYTES_SIZE(SIZE)    (((SIZE) >= 1U) && ((SIZE) <= 4U))

#define IS_QSPI_MATCH_MODE(MODE)           (((MODE) == QSPI_MATCH_MODE_AND) || \
                                            ((MODE) == QSPI_MATCH_MODE_OR))

#define IS_QSPI_AUTOMATIC_STOP(APMS)       (((APMS) == QSPI_AUTOMATIC_STOP_DISABLE) || \
                                            ((APMS) == QSPI_AUTOMATIC_STOP_ENABLE))

#define IS_QSPI_TIMEOUT_ACTIVATION(TCEN)   (((TCEN) == QSPI_TIMEOUT_COUNTER_DISABLE) || \
                                            ((TCEN) == QSPI_TIMEOUT_COUNTER_ENABLE))

#define IS_QSPI_TIMEOUT_PERIOD(PERIOD)     ((PERIOD) <= 0xFFFFU)
   
    
  
                                                                                

   
      
    

   
      
    

#endif                       

#ifdef __cplusplus
}
#endif

#endif                           
