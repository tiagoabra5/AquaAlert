                                                                         
                                  
                                        
                                                         
  
                               
                       
  
                                   
                                                                          
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

   
                      
   

   
                        
    
   

   
                                                          
                                                                      
                                                                       
                                                             
                                 
                                                                       
                                                                           

                                              
                                                                                                            
                                                                                  
                                                                                
                                                                                                       
                                                                                                
      
                                                                                                       
                                                                                                  
                                                                                                
                                                                                                  
                                                                                                    
         
                                                                                                
                                                                              
   

arm_status arm_mat_mult_fast_q31(
  const arm_matrix_instance_q31 * pSrcA,
  const arm_matrix_instance_q31 * pSrcB,
        arm_matrix_instance_q31 * pDst)
{
  q31_t *pInA = pSrcA->pData;                                                     
  q31_t *pInB = pSrcB->pData;                                                     
  q31_t *pInA2;
  q31_t *px;                                                                               
  q31_t *px2;
  q31_t sum1, sum2, sum3, sum4;                                   
  q31_t inA1, inA2, inB1, inB2;
  uint16_t numRowsA = pSrcA->numRows;                                                  
  uint16_t numColsB = pSrcB->numCols;                                                     
  uint16_t numColsA = pSrcA->numCols;                                                     
  uint32_t col, i = 0U, j, row = numRowsA, colCnt;                     
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
    px = pDst->pData;

    row = row >> 1U;
    px2 = px + numColsB;

                                                                                                    
                  
    while (row > 0U)
    {
                                                                              
      col = numColsB;

                                                                                             
      pInB = pSrcB->pData;

      j = 0U;

      col = col >> 1U;

                       
      while (col > 0U)
      {
                                                                     
        sum1 = 0;
        sum2 = 0;
        sum3 = 0;
        sum4 = 0;
        
                                    
        pInA = pSrcA->pData + i;
        pInB = pSrcB->pData + j;
        pInA2 = pInA + numColsA;
        
        colCnt = numColsA;

                                   
        while (colCnt > 0U)
        {
                                                                                   

          inA1 = *pInA++;
          inB1 = pInB[0];
          inA2 = *pInA2++;
          inB2 = pInB[1];
          pInB += numColsB;

#if defined (ARM_MATH_DSP)
          sum1 = __SMMLA(inA1, inB1, sum1);
          sum2 = __SMMLA(inA1, inB2, sum2);
          sum3 = __SMMLA(inA2, inB1, sum3);
          sum4 = __SMMLA(inA2, inB2, sum4);
#else
          sum1 = (q31_t) ((((q63_t) sum1 << 32) + ((q63_t) inA1 * inB1)) >> 32);
          sum2 = (q31_t) ((((q63_t) sum2 << 32) + ((q63_t) inA1 * inB2)) >> 32);
          sum3 = (q31_t) ((((q63_t) sum3 << 32) + ((q63_t) inA2 * inB1)) >> 32);
          sum4 = (q31_t) ((((q63_t) sum4 << 32) + ((q63_t) inA2 * inB2)) >> 32);
#endif

                                      
          colCnt--;
        }

                                                                                         
        *px++  = sum1 << 1;
        *px++  = sum2 << 1;
        *px2++ = sum3 << 1;
        *px2++ = sum4 << 1;

        j += 2;

                                           
        col--;
      }

      i = i + (numColsA << 1U);
      px  = px2 + (numColsB & 1U);
      px2 = px  +  numColsB;

                                      
      row--;
    }

                                                    

                                         
    if (numColsB & 1U) {

                                                       
      row = numRowsA & (~1U);

                                                               
      px = pDst->pData + numColsB-1;
      pInA = pSrcA->pData;

                    
      while (row > 0)
      {

                                              
        pInB  = pSrcB->pData + numColsB-1;

                                                                  
        sum1  = 0;

#if defined (ARM_MATH_LOOPUNROLL)

                                                          
        colCnt = numColsA >> 2U;

                                   
        while (colCnt > 0U)
        {
#if defined (ARM_MATH_DSP)
          sum1 = __SMMLA(*pInA++, *pInB, sum1);
#else
          sum1 = (q31_t) ((((q63_t) sum1 << 32) + ((q63_t) *pInA++ * *pInB)) >> 32);
#endif
          pInB += numColsB;

#if defined (ARM_MATH_DSP)
          sum1 = __SMMLA(*pInA++, *pInB, sum1);
#else
          sum1 = (q31_t) ((((q63_t) sum1 << 32) + ((q63_t) *pInA++ * *pInB)) >> 32);
#endif
          pInB += numColsB;

#if defined (ARM_MATH_DSP)
          sum1 = __SMMLA(*pInA++, *pInB, sum1);
#else
          sum1 = (q31_t) ((((q63_t) sum1 << 32) + ((q63_t) *pInA++ * *pInB)) >> 32);
#endif
          pInB += numColsB;

#if defined (ARM_MATH_DSP)
          sum1 = __SMMLA(*pInA++, *pInB, sum1);
#else
          sum1 = (q31_t) ((((q63_t) sum1 << 32) + ((q63_t) *pInA++ * *pInB)) >> 32);
#endif
          pInB += numColsB;

                                      
          colCnt--;
        }

                                                      
        colCnt = numColsA % 4U;

#else

                                                      
        colCnt = numColsA;

#endif                                        

        while (colCnt > 0U) {
#if defined (ARM_MATH_DSP)
          sum1 = __SMMLA(*pInA++, *pInB, sum1);
#else
          sum1 = (q31_t) ((((q63_t) sum1 << 32) + ((q63_t) *pInA++ * *pInB)) >> 32);
#endif
          pInB += numColsB;
          
          colCnt--;
        }

                                                                                         
        *px = sum1 << 1;
        px += numColsB;

                                        
        row--;
      }
    }

                                      
    if (numRowsA & 1U) {

                                              
      px = pDst->pData + (numColsB) * (numRowsA-1);

      col = numColsB;
      i = 0U;

                    
      while (col > 0)
      {

                                           
        pInA = pSrcA->pData + (numRowsA-1) * numColsA;
        pInB  = pSrcB->pData + i;

                                                                  
        sum1  = 0;

#if defined (ARM_MATH_LOOPUNROLL)

                                                          
        colCnt = numColsA >> 2U;

                                   
        while (colCnt > 0U)
        {
          inA1 = *pInA++;
          inA2 = *pInA++;
          inB1 = *pInB;
          pInB += numColsB;
          inB2 = *pInB;
          pInB += numColsB;
#if defined (ARM_MATH_DSP)
          sum1 = __SMMLA(inA1, inB1, sum1);
          sum1 = __SMMLA(inA2, inB2, sum1);
#else
          sum1 = (q31_t) ((((q63_t) sum1 << 32) + ((q63_t) inA1 * inB1)) >> 32);
          sum1 = (q31_t) ((((q63_t) sum1 << 32) + ((q63_t) inA2 * inB2)) >> 32);
#endif

          inA1 = *pInA++;
          inA2 = *pInA++;
          inB1 = *pInB;
          pInB += numColsB;
          inB2 = *pInB;
          pInB += numColsB;
#if defined (ARM_MATH_DSP)
          sum1 = __SMMLA(inA1, inB1, sum1);
          sum1 = __SMMLA(inA2, inB2, sum1);
#else
          sum1 = (q31_t) ((((q63_t) sum1 << 32) + ((q63_t) inA1 * inB1)) >> 32);
          sum1 = (q31_t) ((((q63_t) sum1 << 32) + ((q63_t) inA2 * inB2)) >> 32);
#endif

                                      
          colCnt--;
        }

                                                      
        colCnt = numColsA % 4U;

#else

                                                      
        colCnt = numColsA;

#endif                                        

        while (colCnt > 0U) {
#if defined (ARM_MATH_DSP)
          sum1 = __SMMLA(*pInA++, *pInB, sum1);
#else
          sum1 = (q31_t) ((((q63_t) sum1 << 32) + ((q63_t) *pInA++ * *pInB)) >> 32);
#endif
          pInB += numColsB;

          colCnt--;
        }

                                                                     
        *px++ = sum1 << 1;
        i++;

                                        
        col--;
      }
    }

                                        
    status = ARM_MATH_SUCCESS;
  }

                             
  return (status);
}

   
                            
   
