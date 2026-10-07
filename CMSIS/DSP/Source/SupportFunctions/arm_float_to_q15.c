                                                                         
                                  
                                   
                                                                                 
  
                               
                       
  
                                   
                                                                          
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

   
                       
   

   
                        
    
   

   
                                                                                  
                                                                     
                                                           
                                                            
                     

                        
                                                                   
       
                                                               
        

                                              
                                                           
                                                                                            

       
                                                                                                    
                                                                          
   
#if defined(ARM_MATH_NEON_EXPERIMENTAL)
void arm_float_to_q15(
  const float32_t * pSrc,
  q15_t * pDst,
  uint32_t blockSize)
{
  const float32_t *pIn = pSrc;                                          
  uint32_t blkCnt;                                                 

  float32_t in;
  float32x4_t inV;
  #ifdef ARM_MATH_ROUNDING
  float32x4_t zeroV = vdupq_n_f32(0.0f);
  float32x4_t pHalf = vdupq_n_f32(0.5f / 32768.0f);
  float32x4_t mHalf = vdupq_n_f32(-0.5f / 32768.0f);
  float32x4_t r;
  uint32x4_t cmp;
  #endif

  int32x4_t cvt;
  int16x4_t outV;

  blkCnt = blockSize >> 2U;

                                 
                                                                   
  while (blkCnt > 0U)
  {

#ifdef ARM_MATH_ROUNDING
                       
                                                                                        
    inV = vld1q_f32(pIn);
    cmp = vcgtq_f32(inV,zeroV);
    r = vbslq_f32(cmp,pHalf,mHalf);
    inV = vaddq_f32(inV, r);

    pIn += 4;

    cvt = vcvtq_n_s32_f32(inV,15);
    outV = vqmovn_s32(cvt);

    vst1_s16(pDst, outV);
    pDst += 4;

#else

                       
                                                                                        
    inV = vld1q_f32(pIn);

    cvt = vcvtq_n_s32_f32(inV,15);
    outV = vqmovn_s32(cvt);

    vst1_s16(pDst, outV);
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
    in = (in * 32768.0f);
    in += in > 0.0f ? 0.5f : -0.5f;
    *pDst++ = (q15_t) (__SSAT((q31_t) (in), 16));

#else

                       
                                                                                        
    *pDst++ = (q15_t) __SSAT((q31_t) (*pIn++ * 32768.0f), 16);

#endif                                           

                                    
    blkCnt--;
  }
}
#else
void arm_float_to_q15(
  const float32_t * pSrc,
        q15_t * pDst,
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

    in = (*pIn++ * 32768.0f);
    in += in > 0.0f ? 0.5f : -0.5f;
    *pDst++ = (q15_t) (__SSAT((q31_t) (in), 16));

    in = (*pIn++ * 32768.0f);
    in += in > 0.0f ? 0.5f : -0.5f;
    *pDst++ = (q15_t) (__SSAT((q31_t) (in), 16));

    in = (*pIn++ * 32768.0f);
    in += in > 0.0f ? 0.5f : -0.5f;
    *pDst++ = (q15_t) (__SSAT((q31_t) (in), 16));

    in = (*pIn++ * 32768.0f);
    in += in > 0.0f ? 0.5f : -0.5f;
    *pDst++ = (q15_t) (__SSAT((q31_t) (in), 16));

#else

    *pDst++ = (q15_t) __SSAT((q31_t) (*pIn++ * 32768.0f), 16);
    *pDst++ = (q15_t) __SSAT((q31_t) (*pIn++ * 32768.0f), 16);
    *pDst++ = (q15_t) __SSAT((q31_t) (*pIn++ * 32768.0f), 16);
    *pDst++ = (q15_t) __SSAT((q31_t) (*pIn++ * 32768.0f), 16);

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

    in = (*pIn++ * 32768.0f);
    in += in > 0.0f ? 0.5f : -0.5f;
    *pDst++ = (q15_t) (__SSAT((q31_t) (in), 16));

#else

                       
                                                                                        
    *pDst++ = (q15_t) __SSAT((q31_t) (*pIn++ * 32768.0f), 16);

#endif                               

                                
    blkCnt--;
  }

}
#endif                                 

   
                            
   
