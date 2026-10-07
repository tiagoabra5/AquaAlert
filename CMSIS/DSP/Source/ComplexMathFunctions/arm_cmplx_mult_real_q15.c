                                                                         
                                  
                                          
                                                   
  
                               
                       
  
                                   
                                                                          
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

   
                         
   

   
                             
    
   

   
                                                    
                                                           
                                                        
                                                            
                                                             
                     

                                              
                                                           
                                                                                            
   

void arm_cmplx_mult_real_q15(
  const q15_t * pSrcCmplx,
  const q15_t * pSrcReal,
        q15_t * pCmplxDst,
        uint32_t numSamples)
{
        uint32_t blkCnt;                                                 
        q15_t in;                                                              

#if defined (ARM_MATH_LOOPUNROLL)

#if defined (ARM_MATH_DSP)
        q31_t inA1, inA2;                                                                          
        q31_t inB1;                                                                                
        q15_t out1, out2, out3, out4;                                                               
        q31_t mul1, mul2, mul3, mul4;                                                                     
#endif

                                                   
  blkCnt = numSamples >> 2U;

  while (blkCnt > 0U)
  {
                                             
                                             

#if defined (ARM_MATH_DSP)
                                                                                  
    inA1 = read_q15x2_ia ((q15_t **) &pSrcCmplx);
    inA2 = read_q15x2_ia ((q15_t **) &pSrcCmplx);
                                                             
    inB1 = read_q15x2_ia ((q15_t **) &pSrcReal);

                                                   
#ifndef ARM_MATH_BIG_ENDIAN
    mul1 = (q31_t) ((q15_t) (inA1)       * (q15_t) (inB1));
    mul2 = (q31_t) ((q15_t) (inA1 >> 16) * (q15_t) (inB1));
    mul3 = (q31_t) ((q15_t) (inA2)       * (q15_t) (inB1 >> 16));
    mul4 = (q31_t) ((q15_t) (inA2 >> 16) * (q15_t) (inB1 >> 16));
#else
    mul2 = (q31_t) ((q15_t) (inA1 >> 16) * (q15_t) (inB1 >> 16));
    mul1 = (q31_t) ((q15_t) inA1         * (q15_t) (inB1 >> 16));
    mul4 = (q31_t) ((q15_t) (inA2 >> 16) * (q15_t) inB1);
    mul3 = (q31_t) ((q15_t) inA2         * (q15_t) inB1);
#endif                                  

                             
    out1 = (q15_t) __SSAT(mul1 >> 15U, 16);
    out2 = (q15_t) __SSAT(mul2 >> 15U, 16);
    out3 = (q15_t) __SSAT(mul3 >> 15U, 16);
    out4 = (q15_t) __SSAT(mul4 >> 15U, 16);

                                                                       
    write_q15x2_ia (&pCmplxDst, __PKHBT(out1, out2, 16));
    write_q15x2_ia (&pCmplxDst, __PKHBT(out3, out4, 16));

    inA1 = read_q15x2_ia ((q15_t **) &pSrcCmplx);
    inA2 = read_q15x2_ia ((q15_t **) &pSrcCmplx);
    inB1 = read_q15x2_ia ((q15_t **) &pSrcReal);

#ifndef ARM_MATH_BIG_ENDIAN
    mul1 = (q31_t) ((q15_t) (inA1)       * (q15_t) (inB1));
    mul2 = (q31_t) ((q15_t) (inA1 >> 16) * (q15_t) (inB1));
    mul3 = (q31_t) ((q15_t) (inA2)       * (q15_t) (inB1 >> 16));
    mul4 = (q31_t) ((q15_t) (inA2 >> 16) * (q15_t) (inB1 >> 16));
#else
    mul2 = (q31_t) ((q15_t) (inA1 >> 16) * (q15_t) (inB1 >> 16));
    mul1 = (q31_t) ((q15_t) inA1         * (q15_t) (inB1 >> 16));
    mul4 = (q31_t) ((q15_t) (inA2 >> 16) * (q15_t) inB1);
    mul3 = (q31_t) ((q15_t) inA2 * (q15_t) inB1);
#endif                                  

    out1 = (q15_t) __SSAT(mul1 >> 15U, 16);
    out2 = (q15_t) __SSAT(mul2 >> 15U, 16);
    out3 = (q15_t) __SSAT(mul3 >> 15U, 16);
    out4 = (q15_t) __SSAT(mul4 >> 15U, 16);

    write_q15x2_ia (&pCmplxDst, __PKHBT(out1, out2, 16));
    write_q15x2_ia (&pCmplxDst, __PKHBT(out3, out4, 16));
#else
    in = *pSrcReal++;
    *pCmplxDst++ = (q15_t) __SSAT((((q31_t) *pSrcCmplx++ * in) >> 15), 16);
    *pCmplxDst++ = (q15_t) __SSAT((((q31_t) *pSrcCmplx++ * in) >> 15), 16);

    in = *pSrcReal++;
    *pCmplxDst++ = (q15_t) __SSAT((((q31_t) *pSrcCmplx++ * in) >> 15), 16);
    *pCmplxDst++ = (q15_t) __SSAT((((q31_t) *pSrcCmplx++ * in) >> 15), 16);

    in = *pSrcReal++;
    *pCmplxDst++ = (q15_t) __SSAT((((q31_t) *pSrcCmplx++ * in) >> 15), 16);
    *pCmplxDst++ = (q15_t) __SSAT((((q31_t) *pSrcCmplx++ * in) >> 15), 16);

    in = *pSrcReal++;
    *pCmplxDst++ = (q15_t) __SSAT((((q31_t) *pSrcCmplx++ * in) >> 15), 16);
    *pCmplxDst++ = (q15_t) __SSAT((((q31_t) *pSrcCmplx++ * in) >> 15), 16);
#endif

                                
    blkCnt--;
  }

                                                 
  blkCnt = numSamples % 0x4U;

#else

                                                
  blkCnt = numSamples;

#endif                                        

  while (blkCnt > 0U)
  {
                                             
                                             

    in = *pSrcReal++;
                                                     
    *pCmplxDst++ = (q15_t) __SSAT((((q31_t) *pSrcCmplx++ * in) >> 15), 16);
    *pCmplxDst++ = (q15_t) __SSAT((((q31_t) *pSrcCmplx++ * in) >> 15), 16);

                                
    blkCnt--;
  }

}

   
                                 
   
