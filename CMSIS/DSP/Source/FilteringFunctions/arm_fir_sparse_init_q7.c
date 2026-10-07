                                                                         
                                  
                                         
                                                             
  
                               
                       
  
                                   
                                                                          
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

   
                       
   

   
                        
    
   

   
                                                                      
                                                                                
                                                                        
                                                                      
                                                      
                                                               
                                                         
                                                                              
                     

                        
                                                                                                          
                                                                                               
                                                                                 
                                                              
                                                
                                                                                                
   

void arm_fir_sparse_init_q7(
        arm_fir_sparse_instance_q7 * S,
        uint16_t numTaps,
  const q7_t * pCoeffs,
        q7_t * pState,
        int32_t * pTapDelay,
        uint16_t maxDelay,
        uint32_t blockSize)
{
                          
  S->numTaps = numTaps;

                                  
  S->pCoeffs = pCoeffs;

                               
  S->pTapDelay = pTapDelay;

                       
  S->maxDelay = maxDelay;

                                 
  S->stateIndex = 0U;

                                                                  
  memset(pState, 0, (maxDelay + blockSize) * sizeof(q7_t));

                            
  S->pState = pState;
}

   
                            
   
