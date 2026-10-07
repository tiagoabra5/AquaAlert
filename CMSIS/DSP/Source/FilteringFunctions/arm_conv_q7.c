                                                                         
                                  
                              
                                            
  
                               
                       
  
                                   
                                                                          
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

   
                       
   

   
                  
    
   

   
                                             
                                                              
                                                              
                                                               
                                                               
                                                                                                                 
                     

                                              
                                                                                   
                                                                                                         
                                                                                                         
                                                                                                                                              
                                                                                                                                   
         
                                                                                                
   

void arm_conv_q7(
  const q7_t * pSrcA,
        uint32_t srcALen,
  const q7_t * pSrcB,
        uint32_t srcBLen,
        q7_t * pDst)
{

#if (1)
                                   

  const q7_t *pIn1;                                                        
  const q7_t *pIn2;                                                        
        q7_t *pOut = pDst;                                                 
  const q7_t *px;                                                                       
  const q7_t *py;                                                                       
  const q7_t *pSrc1, *pSrc2;                                                      
        q31_t sum;                                                       
        uint32_t blockSize1, blockSize2, blockSize3;                      
        uint32_t j, k, count, blkCnt;                                     

#if defined (ARM_MATH_LOOPUNROLL)
        q31_t acc0, acc1, acc2, acc3;                                    
        q31_t input1, input2;                                                         
        q15_t in1, in2;                                                               
        q7_t x0, x1, x2, x3, c0, c1;                                                                                 
#endif

                                                                           
                                                 
                                                                      
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

                                                                                              
                               
                                                                                        
                                                                                     
                                                                        
                                                                                      
                                                                             
                            

                                                  
                                                          
  blockSize1 = srcBLen - 1U;
  blockSize2 = srcALen - (srcBLen - 1U);
  blockSize3 = blockSize1;

                               
                              
                                

                      
                                    
         
                                                                                    
     

                                                                             
                                                                       
  count = 1U;

                                 
  px = pIn1;

                                 
  py = pIn2;


                             
                   
                             

                                   
  while (blockSize1 > 0U)
  {
                                                      
    sum = 0;

#if defined (ARM_MATH_LOOPUNROLL)

                                                     
    k = count >> 2U;

    while (k > 0U)
    {
                       
      in1 = (q15_t) *px++;
      in2 = (q15_t) *px++;
      input1 = ((q31_t) in1 & 0x0000FFFF) | ((q31_t) in2 << 16U);

                                           
      in1 = (q15_t) *py--;
      in2 = (q15_t) *py--;
      input2 = ((q31_t) in1 & 0x0000FFFF) | ((q31_t) in2 << 16U);

                                 
                                 
      sum = __SMLAD(input1, input2, sum);

                       
      in1 = (q15_t) *px++;
      in2 = (q15_t) *px++;
      input1 = ((q31_t) in1 & 0x0000FFFF) | ((q31_t) in2 << 16U);

                                           
      in1 = (q15_t) *py--;
      in2 = (q15_t) *py--;
      input2 = ((q31_t) in1 & 0x0000FFFF) | ((q31_t) in2 << 16U);

                                 
                                 
      sum = __SMLAD(input1, input2, sum);

                                  
      k--;
    }

                                                   
    k = count % 0x4U;

#else

                                             
    k = count;

#endif                                        

    while (k > 0U)
    {
                                           
      sum += ((q15_t) *px++ * *py--);

                                  
      k--;
    }

                                                                        
    *pOut++ = (q7_t) (__SSAT(sum >> 7U, 8));

                                                                        
    py = pIn2 + count;
    px = pIn1;

                             
    count++;

                                
    blockSize1--;
  }

                               
                              
                               

                                                                              
                                                                              
         
                                                                                                    
     

                                 
  px = pIn1;

                                 
  pSrc2 = pIn2 + (srcBLen - 1U);
  py = pSrc2;

                                                                  
  count = 0U;

                        
                   
                         

                                                                                     
                                        
                                                    
  if (srcBLen >= 4U)
  {
#if defined (ARM_MATH_LOOPUNROLL)

                                                     
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
                                        
        c0 = *py--;
                                        
        c1 = *py--;

                              
        x3 = *px++;

                                      
        in1 = (q15_t) x0;
        in2 = (q15_t) x1;

        input1 = ((q31_t) in1 & 0x0000FFFF) | ((q31_t) in2 << 16U);

                                                            
        in1 = (q15_t) c0;
        in2 = (q15_t) c1;

        input2 = ((q31_t) in1 & 0x0000FFFF) | ((q31_t) in2 << 16U);

                                                                    
        acc0 = __SMLAD(input1, input2, acc0);

                                      
        in1 = (q15_t) x1;
        in2 = (q15_t) x2;

        input1 = ((q31_t) in1 & 0x0000FFFF) | ((q31_t) in2 << 16U);

                                                                    
        acc1 = __SMLAD(input1, input2, acc1);

                                      
        in1 = (q15_t) x2;
        in2 = (q15_t) x3;

        input1 = ((q31_t) in1 & 0x0000FFFF) | ((q31_t) in2 << 16U);

                                                                    
        acc2 = __SMLAD(input1, input2, acc2);

                              
        x0 = *px++;

                                      
        in1 = (q15_t) x3;
        in2 = (q15_t) x0;

        input1 = ((q31_t) in1 & 0x0000FFFF) | ((q31_t) in2 << 16U);

                                                                    
        acc3 = __SMLAD(input1, input2, acc3);

                                        
        c0 = *py--;
                                        
        c1 = *py--;

                              
        x1 = *px++;

                                      
        in1 = (q15_t) x2;
        in2 = (q15_t) x3;

        input1 = ((q31_t) in1 & 0x0000FFFF) | ((q31_t) in2 << 16U);

                                                          
        in1 = (q15_t) c0;
        in2 = (q15_t) c1;

        input2 = ((q31_t) in1 & 0x0000FFFF) | ((q31_t) in2 << 16U);

                                                                    
        acc0 = __SMLAD(input1, input2, acc0);

                                      
        in1 = (q15_t) x3;
        in2 = (q15_t) x0;

        input1 = ((q31_t) in1 & 0x0000FFFF) | ((q31_t) in2 << 16U);

                                                                    
        acc1 = __SMLAD(input1, input2, acc1);

                                      
        in1 = (q15_t) x0;
        in2 = (q15_t) x1;

        input1 = ((q31_t) in1 & 0x0000FFFF) | ((q31_t) in2 << 16U);

                                                                    
        acc2 = __SMLAD(input1, input2, acc2);

                              
        x2 = *px++;

                                      
        in1 = (q15_t) x1;
        in2 = (q15_t) x2;

        input1 = ((q31_t) in1 & 0x0000FFFF) | ((q31_t) in2 << 16U);

                                                                    
        acc3 = __SMLAD(input1, input2, acc3);

      } while (--k);

                                                                                
                                       
      k = srcBLen % 0x4U;

      while (k > 0U)
      {
                                        
        c0 = *py--;
                              
        x3 = *px++;

                                              
                                            
        acc0 += ((q15_t) x0 * c0);
                                            
        acc1 += ((q15_t) x1 * c0);
                                            
        acc2 += ((q15_t) x2 * c0);
                                            
        acc3 += ((q15_t) x3 * c0);

                                                        
        x0 = x1;
        x1 = x2;
        x2 = x3;

                                    
        k--;
      }

                                                                          
      *pOut++ = (q7_t) (__SSAT(acc0 >> 7U, 8));
      *pOut++ = (q7_t) (__SSAT(acc1 >> 7U, 8));
      *pOut++ = (q7_t) (__SSAT(acc2 >> 7U, 8));
      *pOut++ = (q7_t) (__SSAT(acc3 >> 7U, 8));

                                                        
      count += 4U;

                                                                          
      px = pIn1 + count;
      py = pSrc2;

                                  
      blkCnt--;
    }

                                                   
    blkCnt = blockSize2 % 0x4U;

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

                                                           
        in1 = (q15_t) *px++;
        in2 = (q15_t) *px++;
        input1 = ((q31_t) in1 & 0x0000FFFF) | ((q31_t) in2 << 16U);

                                                           
        in1 = (q15_t) *py--;
        in2 = (q15_t) *py--;
        input2 = ((q31_t) in1 & 0x0000FFFF) | ((q31_t) in2 << 16U);

                                             
        sum = __SMLAD(input1, input2, sum);

                                                           
        in1 = (q15_t) *px++;
        in2 = (q15_t) *px++;
        input1 = ((q31_t) in1 & 0x0000FFFF) | ((q31_t) in2 << 16U);

                                                           
        in1 = (q15_t) *py--;
        in2 = (q15_t) *py--;
        input2 = ((q31_t) in1 & 0x0000FFFF) | ((q31_t) in2 << 16U);

                                             
        sum = __SMLAD(input1, input2, sum);

                                    
        k--;
      }

                                                     
      k = srcBLen % 0x4U;

#else

                                                    
      k = srcBLen;

#endif                                        

      while (k > 0U)
      {
                                             
        sum += ((q15_t) *px++ * *py--);

                                        
        k--;
      }

                                                                          
      *pOut++ = (q7_t) (__SSAT(sum >> 7U, 8));

                                                        
      count++;

                                                                          
      px = pIn1 + count;
      py = pSrc2;

                                      
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
                                             
        sum += ((q15_t) *px++ * *py--);

                                        
        k--;
      }

                                                                          
      *pOut++ = (q7_t) (__SSAT(sum >> 7U, 8));

                                   
      count++;

                                                                          
      px = pIn1 + count;
      py = pSrc2;

                                  
      blkCnt--;
    }
  }


                               
                              
                                

                                                                                                               
                                                                                                               
         
                                                                      
                                        
     

                                                                             
                                                                            

                                 
  pSrc1 = pIn1 + (srcALen - (srcBLen - 1U));
  px = pSrc1;

                                 
  pSrc2 = pIn2 + (srcBLen - 1U);
  py = pSrc2;

                        
                   
                         

  while (blockSize3 > 0U)
  {
                                                      
    sum = 0;

#if defined (ARM_MATH_LOOPUNROLL)

                                                     
    k = blockSize3 >> 2U;

    while (k > 0U)
    {
                                                                                                                
      in1 = (q15_t) *px++;
      in2 = (q15_t) *px++;
      input1 = ((q31_t) in1 & 0x0000FFFF) | ((q31_t) in2 << 16U);

                                                                                            
      in1 = (q15_t) *py--;
      in2 = (q15_t) *py--;
      input2 = ((q31_t) in1 & 0x0000FFFF) | ((q31_t) in2 << 16U);

                                                            
                                                            
      sum = __SMLAD(input1, input2, sum);

                                                                                                                
      in1 = (q15_t) *px++;
      in2 = (q15_t) *px++;
      input1 = ((q31_t) in1 & 0x0000FFFF) | ((q31_t) in2 << 16U);

                                                                                            
      in1 = (q15_t) *py--;
      in2 = (q15_t) *py--;
      input2 = ((q31_t) in1 & 0x0000FFFF) | ((q31_t) in2 << 16U);

                                                            
                                                            
      sum = __SMLAD(input1, input2, sum);

                                  
      k--;
    }

                                                   
    k = blockSize3 % 0x4U;

#else

                                                  
    k = blockSize3;

#endif                                        

    while (k > 0U)
    {
                                           
                                               
      sum += ((q15_t) *px++ * *py--);

                                  
      k--;
    }

                                                                        
    *pOut++ = (q7_t) (__SSAT(sum >> 7U, 8));

                                                                        
    px = ++pSrc1;
    py = pSrc2;

                                
    blockSize3--;
  }

#else
                                      

  const q7_t *pIn1 = pSrcA;                                                
  const q7_t *pIn2 = pSrcB;                                                
        q31_t sum;                                                      
        uint32_t i, j;                                                    

                                                                       
  for (i = 0U; i < (srcALen + srcBLen - 1U); i++)
  {
                                                              
    sum = 0;

                                                                          
    for (j = 0U; j <= i; j++)
    {
                                       
      if (((i - j) < srcBLen) && (j < srcALen))
      {
                                   
        sum += ((q15_t) pIn1[j] * pIn2[i - j]);
      }
    }

                                                    
    pDst[i] = (q7_t) __SSAT((sum >> 7U), 8U);
  }

#endif                                        

}

   
                      
   
