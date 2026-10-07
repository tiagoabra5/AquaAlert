/*
 * Copyright (C) 2010-2018 Arm Limited or its affiliates. All rights reserved.
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

                                                                         
                                 
                                  
                                                                      
  
                              
                        
  
                                    
  
                                                                          

#include "arm_nnfunctions.h"

       
                            
   

   
                          
     
   


   
                                                                        
                                                                   
                                                                    
                                                              
                                                                  
                                                                  
                
  
                                        
       
                                           
                                                                                
   

void arm_nn_mult_q15(
  q15_t * pSrcA,
  q15_t * pSrcB,
  q15_t * pDst,
  const uint16_t out_shift,
  uint32_t blockSize)
{
  uint32_t blkCnt;                                                  

#if defined (ARM_MATH_DSP)

                                                    
  q31_t inA1, inA2, inB1, inB2;                                                 
  q15_t out1, out2, out3, out4;                                                  
  q31_t mul1, mul2, mul3, mul4;                                           

                      
  blkCnt = blockSize >> 2U;

                                                                                    
                                                                   
  while (blkCnt > 0U)
  {
                                                 
    inA1 = *__SIMD32(pSrcA)++;
                                                 
    inB1 = *__SIMD32(pSrcB)++;
                                                 
    inA2 = *__SIMD32(pSrcA)++;
                                                 
    inB2 = *__SIMD32(pSrcB)++;

                                          
    mul1 = (q31_t) ((q15_t) (inA1 >> 16) * (q15_t) (inB1 >> 16));
    mul2 = (q31_t) ((q15_t) inA1 * (q15_t) inB1);
    mul3 = (q31_t) ((q15_t) (inA2 >> 16) * (q15_t) (inB2 >> 16));
    mul4 = (q31_t) ((q15_t) inA2 * (q15_t) inB2);

                                   
    out1 = (q15_t) __SSAT((mul1 + NN_ROUND(out_shift)) >> out_shift, 16);
    out2 = (q15_t) __SSAT((mul2 + NN_ROUND(out_shift)) >> out_shift, 16);
    out3 = (q15_t) __SSAT((mul3 + NN_ROUND(out_shift)) >> out_shift, 16);
    out4 = (q15_t) __SSAT((mul4 + NN_ROUND(out_shift)) >> out_shift, 16);

                          
#ifndef ARM_MATH_BIG_ENDIAN

    *__SIMD32(pDst)++ = __PKHBT(out2, out1, 16);
    *__SIMD32(pDst)++ = __PKHBT(out4, out3, 16);

#else

    *__SIMD32(pDst)++ = __PKHBT(out2, out1, 16);
    *__SIMD32(pDst)++ = __PKHBT(out4, out3, 16);

#endif                                  

                                              
    blkCnt--;
  }

                                                                                        
                                   
  blkCnt = blockSize % 0x4U;

#else

                                        

                                                
  blkCnt = blockSize;

#endif                                 


  while (blkCnt > 0U)
  {
                   
                                                                            
    *pDst++ = (q15_t) __SSAT((((q31_t) (*pSrcA++) * (*pSrcB++) + NN_ROUND(out_shift)) >> out_shift), 16);

                                              
    blkCnt--;
  }
}

   
                              
   

