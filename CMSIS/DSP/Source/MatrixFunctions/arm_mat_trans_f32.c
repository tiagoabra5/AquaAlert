                                                                         
                                  
                                    
                                                
  
                               
                       
  
                                   
                                                                          
/*
 * Copyright (C) 2010-2017 ARM Limited or its affiliates. All rights reserved.
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

arm_status arm_mat_trans_f32(
  const arm_matrix_instance_f32 * pSrc,
  arm_matrix_instance_f32 * pDst)
{
  float32_t *pIn = pSrc->pData;                                                 
  float32_t *pOut = pDst->pData;                                                 
  float32_t *px;                                                                           
  uint16_t nRows = pSrc->numRows;                                    
  uint16_t nColumns = pSrc->numCols;                                    

  uint16_t blkCnt, rowCnt, i = 0U, row = nRows;                             
  arm_status status;                                                              

#ifdef ARM_MATH_MATRIX_CHECK

                                           
  if ((pSrc->numRows != pDst->numCols) || (pSrc->numCols != pDst->numRows))
  {
                                              
    status = ARM_MATH_SIZE_MISMATCH;
  }
  else
#endif                                         

  {
                                                              
                  
    rowCnt = row >> 2;
    while (rowCnt > 0U)
    {
      float32x4_t row0V,row1V,row2V,row3V;
      float32x4x2_t ra0,ra1,rb0,rb1;

      blkCnt = nColumns >> 2;

                                                                                   
      px = pOut + i;

                                     
                                                                       
      while (blkCnt > 0U)                         
      {
        row0V = vld1q_f32(pIn);
        row1V = vld1q_f32(pIn + 1 * nColumns);
        row2V = vld1q_f32(pIn + 2 * nColumns);
        row3V = vld1q_f32(pIn + 3 * nColumns);
        pIn += 4;

        ra0 = vzipq_f32(row0V,row2V);
        ra1 = vzipq_f32(row1V,row3V);

        rb0 = vzipq_f32(ra0.val[0],ra1.val[0]);
        rb1 = vzipq_f32(ra0.val[1],ra1.val[1]);

        vst1q_f32(px,rb0.val[0]);
        px += nRows;

        vst1q_f32(px,rb0.val[1]);
        px += nRows;

        vst1q_f32(px,rb1.val[0]);
        px += nRows;

        vst1q_f32(px,rb1.val[1]);
        px += nRows;

                                               
        blkCnt--;
      }

                                                             
      blkCnt = nColumns % 0x4U;

      while (blkCnt > 0U)
      {
                                                                 
        *px++ = *pIn;
        *px++ = *(pIn + 1 * nColumns);
        *px++ = *(pIn + 2 * nColumns);
        *px++ = *(pIn + 3 * nColumns);
        
        px += (nRows - 4);
        pIn++;

                                               
        blkCnt--;
      }

      i += 4;
      pIn += 3 * nColumns;

                                          
      rowCnt--;

    }                            

    rowCnt = row & 3;
    while (rowCnt > 0U)
    {
      blkCnt = nColumns ;
                                                                                   
      px = pOut + i;

      while (blkCnt > 0U)
      {
                                                                 
        *px = *pIn++;

                                                                                     
        px += nRows;

                                               
        blkCnt--;
      }
      i++;
      rowCnt -- ;
    }

                                        
    status = ARM_MATH_SUCCESS;
  }

                             
  return (status);
}
#else
arm_status arm_mat_trans_f32(
  const arm_matrix_instance_f32 * pSrc,
        arm_matrix_instance_f32 * pDst)
{
  float32_t *pIn = pSrc->pData;                                                 
  float32_t *pOut = pDst->pData;                                                 
  float32_t *px;                                                                           
  uint16_t nRows = pSrc->numRows;                                    
  uint16_t nCols = pSrc->numCols;                                       
  uint32_t col, row = nRows, i = 0U;                                
  arm_status status;                                                             

#ifdef ARM_MATH_MATRIX_CHECK

                                           
  if ((pSrc->numRows != pDst->numCols) ||
      (pSrc->numCols != pDst->numRows)   )
  {
                                              
    status = ARM_MATH_SIZE_MISMATCH;
  }
  else

#endif                                   

  {
                                                              
                  
    do
    {
                                                                           
      px = pOut + i;

#if defined (ARM_MATH_LOOPUNROLL)

                                                       
      col = nCols >> 2U;

      while (col > 0U)                         
      {
                                                         
        *px = *pIn++;
                                                                         
        px += nRows;

        *px = *pIn++;
        px += nRows;

        *px = *pIn++;
        px += nRows;

        *px = *pIn++;
        px += nRows;

                                           
        col--;
      }

                                                     
      col = nCols % 0x4U;

#else

                                                 
      col = nCols;

#endif                                        

      while (col > 0U)
      {
                                                         
        *px = *pIn++;

                                                                         
        px += nRows;

                                           
        col--;
      }

      i++;

                                      
      row--;

    } while (row > 0U);                            

                                        
    status = ARM_MATH_SUCCESS;
  }

                             
  return (status);
}
#endif                                 

   
                              
   
