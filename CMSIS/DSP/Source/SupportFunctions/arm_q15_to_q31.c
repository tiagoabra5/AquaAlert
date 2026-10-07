                                                                         
                                  
                                 
                                                                      
  
                               
                       
  
                                   
                                                                          
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

   
                       
   

   
                      
    
   

   
                                                                       
                                                          
                                                           
                                                            
                     

                        
                                                                   
       
                                                            
        
   

void arm_q15_to_q31(
  const q15_t * pSrc,
        q31_t * pDst,
        uint32_t blockSize)
{
        uint32_t blkCnt;                                                 
  const q15_t *pIn = pSrc;                                                 

#if defined (ARM_MATH_LOOPUNROLL)
        q31_t in1, in2;
        q31_t out1, out2, out3, out4;
#endif

#if defined (ARM_MATH_LOOPUNROLL)

                                                   
  blkCnt = blockSize >> 2U;

  while (blkCnt > 0U)
  {
                            

                                                                        
    in1 = read_q15x2_ia ((q15_t **) &pIn);
    in2 = read_q15x2_ia ((q15_t **) &pIn);

#ifndef ARM_MATH_BIG_ENDIAN

                                                
    out1 = in1 << 16U;
                                                
    out2 = in1 & 0xFFFF0000;
                                                
    out3 = in2 << 16U;
                                                
    out4 = in2 & 0xFFFF0000;

#else

                                                
    out1 = in1 & 0xFFFF0000;
                                                
    out2 = in1 << 16U;
                                                
    out3 = in2 & 0xFFFF0000;
                                                
    out4 = in2 << 16U;

#endif                                  

    *pDst++ = out1;
    *pDst++ = out2;
    *pDst++ = out3;
    *pDst++ = out4;

                                
    blkCnt--;
  }

                                                 
  blkCnt = blockSize % 0x4U;

#else

                                                
  blkCnt = blockSize;

#endif                                        

  while (blkCnt > 0U)
  {
                             

                                                                        
    *pDst++ = (q31_t) *pIn++ << 16;

                                
    blkCnt--;
  }

}

   
                          
   
