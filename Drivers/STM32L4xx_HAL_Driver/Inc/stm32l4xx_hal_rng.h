/**
  ******************************************************************************
  * @file    stm32l4xx_hal_rng.h
  * @author  MCD Application Team
  * @brief   Header file of RNG HAL module.
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

                                                                                
#ifndef STM32L4xx_HAL_RNG_H
#define STM32L4xx_HAL_RNG_H

#ifdef __cplusplus
extern "C" {
#endif

                                                                                
#include "stm32l4xx_hal_def.h"

                                    
      
    

#if defined (RNG)

                     
                                
      
    

                                                                                

                                                   
      
    

                                                                     
      
    
#if defined(RNG_CR_CED)
typedef struct
{
  uint32_t                    ClockErrorDetection;                                  
} RNG_InitTypeDef;
#endif                 

   
      
    

                                                                      
      
    
typedef enum
{
  HAL_RNG_STATE_RESET     = 0x00U,                                             
  HAL_RNG_STATE_READY     = 0x01U,                                             
  HAL_RNG_STATE_BUSY      = 0x02U,                                             
  HAL_RNG_STATE_TIMEOUT   = 0x03U,                                             
  HAL_RNG_STATE_ERROR     = 0x04U                                              

} HAL_RNG_StateTypeDef;

   
      
    

                                                                       
      
    
#if (USE_HAL_RNG_REGISTER_CALLBACKS == 1)
typedef struct  __RNG_HandleTypeDef
#else
typedef struct
#endif                                     
{
  RNG_TypeDef                 *Instance;                                   
#if defined(RNG_CR_CED)

  RNG_InitTypeDef             Init;                                             
#endif                 

  HAL_LockTypeDef             Lock;                                        

  __IO HAL_RNG_StateTypeDef   State;                                       

  __IO  uint32_t              ErrorCode;                                   

  uint32_t                    RandomNumber;                                

#if (USE_HAL_RNG_REGISTER_CALLBACKS == 1)
  void (* ReadyDataCallback)(struct __RNG_HandleTypeDef *hrng, uint32_t random32bit);                                    
  void (* ErrorCallback)(struct __RNG_HandleTypeDef *hrng);                                                              

  void (* MspInitCallback)(struct __RNG_HandleTypeDef *hrng);                                                            
  void (* MspDeInitCallback)(struct __RNG_HandleTypeDef *hrng);                                                          
#endif                                      

} RNG_HandleTypeDef;

#if (USE_HAL_RNG_REGISTER_CALLBACKS == 1)
   
                                                      
    
typedef enum
{
  HAL_RNG_ERROR_CB_ID                   = 0x00U,                                           

  HAL_RNG_MSPINIT_CB_ID                 = 0x01U,                                           
  HAL_RNG_MSPDEINIT_CB_ID               = 0x02U                                            

} HAL_RNG_CallbackIDTypeDef;

   
                                               
    
typedef  void (*pRNG_CallbackTypeDef)(RNG_HandleTypeDef *hrng);                                                                                   
typedef  void (*pRNG_ReadyDataCallbackTypeDef)(RNG_HandleTypeDef *hrng, uint32_t random32bit);                                                                  

#endif                                     

   
      
    

   
      
    

                                                                                
                                                           
      
    

                                                                    
      
    
#define RNG_IT_DRDY  RNG_SR_DRDY                               
#define RNG_IT_CEI   RNG_SR_CEIS                               
#define RNG_IT_SEI   RNG_SR_SEIS                               
   
      
    

                                                               
      
    
#define RNG_FLAG_DRDY   RNG_SR_DRDY                                    
#define RNG_FLAG_CECS   RNG_SR_CECS                                    
#define RNG_FLAG_SECS   RNG_SR_SECS                                    
   
      
    

#if defined(RNG_CR_CED)
                                                                     
      
    
#define RNG_CED_ENABLE          0x00000000U                                       
#define RNG_CED_DISABLE         RNG_CR_CED                                        
   
      
    

#endif                 
                                                         
      
    
#define  HAL_RNG_ERROR_NONE             0x00000000U                             
#if (USE_HAL_RNG_REGISTER_CALLBACKS == 1)
#define  HAL_RNG_ERROR_INVALID_CALLBACK 0x00000001U                                   
#endif                                     
#define  HAL_RNG_ERROR_TIMEOUT          0x00000002U                             
#define  HAL_RNG_ERROR_BUSY             0x00000004U                             
#define  HAL_RNG_ERROR_SEED             0x00000008U                             
#define  HAL_RNG_ERROR_CLOCK            0x00000010U                             
#if defined(RNG_CR_CONDRST)
#define  HAL_RNG_ERROR_RECOVERSEED      0x00000020U                              
#endif                     
   
      
    

   
      
    

                                                                                
                                                     
      
    

                                 
                                 
                
    
#if (USE_HAL_RNG_REGISTER_CALLBACKS == 1)
#define __HAL_RNG_RESET_HANDLE_STATE(__HANDLE__)  do{                                                   \
                                                       (__HANDLE__)->State = HAL_RNG_STATE_RESET;       \
                                                       (__HANDLE__)->MspInitCallback = NULL;            \
                                                       (__HANDLE__)->MspDeInitCallback = NULL;          \
                                                    } while(0U)
#else
#define __HAL_RNG_RESET_HANDLE_STATE(__HANDLE__) ((__HANDLE__)->State = HAL_RNG_STATE_RESET)
#endif                                     

   
                                       
                                 
                
    
#define __HAL_RNG_ENABLE(__HANDLE__) ((__HANDLE__)->Instance->CR |=  RNG_CR_RNGEN)

   
                                        
                                 
                
    
#define __HAL_RNG_DISABLE(__HANDLE__) ((__HANDLE__)->Instance->CR &= ~RNG_CR_RNGEN)

   
                                               
                                 
                             
                                                               
                                              
                                                              
                                                             
                                                     
    
#define __HAL_RNG_GET_FLAG(__HANDLE__, __FLAG__) (((__HANDLE__)->Instance->SR & (__FLAG__)) == (__FLAG__))

   
                                                
                                 
                                      
                                                                  
                                                                               
                
    
#define __HAL_RNG_CLEAR_FLAG(__HANDLE__, __FLAG__)                                        

   
                                       
                                 
                
    
#define __HAL_RNG_ENABLE_IT(__HANDLE__) ((__HANDLE__)->Instance->CR |=  RNG_CR_IE)

   
                                        
                                 
                
    
#define __HAL_RNG_DISABLE_IT(__HANDLE__) ((__HANDLE__)->Instance->CR &= ~RNG_CR_IE)

   
                                                                           
                                 
                                                                           
                                                              
                                                     
                                                     
                                                    
                                                          
    
#define __HAL_RNG_GET_IT(__HANDLE__, __INTERRUPT__) (((__HANDLE__)->Instance->SR & (__INTERRUPT__)) == (__INTERRUPT__))

   
                                                 
                                 
                                                                           
                                                               
                                                     
                                                    
                                                                                                    
                
    
#define __HAL_RNG_CLEAR_IT(__HANDLE__, __INTERRUPT__) (((__HANDLE__)->Instance->SR) = ~(__INTERRUPT__))

   
      
    

#if defined (RNG_CR_CONDRST)
                                     
#include "stm32l4xx_hal_rng_ex.h"
#endif                      
                                                                                
                                                           
      
    

                                                                                      
      
    
HAL_StatusTypeDef HAL_RNG_Init(RNG_HandleTypeDef *hrng);
HAL_StatusTypeDef HAL_RNG_DeInit(RNG_HandleTypeDef *hrng);
void HAL_RNG_MspInit(RNG_HandleTypeDef *hrng);
void HAL_RNG_MspDeInit(RNG_HandleTypeDef *hrng);

                                                                                
#if (USE_HAL_RNG_REGISTER_CALLBACKS == 1)
HAL_StatusTypeDef HAL_RNG_RegisterCallback(RNG_HandleTypeDef *hrng, HAL_RNG_CallbackIDTypeDef CallbackID,
                                           pRNG_CallbackTypeDef pCallback);
HAL_StatusTypeDef HAL_RNG_UnRegisterCallback(RNG_HandleTypeDef *hrng, HAL_RNG_CallbackIDTypeDef CallbackID);

HAL_StatusTypeDef HAL_RNG_RegisterReadyDataCallback(RNG_HandleTypeDef *hrng, pRNG_ReadyDataCallbackTypeDef pCallback);
HAL_StatusTypeDef HAL_RNG_UnRegisterReadyDataCallback(RNG_HandleTypeDef *hrng);
#endif                                     

   
      
    

                                                                        
      
    
uint32_t HAL_RNG_GetRandomNumber(RNG_HandleTypeDef
                                 *hrng);                                                                 
uint32_t HAL_RNG_GetRandomNumber_IT(RNG_HandleTypeDef
                                    *hrng);                                                              
HAL_StatusTypeDef HAL_RNG_GenerateRandomNumber(RNG_HandleTypeDef *hrng, uint32_t *random32bit);
HAL_StatusTypeDef HAL_RNG_GenerateRandomNumber_IT(RNG_HandleTypeDef *hrng);
uint32_t HAL_RNG_ReadLastRandomNumber(const RNG_HandleTypeDef *hrng);

void HAL_RNG_IRQHandler(RNG_HandleTypeDef *hrng);
void HAL_RNG_ErrorCallback(RNG_HandleTypeDef *hrng);
void HAL_RNG_ReadyDataCallback(RNG_HandleTypeDef *hrng, uint32_t random32bit);

   
      
    

                                                                      
      
    
HAL_RNG_StateTypeDef HAL_RNG_GetState(const RNG_HandleTypeDef *hrng);
uint32_t             HAL_RNG_GetError(const RNG_HandleTypeDef *hrng);
   
      
    

   
      
    

                                                                                
                                                   
      
    
#define IS_RNG_IT(IT) (((IT) == RNG_IT_CEI) || \
                       ((IT) == RNG_IT_SEI))

#define IS_RNG_FLAG(FLAG) (((FLAG) == RNG_FLAG_DRDY) || \
                           ((FLAG) == RNG_FLAG_CECS) || \
                           ((FLAG) == RNG_FLAG_SECS))

#if defined(RNG_CR_CED)
   
                                                     
                                                  
                                                                  
    
#define IS_RNG_CED(__MODE__)   (((__MODE__) == RNG_CED_ENABLE) || \
                                ((__MODE__) == RNG_CED_DISABLE))
#endif                 
   
      
    

#if defined(RNG_CR_CONDRST)
                                                                                
                                                         
      
    
HAL_StatusTypeDef RNG_RecoverSeedError(RNG_HandleTypeDef *hrng);
   
      
    
#endif                     
   
      
    

#endif          

   
      
    

#ifdef __cplusplus
}
#endif


#endif                          

