                                                                         
                                  
                                   
                                                                                 
  
                               
                       
  
                                   
                                                                          
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
void arm_q31_to_float(
  const q31_t * pSrc,
        float32_t * pDst,
        uint32_t blockSize)
{
  const q31_t *pIn = pSrc;                                              
  uint32_t blkCnt;                                                 

  int32x4_t inV;
  float32x4_t outV;

  blkCnt = blockSize >> 2U;

                                 
                                                                   
  while (blkCnt > 0U)
  {
                                        
                                                                                        
    inV = vld1q_s32(pIn);
    pIn += 4;

    outV = vcvtq_n_f32_s32(inV,31);

    vst1q_f32(pDst, outV);
    pDst += 4;

                                    
    blkCnt--;
  }

                                                                                        
                                   
  blkCnt = blockSize & 3;


  while (blkCnt > 0U)
  {
                                        
                                                                                        
    *pDst++ = ((float32_t) * pIn++ / 2147483648.0f);

                                    
    blkCnt--;
  }
}
#else
void arm_q31_to_float(
  const q31_t * pSrc,
  float32_t * pDst,
  uint32_t blockSize)
{
  const q31_t *pIn = pSrc;                                              
  uint32_t blkCnt;                                                 

#if defined (ARM_MATH_LOOPUNROLL)

                      
  blkCnt = blockSize >> 2U;

  while (blkCnt > 0U)
  {
                                        

                                                                          
    *pDst++ = ((float32_t) *pIn++ / 2147483648.0f);
    *pDst++ = ((float32_t) *pIn++ / 2147483648.0f);
    *pDst++ = ((float32_t) *pIn++ / 2147483648.0f);
    *pDst++ = ((float32_t) *pIn++ / 2147483648.0f);

                                
    blkCnt--;
  }

                                                 
  blkCnt = blockSize % 0x4U;

#else

                                                
  blkCnt = blockSize;

#endif                                        

  while (blkCnt > 0U)
  {
                                        

                                                                          
    *pDst++ = ((float32_t) *pIn++ / 2147483648.0f);

                                
    blkCnt--;
  }

}
#endif                                 

   
                          
   
