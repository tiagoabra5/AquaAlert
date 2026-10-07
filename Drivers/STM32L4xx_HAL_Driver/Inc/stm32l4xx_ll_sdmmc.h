/**
  ******************************************************************************
  * @file    stm32l4xx_ll_sdmmc.h
  * @author  MCD Application Team
  * @brief   Header file of SDMMC HAL module.
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

                                                                                
#ifndef STM32L4xx_LL_SDMMC_H
#define STM32L4xx_LL_SDMMC_H

#ifdef __cplusplus
extern "C" {
#endif

#if defined(SDMMC1)

                                                                                
#include "stm32l4xx_hal_def.h"

                                
      
    

                        
      
    

                                                                                
                                                             
      
    

   
                                                    
    
typedef struct
{
  uint32_t ClockEdge;                                                                                 
                                                                                                                  

#if !defined(STM32L4P5xx) && !defined(STM32L4Q5xx) && !defined(STM32L4R5xx) && !defined(STM32L4R7xx) && !defined(STM32L4R9xx) && !defined(STM32L4S5xx) && !defined(STM32L4S7xx) && !defined(STM32L4S9xx)
  uint32_t ClockBypass;                                                                  
                                                          
                                                                                                                  
#endif                                                                                                                                   

  uint32_t ClockPowerSave;                                                              
                                                                    
                                                                                                                  

  uint32_t BusWide;                                                 
                                                                                                                  

  uint32_t HardwareFlowControl;                                                                                
                                                                                                                  

  uint32_t ClockDiv;                                                                        
                                                                                                               

#if defined(STM32L4P5xx) || defined(STM32L4Q5xx) || defined(STM32L4R5xx) || defined(STM32L4R7xx) || defined(STM32L4R9xx) || defined(STM32L4S5xx) || defined(STM32L4S7xx) || defined(STM32L4S9xx)
  uint32_t Transceiver;                                                                             
                                                                                                   
#endif                                                                                                                           
} SDMMC_InitTypeDef;


   
                                           
    
typedef struct
{
  uint32_t Argument;                                                                   
                                                                                         
                                                                                               
                                                                                                        

  uint32_t CmdIndex;                                                                               
                                                                                                        

  uint32_t Response;                                                   
                                                                                                            

  uint32_t WaitForInterrupt;                                                              
                                                         
                                                                                                            

  uint32_t CPSM;                                                                              
                                                            
                                                                                                            
} SDMMC_CmdInitTypeDef;


   
                                        
    
typedef struct
{
  uint32_t DataTimeOut;                                                                              

  uint32_t DataLength;                                                                               

  uint32_t DataBlockSize;                                                             
                                                                                                         

  uint32_t TransferDir;                                                                         
                                                        
                                                                                                         

  uint32_t TransferMode;                                                                        
                                                                                                         

  uint32_t DPSM;                                                                           
                                                            
                                                                                                         
} SDMMC_DataInitTypeDef;

   
      
    

                                                                                
                                                                     
      
    
#define SDMMC_ERROR_NONE                                0x00000000U                                                                         
#define SDMMC_ERROR_CMD_CRC_FAIL                        0x00000001U                                                                         
#define SDMMC_ERROR_DATA_CRC_FAIL                       0x00000002U                                                                         
#define SDMMC_ERROR_CMD_RSP_TIMEOUT                     0x00000004U                                                                         
#define SDMMC_ERROR_DATA_TIMEOUT                        0x00000008U                                                                         
#define SDMMC_ERROR_TX_UNDERRUN                         0x00000010U                                                                         
#define SDMMC_ERROR_RX_OVERRUN                          0x00000020U                                                                         
#define SDMMC_ERROR_ADDR_MISALIGNED                     0x00000040U                                                                         
#define SDMMC_ERROR_BLOCK_LEN_ERR                       0x00000080U                                                                    
                                                                                                                                            
#define SDMMC_ERROR_ERASE_SEQ_ERR                       0x00000100U                                                                         
#define SDMMC_ERROR_BAD_ERASE_PARAM                     0x00000200U                                                                         
#define SDMMC_ERROR_WRITE_PROT_VIOLATION                0x00000400U                                                                         
#define SDMMC_ERROR_LOCK_UNLOCK_FAILED                  0x00000800U                                                               
                                                                                                                                            
#define SDMMC_ERROR_COM_CRC_FAILED                      0x00001000U                                                                         
#define SDMMC_ERROR_ILLEGAL_CMD                         0x00002000U                                                                         
#define SDMMC_ERROR_CARD_ECC_FAILED                     0x00004000U                                                                         
#define SDMMC_ERROR_CC_ERR                              0x00008000U                                                                         
#define SDMMC_ERROR_GENERAL_UNKNOWN_ERR                 0x00010000U                                                                         
#define SDMMC_ERROR_STREAM_READ_UNDERRUN                0x00020000U                                                                         
#define SDMMC_ERROR_STREAM_WRITE_OVERRUN                0x00040000U                                                                         
#define SDMMC_ERROR_CID_CSD_OVERWRITE                   0x00080000U                                                                         
#define SDMMC_ERROR_WP_ERASE_SKIP                       0x00100000U                                                                         
#define SDMMC_ERROR_CARD_ECC_DISABLED                   0x00200000U                                                                         
#define SDMMC_ERROR_ERASE_RESET                         0x00400000U                                                                   
                                                                                                                                            
#define SDMMC_ERROR_AKE_SEQ_ERR                         0x00800000U                                                                         
#define SDMMC_ERROR_INVALID_VOLTRANGE                   0x01000000U                                                                         
#define SDMMC_ERROR_ADDR_OUT_OF_RANGE                   0x02000000U                                                                         
#define SDMMC_ERROR_REQUEST_NOT_APPLICABLE              0x04000000U                                                                         
#define SDMMC_ERROR_INVALID_PARAMETER                   0x08000000U                                                                         
#define SDMMC_ERROR_UNSUPPORTED_FEATURE                 0x10000000U                                                                         
#define SDMMC_ERROR_BUSY                                0x20000000U                                                                         
#define SDMMC_ERROR_DMA                                 0x40000000U                                                                         
#define SDMMC_ERROR_TIMEOUT                             0x80000000U                                                                         

   
                               
    
#define SDMMC_CMD_GO_IDLE_STATE                                 0U                                                                                                    
#define SDMMC_CMD_SEND_OP_COND                                  1U                                                                                                    
#define SDMMC_CMD_ALL_SEND_CID                                  2U                                                                                                    
#define SDMMC_CMD_SET_REL_ADDR                                  3U                                                                                                    
#define SDMMC_CMD_SET_DSR                                       4U                                                                                                    
#define SDMMC_CMD_SDMMC_SEN_OP_COND                             5U                                                                                             
                                                                                                                                                                      
#define SDMMC_CMD_HS_SWITCH                                     6U                                                                                                    
#define SDMMC_CMD_SEL_DESEL_CARD                                7U                                                                                                    
#define SDMMC_CMD_HS_SEND_EXT_CSD                               8U                                                                                                 
                                                                                                                                                                      
#define SDMMC_CMD_SEND_CSD                                      9U                                                                                                    
#define SDMMC_CMD_SEND_CID                                      10U                                                                                                   
#if defined(STM32L4P5xx) || defined(STM32L4Q5xx) || defined(STM32L4R5xx) || defined(STM32L4R7xx) || defined(STM32L4R9xx) || defined(STM32L4S5xx) || defined(STM32L4S7xx) || defined(STM32L4S9xx)
#define SDMMC_CMD_VOLTAGE_SWITCH                      ((uint8_t)11U)                                                                                                  
#else
#define SDMMC_CMD_READ_DAT_UNTIL_STOP                 ((uint8_t)11U)                                                                                                  
#endif                                                                                                                           
#define SDMMC_CMD_STOP_TRANSMISSION                             12U                                                                                                   
#define SDMMC_CMD_SEND_STATUS                                   13U                                                                                                   
#define SDMMC_CMD_HS_BUSTEST_READ                               14U                                                                                                   
#define SDMMC_CMD_GO_INACTIVE_STATE                             15U                                                                                                   
#define SDMMC_CMD_SET_BLOCKLEN                                  16U                                                                                  
                                                                                                                                                          
                                                                                                                                                                      
#define SDMMC_CMD_READ_SINGLE_BLOCK                             17U                                                                                           
                                                                                                                                                                      
#define SDMMC_CMD_READ_MULT_BLOCK                               18U                                                                                 
                                                                                                                                                                      
#define SDMMC_CMD_HS_BUSTEST_WRITE                              19U                                                                                                   
#define SDMMC_CMD_WRITE_DAT_UNTIL_STOP                          20U                                                                                                   
#define SDMMC_CMD_SET_BLOCK_COUNT                               23U                                                                                                   
#define SDMMC_CMD_WRITE_SINGLE_BLOCK                            24U                                                                                            
                                                                                                                                                                      
#define SDMMC_CMD_WRITE_MULT_BLOCK                              25U                                                                                                   
#define SDMMC_CMD_PROG_CID                                      26U                                                                                                   
#define SDMMC_CMD_PROG_CSD                                      27U                                                                                                   
#define SDMMC_CMD_SET_WRITE_PROT                                28U                                                                                                   
#define SDMMC_CMD_CLR_WRITE_PROT                                29U                                                                                                   
#define SDMMC_CMD_SEND_WRITE_PROT                               30U                                                                                                   
#define SDMMC_CMD_SD_ERASE_GRP_START                            32U                                                                                                   
#define SDMMC_CMD_SD_ERASE_GRP_END                              33U                                                                                                   
#define SDMMC_CMD_ERASE_GRP_START                               35U                                                                                         
                                                                                                                                                                      
#define SDMMC_CMD_ERASE_GRP_END                                 36U                                                                                      
                                                                                                                                                                      
#define SDMMC_CMD_ERASE                                         38U                                                                                                   
#define SDMMC_CMD_FAST_IO                                       39U                                                                                                   
#define SDMMC_CMD_GO_IRQ_STATE                                  40U                                                                                                   
#define SDMMC_CMD_LOCK_UNLOCK                                   42U                                                                                              
                                                                                                                                                                      
#define SDMMC_CMD_APP_CMD                                       55U                                                                                             
                                                                                                                                                                      
#define SDMMC_CMD_GEN_CMD                                       56U                                                                                             
                                                                                                                                                                      
#define SDMMC_CMD_NO_CMD                                        64U                                                                                                   

   
                                                            
                                                                      
    
#define SDMMC_CMD_APP_SD_SET_BUSWIDTH                           6U                                                                                              
                                                                                                                                                                      
#define SDMMC_CMD_SD_APP_STATUS                                 13U                                                                                                   
#define SDMMC_CMD_SD_APP_SEND_NUM_WRITE_BLOCKS                  22U                                                                                             
                                                                                                                                                                      
#define SDMMC_CMD_SD_APP_OP_COND                                41U                                                                                            
                                                                                                                                                                      
#define SDMMC_CMD_SD_APP_SET_CLR_CARD_DETECT                    42U                                                                                                   
#define SDMMC_CMD_SD_APP_SEND_SCR                               51U                                                                                                   
#define SDMMC_CMD_SDMMC_RW_DIRECT                               52U                                                                                                   
#define SDMMC_CMD_SDMMC_RW_EXTENDED                             53U                                                                                                   

   
                                                        
    
#define SDMMC_CMD_MMC_SLEEP_AWAKE                     ((uint8_t)5U)                                                                                                   

   
                                                                     
                                                                          
    
#define SDMMC_CMD_SD_APP_GET_MKB                                43U
#define SDMMC_CMD_SD_APP_GET_MID                                44U
#define SDMMC_CMD_SD_APP_SET_CER_RN1                            45U
#define SDMMC_CMD_SD_APP_GET_CER_RN2                            46U
#define SDMMC_CMD_SD_APP_SET_CER_RES2                           47U
#define SDMMC_CMD_SD_APP_GET_CER_RES1                           48U
#define SDMMC_CMD_SD_APP_SECURE_READ_MULTIPLE_BLOCK             18U
#define SDMMC_CMD_SD_APP_SECURE_WRITE_MULTIPLE_BLOCK            25U
#define SDMMC_CMD_SD_APP_SECURE_ERASE                           38U
#define SDMMC_CMD_SD_APP_CHANGE_SECURE_AREA                     49U
#define SDMMC_CMD_SD_APP_SECURE_WRITE_MKB                       48U

   
                                                          
    
#define SDMMC_OCR_ADDR_OUT_OF_RANGE                   0x80000000U
#define SDMMC_OCR_ADDR_MISALIGNED                     0x40000000U
#define SDMMC_OCR_BLOCK_LEN_ERR                       0x20000000U
#define SDMMC_OCR_ERASE_SEQ_ERR                       0x10000000U
#define SDMMC_OCR_BAD_ERASE_PARAM                     0x08000000U
#define SDMMC_OCR_WRITE_PROT_VIOLATION                0x04000000U
#define SDMMC_OCR_LOCK_UNLOCK_FAILED                  0x01000000U
#define SDMMC_OCR_COM_CRC_FAILED                      0x00800000U
#define SDMMC_OCR_ILLEGAL_CMD                         0x00400000U
#define SDMMC_OCR_CARD_ECC_FAILED                     0x00200000U
#define SDMMC_OCR_CC_ERROR                            0x00100000U
#define SDMMC_OCR_GENERAL_UNKNOWN_ERROR               0x00080000U
#define SDMMC_OCR_STREAM_READ_UNDERRUN                0x00040000U
#define SDMMC_OCR_STREAM_WRITE_OVERRUN                0x00020000U
#define SDMMC_OCR_CID_CSD_OVERWRITE                   0x00010000U
#define SDMMC_OCR_WP_ERASE_SKIP                       0x00008000U
#define SDMMC_OCR_CARD_ECC_DISABLED                   0x00004000U
#define SDMMC_OCR_ERASE_RESET                         0x00002000U
#define SDMMC_OCR_AKE_SEQ_ERROR                       0x00000008U
#define SDMMC_OCR_ERRORBITS                           0xFDFFE008U

   
                                 
    
#define SDMMC_R6_GENERAL_UNKNOWN_ERROR                0x00002000U
#define SDMMC_R6_ILLEGAL_CMD                          0x00004000U
#define SDMMC_R6_COM_CRC_FAILED                       0x00008000U

#define SDMMC_VOLTAGE_WINDOW_SD                       0x80100000U
#define SDMMC_HIGH_CAPACITY                           0x40000000U
#define SDMMC_STD_CAPACITY                            0x00000000U
#define SDMMC_CHECK_PATTERN                           0x000001AAU
#define SD_SWITCH_1_8V_CAPACITY                       0x01000000U
#if defined(STM32L4P5xx) || defined(STM32L4Q5xx) || defined(STM32L4R5xx) || defined(STM32L4R7xx) || defined(STM32L4R9xx) || defined(STM32L4S5xx) || defined(STM32L4S7xx) || defined(STM32L4S9xx)
#define SDMMC_DDR50_SWITCH_PATTERN         ((uint32_t)0x80FFFF04U)
#define SDMMC_SDR104_SWITCH_PATTERN        ((uint32_t)0x80FF1F03U)
#define SDMMC_SDR50_SWITCH_PATTERN         ((uint32_t)0x80FF1F02U)
#define SDMMC_SDR25_SWITCH_PATTERN         ((uint32_t)0x80FFFF01U)
#endif                                                                                                                           

#define SDMMC_MAX_VOLT_TRIAL                          0x0000FFFFU

#define SDMMC_MAX_TRIAL                               0x0000FFFFU

#define SDMMC_ALLZERO                                 0x00000000U

#define SDMMC_WIDE_BUS_SUPPORT                        0x00040000U
#define SDMMC_SINGLE_BUS_SUPPORT                      0x00010000U
#define SDMMC_CARD_LOCKED                             0x02000000U

#ifndef SDMMC_DATATIMEOUT                                
#define SDMMC_DATATIMEOUT                  ((uint32_t)0xFFFFFFFFU)
#endif                        

#ifndef SDMMC_SWDATATIMEOUT                                
#define SDMMC_SWDATATIMEOUT                SDMMC_DATATIMEOUT
#endif                          

#define SDMMC_0TO7BITS                                0x000000FFU
#define SDMMC_8TO15BITS                               0x0000FF00U
#define SDMMC_16TO23BITS                              0x00FF0000U
#define SDMMC_24TO31BITS                              0xFF000000U
#define SDMMC_MAX_DATA_LENGTH                         0x01FFFFFFU

#define SDMMC_HALFFIFO                                0x00000008U
#define SDMMC_HALFFIFOBYTES                           0x00000020U

   
                                   
    
#define SDMMC_CCCC_ERASE                       0x00000020U

#define SDMMC_CMDTIMEOUT                       5000U                                                
#define SDMMC_MAXERASETIMEOUT                  63000U                                               
#define SDMMC_STOPTRANSFERTIMEOUT              100000000U                                               

                                            
      
    
#define SDMMC_CLOCK_EDGE_RISING               0x00000000U
#define SDMMC_CLOCK_EDGE_FALLING              SDMMC_CLKCR_NEGEDGE

#define IS_SDMMC_CLOCK_EDGE(EDGE) (((EDGE) == SDMMC_CLOCK_EDGE_RISING) || \
                                   ((EDGE) == SDMMC_CLOCK_EDGE_FALLING))
   
      
    

#if !defined(STM32L4P5xx) && !defined(STM32L4Q5xx) && !defined(STM32L4R5xx) && !defined(STM32L4R7xx) && !defined(STM32L4R9xx) && !defined(STM32L4S5xx) && !defined(STM32L4S7xx) && !defined(STM32L4S9xx)
                                                
      
    
#define SDMMC_CLOCK_BYPASS_DISABLE             ((uint32_t)0x00000000U)
#define SDMMC_CLOCK_BYPASS_ENABLE              SDMMC_CLKCR_BYPASS

#define IS_SDMMC_CLOCK_BYPASS(BYPASS) (((BYPASS) == SDMMC_CLOCK_BYPASS_DISABLE) || \
                                       ((BYPASS) == SDMMC_CLOCK_BYPASS_ENABLE))
   
      
    
#endif                                                                                                                           
   
      
    

                                                          
      
    
#define SDMMC_CLOCK_POWER_SAVE_DISABLE         0x00000000U
#define SDMMC_CLOCK_POWER_SAVE_ENABLE          SDMMC_CLKCR_PWRSAV

#define IS_SDMMC_CLOCK_POWER_SAVE(SAVE) (((SAVE) == SDMMC_CLOCK_POWER_SAVE_DISABLE) || \
                                         ((SAVE) == SDMMC_CLOCK_POWER_SAVE_ENABLE))
   
      
    

                                         
      
    
#define SDMMC_BUS_WIDE_1B                      0x00000000U
#define SDMMC_BUS_WIDE_4B                      SDMMC_CLKCR_WIDBUS_0
#define SDMMC_BUS_WIDE_8B                      SDMMC_CLKCR_WIDBUS_1

#define IS_SDMMC_BUS_WIDE(WIDE) (((WIDE) == SDMMC_BUS_WIDE_1B) || \
                                 ((WIDE) == SDMMC_BUS_WIDE_4B) || \
                                 ((WIDE) == SDMMC_BUS_WIDE_8B))
   
      
    

#if defined(STM32L4P5xx) || defined(STM32L4Q5xx) || defined(STM32L4R5xx) || defined(STM32L4R7xx) || defined(STM32L4R9xx) || defined(STM32L4S5xx) || defined(STM32L4S7xx) || defined(STM32L4S9xx)
                                 
      
    
#define SDMMC_SPEED_MODE_AUTO                  ((uint32_t)0x00000000U)
#define SDMMC_SPEED_MODE_DEFAULT               ((uint32_t)0x00000001U)
#define SDMMC_SPEED_MODE_HIGH                  ((uint32_t)0x00000002U)
#define SDMMC_SPEED_MODE_ULTRA                 ((uint32_t)0x00000003U)
#define SDMMC_SPEED_MODE_DDR                   ((uint32_t)0x00000004U)

#define IS_SDMMC_SPEED_MODE(MODE) (((MODE) == SDMMC_SPEED_MODE_AUTO) || \
                                   ((MODE) == SDMMC_SPEED_MODE_DEFAULT) || \
                                   ((MODE) == SDMMC_SPEED_MODE_HIGH) || \
                                   ((MODE) == SDMMC_SPEED_MODE_ULTRA) || \
                                   ((MODE) == SDMMC_SPEED_MODE_DDR))

   
      
    
#endif                                                                                                                           

                                                                  
      
    
#define SDMMC_HARDWARE_FLOW_CONTROL_DISABLE    0x00000000U
#define SDMMC_HARDWARE_FLOW_CONTROL_ENABLE     SDMMC_CLKCR_HWFC_EN

#define IS_SDMMC_HARDWARE_FLOW_CONTROL(CONTROL) (((CONTROL) == SDMMC_HARDWARE_FLOW_CONTROL_DISABLE) || \
                                                 ((CONTROL) == SDMMC_HARDWARE_FLOW_CONTROL_ENABLE))
   
      
    

                                                    
      
    
#if defined(STM32L4P5xx) || defined(STM32L4Q5xx) || defined(STM32L4R5xx) || defined(STM32L4R7xx) || defined(STM32L4R9xx) || defined(STM32L4S5xx) || defined(STM32L4S7xx) || defined(STM32L4S9xx)
                                                  
#define IS_SDMMC_CLKDIV(DIV)   ((DIV) < 0x400U)
#else
#define IS_SDMMC_CLKDIV(DIV)   ((DIV) <= 0xFFU)
#endif                                                                                                                           
   
      
    

#if defined(STM32L4P5xx) || defined(STM32L4Q5xx) || defined(STM32L4R5xx) || defined(STM32L4R7xx) || defined(STM32L4R9xx) || defined(STM32L4S5xx) || defined(STM32L4S7xx) || defined(STM32L4S9xx)
                                              
      
    
#define SDMMC_TRANSCEIVER_DISABLE    ((uint32_t)0x00000000U)
#define SDMMC_TRANSCEIVER_ENABLE     ((uint32_t)0x00000001U)

#define IS_SDMMC_TRANSCEIVER(MODE) (((MODE) == SDMMC_TRANSCEIVER_DISABLE) || \
                                    ((MODE) == SDMMC_TRANSCEIVER_ENABLE))
   
      
    
#endif                                                                                                                           

                                                  
      
    
#define IS_SDMMC_CMD_INDEX(INDEX)            ((INDEX) < 0x40U)
   
      
    

                                                  
      
    
#define SDMMC_RESPONSE_NO                    0x00000000U
#define SDMMC_RESPONSE_SHORT                 SDMMC_CMD_WAITRESP_0
#define SDMMC_RESPONSE_LONG                  SDMMC_CMD_WAITRESP

#define IS_SDMMC_RESPONSE(RESPONSE) (((RESPONSE) == SDMMC_RESPONSE_NO)    || \
                                     ((RESPONSE) == SDMMC_RESPONSE_SHORT) || \
                                     ((RESPONSE) == SDMMC_RESPONSE_LONG))
   
      
    

                                                          
      
    
#define SDMMC_WAIT_NO                        0x00000000U
#define SDMMC_WAIT_IT                        SDMMC_CMD_WAITINT
#define SDMMC_WAIT_PEND                      SDMMC_CMD_WAITPEND

#define IS_SDMMC_WAIT(WAIT) (((WAIT) == SDMMC_WAIT_NO) || \
                             ((WAIT) == SDMMC_WAIT_IT) || \
                             ((WAIT) == SDMMC_WAIT_PEND))
   
      
    

                                            
      
    
#define SDMMC_CPSM_DISABLE                   0x00000000U
#define SDMMC_CPSM_ENABLE                    SDMMC_CMD_CPSMEN

#define IS_SDMMC_CPSM(CPSM) (((CPSM) == SDMMC_CPSM_DISABLE) || \
                             ((CPSM) == SDMMC_CPSM_ENABLE))
   
      
    

                                                           
      
    
#define SDMMC_RESP1                          0x00000000U
#define SDMMC_RESP2                          0x00000004U
#define SDMMC_RESP3                          0x00000008U
#define SDMMC_RESP4                          0x0000000CU

#define IS_SDMMC_RESP(RESP) (((RESP) == SDMMC_RESP1) || \
                             ((RESP) == SDMMC_RESP2) || \
                             ((RESP) == SDMMC_RESP3) || \
                             ((RESP) == SDMMC_RESP4))
   
      
    

#if defined(STM32L4P5xx) || defined(STM32L4Q5xx) || defined(STM32L4R5xx) || defined(STM32L4R7xx) || defined(STM32L4R9xx) || defined(STM32L4S5xx) || defined(STM32L4S7xx) || defined(STM32L4S9xx)
                                                              
      
    
#define SDMMC_DISABLE_IDMA              ((uint32_t)0x00000000)
#define SDMMC_ENABLE_IDMA_SINGLE_BUFF   (SDMMC_IDMA_IDMAEN)
#define SDMMC_ENABLE_IDMA_DOUBLE_BUFF0  (SDMMC_IDMA_IDMAEN | SDMMC_IDMA_IDMABMODE)
#define SDMMC_ENABLE_IDMA_DOUBLE_BUFF1  (SDMMC_IDMA_IDMAEN | SDMMC_IDMA_IDMABMODE | SDMMC_IDMA_IDMABACT)

   
      
    
#endif                                                                                                                           

                                              
      
    
#define IS_SDMMC_DATA_LENGTH(LENGTH) ((LENGTH) <= 0x01FFFFFFU)
   
      
    

                                                       
      
    
#define SDMMC_DATABLOCK_SIZE_1B               0x00000000U
#define SDMMC_DATABLOCK_SIZE_2B               SDMMC_DCTRL_DBLOCKSIZE_0
#define SDMMC_DATABLOCK_SIZE_4B               SDMMC_DCTRL_DBLOCKSIZE_1
#define SDMMC_DATABLOCK_SIZE_8B               (SDMMC_DCTRL_DBLOCKSIZE_0|SDMMC_DCTRL_DBLOCKSIZE_1)
#define SDMMC_DATABLOCK_SIZE_16B              SDMMC_DCTRL_DBLOCKSIZE_2
#define SDMMC_DATABLOCK_SIZE_32B              (SDMMC_DCTRL_DBLOCKSIZE_0|SDMMC_DCTRL_DBLOCKSIZE_2)
#define SDMMC_DATABLOCK_SIZE_64B              (SDMMC_DCTRL_DBLOCKSIZE_1|SDMMC_DCTRL_DBLOCKSIZE_2)
#define SDMMC_DATABLOCK_SIZE_128B             (SDMMC_DCTRL_DBLOCKSIZE_0|\
                                               SDMMC_DCTRL_DBLOCKSIZE_1|SDMMC_DCTRL_DBLOCKSIZE_2)
#define SDMMC_DATABLOCK_SIZE_256B             SDMMC_DCTRL_DBLOCKSIZE_3
#define SDMMC_DATABLOCK_SIZE_512B             (SDMMC_DCTRL_DBLOCKSIZE_0|SDMMC_DCTRL_DBLOCKSIZE_3)
#define SDMMC_DATABLOCK_SIZE_1024B            (SDMMC_DCTRL_DBLOCKSIZE_1|SDMMC_DCTRL_DBLOCKSIZE_3)
#define SDMMC_DATABLOCK_SIZE_2048B            (SDMMC_DCTRL_DBLOCKSIZE_0|\
                                               SDMMC_DCTRL_DBLOCKSIZE_1|SDMMC_DCTRL_DBLOCKSIZE_3)
#define SDMMC_DATABLOCK_SIZE_4096B            (SDMMC_DCTRL_DBLOCKSIZE_2|SDMMC_DCTRL_DBLOCKSIZE_3)
#define SDMMC_DATABLOCK_SIZE_8192B            (SDMMC_DCTRL_DBLOCKSIZE_0|\
                                               SDMMC_DCTRL_DBLOCKSIZE_2|SDMMC_DCTRL_DBLOCKSIZE_3)
#define SDMMC_DATABLOCK_SIZE_16384B           (SDMMC_DCTRL_DBLOCKSIZE_1|\
                                               SDMMC_DCTRL_DBLOCKSIZE_2|SDMMC_DCTRL_DBLOCKSIZE_3)

#define IS_SDMMC_BLOCK_SIZE(SIZE) (((SIZE) == SDMMC_DATABLOCK_SIZE_1B)    || \
                                   ((SIZE) == SDMMC_DATABLOCK_SIZE_2B)    || \
                                   ((SIZE) == SDMMC_DATABLOCK_SIZE_4B)    || \
                                   ((SIZE) == SDMMC_DATABLOCK_SIZE_8B)    || \
                                   ((SIZE) == SDMMC_DATABLOCK_SIZE_16B)   || \
                                   ((SIZE) == SDMMC_DATABLOCK_SIZE_32B)   || \
                                   ((SIZE) == SDMMC_DATABLOCK_SIZE_64B)   || \
                                   ((SIZE) == SDMMC_DATABLOCK_SIZE_128B)  || \
                                   ((SIZE) == SDMMC_DATABLOCK_SIZE_256B)  || \
                                   ((SIZE) == SDMMC_DATABLOCK_SIZE_512B)  || \
                                   ((SIZE) == SDMMC_DATABLOCK_SIZE_1024B) || \
                                   ((SIZE) == SDMMC_DATABLOCK_SIZE_2048B) || \
                                   ((SIZE) == SDMMC_DATABLOCK_SIZE_4096B) || \
                                   ((SIZE) == SDMMC_DATABLOCK_SIZE_8192B) || \
                                   ((SIZE) == SDMMC_DATABLOCK_SIZE_16384B))
   
      
    

                                                            
      
    
#define SDMMC_TRANSFER_DIR_TO_CARD            0x00000000U
#define SDMMC_TRANSFER_DIR_TO_SDMMC    SDMMC_DCTRL_DTDIR

#define IS_SDMMC_TRANSFER_DIR(DIR) (((DIR) == SDMMC_TRANSFER_DIR_TO_CARD) || \
                                    ((DIR) == SDMMC_TRANSFER_DIR_TO_SDMMC))
   
      
    

                                                  
      
    
#define SDMMC_TRANSFER_MODE_BLOCK             0x00000000U
#if defined(STM32L4P5xx) || defined(STM32L4Q5xx) || defined(STM32L4R5xx) || defined(STM32L4R7xx) || defined(STM32L4R9xx) || defined(STM32L4S5xx) || defined(STM32L4S7xx) || defined(STM32L4S9xx)
#define SDMMC_TRANSFER_MODE_STREAM            SDMMC_DCTRL_DTMODE_1
#else
#define SDMMC_TRANSFER_MODE_STREAM            SDMMC_DCTRL_DTMODE
#endif                                                                                                                           

#define IS_SDMMC_TRANSFER_MODE(MODE) (((MODE) == SDMMC_TRANSFER_MODE_BLOCK) || \
                                      ((MODE) == SDMMC_TRANSFER_MODE_STREAM))
   
      
    

                                            
      
    
#define SDMMC_DPSM_DISABLE                    0x00000000U
#define SDMMC_DPSM_ENABLE                     SDMMC_DCTRL_DTEN

#define IS_SDMMC_DPSM(DPSM) (((DPSM) == SDMMC_DPSM_DISABLE) ||\
                             ((DPSM) == SDMMC_DPSM_ENABLE))
   
      
    

                                                    
      
    
#define SDMMC_READ_WAIT_MODE_DATA2                0x00000000U
#define SDMMC_READ_WAIT_MODE_CLK                  (SDMMC_DCTRL_RWMOD)

#define IS_SDMMC_READWAIT_MODE(MODE) (((MODE) == SDMMC_READ_WAIT_MODE_CLK) || \
                                      ((MODE) == SDMMC_READ_WAIT_MODE_DATA2))
   
      
    

                                                          
      
    
#define SDMMC_IT_CCRCFAIL                    SDMMC_MASK_CCRCFAILIE
#define SDMMC_IT_DCRCFAIL                    SDMMC_MASK_DCRCFAILIE
#define SDMMC_IT_CTIMEOUT                    SDMMC_MASK_CTIMEOUTIE
#define SDMMC_IT_DTIMEOUT                    SDMMC_MASK_DTIMEOUTIE
#define SDMMC_IT_TXUNDERR                    SDMMC_MASK_TXUNDERRIE
#define SDMMC_IT_RXOVERR                     SDMMC_MASK_RXOVERRIE
#define SDMMC_IT_CMDREND                     SDMMC_MASK_CMDRENDIE
#define SDMMC_IT_CMDSENT                     SDMMC_MASK_CMDSENTIE
#define SDMMC_IT_DATAEND                     SDMMC_MASK_DATAENDIE
#if defined(STM32L4P5xx) || defined(STM32L4Q5xx) || defined(STM32L4R5xx) || defined(STM32L4R7xx) || defined(STM32L4R9xx) || defined(STM32L4S5xx) || defined(STM32L4S7xx) || defined(STM32L4S9xx)
#define SDMMC_IT_DHOLD                     SDMMC_MASK_DHOLDIE
#endif                                                                                                                           
#define SDMMC_IT_DBCKEND                     SDMMC_MASK_DBCKENDIE
#if !defined(STM32L4P5xx) && !defined(STM32L4Q5xx) && !defined(STM32L4R5xx) && !defined(STM32L4R7xx) && !defined(STM32L4R9xx) && !defined(STM32L4S5xx) && !defined(STM32L4S7xx) && !defined(STM32L4S9xx)
#define SDMMC_IT_CMDACT                    SDMMC_MASK_CMDACTIE
#define SDMMC_IT_TXACT                     SDMMC_MASK_TXACTIE
#define SDMMC_IT_RXACT                     SDMMC_MASK_RXACTIE
#else
#define SDMMC_IT_DABORT                    SDMMC_MASK_DABORTIE
#endif
#define SDMMC_IT_TXFIFOHE                    SDMMC_MASK_TXFIFOHEIE
#define SDMMC_IT_RXFIFOHF                    SDMMC_MASK_RXFIFOHFIE
#if !defined(STM32L4P5xx) && !defined(STM32L4Q5xx) && !defined(STM32L4R5xx) && !defined(STM32L4R7xx) && !defined(STM32L4R9xx) && !defined(STM32L4S5xx) && !defined(STM32L4S7xx) && !defined(STM32L4S9xx)
#define SDMMC_IT_TXFIFOF                   SDMMC_MASK_TXFIFOFIE
#endif
#define SDMMC_IT_RXFIFOF                     SDMMC_MASK_RXFIFOFIE
#define SDMMC_IT_TXFIFOE                     SDMMC_MASK_TXFIFOEIE
#if defined(STM32L4P5xx) || defined(STM32L4Q5xx) || defined(STM32L4R5xx) || defined(STM32L4R7xx) || defined(STM32L4R9xx) || defined(STM32L4S5xx) || defined(STM32L4S7xx) || defined(STM32L4S9xx)
#define SDMMC_IT_BUSYD0END                 SDMMC_MASK_BUSYD0ENDIE
#else
#define SDMMC_IT_RXFIFOE                     SDMMC_MASK_RXFIFOEIE
#define SDMMC_IT_TXDAVL                      SDMMC_MASK_TXDAVLIE
#define SDMMC_IT_RXDAVL                      SDMMC_MASK_RXDAVLIE
#endif                                                                                                                           
#define SDMMC_IT_SDIOIT                      SDMMC_MASK_SDIOITIE
#if defined(STM32L4P5xx) || defined(STM32L4Q5xx) || defined(STM32L4R5xx) || defined(STM32L4R7xx) || defined(STM32L4R9xx) || defined(STM32L4S5xx) || defined(STM32L4S7xx) || defined(STM32L4S9xx)
#define SDMMC_IT_ACKFAIL                   SDMMC_MASK_ACKFAILIE
#define SDMMC_IT_ACKTIMEOUT                SDMMC_MASK_ACKTIMEOUTIE
#define SDMMC_IT_VSWEND                    SDMMC_MASK_VSWENDIE
#define SDMMC_IT_CKSTOP                    SDMMC_MASK_CKSTOPIE
#define SDMMC_IT_IDMABTC                   SDMMC_MASK_IDMABTCIE
#endif                                                                                                                           
   
      
    

                                  
      
    
#define SDMMC_FLAG_CCRCFAIL                  SDMMC_STA_CCRCFAIL
#define SDMMC_FLAG_DCRCFAIL                  SDMMC_STA_DCRCFAIL
#define SDMMC_FLAG_CTIMEOUT                  SDMMC_STA_CTIMEOUT
#define SDMMC_FLAG_DTIMEOUT                  SDMMC_STA_DTIMEOUT
#define SDMMC_FLAG_TXUNDERR                  SDMMC_STA_TXUNDERR
#define SDMMC_FLAG_RXOVERR                   SDMMC_STA_RXOVERR
#define SDMMC_FLAG_CMDREND                   SDMMC_STA_CMDREND
#define SDMMC_FLAG_CMDSENT                   SDMMC_STA_CMDSENT
#define SDMMC_FLAG_DATAEND                   SDMMC_STA_DATAEND
#if defined(STM32L4P5xx) || defined(STM32L4Q5xx) || defined(STM32L4R5xx) || defined(STM32L4R7xx) || defined(STM32L4R9xx) || defined(STM32L4S5xx) || defined(STM32L4S7xx) || defined(STM32L4S9xx)
#define SDMMC_FLAG_DHOLD                     SDMMC_STA_DHOLD
#endif                                                                                                                           
#define SDMMC_FLAG_DBCKEND                   SDMMC_STA_DBCKEND
#if defined(STM32L4P5xx) || defined(STM32L4Q5xx) || defined(STM32L4R5xx) || defined(STM32L4R7xx) || defined(STM32L4R9xx) || defined(STM32L4S5xx) || defined(STM32L4S7xx) || defined(STM32L4S9xx)
#define SDMMC_FLAG_DABORT                    SDMMC_STA_DABORT
#define SDMMC_FLAG_DPSMACT                   SDMMC_STA_DPSMACT
#define SDMMC_FLAG_CMDACT                    SDMMC_STA_CPSMACT
#else
#define SDMMC_FLAG_CMDACT                    SDMMC_STA_CMDACT
#define SDMMC_FLAG_TXACT                     SDMMC_STA_TXACT
#define SDMMC_FLAG_RXACT                     SDMMC_STA_RXACT
#endif                                                                                                                           
#define SDMMC_FLAG_TXFIFOHE                  SDMMC_STA_TXFIFOHE
#define SDMMC_FLAG_RXFIFOHF                  SDMMC_STA_RXFIFOHF
#define SDMMC_FLAG_TXFIFOF                   SDMMC_STA_TXFIFOF
#define SDMMC_FLAG_RXFIFOF                   SDMMC_STA_RXFIFOF
#define SDMMC_FLAG_TXFIFOE                   SDMMC_STA_TXFIFOE
#define SDMMC_FLAG_RXFIFOE                   SDMMC_STA_RXFIFOE
#if defined(STM32L4P5xx) || defined(STM32L4Q5xx) || defined(STM32L4R5xx) || defined(STM32L4R7xx) || defined(STM32L4R9xx) || defined(STM32L4S5xx) || defined(STM32L4S7xx) || defined(STM32L4S9xx)
#define SDMMC_FLAG_BUSYD0                    SDMMC_STA_BUSYD0
#define SDMMC_FLAG_BUSYD0END                 SDMMC_STA_BUSYD0END
#else
#define SDMMC_FLAG_TXDAVL                    SDMMC_STA_TXDAVL
#define SDMMC_FLAG_RXDAVL                    SDMMC_STA_RXDAVL
#endif                                                                                                                           
#define SDMMC_FLAG_SDIOIT                    SDMMC_STA_SDIOIT
#if defined(STM32L4P5xx) || defined(STM32L4Q5xx) || defined(STM32L4R5xx) || defined(STM32L4R7xx) || defined(STM32L4R9xx) || defined(STM32L4S5xx) || defined(STM32L4S7xx) || defined(STM32L4S9xx)
#define SDMMC_FLAG_ACKFAIL                   SDMMC_STA_ACKFAIL
#define SDMMC_FLAG_ACKTIMEOUT                SDMMC_STA_ACKTIMEOUT
#define SDMMC_FLAG_VSWEND                    SDMMC_STA_VSWEND
#define SDMMC_FLAG_CKSTOP                    SDMMC_STA_CKSTOP
#define SDMMC_FLAG_IDMATE                    SDMMC_STA_IDMATE
#define SDMMC_FLAG_IDMABTC                   SDMMC_STA_IDMABTC
#endif                                                                                                                           

#if defined(STM32L4P5xx) || defined(STM32L4Q5xx) || defined(STM32L4R5xx) || defined(STM32L4R7xx) || defined(STM32L4R9xx) || defined(STM32L4S5xx) || defined(STM32L4S7xx) || defined(STM32L4S9xx)
#define SDMMC_STATIC_FLAGS                   ((uint32_t)(SDMMC_FLAG_CCRCFAIL   | SDMMC_FLAG_DCRCFAIL | SDMMC_FLAG_CTIMEOUT |\
                                                         SDMMC_FLAG_DTIMEOUT   | SDMMC_FLAG_TXUNDERR | SDMMC_FLAG_RXOVERR  |\
                                                         SDMMC_FLAG_CMDREND    | SDMMC_FLAG_CMDSENT  | SDMMC_FLAG_DATAEND  |\
                                                         SDMMC_FLAG_DHOLD      | SDMMC_FLAG_DBCKEND  | SDMMC_FLAG_DABORT   |\
                                                         SDMMC_FLAG_BUSYD0END  | SDMMC_FLAG_SDIOIT   | SDMMC_FLAG_ACKFAIL  |\
                                                         SDMMC_FLAG_ACKTIMEOUT | SDMMC_FLAG_VSWEND   | SDMMC_FLAG_CKSTOP   |\
                                                         SDMMC_FLAG_IDMATE     | SDMMC_FLAG_IDMABTC))

#define SDMMC_STATIC_CMD_FLAGS               ((uint32_t)(SDMMC_FLAG_CCRCFAIL | SDMMC_FLAG_CTIMEOUT  | SDMMC_FLAG_CMDREND |\
                                                         SDMMC_FLAG_CMDSENT  | SDMMC_FLAG_BUSYD0END))

#define SDMMC_STATIC_DATA_FLAGS              ((uint32_t)(SDMMC_FLAG_DCRCFAIL | SDMMC_FLAG_DTIMEOUT | SDMMC_FLAG_TXUNDERR |\
                                                         SDMMC_FLAG_RXOVERR  | SDMMC_FLAG_DATAEND  | SDMMC_FLAG_DHOLD    |\
                                                         SDMMC_FLAG_DBCKEND  | SDMMC_FLAG_DABORT   | SDMMC_FLAG_IDMATE   |\
                                                         SDMMC_FLAG_IDMABTC))

#else
#define SDMMC_STATIC_FLAGS                   ((uint32_t)(SDMMC_FLAG_CCRCFAIL | SDMMC_FLAG_DCRCFAIL | SDMMC_FLAG_CTIMEOUT |\
                                                         SDMMC_FLAG_DTIMEOUT | SDMMC_FLAG_TXUNDERR | SDMMC_FLAG_RXOVERR  |\
                                                         SDMMC_FLAG_CMDREND  | SDMMC_FLAG_CMDSENT  | SDMMC_FLAG_DATAEND  |\
                                                         SDMMC_FLAG_DBCKEND  | SDMMC_FLAG_SDIOIT))

#define SDMMC_STATIC_CMD_FLAGS               ((uint32_t)(SDMMC_FLAG_CCRCFAIL | SDMMC_FLAG_CTIMEOUT | SDMMC_FLAG_CMDREND |\
                                                         SDMMC_FLAG_CMDSENT))

#define SDMMC_STATIC_DATA_FLAGS              ((uint32_t)(SDMMC_FLAG_DCRCFAIL | SDMMC_FLAG_DTIMEOUT | SDMMC_FLAG_TXUNDERR |\
                                                         SDMMC_FLAG_RXOVERR  | SDMMC_FLAG_DATAEND  | SDMMC_FLAG_DBCKEND))
#endif                                                                                                                           
   
      
    

   
      
    

                                                                                
                                                               
      
    

                                                              
                                                             
      
    
                                                                                 
                           
                               
#if defined(STM32L4P5xx) || defined(STM32L4Q5xx) || defined(STM32L4R5xx) || defined(STM32L4R7xx) || defined(STM32L4R9xx) || defined(STM32L4S5xx) || defined(STM32L4S7xx) || defined(STM32L4S9xx)
#define CLKCR_CLEAR_MASK         ((uint32_t)(SDMMC_CLKCR_CLKDIV  | SDMMC_CLKCR_PWRSAV |\
                                             SDMMC_CLKCR_WIDBUS |\
                                             SDMMC_CLKCR_NEGEDGE | SDMMC_CLKCR_HWFC_EN |\
                                             SDMMC_CLKCR_DDR | SDMMC_CLKCR_BUSSPEED |\
                                             SDMMC_CLKCR_SELCLKRX))
#else
#define CLKCR_CLEAR_MASK         ((uint32_t)(SDMMC_CLKCR_CLKDIV  | SDMMC_CLKCR_PWRSAV |\
                                             SDMMC_CLKCR_BYPASS  | SDMMC_CLKCR_WIDBUS |\
                                             SDMMC_CLKCR_NEGEDGE | SDMMC_CLKCR_HWFC_EN))
#endif                                                                                                                           

                           
                            
#define DCTRL_CLEAR_MASK         ((uint32_t)(SDMMC_DCTRL_DTEN    | SDMMC_DCTRL_DTDIR |\
                                             SDMMC_DCTRL_DTMODE  | SDMMC_DCTRL_DBLOCKSIZE))

                         
                             
#if defined(STM32L4P5xx) || defined(STM32L4Q5xx) || defined(STM32L4R5xx) || defined(STM32L4R7xx) || defined(STM32L4R9xx) || defined(STM32L4S5xx) || defined(STM32L4S7xx) || defined(STM32L4S9xx)
#define CMD_CLEAR_MASK           ((uint32_t)(SDMMC_CMD_CMDINDEX | SDMMC_CMD_WAITRESP |\
                                             SDMMC_CMD_WAITINT  | SDMMC_CMD_WAITPEND |\
                                             SDMMC_CMD_CPSMEN   | SDMMC_CMD_CMDSUSPEND))
#else
#define CMD_CLEAR_MASK           ((uint32_t)(SDMMC_CMD_CMDINDEX | SDMMC_CMD_WAITRESP |\
                                             SDMMC_CMD_WAITINT  | SDMMC_CMD_WAITPEND |\
                                             SDMMC_CMD_CPSMEN   | SDMMC_CMD_SDIOSUSPEND))
#endif                                                                                                                           

#if defined(STM32L4P5xx) || defined(STM32L4Q5xx) || defined(STM32L4R5xx) || defined(STM32L4R7xx) || defined(STM32L4R9xx) || defined(STM32L4S5xx) || defined(STM32L4S7xx) || defined(STM32L4S9xx)
                                                                          
#define SDMMC_INIT_CLK_DIV ((uint8_t)0x8A)

                                                                        
#define SDMMC_NSPEED_CLK_DIV ((uint8_t)0x3)

                                                                     
#define SDMMC_HSPEED_CLK_DIV ((uint8_t)0x2)

                                               
#define SDMMC_TRANSFER_CLK_DIV SDMMC_NSPEED_CLK_DIV
#else
                                                 
#define SDMMC_INIT_CLK_DIV     ((uint8_t)0x76)                                                   

                                               
#define SDMMC_TRANSFER_CLK_DIV ((uint8_t)0x0)                                                       
#endif                                                                                                                           
   
      
    

                                                                        
                                                                         
      
    

   
                                    
                                        
                
    
#if !defined(STM32L4P5xx) && !defined(STM32L4Q5xx) && !defined(STM32L4R5xx) && !defined(STM32L4R7xx) && !defined(STM32L4R9xx) && !defined(STM32L4S5xx) && !defined(STM32L4S7xx) && !defined(STM32L4S9xx)
   
                                    
                                       
                
    
#define __SDMMC_ENABLE(__INSTANCE__)  ((__INSTANCE__)->CLKCR |= SDMMC_CLKCR_CLKEN)

   
                                     
                                       
                
    
#define __SDMMC_DISABLE(__INSTANCE__)  ((__INSTANCE__)->CLKCR &= ~SDMMC_CLKCR_CLKEN)

   
                                          
                                       
                
    
#define __SDMMC_DMA_ENABLE(__INSTANCE__)  ((__INSTANCE__)->DCTRL |= SDMMC_DCTRL_DMAEN)

   
                                           
                                       
                
    
#define __SDMMC_DMA_DISABLE(__INSTANCE__)  ((__INSTANCE__)->DCTRL &= ~SDMMC_DCTRL_DMAEN)
#endif                                                                                                                                   

   
                                              
                                                         
                                                                               
                                                                               
                                                                                             
                                                                                            
                                                                         
                                                             
                                                                             
                                                                            
                                                                                             
                                                                                    
                                                                                            
                                                                     
                                                                                            
                                                                                 
                                                                             
                                                                          
                                                                         
                                                                         
                                                                       
                                                                   
                                                                  
                                                                    
                                                                   
                                                                                
                                                                               
                                                                                                         
                                                                        
                                                                               
                                                                              
                                                                                                    
                                                                                               
                                                                                
                
    
#define __SDMMC_ENABLE_IT(__INSTANCE__, __INTERRUPT__)  ((__INSTANCE__)->MASK |= (__INTERRUPT__))

   
                                               
                                                         
                                                                                
                                                                               
                                                                                             
                                                                                            
                                                                         
                                                             
                                                                             
                                                                            
                                                                                             
                                                                                    
                                                                                            
                                                                     
                                                                                            
                                                                                 
                                                                             
                                                                          
                                                                         
                                                                         
                                                                       
                                                                   
                                                                  
                                                                    
                                                                   
                                                                                
                                                                               
                                                                                                         
                                                                        
                                                                               
                                                                              
                                                                                                    
                                                                                               
                                                                                
                
    
#define __SDMMC_DISABLE_IT(__INSTANCE__, __INTERRUPT__)  ((__INSTANCE__)->MASK &= ~(__INTERRUPT__))

   
                                                                  
                                                         
                                                  
                                                               
                                                                                     
                                                                                    
                                                                 
                                                     
                                                                     
                                                                    
                                                                                     
                                                                            
                                                                                    
                                                             
                                                                                    
                                                                         
                                                                         
                                                                            
                                                                     
                                                                  
                                                                 
                                                                 
                                                               
                                                           
                                                          
                                                            
                                                           
                                                                                 
                                                                                                 
                                                                        
                                                                       
                                                                
                                                                       
                                                                      
                                                                                            
                                                                                       
                                                              
                                                                        
                                                       
    
#define __SDMMC_GET_FLAG(__INSTANCE__, __FLAG__)  (((__INSTANCE__)->STA &(__FLAG__)) != 0U)


   
                                           
                                                         
                                                  
                                                                                
                                                                                     
                                                                                    
                                                                 
                                                     
                                                                     
                                                                    
                                                                                     
                                                                            
                                                                                    
                                                             
                                                                                    
                                                                         
                                                                                                 
                                                                
                                                                       
                                                                      
                                                                                            
                                                                                       
                                                              
                                                                        
                
    
#define __SDMMC_CLEAR_FLAG(__INSTANCE__, __FLAG__)  ((__INSTANCE__)->ICR = (__FLAG__))

   
                                                                             
                                                         
                                                                         
                                                               
                                                                                             
                                                                                            
                                                                         
                                                             
                                                                             
                                                                            
                                                                                             
                                                                                    
                                                                                            
                                                                     
                                                                                            
                                                                                 
                                                                             
                                                                          
                                                                         
                                                                         
                                                                       
                                                                   
                                                                  
                                                                    
                                                                   
                                                                                
                                                                               
                                                                                                         
                                                                        
                                                                               
                                                                              
                                                                                                    
                                                                                               
                                                                                
                                                     
    
#define __SDMMC_GET_IT  (__INSTANCE__, __INTERRUPT__)  (((__INSTANCE__)->STA &\
                                                         (__INTERRUPT__)) == (__INTERRUPT__))

   
                                                      
                                                         
                                                                        
                                                                                
                                                                                             
                                                                                            
                                                                         
                                                             
                                                                             
                                                                            
                                                                                             
                                                                                    
                                                                                            
                                                                     
                                                                                              
                                                                                 
                                                                                                         
                                                                        
                                                                               
                                                                              
                                                                                                    
                                                                                               
                                                                                
                
    
#define __SDMMC_CLEAR_IT(__INSTANCE__, __INTERRUPT__)  ((__INSTANCE__)->ICR = (__INTERRUPT__))

   
                                                        
                                                         
                
    
#define __SDMMC_START_READWAIT_ENABLE(__INSTANCE__)  ((__INSTANCE__)->DCTRL |= SDMMC_DCTRL_RWSTART)

   
                                                          
                                                         
                
    
#define __SDMMC_START_READWAIT_DISABLE(__INSTANCE__)  ((__INSTANCE__)->DCTRL &= ~SDMMC_DCTRL_RWSTART)

   
                                                        
                                                         
                
    
#define __SDMMC_STOP_READWAIT_ENABLE(__INSTANCE__)  ((__INSTANCE__)->DCTRL |= SDMMC_DCTRL_RWSTOP)

   
                                                         
                                                         
                
    
#define __SDMMC_STOP_READWAIT_DISABLE(__INSTANCE__)  ((__INSTANCE__)->DCTRL &= ~SDMMC_DCTRL_RWSTOP)

   
                                             
                                                         
                
    
#define __SDMMC_OPERATION_ENABLE(__INSTANCE__)  ((__INSTANCE__)->DCTRL |= SDMMC_DCTRL_SDIOEN)

   
                                              
                                                         
                
    
#define __SDMMC_OPERATION_DISABLE(__INSTANCE__)  ((__INSTANCE__)->DCTRL &= ~SDMMC_DCTRL_SDIOEN)

   
                                                      
                                                         
                
    
#if !defined(STM32L4P5xx) && !defined(STM32L4Q5xx) && !defined(STM32L4R5xx) && !defined(STM32L4R7xx) && !defined(STM32L4R9xx) && !defined(STM32L4S5xx) && !defined(STM32L4S7xx) && !defined(STM32L4S9xx)
#define __SDMMC_SUSPEND_CMD_ENABLE(__INSTANCE__)  ((__INSTANCE__)->CMD |= SDMMC_CMD_SDIOSUSPEND)
#else
#define __SDMMC_SUSPEND_CMD_ENABLE(__INSTANCE__)  ((__INSTANCE__)->CMD |= SDMMC_CMD_CMDSUSPEND)
#endif                                                                                                                                   

   
                                                       
                                                         
                
    
#if !defined(STM32L4P5xx) && !defined(STM32L4Q5xx) && !defined(STM32L4R5xx) && !defined(STM32L4R7xx) && !defined(STM32L4R9xx) && !defined(STM32L4S5xx) && !defined(STM32L4S7xx) && !defined(STM32L4S9xx)
#define __SDMMC_SUSPEND_CMD_DISABLE(__INSTANCE__)  ((__INSTANCE__)->CMD &= ~SDMMC_CMD_SDIOSUSPEND)
#else
#define __SDMMC_SUSPEND_CMD_DISABLE(__INSTANCE__)  ((__INSTANCE__)->CMD &= ~SDMMC_CMD_CMDSUSPEND)
#endif                                                                                                                                   

#if defined(STM32L4P5xx) || defined(STM32L4Q5xx) || defined(STM32L4R5xx) || defined(STM32L4R7xx) || defined(STM32L4R9xx) || defined(STM32L4S5xx) || defined(STM32L4S7xx) || defined(STM32L4S9xx)
   
                                     
                                                       
                
    
#define __SDMMC_CMDTRANS_ENABLE(__INSTANCE__)  ((__INSTANCE__)->CMD |= SDMMC_CMD_CMDTRANS)

   
                                      
                                                       
                
    
#define __SDMMC_CMDTRANS_DISABLE(__INSTANCE__)  ((__INSTANCE__)->CMD &= ~SDMMC_CMD_CMDTRANS)

   
                                    
                                                       
                
    
#define __SDMMC_CMDSTOP_ENABLE(__INSTANCE__)  ((__INSTANCE__)->CMD |= SDMMC_CMD_CMDSTOP)

   
                                     
                                                       
                
    
#define __SDMMC_CMDSTOP_DISABLE(__INSTANCE__)  ((__INSTANCE__)->CMD &= ~SDMMC_CMD_CMDSTOP)
#endif                                                                                                                           

   
      
    

   
      
    

                                                                                
                                           
      
    

                                                                                  
                                   
      
    
HAL_StatusTypeDef SDMMC_Init(SDMMC_TypeDef *SDMMCx, SDMMC_InitTypeDef Init);
   
      
    

                                                                                  
                                   
      
    
uint32_t          SDMMC_ReadFIFO(const SDMMC_TypeDef *SDMMCx);
HAL_StatusTypeDef SDMMC_WriteFIFO(SDMMC_TypeDef *SDMMCx, uint32_t *pWriteData);
   
      
    

                                                                                  
                                   
      
    
HAL_StatusTypeDef SDMMC_PowerState_ON(SDMMC_TypeDef *SDMMCx);
#if defined(STM32L4P5xx) || defined(STM32L4Q5xx) || defined(STM32L4R5xx) || defined(STM32L4R7xx) || defined(STM32L4R9xx) || defined(STM32L4S5xx) || defined(STM32L4S7xx) || defined(STM32L4S9xx)
HAL_StatusTypeDef SDMMC_PowerState_Cycle(SDMMC_TypeDef *SDMMCx);
#endif                                                                                                                           
HAL_StatusTypeDef SDMMC_PowerState_OFF(SDMMC_TypeDef *SDMMCx);
uint32_t          SDMMC_GetPowerState(const SDMMC_TypeDef *SDMMCx);

                                                            
HAL_StatusTypeDef SDMMC_SendCommand(SDMMC_TypeDef *SDMMCx, SDMMC_CmdInitTypeDef *Command);
uint8_t           SDMMC_GetCommandResponse(const SDMMC_TypeDef *SDMMCx);
uint32_t          SDMMC_GetResponse(const SDMMC_TypeDef *SDMMCx, uint32_t Response);

                                                         
HAL_StatusTypeDef SDMMC_ConfigData(SDMMC_TypeDef *SDMMCx, SDMMC_DataInitTypeDef *Data);
uint32_t          SDMMC_GetDataCounter(const SDMMC_TypeDef *SDMMCx);
uint32_t          SDMMC_GetFIFOCount(const SDMMC_TypeDef *SDMMCx);

                                           
HAL_StatusTypeDef SDMMC_SetSDMMCReadWaitMode(SDMMC_TypeDef *SDMMCx,
                                             uint32_t SDMMC_ReadWaitMode);
   
      
    

                                         
                                   
      
    
uint32_t SDMMC_CmdBlockLength(SDMMC_TypeDef *SDMMCx, uint32_t BlockSize);
uint32_t SDMMC_CmdReadSingleBlock(SDMMC_TypeDef *SDMMCx, uint32_t ReadAdd);
uint32_t SDMMC_CmdReadMultiBlock(SDMMC_TypeDef *SDMMCx, uint32_t ReadAdd);
uint32_t SDMMC_CmdWriteSingleBlock(SDMMC_TypeDef *SDMMCx, uint32_t WriteAdd);
uint32_t SDMMC_CmdWriteMultiBlock(SDMMC_TypeDef *SDMMCx, uint32_t WriteAdd);
uint32_t SDMMC_CmdEraseStartAdd(SDMMC_TypeDef *SDMMCx, uint32_t StartAdd);
uint32_t SDMMC_CmdSDEraseStartAdd(SDMMC_TypeDef *SDMMCx, uint32_t StartAdd);
uint32_t SDMMC_CmdEraseEndAdd(SDMMC_TypeDef *SDMMCx, uint32_t EndAdd);
uint32_t SDMMC_CmdSDEraseEndAdd(SDMMC_TypeDef *SDMMCx, uint32_t EndAdd);
uint32_t SDMMC_CmdErase(SDMMC_TypeDef *SDMMCx, uint32_t EraseType);
uint32_t SDMMC_CmdStopTransfer(SDMMC_TypeDef *SDMMCx);
uint32_t SDMMC_CmdSelDesel(SDMMC_TypeDef *SDMMCx, uint64_t Addr);
uint32_t SDMMC_CmdGoIdleState(SDMMC_TypeDef *SDMMCx);
uint32_t SDMMC_CmdOperCond(SDMMC_TypeDef *SDMMCx);
uint32_t SDMMC_CmdAppCommand(SDMMC_TypeDef *SDMMCx, uint32_t Argument);
uint32_t SDMMC_CmdAppOperCommand(SDMMC_TypeDef *SDMMCx, uint32_t Argument);
uint32_t SDMMC_CmdBusWidth(SDMMC_TypeDef *SDMMCx, uint32_t BusWidth);
uint32_t SDMMC_CmdSendSCR(SDMMC_TypeDef *SDMMCx);
uint32_t SDMMC_CmdSendCID(SDMMC_TypeDef *SDMMCx);
uint32_t SDMMC_CmdSendCSD(SDMMC_TypeDef *SDMMCx, uint32_t Argument);
uint32_t SDMMC_CmdSetRelAdd(SDMMC_TypeDef *SDMMCx, uint16_t *pRCA);
uint32_t SDMMC_CmdSetRelAddMmc(SDMMC_TypeDef *SDMMCx, uint16_t RCA);
uint32_t SDMMC_CmdSleepMmc(SDMMC_TypeDef *SDMMCx, uint32_t Argument);
uint32_t SDMMC_CmdSendStatus(SDMMC_TypeDef *SDMMCx, uint32_t Argument);
uint32_t SDMMC_CmdStatusRegister(SDMMC_TypeDef *SDMMCx);
#if defined(STM32L4P5xx) || defined(STM32L4Q5xx) || defined(STM32L4R5xx) || defined(STM32L4R7xx) || defined(STM32L4R9xx) || defined(STM32L4S5xx) || defined(STM32L4S7xx) || defined(STM32L4S9xx)
uint32_t SDMMC_CmdVoltageSwitch(SDMMC_TypeDef *SDMMCx);
#endif                                                                                                                           
uint32_t SDMMC_CmdOpCondition(SDMMC_TypeDef *SDMMCx, uint32_t Argument);
uint32_t SDMMC_CmdSwitch(SDMMC_TypeDef *SDMMCx, uint32_t Argument);
uint32_t SDMMC_CmdSendEXTCSD(SDMMC_TypeDef *SDMMCx, uint32_t Argument);
   
      
    

                                                                                  
                                   
      
    
uint32_t SDMMC_GetCmdResp1(SDMMC_TypeDef *SDMMCx, uint8_t SD_CMD, uint32_t Timeout);
uint32_t SDMMC_GetCmdResp2(SDMMC_TypeDef *SDMMCx);
uint32_t SDMMC_GetCmdResp3(SDMMC_TypeDef *SDMMCx);
uint32_t SDMMC_GetCmdResp6(SDMMC_TypeDef *SDMMCx, uint8_t SD_CMD, uint16_t *pRCA);
uint32_t SDMMC_GetCmdResp7(SDMMC_TypeDef *SDMMCx);
   
      
    

   
      
    

   
      
    

   
      
    

#endif             

#ifdef __cplusplus
}
#endif

#endif                           
