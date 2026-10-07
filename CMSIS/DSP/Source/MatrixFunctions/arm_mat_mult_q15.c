                                                                         
                                  
                                   
                                          
  
                               
                       
  
                                   
                                                                          
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

   
                      
   

   
                        
    
   

   
                                           
                                                                      
                                                                       
                                                             
                                                                                         
                                 
                                                                       
                                                                           

                                              
                                                                                                      
                                                                                              
                                                                                                         
                                                                                         
                                                                                                   
                                                     
      
                                                                                                                
   

arm_status arm_mat_mult_q15(
  const arm_matrix_instance_q15 * pSrcA,
  const arm_matrix_instance_q15 * pSrcB,
        arm_matrix_instance_q15 * pDst,
        q15_t                   * pState)
{
        q63_t sum;                                                      

#if defined (ARM_MATH_DSP)                                         

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
        
        q31_t in;                                                                                      
        q31_t inA1, inB1, inA2, inB2;

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

                                                                                                    
                  
    do
    {
                                                                              
      col = numColsB;

                                                                                                        
      pInB = pSrcBT;

                       
      do
      {
                                                                 
        sum = 0;

                                                                                          
        pInA = pSrcA->pData + i;

                                                                     
        colCnt = numColsA >> 2U;

                                   
        while (colCnt > 0U)
        {
                                                                                   

                                                                     
          inA1 = read_q15x2_ia ((q15_t **) &pInA);
          inB1 = read_q15x2_ia ((q15_t **) &pInB);

          inA2 = read_q15x2_ia ((q15_t **) &pInA);
          inB2 = read_q15x2_ia ((q15_t **) &pInB);

                                       
          sum = __SMLALD(inA1, inB1, sum);
          sum = __SMLALD(inA2, inB2, sum);

                                      
          colCnt--;
        }

                                              
        colCnt = numColsA % 0x4U;

        while (colCnt > 0U)
        {
                                                                                   
          sum += *pInA++ * *pInB++;

                                      
          colCnt--;
        }

                                                             
        *px = (q15_t) (__SSAT((sum >> 15), 16));
        px++;

                                           
        col--;

      } while (col > 0U);

      i = i + numColsA;

                                      
      row--;

    } while (row > 0U);

#else                                 

        q15_t *pIn1 = pSrcA->pData;                                                     
        q15_t *pIn2 = pSrcB->pData;                                                     
        q15_t *pInA = pSrcA->pData;                                                                 
        q15_t *pInB = pSrcB->pData;                                                                 
        q15_t *pOut = pDst->pData;                                                     
        q15_t *px;                                                                               
        uint16_t numColsB = pSrcB->numCols;                                                     
        uint16_t numColsA = pSrcA->numCols;                                                     
        uint16_t numRowsA = pSrcA->numRows;                                                     
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

                                                                           
        colCnt = numColsA;

                                   
        while (colCnt > 0U)
        {
                                                                                   

                                            
          sum += (q31_t) * pIn1++ * *pIn2;
          pIn2 += numColsB;

                                      
          colCnt--;
        }

                                                                                                      

                                                             
        *px++ = (q15_t) __SSAT((sum >> 15), 16);

                                           
        col--;

                                                                             
        pIn2 = pInB + (numColsB - col);

      } while (col > 0U);

                                                                         
      i = i + numColsB;
      pInA = pInA + numColsA;

                                      
      row--;

    } while (row > 0U);

#endif                                 

                                        
    status = ARM_MATH_SUCCESS;
  }

                             
  return (status);
}

   
                            
   
