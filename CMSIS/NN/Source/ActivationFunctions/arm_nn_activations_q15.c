/*
 * Copyright (C) 2010-2018 Arm Limited or its affiliates. All rights reserved.
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
#include "arm_nnfunctions.h"

   
                    
   

   
                   
     
   

     
                                                                             
                                                  
                                                    
                                                                                            
                                                              
                  
    
             
     
                                               
    
                                                             
                                                                     
                                                               
     

void arm_nn_activations_direct_q15(q15_t * data, uint16_t size, uint16_t int_width, arm_nn_activation_type type)
{
    uint16_t  i = size;
    q15_t    *pIn = data;
    q15_t    *pOut = data;
    uint16_t  shift_size = 8 + 3 - int_width;
    uint32_t  bit_mask = 0x7FF >> int_width;
    uint32_t  full_frac = bit_mask + 1;
    const q15_t *lookup_table;

    switch (type)
    {
    case ARM_SIGMOID:
        lookup_table = sigmoidTable_q15;
        break;
    case ARM_TANH:
    default:
        lookup_table = tanhTable_q15;
        break;
    }

    while (i)
    {
        q15_t     out;
        q15_t     in = *pIn++;
        q15_t     frac = (uint32_t) in & bit_mask;
        q15_t     value = lookup_table[__USAT(in >> shift_size, 8)];
        q15_t     value2 = lookup_table[__USAT(1 + (in >> shift_size), 8)];

                                                              
        out = ((q31_t) (full_frac - frac) * value + (q31_t) value2 * frac) >> shift_size;

        *pOut++ = out;
        i--;
    }

}

   
                       
   
