                                                                         
                                  
                                  
                                               
  
                               
                       
  
                                   
                                                                          
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

   
                      
   

   
                                     

                    
                                                                 

                                       
                                                                             
                             
   

   
                       
    
   


   
                                                
                                                                  
                                                                   
                                                             
                                 
                                                                       
                                                                           
   
#if defined(ARM_MATH_NEON)
  

                                                    
                                                             
                                                      

  
arm_status arm_mat_add_f32(
  const arm_matrix_instance_f32 * pSrcA,
  const arm_matrix_instance_f32 * pSrcB,
  arm_matrix_instance_f32 * pDst)
{
  float32_t *pIn1 = pSrcA->pData;                                                  
  float32_t *pIn2 = pSrcB->pData;                                                  
  float32_t *pOut = pDst->pData;                                                   

  float32_t inA1, inA2, inB1, inB2, out1, out2;                           

  uint32_t numSamples;                                                                        
  uint32_t blkCnt;                                                  
  arm_status status;                                                            

#ifdef ARM_MATH_MATRIX_CHECK
                                           
  if ((pSrcA->numRows != pSrcB->numRows) ||
     (pSrcA->numCols != pSrcB->numCols) ||
     (pSrcA->numRows != pDst->numRows) || (pSrcA->numCols != pDst->numCols))
  {
                                              
    status = ARM_MATH_SIZE_MISMATCH;
  }
  else
#endif
  {
    float32x4_t vec1;
    float32x4_t vec2;
    float32x4_t res;

                                                     
    numSamples = (uint32_t) pSrcA->numRows * pSrcA->numCols;

    blkCnt = numSamples >> 2U;

                                   
                                                                     
    while (blkCnt > 0U)
    {
                                    
                                                                     
      vec1 = vld1q_f32(pIn1);
      vec2 = vld1q_f32(pIn2);
      res = vaddq_f32(vec1, vec2);
      vst1q_f32(pOut, res);

                                                   
      pIn1 += 4U;
      pIn2 += 4U;
      pOut += 4U;
                                      
      blkCnt--;
    }

                                                                                           
                                     
    blkCnt = numSamples % 0x4U;

    while (blkCnt > 0U)
    {
                                    
                                                                     
      *pOut++ = (*pIn1++) + (*pIn2++);

                                      
      blkCnt--;
    }

                                        
    status = ARM_MATH_SUCCESS;
  }

                             
  return (status);
}
#else
arm_status arm_mat_add_f32(
  const arm_matrix_instance_f32 * pSrcA,
  const arm_matrix_instance_f32 * pSrcB,
        arm_matrix_instance_f32 * pDst)
{
  float32_t *pInA = pSrcA->pData;                                                 
  float32_t *pInB = pSrcB->pData;                                                 
  float32_t *pOut = pDst->pData;                                                 

  uint32_t numSamples;                                                                       
  uint32_t blkCnt;                                                  
  arm_status status;                                                            

#ifdef ARM_MATH_MATRIX_CHECK

                                           
  if ((pSrcA->numRows != pSrcB->numRows) ||
      (pSrcA->numCols != pSrcB->numCols) ||
      (pSrcA->numRows != pDst->numRows)  ||
      (pSrcA->numCols != pDst->numCols)    )
  {
                                              
    status = ARM_MATH_SIZE_MISMATCH;
  }
  else

#endif                                   

  {
                                                 
    numSamples = (uint32_t) pSrcA->numRows * pSrcA->numCols;

#if defined (ARM_MATH_LOOPUNROLL)

                                                     
    blkCnt = numSamples >> 2U;

    while (blkCnt > 0U)
    {
                                    

                                                       
      *pOut++ = *pInA++ + *pInB++;

      *pOut++ = *pInA++ + *pInB++;

      *pOut++ = *pInA++ + *pInB++;

      *pOut++ = *pInA++ + *pInB++;

                                  
      blkCnt--;
    }

                                                   
    blkCnt = numSamples % 0x4U;

#else

                                                  
    blkCnt = numSamples;

#endif                                        

    while (blkCnt > 0U)
    {
                                    

                                                       
      *pOut++ = *pInA++ + *pInB++;

                                  
      blkCnt--;
    }

                                        
    status = ARM_MATH_SUCCESS;
  }

                             
  return (status);
}
#endif                                 

   
                           
   
