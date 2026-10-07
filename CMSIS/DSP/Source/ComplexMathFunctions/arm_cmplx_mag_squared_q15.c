                                                                         
                                  
                                            
                                              
  
                               
                       
  
                                   
                                                                          
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

   
                         
   

   
                               
    
   

   
                                               
                                                   
                                                    
                                                             
                     

                                              
                                                                                                                         
   

void arm_cmplx_mag_squared_q15(
  const q15_t * pSrc,
        q15_t * pDst,
        uint32_t numSamples)
{
        uint32_t blkCnt;                                                 

#if defined (ARM_MATH_DSP)
        q31_t in;
        q31_t acc0;                                                      
#else
        q15_t real, imag;                                                             
        q31_t acc0, acc1;                                                
#endif

#if defined (ARM_MATH_LOOPUNROLL)

                                                   
  blkCnt = numSamples >> 2U;

  while (blkCnt > 0U)
  {
                                            

#if defined (ARM_MATH_DSP)
    in = read_q15x2_ia ((q15_t **) &pSrc);
    acc0 = __SMUAD(in, in);
                                                            
    *pDst++ = (q15_t) (acc0 >> 17);

    in = read_q15x2_ia ((q15_t **) &pSrc);
    acc0 = __SMUAD(in, in);
    *pDst++ = (q15_t) (acc0 >> 17);

    in = read_q15x2_ia ((q15_t **) &pSrc);
    acc0 = __SMUAD(in, in);
    *pDst++ = (q15_t) (acc0 >> 17);

    in = read_q15x2_ia ((q15_t **) &pSrc);
    acc0 = __SMUAD(in, in);
    *pDst++ = (q15_t) (acc0 >> 17);
#else
    real = *pSrc++;
    imag = *pSrc++;
    acc0 = ((q31_t) real * real);
    acc1 = ((q31_t) imag * imag);
                                                            
    *pDst++ = (q15_t) (((q63_t) acc0 + acc1) >> 17);

    real = *pSrc++;
    imag = *pSrc++;
    acc0 = ((q31_t) real * real);
    acc1 = ((q31_t) imag * imag);
    *pDst++ = (q15_t) (((q63_t) acc0 + acc1) >> 17);

    real = *pSrc++;
    imag = *pSrc++;
    acc0 = ((q31_t) real * real);
    acc1 = ((q31_t) imag * imag);
    *pDst++ = (q15_t) (((q63_t) acc0 + acc1) >> 17);

    real = *pSrc++;
    imag = *pSrc++;
    acc0 = ((q31_t) real * real);
    acc1 = ((q31_t) imag * imag);
    *pDst++ = (q15_t) (((q63_t) acc0 + acc1) >> 17);
#endif                                 

                                
    blkCnt--;
  }

                                                 
  blkCnt = numSamples % 0x4U;

#else

                                                
  blkCnt = numSamples;

#endif                                        

  while (blkCnt > 0U)
  {
                                            

#if defined (ARM_MATH_DSP)
    in = read_q15x2_ia ((q15_t **) &pSrc);
    acc0 = __SMUAD(in, in);

                                                            
    *pDst++ = (q15_t) (acc0 >> 17);
#else
    real = *pSrc++;
    imag = *pSrc++;
    acc0 = ((q31_t) real * real);
    acc1 = ((q31_t) imag * imag);

                                                            
    *pDst++ = (q15_t) (((q63_t) acc0 + acc1) >> 17);
#endif

                                
    blkCnt--;
  }

}

   
                                   
   
