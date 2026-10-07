                                                                         
                                  
                                     
                                                          
  
                               
                       
  
                                   
                                                                          
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

   
                       
   

   
                        
    
   

   
                                                                   
                                                                                  
                                                              
                                                               
                                                                           
                                                               
                     

                                              
                                                                                    
                                                                                
                                                                                                                            
                                                                                             
                                                                                                                          
   

void arm_fir_sparse_q31(
        arm_fir_sparse_instance_q31 * S,
  const q31_t * pSrc,
        q31_t * pDst,
        q31_t * pScratchIn,
        uint32_t blockSize)
{
        q31_t *pState = S->pState;                                        
  const q31_t *pCoeffs = S->pCoeffs;                                            
        q31_t *px;                                                                 
        q31_t *py = pState;                                                                     
        q31_t *pb = pScratchIn;                                                                   
        q31_t *pOut;                                                            
        int32_t *pTapDelay = S->pTapDelay;                                                                                     
        uint32_t delaySize = S->maxDelay + blockSize;                    
        uint16_t numTaps = S->numTaps;                                                                   
        int32_t readIndex;                                                                 
        uint32_t tapCnt, blkCnt;                                          
        q31_t coeff = *pCoeffs++;                                                            
        q31_t in;
        q63_t out;                                                                    


                                                                   
                                                                               
  arm_circularWrite_f32((int32_t *) py, delaySize, &S->stateIndex, 1,
                        (int32_t *) pSrc, 1, blockSize);

                                                                              
  readIndex = (int32_t) (S->stateIndex - blockSize) - *pTapDelay++;

                               
  if (readIndex < 0)
  {
    readIndex += (int32_t) delaySize;
  }

                                                   
  py = pState;

                                                        
  arm_circularRead_f32((int32_t *) py, delaySize, &readIndex, 1,
                       (int32_t *) pb, (int32_t *) pb, blockSize, 1, blockSize);

                                                              
  px = pb;

                                                           
  pOut = pDst;


#if defined (ARM_MATH_LOOPUNROLL)

                                                    
  blkCnt = blockSize >> 2U;

  while (blkCnt > 0U)
  {
                                                                 
    *pOut++ = (q31_t) (((q63_t) *px++ * coeff) >> 32);

    *pOut++ = (q31_t) (((q63_t) *px++ * coeff) >> 32);

    *pOut++ = (q31_t) (((q63_t) *px++ * coeff) >> 32);

    *pOut++ = (q31_t) (((q63_t) *px++ * coeff) >> 32);

                                
    blkCnt--;
  }

                                                 
  blkCnt = blockSize % 0x4U;

#else

                                                
  blkCnt = blockSize;

#endif                                        

  while (blkCnt > 0U)
  {
                                                                
    *pOut++ = (q31_t) (((q63_t) *px++ * coeff) >> 32);

                                
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

                                                          
    arm_circularRead_f32((int32_t *) py, delaySize, &readIndex, 1,
                         (int32_t *) pb, (int32_t *) pb, blockSize, 1, blockSize);

                                                                
    px = pb;

                                                             
    pOut = pDst;


#if defined (ARM_MATH_LOOPUNROLL)

                                                      
    blkCnt = blockSize >> 2U;

    while (blkCnt > 0U)
    {
                                       
      out = *pOut;
      out += ((q63_t) *px++ * coeff) >> 32;
      *pOut++ = (q31_t) (out);

      out = *pOut;
      out += ((q63_t) *px++ * coeff) >> 32;
      *pOut++ = (q31_t) (out);

      out = *pOut;
      out += ((q63_t) *px++ * coeff) >> 32;
      *pOut++ = (q31_t) (out);

      out = *pOut;
      out += ((q63_t) *px++ * coeff) >> 32;
      *pOut++ = (q31_t) (out);

                                  
      blkCnt--;
    }

                                                   
    blkCnt = blockSize % 0x4U;

#else

                                                  
    blkCnt = blockSize;

#endif                                        

    while (blkCnt > 0U)
    {
                                       
      out = *pOut;
      out += ((q63_t) *px++ * coeff) >> 32;
      *pOut++ = (q31_t) (out);

                                  
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

                                                        
  arm_circularRead_f32((int32_t *) py, delaySize, &readIndex, 1,
                       (int32_t *) pb, (int32_t *) pb, blockSize, 1, blockSize);

                                                              
  px = pb;

                                                           
  pOut = pDst;


#if defined (ARM_MATH_LOOPUNROLL)

                                                    
  blkCnt = blockSize >> 2U;

  while (blkCnt > 0U)
  {
                                     
    out = *pOut;
    out += ((q63_t) * px++ * coeff) >> 32;
    *pOut++ = (q31_t) (out);

    out = *pOut;
    out += ((q63_t) * px++ * coeff) >> 32;
    *pOut++ = (q31_t) (out);

    out = *pOut;
    out += ((q63_t) * px++ * coeff) >> 32;
    *pOut++ = (q31_t) (out);

    out = *pOut;
    out += ((q63_t) * px++ * coeff) >> 32;
    *pOut++ = (q31_t) (out);

                                
    blkCnt--;
  }

                                                 
  blkCnt = blockSize % 0x4U;

#else

                                                
  blkCnt = blockSize;

#endif                                        

  while (blkCnt > 0U)
  {
                                     
    out = *pOut;
    out += ((q63_t) *px++ * coeff) >> 32;
    *pOut++ = (q31_t) (out);

                                
    blkCnt--;
  }

                                         
  pOut = pDst;

                                             
#if defined (ARM_MATH_LOOPUNROLL)

                                                    
  blkCnt = blockSize >> 2U;

  while (blkCnt > 0U)
  {
    in = *pOut << 1;
    *pOut++ = in;
    in = *pOut << 1;
    *pOut++ = in;
    in = *pOut << 1;
    *pOut++ = in;
    in = *pOut << 1;
    *pOut++ = in;

                                
    blkCnt--;
  }

                                                 
  blkCnt = blockSize % 0x4U;

#else

                                                
  blkCnt = blockSize;

#endif                                        

  while (blkCnt > 0U)
  {
    in = *pOut << 1;
    *pOut++ = in;

                                
    blkCnt--;
  }

}

   
                            
   
