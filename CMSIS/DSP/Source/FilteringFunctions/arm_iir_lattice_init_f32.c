                                                                         
                                  
                                           
                                                                          
  
                               
                       
  
                                   
                                                                          
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

   
                       
   

   
                         
    
   

   
                                                                                   
                                                                                             
                                                          
                                                                                                      
                                                                                                    
                                                                                               
                                                        
                     
   

void arm_iir_lattice_init_f32(
  arm_iir_lattice_instance_f32 * S,
  uint16_t numStages,
  float32_t * pkCoeffs,
  float32_t * pvCoeffs,
  float32_t * pState,
  uint32_t blockSize)
{
                          
  S->numStages = numStages;

                                             
  S->pkCoeffs = pkCoeffs;

                                         
  S->pvCoeffs = pvCoeffs;

                                                                   
  memset(pState, 0, (numStages + blockSize) * sizeof(float32_t));

                            
  S->pState = pState;
}

   
                             
   
