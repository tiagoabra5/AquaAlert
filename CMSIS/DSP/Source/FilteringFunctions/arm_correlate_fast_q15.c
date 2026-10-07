                                                                         
                                  
                                         
                                     
  
                               
                       
  
                                   
                                                                          
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

   
                       
   

   
                  
    
   

   
                                                             
                                                              
                                                              
                                                               
                                                               
                                                                                                                             
                     

                                              
                                                                                
                                                                                                                                            
                                                                    
                                                                                              
                                                                                           
                                                                                                    
                                                                                              
                                                                                                                                

         
                                                                                                                                                                  
   

void arm_correlate_fast_q15(
  const q15_t * pSrcA,
        uint32_t srcALen,
  const q15_t * pSrcB,
        uint32_t srcBLen,
        q15_t * pDst)
{
  const q15_t *pIn1;                                                       
  const q15_t *pIn2;                                                       
        q15_t *pOut = pDst;                                                
        q31_t sum, acc0, acc1, acc2, acc3;                               
  const q15_t *px;                                                                      
  const q15_t *py;                                                                      
  const q15_t *pSrc1;                                                             
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
                                                         
      sum = __SMLAD(read_q15x2_ia ((q15_t **) &px), read_q15x2_ia ((q15_t **) &py), sum);
                                                         
      sum = __SMLAD(read_q15x2_ia ((q15_t **) &px), read_q15x2_ia ((q15_t **) &py), sum);

                                  
      k--;
    }

                                                                            
                                    
    k = count % 0x4U;

    while (k > 0U)
    {
                                            
                                 
      sum = __SMLAD(*px++, *py++, sum);

                                      
      k--;
    }

                                                                        
    *pOut = (q15_t) (sum >> 15);
                                                                               
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

                                   
      x0 = read_q15x2 ((q15_t *) px);
                                   
      x1 = read_q15x2 ((q15_t *) px + 1);
	  px += 2U;

                                                                   
      k = srcBLen >> 2U;

                                                                                     
                                                                                
      do
      {
                                                        
                           
        c0 = read_q15x2_ia ((q15_t **) &py);

                                                
        acc0 = __SMLAD(x0, c0, acc0);

                                                
        acc1 = __SMLAD(x1, c0, acc1);

                             
        x2 = read_q15x2 ((q15_t *) px);

                             
        x3 = read_q15x2 ((q15_t *) px + 1);

                                                
        acc2 = __SMLAD(x2, c0, acc2);

                                                
        acc3 = __SMLAD(x3, c0, acc3);

                                
        c0 = read_q15x2_ia ((q15_t **) &py);

                                                
        acc0 = __SMLAD(x2, c0, acc0);

                                                
        acc1 = __SMLAD(x3, c0, acc1);

                             
        x0 = read_q15x2 ((q15_t *) px + 2);

                             
        x1 = read_q15x2 ((q15_t *) px + 3);
		px += 4U;

                                                
        acc2 = __SMLAD(x0, c0, acc2);

                                                
        acc3 = __SMLAD(x1, c0, acc3);

      } while (--k);

                                                      
                                                           

                                                                                
                                       
      k = srcBLen % 0x4U;

      if (k == 1U)
      {
                       
        c0 = *py;

#ifdef  ARM_MATH_BIG_ENDIAN
        c0 = c0 << 16U;
#else
        c0 = c0 & 0x0000FFFF;
#endif                                  

                       
        x3 = read_q15x2 ((q15_t *) px);
		px++;

                                              
        acc0 = __SMLAD (x0, c0, acc0);
        acc1 = __SMLAD (x1, c0, acc1);
        acc2 = __SMLADX(x1, c0, acc2);
        acc3 = __SMLADX(x3, c0, acc3);
      }

      if (k == 2U)
      {
                             
        c0 = read_q15x2 ((q15_t *) py);

                             
        x3 = read_q15x2 ((q15_t *) px);

                       
        x2 = read_q15x2 ((q15_t *) px + 1);
		px += 2U;

                                              
        acc0 = __SMLAD(x0, c0, acc0);
        acc1 = __SMLAD(x1, c0, acc1);
        acc2 = __SMLAD(x3, c0, acc2);
        acc3 = __SMLAD(x2, c0, acc3);
      }

      if (k == 3U)
      {
                             
        c0 = read_q15x2_ia ((q15_t **) &py);

                             
        x3 = read_q15x2 ((q15_t *) px);

                       
        x2 = read_q15x2 ((q15_t *) px + 1);

                                              
        acc0 = __SMLAD(x0, c0, acc0);
        acc1 = __SMLAD(x1, c0, acc1);
        acc2 = __SMLAD(x3, c0, acc2);
        acc3 = __SMLAD(x2, c0, acc3);

        c0 = (*py);
                       
#ifdef  ARM_MATH_BIG_ENDIAN
        c0 = c0 << 16U;
#else
        c0 = c0 & 0x0000FFFF;
#endif                                  

                        
        x3 = read_q15x2 ((q15_t *) px + 2);
		px += 3U;

                                              
        acc0 = __SMLADX(x1, c0, acc0);
        acc1 = __SMLAD (x2, c0, acc1);
        acc2 = __SMLADX(x2, c0, acc2);
        acc3 = __SMLADX(x3, c0, acc3);
      }

                                                                          
      *pOut = (q15_t) (acc0 >> 15);
                                                                                 
      pOut += inc;

      *pOut = (q15_t) (acc1 >> 15);
      pOut += inc;

      *pOut = (q15_t) (acc2 >> 15);
      pOut += inc;

      *pOut = (q15_t) (acc3 >> 15);
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
                                              
        sum += ((q31_t) *px++ * *py++);
        sum += ((q31_t) *px++ * *py++);
        sum += ((q31_t) *px++ * *py++);
        sum += ((q31_t) *px++ * *py++);

                                    
        k--;
      }

                                                                                
                                       
      k = srcBLen % 0x4U;

      while (k > 0U)
      {
                                              
        sum += ((q31_t) * px++ * *py++);

                                    
        k--;
      }

                                                                          
      *pOut = (q15_t) (sum >> 15);
                                                                                 
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
                                             
        sum += ((q31_t) *px++ * *py++);

                                    
        k--;
      }

                                                                          
      *pOut = (q15_t) (sum >> 15);
                                                                                 
      pOut += inc;

                               
      count++;

                                                                          
      px = pIn1 + count;
      py = pIn2;

                                  
      blkCnt--;
    }
  }

                               
                              
                                

                                                                                                       
                                                                                                       
         
                                                      
                                
     

                                                                             
                                                                       
  count = srcBLen - 1U;

                                 
  pSrc1 = (pIn1 + srcALen) - (srcBLen - 1U);
  px = pSrc1;

                                 
  py = pIn2;

                        
                   
                         

  while (blockSize3 > 0U)
  {
                                                      
    sum = 0;

                                                                 
    k = count >> 2U;

                                                                                   
                                                                              
    while (k > 0U)
    {
                                            
                                                                                           
      sum = __SMLAD(read_q15x2_ia ((q15_t **) &px), read_q15x2_ia ((q15_t **) &py), sum);
                                                                                           
      sum = __SMLAD(read_q15x2_ia ((q15_t **) &px), read_q15x2_ia ((q15_t **) &py), sum);

                                  
      k--;
    }

                                                                            
                                     
    k = count % 0x4U;

    while (k > 0U)
    {
                                            
      sum = __SMLAD(*px++, *py++, sum);

                                  
      k--;
    }

                                                                        
    *pOut = (q15_t) (sum >> 15);
                                                                               
    pOut += inc;

                                                                        
    px = ++pSrc1;
    py = pIn2;

                                 
    count--;

                                    
    blockSize3--;
  }

}

   
                      
   
