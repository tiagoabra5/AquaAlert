                                                                         
                                  
                                    
                                                             
  
                               
                       
  
                                   
                                                                          
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

   
                     
   

   
                        
    
   

   
                                                                
                                                                            
                                                                            
                                                                            
                                              
                                                          
                                              
                                 
                                                                        
                                                                                                      

                                   
                                                                                                                           
                                                                                                               

                                                          
   

arm_status arm_dct4_init_q15(
  arm_dct4_instance_q15 * S,
  arm_rfft_instance_q15 * S_RFFT,
  arm_cfft_radix4_instance_q15 * S_CFFT,
  uint16_t N,
  uint16_t Nby2,
  q15_t normalize)
{
                                          
  arm_status status = ARM_MATH_SUCCESS;

                                  
  S->N = N;

                                          
  S->Nby2 = Nby2;

                                              
  S->normalize = normalize;

                                    
  S->pRfft = S_RFFT;

                                       
  S->pCfft = S_CFFT;

  switch (N)
  {
  #if !defined(ARM_DSP_CONFIG_TABLES) || defined(ARM_ALL_FFT_TABLES) || defined(ARM_TABLE_DCT4_Q15_8192)
                                              
  case 8192U:
    S->pTwiddle = WeightsQ15_8192;
    S->pCosFactor = cos_factorsQ15_8192;
    break;
  #endif

  #if !defined(ARM_DSP_CONFIG_TABLES) || defined(ARM_ALL_FFT_TABLES) || defined(ARM_TABLE_DCT4_Q15_2048)
  case 2048U:
    S->pTwiddle = WeightsQ15_2048;
    S->pCosFactor = cos_factorsQ15_2048;
    break;
  #endif

  #if !defined(ARM_DSP_CONFIG_TABLES) || defined(ARM_ALL_FFT_TABLES) || defined(ARM_TABLE_DCT4_Q15_512)
  case 512U:
    S->pTwiddle = WeightsQ15_512;
    S->pCosFactor = cos_factorsQ15_512;
    break;
  #endif 

  #if !defined(ARM_DSP_CONFIG_TABLES) || defined(ARM_ALL_FFT_TABLES) || defined(ARM_TABLE_DCT4_Q15_128)
  case 128U:
    S->pTwiddle = WeightsQ15_128;
    S->pCosFactor = cos_factorsQ15_128;
    break;
  #endif 

  default:
    status = ARM_MATH_ARGUMENT_ERROR;
  }

                                 
  arm_rfft_init_q15(S->pRfft, S->N, 0U, 1U);

                                               
  return (status);
}

   
                            
   
