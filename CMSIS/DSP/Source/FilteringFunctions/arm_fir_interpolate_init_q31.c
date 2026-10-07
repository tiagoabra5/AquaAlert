                                                                         
                                  
                                               
                                                             
  
                               
                       
  
                                   
                                                                          
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

   
                       
   

   
                             
    
   

   
                                                                      
                                                                                      
                                          
                                                                      
                                                                  
                                                     
                                                                      
                                 
                                                                        
                                                                                                                                                   
 
                        
                                                                                                                 
       
                                                                 
        
                                                                                                                               
      
                                                                              
                                                                                              
                                                                                                                                                
   

arm_status arm_fir_interpolate_init_q31(
        arm_fir_interpolate_instance_q31 * S,
        uint8_t L,
        uint16_t numTaps,
  const q31_t * pCoeffs,
        q31_t * pState,
        uint32_t blockSize)
{
  arm_status status;

                                                                        
  if ((numTaps % L) != 0U)
  {
                                             
    status = ARM_MATH_LENGTH_ERROR;
  }
  else
  {
                                    
    S->pCoeffs = pCoeffs;

                                     
    S->L = L;

                                
    S->phaseLength = numTaps / L;

                                                                                     
    memset(pState, 0, (blockSize + ((uint32_t) S->phaseLength - 1U)) * sizeof(q31_t));

                              
    S->pState = pState;

    status = ARM_MATH_SUCCESS;
  }

  return (status);
}

   
                                 
   
