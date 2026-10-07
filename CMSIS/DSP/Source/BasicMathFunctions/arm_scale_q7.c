                                                                         
                                  
                               
                                                   
  
                               
                       
  
                                   
                                                                          
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

   
                    
   

   
                        
    
   

   
                                                    
                                                      
                                                                 
                                                                 
                                                       
                                                            
                     

                                              
                                                                                                   
                                                                                                                              
   

void arm_scale_q7(
  const q7_t * pSrc,
        q7_t scaleFract,
        int8_t shift,
        q7_t * pDst,
        uint32_t blockSize)
{
        uint32_t blkCnt;                                                 
        int8_t kShift = 7 - shift;                                                       

#if defined (ARM_MATH_LOOPUNROLL)

#if defined (ARM_MATH_DSP)
  q7_t in1,  in2,  in3,  in4;                                                   
  q7_t out1, out2, out3, out4;                                                   
#endif

                                                   
  blkCnt = blockSize >> 2U;

  while (blkCnt > 0U)
  {
                       

#if defined (ARM_MATH_DSP)
                                      
    in1 = *pSrc++;
    in2 = *pSrc++;
    in3 = *pSrc++;
    in4 = *pSrc++;

                                                                  
    out1 = (q7_t) (__SSAT(((in1) * scaleFract) >> kShift, 8));
    out2 = (q7_t) (__SSAT(((in2) * scaleFract) >> kShift, 8));
    out3 = (q7_t) (__SSAT(((in3) * scaleFract) >> kShift, 8));
    out4 = (q7_t) (__SSAT(((in4) * scaleFract) >> kShift, 8));

                                                                       
    write_q7x4_ia (&pDst, __PACKq7(out1, out2, out3, out4));
#else
    *pDst++ = (q7_t) (__SSAT((((q15_t) *pSrc++ * scaleFract) >> kShift), 8));
    *pDst++ = (q7_t) (__SSAT((((q15_t) *pSrc++ * scaleFract) >> kShift), 8));
    *pDst++ = (q7_t) (__SSAT((((q15_t) *pSrc++ * scaleFract) >> kShift), 8));
    *pDst++ = (q7_t) (__SSAT((((q15_t) *pSrc++ * scaleFract) >> kShift), 8));
#endif

                                
    blkCnt--;
  }

                                                 
  blkCnt = blockSize % 0x4U;

#else

                                                
  blkCnt = blockSize;

#endif                                        

  while (blkCnt > 0U)
  {
                       

                                                             
    *pDst++ = (q7_t) (__SSAT((((q15_t) *pSrc++ * scaleFract) >> kShift), 8));

                                
    blkCnt--;
  }

}

   
                            
   
