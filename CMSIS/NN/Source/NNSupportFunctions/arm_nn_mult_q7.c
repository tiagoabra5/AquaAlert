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

       
                            
   

   
                          
     
   

   
                                                                        
                                                                   
                                                                    
                                                              
                                                                  
                                                                  
                
  
                                        
       
                                           
                                                                           
   

void arm_nn_mult_q7(
  q7_t * pSrcA,
  q7_t * pSrcB,
  q7_t * pDst,
  const uint16_t out_shift,
  uint32_t blockSize)
{
  uint32_t blkCnt;                                                  

#if defined (ARM_MATH_DSP)

                                                    
  q7_t out1, out2, out3, out4;                                                                 

                      
  blkCnt = blockSize >> 2U;

                                                                                    
                                                                   
  while (blkCnt > 0U)
  {
                   
                                                                          
    out1 = (q7_t) __SSAT((((q15_t) (*pSrcA++) * (*pSrcB++) + NN_ROUND(out_shift)) >> out_shift), 8);
    out2 = (q7_t) __SSAT((((q15_t) (*pSrcA++) * (*pSrcB++) + NN_ROUND(out_shift)) >> out_shift), 8);
    out3 = (q7_t) __SSAT((((q15_t) (*pSrcA++) * (*pSrcB++) + NN_ROUND(out_shift)) >> out_shift), 8);
    out4 = (q7_t) __SSAT((((q15_t) (*pSrcA++) * (*pSrcB++) + NN_ROUND(out_shift)) >> out_shift), 8);

                                                                                            
    *__SIMD32(pDst)++ = __PACKq7(out1, out2, out3, out4);

                                              
    blkCnt--;
  }

                                                                                        
                                   
  blkCnt = blockSize % 0x4U;

#else

                                        

                                                
  blkCnt = blockSize;

#endif                                 


  while (blkCnt > 0U)
  {
                   
                                                                            
    *pDst++ = (q7_t) __SSAT((((q15_t) (*pSrcA++) * (*pSrcB++) + NN_ROUND(out_shift)) >> out_shift), 8);

                                              
    blkCnt--;
  }
}

   
                              
   
