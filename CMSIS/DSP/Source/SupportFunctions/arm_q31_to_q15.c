                                                                         
                                  
                                 
                                                                      
  
                               
                       
  
                                   
                                                                          
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

   
                       
   

   
                      
    
   

   
                                                                       
                                                          
                                                           
                                                            
                     

                        
                                                                   
       
                                                            
        
   

void arm_q31_to_q15(
  const q31_t * pSrc,
        q15_t * pDst,
        uint32_t blockSize)
{
        uint32_t blkCnt;                                                 
  const q31_t *pIn = pSrc;                                                 

#if defined (ARM_MATH_LOOPUNROLL) && defined (ARM_MATH_DSP)
        q31_t in1, in2, in3, in4;
        q31_t out1, out2;
#endif

#if defined (ARM_MATH_LOOPUNROLL)

                                                   
  blkCnt = blockSize >> 2U;

  while (blkCnt > 0U)
  {
                               

                                                                        
#if defined (ARM_MATH_DSP)

    in1 = *pIn++;
    in2 = *pIn++;
    in3 = *pIn++;
    in4 = *pIn++;

                                                              
#ifndef ARM_MATH_BIG_ENDIAN
    out1 = __PKHTB(in2, in1, 16);
    out2 = __PKHTB(in4, in3, 16);
#else
    out1 = __PKHTB(in1, in2, 16);
    out2 = __PKHTB(in3, in4, 16);
#endif                                 

    write_q15x2_ia (&pDst, out1);
    write_q15x2_ia (&pDst, out2);

#else

    *pDst++ = (q15_t) (*pIn++ >> 16);
    *pDst++ = (q15_t) (*pIn++ >> 16);
    *pDst++ = (q15_t) (*pIn++ >> 16);
    *pDst++ = (q15_t) (*pIn++ >> 16);

#endif                                 

                                
    blkCnt--;
  }

                                                 
  blkCnt = blockSize % 0x4U;

#else

                                                
  blkCnt = blockSize;

#endif                                        

  while (blkCnt > 0U)
  {
                               

                                                                        
    *pDst++ = (q15_t) (*pIn++ >> 16);

                                
    blkCnt--;
  }

}

   
                          
   
