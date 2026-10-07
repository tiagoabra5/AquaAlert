                                                                         
                                  
                                      
                                                                                     
                                                               
  
                               
                       
  
                                   
                                                                          
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

void arm_radix4_butterfly_inverse_q31(
        q31_t * pSrc,
        uint32_t fftLen,
  const q31_t * pCoef,
        uint32_t twidCoefModifier);

void arm_radix4_butterfly_q31(
        q31_t * pSrc,
        uint32_t fftLen,
  const q31_t * pCoef,
        uint32_t twidCoefModifier);

void arm_bitreversal_q31(
        q31_t * pSrc,
        uint32_t fftLen,
        uint16_t bitRevFactor,
  const uint16_t * pBitRevTab);

   
                          
   

   
                        
    
   

   
                                                            
                                                                                                                          
                                                                           
                                                                                                                 
                     
 
                                
                                                                                                                    
                                                                              
                                                                                                                                                         
      
                                                                                
                                                                                  
   

void arm_cfft_radix4_q31(
  const arm_cfft_radix4_instance_q31 * S,
        q31_t * pSrc)
{
  if (S->ifftFlag == 1U)
  {
                              
    arm_radix4_butterfly_inverse_q31(pSrc, S->fftLen, S->pTwiddle, S->twidCoefModifier);
  }
  else
  {
                             
    arm_radix4_butterfly_q31(pSrc, S->fftLen, S->pTwiddle, S->twidCoefModifier);
  }

  if (S->bitReverseFlag == 1U)
  {
                       
    arm_bitreversal_q31(pSrc, S->fftLen, S->bitRevFactor, S->pBitRevTable);
  }

}

   
                            
   

  
                                  
  
                                 
                     
                          
                          
                          
  
  
                                  
                       
                         
                         
                         
  
  
                                   
                         
                          
                          
  
                             
                          
                          
                                                  
                                                  
                                                  
                                                  
                                                  
                                                  
  
   

   
                                                                  
                                                                                 
                                                    
                                                                       
                                                                                                                                    
                     
   

void arm_radix4_butterfly_q31(
        q31_t * pSrc,
        uint32_t fftLen,
  const q31_t * pCoef,
        uint32_t twidCoefModifier)
{
        uint32_t n1, n2, ia1, ia2, ia3, i0, i1, i2, i3, j, k;
        q31_t t1, t2, r1, r2, s1, s2, co1, co2, co3, si1, si2, si3;
        
        q31_t xa, xb, xc, xd;
        q31_t ya, yb, yc, yd;
        q31_t xa_out, xb_out, xc_out, xd_out;
        q31_t ya_out, yb_out, yc_out, yd_out;
        
        q31_t *ptr1;

                                                  

                                                        


                                    

                                            
  n2 = fftLen;
  n1 = n2;
                     
  n2 >>= 2U;
  i0 = 0U;
  ia1 = 0U;

  j = n2;

                                   
  do
  {
                                              
                                                                                        
    i1 = i0 + n2;
    i2 = i1 + n2;
    i3 = i2 + n2;

                                                                             

                                   
                 
    r1 = (pSrc[(2U * i0)] >> 4U) + (pSrc[(2U * i2)] >> 4U);
                 
    r2 = (pSrc[(2U * i0)] >> 4U) - (pSrc[(2U * i2)] >> 4U);

                 
    t1 = (pSrc[(2U * i1)] >> 4U) + (pSrc[(2U * i3)] >> 4U);

                 
    s1 = (pSrc[(2U * i0) + 1U] >> 4U) + (pSrc[(2U * i2) + 1U] >> 4U);
                 
    s2 = (pSrc[(2U * i0) + 1U] >> 4U) - (pSrc[(2U * i2) + 1U] >> 4U);

                                 
    pSrc[2U * i0] = (r1 + t1);
                               
    r1 = r1 - t1;
                 
    t2 = (pSrc[(2U * i1) + 1U] >> 4U) + (pSrc[(2U * i3) + 1U] >> 4U);

                                 
    pSrc[(2U * i0) + 1U] = (s1 + t2);

                               
    s1 = s1 - t2;

                 
    t1 = (pSrc[(2U * i1) + 1U] >> 4U) - (pSrc[(2U * i3) + 1U] >> 4U);
                 
    t2 = (pSrc[(2U * i1)] >> 4U) - (pSrc[(2U * i3)] >> 4U);

                                                 
    ia2 = 2U * ia1;
    co2 = pCoef[(ia2 * 2U)];
    si2 = pCoef[(ia2 * 2U) + 1U];

                                                     
    pSrc[2U * i1] = (((int32_t) (((q63_t) r1 * co2) >> 32)) +
                     ((int32_t) (((q63_t) s1 * si2) >> 32))) << 1U;

                                                     
    pSrc[(2U * i1) + 1U] = (((int32_t) (((q63_t) s1 * co2) >> 32)) -
                            ((int32_t) (((q63_t) r1 * si2) >> 32))) << 1U;

                               
    r1 = r2 + t1;
                               
    r2 = r2 - t1;

                               
    s1 = s2 - t2;
                               
    s2 = s2 + t2;

    co1 = pCoef[(ia1 * 2U)];
    si1 = pCoef[(ia1 * 2U) + 1U];

                                                     
    pSrc[2U * i2] = (((int32_t) (((q63_t) r1 * co1) >> 32)) +
                     ((int32_t) (((q63_t) s1 * si1) >> 32))) << 1U;

                                                     
    pSrc[(2U * i2) + 1U] = (((int32_t) (((q63_t) s1 * co1) >> 32)) -
                            ((int32_t) (((q63_t) r1 * si1) >> 32))) << 1U;

                                                 
    ia3 = 3U * ia1;
    co3 = pCoef[(ia3 * 2U)];
    si3 = pCoef[(ia3 * 2U) + 1U];

                                                     
    pSrc[2U * i3] = (((int32_t) (((q63_t) r2 * co3) >> 32)) +
                     ((int32_t) (((q63_t) s2 * si3) >> 32))) << 1U;

                                                     
    pSrc[(2U * i3) + 1U] = (((int32_t) (((q63_t) s2 * co3) >> 32)) -
                            ((int32_t) (((q63_t) r2 * si3) >> 32))) << 1U;

                                              
    ia1 = ia1 + twidCoefModifier;

                               
    i0 = i0 + 1U;

  } while (--j);

                                  

                                   


                                      


                                                                          

  twidCoefModifier <<= 2U;


  for (k = fftLen / 4U; k > 4U; k >>= 2U)
  {
                                              
    n1 = n2;
    n2 >>= 2U;
    ia1 = 0U;

                                     
    for (j = 0U; j <= (n2 - 1U); j++)
    {
                                                   
      ia2 = ia1 + ia1;
      ia3 = ia2 + ia1;
      co1 = pCoef[(ia1 * 2U)];
      si1 = pCoef[(ia1 * 2U) + 1U];
      co2 = pCoef[(ia2 * 2U)];
      si2 = pCoef[(ia2 * 2U) + 1U];
      co3 = pCoef[(ia3 * 2U)];
      si3 = pCoef[(ia3 * 2U) + 1U];
                                                
      ia1 = ia1 + twidCoefModifier;

      for (i0 = j; i0 < fftLen; i0 += n1)
      {
                                                  
                                                                                            
        i1 = i0 + n2;
        i2 = i1 + n2;
        i3 = i2 + n2;

                                       
                     
        r1 = pSrc[2U * i0] + pSrc[2U * i2];
                     
        r2 = pSrc[2U * i0] - pSrc[2U * i2];

                     
        s1 = pSrc[(2U * i0) + 1U] + pSrc[(2U * i2) + 1U];
                     
        s2 = pSrc[(2U * i0) + 1U] - pSrc[(2U * i2) + 1U];

                     
        t1 = pSrc[2U * i1] + pSrc[2U * i3];

                                     
        pSrc[2U * i0] = (r1 + t1) >> 2U;
                                
        r1 = r1 - t1;

                     
        t2 = pSrc[(2U * i1) + 1U] + pSrc[(2U * i3) + 1U];
                                     
        pSrc[(2U * i0) + 1U] = (s1 + t2) >> 2U;

                                   
        s1 = s1 - t2;

                       
        t1 = pSrc[(2U * i1) + 1U] - pSrc[(2U * i3) + 1U];
                       
        t2 = pSrc[2U * i1] - pSrc[2U * i3];

                                                         
        pSrc[2U * i1] = (((int32_t) (((q63_t) r1 * co2) >> 32)) +
                         ((int32_t) (((q63_t) s1 * si2) >> 32))) >> 1U;

                                                         
        pSrc[(2U * i1) + 1U] = (((int32_t) (((q63_t) s1 * co2) >> 32)) -
                                ((int32_t) (((q63_t) r1 * si2) >> 32))) >> 1U;

                                   
        r1 = r2 + t1;
                                   
        r2 = r2 - t1;

                                    
        s1 = s2 - t2;
                                    
        s2 = s2 + t2;

                                                         
        pSrc[2U * i2] = (((int32_t) (((q63_t) r1 * co1) >> 32)) +
                         ((int32_t) (((q63_t) s1 * si1) >> 32))) >> 1U;

                                                         
        pSrc[(2U * i2) + 1U] = (((int32_t) (((q63_t) s1 * co1) >> 32)) -
                                ((int32_t) (((q63_t) r1 * si1) >> 32))) >> 1U;

                                                         
        pSrc[2U * i3] = (((int32_t) (((q63_t) r2 * co3) >> 32)) +
                         ((int32_t) (((q63_t) s2 * si3) >> 32))) >> 1U;

                                                         
        pSrc[(2U * i3) + 1U] = (((int32_t) (((q63_t) s2 * co3) >> 32)) -
                                ((int32_t) (((q63_t) r2 * si3) >> 32))) >> 1U;
      }
    }
    twidCoefModifier <<= 2U;
  }

                                    

                                                                                    
                                                                                  
                                                                                
                                                                                  


                                   
                                           
  j = fftLen >> 2;
  ptr1 = &pSrc[0];

                                   
  do
  {
                                        
    xa = *ptr1++;
    ya = *ptr1++;

                                        
    xb = *ptr1++;
    yb = *ptr1++;

                                        
    xc = *ptr1++;
    yc = *ptr1++;

                                        
    xd = *ptr1++;
    yd = *ptr1++;

                                 
    xa_out = xa + xb + xc + xd;

                                 
    ya_out = ya + yb + yc + yd;

                                      
    ptr1 = ptr1 - 8U;

                             
    *ptr1++ = xa_out;
    *ptr1++ = ya_out;

    xc_out = (xa - xb + xc - xd);
    yc_out = (ya - yb + yc - yd);

                             
    *ptr1++ = xc_out;
    *ptr1++ = yc_out;

    xb_out = (xa + yb - xc - yd);
    yb_out = (ya - xb - yc + xd);

                             
    *ptr1++ = xb_out;
    *ptr1++ = yb_out;

    xd_out = (xa - yb - xc + yd);
    yd_out = (ya + xb - yc - xd);

                             
    *ptr1++ = xd_out;
    *ptr1++ = yd_out;


  } while (--j);

                                                         
                                                       
                                                      
                                                      

                                 

}


   
                                                                   
                                                                                 
                                                    
                                                                       
                                                                                                                                    
                     
   

  
                                   
  
                                                        
                                                                                          
  
  
                                                                   
  
                                 
                     
                          
                          
                          
  
  
                                  
                       
                         
                         
                         
  
  
                                    
                       
                        
                        
 
                                                                     
                          
                          
                                                  
                                                  
                                                  
                                                  
                                                  
                                                  
  
   

void arm_radix4_butterfly_inverse_q31(
        q31_t * pSrc,
        uint32_t fftLen,
  const q31_t * pCoef,
        uint32_t twidCoefModifier)
{
        uint32_t n1, n2, ia1, ia2, ia3, i0, i1, i2, i3, j, k;
        q31_t t1, t2, r1, r2, s1, s2, co1, co2, co3, si1, si2, si3;
        q31_t xa, xb, xc, xd;
        q31_t ya, yb, yc, yd;
        q31_t xa_out, xb_out, xc_out, xd_out;
        q31_t ya_out, yb_out, yc_out, yd_out;
        
        q31_t *ptr1;

                                                      
                                                  
                                                        

                                    

                                           
  n2 = fftLen;
  n1 = n2;
                     
  n2 >>= 2U;
  i0 = 0U;
  ia1 = 0U;

  j = n2;

  do
  {
                                                                             

                                              
                                                                                        
    i1 = i0 + n2;
    i2 = i1 + n2;
    i3 = i2 + n2;

                                   
                 
    r1 = (pSrc[2U * i0] >> 4U) + (pSrc[2U * i2] >> 4U);
                 
    r2 = (pSrc[2U * i0] >> 4U) - (pSrc[2U * i2] >> 4U);

                 
    t1 = (pSrc[2U * i1] >> 4U) + (pSrc[2U * i3] >> 4U);

                 
    s1 = (pSrc[(2U * i0) + 1U] >> 4U) + (pSrc[(2U * i2) + 1U] >> 4U);
                 
    s2 = (pSrc[(2U * i0) + 1U] >> 4U) - (pSrc[(2U * i2) + 1U] >> 4U);

                                 
    pSrc[2U * i0] = (r1 + t1);
                               
    r1 = r1 - t1;
                 
    t2 = (pSrc[(2U * i1) + 1U] >> 4U) + (pSrc[(2U * i3) + 1U] >> 4U);
                                 
    pSrc[(2U * i0) + 1U] = (s1 + t2);

                               
    s1 = s1 - t2;

                 
    t1 = (pSrc[(2U * i1) + 1U] >> 4U) - (pSrc[(2U * i3) + 1U] >> 4U);
                 
    t2 = (pSrc[2U * i1] >> 4U) - (pSrc[2U * i3] >> 4U);

                                                 
    ia2 = 2U * ia1;
    co2 = pCoef[ia2 * 2U];
    si2 = pCoef[(ia2 * 2U) + 1U];

                                                     
    pSrc[2U * i1] = (((int32_t) (((q63_t) r1 * co2) >> 32)) -
                     ((int32_t) (((q63_t) s1 * si2) >> 32))) << 1U;

                                                     
    pSrc[2U * i1 + 1U] = (((int32_t) (((q63_t) s1 * co2) >> 32)) +
                          ((int32_t) (((q63_t) r1 * si2) >> 32))) << 1U;

                               
    r1 = r2 - t1;
                               
    r2 = r2 + t1;

                               
    s1 = s2 + t2;
                               
    s2 = s2 - t2;

    co1 = pCoef[ia1 * 2U];
    si1 = pCoef[(ia1 * 2U) + 1U];

                                                     
    pSrc[2U * i2] = (((int32_t) (((q63_t) r1 * co1) >> 32)) -
                     ((int32_t) (((q63_t) s1 * si1) >> 32))) << 1U;

                                                     
    pSrc[(2U * i2) + 1U] = (((int32_t) (((q63_t) s1 * co1) >> 32)) +
                            ((int32_t) (((q63_t) r1 * si1) >> 32))) << 1U;

                                                 
    ia3 = 3U * ia1;
    co3 = pCoef[ia3 * 2U];
    si3 = pCoef[(ia3 * 2U) + 1U];

                                                     
    pSrc[2U * i3] = (((int32_t) (((q63_t) r2 * co3) >> 32)) -
                     ((int32_t) (((q63_t) s2 * si3) >> 32))) << 1U;

                                                     
    pSrc[(2U * i3) + 1U] = (((int32_t) (((q63_t) s2 * co3) >> 32)) +
                            ((int32_t) (((q63_t) r2 * si3) >> 32))) << 1U;

                                              
    ia1 = ia1 + twidCoefModifier;

                               
    i0 = i0 + 1U;

  } while (--j);

                                   
                                                         


                                      

  twidCoefModifier <<= 2U;

                                                            
  for (k = fftLen / 4U; k > 4U; k >>= 2U)
  {
                                              
    n1 = n2;
    n2 >>= 2U;
    ia1 = 0U;

    for (j = 0; j <= (n2 - 1U); j++)
    {
                                                   
      ia2 = ia1 + ia1;
      ia3 = ia2 + ia1;
      co1 = pCoef[(ia1 * 2U)];
      si1 = pCoef[(ia1 * 2U) + 1U];
      co2 = pCoef[(ia2 * 2U)];
      si2 = pCoef[(ia2 * 2U) + 1U];
      co3 = pCoef[(ia3 * 2U)];
      si3 = pCoef[(ia3 * 2U) + 1U];
                                                
      ia1 = ia1 + twidCoefModifier;

      for (i0 = j; i0 < fftLen; i0 += n1)
      {
                                                  
                                                                                            
        i1 = i0 + n2;
        i2 = i1 + n2;
        i3 = i2 + n2;

                                       
                     
        r1 = pSrc[2U * i0] + pSrc[2U * i2];
                     
        r2 = pSrc[2U * i0] - pSrc[2U * i2];

                     
        s1 = pSrc[(2U * i0) + 1U] + pSrc[(2U * i2) + 1U];
                     
        s2 = pSrc[(2U * i0) + 1U] - pSrc[(2U * i2) + 1U];

                     
        t1 = pSrc[2U * i1] + pSrc[2U * i3];

                                     
        pSrc[2U * i0] = (r1 + t1) >> 2U;
                                
        r1 = r1 - t1;
                     
        t2 = pSrc[(2U * i1) + 1U] + pSrc[(2U * i3) + 1U];
                                     
        pSrc[(2U * i0) + 1U] = (s1 + t2) >> 2U;

                                   
        s1 = s1 - t2;

                       
        t1 = pSrc[(2U * i1) + 1U] - pSrc[(2U * i3) + 1U];
                       
        t2 = pSrc[2U * i1] - pSrc[2U * i3];

                                                         
        pSrc[2U * i1] = (((int32_t) (((q63_t) r1 * co2) >> 32U)) -
                         ((int32_t) (((q63_t) s1 * si2) >> 32U))) >> 1U;

                                                         
        pSrc[(2U * i1) + 1U] = (((int32_t) (((q63_t) s1 * co2) >> 32U)) +
                                ((int32_t) (((q63_t) r1 * si2) >> 32U))) >> 1U;

                                   
        r1 = r2 - t1;
                                   
        r2 = r2 + t1;

                                    
        s1 = s2 + t2;
                                    
        s2 = s2 - t2;

                                                         
        pSrc[2U * i2] = (((int32_t) (((q63_t) r1 * co1) >> 32)) -
                         ((int32_t) (((q63_t) s1 * si1) >> 32))) >> 1U;

                                                         
        pSrc[(2U * i2) + 1U] = (((int32_t) (((q63_t) s1 * co1) >> 32)) +
                                ((int32_t) (((q63_t) r1 * si1) >> 32))) >> 1U;

                                                         
        pSrc[(2U * i3)] = (((int32_t) (((q63_t) r2 * co3) >> 32)) -
                           ((int32_t) (((q63_t) s2 * si3) >> 32))) >> 1U;

                                                         
        pSrc[(2U * i3) + 1U] = (((int32_t) (((q63_t) s2 * co3) >> 32)) +
                                ((int32_t) (((q63_t) r2 * si3) >> 32))) >> 1U;
      }
    }
    twidCoefModifier <<= 2U;
  }

                                    

                                                                                    
                                                                                  
                                                                                
                                                                                  


                                   


                                           
  j = fftLen >> 2;
  ptr1 = &pSrc[0];

                                   
  do
  {
                                        
    xa = *ptr1++;
    ya = *ptr1++;

                                        
    xb = *ptr1++;
    yb = *ptr1++;

                                        
    xc = *ptr1++;
    yc = *ptr1++;

                                        
    xd = *ptr1++;
    yd = *ptr1++;

                                 
    xa_out = xa + xb + xc + xd;

                                 
    ya_out = ya + yb + yc + yd;

                                      
    ptr1 = ptr1 - 8U;

                             
    *ptr1++ = xa_out;
    *ptr1++ = ya_out;

    xc_out = (xa - xb + xc - xd);
    yc_out = (ya - yb + yc - yd);

                             
    *ptr1++ = xc_out;
    *ptr1++ = yc_out;

    xb_out = (xa - yb - xc + yd);
    yb_out = (ya + xb - yc - xd);

                             
    *ptr1++ = xb_out;
    *ptr1++ = yb_out;

    xd_out = (xa + yb - xc - yd);
    yd_out = (ya - xb - yc + xd);

                             
    *ptr1++ = xd_out;
    *ptr1++ = yd_out;

  } while (--j);

                                                         
                                                       
                                                      
                                                      

                                 
}
