                                                                         
                                  
                                      
                                                           
  
                               
                       
  
                                   
                                                                          
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

   
                       
   

   
                         
    
   

   
                                                                    
                                                                                  
                                                             
                                                              
                                                        
                     

                                              
                                                                                                              
   

void arm_fir_lattice_q31(
  const arm_fir_lattice_instance_q31 * S,
  const q31_t * pSrc,
        q31_t * pDst,
        uint32_t blockSize)
{
        q31_t *pState = S->pState;                                        
  const q31_t *pCoeffs = S->pCoeffs;                                            
        q31_t *px;                                                                  
  const q31_t *pk;                                                                        
        uint32_t numStages = S->numStages;                                                 
        uint32_t blkCnt, stageCnt;                                        
        q31_t fcurr0, fnext0, gnext0, gcurr0;                                   

#if (1)
                                   

#if defined (ARM_MATH_LOOPUNROLL)
        q31_t fcurr1, fnext1, gnext1;                                                                               
        q31_t fcurr2, fnext2, gnext2;                                                                              
        q31_t fcurr3, fnext3, gnext3;                                                                               
#endif

  gcurr0 = 0;

#if defined (ARM_MATH_LOOPUNROLL)

                                                   
  blkCnt = blockSize >> 2U;

  while (blkCnt > 0U)
  {
                                            
                      
    fcurr0 = *pSrc++;
    fcurr1 = *pSrc++;

                                  
    px = pState;

                                  
    pk = pCoeffs;

                                        
    gcurr0 = *px;

                                            
                                       
    fnext0 = (q31_t) (((q63_t) gcurr0 * (*pk)) >> 32U);
    fnext0 = (fnext0 << 1U) + fcurr0;

                                        
    gnext0 = (q31_t) (((q63_t) fcurr0 * (*pk)) >> 32U);
    gnext0 = (gnext0 << 1U) + gcurr0;

                                             
    fnext1 = (q31_t) (((q63_t) fcurr0 * (*pk)) >> 32U);
    fnext1 = (fnext1 << 1U) + fcurr1;
    gnext1 = (q31_t) (((q63_t) fcurr1 * (*pk)) >> 32U);
    gnext1 = (gnext1 << 1U) + fcurr0;

                                                 
                          
    fcurr2 = *pSrc++;
    fcurr3 = *pSrc++;

                                            
    fnext2 = (q31_t) (((q63_t) fcurr1 * (*pk)) >> 32U);
    fnext2 = (fnext2 << 1U) + fcurr2;
    gnext2 = (q31_t) (((q63_t) fcurr2 * (*pk)) >> 32U);
    gnext2 = (gnext2 << 1U) + fcurr1;

                                             
    fnext3 = (q31_t) (((q63_t) fcurr2 * (*pk  )) >> 32U);
    fnext3 = (fnext3 << 1U) + fcurr3;
    gnext3 = (q31_t) (((q63_t) fcurr3 * (*pk++)) >> 32U);
    gnext3 = (gnext3 << 1U) + fcurr2;

                                                        
                                                        
    *px++ = fcurr3;

                                                                
    fcurr0 = fnext0;
    fcurr1 = fnext1;
    fcurr2 = fnext2;
    fcurr3 = fnext3;

                                                     
    stageCnt = (numStages - 1U) >> 2U;

                                                              
                                                               

                                                     
    while (stageCnt > 0U)
    {
                                                 
      gcurr0 = *px;

                                      
      *px++ = gnext3;

                                                    
                                            
                                         
      fnext0 = (q31_t) (((q63_t) gcurr0 * (*pk)) >> 32U);
      fnext0 = (fnext0 << 1U) + fcurr0;

                                                     
                                   
      fnext1 = (q31_t) (((q63_t) gnext0 * (*pk)) >> 32U);
      fnext1 = (fnext1 << 1U) + fcurr1;

                                                    
      fnext2 = (q31_t) (((q63_t) gnext1 * (*pk)) >> 32U);
      fnext2 = (fnext2 << 1U) + fcurr2;

                                                     
      fnext3 = (q31_t) (((q63_t) gnext2 * (*pk)) >> 32U);
      fnext3 = (fnext3 << 1U) + fcurr3;

                                          
                                                      
      gnext3 = (q31_t) (((q63_t) fcurr3 * (*pk)) >> 32U);
      gnext3 = (gnext3 << 1U) + gnext2;

      gnext2 = (q31_t) (((q63_t) fcurr2 * (*pk)) >> 32U);
      gnext2 = (gnext2 << 1U) + gnext1;

      gnext1 = (q31_t) (((q63_t) fcurr1 * (*pk)) >> 32U);
      gnext1 = (gnext1 << 1U) + gnext0;

      gnext0 = (q31_t) (((q63_t) fcurr0 * (*pk++)) >> 32U);
      gnext0 = (gnext0 << 1U) + gcurr0;


                                                 
      gcurr0 = *px;

                                      
      *px++ = gnext3;

                                            
                                                    
                                         
      fcurr0 = (q31_t) (((q63_t) gcurr0 * (*pk)) >> 32U);
      fcurr0 = (fcurr0 << 1U) + fnext0;

                                                     
      fcurr1 = (q31_t) (((q63_t) gnext0 * (*pk)) >> 32U);
      fcurr1 = (fcurr1 << 1U) + fnext1;

                                                    
      fcurr2 = (q31_t) (((q63_t) gnext1 * (*pk)) >> 32U);
      fcurr2 = (fcurr2 << 1U) + fnext2;

                                                     
      fcurr3 = (q31_t) (((q63_t) gnext2 * (*pk)) >> 32U);
      fcurr3 = (fcurr3 << 1U) + fnext3;

                                                      
                                          
      gnext3 = (q31_t) (((q63_t) fnext3 * (*pk)) >> 32U);
      gnext3 = (gnext3 << 1U) + gnext2;

      gnext2 = (q31_t) (((q63_t) fnext2 * (*pk)) >> 32U);
      gnext2 = (gnext2 << 1U) + gnext1;

      gnext1 = (q31_t) (((q63_t) fnext1 * (*pk)) >> 32U);
      gnext1 = (gnext1 << 1U) + gnext0;

      gnext0 = (q31_t) (((q63_t) fnext0 * (*pk++)) >> 32U);
      gnext0 = (gnext0 << 1U) + gcurr0;

                                                 
      gcurr0 = *px;

                                      
      *px++ = gnext3;

                                            
                                                    
                                         
      fnext0 = (q31_t) (((q63_t) gcurr0 * (*pk)) >> 32U);
      fnext0 = (fnext0 << 1U) + fcurr0;

                                                     
                                   
      fnext1 = (q31_t) (((q63_t) gnext0 * (*pk)) >> 32U);
      fnext1 = (fnext1 << 1U) + fcurr1;

                                                    
      fnext2 = (q31_t) (((q63_t) gnext1 * (*pk)) >> 32U);
      fnext2 = (fnext2 << 1U) + fcurr2;

                                                     
      fnext3 = (q31_t) (((q63_t) gnext2 * (*pk)) >> 32U);
      fnext3 = (fnext3 << 1U) + fcurr3;

                                          
                                                      
      gnext3 = (q31_t) (((q63_t) fcurr3 * (*pk)) >> 32U);
      gnext3 = (gnext3 << 1U) + gnext2;

      gnext2 = (q31_t) (((q63_t) fcurr2 * (*pk)) >> 32U);
      gnext2 = (gnext2 << 1U) + gnext1;

      gnext1 = (q31_t) (((q63_t) fcurr1 * (*pk)) >> 32U);
      gnext1 = (gnext1 << 1U) + gnext0;

      gnext0 = (q31_t) (((q63_t) fcurr0 * (*pk++)) >> 32U);
      gnext0 = (gnext0 << 1U) + gcurr0;

                                                 
      gcurr0 = *px;

                                      
      *px++ = gnext3;

                                            
                                                    
                                         
      fcurr0 = (q31_t) (((q63_t) gcurr0 * (*pk)) >> 32U);
      fcurr0 = (fcurr0 << 1U) + fnext0;

                                                     
      fcurr1 = (q31_t) (((q63_t) gnext0 * (*pk)) >> 32U);
      fcurr1 = (fcurr1 << 1U) + fnext1;

                                                    
      fcurr2 = (q31_t) (((q63_t) gnext1 * (*pk)) >> 32U);
      fcurr2 = (fcurr2 << 1U) + fnext2;

                                                     
      fcurr3 = (q31_t) (((q63_t) gnext2 * (*pk)) >> 32U);
      fcurr3 = (fcurr3 << 1U) + fnext3;

                                                      
                                          
      gnext3 = (q31_t) (((q63_t) fnext3 * (*pk)) >> 32U);
      gnext3 = (gnext3 << 1U) + gnext2;

      gnext2 = (q31_t) (((q63_t) fnext2 * (*pk)) >> 32U);
      gnext2 = (gnext2 << 1U) + gnext1;

      gnext1 = (q31_t) (((q63_t) fnext1 * (*pk)) >> 32U);
      gnext1 = (gnext1 << 1U) + gnext0;

      gnext0 = (q31_t) (((q63_t) fnext0 * (*pk++)) >> 32U);
      gnext0 = (gnext0 << 1U) + gcurr0;

      stageCnt--;
    }

                                                                                             
    stageCnt = (numStages - 1U) % 0x4U;

    while (stageCnt > 0U)
    {
      gcurr0 = *px;

                                        
      *px++ = gnext3;

                                                         
      fnext0 = (q31_t) (((q63_t) gcurr0 * (*pk)) >> 32U);
      fnext0 = (fnext0 << 1U) + fcurr0;

      fnext1 = (q31_t) (((q63_t) gnext0 * (*pk)) >> 32U);
      fnext1 = (fnext1 << 1U) + fcurr1;

      fnext2 = (q31_t) (((q63_t) gnext1 * (*pk)) >> 32U);
      fnext2 = (fnext2 << 1U) + fcurr2;

      fnext3 = (q31_t) (((q63_t) gnext2 * (*pk)) >> 32U);
      fnext3 = (fnext3 << 1U) + fcurr3;

                                          
      gnext3 = (q31_t) (((q63_t) fcurr3 * (*pk)) >> 32U);
      gnext3 = (gnext3 << 1U) + gnext2;

      gnext2 = (q31_t) (((q63_t) fcurr2 * (*pk)) >> 32U);
      gnext2 = (gnext2 << 1U) + gnext1;

      gnext1 = (q31_t) (((q63_t) fcurr1 * (*pk)) >> 32U);
      gnext1 = (gnext1 << 1U) + gnext0;

      gnext0 = (q31_t) (((q63_t) fcurr0 * (*pk++)) >> 32U);
      gnext0 = (gnext0 << 1U) + gcurr0;

                                                                  
      fcurr0 = fnext0;
      fcurr1 = fnext1;
      fcurr2 = fnext2;
      fcurr3 = fnext3;

      stageCnt--;
    }

                                                                             
                      
    *pDst++ = fcurr0;
    *pDst++ = fcurr1;
    *pDst++ = fcurr2;
    *pDst++ = fcurr3;

    blkCnt--;
  }

                                                 
  blkCnt = blockSize % 0x4U;

#else

                                                
  blkCnt = blockSize;

#endif                                        

  while (blkCnt > 0U)
  {
                      
    fcurr0 = *pSrc++;

                                  
    px = pState;

                                  
    pk = pCoeffs;

                                      
    gcurr0 = *px;

                                 
                                       
    fnext0 = (q31_t) (((q63_t) gcurr0 * (*pk)) >> 32U);
    fnext0 = (fnext0 << 1U) + fcurr0;

                                        
    gnext0 = (q31_t) (((q63_t) fcurr0 * (*pk++)) >> 32U);
    gnext0 = (gnext0 << 1U) + gcurr0;

                                    
    *px++ = fcurr0;

                                                            
    fcurr0 = fnext0;

    stageCnt = (numStages - 1U);

                    
    while (stageCnt > 0U)
    {
                                        
      gcurr0 = *px;

                                      
      *px++ = gnext0;

                                            
                                         
      fnext0 = (q31_t) (((q63_t) gcurr0 * (*pk)) >> 32U);
      fnext0 = (fnext0 << 1U) + fcurr0;

                                          
      gnext0 = (q31_t) (((q63_t) fcurr0 * (*pk++)) >> 32U);
      gnext0 = (gnext0 << 1U) + gcurr0;

                                                              
      fcurr0 = fnext0;

      stageCnt--;
    }

                      
    *pDst++ = fcurr0;

    blkCnt--;
  }

#else
                                      

  blkCnt = blockSize;

  while (blkCnt > 0U)
  {
                      
    fcurr0 = *pSrc++;

                                  
    px = pState;

                                  
    pk = pCoeffs;

                                        
    gcurr0 = *px;

                                 
                                       
    fnext0 = (q31_t) (((q63_t) gcurr0 * (*pk)) >> 32U);
    fnext0 = (fnext << 1U) + fcurr0;

                                        
    gnext0 = (q31_t) (((q63_t) fcurr0 * (*pk++)) >> 32U);
    gnext0 = (gnext0 << 1U) + gcurr0;

                                    
    *px++ = fcurr0;

                                                           
    fcurr0 = fnext0;

    stageCnt = (numStages - 1U);

                    
    while (stageCnt > 0U)
    {
                                          
      gcurr0 = *px;

                                        
      *px++ = gnext0;

                                            
                                         
      fnext0 = (q31_t) (((q63_t) gcurr0 * (*pk)) >> 32U);
      fnext0 = (fnext0 << 1U) + fcurr0;

                                          
      gnext0 = (q31_t) (((q63_t) fcurr0 * (*pk++)) >> 32U);
      gnext0 = (gnext0 << 1U) + gcurr0;

                                                              
      fcurr0 = fnext0;

      stageCnt--;
    }

                      
    *pDst++ = fcurr0;

    blkCnt--;
  }

#endif                                        

}

   
                             
   
