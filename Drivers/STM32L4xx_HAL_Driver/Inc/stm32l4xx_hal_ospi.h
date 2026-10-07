/**
  ******************************************************************************
  * @file    stm32l4xx_hal_ospi.h
  * @author  MCD Application Team
  * @brief   Header file of OSPI HAL module.
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

                                                                                
#ifndef STM32L4xx_HAL_OSPI_H
#define STM32L4xx_HAL_OSPI_H

#ifdef __cplusplus
extern "C" {
#endif

                                                                                
#include "stm32l4xx_hal_def.h"

#if defined(OCTOSPI) || defined(OCTOSPI1) || defined(OCTOSPI2)

                                    
      
    

                    
      
    

                                                                                
                                                     
      
    

   
                                         
    
typedef struct
{
  uint32_t FifoThreshold;                                                                                        
                                                                                                        
                                                                        
                                                                                            
  uint32_t DualQuad;                                                                                       
                                                                                                         
                                                                                                 
  uint32_t MemoryType;                                                                                 
                                                                                                   
  uint32_t DeviceSize;                                                                                      
                                                                                                          
                                                               
                                                                                            
  uint32_t ChipSelectHighTime;                                                                          
                                                                             
                                                                                           
  uint32_t FreeRunningClock;                                                        
                                                                                                         
  uint32_t ClockMode;                                                                                       
                                                                                                  
  uint32_t ClockPrescaler;                                                                      
                                                                                     
                                                                                             
  uint32_t SampleShifting;                                                                           
                                                                                     
                                                                                                       
  uint32_t DelayHoldQuarterCycle;                                                  
                                                                                                              
  uint32_t ChipSelectBoundary;                                                            
                                                                                                    
                                                                                            
  uint32_t DelayBlockBypass;                                                                                 
                                                              
                                                                                                         
#if   defined (OCTOSPI_DCR3_MAXTRAN)
  uint32_t MaxTran;                                                                                           
                                                                                                                   
                                                      
                                                                                             
#endif
#if   defined (OCTOSPI_DCR4_REFRESH)
  uint32_t Refresh;                                                                                              
                                                                  
                                                                                                    
#endif
} OSPI_InitTypeDef;

   
                                                
    
#if defined (USE_HAL_OSPI_REGISTER_CALLBACKS) && (USE_HAL_OSPI_REGISTER_CALLBACKS == 1U)
typedef struct __OSPI_HandleTypeDef
#else
typedef struct
#endif                                                                                   
{
  OCTOSPI_TypeDef            *Instance;                                                             
  OSPI_InitTypeDef           Init;                                                                  
  uint8_t                    *pBuffPtr;                                                             
  __IO uint32_t              XferSize;                                                              
  __IO uint32_t              XferCount;                                                             
  DMA_HandleTypeDef     *hdma;                                                            
  __IO uint32_t              State;                                                                 
  __IO uint32_t              ErrorCode;                                                             
  uint32_t                   Timeout;                                                               
#if defined (USE_HAL_OSPI_REGISTER_CALLBACKS) && (USE_HAL_OSPI_REGISTER_CALLBACKS == 1U)
  void (* ErrorCallback)(struct __OSPI_HandleTypeDef *hospi);
  void (* AbortCpltCallback)(struct __OSPI_HandleTypeDef *hospi);
  void (* FifoThresholdCallback)(struct __OSPI_HandleTypeDef *hospi);
  void (* CmdCpltCallback)(struct __OSPI_HandleTypeDef *hospi);
  void (* RxCpltCallback)(struct __OSPI_HandleTypeDef *hospi);
  void (* TxCpltCallback)(struct __OSPI_HandleTypeDef *hospi);
  void (* RxHalfCpltCallback)(struct __OSPI_HandleTypeDef *hospi);
  void (* TxHalfCpltCallback)(struct __OSPI_HandleTypeDef *hospi);
  void (* StatusMatchCallback)(struct __OSPI_HandleTypeDef *hospi);
  void (* TimeOutCallback)(struct __OSPI_HandleTypeDef *hospi);

  void (* MspInitCallback)(struct __OSPI_HandleTypeDef *hospi);
  void (* MspDeInitCallback)(struct __OSPI_HandleTypeDef *hospi);
#endif                                                                                   
} OSPI_HandleTypeDef;

   
                                                         
    
typedef struct
{
  uint32_t OperationType;                                                                                      
                                                                                                             
                                                                        
                                                                                                      
  uint32_t FlashId;                                                                                           
                                                                                                                 
                                                                                                
  uint32_t Instruction;                                                                         
                                                                                                    
  uint32_t InstructionMode;                                                         
                                                                                                        
  uint32_t InstructionSize;                                                         
                                                                                                        
  uint32_t InstructionDtrMode;                                                                      
                                                                                                           
  uint32_t Address;                                                                         
                                                                                                    
  uint32_t AddressMode;                                                         
                                                                                                    
  uint32_t AddressSize;                                                         
                                                                                                    
  uint32_t AddressDtrMode;                                                                      
                                                                                                       
  uint32_t AlternateBytes;                                                                          
                                                                                                    
  uint32_t AlternateBytesMode;                                                          
                                                                                                           
  uint32_t AlternateBytesSize;                                                          
                                                                                                           
  uint32_t AlternateBytesDtrMode;                                                                       
                                                                                                              
  uint32_t DataMode;                                                         
                                                                                                 
  uint32_t NbData;                                                                                       
                                                                                     
                                                                                                    
  uint32_t DataDtrMode;                                                                      
                                                                                                    
  uint32_t DummyCycles;                                                                                       
                                                                                            
  uint32_t DQSMode;                                                                     
                                                                                                
  uint32_t SIOOMode;                                                       
                                                                                                 
} OSPI_RegularCmdTypeDef;

   
                                                                
    
typedef struct
{
  uint32_t RWRecoveryTime;                                                                                      
                                                                                        
  uint32_t AccessTime;                                                                             
                                                                                        
  uint32_t WriteZeroLatency;                                                             
                                                                                                    
  uint32_t LatencyMode;                                              
                                                                                               
} OSPI_HyperbusCfgTypeDef;

   
                                                          
    
typedef struct
{
  uint32_t AddressSpace;                                                                 
                                                                                            
  uint32_t Address;                                                                
                                                                                           
  uint32_t AddressSize;                                                
                                                                                           
  uint32_t NbData;                                                                              
                                                                            
                                                                                        
                                                                                                                 
  uint32_t DQSMode;                                                            
                                                                                       
} OSPI_HyperbusCmdTypeDef;

   
                                                                         
    
typedef struct
{
  uint32_t Match;                                                                                                     
                                                                                               
  uint32_t Mask;                                                                                  
                                                                                               
  uint32_t MatchMode;                                                                 
                                                                                           
  uint32_t AutomaticStop;                                                                   
                                                                                               
  uint32_t Interval;                                                                                                      
                                                                                           
} OSPI_AutoPollingTypeDef;

   
                                                                          
    
typedef struct
{
  uint32_t TimeOutActivation;                                                                              
                                                                                                   
  uint32_t TimeOutPeriod;                                                                                                         
                                                                                           
} OSPI_MemoryMappedTypeDef;

   
                                                                 
    
typedef struct
{
  uint32_t ClkPort;                                                                                             
                                                                                        
  uint32_t DQSPort;                                                                                            
                                                                                                                      
  uint32_t NCSPort;                                                                                            
                                                                                        
  uint32_t IOLowPort;                                                                                               
                                                                                             
  uint32_t IOHighPort;                                                                                              
                                                                                             
#if   defined (OCTOSPIM_CR_MUXEN)
  uint32_t Req2AckTime;                                                                                                 
                                                                                                                   
                                                                                          
#endif
} OSPIM_CfgTypeDef;

#if defined (USE_HAL_OSPI_REGISTER_CALLBACKS) && (USE_HAL_OSPI_REGISTER_CALLBACKS == 1U)
   
                                                       
    
typedef enum
{
  HAL_OSPI_ERROR_CB_ID          = 0x00U,                                           
  HAL_OSPI_ABORT_CB_ID          = 0x01U,                                           
  HAL_OSPI_FIFO_THRESHOLD_CB_ID = 0x02U,                                           
  HAL_OSPI_CMD_CPLT_CB_ID       = 0x03U,                                           
  HAL_OSPI_RX_CPLT_CB_ID        = 0x04U,                                           
  HAL_OSPI_TX_CPLT_CB_ID        = 0x05U,                                           
  HAL_OSPI_RX_HALF_CPLT_CB_ID   = 0x06U,                                           
  HAL_OSPI_TX_HALF_CPLT_CB_ID   = 0x07U,                                           
  HAL_OSPI_STATUS_MATCH_CB_ID   = 0x08U,                                           
  HAL_OSPI_TIMEOUT_CB_ID        = 0x09U,                                           

  HAL_OSPI_MSP_INIT_CB_ID       = 0x0AU,                                           
  HAL_OSPI_MSP_DEINIT_CB_ID     = 0x0BU                                            
} HAL_OSPI_CallbackIDTypeDef;

   
                                                
    
typedef void (*pOSPI_CallbackTypeDef)(OSPI_HandleTypeDef *hospi);
#endif                                                                                   
   
      
    

                                                                                
                                                             
      
    

                                   
      
    
#define HAL_OSPI_STATE_RESET                 ((uint32_t)0x00000000U)                                                                                    
#define HAL_OSPI_STATE_HYPERBUS_INIT         ((uint32_t)0x00000001U)                                                                                    
#define HAL_OSPI_STATE_READY                 ((uint32_t)0x00000002U)                                                                                    
#define HAL_OSPI_STATE_CMD_CFG               ((uint32_t)0x00000004U)                                                                                    
#define HAL_OSPI_STATE_READ_CMD_CFG          ((uint32_t)0x00000014U)                                                                                    
#define HAL_OSPI_STATE_WRITE_CMD_CFG         ((uint32_t)0x00000024U)                                                                                    
#define HAL_OSPI_STATE_BUSY_CMD              ((uint32_t)0x00000008U)                                                                                    
#define HAL_OSPI_STATE_BUSY_TX               ((uint32_t)0x00000018U)                                                                                    
#define HAL_OSPI_STATE_BUSY_RX               ((uint32_t)0x00000028U)                                                                                    
#define HAL_OSPI_STATE_BUSY_AUTO_POLLING     ((uint32_t)0x00000048U)                                                                                    
#define HAL_OSPI_STATE_BUSY_MEM_MAPPED       ((uint32_t)0x00000088U)                                                                                    
#define HAL_OSPI_STATE_ABORT                 ((uint32_t)0x00000100U)                                                                                    
#define HAL_OSPI_STATE_ERROR                 ((uint32_t)0x00000200U)                                                                                    
   
      
    

                                            
      
    
#define HAL_OSPI_ERROR_NONE                  ((uint32_t)0x00000000U)                                                                                           
#define HAL_OSPI_ERROR_TIMEOUT               ((uint32_t)0x00000001U)                                                                                           
#define HAL_OSPI_ERROR_TRANSFER              ((uint32_t)0x00000002U)                                                                                           
#define HAL_OSPI_ERROR_DMA                   ((uint32_t)0x00000004U)                                                                                           
#define HAL_OSPI_ERROR_INVALID_PARAM         ((uint32_t)0x00000008U)                                                                                           
#define HAL_OSPI_ERROR_INVALID_SEQUENCE      ((uint32_t)0x00000010U)                                                                                           
#if defined (USE_HAL_OSPI_REGISTER_CALLBACKS) && (USE_HAL_OSPI_REGISTER_CALLBACKS == 1U)
#define HAL_OSPI_ERROR_INVALID_CALLBACK      ((uint32_t)0x00000020U)                                                                                           
#endif                                                                                  
   
      
    

                                          
      
    
#define HAL_OSPI_DUALQUAD_DISABLE            ((uint32_t)0x00000000U)                                                                        
#define HAL_OSPI_DUALQUAD_ENABLE             ((uint32_t)OCTOSPI_CR_DQM)                                                                     
   
      
    

                                              
      
    
#define HAL_OSPI_MEMTYPE_MICRON              ((uint32_t)0x00000000U)                                                                  
#define HAL_OSPI_MEMTYPE_MACRONIX            ((uint32_t)OCTOSPI_DCR1_MTYP_0)                                                          
#if !defined(STM32L4R5xx)&&!defined(STM32L4R7xx)&&!defined(STM32L4R9xx)&&!defined(STM32L4S5xx)&&!defined(STM32L4S7xx)&&!defined(STM32L4S9xx)
#define HAL_OSPI_MEMTYPE_APMEMORY            ((uint32_t)OCTOSPI_DCR1_MTYP_1)                                                          
#endif
#define HAL_OSPI_MEMTYPE_MACRONIX_RAM        ((uint32_t)(OCTOSPI_DCR1_MTYP_1 | OCTOSPI_DCR1_MTYP_0))                                  
#define HAL_OSPI_MEMTYPE_HYPERBUS            ((uint32_t)OCTOSPI_DCR1_MTYP_2)                                                          
   
      
    

                                                           
      
    
#define HAL_OSPI_FREERUNCLK_DISABLE          ((uint32_t)0x00000000U)                                                                                      
#define HAL_OSPI_FREERUNCLK_ENABLE           ((uint32_t)OCTOSPI_DCR1_FRCK)                                                                                
   
      
    

                                            
      
    
#define HAL_OSPI_CLOCK_MODE_0                ((uint32_t)0x00000000U)                                                                                     
#define HAL_OSPI_CLOCK_MODE_3                ((uint32_t)OCTOSPI_DCR1_CKMODE)                                                                             
   
      
    

                                                      
      
    
#define HAL_OSPI_SAMPLE_SHIFTING_NONE        ((uint32_t)0x00000000U)                                                                
#define HAL_OSPI_SAMPLE_SHIFTING_HALFCYCLE   ((uint32_t)OCTOSPI_TCR_SSHIFT)                                                         
   
      
    

                                                                      
      
    
#define HAL_OSPI_DHQC_DISABLE                ((uint32_t)0x00000000U)                                                                     
#define HAL_OSPI_DHQC_ENABLE                 ((uint32_t)OCTOSPI_TCR_DHQC)                                                                
   
      
    

                                                           
      
    
#define HAL_OSPI_DELAY_BLOCK_USED            ((uint32_t)0x00000000U)                                                                                             
#define HAL_OSPI_DELAY_BLOCK_BYPASSED        ((uint32_t)OCTOSPI_DCR1_DLYBYP)                                                                                     
   
      
    

                                                    
      
    
#define HAL_OSPI_OPTYPE_COMMON_CFG           ((uint32_t)0x00000000U)                                                                                                     
#define HAL_OSPI_OPTYPE_READ_CFG             ((uint32_t)0x00000001U)                                                                                                     
#define HAL_OSPI_OPTYPE_WRITE_CFG            ((uint32_t)0x00000002U)                                                                                                     
   
      
    

                                        
      
    
#define HAL_OSPI_FLASH_ID_1                  ((uint32_t)0x00000000U)                                                                 
#define HAL_OSPI_FLASH_ID_2                  ((uint32_t)OCTOSPI_CR_FSEL)                                                             
   
      
    

                                                        
      
    
#define HAL_OSPI_INSTRUCTION_NONE            ((uint32_t)0x00000000U)                                                                             
#define HAL_OSPI_INSTRUCTION_1_LINE          ((uint32_t)OCTOSPI_CCR_IMODE_0)                                                                     
#define HAL_OSPI_INSTRUCTION_2_LINES         ((uint32_t)OCTOSPI_CCR_IMODE_1)                                                                     
#define HAL_OSPI_INSTRUCTION_4_LINES         ((uint32_t)(OCTOSPI_CCR_IMODE_0 | OCTOSPI_CCR_IMODE_1))                                             
#define HAL_OSPI_INSTRUCTION_8_LINES         ((uint32_t)OCTOSPI_CCR_IMODE_2)                                                                     
   
      
    

                                                        
      
    
#define HAL_OSPI_INSTRUCTION_8_BITS          ((uint32_t)0x00000000U)                                                                   
#define HAL_OSPI_INSTRUCTION_16_BITS         ((uint32_t)OCTOSPI_CCR_ISIZE_0)                                                           
#define HAL_OSPI_INSTRUCTION_24_BITS         ((uint32_t)OCTOSPI_CCR_ISIZE_1)                                                           
#define HAL_OSPI_INSTRUCTION_32_BITS         ((uint32_t)OCTOSPI_CCR_ISIZE)                                                             
   
      
    

                                                               
      
    
#define HAL_OSPI_INSTRUCTION_DTR_DISABLE     ((uint32_t)0x00000000U)                                                                                        
#define HAL_OSPI_INSTRUCTION_DTR_ENABLE      ((uint32_t)OCTOSPI_CCR_IDTR)                                                                                   
   
      
    

                                                
      
    
#define HAL_OSPI_ADDRESS_NONE                ((uint32_t)0x00000000U)                                                                         
#define HAL_OSPI_ADDRESS_1_LINE              ((uint32_t)OCTOSPI_CCR_ADMODE_0)                                                                
#define HAL_OSPI_ADDRESS_2_LINES             ((uint32_t)OCTOSPI_CCR_ADMODE_1)                                                                
#define HAL_OSPI_ADDRESS_4_LINES             ((uint32_t)(OCTOSPI_CCR_ADMODE_0 | OCTOSPI_CCR_ADMODE_1))                                       
#define HAL_OSPI_ADDRESS_8_LINES             ((uint32_t)OCTOSPI_CCR_ADMODE_2)                                                                
   
      
    

                                                
      
    
#define HAL_OSPI_ADDRESS_8_BITS              ((uint32_t)0x00000000U)                                                               
#define HAL_OSPI_ADDRESS_16_BITS             ((uint32_t)OCTOSPI_CCR_ADSIZE_0)                                                      
#define HAL_OSPI_ADDRESS_24_BITS             ((uint32_t)OCTOSPI_CCR_ADSIZE_1)                                                      
#define HAL_OSPI_ADDRESS_32_BITS             ((uint32_t)OCTOSPI_CCR_ADSIZE)                                                        
   
      
    

                                                       
      
    
#define HAL_OSPI_ADDRESS_DTR_DISABLE         ((uint32_t)0x00000000U)                                                                                    
#define HAL_OSPI_ADDRESS_DTR_ENABLE          ((uint32_t)OCTOSPI_CCR_ADDTR)                                                                              
   
      
    

                                                               
      
    
#define HAL_OSPI_ALTERNATE_BYTES_NONE        ((uint32_t)0x00000000U)                                                                                 
#define HAL_OSPI_ALTERNATE_BYTES_1_LINE      ((uint32_t)OCTOSPI_CCR_ABMODE_0)                                                                        
#define HAL_OSPI_ALTERNATE_BYTES_2_LINES     ((uint32_t)OCTOSPI_CCR_ABMODE_1)                                                                        
#define HAL_OSPI_ALTERNATE_BYTES_4_LINES     ((uint32_t)(OCTOSPI_CCR_ABMODE_0 | OCTOSPI_CCR_ABMODE_1))                                               
#define HAL_OSPI_ALTERNATE_BYTES_8_LINES     ((uint32_t)OCTOSPI_CCR_ABMODE_2)                                                                        
   
      
    

                                                               
      
    
#define HAL_OSPI_ALTERNATE_BYTES_8_BITS      ((uint32_t)0x00000000U)                                                                       
#define HAL_OSPI_ALTERNATE_BYTES_16_BITS     ((uint32_t)OCTOSPI_CCR_ABSIZE_0)                                                              
#define HAL_OSPI_ALTERNATE_BYTES_24_BITS     ((uint32_t)OCTOSPI_CCR_ABSIZE_1)                                                              
#define HAL_OSPI_ALTERNATE_BYTES_32_BITS     ((uint32_t)OCTOSPI_CCR_ABSIZE)                                                                
   
      
    

                                                                      
      
    
#define HAL_OSPI_ALTERNATE_BYTES_DTR_DISABLE ((uint32_t)0x00000000U)                                                                                            
#define HAL_OSPI_ALTERNATE_BYTES_DTR_ENABLE  ((uint32_t)OCTOSPI_CCR_ABDTR)                                                                                      
   
      
    

                                          
      
    
#define HAL_OSPI_DATA_NONE                   ((uint32_t)0x00000000U)                                                                      
#define HAL_OSPI_DATA_1_LINE                 ((uint32_t)OCTOSPI_CCR_DMODE_0)                                                              
#define HAL_OSPI_DATA_2_LINES                ((uint32_t)OCTOSPI_CCR_DMODE_1)                                                              
#define HAL_OSPI_DATA_4_LINES                ((uint32_t)(OCTOSPI_CCR_DMODE_0 | OCTOSPI_CCR_DMODE_1))                                      
#define HAL_OSPI_DATA_8_LINES                ((uint32_t)OCTOSPI_CCR_DMODE_2)                                                              
   
      
    

                                                 
      
    
#define HAL_OSPI_DATA_DTR_DISABLE            ((uint32_t)0x00000000U)                                                                                 
#define HAL_OSPI_DATA_DTR_ENABLE             ((uint32_t)OCTOSPI_CCR_DDTR)                                                                            
   
      
    

                                        
      
    
#define HAL_OSPI_DQS_DISABLE                 ((uint32_t)0x00000000U)                                                             
#define HAL_OSPI_DQS_ENABLE                  ((uint32_t)OCTOSPI_CCR_DQSE)                                                        
   
      
    

                                          
      
    
#define HAL_OSPI_SIOO_INST_EVERY_CMD         ((uint32_t)0x00000000U)                                                                                            
#define HAL_OSPI_SIOO_INST_ONLY_FIRST_CMD    ((uint32_t)OCTOSPI_CCR_SIOO)                                                                                       
   
      
    

                                                                               
      
    
#define HAL_OSPI_LATENCY_ON_WRITE            ((uint32_t)0x00000000U)                                                                             
#define HAL_OSPI_NO_LATENCY_ON_WRITE         ((uint32_t)OCTOSPI_HLCR_WZL)                                                                        
   
      
    

                                                         
      
    
#define HAL_OSPI_VARIABLE_LATENCY            ((uint32_t)0x00000000U)                                                                         
#define HAL_OSPI_FIXED_LATENCY               ((uint32_t)OCTOSPI_HLCR_LM)                                                                     
   
      
    

                                                           
      
    
#define HAL_OSPI_MEMORY_ADDRESS_SPACE        ((uint32_t)0x00000000U)                                                                       
#define HAL_OSPI_REGISTER_ADDRESS_SPACE      ((uint32_t)OCTOSPI_DCR1_MTYP_0)                                                               
   
      
    

                                            
      
    
#define HAL_OSPI_MATCH_MODE_AND              ((uint32_t)0x00000000U)                                                                                     
#define HAL_OSPI_MATCH_MODE_OR               ((uint32_t)OCTOSPI_CR_PMM)                                                                                  
   
      
    

                                                    
      
    
#define HAL_OSPI_AUTOMATIC_STOP_DISABLE      ((uint32_t)0x00000000U)                                                                                                    
#define HAL_OSPI_AUTOMATIC_STOP_ENABLE       ((uint32_t)OCTOSPI_CR_APMS)                                                                                                
   
      
    

                                                            
      
    
#define HAL_OSPI_TIMEOUT_COUNTER_DISABLE     ((uint32_t)0x00000000U)                                                                                                           
#define HAL_OSPI_TIMEOUT_COUNTER_ENABLE      ((uint32_t)OCTOSPI_CR_TCEN)                                                                                                       
   
      
    

                                   
      
    
#define HAL_OSPI_FLAG_BUSY                   OCTOSPI_SR_BUSY                                                                                                                                                                 
#define HAL_OSPI_FLAG_TO                     OCTOSPI_SR_TOF                                                                                                                                                                  
#define HAL_OSPI_FLAG_SM                     OCTOSPI_SR_SMF                                                                                                                                                                  
#define HAL_OSPI_FLAG_FT                     OCTOSPI_SR_FTF                                                                                                                                                                  
#define HAL_OSPI_FLAG_TC                     OCTOSPI_SR_TCF                                                                                                                                                                  
#define HAL_OSPI_FLAG_TE                     OCTOSPI_SR_TEF                                                                                                                                                                  
   
      
    

                                             
      
    
#define HAL_OSPI_IT_TO                       OCTOSPI_CR_TOIE                                                                                                
#define HAL_OSPI_IT_SM                       OCTOSPI_CR_SMIE                                                                                                
#define HAL_OSPI_IT_FT                       OCTOSPI_CR_FTIE                                                                                                
#define HAL_OSPI_IT_TC                       OCTOSPI_CR_TCIE                                                                                                
#define HAL_OSPI_IT_TE                       OCTOSPI_CR_TEIE                                                                                                
   
      
    

                                                             
      
    
#define HAL_OSPI_TIMEOUT_DEFAULT_VALUE       ((uint32_t)5000U)                                                        
   
      
    

                                                  
      
    
#define HAL_OSPIM_IOPORT_NONE              ((uint32_t)0x00000000U)                                                              
#define HAL_OSPIM_IOPORT_1_LOW             ((uint32_t)(OCTOSPIM_PCR_IOLEN | 0x1U))                                                  
#define HAL_OSPIM_IOPORT_1_HIGH            ((uint32_t)(OCTOSPIM_PCR_IOHEN | 0x1U))                                                  
#define HAL_OSPIM_IOPORT_2_LOW             ((uint32_t)(OCTOSPIM_PCR_IOLEN | 0x2U))                                                  
#define HAL_OSPIM_IOPORT_2_HIGH            ((uint32_t)(OCTOSPIM_PCR_IOHEN | 0x2U))                                                  
   
      
    
   
      
    

                                                                                
                                                       
      
    
                                   
                                                 
                
    
#if defined (USE_HAL_OSPI_REGISTER_CALLBACKS) && (USE_HAL_OSPI_REGISTER_CALLBACKS == 1U)
#define __HAL_OSPI_RESET_HANDLE_STATE(__HANDLE__)           do {                                              \
                                                                  (__HANDLE__)->State = HAL_OSPI_STATE_RESET; \
                                                                  (__HANDLE__)->MspInitCallback = NULL;       \
                                                                  (__HANDLE__)->MspDeInitCallback = NULL;     \
                                                               } while(0)
#else
#define __HAL_OSPI_RESET_HANDLE_STATE(__HANDLE__)           ((__HANDLE__)->State = HAL_OSPI_STATE_RESET)
#endif                                                                                   

                                       
                                                 
                
    
#define __HAL_OSPI_ENABLE(__HANDLE__)                       SET_BIT((__HANDLE__)->Instance->CR, OCTOSPI_CR_EN)

                                        
                                                 
                
    
#define __HAL_OSPI_DISABLE(__HANDLE__)                      CLEAR_BIT((__HANDLE__)->Instance->CR, OCTOSPI_CR_EN)

                                                
                                                 
                                                                        
                                                               
                                                          
                                                               
                                                                 
                                                                    
                                                                 
                
    
#define __HAL_OSPI_ENABLE_IT(__HANDLE__, __INTERRUPT__)     SET_BIT((__HANDLE__)->Instance->CR, (__INTERRUPT__))


                                                 
                                                 
                                                                         
                                                               
                                                          
                                                               
                                                                 
                                                                    
                                                                 
                
    
#define __HAL_OSPI_DISABLE_IT(__HANDLE__, __INTERRUPT__)    CLEAR_BIT((__HANDLE__)->Instance->CR, (__INTERRUPT__))

                                                                                
                                                 
                                                                       
                                                               
                                                          
                                                               
                                                                 
                                                                    
                                                                 
                                                           
    
#define __HAL_OSPI_GET_IT_SOURCE(__HANDLE__, __INTERRUPT__) (READ_BIT((__HANDLE__)->Instance->CR, (__INTERRUPT__))\
                                                             == (__INTERRUPT__))

   
                                                               
                                                 
                                                      
                                                               
                                                      
                                                         
                                                              
                                                                
                                                                   
                                                                
                
    
#define __HAL_OSPI_GET_FLAG(__HANDLE__, __FLAG__)           ((READ_BIT((__HANDLE__)->Instance->SR, (__FLAG__)) \
                                                              != 0U) ? SET : RESET)

                                                    
                                                 
                                                                                
                                                               
                                                         
                                                              
                                                                   
                                                                
                
    
#define __HAL_OSPI_CLEAR_FLAG(__HANDLE__, __FLAG__)         WRITE_REG((__HANDLE__)->Instance->FCR, (__FLAG__))

   
      
    

                                                                                
                                       
      
    

                                                                                
                                              
      
    
HAL_StatusTypeDef     HAL_OSPI_Init(OSPI_HandleTypeDef *hospi);
void                  HAL_OSPI_MspInit(OSPI_HandleTypeDef *hospi);
HAL_StatusTypeDef     HAL_OSPI_DeInit(OSPI_HandleTypeDef *hospi);
void                  HAL_OSPI_MspDeInit(OSPI_HandleTypeDef *hospi);

   
      
    

                                                                                
                                              
      
    
                               
void                  HAL_OSPI_IRQHandler(OSPI_HandleTypeDef *hospi);

                                          
HAL_StatusTypeDef     HAL_OSPI_Command(OSPI_HandleTypeDef *hospi, OSPI_RegularCmdTypeDef *cmd, uint32_t Timeout);
HAL_StatusTypeDef     HAL_OSPI_Command_IT(OSPI_HandleTypeDef *hospi, OSPI_RegularCmdTypeDef *cmd);
HAL_StatusTypeDef     HAL_OSPI_HyperbusCfg(OSPI_HandleTypeDef *hospi, OSPI_HyperbusCfgTypeDef *cfg, uint32_t Timeout);
HAL_StatusTypeDef     HAL_OSPI_HyperbusCmd(OSPI_HandleTypeDef *hospi, OSPI_HyperbusCmdTypeDef *cmd, uint32_t Timeout);

                                  
HAL_StatusTypeDef     HAL_OSPI_Transmit(OSPI_HandleTypeDef *hospi, uint8_t *pData, uint32_t Timeout);
HAL_StatusTypeDef     HAL_OSPI_Receive(OSPI_HandleTypeDef *hospi, uint8_t *pData, uint32_t Timeout);
HAL_StatusTypeDef     HAL_OSPI_Transmit_IT(OSPI_HandleTypeDef *hospi, uint8_t *pData);
HAL_StatusTypeDef     HAL_OSPI_Receive_IT(OSPI_HandleTypeDef *hospi, uint8_t *pData);
HAL_StatusTypeDef     HAL_OSPI_Transmit_DMA(OSPI_HandleTypeDef *hospi, uint8_t *pData);
HAL_StatusTypeDef     HAL_OSPI_Receive_DMA(OSPI_HandleTypeDef *hospi, uint8_t *pData);

                                             
HAL_StatusTypeDef     HAL_OSPI_AutoPolling(OSPI_HandleTypeDef *hospi, OSPI_AutoPollingTypeDef *cfg, uint32_t Timeout);
HAL_StatusTypeDef     HAL_OSPI_AutoPolling_IT(OSPI_HandleTypeDef *hospi, OSPI_AutoPollingTypeDef *cfg);

                                       
HAL_StatusTypeDef     HAL_OSPI_MemoryMapped(OSPI_HandleTypeDef *hospi, OSPI_MemoryMappedTypeDef *cfg);
uint32_t              HAL_OSPI_IsMemoryMapped(OSPI_HandleTypeDef *hospi);

                                                                                
void                  HAL_OSPI_ErrorCallback(OSPI_HandleTypeDef *hospi);
void                  HAL_OSPI_AbortCpltCallback(OSPI_HandleTypeDef *hospi);
void                  HAL_OSPI_FifoThresholdCallback(OSPI_HandleTypeDef *hospi);

                                  
void                  HAL_OSPI_CmdCpltCallback(OSPI_HandleTypeDef *hospi);
void                  HAL_OSPI_RxCpltCallback(OSPI_HandleTypeDef *hospi);
void                  HAL_OSPI_TxCpltCallback(OSPI_HandleTypeDef *hospi);
void                  HAL_OSPI_RxHalfCpltCallback(OSPI_HandleTypeDef *hospi);
void                  HAL_OSPI_TxHalfCpltCallback(OSPI_HandleTypeDef *hospi);

                                             
void                  HAL_OSPI_StatusMatchCallback(OSPI_HandleTypeDef *hospi);

                                       
void                  HAL_OSPI_TimeOutCallback(OSPI_HandleTypeDef *hospi);

#if defined (USE_HAL_OSPI_REGISTER_CALLBACKS) && (USE_HAL_OSPI_REGISTER_CALLBACKS == 1U)
                                             
HAL_StatusTypeDef     HAL_OSPI_RegisterCallback(OSPI_HandleTypeDef *hospi, HAL_OSPI_CallbackIDTypeDef CallbackID,
                                                pOSPI_CallbackTypeDef pCallback);
HAL_StatusTypeDef     HAL_OSPI_UnRegisterCallback(OSPI_HandleTypeDef *hospi, HAL_OSPI_CallbackIDTypeDef CallbackID);
#endif                                                                                   
   
      
    

                                                                                
                                              
      
    
HAL_StatusTypeDef     HAL_OSPI_Abort(OSPI_HandleTypeDef *hospi);
HAL_StatusTypeDef     HAL_OSPI_Abort_IT(OSPI_HandleTypeDef *hospi);
HAL_StatusTypeDef     HAL_OSPI_SetFifoThreshold(OSPI_HandleTypeDef *hospi, uint32_t Threshold);
uint32_t              HAL_OSPI_GetFifoThreshold(const OSPI_HandleTypeDef *hospi);
HAL_StatusTypeDef     HAL_OSPI_SetTimeout(OSPI_HandleTypeDef *hospi, uint32_t Timeout);
uint32_t              HAL_OSPI_GetError(const OSPI_HandleTypeDef *hospi);
uint32_t              HAL_OSPI_GetState(const OSPI_HandleTypeDef *hospi);

   
      
    

                                                                                
                                              
      
    
HAL_StatusTypeDef     HAL_OSPIM_Config(OSPI_HandleTypeDef *hospi, OSPIM_CfgTypeDef *cfg, uint32_t Timeout);

   
      
    

   
      
    
                                                                                

                                                                                
   
         
    
#define IS_OSPI_FIFO_THRESHOLD(THRESHOLD)  (((THRESHOLD) >= 1U) && ((THRESHOLD) <= 32U))

#define IS_OSPI_DUALQUAD_MODE(MODE)        (((MODE) == HAL_OSPI_DUALQUAD_DISABLE) || \
                                            ((MODE) == HAL_OSPI_DUALQUAD_ENABLE))

#if defined(STM32L4R5xx) || defined(STM32L4R7xx) || defined(STM32L4R9xx) || defined(STM32L4S5xx) || defined(STM32L4S7xx) || defined(STM32L4S9xx)
#define IS_OSPI_MEMORY_TYPE(TYPE)          (((TYPE) == HAL_OSPI_MEMTYPE_MICRON)       || \
                                            ((TYPE) == HAL_OSPI_MEMTYPE_MACRONIX)     || \
                                            ((TYPE) == HAL_OSPI_MEMTYPE_MACRONIX_RAM) || \
                                            ((TYPE) == HAL_OSPI_MEMTYPE_HYPERBUS))
#else
#define IS_OSPI_MEMORY_TYPE(TYPE)          (((TYPE) == HAL_OSPI_MEMTYPE_MICRON)       || \
                                            ((TYPE) == HAL_OSPI_MEMTYPE_MACRONIX)     || \
                                            ((TYPE) == HAL_OSPI_MEMTYPE_APMEMORY)     || \
                                            ((TYPE) == HAL_OSPI_MEMTYPE_MACRONIX_RAM) || \
                                            ((TYPE) == HAL_OSPI_MEMTYPE_HYPERBUS))
#endif

#define IS_OSPI_DEVICE_SIZE(SIZE)          (((SIZE) >= 1U) && ((SIZE) <= 32U))

#define IS_OSPI_CS_HIGH_TIME(TIME)         (((TIME) >= 1U) && ((TIME) <= 64U))

#define IS_OSPI_FREE_RUN_CLK(CLK)          (((CLK) == HAL_OSPI_FREERUNCLK_DISABLE) || \
                                            ((CLK) == HAL_OSPI_FREERUNCLK_ENABLE))

#define IS_OSPI_CLOCK_MODE(MODE)           (((MODE) == HAL_OSPI_CLOCK_MODE_0) || \
                                            ((MODE) == HAL_OSPI_CLOCK_MODE_3))

#define IS_OSPI_CLK_PRESCALER(PRESCALER)   (((PRESCALER) >= 1U) && ((PRESCALER) <= 256U))

#define IS_OSPI_SAMPLE_SHIFTING(CYCLE)     (((CYCLE) == HAL_OSPI_SAMPLE_SHIFTING_NONE)      || \
                                            ((CYCLE) == HAL_OSPI_SAMPLE_SHIFTING_HALFCYCLE))

#define IS_OSPI_DHQC(CYCLE)                (((CYCLE) == HAL_OSPI_DHQC_DISABLE) || \
                                            ((CYCLE) == HAL_OSPI_DHQC_ENABLE))

#define IS_OSPI_OPERATION_TYPE(TYPE)       (((TYPE) == HAL_OSPI_OPTYPE_COMMON_CFG) || \
                                            ((TYPE) == HAL_OSPI_OPTYPE_READ_CFG)   || \
                                            ((TYPE) == HAL_OSPI_OPTYPE_WRITE_CFG))

#define IS_OSPI_FLASH_ID(FLASHID)          (((FLASHID) == HAL_OSPI_FLASH_ID_1) || \
                                            ((FLASHID) == HAL_OSPI_FLASH_ID_2))

#define IS_OSPI_INSTRUCTION_MODE(MODE)     (((MODE) == HAL_OSPI_INSTRUCTION_NONE)    || \
                                            ((MODE) == HAL_OSPI_INSTRUCTION_1_LINE)  || \
                                            ((MODE) == HAL_OSPI_INSTRUCTION_2_LINES) || \
                                            ((MODE) == HAL_OSPI_INSTRUCTION_4_LINES) || \
                                            ((MODE) == HAL_OSPI_INSTRUCTION_8_LINES))

#define IS_OSPI_INSTRUCTION_SIZE(SIZE)     (((SIZE) == HAL_OSPI_INSTRUCTION_8_BITS)  || \
                                            ((SIZE) == HAL_OSPI_INSTRUCTION_16_BITS) || \
                                            ((SIZE) == HAL_OSPI_INSTRUCTION_24_BITS) || \
                                            ((SIZE) == HAL_OSPI_INSTRUCTION_32_BITS))

#define IS_OSPI_INSTRUCTION_DTR_MODE(MODE) (((MODE) == HAL_OSPI_INSTRUCTION_DTR_DISABLE) || \
                                            ((MODE) == HAL_OSPI_INSTRUCTION_DTR_ENABLE))

#define IS_OSPI_ADDRESS_MODE(MODE)         (((MODE) == HAL_OSPI_ADDRESS_NONE)    || \
                                            ((MODE) == HAL_OSPI_ADDRESS_1_LINE)  || \
                                            ((MODE) == HAL_OSPI_ADDRESS_2_LINES) || \
                                            ((MODE) == HAL_OSPI_ADDRESS_4_LINES) || \
                                            ((MODE) == HAL_OSPI_ADDRESS_8_LINES))

#define IS_OSPI_ADDRESS_SIZE(SIZE)         (((SIZE) == HAL_OSPI_ADDRESS_8_BITS)  || \
                                            ((SIZE) == HAL_OSPI_ADDRESS_16_BITS) || \
                                            ((SIZE) == HAL_OSPI_ADDRESS_24_BITS) || \
                                            ((SIZE) == HAL_OSPI_ADDRESS_32_BITS))

#define IS_OSPI_ADDRESS_DTR_MODE(MODE)     (((MODE) == HAL_OSPI_ADDRESS_DTR_DISABLE) || \
                                            ((MODE) == HAL_OSPI_ADDRESS_DTR_ENABLE))

#define IS_OSPI_ALT_BYTES_MODE(MODE)       (((MODE) == HAL_OSPI_ALTERNATE_BYTES_NONE)    || \
                                            ((MODE) == HAL_OSPI_ALTERNATE_BYTES_1_LINE)  || \
                                            ((MODE) == HAL_OSPI_ALTERNATE_BYTES_2_LINES) || \
                                            ((MODE) == HAL_OSPI_ALTERNATE_BYTES_4_LINES) || \
                                            ((MODE) == HAL_OSPI_ALTERNATE_BYTES_8_LINES))

#define IS_OSPI_ALT_BYTES_SIZE(SIZE)       (((SIZE) == HAL_OSPI_ALTERNATE_BYTES_8_BITS)  || \
                                            ((SIZE) == HAL_OSPI_ALTERNATE_BYTES_16_BITS) || \
                                            ((SIZE) == HAL_OSPI_ALTERNATE_BYTES_24_BITS) || \
                                            ((SIZE) == HAL_OSPI_ALTERNATE_BYTES_32_BITS))

#define IS_OSPI_ALT_BYTES_DTR_MODE(MODE)   (((MODE) == HAL_OSPI_ALTERNATE_BYTES_DTR_DISABLE) || \
                                            ((MODE) == HAL_OSPI_ALTERNATE_BYTES_DTR_ENABLE))

#define IS_OSPI_DATA_MODE(MODE)            (((MODE) == HAL_OSPI_DATA_NONE)    || \
                                            ((MODE) == HAL_OSPI_DATA_1_LINE)  || \
                                            ((MODE) == HAL_OSPI_DATA_2_LINES) || \
                                            ((MODE) == HAL_OSPI_DATA_4_LINES) || \
                                            ((MODE) == HAL_OSPI_DATA_8_LINES))

#define IS_OSPI_NUMBER_DATA(NUMBER)        ((NUMBER) >= 1U)

#define IS_OSPI_DATA_DTR_MODE(MODE)        (((MODE) == HAL_OSPI_DATA_DTR_DISABLE) || \
                                            ((MODE) == HAL_OSPI_DATA_DTR_ENABLE))

#define IS_OSPI_DUMMY_CYCLES(NUMBER)       ((NUMBER) <= 31U)

#define IS_OSPI_DQS_MODE(MODE)             (((MODE) == HAL_OSPI_DQS_DISABLE) || \
                                            ((MODE) == HAL_OSPI_DQS_ENABLE))

#define IS_OSPI_SIOO_MODE(MODE)            (((MODE) == HAL_OSPI_SIOO_INST_EVERY_CMD) || \
                                            ((MODE) == HAL_OSPI_SIOO_INST_ONLY_FIRST_CMD))

#define IS_OSPI_RW_RECOVERY_TIME(NUMBER)   ((NUMBER) <= 255U)

#define IS_OSPI_ACCESS_TIME(NUMBER)        ((NUMBER) <= 255U)

#define IS_OSPI_WRITE_ZERO_LATENCY(MODE)   (((MODE) == HAL_OSPI_LATENCY_ON_WRITE) || \
                                            ((MODE) == HAL_OSPI_NO_LATENCY_ON_WRITE))

#define IS_OSPI_LATENCY_MODE(MODE)         (((MODE) == HAL_OSPI_VARIABLE_LATENCY) || \
                                            ((MODE) == HAL_OSPI_FIXED_LATENCY))

#define IS_OSPI_ADDRESS_SPACE(SPACE)       (((SPACE) == HAL_OSPI_MEMORY_ADDRESS_SPACE) || \
                                            ((SPACE) == HAL_OSPI_REGISTER_ADDRESS_SPACE))

#define IS_OSPI_MATCH_MODE(MODE)           (((MODE) == HAL_OSPI_MATCH_MODE_AND) || \
                                            ((MODE) == HAL_OSPI_MATCH_MODE_OR))

#define IS_OSPI_AUTOMATIC_STOP(MODE)       (((MODE) == HAL_OSPI_AUTOMATIC_STOP_ENABLE) || \
                                            ((MODE) == HAL_OSPI_AUTOMATIC_STOP_DISABLE))

#define IS_OSPI_INTERVAL(INTERVAL)         ((INTERVAL) <= 0xFFFFU)

#define IS_OSPI_STATUS_BYTES_SIZE(SIZE)    (((SIZE) >= 1U) && ((SIZE) <= 4U))

#define IS_OSPI_TIMEOUT_ACTIVATION(MODE)   (((MODE) == HAL_OSPI_TIMEOUT_COUNTER_DISABLE) || \
                                            ((MODE) == HAL_OSPI_TIMEOUT_COUNTER_ENABLE))

#define IS_OSPI_TIMEOUT_PERIOD(PERIOD)     ((PERIOD) <= 0xFFFFU)

#define IS_OSPI_CS_BOUNDARY(BOUNDARY)      ((BOUNDARY) <= 31U)

#define IS_OSPI_DLYBYP(MODE)               (((MODE) == HAL_OSPI_DELAY_BLOCK_USED) || \
                                            ((MODE) == HAL_OSPI_DELAY_BLOCK_BYPASSED))
#if   defined (OCTOSPI_DCR3_MAXTRAN)

#define IS_OSPI_MAXTRAN(NB_BYTES)          ((NB_BYTES) <= 255U)
#endif

#define IS_OSPIM_PORT(NUMBER)              (((NUMBER) >= 1U) && ((NUMBER) <= 2U))

#define IS_OSPIM_DQS_PORT(NUMBER)          ((NUMBER) <= 2U)

#define IS_OSPIM_IO_PORT(PORT)             (((PORT) == HAL_OSPIM_IOPORT_NONE)  || \
                                            ((PORT) == HAL_OSPIM_IOPORT_1_LOW)  || \
                                            ((PORT) == HAL_OSPIM_IOPORT_1_HIGH) || \
                                            ((PORT) == HAL_OSPIM_IOPORT_2_LOW)  || \
                                            ((PORT) == HAL_OSPIM_IOPORT_2_HIGH))

#if   defined (OCTOSPIM_CR_MUXEN)
#define IS_OSPIM_REQ2ACKTIME(TIME)          (((TIME) >= 1U) && ((TIME) <= 256U))
#endif                        
   
          
    

                                                                                

   
      
    

   
      
    

#endif                                      

#ifdef __cplusplus
}
#endif

#endif                           
