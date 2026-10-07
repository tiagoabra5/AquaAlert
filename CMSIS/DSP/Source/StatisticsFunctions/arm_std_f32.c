                                                                         
                                  
                              
                                                                              
  
                               
                       
  
                                   
                                                                          
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
void arm_std_f32(
  const float32_t * pSrc,
        uint32_t blockSize,
        float32_t * pResult)
{
  float32_t var;
  arm_var_f32(pSrc,blockSize,&var);
  arm_sqrt_f32(var, pResult);
}
#else
void arm_std_f32(
  const float32_t * pSrc,
        uint32_t blockSize,
        float32_t * pResult)
{
        uint32_t blkCnt;                                                 
        float32_t sum = 0.0f;                                                        
        float32_t sumOfSquares = 0.0f;                                     
        float32_t in;                                                                               

#ifndef ARM_MATH_CM0_FAMILY
        float32_t meanOfSquares, mean, squareOfMean;                            
#else
        float32_t squareOfSum;                                            
        float32_t var;                                                                 
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
                                                                               
                                                

    in = *pSrc++;
                                                                                        
    sumOfSquares += in * in;
                                                                    
    sum += in;

    in = *pSrc++;
    sumOfSquares += in * in;
    sum += in;

    in = *pSrc++;
    sumOfSquares += in * in;
    sum += in;

    in = *pSrc++;
    sumOfSquares += in * in;
    sum += in;

                                
    blkCnt--;
  }

                                                 
  blkCnt = blockSize % 0x4U;

#else

                                                
  blkCnt = blockSize;

#endif                                        

  while (blkCnt > 0U)
  {
                                                                               
                                                

    in = *pSrc++;
                                                                                        
    sumOfSquares += ( in * in);
                                                                    
    sum += in;

                                
    blkCnt--;
  }

#ifndef ARM_MATH_CM0_FAMILY

                                                                                        
  meanOfSquares = sumOfSquares / ((float32_t) blockSize - 1.0f);

                                        
  mean = sum / (float32_t) blockSize;

                              
  squareOfMean = (mean * mean) * (((float32_t) blockSize) /
                                  ((float32_t) blockSize - 1.0f));

                                                                  
  arm_sqrt_f32((meanOfSquares - squareOfMean), pResult);

#else
                                        

                             
  squareOfSum = ((sum * sum) / (float32_t) blockSize);

                        
  var = ((sumOfSquares - squareOfSum) / (float32_t) (blockSize - 1.0f));

                                                                  
  arm_sqrt_f32(var, pResult);

#endif                                  

}
#endif                                 

   
                     
   
