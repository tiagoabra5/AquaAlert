                                                                         
                                  
                               
                                           
  
                               
                       
  
                                   
                                                                          
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

   
                     
   

   
                  
    
   

   
                                            
                                                      
                                                             
                                                    
                     

                                              
                                                                                   
                                                                                         
                                               
                                                                                    
                                                                      
                                                                                          
   

void arm_mean_q15(
  const q15_t * pSrc,
        uint32_t blockSize,
        q15_t * pResult)
{
        uint32_t blkCnt;                                                 
        q31_t sum = 0;                                                               

#if defined (ARM_MATH_LOOPUNROLL)
        q31_t in;
#endif

#if defined (ARM_MATH_LOOPUNROLL)

                                                   
  blkCnt = blockSize >> 2U;

  while (blkCnt > 0U)
  {
                                                         
    in = read_q15x2_ia ((q15_t **) &pSrc);
    sum += ((in << 16U) >> 16U);
    sum +=  (in >> 16U);

    in = read_q15x2_ia ((q15_t **) &pSrc);
    sum += ((in << 16U) >> 16U);
    sum +=  (in >> 16U);

                                    
    blkCnt--;
  }

                                                 
  blkCnt = blockSize % 0x4U;

#else

                                                
  blkCnt = blockSize;

#endif                                        

  while (blkCnt > 0U)
  {
                                                         
    sum += *pSrc++;

                                
    blkCnt--;
  }

                                                                    
                                   
  *pResult = (q15_t) (sum / (int32_t) blockSize);
}

   
                      
   
