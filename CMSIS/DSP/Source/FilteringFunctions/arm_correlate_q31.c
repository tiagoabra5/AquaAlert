                                                                         
                                  
                                    
                                             
  
                               
                       
  
                                   
                                                                          
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

   
                       
   

   
                  
    
   

   
                                              
                                                              
                                                              
                                                               
                                                               
                                                                                                                             
                     

                                              
                                                                                    
                                                                                                                                                                  
                                                                    
                                                                                              
                                                                                           
                                                                                                    
                                                                                              
                                                                                                                           

         
                                                                                                                        
   

void arm_correlate_q31(
  const q31_t * pSrcA,
        uint32_t srcALen,
  const q31_t * pSrcB,
        uint32_t srcBLen,
        q31_t * pDst)
{

#if (1)
                                   

  const q31_t *pIn1;                                                       
  const q31_t *pIn2;                                                       
        q31_t *pOut = pDst;                                                
  const q31_t *px;                                                                      
  const q31_t *py;                                                                      
  const q31_t *pSrc1;                                                             
        q63_t sum;                                                       
        uint32_t blockSize1, blockSize2, blockSize3;                      
        uint32_t j, k, count, blkCnt;                                     
        uint32_t outBlockSize;
        int32_t inc = 1;                                                                 

#if defined (ARM_MATH_LOOPUNROLL)
        q63_t acc0, acc1, acc2;                                          
        q31_t x0, x1, x2, c0;                                                                                            
#endif

                                                                           
                                                 
                                                                      
                                               
                                                                                                   
                                                              
                                                                                                   
                                    
                                                                                       
                          
                                                                                       
                          
                                                                                     
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

#if defined (ARM_MATH_LOOPUNROLL)

                                                     
    k = count >> 2U;

    while (k > 0U)
    {
                                 
      sum += (q63_t) *px++ * (*py++);

                                 
      sum += (q63_t) *px++ * (*py++);

                                 
      sum += (q63_t) *px++ * (*py++);

                                 
      sum += (q63_t) *px++ * (*py++);

                                  
      k--;
    }

                                                   
    k = count % 0x4U;

#else

                                             
    k = count;

#endif                                        

    while (k > 0U)
    {
                                           
                                 
      sum += (q63_t) *px++ * (*py++);

                                  
      k--;
    }

                                                                        
    *pOut = (q31_t) (sum >> 31);
                                                                               
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
#if defined (ARM_MATH_LOOPUNROLL)

                          
    blkCnt = blockSize2 / 3;

    while (blkCnt > 0U)
    {
                                        
      acc0 = 0;
      acc1 = 0;
      acc2 = 0;

                                   
      x0 = *px++;
      x1 = *px++;

                                                                   
      k = srcBLen / 3;

                                                                                     
                                                                                
      do
      {
                              
        c0 = *(py);
                              
        x2 = *(px);

                                             
                                  
        acc0 += ((q63_t) x0 * c0);
                                  
        acc1 += ((q63_t) x1 * c0);
                                  
        acc2 += ((q63_t) x2 * c0);

                              
        c0 = *(py + 1U);
                              
        x0 = *(px + 1U);

                                             
                                  
        acc0 += ((q63_t) x1 * c0);
                                  
        acc1 += ((q63_t) x2 * c0);
                                  
        acc2 += ((q63_t) x0 * c0);

                              
        c0 = *(py + 2U);
                              
        x1 = *(px + 2U);

                                             
                                  
        acc0 += ((q63_t) x2 * c0);
                                  
        acc1 += ((q63_t) x0 * c0);
                                  
        acc2 += ((q63_t) x1 * c0);

                                     
        px += 3U;
        py += 3U;

      } while (--k);

                                                                                
                                       
      k = srcBLen - (3 * (srcBLen / 3));

      while (k > 0U)
      {
                              
        c0 = *(py++);

                              
        x2 = *(px++);

                                              
                                  
        acc0 += ((q63_t) x0 * c0);
                                  
        acc1 += ((q63_t) x1 * c0);
                                  
        acc2 += ((q63_t) x2 * c0);

                                                        
        x0 = x1;
        x1 = x2;

                                    
        k--;
      }

                                                                          
      *pOut = (q31_t) (acc0 >> 31);
                                                                                 
      pOut += inc;

      *pOut = (q31_t) (acc1 >> 31);
      pOut += inc;

      *pOut = (q31_t) (acc2 >> 31);
      pOut += inc;

                                                        
      count += 3U;

                                                                          
      px = pIn1 + count;
      py = pIn2;

                                  
      blkCnt--;
    }

                                                   
    blkCnt = blockSize2 - 3 * (blockSize2 / 3);

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
                                              
        sum += (q63_t) *px++ * *py++;
        sum += (q63_t) *px++ * *py++;
        sum += (q63_t) *px++ * *py++;
        sum += (q63_t) *px++ * *py++;

                                    
        k--;
      }

                                                     
      k = srcBLen % 0x4U;

#else

                                                    
      k = srcBLen;

#endif                                        

      while (k > 0U)
      {
                                             
        sum += (q63_t) *px++ * *py++;

                                        
        k--;
      }

                                                                          
      *pOut = (q31_t) (sum >> 31);
                                                                                 
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
                                             
        sum += (q63_t) *px++ * *py++;

                                        
        k--;
      }

                                                                          
      *pOut = (q31_t) (sum >> 31);
                                                                                 
      pOut += inc;

                               
      count++;

                                                                          
      px = pIn1 + count;
      py = pIn2;

                                  
      blkCnt--;
    }
  }


                               
                              
                                

                                                                                                       
                                                                                                       
         
                                                      
                                
     

                                                                             
                                                                       
  count = srcBLen - 1U;

                                 
  pSrc1 = pIn1 + (srcALen - (srcBLen - 1U));
  px = pSrc1;

                                 
  py = pIn2;

                        
                   
                         

  while (blockSize3 > 0U)
  {
                                                      
    sum = 0;

#if defined (ARM_MATH_LOOPUNROLL)

                                                     
    k = count >> 2U;

    while (k > 0U)
    {
                                           
                                                  
      sum += (q63_t) *px++ * *py++;

                                                  
      sum += (q63_t) *px++ * *py++;

                                                  
      sum += (q63_t) *px++ * *py++;

                                                  
      sum += (q63_t) *px++ * *py++;

                                  
      k--;
    }

                                                   
    k = count % 0x4U;

#else

                                                  
    k = count;

#endif                                        

    while (k > 0U)
    {
                                           
      sum += (q63_t) *px++ * *py++;

                                  
      k--;
    }

                                                                        
    *pOut = (q31_t) (sum >> 31);
                                                                               
    pOut += inc;

                                                                        
    px = ++pSrc1;
    py = pIn2;

                             
    count--;

                                
    blockSize3--;
  }

#else
                                      

  const q31_t *pIn1 = pSrcA;                                               
  const q31_t *pIn2 = pSrcB + (srcBLen - 1U);                              
        q63_t sum;                                                       
        uint32_t i = 0U, j;                                               
        uint32_t inv = 0U;                                                     
        uint32_t tot = 0U;                                         

                                                                           
                                                 
                                                                      
                                               
                                                                                                   
                                       
                                                                           
                                                                             
                                                                     
                                                                            
                                     
                                                                            
                                   
                                                                            
                                                                   

                                                      
  tot = ((srcALen + srcBLen) - 2U);

  if (srcALen > srcBLen)
  {
                                                                    
    j = srcALen - srcBLen;

                                                   
    pDst += j;
  }

  else if (srcALen < srcBLen)
  {
                                          
    pIn1 = pSrcB;

                                                     
    pIn2 = pSrcA + (srcALen - 1U);

                                                          
    pDst = pDst + tot;

                              
    j = srcALen;
    srcALen = srcBLen;
    srcBLen = j;

                                  
    inv = 1;
  }

                                                                       
  for (i = 0U; i <= tot; i++)
  {
                                                              
    sum = 0;

                                                                          
    for (j = 0U; j <= i; j++)
    {
                                       
      if (((i - j) < srcBLen) && (j < srcALen))
      {
                                   
        sum += ((q63_t) pIn1[j] * pIn2[-((int32_t) i - j)]);
      }
    }

                                                    
    if (inv == 1)
      *pDst-- = (q31_t) (sum >> 31U);
    else
      *pDst++ = (q31_t) (sum >> 31U);
  }

#endif                                        

}

   
                      
   
