                                                                         
                                  
                                  
                                       
  
                               
                       
  
                                   
                                                                          
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

   
                      
   

   
                       
    
   

   
                                        
                                                                      
                                                                       
                                                             
                                 
                                                                       
                                                                           

                                              
                                                           
                                                                                                    
   

arm_status arm_mat_sub_q31(
  const arm_matrix_instance_q31 * pSrcA,
  const arm_matrix_instance_q31 * pSrcB,
        arm_matrix_instance_q31 * pDst)
{
  q31_t *pInA = pSrcA->pData;                                                     
  q31_t *pInB = pSrcB->pData;                                                     
  q31_t *pOut = pDst->pData;                                                     

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
                                    

                                                                                    
      *pOut++ = __QSUB(*pInA++, *pInB++);

      *pOut++ = __QSUB(*pInA++, *pInB++);

      *pOut++ = __QSUB(*pInA++, *pInB++);

      *pOut++ = __QSUB(*pInA++, *pInB++);

                                  
      blkCnt--;
    }

                                                   
    blkCnt = numSamples % 0x4U;

#else

                                                  
    blkCnt = numSamples;

#endif                                        

    while (blkCnt > 0U)
    {
                                    

                                                                      
      *pOut++ = __QSUB(*pInA++, *pInB++);

                                  
      blkCnt--;
    }

                                        
    status = ARM_MATH_SUCCESS;
  }

                             
  return (status);
}

   
                           
   
