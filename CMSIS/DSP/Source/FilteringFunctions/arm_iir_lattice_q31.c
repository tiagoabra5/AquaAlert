                                                                         
                                  
                                      
                                                           
  
                               
                       
  
                                   
                                                                          
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

   
                       
   

   
                         
    
   

   
                                                                    
                                                                                  
                                                             
                                                              
                                                        
                     

                                              
                                                                                    
                                                                                                                                                                  
                                                                                              
                                                                                                                         
                                                                                                                                                    
   

void arm_iir_lattice_q31(
  const arm_iir_lattice_instance_q31 * S,
  const q31_t * pSrc,
        q31_t * pDst,
        uint32_t blockSize)
{       
        q31_t *pState = S->pState;                                          
        q31_t *pStateCur;                                                           
        q31_t fcurr, fnext = 0, gcurr = 0, gnext;                                                    
        q63_t acc;                                                       
        q31_t *px1, *px2, *pk, *pv;                                                                 
        uint32_t numStages = S->numStages;                                     
        uint32_t blkCnt, tapCnt;                                                             


                             
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
                                          
    fnext = __QSUB(fcurr, (q31_t) (((q63_t) gcurr * (*pk  )) >> 31));

                                          
    gnext = __QADD(gcurr, (q31_t) (((q63_t) fnext * (*pk++)) >> 31));

                                                               
    *px2++ = gnext;

                            
    acc += ((q63_t) gnext * *pv++);

                                                         
    fcurr = fnext;


#if defined (ARM_MATH_LOOPUNROLL)

                                                   
    tapCnt = (numStages - 1U) >> 2U;

    while (tapCnt > 0U)
    {
                                               
                                            
      gcurr = *px1++;
                                                
      fnext = __QSUB(fcurr, (q31_t) (((q63_t) gcurr * (*pk  )) >> 31));
                                                
      gnext = __QADD(gcurr, (q31_t) (((q63_t) fnext * (*pk++)) >> 31));
                                   
                                                          
      acc += ((q63_t) gnext * *pv++);
                                                               
      *px2++ = gnext;

                                               
                                            
      gcurr = *px1++;
                                               
                                                
      fcurr = __QSUB(fnext, (q31_t) (((q63_t) gcurr * (*pk  )) >> 31));
                                                
      gnext = __QADD(gcurr, (q31_t) (((q63_t) fcurr * (*pk++)) >> 31));
                                   
                                                            
      acc += ((q63_t) gnext * *pv++);
                                                               
      *px2++ = gnext;

                                               
                                            
      gcurr = *px1++;
                                               
                                                
      fnext = __QSUB(fcurr, (q31_t) (((q63_t) gcurr * (*pk  )) >> 31));
                                                
      gnext = __QADD(gcurr, (q31_t) (((q63_t) fnext * (*pk++)) >> 31));
                                   
                                                            
      acc += ((q63_t) gnext * *pv++);
                                                               
      *px2++ = gnext;

                                               
                                            
      gcurr = *px1++;
                                               
                                                
      fcurr = __QSUB(fnext, (q31_t) (((q63_t) gcurr * (*pk  )) >> 31));
                                                
      gnext = __QADD(gcurr, (q31_t) (((q63_t) fcurr * (*pk++)) >> 31));
                                   
                                                            
      acc += ((q63_t) gnext * *pv++);

                                                               
      *px2++ = gnext;

                                  
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
                                        
      fnext = __QSUB(fcurr, (q31_t) (((q63_t) gcurr * (*pk  )) >> 31));
      gnext = __QADD(gcurr, (q31_t) (((q63_t) fnext * (*pk++)) >> 31));

                                        
      acc += ((q63_t) gnext * *pv++);
      *px2++ = gnext;
      fcurr = fnext;

                                  
      tapCnt--;
    }

                            
    acc += ((q63_t) fnext * *pv++);

    *px2++ = fnext;

                             
    *pDst++ = (q31_t) (acc >> 31U);

                                                                               
    pState = pState + 1U;

                                
    blkCnt--;
  }

                                                                                      
                                                 

                                               
  pStateCur = &S->pState[0];
  pState = &S->pState[blockSize];

                 
#if defined (ARM_MATH_LOOPUNROLL)

                                                 
  tapCnt = numStages >> 2U;

  while (tapCnt > 0U)
  {
    *pStateCur++ = *pState++;
    *pStateCur++ = *pState++;
    *pStateCur++ = *pState++;
    *pStateCur++ = *pState++;

                                
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
                          
                                            
      fnext = clip_q63_to_q31(((q63_t) fcurr - ((q31_t) (((q63_t) gcurr * (*pk  )) >> 31))));

                                            
      gnext = clip_q63_to_q31(((q63_t) gcurr + ((q31_t) (((q63_t) fnext * (*pk++)) >> 31))));

                          
                              
      acc += ((q63_t) gnext * *pv++);

                                                                 
      *px2++ = gnext;

                                                           
      fcurr = fnext;

      tapCnt--;
    }

                            
    acc += ((q63_t) fnext * *pv++);

    *px2++ = fnext;

                             
    *pDst++ = (q31_t) (acc >> 31U);

                                                                             
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

   
                             
   
