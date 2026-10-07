                                                                         
                                  
                               
                                         
  
                               
                       
  
                                   
                                                                          
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

   
                        
   

   
                  
    
   

   
                                          
                                                                                                       
                                                           
                                 
                                                                           
                                                                                              
   

arm_status arm_sqrt_q31(
  q31_t in,
  q31_t * pOut)
{
  q31_t bits_val1;
  q31_t number, temp1, var1, signBits1, half;
  float32_t temp_float1;
  union
  {
    q31_t fracval;
    float32_t floatval;
  } tempconv;

  number = in;

                                                                    
  if (number > 0)
  {
    signBits1 = __CLZ(number) - 1;

                                          
    if ((signBits1 % 2) == 0)
    {
      number = number << signBits1;
    }
    else
    {
      number = number << (signBits1 - 1);
    }

                                            
    half = number >> 1;
                                        
    temp1 = number;

                          
    temp_float1 = number * 4.6566128731e-010f;
                          
    tempconv.floatval = temp_float1;
    bits_val1 = tempconv.fracval;
                                                                               
    bits_val1 = 0x5f3759df - (bits_val1 >> 1);                           
                        
    tempconv.fracval = bits_val1;
    temp_float1 = tempconv.floatval;
                                   
    var1 = (q31_t) (temp_float1 * 1073741824);

                       
    var1 = ((q31_t) ((q63_t) var1 * (0x30000000 -
                                     ((q31_t)
                                      ((((q31_t)
                                         (((q63_t) var1 * var1) >> 31)) *
                                        (q63_t) half) >> 31))) >> 31)) << 2;
                       
    var1 = ((q31_t) ((q63_t) var1 * (0x30000000 -
                                     ((q31_t)
                                      ((((q31_t)
                                         (((q63_t) var1 * var1) >> 31)) *
                                        (q63_t) half) >> 31))) >> 31)) << 2;
                       
    var1 = ((q31_t) ((q63_t) var1 * (0x30000000 -
                                     ((q31_t)
                                      ((((q31_t)
                                         (((q63_t) var1 * var1) >> 31)) *
                                        (q63_t) half) >> 31))) >> 31)) << 2;

                                                                  
    var1 = ((q31_t) (((q63_t) temp1 * var1) >> 31)) << 1;

                                           
    if ((signBits1 % 2) == 0)
    {
      var1 = var1 >> (signBits1 / 2);
    }
    else
    {
      var1 = var1 >> ((signBits1 - 1) / 2);
    }
    *pOut = var1;

    return (ARM_MATH_SUCCESS);
  }
                                                                                   
  else
  {
    *pOut = 0;

    return (ARM_MATH_ARGUMENT_ERROR);
  }
}

   
                      
   
