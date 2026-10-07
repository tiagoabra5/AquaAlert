                                                                         
                                  
                                   
                                                       
  
                               
                       
  
                                   
                                                                          
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

   
                       
   

   
                 
    
   

   
                                                                
                                                                                  
                                                                                                                   
                                                                     
                                                       
                                                                 
                                 
                                                                        
                                                                                                                   

                        
                                                                                                                 
       
                                                           
        
                                                                                              
                                                                                                                                    
                                                                                                  
       
                      
        
                                                                       
       
                          
        
                                                             
       
                 
        
                                                                       
       
                        
        
                                                                              
                                                                                                                                                                                                                                                                                                                           
   

arm_status arm_fir_init_q15(
        arm_fir_instance_q15 * S,
        uint16_t numTaps,
  const q15_t * pCoeffs,
        q15_t * pState,
        uint32_t blockSize)
{
  arm_status status;

#if defined (ARM_MATH_DSP)

                                                                                   
  if (numTaps & 0x1U)
  {
    status = ARM_MATH_ARGUMENT_ERROR;
  }
  else
  {
                            
    S->numTaps = numTaps;

                                    
    S->pCoeffs = pCoeffs;

                                                                            
    memset(pState, 0, (numTaps + (blockSize)) * sizeof(q15_t));

                              
    S->pState = pState;

    status = ARM_MATH_SUCCESS;
  }

  return (status);

#else

                          
  S->numTaps = numTaps;

                                  
  S->pCoeffs = pCoeffs;

                                                                        
  memset(pState, 0, (numTaps + (blockSize - 1U)) * sizeof(q15_t));

                            
  S->pState = pState;

  status = ARM_MATH_SUCCESS;

  return (status);

#endif                                 

}

   
                     
   
