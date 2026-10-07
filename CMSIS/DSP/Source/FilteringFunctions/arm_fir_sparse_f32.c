                                                                         
                                  
                                     
                                                                     
  
                               
                       
  
                                   
                                                                          
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

   
                       
   

   
                                                                   

                                                        
                                                                                                                   
                                                                                              

                                                                               
                                                                                                   
                                                                           
                                                                                                            

                          
                                                                                                                                                                          
                                                                               
                                                                                                                          
       
                                                                                                                                           
        
      
                                                                                                          
      
                                                                                                   
                                                                                                                         
                                                                                                               
                                                                                                                           
                                                                                           

                                   
                                                                                                                       
                                                                                 
                                                                                                                                    
                                                                                                             

                                         
                                                                                          
                                                                                 
                                                                      
                                                              
                                                                                                                                
                                                                                                                           
      
                                                                  
                                                                                                                                           
                                                                                                                                 
                                                                                            
                                                                                                                     
       
                                                                                         
                                                                                         
                                                                                         
                                                                                         
        

                                     
                                                                                                             
                                                                                                                                   
                                                                                           
   

   
                        
    
   

   
                                                                              
                                                                                             
                                                              
                                                               
                                                                           
                                                               
                     
   

void arm_fir_sparse_f32(
        arm_fir_sparse_instance_f32 * S,
  const float32_t * pSrc,
        float32_t * pDst,
        float32_t * pScratchIn,
        uint32_t blockSize)
{
        float32_t *pState = S->pState;                                    
  const float32_t *pCoeffs = S->pCoeffs;                                        
        float32_t *px;                                                             
        float32_t *py = pState;                                                                 
        float32_t *pb = pScratchIn;                                                               
        float32_t *pOut;                                                        
        int32_t *pTapDelay = S->pTapDelay;                                                                                     
        uint32_t delaySize = S->maxDelay + blockSize;                    
        uint16_t numTaps = S->numTaps;                                                                   
        int32_t readIndex;                                                                 
        uint32_t tapCnt, blkCnt;                                          
        float32_t coeff = *pCoeffs++;                                                        


                                                                   
                                                                               
  arm_circularWrite_f32((int32_t *) py, delaySize, &S->stateIndex, 1, (int32_t *) pSrc, 1, blockSize);

                                                                              
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
                                                                 
    *pOut++ = *px++ * coeff;

    *pOut++ = *px++ * coeff;

    *pOut++ = *px++ * coeff;

    *pOut++ = *px++ * coeff;

                                
    blkCnt--;
  }

                                                 
  blkCnt = blockSize % 0x4U;

#else

                                                
  blkCnt = blockSize;

#endif                                        

  while (blkCnt > 0U)
  {
                                                                
    *pOut++ = *px++ * coeff;

                                
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
                                       
      *pOut++ += *px++ * coeff;

      *pOut++ += *px++ * coeff;

      *pOut++ += *px++ * coeff;

      *pOut++ += *px++ * coeff;

                                  
      blkCnt--;
    }

                                                   
    blkCnt = blockSize % 0x4U;

#else

                                                  
    blkCnt = blockSize;

#endif                                        

    while (blkCnt > 0U)
    {
                                       
      *pOut++ += *px++ * coeff;

                                  
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
                                     
    *pOut++ += *px++ * coeff;
    *pOut++ += *px++ * coeff;
    *pOut++ += *px++ * coeff;
    *pOut++ += *px++ * coeff;

                                
    blkCnt--;
  }

                                                 
  blkCnt = blockSize % 0x4U;

#else

                                                
  blkCnt = blockSize;

#endif                                        

  while (blkCnt > 0U)
  {
                                     
    *pOut++ += *px++ * coeff;

                                
    blkCnt--;
  }

}

   
                            
   
