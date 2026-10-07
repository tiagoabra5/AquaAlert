                                                                         
                                  
                                    
                                     
  
                               
                       
  
                                   
                                                                          
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

   
                      
   

   
                         
    
   

   
                                      
                                                 
                                                  
                                 
                                                                       
                                                                           
   

arm_status arm_mat_trans_q31(
  const arm_matrix_instance_q31 * pSrc,
        arm_matrix_instance_q31 * pDst)
{
  q31_t *pIn = pSrc->pData;                                                     
  q31_t *pOut = pDst->pData;                                                     
  q31_t *px;                                                                               
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

   
                             
   
