                                                                         
                                  
                                        
                                                         
  
                               
                       
  
                                   
                                                                          
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

   
                      
   

   
                        
    
   

   
                                                          
                                                                      
                                                                       
                                                             
                                                                                
                                 
                                                                       
                                                                           

                                              
                                                                                                            
                                                                                  
                                                                                
                                                                                                       
                                                                                                
      
                                                                                                       
                                                                                                  
                                                                                                
                                                                                                  
                                                                                                    
         
                                                                                                
                                                                              
   

arm_status arm_mat_mult_fast_q15(
  const arm_matrix_instance_q15 * pSrcA,
  const arm_matrix_instance_q15 * pSrcB,
        arm_matrix_instance_q15 * pDst,
        q15_t                   * pState)
{
        q31_t sum;                                                      
        q15_t *pSrcBT = pState;                                                                     
        q15_t *pInA = pSrcA->pData;                                                                 
        q15_t *pInB = pSrcB->pData;                                                                 
        q15_t *px;                                                                               
        uint16_t numRowsA = pSrcA->numRows;                                                  
        uint16_t numColsB = pSrcB->numCols;                                                     
        uint16_t numColsA = pSrcA->numCols;                                                     
        uint16_t numRowsB = pSrcB->numRows;                                                  
        uint32_t col, i = 0U, row = numRowsB, colCnt;                     
        arm_status status;                                                                  

#if defined (ARM_MATH_DSP)
        q31_t in;                                                                                      
        q31_t inA1, inB1, inA2, inB2;
        q31_t sum2, sum3, sum4;
        q15_t *pInA2, *pInB2, *px2;
        uint32_t j = 0;
#else
        q15_t in;                                                                                      
        q15_t inA1, inB1, inA2, inB2;
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

                                                                       
      col = numColsB >> 2U;

                                                                                        
                                                                       
      while (col > 0U)
      {

#if defined (ARM_MATH_DSP)

                                        
        in = read_q15x2_ia ((q15_t **) &pInB);

                                                         
#ifndef ARM_MATH_BIG_ENDIAN
        *px = (q15_t) in;
#else
        *px = (q15_t) ((in & (q31_t) 0xffff0000) >> 16);
#endif                                  

                                                                         
        px += numRowsB;

                                                            
#ifndef ARM_MATH_BIG_ENDIAN
        *px = (q15_t) ((in & (q31_t) 0xffff0000) >> 16);
#else
        *px = (q15_t) in;
#endif                                  

                                                                         
        px += numRowsB;

        in = read_q15x2_ia ((q15_t **) &pInB);
#ifndef ARM_MATH_BIG_ENDIAN
        *px = (q15_t) in;
#else
        *px = (q15_t) ((in & (q31_t) 0xffff0000) >> 16);
#endif                                  
        px += numRowsB;

#ifndef ARM_MATH_BIG_ENDIAN
        *px = (q15_t) ((in & (q31_t) 0xffff0000) >> 16);
#else
        *px = (q15_t) in;
#endif                                  
        px += numRowsB;

#else                                 

                                       
        in = *pInB++;

                                              
        *px = in;

                                                                         
        px += numRowsB;

        in = *pInB++;
        *px = in;
        px += numRowsB;

        in = *pInB++;
        *px = in;
        px += numRowsB;

        in = *pInB++;
        *px = in;
        px += numRowsB;

#endif                                 

                                           
        col--;
      }

                                                                                                   
                                       
      col = numColsB % 0x4U;

      while (col > 0U)
      {
                                                         
        *px = *pInB++;

                                                                         
        px += numRowsB;

                                           
        col--;
      }

      i++;

                                      
      row--;

    } while (row > 0U);

                                                                       
    row = numRowsA;
    i = 0U;
    px = pDst->pData;

#if defined (ARM_MATH_DSP)
                                                                                
    row = row >> 1U;
    px2 = px + numColsB;
#endif

                                                                                                    
                  
    while (row > 0U)
    {
                                                                              
      col = numColsB;

                                                                                                        
      pInB = pSrcBT;

#if defined (ARM_MATH_DSP)
                                                                    
      col = col >> 1U;
      j = 0;
#endif

                       
      while (col > 0U)
      {
                                                                 
        sum = 0;

                                                                                          
        pInA = pSrcA->pData + i;

#if defined (ARM_MATH_DSP)
        sum2 = 0;
        sum3 = 0;
        sum4 = 0;
        pInB  = pSrcBT + j;
        pInA2 = pInA + numColsA;
        pInB2 = pInB + numRowsB;

                                                                       
        colCnt = numColsA >> 1U;
#else
        colCnt = numColsA >> 2U;
#endif

                                   
        while (colCnt > 0U)
        {
                                                                                   

#if defined (ARM_MATH_DSP)
                                                                     
          inA1 = read_q15x2_ia ((q15_t **) &pInA);
          inB1 = read_q15x2_ia ((q15_t **) &pInB);

          inA2 = read_q15x2_ia ((q15_t **) &pInA2);
          inB2 = read_q15x2_ia ((q15_t **) &pInB2);

                                       
          sum  = __SMLAD(inA1, inB1, sum);
          sum2 = __SMLAD(inA1, inB2, sum2);
          sum3 = __SMLAD(inA2, inB1, sum3);
          sum4 = __SMLAD(inA2, inB2, sum4);
#else
                                                                     
          inA1 = *pInA++;
          inB1 = *pInB++;
                                       
          sum += inA1 * inB1;

          inA2 = *pInA++;
          inB2 = *pInB++;
          sum += inA2 * inB2;

          inA1 = *pInA++;
          inB1 = *pInB++;
          sum += inA1 * inB1;

          inA2 = *pInA++;
          inB2 = *pInB++;
          sum += inA2 * inB2;
#endif                                 

                                      
          colCnt--;
        }

                                        
#if defined (ARM_MATH_DSP)
        if (numColsA & 1U) {
          inA1 = *pInA++;
          inB1 = *pInB++;
          inA2 = *pInA2++;
          inB2 = *pInB2++;
          sum  += inA1 * inB1;
          sum2 += inA1 * inB2;
          sum3 += inA2 * inB1;
          sum4 += inA2 * inB2;
        }
#else
        colCnt = numColsA % 0x4U;

        while (colCnt > 0U)
        {
                                                                                   
          sum += (q31_t) *pInA++ * *pInB++;

                                      
          colCnt--;
        }
#endif                                 

                                                             
        *px++  = (q15_t) (sum >> 15);

#if defined (ARM_MATH_DSP)
        *px++  = (q15_t) (sum2 >> 15);
        *px2++ = (q15_t) (sum3 >> 15);
        *px2++ = (q15_t) (sum4 >> 15);
        j += numRowsB * 2;
#endif

                                           
        col--;

      }

      i = i + numColsA;

#if defined (ARM_MATH_DSP)
      i = i + numColsA;
      px = px2 + (numColsB & 1U);
      px2 = px + numColsB;
#endif

                                      
      row--;

    }

                                                    

#if defined (ARM_MATH_DSP)

                                         
    if (numColsB & 1U) {

                                                       
      row = numRowsA & (~0x1);

                                                               
      px = pDst->pData + numColsB-1;
      pInA = pSrcA->pData;

                    
      while (row > 0)
      {

                                              
        pInB  = pSrcBT + numRowsB * (numColsB-1);

                                                                 
        sum  = 0;

                                       
        colCnt = numColsA >> 2U;

                                   
        while (colCnt > 0U)
        {
          inA1 = read_q15x2_ia ((q15_t **) &pInA);
          inA2 = read_q15x2_ia ((q15_t **) &pInA);
          inB1 = read_q15x2_ia ((q15_t **) &pInB);
          inB2 = read_q15x2_ia ((q15_t **) &pInB);

          sum  = __SMLAD(inA1, inB1, sum);
          sum  = __SMLAD(inA2, inB2, sum);

                                      
          colCnt--;
        }

        colCnt = numColsA & 3U;
        while (colCnt > 0U) {
          sum += (q31_t) (*pInA++) * (*pInB++);
          colCnt--;
        }

                                                
        *px = (q15_t) (sum  >> 15);
        px += numColsB;

                                        
        row--;
      }
    }

                                      
    if (numRowsA & 1U) {

                                              
      px = pDst->pData + (numColsB) * (numRowsA-1);

      pInB  = pSrcBT;
      col = numColsB;
      i = 0U;

                    
      while (col > 0)
      {
                                           
        pInA = pSrcA->pData + (numRowsA-1) * numColsA;

                                                                 
        sum  = 0;

                                       
        colCnt = numColsA >> 2U;

                                   
        while (colCnt > 0U)
        {
          inA1 = read_q15x2_ia ((q15_t **) &pInA);
          inA2 = read_q15x2_ia ((q15_t **) &pInA);
          inB1 = read_q15x2_ia ((q15_t **) &pInB);
          inB2 = read_q15x2_ia ((q15_t **) &pInB);

          sum  = __SMLAD(inA1, inB1, sum);
          sum  = __SMLAD(inA2, inB2, sum);

                                      
          colCnt--;
        }

        colCnt = numColsA % 4U;
        while (colCnt > 0U) {
          sum += (q31_t) (*pInA++) * (*pInB++);

          colCnt--;
        }

                                                
        *px++ = (q15_t) (sum  >> 15);

                                           
        col--;
      }
    }

#endif                                 

                                        
    status = ARM_MATH_SUCCESS;
  }

                             
  return (status);
}

   
                            
   
