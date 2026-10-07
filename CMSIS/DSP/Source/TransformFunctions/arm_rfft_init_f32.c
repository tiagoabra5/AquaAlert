                                                                         
                                  
                                    
                                                                    
  
                               
                       
  
                                   
                                                                          
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


   
                     
    
   

   
                                                                           
                                                                                                                                   
                                                                                               
                                                                                               
                                                  
                                                                     
                                                 
                                                 
                                                                                   
                                                               
                                                              
                                 
                                                                        
                                                                                                     

                  
                                                                                               
                                                            
      
                                                                                                                    
                                                                                      
      
                                                                                                                              
                                                                                                                     
      
                                                                       
   

arm_status arm_rfft_init_f32(
  arm_rfft_instance_f32 * S,
  arm_cfft_radix4_instance_f32 * S_CFFT,
  uint32_t fftLenReal,
  uint32_t ifftFlagR,
  uint32_t bitReverseFlag)
{

                                          
  arm_status status = ARM_MATH_SUCCESS;

                                       
  S->fftLenReal = (uint16_t) fftLenReal;

                                          
  S->fftLenBy2 = (uint16_t) fftLenReal / 2U;

                                                    
  S->pTwiddleAReal = (float32_t *) realCoefA;

                                                    
  S->pTwiddleBReal = (float32_t *) realCoefB;

                                                           
  S->ifftFlagR = (uint8_t) ifftFlagR;

                                                                
  S->bitReverseFlagR = (uint8_t) bitReverseFlag;

                                                                            
  switch (S->fftLenReal)
  {
                                   
  case 8192U:
    S->twidCoefRModifier = 1U;
    break;
  case 2048U:
    S->twidCoefRModifier = 4U;
    break;
  case 512U:
    S->twidCoefRModifier = 16U;
    break;
  case 128U:
    S->twidCoefRModifier = 64U;
    break;
  default:
                                                                  
    status = ARM_MATH_ARGUMENT_ERROR;
    break;
  }

                                 
  S->pCfft = S_CFFT;

  if (S->ifftFlagR)
  {
                                                              
    arm_cfft_radix4_init_f32(S->pCfft, S->fftLenBy2, 1U, 0U);
  }
  else
  {
                                                             
    arm_cfft_radix4_init_f32(S->pCfft, S->fftLenBy2, 0U, 0U);
  }

                                               
  return (status);

}

   
                         
   
