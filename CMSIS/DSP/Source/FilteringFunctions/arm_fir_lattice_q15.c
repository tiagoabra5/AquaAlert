                                                                         
                                  
                                      
                                                           
  
                               
                       
  
                                   
                                                                          
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

   
                       
   

   
                         
    
   

   
                                                                
                                                                                  
                                                             
                                                              
                                                        
                     
   

void arm_fir_lattice_q15(
  const arm_fir_lattice_instance_q15 * S,
  const q15_t * pSrc,
        q15_t * pDst,
        uint32_t blockSize)
{
        q15_t *pState = S->pState;                                        
  const q15_t *pCoeffs = S->pCoeffs;                                            
        q15_t *px;                                                                  
  const q15_t *pk;                                                                        
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

                                            
                                       
    fnext0 = (q31_t) ((gcurr0 * (*pk)) >> 15U) + fcurr0;
    fnext0 = __SSAT(fnext0, 16);

                                        
    gnext0 = (q31_t) ((fcurr0 * (*pk)) >> 15U) + gcurr0;
    gnext0 = __SSAT(gnext0, 16);

                                             
    fnext1 = (q31_t) ((fcurr0 * (*pk)) >> 15U) + fcurr1;
    fnext1 = __SSAT(fnext1, 16);
    gnext1 = (q31_t) ((fcurr1 * (*pk)) >> 15U) + fcurr0;
    gnext1 = __SSAT(gnext1, 16);

                                                 
                          
    fcurr2 = *pSrc++;
    fcurr3 = *pSrc++;

                                            
    fnext2 = (q31_t) ((fcurr1 * (*pk)) >> 15U) + fcurr2;
    fnext2 = __SSAT(fnext2, 16);
    gnext2 = (q31_t) ((fcurr2 * (*pk)) >> 15U) + fcurr1;
    gnext2 = __SSAT(gnext2, 16);

                                             
    fnext3 = (q31_t) ((fcurr2 * (*pk  )) >> 15U) + fcurr3;
    fnext3 = __SSAT(fnext3, 16);
    gnext3 = (q31_t) ((fcurr3 * (*pk++)) >> 15U) + fcurr2;
    gnext3 = __SSAT(gnext3, 16);

                                                        
                                                        
    *px++ = (q15_t) fcurr3;

                                                                
    fcurr0 = fnext0;
    fcurr1 = fnext1;
    fcurr2 = fnext2;
    fcurr3 = fnext3;

                                                     
    stageCnt = (numStages - 1U) >> 2U;

                                                              
                                                               

                                                     
    while (stageCnt > 0U)
    {
                                                 
      gcurr0 = *px;

                                      
      *px++ = (q15_t) gnext3;

                                                    
                                            
                                         
      fnext0 = (q31_t) ((gcurr0 * (*pk)) >> 15U) + fcurr0;
      fnext0 = __SSAT(fnext0, 16);

                                                     
                                   
      fnext1 = (q31_t) ((gnext0 * (*pk)) >> 15U) + fcurr1;
      fnext1 = __SSAT(fnext1, 16);

                                                    
      fnext2 = (q31_t) ((gnext1 * (*pk)) >> 15U) + fcurr2;
      fnext2 = __SSAT(fnext2, 16);

                                                     
      fnext3 = (q31_t) ((gnext2 * (*pk)) >> 15U) + fcurr3;
      fnext3 = __SSAT(fnext3, 16);

                                          
                                                      
      gnext3 = (q31_t) ((fcurr3 * (*pk)) >> 15U) + gnext2;
      gnext3 = __SSAT(gnext3, 16);

      gnext2 = (q31_t) ((fcurr2 * (*pk)) >> 15U) + gnext1;
      gnext2 = __SSAT(gnext2, 16);

      gnext1 = (q31_t) ((fcurr1 * (*pk)) >> 15U) + gnext0;
      gnext1 = __SSAT(gnext1, 16);

      gnext0 = (q31_t) ((fcurr0 * (*pk++)) >> 15U) + gcurr0;
      gnext0 = __SSAT(gnext0, 16);


                                                 
      gcurr0 = *px;

                                      
      *px++ = (q15_t) gnext3;

                                            
                                                    
                                         
      fcurr0 = (q31_t) ((gcurr0 * (*pk)) >> 15U) + fnext0;
      fcurr0 = __SSAT(fcurr0, 16);

                                                     
      fcurr1 = (q31_t) ((gnext0 * (*pk)) >> 15U) + fnext1;
      fcurr1 = __SSAT(fcurr1, 16);

                                                    
      fcurr2 = (q31_t) ((gnext1 * (*pk)) >> 15U) + fnext2;
      fcurr2 = __SSAT(fcurr2, 16);

                                                     
      fcurr3 = (q31_t) ((gnext2 * (*pk)) >> 15U) + fnext3;
      fcurr3 = __SSAT(fcurr3, 16);

                                                      
                                          
      gnext3 = (q31_t) ((fnext3 * (*pk)) >> 15U) + gnext2;
      gnext3 = __SSAT(gnext3, 16);

      gnext2 = (q31_t) ((fnext2 * (*pk)) >> 15U) + gnext1;
      gnext2 = __SSAT(gnext2, 16);

      gnext1 = (q31_t) ((fnext1 * (*pk)) >> 15U) + gnext0;
      gnext1 = __SSAT(gnext1, 16);

      gnext0 = (q31_t) ((fnext0 * (*pk++)) >> 15U) + gcurr0;
      gnext0 = __SSAT(gnext0, 16);

                                                 
      gcurr0 = *px;

                                      
      *px++ = (q15_t) gnext3;

                                            
                                                    
                                         
      fnext0 = (q31_t) ((gcurr0 * (*pk)) >> 15U) + fcurr0;
      fnext0 = __SSAT(fnext0, 16);

                                                     
                                   
      fnext1 = (q31_t) ((gnext0 * (*pk)) >> 15U) + fcurr1;
      fnext1 = __SSAT(fnext1, 16);

                                                    
      fnext2 = (q31_t) ((gnext1 * (*pk)) >> 15U) + fcurr2;
      fnext2 = __SSAT(fnext2, 16);

                                                     
      fnext3 = (q31_t) ((gnext2 * (*pk)) >> 15U) + fcurr3;
      fnext3 = __SSAT(fnext3, 16);

                                          
                                                      
      gnext3 = (q31_t) ((fcurr3 * (*pk)) >> 15U) + gnext2;
      gnext3 = __SSAT(gnext3, 16);

      gnext2 = (q31_t) ((fcurr2 * (*pk)) >> 15U) + gnext1;
      gnext2 = __SSAT(gnext2, 16);

      gnext1 = (q31_t) ((fcurr1 * (*pk)) >> 15U) + gnext0;
      gnext1 = __SSAT(gnext1, 16);

      gnext0 = (q31_t) ((fcurr0 * (*pk++)) >> 15U) + gcurr0;
      gnext0 = __SSAT(gnext0, 16);

                                                 
      gcurr0 = *px;

                                      
      *px++ = (q15_t) gnext3;

                                            
                                                    
                                         
      fcurr0 = (q31_t) ((gcurr0 * (*pk)) >> 15U) + fnext0;
      fcurr0 = __SSAT(fcurr0, 16);

                                                     
      fcurr1 = (q31_t) ((gnext0 * (*pk)) >> 15U) + fnext1;
      fcurr1 = __SSAT(fcurr1, 16);

                                                    
      fcurr2 = (q31_t) ((gnext1 * (*pk)) >> 15U) + fnext2;
      fcurr2 = __SSAT(fcurr2, 16);

                                                     
      fcurr3 = (q31_t) ((gnext2 * (*pk)) >> 15U) + fnext3;
      fcurr3 = __SSAT(fcurr3, 16);

                                                      
                                          
      gnext3 = (q31_t) ((fnext3 * (*pk)) >> 15U) + gnext2;
      gnext3 = __SSAT(gnext3, 16);

      gnext2 = (q31_t) ((fnext2 * (*pk)) >> 15U) + gnext1;
      gnext2 = __SSAT(gnext2, 16);

      gnext1 = (q31_t) ((fnext1 * (*pk)) >> 15U) + gnext0;
      gnext1 = __SSAT(gnext1, 16);

      gnext0 = (q31_t) ((fnext0 * (*pk++)) >> 15U) + gcurr0;
      gnext0 = __SSAT(gnext0, 16);

      stageCnt--;
    }

                                                                                             
    stageCnt = (numStages - 1U) % 0x4U;

    while (stageCnt > 0U)
    {
      gcurr0 = *px;

                                        
      *px++ = (q15_t) gnext3;

                                                         
      fnext0 = (q31_t) ((gcurr0 * (*pk)) >> 15U) + fcurr0;
      fnext0 = __SSAT(fnext0, 16);

      fnext1 = (q31_t) ((gnext0 * (*pk)) >> 15U) + fcurr1;
      fnext1 = __SSAT(fnext1, 16);

      fnext2 = (q31_t) ((gnext1 * (*pk)) >> 15U) + fcurr2;
      fnext2 = __SSAT(fnext2, 16);

      fnext3 = (q31_t) ((gnext2 * (*pk)) >> 15U) + fcurr3;
      fnext3 = __SSAT(fnext3, 16);

                                          
      gnext3 = (q31_t) ((fcurr3 * (*pk)) >> 15U) + gnext2;
      gnext3 = __SSAT(gnext3, 16);

      gnext2 = (q31_t) ((fcurr2 * (*pk)) >> 15U) + gnext1;
      gnext2 = __SSAT(gnext2, 16);

      gnext1 = (q31_t) ((fcurr1 * (*pk)) >> 15U) + gnext0;
      gnext1 = __SSAT(gnext1, 16);

      gnext0 = (q31_t) ((fcurr0 * (*pk++)) >> 15U) + gcurr0;
      gnext0 = __SSAT(gnext0, 16);

                                                                  
      fcurr0 = fnext0;
      fcurr1 = fnext1;
      fcurr2 = fnext2;
      fcurr3 = fnext3;

      stageCnt--;
    }

                                                                             
                      

#ifndef  ARM_MATH_BIG_ENDIAN
    write_q15x2_ia (&pDst, __PKHBT(fcurr0, fcurr1, 16));
    write_q15x2_ia (&pDst, __PKHBT(fcurr2, fcurr3, 16));
#else
    write_q15x2_ia (&pDst, __PKHBT(fcurr1, fcurr0, 16));
    write_q15x2_ia (&pDst, __PKHBT(fcurr3, fcurr2, 16));
#endif                                   

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

                                 
                                       
    fnext0 = (((q31_t) gcurr0 * (*pk)) >> 15U) + fcurr0;
    fnext0 = __SSAT(fnext0, 16);

                                        
    gnext0 = (((q31_t) fcurr0 * (*pk++)) >> 15U) + gcurr0;
    gnext0 = __SSAT(gnext0, 16);

                                    
    *px++ = (q15_t) fcurr0;

                                                            
    fcurr0 = fnext0;

    stageCnt = (numStages - 1U);

                    
    while (stageCnt > 0U)
    {
                                        
      gcurr0 = *px;

                                      
      *px++ = (q15_t) gnext0;

                                            
                                         
      fnext0 = (((q31_t) gcurr0 * (*pk)) >> 15U) + fcurr0;
      fnext0 = __SSAT(fnext0, 16);

                                          
      gnext0 = (((q31_t) fcurr0 * (*pk++)) >> 15U) + gcurr0;
      gnext0 = __SSAT(gnext0, 16);

                                                              
      fcurr0 = fnext0;

      stageCnt--;
    }

                      
    *pDst++ = __SSAT(fcurr0, 16);

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

                                 
                                       
    fnext0 = ((gcurr0 * (*pk)) >> 15U) + fcurr0;
    fnext0 = __SSAT(fnext, 16);

                                        
    gnext0 = ((fcurr0 * (*pk++)) >> 15U) + gcurr0;
    gnext0 = __SSAT(gnext0, 16);

                                    
    *px++ = (q15_t) fcurr0;

                                                           
    fcurr0 = fnext0;

    stageCnt = (numStages - 1U);

                    
    while (stageCnt > 0U)
    {
                                          
      gcurr0 = *px;

                                        
      *px++ = (q15_t) gnext0;

                                            
                                         
      fnext0 = ((gcurr0 * (*pk)) >> 15U) + fcurr0;
      fnext0 = __SSAT(fnext0, 16);

                                          
      gnext0 = ((fcurr0 * (*pk++)) >> 15U) + gcurr0;
      gnext0 = __SSAT(gnext0, 16);

                                                              
      fcurr0 = fnext0;

      stageCnt--;
    }

                      
    *pDst++ = __SSAT(fcurr0, 16);

    blkCnt--;
  }

#endif                                        

}

   
                             
   
