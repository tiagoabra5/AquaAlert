                                                                         
                                  
                                  
                                                                                
  
                               
                       
  
                                   
                                                                          
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
void arm_q7_to_float(
  const q7_t * pSrc,
  float32_t * pDst,
  uint32_t blockSize)
{
  const q7_t *pIn = pSrc;                                               
  uint32_t blkCnt;                                                 

  int8x16_t inV;
  int16x8_t inVLO, inVHI;
  int32x4_t inVLL, inVLH, inVHL, inVHH;
  float32x4_t outV;

  blkCnt = blockSize >> 4U;

                                  
                                                                    
  while (blkCnt > 0U)
  {
                                 
                                                                                       
    inV = vld1q_s8(pIn);
    pIn += 16;

    inVLO = vmovl_s8(vget_low_s8(inV));
    inVHI = vmovl_s8(vget_high_s8(inV));

    inVLL = vmovl_s16(vget_low_s16(inVLO));
    inVLH = vmovl_s16(vget_high_s16(inVLO));
    inVHL = vmovl_s16(vget_low_s16(inVHI));
    inVHH = vmovl_s16(vget_high_s16(inVHI));

    outV = vcvtq_n_f32_s32(inVLL,7);
    vst1q_f32(pDst, outV);
    pDst += 4;

    outV = vcvtq_n_f32_s32(inVLH,7);
    vst1q_f32(pDst, outV);
    pDst += 4;

    outV = vcvtq_n_f32_s32(inVHL,7);
    vst1q_f32(pDst, outV);
    pDst += 4;

    outV = vcvtq_n_f32_s32(inVHH,7);
    vst1q_f32(pDst, outV);
    pDst += 4;

                                    
    blkCnt--;
  }

                                                                                         
                                   
  blkCnt = blockSize & 0xF;

  while (blkCnt > 0U)
  {
                                 
                                                                                       
    *pDst++ = ((float32_t) * pIn++ / 128.0f);

                                    
    blkCnt--;
  }
}
#else
void arm_q7_to_float(
  const q7_t * pSrc,
        float32_t * pDst,
        uint32_t blockSize)
{
        uint32_t blkCnt;                                                 
  const q7_t *pIn = pSrc;                                                  

#if defined (ARM_MATH_LOOPUNROLL)

                                                   
  blkCnt = blockSize >> 2U;

  while (blkCnt > 0U)
  {
                                 

                                                                         
    *pDst++ = ((float32_t) * pIn++ / 128.0f);
    *pDst++ = ((float32_t) * pIn++ / 128.0f);
    *pDst++ = ((float32_t) * pIn++ / 128.0f);
    *pDst++ = ((float32_t) * pIn++ / 128.0f);

                                
    blkCnt--;
  }

                                                 
  blkCnt = blockSize % 0x4U;

#else

                                                
  blkCnt = blockSize;

#endif                                        

  while (blkCnt > 0U)
  {
                                 

                                                                         
    *pDst++ = ((float32_t) * pIn++ / 128.0f);

                                
    blkCnt--;
  }

}
#endif                                 

   
                         
   
