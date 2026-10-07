                                                                         
                                  
                                
                                                               
  
                               
                       
  
                                   
                                                                          
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

   
                    
   

   
                                   

                                                                                       

       
                                                      
        

                                                                                     
                                                                                                 
                                                                   
                                              

       
                                                                      
        

                                                             
       
                                   
        

                                                                                
                                               
   

   
                        
    
   

   
                                                                
                                                      
                                                      
                                                       
                                                            
                     
   

void arm_scale_f32(
  const float32_t *pSrc,
        float32_t scale,
        float32_t *pDst,
        uint32_t blockSize)
{
  uint32_t blkCnt;                                                 
#if defined(ARM_MATH_NEON_EXPERIMENTAL)
    float32x4_t vec1;
    float32x4_t res;

                                     
    blkCnt = blockSize >> 2U;

    while (blkCnt > 0U)
    {
                           

    	                                                                           
        vec1 = vld1q_f32(pSrc);
        res = vmulq_f32(vec1, vdupq_n_f32(scale));
        vst1q_f32(pDst, res);

                                
        pSrc += 4; 
        pDst += 4;
        
                                        
        blkCnt--;
    }

              
    blkCnt = blockSize & 0x3;

#else
#if defined (ARM_MATH_LOOPUNROLL)

                                                   
  blkCnt = blockSize >> 2U;

  while (blkCnt > 0U)
  {
                       

                                                             
    *pDst++ = (*pSrc++) * scale;

    *pDst++ = (*pSrc++) * scale;

    *pDst++ = (*pSrc++) * scale;

    *pDst++ = (*pSrc++) * scale;

                                
    blkCnt--;
  }

                                                 
  blkCnt = blockSize % 0x4U;

#else

                                                
  blkCnt = blockSize;

#endif                                        
#endif                                              

  while (blkCnt > 0U)
  {
                       

                                                             
    *pDst++ = (*pSrc++) * scale;

                                
    blkCnt--;
  }

}

   
                            
   
