                                                                         
                                  
                                    
                                                 
  
                               
                       
  
                                   
                                                                          
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

   
                         
   

   
                                       

                                                                  

                                                     
                                                                     
                                                                 
                                                                     
                                
                                                                  
                                                                 

                                   

       
                                    
                                                        
   
        

                                                                           
   

   
                       
    
   

   
                                                  
                                                   
                                                    
                                                             
                     
   

void arm_cmplx_mag_f32(
  const float32_t * pSrc,
        float32_t * pDst,
        uint32_t numSamples)
{
  uint32_t blkCnt;                                                 
  float32_t real, imag;                                                                    

#if defined(ARM_MATH_NEON)

  float32x4x2_t vecA;
  float32x4_t vRealA;
  float32x4_t vImagA;
  float32x4_t vMagSqA;

  float32x4x2_t vecB;
  float32x4_t vRealB;
  float32x4_t vImagB;
  float32x4_t vMagSqB;

                                                   
  blkCnt = numSamples >> 3;

  while (blkCnt > 0U)
  {
                                                   

    vecA = vld2q_f32(pSrc);
    pSrc += 8;

    vecB = vld2q_f32(pSrc);
    pSrc += 8;

    vRealA = vmulq_f32(vecA.val[0], vecA.val[0]);
    vImagA = vmulq_f32(vecA.val[1], vecA.val[1]);
    vMagSqA = vaddq_f32(vRealA, vImagA);

    vRealB = vmulq_f32(vecB.val[0], vecB.val[0]);
    vImagB = vmulq_f32(vecB.val[1], vecB.val[1]);
    vMagSqB = vaddq_f32(vRealB, vImagB);

                                                     
    vst1q_f32(pDst, __arm_vec_sqrt_f32_neon(vMagSqA));
    pDst += 4;

    vst1q_f32(pDst, __arm_vec_sqrt_f32_neon(vMagSqB));
    pDst += 4;

                                    
    blkCnt--;
  }

  blkCnt = numSamples & 7;

#else

#if defined (ARM_MATH_LOOPUNROLL)

                                                   
  blkCnt = numSamples >> 2U;

  while (blkCnt > 0U)
  {
                                                

    real = *pSrc++;
    imag = *pSrc++;

                                             
    arm_sqrt_f32((real * real) + (imag * imag), pDst++);

    real = *pSrc++;
    imag = *pSrc++;
    arm_sqrt_f32((real * real) + (imag * imag), pDst++);

    real = *pSrc++;
    imag = *pSrc++;
    arm_sqrt_f32((real * real) + (imag * imag), pDst++);

    real = *pSrc++;
    imag = *pSrc++;
    arm_sqrt_f32((real * real) + (imag * imag), pDst++);

                                
    blkCnt--;
  }

                                                 
  blkCnt = numSamples % 0x4U;

#else

                                                
  blkCnt = numSamples;

#endif                                        
#endif                                 

  while (blkCnt > 0U)
  {
                                                

    real = *pSrc++;
    imag = *pSrc++;

                                             
    arm_sqrt_f32((real * real) + (imag * imag), pDst++);

                                
    blkCnt--;
  }

}

   
                           
   
