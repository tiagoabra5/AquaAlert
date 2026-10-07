                                                                         
                                  
                                
                                                    
  
                               
                       
  
                                   
                                                                          
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

   
                    
   

   
                        
    
   

   
                                                     
                                                      
                                                                 
                                                                 
                                                       
                                                            
                     

                                              
                                                                                                    
                                                                                                                               
   

void arm_scale_q15(
  const q15_t *pSrc,
        q15_t scaleFract,
        int8_t shift,
        q15_t *pDst,
        uint32_t blockSize)
{
        uint32_t blkCnt;                                                 
        int8_t kShift = 15 - shift;                                                      

#if defined (ARM_MATH_LOOPUNROLL)
#if defined (ARM_MATH_DSP)
  q31_t inA1, inA2;
  q31_t out1, out2, out3, out4;                                                  
  q15_t in1, in2, in3, in4;                                                     
#endif
#endif

#if defined (ARM_MATH_LOOPUNROLL)

                                                   
  blkCnt = blockSize >> 2U;

  while (blkCnt > 0U)
  {
                       

#if defined (ARM_MATH_DSP)
                                                      
    inA1 = read_q15x2_ia ((q15_t **) &pSrc);
    inA2 = read_q15x2_ia ((q15_t **) &pSrc);

                                                           
                                                
    out1 = (q31_t) ((q15_t) (inA1 >> 16) * scaleFract);
    out2 = (q31_t) ((q15_t) (inA1      ) * scaleFract);
    out3 = (q31_t) ((q15_t) (inA2 >> 16) * scaleFract);
    out4 = (q31_t) ((q15_t) (inA2      ) * scaleFract);

                        
    out1 = out1 >> kShift;
    out2 = out2 >> kShift;
    out3 = out3 >> kShift;
    out4 = out4 >> kShift;

                             
    in1 = (q15_t) (__SSAT(out1, 16));
    in2 = (q15_t) (__SSAT(out2, 16));
    in3 = (q15_t) (__SSAT(out3, 16));
    in4 = (q15_t) (__SSAT(out4, 16));

                                     
    write_q15x2_ia (&pDst, __PKHBT(in2, in1, 16));
    write_q15x2_ia (&pDst, __PKHBT(in4, in3, 16));
#else
    *pDst++ = (q15_t) (__SSAT(((q31_t) *pSrc++ * scaleFract) >> kShift, 16));
    *pDst++ = (q15_t) (__SSAT(((q31_t) *pSrc++ * scaleFract) >> kShift, 16));
    *pDst++ = (q15_t) (__SSAT(((q31_t) *pSrc++ * scaleFract) >> kShift, 16));
    *pDst++ = (q15_t) (__SSAT(((q31_t) *pSrc++ * scaleFract) >> kShift, 16));
#endif

                                
    blkCnt--;
  }

                                                 
  blkCnt = blockSize % 0x4U;

#else

                                                
  blkCnt = blockSize;

#endif                                        

  while (blkCnt > 0U)
  {
                       

                                                             
    *pDst++ = (q15_t) (__SSAT(((q31_t) *pSrc++ * scaleFract) >> kShift, 16));

                                
    blkCnt--;
  }

}

   
                            
   
