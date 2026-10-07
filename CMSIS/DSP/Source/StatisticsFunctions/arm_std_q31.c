                                                                         
                                  
                              
                                                                   
  
                               
                       
  
                                   
                                                                          
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

   
                     
   

   
                 
    
   

   
                                                                    
                                                       
                                                              
                                                                   
                     

                                              
                                                                                    
                                                                                               
                                                                                           
                                                                                                       
                                                     
                                                                    
                                                                                        
                                                                                                 
                                                                                                      
                                                                      
                                                                                                           
   

void arm_std_q31(
  const q31_t * pSrc,
        uint32_t blockSize,
        q31_t * pResult)
{
        uint32_t blkCnt;                                                 
        q63_t sum = 0;                                                  
        q63_t meanOfSquares, squareOfMean;                                                    
        q63_t sumOfSquares = 0;                                            
        q31_t in;                                                                                   

  if (blockSize <= 1U)
  {
    *pResult = 0;
    return;
  }

#if defined (ARM_MATH_LOOPUNROLL)

                                                   
  blkCnt = blockSize >> 2U;

  while (blkCnt > 0U)
  {
                                                                               
                                                

    in = *pSrc++ >> 8U;
                                                                                        
    sumOfSquares += ((q63_t) (in) * (in));
                                                                    
    sum += in;

    in = *pSrc++ >> 8U;
    sumOfSquares += ((q63_t) (in) * (in));
    sum += in;

    in = *pSrc++ >> 8U;
    sumOfSquares += ((q63_t) (in) * (in));
    sum += in;

    in = *pSrc++ >> 8U;
    sumOfSquares += ((q63_t) (in) * (in));
    sum += in;

                                
    blkCnt--;
  }

                                                 
  blkCnt = blockSize % 0x4U;

#else

                                                
  blkCnt = blockSize;

#endif                                        

  while (blkCnt > 0U)
  {
                                                                               
                                                

    in = *pSrc++ >> 8U;
                                                                                        
    sumOfSquares += ((q63_t) (in) * (in));
                                                                    
    sum += in;

                                
    blkCnt--;
  }

                                                                                        
  meanOfSquares = (sumOfSquares / (q63_t)(blockSize - 1U));

                              
  squareOfMean = ( sum * sum / (q63_t)(blockSize * (blockSize - 1U)));

                                                                  
  arm_sqrt_q31((meanOfSquares - squareOfMean) >> 15U, pResult);
}

   
                     
   
