                                                                         
                                  
                                
                                                                                  
  
                               
                       
  
                                   
                                                                          
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

   
                    
   
   
                                   

                                                                            
                                                               
                                   

       
                                                       
        

                                                                                            
                                                                                             

                                                                                
                                               
   

   
                        
    
   

   
                                                                                
                                                      
                                                                                                                  
                                                       
                                                           
                     

                                              
                                                           
                                                                                                    
   

void arm_shift_q31(
  const q31_t * pSrc,
        int8_t shiftBits,
        q31_t * pDst,
        uint32_t blockSize)
{
        uint32_t blkCnt;                                                 
        uint8_t sign = (shiftBits & 0x80);                                    

#if defined (ARM_MATH_LOOPUNROLL)

  q31_t in, out;                                                          

                                                   
  blkCnt = blockSize >> 2U;

                                                                          
  if (sign == 0U)
  {
    while (blkCnt > 0U)
    {
                              

                                                               
      in = *pSrc++;
      out = in << shiftBits;
      if (in != (out >> shiftBits))
        out = 0x7FFFFFFF ^ (in >> 31);
      *pDst++ = out;

      in = *pSrc++;
      out = in << shiftBits;
      if (in != (out >> shiftBits))
        out = 0x7FFFFFFF ^ (in >> 31);
      *pDst++ = out;

      in = *pSrc++;
      out = in << shiftBits;
      if (in != (out >> shiftBits))
        out = 0x7FFFFFFF ^ (in >> 31);
      *pDst++ = out;

      in = *pSrc++;
      out = in << shiftBits;
      if (in != (out >> shiftBits))
        out = 0x7FFFFFFF ^ (in >> 31);
      *pDst++ = out;

                                  
      blkCnt--;
    }
  }
  else
  {
    while (blkCnt > 0U)
    {
                              

                                                                
      *pDst++ = (*pSrc++ >> -shiftBits);
      *pDst++ = (*pSrc++ >> -shiftBits);
      *pDst++ = (*pSrc++ >> -shiftBits);
      *pDst++ = (*pSrc++ >> -shiftBits);

                                  
      blkCnt--;
    }
  }

                                                 
  blkCnt = blockSize % 0x4U;

#else

                                                
  blkCnt = blockSize;

#endif                                        

                                                                          
  if (sign == 0U)
  {
    while (blkCnt > 0U)
    {
                              

                                                               
      *pDst++ = clip_q63_to_q31((q63_t) *pSrc++ << shiftBits);

                                  
      blkCnt--;
    }
  }
  else
  {
    while (blkCnt > 0U)
    {
                              

                                                               
      *pDst++ = (*pSrc++ >> -shiftBits);

                                  
      blkCnt--;
    }
  }

}

   
                            
   
