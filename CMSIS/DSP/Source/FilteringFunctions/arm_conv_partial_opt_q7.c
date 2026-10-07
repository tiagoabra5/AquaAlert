                                                                         
                                  
                                          
                                                    
  
                               
                       
  
                                   
                                                                          
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

   
                       
   

   
                         
    
   

   
                                                     
                                                              
                                                              
                                                               
                                                               
                                                                                     
                                                                    
                                                                         
                                                                                                                                
                                                                                                   
                                 
                                                                        
                                                                                                              
   

arm_status arm_conv_partial_opt_q7(
  const q7_t * pSrcA,
        uint32_t srcALen,
  const q7_t * pSrcB,
        uint32_t srcBLen,
        q7_t * pDst,
        uint32_t firstIndex,
        uint32_t numPoints,
        q15_t * pScratch1,
        q15_t * pScratch2)
{
        q15_t *pScr2, *pScr1;                                                                          
        q15_t x4;                                                                    
  const q7_t *pIn1, *pIn2;                                                            
        uint32_t j, k, blkCnt, tapCnt;                                   
  const q7_t *px;                                                                    
        q15_t *py;                                                                   
        q31_t acc0, acc1, acc2, acc3;                                   
        q31_t x1, x2, x3, y1;                                                         
        arm_status status;
        q7_t *pOut = pDst;                                                 
        q7_t out0, out1, out2, out3;                                            

                                                          
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

                                                
    pScr2 = pScratch2;

                                           
    px = pIn2 + srcBLen - 1;

                                                              
    k = srcBLen >> 2U;

                                                                                       
                                                                       
    while (k > 0U)
    {
                                                 
      x4 = (q15_t) *px--;
      *pScr2++ = x4;
      x4 = (q15_t) *px--;
      *pScr2++ = x4;
      x4 = (q15_t) *px--;
      *pScr2++ = x4;
      x4 = (q15_t) *px--;
      *pScr2++ = x4;

                                  
      k--;
    }

                                                                        
                                     
    k = srcBLen % 0x4U;

    while (k > 0U)
    {
                                                                       
      x4 = (q15_t) *px--;
      *pScr2++ = x4;

                                  
      k--;
    }

                                             
    pScr1 = pScratch1;

                                                     
    arm_fill_q15(0, pScr1, (srcBLen - 1U));

                                          
    pScr1 += (srcBLen - 1U);

                                                  
                                                              
    k = srcALen >> 2U;

                                                                                       
                                                                       
    while (k > 0U)
    {
                                                 
      x4 = (q15_t) *pIn1++;
      *pScr1++ = x4;
      x4 = (q15_t) *pIn1++;
      *pScr1++ = x4;
      x4 = (q15_t) *pIn1++;
      *pScr1++ = x4;
      x4 = (q15_t) *pIn1++;
      *pScr1++ = x4;

                                  
      k--;
    }

                                                                        
                                     
    k = srcALen % 0x4U;

    while (k > 0U)
    {
                                                                       
      x4 = (q15_t) *pIn1++;
      *pScr1++ = x4;

                                      
      k--;
    }

                                                            
    arm_fill_q15(0, pScr1, (srcBLen - 1U));

                        
    pScr1 += (srcBLen - 1U);


                                        
    py = pScratch2;

                                        
    pIn2 = (q7_t *) py;

    pScr2 = py;

    pOut = pDst + firstIndex;

    pScratch1 += firstIndex;

                                                
    blkCnt = (numPoints) >> 2;

    while (blkCnt > 0)
    {
                                                            
      pScr1 = pScratch1;

                              
      acc0 = 0;
      acc1 = 0;
      acc2 = 0;
      acc3 = 0;

                                                 
      x1 = read_q15x2_ia (&pScr1);

                                                      
      x2 = read_q15x2_ia (&pScr1);

      tapCnt = (srcBLen) >> 2U;

      while (tapCnt > 0U)
      {
                                                   
        y1 = read_q15x2_ia (&pScr2);

                                    
        acc0 = __SMLAD(x1, y1, acc0);
        acc2 = __SMLAD(x2, y1, acc2);

                             
#ifndef ARM_MATH_BIG_ENDIAN
        x3 = __PKHBT(x2, x1, 0);
#else
        x3 = __PKHBT(x1, x2, 0);
#endif

                                    
        acc1 = __SMLADX(x3, y1, acc1);

                                                        
        x1 = read_q15x2_ia (&pScr1);

                             
#ifndef ARM_MATH_BIG_ENDIAN
        x3 = __PKHBT(x1, x2, 0);
#else
        x3 = __PKHBT(x2, x1, 0);
#endif

        acc3 = __SMLADX(x3, y1, acc3);

                                                   
        y1 = read_q15x2_ia (&pScr2);

        acc0 = __SMLAD(x2, y1, acc0);

        acc2 = __SMLAD(x1, y1, acc2);

        acc1 = __SMLADX(x3, y1, acc1);

        x2 = read_q15x2_ia (&pScr1);

#ifndef ARM_MATH_BIG_ENDIAN
        x3 = __PKHBT(x2, x1, 0);
#else
        x3 = __PKHBT(x1, x2, 0);
#endif

        acc3 = __SMLADX(x3, y1, acc3);

                                    
        tapCnt--;
      }

                                                                                   
      pScr1 -= 4U;

                                                                             
      tapCnt = (srcBLen) & 3U;

      while (tapCnt > 0U)
      {
                                   
        acc0 += (*pScr1++ * *pScr2);
        acc1 += (*pScr1++ * *pScr2);
        acc2 += (*pScr1++ * *pScr2);
        acc3 += (*pScr1++ * *pScr2++);

        pScr1 -= 3U;

                                    
        tapCnt--;
      }

      blkCnt--;

                                                                          
      out0 = (q7_t) (__SSAT(acc0 >> 7U, 8));
      out1 = (q7_t) (__SSAT(acc1 >> 7U, 8));
      out2 = (q7_t) (__SSAT(acc2 >> 7U, 8));
      out3 = (q7_t) (__SSAT(acc3 >> 7U, 8));

      write_q7x4_ia (&pOut, __PACKq7(out0, out1, out2, out3));

                                            
      pScr2 = py;

      pScratch1 += 4U;
    }

    blkCnt = (numPoints) & 0x3;

                                                                               
    while (blkCnt > 0)
    {
                                                           
      pScr1 = pScratch1;

                             
      acc0 = 0;

      tapCnt = (srcBLen) >> 1U;

      while (tapCnt > 0U)
      {

                                                        
        x1 = read_q15x2_ia (&pScr1);

                                                  
        y1 = read_q15x2_ia (&pScr2);

        acc0 = __SMLAD(x1, y1, acc0);

                                        
        tapCnt--;
      }

      tapCnt = (srcBLen) & 1U;

                                                                             
      while (tapCnt > 0U)
      {

                                   
        acc0 += (*pScr1++ * *pScr2++);

                                    
        tapCnt--;
      }

      blkCnt--;

                                                                          
      *pOut++ = (q7_t) (__SSAT(acc0 >> 7U, 8));

                                            
      pScr2 = py;

      pScratch1 += 1U;
    }

                                        
    status = ARM_MATH_SUCCESS;
  }

  return (status);
}

   
                             
   
