                                                                         
                                  
                                   
                                                     
  
                               
                       
  
                                   
                                                                          
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

#define GROUPOFROWS 8

arm_status arm_mat_mult_f32(
  const arm_matrix_instance_f32 * pSrcA,
  const arm_matrix_instance_f32 * pSrcB,
  arm_matrix_instance_f32 * pDst)
{
  float32_t *pIn1 = pSrcA->pData;                                                 
  float32_t *pIn2 = pSrcB->pData;                                                 
  float32_t *pInA = pSrcA->pData;                                                  
  float32_t *pOut = pDst->pData;                                                 
  float32_t *px;                                                                           
  float32_t sum;                                                  
  uint16_t numRowsA = pSrcA->numRows;                                                  
  uint16_t numColsB = pSrcB->numCols;                                                     
  uint16_t numColsA = pSrcA->numCols;                                                     


  float32_t in1, in2, in3, in4;
  uint16_t col, i = 0U, j, row = numRowsA, rowCnt, colCnt;                         
  arm_status status;                                                                  

  float32x4_t a0V, a1V, a2V, a3V, a4V, a5V, a6V, a7V;
  float32x4_t acc0,acc1,acc2,acc3,acc4,acc5,acc6,acc7,temp;
  float32x2_t accum = vdup_n_f32(0);
  float32_t *pIn1B = pSrcA->pData;    
  float32_t *pIn1C = pSrcA->pData;    
  float32_t *pIn1D = pSrcA->pData;  
  float32_t *pIn1E = pSrcA->pData; 
  float32_t *pIn1F = pSrcA->pData; 
  float32_t *pIn1G = pSrcA->pData; 
  float32_t *pIn1H = pSrcA->pData;   

  float32_t *pxB,*pxC, *pxD, *pxE, *pxF, *pxG, *pxH;                                                                           
  float32_t sum0,sum1, sum2,sum3, sum4, sum5 , sum6, sum7;

#ifdef ARM_MATH_MATRIX_CHECK

                                           
  if ((pSrcA->numCols != pSrcB->numRows) ||
     (pSrcA->numRows != pDst->numRows) || (pSrcB->numCols != pDst->numCols))
  {
                                              
    status = ARM_MATH_SIZE_MISMATCH;
  }
  else
#endif                                           
  {
                                                                                                    
                  
    rowCnt = row >> 3;

    while(rowCnt > 0)
    {
                                                                                
      px = pOut + GROUPOFROWS*i;
      pxB = px + numColsB;
      pxC = px + 2*numColsB;
      pxD = px + 3*numColsB;
      pxE = px + 4*numColsB;
      pxF = px + 5*numColsB;
      pxG = px + 6*numColsB;
      pxH = px + 7*numColsB;

                                                                                  
      col = numColsB;

                                                            
                                                      
      pIn2 = pSrcB->pData;

      j = 0U;

                       
      do
      {
                                                                     
        sum0 = 0.0f;
        sum1 = 0.0f;
        sum2 = 0.0f;
        sum3 = 0.0f;
        sum4 = 0.0f;
        sum5 = 0.0f;
        sum6 = 0.0f;
        sum7 = 0.0f;

                                                                                                      
        pIn1 = pInA;
        pIn1B = pIn1 + numColsA;
        pIn1C = pIn1 + 2*numColsA;
        pIn1D = pIn1 + 3*numColsA;
        pIn1E = pIn1 + 4*numColsA;
        pIn1F = pIn1 + 5*numColsA;
        pIn1G = pIn1 + 6*numColsA;
        pIn1H = pIn1 + 7*numColsA;

        acc0 = vdupq_n_f32(0.0);
        acc1 = vdupq_n_f32(0.0);
        acc2 = vdupq_n_f32(0.0);
        acc3 = vdupq_n_f32(0.0);
        acc4 = vdupq_n_f32(0.0);
        acc5 = vdupq_n_f32(0.0);
        acc6 = vdupq_n_f32(0.0);
        acc7 = vdupq_n_f32(0.0);

                                            
        colCnt = numColsA >> 2U;

                                   
        while (colCnt > 0U)
        {
                                                                            
          a0V = vld1q_f32(pIn1);  
          a1V = vld1q_f32(pIn1B);  
          a2V = vld1q_f32(pIn1C); 
          a3V = vld1q_f32(pIn1D); 
          a4V = vld1q_f32(pIn1E); 
          a5V = vld1q_f32(pIn1F); 
          a6V = vld1q_f32(pIn1G); 
          a7V = vld1q_f32(pIn1H); 

	  pIn1 += 4;
          pIn1B += 4;
          pIn1C += 4;
          pIn1D += 4;
          pIn1E += 4;
          pIn1F += 4;
          pIn1G += 4;
          pIn1H += 4;
          
          temp[0] = *pIn2;
          pIn2 += numColsB;
          temp[1] = *pIn2;
          pIn2 += numColsB;
          temp[2] = *pIn2;
          pIn2 += numColsB;
          temp[3] = *pIn2;
          pIn2 += numColsB;

          acc0 = vmlaq_f32(acc0,a0V,temp);
          acc1 = vmlaq_f32(acc1,a1V,temp);
          acc2 = vmlaq_f32(acc2,a2V,temp);
          acc3 = vmlaq_f32(acc3,a3V,temp);
          acc4 = vmlaq_f32(acc4,a4V,temp);
          acc5 = vmlaq_f32(acc5,a5V,temp);
          acc6 = vmlaq_f32(acc6,a6V,temp);
          acc7 = vmlaq_f32(acc7,a7V,temp);

                                        
          colCnt--;
        }

        accum = vpadd_f32(vget_low_f32(acc0), vget_high_f32(acc0));
        sum0 += accum[0] + accum[1];

        accum = vpadd_f32(vget_low_f32(acc1), vget_high_f32(acc1));
        sum1 += accum[0] + accum[1];

        accum = vpadd_f32(vget_low_f32(acc2), vget_high_f32(acc2));
        sum2 += accum[0] + accum[1];

        accum = vpadd_f32(vget_low_f32(acc3), vget_high_f32(acc3));
        sum3 += accum[0] + accum[1];

        accum = vpadd_f32(vget_low_f32(acc4), vget_high_f32(acc4));
        sum4 += accum[0] + accum[1];

        accum = vpadd_f32(vget_low_f32(acc5), vget_high_f32(acc5));
        sum5 += accum[0] + accum[1];

        accum = vpadd_f32(vget_low_f32(acc6), vget_high_f32(acc6));
        sum6 += accum[0] + accum[1];

        accum = vpadd_f32(vget_low_f32(acc7), vget_high_f32(acc7));
        sum7 += accum[0] + accum[1];

                                                                                           
                                         
        colCnt = numColsA & 3;

        while (colCnt > 0U)
        {
                                                                            
          sum0 += *pIn1++ * (*pIn2);
          sum1 += *pIn1B++ * (*pIn2);
          sum2 += *pIn1C++ * (*pIn2);
          sum3 += *pIn1D++ * (*pIn2);
          sum4 += *pIn1E++ * (*pIn2);
          sum5 += *pIn1F++ * (*pIn2);
          sum6 += *pIn1G++ * (*pIn2);
          sum7 += *pIn1H++ * (*pIn2);
          pIn2 += numColsB;

                                          
          colCnt--;
        }

                                                        
        *px++ = sum0;
        *pxB++ = sum1;
        *pxC++ = sum2;
        *pxD++ = sum3;
        *pxE++ = sum4;
        *pxF++ = sum5;
        *pxG++ = sum6;
        *pxH++ = sum7;

                                                                                          
        j++;
        pIn2 = pSrcB->pData + j;

                                               
        col--;

      } while (col > 0U);

                                                                                     
      i = i + numColsB;
      pInA = pInA + GROUPOFROWS*numColsA;

                                          
      rowCnt--;
    } 

      

                                                                 
                                                                         
                                               

      

    i = GROUPOFROWS*i;
    rowCnt = row & 7;

    while(rowCnt > 0)
    {
                                                                                
      px = pOut + i;

                                                                                  
      col = numColsB;

                                                            
                                                      
      pIn2 = pSrcB->pData;

      j = 0U;

                       
      do
      {
                                                                     
        sum = 0.0f;

                                                                                                      
        pIn1 = pInA;

        acc0 = vdupq_n_f32(0.0);

                                            
        colCnt = numColsA >> 2U;

                                     
        while (colCnt > 0U)
        {
                                                                            
          a0V = vld1q_f32(pIn1);                                                      
          pIn1 += 4;
          
          temp[0] = *pIn2;
          pIn2 += numColsB;
          temp[1] = *pIn2;
          pIn2 += numColsB;
          temp[2] = *pIn2;
          pIn2 += numColsB;
          temp[3] = *pIn2;
          pIn2 += numColsB;

          acc0 = vmlaq_f32(acc0,a0V,temp);

                                        
          colCnt--;
        }

        accum = vpadd_f32(vget_low_f32(acc0), vget_high_f32(acc0));
        sum += accum[0] + accum[1];

                                                                                           
                                         
        colCnt = numColsA % 0x4U;

        while (colCnt > 0U)
        {
                                                                            
          sum += *pIn1++ * (*pIn2);
          pIn2 += numColsB;

                                          
          colCnt--;
        }

                                                        
        *px++ = sum;

                                                                                          
        j++;
        pIn2 = pSrcB->pData + j;

                                               
        col--;

      } while (col > 0U);


                                                                                     
      i = i + numColsB;
      pInA = pInA + numColsA;

                                          
      rowCnt--;

    } 
                                        
    status = ARM_MATH_SUCCESS;
  }

                             
  return (status);
}
#else
arm_status arm_mat_mult_f32(
  const arm_matrix_instance_f32 * pSrcA,
  const arm_matrix_instance_f32 * pSrcB,
        arm_matrix_instance_f32 * pDst)
{
  float32_t *pIn1 = pSrcA->pData;                                                 
  float32_t *pIn2 = pSrcB->pData;                                                 
  float32_t *pInA = pSrcA->pData;                                                 
  float32_t *pInB = pSrcB->pData;                                                 
  float32_t *pOut = pDst->pData;                                                 
  float32_t *px;                                                                           
  float32_t sum;                                                  
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
                                                                     
        sum = 0.0f;

                                                                                            
        pIn1 = pInA;

#if defined (ARM_MATH_LOOPUNROLL)

                                                       
        colCnt = numColsA >> 2U;

                                   
        while (colCnt > 0U)
        {
                                                                                   

                                                
          sum += *pIn1++ * *pIn2;
          pIn2 += numColsB;

          sum += *pIn1++ * *pIn2;
          pIn2 += numColsB;

          sum += *pIn1++ * *pIn2;
          pIn2 += numColsB;

          sum += *pIn1++ * *pIn2;
          pIn2 += numColsB;

                                      
          colCnt--;
        }

                                                    
        colCnt = numColsA % 0x4U;

#else

                                                      
        colCnt = numColsA;

#endif                                        

        while (colCnt > 0U)
        {
                                                                                   

                                                
          sum += *pIn1++ * *pIn2;
          pIn2 += numColsB;

                                      
          colCnt--;
        }

                                                
        *px++ = sum;

                                           
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

#endif                                 

   
                             
   
