                                                                         
                                  
                               
                                                                  
  
                               
                       
  
                                   
                                                                          
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

   
                     
   

   
                   
    
   

   
                                                                   
                                                      
                                                             
                                                                  
                     

                                              
                                                                                   
                                                          
                                                                             
                                                                                        
                                                                                               
                                                                                  
                                                                 
   

void arm_power_q7(
  const q7_t * pSrc,
        uint32_t blockSize,
        q31_t * pResult)
{
        uint32_t blkCnt;                                                 
        q31_t sum = 0;                                                               
        q7_t in;                                                                                    

#if defined (ARM_MATH_LOOPUNROLL) && defined (ARM_MATH_DSP)
        q31_t in32;                                                                                        
        q31_t in1, in2;                                                                              
#endif

#if defined (ARM_MATH_LOOPUNROLL)

                                                   
  blkCnt = blockSize >> 2U;

  while (blkCnt > 0U)
  {
                                                                               

                                                                      
#if defined (ARM_MATH_DSP)
    in32 = read_q7x4_ia ((q7_t **) &pSrc);

    in1 = __SXTB16(__ROR(in32, 8));
    in2 = __SXTB16(in32);

                                                       
    sum = __SMLAD(in1, in1, sum);
    sum = __SMLAD(in2, in2, sum);
#else
    in = *pSrc++;
    sum += ((q15_t) in * in);

    in = *pSrc++;
    sum += ((q15_t) in * in);

    in = *pSrc++;
    sum += ((q15_t) in * in);

    in = *pSrc++;
    sum += ((q15_t) in * in);
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
    sum += ((q15_t) in * in);

                                
    blkCnt--;
  }

                                    
  *pResult = sum;
}

   
                       
   
