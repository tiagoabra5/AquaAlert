                                                                         
                                  
                                      
                                                                                                
  
                               
                       
  
                                   
                                                                          
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

extern void arm_bitreversal_f32(
        float32_t * pSrc,
        uint16_t fftSize,
        uint16_t bitRevFactor,
  const uint16_t * pBitRevTab);

void arm_radix4_butterfly_f32(
        float32_t * pSrc,
        uint16_t fftLen,
  const float32_t * pCoef,
        uint16_t twidCoefModifier);

void arm_radix4_butterfly_inverse_f32(
        float32_t * pSrc,
        uint16_t fftLen,
  const float32_t * pCoef,
        uint16_t twidCoefModifier,
        float32_t onebyfftLen);


   
                          
   

   
                        
    
   

   
                                                                               
                                                                                                                         
                                                                                              
                                                                                                                 
                     
   

void arm_cfft_radix4_f32(
  const arm_cfft_radix4_instance_f32 * S,
        float32_t * pSrc)
{
   if (S->ifftFlag == 1U)
   {
                                  
      arm_radix4_butterfly_inverse_f32(pSrc, S->fftLen, S->pTwiddle, S->twidCoefModifier, S->onebyfftLen);
   }
   else
   {
                                 
      arm_radix4_butterfly_f32(pSrc, S->fftLen, S->pTwiddle, S->twidCoefModifier);
   }

   if (S->bitReverseFlag == 1U)
   {
                         
      arm_bitreversal_f32(pSrc, S->fftLen, S->bitRevFactor, S->pBitRevTable);
   }

}

   
                            
   

                                                                         
                                            
                                                                            

   
                                                                            
                                                                                          
                                                  
                                                                         
                                                                                                                                  
                    
   

void arm_radix4_butterfly_f32(
        float32_t * pSrc,
        uint16_t fftLen,
  const float32_t * pCoef,
        uint16_t twidCoefModifier)
{
        float32_t co1, co2, co3, si1, si2, si3;
        uint32_t ia1, ia2, ia3;
        uint32_t i0, i1, i2, i3;
        uint32_t n1, n2, j, k;

#if defined (ARM_MATH_LOOPUNROLL)

        float32_t xaIn, yaIn, xbIn, ybIn, xcIn, ycIn, xdIn, ydIn;
        float32_t Xaplusc, Xbplusd, Yaplusc, Ybplusd, Xaminusc, Xbminusd, Yaminusc,
        Ybminusd;
        float32_t Xb12C_out, Yb12C_out, Xc12C_out, Yc12C_out, Xd12C_out, Yd12C_out;
        float32_t Xb12_out, Yb12_out, Xc12_out, Yc12_out, Xd12_out, Yd12_out;
        float32_t *ptr1;
        float32_t p0,p1,p2,p3,p4,p5;
        float32_t a0,a1,a2,a3,a4,a5,a6,a7;

                                             
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

      xaIn = pSrc[(2U * i0)];
      yaIn = pSrc[(2U * i0) + 1U];

      xbIn = pSrc[(2U * i1)];
      ybIn = pSrc[(2U * i1) + 1U];

      xcIn = pSrc[(2U * i2)];
      ycIn = pSrc[(2U * i2) + 1U];

      xdIn = pSrc[(2U * i3)];
      ydIn = pSrc[(2U * i3) + 1U];

                   
      Xaplusc = xaIn + xcIn;
                   
      Xbplusd = xbIn + xdIn;
                   
      Yaplusc = yaIn + ycIn;
                   
      Ybplusd = ybIn + ydIn;

                                                   
      ia2 = ia1 + ia1;
      co2 = pCoef[ia2 * 2U];
      si2 = pCoef[(ia2 * 2U) + 1U];

                   
      Xaminusc = xaIn - xcIn;
                   
      Xbminusd = xbIn - xdIn;
                   
      Yaminusc = yaIn - ycIn;
                   
      Ybminusd = ybIn - ydIn;

                                   
      pSrc[(2U * i0)] = Xaplusc + Xbplusd;
                                   
      pSrc[(2U * i0) + 1U] = Yaplusc + Ybplusd;

                                 
      Xb12C_out = (Xaminusc + Ybminusd);
                                 
      Yb12C_out = (Yaminusc - Xbminusd);
                                 
      Xc12C_out = (Xaplusc - Xbplusd);
                                 
      Yc12C_out = (Yaplusc - Ybplusd);
                                 
      Xd12C_out = (Xaminusc - Ybminusd);
                                 
      Yd12C_out = (Xbminusd + Yaminusc);

      co1 = pCoef[ia1 * 2U];
      si1 = pCoef[(ia1 * 2U) + 1U];

                                                   
      ia3 = ia2 + ia1;
      co3 = pCoef[ia3 * 2U];
      si3 = pCoef[(ia3 * 2U) + 1U];

      Xb12_out = Xb12C_out * co1;
      Yb12_out = Yb12C_out * co1;
      Xc12_out = Xc12C_out * co2;
      Yc12_out = Yc12C_out * co2;
      Xd12_out = Xd12C_out * co3;
      Yd12_out = Yd12C_out * co3;

                                                       
                                    
      p0 = Yb12C_out * si1;
                                                       
                                    
      p1 = Xb12C_out * si1;
                                                       
                                    
      p2 = Yc12C_out * si2;
                                                       
                                    
      p3 = Xc12C_out * si2;
                                                       
                                    
      p4 = Yd12C_out * si3;
                                                       
                                    
      p5 = Xd12C_out * si3;

      Xb12_out += p0;
      Yb12_out -= p1;
      Xc12_out += p2;
      Yc12_out -= p3;
      Xd12_out += p4;
      Yd12_out -= p5;

                                                       
      pSrc[2U * i1] = Xc12_out;

                                                       
      pSrc[(2U * i1) + 1U] = Yc12_out;

                                                       
      pSrc[2U * i2] = Xb12_out;

                                                       
      pSrc[(2U * i2) + 1U] = Yb12_out;

                                                       
      pSrc[2U * i3] = Xd12_out;

                                                       
      pSrc[(2U * i3) + 1U] = Yd12_out;

                                                
      ia1 += twidCoefModifier;

                                 
      i0++;

   }
   while (--j);

   twidCoefModifier <<= 2U;

                                                             
   for (k = fftLen >> 2U; k > 4U; k >>= 2U)
   {
                                                
      n1 = n2;
      n2 >>= 2U;
      ia1 = 0U;

                                       
      j = 0;
      do
      {
                                                      
         ia2 = ia1 + ia1;
         ia3 = ia2 + ia1;
         co1 = pCoef[(ia1 * 2U)];
         si1 = pCoef[(ia1 * 2U) + 1U];
         co2 = pCoef[(ia2 * 2U)];
         si2 = pCoef[(ia2 * 2U) + 1U];
         co3 = pCoef[(ia3 * 2U)];
         si3 = pCoef[(ia3 * 2U) + 1U];

                                                   
         ia1 += twidCoefModifier;

         i0 = j;
         do
         {
                                                      
                                                                                               
            i1 = i0 + n2;
            i2 = i1 + n2;
            i3 = i2 + n2;

            xaIn = pSrc[(2U * i0)];
            yaIn = pSrc[(2U * i0) + 1U];

            xbIn = pSrc[(2U * i1)];
            ybIn = pSrc[(2U * i1) + 1U];

            xcIn = pSrc[(2U * i2)];
            ycIn = pSrc[(2U * i2) + 1U];

            xdIn = pSrc[(2U * i3)];
            ydIn = pSrc[(2U * i3) + 1U];

                         
            Xaminusc = xaIn - xcIn;
                           
            Xbminusd = xbIn - xdIn;
                         
            Yaminusc = yaIn - ycIn;
                           
            Ybminusd = ybIn - ydIn;

                         
            Xaplusc = xaIn + xcIn;
                         
            Xbplusd = xbIn + xdIn;
                         
            Yaplusc = yaIn + ycIn;
                         
            Ybplusd = ybIn + ydIn;

                                       
            Xb12C_out = (Xaminusc + Ybminusd);
                                        
            Yb12C_out = (Yaminusc - Xbminusd);
                                    
            Xc12C_out = (Xaplusc - Xbplusd);
                                       
            Yc12C_out = (Yaplusc - Ybplusd);
                                       
            Xd12C_out = (Xaminusc - Ybminusd);
                                        
            Yd12C_out = (Xbminusd + Yaminusc);

            pSrc[(2U * i0)] = Xaplusc + Xbplusd;
            pSrc[(2U * i0) + 1U] = Yaplusc + Ybplusd;

            Xb12_out = Xb12C_out * co1;
            Yb12_out = Yb12C_out * co1;
            Xc12_out = Xc12C_out * co2;
            Yc12_out = Yc12C_out * co2;
            Xd12_out = Xd12C_out * co3;
            Yd12_out = Yd12C_out * co3;

                                                             
                                          
            p0 = Yb12C_out * si1;
                                                             
                                          
            p1 = Xb12C_out * si1;
                                                             
                                          
            p2 = Yc12C_out * si2;
                                                             
                                          
            p3 = Xc12C_out * si2;
                                                             
                                          
            p4 = Yd12C_out * si3;
                                                             
                                          
            p5 = Xd12C_out * si3;

            Xb12_out += p0;
            Yb12_out -= p1;
            Xc12_out += p2;
            Yc12_out -= p3;
            Xd12_out += p4;
            Yd12_out -= p5;

                                                             
            pSrc[2U * i1] = Xc12_out;

                                                             
            pSrc[(2U * i1) + 1U] = Yc12_out;

                                                             
            pSrc[2U * i2] = Xb12_out;

                                                             
            pSrc[(2U * i2) + 1U] = Yb12_out;

                                                             
            pSrc[2U * i3] = Xd12_out;

                                                             
            pSrc[(2U * i3) + 1U] = Yd12_out;

            i0 += n1;
         } while (i0 < fftLen);
         j++;
      } while (j <= (n2 - 1U));
      twidCoefModifier <<= 2U;
   }

   j = fftLen >> 2;
   ptr1 = &pSrc[0];

                                    
   do
   {
      xaIn = ptr1[0];
      yaIn = ptr1[1];
      xbIn = ptr1[2];
      ybIn = ptr1[3];
      xcIn = ptr1[4];
      ycIn = ptr1[5];
      xdIn = ptr1[6];
      ydIn = ptr1[7];

                   
      Xaplusc = xaIn + xcIn;

                   
      Xaminusc = xaIn - xcIn;

                   
      Yaplusc = yaIn + ycIn;

                   
      Yaminusc = yaIn - ycIn;

                   
      Xbplusd = xbIn + xdIn;

                   
      Ybplusd = ybIn + ydIn;

                   
      Xbminusd = xbIn - xdIn;

                   
      Ybminusd = ybIn - ydIn;

                                   
      a0 = (Xaplusc + Xbplusd);
                                   
      a1 = (Yaplusc + Ybplusd);
                               
      a2 = (Xaplusc - Xbplusd);
                               
      a3 = (Yaplusc - Ybplusd);
                               
      a4 = (Xaminusc + Ybminusd);
                               
      a5 = (Yaminusc - Xbminusd);
                                
      a6 = (Xaminusc - Ybminusd);
                               
      a7 = (Xbminusd + Yaminusc);

      ptr1[0] = a0;
      ptr1[1] = a1;
      ptr1[2] = a2;
      ptr1[3] = a3;
      ptr1[4] = a4;
      ptr1[5] = a5;
      ptr1[6] = a6;
      ptr1[7] = a7;

                                  
      ptr1 += 8U;
   } while (--j);

#else

        float32_t t1, t2, r1, r2, s1, s2;

                                                
   n2 = fftLen;
   n1 = n2;
   for (k = fftLen; k > 1U; k >>= 2U)
   {
                                                    
      n1 = n2;
      n2 >>= 2U;
      ia1 = 0U;

                            
      j = 0;
      do
      {
                                                      
         ia2 = ia1 + ia1;
         ia3 = ia2 + ia1;
         co1 = pCoef[ia1 * 2U];
         si1 = pCoef[(ia1 * 2U) + 1U];
         co2 = pCoef[ia2 * 2U];
         si2 = pCoef[(ia2 * 2U) + 1U];
         co3 = pCoef[ia3 * 2U];
         si3 = pCoef[(ia3 * 2U) + 1U];

                                                   
         ia1 = ia1 + twidCoefModifier;

         i0 = j;
         do
         {
                                                      
                                                                                               
            i1 = i0 + n2;
            i2 = i1 + n2;
            i3 = i2 + n2;

                         
            r1 = pSrc[(2U * i0)] + pSrc[(2U * i2)];

                         
            r2 = pSrc[(2U * i0)] - pSrc[(2U * i2)];

                         
            s1 = pSrc[(2U * i0) + 1U] + pSrc[(2U * i2) + 1U];

                         
            s2 = pSrc[(2U * i0) + 1U] - pSrc[(2U * i2) + 1U];

                         
            t1 = pSrc[2U * i1] + pSrc[2U * i3];

                                         
            pSrc[2U * i0] = r1 + t1;

                                    
            r1 = r1 - t1;

                         
            t2 = pSrc[(2U * i1) + 1U] + pSrc[(2U * i3) + 1U];

                                         
            pSrc[(2U * i0) + 1U] = s1 + t2;

                                       
            s1 = s1 - t2;

                           
            t1 = pSrc[(2U * i1) + 1U] - pSrc[(2U * i3) + 1U];

                           
            t2 = pSrc[2U * i1] - pSrc[2U * i3];

                                                             
            pSrc[2U * i1] = (r1 * co2) + (s1 * si2);

                                                             
            pSrc[(2U * i1) + 1U] = (s1 * co2) - (r1 * si2);

                                       
            r1 = r2 + t1;

                                       
            r2 = r2 - t1;

                                        
            s1 = s2 - t2;

                                        
            s2 = s2 + t2;

                                                             
            pSrc[2U * i2] = (r1 * co1) + (s1 * si1);

                                                             
            pSrc[(2U * i2) + 1U] = (s1 * co1) - (r1 * si1);

                                                             
            pSrc[2U * i3] = (r2 * co3) + (s2 * si3);

                                                             
            pSrc[(2U * i3) + 1U] = (s2 * co3) - (r2 * si3);

            i0 += n1;
         } while ( i0 < fftLen);
         j++;
      } while (j <= (n2 - 1U));
      twidCoefModifier <<= 2U;
   }

#endif                                        

}

   
                                                                             
                                                                                          
                                                  
                                                                     
                                                                                                                                   
                                                  
                    
   

void arm_radix4_butterfly_inverse_f32(
        float32_t * pSrc,
        uint16_t fftLen,
  const float32_t * pCoef,
        uint16_t twidCoefModifier,
        float32_t onebyfftLen)
{
        float32_t co1, co2, co3, si1, si2, si3;
        uint32_t ia1, ia2, ia3;
        uint32_t i0, i1, i2, i3;
        uint32_t n1, n2, j, k;

#if defined (ARM_MATH_LOOPUNROLL)

        float32_t xaIn, yaIn, xbIn, ybIn, xcIn, ycIn, xdIn, ydIn;
        float32_t Xaplusc, Xbplusd, Yaplusc, Ybplusd, Xaminusc, Xbminusd, Yaminusc,
        Ybminusd;
        float32_t Xb12C_out, Yb12C_out, Xc12C_out, Yc12C_out, Xd12C_out, Yd12C_out;
        float32_t Xb12_out, Yb12_out, Xc12_out, Yc12_out, Xd12_out, Yd12_out;
        float32_t *ptr1;
        float32_t p0,p1,p2,p3,p4,p5,p6,p7;
        float32_t a0,a1,a2,a3,a4,a5,a6,a7;


                                             
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

                                     
      xaIn = pSrc[(2U * i0)];
      yaIn = pSrc[(2U * i0) + 1U];

      xcIn = pSrc[(2U * i2)];
      ycIn = pSrc[(2U * i2) + 1U];

      xbIn = pSrc[(2U * i1)];
      ybIn = pSrc[(2U * i1) + 1U];

      xdIn = pSrc[(2U * i3)];
      ydIn = pSrc[(2U * i3) + 1U];

                   
      Xaplusc = xaIn + xcIn;
                   
      Xbplusd = xbIn + xdIn;
                   
      Yaplusc = yaIn + ycIn;
                   
      Ybplusd = ybIn + ydIn;

                                                   
      ia2 = ia1 + ia1;
      co2 = pCoef[ia2 * 2U];
      si2 = pCoef[(ia2 * 2U) + 1U];

                   
      Xaminusc = xaIn - xcIn;
                   
      Xbminusd = xbIn - xdIn;
                   
      Yaminusc = yaIn - ycIn;
                   
      Ybminusd = ybIn - ydIn;

                                   
      pSrc[(2U * i0)] = Xaplusc + Xbplusd;

                                   
      pSrc[(2U * i0) + 1U] = Yaplusc + Ybplusd;

                                 
      Xb12C_out = (Xaminusc - Ybminusd);
                                 
      Yb12C_out = (Yaminusc + Xbminusd);
                                 
      Xc12C_out = (Xaplusc - Xbplusd);
                                 
      Yc12C_out = (Yaplusc - Ybplusd);
                                 
      Xd12C_out = (Xaminusc + Ybminusd);
                                 
      Yd12C_out = (Yaminusc - Xbminusd);

      co1 = pCoef[ia1 * 2U];
      si1 = pCoef[(ia1 * 2U) + 1U];

                                                   
      ia3 = ia2 + ia1;
      co3 = pCoef[ia3 * 2U];
      si3 = pCoef[(ia3 * 2U) + 1U];

      Xb12_out = Xb12C_out * co1;
      Yb12_out = Yb12C_out * co1;
      Xc12_out = Xc12C_out * co2;
      Yc12_out = Yc12C_out * co2;
      Xd12_out = Xd12C_out * co3;
      Yd12_out = Yd12C_out * co3;

                                                       
                                    
      p0 = Yb12C_out * si1;
                                                       
                                    
      p1 = Xb12C_out * si1;
                                                       
                                    
      p2 = Yc12C_out * si2;
                                                       
                                    
      p3 = Xc12C_out * si2;
                                                       
                                    
      p4 = Yd12C_out * si3;
                                                       
                                    
      p5 = Xd12C_out * si3;

      Xb12_out -= p0;
      Yb12_out += p1;
      Xc12_out -= p2;
      Yc12_out += p3;
      Xd12_out -= p4;
      Yd12_out += p5;

                                                       
      pSrc[2U * i1] = Xc12_out;

                                                       
      pSrc[(2U * i1) + 1U] = Yc12_out;

                                                       
      pSrc[2U * i2] = Xb12_out;

                                                       
      pSrc[(2U * i2) + 1U] = Yb12_out;

                                                       
      pSrc[2U * i3] = Xd12_out;

                                                       
      pSrc[(2U * i3) + 1U] = Yd12_out;

                                                
      ia1 = ia1 + twidCoefModifier;

                                 
      i0 = i0 + 1U;

   } while (--j);

   twidCoefModifier <<= 2U;

                                                             
   for (k = fftLen >> 2U; k > 4U; k >>= 2U)
   {
                                                
      n1 = n2;
      n2 >>= 2U;
      ia1 = 0U;

                                       
      j = 0;
      do
      {
                                                      
         ia2 = ia1 + ia1;
         ia3 = ia2 + ia1;
         co1 = pCoef[ia1 * 2U];
         si1 = pCoef[(ia1 * 2U) + 1U];
         co2 = pCoef[ia2 * 2U];
         si2 = pCoef[(ia2 * 2U) + 1U];
         co3 = pCoef[ia3 * 2U];
         si3 = pCoef[(ia3 * 2U) + 1U];

                                                   
         ia1 = ia1 + twidCoefModifier;

         i0 = j;
         do
         {
                                                      
                                                                                               
            i1 = i0 + n2;
            i2 = i1 + n2;
            i3 = i2 + n2;

            xaIn = pSrc[(2U * i0)];
            yaIn = pSrc[(2U * i0) + 1U];

            xbIn = pSrc[(2U * i1)];
            ybIn = pSrc[(2U * i1) + 1U];

            xcIn = pSrc[(2U * i2)];
            ycIn = pSrc[(2U * i2) + 1U];

            xdIn = pSrc[(2U * i3)];
            ydIn = pSrc[(2U * i3) + 1U];

                         
            Xaminusc = xaIn - xcIn;
                           
            Xbminusd = xbIn - xdIn;
                         
            Yaminusc = yaIn - ycIn;
                           
            Ybminusd = ybIn - ydIn;

                         
            Xaplusc = xaIn + xcIn;
                         
            Xbplusd = xbIn + xdIn;
                         
            Yaplusc = yaIn + ycIn;
                         
            Ybplusd = ybIn + ydIn;

                                       
            Xb12C_out = (Xaminusc - Ybminusd);
                                        
            Yb12C_out = (Yaminusc + Xbminusd);
                                    
            Xc12C_out = (Xaplusc - Xbplusd);
                                       
            Yc12C_out = (Yaplusc - Ybplusd);
                                       
            Xd12C_out = (Xaminusc + Ybminusd);
                                        
            Yd12C_out = (Yaminusc - Xbminusd);

            pSrc[(2U * i0)] = Xaplusc + Xbplusd;
            pSrc[(2U * i0) + 1U] = Yaplusc + Ybplusd;

            Xb12_out = Xb12C_out * co1;
            Yb12_out = Yb12C_out * co1;
            Xc12_out = Xc12C_out * co2;
            Yc12_out = Yc12C_out * co2;
            Xd12_out = Xd12C_out * co3;
            Yd12_out = Yd12C_out * co3;

                                                             
                                          
            p0 = Yb12C_out * si1;
                                                             
                                          
            p1 = Xb12C_out * si1;
                                                             
                                          
            p2 = Yc12C_out * si2;
                                                             
                                          
            p3 = Xc12C_out * si2;
                                                             
                                          
            p4 = Yd12C_out * si3;
                                                             
                                          
            p5 = Xd12C_out * si3;

            Xb12_out -= p0;
            Yb12_out += p1;
            Xc12_out -= p2;
            Yc12_out += p3;
            Xd12_out -= p4;
            Yd12_out += p5;

                                                             
            pSrc[2U * i1] = Xc12_out;

                                                             
            pSrc[(2U * i1) + 1U] = Yc12_out;

                                                             
            pSrc[2U * i2] = Xb12_out;

                                                             
            pSrc[(2U * i2) + 1U] = Yb12_out;

                                                             
            pSrc[2U * i3] = Xd12_out;

                                                             
            pSrc[(2U * i3) + 1U] = Yd12_out;

            i0 += n1;
         } while (i0 < fftLen);
         j++;
      } while (j <= (n2 - 1U));
      twidCoefModifier <<= 2U;
   }
                                       

   j = fftLen >> 2;
   ptr1 = &pSrc[0];

                                    
   do
   {
      xaIn = ptr1[0];
      yaIn = ptr1[1];
      xbIn = ptr1[2];
      ybIn = ptr1[3];
      xcIn = ptr1[4];
      ycIn = ptr1[5];
      xdIn = ptr1[6];
      ydIn = ptr1[7];

                                     
                   
      Xaplusc = xaIn + xcIn;

                   
      Xaminusc = xaIn - xcIn;

                   
      Yaplusc = yaIn + ycIn;

                   
      Yaminusc = yaIn - ycIn;

                   
      Xbplusd = xbIn + xdIn;

                   
      Ybplusd = ybIn + ydIn;

                   
      Xbminusd = xbIn - xdIn;

                   
      Ybminusd = ybIn - ydIn;

                                             
      a0 = (Xaplusc + Xbplusd);
                                             
      a1 = (Yaplusc + Ybplusd);
                                             
      a2 = (Xaplusc - Xbplusd);
                                              
      a3 = (Yaplusc - Ybplusd);
                                             
      a4 = (Xaminusc - Ybminusd);
                                             
      a5 = (Yaminusc + Xbminusd);
                                             
      a6 = (Xaminusc + Ybminusd);
                                             
      a7 = (Yaminusc - Xbminusd);

      p0 = a0 * onebyfftLen;
      p1 = a1 * onebyfftLen;
      p2 = a2 * onebyfftLen;
      p3 = a3 * onebyfftLen;
      p4 = a4 * onebyfftLen;
      p5 = a5 * onebyfftLen;
      p6 = a6 * onebyfftLen;
      p7 = a7 * onebyfftLen;

                                             
      ptr1[0] = p0;
                                             
      ptr1[1] = p1;
                                             
      ptr1[2] = p2;
                                              
      ptr1[3] = p3;
                                             
      ptr1[4] = p4;
                                             
      ptr1[5] = p5;
                                             
      ptr1[6] = p6;
                                             
      ptr1[7] = p7;

                                                               
      ptr1 = ptr1 + 8U;

   } while (--j);

#else

        float32_t t1, t2, r1, r2, s1, s2;

                                             
   n2 = fftLen;
   n1 = n2;

                                    
   for (k = fftLen; k > 4U; k >>= 2U)
   {
                                                
      n1 = n2;
      n2 >>= 2U;
      ia1 = 0U;

                                       
      j = 0;
      do
      {
                                                      
         ia2 = ia1 + ia1;
         ia3 = ia2 + ia1;
         co1 = pCoef[ia1 * 2U];
         si1 = pCoef[(ia1 * 2U) + 1U];
         co2 = pCoef[ia2 * 2U];
         si2 = pCoef[(ia2 * 2U) + 1U];
         co3 = pCoef[ia3 * 2U];
         si3 = pCoef[(ia3 * 2U) + 1U];

                                                   
         ia1 = ia1 + twidCoefModifier;

         i0 = j;
         do
         {
                                                      
                                                                                               
            i1 = i0 + n2;
            i2 = i1 + n2;
            i3 = i2 + n2;

                         
            r1 = pSrc[(2U * i0)] + pSrc[(2U * i2)];

                         
            r2 = pSrc[(2U * i0)] - pSrc[(2U * i2)];

                         
            s1 = pSrc[(2U * i0) + 1U] + pSrc[(2U * i2) + 1U];

                         
            s2 = pSrc[(2U * i0) + 1U] - pSrc[(2U * i2) + 1U];

                         
            t1 = pSrc[2U * i1] + pSrc[2U * i3];

                                         
            pSrc[2U * i0] = r1 + t1;

                                    
            r1 = r1 - t1;

                         
            t2 = pSrc[(2U * i1) + 1U] + pSrc[(2U * i3) + 1U];

                                         
            pSrc[(2U * i0) + 1U] = s1 + t2;

                                       
            s1 = s1 - t2;

                           
            t1 = pSrc[(2U * i1) + 1U] - pSrc[(2U * i3) + 1U];

                           
            t2 = pSrc[2U * i1] - pSrc[2U * i3];

                                                             
            pSrc[2U * i1] = (r1 * co2) - (s1 * si2);

                                                             
            pSrc[(2U * i1) + 1U] = (s1 * co2) + (r1 * si2);

                                       
            r1 = r2 - t1;

                                       
            r2 = r2 + t1;

                                        
            s1 = s2 + t2;

                                        
            s2 = s2 - t2;

                                                             
            pSrc[2U * i2] = (r1 * co1) - (s1 * si1);

                                                             
            pSrc[(2U * i2) + 1U] = (s1 * co1) + (r1 * si1);

                                                             
            pSrc[2U * i3] = (r2 * co3) - (s2 * si3);

                                                             
            pSrc[(2U * i3) + 1U] = (s2 * co3) + (r2 * si3);

            i0 += n1;
         } while ( i0 < fftLen);
         j++;
      } while (j <= (n2 - 1U));
      twidCoefModifier <<= 2U;
   }
                                       
   n1 = n2;
   n2 >>= 2U;

                                    
   for (i0 = 0U; i0 <= (fftLen - n1); i0 += n1)
   {
                                                
                                                                                         
      i1 = i0 + n2;
      i2 = i1 + n2;
      i3 = i2 + n2;

                                     
                   
      r1 = pSrc[2U * i0] + pSrc[2U * i2];

                   
      r2 = pSrc[2U * i0] - pSrc[2U * i2];

                   
      s1 = pSrc[(2U * i0) + 1U] + pSrc[(2U * i2) + 1U];

                   
      s2 = pSrc[(2U * i0) + 1U] - pSrc[(2U * i2) + 1U];

                   
      t1 = pSrc[2U * i1] + pSrc[2U * i3];

                                   
      pSrc[2U * i0] = (r1 + t1) * onebyfftLen;

                                 
      r1 = r1 - t1;

                   
      t2 = pSrc[(2U * i1) + 1U] + pSrc[(2U * i3) + 1U];

                                   
      pSrc[(2U * i0) + 1U] = (s1 + t2) * onebyfftLen;

                                 
      s1 = s1 - t2;

                   
      t1 = pSrc[(2U * i1) + 1U] - pSrc[(2U * i3) + 1U];

                   
      t2 = pSrc[2U * i1] - pSrc[2U * i3];

                                                       
      pSrc[2U * i1] = r1 * onebyfftLen;

                                                       
      pSrc[(2U * i1) + 1U] = s1 * onebyfftLen;

                               
      r1 = r2 - t1;

                               
      r2 = r2 + t1;

                               
      s1 = s2 + t2;

                               
      s2 = s2 - t2;

                                                       
      pSrc[2U * i2] = r1 * onebyfftLen;

                                                       
      pSrc[(2U * i2) + 1U] = s1 * onebyfftLen;

                                                       
      pSrc[2U * i3] = r2 * onebyfftLen;

                                                       
      pSrc[(2U * i3) + 1U] = s2 * onebyfftLen;
   }

#endif                                        
}


