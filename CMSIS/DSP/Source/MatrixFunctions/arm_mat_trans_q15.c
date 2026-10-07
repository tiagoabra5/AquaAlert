                                                                         
                                  
                                    
                                     
  
                               
                       
  
                                   
                                                                          
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

   
                      
   

   
                         
    
   

   
                                      
                                                 
                                                  
                                 
                                                                       
                                                                           
   

arm_status arm_mat_trans_q15(
  const arm_matrix_instance_q15 * pSrc,
        arm_matrix_instance_q15 * pDst)
{
        q15_t *pIn = pSrc->pData;                                                     
        q15_t *pOut = pDst->pData;                                                     
        uint16_t nRows = pSrc->numRows;                                    
        uint16_t nCols = pSrc->numCols;                                       
        uint32_t col, row = nRows, i = 0U;                                
        arm_status status;                                                             

#if defined (ARM_MATH_LOOPUNROLL)
        q31_t in;                                                                              
#endif

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
                                                                             
      pOut = pDst->pData + i;

#if defined (ARM_MATH_LOOPUNROLL)

                                                       
      col = nCols >> 2U;

      while (col > 0U)                         
      {
                                        
        in = read_q15x2_ia ((q15_t **) &pIn);

                                                          
#ifndef ARM_MATH_BIG_ENDIAN
        *pOut = (q15_t) in;
#else
        *pOut = (q15_t) ((in & (q31_t) 0xffff0000) >> 16);
#endif                                  

                                                                           
        pOut += nRows;

                                                            
#ifndef ARM_MATH_BIG_ENDIAN
        *pOut = (q15_t) ((in & (q31_t) 0xffff0000) >> 16);
#else
        *pOut = (q15_t) in;
#endif                                  

                                                                            
        pOut += nRows;

                                        
        in = read_q15x2_ia ((q15_t **) &pIn);

                                                         
#ifndef ARM_MATH_BIG_ENDIAN
        *pOut = (q15_t) in;
#else
        *pOut = (q15_t) ((in & (q31_t) 0xffff0000) >> 16);

#endif                                  

                                                                           
        pOut += nRows;

                                                            
#ifndef ARM_MATH_BIG_ENDIAN
        *pOut = (q15_t) ((in & (q31_t) 0xffff0000) >> 16);
#else
        *pOut = (q15_t) in;
#endif                                  

                                                                           
        pOut += nRows;

                                           
        col--;
      }

                                                     
      col = nCols % 0x4U;

#else

                                                 
      col = nCols;

#endif                                        

      while (col > 0U)
      {
                                                         
        *pOut = *pIn++;

                                                                           
        pOut += nRows;

                                           
        col--;
      }

      i++;

                                      
      row--;

    } while (row > 0U);                            

                                        
    status = ARM_MATH_SUCCESS;
  }

                             
  return (status);
}

   
                             
   
