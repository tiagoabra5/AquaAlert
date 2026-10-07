                                                                         
                                  
                              
                                                              
  
                               
                       
  
                                   
                                                                          
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

void arm_fir_f32(
const arm_fir_instance_f32 * S,
const float32_t * pSrc,
float32_t * pDst,
uint32_t blockSize)
{
   float32_t *pState = S->pState;                                    
   const float32_t *pCoeffs = S->pCoeffs;                                  
   float32_t *pStateCurnt;                                                                       
   float32_t *px;                                                                          
   const float32_t *pb;                                                                          
   uint32_t numTaps = S->numTaps;                                                                  
   uint32_t i, tapCnt, blkCnt;                                       

   float32x4_t accv0,accv1,samples0,samples1,x0,x1,x2,xa,xb,x,b,accv;
   uint32x4_t x0_u,x1_u,x2_u,xa_u,xb_u;
   float32_t acc;

                                                                                            
                                                                                      
   pStateCurnt = &(S->pState[(numTaps - 1U)]);

                       
   blkCnt = blockSize >> 3;

   while (blkCnt > 0U)
   {
                                                       
      samples0 = vld1q_f32(pSrc);
      vst1q_f32(pStateCurnt,samples0);

      pStateCurnt += 4;
      pSrc += 4 ;

      samples1 = vld1q_f32(pSrc);
      vst1q_f32(pStateCurnt,samples1);

      pStateCurnt += 4;
      pSrc += 4 ;

                                        
      accv0 = vdupq_n_f32(0);
      accv1 = vdupq_n_f32(0);

                                    
      px = pState;

                                          
      pb = pCoeffs;

                         
      i = numTaps >> 2;

                                            
      x0 = vld1q_f32(px);
      x1 = vld1q_f32(px + 4);

      while(i > 0)
      {
                                                                                                                                     
         x2 = vld1q_f32(px + 8);
         b = vld1q_f32(pb);
         xa = x0;
         xb = x1;
         accv0 = vmlaq_n_f32(accv0,xa,b[0]);
         accv1 = vmlaq_n_f32(accv1,xb,b[0]);

         xa = vextq_f32(x0,x1,1);
         xb = vextq_f32(x1,x2,1);
         
	 accv0 = vmlaq_n_f32(accv0,xa,b[1]);
         accv1 = vmlaq_n_f32(accv1,xb,b[1]);

	 xa = vextq_f32(x0,x1,2);
         xb = vextq_f32(x1,x2,2);

         accv0 = vmlaq_n_f32(accv0,xa,b[2]);
         accv1 = vmlaq_n_f32(accv1,xb,b[2]);

	 xa = vextq_f32(x0,x1,3);
	 xb = vextq_f32(x1,x2,3);
         
 	 accv0 = vmlaq_n_f32(accv0,xa,b[3]);
         accv1 = vmlaq_n_f32(accv1,xb,b[3]);

         pb += 4;
         x0 = x1;
         x1 = x2;
         px += 4;
         i--;

      }

                
      i = numTaps & 3;
      x2 = vld1q_f32(px + 8);

                                            
      switch(i)
      {
         case 3:
         {
           accv0 = vmlaq_n_f32(accv0,x0,*pb);
           accv1 = vmlaq_n_f32(accv1,x1,*pb);

           pb++;

	   xa = vextq_f32(x0,x1,1);
	   xb = vextq_f32(x1,x2,1);

           accv0 = vmlaq_n_f32(accv0,xa,*pb);
           accv1 = vmlaq_n_f32(accv1,xb,*pb);

           pb++;

           xa = vextq_f32(x0,x1,2);
           xb = vextq_f32(x1,x2,2);
           
	   accv0 = vmlaq_n_f32(accv0,xa,*pb);
           accv1 = vmlaq_n_f32(accv1,xb,*pb);

         }
         break;
         case 2:
         {
           accv0 = vmlaq_n_f32(accv0,x0,*pb);
           accv1 = vmlaq_n_f32(accv1,x1,*pb);

           pb++;

           xa = vextq_f32(x0,x1,1);
           xb = vextq_f32(x1,x2,1);
           
	   accv0 = vmlaq_n_f32(accv0,xa,*pb);
           accv1 = vmlaq_n_f32(accv1,xb,*pb);

         }
         break;
         case 1:
         {
           
           accv0 = vmlaq_n_f32(accv0,x0,*pb);
           accv1 = vmlaq_n_f32(accv1,x1,*pb);

         }
         break;
         default:
         break;
      }

                                                           
      vst1q_f32(pDst,accv0);
      pDst += 4;
      vst1q_f32(pDst,accv1);
      pDst += 4;

                                                             
      pState = pState + 8;

      blkCnt--;
   }

             
   blkCnt = blockSize & 0x7;

   while (blkCnt > 0U)
   {
                                                       
      *pStateCurnt++ = *pSrc++;

                                       
      acc = 0.0f;

                                    
      px = pState;

                                          
      pb = pCoeffs;

      i = numTaps;

                                            
      do
      {
                                                                                                                                     
         acc += *px++ * *pb++;
         i--;

      } while (i > 0U);

                                                           
      *pDst++ = acc;

                                                          
      pState = pState + 1;

      blkCnt--;
   }

                             
                                                                                
                                                                   

                                                
   pStateCurnt = S->pState;

                                      
   tapCnt = numTaps - 1U;

                  
   while (tapCnt > 0U)
   {
      *pStateCurnt++ = *pState++;

                                      
      tapCnt--;
   }

}
#else
void arm_fir_f32(
  const arm_fir_instance_f32 * S,
  const float32_t * pSrc,
        float32_t * pDst,
        uint32_t blockSize)
{
        float32_t *pState = S->pState;                                    
  const float32_t *pCoeffs = S->pCoeffs;                                        
        float32_t *pStateCurnt;                                                                       
        float32_t *px;                                                                         
  const float32_t *pb;                                                                               
        float32_t acc0;                                                 
        uint32_t numTaps = S->numTaps;                                                                  
        uint32_t i, tapCnt, blkCnt;                                       

#if defined (ARM_MATH_LOOPUNROLL)
        float32_t acc1, acc2, acc3, acc4, acc5, acc6, acc7;                       
        float32_t x0, x1, x2, x3, x4, x5, x6, x7;                                                             
        float32_t c0;                                                                                             
#endif

                                                                                           
                                                                                     
  pStateCurnt = &(S->pState[(numTaps - 1U)]);

#if defined (ARM_MATH_LOOPUNROLL)

                                                            
                                                                            
    
                                                                                                                               
                                                                                                                               
                                                                                                                               
                                                                                                                               
     

  blkCnt = blockSize >> 3U;

  while (blkCnt > 0U)
  {
                                                         
    *pStateCurnt++ = *pSrc++;
    *pStateCurnt++ = *pSrc++;
    *pStateCurnt++ = *pSrc++;
    *pStateCurnt++ = *pSrc++;

                                      
    acc0 = 0.0f;
    acc1 = 0.0f;
    acc2 = 0.0f;
    acc3 = 0.0f;
    acc4 = 0.0f;
    acc5 = 0.0f;
    acc6 = 0.0f;
    acc7 = 0.0f;

                                  
    px = pState;

                                        
    pb = pCoeffs;

                                                 
                                                      
       
    *pStateCurnt++ = *pSrc++;
    *pStateCurnt++ = *pSrc++;
    *pStateCurnt++ = *pSrc++;
    *pStateCurnt++ = *pSrc++;

                                                                                                       
    x0 = *px++;
    x1 = *px++;
    x2 = *px++;
    x3 = *px++;
    x4 = *px++;
    x5 = *px++;
    x6 = *px++;

                                                   
    tapCnt = numTaps >> 3U;

    while (tapCnt > 0U)
    {
                                             
      c0 = *(pb++);

                                      
      x7 = *(px++);

                                                
      acc0 += x0 * c0;

                                                  
      acc1 += x1 * c0;

                                                  
      acc2 += x2 * c0;

                                                  
      acc3 += x3 * c0;

                                                  
      acc4 += x4 * c0;

                                                  
      acc5 += x5 * c0;

                                                  
      acc6 += x6 * c0;

                                                  
      acc7 += x7 * c0;

                                             
      c0 = *(pb++);

                                      
      x0 = *(px++);

                                           
      acc0 += x1 * c0;
      acc1 += x2 * c0;
      acc2 += x3 * c0;
      acc3 += x4 * c0;
      acc4 += x5 * c0;
      acc5 += x6 * c0;
      acc6 += x7 * c0;
      acc7 += x0 * c0;

                                             
      c0 = *(pb++);

                                      
      x1 = *(px++);

                                            
      acc0 += x2 * c0;
      acc1 += x3 * c0;
      acc2 += x4 * c0;
      acc3 += x5 * c0;
      acc4 += x6 * c0;
      acc5 += x7 * c0;
      acc6 += x0 * c0;
      acc7 += x1 * c0;

                                             
      c0 = *(pb++);

                                      
      x2 = *(px++);

                                            
      acc0 += x3 * c0;
      acc1 += x4 * c0;
      acc2 += x5 * c0;
      acc3 += x6 * c0;
      acc4 += x7 * c0;
      acc5 += x0 * c0;
      acc6 += x1 * c0;
      acc7 += x2 * c0;

                                             
      c0 = *(pb++);

                                      
      x3 = *(px++);
                                            
      acc0 += x4 * c0;
      acc1 += x5 * c0;
      acc2 += x6 * c0;
      acc3 += x7 * c0;
      acc4 += x0 * c0;
      acc5 += x1 * c0;
      acc6 += x2 * c0;
      acc7 += x3 * c0;

                                             
      c0 = *(pb++);

                                      
      x4 = *(px++);

                                            
      acc0 += x5 * c0;
      acc1 += x6 * c0;
      acc2 += x7 * c0;
      acc3 += x0 * c0;
      acc4 += x1 * c0;
      acc5 += x2 * c0;
      acc6 += x3 * c0;
      acc7 += x4 * c0;

                                             
      c0 = *(pb++);

                                      
      x5 = *(px++);

                                            
      acc0 += x6 * c0;
      acc1 += x7 * c0;
      acc2 += x0 * c0;
      acc3 += x1 * c0;
      acc4 += x2 * c0;
      acc5 += x3 * c0;
      acc6 += x4 * c0;
      acc7 += x5 * c0;

                                             
      c0 = *(pb++);

                                      
      x6 = *(px++);

                                            
      acc0 += x7 * c0;
      acc1 += x0 * c0;
      acc2 += x1 * c0;
      acc3 += x2 * c0;
      acc4 += x3 * c0;
      acc5 += x4 * c0;
      acc6 += x5 * c0;
      acc7 += x6 * c0;

                                  
      tapCnt--;
    }

                                                   
    tapCnt = numTaps % 0x8U;

    while (tapCnt > 0U)
    {
                             
      c0 = *(pb++);

                                  
      x7 = *(px++);

                                            
      acc0 += x0 * c0;
      acc1 += x1 * c0;
      acc2 += x2 * c0;
      acc3 += x3 * c0;
      acc4 += x4 * c0;
      acc5 += x5 * c0;
      acc6 += x6 * c0;
      acc7 += x7 * c0;

                                                           
      x0 = x1;
      x1 = x2;
      x2 = x3;
      x3 = x4;
      x4 = x5;
      x5 = x6;
      x6 = x7;

                                  
      tapCnt--;
    }

                                                                               
    pState = pState + 8;

                                                                             
    *pDst++ = acc0;
    *pDst++ = acc1;
    *pDst++ = acc2;
    *pDst++ = acc3;
    *pDst++ = acc4;
    *pDst++ = acc5;
    *pDst++ = acc6;
    *pDst++ = acc7;


                                
    blkCnt--;
  }

                                                        
  blkCnt = blockSize % 0x8U;

#else

                                             
  blkCnt = blockSize;

#endif                                        

  while (blkCnt > 0U)
  {
                                                     
    *pStateCurnt++ = *pSrc++;

                                     
    acc0 = 0.0f;

                                  
    px = pState;

                                        
    pb = pCoeffs;

    i = numTaps;

                                          
    do
    {
                                                                                                                                  
      acc0 += *px++ * *pb++;

      i--;
    } while (i > 0U);

                                             
    *pDst++ = acc0;

                                                        
    pState = pState + 1U;

                                
    blkCnt--;
  }

                            
                                                                            
                                                                  

                                               
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
   
                     
  
