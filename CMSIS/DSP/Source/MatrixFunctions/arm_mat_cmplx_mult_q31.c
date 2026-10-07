                                                                         
                                  
                                         
                                                     
  
                               
                       
  
                                   
                                                                          
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

   
                      
   

   
                             
    
   

   
                                                   
                                                                          
                                                                           
                                                                     
                                 
                                                                       
                                                                           

                                              
                                                                                    
                                                                                                     
                                                                                                      
                                                                                                    
                                                                                                     
                                                                                  
                                                                                                 
                                                                                                                           
   

arm_status arm_mat_cmplx_mult_q31(
  const arm_matrix_instance_q31 * pSrcA,
  const arm_matrix_instance_q31 * pSrcB,
        arm_matrix_instance_q31 * pDst)
{
  q31_t *pIn1 = pSrcA->pData;                                                     
  q31_t *pIn2 = pSrcB->pData;                                                     
  q31_t *pInA = pSrcA->pData;                                                     
  q31_t *pOut = pDst->pData;                                                     
  q31_t *px;                                                                               
  uint16_t numRowsA = pSrcA->numRows;                                                  
  uint16_t numColsB = pSrcB->numCols;                                                     
  uint16_t numColsA = pSrcA->numCols;                                                     
  q63_t sumReal, sumImag;                                         
  q31_t a1, b1, c1, d1;
  uint32_t col, i = 0U, j, row = numRowsA, colCnt;                    
  arm_status status;                                                                  

#if defined (ARM_MATH_LOOPUNROLL)
  q31_t a0, b0, c0, d0;
#endif

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
                                                                                
      px = pOut + 2 * i;

                                                                                  
      col = numColsB;

                                                            
                                                      
      pIn2 = pSrcB->pData;

      j = 0U;

                       
      do
      {
                                                                     
        sumReal = 0.0;
        sumImag = 0.0;

                                                                                          
        pIn1 = pInA;

#if defined (ARM_MATH_LOOPUNROLL)

                                                                     
        colCnt = numColsA >> 2U;

                                   
        while (colCnt > 0U)
        {

                                                     
          a0 = *pIn1;

                                                     
          c0 = *pIn2;

                                                          
          b0 = *(pIn1 + 1U);

                                                          
          d0 = *(pIn2 + 1U);

                                       
          sumReal += (q63_t) a0 * c0;
          sumImag += (q63_t) b0 * c0;

                               
          pIn1 += 2U;
          pIn2 += 2 * numColsB;

                                       
          sumReal -= (q63_t) b0 * d0;
          sumImag += (q63_t) a0 * d0;

                                                                                   

                                                                     
          a1 = *(pIn1     );
          c1 = *(pIn2     );
          b1 = *(pIn1 + 1U);
          d1 = *(pIn2 + 1U);

                                       
          sumReal += (q63_t) a1 * c1;
          sumImag += (q63_t) b1 * c1;

                               
          pIn1 += 2U;
          pIn2 += 2 * numColsB;

                                       
          sumReal -= (q63_t) b1 * d1;
          sumImag += (q63_t) a1 * d1;

          a0 = *(pIn1     );
          c0 = *(pIn2     );
          b0 = *(pIn1 + 1U);
          d0 = *(pIn2 + 1U);

                                       
          sumReal += (q63_t) a0 * c0;
          sumImag += (q63_t) b0 * c0;

                               
          pIn1 += 2U;
          pIn2 += 2 * numColsB;

                                       
          sumReal -= (q63_t) b0 * d0;
          sumImag += (q63_t) a0 * d0;

                                                                                   

          a1 = *(pIn1     );
          c1 = *(pIn2     );
          b1 = *(pIn1 + 1U);
          d1 = *(pIn2 + 1U);

                                       
          sumReal += (q63_t) a1 * c1;
          sumImag += (q63_t) b1 * c1;

                               
          pIn1 += 2U;
          pIn2 += 2 * numColsB;

                                       
          sumReal -= (q63_t) b1 * d1;
          sumImag += (q63_t) a1 * d1;

                                    
          colCnt--;
        }

                                                                                           
                                         
        colCnt = numColsA % 0x4U;

#else

                                                      
        colCnt = numColsA;

#endif                                        

        while (colCnt > 0U)
        {
                                                                                   
          a1 = *(pIn1     );
          c1 = *(pIn2     );
          b1 = *(pIn1 + 1U);
          d1 = *(pIn2 + 1U);

                                       
          sumReal += (q63_t) a1 * c1;
          sumImag += (q63_t) b1 * c1;

                               
          pIn1 += 2U;
          pIn2 += 2 * numColsB;

                                       
          sumReal -= (q63_t) b1 * d1;
          sumImag += (q63_t) a1 * d1;

                                      
          colCnt--;
        }

                                                
        *px++ = (q31_t) clip_q63_to_q31(sumReal >> 31);
        *px++ = (q31_t) clip_q63_to_q31(sumImag >> 31);

                                                                             
        j++;
        pIn2 = pSrcB->pData + 2U * j;

                                           
        col--;

      } while (col > 0U);

                                                                        
      i = i + numColsB;
      pInA = pInA + 2 * numColsA;

                                      
      row--;

    } while (row > 0U);

                                        
    status = ARM_MATH_SUCCESS;
  }

                             
  return (status);
}

   
                            
   
