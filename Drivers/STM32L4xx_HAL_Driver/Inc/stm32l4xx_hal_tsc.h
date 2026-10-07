/**
  ******************************************************************************
  * @file    stm32l4xx_hal_tsc.h
  * @author  MCD Application Team
  * @brief   Header file of TSC HAL module.
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

                                                                                
#ifndef STM32L4xx_HAL_TSC_H
#define STM32L4xx_HAL_TSC_H

#ifdef __cplusplus
extern "C" {
#endif

                                                                                
#include "stm32l4xx_hal_def.h"


                                    
      
    

                   
      
    

                                                                                
                                                   
      
    

   
                                         
    
typedef enum
{
  HAL_TSC_STATE_RESET  = 0x00UL,                                             
  HAL_TSC_STATE_READY  = 0x01UL,                                                                               
  HAL_TSC_STATE_BUSY   = 0x02UL,                                                      
  HAL_TSC_STATE_ERROR  = 0x03UL                                                       
} HAL_TSC_StateTypeDef;

   
                                                
    
typedef enum
{
  TSC_GROUP_ONGOING   = 0x00UL,                                                        
  TSC_GROUP_COMPLETED = 0x01UL                                                                            
} TSC_GroupStatusTypeDef;

   
                                        
    
typedef struct
{
  uint32_t CTPulseHighLength;                                             
                                                                                                       
  uint32_t CTPulseLowLength;                                             
                                                                                                       
  FunctionalState SpreadSpectrum;                                  
                                                                                           
  uint32_t SpreadSpectrumDeviation;                               
                                                                                                                   
  uint32_t SpreadSpectrumPrescaler;                               
                                                                                                          
  uint32_t PulseGeneratorPrescaler;                               
                                                                                                              
  uint32_t MaxCountValue;                               
                                                                                                     
  uint32_t IODefaultMode;                               
                                                                                                      
  uint32_t SynchroPinPolarity;                               
                                                                                                          
  uint32_t AcquisitionMode;                              
                                                                                                       
  FunctionalState MaxCountInterrupt;                                   
                                                                                           
  uint32_t ChannelIOs;                                      
  uint32_t ShieldIOs;                                      
  uint32_t SamplingIOs;                                      
} TSC_InitTypeDef;

   
                                                     
    
typedef struct
{
  uint32_t ChannelIOs;                          
  uint32_t ShieldIOs;                          
  uint32_t SamplingIOs;                          
} TSC_IOConfigTypeDef;

   
                                           
    
#if (USE_HAL_TSC_REGISTER_CALLBACKS == 1)
typedef struct __TSC_HandleTypeDef
#else
typedef struct
#endif                                      
{
  TSC_TypeDef               *Instance;                                    
  TSC_InitTypeDef           Init;                                         
  __IO HAL_TSC_StateTypeDef State;                                        
  HAL_LockTypeDef           Lock;                                         
  __IO uint32_t             ErrorCode;                                    

#if (USE_HAL_TSC_REGISTER_CALLBACKS == 1)
  void (* ConvCpltCallback)(struct __TSC_HandleTypeDef *htsc);                                            
  void (* ErrorCallback)(struct __TSC_HandleTypeDef *htsc);                                               

  void (* MspInitCallback)(struct __TSC_HandleTypeDef *htsc);                                             
  void (* MspDeInitCallback)(struct __TSC_HandleTypeDef *htsc);                                           

#endif                                      
} TSC_HandleTypeDef;

enum
{
  TSC_GROUP1_IDX = 0x00UL,
  TSC_GROUP2_IDX,
  TSC_GROUP3_IDX,
  TSC_GROUP4_IDX,
#if defined(TSC_IOCCR_G5_IO1)
  TSC_GROUP5_IDX,
#endif                       
#if defined(TSC_IOCCR_G6_IO1)
  TSC_GROUP6_IDX,
#endif                       
#if defined(TSC_IOCCR_G7_IO1)
  TSC_GROUP7_IDX,
#endif                       
#if defined(TSC_IOCCR_G8_IO1)
  TSC_GROUP8_IDX,
#endif                       
  TSC_NB_OF_GROUPS
};

#if (USE_HAL_TSC_REGISTER_CALLBACKS == 1)
   
                                                      
    
typedef enum
{
  HAL_TSC_CONV_COMPLETE_CB_ID           = 0x00UL,                                               
  HAL_TSC_ERROR_CB_ID                   = 0x01UL,                                               

  HAL_TSC_MSPINIT_CB_ID                 = 0x02UL,                                               
  HAL_TSC_MSPDEINIT_CB_ID               = 0x03UL                                                

} HAL_TSC_CallbackIDTypeDef;

   
                                               
    
typedef  void (*pTSC_CallbackTypeDef)(TSC_HandleTypeDef *htsc);                                            

#endif                                      

   
      
    

                                                                                
                                                           
      
    

                                                                 
                                     
      
    
#define HAL_TSC_ERROR_NONE      0x00000000UL                                 
#if (USE_HAL_TSC_REGISTER_CALLBACKS == 1)
#define HAL_TSC_ERROR_INVALID_CALLBACK  0x00000001UL                                  
#endif                                     
   
      
    

                                                      
      
    
#define TSC_CTPH_1CYCLE         0x00000000UL
                                                           
#define TSC_CTPH_2CYCLES        TSC_CR_CTPH_0
                                                           
#define TSC_CTPH_3CYCLES        TSC_CR_CTPH_1
                                                           
#define TSC_CTPH_4CYCLES        (TSC_CR_CTPH_1 | TSC_CR_CTPH_0)
                                                           
#define TSC_CTPH_5CYCLES        TSC_CR_CTPH_2
                                                           
#define TSC_CTPH_6CYCLES        (TSC_CR_CTPH_2 | TSC_CR_CTPH_0)
                                                           
#define TSC_CTPH_7CYCLES        (TSC_CR_CTPH_2 | TSC_CR_CTPH_1)
                                                           
#define TSC_CTPH_8CYCLES        (TSC_CR_CTPH_2 | TSC_CR_CTPH_1 | TSC_CR_CTPH_0)
                                                           
#define TSC_CTPH_9CYCLES        TSC_CR_CTPH_3
                                                           
#define TSC_CTPH_10CYCLES       (TSC_CR_CTPH_3 | TSC_CR_CTPH_0)
                                                           
#define TSC_CTPH_11CYCLES       (TSC_CR_CTPH_3 | TSC_CR_CTPH_1)
                                                           
#define TSC_CTPH_12CYCLES       (TSC_CR_CTPH_3 | TSC_CR_CTPH_1 | TSC_CR_CTPH_0)
                                                           
#define TSC_CTPH_13CYCLES       (TSC_CR_CTPH_3 | TSC_CR_CTPH_2)
                                                           
#define TSC_CTPH_14CYCLES       (TSC_CR_CTPH_3 | TSC_CR_CTPH_2 | TSC_CR_CTPH_0)
                                                           
#define TSC_CTPH_15CYCLES       (TSC_CR_CTPH_3 | TSC_CR_CTPH_2 | TSC_CR_CTPH_1)
                                                           
#define TSC_CTPH_16CYCLES       (TSC_CR_CTPH_3 | TSC_CR_CTPH_2 | TSC_CR_CTPH_1 | TSC_CR_CTPH_0)
                                                           
   
      
    

                                                     
      
    
#define TSC_CTPL_1CYCLE         0x00000000UL
                                                          
#define TSC_CTPL_2CYCLES        TSC_CR_CTPL_0
                                                          
#define TSC_CTPL_3CYCLES        TSC_CR_CTPL_1
                                                          
#define TSC_CTPL_4CYCLES        (TSC_CR_CTPL_1 | TSC_CR_CTPL_0)
                                                          
#define TSC_CTPL_5CYCLES        TSC_CR_CTPL_2
                                                          
#define TSC_CTPL_6CYCLES        (TSC_CR_CTPL_2 | TSC_CR_CTPL_0)
                                                          
#define TSC_CTPL_7CYCLES        (TSC_CR_CTPL_2 | TSC_CR_CTPL_1)
                                                          
#define TSC_CTPL_8CYCLES        (TSC_CR_CTPL_2 | TSC_CR_CTPL_1 | TSC_CR_CTPL_0)
                                                          
#define TSC_CTPL_9CYCLES        TSC_CR_CTPL_3
                                                          
#define TSC_CTPL_10CYCLES       (TSC_CR_CTPL_3 | TSC_CR_CTPL_0)
                                                          
#define TSC_CTPL_11CYCLES       (TSC_CR_CTPL_3 | TSC_CR_CTPL_1)
                                                          
#define TSC_CTPL_12CYCLES       (TSC_CR_CTPL_3 | TSC_CR_CTPL_1 | TSC_CR_CTPL_0)
                                                          
#define TSC_CTPL_13CYCLES       (TSC_CR_CTPL_3 | TSC_CR_CTPL_2)
                                                          
#define TSC_CTPL_14CYCLES       (TSC_CR_CTPL_3 | TSC_CR_CTPL_2 | TSC_CR_CTPL_0)
                                                          
#define TSC_CTPL_15CYCLES       (TSC_CR_CTPL_3 | TSC_CR_CTPL_2 | TSC_CR_CTPL_1)
                                                          
#define TSC_CTPL_16CYCLES       (TSC_CR_CTPL_3 | TSC_CR_CTPL_2 | TSC_CR_CTPL_1 | TSC_CR_CTPL_0)
                                                          
   
      
    

                                                                
      
    
#define TSC_SS_PRESC_DIV1       0x00000000UL                                        
#define TSC_SS_PRESC_DIV2       TSC_CR_SSPSC                                        
   
      
    

                                                                    
      
    
#define TSC_PG_PRESC_DIV1       0x00000000UL                                                                           
#define TSC_PG_PRESC_DIV2       TSC_CR_PGPSC_0                                                                         
#define TSC_PG_PRESC_DIV4       TSC_CR_PGPSC_1                                                                         
#define TSC_PG_PRESC_DIV8       (TSC_CR_PGPSC_1 | TSC_CR_PGPSC_0)                                                      
#define TSC_PG_PRESC_DIV16      TSC_CR_PGPSC_2                                                                         
#define TSC_PG_PRESC_DIV32      (TSC_CR_PGPSC_2 | TSC_CR_PGPSC_0)                                                      
#define TSC_PG_PRESC_DIV64      (TSC_CR_PGPSC_2 | TSC_CR_PGPSC_1)                                                      
#define TSC_PG_PRESC_DIV128     (TSC_CR_PGPSC_2 | TSC_CR_PGPSC_1 | TSC_CR_PGPSC_0)                                     
   
      
    

                                                
      
    
#define TSC_MCV_255             0x00000000UL                                                                         
#define TSC_MCV_511             TSC_CR_MCV_0                                                                         
#define TSC_MCV_1023            TSC_CR_MCV_1                                                                         
#define TSC_MCV_2047            (TSC_CR_MCV_1 | TSC_CR_MCV_0)                                                        
#define TSC_MCV_4095            TSC_CR_MCV_2                                                                         
#define TSC_MCV_8191            (TSC_CR_MCV_2 | TSC_CR_MCV_0)                                                        
#define TSC_MCV_16383           (TSC_CR_MCV_2 | TSC_CR_MCV_1)                                                        
   
      
    

                                                 
      
    
#define TSC_IODEF_OUT_PP_LOW    0x00000000UL                                                
#define TSC_IODEF_IN_FLOAT      TSC_CR_IODEF                                                
   
      
    

                                                           
      
    
#define TSC_SYNC_POLARITY_FALLING  0x00000000UL                                      
#define TSC_SYNC_POLARITY_RISING   TSC_CR_SYNCPOL                                    
   
      
    

                                                   
      
    
#define TSC_ACQ_MODE_NORMAL     0x00000000UL
                                                                                
#define TSC_ACQ_MODE_SYNCHRO    TSC_CR_AM
                                                                              
                                                              
   
      
    

                                                             
      
    
#define TSC_IT_EOA              TSC_IER_EOAIE                                            
#define TSC_IT_MCE              TSC_IER_MCEIE                                            
   
      
    

                                                   
      
    
#define TSC_FLAG_EOA            TSC_ISR_EOAF                                
#define TSC_FLAG_MCE            TSC_ISR_MCEF                                
   
      
    

                                                   
      
    
#define TSC_GROUP1              (0x1UL << TSC_GROUP1_IDX)
#define TSC_GROUP2              (0x1UL << TSC_GROUP2_IDX)
#define TSC_GROUP3              (0x1UL << TSC_GROUP3_IDX)
#define TSC_GROUP4              (0x1UL << TSC_GROUP4_IDX)
#if defined(TSC_IOCCR_G5_IO1)
#define TSC_GROUP5              (0x1UL << TSC_GROUP5_IDX)
#endif                       
#if defined(TSC_IOCCR_G6_IO1)
#define TSC_GROUP6              (0x1UL << TSC_GROUP6_IDX)
#endif                       
#if defined(TSC_IOCCR_G7_IO1)
#define TSC_GROUP7              (0x1UL << TSC_GROUP7_IDX)
#endif                       
#if defined(TSC_IOCCR_G8_IO1)
#define TSC_GROUP8              (0x1UL << TSC_GROUP8_IDX)
#endif                       

#define TSC_GROUPX_NOT_SUPPORTED        0xFF000000UL                                          

#define TSC_GROUP1_IO1          TSC_IOCCR_G1_IO1                       
#define TSC_GROUP1_IO2          TSC_IOCCR_G1_IO2                       
#define TSC_GROUP1_IO3          TSC_IOCCR_G1_IO3                       
#define TSC_GROUP1_IO4          TSC_IOCCR_G1_IO4                       

#define TSC_GROUP2_IO1          TSC_IOCCR_G2_IO1                       
#define TSC_GROUP2_IO2          TSC_IOCCR_G2_IO2                       
#define TSC_GROUP2_IO3          TSC_IOCCR_G2_IO3                       
#define TSC_GROUP2_IO4          TSC_IOCCR_G2_IO4                       

#define TSC_GROUP3_IO1          TSC_IOCCR_G3_IO1                       
#define TSC_GROUP3_IO2          TSC_IOCCR_G3_IO2                       
#define TSC_GROUP3_IO3          TSC_IOCCR_G3_IO3                       
#define TSC_GROUP3_IO4          TSC_IOCCR_G3_IO4                       

#define TSC_GROUP4_IO1          TSC_IOCCR_G4_IO1                       
#define TSC_GROUP4_IO2          TSC_IOCCR_G4_IO2                       
#define TSC_GROUP4_IO3          TSC_IOCCR_G4_IO3                       
#define TSC_GROUP4_IO4          TSC_IOCCR_G4_IO4                       
#if defined(TSC_IOCCR_G5_IO1)

#define TSC_GROUP5_IO1          TSC_IOCCR_G5_IO1                       
#define TSC_GROUP5_IO2          TSC_IOCCR_G5_IO2                       
#define TSC_GROUP5_IO3          TSC_IOCCR_G5_IO3                       
#define TSC_GROUP5_IO4          TSC_IOCCR_G5_IO4                       
#else

#define TSC_GROUP5_IO1          (uint32_t)(0x00000010UL | TSC_GROUPX_NOT_SUPPORTED)                                           
#define TSC_GROUP5_IO2          TSC_GROUP5_IO1                                                                                
#define TSC_GROUP5_IO3          TSC_GROUP5_IO1                                                                                
#define TSC_GROUP5_IO4          TSC_GROUP5_IO1                                                                                
#endif                       
#if defined(TSC_IOCCR_G6_IO1)

#define TSC_GROUP6_IO1          TSC_IOCCR_G6_IO1                       
#define TSC_GROUP6_IO2          TSC_IOCCR_G6_IO2                       
#define TSC_GROUP6_IO3          TSC_IOCCR_G6_IO3                       
#define TSC_GROUP6_IO4          TSC_IOCCR_G6_IO4                       
#else

#define TSC_GROUP6_IO1          (uint32_t)(0x00000020UL | TSC_GROUPX_NOT_SUPPORTED)                                           
#define TSC_GROUP6_IO2          TSC_GROUP6_IO1                                                                                
#define TSC_GROUP6_IO3          TSC_GROUP6_IO1                                                                                
#define TSC_GROUP6_IO4          TSC_GROUP6_IO1                                                                                
#endif                       
#if defined(TSC_IOCCR_G7_IO1)

#define TSC_GROUP7_IO1          TSC_IOCCR_G7_IO1                       
#define TSC_GROUP7_IO2          TSC_IOCCR_G7_IO2                       
#define TSC_GROUP7_IO3          TSC_IOCCR_G7_IO3                       
#define TSC_GROUP7_IO4          TSC_IOCCR_G7_IO4                       
#else

#define TSC_GROUP7_IO1          (uint32_t)(0x00000040UL | TSC_GROUPX_NOT_SUPPORTED)                                           
#define TSC_GROUP7_IO2          TSC_GROUP7_IO1                                                                                
#define TSC_GROUP7_IO3          TSC_GROUP7_IO1                                                                                
#define TSC_GROUP7_IO4          TSC_GROUP7_IO1                                                                                
#endif                       
#if defined(TSC_IOCCR_G8_IO1)

#define TSC_GROUP8_IO1          TSC_IOCCR_G8_IO1                       
#define TSC_GROUP8_IO2          TSC_IOCCR_G8_IO2                       
#define TSC_GROUP8_IO3          TSC_IOCCR_G8_IO3                       
#define TSC_GROUP8_IO4          TSC_IOCCR_G8_IO4                       
#else

#define TSC_GROUP8_IO1          (uint32_t)(0x00000080UL | TSC_GROUPX_NOT_SUPPORTED)                                           
#define TSC_GROUP8_IO2          TSC_GROUP8_IO1                                                                                
#define TSC_GROUP8_IO3          TSC_GROUP8_IO1                                                                                
#define TSC_GROUP8_IO4          TSC_GROUP8_IO1                                                                                
#endif                       
   
      
    

   
      
    

                                                                                

                                                     
      
    

                                  
                                 
                
    
#if (USE_HAL_TSC_REGISTER_CALLBACKS == 1)
#define __HAL_TSC_RESET_HANDLE_STATE(__HANDLE__)                   do{                                             \
                                                                       (__HANDLE__)->State = HAL_TSC_STATE_RESET;  \
                                                                       (__HANDLE__)->MspInitCallback = NULL;       \
                                                                       (__HANDLE__)->MspDeInitCallback = NULL;     \
                                                                     } while(0)
#else
#define __HAL_TSC_RESET_HANDLE_STATE(__HANDLE__)                   ((__HANDLE__)->State = HAL_TSC_STATE_RESET)
#endif                                            

   
                                     
                                 
                
    
#define __HAL_TSC_ENABLE(__HANDLE__)                               ((__HANDLE__)->Instance->CR |= TSC_CR_TSCE)

   
                                      
                                 
                
    
#define __HAL_TSC_DISABLE(__HANDLE__)                              ((__HANDLE__)->Instance->CR &= (~TSC_CR_TSCE))

   
                             
                                 
                
    
#define __HAL_TSC_START_ACQ(__HANDLE__)                            ((__HANDLE__)->Instance->CR |= TSC_CR_START)

   
                            
                                 
                
    
#define __HAL_TSC_STOP_ACQ(__HANDLE__)                             ((__HANDLE__)->Instance->CR &= (~TSC_CR_START))

   
                                                       
                                 
                
    
#define __HAL_TSC_SET_IODEF_OUTPPLOW(__HANDLE__)                   ((__HANDLE__)->Instance->CR &= (~TSC_CR_IODEF))

   
                                                 
                                 
                
    
#define __HAL_TSC_SET_IODEF_INFLOAT(__HANDLE__)                    ((__HANDLE__)->Instance->CR |= TSC_CR_IODEF)

   
                                                        
                                 
                
    
#define __HAL_TSC_SET_SYNC_POL_FALL(__HANDLE__)                    ((__HANDLE__)->Instance->CR &= (~TSC_CR_SYNCPOL))

   
                                                                      
                                 
                
    
#define __HAL_TSC_SET_SYNC_POL_RISE_HIGH(__HANDLE__)               ((__HANDLE__)->Instance->CR |= TSC_CR_SYNCPOL)

   
                                
                                 
                                       
                
    
#define __HAL_TSC_ENABLE_IT(__HANDLE__, __INTERRUPT__)             ((__HANDLE__)->Instance->IER |= (__INTERRUPT__))

   
                                 
                                 
                                       
                
    
#define __HAL_TSC_DISABLE_IT(__HANDLE__, __INTERRUPT__)            ((__HANDLE__)->Instance->IER &= (~(__INTERRUPT__)))

                                                                              
                                 
                                       
                        
    
#define __HAL_TSC_GET_IT_SOURCE(__HANDLE__, __INTERRUPT__)         ((((__HANDLE__)->Instance->IER\
                                                                      & (__INTERRUPT__)) == (__INTERRUPT__)) ? SET :\
                                                                    RESET)

   
                                                              
                                 
                             
                        
    
#define __HAL_TSC_GET_FLAG(__HANDLE__, __FLAG__)                   ((((__HANDLE__)->Instance->ISR\
                                                                      & (__FLAG__)) == (__FLAG__)) ? SET : RESET)

   
                                        
                                 
                             
                
    
#define __HAL_TSC_CLEAR_FLAG(__HANDLE__, __FLAG__)                 ((__HANDLE__)->Instance->ICR = (__FLAG__))

   
                                                               
                                 
                                    
                
    
#define __HAL_TSC_ENABLE_HYSTERESIS(__HANDLE__, __GX_IOY_MASK__)   ((__HANDLE__)->Instance->IOHCR |= (__GX_IOY_MASK__))

   
                                                                
                                 
                                    
                
    
#define __HAL_TSC_DISABLE_HYSTERESIS(__HANDLE__, __GX_IOY_MASK__)  ((__HANDLE__)->Instance->IOHCR\
                                                                    &= (~(__GX_IOY_MASK__)))

   
                                                
                                 
                                    
                
    
#define __HAL_TSC_OPEN_ANALOG_SWITCH(__HANDLE__, __GX_IOY_MASK__)  ((__HANDLE__)->Instance->IOASCR\
                                                                    &= (~(__GX_IOY_MASK__)))

   
                                                 
                                 
                                    
                
    
#define __HAL_TSC_CLOSE_ANALOG_SWITCH(__HANDLE__, __GX_IOY_MASK__) ((__HANDLE__)->Instance->IOASCR |= (__GX_IOY_MASK__))

   
                                                 
                                 
                                    
                
    
#define __HAL_TSC_ENABLE_CHANNEL(__HANDLE__, __GX_IOY_MASK__)      ((__HANDLE__)->Instance->IOCCR |= (__GX_IOY_MASK__))

   
                                          
                                 
                                    
                
    
#define __HAL_TSC_DISABLE_CHANNEL(__HANDLE__, __GX_IOY_MASK__)     ((__HANDLE__)->Instance->IOCCR\
                                                                    &= (~(__GX_IOY_MASK__)))

   
                                                  
                                 
                                    
                
    
#define __HAL_TSC_ENABLE_SAMPLING(__HANDLE__, __GX_IOY_MASK__)     ((__HANDLE__)->Instance->IOSCR |= (__GX_IOY_MASK__))

   
                                           
                                 
                                    
                
    
#define __HAL_TSC_DISABLE_SAMPLING(__HANDLE__, __GX_IOY_MASK__) ((__HANDLE__)->Instance->IOSCR &= (~(__GX_IOY_MASK__)))

   
                                     
                                 
                                   
                
    
#define __HAL_TSC_ENABLE_GROUP(__HANDLE__, __GX_MASK__) ((__HANDLE__)->Instance->IOGCSR |= (__GX_MASK__))

   
                                      
                                 
                                   
                
    
#define __HAL_TSC_DISABLE_GROUP(__HANDLE__, __GX_MASK__) ((__HANDLE__)->Instance->IOGCSR &= (~(__GX_MASK__)))

                                         
                                 
                                    
                        
    
#define __HAL_TSC_GET_GROUP_STATUS(__HANDLE__, __GX_INDEX__) \
  ((((__HANDLE__)->Instance->IOGCSR & (uint32_t)(1UL << (((__GX_INDEX__) & 0xFUL) + 16UL))) == \
    (uint32_t)(1UL << (((__GX_INDEX__) & 0xFUL) + 16UL))) ? TSC_GROUP_COMPLETED : TSC_GROUP_ONGOING)

   
      
    

                                                                                

                                                   
      
    

#define IS_TSC_CTPH(__VALUE__)          (((__VALUE__) == TSC_CTPH_1CYCLE)   || \
                                         ((__VALUE__) == TSC_CTPH_2CYCLES)  || \
                                         ((__VALUE__) == TSC_CTPH_3CYCLES)  || \
                                         ((__VALUE__) == TSC_CTPH_4CYCLES)  || \
                                         ((__VALUE__) == TSC_CTPH_5CYCLES)  || \
                                         ((__VALUE__) == TSC_CTPH_6CYCLES)  || \
                                         ((__VALUE__) == TSC_CTPH_7CYCLES)  || \
                                         ((__VALUE__) == TSC_CTPH_8CYCLES)  || \
                                         ((__VALUE__) == TSC_CTPH_9CYCLES)  || \
                                         ((__VALUE__) == TSC_CTPH_10CYCLES) || \
                                         ((__VALUE__) == TSC_CTPH_11CYCLES) || \
                                         ((__VALUE__) == TSC_CTPH_12CYCLES) || \
                                         ((__VALUE__) == TSC_CTPH_13CYCLES) || \
                                         ((__VALUE__) == TSC_CTPH_14CYCLES) || \
                                         ((__VALUE__) == TSC_CTPH_15CYCLES) || \
                                         ((__VALUE__) == TSC_CTPH_16CYCLES))

#define IS_TSC_CTPL(__VALUE__)          (((__VALUE__) == TSC_CTPL_1CYCLE)   || \
                                         ((__VALUE__) == TSC_CTPL_2CYCLES)  || \
                                         ((__VALUE__) == TSC_CTPL_3CYCLES)  || \
                                         ((__VALUE__) == TSC_CTPL_4CYCLES)  || \
                                         ((__VALUE__) == TSC_CTPL_5CYCLES)  || \
                                         ((__VALUE__) == TSC_CTPL_6CYCLES)  || \
                                         ((__VALUE__) == TSC_CTPL_7CYCLES)  || \
                                         ((__VALUE__) == TSC_CTPL_8CYCLES)  || \
                                         ((__VALUE__) == TSC_CTPL_9CYCLES)  || \
                                         ((__VALUE__) == TSC_CTPL_10CYCLES) || \
                                         ((__VALUE__) == TSC_CTPL_11CYCLES) || \
                                         ((__VALUE__) == TSC_CTPL_12CYCLES) || \
                                         ((__VALUE__) == TSC_CTPL_13CYCLES) || \
                                         ((__VALUE__) == TSC_CTPL_14CYCLES) || \
                                         ((__VALUE__) == TSC_CTPL_15CYCLES) || \
                                         ((__VALUE__) == TSC_CTPL_16CYCLES))

#define IS_TSC_SS(__VALUE__)            (((FunctionalState)(__VALUE__) == DISABLE)\
                                         || ((FunctionalState)(__VALUE__) == ENABLE))

#define IS_TSC_SSD(__VALUE__)           (((__VALUE__) == 0UL) || (((__VALUE__) > 0UL) && ((__VALUE__) < 128UL)))

#define IS_TSC_SS_PRESC(__VALUE__)      (((__VALUE__) == TSC_SS_PRESC_DIV1) || ((__VALUE__) == TSC_SS_PRESC_DIV2))

#define IS_TSC_PG_PRESC(__VALUE__)      (((__VALUE__) == TSC_PG_PRESC_DIV1)  || \
                                         ((__VALUE__) == TSC_PG_PRESC_DIV2)  || \
                                         ((__VALUE__) == TSC_PG_PRESC_DIV4)  || \
                                         ((__VALUE__) == TSC_PG_PRESC_DIV8)  || \
                                         ((__VALUE__) == TSC_PG_PRESC_DIV16) || \
                                         ((__VALUE__) == TSC_PG_PRESC_DIV32) || \
                                         ((__VALUE__) == TSC_PG_PRESC_DIV64) || \
                                         ((__VALUE__) == TSC_PG_PRESC_DIV128))

#define IS_TSC_PG_PRESC_VS_CTPL(__PGPSC__, __CTPL__)    ((((__PGPSC__) == TSC_PG_PRESC_DIV1) && \
                                                          (((__CTPL__) == TSC_CTPL_1CYCLE) ||   \
                                                           ((__CTPL__) > TSC_CTPL_2CYCLES))) ||   \
                                                         (((__PGPSC__) == TSC_PG_PRESC_DIV2) && \
                                                          ((__CTPL__) > TSC_CTPL_1CYCLE))  ||   \
                                                         (((__PGPSC__) > TSC_PG_PRESC_DIV2)  && \
                                                          (((__CTPL__) == TSC_CTPL_1CYCLE) ||   \
                                                           ((__CTPL__) > TSC_CTPL_1CYCLE))))

#define IS_TSC_MCV(__VALUE__)           (((__VALUE__) == TSC_MCV_255)  || \
                                         ((__VALUE__) == TSC_MCV_511)  || \
                                         ((__VALUE__) == TSC_MCV_1023) || \
                                         ((__VALUE__) == TSC_MCV_2047) || \
                                         ((__VALUE__) == TSC_MCV_4095) || \
                                         ((__VALUE__) == TSC_MCV_8191) || \
                                         ((__VALUE__) == TSC_MCV_16383))

#define IS_TSC_IODEF(__VALUE__)         (((__VALUE__) == TSC_IODEF_OUT_PP_LOW) || ((__VALUE__) == TSC_IODEF_IN_FLOAT))

#define IS_TSC_SYNC_POL(__VALUE__)      (((__VALUE__) == TSC_SYNC_POLARITY_FALLING)\
                                         || ((__VALUE__) == TSC_SYNC_POLARITY_RISING))

#define IS_TSC_ACQ_MODE(__VALUE__)      (((__VALUE__) == TSC_ACQ_MODE_NORMAL) || ((__VALUE__) == TSC_ACQ_MODE_SYNCHRO))

#define IS_TSC_MCE_IT(__VALUE__)        (((FunctionalState)(__VALUE__) == DISABLE)\
                                         || ((FunctionalState)(__VALUE__) == ENABLE))

#define IS_TSC_GROUP_INDEX(__VALUE__)   (((__VALUE__) == 0UL)\
                                         || (((__VALUE__) > 0UL) && ((__VALUE__) < (uint32_t)TSC_NB_OF_GROUPS)))


#define IS_TSC_GROUP(__VALUE__)        ((((__VALUE__) & TSC_GROUPX_NOT_SUPPORTED) != TSC_GROUPX_NOT_SUPPORTED) && \
                                        (((__VALUE__) == 0UL)                               ||\
                                         (((__VALUE__) & TSC_GROUP1_IO1) == TSC_GROUP1_IO1) ||\
                                         (((__VALUE__) & TSC_GROUP1_IO2) == TSC_GROUP1_IO2) ||\
                                         (((__VALUE__) & TSC_GROUP1_IO3) == TSC_GROUP1_IO3) ||\
                                         (((__VALUE__) & TSC_GROUP1_IO4) == TSC_GROUP1_IO4) ||\
                                         (((__VALUE__) & TSC_GROUP2_IO1) == TSC_GROUP2_IO1) ||\
                                         (((__VALUE__) & TSC_GROUP2_IO2) == TSC_GROUP2_IO2) ||\
                                         (((__VALUE__) & TSC_GROUP2_IO3) == TSC_GROUP2_IO3) ||\
                                         (((__VALUE__) & TSC_GROUP2_IO4) == TSC_GROUP2_IO4) ||\
                                         (((__VALUE__) & TSC_GROUP3_IO1) == TSC_GROUP3_IO1) ||\
                                         (((__VALUE__) & TSC_GROUP3_IO2) == TSC_GROUP3_IO2) ||\
                                         (((__VALUE__) & TSC_GROUP3_IO3) == TSC_GROUP3_IO3) ||\
                                         (((__VALUE__) & TSC_GROUP3_IO4) == TSC_GROUP3_IO4) ||\
                                         (((__VALUE__) & TSC_GROUP4_IO1) == TSC_GROUP4_IO1) ||\
                                         (((__VALUE__) & TSC_GROUP4_IO2) == TSC_GROUP4_IO2) ||\
                                         (((__VALUE__) & TSC_GROUP4_IO3) == TSC_GROUP4_IO3) ||\
                                         (((__VALUE__) & TSC_GROUP4_IO4) == TSC_GROUP4_IO4) ||\
                                         (((__VALUE__) & TSC_GROUP5_IO1) == TSC_GROUP5_IO1) ||\
                                         (((__VALUE__) & TSC_GROUP5_IO2) == TSC_GROUP5_IO2) ||\
                                         (((__VALUE__) & TSC_GROUP5_IO3) == TSC_GROUP5_IO3) ||\
                                         (((__VALUE__) & TSC_GROUP5_IO4) == TSC_GROUP5_IO4) ||\
                                         (((__VALUE__) & TSC_GROUP6_IO1) == TSC_GROUP6_IO1) ||\
                                         (((__VALUE__) & TSC_GROUP6_IO2) == TSC_GROUP6_IO2) ||\
                                         (((__VALUE__) & TSC_GROUP6_IO3) == TSC_GROUP6_IO3) ||\
                                         (((__VALUE__) & TSC_GROUP6_IO4) == TSC_GROUP6_IO4) ||\
                                         (((__VALUE__) & TSC_GROUP7_IO1) == TSC_GROUP7_IO1) ||\
                                         (((__VALUE__) & TSC_GROUP7_IO2) == TSC_GROUP7_IO2) ||\
                                         (((__VALUE__) & TSC_GROUP7_IO3) == TSC_GROUP7_IO3) ||\
                                         (((__VALUE__) & TSC_GROUP7_IO4) == TSC_GROUP7_IO4) ||\
                                         (((__VALUE__) & TSC_GROUP8_IO1) == TSC_GROUP8_IO1) ||\
                                         (((__VALUE__) & TSC_GROUP8_IO2) == TSC_GROUP8_IO2) ||\
                                         (((__VALUE__) & TSC_GROUP8_IO3) == TSC_GROUP8_IO3) ||\
                                         (((__VALUE__) & TSC_GROUP8_IO4) == TSC_GROUP8_IO4)))

   
      
    

                                                                                
                                      
      
    

                                                                                            
      
    
                                                                                
HAL_StatusTypeDef HAL_TSC_Init(TSC_HandleTypeDef *htsc);
HAL_StatusTypeDef HAL_TSC_DeInit(TSC_HandleTypeDef *htsc);
void HAL_TSC_MspInit(TSC_HandleTypeDef *htsc);
void HAL_TSC_MspDeInit(TSC_HandleTypeDef *htsc);

                                                                                
#if (USE_HAL_TSC_REGISTER_CALLBACKS == 1)
HAL_StatusTypeDef HAL_TSC_RegisterCallback(TSC_HandleTypeDef *htsc, HAL_TSC_CallbackIDTypeDef CallbackID,
                                           pTSC_CallbackTypeDef pCallback);
HAL_StatusTypeDef HAL_TSC_UnRegisterCallback(TSC_HandleTypeDef *htsc, HAL_TSC_CallbackIDTypeDef CallbackID);
#endif                                     
   
      
    

                                                                                  
      
    
                                                                                
HAL_StatusTypeDef HAL_TSC_Start(TSC_HandleTypeDef *htsc);
HAL_StatusTypeDef HAL_TSC_Start_IT(TSC_HandleTypeDef *htsc);
HAL_StatusTypeDef HAL_TSC_Stop(TSC_HandleTypeDef *htsc);
HAL_StatusTypeDef HAL_TSC_Stop_IT(TSC_HandleTypeDef *htsc);
HAL_StatusTypeDef HAL_TSC_PollForAcquisition(TSC_HandleTypeDef *htsc);
TSC_GroupStatusTypeDef HAL_TSC_GroupGetStatus(const TSC_HandleTypeDef *htsc, uint32_t gx_index);
uint32_t HAL_TSC_GroupGetValue(const TSC_HandleTypeDef *htsc, uint32_t gx_index);
   
      
    

                                                                          
      
    
                                                                                
HAL_StatusTypeDef HAL_TSC_IOConfig(TSC_HandleTypeDef *htsc, const TSC_IOConfigTypeDef *config);
HAL_StatusTypeDef HAL_TSC_IODischarge(TSC_HandleTypeDef *htsc, FunctionalState choice);
   
      
    

                                                                                   
      
    
                                                                                
HAL_TSC_StateTypeDef HAL_TSC_GetState(TSC_HandleTypeDef *htsc);
   
      
    

                                                                       
      
    
                                                               
void HAL_TSC_IRQHandler(TSC_HandleTypeDef *htsc);
void HAL_TSC_ConvCpltCallback(TSC_HandleTypeDef *htsc);
void HAL_TSC_ErrorCallback(TSC_HandleTypeDef *htsc);
   
      
    

   
      
    

   
      
    

   
      
    

#ifdef __cplusplus
}
#endif

#endif                          
