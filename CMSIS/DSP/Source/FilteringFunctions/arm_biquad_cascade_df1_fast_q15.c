                                                                         
                                  
                                                  
                                                                           
  
                               
                       
  
                                   
                                                                          
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

   
                       
   

   
                              
    
   

   
                                                                                      
                                                                                    
                                                            
                                                             
                                                                
                     

                                              
                                                                                
                                                                                                                                            
                                                                                                     
                                                                                                                                              
                                                                                                                                                             
        
                                                                                                          
                                                                                                                                                       
                                                                                                              
   

void arm_biquad_cascade_df1_fast_q15(
  const arm_biquad_casd_df1_inst_q15 * S,
  const q15_t * pSrc,
        q15_t * pDst,
        uint32_t blockSize)
{
  const q15_t *pIn = pSrc;                                                 
        q15_t *pOut = pDst;                                                     
        q15_t *pState = S->pState;                                        
  const q15_t *pCoeffs = S->pCoeffs;                                            
        q31_t acc;                                                      
        q31_t in;                                                                                  
        q31_t out;                                                                                  
        q31_t b0;                                                                               
        q31_t b1, a1;                                                           
        q31_t state_in, state_out;                                                 
        int32_t shift = (int32_t) (15 - S->postShift);                 
        uint32_t sample, stage = S->numStages;                            

  do
  {
                                                    
    b0 = read_q15x2_ia ((q15_t **) &pCoeffs);

                                                    
    b1 = read_q15x2_ia ((q15_t **) &pCoeffs);

                                                    
    a1 = read_q15x2_ia ((q15_t **) &pCoeffs);

                                                                            
    state_in = read_q15x2_ia (&pState);

                                                                             
    state_out = read_q15x2_da (&pState);

#if defined (ARM_MATH_LOOPUNROLL)

                                                                          
                                                               
      
                                                                               
                                                                               
       

                                                     
    sample = blockSize >> 1U;

    while (sample > 0U)
    {

                          
      in = read_q15x2_ia ((q15_t **) &pIn);

                                    
      out = __SMUAD(b0, in);
                                                          
      acc = __SMLAD(b1, state_in, out);
                                                     
      acc = __SMLAD(a1, state_out, acc);

                                                                                    
      out = __SSAT((acc >> shift), 16);

                                                                            
                                             
                     
                     
                     
                     
                                                                             
                                                                              

#ifndef  ARM_MATH_BIG_ENDIAN
      state_in  = __PKHBT(in, state_in, 16);
      state_out = __PKHBT(out, state_out, 16);
#else
      state_in  = __PKHBT(state_in >> 16, (in >> 16), 16);
      state_out = __PKHBT(state_out >> 16, (out), 16);
#endif                                   

                                    
      out = __SMUADX(b0, in);
                                                            
      acc = __SMLAD(b1, state_in, out);
                                                     
      acc = __SMLAD(a1, state_out, acc);

                                                                                    
      out = __SSAT((acc >> shift), 16);

                                                       
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

                                                   
    sample = (blockSize & 0x1U);

#else

                                                  
    sample = blockSize;

#endif                                        

    while (sample > 0U)
    {
                          
      in = *pIn++;

                                    
#ifndef  ARM_MATH_BIG_ENDIAN
      out = __SMUAD(b0, in);
#else
      out = __SMUADX(b0, in);
#endif                                   

                                                         
      acc = __SMLAD(b1, state_in, out);
                                                     
      acc = __SMLAD(a1, state_out, acc);

                                                                                    
      out = __SSAT((acc >> shift), 16);

                                                       
      *pOut++ = (q15_t) out;

                                                                            
                                             
                     
                     
                     
                     
                                                                             
                                                                              
#ifndef  ARM_MATH_BIG_ENDIAN
      state_in = __PKHBT(in, state_in, 16);
      state_out = __PKHBT(out, state_out, 16);
#else
      state_in = __PKHBT(state_in >> 16, in, 16);
      state_out = __PKHBT(state_out >> 16, out, 16);
#endif                                   

                                  
      sample--;
    }

                                                                          
                                                                        
    pIn = pDst;

                                  
    pOut = pDst;

                                                                     
    write_q15x2_ia(&pState, state_in);
    write_q15x2_ia(&pState, state_out);

                                
    stage--;

  } while (stage > 0U);
}

   
                                  
   
