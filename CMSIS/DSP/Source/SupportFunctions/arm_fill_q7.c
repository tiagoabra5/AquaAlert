                                                                         
                                  
                              
                                                        
  
                               
                       
  
                                   
                                                                          
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

   
                       
   

   
                  
    
   

   
                                                         
                                                    
                                                   
                                                            
                     
   

void arm_fill_q7(
  q7_t value,
  q7_t * pDst,
  uint32_t blockSize)
{
  uint32_t blkCnt;                                                 

#if defined (ARM_MATH_LOOPUNROLL)
  q31_t packedValue;                                                          

                                                                      
  packedValue = __PACKq7(value, value, value, value);

                                                   
  blkCnt = blockSize >> 2U;

  while (blkCnt > 0U)
  {
                   

                                  
    write_q7x4_ia (&pDst, packedValue);

                                
    blkCnt--;
  }

                                                 
  blkCnt = blockSize % 0x4U;

#else

                                                
  blkCnt = blockSize;

#endif                                        

  while (blkCnt > 0U)
  {
                   

                                          
    *pDst++ = value;

                                
    blkCnt--;
  }
}

   
                      
   
