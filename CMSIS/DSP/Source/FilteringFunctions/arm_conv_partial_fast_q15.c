                                                                         
                                  
                                            
                                             
  
                               
                       
  
                                   
                                                                          
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

   
                       
   

   
                         
    
   

   
                                                                     
                                                              
                                                              
                                                               
                                                               
                                                                                     
                                                                    
                                                                         
                                 
                                                                        
                                                                                                              
         
                                                                                                                                                                     
   

arm_status arm_conv_partial_fast_q15(
  const q15_t * pSrcA,
        uint32_t srcALen,
  const q15_t * pSrcB,
        uint32_t srcBLen,
        q15_t * pDst,
        uint32_t firstIndex,
        uint32_t numPoints)
{
  const q15_t *pIn1;                                                       
  const q15_t *pIn2;                                                       
        q15_t *pOut = pDst;                                                
        q31_t sum, acc0, acc1, acc2, acc3;                              
  const q15_t *px;                                                                      
  const q15_t *py;                                                                      
  const q15_t *pSrc1, *pSrc2;                                                     
        q31_t x0, x1, x2, x3, c0;                                                     
        uint32_t j, k, count, blkCnt, check;
        int32_t blockSize1, blockSize2, blockSize3;                       
        arm_status status;                                                                

                                                          
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

                               
                     
                               

                                                                  
                                                                          
                                                                                          

                                                 
    while ((count < 4U) && (blockSize1 > 0))
    {
                                                        
      sum = 0;

                                                   
                                             
      k = count;

      while (k > 0U)
      {
                                              
        sum = __SMLAD(*px++, *py--, sum);

                                    
        k--;
      }

                                                                          
      *pOut++ = (q15_t) (sum >> 15);

                                                                          
      py = ++pSrc2;
      px = pIn1;

                               
      count++;

                                  
      blockSize1--;
    }

                                                  
                                                         
                                                       
                                                                          
    py = py - 1;

    while (blockSize1 > 0)
    {
                                                        
      sum = 0;

                                                                   
      k = count >> 2U;

                                                                                     
                                                                               
      while (k > 0U)
      {
                                             
                                                                                        
        sum = __SMLADX(read_q15x2_ia ((q15_t **) &px), read_q15x2_da ((q15_t **) &py), sum);
                                                                                        
        sum = __SMLADX(read_q15x2_ia ((q15_t **) &px), read_q15x2_da ((q15_t **) &py), sum);

                                    
        k--;
      }

                                                                         
                                      
      py = py + 1U;

                                                                              
                                      
      k = count % 0x4U;

      while (k > 0U)
      {
                                              
        sum = __SMLAD(*px++, *py--, sum);

                                    
        k--;
      }

                                                                          
      *pOut++ = (q15_t) (sum >> 15);

                                                                          
      py = ++pSrc2 - 1U;
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
                                                       
      blkCnt = ((uint32_t) blockSize2 >> 2U);

      while (blkCnt > 0U)
      {
        py = py - 1U;

                                          
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
                                                         
                                                 
          c0 = read_q15x2_da ((q15_t **) &py);

                                                                      
          acc0 = __SMLADX(x0, c0, acc0);

                                                                      
          acc1 = __SMLADX(x1, c0, acc1);

                               
          x2 = read_q15x2 ((q15_t *) px);

                               
          x3 = read_q15x2 ((q15_t *) px + 1);

                                                                      
          acc2 = __SMLADX(x2, c0, acc2);

                                                                      
          acc3 = __SMLADX(x3, c0, acc3);

                                                      
          c0 = read_q15x2_da ((q15_t **) &py);

                                                                      
          acc0 = __SMLADX(x2, c0, acc0);

                                                                      
          acc1 = __SMLADX(x3, c0, acc1);

                               
          x0 = read_q15x2 ((q15_t *) px + 2);

                               
          x1 = read_q15x2 ((q15_t *) px + 3);
          px += 4U;

                                                                      
          acc2 = __SMLADX(x0, c0, acc2);

                                                                      
          acc3 = __SMLADX(x1, c0, acc3);

        } while (--k);

                                                        
                                                             

                                                                                  
                                        
        k = srcBLen % 0x4U;

        if (k == 1U)
        {
                                   
          c0 = *(py + 1);
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

                                               
          acc0 = __SMLADX(x0, c0, acc0);
          acc1 = __SMLADX(x1, c0, acc1);
          acc2 = __SMLADX(x3, c0, acc2);
          acc3 = __SMLADX(x2, c0, acc3);
        }

        if (k == 3U)
        {
                                                   
          c0 = read_q15x2 ((q15_t *) py);

                               
          x3 = read_q15x2 ((q15_t *) px);

                         
          x2 = read_q15x2 ((q15_t *) px + 1);

                                               
          acc0 = __SMLADX(x0, c0, acc0);
          acc1 = __SMLADX(x1, c0, acc1);
          acc2 = __SMLADX(x3, c0, acc2);
          acc3 = __SMLADX(x2, c0, acc3);

          c0 = *(py-1);
#ifdef  ARM_MATH_BIG_ENDIAN
          c0 = c0 << 16U;
#else
          c0 = c0 & 0x0000FFFF;
#endif                                  

                          
          x3 =  read_q15x2 ((q15_t *) px + 2);
          px += 3U;

                                                
          acc0 = __SMLADX(x1, c0, acc0);
          acc1 = __SMLAD (x2, c0, acc1);
          acc2 = __SMLADX(x2, c0, acc2);
          acc3 = __SMLADX(x3, c0, acc3);
        }

                                                                              
#ifndef ARM_MATH_BIG_ENDIAN
        write_q15x2_ia (&pOut, __PKHBT(acc0 >> 15, acc1 >> 15, 16));
        write_q15x2_ia (&pOut, __PKHBT(acc2 >> 15, acc3 >> 15, 16));
#else
        write_q15x2_ia (&pOut, __PKHBT(acc1 >> 15, acc0 >> 15, 16));
        write_q15x2_ia (&pOut, __PKHBT(acc3 >> 15, acc2 >> 15, 16));
#endif                                   

                                                          
        count += 4U;

                                                                            
        px = pSrc1 + count;
        py = pSrc2;

                                        
        blkCnt--;
      }

                                                                                             
                                      
      blkCnt = (uint32_t) blockSize2 % 0x4U;

      while (blkCnt > 0U)
      {
                                                          
        sum = 0;

                                                                     
        k = srcBLen >> 2U;

                                                                                       
                                                                                 
        while (k > 0U)
        {
                                                
          sum += ((q31_t) *px++ * *py--);
          sum += ((q31_t) *px++ * *py--);
          sum += ((q31_t) *px++ * *py--);
          sum += ((q31_t) *px++ * *py--);

                                      
          k--;
        }

                                                                                  
                                         
        k = srcBLen % 0x4U;

        while (k > 0U)
        {
                                                
          sum += ((q31_t) *px++ * *py--);

                                          
          k--;
        }

                                                                            
        *pOut++ = (q15_t) (sum >> 15);

                                                          
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
                                               
          sum += ((q31_t) *px++ * *py--);

                                          
          k--;
        }

                                                                            
        *pOut++ = (q15_t) (sum >> 15);

                                     
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
    pIn2 = pSrc2 - 1U;
    py = pIn2;

                          
                     
                           

                                                                  
                                                                             
                                                                                       

                                                 
    j = count >> 2U;

    while ((j > 0U) && (blockSize3 > 0))
    {
                                                        
      sum = 0;

                                                                   
      k = count >> 2U;

                                                                                     
                                                                                
      while (k > 0U)
      {
                                                                            
                                                              
        sum = __SMLADX(read_q15x2_ia ((q15_t **) &px), read_q15x2_da ((q15_t **) &py), sum);
                                                                            
                                                              
        sum = __SMLADX(read_q15x2_ia ((q15_t **) &px), read_q15x2_da ((q15_t **) &py), sum);

                                    
        k--;
      }

                                                                         
                                      
      py = py + 1U;

                                                                              
                                      
      k = count % 0x4U;

      while (k > 0U)
      {
                                                              
        sum = __SMLAD(*px++, *py--, sum);

                                        
        k--;
      }

                                                                          
      *pOut++ = (q15_t) (sum >> 15);

                                                                          
      px = ++pSrc1;
      py = pIn2;

                                   
      count--;

                                      
      blockSize3--;

      j--;
    }

                                                  
                                                    
                                                                    
    py = py + 1U;

    while (blockSize3 > 0)
    {
                                                        
      sum = 0;

                                                                   
      k = count;

      while (k > 0U)
      {
                                              
                                                 
        sum = __SMLAD(*px++, *py--, sum);

                                        
        k--;
      }

                                                                          
      *pOut++ = (q15_t) (sum >> 15);

                                                                          
      px = ++pSrc1;
      py = pSrc2;

                                   
      count--;

                                      
      blockSize3--;
    }

                                        
    status = ARM_MATH_SUCCESS;
  }

                             
  return (status);

}

   
                             
   
