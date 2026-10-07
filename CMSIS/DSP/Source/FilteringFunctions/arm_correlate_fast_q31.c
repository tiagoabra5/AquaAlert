                                                                         
                                  
                                         
                                     
  
                               
                       
  
                                   
                                                                          
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

   
                       
   

   
                  
    
   

   
                                                             
                                                              
                                                              
                                                               
                                                               
                                                                                                                             
                     

                                              
                                                                                                                        
                                                                                             
                                                                                                  
                                                                                        
      
                                                                                                                                                                                       
                                                                                                
                                                                                           
                                                                                                    
                                                                                              

        
                                                                                                                                                             
   

void arm_correlate_fast_q31(
  const q31_t * pSrcA,
        uint32_t srcALen,
  const q31_t * pSrcB,
        uint32_t srcBLen,
        q31_t * pDst)
{
  const q31_t *pIn1;                                                       
  const q31_t *pIn2;                                                       
        q31_t *pOut = pDst;                                                
  const q31_t *px;                                                                      
  const q31_t *py;                                                                      
  const q31_t *pSrc1;                                                             
        q31_t sum, acc0, acc1, acc2, acc3;                               
        q31_t x0, x1, x2, x3, c0;                                                                                        
        uint32_t blockSize1, blockSize2, blockSize3;                      
        uint32_t j, k, count, blkCnt;                                     
        uint32_t outBlockSize;
        int32_t inc = 1;                                                                 

                                                                           
                                                 
                                                                      
  if (srcALen >= srcBLen)
  {
                                          
    pIn1 = pSrcA;

                                          
    pIn2 = pSrcB;

                                                
    outBlockSize = (2U * srcALen) - 1U;

                                                           
                                   
                                                        
                                                
    j = outBlockSize - (srcALen + (srcBLen - 1U));

                                                         
    pOut += j;

  }
  else
  {
                                          
    pIn1 = pSrcB;

                                          
    pIn2 = pSrcA;

                                                                     
    j = srcBLen;
    srcBLen = srcALen;
    srcALen = j;

                                                
                                                                              
    pOut = pDst + ((srcALen + srcBLen) - 2U);

                                                   
    inc = -1;

  }

                               
                                                                                        
                                                                                     
                                                                        
                                                                                      
                                                                             
                            

                                                  
                                                          
  blockSize1 = srcBLen - 1U;
  blockSize2 = srcALen - (srcBLen - 1U);
  blockSize3 = blockSize1;

                               
                              
                                

                                
                                                        
         
                                                                          
     

                                                                             
                                                                       
  count = 1U;

                                 
  px = pIn1;

                                 
  pSrc1 = pIn2 + (srcBLen - 1U);
  py = pSrc1;

                             
                   
                             

                                   
  while (blockSize1 > 0U)
  {
                                                      
    sum = 0;

                                                                 
    k = count >> 2U;

                                                                                   
                                                                              
    while (k > 0U)
    {
                                 
      sum = (q31_t) ((((q63_t) sum << 32) +
                      ((q63_t) *px++ * (*py++))) >> 32);

                                 
      sum = (q31_t) ((((q63_t) sum << 32) +
                      ((q63_t) *px++ * (*py++))) >> 32);

                                 
      sum = (q31_t) ((((q63_t) sum << 32) +
                      ((q63_t) *px++ * (*py++))) >> 32);

                                 
      sum = (q31_t) ((((q63_t) sum << 32) +
                      ((q63_t) *px++ * (*py++))) >> 32);

                                  
      k--;
    }

                                                                            
                                     
    k = count % 0x4U;

    while (k > 0U)
    {
                                           
                                 
      sum = (q31_t) ((((q63_t) sum << 32) +
                      ((q63_t) *px++ * (*py++))) >> 32);

                                  
      k--;
    }

                                                                        
    *pOut = sum << 1;
                                                                               
    pOut += inc;

                                                                        
    py = pSrc1 - count;
    px = pIn1;

                             
    count++;

                                
    blockSize1--;
  }

                               
                              
                               

                                                                      
                                                                    
         
                                                                                                      
     

                                 
  px = pIn1;

                                 
  py = pIn2;

                                                                  
  count = 0U;

                        
                   
                         

                                                                                     
                                        
                                                    
  if (srcBLen >= 4U)
  {
                                           
    blkCnt = blockSize2 >> 2U;

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
                              
        c0 = *py++;
                              
        x3 = *px++;

                                             
                                  
        acc0 = (q31_t) ((((q63_t) acc0 << 32) + ((q63_t) x0 * c0)) >> 32);
                                  
        acc1 = (q31_t) ((((q63_t) acc1 << 32) + ((q63_t) x1 * c0)) >> 32);
                                  
        acc2 = (q31_t) ((((q63_t) acc2 << 32) + ((q63_t) x2 * c0)) >> 32);
                                  
        acc3 = (q31_t) ((((q63_t) acc3 << 32) + ((q63_t) x3 * c0)) >> 32);


                              
        c0 = *py++;
                              
        x0 = *px++;

                                             
                                  
        acc0 = (q31_t) ((((q63_t) acc0 << 32) + ((q63_t) x1 * c0)) >> 32);
                                  
        acc1 = (q31_t) ((((q63_t) acc1 << 32) + ((q63_t) x2 * c0)) >> 32);
                                  
        acc2 = (q31_t) ((((q63_t) acc2 << 32) + ((q63_t) x3 * c0)) >> 32);
                                  
        acc3 = (q31_t) ((((q63_t) acc3 << 32) + ((q63_t) x0 * c0)) >> 32);


                              
        c0 = *py++;
                              
        x1 = *px++;

                                              
                                  
        acc0 = (q31_t) ((((q63_t) acc0 << 32) + ((q63_t) x2 * c0)) >> 32);
                                  
        acc1 = (q31_t) ((((q63_t) acc1 << 32) + ((q63_t) x3 * c0)) >> 32);
                                  
        acc2 = (q31_t) ((((q63_t) acc2 << 32) + ((q63_t) x0 * c0)) >> 32);
                                  
        acc3 = (q31_t) ((((q63_t) acc3 << 32) + ((q63_t) x1 * c0)) >> 32);


                              
        c0 = *py++;
                              
        x2 = *px++;

                                              
                                  
        acc0 = (q31_t) ((((q63_t) acc0 << 32) + ((q63_t) x3 * c0)) >> 32);
                                  
        acc1 = (q31_t) ((((q63_t) acc1 << 32) + ((q63_t) x0 * c0)) >> 32);
                                  
        acc2 = (q31_t) ((((q63_t) acc2 << 32) + ((q63_t) x1 * c0)) >> 32);
                                  
        acc3 = (q31_t) ((((q63_t) acc3 << 32) + ((q63_t) x2 * c0)) >> 32);


      } while (--k);

                                                                                
                                       
      k = srcBLen % 0x4U;

      while (k > 0U)
      {
                              
        c0 = *py++;
                              
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

                                                                          
      *pOut = (q31_t) (acc0 << 1);
                                                                                 
      pOut += inc;

      *pOut = (q31_t) (acc1 << 1);
      pOut += inc;

      *pOut = (q31_t) (acc2 << 1);
      pOut += inc;

      *pOut = (q31_t) (acc3 << 1);
      pOut += inc;

                                                        
      count += 4U;

                                                                          
      px = pIn1 + count;
      py = pIn2;

                                  
      blkCnt--;
    }

                                                                                           
                                     
    blkCnt = blockSize2 % 0x4U;

    while (blkCnt > 0U)
    {
                                                        
      sum = 0;

                                                                   
      k = srcBLen >> 2U;

                                                                                     
                                                                                
      while (k > 0U)
      {
                                              
        sum = (q31_t) ((((q63_t) sum << 32) +
                        ((q63_t) *px++ * (*py++))) >> 32);
        sum = (q31_t) ((((q63_t) sum << 32) +
                        ((q63_t) *px++ * (*py++))) >> 32);
        sum = (q31_t) ((((q63_t) sum << 32) +
                        ((q63_t) *px++ * (*py++))) >> 32);
        sum = (q31_t) ((((q63_t) sum << 32) +
                        ((q63_t) *px++ * (*py++))) >> 32);

                                    
        k--;
      }

                                                                                
                                       
      k = srcBLen % 0x4U;

      while (k > 0U)
      {
                                             
        sum = (q31_t) ((((q63_t) sum << 32) +
                        ((q63_t) *px++ * (*py++))) >> 32);

                                    
        k--;
      }

                                                                          
      *pOut = sum << 1;
                                                                                 
      pOut += inc;

                               
      count++;

                                                                          
      px = pIn1 + count;
      py = pIn2;

                                  
      blkCnt--;
    }
  }
  else
  {
                                             
                                                     
    blkCnt = blockSize2;

    while (blkCnt > 0U)
    {
                                                        
      sum = 0;

                                                      
      k = srcBLen;

      while (k > 0U)
      {
                                             
        sum = (q31_t) ((((q63_t) sum << 32) +
                        ((q63_t) *px++ * (*py++))) >> 32);

                                    
        k--;
      }

                                                                          
      *pOut = sum << 1;
                                                                                 
      pOut += inc;

                               
      count++;

                                                                          
      px = pIn1 + count;
      py = pIn2;

                                  
      blkCnt--;
    }
  }


                               
                              
                                

                                                                                                       
                                                                                                       
         
                                                      
                                
     

                                                                             
                                                                       
  count = srcBLen - 1U;

                                 
  pSrc1 = ((pIn1 + srcALen) - srcBLen) + 1U;
  px = pSrc1;

                                 
  py = pIn2;

                        
                   
                         

  while (blockSize3 > 0U)
  {
                                                      
    sum = 0;

                                                                 
    k = count >> 2U;

                                                                                   
                                                                              
    while (k > 0U)
    {
                                           
                                                  
      sum = (q31_t) ((((q63_t) sum << 32) +
                      ((q63_t) *px++ * (*py++))) >> 32);

                                                  
      sum = (q31_t) ((((q63_t) sum << 32) +
                      ((q63_t) *px++ * (*py++))) >> 32);

                                                  
      sum = (q31_t) ((((q63_t) sum << 32) +
                      ((q63_t) *px++ * (*py++))) >> 32);

                                                  
      sum = (q31_t) ((((q63_t) sum << 32) +
                      ((q63_t) *px++ * (*py++))) >> 32);

                                  
      k--;
    }

                                                                            
                                     
    k = count % 0x4U;

    while (k > 0U)
    {
                                           
      sum = (q31_t) ((((q63_t) sum << 32) +
                      ((q63_t) *px++ * (*py++))) >> 32);

                                  
      k--;
    }

                                                                        
    *pOut = sum << 1;
                                                                               
    pOut += inc;

                                                                        
    px = ++pSrc1;
    py = pIn2;

                             
    count--;

                                
    blockSize3--;
  }

}

   
                      
   
