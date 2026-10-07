                                                                         
                                  
                                  
                               
  
                               
                       
  
                                   
                                                                          
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

   
                    
   

   
                          
    
   

   
                                           
                                                            
                                                             
                                                            
                                                       
                     

                                              
                                                                                            
                                                                       
                                                                                                    
                                                                
                                                        
   

void arm_dot_prod_q7(
  const q7_t * pSrcA,
  const q7_t * pSrcB,
        uint32_t blockSize,
        q31_t * result)
{
        uint32_t blkCnt;                                                 
        q31_t sum = 0;                                                                

#if defined (ARM_MATH_LOOPUNROLL)

#if defined (ARM_MATH_DSP)
  q31_t input1, input2;                                                   
  q31_t inA1, inA2, inB1, inB2;                                           
#endif

                                                   
  blkCnt = blockSize >> 2U;

  while (blkCnt > 0U)
  {
                                                                                          

#if defined (ARM_MATH_DSP)
                                               
    input1 = read_q7x4_ia ((q7_t **) &pSrcA);
                                               
    input2 = read_q7x4_ia ((q7_t **) &pSrcB);

                                                   
    inA1 = __SXTB16(__ROR(input1, 8));
                                       
    inA2 = __SXTB16(input1);
                                                   
    inB1 = __SXTB16(__ROR(input2, 8));
                                       
    inB2 = __SXTB16(input2);

                                                       
    sum = __SMLAD(inA1, inB1, sum);
    sum = __SMLAD(inA2, inB2, sum);
#else
    sum += (q31_t) ((q15_t) *pSrcA++ * *pSrcB++);
    sum += (q31_t) ((q15_t) *pSrcA++ * *pSrcB++);
    sum += (q31_t) ((q15_t) *pSrcA++ * *pSrcB++);
    sum += (q31_t) ((q15_t) *pSrcA++ * *pSrcB++);
#endif

                                
    blkCnt--;
  }

                                                 
  blkCnt = blockSize % 0x4U;

#else

                                                
  blkCnt = blockSize;

#endif                                        

  while (blkCnt > 0U)
  {
                                                                                          

                                                                       
                            
                                              
       
    sum += (q31_t) ((q15_t) *pSrcA++ * *pSrcB++);
        

                                
    blkCnt--;
  }

                                                          
  *result = sum;
}

   
                              
   
