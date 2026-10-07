                                                                         
                                  
                                   
                                                                  
  
                               
                       
  
                                   
                                                                          
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

   
                       
   

   
                      
    
   

   
                                                                   
                                                                                           
                                                            
                                                                
                                                             
                                                            
                                                       
                     

                                              
                                                                                   
                                                                                           
                                                                                         
                                                                       
                                                                                        
                                                                                              
                                                                                       
                                                                                          
                                         
     
                                                                                         
                                                               
   

void arm_lms_norm_q15(
        arm_lms_norm_instance_q15 * S,
  const q15_t * pSrc,
        q15_t * pRef,
        q15_t * pOut,
        q15_t * pErr,
        uint32_t blockSize)
{
        q15_t *pState = S->pState;                                        
        q15_t *pCoeffs = S->pCoeffs;                                            
        q15_t *pStateCurnt;                                                                           
        q15_t *px, *pb;                                                                                          
        q15_t mu = S->mu;                                                   
        uint32_t numTaps = S->numTaps;                                                                  
        uint32_t tapCnt, blkCnt;                                          
        q63_t acc;                                                      
        q31_t energy;                                                           
        q15_t e = 0, d = 0;                                                              
        q15_t w = 0, in;                                                            
        q15_t x0;                                                                                   
        q15_t errorXmu, oneByEnergy;                                                                                                   
        q15_t postShift;                                                                                                    
        q31_t coef;                                                                            
        q31_t acc_l, acc_h;                                                 
        int32_t lShift = (15 - (int32_t) S->postShift);                         
        int32_t uShift = (32 - lShift);

  energy = S->energy;
  x0 = S->x0;

                                                                                      
                                                                                     
  pStateCurnt = &(S->pState[(numTaps - 1U)]);

                             
  blkCnt = blockSize;

  while (blkCnt > 0U)
  {
                                                         
    *pStateCurnt++ = *pSrc;

                                   
    px = pState;

                                        
    pb = pCoeffs;

                                           
    in = *pSrc++;

                                       
    energy -= (((q31_t) x0 * (x0)) >> 15);
    energy += (((q31_t) in * (in)) >> 15);

                                     
    acc = 0;

#if defined (ARM_MATH_LOOPUNROLL)

                                                   
    tapCnt = numTaps >> 2U;

    while (tapCnt > 0U)
    {
                                           
                                                     
      acc = __SMLALD(read_q15x2_ia (&px), read_q15x2_ia (&pb), acc);
      acc = __SMLALD(read_q15x2_ia (&px), read_q15x2_ia (&pb), acc);

                                  
      tapCnt--;
    }

                                                
    tapCnt = numTaps % 0x4U;

#else

                                                  
    tapCnt = numTaps;

#endif                                        

    while (tapCnt > 0U)
    {
                                           
      acc += (q63_t) (((q31_t) (*px++) * (*pb++)));

                                      
      tapCnt--;
    }

                                
    acc_l = acc & 0xffffffff;

                                
    acc_h = (acc >> 32) & 0xffffffff;

                                                                 
    acc = (uint32_t) acc_l >> lShift | acc_h << uShift;

                                                                      
    acc = __SSAT(acc, 16U);

                                                                        
    *pOut++ = (q15_t) acc;

                                 
    d = *pRef++;
    e = d - (q15_t) acc;
    *pErr++ = e;

                                 
    postShift = arm_recip_q15((q15_t) energy + DELTA_Q15, &oneByEnergy, S->recipTable);

                                     
    errorXmu = (q15_t) (((q31_t) e * mu) >> 15);

                                                    
    acc = (((q31_t) errorXmu * oneByEnergy) >> (15 - postShift));

                                                     
    w = (q15_t) __SSAT((q31_t) acc, 16);

                                   
    px = pState;

                                        
    pb = pCoeffs;

#if defined (ARM_MATH_LOOPUNROLL)

                                                   
    tapCnt = numTaps >> 2U;

                                    
    while (tapCnt > 0U)
    {
      coef = (q31_t) *pb + (((q31_t) w * (*px++)) >> 15);
      *pb++ = (q15_t) __SSAT(coef, 16);

      coef = (q31_t) *pb + (((q31_t) w * (*px++)) >> 15);
      *pb++ = (q15_t) __SSAT(coef, 16);

      coef = (q31_t) *pb + (((q31_t) w * (*px++)) >> 15);
      *pb++ = (q15_t) __SSAT(coef, 16);

      coef = (q31_t) *pb + (((q31_t) w * (*px++)) >> 15);
      *pb++ = (q15_t) __SSAT(coef, 16);

                                  
      tapCnt--;
    }

                                                
    tapCnt = numTaps % 0x4U;

#else

                                                  
    tapCnt = numTaps;

#endif                                        

    while (tapCnt > 0U)
    {
                                           
      coef = (q31_t) *pb + (((q31_t) w * (*px++)) >> 15);
      *pb++ = (q15_t) __SSAT(coef, 16);

                                  
      tapCnt--;
    }

    x0 = *pState;

                                                        
    pState = pState + 1;

                                
    blkCnt--;
  }

                                                    
  S->energy = (q15_t) energy;
  S->x0 = x0;

                            
                                                                            
                                                                  

                                                
  pStateCurnt = S->pState;

                 
#if defined (ARM_MATH_LOOPUNROLL)

                                                 
  tapCnt = (numTaps - 1U) >> 2U;

  while (tapCnt > 0U)
  {
    write_q15x2_ia (&pStateCurnt, read_q15x2_ia (&pState));
    write_q15x2_ia (&pStateCurnt, read_q15x2_ia (&pState));

                                
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

   
                          
   
