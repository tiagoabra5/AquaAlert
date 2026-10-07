                                                                         
                                  
                                      
                                                                          
  
                               
                       
  
                                   
                                                                          
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

   
                       
   

   
                                                                     

                                                                                
                                                                            
                                                                                  
                                            
                                 
                                                                  
                                                                           
                                                                                              

                          
                                                                                      
                                                                    
      
       
                          
                                                         
                                                         
                  
        
      
                                                                                                                      
                                                                             
      
       
                       
        
                                              
      
                                                                                              
                                                                                                             
       
                                    
        
                                                                                                                         

                                   
                                                                                                                       
                                                                                 
                                                                                                                         
                                                                                                             

                                         
                                                                                          
                                                                                 
                                                                      
                                                              
                                                                                                                                
                                                                                            
      
                                                                  
                                                                                                                                           
                                                                                                                                 
                                                                                                                              
       
                                                                    
                                                                    
                                                                    
        
      
                                                                                      
                                                                          
                                                                                 

                                     
                                                                                                              
                                                                                                                                   
                                                                                           
   

   
                         
    
   

   
                                                                               
                                                                                             
                                                             
                                                              
                                                        
                     
   

void arm_fir_lattice_f32(
  const arm_fir_lattice_instance_f32 * S,
  const float32_t * pSrc,
        float32_t * pDst,
        uint32_t blockSize)
{
        float32_t *pState = S->pState;                                    
  const float32_t *pCoeffs = S->pCoeffs;                                        
        float32_t *px;                                                              
  const float32_t *pk;                                                                    
        uint32_t numStages = S->numStages;                                                 
        uint32_t blkCnt, stageCnt;                                        
        float32_t fcurr0, fnext0, gnext0, gcurr0;                               

#if defined (ARM_MATH_LOOPUNROLL)
        float32_t fcurr1, fnext1, gnext1;                                                                           
        float32_t fcurr2, fnext2, gnext2;                                                                          
        float32_t fcurr3, fnext3, gnext3;                                                                           
#endif

  gcurr0 = 0.0f;

#if defined (ARM_MATH_LOOPUNROLL)

                                                   
  blkCnt = blockSize >> 2U;

  while (blkCnt > 0U)
  {
                                            
                      
    fcurr0 = *pSrc++;
    fcurr1 = *pSrc++;

                                  
    px = pState;

                                  
    pk = pCoeffs;

                                        
    gcurr0 = *px;

                                            
                                       
    fnext0 = (gcurr0 * (*pk)) + fcurr0;

                                        
    gnext0 = (fcurr0 * (*pk)) + gcurr0;

                                             
    fnext1 = (fcurr0 * (*pk)) + fcurr1;
    gnext1 = (fcurr1 * (*pk)) + fcurr0;

                                                 
                          
    fcurr2 = *pSrc++;
    fcurr3 = *pSrc++;

                                            
    fnext2 = (fcurr1 * (*pk)) + fcurr2;
    gnext2 = (fcurr2 * (*pk)) + fcurr1;

                                             
    fnext3 = (fcurr2 * (*pk  )) + fcurr3;
    gnext3 = (fcurr3 * (*pk++)) + fcurr2;

                                                        
                                                        
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

                                                    
                                            
                                         
      fnext0 = (gcurr0 * (*pk)) + fcurr0;

                                                     
                                   
      fnext1 = (gnext0 * (*pk)) + fcurr1;

                                                    
      fnext2 = (gnext1 * (*pk)) + fcurr2;

                                                     
      fnext3 = (gnext2 * (*pk)) + fcurr3;

                                          
                                                      
      gnext3 = (fcurr3 * (*pk)) + gnext2;

      gnext2 = (fcurr2 * (*pk)) + gnext1;

      gnext1 = (fcurr1 * (*pk)) + gnext0;

      gnext0 = (fcurr0 * (*pk++)) + gcurr0;


                                                 
      gcurr0 = *px;

                                      
      *px++ = gnext3;

                                            
                                                    
                                         
      fcurr0 = (gcurr0 * (*pk)) + fnext0;

                                                     
      fcurr1 = (gnext0 * (*pk)) + fnext1;

                                                    
      fcurr2 = (gnext1 * (*pk)) + fnext2;

                                                     
      fcurr3 = (gnext2 * (*pk)) + fnext3;

                                                      
                                          
      gnext3 = (fnext3 * (*pk)) + gnext2;

      gnext2 = (fnext2 * (*pk)) + gnext1;

      gnext1 = (fnext1 * (*pk)) + gnext0;

      gnext0 = (fnext0 * (*pk++)) + gcurr0;


                                                 
      gcurr0 = *px;

                                      
      *px++ = gnext3;

                                            
                                                    
                                         
      fnext0 = (gcurr0 * (*pk)) + fcurr0;

                                                     
                                   
      fnext1 = (gnext0 * (*pk)) + fcurr1;

                                                    
      fnext2 = (gnext1 * (*pk)) + fcurr2;

                                                     
      fnext3 = (gnext2 * (*pk)) + fcurr3;

                                          
                                                      
      gnext3 = (fcurr3 * (*pk)) + gnext2;

      gnext2 = (fcurr2 * (*pk)) + gnext1;

      gnext1 = (fcurr1 * (*pk)) + gnext0;

      gnext0 = (fcurr0 * (*pk++)) + gcurr0;


                                                 
      gcurr0 = *px;

                                      
      *px++ = gnext3;

                                            
                                                    
                                         
      fcurr0 = (gcurr0 * (*pk)) + fnext0;

                                                     
      fcurr1 = (gnext0 * (*pk)) + fnext1;

                                                    
      fcurr2 = (gnext1 * (*pk)) + fnext2;

                                                     
      fcurr3 = (gnext2 * (*pk)) + fnext3;

                                                      
                                          
      gnext3 = (fnext3 * (*pk)) + gnext2;

      gnext2 = (fnext2 * (*pk)) + gnext1;

      gnext1 = (fnext1 * (*pk)) + gnext0;

      gnext0 = (fnext0 * (*pk++)) + gcurr0;

      stageCnt--;
    }

                                                                                             
    stageCnt = (numStages - 1U) % 0x4U;

    while (stageCnt > 0U)
    {
      gcurr0 = *px;

                                        
      *px++ = gnext3;

                                                         
      fnext0 = (gcurr0 * (*pk)) + fcurr0;

      fnext1 = (gnext0 * (*pk)) + fcurr1;

      fnext2 = (gnext1 * (*pk)) + fcurr2;

      fnext3 = (gnext2 * (*pk)) + fcurr3;

                                          
      gnext3 = (fcurr3 * (*pk)) + gnext2;

      gnext2 = (fcurr2 * (*pk)) + gnext1;

      gnext1 = (fcurr1 * (*pk)) + gnext0;

      gnext0 = (fcurr0 * (*pk++)) + gcurr0;

                                                                  
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

                                 
                                       
    fnext0 = (gcurr0 * (*pk)) + fcurr0;

                                        
    gnext0 = (fcurr0 * (*pk++)) + gcurr0;

                                    
    *px++ = fcurr0;

                                                            
    fcurr0 = fnext0;

    stageCnt = (numStages - 1U);

                    
    while (stageCnt > 0U)
    {
                                        
      gcurr0 = *px;

                                      
      *px++ = gnext0;

                                            
                                         
      fnext0 = (gcurr0 * (*pk)) + fcurr0;

                                          
      gnext0 = (fcurr0 * (*pk++)) + gcurr0;

                                                              
      fcurr0 = fnext0;

      stageCnt--;
    }

                      
    *pDst++ = fcurr0;

    blkCnt--;
  }

}

   
                             
   
