                                                                         
                                  
                                     
                                      
  
                               
                       
  
                                   
                                                                          
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

   
                         
   

   
                        
    
   

   
                                       
                                                       
                                                        
                                                             
                     

                                              
                                                           
                                                                                                         
   

void arm_cmplx_conj_q15(
  const q15_t * pSrc,
        q15_t * pDst,
        uint32_t numSamples)
{
        uint32_t blkCnt;                                                 
        q31_t in1;                                                                   

#if defined (ARM_MATH_LOOPUNROLL) && defined (ARM_MATH_DSP)
        q31_t in2, in3, in4;                                                          
#endif


#if defined (ARM_MATH_LOOPUNROLL)

                                                   
  blkCnt = numSamples >> 2U;

  while (blkCnt > 0U)
  {
                                        

                                                                             

    #if defined (ARM_MATH_DSP)
    in1 = read_q15x2_ia ((q15_t **) &pSrc);
    in2 = read_q15x2_ia ((q15_t **) &pSrc);
    in3 = read_q15x2_ia ((q15_t **) &pSrc);
    in4 = read_q15x2_ia ((q15_t **) &pSrc);

#ifndef ARM_MATH_BIG_ENDIAN
    in1 = __QASX(0, in1);
    in2 = __QASX(0, in2);
    in3 = __QASX(0, in3);
    in4 = __QASX(0, in4);
#else
    in1 = __QSAX(0, in1);
    in2 = __QSAX(0, in2);
    in3 = __QSAX(0, in3);
    in4 = __QSAX(0, in4);
#endif                                  

    in1 = ((uint32_t) in1 >> 16) | ((uint32_t) in1 << 16);
    in2 = ((uint32_t) in2 >> 16) | ((uint32_t) in2 << 16);
    in3 = ((uint32_t) in3 >> 16) | ((uint32_t) in3 << 16);
    in4 = ((uint32_t) in4 >> 16) | ((uint32_t) in4 << 16);

    write_q15x2_ia (&pDst, in1);
    write_q15x2_ia (&pDst, in2);
    write_q15x2_ia (&pDst, in3);
    write_q15x2_ia (&pDst, in4);
#else
    *pDst++ =  *pSrc++;
    in1 = *pSrc++;
    *pDst++ = (in1 == (q15_t) 0x8000) ? (q15_t) 0x7fff : -in1;

    *pDst++ =  *pSrc++;
    in1 = *pSrc++;
    *pDst++ = (in1 == (q15_t) 0x8000) ? (q15_t) 0x7fff : -in1;

    *pDst++ =  *pSrc++;
    in1 = *pSrc++;
    *pDst++ = (in1 == (q15_t) 0x8000) ? (q15_t) 0x7fff : -in1;

    *pDst++ =  *pSrc++;
    in1 = *pSrc++;
    *pDst++ = (in1 == (q15_t) 0x8000) ? (q15_t) 0x7fff : -in1;

#endif                                 

                                
    blkCnt--;
  }

                                                 
  blkCnt = numSamples % 0x4U;

#else

                                                
  blkCnt = numSamples;

#endif                                        

  while (blkCnt > 0U)
  {
                                        

                                                                             
    *pDst++ =  *pSrc++;
    in1 = *pSrc++;
#if defined (ARM_MATH_DSP)
    *pDst++ = __SSAT(-in1, 16);
#else
    *pDst++ = (in1 == (q15_t) 0x8000) ? (q15_t) 0x7fff : -in1;
#endif

                                
    blkCnt--;
  }

}

   
                            
   
