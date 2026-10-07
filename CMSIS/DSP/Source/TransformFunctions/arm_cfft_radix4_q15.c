                                                                         
                                  
                                      
                                                                                     
                                                               
  
                               
                       
  
                                   
                                                                          
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


void arm_radix4_butterfly_q15(
        q15_t * pSrc16,
        uint32_t fftLen,
  const q15_t * pCoef16,
        uint32_t twidCoefModifier);

void arm_radix4_butterfly_inverse_q15(
        q15_t * pSrc16,
        uint32_t fftLen,
  const q15_t * pCoef16,
        uint32_t twidCoefModifier);

void arm_bitreversal_q15(
        q15_t * pSrc,
        uint32_t fftLen,
        uint16_t bitRevFactor,
  const uint16_t * pBitRevTab);

   
                          
   

   
                        
    
   


   
                                                                  
                                                                                                                                
                                                                             
                                                                                     
                     
 
                                
                                                                                                                    
                                                                              
                                                                                                                                                         
      
                                                                                
                                                                                  
   

void arm_cfft_radix4_q15(
  const arm_cfft_radix4_instance_q15 * S,
        q15_t * pSrc)
{
  if (S->ifftFlag == 1U)
  {
                                
    arm_radix4_butterfly_inverse_q15(pSrc, S->fftLen, S->pTwiddle, S->twidCoefModifier);
  }
  else
  {
                               
    arm_radix4_butterfly_q15(pSrc, S->fftLen, S->pTwiddle, S->twidCoefModifier);
  }

  if (S->bitReverseFlag == 1U)
  {
                       
    arm_bitreversal_q15(pSrc, S->fftLen, S->bitRevFactor, S->pBitRevTable);
  }

}

   
                            
   

  
                                  
  
                                 
                     
                          
                          
                          
  
  
                                  
                       
                         
                         
                         
  
  
                                   
                         
                          
                          
 
                                                                     
                          
                          
                                                  
                                                  
                                                  
                                                  
                                                  
                                                  
  
   

   
                                                                  
                                                                               
                                                   
                                                                     
                                                                                                                                   
                     
   

void arm_radix4_butterfly_q15(
        q15_t * pSrc16,
        uint32_t fftLen,
  const q15_t * pCoef16,
        uint32_t twidCoefModifier)
{

#if defined (ARM_MATH_DSP)

        q31_t R, S, T, U;
        q31_t C1, C2, C3, out1, out2;
        uint32_t n1, n2, ic, i0, j, k;

        q15_t *ptr1;
        q15_t *pSi0;
        q15_t *pSi1;
        q15_t *pSi2;
        q15_t *pSi3;

        q31_t xaya, xbyb, xcyc, xdyd;

                                                  

                                                        

                                            
  n2 = fftLen;
  n1 = n2;

                     
  n2 >>= 2U;

                                     
  ic = 0U;

                                             
  j = n2;

  pSi0 = pSrc16;
  pSi1 = pSi0 + 2 * n2;
  pSi2 = pSi1 + 2 * n2;
  pSi3 = pSi2 + 2 * n2;

                                    

                                     
  do
  {
                                   

                                        
                                        
    T = read_q15x2 (pSi0);
    T = __SHADD16(T, 0);                                                      
    T = __SHADD16(T, 0);                                                                                
  
                                                                                     
                                                 
  

                                        
    S = read_q15x2 (pSi2);
    S = __SHADD16(S, 0);
    S = __SHADD16(S, 0);

                                           
    R = __QADD16(T, S);

                                           
    S = __QSUB16(T, S);

                                                    
                                        
    T = read_q15x2 (pSi1);
    T = __SHADD16(T, 0);
    T = __SHADD16(T, 0);

                                        
    U = read_q15x2 (pSi3);
    U = __SHADD16(U, 0);
    U = __SHADD16(U, 0);

                                           
    T = __QADD16(T, U);

                                                    
                                 
                                 
    write_q15x2_ia (&pSi0, __SHADD16(R, T));

                                                                 
    R = __QSUB16(R, T);

                                                          
    C2 = read_q15x2 ((q15_t *) pCoef16 + (4U * ic));

#ifndef ARM_MATH_BIG_ENDIAN
                                                         
    out1 = __SMUAD(C2, R) >> 16U;
                                                         
    out2 = __SMUSDX(C2, R);
#else
                                                         
    out1 = __SMUSDX(R, C2) >> 16U;
                                                         
    out2 = __SMUAD(C2, R);
#endif                                  

                              
                            
    T = read_q15x2 (pSi1);
    T = __SHADD16(T, 0);
    T = __SHADD16(T, 0);

                                                              
                                                          
    write_q15x2_ia (&pSi1, (q31_t) ((out2) & 0xFFFF0000) | (out1 & 0x0000FFFF));

                                 
                            
    U = read_q15x2 (pSi3);
    U = __SHADD16(U, 0);
    U = __SHADD16(U, 0);

                                  
    T = __QSUB16(T, U);

#ifndef ARM_MATH_BIG_ENDIAN
                                                            
    R = __QASX(S, T);
                                                            
    S = __QSAX(S, T);
#else
                                                            
    R = __QSAX(S, T);
                                                            
    S = __QASX(S, T);
#endif                                  

                                                          
    C1 = read_q15x2 ((q15_t *) pCoef16 + (2U * ic));
                                                       

#ifndef ARM_MATH_BIG_ENDIAN
                                                         
    out1 = __SMUAD(C1, S) >> 16U;
                                                         
    out2 = __SMUSDX(C1, S);
#else
                                                         
    out1 = __SMUSDX(S, C1) >> 16U;
                                                         
    out2 = __SMUAD(C1, S);
#endif                                  

                                                          
    write_q15x2_ia (&pSi2, ((out2) & 0xFFFF0000) | ((out1) & 0x0000FFFF));

                                                          
    C3 = read_q15x2 ((q15_t *) pCoef16 + (6U * ic));
                                                        

#ifndef ARM_MATH_BIG_ENDIAN
                                                         
    out1 = __SMUAD(C3, R) >> 16U;
                                                         
    out2 = __SMUSDX(C3, R);
#else
                                                         
    out1 = __SMUSDX(R, C3) >> 16U;
                                                         
    out2 = __SMUAD(C3, R);
#endif                                  

                                                          
    write_q15x2_ia (&pSi3, ((out2) & 0xFFFF0000) | (out1 & 0x0000FFFF));

                                              
    ic = ic + twidCoefModifier;

  } while (--j);
                                   

                                  


                                     

                                            
  twidCoefModifier <<= 2U;

                                    
  for (k = fftLen / 4U; k > 4U; k >>= 2U)
  {
                                               
    n1 = n2;
    n2 >>= 2U;
    ic = 0U;

    for (j = 0U; j <= (n2 - 1U); j++)
    {
                                                   
      C1 = read_q15x2 ((q15_t *) pCoef16 + (2U * ic));
      C2 = read_q15x2 ((q15_t *) pCoef16 + (4U * ic));
      C3 = read_q15x2 ((q15_t *) pCoef16 + (6U * ic));

                                                
      ic = ic + twidCoefModifier;

      pSi0 = pSrc16 + 2 * j;
      pSi1 = pSi0 + 2 * n2;
      pSi2 = pSi1 + 2 * n2;
      pSi3 = pSi2 + 2 * n2;

                                     
      for (i0 = j; i0 < fftLen; i0 += n1)
      {
                                             
                                            
        T = read_q15x2 (pSi0);

                                            
        S = read_q15x2 (pSi2);

                                               
        R = __QADD16(T, S);

                                              
        S = __QSUB16(T, S);

                                                        
                                            
        T = read_q15x2 (pSi1);

                                            
        U = read_q15x2 (pSi3);

                                               
        T = __QADD16(T, U);

                                                        

                                     
                                     
        out1 = __SHADD16(R, T);
        out1 = __SHADD16(out1, 0);
        write_q15x2 (pSi0, out1);
        pSi0 += 2 * n1;

                                                                       
        R = __SHSUB16(R, T);

#ifndef ARM_MATH_BIG_ENDIAN
                                                       
        out1 = __SMUAD(C2, R) >> 16U;

                                                       
        out2 = __SMUSDX(C2, R);
#else
                                                       
        out1 = __SMUSDX(R, C2) >> 16U;

                                                       
        out2 = __SMUAD(C2, R);
#endif                                  

                                   
                                            
        T = read_q15x2 (pSi1);

                                                                   
                                                             
                                                             
        write_q15x2 (pSi1, ((out2) & 0xFFFF0000) | (out1 & 0x0000FFFF));
        pSi1 += 2 * n1;

                                     

                                            
        U = read_q15x2 (pSi3);

                                      
        T = __QSUB16(T, U);

#ifndef ARM_MATH_BIG_ENDIAN
                                                                
        R = __SHASX(S, T);

                                                                
        S = __SHSAX(S, T);


                                                           
        out1 = __SMUAD(C1, S) >> 16U;
        out2 = __SMUSDX(C1, S);
#else
                                                                
        R = __SHSAX(S, T);

                                                                
        S = __SHASX(S, T);


                                                           
        out1 = __SMUSDX(S, C1) >> 16U;
        out2 = __SMUAD(C1, S);
#endif                                  

                                                             
                                                             
        write_q15x2 (pSi2, ((out2) & 0xFFFF0000) | (out1 & 0x0000FFFF));
        pSi2 += 2 * n1;

                                                            

#ifndef ARM_MATH_BIG_ENDIAN
        out1 = __SMUAD(C3, R) >> 16U;
        out2 = __SMUSDX(C3, R);
#else
        out1 = __SMUSDX(R, C3) >> 16U;
        out2 = __SMUAD(C3, R);
#endif                                  

                                                             
                                                             
        write_q15x2 (pSi3, ((out2) & 0xFFFF0000) | (out1 & 0x0000FFFF));
        pSi3 += 2 * n1;
      }
    }
                                              
    twidCoefModifier <<= 2U;
  }
                                   


                                                     
                                                   
                                                    
                                                    

                                           
  j = fftLen >> 2;

  ptr1 = &pSrc16[0];

                                   

                                 
  do
  {
                                        
    xaya = read_q15x2_ia ((q15_t **) &ptr1);

                                        
    xbyb = read_q15x2_ia ((q15_t **) &ptr1);

                                        
    xcyc = read_q15x2_ia ((q15_t **) &ptr1);

                                        
    xdyd = read_q15x2_ia ((q15_t **) &ptr1);

                                          
    R = __QADD16(xaya, xcyc);

                                          
    T = __QADD16(xbyb, xdyd);

                                      
    ptr1 = ptr1 - 8U;


                                 
                                 
    write_q15x2_ia (&ptr1, __SHADD16(R, T));

                                          
    T = __QADD16(xbyb, xdyd);

                             
                             
    write_q15x2_ia (&ptr1, __SHSUB16(R, T));

                                          
    S = __QSUB16(xaya, xcyc);

                                        
                                            
    U = __QSUB16(xbyb, xdyd);

#ifndef ARM_MATH_BIG_ENDIAN
                             
                             
    write_q15x2_ia (&ptr1, __SHSAX(S, U));

                             
                             
    write_q15x2_ia (&ptr1, __SHASX(S, U));
#else
                             
                             
    write_q15x2_ia (&ptr1, __SHASX(S, U));

                             
                             
    write_q15x2_ia (&ptr1, __SHSAX(S, U));
#endif                                  

  } while (--j);

                                 

                                                       
                                                       
                                                     
                                                       


#else                                 

        q15_t R0, R1, S0, S1, T0, T1, U0, U1;
        q15_t Co1, Si1, Co2, Si2, Co3, Si3, out1, out2;
        uint32_t n1, n2, ic, i0, i1, i2, i3, j, k;

                                                  

                                                        

                                            
  n2 = fftLen;
  n1 = n2;

                     
  n2 >>= 2U;

                                     
  ic = 0U;

                                             
  i0 = 0U;
  j = n2;

                                    

                                     
  do
  {
                                   

                                              
                                                                                               
    i1 = i0 + n2;
    i2 = i1 + n2;
    i3 = i2 + n2;

                                         

                                                    
                                        
    T0 = pSrc16[i0 * 2U] >> 2U;
    T1 = pSrc16[(i0 * 2U) + 1U] >> 2U;

                                                    
                                        
    S0 = pSrc16[i2 * 2U] >> 2U;
    S1 = pSrc16[(i2 * 2U) + 1U] >> 2U;

                        
    R0 = __SSAT(T0 + S0, 16U);
                        
    R1 = __SSAT(T1 + S1, 16U);

                        
    S0 = __SSAT(T0 - S0, 16);
                        
    S1 = __SSAT(T1 - S1, 16);

                                                    
                                                    
                                        
    T0 = pSrc16[i1 * 2U] >> 2U;
    T1 = pSrc16[(i1 * 2U) + 1U] >> 2U;

                                                    
                                        
    U0 = pSrc16[i3 * 2U] >> 2U;
    U1 = pSrc16[(i3 * 2U) + 1] >> 2U;

                        
    T0 = __SSAT(T0 + U0, 16U);
                        
    T1 = __SSAT(T1 + U1, 16U);

                                                    
                                 
                                 
    pSrc16[i0 * 2U] = (R0 >> 1U) + (T0 >> 1U);
    pSrc16[(i0 * 2U) + 1U] = (R1 >> 1U) + (T1 >> 1U);

                                    
                                    
    R0 = __SSAT(R0 - T0, 16U);
    R1 = __SSAT(R1 - T1, 16U);

                                                     
    Co2 = pCoef16[2U * ic * 2U];
    Si2 = pCoef16[(2U * ic * 2U) + 1];

                                                         
    out1 = (q15_t) ((Co2 * R0 + Si2 * R1) >> 16U);
                                                         
    out2 = (q15_t) ((-Si2 * R0 + Co2 * R1) >> 16U);

                              
                                                    
                           
    T0 = pSrc16[i1 * 2U] >> 2;
    T1 = pSrc16[(i1 * 2U) + 1] >> 2;

                                                              
                                                          
    pSrc16[i1 * 2U] = out1;
    pSrc16[(i1 * 2U) + 1] = out2;

                                 
                                                    
                          
    U0 = pSrc16[i3 * 2U] >> 2;
    U1 = pSrc16[(i3 * 2U) + 1] >> 2;
                    
    T0 = __SSAT(T0 - U0, 16);
                    
    T1 = __SSAT(T1 - U1, 16);

                                                           
    R0 = (q15_t) __SSAT((q31_t) (S0 - T1), 16);
    R1 = (q15_t) __SSAT((q31_t) (S1 + T0), 16);

                                                          
    S0 = (q15_t) __SSAT(((q31_t) S0 + T1), 16U);
    S1 = (q15_t) __SSAT(((q31_t) S1 - T0), 16U);

                                                     
    Co1 = pCoef16[ic * 2U];
    Si1 = pCoef16[(ic * 2U) + 1];
                                                       
                                                         
    out1 = (q15_t) ((Si1 * S1 + Co1 * S0) >> 16);
                                                         
    out2 = (q15_t) ((-Si1 * S0 + Co1 * S1) >> 16);

                                                          
    pSrc16[i2 * 2U] = out1;
    pSrc16[(i2 * 2U) + 1] = out2;

                                                     
    Co3 = pCoef16[3U * (ic * 2U)];
    Si3 = pCoef16[(3U * (ic * 2U)) + 1];
                                                        
                                                         
    out1 = (q15_t) ((Si3 * R1 + Co3 * R0) >> 16U);
                                                         
    out2 = (q15_t) ((-Si3 * R0 + Co3 * R1) >> 16U);
                                                          
    pSrc16[i3 * 2U] = out1;
    pSrc16[(i3 * 2U) + 1] = out2;

                                              
    ic = ic + twidCoefModifier;

                               
    i0 = i0 + 1U;

  } while (--j);
                                   

                                  


                                     

                                            
  twidCoefModifier <<= 2U;

                                    
  for (k = fftLen / 4U; k > 4U; k >>= 2U)
  {
                                               
    n1 = n2;
    n2 >>= 2U;
    ic = 0U;

    for (j = 0U; j <= (n2 - 1U); j++)
    {
                                                   
      Co1 = pCoef16[ic * 2U];
      Si1 = pCoef16[(ic * 2U) + 1U];
      Co2 = pCoef16[2U * (ic * 2U)];
      Si2 = pCoef16[(2U * (ic * 2U)) + 1U];
      Co3 = pCoef16[3U * (ic * 2U)];
      Si3 = pCoef16[(3U * (ic * 2U)) + 1U];

                                                
      ic = ic + twidCoefModifier;

                                     
      for (i0 = j; i0 < fftLen; i0 += n1)
      {
                                                  
                                                                                                   
        i1 = i0 + n2;
        i2 = i1 + n2;
        i3 = i2 + n2;

                                             
                                            
        T0 = pSrc16[i0 * 2U];
        T1 = pSrc16[(i0 * 2U) + 1U];

                                            
        S0 = pSrc16[i2 * 2U];
        S1 = pSrc16[(i2 * 2U) + 1U];

                                            
        R0 = __SSAT(T0 + S0, 16);
        R1 = __SSAT(T1 + S1, 16);

                                           
        S0 = __SSAT(T0 - S0, 16);
        S1 = __SSAT(T1 - S1, 16);

                                                        
                                            
        T0 = pSrc16[i1 * 2U];
        T1 = pSrc16[(i1 * 2U) + 1U];

                                            
        U0 = pSrc16[i3 * 2U];
        U1 = pSrc16[(i3 * 2U) + 1U];


                                            
        T0 = __SSAT(T0 + U0, 16);
        T1 = __SSAT(T1 + U1, 16);

                                                        

                                     
                                     
        out1 = ((R0 >> 1U) + (T0 >> 1U)) >> 1U;
        out2 = ((R1 >> 1U) + (T1 >> 1U)) >> 1U;

        pSrc16[i0 * 2U] = out1;
        pSrc16[(2U * i0) + 1U] = out2;

                                                                    
        R0 = (R0 >> 1U) - (T0 >> 1U);
        R1 = (R1 >> 1U) - (T1 >> 1U);

                                                       
        out1 = (q15_t) ((Co2 * R0 + Si2 * R1) >> 16U);

                                                       
        out2 = (q15_t) ((-Si2 * R0 + Co2 * R1) >> 16U);

                                   
                                            
        T0 = pSrc16[i1 * 2U];
        T1 = pSrc16[(i1 * 2U) + 1U];

                                                                   
                                                             
                                                             
        pSrc16[i1 * 2U] = out1;
        pSrc16[(i1 * 2U) + 1U] = out2;

                                     

                                            
        U0 = pSrc16[i3 * 2U];
        U1 = pSrc16[(i3 * 2U) + 1U];

                                    
        T0 = __SSAT(T0 - U0, 16);
        T1 = __SSAT(T1 - U1, 16);

                                                              
        R0 = (S0 >> 1U) - (T1 >> 1U);
        R1 = (S1 >> 1U) + (T0 >> 1U);

                                                              
        S0 = (S0 >> 1U) + (T1 >> 1U);
        S1 = (S1 >> 1U) - (T0 >> 1U);

                                                           
        out1 = (q15_t) ((Co1 * S0 + Si1 * S1) >> 16U);

        out2 = (q15_t) ((-Si1 * S0 + Co1 * S1) >> 16U);

                                                             
                                                             
        pSrc16[i2 * 2U] = out1;
        pSrc16[(i2 * 2U) + 1U] = out2;

                                                            
        out1 = (q15_t) ((Si3 * R1 + Co3 * R0) >> 16U);

        out2 = (q15_t) ((-Si3 * R0 + Co3 * R1) >> 16U);
                                                             
                                                             
        pSrc16[i3 * 2U] = out1;
        pSrc16[(i3 * 2U) + 1U] = out2;
      }
    }
                                              
    twidCoefModifier <<= 2U;
  }
                                   


                                                     
                                                   
                                                    
                                                    

                                           
  n1 = n2;
  n2 >>= 2U;

                                   

                                 
  for (i0 = 0U; i0 <= (fftLen - n1); i0 += n1)
  {
                                              
                                                                                               
    i1 = i0 + n2;
    i2 = i1 + n2;
    i3 = i2 + n2;

                                         
                                        
    T0 = pSrc16[i0 * 2U];
    T1 = pSrc16[(i0 * 2U) + 1U];

                                        
    S0 = pSrc16[i2 * 2U];
    S1 = pSrc16[(i2 * 2U) + 1U];

                                        
    R0 = __SSAT(T0 + S0, 16U);
    R1 = __SSAT(T1 + S1, 16U);

                                        
    S0 = __SSAT(T0 - S0, 16U);
    S1 = __SSAT(T1 - S1, 16U);

                                                    
                                        
    T0 = pSrc16[i1 * 2U];
    T1 = pSrc16[(i1 * 2U) + 1U];
                                        
    U0 = pSrc16[i3 * 2U];
    U1 = pSrc16[(i3 * 2U) + 1U];

                                         
    T0 = __SSAT(T0 + U0, 16U);
    T1 = __SSAT(T1 + U1, 16U);

                                                    
                                 
                                 
    pSrc16[i0 * 2U] = (R0 >> 1U) + (T0 >> 1U);
    pSrc16[(i0 * 2U) + 1U] = (R1 >> 1U) + (T1 >> 1U);

                                                                
    R0 = (R0 >> 1U) - (T0 >> 1U);
    R1 = (R1 >> 1U) - (T1 >> 1U);
                                        
    T0 = pSrc16[i1 * 2U];
    T1 = pSrc16[(i1 * 2U) + 1U];

                                                               
                             
                             
    pSrc16[i1 * 2U] = R0;
    pSrc16[(i1 * 2U) + 1U] = R1;

                                        
    U0 = pSrc16[i3 * 2U];
    U1 = pSrc16[(i3 * 2U) + 1U];
                                         
    T0 = __SSAT(T0 - U0, 16U);
    T1 = __SSAT(T1 - U1, 16U);

                                                               
                             
                             
    pSrc16[i2 * 2U] = (S0 >> 1U) + (T1 >> 1U);
    pSrc16[(i2 * 2U) + 1U] = (S1 >> 1U) - (T0 >> 1U);

                                                                
                             
                             
    pSrc16[i3 * 2U] = (S0 >> 1U) - (T1 >> 1U);
    pSrc16[(i3 * 2U) + 1U] = (S1 >> 1U) + (T0 >> 1U);

  }

                                 

                                                       
                                                       
                                                     
                                                       

#endif                                 

}


   
                                                                   
                                                                                
                                                   
                                                                      
                                                                                                                                    
                     
   

  
                                   
  
                                                        
                                                                                          
  
  
                                                                   
  
                                 
                     
                          
                          
                          
  
  
                                  
                       
                         
                         
                         
  
  
                                    
                       
                        
                        
 
                                                                     
                          
                          
                                                  
                                                  
                                                  
                                                  
                                                  
                                                  
  
   

void arm_radix4_butterfly_inverse_q15(
        q15_t * pSrc16,
        uint32_t fftLen,
  const q15_t * pCoef16,
        uint32_t twidCoefModifier)
{

#if defined (ARM_MATH_DSP)

        q31_t R, S, T, U;
        q31_t C1, C2, C3, out1, out2;
        uint32_t n1, n2, ic, i0, j, k;
        
        q15_t *ptr1;
        q15_t *pSi0;
        q15_t *pSi1;
        q15_t *pSi2;
        q15_t *pSi3;
        
        q31_t xaya, xbyb, xcyc, xdyd;

                                                  

                                                        

                                            
  n2 = fftLen;
  n1 = n2;

                     
  n2 >>= 2U;

                                     
  ic = 0U;

                                             
  j = n2;

  pSi0 = pSrc16;
  pSi1 = pSi0 + 2 * n2;
  pSi2 = pSi1 + 2 * n2;
  pSi3 = pSi2 + 2 * n2;

                                    

                                     
  do
  {
                                   

                                         
                                        
    T = read_q15x2 (pSi0);
    T = __SHADD16(T, 0);
    T = __SHADD16(T, 0);

                                        
    S = read_q15x2 (pSi2);
    S = __SHADD16(S, 0);
    S = __SHADD16(S, 0);

                                           
    R = __QADD16(T, S);

                                           
    S = __QSUB16(T, S);

                                                    
                                        
    T = read_q15x2 (pSi1);
    T = __SHADD16(T, 0);
    T = __SHADD16(T, 0);

                                        
    U = read_q15x2 (pSi3);
    U = __SHADD16(U, 0);
    U = __SHADD16(U, 0);

                                           
    T = __QADD16(T, U);

                                                    
                                 
                                 
    write_q15x2_ia (&pSi0, __SHADD16(R, T));

                                                                 
    R = __QSUB16(R, T);

                                                          
    C2 = read_q15x2 ((q15_t *) pCoef16 + (4U * ic));

#ifndef ARM_MATH_BIG_ENDIAN
                                                         
    out1 = __SMUSD(C2, R) >> 16U;
                                                         
    out2 = __SMUADX(C2, R);
#else
                                                         
    out1 = __SMUADX(C2, R) >> 16U;
                                                         
    out2 = __SMUSD(__QSUB16(0, C2), R);
#endif                                  

                              
                            
    T = read_q15x2 (pSi1);
    T = __SHADD16(T, 0);
    T = __SHADD16(T, 0);

                                                              
                                                          
    write_q15x2_ia (&pSi1, (q31_t) ((out2) & 0xFFFF0000) | (out1 & 0x0000FFFF));

                                 
                            
    U = read_q15x2 (pSi3);
    U = __SHADD16(U, 0);
    U = __SHADD16(U, 0);

                                  
    T = __QSUB16(T, U);

#ifndef ARM_MATH_BIG_ENDIAN
                                                            
    R = __QSAX(S, T);
                                                            
    S = __QASX(S, T);
#else
                                                            
    R = __QASX(S, T);
                                                            
    S = __QSAX(S, T);
#endif                                  

                                                          
    C1 = read_q15x2 ((q15_t *) pCoef16 + (2U * ic));
                                                       

#ifndef ARM_MATH_BIG_ENDIAN
                                                         
    out1 = __SMUSD(C1, S) >> 16U;
                                                         
    out2 = __SMUADX(C1, S);
#else
                                                         
    out1 = __SMUADX(C1, S) >> 16U;
                                                         
    out2 = __SMUSD(__QSUB16(0, C1), S);
#endif                                  

                                                          
    write_q15x2_ia (&pSi2, ((out2) & 0xFFFF0000) | ((out1) & 0x0000FFFF));

                                                          
    C3 = read_q15x2 ((q15_t *) pCoef16 + (6U * ic));
                                                        

#ifndef ARM_MATH_BIG_ENDIAN
                                                         
    out1 = __SMUSD(C3, R) >> 16U;
                                                         
    out2 = __SMUADX(C3, R);
#else
                                                         
    out1 = __SMUADX(C3, R) >> 16U;
                                                         
    out2 = __SMUSD(__QSUB16(0, C3), R);
#endif                                  

                                                          
    write_q15x2_ia (&pSi3, ((out2) & 0xFFFF0000) | (out1 & 0x0000FFFF));

                                              
    ic = ic + twidCoefModifier;

  } while (--j);
                                   

                                  


                                     

                                            
  twidCoefModifier <<= 2U;

                                    
  for (k = fftLen / 4U; k > 4U; k >>= 2U)
  {
                                               
    n1 = n2;
    n2 >>= 2U;
    ic = 0U;

    for (j = 0U; j <= (n2 - 1U); j++)
    {
                                                   
      C1 = read_q15x2 ((q15_t *) pCoef16 + (2U * ic));
      C2 = read_q15x2 ((q15_t *) pCoef16 + (4U * ic));
      C3 = read_q15x2 ((q15_t *) pCoef16 + (6U * ic));

                                                
      ic = ic + twidCoefModifier;

      pSi0 = pSrc16 + 2 * j;
      pSi1 = pSi0 + 2 * n2;
      pSi2 = pSi1 + 2 * n2;
      pSi3 = pSi2 + 2 * n2;

                                     
      for (i0 = j; i0 < fftLen; i0 += n1)
      {
                                             
                                            
        T = read_q15x2 (pSi0);

                                            
        S = read_q15x2 (pSi2);

                                               
        R = __QADD16(T, S);

                                              
        S = __QSUB16(T, S);

                                                        
                                            
        T = read_q15x2 (pSi1);

                                            
        U = read_q15x2 (pSi3);

                                               
        T = __QADD16(T, U);

                                                        

                                     
                                     
        out1 = __SHADD16(R, T);
        out1 = __SHADD16(out1, 0);
        write_q15x2 (pSi0, out1);
        pSi0 += 2 * n1;

                                                                       
        R = __SHSUB16(R, T);

#ifndef ARM_MATH_BIG_ENDIAN
                                                       
        out1 = __SMUSD(C2, R) >> 16U;

                                                       
        out2 = __SMUADX(C2, R);
#else
                                                       
        out1 = __SMUADX(R, C2) >> 16U;

                                                       
        out2 = __SMUSD(__QSUB16(0, C2), R);
#endif                                  

                                   
                                            
        T = read_q15x2 (pSi1);

                                                                   
                                                             
                                                             
        write_q15x2 (pSi1, ((out2) & 0xFFFF0000) | (out1 & 0x0000FFFF));
        pSi1 += 2 * n1;

                                     

                                            
        U = read_q15x2 (pSi3);

                                      
        T = __QSUB16(T, U);

#ifndef ARM_MATH_BIG_ENDIAN
                                                                
        R = __SHSAX(S, T);

                                                                
        S = __SHASX(S, T);

                                                           
        out1 = __SMUSD(C1, S) >> 16U;
        out2 = __SMUADX(C1, S);
#else
                                                                
        R = __SHASX(S, T);

                                                                
        S = __SHSAX(S, T);

                                                           
        out1 = __SMUADX(S, C1) >> 16U;
        out2 = __SMUSD(__QSUB16(0, C1), S);
#endif                                  

                                                             
                                                             
        write_q15x2 (pSi2, ((out2) & 0xFFFF0000) | (out1 & 0x0000FFFF));
        pSi2 += 2 * n1;

                                                            

#ifndef ARM_MATH_BIG_ENDIAN
        out1 = __SMUSD(C3, R) >> 16U;
        out2 = __SMUADX(C3, R);
#else
        out1 = __SMUADX(C3, R) >> 16U;
        out2 = __SMUSD(__QSUB16(0, C3), R);
#endif                                  

                                                             
                                                             
        write_q15x2 (pSi3, ((out2) & 0xFFFF0000) | (out1 & 0x0000FFFF));
        pSi3 += 2 * n1;
      }
    }
                                              
    twidCoefModifier <<= 2U;
  }
                                   

                                                     
                                                   
                                                    
                                                    

                                           
  j = fftLen >> 2;

  ptr1 = &pSrc16[0];

                                   

                                 
  do
  {
                                        
    xaya = read_q15x2_ia ((q15_t **) &ptr1);

                                        
    xbyb = read_q15x2_ia ((q15_t **) &ptr1);

                                        
    xcyc = read_q15x2_ia ((q15_t **) &ptr1);

                                        
    xdyd = read_q15x2_ia ((q15_t **) &ptr1);

                                          
    R = __QADD16(xaya, xcyc);

                                          
    T = __QADD16(xbyb, xdyd);

                                      
    ptr1 = ptr1 - 8U;


                                 
                                 
    write_q15x2_ia (&ptr1, __SHADD16(R, T));

                                          
    T = __QADD16(xbyb, xdyd);

                             
                             
    write_q15x2_ia (&ptr1, __SHSUB16(R, T));

                                          
    S = __QSUB16(xaya, xcyc);

                                        
                                            
    U = __QSUB16(xbyb, xdyd);

#ifndef ARM_MATH_BIG_ENDIAN
                             
                             
    write_q15x2_ia (&ptr1, __SHASX(S, U));

                             
                             
    write_q15x2_ia (&ptr1, __SHSAX(S, U));
#else
                             
                             
    write_q15x2_ia (&ptr1, __SHSAX(S, U));

                             
                             
    write_q15x2_ia (&ptr1, __SHASX(S, U));
#endif                                  

  } while (--j);

                                  

                                                       
                                                       
                                                     
                                                       


#else                                       

        q15_t R0, R1, S0, S1, T0, T1, U0, U1;
        q15_t Co1, Si1, Co2, Si2, Co3, Si3, out1, out2;
        uint32_t n1, n2, ic, i0, i1, i2, i3, j, k;

                                                  

                                                        

                                            
  n2 = fftLen;
  n1 = n2;

                     
  n2 >>= 2U;

                                     
  ic = 0U;

                                             
  i0 = 0U;

  j = n2;

                                    

                                     
  do
  {
                                   

                                              
                                                                                               
    i1 = i0 + n2;
    i2 = i1 + n2;
    i3 = i2 + n2;

                                         
                                                    
                                        
    T0 = pSrc16[i0 * 2U] >> 2U;
    T1 = pSrc16[(i0 * 2U) + 1U] >> 2U;
                                                    
                                        
    S0 = pSrc16[i2 * 2U] >> 2U;
    S1 = pSrc16[(i2 * 2U) + 1U] >> 2U;

                                        
    R0 = __SSAT(T0 + S0, 16U);
    R1 = __SSAT(T1 + S1, 16U);
                                        
    S0 = __SSAT(T0 - S0, 16U);
    S1 = __SSAT(T1 - S1, 16U);

                                                    
                                                    
                                        
    T0 = pSrc16[i1 * 2U] >> 2U;
    T1 = pSrc16[(i1 * 2U) + 1U] >> 2U;
                                        
                                                    
    U0 = pSrc16[i3 * 2U] >> 2U;
    U1 = pSrc16[(i3 * 2U) + 1U] >> 2U;

                                        
    T0 = __SSAT(T0 + U0, 16U);
    T1 = __SSAT(T1 + U1, 16U);

                                                    
                                 
                                 
    pSrc16[i0 * 2U] = (R0 >> 1U) + (T0 >> 1U);
    pSrc16[(i0 * 2U) + 1U] = (R1 >> 1U) + (T1 >> 1U);

                                                               
    R0 = __SSAT(R0 - T0, 16U);
    R1 = __SSAT(R1 - T1, 16U);
                                                     
    Co2 = pCoef16[2U * ic * 2U];
    Si2 = pCoef16[(2U * ic * 2U) + 1U];
                                                         
    out1 = (q15_t) ((Co2 * R0 - Si2 * R1) >> 16U);
                                                         
    out2 = (q15_t) ((Si2 * R0 + Co2 * R1) >> 16U);

                              
                                                    
                          
    T0 = pSrc16[i1 * 2U] >> 2U;
    T1 = pSrc16[(i1 * 2U) + 1U] >> 2U;

                                                              
                                                          
    pSrc16[i1 * 2U] = out1;
    pSrc16[(i1 * 2U) + 1U] = out2;

                                 
                                                    
                           
    U0 = pSrc16[i3 * 2U] >> 2U;
    U1 = pSrc16[(i3 * 2U) + 1U] >> 2U;

                                 
    T0 = __SSAT(T0 - U0, 16U);
    T1 = __SSAT(T1 - U1, 16U);
                                                          
    R0 = (q15_t) __SSAT((q31_t) (S0 + T1), 16);
    R1 = (q15_t) __SSAT((q31_t) (S1 - T0), 16);
                                                        
    S0 = (q15_t) __SSAT((q31_t) (S0 - T1), 16);
    S1 = (q15_t) __SSAT((q31_t) (S1 + T0), 16);

                                                     
    Co1 = pCoef16[ic * 2U];
    Si1 = pCoef16[(ic * 2U) + 1U];
                                                       
                                                         
    out1 = (q15_t) ((Co1 * S0 - Si1 * S1) >> 16U);
                                                         
    out2 = (q15_t) ((Si1 * S0 + Co1 * S1) >> 16U);
                                                          
    pSrc16[i2 * 2U] = out1;
    pSrc16[(i2 * 2U) + 1U] = out2;

                                                     
    Co3 = pCoef16[3U * ic * 2U];
    Si3 = pCoef16[(3U * ic * 2U) + 1U];
                                                        
                                                         
    out1 = (q15_t) ((Co3 * R0 - Si3 * R1) >> 16U);
                                                         
    out2 = (q15_t) ((Si3 * R0 + Co3 * R1) >> 16U);
                                                          
    pSrc16[i3 * 2U] = out1;
    pSrc16[(i3 * 2U) + 1U] = out2;

                                              
    ic = ic + twidCoefModifier;

                               
    i0 = i0 + 1U;

  } while (--j);

                                   

                                   


                                      

                                            
  twidCoefModifier <<= 2U;

                                    
  for (k = fftLen / 4U; k > 4U; k >>= 2U)
  {
                                               
    n1 = n2;
    n2 >>= 2U;
    ic = 0U;

    for (j = 0U; j <= (n2 - 1U); j++)
    {
                                                   
      Co1 = pCoef16[ic * 2U];
      Si1 = pCoef16[(ic * 2U) + 1U];
      Co2 = pCoef16[2U * ic * 2U];
      Si2 = pCoef16[2U * ic * 2U + 1U];
      Co3 = pCoef16[3U * ic * 2U];
      Si3 = pCoef16[(3U * ic * 2U) + 1U];

                                                
      ic = ic + twidCoefModifier;

                                     
      for (i0 = j; i0 < fftLen; i0 += n1)
      {
                                                  
                                                                                                   
        i1 = i0 + n2;
        i2 = i1 + n2;
        i3 = i2 + n2;

                                             
                                            
        T0 = pSrc16[i0 * 2U];
        T1 = pSrc16[(i0 * 2U) + 1U];

                                            
        S0 = pSrc16[i2 * 2U];
        S1 = pSrc16[(i2 * 2U) + 1U];


                                            
        R0 = __SSAT(T0 + S0, 16U);
        R1 = __SSAT(T1 + S1, 16U);
                                            
        S0 = __SSAT(T0 - S0, 16U);
        S1 = __SSAT(T1 - S1, 16U);

                                                        
                                            
        T0 = pSrc16[i1 * 2U];
        T1 = pSrc16[(i1 * 2U) + 1U];

                                            
        U0 = pSrc16[i3 * 2U];
        U1 = pSrc16[(i3 * 2U) + 1U];

                                            
        T0 = __SSAT(T0 + U0, 16U);
        T1 = __SSAT(T1 + U1, 16U);

                                                        
                                     
                                     
        pSrc16[i0 * 2U] = ((R0 >> 1U) + (T0 >> 1U)) >> 1U;
        pSrc16[(i0 * 2U) + 1U] = ((R1 >> 1U) + (T1 >> 1U)) >> 1U;

                                                                    
        R0 = (R0 >> 1U) - (T0 >> 1U);
        R1 = (R1 >> 1U) - (T1 >> 1U);

                                                       
        out1 = (q15_t) ((Co2 * R0 - Si2 * R1) >> 16);
                                                       
        out2 = (q15_t) ((Si2 * R0 + Co2 * R1) >> 16);

                                   
                                            
        T0 = pSrc16[i1 * 2U];
        T1 = pSrc16[(i1 * 2U) + 1U];

                                                                   
                                                             
                                                             
        pSrc16[i1 * 2U] = out1;
        pSrc16[(i1 * 2U) + 1U] = out2;

                                     
                                            
        U0 = pSrc16[i3 * 2U];
        U1 = pSrc16[(i3 * 2U) + 1U];

                                     
        T0 = __SSAT(T0 - U0, 16U);
        T1 = __SSAT(T1 - U1, 16U);

                                                              
        R0 = (S0 >> 1U) + (T1 >> 1U);
        R1 = (S1 >> 1U) - (T0 >> 1U);

                                                             
        S0 = (S0 >> 1U) - (T1 >> 1U);
        S1 = (S1 >> 1U) + (T0 >> 1U);

                                                           
        out1 = (q15_t) ((Co1 * S0 - Si1 * S1) >> 16U);
        out2 = (q15_t) ((Si1 * S0 + Co1 * S1) >> 16U);
                                                             
                                                             
        pSrc16[i2 * 2U] = out1;
        pSrc16[(i2 * 2U) + 1U] = out2;

                                                            
        out1 = (q15_t) ((Co3 * R0 - Si3 * R1) >> 16U);

        out2 = (q15_t) ((Si3 * R0 + Co3 * R1) >> 16U);
                                                             
                                                             
        pSrc16[i3 * 2U] = out1;
        pSrc16[(i3 * 2U) + 1U] = out2;


      }
    }
                                              
    twidCoefModifier <<= 2U;
  }
                                     


                                                     
                                                     
                                                     
                                                     

                                   


                                           
  n1 = n2;
  n2 >>= 2U;

                                 
  for (i0 = 0U; i0 <= (fftLen - n1); i0 += n1)
  {
                                              
                                                                                               
    i1 = i0 + n2;
    i2 = i1 + n2;
    i3 = i2 + n2;

                                         
                                        
    T0 = pSrc16[i0 * 2U];
    T1 = pSrc16[(i0 * 2U) + 1U];
                                        
    S0 = pSrc16[i2 * 2U];
    S1 = pSrc16[(i2 * 2U) + 1U];

                                        
    R0 = __SSAT(T0 + S0, 16U);
    R1 = __SSAT(T1 + S1, 16U);
                                        
    S0 = __SSAT(T0 - S0, 16U);
    S1 = __SSAT(T1 - S1, 16U);

                                                    
                                        
    T0 = pSrc16[i1 * 2U];
    T1 = pSrc16[(i1 * 2U) + 1U];
                                        
    U0 = pSrc16[i3 * 2U];
    U1 = pSrc16[(i3 * 2U) + 1U];

                                        
    T0 = __SSAT(T0 + U0, 16U);
    T1 = __SSAT(T1 + U1, 16U);

                                                    
                                 
                                 
    pSrc16[i0 * 2U] = (R0 >> 1U) + (T0 >> 1U);
    pSrc16[(i0 * 2U) + 1U] = (R1 >> 1U) + (T1 >> 1U);

                                                                
    R0 = (R0 >> 1U) - (T0 >> 1U);
    R1 = (R1 >> 1U) - (T1 >> 1U);

                                        
    T0 = pSrc16[i1 * 2U];
    T1 = pSrc16[(i1 * 2U) + 1U];

                                                               
                             
                             
    pSrc16[i1 * 2U] = R0;
    pSrc16[(i1 * 2U) + 1U] = R1;

                                        
    U0 = pSrc16[i3 * 2U];
    U1 = pSrc16[(i3 * 2U) + 1U];
                                        
    T0 = __SSAT(T0 - U0, 16U);
    T1 = __SSAT(T1 - U1, 16U);

                                                               
                             
                             
    pSrc16[i2 * 2U] = (S0 >> 1U) - (T1 >> 1U);
    pSrc16[(i2 * 2U) + 1U] = (S1 >> 1U) + (T0 >> 1U);


                                                                
                             
                             
    pSrc16[i3 * 2U] = (S0 >> 1U) + (T1 >> 1U);
    pSrc16[(i3 * 2U) + 1U] = (S1 >> 1U) - (T0 >> 1U);
  }
                                  

                                                       
                                                       
                                                     
                                                       

#endif                                 

}
