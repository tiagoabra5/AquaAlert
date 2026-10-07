                                                                         
                                  
                                       
                                                                
  
                               
                       
  
                                   
                                                                          
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

   
                       
   

   
                                           

                                                                                                           
                                             
                                                                                       
                                                                    
                                               
                                                         
                                                                            

                                                                 
                                                                                                        
                                                  
                                                                         

                              
                                                                                      
                                                                                                                    
                                                                                           

                             
                                                                                                                                
                                                                                                                                                          
   

   
                         
    
   

   
                                                                 
                                                               
                                                               
                                                                
                                                                
                                                                                      
                                                                     
                                                                          
                                 
                                                                        
                                                                                                              
   

arm_status arm_conv_partial_f32(
  const float32_t * pSrcA,
        uint32_t srcALen,
  const float32_t * pSrcB,
        uint32_t srcBLen,
        float32_t * pDst,
        uint32_t firstIndex,
        uint32_t numPoints)
{

#if (1)
                                   

  const float32_t *pIn1 = pSrcA;                                           
  const float32_t *pIn2 = pSrcB;                                           
        float32_t *pOut = pDst;                                            
  const float32_t *px;                                                                  
  const float32_t *py;                                                                  
  const float32_t *pSrc1, *pSrc2;                                                 
        float32_t sum;                                                  
        uint32_t j, k, count, blkCnt, check;
        int32_t blockSize1, blockSize2, blockSize3;                       
        arm_status status;                                                                

#if defined (ARM_MATH_LOOPUNROLL)
        float32_t acc0, acc1, acc2, acc3;                               
        float32_t x0, x1, x2, x3, c0;                                           
#endif

                                                          
  if ((firstIndex + numPoints) > ((srcALen + (srcBLen - 1U))))
  {
                                               
    status = ARM_MATH_ARGUMENT_ERROR;
  }
  else
  {
                                                                             
                                                   
                                                                        
    if (srcALen >= srcBLen)
    {
                                            
      pIn1 = pSrcA;

                                            
      pIn2 = pSrcB;
    }
    else
    {
                                            
      pIn1 = pSrcB;

                                            
      pIn2 = pSrcA;

                                                                       
      j = srcBLen;
      srcBLen = srcALen;
      srcALen = j;
    }

                                                  
                                                                            
    check = firstIndex + numPoints;
    blockSize3 = ((int32_t)check > (int32_t)srcALen) ? (int32_t)check - (int32_t)srcALen : 0;
    blockSize3 = ((int32_t)firstIndex > (int32_t)srcALen - 1) ? blockSize3 - (int32_t)firstIndex + (int32_t)srcALen : blockSize3;
    blockSize1 = ((int32_t) srcBLen - 1) - (int32_t) firstIndex;
    blockSize1 = (blockSize1 > 0) ? ((check > (srcBLen - 1U)) ? blockSize1 : (int32_t) numPoints) : 0;
    blockSize2 = ((int32_t) check - blockSize3) - (blockSize1 + (int32_t) firstIndex);
    blockSize2 = (blockSize2 > 0) ? blockSize2 : 0;

                                                                                                
                                 
                                                                                          
                                                                                       
                                                                          
                                                                                        
                                                                               
                              

                                                        
                                                
    pOut = pDst + firstIndex;

                                 
                                
                                  

                        
                                      
           
                                                                                      
       

                                                                               
                                                                       
                                                           
                                                          
    count = 1U + firstIndex;

                                   
    px = pIn1;

                                   
    pSrc1 = pIn2 + firstIndex;
    py = pSrc1;

                               
                     
                               

                                     
    while (blockSize1 > 0U)
    {
                                                        
      sum = 0.0f;

#if defined (ARM_MATH_LOOPUNROLL)

                                                       
      k = count >> 2U;

      while (k > 0U)
      {
                                   
        sum += *px++ * *py--;

                                   
        sum += *px++ * *py--;

                                   
        sum += *px++ * *py--;

                                   
        sum += *px++ * *py--;

                                    
        k--;
      }

                                                     
      k = count % 0x4U;

#else

                                               
      k = count;

#endif                                        

      while (k > 0U)
      {
                                             
        sum += *px++ * *py--;

                                    
        k--;
      }

                                                                          
      *pOut++ = sum;

                                                                          
      py = ++pSrc1;
      px = pIn1;

                               
      count++;

                                  
      blockSize1--;
    }

                                 
                                
                                 

                                                                                
                                                                              
           
                                                                                                      
       

                                   
    if ((int32_t)firstIndex - (int32_t)srcBLen + 1 > 0)
    {
      pSrc1 = pIn1 + firstIndex - srcBLen + 1;
    }
    else
    {
      pSrc1 = pIn1;
    }
    px = pSrc1;

                                   
    pSrc2 = pIn2 + (srcBLen - 1U);
    py = pSrc2;

                                                                    
    count = 0U;

                          
                     
                           

                                                                                       
                                          
                                                      
    if (srcBLen >= 4U)
    {
#if defined (ARM_MATH_LOOPUNROLL)

                                                       
      blkCnt = ((uint32_t) blockSize2 >> 2U);

      while (blkCnt > 0U)
      {
                                          
        acc0 = 0.0f;
        acc1 = 0.0f;
        acc2 = 0.0f;
        acc3 = 0.0f;

                                           
        x0 = *px++;
        x1 = *px++;
        x2 = *px++;

                                                                     
        k = srcBLen >> 2U;

                                                                                       
                                                                                  
        do
        {
                                          
          c0 = *py--;
                                
          x3 = *px++;

                                               
                                              
          acc0 += x0 * c0;
                                              
          acc1 += x1 * c0;
                                              
          acc2 += x2 * c0;
                                              
          acc3 += x3 * c0;

                                          
          c0 = *py--;
                                
          x0 = *px++;

                                               
                                              
          acc0 += x1 * c0;
                                              
          acc1 += x2 * c0;
                                              
          acc2 += x3 * c0;
                                              
          acc3 += x0 * c0;

                                          
          c0 = *py--;
                                
          x1 = *px++;

                                               
                                              
          acc0 += x2 * c0;
                                              
          acc1 += x3 * c0;
                                              
          acc2 += x0 * c0;
                                              
          acc3 += x1 * c0;

                                          
          c0 = *py--;
                                
          x2 = *px++;

                                               
                                              
          acc0 += x3 * c0;
                                              
          acc1 += x0 * c0;
                                              
          acc2 += x1 * c0;
                                              
          acc3 += x2 * c0;

        } while (--k);

                                                                                  
                                         
        k = srcBLen % 0x4U;

        while (k > 0U)
        {
                                          
          c0 = *py--;
                                
          x3 = *px++;

                                                
                                              
          acc0 += x0 * c0;
                                              
          acc1 += x1 * c0;
                                              
          acc2 += x2 * c0;
                                              
          acc3 += x3 * c0;

                                                          
          x0 = x1;
          x1 = x2;
          x2 = x3;

                                          
          k--;
        }

                                                                            
        *pOut++ = acc0;
        *pOut++ = acc1;
        *pOut++ = acc2;
        *pOut++ = acc3;

                                                          
        count += 4U;

                                                                            
        px = pSrc1 + count;
        py = pSrc2;

                                    
        blkCnt--;
      }

                                                     
      blkCnt = (uint32_t) blockSize2 % 0x4U;

#else

                                                    
      blkCnt = blockSize2;

#endif                                        

      while (blkCnt > 0U)
      {
                                                          
        sum = 0.0f;

#if defined (ARM_MATH_LOOPUNROLL)

                                                         
        k = srcBLen >> 2U;

        while (k > 0U)
        {
                                                
          sum += *px++ * *py--;
          sum += *px++ * *py--;
          sum += *px++ * *py--;
          sum += *px++ * *py--;

                                      
          k--;
        }

                                                       
        k = srcBLen % 0x4U;

#else

                                                      
        k = srcBLen;

#endif                                        

        while (k > 0U)
        {
                                               
          sum += *px++ * *py--;

                                      
          k--;
        }

                                                                            
        *pOut++ = sum;

                                 
        count++;

                                                                            
        px = pSrc1 + count;
        py = pSrc2;

                                    
        blkCnt--;
      }
    }
    else
    {
                                               
                                                       
      blkCnt = (uint32_t) blockSize2;

      while (blkCnt > 0U)
      {
                                                          
        sum = 0.0f;

                                                        
        k = srcBLen;

        while (k > 0U)
        {
                                               
          sum += *px++ * *py--;

                                      
          k--;
        }

                                                                            
        *pOut++ = sum;

                                     
        count++;

                                                                            
        px = pSrc1 + count;
        py = pSrc2;

                                        
        blkCnt--;
      }
    }


                                 
                                
                                  

                                                                                                                 
                                                                                                                 
           
                                                                        
                                          
       

                                                                               
                                                                              
    count = srcBLen - 1U;

                                   
    pSrc1 = (pIn1 + srcALen) - (srcBLen - 1U);
    px = pSrc1;

                                   
    pSrc2 = pIn2 + (srcBLen - 1U);
    py = pSrc2;

                          
                     
                           

    while (blockSize3 > 0U)
    {
                                                        
      sum = 0.0f;

#if defined (ARM_MATH_LOOPUNROLL)

                                                       
      k = count >> 2U;

      while (k > 0U)
      {
                                                              
        sum += *px++ * *py--;

                                                              
        sum += *px++ * *py--;

                                                              
        sum += *px++ * *py--;

                                                              
        sum += *px++ * *py--;

                                    
        k--;
      }

                                                     
      k = count % 0x4U;

#else

                                                    
      k = count;

#endif                                        

      while (k > 0U)
      {
                                             
                                                 
        sum += *px++ * *py--;

                                    
        k--;
      }

                                                                          
      *pOut++ = sum;

                                                                          
      px = ++pSrc1;
      py = pSrc2;

                               
      count--;

                                      
      blockSize3--;
    }

                                        
    status = ARM_MATH_SUCCESS;
  }

                             
  return (status);

#else
                                      

  const float32_t *pIn1 = pSrcA;                                           
  const float32_t *pIn2 = pSrcB;                                           
        float32_t sum;                                                  
        uint32_t i, j;                                                    
        arm_status status;                                                                

                                                          
  if ((firstIndex + numPoints) > ((srcALen + (srcBLen - 1U))))
  {
                                               
    status = ARM_MATH_ARGUMENT_ERROR;
  }
  else
  {
                                                                          
    for (i = firstIndex; i <= (firstIndex + numPoints - 1); i++)
    {
                                                               
      sum = 0.0f;

                                                                            
      for (j = 0U; j <= i; j++)
      {
                                         
        if (((i - j) < srcBLen) && (j < srcALen))
        {
                                     
          sum += ( pIn1[j] * pIn2[i - j]);
        }
      }

                                                      
      pDst[i] = sum;
    }

                                   
    status = ARM_MATH_SUCCESS;
  }

                             
  return (status);

#endif                                        

}

   
                             
   
