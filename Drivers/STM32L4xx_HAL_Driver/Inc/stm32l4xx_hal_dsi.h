/**
  ******************************************************************************
  * @file    stm32l4xx_hal_dsi.h
  * @author  MCD Application Team
  * @brief   Header file of DSI HAL module.
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

                                                                                
#ifndef STM32L4xx_HAL_DSI_H
#define STM32L4xx_HAL_DSI_H

#ifdef __cplusplus
extern "C" {
#endif

                                                                                
#include "stm32l4xx_hal_def.h"

#if defined(DSI)

                                    
      
    

                     
                                
      
    

                                                                                
                                                   
      
    
   
                                         
    
typedef struct
{
  uint32_t AutomaticClockLaneControl;                                     
                                                                                                                       

  uint32_t TXEscapeCkdiv;                                             
                                                                                                                       

  uint32_t NumberOfLanes;                                    
                                                                                                                       

} DSI_InitTypeDef;

   
                                              
    
typedef struct
{
  uint32_t PLLNDIV;                                              
                                                                                                                

  uint32_t PLLIDF;                                                
                                                                                                                

  uint32_t PLLODF;                                                 
                                                                                                                

} DSI_PLLInitTypeDef;

   
                                        
    
typedef struct
{
  uint32_t VirtualChannelID;                                                                                       

  uint32_t ColorCoding;                                                      
                                                                                                                   

  uint32_t LooselyPacked;                                                                                    
                                                                    
                                                                                                                   

  uint32_t Mode;                                             
                                                                                                                   

  uint32_t PacketSize;                                                                                             

  uint32_t NumberOfChunks;                                                                                         

  uint32_t NullPacketSize;                                                                                         

  uint32_t HSPolarity;                                          
                                                                                                                   

  uint32_t VSPolarity;                                          
                                                                                                                   

  uint32_t DEPolarity;                                                
                                                                                                                   

  uint32_t HorizontalSyncActive;                                                                                   

  uint32_t HorizontalBackPorch;                                                                                    

  uint32_t HorizontalLine;                                                                                         

  uint32_t VerticalSyncActive;                                                                                     

  uint32_t VerticalBackPorch;                                                                                      

  uint32_t VerticalFrontPorch;                                                                                     

  uint32_t VerticalActive;                                                                                         

  uint32_t LPCommandEnable;                                           
                                                                                                                   

  uint32_t LPLargestPacketSize;                                                                       
                                                                                                                   

  uint32_t LPVACTLargestPacketSize;                                                                   
                                                                                                                   

  uint32_t LPHorizontalFrontPorchEnable;                                             
                                                                                                                   

  uint32_t LPHorizontalBackPorchEnable;                                             
                                                                                                                   

  uint32_t LPVerticalActiveEnable;                                            
                                                                                                                   

  uint32_t LPVerticalFrontPorchEnable;                                             
                                                                                                                   

  uint32_t LPVerticalBackPorchEnable;                                             
                                                                                                                   

  uint32_t LPVerticalSyncActiveEnable;                                             
                                                                                                                   

  uint32_t FrameBTAAcknowledgeEnable;                                                 
                                                                                                                   

} DSI_VidCfgTypeDef;

   
                                                  
    
typedef struct
{
  uint32_t VirtualChannelID;                                                                                      

  uint32_t ColorCoding;                                                      
                                                                                                                  

  uint32_t CommandSize;                                                                                         
                                                                                                                   

  uint32_t TearingEffectSource;                                    
                                                                                                                  

  uint32_t TearingEffectPolarity;                                        
                                                                                                                  

  uint32_t HSPolarity;                                          
                                                                                                                  

  uint32_t VSPolarity;                                          
                                                                                                                  

  uint32_t DEPolarity;                                                
                                                                                                                  

  uint32_t VSyncPol;                                                                
                                                                                                                  

  uint32_t AutomaticRefresh;                                        
                                                                                                                  

  uint32_t TEAcknowledgeRequest;                                                       
                                                                                                                  

} DSI_CmdCfgTypeDef;

   
                                                       
    
typedef struct
{
  uint32_t LPGenShortWriteNoP;                                                                
                                                                                                                   

  uint32_t LPGenShortWriteOneP;                                                             
                                                                                                                   

  uint32_t LPGenShortWriteTwoP;                                                              
                                                                                                                   

  uint32_t LPGenShortReadNoP;                                                                
                                                                                                                   

  uint32_t LPGenShortReadOneP;                                                             
                                                                                                                   

  uint32_t LPGenShortReadTwoP;                                                              
                                                                                                                   

  uint32_t LPGenLongWrite;                                                   
                                                                                                                   

  uint32_t LPDcsShortWriteNoP;                                                            
                                                                                                                   

  uint32_t LPDcsShortWriteOneP;                                                         
                                                                                                                   

  uint32_t LPDcsShortReadNoP;                                                            
                                                                                                                   

  uint32_t LPDcsLongWrite;                                               
                                                                                                                   

  uint32_t LPMaxReadPacket;                                                        
                                                                                                                   

  uint32_t AcknowledgeRequest;                                          
                                                                                                                   

} DSI_LPCmdTypeDef;

   
                                      
    
typedef struct
{
  uint32_t ClockLaneHS2LPTime;                                                                                      
                                                                                                                       

  uint32_t ClockLaneLP2HSTime;                                                                                     
                                                                                                                       

  uint32_t DataLaneHS2LPTime;                                                                                       
                                                                                                                       

  uint32_t DataLaneLP2HSTime;                                                                                      
                                                                                                                       

  uint32_t DataLaneMaxReadTime;                                                                     

  uint32_t StopWaitTime;                                                                                            
                                                                                                                       

} DSI_PHY_TimerTypeDef;

   
                                        
    
typedef struct
{
  uint32_t TimeoutCkdiv;                                                                                 

  uint32_t HighSpeedTransmissionTimeout;                                                                 

  uint32_t LowPowerReceptionTimeout;                                                                     

  uint32_t HighSpeedReadTimeout;                                                                         

  uint32_t LowPowerReadTimeout;                                                                          

  uint32_t HighSpeedWriteTimeout;                                                                        

  uint32_t HighSpeedWritePrespMode;                                      
                                                                                                         

  uint32_t LowPowerWriteTimeout;                                                                         

  uint32_t BTATimeout;                                                                                   

} DSI_HOST_TimeoutTypeDef;

   
                                           
    
typedef enum
{
  HAL_DSI_STATE_RESET   = 0x00U,
  HAL_DSI_STATE_READY   = 0x01U,
  HAL_DSI_STATE_ERROR   = 0x02U,
  HAL_DSI_STATE_BUSY    = 0x03U,
  HAL_DSI_STATE_TIMEOUT = 0x04U
} HAL_DSI_StateTypeDef;

   
                                           
    
#if (USE_HAL_DSI_REGISTER_CALLBACKS == 1)
typedef struct __DSI_HandleTypeDef
#else
typedef struct
#endif                                     
{
  DSI_TypeDef               *Instance;                                      
  DSI_InitTypeDef           Init;                                           
  HAL_LockTypeDef           Lock;                                           
  __IO HAL_DSI_StateTypeDef State;                                          
  __IO uint32_t             ErrorCode;                                      
  uint32_t                  ErrorMsk;                                       

#if (USE_HAL_DSI_REGISTER_CALLBACKS == 1)
  void (* TearingEffectCallback)(struct __DSI_HandleTypeDef *hdsi);                                      
  void (* EndOfRefreshCallback)(struct __DSI_HandleTypeDef *hdsi);                                       
  void (* ErrorCallback)(struct __DSI_HandleTypeDef *hdsi);                                              

  void (* MspInitCallback)(struct __DSI_HandleTypeDef *hdsi);                                            
  void (* MspDeInitCallback)(struct __DSI_HandleTypeDef *hdsi);                                          

#endif                                     

} DSI_HandleTypeDef;

#if (USE_HAL_DSI_REGISTER_CALLBACKS == 1)
   
                                                      
    
typedef enum
{
  HAL_DSI_MSPINIT_CB_ID            = 0x00U,                                          
  HAL_DSI_MSPDEINIT_CB_ID          = 0x01U,                                          

  HAL_DSI_TEARING_EFFECT_CB_ID     = 0x02U,                                          
  HAL_DSI_ENDOF_REFRESH_CB_ID      = 0x03U,                                          
  HAL_DSI_ERROR_CB_ID              = 0x04U                                           

} HAL_DSI_CallbackIDTypeDef;

   
                                               
    
typedef  void (*pDSI_CallbackTypeDef)(DSI_HandleTypeDef *hdsi);                                             

#endif                                     
   
      
    

                                                                                
                                                           
      
    
                                             
      
    
#define DSI_ENTER_IDLE_MODE       0x39U
#define DSI_ENTER_INVERT_MODE     0x21U
#define DSI_ENTER_NORMAL_MODE     0x13U
#define DSI_ENTER_PARTIAL_MODE    0x12U
#define DSI_ENTER_SLEEP_MODE      0x10U
#define DSI_EXIT_IDLE_MODE        0x38U
#define DSI_EXIT_INVERT_MODE      0x20U
#define DSI_EXIT_SLEEP_MODE       0x11U
#define DSI_GET_3D_CONTROL        0x3FU
#define DSI_GET_ADDRESS_MODE      0x0BU
#define DSI_GET_BLUE_CHANNEL      0x08U
#define DSI_GET_DIAGNOSTIC_RESULT 0x0FU
#define DSI_GET_DISPLAY_MODE      0x0DU
#define DSI_GET_GREEN_CHANNEL     0x07U
#define DSI_GET_PIXEL_FORMAT      0x0CU
#define DSI_GET_POWER_MODE        0x0AU
#define DSI_GET_RED_CHANNEL       0x06U
#define DSI_GET_SCANLINE          0x45U
#define DSI_GET_SIGNAL_MODE       0x0EU
#define DSI_NOP                   0x00U
#define DSI_READ_DDB_CONTINUE     0xA8U
#define DSI_READ_DDB_START        0xA1U
#define DSI_READ_MEMORY_CONTINUE  0x3EU
#define DSI_READ_MEMORY_START     0x2EU
#define DSI_SET_3D_CONTROL        0x3DU
#define DSI_SET_ADDRESS_MODE      0x36U
#define DSI_SET_COLUMN_ADDRESS    0x2AU
#define DSI_SET_DISPLAY_OFF       0x28U
#define DSI_SET_DISPLAY_ON        0x29U
#define DSI_SET_GAMMA_CURVE       0x26U
#define DSI_SET_PAGE_ADDRESS      0x2BU
#define DSI_SET_PARTIAL_COLUMNS   0x31U
#define DSI_SET_PARTIAL_ROWS      0x30U
#define DSI_SET_PIXEL_FORMAT      0x3AU
#define DSI_SET_SCROLL_AREA       0x33U
#define DSI_SET_SCROLL_START      0x37U
#define DSI_SET_TEAR_OFF          0x34U
#define DSI_SET_TEAR_ON           0x35U
#define DSI_SET_TEAR_SCANLINE     0x44U
#define DSI_SET_VSYNC_TIMING      0x40U
#define DSI_SOFT_RESET            0x01U
#define DSI_WRITE_LUT             0x2DU
#define DSI_WRITE_MEMORY_CONTINUE 0x3CU
#define DSI_WRITE_MEMORY_START    0x2CU
   
      
    

                                                     
      
    
#define DSI_VID_MODE_NB_PULSES    0U
#define DSI_VID_MODE_NB_EVENTS    1U
#define DSI_VID_MODE_BURST        2U
   
      
    

                                           
      
    
#define DSI_COLOR_MODE_FULL       0x00000000U
#define DSI_COLOR_MODE_EIGHT      DSI_WCR_COLM
   
      
    

                                       
      
    
#define DSI_DISPLAY_ON            0x00000000U
#define DSI_DISPLAY_OFF           DSI_WCR_SHTDN
   
      
    

                                           
      
    
#define DSI_LP_COMMAND_DISABLE    0x00000000U
#define DSI_LP_COMMAND_ENABLE     DSI_VMCR_LPCE
   
      
    

                                   
      
    
#define DSI_LP_HFP_DISABLE        0x00000000U
#define DSI_LP_HFP_ENABLE         DSI_VMCR_LPHFPE
   
      
    

                                   
      
    
#define DSI_LP_HBP_DISABLE        0x00000000U
#define DSI_LP_HBP_ENABLE         DSI_VMCR_LPHBPE
   
      
    

                                     
      
    
#define DSI_LP_VACT_DISABLE       0x00000000U
#define DSI_LP_VACT_ENABLE        DSI_VMCR_LPVAE
   
      
    

                                   
      
    
#define DSI_LP_VFP_DISABLE       0x00000000U
#define DSI_LP_VFP_ENABLE        DSI_VMCR_LPVFPE
   
      
    

                                   
      
    
#define DSI_LP_VBP_DISABLE       0x00000000U
#define DSI_LP_VBP_ENABLE        DSI_VMCR_LPVBPE
   
      
    

                                       
      
    
#define DSI_LP_VSYNC_DISABLE     0x00000000U
#define DSI_LP_VSYNC_ENABLE      DSI_VMCR_LPVSAE
   
      
    

                                                       
      
    
#define DSI_FBTAA_DISABLE        0x00000000U
#define DSI_FBTAA_ENABLE         DSI_VMCR_FBTAAE
   
      
    

                                                               
      
    
#define DSI_TE_DSILINK           0x00000000U
#define DSI_TE_EXTERNAL          DSI_WCFGR_TESRC
   
      
    

                                                                   
      
    
#define DSI_TE_RISING_EDGE       0x00000000U
#define DSI_TE_FALLING_EDGE      DSI_WCFGR_TEPOL
   
      
    

                                                   
      
    
#define DSI_VSYNC_FALLING        0x00000000U
#define DSI_VSYNC_RISING         DSI_WCFGR_VSPOL
   
      
    

                                                        
      
    
#define DSI_AR_DISABLE           0x00000000U
#define DSI_AR_ENABLE            DSI_WCFGR_AR
   
      
    

                                                                  
      
    
#define DSI_TE_ACKNOWLEDGE_DISABLE 0x00000000U
#define DSI_TE_ACKNOWLEDGE_ENABLE  DSI_CMCR_TEARE
   
      
    

                                                            
      
    
#define DSI_ACKNOWLEDGE_DISABLE   0x00000000U
#define DSI_ACKNOWLEDGE_ENABLE    DSI_CMCR_ARE
   
      
    

                                                                    
      
    
#define DSI_LP_GSW0P_DISABLE     0x00000000U
#define DSI_LP_GSW0P_ENABLE      DSI_CMCR_GSW0TX
   
      
    

                                                                      
      
    
#define DSI_LP_GSW1P_DISABLE     0x00000000U
#define DSI_LP_GSW1P_ENABLE      DSI_CMCR_GSW1TX
   
      
    

                                                                      
      
    
#define DSI_LP_GSW2P_DISABLE     0x00000000U
#define DSI_LP_GSW2P_ENABLE      DSI_CMCR_GSW2TX
   
      
    

                                                                  
      
    
#define DSI_LP_GSR0P_DISABLE     0x00000000U
#define DSI_LP_GSR0P_ENABLE      DSI_CMCR_GSR0TX
   
      
    

                                                                    
      
    
#define DSI_LP_GSR1P_DISABLE     0x00000000U
#define DSI_LP_GSR1P_ENABLE      DSI_CMCR_GSR1TX
   
      
    

                                                                    
      
    
#define DSI_LP_GSR2P_DISABLE     0x00000000U
#define DSI_LP_GSR2P_ENABLE      DSI_CMCR_GSR2TX
   
      
    

                                                          
      
    
#define DSI_LP_GLW_DISABLE       0x00000000U
#define DSI_LP_GLW_ENABLE        DSI_CMCR_GLWTX
   
      
    

                                                                    
      
    
#define DSI_LP_DSW0P_DISABLE     0x00000000U
#define DSI_LP_DSW0P_ENABLE      DSI_CMCR_DSW0TX
   
      
    

                                                                      
      
    
#define DSI_LP_DSW1P_DISABLE     0x00000000U
#define DSI_LP_DSW1P_ENABLE      DSI_CMCR_DSW1TX
   
      
    

                                                                  
      
    
#define DSI_LP_DSR0P_DISABLE     0x00000000U
#define DSI_LP_DSR0P_ENABLE      DSI_CMCR_DSR0TX
   
      
    

                                                           
      
    
#define DSI_LP_DLW_DISABLE       0x00000000U
#define DSI_LP_DLW_ENABLE        DSI_CMCR_DLWTX
   
      
    

                                                             
      
    
#define DSI_LP_MRDP_DISABLE      0x00000000U
#define DSI_LP_MRDP_ENABLE       DSI_CMCR_MRDPS
   
      
    

                                                
      
    
#define DSI_HS_PM_DISABLE        0x00000000U
#define DSI_HS_PM_ENABLE         DSI_TCCR3_PM
   
      
    


                                                                           
      
    
#define DSI_AUTO_CLK_LANE_CTRL_DISABLE 0x00000000U
#define DSI_AUTO_CLK_LANE_CTRL_ENABLE  DSI_CLCR_ACR
   
      
    

                                                     
      
    
#define DSI_ONE_DATA_LANE          0U
#define DSI_TWO_DATA_LANES         1U
   
      
    

                                              
      
    
#define DSI_FLOW_CONTROL_CRC_RX    DSI_PCR_CRCRXE
#define DSI_FLOW_CONTROL_ECC_RX    DSI_PCR_ECCRXE
#define DSI_FLOW_CONTROL_BTA       DSI_PCR_BTAE
#define DSI_FLOW_CONTROL_EOTP_RX   DSI_PCR_ETRXE
#define DSI_FLOW_CONTROL_EOTP_TX   DSI_PCR_ETTXE
#define DSI_FLOW_CONTROL_ALL       (DSI_FLOW_CONTROL_CRC_RX | DSI_FLOW_CONTROL_ECC_RX  | \
                                    DSI_FLOW_CONTROL_BTA    | DSI_FLOW_CONTROL_EOTP_RX | \
                                    DSI_FLOW_CONTROL_EOTP_TX)
   
      
    

                                               
      
    
#define DSI_RGB565                 0x00000000U                                                                                                      
#define DSI_RGB666                 0x00000003U                                                                                                      
#define DSI_RGB888                 0x00000005U
   
      
    

                                                  
      
    
#define DSI_LOOSELY_PACKED_ENABLE  DSI_LCOLCR_LPE
#define DSI_LOOSELY_PACKED_DISABLE 0x00000000U
   
      
    

                                                   
      
    
#define DSI_HSYNC_ACTIVE_HIGH       0x00000000U
#define DSI_HSYNC_ACTIVE_LOW        DSI_LPCR_HSP
   
      
    

                                                                 
      
    
#define DSI_VSYNC_ACTIVE_HIGH       0x00000000U
#define DSI_VSYNC_ACTIVE_LOW        DSI_LPCR_VSP
   
      
    

                                                               
      
    
#define DSI_DATA_ENABLE_ACTIVE_HIGH 0x00000000U
#define DSI_DATA_ENABLE_ACTIVE_LOW  DSI_LPCR_DEP
   
      
    

                                     
      
    
#define DSI_PLL_IN_DIV1             0x00000001U
#define DSI_PLL_IN_DIV2             0x00000002U
#define DSI_PLL_IN_DIV3             0x00000003U
#define DSI_PLL_IN_DIV4             0x00000004U
#define DSI_PLL_IN_DIV5             0x00000005U
#define DSI_PLL_IN_DIV6             0x00000006U
#define DSI_PLL_IN_DIV7             0x00000007U
   
      
    

                                     
      
    
#define DSI_PLL_OUT_DIV1            0x00000000U
#define DSI_PLL_OUT_DIV2            0x00000001U
#define DSI_PLL_OUT_DIV4            0x00000002U
#define DSI_PLL_OUT_DIV8            0x00000003U
   
      
    

                                 
      
    
#define DSI_FLAG_TE                 DSI_WISR_TEIF
#define DSI_FLAG_ER                 DSI_WISR_ERIF
#define DSI_FLAG_BUSY               DSI_WISR_BUSY
#define DSI_FLAG_PLLLS              DSI_WISR_PLLLS
#define DSI_FLAG_PLLL               DSI_WISR_PLLLIF
#define DSI_FLAG_PLLU               DSI_WISR_PLLUIF
#define DSI_FLAG_RRS                DSI_WISR_RRS
#define DSI_FLAG_RR                 DSI_WISR_RRIF
   
      
    

                                           
      
    
#define DSI_IT_TE                   DSI_WIER_TEIE
#define DSI_IT_ER                   DSI_WIER_ERIE
#define DSI_IT_PLLL                 DSI_WIER_PLLLIE
#define DSI_IT_PLLU                 DSI_WIER_PLLUIE
#define DSI_IT_RR                   DSI_WIER_RRIE
   
      
    

                                                                         
      
    
#define DSI_DCS_SHORT_PKT_WRITE_P0  0x00000005U                                            
#define DSI_DCS_SHORT_PKT_WRITE_P1  0x00000015U                                            
#define DSI_GEN_SHORT_PKT_WRITE_P0  0x00000003U                                            
#define DSI_GEN_SHORT_PKT_WRITE_P1  0x00000013U                                            
#define DSI_GEN_SHORT_PKT_WRITE_P2  0x00000023U                                            
   
      
    

                                                                       
      
    
#define DSI_DCS_LONG_PKT_WRITE      0x00000039U                           
#define DSI_GEN_LONG_PKT_WRITE      0x00000029U                           
   
      
    

                                                                       
      
    
#define DSI_DCS_SHORT_PKT_READ      0x00000006U                                           
#define DSI_GEN_SHORT_PKT_READ_P0   0x00000004U                                           
#define DSI_GEN_SHORT_PKT_READ_P1   0x00000014U                                           
#define DSI_GEN_SHORT_PKT_READ_P2   0x00000024U                                           
   
      
    

                                                     
      
    
#define HAL_DSI_ERROR_NONE              0U
#define HAL_DSI_ERROR_ACK               0x00000001U                                       
#define HAL_DSI_ERROR_PHY               0x00000002U                                       
#define HAL_DSI_ERROR_TX                0x00000004U                                       
#define HAL_DSI_ERROR_RX                0x00000008U                                       
#define HAL_DSI_ERROR_ECC               0x00000010U                                       
#define HAL_DSI_ERROR_CRC               0x00000020U                                       
#define HAL_DSI_ERROR_PSE               0x00000040U                                       
#define HAL_DSI_ERROR_EOT               0x00000080U                                       
#define HAL_DSI_ERROR_OVF               0x00000100U                                       
#define HAL_DSI_ERROR_GEN               0x00000200U                                       
#if (USE_HAL_DSI_REGISTER_CALLBACKS == 1)
#define HAL_DSI_ERROR_INVALID_CALLBACK  0x00000400U                                        
#endif                                     
   
      
    

                                           
      
    
#define DSI_CLOCK_LANE              0x00000000U
#define DSI_DATA_LANES              0x00000001U
   
      
    

                                                             
      
    
#define DSI_SLEW_RATE_HSTX          0x00000000U
#define DSI_SLEW_RATE_LPTX          0x00000001U
#define DSI_HS_DELAY                0x00000002U
   
      
    

                                           
      
    
#define DSI_SWAP_LANE_PINS          0x00000000U
#define DSI_INVERT_HS_SIGNAL        0x00000001U
   
      
    

                                             
      
    
#define DSI_CLK_LANE                0x00000000U
#define DSI_DATA_LANE0              0x00000001U
#define DSI_DATA_LANE1              0x00000002U
   
      
    

                                           
      
    
#define DSI_TCLK_POST               0x00000000U
#define DSI_TLPX_CLK                0x00000001U
#define DSI_THS_EXIT                0x00000002U
#define DSI_TLPX_DATA               0x00000003U
#define DSI_THS_ZERO                0x00000004U
#define DSI_THS_TRAIL               0x00000005U
#define DSI_THS_PREPARE             0x00000006U
#define DSI_TCLK_ZERO               0x00000007U
#define DSI_TCLK_PREPARE            0x00000008U
   
      
    


   
      
    

                                                                                
                                                     
      
    

   
                                  
                                 
                
    
#if (USE_HAL_DSI_REGISTER_CALLBACKS == 1)
#define __HAL_DSI_RESET_HANDLE_STATE(__HANDLE__) do{                                               \
                                                     (__HANDLE__)->State = HAL_DSI_STATE_RESET;    \
                                                     (__HANDLE__)->MspInitCallback = NULL;         \
                                                     (__HANDLE__)->MspDeInitCallback = NULL;       \
                                                   } while(0)
#else
#define __HAL_DSI_RESET_HANDLE_STATE(__HANDLE__) ((__HANDLE__)->State = HAL_DSI_STATE_RESET)
#endif                                    

   
                                 
                                  
                 
    
#define __HAL_DSI_ENABLE(__HANDLE__) do { \
                                          __IO uint32_t tmpreg = 0x00U; \
                                          SET_BIT((__HANDLE__)->Instance->CR, DSI_CR_EN);\
                                                                                 \
                                          tmpreg = READ_BIT((__HANDLE__)->Instance->CR, DSI_CR_EN);\
                                          UNUSED(tmpreg); \
                                        } while(0U)

   
                                  
                                  
                 
    
#define __HAL_DSI_DISABLE(__HANDLE__) do { \
                                           __IO uint32_t tmpreg = 0x00U; \
                                           CLEAR_BIT((__HANDLE__)->Instance->CR, DSI_CR_EN);\
                                                                                   \
                                           tmpreg = READ_BIT((__HANDLE__)->Instance->CR, DSI_CR_EN);\
                                           UNUSED(tmpreg); \
                                         } while(0U)

   
                                    
                                  
                 
    
#define __HAL_DSI_WRAPPER_ENABLE(__HANDLE__) do { \
                                                  __IO uint32_t tmpreg = 0x00U; \
                                                  SET_BIT((__HANDLE__)->Instance->WCR, DSI_WCR_DSIEN);\
                                                                                            \
                                                  tmpreg = READ_BIT((__HANDLE__)->Instance->WCR, DSI_WCR_DSIEN);\
                                                  UNUSED(tmpreg); \
                                                } while(0U)

   
                                    
                                  
                 
    
#define __HAL_DSI_WRAPPER_DISABLE(__HANDLE__) do { \
                                                   __IO uint32_t tmpreg = 0x00U; \
                                                   CLEAR_BIT((__HANDLE__)->Instance->WCR, DSI_WCR_DSIEN);\
                                                                                             \
                                                   tmpreg = READ_BIT((__HANDLE__)->Instance->WCR, DSI_WCR_DSIEN);\
                                                   UNUSED(tmpreg); \
                                                 } while(0U)

   
                                
                                  
                 
    
#define __HAL_DSI_PLL_ENABLE(__HANDLE__) do { \
                                              __IO uint32_t tmpreg = 0x00U; \
                                              SET_BIT((__HANDLE__)->Instance->WRPCR, DSI_WRPCR_PLLEN);\
                                                                                    \
                                              tmpreg = READ_BIT((__HANDLE__)->Instance->WRPCR, DSI_WRPCR_PLLEN);\
                                              UNUSED(tmpreg); \
                                            } while(0U)

   
                                 
                                  
                 
    
#define __HAL_DSI_PLL_DISABLE(__HANDLE__) do { \
                                               __IO uint32_t tmpreg = 0x00U; \
                                               CLEAR_BIT((__HANDLE__)->Instance->WRPCR, DSI_WRPCR_PLLEN);\
                                                                                      \
                                               tmpreg = READ_BIT((__HANDLE__)->Instance->WRPCR, DSI_WRPCR_PLLEN);\
                                               UNUSED(tmpreg); \
                                             } while(0U)

   
                                      
                                  
                 
    
#define __HAL_DSI_REG_ENABLE(__HANDLE__) do { \
                                              __IO uint32_t tmpreg = 0x00U; \
                                              SET_BIT((__HANDLE__)->Instance->WRPCR, DSI_WRPCR_REGEN);\
                                                                                          \
                                              tmpreg = READ_BIT((__HANDLE__)->Instance->WRPCR, DSI_WRPCR_REGEN);\
                                              UNUSED(tmpreg); \
                                            } while(0U)

   
                                       
                                  
                 
    
#define __HAL_DSI_REG_DISABLE(__HANDLE__) do { \
                                               __IO uint32_t tmpreg = 0x00U; \
                                               CLEAR_BIT((__HANDLE__)->Instance->WRPCR, DSI_WRPCR_REGEN);\
                                                                                            \
                                               tmpreg = READ_BIT((__HANDLE__)->Instance->WRPCR, DSI_WRPCR_REGEN);\
                                               UNUSED(tmpreg); \
                                             } while(0U)

   
                                      
                                   
                                             
                                                                           
                                                                 
                                                                 
                                             
                                                   
                                                           
                                                             
                                                        
                                                                  
                                             
    
#define __HAL_DSI_GET_FLAG(__HANDLE__, __FLAG__) ((__HANDLE__)->Instance->WISR & (__FLAG__))

   
                                         
                                   
                                                  
                                                                           
                                                                 
                                                                 
                                                           
                                                             
                                                                  
                
    
#define __HAL_DSI_CLEAR_FLAG(__HANDLE__, __FLAG__) ((__HANDLE__)->Instance->WIFCR = (__FLAG__))

   
                                                 
                                   
                                                                            
                                                                           
                                                         
                                                         
                                                   
                                                     
                                                          
                
    
#define __HAL_DSI_ENABLE_IT(__HANDLE__, __INTERRUPT__) ((__HANDLE__)->Instance->WIER |= (__INTERRUPT__))

   
                                                  
                                  
                                                                             
                                                                           
                                                         
                                                         
                                                   
                                                     
                                                          
                
    
#define __HAL_DSI_DISABLE_IT(__HANDLE__, __INTERRUPT__) ((__HANDLE__)->Instance->WIER &= ~(__INTERRUPT__))

   
                                                                                
                                  
                                                                       
                                                               
                                                         
                                                         
                                                   
                                                     
                                                          
                                                  
    
#define __HAL_DSI_GET_IT_SOURCE(__HANDLE__, __INTERRUPT__) ((__HANDLE__)->Instance->WIER & (__INTERRUPT__))

   
      
    

                                                                                
                                                           
      
    
                                                                   
                                                        
      
    
HAL_StatusTypeDef HAL_DSI_Init(DSI_HandleTypeDef *hdsi, DSI_PLLInitTypeDef *PLLInit);
HAL_StatusTypeDef HAL_DSI_DeInit(DSI_HandleTypeDef *hdsi);
void HAL_DSI_MspInit(DSI_HandleTypeDef *hdsi);
void HAL_DSI_MspDeInit(DSI_HandleTypeDef *hdsi);
HAL_StatusTypeDef HAL_DSI_ConfigErrorMonitor(DSI_HandleTypeDef *hdsi, uint32_t ActiveErrors);
                                                                                
#if (USE_HAL_DSI_REGISTER_CALLBACKS == 1)
HAL_StatusTypeDef HAL_DSI_RegisterCallback(DSI_HandleTypeDef *hdsi, HAL_DSI_CallbackIDTypeDef CallbackID,
                                           pDSI_CallbackTypeDef pCallback);
HAL_StatusTypeDef HAL_DSI_UnRegisterCallback(DSI_HandleTypeDef *hdsi, HAL_DSI_CallbackIDTypeDef CallbackID);
#endif                                     
   
      
    

                                               
                                     
      
    
void HAL_DSI_IRQHandler(DSI_HandleTypeDef *hdsi);
void HAL_DSI_TearingEffectCallback(DSI_HandleTypeDef *hdsi);
void HAL_DSI_EndOfRefreshCallback(DSI_HandleTypeDef *hdsi);
void HAL_DSI_ErrorCallback(DSI_HandleTypeDef *hdsi);
   
      
    

                                                     
                                           
      
    
HAL_StatusTypeDef HAL_DSI_SetGenericVCID(DSI_HandleTypeDef *hdsi, uint32_t VirtualChannelID);
HAL_StatusTypeDef HAL_DSI_ConfigVideoMode(DSI_HandleTypeDef *hdsi, DSI_VidCfgTypeDef *VidCfg);
HAL_StatusTypeDef HAL_DSI_ConfigAdaptedCommandMode(DSI_HandleTypeDef *hdsi, DSI_CmdCfgTypeDef *CmdCfg);
HAL_StatusTypeDef HAL_DSI_ConfigCommand(DSI_HandleTypeDef *hdsi, DSI_LPCmdTypeDef *LPCmd);
HAL_StatusTypeDef HAL_DSI_ConfigFlowControl(DSI_HandleTypeDef *hdsi, uint32_t FlowControl);
HAL_StatusTypeDef HAL_DSI_ConfigPhyTimer(DSI_HandleTypeDef *hdsi, DSI_PHY_TimerTypeDef *PhyTimers);
HAL_StatusTypeDef HAL_DSI_ConfigHostTimeouts(DSI_HandleTypeDef *hdsi, DSI_HOST_TimeoutTypeDef *HostTimeouts);
HAL_StatusTypeDef HAL_DSI_Start(DSI_HandleTypeDef *hdsi);
HAL_StatusTypeDef HAL_DSI_Stop(DSI_HandleTypeDef *hdsi);
HAL_StatusTypeDef HAL_DSI_Refresh(DSI_HandleTypeDef *hdsi);
HAL_StatusTypeDef HAL_DSI_ColorMode(DSI_HandleTypeDef *hdsi, uint32_t ColorMode);
HAL_StatusTypeDef HAL_DSI_Shutdown(DSI_HandleTypeDef *hdsi, uint32_t Shutdown);
HAL_StatusTypeDef HAL_DSI_ShortWrite(DSI_HandleTypeDef *hdsi,
                                     uint32_t ChannelID,
                                     uint32_t Mode,
                                     uint32_t Param1,
                                     uint32_t Param2);
HAL_StatusTypeDef HAL_DSI_LongWrite(DSI_HandleTypeDef *hdsi,
                                    uint32_t ChannelID,
                                    uint32_t Mode,
                                    uint32_t NbParams,
                                    uint32_t Param1,
                                    const uint8_t *ParametersTable);
HAL_StatusTypeDef HAL_DSI_Read(DSI_HandleTypeDef *hdsi,
                               uint32_t ChannelNbr,
                               uint8_t *Array,
                               uint32_t Size,
                               uint32_t Mode,
                               uint32_t DCSCmd,
                               uint8_t *ParametersTable);
HAL_StatusTypeDef HAL_DSI_EnterULPMData(DSI_HandleTypeDef *hdsi);
HAL_StatusTypeDef HAL_DSI_ExitULPMData(DSI_HandleTypeDef *hdsi);
HAL_StatusTypeDef HAL_DSI_EnterULPM(DSI_HandleTypeDef *hdsi);
HAL_StatusTypeDef HAL_DSI_ExitULPM(DSI_HandleTypeDef *hdsi);

HAL_StatusTypeDef HAL_DSI_PatternGeneratorStart(DSI_HandleTypeDef *hdsi, uint32_t Mode, uint32_t Orientation);
HAL_StatusTypeDef HAL_DSI_PatternGeneratorStop(DSI_HandleTypeDef *hdsi);

HAL_StatusTypeDef HAL_DSI_SetSlewRateAndDelayTuning(DSI_HandleTypeDef *hdsi, uint32_t CommDelay, uint32_t Lane,
                                                    uint32_t Value);
HAL_StatusTypeDef HAL_DSI_SetLowPowerRXFilter(DSI_HandleTypeDef *hdsi, uint32_t Frequency);
HAL_StatusTypeDef HAL_DSI_SetSDD(DSI_HandleTypeDef *hdsi, FunctionalState State);
HAL_StatusTypeDef HAL_DSI_SetLanePinsConfiguration(DSI_HandleTypeDef *hdsi, uint32_t CustomLane, uint32_t Lane,
                                                   FunctionalState State);
HAL_StatusTypeDef HAL_DSI_SetPHYTimings(DSI_HandleTypeDef *hdsi, uint32_t Timing, FunctionalState State,
                                        uint32_t Value);
HAL_StatusTypeDef HAL_DSI_ForceTXStopMode(DSI_HandleTypeDef *hdsi, uint32_t Lane, FunctionalState State);
HAL_StatusTypeDef HAL_DSI_ForceRXLowPower(DSI_HandleTypeDef *hdsi, FunctionalState State);
HAL_StatusTypeDef HAL_DSI_ForceDataLanesInRX(DSI_HandleTypeDef *hdsi, FunctionalState State);
HAL_StatusTypeDef HAL_DSI_SetPullDown(DSI_HandleTypeDef *hdsi, FunctionalState State);
HAL_StatusTypeDef HAL_DSI_SetContentionDetectionOff(DSI_HandleTypeDef *hdsi, FunctionalState State);

   
      
    

                                                              
                                                    
      
    
uint32_t HAL_DSI_GetError(const DSI_HandleTypeDef *hdsi);
HAL_DSI_StateTypeDef HAL_DSI_GetState(const DSI_HandleTypeDef *hdsi);

   
      
    

   
      
    

                                                                                
                                                                                
                                                                                
                                                                                
                                                         
      
    
#define DSI_MAX_RETURN_PKT_SIZE (0x00000037U)                                            
   
      
    

                                                                                
                                                   
      
    
#define IS_DSI_PLL_NDIV(NDIV)                       ((10U <= (NDIV)) && ((NDIV) <= 125U))
#define IS_DSI_PLL_IDF(IDF)                         (((IDF) == DSI_PLL_IN_DIV1) || \
                                                     ((IDF) == DSI_PLL_IN_DIV2) || \
                                                     ((IDF) == DSI_PLL_IN_DIV3) || \
                                                     ((IDF) == DSI_PLL_IN_DIV4) || \
                                                     ((IDF) == DSI_PLL_IN_DIV5) || \
                                                     ((IDF) == DSI_PLL_IN_DIV6) || \
                                                     ((IDF) == DSI_PLL_IN_DIV7))
#define IS_DSI_PLL_ODF(ODF)                         (((ODF) == DSI_PLL_OUT_DIV1) || \
                                                     ((ODF) == DSI_PLL_OUT_DIV2) || \
                                                     ((ODF) == DSI_PLL_OUT_DIV4) || \
                                                     ((ODF) == DSI_PLL_OUT_DIV8))
#define IS_DSI_AUTO_CLKLANE_CONTROL(AutoClkLane)    (((AutoClkLane) == DSI_AUTO_CLK_LANE_CTRL_DISABLE)\
                                                     || ((AutoClkLane) == DSI_AUTO_CLK_LANE_CTRL_ENABLE))
#define IS_DSI_NUMBER_OF_LANES(NumberOfLanes)       (((NumberOfLanes) == DSI_ONE_DATA_LANE)\
                                                     || ((NumberOfLanes) == DSI_TWO_DATA_LANES))
#define IS_DSI_FLOW_CONTROL(FlowControl)            (((FlowControl) | DSI_FLOW_CONTROL_ALL) == DSI_FLOW_CONTROL_ALL)
#define IS_DSI_COLOR_CODING(ColorCoding)            ((ColorCoding) <= 5U)
#define IS_DSI_LOOSELY_PACKED(LooselyPacked)        (((LooselyPacked) == DSI_LOOSELY_PACKED_ENABLE)\
                                                     || ((LooselyPacked) == DSI_LOOSELY_PACKED_DISABLE))
#define IS_DSI_DE_POLARITY(DataEnable)              (((DataEnable) == DSI_DATA_ENABLE_ACTIVE_HIGH)\
                                                     || ((DataEnable) == DSI_DATA_ENABLE_ACTIVE_LOW))
#define IS_DSI_VSYNC_POLARITY(Vsync)                (((Vsync) == DSI_VSYNC_ACTIVE_HIGH)\
                                                     || ((Vsync) == DSI_VSYNC_ACTIVE_LOW))
#define IS_DSI_HSYNC_POLARITY(Hsync)                (((Hsync) == DSI_HSYNC_ACTIVE_HIGH)\
                                                     || ((Hsync) == DSI_HSYNC_ACTIVE_LOW))
#define IS_DSI_VIDEO_MODE_TYPE(VideoModeType)       (((VideoModeType) == DSI_VID_MODE_NB_PULSES) || \
                                                     ((VideoModeType) == DSI_VID_MODE_NB_EVENTS) || \
                                                     ((VideoModeType) == DSI_VID_MODE_BURST))
#define IS_DSI_COLOR_MODE(ColorMode)                (((ColorMode) == DSI_COLOR_MODE_FULL)\
                                                     || ((ColorMode) == DSI_COLOR_MODE_EIGHT))
#define IS_DSI_SHUT_DOWN(ShutDown)                  (((ShutDown) == DSI_DISPLAY_ON) || ((ShutDown) == DSI_DISPLAY_OFF))
#define IS_DSI_LP_COMMAND(LPCommand)                (((LPCommand) == DSI_LP_COMMAND_DISABLE)\
                                                     || ((LPCommand) == DSI_LP_COMMAND_ENABLE))
#define IS_DSI_LP_HFP(LPHFP)                        (((LPHFP) == DSI_LP_HFP_DISABLE) || ((LPHFP) == DSI_LP_HFP_ENABLE))
#define IS_DSI_LP_HBP(LPHBP)                        (((LPHBP) == DSI_LP_HBP_DISABLE) || ((LPHBP) == DSI_LP_HBP_ENABLE))
#define IS_DSI_LP_VACTIVE(LPVActive)                (((LPVActive) == DSI_LP_VACT_DISABLE)\
                                                     || ((LPVActive) == DSI_LP_VACT_ENABLE))
#define IS_DSI_LP_VFP(LPVFP)                        (((LPVFP) == DSI_LP_VFP_DISABLE) || ((LPVFP) == DSI_LP_VFP_ENABLE))
#define IS_DSI_LP_VBP(LPVBP)                        (((LPVBP) == DSI_LP_VBP_DISABLE) || ((LPVBP) == DSI_LP_VBP_ENABLE))
#define IS_DSI_LP_VSYNC(LPVSYNC)                    (((LPVSYNC) == DSI_LP_VSYNC_DISABLE)\
                                                     || ((LPVSYNC) == DSI_LP_VSYNC_ENABLE))
#define IS_DSI_FBTAA(FrameBTAAcknowledge)           (((FrameBTAAcknowledge) == DSI_FBTAA_DISABLE)\
                                                     || ((FrameBTAAcknowledge) == DSI_FBTAA_ENABLE))
#define IS_DSI_TE_SOURCE(TESource)                  (((TESource) == DSI_TE_DSILINK) || ((TESource) == DSI_TE_EXTERNAL))
#define IS_DSI_TE_POLARITY(TEPolarity)              (((TEPolarity) == DSI_TE_RISING_EDGE)\
                                                     || ((TEPolarity) == DSI_TE_FALLING_EDGE))
#define IS_DSI_AUTOMATIC_REFRESH(AutomaticRefresh)  (((AutomaticRefresh) == DSI_AR_DISABLE)\
                                                     || ((AutomaticRefresh) == DSI_AR_ENABLE))
#define IS_DSI_VS_POLARITY(VSPolarity)              (((VSPolarity) == DSI_VSYNC_FALLING)\
                                                     || ((VSPolarity) == DSI_VSYNC_RISING))
#define IS_DSI_TE_ACK_REQUEST(TEAcknowledgeRequest) (((TEAcknowledgeRequest) == DSI_TE_ACKNOWLEDGE_DISABLE)\
                                                     || ((TEAcknowledgeRequest) == DSI_TE_ACKNOWLEDGE_ENABLE))
#define IS_DSI_ACK_REQUEST(AcknowledgeRequest)      (((AcknowledgeRequest) == DSI_ACKNOWLEDGE_DISABLE)\
                                                     || ((AcknowledgeRequest) == DSI_ACKNOWLEDGE_ENABLE))
#define IS_DSI_LP_GSW0P(LP_GSW0P)                   (((LP_GSW0P) == DSI_LP_GSW0P_DISABLE)\
                                                     || ((LP_GSW0P) == DSI_LP_GSW0P_ENABLE))
#define IS_DSI_LP_GSW1P(LP_GSW1P)                   (((LP_GSW1P) == DSI_LP_GSW1P_DISABLE)\
                                                     || ((LP_GSW1P) == DSI_LP_GSW1P_ENABLE))
#define IS_DSI_LP_GSW2P(LP_GSW2P)                   (((LP_GSW2P) == DSI_LP_GSW2P_DISABLE)\
                                                     || ((LP_GSW2P) == DSI_LP_GSW2P_ENABLE))
#define IS_DSI_LP_GSR0P(LP_GSR0P)                   (((LP_GSR0P) == DSI_LP_GSR0P_DISABLE)\
                                                     || ((LP_GSR0P) == DSI_LP_GSR0P_ENABLE))
#define IS_DSI_LP_GSR1P(LP_GSR1P)                   (((LP_GSR1P) == DSI_LP_GSR1P_DISABLE)\
                                                     || ((LP_GSR1P) == DSI_LP_GSR1P_ENABLE))
#define IS_DSI_LP_GSR2P(LP_GSR2P)                   (((LP_GSR2P) == DSI_LP_GSR2P_DISABLE)\
                                                     || ((LP_GSR2P) == DSI_LP_GSR2P_ENABLE))
#define IS_DSI_LP_GLW(LP_GLW)                       (((LP_GLW) == DSI_LP_GLW_DISABLE)\
                                                     || ((LP_GLW) == DSI_LP_GLW_ENABLE))
#define IS_DSI_LP_DSW0P(LP_DSW0P)                   (((LP_DSW0P) == DSI_LP_DSW0P_DISABLE)\
                                                     || ((LP_DSW0P) == DSI_LP_DSW0P_ENABLE))
#define IS_DSI_LP_DSW1P(LP_DSW1P)                   (((LP_DSW1P) == DSI_LP_DSW1P_DISABLE)\
                                                     || ((LP_DSW1P) == DSI_LP_DSW1P_ENABLE))
#define IS_DSI_LP_DSR0P(LP_DSR0P)                   (((LP_DSR0P) == DSI_LP_DSR0P_DISABLE)\
                                                     || ((LP_DSR0P) == DSI_LP_DSR0P_ENABLE))
#define IS_DSI_LP_DLW(LP_DLW)                       (((LP_DLW) == DSI_LP_DLW_DISABLE)\
                                                     || ((LP_DLW) == DSI_LP_DLW_ENABLE))
#define IS_DSI_LP_MRDP(LP_MRDP)                     (((LP_MRDP) == DSI_LP_MRDP_DISABLE)\
                                                     || ((LP_MRDP) == DSI_LP_MRDP_ENABLE))
#define IS_DSI_SHORT_WRITE_PACKET_TYPE(MODE)        (((MODE) == DSI_DCS_SHORT_PKT_WRITE_P0) || \
                                                     ((MODE) == DSI_DCS_SHORT_PKT_WRITE_P1) || \
                                                     ((MODE) == DSI_GEN_SHORT_PKT_WRITE_P0) || \
                                                     ((MODE) == DSI_GEN_SHORT_PKT_WRITE_P1) || \
                                                     ((MODE) == DSI_GEN_SHORT_PKT_WRITE_P2))
#define IS_DSI_LONG_WRITE_PACKET_TYPE(MODE)         (((MODE) == DSI_DCS_LONG_PKT_WRITE) || \
                                                     ((MODE) == DSI_GEN_LONG_PKT_WRITE))
#define IS_DSI_READ_PACKET_TYPE(MODE)               (((MODE) == DSI_DCS_SHORT_PKT_READ) || \
                                                     ((MODE) == DSI_GEN_SHORT_PKT_READ_P0) || \
                                                     ((MODE) == DSI_GEN_SHORT_PKT_READ_P1) || \
                                                     ((MODE) == DSI_GEN_SHORT_PKT_READ_P2))
#define IS_DSI_COMMUNICATION_DELAY(CommDelay)       (((CommDelay) == DSI_SLEW_RATE_HSTX) || \
                                                     ((CommDelay) == DSI_SLEW_RATE_LPTX) || \
                                                     ((CommDelay) == DSI_HS_DELAY))
#define IS_DSI_LANE_GROUP(Lane)                     (((Lane) == DSI_CLOCK_LANE) || ((Lane) == DSI_DATA_LANES))
#define IS_DSI_CUSTOM_LANE(CustomLane)              (((CustomLane) == DSI_SWAP_LANE_PINS)\
                                                     || ((CustomLane) == DSI_INVERT_HS_SIGNAL))
#define IS_DSI_LANE(Lane)                           (((Lane) == DSI_CLOCK_LANE) || \
                                                     ((Lane) == DSI_DATA_LANE0) || ((Lane) == DSI_DATA_LANE1))
#define IS_DSI_PHY_TIMING(Timing)                   (((Timing) == DSI_TCLK_POST   ) || \
                                                     ((Timing) == DSI_TLPX_CLK    ) || \
                                                     ((Timing) == DSI_THS_EXIT    ) || \
                                                     ((Timing) == DSI_TLPX_DATA   ) || \
                                                     ((Timing) == DSI_THS_ZERO    ) || \
                                                     ((Timing) == DSI_THS_TRAIL   ) || \
                                                     ((Timing) == DSI_THS_PREPARE ) || \
                                                     ((Timing) == DSI_TCLK_ZERO   ) || \
                                                     ((Timing) == DSI_TCLK_PREPARE))

   
      
    

   
      
    

   
      
    
#endif          

#ifdef __cplusplus
}
#endif

#endif                          
