                                                                         
                                  
                                      
                                                           
  
                               
                       
  
                                   
                                                                          
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

   
                       
   

   
                         
    
   

   
                                                                    
                                                                                  
                                                             
                                                              
                                                        
                     

                                              
                                                                                    
                                                                                                                                
                                                                                                         
                                                                                                                                                
                                                                                                                                   
                                                                                         
   

void arm_iir_lattice_q15(
  const arm_iir_lattice_instance_q15 * S,
  const q15_t * pSrc,
        q15_t * pDst,
        uint32_t blockSize)
{
        q15_t *pState = S->pState;                                        
        q15_t *pStateCur;                                                         
        q31_t fcurr, fnext = 0, gcurr = 0, gnext;                                                  
        q63_t acc;                                                     
        q15_t *px1, *px2, *pk, *pv;                                                               
        uint32_t numStages = S->numStages;                                   
        uint32_t blkCnt, tapCnt;                                                           
        q15_t out;                                                                        

#if defined (ARM_MATH_DSP) && defined (ARM_MATH_LOOPUNROLL)
        q15_t gnext1, gnext2;                                                                      
        q31_t v;                                                                                      
#endif

                             
  blkCnt = blockSize;

#if defined (ARM_MATH_DSP)

                         
  while (blkCnt > 0U)
  {
                                       
                      
    fcurr = *pSrc++;

                                         
    pv = &S->pvCoeffs[0];

                                             
    pk = &S->pkCoeffs[0];

                                       
    px1 = pState;

                                        
    px2 = pState;

                                 
    acc = 0;

                                      
    gcurr = *px1++;
                                          
    fnext = fcurr - (((q31_t) gcurr * (*pk)) >> 15);
    fnext = __SSAT(fnext, 16);

                                          
    gnext = (((q31_t) fnext * (*pk++)) >> 15) + gcurr;
    gnext = __SSAT(gnext, 16);

                                                           
    *px2++ = (q15_t) gnext;

                            
    acc += (q31_t) ((gnext * (*pv++)));

                                                         
    fcurr = fnext;


#if defined (ARM_MATH_LOOPUNROLL)

                                                   
    tapCnt = (numStages - 1U) >> 2U;

    while (tapCnt > 0U)
    {
                                               
                                            
      gcurr = *px1++;
                                                
      fnext = fcurr - (((q31_t) gcurr * (*pk)) >> 15);
      fnext = __SSAT(fnext, 16);
                                                
      gnext = (((q31_t) fnext * (*pk++)) >> 15) + gcurr;
      gnext1 = (q15_t) __SSAT(gnext, 16);
                                                               
      *px2++ = (q15_t) gnext1;

                                               
                                            
      gcurr = *px1++;
                                               
                                                
      fcurr = fnext - (((q31_t) gcurr * (*pk)) >> 15);
      fcurr = __SSAT(fcurr, 16);
                                                
      gnext = (((q31_t) fcurr * (*pk++)) >> 15) + gcurr;
      gnext2 = (q15_t) __SSAT(gnext, 16);
                                    
      *px2++ = (q15_t) gnext2;

                                        
      v = read_q15x2_ia (&pv);

                                    

#ifndef  ARM_MATH_BIG_ENDIAN
      gnext = __PKHBT(gnext1, gnext2, 16);
#else
      gnext = __PKHBT(gnext2, gnext1, 16);
#endif                                   

                                   
                                                          
                                   
                                                            
      acc = __SMLALD(gnext, v, acc);

                                               
                                            
      gcurr = *px1++;
                                               
                                                
      fnext = fcurr - (((q31_t) gcurr * (*pk)) >> 15);
      fnext = __SSAT(fnext, 16);
                                                
      gnext = (((q31_t) fnext * (*pk++)) >> 15) + gcurr;
      gnext1 = (q15_t) __SSAT(gnext, 16);
                                                      
      *px2++ = (q15_t) gnext1;

                                               
                                            
      gcurr = *px1++;
                                               
                                                
      fcurr = fnext - (((q31_t) gcurr * (*pk)) >> 15);
      fcurr = __SSAT(fcurr, 16);
                                                
      gnext = (((q31_t) fcurr * (*pk++)) >> 15) + gcurr;
      gnext2 = (q15_t) __SSAT(gnext, 16);
                                                          
      *px2++ = (q15_t) gnext2;

                                        
      v = read_q15x2_ia (&pv);

                                    
#ifndef ARM_MATH_BIG_ENDIAN
      gnext = __PKHBT(gnext1, gnext2, 16);
#else
      gnext = __PKHBT(gnext2, gnext1, 16);
#endif                                  

                                   
                                                            
                                   
                                                            
      acc = __SMLALD(gnext, v, acc);

                                  
      tapCnt--;
    }

    fnext = fcurr;

                                                
    tapCnt = (numStages - 1U) % 0x4U;

#else

                                                  
    tapCnt = (numStages - 1U);

#endif                                        

    while (tapCnt > 0U)
    {
      gcurr = *px1++;
                                        
      fnext = fcurr - (((q31_t) gcurr * (*pk)) >> 15);
      fnext = __SSAT(fnext, 16);
      gnext = (((q31_t) fnext * (*pk++)) >> 15) + gcurr;
      gnext = __SSAT(gnext, 16);

                                        
      acc += (q31_t) (((q31_t) gnext * (*pv++)));
      *px2++ = (q15_t) gnext;
      fcurr = fnext;

                                  
      tapCnt--;
    }

                            
    acc += (q31_t) (((q31_t) fnext * (*pv++)));

    out = (q15_t) __SSAT(acc >> 15, 16);
    *px2++ = (q15_t) fnext;

                             
    *pDst++ = out;

                                                                               
    pState = pState + 1U;

                                
    blkCnt--;
  }

                                                                                      
                                                 

                                               
  pStateCur = &S->pState[0];
  pState = &S->pState[blockSize];

                 
#if defined (ARM_MATH_LOOPUNROLL)

                                                 
  tapCnt = numStages >> 2U;

  while (tapCnt > 0U)
  {
    write_q15x2_ia (&pStateCur, read_q15x2_ia (&pState));
    write_q15x2_ia (&pStateCur, read_q15x2_ia (&pState));

                                
    tapCnt--;
  }

                                              
  tapCnt = numStages % 0x4U;

#else

                                                
  tapCnt = (numStages - 1U);

#endif                                        

  while (tapCnt > 0U)
  {
    *pStateCur++ = *pState++;

                                
    tapCnt--;
  }

#else                                 

                         
  while (blkCnt > 0U)
  {
                                       
                      
    fcurr = *pSrc++;

                                         
    pv = &S->pvCoeffs[0];

                                             
    pk = &S->pkCoeffs[0];

                                       
    px1 = pState;

                                        
    px2 = pState;

                                 
    acc = 0;

    tapCnt = numStages;

    while (tapCnt > 0U)
    {
      gcurr = *px1++;
                          
                                            
      fnext = fcurr - ((gcurr * (*pk)) >> 15);
      fnext = __SSAT(fnext, 16);

                                            
      gnext = ((fnext * (*pk++)) >> 15) + gcurr;
      gnext = __SSAT(gnext, 16);

                          
                              
      acc += (q31_t) ((gnext * (*pv++)));

                                                             
      *px2++ = (q15_t) gnext;

                                                           
      fcurr = fnext;

      tapCnt--;
    }

                            
    acc += (q31_t) ((fnext * (*pv++)));

    out = (q15_t) __SSAT(acc >> 15, 16);
    *px2++ = (q15_t) fnext;

                             
    *pDst++ = out;

                                                                             
    pState = pState + 1U;

                                
    blkCnt--;
  }

                                                                                      
                                                 

                                               
  pStateCur = &S->pState[0];
  pState = &S->pState[blockSize];

  tapCnt = numStages;

                 
  while (tapCnt > 0U)
  {
    *pStateCur++ = *pState++;

                                
    tapCnt--;
  }

#endif                                 

}

   
                             
   
