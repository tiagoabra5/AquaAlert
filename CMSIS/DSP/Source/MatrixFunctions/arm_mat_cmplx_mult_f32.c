                                                                         
                                  
                                         
                                                     
  
                               
                       
  
                                   
                                                                          
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
arm_status arm_mat_cmplx_mult_f32(
  const arm_matrix_instance_f32 * pSrcA,
  const arm_matrix_instance_f32 * pSrcB,
  arm_matrix_instance_f32 * pDst)
{
  float32_t *pIn1 = pSrcA->pData;                                                 
  float32_t *pIn2 = pSrcB->pData;                                                 
  float32_t *pInA = pSrcA->pData;                                                  
  float32_t *pOut = pDst->pData;                                                 
  float32_t *px;                                                                           
  uint16_t numRowsA = pSrcA->numRows;                                                  
  uint16_t numColsB = pSrcB->numCols;                                                     
  uint16_t numColsA = pSrcA->numCols;                                                     
  float32_t sumReal1, sumImag1;                                   
  float32_t a0, b0, c0, d0;
  float32_t a1, a1B,b1, b1B, c1, d1;
  float32_t sumReal2, sumImag2;                                   


  float32x4x2_t a0V, a1V;
  float32x4_t accR0,accI0, accR1,accI1,tempR, tempI;
  float32x2_t accum = vdup_n_f32(0);
  float32_t *pIn1B = pSrcA->pData;    

  uint16_t col, i = 0U, j, rowCnt, row = numRowsA, colCnt;                         
  arm_status status;                                                                  
  float32_t sumReal1B, sumImag1B; 
  float32_t sumReal2B, sumImag2B; 
  float32_t *pxB;  

#ifdef ARM_MATH_MATRIX_CHECK


                                           
  if ((pSrcA->numCols != pSrcB->numRows) ||
     (pSrcA->numRows != pDst->numRows) || (pSrcB->numCols != pDst->numCols))
  {

                                              
    status = ARM_MATH_SIZE_MISMATCH;
  }
  else
#endif                                           

  {
                                                                                                    

    rowCnt = row >> 1;

                  
    while (rowCnt > 0U)
    {
                                                                                
      px = pOut + 2 * i;
      pxB = px + 2 * numColsB;

                                                                                  
      col = numColsB;

                                                            
                                                      
      pIn2 = pSrcB->pData;

      j = 0U;

                       
      while (col > 0U)
      {
                                                                     
        sumReal1 = 0.0f;
        sumImag1 = 0.0f;
        sumReal1B = 0.0f;
        sumImag1B = 0.0f;

        sumReal2 = 0.0f;
        sumImag2 = 0.0f;
        sumReal2B = 0.0f;
        sumImag2B = 0.0f;

                                                                                                      
        pIn1 = pInA;
        pIn1B = pIn1 + 2*numColsA;

        accR0 = vdupq_n_f32(0.0);
        accI0 = vdupq_n_f32(0.0);
        accR1 = vdupq_n_f32(0.0);
        accI1 = vdupq_n_f32(0.0);

                                            
        colCnt = numColsA >> 2;

                                   
        while (colCnt > 0U)
        {
                                                     
          a0V = vld2q_f32(pIn1);                                                      
          a1V = vld2q_f32(pIn1B);                                                      

          pIn1 += 8;
          pIn1B += 8;

          tempR[0] = *pIn2;
          tempI[0] = *(pIn2 + 1U);
          pIn2 += 2 * numColsB;

          tempR[1] = *pIn2;
          tempI[1] = *(pIn2 + 1U);
          pIn2 += 2 * numColsB;

          tempR[2] = *pIn2;
          tempI[2] = *(pIn2 + 1U);
          pIn2 += 2 * numColsB;

          tempR[3] = *pIn2;
          tempI[3] = *(pIn2 + 1U);
          pIn2 += 2 * numColsB;

          accR0 = vmlaq_f32(accR0,a0V.val[0],tempR);
          accR0 = vmlsq_f32(accR0,a0V.val[1],tempI);

          accI0 = vmlaq_f32(accI0,a0V.val[1],tempR);
          accI0 = vmlaq_f32(accI0,a0V.val[0],tempI);

          accR1 = vmlaq_f32(accR1,a1V.val[0],tempR);
          accR1 = vmlsq_f32(accR1,a1V.val[1],tempI);

          accI1 = vmlaq_f32(accI1,a1V.val[1],tempR);
          accI1 = vmlaq_f32(accI1,a1V.val[0],tempI);

                                        
          colCnt--;
        }

        accum = vpadd_f32(vget_low_f32(accR0), vget_high_f32(accR0));
        sumReal1 += accum[0] + accum[1];

        accum = vpadd_f32(vget_low_f32(accI0), vget_high_f32(accI0));
        sumImag1 += accum[0] + accum[1];

        accum = vpadd_f32(vget_low_f32(accR1), vget_high_f32(accR1));
        sumReal1B += accum[0] + accum[1];

        accum = vpadd_f32(vget_low_f32(accI1), vget_high_f32(accI1));
        sumImag1B += accum[0] + accum[1];

                                                                                           
                                         
        colCnt = numColsA & 3;

        while (colCnt > 0U)
        {
                                                                            
          a1 = *pIn1;
          a1B = *pIn1B;

          c1 = *pIn2;

          b1 = *(pIn1 + 1U);
          b1B = *(pIn1B + 1U);

          d1 = *(pIn2 + 1U);

          sumReal1 += a1 * c1;
          sumImag1 += b1 * c1;

          sumReal1B += a1B * c1;
          sumImag1B += b1B * c1;

          pIn1 += 2U;
          pIn1B += 2U;
          pIn2 += 2 * numColsB;

          sumReal2 -= b1 * d1;
          sumImag2 += a1 * d1;

          sumReal2B -= b1B * d1;
          sumImag2B += a1B * d1;

                                          
          colCnt--;
        }

        sumReal1 += sumReal2;
        sumImag1 += sumImag2;

        sumReal1B += sumReal2B;
        sumImag1B += sumImag2B;

                                                        
        *px++ = sumReal1;
        *px++ = sumImag1;
        *pxB++ = sumReal1B;
        *pxB++ = sumImag1B;

                                                                                          
        j++;
        pIn2 = pSrcB->pData + 2U * j;

                                               
        col--;
      } 

                                                                                       
      i = i + 2*numColsB;
      pInA = pInA + 4 * numColsA;

                                          
      rowCnt--;
    }

    rowCnt = row & 1;
    while (rowCnt > 0U)
    {
                                                                                
      px = pOut + 2 * i;

                                                                                  
      col = numColsB;

                                                            
                                                      
      pIn2 = pSrcB->pData;

      j = 0U;

                       
      while (col > 0U)
      {
                                                                     
        sumReal1 = 0.0f;
        sumImag1 = 0.0f;

        sumReal2 = 0.0f;
        sumImag2 = 0.0f;

                                                                                                      
        pIn1 = pInA;

        accR0 = vdupq_n_f32(0.0);
        accI0 = vdupq_n_f32(0.0);

                                            
        colCnt = numColsA >> 2;

                                   
        while (colCnt > 0U)
        {
                                                     
          a0V = vld2q_f32(pIn1);                                                      
          pIn1 += 8;

          tempR[0] = *pIn2;
          tempI[0] = *(pIn2 + 1U);
          pIn2 += 2 * numColsB;

          tempR[1] = *pIn2;
          tempI[1] = *(pIn2 + 1U);
          pIn2 += 2 * numColsB;

          tempR[2] = *pIn2;
          tempI[2] = *(pIn2 + 1U);
          pIn2 += 2 * numColsB;

          tempR[3] = *pIn2;
          tempI[3] = *(pIn2 + 1U);
          pIn2 += 2 * numColsB;

          accR0 = vmlaq_f32(accR0,a0V.val[0],tempR);
          accR0 = vmlsq_f32(accR0,a0V.val[1],tempI);

          accI0 = vmlaq_f32(accI0,a0V.val[1],tempR);
          accI0 = vmlaq_f32(accI0,a0V.val[0],tempI);

                                        
          colCnt--;
        }

        accum = vpadd_f32(vget_low_f32(accR0), vget_high_f32(accR0));
        sumReal1 += accum[0] + accum[1];

        accum = vpadd_f32(vget_low_f32(accI0), vget_high_f32(accI0));
        sumImag1 += accum[0] + accum[1];

                                                                                           
                                         
        colCnt = numColsA & 3;

        while (colCnt > 0U)
        {
                                                                            
          a1 = *pIn1;
          c1 = *pIn2;

          b1 = *(pIn1 + 1U);
          d1 = *(pIn2 + 1U);

          sumReal1 += a1 * c1;
          sumImag1 += b1 * c1;

          pIn1 += 2U;
          pIn2 += 2 * numColsB;

          sumReal2 -= b1 * d1;
          sumImag2 += a1 * d1;

                                          
          colCnt--;
        }

        sumReal1 += sumReal2;
        sumImag1 += sumImag2;

                                                        
        *px++ = sumReal1;
        *px++ = sumImag1;

                                                                                          
        j++;
        pIn2 = pSrcB->pData + 2U * j;

                                               
        col--;

      } 

                                                                                     
      i = i + numColsB;
      pInA = pInA + 2 * numColsA;

                                          
      rowCnt--;

    }

                                        
    status = ARM_MATH_SUCCESS;
  }

                             
  return (status);
}
#else
arm_status arm_mat_cmplx_mult_f32(
  const arm_matrix_instance_f32 * pSrcA,
  const arm_matrix_instance_f32 * pSrcB,
        arm_matrix_instance_f32 * pDst)
{
  float32_t *pIn1 = pSrcA->pData;                                                 
  float32_t *pIn2 = pSrcB->pData;                                                 
  float32_t *pInA = pSrcA->pData;                                                 
  float32_t *pOut = pDst->pData;                                                 
  float32_t *px;                                                                           
  uint16_t numRowsA = pSrcA->numRows;                                                  
  uint16_t numColsB = pSrcB->numCols;                                                     
  uint16_t numColsA = pSrcA->numCols;                                                     
  float32_t sumReal, sumImag;                                     
  float32_t a1, b1, c1, d1;
  uint32_t col, i = 0U, j, row = numRowsA, colCnt;                    
  arm_status status;                                                                  

#if defined (ARM_MATH_LOOPUNROLL)
  float32_t a0, b0, c0, d0;
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
                                                                     
        sumReal = 0.0f;
        sumImag = 0.0f;

                                                                                          
        pIn1 = pInA;

#if defined (ARM_MATH_LOOPUNROLL)

                                                                     
        colCnt = numColsA >> 2U;

                                   
        while (colCnt > 0U)
        {

                                                     
          a0 = *pIn1;

                                                     
          c0 = *pIn2;

                                                          
          b0 = *(pIn1 + 1U);

                                                          
          d0 = *(pIn2 + 1U);

                                       
          sumReal += a0 * c0;
          sumImag += b0 * c0;

                               
          pIn1 += 2U;
          pIn2 += 2 * numColsB;

                                       
          sumReal -= b0 * d0;
          sumImag += a0 * d0;

                                                                                   

                                                                     
          a1 = *(pIn1     );
          c1 = *(pIn2     );
          b1 = *(pIn1 + 1U);
          d1 = *(pIn2 + 1U);

                                       
          sumReal += a1 * c1;
          sumImag += b1 * c1;

                               
          pIn1 += 2U;
          pIn2 += 2 * numColsB;

                                       
          sumReal -= b1 * d1;
          sumImag += a1 * d1;

          a0 = *(pIn1     );
          c0 = *(pIn2     );
          b0 = *(pIn1 + 1U);
          d0 = *(pIn2 + 1U);

                                       
          sumReal += a0 * c0;
          sumImag += b0 * c0;

                               
          pIn1 += 2U;
          pIn2 += 2 * numColsB;

                                       
          sumReal -= b0 * d0;
          sumImag += a0 * d0;

                                                                                   

          a1 = *(pIn1     );
          c1 = *(pIn2     );
          b1 = *(pIn1 + 1U);
          d1 = *(pIn2 + 1U);

                                       
          sumReal += a1 * c1;
          sumImag += b1 * c1;

                               
          pIn1 += 2U;
          pIn2 += 2 * numColsB;

                                       
          sumReal -= b1 * d1;
          sumImag += a1 * d1;

                                    
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

                                       
          sumReal += a1 * c1;
          sumImag += b1 * c1;

                               
          pIn1 += 2U;
          pIn2 += 2 * numColsB;

                                       
          sumReal -= b1 * d1;
          sumImag += a1 * d1;

                                      
          colCnt--;
        }

                                                
        *px++ = sumReal;
        *px++ = sumImag;

                                                                             
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

#endif                                 

   
                            
   
