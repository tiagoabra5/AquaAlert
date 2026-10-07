                                                                         
                                  
                              
                                          
  
                               
                       
  
                                   
                                                                          
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

   
                    
   

   
                      
    
   

   
                                           
                                                      
                                                       
                                                            
                     

                                              
                                                           
                                                                                                              
   

void arm_abs_q15(
  const q15_t * pSrc,
        q15_t * pDst,
        uint32_t blockSize)
{
        uint32_t blkCnt;                                                 
        q15_t in;                                                                    

#if defined (ARM_MATH_LOOPUNROLL)

                                                   
  blkCnt = blockSize >> 2U;

  while (blkCnt > 0U)
  {
                 

                                                                                                              
    in = *pSrc++;
#if defined (ARM_MATH_DSP)
    *pDst++ = (in > 0) ? in : (q15_t)__QSUB16(0, in);
#else
    *pDst++ = (in > 0) ? in : ((in == (q15_t) 0x8000) ? 0x7fff : -in);
#endif

    in = *pSrc++;
#if defined (ARM_MATH_DSP)
    *pDst++ = (in > 0) ? in : (q15_t)__QSUB16(0, in);
#else
    *pDst++ = (in > 0) ? in : ((in == (q15_t) 0x8000) ? 0x7fff : -in);
#endif

    in = *pSrc++;
#if defined (ARM_MATH_DSP)
    *pDst++ = (in > 0) ? in : (q15_t)__QSUB16(0, in);
#else
    *pDst++ = (in > 0) ? in : ((in == (q15_t) 0x8000) ? 0x7fff : -in);
#endif

    in = *pSrc++;
#if defined (ARM_MATH_DSP)
    *pDst++ = (in > 0) ? in : (q15_t)__QSUB16(0, in);
#else
    *pDst++ = (in > 0) ? in : ((in == (q15_t) 0x8000) ? 0x7fff : -in);
#endif

                                
    blkCnt--;
  }

                                                 
  blkCnt = blockSize % 0x4U;

#else

                                                
  blkCnt = blockSize;

#endif                                        

  while (blkCnt > 0U)
  {
                 

                                                                                                              
    in = *pSrc++;
#if defined (ARM_MATH_DSP)
    *pDst++ = (in > 0) ? in : (q15_t)__QSUB16(0, in);
#else
    *pDst++ = (in > 0) ? in : ((in == (q15_t) 0x8000) ? 0x7fff : -in);
#endif

                                
    blkCnt--;
  }

}

   
                          
   
