                                                                         
                                  
                              
                                                         
  
                               
                       
  
                                   
                                                                          
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
#include <limits.h>

   
                     
   

   
                       

                                                 
                                                                                
                                                                               
   

   
                 
    
   

   
                                                          
                                                      
                                                             
                                                       
                                                                
                     
   
#if defined(ARM_MATH_NEON)
void arm_min_f32(
  const float32_t * pSrc,
  uint32_t blockSize,
  float32_t * pResult,
  uint32_t * pIndex)
{
  float32_t maxVal1, maxVal2, out;                                                                   
  uint32_t blkCnt, outIndex, count;                                

  float32x4_t outV, srcV;
  float32x2_t outV2;

  uint32x4_t idxV;
  uint32x4_t maxIdx={ULONG_MAX,ULONG_MAX,ULONG_MAX,ULONG_MAX};
  uint32x4_t index={4,5,6,7};
  uint32x4_t delta={4,4,4,4};
  uint32x4_t countV={0,1,2,3};
  uint32x2_t countV2;

                                   
  count = 0U;

                                           
  outIndex = 0U;

                                                                         
  if (blockSize <= 3)
  {
      out = *pSrc++;

      blkCnt = blockSize - 1;

      while (blkCnt > 0U)
      {
                                                                         
        maxVal1 = *pSrc++;
    
                                           
        if (out > maxVal1)
        {
                                                       
          out = maxVal1;
          outIndex = blockSize - blkCnt;
        }
    
                                        
        blkCnt--;
      }
  }
  else
  {
      outV = vld1q_f32(pSrc);
      pSrc += 4;
    
                                       
      blkCnt = (blockSize - 4 ) >> 2U;
    
      while (blkCnt > 0U)
      {
        srcV = vld1q_f32(pSrc);
        pSrc += 4;
    
        idxV = vcltq_f32(srcV, outV);
        outV = vbslq_f32(idxV, srcV, outV );
        countV = vbslq_u32(idxV, index,countV );
    
        index = vaddq_u32(index,delta);
    
                                        
        blkCnt--;
      }
    
      outV2 = vpmin_f32(vget_low_f32(outV),vget_high_f32(outV));
      outV2 = vpmin_f32(outV2,outV2);
      out = outV2[0];
    
      idxV = vceqq_f32(outV, vdupq_n_f32(out));
      countV = vbslq_u32(idxV, countV,maxIdx);
      
      countV2 = vpmin_u32(vget_low_u32(countV),vget_high_u32(countV));
      countV2 = vpmin_u32(countV2,countV2);
      outIndex = countV2[0];
    
                                                    
      blkCnt = (blockSize - 4 ) % 4U;
    
      while (blkCnt > 0U)
      {
                                                                         
        maxVal1 = *pSrc++;
    
                                           
        if (out > maxVal1)
        {
                                                       
          out = maxVal1;
          outIndex = blockSize - blkCnt ;
        }
    
                                        
        blkCnt--;
      }
  }

                                                                        
  *pResult = out;
  *pIndex = outIndex;
}
#else
void arm_min_f32(
  const float32_t * pSrc,
        uint32_t blockSize,
        float32_t * pResult,
        uint32_t * pIndex)
{
        float32_t minVal, out;                                                                             
        uint32_t blkCnt, outIndex;                                       

#if defined (ARM_MATH_LOOPUNROLL)
        uint32_t index;                                                            
#endif

                                       
  outIndex = 0U;

                                                                          
  out = *pSrc++;

#if defined (ARM_MATH_LOOPUNROLL)
                                          
  index = 0U;

                                                   
  blkCnt = (blockSize - 1U) >> 2U;

  while (blkCnt > 0U)
  {
                                                                 
    minVal = *pSrc++;

                                       
    if (out > minVal)
    {
                                                   
      out = minVal;
      outIndex = index + 1U;
    }

    minVal = *pSrc++;
    if (out > minVal)
    {
      out = minVal;
      outIndex = index + 2U;
    }

    minVal = *pSrc++;
    if (out > minVal)
    {
      out = minVal;
      outIndex = index + 3U;
    }

    minVal = *pSrc++;
    if (out > minVal)
    {
      out = minVal;
      outIndex = index + 4U;
    }

    index += 4U;

                                
    blkCnt--;
  }

                                                 
  blkCnt = (blockSize - 1U) % 4U;

#else

                                                
  blkCnt = (blockSize - 1U);

#endif                                        

  while (blkCnt > 0U)
  {
                                                                     
    minVal = *pSrc++;

                                       
    if (out > minVal)
    {
                                                   
      out = minVal;
      outIndex = blockSize - blkCnt;
    }

                                
    blkCnt--;
  }

                                                                        
  *pResult = out;
  *pIndex = outIndex;
}
#endif                                 

   
                     
   
