                                                                         
                                  
                                  
                                                                                
  
                               
                       
  
                                   
                                                                          
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
void arm_float_to_q7(
  const float32_t * pSrc,
  q7_t * pDst,
  uint32_t blockSize)
{
  const float32_t *pIn = pSrc;                                          
  uint32_t blkCnt;                                                 

  float32_t in;
  float32x4_t inV;
  #ifdef ARM_MATH_ROUNDING
  float32x4_t zeroV = vdupq_n_f32(0.0f);
  float32x4_t pHalf = vdupq_n_f32(0.5f / 128.0f);
  float32x4_t mHalf = vdupq_n_f32(-0.5f / 128.0f);
  float32x4_t r;
  uint32x4_t cmp;
  #endif

  int32x4_t cvt;
  int16x4_t cvt1,cvt2;
  int8x8_t outV;

  blkCnt = blockSize >> 3U;

                                 
                                                                   
  while (blkCnt > 0U)
  {

#ifdef ARM_MATH_ROUNDING
                     
                                                                                       
    inV = vld1q_f32(pIn);
    cmp = vcgtq_f32(inV,zeroV);
    r = vbslq_f32(cmp,pHalf,mHalf);
    inV = vaddq_f32(inV, r);
    cvt1 = vqmovn_s32(vcvtq_n_s32_f32(inV,7));
    pIn += 4;

    inV = vld1q_f32(pIn);
    cmp = vcgtq_f32(inV,zeroV);
    r = vbslq_f32(cmp,pHalf,mHalf);
    inV = vaddq_f32(inV, r);
    cvt2 = vqmovn_s32(vcvtq_n_s32_f32(inV,7));
    pIn += 4;
    
    outV = vqmovn_s16(vcombine_s16(cvt1,cvt2));
    vst1_s8(pDst, outV);
    pDst += 8;

#else

                     
                                                                                       
    inV = vld1q_f32(pIn);
    cvt1 = vqmovn_s32(vcvtq_n_s32_f32(inV,7));
    pIn += 4;

    inV = vld1q_f32(pIn);
    cvt2 = vqmovn_s32(vcvtq_n_s32_f32(inV,7));
    pIn += 4;

    outV = vqmovn_s16(vcombine_s16(cvt1,cvt2));

    vst1_s8(pDst, outV);
    pDst += 8;
#endif                                           

                                    
    blkCnt--;
  }

                                                                                        
                                   
  blkCnt = blockSize & 7;

  while (blkCnt > 0U)
  {

#ifdef ARM_MATH_ROUNDING
                     
                                                                                       
    in = *pIn++;
    in = (in * 128);
    in += in > 0.0f ? 0.5f : -0.5f;
    *pDst++ = (q7_t) (__SSAT((q15_t) (in), 8));

#else

                     
                                                                                       
    *pDst++ = __SSAT((q31_t) (*pIn++ * 128.0f), 8);

#endif                                           

                                    
    blkCnt--;
  }

}
#else
void arm_float_to_q7(
  const float32_t * pSrc,
        q7_t * pDst,
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

    in = (*pIn++ * 128);
    in += in > 0.0f ? 0.5f : -0.5f;
    *pDst++ = (q7_t) (__SSAT((q15_t) (in), 8));

    in = (*pIn++ * 128);
    in += in > 0.0f ? 0.5f : -0.5f;
    *pDst++ = (q7_t) (__SSAT((q15_t) (in), 8));

    in = (*pIn++ * 128);
    in += in > 0.0f ? 0.5f : -0.5f;
    *pDst++ = (q7_t) (__SSAT((q15_t) (in), 8));

    in = (*pIn++ * 128);
    in += in > 0.0f ? 0.5f : -0.5f;
    *pDst++ = (q7_t) (__SSAT((q15_t) (in), 8));

#else

    *pDst++ = __SSAT((q31_t) (*pIn++ * 128.0f), 8);
    *pDst++ = __SSAT((q31_t) (*pIn++ * 128.0f), 8);
    *pDst++ = __SSAT((q31_t) (*pIn++ * 128.0f), 8);
    *pDst++ = __SSAT((q31_t) (*pIn++ * 128.0f), 8);

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

    in = (*pIn++ * 128);
    in += in > 0.0f ? 0.5f : -0.5f;
    *pDst++ = (q7_t) (__SSAT((q15_t) (in), 8));

#else

    *pDst++ = (q7_t) __SSAT((q31_t) (*pIn++ * 128.0f), 8);

#endif                               

                                
    blkCnt--;
  }

}
#endif                                 

   
                            
   
