                                                                         
                                  
                                     
                                                 
  
                               
                       
  
                                   
                                                                          
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

   
                         
   

   
                                        

                                                   

                                                     
                                                                                      
                                                                 
                                                                
                                
                                                             

                                   
       
                                    
                                                     
                                                     
   
        

                                                                           
   

   
                        
    
   

   
                                                  
                                                       
                                                        
                                                             
                     
   


void arm_cmplx_conj_f32(
  const float32_t * pSrc,
        float32_t * pDst,
        uint32_t numSamples)
{
        uint32_t blkCnt;                                                 

#if defined(ARM_MATH_NEON)
   float32x4_t zero;
   float32x4x2_t vec;

   zero = vdupq_n_f32(0.0);

                                    
   blkCnt = numSamples >> 2U;

   while (blkCnt > 0U)
   {
                                       
                                                                                            
     vec = vld2q_f32(pSrc);
     vec.val[1] = vsubq_f32(zero,vec.val[1]);
     vst2q_f32(pDst,vec);

                             
     pSrc += 8;
     pDst += 8;
        
                                     
     blkCnt--;
   }

             
   blkCnt = numSamples & 0x3;

#else
#if defined (ARM_MATH_LOOPUNROLL)

                                                   
  blkCnt = numSamples >> 2U;

  while (blkCnt > 0U)
  {
                                        

                                                                             
    *pDst++ =  *pSrc++;
    *pDst++ = -*pSrc++;

    *pDst++ =  *pSrc++;
    *pDst++ = -*pSrc++;

    *pDst++ =  *pSrc++;
    *pDst++ = -*pSrc++;

    *pDst++ =  *pSrc++;
    *pDst++ = -*pSrc++;

                                
    blkCnt--;
  }

                                                 
  blkCnt = numSamples % 0x4U;

#else

                                                
  blkCnt = numSamples;

#endif                                        
#endif                                  

  while (blkCnt > 0U)
  {
                                        

                                                                             
    *pDst++ =  *pSrc++;
    *pDst++ = -*pSrc++;

                                
    blkCnt--;
  }

}

   
                            
   
