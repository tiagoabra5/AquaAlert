/**
  ******************************************************************************
  * @file    stm32l4xx_hal_can.h
  * @author  MCD Application Team
  * @brief   Header file of CAN HAL module.
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

                                                                                
#ifndef STM32L4xx_HAL_CAN_H
#define STM32L4xx_HAL_CAN_H

#ifdef __cplusplus
extern "C" {
#endif

                                                                                
#include "stm32l4xx_hal_def.h"

                                    
      
    

#if defined (CAN1)
                   
      
    

                                                                                
                                                   
      
    
   
                                           
    
typedef enum
{
  HAL_CAN_STATE_RESET             = 0x00U,                                             
  HAL_CAN_STATE_READY             = 0x01U,                                             
  HAL_CAN_STATE_LISTENING         = 0x02U,                                             
  HAL_CAN_STATE_SLEEP_PENDING     = 0x03U,                                             
  HAL_CAN_STATE_SLEEP_ACTIVE      = 0x04U,                                             
  HAL_CAN_STATE_ERROR             = 0x05U                                              

} HAL_CAN_StateTypeDef;

   
                                         
    
typedef struct
{
  uint32_t Prescaler;                                                              
                                                                                                                        

  uint32_t Mode;                                                             
                                                                                                       

  uint32_t SyncJumpWidth;                                                                               
                                                                                                                 
                                                                                                                   

  uint32_t TimeSeg1;                                                                             
                                                                                                                      

  uint32_t TimeSeg2;                                                                             
                                                                                                                      

  FunctionalState TimeTriggeredMode;                                                                
                                                                                              

  FunctionalState AutoBusOff;                                                                  
                                                                                              

  FunctionalState AutoWakeUp;                                                            
                                                                                              

  FunctionalState AutoRetransmission;                                                               
                                                                                              

  FunctionalState ReceiveFifoLocked;                                                       
                                                                                              

  FunctionalState TransmitFifoPriority;                                                  
                                                                                              

} CAN_InitTypeDef;

   
                                                         
    
typedef struct
{
  uint32_t FilterIdHigh;                                                                            
                                                                                            
                                                                              
                                                                                  

  uint32_t FilterIdLow;                                                                             
                                                                                             
                                                                              
                                                                                  

  uint32_t FilterMaskIdHigh;                                                                     
                                                                                              
                                                                             
                                                                              
                                                                                  

  uint32_t FilterMaskIdLow;                                                                      
                                                                                              
                                                                              
                                                                              
                                                                                  

  uint32_t FilterFIFOAssignment;                                                                         
                                                                                               

  uint32_t FilterBank;                                                                     
                                                                                          
                                                                                                              
                                                                                      
                                                                                                                 

  uint32_t FilterMode;                                                             
                                                                                               

  uint32_t FilterScale;                                           
                                                                                                

  uint32_t FilterActivation;                                        
                                                                                                     

  uint32_t SlaveStartFilterBank;                                                               
                                                                                               
                                                                                                                       
                                                                                                                      
                                                    
                                                                                                                 

} CAN_FilterTypeDef;

   
                                                      
    
typedef struct
{
  uint32_t StdId;                                           
                                                                                                       

  uint32_t ExtId;                                           
                                                                                                            

  uint32_t IDE;                                                                                     
                                                                                      

  uint32_t RTR;                                                                                
                                                                                                  

  uint32_t DLC;                                                                      
                                                                                                   

  FunctionalState TransmitGlobalTime;                                                                     
                                                                                                            
                                                                                   
                                                                                                    
                                                                            

} CAN_TxHeaderTypeDef;

   
                                                      
    
typedef struct
{
  uint32_t StdId;                                           
                                                                                                       

  uint32_t ExtId;                                           
                                                                                                            

  uint32_t IDE;                                                                                     
                                                                                      

  uint32_t RTR;                                                                                
                                                                                                  

  uint32_t DLC;                                                                      
                                                                                                   

  uint32_t Timestamp;                                                                                 
                                                                                   
                                                                                                        

  uint32_t FilterMatchIndex;                                                                
                                                                                                      

} CAN_RxHeaderTypeDef;

   
                                           
    
#if USE_HAL_CAN_REGISTER_CALLBACKS == 1
typedef struct __CAN_HandleTypeDef
#else
typedef struct
#endif                                     
{
  CAN_TypeDef                 *Instance;                                              

  CAN_InitTypeDef             Init;                                                     

  __IO HAL_CAN_StateTypeDef   State;                                                    

  __IO uint32_t               ErrorCode;                                     
                                                                                                                     

#if USE_HAL_CAN_REGISTER_CALLBACKS == 1
  void (* TxMailbox0CompleteCallback)(struct __CAN_HandleTypeDef *hcan);                                             
  void (* TxMailbox1CompleteCallback)(struct __CAN_HandleTypeDef *hcan);                                             
  void (* TxMailbox2CompleteCallback)(struct __CAN_HandleTypeDef *hcan);                                             
  void (* TxMailbox0AbortCallback)(struct __CAN_HandleTypeDef *hcan);                                                
  void (* TxMailbox1AbortCallback)(struct __CAN_HandleTypeDef *hcan);                                                
  void (* TxMailbox2AbortCallback)(struct __CAN_HandleTypeDef *hcan);                                                
  void (* RxFifo0MsgPendingCallback)(struct __CAN_HandleTypeDef *hcan);                                              
  void (* RxFifo0FullCallback)(struct __CAN_HandleTypeDef *hcan);                                                    
  void (* RxFifo1MsgPendingCallback)(struct __CAN_HandleTypeDef *hcan);                                              
  void (* RxFifo1FullCallback)(struct __CAN_HandleTypeDef *hcan);                                                    
  void (* SleepCallback)(struct __CAN_HandleTypeDef *hcan);                                                          
  void (* WakeUpFromRxMsgCallback)(struct __CAN_HandleTypeDef *hcan);                                                
  void (* ErrorCallback)(struct __CAN_HandleTypeDef *hcan);                                                          

  void (* MspInitCallback)(struct __CAN_HandleTypeDef *hcan);                                                        
  void (* MspDeInitCallback)(struct __CAN_HandleTypeDef *hcan);                                                      

#endif                                       
} CAN_HandleTypeDef;

#if USE_HAL_CAN_REGISTER_CALLBACKS == 1
   
                                                             
    
typedef enum
{
  HAL_CAN_TX_MAILBOX0_COMPLETE_CB_ID       = 0x00U,                                                         
  HAL_CAN_TX_MAILBOX1_COMPLETE_CB_ID       = 0x01U,                                                         
  HAL_CAN_TX_MAILBOX2_COMPLETE_CB_ID       = 0x02U,                                                         
  HAL_CAN_TX_MAILBOX0_ABORT_CB_ID          = 0x03U,                                                         
  HAL_CAN_TX_MAILBOX1_ABORT_CB_ID          = 0x04U,                                                         
  HAL_CAN_TX_MAILBOX2_ABORT_CB_ID          = 0x05U,                                                         
  HAL_CAN_RX_FIFO0_MSG_PENDING_CB_ID       = 0x06U,                                                         
  HAL_CAN_RX_FIFO0_FULL_CB_ID              = 0x07U,                                                         
  HAL_CAN_RX_FIFO1_MSG_PENDING_CB_ID       = 0x08U,                                                         
  HAL_CAN_RX_FIFO1_FULL_CB_ID              = 0x09U,                                                         
  HAL_CAN_SLEEP_CB_ID                      = 0x0AU,                                                         
  HAL_CAN_WAKEUP_FROM_RX_MSG_CB_ID         = 0x0BU,                                                        
  HAL_CAN_ERROR_CB_ID                      = 0x0CU,                                                         

  HAL_CAN_MSPINIT_CB_ID                    = 0x0DU,                                                         
  HAL_CAN_MSPDEINIT_CB_ID                  = 0x0EU,                                                         

} HAL_CAN_CallbackIDTypeDef;

   
                                               
    
typedef  void (*pCAN_CallbackTypeDef)(CAN_HandleTypeDef *hcan);                                             

#endif                                     
   
      
    

                                                                                

                                                           
      
    

                                           
      
    
#define HAL_CAN_ERROR_NONE            (0x00000000U)                                                              
#define HAL_CAN_ERROR_EWG             (0x00000001U)                                                              
#define HAL_CAN_ERROR_EPV             (0x00000002U)                                                              
#define HAL_CAN_ERROR_BOF             (0x00000004U)                                                              
#define HAL_CAN_ERROR_STF             (0x00000008U)                                                              
#define HAL_CAN_ERROR_FOR             (0x00000010U)                                                              
#define HAL_CAN_ERROR_ACK             (0x00000020U)                                                              
#define HAL_CAN_ERROR_BR              (0x00000040U)                                                              
#define HAL_CAN_ERROR_BD              (0x00000080U)                                                              
#define HAL_CAN_ERROR_CRC             (0x00000100U)                                                              
#define HAL_CAN_ERROR_RX_FOV0         (0x00000200U)                                                              
#define HAL_CAN_ERROR_RX_FOV1         (0x00000400U)                                                              
#define HAL_CAN_ERROR_TX_ALST0        (0x00000800U)                                                              
#define HAL_CAN_ERROR_TX_TERR0        (0x00001000U)                                                              
#define HAL_CAN_ERROR_TX_ALST1        (0x00002000U)                                                              
#define HAL_CAN_ERROR_TX_TERR1        (0x00004000U)                                                              
#define HAL_CAN_ERROR_TX_ALST2        (0x00008000U)                                                              
#define HAL_CAN_ERROR_TX_TERR2        (0x00010000U)                                                              
#define HAL_CAN_ERROR_TIMEOUT         (0x00020000U)                                                              
#define HAL_CAN_ERROR_NOT_INITIALIZED (0x00040000U)                                                              
#define HAL_CAN_ERROR_NOT_READY       (0x00080000U)                                                              
#define HAL_CAN_ERROR_NOT_STARTED     (0x00100000U)                                                              
#define HAL_CAN_ERROR_PARAM           (0x00200000U)                                                              

#if USE_HAL_CAN_REGISTER_CALLBACKS == 1
#define HAL_CAN_ERROR_INVALID_CALLBACK (0x00400000U)                                                             
#endif                                     
#define HAL_CAN_ERROR_INTERNAL        (0x00800000U)                                                              

   
      
    

                                           
      
    
#define CAN_INITSTATUS_FAILED       (0x00000000U)                                   
#define CAN_INITSTATUS_SUCCESS      (0x00000001U)                                   
   
      
    

                                                   
      
    
#define CAN_MODE_NORMAL             (0x00000000U)                                                   
#define CAN_MODE_LOOPBACK           ((uint32_t)CAN_BTR_LBKM)                                        
#define CAN_MODE_SILENT             ((uint32_t)CAN_BTR_SILM)                                        
#define CAN_MODE_SILENT_LOOPBACK    ((uint32_t)(CAN_BTR_LBKM | CAN_BTR_SILM))                             
                                                                                                    
   
      
    


                                                                           
      
    
#define CAN_SJW_1TQ                 (0x00000000U)                                    
#define CAN_SJW_2TQ                 ((uint32_t)CAN_BTR_SJW_0)                        
#define CAN_SJW_3TQ                 ((uint32_t)CAN_BTR_SJW_1)                        
#define CAN_SJW_4TQ                 ((uint32_t)CAN_BTR_SJW)                          
   
      
    

                                                                                 
      
    
#define CAN_BS1_1TQ                 (0x00000000U)                                                                       
#define CAN_BS1_2TQ                 ((uint32_t)CAN_BTR_TS1_0)                                                           
#define CAN_BS1_3TQ                 ((uint32_t)CAN_BTR_TS1_1)                                                           
#define CAN_BS1_4TQ                 ((uint32_t)(CAN_BTR_TS1_1 | CAN_BTR_TS1_0))                                         
#define CAN_BS1_5TQ                 ((uint32_t)CAN_BTR_TS1_2)                                                           
#define CAN_BS1_6TQ                 ((uint32_t)(CAN_BTR_TS1_2 | CAN_BTR_TS1_0))                                         
#define CAN_BS1_7TQ                 ((uint32_t)(CAN_BTR_TS1_2 | CAN_BTR_TS1_1))                                         
#define CAN_BS1_8TQ                 ((uint32_t)(CAN_BTR_TS1_2 | CAN_BTR_TS1_1 | CAN_BTR_TS1_0))                         
#define CAN_BS1_9TQ                 ((uint32_t)CAN_BTR_TS1_3)                                                           
#define CAN_BS1_10TQ                ((uint32_t)(CAN_BTR_TS1_3 | CAN_BTR_TS1_0))                                         
#define CAN_BS1_11TQ                ((uint32_t)(CAN_BTR_TS1_3 | CAN_BTR_TS1_1))                                         
#define CAN_BS1_12TQ                ((uint32_t)(CAN_BTR_TS1_3 | CAN_BTR_TS1_1 | CAN_BTR_TS1_0))                         
#define CAN_BS1_13TQ                ((uint32_t)(CAN_BTR_TS1_3 | CAN_BTR_TS1_2))                                         
#define CAN_BS1_14TQ                ((uint32_t)(CAN_BTR_TS1_3 | CAN_BTR_TS1_2 | CAN_BTR_TS1_0))                         
#define CAN_BS1_15TQ                ((uint32_t)(CAN_BTR_TS1_3 | CAN_BTR_TS1_2 | CAN_BTR_TS1_1))                         
#define CAN_BS1_16TQ                ((uint32_t)CAN_BTR_TS1)                        
   
      
    

                                                                                 
      
    
#define CAN_BS2_1TQ                 (0x00000000U)                                                      
#define CAN_BS2_2TQ                 ((uint32_t)CAN_BTR_TS2_0)                                          
#define CAN_BS2_3TQ                 ((uint32_t)CAN_BTR_TS2_1)                                          
#define CAN_BS2_4TQ                 ((uint32_t)(CAN_BTR_TS2_1 | CAN_BTR_TS2_0))                        
#define CAN_BS2_5TQ                 ((uint32_t)CAN_BTR_TS2_2)                                          
#define CAN_BS2_6TQ                 ((uint32_t)(CAN_BTR_TS2_2 | CAN_BTR_TS2_0))                        
#define CAN_BS2_7TQ                 ((uint32_t)(CAN_BTR_TS2_2 | CAN_BTR_TS2_1))                        
#define CAN_BS2_8TQ                 ((uint32_t)CAN_BTR_TS2)                                            
   
      
    

                                             
      
    
#define CAN_FILTERMODE_IDMASK       (0x00000000U)                              
#define CAN_FILTERMODE_IDLIST       (0x00000001U)                              
   
      
    

                                               
      
    
#define CAN_FILTERSCALE_16BIT       (0x00000000U)                            
#define CAN_FILTERSCALE_32BIT       (0x00000001U)                            
   
      
    

                                                         
      
    
#define CAN_FILTER_DISABLE          (0x00000000U)                        
#define CAN_FILTER_ENABLE           (0x00000001U)                        
   
      
    

                                             
      
    
#define CAN_FILTER_FIFO0            (0x00000000U)                                               
#define CAN_FILTER_FIFO1            (0x00000001U)                                               
   
      
    

                                                     
      
    
#define CAN_ID_STD                  (0x00000000U)                     
#define CAN_ID_EXT                  (0x00000004U)                     
   
      
    

                                                                             
      
    
#define CAN_RTR_DATA                (0x00000000U)                      
#define CAN_RTR_REMOTE              (0x00000002U)                      
   
      
    

                                                             
      
    
#define CAN_RX_FIFO0                (0x00000000U)                            
#define CAN_RX_FIFO1                (0x00000001U)                            
   
      
    

                                               
      
    
#define CAN_TX_MAILBOX0             (0x00000001U)                       
#define CAN_TX_MAILBOX1             (0x00000002U)                       
#define CAN_TX_MAILBOX2             (0x00000004U)                       
   
      
    

                                 
      
    
                    
#define CAN_FLAG_RQCP0              (0x00000500U)                                           
#define CAN_FLAG_TXOK0              (0x00000501U)                                           
#define CAN_FLAG_ALST0              (0x00000502U)                                           
#define CAN_FLAG_TERR0              (0x00000503U)                                           
#define CAN_FLAG_RQCP1              (0x00000508U)                                           
#define CAN_FLAG_TXOK1              (0x00000509U)                                           
#define CAN_FLAG_ALST1              (0x0000050AU)                                           
#define CAN_FLAG_TERR1              (0x0000050BU)                                           
#define CAN_FLAG_RQCP2              (0x00000510U)                                           
#define CAN_FLAG_TXOK2              (0x00000511U)                                           
#define CAN_FLAG_ALST2              (0x00000512U)                                           
#define CAN_FLAG_TERR2              (0x00000513U)                                           
#define CAN_FLAG_TME0               (0x0000051AU)                                           
#define CAN_FLAG_TME1               (0x0000051BU)                                           
#define CAN_FLAG_TME2               (0x0000051CU)                                           
#define CAN_FLAG_LOW0               (0x0000051DU)                                           
#define CAN_FLAG_LOW1               (0x0000051EU)                                           
#define CAN_FLAG_LOW2               (0x0000051FU)                                           

                   
#define CAN_FLAG_FF0                (0x00000203U)                                           
#define CAN_FLAG_FOV0               (0x00000204U)                                           
#define CAN_FLAG_FF1                (0x00000403U)                                           
#define CAN_FLAG_FOV1               (0x00000404U)                                           

                          
#define CAN_FLAG_INAK               (0x00000100U)                                           
#define CAN_FLAG_SLAK               (0x00000101U)                                           
#define CAN_FLAG_ERRI               (0x00000102U)                                           
#define CAN_FLAG_WKU                (0x00000103U)                                           
#define CAN_FLAG_SLAKI              (0x00000104U)                                           

                 
#define CAN_FLAG_EWG                (0x00000300U)                                           
#define CAN_FLAG_EPV                (0x00000301U)                                           
#define CAN_FLAG_BOF                (0x00000302U)                                           
   
      
    


                                           
      
    
                        
#define CAN_IT_TX_MAILBOX_EMPTY     ((uint32_t)CAN_IER_TMEIE)                                           

                        
#define CAN_IT_RX_FIFO0_MSG_PENDING ((uint32_t)CAN_IER_FMPIE0)                                          
#define CAN_IT_RX_FIFO0_FULL        ((uint32_t)CAN_IER_FFIE0)                                           
#define CAN_IT_RX_FIFO0_OVERRUN     ((uint32_t)CAN_IER_FOVIE0)                                          
#define CAN_IT_RX_FIFO1_MSG_PENDING ((uint32_t)CAN_IER_FMPIE1)                                          
#define CAN_IT_RX_FIFO1_FULL        ((uint32_t)CAN_IER_FFIE1)                                           
#define CAN_IT_RX_FIFO1_OVERRUN     ((uint32_t)CAN_IER_FOVIE1)                                          

                               
#define CAN_IT_WAKEUP               ((uint32_t)CAN_IER_WKUIE)                                           
#define CAN_IT_SLEEP_ACK            ((uint32_t)CAN_IER_SLKIE)                                           

                      
#define CAN_IT_ERROR_WARNING        ((uint32_t)CAN_IER_EWGIE)                                           
#define CAN_IT_ERROR_PASSIVE        ((uint32_t)CAN_IER_EPVIE)                                           
#define CAN_IT_BUSOFF               ((uint32_t)CAN_IER_BOFIE)                                           
#define CAN_IT_LAST_ERROR_CODE      ((uint32_t)CAN_IER_LECIE)                                           
#define CAN_IT_ERROR                ((uint32_t)CAN_IER_ERRIE)                                           
   
      
    

   
      
    

                                                                                
                                                     
      
    

                                  
                                  
                
    
#if USE_HAL_CAN_REGISTER_CALLBACKS == 1
#define __HAL_CAN_RESET_HANDLE_STATE(__HANDLE__) do{                                              \
                                                     (__HANDLE__)->State = HAL_CAN_STATE_RESET;   \
                                                     (__HANDLE__)->MspInitCallback = NULL;        \
                                                     (__HANDLE__)->MspDeInitCallback = NULL;      \
                                                   } while(0)
#else
#define __HAL_CAN_RESET_HANDLE_STATE(__HANDLE__) ((__HANDLE__)->State = HAL_CAN_STATE_RESET)
#endif                                    

   
                                                
                                  
                                                          
                                                                          
                
    
#define __HAL_CAN_ENABLE_IT(__HANDLE__, __INTERRUPT__) (((__HANDLE__)->Instance->IER) |= (__INTERRUPT__))

   
                                                 
                                  
                                                           
                                                                          
                
    
#define __HAL_CAN_DISABLE_IT(__HANDLE__, __INTERRUPT__) (((__HANDLE__)->Instance->IER) &= ~(__INTERRUPT__))

                                                                               
                                                
                                                                      
                                                                  
                                                
    
#define __HAL_CAN_GET_IT_SOURCE(__HANDLE__, __INTERRUPT__) (((__HANDLE__)->Instance->IER) & (__INTERRUPT__))

                                                               
                                                
                                                 
                                                       
                                                  
    
#define __HAL_CAN_GET_FLAG(__HANDLE__, __FLAG__) \
  ((((__FLAG__) >> 8U) == 5U)? ((((__HANDLE__)->Instance->TSR) & (1U << ((__FLAG__) & CAN_FLAG_MASK))) == (1U << ((__FLAG__) & CAN_FLAG_MASK))): \
   (((__FLAG__) >> 8U) == 2U)? ((((__HANDLE__)->Instance->RF0R) & (1U << ((__FLAG__) & CAN_FLAG_MASK))) == (1U << ((__FLAG__) & CAN_FLAG_MASK))): \
   (((__FLAG__) >> 8U) == 4U)? ((((__HANDLE__)->Instance->RF1R) & (1U << ((__FLAG__) & CAN_FLAG_MASK))) == (1U << ((__FLAG__) & CAN_FLAG_MASK))): \
   (((__FLAG__) >> 8U) == 1U)? ((((__HANDLE__)->Instance->MSR) & (1U << ((__FLAG__) & CAN_FLAG_MASK))) == (1U << ((__FLAG__) & CAN_FLAG_MASK))): \
   (((__FLAG__) >> 8U) == 3U)? ((((__HANDLE__)->Instance->ESR) & (1U << ((__FLAG__) & CAN_FLAG_MASK))) == (1U << ((__FLAG__) & CAN_FLAG_MASK))): 0U)

                                                 
                                                
                                                 
                                                              
                                                                   
                                                                  
                                                                   
                                                                     
                                                                   
                                                                  
                                                                   
                                                                     
                                                                   
                                                                  
                                                                   
                                                                     
                                                       
                                                          
                                                       
                                                          
                                                          
                                                                    
                
    
#define __HAL_CAN_CLEAR_FLAG(__HANDLE__, __FLAG__) \
  ((((__FLAG__) >> 8U) == 5U)? (((__HANDLE__)->Instance->TSR) = (1UL << ((__FLAG__) & CAN_FLAG_MASK))): \
   (((__FLAG__) >> 8U) == 2U)? (((__HANDLE__)->Instance->RF0R) = (1UL << ((__FLAG__) & CAN_FLAG_MASK))): \
   (((__FLAG__) >> 8U) == 4U)? (((__HANDLE__)->Instance->RF1R) = (1UL << ((__FLAG__) & CAN_FLAG_MASK))): \
   (((__FLAG__) >> 8U) == 1U)? (((__HANDLE__)->Instance->MSR) = (1UL << ((__FLAG__) & CAN_FLAG_MASK))): 0U)

   
     
   

                                                                                
                                                             
      
    

                                                                                            
                                                        
     
   

                                                                                
HAL_StatusTypeDef HAL_CAN_Init(CAN_HandleTypeDef *hcan);
HAL_StatusTypeDef HAL_CAN_DeInit(CAN_HandleTypeDef *hcan);
void HAL_CAN_MspInit(CAN_HandleTypeDef *hcan);
void HAL_CAN_MspDeInit(CAN_HandleTypeDef *hcan);

#if USE_HAL_CAN_REGISTER_CALLBACKS == 1
                                                                                
HAL_StatusTypeDef HAL_CAN_RegisterCallback(CAN_HandleTypeDef *hcan, HAL_CAN_CallbackIDTypeDef CallbackID,
                                           void (* pCallback)(CAN_HandleTypeDef *_hcan));
HAL_StatusTypeDef HAL_CAN_UnRegisterCallback(CAN_HandleTypeDef *hcan, HAL_CAN_CallbackIDTypeDef CallbackID);

#endif                                       
   
     
   

                                                                     
                                     
     
   

                                                                                
HAL_StatusTypeDef HAL_CAN_ConfigFilter(CAN_HandleTypeDef *hcan, const CAN_FilterTypeDef *sFilterConfig);

   
     
   

                                                               
                               
     
   

                                                                                
HAL_StatusTypeDef HAL_CAN_Start(CAN_HandleTypeDef *hcan);
HAL_StatusTypeDef HAL_CAN_Stop(CAN_HandleTypeDef *hcan);
HAL_StatusTypeDef HAL_CAN_RequestSleep(CAN_HandleTypeDef *hcan);
HAL_StatusTypeDef HAL_CAN_WakeUp(CAN_HandleTypeDef *hcan);
uint32_t HAL_CAN_IsSleepActive(const CAN_HandleTypeDef *hcan);
HAL_StatusTypeDef HAL_CAN_AddTxMessage(CAN_HandleTypeDef *hcan, const CAN_TxHeaderTypeDef *pHeader,
                                       const uint8_t aData[], uint32_t *pTxMailbox);
HAL_StatusTypeDef HAL_CAN_AbortTxRequest(CAN_HandleTypeDef *hcan, uint32_t TxMailboxes);
uint32_t HAL_CAN_GetTxMailboxesFreeLevel(const CAN_HandleTypeDef *hcan);
uint32_t HAL_CAN_IsTxMessagePending(const CAN_HandleTypeDef *hcan, uint32_t TxMailboxes);
uint32_t HAL_CAN_GetTxTimestamp(const CAN_HandleTypeDef *hcan, uint32_t TxMailbox);
HAL_StatusTypeDef HAL_CAN_GetRxMessage(CAN_HandleTypeDef *hcan, uint32_t RxFifo,
                                       CAN_RxHeaderTypeDef *pHeader, uint8_t aData[]);
uint32_t HAL_CAN_GetRxFifoFillLevel(const CAN_HandleTypeDef *hcan, uint32_t RxFifo);

   
     
   

                                                                   
                                   
     
   
                                                                                
HAL_StatusTypeDef HAL_CAN_ActivateNotification(CAN_HandleTypeDef *hcan, uint32_t ActiveITs);
HAL_StatusTypeDef HAL_CAN_DeactivateNotification(CAN_HandleTypeDef *hcan, uint32_t InactiveITs);
void HAL_CAN_IRQHandler(CAN_HandleTypeDef *hcan);

   
     
   

                                                                
                                
     
   
                                                                                

void HAL_CAN_TxMailbox0CompleteCallback(CAN_HandleTypeDef *hcan);
void HAL_CAN_TxMailbox1CompleteCallback(CAN_HandleTypeDef *hcan);
void HAL_CAN_TxMailbox2CompleteCallback(CAN_HandleTypeDef *hcan);
void HAL_CAN_TxMailbox0AbortCallback(CAN_HandleTypeDef *hcan);
void HAL_CAN_TxMailbox1AbortCallback(CAN_HandleTypeDef *hcan);
void HAL_CAN_TxMailbox2AbortCallback(CAN_HandleTypeDef *hcan);
void HAL_CAN_RxFifo0MsgPendingCallback(CAN_HandleTypeDef *hcan);
void HAL_CAN_RxFifo0FullCallback(CAN_HandleTypeDef *hcan);
void HAL_CAN_RxFifo1MsgPendingCallback(CAN_HandleTypeDef *hcan);
void HAL_CAN_RxFifo1FullCallback(CAN_HandleTypeDef *hcan);
void HAL_CAN_SleepCallback(CAN_HandleTypeDef *hcan);
void HAL_CAN_WakeUpFromRxMsgCallback(CAN_HandleTypeDef *hcan);
void HAL_CAN_ErrorCallback(CAN_HandleTypeDef *hcan);

   
     
   

                                                                                  
                                           
     
   
                                                                                
HAL_CAN_StateTypeDef HAL_CAN_GetState(const CAN_HandleTypeDef *hcan);
uint32_t HAL_CAN_GetError(const CAN_HandleTypeDef *hcan);
HAL_StatusTypeDef HAL_CAN_ResetError(CAN_HandleTypeDef *hcan);

   
     
   

   
     
   

                                                                                
                                                 
      
    

   
      
    

                                                                                
                                                         
      
    

   
      
    

                                                                                
                                                         
      
    
#define CAN_FLAG_MASK  (0x000000FFU)
   
      
    

                                                                               
                                                   
      
    

#define IS_CAN_MODE(MODE) (((MODE) == CAN_MODE_NORMAL) || \
                           ((MODE) == CAN_MODE_LOOPBACK)|| \
                           ((MODE) == CAN_MODE_SILENT) || \
                           ((MODE) == CAN_MODE_SILENT_LOOPBACK))
#define IS_CAN_SJW(SJW) (((SJW) == CAN_SJW_1TQ) || ((SJW) == CAN_SJW_2TQ) || \
                         ((SJW) == CAN_SJW_3TQ) || ((SJW) == CAN_SJW_4TQ))
#define IS_CAN_BS1(BS1) (((BS1) == CAN_BS1_1TQ) || ((BS1) == CAN_BS1_2TQ) || \
                         ((BS1) == CAN_BS1_3TQ) || ((BS1) == CAN_BS1_4TQ) || \
                         ((BS1) == CAN_BS1_5TQ) || ((BS1) == CAN_BS1_6TQ) || \
                         ((BS1) == CAN_BS1_7TQ) || ((BS1) == CAN_BS1_8TQ) || \
                         ((BS1) == CAN_BS1_9TQ) || ((BS1) == CAN_BS1_10TQ)|| \
                         ((BS1) == CAN_BS1_11TQ)|| ((BS1) == CAN_BS1_12TQ)|| \
                         ((BS1) == CAN_BS1_13TQ)|| ((BS1) == CAN_BS1_14TQ)|| \
                         ((BS1) == CAN_BS1_15TQ)|| ((BS1) == CAN_BS1_16TQ))
#define IS_CAN_BS2(BS2) (((BS2) == CAN_BS2_1TQ) || ((BS2) == CAN_BS2_2TQ) || \
                         ((BS2) == CAN_BS2_3TQ) || ((BS2) == CAN_BS2_4TQ) || \
                         ((BS2) == CAN_BS2_5TQ) || ((BS2) == CAN_BS2_6TQ) || \
                         ((BS2) == CAN_BS2_7TQ) || ((BS2) == CAN_BS2_8TQ))
#define IS_CAN_PRESCALER(PRESCALER) (((PRESCALER) >= 1U) && ((PRESCALER) <= 1024U))
#define IS_CAN_FILTER_ID_HALFWORD(HALFWORD) ((HALFWORD) <= 0xFFFFU)
#if   defined(CAN2)
#define IS_CAN_FILTER_BANK_DUAL(BANK) ((BANK) <= 27U)
#endif
#define IS_CAN_FILTER_BANK_SINGLE(BANK) ((BANK) <= 13U)
#define IS_CAN_FILTER_MODE(MODE) (((MODE) == CAN_FILTERMODE_IDMASK) || \
                                  ((MODE) == CAN_FILTERMODE_IDLIST))
#define IS_CAN_FILTER_SCALE(SCALE) (((SCALE) == CAN_FILTERSCALE_16BIT) || \
                                    ((SCALE) == CAN_FILTERSCALE_32BIT))
#define IS_CAN_FILTER_ACTIVATION(ACTIVATION) (((ACTIVATION) == CAN_FILTER_DISABLE) || \
                                              ((ACTIVATION) == CAN_FILTER_ENABLE))
#define IS_CAN_FILTER_FIFO(FIFO) (((FIFO) == CAN_FILTER_FIFO0) || \
                                  ((FIFO) == CAN_FILTER_FIFO1))
#define IS_CAN_TX_MAILBOX(TRANSMITMAILBOX) (((TRANSMITMAILBOX) == CAN_TX_MAILBOX0 ) || \
                                            ((TRANSMITMAILBOX) == CAN_TX_MAILBOX1 ) || \
                                            ((TRANSMITMAILBOX) == CAN_TX_MAILBOX2 ))
#define IS_CAN_TX_MAILBOX_LIST(TRANSMITMAILBOX) ((TRANSMITMAILBOX) <= (CAN_TX_MAILBOX0 | CAN_TX_MAILBOX1 | \
                                                                       CAN_TX_MAILBOX2))
#define IS_CAN_STDID(STDID)   ((STDID) <= 0x7FFU)
#define IS_CAN_EXTID(EXTID)   ((EXTID) <= 0x1FFFFFFFU)
#define IS_CAN_DLC(DLC)       ((DLC) <= 8U)
#define IS_CAN_IDTYPE(IDTYPE)  (((IDTYPE) == CAN_ID_STD) || \
                                ((IDTYPE) == CAN_ID_EXT))
#define IS_CAN_RTR(RTR) (((RTR) == CAN_RTR_DATA) || ((RTR) == CAN_RTR_REMOTE))
#define IS_CAN_RX_FIFO(FIFO) (((FIFO) == CAN_RX_FIFO0) || ((FIFO) == CAN_RX_FIFO1))
#define IS_CAN_IT(IT) ((IT) <= (CAN_IT_TX_MAILBOX_EMPTY     | CAN_IT_RX_FIFO0_MSG_PENDING      | \
                                CAN_IT_RX_FIFO0_FULL        | CAN_IT_RX_FIFO0_OVERRUN          | \
                                CAN_IT_RX_FIFO1_MSG_PENDING | CAN_IT_RX_FIFO1_FULL             | \
                                CAN_IT_RX_FIFO1_OVERRUN     | CAN_IT_WAKEUP                    | \
                                CAN_IT_SLEEP_ACK            | CAN_IT_ERROR_WARNING             | \
                                CAN_IT_ERROR_PASSIVE        | CAN_IT_BUSOFF                    | \
                                CAN_IT_LAST_ERROR_CODE      | CAN_IT_ERROR))

   
      
    
                                                                                

   
      
    


#endif           
   
      
    

#ifdef __cplusplus
}
#endif

#endif                          
