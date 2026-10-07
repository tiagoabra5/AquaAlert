                                                                         
                                  
                                    
                                                    
  
                               
                       
  
                                   
                                                                          
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

   
                      
   

   
                         
    
   

   
                                    
                                                   
                                                                   
                                                                  
                                                              
                                 
                                                                       
                                                                           

                                              
                                                                                                    
                                                                                                                               
   

arm_status arm_mat_scale_q15(
  const arm_matrix_instance_q15 * pSrc,
        q15_t                     scaleFract,
        int32_t                   shift,
        arm_matrix_instance_q15 * pDst)
{
        q15_t *pIn = pSrc->pData;                                                     
        q15_t *pOut = pDst->pData;                                                     
        uint32_t numSamples;                                                                       
        uint32_t blkCnt;                                                 
        arm_status status;                                                           
        int32_t kShift = 15 - shift;                                                           

#if defined (ARM_MATH_LOOPUNROLL) && defined (ARM_MATH_DSP)
        q31_t inA1, inA2;
        q31_t out1, out2, out3, out4;                                                  
        q15_t in1, in2, in3, in4;                                                     
#endif

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
                               

#if defined (ARM_MATH_DSP)
                                                        
      inA1 = read_q15x2_ia ((q15_t **) &pIn);
      inA2 = read_q15x2_ia ((q15_t **) &pIn);

                                                             
                                                  
      out1 = (q31_t) ((q15_t) (inA1 >> 16) * scaleFract);
      out2 = (q31_t) ((q15_t) (inA1      ) * scaleFract);
      out3 = (q31_t) ((q15_t) (inA2 >> 16) * scaleFract);
      out4 = (q31_t) ((q15_t) (inA2      ) * scaleFract);

                          
      out1 = out1 >> kShift;
      out2 = out2 >> kShift;
      out3 = out3 >> kShift;
      out4 = out4 >> kShift;

                               
      in1 = (q15_t) (__SSAT(out1, 16));
      in2 = (q15_t) (__SSAT(out2, 16));
      in3 = (q15_t) (__SSAT(out3, 16));
      in4 = (q15_t) (__SSAT(out4, 16));

                                       
      write_q15x2_ia (&pOut, __PKHBT(in2, in1, 16));
      write_q15x2_ia (&pOut, __PKHBT(in4, in3, 16));

#else
      *pOut++ = (q15_t) (__SSAT(((q31_t) (*pIn++) * scaleFract) >> kShift, 16));
      *pOut++ = (q15_t) (__SSAT(((q31_t) (*pIn++) * scaleFract) >> kShift, 16));
      *pOut++ = (q15_t) (__SSAT(((q31_t) (*pIn++) * scaleFract) >> kShift, 16));
      *pOut++ = (q15_t) (__SSAT(((q31_t) (*pIn++) * scaleFract) >> kShift, 16));
#endif

                                  
      blkCnt--;
    }

                                                   
    blkCnt = numSamples % 0x4U;

#else

                                                  
    blkCnt = numSamples;

#endif                                        

    while (blkCnt > 0U)
    {
                               

                                                                   
      *pOut++ = (q15_t) (__SSAT(((q31_t) (*pIn++) * scaleFract) >> kShift, 16));

                                  
      blkCnt--;
    }

                                        
    status = ARM_MATH_SUCCESS;
  }

                             
  return (status);
}

   
                             
   
