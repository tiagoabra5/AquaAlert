                                                                         
                                  
                              
                                                                                  
  
                               
                       
  
                                   
                                                                          
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
void arm_rms_f32(
  const float32_t * pSrc,
  uint32_t blockSize,
  float32_t * pResult)
{
  float32_t sum = 0.0f;                                           
  float32_t in;                                                                               
  uint32_t blkCnt;                                                 

  float32x4_t sumV = vdupq_n_f32(0.0f);                                                        
  float32x2_t sumV2;
  float32x4_t inV;

  blkCnt = blockSize >> 2U;

                                 
                                                                   
  while (blkCnt > 0U)
  {
                                                                                             
                                                                               
    inV = vld1q_f32(pSrc);
    sumV = vmlaq_f32(sumV, inV, inV);
    pSrc += 4;

                                    
    blkCnt--;
  }

  sumV2 = vpadd_f32(vget_low_f32(sumV),vget_high_f32(sumV));
  sum = sumV2[0] + sumV2[1];

                                                                                        
                                   
  blkCnt = blockSize % 0x4U;

  while (blkCnt > 0U)
  {
                                                                                             
                                                                               
    in = *pSrc++;
    sum += in * in;

                                    
    blkCnt--;
  }

                                                           
  arm_sqrt_f32(sum / (float32_t) blockSize, pResult);
}
#else
void arm_rms_f32(
  const float32_t * pSrc,
        uint32_t blockSize,
        float32_t * pResult)
{
        uint32_t blkCnt;                                                 
        float32_t sum = 0.0f;                                                        
        float32_t in;                                                                               

#if defined (ARM_MATH_LOOPUNROLL)

                                                   
  blkCnt = blockSize >> 2U;

  while (blkCnt > 0U)
  {
                                                                               

    in = *pSrc++;
                                                                               
    sum += in * in;

    in = *pSrc++;
    sum += in * in;

    in = *pSrc++;
    sum += in * in;

    in = *pSrc++;
    sum += in * in;

                                
    blkCnt--;
  }

                                                 
  blkCnt = blockSize % 0x4U;

#else

                                                
  blkCnt = blockSize;

#endif                                        

  while (blkCnt > 0U)
  {
                                                                               

    in = *pSrc++;
                                                                          
    sum += ( in * in);

                                
    blkCnt--;
  }

                                                   
  arm_sqrt_f32(sum / (float32_t) blockSize, pResult);
}
#endif                                 

   
                     
   
