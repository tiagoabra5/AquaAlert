                                                                         
                                  
                                       
                                  
  
                               
                       
  
                                   
                                                                          
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

   
                       
   

   
                          
    
   

   
                                                               
                                                                                    
                                                             
                                                              
                                                        
                     

                                              
                                                                                    
                                                                                                                                                                  
                                                                                              
                                                                                                                                                               
                                                                                                                                                    

        
                                                                                                                           
   

void arm_fir_decimate_q31(
  const arm_fir_decimate_instance_q31 * S,
  const q31_t * pSrc,
        q31_t * pDst,
        uint32_t blockSize)
{
        q31_t *pState = S->pState;                                        
  const q31_t *pCoeffs = S->pCoeffs;                                            
        q31_t *pStateCur;                                                                             
        q31_t *px0;                                                                            
  const q31_t *pb;                                                                                   
        q31_t x0, c0;                                                                                                
        q63_t acc0;                                                     
        uint32_t numTaps = S->numTaps;                                                                  
        uint32_t i, tapCnt, blkCnt, outBlockSize = blockSize / S->M;                     

#if defined (ARM_MATH_LOOPUNROLL)
        q31_t *px1, *px2, *px3;
        q31_t x1, x2, x3;
        q63_t acc1, acc2, acc3;
#endif

                                                                      
                                                                                   
  pStateCur = S->pState + (numTaps - 1U);

#if defined (ARM_MATH_LOOPUNROLL)

                                                     
  blkCnt = outBlockSize >> 2U;

                                  
  while (blkCnt > 0U)
  {
                                                                                      
    i = S->M * 4;

    do
    {
      *pStateCur++ = *pSrc++;

    } while (--i);

                                  
    acc0 = 0;
    acc1 = 0;
    acc2 = 0;
    acc3 = 0;

                                                      
    px0 = pState;
    px1 = pState + S->M;
    px2 = pState + 2 * S->M;
    px3 = pState + 3 * S->M;

                                  
    pb = pCoeffs;

                                                  
    tapCnt = numTaps >> 2U;

    while (tapCnt > 0U)
    {
                                             
      c0 = *(pb++);

                                               
      x0 = *(px0++);
                                               
      x1 = *(px1++);
                                               
      x2 = *(px2++);
                                               
      x3 = *(px3++);

                                           
      acc0 += (q63_t) x0 * c0;
      acc1 += (q63_t) x1 * c0;
      acc2 += (q63_t) x2 * c0;
      acc3 += (q63_t) x3 * c0;

                                             
      c0 = *(pb++);

                                                                 
      x0 = *(px0++);
      x1 = *(px1++);
      x2 = *(px2++);
      x3 = *(px3++);

                                           
      acc0 += (q63_t) x0 * c0;
      acc1 += (q63_t) x1 * c0;
      acc2 += (q63_t) x2 * c0;
      acc3 += (q63_t) x3 * c0;

                                             
      c0 = *(pb++);

                                                             
      x0 = *(px0++);
      x1 = *(px1++);
      x2 = *(px2++);
      x3 = *(px3++);

                                           
      acc0 += (q63_t) x0 * c0;
      acc1 += (q63_t) x1 * c0;
      acc2 += (q63_t) x2 * c0;
      acc3 += (q63_t) x3 * c0;

                                             
      c0 = *(pb++);

                                                             
      x0 = *(px0++);
      x1 = *(px1++);
      x2 = *(px2++);
      x3 = *(px3++);

                                           
      acc0 += (q63_t) x0 * c0;
      acc1 += (q63_t) x1 * c0;
      acc2 += (q63_t) x2 * c0;
      acc3 += (q63_t) x3 * c0;

                                  
      tapCnt--;
    }

                                                
    tapCnt = numTaps % 0x4U;

    while (tapCnt > 0U)
    {
                             
      c0 = *(pb++);

                                                            
      x0 = *(px0++);
      x1 = *(px1++);
      x2 = *(px2++);
      x3 = *(px3++);

                                           
      acc0 += (q63_t) x0 * c0;
      acc1 += (q63_t) x1 * c0;
      acc2 += (q63_t) x2 * c0;
      acc3 += (q63_t) x3 * c0;

                                  
      tapCnt--;
    }

                                                         
                                                                       
    pState = pState + S->M * 4;

                                                                            
    *pDst++ = (q31_t) (acc0 >> 31);
    *pDst++ = (q31_t) (acc1 >> 31);
    *pDst++ = (q31_t) (acc2 >> 31);
    *pDst++ = (q31_t) (acc3 >> 31);

                                
    blkCnt--;
  }

                                                 
  blkCnt = outBlockSize % 0x4U;

#else

                                                
  blkCnt = outBlockSize;

#endif                                        

  while (blkCnt > 0U)
  {
                                                                                  
    i = S->M;

    do
    {
      *pStateCur++ = *pSrc++;

    } while (--i);

                                 
    acc0 = 0;

                                  
    px0 = pState;

                                  
    pb = pCoeffs;

#if defined (ARM_MATH_LOOPUNROLL)

                                                  
    tapCnt = numTaps >> 2U;

    while (tapCnt > 0U)
    {
                                             
      c0 = *pb++;

                                      
      x0 = *px0++;

                                           
      acc0 += (q63_t) x0 * c0;

                                             
      c0 = *pb++;

                                      
      x0 = *px0++;

                                           
      acc0 += (q63_t) x0 * c0;

                                             
      c0 = *pb++;

                                      
      x0 = *px0++;

                                           
      acc0 += (q63_t) x0 * c0;

                                             
      c0 = *pb++;

                                      
      x0 = *px0++;

                                           
      acc0 += (q63_t) x0 * c0;

                                  
      tapCnt--;
    }

                                                
    tapCnt = numTaps % 0x4U;

#else

                                               
    tapCnt = numTaps;

#endif                                        

    while (tapCnt > 0U)
    {
                             
      c0 = *pb++;

                                  
      x0 = *px0++;

                                           
      acc0 += (q63_t) x0 * c0;

                                  
      tapCnt--;
    }

                                                         
                                                                       
    pState = pState + S->M;

                                                                            
    *pDst++ = (q31_t) (acc0 >> 31);

                                
    blkCnt--;
  }

                            
                                                                            
                                                                  

                                               
  pStateCur = S->pState;

#if defined (ARM_MATH_LOOPUNROLL)

                                                
  tapCnt = (numTaps - 1U) >> 2U;

                 
  while (tapCnt > 0U)
  {
    *pStateCur++ = *pState++;
    *pStateCur++ = *pState++;
    *pStateCur++ = *pState++;
    *pStateCur++ = *pState++;

                                
    tapCnt--;
  }

                                              
  tapCnt = (numTaps - 1U) % 0x04U;

#else

                                             
  tapCnt = (numTaps - 1U);

#endif                                        

                 
  while (tapCnt > 0U)
  {
    *pStateCur++ = *pState++;

                                
    tapCnt--;
  }

}

   
                              
   
