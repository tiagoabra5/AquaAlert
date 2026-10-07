                                                                         
                                  
                                          
                                                              
  
                               
                       
  
                                   
                                                                          
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

   
                         
   

   
                                                          

                                                                              
                                                                    
                                
                                                                        
                                                                                  
                                                                         
              

                                   

       
                                    
                                                            
                                                            
   
        

                                                                           
   

   
                             
    
   

   
                                                               
                                                           
                                                        
                                                            
                                                             
                     
   

void arm_cmplx_mult_real_f32(
  const float32_t * pSrcCmplx,
  const float32_t * pSrcReal,
        float32_t * pCmplxDst,
        uint32_t numSamples)
{
        uint32_t blkCnt;                                                 
        float32_t in;                                                          

#if defined(ARM_MATH_NEON)
    float32x4_t r;
    float32x4x2_t ab,outCplx;

                                     
    blkCnt = numSamples >> 2U;

    while (blkCnt > 0U)
    {
        ab = vld2q_f32(pSrcCmplx);                                                      
        r = vld1q_f32(pSrcReal);                                    

	                        
        pSrcCmplx += 8;
        pSrcReal += 4;

        outCplx.val[0] = vmulq_f32(ab.val[0], r);
        outCplx.val[1] = vmulq_f32(ab.val[1], r);

        vst2q_f32(pCmplxDst, outCplx);
        pCmplxDst += 8;

        blkCnt--;
    }

              
    blkCnt = numSamples & 3;
#else
#if defined (ARM_MATH_LOOPUNROLL)

                                                   
  blkCnt = numSamples >> 2U;

  while (blkCnt > 0U)
  {
                                             
                                             

    in = *pSrcReal++;
                                             
    *pCmplxDst++ = *pSrcCmplx++ * in;
    *pCmplxDst++ = *pSrcCmplx++ * in;

    in = *pSrcReal++;
    *pCmplxDst++ = *pSrcCmplx++ * in;
    *pCmplxDst++ = *pSrcCmplx++ * in;

    in = *pSrcReal++;
    *pCmplxDst++ = *pSrcCmplx++ * in;
    *pCmplxDst++ = *pSrcCmplx++ * in;

    in = *pSrcReal++;
    *pCmplxDst++ = *pSrcCmplx++* in;
    *pCmplxDst++ = *pSrcCmplx++ * in;

                                
    blkCnt--;
  }

                                                 
  blkCnt = numSamples % 0x4U;

#else

                                                
  blkCnt = numSamples;

#endif                                        
#endif                                 

  while (blkCnt > 0U)
  {
                                             
                                             

    in = *pSrcReal++;
                                             
    *pCmplxDst++ = *pSrcCmplx++ * in;
    *pCmplxDst++ = *pSrcCmplx++ * in;

                                
    blkCnt--;
  }

}

   
                                 
   
