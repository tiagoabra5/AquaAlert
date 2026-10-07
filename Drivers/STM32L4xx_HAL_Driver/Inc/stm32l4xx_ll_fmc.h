/**
  ******************************************************************************
  * @file    stm32l4xx_ll_fmc.h
  * @author  MCD Application Team
  * @brief   Header file of FMC HAL module.
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

                                                                                
#ifndef STM32L4xx_LL_FMC_H
#define STM32L4xx_LL_FMC_H

#ifdef __cplusplus
extern "C" {
#endif

                                                                                
#include "stm32l4xx_hal_def.h"

                                    
      
    

                      
      
    

                                     
      
    
#if defined(FMC_BANK1)

#define IS_FMC_NORSRAM_BANK(__BANK__) (((__BANK__) == FMC_NORSRAM_BANK1) || \
                                       ((__BANK__) == FMC_NORSRAM_BANK2) || \
                                       ((__BANK__) == FMC_NORSRAM_BANK3) || \
                                       ((__BANK__) == FMC_NORSRAM_BANK4))
#define IS_FMC_MUX(__MUX__) (((__MUX__) == FMC_DATA_ADDRESS_MUX_DISABLE) || \
                             ((__MUX__) == FMC_DATA_ADDRESS_MUX_ENABLE))
#define IS_FMC_MEMORY(__MEMORY__) (((__MEMORY__) == FMC_MEMORY_TYPE_SRAM) || \
                                   ((__MEMORY__) == FMC_MEMORY_TYPE_PSRAM)|| \
                                   ((__MEMORY__) == FMC_MEMORY_TYPE_NOR))
#define IS_FMC_NORSRAM_MEMORY_WIDTH(__WIDTH__) (((__WIDTH__) == FMC_NORSRAM_MEM_BUS_WIDTH_8)  || \
                                                ((__WIDTH__) == FMC_NORSRAM_MEM_BUS_WIDTH_16) || \
                                                ((__WIDTH__) == FMC_NORSRAM_MEM_BUS_WIDTH_32))
#define IS_FMC_PAGESIZE(__SIZE__) (((__SIZE__) == FMC_PAGE_SIZE_NONE) || \
                                   ((__SIZE__) == FMC_PAGE_SIZE_128) || \
                                   ((__SIZE__) == FMC_PAGE_SIZE_256) || \
                                   ((__SIZE__) == FMC_PAGE_SIZE_512) || \
                                   ((__SIZE__) == FMC_PAGE_SIZE_1024))
#if defined(FMC_BCR1_WFDIS)
#define IS_FMC_WRITE_FIFO(__FIFO__) (((__FIFO__) == FMC_WRITE_FIFO_DISABLE) || \
                                     ((__FIFO__) == FMC_WRITE_FIFO_ENABLE))
#endif                     
#define IS_FMC_ACCESS_MODE(__MODE__) (((__MODE__) == FMC_ACCESS_MODE_A) || \
                                      ((__MODE__) == FMC_ACCESS_MODE_B) || \
                                      ((__MODE__) == FMC_ACCESS_MODE_C) || \
                                      ((__MODE__) == FMC_ACCESS_MODE_D))
#if defined(FMC_BCRx_NBLSET)
#define IS_FMC_NBL_SETUPTIME(__NBL__) (((__NBL__) == FMC_NBL_SETUPTIME_0) || \
                                       ((__NBL__) == FMC_NBL_SETUPTIME_1) || \
                                       ((__NBL__) == FMC_NBL_SETUPTIME_2) || \
                                       ((__NBL__) == FMC_NBL_SETUPTIME_3))
#endif                      
#define IS_FMC_BURSTMODE(__STATE__) (((__STATE__) == FMC_BURST_ACCESS_MODE_DISABLE) || \
                                     ((__STATE__) == FMC_BURST_ACCESS_MODE_ENABLE))
#define IS_FMC_WAIT_POLARITY(__POLARITY__) (((__POLARITY__) == FMC_WAIT_SIGNAL_POLARITY_LOW) || \
                                            ((__POLARITY__) == FMC_WAIT_SIGNAL_POLARITY_HIGH))
#define IS_FMC_WAIT_SIGNAL_ACTIVE(__ACTIVE__) (((__ACTIVE__) == FMC_WAIT_TIMING_BEFORE_WS) || \
                                               ((__ACTIVE__) == FMC_WAIT_TIMING_DURING_WS))
#define IS_FMC_WRITE_OPERATION(__OPERATION__) (((__OPERATION__) == FMC_WRITE_OPERATION_DISABLE) || \
                                               ((__OPERATION__) == FMC_WRITE_OPERATION_ENABLE))
#define IS_FMC_WAITE_SIGNAL(__SIGNAL__) (((__SIGNAL__) == FMC_WAIT_SIGNAL_DISABLE) || \
                                         ((__SIGNAL__) == FMC_WAIT_SIGNAL_ENABLE))
#define IS_FMC_EXTENDED_MODE(__MODE__) (((__MODE__) == FMC_EXTENDED_MODE_DISABLE) || \
                                        ((__MODE__) == FMC_EXTENDED_MODE_ENABLE))
#define IS_FMC_ASYNWAIT(__STATE__) (((__STATE__) == FMC_ASYNCHRONOUS_WAIT_DISABLE) || \
                                    ((__STATE__) == FMC_ASYNCHRONOUS_WAIT_ENABLE))
#define IS_FMC_DATA_LATENCY(__LATENCY__) (((__LATENCY__) > 1U) && ((__LATENCY__) <= 17U))
#define IS_FMC_WRITE_BURST(__BURST__) (((__BURST__) == FMC_WRITE_BURST_DISABLE) || \
                                       ((__BURST__) == FMC_WRITE_BURST_ENABLE))
#define IS_FMC_CONTINOUS_CLOCK(__CCLOCK__) (((__CCLOCK__) == FMC_CONTINUOUS_CLOCK_SYNC_ONLY) || \
                                            ((__CCLOCK__) == FMC_CONTINUOUS_CLOCK_SYNC_ASYNC))
#define IS_FMC_ADDRESS_SETUP_TIME(__TIME__) ((__TIME__) <= 15U)
#define IS_FMC_ADDRESS_HOLD_TIME(__TIME__) (((__TIME__) > 0U) && ((__TIME__) <= 15U))
#define IS_FMC_DATASETUP_TIME(__TIME__) (((__TIME__) > 0U) && ((__TIME__) <= 255U))
#define IS_FMC_DATAHOLD_DURATION(__DATAHOLD__) ((__DATAHOLD__) <= 3U)
#define IS_FMC_TURNAROUND_TIME(__TIME__) ((__TIME__) <= 15U)
#define IS_FMC_CLK_DIV(__DIV__) (((__DIV__) > 1U) && ((__DIV__) <= 16U))
#define IS_FMC_NORSRAM_DEVICE(__INSTANCE__) ((__INSTANCE__) == FMC_NORSRAM_DEVICE)
#define IS_FMC_NORSRAM_EXTENDED_DEVICE(__INSTANCE__) ((__INSTANCE__) == FMC_NORSRAM_EXTENDED_DEVICE)
#if defined(FMC_PCSCNTR_CSCOUNT)
#define IS_FMC_MAX_CHIP_SELECT_PULSE_TIME(__TIME__) (((__TIME__) >= 1U) && ((__TIME__) <= 65535U))
#endif                          

#endif                
#if  defined(FMC_BANK3)

#define IS_FMC_NAND_BANK(__BANK__) ((__BANK__) == FMC_NAND_BANK3)
#define IS_FMC_WAIT_FEATURE(__FEATURE__) (((__FEATURE__) == FMC_NAND_WAIT_FEATURE_DISABLE) || \
                                          ((__FEATURE__) == FMC_NAND_WAIT_FEATURE_ENABLE))
#define IS_FMC_NAND_MEMORY_WIDTH(__WIDTH__) (((__WIDTH__) == FMC_NAND_MEM_BUS_WIDTH_8) || \
                                             ((__WIDTH__) == FMC_NAND_MEM_BUS_WIDTH_16))
#define IS_FMC_ECC_STATE(__STATE__) (((__STATE__) == FMC_NAND_ECC_DISABLE) || \
                                     ((__STATE__) == FMC_NAND_ECC_ENABLE))

#define IS_FMC_ECCPAGE_SIZE(__SIZE__) (((__SIZE__) == FMC_NAND_ECC_PAGE_SIZE_256BYTE)  || \
                                       ((__SIZE__) == FMC_NAND_ECC_PAGE_SIZE_512BYTE)  || \
                                       ((__SIZE__) == FMC_NAND_ECC_PAGE_SIZE_1024BYTE) || \
                                       ((__SIZE__) == FMC_NAND_ECC_PAGE_SIZE_2048BYTE) || \
                                       ((__SIZE__) == FMC_NAND_ECC_PAGE_SIZE_4096BYTE) || \
                                       ((__SIZE__) == FMC_NAND_ECC_PAGE_SIZE_8192BYTE))
#define IS_FMC_TCLR_TIME(__TIME__) ((__TIME__) <= 255U)
#define IS_FMC_TAR_TIME(__TIME__) ((__TIME__) <= 255U)
#define IS_FMC_SETUP_TIME(__TIME__) ((__TIME__) <= 254U)
#define IS_FMC_WAIT_TIME(__TIME__) ((__TIME__) <= 254U)
#define IS_FMC_HOLD_TIME(__TIME__) ((__TIME__) <= 254U)
#define IS_FMC_HIZ_TIME(__TIME__) ((__TIME__) <= 254U)
#define IS_FMC_NAND_DEVICE(__INSTANCE__) ((__INSTANCE__) == FMC_NAND_DEVICE)

#endif                

   
      
    

                                                                                

                                                                  
      
    

#if defined(FMC_BANK1)
#define FMC_NORSRAM_TypeDef            FMC_Bank1_TypeDef
#define FMC_NORSRAM_EXTENDED_TypeDef   FMC_Bank1E_TypeDef
#endif                
#if defined(FMC_BANK3)
#define FMC_NAND_TypeDef               FMC_Bank3_TypeDef
#endif                

#if defined(FMC_BANK1)
#define FMC_NORSRAM_DEVICE             FMC_Bank1_R
#define FMC_NORSRAM_EXTENDED_DEVICE    FMC_Bank1E_R
#endif                
#if defined(FMC_BANK3)
#define FMC_NAND_DEVICE                FMC_Bank3_R
#endif                

#if defined(FMC_BANK1)
   
                                                          
    
typedef struct
{
  uint32_t NSBank;                                                                                  
                                                                                                                       

  uint32_t DataAddressMux;                                                                     
                                                                                 
                                                                                                                       

  uint32_t MemoryType;                                                                         
                                                                              
                                                                                                                       

  uint32_t MemoryDataWidth;                                                              
                                                                                                                       

  uint32_t BurstAccessMode;                                                                              
                                                                                               
                                                                                                                       

  uint32_t WaitSignalPolarity;                                                                             
                                                                             
                                                                                                                       

  uint32_t WaitSignalActive;                                                                            
                                                                                                         
                                                                                               
                                                                                                                       

  uint32_t WriteOperation;                                                                                  
                                                         
                                                                                                                       

  uint32_t WaitSignal;                                                                             
                                                                                                  
                                                                                                                       

  uint32_t ExtendedMode;                                                            
                                                                                                                       

  uint32_t AsynchronousWait;                                                                                
                                                                                          
                                                                                                                       

  uint32_t WriteBurst;                                                                      
                                                                                                                       

  uint32_t ContinuousClock;                                                                                       
                                                                                                           
                                                                                           
                                                                                                                       

  uint32_t WriteFifo;                                                                                       
                                                                                                           
                                                                                           
                                                                                                                       

  uint32_t PageSize;                                                         
                                                                                                                       

  uint32_t NBLSetupTime;                                                                       
                                                                                                                       
#if defined(FMC_PCSCNTR_CSCOUNT)

  FunctionalState MaxChipSelectPulse;                                                                             
                                                                       
                                                                                                                       

  uint32_t MaxChipSelectPulseTime;                                                                              
                                                                                                                
                                                                                         
                                                                                                                      
                                                                                                                       
#endif                          
} FMC_NORSRAM_InitTypeDef;

   
                                                              
    
typedef struct
{
  uint32_t AddressSetupTime;                                                                
                                                                                     
                                                                                                                   
                                                                                                                        

  uint32_t AddressHoldTime;                                                                 
                                                                                    
                                                                                                                   
                                                                                                                        

  uint32_t DataSetupTime;                                                                   
                                                                                  
                                                                                                                    
                                                                                                                       
                                                                                                                        

  uint32_t DataHoldTime;                                                                    
                                                                                 
                                                                                                                  
                                                                                                                        

  uint32_t BusTurnAroundDuration;                                                           
                                                                                 
                                                                                                                   
                                                                                                                        

  uint32_t CLKDivision;                                                                                            
                                                                                                                 
                                                            
                                                                                                                      
                                                                                                                        

  uint32_t DataLatency;                                                                         
                                                                                          
                                                                                                            
                                                                                     
                                                                                                          
                                                                                                            
                                                                                                                        

  uint32_t AccessMode;                                                               
                                                                                                                       
} FMC_NORSRAM_TimingTypeDef;
#endif                

#if defined(FMC_BANK3)
   
                                                       
    
typedef struct
{
  uint32_t NandBank;                                                                       
                                                                                                               

  uint32_t Waitfeature;                                                                                 
                                                                                                               

  uint32_t MemoryDataWidth;                                                        
                                                                                                               

  uint32_t EccComputation;                                                      
                                                                                                               

  uint32_t ECCPageSize;                                                            
                                                                                                               

  uint32_t TCLRSetupTime;                                                                 
                                                                         
                                                                                                                 

  uint32_t TARSetupTime;                                                                  
                                                                         
                                                                                                                 
} FMC_NAND_InitTypeDef;
#endif                

#if defined(FMC_BANK3)
   
                                                           
    
typedef struct
{
  uint32_t SetupTime;                                                                          
                                                                                               
                                                                                           
                                                                                
                                                                                                                 

  uint32_t WaitSetupTime;                                                                    
                                                                                    
                                                                                            
                                                                            
                                                                                                                 

  uint32_t HoldSetupTime;                                                                    
                                                                                                
                                                                                             
                                                                                               
                                                        
                                                                                                                 

  uint32_t HiZSetupTime;                                                                      
                                                                                             
                                                                                                     
                                                                                   
                                                                                                                 
} FMC_NAND_PCC_TimingTypeDef;
#endif                


   
      
    

                                                                                
                                                                          
      
    
#if defined(FMC_BANK1)

                                                                
      
    

                                                
      
    
#define FMC_NORSRAM_BANK1                       (0x00000000U)
#define FMC_NORSRAM_BANK2                       (0x00000002U)
#define FMC_NORSRAM_BANK3                       (0x00000004U)
#define FMC_NORSRAM_BANK4                       (0x00000006U)
   
      
    

                                                                                 
      
    
#define FMC_DATA_ADDRESS_MUX_DISABLE            (0x00000000U)
#define FMC_DATA_ADDRESS_MUX_ENABLE             (0x00000002U)
   
      
    

                                             
      
    
#define FMC_MEMORY_TYPE_SRAM                    (0x00000000U)
#define FMC_MEMORY_TYPE_PSRAM                   (0x00000004U)
#define FMC_MEMORY_TYPE_NOR                     (0x00000008U)
   
      
    

                                                           
      
    
#define FMC_NORSRAM_MEM_BUS_WIDTH_8             (0x00000000U)
#define FMC_NORSRAM_MEM_BUS_WIDTH_16            (0x00000010U)
#define FMC_NORSRAM_MEM_BUS_WIDTH_32            (0x00000020U)
   
      
    

                                                                
      
    
#define FMC_NORSRAM_FLASH_ACCESS_ENABLE         (0x00000040U)
#define FMC_NORSRAM_FLASH_ACCESS_DISABLE        (0x00000000U)
   
      
    

                                                         
      
    
#define FMC_BURST_ACCESS_MODE_DISABLE           (0x00000000U)
#define FMC_BURST_ACCESS_MODE_ENABLE            (0x00000100U)
   
      
    

                                                               
      
    
#define FMC_WAIT_SIGNAL_POLARITY_LOW            (0x00000000U)
#define FMC_WAIT_SIGNAL_POLARITY_HIGH           (0x00000200U)
   
      
    

                                             
      
    
#define FMC_WAIT_TIMING_BEFORE_WS               (0x00000000U)
#define FMC_WAIT_TIMING_DURING_WS               (0x00000800U)
   
      
    

                                                     
      
    
#define FMC_WRITE_OPERATION_DISABLE             (0x00000000U)
#define FMC_WRITE_OPERATION_ENABLE              (0x00001000U)
   
      
    

                                             
      
    
#define FMC_WAIT_SIGNAL_DISABLE                 (0x00000000U)
#define FMC_WAIT_SIGNAL_ENABLE                  (0x00002000U)
   
      
    

                                                 
      
    
#define FMC_EXTENDED_MODE_DISABLE               (0x00000000U)
#define FMC_EXTENDED_MODE_ENABLE                (0x00004000U)
   
      
    

                                                        
      
    
#define FMC_ASYNCHRONOUS_WAIT_DISABLE           (0x00000000U)
#define FMC_ASYNCHRONOUS_WAIT_ENABLE            (0x00008000U)
   
      
    

                                         
      
    
#define FMC_PAGE_SIZE_NONE                      (0x00000000U)
#define FMC_PAGE_SIZE_128                       FMC_BCRx_CPSIZE_0
#define FMC_PAGE_SIZE_256                       FMC_BCRx_CPSIZE_1
#define FMC_PAGE_SIZE_512                       (FMC_BCRx_CPSIZE_0\
                                                 | FMC_BCRx_CPSIZE_1)
#define FMC_PAGE_SIZE_1024                      FMC_BCRx_CPSIZE_2
   
      
    

                                             
      
    
#define FMC_WRITE_BURST_DISABLE                 (0x00000000U)
#define FMC_WRITE_BURST_ENABLE                  (0x00080000U)
   
      
    

                                                      
      
    
#define FMC_CONTINUOUS_CLOCK_SYNC_ONLY          (0x00000000U)
#define FMC_CONTINUOUS_CLOCK_SYNC_ASYNC         (0x00100000U)
   
      
    

#if defined(FMC_BCR1_WFDIS)
                                           
      
    
#define FMC_WRITE_FIFO_DISABLE                  FMC_BCR1_WFDIS
#define FMC_WRITE_FIFO_ENABLE                   (0x00000000U)
#endif                     
   
      
    

                                             
      
    
#define FMC_ACCESS_MODE_A                       (0x00000000U)
#define FMC_ACCESS_MODE_B                       (0x10000000U)
#define FMC_ACCESS_MODE_C                       (0x20000000U)
#define FMC_ACCESS_MODE_D                       (0x30000000U)
   
      
    

                                                    
      
    
#define FMC_NBL_SETUPTIME_0                     (0x00000000U)
#define FMC_NBL_SETUPTIME_1                     (0x00400000U)
#define FMC_NBL_SETUPTIME_2                     (0x00800000U)
#define FMC_NBL_SETUPTIME_3                     (0x00C00000U)
   
      
    

   
      
    
#endif                

#if defined(FMC_BANK3)

                                                        
      
    
                                         
      
    
#define FMC_NAND_BANK3                          (0x00000100U)
   
      
    

                                               
      
    
#define FMC_NAND_WAIT_FEATURE_DISABLE           (0x00000000U)
#define FMC_NAND_WAIT_FEATURE_ENABLE            (0x00000002U)
   
      
    

                                                     
      
    
#define FMC_PCR_MEMORY_TYPE_NAND                (0x00000008U)
   
      
    

                                                     
      
    
#define FMC_NAND_MEM_BUS_WIDTH_8                (0x00000000U)
#define FMC_NAND_MEM_BUS_WIDTH_16               (0x00000010U)
   
      
    

                             
      
    
#define FMC_NAND_ECC_DISABLE                    (0x00000000U)
#define FMC_NAND_ECC_ENABLE                     (0x00000040U)
   
      
    

                                                 
      
    
#define FMC_NAND_ECC_PAGE_SIZE_256BYTE          (0x00000000U)
#define FMC_NAND_ECC_PAGE_SIZE_512BYTE          (0x00020000U)
#define FMC_NAND_ECC_PAGE_SIZE_1024BYTE         (0x00040000U)
#define FMC_NAND_ECC_PAGE_SIZE_2048BYTE         (0x00060000U)
#define FMC_NAND_ECC_PAGE_SIZE_4096BYTE         (0x00080000U)
#define FMC_NAND_ECC_PAGE_SIZE_8192BYTE         (0x000A0000U)
   
      
    

   
      
    
#endif                


                                                                            
      
    
#if defined(FMC_BANK3)
#define FMC_IT_RISING_EDGE                      (0x00000008U)
#define FMC_IT_LEVEL                            (0x00000010U)
#define FMC_IT_FALLING_EDGE                     (0x00000020U)
#endif                
   
      
    

                                                                  
      
    
#if defined(FMC_BANK3)
#define FMC_FLAG_RISING_EDGE                    (0x00000001U)
#define FMC_FLAG_LEVEL                          (0x00000002U)
#define FMC_FLAG_FALLING_EDGE                   (0x00000004U)
#define FMC_FLAG_FEMPT                          (0x00000040U)
#endif                
   
      
    

   
      
    

   
      
    

                                                                                
                                                          
      
    
#if defined(FMC_BANK1)
                                                   
                                                                               
      
    

   
                                             
                                             
                                     
                
    
#define __FMC_NORSRAM_ENABLE(__INSTANCE__, __BANK__)  ((__INSTANCE__)->BTCR[(__BANK__)]\
                                                       |= FMC_BCRx_MBKEN)

   
                                              
                                             
                                     
                
    
#define __FMC_NORSRAM_DISABLE(__INSTANCE__, __BANK__) ((__INSTANCE__)->BTCR[(__BANK__)]\
                                                       &= ~FMC_BCRx_MBKEN)

   
      
    
#endif                

#if defined(FMC_BANK3)
                                                
                                                       
       
    

   
                                          
                                          
                
    
#define __FMC_NAND_ENABLE(__INSTANCE__)  ((__INSTANCE__)->PCR |= FMC_PCR_PBKEN)

   
                                           
                                          
                                      
                
    
#define __FMC_NAND_DISABLE(__INSTANCE__, __BANK__) CLEAR_BIT((__INSTANCE__)->PCR, FMC_PCR_PBKEN)

   
      
    
#endif                

#if defined(FMC_BANK3)
                                                      
                                           
      
    

   
                                             
                                           
                                            
                                                                          
                                                              
                                                  
                                                                
                
    
#define __FMC_NAND_ENABLE_IT(__INSTANCE__, __INTERRUPT__)  ((__INSTANCE__)->SR |= (__INTERRUPT__))

   
                                              
                                           
                                            
                                                                          
                                                              
                                                  
                                                                
                
    
#define __FMC_NAND_DISABLE_IT(__INSTANCE__, __INTERRUPT__)  ((__INSTANCE__)->SR &= ~(__INTERRUPT__))

   
                                               
                                          
                                      
                                      
                                                                          
                                                                     
                                                              
                                                                       
                                                    
                                             
    
#define __FMC_NAND_GET_FLAG(__INSTANCE__, __BANK__, __FLAG__)  (((__INSTANCE__)->SR &(__FLAG__)) == (__FLAG__))

   
                                                 
                                          
                                      
                                                                          
                                                                     
                                                              
                                                                       
                                                    
                
    
#define __FMC_NAND_CLEAR_FLAG(__INSTANCE__, __FLAG__)  ((__INSTANCE__)->SR &= ~(__FLAG__))

   
      
    
#endif                


   
      
    

   
      
    

                                                                                
                                                               
       
    
#if defined(FMC_BANK1)

                                      
       
    
                                                                                                         
       
    
HAL_StatusTypeDef  FMC_NORSRAM_Init(FMC_NORSRAM_TypeDef *Device,
                                    const FMC_NORSRAM_InitTypeDef *Init);
HAL_StatusTypeDef  FMC_NORSRAM_Timing_Init(FMC_NORSRAM_TypeDef *Device,
                                           const FMC_NORSRAM_TimingTypeDef *Timing, uint32_t Bank);
HAL_StatusTypeDef  FMC_NORSRAM_Extended_Timing_Init(FMC_NORSRAM_EXTENDED_TypeDef *Device,
                                                    const FMC_NORSRAM_TimingTypeDef *Timing, uint32_t Bank,
                                                    uint32_t ExtendedMode);
HAL_StatusTypeDef  FMC_NORSRAM_DeInit(FMC_NORSRAM_TypeDef *Device,
                                      FMC_NORSRAM_EXTENDED_TypeDef *ExDevice, uint32_t Bank);
   
      
    

                                                                                
       
    
HAL_StatusTypeDef  FMC_NORSRAM_WriteOperation_Enable(FMC_NORSRAM_TypeDef *Device, uint32_t Bank);
HAL_StatusTypeDef  FMC_NORSRAM_WriteOperation_Disable(FMC_NORSRAM_TypeDef *Device, uint32_t Bank);
   
      
    
   
      
    
#endif                
#if defined(FMC_BANK3)

                              
       
    
                                                                                                  
       
    
HAL_StatusTypeDef  FMC_NAND_Init(FMC_NAND_TypeDef *Device, const FMC_NAND_InitTypeDef *Init);
HAL_StatusTypeDef  FMC_NAND_CommonSpace_Timing_Init(FMC_NAND_TypeDef *Device,
                                                    const FMC_NAND_PCC_TimingTypeDef *Timing, uint32_t Bank);
HAL_StatusTypeDef  FMC_NAND_AttributeSpace_Timing_Init(FMC_NAND_TypeDef *Device,
                                                       const FMC_NAND_PCC_TimingTypeDef *Timing, uint32_t Bank);
HAL_StatusTypeDef  FMC_NAND_DeInit(FMC_NAND_TypeDef *Device, uint32_t Bank);
   
      
    

                                                                         
       
    
HAL_StatusTypeDef  FMC_NAND_ECC_Enable(FMC_NAND_TypeDef *Device, uint32_t Bank);
HAL_StatusTypeDef  FMC_NAND_ECC_Disable(FMC_NAND_TypeDef *Device, uint32_t Bank);
HAL_StatusTypeDef  FMC_NAND_GetECC(const FMC_NAND_TypeDef *Device, uint32_t *ECCval, uint32_t Bank,
                                   uint32_t Timeout);
   
      
    
   
      
    
#endif                

   
      
    

   
      
    

   
      
    

#ifdef __cplusplus
}
#endif

#endif                         
