                                                                         
                                  
                                           
                                                                                                 
  
                               
                       
  
                                   
                                                                          
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

   
                          
   

   
                        
    
   

   
                                                                
                                                                                                                         
                                                                                     
                                                 
                                                                     
                                                 
                                                 
                                                                                   
                                                               
                                                              
                                 
                                                                        
                                                                                                 

                        
                                                                                                                   
                                                                                         
      
                                                                                                                              
                                                                                                                     
      
                                                                                                                                         
      
                                                                                                              
  

arm_status arm_cfft_radix2_init_q31(
  arm_cfft_radix2_instance_q31 * S,
  uint16_t fftLen,
  uint8_t ifftFlag,
  uint8_t bitReverseFlag)
{
                                          
  arm_status status = ARM_MATH_SUCCESS;

                                  
  S->fftLen = fftLen;

                                                   
  S->pTwiddle = (q31_t *) twiddleCoef_4096_q31;

                                                           
  S->ifftFlag = ifftFlag;

                                                                
  S->bitReverseFlag = bitReverseFlag;

                                                                          
  switch (S->fftLen)
  {
                                                                     
  case 4096U:
                                                     
    S->twidCoefModifier = 1U;
                                                     
    S->bitRevFactor = 1U;
                                                    
    S->pBitRevTable = (uint16_t *) armBitRevTable;
    break;

                                                                     
  case 2048U:
                                                     
    S->twidCoefModifier = 2U;
                                                     
    S->bitRevFactor = 2U;
                                                    
    S->pBitRevTable = (uint16_t *) & armBitRevTable[1];
    break;

                                                                     
  case 1024U:
                                                     
    S->twidCoefModifier = 4U;
                                                     
    S->bitRevFactor = 4U;
                                                    
    S->pBitRevTable = (uint16_t *) & armBitRevTable[3];
    break;

                                                                    
  case 512U:
                                                     
    S->twidCoefModifier = 8U;
                                                     
    S->bitRevFactor = 8U;
                                                    
    S->pBitRevTable = (uint16_t *) & armBitRevTable[7];
    break;

  case 256U:
                                                                    
    S->twidCoefModifier = 16U;
    S->bitRevFactor = 16U;
    S->pBitRevTable = (uint16_t *) & armBitRevTable[15];
    break;

  case 128U:
                                                                    
    S->twidCoefModifier = 32U;
    S->bitRevFactor = 32U;
    S->pBitRevTable = (uint16_t *) & armBitRevTable[31];
    break;

  case 64U:
                                                                   
    S->twidCoefModifier = 64U;
    S->bitRevFactor = 64U;
    S->pBitRevTable = (uint16_t *) & armBitRevTable[63];
    break;

  case 32U:
                                                                   
    S->twidCoefModifier = 128U;
    S->bitRevFactor = 128U;
    S->pBitRevTable = (uint16_t *) & armBitRevTable[127];
    break;

  case 16U:
                                                                   
    S->twidCoefModifier = 256U;
    S->bitRevFactor = 256U;
    S->pBitRevTable = (uint16_t *) & armBitRevTable[255];
    break;


  default:
                                                                 
    status = ARM_MATH_ARGUMENT_ERROR;
    break;
  }

  return (status);
}

   
                            
   
