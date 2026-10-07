                                                                         
                                  
                                    
                                                         
  
                               
                       
  
                                   
                                                                          
/*
 * Copyright (C) 2010-2019 ARM Limited or its affiliates. All rights reserved.
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed under the Apache License, Version 2.0 (the License); you may
 * not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an AS IS BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "arm_math.h"
#include "arm_common_tables.h"
#include "arm_const_structs.h"

   
                     
    
   

   
                                                                
                                                                                     
                                                 
                                                                     
                                                 
                                                 
                                                                                   
                                                               
                                                              
                                 
                                                                        
                                                                                                     

                        
                                                                                                
                                                                                           
      
                                                                                                                    
                                                                                      
      
                                                                                                                              
                                                                                                                     
      
                                                                       
   

arm_status arm_rfft_init_q15(
    arm_rfft_instance_q15 * S,
    uint32_t fftLenReal,
    uint32_t ifftFlagR,
    uint32_t bitReverseFlag)
{
                                            
    arm_status status = ARM_MATH_SUCCESS;

                                         
    S->fftLenReal = (uint16_t) fftLenReal;

                                                      
    S->pTwiddleAReal = (q15_t *) realCoefAQ15;

                                                      
    S->pTwiddleBReal = (q15_t *) realCoefBQ15;

                                                             
    S->ifftFlagR = (uint8_t) ifftFlagR;

                                                                  
    S->bitReverseFlagR = (uint8_t) bitReverseFlag;

                                                                      
    switch (S->fftLenReal)
    {
#if !defined(ARM_DSP_CONFIG_TABLES) || defined(ARM_ALL_FFT_TABLES) || (defined(ARM_TABLE_TWIDDLECOEF_Q15_4096) && defined(ARM_TABLE_BITREVIDX_FXT_4096))
    case 8192U:
        S->twidCoefRModifier = 1U;
        S->pCfft = &arm_cfft_sR_q15_len4096;
        break;
#endif
#if !defined(ARM_DSP_CONFIG_TABLES) || defined(ARM_ALL_FFT_TABLES) || (defined(ARM_TABLE_TWIDDLECOEF_Q15_2048) && defined(ARM_TABLE_BITREVIDX_FXT_2048))
    case 4096U:
        S->twidCoefRModifier = 2U;
        S->pCfft = &arm_cfft_sR_q15_len2048;
        break;
#endif
#if !defined(ARM_DSP_CONFIG_TABLES) || defined(ARM_ALL_FFT_TABLES) || (defined(ARM_TABLE_TWIDDLECOEF_Q15_1024) && defined(ARM_TABLE_BITREVIDX_FXT_1024))
    case 2048U:
        S->twidCoefRModifier = 4U;
        S->pCfft = &arm_cfft_sR_q15_len1024;
        break;
#endif 
#if !defined(ARM_DSP_CONFIG_TABLES) || defined(ARM_ALL_FFT_TABLES) || (defined(ARM_TABLE_TWIDDLECOEF_Q15_512) && defined(ARM_TABLE_BITREVIDX_FXT_512))
    case 1024U:
        S->twidCoefRModifier = 8U;
        S->pCfft = &arm_cfft_sR_q15_len512;
        break;
#endif 
#if !defined(ARM_DSP_CONFIG_TABLES) || defined(ARM_ALL_FFT_TABLES) || (defined(ARM_TABLE_TWIDDLECOEF_Q15_256) && defined(ARM_TABLE_BITREVIDX_FXT_256))
    case 512U:
        S->twidCoefRModifier = 16U;
        S->pCfft = &arm_cfft_sR_q15_len256;
        break;
#endif
#if !defined(ARM_DSP_CONFIG_TABLES) || defined(ARM_ALL_FFT_TABLES) || (defined(ARM_TABLE_TWIDDLECOEF_Q15_128) && defined(ARM_TABLE_BITREVIDX_FXT_128))
    case 256U:
        S->twidCoefRModifier = 32U;
        S->pCfft = &arm_cfft_sR_q15_len128;
        break;
#endif
#if !defined(ARM_DSP_CONFIG_TABLES) || defined(ARM_ALL_FFT_TABLES) || (defined(ARM_TABLE_TWIDDLECOEF_Q15_64) && defined(ARM_TABLE_BITREVIDX_FXT_64))
    case 128U:
        S->twidCoefRModifier = 64U;
        S->pCfft = &arm_cfft_sR_q15_len64;
        break;
#endif 
#if !defined(ARM_DSP_CONFIG_TABLES) || defined(ARM_ALL_FFT_TABLES) || (defined(ARM_TABLE_TWIDDLECOEF_Q15_32) && defined(ARM_TABLE_BITREVIDX_FXT_32))
    case 64U:
        S->twidCoefRModifier = 128U;
        S->pCfft = &arm_cfft_sR_q15_len32;
        break;
#endif 
#if !defined(ARM_DSP_CONFIG_TABLES) || defined(ARM_ALL_FFT_TABLES) || (defined(ARM_TABLE_TWIDDLECOEF_Q15_16) && defined(ARM_TABLE_BITREVIDX_FXT_16))
    case 32U:
        S->twidCoefRModifier = 256U;
        S->pCfft = &arm_cfft_sR_q15_len16;
        break;
#endif
    default:
                                                                      
        status = ARM_MATH_ARGUMENT_ERROR;
        break;
    }

                                                 
    return (status);
}

   
                         
   
