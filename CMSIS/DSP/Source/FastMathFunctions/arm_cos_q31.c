                                                                         
                                  
                              
                                                       
  
                               
                       
  
                                   
                                                                          
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

   
                        
   

   
                 
    
   

   
                                                                                      
                                                 
                       

                                                                                                        
   

q31_t arm_cos_q31(
  q31_t x)
{
  q31_t cosVal;                                                                         
  int32_t index;                                                     
  q31_t a, b;                                                                   
  q31_t fract;                                                                               

                                          
  x = (uint32_t)x + 0x20000000;
  if (x < 0)
  {                                                              
    x = (uint32_t)x + 0x80000000;
  }

                                   
  index = (uint32_t)x >> FAST_MATH_Q31_SHIFT;

                                       
  fract = (x - (index << FAST_MATH_Q31_SHIFT)) << 9;

                                                                 
  a = sinTable_q31[index];
  b = sinTable_q31[index+1];

                                    
  cosVal = (q63_t) (0x80000000 - fract) * a >> 32;
  cosVal = (q31_t) ((((q63_t) cosVal << 32) + ((q63_t) fract * b)) >> 32);

                           
  return (cosVal << 1);
}

   
                     
   
