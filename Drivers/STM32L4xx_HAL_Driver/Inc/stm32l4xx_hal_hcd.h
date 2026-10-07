/**
  ******************************************************************************
  * @file    stm32l4xx_hal_hcd.h
  * @author  MCD Application Team
  * @brief   Header file of HCD HAL module.
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

                                                                                
#ifndef STM32L4xx_HAL_HCD_H
#define STM32L4xx_HAL_HCD_H

#ifdef __cplusplus
extern "C" {
#endif

                                                                                
#include "stm32l4xx_ll_usb.h"

#if defined (USB_OTG_FS)
                                    
      
    

                       
      
    

                                                                                
                                                   
      
    

                                                                      
      
    
typedef enum
{
  HAL_HCD_STATE_RESET    = 0x00,
  HAL_HCD_STATE_READY    = 0x01,
  HAL_HCD_STATE_ERROR    = 0x02,
  HAL_HCD_STATE_BUSY     = 0x03,
  HAL_HCD_STATE_TIMEOUT  = 0x04
} HCD_StateTypeDef;

typedef USB_OTG_GlobalTypeDef   HCD_TypeDef;
typedef USB_OTG_CfgTypeDef      HCD_InitTypeDef;
typedef USB_OTG_HCTypeDef       HCD_HCTypeDef;
typedef USB_OTG_URBStateTypeDef HCD_URBStateTypeDef;
typedef USB_OTG_HCStateTypeDef  HCD_HCStateTypeDef;
   
      
    

                                                                       
      
    
#if (USE_HAL_HCD_REGISTER_CALLBACKS == 1U)
typedef struct __HCD_HandleTypeDef
#else
typedef struct
#endif                                     
{
  HCD_TypeDef               *Instance;                                  
  HCD_InitTypeDef           Init;                                       
  HCD_HCTypeDef             hc[16];                                     
  HAL_LockTypeDef           Lock;                                       
  __IO HCD_StateTypeDef     State;                                      
  __IO  uint32_t            ErrorCode;                                  
  void                      *pData;                                     
#if (USE_HAL_HCD_REGISTER_CALLBACKS == 1U)
  void (* SOFCallback)(struct __HCD_HandleTypeDef *hhcd);                                                                              
  void (* ConnectCallback)(struct __HCD_HandleTypeDef *hhcd);                                                                          
  void (* DisconnectCallback)(struct __HCD_HandleTypeDef *hhcd);                                                                       
  void (* PortEnabledCallback)(struct __HCD_HandleTypeDef *hhcd);                                                                      
  void (* PortDisabledCallback)(struct __HCD_HandleTypeDef *hhcd);                                                                     
  void (* HC_NotifyURBChangeCallback)(struct __HCD_HandleTypeDef *hhcd, uint8_t chnum,
                                      HCD_URBStateTypeDef urb_state);                                                                               

  void (* MspInitCallback)(struct __HCD_HandleTypeDef *hhcd);                                                                          
  void (* MspDeInitCallback)(struct __HCD_HandleTypeDef *hhcd);                                                                        
#endif                                     
} HCD_HandleTypeDef;
   
      
    

   
      
    

                                                                                
                                                           
      
    
#ifndef HAL_HCD_CHANNEL_NAK_COUNT
#define HAL_HCD_CHANNEL_NAK_COUNT           2U
#endif                                

                                 
      
    
#define HCD_SPEED_FULL               USBH_FSLS_SPEED
#define HCD_SPEED_LOW                USBH_FSLS_SPEED
   
      
    

                                               
      
    
#define HCD_DEVICE_SPEED_HIGH               0U
#define HCD_DEVICE_SPEED_FULL               1U
#define HCD_DEVICE_SPEED_LOW                2U
   
      
    

                                           
      
    
#define HCD_PHY_ULPI                 1U
#define HCD_PHY_EMBEDDED             2U
   
      
    

                                                                 
                                     
      
    
#if (USE_HAL_HCD_REGISTER_CALLBACKS == 1U)
#define  HAL_HCD_ERROR_INVALID_CALLBACK                        (0x00000010U)                                   
#endif                                     

   
      
    

   
      
    

                                                                                
                                                     
                                                                         
      
    
#define __HAL_HCD_ENABLE(__HANDLE__)                   (void)USB_EnableGlobalInt ((__HANDLE__)->Instance)
#define __HAL_HCD_DISABLE(__HANDLE__)                  (void)USB_DisableGlobalInt ((__HANDLE__)->Instance)

#define __HAL_HCD_GET_FLAG(__HANDLE__, __INTERRUPT__)      ((USB_ReadInterrupts((__HANDLE__)->Instance)\
                                                             & (__INTERRUPT__)) == (__INTERRUPT__))

#define __HAL_HCD_GET_CH_FLAG(__HANDLE__, __chnum__, __INTERRUPT__) \
  ((USB_ReadChInterrupts((__HANDLE__)->Instance, (__chnum__)) & (__INTERRUPT__)) == (__INTERRUPT__))

#define __HAL_HCD_CLEAR_FLAG(__HANDLE__, __INTERRUPT__)    (((__HANDLE__)->Instance->GINTSTS) = (__INTERRUPT__))
#define __HAL_HCD_IS_INVALID_INTERRUPT(__HANDLE__)         (USB_ReadInterrupts((__HANDLE__)->Instance) == 0U)

#define __HAL_HCD_CLEAR_HC_INT(chnum, __INTERRUPT__)  (USBx_HC(chnum)->HCINT = (__INTERRUPT__))
#define __HAL_HCD_MASK_HALT_HC_INT(chnum)             (USBx_HC(chnum)->HCINTMSK &= ~USB_OTG_HCINTMSK_CHHM)
#define __HAL_HCD_UNMASK_HALT_HC_INT(chnum)           (USBx_HC(chnum)->HCINTMSK |= USB_OTG_HCINTMSK_CHHM)
#define __HAL_HCD_MASK_ACK_HC_INT(chnum)              (USBx_HC(chnum)->HCINTMSK &= ~USB_OTG_HCINTMSK_ACKM)
#define __HAL_HCD_UNMASK_ACK_HC_INT(chnum)            (USBx_HC(chnum)->HCINTMSK |= USB_OTG_HCINTMSK_ACKM)
   
      
    

                                                                                
                                                             
      
    

                                                                                          
      
    
HAL_StatusTypeDef HAL_HCD_Init(HCD_HandleTypeDef *hhcd);
HAL_StatusTypeDef HAL_HCD_DeInit(HCD_HandleTypeDef *hhcd);
HAL_StatusTypeDef HAL_HCD_HC_Init(HCD_HandleTypeDef *hhcd, uint8_t ch_num,
                                  uint8_t epnum, uint8_t dev_address,
                                  uint8_t speed, uint8_t ep_type, uint16_t mps);

HAL_StatusTypeDef HAL_HCD_HC_Halt(HCD_HandleTypeDef *hhcd, uint8_t ch_num);
HAL_StatusTypeDef HAL_HCD_HC_Activate(HCD_HandleTypeDef *hhcd, uint8_t ch_num);
void              HAL_HCD_MspInit(HCD_HandleTypeDef *hhcd);
void              HAL_HCD_MspDeInit(HCD_HandleTypeDef *hhcd);

#if (USE_HAL_HCD_REGISTER_CALLBACKS == 1U)
                                                                                                           
                                                              
      
    
typedef enum
{
  HAL_HCD_SOF_CB_ID            = 0x01,                                                
  HAL_HCD_CONNECT_CB_ID        = 0x02,                                                
  HAL_HCD_DISCONNECT_CB_ID     = 0x03,                                                
  HAL_HCD_PORT_ENABLED_CB_ID   = 0x04,                                                
  HAL_HCD_PORT_DISABLED_CB_ID  = 0x05,                                                

  HAL_HCD_MSPINIT_CB_ID        = 0x06,                                                
  HAL_HCD_MSPDEINIT_CB_ID      = 0x07                                                 

} HAL_HCD_CallbackIDTypeDef;
   
      
    

                                                                                             
                                                       
      
    

typedef void (*pHCD_CallbackTypeDef)(HCD_HandleTypeDef *hhcd);                                                                             
typedef void (*pHCD_HC_NotifyURBChangeCallbackTypeDef)(HCD_HandleTypeDef *hhcd,
                                                       uint8_t epnum,
                                                       HCD_URBStateTypeDef urb_state);                                                        
   
      
    

HAL_StatusTypeDef HAL_HCD_RegisterCallback(HCD_HandleTypeDef *hhcd,
                                           HAL_HCD_CallbackIDTypeDef CallbackID,
                                           pHCD_CallbackTypeDef pCallback);

HAL_StatusTypeDef HAL_HCD_UnRegisterCallback(HCD_HandleTypeDef *hhcd,
                                             HAL_HCD_CallbackIDTypeDef CallbackID);

HAL_StatusTypeDef HAL_HCD_RegisterHC_NotifyURBChangeCallback(HCD_HandleTypeDef *hhcd,
                                                             pHCD_HC_NotifyURBChangeCallbackTypeDef pCallback);

HAL_StatusTypeDef HAL_HCD_UnRegisterHC_NotifyURBChangeCallback(HCD_HandleTypeDef *hhcd);
#endif                                     
   
      
    

                                                                                
                                                                                  
      
    
HAL_StatusTypeDef HAL_HCD_HC_SubmitRequest(HCD_HandleTypeDef *hhcd, uint8_t ch_num,
                                           uint8_t direction, uint8_t ep_type,
                                           uint8_t token, uint8_t *pbuff,
                                           uint16_t length, uint8_t do_ping);

HAL_StatusTypeDef HAL_HCD_HC_SetHubInfo(HCD_HandleTypeDef *hhcd, uint8_t ch_num,
                                        uint8_t addr, uint8_t PortNbr);

HAL_StatusTypeDef HAL_HCD_HC_ClearHubInfo(HCD_HandleTypeDef *hhcd, uint8_t ch_num);

                                  
void HAL_HCD_IRQHandler(HCD_HandleTypeDef *hhcd);
void HAL_HCD_SOF_Callback(HCD_HandleTypeDef *hhcd);
void HAL_HCD_Connect_Callback(HCD_HandleTypeDef *hhcd);
void HAL_HCD_Disconnect_Callback(HCD_HandleTypeDef *hhcd);
void HAL_HCD_PortEnabled_Callback(HCD_HandleTypeDef *hhcd);
void HAL_HCD_PortDisabled_Callback(HCD_HandleTypeDef *hhcd);
void HAL_HCD_HC_NotifyURBChange_Callback(HCD_HandleTypeDef *hhcd, uint8_t chnum,
                                         HCD_URBStateTypeDef urb_state);
   
      
    

                                                                                
                                                                          
      
    
HAL_StatusTypeDef HAL_HCD_ResetPort(HCD_HandleTypeDef *hhcd);
HAL_StatusTypeDef HAL_HCD_Start(HCD_HandleTypeDef *hhcd);
HAL_StatusTypeDef HAL_HCD_Stop(HCD_HandleTypeDef *hhcd);
   
      
    

                                                                                
                                                                        
      
    
HCD_StateTypeDef        HAL_HCD_GetState(HCD_HandleTypeDef const *hhcd);
HCD_URBStateTypeDef     HAL_HCD_HC_GetURBState(HCD_HandleTypeDef const *hhcd, uint8_t chnum);
HCD_HCStateTypeDef      HAL_HCD_HC_GetState(HCD_HandleTypeDef const *hhcd, uint8_t chnum);
uint32_t                HAL_HCD_HC_GetXferCount(HCD_HandleTypeDef const *hhcd, uint8_t chnum);
uint32_t                HAL_HCD_GetCurrentFrame(HCD_HandleTypeDef *hhcd);
uint32_t                HAL_HCD_GetCurrentSpeed(HCD_HandleTypeDef *hhcd);


   
      
    

                                                                                
                                                   
      
    
   
      
    
                                                                                

   
      
    
   
      
    
   
      
    
#endif                           

#ifdef __cplusplus
}
#endif

#endif                          
