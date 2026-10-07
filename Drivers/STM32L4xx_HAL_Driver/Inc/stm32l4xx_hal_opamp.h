/**
  ******************************************************************************
  * @file    stm32l4xx_hal_opamp.h
  * @author  MCD Application Team
  * @brief   Header file of OPAMP HAL module.
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

                                                                                
#ifndef STM32L4xx_HAL_OPAMP_H
#define STM32L4xx_HAL_OPAMP_H

#ifdef __cplusplus
 extern "C" {
#endif

                                                                                
#include "stm32l4xx_hal_def.h"

                                    
      
    

                     
      
    

                                                                                

                                                       
      
    

   
                                           
    

typedef struct
{
  uint32_t PowerSupplyRange;                                                                       
                                                                                                          
                                                                                                                                                                                                    

  uint32_t PowerMode;                                                                     
                                                                                                      

  uint32_t Mode;                                                     
                                                                                              
                                                                                            

  uint32_t InvertingInput;                                                                          
                                                                                                              
                                                                                                       
                                                                                                            
                                                                                                          
                                                                                    

  uint32_t NonInvertingInput;                                                               
                                                                                                              

  uint32_t PgaGain;                                                        
                                                                              
                                                                                                                     

  uint32_t UserTrimming;                                                
                                                                                                      
                                                                                               

  uint32_t TrimmingValueP;                                                             
                                                                                           
                                                                                                                   
                                                                           

  uint32_t TrimmingValueN;                                                             
                                                                                           
                                                                                                                   
                                                                           

  uint32_t TrimmingValuePLowPower;                                                     
                                                                                           
                                                                                                                   
                                                                           

  uint32_t TrimmingValueNLowPower;                                                     
                                                                                           
                                                                                                                   
                                                                           

}OPAMP_InitTypeDef;

   
                                           
    

typedef enum
{
  HAL_OPAMP_STATE_RESET               = 0x00000000,                                              

  HAL_OPAMP_STATE_READY               = 0x00000001,                                               
  HAL_OPAMP_STATE_CALIBBUSY           = 0x00000002,                                                  

  HAL_OPAMP_STATE_BUSY                = 0x00000004,                                                    
  HAL_OPAMP_STATE_BUSYLOCKED          = 0x00000005                      
                                                                                                             

}HAL_OPAMP_StateTypeDef;

   
                                            
    

#if (USE_HAL_OPAMP_REGISTER_CALLBACKS == 1)
typedef struct __OPAMP_HandleTypeDef
#else
typedef struct
#endif                                       
{
  OPAMP_TypeDef       *Instance;                                                                     
  OPAMP_InitTypeDef   Init;                                                          
  HAL_StatusTypeDef   Status;                                                        
  HAL_LockTypeDef     Lock;                                                        
  __IO HAL_OPAMP_StateTypeDef  State;                                                

#if (USE_HAL_OPAMP_REGISTER_CALLBACKS == 1)
void (* MspInitCallback)                (struct __OPAMP_HandleTypeDef *hopamp);
void (* MspDeInitCallback)              (struct __OPAMP_HandleTypeDef *hopamp);
#endif                                       

}OPAMP_HandleTypeDef;

   
                                                    
    

typedef  uint32_t HAL_OPAMP_TrimmingValueTypeDef;

   
      
    

#if (USE_HAL_OPAMP_REGISTER_CALLBACKS == 1)
   
                                                        
    
typedef enum
{
  HAL_OPAMP_MSPINIT_CB_ID                     = 0x01U,                                             
  HAL_OPAMP_MSPDEINIT_CB_ID                   = 0x02U,                                             
  HAL_OPAMP_ALL_CB_ID                          = 0x03U                                              
}HAL_OPAMP_CallbackIDTypeDef;

   
                                                 
    
typedef void (*pOPAMP_CallbackTypeDef)(OPAMP_HandleTypeDef *hopamp);
#endif                                       


                                                                                

                                                               
      
    

                                   
      
    
#define OPAMP_STANDALONE_MODE            0x00000000U                                   
#define OPAMP_PGA_MODE                   OPAMP_CSR_OPAMODE_1                    
#define OPAMP_FOLLOWER_MODE              OPAMP_CSR_OPAMODE                           

   
      
    

                                                               
      
    

#define OPAMP_NONINVERTINGINPUT_IO0         0x00000000U                                                                           
#define OPAMP_NONINVERTINGINPUT_DAC_CH      OPAMP_CSR_VPSEL                                                                             

   
      
    

                                                        
      
    

#define OPAMP_INVERTINGINPUT_IO0              0x00000000U                                                                                    
#define OPAMP_INVERTINGINPUT_IO1              OPAMP_CSR_VMSEL_0                                                                                                      
#define OPAMP_INVERTINGINPUT_CONNECT_NO       OPAMP_CSR_VMSEL_1                                                                             

   
      
    

                                          
      
    

#define OPAMP_PGA_GAIN_2                0x00000000U                                                        
#define OPAMP_PGA_GAIN_4                OPAMP_CSR_PGGAIN_0                                                 
#define OPAMP_PGA_GAIN_8                OPAMP_CSR_PGGAIN_1                                                 
#define OPAMP_PGA_GAIN_16              (OPAMP_CSR_PGGAIN_0 | OPAMP_CSR_PGGAIN_1)                           

   
      
    

                                             
      
    
#define OPAMP_POWERMODE_NORMALPOWER   0x00000000U                                                
#define OPAMP_POWERMODE_LOWPOWER      OPAMP_CSR_OPALPM                                           

   
      
    

                                                           
      
    
#define OPAMP_POWERSUPPLY_LOW          0x00000000U                                                                  
#define OPAMP_POWERSUPPLY_HIGH         OPAMP1_CSR_OPARANGE                                                            

   
      
    

                                                    
      
    
#define OPAMP_TRIMMING_FACTORY        0x00000000U                                                             
#define OPAMP_TRIMMING_USER           OPAMP_CSR_USERTRIM                                                   

   
      
    

                                                          
      
    
#define OPAMP_FACTORYTRIMMING_DUMMY    0xFFFFFFFFU                                                                             
#define OPAMP_FACTORYTRIMMING_N        0U                                                   
#define OPAMP_FACTORYTRIMMING_P        1U                                                   

   
      
    

    
      
    

                                                                                
                                                             
                                                
      
    

                                              
#define OPAMP_INPUT_NONINVERTING              ((uint32_t) 8)                            

                                                                                
                                                                                
                                                                                
                                                                                
#define OPAMP_TRIMMING_DELAY               ((uint32_t) 1)

   
      
    

                                                                                
                                                         
      
    

                                    
                                    
                
    
#if (USE_HAL_OPAMP_REGISTER_CALLBACKS == 1)
#define __HAL_OPAMP_RESET_HANDLE_STATE(__HANDLE__)           do {                                              \
                                                                 (__HANDLE__)->State = HAL_OPAMP_STATE_RESET; \
                                                                 (__HANDLE__)->MspInitCallback = NULL;       \
                                                                 (__HANDLE__)->MspDeInitCallback = NULL;     \
                                                               } while(0)
#else
#define __HAL_OPAMP_RESET_HANDLE_STATE(__HANDLE__) ((__HANDLE__)->State = HAL_OPAMP_STATE_RESET)
#endif                                       



   
      
    

                                                                                

                                                       
      
    

#define IS_OPAMP_FUNCTIONAL_NORMALMODE(INPUT) (((INPUT) == OPAMP_STANDALONE_MODE) || \
                                               ((INPUT) == OPAMP_PGA_MODE) || \
                                               ((INPUT) == OPAMP_FOLLOWER_MODE))

#if defined (STM32L471xx) || defined (STM32L475xx) || defined (STM32L476xx) || defined (STM32L485xx) || defined (STM32L486xx) || \
    defined (STM32L496xx) || defined (STM32L4A6xx) || \
    defined (STM32L4P5xx) || defined (STM32L4Q5xx) || \
    defined (STM32L4R5xx) || defined (STM32L4R7xx) || defined (STM32L4R9xx) || defined (STM32L4S5xx) || defined (STM32L4S7xx) || defined(STM32L4S9xx)
#define IS_OPAMP_INVERTING_INPUT_STANDALONE(INPUT) (((INPUT) == OPAMP_INVERTINGINPUT_IO0) || \
                                                    ((INPUT) == OPAMP_INVERTINGINPUT_IO1))
#endif                                                                   
                                                                         
                                                                         
                                                                                     

#if defined (STM32L412xx) || defined (STM32L422xx) || \
    defined (STM32L431xx) || defined (STM32L432xx) || defined (STM32L433xx)  || defined (STM32L442xx)  || defined (STM32L443xx) || \
    defined (STM32L451xx) || defined (STM32L452xx) || defined (STM32L462xx)
#define IS_OPAMP_INVERTING_INPUT_STANDALONE(INPUT) ((INPUT) == OPAMP_INVERTINGINPUT_IO0)
#endif                                                                   
                                                                         
                                                

#if defined (STM32L412xx) || defined (STM32L422xx)
#define IS_OPAMP_NONINVERTING_INPUT(INPUT) ((INPUT) == OPAMP_NONINVERTINGINPUT_IO0)
#endif                                                                   

#if defined (STM32L431xx) || defined (STM32L432xx) || defined (STM32L433xx)  || defined (STM32L442xx)  || defined (STM32L443xx) || \
    defined (STM32L451xx) || defined (STM32L452xx) || defined (STM32L462xx) || \
    defined (STM32L471xx) || defined (STM32L475xx) || defined (STM32L476xx) || defined (STM32L485xx) || defined (STM32L486xx) || \
    defined (STM32L496xx) || defined (STM32L4A6xx) || \
    defined (STM32L4P5xx) || defined (STM32L4Q5xx) || \
    defined (STM32L4R5xx) || defined (STM32L4R7xx) || defined (STM32L4R9xx) || defined (STM32L4S5xx) || defined (STM32L4S7xx) || defined(STM32L4S9xx)
#define IS_OPAMP_NONINVERTING_INPUT(INPUT) (((INPUT) == OPAMP_NONINVERTINGINPUT_IO0) || \
                                            ((INPUT) == OPAMP_NONINVERTINGINPUT_DAC_CH))
#endif                                                                   
                                                
                                                                         
                                                                         
                                                                         
                                                                                     

#if defined (STM32L471xx) || defined (STM32L475xx) || defined (STM32L476xx) || defined (STM32L485xx) || defined (STM32L486xx) || \
    defined (STM32L496xx) || defined (STM32L4A6xx) || \
    defined (STM32L4P5xx) || defined (STM32L4Q5xx) || \
    defined (STM32L4R5xx) || defined (STM32L4R7xx) || defined (STM32L4R9xx) || defined (STM32L4S5xx) || defined (STM32L4S7xx) || defined(STM32L4S9xx)
#define IS_OPAMP_INVERTING_INPUT_PGA(INPUT) (((INPUT) == OPAMP_INVERTINGINPUT_IO0) || \
                                             ((INPUT) == OPAMP_INVERTINGINPUT_IO1) || \
                                             ((INPUT) == OPAMP_INVERTINGINPUT_CONNECT_NO))
#endif                                                                   
                                                                         
                                                                         
                                                                                     

#if defined (STM32L412xx) || defined (STM32L422xx) || \
    defined (STM32L431xx) || defined (STM32L432xx) || defined (STM32L433xx)  || defined (STM32L442xx)  || defined (STM32L443xx) || \
    defined (STM32L451xx) || defined (STM32L452xx) || defined (STM32L462xx)
#define IS_OPAMP_INVERTING_INPUT_PGA(INPUT) (((INPUT) == OPAMP_INVERTINGINPUT_IO0) || \
                                             ((INPUT) == OPAMP_INVERTINGINPUT_CONNECT_NO))
#endif                                                                   
                                                                         
                                                

#define IS_OPAMP_PGA_GAIN(GAIN) (((GAIN) == OPAMP_PGA_GAIN_2) || \
                                 ((GAIN) == OPAMP_PGA_GAIN_4) || \
                                 ((GAIN) == OPAMP_PGA_GAIN_8) || \
                                 ((GAIN) == OPAMP_PGA_GAIN_16))

#define IS_OPAMP_POWERMODE(TRIMMING) (((TRIMMING) == OPAMP_POWERMODE_NORMALPOWER) || \
                                      ((TRIMMING) == OPAMP_POWERMODE_LOWPOWER) )

#define IS_OPAMP_POWER_SUPPLY_RANGE(RANGE) (((RANGE) == OPAMP_POWERSUPPLY_LOW) || \
                                            ((RANGE) == OPAMP_POWERSUPPLY_HIGH)  )

#define IS_OPAMP_TRIMMING(TRIMMING) (((TRIMMING) == OPAMP_TRIMMING_FACTORY) || \
                                     ((TRIMMING) == OPAMP_TRIMMING_USER))


#define IS_OPAMP_TRIMMINGVALUE(TRIMMINGVALUE) ((TRIMMINGVALUE) <= 31U)

#define IS_OPAMP_FACTORYTRIMMING(TRIMMING) (((TRIMMING) == OPAMP_FACTORYTRIMMING_N) || \
                                             ((TRIMMING) == OPAMP_FACTORYTRIMMING_P))

   
      
    

                                       
#include "stm32l4xx_hal_opamp_ex.h"

                                                                                
                                        
      
    

                                               
      
    
                                                                                  
HAL_StatusTypeDef HAL_OPAMP_Init(OPAMP_HandleTypeDef *hopamp);
HAL_StatusTypeDef HAL_OPAMP_DeInit (OPAMP_HandleTypeDef *hopamp);
void HAL_OPAMP_MspInit(OPAMP_HandleTypeDef *hopamp);
void HAL_OPAMP_MspDeInit(OPAMP_HandleTypeDef *hopamp);
   
      
    

                                               
      
    

                                                                                  
HAL_StatusTypeDef HAL_OPAMP_Start(OPAMP_HandleTypeDef *hopamp);
HAL_StatusTypeDef HAL_OPAMP_Stop(OPAMP_HandleTypeDef *hopamp);
HAL_StatusTypeDef HAL_OPAMP_SelfCalibrate(OPAMP_HandleTypeDef *hopamp);

   
      
    

                                               
      
    

                                                                                  
#if (USE_HAL_OPAMP_REGISTER_CALLBACKS == 1)
                                              
HAL_StatusTypeDef HAL_OPAMP_RegisterCallback (OPAMP_HandleTypeDef *hopamp, HAL_OPAMP_CallbackIDTypeDef CallbackID, pOPAMP_CallbackTypeDef pCallback);
HAL_StatusTypeDef HAL_OPAMP_UnRegisterCallback (OPAMP_HandleTypeDef *hopamp, HAL_OPAMP_CallbackIDTypeDef CallbackID);
#endif                                       

HAL_StatusTypeDef HAL_OPAMP_Lock(OPAMP_HandleTypeDef *hopamp);
HAL_OPAMP_TrimmingValueTypeDef HAL_OPAMP_GetTrimOffset (OPAMP_HandleTypeDef *hopamp, uint32_t trimmingoffset);

   
      
    

                                               
      
    

                                                                                  
HAL_OPAMP_StateTypeDef HAL_OPAMP_GetState(OPAMP_HandleTypeDef *hopamp);

   
      
    

   
      
    

   
      
    

   
      
    

#ifdef __cplusplus
}
#endif

#endif                            
