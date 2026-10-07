                                                                         
                                  
                               
                                                                    
  
                               
                       
  
                                   
                                                                          
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
void arm_fill_f32(
  float32_t value,
  float32_t * pDst,
  uint32_t blockSize)
{
  uint32_t blkCnt;                                                 


  float32x4_t inV = vdupq_n_f32(value);

  blkCnt = blockSize >> 2U;

                                 
                                                                   
  while (blkCnt > 0U)
  {
                   
                                                  
    vst1q_f32(pDst, inV);
    pDst += 4;

                                    
    blkCnt--;
  }

                                                                                        
                                   
  blkCnt = blockSize & 3;

  while (blkCnt > 0U)
  {
                   
                                                  
    *pDst++ = value;

                                    
    blkCnt--;
  }
}
#else
void arm_fill_f32(
  float32_t value,
  float32_t * pDst,
  uint32_t blockSize)
{
  uint32_t blkCnt;                                                 

#if defined (ARM_MATH_LOOPUNROLL)

                                                   
  blkCnt = blockSize >> 2U;

  while (blkCnt > 0U)
  {
                   

                                          
    *pDst++ = value;
    *pDst++ = value;
    *pDst++ = value;
    *pDst++ = value;

                                
    blkCnt--;
  }

                                                 
  blkCnt = blockSize % 0x4U;

#else

                                                
  blkCnt = blockSize;

#endif                                        

  while (blkCnt > 0U)
  {
                   

                                          
    *pDst++ = value;

                                
    blkCnt--;
  }
}
#endif                                 
   
                      
   
