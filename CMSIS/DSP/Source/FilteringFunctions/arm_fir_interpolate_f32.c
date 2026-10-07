                                                                         
                                  
                                          
                                                           
  
                               
                       
  
                                   
                                                                          
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
void arm_fir_interpolate_f32(
  const arm_fir_interpolate_instance_f32 * S,
  const float32_t * pSrc,
  float32_t * pDst,
  uint32_t blockSize)
{
  float32_t *pState = S->pState;                                    
  const float32_t *pCoeffs = S->pCoeffs;                                  
  float32_t *pStateCurnt;                                                                       
  float32_t *ptr1;                                                                        
  const float32_t *ptr2;                                                                        
  float32_t sum0;                                                  
  float32_t x0, c0;                                                                                            
  uint32_t i, blkCnt, j;                                            
  uint16_t phaseLen = S->phaseLength, tapCnt;                                                   
  float32_t acc0, acc1, acc2, acc3;
  float32_t x1, x2, x3;
  uint32_t blkCntN4;
  float32_t c1, c2, c3;

  float32x4_t sum0v;
  float32x4_t accV,accV0,accV1;
  float32x4_t x0v,x1v,x2v,xa,xb;
  uint32x4_t x0v_u,x1v_u,x2v_u,xa_u,xb_u;
  float32x2_t tempV;

                                                                       
                                                                                     
  pStateCurnt = S->pState + (phaseLen - 1U);

                          
  blkCnt = blockSize >> 3;
  blkCntN4 = blockSize & 7;

                      
  while (blkCnt > 0U)
  {
                                                      
    sum0v = vld1q_f32(pSrc);
    vst1q_f32(pStateCurnt,sum0v);
    pSrc += 4;
    pStateCurnt += 4;

    sum0v = vld1q_f32(pSrc);
    vst1q_f32(pStateCurnt,sum0v);
    pSrc += 4;
    pStateCurnt += 4;

                                                      
    j = 1U;

                                             
    i = (S->L);

    while (i > 0U)
    {
                                   
      accV0 = vdupq_n_f32(0.0);
      accV1 = vdupq_n_f32(0.0);

                                    
      ptr1 = pState;

                                          
      ptr2 = pCoeffs + (S->L - j);

                                                                 
                                                                       
      tapCnt = phaseLen >> 2U;
     
      x0v = vld1q_f32(ptr1);
      x1v = vld1q_f32(ptr1 + 4);
	
      while (tapCnt > 0U)
      {
                                    
        x2v = vld1q_f32(ptr1 + 8);

                                   
        c0 = *(ptr2);

                                             
        accV0 = vmlaq_n_f32(accV0,x0v,c0);
        accV1 = vmlaq_n_f32(accV1,x1v,c0);
       
                                                                           
        c1 = *(ptr2 + S->L);
	
        xa = vextq_f32(x0v,x1v,1);
        xb = vextq_f32(x1v,x2v,1);

        accV0 = vmlaq_n_f32(accV0,xa,c1);
        accV1 = vmlaq_n_f32(accV1,xb,c1);

                                                                           
        c2 = *(ptr2 + S->L * 2);
	
        xa = vextq_f32(x0v,x1v,2);
        xb = vextq_f32(x1v,x2v,2);
        
	accV0 = vmlaq_n_f32(accV0,xa,c2);
        accV1 = vmlaq_n_f32(accV1,xb,c2);

                                                                           
        c3 = *(ptr2 + S->L * 3);

        xa = vextq_f32(x0v,x1v,3);
        xb = vextq_f32(x1v,x2v,3);
        
	accV0 = vmlaq_n_f32(accV0,xa,c3);
        accV1 = vmlaq_n_f32(accV1,xb,c3);

                                                                        
                                                             
                                                                              
        ptr2 += 4 * S->L;
        ptr1 += 4;
        x0v = x1v;
        x1v = x2v;

                                        
        tapCnt--;
      }

                                                                                             
      tapCnt = phaseLen % 0x4U;

      x2v = vld1q_f32(ptr1 + 8);

      switch (tapCnt)
      {
        case 3:
             c0 = *(ptr2);
             accV0 = vmlaq_n_f32(accV0,x0v,c0);
             accV1 = vmlaq_n_f32(accV1,x1v,c0);
             ptr2 += S->L;

             c0 = *(ptr2);

             xa = vextq_f32(x0v,x1v,1);
             xb = vextq_f32(x1v,x2v,1);

             accV0 = vmlaq_n_f32(accV0,xa,c0);
             accV1 = vmlaq_n_f32(accV1,xb,c0);
             ptr2 += S->L;

             c0 = *(ptr2);

             xa = vextq_f32(x0v,x1v,2);
             xb = vextq_f32(x1v,x2v,2);
             
	     accV0 = vmlaq_n_f32(accV0,xa,c0);
             accV1 = vmlaq_n_f32(accV1,xb,c0);
             ptr2 += S->L;

        break;

        case 2:
             c0 = *(ptr2);
             accV0 = vmlaq_n_f32(accV0,x0v,c0);
             accV1 = vmlaq_n_f32(accV1,x1v,c0);
             ptr2 += S->L;

             c0 = *(ptr2);

             xa = vextq_f32(x0v,x1v,1);
             xb = vextq_f32(x1v,x2v,1);
             
	     accV0 = vmlaq_n_f32(accV0,xa,c0);
             accV1 = vmlaq_n_f32(accV1,xb,c0);
             ptr2 += S->L;

        break;

        case 1:
             c0 = *(ptr2);
             accV0 = vmlaq_n_f32(accV0,x0v,c0);
             accV1 = vmlaq_n_f32(accV1,x1v,c0);
             ptr2 += S->L;

        break;

        default:
        break;
        
      }

                                                                              
      *pDst = accV0[0];
      *(pDst + S->L) = accV0[1];
      *(pDst + 2 * S->L) = accV0[2];
      *(pDst + 3 * S->L) = accV0[3];

      *(pDst + 4 * S->L) = accV1[0];
      *(pDst + 5 * S->L) = accV1[1];
      *(pDst + 6 * S->L) = accV1[2];
      *(pDst + 7 * S->L) = accV1[3];

      pDst++;

                                                                      
      j++;

                                      
      i--;
    }

                                     
                                                                          
    pState = pState + 8;

    pDst += S->L * 7;

                                    
    blkCnt--;
  }

                                                                                        
                                   

  while (blkCntN4 > 0U)
  {
                                                     
    *pStateCurnt++ = *pSrc++;

                                                      
    j = 1U;

                                             
    i = S->L;

    while (i > 0U)
    {
                                   
      sum0v = vdupq_n_f32(0.0);

                                    
      ptr1 = pState;

                                          
      ptr2 = pCoeffs + (S->L - j);

                                                                 
                                                                       
      tapCnt = phaseLen >> 2U;

      while (tapCnt > 0U)
      {
                                  
        x1v[0] = *(ptr2);

                                                                        
                                                             
                                                                              
        ptr2 += S->L;

                                   
        x0v = vld1q_f32(ptr1);
        ptr1 += 4;

                                  
        x1v[1] = *(ptr2);

                                                                              
        ptr2 += S->L;

                                  
        x1v[2] = *(ptr2);

                                                                              
        ptr2 += S->L;

                                  
        x1v[3] = *(ptr2);

                                                                              
        ptr2 += S->L;

        sum0v = vmlaq_f32(sum0v,x0v,x1v);
       
                                        
        tapCnt--;
      }

      tempV = vpadd_f32(vget_low_f32(sum0v),vget_high_f32(sum0v));
      sum0 = tempV[0] + tempV[1];

                                                                                             
      tapCnt = phaseLen % 0x4U;

      while (tapCnt > 0U)
      {
                                             
        sum0 += *(ptr1++) * (*ptr2);

                                                                              
        ptr2 += S->L;

                                        
        tapCnt--;
      }

                                                                              
      *pDst++ = sum0;

                                                                      
      j++;

                                      
      i--;
    }

                                     
                                                                          
    pState = pState + 1;

                                    
    blkCntN4--;
  }

                            
                                                                              
                                                                   

                                               
  pStateCurnt = S->pState;

  tapCnt = (phaseLen - 1U) >> 2U;

                 
  while (tapCnt > 0U)
  {
    sum0v = vld1q_f32(pState);
    vst1q_f32(pStateCurnt,sum0v);
    pState += 4;
    pStateCurnt += 4;

                                    
    tapCnt--;
  }

  tapCnt = (phaseLen - 1U) % 0x04U;

                 
  while (tapCnt > 0U)
  {
    *pStateCurnt++ = *pState++;

                                    
    tapCnt--;
  }

}
#else

void arm_fir_interpolate_f32(
  const arm_fir_interpolate_instance_f32 * S,
  const float32_t * pSrc,
        float32_t * pDst,
        uint32_t blockSize)
{
#if (1)
                                   

        float32_t *pState = S->pState;                                    
  const float32_t *pCoeffs = S->pCoeffs;                                        
        float32_t *pStateCur;                                                                         
        float32_t *ptr1;                                                                       
  const float32_t *ptr2;                                                                             
        float32_t sum0;                                                  
        uint32_t i, blkCnt, tapCnt;                                       
        uint32_t phaseLen = S->phaseLength;                                                           
        uint32_t j;

#if defined (ARM_MATH_LOOPUNROLL)
        float32_t acc0, acc1, acc2, acc3;
        float32_t x0, x1, x2, x3;
        float32_t c0, c1, c2, c3;
#endif

                                                                       
                                                                                   
  pStateCur = S->pState + (phaseLen - 1U);

#if defined (ARM_MATH_LOOPUNROLL)

                                                   
  blkCnt = blockSize >> 2U;

  while (blkCnt > 0U)
  {
                                                     
    *pStateCur++ = *pSrc++;
    *pStateCur++ = *pSrc++;
    *pStateCur++ = *pSrc++;
    *pStateCur++ = *pSrc++;

                                                      
    j = 1U;

                                             
    i = (S->L);

    while (i > 0U)
    {
                                   
      acc0 = 0.0f;
      acc1 = 0.0f;
      acc2 = 0.0f;
      acc3 = 0.0f;

                                    
      ptr1 = pState;

                                          
      ptr2 = pCoeffs + (S->L - j);

                                                                 
                                                                      
      tapCnt = phaseLen >> 2U;

      x0 = *(ptr1++);
      x1 = *(ptr1++);
      x2 = *(ptr1++);

      while (tapCnt > 0U)
      {
                                   
        x3 = *(ptr1++);

                                  
        c0 = *(ptr2);

                                             
        acc0 += x0 * c0;
        acc1 += x1 * c0;
        acc2 += x2 * c0;
        acc3 += x3 * c0;

                                  
        c1 = *(ptr2 + S->L);

                                   
        x0 = *(ptr1++);

                                             
        acc0 += x1 * c1;
        acc1 += x2 * c1;
        acc2 += x3 * c1;
        acc3 += x0 * c1;

                                  
        c2 = *(ptr2 + S->L * 2);

                                   
        x1 = *(ptr1++);

                                             
        acc0 += x2 * c2;
        acc1 += x3 * c2;
        acc2 += x0 * c2;
        acc3 += x1 * c2;

                                  
        c3 = *(ptr2 + S->L * 3);

                                   
        x2 = *(ptr1++);

                                             
        acc0 += x3 * c3;
        acc1 += x0 * c3;
        acc2 += x1 * c3;
        acc3 += x2 * c3;


                                                                        
                                                             
                                                                              
        ptr2 += 4 * S->L;

                                    
        tapCnt--;
      }

                                                                                             
      tapCnt = phaseLen % 0x4U;

      while (tapCnt > 0U)
      {
                                   
        x3 = *(ptr1++);

                                  
        c0 = *(ptr2);

                                             
        acc0 += x0 * c0;
        acc1 += x1 * c0;
        acc2 += x2 * c0;
        acc3 += x3 * c0;

                                                                              
        ptr2 += S->L;

                                                      
        x0 = x1;
        x1 = x2;
        x2 = x3;

                                    
        tapCnt--;
      }

                                                                              
      *(pDst           ) = acc0;
      *(pDst +     S->L) = acc1;
      *(pDst + 2 * S->L) = acc2;
      *(pDst + 3 * S->L) = acc3;

      pDst++;

                                                                      
      j++;

                                  
      i--;
    }

                                     
                                                                          
    pState = pState + 4;

    pDst += S->L * 3;

                                
    blkCnt--;
  }

                                                 
  blkCnt = blockSize % 0x4U;

#else

                                                
  blkCnt = blockSize;

#endif                                        

  while (blkCnt > 0U)
  {
                                                     
    *pStateCur++ = *pSrc++;

                                                      
    j = 1U;

                                             
    i = S->L;

    while (i > 0U)
    {
                                   
      sum0 = 0.0f;

                                    
      ptr1 = pState;

                                          
      ptr2 = pCoeffs + (S->L - j);

                                        
                                                                      

#if defined (ARM_MATH_LOOPUNROLL)

                                                      
      tapCnt = phaseLen >> 2U;

      while (tapCnt > 0U)
      {
                                             
        sum0 += *ptr1++ * *ptr2;

                                                                        
                                                             
                                                                              
        ptr2 += S->L;

        sum0 += *ptr1++ * *ptr2;
        ptr2 += S->L;

        sum0 += *ptr1++ * *ptr2;
        ptr2 += S->L;

        sum0 += *ptr1++ * *ptr2;
        ptr2 += S->L;

                                    
        tapCnt--;
      }

                                                     
      tapCnt = phaseLen % 0x4U;

#else

                                                    
      tapCnt = phaseLen;

#endif                                        

      while (tapCnt > 0U)
      {
                                             
        sum0 += *ptr1++ * *ptr2;

                                                                        
                                                             
                                                                              
        ptr2 += S->L;

                                    
        tapCnt--;
      }

                                                                              
      *pDst++ = sum0;

                                                                      
      j++;

                                      
      i--;
    }

                                     
                                                                          
    pState = pState + 1;

                                    
    blkCnt--;
  }

                            
                                                                             
                                                                  

                                               
  pStateCur = S->pState;

#if defined (ARM_MATH_LOOPUNROLL)

                                                   
  tapCnt = (phaseLen - 1U) >> 2U;

                 
  while (tapCnt > 0U)
  {
    *pStateCur++ = *pState++;
    *pStateCur++ = *pState++;
    *pStateCur++ = *pState++;
    *pStateCur++ = *pState++;

                                
    tapCnt--;
  }

                                                 
  tapCnt = (phaseLen - 1U) % 0x04U;

#else

                                                  
    tapCnt = (phaseLen - 1U);

#endif                                        

                 
  while (tapCnt > 0U)
  {
    *pStateCur++ = *pState++;

                                
    tapCnt--;
  }

#else
                                      

        float32_t *pState = S->pState;                                    
  const float32_t *pCoeffs = S->pCoeffs;                                        
        float32_t *pStateCur;                                                                       
        float32_t *ptr1;                                                                       
  const float32_t *ptr2;                                                                             
        float32_t sum0;                                                  
        uint32_t i, blkCnt, tapCnt;                                       
        uint32_t phaseLen = S->phaseLength;                                                           

                                                                       
                                                                                   
  pStateCur = S->pState + (phaseLen - 1U);

                                      
  blkCnt = blockSize;

                                
  while (blkCnt > 0U)
  {
                                                     
    *pStateCur++ = *pSrc++;

                                             
    i = S->L;

    while (i > 0U)
    {
                                   
      sum0 = 0.0f;

                                    
      ptr1 = pState;

                                          
      ptr2 = pCoeffs + (i - 1U);

                                          
      tapCnt = phaseLen;

      while (tapCnt > 0U)
      {
                                             
        sum0 += *ptr1++ * *ptr2;

                                                                              
        ptr2 += S->L;

                                        
        tapCnt--;
      }

                                                                              
      *pDst++ = sum0;

                                  
      i--;
    }

                                     
                                                                          
    pState = pState + 1;

                                
    blkCnt--;
  }

                            
                                                                              
                                                                   

                                               
  pStateCur = S->pState;

  tapCnt = phaseLen - 1U;

                 
  while (tapCnt > 0U)
  {
    *pStateCur++ = *pState++;

                                
    tapCnt--;
  }

#endif                                        

}

#endif                                 

   
                                 
   
