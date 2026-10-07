                                                                         
                                  
                               
                                                  
  
                               
                       
  
                                   
                                                                          
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

                                                                         
                                
                                                                          

void arm_split_rfft_q15(
        q15_t * pSrc,
        uint32_t fftLen,
  const q15_t * pATable,
  const q15_t * pBTable,
        q15_t * pDst,
        uint32_t modifier);

void arm_split_rifft_q15(
        q15_t * pSrc,
        uint32_t fftLen,
  const q15_t * pATable,
  const q15_t * pBTable,
        q15_t * pDst,
        uint32_t modifier);

   
                     
    
   

   
                                                            
                                                                            
                                             
                                              
                     

                                        
                                                                                                                      
                                                                                 
                                                                                                                                                            
      
                                                                                  
      
                                                                                    
   

void arm_rfft_q15(
  const arm_rfft_instance_q15 * S,
        q15_t * pSrc,
        q15_t * pDst)
{
  const arm_cfft_instance_q15 *S_CFFT = S->pCfft;
        uint32_t L2 = S->fftLenReal >> 1U;
        uint32_t i;

                                     
  if (S->ifftFlagR == 1U)
  {
                                  
     arm_split_rifft_q15 (pSrc, L2, S->pTwiddleAReal, S->pTwiddleBReal, pDst, S->twidCoefRModifier);

                               
     arm_cfft_q15 (S_CFFT, pDst, S->ifftFlagR, S->bitReverseFlagR);

     for(i = 0; i < S->fftLenReal; i++)
     {
        pDst[i] = pDst[i] << 1U;
     }
  }
  else
  {
                                       

                              
     arm_cfft_q15 (S_CFFT, pSrc, S->ifftFlagR, S->bitReverseFlagR);

                                 
     arm_split_rfft_q15 (pSrc, L2, S->pTwiddleAReal, S->pTwiddleBReal, pDst, S->twidCoefRModifier);
  }

}

   
                         
   

   
                                      
                                                 
                                        
                                                          
                                                          
                                                  
                                                                                                                            
                     

      
                                                     
   

void arm_split_rfft_q15(
        q15_t * pSrc,
        uint32_t fftLen,
  const q15_t * pATable,
  const q15_t * pBTable,
        q15_t * pDst,
        uint32_t modifier)
{       
        uint32_t i;                                                      
        q31_t outR, outI;                                                                  
  const q15_t *pCoefA, *pCoefB;                                                                    
        q15_t *pSrc1, *pSrc2;
#if defined (ARM_MATH_DSP)
        q15_t *pD1, *pD2;
#endif

                                 
  pCoefA = &pATable[modifier * 2];
  pCoefB = &pBTable[modifier * 2];

  pSrc1 = &pSrc[2];
  pSrc2 = &pSrc[(2U * fftLen) - 2U];

#if defined (ARM_MATH_DSP)

    i = 1U;
    pD1 = pDst + 2;
    pD2 = pDst + (4U * fftLen) - 2;

    for (i = fftLen - 1; i > 0; i--)
    {
          
                                                            
                                                                
                                                            
                                                                  

                                                           
                                                               
                                                               
                                                            
           


#ifndef ARM_MATH_BIG_ENDIAN
                                                                                 
        outR = __SMUSD(read_q15x2 (pSrc1), read_q15x2((q15_t *) pCoefA));
#else
                                                                                    
        outR = -(__SMUSD(read_q15x2 (pSrc1), read_q15x2((q15_t *) pCoefA)));
#endif                                  

                                                                                                  
        outR = __SMLAD(read_q15x2 (pSrc2), read_q15x2((q15_t *) pCoefB), outR) >> 16U;

                                                                                               
#ifndef ARM_MATH_BIG_ENDIAN
        outI = __SMUSDX(read_q15x2_da (&pSrc2), read_q15x2((q15_t *) pCoefB));
#else
        outI = __SMUSDX(read_q15x2 ((q15_t *) pCoefB), read_q15x2_da (&pSrc2));
#endif                                  

                                                                                
        outI = __SMLADX(read_q15x2_ia (&pSrc1), read_q15x2 ((q15_t *) pCoefA), outI);

                          
        *pD1++ = (q15_t) outR;
        *pD1++ = outI >> 16U;

                                            
        pD2[0] = (q15_t) outR;
        pD2[1] = -(outI >> 16U);
        pD2 -= 2;

                                        
        pCoefB = pCoefB + (2U * modifier);
        pCoefA = pCoefA + (2U * modifier);
    }

    pDst[2U * fftLen]      = (pSrc[0] - pSrc[1]) >> 1U;
    pDst[2U * fftLen + 1U] = 0;

    pDst[0] = (pSrc[0] + pSrc[1]) >> 1U;
    pDst[1] = 0;

#else

    i = 1U;

    while (i < fftLen)
    {
          
                                                            
                                                                
                                                            
                                                                  
          

        outR = *pSrc1 * *pCoefA;
        outR = outR - (*(pSrc1 + 1) * *(pCoefA + 1));
        outR = outR + (*pSrc2 * *pCoefB);
        outR = (outR + (*(pSrc2 + 1) * *(pCoefB + 1))) >> 16;

          
                                                           
                                                               
                                                               
                                                             
          

        outI = *pSrc2 * *(pCoefB + 1);
        outI = outI - (*(pSrc2 + 1) * *pCoefB);
        outI = outI + (*(pSrc1 + 1) * *pCoefA);
        outI = outI + (*pSrc1 * *(pCoefA + 1));

                                   
        pSrc1 += 2U;
        pSrc2 -= 2U;

                          
        pDst[2U * i] = (q15_t) outR;
        pDst[2U * i + 1U] = outI >> 16U;

                                            
        pDst[(4U * fftLen) - (2U * i)] = (q15_t) outR;
        pDst[((4U * fftLen) - (2U * i)) + 1U] = -(outI >> 16U);

                                        
        pCoefB = pCoefB + (2U * modifier);
        pCoefA = pCoefA + (2U * modifier);

        i++;
    }

    pDst[2U * fftLen] = (pSrc[0] - pSrc[1]) >> 1;
    pDst[2U * fftLen + 1U] = 0;

    pDst[0] = (pSrc[0] + pSrc[1]) >> 1;
    pDst[1] = 0;

#endif                                 
}


   
                                       
                                                 
                                        
                                                          
                                                          
                                                  
                                                                                                                            
                     

      
                                                      
   

void arm_split_rifft_q15(
        q15_t * pSrc,
        uint32_t fftLen,
  const q15_t * pATable,
  const q15_t * pBTable,
        q15_t * pDst,
        uint32_t modifier)
{
        uint32_t i;                                                      
        q31_t outR, outI;                                                                  
  const q15_t *pCoefA, *pCoefB;                                                                    
        q15_t *pSrc1, *pSrc2;
        q15_t *pDst1 = &pDst[0];

  pCoefA = &pATable[0];
  pCoefB = &pBTable[0];

  pSrc1 = &pSrc[0];
  pSrc2 = &pSrc[2 * fftLen];

  i = fftLen;
  while (i > 0U)
  {
        
                                                         
                                                             
                                                         
                                                               

                                                         
                                                             
                                                             
                                                           
         

#if defined (ARM_MATH_DSP)

#ifndef ARM_MATH_BIG_ENDIAN
                                                                                              
      outR = __SMUSD(read_q15x2(pSrc2), read_q15x2((q15_t *) pCoefB));
#else
                                                                                                  
      outR = -(__SMUSD(read_q15x2(pSrc2), read_q15x2((q15_t *) pCoefB)));
#endif                                  

                                                                                                                   
      outR = __SMLAD(read_q15x2(pSrc1), read_q15x2 ((q15_t *) pCoefA), outR) >> 16U;

                                                                                              
      outI = __SMUADX(read_q15x2_da (&pSrc2), read_q15x2((q15_t *) pCoefB));

                                                                             
#ifndef ARM_MATH_BIG_ENDIAN
      outI = __SMLSDX(read_q15x2 ((q15_t *) pCoefA), read_q15x2_ia (&pSrc1), -outI);
#else
      outI = __SMLSDX(read_q15x2_ia (&pSrc1), read_q15x2 ((q15_t *) pCoefA), -outI);
#endif                                  

                        
#ifndef ARM_MATH_BIG_ENDIAN
      write_q15x2_ia (&pDst1, __PKHBT(outR, (outI >> 16U), 16));
#else
      write_q15x2_ia (&pDst1, __PKHBT((outI >> 16U), outR, 16));
#endif                                  


#else                                  

      outR = *pSrc2 * *pCoefB;
      outR = outR - (*(pSrc2 + 1) * *(pCoefB + 1));
      outR = outR + (*pSrc1 * *pCoefA);
      outR = (outR + (*(pSrc1 + 1) * *(pCoefA + 1))) >> 16;

      outI = *(pSrc1 + 1) * *pCoefA;
      outI = outI - (*pSrc1 * *(pCoefA + 1));
      outI = outI - (*pSrc2 * *(pCoefB + 1));
      outI = outI - (*(pSrc2 + 1) * *(pCoefB));

                                 
      pSrc1 += 2U;
      pSrc2 -= 2U;

                        
      *pDst1++ = (q15_t) outR;
      *pDst1++ = (q15_t) (outI >> 16);

#endif                                 

                                      
      pCoefB = pCoefB + (2 * modifier);
      pCoefA = pCoefA + (2 * modifier);

      i--;
  }

}
