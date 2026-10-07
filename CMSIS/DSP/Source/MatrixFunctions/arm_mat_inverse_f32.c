                                                                         
                                  
                                      
                                              
  
                               
                       
  
                                   
                                                                          
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
arm_status arm_mat_inverse_f32(
  const arm_matrix_instance_f32 * pSrc,
  arm_matrix_instance_f32 * pDst)
{
  float32_t *pIn = pSrc->pData;                                                 
  float32_t *pOut = pDst->pData;                                                 
  float32_t *pInT1, *pInT2;                                                               
  float32_t *pOutT1, *pOutT2;                                                              
  float32_t *pPivotRowIn, *pPRT_in, *pPivotRowDst, *pPRT_pDst;                                                      
  uint32_t numRows = pSrc->numRows;                                                 
  uint32_t numCols = pSrc->numCols;                                                 

  float32_t maxC;                                                                 

  float32_t Xchg, in = 0.0f, in1;                                             
  uint32_t i, rowCnt, flag = 0U, j, loopCnt, k, l;                         
  arm_status status;                                                           
  float32x4_t vec1;
  float32x4_t vec2;
  float32x4_t tmpV;

#ifdef ARM_MATH_MATRIX_CHECK

                                           
  if ((pSrc->numRows != pSrc->numCols) || (pDst->numRows != pDst->numCols)
     || (pSrc->numRows != pDst->numRows))
  {
                                              
    status = ARM_MATH_SIZE_MISMATCH;
  }
  else
#endif                                         

  {
                                                                                                                   
                                                                  
    
                          
    
                                                                                                
                                        
                                                          
                                                           
                                                           
                                                           
    
                                                                         
    
                                               
    
                                                                                  
                                                                                    
                                                                              
                                                                                                
                                                                                         
                                                                                                    
                                                                            
    
                                                        
    
                                                                                          
                                                                                        
    
                                                                                              
                                                               
    
                                                                                        
                                                                                            
                                                                                                                      

                                                
    pOutT1 = pOut;

                                      
    rowCnt = numRows;

                                                          
    while (rowCnt > 0U)
    {
                                                                          
      j = numRows - rowCnt;
      while (j > 0U)
      {
        *pOutT1++ = 0.0f;
        j--;
      }

                                                                      
      *pOutT1++ = 1.0f;

                                                                          
      j = rowCnt - 1U;

      while (j > 0U)
      {
        *pOutT1++ = 0.0f;
        j--;
      }

                                      
      rowCnt--;
    }

                                                           
                                                                             
    loopCnt = numCols;

                                                        
    l = 0U;

    while (loopCnt > 0U)
    {
                                             
                                                                        
                                                                      
                                        

                                                         
                                                       
      pInT1 = pIn + (l * numCols);

                                                               
                                                       
      pOutT1 = pOut + (l * numCols);

                                                      
      in = *pInT1;

                                                         
      maxC = 0;

      for (i = l; i < numRows; i++)
      {
        maxC = *pInT1 > 0 ? (*pInT1 > maxC ? *pInT1 : maxC) : (-*pInT1 > maxC ? -*pInT1 : maxC);
        pInT1 += numCols;
      }

                                                       
      if (maxC == 0.0f)
      {
        return ARM_MATH_SINGULAR;
      }

                         
      pInT1 = pIn;

                                        
      k = 1U;

                                                                            
      if ( (in > 0.0f ? in : -in) != maxC)
      {
                                                     
        i = numRows - (l + 1U);

        while (i > 0U)
        {
                                                         
          pInT2 = pInT1 + (numCols * l);
          pOutT2 = pOutT1 + (numCols * k);

                                                     
                                         
          if ((*pInT2 > 0.0f ? *pInT2: -*pInT2) == maxC)
          {
                                          
                                                   
            j = numCols - l;

            while (j > 0U)
            {
                                                                 
              Xchg = *pInT2;
              *pInT2++ = *pInT1;
              *pInT1++ = Xchg;

                                              
              j--;
            }

                                                                       
            j = numCols;

            while (j > 0U)
            {
                                                                       
              Xchg = *pOutT2;
              *pOutT2++ = *pOutT1;
              *pOutT1++ = Xchg;

                                              
              j--;
            }

                                                                  
            flag = 1U;

                                              
            break;
          }

                                                       
          k++;

                                          
          i--;
        }
      }

                                                       
      if ((flag != 1U) && (in == 0.0f))
      {
        return ARM_MATH_SINGULAR;
      }

                                                                     
      pPivotRowIn = pIn + (l * numCols);
      pPivotRowDst = pOut + (l * numCols);

                                                        
      pInT1 = pPivotRowIn;
      pInT2 = pPivotRowDst;

                                    
      in = *pPivotRowIn;
      tmpV = vdupq_n_f32(1.0/in);

                                    
                                             
      j = (numCols - l) >> 2;

      while (j > 0U)
      {
                                                             
                                  
        vec1 = vld1q_f32(pInT1);

        vec1 = vmulq_f32(vec1, tmpV);
        vst1q_f32(pInT1, vec1);
        pInT1 += 4;

                                        
        j--;
      }

                
      j = (numCols - l) & 3;

      while (j > 0U)
      {
                                                             
                                  
        in1 = *pInT1;
        *pInT1++ = in1 / in;

                                        
        j--;
      }

                                                                 
      j = numCols >> 2;

      while (j > 0U)
      {
                                                                   
                                  
        vec1 = vld1q_f32(pInT2);

        vec1 = vmulq_f32(vec1, tmpV);
        vst1q_f32(pInT2, vec1);
        pInT2 += 4;
      
                                        
        j--;
      }

                
      j = numCols & 3;

      while (j > 0U)
      {
                                                                   
                                  
        in1 = *pInT2;
        *pInT2++ = in1 / in;

                                        
        j--;
      }

                                                                          
                                                                    

                                                                 
      pInT1 = pIn;
      pInT2 = pOut;

                                                 
      i = 0U;

                                    
                                                                          
      k = numRows;

      while (k > 0U)
      {
                                         
        if (i == l)
        {
                                                            
                                                                 
          pInT1 += numCols - l;

          pInT2 += numCols;
        }
        else
        {
                                            
          in = *pInT1;
          tmpV = vdupq_n_f32(in);

                                                                     
          pPRT_in = pPivotRowIn;
          pPRT_pDst = pPivotRowDst;

                                                                               
                                                           
          j = (numCols - l) >> 2;
	  
          while (j > 0U)
          {
                                                         
                                                      
            vec1 = vld1q_f32(pInT1);
            vec2 = vld1q_f32(pPRT_in);
            vec1 = vmlsq_f32(vec1, tmpV, vec2);
            vst1q_f32(pInT1, vec1);
            pPRT_in += 4;
            pInT1 += 4;

                                            
            j--;
          }

	            
          j = (numCols - l) & 3;

          while (j > 0U)
          {
                                                         
                                                      
            in1 = *pInT1;
            *pInT1++ = in1 - (in * *pPRT_in++);

                                            
            j--;
          }

                                               
                                                              
          j = numCols >> 2;

          while (j > 0U)
          {
                                                         
                                                      
            vec1 = vld1q_f32(pInT2);
            vec2 = vld1q_f32(pPRT_pDst);
            vec1 = vmlsq_f32(vec1, tmpV, vec2);
            vst1q_f32(pInT2, vec1);
            pPRT_pDst += 4;
            pInT2 += 4;

                                            
            j--;
          }

	            
          j = numCols & 3;

          while (j > 0U)
          {
                                                         
                                                      
            in1 = *pInT2;
            *pInT2++ = in1 - (in * *pPRT_pDst++);

                                            
            j--;
          }

        }

                                                   
        pInT1 = pInT1 + l;

                                        
        k--;

                                       
        i++;
      }

                                       
      pIn++;

                                      
      loopCnt--;

                                        
      l++;
    }

                                        
    status = ARM_MATH_SUCCESS;

    if ((flag != 1U) && (in == 0.0f))
    {
      pIn = pSrc->pData;
      for (i = 0; i < numRows * numCols; i++)
      {
        if (pIn[i] != 0.0f)
            break;
      }

      if (i == numRows * numCols)
        status = ARM_MATH_SINGULAR;
    }
  }
                             
  return (status);
}
#else
arm_status arm_mat_inverse_f32(
  const arm_matrix_instance_f32 * pSrc,
        arm_matrix_instance_f32 * pDst)
{
  float32_t *pIn = pSrc->pData;                                                 
  float32_t *pOut = pDst->pData;                                                 
  float32_t *pInT1, *pInT2;                                                               
  float32_t *pOutT1, *pOutT2;                                                              
  float32_t *pPivotRowIn, *pPRT_in, *pPivotRowDst, *pPRT_pDst;                                                      
  uint32_t numRows = pSrc->numRows;                                                 
  uint32_t numCols = pSrc->numCols;                                                 

#if defined (ARM_MATH_DSP)
  float32_t maxC;                                                                 

  float32_t Xchg, in = 0.0f, in1;                                             
  uint32_t i, rowCnt, flag = 0U, j, loopCnt, k, l;                         
  arm_status status;                                                           

#ifdef ARM_MATH_MATRIX_CHECK

                                           
  if ((pSrc->numRows != pSrc->numCols) ||
      (pDst->numRows != pDst->numCols) ||
      (pSrc->numRows != pDst->numRows)   )
  {
                                              
    status = ARM_MATH_SIZE_MISMATCH;
  }
  else

#endif                                   

  {

                                                                                                                    
                                                                    
      
                            
      
                                                                                                   
                                          
                                                                    
                                                                     
                                                                     
                                                                     
      
                                                                             
      
                                                   
      
                                                                                    
                                                                                        
                                                                                  
                                                                                                    
                                                                                             
                                                                                                      
                                                                                
      
                                                          
      
                                                                                            
                                                                                            
      
                                                                                                
                                                                   
      
                                                                                            
                                                                                                
                                                                                                                        

                                                
    pOutT1 = pOut;

                                      
    rowCnt = numRows;

                                                          
    while (rowCnt > 0U)
    {
                                                                          
      j = numRows - rowCnt;
      while (j > 0U)
      {
        *pOutT1++ = 0.0f;
        j--;
      }

                                                                      
      *pOutT1++ = 1.0f;

                                                                          
      j = rowCnt - 1U;
      while (j > 0U)
      {
        *pOutT1++ = 0.0f;
        j--;
      }

                                  
      rowCnt--;
    }

                                                           
                                                                             
    loopCnt = numCols;

                                                        
    l = 0U;

    while (loopCnt > 0U)
    {
                                             
                                                                        
                                                                      
                                        

                                                         
                                                       
      pInT1 = pIn + (l * numCols);

                                                               
                                                       
      pOutT1 = pOut + (l * numCols);

                                                      
      in = *pInT1;

                                                         
      maxC = 0;
      for (i = l; i < numRows; i++)
      {
        maxC = *pInT1 > 0 ? (*pInT1 > maxC ? *pInT1 : maxC) : (-*pInT1 > maxC ? -*pInT1 : maxC);
        pInT1 += numCols;
      }

                                                       
      if (maxC == 0.0f)
      {
        return ARM_MATH_SINGULAR;
      }

                          
      pInT1 = pIn;

                                        
      k = 1U;

                                                                            
      if ( (in > 0.0f ? in : -in) != maxC)
      {
                                                     
        i = numRows - (l + 1U);

        while (i > 0U)
        {
                                                         
          pInT2 = pInT1 + (numCols * l);
          pOutT2 = pOutT1 + (numCols * k);

                                                     
                                         
          if ((*pInT2 > 0.0f ? *pInT2: -*pInT2) == maxC)
          {
                                          
                                                   
            j = numCols - l;

            while (j > 0U)
            {
                                                                 
              Xchg = *pInT2;
              *pInT2++ = *pInT1;
              *pInT1++ = Xchg;

                                              
              j--;
            }

                                                                       
            j = numCols;

            while (j > 0U)
            {
                                                                       
              Xchg = *pOutT2;
              *pOutT2++ = *pOutT1;
              *pOutT1++ = Xchg;

                                          
              j--;
            }

                                                                  
            flag = 1U;

                                              
            break;
          }

                                                       
          k++;

                                      
          i--;
        }
      }

                                                       
      if ((flag != 1U) && (in == 0.0f))
      {
        return ARM_MATH_SINGULAR;
      }

                                                                     
      pPivotRowIn = pIn + (l * numCols);
      pPivotRowDst = pOut + (l * numCols);

                                                        
      pInT1 = pPivotRowIn;
      pInT2 = pPivotRowDst;

                                    
      in = *pPivotRowIn;

                                    
                                             
      j = (numCols - l);

      while (j > 0U)
      {
                                                             
                                  
        in1 = *pInT1;
        *pInT1++ = in1 / in;

                                        
        j--;
      }

                                                                 
      j = numCols;

      while (j > 0U)
      {
                                                                   
                                  
        in1 = *pInT2;
        *pInT2++ = in1 / in;

                                        
        j--;
      }

                                                                          
                                                                    

                                                                 
      pInT1 = pIn;
      pInT2 = pOut;

                                                 
      i = 0U;

                                    
                                                                          
      k = numRows;

      while (k > 0U)
      {
                                         
        if (i == l)
        {
                                                            
                                                                 
          pInT1 += numCols - l;

          pInT2 += numCols;
        }
        else
        {
                                            
          in = *pInT1;

                                                                     
          pPRT_in = pPivotRowIn;
          pPRT_pDst = pPivotRowDst;

                                                                               
                                                           
          j = (numCols - l);

          while (j > 0U)
          {
                                                         
                                                      
            in1 = *pInT1;
            *pInT1++ = in1 - (in * *pPRT_in++);

                                            
            j--;
          }

                                               
                                                              
          j = numCols;

          while (j > 0U)
          {
                                                         
                                                      
            in1 = *pInT2;
            *pInT2++ = in1 - (in * *pPRT_pDst++);

                                        
            j--;
          }

        }

                                               
        pInT1 = pInT1 + l;

                                    
        k--;

                                   
        i++;
      }

                                       
      pIn++;

                                      
      loopCnt--;

                                        
      l++;
    }


#else

  float32_t Xchg, in = 0.0f;                                                  
  uint32_t i, rowCnt, flag = 0U, j, loopCnt, k, l;                         
  arm_status status;                                                           

#ifdef ARM_MATH_MATRIX_CHECK

                                           
  if ((pSrc->numRows != pSrc->numCols) ||
      (pDst->numRows != pDst->numCols) ||
      (pSrc->numRows != pDst->numRows)   )
  {
                                              
    status = ARM_MATH_SIZE_MISMATCH;
  }
  else

#endif                                   

  {

                                                                                                                    
                                                                    
      
                            
      
                                                                                                   
                                          
                                                                                
                                                                                 
                                                                                 
                                                                                 
      
                                                                             
      
                                                   
      
                                                           
                                                                                        
                                                                                  
                                                                                        
                                                                                   
                                             
      
                                                          
      
                                                                                            
                                                                                            
      
                                                                                                
                                                                   
      
                                                                                           
                                                                                              
                                                                                                                        

                                                
    pOutT1 = pOut;

                                      
    rowCnt = numRows;

                                                          
    while (rowCnt > 0U)
    {
                                                                          
      j = numRows - rowCnt;
      while (j > 0U)
      {
        *pOutT1++ = 0.0f;
        j--;
      }

                                                                      
      *pOutT1++ = 1.0f;

                                                                          
      j = rowCnt - 1U;
      while (j > 0U)
      {
        *pOutT1++ = 0.0f;
        j--;
      }

                                  
      rowCnt--;
    }

                                                           
                                                                             
    loopCnt = numCols;

                                                        
    l = 0U;

    while (loopCnt > 0U)
    {
                                             
                                                                        
                                                                      
                                        

                                                         
                                                       
      pInT1 = pIn + (l * numCols);

                                                               
                                                       
      pOutT1 = pOut + (l * numCols);

                                                      
      in = *pInT1;

                                        
      k = 1U;

                                              
      if (*pInT1 == 0.0f)
      {
                                                     
        for (i = (l + 1U); i < numRows; i++)
        {
                                                         
          pInT2 = pInT1 + (numCols * l);
          pOutT2 = pOutT1 + (numCols * k);

                                                          
                                         
          if (*pInT2 != 0.0f)
          {
                                          
                                                   
            for (j = 0U; j < (numCols - l); j++)
            {
                                                                 
              Xchg = *pInT2;
              *pInT2++ = *pInT1;
              *pInT1++ = Xchg;
            }

            for (j = 0U; j < numCols; j++)
            {
              Xchg = *pOutT2;
              *pOutT2++ = *pOutT1;
              *pOutT1++ = Xchg;
            }

                                                                  
            flag = 1U;

                                              
            break;
          }

                                                       
          k++;
        }
      }

                                                       
      if ((flag != 1U) && (in == 0.0f))
      {
        return ARM_MATH_SINGULAR;
      }

                                                                     
      pPivotRowIn = pIn + (l * numCols);
      pPivotRowDst = pOut + (l * numCols);

                                                        
      pInT1 = pPivotRowIn;
      pOutT1 = pPivotRowDst;

                                    
      in = *(pIn + (l * numCols));

                                    
                                             
      for (j = 0U; j < (numCols - l); j++)
      {
                                                             
                                  
        *pInT1 = *pInT1 / in;
        pInT1++;
      }
      for (j = 0U; j < numCols; j++)
      {
                                                                   
                                  
        *pOutT1 = *pOutT1 / in;
        pOutT1++;
      }

                                                                          
                                                                    

                                                                 
      pInT1 = pIn;
      pOutT1 = pOut;

      for (i = 0U; i < numRows; i++)
      {
                                         
        if (i == l)
        {
                                                            
                                                                 
          pInT1 += numCols - l;
          pOutT1 += numCols;
        }
        else
        {
                                            
          in = *pInT1;

                                                                     
          pPRT_in = pPivotRowIn;
          pPRT_pDst = pPivotRowDst;

                                                                               
                                                           
          for (j = 0U; j < (numCols - l); j++)
          {
                                                         
                                                      
            *pInT1 = *pInT1 - (in * *pPRT_in++);
            pInT1++;
          }

                                               
                                                              
          for (j = 0U; j < numCols; j++)
          {
                                                         
                                                      
            *pOutT1 = *pOutT1 - (in * *pPRT_pDst++);
            pOutT1++;
          }

        }

                                               
        pInT1 = pInT1 + l;
      }

                                       
      pIn++;

                                      
      loopCnt--;

                                        
      l++;
    }

#endif                                 

                                        
    status = ARM_MATH_SUCCESS;

    if ((flag != 1U) && (in == 0.0f))
    {
      pIn = pSrc->pData;
      for (i = 0; i < numRows * numCols; i++)
      {
        if (pIn[i] != 0.0f)
            break;
      }

      if (i == numRows * numCols)
        status = ARM_MATH_SINGULAR;
    }
  }

                             
  return (status);
}
#endif                                 

   
                           
   
