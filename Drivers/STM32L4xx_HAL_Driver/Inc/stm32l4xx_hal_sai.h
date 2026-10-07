/**
  ******************************************************************************
  * @file    stm32l4xx_hal_sai.h
  * @author  MCD Application Team
  * @brief   Header file of SAI HAL module.
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

                                                                                
#ifndef STM32L4xx_HAL_SAI_H
#define STM32L4xx_HAL_SAI_H

#ifdef __cplusplus
extern "C" {
#endif

#if !defined(STM32L412xx) && !defined(STM32L422xx)

                                                                                
#include "stm32l4xx_hal_def.h"

                                    
      
    

                   
      
    

                                                                                
                                                   
      
    

   
                                           
    
typedef enum
{
  HAL_SAI_STATE_RESET   = 0x00U,                                             
  HAL_SAI_STATE_READY   = 0x01U,                                             
  HAL_SAI_STATE_BUSY    = 0x02U,                                             
  HAL_SAI_STATE_BUSY_TX = 0x12U,                                             
  HAL_SAI_STATE_BUSY_RX = 0x22U,                                             
} HAL_SAI_StateTypeDef;

   
                                  
    
typedef void (*SAIcallback)(void);

#if defined(STM32L4R5xx) || defined(STM32L4R7xx) || defined(STM32L4R9xx) || defined(STM32L4S5xx) || defined(STM32L4S7xx) || defined(STM32L4S9xx) || \
    defined(STM32L4P5xx) || defined(STM32L4Q5xx)
                                                                       
                                             
      
    
typedef struct
{
  FunctionalState  Activation;                                      
  uint32_t         MicPairsNbr;                                                    
                                                                                                              
  uint32_t         ClockEnable;                                            
                                                                                                              
} SAI_PdmInitTypeDef;
   
      
    
#endif                                                                                                
                                

                                                                         
                                         
      
    
typedef struct
{
  uint32_t AudioMode;                                                   
                                                                                            

  uint32_t Synchro;                                                     
                                                                                                       

  uint32_t SynchroExt;                                                                                  
                                                          
                                                                                            
                                                                                                        
                                                                                              

  uint32_t OutputDrive;                                                          
                                                                                                 
                                                                                                   
                                                                                      

  uint32_t NoDivider;                                                                      
                                                                                              
                                                                            
                                                                                                               
                                                                                                                
                                                                                                               
                                                                                                                
                                                                 
                                                              
                                                                                                               
                                                                                                                
                                                                                                               
                                                                                                               
                                                                                              
                                                                                             

  uint32_t FIFOThreshold;                                               
                                                                                                      

  uint32_t AudioFrequency;                                                  
                                                                                                 

  uint32_t Mckdiv;                                                      
                                                                                                                                           
                                                                                                                             
                                                                                                  
                                                                                                             

#if defined(STM32L4R5xx) || defined(STM32L4R7xx) || defined(STM32L4R9xx) || defined(STM32L4S5xx) || defined(STM32L4S7xx) || defined(STM32L4S9xx) || \
    defined(STM32L4P5xx) || defined(STM32L4Q5xx)
  uint32_t MckOverSampling;                                                  
                                                                                                        
#endif                                                                                                
                                

  uint32_t MonoStereoMode;                                                            
                                                                                                  

  uint32_t CompandingMode;                                              
                                                                                                       

  uint32_t TriState;                                                    
                                                                                                     

#if defined(STM32L4R5xx) || defined(STM32L4R7xx) || defined(STM32L4R9xx) || defined(STM32L4S5xx) || defined(STM32L4S7xx) || defined(STM32L4S9xx) || \
    defined(STM32L4P5xx) || defined(STM32L4Q5xx)
  SAI_PdmInitTypeDef PdmInit;                                           
#endif                                                                                                
                                

                                                                                                       
                                     

  uint32_t Protocol;                                              
                                                                                            

  uint32_t DataSize;                                               
                                                                                             

  uint32_t FirstBit;                                                                        
                                                                                                        

  uint32_t ClockStrobing;                                                                
                                                                                                  
} SAI_InitTypeDef;
   
      
    

                                                                           
                                               
                                                                                         
      
    
typedef struct
{

  uint32_t FrameLength;                                                                                       
                                                                                                            
                                                                                                               
                                                                                                            
                                                                                                              

  uint32_t ActiveFrameLength;                                                               
                                                                                                        
                                                                                    
                                                                                                              

  uint32_t FSDefinition;                                                           
                                                                                                    

  uint32_t FSPolarity;                                                           
                                                                                                  

  uint32_t FSOffset;                                                           
                                                                                                

} SAI_FrameInitTypeDef;
   
      
    

                                                                         
                                                     
                                                                                 
                                                                                                   
      
    
typedef struct
{
  uint32_t FirstBitOffset;                                                                     
                                                                                                          

  uint32_t SlotSize;                                     
                                                                                             

  uint32_t SlotNumber;                                                           
                                                                                                          

  uint32_t SlotActive;                                                                     
                                                                                               
} SAI_SlotInitTypeDef;
   
      
    

                                                                             
                                           
      
    
typedef struct __SAI_HandleTypeDef
{
  SAI_Block_TypeDef         *Instance;                                             

  SAI_InitTypeDef           Init;                                             

  SAI_FrameInitTypeDef      FrameInit;                                              

  SAI_SlotInitTypeDef       SlotInit;                                              

  uint8_t                  *pBuffPtr;                                           

  uint16_t                  XferSize;                              

  uint16_t                  XferCount;                                

  DMA_HandleTypeDef         *hdmatx;                                          

  DMA_HandleTypeDef         *hdmarx;                                          

  SAIcallback               mutecallback;                          

  void (*InterruptServiceRoutine)(struct __SAI_HandleTypeDef *hsai);                                       

  HAL_LockTypeDef           Lock;                                   

  __IO HAL_SAI_StateTypeDef State;                                       

  __IO uint32_t             ErrorCode;                          

#if (USE_HAL_SAI_REGISTER_CALLBACKS == 1)
  void (*RxCpltCallback)(struct __SAI_HandleTypeDef *hsai);                                           
  void (*RxHalfCpltCallback)(struct __SAI_HandleTypeDef *hsai);                                            
  void (*TxCpltCallback)(struct __SAI_HandleTypeDef *hsai);                                            
  void (*TxHalfCpltCallback)(struct __SAI_HandleTypeDef *hsai);                                             
  void (*ErrorCallback)(struct __SAI_HandleTypeDef *hsai);                                 
  void (*MspInitCallback)(struct __SAI_HandleTypeDef *hsai);                                  
  void (*MspDeInitCallback)(struct __SAI_HandleTypeDef *hsai);                                   
#endif
} SAI_HandleTypeDef;
   
      
    

#if (USE_HAL_SAI_REGISTER_CALLBACKS == 1)
   
                                                  
    
typedef enum
{
  HAL_SAI_RX_COMPLETE_CB_ID     = 0x00U,                                         
  HAL_SAI_RX_HALFCOMPLETE_CB_ID = 0x01U,                                              
  HAL_SAI_TX_COMPLETE_CB_ID     = 0x02U,                                          
  HAL_SAI_TX_HALFCOMPLETE_CB_ID = 0x03U,                                               
  HAL_SAI_ERROR_CB_ID           = 0x04U,                              
  HAL_SAI_MSPINIT_CB_ID         = 0x05U,                                 
  HAL_SAI_MSPDEINIT_CB_ID       = 0x06U                                     
} HAL_SAI_CallbackIDTypeDef;

   
                                           
    
typedef void (*pSAI_CallbackTypeDef)(SAI_HandleTypeDef *hsai);
#endif

   
      
    

                                                                                
                                                           
      
    

                                           
      
    
#define HAL_SAI_ERROR_NONE             0x00000000U                  
#define HAL_SAI_ERROR_OVR              0x00000001U                       
#define HAL_SAI_ERROR_UDR              0x00000002U                        
#define HAL_SAI_ERROR_AFSDET           0x00000004U                                                     
#define HAL_SAI_ERROR_LFSDET           0x00000008U                                              
#define HAL_SAI_ERROR_CNREADY          0x00000010U                         
#define HAL_SAI_ERROR_WCKCFG           0x00000020U                                   
#define HAL_SAI_ERROR_TIMEOUT          0x00000040U                       
#define HAL_SAI_ERROR_DMA              0x00000080U                   
#if (USE_HAL_SAI_REGISTER_CALLBACKS == 1)
#define HAL_SAI_ERROR_INVALID_CALLBACK 0x00000100U                                
#endif
   
      
    

                                                            
      
    
#define SAI_SYNCEXT_DISABLE          0U
#define SAI_SYNCEXT_OUTBLOCKA_ENABLE 1U
#define SAI_SYNCEXT_OUTBLOCKB_ENABLE 2U
   
      
    

                                                 
      
    
#define SAI_I2S_STANDARD      0U
#define SAI_I2S_MSBJUSTIFIED  1U
#define SAI_I2S_LSBJUSTIFIED  2U
#define SAI_PCM_LONG          3U
#define SAI_PCM_SHORT         4U
   
      
    

                                                          
      
    
#define SAI_PROTOCOL_DATASIZE_16BIT         0U
#define SAI_PROTOCOL_DATASIZE_16BITEXTENDED 1U
#define SAI_PROTOCOL_DATASIZE_24BIT         2U
#define SAI_PROTOCOL_DATASIZE_32BIT         3U
   
      
    

                                                     
      
    
#define SAI_AUDIO_FREQUENCY_192K          192000U
#define SAI_AUDIO_FREQUENCY_96K           96000U
#define SAI_AUDIO_FREQUENCY_48K           48000U
#define SAI_AUDIO_FREQUENCY_44K           44100U
#define SAI_AUDIO_FREQUENCY_32K           32000U
#define SAI_AUDIO_FREQUENCY_22K           22050U
#define SAI_AUDIO_FREQUENCY_16K           16000U
#define SAI_AUDIO_FREQUENCY_11K           11025U
#define SAI_AUDIO_FREQUENCY_8K            8000U
#define SAI_AUDIO_FREQUENCY_MCKDIV        0U
   
      
    

#if defined(STM32L4R5xx) || defined(STM32L4R7xx) || defined(STM32L4R9xx) || defined(STM32L4S5xx) || defined(STM32L4S7xx) || defined(STM32L4S9xx) || \
    defined(STM32L4P5xx) || defined(STM32L4Q5xx)
                                                                            
      
    
#define SAI_MCK_OVERSAMPLING_DISABLE      0x00000000U
#define SAI_MCK_OVERSAMPLING_ENABLE       SAI_xCR1_OSR
   
      
    

                                                      
      
    
#define SAI_PDM_CLOCK1_ENABLE     SAI_PDMCR_CKEN1
#define SAI_PDM_CLOCK2_ENABLE     SAI_PDMCR_CKEN2
   
      
    
#endif                                                                                                
                                

                                           
      
    
#define SAI_MODEMASTER_TX         0x00000000U
#define SAI_MODEMASTER_RX         SAI_xCR1_MODE_0
#define SAI_MODESLAVE_TX          SAI_xCR1_MODE_1
#define SAI_MODESLAVE_RX          (SAI_xCR1_MODE_1 | SAI_xCR1_MODE_0)

   
      
    

                                                   
      
    
#define SAI_FREE_PROTOCOL                 0x00000000U
#define SAI_SPDIF_PROTOCOL                SAI_xCR1_PRTCFG_0
#define SAI_AC97_PROTOCOL                 SAI_xCR1_PRTCFG_1
   
      
    

                                                     
      
    
#define SAI_DATASIZE_8     SAI_xCR1_DS_1
#define SAI_DATASIZE_10    (SAI_xCR1_DS_1 | SAI_xCR1_DS_0)
#define SAI_DATASIZE_16    SAI_xCR1_DS_2
#define SAI_DATASIZE_20    (SAI_xCR1_DS_2 | SAI_xCR1_DS_0)
#define SAI_DATASIZE_24    (SAI_xCR1_DS_2 | SAI_xCR1_DS_1)
#define SAI_DATASIZE_32    (SAI_xCR1_DS_2 | SAI_xCR1_DS_1 | SAI_xCR1_DS_0)
   
      
    

                                                                           
      
    
#define SAI_FIRSTBIT_MSB                  0x00000000U
#define SAI_FIRSTBIT_LSB                  SAI_xCR1_LSBFIRST
   
      
    

                                                               
      
    
#define SAI_CLOCKSTROBING_FALLINGEDGE     0U
#define SAI_CLOCKSTROBING_RISINGEDGE      1U
   
      
    

                                                                 
      
    
#define SAI_ASYNCHRONOUS                  0U                     
#define SAI_SYNCHRONOUS                   1U                                                 
#define SAI_SYNCHRONOUS_EXT_SAI1          2U                                         
#define SAI_SYNCHRONOUS_EXT_SAI2          3U                                         
   
      
    

                                                           
      
    
#define SAI_OUTPUTDRIVE_DISABLE          0x00000000U
#define SAI_OUTPUTDRIVE_ENABLE           SAI_xCR1_OUTDRIV
   
      
    

                                                     
      
    
#define SAI_MASTERDIVIDER_ENABLE         0x00000000U
#if defined(STM32L4R5xx) || defined(STM32L4R7xx) || defined(STM32L4R9xx) || defined(STM32L4S5xx) || defined(STM32L4S7xx) || defined(STM32L4S9xx) || \
    defined(STM32L4P5xx) || defined(STM32L4Q5xx)
#define SAI_MASTERDIVIDER_DISABLE        SAI_xCR1_NOMCK
#else
#define SAI_MASTERDIVIDER_DISABLE        SAI_xCR1_NODIV
#endif                                                                                                
                                
   
      
    

                                                             
      
    
#define SAI_FS_STARTFRAME                 0x00000000U
#define SAI_FS_CHANNEL_IDENTIFICATION     SAI_xFRCR_FSDEF
   
      
    

                                                         
      
    
#define SAI_FS_ACTIVE_LOW                  0x00000000U
#define SAI_FS_ACTIVE_HIGH                 SAI_xFRCR_FSPOL
   
      
    

                                                     
      
    
#define SAI_FS_FIRSTBIT                   0x00000000U
#define SAI_FS_BEFOREFIRSTBIT             SAI_xFRCR_FSOFF
   
      
    

                                                     
      
    
#define SAI_SLOTSIZE_DATASIZE             0x00000000U
#define SAI_SLOTSIZE_16B                  SAI_xSLOTR_SLOTSZ_0
#define SAI_SLOTSIZE_32B                  SAI_xSLOTR_SLOTSZ_1
   
      
    

                                                         
      
    
#define SAI_SLOT_NOTACTIVE           0x00000000U
#define SAI_SLOTACTIVE_0             0x00000001U
#define SAI_SLOTACTIVE_1             0x00000002U
#define SAI_SLOTACTIVE_2             0x00000004U
#define SAI_SLOTACTIVE_3             0x00000008U
#define SAI_SLOTACTIVE_4             0x00000010U
#define SAI_SLOTACTIVE_5             0x00000020U
#define SAI_SLOTACTIVE_6             0x00000040U
#define SAI_SLOTACTIVE_7             0x00000080U
#define SAI_SLOTACTIVE_8             0x00000100U
#define SAI_SLOTACTIVE_9             0x00000200U
#define SAI_SLOTACTIVE_10            0x00000400U
#define SAI_SLOTACTIVE_11            0x00000800U
#define SAI_SLOTACTIVE_12            0x00001000U
#define SAI_SLOTACTIVE_13            0x00002000U
#define SAI_SLOTACTIVE_14            0x00004000U
#define SAI_SLOTACTIVE_15            0x00008000U
#define SAI_SLOTACTIVE_ALL           0x0000FFFFU
   
      
    

                                                       
      
    
#define SAI_STEREOMODE               0x00000000U
#define SAI_MONOMODE                 SAI_xCR1_MONO
   
      
    

                                                             
      
    
#define SAI_OUTPUT_NOTRELEASED    0x00000000U
#define SAI_OUTPUT_RELEASED       SAI_xCR2_TRIS
   
      
    

                                                               
      
    
#define SAI_FIFOTHRESHOLD_EMPTY  0x00000000U
#define SAI_FIFOTHRESHOLD_1QF    SAI_xCR2_FTH_0
#define SAI_FIFOTHRESHOLD_HF     SAI_xCR2_FTH_1
#define SAI_FIFOTHRESHOLD_3QF    (SAI_xCR2_FTH_1 | SAI_xCR2_FTH_0)
#define SAI_FIFOTHRESHOLD_FULL   SAI_xCR2_FTH_2
   
      
    

                                                                 
      
    
#define SAI_NOCOMPANDING                 0x00000000U
#define SAI_ULAW_1CPL_COMPANDING         SAI_xCR2_COMP_1
#define SAI_ALAW_1CPL_COMPANDING         (SAI_xCR2_COMP_1 | SAI_xCR2_COMP_0)
#define SAI_ULAW_2CPL_COMPANDING         (SAI_xCR2_COMP_1 | SAI_xCR2_CPL)
#define SAI_ALAW_2CPL_COMPANDING         (SAI_xCR2_COMP_1 | SAI_xCR2_COMP_0 | SAI_xCR2_CPL)
   
      
    

                                                       
      
    
#define SAI_ZERO_VALUE                     0x00000000U
#define SAI_LAST_SENT_VALUE                SAI_xCR2_MUTEVAL
   
      
    

                                                                             
      
    
#define SAI_IT_OVRUDR                     SAI_xIMR_OVRUDRIE
#define SAI_IT_MUTEDET                    SAI_xIMR_MUTEDETIE
#define SAI_IT_WCKCFG                     SAI_xIMR_WCKCFGIE
#define SAI_IT_FREQ                       SAI_xIMR_FREQIE
#define SAI_IT_CNRDY                      SAI_xIMR_CNRDYIE
#define SAI_IT_AFSDET                     SAI_xIMR_AFSDETIE
#define SAI_IT_LFSDET                     SAI_xIMR_LFSDETIE
   
      
    

                                                                    
      
    
#define SAI_FLAG_OVRUDR                   SAI_xSR_OVRUDR
#define SAI_FLAG_MUTEDET                  SAI_xSR_MUTEDET
#define SAI_FLAG_WCKCFG                   SAI_xSR_WCKCFG
#define SAI_FLAG_FREQ                     SAI_xSR_FREQ
#define SAI_FLAG_CNRDY                    SAI_xSR_CNRDY
#define SAI_FLAG_AFSDET                   SAI_xSR_AFSDET
#define SAI_FLAG_LFSDET                   SAI_xSR_LFSDET
   
      
    

                                                                       
      
    
#define SAI_FIFOSTATUS_EMPTY              0x00000000U
#define SAI_FIFOSTATUS_LESS1QUARTERFULL   0x00010000U
#define SAI_FIFOSTATUS_1QUARTERFULL       0x00020000U
#define SAI_FIFOSTATUS_HALFFULL           0x00030000U
#define SAI_FIFOSTATUS_3QUARTERFULL       0x00040000U
#define SAI_FIFOSTATUS_FULL               0x00050000U
   
      
    

   
      
    

                                                                                
                                                     
                                                                  
      
    

                                  
                                                
                
    
#if (USE_HAL_SAI_REGISTER_CALLBACKS == 1)
#define __HAL_SAI_RESET_HANDLE_STATE(__HANDLE__) do{                                            \
                                                     (__HANDLE__)->State = HAL_SAI_STATE_RESET; \
                                                     (__HANDLE__)->MspInitCallback = NULL;      \
                                                     (__HANDLE__)->MspDeInitCallback = NULL;    \
                                                   } while(0)
#else
#define __HAL_SAI_RESET_HANDLE_STATE(__HANDLE__) ((__HANDLE__)->State = HAL_SAI_STATE_RESET)
#endif

                                                
                                                
                                                                              
                                                              
                                                                    
                                                                   
                                                                             
                                                              
                                                                  
                                                                                               
                                                                                        
                
    
#define __HAL_SAI_ENABLE_IT(__HANDLE__, __INTERRUPT__)   ((__HANDLE__)->Instance->IMR |= (__INTERRUPT__))

                                                 
                                                
                                                                              
                                                              
                                                                    
                                                                   
                                                                             
                                                              
                                                                  
                                                                                               
                                                                                        
                
    
#define __HAL_SAI_DISABLE_IT(__HANDLE__, __INTERRUPT__)  ((__HANDLE__)->Instance->IMR &= (~(__INTERRUPT__)))

                                                                               
                                                
                                                                      
                                                              
                                                                    
                                                                   
                                                                             
                                                              
                                                                  
                                                                                               
                                                                                        
                                                           
    
#define __HAL_SAI_GET_IT_SOURCE(__HANDLE__, __INTERRUPT__) ((((__HANDLE__)->Instance->IMR & (__INTERRUPT__)) == (__INTERRUPT__)) ? SET : RESET)

                                                               
                                                
                                                 
                                                              
                                                           
                                                          
                                                                    
                                                     
                                                         
                                                                                      
                                                                               
                                                      
    
#define __HAL_SAI_GET_FLAG(__HANDLE__, __FLAG__) ((((__HANDLE__)->Instance->SR) & (__FLAG__)) == (__FLAG__))

                                                 
                                                
                                                 
                                                                           
                                                           
                                                          
                                                                    
                                                     
                                                         
                                                                                      
                                                                               
   
                
    
#define __HAL_SAI_CLEAR_FLAG(__HANDLE__, __FLAG__) ((__HANDLE__)->Instance->CLRFR = (__FLAG__))

                       
                                                
                
    
#define __HAL_SAI_ENABLE(__HANDLE__) ((__HANDLE__)->Instance->CR1 |=  SAI_xCR1_SAIEN)

                        
                                                
                
    
#define __HAL_SAI_DISABLE(__HANDLE__) ((__HANDLE__)->Instance->CR1 &=  ~SAI_xCR1_SAIEN)

   
      
    

#if defined(STM32L4R5xx) || defined(STM32L4R7xx) || defined(STM32L4R9xx) || defined(STM32L4S5xx) || defined(STM32L4S7xx) || defined(STM32L4S9xx) || \
    defined(STM32L4P5xx) || defined(STM32L4Q5xx)
                                      
#include "stm32l4xx_hal_sai_ex.h"
#endif                                                                                                
                                

                                                                                
                                      
      
    

                                                                                
                                             
      
    
HAL_StatusTypeDef HAL_SAI_InitProtocol(SAI_HandleTypeDef *hsai, uint32_t protocol, uint32_t datasize, uint32_t nbslot);
HAL_StatusTypeDef HAL_SAI_Init(SAI_HandleTypeDef *hsai);
HAL_StatusTypeDef HAL_SAI_DeInit(SAI_HandleTypeDef *hsai);
void HAL_SAI_MspInit(SAI_HandleTypeDef *hsai);
void HAL_SAI_MspDeInit(SAI_HandleTypeDef *hsai);

#if (USE_HAL_SAI_REGISTER_CALLBACKS == 1)
                                                                                
HAL_StatusTypeDef HAL_SAI_RegisterCallback(SAI_HandleTypeDef        *hsai,
                                           HAL_SAI_CallbackIDTypeDef CallbackID,
                                           pSAI_CallbackTypeDef      pCallback);
HAL_StatusTypeDef HAL_SAI_UnRegisterCallback(SAI_HandleTypeDef        *hsai,
                                             HAL_SAI_CallbackIDTypeDef CallbackID);
#endif
   
      
    

                                                                                
                                             
      
    
                            
HAL_StatusTypeDef HAL_SAI_Transmit(SAI_HandleTypeDef *hsai, uint8_t *pData, uint16_t Size, uint32_t Timeout);
HAL_StatusTypeDef HAL_SAI_Receive(SAI_HandleTypeDef *hsai, uint8_t *pData, uint16_t Size, uint32_t Timeout);

                                  
HAL_StatusTypeDef HAL_SAI_Transmit_IT(SAI_HandleTypeDef *hsai, uint8_t *pData, uint16_t Size);
HAL_StatusTypeDef HAL_SAI_Receive_IT(SAI_HandleTypeDef *hsai, uint8_t *pData, uint16_t Size);

                            
HAL_StatusTypeDef HAL_SAI_Transmit_DMA(SAI_HandleTypeDef *hsai, uint8_t *pData, uint16_t Size);
HAL_StatusTypeDef HAL_SAI_Receive_DMA(SAI_HandleTypeDef *hsai, uint8_t *pData, uint16_t Size);
HAL_StatusTypeDef HAL_SAI_DMAPause(SAI_HandleTypeDef *hsai);
HAL_StatusTypeDef HAL_SAI_DMAResume(SAI_HandleTypeDef *hsai);
HAL_StatusTypeDef HAL_SAI_DMAStop(SAI_HandleTypeDef *hsai);

                    
HAL_StatusTypeDef HAL_SAI_Abort(SAI_HandleTypeDef *hsai);

                     
HAL_StatusTypeDef HAL_SAI_EnableTxMuteMode(SAI_HandleTypeDef *hsai, uint16_t val);
HAL_StatusTypeDef HAL_SAI_DisableTxMuteMode(SAI_HandleTypeDef *hsai);
HAL_StatusTypeDef HAL_SAI_EnableRxMuteMode(SAI_HandleTypeDef *hsai, SAIcallback callback, uint16_t counter);
HAL_StatusTypeDef HAL_SAI_DisableRxMuteMode(SAI_HandleTypeDef *hsai);

                                                                                 
void HAL_SAI_IRQHandler(SAI_HandleTypeDef *hsai);
void HAL_SAI_TxHalfCpltCallback(SAI_HandleTypeDef *hsai);
void HAL_SAI_TxCpltCallback(SAI_HandleTypeDef *hsai);
void HAL_SAI_RxHalfCpltCallback(SAI_HandleTypeDef *hsai);
void HAL_SAI_RxCpltCallback(SAI_HandleTypeDef *hsai);
void HAL_SAI_ErrorCallback(SAI_HandleTypeDef *hsai);
   
      
    

                                             
      
    
                                                                                
HAL_SAI_StateTypeDef HAL_SAI_GetState(const SAI_HandleTypeDef *hsai);
uint32_t HAL_SAI_GetError(const SAI_HandleTypeDef *hsai);
   
      
    

   
      
    

                                                                                
                                                   
      
    
#define IS_SAI_BLOCK_SYNCEXT(STATE) (((STATE) == SAI_SYNCEXT_DISABLE) ||\
                                     ((STATE) == SAI_SYNCEXT_OUTBLOCKA_ENABLE) ||\
                                     ((STATE) == SAI_SYNCEXT_OUTBLOCKB_ENABLE))

#define IS_SAI_SUPPORTED_PROTOCOL(PROTOCOL)   (((PROTOCOL) == SAI_I2S_STANDARD)     ||\
                                               ((PROTOCOL) == SAI_I2S_MSBJUSTIFIED) ||\
                                               ((PROTOCOL) == SAI_I2S_LSBJUSTIFIED) ||\
                                               ((PROTOCOL) == SAI_PCM_LONG)         ||\
                                               ((PROTOCOL) == SAI_PCM_SHORT))

#define IS_SAI_PROTOCOL_DATASIZE(DATASIZE)   (((DATASIZE) == SAI_PROTOCOL_DATASIZE_16BIT)         ||\
                                              ((DATASIZE) == SAI_PROTOCOL_DATASIZE_16BITEXTENDED) ||\
                                              ((DATASIZE) == SAI_PROTOCOL_DATASIZE_24BIT)         ||\
                                              ((DATASIZE) == SAI_PROTOCOL_DATASIZE_32BIT))

#define IS_SAI_AUDIO_FREQUENCY(AUDIO) (((AUDIO) == SAI_AUDIO_FREQUENCY_192K) || ((AUDIO) == SAI_AUDIO_FREQUENCY_96K) || \
                                       ((AUDIO) == SAI_AUDIO_FREQUENCY_48K)  || ((AUDIO) == SAI_AUDIO_FREQUENCY_44K) || \
                                       ((AUDIO) == SAI_AUDIO_FREQUENCY_32K)  || ((AUDIO) == SAI_AUDIO_FREQUENCY_22K) || \
                                       ((AUDIO) == SAI_AUDIO_FREQUENCY_16K)  || ((AUDIO) == SAI_AUDIO_FREQUENCY_11K) || \
                                       ((AUDIO) == SAI_AUDIO_FREQUENCY_8K)   || ((AUDIO) == SAI_AUDIO_FREQUENCY_MCKDIV))

#if defined(STM32L4R5xx) || defined(STM32L4R7xx) || defined(STM32L4R9xx) || defined(STM32L4S5xx) || defined(STM32L4S7xx) || defined(STM32L4S9xx) || \
    defined(STM32L4P5xx) || defined(STM32L4Q5xx)
#define IS_SAI_BLOCK_MCK_OVERSAMPLING(VALUE) (((VALUE) == SAI_MCK_OVERSAMPLING_DISABLE) || \
                                              ((VALUE) == SAI_MCK_OVERSAMPLING_ENABLE))

#define IS_SAI_PDM_MIC_PAIRS_NUMBER(VALUE)   ((1U <= (VALUE)) && ((VALUE) <= 3U))

#define IS_SAI_PDM_CLOCK_ENABLE(CLOCK) (((CLOCK) != 0U) && \
                                       (((CLOCK) & ~(SAI_PDM_CLOCK1_ENABLE | SAI_PDM_CLOCK2_ENABLE)) == 0U))
#endif                                                                                                
                                

#define IS_SAI_BLOCK_MODE(MODE)  (((MODE) == SAI_MODEMASTER_TX) || \
                                  ((MODE) == SAI_MODEMASTER_RX) || \
                                  ((MODE) == SAI_MODESLAVE_TX)  || \
                                  ((MODE) == SAI_MODESLAVE_RX))

#define IS_SAI_BLOCK_PROTOCOL(PROTOCOL) (((PROTOCOL) == SAI_FREE_PROTOCOL)  || \
                                         ((PROTOCOL) == SAI_AC97_PROTOCOL)  || \
                                         ((PROTOCOL) == SAI_SPDIF_PROTOCOL))

#define IS_SAI_BLOCK_DATASIZE(DATASIZE) (((DATASIZE) == SAI_DATASIZE_8)  || \
                                         ((DATASIZE) == SAI_DATASIZE_10) || \
                                         ((DATASIZE) == SAI_DATASIZE_16) || \
                                         ((DATASIZE) == SAI_DATASIZE_20) || \
                                         ((DATASIZE) == SAI_DATASIZE_24) || \
                                         ((DATASIZE) == SAI_DATASIZE_32))

#define IS_SAI_BLOCK_FIRST_BIT(BIT) (((BIT) == SAI_FIRSTBIT_MSB) || \
                                     ((BIT) == SAI_FIRSTBIT_LSB))

#define IS_SAI_BLOCK_CLOCK_STROBING(CLOCK) (((CLOCK) == SAI_CLOCKSTROBING_FALLINGEDGE) || \
                                            ((CLOCK) == SAI_CLOCKSTROBING_RISINGEDGE))

#define IS_SAI_BLOCK_SYNCHRO(SYNCHRO) (((SYNCHRO) == SAI_ASYNCHRONOUS)         || \
                                       ((SYNCHRO) == SAI_SYNCHRONOUS)          || \
                                       ((SYNCHRO) == SAI_SYNCHRONOUS_EXT_SAI1) || \
                                       ((SYNCHRO) == SAI_SYNCHRONOUS_EXT_SAI2))

#define IS_SAI_BLOCK_OUTPUT_DRIVE(DRIVE) (((DRIVE) == SAI_OUTPUTDRIVE_DISABLE) || \
                                          ((DRIVE) == SAI_OUTPUTDRIVE_ENABLE))

#define IS_SAI_BLOCK_NODIVIDER(NODIVIDER) (((NODIVIDER) == SAI_MASTERDIVIDER_ENABLE) || \
                                           ((NODIVIDER) == SAI_MASTERDIVIDER_DISABLE))

#define IS_SAI_BLOCK_MUTE_COUNTER(COUNTER) ((COUNTER) <= 63U)

#define IS_SAI_BLOCK_MUTE_VALUE(VALUE)    (((VALUE) == SAI_ZERO_VALUE)     || \
                                           ((VALUE) == SAI_LAST_SENT_VALUE))

#define IS_SAI_BLOCK_COMPANDING_MODE(MODE)    (((MODE) == SAI_NOCOMPANDING)         || \
                                               ((MODE) == SAI_ULAW_1CPL_COMPANDING) || \
                                               ((MODE) == SAI_ALAW_1CPL_COMPANDING) || \
                                               ((MODE) == SAI_ULAW_2CPL_COMPANDING) || \
                                               ((MODE) == SAI_ALAW_2CPL_COMPANDING))

#define IS_SAI_BLOCK_FIFO_THRESHOLD(THRESHOLD) (((THRESHOLD) == SAI_FIFOTHRESHOLD_EMPTY)   || \
                                                ((THRESHOLD) == SAI_FIFOTHRESHOLD_1QF)     || \
                                                ((THRESHOLD) == SAI_FIFOTHRESHOLD_HF)      || \
                                                ((THRESHOLD) == SAI_FIFOTHRESHOLD_3QF)     || \
                                                ((THRESHOLD) == SAI_FIFOTHRESHOLD_FULL))

#define IS_SAI_BLOCK_TRISTATE_MANAGEMENT(STATE) (((STATE) == SAI_OUTPUT_NOTRELEASED) ||\
                                                 ((STATE) == SAI_OUTPUT_RELEASED))

#define IS_SAI_MONO_STEREO_MODE(MODE) (((MODE) == SAI_MONOMODE) ||\
                                       ((MODE) == SAI_STEREOMODE))

#define IS_SAI_SLOT_ACTIVE(ACTIVE)  ((ACTIVE) <= SAI_SLOTACTIVE_ALL)

#define IS_SAI_BLOCK_SLOT_NUMBER(NUMBER) ((1U <= (NUMBER)) && ((NUMBER) <= 16U))

#define IS_SAI_BLOCK_SLOT_SIZE(SIZE) (((SIZE) == SAI_SLOTSIZE_DATASIZE) || \
                                      ((SIZE) == SAI_SLOTSIZE_16B)      || \
                                      ((SIZE) == SAI_SLOTSIZE_32B))

#define IS_SAI_BLOCK_FIRSTBIT_OFFSET(OFFSET) ((OFFSET) <= 24U)

#define IS_SAI_BLOCK_FS_OFFSET(OFFSET) (((OFFSET) == SAI_FS_FIRSTBIT) || \
                                        ((OFFSET) == SAI_FS_BEFOREFIRSTBIT))

#define IS_SAI_BLOCK_FS_POLARITY(POLARITY) (((POLARITY) == SAI_FS_ACTIVE_LOW) || \
                                            ((POLARITY) == SAI_FS_ACTIVE_HIGH))

#define IS_SAI_BLOCK_FS_DEFINITION(DEFINITION) (((DEFINITION) == SAI_FS_STARTFRAME) || \
                                                ((DEFINITION) == SAI_FS_CHANNEL_IDENTIFICATION))

#if defined(STM32L4R5xx) || defined(STM32L4R7xx) || defined(STM32L4R9xx) || defined(STM32L4S5xx) || defined(STM32L4S7xx) || defined(STM32L4S9xx) || \
    defined(STM32L4P5xx) || defined(STM32L4Q5xx)
#define IS_SAI_BLOCK_MASTER_DIVIDER(DIVIDER) ((DIVIDER) <= 63U)
#else
#define IS_SAI_BLOCK_MASTER_DIVIDER(DIVIDER) ((DIVIDER) <= 15U)
#endif                                                                                                
                                

#define IS_SAI_BLOCK_FRAME_LENGTH(LENGTH) ((8U <= (LENGTH)) && ((LENGTH) <= 256U))

#define IS_SAI_BLOCK_ACTIVE_FRAME(LENGTH) ((1U <= (LENGTH)) && ((LENGTH) <= 128U))

   
      
    

                                                                                
                                                         
      
    

   
      
    

   
      
    

   
      
    

#endif                                   

#ifdef __cplusplus
}
#endif

#endif                          

