/**
  ******************************************************************************
  * @file    stm32l4xx_hal_crc.h
  * @author  MCD Application Team
  * @brief   Header file of CRC HAL module.
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

                                                                                
#ifndef STM32L4xx_HAL_CRC_H
#define STM32L4xx_HAL_CRC_H

#ifdef __cplusplus
extern "C" {
#endif

                                                                                
#include "stm32l4xx_hal_def.h"

                                    
      
    

                   
      
    

                                                                                
                                                   
      
    

   
                                              
    
typedef enum
{
  HAL_CRC_STATE_RESET     = 0x00U,                                             
  HAL_CRC_STATE_READY     = 0x01U,                                             
  HAL_CRC_STATE_BUSY      = 0x02U,                                             
  HAL_CRC_STATE_TIMEOUT   = 0x03U,                                             
  HAL_CRC_STATE_ERROR     = 0x04U                                              
} HAL_CRC_StateTypeDef;

   
                                        
    
typedef struct
{
  uint8_t DefaultPolynomialUse;                                                                                                                 
                                                                                                  
                                                                                                                    
                                                            
                                                                                                             
                                                                                                                    
                                                                            

  uint8_t DefaultInitValueUse;                                                                                                                     
                                                                                                 
                                                                                                                      
                                                                                                                       

  uint32_t GeneratingPolynomial;                                                                                                   
                                                                                                                 
                                                                                                                       
                                                                                                                   
                                                                           

  uint32_t CRCLength;                                                                                                      
                                                                     
                                                                                                      
                                                                                                      
                                                                                                     
                                                                                                        

  uint32_t InitValue;                                                                                                          
                                                                                    

  uint32_t InputDataInversionMode;                                                                                                              
                                                                                    
                                                                                                               
                                                                                                                       
                                                             
                                                                                                                
                                                                        
                                                                                                                       
                                                                

  uint32_t OutputDataInversionMode;                                                                                                                          
                                                         
                                                                                                          
                                                                                                                    
                                                               
} CRC_InitTypeDef;

   
                                           
    
typedef struct
{
  CRC_TypeDef                 *Instance;                                       

  CRC_InitTypeDef             Init;                                            

  HAL_LockTypeDef             Lock;                                            

  __IO HAL_CRC_StateTypeDef   State;                                           

  uint32_t InputDataFormat;                                                                                                               
                                                         
                                                                                                                      
                                                        
                                                                                                                
                                                                    
                                                                                                                      
                                                         

                                                                                                                        
                                                                                                                     
                                                   
} CRC_HandleTypeDef;
   
      
    

                                                                                
                                                           
      
    

                                                                               
      
    
#define DEFAULT_CRC32_POLY      0x04C11DB7U                                                                                                   
   
      
    

                                                                                   
      
    
#define DEFAULT_CRC_INITVALUE   0xFFFFFFFFU                                   
   
      
    

                                                                                           
      
    
#define DEFAULT_POLYNOMIAL_ENABLE       ((uint8_t)0x00U)                                                          
#define DEFAULT_POLYNOMIAL_DISABLE      ((uint8_t)0x01U)                                                          
   
      
    

                                                                                              
      
    
#define DEFAULT_INIT_VALUE_ENABLE      ((uint8_t)0x00U)                                          
#define DEFAULT_INIT_VALUE_DISABLE     ((uint8_t)0x01U)                                          
   
      
    

                                                                               
      
    
#define CRC_POLYLENGTH_32B                  0x00000000U                                                             
#define CRC_POLYLENGTH_16B                  CRC_CR_POLYSIZE_0                                                       
#define CRC_POLYLENGTH_8B                   CRC_CR_POLYSIZE_1                                                       
#define CRC_POLYLENGTH_7B                   CRC_CR_POLYSIZE                                                         
   
      
    

                                                                                              
      
    
#define HAL_CRC_LENGTH_32B     32U                                 
#define HAL_CRC_LENGTH_16B     16U                                 
#define HAL_CRC_LENGTH_8B       8U                                 
#define HAL_CRC_LENGTH_7B       7U                                 
   
      
    

                                                         
      
    
                                                                            
                                                                          
                                                                            
                                              
#define CRC_INPUTDATA_FORMAT_UNDEFINED             0x00000000U                                        
#define CRC_INPUTDATA_FORMAT_BYTES                 0x00000001U                                        
#define CRC_INPUTDATA_FORMAT_HALFWORDS             0x00000002U                                        
#define CRC_INPUTDATA_FORMAT_WORDS                 0x00000003U                                        
   
      
    

   
      
    

                                                                                
                                                     
      
    

                                  
                                  
                
    
#define __HAL_CRC_RESET_HANDLE_STATE(__HANDLE__) ((__HANDLE__)->State = HAL_CRC_STATE_RESET)

   
                                    
                                 
                
    
#define __HAL_CRC_DR_RESET(__HANDLE__) ((__HANDLE__)->Instance->CR |= CRC_CR_RESET)

   
                                          
                                 
                                         
                
    
#define __HAL_CRC_INITIALCRCVALUE_CONFIG(__HANDLE__, __INIT__) ((__HANDLE__)->Instance->INIT = (__INIT__))

   
                                                            
                                
                                                           
                                                                                       
                
    
#define __HAL_CRC_SET_IDR(__HANDLE__, __VALUE__) (WRITE_REG((__HANDLE__)->Instance->IDR, (__VALUE__)))

   
                                                                        
                                
                                                                                       
                                    
    
#define __HAL_CRC_GET_IDR(__HANDLE__) (((__HANDLE__)->Instance->IDR) & CRC_IDR_IDR)
   
      
    


                                                                            
                                                    
      
    

#define IS_DEFAULT_POLYNOMIAL(DEFAULT) (((DEFAULT) == DEFAULT_POLYNOMIAL_ENABLE) || \
                                        ((DEFAULT) == DEFAULT_POLYNOMIAL_DISABLE))

#define IS_DEFAULT_INIT_VALUE(VALUE)  (((VALUE) == DEFAULT_INIT_VALUE_ENABLE) || \
                                       ((VALUE) == DEFAULT_INIT_VALUE_DISABLE))

#define IS_CRC_POL_LENGTH(LENGTH)     (((LENGTH) == CRC_POLYLENGTH_32B) || \
                                       ((LENGTH) == CRC_POLYLENGTH_16B) || \
                                       ((LENGTH) == CRC_POLYLENGTH_8B)  || \
                                       ((LENGTH) == CRC_POLYLENGTH_7B))

#define IS_CRC_INPUTDATA_FORMAT(FORMAT)           (((FORMAT) == CRC_INPUTDATA_FORMAT_BYTES)     || \
                                                   ((FORMAT) == CRC_INPUTDATA_FORMAT_HALFWORDS) || \
                                                   ((FORMAT) == CRC_INPUTDATA_FORMAT_WORDS))

   
      
    

                                     
#include "stm32l4xx_hal_crc_ex.h"

                                                                                
                                                           
      
    

                                                                                
                                                                                          
      
    
HAL_StatusTypeDef HAL_CRC_Init(CRC_HandleTypeDef *hcrc);
HAL_StatusTypeDef HAL_CRC_DeInit(CRC_HandleTypeDef *hcrc);
void HAL_CRC_MspInit(CRC_HandleTypeDef *hcrc);
void HAL_CRC_MspDeInit(CRC_HandleTypeDef *hcrc);
   
      
    

                                                                                
                                                                        
      
    
uint32_t HAL_CRC_Accumulate(CRC_HandleTypeDef *hcrc, const uint32_t pBuffer[], uint32_t BufferLength);
uint32_t HAL_CRC_Calculate(CRC_HandleTypeDef *hcrc, const uint32_t pBuffer[], uint32_t BufferLength);
   
      
    

                                                                                
                                                                      
      
    
HAL_CRC_StateTypeDef HAL_CRC_GetState(const CRC_HandleTypeDef *hcrc);
   
      
    

   
      
    

   
      
    

   
      
    

#ifdef __cplusplus
}
#endif

#endif                          
