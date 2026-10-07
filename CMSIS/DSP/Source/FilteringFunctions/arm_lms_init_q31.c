                                                                         
                                  
                                   
                                                       
  
                               
                       
  
                                   
                                                                          
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

   
                       
   

   
                 
    
   

   
                                                            
                                                                                 
                                                         
                                                        
                                                  
                                                                              
                                                        
                                                             
                     

                        
                                                                                                                 
       
                                                          
        
                                                                                                     
                                                                                                             
                                                                                                        
                                              
   

void arm_lms_init_q31(
  arm_lms_instance_q31 * S,
  uint16_t numTaps,
  q31_t * pCoeffs,
  q31_t * pState,
  q31_t mu,
  uint32_t blockSize,
  uint32_t postShift)
{
                          
  S->numTaps = numTaps;

                                  
  S->pCoeffs = pCoeffs;

                                                                     
  memset(pState, 0, (numTaps + (blockSize - 1U)) * sizeof(q31_t));

                            
  S->pState = pState;

                              
  S->mu = mu;

                                            
  S->postShift = postShift;
}

   
                     
   
