                                                                         
                                  
                                           
                                                                                                    
  
                               
                       
  
                                   
                                                                          
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

   
                          
   

   
                        
    
   

   
                                                                           
                                                                                                                         
                                                                                                
                                                 
                                                                     
                                                 
                                                 
                                                                                   
                                                               
                                                              
                                 
                                                                        
                                                                                                 

                        
                                                                                                                   
                                                                                          
      
                                                                                                                              
                                                                                                                     
      
                                                                                                                                         
      
                                                                                                              
  

arm_status arm_cfft_radix2_init_f32(
  arm_cfft_radix2_instance_f32 * S,
  uint16_t fftLen,
  uint8_t ifftFlag,
  uint8_t bitReverseFlag)
{
                                          
  arm_status status = ARM_MATH_SUCCESS;

                                  
  S->fftLen = fftLen;

                                                   
  S->pTwiddle = (float32_t *) twiddleCoef;

                                                           
  S->ifftFlag = ifftFlag;

                                                                
  S->bitReverseFlag = bitReverseFlag;

                                                                            
  switch (S->fftLen)
  {

  case 4096U:
                                                                     

                                                     
    S->twidCoefModifier = 1U;
                                                     
    S->bitRevFactor = 1U;
                                                    
    S->pBitRevTable = (uint16_t *) armBitRevTable;
                                        
    S->onebyfftLen = 0.000244140625;
    break;

  case 2048U:
                                                                     

                                                     
    S->twidCoefModifier = 2U;
                                                     
    S->bitRevFactor = 2U;
                                                    
    S->pBitRevTable = (uint16_t *) & armBitRevTable[1];
                                        
    S->onebyfftLen = 0.00048828125;
    break;

  case 1024U:
                                                                     

                                                     
    S->twidCoefModifier = 4U;
                                                     
    S->bitRevFactor = 4U;
                                                    
    S->pBitRevTable = (uint16_t *) & armBitRevTable[3];
                                        
    S->onebyfftLen = 0.0009765625f;
    break;

  case 512U:
                                                                    

                                                     
    S->twidCoefModifier = 8U;
                                                     
    S->bitRevFactor = 8U;
                                                    
    S->pBitRevTable = (uint16_t *) & armBitRevTable[7];
                                        
    S->onebyfftLen = 0.001953125;
    break;

  case 256U:
                                                                    
    S->twidCoefModifier = 16U;
    S->bitRevFactor = 16U;
    S->pBitRevTable = (uint16_t *) & armBitRevTable[15];
    S->onebyfftLen = 0.00390625f;
    break;

  case 128U:
                                                                    
    S->twidCoefModifier = 32U;
    S->bitRevFactor = 32U;
    S->pBitRevTable = (uint16_t *) & armBitRevTable[31];
    S->onebyfftLen = 0.0078125;
    break;

  case 64U:
                                                                   
    S->twidCoefModifier = 64U;
    S->bitRevFactor = 64U;
    S->pBitRevTable = (uint16_t *) & armBitRevTable[63];
    S->onebyfftLen = 0.015625f;
    break;

  case 32U:
                                                                   
    S->twidCoefModifier = 128U;
    S->bitRevFactor = 128U;
    S->pBitRevTable = (uint16_t *) & armBitRevTable[127];
    S->onebyfftLen = 0.03125;
    break;

  case 16U:
                                                                   
    S->twidCoefModifier = 256U;
    S->bitRevFactor = 256U;
    S->pBitRevTable = (uint16_t *) & armBitRevTable[255];
    S->onebyfftLen = 0.0625f;
    break;


  default:
                                                                 
    status = ARM_MATH_ARGUMENT_ERROR;
    break;
  }

  return (status);
}

   
                            
   
