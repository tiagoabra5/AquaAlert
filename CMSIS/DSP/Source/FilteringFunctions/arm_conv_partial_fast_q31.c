                                                                         
                                  
                                            
                                             
  
                               
                       
  
                                   
                                                                          
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

   
                       
   

   
                         
    
   

   
                                                                     
                                                              
                                                              
                                                               
                                                               
                                                                                     
                                                                    
                                                                         
                                 
                                                                        
                                                                                                              

         
                                                                                                                                                                 
   

arm_status arm_conv_partial_fast_q31(
  const q31_t * pSrcA,
        uint32_t srcALen,
  const q31_t * pSrcB,
        uint32_t srcBLen,
        q31_t * pDst,
        uint32_t firstIndex,
        uint32_t numPoints)
{
  const q31_t *pIn1;                                                       
  const q31_t *pIn2;                                                       
        q31_t *pOut = pDst;                                                
  const q31_t *px;                                                                      
  const q31_t *py;                                                                      
  const q31_t *pSrc1, *pSrc2;                                                     
        q31_t sum;                                                       
        uint32_t j, k, count, check, blkCnt;
        int32_t blockSize1, blockSize2, blockSize3;                       
        arm_status status;                                                                

#if defined (ARM_MATH_LOOPUNROLL)
        q31_t acc0, acc1, acc2, acc3;                                    
        q31_t x0, x1, x2, x3, c0;
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
    blockSize2 = (int32_t) check - ((blockSize3 + blockSize1) + (int32_t) firstIndex);
    blockSize2 = (blockSize2 > 0) ? blockSize2 : 0;

                                                                                                
                                 
                                                                                          
                                                                                       
                                                                          
                                                                                        
                                                                               
                              

                                                        
                                                
    pOut = pDst + firstIndex;

                                 
                                
                                  

                        
                                      
           
                                                                                      
       

                                                                               
                                                                       
                                                           
                                                          
    count = 1U + firstIndex;

                                   
    px = pIn1;

                                   
    pSrc2 = pIn2 + firstIndex;
    py = pSrc2;

                               
                     
                               

                                     
    while (blockSize1 > 0U)
    {
                                                        
      sum = 0;

#if defined (ARM_MATH_LOOPUNROLL)

                                                       
      k = count >> 2U;

      while (k > 0U)
      {
                                   
        sum = (q31_t) ((((q63_t) sum << 32) +
                        ((q63_t) *px++ * (*py--))) >> 32);

                                   
        sum = (q31_t) ((((q63_t) sum << 32) +
                        ((q63_t) *px++ * (*py--))) >> 32);

                                   
        sum = (q31_t) ((((q63_t) sum << 32) +
                        ((q63_t) *px++ * (*py--))) >> 32);

                                   
        sum = (q31_t) ((((q63_t) sum << 32) +
                        ((q63_t) *px++ * (*py--))) >> 32);

                                    
        k--;
      }

                                                     
      k = count % 0x4U;

#else

                                               
      k = count;

#endif                                        

      while (k > 0U)
      {
                                             
        sum = (q31_t) ((((q63_t) sum << 32) +
                        ((q63_t) *px++ * (*py--))) >> 32);

                                    
        k--;
      }

                                                                          
      *pOut++ = sum << 1;

                                                                          
      py = ++pSrc2;
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
                                          
        acc0 = 0;
        acc1 = 0;
        acc2 = 0;
        acc3 = 0;

                                           
        x0 = *px++;
        x1 = *px++;
        x2 = *px++;

                                                                     
        k = srcBLen >> 2U;

                                                                                       
                                                                                  
        do
        {
                                          
          c0 = *py--;
                                
          x3 = *px++;

                                               
                                              
          acc0 = (q31_t) ((((q63_t) acc0 << 32) + ((q63_t) x0 * c0)) >> 32);
                                              
          acc1 = (q31_t) ((((q63_t) acc1 << 32) + ((q63_t) x1 * c0)) >> 32);
                                              
          acc2 = (q31_t) ((((q63_t) acc2 << 32) + ((q63_t) x2 * c0)) >> 32);
                                              
          acc3 = (q31_t) ((((q63_t) acc3 << 32) + ((q63_t) x3 * c0)) >> 32);

                                          
          c0 = *py--;
                                
          x0 = *px++;

                                               
                                              
          acc0 = (q31_t) ((((q63_t) acc0 << 32) + ((q63_t) x1 * c0)) >> 32);
                                              
          acc1 = (q31_t) ((((q63_t) acc1 << 32) + ((q63_t) x2 * c0)) >> 32);
                                              
          acc2 = (q31_t) ((((q63_t) acc2 << 32) + ((q63_t) x3 * c0)) >> 32);
                                              
          acc3 = (q31_t) ((((q63_t) acc3 << 32) + ((q63_t) x0 * c0)) >> 32);

                                          
          c0 = *py--;
                                
          x1 = *px++;

                                                
                                              
          acc0 = (q31_t) ((((q63_t) acc0 << 32) + ((q63_t) x2 * c0)) >> 32);
                                              
          acc1 = (q31_t) ((((q63_t) acc1 << 32) + ((q63_t) x3 * c0)) >> 32);
                                              
          acc2 = (q31_t) ((((q63_t) acc2 << 32) + ((q63_t) x0 * c0)) >> 32);
                                              
          acc3 = (q31_t) ((((q63_t) acc3 << 32) + ((q63_t) x1 * c0)) >> 32);

                                          
          c0 = *py--;
                                
          x2 = *px++;

                                                
                                              
          acc0 = (q31_t) ((((q63_t) acc0 << 32) + ((q63_t) x3 * c0)) >> 32);
                                              
          acc1 = (q31_t) ((((q63_t) acc1 << 32) + ((q63_t) x0 * c0)) >> 32);
                                              
          acc2 = (q31_t) ((((q63_t) acc2 << 32) + ((q63_t) x1 * c0)) >> 32);
                                              
          acc3 = (q31_t) ((((q63_t) acc3 << 32) + ((q63_t) x2 * c0)) >> 32);

        } while (--k);

                                                                                  
                                         
        k = srcBLen % 0x4U;

        while (k > 0U)
        {
                                          
          c0 = *py--;
                                
          x3 = *px++;

                                                
                                              
          acc0 = (q31_t) ((((q63_t) acc0 << 32) + ((q63_t) x0 * c0)) >> 32);
                                              
          acc1 = (q31_t) ((((q63_t) acc1 << 32) + ((q63_t) x1 * c0)) >> 32);
                                              
          acc2 = (q31_t) ((((q63_t) acc2 << 32) + ((q63_t) x2 * c0)) >> 32);
                                              
          acc3 = (q31_t) ((((q63_t) acc3 << 32) + ((q63_t) x3 * c0)) >> 32);

                                                          
          x0 = x1;
          x1 = x2;
          x2 = x3;

                                          
          k--;
        }

                                                                            
        *pOut++ = (q31_t) (acc0 << 1);
        *pOut++ = (q31_t) (acc1 << 1);
        *pOut++ = (q31_t) (acc2 << 1);
        *pOut++ = (q31_t) (acc3 << 1);

                                                          
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
                                                          
        sum = 0;

#if defined (ARM_MATH_LOOPUNROLL)

                                                         
        k = srcBLen >> 2U;

        while (k > 0U)
        {
                                                
          sum = (q31_t) ((((q63_t) sum << 32) +
                          ((q63_t) * px++ * (*py--))) >> 32);
          sum = (q31_t) ((((q63_t) sum << 32) +
                          ((q63_t) * px++ * (*py--))) >> 32);
          sum = (q31_t) ((((q63_t) sum << 32) +
                          ((q63_t) * px++ * (*py--))) >> 32);
          sum = (q31_t) ((((q63_t) sum << 32) +
                          ((q63_t) * px++ * (*py--))) >> 32);

                                      
          k--;
        }

                                                       
        k = srcBLen % 0x4U;

#else

                                                      
        k = srcBLen;

#endif                                        

        while (k > 0U)
        {
                                               
          sum = (q31_t) ((((q63_t) sum << 32) +
                          ((q63_t) *px++ * (*py--))) >> 32);

                                      
          k--;
        }

                                                                            
        *pOut++ = sum << 1;

                                 
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
                                                          
        sum = 0;

                                                        
        k = srcBLen;

        while (k > 0U)
        {
                                               
          sum = (q31_t) ((((q63_t) sum << 32) +
                          ((q63_t) *px++ * (*py--))) >> 32);

                                      
          k--;
        }

                                                                            
        *pOut++ = sum << 1;

                                     
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
                                                        
      sum = 0;

#if defined (ARM_MATH_LOOPUNROLL)

                                                       
      k = count >> 2U;

      while (k > 0U)
      {
                                                              
        sum = (q31_t) ((((q63_t) sum << 32) +
                        ((q63_t) *px++ * (*py--))) >> 32);

                                                              
        sum = (q31_t) ((((q63_t) sum << 32) +
                        ((q63_t) *px++ * (*py--))) >> 32);

                                                              
        sum = (q31_t) ((((q63_t) sum << 32) +
                        ((q63_t) *px++ * (*py--))) >> 32);

                                                              
        sum = (q31_t) ((((q63_t) sum << 32) +
                        ((q63_t) *px++ * (*py--))) >> 32);

                                    
        k--;
      }

                                                     
      k = count % 0x4U;

#else

                                                    
      k = count;

#endif                                        

      while (k > 0U)
      {
                                              
                                                 
        sum = (q31_t) ((((q63_t) sum << 32) +
                        ((q63_t) *px++ * (*py--))) >> 32);

                                    
        k--;
      }

                                                                          
      *pOut++ = sum << 1;

                                                                          
      px = ++pSrc1;
      py = pSrc2;

                               
      count--;

                                      
      blockSize3--;
    }

                                        
    status = ARM_MATH_SUCCESS;
  }

                             
  return (status);

}

   
                             
   
