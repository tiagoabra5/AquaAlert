/**
  ******************************************************************************
  * @file    stm32l4xx_hal_can_legacy.h
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

                                                                                
#ifndef __STM32L4xx_CAN_LEGACY_H
#define __STM32L4xx_CAN_LEGACY_H

#ifdef __cplusplus
 extern "C" {
#endif

#if defined(CAN1)
                                                                                
#include "stm32l4xx_hal_def.h"

                                    
      
    

                   
      
    

                                                                                
                                                   
      
    

   
                                           
    
typedef enum
{
  HAL_CAN_STATE_RESET             = 0x00,                                             
  HAL_CAN_STATE_READY             = 0x01,                                             
  HAL_CAN_STATE_BUSY              = 0x02,                                             
  HAL_CAN_STATE_BUSY_TX           = 0x12,                                             
  HAL_CAN_STATE_BUSY_RX           = 0x22,                                             
  HAL_CAN_STATE_BUSY_TX_RX        = 0x32,                                             
  HAL_CAN_STATE_TIMEOUT           = 0x03,                                             
  HAL_CAN_STATE_ERROR             = 0x04                                              

}HAL_CAN_StateTypeDef;

   
                                         
    
typedef struct
{
  uint32_t Prescaler;                                              
                                                                                                       

  uint32_t Mode;                                             
                                                                                       

  uint32_t SJW;                                                        
                                                                      
                                                                       
                                                                                                   

  uint32_t BS1;                                                                  
                                                                                                      

  uint32_t BS2;                                                                  
                                                                                                      

  uint32_t TTCM;                                                                    
                                                                              

  uint32_t ABOM;                                                               
                                                                             

  uint32_t AWUM;                                                         
                                                                             

  uint32_t NART;                                                                    
                                                                             

  uint32_t RFLM;                                                           
                                                                             

  uint32_t TXFP;                                                         
                                                                             
}CAN_InitTypeDef;

   
                                                         
    
typedef struct
{
  uint32_t FilterIdHigh;                                                                            
                                                                                            
                                                                                                                         

  uint32_t FilterIdLow;                                                                             
                                                                                             
                                                                                                                         

  uint32_t FilterMaskIdHigh;                                                                     
                                                                                              
                                                                             
                                                                                                                         

  uint32_t FilterMaskIdLow;                                                                      
                                                                                              
                                                                              
                                                                                                                         

  uint32_t FilterFIFOAssignment;                                                                        
                                                                                               

  uint32_t FilterNumber;                                                              
                                                                                                                

  uint32_t FilterMode;                                                             
                                                                                               

  uint32_t FilterScale;                                           
                                                                                                

  uint32_t FilterActivation;                                        
                                                                                        

  uint32_t BankNumber;                                                    
                                                                                                                

}CAN_FilterConfTypeDef;

   
                                               
    
typedef struct
{
  uint32_t StdId;                                           
                                                                                                      

  uint32_t ExtId;                                           
                                                                                                           

  uint32_t IDE;                                                                                     
                                                                                      

  uint32_t RTR;                                                                                
                                                                                                  

  uint32_t DLC;                                                                      
                                                                                                  

  uint8_t Data[8];                                            
                                                                                                     

}CanTxMsgTypeDef;

   
                                               
    
typedef struct
{
  uint32_t StdId;                                              
                                                                                                         

  uint32_t ExtId;                                              
                                                                                                              

  uint32_t IDE;                                                                                     
                                                                                         

  uint32_t RTR;                                                                   
                                                                                                     

  uint32_t DLC;                                                                      
                                                                                                     

  uint8_t Data[8];                                            
                                                                                                        

  uint32_t FMI;                                                                                                 
                                                                                                        

  uint32_t FIFONumber;                                         
                                                                            

}CanRxMsgTypeDef;

   
                                           
    
typedef struct
{
  CAN_TypeDef                 *Instance;                                        

  CAN_InitTypeDef             Init;                                             

  CanTxMsgTypeDef*            pTxMsg;                                           

  CanRxMsgTypeDef*            pRxMsg;                                           

  __IO HAL_CAN_StateTypeDef   State;                                            

  HAL_LockTypeDef             Lock;                                             

  __IO uint32_t               ErrorCode;                                        

}CAN_HandleTypeDef;

   
      
    

                                                                                
                                                           
      
    

                                           
      
    
#define   HAL_CAN_ERROR_NONE        ((uint32_t)0x00000000)                                
#define   HAL_CAN_ERROR_EWG         ((uint32_t)0x00000001)                                
#define   HAL_CAN_ERROR_EPV         ((uint32_t)0x00000002)                                
#define   HAL_CAN_ERROR_BOF         ((uint32_t)0x00000004)                                
#define   HAL_CAN_ERROR_STF         ((uint32_t)0x00000008)                                
#define   HAL_CAN_ERROR_FOR         ((uint32_t)0x00000010)                                
#define   HAL_CAN_ERROR_ACK         ((uint32_t)0x00000020)                                
#define   HAL_CAN_ERROR_BR          ((uint32_t)0x00000040)                                
#define   HAL_CAN_ERROR_BD          ((uint32_t)0x00000080)                                
#define   HAL_CAN_ERROR_CRC         ((uint32_t)0x00000100)                                
#define   HAL_CAN_ERROR_FOV0        ((uint32_t)0x00000200)                                
#define   HAL_CAN_ERROR_FOV1        ((uint32_t)0x00000400)                                
   
      
    

                                                      
      
    
#define CAN_INITSTATUS_FAILED       ((uint32_t)0x00000000)                                   
#define CAN_INITSTATUS_SUCCESS      ((uint32_t)0x00000001)                               
   
      
    

                                                   
      
    
#define CAN_MODE_NORMAL             ((uint32_t)0x00000000)                                          
#define CAN_MODE_LOOPBACK           ((uint32_t)CAN_BTR_LBKM)                                        
#define CAN_MODE_SILENT             ((uint32_t)CAN_BTR_SILM)                                        
#define CAN_MODE_SILENT_LOOPBACK    ((uint32_t)(CAN_BTR_LBKM | CAN_BTR_SILM))                                            
   
      
    


                                                                           
      
    
#define CAN_SJW_1TQ                 ((uint32_t)0x00000000)                           
#define CAN_SJW_2TQ                 ((uint32_t)CAN_BTR_SJW_0)                        
#define CAN_SJW_3TQ                 ((uint32_t)CAN_BTR_SJW_1)                        
#define CAN_SJW_4TQ                 ((uint32_t)CAN_BTR_SJW)                          
   
      
    

                                                                                 
      
    
#define CAN_BS1_1TQ                 ((uint32_t)0x00000000)                                                              
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
   
      
    

                                                                                 
      
    
#define CAN_BS2_1TQ                 ((uint32_t)0x00000000)                                             
#define CAN_BS2_2TQ                 ((uint32_t)CAN_BTR_TS2_0)                                          
#define CAN_BS2_3TQ                 ((uint32_t)CAN_BTR_TS2_1)                                          
#define CAN_BS2_4TQ                 ((uint32_t)(CAN_BTR_TS2_1 | CAN_BTR_TS2_0))                        
#define CAN_BS2_5TQ                 ((uint32_t)CAN_BTR_TS2_2)                                          
#define CAN_BS2_6TQ                 ((uint32_t)(CAN_BTR_TS2_2 | CAN_BTR_TS2_0))                        
#define CAN_BS2_7TQ                 ((uint32_t)(CAN_BTR_TS2_2 | CAN_BTR_TS2_1))                        
#define CAN_BS2_8TQ                 ((uint32_t)CAN_BTR_TS2)                                            
   
      
    

                                             
      
    
#define CAN_FILTERMODE_IDMASK       ((uint8_t)0x00)                              
#define CAN_FILTERMODE_IDLIST       ((uint8_t)0x01)                              
   
      
    

                                               
      
    
#define CAN_FILTERSCALE_16BIT       ((uint8_t)0x00)                            
#define CAN_FILTERSCALE_32BIT       ((uint8_t)0x01)                            
   
      
    

                                             
      
    
#define CAN_FILTER_FIFO0             ((uint8_t)0x00)                                               
#define CAN_FILTER_FIFO1             ((uint8_t)0x01)                                               
   
      
    

                                                     
      
    
#define CAN_ID_STD             ((uint32_t)0x00000000)                     
#define CAN_ID_EXT             ((uint32_t)0x00000004)                     
   
      
    

                                                                             
      
    
#define CAN_RTR_DATA                ((uint32_t)0x00000000)                    
#define CAN_RTR_REMOTE              ((uint32_t)0x00000002)                      
   
      
    

                                                                       
      
    
#define CAN_FIFO0                   ((uint8_t)0x00)                                    
#define CAN_FIFO1                   ((uint8_t)0x01)                                    
   
      
    

                                 
      
    
                                                                                   
                                    
                                                                    
                                    

                    
#define CAN_FLAG_RQCP0             ((uint32_t)0x00000500)                                       
#define CAN_FLAG_RQCP1             ((uint32_t)0x00000508)                                       
#define CAN_FLAG_RQCP2             ((uint32_t)0x00000510)                                       
#define CAN_FLAG_TXOK0             ((uint32_t)0x00000501)                                       
#define CAN_FLAG_TXOK1             ((uint32_t)0x00000509)                                       
#define CAN_FLAG_TXOK2             ((uint32_t)0x00000511)                                       
#define CAN_FLAG_TME0              ((uint32_t)0x0000051A)                                       
#define CAN_FLAG_TME1              ((uint32_t)0x0000051B)                                       
#define CAN_FLAG_TME2              ((uint32_t)0x0000051C)                                       

                   
#define CAN_FLAG_FF0               ((uint32_t)0x00000203)                             
#define CAN_FLAG_FOV0              ((uint32_t)0x00000204)                             

#define CAN_FLAG_FF1               ((uint32_t)0x00000403)                             
#define CAN_FLAG_FOV1              ((uint32_t)0x00000404)                             

                          
#define CAN_FLAG_WKU               ((uint32_t)0x00000103)                                
#define CAN_FLAG_SLAK              ((uint32_t)0x00000101)                                
#define CAN_FLAG_SLAKI             ((uint32_t)0x00000104)                                
                                                                                    
                                                   

                 
#define CAN_FLAG_EWG               ((uint32_t)0x00000300)                              
#define CAN_FLAG_EPV               ((uint32_t)0x00000301)                              
#define CAN_FLAG_BOF               ((uint32_t)0x00000302)                              
   
      
    

                                           
      
    
#define CAN_IT_TME                  ((uint32_t)CAN_IER_TMEIE)                                           

                        
#define CAN_IT_FMP0                 ((uint32_t)CAN_IER_FMPIE0)                                          
#define CAN_IT_FF0                  ((uint32_t)CAN_IER_FFIE0)                                           
#define CAN_IT_FOV0                 ((uint32_t)CAN_IER_FOVIE0)                                          
#define CAN_IT_FMP1                 ((uint32_t)CAN_IER_FMPIE1)                                          
#define CAN_IT_FF1                  ((uint32_t)CAN_IER_FFIE1)                                           
#define CAN_IT_FOV1                 ((uint32_t)CAN_IER_FOVIE1)                                          

                               
#define CAN_IT_WKU                  ((uint32_t)CAN_IER_WKUIE)                                     
#define CAN_IT_SLK                  ((uint32_t)CAN_IER_SLKIE)                                     

                      
#define CAN_IT_EWG                  ((uint32_t)CAN_IER_EWGIE)                                  
#define CAN_IT_EPV                  ((uint32_t)CAN_IER_EPVIE)                                  
#define CAN_IT_BOF                  ((uint32_t)CAN_IER_BOFIE)                                  
#define CAN_IT_LEC                  ((uint32_t)CAN_IER_LECIE)                                  
#define CAN_IT_ERR                  ((uint32_t)CAN_IER_ERRIE)                                  

   
      
    

                          
#define CAN_TXMAILBOX_0   ((uint8_t)0x00)
#define CAN_TXMAILBOX_1   ((uint8_t)0x01)
#define CAN_TXMAILBOX_2   ((uint8_t)0x02)

   
      
    

                                                                                
                                                    
      
    

                                   
                                   
                
    
#define __HAL_CAN_RESET_HANDLE_STATE(__HANDLE__) ((__HANDLE__)->State = HAL_CAN_STATE_RESET)

   
                                               
                                   
                                         
                
    
#define __HAL_CAN_ENABLE_IT(__HANDLE__, __INTERRUPT__) (((__HANDLE__)->Instance->IER) |= (__INTERRUPT__))

   
                                                
                                   
                                         
                
    
#define __HAL_CAN_DISABLE_IT(__HANDLE__, __INTERRUPT__) (((__HANDLE__)->Instance->IER) &= ~(__INTERRUPT__))

   
                                                           
                                   
                                                                        
                                          
    
#define __HAL_CAN_MSG_PENDING(__HANDLE__, __FIFONUMBER__) (((__FIFONUMBER__) == CAN_FIFO0)? \
((uint8_t)((__HANDLE__)->Instance->RF0R&(uint32_t)0x03)) : ((uint8_t)((__HANDLE__)->Instance->RF1R&(uint32_t)0x03)))

                                                               
                                                 
                                                  
                                                              
                                                        
                                                        
                                                        
                                                                 
                                                                 
                                                                 
                                                                
                                                                
                                                                
                                                              
                                                  
                                                      
                                                              
                                                  
                                                      
                                              
                                                         
                                                          
                                                    
                                                    
                                              
                                                      
    
#define __HAL_CAN_GET_FLAG(__HANDLE__, __FLAG__) \
((((__FLAG__) >> 8) == 5)? ((((__HANDLE__)->Instance->TSR) & (1U << ((__FLAG__) & CAN_FLAG_MASK))) == (1U << ((__FLAG__) & CAN_FLAG_MASK))): \
 (((__FLAG__) >> 8) == 2)? ((((__HANDLE__)->Instance->RF0R) & (1U << ((__FLAG__) & CAN_FLAG_MASK))) == (1U << ((__FLAG__) & CAN_FLAG_MASK))): \
 (((__FLAG__) >> 8) == 4)? ((((__HANDLE__)->Instance->RF1R) & (1U << ((__FLAG__) & CAN_FLAG_MASK))) == (1U << ((__FLAG__) & CAN_FLAG_MASK))): \
 (((__FLAG__) >> 8) == 1)? ((((__HANDLE__)->Instance->MSR) & (1U << ((__FLAG__) & CAN_FLAG_MASK))) == (1U << ((__FLAG__) & CAN_FLAG_MASK))): \
 ((((__HANDLE__)->Instance->ESR) & (1U << ((__FLAG__) & CAN_FLAG_MASK))) == (1U << ((__FLAG__) & CAN_FLAG_MASK))))

                                                 
                                                 
                                                  
                                                              
                                                        
                                                        
                                                        
                                                                 
                                                                 
                                                                 
                                                                
                                                                
                                                                
                                                              
                                                  
                                                      
                                                              
                                                  
                                                      
                                              
                                                          
                                                      
    
#define __HAL_CAN_CLEAR_FLAG(__HANDLE__, __FLAG__) \
((((__FLAG__) >> 8U) == 5)? (((__HANDLE__)->Instance->TSR) = (1U << ((__FLAG__) & CAN_FLAG_MASK))): \
 (((__FLAG__) >> 8U) == 2)? (((__HANDLE__)->Instance->RF0R) = (1U << ((__FLAG__) & CAN_FLAG_MASK))): \
 (((__FLAG__) >> 8U) == 4)? (((__HANDLE__)->Instance->RF1R) = (1U << ((__FLAG__) & CAN_FLAG_MASK))): \
 (((__FLAG__) >> 8U) == 1)? (((__HANDLE__)->Instance->MSR) = (1U << ((__FLAG__) & CAN_FLAG_MASK))): 0)


                                                                               
                                                 
                                                                       
                                                              
                                                                       
                                                                       
                                                                       
                                                    
    
#define __HAL_CAN_GET_IT_SOURCE(__HANDLE__, __INTERRUPT__) ((((__HANDLE__)->Instance->IER & (__INTERRUPT__)) == (__INTERRUPT__)) ? SET : RESET)

   
                                                         
                                                 
                                                                                         
                                                            
    
#define __HAL_CAN_TRANSMIT_STATUS(__HANDLE__, __TRANSMITMAILBOX__)\
(((__TRANSMITMAILBOX__) == CAN_TXMAILBOX_0)? ((((__HANDLE__)->Instance->TSR) & (CAN_TSR_RQCP0 | CAN_TSR_TXOK0 | CAN_TSR_TME0)) == (CAN_TSR_RQCP0 | CAN_TSR_TXOK0 | CAN_TSR_TME0)) :\
 ((__TRANSMITMAILBOX__) == CAN_TXMAILBOX_1)? ((((__HANDLE__)->Instance->TSR) & (CAN_TSR_RQCP1 | CAN_TSR_TXOK1 | CAN_TSR_TME1)) == (CAN_TSR_RQCP1 | CAN_TSR_TXOK1 | CAN_TSR_TME1)) :\
 ((((__HANDLE__)->Instance->TSR) & (CAN_TSR_RQCP2 | CAN_TSR_TXOK2 | CAN_TSR_TME2)) == (CAN_TSR_RQCP2 | CAN_TSR_TXOK2 | CAN_TSR_TME2)))



   
                                               
                                   
                                                                        
                
    
#define __HAL_CAN_FIFO_RELEASE(__HANDLE__, __FIFONUMBER__) (((__FIFONUMBER__) == CAN_FIFO0)? \
((__HANDLE__)->Instance->RF0R |= CAN_RF0R_RFOM0) : ((__HANDLE__)->Instance->RF1R |= CAN_RF1R_RFOM1))

   
                                      
                                                 
                                                                                         
                
    
#define __HAL_CAN_CANCEL_TRANSMIT(__HANDLE__, __TRANSMITMAILBOX__)\
(((__TRANSMITMAILBOX__) == CAN_TXMAILBOX_0)? ((__HANDLE__)->Instance->TSR |= CAN_TSR_ABRQ0) :\
 ((__TRANSMITMAILBOX__) == CAN_TXMAILBOX_1)? ((__HANDLE__)->Instance->TSR |= CAN_TSR_ABRQ1) :\
 ((__HANDLE__)->Instance->TSR |= CAN_TSR_ABRQ2))

   
                                                     
                                                 
                                                          
                                                                               
                                                                                   
                                                     
                
    
#define __HAL_CAN_DBG_FREEZE(__HANDLE__, __NEWSTATE__) (((__NEWSTATE__) == ENABLE)? \
((__HANDLE__)->Instance->MCR |= CAN_MCR_DBF) : ((__HANDLE__)->Instance->MCR &= ~CAN_MCR_DBF))

   
     
   

                                                                                
                                                             
      
    

                                                                                          
                                                        
     
   
                                                                            
HAL_StatusTypeDef HAL_CAN_Init(CAN_HandleTypeDef* hcan);
HAL_StatusTypeDef HAL_CAN_ConfigFilter(CAN_HandleTypeDef* hcan, CAN_FilterConfTypeDef* sFilterConfig);
HAL_StatusTypeDef HAL_CAN_DeInit(CAN_HandleTypeDef* hcan);
void HAL_CAN_MspInit(CAN_HandleTypeDef* hcan);
void HAL_CAN_MspDeInit(CAN_HandleTypeDef* hcan);
   
     
   

                                                                                  
                                     
     
   
                                                                                
HAL_StatusTypeDef HAL_CAN_Transmit(CAN_HandleTypeDef *hcan, uint32_t Timeout);
HAL_StatusTypeDef HAL_CAN_Transmit_IT(CAN_HandleTypeDef *hcan);
HAL_StatusTypeDef HAL_CAN_Receive(CAN_HandleTypeDef *hcan, uint8_t FIFONumber, uint32_t Timeout);
HAL_StatusTypeDef HAL_CAN_Receive_IT(CAN_HandleTypeDef *hcan, uint8_t FIFONumber);
HAL_StatusTypeDef HAL_CAN_Sleep(CAN_HandleTypeDef *hcan);
HAL_StatusTypeDef HAL_CAN_WakeUp(CAN_HandleTypeDef *hcan);
void HAL_CAN_IRQHandler(CAN_HandleTypeDef* hcan);
void HAL_CAN_TxCpltCallback(CAN_HandleTypeDef* hcan);
void HAL_CAN_RxCpltCallback(CAN_HandleTypeDef* hcan);
void HAL_CAN_ErrorCallback(CAN_HandleTypeDef *hcan);
   
     
   

                                                                                  
                                           
     
   
                                                                                
uint32_t HAL_CAN_GetError(CAN_HandleTypeDef *hcan);
HAL_CAN_StateTypeDef HAL_CAN_GetState(CAN_HandleTypeDef* hcan);
   
     
   

   
     
   

                                                                                
                                                                                
                                                         
      
    
                                                           
      
    
#define CAN_TXSTATUS_NOMAILBOX      ((uint8_t)0x04)                                                         
   
      
    
#define CAN_FLAG_MASK     ((uint32_t)0x000000FF)


   
      
    

                                                                                
                                                   
      
    

#define IS_CAN_MODE(MODE) (((MODE) == CAN_MODE_NORMAL) || \
                           ((MODE) == CAN_MODE_LOOPBACK)|| \
                           ((MODE) == CAN_MODE_SILENT) || \
                           ((MODE) == CAN_MODE_SILENT_LOOPBACK))

#define IS_CAN_SJW(SJW) (((SJW) == CAN_SJW_1TQ) || ((SJW) == CAN_SJW_2TQ)|| \
                         ((SJW) == CAN_SJW_3TQ) || ((SJW) == CAN_SJW_4TQ))

#define IS_CAN_BS1(BS1) ((BS1) <= CAN_BS1_16TQ)

#define IS_CAN_BS2(BS2) ((BS2) <= CAN_BS2_8TQ)

#define IS_CAN_PRESCALER(PRESCALER) (((PRESCALER) >= 1) && ((PRESCALER) <= 1024))

#define IS_CAN_FILTER_NUMBER(NUMBER) ((NUMBER) <= 27)

#define IS_CAN_FILTER_MODE(MODE) (((MODE) == CAN_FILTERMODE_IDMASK) || \
                                  ((MODE) == CAN_FILTERMODE_IDLIST))

#define IS_CAN_FILTER_SCALE(SCALE) (((SCALE) == CAN_FILTERSCALE_16BIT) || \
                                    ((SCALE) == CAN_FILTERSCALE_32BIT))

#define IS_CAN_FILTER_FIFO(FIFO) (((FIFO) == CAN_FILTER_FIFO0) || \
                                  ((FIFO) == CAN_FILTER_FIFO1))

#define IS_CAN_BANKNUMBER(BANKNUMBER) ((BANKNUMBER) <= 28)

#define IS_CAN_TRANSMITMAILBOX(TRANSMITMAILBOX) ((TRANSMITMAILBOX) <= ((uint8_t)0x02))

#define IS_CAN_STDID(STDID)   ((STDID) <= ((uint32_t)0x7FF))

#define IS_CAN_EXTID(EXTID)   ((EXTID) <= ((uint32_t)0x1FFFFFFF))

#define IS_CAN_DLC(DLC)       ((DLC) <= ((uint8_t)0x08))

#define IS_CAN_IDTYPE(IDTYPE)  (((IDTYPE) == CAN_ID_STD) || \
                                ((IDTYPE) == CAN_ID_EXT))

#define IS_CAN_RTR(RTR) (((RTR) == CAN_RTR_DATA) || ((RTR) == CAN_RTR_REMOTE))

#define IS_CAN_FIFO(FIFO) (((FIFO) == CAN_FIFO0) || ((FIFO) == CAN_FIFO1))

   
      
    

                                                                                

   
      
    

   
      
    
#endif           

#ifdef __cplusplus
}
#endif

#endif                                   
