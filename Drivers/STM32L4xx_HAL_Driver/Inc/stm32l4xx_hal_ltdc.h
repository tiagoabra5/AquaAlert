/**
  ******************************************************************************
  * @file    stm32l4xx_hal_ltdc.h
  * @author  MCD Application Team
  * @brief   Header file of LTDC HAL module.
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

                                                                                
#ifndef STM32L4xx_HAL_LTDC_H
#define STM32L4xx_HAL_LTDC_H

#ifdef __cplusplus
extern "C" {
#endif

                                                                                
#include "stm32l4xx_hal_def.h"

#if defined (LTDC)

                                    
      
    

                       
                                 
      
    

                                                                                
                                                     
      
    
#if defined(LTDC_Layer2_BASE)
#define MAX_LAYER  2U
#elif defined(LTDC_Layer1_BASE)
#define MAX_LAYER  1U
#endif

   
                                           
    
typedef struct
{
  uint8_t Blue;                                                   
                                                                                                                       

  uint8_t Green;                                                   
                                                                                                                       

  uint8_t Red;                                                   
                                                                                                                       

  uint8_t Reserved;                                     
} LTDC_ColorTypeDef;

   
                                          
    
typedef struct
{
  uint32_t            HSPolarity;                                                                        
                                                                                                                 

  uint32_t            VSPolarity;                                                                      
                                                                                                                 

  uint32_t            DEPolarity;                                                         
                                                                                                                    

  uint32_t            PCPolarity;                                                         
                                                                                                                    

  uint32_t            HorizontalSync;                                                                           
                                                                                             
                                                                                               

  uint32_t            VerticalSync;                                                                            
                                                                                             
                                                                                               

  uint32_t            AccumulatedHBP;                                                                        
                                                                                             
                                                                                                             

  uint32_t            AccumulatedVBP;                                                                       
                                                                                             
                                                                                                           

  uint32_t            AccumulatedActiveW;                                                     
                                                                                             
                                                                                                             

  uint32_t            AccumulatedActiveH;                                                      
                                                                                             
                                                                                                             

  uint32_t            TotalWidth;                                                
                                                                                             
                                                                                                                 

  uint32_t            TotalHeigh;                                                 
                                                                                             
                                                                                                                 

  LTDC_ColorTypeDef   Backcolor;                                                         
} LTDC_InitTypeDef;

   
                                           
    
typedef struct
{
  uint32_t WindowX0;                                                                        
                                                                                   
                                                                                     

  uint32_t WindowX1;                                                                       
                                                                                   
                                                                                     

  uint32_t WindowY0;                                                                      
                                                                                   
                                                                                     

  uint32_t WindowY1;                                                                     
                                                                                   
                                                                                      

  uint32_t PixelFormat;                                                
                                                                                                          

  uint32_t Alpha;                                                                          
                                                                                   
                                                                                   

  uint32_t Alpha0;                                                             
                                                                                   
                                                                                   

  uint32_t BlendingFactor1;                                              
                                                                                                              

  uint32_t BlendingFactor2;                                              
                                                                                                              

  uint32_t FBStartAdress;                                                               

  uint32_t ImageWidth;                                                                    
                                                                                   
                                                                                       

  uint32_t ImageHeight;                                                                  
                                                                                   
                                                                                     

  LTDC_ColorTypeDef   Backcolor;                                                     
} LTDC_LayerCfgTypeDef;

   
                                                
    
typedef enum
{
  HAL_LTDC_STATE_RESET             = 0x00U,                                                
  HAL_LTDC_STATE_READY             = 0x01U,                                                
  HAL_LTDC_STATE_BUSY              = 0x02U,                                                
  HAL_LTDC_STATE_TIMEOUT           = 0x03U,                                                
  HAL_LTDC_STATE_ERROR             = 0x04U                                                 
} HAL_LTDC_StateTypeDef;

   
                                            
    
#if (USE_HAL_LTDC_REGISTER_CALLBACKS == 1)
typedef struct __LTDC_HandleTypeDef
#else
typedef struct
#endif                                      
{
  LTDC_TypeDef                *Instance;                                                                 

  LTDC_InitTypeDef            Init;                                                                      

  LTDC_LayerCfgTypeDef        LayerCfg[MAX_LAYER];                                                       

  HAL_LockTypeDef             Lock;                                                                      

  __IO HAL_LTDC_StateTypeDef  State;                                                                     

  __IO uint32_t               ErrorCode;                                                                 

#if (USE_HAL_LTDC_REGISTER_CALLBACKS == 1)
  void (* LineEventCallback)(struct __LTDC_HandleTypeDef *hltdc);                                        
  void (* ReloadEventCallback)(struct __LTDC_HandleTypeDef *hltdc);                                      
  void (* ErrorCallback)(struct __LTDC_HandleTypeDef *hltdc);                                            

  void (* MspInitCallback)(struct __LTDC_HandleTypeDef *hltdc);                                          
  void (* MspDeInitCallback)(struct __LTDC_HandleTypeDef *hltdc);                                        

#endif                                      


} LTDC_HandleTypeDef;

#if (USE_HAL_LTDC_REGISTER_CALLBACKS == 1)
   
                                                       
    
typedef enum
{
  HAL_LTDC_MSPINIT_CB_ID            = 0x00U,                                          
  HAL_LTDC_MSPDEINIT_CB_ID          = 0x01U,                                          

  HAL_LTDC_LINE_EVENT_CB_ID         = 0x02U,                                          
  HAL_LTDC_RELOAD_EVENT_CB_ID       = 0x03U,                                          
  HAL_LTDC_ERROR_CB_ID              = 0x04U                                           

} HAL_LTDC_CallbackIDTypeDef;

   
                                                
    
typedef  void (*pLTDC_CallbackTypeDef)(LTDC_HandleTypeDef *hltdc);                                              

#endif                                      

   
      
    

                                                                                
                                                             
      
    

                                             
      
    
#define HAL_LTDC_ERROR_NONE               0x00000000U                                    
#define HAL_LTDC_ERROR_TE                 0x00000001U                                    
#define HAL_LTDC_ERROR_FU                 0x00000002U                                    
#define HAL_LTDC_ERROR_TIMEOUT            0x00000020U                                    
#if (USE_HAL_LTDC_REGISTER_CALLBACKS == 1)
#define  HAL_LTDC_ERROR_INVALID_CALLBACK  0x00000040U                                       
#endif                                      
   
      
    

                                   
      
    
#if defined(LTDC_Layer1_BASE)
#define LTDC_LAYER_1                      0x00000000U                       
#endif
#if defined(LTDC_Layer2_BASE)
#define LTDC_LAYER_2                      0x00000001U                       
#endif
   
      
    

                                               
      
    
#define LTDC_HSPOLARITY_AL                0x00000000U                                                    
#define LTDC_HSPOLARITY_AH                LTDC_GCR_HSPOL                                                              
   
      
    

                                               
      
    
#define LTDC_VSPOLARITY_AL                0x00000000U                                                  
#define LTDC_VSPOLARITY_AH                LTDC_GCR_VSPOL                                                            
   
      
    

                                               
      
    
#define LTDC_DEPOLARITY_AL                0x00000000U                                      
#define LTDC_DEPOLARITY_AH                LTDC_GCR_DEPOL                                                
   
      
    

                                               
      
    
#define LTDC_PCPOLARITY_IPC               0x00000000U                             
#define LTDC_PCPOLARITY_IIPC              LTDC_GCR_PCPOL                                               
   
      
    

                                 
      
    
#define LTDC_HORIZONTALSYNC               (LTDC_SSCR_HSW >> 16U)                                             
#define LTDC_VERTICALSYNC                 LTDC_SSCR_VSH                                                     
   
      
    

                                             
      
    
#define LTDC_COLOR                        0x000000FFU                     
   
      
    

                                                        
      
    
#define LTDC_BLENDING_FACTOR1_CA          0x00000400U                                      
#define LTDC_BLENDING_FACTOR1_PAxCA       0x00000600U                                                   
   
      
    

                                                        
      
    
#define LTDC_BLENDING_FACTOR2_CA          0x00000005U                                      
#define LTDC_BLENDING_FACTOR2_PAxCA       0x00000007U                                                   
   
      
    

                                                
      
    
#define LTDC_PIXEL_FORMAT_ARGB8888        0x00000000U                                                 
#define LTDC_PIXEL_FORMAT_RGB888          0x00000001U                                                 
#define LTDC_PIXEL_FORMAT_RGB565          0x00000002U                                                 
#define LTDC_PIXEL_FORMAT_ARGB1555        0x00000003U                                                 
#define LTDC_PIXEL_FORMAT_ARGB4444        0x00000004U                                                 
#define LTDC_PIXEL_FORMAT_L8              0x00000005U                                                 
#define LTDC_PIXEL_FORMAT_AL44            0x00000006U                                                 
#define LTDC_PIXEL_FORMAT_AL88            0x00000007U                                                 
   
      
    

                                   
      
    
#define LTDC_ALPHA                        LTDC_LxCACR_CONSTA                                        
   
      
    

                                                 
      
    
#define LTDC_STOPPOSITION                 (LTDC_LxWHPCR_WHSPPOS >> 16U)                                  
#define LTDC_STARTPOSITION                LTDC_LxWHPCR_WHSTPOS                                           

#define LTDC_COLOR_FRAME_BUFFER           LTDC_LxCFBLR_CFBLL                                             
#define LTDC_LINE_NUMBER                  LTDC_LxCFBLNR_CFBLNBR                                          
   
      
    

                                             
      
    
#define LTDC_IT_LI                        LTDC_IER_LIE                                                    
#define LTDC_IT_FU                        LTDC_IER_FUIE                                                   
#define LTDC_IT_TE                        LTDC_IER_TERRIE                                                 
#define LTDC_IT_RR                        LTDC_IER_RRIE                                                   
   
      
    

                                   
      
    
#define LTDC_FLAG_LI                      LTDC_ISR_LIF                                                         
#define LTDC_FLAG_FU                      LTDC_ISR_FUIF                                                        
#define LTDC_FLAG_TE                      LTDC_ISR_TERRIF                                                      
#define LTDC_FLAG_RR                      LTDC_ISR_RRIF                                                        
   
      
    

                                               
      
    
#define LTDC_RELOAD_IMMEDIATE             LTDC_SRCR_IMR                                     
#define LTDC_RELOAD_VERTICAL_BLANKING     LTDC_SRCR_VBR                                             
   
      
    

   
      
    

                                                                                
                                                       
      
    

                                   
                                   
                
    
#if (USE_HAL_LTDC_REGISTER_CALLBACKS == 1)
#define __HAL_LTDC_RESET_HANDLE_STATE(__HANDLE__) do{                                                 \
                                                      (__HANDLE__)->State = HAL_LTDC_STATE_RESET;     \
                                                      (__HANDLE__)->MspInitCallback = NULL;           \
                                                      (__HANDLE__)->MspDeInitCallback = NULL;         \
                                                    } while(0)
#else
#define __HAL_LTDC_RESET_HANDLE_STATE(__HANDLE__) ((__HANDLE__)->State = HAL_LTDC_STATE_RESET)
#endif                                     

   
                            
                                   
                 
    
#define __HAL_LTDC_ENABLE(__HANDLE__)    ((__HANDLE__)->Instance->GCR |= LTDC_GCR_LTDCEN)

   
                             
                                   
                 
    
#define __HAL_LTDC_DISABLE(__HANDLE__)   ((__HANDLE__)->Instance->GCR &= ~(LTDC_GCR_LTDCEN))

   
                                  
                                   
                                                        
                                                                                   
                 
    
#define __HAL_LTDC_LAYER_ENABLE(__HANDLE__, __LAYER__)  ((LTDC_LAYER((__HANDLE__), (__LAYER__)))->CR\
                                                         |= (uint32_t)LTDC_LxCR_LEN)

   
                                   
                                   
                                                         
                                                                                   
                 
    
#define __HAL_LTDC_LAYER_DISABLE(__HANDLE__, __LAYER__) ((LTDC_LAYER((__HANDLE__), (__LAYER__)))->CR\
                                                         &= ~(uint32_t)LTDC_LxCR_LEN)

   
                                               
                                   
                 
    
#define __HAL_LTDC_RELOAD_IMMEDIATE_CONFIG(__HANDLE__)  ((__HANDLE__)->Instance->SRCR |= LTDC_SRCR_IMR)

   
                                                                   
                                   
                 
    
#define __HAL_LTDC_VERTICAL_BLANKING_RELOAD_CONFIG(__HANDLE__)  ((__HANDLE__)->Instance->SRCR |= LTDC_SRCR_VBR)

                                 
   
                                       
                                   
                                               
                                                                           
                                                     
                                                              
                                                               
                                                                
                                             
    
#define __HAL_LTDC_GET_FLAG(__HANDLE__, __FLAG__) ((__HANDLE__)->Instance->ISR & (__FLAG__))

   
                                          
                                   
                                                  
                                                                           
                                                     
                                                              
                                                               
                                                                
                
    
#define __HAL_LTDC_CLEAR_FLAG(__HANDLE__, __FLAG__) ((__HANDLE__)->Instance->ICR = (__FLAG__))

   
                                                  
                                   
                                                                          
                                                                           
                                                   
                                                            
                                                             
                                                              
                
    
#define __HAL_LTDC_ENABLE_IT(__HANDLE__, __INTERRUPT__) ((__HANDLE__)->Instance->IER |= (__INTERRUPT__))

   
                                                   
                                   
                                                                           
                                                                           
                                                   
                                                            
                                                             
                                                              
                
    
#define __HAL_LTDC_DISABLE_IT(__HANDLE__, __INTERRUPT__) ((__HANDLE__)->Instance->IER &= ~(__INTERRUPT__))

   
                                                                           
                                   
                                                                    
                                                               
                                                   
                                                            
                                                             
                                                              
                                                  
    
#define __HAL_LTDC_GET_IT_SOURCE(__HANDLE__, __INTERRUPT__) ((__HANDLE__)->Instance->IER & (__INTERRUPT__))
   
      
    

                                       
#include "stm32l4xx_hal_ltdc_ex.h"

                                                                                
                                       
      
    
                                              
      
    
                                                                                
HAL_StatusTypeDef HAL_LTDC_Init(LTDC_HandleTypeDef *hltdc);
HAL_StatusTypeDef HAL_LTDC_DeInit(LTDC_HandleTypeDef *hltdc);
void HAL_LTDC_MspInit(LTDC_HandleTypeDef *hltdc);
void HAL_LTDC_MspDeInit(LTDC_HandleTypeDef *hltdc);
void HAL_LTDC_ErrorCallback(LTDC_HandleTypeDef *hltdc);
void HAL_LTDC_LineEventCallback(LTDC_HandleTypeDef *hltdc);
void HAL_LTDC_ReloadEventCallback(LTDC_HandleTypeDef *hltdc);

                                                                                
#if (USE_HAL_LTDC_REGISTER_CALLBACKS == 1)
HAL_StatusTypeDef HAL_LTDC_RegisterCallback(LTDC_HandleTypeDef *hltdc, HAL_LTDC_CallbackIDTypeDef CallbackID,
                                            pLTDC_CallbackTypeDef pCallback);
HAL_StatusTypeDef HAL_LTDC_UnRegisterCallback(LTDC_HandleTypeDef *hltdc, HAL_LTDC_CallbackIDTypeDef CallbackID);
#endif                                      

   
      
    

                                              
      
    
                                                                                
void  HAL_LTDC_IRQHandler(LTDC_HandleTypeDef *hltdc);
   
      
    

                                              
      
    
                                                                                
HAL_StatusTypeDef HAL_LTDC_ConfigLayer(LTDC_HandleTypeDef *hltdc, LTDC_LayerCfgTypeDef *pLayerCfg, uint32_t LayerIdx);
HAL_StatusTypeDef HAL_LTDC_SetWindowSize(LTDC_HandleTypeDef *hltdc, uint32_t XSize, uint32_t YSize, uint32_t LayerIdx);
HAL_StatusTypeDef HAL_LTDC_SetWindowPosition(LTDC_HandleTypeDef *hltdc, uint32_t X0, uint32_t Y0, uint32_t LayerIdx);
HAL_StatusTypeDef HAL_LTDC_SetPixelFormat(LTDC_HandleTypeDef *hltdc, uint32_t Pixelformat, uint32_t LayerIdx);
HAL_StatusTypeDef HAL_LTDC_SetAlpha(LTDC_HandleTypeDef *hltdc, uint32_t Alpha, uint32_t LayerIdx);
HAL_StatusTypeDef HAL_LTDC_SetAddress(LTDC_HandleTypeDef *hltdc, uint32_t Address, uint32_t LayerIdx);
HAL_StatusTypeDef HAL_LTDC_SetPitch(LTDC_HandleTypeDef *hltdc, uint32_t LinePitchInPixels, uint32_t LayerIdx);
HAL_StatusTypeDef HAL_LTDC_ConfigColorKeying(LTDC_HandleTypeDef *hltdc, uint32_t RGBValue, uint32_t LayerIdx);
HAL_StatusTypeDef HAL_LTDC_ConfigCLUT(LTDC_HandleTypeDef *hltdc, const uint32_t *pCLUT, uint32_t CLUTSize,
                                      uint32_t LayerIdx);
HAL_StatusTypeDef HAL_LTDC_EnableColorKeying(LTDC_HandleTypeDef *hltdc, uint32_t LayerIdx);
HAL_StatusTypeDef HAL_LTDC_DisableColorKeying(LTDC_HandleTypeDef *hltdc, uint32_t LayerIdx);
HAL_StatusTypeDef HAL_LTDC_EnableCLUT(LTDC_HandleTypeDef *hltdc, uint32_t LayerIdx);
HAL_StatusTypeDef HAL_LTDC_DisableCLUT(LTDC_HandleTypeDef *hltdc, uint32_t LayerIdx);
HAL_StatusTypeDef HAL_LTDC_ProgramLineEvent(LTDC_HandleTypeDef *hltdc, uint32_t Line);
HAL_StatusTypeDef HAL_LTDC_EnableDither(LTDC_HandleTypeDef *hltdc);
HAL_StatusTypeDef HAL_LTDC_DisableDither(LTDC_HandleTypeDef *hltdc);
HAL_StatusTypeDef HAL_LTDC_Reload(LTDC_HandleTypeDef *hltdc, uint32_t ReloadType);
HAL_StatusTypeDef HAL_LTDC_ConfigLayer_NoReload(LTDC_HandleTypeDef *hltdc, LTDC_LayerCfgTypeDef *pLayerCfg,
                                                uint32_t LayerIdx);
HAL_StatusTypeDef HAL_LTDC_SetWindowSize_NoReload(LTDC_HandleTypeDef *hltdc, uint32_t XSize, uint32_t YSize,
                                                  uint32_t LayerIdx);
HAL_StatusTypeDef HAL_LTDC_SetWindowPosition_NoReload(LTDC_HandleTypeDef *hltdc, uint32_t X0, uint32_t Y0,
                                                      uint32_t LayerIdx);
HAL_StatusTypeDef HAL_LTDC_SetPixelFormat_NoReload(LTDC_HandleTypeDef *hltdc, uint32_t Pixelformat, uint32_t LayerIdx);
HAL_StatusTypeDef HAL_LTDC_SetAlpha_NoReload(LTDC_HandleTypeDef *hltdc, uint32_t Alpha, uint32_t LayerIdx);
HAL_StatusTypeDef HAL_LTDC_SetAddress_NoReload(LTDC_HandleTypeDef *hltdc, uint32_t Address, uint32_t LayerIdx);
HAL_StatusTypeDef HAL_LTDC_SetPitch_NoReload(LTDC_HandleTypeDef *hltdc, uint32_t LinePitchInPixels, uint32_t LayerIdx);
HAL_StatusTypeDef HAL_LTDC_ConfigColorKeying_NoReload(LTDC_HandleTypeDef *hltdc, uint32_t RGBValue, uint32_t LayerIdx);
HAL_StatusTypeDef HAL_LTDC_EnableColorKeying_NoReload(LTDC_HandleTypeDef *hltdc, uint32_t LayerIdx);
HAL_StatusTypeDef HAL_LTDC_DisableColorKeying_NoReload(LTDC_HandleTypeDef *hltdc, uint32_t LayerIdx);
HAL_StatusTypeDef HAL_LTDC_EnableCLUT_NoReload(LTDC_HandleTypeDef *hltdc, uint32_t LayerIdx);
HAL_StatusTypeDef HAL_LTDC_DisableCLUT_NoReload(LTDC_HandleTypeDef *hltdc, uint32_t LayerIdx);

   
      
    

                                              
      
    
                                                                                
HAL_LTDC_StateTypeDef HAL_LTDC_GetState(const LTDC_HandleTypeDef *hltdc);
uint32_t              HAL_LTDC_GetError(const LTDC_HandleTypeDef *hltdc);
   
      
    

   
      
    

                                                                                
                                                                                
                                                                                
                                                                                
                                                     
      
    
#define LTDC_LAYER(__HANDLE__, __LAYER__)              ((LTDC_Layer_TypeDef *)((uint32_t)(\
                                                                               ((uint32_t)((__HANDLE__)->Instance))\
                                                                               + 0x84U + (0x80U*(__LAYER__)))))
#define IS_LTDC_LAYER(__LAYER__)                       ((__LAYER__) < MAX_LAYER)
#define IS_LTDC_HSPOL(__HSPOL__)                       (((__HSPOL__) == LTDC_HSPOLARITY_AL)\
                                                        || ((__HSPOL__) == LTDC_HSPOLARITY_AH))
#define IS_LTDC_VSPOL(__VSPOL__)                       (((__VSPOL__) == LTDC_VSPOLARITY_AL)\
                                                        || ((__VSPOL__) == LTDC_VSPOLARITY_AH))
#define IS_LTDC_DEPOL(__DEPOL__)                       (((__DEPOL__) == LTDC_DEPOLARITY_AL)\
                                                        || ((__DEPOL__) ==  LTDC_DEPOLARITY_AH))
#define IS_LTDC_PCPOL(__PCPOL__)                       (((__PCPOL__) == LTDC_PCPOLARITY_IPC)\
                                                        || ((__PCPOL__) ==  LTDC_PCPOLARITY_IIPC))
#define IS_LTDC_HSYNC(__HSYNC__)                       ((__HSYNC__)  <= LTDC_HORIZONTALSYNC)
#define IS_LTDC_VSYNC(__VSYNC__)                       ((__VSYNC__)  <= LTDC_VERTICALSYNC)
#define IS_LTDC_AHBP(__AHBP__)                         ((__AHBP__)   <= LTDC_HORIZONTALSYNC)
#define IS_LTDC_AVBP(__AVBP__)                         ((__AVBP__)   <= LTDC_VERTICALSYNC)
#define IS_LTDC_AAW(__AAW__)                           ((__AAW__)    <= LTDC_HORIZONTALSYNC)
#define IS_LTDC_AAH(__AAH__)                           ((__AAH__)    <= LTDC_VERTICALSYNC)
#define IS_LTDC_TOTALW(__TOTALW__)                     ((__TOTALW__) <= LTDC_HORIZONTALSYNC)
#define IS_LTDC_TOTALH(__TOTALH__)                     ((__TOTALH__) <= LTDC_VERTICALSYNC)
#define IS_LTDC_BLUEVALUE(__BBLUE__)                   ((__BBLUE__)  <= LTDC_COLOR)
#define IS_LTDC_GREENVALUE(__BGREEN__)                 ((__BGREEN__) <= LTDC_COLOR)
#define IS_LTDC_REDVALUE(__BRED__)                     ((__BRED__)   <= LTDC_COLOR)
#define IS_LTDC_BLENDING_FACTOR1(__BLENDING_FACTOR1__) (((__BLENDING_FACTOR1__) == LTDC_BLENDING_FACTOR1_CA) || \
                                                        ((__BLENDING_FACTOR1__) == LTDC_BLENDING_FACTOR1_PAxCA))
#define IS_LTDC_BLENDING_FACTOR2(__BLENDING_FACTOR1__) (((__BLENDING_FACTOR1__) == LTDC_BLENDING_FACTOR2_CA) || \
                                                        ((__BLENDING_FACTOR1__) == LTDC_BLENDING_FACTOR2_PAxCA))
#define IS_LTDC_PIXEL_FORMAT(__PIXEL_FORMAT__)         (((__PIXEL_FORMAT__) == LTDC_PIXEL_FORMAT_ARGB8888) || \
                                                        ((__PIXEL_FORMAT__) == LTDC_PIXEL_FORMAT_RGB888)   || \
                                                        ((__PIXEL_FORMAT__) == LTDC_PIXEL_FORMAT_RGB565)   || \
                                                        ((__PIXEL_FORMAT__) == LTDC_PIXEL_FORMAT_ARGB1555) || \
                                                        ((__PIXEL_FORMAT__) == LTDC_PIXEL_FORMAT_ARGB4444) || \
                                                        ((__PIXEL_FORMAT__) == LTDC_PIXEL_FORMAT_L8)       || \
                                                        ((__PIXEL_FORMAT__) == LTDC_PIXEL_FORMAT_AL44)     || \
                                                        ((__PIXEL_FORMAT__) == LTDC_PIXEL_FORMAT_AL88))
#define IS_LTDC_ALPHA(__ALPHA__)                       ((__ALPHA__) <= LTDC_ALPHA)
#define IS_LTDC_HCONFIGST(__HCONFIGST__)               ((__HCONFIGST__) <= LTDC_STARTPOSITION)
#define IS_LTDC_HCONFIGSP(__HCONFIGSP__)               ((__HCONFIGSP__) <= LTDC_STOPPOSITION)
#define IS_LTDC_VCONFIGST(__VCONFIGST__)               ((__VCONFIGST__) <= LTDC_STARTPOSITION)
#define IS_LTDC_VCONFIGSP(__VCONFIGSP__)               ((__VCONFIGSP__) <= LTDC_STOPPOSITION)
#define IS_LTDC_CFBP(__CFBP__)                         ((__CFBP__) <= LTDC_COLOR_FRAME_BUFFER)
#define IS_LTDC_CFBLL(__CFBLL__)                       ((__CFBLL__) <= LTDC_COLOR_FRAME_BUFFER)
#define IS_LTDC_CFBLNBR(__CFBLNBR__)                   ((__CFBLNBR__) <= LTDC_LINE_NUMBER)
#define IS_LTDC_LIPOS(__LIPOS__)                       ((__LIPOS__) <= 0x7FFU)
#define IS_LTDC_RELOAD(__RELOADTYPE__)                 (((__RELOADTYPE__) == LTDC_RELOAD_IMMEDIATE) || \
                                                        ((__RELOADTYPE__) == LTDC_RELOAD_VERTICAL_BLANKING))
   
      
    

                                                                                
                                                           
      
    

   
      
    

   
      
    

   
      
    

#endif           

#ifdef __cplusplus
}
#endif

#endif                           

