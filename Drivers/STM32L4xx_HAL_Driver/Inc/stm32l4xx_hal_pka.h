/**
  ******************************************************************************
  * @file    stm32l4xx_hal_pka.h
  * @author  MCD Application Team
  * @brief   Header file of PKA HAL module.
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

                                                                                
#ifndef STM32L4xx_HAL_PKA_H
#define STM32L4xx_HAL_PKA_H

#ifdef __cplusplus
extern "C" {
#endif

                                                                                
#include "stm32l4xx_hal_def.h"

                                    
      
    

#if defined(PKA) && defined(HAL_PKA_MODULE_ENABLED)

                   
      
    

                                                                                
                                                   
      
    

                                                                           
                                           
      
    
typedef enum
{
  HAL_PKA_STATE_RESET   = 0x00U,                                              
  HAL_PKA_STATE_READY   = 0x01U,                                              
  HAL_PKA_STATE_BUSY    = 0x02U,                                              
  HAL_PKA_STATE_ERROR   = 0x03U,                                              
}
HAL_PKA_StateTypeDef;

   
      
    

#if (USE_HAL_PKA_REGISTER_CALLBACKS == 1)
                                                         
      
    
typedef enum
{
  HAL_PKA_OPERATION_COMPLETE_CB_ID      = 0x00U,                                             
  HAL_PKA_ERROR_CB_ID                   = 0x01U,                                             
  HAL_PKA_MSPINIT_CB_ID                 = 0x02U,                                             
  HAL_PKA_MSPDEINIT_CB_ID               = 0x03U                                              
} HAL_PKA_CallbackIDTypeDef;

   
      
    

#endif                                     

                                                                 
                                     
      
    
#define HAL_PKA_ERROR_NONE      (0x00000000U)
#define HAL_PKA_ERROR_ADDRERR   (0x00000001U)
#define HAL_PKA_ERROR_RAMERR    (0x00000002U)
#define HAL_PKA_ERROR_TIMEOUT   (0x00000004U)
#define HAL_PKA_ERROR_OPERATION (0x00000008U)
#if (USE_HAL_PKA_REGISTER_CALLBACKS == 1)
#define HAL_PKA_ERROR_INVALID_CALLBACK  (0x00000010U)                                  
#endif                                     

   
      
    

                                                                             
                                           
      
    
#if (USE_HAL_PKA_REGISTER_CALLBACKS == 1)
typedef struct __PKA_HandleTypeDef
#else
typedef struct
#endif                                      
{
  PKA_TypeDef                   *Instance;                                           
  __IO HAL_PKA_StateTypeDef     State;                                   
  __IO uint32_t                 ErrorCode;                                    
#if (USE_HAL_PKA_REGISTER_CALLBACKS == 1)
  void (* OperationCpltCallback)(struct __PKA_HandleTypeDef *hpka);                                      
  void (* ErrorCallback)(struct __PKA_HandleTypeDef *hpka);                                              
  void (* MspInitCallback)(struct __PKA_HandleTypeDef *hpka);                                            
  void (* MspDeInitCallback)(struct __PKA_HandleTypeDef *hpka);                                          
#endif                                      
} PKA_HandleTypeDef;
   
      
    

#if (USE_HAL_PKA_REGISTER_CALLBACKS == 1)
                                                                     
                                           
      
    
typedef  void (*pPKA_CallbackTypeDef)(PKA_HandleTypeDef *hpka);                                           
   
      
    
#endif                                     
                                                              
                                            
      
    
typedef struct
{
  uint32_t scalarMulSize;                                                          
  uint32_t modulusSize;                                                                                     
  uint32_t coefSign;                                                   
  const uint8_t *coefA;                                                                                        
  const uint8_t *modulus;                                                                                      
  const uint8_t *pointX;                                                                                       
  const uint8_t *pointY;                                                                                       
  const uint8_t *scalarMul;                                                                                      
  const uint32_t *pMontgomeryParam;                                                                              
} PKA_ECCMulFastModeInTypeDef;

typedef struct
{
  uint32_t scalarMulSize;                                                          
  uint32_t modulusSize;                                                                                     
  uint32_t coefSign;                                                   
  const uint8_t *coefA;                                                                                        
  const uint8_t *modulus;                                                                                      
  const uint8_t *pointX;                                                                                       
  const uint8_t *pointY;                                                                                       
  const uint8_t *scalarMul;                                                                                      
} PKA_ECCMulInTypeDef;

typedef struct
{
  uint32_t modulusSize;                                                                                            
  uint32_t coefSign;                                                   
  const uint8_t *coefA;                                                                                        
  const uint8_t *coefB;                                                                                        
  const uint8_t *modulus;                                                                                      
  const uint8_t *pointX;                                                                                       
  const uint8_t *pointY;                                                                                       
} PKA_PointCheckInTypeDef;

typedef struct
{
  uint32_t size;                                                              
  const uint8_t *pOpDp;                                                                          
  const uint8_t *pOpDq;                                                                          
  const uint8_t *pOpQinv;                                                                        
  const uint8_t *pPrimeP;                                                                        
  const uint8_t *pPrimeQ;                                                                        
  const uint8_t *popA;                                                                         
} PKA_RSACRTExpInTypeDef;

typedef struct
{
  uint32_t primeOrderSize;                                                          
  uint32_t modulusSize;                                                          
  uint32_t coefSign;                                                   
  const uint8_t *coef;                                                                                             
  const uint8_t *modulus;                                                                                          
  const uint8_t *basePointX;                                                                                       
  const uint8_t *basePointY;                                                                                       
  const uint8_t *pPubKeyCurvePtX;                                                                                  
  const uint8_t *pPubKeyCurvePtY;                                                                                  
  const uint8_t *RSign;                                                                                               
  const uint8_t *SSign;                                                                                               
  const uint8_t *hash;                                                                                                
  const uint8_t *primeOrder;                                                                                          
} PKA_ECDSAVerifInTypeDef;

typedef struct
{
  uint32_t primeOrderSize;                                                          
  uint32_t modulusSize;                                                          
  uint32_t coefSign;                                                   
  const uint8_t *coef;                                                                                             
  const uint8_t *modulus;                                                                                          
  const uint8_t *integer;                                                                                             
  const uint8_t *basePointX;                                                                                       
  const uint8_t *basePointY;                                                                                       
  const uint8_t *hash;                                                                                                
  const uint8_t *privateKey;                                                                                          
  const uint8_t *primeOrder;                                                                                          
} PKA_ECDSASignInTypeDef;

typedef struct
{
  uint8_t *RSign;                                                                                                  
  uint8_t *SSign;                                                                                                  
} PKA_ECDSASignOutTypeDef;

typedef struct
{
  uint8_t *ptX;                                                                                                    
  uint8_t *ptY;                                                                                                    
} PKA_ECDSASignOutExtParamTypeDef, PKA_ECCMulOutTypeDef;


typedef struct
{
  uint32_t expSize;                                                           
  uint32_t OpSize;                                                                      
  const uint8_t *pExp;                                                                                    
  const uint8_t *pOp1;                                                                                   
  const uint8_t *pMod;                                                                                   
} PKA_ModExpInTypeDef;


typedef struct
{
  uint32_t expSize;                                                                                 
  uint32_t OpSize;                                                                      
  const uint8_t *pExp;                                                                                    
  const uint8_t *pOp1;                                                                                   
  const uint8_t *pMod;                                                                                   
  const uint32_t *pMontgomeryParam;                                                                         
} PKA_ModExpFastModeInTypeDef;

typedef struct
{
  uint32_t size;                                                              
  const uint8_t *pOp1;                                                                    
} PKA_MontgomeryParamInTypeDef;

typedef struct
{
  uint32_t size;                                                                        
  const uint32_t *pOp1;                                                                     
  const uint32_t *pOp2;                                                                     
} PKA_AddInTypeDef, PKA_SubInTypeDef, PKA_MulInTypeDef, PKA_CmpInTypeDef;

typedef struct
{
  uint32_t size;                                                              
  const uint32_t *pOp1;                                                                           
  const uint8_t *pMod;                                                                              
} PKA_ModInvInTypeDef;

typedef struct
{
  uint32_t OpSize;                                                            
  uint32_t modSize;                                                           
  const uint32_t *pOp1;                                                                             
  const uint8_t *pMod;                                                                               
} PKA_ModRedInTypeDef;

typedef struct
{
  uint32_t size;                                                                        
  const uint32_t *pOp1;                                                                     
  const uint32_t *pOp2;                                                                     
  const uint8_t  *pOp3;                                                                       
} PKA_ModAddInTypeDef, PKA_ModSubInTypeDef, PKA_MontgomeryMulInTypeDef;

   
      
    

   
      
    

                                                                                
                                                           
      
    

                               
      
    
#define PKA_MODE_MONTGOMERY_PARAM                 (0x00000001U)
#define PKA_MODE_MODULAR_EXP                      (0x00000000U)
#define PKA_MODE_MODULAR_EXP_FAST_MODE            (0x00000002U)
#define PKA_MODE_ECC_MUL                          (0x00000020U)
#define PKA_MODE_ECC_MUL_FAST_MODE                (0x00000022U)
#define PKA_MODE_ECDSA_SIGNATURE                  (0x00000024U)
#define PKA_MODE_ECDSA_VERIFICATION               (0x00000026U)
#define PKA_MODE_POINT_CHECK                      (0x00000028U)
#define PKA_MODE_RSA_CRT_EXP                      (0x00000007U)
#define PKA_MODE_MODULAR_INV                      (0x00000008U)
#define PKA_MODE_ARITHMETIC_ADD                   (0x00000009U)
#define PKA_MODE_ARITHMETIC_SUB                   (0x0000000AU)
#define PKA_MODE_ARITHMETIC_MUL                   (0x0000000BU)
#define PKA_MODE_COMPARISON                       (0x0000000CU)
#define PKA_MODE_MODULAR_RED                      (0x0000000DU)
#define PKA_MODE_MODULAR_ADD                      (0x0000000EU)
#define PKA_MODE_MODULAR_SUB                      (0x0000000FU)
#define PKA_MODE_MONTGOMERY_MUL                   (0x00000010U)
   
      
    

                                                                                           
                                   
      
    
#define PKA_IT_PROCEND                            PKA_CR_PROCENDIE
#define PKA_IT_ADDRERR                            PKA_CR_ADDRERRIE
#define PKA_IT_RAMERR                             PKA_CR_RAMERRIE

   
      
    

                                                     
      
    
#define PKA_FLAG_PROCEND                          PKA_SR_PROCENDF
#define PKA_FLAG_ADDRERR                          PKA_SR_ADDRERRF
#define PKA_FLAG_RAMERR                           PKA_SR_RAMERRF

   
      
    

   
      
    

                                                                                

                                                     
      
    

                                   
                                               
                
    
#if (USE_HAL_PKA_REGISTER_CALLBACKS == 1)
#define __HAL_PKA_RESET_HANDLE_STATE(__HANDLE__)                do{                                                   \
                                                                    (__HANDLE__)->State = HAL_PKA_STATE_RESET;       \
                                                                    (__HANDLE__)->MspInitCallback = NULL;            \
                                                                    (__HANDLE__)->MspDeInitCallback = NULL;          \
                                                                  } while(0)
#else
#define __HAL_PKA_RESET_HANDLE_STATE(__HANDLE__)                ((__HANDLE__)->State = HAL_PKA_STATE_RESET)
#endif                                     

                                               
                                               
                                                                   
                                                             
                                                                         
                                                                      
                                                                 
                
    
#define __HAL_PKA_ENABLE_IT(__HANDLE__, __INTERRUPT__)          ((__HANDLE__)->Instance->CR |= (__INTERRUPT__))

                                                
                                               
                                                                    
                                                             
                                                                         
                                                                      
                                                                 
                
    
#define __HAL_PKA_DISABLE_IT(__HANDLE__, __INTERRUPT__)         ((__HANDLE__)->Instance->CR &= (~(__INTERRUPT__)))

                                                                               
                                               
                                                                      
                                                             
                                                                         
                                                                      
                                                                 
                                                         
    
#define __HAL_PKA_GET_IT_SOURCE(__HANDLE__, __INTERRUPT__)      ((((__HANDLE__)->Instance->CR\
                                                                   & (__INTERRUPT__)) == (__INTERRUPT__)) ? SET : RESET)

                                                               
                                               
                                                 
                                                             
                                                          
                                                       
                                                  
                                                    
    
#define __HAL_PKA_GET_FLAG(__HANDLE__, __FLAG__)                (((((__HANDLE__)->Instance->SR)\
                                                                   & (__FLAG__)) == (__FLAG__)) ? SET : RESET)

                                                                                         
                                               
                                                 
                                                                           
                                                          
                                                       
                                                  
                
    
#define __HAL_PKA_CLEAR_FLAG(__HANDLE__, __FLAG__)              ((__HANDLE__)->Instance->CLRFR = (__FLAG__))

                                                
                                               
                
    
#define __HAL_PKA_ENABLE(__HANDLE__)                            (SET_BIT((__HANDLE__)->Instance->CR,  PKA_CR_EN))

                                                 
                                               
                
    
#define __HAL_PKA_DISABLE(__HANDLE__)                           (CLEAR_BIT((__HANDLE__)->Instance->CR, PKA_CR_EN))

                                  
                                               
                
    
#define __HAL_PKA_START(__HANDLE__)                             (SET_BIT((__HANDLE__)->Instance->CR,  PKA_CR_START))
   
      
    

                                                                            
                                                                                
                                      
      
    

                                             
      
    
                                                                                
HAL_StatusTypeDef HAL_PKA_Init(PKA_HandleTypeDef *hpka);
HAL_StatusTypeDef HAL_PKA_DeInit(PKA_HandleTypeDef *hpka);
void              HAL_PKA_MspInit(PKA_HandleTypeDef *hpka);
void              HAL_PKA_MspDeInit(PKA_HandleTypeDef *hpka);

#if (USE_HAL_PKA_REGISTER_CALLBACKS == 1)
                                                                                
HAL_StatusTypeDef HAL_PKA_RegisterCallback(PKA_HandleTypeDef *hpka, HAL_PKA_CallbackIDTypeDef CallbackID,
                                           pPKA_CallbackTypeDef pCallback);
HAL_StatusTypeDef HAL_PKA_UnRegisterCallback(PKA_HandleTypeDef *hpka, HAL_PKA_CallbackIDTypeDef CallbackID);
#endif                                     

   
      
    

                                             
      
    
                                                                                
                                                                                
HAL_StatusTypeDef HAL_PKA_ModExp(PKA_HandleTypeDef *hpka, PKA_ModExpInTypeDef *in, uint32_t Timeout);
HAL_StatusTypeDef HAL_PKA_ModExp_IT(PKA_HandleTypeDef *hpka, PKA_ModExpInTypeDef *in);
HAL_StatusTypeDef HAL_PKA_ModExpFastMode(PKA_HandleTypeDef *hpka, PKA_ModExpFastModeInTypeDef *in, uint32_t Timeout);
HAL_StatusTypeDef HAL_PKA_ModExpFastMode_IT(PKA_HandleTypeDef *hpka, PKA_ModExpFastModeInTypeDef *in);
void HAL_PKA_ModExp_GetResult(PKA_HandleTypeDef *hpka, uint8_t *pRes);

HAL_StatusTypeDef HAL_PKA_ECDSASign(PKA_HandleTypeDef *hpka, PKA_ECDSASignInTypeDef *in, uint32_t Timeout);
HAL_StatusTypeDef HAL_PKA_ECDSASign_IT(PKA_HandleTypeDef *hpka, PKA_ECDSASignInTypeDef *in);
void HAL_PKA_ECDSASign_GetResult(PKA_HandleTypeDef *hpka, PKA_ECDSASignOutTypeDef *out,
                                 PKA_ECDSASignOutExtParamTypeDef *outExt);

HAL_StatusTypeDef HAL_PKA_ECDSAVerif(PKA_HandleTypeDef *hpka, PKA_ECDSAVerifInTypeDef *in, uint32_t Timeout);
HAL_StatusTypeDef HAL_PKA_ECDSAVerif_IT(PKA_HandleTypeDef *hpka, PKA_ECDSAVerifInTypeDef *in);
uint32_t HAL_PKA_ECDSAVerif_IsValidSignature(PKA_HandleTypeDef const *const hpka);

HAL_StatusTypeDef HAL_PKA_RSACRTExp(PKA_HandleTypeDef *hpka, PKA_RSACRTExpInTypeDef *in, uint32_t Timeout);
HAL_StatusTypeDef HAL_PKA_RSACRTExp_IT(PKA_HandleTypeDef *hpka, PKA_RSACRTExpInTypeDef *in);
void HAL_PKA_RSACRTExp_GetResult(PKA_HandleTypeDef *hpka, uint8_t *pRes);

HAL_StatusTypeDef HAL_PKA_PointCheck(PKA_HandleTypeDef *hpka, PKA_PointCheckInTypeDef *in, uint32_t Timeout);
HAL_StatusTypeDef HAL_PKA_PointCheck_IT(PKA_HandleTypeDef *hpka, PKA_PointCheckInTypeDef *in);
uint32_t HAL_PKA_PointCheck_IsOnCurve(PKA_HandleTypeDef const *const hpka);

HAL_StatusTypeDef HAL_PKA_ECCMul(PKA_HandleTypeDef *hpka, PKA_ECCMulInTypeDef *in, uint32_t Timeout);
HAL_StatusTypeDef HAL_PKA_ECCMul_IT(PKA_HandleTypeDef *hpka, PKA_ECCMulInTypeDef *in);
HAL_StatusTypeDef HAL_PKA_ECCMulFastMode(PKA_HandleTypeDef *hpka, PKA_ECCMulFastModeInTypeDef *in, uint32_t Timeout);
HAL_StatusTypeDef HAL_PKA_ECCMulFastMode_IT(PKA_HandleTypeDef *hpka, PKA_ECCMulFastModeInTypeDef *in);
void HAL_PKA_ECCMul_GetResult(PKA_HandleTypeDef *hpka, PKA_ECCMulOutTypeDef *out);

HAL_StatusTypeDef HAL_PKA_Add(PKA_HandleTypeDef *hpka, PKA_AddInTypeDef *in, uint32_t Timeout);
HAL_StatusTypeDef HAL_PKA_Add_IT(PKA_HandleTypeDef *hpka, PKA_AddInTypeDef *in);
HAL_StatusTypeDef HAL_PKA_Sub(PKA_HandleTypeDef *hpka, PKA_SubInTypeDef *in, uint32_t Timeout);
HAL_StatusTypeDef HAL_PKA_Sub_IT(PKA_HandleTypeDef *hpka, PKA_SubInTypeDef *in);
HAL_StatusTypeDef HAL_PKA_Cmp(PKA_HandleTypeDef *hpka, PKA_CmpInTypeDef *in, uint32_t Timeout);
HAL_StatusTypeDef HAL_PKA_Cmp_IT(PKA_HandleTypeDef *hpka, PKA_CmpInTypeDef *in);
HAL_StatusTypeDef HAL_PKA_Mul(PKA_HandleTypeDef *hpka, PKA_MulInTypeDef *in, uint32_t Timeout);
HAL_StatusTypeDef HAL_PKA_Mul_IT(PKA_HandleTypeDef *hpka, PKA_MulInTypeDef *in);
HAL_StatusTypeDef HAL_PKA_ModAdd(PKA_HandleTypeDef *hpka, PKA_ModAddInTypeDef *in, uint32_t Timeout);
HAL_StatusTypeDef HAL_PKA_ModAdd_IT(PKA_HandleTypeDef *hpka, PKA_ModAddInTypeDef *in);
HAL_StatusTypeDef HAL_PKA_ModSub(PKA_HandleTypeDef *hpka, PKA_ModSubInTypeDef *in, uint32_t Timeout);
HAL_StatusTypeDef HAL_PKA_ModSub_IT(PKA_HandleTypeDef *hpka, PKA_ModSubInTypeDef *in);
HAL_StatusTypeDef HAL_PKA_ModInv(PKA_HandleTypeDef *hpka, PKA_ModInvInTypeDef *in, uint32_t Timeout);
HAL_StatusTypeDef HAL_PKA_ModInv_IT(PKA_HandleTypeDef *hpka, PKA_ModInvInTypeDef *in);
HAL_StatusTypeDef HAL_PKA_ModRed(PKA_HandleTypeDef *hpka, PKA_ModRedInTypeDef *in, uint32_t Timeout);
HAL_StatusTypeDef HAL_PKA_ModRed_IT(PKA_HandleTypeDef *hpka, PKA_ModRedInTypeDef *in);
HAL_StatusTypeDef HAL_PKA_MontgomeryMul(PKA_HandleTypeDef *hpka, PKA_MontgomeryMulInTypeDef *in, uint32_t Timeout);
HAL_StatusTypeDef HAL_PKA_MontgomeryMul_IT(PKA_HandleTypeDef *hpka, PKA_MontgomeryMulInTypeDef *in);
void HAL_PKA_Arithmetic_GetResult(PKA_HandleTypeDef *hpka, uint32_t *pRes);

HAL_StatusTypeDef HAL_PKA_MontgomeryParam(PKA_HandleTypeDef *hpka, PKA_MontgomeryParamInTypeDef *in, uint32_t Timeout);
HAL_StatusTypeDef HAL_PKA_MontgomeryParam_IT(PKA_HandleTypeDef *hpka, PKA_MontgomeryParamInTypeDef *in);
void HAL_PKA_MontgomeryParam_GetResult(PKA_HandleTypeDef *hpka, uint32_t *pRes);


HAL_StatusTypeDef HAL_PKA_Abort(PKA_HandleTypeDef *hpka);
void HAL_PKA_RAMReset(PKA_HandleTypeDef *hpka);
void HAL_PKA_OperationCpltCallback(PKA_HandleTypeDef *hpka);
void HAL_PKA_ErrorCallback(PKA_HandleTypeDef *hpka);
void HAL_PKA_IRQHandler(PKA_HandleTypeDef *hpka);
   
      
    

                                             
      
    
                                                                                
HAL_PKA_StateTypeDef HAL_PKA_GetState(const PKA_HandleTypeDef *hpka);
uint32_t             HAL_PKA_GetError(const PKA_HandleTypeDef *hpka);
   
      
    

   
      
    

   
      
    

#endif                                                      

   
      
    

#ifdef __cplusplus
}
#endif

#endif                          
