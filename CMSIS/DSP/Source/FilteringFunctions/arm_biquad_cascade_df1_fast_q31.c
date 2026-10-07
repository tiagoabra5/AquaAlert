                                                                         
                                  
                                                  
                                                                                            
  
                               
                       
  
                                   
                                                                          
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

   
                       
   

   
                              
    
   

   
                                                                                      
                                                                                    
                                                            
                                                             
                                                                
                     

                                              
                                                                                                                        
                                                                                             
                                                                              
                                                                                        
                                                                                                                                                                                       
                                                                                                                                                                             
                                                                                    
         
                                                                                                          
                                                                                                                                                   
                                                                                                              
   

void arm_biquad_cascade_df1_fast_q31(
  const arm_biquad_casd_df1_inst_q31 * S,
  const q31_t * pSrc,
        q31_t * pDst,
        uint32_t blockSize)
{
  const q31_t *pIn = pSrc;                                                 
        q31_t *pOut = pDst;                                                     
        q31_t *pState = S->pState;                                         
  const q31_t *pCoeffs = S->pCoeffs;                                            
        q31_t acc = 0;                                                  
        q31_t b0, b1, b2, a1, a2;                                               
        q31_t Xn1, Xn2, Yn1, Yn2;                                                   
        q31_t Xn;                                                           
        int32_t shift = (int32_t) S->postShift + 1;                                           
        uint32_t sample, stage = S->numStages;                            

  do
  {
                                  
    b0 = *pCoeffs++;
    b1 = *pCoeffs++;
    b2 = *pCoeffs++;
    a1 = *pCoeffs++;
    a2 = *pCoeffs++;

                                   
    Xn1 = pState[0];
    Xn2 = pState[1];
    Yn1 = pState[2];
    Yn2 = pState[3];

#if defined (ARM_MATH_LOOPUNROLL)

                                                                          
                                                                         
      
                                                                               
       

                                                     
    sample = blockSize >> 2U;

    while (sample > 0U)
    {
                          
      Xn = *pIn;

                                                                                    
                            
                                                    
      mult_32x32_keep32_R(acc, b1, Xn1);
                               
                                                                             
      multAcc_32x32_keep32_R(acc, b0, Xn);
                                 
                                                                              
      multAcc_32x32_keep32_R(acc, b2, Xn2);
                               
                                                                              
      multAcc_32x32_keep32_R(acc, a1, Yn1);
                               
                                                                              
      multAcc_32x32_keep32_R(acc, a2, Yn2);

                                                                    
      Yn2 = acc << shift;

                                 
      Xn2 = *(pIn + 1U);

                                                       
      *pOut = Yn2;

                                                                                    
                            
                                                      
      mult_32x32_keep32_R(acc, b0, Xn2);
                               
                                                                             
      multAcc_32x32_keep32_R(acc, b1, Xn);
                                 
                                                                              
      multAcc_32x32_keep32_R(acc, b2, Xn1);
                               
                                                                              
      multAcc_32x32_keep32_R(acc, a1, Yn2);
                               
                                                                              
      multAcc_32x32_keep32_R(acc, a2, Yn1);

                                                                    
      Yn1 = acc << shift;

                                 
      Xn1 = *(pIn + 2U);

                                                       
      *(pOut + 1U) = Yn1;

                                                                                    
                            
                                                      
      mult_32x32_keep32_R(acc, b0, Xn1);
                               
                                                                              
      multAcc_32x32_keep32_R(acc, b1, Xn2);
                                 
                                                                             
      multAcc_32x32_keep32_R(acc, b2, Xn);
                               
                                                                              
      multAcc_32x32_keep32_R(acc, a1, Yn1);
                               
                                                                              
      multAcc_32x32_keep32_R(acc, a2, Yn2);

                                                                    
      Yn2 = acc << shift;

                                
      Xn = *(pIn + 3U);

                                                       
      *(pOut + 2U) = Yn2;
      pIn += 4U;

                                                                                    
                            
                                                     
      mult_32x32_keep32_R(acc, b0, Xn);
                               
                                                                             
      multAcc_32x32_keep32_R(acc, b1, Xn1);
                                 
                                                                             
      multAcc_32x32_keep32_R(acc, b2, Xn2);
                               
                                                                             
      multAcc_32x32_keep32_R(acc, a1, Yn2);
                               
                                                                             
      multAcc_32x32_keep32_R(acc, a2, Yn1);

                                                                            
                                             
                     
      Xn2 = Xn1;

                                                                    
      Yn1 = acc << shift;

                    
      Xn1 = Xn;

                                                       
      *(pOut + 3U) = Yn1;
      pOut += 4U;

                                  
      sample--;
    }

                                                   
    sample = (blockSize & 0x3U);

#else

                                                  
    sample = blockSize;

#endif                                        

    while (sample > 0U)
    {
                          
      Xn = *pIn++;

                                                                                    
                            
                                                     
      mult_32x32_keep32_R(acc, b0, Xn);
                               
                                                                              
      multAcc_32x32_keep32_R(acc, b1, Xn1);
                                 
                                                                              
      multAcc_32x32_keep32_R(acc, b2, Xn2);
                               
                                                                              
      multAcc_32x32_keep32_R(acc, a1, Yn1);
                               
                                                                              
      multAcc_32x32_keep32_R(acc, a2, Yn2);

                                            
      acc = acc << shift;

                                                                            
                                             
                     
                     
                     
                     
      Xn2 = Xn1;
      Xn1 = Xn;
      Yn2 = Yn1;
      Yn1 = acc;

                                                       
      *pOut++ = acc;

                                  
      sample--;
    }

                                                                          
                                                               
    pIn = pDst;

                                      
    pOut = pDst;

                                                                      
    *pState++ = Xn1;
    *pState++ = Xn2;
    *pState++ = Yn1;
    *pState++ = Yn2;

  } while (--stage);
}

   
                                  
   
