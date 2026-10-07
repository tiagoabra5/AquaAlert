/**
  ******************************************************************************
  * @file    stm32l4xx_hal_dcmi.h
  * @author  MCD Application Team
  * @brief   Header file of DCMI HAL module.
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

                                                                                
#ifndef STM32L4xx_HAL_DCMI_H
#define STM32L4xx_HAL_DCMI_H

#ifdef __cplusplus
 extern "C" {
#endif

                                                                                
#include "stm32l4xx_hal_def.h"

#if defined (DCMI)

                                    
      
    

                         
                                 
      
    

                                                                                
                                                     
      
    

   
                                                                         
    
typedef struct
{
  uint8_t FrameStartCode;                                                         
  uint8_t LineStartCode;                                                          
  uint8_t LineEndCode;                                                            
  uint8_t FrameEndCode;                                                           
}DCMI_CodesInitTypeDef;


   
                                                                         
    
typedef struct
{
  uint8_t FrameStartUnmask;                                                    
  uint8_t LineStartUnmask;                                                     
  uint8_t LineEndUnmask;                                                       
  uint8_t FrameEndUnmask;                                                      
}DCMI_SyncUnmaskTypeDef;


   
                                           
    
typedef struct
{
  uint32_t  SynchroMode;                                                                              
                                                                                                               

  uint32_t  PCKPolarity;                                                                           
                                                                                                               

  uint32_t  VSPolarity;                                                                                   
                                                                                                               

  uint32_t  HSPolarity;                                                                                     
                                                                                                               

  uint32_t  CaptureRate;                                                                               
                                                                                                               

  uint32_t  ExtendedDataMode;                                                                          
                                                                                                               

  DCMI_CodesInitTypeDef SynchroCode;                                                                            

  uint32_t JPEGMode;                                                         
                                                                                                               

  uint32_t ByteSelectMode;                                                                     
                                                                                                               

  uint32_t ByteSelectStart;                                                                                      
                                                                                                               

  uint32_t LineSelectMode;                                                                             
                                                                                                               

  uint32_t LineSelectStart;                                                                                              
                                                                                                               
}DCMI_InitTypeDef;


   
                                                
    
typedef enum
{
  HAL_DCMI_STATE_RESET             = 0x00U,                                               
  HAL_DCMI_STATE_READY             = 0x01U,                                               
  HAL_DCMI_STATE_BUSY              = 0x02U,                                               
  HAL_DCMI_STATE_TIMEOUT           = 0x03U,                                               
  HAL_DCMI_STATE_ERROR             = 0x04U,                                               
  HAL_DCMI_STATE_SUSPENDED         = 0x05U                                                
}HAL_DCMI_StateTypeDef;


   
                                            
    
#if (USE_HAL_DCMI_REGISTER_CALLBACKS == 1)
typedef struct __DCMI_HandleTypeDef
#else
typedef struct
#endif                                      
{
  DCMI_TypeDef                  *Instance;                                               

  DCMI_InitTypeDef              Init;                                                    

  HAL_LockTypeDef               Lock;                                                    

  __IO HAL_DCMI_StateTypeDef    State;                                                   

  __IO uint32_t                 XferCount;                                               

  __IO uint32_t                 XferSize;                                                

  uint32_t                      pBuffPtr;                                                

  uint32_t                      XferCount_0;                                              

  uint32_t                      XferSize_0;                                              

  uint32_t                      pBuffPtr_0;                                                           

  DMA_HandleTypeDef             *DMA_Handle;                                             

  DMA_HandleTypeDef             *DMAM2M_Handle;                                                           
                                                                                                             

  __IO uint32_t                 ErrorCode;                                               

  uint32_t                      pCircularBuffer;                                             
                                                                                                             

  uint32_t                      HalfCopyLength;                                     
                                                                                                             

#if (USE_HAL_DCMI_REGISTER_CALLBACKS == 1)
  void    (* FrameEventCallback) ( struct __DCMI_HandleTypeDef *hdcmi);                                   
  void    (* VsyncEventCallback) ( struct __DCMI_HandleTypeDef *hdcmi);                                   
  void    (* LineEventCallback ) ( struct __DCMI_HandleTypeDef *hdcmi);                                   
  void    (* ErrorCallback)      ( struct __DCMI_HandleTypeDef *hdcmi);                                   
  void    (* MspInitCallback)    ( struct __DCMI_HandleTypeDef *hdcmi);                                   
  void    (* MspDeInitCallback)  ( struct __DCMI_HandleTypeDef *hdcmi);                                   
#endif                                       

}DCMI_HandleTypeDef;

#if (USE_HAL_DCMI_REGISTER_CALLBACKS == 1)
typedef enum
{
  HAL_DCMI_FRAME_EVENT_CB_ID    = 0x00U,                                        
  HAL_DCMI_VSYNC_EVENT_CB_ID    = 0x01U,                                        
  HAL_DCMI_LINE_EVENT_CB_ID     = 0x02U,                                        
  HAL_DCMI_ERROR_CB_ID          = 0x03U,                                        
  HAL_DCMI_MSPINIT_CB_ID        = 0x04U,                                        
  HAL_DCMI_MSPDEINIT_CB_ID      = 0x05U                                         

}HAL_DCMI_CallbackIDTypeDef;

typedef void (*pDCMI_CallbackTypeDef)(DCMI_HandleTypeDef *hdcmi);
#endif                                      

   
      
    

                                                                                
                                                             
      
    

                                             
      
    
#define HAL_DCMI_ERROR_NONE             ((uint32_t)0x00000000U)                               
#define HAL_DCMI_ERROR_OVR              ((uint32_t)0x00000001U)                               
#define HAL_DCMI_ERROR_SYNC             ((uint32_t)0x00000002U)                               
#define HAL_DCMI_ERROR_TIMEOUT          ((uint32_t)0x00000020U)                               
#define HAL_DCMI_ERROR_DMA              ((uint32_t)0x00000040U)                               
#if (USE_HAL_DCMI_REGISTER_CALLBACKS == 1)
#define HAL_DCMI_ERROR_INVALID_CALLBACK ((uint32_t)0x00000080U)                                
#endif
   
      
    

                                                 
      
    
#define DCMI_MODE_CONTINUOUS           ((uint32_t)0x00000000U)                                                    
                                                                                                                              
#define DCMI_MODE_SNAPSHOT             ((uint32_t)DCMI_CR_CM)                                                           
                                                                                                                              
   
      
    

                                                                 
      
    
#define DCMI_SYNCHRO_HARDWARE        ((uint32_t)0x00000000U)                                                                    
                                                                                                                                   
#define DCMI_SYNCHRO_EMBEDDED        ((uint32_t)DCMI_CR_ESS)                                                                 
                                                                                                                                   

   
      
    

                                                           
      
    
#define DCMI_PCKPOLARITY_FALLING    ((uint32_t)0x00000000U)                                               
#define DCMI_PCKPOLARITY_RISING     ((uint32_t)DCMI_CR_PCKPOL)                                            

   
      
    

                                                     
      
    
#define DCMI_VSPOLARITY_LOW     ((uint32_t)0x00000000U)                                                
#define DCMI_VSPOLARITY_HIGH    ((uint32_t)DCMI_CR_VSPOL)                                              

   
      
    

                                                     
      
    
#define DCMI_HSPOLARITY_LOW     ((uint32_t)0x00000000U)                                                  
#define DCMI_HSPOLARITY_HIGH    ((uint32_t)DCMI_CR_HSPOL)                                                

   
      
    

                                           
      
    
#define DCMI_JPEG_DISABLE   ((uint32_t)0x00000000U)                              
#define DCMI_JPEG_ENABLE    ((uint32_t)DCMI_CR_JPEG)                             

   
      
    

                                                 
      
    
#define DCMI_CR_ALL_FRAME            ((uint32_t)0x00000000U)                                           
#define DCMI_CR_ALTERNATE_2_FRAME    ((uint32_t)DCMI_CR_FCRC_0)                                        
#define DCMI_CR_ALTERNATE_4_FRAME    ((uint32_t)DCMI_CR_FCRC_1)                                        

   
      
    

                                                             
      
    
#define DCMI_EXTEND_DATA_8B     ((uint32_t)0x00000000U)                                                                                 
#define DCMI_EXTEND_DATA_10B    ((uint32_t)DCMI_CR_EDM_0)                                                                               
#define DCMI_EXTEND_DATA_12B    ((uint32_t)DCMI_CR_EDM_1)                                                                               
#define DCMI_EXTEND_DATA_14B    ((uint32_t)(DCMI_CR_EDM_0 | DCMI_CR_EDM_1))                                                             

   
      
    

                                                         
      
    
#define DCMI_BSM_ALL                 ((uint32_t)0x00000000U)                                             
#define DCMI_BSM_OTHER               ((uint32_t)DCMI_CR_BSM_0)                                                                   
#define DCMI_BSM_ALTERNATE_4         ((uint32_t)DCMI_CR_BSM_1)                                                
#define DCMI_BSM_ALTERNATE_2         ((uint32_t)(DCMI_CR_BSM_0 | DCMI_CR_BSM_1))                                                 

   
      
    

                                                           
      
    
#define DCMI_OEBS_ODD               ((uint32_t)0x00000000U)                                                                                           
#define DCMI_OEBS_EVEN              ((uint32_t)DCMI_CR_OEBS)                                                                                          

   
      
    

                                                         
      
    
#define DCMI_LSM_ALL                 ((uint32_t)0x00000000U)                                              
#define DCMI_LSM_ALTERNATE_2         ((uint32_t)DCMI_CR_LSM)                                               

   
      
    

                                                           
      
    
#define DCMI_OELS_ODD               ((uint32_t)0x00000000U)                                                                                     
#define DCMI_OELS_EVEN              ((uint32_t)DCMI_CR_OELS)                                                                                     

   
      
    


                                                            
      
    
#define DCMI_IT_FRAME    ((uint32_t)DCMI_IER_FRAME_IE)                                           
#define DCMI_IT_OVR      ((uint32_t)DCMI_IER_OVR_IE)                                             
#define DCMI_IT_ERR      ((uint32_t)DCMI_IER_ERR_IE)                                             
#define DCMI_IT_VSYNC    ((uint32_t)DCMI_IER_VSYNC_IE)                                           
#define DCMI_IT_LINE     ((uint32_t)DCMI_IER_LINE_IE)                                            
   
      
    

                                   
      
    

   
                             
    
#define DCMI_FLAG_HSYNC     ((uint32_t)DCMI_SR_INDEX|DCMI_SR_HSYNC)                                                                        
#define DCMI_FLAG_VSYNC     ((uint32_t)DCMI_SR_INDEX|DCMI_SR_VSYNC)                                                                        
#define DCMI_FLAG_FNE       ((uint32_t)DCMI_SR_INDEX|DCMI_SR_FNE)                                                                              
   
                              
    
#define DCMI_FLAG_FRAMERI    ((uint32_t)DCMI_RIS_FRAME_RIS)                                              
#define DCMI_FLAG_OVRRI      ((uint32_t)DCMI_RIS_OVR_RIS)                                                
#define DCMI_FLAG_ERRRI      ((uint32_t)DCMI_RIS_ERR_RIS)                                                
#define DCMI_FLAG_VSYNCRI    ((uint32_t)DCMI_RIS_VSYNC_RIS)                                              
#define DCMI_FLAG_LINERI     ((uint32_t)DCMI_RIS_LINE_RIS)                                               
   
                              
    
#define DCMI_FLAG_FRAMEMI    ((uint32_t)DCMI_MIS_INDEX|DCMI_MIS_FRAME_MIS)                                                            
#define DCMI_FLAG_OVRMI      ((uint32_t)DCMI_MIS_INDEX|DCMI_MIS_OVR_MIS  )                                                            
#define DCMI_FLAG_ERRMI      ((uint32_t)DCMI_MIS_INDEX|DCMI_MIS_ERR_MIS  )                                                            
#define DCMI_FLAG_VSYNCMI    ((uint32_t)DCMI_MIS_INDEX|DCMI_MIS_VSYNC_MIS)                                                            
#define DCMI_FLAG_LINEMI     ((uint32_t)DCMI_MIS_INDEX|DCMI_MIS_LINE_MIS )                                                            
   
      
    

   
      
    

                                                                                
                                                       
      
    

                                  
                                                 
                
    
#if (USE_HAL_DCMI_REGISTER_CALLBACKS == 1)
#define __HAL_DCMI_RESET_HANDLE_STATE(__HANDLE__) do{                                            \
                                                     (__HANDLE__)->State = HAL_DCMI_STATE_RESET; \
                                                     (__HANDLE__)->MspInitCallback = NULL;      \
                                                     (__HANDLE__)->MspDeInitCallback = NULL;    \
                                                   } while(0)
#else
#define __HAL_DCMI_RESET_HANDLE_STATE(__HANDLE__) ((__HANDLE__)->State = HAL_DCMI_STATE_RESET)
#endif                                      

   
                            
                                  
                
    
#define __HAL_DCMI_ENABLE(__HANDLE__)    ((__HANDLE__)->Instance->CR |= DCMI_CR_ENABLE)

   
                             
                                  
                
    
#define __HAL_DCMI_DISABLE(__HANDLE__)   ((__HANDLE__)->Instance->CR &= ~(DCMI_CR_ENABLE))

                                 
   
                                      
                                  
                                            
                                                                                      
                                                                                                  
                                                                                                    
                                                  
                                                                  
                                                 
                                                               
                                                 
                                               
                                                                                    
                                                                         
                                                                                       
                                                                         
                                                                       
                              
    
#define __HAL_DCMI_GET_FLAG(__HANDLE__, __FLAG__)\
 ((((__FLAG__) & (DCMI_SR_INDEX|DCMI_MIS_INDEX)) == 0x0U)? ((__HANDLE__)->Instance->RISR & (__FLAG__)) :\
 (((__FLAG__) & DCMI_SR_INDEX) == 0x0U)? ((__HANDLE__)->Instance->MISR & (__FLAG__)) : ((__HANDLE__)->Instance->SR & (__FLAG__)))

   
                                        
                                  
                                                 
                                                                          
                                                                  
                                                 
                                                               
                                                 
                                               
                
    
#define __HAL_DCMI_CLEAR_FLAG(__HANDLE__, __FLAG__) ((__HANDLE__)->Instance->ICR = (__FLAG__))

   
                                                 
                                  
                                                                             
                                                                          
                                                                   
                                                  
                                                                
                                                  
                                                
                
    
#define __HAL_DCMI_ENABLE_IT(__HANDLE__, __INTERRUPT__) ((__HANDLE__)->Instance->IER |= (__INTERRUPT__))

   
                                                  
                                  
                                                                             
                                                                          
                                                                   
                                                  
                                                                
                                                  
                                                
                
    
#define __HAL_DCMI_DISABLE_IT(__HANDLE__, __INTERRUPT__) ((__HANDLE__)->Instance->IER &= ~(__INTERRUPT__))

   
                                                                           
                                                                           
                                                                         
                                  
                                                                                
                                                              
                                                                        
                                                       
                                                                     
                                                       
                                                     
                                   
    
#define __HAL_DCMI_GET_IT_SOURCE(__HANDLE__, __INTERRUPT__) ((__HANDLE__)->Instance->MIS & (__INTERRUPT__))

   
      
    

                                                                                
                                       
      
    

                                                                                         
     
   

                                                                                
HAL_StatusTypeDef HAL_DCMI_Init(DCMI_HandleTypeDef *hdcmi);
HAL_StatusTypeDef HAL_DCMI_DeInit(DCMI_HandleTypeDef *hdcmi);
void       HAL_DCMI_MspInit(DCMI_HandleTypeDef* hdcmi);
void       HAL_DCMI_MspDeInit(DCMI_HandleTypeDef* hdcmi);

                                                                                
#if (USE_HAL_DCMI_REGISTER_CALLBACKS == 1)
HAL_StatusTypeDef HAL_DCMI_RegisterCallback(DCMI_HandleTypeDef *hdcmi, HAL_DCMI_CallbackIDTypeDef CallbackID, pDCMI_CallbackTypeDef pCallback);
HAL_StatusTypeDef HAL_DCMI_UnRegisterCallback(DCMI_HandleTypeDef *hdcmi, HAL_DCMI_CallbackIDTypeDef CallbackID);
#endif                                      
   
      
    

                                                                     
     
   

                                                                                
HAL_StatusTypeDef HAL_DCMI_Start_DMA(DCMI_HandleTypeDef* hdcmi, uint32_t DCMI_Mode, uint32_t pData, uint32_t Length);
HAL_StatusTypeDef HAL_DCMI_Stop(DCMI_HandleTypeDef* hdcmi);
HAL_StatusTypeDef HAL_DCMI_Suspend(DCMI_HandleTypeDef* hdcmi);
HAL_StatusTypeDef HAL_DCMI_Resume(DCMI_HandleTypeDef* hdcmi);
void              HAL_DCMI_ErrorCallback(DCMI_HandleTypeDef *hdcmi);
void              HAL_DCMI_LineEventCallback(DCMI_HandleTypeDef *hdcmi);
void              HAL_DCMI_FrameEventCallback(DCMI_HandleTypeDef *hdcmi);
void              HAL_DCMI_VsyncEventCallback(DCMI_HandleTypeDef *hdcmi);
void              HAL_DCMI_IRQHandler(DCMI_HandleTypeDef *hdcmi);
   
      
    

                                                                           
     
   
                                                                                
HAL_StatusTypeDef     HAL_DCMI_ConfigCrop(DCMI_HandleTypeDef *hdcmi, uint32_t X0, uint32_t Y0, uint32_t XSize, uint32_t YSize);
HAL_StatusTypeDef     HAL_DCMI_EnableCrop(DCMI_HandleTypeDef *hdcmi);
HAL_StatusTypeDef     HAL_DCMI_DisableCrop(DCMI_HandleTypeDef *hdcmi);
HAL_StatusTypeDef     HAL_DCMI_ConfigSyncUnmask(DCMI_HandleTypeDef *hdcmi, DCMI_SyncUnmaskTypeDef *SyncUnmask);
   
      
    

                                                                         
     
   
                                                                                
HAL_DCMI_StateTypeDef HAL_DCMI_GetState(DCMI_HandleTypeDef *hdcmi);
uint32_t              HAL_DCMI_GetError(DCMI_HandleTypeDef *hdcmi);
   
      
    

   
      
    

                                                                                
                                                                                
                                                                                
                                                             
      
    

                                                           
      
    
#define DCMI_MIS_INDEX        (0x1000U)                                        
#define DCMI_SR_INDEX         (0x2000U)                                       
   
      
    

                                                           
      
    
#define DCMI_WINDOW_COORDINATE    ((uint32_t)0x3FFFU)                           
   
      
    

                                                   
      
    
#define DCMI_WINDOW_HEIGHT    ((uint32_t)0x1FFFU)                       
   
      
    

   
      
    

                                                                                
                                                     
      
    
#define IS_DCMI_CAPTURE_MODE(MODE)(((MODE) == DCMI_MODE_CONTINUOUS) || \
                                   ((MODE) == DCMI_MODE_SNAPSHOT))

#define IS_DCMI_SYNCHRO(MODE)(((MODE) == DCMI_SYNCHRO_HARDWARE) || \
                              ((MODE) == DCMI_SYNCHRO_EMBEDDED))

#define IS_DCMI_PCKPOLARITY(POLARITY)(((POLARITY) == DCMI_PCKPOLARITY_FALLING) || \
                                      ((POLARITY) == DCMI_PCKPOLARITY_RISING))

#define IS_DCMI_VSPOLARITY(POLARITY)(((POLARITY) == DCMI_VSPOLARITY_LOW) || \
                                     ((POLARITY) == DCMI_VSPOLARITY_HIGH))

#define IS_DCMI_HSPOLARITY(POLARITY)(((POLARITY) == DCMI_HSPOLARITY_LOW) || \
                                     ((POLARITY) == DCMI_HSPOLARITY_HIGH))

#define IS_DCMI_MODE_JPEG(JPEG_MODE)(((JPEG_MODE) == DCMI_JPEG_DISABLE) || \
                                     ((JPEG_MODE) == DCMI_JPEG_ENABLE))

#define IS_DCMI_CAPTURE_RATE(RATE) (((RATE) == DCMI_CR_ALL_FRAME)         || \
                                    ((RATE) == DCMI_CR_ALTERNATE_2_FRAME) || \
                                    ((RATE) == DCMI_CR_ALTERNATE_4_FRAME))

#define IS_DCMI_EXTENDED_DATA(DATA)(((DATA) == DCMI_EXTEND_DATA_8B)  || \
                                    ((DATA) == DCMI_EXTEND_DATA_10B) || \
                                    ((DATA) == DCMI_EXTEND_DATA_12B) || \
                                    ((DATA) == DCMI_EXTEND_DATA_14B))

#define IS_DCMI_WINDOW_COORDINATE(COORDINATE) ((COORDINATE) <= DCMI_WINDOW_COORDINATE)

#define IS_DCMI_WINDOW_HEIGHT(HEIGHT) ((HEIGHT) <= DCMI_WINDOW_HEIGHT)

#define IS_DCMI_BYTE_SELECT_MODE(MODE)(((MODE) == DCMI_BSM_ALL) || \
                                       ((MODE) == DCMI_BSM_OTHER) || \
                                       ((MODE) == DCMI_BSM_ALTERNATE_4) || \
                                       ((MODE) == DCMI_BSM_ALTERNATE_2))

#define IS_DCMI_BYTE_SELECT_START(POLARITY)(((POLARITY) == DCMI_OEBS_ODD) || \
                                            ((POLARITY) == DCMI_OEBS_EVEN))

#define IS_DCMI_LINE_SELECT_MODE(MODE)(((MODE) == DCMI_LSM_ALL) || \
                                       ((MODE) == DCMI_LSM_ALTERNATE_2))

#define IS_DCMI_LINE_SELECT_START(POLARITY)(((POLARITY) == DCMI_OELS_ODD) || \
                                            ((POLARITY) == DCMI_OELS_EVEN))

   
      
    

   
      
    

   
      
    

#endif           

#ifdef __cplusplus
}
#endif

#endif                           
