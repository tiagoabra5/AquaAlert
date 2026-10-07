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

   
                    
   

   
                   
     
   

     
                                                                            
                                                  
                                                    
                                                                                            
                                                              
                  
    
             
     
                                               
    
                                                             
                                                                     
                                                               
     

void arm_nn_activations_direct_q7(q7_t * data, uint16_t size, uint16_t int_width, arm_nn_activation_type type)
{
    uint16_t  i = size;
    q7_t     *pIn = data;
    q7_t     *pOut = data;
    q7_t      in;
    q7_t      out;
    uint16_t  shift_size = 3 - int_width;
    const q7_t *lookup_table;
    switch (type)
    {
    case ARM_SIGMOID:
        lookup_table = sigmoidTable_q7;
        break;
    case ARM_TANH:
    default:
        lookup_table = tanhTable_q7;
        break;
    }
    while (i)
    {
        in = *pIn++;
        out = lookup_table[(uint8_t) (in >> shift_size)];
        *pOut++ = out;
        i--;
    }
}

   
                       
   
