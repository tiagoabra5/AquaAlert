                                                                         
                                  
                                          
                                      
  
                               
                       
  
                                   
                                                                          
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

   
                       
   

   
                             
    
   

   
                                                                  
                                                                                       
                                                             
                                                              
                                                        
                     

                                              
                                                                                    
                                                                                                                                                                  
                                                                                              
                                                                                                                             
                                                                                  
                                                                                                                                                    
   

void arm_fir_interpolate_q31(
  const arm_fir_interpolate_instance_q31 * S,
  const q31_t * pSrc,
        q31_t * pDst,
        uint32_t blockSize)
{
#if (1)
                                   

        q31_t *pState = S->pState;                                        
  const q31_t *pCoeffs = S->pCoeffs;                                            
        q31_t *pStateCur;                                                                             
        q31_t *ptr1;                                                                           
  const q31_t *ptr2;                                                                                 
        q63_t sum0;                                                      
        uint32_t i, blkCnt, tapCnt;                                       
        uint32_t phaseLen = S->phaseLength;                                                           
        uint32_t j;

#if defined (ARM_MATH_LOOPUNROLL)
        q63_t acc0, acc1, acc2, acc3;
        q31_t x0, x1, x2, x3;
        q31_t c0, c1, c2, c3;
#endif

                                                                       
                                                                                   
  pStateCur = S->pState + (phaseLen - 1U);

#if defined (ARM_MATH_LOOPUNROLL)

                                                   
  blkCnt = blockSize >> 2U;

  while (blkCnt > 0U)
  {
                                                     
    *pStateCur++ = *pSrc++;
    *pStateCur++ = *pSrc++;
    *pStateCur++ = *pSrc++;
    *pStateCur++ = *pSrc++;

                                                      
    j = 1U;

                                             
    i = (S->L);

    while (i > 0U)
    {
                                   
      acc0 = 0;
      acc1 = 0;
      acc2 = 0;
      acc3 = 0;

                                    
      ptr1 = pState;

                                          
      ptr2 = pCoeffs + (S->L - j);

                                                                 
                                                                      
      tapCnt = phaseLen >> 2U;

      x0 = *(ptr1++);
      x1 = *(ptr1++);
      x2 = *(ptr1++);

      while (tapCnt > 0U)
      {
                                   
        x3 = *(ptr1++);

                                  
        c0 = *(ptr2);

                                             
        acc0 += (q63_t) x0 * c0;
        acc1 += (q63_t) x1 * c0;
        acc2 += (q63_t) x2 * c0;
        acc3 += (q63_t) x3 * c0;

                                  
        c1 = *(ptr2 + S->L);

                                   
        x0 = *(ptr1++);

                                             
        acc0 += (q63_t) x1 * c1;
        acc1 += (q63_t) x2 * c1;
        acc2 += (q63_t) x3 * c1;
        acc3 += (q63_t) x0 * c1;

                                  
        c2 = *(ptr2 + S->L * 2);

                                   
        x1 = *(ptr1++);

                                             
        acc0 += (q63_t) x2 * c2;
        acc1 += (q63_t) x3 * c2;
        acc2 += (q63_t) x0 * c2;
        acc3 += (q63_t) x1 * c2;

                                  
        c3 = *(ptr2 + S->L * 3);

                                   
        x2 = *(ptr1++);

                                             
        acc0 += (q63_t) x3 * c3;
        acc1 += (q63_t) x0 * c3;
        acc2 += (q63_t) x1 * c3;
        acc3 += (q63_t) x2 * c3;


                                                                        
                                                             
                                                                              
        ptr2 += 4 * S->L;

                                    
        tapCnt--;
      }

                                                                                             
      tapCnt = phaseLen % 0x4U;

      while (tapCnt > 0U)
      {
                                   
        x3 = *(ptr1++);

                                  
        c0 = *(ptr2);

                                             
        acc0 += (q63_t) x0 * c0;
        acc1 += (q63_t) x1 * c0;
        acc2 += (q63_t) x2 * c0;
        acc3 += (q63_t) x3 * c0;

                                                                              
        ptr2 += S->L;

                                                      
        x0 = x1;
        x1 = x2;
        x2 = x3;

                                    
        tapCnt--;
      }

                                                                              
      *(pDst           ) = (q31_t) (acc0 >> 31);
      *(pDst +     S->L) = (q31_t) (acc1 >> 31);
      *(pDst + 2 * S->L) = (q31_t) (acc2 >> 31);
      *(pDst + 3 * S->L) = (q31_t) (acc3 >> 31);

      pDst++;

                                                                      
      j++;

                                  
      i--;
    }

                                     
                                                                          
    pState = pState + 4;

    pDst += S->L * 3;

                                
    blkCnt--;
  }

                                                 
  blkCnt = blockSize % 0x4U;

#else

                                                
  blkCnt = blockSize;

#endif                                        

  while (blkCnt > 0U)
  {
                                                     
    *pStateCur++ = *pSrc++;

                                                      
    j = 1U;

                                             
    i = S->L;
    while (i > 0U)
    {
                                   
      sum0 = 0;

                                    
      ptr1 = pState;

                                          
      ptr2 = pCoeffs + (S->L - j);

                                        
                                                                      

#if defined (ARM_MATH_LOOPUNROLL)

                                                      
      tapCnt = phaseLen >> 2U;

      while (tapCnt > 0U)
      {
                                             
        sum0 += (q63_t) *ptr1++ * *ptr2;

                                                                        
                                                             
                                                                              
        ptr2 += S->L;

        sum0 += (q63_t) *ptr1++ * *ptr2;
        ptr2 += S->L;

        sum0 += (q63_t) *ptr1++ * *ptr2;
        ptr2 += S->L;

        sum0 += (q63_t) *ptr1++ * *ptr2;
        ptr2 += S->L;

                                    
        tapCnt--;
      }

                                                     
      tapCnt = phaseLen % 0x4U;

#else

                                                    
      tapCnt = phaseLen;

#endif                                        

      while (tapCnt > 0U)
      {
                                             
        sum0 += (q63_t) *ptr1++ * *ptr2;

                                                                        
                                                             
                                                                              
        ptr2 += S->L;

                                    
        tapCnt--;
      }

                                                                              
      *pDst++ = (q31_t) (sum0 >> 31);

                                                                      
      j++;

                                      
      i--;
    }

                                     
                                                                          
    pState = pState + 1;

                                    
    blkCnt--;
  }

                            
                                                                             
                                                                  

                                               
  pStateCur = S->pState;

#if defined (ARM_MATH_LOOPUNROLL)

                                                   
  tapCnt = (phaseLen - 1U) >> 2U;

                 
  while (tapCnt > 0U)
  {
    *pStateCur++ = *pState++;
    *pStateCur++ = *pState++;
    *pStateCur++ = *pState++;
    *pStateCur++ = *pState++;

                                
    tapCnt--;
  }

                                                 
  tapCnt = (phaseLen - 1U) % 0x04U;

#else

                                                  
    tapCnt = (phaseLen - 1U);

#endif                                        

                 
  while (tapCnt > 0U)
  {
    *pStateCur++ = *pState++;

                                
    tapCnt--;
  }

#else
                                      

        q31_t *pState = S->pState;                                        
  const q31_t *pCoeffs = S->pCoeffs;                                            
        q31_t *pStateCur;                                                                             
        q31_t *ptr1;                                                                           
  const q31_t *ptr2;                                                                                 
        q63_t sum0;                                                      
        uint32_t i, blkCnt, tapCnt;                                       
        uint32_t phaseLen = S->phaseLength;                                                           

                                                                       
                                                                                   
  pStateCur = S->pState + (phaseLen - 1U);

                                      
  blkCnt = blockSize;

                                
  while (blkCnt > 0U)
  {
                                                     
    *pStateCur++ = *pSrc++;

                                             
    i = S->L;

    while (i > 0U)
    {
                                   
      sum0 = 0;

                                    
      ptr1 = pState;

                                          
      ptr2 = pCoeffs + (i - 1U);

                                          
      tapCnt = phaseLen;

      while (tapCnt > 0U)
      {
                                             
        sum0 += ((q63_t) *ptr1++ * *ptr2);

                                                                              
        ptr2 += S->L;

                                        
        tapCnt--;
      }

                                                                              
      *pDst++ = (q31_t) (sum0 >> 31);

                                  
      i--;
    }

                                     
                                                                          
    pState = pState + 1;

                                
    blkCnt--;
  }

                            
                                                                              
                                                                   

                                               
  pStateCur = S->pState;

  tapCnt = phaseLen - 1U;

                 
  while (tapCnt > 0U)
  {
    *pStateCur++ = *pState++;

                                
    tapCnt--;
  }

#endif                                        

}

   
                                 
   
