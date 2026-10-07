/**
  ******************************************************************************
  * @file    stm32l4xx_hal_dma2d.h
  * @author  MCD Application Team
  * @brief   Header file of DMA2D HAL module.
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

                                                                                
#ifndef STM32L4xx_HAL_DMA2D_H
#define STM32L4xx_HAL_DMA2D_H

#ifdef __cplusplus
extern "C" {
#endif

                                                                                
#include "stm32l4xx_hal_def.h"

                                    
      
    

#if defined (DMA2D)

                           
                                  
      
    

                                                                                
                                                       
      
    
#define MAX_DMA2D_LAYER  2U                                        

   
                                          
    
typedef struct
{
  uint32_t *pCLUT;                                                                  

  uint32_t CLUTColorMode;                                                     
                                                                                                  

  uint32_t Size;                                                        
                                                                                                                       
} DMA2D_CLUTCfgTypeDef;

   
                                          
    
typedef struct
{
  uint32_t             Mode;                                                       
                                                                                                      

  uint32_t             ColorMode;                                                               
                                                                                                                   

  uint32_t             OutputOffset;                                       
                                                                                       
                                                                                           
  uint32_t             AlphaInverted;                                                                                       
                                                                                                               

  uint32_t             RedBlueSwap;                                                                        
                                                                                     
                                                                                                        


#if defined(DMA2D_OUTPUT_TWO_BY_TWO_SWAP_SUPPORT)
  uint32_t             BytesSwap;                                                                       
                                                                                                           
#endif                                           

#if defined(DMA2D_LINE_OFFSET_MODE_SUPPORT)
  uint32_t             LineOffsetMode;                                                    
                                                                                         
                                                                                                                 
#endif                                     

} DMA2D_InitTypeDef;


   
                                           
    
typedef struct
{
  uint32_t             InputOffset;                                                                 
                                                                                      
                                                                                          

  uint32_t             InputColorMode;                                                                  
                                                                                                                 

  uint32_t             AlphaMode;                                                                       
                                                                                                           

  uint32_t             InputAlpha;                                                                                     
                                                                              
                                                                                                      
                                                                                                             
                                                                                           
                                                                                      
                                                                                                    
                                                                                                
                                                                                            
                                                                                               
                                                                                                
  uint32_t             AlphaInverted;                                                 
                                                                                                               

  uint32_t             RedBlueSwap;                                                                         
                                                                                                        


} DMA2D_LayerCfgTypeDef;

   
                                                 
    
typedef enum
{
  HAL_DMA2D_STATE_RESET             = 0x00U,                                                       
  HAL_DMA2D_STATE_READY             = 0x01U,                                                       
  HAL_DMA2D_STATE_BUSY              = 0x02U,                                                       
  HAL_DMA2D_STATE_TIMEOUT           = 0x03U,                                                       
  HAL_DMA2D_STATE_ERROR             = 0x04U,                                                       
  HAL_DMA2D_STATE_SUSPEND           = 0x05U                                                        
} HAL_DMA2D_StateTypeDef;

   
                                             
    
typedef struct __DMA2D_HandleTypeDef
{
  DMA2D_TypeDef               *Instance;                                                                                

  DMA2D_InitTypeDef           Init;                                                                                     

  void (* XferCpltCallback)(struct __DMA2D_HandleTypeDef *hdma2d);                                                      

  void (* XferErrorCallback)(struct __DMA2D_HandleTypeDef *hdma2d);                                                     

#if (USE_HAL_DMA2D_REGISTER_CALLBACKS == 1)
  void (* LineEventCallback)(struct __DMA2D_HandleTypeDef *hdma2d);                                                     

  void (* CLUTLoadingCpltCallback)(struct __DMA2D_HandleTypeDef *hdma2d);                                               

  void (* MspInitCallback)(struct __DMA2D_HandleTypeDef *hdma2d);                                                       

  void (* MspDeInitCallback)(struct __DMA2D_HandleTypeDef *hdma2d);                                                     

#endif                                         

  DMA2D_LayerCfgTypeDef       LayerCfg[MAX_DMA2D_LAYER];                                                                

  HAL_LockTypeDef             Lock;                                                                                     

  __IO HAL_DMA2D_StateTypeDef State;                                                                                    

  __IO uint32_t               ErrorCode;                                                                                
} DMA2D_HandleTypeDef;

#if (USE_HAL_DMA2D_REGISTER_CALLBACKS == 1)
   
                                                 
    
typedef void (*pDMA2D_CallbackTypeDef)(DMA2D_HandleTypeDef *hdma2d);                                                    
#endif                                       
   
      
    

                                                                                
                                                               
      
    

                                               
      
    
#define HAL_DMA2D_ERROR_NONE        0x00000000U                              
#define HAL_DMA2D_ERROR_TE          0x00000001U                              
#define HAL_DMA2D_ERROR_CE          0x00000002U                              
#define HAL_DMA2D_ERROR_CAE         0x00000004U                              
#define HAL_DMA2D_ERROR_TIMEOUT     0x00000020U                              
#if (USE_HAL_DMA2D_REGISTER_CALLBACKS == 1)
#define HAL_DMA2D_ERROR_INVALID_CALLBACK 0x00000040U                                 
#endif                                      

   
      
    

                                   
      
    
#define DMA2D_M2M                   0x00000000U                                                                     
#define DMA2D_M2M_PFC               DMA2D_CR_MODE_0                                                                                              
#define DMA2D_M2M_BLEND             DMA2D_CR_MODE_1                                                                               
#define DMA2D_R2M                   (DMA2D_CR_MODE_1 | DMA2D_CR_MODE_0)                                               
#if defined(DMA2D_M2M_BLEND_FIXED_COLOR_FG_BG_SUPPORT)
#define DMA2D_M2M_BLEND_FG          DMA2D_CR_MODE_2                                                                                                  
#define DMA2D_M2M_BLEND_BG          (DMA2D_CR_MODE_2 | DMA2D_CR_MODE_0)                                                                              
#endif                                                
   
      
    

                                                             
      
    
#define DMA2D_OUTPUT_ARGB8888       0x00000000U                                                            
#define DMA2D_OUTPUT_RGB888         DMA2D_OPFCCR_CM_0                                                      
#define DMA2D_OUTPUT_RGB565         DMA2D_OPFCCR_CM_1                                                      
#define DMA2D_OUTPUT_ARGB1555       (DMA2D_OPFCCR_CM_0|DMA2D_OPFCCR_CM_1)                                  
#define DMA2D_OUTPUT_ARGB4444       DMA2D_OPFCCR_CM_2                                                      
   
      
    

                                                           
      
    
#define DMA2D_INPUT_ARGB8888        0x00000000U                             
#define DMA2D_INPUT_RGB888          0x00000001U                             
#define DMA2D_INPUT_RGB565          0x00000002U                             
#define DMA2D_INPUT_ARGB1555        0x00000003U                             
#define DMA2D_INPUT_ARGB4444        0x00000004U                             
#define DMA2D_INPUT_L8              0x00000005U                             
#define DMA2D_INPUT_AL44            0x00000006U                             
#define DMA2D_INPUT_AL88            0x00000007U                             
#define DMA2D_INPUT_L4              0x00000008U                             
#define DMA2D_INPUT_A8              0x00000009U                             
#define DMA2D_INPUT_A4              0x0000000AU                             
   
      
    

                                               
      
    
#define DMA2D_NO_MODIF_ALPHA        0x00000000U                                                                        
#define DMA2D_REPLACE_ALPHA         0x00000001U                                                                        
#define DMA2D_COMBINE_ALPHA         0x00000002U                                                                     
                                                                                                                       
   
      
    

                                                        
      
    
#define DMA2D_REGULAR_ALPHA         0x00000000U                                                    
#define DMA2D_INVERTED_ALPHA        0x00000001U                                        
   
      
    

                                                   
      
    
#define DMA2D_RB_REGULAR            0x00000000U                                           
#define DMA2D_RB_SWAP               0x00000001U                                        
   
      
    



#if defined(DMA2D_LINE_OFFSET_MODE_SUPPORT)
                                                           
      
    
#define DMA2D_LOM_PIXELS            0x00000000U                                            
#define DMA2D_LOM_BYTES             DMA2D_CR_LOM                                          
   
      
    
#endif                                     

#if defined(DMA2D_OUTPUT_TWO_BY_TWO_SWAP_SUPPORT)
                                               
      
    
#define DMA2D_BYTES_REGULAR         0x00000000U                                                   
#define DMA2D_BYTES_SWAP            DMA2D_OPFCCR_SB                                                     
   
      
    
#endif                                           


                                                 
      
    
#define DMA2D_CCM_ARGB8888          0x00000000U                                        
#define DMA2D_CCM_RGB888            0x00000001U                                        
   
      
    

                                               
      
    
#define DMA2D_IT_CE                 DMA2D_CR_CEIE                                                 
#define DMA2D_IT_CTC                DMA2D_CR_CTCIE                                                   
#define DMA2D_IT_CAE                DMA2D_CR_CAEIE                                              
#define DMA2D_IT_TW                 DMA2D_CR_TWIE                                                
#define DMA2D_IT_TC                 DMA2D_CR_TCIE                                               
#define DMA2D_IT_TE                 DMA2D_CR_TEIE                                            
   
      
    

                                     
      
    
#define DMA2D_FLAG_CE               DMA2D_ISR_CEIF                                                     
#define DMA2D_FLAG_CTC              DMA2D_ISR_CTCIF                                                       
#define DMA2D_FLAG_CAE              DMA2D_ISR_CAEIF                                                  
#define DMA2D_FLAG_TW               DMA2D_ISR_TWIF                                                    
#define DMA2D_FLAG_TC               DMA2D_ISR_TCIF                                                   
#define DMA2D_FLAG_TE               DMA2D_ISR_TEIF                                                
   
      
    

#if (USE_HAL_DMA2D_REGISTER_CALLBACKS == 1)
   
                                                               
    
typedef enum
{
  HAL_DMA2D_MSPINIT_CB_ID           = 0x00U,                                                     
  HAL_DMA2D_MSPDEINIT_CB_ID         = 0x01U,                                                     
  HAL_DMA2D_TRANSFERCOMPLETE_CB_ID  = 0x02U,                                                     
  HAL_DMA2D_TRANSFERERROR_CB_ID     = 0x03U,                                                     
  HAL_DMA2D_LINEEVENT_CB_ID         = 0x04U,                                                     
  HAL_DMA2D_CLUTLOADINGCPLT_CB_ID   = 0x05U,                                                     
} HAL_DMA2D_CallbackIDTypeDef;
#endif                                       


   
      
    
                                                                                 
                                                         
      
    

                                   
                                                  
                
    
#if (USE_HAL_DMA2D_REGISTER_CALLBACKS == 1)
#define __HAL_DMA2D_RESET_HANDLE_STATE(__HANDLE__) do{                                             \
                                                       (__HANDLE__)->State = HAL_DMA2D_STATE_RESET;\
                                                       (__HANDLE__)->MspInitCallback = NULL;       \
                                                       (__HANDLE__)->MspDeInitCallback = NULL;     \
                                                     }while(0)
#else
#define __HAL_DMA2D_RESET_HANDLE_STATE(__HANDLE__) ((__HANDLE__)->State = HAL_DMA2D_STATE_RESET)
#endif                                       


   
                             
                                   
                 
    
#define __HAL_DMA2D_ENABLE(__HANDLE__)        ((__HANDLE__)->Instance->CR |= DMA2D_CR_START)


                                 
   
                                        
                                   
                                   
                                                                           
                                                            
                                                               
                                                          
                                                           
                                                          
                                                       
                              
    
#define __HAL_DMA2D_GET_FLAG(__HANDLE__, __FLAG__) ((__HANDLE__)->Instance->ISR & (__FLAG__))

   
                                          
                                   
                                                 
                                                                           
                                                            
                                                               
                                                          
                                                           
                                                          
                                                       
                
    
#define __HAL_DMA2D_CLEAR_FLAG(__HANDLE__, __FLAG__) ((__HANDLE__)->Instance->IFCR = (__FLAG__))

   
                                                  
                                   
                                                                             
                                                                           
                                                                    
                                                                       
                                                                  
                                                                   
                                                                  
                                                               
                
    
#define __HAL_DMA2D_ENABLE_IT(__HANDLE__, __INTERRUPT__) ((__HANDLE__)->Instance->CR |= (__INTERRUPT__))

   
                                                   
                                   
                                                                              
                                                                           
                                                                    
                                                                       
                                                                  
                                                                   
                                                                  
                                                               
                
    
#define __HAL_DMA2D_DISABLE_IT(__HANDLE__, __INTERRUPT__) ((__HANDLE__)->Instance->CR &= ~(__INTERRUPT__))

   
                                                                                 
                                   
                                                                        
                                                               
                                                                    
                                                                       
                                                                  
                                                                   
                                                                  
                                                               
                                          
    
#define __HAL_DMA2D_GET_IT_SOURCE(__HANDLE__, __INTERRUPT__) ((__HANDLE__)->Instance->CR & (__INTERRUPT__))

   
      
    

                                                                                
                                                                 
      
    

                                                                                              
      
    

                                                                                  
HAL_StatusTypeDef HAL_DMA2D_Init(DMA2D_HandleTypeDef *hdma2d);
HAL_StatusTypeDef HAL_DMA2D_DeInit(DMA2D_HandleTypeDef *hdma2d);
void              HAL_DMA2D_MspInit(DMA2D_HandleTypeDef *hdma2d);
void              HAL_DMA2D_MspDeInit(DMA2D_HandleTypeDef *hdma2d);
                                                                                
#if (USE_HAL_DMA2D_REGISTER_CALLBACKS == 1)
HAL_StatusTypeDef HAL_DMA2D_RegisterCallback(DMA2D_HandleTypeDef *hdma2d, HAL_DMA2D_CallbackIDTypeDef CallbackID,
                                             pDMA2D_CallbackTypeDef pCallback);
HAL_StatusTypeDef HAL_DMA2D_UnRegisterCallback(DMA2D_HandleTypeDef *hdma2d, HAL_DMA2D_CallbackIDTypeDef CallbackID);
#endif                                       

   
      
    


                                                                      
      
    

                                                                                  
HAL_StatusTypeDef HAL_DMA2D_Start(DMA2D_HandleTypeDef *hdma2d, uint32_t pdata, uint32_t DstAddress, uint32_t Width,
                                  uint32_t Height);
HAL_StatusTypeDef HAL_DMA2D_BlendingStart(DMA2D_HandleTypeDef *hdma2d, uint32_t SrcAddress1, uint32_t SrcAddress2,
                                          uint32_t DstAddress, uint32_t Width,  uint32_t Height);
HAL_StatusTypeDef HAL_DMA2D_Start_IT(DMA2D_HandleTypeDef *hdma2d, uint32_t pdata, uint32_t DstAddress, uint32_t Width,
                                     uint32_t Height);
HAL_StatusTypeDef HAL_DMA2D_BlendingStart_IT(DMA2D_HandleTypeDef *hdma2d, uint32_t SrcAddress1, uint32_t SrcAddress2,
                                             uint32_t DstAddress, uint32_t Width, uint32_t Height);
HAL_StatusTypeDef HAL_DMA2D_Suspend(DMA2D_HandleTypeDef *hdma2d);
HAL_StatusTypeDef HAL_DMA2D_Resume(DMA2D_HandleTypeDef *hdma2d);
HAL_StatusTypeDef HAL_DMA2D_Abort(DMA2D_HandleTypeDef *hdma2d);
HAL_StatusTypeDef HAL_DMA2D_EnableCLUT(DMA2D_HandleTypeDef *hdma2d, uint32_t LayerIdx);
HAL_StatusTypeDef HAL_DMA2D_CLUTStartLoad(DMA2D_HandleTypeDef *hdma2d, const DMA2D_CLUTCfgTypeDef *CLUTCfg,
                                          uint32_t LayerIdx);
HAL_StatusTypeDef HAL_DMA2D_CLUTStartLoad_IT(DMA2D_HandleTypeDef *hdma2d, const DMA2D_CLUTCfgTypeDef *CLUTCfg,
                                             uint32_t LayerIdx);
HAL_StatusTypeDef HAL_DMA2D_CLUTLoad(DMA2D_HandleTypeDef *hdma2d, DMA2D_CLUTCfgTypeDef CLUTCfg, uint32_t LayerIdx);
HAL_StatusTypeDef HAL_DMA2D_CLUTLoad_IT(DMA2D_HandleTypeDef *hdma2d, DMA2D_CLUTCfgTypeDef CLUTCfg, uint32_t LayerIdx);
HAL_StatusTypeDef HAL_DMA2D_CLUTLoading_Abort(DMA2D_HandleTypeDef *hdma2d, uint32_t LayerIdx);
HAL_StatusTypeDef HAL_DMA2D_CLUTLoading_Suspend(DMA2D_HandleTypeDef *hdma2d, uint32_t LayerIdx);
HAL_StatusTypeDef HAL_DMA2D_CLUTLoading_Resume(DMA2D_HandleTypeDef *hdma2d, uint32_t LayerIdx);
HAL_StatusTypeDef HAL_DMA2D_PollForTransfer(DMA2D_HandleTypeDef *hdma2d, uint32_t Timeout);
void              HAL_DMA2D_IRQHandler(DMA2D_HandleTypeDef *hdma2d);
void              HAL_DMA2D_LineEventCallback(DMA2D_HandleTypeDef *hdma2d);
void              HAL_DMA2D_CLUTLoadingCpltCallback(DMA2D_HandleTypeDef *hdma2d);

   
      
    

                                                                            
      
    

                                                                                  
HAL_StatusTypeDef HAL_DMA2D_ConfigLayer(DMA2D_HandleTypeDef *hdma2d, uint32_t LayerIdx);
HAL_StatusTypeDef HAL_DMA2D_ConfigCLUT(DMA2D_HandleTypeDef *hdma2d, DMA2D_CLUTCfgTypeDef CLUTCfg, uint32_t LayerIdx);
HAL_StatusTypeDef HAL_DMA2D_ProgramLineEvent(DMA2D_HandleTypeDef *hdma2d, uint32_t Line);
HAL_StatusTypeDef HAL_DMA2D_EnableDeadTime(DMA2D_HandleTypeDef *hdma2d);
HAL_StatusTypeDef HAL_DMA2D_DisableDeadTime(DMA2D_HandleTypeDef *hdma2d);
HAL_StatusTypeDef HAL_DMA2D_ConfigDeadTime(DMA2D_HandleTypeDef *hdma2d, uint8_t DeadTime);

   
      
    

                                                                                    
      
    

                                                                                  
HAL_DMA2D_StateTypeDef HAL_DMA2D_GetState(const DMA2D_HandleTypeDef *hdma2d);
uint32_t               HAL_DMA2D_GetError(const DMA2D_HandleTypeDef *hdma2d);

   
      
    

   
      
    

                                                                                

                                                               
      
    

                                                                       
      
    
#define DMA2D_LINE_WATERMARK_MAX            DMA2D_LWR_LW                                           
   
      
    

                                                 
      
    
#define DMA2D_COLOR_VALUE                 0x000000FFU                          
   
      
    

                                                            
      
    
#define DMA2D_MAX_LAYER         2U                                               
   
      
    

                                       
      
    
#define DMA2D_BACKGROUND_LAYER             0x00000000U                                           
#define DMA2D_FOREGROUND_LAYER             0x00000001U                                           
   
      
    

                                       
      
    
#define DMA2D_OFFSET                DMA2D_FGOR_LO                                       
   
      
    

                                   
      
    
#define DMA2D_PIXEL                 (DMA2D_NLR_PL >> 16U)                                                   
#define DMA2D_LINE                  DMA2D_NLR_NL                                                            
   
      
    

                                             
      
    
#define DMA2D_CLUT_SIZE             (DMA2D_FGPFCCR_CS >> 8U)                                 
   
      
    

   
      
    


                                                                                
                                                       
      
    
#define IS_DMA2D_LAYER(LAYER)                 (((LAYER) == DMA2D_BACKGROUND_LAYER)\
                                               || ((LAYER) == DMA2D_FOREGROUND_LAYER))

#if defined(DMA2D_M2M_BLEND_FIXED_COLOR_FG_BG_SUPPORT)
#define IS_DMA2D_MODE(MODE)                   (((MODE) == DMA2D_M2M)          || ((MODE) == DMA2D_M2M_PFC) || \
                                               ((MODE) == DMA2D_M2M_BLEND)    || ((MODE) == DMA2D_R2M)     || \
                                               ((MODE) == DMA2D_M2M_BLEND_FG) || ((MODE) == DMA2D_M2M_BLEND_BG))
#else
#define IS_DMA2D_MODE(MODE)                   (((MODE) == DMA2D_M2M)       || ((MODE) == DMA2D_M2M_PFC) || \
                                               ((MODE) == DMA2D_M2M_BLEND) || ((MODE) == DMA2D_R2M))
#endif                                                

#define IS_DMA2D_CMODE(MODE_ARGB)             (((MODE_ARGB) == DMA2D_OUTPUT_ARGB8888) || \
                                               ((MODE_ARGB) == DMA2D_OUTPUT_RGB888)   || \
                                               ((MODE_ARGB) == DMA2D_OUTPUT_RGB565)   || \
                                               ((MODE_ARGB) == DMA2D_OUTPUT_ARGB1555) || \
                                               ((MODE_ARGB) == DMA2D_OUTPUT_ARGB4444))

#define IS_DMA2D_COLOR(COLOR)                 ((COLOR) <= DMA2D_COLOR_VALUE)
#define IS_DMA2D_LINE(LINE)                   ((LINE) <= DMA2D_LINE)
#define IS_DMA2D_PIXEL(PIXEL)                 ((PIXEL) <= DMA2D_PIXEL)
#define IS_DMA2D_OFFSET(OOFFSET)              ((OOFFSET) <= DMA2D_OFFSET)

#define IS_DMA2D_INPUT_COLOR_MODE(INPUT_CM)   (((INPUT_CM) == DMA2D_INPUT_ARGB8888) || \
                                               ((INPUT_CM) == DMA2D_INPUT_RGB888)   || \
                                               ((INPUT_CM) == DMA2D_INPUT_RGB565)   || \
                                               ((INPUT_CM) == DMA2D_INPUT_ARGB1555) || \
                                               ((INPUT_CM) == DMA2D_INPUT_ARGB4444) || \
                                               ((INPUT_CM) == DMA2D_INPUT_L8)       || \
                                               ((INPUT_CM) == DMA2D_INPUT_AL44)     || \
                                               ((INPUT_CM) == DMA2D_INPUT_AL88)     || \
                                               ((INPUT_CM) == DMA2D_INPUT_L4)       || \
                                               ((INPUT_CM) == DMA2D_INPUT_A8)       || \
                                               ((INPUT_CM) == DMA2D_INPUT_A4))

#define IS_DMA2D_ALPHA_MODE(AlphaMode)        (((AlphaMode) == DMA2D_NO_MODIF_ALPHA) || \
                                               ((AlphaMode) == DMA2D_REPLACE_ALPHA)  || \
                                               ((AlphaMode) == DMA2D_COMBINE_ALPHA))

#define IS_DMA2D_ALPHA_INVERTED(Alpha_Inverted) (((Alpha_Inverted) == DMA2D_REGULAR_ALPHA) || \
                                                 ((Alpha_Inverted) == DMA2D_INVERTED_ALPHA))

#define IS_DMA2D_RB_SWAP(RB_Swap) (((RB_Swap) == DMA2D_RB_REGULAR) || \
                                   ((RB_Swap) == DMA2D_RB_SWAP))

#if defined(DMA2D_LINE_OFFSET_MODE_SUPPORT)
#define IS_DMA2D_LOM_MODE(LOM)          (((LOM) == DMA2D_LOM_PIXELS) || \
                                         ((LOM) == DMA2D_LOM_BYTES))
#endif                                     

#if defined(DMA2D_OUTPUT_TWO_BY_TWO_SWAP_SUPPORT)
#define IS_DMA2D_BYTES_SWAP(BYTES_SWAP) (((BYTES_SWAP) == DMA2D_BYTES_REGULAR) || \
                                         ((BYTES_SWAP) == DMA2D_BYTES_SWAP))
#endif                                           


#define IS_DMA2D_CLUT_CM(CLUT_CM)             (((CLUT_CM) == DMA2D_CCM_ARGB8888) || ((CLUT_CM) == DMA2D_CCM_RGB888))
#define IS_DMA2D_CLUT_SIZE(CLUT_SIZE)         ((CLUT_SIZE) <= DMA2D_CLUT_SIZE)
#define IS_DMA2D_LINEWATERMARK(LineWatermark) ((LineWatermark) <= DMA2D_LINE_WATERMARK_MAX)
#define IS_DMA2D_IT(IT)                       (((IT) == DMA2D_IT_CTC) || ((IT) == DMA2D_IT_CAE) || \
                                               ((IT) == DMA2D_IT_TW)  || ((IT) == DMA2D_IT_TC)  || \
                                               ((IT) == DMA2D_IT_TE)  || ((IT) == DMA2D_IT_CE))
#define IS_DMA2D_GET_FLAG(FLAG)               (((FLAG) == DMA2D_FLAG_CTC) || ((FLAG) == DMA2D_FLAG_CAE) || \
                                               ((FLAG) == DMA2D_FLAG_TW)  || ((FLAG) == DMA2D_FLAG_TC)  || \
                                               ((FLAG) == DMA2D_FLAG_TE)  || ((FLAG) == DMA2D_FLAG_CE))
   
      
    

   
      
    

#endif                      

   
      
    

#ifdef __cplusplus
}
#endif

#endif                            
