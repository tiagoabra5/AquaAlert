                                                                         
                                  
                                         
                                                   
  
                               
                       
  
                                   
                                                                          
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

   
                         
   

   
                                              

                                                  
                                                                

                                                                     
                                                               
                                                                 
                                                                
                                
                                                             

                                   

       
                 
                 
                                    
                                                                                      
                                                                                      
   
        

                                                                           
   

   
                            
    
   

   
                                                    
                                                             
                                                              
                                                             
                                                                  
                                                                       
                     
   

void arm_cmplx_dot_prod_f32(
  const float32_t * pSrcA,
  const float32_t * pSrcB,
        uint32_t numSamples,
        float32_t * realResult,
        float32_t * imagResult)
{
        uint32_t blkCnt;                                                 
        float32_t real_sum = 0.0f, imag_sum = 0.0f;                                    
        float32_t a0,b0,c0,d0;

#if defined(ARM_MATH_NEON)
    float32x4x2_t vec1,vec2,vec3,vec4;
    float32x4_t accR,accI;
    float32x2_t accum = vdup_n_f32(0);

    accR = vdupq_n_f32(0.0);
    accI = vdupq_n_f32(0.0);

                                                     
    blkCnt = numSamples >> 3U;

    while (blkCnt > 0U)
    {
	                                          
                                                                                    

	vec1 = vld2q_f32(pSrcA);
        vec2 = vld2q_f32(pSrcB);

	                        
        pSrcA += 8;
        pSrcB += 8;

	                                       
        accR = vmlaq_f32(accR,vec1.val[0],vec2.val[0]);
        accR = vmlsq_f32(accR,vec1.val[1],vec2.val[1]);

	                                       
        accI = vmlaq_f32(accI,vec1.val[1],vec2.val[0]);
        accI = vmlaq_f32(accI,vec1.val[0],vec2.val[1]);

        vec3 = vld2q_f32(pSrcA);
        vec4 = vld2q_f32(pSrcB);
	
	                        
        pSrcA += 8;
        pSrcB += 8;

	                                       
        accR = vmlaq_f32(accR,vec3.val[0],vec4.val[0]);
        accR = vmlsq_f32(accR,vec3.val[1],vec4.val[1]);

	                                       
        accI = vmlaq_f32(accI,vec3.val[1],vec4.val[0]);
        accI = vmlaq_f32(accI,vec3.val[0],vec4.val[1]);

                                        
        blkCnt--;
    }

    accum = vpadd_f32(vget_low_f32(accR), vget_high_f32(accR));
    real_sum += accum[0] + accum[1];

    accum = vpadd_f32(vget_low_f32(accI), vget_high_f32(accI));
    imag_sum += accum[0] + accum[1];

              
    blkCnt = numSamples & 0x7;

#else
#if defined (ARM_MATH_LOOPUNROLL)

                                                   
  blkCnt = numSamples >> 2U;

  while (blkCnt > 0U)
  {
    a0 = *pSrcA++;
    b0 = *pSrcA++;
    c0 = *pSrcB++;
    d0 = *pSrcB++;

    real_sum += a0 * c0;
    imag_sum += a0 * d0;
    real_sum -= b0 * d0;
    imag_sum += b0 * c0;

    a0 = *pSrcA++;
    b0 = *pSrcA++;
    c0 = *pSrcB++;
    d0 = *pSrcB++;

    real_sum += a0 * c0;
    imag_sum += a0 * d0;
    real_sum -= b0 * d0;
    imag_sum += b0 * c0;

    a0 = *pSrcA++;
    b0 = *pSrcA++;
    c0 = *pSrcB++;
    d0 = *pSrcB++;

    real_sum += a0 * c0;
    imag_sum += a0 * d0;
    real_sum -= b0 * d0;
    imag_sum += b0 * c0;

    a0 = *pSrcA++;
    b0 = *pSrcA++;
    c0 = *pSrcB++;
    d0 = *pSrcB++;

    real_sum += a0 * c0;
    imag_sum += a0 * d0;
    real_sum -= b0 * d0;
    imag_sum += b0 * c0;

                                
    blkCnt--;
  }

                                                 
  blkCnt = numSamples % 0x4U;

#else

                                                
  blkCnt = numSamples;

#endif                                        
#endif                                 

  while (blkCnt > 0U)
  {
    a0 = *pSrcA++;
    b0 = *pSrcA++;
    c0 = *pSrcB++;
    d0 = *pSrcB++;

    real_sum += a0 * c0;
    imag_sum += a0 * d0;
    real_sum -= b0 * d0;
    imag_sum += b0 * c0;

                                
    blkCnt--;
  }

                                                              
  *realResult = real_sum;
  *imagResult = imag_sum;
}

   
                                
   
