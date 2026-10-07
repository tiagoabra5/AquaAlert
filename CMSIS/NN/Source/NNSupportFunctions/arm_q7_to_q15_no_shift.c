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

                                                                         
                                 
                                         
                                                                                        
  
                                 
                        
  
                                    
  
                                                                          

#include "arm_nnsupportfunctions.h"

       
                            
   

       
                                 
         
   

       
                                                                                  
                                                           
                                                            
                                                            
                    
      
                        
      
                                                       
     
            
                                                        
             
     
   

void arm_q7_to_q15_no_shift(const q7_t * pSrc, q15_t * pDst, uint32_t blockSize)
{
    const q7_t *pIn = pSrc;                      
    uint32_t  blkCnt;                             

#ifndef ARM_MATH_CM0_FAMILY
    q31_t     in;
    q31_t     in1, in2;
    q31_t     out1, out2;

                                                        

                       
    blkCnt = blockSize >> 2u;

                                                                                          
                                                                     
    while (blkCnt > 0u)
    {
                                
                                                                                         
        in = *__SIMD32(pIn)++;

                                                                         
        in1 = __SXTB16(__ROR(in, 8));

                                                             
        in2 = __SXTB16(in);

#ifndef ARM_MATH_BIG_ENDIAN

        out2 = __PKHTB(in1, in2, 16);
        out1 = __PKHBT(in2, in1, 16);

#else

        out1 = __PKHTB(in1, in2, 16);
        out2 = __PKHBT(in2, in1, 16);

#endif

        *__SIMD32(pDst)++ = out1;
        *__SIMD32(pDst)++ = out2;

                                        
        blkCnt--;
    }

                                                                                              
                                     
    blkCnt = blockSize % 0x4u;

#else

                                          

                                              
    blkCnt = blockSize;

#endif                                                           

    while (blkCnt > 0u)
    {
                                
                                                                                         
        *pDst++ = (q15_t) * pIn++;

                                        
        blkCnt--;
    }

}

       
                                    
   
