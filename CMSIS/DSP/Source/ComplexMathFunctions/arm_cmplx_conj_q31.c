                                                                         
                                  
                                     
                                      
  
                               
                       
  
                                   
                                                                          
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

   
                         
   

   
                        
    
   

   
                                       
                                                       
                                                        
                                                             
                     

                                              
                                                           
                                                                                                                 
   

void arm_cmplx_conj_q31(
  const q31_t * pSrc,
        q31_t * pDst,
        uint32_t numSamples)
{
        uint32_t blkCnt;                                                 
        q31_t in;                                                                    

#if defined (ARM_MATH_LOOPUNROLL)

                                                   
  blkCnt = numSamples >> 2U;

  while (blkCnt > 0U)
  {
                                        

                                                                             
    *pDst++ =  *pSrc++;
    in = *pSrc++;
#if defined (ARM_MATH_DSP)
    *pDst++ = __QSUB(0, in);
#else
    *pDst++ = (in == INT32_MIN) ? INT32_MAX : -in;
#endif

    *pDst++ =  *pSrc++;
    in =  *pSrc++;
#if defined (ARM_MATH_DSP)
    *pDst++ = __QSUB(0, in);
#else
    *pDst++ = (in == INT32_MIN) ? INT32_MAX : -in;
#endif

    *pDst++ =  *pSrc++;
    in = *pSrc++;
#if defined (ARM_MATH_DSP)
    *pDst++ = __QSUB(0, in);
#else
    *pDst++ = (in == INT32_MIN) ? INT32_MAX : -in;
#endif

    *pDst++ =  *pSrc++;
    in = *pSrc++;
#if defined (ARM_MATH_DSP)
    *pDst++ = __QSUB(0, in);
#else
    *pDst++ = (in == INT32_MIN) ? INT32_MAX : -in;
#endif

                                
    blkCnt--;
  }

                                                 
  blkCnt = numSamples % 0x4U;

#else

                                                
  blkCnt = numSamples;

#endif                                        

  while (blkCnt > 0U)
  {
                                        

                                                                             
    *pDst++ =  *pSrc++;
    in = *pSrc++;
#if defined (ARM_MATH_DSP)
    *pDst++ = __QSUB(0, in);
#else
    *pDst++ = (in == INT32_MIN) ? INT32_MAX : -in;
#endif

                                
    blkCnt--;
  }

}

   
                            
   
