                                                                         
                                  
                                      
                                                                      
  
                               
                       
  
                                   
                                                                          
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

   
                       
   

   
                                                                       

                                                  
                                                                            
                                                                                   
                                                                      
                                 
                                                                  
                                                                           
                                                                                              

                          
                                                                                        
      
       
                    
                                                               
                                                               
                                                             
        
      
                                                                                                                   
                                                                             
      
       
                        
        
      
                                                                                                                      
                                                                        
       
                         
        
      
                                                                                                          
                                                                                                                            
                                                                                                                         

                                   
                                                                                                                       
                                                                                 
                                                                                                                         
                                                                                                             

                                         
                                                                                          
                                                                                 
                                                                      
                                                              
                                                                                                                                
                                                                                                       
      
                                                                  
                                                                                                                                           
                                                                                                                                 
                                                                                                                              
       
                                                                               
                                                                               
                                                                               
        
      
                                                                                                                                            
                                                                                                                                                          

                                     
                                                                                                              
                                                                                                                                   
                                                                                           
   

   
                         
    
   

   
                                                                               
                                                                                             
                                                             
                                                              
                                                        
                     
   

void arm_iir_lattice_f32(
  const arm_iir_lattice_instance_f32 * S,
  const float32_t * pSrc,
        float32_t * pDst,
        uint32_t blockSize)
{       
        float32_t *pState = S->pState;                                      
        float32_t *pStateCur;                                                       
        float32_t acc;                                                   
        float32_t fnext1, fnext2, gcurr1, gnext;                                                     
        float32_t *px1, *px2, *pk, *pv;                                                             
        uint32_t numStages = S->numStages;                                     
        uint32_t blkCnt, tapCnt;                                                             

#if defined (ARM_MATH_LOOPUNROLL)
        float32_t gcurr2;                                                                            
        float32_t k1, k2;
        float32_t v1, v2, v3, v4;
#endif

                             
  blkCnt = blockSize;

                         
  while (blkCnt > 0U)
  {
                                       
                      
    fnext2 = *pSrc++;

                                         
    pv = &S->pvCoeffs[0];

                                             
    pk = &S->pkCoeffs[0];

                                       
    px1 = pState;

                                        
    px2 = pState;

                                 
    acc = 0.0;

#if defined (ARM_MATH_LOOPUNROLL)

                                                   
    tapCnt = (numStages) >> 2U;

    while (tapCnt > 0U)
    {
                                            
      gcurr1 = *px1;

                                          
      k1 = *pk;

                                            
      fnext1 = fnext2 - (k1 * gcurr1);

                                      
      v1 = *pv;

                                                 
      k2 = *(pk + 1U);

                                            
      gcurr2 = *(px1 + 1U);

                                             
      v2 = *(pv + 1U);

                                                
      fnext2 = fnext1 - (k2 * gcurr2);

                                              
      gnext = gcurr1 + (k1 * fnext1);

                                            
      k1 = *(pk + 2U);

                                                             
      *px2++ = gnext;

                                            
      gcurr1 = *(px1 + 2U);

                               
      acc += (gnext * v1);

                                                
      fnext1 = fnext2 - (k1 * gcurr1);

                                                  
      gnext = gcurr2 + (k2 * fnext2);

                                            
      gcurr2 = *(px1 + 3U);

                                   
      acc += (gnext * v2);

                                            
      k2 = *(pk + 3U);

                                                               
      *px2++ = gnext;

                                                
      fnext2 = fnext1 - (k2 * gcurr2);

                                                
      gnext = gcurr1 + (k1 * fnext1);

                                        
      v3 = *(pv + 2U);

                                   
      acc += (gnext * v3);

                                                               
      *px2++ = gnext;

                          
      pk += 4U;

                                                
      gnext = (fnext2 * k2) + gcurr2;

                                             
      v4 = *(pv + 3U);

                                   
      acc += (gnext * v4);

                                                               
      *px2++ = gnext;

                           
      px1 += 4U;
      pv += 4U;

                                  
      tapCnt--;
    }

                                                
    tapCnt = numStages % 0x4U;

#else

                                                  
    tapCnt = numStages;

#endif                                        

    while (tapCnt > 0U)
    {
      gcurr1 = *px1++;
                                        
      fnext1 = fnext2 - ((*pk) * gcurr1);
      gnext = (fnext1 * (*pk++)) + gcurr1;
                                        
      acc += (gnext * (*pv++));
      *px2++ = gnext;
      fnext2 = fnext1;

                                  
      tapCnt--;
    }

                            
    acc += (fnext2 * (*pv));

    *px2++ = fnext2;

                             
    *pDst++ = acc;

                                                                               
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

                                                
  tapCnt = numStages;

#endif                                        

  while (tapCnt > 0U)
  {
    *pStateCur++ = *pState++;

                                
    tapCnt--;
  }

}

   
                             
   
