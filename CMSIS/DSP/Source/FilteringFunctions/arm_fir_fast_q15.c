                                                                         
                                  
                                   
                                                        
  
                               
                       
  
                                   
                                                                          
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

   
                       
   

   
                 
    
   

   
                                                                           
                                                                                 
                                                             
                                                              
                                                        
                     

                                              
                                                                                
                                                                                                                                            
                                                                                                     
                                                                                                                     
                                                                                                                

         
                                                                                                                                                                                                                                 
                                                                                           
   

void arm_fir_fast_q15(
  const arm_fir_instance_q15 * S,
  const q15_t * pSrc,
        q15_t * pDst,
        uint32_t blockSize)
{
        q15_t *pState = S->pState;                                        
  const q15_t *pCoeffs = S->pCoeffs;                                            
        q15_t *pStateCurnt;                                                                           
        q15_t *px;                                                                             
  const q15_t *pb;                                                                                   
        q31_t acc0;                                                      
        uint32_t numTaps = S->numTaps;                                                                  
        uint32_t tapCnt, blkCnt;                                          

#if defined (ARM_MATH_LOOPUNROLL)
        q31_t acc1, acc2, acc3;                                          
        q31_t x0, x1, x2, c0;                                                                                        
#endif

                                                                                           
                                                                                     
  pStateCurnt = &(S->pState[(numTaps - 1U)]);

#if defined (ARM_MATH_LOOPUNROLL)

                                                            
                                                                            
    
                                                                                                                               
                                                                                                                               
                                                                                                                               
                                                                                                                               
     
  blkCnt = blockSize >> 2U;

  while (blkCnt > 0U)
  {
                                                         
    *pStateCurnt++ = *pSrc++;
    *pStateCurnt++ = *pSrc++;
    *pStateCurnt++ = *pSrc++;
    *pStateCurnt++ = *pSrc++;

                                      
    acc0 = 0;
    acc1 = 0;
    acc2 = 0;
    acc3 = 0;

                                                                            
    px = pState;

                                                                                  
    pb = pCoeffs;

                                                                             
    x0 = read_q15x2_ia (&px);

                                                                                    
    x2 = read_q15x2_ia (&px);

                                                              
                                                                       
    tapCnt = numTaps >> 2U;

    while (tapCnt > 0U)
    {
                                                                                     
      c0 = read_q15x2_ia ((q15_t **) &pb);

                                                      
      acc0 = __SMLAD(x0, c0, acc0);

                                                        
      acc2 = __SMLAD(x2, c0, acc2);

                                       
#ifndef ARM_MATH_BIG_ENDIAN
      x1 = __PKHBT(x2, x0, 0);
#else
      x1 = __PKHBT(x0, x2, 0);
#endif

                                         
      x0 = read_q15x2_ia (&px);

                                                        
      acc1 = __SMLADX(x1, c0, acc1);

                                       
#ifndef ARM_MATH_BIG_ENDIAN
      x1 = __PKHBT(x0, x2, 0);
#else
      x1 = __PKHBT(x2, x0, 0);
#endif

                                                        
      acc3 = __SMLADX(x1, c0, acc3);

                                            
      c0 = read_q15x2_ia ((q15_t **) &pb);

                                                          
      acc0 = __SMLAD(x2, c0, acc0);

                                                     
      x2 = read_q15x2_ia (&px);

                                                          
      acc2 = __SMLAD(x0, c0, acc2);

                                                          
      acc1 = __SMLADX(x1, c0, acc1);

                                       
#ifndef ARM_MATH_BIG_ENDIAN
      x1 = __PKHBT(x2, x0, 0);
#else
      x1 = __PKHBT(x0, x2, 0);
#endif

                                                          
      acc3 = __SMLADX(x1, c0, acc3);

                               
      tapCnt--;
    }

                                                                                      
                                                                   
    if ((numTaps & 0x3U) != 0U)
    {
                                      
      c0 = read_q15x2_ia ((q15_t **) &pb);

                                            
      acc0 = __SMLAD(x0, c0, acc0);
      acc2 = __SMLAD(x2, c0, acc2);

                                
#ifndef ARM_MATH_BIG_ENDIAN
      x1 = __PKHBT(x2, x0, 0);
#else
      x1 = __PKHBT(x0, x2, 0);
#endif

                                     
      x0 = read_q15x2 (px);

                                            
      acc1 = __SMLADX(x1, c0, acc1);

                                
#ifndef ARM_MATH_BIG_ENDIAN
      x1 = __PKHBT(x0, x2, 0);
#else
      x1 = __PKHBT(x2, x0, 0);
#endif

                                            
      acc3 = __SMLADX(x1, c0, acc3);
    }

                                                                                             
                                                             
#ifndef ARM_MATH_BIG_ENDIAN
    write_q15x2_ia (&pDst, __PKHBT(__SSAT((acc0 >> 15), 16), __SSAT((acc1 >> 15), 16), 16));
    write_q15x2_ia (&pDst, __PKHBT(__SSAT((acc2 >> 15), 16), __SSAT((acc3 >> 15), 16), 16));
#else
    write_q15x2_ia (&pDst, __PKHBT(__SSAT((acc1 >> 15), 16), __SSAT((acc0 >> 15), 16), 16));
    write_q15x2_ia (&pDst, __PKHBT(__SSAT((acc3 >> 15), 16), __SSAT((acc2 >> 15), 16), 16));
#endif                                  

                                                                               
    pState = pState + 4U;

                                
    blkCnt--;
  }

                                                        
  blkCnt = blockSize % 0x4U;

#else

                                             
  blkCnt = blockSize;

#endif                                        

  while (blkCnt > 0U)
  {
                                            
    *pStateCurnt++ = *pSrc++;

                                     
    acc0 = 0;

                                                  
    px = pState;
    pb = pCoeffs;

    tapCnt = numTaps >> 1U;

    do
    {
      acc0 += (q31_t) *px++ * *pb++;
	  acc0 += (q31_t) *px++ * *pb++;

      tapCnt--;
    }
    while (tapCnt > 0U);

                                                                     
                                                          
    *pDst++ = (q15_t) (__SSAT((acc0 >> 15), 16));

                                                        
    pState = pState + 1U;

                                
    blkCnt--;
  }

                            
                                                                            
                                                                  

                                               
  pStateCurnt = S->pState;

#if defined (ARM_MATH_LOOPUNROLL)

                                                
  tapCnt = (numTaps - 1U) >> 2U;

                 
  while (tapCnt > 0U)
  {
    *pStateCurnt++ = *pState++;
    *pStateCurnt++ = *pState++;
    *pStateCurnt++ = *pState++;
    *pStateCurnt++ = *pState++;

                                
    tapCnt--;
  }

                                            
  tapCnt = (numTaps - 1U) % 0x4U;

#else

                                             
  tapCnt = (numTaps - 1U);

#endif                                        

                           
  while (tapCnt > 0U)
  {
    *pStateCurnt++ = *pState++;

                                
    tapCnt--;
  }

}

   
                     
   
