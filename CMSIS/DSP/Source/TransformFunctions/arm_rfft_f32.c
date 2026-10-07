                                                                         
                                  
                               
                                                             
  
                               
                       
  
                                   
                                                                          
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

                                                                         
                                
                                                                          

extern void arm_radix4_butterfly_f32(
        float32_t * pSrc,
        uint16_t fftLen,
  const float32_t * pCoef,
        uint16_t twidCoefModifier);

extern void arm_radix4_butterfly_inverse_f32(
        float32_t * pSrc,
        uint16_t fftLen,
  const float32_t * pCoef,
        uint16_t twidCoefModifier,
        float32_t onebyfftLen);

extern void arm_bitreversal_f32(
        float32_t * pSrc,
        uint16_t fftSize,
        uint16_t bitRevFactor,
  const uint16_t * pBitRevTab);

void arm_split_rfft_f32(
        float32_t * pSrc,
        uint32_t fftLen,
  const float32_t * pATable,
  const float32_t * pBTable,
        float32_t * pDst,
        uint32_t modifier);

void arm_split_rifft_f32(
        float32_t * pSrc,
        uint32_t fftLen,
  const float32_t * pATable,
  const float32_t * pBTable,
        float32_t * pDst,
        uint32_t modifier);

   
                          
   

   
                     
    
   

   
                                                                       
                                                                                                                               
                                                                                      
                                                
                                                 
                     
   

void arm_rfft_f32(
  const arm_rfft_instance_f32 * S,
        float32_t * pSrc,
        float32_t * pDst)
{
  const arm_cfft_radix4_instance_f32 *S_CFFT = S->pCfft;

                                         
  if (S->ifftFlagR == 1U)
  {
                                  
     arm_split_rifft_f32 (pSrc, S->fftLenBy2, S->pTwiddleAReal, S->pTwiddleBReal, pDst, S->twidCoefRModifier);


                                       
     arm_radix4_butterfly_inverse_f32 (pDst, S_CFFT->fftLen, S_CFFT->pTwiddle, S_CFFT->twidCoefModifier, S_CFFT->onebyfftLen);

                              
    if (S->bitReverseFlagR == 1U)
    {
      arm_bitreversal_f32 (pDst, S_CFFT->fftLen, S_CFFT->bitRevFactor, S_CFFT->pBitRevTable);
    }
  }
  else
  {
                                      

                                     
    arm_radix4_butterfly_f32 (pSrc, S_CFFT->fftLen, S_CFFT->pTwiddle, S_CFFT->twidCoefModifier);

                              
    if (S->bitReverseFlagR == 1U)
    {
      arm_bitreversal_f32 (pSrc, S_CFFT->fftLen, S_CFFT->bitRevFactor, S_CFFT->pBitRevTable);
    }

                                
    arm_split_rfft_f32 (pSrc, S->fftLenBy2, S->pTwiddleAReal, S->pTwiddleBReal, pDst, S->twidCoefRModifier);
  }

}

   
                         
   

   
                                      
                                                 
                                        
                                                          
                                                          
                                                  
                                                                                                                            
                     
   

void arm_split_rfft_f32(
        float32_t * pSrc,
        uint32_t fftLen,
  const float32_t * pATable,
  const float32_t * pBTable,
        float32_t * pDst,
        uint32_t modifier)
{
        uint32_t i;                                                      
        float32_t outR, outI;                                                              
  const float32_t *pCoefA, *pCoefB;                                                                
        float32_t CoefA1, CoefA2, CoefB1;                                                                
        float32_t *pDst1 = &pDst[2], *pDst2 = &pDst[(4U * fftLen) - 1U];                                           
        float32_t *pSrc1 = &pSrc[2], *pSrc2 = &pSrc[(2U * fftLen) - 1U];                                          

                                 
  pCoefA = &pATable[modifier * 2];
  pCoefB = &pBTable[modifier * 2];

  i = fftLen - 1U;

  while (i > 0U)
  {
       
                                                         
                                                             
                                                         
                                                               

                                                        
                                                            
                                                            
                                                          
        

                             
    CoefA1 = *pCoefA++;
                            
    CoefA2 = *pCoefA;

                                      
    outR = *pSrc1 * CoefA1;
                              
    outI = *pSrc1++ * CoefA2;

                                                                   
    outR -= (*pSrc1 + *pSrc2) * CoefA2;
                                  
    outI += *pSrc1++ * CoefA1;

    CoefB1 = *pCoefB;

                                               
    outI -= *pSrc2-- * CoefB1;
                                           
    outI -= *pSrc2 * CoefA2;

                                           
    outR += *pSrc2-- * CoefB1;

                      
    *pDst1++ = outR;
    *pDst1++ = outI;

                                        
    *pDst2-- = -outI;
    *pDst2-- = outR;

                                    
    pCoefB = pCoefB + (modifier * 2U);
    pCoefA = pCoefA + ((modifier * 2U) - 1U);

    i--;

  }

  pDst[2U * fftLen] = pSrc[0] - pSrc[1];
  pDst[(2U * fftLen) + 1U] = 0.0f;

  pDst[0] = pSrc[0] + pSrc[1];
  pDst[1] = 0.0f;

}


   
                                       
                                                 
                                        
                                                          
                                                          
                                                  
                                                                                                                            
                     
   

void arm_split_rifft_f32(
        float32_t * pSrc,
        uint32_t fftLen,
  const float32_t * pATable,
  const float32_t * pBTable,
        float32_t * pDst,
        uint32_t modifier)
{
        float32_t outR, outI;                                                              
  const float32_t *pCoefA, *pCoefB;                                                                
        float32_t CoefA1, CoefA2, CoefB1;                                                                
        float32_t *pSrc1 = &pSrc[0], *pSrc2 = &pSrc[(2U * fftLen) + 1U];

  pCoefA = &pATable[0];
  pCoefB = &pBTable[0];

  while (fftLen > 0U)
  {
       
                                                        
                                                            
                                                        
                                                              

                                                        
                                                            
                                                            
                                                          
        

     CoefA1 = *pCoefA++;
     CoefA2 = *pCoefA;

                                       
     outR = *pSrc1 * CoefA1;

                                 
     outI = -(*pSrc1++) * CoefA2;

                                                                    
     outR += (*pSrc1 + *pSrc2) * CoefA2;

                                   
     outI += (*pSrc1++) * CoefA1;

     CoefB1 = *pCoefB;

                                                  
     outI -= *pSrc2-- * CoefB1;

                                            
     outR += *pSrc2 * CoefB1;

                                            
     outI += *pSrc2-- * CoefA2;

                       
     *pDst++ = outR;
     *pDst++ = outI;

                                     
     pCoefB = pCoefB + (modifier * 2);
     pCoefA = pCoefA + (modifier * 2 - 1);

                               
     fftLen--;
  }

}
