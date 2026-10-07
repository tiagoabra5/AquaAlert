                                                                         
                                  
                                              
                                                                                                       
  
                               
                       
  
                                   
                                                                          
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

void arm_biquad_cascade_df2T_f32(
  const arm_biquad_cascade_df2T_instance_f32 * S,
  const float32_t * pSrc,
        float32_t * pDst,
        uint32_t blockSize)
{
   const float32_t *pIn = pSrc;                                                   
   float32_t *pOut = pDst;                                                        
   float32_t *pState = S->pState;                                                 
   const float32_t *pCoeffs = S->pCoeffs;                                         
   float32_t acc1;                                                                
   float32_t b0, b1, b2, a1, a2;                                                  
   float32_t Xn1;                                                                 
   float32_t d1, d2;                                                              
   uint32_t sample, stageCnt,stage = S->numStages;                                


   float32_t Xn2, Xn3, Xn4;                                                       
   float32_t acc2, acc3, acc4;                                                    


   float32_t p0, p1, p2, p3, p4, A1;

   float32x4_t XnV, YnV;
   float32x4x2_t dV;
   float32x4_t zeroV = vdupq_n_f32(0.0);
   float32x4_t t1,t2,t3,t4,b1V,b2V,a1V,a2V,s;

                                                    
   stageCnt = stage >> 2;

   while (stageCnt > 0U)
   {
                                    
      t1 = vld1q_f32(pCoeffs);
      pCoeffs += 4;

      t2 = vld1q_f32(pCoeffs);
      pCoeffs += 4;

      t3 = vld1q_f32(pCoeffs);
      pCoeffs += 4;

      t4 = vld1q_f32(pCoeffs);
      pCoeffs += 4;

      b1V = vld1q_f32(pCoeffs);
      pCoeffs += 4;

      b2V = vld1q_f32(pCoeffs);
      pCoeffs += 4;

      a1V = vld1q_f32(pCoeffs);
      pCoeffs += 4;

      a2V = vld1q_f32(pCoeffs);
      pCoeffs += 4;

                                    
      dV = vld2q_f32(pState);

      sample = blockSize;
      
      while (sample > 0U) {
                                    
                                              
                                         

         XnV = vdupq_n_f32(*pIn++);

         s = dV.val[0];
         YnV = s;

         s = vextq_f32(zeroV,dV.val[0],3);
         YnV = vmlaq_f32(YnV, t1, s);

         s = vextq_f32(zeroV,dV.val[0],2);
         YnV = vmlaq_f32(YnV, t2, s);

         s = vextq_f32(zeroV,dV.val[0],1);
         YnV = vmlaq_f32(YnV, t3, s);

         YnV = vmlaq_f32(YnV, t4, XnV);

         s = vextq_f32(XnV,YnV,3);

         dV.val[0] = vmlaq_f32(dV.val[1], s, b1V);
         dV.val[0] = vmlaq_f32(dV.val[0], YnV, a1V);

         dV.val[1] = vmulq_f32(s, b2V);
         dV.val[1] = vmlaq_f32(dV.val[1], YnV, a2V);

         *pOut++ = YnV[3];

         sample--;
      }
     
                                                                       
      vst2q_f32(pState,dV);
      pState += 8;

                                                                            
      pIn = pDst;

                                           
      pOut = pDst;

                                      
      stageCnt--;

   } 

             
   stageCnt = stage & 3;
   
   while (stageCnt > 0U)
   {
                                    
      b0 = *pCoeffs++;
      b1 = *pCoeffs++;
      b2 = *pCoeffs++;
      a1 = *pCoeffs++;
      a2 = *pCoeffs++;

                                   
      d1 = pState[0];
      d2 = pState[1];

      sample = blockSize;

      while (sample > 0U)
      {
                             
         Xn1 = *pIn++;

                                    
         acc1 = (b0 * Xn1) + d1;

                                                                             
         *pOut++ = acc1;

                                                                               
                                              
         d1 = ((b1 * Xn1) + (a1 * acc1)) + d2;

                                         
         d2 = (b2 * Xn1) + (a2 * acc1);

                                         
         sample--;
      }

                                                                       
      *pState++ = d1;
      *pState++ = d2;

                                                                            
      pIn = pDst;

                                           
      pOut = pDst;

                                      
      stageCnt--;
   }
}
#else
LOW_OPTIMIZATION_ENTER
void arm_biquad_cascade_df2T_f32(
  const arm_biquad_cascade_df2T_instance_f32 * S,
  const float32_t * pSrc,
        float32_t * pDst,
        uint32_t blockSize)
{
  const float32_t *pIn = pSrc;                                             
        float32_t *pOut = pDst;                                                 
        float32_t *pState = S->pState;                                    
  const float32_t *pCoeffs = S->pCoeffs;                                        
        float32_t acc1;                                                 
        float32_t b0, b1, b2, a1, a2;                                           
        float32_t Xn1;                                                      
        float32_t d1, d2;                                                   
        uint32_t sample, stage = S->numStages;                            

  do
  {
                                   
     b0 = pCoeffs[0];
     b1 = pCoeffs[1];
     b2 = pCoeffs[2];
     a1 = pCoeffs[3];
     a2 = pCoeffs[4];

                                   
     d1 = pState[0];
     d2 = pState[1];

     pCoeffs += 5U;

#if defined (ARM_MATH_LOOPUNROLL)

                                                       
     sample = blockSize >> 4U;

     while (sample > 0U) {

                                  
                                            
                                       

        
       Xn1 = *pIn++;

       acc1 = b0 * Xn1 + d1;

       d1 = b1 * Xn1 + d2;
       d1 += a1 * acc1;

       d2 = b2 * Xn1;
       d2 += a2 * acc1;

       *pOut++ = acc1;

        
         Xn1 = *pIn++;

        acc1 = b0 * Xn1 + d1;

        d1 = b1 * Xn1 + d2;
        d1 += a1 * acc1;

        d2 = b2 * Xn1;
        d2 += a2 * acc1;

        *pOut++ = acc1;

        
         Xn1 = *pIn++;

        acc1 = b0 * Xn1 + d1;

        d1 = b1 * Xn1 + d2;
        d1 += a1 * acc1;

        d2 = b2 * Xn1;
        d2 += a2 * acc1;

        *pOut++ = acc1;

        
         Xn1 = *pIn++;

        acc1 = b0 * Xn1 + d1;

        d1 = b1 * Xn1 + d2;
        d1 += a1 * acc1;

        d2 = b2 * Xn1;
        d2 += a2 * acc1;

        *pOut++ = acc1;

        
         Xn1 = *pIn++;

        acc1 = b0 * Xn1 + d1;

        d1 = b1 * Xn1 + d2;
        d1 += a1 * acc1;

        d2 = b2 * Xn1;
        d2 += a2 * acc1;

        *pOut++ = acc1;

        
         Xn1 = *pIn++;

        acc1 = b0 * Xn1 + d1;

        d1 = b1 * Xn1 + d2;
        d1 += a1 * acc1;

        d2 = b2 * Xn1;
        d2 += a2 * acc1;

        *pOut++ = acc1;

        
         Xn1 = *pIn++;

        acc1 = b0 * Xn1 + d1;

        d1 = b1 * Xn1 + d2;
        d1 += a1 * acc1;

        d2 = b2 * Xn1;
        d2 += a2 * acc1;

        *pOut++ = acc1;

        
         Xn1 = *pIn++;

        acc1 = b0 * Xn1 + d1;

        d1 = b1 * Xn1 + d2;
        d1 += a1 * acc1;

        d2 = b2 * Xn1;
        d2 += a2 * acc1;

        *pOut++ = acc1;

        
         Xn1 = *pIn++;

        acc1 = b0 * Xn1 + d1;

        d1 = b1 * Xn1 + d2;
        d1 += a1 * acc1;

        d2 = b2 * Xn1;
        d2 += a2 * acc1;

        *pOut++ = acc1;

        
         Xn1 = *pIn++;

        acc1 = b0 * Xn1 + d1;

        d1 = b1 * Xn1 + d2;
        d1 += a1 * acc1;

        d2 = b2 * Xn1;
        d2 += a2 * acc1;

        *pOut++ = acc1;

        
         Xn1 = *pIn++;

        acc1 = b0 * Xn1 + d1;

        d1 = b1 * Xn1 + d2;
        d1 += a1 * acc1;

        d2 = b2 * Xn1;
        d2 += a2 * acc1;

        *pOut++ = acc1;

        
         Xn1 = *pIn++;

        acc1 = b0 * Xn1 + d1;

        d1 = b1 * Xn1 + d2;
        d1 += a1 * acc1;

        d2 = b2 * Xn1;
        d2 += a2 * acc1;

        *pOut++ = acc1;

        
         Xn1 = *pIn++;

        acc1 = b0 * Xn1 + d1;

        d1 = b1 * Xn1 + d2;
        d1 += a1 * acc1;

        d2 = b2 * Xn1;
        d2 += a2 * acc1;

        *pOut++ = acc1;

        
         Xn1 = *pIn++;

        acc1 = b0 * Xn1 + d1;

        d1 = b1 * Xn1 + d2;
        d1 += a1 * acc1;

        d2 = b2 * Xn1;
        d2 += a2 * acc1;

        *pOut++ = acc1;

        
         Xn1 = *pIn++;

        acc1 = b0 * Xn1 + d1;

        d1 = b1 * Xn1 + d2;
        d1 += a1 * acc1;

        d2 = b2 * Xn1;
        d2 += a2 * acc1;

        *pOut++ = acc1;

        
         Xn1 = *pIn++;

        acc1 = b0 * Xn1 + d1;

        d1 = b1 * Xn1 + d2;
        d1 += a1 * acc1;

        d2 = b2 * Xn1;
        d2 += a2 * acc1;

        *pOut++ = acc1;

                                    
        sample--;
      }

                                                     
      sample = blockSize & 0xFU;

#else

                                                    
      sample = blockSize;

#endif                                        

      while (sample > 0U) {
        Xn1 = *pIn++;

        acc1 = b0 * Xn1 + d1;

        d1 = b1 * Xn1 + d2;
        d1 += a1 * acc1;

        d2 = b2 * Xn1;
        d2 += a2 * acc1;

        *pOut++ = acc1;

                                    
        sample--;
      }

                                                                       
      pState[0] = d1;
      pState[1] = d2;

      pState += 2U;

                                                                            
      pIn = pDst;

                                            
      pOut = pDst;

                                  
      stage--;

   } while (stage > 0U);

}
LOW_OPTIMIZATION_EXIT
#endif                                 

   
                                   
   
