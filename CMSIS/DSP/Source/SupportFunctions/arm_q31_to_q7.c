                                                                         
                                  
                                
                                                                     
  
                               
                       
  
                                   
                                                                          
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

   
                       
   

   
                      
    
   

   
                                                                      
                                                          
                                                          
                                                            
                     

                        
                                                                   
       
                                                           
        
   

void arm_q31_to_q7(
  const q31_t * pSrc,
        q7_t * pDst,
        uint32_t blockSize)
{
        uint32_t blkCnt;                                                 
  const q31_t *pIn = pSrc;                                                 

#if defined (ARM_MATH_LOOPUNROLL)

  q7_t out1, out2, out3, out4;

                                                   
  blkCnt = blockSize >> 2U;

  while (blkCnt > 0U)
  {
                              

                                                                       

    out1 = (q7_t) (*pIn++ >> 24);
    out2 = (q7_t) (*pIn++ >> 24);
    out3 = (q7_t) (*pIn++ >> 24);
    out4 = (q7_t) (*pIn++ >> 24);
    write_q7x4_ia (&pDst, __PACKq7(out1, out2, out3, out4));

                                
    blkCnt--;
  }

                                                 
  blkCnt = blockSize % 0x4U;

#else

                                                
  blkCnt = blockSize;

#endif                                        

  while (blkCnt > 0U)
  {
                              

                                                                       
    *pDst++ = (q7_t) (*pIn++ >> 24);

                                
    blkCnt--;
  }

}

   
                          
   
