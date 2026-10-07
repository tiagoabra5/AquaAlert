                                                                         
                                  
                              
                                                           
  
                               
                       
  
                                   
                                                                          
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

   
                       
   

   
                 
    
   

   
                                                        
                                                                                 
                                                             
                                                                 
                                                              
                                                             
                                                        
                     

                                              
                                                                                    
                                                                                                     
                                                                               
                                                                                               
                                                                                                 
                                      
                                                                  
                                                                                                
                                                                          
                                                                         
     
                                                                                      
                                                                   
   

void arm_lms_q31(
  const arm_lms_instance_q31 * S,
  const q31_t * pSrc,
        q31_t * pRef,
        q31_t * pOut,
        q31_t * pErr,
        uint32_t blockSize)
{       
        q31_t *pState = S->pState;                                        
        q31_t *pCoeffs = S->pCoeffs;                                            
        q31_t *pStateCurnt;                                                                           
        q31_t *px, *pb;                                                                                          
        q31_t mu = S->mu;                                                   
        uint32_t numTaps = S->numTaps;                                                                  
        uint32_t tapCnt, blkCnt;                                          
        q63_t acc;                                                      
        q31_t e = 0;                                                             
        q31_t alpha;                                                                              
        q31_t coef;                                                                     
        q31_t acc_l, acc_h;                                                 
        uint32_t uShift = ((uint32_t) S->postShift + 1U);
        uint32_t lShift = 32U - uShift;                                                        

                                                                                      
                                                                                     
  pStateCurnt = &(S->pState[(numTaps - 1U)]);

                             
  blkCnt = blockSize;

  while (blkCnt > 0U)
  {
                                                         
    *pStateCurnt++ = *pSrc++;

                                   
    px = pState;

                                        
    pb = pCoeffs;

                                     
    acc = 0;

#if defined (ARM_MATH_LOOPUNROLL)

                                                   
    tapCnt = numTaps >> 2U;

    while (tapCnt > 0U)
    {
                                           
                                 
      acc += ((q63_t) (*px++)) * (*pb++);

                                     
      acc += ((q63_t) (*px++)) * (*pb++);

                                     
      acc += ((q63_t) (*px++)) * (*pb++);

                                     
      acc += ((q63_t) (*px++)) * (*pb++);

                                  
      tapCnt--;
    }

                                                
    tapCnt = numTaps % 0x4U;

#else

                                                  
    tapCnt = numTaps;

#endif                                        

    while (tapCnt > 0U)
    {
                                           
      acc += ((q63_t) (*px++)) * (*pb++);

                                      
      tapCnt--;
    }

                                              
                                
    acc_l = acc & 0xffffffff;

                                
    acc_h = (acc >> 32) & 0xffffffff;

    acc = (uint32_t) acc_l >> lShift | acc_h << uShift;

                                                                        
    *pOut++ = (q31_t) acc;

                                 
    e = *pRef++ - (q31_t) acc;
    *pErr++ = e;

                                                                  
    alpha = (q31_t) (((q63_t) e * mu) >> 31);

                                   
                                                        
    px = pState++;

                                        
    pb = pCoeffs;

#if defined (ARM_MATH_LOOPUNROLL)

                                                   
    tapCnt = numTaps >> 2U;

                                    
    while (tapCnt > 0U)
    {
                                           

                                  
      coef = (q31_t) (((q63_t) alpha * (*px++)) >> (32));
                                                    
      *pb = clip_q63_to_q31((q63_t) * pb + (coef << 1U));
                                                         
      pb++;

      coef = (q31_t) (((q63_t) alpha * (*px++)) >> (32));
      *pb = clip_q63_to_q31((q63_t) * pb + (coef << 1U));
      pb++;

      coef = (q31_t) (((q63_t) alpha * (*px++)) >> (32));
      *pb = clip_q63_to_q31((q63_t) * pb + (coef << 1U));
      pb++;

      coef = (q31_t) (((q63_t) alpha * (*px++)) >> (32));
      *pb = clip_q63_to_q31((q63_t) * pb + (coef << 1U));
      pb++;

                                  
      tapCnt--;
    }

                                                
    tapCnt = numTaps % 0x4U;

#else

                                                  
    tapCnt = numTaps;

#endif                                        

    while (tapCnt > 0U)
    {
                                           
      coef = (q31_t) (((q63_t) alpha * (*px++)) >> (32));
      *pb = clip_q63_to_q31((q63_t) * pb + (coef << 1U));
      pb++;

                                  
      tapCnt--;
    }

                                
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

   
                     
   
