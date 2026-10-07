                                                                         
                                  
                                    
                                                    
  
                               
                       
  
                                   
                                                                          
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

   
                      
   

   
                         
    
   

   
                                    
                                                   
                                                                   
                                                                  
                                                              
                                 
                                                                       
                                                                           

                                              
                                                                                                    
                                                                                                                            
   

arm_status arm_mat_scale_q31(
  const arm_matrix_instance_q31 * pSrc,
        q31_t                     scaleFract,
        int32_t                   shift,
        arm_matrix_instance_q31 * pDst)
{
  q31_t *pIn = pSrc->pData;                                                     
  q31_t *pOut = pDst->pData;                                                     
  uint32_t numSamples;                                                                       
  uint32_t blkCnt;                                                 
  arm_status status;                                                           
  int32_t kShift = shift + 1;                                                      
  q31_t in, out;                                                          

#ifdef ARM_MATH_MATRIX_CHECK

                                           
  if ((pSrc->numRows != pDst->numRows) ||
      (pSrc->numCols != pDst->numCols)   )
  {
                                              
    status = ARM_MATH_SIZE_MISMATCH;
  }
  else

#endif                                   

  {
                                                 
    numSamples = (uint32_t) pSrc->numRows * pSrc->numCols;

#if defined (ARM_MATH_LOOPUNROLL)

                                                     
    blkCnt = numSamples >> 2U;

    while (blkCnt > 0U)
    {
                               

                                                                   
      in = *pIn++;                                                                   
      in = ((q63_t) in * scaleFract) >> 32;                                              
      out = in << kShift;                                              
      if (in != (out >> kShift))                                              
        out = 0x7FFFFFFF ^ (in >> 31);
      *pOut++ = out;                                                             

      in = *pIn++;
      in = ((q63_t) in * scaleFract) >> 32;
      out = in << kShift;
      if (in != (out >> kShift))
        out = 0x7FFFFFFF ^ (in >> 31);
      *pOut++ = out;

      in = *pIn++;
      in = ((q63_t) in * scaleFract) >> 32;
      out = in << kShift;
      if (in != (out >> kShift))
        out = 0x7FFFFFFF ^ (in >> 31);
      *pOut++ = out;

      in = *pIn++;
      in = ((q63_t) in * scaleFract) >> 32;
      out = in << kShift;
      if (in != (out >> kShift))
        out = 0x7FFFFFFF ^ (in >> 31);
      *pOut++ = out;

                                  
      blkCnt--;
    }

                                                   
    blkCnt = numSamples % 0x4U;

#else

                                                  
    blkCnt = numSamples;

#endif                                        

    while (blkCnt > 0U)
    {
                               

                                                                   
      in = *pIn++;
      in = ((q63_t) in * scaleFract) >> 32;
      out = in << kShift;
      if (in != (out >> kShift))
        out = 0x7FFFFFFF ^ (in >> 31);
      *pOut++ = out;

                                  
      blkCnt--;
    }

                                        
    status = ARM_MATH_SUCCESS;
  }

                             
  return (status);
}

   
                             
   
