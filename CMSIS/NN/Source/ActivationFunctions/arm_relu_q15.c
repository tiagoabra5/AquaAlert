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
#include "arm_nnfunctions.h"

   
                    
   

   
                   
     
   

     
                             
                                                  
                                                    
                  
     
             
    
                                           
    
     

void arm_relu_q15(q15_t * data, uint16_t size)
{

#if defined (ARM_MATH_DSP)
                                                            

    uint16_t  i = size >> 1;
    q15_t    *pIn = data;
    q15_t    *pOut = data;
    q31_t     in;
    q31_t     buf;
    q31_t     mask;

    while (i)
    {
        in = *__SIMD32(pIn)++;

                                   
        buf = __ROR(in & 0x80008000, 15);

                                                        
        mask = __QSUB16(0x00000000, buf);

        *__SIMD32(pOut)++ = in & (~mask);
        i--;
    }

    if (size & 0x1)
    {
        if (*pIn < 0)
        {
            *pIn = 0;
        }
        pIn++;
    }
#else
                                                                                        
    uint16_t  i;

    for (i = 0; i < size; i++)
    {
        if (data[i] < 0)
            data[i] = 0;
    }

#endif                                            

}

   
                       
   
