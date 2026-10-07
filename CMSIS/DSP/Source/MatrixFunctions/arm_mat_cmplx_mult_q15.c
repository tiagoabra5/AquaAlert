                                                                         
                                  
                                         
                                                  
  
                               
                       
  
                                   
                                                                          
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

   
                      
   

   
                             
    
   

   
                                                   
                                                                          
                                                                           
                                                                     
                                                                               
                                 
                                                                       
                                                                           

                                                   
                                                                              

                                              
                                                                                                      
                                                                                              
                                                                                                         
                                                                                                                  
                                                                                                             
   

arm_status arm_mat_cmplx_mult_q15(
  const arm_matrix_instance_q15 * pSrcA,
  const arm_matrix_instance_q15 * pSrcB,
        arm_matrix_instance_q15 * pDst,
        q15_t                   * pScratch)
{
        q15_t *pSrcBT = pScratch;                                                                   
        q15_t *pInA = pSrcA->pData;                                                                 
        q15_t *pInB = pSrcB->pData;                                                                 
        q15_t *px;                                                                               
        uint16_t numRowsA = pSrcA->numRows;                                                  
        uint16_t numColsB = pSrcB->numCols;                                                     
        uint16_t numColsA = pSrcA->numCols;                                                     
        uint16_t numRowsB = pSrcB->numRows;                                                  
        q63_t sumReal, sumImag;                                         
        uint32_t col, i = 0U, row = numRowsB, colCnt;                     
        arm_status status;                                                                  

#if defined (ARM_MATH_DSP)
        q31_t prod1, prod2;
        q31_t pSourceA, pSourceB;
#else
        q15_t a, b, c, d;
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
                                                                               
      px = pSrcBT + i;

#if defined (ARM_MATH_LOOPUNROLL)

                                                                           
      col = numColsB >> 2;

                                                                                        
                                                                      
      while (col > 0U)
      {
                                        
        write_q15x2 (px, read_q15x2_ia (&pInB));

                                                                         
        px += numRowsB * 2;

                                        
        write_q15x2 (px, read_q15x2_ia (&pInB));

                                                                         
        px += numRowsB * 2;

                                        
        write_q15x2 (px, read_q15x2_ia (&pInB));

                                                                         
        px += numRowsB * 2;

                                        
        write_q15x2 (px, read_q15x2_ia (&pInB));

                                                                         
        px += numRowsB * 2;

                                           
        col--;
      }

                                                                                                   
                                       
      col = numColsB % 0x4U;

#else

                                                      
        col = numColsB;

#endif                                        

      while (col > 0U)
      {
                                        
        write_q15x2 (px, read_q15x2_ia (&pInB));

                                                                         
        px += numRowsB * 2;

                                           
        col--;
      }

      i = i + 2U;

                                      
      row--;

    } while (row > 0U);

                                                                       
    row = numRowsA;
    i = 0U;
    px = pDst->pData;

                                                                                                    
                  
    do
    {
                                                                              
      col = numColsB;

                                                                                                        
      pInB = pSrcBT;

                       
      do
      {
                                                                 
        sumReal = 0;
        sumImag = 0;

                                                                                          
        pInA = pSrcA->pData + i * 2;

                                                                     
        colCnt = numColsA >> 1U;

                                   
        while (colCnt > 0U)
        {
                                                                                   

#if defined (ARM_MATH_DSP)

                                                                     
          pSourceA = read_q15x2_ia ((q15_t **) &pInA);
          pSourceB = read_q15x2_ia ((q15_t **) &pInB);

                                       
#ifdef ARM_MATH_BIG_ENDIAN
          prod1 = -__SMUSD(pSourceA, pSourceB);
#else
          prod1 = __SMUSD(pSourceA, pSourceB);
#endif
          prod2 = __SMUADX(pSourceA, pSourceB);
          sumReal += (q63_t) prod1;
          sumImag += (q63_t) prod2;

                                                                     
          pSourceA = read_q15x2_ia ((q15_t **) &pInA);
          pSourceB = read_q15x2_ia ((q15_t **) &pInB);

                                       
#ifdef ARM_MATH_BIG_ENDIAN
          prod1 = -__SMUSD(pSourceA, pSourceB);
#else
          prod1 = __SMUSD(pSourceA, pSourceB);
#endif
          prod2 = __SMUADX(pSourceA, pSourceB);
          sumReal += (q63_t) prod1;
          sumImag += (q63_t) prod2;

#else                                 

                                                           
          a = *pInA;
          b = *(pInA + 1U);
                                                           
          c = *pInB;
          d = *(pInB + 1U);

                                       
          sumReal += (q31_t) a *c;
          sumImag += (q31_t) a *d;
          sumReal -= (q31_t) b *d;
          sumImag += (q31_t) b *c;

                                                                
          a = *(pInA + 2U);
          b = *(pInA + 3U);
                                                                
          c = *(pInB + 2U);
          d = *(pInB + 3U);

                              
          pInA += 4U;

                                       
          sumReal += (q31_t) a * c;
          sumImag += (q31_t) a * d;
          sumReal -= (q31_t) b * d;
          sumImag += (q31_t) b * c;
                              
          pInB += 4U;

#endif                                 

                                      
          colCnt--;
        }

                                        
        if ((numColsA & 0x1U) > 0U)
        {
                                                                                   

#if defined (ARM_MATH_DSP)
                                                                     
          pSourceA = read_q15x2_ia ((q15_t **) &pInA);
          pSourceB = read_q15x2_ia ((q15_t **) &pInB);

                                       
#ifdef ARM_MATH_BIG_ENDIAN
          prod1 = -__SMUSD(pSourceA, pSourceB);
#else
          prod1 = __SMUSD(pSourceA, pSourceB);
#endif
          prod2 = __SMUADX(pSourceA, pSourceB);
          sumReal += (q63_t) prod1;
          sumImag += (q63_t) prod2;

#else                                 

                                                                     
          a = *pInA++;
          b = *pInA++;
          c = *pInB++;
          d = *pInB++;

                                       
          sumReal += (q31_t) a * c;
          sumImag += (q31_t) a * d;
          sumReal -= (q31_t) b * d;
          sumImag += (q31_t) b * c;

#endif                                 

        }

                                                             
        *px++ = (q15_t) (__SSAT(sumReal >> 15, 16));
        *px++ = (q15_t) (__SSAT(sumImag >> 15, 16));

                                           
        col--;

      } while (col > 0U);

      i = i + numColsA;

                                      
      row--;

    } while (row > 0U);

                                        
    status = ARM_MATH_SUCCESS;
  }

                             
  return (status);
}

   
                            
   
