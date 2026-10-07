                                                                         
                                  
                                            
                                       
  
                               
                       
  
                                   
                                                                          
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

   
                       
   

   
                          
    
   

   
                                                                              
                                                                                    
                                                             
                                                              
                                                                       
                     

                                              
                                                                                
                                                                                                                                            
                                                                                                     
                                                                                                                                                         
                                                                                                                
         
                                                                                                                                                                    
                                                                                       
                                                                                                    
   

#if defined (ARM_MATH_DSP)

void arm_fir_decimate_fast_q15(
  const arm_fir_decimate_instance_q15 * S,
  const q15_t * pSrc,
        q15_t * pDst,
        uint32_t blockSize)
{
        q15_t *pState = S->pState;                                        
  const q15_t *pCoeffs = S->pCoeffs;                                            
        q15_t *pStateCur;                                                                             
        q15_t *px;                                                                             
  const q15_t *pb;                                                                                   
        q31_t x0, x1, c0;                                                                                            
        q31_t sum0;                                                      
        q31_t acc0, acc1;
        q15_t *px0, *px1;
        uint32_t blkCntN3;
        uint32_t numTaps = S->numTaps;                                     
        uint32_t i, blkCnt, tapCnt, outBlockSize = blockSize / S->M;                     

#if defined (ARM_MATH_LOOPUNROLL)
        q31_t c1;                                                                                                    
#endif

                                                                      
                                                                                   
  pStateCur = S->pState + (numTaps - 1U);

                                                     
  blkCnt = outBlockSize / 2;
  blkCntN3 = outBlockSize - (2 * blkCnt);

  while (blkCnt > 0U)
  {
                                                                                      
    i = S->M * 2;

    do
    {
      *pStateCur++ = *pSrc++;

    } while (--i);

                                 
    acc0 = 0;
    acc1 = 0;

                                                      
    px0 = pState;
    px1 = pState + S->M;

                                  
    pb = pCoeffs;

#if defined (ARM_MATH_LOOPUNROLL)

                                                  
    tapCnt = numTaps >> 2U;

    while (tapCnt > 0U)
    {
                                                               
      c0 = read_q15x2_ia ((q15_t **) &pb);

                                                        
      x0 = read_q15x2_ia (&px0);
      x1 = read_q15x2_ia (&px1);

                                           
      acc0 = __SMLAD(x0, c0, acc0);
      acc1 = __SMLAD(x1, c0, acc1);

                                                              
      c0 = read_q15x2_ia ((q15_t **) &pb);

                                                         
      x0 = read_q15x2_ia (&px0);
      x1 = read_q15x2_ia (&px1);

                                           
      acc0 = __SMLAD(x0, c0, acc0);
      acc1 = __SMLAD(x1, c0, acc1);

                                  
      tapCnt--;
    }

                                                
    tapCnt = numTaps % 0x4U;

#else

                                               
    tapCnt = numTaps;

#endif                                        

    while (tapCnt > 0U)
    {
                             
      c0 = *pb++;

                                                
      x0 = *px0++;
      x1 = *px1++;

                                           
      acc0 = __SMLAD(x0, c0, acc0);
      acc1 = __SMLAD(x1, c0, acc1);

                                  
      tapCnt--;
    }

                                                         
                                                                       
    pState = pState + S->M * 2;

                                                                      
                                                  
    *pDst++ = (q15_t) (__SSAT((acc0 >> 15), 16));
    *pDst++ = (q15_t) (__SSAT((acc1 >> 15), 16));

                                
    blkCnt--;
  }

  while (blkCntN3 > 0U)
  {
                                                                                  
    i = S->M;

    do
    {
      *pStateCur++ = *pSrc++;

    } while (--i);

                                 
    sum0 = 0;

                                  
    px = pState;

                                  
    pb = pCoeffs;

#if defined (ARM_MATH_LOOPUNROLL)

                                                  
    tapCnt = numTaps >> 2U;

    while (tapCnt > 0U)
    {
                                                               
      c0 = read_q15x2_ia ((q15_t **) &pb);

                                                         
      x0 = read_q15x2_ia (&px);

                                                               
      c1 = read_q15x2_ia ((q15_t **) &pb);

                                           
      sum0 = __SMLAD(x0, c0, sum0);

                                                         
      x0 = read_q15x2_ia (&px);

                                           
      sum0 = __SMLAD(x0, c1, sum0);

                                  
      tapCnt--;
    }

                                                
    tapCnt = numTaps % 0x4U;

#else

                                               
    tapCnt = numTaps;

#endif                                        

    while (tapCnt > 0U)
    {
                             
      c0 = *pb++;

                                  
      x0 = *px++;

                                           
      sum0 = __SMLAD(x0, c0, sum0);

                                  
      tapCnt--;
    }

                                                         
                                                                       
    pState = pState + S->M;

                                                                      
                                                  
    *pDst++ = (q15_t) (__SSAT((sum0 >> 15), 16));

                                
    blkCntN3--;
  }

                            
                                                                            
                                                                  

                                               
  pStateCur = S->pState;

  i = (numTaps - 1U) >> 2U;

                 
  while (i > 0U)
  {
    write_q15x2_ia (&pStateCur, read_q15x2_ia (&pState));
    write_q15x2_ia (&pStateCur, read_q15x2_ia (&pState));

                                
    i--;
  }

  i = (numTaps - 1U) % 0x04U;

                 
  while (i > 0U)
  {
    *pStateCur++ = *pState++;

                                
    i--;
  }

}

#else                                 

void arm_fir_decimate_fast_q15(
  const arm_fir_decimate_instance_q15 * S,
  const q15_t * pSrc,
        q15_t * pDst,
        uint32_t blockSize)
{
        q15_t *pState = S->pState;                                        
  const q15_t *pCoeffs = S->pCoeffs;                                            
        q15_t *pStateCur;                                                                             
        q15_t *px;                                                                             
  const q15_t *pb;                                                                                   
        q15_t x0, x1, c0;                                                                                            
        q31_t sum0;                                                      
        q31_t acc0, acc1;
        q15_t *px0, *px1;
        uint32_t blkCntN3;
        uint32_t numTaps = S->numTaps;                                     
        uint32_t i, blkCnt, tapCnt, outBlockSize = blockSize / S->M;                     


                                                                      
                                                                                   
  pStateCur = S->pState + (numTaps - 1U);

                                                     
  blkCnt = outBlockSize / 2;
  blkCntN3 = outBlockSize - (2 * blkCnt);

  while (blkCnt > 0U)
  {
                                                                                      
    i = S->M * 2;

    do
    {
      *pStateCur++ = *pSrc++;

    } while (--i);

                                 
    acc0 = 0;
    acc1 = 0;

                                  
    px0 = pState;
    px1 = pState + S->M;

                                  
    pb = pCoeffs;

#if defined (ARM_MATH_LOOPUNROLL)

                                                  
    tapCnt = numTaps >> 2U;

    while (tapCnt > 0U)
    {
                                                   
      c0 = *pb++;

                                                             
      x0 = *px0++;
      x1 = *px1++;

                                           
      acc0 += x0 * c0;
      acc1 += x1 * c0;

                                             
      c0 = *pb++;

                                                         
      x0 = *px0++;
      x1 = *px1++;

                                           
      acc0 += x0 * c0;
      acc1 += x1 * c0;

                                              
      c0 = *pb++;

                                                         
      x0 = *px0++;
      x1 = *px1++;

                                           
      acc0 += x0 * c0;
      acc1 += x1 * c0;

                                             
      c0 = *pb++;

                                                         
      x0 = *px0++;
      x1 = *px1++;

                                           
      acc0 += x0 * c0;
      acc1 += x1 * c0;

                                      
      tapCnt--;
    }

                                                
    tapCnt = numTaps % 0x4U;

#else

                                               
    tapCnt = numTaps;

#endif                                        

    while (tapCnt > 0U)
    {
                             
      c0 = *pb++;

                                  
      x0 = *px0++;
      x1 = *px1++;

                                           
      acc0 += x0 * c0;
      acc1 += x1 * c0;

                                      
      tapCnt--;
    }

                                                         
                                                                       
    pState = pState + S->M * 2;

                                                                      
                                                  

    *pDst++ = (q15_t) (__SSAT((acc0 >> 15), 16));
    *pDst++ = (q15_t) (__SSAT((acc1 >> 15), 16));

                                
    blkCnt--;
  }

  while (blkCntN3 > 0U)
  {
                                                                                  
    i = S->M;

    do
    {
      *pStateCur++ = *pSrc++;

    } while (--i);

                                 
    sum0 = 0;

                                  
    px = pState;

                                  
    pb = pCoeffs;

#if defined (ARM_MATH_LOOPUNROLL)

                                                  
    tapCnt = numTaps >> 2U;

    while (tapCnt > 0U)
    {
                                             
      c0 = *pb++;

                                      
      x0 = *px++;

                                           
      sum0 += x0 * c0;

                                             
      c0 = *pb++;

                                      
      x0 = *px++;

                                           
      sum0 += x0 * c0;

                                             
      c0 = *pb++;

                                      
      x0 = *px++;

                                           
      sum0 += x0 * c0;

                                             
      c0 = *pb++;

                                      
      x0 = *px++;

                                           
      sum0 += x0 * c0;

                                  
      tapCnt--;
    }

                                                
    tapCnt = numTaps % 0x4U;

#else

                                               
    tapCnt = numTaps;

#endif                                        

    while (tapCnt > 0U)
    {
                             
      c0 = *pb++;

                                  
      x0 = *px++;

                                           
      sum0 += x0 * c0;

                                      
      tapCnt--;
    }

                                                         
                                                                       
    pState = pState + S->M;

                                                                      
                                                  
    *pDst++ = (q15_t) (__SSAT((sum0 >> 15), 16));

                                
    blkCntN3--;
  }

                            
                                                                             
                                                                   

                                               
  pStateCur = S->pState;

  i = (numTaps - 1U) >> 2U;

                 
  while (i > 0U)
  {
    *pStateCur++ = *pState++;
    *pStateCur++ = *pState++;
    *pStateCur++ = *pState++;
    *pStateCur++ = *pState++;

                                
    i--;
  }

  i = (numTaps - 1U) % 0x04U;

                 
  while (i > 0U)
  {
    *pStateCur++ = *pState++;

                                
    i--;
  }
}

#endif                                 

   
                              
   
