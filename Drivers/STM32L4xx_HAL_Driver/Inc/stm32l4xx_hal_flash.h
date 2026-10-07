/**
  ******************************************************************************
  * @file    stm32l4xx_hal_flash.h
  * @author  MCD Application Team
  * @brief   Header file of FLASH HAL module.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2017 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file in
  * the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  ******************************************************************************
  */

                                                                                
#ifndef STM32L4xx_HAL_FLASH_H
#define STM32L4xx_HAL_FLASH_H

#ifdef __cplusplus
 extern "C" {
#endif

                                                                                
#include "stm32l4xx_hal_def.h"

                                    
      
    

                     
      
    

                                                                                
                                                       
      
    

   
                                            
    
typedef struct
{
  uint32_t TypeErase;                                 
                                                                                      
  uint32_t Banks;                                 
                                                                               
                                                                                    
  uint32_t Page;                                                                    
                                                                                                               
                                                            
  uint32_t NbPages;                                       
                                                                                                                                     
} FLASH_EraseInitTypeDef;

   
                                                           
    
typedef struct
{
  uint32_t OptionType;                                       
                                                                                                          
  uint32_t WRPArea;                                                                              
                                                                                       
                                                                                        
  uint32_t WRPStartOffset;                                                              
                                                                                                                  
                                                              
  uint32_t WRPEndOffset;                                                              
                                                                                                                                  
  uint32_t RDPLevel;                                                                      
                                                                                                 
  uint32_t USERType;                                                                            
                                                                                                 
  uint32_t USERConfig;                                                                   
                                                                                                    
                                                                                              
                                                                                             
                                                                                              
                                                                                    
                                                                                       
                                                                                          
                                                                                            
  uint32_t PCROPConfig;                                                                
                                                                                                                 
                                                              
  uint32_t PCROPStartAddr;                                                      
                                                                                            
                                                                                     
  uint32_t PCROPEndAddr;                                                      
                                                                                                             
} FLASH_OBProgramInitTypeDef;

   
                                                
    
typedef enum
{
  FLASH_PROC_NONE = 0,
  FLASH_PROC_PAGE_ERASE,
  FLASH_PROC_MASS_ERASE,
  FLASH_PROC_PROGRAM,
  FLASH_PROC_PROGRAM_LAST
} FLASH_ProcedureTypeDef;

   
                                            
    
typedef enum
{
  FLASH_CACHE_DISABLED = 0,
  FLASH_CACHE_ICACHE_ENABLED,
  FLASH_CACHE_DCACHE_ENABLED,
  FLASH_CACHE_ICACHE_DCACHE_ENABLED
} FLASH_CacheTypeDef;

   
                                             
    
typedef struct
{
  HAL_LockTypeDef             Lock;                                        
  __IO uint32_t               ErrorCode;                               
  __IO FLASH_ProcedureTypeDef ProcedureOnGoing;                                                                                     
  __IO uint32_t               Address;                                                                                     
  __IO uint32_t               Bank;                                                                                              
  __IO uint32_t               Page;                                                                                               
  __IO uint32_t               NbPagesToErase;                                                                              
  __IO FLASH_CacheTypeDef     CacheToReactivate;                                                                       
}FLASH_ProcessTypeDef;

   
      
    

                                                                                
                                                               
      
    

                                     
      
    
#define HAL_FLASH_ERROR_NONE      0x00000000U
#define HAL_FLASH_ERROR_OP        FLASH_FLAG_OPERR
#define HAL_FLASH_ERROR_PROG      FLASH_FLAG_PROGERR
#define HAL_FLASH_ERROR_WRP       FLASH_FLAG_WRPERR
#define HAL_FLASH_ERROR_PGA       FLASH_FLAG_PGAERR
#define HAL_FLASH_ERROR_SIZ       FLASH_FLAG_SIZERR
#define HAL_FLASH_ERROR_PGS       FLASH_FLAG_PGSERR
#define HAL_FLASH_ERROR_MIS       FLASH_FLAG_MISERR
#define HAL_FLASH_ERROR_FAST      FLASH_FLAG_FASTERR
#define HAL_FLASH_ERROR_RD        FLASH_FLAG_RDERR
#define HAL_FLASH_ERROR_OPTV      FLASH_FLAG_OPTVERR
#define HAL_FLASH_ERROR_ECCC      FLASH_FLAG_ECCC
#define HAL_FLASH_ERROR_ECCD      FLASH_FLAG_ECCD
#if defined (STM32L412xx) || defined (STM32L422xx) || defined (STM32L431xx) || defined (STM32L432xx) || defined (STM32L433xx) || defined (STM32L442xx) || \
    defined (STM32L443xx) || defined (STM32L451xx) || defined (STM32L452xx) || defined (STM32L462xx) || defined (STM32L496xx) || defined (STM32L4A6xx) || \
    defined (STM32L4P5xx) || defined (STM32L4Q5xx) || defined (STM32L4R5xx) || defined (STM32L4R7xx) || defined (STM32L4R9xx) || defined (STM32L4S5xx) || \
    defined (STM32L4S7xx) || defined (STM32L4S9xx)
#define HAL_FLASH_ERROR_PEMPTY    FLASH_FLAG_PEMPTY
#endif
   
      
    

                                               
      
    
#define FLASH_TYPEERASE_PAGES     ((uint32_t)0x00)                        
#define FLASH_TYPEERASE_MASSERASE ((uint32_t)0x01)                                   
   
      
    

                                     
      
    
#define FLASH_BANK_1              ((uint32_t)0x01)                                          
#if defined (STM32L471xx) || defined (STM32L475xx) || defined (STM32L476xx) || defined (STM32L485xx) || defined (STM32L486xx) || \
    defined (STM32L496xx) || defined (STM32L4A6xx) || defined (STM32L4P5xx) || defined (STM32L4Q5xx) || defined (STM32L4R5xx) || \
    defined (STM32L4R7xx) || defined (STM32L4R9xx) || defined (STM32L4S5xx) || defined (STM32L4S7xx) || defined (STM32L4S9xx)
#define FLASH_BANK_2              ((uint32_t)0x02)                                          
#define FLASH_BANK_BOTH           ((uint32_t)(FLASH_BANK_1 | FLASH_BANK_2))                         
#else
#define FLASH_BANK_BOTH           ((uint32_t)(FLASH_BANK_1))                                
#endif
   
      
    


                                                   
      
    
#define FLASH_TYPEPROGRAM_DOUBLEWORD    ((uint32_t)0x00)                                                              
#define FLASH_TYPEPROGRAM_FAST          ((uint32_t)0x01)                                                                        
                                                                                                                              
#define FLASH_TYPEPROGRAM_FAST_AND_LAST ((uint32_t)0x02)                                                                        
                                                                                                                               
   
      
    

                                                   
      
    
#define OPTIONBYTE_WRP            ((uint32_t)0x01)                                       
#define OPTIONBYTE_RDP            ((uint32_t)0x02)                                       
#define OPTIONBYTE_USER           ((uint32_t)0x04)                                        
#define OPTIONBYTE_PCROP          ((uint32_t)0x08)                                         
   
      
    

                                              
      
    
#define OB_WRPAREA_BANK1_AREAA    ((uint32_t)0x00)                             
#define OB_WRPAREA_BANK1_AREAB    ((uint32_t)0x01)                             
#if defined (STM32L471xx) || defined (STM32L475xx) || defined (STM32L476xx) || defined (STM32L485xx) || defined (STM32L486xx) || \
    defined (STM32L496xx) || defined (STM32L4A6xx) || defined (STM32L4P5xx) || defined (STM32L4Q5xx) || defined (STM32L4R5xx) || \
    defined (STM32L4R7xx) || defined (STM32L4R9xx) || defined (STM32L4S5xx) || defined (STM32L4S7xx) || defined (STM32L4S9xx)
#define OB_WRPAREA_BANK2_AREAA    ((uint32_t)0x02)                             
#define OB_WRPAREA_BANK2_AREAB    ((uint32_t)0x04)                             
#endif
   
      
    

                                                                         
      
    
#define OB_RDP_LEVEL_0            ((uint32_t)0xAA)
#define OB_RDP_LEVEL_1            ((uint32_t)0xBB)
#define OB_RDP_LEVEL_2            ((uint32_t)0xCC)                                                    
                                                                                                           
   
      
    

                                                             
      
    
#define OB_USER_BOR_LEV           ((uint32_t)0x0001)                                          
#define OB_USER_nRST_STOP         ((uint32_t)0x0002)                                                                      
#define OB_USER_nRST_STDBY        ((uint32_t)0x0004)                                                                         
#define OB_USER_IWDG_SW           ((uint32_t)0x0008)                                                         
#define OB_USER_IWDG_STOP         ((uint32_t)0x0010)                                                                           
#define OB_USER_IWDG_STDBY        ((uint32_t)0x0020)                                                                              
#define OB_USER_WWDG_SW           ((uint32_t)0x0040)                                                    
#if defined (STM32L471xx) || defined (STM32L475xx) || defined (STM32L476xx) || defined (STM32L485xx) || defined (STM32L486xx) || \
    defined (STM32L496xx) || defined (STM32L4A6xx) || defined (STM32L4P5xx) || defined (STM32L4Q5xx) || defined (STM32L4R5xx) || \
    defined (STM32L4R7xx) || defined (STM32L4R9xx) || defined (STM32L4S5xx) || defined (STM32L4S7xx) || defined (STM32L4S9xx)
#define OB_USER_BFB2              ((uint32_t)0x0080)                                         
#if defined (STM32L4R5xx) || defined (STM32L4R7xx) || defined (STM32L4R9xx) || defined (STM32L4S5xx) || defined (STM32L4S7xx) || defined (STM32L4S9xx)
#define OB_USER_DUALBANK          ((uint32_t)0x0100)                                                                         
#else
#define OB_USER_DUALBANK          ((uint32_t)0x0100)                                                                           
#endif
#endif
#define OB_USER_nBOOT1            ((uint32_t)0x0200)                                             
#define OB_USER_SRAM2_PE          ((uint32_t)0x0400)                                                    
#define OB_USER_SRAM2_RST         ((uint32_t)0x0800)                                                        
#define OB_USER_nRST_SHDW         ((uint32_t)0x1000)                                                                          
#if defined (STM32L412xx) || defined (STM32L422xx) || defined (STM32L431xx) || defined (STM32L432xx) || defined (STM32L433xx) || \
    defined (STM32L442xx) || defined (STM32L443xx) || defined (STM32L451xx) || defined (STM32L452xx) || defined (STM32L462xx) || \
    defined (STM32L496xx) || defined (STM32L4A6xx) || defined (STM32L4P5xx) || defined (STM32L4Q5xx) || defined (STM32L4R5xx) || \
    defined (STM32L4R7xx) || defined (STM32L4R9xx) || defined (STM32L4S5xx) || defined (STM32L4S7xx) || defined (STM32L4S9xx)
#define OB_USER_nSWBOOT0          ((uint32_t)0x2000)                                         
#define OB_USER_nBOOT0            ((uint32_t)0x4000)                                            
#endif
#if defined (STM32L4P5xx) || defined (STM32L4Q5xx) || defined (STM32L4R5xx) || defined (STM32L4R7xx) || defined (STM32L4R9xx) || defined (STM32L4S5xx) || defined (STM32L4S7xx) || defined (STM32L4S9xx)
#define OB_USER_DBANK             ((uint32_t)0x8000)                                                                                        
#endif
   
      
    

                                                                       
      
    
#define OB_BOR_LEVEL_0            ((uint32_t)FLASH_OPTR_BOR_LEV_0)                                                 
#define OB_BOR_LEVEL_1            ((uint32_t)FLASH_OPTR_BOR_LEV_1)                                                 
#define OB_BOR_LEVEL_2            ((uint32_t)FLASH_OPTR_BOR_LEV_2)                                                 
#define OB_BOR_LEVEL_3            ((uint32_t)FLASH_OPTR_BOR_LEV_3)                                                 
#define OB_BOR_LEVEL_4            ((uint32_t)FLASH_OPTR_BOR_LEV_4)                                                 
   
      
    

                                                                           
      
    
#define OB_STOP_RST               ((uint32_t)0x0000)                                                                      
#define OB_STOP_NORST             ((uint32_t)FLASH_OPTR_nRST_STOP)                                                           
   
      
    

                                                                                 
      
    
#define OB_STANDBY_RST            ((uint32_t)0x0000)                                                                         
#define OB_STANDBY_NORST          ((uint32_t)FLASH_OPTR_nRST_STDBY)                                                             
   
      
    

                                                                                   
      
    
#define OB_SHUTDOWN_RST           ((uint32_t)0x0000)                                                                          
#define OB_SHUTDOWN_NORST         ((uint32_t)FLASH_OPTR_nRST_SHDW)                                                               
   
      
    

                                                                     
      
    
#define OB_IWDG_HW                ((uint32_t)0x00000)                                                       
#define OB_IWDG_SW                ((uint32_t)FLASH_OPTR_IWDG_SW)                                            
   
      
    

                                                                               
      
    
#define OB_IWDG_STOP_FREEZE       ((uint32_t)0x00000)                                                                             
#define OB_IWDG_STOP_RUN          ((uint32_t)FLASH_OPTR_IWDG_STOP)                                                                 
   
      
    

                                                                                     
      
    
#define OB_IWDG_STDBY_FREEZE      ((uint32_t)0x00000)                                                                                
#define OB_IWDG_STDBY_RUN         ((uint32_t)FLASH_OPTR_IWDG_STDBY)                                                                   
   
      
    

                                                                     
      
    
#define OB_WWDG_HW                ((uint32_t)0x00000)                                                  
#define OB_WWDG_SW                ((uint32_t)FLASH_OPTR_WWDG_SW)                                       
   
      
    

#if defined (STM32L471xx) || defined (STM32L475xx) || defined (STM32L476xx) || defined (STM32L485xx) || defined (STM32L486xx) || \
    defined (STM32L496xx) || defined (STM32L4A6xx) || defined (STM32L4P5xx) || defined (STM32L4Q5xx) || defined (STM32L4R5xx) || \
    defined (STM32L4R7xx) || defined (STM32L4R9xx) || defined (STM32L4S5xx) || defined (STM32L4S7xx) || defined (STM32L4S9xx)
                                                                  
      
    
#define OB_BFB2_DISABLE           ((uint32_t)0x000000)                                               
#define OB_BFB2_ENABLE            ((uint32_t)FLASH_OPTR_BFB2)                                       
   
      
    
#if defined (STM32L4P5xx) || defined (STM32L4Q5xx) || defined (STM32L4R5xx) || defined (STM32L4R7xx) || defined (STM32L4R9xx) || defined (STM32L4S5xx) || defined (STM32L4S7xx) || defined (STM32L4S9xx)
                                                                           
      
    
#define OB_DUALBANK_SINGLE        ((uint32_t)0x000000)                                                      
#define OB_DUALBANK_DUAL          ((uint32_t)FLASH_OPTR_DB1M)                                             
   
      
    
#else
                                                                           
      
    
#define OB_DUALBANK_SINGLE        ((uint32_t)0x000000)                                                        
#define OB_DUALBANK_DUAL          ((uint32_t)FLASH_OPTR_DUALBANK)                                           
   
      
    
#endif
#endif

#if defined (STM32L4P5xx) || defined (STM32L4Q5xx) || defined (STM32L4R5xx) || defined (STM32L4R7xx) || defined (STM32L4R9xx) || defined (STM32L4S5xx) || defined (STM32L4S7xx) || defined (STM32L4S9xx)
                                                                    
      
    
#define OB_DBANK_128_BITS         ((uint32_t)0x000000)                                                       
#define OB_DBANK_64_BITS          ((uint32_t)FLASH_OPTR_DBANK)                                            
#endif
   
      
    
                                                                     
      
    
#define OB_BOOT1_SRAM             ((uint32_t)0x000000)                                                                              
#define OB_BOOT1_SYSTEM           ((uint32_t)FLASH_OPTR_nBOOT1)                                                                    
   
      
    

                                                                                    
      
    
#define OB_SRAM2_PARITY_ENABLE    ((uint32_t)0x0000000)                                                 
#define OB_SRAM2_PARITY_DISABLE   ((uint32_t)FLASH_OPTR_SRAM2_PE)                                        
   
      
    

                                                                                       
      
    
#define OB_SRAM2_RST_ERASE        ((uint32_t)0x0000000)                                                               
#define OB_SRAM2_RST_NOT_ERASE    ((uint32_t)FLASH_OPTR_SRAM2_RST)                                                           
   
      
    

#if defined (STM32L412xx) || defined (STM32L422xx) || defined (STM32L431xx) || defined (STM32L432xx) || defined (STM32L433xx) || \
    defined (STM32L442xx) || defined (STM32L443xx) || defined (STM32L451xx) || defined (STM32L452xx) || defined (STM32L462xx) || \
    defined (STM32L496xx) || defined (STM32L4A6xx) || defined (STM32L4P5xx) || defined (STM32L4Q5xx) || defined (STM32L4R5xx) || \
    defined (STM32L4R7xx) || defined (STM32L4R9xx) || defined (STM32L4S5xx) || defined (STM32L4S7xx) || defined (STM32L4S9xx)
                                                                           
      
    
#define OB_BOOT0_FROM_OB          ((uint32_t)0x0000000)                                                              
#define OB_BOOT0_FROM_PIN         ((uint32_t)FLASH_OPTR_nSWBOOT0)                                            
   
      
    

                                                                            
      
    
#define OB_BOOT0_RESET            ((uint32_t)0x0000000)                                  
#define OB_BOOT0_SET              ((uint32_t)FLASH_OPTR_nBOOT0)                          
   
      
    
#endif

                                                                           
      
    
#define OB_PCROP_RDP_NOT_ERASE    ((uint32_t)0x00000000)                                                               
                                                                                                                   
#define OB_PCROP_RDP_ERASE        ((uint32_t)FLASH_PCROP1ER_PCROP_RDP)                                                
                                                                                                                                  
   
      
    

                                         
      
    
#define FLASH_LATENCY_0           FLASH_ACR_LATENCY_0WS                                             
#define FLASH_LATENCY_1           FLASH_ACR_LATENCY_1WS                                            
#define FLASH_LATENCY_2           FLASH_ACR_LATENCY_2WS                                             
#define FLASH_LATENCY_3           FLASH_ACR_LATENCY_3WS                                               
#define FLASH_LATENCY_4           FLASH_ACR_LATENCY_4WS                                              
#if defined (STM32L4P5xx) || defined (STM32L4Q5xx) || defined (STM32L4R5xx) || defined (STM32L4R7xx) || defined (STM32L4R9xx) || defined (STM32L4S5xx) || defined (STM32L4S7xx) || defined (STM32L4S9xx)
#define FLASH_LATENCY_5           FLASH_ACR_LATENCY_5WS                                             
#define FLASH_LATENCY_6           FLASH_ACR_LATENCY_6WS                                            
#define FLASH_LATENCY_7           FLASH_ACR_LATENCY_7WS                                               
#define FLASH_LATENCY_8           FLASH_ACR_LATENCY_8WS                                               
#define FLASH_LATENCY_9           FLASH_ACR_LATENCY_9WS                                              
#define FLASH_LATENCY_10          FLASH_ACR_LATENCY_10WS                                           
#define FLASH_LATENCY_11          FLASH_ACR_LATENCY_11WS                                              
#define FLASH_LATENCY_12          FLASH_ACR_LATENCY_12WS                                               
#define FLASH_LATENCY_13          FLASH_ACR_LATENCY_13WS                                                 
#define FLASH_LATENCY_14          FLASH_ACR_LATENCY_14WS                                                 
#define FLASH_LATENCY_15          FLASH_ACR_LATENCY_15WS                                                
#endif
   
      
    

                                   
      
    
#define FLASH_KEY1                0x45670123U                                            
#define FLASH_KEY2                0xCDEF89ABU                                                               
                                                                                                                   

#define FLASH_PDKEY1              0x04152637U                                                       
#define FLASH_PDKEY2              0xFAFBFCFDU                                                                            
                                                                                                                    

#define FLASH_OPTKEY1             0x08192A3BU                                                        
#define FLASH_OPTKEY2             0x4C5D6E7FU                                                                              
                                                                                                               
   
      
    

                                                
      
    
#define FLASH_FLAG_EOP            FLASH_SR_EOP                                                            
#define FLASH_FLAG_OPERR          FLASH_SR_OPERR                                                         
#define FLASH_FLAG_PROGERR        FLASH_SR_PROGERR                                                         
#define FLASH_FLAG_WRPERR         FLASH_SR_WRPERR                                                               
#define FLASH_FLAG_PGAERR         FLASH_SR_PGAERR                                                                    
#define FLASH_FLAG_SIZERR         FLASH_SR_SIZERR                                                    
#define FLASH_FLAG_PGSERR         FLASH_SR_PGSERR                                                                   
#define FLASH_FLAG_MISERR         FLASH_SR_MISERR                                                                         
#define FLASH_FLAG_FASTERR        FLASH_SR_FASTERR                                                              
#define FLASH_FLAG_RDERR          FLASH_SR_RDERR                                                          
#define FLASH_FLAG_OPTVERR        FLASH_SR_OPTVERR                                                              
#define FLASH_FLAG_BSY            FLASH_SR_BSY                                                
#if defined (STM32L412xx) || defined (STM32L422xx) || defined (STM32L431xx) || defined (STM32L432xx) || defined (STM32L433xx) || defined (STM32L442xx) || \
    defined (STM32L443xx) || defined (STM32L451xx) || defined (STM32L452xx) || defined (STM32L462xx) || \
    defined (STM32L4P5xx) || defined (STM32L4Q5xx) || defined (STM32L4R5xx) || defined (STM32L4R7xx) || defined (STM32L4R9xx) || defined (STM32L4S5xx) || \
    defined (STM32L4S7xx) || defined (STM32L4S9xx)
#define FLASH_FLAG_PEMPTY         FLASH_SR_PEMPTY                                                 
#define FLASH_FLAG_SR_ERRORS      (FLASH_FLAG_OPERR   | FLASH_FLAG_PROGERR | FLASH_FLAG_WRPERR | \
                                   FLASH_FLAG_PGAERR  | FLASH_FLAG_SIZERR  | FLASH_FLAG_PGSERR | \
                                   FLASH_FLAG_MISERR  | FLASH_FLAG_FASTERR | FLASH_FLAG_RDERR  | \
                                   FLASH_FLAG_OPTVERR | FLASH_FLAG_PEMPTY)
#else
#define FLASH_FLAG_SR_ERRORS      (FLASH_FLAG_OPERR   | FLASH_FLAG_PROGERR | FLASH_FLAG_WRPERR | \
                                   FLASH_FLAG_PGAERR  | FLASH_FLAG_SIZERR  | FLASH_FLAG_PGSERR | \
                                   FLASH_FLAG_MISERR  | FLASH_FLAG_FASTERR | FLASH_FLAG_RDERR  | \
                                   FLASH_FLAG_OPTVERR)
#endif
#if defined (STM32L4P5xx) || defined (STM32L4Q5xx) || defined (STM32L4R5xx) || defined (STM32L4R7xx) || defined (STM32L4R9xx) || defined (STM32L4S5xx) || \
    defined (STM32L4S7xx) || defined (STM32L4S9xx)
#define FLASH_FLAG_ECCC           (FLASH_ECCR_ECCC | FLASH_ECCR_ECCC2)                             
#define FLASH_FLAG_ECCD           (FLASH_ECCR_ECCD | FLASH_ECCR_ECCD2)                            
#else
#define FLASH_FLAG_ECCC           FLASH_ECCR_ECCC                                                  
#define FLASH_FLAG_ECCD           FLASH_ECCR_ECCD                                                 
#endif
#define FLASH_FLAG_ECCR_ERRORS    (FLASH_FLAG_ECCD | FLASH_FLAG_ECCC)

#define FLASH_FLAG_ALL_ERRORS     (FLASH_FLAG_OPERR   | FLASH_FLAG_PROGERR | FLASH_FLAG_WRPERR | \
                                   FLASH_FLAG_PGAERR  | FLASH_FLAG_SIZERR  | FLASH_FLAG_PGSERR | \
                                   FLASH_FLAG_MISERR  | FLASH_FLAG_FASTERR | FLASH_FLAG_RDERR  | \
                                   FLASH_FLAG_OPTVERR | FLASH_FLAG_ECCR_ERRORS)
   
      
    

                                                                    
                                     
      
    
#define FLASH_IT_EOP              FLASH_CR_EOPIE                                                                      
#define FLASH_IT_OPERR            FLASH_CR_ERRIE                                                     
#define FLASH_IT_RDERR            FLASH_CR_RDERRIE                                                             
#define FLASH_IT_ECCC             (FLASH_ECCR_ECCIE >> 24)                                                    
   
      
    

                                                                                
                                                         
                                           
      
   

   
                                  
                                     
                                                               
                                                   
                                                  
                                                   
                                                     
                                                    
                
    
#define __HAL_FLASH_SET_LATENCY(__LATENCY__)    (MODIFY_REG(FLASH->ACR, FLASH_ACR_LATENCY, (__LATENCY__)))

   
                                  
                         
                                                               
                                                   
                                                  
                                                   
                                                     
                                                    
    
#define __HAL_FLASH_GET_LATENCY()               READ_BIT(FLASH->ACR, FLASH_ACR_LATENCY)

   
                                             
                
    
#define __HAL_FLASH_PREFETCH_BUFFER_ENABLE()    SET_BIT(FLASH->ACR, FLASH_ACR_PRFTEN)

   
                                              
                
    
#define __HAL_FLASH_PREFETCH_BUFFER_DISABLE()   CLEAR_BIT(FLASH->ACR, FLASH_ACR_PRFTEN)

   
                                               
                
    
#define __HAL_FLASH_INSTRUCTION_CACHE_ENABLE()  SET_BIT(FLASH->ACR, FLASH_ACR_ICEN)

   
                                                
                
    
#define __HAL_FLASH_INSTRUCTION_CACHE_DISABLE() CLEAR_BIT(FLASH->ACR, FLASH_ACR_ICEN)

   
                                        
                
    
#define __HAL_FLASH_DATA_CACHE_ENABLE()         SET_BIT(FLASH->ACR, FLASH_ACR_DCEN)

   
                                         
                
    
#define __HAL_FLASH_DATA_CACHE_DISABLE()        CLEAR_BIT(FLASH->ACR, FLASH_ACR_DCEN)

   
                                              
                                                                                   
                
    
#define __HAL_FLASH_INSTRUCTION_CACHE_RESET()   do { SET_BIT(FLASH->ACR, FLASH_ACR_ICRST);   \
                                                     CLEAR_BIT(FLASH->ACR, FLASH_ACR_ICRST); \
                                                   } while (0)

   
                                       
                                                                            
                
    
#define __HAL_FLASH_DATA_CACHE_RESET()          do { SET_BIT(FLASH->ACR, FLASH_ACR_DCRST);   \
                                                     CLEAR_BIT(FLASH->ACR, FLASH_ACR_DCRST); \
                                                   } while (0)

   
                                                                  
                                                                       
                                                                            
    
#define __HAL_FLASH_POWER_DOWN_ENABLE()         do { WRITE_REG(FLASH->PDKEYR, FLASH_PDKEY1); \
                                                     WRITE_REG(FLASH->PDKEYR, FLASH_PDKEY2); \
                                                     SET_BIT(FLASH->ACR, FLASH_ACR_RUN_PD);   \
                                                   } while (0)

   
                                                                   
                                                                       
                                                                            
    
#define __HAL_FLASH_POWER_DOWN_DISABLE()        do { WRITE_REG(FLASH->PDKEYR, FLASH_PDKEY1); \
                                                     WRITE_REG(FLASH->PDKEYR, FLASH_PDKEY2); \
                                                     CLEAR_BIT(FLASH->ACR, FLASH_ACR_RUN_PD); \
                                                   } while (0)

   
                                                                   
                
    
#define __HAL_FLASH_SLEEP_POWERDOWN_ENABLE()    SET_BIT(FLASH->ACR, FLASH_ACR_SLEEP_PD)

   
                                                                    
                
    
#define __HAL_FLASH_SLEEP_POWERDOWN_DISABLE()   CLEAR_BIT(FLASH->ACR, FLASH_ACR_SLEEP_PD)

   
      
    

                                                     
                                            
     
   

   
                                                 
                                         
                                                                          
                                                           
                                            
                                                       
                                                    
                
    
#define __HAL_FLASH_ENABLE_IT(__INTERRUPT__)    do { if(((__INTERRUPT__) & FLASH_IT_ECCC) != 0U) { SET_BIT(FLASH->ECCR, FLASH_ECCR_ECCIE); }\
                                                     if(((__INTERRUPT__) & (~FLASH_IT_ECCC)) != 0U) { SET_BIT(FLASH->CR, ((__INTERRUPT__) & (~FLASH_IT_ECCC))); }\
                                                   } while(0)

   
                                                  
                                         
                                                                          
                                                           
                                            
                                                       
                                                    
                
    
#define __HAL_FLASH_DISABLE_IT(__INTERRUPT__)   do { if(((__INTERRUPT__) & FLASH_IT_ECCC) != 0U) { CLEAR_BIT(FLASH->ECCR, FLASH_ECCR_ECCIE); }\
                                                     if(((__INTERRUPT__) & (~FLASH_IT_ECCC)) != 0U) { CLEAR_BIT(FLASH->CR, ((__INTERRUPT__) & (~FLASH_IT_ECCC))); }\
                                                   } while(0)

   
                                                                 
                                                       
                                                        
                                                        
                                                         
                                                             
                                                                 
                                                                      
                                                     
                                                                     
                                                                           
                                                                  
                                                           
                                                                 
                                                                          
                                                                                                                  
                                                                                 
                                                                     
                                                       
    
#define __HAL_FLASH_GET_FLAG(__FLAG__)          ((((__FLAG__) & FLASH_FLAG_ECCR_ERRORS) != 0U)     ? \
                                                 (READ_BIT(FLASH->ECCR, (__FLAG__)) != 0U) : \
                                                 (READ_BIT(FLASH->SR,   (__FLAG__)) != 0U))

   
                                            
                                                        
                                                                    
                                                        
                                                         
                                                             
                                                                 
                                                                      
                                                     
                                                                     
                                                                           
                                                                  
                                                           
                                                                 
                                                                                 
                                                                     
                                                          
                
    
#define __HAL_FLASH_CLEAR_FLAG(__FLAG__)        do { if(((__FLAG__) & FLASH_FLAG_ECCR_ERRORS) != 0U) { SET_BIT(FLASH->ECCR, ((__FLAG__) & FLASH_FLAG_ECCR_ERRORS)); }\
                                                     if(((__FLAG__) & ~(FLASH_FLAG_ECCR_ERRORS)) != 0U) { WRITE_REG(FLASH->SR, ((__FLAG__) & ~(FLASH_FLAG_ECCR_ERRORS))); }\
                                                   } while(0)
   
      
    

                                       
#include "stm32l4xx_hal_flash_ex.h"
#include "stm32l4xx_hal_flash_ramfunc.h"

                                                                                
                                        
      
    

                                                                                
                                               
      
    
HAL_StatusTypeDef  HAL_FLASH_Program(uint32_t TypeProgram, uint32_t Address, uint64_t Data);
HAL_StatusTypeDef  HAL_FLASH_Program_IT(uint32_t TypeProgram, uint32_t Address, uint64_t Data);
                              
void               HAL_FLASH_IRQHandler(void);
                                     
void               HAL_FLASH_EndOfOperationCallback(uint32_t ReturnValue);
void               HAL_FLASH_OperationErrorCallback(uint32_t ReturnValue);
   
      
    

                                                                                
                                               
      
    
HAL_StatusTypeDef  HAL_FLASH_Unlock(void);
HAL_StatusTypeDef  HAL_FLASH_Lock(void);
                          
HAL_StatusTypeDef  HAL_FLASH_OB_Unlock(void);
HAL_StatusTypeDef  HAL_FLASH_OB_Lock(void);
HAL_StatusTypeDef  HAL_FLASH_OB_Launch(void);
   
      
    

                                                                                
                                               
      
    
uint32_t HAL_FLASH_GetError(void);
   
      
    

   
      
    

                                                                                
                                                               
     
   
extern FLASH_ProcessTypeDef pFlash;
   
      
    

                                                                                
                                                               
     
   
HAL_StatusTypeDef FLASH_WaitForLastOperation(uint32_t Timeout);
   
      
    

                                                                               
                                                             
      
    
#if defined (STM32L471xx) || defined (STM32L475xx) || defined (STM32L476xx) || defined (STM32L485xx) || defined (STM32L486xx) || \
    defined (STM32L496xx) || defined (STM32L4A6xx) || defined (STM32L4P5xx) || defined (STM32L4Q5xx) || defined (STM32L4R5xx) || \
    defined (STM32L4R7xx) || defined (STM32L4R9xx) || defined (STM32L4S5xx) || defined (STM32L4S7xx) || defined (STM32L4S9xx)
#define FLASH_BANK_SIZE                    (FLASH_SIZE >> 1U)
#else
#define FLASH_BANK_SIZE                    (FLASH_SIZE)
#endif

#if defined (STM32L4P5xx) || defined (STM32L4Q5xx) || defined (STM32L4R5xx) || defined (STM32L4R7xx) || defined (STM32L4R9xx) || defined (STM32L4S5xx) || defined (STM32L4S7xx) || defined (STM32L4S9xx)
#define FLASH_PAGE_SIZE                    ((uint32_t)0x1000)
#define FLASH_PAGE_SIZE_128_BITS           ((uint32_t)0x2000)
#else
#define FLASH_PAGE_SIZE                    ((uint32_t)0x800)
#endif

#define FLASH_TIMEOUT_VALUE                ((uint32_t)50000)          
   
      
    

                                                                                
                                                       
      
   

#define IS_FLASH_TYPEERASE(VALUE)          (((VALUE) == FLASH_TYPEERASE_PAGES) || \
                                            ((VALUE) == FLASH_TYPEERASE_MASSERASE))

#if defined (STM32L471xx) || defined (STM32L475xx) || defined (STM32L476xx) || defined (STM32L485xx) || defined (STM32L486xx) || \
    defined (STM32L496xx) || defined (STM32L4A6xx) || defined (STM32L4P5xx) || defined (STM32L4Q5xx) || defined (STM32L4R5xx) || \
    defined (STM32L4R7xx) || defined (STM32L4R9xx) || defined (STM32L4S5xx) || defined (STM32L4S7xx) || defined (STM32L4S9xx)
#define IS_FLASH_BANK(BANK)                (((BANK) == FLASH_BANK_1)  || \
                                            ((BANK) == FLASH_BANK_2)  || \
                                            ((BANK) == FLASH_BANK_BOTH))

#define IS_FLASH_BANK_EXCLUSIVE(BANK)      (((BANK) == FLASH_BANK_1)  || \
                                            ((BANK) == FLASH_BANK_2))
#else
#define IS_FLASH_BANK(BANK)                ((BANK) == FLASH_BANK_1)

#define IS_FLASH_BANK_EXCLUSIVE(BANK)      ((BANK) == FLASH_BANK_1)
#endif

#define IS_FLASH_TYPEPROGRAM(VALUE)        (((VALUE) == FLASH_TYPEPROGRAM_DOUBLEWORD) || \
                                            ((VALUE) == FLASH_TYPEPROGRAM_FAST) || \
                                            ((VALUE) == FLASH_TYPEPROGRAM_FAST_AND_LAST))

#if defined (STM32L4R5xx) || defined (STM32L4R7xx) || defined (STM32L4R9xx) || defined (STM32L4S5xx) || defined (STM32L4S7xx) || defined (STM32L4S9xx)
#define IS_FLASH_MAIN_MEM_ADDRESS(ADDRESS) (((ADDRESS) >= (FLASH_BASE)) && ((ADDRESS) <= (FLASH_BASE+0x1FFFFFU)))
#else
#define IS_FLASH_MAIN_MEM_ADDRESS(ADDRESS) (((ADDRESS) >= (FLASH_BASE))         && ((((*((uint16_t *)FLASH_SIZE_DATA_REGISTER)) & (0x0FFFU)) == 0x400U) ? \
                                            ((ADDRESS) <= (FLASH_BASE+0xFFFFFU)) : ((((*((uint16_t *)FLASH_SIZE_DATA_REGISTER)) & (0x0FFFU)) == 0x200U) ? \
                                            ((ADDRESS) <= (FLASH_BASE+0x7FFFFU)) : ((((*((uint16_t *)FLASH_SIZE_DATA_REGISTER)) & (0x0FFFU)) == 0x100U) ? \
                                            ((ADDRESS) <= (FLASH_BASE+0x3FFFFU)) : ((((*((uint16_t *)FLASH_SIZE_DATA_REGISTER)) & (0x0FFFU)) == 0x80U) ? \
                                            ((ADDRESS) <= (FLASH_BASE+0x1FFFFU)) : ((ADDRESS) <= (FLASH_BASE+0xFFFFFU)))))))
#endif

#define IS_FLASH_OTP_ADDRESS(ADDRESS)      (((ADDRESS) >= 0x1FFF7000U) && ((ADDRESS) <= 0x1FFF73FFU))

#define IS_FLASH_PROGRAM_ADDRESS(ADDRESS)  ((IS_FLASH_MAIN_MEM_ADDRESS(ADDRESS)) || (IS_FLASH_OTP_ADDRESS(ADDRESS)))

#if defined (STM32L4R5xx) || defined (STM32L4R7xx) || defined (STM32L4R9xx) || defined (STM32L4S5xx) || defined (STM32L4S7xx) || defined (STM32L4S9xx)
#define IS_FLASH_PAGE(PAGE)                ((PAGE) < 256U)
#elif defined(STM32L471xx) || defined(STM32L475xx) || defined(STM32L476xx) || defined(STM32L485xx) || defined(STM32L486xx) || defined(STM32L496xx) || defined(STM32L4A6xx) || defined (STM32L4P5xx) || defined (STM32L4Q5xx)
#define IS_FLASH_PAGE(PAGE)                (((((*((uint16_t *)FLASH_SIZE_DATA_REGISTER)) & (0x0FFFU)) == 0x400U) ? ((PAGE) < 256U) : \
                                            ((((*((uint16_t *)FLASH_SIZE_DATA_REGISTER)) & (0x0FFFU)) == 0x200U) ? ((PAGE) < 128U) : \
                                            ((((*((uint16_t *)FLASH_SIZE_DATA_REGISTER)) & (0x0FFFU)) == 0x100U) ? ((PAGE) < 64U)  : \
                                            ((PAGE) < 256U)))))
#elif defined (STM32L451xx) || defined (STM32L452xx) || defined (STM32L462xx)
#define IS_FLASH_PAGE(PAGE)                (((((*((uint16_t *)FLASH_SIZE_DATA_REGISTER)) & (0x0FFFU)) == 0x200U) ? ((PAGE) < 256U) : \
                                            ((((*((uint16_t *)FLASH_SIZE_DATA_REGISTER)) & (0x0FFFU)) == 0x100U) ? ((PAGE) < 128U) : \
                                            ((PAGE) < 256U))))
#else
#define IS_FLASH_PAGE(PAGE)                (((((*((uint16_t *)FLASH_SIZE_DATA_REGISTER)) & (0x0FFFU)) == 0x100U) ? ((PAGE) < 128U) : \
                                            ((((*((uint16_t *)FLASH_SIZE_DATA_REGISTER)) & (0x0FFFU)) == 0x80U)  ? ((PAGE) < 64U)  : \
                                            ((PAGE) < 128U))))
#endif

#define IS_OPTIONBYTE(VALUE)               (((VALUE) <= (OPTIONBYTE_WRP | OPTIONBYTE_RDP | OPTIONBYTE_USER | OPTIONBYTE_PCROP)))

#if defined (STM32L471xx) || defined (STM32L475xx) || defined (STM32L476xx) || defined (STM32L485xx) || defined (STM32L486xx) || \
    defined (STM32L496xx) || defined (STM32L4A6xx) || defined (STM32L4P5xx) || defined (STM32L4Q5xx) || defined (STM32L4R5xx) || \
    defined (STM32L4R7xx) || defined (STM32L4R9xx) || defined (STM32L4S5xx) || defined (STM32L4S7xx) || defined (STM32L4S9xx)
#define IS_OB_WRPAREA(VALUE)               (((VALUE) == OB_WRPAREA_BANK1_AREAA) || ((VALUE) == OB_WRPAREA_BANK1_AREAB) || \
                                            ((VALUE) == OB_WRPAREA_BANK2_AREAA) || ((VALUE) == OB_WRPAREA_BANK2_AREAB))
#else
#define IS_OB_WRPAREA(VALUE)               (((VALUE) == OB_WRPAREA_BANK1_AREAA) || ((VALUE) == OB_WRPAREA_BANK1_AREAB))
#endif

#define IS_OB_RDP_LEVEL(LEVEL)             (((LEVEL) == OB_RDP_LEVEL_0) || \
                                                                         ((LEVEL) == OB_RDP_LEVEL_1))

#if defined (STM32L4P5xx) || defined (STM32L4Q5xx) || defined (STM32L4R5xx) || defined (STM32L4R7xx) || defined (STM32L4R9xx) || defined (STM32L4S5xx) || defined (STM32L4S7xx) || defined (STM32L4S9xx)
#define IS_OB_USER_TYPE(TYPE)              (((TYPE) <= (uint32_t)0xFFFFU) && ((TYPE) != 0U))
#elif defined(STM32L471xx) || defined(STM32L475xx) || defined(STM32L476xx) || defined(STM32L485xx) || defined(STM32L486xx)
#define IS_OB_USER_TYPE(TYPE)              (((TYPE) <= (uint32_t)0x1FFFU) && ((TYPE) != 0U))
#elif defined(STM32L496xx) || defined(STM32L4A6xx)
#define IS_OB_USER_TYPE(TYPE)              (((TYPE) <= (uint32_t)0x7FFFU) && ((TYPE) != 0U))
#else
#define IS_OB_USER_TYPE(TYPE)              (((TYPE) <= (uint32_t)0x7E7FU) && ((TYPE) != 0U) && (((TYPE)&0x0180U) == 0U))
#endif

#define IS_OB_USER_BOR_LEVEL(LEVEL)        (((LEVEL) == OB_BOR_LEVEL_0) || ((LEVEL) == OB_BOR_LEVEL_1) || \
                                            ((LEVEL) == OB_BOR_LEVEL_2) || ((LEVEL) == OB_BOR_LEVEL_3) || \
                                            ((LEVEL) == OB_BOR_LEVEL_4))

#define IS_OB_USER_STOP(VALUE)             (((VALUE) == OB_STOP_RST) || ((VALUE) == OB_STOP_NORST))

#define IS_OB_USER_STANDBY(VALUE)          (((VALUE) == OB_STANDBY_RST) || ((VALUE) == OB_STANDBY_NORST))

#define IS_OB_USER_SHUTDOWN(VALUE)         (((VALUE) == OB_SHUTDOWN_RST) || ((VALUE) == OB_SHUTDOWN_NORST))

#define IS_OB_USER_IWDG(VALUE)             (((VALUE) == OB_IWDG_HW) || ((VALUE) == OB_IWDG_SW))

#define IS_OB_USER_IWDG_STOP(VALUE)        (((VALUE) == OB_IWDG_STOP_FREEZE) || ((VALUE) == OB_IWDG_STOP_RUN))

#define IS_OB_USER_IWDG_STDBY(VALUE)       (((VALUE) == OB_IWDG_STDBY_FREEZE) || ((VALUE) == OB_IWDG_STDBY_RUN))

#define IS_OB_USER_WWDG(VALUE)             (((VALUE) == OB_WWDG_HW) || ((VALUE) == OB_WWDG_SW))

#if defined (STM32L471xx) || defined (STM32L475xx) || defined (STM32L476xx) || defined (STM32L485xx) || defined (STM32L486xx) || \
    defined (STM32L496xx) || defined (STM32L4A6xx) || defined (STM32L4P5xx) || defined (STM32L4Q5xx) || defined (STM32L4R5xx) || \
    defined (STM32L4R7xx) || defined (STM32L4R9xx) || defined (STM32L4S5xx) || defined (STM32L4S7xx) || defined (STM32L4S9xx)
#define IS_OB_USER_BFB2(VALUE)             (((VALUE) == OB_BFB2_DISABLE) || ((VALUE) == OB_BFB2_ENABLE))

#define IS_OB_USER_DUALBANK(VALUE)         (((VALUE) == OB_DUALBANK_SINGLE) || ((VALUE) == OB_DUALBANK_DUAL))
#endif

#if defined (STM32L4R5xx) || defined (STM32L4R7xx) || defined (STM32L4R9xx) || defined (STM32L4S5xx) || defined (STM32L4S7xx) || defined (STM32L4S9xx)
#define IS_OB_USER_DBANK(VALUE)            (((VALUE) == OB_DBANK_128_BITS) || ((VALUE) == OB_DBANK_64_BITS))
#endif

#define IS_OB_USER_BOOT1(VALUE)            (((VALUE) == OB_BOOT1_SRAM) || ((VALUE) == OB_BOOT1_SYSTEM))

#define IS_OB_USER_SRAM2_PARITY(VALUE)     (((VALUE) == OB_SRAM2_PARITY_ENABLE) || ((VALUE) == OB_SRAM2_PARITY_DISABLE))

#define IS_OB_USER_SRAM2_RST(VALUE)        (((VALUE) == OB_SRAM2_RST_ERASE) || ((VALUE) == OB_SRAM2_RST_NOT_ERASE))

#if defined (STM32L412xx) || defined (STM32L422xx) || defined (STM32L431xx) || defined (STM32L432xx) || defined (STM32L433xx) || \
    defined (STM32L442xx) || defined (STM32L443xx) || defined (STM32L451xx) || defined (STM32L452xx) || defined (STM32L462xx) || \
    defined (STM32L496xx) || defined (STM32L4A6xx) || defined (STM32L4P5xx) || defined (STM32L4Q5xx) || defined (STM32L4R5xx) || \
    defined (STM32L4R7xx) || defined (STM32L4R9xx) || defined (STM32L4S5xx) || defined (STM32L4S7xx) || defined (STM32L4S9xx)
#define IS_OB_USER_SWBOOT0(VALUE)          (((VALUE) == OB_BOOT0_FROM_OB) || ((VALUE) == OB_BOOT0_FROM_PIN))

#define IS_OB_USER_BOOT0(VALUE)            (((VALUE) == OB_BOOT0_RESET) || ((VALUE) == OB_BOOT0_SET))
#endif

#define IS_OB_PCROP_RDP(VALUE)             (((VALUE) == OB_PCROP_RDP_NOT_ERASE) || ((VALUE) == OB_PCROP_RDP_ERASE))

#if defined (STM32L4P5xx) || defined (STM32L4Q5xx) || defined (STM32L4R5xx) || defined (STM32L4R7xx) || defined (STM32L4R9xx) || defined (STM32L4S5xx) || defined (STM32L4S7xx) || defined (STM32L4S9xx)
#define IS_FLASH_LATENCY(LATENCY)          (((LATENCY) == FLASH_LATENCY_0) || ((LATENCY) == FLASH_LATENCY_1) || \
                                            ((LATENCY) == FLASH_LATENCY_2) || ((LATENCY) == FLASH_LATENCY_3) || \
                                            ((LATENCY) == FLASH_LATENCY_4) || ((LATENCY) == FLASH_LATENCY_5) || \
                                            ((LATENCY) == FLASH_LATENCY_6) || ((LATENCY) == FLASH_LATENCY_7) || \
                                            ((LATENCY) == FLASH_LATENCY_8) || ((LATENCY) == FLASH_LATENCY_9) || \
                                            ((LATENCY) == FLASH_LATENCY_10) || ((LATENCY) == FLASH_LATENCY_11) || \
                                            ((LATENCY) == FLASH_LATENCY_12) || ((LATENCY) == FLASH_LATENCY_13) || \
                                            ((LATENCY) == FLASH_LATENCY_14) || ((LATENCY) == FLASH_LATENCY_15))
#else
#define IS_FLASH_LATENCY(LATENCY)          (((LATENCY) == FLASH_LATENCY_0) || \
                                            ((LATENCY) == FLASH_LATENCY_1) || \
                                            ((LATENCY) == FLASH_LATENCY_2) || \
                                            ((LATENCY) == FLASH_LATENCY_3) || \
                                            ((LATENCY) == FLASH_LATENCY_4))
#endif
   
      
    

   
      
    

   
      
    

   
      
    

#ifdef __cplusplus
}
#endif

#endif                            
