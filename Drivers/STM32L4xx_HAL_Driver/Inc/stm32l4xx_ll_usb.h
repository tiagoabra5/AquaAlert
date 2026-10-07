/**
  ******************************************************************************
  * @file    stm32l4xx_ll_usb.h
  * @author  MCD Application Team
  * @brief   Header file of USB Low Layer HAL module.
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

                                                                                
#ifndef STM32L4xx_LL_USB_H
#define STM32L4xx_LL_USB_H

#ifdef __cplusplus
extern "C" {
#endif                  

                                                                                
#include "stm32l4xx_hal_def.h"

#if defined (USB) || defined (USB_OTG_FS)
                                    
      
    

                      
      
    

                                                                                
#ifndef HAL_USB_TIMEOUT
#define HAL_USB_TIMEOUT                                       0xF000000U
#endif                             

#ifndef HAL_USB_CURRENT_MODE_MAX_DELAY_MS
#define HAL_USB_CURRENT_MODE_MAX_DELAY_MS                           200U
#endif                                               

   
                               
    

typedef enum
{
  USB_DEVICE_MODE = 0,
  USB_HOST_MODE   = 1,
  USB_DRD_MODE    = 2
} USB_ModeTypeDef;

#if defined (HAL_HCD_MODULE_ENABLED)
   
                                 
    
typedef enum
{
  URB_IDLE = 0,
  URB_DONE,
  URB_NOTREADY,
  URB_NYET,
  URB_ERROR,
  URB_STALL,
  URB_NAK_WAIT
} USB_URBStateTypeDef;

   
                                           
    
typedef enum
{
  HC_IDLE = 0,
  HC_XFRC,
  HC_HALTED,
  HC_ACK,
  HC_NAK,
  HC_NYET,
  HC_STALL,
  HC_XACTERR,
  HC_BBLERR,
  HC_DATATGLERR
} USB_HCStateTypeDef;
#endif                                       


   
                                                            
    
typedef struct
{
  uint8_t dev_endpoints;                                         
                                                                                     
                                                                                                                  

#if defined (USB_OTG_FS)
  uint8_t Host_channels;                                      
                                                                                     
                                                                                                                  
#endif                           

  uint8_t dma_enable;                                 
                                                                                                                  

  uint8_t speed;                                       
                                                                                                   
                                                                                                                 

  uint8_t ep0_mps;                                                                                               

  uint8_t phy_itface;                                                 
                                                                                                                 

  uint8_t Sof_enable;                                                                                            

  uint8_t low_power_enable;                                                                                      

  uint8_t lpm_enable;                                                                                            

  uint8_t battery_charging_enable;                                                                               

#if defined (USB_OTG_FS)
  uint8_t vbus_sensing_enable;                                                                                   

  uint8_t use_dedicated_ep1;                                                                                     

  uint8_t use_external_vbus;                                                                                     
#endif                           
} USB_CfgTypeDef;

#if defined (HAL_PCD_MODULE_ENABLED)
typedef struct
{
  uint8_t   num;                                      
                                                                                                                  

  uint8_t   is_in;                                       
                                                                                                                  

  uint8_t   is_stall;                                          
                                                                                                                  

#if defined (USB_OTG_FS)
  uint8_t   is_iso_incomplete;                                
                                                                                                                  
#endif                           

  uint8_t   type;                                   
                                                                                                                  

  uint8_t   data_pid_start;                            
                                                                                                                  

#if defined (USB)
  uint16_t  pmaadress;                            
                                                                                                                  

  uint16_t  pmaaddr0;                              
                                                                                                                  

  uint16_t  pmaaddr1;                              
                                                                                                                  

  uint8_t   doublebuffer;                                  
                                                                                                                  
#endif                    

  uint32_t  maxpacket;                                         
                                                                                                                  

  uint8_t   *xfer_buff;                                                                                           

  uint32_t  xfer_len;                                                                                             

  uint32_t  xfer_count;                                                                                           

#if defined (USB_OTG_FS)
  uint8_t   even_odd_frame;                         
                                                                                                                  

  uint16_t  tx_fifo_num;                                       
                                                                                                                  

  uint32_t  dma_addr;                                                                                             

  uint32_t  xfer_size;                                                                                            
#endif                           

#if defined (USB)
  uint32_t  xfer_len_db;                                                                                          

  uint8_t   xfer_fill_db;                                                                                         
#endif                    
} USB_EPTypeDef;
#endif                                       

#if defined (HAL_HCD_MODULE_ENABLED)
typedef struct
{
  uint8_t   dev_addr;                                   
                                                                                                                  

  uint8_t   ch_num;                                      
                                                                                                                  

  uint8_t   ep_num;                                  
                                                                                                                  

  uint8_t   ep_is_in;                                  
                                                                                                                  

  uint8_t   ch_dir;                                   
                                                                                                                  

  uint8_t   speed;                                          
                                                                                              
                                                                                                                  

  uint8_t   do_ping;                                                                                              

  uint8_t   hub_port_nbr;                                                                                         
  uint8_t   hub_addr;                                                                                             

  uint8_t   ep_type;                               
                                                                                                                  

  uint16_t  max_packet;                                       
                                                                                                                  

  uint8_t   data_pid;                                 
                                                                                                                  

  uint8_t   *xfer_buff;                                                                                           

  uint32_t  XferSize;                                                                                             

  uint32_t  xfer_len;                                                                                             

  uint32_t  xfer_count;                                                                                           

  uint8_t   toggle_in;                                               
                                                                                                                  

  uint8_t   toggle_out;                                              
                                                                                                                  

  uint32_t  dma_addr;                                                                                             

  uint32_t  NakCnt;                                                                                               

  uint32_t  ErrCnt;                                                                                               

  USB_URBStateTypeDef urb_state;                 
                                                                                                                  

  USB_HCStateTypeDef state;                               
                                                                                                                  
} USB_HCTypeDef;
#endif                                       

#if defined (USB_OTG_FS)
typedef USB_ModeTypeDef     USB_OTG_ModeTypeDef;
typedef USB_CfgTypeDef      USB_OTG_CfgTypeDef;

#if defined (HAL_PCD_MODULE_ENABLED)
typedef USB_EPTypeDef       USB_OTG_EPTypeDef;
#endif                                       

#if defined (HAL_HCD_MODULE_ENABLED)
typedef USB_URBStateTypeDef USB_OTG_URBStateTypeDef;
typedef USB_HCStateTypeDef  USB_OTG_HCStateTypeDef;
typedef USB_HCTypeDef       USB_OTG_HCTypeDef;
#endif                                       
#endif                           

                                                                                

                                                           
      
    

#if defined (USB_OTG_FS)
                                     
      
    
#define USB_OTG_CORE_ID_300A          0x4F54300AU
#define USB_OTG_CORE_ID_310A          0x4F54310AU
   
      
    

                                          
      
    
#define USB_OTG_MODE_DEVICE                    0U
#define USB_OTG_MODE_HOST                      1U
#define USB_OTG_MODE_DRD                       2U
   
      
    

                                                        
      
    
#define USB_OTG_SPEED_FULL                     3U
   
      
    

                                                    
      
    
#define USB_OTG_EMBEDDED_PHY                   2U
   
      
    

                                                                
      
    
#ifndef USBD_FS_TRDT_VALUE
#define USBD_FS_TRDT_VALUE                     5U
#define USBD_DEFAULT_TRDT_VALUE                9U
#endif                         
   
      
    

                                                    
      
    
#define USB_OTG_FS_MAX_PACKET_SIZE            64U
#define USB_OTG_MAX_EP0_SIZE                  64U
   
      
    

                                                                        
      
    
#define DSTS_ENUMSPD_HS_PHY_30MHZ_OR_60MHZ     (0UL << 1)
#define DSTS_ENUMSPD_FS_PHY_30MHZ_OR_60MHZ     (1UL << 1)
#define DSTS_ENUMSPD_FS_PHY_48MHZ              (3UL << 1)
   
      
    

                                                                          
      
    
#define DCFG_FRAME_INTERVAL_80                 0U
#define DCFG_FRAME_INTERVAL_85                 1U
#define DCFG_FRAME_INTERVAL_90                 2U
#define DCFG_FRAME_INTERVAL_95                 3U
   
      
    
#endif                           
                                                  
      
    
#define EP_MPS_64                              0U
#define EP_MPS_32                              1U
#define EP_MPS_16                              2U
#define EP_MPS_8                               3U
   
      
    

                                                  
      
    
#define EP_TYPE_CTRL                           0U
#define EP_TYPE_ISOC                           1U
#define EP_TYPE_BULK                           2U
#define EP_TYPE_INTR                           3U
#define EP_TYPE_MSK                            3U
   
      
    

                                                    
      
    
#define EP_SPEED_LOW                           0U
#define EP_SPEED_FULL                          1U
#define EP_SPEED_HIGH                          2U
   
      
    

                                                               
      
    
#define HC_PID_DATA0                           0U
#define HC_PID_DATA2                           1U
#define HC_PID_DATA1                           2U
#define HC_PID_SETUP                           3U
   
      
    

                                 
      
    
#define USBD_FS_SPEED                          2U
#define USBH_FSLS_SPEED                        1U
   
      
    

#if defined (USB_OTG_FS)
                                                          
      
    
#define STS_GOUT_NAK                           1U
#define STS_DATA_UPDT                          2U
#define STS_XFER_COMP                          3U
#define STS_SETUP_COMP                         4U
#define STS_SETUP_UPDT                         6U
   
      
    

                                                                        
      
    
#define HCFG_30_60_MHZ                         0U
#define HCFG_48_MHZ                            1U
#define HCFG_6_MHZ                             2U
   
      
    

                                                                      
      
    
#define HFIR_6_MHZ                          6000U
#define HFIR_60_MHZ                        60000U
#define HFIR_48_MHZ                        48000U
   
      
    

                                                                                        
      
    
#define HPRT0_PRTSPD_HIGH_SPEED                0UL
#define HPRT0_PRTSPD_FULL_SPEED                1UL
#define HPRT0_PRTSPD_LOW_SPEED                 2UL
   
      
    

#define HCCHAR_CTRL                            0U
#define HCCHAR_ISOC                            1U
#define HCCHAR_BULK                            2U
#define HCCHAR_INTR                            3U

#define GRXSTS_PKTSTS_IN                       2U
#define GRXSTS_PKTSTS_IN_XFER_COMP             3U
#define GRXSTS_PKTSTS_DATA_TOGGLE_ERR          5U
#define GRXSTS_PKTSTS_CH_HALTED                7U

#define CLEAR_INTERRUPT_MASK          0xFFFFFFFFU

#define HC_MAX_PKT_CNT                       256U

#define USBx_PCGCCTL    *(__IO uint32_t *)((uint32_t)USBx_BASE + USB_OTG_PCGCCTL_BASE)
#define USBx_HPRT0      *(__IO uint32_t *)((uint32_t)USBx_BASE + USB_OTG_HOST_PORT_BASE)

#define USBx_DEVICE     ((USB_OTG_DeviceTypeDef *)(USBx_BASE + USB_OTG_DEVICE_BASE))
#define USBx_INEP(i)    ((USB_OTG_INEndpointTypeDef *)(USBx_BASE\
                                                       + USB_OTG_IN_ENDPOINT_BASE + ((i) * USB_OTG_EP_REG_SIZE)))

#define USBx_OUTEP(i)   ((USB_OTG_OUTEndpointTypeDef *)(USBx_BASE\
                                                        + USB_OTG_OUT_ENDPOINT_BASE + ((i) * USB_OTG_EP_REG_SIZE)))

#define USBx_DFIFO(i)   *(__IO uint32_t *)(USBx_BASE + USB_OTG_FIFO_BASE + ((i) * USB_OTG_FIFO_SIZE))

#define USBx_HOST       ((USB_OTG_HostTypeDef *)(USBx_BASE + USB_OTG_HOST_BASE))
#define USBx_HC(i)      ((USB_OTG_HostChannelTypeDef *)(USBx_BASE\
                                                        + USB_OTG_HOST_CHANNEL_BASE\
                                                        + ((i) * USB_OTG_HOST_CHANNEL_SIZE)))


#define EP_ADDR_MSK                            0xFU
#endif                           

#if defined (USB)
#define BTABLE_ADDRESS                         0x000U
#define PMA_ACCESS                             1U

#ifndef USB_EP_RX_STRX
#define USB_EP_RX_STRX                         (0x3UL << 12)
#endif                     

#define EP_ADDR_MSK                            0x7U

#ifndef USE_USB_DOUBLE_BUFFER
#define USE_USB_DOUBLE_BUFFER                  1U
#endif                            
#endif                    

   
      
    

                                                                                
                                                                  
      
    
#if defined (USB_OTG_FS)
#define USB_MASK_INTERRUPT(__INSTANCE__, __INTERRUPT__)     ((__INSTANCE__)->GINTMSK &= ~(__INTERRUPT__))
#define USB_UNMASK_INTERRUPT(__INSTANCE__, __INTERRUPT__)   ((__INSTANCE__)->GINTMSK |= (__INTERRUPT__))

#define CLEAR_IN_EP_INTR(__EPNUM__, __INTERRUPT__)          (USBx_INEP(__EPNUM__)->DIEPINT = (__INTERRUPT__))
#define CLEAR_OUT_EP_INTR(__EPNUM__, __INTERRUPT__)         (USBx_OUTEP(__EPNUM__)->DOEPINT = (__INTERRUPT__))
#endif                           
   
      
    

                                                                                
                                                                          
      
    
#if defined (USB_OTG_FS)
HAL_StatusTypeDef USB_CoreInit(USB_OTG_GlobalTypeDef *USBx, USB_OTG_CfgTypeDef cfg);
HAL_StatusTypeDef USB_DevInit(USB_OTG_GlobalTypeDef *USBx, USB_OTG_CfgTypeDef cfg);
HAL_StatusTypeDef USB_EnableGlobalInt(USB_OTG_GlobalTypeDef *USBx);
HAL_StatusTypeDef USB_DisableGlobalInt(USB_OTG_GlobalTypeDef *USBx);
HAL_StatusTypeDef USB_SetTurnaroundTime(USB_OTG_GlobalTypeDef *USBx, uint32_t hclk, uint8_t speed);
HAL_StatusTypeDef USB_SetCurrentMode(USB_OTG_GlobalTypeDef *USBx, USB_ModeTypeDef mode);
HAL_StatusTypeDef USB_SetDevSpeed(const USB_OTG_GlobalTypeDef *USBx, uint8_t speed);
HAL_StatusTypeDef USB_FlushRxFifo(USB_OTG_GlobalTypeDef *USBx);
HAL_StatusTypeDef USB_FlushTxFifo(USB_OTG_GlobalTypeDef *USBx, uint32_t num);

#if defined (HAL_PCD_MODULE_ENABLED)
HAL_StatusTypeDef USB_ActivateEndpoint(const USB_OTG_GlobalTypeDef *USBx, const USB_OTG_EPTypeDef *ep);
HAL_StatusTypeDef USB_DeactivateEndpoint(const USB_OTG_GlobalTypeDef *USBx, const USB_OTG_EPTypeDef *ep);
HAL_StatusTypeDef USB_ActivateDedicatedEndpoint(const USB_OTG_GlobalTypeDef *USBx, const USB_OTG_EPTypeDef *ep);
HAL_StatusTypeDef USB_DeactivateDedicatedEndpoint(const USB_OTG_GlobalTypeDef *USBx, const USB_OTG_EPTypeDef *ep);
HAL_StatusTypeDef USB_EPSetStall(const USB_OTG_GlobalTypeDef *USBx, const USB_OTG_EPTypeDef *ep);
HAL_StatusTypeDef USB_EPClearStall(const USB_OTG_GlobalTypeDef *USBx, const USB_OTG_EPTypeDef *ep);
HAL_StatusTypeDef USB_EPStartXfer(USB_OTG_GlobalTypeDef *USBx, USB_OTG_EPTypeDef *ep);
HAL_StatusTypeDef USB_EPStopXfer(USB_OTG_GlobalTypeDef *USBx, USB_OTG_EPTypeDef *ep);
#endif                                       

HAL_StatusTypeDef USB_WritePacket(const USB_OTG_GlobalTypeDef *USBx, uint8_t *src,
                                  uint8_t ch_ep_num, uint16_t len);

void             *USB_ReadPacket(const USB_OTG_GlobalTypeDef *USBx, uint8_t *dest, uint16_t len);

HAL_StatusTypeDef USB_SetDevAddress(const USB_OTG_GlobalTypeDef *USBx, uint8_t address);
HAL_StatusTypeDef USB_DevConnect(const USB_OTG_GlobalTypeDef *USBx);
HAL_StatusTypeDef USB_DevDisconnect(const USB_OTG_GlobalTypeDef *USBx);
HAL_StatusTypeDef USB_StopDevice(USB_OTG_GlobalTypeDef *USBx);
HAL_StatusTypeDef USB_ActivateSetup(const USB_OTG_GlobalTypeDef *USBx);
HAL_StatusTypeDef USB_EP0_OutStart(const USB_OTG_GlobalTypeDef *USBx, const uint8_t *psetup);
uint8_t           USB_GetDevSpeed(const USB_OTG_GlobalTypeDef *USBx);
uint32_t          USB_GetMode(const USB_OTG_GlobalTypeDef *USBx);
uint32_t          USB_ReadInterrupts(USB_OTG_GlobalTypeDef const *USBx);
uint32_t          USB_ReadChInterrupts(const USB_OTG_GlobalTypeDef *USBx, uint8_t chnum);
uint32_t          USB_ReadDevAllOutEpInterrupt(const USB_OTG_GlobalTypeDef *USBx);
uint32_t          USB_ReadDevOutEPInterrupt(const USB_OTG_GlobalTypeDef *USBx, uint8_t epnum);
uint32_t          USB_ReadDevAllInEpInterrupt(const USB_OTG_GlobalTypeDef *USBx);
uint32_t          USB_ReadDevInEPInterrupt(const USB_OTG_GlobalTypeDef *USBx, uint8_t epnum);
void              USB_ClearInterrupts(USB_OTG_GlobalTypeDef *USBx, uint32_t interrupt);
HAL_StatusTypeDef USB_InitFSLSPClkSel(const USB_OTG_GlobalTypeDef *USBx, uint8_t freq);

HAL_StatusTypeDef USB_HostInit(USB_OTG_GlobalTypeDef *USBx, USB_OTG_CfgTypeDef cfg);
HAL_StatusTypeDef USB_ResetPort(const USB_OTG_GlobalTypeDef *USBx);
HAL_StatusTypeDef USB_DriveVbus(const USB_OTG_GlobalTypeDef *USBx, uint8_t state);
uint32_t          USB_GetHostSpeed(USB_OTG_GlobalTypeDef const *USBx);
uint32_t          USB_GetCurrentFrame(USB_OTG_GlobalTypeDef const *USBx);
HAL_StatusTypeDef USB_DoPing(const USB_OTG_GlobalTypeDef *USBx, uint8_t ch_num);
HAL_StatusTypeDef USB_StopHost(USB_OTG_GlobalTypeDef *USBx);

#if defined (HAL_HCD_MODULE_ENABLED)
HAL_StatusTypeDef USB_HC_Init(USB_OTG_GlobalTypeDef *USBx, uint8_t ch_num,
                              uint8_t epnum, uint8_t dev_address, uint8_t speed,
                              uint8_t ep_type, uint16_t mps);
HAL_StatusTypeDef USB_HC_StartXfer(USB_OTG_GlobalTypeDef *USBx,
                                   USB_OTG_HCTypeDef *hc);

uint32_t          USB_HC_ReadInterrupt(const USB_OTG_GlobalTypeDef *USBx);
HAL_StatusTypeDef USB_HC_Halt(const USB_OTG_GlobalTypeDef *USBx, uint8_t hc_num);
HAL_StatusTypeDef USB_HC_Activate(const USB_OTG_GlobalTypeDef *USBx, uint8_t ch_num, uint8_t ch_dir);
#endif                                       

HAL_StatusTypeDef USB_ActivateRemoteWakeup(const USB_OTG_GlobalTypeDef *USBx);
HAL_StatusTypeDef USB_DeActivateRemoteWakeup(const USB_OTG_GlobalTypeDef *USBx);
#endif                           

#if defined (USB)
HAL_StatusTypeDef USB_CoreInit(USB_TypeDef *USBx, USB_CfgTypeDef cfg);
HAL_StatusTypeDef USB_DevInit(USB_TypeDef *USBx, USB_CfgTypeDef cfg);
HAL_StatusTypeDef USB_EnableGlobalInt(USB_TypeDef *USBx);
HAL_StatusTypeDef USB_DisableGlobalInt(USB_TypeDef *USBx);
HAL_StatusTypeDef USB_SetCurrentMode(USB_TypeDef *USBx, USB_ModeTypeDef mode);
HAL_StatusTypeDef USB_SetDevSpeed(USB_TypeDef *USBx, uint8_t speed);

HAL_StatusTypeDef USB_FlushRxFifo(USB_TypeDef const *USBx);
HAL_StatusTypeDef USB_FlushTxFifo(USB_TypeDef const *USBx, uint32_t num);

#if defined (HAL_PCD_MODULE_ENABLED)
HAL_StatusTypeDef USB_ActivateEndpoint(USB_TypeDef *USBx, USB_EPTypeDef *ep);
HAL_StatusTypeDef USB_DeactivateEndpoint(USB_TypeDef *USBx, USB_EPTypeDef *ep);
HAL_StatusTypeDef USB_EPStartXfer(USB_TypeDef *USBx, USB_EPTypeDef *ep);
HAL_StatusTypeDef USB_EPSetStall(USB_TypeDef *USBx, USB_EPTypeDef *ep);
HAL_StatusTypeDef USB_EPClearStall(USB_TypeDef *USBx, USB_EPTypeDef *ep);
HAL_StatusTypeDef USB_EPStopXfer(USB_TypeDef *USBx, USB_EPTypeDef *ep);
#endif                                       

HAL_StatusTypeDef USB_SetDevAddress(USB_TypeDef *USBx, uint8_t address);
HAL_StatusTypeDef USB_DevConnect(USB_TypeDef *USBx);
HAL_StatusTypeDef USB_DevDisconnect(USB_TypeDef *USBx);
HAL_StatusTypeDef USB_StopDevice(USB_TypeDef *USBx);
HAL_StatusTypeDef USB_EP0_OutStart(USB_TypeDef *USBx, uint8_t *psetup);
HAL_StatusTypeDef USB_WritePacket(USB_TypeDef *USBx, uint8_t *src,
                                  uint8_t ch_ep_num, uint16_t len);

void             *USB_ReadPacket(USB_TypeDef *USBx, uint8_t *dest, uint16_t len);

uint32_t          USB_ReadInterrupts(USB_TypeDef const *USBx);
uint32_t          USB_ReadDevAllOutEpInterrupt(USB_TypeDef *USBx);
uint32_t          USB_ReadDevOutEPInterrupt(USB_TypeDef *USBx, uint8_t epnum);
uint32_t          USB_ReadDevAllInEpInterrupt(USB_TypeDef *USBx);
uint32_t          USB_ReadDevInEPInterrupt(USB_TypeDef *USBx, uint8_t epnum);
void              USB_ClearInterrupts(USB_TypeDef *USBx, uint32_t interrupt);
HAL_StatusTypeDef USB_ActivateRemoteWakeup(USB_TypeDef *USBx);
HAL_StatusTypeDef USB_DeActivateRemoteWakeup(USB_TypeDef *USBx);

void              USB_WritePMA(USB_TypeDef const *USBx, uint8_t *pbUsrBuf,
                               uint16_t wPMABufAddr, uint16_t wNBytes);

void              USB_ReadPMA(USB_TypeDef const *USBx, uint8_t *pbUsrBuf,
                              uint16_t wPMABufAddr, uint16_t wNBytes);
#endif                    
   
      
    

   
      
    

   
      
    

   
      
    
#endif                                            

#ifdef __cplusplus
}
#endif                  

#endif                         
