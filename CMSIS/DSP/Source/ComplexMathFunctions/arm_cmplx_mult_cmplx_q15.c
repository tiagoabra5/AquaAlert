                                                                         
                                  
                                           
                                                      
  
                               
                       
  
                                   
                                                                          
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

   
                         
   

   
                              
    
   

   
                                                       
                                                         
                                                          
                                                    
                                                             
                     

                                              
                                                                                                                         
   

void arm_cmplx_mult_cmplx_q15(
  const q15_t * pSrcA,
  const q15_t * pSrcB,
        q15_t * pDst,
        uint32_t numSamples)
{
        uint32_t blkCnt;                                                 
        q15_t a, b, c, d;                                                       

#if defined (ARM_MATH_LOOPUNROLL)

                                                   
  blkCnt = numSamples >> 2U;

  while (blkCnt > 0U)
  {
                                                                               
                                                                               

    a = *pSrcA++;
    b = *pSrcA++;
    c = *pSrcB++;
    d = *pSrcB++;
                                                            
    *pDst++ = (q15_t) ( (((q31_t) a * c) >> 17) - (((q31_t) b * d) >> 17) );
    *pDst++ = (q15_t) ( (((q31_t) a * d) >> 17) + (((q31_t) b * c) >> 17) );

    a = *pSrcA++;
    b = *pSrcA++;
    c = *pSrcB++;
    d = *pSrcB++;
    *pDst++ = (q15_t) ( (((q31_t) a * c) >> 17) - (((q31_t) b * d) >> 17) );
    *pDst++ = (q15_t) ( (((q31_t) a * d) >> 17) + (((q31_t) b * c) >> 17) );

    a = *pSrcA++;
    b = *pSrcA++;
    c = *pSrcB++;
    d = *pSrcB++;
    *pDst++ = (q15_t) ( (((q31_t) a * c) >> 17) - (((q31_t) b * d) >> 17) );
    *pDst++ = (q15_t) ( (((q31_t) a * d) >> 17) + (((q31_t) b * c) >> 17) );

    a = *pSrcA++;
    b = *pSrcA++;
    c = *pSrcB++;
    d = *pSrcB++;
    *pDst++ = (q15_t) ( (((q31_t) a * c) >> 17) - (((q31_t) b * d) >> 17) );
    *pDst++ = (q15_t) ( (((q31_t) a * d) >> 17) + (((q31_t) b * c) >> 17) );

                                
    blkCnt--;
  }

                                                 
  blkCnt = numSamples % 0x4U;

#else

                                                
  blkCnt = numSamples;

#endif                                        

  while (blkCnt > 0U)
  {
                                                                               
                                                                               

    a = *pSrcA++;
    b = *pSrcA++;
    c = *pSrcB++;
    d = *pSrcB++;

                                                            
    *pDst++ = (q15_t) ( (((q31_t) a * c) >> 17) - (((q31_t) b * d) >> 17) );
    *pDst++ = (q15_t) ( (((q31_t) a * d) >> 17) + (((q31_t) b * c) >> 17) );

                                
    blkCnt--;
  }

}

   
                                  
   
