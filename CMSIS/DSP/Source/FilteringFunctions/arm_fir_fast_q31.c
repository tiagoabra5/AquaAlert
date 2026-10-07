                                                                         
                                  
                                   
                                                                
  
                               
                       
  
                                   
                                                                          
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

   
                       
   

   
                 
    
   

   
                                                                           
                                                                      
                                                             
                                                              
                                                        
                     

                                              
                                                                                                                        
                                                                                             
                                                                              
                                                                                        
                                                                                                                                                                                       
                                                                                                                     

        
                                                                                                                                                                                                                              
                                                                                           
   

IAR_ONLY_LOW_OPTIMIZATION_ENTER
void arm_fir_fast_q31(
  const arm_fir_instance_q31 * S,
  const q31_t * pSrc,
        q31_t * pDst,
        uint32_t blockSize)
{
        q31_t *pState = S->pState;                                        
  const q31_t *pCoeffs = S->pCoeffs;                                            
        q31_t *pStateCurnt;                                                                           
        q31_t *px;                                                                             
  const q31_t *pb;                                                                                   
        q31_t acc0;                                                      
        uint32_t numTaps = S->numTaps;                                                                  
        uint32_t i, tapCnt, blkCnt;                                       

#if defined (ARM_MATH_LOOPUNROLL)
        q31_t acc1, acc2, acc3;                                          
        q31_t x0, x1, x2, x3, c0;                                                                                    
#endif

                                                                                           
                                                                                     
  pStateCurnt = &(S->pState[(numTaps - 1U)]);

#if defined (ARM_MATH_LOOPUNROLL)

                                                            
                                                                            
    
                                                                                                                               
                                                                                                                               
                                                                                                                               
                                                                                                                               
     
  blkCnt = blockSize >> 2U;

  while (blkCnt > 0U)
  {
                                                         
    *pStateCurnt++ = *pSrc++;
    *pStateCurnt++ = *pSrc++;
    *pStateCurnt++ = *pSrc++;
    *pStateCurnt++ = *pSrc++;

                                      
    acc0 = 0;
    acc1 = 0;
    acc2 = 0;
    acc3 = 0;

                                  
    px = pState;

                                        
    pb = pCoeffs;

                                                      
                                                       
    x0 = *px++;
    x1 = *px++;
    x2 = *px++;

                                                   
    tapCnt = numTaps >> 2U;

                                                              
                                                             
    while (tapCnt > 0U)
    {
                                           
      c0 = *pb;

                                      
      x3 = *px;

                                              
      multAcc_32x32_keep32_R(acc0, x0, c0);

                                                
      multAcc_32x32_keep32_R(acc1, x1, c0);

                                                
      multAcc_32x32_keep32_R(acc2, x2, c0);

                                                
      multAcc_32x32_keep32_R(acc3, x3, c0);

                                             
      c0 = *(pb + 1U);

                                      
      x0 = *(px + 1U);

                                            
      multAcc_32x32_keep32_R(acc0, x1, c0);
      multAcc_32x32_keep32_R(acc1, x2, c0);
      multAcc_32x32_keep32_R(acc2, x3, c0);
      multAcc_32x32_keep32_R(acc3, x0, c0);

                                             
      c0 = *(pb + 2U);

                                      
      x1 = *(px + 2U);

                                            
      multAcc_32x32_keep32_R(acc0, x2, c0);
      multAcc_32x32_keep32_R(acc1, x3, c0);
      multAcc_32x32_keep32_R(acc2, x0, c0);
      multAcc_32x32_keep32_R(acc3, x1, c0);

                                              
      c0 = *(pb + 3U);

                                      
      x2 = *(px + 3U);

                                            
      multAcc_32x32_keep32_R(acc0, x3, c0);
      multAcc_32x32_keep32_R(acc1, x0, c0);
      multAcc_32x32_keep32_R(acc2, x1, c0);
      multAcc_32x32_keep32_R(acc3, x2, c0);

                                      
      pb += 4U;
      px += 4U;

                                  
      tapCnt--;
    }

                                                                                        
    tapCnt = numTaps % 0x4U;

    while (tapCnt > 0U)
    {
                             
      c0 = *(pb++);

                                  
      x3 = *(px++);

                                            
      multAcc_32x32_keep32_R(acc0, x0, c0);
      multAcc_32x32_keep32_R(acc1, x1, c0);
      multAcc_32x32_keep32_R(acc2, x2, c0);
      multAcc_32x32_keep32_R(acc3, x3, c0);

                                                           
      x0 = x1;
      x1 = x2;
      x2 = x3;

                                  
      tapCnt--;
    }

                                                                            
                                                             
    *pDst++ = (q31_t) (acc0 << 1);
    *pDst++ = (q31_t) (acc1 << 1);
    *pDst++ = (q31_t) (acc2 << 1);
    *pDst++ = (q31_t) (acc3 << 1);

                                                                               
    pState = pState + 4U;

                                
    blkCnt--;
  }

                                                        
  blkCnt = blockSize % 0x4U;

#else

                                             
  blkCnt = blockSize;

#endif                                        

  while (blkCnt > 0U)
  {
                                                     
    *pStateCurnt++ = *pSrc++;

                                     
    acc0 = 0;

                                  
    px = pState;

                                        
    pb = pCoeffs;

    i = numTaps;

                                          
    do
    {
      multAcc_32x32_keep32_R(acc0, (*px++), (*pb++));
      i--;
    } while (i > 0U);

                                                    
                                                          
    *pDst++ = (q31_t) (acc0 << 1);

                                                        
    pState = pState + 1U;

                                
    blkCnt--;
  }

                            
                                                                            
                                                                  

                                               
  pStateCurnt = S->pState;

#if defined (ARM_MATH_LOOPUNROLL)

                                                
  tapCnt = (numTaps - 1U) >> 2U;

                 
  while (tapCnt > 0U)
  {
    *pStateCurnt++ = *pState++;
    *pStateCurnt++ = *pState++;
    *pStateCurnt++ = *pState++;
    *pStateCurnt++ = *pState++;

                                
    tapCnt--;
  }

                                            
  tapCnt = (numTaps - 1U) % 0x4U;

#else

                                             
  tapCnt = (numTaps - 1U);

#endif                                        

                           
  while (tapCnt > 0U)
  {
    *pStateCurnt++ = *pState++;

                                    
    tapCnt--;
  }

}
IAR_ONLY_LOW_OPTIMIZATION_EXIT
   
                     
   
