                                                                         
                                  
                              
                                       
  
                               
                       
  
                                   
                                                                          
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

   
                    
   

   
                      
    
   

   
                                        
                                                            
                                                             
                                                       
                                                            
                     

                                              
                                                           
                                                                                            
   

void arm_sub_q15(
  const q15_t * pSrcA,
  const q15_t * pSrcB,
        q15_t * pDst,
        uint32_t blockSize)
{
        uint32_t blkCnt;                                                 

#if defined (ARM_MATH_LOOPUNROLL)

#if defined (ARM_MATH_DSP)
  q31_t inA1, inA2;
  q31_t inB1, inB2;
#endif

                                                   
  blkCnt = blockSize >> 2U;

  while (blkCnt > 0U)
  {
                   

#if defined (ARM_MATH_DSP)
                                                       
    inA1 = read_q15x2_ia ((q15_t **) &pSrcA);
    inA2 = read_q15x2_ia ((q15_t **) &pSrcA);
                                                       
    inB1 = read_q15x2_ia ((q15_t **) &pSrcB);
    inB2 = read_q15x2_ia ((q15_t **) &pSrcB);

                                                        
    write_q15x2_ia (&pDst, __QSUB16(inA1, inB1));
    write_q15x2_ia (&pDst, __QSUB16(inA2, inB2));
#else
    *pDst++ = (q15_t) __SSAT(((q31_t) *pSrcA++ - *pSrcB++), 16);
    *pDst++ = (q15_t) __SSAT(((q31_t) *pSrcA++ - *pSrcB++), 16);
    *pDst++ = (q15_t) __SSAT(((q31_t) *pSrcA++ - *pSrcB++), 16);
    *pDst++ = (q15_t) __SSAT(((q31_t) *pSrcA++ - *pSrcB++), 16);
#endif

                                
    blkCnt--;
  }

                                                 
  blkCnt = blockSize % 0x4U;

#else

                                                
  blkCnt = blockSize;

#endif                                        

  while (blkCnt > 0U)
  {
                   

                                                          
#if defined (ARM_MATH_DSP)
    *pDst++ = (q15_t) __QSUB16(*pSrcA++, *pSrcB++);
#else
    *pDst++ = (q15_t) __SSAT(((q31_t) *pSrcA++ - *pSrcB++), 16);
#endif

                                
    blkCnt--;
  }

}

   
                          
   
