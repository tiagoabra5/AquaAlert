                                                                         
                                  
                              
                                                             
  
                               
                       
  
                                   
                                                                          
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

   
                     
   

   
                 
    
   

   
                                                                    
                                                      
                                                             
                                                                  
                     

                                              
                                                                                   
                                                           
                                                                             
                                                                                              
                                                                                               
                                                                                  
                                                                                                 
                                                                                
   

void arm_std_q15(
  const q15_t * pSrc,
        uint32_t blockSize,
        q15_t * pResult)
{
        uint32_t blkCnt;                                                 
        q31_t sum = 0;                                                  
        q31_t meanOfSquares, squareOfMean;                                                    
        q63_t sumOfSquares = 0;                                            
        q15_t in;                                                                                   

#if defined (ARM_MATH_LOOPUNROLL) && defined (ARM_MATH_DSP)
  q31_t in32;                                                                                 
#endif

  if (blockSize <= 1U)
  {
    *pResult = 0;
    return;
  }

#if defined (ARM_MATH_LOOPUNROLL)

                                                   
  blkCnt = blockSize >> 2U;

  while (blkCnt > 0U)
  {
                                                                               
                                                

                                                                                        
                                                                    
#if defined (ARM_MATH_DSP)
    in32 = read_q15x2_ia ((q15_t **) &pSrc);
    sumOfSquares = __SMLALD(in32, in32, sumOfSquares);
    sum += ((in32 << 16U) >> 16U);
    sum +=  (in32 >> 16U);

    in32 = read_q15x2_ia ((q15_t **) &pSrc);
    sumOfSquares = __SMLALD(in32, in32, sumOfSquares);
    sum += ((in32 << 16U) >> 16U);
    sum +=  (in32 >> 16U);
#else
    in = *pSrc++;
    sumOfSquares += (in * in);
    sum += in;

    in = *pSrc++;
    sumOfSquares += (in * in);
    sum += in;

    in = *pSrc++;
    sumOfSquares += (in * in);
    sum += in;

    in = *pSrc++;
    sumOfSquares += (in * in);
    sum += in;
#endif                                 

                                
    blkCnt--;
  }

                                                 
  blkCnt = blockSize % 0x4U;

#else

                                                
  blkCnt = blockSize;

#endif                                        

  while (blkCnt > 0U)
  {
                                                                               
                                                

    in = *pSrc++;
                                                                                        
    sumOfSquares += (in * in);
                                                                    
    sum += in;

                                
    blkCnt--;
  }

                                                                                        
  meanOfSquares = (q31_t) (sumOfSquares / (q63_t)(blockSize - 1U));

                              
  squareOfMean = (q31_t) ((q63_t) sum * sum / (q63_t)(blockSize * (blockSize - 1U)));

                                                 
                                                                  
  arm_sqrt_q15(__SSAT((meanOfSquares - squareOfMean) >> 15U, 16U), pResult);
}

   
                     
   
