                                                                         
                                  
                                    
                                                         
  
                               
                       
  
                                   
                                                                          
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

   
                       
   

   
                        
    
   

   
                                                                  
                                                                                 
                                                              
                                                               
                                                                           
                                                                           
                                                               
                     

                                              
                                                                                   
                                                                                                                               
                                                                                                         
                                                                                                                                                
                                                                                                 
                                                                  
   

void arm_fir_sparse_q7(
        arm_fir_sparse_instance_q7 * S,
  const q7_t * pSrc,
        q7_t * pDst,
        q7_t * pScratchIn,
        q31_t * pScratchOut,
        uint32_t blockSize)
{
        q7_t *pState = S->pState;                                         
  const q7_t *pCoeffs = S->pCoeffs;                                             
        q7_t *px;                                                                  
        q7_t *py = pState;                                                                      
        q7_t *pb = pScratchIn;                                                                    
        q7_t *pOut = pDst;                                                      
        int32_t *pTapDelay = S->pTapDelay;                                                                                     
        uint32_t delaySize = S->maxDelay + blockSize;                    
        uint16_t numTaps = S->numTaps;                                                                   
        int32_t readIndex;                                                                 
        uint32_t tapCnt, blkCnt;                                          
        q31_t *pScr2 = pScratchOut;                                                                             
        q31_t in;
        q7_t coeff = *pCoeffs++;                                                       

#if defined (ARM_MATH_LOOPUNROLL)
        q7_t in1, in2, in3, in4;
#endif

                                                                   
                                                                               
  arm_circularWrite_q7(py, (int32_t) delaySize, &S->stateIndex, 1, pSrc, 1, blockSize);

                                     
  tapCnt = numTaps;

                                                                              
  readIndex = (int32_t) (S->stateIndex - blockSize) - *pTapDelay++;

                               
  if (readIndex < 0)
  {
    readIndex += (int32_t) delaySize;
  }

                                                   
  py = pState;

                                                        
  arm_circularRead_q7(py, (int32_t) delaySize, &readIndex, 1,
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

                                                          
    arm_circularRead_q7(py, (int32_t) delaySize, &readIndex, 1,
                        pb, pb, (int32_t) blockSize, 1, blockSize);

                                                                
    px = pb;

                                                             
    pScratchOut = pScr2;


#if defined (ARM_MATH_LOOPUNROLL)

                                                      
    blkCnt = blockSize >> 2U;

    while (blkCnt > 0U)
    {
                                       
      in = *pScratchOut + ((q31_t) * px++ * coeff);
      *pScratchOut++ = in;
      in = *pScratchOut + ((q31_t) * px++ * coeff);
      *pScratchOut++ = in;
      in = *pScratchOut + ((q31_t) * px++ * coeff);
      *pScratchOut++ = in;
      in = *pScratchOut + ((q31_t) * px++ * coeff);
      *pScratchOut++ = in;

                                  
      blkCnt--;
    }

                                                   
    blkCnt = blockSize % 0x4U;

#else

                                                  
    blkCnt = blockSize;

#endif                                        

    while (blkCnt > 0U)
    {
                                       
      in = *pScratchOut + ((q31_t) *px++ * coeff);
      *pScratchOut++ = in;

                                  
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

                                                        
  arm_circularRead_q7(py, (int32_t) delaySize, &readIndex, 1,
                      pb, pb, (int32_t) blockSize, 1, blockSize);

                                                              
  px = pb;

                                                           
  pScratchOut = pScr2;


#if defined (ARM_MATH_LOOPUNROLL)

                                                    
  blkCnt = blockSize >> 2U;

  while (blkCnt > 0U)
  {
                                     
    in = *pScratchOut + ((q31_t) *px++ * coeff);
    *pScratchOut++ = in;
    in = *pScratchOut + ((q31_t) *px++ * coeff);
    *pScratchOut++ = in;
    in = *pScratchOut + ((q31_t) *px++ * coeff);
    *pScratchOut++ = in;
    in = *pScratchOut + ((q31_t) *px++ * coeff);
    *pScratchOut++ = in;

                                
    blkCnt--;
  }

                                                 
  blkCnt = blockSize % 0x4U;

#else

                                                
  blkCnt = blockSize;

#endif                                        

  while (blkCnt > 0U)
  {
                                     
    in = *pScratchOut + ((q31_t) *px++ * coeff);
    *pScratchOut++ = in;

                                
    blkCnt--;
  }

                                                     
                                                                                    
#if defined (ARM_MATH_LOOPUNROLL)

                                                    
  blkCnt = blockSize >> 2U;

  while (blkCnt > 0U)
  {
    in1 = (q7_t) __SSAT(*pScr2++ >> 7, 8);
    in2 = (q7_t) __SSAT(*pScr2++ >> 7, 8);
    in3 = (q7_t) __SSAT(*pScr2++ >> 7, 8);
    in4 = (q7_t) __SSAT(*pScr2++ >> 7, 8);

    write_q7x4_ia (&pOut, __PACKq7(in1, in2, in3, in4));

                                
    blkCnt--;
  }

                                                 
  blkCnt = blockSize % 0x4U;

#else

                                                
  blkCnt = blockSize;

#endif                                        

  while (blkCnt > 0U)
  {
    *pOut++ = (q7_t) __SSAT(*pScr2++ >> 7, 8);

                                
    blkCnt--;
  }

}

   
                            
   
