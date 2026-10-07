                                                                         
                                  
                                
                                                    
  
                               
                       
  
                                   
                                                                          
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

   
                    
   

   
                        
    
   

   
                                                     
                                                      
                                                                 
                                                                 
                                                       
                                                            
                     

                                              
                                                                                                    
                                                                                                                               
   

void arm_scale_q31(
  const q31_t *pSrc,
        q31_t scaleFract,
        int8_t shift,
        q31_t *pDst,
        uint32_t blockSize)
{
        uint32_t blkCnt;                                                 
        q31_t in, out;                                                          
        int8_t kShift = shift + 1;                                                       
        int8_t sign = (kShift & 0x80);

#if defined (ARM_MATH_LOOPUNROLL)

                                                   
  blkCnt = blockSize >> 2U;

  if (sign == 0U)
  {
    while (blkCnt > 0U)
    {
                         

                                                               
      in = *pSrc++;                                                            
      in = ((q63_t) in * scaleFract) >> 32;                                              
      out = in << kShift;                                              
      if (in != (out >> kShift))                                            
        out = 0x7FFFFFFF ^ (in >> 31);
      *pDst++ = out;                                                             

      in = *pSrc++;
      in = ((q63_t) in * scaleFract) >> 32;
      out = in << kShift;
      if (in != (out >> kShift))
        out = 0x7FFFFFFF ^ (in >> 31);
      *pDst++ = out;

      in = *pSrc++;
      in = ((q63_t) in * scaleFract) >> 32;
      out = in << kShift;
      if (in != (out >> kShift))
        out = 0x7FFFFFFF ^ (in >> 31);
      *pDst++ = out;

      in = *pSrc++;
      in = ((q63_t) in * scaleFract) >> 32;
      out = in << kShift;
      if (in != (out >> kShift))
        out = 0x7FFFFFFF ^ (in >> 31);
      *pDst++ = out;

                                  
      blkCnt--;
    }
  }
  else
  {
    while (blkCnt > 0U)
    {
                         

                                                               
      in = *pSrc++;                                                                  
      in = ((q63_t) in * scaleFract) >> 32;                                              
      out = in >> -kShift;                                             
      *pDst++ = out;                                                             

      in = *pSrc++;
      in = ((q63_t) in * scaleFract) >> 32;
      out = in >> -kShift;
      *pDst++ = out;

      in = *pSrc++;
      in = ((q63_t) in * scaleFract) >> 32;
      out = in >> -kShift;
      *pDst++ = out;

      in = *pSrc++;
      in = ((q63_t) in * scaleFract) >> 32;
      out = in >> -kShift;
      *pDst++ = out;

                                  
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
                         

                                                               
      in = *pSrc++;
      in = ((q63_t) in * scaleFract) >> 32;
      out = in << kShift;
      if (in != (out >> kShift))
          out = 0x7FFFFFFF ^ (in >> 31);
      *pDst++ = out;

                                  
      blkCnt--;
    }
  }
  else
  {
    while (blkCnt > 0U)
    {
                         

                                                               
      in = *pSrc++;
      in = ((q63_t) in * scaleFract) >> 32;
      out = in >> -kShift;
      *pDst++ = out;

                                  
      blkCnt--;
    }
  }

}

   
                            
   
