                                                                         
                                  
                                   
                                          
  
                               
                       
  
                                   
                                                                          
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

   
                      
   

   
                        
    
   

   
                                           
                                                                      
                                                                       
                                                             
                                 
                                                                       
                                                                           

                                              
                                                                                    
                                                                                                     
                                                                                                      
                                                                                                    
                                                                                                     
                                                                                  
                                                                                                 
                                                                                                                           
         
                                                                                                                       
   

arm_status arm_mat_mult_q31(
  const arm_matrix_instance_q31 * pSrcA,
  const arm_matrix_instance_q31 * pSrcB,
        arm_matrix_instance_q31 * pDst)
{
  q31_t *pIn1 = pSrcA->pData;                                                     
  q31_t *pIn2 = pSrcB->pData;                                                     
  q31_t *pInA = pSrcA->pData;                                                     
  q31_t *pInB = pSrcB->pData;                                                     
  q31_t *pOut = pDst->pData;                                                     
  q31_t *px;                                                                               
  q63_t sum;                                                      
  uint16_t numRowsA = pSrcA->numRows;                                                  
  uint16_t numColsB = pSrcB->numCols;                                                     
  uint16_t numColsA = pSrcA->numCols;                                                     
  uint32_t col, i = 0U, row = numRowsA, colCnt;                     
  arm_status status;                                                                  

#ifdef ARM_MATH_MATRIX_CHECK

                                           
  if ((pSrcA->numCols != pSrcB->numRows) ||
      (pSrcA->numRows != pDst->numRows)  ||
      (pSrcB->numCols != pDst->numCols)    )
  {
                                              
    status = ARM_MATH_SIZE_MISMATCH;
  }
  else

#endif                                   

  {
                                                                                                    
                  
    do
    {
                                                                            
      px = pOut + i;

                                                                              
      col = numColsB;

                                                                                             
      pIn2 = pSrcB->pData;

                       
      do
      {
                                                                     
        sum = 0;

                                                                                            
        pIn1 = pInA;

#if defined (ARM_MATH_LOOPUNROLL)

                                                       
        colCnt = numColsA >> 2U;

                                   
        while (colCnt > 0U)
        {
                                                                                   

                                                
          sum += (q63_t) *pIn1++ * *pIn2;
          pIn2 += numColsB;

          sum += (q63_t) *pIn1++ * *pIn2;
          pIn2 += numColsB;

          sum += (q63_t) *pIn1++ * *pIn2;
          pIn2 += numColsB;

          sum += (q63_t) *pIn1++ * *pIn2;
          pIn2 += numColsB;

                                      
          colCnt--;
        }

                                                    
        colCnt = numColsA % 0x4U;

#else

                                                      
        colCnt = numColsA;

#endif                                        

        while (colCnt > 0U)
        {
                                                                                   

                                                
          sum += (q63_t) *pIn1++ * *pIn2;
          pIn2 += numColsB;

                                      
          colCnt--;
        }

                                                                                     
        *px++ = (q31_t) (sum >> 31);

                                           
        col--;

                                                                             
        pIn2 = pInB + (numColsB - col);

      } while (col > 0U);

                                                                        
      i = i + numColsB;
      pInA = pInA + numColsA;

                                      
      row--;

    } while (row > 0U);

                                        
    status = ARM_MATH_SUCCESS;
  }

                             
  return (status);
}

   
                            
   
