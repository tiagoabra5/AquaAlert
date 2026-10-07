                                                                         
                                  
                             
                                             
  
                               
                       
  
                                   
                                                                          
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

   
                     
   

   
                 
    
   

   
                                              
                                                      
                                                             
                                                       
                                                                
                     
   

void arm_max_q7(
  const q7_t * pSrc,
        uint32_t blockSize,
        q7_t * pResult,
        uint32_t * pIndex)
{
        q7_t maxVal, out;                                                                                  
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
                                                                 
    maxVal = *pSrc++;

                                       
    if (out < maxVal)
    {
                                                   
      out = maxVal;
      outIndex = index + 1U;
    }

    maxVal = *pSrc++;
    if (out < maxVal)
    {
      out = maxVal;
      outIndex = index + 2U;
    }

    maxVal = *pSrc++;
    if (out < maxVal)
    {
      out = maxVal;
      outIndex = index + 3U;
    }

    maxVal = *pSrc++;
    if (out < maxVal)
    {
      out = maxVal;
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
                                                                     
    maxVal = *pSrc++;

                                       
    if (out < maxVal)
    {
                                                   
      out = maxVal;
      outIndex = blockSize - blkCnt;
    }

                                
    blkCnt--;
  }

                                                                        
  *pResult = out;
  *pIndex = outIndex;
}

   
                     
   
