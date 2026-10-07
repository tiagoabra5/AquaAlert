                                                                         
                                  
                                   
                                                        
  
                               
                       
  
                                   
                                                                          
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

   
                 
    
   

   
                                                                 
                                                                               
                               
                                                  
                                           
                     

                        
                                                                                                    
                                                                                                               
                                                                                                         
                                                              
   

void arm_pid_init_q31(
  arm_pid_instance_q31 * S,
  int32_t resetStateFlag)
{

#if defined (ARM_MATH_DSP)

                              
  S->A0 = __QADD(__QADD(S->Kp, S->Ki), S->Kd);

                              
  S->A1 = -__QADD(__QADD(S->Kd, S->Kd), S->Kp);

#else

  q31_t temp;                                                          

                              
  temp = clip_q63_to_q31((q63_t) S->Kp + S->Ki);
  S->A0 = clip_q63_to_q31((q63_t) temp + S->Kd);

                              
  temp = clip_q63_to_q31((q63_t) S->Kd + S->Kd);
  S->A1 = -clip_q63_to_q31((q63_t) temp + S->Kp);

#endif                                 

                              
  S->A2 = S->Kd;

                                              
  if (resetStateFlag)
  {
                                                                
    memset(S->state, 0, 3U * sizeof(q31_t));
  }

}

   
                     
   
