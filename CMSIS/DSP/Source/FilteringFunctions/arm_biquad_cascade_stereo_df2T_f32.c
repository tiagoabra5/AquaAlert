                                                                         
                                  
                                                     
                                                                                                                   
  
                               
                       
  
                                   
                                                                          
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

   
                       
  

   
                               
    
   

   
                                                                                                            
                                                                             
                                                            
                                                             
                                                       
                     
   

LOW_OPTIMIZATION_ENTER
void arm_biquad_cascade_stereo_df2T_f32(
  const arm_biquad_cascade_stereo_df2T_instance_f32 * S,
  const float32_t * pSrc,
        float32_t * pDst,
        uint32_t blockSize)
{
  const float32_t *pIn = pSrc;                                             
        float32_t *pOut = pDst;                                                 
        float32_t *pState = S->pState;                                    
  const float32_t *pCoeffs = S->pCoeffs;                                        
        float32_t acc1a, acc1b;                                         
        float32_t b0, b1, b2, a1, a2;                                           
        float32_t Xn1a, Xn1b;                                               
        float32_t d1a, d2a, d1b, d2b;                                       
        uint32_t sample, stage = S->numStages;                            

    do
    {
                                      
        b0 = pCoeffs[0];
        b1 = pCoeffs[1];
        b2 = pCoeffs[2];
        a1 = pCoeffs[3];
        a2 = pCoeffs[4];

                                      
        d1a = pState[0];
        d2a = pState[1];
        d1b = pState[2];
        d2b = pState[3];

        pCoeffs += 5U;

#if defined (ARM_MATH_LOOPUNROLL)

                                                     
        sample = blockSize >> 3U;

        while (sample > 0U) {
                                     
                                               
                                          

        
          Xn1a = *pIn++;                
          Xn1b = *pIn++;                

          acc1a = (b0 * Xn1a) + d1a;
          acc1b = (b0 * Xn1b) + d1b;

          *pOut++ = acc1a;
          *pOut++ = acc1b;

          d1a = ((b1 * Xn1a) + (a1 * acc1a)) + d2a;
          d1b = ((b1 * Xn1b) + (a1 * acc1b)) + d2b;

          d2a = (b2 * Xn1a) + (a2 * acc1a);
          d2b = (b2 * Xn1b) + (a2 * acc1b);

        
          Xn1a = *pIn++;                
          Xn1b = *pIn++;                

          acc1a = (b0 * Xn1a) + d1a;
          acc1b = (b0 * Xn1b) + d1b;

          *pOut++ = acc1a;
          *pOut++ = acc1b;

          d1a = ((b1 * Xn1a) + (a1 * acc1a)) + d2a;
          d1b = ((b1 * Xn1b) + (a1 * acc1b)) + d2b;

          d2a = (b2 * Xn1a) + (a2 * acc1a);
          d2b = (b2 * Xn1b) + (a2 * acc1b);

        
          Xn1a = *pIn++;                
          Xn1b = *pIn++;                

          acc1a = (b0 * Xn1a) + d1a;
          acc1b = (b0 * Xn1b) + d1b;

          *pOut++ = acc1a;
          *pOut++ = acc1b;

          d1a = ((b1 * Xn1a) + (a1 * acc1a)) + d2a;
          d1b = ((b1 * Xn1b) + (a1 * acc1b)) + d2b;

          d2a = (b2 * Xn1a) + (a2 * acc1a);
          d2b = (b2 * Xn1b) + (a2 * acc1b);

        
          Xn1a = *pIn++;                
          Xn1b = *pIn++;                

          acc1a = (b0 * Xn1a) + d1a;
          acc1b = (b0 * Xn1b) + d1b;

          *pOut++ = acc1a;
          *pOut++ = acc1b;

          d1a = ((b1 * Xn1a) + (a1 * acc1a)) + d2a;
          d1b = ((b1 * Xn1b) + (a1 * acc1b)) + d2b;

          d2a = (b2 * Xn1a) + (a2 * acc1a);
          d2b = (b2 * Xn1b) + (a2 * acc1b);

        
          Xn1a = *pIn++;                
          Xn1b = *pIn++;                

          acc1a = (b0 * Xn1a) + d1a;
          acc1b = (b0 * Xn1b) + d1b;

          *pOut++ = acc1a;
          *pOut++ = acc1b;

          d1a = ((b1 * Xn1a) + (a1 * acc1a)) + d2a;
          d1b = ((b1 * Xn1b) + (a1 * acc1b)) + d2b;

          d2a = (b2 * Xn1a) + (a2 * acc1a);
          d2b = (b2 * Xn1b) + (a2 * acc1b);

        
          Xn1a = *pIn++;                
          Xn1b = *pIn++;                

          acc1a = (b0 * Xn1a) + d1a;
          acc1b = (b0 * Xn1b) + d1b;

          *pOut++ = acc1a;
          *pOut++ = acc1b;

          d1a = ((b1 * Xn1a) + (a1 * acc1a)) + d2a;
          d1b = ((b1 * Xn1b) + (a1 * acc1b)) + d2b;

          d2a = (b2 * Xn1a) + (a2 * acc1a);
          d2b = (b2 * Xn1b) + (a2 * acc1b);

        
          Xn1a = *pIn++;                
          Xn1b = *pIn++;                

          acc1a = (b0 * Xn1a) + d1a;
          acc1b = (b0 * Xn1b) + d1b;

          *pOut++ = acc1a;
          *pOut++ = acc1b;

          d1a = ((b1 * Xn1a) + (a1 * acc1a)) + d2a;
          d1b = ((b1 * Xn1b) + (a1 * acc1b)) + d2b;

          d2a = (b2 * Xn1a) + (a2 * acc1a);
          d2b = (b2 * Xn1b) + (a2 * acc1b);

        
          Xn1a = *pIn++;                
          Xn1b = *pIn++;                

          acc1a = (b0 * Xn1a) + d1a;
          acc1b = (b0 * Xn1b) + d1b;

          *pOut++ = acc1a;
          *pOut++ = acc1b;

          d1a = ((b1 * Xn1a) + (a1 * acc1a)) + d2a;
          d1b = ((b1 * Xn1b) + (a1 * acc1b)) + d2b;

          d2a = (b2 * Xn1a) + (a2 * acc1a);
          d2b = (b2 * Xn1b) + (a2 * acc1b);

                                      
          sample--;
        }

                                                       
        sample = blockSize & 0x7U;

#else

                                                      
        sample = blockSize;

#endif                                        

        while (sample > 0U) {
                              
          Xn1a = *pIn++;                
          Xn1b = *pIn++;                

                                     
          acc1a = (b0 * Xn1a) + d1a;
          acc1b = (b0 * Xn1b) + d1b;

                                                                              
          *pOut++ = acc1a;
          *pOut++ = acc1b;

                                                                                
                                               
          d1a = ((b1 * Xn1a) + (a1 * acc1a)) + d2a;
          d1b = ((b1 * Xn1b) + (a1 * acc1b)) + d2b;

                                          
          d2a = (b2 * Xn1a) + (a2 * acc1a);
          d2b = (b2 * Xn1b) + (a2 * acc1b);

                                      
          sample--;
        }

                                                                         
        pState[0] = d1a;
        pState[1] = d2a;

        pState[2] = d1b;
        pState[3] = d2b;

        pState += 4U;

                                                                              
        pIn = pDst;

                                              
        pOut = pDst;

                                        
        stage--;

    } while (stage > 0U);

}
LOW_OPTIMIZATION_EXIT
   
                                   
   
