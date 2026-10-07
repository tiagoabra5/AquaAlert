                                                                         
                                  
                                   
                                             
  
                               
                       
  
                                   
                                                                          
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

   
                       
   

   
                  
    
   

   
                                              
                                                              
                                                              
                                                               
                                                               
                                                                                                                 
                                                                                                                 
                                                                                   
                     

                                              
                                                                                   
                                                                                          
                                                                                                         
                                                                                         
                                                                                                                                      
         
                                                                                                            
   

void arm_conv_opt_q15(
  const q15_t * pSrcA,
        uint32_t srcALen,
  const q15_t * pSrcB,
        uint32_t srcBLen,
        q15_t * pDst,
        q15_t * pScratch1,
        q15_t * pScratch2)
{
        q63_t acc0;                                                      
  const q15_t *pIn1;                                                       
  const q15_t *pIn2;                                                       
        q15_t *pOut = pDst;                                                
        q15_t *pScr1 = pScratch1;                                                          
        q15_t *pScr2 = pScratch2;                                                          
  const q15_t *px;                                                                      
        q15_t *py;                                                                      
        uint32_t j, k, blkCnt;                                           
        uint32_t tapCnt;                                               

#if defined (ARM_MATH_LOOPUNROLL)
        q63_t acc1, acc2, acc3;                                          
        q31_t x1, x2, x3;                                                                                            
        q31_t y1, y2;                                                       
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

                                              
  pScr2 = pScratch2 + srcBLen - 1;

                                         
  px = pIn2;

#if defined (ARM_MATH_LOOPUNROLL)

                                                   
  k = srcBLen >> 2U;

                                                                                      
  while (k > 0U)
  {
                                               
    *pScr2-- = *px++;
    *pScr2-- = *px++;
    *pScr2-- = *px++;
    *pScr2-- = *px++;

                                
    k--;
  }

                                                 
  k = srcBLen % 0x4U;

#else

                                           
  k = srcBLen;

#endif                                        

  while (k > 0U)
  {
                                                                     
    *pScr2-- = *px++;

                                
    k--;
  }

                                           
  pScr1 = pScratch1;

                                                     
                                                    
  arm_fill_q15(0, pScr1, (srcBLen - 1U));

                                        
  pScr1 += (srcBLen - 1U);

                                                                       

                                                
  arm_copy_q15(pIn1, pScr1, srcALen);

                       
  pScr1 += srcALen;


                                                          
  arm_fill_q15(0, pScr1, (srcBLen - 1U));

                      
  pScr1 += (srcBLen - 1U);

                                      
  py = pScratch2;


                                      
  pIn2 = py;

#if defined (ARM_MATH_LOOPUNROLL)

                                                   
  blkCnt = (srcALen + srcBLen - 1U) >> 2;

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

                                                 
      y1 = read_q15x2_ia ((q15_t **) &pIn2);
      y2 = read_q15x2_ia ((q15_t **) &pIn2);

                                  
      acc0 = __SMLALD(x1, y1, acc0);
      acc2 = __SMLALD(x2, y1, acc2);

                           
#ifndef ARM_MATH_BIG_ENDIAN
      x3 = __PKHBT(x2, x1, 0);
#else
      x3 = __PKHBT(x1, x2, 0);
#endif

                                  
      acc1 = __SMLALDX(x3, y1, acc1);

                                                      
      x1 = read_q15x2_ia (&pScr1);

                                  
      acc0 = __SMLALD(x2, y2, acc0);
      acc2 = __SMLALD(x1, y2, acc2);

                           
#ifndef ARM_MATH_BIG_ENDIAN
      x3 = __PKHBT(x1, x2, 0);
#else
      x3 = __PKHBT(x2, x1, 0);
#endif

      acc3 = __SMLALDX(x3, y1, acc3);
      acc1 = __SMLALDX(x3, y2, acc1);

      x2 = read_q15x2_ia (&pScr1);

#ifndef ARM_MATH_BIG_ENDIAN
      x3 = __PKHBT(x2, x1, 0);
#else
      x3 = __PKHBT(x1, x2, 0);
#endif

      acc3 = __SMLALDX(x3, y2, acc3);

                                  
      tapCnt--;
    }

                                                                                 
    pScr1 -= 4U;

                                                                           
    tapCnt = (srcBLen) & 3U;

    while (tapCnt > 0U)
    {
                                 
      acc0 += (*pScr1++ * *pIn2);
      acc1 += (*pScr1++ * *pIn2);
      acc2 += (*pScr1++ * *pIn2);
      acc3 += (*pScr1++ * *pIn2++);

      pScr1 -= 3U;

                                  
      tapCnt--;
    }

    blkCnt--;

                                                                          
#ifndef ARM_MATH_BIG_ENDIAN
    write_q15x2_ia (&pOut, __PKHBT(__SSAT((acc0 >> 15), 16), __SSAT((acc1 >> 15), 16), 16));
    write_q15x2_ia (&pOut, __PKHBT(__SSAT((acc2 >> 15), 16), __SSAT((acc3 >> 15), 16), 16));
#else
    write_q15x2_ia (&pOut, __PKHBT(__SSAT((acc1 >> 15), 16), __SSAT((acc0 >> 15), 16), 16));
    write_q15x2_ia (&pOut, __PKHBT(__SSAT((acc3 >> 15), 16), __SSAT((acc2 >> 15), 16), 16));
#endif                                  

                                          
    pIn2 = py;

    pScratch1 += 4U;
  }

                                                 
  blkCnt = (srcALen + srcBLen - 1U) & 0x3;

#else

                                                
  blkCnt = (srcALen + srcBLen - 1U);

#endif                                        

                                                                             
  while (blkCnt > 0)
  {
                                                         
    pScr1 = pScratch1;

                           
    acc0 = 0;

    tapCnt = (srcBLen) >> 1U;

    while (tapCnt > 0U)
    {

                                                      
      acc0 += (*pScr1++ * *pIn2++);
      acc0 += (*pScr1++ * *pIn2++);

                                  
      tapCnt--;
    }

    tapCnt = (srcBLen) & 1U;

                                                                           
    while (tapCnt > 0U)
    {

                                 
      acc0 += (*pScr1++ * *pIn2++);

                                  
      tapCnt--;
    }

    blkCnt--;

                                                                      
                                                          
    *pOut++ = (q15_t) (__SSAT((acc0 >> 15), 16));

                                          
    pIn2 = py;

    pScratch1 += 1U;
  }

}

   
                      
   
