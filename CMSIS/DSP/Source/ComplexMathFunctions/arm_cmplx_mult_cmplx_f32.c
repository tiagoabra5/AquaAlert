                                                                         
                                  
                                           
                                                                 
  
                               
                       
  
                                   
                                                                          
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

   
                         
   

   
                                                              

                                                                                       
                                                                    
                                
                                                                        
                                                                                  
              

                                   

       
                                    
                                                                                        
                                                                                        
   
        

                                                                           
   

   
                              
    
   

   
                                                                  
                                                         
                                                          
                                                    
                                                             
                     
   

void arm_cmplx_mult_cmplx_f32(
  const float32_t * pSrcA,
  const float32_t * pSrcB,
        float32_t * pDst,
        uint32_t numSamples)
{
    uint32_t blkCnt;                                                 
    float32_t a, b, c, d;                                                              

#if defined(ARM_MATH_NEON)
    float32x4x2_t va, vb;
    float32x4_t real, imag;
    float32x4x2_t outCplx;

                                     
    blkCnt = numSamples >> 2U;

    while (blkCnt > 0U)
    {
        va = vld2q_f32(pSrcA);                                                      
        vb = vld2q_f32(pSrcB);                                    

	                        
        pSrcA += 8;
        pSrcB += 8;
	
	                                       
        outCplx.val[0] = vmulq_f32(va.val[0], vb.val[0]);
        outCplx.val[0] = vmlsq_f32(outCplx.val[0], va.val[1], vb.val[1]);

	                                       
        outCplx.val[1] = vmulq_f32(va.val[0], vb.val[1]);
        outCplx.val[1] = vmlaq_f32(outCplx.val[1], va.val[1], vb.val[0]);

        vst2q_f32(pDst, outCplx);

	                       
        pDst += 8;

	                                
        blkCnt--;
    }

              
    blkCnt = numSamples & 3;

#else
#if defined (ARM_MATH_LOOPUNROLL)

                                                   
  blkCnt = numSamples >> 2U;

  while (blkCnt > 0U)
  {
                                                                               
                                                                               

    a = *pSrcA++;
    b = *pSrcA++;
    c = *pSrcB++;
    d = *pSrcB++;
                                             
    *pDst++ = (a * c) - (b * d);
    *pDst++ = (a * d) + (b * c);

    a = *pSrcA++;
    b = *pSrcA++;
    c = *pSrcB++;
    d = *pSrcB++;
    *pDst++ = (a * c) - (b * d);
    *pDst++ = (a * d) + (b * c);

    a = *pSrcA++;
    b = *pSrcA++;
    c = *pSrcB++;
    d = *pSrcB++;
    *pDst++ = (a * c) - (b * d);
    *pDst++ = (a * d) + (b * c);

    a = *pSrcA++;
    b = *pSrcA++;
    c = *pSrcB++;
    d = *pSrcB++;
    *pDst++ = (a * c) - (b * d);
    *pDst++ = (a * d) + (b * c);

                                
    blkCnt--;
  }

                                                 
  blkCnt = numSamples % 0x4U;

#else

                                                
  blkCnt = numSamples;

#endif                                        
#endif                                 

  while (blkCnt > 0U)
  {
                                                                               
                                                                               

    a = *pSrcA++;
    b = *pSrcA++;
    c = *pSrcB++;
    d = *pSrcB++;

                                             
    *pDst++ = (a * c) - (b * d);
    *pDst++ = (a * d) + (b * c);

                                
    blkCnt--;
  }

}

   
                                  
   
