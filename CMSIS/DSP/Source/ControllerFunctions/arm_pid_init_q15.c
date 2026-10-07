                                                                         
                                  
                                   
                                                        
  
                               
                       
  
                                   
                                                                          
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

   
                 
    
   

   
                                                                 
                                                                               
                               
                                                  
                                           
                     

                        
                                                                                                    
                                                                                                               
                                                                                                         
                                                              
   

void arm_pid_init_q15(
  arm_pid_instance_q15 * S,
  int32_t resetStateFlag)
{

#if defined (ARM_MATH_DSP)

                              
  S->A0 = __QADD16(__QADD16(S->Kp, S->Ki), S->Kd);

                                             

#ifndef  ARM_MATH_BIG_ENDIAN
  S->A1 = __PKHBT(-__QADD16(__QADD16(S->Kd, S->Kd), S->Kp), S->Kd, 16);
#else
  S->A1 = __PKHBT(S->Kd, -__QADD16(__QADD16(S->Kd, S->Kd), S->Kp), 16);
#endif

#else

  q31_t temp;                                                          

                              
  temp = S->Kp + S->Ki + S->Kd;
  S->A0 = (q15_t) __SSAT(temp, 16);

                                             
  temp = -(S->Kd + S->Kd + S->Kp);
  S->A1 = (q15_t) __SSAT(temp, 16);
  S->A2 = S->Kd;

#endif                                 

                                              
  if (resetStateFlag)
  {
                                                                
    memset(S->state, 0, 3U * sizeof(q15_t));
  }

}

   
                     
   
