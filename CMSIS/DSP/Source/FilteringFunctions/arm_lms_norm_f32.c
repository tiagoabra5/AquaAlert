                                                                         
                                  
                                   
                                                                       
  
                               
                       
  
                                   
                                                                          
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

   
                       
   

   
                                           

                                                                   
                                                                                                       
                                                           
                                                                                                                         

                                                                                         
                                                              
                                                         
                                        
                                                                                                                   
                                                                                                                    
                                                                                                                           
                                                              
                                                                                                                             
                                                                      

                                                                                 
                                                    
                                                                                         
                                                                                         
                                                   

                                                  
                                                                                                
                                                                                       

                          
                                                                                            
       
                                                                                             
        

     
                                                                                                                               
       
                         
        

     
                                                                                                                                        
       
                                                    
        
                                                                                                          
       
                                                                       
        
                                                                                                           
     
                                                                                                                
                                                                  
     
       
                                                          
        
     
                                                                                                            
                                                                       
     
       
                                                                                                      
        
     
                                                                                                                                            
                                                                                                                            
                                                                            
                                                                                         

                                   
                                                                                                                       
                                                                                    
                                                                                 
                                                                                                             

                                         
                                                                                          
                                                                                 
                                                                      
                                                              
                                                                                                                                
                                                                                                          
                                                                                      
                                        
     
                                                                                                                                          
                                     
                                                                                                       
                                                           
                                            
                                            

                                        
                                                                               
                                                                                        
                                                                                                         
                                                                                                                                        
                                                                                                  
                                                                                           
                                                                                                                                      

                                        
                                                                                               
                                                                                             
   

   
                      
    
   

   
                                                                              
                                                                                                      
                                                            
                                                                
                                                             
                                                            
                                                       
                     
   

#if defined(ARM_MATH_NEON)
void arm_lms_norm_f32(
  arm_lms_norm_instance_f32 * S,
  const float32_t * pSrc,
  float32_t * pRef,
  float32_t * pOut,
  float32_t * pErr,
  uint32_t blockSize)
{
  float32_t *pState = S->pState;                                    
  float32_t *pCoeffs = S->pCoeffs;                                        
  float32_t *pStateCurnt;                                                                       
  float32_t *px, *pb;                                                                                      
  float32_t mu = S->mu;                                               
  uint32_t numTaps = S->numTaps;                                                                  
  uint32_t tapCnt, blkCnt;                                          
  float32_t energy;                                                       
  float32_t sum, e, d;                                                                          
  float32_t w, x0, in;                                                                                                 

  float32x4_t tempV, sumV, xV, bV;
  float32x2_t tempV2;

                                                                 
  e = 0.0f;
  d = 0.0f;
  w = 0.0f;

  energy = S->energy;
  x0 = S->x0;

                                                                                      
                                                                                     
  pStateCurnt = &(S->pState[(numTaps - 1U)]);

                                            
  blkCnt = blockSize;

  while (blkCnt > 0U)
  {
                                                         
    *pStateCurnt++ = *pSrc;

                                   
    px = pState;

                                  
    pb = (pCoeffs);

                                           
    in = *pSrc++;

                                       
    energy -= x0 * x0;
    energy += in * in;

                                     
    sum = 0.0f;
    sumV = vdupq_n_f32(0.0);

                                   
    tapCnt = numTaps >> 2;

    while (tapCnt > 0U)
    {
                                           
      xV = vld1q_f32(px);
      bV = vld1q_f32(pb);
      sumV = vmlaq_f32(sumV, xV, bV);

      px += 4; 
      pb += 4;

                                      
      tapCnt--;
    }
    tempV2 = vpadd_f32(vget_low_f32(sumV),vget_high_f32(sumV));
    sum = tempV2[0] + tempV2[1];

                                                                                        
    tapCnt = numTaps % 0x4U;

    while (tapCnt > 0U)
    {
                                           
      sum += (*px++) * (*pb++);

                                      
      tapCnt--;
    }

                                                                         
    *pOut++ = sum;

                                 
    d = (float32_t) (*pRef++);
    e = d - sum;
    *pErr++ = e;

                                                                          
                                          
    w = (e * mu) / (energy + 0.000000119209289f);

                                   
    px = pState;

                                  
    pb = (pCoeffs);

                                   
    tapCnt = numTaps >> 2;

                                    
    while (tapCnt > 0U)
    {
                                           
      xV = vld1q_f32(px);
      bV = vld1q_f32(pb);
      px += 4;
      bV = vmlaq_n_f32(bV,xV,w);

      vst1q_f32(pb,bV); 
      pb += 4;


                                      
      tapCnt--;
    }

                                                                                        
    tapCnt = numTaps % 0x4U;

    while (tapCnt > 0U)
    {
                                           
      *pb += w * (*px++);
      pb++;

                                      
      tapCnt--;
    }

    x0 = *pState;

                                                        
    pState = pState + 1;

                                    
    blkCnt--;
  }

  S->energy = energy;
  S->x0 = x0;

                                                                         
                                                                      
                           

                                                
  pStateCurnt = S->pState;

                                                                  
  tapCnt = (numTaps - 1U) >> 2U;

                 
  while (tapCnt > 0U)
  {
    tempV = vld1q_f32(pState);
    vst1q_f32(pStateCurnt,tempV); 
    pState += 4;
    pStateCurnt += 4;

                                    
    tapCnt--;
  }

                                            
  tapCnt = (numTaps - 1U) % 0x4U;

                                     
  while (tapCnt > 0U)
  {
    *pStateCurnt++ = *pState++;

                                    
    tapCnt--;
  }

}
#else
void arm_lms_norm_f32(
        arm_lms_norm_instance_f32 * S,
  const float32_t * pSrc,
        float32_t * pRef,
        float32_t * pOut,
        float32_t * pErr,
        uint32_t blockSize)
{
        float32_t *pState = S->pState;                                    
        float32_t *pCoeffs = S->pCoeffs;                                        
        float32_t *pStateCurnt;                                                                       
        float32_t *px, *pb;                                                                                      
        float32_t mu = S->mu;                                               
        float32_t acc, e;                                                      
        float32_t w;                                                      
        uint32_t numTaps = S->numTaps;                                                                  
        uint32_t tapCnt, blkCnt;                                          
        float32_t energy;                                                       
        float32_t x0, in;                                                                                     

                                                                 
  e = 0.0f;
  w = 0.0f;

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

                                       
    energy -= x0 * x0;
    energy += in * in;

                                     
    acc = 0.0f;

#if defined (ARM_MATH_LOOPUNROLL)

                                                   
    tapCnt = numTaps >> 2U;

    while (tapCnt > 0U)
    {
                                           
      acc += (*px++) * (*pb++);

      acc += (*px++) * (*pb++);

      acc += (*px++) * (*pb++);

      acc += (*px++) * (*pb++);

                                  
      tapCnt--;
    }

                                                
    tapCnt = numTaps % 0x4U;

#else

                                                  
    tapCnt = numTaps;

#endif                                        

    while (tapCnt > 0U)
    {
                                           
      acc += (*px++) * (*pb++);

                                      
      tapCnt--;
    }

                                                                        
    *pOut++ = acc;

                                 
    e = (float32_t) *pRef++ - acc;
    *pErr++ = e;

                                                                          
                                          
    w = (e * mu) / (energy + 0.000000119209289f);

                                   
    px = pState;

                                        
    pb = pCoeffs;

#if defined (ARM_MATH_LOOPUNROLL)

                                                   
    tapCnt = numTaps >> 2U;

                                    
    while (tapCnt > 0U)
    {
                                           
      *pb += w * (*px++);
      pb++;

      *pb += w * (*px++);
      pb++;

      *pb += w * (*px++);
      pb++;

      *pb += w * (*px++);
      pb++;

                                  
      tapCnt--;
    }

                                                
    tapCnt = numTaps % 0x4U;

#else

                                                  
    tapCnt = numTaps;

#endif                                        

    while (tapCnt > 0U)
    {
                                           
      *pb += w * (*px++);
      pb++;

                                  
      tapCnt--;
    }

    x0 = *pState;

                                                        
    pState = pState + 1;

                                
    blkCnt--;
  }

                                                    
  S->energy = energy;
  S->x0 = x0;

                            
                                                                            
                                                                  

                                                
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
#endif                                 
   
                          
   
