                                                                         
                                  
                                   
                                                                                 
  
                               
                       
  
                                   
                                                                          
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

   
                       
   

   
                                                            
   

   
                        
    
   

   
                                                                                  
                                                                     
                                                           
                                                            
                     

                        
                                                                   
       
                                                                    
        

                                              
                                                           
                                                                                                   

       
                                                                                                    
                                                                          
   

#if defined(ARM_MATH_NEON)
void arm_float_to_q31(
  const float32_t * pSrc,
  q31_t * pDst,
  uint32_t blockSize)
{
  const float32_t *pIn = pSrc;                                          
  uint32_t blkCnt;                                                 

  float32_t in;
  float32x4_t inV;
  #ifdef ARM_MATH_ROUNDING
  float32x4_t zeroV = vdupq_n_f32(0.0f);
  float32x4_t pHalf = vdupq_n_f32(0.5f / 2147483648.0f);
  float32x4_t mHalf = vdupq_n_f32(-0.5f / 2147483648.0f);
  float32x4_t r;
  uint32x4_t cmp;
  #endif

  int32x4_t outV;

  blkCnt = blockSize >> 2U;

                                 
                                                                   
  while (blkCnt > 0U)
  {

#ifdef ARM_MATH_ROUNDING

                       
                                                                                        
    inV = vld1q_f32(pIn);
    cmp = vcgtq_f32(inV,zeroV);
    r = vbslq_f32(cmp,pHalf,mHalf);
    inV = vaddq_f32(inV, r);

    pIn += 4;

    outV = vcvtq_n_s32_f32(inV,31);

    vst1q_s32(pDst, outV);
    pDst += 4;

#else

                            
                                                                                        
    inV = vld1q_f32(pIn);

    outV = vcvtq_n_s32_f32(inV,31);

    vst1q_s32(pDst, outV);
    pDst += 4;
    pIn += 4;

#endif                                           

                                    
    blkCnt--;
  }

                                                                                        
                                   
  blkCnt = blockSize & 3;

  while (blkCnt > 0U)
  {

#ifdef ARM_MATH_ROUNDING

                            
                                                                                        
    in = *pIn++;
    in = (in * 2147483648.0f);
    in += in > 0.0f ? 0.5f : -0.5f;
    *pDst++ = clip_q63_to_q31((q63_t) (in));

#else

                            
                                                                                        
    *pDst++ = clip_q63_to_q31((q63_t) (*pIn++ * 2147483648.0f));

#endif                                           

                                    
    blkCnt--;
  }


}
#else
void arm_float_to_q31(
  const float32_t * pSrc,
        q31_t * pDst,
        uint32_t blockSize)
{
        uint32_t blkCnt;                                                 
  const float32_t *pIn = pSrc;                                             

#ifdef ARM_MATH_ROUNDING
        float32_t in;
#endif                               

#if defined (ARM_MATH_LOOPUNROLL)

                                                   
  blkCnt = blockSize >> 2U;

  while (blkCnt > 0U)
  {
                            

                                                                          
#ifdef ARM_MATH_ROUNDING

    in = (*pIn++ * 2147483648.0f);
    in += in > 0.0f ? 0.5f : -0.5f;
    *pDst++ = clip_q63_to_q31((q63_t) (in));

    in = (*pIn++ * 2147483648.0f);
    in += in > 0.0f ? 0.5f : -0.5f;
    *pDst++ = clip_q63_to_q31((q63_t) (in));

    in = (*pIn++ * 2147483648.0f);
    in += in > 0.0f ? 0.5f : -0.5f;
    *pDst++ = clip_q63_to_q31((q63_t) (in));

    in = (*pIn++ * 2147483648.0f);
    in += in > 0.0f ? 0.5f : -0.5f;
    *pDst++ = clip_q63_to_q31((q63_t) (in));

#else

                            
                                                                                        
    *pDst++ = clip_q63_to_q31((q63_t) (*pIn++ * 2147483648.0f));
    *pDst++ = clip_q63_to_q31((q63_t) (*pIn++ * 2147483648.0f));
    *pDst++ = clip_q63_to_q31((q63_t) (*pIn++ * 2147483648.0f));
    *pDst++ = clip_q63_to_q31((q63_t) (*pIn++ * 2147483648.0f));

#endif                               

                                
    blkCnt--;
  }

                                                 
  blkCnt = blockSize % 0x4U;

#else

                                                
  blkCnt = blockSize;

#endif                                        

  while (blkCnt > 0U)
  {
                            

                                                                          
#ifdef ARM_MATH_ROUNDING

    in = (*pIn++ * 2147483648.0f);
    in += in > 0.0f ? 0.5f : -0.5f;
    *pDst++ = clip_q63_to_q31((q63_t) (in));

#else

                            
                                                                                        
    *pDst++ = clip_q63_to_q31((q63_t) (*pIn++ * 2147483648.0f));

#endif                               

                                
    blkCnt--;
  }

}
#endif                                 

   
                            
   
