                                                                         
                                  
                                             
                                                                                                  
  
                               
                       
  
                                   
                                                                          
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
void arm_biquad_cascade_df1_f32(
  const arm_biquad_casd_df1_inst_f32 * S,
  const float32_t * pSrc,
  float32_t * pDst,
  uint32_t blockSize)
{

  const float32_t *pIn = pSrc;                                                         
  float32_t *pOut = pDst;                                                        
  float32_t *pState = S->pState;                                                 
  const float32_t *pCoeffs = S->pCoeffs;                                               
  float32_t acc;                                                                 
  
  uint32_t sample, stage = S->numStages;                                         

  float32x4_t Xn;
  float32x2_t Yn;
  float32x2_t a;
  float32x4_t b;
  
  float32x4_t x,tmp;
  float32x2_t t;
  float32x2x2_t y;

  float32_t Xns;

  while (stage > 0U)
  {
                                  
    Xn = vld1q_f32(pState);
    Yn = vld1_f32(pState + 2);

    b = vld1q_f32(pCoeffs);
    b = vrev64q_f32(b);  
    b = vcombine_f32(vget_high_f32(b), vget_low_f32(b));

    a = vld1_f32(pCoeffs + 3);
    a = vrev64_f32(a);
    b[0] = 0.0;
    pCoeffs += 5;
    
                                   
   
                                                                          
                                                                        
      
                                                                                  
                                                                                  
                                                                                  
                                                                                  
       

                                                                                      
                                                                     
    sample = blockSize >> 2U;

    while (sample > 0U)
    {
                                   
      x = vld1q_f32(pIn);

      pIn += 4;

      tmp = vextq_f32(Xn, x, 1);
      t = vmul_f32(vget_high_f32(b), vget_high_f32(tmp));
      t = vmla_f32(t, vget_low_f32(b), vget_low_f32(tmp));
      t = vmla_f32(t, a, Yn);
      t = vpadd_f32(t, t);
      Yn = vext_f32(Yn, t, 1);

      tmp = vextq_f32(Xn, x, 2);
      t = vmul_f32(vget_high_f32(b), vget_high_f32(tmp));
      t = vmla_f32(t, vget_low_f32(b), vget_low_f32(tmp));
      t = vmla_f32(t, a, Yn);
      t = vpadd_f32(t, t);
      Yn = vext_f32(Yn, t, 1);

      y.val[0] = Yn;

      tmp = vextq_f32(Xn, x, 3);
      t = vmul_f32(vget_high_f32(b), vget_high_f32(tmp));
      t = vmla_f32(t, vget_low_f32(b), vget_low_f32(tmp));
      t = vmla_f32(t, a, Yn);
      t = vpadd_f32(t, t);
      Yn = vext_f32(Yn, t, 1);

      Xn = x;
      t = vmul_f32(vget_high_f32(b), vget_high_f32(Xn));
      t = vmla_f32(t, vget_low_f32(b), vget_low_f32(Xn));
      t = vmla_f32(t, a, Yn);
      t = vpadd_f32(t, t);
      Yn = vext_f32(Yn, t, 1);
      
      y.val[1] = Yn;

      tmp = vcombine_f32(y.val[0], y.val[1]);

                                                         
      vst1q_f32(pOut, tmp);
      pOut += 4;

                                      
      sample--;
    }

                                                                                           
                                     
    sample = blockSize & 0x3U;

    while (sample > 0U)
    {
                          
      Xns = *pIn++;

                                                                                    
      acc =  (b[1] * Xn[2]) + (b[2] * Xn[3]) + (b[3] * Xns) + (a[0] * Yn[0]) + (a[1] * Yn[1]);

                                                                          
      *pOut++ = acc;

                                                                            
                                               
                       
                       
                       
                       
      Xn[2] = Xn[3];
      Xn[3] = Xns;
      Yn[0] = Yn[1];
      Yn[1] = acc;

                                      
      sample--;

    }

    vst1q_f32(pState,vcombine_f32(vrev64_f32(vget_high_f32(Xn)),vrev64_f32(Yn)));
    pState += 4;
                                                                       
   
                                                                           
                                                                    
    pIn = pDst;

                                  
    pOut = pDst;

                                    
    stage--;
  }
}

#else
void arm_biquad_cascade_df1_f32(
  const arm_biquad_casd_df1_inst_f32 * S,
  const float32_t * pSrc,
        float32_t * pDst,
        uint32_t blockSize)
{
  const float32_t *pIn = pSrc;                                             
        float32_t *pOut = pDst;                                                 
        float32_t *pState = S->pState;                                     
  const float32_t *pCoeffs = S->pCoeffs;                                        
        float32_t acc;                                                  
        float32_t b0, b1, b2, a1, a2;                                           
        float32_t Xn1, Xn2, Yn1, Yn2;                                               
        float32_t Xn;                                                       
        uint32_t sample, stage = S->numStages;                            

  do
  {
                                  
    b0 = *pCoeffs++;
    b1 = *pCoeffs++;
    b2 = *pCoeffs++;
    a1 = *pCoeffs++;
    a2 = *pCoeffs++;

                                   
    Xn1 = pState[0];
    Xn2 = pState[1];
    Yn1 = pState[2];
    Yn2 = pState[3];

#if defined (ARM_MATH_LOOPUNROLL)

                                                                          
                                                               
      
                                                                               
                                                                               
                                                                               
                                                                               
       

                                                     
    sample = blockSize >> 2U;

    while (sample > 0U)
    {
                                
      Xn = *pIn++;

                                                                                    
      Yn2 = (b0 * Xn) + (b1 * Xn1) + (b2 * Xn2) + (a1 * Yn1) + (a2 * Yn2);

                                               
      *pOut++ = Yn2;

                                                                            
                                            
                     
                     
                     
                     

                                 
      Xn2 = *pIn++;

                                                                                    
      Yn1 = (b0 * Xn2) + (b1 * Xn) + (b2 * Xn1) + (a1 * Yn2) + (a2 * Yn1);

                                               
      *pOut++ = Yn1;

                                                                            
                                            
                     
                     
                     
                     

                                
      Xn1 = *pIn++;

                                                                                    
      Yn2 = (b0 * Xn1) + (b1 * Xn2) + (b2 * Xn) + (a1 * Yn1) + (a2 * Yn2);

                                               
      *pOut++ = Yn2;

                                                                            
                                            
                     
                     
                     
                     

                                
      Xn = *pIn++;

                                                                                    
      Yn1 = (b0 * Xn) + (b1 * Xn1) + (b2 * Xn2) + (a1 * Yn2) + (a2 * Yn1);

                                               
      *pOut++ = Yn1;

                                                                            
                                            
                     
                     
                     
                     
      Xn2 = Xn1;
      Xn1 = Xn;

                                  
      sample--;
    }

                                                   
    sample = blockSize & 0x3U;

#else

                                                  
    sample = blockSize;

#endif                                        

    while (sample > 0U)
    {
                          
      Xn = *pIn++;

                                                                                    
      acc = (b0 * Xn) + (b1 * Xn1) + (b2 * Xn2) + (a1 * Yn1) + (a2 * Yn2);

                                               
      *pOut++ = acc;

                                                                            
                                            
                     
                     
                     
                     
      Xn2 = Xn1;
      Xn1 = Xn;
      Yn2 = Yn1;
      Yn1 = acc;

                                  
      sample--;
    }

                                                                      
    *pState++ = Xn1;
    *pState++ = Xn2;
    *pState++ = Yn1;
    *pState++ = Yn2;

                                                                          
                                                                  
    pIn = pDst;

                              
    pOut = pDst;

                                
    stage--;

  } while (stage > 0U);

}

#endif                                 
   
                                  
   
