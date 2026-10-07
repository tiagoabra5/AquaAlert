                                                                         
                                  
                                       
                                                            
  
                               
                       
  
                                   
                                                                          
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
void arm_fir_decimate_f32(
  const arm_fir_decimate_instance_f32 * S,
  const float32_t * pSrc,
  float32_t * pDst,
  uint32_t blockSize)
{
  float32_t *pState = S->pState;                                    
  const float32_t *pCoeffs = S->pCoeffs;                                  
  float32_t *pStateCurnt;                                                                       
  float32_t *px;                                                                         
  const float32_t *pb;                                                                         
  float32_t sum0;                                                 
  float32_t x0, c0;                                                                                            
  uint32_t numTaps = S->numTaps;                                                                  
  uint32_t i, tapCnt, blkCnt, outBlockSize = blockSize / S->M;                     

  uint32_t blkCntN4;
  float32_t *px0, *px1, *px2, *px3;
  float32_t acc0, acc1, acc2, acc3;
  float32_t x1, x2, x3;

  float32x4_t accv,acc0v,acc1v,acc2v,acc3v;
  float32x4_t x0v, x1v, x2v, x3v;
  float32x4_t c0v;
  float32x2_t temp;
  float32x4_t sum0v;
 
                                                                      
                                                                                     
  pStateCurnt = S->pState + (numTaps - 1U);

                                                     
  blkCnt = outBlockSize / 4;
  blkCntN4 = outBlockSize - (4 * blkCnt);

  while (blkCnt > 0U)
  {
                                                                                      
    i = 4 * S->M;

    do
    {
      *pStateCurnt++ = *pSrc++;

    } while (--i);

                                  
    acc0v = vdupq_n_f32(0.0);
    acc1v = vdupq_n_f32(0.0);
    acc2v = vdupq_n_f32(0.0);
    acc3v = vdupq_n_f32(0.0);

                                                      
    px0 = pState;
    px1 = pState + S->M;
    px2 = pState + 2 * S->M;
    px3 = pState + 3 * S->M;

                                  
    pb = pCoeffs;

                                   
    tapCnt = numTaps >> 2;

                                     
                                                              

    while (tapCnt > 0U)
    {
                                             
      c0v = vld1q_f32(pb);
      pb += 4;

                                               
      x0v = vld1q_f32(px0);
      x1v = vld1q_f32(px1);
      x2v = vld1q_f32(px2);
      x3v = vld1q_f32(px3);

      px0 += 4;
      px1 += 4;
      px2 += 4;
      px3 += 4;
     
      acc0v = vmlaq_f32(acc0v, x0v, c0v);
      acc1v = vmlaq_f32(acc1v, x1v, c0v);
      acc2v = vmlaq_f32(acc2v, x2v, c0v);
      acc3v = vmlaq_f32(acc3v, x3v, c0v);

                                      
      tapCnt--;
    }

    temp = vpadd_f32(vget_low_f32(acc0v),vget_high_f32(acc0v));
    accv[0] = temp[0] + temp[1];

    temp = vpadd_f32(vget_low_f32(acc1v),vget_high_f32(acc1v));
    accv[1] = temp[0] + temp[1];

    temp = vpadd_f32(vget_low_f32(acc2v),vget_high_f32(acc2v));
    accv[2] = temp[0] + temp[1];

    temp = vpadd_f32(vget_low_f32(acc3v),vget_high_f32(acc3v));
    accv[3] = temp[0] + temp[1];

                                                                                        
    tapCnt = numTaps % 0x4U;

    while (tapCnt > 0U)
    {
                             
      c0 = *(pb++);

                                                             
      x0 = *(px0++);
      x1 = *(px1++);
      x2 = *(px2++);
      x3 = *(px3++);

                                           
      accv[0] += x0 * c0;
      accv[1] += x1 * c0;
      accv[2] += x2 * c0;
      accv[3] += x3 * c0;

                                      
      tapCnt--;
    }

                                                         
                                                                       
    pState = pState + 4 * S->M;

                                                                            
    vst1q_f32(pDst,accv);
    pDst += 4;

                                    
    blkCnt--;
  }

  while (blkCntN4 > 0U)
  {
                                                                                  
    i = S->M;

    do
    {
      *pStateCurnt++ = *pSrc++;

    } while (--i);

                                 
    sum0v =  vdupq_n_f32(0.0);

                                  
    px = pState;

                                  
    pb = pCoeffs;

                                   
    tapCnt = numTaps >> 2;

                                    
                                                              
    while (tapCnt > 0U)
    {
      c0v = vld1q_f32(pb);
      pb += 4;

      x0v = vld1q_f32(px);
      px += 4;

      sum0v = vmlaq_f32(sum0v, x0v, c0v);
      
                                      
      tapCnt--;
    }

    temp = vpadd_f32(vget_low_f32(sum0v),vget_high_f32(sum0v));
    sum0 = temp[0] + temp[1];

                                                                                        
    tapCnt = numTaps % 0x4U;

    while (tapCnt > 0U)
    {
                             
      c0 = *(pb++);

                                  
      x0 = *(px++);

                                           
      sum0 += x0 * c0;

                                      
      tapCnt--;
    }

                                                         
                                                                       
    pState = pState + S->M;

                                                                            
    *pDst++ = sum0;

                                    
    blkCntN4--;
  }

                            
                                                                             
                                                                   

                                               
  pStateCurnt = S->pState;

  i = (numTaps - 1U) >> 2;

                 
  while (i > 0U)
  {
    sum0v = vld1q_f32(pState);
    vst1q_f32(pStateCurnt,sum0v);
    pState += 4;
    pStateCurnt += 4;

                                    
    i--;
  }

  i = (numTaps - 1U) % 0x04U;

                 
  while (i > 0U)
  {
    *pStateCurnt++ = *pState++;

                                    
    i--;
  }
}
#else
void arm_fir_decimate_f32(
  const arm_fir_decimate_instance_f32 * S,
  const float32_t * pSrc,
        float32_t * pDst,
        uint32_t blockSize)
{
        float32_t *pState = S->pState;                                    
  const float32_t *pCoeffs = S->pCoeffs;                                        
        float32_t *pStateCur;                                                                         
        float32_t *px0;                                                                        
  const float32_t *pb;                                                                               
        float32_t x0, c0;                                                                                            
        float32_t acc0;                                                 
        uint32_t numTaps = S->numTaps;                                                                  
        uint32_t i, tapCnt, blkCnt, outBlockSize = blockSize / S->M;                     

#if defined (ARM_MATH_LOOPUNROLL)
        float32_t *px1, *px2, *px3;
        float32_t x1, x2, x3;
        float32_t acc1, acc2, acc3;
#endif

                                                                      
                                                                                   
  pStateCur = S->pState + (numTaps - 1U);

#if defined (ARM_MATH_LOOPUNROLL)

                                                     
  blkCnt = outBlockSize >> 2U;

                                  
  while (blkCnt > 0U)
  {
                                                                                      
    i = S->M * 4;

    do
    {
      *pStateCur++ = *pSrc++;

    } while (--i);

                                  
    acc0 = 0.0f;
    acc1 = 0.0f;
    acc2 = 0.0f;
    acc3 = 0.0f;

                                                      
    px0 = pState;
    px1 = pState + S->M;
    px2 = pState + 2 * S->M;
    px3 = pState + 3 * S->M;

                                  
    pb = pCoeffs;

                                                  
    tapCnt = numTaps >> 2U;

    while (tapCnt > 0U)
    {
                                             
      c0 = *(pb++);

                                               
      x0 = *(px0++);
                                               
      x1 = *(px1++);
                                               
      x2 = *(px2++);
                                               
      x3 = *(px3++);

                                           
      acc0 += x0 * c0;
      acc1 += x1 * c0;
      acc2 += x2 * c0;
      acc3 += x3 * c0;

                                             
      c0 = *(pb++);

                                                                 
      x0 = *(px0++);
      x1 = *(px1++);
      x2 = *(px2++);
      x3 = *(px3++);

                                           
      acc0 += x0 * c0;
      acc1 += x1 * c0;
      acc2 += x2 * c0;
      acc3 += x3 * c0;

                                             
      c0 = *(pb++);

                                                             
      x0 = *(px0++);
      x1 = *(px1++);
      x2 = *(px2++);
      x3 = *(px3++);

                                           
      acc0 += x0 * c0;
      acc1 += x1 * c0;
      acc2 += x2 * c0;
      acc3 += x3 * c0;

                                             
      c0 = *(pb++);

                                                             
      x0 = *(px0++);
      x1 = *(px1++);
      x2 = *(px2++);
      x3 = *(px3++);

                                           
      acc0 += x0 * c0;
      acc1 += x1 * c0;
      acc2 += x2 * c0;
      acc3 += x3 * c0;

                                  
      tapCnt--;
    }

                                                
    tapCnt = numTaps % 0x4U;

    while (tapCnt > 0U)
    {
                             
      c0 = *(pb++);

                                                            
      x0 = *(px0++);
      x1 = *(px1++);
      x2 = *(px2++);
      x3 = *(px3++);

                                           
      acc0 += x0 * c0;
      acc1 += x1 * c0;
      acc2 += x2 * c0;
      acc3 += x3 * c0;

                                  
      tapCnt--;
    }

                                                         
                                                                       
    pState = pState + S->M * 4;

                                                                            
    *pDst++ = acc0;
    *pDst++ = acc1;
    *pDst++ = acc2;
    *pDst++ = acc3;

                                
    blkCnt--;
  }

                                                 
  blkCnt = outBlockSize % 0x4U;

#else

                                                
  blkCnt = outBlockSize;

#endif                                        

  while (blkCnt > 0U)
  {
                                                                                  
    i = S->M;

    do
    {
      *pStateCur++ = *pSrc++;

    } while (--i);

                                 
    acc0 = 0.0f;

                                  
    px0 = pState;

                                  
    pb = pCoeffs;

#if defined (ARM_MATH_LOOPUNROLL)

                                                  
    tapCnt = numTaps >> 2U;

    while (tapCnt > 0U)
    {
                                             
      c0 = *pb++;

                                      
      x0 = *px0++;

                                           
      acc0 += x0 * c0;

                                             
      c0 = *pb++;

                                      
      x0 = *px0++;

                                           
      acc0 += x0 * c0;

                                             
      c0 = *pb++;

                                      
      x0 = *px0++;

                                           
      acc0 += x0 * c0;

                                             
      c0 = *pb++;

                                      
      x0 = *px0++;

                                           
      acc0 += x0 * c0;

                                  
      tapCnt--;
    }

                                                
    tapCnt = numTaps % 0x4U;

#else

                                               
    tapCnt = numTaps;

#endif                                        

    while (tapCnt > 0U)
    {
                             
      c0 = *pb++;

                                  
      x0 = *px0++;

                                           
      acc0 += x0 * c0;

                                  
      tapCnt--;
    }

                                                         
                                                                       
    pState = pState + S->M;

                                                                            
    *pDst++ = acc0;

                                
    blkCnt--;
  }

                            
                                                                            
                                                                  

                                               
  pStateCur = S->pState;

#if defined (ARM_MATH_LOOPUNROLL)

                                                
  tapCnt = (numTaps - 1U) >> 2U;

                 
  while (tapCnt > 0U)
  {
    *pStateCur++ = *pState++;
    *pStateCur++ = *pState++;
    *pStateCur++ = *pState++;
    *pStateCur++ = *pState++;

                                
    tapCnt--;
  }

                                              
  tapCnt = (numTaps - 1U) % 0x04U;

#else

                                             
  tapCnt = (numTaps - 1U);

#endif                                        

                 
  while (tapCnt > 0U)
  {
    *pStateCur++ = *pState++;

                                
    tapCnt--;
  }

}
#endif                                 

   
                              
   
