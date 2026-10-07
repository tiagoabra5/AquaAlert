                                                                         
                                  
                               
                                                 
  
                               
                       
  
                                   
                                                                          
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

                                                                         
                                
                                                                          

void arm_split_rfft_q31(
        q31_t * pSrc,
        uint32_t fftLen,
  const q31_t * pATable,
  const q31_t * pBTable,
        q31_t * pDst,
        uint32_t modifier);

void arm_split_rifft_q31(
        q31_t * pSrc,
        uint32_t fftLen,
  const q31_t * pATable,
  const q31_t * pBTable,
        q31_t * pDst,
        uint32_t modifier);

   
                     
    
   

   
                                                            
                                                                            
                                             
                                              
                     

                                        
                                                                                                                      
                                                                                 
                                                                                                                                                            
      
                                                                                  
      
                                                                                    
   

void arm_rfft_q31(
  const arm_rfft_instance_q31 * S,
        q31_t * pSrc,
        q31_t * pDst)
{
  const arm_cfft_instance_q31 *S_CFFT = S->pCfft;
        uint32_t L2 = S->fftLenReal >> 1U;
        uint32_t i;

                                     
  if (S->ifftFlagR == 1U)
  {
                                  
     arm_split_rifft_q31 (pSrc, L2, S->pTwiddleAReal, S->pTwiddleBReal, pDst, S->twidCoefRModifier);

                               
     arm_cfft_q31 (S_CFFT, pDst, S->ifftFlagR, S->bitReverseFlagR);

     for(i = 0; i < S->fftLenReal; i++)
     {
        pDst[i] = pDst[i] << 1U;
     }
  }
  else
  {
                                       

                              
     arm_cfft_q31 (S_CFFT, pSrc, S->ifftFlagR, S->bitReverseFlagR);

                                 
     arm_split_rfft_q31 (pSrc, L2, S->pTwiddleAReal, S->pTwiddleBReal, pDst, S->twidCoefRModifier);
  }

}

   
                         
   

   
                                      
                                                 
                                        
                                                          
                                                          
                                                  
                                                                                                                            
                     
   

void arm_split_rfft_q31(
        q31_t * pSrc,
        uint32_t fftLen,
  const q31_t * pATable,
  const q31_t * pBTable,
        q31_t * pDst,
        uint32_t modifier)
{
        uint32_t i;                                                      
        q31_t outR, outI;                                                                  
  const q31_t *pCoefA, *pCoefB;                                                                    
        q31_t CoefA1, CoefA2, CoefB1;                                                                    
        q31_t *pOut1 = &pDst[2], *pOut2 = &pDst[4 * fftLen - 1];
        q31_t *pIn1 =  &pSrc[2], *pIn2 =  &pSrc[2 * fftLen - 1];

                                 
  pCoefA = &pATable[modifier * 2];
  pCoefB = &pBTable[modifier * 2];

  i = fftLen - 1U;

  while (i > 0U)
  {
       
                                                         
                                                             
                                                         
                                                               

                                                        
                                                            
                                                            
                                                          
        

     CoefA1 = *pCoefA++;
     CoefA2 = *pCoefA;

                                               
     mult_32x32_keep32_R (outR, *pIn1, CoefA1);

                                                 
     mult_32x32_keep32_R (outI, *pIn1++, CoefA2);

                                                 
     multSub_32x32_keep32_R (outR, *pIn1, CoefA2);

                                           
     multAcc_32x32_keep32_R (outI, *pIn1++, CoefA1);

                                                
     multSub_32x32_keep32_R (outR, *pIn2, CoefA2);
     CoefB1 = *pCoefB;

                                                  
     multSub_32x32_keep32_R (outI, *pIn2--, CoefB1);

                                                       
     multAcc_32x32_keep32_R (outR, *pIn2, CoefB1);

                                                  
     multSub_32x32_keep32_R (outI, *pIn2--, CoefA2);

                       
     *pOut1++ = outR;
     *pOut1++ = outI;

                                         
     *pOut2-- = -outI;
     *pOut2-- = outR;

                                     
     pCoefB = pCoefB + (2 * modifier);
     pCoefA = pCoefA + (2 * modifier - 1);

                               
     i--;
  }

  pDst[2 * fftLen]     = (pSrc[0] - pSrc[1]) >> 1U;
  pDst[2 * fftLen + 1] = 0;

  pDst[0] = (pSrc[0] + pSrc[1]) >> 1U;
  pDst[1] = 0;
}


   
                                       
                                                 
                                        
                                                          
                                                          
                                                  
                                                                                                                            
                     
   

void arm_split_rifft_q31(
        q31_t * pSrc,
        uint32_t fftLen,
  const q31_t * pATable,
  const q31_t * pBTable,
        q31_t * pDst,
        uint32_t modifier)
{       
        q31_t outR, outI;                                                                  
  const q31_t *pCoefA, *pCoefB;                                                                    
        q31_t CoefA1, CoefA2, CoefB1;                                                                    
        q31_t *pIn1 = &pSrc[0], *pIn2 = &pSrc[2 * fftLen + 1];

  pCoefA = &pATable[0];
  pCoefB = &pBTable[0];

  while (fftLen > 0U)
  {
       
                                                        
                                                            
                                                        
                                                              

                                                        
                                                            
                                                            
                                                          
        

     CoefA1 = *pCoefA++;
     CoefA2 = *pCoefA;

                                              
     mult_32x32_keep32_R (outR, *pIn1, CoefA1);

                                            
     mult_32x32_keep32_R (outI, *pIn1++, -CoefA2);

                                              
     multAcc_32x32_keep32_R (outR, *pIn1, CoefA2);

                                          
     multAcc_32x32_keep32_R (outI, *pIn1++, CoefA1);

                                              
     multAcc_32x32_keep32_R (outR, *pIn2, CoefA2);
     CoefB1 = *pCoefB;

                                                  
     multSub_32x32_keep32_R (outI, *pIn2--, CoefB1);

                                                      
     multAcc_32x32_keep32_R (outR, *pIn2, CoefB1);

                                                  
     multAcc_32x32_keep32_R (outI, *pIn2--, CoefA2);

                       
     *pDst++ = outR;
     *pDst++ = outI;

                                     
     pCoefB = pCoefB + (modifier * 2);
     pCoefA = pCoefA + (modifier * 2 - 1);

                               
     fftLen--;
  }

}
