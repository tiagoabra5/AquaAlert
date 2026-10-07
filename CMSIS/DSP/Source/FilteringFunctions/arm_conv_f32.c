                                                                         
                                  
                               
                                                        
  
                               
                       
  
                                   
                                                                          
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

   
                       
   

   
                            

                                                                                                                               
                                                                                              
                                                                                                      
                                                                       

                          
                                                                                                              
                                                                                  
       
                       
        
      
                                
                                                      
      
                                                                                                                                                                                   
                                                                                                         
                                                                                                       
                                                                                                                                                                
      
                                                                                                        
                                                                              
                                                                                                                      
      
                                                                    
       
                               
        
      
                                                                                                              

                                     
                                                                                           
                                                                                                 
                                                                                                                           

                              
                                                                                                                                                         
                                                                                           

                             
                                                                                                                                
                                                                                                                                   
   

   
                  
    
   

   
                                                         
                                                              
                                                              
                                                               
                                                               
                                                                                                                 
                     
   

void arm_conv_f32(
  const float32_t * pSrcA,
        uint32_t srcALen,
  const float32_t * pSrcB,
        uint32_t srcBLen,
        float32_t * pDst)
{

#if (1)
                                   

  const float32_t *pIn1;                                                   
  const float32_t *pIn2;                                                   
        float32_t *pOut = pDst;                                            
  const float32_t *px;                                                                  
  const float32_t *py;                                                                  
  const float32_t *pSrc1, *pSrc2;                                                 
        float32_t sum;                                                   
        uint32_t blockSize1, blockSize2, blockSize3;                      
        uint32_t j, k, count, blkCnt;                                     

#if defined (ARM_MATH_LOOPUNROLL) || defined(ARM_MATH_NEON)
        float32_t acc0, acc1, acc2, acc3;                                
        float32_t x0, x1, x2, x3, c0;                                                                                
#endif

                                                                           
                                                 
                                                                      
  if (srcALen >= srcBLen)
  {
                                          
    pIn1 = pSrcA;

                                          
    pIn2 = pSrcB;
  }
  else
  {
                                          
    pIn1 = pSrcB;

                                          
    pIn2 = pSrcA;

                                                                     
    j = srcBLen;
    srcBLen = srcALen;
    srcALen = j;
  }

                                                                                              
                               
                                                                                        
                                                                                     
                                                                        
                                                                                      
                                                                             
                            

                                                  
                                                          
  blockSize1 = srcBLen - 1U;
  blockSize2 = srcALen - (srcBLen - 1U);
  blockSize3 = blockSize1;

                               
                              
                                

                      
                                    
         
                                                                                    
     

                                                                             
                                                                       
  count = 1U;

                                 
  px = pIn1;

                                 
  py = pIn2;


                             
                   
                             
#if defined(ARM_MATH_NEON)
    float32x4_t vec1;
    float32x4_t vec2;
    float32x4_t res = vdupq_n_f32(0) ;
    float32x2_t accum = vdup_n_f32(0);
#endif                                 

                                   
  while (blockSize1 > 0U)
  {
                                                      
    sum = 0.0f;

#if defined (ARM_MATH_LOOPUNROLL) || defined(ARM_MATH_NEON)
                                                     
    k = count >> 2U;

#if defined(ARM_MATH_NEON)
    res = vdupq_n_f32(0) ;
    accum = vdup_n_f32(0);

                                        
    k = count >> 2U;

                                                               
                                                                              

    while (k > 0U)
    {
      vec1 = vld1q_f32(px);
      vec2 = vld1q_f32(py-3);
      vec2 = vrev64q_f32(vec2);
      vec2 = vcombine_f32(vget_high_f32(vec2), vget_low_f32(vec2));

      res = vmlaq_f32(res,vec1, vec2);

                              
      px += 4;
      py -= 4; 

                                      
      k--;
    }

    accum = vpadd_f32(vget_low_f32(res), vget_high_f32(res));
    sum += accum[0] + accum[1];

                                                                            
                                     
    k = count & 3;
#else
    while (k > 0U)
    {
                                 
      sum += *px++ * *py--;

                                 
      sum += *px++ * *py--;

                                 
      sum += *px++ * *py--;

                                 
      sum += *px++ * *py--;

                                  
      k--;
    }

                                                   
    k = count % 0x4U;

#endif                                 

#else
                                             
    k = count;

#endif                                                                  

    while (k > 0U)
    {
                                           
      sum += *px++ * *py--;

                                  
      k--;
    }

                                                                        
    *pOut++ = sum;

                                                                        
    py = pIn2 + count;
    px = pIn1;

                             
    count++;

                                
    blockSize1--;
  }

                               
                              
                               

                                                                              
                                                                              
         
                                                                                                    
     

                                 
  px = pIn1;

                                 
  pSrc2 = pIn2 + (srcBLen - 1U);
  py = pSrc2;

                                                                  
  count = 0U;

                        
                   
                         

                                                                                     
                                        
                                                    
  if (srcBLen >= 4U)
  {
   
#if defined(ARM_MATH_NEON)
      float32x4_t c;
      float32x4_t x1v;
      float32x4_t x2v;
      uint32x4_t x1v_u;
      uint32x4_t x2v_u;
      uint32x4_t x_u;
      float32x4_t x;
      float32x4_t res = vdupq_n_f32(0) ;
#endif                                 
   
#if defined (ARM_MATH_LOOPUNROLL) || defined(ARM_MATH_NEON)

                                                     
    blkCnt = blockSize2 >> 2U;

    while (blkCnt > 0U)
    {
                                        
      acc0 = 0.0f;
      acc1 = 0.0f;
      acc2 = 0.0f;
      acc3 = 0.0f;

                                                                    
      k = srcBLen >> 2U;

#if defined(ARM_MATH_NEON)
      res = vdupq_n_f32(0) ;

      x1v = vld1q_f32(px);
      x2v = vld1q_f32(px+4);

      do
      {
        c = vld1q_f32(py-3);

        px += 4;
        x = x1v;
        res = vmlaq_n_f32(res,x,c[3]);

	x = vextq_f32(x1v,x2v,1);

        res = vmlaq_n_f32(res,x,c[2]);

        x = vextq_f32(x1v,x2v,2);

	res = vmlaq_n_f32(res,x,c[1]);

	x = vextq_f32(x1v,x2v,3);

	res = vmlaq_n_f32(res,x,c[0]);

        py -= 4; 

        x1v = x2v ;
        x2v = vld1q_f32(px+4);

      } while (--k);
      
      
                                                                                
                                       
      k = srcBLen & 0x3;

      x1v = vld1q_f32(px);
      px += 4;

      while (k > 0U)
      {
                                        
        c0 = *(py--);

        res = vmlaq_n_f32(res,x1v,c0);

                                                        
        x1v[0] = x1v[1];
        x1v[1] = x1v[2];
        x1v[2] = x1v[3];

        x1v[3] = *(px++);

                                        
        k--;
      }

      acc0 = res[0];
      acc1 = res[1];
      acc2 = res[2];
      acc3 = res[3];

#else
                                         
      x0 = *px++;
      x1 = *px++;
      x2 = *px++;

                                                                                     
                                                                                
      do
      {
                                        
        c0 = *py--;
                              
        x3 = *(px);

                                             
                                            
        acc0 += x0 * c0;
                                            
        acc1 += x1 * c0;
                                            
        acc2 += x2 * c0;
                                            
        acc3 += x3 * c0;

                                        
        c0 = *py--;
                              
        x0 = *(px + 1U);

                                             
                                            
        acc0 += x1 * c0;
                                            
        acc1 += x2 * c0;
                                            
        acc2 += x3 * c0;
                                            
        acc3 += x0 * c0;

                                        
        c0 = *py--;
                              
        x1 = *(px + 2U);

                                             
                                            
        acc0 += x2 * c0;
                                            
        acc1 += x3 * c0;
                                            
        acc2 += x0 * c0;
                                            
        acc3 += x1 * c0;

                                        
        c0 = *py--;
                              
        x2 = *(px + 3U);
        px += 4U;

                                             
                                            
        acc0 += x3 * c0;
                                            
        acc1 += x0 * c0;
                                            
        acc2 += x1 * c0;
                                            
        acc3 += x2 * c0;

      } while (--k);

                                                                                
                                       
      k = srcBLen % 0x4U;

      while (k > 0U)
      {
                                        
        c0 = *py--;
                              
        x3 = *px++;

                                             
                                            
        acc0 += x0 * c0;
                                            
        acc1 += x1 * c0;
                                            
        acc2 += x2 * c0;
                                            
        acc3 += x3 * c0;

                                                        
        x0 = x1;
        x1 = x2;
        x2 = x3;

                                        
        k--;
      }
#endif                                 

                                                                          
      *pOut++ = acc0;
      *pOut++ = acc1;
      *pOut++ = acc2;
      *pOut++ = acc3;

                                                        
      count += 4U;

                                                                          
      px = pIn1 + count;
      py = pSrc2;

                                      
      blkCnt--;
    }

                                                                                           
                                     
    blkCnt = blockSize2 % 0x4U;

#else

                                                  
    blkCnt = blockSize2;

#endif                                                                  

    while (blkCnt > 0U)
    {
                                                        
      sum = 0.0f;

#if defined(ARM_MATH_NEON) || defined (ARM_MATH_LOOPUNROLL)
                                                       
      k = srcBLen >> 2U;

#if defined (ARM_MATH_NEON)
      float32x4_t res = vdupq_n_f32(0) ;
      float32x4_t x = vdupq_n_f32(0) ;
      float32x4_t y = vdupq_n_f32(0) ;
      float32x2_t accum = vdup_n_f32(0) ;

                                                                 
                                                                                
      while (k > 0U)
      {
        x = vld1q_f32(px);
        y = vld1q_f32(py-3);

        y = vrev64q_f32(y);
        y = vcombine_f32(vget_high_f32(y), vget_low_f32(y));

        res = vmlaq_f32(res,x,y);

        px += 4 ;
        py -= 4 ;

                                        
        k--;
      }

      accum = vpadd_f32(vget_low_f32(res), vget_high_f32(res));
      sum += accum[0] + accum[1]; 

                                                                                
                                       
      k = srcBLen & 0x3U;

#else
      while (k > 0U)
      {
                                             
        sum += *px++ * *py--;
        sum += *px++ * *py--;
        sum += *px++ * *py--;
        sum += *px++ * *py--;

                                    
        k--;
      }

                                                     
      k = srcBLen % 0x4U;

#endif                                 
#else
                                                    
      k = srcBLen;

#endif                                                                  

      while (k > 0U)
      {
                                             
        sum += *px++ * *py--;

                                        
        k--;
      }

                                                                          
      *pOut++ = sum;

                                   
      count++;

                                                                          
      px = pIn1 + count;
      py = pSrc2;

                                      
      blkCnt--;
    }
  }
  else
  {
                                             
                                                     
    blkCnt = blockSize2;

    while (blkCnt > 0U)
    {
                                                        
      sum = 0.0f;

                                                      
      k = srcBLen;

      while (k > 0U)
      {
                                             
        sum += *px++ * *py--;

                                        
        k--;
      }

                                                                          
      *pOut++ = sum;

                                   
      count++;

                                                                          
      px = pIn1 + count;
      py = pSrc2;

                                      
      blkCnt--;
    }
  }


                               
                              
                                

                                                                                                               
                                                                                                               
         
                                                                      
                                        
     

                                                                             
                                                                            

                                 
  pSrc1 = pIn1 + (srcALen - (srcBLen - 1U));
  px = pSrc1;

                                 
  pSrc2 = pIn2 + (srcBLen - 1U);
  py = pSrc2;

                        
                   
                         
  while (blockSize3 > 0U)
  {
                                                      
    sum = 0.0f;

#if defined (ARM_MATH_LOOPUNROLL) || defined(ARM_MATH_NEON)
                                                     
    k = blockSize3 >> 2U;

#if defined(ARM_MATH_NEON)
    float32x4_t res = vdupq_n_f32(0) ;
    float32x4_t x = vdupq_n_f32(0) ;
    float32x4_t y = vdupq_n_f32(0) ;
    float32x2_t accum = vdup_n_f32(0) ;

    while (k > 0U)
    {
      x = vld1q_f32(px);
      y = vld1q_f32(py-3);

      y = vrev64q_f32(y);
      y = vcombine_f32(vget_high_f32(y), vget_low_f32(y));

      res = vmlaq_f32(res,x,y);

      px += 4 ;
      py -= 4 ;

                                      
      k--;
    }

    accum = vpadd_f32(vget_low_f32(res), vget_high_f32(res));
    sum += accum[0] + accum[1]; 

#else
    while (k > 0U)
    {
                                           
                                                            
      sum += *px++ * *py--;

                                                            
      sum += *px++ * *py--;

                                                            
      sum += *px++ * *py--;

                                                            
      sum += *px++ * *py--;

                                  
      k--;
    }
#endif                                  

                                                   
    k = blockSize3 % 0x4U;
#else

                                                  
    k = blockSize3;

#endif                                                                  

    while (k > 0U)
    {
                                           
                                               
      sum += *px++ * *py--;

                                  
      k--;
    }

                                                                        
    *pOut++ = sum;

                                                                        
    px = ++pSrc1;
    py = pSrc2;

                                    
    blockSize3--;
  }

#else
                                      

  const float32_t *pIn1 = pSrcA;                                           
  const float32_t *pIn2 = pSrcB;                                           
        float32_t sum;                                                  
        uint32_t i, j;                                                    

                                                                       
  for (i = 0U; i < (srcALen + srcBLen - 1U); i++)
  {
                                                              
    sum = 0.0f;

                                                                          
    for (j = 0U; j <= i; j++)
    {
                                       
      if (((i - j) < srcBLen) && (j < srcALen))
      {
                                   
        sum += ( pIn1[j] * pIn2[i - j]);
      }
    }

                                                    
    pDst[i] = sum;
  }

#endif                                        

}

   
                      
   
