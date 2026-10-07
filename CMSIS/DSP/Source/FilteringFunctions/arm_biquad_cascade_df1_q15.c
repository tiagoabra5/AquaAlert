                                                                         
                                  
                                             
                                                                                       
  
                               
                       
  
                                   
                                                                          
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

   
                       
   

   
                              
    
   

   
                                                                       
                                                                                    
                                                            
                                                                                    
                                                       
                     

                                              
                                                                                   
                                                                                                                                
                                                                                                         
                                                                                                                                                
                                                                                                                                                      
                                                                   
         
                                                                                                                               
   

void arm_biquad_cascade_df1_q15(
  const arm_biquad_casd_df1_inst_q15 * S,
  const q15_t * pSrc,
        q15_t * pDst,
        uint32_t blockSize)
{


#if defined (ARM_MATH_DSP)

  const q15_t *pIn = pSrc;                                                 
        q15_t *pOut = pDst;                                                     
        q31_t in;                                                                                  
        q31_t out;                                                                                  
        q31_t b0;                                                                               
        q31_t b1, a1;                                                           
        q31_t state_in, state_out;                                                 
        q31_t acc_l, acc_h;
        q63_t acc;                                                      
        q15_t *pState = S->pState;                                        
  const q15_t *pCoeffs = S->pCoeffs;                                            
        int32_t lShift = (15 - (int32_t) S->postShift);                       
        uint32_t sample, stage = (uint32_t) S->numStages;                             
        int32_t uShift = (32 - lShift);

  do
  {
                                                    
    b0 = read_q15x2_ia ((q15_t **) &pCoeffs);

                                                    
    b1 = read_q15x2_ia ((q15_t **) &pCoeffs);

                                                    
    a1 = read_q15x2_ia ((q15_t **) &pCoeffs);

                                                                            
    state_in = read_q15x2_ia (&pState);

                                                                             
    state_out = read_q15x2_da (&pState);

                                                                          
                                                                        
      
                                                                                  
                                                                                  
       
    sample = blockSize >> 1U;

                                                                                      
                                                               
    while (sample > 0U)
    {

                          
      in = read_q15x2_ia ((q15_t **) &pIn);

                                    
      out = __SMUAD(b0, in);

                                                    
      acc = __SMLALD(b1, state_in, out);
                                              
      acc = __SMLALD(a1, state_out, acc);

                                                                                                      
                                  
      acc_l = acc & 0xffffffff;

                                  
      acc_h = (acc >> 32) & 0xffffffff;

                                                                   
      out = (uint32_t) acc_l >> lShift | acc_h << uShift;

      out = __SSAT(out, 16);

                                                                            
                                             
                     
                     
                     
                     
                                                                             
                                                                              

#ifndef  ARM_MATH_BIG_ENDIAN
      state_in  = __PKHBT(in, state_in, 16);
      state_out = __PKHBT(out, state_out, 16);
#else
      state_in  = __PKHBT(state_in >> 16, (in >> 16), 16);
      state_out = __PKHBT(state_out >> 16, (out), 16);
#endif                                   

                                    
      out = __SMUADX(b0, in);
                                                    
      acc = __SMLALD(b1, state_in, out);
                                             
      acc = __SMLALD(a1, state_out, acc);

                                                                                                      
                                  
      acc_l = acc & 0xffffffff;

                                  
      acc_h = (acc >> 32) & 0xffffffff;

                                                                   
      out = (uint32_t) acc_l >> lShift | acc_h << uShift;

      out = __SSAT(out, 16);

                                                       
#ifndef  ARM_MATH_BIG_ENDIAN
      write_q15x2_ia (&pOut, __PKHBT(state_out, out, 16));
#else
      write_q15x2_ia (&pOut, __PKHBT(out, state_out >> 16, 16));
#endif                                   

                                                                            
                                             
                     
                     
                     
                     
                                                                             
                                                                              
#ifndef  ARM_MATH_BIG_ENDIAN
      state_in  = __PKHBT(in >> 16, state_in, 16);
      state_out = __PKHBT(out, state_out, 16);
#else
      state_in  = __PKHBT(state_in >> 16, in, 16);
      state_out = __PKHBT(state_out >> 16, out, 16);
#endif                                   

                                  
      sample--;
    }

                                                                                          
                                     

    if ((blockSize & 0x1U) != 0U)
    {
                          
      in = *pIn++;

                                    
#ifndef  ARM_MATH_BIG_ENDIAN
      out = __SMUAD(b0, in);
#else
      out = __SMUADX(b0, in);
#endif                                   

                                                  
      acc = __SMLALD(b1, state_in, out);
                                             
      acc = __SMLALD(a1, state_out, acc);

                                                                                                      
                                  
      acc_l = acc & 0xffffffff;

                                  
      acc_h = (acc >> 32) & 0xffffffff;

                                                                   
      out = (uint32_t) acc_l >> lShift | acc_h << uShift;

      out = __SSAT(out, 16);

                                                       
      *pOut++ = (q15_t) out;

                                                                            
                                             
                     
                     
                     
                     
                                                                             
                                                                              
#ifndef  ARM_MATH_BIG_ENDIAN
      state_in = __PKHBT(in, state_in, 16);
      state_out = __PKHBT(out, state_out, 16);
#else
      state_in = __PKHBT(state_in >> 16, in, 16);
      state_out = __PKHBT(state_out >> 16, out, 16);
#endif                                   
    }

                                                                       
                                                                 
    pIn = pDst;

                                  
    pOut = pDst;

                                                                     
    write_q15x2_ia (&pState, state_in);
    write_q15x2_ia (&pState, state_out);

                                
    stage--;

  } while (stage > 0U);

#else

  const q15_t *pIn = pSrc;                                                 
        q15_t *pOut = pDst;                                                     
        q15_t b0, b1, b2, a1, a2;                                               
        q15_t Xn1, Xn2, Yn1, Yn2;                                                  
        q15_t Xn;                                                           
        q63_t acc;                                                      
        int32_t shift = (15 - (int32_t) S->postShift);                 
        q15_t *pState = S->pState;                                        
  const q15_t *pCoeffs = S->pCoeffs;                                            
        uint32_t sample, stage = (uint32_t) S->numStages;                             

  do
  {
                                  
    b0 = *pCoeffs++;
    pCoeffs++;                           
    b1 = *pCoeffs++;
    b2 = *pCoeffs++;
    a1 = *pCoeffs++;
    a2 = *pCoeffs++;

                                  
    Xn1 = pState[0];
    Xn2 = pState[1];
    Yn1 = pState[2];
    Yn2 = pState[3];

                                                                 
                                                                                  
       

    sample = blockSize;

    while (sample > 0U)
    {
                          
      Xn = *pIn++;

                                                                                    
                            
      acc = (q31_t) b0 *Xn;

                               
      acc += (q31_t) b1 *Xn1;
                                 
      acc += (q31_t) b2 *Xn2;
                               
      acc += (q31_t) a1 *Yn1;
                               
      acc += (q31_t) a2 *Yn2;

                                            
      acc = __SSAT((acc >> shift), 16);

                                                                            
                                             
                     
                     
                     
                     
      Xn2 = Xn1;
      Xn1 = Xn;
      Yn2 = Yn1;
      Yn1 = (q15_t) acc;

                                                       
      *pOut++ = (q15_t) acc;

                                      
      sample--;
    }

                                                                           
                                                                
    pIn = pDst;

                                      
    pOut = pDst;

                                                                       
    *pState++ = Xn1;
    *pState++ = Xn2;
    *pState++ = Yn1;
    *pState++ = Yn2;

  } while (--stage);

#endif                                 

}

   
                                  
   
