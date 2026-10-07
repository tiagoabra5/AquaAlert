                                                                         
                                  
                                     
                                                          
  
                               
                       
  
                                   
                                                                          
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

   
                       
   

   
                        
    
   

   
                                                                   
                                                                                  
                                                              
                                                               
                                                                           
                                                                           
                                                                        
                     

                                              
                                                                                    
                                                                                                                 
                                                                                                                                        
                                                                                                
                                                                                                                                                    
                                                                                                                          
   

void arm_fir_sparse_q15(
        arm_fir_sparse_instance_q15 * S,
  const q15_t * pSrc,
        q15_t * pDst,
        q15_t * pScratchIn,
        q31_t * pScratchOut,
        uint32_t blockSize)
{
        q15_t *pState = S->pState;                                        
  const q15_t *pCoeffs = S->pCoeffs;                                            
        q15_t *px;                                                                                
        q15_t *py = pState;                                                                     
        q15_t *pb = pScratchIn;                                                                   
        q15_t *pOut = pDst;                                                            
        int32_t *pTapDelay = S->pTapDelay;                                                                                     
        uint32_t delaySize = S->maxDelay + blockSize;                    
        uint16_t numTaps = S->numTaps;                                                                   
        int32_t readIndex;                                                                 
        uint32_t tapCnt, blkCnt;                                          
        q31_t *pScr2 = pScratchOut;                                                                             
        q15_t coeff = *pCoeffs++;                                                            

#if defined (ARM_MATH_LOOPUNROLL)
        q31_t in1, in2;                                                         
#endif

                                                                   
                                                                               
  arm_circularWrite_q15(py, (int32_t) delaySize, &S->stateIndex, 1,pSrc, 1, blockSize);

                                     
  tapCnt = numTaps;

                                                                              
  readIndex = (int32_t) (S->stateIndex - blockSize) - *pTapDelay++;

                               
  if (readIndex < 0)
  {
    readIndex += (int32_t) delaySize;
  }

                                                   
  py = pState;

                                                        
  arm_circularRead_q15(py, (int32_t) delaySize, &readIndex, 1,
                       pb, pb, (int32_t) blockSize, 1, blockSize);

                                                              
  px = pb;

                                                           
  pScratchOut = pScr2;


#if defined (ARM_MATH_LOOPUNROLL)

                                                    
  blkCnt = blockSize >> 2U;

  while (blkCnt > 0U)
  {
                                                                
    *pScratchOut++ = ((q31_t) *px++ * coeff);
    *pScratchOut++ = ((q31_t) *px++ * coeff);
    *pScratchOut++ = ((q31_t) *px++ * coeff);
    *pScratchOut++ = ((q31_t) *px++ * coeff);

                                
    blkCnt--;
  }

                                                 
  blkCnt = blockSize % 0x4U;

#else

                                                
  blkCnt = blockSize;

#endif                                        

  while (blkCnt > 0U)
  {
                                                                
    *pScratchOut++ = ((q31_t) *px++ * coeff);

                                
    blkCnt--;
  }

                                   
                                                                         
  coeff = *pCoeffs++;

                                                                              
  readIndex = (int32_t) (S->stateIndex - blockSize) - *pTapDelay++;

                               
  if (readIndex < 0)
  {
    readIndex += (int32_t) delaySize;
  }

                                     
  tapCnt = (uint32_t) numTaps - 2U;

  while (tapCnt > 0U)
  {
                                                     
    py = pState;

                                                          
    arm_circularRead_q15(py, (int32_t) delaySize, &readIndex, 1,
                         pb, pb, (int32_t) blockSize, 1, blockSize);

                                                                
    px = pb;

                                                             
    pScratchOut = pScr2;


#if defined (ARM_MATH_LOOPUNROLL)

                                                      
    blkCnt = blockSize >> 2U;

    while (blkCnt > 0U)
    {
                                       
      *pScratchOut++ += (q31_t) *px++ * coeff;
      *pScratchOut++ += (q31_t) *px++ * coeff;
      *pScratchOut++ += (q31_t) *px++ * coeff;
      *pScratchOut++ += (q31_t) *px++ * coeff;

                                  
      blkCnt--;
    }

                                                   
    blkCnt = blockSize % 0x4U;

#else

                                                  
    blkCnt = blockSize;

#endif                                        

    while (blkCnt > 0U)
    {
                                       
      *pScratchOut++ += (q31_t) *px++ * coeff;

                                  
      blkCnt--;
    }

                                     
                                                                           
    coeff = *pCoeffs++;

                                                                                
    readIndex = (int32_t) (S->stateIndex - blockSize) - *pTapDelay++;

                                 
    if (readIndex < 0)
    {
      readIndex += (int32_t) delaySize;
    }

                                
    tapCnt--;
  }

                                                            

                                                   
  py = pState;

                                                        
  arm_circularRead_q15(py, (int32_t) delaySize, &readIndex, 1,
                       pb, pb, (int32_t) blockSize, 1, blockSize);

                                                              
  px = pb;

                                                           
  pScratchOut = pScr2;


#if defined (ARM_MATH_LOOPUNROLL)

                                                    
  blkCnt = blockSize >> 2U;

  while (blkCnt > 0U)
  {
                                     
    *pScratchOut++ += (q31_t) *px++ * coeff;
    *pScratchOut++ += (q31_t) *px++ * coeff;
    *pScratchOut++ += (q31_t) *px++ * coeff;
    *pScratchOut++ += (q31_t) *px++ * coeff;

                                
    blkCnt--;
  }

                                                 
  blkCnt = blockSize % 0x4U;

#else

                                                
  blkCnt = blockSize;

#endif                                        

  while (blkCnt > 0U)
  {
                                     
    *pScratchOut++ += (q31_t) *px++ * coeff;

                                
    blkCnt--;
  }

                                                     
                                                                                    
#if defined (ARM_MATH_LOOPUNROLL)

                                                    
  blkCnt = blockSize >> 2U;

  while (blkCnt > 0U)
  {
    in1 = *pScr2++;
    in2 = *pScr2++;

#ifndef ARM_MATH_BIG_ENDIAN
    write_q15x2_ia (&pOut, __PKHBT((q15_t) __SSAT(in1 >> 15, 16), (q15_t) __SSAT(in2 >> 15, 16), 16));
#else
    write_q15x2_ia (&pOut, __PKHBT((q15_t) __SSAT(in2 >> 15, 16), (q15_t) __SSAT(in1 >> 15, 16), 16));
#endif                                  

    in1 = *pScr2++;
    in2 = *pScr2++;

#ifndef ARM_MATH_BIG_ENDIAN
    write_q15x2_ia (&pOut, __PKHBT((q15_t) __SSAT(in1 >> 15, 16), (q15_t) __SSAT(in2 >> 15, 16), 16));
#else
    write_q15x2_ia (&pOut, __PKHBT((q15_t) __SSAT(in2 >> 15, 16), (q15_t) __SSAT(in1 >> 15, 16), 16));
#endif                                  

                                
    blkCnt--;
  }

                                                 
  blkCnt = blockSize % 0x4U;

#else

                                                
  blkCnt = blockSize;

#endif                                        

  while (blkCnt > 0U)
  {
    *pOut++ = (q15_t) __SSAT(*pScr2++ >> 15, 16);

                                
    blkCnt--;
  }

}

   
                            
   
