/*
 * Copyright (C) 2010-2018 Arm Limited or its affiliates. All rights reserved.
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

                                                                         
                                 
                                         
                                                                             
  
                              
                        
  
                                    
                                                                          

#ifndef _ARM_NNSUPPORTFUNCTIONS_H_
#define _ARM_NNSUPPORTFUNCTIONS_H_

#include "arm_math.h"
#include "arm_common_tables.h"

#ifdef __cplusplus
extern    "C"
{
#endif

#define LEFT_SHIFT(_shift)  (_shift > 0 ? _shift : 0)
#define RIGHT_SHIFT(_shift) (_shift > 0 ? 0 : -_shift)
#define Q31_MIN (0x80000000L)
#define Q31_MAX (0x7FFFFFFFL)

   
                                                   
   
union arm_nnword
{
    q31_t     word;
                               
    q15_t     half_words[2];
                               
    q7_t      bytes[4];
                              
};

   
                                                         
  
   
typedef enum
{
    ARM_SIGMOID = 0,
                                                   
    ARM_TANH = 1,
                                             
} arm_nn_activation_type;

   
                                                                    
  
                                                                    
  
   

   
                                                                                 
                                                       
                                                         
                                                        
                
  
   

void      arm_q7_to_q15_no_shift(const q7_t * pSrc, q15_t * pDst, uint32_t blockSize);

   
                                                                                            
                                                       
                                                         
                                                        
                
  
   

void      arm_q7_to_q15_reordered_no_shift(const q7_t * pSrc, q15_t * pDst, uint32_t blockSize);

#if defined (ARM_MATH_DSP)

   
                                                        
   

__STATIC_FORCEINLINE void *read_and_pad(void *source, q31_t * out1, q31_t * out2)
{
        q31_t     inA = *__SIMD32(source)++;
        q31_t     inAbuf1 = __SXTB16(__ROR(inA, 8));
        q31_t     inAbuf2 = __SXTB16(inA);

#ifndef ARM_MATH_BIG_ENDIAN
        *out2 = __PKHTB(inAbuf1, inAbuf2, 16);
        *out1 = __PKHBT(inAbuf2, inAbuf1, 16);
#else
        *out1 = __PKHTB(inAbuf1, inAbuf2, 16);
        *out2 = __PKHBT(inAbuf2, inAbuf1, 16);
#endif

        return source;
}

   
                                                                        
   

__STATIC_FORCEINLINE void *read_and_pad_reordered(void *source, q31_t * out1, q31_t * out2)
{
        q31_t     inA = *__SIMD32(source)++;
#ifndef ARM_MATH_BIG_ENDIAN
        *out2 = __SXTB16(__ROR(inA, 8));
        *out1 = __SXTB16(inA);
#else
        *out1 = __SXTB16(__ROR(inA, 8));
        *out2 = __SXTB16(inA);
#endif

        return source;
}
#endif

   
                                                                            
  
                                                      
  
   

   
                                                                        
                                                                   
                                                                    
                                                              
                                                                  
                                                                  
                
  
                                        
       
                                           
                                                                                
   

void arm_nn_mult_q15(
  q15_t * pSrcA,
  q15_t * pSrcB,
  q15_t * pDst,
  const uint16_t out_shift,
  uint32_t blockSize);

   
                                                                        
                                                                   
                                                                    
                                                              
                                                                  
                                                                  
                
  
                                        
       
                                           
                                                                           
   

void arm_nn_mult_q7(
  q7_t * pSrcA,
  q7_t * pSrcB,
  q7_t * pDst,
  const uint16_t out_shift,
  uint32_t blockSize);

   
                                          
   
#ifndef ARM_NN_TRUNCATE
    #define NN_ROUND(out_shift) ( (0x1u << out_shift) >> 1 )
#else
    #define NN_ROUND(out_shift) 0
#endif

   
                                                                     
                                              
                                          
                                        
                                             
  
   
__STATIC_FORCEINLINE q31_t arm_nn_sat_doubling_high_mult(const q31_t m1, const q31_t m2)
{
    q31_t result = 0;
                                                     
    q63_t mult = 1 << 30;

    if ((m1 < 0) ^ (m2 < 0))
    {
        mult = 1 - mult;
    }
                                           
    mult = mult + (q63_t)m1 * m2;

                                                                  
               
    result = mult / (1UL << 31);

    if ((m1 == m2) && (m1 == Q31_MIN))
    {
        result = Q31_MAX;
    }
    return result;
}

   
                                                    
                                       
                                                           
                                             
                                                                                   
  
   
__STATIC_FORCEINLINE q31_t arm_nn_divide_by_power_of_two(const q31_t dividend, const q31_t exponent)
{
    q31_t result = 0;
    const q31_t remainder_mask = (1l << exponent) - 1;
    int32_t remainder = remainder_mask & dividend;

                     
    result = dividend >> exponent;

                                                              
    q31_t threshold = remainder_mask >> 1;
    if (result < 0)
    {
        threshold++;
    }
    if (remainder > threshold)
    {
        result++;
    }

    return result;
}

#ifdef __cplusplus
}
#endif

#endif
