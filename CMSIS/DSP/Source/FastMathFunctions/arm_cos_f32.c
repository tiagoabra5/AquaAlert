                                                                         
                                  
                              
                                                                  
  
                               
                       
  
                                   
                                                                          
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

   
                        
   

   
                      

                                                                                
                                                             
                                          
                                                                 
                                                            
                                                                             
                                  

                                                                                                  
                     
                                                    
                                                                
                                                                    

       
       
                      
                        
        
   

   
                 
    
   

   
                                                                                                 
                                          
                       
   

float32_t arm_cos_f32(
  float32_t x)
{
  float32_t cosVal, fract, in;                                                          
  uint16_t index;                                                    
  float32_t a, b;                                                               
  int32_t n;
  float32_t findex;

                             
                                                                                                           
  in = x * 0.159154943092f + 0.25f;

                                           
  n = (int32_t) in;

                                              
  if (in < 0.0f)
  {
    n--;
  }

                                
  in = in - (float32_t) n;

                                         
  findex = (float32_t)FAST_MATH_TABLE_SIZE * in;
  index = (uint16_t)findex;

                                                                     
  if (index >= FAST_MATH_TABLE_SIZE) {
    index = 0;
    findex -= (float32_t)FAST_MATH_TABLE_SIZE;
  }

                                    
  fract = findex - (float32_t) index;

                                                                 
  a = sinTable_f32[index];
  b = sinTable_f32[index+1];

                                    
  cosVal = (1.0f - fract) * a + fract * b;

                           
  return (cosVal);
}

   
                     
   
