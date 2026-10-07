                                                                         
                                  
                                    
                                                               
  
                               
                       
  
                                   
                                                                          
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

   
                      
   

   
                                    

                                                                                           
                                     
                                                                

                                                                                           

                                                                                
                                                                                                 
                                                                   
                                                             
       
                                   
        
   

   
                         
    
   

   
                                               
                                                  
                                                      
                                                             
                                 
                                                                       
                                                                           
   
#if defined(ARM_MATH_NEON_EXPERIMENTAL)
arm_status arm_mat_scale_f32(
  const arm_matrix_instance_f32 * pSrc,
  float32_t scale,
  arm_matrix_instance_f32 * pDst)
{
  float32_t *pIn = pSrc->pData;                                                 
  float32_t *pOut = pDst->pData;                                                 
  uint32_t numSamples;                                                                       
  uint32_t blkCnt;                                                  
  arm_status status;                                                               


  float32_t in1, in2, in3, in4;                                           
  float32_t out1, out2, out3, out4;                                       


#ifdef ARM_MATH_MATRIX_CHECK
                                           
  if ((pSrc->numRows != pDst->numRows) || (pSrc->numCols != pDst->numCols))
  {
                                              
    status = ARM_MATH_SIZE_MISMATCH;
  }
  else
#endif                                         
  {
    float32x4_t vec1;
    float32x4_t res;

                                                     
    numSamples = (uint32_t) pSrc->numRows * pSrc->numCols;

    blkCnt = numSamples >> 2;

                                   
                                                                     
    while (blkCnt > 0U)
    {
                                   
                                                                     
      vec1 = vld1q_f32(pIn);
      res = vmulq_f32(vec1, vdupq_n_f32(scale));
      vst1q_f32(pOut, res);

                                                   
      pIn += 4U;
      pOut += 4U;

                                                 
      blkCnt--;
    }

                                                                                           
                                     
    blkCnt = numSamples % 0x4U;

    while (blkCnt > 0U)
    {
                                   
                                                             
      *pOut++ = (*pIn++) * scale;

                                      
      blkCnt--;
    }

                                        
    status = ARM_MATH_SUCCESS;
  }

                             
  return (status);
}
#else
arm_status arm_mat_scale_f32(
  const arm_matrix_instance_f32 * pSrc,
        float32_t                 scale,
        arm_matrix_instance_f32 * pDst)
{
  float32_t *pIn = pSrc->pData;                                                 
  float32_t *pOut = pDst->pData;                                                 
  uint32_t numSamples;                                                                       
  uint32_t blkCnt;                                                  
  arm_status status;                                                           

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
                                   

                                                         
      *pOut++ = (*pIn++) * scale;
      *pOut++ = (*pIn++) * scale;
      *pOut++ = (*pIn++) * scale;
      *pOut++ = (*pIn++) * scale;

                                  
      blkCnt--;
    }

                                                   
    blkCnt = numSamples % 0x4U;

#else

                                                  
    blkCnt = numSamples;

#endif                                        

    while (blkCnt > 0U)
    {
                                   

                                                         
      *pOut++ = (*pIn++) * scale;

                                  
      blkCnt--;
    }

                                        
    status = ARM_MATH_SUCCESS;
  }

                             
  return (status);
}
#endif                                 

   
                             
   
