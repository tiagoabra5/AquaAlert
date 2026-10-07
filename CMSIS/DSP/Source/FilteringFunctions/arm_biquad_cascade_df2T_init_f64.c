                                                                         
                                  
                                                   
                                                                                                           
  
                               
                       
  
                                   
                                                                          
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

   
                       
   

   
                               
    
   

   
                                                                                                                
                                                                               
                                                                     
                                                              
                                                       
                     

                                               
                                                                                                        
       
                                                             
        
      
                                                                                                        
                                                                                                   
                                                                                                                  
      
                                                                       
                                                                                                
                                                                                                                  
                                                                                         
                                                                                                                         
   

void arm_biquad_cascade_df2T_init_f64(
        arm_biquad_cascade_df2T_instance_f64 * S,
        uint8_t numStages,
        float64_t * pCoeffs,
        float64_t * pState)
{
                            
  S->numStages = numStages;

                                  
  S->pCoeffs = pCoeffs;

                                                           
  memset(pState, 0, (2U * (uint32_t) numStages) * sizeof(float64_t));

                            
  S->pState = pState;
}

   
                                   
   
