/**
  ******************************************************************************
  * @file    stm32l4xx_hal_cryp.h
  * @author  MCD Application Team
  * @brief   Header file of CRYP HAL module.
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

                                                                                
#ifndef STM32L4xx_HAL_CRYP_H
#define STM32L4xx_HAL_CRYP_H

#ifdef __cplusplus
 extern "C" {
#endif

                                                                                
#include "stm32l4xx_hal_def.h"

                                    
      
    

#if defined(AES)
  
                    
      
    

                                                                                
                                                     
      
    

   
                                                   
    
typedef struct
{
  uint32_t DataType;                                                                 
                                                                                    

  uint32_t KeySize;                                       
                                                                                   

  uint32_t OperatingMode;                          
                                                                                            

  uint32_t ChainingMode;                          
                                                                                           

  uint32_t KeyWriteFlag;                                                               
                                                                                    

  uint32_t GCMCMACPhase;                                                                        
                                                                                      
                                                                                                
                                                          
                                                                                         

  uint8_t* pKey;                                            

  uint8_t* pInitVect;                                                                                    
                                                                  

  uint8_t* Header;                                                                                                

  uint64_t HeaderSize;                                 

}CRYP_InitTypeDef;

   
                                               
    
typedef enum
{
  HAL_CRYP_STATE_RESET             = 0x00,                                               
  HAL_CRYP_STATE_READY             = 0x01,                                               
  HAL_CRYP_STATE_BUSY              = 0x02,                                               
  HAL_CRYP_STATE_TIMEOUT           = 0x03,                                               
  HAL_CRYP_STATE_ERROR             = 0x04,                                               
  HAL_CRYP_STATE_SUSPENDED         = 0x05                                                
}HAL_CRYP_STATETypeDef;

   
                                               
    
typedef enum
{
  HAL_CRYP_PHASE_READY             = 0x01,                                                                    
  HAL_CRYP_PHASE_PROCESS           = 0x02,                                                                    
  HAL_CRYP_PHASE_START             = 0x03,                                                 
                                                                                                              
  HAL_CRYP_PHASE_INIT_OVER         = 0x04,                                                                    
  HAL_CRYP_PHASE_HEADER_OVER       = 0x05,                                                                    
  HAL_CRYP_PHASE_PAYLOAD_OVER      = 0x06,                                                                    
  HAL_CRYP_PHASE_FINAL_OVER        = 0x07,                                                                    
  HAL_CRYP_PHASE_HEADER_SUSPENDED  = 0x08,                                                                    
  HAL_CRYP_PHASE_PAYLOAD_SUSPENDED = 0x09,                                                                    
  HAL_CRYP_PHASE_NOT_USED          = 0x0a                                                                     
}HAL_PhaseTypeDef;

   
                                            
    
typedef enum
{
  HAL_CRYP_SUSPEND_NONE            = 0x00,                                                    
  HAL_CRYP_SUSPEND                 = 0x01                                                     
}HAL_SuspendTypeDef;


   
                                           
    
#define HAL_CRYP_ERROR_NONE      ((uint32_t)0x00000000)                         
#define HAL_CRYP_WRITE_ERROR     ((uint32_t)0x00000001)                         
#define HAL_CRYP_READ_ERROR      ((uint32_t)0x00000002)                         
#define HAL_CRYP_DMA_ERROR       ((uint32_t)0x00000004)                         
#define HAL_CRYP_BUSY_ERROR      ((uint32_t)0x00000008)                         
#if (USE_HAL_CRYP_REGISTER_CALLBACKS == 1)
#define  HAL_CRYP_ERROR_INVALID_CALLBACK ((uint32_t)0x00000010U)                                  
#endif                                      

#if (USE_HAL_CRYP_REGISTER_CALLBACKS == 1)
   
                                                              
    
typedef enum
{
  HAL_CRYP_INPUTCPLT_CB_ID         = 0x01U,                                                           
  HAL_CRYP_OUTPUTCPLT_CB_ID        = 0x02U,                                                           
  HAL_CRYP_COMPCPLT_CB_ID          = 0x03U,                                                           
  HAL_CRYP_ERROR_CB_ID             = 0x04U,                                                           
  HAL_CRYP_MSPINIT_CB_ID           = 0x05U,                                                           
  HAL_CRYP_MSPDEINIT_CB_ID         = 0x06U,                                                           
}HAL_CRYP_CallbackIDTypeDef;
#endif                                      

   
                                            
    
#if (USE_HAL_CRYP_REGISTER_CALLBACKS == 1)
typedef struct __CRYP_HandleTypeDef
#else
typedef struct
#endif                                      
{
      AES_TypeDef              *Instance;                                            

      CRYP_InitTypeDef         Init;                                                   

      uint8_t                  *pCrypInBuffPtr;                                                                              

      uint8_t                  *pCrypOutBuffPtr;                                                                              

      uint32_t                 CrypInCount;                                                                       
                                                                                    

      uint32_t                 CrypOutCount;                                      

      HAL_PhaseTypeDef         Phase;                                                                                       
                                                                                     
                                                                                                  
                                                                           

      DMA_HandleTypeDef        *hdmain;                                                             

      DMA_HandleTypeDef        *hdmaout;                                                             

      HAL_LockTypeDef          Lock;                                        

   __IO  HAL_CRYP_STATETypeDef State;                                         

    __IO uint32_t              ErrorCode;                                          

     HAL_SuspendTypeDef        SuspendRequest;                                                  

#if (USE_HAL_CRYP_REGISTER_CALLBACKS == 1)
  void    (* InCpltCallback)( struct __CRYP_HandleTypeDef * hcryp);                                                       

  void    (* OutCpltCallback)( struct __CRYP_HandleTypeDef * hcryp);                                                       

  void    (* CompCpltCallback)( struct __CRYP_HandleTypeDef * hcryp);                                              

  void    (* ErrorCallback)( struct __CRYP_HandleTypeDef * hcryp);                                

  void    (* MspInitCallback)( struct __CRYP_HandleTypeDef * hcryp);                                 

  void    (* MspDeInitCallback)( struct __CRYP_HandleTypeDef * hcryp);                                 

#endif                                        
}CRYP_HandleTypeDef;


#if (USE_HAL_CRYP_REGISTER_CALLBACKS == 1)
   
                                                
    
typedef  void (*pCRYP_CallbackTypeDef)(CRYP_HandleTypeDef * hcryp);                                                    
#endif                                      
   
      
    


                                                                                
                                                             
      
    

                                               
      
    
#define CRYP_KEYSIZE_128B         ((uint32_t)0x00000000)                          
#define CRYP_KEYSIZE_256B         AES_CR_KEYSIZE                                  
   
      
    

                                                     
      
    
#define CRYP_DATATYPE_32B         ((uint32_t)0x00000000)                                               
#define CRYP_DATATYPE_16B         AES_CR_DATATYPE_0                                                    
#define CRYP_DATATYPE_8B          AES_CR_DATATYPE_1                                                    
#define CRYP_DATATYPE_1B          AES_CR_DATATYPE                                                      
   
      
    

                                               
      
    
#define CRYP_AES_DISABLE                 ((uint32_t)0x00000000)                      
#define CRYP_AES_ENABLE                   AES_CR_EN                                  
   
      
    

                                                       
      
    
#define CRYP_ALGOMODE_ENCRYPT                   ((uint32_t)0x00000000)                                                                      
#define CRYP_ALGOMODE_KEYDERIVATION             AES_CR_MODE_0                                                                               
#define CRYP_ALGOMODE_DECRYPT                   AES_CR_MODE_1                                                                               
#define CRYP_ALGOMODE_KEYDERIVATION_DECRYPT     AES_CR_MODE                                                                                 
#define CRYP_ALGOMODE_TAG_GENERATION            ((uint32_t)0x00000000)                                                                      
   
      
    

                                                     
      
    
#define CRYP_CHAINMODE_AES_ECB            ((uint32_t)0x00000000)                                                                            
#define CRYP_CHAINMODE_AES_CBC            AES_CR_CHMOD_0                                                                                    
#define CRYP_CHAINMODE_AES_CTR            AES_CR_CHMOD_1                                                                                    
#define CRYP_CHAINMODE_AES_GCM_GMAC       (AES_CR_CHMOD_0 | AES_CR_CHMOD_1)                                                                 
#if defined(AES_CR_NPBLB)
#define CRYP_CHAINMODE_AES_CCM            AES_CR_CHMOD_2                                                                                    
#else
#define CRYP_CHAINMODE_AES_CMAC           AES_CR_CHMOD_2                                                                                    
#endif
   
      
    

                                                             
      
    
#define CRYP_KEY_WRITE_ENABLE            ((uint32_t)0x00000000)                                        
#define CRYP_KEY_WRITE_DISABLE           ((uint32_t)0x00000001)                                        
   
      
    

                                                                
      
    
#define CRYP_DMAIN_DISABLE             ((uint32_t)0x00000000)                                              
#define CRYP_DMAIN_ENABLE              AES_CR_DMAINEN                                                      
   
      
    

                                                                  
      
    
#define CRYP_DMAOUT_DISABLE             ((uint32_t)0x00000000)                                              
#define CRYP_DMAOUT_ENABLE              AES_CR_DMAOUTEN                                                     
   
      
    


                                                                                                    
      
    
#define CRYP_GCM_INIT_PHASE             ((uint32_t)0x00000000)                                        
#define CRYP_GCMCMAC_HEADER_PHASE       AES_CR_GCMPH_0                                                
#define CRYP_GCM_PAYLOAD_PHASE          AES_CR_GCMPH_1                                                
#define CRYP_GCMCMAC_FINAL_PHASE        AES_CR_GCMPH                                                  
                                                       
                                                                             
#define CRYP_INIT_PHASE                 ((uint32_t)0x00000000)                       
#define CRYP_HEADER_PHASE               AES_CR_GCMPH_0                               
#define CRYP_PAYLOAD_PHASE              AES_CR_GCMPH_1                               
#define CRYP_FINAL_PHASE                AES_CR_GCMPH                                 
   
      
    

                                           
      
    

#define CRYP_FLAG_BUSY    AES_SR_BUSY                                           
#define CRYP_FLAG_WRERR   AES_SR_WRERR                                          
#define CRYP_FLAG_RDERR   AES_SR_RDERR                                          
#define CRYP_FLAG_CCF     AES_SR_CCF                                            
   
      
    

                                                   
      
    

#define CRYP_CCF_CLEAR    AES_CR_CCFC                                          
#define CRYP_ERR_CLEAR    AES_CR_ERRC                                          
   
      
    

                                                              
      
    
#define CRYP_IT_CCFIE                         AES_CR_CCFIE                                              
#define CRYP_IT_ERRIE                         AES_CR_ERRIE                                              
   
      
    

                                                          
      
    
#define CRYP_IT_WRERR   AES_SR_WRERR                               
#define CRYP_IT_RDERR   AES_SR_RDERR                               
#define CRYP_IT_CCF     AES_SR_CCF                                 
   
      
    

   
      
    

                                                                                
                                                       
      
    

                                   
                                                 
                
    
#if (USE_HAL_CRYP_REGISTER_CALLBACKS == 1)
#define __HAL_CRYP_RESET_HANDLE_STATE(__HANDLE__) do{\
                                                      (__HANDLE__)->State = HAL_CRYP_STATE_RESET;\
                                                      (__HANDLE__)->MspInitCallback = NULL;      \
                                                      (__HANDLE__)->MspDeInitCallback = NULL;    \
                                                     }while(0)
#else
#define __HAL_CRYP_RESET_HANDLE_STATE(__HANDLE__) ((__HANDLE__)->State = HAL_CRYP_STATE_RESET)
#endif                                      

   
                                           
                                                 
                
    
#define __HAL_CRYP_ENABLE(__HANDLE__)  ((__HANDLE__)->Instance->CR |=  AES_CR_EN)

   
                                            
                                                 
                
    
#define __HAL_CRYP_DISABLE(__HANDLE__) ((__HANDLE__)->Instance->CR &=  ~AES_CR_EN)

   
                                             
                                                 
                                                           
                                                               
                                                         
                                                                   
                                                         
                                                                                          
                
    
#define __HAL_CRYP_SET_OPERATINGMODE(__HANDLE__, __OPERATING_MODE__) MODIFY_REG((__HANDLE__)->Instance->CR, AES_CR_MODE, (__OPERATING_MODE__))


   
                                            
                                                 
                                                         
                                                               
                                                                   
                                                                     
                                                            
                                                                                                              
                                                                                                                                 
                
    
#define __HAL_CRYP_SET_CHAININGMODE(__HANDLE__, __CHAINING_MODE__) MODIFY_REG((__HANDLE__)->Instance->CR, AES_CR_CHMOD, (__CHAINING_MODE__))



                                                                       
                                                 
                                                 
                                                              
                                                                        
                                                  
                                                 
                                                         
                                                  
    
#define __HAL_CRYP_GET_FLAG(__HANDLE__, __FLAG__) (((__HANDLE__)->Instance->SR & (__FLAG__)) == (__FLAG__))


                                               
                                                 
                                                 
                                                              
                                                                                      
                                                                             
                
    
#define __HAL_CRYP_CLEAR_FLAG(__HANDLE__, __FLAG__) SET_BIT((__HANDLE__)->Instance->CR, (__FLAG__))



                                                                                
                                                 
                                                       
                                                              
                                                                                 
                                                                     
                                                  
    
#define __HAL_CRYP_GET_IT_SOURCE(__HANDLE__, __INTERRUPT__) (((__HANDLE__)->Instance->CR & (__INTERRUPT__)) == (__INTERRUPT__))


                                                                     
                                                 
                                                           
                                                              
                                                  
                                                 
                                                          
                                                       
    
#define __HAL_CRYP_GET_IT(__HANDLE__, __INTERRUPT__) (((__HANDLE__)->Instance->SR & (__INTERRUPT__)) == (__INTERRUPT__))



                                             
                                                 
                                                    
                                                              
                                                                                      
                                                                             
                
    
#define __HAL_CRYP_CLEAR_IT(__HANDLE__, __INTERRUPT__) SET_BIT((__HANDLE__)->Instance->CR, (__INTERRUPT__))


   
                                      
                                                 
                                         
                                                              
                                                                                 
                                                                     
                
    
#define __HAL_CRYP_ENABLE_IT(__HANDLE__, __INTERRUPT__) (((__HANDLE__)->Instance->CR) |= (__INTERRUPT__))


   
                                       
                                                 
                                         
                                                              
                                                                                 
                                                                     
                
    
#define __HAL_CRYP_DISABLE_IT(__HANDLE__, __INTERRUPT__) (((__HANDLE__)->Instance->CR) &= ~(__INTERRUPT__))

   
      
    

                                                                            
                                                          
      
    

   
                                      
                                                                
                                                                                
    
#define IS_CRYP_KEYSIZE(__KEYSIZE__)  (((__KEYSIZE__) == CRYP_KEYSIZE_128B)  || \
                                       ((__KEYSIZE__) == CRYP_KEYSIZE_256B))

   
                                      
                                                                        
                                                                          
    
#define IS_CRYP_DATATYPE(__DATATYPE__) (((__DATATYPE__) == CRYP_DATATYPE_32B) || \
                                        ((__DATATYPE__) == CRYP_DATATYPE_16B) || \
                                        ((__DATATYPE__) == CRYP_DATATYPE_8B)  || \
                                        ((__DATATYPE__) == CRYP_DATATYPE_1B))

   
                                               
                                             
                                                                  
    
#define IS_CRYP_AES(__MODE__) (((__MODE__) == CRYP_AES_DISABLE) || \
                               ((__MODE__) == CRYP_AES_ENABLE))

   
                                              
                                                                                                                        
                                                                          
    
#define IS_CRYP_ALGOMODE(__ALGOMODE__) (((__ALGOMODE__) == CRYP_ALGOMODE_ENCRYPT)        || \
                                        ((__ALGOMODE__) == CRYP_ALGOMODE_KEYDERIVATION)  || \
                                        ((__ALGOMODE__) == CRYP_ALGOMODE_DECRYPT)        || \
                                        ((__ALGOMODE__) == CRYP_ALGOMODE_TAG_GENERATION) || \
                                        ((__ALGOMODE__) == CRYP_ALGOMODE_KEYDERIVATION_DECRYPT))

   
                                                       
                                                          
                                                                            
    
#if defined(AES_CR_NPBLB)
#define IS_CRYP_CHAINMODE(__CHAINMODE__) (((__CHAINMODE__) == CRYP_CHAINMODE_AES_ECB)     || \
                                         ((__CHAINMODE__) == CRYP_CHAINMODE_AES_CBC)      || \
                                         ((__CHAINMODE__) == CRYP_CHAINMODE_AES_CTR)      || \
                                         ((__CHAINMODE__) == CRYP_CHAINMODE_AES_GCM_GMAC) || \
                                         ((__CHAINMODE__) == CRYP_CHAINMODE_AES_CCM))
#else
#define IS_CRYP_CHAINMODE(__CHAINMODE__) (((__CHAINMODE__) == CRYP_CHAINMODE_AES_ECB)     || \
                                         ((__CHAINMODE__) == CRYP_CHAINMODE_AES_CBC)      || \
                                         ((__CHAINMODE__) == CRYP_CHAINMODE_AES_CTR)      || \
                                         ((__CHAINMODE__) == CRYP_CHAINMODE_AES_GCM_GMAC) || \
                                         ((__CHAINMODE__) == CRYP_CHAINMODE_AES_CMAC))
#endif

   
                                                   
                                                  
                                                                    
    
#define IS_CRYP_WRITE(__WRITE__)   (((__WRITE__) == CRYP_KEY_WRITE_ENABLE)      || \
                                    ((__WRITE__) == CRYP_KEY_WRITE_DISABLE))

   
                                               
                                             
                                                                  
    
#define IS_CRYP_DMAIN(__MODE__) (((__MODE__) == CRYP_DMAIN_DISABLE) || \
                                 ((__MODE__) == CRYP_DMAIN_ENABLE))

   
                                                
                                              
                                                                  
    
#define IS_CRYP_DMAOUT(__MODE__) (((__MODE__) == CRYP_DMAOUT_DISABLE) || \
                                  ((__MODE__) == CRYP_DMAOUT_ENABLE))

   
                                                                                    
                                                                                   
                                                                    
    
#define IS_CRYP_GCMCMAC_PHASE(__PHASE__) (((__PHASE__) == CRYP_INIT_PHASE)    || \
                                          ((__PHASE__) == CRYP_HEADER_PHASE)  || \
                                          ((__PHASE__) == CRYP_PAYLOAD_PHASE) || \
                                          ((__PHASE__) == CRYP_FINAL_PHASE))

   
      
    

                                      
#include "stm32l4xx_hal_cryp_ex.h"

                                                                                
                                                               
      
    

                                                                                            
      
    

                                                                                
HAL_StatusTypeDef HAL_CRYP_Init(CRYP_HandleTypeDef *hcryp);
HAL_StatusTypeDef HAL_CRYP_DeInit(CRYP_HandleTypeDef *hcryp);

                                                                                
void HAL_CRYP_MspInit(CRYP_HandleTypeDef *hcryp);
void HAL_CRYP_MspDeInit(CRYP_HandleTypeDef *hcryp);

   
      
    

                                                                       
      
    

                                                                                

                                                                                
HAL_StatusTypeDef     HAL_CRYP_AESECB_Encrypt(CRYP_HandleTypeDef *hcryp, uint8_t *pPlainData, uint16_t Size, uint8_t *pCypherData, uint32_t Timeout);
HAL_StatusTypeDef     HAL_CRYP_AESECB_Decrypt(CRYP_HandleTypeDef *hcryp, uint8_t *pCypherData, uint16_t Size, uint8_t *pPlainData, uint32_t Timeout);
HAL_StatusTypeDef     HAL_CRYP_AESCBC_Encrypt(CRYP_HandleTypeDef *hcryp, uint8_t *pPlainData, uint16_t Size, uint8_t *pCypherData, uint32_t Timeout);
HAL_StatusTypeDef     HAL_CRYP_AESCBC_Decrypt(CRYP_HandleTypeDef *hcryp, uint8_t *pCypherData, uint16_t Size, uint8_t *pPlainData, uint32_t Timeout);
HAL_StatusTypeDef     HAL_CRYP_AESCTR_Encrypt(CRYP_HandleTypeDef *hcryp, uint8_t *pPlainData, uint16_t Size, uint8_t *pCypherData, uint32_t Timeout);
HAL_StatusTypeDef     HAL_CRYP_AESCTR_Decrypt(CRYP_HandleTypeDef *hcryp, uint8_t *pCypherData, uint16_t Size, uint8_t *pPlainData, uint32_t Timeout);

                                                                                
HAL_StatusTypeDef     HAL_CRYP_AESECB_Encrypt_IT(CRYP_HandleTypeDef *hcryp, uint8_t *pPlainData, uint16_t Size, uint8_t *pCypherData);
HAL_StatusTypeDef     HAL_CRYP_AESCBC_Encrypt_IT(CRYP_HandleTypeDef *hcryp, uint8_t *pPlainData, uint16_t Size, uint8_t *pCypherData);
HAL_StatusTypeDef     HAL_CRYP_AESCTR_Encrypt_IT(CRYP_HandleTypeDef *hcryp, uint8_t *pPlainData, uint16_t Size, uint8_t *pCypherData);
HAL_StatusTypeDef     HAL_CRYP_AESECB_Decrypt_IT(CRYP_HandleTypeDef *hcryp, uint8_t *pCypherData, uint16_t Size, uint8_t *pPlainData);
HAL_StatusTypeDef     HAL_CRYP_AESCTR_Decrypt_IT(CRYP_HandleTypeDef *hcryp, uint8_t *pCypherData, uint16_t Size, uint8_t *pPlainData);
HAL_StatusTypeDef     HAL_CRYP_AESCBC_Decrypt_IT(CRYP_HandleTypeDef *hcryp, uint8_t *pCypherData, uint16_t Size, uint8_t *pPlainData);

                                                                                
HAL_StatusTypeDef     HAL_CRYP_AESECB_Encrypt_DMA(CRYP_HandleTypeDef *hcryp, uint8_t *pPlainData, uint16_t Size, uint8_t *pCypherData);
HAL_StatusTypeDef     HAL_CRYP_AESECB_Decrypt_DMA(CRYP_HandleTypeDef *hcryp, uint8_t *pCypherData, uint16_t Size, uint8_t *pPlainData);
HAL_StatusTypeDef     HAL_CRYP_AESCBC_Encrypt_DMA(CRYP_HandleTypeDef *hcryp, uint8_t *pPlainData, uint16_t Size, uint8_t *pCypherData);
HAL_StatusTypeDef     HAL_CRYP_AESCBC_Decrypt_DMA(CRYP_HandleTypeDef *hcryp, uint8_t *pCypherData, uint16_t Size, uint8_t *pPlainData);
HAL_StatusTypeDef     HAL_CRYP_AESCTR_Encrypt_DMA(CRYP_HandleTypeDef *hcryp, uint8_t *pPlainData, uint16_t Size, uint8_t *pCypherData);
HAL_StatusTypeDef     HAL_CRYP_AESCTR_Decrypt_DMA(CRYP_HandleTypeDef *hcryp, uint8_t *pCypherData, uint16_t Size, uint8_t *pPlainData);

   
      
    

                                                                 
      
    
                                                                                
void HAL_CRYP_InCpltCallback(CRYP_HandleTypeDef *hcryp);
void HAL_CRYP_OutCpltCallback(CRYP_HandleTypeDef *hcryp);
void HAL_CRYP_ErrorCallback(CRYP_HandleTypeDef *hcryp);
                                                                                
#if (USE_HAL_CRYP_REGISTER_CALLBACKS == 1)
HAL_StatusTypeDef HAL_CRYP_RegisterCallback(CRYP_HandleTypeDef *hcryp, HAL_CRYP_CallbackIDTypeDef CallbackID, pCRYP_CallbackTypeDef pCallback);
HAL_StatusTypeDef HAL_CRYP_UnRegisterCallback(CRYP_HandleTypeDef *hcryp, HAL_CRYP_CallbackIDTypeDef CallbackID);
#endif                                      

   
      
    

                                                               
      
    

                                                                                
void HAL_CRYP_IRQHandler(CRYP_HandleTypeDef *hcryp);

   
      
    

                                                                         
      
    

                                                                                
HAL_CRYP_STATETypeDef HAL_CRYP_GetState(const CRYP_HandleTypeDef *hcryp);
uint32_t              HAL_CRYP_GetError(const CRYP_HandleTypeDef *hcryp);

   
      
    

   
      
    

   
      
    

#endif          

   
      
    
  
#ifdef __cplusplus
}
#endif

#endif                           
