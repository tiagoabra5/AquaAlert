/**
  ******************************************************************************
  * @file    stm32l4xx_hal_pssi.h
  * @author  MCD Application Team
  * @brief   Header file of PSSI HAL module.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2019 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */

                                                                                
#ifndef STM32L4xx_HAL_PSSI_H
#define STM32L4xx_HAL_PSSI_H

#ifdef __cplusplus
extern "C" {
#endif

                                                                                
#include "stm32l4xx_hal_def.h"

                                    
      
    
#if defined(PSSI)

#ifndef USE_HAL_PSSI_REGISTER_CALLBACKS
                                                                                               
#define USE_HAL_PSSI_REGISTER_CALLBACKS 0U
#endif                                      

                         
                                 
      
    

                                                                                
                                                     
      
    


   
                                         
    
typedef struct
{
  uint32_t  DataWidth;                                          
                                                                                               
  uint32_t  BusWidth;                                                   
                                                                                              
  uint32_t  ControlSignal;                                                  
                                                                                                           
  uint32_t  ClockPolarity;                                                     
                                                                                              
  uint32_t  DataEnablePolarity;                                                
                                                                                                    
  uint32_t  ReadyPolarity;                                               
                                                                                              

} PSSI_InitTypeDef;


   
                                                
    
typedef enum
{
  HAL_PSSI_STATE_RESET   = 0x00U,                                                  
  HAL_PSSI_STATE_READY   = 0x01U,                                                  
  HAL_PSSI_STATE_BUSY    = 0x02U,                                                  
  HAL_PSSI_STATE_BUSY_TX = 0x03U,                                                  
  HAL_PSSI_STATE_BUSY_RX = 0x04U,                                                  
  HAL_PSSI_STATE_TIMEOUT = 0x05U,                                                  
  HAL_PSSI_STATE_ERROR   = 0x06U,                                                  
  HAL_PSSI_STATE_ABORT   = 0x07U,                                                  

} HAL_PSSI_StateTypeDef;

   
                                            
    
#if (USE_HAL_PSSI_REGISTER_CALLBACKS == 1)
typedef struct __PSSI_HandleTypeDef
#else
typedef struct
#endif                                      
{
  PSSI_TypeDef         *Instance;                                          
  PSSI_InitTypeDef      Init;                                              
  uint32_t             *pBuffPtr;                                          
  uint32_t              XferCount;                                         
  uint32_t              XferSize;                                          
#if defined(HAL_DMA_MODULE_ENABLED)
  DMA_HandleTypeDef    *hdmatx;                                            
  DMA_HandleTypeDef    *hdmarx;                                            
#endif                           

#if (USE_HAL_PSSI_REGISTER_CALLBACKS == 1)
  void (* TxCpltCallback)(struct __PSSI_HandleTypeDef *hpssi);                                            
  void (* RxCpltCallback)(struct __PSSI_HandleTypeDef *hpssi);                                            
  void (* ErrorCallback)(struct __PSSI_HandleTypeDef *hpssi);                                             
  void (* AbortCpltCallback)(struct __PSSI_HandleTypeDef *hpssi);                                         

  void (* MspInitCallback)(struct __PSSI_HandleTypeDef *hpssi);                                           
  void (* MspDeInitCallback)(struct __PSSI_HandleTypeDef *hpssi);                                         
#endif                                      

  HAL_LockTypeDef             Lock;                                                                       
  __IO HAL_PSSI_StateTypeDef State;                                                                       
  __IO uint32_t               ErrorCode;                                                                  

} PSSI_HandleTypeDef;

#if (USE_HAL_PSSI_REGISTER_CALLBACKS == 1)
   
                                                
    
typedef  void (*pPSSI_CallbackTypeDef)(PSSI_HandleTypeDef *hpssi);                                                    

   
                                                       
    
typedef enum
{
  HAL_PSSI_TX_COMPLETE_CB_ID = 0x00U,                                                
  HAL_PSSI_RX_COMPLETE_CB_ID = 0x01U,                                                
  HAL_PSSI_ERROR_CB_ID       = 0x03U,                                                
  HAL_PSSI_ABORT_CB_ID       = 0x04U,                                                

  HAL_PSSI_MSPINIT_CB_ID     = 0x05U,                                                
  HAL_PSSI_MSPDEINIT_CB_ID   = 0x06U                                                 

} HAL_PSSI_CallbackIDTypeDef;
#endif                                      

   
      
    

                                                                                
                                                             
      
    

                                             
      
    
#define HAL_PSSI_ERROR_NONE             0x00000000U                                
#define HAL_PSSI_ERROR_NOT_SUPPORTED    0x00000001U                                
#define HAL_PSSI_ERROR_UNDER_RUN        0x00000002U                                
#define HAL_PSSI_ERROR_OVER_RUN         0x00000004U                                
#define HAL_PSSI_ERROR_DMA              0x00000008U                                
#define HAL_PSSI_ERROR_TIMEOUT          0x00000010U                                
#if (USE_HAL_PSSI_REGISTER_CALLBACKS == 1)
#define HAL_PSSI_ERROR_INVALID_CALLBACK 0x00000020U                                
#endif                                      

   
      
    

                                             
      
    

#define HAL_PSSI_8BITS                  0x00000000U                   
#define HAL_PSSI_16BITS                 0x00000001U                   
#define HAL_PSSI_32BITS                 0x00000002U                   
   
      
    

                                           
      
    

#define HAL_PSSI_8LINES                 0x00000000U                        
#define HAL_PSSI_16LINES                PSSI_CR_EDM                        
   
      
    
                                 
      
    
#define HAL_PSSI_UNIDIRECTIONAL         0x00000000U                             
#define HAL_PSSI_BIDIRECTIONAL          0x00000001U                             
   
      
    

                                                                     
      
    
#define HAL_PSSI_DE_RDY_DISABLE           (0x0U << PSSI_CR_DERDYCFG_Pos)                                       
#define HAL_PSSI_RDY_ENABLE               (0x1U << PSSI_CR_DERDYCFG_Pos)                         
#define HAL_PSSI_DE_ENABLE                (0x2U << PSSI_CR_DERDYCFG_Pos)                        
#define HAL_PSSI_DE_RDY_ALT_ENABLE        (0x3U << PSSI_CR_DERDYCFG_Pos)                                                    
#define HAL_PSSI_MAP_RDY_BIDIR_ENABLE     (0x4U << PSSI_CR_DERDYCFG_Pos)                                  
#define HAL_PSSI_RDY_MAP_ENABLE           (0x5U << PSSI_CR_DERDYCFG_Pos)                                           
#define HAL_PSSI_DE_MAP_ENABLE            (0x6U << PSSI_CR_DERDYCFG_Pos)                                           
#define HAL_PSSI_MAP_DE_BIDIR_ENABLE      (0x7U << PSSI_CR_DERDYCFG_Pos)                                 

   
      
    


                                                       
      
    
#define HAL_PSSI_DEPOL_ACTIVE_LOW         0x0U                              
#define HAL_PSSI_DEPOL_ACTIVE_HIGH        PSSI_CR_DEPOL                      
   
      
    
                                           
      
    
#define HAL_PSSI_RDYPOL_ACTIVE_LOW        0x0U                              
#define HAL_PSSI_RDYPOL_ACTIVE_HIGH       PSSI_CR_RDYPOL                     
   
      
    

                                           
      
    
#define HAL_PSSI_FALLING_EDGE             0x0U                                 
#define HAL_PSSI_RISING_EDGE              0x1U                               
   
      
    


                                              
      
    

#define PSSI_MAX_NBYTE_SIZE         0x10000U                    
#define PSSI_TIMEOUT_TRANSMIT       0x0000FFFFU                             

#define PSSI_CR_OUTEN_INPUT         0x00000000U                             
#define PSSI_CR_OUTEN_OUTPUT        PSSI_CR_OUTEN                           

#define PSSI_CR_DMA_ENABLE          PSSI_CR_DMAEN                           
#define PSSI_CR_DMA_DISABLE         (~PSSI_CR_DMAEN)                        

#define PSSI_CR_16BITS              PSSI_CR_EDM                             
#define PSSI_CR_8BITS               (~PSSI_CR_EDM)                          

#define PSSI_FLAG_RTT1B             PSSI_SR_RTT1B                            
#define PSSI_FLAG_RTT4B             PSSI_SR_RTT4B                            



   
      
    

                                             
      
    

#define PSSI_FLAG_OVR_RIS            PSSI_RIS_OVR_RIS                                          
#define PSSI_FLAG_MASK               PSSI_RIS_OVR_RIS_Msk                                      
#define PSSI_FLAG_OVR_MIS            PSSI_MIS_OVR_MIS                                                 
   
      
    



   
      
    
                                                                                 
                                                       
      
    

                                  
                                                 
                
    
#if (USE_HAL_PSSI_REGISTER_CALLBACKS == 1)
#define HAL_PSSI_RESET_HANDLE_STATE(__HANDLE__) do{                                            \
                                                      (__HANDLE__)->State = HAL_PSSI_STATE_RESET;\
                                                      (__HANDLE__)->MspInitCallback = NULL;       \
                                                      (__HANDLE__)->MspDeInitCallback = NULL;     \
                                                     }while(0)
#else
#define HAL_PSSI_RESET_HANDLE_STATE(__HANDLE__) ((__HANDLE__)->State = HAL_PSSI_STATE_RESET)
#endif                                      


   
                            
                                  
                 
    
#define HAL_PSSI_ENABLE(__HANDLE__)        ((__HANDLE__)->Instance->CR |= PSSI_CR_ENABLE)
   
                             
                                  
                 
    
#define HAL_PSSI_DISABLE(__HANDLE__)        ((__HANDLE__)->Instance->CR &= (~PSSI_CR_ENABLE))

                           
   
                                       
                                  
                                   
                                                                           
                                                                        
                                                                         
                              
    

#define HAL_PSSI_GET_STATUS(__HANDLE__, __FLAG__) ((__HANDLE__)->Instance->SR & (__FLAG__))



                                 
   
                                       
                                  
                                   
                                                                           
                                                                              
                              
    
#define HAL_PSSI_GET_FLAG(__HANDLE__, __FLAG__) ((__HANDLE__)->Instance->RIS & (__FLAG__))

   
                                         
                                  
                                                 
                                                                           
                                                                              
                
    
#define HAL_PSSI_CLEAR_FLAG(__HANDLE__, __FLAG__) ((__HANDLE__)->Instance->ICR = (__FLAG__))

   
                                                 
                                  
                                                                            
                                                                           
                                                               
                
    
#define HAL_PSSI_ENABLE_IT(__HANDLE__, __INTERRUPT__) ((__HANDLE__)->Instance->IER |= (__INTERRUPT__))

   
                                                  
                                  
                                                                             
                                                                           
                                                            
                
    
#define HAL_PSSI_DISABLE_IT(__HANDLE__, __INTERRUPT__) ((__HANDLE__)->Instance->IER &= ~(__INTERRUPT__))

   
                                                                                
                                  
                                                                       
                                                               
                                                                                     
                                          
    
#define HAL_PSSI_GET_IT_SOURCE(__HANDLE__, __INTERRUPT__) ((__HANDLE__)->Instance->IER & (__INTERRUPT__))


   
                                                           
                                                     
                         
    

#define IS_PSSI_CONTROL_SIGNAL(__CONTROL__) (((__CONTROL__) == HAL_PSSI_DE_RDY_DISABLE        ) || \
                                             ((__CONTROL__) == HAL_PSSI_RDY_ENABLE            ) || \
                                             ((__CONTROL__) == HAL_PSSI_DE_ENABLE             ) || \
                                             ((__CONTROL__) == HAL_PSSI_DE_RDY_ALT_ENABLE     ) || \
                                             ((__CONTROL__) == HAL_PSSI_MAP_RDY_BIDIR_ENABLE  ) || \
                                             ((__CONTROL__) == HAL_PSSI_RDY_MAP_ENABLE        ) || \
                                             ((__CONTROL__) == HAL_PSSI_DE_MAP_ENABLE         ) || \
                                             ((__CONTROL__) == HAL_PSSI_MAP_DE_BIDIR_ENABLE   ))



   
                                                      
                                        
                         
    

#define IS_PSSI_BUSWIDTH(__BUSWIDTH__) (((__BUSWIDTH__) == HAL_PSSI_8LINES    ) || \
                                        ((__BUSWIDTH__) == HAL_PSSI_16LINES   ))

   

                                                           
                                            
                         
    

#define IS_PSSI_CLOCK_POLARITY(__CLOCKPOL__) (((__CLOCKPOL__) == HAL_PSSI_FALLING_EDGE   ) || \
                                              ((__CLOCKPOL__) == HAL_PSSI_RISING_EDGE    ))


   
                                                                 
                                      
                         
    

#define IS_PSSI_DE_POLARITY(__DEPOL__) (((__DEPOL__) == HAL_PSSI_DEPOL_ACTIVE_LOW    ) || \
                                        ((__DEPOL__) == HAL_PSSI_DEPOL_ACTIVE_HIGH   ))

   
                                                           
                                        
                         
    

#define IS_PSSI_RDY_POLARITY(__RDYPOL__) (((__RDYPOL__) == HAL_PSSI_RDYPOL_ACTIVE_LOW   ) || \
                                          ((__RDYPOL__) == HAL_PSSI_RDYPOL_ACTIVE_HIGH   ))

   
      
    


                                                                                
                                                               
      
    

                                                                                             
      
    

                                                                                  
HAL_StatusTypeDef HAL_PSSI_Init(PSSI_HandleTypeDef *hpssi);
HAL_StatusTypeDef HAL_PSSI_DeInit(PSSI_HandleTypeDef *hpssi);
void              HAL_PSSI_MspInit(PSSI_HandleTypeDef *hpssi);
void              HAL_PSSI_MspDeInit(PSSI_HandleTypeDef *hpssi);
                                                                                
#if (USE_HAL_PSSI_REGISTER_CALLBACKS == 1)
HAL_StatusTypeDef HAL_PSSI_RegisterCallback(PSSI_HandleTypeDef *hpssi, HAL_PSSI_CallbackIDTypeDef CallbackID,
                                            pPSSI_CallbackTypeDef pCallback);
HAL_StatusTypeDef HAL_PSSI_UnRegisterCallback(PSSI_HandleTypeDef *hpssi, HAL_PSSI_CallbackIDTypeDef CallbackID);
#endif                                      

   
      
    


                                                                                   
      
    

                                                                                  
HAL_StatusTypeDef HAL_PSSI_Transmit(PSSI_HandleTypeDef *hpssi, uint8_t *pData, uint32_t Size, uint32_t Timeout);
HAL_StatusTypeDef HAL_PSSI_Receive(PSSI_HandleTypeDef *hpssi, uint8_t *pData, uint32_t Size, uint32_t Timeout);
#if defined(HAL_DMA_MODULE_ENABLED)
HAL_StatusTypeDef HAL_PSSI_Transmit_DMA(PSSI_HandleTypeDef *hpssi, uint32_t *pData, uint32_t Size);
HAL_StatusTypeDef HAL_PSSI_Receive_DMA(PSSI_HandleTypeDef *hpssi, uint32_t *pData, uint32_t Size);
HAL_StatusTypeDef HAL_PSSI_Abort_DMA(PSSI_HandleTypeDef *hpssi);
#endif                           

   
      
    

                                                                                   
      
    

                                                                                  
HAL_PSSI_StateTypeDef HAL_PSSI_GetState(const PSSI_HandleTypeDef *hpssi);
uint32_t              HAL_PSSI_GetError(const PSSI_HandleTypeDef *hpssi);

   
      
    

                                                                        
      
    

void HAL_PSSI_IRQHandler(PSSI_HandleTypeDef *hpssi);
void HAL_PSSI_TxCpltCallback(PSSI_HandleTypeDef *hpssi);
void HAL_PSSI_RxCpltCallback(PSSI_HandleTypeDef *hpssi);
void HAL_PSSI_ErrorCallback(PSSI_HandleTypeDef *hpssi);
void HAL_PSSI_AbortCpltCallback(PSSI_HandleTypeDef *hpssi);

   
      
    



   
      
    

                                                                                


                                                                                


   
      
    
#endif           

   
      
    


#ifdef __cplusplus
}
#endif

#endif                           

