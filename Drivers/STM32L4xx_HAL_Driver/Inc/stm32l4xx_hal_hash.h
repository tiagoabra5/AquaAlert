/**
  ******************************************************************************
  * @file    stm32l4xx_hal_hash.h
  * @author  MCD Application Team
  * @brief   Header file of HASH HAL module.
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

                                                                                
#ifndef STM32L4xx_HAL_HASH_H
#define STM32L4xx_HAL_HASH_H

#ifdef __cplusplus
extern "C" {
#endif

                                                                                
#include "stm32l4xx_hal_def.h"

                                    
      
    
#if defined (HASH)
                    
      
    

                                                                                
                                                     
      
    

   
                                                   
    
typedef struct
{
  uint32_t DataType;                                                            
                                                                                      

  uint32_t KeySize;                                                         

  uint8_t *pKey;                                                       

} HASH_InitTypeDef;

   
                                          
    
typedef enum
{
  HAL_HASH_STATE_RESET             = 0x00U,                                                    
  HAL_HASH_STATE_READY             = 0x01U,                                                    
  HAL_HASH_STATE_BUSY              = 0x02U,                                                    
  HAL_HASH_STATE_TIMEOUT           = 0x06U,                                                    
  HAL_HASH_STATE_ERROR             = 0x07U,                                                    
  HAL_HASH_STATE_SUSPENDED         = 0x08U                                                     
} HAL_HASH_StateTypeDef;

   
                                          
    
typedef enum
{
  HAL_HASH_PHASE_READY             = 0x01U,                                                                
  HAL_HASH_PHASE_PROCESS           = 0x02U,                                                                
  HAL_HASH_PHASE_HMAC_STEP_1       = 0x03U,                                                           
                                                                                                          
  HAL_HASH_PHASE_HMAC_STEP_2       = 0x04U,                                                           
                                                                                               
  HAL_HASH_PHASE_HMAC_STEP_3       = 0x05U                                                            
                                                                                                          
} HAL_HASH_PhaseTypeDef;

   
                                            
    
typedef enum
{
  HAL_HASH_SUSPEND_NONE            = 0x00U,                                                    
  HAL_HASH_SUSPEND                 = 0x01U                                                     
} HAL_HASH_SuspendTypeDef;

#if (USE_HAL_HASH_REGISTER_CALLBACKS == 1U)
   
                                                              
    
typedef enum
{
  HAL_HASH_MSPINIT_CB_ID           = 0x00U,                                        
  HAL_HASH_MSPDEINIT_CB_ID         = 0x01U,                                        
  HAL_HASH_INPUTCPLT_CB_ID         = 0x02U,                                             
  HAL_HASH_DGSTCPLT_CB_ID          = 0x03U,                                                          
  HAL_HASH_ERROR_CB_ID             = 0x04U,                                      
} HAL_HASH_CallbackIDTypeDef;
#endif                                      


   
                                            
    
#if (USE_HAL_HASH_REGISTER_CALLBACKS == 1)
typedef struct __HASH_HandleTypeDef
#else
typedef struct
#endif                                        
{
  HASH_InitTypeDef           Init;                                             

  uint8_t const              *pHashInBuffPtr;                                 

  uint8_t                    *pHashOutBuffPtr;                                          

  uint8_t                    *pHashKeyBuffPtr;                                          

  uint8_t const              *pHashMsgBuffPtr;                                              

  uint32_t                   HashBuffSize;                                           

  __IO uint32_t              HashInCount;                                      

  __IO uint32_t              HashITCounter;                                        

  __IO uint32_t              HashKeyCount;                                                      

  HAL_StatusTypeDef          Status;                                           

  HAL_HASH_PhaseTypeDef      Phase;                                           

  DMA_HandleTypeDef          *hdmain;                                               

  HAL_LockTypeDef            Lock;                                   

  __IO HAL_HASH_StateTypeDef State;                                         

  HAL_HASH_SuspendTypeDef    SuspendRequest;                                                  

  FlagStatus                 DigestCalculationDisable;                                                                                                        

  __IO uint32_t              NbWordsAlreadyPushed;                                                                                

  __IO  uint32_t             ErrorCode;                               

  __IO  uint32_t             Accumulation;                                                 

#if (USE_HAL_HASH_REGISTER_CALLBACKS == 1)
  void (* InCpltCallback)(struct __HASH_HandleTypeDef *hhash);                                               

  void (* DgstCpltCallback)(struct __HASH_HandleTypeDef *hhash);                                                          

  void (* ErrorCallback)(struct __HASH_HandleTypeDef *hhash);                                     

  void (* MspInitCallback)(struct __HASH_HandleTypeDef *hhash);                                      

  void (* MspDeInitCallback)(struct __HASH_HandleTypeDef *hhash);                                      

#endif                                        
} HASH_HandleTypeDef;

#if (USE_HAL_HASH_REGISTER_CALLBACKS == 1U)
   
                                                
    
typedef  void (*pHASH_CallbackTypeDef)(HASH_HandleTypeDef *hhash);                                                     
#endif                                      

   
      
    

                                                                                

                                                              
      
    

                                                            
      
    
#define HASH_ALGOSELECTION_SHA1      0x00000000U                                
#define HASH_ALGOSELECTION_MD5       HASH_CR_ALGO_0                                    
#define HASH_ALGOSELECTION_SHA224    HASH_CR_ALGO_1                                    
#define HASH_ALGOSELECTION_SHA256    HASH_CR_ALGO                                      
   
      
    

                                                       
      
    
#define HASH_ALGOMODE_HASH         0x00000000U                          
#define HASH_ALGOMODE_HMAC         HASH_CR_MODE                                    
   
      
    

                                                      
      
    
#define HASH_DATATYPE_32B          0x00000000U                                                     
#define HASH_DATATYPE_16B          HASH_CR_DATATYPE_0                                                     
#define HASH_DATATYPE_8B           HASH_CR_DATATYPE_1                                                     
#define HASH_DATATYPE_1B           HASH_CR_DATATYPE                                                       
   
      
    

                                                                          
      
    
#define HASH_HMAC_KEYTYPE_SHORTKEY      0x00000000U                                     
#define HASH_HMAC_KEYTYPE_LONGKEY       HASH_CR_LKEY                                               
   
      
    

                                                           
      
    
#define HASH_FLAG_DINIS            HASH_SR_DINIS                                                                                         
#define HASH_FLAG_DCIS             HASH_SR_DCIS                                                                                          
#define HASH_FLAG_DMAS             HASH_SR_DMAS                                                                                          
#define HASH_FLAG_BUSY             HASH_SR_BUSY                                                                                          
#define HASH_FLAG_DINNE            HASH_CR_DINNE                                                                                         

   
      
    

                                                                      
      
    
#define HASH_IT_DINI               HASH_IMR_DINIE                                                                
#define HASH_IT_DCI                HASH_IMR_DCIE                                                                 

   
      
    

                                                           
      
    
#define  HAL_HASH_ERROR_NONE             0x00000000U                                  
#define  HAL_HASH_ERROR_IT               0x00000001U                                  
#define  HAL_HASH_ERROR_DMA              0x00000002U                                  
#if (USE_HAL_HASH_REGISTER_CALLBACKS == 1U)
#define  HAL_HASH_ERROR_INVALID_CALLBACK 0x00000004U                                  
#endif                                      
   
      
    

   
      
    

                                                                                
                                                       
      
    

                                                                
                                                 
                                                             
                                                                                          
                                                                    
                                                                                                   
                                                                                           
                                                                                                             
                                                      
    
#define __HAL_HASH_GET_FLAG(__FLAG__)  (((__FLAG__) > 8U)  ?                    \
                                        ((HASH->CR & (__FLAG__)) == (__FLAG__)) :\
                                        ((HASH->SR & (__FLAG__)) == (__FLAG__)) )


                                          
                                                 
                                                             
                                                                                          
                                                                   
                
    
#define __HAL_HASH_CLEAR_FLAG(__FLAG__) CLEAR_BIT(HASH->SR, (__FLAG__))


                                                
                                                                        
                                                               
                                                                                             
                                                                  
                
    
#define __HAL_HASH_ENABLE_IT(__INTERRUPT__)   SET_BIT(HASH->IMR, (__INTERRUPT__))

                                                 
                                                                         
                                                               
                                                                                             
                                                                  
                
    
#define __HAL_HASH_DISABLE_IT(__INTERRUPT__)   CLEAR_BIT(HASH->IMR, (__INTERRUPT__))

                                   
                                   
                
    

#if (USE_HAL_HASH_REGISTER_CALLBACKS == 1)
#define __HAL_HASH_RESET_HANDLE_STATE(__HANDLE__) do{\
                                                      (__HANDLE__)->State = HAL_HASH_STATE_RESET;\
                                                      (__HANDLE__)->MspInitCallback = NULL;      \
                                                      (__HANDLE__)->MspDeInitCallback = NULL;    \
                                                     }while(0)
#else
#define __HAL_HASH_RESET_HANDLE_STATE(__HANDLE__) ((__HANDLE__)->State = HAL_HASH_STATE_RESET)
#endif                                      


                                    
                                   
                
    
#define __HAL_HASH_RESET_HANDLE_STATUS(__HANDLE__) ((__HANDLE__)->Status = HAL_OK)

   
                                                      
                                                                                            
                
    
#define __HAL_HASH_SET_MDMAT()          SET_BIT(HASH->CR, HASH_CR_MDMAT)

   
                                                       
                
    
#define __HAL_HASH_RESET_MDMAT()        CLEAR_BIT(HASH->CR, HASH_CR_MDMAT)


   
                                        
                
    
#define __HAL_HASH_START_DIGEST()       SET_BIT(HASH->STR, HASH_STR_DCAL)

   
                                                                                      
                                                                         
                
    
#define  __HAL_HASH_SET_NBVALIDBITS(__SIZE__)    MODIFY_REG(HASH->STR, HASH_STR_NBLW, 8U * ((__SIZE__) % 4U))

   
                               
                
    
#define __HAL_HASH_INIT()       SET_BIT(HASH->CR, HASH_CR_INIT)

   
      
    


                                                                            
                                                       
      
    
   
                                          
                         
    
#define HASH_DIGEST_LENGTH() ((READ_BIT(HASH->CR, HASH_CR_ALGO) == HASH_ALGOSELECTION_SHA1)   ?  20U : \
                              ((READ_BIT(HASH->CR, HASH_CR_ALGO) == HASH_ALGOSELECTION_SHA224) ?  28U : \
                               ((READ_BIT(HASH->CR, HASH_CR_ALGO) == HASH_ALGOSELECTION_SHA256) ?  32U : 16U ) ) )
   
                                                              
                                                      
    
#define HASH_NBW_PUSHED() ((READ_BIT(HASH->CR, HASH_CR_NBW)) >> 8U)

   
                                                     
                                             
                                                                          
    
#define IS_HASH_DATATYPE(__DATATYPE__) (((__DATATYPE__) == HASH_DATATYPE_32B)|| \
                                        ((__DATATYPE__) == HASH_DATATYPE_16B)|| \
                                        ((__DATATYPE__) == HASH_DATATYPE_8B) || \
                                        ((__DATATYPE__) == HASH_DATATYPE_1B))

   
                                                                            
                                  
                                                                                 
                                           
                                                                  
    
#define IS_HASH_DMA_MULTIBUFFER_SIZE(__SIZE__)  ((READ_BIT(HASH->CR, HASH_CR_MDMAT) == 0U) || (((__SIZE__) % 4U) == 0U))

   
                                                                            
                                  
                                                                                 
                                  
                                           
                                                                  
    
#define IS_HMAC_DMA_MULTIBUFFER_SIZE(__HANDLE__,__SIZE__)  ((((__HANDLE__)->DigestCalculationDisable) == RESET)\
                                                            || (((__SIZE__) % 4U) == 0U))
   
                                                              
                                  
                                                                                                              
    
#define IS_HASH_PROCESSING(__HANDLE__)  ((__HANDLE__)->Phase == HAL_HASH_PHASE_PROCESS)

   
                                                              
                                  
                                                                                                              
    
#define IS_HMAC_PROCESSING(__HANDLE__)  (((__HANDLE__)->Phase == HAL_HASH_PHASE_HMAC_STEP_1) || \
                                         ((__HANDLE__)->Phase == HAL_HASH_PHASE_HMAC_STEP_2) || \
                                         ((__HANDLE__)->Phase == HAL_HASH_PHASE_HMAC_STEP_3))

   
      
    

                                      
#include "stm32l4xx_hal_hash_ex.h"
                                                                                

                                                               
      
    

                                                                                             
      
    

                                                                                
HAL_StatusTypeDef HAL_HASH_Init(HASH_HandleTypeDef *hhash);
HAL_StatusTypeDef HAL_HASH_DeInit(HASH_HandleTypeDef *hhash);
void HAL_HASH_MspInit(HASH_HandleTypeDef *hhash);
void HAL_HASH_MspDeInit(HASH_HandleTypeDef *hhash);
void HAL_HASH_InCpltCallback(HASH_HandleTypeDef *hhash);
void HAL_HASH_DgstCpltCallback(HASH_HandleTypeDef *hhash);
void HAL_HASH_ErrorCallback(HASH_HandleTypeDef *hhash);
                                                                                
#if (USE_HAL_HASH_REGISTER_CALLBACKS == 1)
HAL_StatusTypeDef HAL_HASH_RegisterCallback(HASH_HandleTypeDef *hhash, HAL_HASH_CallbackIDTypeDef CallbackID,
                                            pHASH_CallbackTypeDef pCallback);
HAL_StatusTypeDef HAL_HASH_UnRegisterCallback(HASH_HandleTypeDef *hhash, HAL_HASH_CallbackIDTypeDef CallbackID);
#endif                                      


   
      
    

                                                                                        
      
    


                                                                                
HAL_StatusTypeDef HAL_HASH_SHA1_Start(HASH_HandleTypeDef *hhash, const uint8_t *const pInBuffer, uint32_t Size,
                                      uint8_t *pOutBuffer,
                                      uint32_t Timeout);
HAL_StatusTypeDef HAL_HASH_MD5_Start(HASH_HandleTypeDef *hhash, const uint8_t *const pInBuffer, uint32_t Size,
                                     uint8_t *pOutBuffer,
                                     uint32_t Timeout);
HAL_StatusTypeDef HAL_HASH_MD5_Accmlt(HASH_HandleTypeDef *hhash, const uint8_t *const pInBuffer, uint32_t Size);
HAL_StatusTypeDef HAL_HASH_SHA1_Accmlt(HASH_HandleTypeDef *hhash, const uint8_t *const pInBuffer, uint32_t Size);
HAL_StatusTypeDef HAL_HASH_MD5_Accmlt_End(HASH_HandleTypeDef *hhash, const uint8_t *const pInBuffer, uint32_t Size,
                                          uint8_t *pOutBuffer, uint32_t Timeout);
HAL_StatusTypeDef HAL_HASH_SHA1_Accmlt_End(HASH_HandleTypeDef *hhash, const uint8_t *const pInBuffer, uint32_t Size,
                                           uint8_t *pOutBuffer, uint32_t Timeout);


   
      
    

                                                                                          
      
    

                                                                                
HAL_StatusTypeDef HAL_HASH_SHA1_Start_IT(HASH_HandleTypeDef *hhash, const uint8_t *const pInBuffer, uint32_t Size,
                                         uint8_t *pOutBuffer);
HAL_StatusTypeDef HAL_HASH_SHA1_Accmlt_IT(HASH_HandleTypeDef *hhash, const uint8_t *const pInBuffer, uint32_t Size);
HAL_StatusTypeDef HAL_HASH_SHA1_Accmlt_End_IT(HASH_HandleTypeDef *hhash, const uint8_t *const pInBuffer, uint32_t Size,
                                              uint8_t *pOutBuffer);
HAL_StatusTypeDef HAL_HASH_MD5_Start_IT(HASH_HandleTypeDef *hhash, const uint8_t *const pInBuffer, uint32_t Size,
                                        uint8_t *pOutBuffer);
HAL_StatusTypeDef HAL_HASH_MD5_Accmlt_IT(HASH_HandleTypeDef *hhash, const uint8_t *const pInBuffer, uint32_t Size);
HAL_StatusTypeDef HAL_HASH_MD5_Accmlt_End_IT(HASH_HandleTypeDef *hhash, const uint8_t *const pInBuffer, uint32_t Size,
                                             uint8_t *pOutBuffer);
void HAL_HASH_IRQHandler(HASH_HandleTypeDef *hhash);
   
      
    

                                                                                    
      
    

                                                                                
HAL_StatusTypeDef HAL_HASH_SHA1_Start_DMA(HASH_HandleTypeDef *hhash, const uint8_t *const pInBuffer, uint32_t Size);
HAL_StatusTypeDef HAL_HASH_SHA1_Finish(HASH_HandleTypeDef *hhash, uint8_t *pOutBuffer, uint32_t Timeout);
HAL_StatusTypeDef HAL_HASH_MD5_Start_DMA(HASH_HandleTypeDef *hhash, const uint8_t *const pInBuffer, uint32_t Size);
HAL_StatusTypeDef HAL_HASH_MD5_Finish(HASH_HandleTypeDef *hhash, uint8_t *pOutBuffer, uint32_t Timeout);

   
      
    

                                                                                        
      
    

                                                                                
HAL_StatusTypeDef HAL_HMAC_SHA1_Start(HASH_HandleTypeDef *hhash, const uint8_t *const pInBuffer, uint32_t Size,
                                      uint8_t *pOutBuffer,
                                      uint32_t Timeout);
HAL_StatusTypeDef HAL_HMAC_MD5_Start(HASH_HandleTypeDef *hhash, const uint8_t *const pInBuffer, uint32_t Size,
                                     uint8_t *pOutBuffer,
                                     uint32_t Timeout);

   
      
    

                                                                                          
      
    

HAL_StatusTypeDef HAL_HMAC_MD5_Start_IT(HASH_HandleTypeDef *hhash, const uint8_t *const pInBuffer, uint32_t Size,
                                        uint8_t *pOutBuffer);
HAL_StatusTypeDef HAL_HMAC_SHA1_Start_IT(HASH_HandleTypeDef *hhash, const uint8_t *const pInBuffer, uint32_t Size,
                                         uint8_t *pOutBuffer);

   
      
    

                                                                                    
      
    

                                                                                
HAL_StatusTypeDef HAL_HMAC_SHA1_Start_DMA(HASH_HandleTypeDef *hhash, const uint8_t *const pInBuffer, uint32_t Size);
HAL_StatusTypeDef HAL_HMAC_MD5_Start_DMA(HASH_HandleTypeDef *hhash, const uint8_t *const pInBuffer, uint32_t Size);

   
      
    

                                                                          
      
    


                                                                                
HAL_HASH_StateTypeDef HAL_HASH_GetState(const HASH_HandleTypeDef *hhash);
HAL_StatusTypeDef HAL_HASH_GetStatus(const HASH_HandleTypeDef *hhash);
void HAL_HASH_ContextSaving(const HASH_HandleTypeDef *hhash, const uint8_t *pMemBuffer);
void HAL_HASH_ContextRestoring(HASH_HandleTypeDef *hhash, const uint8_t *pMemBuffer);
void HAL_HASH_SwFeed_ProcessSuspend(HASH_HandleTypeDef *hhash);
HAL_StatusTypeDef HAL_HASH_DMAFeed_ProcessSuspend(HASH_HandleTypeDef *hhash);
uint32_t HAL_HASH_GetError(const HASH_HandleTypeDef *hhash);

   
      
    

   
      
    

                                                                                  

                                                             
      
    

                       
HAL_StatusTypeDef HASH_Start(HASH_HandleTypeDef *hhash, const uint8_t *const pInBuffer, uint32_t Size,
                             uint8_t *pOutBuffer,
                             uint32_t Timeout, uint32_t Algorithm);
HAL_StatusTypeDef HASH_Accumulate(HASH_HandleTypeDef *hhash, const uint8_t *const pInBuffer, uint32_t Size,
                                  uint32_t Algorithm);
HAL_StatusTypeDef HASH_Accumulate_IT(HASH_HandleTypeDef *hhash, const uint8_t *const pInBuffer, uint32_t Size,
                                     uint32_t Algorithm);
HAL_StatusTypeDef HASH_Start_IT(HASH_HandleTypeDef *hhash, const uint8_t *const pInBuffer, uint32_t Size,
                                uint8_t *pOutBuffer,
                                uint32_t Algorithm);
HAL_StatusTypeDef HASH_Start_DMA(HASH_HandleTypeDef *hhash, const uint8_t *const pInBuffer, uint32_t Size,
                                 uint32_t Algorithm);
HAL_StatusTypeDef HASH_Finish(HASH_HandleTypeDef *hhash, uint8_t *pOutBuffer, uint32_t Timeout);
HAL_StatusTypeDef HMAC_Start(HASH_HandleTypeDef *hhash, const uint8_t *const pInBuffer, uint32_t Size,
                             uint8_t *pOutBuffer,
                             uint32_t Timeout, uint32_t Algorithm);
HAL_StatusTypeDef HMAC_Start_IT(HASH_HandleTypeDef *hhash, const uint8_t *const pInBuffer, uint32_t Size,
                                uint8_t *pOutBuffer,
                                uint32_t Algorithm);
HAL_StatusTypeDef HMAC_Start_DMA(HASH_HandleTypeDef *hhash, const uint8_t *const pInBuffer, uint32_t Size,
                                 uint32_t Algorithm);

   
      
    

   
      
    
#endif           
   
      
    


#ifdef __cplusplus
}
#endif


#endif                           

