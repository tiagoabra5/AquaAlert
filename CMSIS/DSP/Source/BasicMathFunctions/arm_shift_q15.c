                                                                         
                                  
                                
                                                                                  
  
                               
                       
  
                                   
                                                                          
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

   
                    
   

   
                        
    
   

   
                                                                               
                                                      
                                                                                                                  
                                                       
                                                            
                     

                                              
                                                           
                                                                                            
   

void arm_shift_q15(
  const q15_t * pSrc,
        int8_t shiftBits,
        q15_t * pDst,
        uint32_t blockSize)
{
        uint32_t blkCnt;                                                 
        uint8_t sign = (shiftBits & 0x80);                                    

#if defined (ARM_MATH_LOOPUNROLL)

#if defined (ARM_MATH_DSP)
  q15_t in1, in2;                                                               
#endif

                                                   
  blkCnt = blockSize >> 2U;

                                                                          
  if (sign == 0U)
  {
    while (blkCnt > 0U)
    {
                              

#if defined (ARM_MATH_DSP)
                                      
      in1 = *pSrc++;
      in2 = *pSrc++;

                                                                                  
#ifndef ARM_MATH_BIG_ENDIAN
      write_q15x2_ia (&pDst, __PKHBT(__SSAT((in1 << shiftBits), 16),
                                     __SSAT((in2 << shiftBits), 16), 16));
#else
      write_q15x2_ia (&pDst, __PKHBT(__SSAT((in2 << shiftBits), 16),
                                      __SSAT((in1 << shiftBits), 16), 16));
#endif                                  

                                      
      in1 = *pSrc++;
      in2 = *pSrc++;

#ifndef ARM_MATH_BIG_ENDIAN
      write_q15x2_ia (&pDst, __PKHBT(__SSAT((in1 << shiftBits), 16),
                                     __SSAT((in2 << shiftBits), 16), 16));
#else
      write_q15x2_ia (&pDst, __PKHBT(__SSAT((in2 << shiftBits), 16),
                                     __SSAT((in1 << shiftBits), 16), 16));
#endif                                  

#else
      *pDst++ = __SSAT(((q31_t) *pSrc++ << shiftBits), 16);
      *pDst++ = __SSAT(((q31_t) *pSrc++ << shiftBits), 16);
      *pDst++ = __SSAT(((q31_t) *pSrc++ << shiftBits), 16);
      *pDst++ = __SSAT(((q31_t) *pSrc++ << shiftBits), 16);
#endif

                                  
      blkCnt--;
    }
  }
  else
  {
    while (blkCnt > 0U)
    {
                              

#if defined (ARM_MATH_DSP)
                                      
      in1 = *pSrc++;
      in2 = *pSrc++;

                                                                                  
#ifndef ARM_MATH_BIG_ENDIAN
      write_q15x2_ia (&pDst, __PKHBT((in1 >> -shiftBits),
                                     (in2 >> -shiftBits), 16));
#else
      write_q15x2_ia (&pDst, __PKHBT((in2 >> -shiftBits),
                                     (in1 >> -shiftBits), 16));
#endif                                  

                                      
      in1 = *pSrc++;
      in2 = *pSrc++;

#ifndef ARM_MATH_BIG_ENDIAN
      write_q15x2_ia (&pDst, __PKHBT((in1 >> -shiftBits),
                                     (in2 >> -shiftBits), 16));
#else
      write_q15x2_ia (&pDst, __PKHBT((in2 >> -shiftBits),
                                     (in1 >> -shiftBits), 16));
#endif                                  

#else
      *pDst++ = (*pSrc++ >> -shiftBits);
      *pDst++ = (*pSrc++ >> -shiftBits);
      *pDst++ = (*pSrc++ >> -shiftBits);
      *pDst++ = (*pSrc++ >> -shiftBits);
#endif

                                  
      blkCnt--;
    }
  }

                                                 
  blkCnt = blockSize % 0x4U;

#else

                                                
  blkCnt = blockSize;

#endif                                        

                                                                          
  if (sign == 0U)
  {
    while (blkCnt > 0U)
    {
                              

                                                               
      *pDst++ = __SSAT(((q31_t) *pSrc++ << shiftBits), 16);

                                  
      blkCnt--;
    }
  }
  else
  {
    while (blkCnt > 0U)
    {
                              

                                                               
      *pDst++ = (*pSrc++ >> -shiftBits);

                                  
      blkCnt--;
    }
  }

}

   
                            
   
