                                                                               
                       
                                                     
                   
                           
                                                                                
/*
 * Copyright (c) 2010-2019 Arm Limited or its affiliates. All rights reserved.
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

   
                                       
    
                 
                 
    
                                                               
                                                                                               
    
                                                                                         
                           
                          
                             
              
                       
                          
                              
                            
                        
                              
    
                                                                                         
                                                     
    
                      
                 
    
                                                                                                      
                                                                                                 
                                                                                              
                                                                                                 
                                                                                                    
                                                        
                                                     
                                                                              
                                                                           
                                                        
                                                     
                                                        
                                                     
                                                                     
                                                                  
                                                               
                                                               
                                                                                                        
                                                                                  
                                                                                                                           
    
                                                                                                                                      
                                                                                                                                                      
                                                                                                                                                                           
    
    
             
             
    
                                                                                                    
    
                      
                 
    
                                                                        
                                                                                                                       
    
                         
                 
    
                                                                                                                                              
                               
    
    
                                                                                                                                                                                      
    
                        
                 
    
                                                             
    
                           
    
                                                                                                                                       
    
                             
    
                                                                                              
    
                         
    
                                                                     
    
                           
    
                                                                                      
    
                     
    
                                                                             
                                                                                  
                                                       
    
                                  
    
                                                                                     
                                                                                   
                                           
    
         
                                 
                                  
    
                                                                                                     
                                                                                                                 
                                                                                                                 
                                                                                                                 
                                                                                                                 
                                                                                                                 
                                                                                                                 
                                                                                                                 
                                                                                                                 
                                                                                                                 
    
         
                                  
                 
                                       
     


   
                                           
   

   
                                              
                                                                                        
                                                                                                
                                               
                                                                      
  
   

   
                                                  
                                                          
                                                                     
                                 
                                                                        
                                                                           
               
   

   
                                             
   

   
                                         
  
                                                               
                                                                 
           
                                                              
         
        
                     
        
                                                               
                                                                  
                                                                   
                                 
         
                                                            
  
                                                                    
                                                                         
                                                          
                                      
        
                           
         
  
                      
                                                                         
                  
                                                                                
                                                                                        
                                                        
  
       
                                                                                              
                                                                          
                                                  
                                                                 
        
                                                                     
                                                                     
                                                                     
         
                                                                               
                                                                        
              
  
                     
                                                                                
                                                                               
                                                                                
                                                         
        
                             
         
                                 
        
                       
         
                                                                    
                                                       
        
                            
         
                                                                         
                                                                     
                                                                      
                                                                     
                                        
   

   
                                                
   

   
                                                 
   

   
                                            
   

   
                                           
   

   
                                                       
                                                                      
                                                          
                                                         
   

   
                                   
   


#ifndef _ARM_MATH_H
#define _ARM_MATH_H

                                             
#if   defined ( __CC_ARM )

#elif defined ( __ARMCC_VERSION ) && ( __ARMCC_VERSION >= 6010050 )

#elif defined ( __GNUC__ )
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wsign-conversion"
  #pragma GCC diagnostic ignored "-Wconversion"
  #pragma GCC diagnostic ignored "-Wunused-parameter"

#elif defined ( __ICCARM__ )

#elif defined ( __TI_ARM__ )

#elif defined ( __CSMC__ )

#elif defined ( __TASKING__ )

#elif defined ( _MSC_VER )

#else
  #error Unknown compiler
#endif


                                          
#if !defined ( _MSC_VER )
#include "cmsis_compiler.h"
#else
#include <stdint.h>
#define __STATIC_FORCEINLINE static __forceinline
#define __ALIGNED(x) __declspec(align(x))
#define LOW_OPTIMIZATION_ENTER
#define LOW_OPTIMIZATION_EXIT
#define IAR_ONLY_LOW_OPTIMIZATION_ENTER 
#define IAR_ONLY_LOW_OPTIMIZATION_EXIT
#endif

#include "string.h"
#include "math.h"
#include "float.h"

                              
#if (defined (__ARM_FEATURE_DSP) && (__ARM_FEATURE_DSP == 1))
  #define ARM_MATH_DSP                   1
#endif

#if defined(__ARM_NEON)
#include <arm_neon.h>
#endif


#ifdef   __cplusplus
extern "C"
{
#endif


     
                                                                        
     

#define DELTA_Q31          (0x100)
#define DELTA_Q15          0x5
#define INDEX_MASK         0x0000003F
#ifndef PI
  #define PI               3.14159265358979f
#endif

     
                                                                        
     

#define FAST_MATH_TABLE_SIZE  512
#define FAST_MATH_Q31_SHIFT   (32 - 10)
#define FAST_MATH_Q15_SHIFT   (16 - 10)
#define CONTROLLER_Q31_SHIFT  (32 - 9)
#define TABLE_SPACING_Q31     0x400000
#define TABLE_SPACING_Q15     0x80

     
                                                                    
     
                                      
                                                                       
#define INPUT_SPACING         0xB60B61


     
                                                                   
     

  typedef enum
  {
    ARM_MATH_SUCCESS        =  0,                        
    ARM_MATH_ARGUMENT_ERROR = -1,                                                   
    ARM_MATH_LENGTH_ERROR   = -2,                                                  
    ARM_MATH_SIZE_MISMATCH  = -3,                                                                     
    ARM_MATH_NANINF         = -4,                                                           
    ARM_MATH_SINGULAR       = -5,                                                               
    ARM_MATH_TEST_FAILURE   = -6                            
  } arm_status;

     
                                                     
     
  typedef int8_t q7_t;

     
                                                       
     
  typedef int16_t q15_t;

     
                                                       
     
  typedef int32_t q31_t;

     
                                                       
     
  typedef int64_t q63_t;

     
                                                  
     
  typedef float float32_t;

     
                                                  
     
  typedef double float64_t;


   
                                                    
             
   
#if   defined ( __CC_ARM )
  #define __SIMD32_TYPE int32_t __packed
#elif defined ( __ARMCC_VERSION ) && ( __ARMCC_VERSION >= 6010050 )
  #define __SIMD32_TYPE int32_t
#elif defined ( __GNUC__ )
  #define __SIMD32_TYPE int32_t
#elif defined ( __ICCARM__ )
  #define __SIMD32_TYPE int32_t __packed
#elif defined ( __TI_ARM__ )
  #define __SIMD32_TYPE int32_t
#elif defined ( __CSMC__ )
  #define __SIMD32_TYPE int32_t
#elif defined ( __TASKING__ )
  #define __SIMD32_TYPE __un(aligned) int32_t
#elif defined(_MSC_VER )
  #define __SIMD32_TYPE int32_t
#else
  #error Unknown compiler
#endif

#define __SIMD32(addr)        (*(__SIMD32_TYPE **) & (addr))
#define __SIMD32_CONST(addr)  ( (__SIMD32_TYPE * )   (addr))
#define _SIMD32_OFFSET(addr)  (*(__SIMD32_TYPE * )   (addr))
#define __SIMD64(addr)        (*(      int64_t **) & (addr))

                      


   
                                             
                                                
                          
   
__STATIC_FORCEINLINE q31_t read_q15x2 (
  q15_t * pQ15)
{
  q31_t val;

  memcpy (&val, pQ15, 4);

  return (val);
}

   
                                                                              
                                                
                          
   
__STATIC_FORCEINLINE q31_t read_q15x2_ia (
  q15_t ** pQ15)
{
  q31_t val;

  memcpy (&val, *pQ15, 4);
  *pQ15 += 2;

  return (val);
}

   
                                                                              
                                                
                          
   
__STATIC_FORCEINLINE q31_t read_q15x2_da (
  q15_t ** pQ15)
{
  q31_t val;

  memcpy (&val, *pQ15, 4);
  *pQ15 -= 2;

  return (val);
}

   
                                                                             
                                                
                                    
                     
   
__STATIC_FORCEINLINE void write_q15x2_ia (
  q15_t ** pQ15,
  q31_t    value)
{
  q31_t val = value;

  memcpy (*pQ15, &val, 4);
  *pQ15 += 2;
}

   
                                            
                                                
                                    
                     
   
__STATIC_FORCEINLINE void write_q15x2 (
  q15_t * pQ15,
  q31_t   value)
{
  q31_t val = value;

  memcpy (pQ15, &val, 4);
}


   
                                                                            
                                                
                          
   
__STATIC_FORCEINLINE q31_t read_q7x4_ia (
  q7_t ** pQ7)
{
  q31_t val;

  memcpy (&val, *pQ7, 4);
  *pQ7 += 4;

  return (val);
}

   
                                                                            
                                                
                          
   
__STATIC_FORCEINLINE q31_t read_q7x4_da (
  q7_t ** pQ7)
{
  q31_t val;

  memcpy (&val, *pQ7, 4);
  *pQ7 -= 4;

  return (val);
}

   
                                                                           
                                                
                                    
                     
   
__STATIC_FORCEINLINE void write_q7x4_ia (
  q7_t ** pQ7,
  q31_t   value)
{
  q31_t val = value;

  memcpy (*pQ7, &val, 4);
  *pQ7 += 4;
}

  

                                                         
                  

                                                                    
                                                                 
                              

                                                                       
                                                     

  
#if defined ( _MSC_VER )
    __STATIC_FORCEINLINE uint8_t __CLZ(uint32_t data)
    {
      if (data == 0U) { return 32U; }

      uint32_t count = 0U;
      uint32_t mask = 0x80000000U;

      while ((data & mask) == 0U)
      {
        count += 1U;
        mask = mask >> 1U;
      }
      return count;
    }

  __STATIC_FORCEINLINE int32_t __SSAT(int32_t val, uint32_t sat)
  {
    if ((sat >= 1U) && (sat <= 32U))
    {
      const int32_t max = (int32_t)((1U << (sat - 1U)) - 1U);
      const int32_t min = -1 - max ;
      if (val > max)
      {
        return max;
      }
      else if (val < min)
      {
        return min;
      }
    }
    return val;
  }

  __STATIC_FORCEINLINE uint32_t __USAT(int32_t val, uint32_t sat)
  {
    if (sat <= 31U)
    {
      const uint32_t max = ((1U << sat) - 1U);
      if (val > (int32_t)max)
      {
        return max;
      }
      else if (val < 0)
      {
        return 0U;
      }
    }
    return (uint32_t)val;
  }
#endif

#ifndef ARM_MATH_DSP
     
                                                 
     
  #define __PKHBT(ARG1, ARG2, ARG3) ( (((int32_t)(ARG1) <<    0) & (int32_t)0x0000FFFF) | \
                                      (((int32_t)(ARG2) << ARG3) & (int32_t)0xFFFF0000)  )
  #define __PKHTB(ARG1, ARG2, ARG3) ( (((int32_t)(ARG1) <<    0) & (int32_t)0xFFFF0000) | \
                                      (((int32_t)(ARG2) >> ARG3) & (int32_t)0x0000FFFF)  )
#endif

      
                                                 
     
#ifndef ARM_MATH_BIG_ENDIAN
  #define __PACKq7(v0,v1,v2,v3) ( (((int32_t)(v0) <<  0) & (int32_t)0x000000FF) | \
                                  (((int32_t)(v1) <<  8) & (int32_t)0x0000FF00) | \
                                  (((int32_t)(v2) << 16) & (int32_t)0x00FF0000) | \
                                  (((int32_t)(v3) << 24) & (int32_t)0xFF000000)  )
#else
  #define __PACKq7(v0,v1,v2,v3) ( (((int32_t)(v3) <<  0) & (int32_t)0x000000FF) | \
                                  (((int32_t)(v2) <<  8) & (int32_t)0x0000FF00) | \
                                  (((int32_t)(v1) << 16) & (int32_t)0x00FF0000) | \
                                  (((int32_t)(v0) << 24) & (int32_t)0xFF000000)  )
#endif


     
                                    
     
  __STATIC_FORCEINLINE q31_t clip_q63_to_q31(
  q63_t x)
  {
    return ((q31_t) (x >> 32) != ((q31_t) x >> 31)) ?
      ((0x7FFFFFFF ^ ((q31_t) (x >> 63)))) : (q31_t) x;
  }

     
                                    
     
  __STATIC_FORCEINLINE q15_t clip_q63_to_q15(
  q63_t x)
  {
    return ((q31_t) (x >> 32) != ((q31_t) x >> 31)) ?
      ((0x7FFF ^ ((q15_t) (x >> 63)))) : (q15_t) (x >> 15);
  }

     
                                   
     
  __STATIC_FORCEINLINE q7_t clip_q31_to_q7(
  q31_t x)
  {
    return ((q31_t) (x >> 24) != ((q31_t) x >> 23)) ?
      ((0x7F ^ ((q7_t) (x >> 31)))) : (q7_t) x;
  }

     
                                    
     
  __STATIC_FORCEINLINE q15_t clip_q31_to_q15(
  q31_t x)
  {
    return ((q31_t) (x >> 16) != ((q31_t) x >> 15)) ?
      ((0x7FFF ^ ((q15_t) (x >> 31)))) : (q15_t) x;
  }

     
                                                                        
     
  __STATIC_FORCEINLINE q63_t mult32x64(
  q63_t x,
  q31_t y)
  {
    return ((((q63_t) (x & 0x00000000FFFFFFFF) * y) >> 32) +
            (((q63_t) (x >> 32)                * y)      )  );
  }

     
                                                                            
     
  __STATIC_FORCEINLINE uint32_t arm_recip_q31(
        q31_t in,
        q31_t * dst,
  const q31_t * pRecipTable)
  {
    q31_t out;
    uint32_t tempVal;
    uint32_t index, i;
    uint32_t signBits;

    if (in > 0)
    {
      signBits = ((uint32_t) (__CLZ( in) - 1));
    }
    else
    {
      signBits = ((uint32_t) (__CLZ(-in) - 1));
    }

                                             
    in = (in << signBits);

                                                           
    index = (uint32_t)(in >> 24);
    index = (index & INDEX_MASK);

                         
    out = pRecipTable[index];

                                         
                                                  
    for (i = 0U; i < 2U; i++)
    {
      tempVal = (uint32_t) (((q63_t) in * out) >> 31);
      tempVal = 0x7FFFFFFFu - tempVal;
                                
                                                          
      out = clip_q63_to_q31(((q63_t) out * tempVal) >> 30);
    }

                      
    *dst = out;

                                                    
    return (signBits + 1U);
  }


     
                                                                            
     
  __STATIC_FORCEINLINE uint32_t arm_recip_q15(
        q15_t in,
        q15_t * dst,
  const q15_t * pRecipTable)
  {
    q15_t out = 0;
    uint32_t tempVal = 0;
    uint32_t index = 0, i = 0;
    uint32_t signBits = 0;

    if (in > 0)
    {
      signBits = ((uint32_t)(__CLZ( in) - 17));
    }
    else
    {
      signBits = ((uint32_t)(__CLZ(-in) - 17));
    }

                                             
    in = (in << signBits);

                                                           
    index = (uint32_t)(in >>  8);
    index = (index & INDEX_MASK);

                               
    out = pRecipTable[index];

                                         
                                                  
    for (i = 0U; i < 2U; i++)
    {
      tempVal = (uint32_t) (((q31_t) in * out) >> 15);
      tempVal = 0x7FFFu - tempVal;
                                
      out = (q15_t) (((q31_t) out * tempVal) >> 14);
                                                                 
    }

                      
    *dst = out;

                                                    
    return (signBits + 1);
  }

#if defined(ARM_MATH_NEON)

static inline float32x4_t __arm_vec_sqrt_f32_neon(float32x4_t  x)
{
    float32x4_t x1 = vmaxq_f32(x, vdupq_n_f32(FLT_MIN));
    float32x4_t e = vrsqrteq_f32(x1);
    e = vmulq_f32(vrsqrtsq_f32(vmulq_f32(x1, e), e), e);
    e = vmulq_f32(vrsqrtsq_f32(vmulq_f32(x1, e), e), e);
    return vmulq_f32(x, e);
}

static inline int16x8_t __arm_vec_sqrt_q15_neon(int16x8_t vec)
{
    float32x4_t tempF;
    int32x4_t tempHI,tempLO;

    tempLO = vmovl_s16(vget_low_s16(vec));
    tempF = vcvtq_n_f32_s32(tempLO,15);
    tempF = __arm_vec_sqrt_f32_neon(tempF);
    tempLO = vcvtq_n_s32_f32(tempF,15);

    tempHI = vmovl_s16(vget_high_s16(vec));
    tempF = vcvtq_n_f32_s32(tempHI,15);
    tempF = __arm_vec_sqrt_f32_neon(tempF);
    tempHI = vcvtq_n_s32_f32(tempF,15);

    return(vcombine_s16(vqmovn_s32(tempLO),vqmovn_s32(tempHI)));
}

static inline int32x4_t __arm_vec_sqrt_q31_neon(int32x4_t vec)
{
  float32x4_t temp;

  temp = vcvtq_n_f32_s32(vec,31);
  temp = __arm_vec_sqrt_f32_neon(temp);
  return(vcvtq_n_s32_f32(temp,31));
}

#endif

  
                                              
   
#if !defined (ARM_MATH_DSP)

    
                                  
     
  __STATIC_FORCEINLINE uint32_t __QADD8(
  uint32_t x,
  uint32_t y)
  {
    q31_t r, s, t, u;

    r = __SSAT(((((q31_t)x << 24) >> 24) + (((q31_t)y << 24) >> 24)), 8) & (int32_t)0x000000FF;
    s = __SSAT(((((q31_t)x << 16) >> 24) + (((q31_t)y << 16) >> 24)), 8) & (int32_t)0x000000FF;
    t = __SSAT(((((q31_t)x <<  8) >> 24) + (((q31_t)y <<  8) >> 24)), 8) & (int32_t)0x000000FF;
    u = __SSAT(((((q31_t)x      ) >> 24) + (((q31_t)y      ) >> 24)), 8) & (int32_t)0x000000FF;

    return ((uint32_t)((u << 24) | (t << 16) | (s <<  8) | (r      )));
  }


    
                                  
     
  __STATIC_FORCEINLINE uint32_t __QSUB8(
  uint32_t x,
  uint32_t y)
  {
    q31_t r, s, t, u;

    r = __SSAT(((((q31_t)x << 24) >> 24) - (((q31_t)y << 24) >> 24)), 8) & (int32_t)0x000000FF;
    s = __SSAT(((((q31_t)x << 16) >> 24) - (((q31_t)y << 16) >> 24)), 8) & (int32_t)0x000000FF;
    t = __SSAT(((((q31_t)x <<  8) >> 24) - (((q31_t)y <<  8) >> 24)), 8) & (int32_t)0x000000FF;
    u = __SSAT(((((q31_t)x      ) >> 24) - (((q31_t)y      ) >> 24)), 8) & (int32_t)0x000000FF;

    return ((uint32_t)((u << 24) | (t << 16) | (s <<  8) | (r      )));
  }


    
                                   
     
  __STATIC_FORCEINLINE uint32_t __QADD16(
  uint32_t x,
  uint32_t y)
  {
                                                                                                                 
    q31_t r = 0, s = 0;

    r = __SSAT(((((q31_t)x << 16) >> 16) + (((q31_t)y << 16) >> 16)), 16) & (int32_t)0x0000FFFF;
    s = __SSAT(((((q31_t)x      ) >> 16) + (((q31_t)y      ) >> 16)), 16) & (int32_t)0x0000FFFF;

    return ((uint32_t)((s << 16) | (r      )));
  }


    
                                    
     
  __STATIC_FORCEINLINE uint32_t __SHADD16(
  uint32_t x,
  uint32_t y)
  {
    q31_t r, s;

    r = (((((q31_t)x << 16) >> 16) + (((q31_t)y << 16) >> 16)) >> 1) & (int32_t)0x0000FFFF;
    s = (((((q31_t)x      ) >> 16) + (((q31_t)y      ) >> 16)) >> 1) & (int32_t)0x0000FFFF;

    return ((uint32_t)((s << 16) | (r      )));
  }


    
                                   
     
  __STATIC_FORCEINLINE uint32_t __QSUB16(
  uint32_t x,
  uint32_t y)
  {
    q31_t r, s;

    r = __SSAT(((((q31_t)x << 16) >> 16) - (((q31_t)y << 16) >> 16)), 16) & (int32_t)0x0000FFFF;
    s = __SSAT(((((q31_t)x      ) >> 16) - (((q31_t)y      ) >> 16)), 16) & (int32_t)0x0000FFFF;

    return ((uint32_t)((s << 16) | (r      )));
  }


    
                                    
     
  __STATIC_FORCEINLINE uint32_t __SHSUB16(
  uint32_t x,
  uint32_t y)
  {
    q31_t r, s;

    r = (((((q31_t)x << 16) >> 16) - (((q31_t)y << 16) >> 16)) >> 1) & (int32_t)0x0000FFFF;
    s = (((((q31_t)x      ) >> 16) - (((q31_t)y      ) >> 16)) >> 1) & (int32_t)0x0000FFFF;

    return ((uint32_t)((s << 16) | (r      )));
  }


    
                                 
     
  __STATIC_FORCEINLINE uint32_t __QASX(
  uint32_t x,
  uint32_t y)
  {
    q31_t r, s;

    r = __SSAT(((((q31_t)x << 16) >> 16) - (((q31_t)y      ) >> 16)), 16) & (int32_t)0x0000FFFF;
    s = __SSAT(((((q31_t)x      ) >> 16) + (((q31_t)y << 16) >> 16)), 16) & (int32_t)0x0000FFFF;

    return ((uint32_t)((s << 16) | (r      )));
  }


    
                                  
     
  __STATIC_FORCEINLINE uint32_t __SHASX(
  uint32_t x,
  uint32_t y)
  {
    q31_t r, s;

    r = (((((q31_t)x << 16) >> 16) - (((q31_t)y      ) >> 16)) >> 1) & (int32_t)0x0000FFFF;
    s = (((((q31_t)x      ) >> 16) + (((q31_t)y << 16) >> 16)) >> 1) & (int32_t)0x0000FFFF;

    return ((uint32_t)((s << 16) | (r      )));
  }


    
                                 
     
  __STATIC_FORCEINLINE uint32_t __QSAX(
  uint32_t x,
  uint32_t y)
  {
    q31_t r, s;

    r = __SSAT(((((q31_t)x << 16) >> 16) + (((q31_t)y      ) >> 16)), 16) & (int32_t)0x0000FFFF;
    s = __SSAT(((((q31_t)x      ) >> 16) - (((q31_t)y << 16) >> 16)), 16) & (int32_t)0x0000FFFF;

    return ((uint32_t)((s << 16) | (r      )));
  }


    
                                  
     
  __STATIC_FORCEINLINE uint32_t __SHSAX(
  uint32_t x,
  uint32_t y)
  {
    q31_t r, s;

    r = (((((q31_t)x << 16) >> 16) + (((q31_t)y      ) >> 16)) >> 1) & (int32_t)0x0000FFFF;
    s = (((((q31_t)x      ) >> 16) - (((q31_t)y << 16) >> 16)) >> 1) & (int32_t)0x0000FFFF;

    return ((uint32_t)((s << 16) | (r      )));
  }


    
                                   
     
  __STATIC_FORCEINLINE uint32_t __SMUSDX(
  uint32_t x,
  uint32_t y)
  {
    return ((uint32_t)(((((q31_t)x << 16) >> 16) * (((q31_t)y      ) >> 16)) -
                       ((((q31_t)x      ) >> 16) * (((q31_t)y << 16) >> 16))   ));
  }

    
                                   
     
  __STATIC_FORCEINLINE uint32_t __SMUADX(
  uint32_t x,
  uint32_t y)
  {
    return ((uint32_t)(((((q31_t)x << 16) >> 16) * (((q31_t)y      ) >> 16)) +
                       ((((q31_t)x      ) >> 16) * (((q31_t)y << 16) >> 16))   ));
  }


    
                                 
     
  __STATIC_FORCEINLINE int32_t __QADD(
  int32_t x,
  int32_t y)
  {
    return ((int32_t)(clip_q63_to_q31((q63_t)x + (q31_t)y)));
  }


    
                                 
     
  __STATIC_FORCEINLINE int32_t __QSUB(
  int32_t x,
  int32_t y)
  {
    return ((int32_t)(clip_q63_to_q31((q63_t)x - (q31_t)y)));
  }


    
                                  
     
  __STATIC_FORCEINLINE uint32_t __SMLAD(
  uint32_t x,
  uint32_t y,
  uint32_t sum)
  {
    return ((uint32_t)(((((q31_t)x << 16) >> 16) * (((q31_t)y << 16) >> 16)) +
                       ((((q31_t)x      ) >> 16) * (((q31_t)y      ) >> 16)) +
                       ( ((q31_t)sum    )                                  )   ));
  }


    
                                   
     
  __STATIC_FORCEINLINE uint32_t __SMLADX(
  uint32_t x,
  uint32_t y,
  uint32_t sum)
  {
    return ((uint32_t)(((((q31_t)x << 16) >> 16) * (((q31_t)y      ) >> 16)) +
                       ((((q31_t)x      ) >> 16) * (((q31_t)y << 16) >> 16)) +
                       ( ((q31_t)sum    )                                  )   ));
  }


    
                                   
     
  __STATIC_FORCEINLINE uint32_t __SMLSDX(
  uint32_t x,
  uint32_t y,
  uint32_t sum)
  {
    return ((uint32_t)(((((q31_t)x << 16) >> 16) * (((q31_t)y      ) >> 16)) -
                       ((((q31_t)x      ) >> 16) * (((q31_t)y << 16) >> 16)) +
                       ( ((q31_t)sum    )                                  )   ));
  }


    
                                   
     
  __STATIC_FORCEINLINE uint64_t __SMLALD(
  uint32_t x,
  uint32_t y,
  uint64_t sum)
  {
                                                                                        
    return ((uint64_t)(((((q31_t)x << 16) >> 16) * (((q31_t)y << 16) >> 16)) +
                       ((((q31_t)x      ) >> 16) * (((q31_t)y      ) >> 16)) +
                       ( ((q63_t)sum    )                                  )   ));
  }


    
                                    
     
  __STATIC_FORCEINLINE uint64_t __SMLALDX(
  uint32_t x,
  uint32_t y,
  uint64_t sum)
  {
                                                                                        
    return ((uint64_t)(((((q31_t)x << 16) >> 16) * (((q31_t)y      ) >> 16)) +
                       ((((q31_t)x      ) >> 16) * (((q31_t)y << 16) >> 16)) +
                       ( ((q63_t)sum    )                                  )   ));
  }


    
                                  
     
  __STATIC_FORCEINLINE uint32_t __SMUAD(
  uint32_t x,
  uint32_t y)
  {
    return ((uint32_t)(((((q31_t)x << 16) >> 16) * (((q31_t)y << 16) >> 16)) +
                       ((((q31_t)x      ) >> 16) * (((q31_t)y      ) >> 16))   ));
  }


    
                                  
     
  __STATIC_FORCEINLINE uint32_t __SMUSD(
  uint32_t x,
  uint32_t y)
  {
    return ((uint32_t)(((((q31_t)x << 16) >> 16) * (((q31_t)y << 16) >> 16)) -
                       ((((q31_t)x      ) >> 16) * (((q31_t)y      ) >> 16))   ));
  }


    
                                   
     
  __STATIC_FORCEINLINE uint32_t __SXTB16(
  uint32_t x)
  {
    return ((uint32_t)(((((q31_t)x << 24) >> 24) & (q31_t)0x0000FFFF) |
                       ((((q31_t)x <<  8) >>  8) & (q31_t)0xFFFF0000)  ));
  }

    
                                  
     
  __STATIC_FORCEINLINE int32_t __SMMLA(
  int32_t x,
  int32_t y,
  int32_t sum)
  {
    return (sum + (int32_t) (((int64_t) x * y) >> 32));
  }

#endif                              


     
                                                     
     
  typedef struct
  {
          uint16_t numTaps;                                                            
          q7_t *pState;                                                                                                   
    const q7_t *pCoeffs;                                                                                  
  } arm_fir_instance_q7;

     
                                                      
     
  typedef struct
  {
          uint16_t numTaps;                                                             
          q15_t *pState;                                                                                                   
    const q15_t *pCoeffs;                                                                                  
  } arm_fir_instance_q15;

     
                                                      
     
  typedef struct
  {
          uint16_t numTaps;                                                             
          q31_t *pState;                                                                                                   
    const q31_t *pCoeffs;                                                                                   
  } arm_fir_instance_q31;

     
                                                                 
     
  typedef struct
  {
          uint16_t numTaps;                                                         
          float32_t *pState;                                                                                           
    const float32_t *pCoeffs;                                                                           
  } arm_fir_instance_f32;

     
                                                      
                                                                                 
                                                              
                                                               
                                                         
     
  void arm_fir_q7(
  const arm_fir_instance_q7 * S,
  const q7_t * pSrc,
        q7_t * pDst,
        uint32_t blockSize);

     
                                                           
                                                                             
                                                                           
                                                                 
                                                          
                                                                    
     
  void arm_fir_init_q7(
        arm_fir_instance_q7 * S,
        uint16_t numTaps,
  const q7_t * pCoeffs,
        q7_t * pState,
        uint32_t blockSize);

     
                                                       
                                                                           
                                                              
                                                               
                                                         
     
  void arm_fir_q15(
  const arm_fir_instance_q15 * S,
  const q15_t * pSrc,
        q15_t * pDst,
        uint32_t blockSize);

     
                                                                           
                                                                                  
                                                              
                                                               
                                                         
     
  void arm_fir_fast_q15(
  const arm_fir_instance_q15 * S,
  const q15_t * pSrc,
        q15_t * pDst,
        uint32_t blockSize);

     
                                                            
                                                                                     
                                                                                                                        
                                                                 
                                                          
                                                                              
                                            
                                                                      
                                                                                           
     
  arm_status arm_fir_init_q15(
        arm_fir_instance_q15 * S,
        uint16_t numTaps,
  const q15_t * pCoeffs,
        q15_t * pState,
        uint32_t blockSize);

     
                                                       
                                                                                  
                                                              
                                                               
                                                         
     
  void arm_fir_q31(
  const arm_fir_instance_q31 * S,
  const q31_t * pSrc,
        q31_t * pDst,
        uint32_t blockSize);

     
                                                                           
                                                                                  
                                                              
                                                               
                                                         
     
  void arm_fir_fast_q31(
  const arm_fir_instance_q31 * S,
  const q31_t * pSrc,
        q31_t * pDst,
        uint32_t blockSize);

     
                                                            
                                                                              
                                                                           
                                                                 
                                                          
                                                                              
     
  void arm_fir_init_q31(
        arm_fir_instance_q31 * S,
        uint16_t numTaps,
  const q31_t * pCoeffs,
        q31_t * pState,
        uint32_t blockSize);

     
                                                                  
                                                                                      
                                                              
                                                               
                                                         
     
  void arm_fir_f32(
  const arm_fir_instance_f32 * S,
  const float32_t * pSrc,
        float32_t * pDst,
        uint32_t blockSize);

     
                                                                       
                                                                                                
                                                                           
                                                                 
                                                          
                                                                              
     
  void arm_fir_init_f32(
        arm_fir_instance_f32 * S,
        uint16_t numTaps,
  const float32_t * pCoeffs,
        float32_t * pState,
        uint32_t blockSize);

     
                                                                 
     
  typedef struct
  {
          int8_t numStages;                                                                                        
          q15_t *pState;                                                                                                  
    const q15_t *pCoeffs;                                                                                           
          int8_t postShift;                                                                         
  } arm_biquad_casd_df1_inst_q15;

     
                                                                 
     
  typedef struct
  {
          uint32_t numStages;                                                                                      
          q31_t *pState;                                                                                                  
    const q31_t *pCoeffs;                                                                                           
          uint8_t postShift;                                                                        
  } arm_biquad_casd_df1_inst_q31;

     
                                                                            
     
  typedef struct
  {
          uint32_t numStages;                                                                                      
          float32_t *pState;                                                                                              
    const float32_t *pCoeffs;                                                                                       
  } arm_biquad_casd_df1_inst_f32;

     
                                                                  
                                                                                      
                                                              
                                                               
                                                         
     
  void arm_biquad_cascade_df1_q15(
  const arm_biquad_casd_df1_inst_q15 * S,
  const q15_t * pSrc,
        q15_t * pDst,
        uint32_t blockSize);

     
                                                                       
                                                                                         
                                                                        
                                                                 
                                                          
                                                                                                             
     
  void arm_biquad_cascade_df1_init_q15(
        arm_biquad_casd_df1_inst_q15 * S,
        uint8_t numStages,
  const q15_t * pCoeffs,
        q15_t * pState,
        int8_t postShift);

     
                                                                                                                    
                                                                                      
                                                              
                                                               
                                                         
     
  void arm_biquad_cascade_df1_fast_q15(
  const arm_biquad_casd_df1_inst_q15 * S,
  const q15_t * pSrc,
        q15_t * pDst,
        uint32_t blockSize);

     
                                                                 
                                                                                      
                                                              
                                                               
                                                         
     
  void arm_biquad_cascade_df1_q31(
  const arm_biquad_casd_df1_inst_q31 * S,
  const q31_t * pSrc,
        q31_t * pDst,
        uint32_t blockSize);

     
                                                                                                                    
                                                                                      
                                                              
                                                               
                                                         
     
  void arm_biquad_cascade_df1_fast_q31(
  const arm_biquad_casd_df1_inst_q31 * S,
  const q31_t * pSrc,
        q31_t * pDst,
        uint32_t blockSize);

     
                                                                       
                                                                                         
                                                                        
                                                                 
                                                          
                                                                                                             
     
  void arm_biquad_cascade_df1_init_q31(
        arm_biquad_casd_df1_inst_q31 * S,
        uint8_t numStages,
  const q31_t * pCoeffs,
        q31_t * pState,
        int8_t postShift);

     
                                                                             
                                                                                                 
                                                              
                                                               
                                                         
     
  void arm_biquad_cascade_df1_f32(
  const arm_biquad_casd_df1_inst_f32 * S,
  const float32_t * pSrc,
        float32_t * pDst,
        uint32_t blockSize);

     
                                                                                  
                                                                                                    
                                                                        
                                                                 
                                                          
     
  void arm_biquad_cascade_df1_init_f32(
        arm_biquad_casd_df1_inst_f32 * S,
        uint8_t numStages,
  const float32_t * pCoeffs,
        float32_t * pState);

     
                                                                       
     
  typedef struct
  {
    uint16_t numRows;                                              
    uint16_t numCols;                                              
    float32_t *pData;                                              
  } arm_matrix_instance_f32;


     
                                                                       
     
  typedef struct
  {
    uint16_t numRows;                                              
    uint16_t numCols;                                              
    float64_t *pData;                                              
  } arm_matrix_instance_f64;

     
                                                            
     
  typedef struct
  {
    uint16_t numRows;                                              
    uint16_t numCols;                                              
    q15_t *pData;                                                  
  } arm_matrix_instance_q15;

     
                                                            
     
  typedef struct
  {
    uint16_t numRows;                                              
    uint16_t numCols;                                              
    q31_t *pData;                                                  
  } arm_matrix_instance_q31;

     
                                           
                                                                  
                                                                   
                                                         
                                            
                                                                                                                
     
arm_status arm_mat_add_f32(
  const arm_matrix_instance_f32 * pSrcA,
  const arm_matrix_instance_f32 * pSrcB,
        arm_matrix_instance_f32 * pDst);

     
                                
                                                                   
                                                                    
                                                          
                                            
                                                                                                                
     
arm_status arm_mat_add_q15(
  const arm_matrix_instance_q15 * pSrcA,
  const arm_matrix_instance_q15 * pSrcB,
        arm_matrix_instance_q15 * pDst);

     
                                
                                                                  
                                                                   
                                                         
                                            
                                                                                                                
     
arm_status arm_mat_add_q31(
  const arm_matrix_instance_q31 * pSrcA,
  const arm_matrix_instance_q31 * pSrcB,
        arm_matrix_instance_q31 * pDst);

     
                                                           
                                                                  
                                                                   
                                                         
                                            
                                                                                                                
     
arm_status arm_mat_cmplx_mult_f32(
  const arm_matrix_instance_f32 * pSrcA,
  const arm_matrix_instance_f32 * pSrcB,
        arm_matrix_instance_f32 * pDst);

     
                                                 
                                                                  
                                                                   
                                                         
                                            
                                                                                                                
     
arm_status arm_mat_cmplx_mult_q15(
  const arm_matrix_instance_q15 * pSrcA,
  const arm_matrix_instance_q15 * pSrcB,
        arm_matrix_instance_q15 * pDst,
        q15_t * pScratch);

     
                                                
                                                                  
                                                                   
                                                         
                                            
                                                                                                                
     
arm_status arm_mat_cmplx_mult_q31(
  const arm_matrix_instance_q31 * pSrcA,
  const arm_matrix_instance_q31 * pSrcB,
        arm_matrix_instance_q31 * pDst);

     
                                            
                                                 
                                                  
                                                                                
                                                                            
     
arm_status arm_mat_trans_f32(
  const arm_matrix_instance_f32 * pSrc,
        arm_matrix_instance_f32 * pDst);

     
                                 
                                                 
                                                  
                                                                                
                                                                            
     
arm_status arm_mat_trans_q15(
  const arm_matrix_instance_q15 * pSrc,
        arm_matrix_instance_q15 * pDst);

     
                                 
                                                 
                                                  
                                                                                
                                                                            
     
arm_status arm_mat_trans_q31(
  const arm_matrix_instance_q31 * pSrc,
        arm_matrix_instance_q31 * pDst);

     
                                                
                                                                  
                                                                   
                                                         
                                            
                                                                                                                
     
arm_status arm_mat_mult_f32(
  const arm_matrix_instance_f32 * pSrcA,
  const arm_matrix_instance_f32 * pSrcB,
        arm_matrix_instance_f32 * pDst);

     
                                     
                                                                   
                                                                    
                                                          
                                                                             
                                            
                                                                                                                
     
arm_status arm_mat_mult_q15(
  const arm_matrix_instance_q15 * pSrcA,
  const arm_matrix_instance_q15 * pSrcB,
        arm_matrix_instance_q15 * pDst,
        q15_t * pState);

     
                                                                                
                                                                   
                                                                    
                                                          
                                                                             
                                            
                                                                                                                
     
arm_status arm_mat_mult_fast_q15(
  const arm_matrix_instance_q15 * pSrcA,
  const arm_matrix_instance_q15 * pSrcB,
        arm_matrix_instance_q15 * pDst,
        q15_t * pState);

     
                                     
                                                                  
                                                                   
                                                         
                                            
                                                                                                                
     
arm_status arm_mat_mult_q31(
  const arm_matrix_instance_q31 * pSrcA,
  const arm_matrix_instance_q31 * pSrcB,
        arm_matrix_instance_q31 * pDst);

     
                                                                                
                                                                  
                                                                   
                                                         
                                            
                                                                                                                
     
arm_status arm_mat_mult_fast_q31(
  const arm_matrix_instance_q31 * pSrcA,
  const arm_matrix_instance_q31 * pSrcB,
        arm_matrix_instance_q31 * pDst);

     
                                             
                                                                  
                                                                   
                                                         
                                            
                                                                                                                
     
arm_status arm_mat_sub_f32(
  const arm_matrix_instance_f32 * pSrcA,
  const arm_matrix_instance_f32 * pSrcB,
        arm_matrix_instance_f32 * pDst);

     
                                  
                                                                  
                                                                   
                                                         
                                            
                                                                                                                
     
arm_status arm_mat_sub_q15(
  const arm_matrix_instance_q15 * pSrcA,
  const arm_matrix_instance_q15 * pSrcB,
        arm_matrix_instance_q15 * pDst);

     
                                  
                                                                  
                                                                   
                                                         
                                            
                                                                                                                
     
arm_status arm_mat_sub_q31(
  const arm_matrix_instance_q31 * pSrcA,
  const arm_matrix_instance_q31 * pSrcB,
        arm_matrix_instance_q31 * pDst);

     
                                          
                                                  
                                    
                                                   
                                            
                                                                                                                
     
arm_status arm_mat_scale_f32(
  const arm_matrix_instance_f32 * pSrc,
        float32_t scale,
        arm_matrix_instance_f32 * pDst);

     
                               
                                                   
                                                                   
                                                                  
                                                    
                                            
                                                                                                                
     
arm_status arm_mat_scale_q15(
  const arm_matrix_instance_q15 * pSrc,
        q15_t scaleFract,
        int32_t shift,
        arm_matrix_instance_q15 * pDst);

     
                               
                                                   
                                                                   
                                                                  
                                                              
                                            
                                                                                                                
     
arm_status arm_mat_scale_q31(
  const arm_matrix_instance_q31 * pSrc,
        q31_t scaleFract,
        int32_t shift,
        arm_matrix_instance_q31 * pDst);

     
                                       
                                                                                           
                                                           
                                                              
                                                              
     
void arm_mat_init_q31(
        arm_matrix_instance_q31 * S,
        uint16_t nRows,
        uint16_t nColumns,
        q31_t * pData);

     
                                       
                                                                                           
                                                           
                                                              
                                                              
     
void arm_mat_init_q15(
        arm_matrix_instance_q15 * S,
        uint16_t nRows,
        uint16_t nColumns,
        q15_t * pData);

     
                                                  
                                                                                           
                                                           
                                                              
                                                              
     
void arm_mat_init_f32(
        arm_matrix_instance_f32 * S,
        uint16_t nRows,
        uint16_t nColumns,
        float32_t * pData);


     
                                                       
     
  typedef struct
  {
          q15_t A0;                                                        
#if !defined (ARM_MATH_DSP)
          q15_t A1;
          q15_t A2;
#else
          q31_t A1;                                                       
#endif
          q15_t state[3];                                         
          q15_t Kp;                                         
          q15_t Ki;                                     
          q15_t Kd;                                       
  } arm_pid_instance_q15;

     
                                                       
     
  typedef struct
  {
          q31_t A0;                                                         
          q31_t A1;                                                     
          q31_t A2;                                               
          q31_t state[3];                                          
          q31_t Kp;                                          
          q31_t Ki;                                      
          q31_t Kd;                                        
  } arm_pid_instance_q31;

     
                                                                  
     
  typedef struct
  {
          float32_t A0;                                                       
          float32_t A1;                                                   
          float32_t A2;                                             
          float32_t state[3];                                        
          float32_t Kp;                                        
          float32_t Ki;                                    
          float32_t Kd;                                      
  } arm_pid_instance_f32;



     
                                                                        
                                                                               
                                                                                                        
     
  void arm_pid_init_f32(
        arm_pid_instance_f32 * S,
        int32_t resetStateFlag);


     
                                                               
                                                                                 
     
  void arm_pid_reset_f32(
        arm_pid_instance_f32 * S);


     
                                                             
                                                                                   
                                                                                                        
     
  void arm_pid_init_q31(
        arm_pid_instance_q31 * S,
        int32_t resetStateFlag);


     
                                                    
                                                                              
     

  void arm_pid_reset_q31(
        arm_pid_instance_q31 * S);


     
                                                             
                                                                                   
                                                                                                        
     
  void arm_pid_init_q15(
        arm_pid_instance_q15 * S,
        int32_t resetStateFlag);


     
                                                    
                                                                             
     
  void arm_pid_reset_q15(
        arm_pid_instance_q15 * S);


     
                                                                                  
     
  typedef struct
  {
          uint32_t nValues;                          
          float32_t x1;                         
          float32_t xSpacing;                         
          float32_t *pYData;                                                  
  } arm_linear_interp_instance_f32;

     
                                                                                      
     
  typedef struct
  {
          uint16_t numRows;                                            
          uint16_t numCols;                                               
          float32_t *pData;                                    
  } arm_bilinear_interp_instance_f32;

      
                                                                           
     
  typedef struct
  {
          uint16_t numRows;                                            
          uint16_t numCols;                                               
          q31_t *pData;                                        
  } arm_bilinear_interp_instance_q31;

      
                                                                           
     
  typedef struct
  {
          uint16_t numRows;                                            
          uint16_t numCols;                                               
          q15_t *pData;                                        
  } arm_bilinear_interp_instance_q15;

      
                                                                           
     
  typedef struct
  {
          uint16_t numRows;                                            
          uint16_t numCols;                                               
          q7_t *pData;                                         
  } arm_bilinear_interp_instance_q7;


     
                                     
                                                            
                                                             
                                                       
                                                            
     
  void arm_mult_q7(
  const q7_t * pSrcA,
  const q7_t * pSrcB,
        q7_t * pDst,
        uint32_t blockSize);


     
                                      
                                                            
                                                             
                                                       
                                                            
     
  void arm_mult_q15(
  const q15_t * pSrcA,
  const q15_t * pSrcB,
        q15_t * pDst,
        uint32_t blockSize);


     
                                      
                                                            
                                                             
                                                       
                                                            
     
  void arm_mult_q31(
  const q31_t * pSrcA,
  const q31_t * pSrcB,
        q31_t * pDst,
        uint32_t blockSize);


     
                                                 
                                                            
                                                             
                                                       
                                                            
     
  void arm_mult_f32(
  const float32_t * pSrcA,
  const float32_t * pSrcB,
        float32_t * pDst,
        uint32_t blockSize);


     
                                                               
     
  typedef struct
  {
          uint16_t fftLen;                                           
          uint8_t ifftFlag;                                                                                                 
          uint8_t bitReverseFlag;                                                                                                             
    const q15_t *pTwiddle;                                                                
    const uint16_t *pBitRevTable;                                                   
          uint16_t twidCoefModifier;                                                                                                                 
          uint16_t bitRevFactor;                                                                                                            
  } arm_cfft_radix2_instance_q15;

                
  arm_status arm_cfft_radix2_init_q15(
        arm_cfft_radix2_instance_q15 * S,
        uint16_t fftLen,
        uint8_t ifftFlag,
        uint8_t bitReverseFlag);

                
  void arm_cfft_radix2_q15(
  const arm_cfft_radix2_instance_q15 * S,
        q15_t * pSrc);


     
                                                               
     
  typedef struct
  {
          uint16_t fftLen;                                           
          uint8_t ifftFlag;                                                                                                 
          uint8_t bitReverseFlag;                                                                                                             
    const q15_t *pTwiddle;                                                            
    const uint16_t *pBitRevTable;                                                   
          uint16_t twidCoefModifier;                                                                                                                 
          uint16_t bitRevFactor;                                                                                                            
  } arm_cfft_radix4_instance_q15;

                
  arm_status arm_cfft_radix4_init_q15(
        arm_cfft_radix4_instance_q15 * S,
        uint16_t fftLen,
        uint8_t ifftFlag,
        uint8_t bitReverseFlag);

                
  void arm_cfft_radix4_q15(
  const arm_cfft_radix4_instance_q15 * S,
        q15_t * pSrc);

     
                                                                       
     
  typedef struct
  {
          uint16_t fftLen;                                           
          uint8_t ifftFlag;                                                                                                 
          uint8_t bitReverseFlag;                                                                                                             
    const q31_t *pTwiddle;                                                            
    const uint16_t *pBitRevTable;                                                   
          uint16_t twidCoefModifier;                                                                                                                 
          uint16_t bitRevFactor;                                                                                                            
  } arm_cfft_radix2_instance_q31;

                
  arm_status arm_cfft_radix2_init_q31(
        arm_cfft_radix2_instance_q31 * S,
        uint16_t fftLen,
        uint8_t ifftFlag,
        uint8_t bitReverseFlag);

                
  void arm_cfft_radix2_q31(
  const arm_cfft_radix2_instance_q31 * S,
        q31_t * pSrc);

     
                                                               
     
  typedef struct
  {
          uint16_t fftLen;                                           
          uint8_t ifftFlag;                                                                                                 
          uint8_t bitReverseFlag;                                                                                                             
    const q31_t *pTwiddle;                                                            
    const uint16_t *pBitRevTable;                                                   
          uint16_t twidCoefModifier;                                                                                                                 
          uint16_t bitRevFactor;                                                                                                            
  } arm_cfft_radix4_instance_q31;

                
  void arm_cfft_radix4_q31(
  const arm_cfft_radix4_instance_q31 * S,
        q31_t * pSrc);

                
  arm_status arm_cfft_radix4_init_q31(
        arm_cfft_radix4_instance_q31 * S,
        uint16_t fftLen,
        uint8_t ifftFlag,
        uint8_t bitReverseFlag);

     
                                                                          
     
  typedef struct
  {
          uint16_t fftLen;                                             
          uint8_t ifftFlag;                                                                                                   
          uint8_t bitReverseFlag;                                                                                                               
    const float32_t *pTwiddle;                                                          
    const uint16_t *pBitRevTable;                                                     
          uint16_t twidCoefModifier;                                                                                                                   
          uint16_t bitRevFactor;                                                                                                              
          float32_t onebyfftLen;                                       
  } arm_cfft_radix2_instance_f32;

                
  arm_status arm_cfft_radix2_init_f32(
        arm_cfft_radix2_instance_f32 * S,
        uint16_t fftLen,
        uint8_t ifftFlag,
        uint8_t bitReverseFlag);

                
  void arm_cfft_radix2_f32(
  const arm_cfft_radix2_instance_f32 * S,
        float32_t * pSrc);

     
                                                                          
     
  typedef struct
  {
          uint16_t fftLen;                                             
          uint8_t ifftFlag;                                                                                                   
          uint8_t bitReverseFlag;                                                                                                               
    const float32_t *pTwiddle;                                                          
    const uint16_t *pBitRevTable;                                                     
          uint16_t twidCoefModifier;                                                                                                                   
          uint16_t bitRevFactor;                                                                                                              
          float32_t onebyfftLen;                                       
  } arm_cfft_radix4_instance_f32;

                
  arm_status arm_cfft_radix4_init_f32(
        arm_cfft_radix4_instance_f32 * S,
        uint16_t fftLen,
        uint8_t ifftFlag,
        uint8_t bitReverseFlag);

                
  void arm_cfft_radix4_f32(
  const arm_cfft_radix4_instance_f32 * S,
        float32_t * pSrc);

     
                                                                       
     
  typedef struct
  {
          uint16_t fftLen;                                             
    const q15_t *pTwiddle;                                                        
    const uint16_t *pBitRevTable;                                               
          uint16_t bitRevLength;                                               
  } arm_cfft_instance_q15;

void arm_cfft_q15(
    const arm_cfft_instance_q15 * S,
          q15_t * p1,
          uint8_t ifftFlag,
          uint8_t bitReverseFlag);

     
                                                                       
     
  typedef struct
  {
          uint16_t fftLen;                                             
    const q31_t *pTwiddle;                                                        
    const uint16_t *pBitRevTable;                                               
          uint16_t bitRevLength;                                               
  } arm_cfft_instance_q31;

void arm_cfft_q31(
    const arm_cfft_instance_q31 * S,
          q31_t * p1,
          uint8_t ifftFlag,
          uint8_t bitReverseFlag);

     
                                                                          
     
  typedef struct
  {
          uint16_t fftLen;                                             
    const float32_t *pTwiddle;                                                    
    const uint16_t *pBitRevTable;                                               
          uint16_t bitRevLength;                                               
  } arm_cfft_instance_f32;

  void arm_cfft_f32(
  const arm_cfft_instance_f32 * S,
        float32_t * p1,
        uint8_t ifftFlag,
        uint8_t bitReverseFlag);

     
                                                               
     
  typedef struct
  {
          uint32_t fftLenReal;                                                     
          uint8_t ifftFlagR;                                                                                                           
          uint8_t bitReverseFlagR;                                                                                                                       
          uint32_t twidCoefRModifier;                                                                                                                         
    const q15_t *pTwiddleAReal;                                                                     
    const q15_t *pTwiddleBReal;                                                                     
    const arm_cfft_instance_q15 *pCfft;                                                  
  } arm_rfft_instance_q15;

  arm_status arm_rfft_init_q15(
        arm_rfft_instance_q15 * S,
        uint32_t fftLenReal,
        uint32_t ifftFlagR,
        uint32_t bitReverseFlag);

  void arm_rfft_q15(
  const arm_rfft_instance_q15 * S,
        q15_t * pSrc,
        q15_t * pDst);

     
                                                               
     
  typedef struct
  {
          uint32_t fftLenReal;                                                       
          uint8_t ifftFlagR;                                                                                                             
          uint8_t bitReverseFlagR;                                                                                                                         
          uint32_t twidCoefRModifier;                                                                                                                           
    const q31_t *pTwiddleAReal;                                                                       
    const q31_t *pTwiddleBReal;                                                                       
    const arm_cfft_instance_q31 *pCfft;                                                    
  } arm_rfft_instance_q31;

  arm_status arm_rfft_init_q31(
        arm_rfft_instance_q31 * S,
        uint32_t fftLenReal,
        uint32_t ifftFlagR,
        uint32_t bitReverseFlag);

  void arm_rfft_q31(
  const arm_rfft_instance_q31 * S,
        q31_t * pSrc,
        q31_t * pDst);

     
                                                                          
     
  typedef struct
  {
          uint32_t fftLenReal;                                                       
          uint16_t fftLenBy2;                                                           
          uint8_t ifftFlagR;                                                                                                             
          uint8_t bitReverseFlagR;                                                                                                                         
          uint32_t twidCoefRModifier;                                                                                                                               
    const float32_t *pTwiddleAReal;                                                                   
    const float32_t *pTwiddleBReal;                                                                   
          arm_cfft_radix4_instance_f32 *pCfft;                                                   
  } arm_rfft_instance_f32;

  arm_status arm_rfft_init_f32(
        arm_rfft_instance_f32 * S,
        arm_cfft_radix4_instance_f32 * S_CFFT,
        uint32_t fftLenReal,
        uint32_t ifftFlagR,
        uint32_t bitReverseFlag);

  void arm_rfft_f32(
  const arm_rfft_instance_f32 * S,
        float32_t * pSrc,
        float32_t * pDst);

     
                                                                          
     
typedef struct
  {
          arm_cfft_instance_f32 Sint;                                      
          uint16_t fftLenRFFT;                                                
    const float32_t * pTwiddleRFFT;                                           
  } arm_rfft_fast_instance_f32 ;

arm_status arm_rfft_fast_init_f32 (
         arm_rfft_fast_instance_f32 * S,
         uint16_t fftLen);

arm_status arm_rfft_32_fast_init_f32 ( arm_rfft_fast_instance_f32 * S );

arm_status arm_rfft_64_fast_init_f32 ( arm_rfft_fast_instance_f32 * S );

arm_status arm_rfft_128_fast_init_f32 ( arm_rfft_fast_instance_f32 * S );

arm_status arm_rfft_256_fast_init_f32 ( arm_rfft_fast_instance_f32 * S );

arm_status arm_rfft_512_fast_init_f32 ( arm_rfft_fast_instance_f32 * S );

arm_status arm_rfft_1024_fast_init_f32 ( arm_rfft_fast_instance_f32 * S );

arm_status arm_rfft_2048_fast_init_f32 ( arm_rfft_fast_instance_f32 * S );

arm_status arm_rfft_4096_fast_init_f32 ( arm_rfft_fast_instance_f32 * S );


  void arm_rfft_fast_f32(
        arm_rfft_fast_instance_f32 * S,
        float32_t * p, float32_t * pOut,
        uint8_t ifftFlag);

     
                                                                          
     
  typedef struct
  {
          uint16_t N;                                                     
          uint16_t Nby2;                                                              
          float32_t normalize;                                            
    const float32_t *pTwiddle;                                                            
    const float32_t *pCosFactor;                                                     
          arm_rfft_instance_f32 *pRfft;                                                
          arm_cfft_radix4_instance_f32 *pCfft;                                            
  } arm_dct4_instance_f32;


     
                                                                       
                                                                                            
                                                                                            
                                                                                            
                                                  
                                                              
                                                  
                                                                                                                                                                                         
     
  arm_status arm_dct4_init_f32(
        arm_dct4_instance_f32 * S,
        arm_rfft_instance_f32 * S_RFFT,
        arm_cfft_radix4_instance_f32 * S_CFFT,
        uint16_t N,
        uint16_t Nby2,
        float32_t normalize);


     
                                                                  
                                                                                                    
                                                          
                                                                                  
     
  void arm_dct4_f32(
  const arm_dct4_instance_f32 * S,
        float32_t * pState,
        float32_t * pInlineBuffer);


     
                                                               
     
  typedef struct
  {
          uint16_t N;                                                     
          uint16_t Nby2;                                                              
          q31_t normalize;                                                
    const q31_t *pTwiddle;                                                                
    const q31_t *pCosFactor;                                                         
          arm_rfft_instance_q31 *pRfft;                                                
          arm_cfft_radix4_instance_q31 *pCfft;                                            
  } arm_dct4_instance_q31;


     
                                                            
                                                                                 
                                                                                
                                                                                
                                                  
                                                              
                                                  
                                                                                                                                                                                
     
  arm_status arm_dct4_init_q31(
        arm_dct4_instance_q31 * S,
        arm_rfft_instance_q31 * S_RFFT,
        arm_cfft_radix4_instance_q31 * S_CFFT,
        uint16_t N,
        uint16_t Nby2,
        q31_t normalize);


     
                                                       
                                                                                   
                                                          
                                                                                  
     
  void arm_dct4_q31(
  const arm_dct4_instance_q31 * S,
        q31_t * pState,
        q31_t * pInlineBuffer);


     
                                                               
     
  typedef struct
  {
          uint16_t N;                                                     
          uint16_t Nby2;                                                              
          q15_t normalize;                                                
    const q15_t *pTwiddle;                                                                
    const q15_t *pCosFactor;                                                         
          arm_rfft_instance_q15 *pRfft;                                                
          arm_cfft_radix4_instance_q15 *pCfft;                                            
  } arm_dct4_instance_q15;


     
                                                            
                                                                                 
                                                                                 
                                                                                 
                                                  
                                                              
                                                  
                                                                                                                                                                                
     
  arm_status arm_dct4_init_q15(
        arm_dct4_instance_q15 * S,
        arm_rfft_instance_q15 * S_RFFT,
        arm_cfft_radix4_instance_q15 * S_CFFT,
        uint16_t N,
        uint16_t Nby2,
        q15_t normalize);


     
                                                       
                                                                                   
                                                          
                                                                                  
     
  void arm_dct4_q15(
  const arm_dct4_instance_q15 * S,
        q15_t * pState,
        q15_t * pInlineBuffer);


     
                                           
                                                            
                                                             
                                                       
                                                            
     
  void arm_add_f32(
  const float32_t * pSrcA,
  const float32_t * pSrcB,
        float32_t * pDst,
        uint32_t blockSize);


     
                               
                                                            
                                                             
                                                       
                                                            
     
  void arm_add_q7(
  const q7_t * pSrcA,
  const q7_t * pSrcB,
        q7_t * pDst,
        uint32_t blockSize);


     
                                
                                                            
                                                             
                                                       
                                                            
     
  void arm_add_q15(
  const q15_t * pSrcA,
  const q15_t * pSrcB,
        q15_t * pDst,
        uint32_t blockSize);


     
                                
                                                            
                                                             
                                                       
                                                            
     
  void arm_add_q31(
  const q31_t * pSrcA,
  const q31_t * pSrcB,
        q31_t * pDst,
        uint32_t blockSize);


     
                                              
                                                            
                                                             
                                                       
                                                            
     
  void arm_sub_f32(
  const float32_t * pSrcA,
  const float32_t * pSrcB,
        float32_t * pDst,
        uint32_t blockSize);


     
                                  
                                                            
                                                             
                                                       
                                                            
     
  void arm_sub_q7(
  const q7_t * pSrcA,
  const q7_t * pSrcB,
        q7_t * pDst,
        uint32_t blockSize);


     
                                   
                                                            
                                                             
                                                       
                                                            
     
  void arm_sub_q15(
  const q15_t * pSrcA,
  const q15_t * pSrcB,
        q15_t * pDst,
        uint32_t blockSize);


     
                                   
                                                            
                                                             
                                                       
                                                            
     
  void arm_sub_q31(
  const q31_t * pSrcA,
  const q31_t * pSrcB,
        q31_t * pDst,
        uint32_t blockSize);


     
                                                           
                                                      
                                                      
                                                       
                                                           
     
  void arm_scale_f32(
  const float32_t * pSrc,
        float32_t scale,
        float32_t * pDst,
        uint32_t blockSize);


     
                                               
                                                       
                                                                  
                                                                  
                                                        
                                                            
     
  void arm_scale_q7(
  const q7_t * pSrc,
        q7_t scaleFract,
        int8_t shift,
        q7_t * pDst,
        uint32_t blockSize);


     
                                                
                                                       
                                                                  
                                                                  
                                                        
                                                            
     
  void arm_scale_q15(
  const q15_t * pSrc,
        q15_t scaleFract,
        int8_t shift,
        q15_t * pDst,
        uint32_t blockSize);


     
                                                
                                                       
                                                                  
                                                                  
                                                        
                                                            
     
  void arm_scale_q31(
  const q31_t * pSrc,
        q31_t scaleFract,
        int8_t shift,
        q31_t * pDst,
        uint32_t blockSize);


     
                                     
                                                      
                                                       
                                                            
     
  void arm_abs_q7(
  const q7_t * pSrc,
        q7_t * pDst,
        uint32_t blockSize);


     
                                                 
                                                      
                                                       
                                                            
     
  void arm_abs_f32(
  const float32_t * pSrc,
        float32_t * pDst,
        uint32_t blockSize);


     
                                      
                                                      
                                                       
                                                            
     
  void arm_abs_q15(
  const q15_t * pSrc,
        q15_t * pDst,
        uint32_t blockSize);


     
                                      
                                                      
                                                       
                                                            
     
  void arm_abs_q31(
  const q31_t * pSrc,
        q31_t * pDst,
        uint32_t blockSize);


     
                                                  
                                                            
                                                             
                                                            
                                                       
     
  void arm_dot_prod_f32(
  const float32_t * pSrcA,
  const float32_t * pSrcB,
        uint32_t blockSize,
        float32_t * result);


     
                                      
                                                            
                                                             
                                                            
                                                       
     
  void arm_dot_prod_q7(
  const q7_t * pSrcA,
  const q7_t * pSrcB,
        uint32_t blockSize,
        q31_t * result);


     
                                       
                                                            
                                                             
                                                            
                                                       
     
  void arm_dot_prod_q15(
  const q15_t * pSrcA,
  const q15_t * pSrcB,
        uint32_t blockSize,
        q63_t * result);


     
                                       
                                                            
                                                             
                                                            
                                                       
     
  void arm_dot_prod_q31(
  const q31_t * pSrcA,
  const q31_t * pSrcB,
        uint32_t blockSize,
        q63_t * result);


     
                                                                           
                                                      
                                                                                                                  
                                                       
                                                           
     
  void arm_shift_q7(
  const q7_t * pSrc,
        int8_t shiftBits,
        q7_t * pDst,
        uint32_t blockSize);


     
                                                                            
                                                      
                                                                                                                  
                                                       
                                                           
     
  void arm_shift_q15(
  const q15_t * pSrc,
        int8_t shiftBits,
        q15_t * pDst,
        uint32_t blockSize);


     
                                                                            
                                                      
                                                                                                                  
                                                       
                                                           
     
  void arm_shift_q31(
  const q31_t * pSrc,
        int8_t shiftBits,
        q31_t * pDst,
        uint32_t blockSize);


     
                                                               
                                                      
                                                     
                                                       
                                                           
     
  void arm_offset_f32(
  const float32_t * pSrc,
        float32_t offset,
        float32_t * pDst,
        uint32_t blockSize);


     
                                                   
                                                      
                                                     
                                                       
                                                           
     
  void arm_offset_q7(
  const q7_t * pSrc,
        q7_t offset,
        q7_t * pDst,
        uint32_t blockSize);


     
                                                    
                                                      
                                                     
                                                       
                                                           
     
  void arm_offset_q15(
  const q15_t * pSrc,
        q15_t offset,
        q15_t * pDst,
        uint32_t blockSize);


     
                                                    
                                                      
                                                     
                                                       
                                                           
     
  void arm_offset_q31(
  const q31_t * pSrc,
        q31_t offset,
        q31_t * pDst,
        uint32_t blockSize);


     
                                                             
                                                      
                                                       
                                                           
     
  void arm_negate_f32(
  const float32_t * pSrc,
        float32_t * pDst,
        uint32_t blockSize);


     
                                                 
                                                      
                                                       
                                                           
     
  void arm_negate_q7(
  const q7_t * pSrc,
        q7_t * pDst,
        uint32_t blockSize);


     
                                                  
                                                      
                                                       
                                                           
     
  void arm_negate_q15(
  const q15_t * pSrc,
        q15_t * pDst,
        uint32_t blockSize);


     
                                                  
                                                      
                                                       
                                                           
     
  void arm_negate_q31(
  const q31_t * pSrc,
        q31_t * pDst,
        uint32_t blockSize);


     
                                                            
                                         
                                          
                                                        
     
  void arm_copy_f32(
  const float32_t * pSrc,
        float32_t * pDst,
        uint32_t blockSize);


     
                                                
                                         
                                          
                                                        
     
  void arm_copy_q7(
  const q7_t * pSrc,
        q7_t * pDst,
        uint32_t blockSize);


     
                                                 
                                         
                                          
                                                        
     
  void arm_copy_q15(
  const q15_t * pSrc,
        q15_t * pDst,
        uint32_t blockSize);


     
                                                 
                                         
                                          
                                                        
     
  void arm_copy_q31(
  const q31_t * pSrc,
        q31_t * pDst,
        uint32_t blockSize);


     
                                                                 
                                                    
                                          
                                                        
     
  void arm_fill_f32(
        float32_t value,
        float32_t * pDst,
        uint32_t blockSize);


     
                                                     
                                                    
                                          
                                                        
     
  void arm_fill_q7(
        q7_t value,
        q7_t * pDst,
        uint32_t blockSize);


     
                                                      
                                                    
                                          
                                                        
     
  void arm_fill_q15(
        q15_t value,
        q15_t * pDst,
        uint32_t blockSize);


     
                                                      
                                                    
                                          
                                                        
     
  void arm_fill_q31(
        q31_t value,
        q31_t * pDst,
        uint32_t blockSize);


   
                                                  
                                                           
                                                           
                                                            
                                                            
                                                                                                             
   
  void arm_conv_f32(
  const float32_t * pSrcA,
        uint32_t srcALen,
  const float32_t * pSrcB,
        uint32_t srcBLen,
        float32_t * pDst);


     
                                         
                                                               
                                                               
                                                                
                                                                
                                                                                         
                                                                                                                 
                                                                                   
     
  void arm_conv_opt_q15(
  const q15_t * pSrcA,
        uint32_t srcALen,
  const q15_t * pSrcB,
        uint32_t srcBLen,
        q15_t * pDst,
        q15_t * pScratch1,
        q15_t * pScratch2);


   
                                       
                                                           
                                                           
                                                            
                                                            
                                                                                                             
   
  void arm_conv_q15(
  const q15_t * pSrcA,
        uint32_t srcALen,
  const q15_t * pSrcB,
        uint32_t srcBLen,
        q15_t * pDst);


     
                                                                                   
                                                             
                                                             
                                                              
                                                              
                                                                                       
     
  void arm_conv_fast_q15(
  const q15_t * pSrcA,
        uint32_t srcALen,
  const q15_t * pSrcB,
        uint32_t srcBLen,
        q15_t * pDst);


     
                                                                                   
                                                               
                                                               
                                                                
                                                                
                                                                                         
                                                                                                                 
                                                                                   
     
  void arm_conv_fast_opt_q15(
  const q15_t * pSrcA,
        uint32_t srcALen,
  const q15_t * pSrcB,
        uint32_t srcBLen,
        q15_t * pDst,
        q15_t * pScratch1,
        q15_t * pScratch2);


     
                                         
                                                             
                                                             
                                                              
                                                              
                                                                                       
     
  void arm_conv_q31(
  const q31_t * pSrcA,
        uint32_t srcALen,
  const q31_t * pSrcB,
        uint32_t srcBLen,
        q31_t * pDst);


     
                                                                                   
                                                             
                                                             
                                                              
                                                              
                                                                                       
     
  void arm_conv_fast_q31(
  const q31_t * pSrcA,
        uint32_t srcALen,
  const q31_t * pSrcB,
        uint32_t srcBLen,
        q31_t * pDst);


       
                                        
                                                               
                                                               
                                                                
                                                                
                                                                                         
                                                                                                                                
                                                                                                   
     
  void arm_conv_opt_q7(
  const q7_t * pSrcA,
        uint32_t srcALen,
  const q7_t * pSrcB,
        uint32_t srcBLen,
        q7_t * pDst,
        q15_t * pScratch1,
        q15_t * pScratch2);


     
                                        
                                                             
                                                             
                                                              
                                                              
                                                                                       
     
  void arm_conv_q7(
  const q7_t * pSrcA,
        uint32_t srcALen,
  const q7_t * pSrcB,
        uint32_t srcBLen,
        q7_t * pDst);


     
                                                            
                                                                
                                                                
                                                                 
                                                                 
                                                               
                                                                      
                                                                           
                                                                                                                                                                               
     
  arm_status arm_conv_partial_f32(
  const float32_t * pSrcA,
        uint32_t srcALen,
  const float32_t * pSrcB,
        uint32_t srcBLen,
        float32_t * pDst,
        uint32_t firstIndex,
        uint32_t numPoints);


     
                                                 
                                                                
                                                                
                                                                 
                                                                 
                                                               
                                                                      
                                                                           
                                                                                                                  
                                                                                    
                                                                                                                                                                               
     
  arm_status arm_conv_partial_opt_q15(
  const q15_t * pSrcA,
        uint32_t srcALen,
  const q15_t * pSrcB,
        uint32_t srcBLen,
        q15_t * pDst,
        uint32_t firstIndex,
        uint32_t numPoints,
        q15_t * pScratch1,
        q15_t * pScratch2);


     
                                                 
                                                                
                                                                
                                                                 
                                                                 
                                                               
                                                                      
                                                                           
                                                                                                                                                                               
     
  arm_status arm_conv_partial_q15(
  const q15_t * pSrcA,
        uint32_t srcALen,
  const q15_t * pSrcB,
        uint32_t srcBLen,
        q15_t * pDst,
        uint32_t firstIndex,
        uint32_t numPoints);


     
                                                                                           
                                                                
                                                                
                                                                 
                                                                 
                                                               
                                                                      
                                                                           
                                                                                                                                                                               
     
  arm_status arm_conv_partial_fast_q15(
  const q15_t * pSrcA,
        uint32_t srcALen,
  const q15_t * pSrcB,
        uint32_t srcBLen,
        q15_t * pDst,
        uint32_t firstIndex,
        uint32_t numPoints);


     
                                                                                           
                                                                
                                                                
                                                                 
                                                                 
                                                               
                                                                      
                                                                           
                                                                                                                  
                                                                                    
                                                                                                                                                                               
     
  arm_status arm_conv_partial_fast_opt_q15(
  const q15_t * pSrcA,
        uint32_t srcALen,
  const q15_t * pSrcB,
        uint32_t srcBLen,
        q15_t * pDst,
        uint32_t firstIndex,
        uint32_t numPoints,
        q15_t * pScratch1,
        q15_t * pScratch2);


     
                                                 
                                                                
                                                                
                                                                 
                                                                 
                                                               
                                                                      
                                                                           
                                                                                                                                                                               
     
  arm_status arm_conv_partial_q31(
  const q31_t * pSrcA,
        uint32_t srcALen,
  const q31_t * pSrcB,
        uint32_t srcBLen,
        q31_t * pDst,
        uint32_t firstIndex,
        uint32_t numPoints);


     
                                                                                           
                                                                
                                                                
                                                                 
                                                                 
                                                               
                                                                      
                                                                           
                                                                                                                                                                               
     
  arm_status arm_conv_partial_fast_q31(
  const q31_t * pSrcA,
        uint32_t srcALen,
  const q31_t * pSrcB,
        uint32_t srcBLen,
        q31_t * pDst,
        uint32_t firstIndex,
        uint32_t numPoints);


     
                                               
                                                                
                                                                
                                                                 
                                                                 
                                                               
                                                                      
                                                                           
                                                                                                                                 
                                                                                                    
                                                                                                                                                                               
     
  arm_status arm_conv_partial_opt_q7(
  const q7_t * pSrcA,
        uint32_t srcALen,
  const q7_t * pSrcB,
        uint32_t srcBLen,
        q7_t * pDst,
        uint32_t firstIndex,
        uint32_t numPoints,
        q15_t * pScratch1,
        q15_t * pScratch2);


   
                                                
                                                                
                                                                
                                                                 
                                                                 
                                                               
                                                                      
                                                                           
                                                                                                                                                                               
     
  arm_status arm_conv_partial_q7(
  const q7_t * pSrcA,
        uint32_t srcALen,
  const q7_t * pSrcB,
        uint32_t srcBLen,
        q7_t * pDst,
        uint32_t firstIndex,
        uint32_t numPoints);


     
                                                         
     
  typedef struct
  {
          uint8_t M;                                            
          uint16_t numTaps;                                                        
    const q15_t *pCoeffs;                                                                                    
          q15_t *pState;                                                                                                     
  } arm_fir_decimate_instance_q15;

     
                                                         
     
  typedef struct
  {
          uint8_t M;                                            
          uint16_t numTaps;                                                        
    const q31_t *pCoeffs;                                                                                    
          q31_t *pState;                                                                                                     
  } arm_fir_decimate_instance_q31;

   
                                                             
   
typedef struct
  {
          uint8_t M;                                            
          uint16_t numTaps;                                                        
    const float32_t *pCoeffs;                                                                                
          float32_t *pState;                                                                                                 
  } arm_fir_decimate_instance_f32;


   
                                                                      
                                                                                              
                                                            
                                                             
                                                       
   
void arm_fir_decimate_f32(
  const arm_fir_decimate_instance_f32 * S,
  const float32_t * pSrc,
        float32_t * pDst,
        uint32_t blockSize);


   
                                                                              
                                                                                               
                                                                
                                             
                                                             
                                                      
                                                                       
                                 
                                                                      
                                                                                                            
   
arm_status arm_fir_decimate_init_f32(
        arm_fir_decimate_instance_f32 * S,
        uint16_t numTaps,
        uint8_t M,
  const float32_t * pCoeffs,
        float32_t * pState,
        uint32_t blockSize);


     
                                                          
                                                                                     
                                                              
                                                              
                                                                        
     
  void arm_fir_decimate_q15(
  const arm_fir_decimate_instance_q15 * S,
  const q15_t * pSrc,
        q15_t * pDst,
        uint32_t blockSize);


     
                                                                                                     
                                                                                     
                                                              
                                                              
                                                                        
     
  void arm_fir_decimate_fast_q15(
  const arm_fir_decimate_instance_q15 * S,
  const q15_t * pSrc,
        q15_t * pDst,
        uint32_t blockSize);


     
                                                               
                                                                                        
                                                                    
                                                 
                                                                 
                                                          
                                                                           
                                                                                                                 
                                                                
     
  arm_status arm_fir_decimate_init_q15(
        arm_fir_decimate_instance_q15 * S,
        uint16_t numTaps,
        uint8_t M,
  const q15_t * pCoeffs,
        q15_t * pState,
        uint32_t blockSize);


     
                                                          
                                                                                
                                                         
                                                         
                                                                      
     
  void arm_fir_decimate_q31(
  const arm_fir_decimate_instance_q31 * S,
  const q31_t * pSrc,
        q31_t * pDst,
        uint32_t blockSize);

     
                                                                                                     
                                                                                     
                                                              
                                                              
                                                                        
     
  void arm_fir_decimate_fast_q31(
  const arm_fir_decimate_instance_q31 * S,
  const q31_t * pSrc,
        q31_t * pDst,
        uint32_t blockSize);


     
                                                               
                                                                                        
                                                                    
                                                 
                                                                 
                                                          
                                                                           
                                                                                                                 
                                                                
     
  arm_status arm_fir_decimate_init_q31(
        arm_fir_decimate_instance_q31 * S,
        uint16_t numTaps,
        uint8_t M,
  const q31_t * pCoeffs,
        q31_t * pState,
        uint32_t blockSize);


     
                                                            
     
  typedef struct
  {
        uint8_t L;                                              
        uint16_t phaseLength;                                                             
  const q15_t *pCoeffs;                                                                                               
        q15_t *pState;                                                                                                             
  } arm_fir_interpolate_instance_q15;

     
                                                            
     
  typedef struct
  {
        uint8_t L;                                              
        uint16_t phaseLength;                                                             
  const q31_t *pCoeffs;                                                                                               
        q31_t *pState;                                                                                                             
  } arm_fir_interpolate_instance_q31;

     
                                                                       
     
  typedef struct
  {
        uint8_t L;                                             
        uint16_t phaseLength;                                                            
  const float32_t *pCoeffs;                                                                                          
        float32_t *pState;                                                                                                      
  } arm_fir_interpolate_instance_f32;


     
                                                             
                                                                                        
                                                              
                                                               
                                                                        
     
  void arm_fir_interpolate_q15(
  const arm_fir_interpolate_instance_q15 * S,
  const q15_t * pSrc,
        q15_t * pDst,
        uint32_t blockSize);


     
                                                                  
                                                                                           
                                               
                                                                           
                                                                       
                                                          
                                                                           
                                                                                                                     
                                                                                                         
     
  arm_status arm_fir_interpolate_init_q15(
        arm_fir_interpolate_instance_q15 * S,
        uint8_t L,
        uint16_t numTaps,
  const q15_t * pCoeffs,
        q15_t * pState,
        uint32_t blockSize);


     
                                                             
                                                                                        
                                                              
                                                               
                                                                        
     
  void arm_fir_interpolate_q31(
  const arm_fir_interpolate_instance_q31 * S,
  const q31_t * pSrc,
        q31_t * pDst,
        uint32_t blockSize);


     
                                                                  
                                                                                           
                                               
                                                                           
                                                                       
                                                          
                                                                           
                                                                                                                     
                                                                                                         
     
  arm_status arm_fir_interpolate_init_q31(
        arm_fir_interpolate_instance_q31 * S,
        uint8_t L,
        uint16_t numTaps,
  const q31_t * pCoeffs,
        q31_t * pState,
        uint32_t blockSize);


     
                                                                        
                                                                                                   
                                                              
                                                               
                                                                        
     
  void arm_fir_interpolate_f32(
  const arm_fir_interpolate_instance_f32 * S,
  const float32_t * pSrc,
        float32_t * pDst,
        uint32_t blockSize);


     
                                                                             
                                                                                                      
                                               
                                                                           
                                                                       
                                                          
                                                                           
                                                                                                                     
                                                                                                         
     
  arm_status arm_fir_interpolate_init_f32(
        arm_fir_interpolate_instance_f32 * S,
        uint8_t L,
        uint16_t numTaps,
  const float32_t * pCoeffs,
        float32_t * pState,
        uint32_t blockSize);


     
                                                                                
     
  typedef struct
  {
          uint8_t numStages;                                                                                       
          q63_t *pState;                                                                                                  
    const q31_t *pCoeffs;                                                                                           
          uint8_t postShift;                                                                        
  } arm_biquad_cas_df1_32x64_ins_q31;


     
                                                                                                            
                                                              
                                                              
                                                         
     
  void arm_biquad_cas_df1_32x64_q31(
  const arm_biquad_cas_df1_32x64_ins_q31 * S,
        q31_t * pSrc,
        q31_t * pDst,
        uint32_t blockSize);


     
                                                                                                               
                                                                        
                                                                 
                                                          
                                                                                                             
     
  void arm_biquad_cas_df1_32x64_init_q31(
        arm_biquad_cas_df1_32x64_ins_q31 * S,
        uint8_t numStages,
  const q31_t * pCoeffs,
        q63_t * pState,
        uint8_t postShift);


     
                                                                                                      
     
  typedef struct
  {
          uint8_t numStages;                                                                                         
          float32_t *pState;                                                                                                
    const float32_t *pCoeffs;                                                                                         
  } arm_biquad_cascade_df2T_instance_f32;

     
                                                                                                      
     
  typedef struct
  {
          uint8_t numStages;                                                                                         
          float32_t *pState;                                                                                                
    const float32_t *pCoeffs;                                                                                         
  } arm_biquad_cascade_stereo_df2T_instance_f32;

     
                                                                                                      
     
  typedef struct
  {
          uint8_t numStages;                                                                                         
          float64_t *pState;                                                                                                
          float64_t *pCoeffs;                                                                                         
  } arm_biquad_cascade_df2T_instance_f64;


     
                                                                                                       
                                                                               
                                                              
                                                              
                                                         
     
  void arm_biquad_cascade_df2T_f32(
  const arm_biquad_cascade_df2T_instance_f32 * S,
  const float32_t * pSrc,
        float32_t * pDst,
        uint32_t blockSize);


     
                                                                                                                  
                                                                               
                                                              
                                                              
                                                         
     
  void arm_biquad_cascade_stereo_df2T_f32(
  const arm_biquad_cascade_stereo_df2T_instance_f32 * S,
  const float32_t * pSrc,
        float32_t * pDst,
        uint32_t blockSize);


     
                                                                                                       
                                                                               
                                                              
                                                              
                                                         
     
  void arm_biquad_cascade_df2T_f64(
  const arm_biquad_cascade_df2T_instance_f64 * S,
        float64_t * pSrc,
        float64_t * pDst,
        uint32_t blockSize);


#if defined(ARM_MATH_NEON) 
void arm_biquad_cascade_df2T_compute_coefs_f32(
  arm_biquad_cascade_df2T_instance_f32 * S,
  uint8_t numStages,
  float32_t * pCoeffs);
#endif
     
                                                                                                            
                                                                                  
                                                                        
                                                                 
                                                          
     
  void arm_biquad_cascade_df2T_init_f32(
        arm_biquad_cascade_df2T_instance_f32 * S,
        uint8_t numStages,
  const float32_t * pCoeffs,
        float32_t * pState);


     
                                                                                                            
                                                                                  
                                                                        
                                                                 
                                                          
     
  void arm_biquad_cascade_stereo_df2T_init_f32(
        arm_biquad_cascade_stereo_df2T_instance_f32 * S,
        uint8_t numStages,
  const float32_t * pCoeffs,
        float32_t * pState);


     
                                                                                                            
                                                                                  
                                                                        
                                                                 
                                                          
     
  void arm_biquad_cascade_df2T_init_f64(
        arm_biquad_cascade_df2T_instance_f64 * S,
        uint8_t numStages,
        float64_t * pCoeffs,
        float64_t * pState);


     
                                                              
     
  typedef struct
  {
          uint16_t numStages;                                                  
          q15_t *pState;                                                                                                    
    const q15_t *pCoeffs;                                                                                                
  } arm_fir_lattice_instance_q15;

     
                                                              
     
  typedef struct
  {
          uint16_t numStages;                                                  
          q31_t *pState;                                                                                                    
    const q31_t *pCoeffs;                                                                                                
  } arm_fir_lattice_instance_q31;

     
                                                                         
     
  typedef struct
  {
          uint16_t numStages;                                                  
          float32_t *pState;                                                                                                
    const float32_t *pCoeffs;                                                                                            
  } arm_fir_lattice_instance_f32;


     
                                                                   
                                                                                  
                                                   
                                                                                               
                                                                                         
     
  void arm_fir_lattice_init_q15(
        arm_fir_lattice_instance_q15 * S,
        uint16_t numStages,
  const q15_t * pCoeffs,
        q15_t * pState);


     
                                                               
                                                                                   
                                                              
                                                               
                                                         
     
  void arm_fir_lattice_q15(
  const arm_fir_lattice_instance_q15 * S,
  const q15_t * pSrc,
        q15_t * pDst,
        uint32_t blockSize);


     
                                                                   
                                                                                  
                                                   
                                                                                               
                                                                                          
     
  void arm_fir_lattice_init_q31(
        arm_fir_lattice_instance_q31 * S,
        uint16_t numStages,
  const q31_t * pCoeffs,
        q31_t * pState);


     
                                                               
                                                                                   
                                                              
                                                              
                                                         
     
  void arm_fir_lattice_q31(
  const arm_fir_lattice_instance_q31 * S,
  const q31_t * pSrc,
        q31_t * pDst,
        uint32_t blockSize);


   
                                                                            
                                                                                           
                                                 
                                                                                             
                                                                                       
   
  void arm_fir_lattice_init_f32(
        arm_fir_lattice_instance_f32 * S,
        uint16_t numStages,
  const float32_t * pCoeffs,
        float32_t * pState);


     
                                                                          
                                                                                              
                                                              
                                                              
                                                         
     
  void arm_fir_lattice_f32(
  const arm_fir_lattice_instance_f32 * S,
  const float32_t * pSrc,
        float32_t * pDst,
        uint32_t blockSize);


     
                                                              
     
  typedef struct
  {
          uint16_t numStages;                                                         
          q15_t *pState;                                                                                                              
          q15_t *pkCoeffs;                                                                                                          
          q15_t *pvCoeffs;                                                                                                        
  } arm_iir_lattice_instance_q15;

     
                                                              
     
  typedef struct
  {
          uint16_t numStages;                                                         
          q31_t *pState;                                                                                                              
          q31_t *pkCoeffs;                                                                                                          
          q31_t *pvCoeffs;                                                                                                        
  } arm_iir_lattice_instance_q31;

     
                                                                         
     
  typedef struct
  {
          uint16_t numStages;                                                         
          float32_t *pState;                                                                                                          
          float32_t *pkCoeffs;                                                                                                      
          float32_t *pvCoeffs;                                                                                                    
  } arm_iir_lattice_instance_f32;


     
                                                                          
                                                                                              
                                                              
                                                               
                                                         
     
  void arm_iir_lattice_f32(
  const arm_iir_lattice_instance_f32 * S,
  const float32_t * pSrc,
        float32_t * pDst,
        uint32_t blockSize);


     
                                                                              
                                                                                             
                                                          
                                                                                                          
                                                                                                        
                                                                                                     
                                                        
     
  void arm_iir_lattice_init_f32(
        arm_iir_lattice_instance_f32 * S,
        uint16_t numStages,
        float32_t * pkCoeffs,
        float32_t * pvCoeffs,
        float32_t * pState,
        uint32_t blockSize);


     
                                                               
                                                                                   
                                                              
                                                               
                                                         
     
  void arm_iir_lattice_q31(
  const arm_iir_lattice_instance_q31 * S,
  const q31_t * pSrc,
        q31_t * pDst,
        uint32_t blockSize);


     
                                                                   
                                                                                  
                                                          
                                                                                                          
                                                                                                        
                                                                                                   
                                                        
     
  void arm_iir_lattice_init_q31(
        arm_iir_lattice_instance_q31 * S,
        uint16_t numStages,
        q31_t * pkCoeffs,
        q31_t * pvCoeffs,
        q31_t * pState,
        uint32_t blockSize);


     
                                                               
                                                                                   
                                                              
                                                               
                                                         
     
  void arm_iir_lattice_q15(
  const arm_iir_lattice_instance_q15 * S,
  const q15_t * pSrc,
        q15_t * pDst,
        uint32_t blockSize);


   
                                                                 
                                                                                            
                                                        
                                                                                                    
                                                                                                  
                                                                                             
                                                               
   
  void arm_iir_lattice_init_q15(
        arm_iir_lattice_instance_q15 * S,
        uint16_t numStages,
        q15_t * pkCoeffs,
        q15_t * pvCoeffs,
        q15_t * pState,
        uint32_t blockSize);


     
                                                                 
     
  typedef struct
  {
          uint16_t numTaps;                                                 
          float32_t *pState;                                                                                          
          float32_t *pCoeffs;                                                                          
          float32_t mu;                                                                   
  } arm_lms_instance_f32;


     
                                                              
                                                                                             
                                                              
                                                                  
                                                               
                                                              
                                                         
     
  void arm_lms_f32(
  const arm_lms_instance_f32 * S,
  const float32_t * pSrc,
        float32_t * pRef,
        float32_t * pOut,
        float32_t * pErr,
        uint32_t blockSize);


     
                                                                  
                                                                                            
                                                         
                                                            
                                                  
                                                                              
                                                        
     
  void arm_lms_init_f32(
        arm_lms_instance_f32 * S,
        uint16_t numTaps,
        float32_t * pCoeffs,
        float32_t * pState,
        float32_t mu,
        uint32_t blockSize);


     
                                                      
     
  typedef struct
  {
          uint16_t numTaps;                                                 
          q15_t *pState;                                                                                              
          q15_t *pCoeffs;                                                                              
          q15_t mu;                                                                       
          uint32_t postShift;                                            
  } arm_lms_instance_q15;


     
                                                           
                                                                                 
                                                         
                                                            
                                                      
                                                                              
                                                        
                                                             
     
  void arm_lms_init_q15(
        arm_lms_instance_q15 * S,
        uint16_t numTaps,
        q15_t * pCoeffs,
        q15_t * pState,
        q15_t mu,
        uint32_t blockSize,
        uint32_t postShift);


     
                                                   
                                                                                  
                                                              
                                                                  
                                                               
                                                              
                                                         
     
  void arm_lms_q15(
  const arm_lms_instance_q15 * S,
  const q15_t * pSrc,
        q15_t * pRef,
        q15_t * pOut,
        q15_t * pErr,
        uint32_t blockSize);


     
                                                      
     
  typedef struct
  {
          uint16_t numTaps;                                                 
          q31_t *pState;                                                                                              
          q31_t *pCoeffs;                                                                              
          q31_t mu;                                                                       
          uint32_t postShift;                                            
  } arm_lms_instance_q31;


     
                                                   
                                                                                  
                                                              
                                                                  
                                                               
                                                              
                                                         
     
  void arm_lms_q31(
  const arm_lms_instance_q31 * S,
  const q31_t * pSrc,
        q31_t * pRef,
        q31_t * pOut,
        q31_t * pErr,
        uint32_t blockSize);


     
                                                       
                                                                                 
                                                         
                                                        
                                                  
                                                                              
                                                        
                                                             
     
  void arm_lms_init_q31(
        arm_lms_instance_q31 * S,
        uint16_t numTaps,
        q31_t * pCoeffs,
        q31_t * pState,
        q31_t mu,
        uint32_t blockSize,
        uint32_t postShift);


     
                                                                            
     
  typedef struct
  {
          uint16_t numTaps;                                                  
          float32_t *pState;                                                                                           
          float32_t *pCoeffs;                                                                           
          float32_t mu;                                                                   
          float32_t energy;                                         
          float32_t x0;                                             
  } arm_lms_norm_instance_f32;


     
                                                                         
                                                                                                        
                                                              
                                                                  
                                                               
                                                              
                                                         
     
  void arm_lms_norm_f32(
        arm_lms_norm_instance_f32 * S,
  const float32_t * pSrc,
        float32_t * pRef,
        float32_t * pOut,
        float32_t * pErr,
        uint32_t blockSize);


     
                                                                             
                                                                                            
                                                         
                                                        
                                                  
                                                                              
                                                        
     
  void arm_lms_norm_init_f32(
        arm_lms_norm_instance_f32 * S,
        uint16_t numTaps,
        float32_t * pCoeffs,
        float32_t * pState,
        float32_t mu,
        uint32_t blockSize);


     
                                                                 
     
  typedef struct
  {
          uint16_t numTaps;                                                  
          q31_t *pState;                                                                                               
          q31_t *pCoeffs;                                                                               
          q31_t mu;                                                                        
          uint8_t postShift;                                              
    const q31_t *recipTable;                                                         
          q31_t energy;                                             
          q31_t x0;                                                 
  } arm_lms_norm_instance_q31;


     
                                                              
                                                                                             
                                                              
                                                                  
                                                               
                                                              
                                                         
     
  void arm_lms_norm_q31(
        arm_lms_norm_instance_q31 * S,
  const q31_t * pSrc,
        q31_t * pRef,
        q31_t * pOut,
        q31_t * pErr,
        uint32_t blockSize);


     
                                                                  
                                                                                            
                                                         
                                                        
                                                  
                                                                              
                                                        
                                                             
     
  void arm_lms_norm_init_q31(
        arm_lms_norm_instance_q31 * S,
        uint16_t numTaps,
        q31_t * pCoeffs,
        q31_t * pState,
        q31_t mu,
        uint32_t blockSize,
        uint8_t postShift);


     
                                                                 
     
  typedef struct
  {
          uint16_t numTaps;                                                  
          q15_t *pState;                                                                                               
          q15_t *pCoeffs;                                                                               
          q15_t mu;                                                                        
          uint8_t postShift;                                              
    const q15_t *recipTable;                                                         
          q15_t energy;                                             
          q15_t x0;                                                 
  } arm_lms_norm_instance_q15;


     
                                                              
                                                                                             
                                                              
                                                                  
                                                               
                                                              
                                                         
     
  void arm_lms_norm_q15(
        arm_lms_norm_instance_q15 * S,
  const q15_t * pSrc,
        q15_t * pRef,
        q15_t * pOut,
        q15_t * pErr,
        uint32_t blockSize);


     
                                                                  
                                                                                            
                                                         
                                                        
                                                  
                                                                              
                                                        
                                                             
     
  void arm_lms_norm_init_q15(
        arm_lms_norm_instance_q15 * S,
        uint16_t numTaps,
        q15_t * pCoeffs,
        q15_t * pState,
        q15_t mu,
        uint32_t blockSize,
        uint8_t postShift);


     
                                                    
                                                             
                                                             
                                                              
                                                              
                                                                                                   
     
  void arm_correlate_f32(
  const float32_t * pSrcA,
        uint32_t srcALen,
  const float32_t * pSrcB,
        uint32_t srcBLen,
        float32_t * pDst);


   
                                    
                                                         
                                                         
                                                          
                                                          
                                                                                                
                                                                                                            
  
void arm_correlate_opt_q15(
  const q15_t * pSrcA,
        uint32_t srcALen,
  const q15_t * pSrcB,
        uint32_t srcBLen,
        q15_t * pDst,
        q15_t * pScratch);


   
                                      
                                                         
                                                         
                                                          
                                                          
                                                                                                
   
  void arm_correlate_q15(
  const q15_t * pSrcA,
        uint32_t srcALen,
  const q15_t * pSrcB,
        uint32_t srcBLen,
        q15_t * pDst);


   
                                                             
                                                              
                                                              
                                                               
                                                               
                                                                                                                             
                     
   
void arm_correlate_fast_q15(
  const q15_t * pSrcA,
        uint32_t srcALen,
  const q15_t * pSrcB,
        uint32_t srcBLen,
        q15_t * pDst);


   
                                                     
                                                           
                                                           
                                                            
                                                            
                                                                                                 
                                                                                                             
   
void arm_correlate_fast_opt_q15(
  const q15_t * pSrcA,
        uint32_t srcALen,
  const q15_t * pSrcB,
        uint32_t srcBLen,
        q15_t * pDst,
        q15_t * pScratch);


     
                                         
                                                             
                                                             
                                                              
                                                              
                                                                                                   
     
  void arm_correlate_q31(
  const q31_t * pSrcA,
        uint32_t srcALen,
  const q31_t * pSrcB,
        uint32_t srcBLen,
        q31_t * pDst);


   
                                                     
                                                         
                                                         
                                                          
                                                          
                                                                                                
   
void arm_correlate_fast_q31(
  const q31_t * pSrcA,
        uint32_t srcALen,
  const q31_t * pSrcB,
        uint32_t srcBLen,
        q31_t * pDst);


    
                                        
                                                               
                                                               
                                                                
                                                                
                                                                                                     
                                                                                                                                
                                                                                                   
     
  void arm_correlate_opt_q7(
  const q7_t * pSrcA,
        uint32_t srcALen,
  const q7_t * pSrcB,
        uint32_t srcBLen,
        q7_t * pDst,
        q15_t * pScratch1,
        q15_t * pScratch2);


     
                                        
                                                             
                                                             
                                                              
                                                              
                                                                                                   
     
  void arm_correlate_q7(
  const q7_t * pSrcA,
        uint32_t srcALen,
  const q7_t * pSrcB,
        uint32_t srcBLen,
        q7_t * pDst);


     
                                                                        
     
  typedef struct
  {
          uint16_t numTaps;                                                          
          uint16_t stateIndex;                                                                                       
          float32_t *pState;                                                                                                  
    const float32_t *pCoeffs;                                                                                  
          uint16_t maxDelay;                                                                    
          int32_t *pTapDelay;                                                                                        
  } arm_fir_sparse_instance_f32;

     
                                                             
     
  typedef struct
  {
          uint16_t numTaps;                                                          
          uint16_t stateIndex;                                                                                       
          q31_t *pState;                                                                                                      
    const q31_t *pCoeffs;                                                                                      
          uint16_t maxDelay;                                                                    
          int32_t *pTapDelay;                                                                                        
  } arm_fir_sparse_instance_q31;

     
                                                             
     
  typedef struct
  {
          uint16_t numTaps;                                                          
          uint16_t stateIndex;                                                                                       
          q15_t *pState;                                                                                                      
    const q15_t *pCoeffs;                                                                                      
          uint16_t maxDelay;                                                                    
          int32_t *pTapDelay;                                                                                        
  } arm_fir_sparse_instance_q15;

     
                                                            
     
  typedef struct
  {
          uint16_t numTaps;                                                          
          uint16_t stateIndex;                                                                                       
          q7_t *pState;                                                                                                       
    const q7_t *pCoeffs;                                                                                       
          uint16_t maxDelay;                                                                    
          int32_t *pTapDelay;                                                                                        
  } arm_fir_sparse_instance_q7;


     
                                                                         
                                                                                              
                                                               
                                                               
                                                                            
                                                                         
     
  void arm_fir_sparse_f32(
        arm_fir_sparse_instance_f32 * S,
  const float32_t * pSrc,
        float32_t * pDst,
        float32_t * pScratchIn,
        uint32_t blockSize);


     
                                                                              
                                                                                                
                                                                            
                                                                          
                                                          
                                                                   
                                                             
                                                                                  
     
  void arm_fir_sparse_init_f32(
        arm_fir_sparse_instance_f32 * S,
        uint16_t numTaps,
  const float32_t * pCoeffs,
        float32_t * pState,
        int32_t * pTapDelay,
        uint16_t maxDelay,
        uint32_t blockSize);


     
                                                              
                                                                                   
                                                               
                                                               
                                                                            
                                                                         
     
  void arm_fir_sparse_q31(
        arm_fir_sparse_instance_q31 * S,
  const q31_t * pSrc,
        q31_t * pDst,
        q31_t * pScratchIn,
        uint32_t blockSize);


     
                                                                   
                                                                                     
                                                                            
                                                                          
                                                          
                                                                   
                                                             
                                                                                  
     
  void arm_fir_sparse_init_q31(
        arm_fir_sparse_instance_q31 * S,
        uint16_t numTaps,
  const q31_t * pCoeffs,
        q31_t * pState,
        int32_t * pTapDelay,
        uint16_t maxDelay,
        uint32_t blockSize);


     
                                                              
                                                                                    
                                                                
                                                                
                                                                             
                                                                             
                                                                          
     
  void arm_fir_sparse_q15(
        arm_fir_sparse_instance_q15 * S,
  const q15_t * pSrc,
        q15_t * pDst,
        q15_t * pScratchIn,
        q31_t * pScratchOut,
        uint32_t blockSize);


     
                                                                   
                                                                                     
                                                                            
                                                                          
                                                          
                                                                   
                                                             
                                                                                  
     
  void arm_fir_sparse_init_q15(
        arm_fir_sparse_instance_q15 * S,
        uint16_t numTaps,
  const q15_t * pCoeffs,
        q15_t * pState,
        int32_t * pTapDelay,
        uint16_t maxDelay,
        uint32_t blockSize);


     
                                                             
                                                                                   
                                                                
                                                                
                                                                             
                                                                             
                                                                          
     
  void arm_fir_sparse_q7(
        arm_fir_sparse_instance_q7 * S,
  const q7_t * pSrc,
        q7_t * pDst,
        q7_t * pScratchIn,
        q31_t * pScratchOut,
        uint32_t blockSize);


     
                                                                  
                                                                                    
                                                                            
                                                                          
                                                          
                                                                   
                                                             
                                                                                  
     
  void arm_fir_sparse_init_q7(
        arm_fir_sparse_instance_q7 * S,
        uint16_t numTaps,
  const q7_t * pCoeffs,
        q7_t * pState,
        int32_t * pTapDelay,
        uint16_t maxDelay,
        uint32_t blockSize);


     
                                             
                                               
                                                              
                                                             
     
  void arm_sin_cos_f32(
        float32_t theta,
        float32_t * pSinVal,
        float32_t * pCosVal);


     
                                  
                                                       
                                                              
                                                                
     
  void arm_sin_cos_q31(
        q31_t theta,
        q31_t * pSinVal,
        q31_t * pCosVal);


     
                                              
                                                       
                                                        
                                                                     
     
  void arm_cmplx_conj_f32(
  const float32_t * pSrc,
        float32_t * pDst,
        uint32_t numSamples);

     
                                   
                                                       
                                                        
                                                                     
     
  void arm_cmplx_conj_q31(
  const q31_t * pSrc,
        q31_t * pDst,
        uint32_t numSamples);


     
                                   
                                                       
                                                        
                                                                     
     
  void arm_cmplx_conj_q15(
  const q15_t * pSrc,
        q15_t * pDst,
        uint32_t numSamples);


     
                                                     
                                                               
                                                             
                                                                          
     
  void arm_cmplx_mag_squared_f32(
  const float32_t * pSrc,
        float32_t * pDst,
        uint32_t numSamples);


     
                                          
                                                               
                                                             
                                                                          
     
  void arm_cmplx_mag_squared_q31(
  const q31_t * pSrc,
        q31_t * pDst,
        uint32_t numSamples);


     
                                          
                                                               
                                                             
                                                                          
     
  void arm_cmplx_mag_squared_q15(
  const q15_t * pSrc,
        q15_t * pDst,
        uint32_t numSamples);


    
                             
     

     
                                    
    
                                                                                      
                                                              
                                                                            
    
                                                       
                                                                                           
                                                                            
                                                                                             
                                                                      
    
                    
          
                                                             
                         
                               
               
           
    
         
                                                                                                      
    
         
                                                                      
    
         
                                                                             
                                                 
                                                                                           
                                                                         
                                                                                  
                                                                                                             
    
                            
                                                                                                                     
                                                                           
                                                                                               
    
                         
                                                                                                
    
                                  
                                                                            
                                                                   
                                                             
                                                
    
         
                                                                                                                            
    
                              
                                                                                            
                                                                                                                     
                                                                             
     

     
                    
       
     

     
                                                                        
                                                                                  
                                               
                                            
     
  __STATIC_FORCEINLINE float32_t arm_pid_f32(
  arm_pid_instance_f32 * S,
  float32_t in)
  {
    float32_t out;

                                                                
    out = (S->A0 * in) +
      (S->A1 * S->state[0]) + (S->A2 * S->state[1]) + (S->state[2]);

                      
    S->state[1] = S->state[0];
    S->state[0] = in;
    S->state[2] = out;

                               
    return (out);

  }

   
                                                          
                                                                          
                                            
                                         

                                    
                                                                          
                                                                                                                                                        
                                                                                    
                                                                                                                           
                                                                                                                                          
   
__STATIC_FORCEINLINE q31_t arm_pid_q31(
  arm_pid_instance_q31 * S,
  q31_t in)
  {
    q63_t acc;
    q31_t out;

                          
    acc = (q63_t) S->A0 * in;

                            
    acc += (q63_t) S->A1 * S->state[0];

                             
    acc += (q63_t) S->A2 * S->state[1];

                                                     
    out = (q31_t) (acc >> 31U);

                       
    out += S->state[2];

                      
    S->state[1] = S->state[0];
    S->state[0] = in;
    S->state[2] = out;

                               
    return (out);
  }


   
                                                          
                                                                           
                                            
                                         

                                    
                                                                         
                                                                                                               
                                                                                               
                                                                                                                                      
                                                                                                                         
                                                                               
   
__STATIC_FORCEINLINE q15_t arm_pid_q15(
  arm_pid_instance_q15 * S,
  q15_t in)
  {
    q63_t acc;
    q15_t out;

#if defined (ARM_MATH_DSP)
                                          

                          
    acc = (q31_t) __SMUAD((uint32_t)S->A0, (uint32_t)in);

                                           
    acc = (q63_t)__SMLALD((uint32_t)S->A1, (uint32_t)read_q15x2 (S->state), (uint64_t)acc);
#else
                          
    acc = ((q31_t) S->A0) * in;

                                           
    acc += (q31_t) S->A1 * S->state[0];
    acc += (q31_t) S->A2 * S->state[1];
#endif

                       
    acc += (q31_t) S->state[2] << 15;

                             
    out = (q15_t) (__SSAT((acc >> 15), 16));

                      
    S->state[1] = S->state[0];
    S->state[0] = in;
    S->state[2] = out;

                               
    return (out);
  }

     
                        
     


     
                                          
                                                                                           
                                                                                            
                                                                                         
                                                                                                                                          
     
  arm_status arm_mat_inverse_f32(
  const arm_matrix_instance_f32 * src,
  arm_matrix_instance_f32 * dst);


     
                                          
                                                                                           
                                                                                            
                                                                                         
                                                                                                                                          
     
  arm_status arm_mat_inverse_f64(
  const arm_matrix_instance_f64 * src,
  arm_matrix_instance_f64 * dst);



     
                             
     

     
                                             
                                                                                                                   
                                                                                                              
                                                                                        
                                                                                             
                                                                                    
                                                                                                    
                                                                      
    
                                                                                                                 
                                                                                   
                   
                                  
                                                                                      
                                                                                                   
                              
                                                                           
                                                                                                    
                                                                             
     

     
                       
       
     

     
    
                                            
                                                                     
                                                                     
                                                                                 
                                                                                
                        
     
  __STATIC_FORCEINLINE void arm_clarke_f32(
  float32_t Ia,
  float32_t Ib,
  float32_t * pIalpha,
  float32_t * pIbeta)
  {
                                                            
    *pIalpha = Ia;

                                                                                           
    *pIbeta = ((float32_t) 0.57735026919 * Ia + (float32_t) 1.15470053838 * Ib);
  }


   
                                          
                                                                  
                                                                  
                                                                              
                                                                             
                  

                                    
                                                                          
                                                                                                                             
                                                                                 
   
__STATIC_FORCEINLINE void arm_clarke_q31(
  q31_t Ia,
  q31_t Ib,
  q31_t * pIalpha,
  q31_t * pIbeta)
  {
    q31_t product1, product2;                                                                                

                                                              
    *pIalpha = Ia;

                                                                  
    product1 = (q31_t) (((q63_t) Ia * 0x24F34E8B) >> 30);

                                                                
    product2 = (q31_t) (((q63_t) Ib * 0x49E69D16) >> 30);

                                                                  
    *pIbeta = __QADD(product1, product2);
  }

     
                           
     


     
                             
     

     
                                                         
                                                                                                                 
    
                                                                                                                 
                                                                                   
                   
                                     
                                                                                        
                                                                                                 
                              
                                                                           
                                                                                                    
                                                                             
     

     
                           
       
     

      
                                                    
                                                                     
                                                                    
                                                                               
                                                                               
                     
     
  __STATIC_FORCEINLINE void arm_inv_clarke_f32(
  float32_t Ialpha,
  float32_t Ibeta,
  float32_t * pIa,
  float32_t * pIb)
  {
                                                              
    *pIa = Ialpha;

                                                                                                       
    *pIb = -0.5f * Ialpha + 0.8660254039f * Ibeta;
  }


   
                                                  
                                                                  
                                                                 
                                                                            
                                                                            
                  

                                    
                                                                          
                                                                                                                             
                                                                                    
   
__STATIC_FORCEINLINE void arm_inv_clarke_q31(
  q31_t Ialpha,
  q31_t Ibeta,
  q31_t * pIa,
  q31_t * pIb)
  {
    q31_t product1, product2;                                                                                

                                                              
    *pIa = Ialpha;

                                                                    
    product1 = (q31_t) (((q63_t) (Ialpha) * (0x40000000)) >> 31);

                                                                 
    product2 = (q31_t) (((q63_t) (Ibeta) * (0x6ED9EBA1)) >> 31);

                                                       
    *pIb = __QSUB(product2, product1);
  }

     
                               
     



     
                             
     

     
                                         
    
                                                                                                   
                                                                                                                                
                                                                                                   
                                                     
                                                                                       
                                                                       
                                                                                                                          
    
                                                                                                                 
                                                                                   
                   
                                
                                                                                       
                                                                                                                              
                                                           
                              
                                                                         
                                                                                                    
                                                                             
     

     
                     
       
     

     
                                         
                                                                
                                                               
                                                                   
                                                                   
                                                           
                                                             
                     
    
                                                        
    
     
  __STATIC_FORCEINLINE void arm_park_f32(
  float32_t Ialpha,
  float32_t Ibeta,
  float32_t * pId,
  float32_t * pIq,
  float32_t sinVal,
  float32_t cosVal)
  {
                                                                                  
    *pId = Ialpha * cosVal + Ibeta * sinVal;

                                                                                    
    *pIq = -Ialpha * sinVal + Ibeta * cosVal;
  }


   
                                        
                                                             
                                                            
                                                              
                                                              
                                                        
                                                          
                  

                                    
                                                                          
                                                                                                                             
                                                                                                 
   
__STATIC_FORCEINLINE void arm_park_q31(
  q31_t Ialpha,
  q31_t Ibeta,
  q31_t * pId,
  q31_t * pIq,
  q31_t sinVal,
  q31_t cosVal)
  {
    q31_t product1, product2;                                                                                
    q31_t product3, product4;                                                                                

                                                                 
    product1 = (q31_t) (((q63_t) (Ialpha) * (cosVal)) >> 31);

                                                                
    product2 = (q31_t) (((q63_t) (Ibeta) * (sinVal)) >> 31);


                                                                 
    product3 = (q31_t) (((q63_t) (Ialpha) * (sinVal)) >> 31);

                                                                
    product4 = (q31_t) (((q63_t) (Ibeta) * (cosVal)) >> 31);

                                                                       
    *pId = __QADD(product1, product2);

                                                                             
    *pIq = __QSUB(product4, product3);
  }

     
                         
     


     
                             
     

     
                                                     
                                                                                                   
    
                                                                                                                 
                                                                                   
                   
                                   
                                                                                         
                                                                                                                            
                                                           
                              
                                                                         
                                                                                                    
                                                                             
     

     
                         
       
     

      
                                                  
                                                                     
                                                                     
                                                                                 
                                                                                
                                                            
                                                              
                     
     
  __STATIC_FORCEINLINE void arm_inv_park_f32(
  float32_t Id,
  float32_t Iq,
  float32_t * pIalpha,
  float32_t * pIbeta,
  float32_t sinVal,
  float32_t cosVal)
  {
                                                                                   
    *pIalpha = Id * cosVal - Iq * sinVal;

                                                                                 
    *pIbeta = Id * sinVal + Iq * cosVal;
  }


   
                                                  
                                                                  
                                                                  
                                                                              
                                                                             
                                                         
                                                           
                  

                                    
                                                                          
                                                                                                                             
                                                                                 
   
__STATIC_FORCEINLINE void arm_inv_park_q31(
  q31_t Id,
  q31_t Iq,
  q31_t * pIalpha,
  q31_t * pIbeta,
  q31_t sinVal,
  q31_t cosVal)
  {
    q31_t product1, product2;                                                                                
    q31_t product3, product4;                                                                                

                                                             
    product1 = (q31_t) (((q63_t) (Id) * (cosVal)) >> 31);

                                                             
    product2 = (q31_t) (((q63_t) (Iq) * (sinVal)) >> 31);


                                                             
    product3 = (q31_t) (((q63_t) (Id) * (sinVal)) >> 31);

                                                             
    product4 = (q31_t) (((q63_t) (Iq) * (cosVal)) >> 31);

                                                                          
    *pIalpha = __QSUB(product1, product2);

                                                                         
    *pIbeta = __QADD(product4, product3);
  }

     
                                 
     


     
                                
     

     
                                                     
    
                                                                                
                                                                                                                                                          
    
         
                                                        
    
         
                                                                                   
                                                                                                                                        
    
                    
          
                                                  
                                                     
                                                      
           
    
         
                                                                  
                                                                                        
                                                                                   
                                                                                            
                                                                                      
    
         
                                                                                                 
                                                                                   
     

     
                                  
       
     

     
                                                                                   
                                                                                          
                                              
                                       
    
     
  __STATIC_FORCEINLINE float32_t arm_linear_interp_f32(
  arm_linear_interp_instance_f32 * S,
  float32_t x)
  {
    float32_t y;
    float32_t x0, x1;                                                      
    float32_t y0, y1;                                                       
    float32_t xSpacing = S->xSpacing;                                              
    int32_t i;                                                       
    float32_t *pYData = S->pYData;                                            

                              
    i = (int32_t) ((x - S->x1) / xSpacing);

    if (i < 0)
    {
                                                                                      
      y = pYData[0];
    }
    else if ((uint32_t)i >= S->nValues)
    {
                                                                                     
      y = pYData[S->nValues - 1];
    }
    else
    {
                                               
      x0 = S->x1 +  i      * xSpacing;
      x1 = S->x1 + (i + 1) * xSpacing;

                                         
      y0 = pYData[i];
      y1 = pYData[i + 1];

                                 
      y = y0 + (x - x0) * ((y1 - y0) / (x1 - x0));

    }

                              
    return (y);
  }


      
    
                                                                        
                                                                  
                                                
                                               
                                       
    
         
                                                                                                                           
                                                          
    
     
  __STATIC_FORCEINLINE q31_t arm_linear_interp_q31(
  q31_t * pYData,
  q31_t x,
  uint32_t nValues)
  {
    q31_t y;                                                 
    q31_t y0, y1;                                                           
    q31_t fract;                                                      
    int32_t index;                                                                        

                                  
                                     
                                 
    index = ((x & (q31_t)0xFFF00000) >> 20);

    if (index >= (int32_t)(nValues - 1))
    {
      return (pYData[nValues - 1]);
    }
    else if (index < 0)
    {
      return (pYData[0]);
    }
    else
    {
                                           
                                                         
      fract = (x & 0x000FFFFF) << 11;

                                                                             
      y0 = pYData[index];
      y1 = pYData[index + 1];

                                                                 
      y = ((q31_t) ((q63_t) y0 * (0x7FFFFFFF - fract) >> 32));

                                                                             
      y += ((q31_t) (((q63_t) y1 * fract) >> 32));

                                    
      return (y << 1U);
    }
  }


     
    
                                                                        
                                                                  
                                                
                                               
                                       
    
         
                                                                                                                           
                                                          
    
     
  __STATIC_FORCEINLINE q15_t arm_linear_interp_q15(
  q15_t * pYData,
  q31_t x,
  uint32_t nValues)
  {
    q63_t y;                                                 
    q15_t y0, y1;                                                           
    q31_t fract;                                                      
    int32_t index;                                                                        

                                  
                                     
                                 
    index = ((x & (int32_t)0xFFF00000) >> 20);

    if (index >= (int32_t)(nValues - 1))
    {
      return (pYData[nValues - 1]);
    }
    else if (index < 0)
    {
      return (pYData[0]);
    }
    else
    {
                                           
                                    
      fract = (x & 0x000FFFFF);

                                                         
      y0 = pYData[index];
      y1 = pYData[index + 1];

                                                                  
      y = ((q63_t) y0 * (0xFFFFF - fract));

                                                                                 
      y += ((q63_t) y1 * (fract));

                                    
      return (q15_t) (y >> 20);
    }
  }


     
    
                                                                       
                                                                 
                                                
                                               
                                       
    
         
                                                                                                                           
                                                          
     
  __STATIC_FORCEINLINE q7_t arm_linear_interp_q7(
  q7_t * pYData,
  q31_t x,
  uint32_t nValues)
  {
    q31_t y;                                                 
    q7_t y0, y1;                                                            
    q31_t fract;                                                      
    uint32_t index;                                                                       

                                  
                                     
                                 
    if (x < 0)
    {
      return (pYData[0]);
    }
    index = (x >> 20) & 0xfff;

    if (index >= (nValues - 1))
    {
      return (pYData[nValues - 1]);
    }
    else
    {
                                           
                                    
      fract = (x & 0x000FFFFF);

                                                                                   
      y0 = pYData[index];
      y1 = pYData[index + 1];

                                                                        
      y = ((y0 * (0xFFFFF - fract)));

                                                                                    
      y += (y1 * fract);

                                       
      return (q7_t) (y >> 20);
     }
  }

     
                                      
     

     
                                                                                           
                                          
                     
     
  float32_t arm_sin_f32(
  float32_t x);


     
                                                                                
                                                 
                     
     
  q31_t arm_sin_q31(
  q31_t x);


     
                                                                                
                                                 
                     
     
  q15_t arm_sin_q15(
  q15_t x);


     
                                                                                             
                                          
                     
     
  float32_t arm_cos_f32(
  float32_t x);


     
                                                                                 
                                                 
                     
     
  q31_t arm_cos_q31(
  q31_t x);


     
                                                                                  
                                                 
                     
     
  q15_t arm_cos_q15(
  q15_t x);


     
                           
     


     
                               
    
                                          
                                                                              
                                                                             
                                                
          
                                
           
                                                   
                                                  
                                                                                            
                                                            
          
                                                          
                                                           
           
     


     
                     
       
     

   
                                                     
                                  
                                                 
                                 
                                                                           
                                                                                              
   
__STATIC_FORCEINLINE arm_status arm_sqrt_f32(
  float32_t in,
  float32_t * pOut)
  {
    if (in >= 0.0f)
    {
#if defined ( __CC_ARM )
  #if defined __TARGET_FPU_VFP
      *pOut = __sqrtf(in);
  #else
      *pOut = sqrtf(in);
  #endif

#elif defined ( __ICCARM__ )
  #if defined __ARMVFP__
      __ASM("VSQRT.F32 %0,%1" : "=t"(*pOut) : "t"(in));
  #else
      *pOut = sqrtf(in);
  #endif

#else
      *pOut = sqrtf(in);
#endif

      return (ARM_MATH_SUCCESS);
    }
    else
    {
      *pOut = 0.0f;
      return (ARM_MATH_ARGUMENT_ERROR);
    }
  }


   
                                          
                                                                                                       
                                                           
                                 
                                                                           
                                                                                              
   
arm_status arm_sqrt_q31(
  q31_t in,
  q31_t * pOut);


   
                                          
                                                                                               
                                                           
                                 
                                                                           
                                                                                              
   
arm_status arm_sqrt_q15(
  q15_t in,
  q15_t * pOut);

     
                                                        
                                    
                                                                
                                              
                                                                                                                 
                                                                                   
     
  void arm_vsqrt_f32(
  float32_t * pIn,
  float32_t * pOut,
  uint16_t len);

  void arm_vsqrt_q31(
  q31_t * pIn,
  q31_t * pOut,
  uint16_t len);

  void arm_vsqrt_q15(
  q15_t * pIn,
  q15_t * pOut,
  uint16_t len);

     
                         
     


     
                                                   
     
  __STATIC_FORCEINLINE void arm_circularWrite_f32(
  int32_t * circBuffer,
  int32_t L,
  uint16_t * writeOffset,
  int32_t bufferInc,
  const int32_t * src,
  int32_t srcInc,
  uint32_t blockSize)
  {
    uint32_t i = 0U;
    int32_t wOffset;

                                                  
                                                                      
    wOffset = *writeOffset;

                                 
    i = blockSize;

    while (i > 0U)
    {
                                                        
      circBuffer[wOffset] = *src;

                                    
      src += srcInc;

                                                                                 
      wOffset += bufferInc;
      if (wOffset >= L)
        wOffset -= L;

                                      
      i--;
    }

                                  
    *writeOffset = (uint16_t)wOffset;
  }



     
                                                  
     
  __STATIC_FORCEINLINE void arm_circularRead_f32(
  int32_t * circBuffer,
  int32_t L,
  int32_t * readOffset,
  int32_t bufferInc,
  int32_t * dst,
  int32_t * dst_base,
  int32_t dst_length,
  int32_t dstInc,
  uint32_t blockSize)
  {
    uint32_t i = 0U;
    int32_t rOffset;
    int32_t* dst_end;

                                                  
                                                                         
    rOffset = *readOffset;
    dst_end = dst_base + dst_length;

                                 
    i = blockSize;

    while (i > 0U)
    {
                                                                              
      *dst = circBuffer[rOffset];

                                    
      dst += dstInc;

      if (dst == dst_end)
      {
        dst = dst_base;
      }

                                                                                  
      rOffset += bufferInc;

      if (rOffset >= L)
      {
        rOffset -= L;
      }

                                      
      i--;
    }

                                  
    *readOffset = rOffset;
  }


     
                                        
     
  __STATIC_FORCEINLINE void arm_circularWrite_q15(
  q15_t * circBuffer,
  int32_t L,
  uint16_t * writeOffset,
  int32_t bufferInc,
  const q15_t * src,
  int32_t srcInc,
  uint32_t blockSize)
  {
    uint32_t i = 0U;
    int32_t wOffset;

                                                  
                                                                      
    wOffset = *writeOffset;

                                 
    i = blockSize;

    while (i > 0U)
    {
                                                        
      circBuffer[wOffset] = *src;

                                    
      src += srcInc;

                                                                                 
      wOffset += bufferInc;
      if (wOffset >= L)
        wOffset -= L;

                                      
      i--;
    }

                                  
    *writeOffset = (uint16_t)wOffset;
  }


     
                                       
     
  __STATIC_FORCEINLINE void arm_circularRead_q15(
  q15_t * circBuffer,
  int32_t L,
  int32_t * readOffset,
  int32_t bufferInc,
  q15_t * dst,
  q15_t * dst_base,
  int32_t dst_length,
  int32_t dstInc,
  uint32_t blockSize)
  {
    uint32_t i = 0;
    int32_t rOffset;
    q15_t* dst_end;

                                                  
                                                                         
    rOffset = *readOffset;

    dst_end = dst_base + dst_length;

                                 
    i = blockSize;

    while (i > 0U)
    {
                                                                              
      *dst = circBuffer[rOffset];

                                    
      dst += dstInc;

      if (dst == dst_end)
      {
        dst = dst_base;
      }

                                                                                 
      rOffset += bufferInc;

      if (rOffset >= L)
      {
        rOffset -= L;
      }

                                      
      i--;
    }

                                  
    *readOffset = rOffset;
  }


     
                                       
     
  __STATIC_FORCEINLINE void arm_circularWrite_q7(
  q7_t * circBuffer,
  int32_t L,
  uint16_t * writeOffset,
  int32_t bufferInc,
  const q7_t * src,
  int32_t srcInc,
  uint32_t blockSize)
  {
    uint32_t i = 0U;
    int32_t wOffset;

                                                  
                                                                      
    wOffset = *writeOffset;

                                 
    i = blockSize;

    while (i > 0U)
    {
                                                        
      circBuffer[wOffset] = *src;

                                    
      src += srcInc;

                                                                                 
      wOffset += bufferInc;
      if (wOffset >= L)
        wOffset -= L;

                                      
      i--;
    }

                                  
    *writeOffset = (uint16_t)wOffset;
  }


     
                                      
     
  __STATIC_FORCEINLINE void arm_circularRead_q7(
  q7_t * circBuffer,
  int32_t L,
  int32_t * readOffset,
  int32_t bufferInc,
  q7_t * dst,
  q7_t * dst_base,
  int32_t dst_length,
  int32_t dstInc,
  uint32_t blockSize)
  {
    uint32_t i = 0;
    int32_t rOffset;
    q7_t* dst_end;

                                                  
                                                                         
    rOffset = *readOffset;

    dst_end = dst_base + dst_length;

                                 
    i = blockSize;

    while (i > 0U)
    {
                                                                              
      *dst = circBuffer[rOffset];

                                    
      dst += dstInc;

      if (dst == dst_end)
      {
        dst = dst_base;
      }

                                                                                 
      rOffset += bufferInc;

      if (rOffset >= L)
      {
        rOffset -= L;
      }

                                      
      i--;
    }

                                  
    *readOffset = rOffset;
  }


     
                                                                
                                            
                                                               
                                            
     
  void arm_power_q31(
  const q31_t * pSrc,
        uint32_t blockSize,
        q63_t * pResult);


     
                                                                           
                                            
                                                               
                                            
     
  void arm_power_f32(
  const float32_t * pSrc,
        uint32_t blockSize,
        float32_t * pResult);


     
                                                                
                                            
                                                               
                                            
     
  void arm_power_q15(
  const q15_t * pSrc,
        uint32_t blockSize,
        q63_t * pResult);


     
                                                               
                                            
                                                               
                                            
     
  void arm_power_q7(
  const q7_t * pSrc,
        uint32_t blockSize,
        q31_t * pResult);


     
                                       
                                            
                                                               
                                            
     
  void arm_mean_q7(
  const q7_t * pSrc,
        uint32_t blockSize,
        q7_t * pResult);


     
                                        
                                            
                                                               
                                            
     
  void arm_mean_q15(
  const q15_t * pSrc,
        uint32_t blockSize,
        q15_t * pResult);


     
                                        
                                            
                                                               
                                            
     
  void arm_mean_q31(
  const q31_t * pSrc,
        uint32_t blockSize,
        q31_t * pResult);


     
                                                   
                                            
                                                               
                                            
     
  void arm_mean_f32(
  const float32_t * pSrc,
        uint32_t blockSize,
        float32_t * pResult);


     
                                                                 
                                            
                                                               
                                            
     
  void arm_var_f32(
  const float32_t * pSrc,
        uint32_t blockSize,
        float32_t * pResult);


     
                                                      
                                            
                                                               
                                            
     
  void arm_var_q31(
  const q31_t * pSrc,
        uint32_t blockSize,
        q31_t * pResult);


     
                                                      
                                            
                                                               
                                            
     
  void arm_var_q15(
  const q15_t * pSrc,
        uint32_t blockSize,
        q15_t * pResult);


     
                                                                         
                                            
                                                               
                                            
     
  void arm_rms_f32(
  const float32_t * pSrc,
        uint32_t blockSize,
        float32_t * pResult);


     
                                                              
                                            
                                                               
                                            
     
  void arm_rms_q31(
  const q31_t * pSrc,
        uint32_t blockSize,
        q31_t * pResult);


     
                                                              
                                            
                                                               
                                            
     
  void arm_rms_q15(
  const q15_t * pSrc,
        uint32_t blockSize,
        q15_t * pResult);


     
                                                                           
                                            
                                                               
                                            
     
  void arm_std_f32(
  const float32_t * pSrc,
        uint32_t blockSize,
        float32_t * pResult);


     
                                                                
                                            
                                                               
                                            
     
  void arm_std_q31(
  const q31_t * pSrc,
        uint32_t blockSize,
        q31_t * pResult);


     
                                                                
                                            
                                                               
                                            
     
  void arm_std_q15(
  const q15_t * pSrc,
        uint32_t blockSize,
        q15_t * pResult);


     
                                             
                                                               
                                                             
                                                                          
     
  void arm_cmplx_mag_f32(
  const float32_t * pSrc,
        float32_t * pDst,
        uint32_t numSamples);


     
                                  
                                                               
                                                             
                                                                          
     
  void arm_cmplx_mag_q31(
  const q31_t * pSrc,
        q31_t * pDst,
        uint32_t numSamples);


     
                                  
                                                               
                                                             
                                                                          
     
  void arm_cmplx_mag_q15(
  const q15_t * pSrc,
        q15_t * pDst,
        uint32_t numSamples);


     
                                    
                                                             
                                                              
                                                                     
                                                                  
                                                                       
     
  void arm_cmplx_dot_prod_q15(
  const q15_t * pSrcA,
  const q15_t * pSrcB,
        uint32_t numSamples,
        q31_t * realResult,
        q31_t * imagResult);


     
                                    
                                                             
                                                              
                                                                     
                                                                  
                                                                       
     
  void arm_cmplx_dot_prod_q31(
  const q31_t * pSrcA,
  const q31_t * pSrcB,
        uint32_t numSamples,
        q63_t * realResult,
        q63_t * imagResult);


     
                                               
                                                             
                                                              
                                                                     
                                                                  
                                                                       
     
  void arm_cmplx_dot_prod_f32(
  const float32_t * pSrcA,
  const float32_t * pSrcB,
        uint32_t numSamples,
        float32_t * realResult,
        float32_t * imagResult);


     
                                               
                                                               
                                                            
                                                                
                                                             
     
  void arm_cmplx_mult_real_q15(
  const q15_t * pSrcCmplx,
  const q15_t * pSrcReal,
        q15_t * pCmplxDst,
        uint32_t numSamples);


     
                                               
                                                               
                                                            
                                                                
                                                             
     
  void arm_cmplx_mult_real_q31(
  const q31_t * pSrcCmplx,
  const q31_t * pSrcReal,
        q31_t * pCmplxDst,
        uint32_t numSamples);


     
                                                          
                                                               
                                                            
                                                                
                                                             
     
  void arm_cmplx_mult_real_f32(
  const float32_t * pSrcCmplx,
  const float32_t * pSrcReal,
        float32_t * pCmplxDst,
        uint32_t numSamples);


     
                                          
                                            
                                                               
                                             
                                                                                        
     
  void arm_min_q7(
  const q7_t * pSrc,
        uint32_t blockSize,
        q7_t * result,
        uint32_t * index);


     
                                           
                                            
                                                               
                                             
                                                                                        
     
  void arm_min_q15(
  const q15_t * pSrc,
        uint32_t blockSize,
        q15_t * pResult,
        uint32_t * pIndex);


     
                                           
                                            
                                                               
                                             
                                                                                        
     
  void arm_min_q31(
  const q31_t * pSrc,
        uint32_t blockSize,
        q31_t * pResult,
        uint32_t * pIndex);


     
                                                      
                                            
                                                               
                                             
                                                                                        
     
  void arm_min_f32(
  const float32_t * pSrc,
        uint32_t blockSize,
        float32_t * pResult,
        uint32_t * pIndex);


   
                                       
                                                    
                                                    
                                                     
                                                              
   
  void arm_max_q7(
  const q7_t * pSrc,
        uint32_t blockSize,
        q7_t * pResult,
        uint32_t * pIndex);


   
                                        
                                                    
                                                    
                                                     
                                                              
   
  void arm_max_q15(
  const q15_t * pSrc,
        uint32_t blockSize,
        q15_t * pResult,
        uint32_t * pIndex);


   
                                        
                                                    
                                                    
                                                     
                                                              
   
  void arm_max_q31(
  const q31_t * pSrc,
        uint32_t blockSize,
        q31_t * pResult,
        uint32_t * pIndex);


   
                                                   
                                                    
                                                    
                                                     
                                                              
   
  void arm_max_f32(
  const float32_t * pSrc,
        uint32_t blockSize,
        float32_t * pResult,
        uint32_t * pIndex);


     
                                                  
                                                             
                                                              
                                                        
                                                                     
     
  void arm_cmplx_mult_cmplx_q15(
  const q15_t * pSrcA,
  const q15_t * pSrcB,
        q15_t * pDst,
        uint32_t numSamples);


     
                                                  
                                                             
                                                              
                                                        
                                                                     
     
  void arm_cmplx_mult_cmplx_q31(
  const q31_t * pSrcA,
  const q31_t * pSrcB,
        q31_t * pDst,
        uint32_t numSamples);


     
                                                             
                                                             
                                                              
                                                        
                                                                     
     
  void arm_cmplx_mult_cmplx_f32(
  const float32_t * pSrcA,
  const float32_t * pSrcB,
        float32_t * pDst,
        uint32_t numSamples);


     
                                                                             
                                                                     
                                                           
                                                      
     
  void arm_float_to_q31(
  const float32_t * pSrc,
        q31_t * pDst,
        uint32_t blockSize);


     
                                                                             
                                                                     
                                                           
                                                      
     
  void arm_float_to_q15(
  const float32_t * pSrc,
        q15_t * pDst,
        uint32_t blockSize);


     
                                                                            
                                                                     
                                                          
                                                      
     
  void arm_float_to_q7(
  const float32_t * pSrc,
        q7_t * pDst,
        uint32_t blockSize);


     
                                                                              
                                            
                                             
                                                               
     
  void arm_q31_to_float(
  const q31_t * pSrc,
        float32_t * pDst,
        uint32_t blockSize);


     
                                                                   
                                            
                                             
                                                               
     
  void arm_q31_to_q15(
  const q31_t * pSrc,
        q15_t * pDst,
        uint32_t blockSize);


     
                                                                  
                                            
                                             
                                                               
     
  void arm_q31_to_q7(
  const q31_t * pSrc,
        q7_t * pDst,
        uint32_t blockSize);


     
                                                                              
                                            
                                             
                                                               
     
  void arm_q15_to_float(
  const q15_t * pSrc,
        float32_t * pDst,
        uint32_t blockSize);


     
                                                                   
                                            
                                             
                                                               
     
  void arm_q15_to_q31(
  const q15_t * pSrc,
        q31_t * pDst,
        uint32_t blockSize);


     
                                                                  
                                            
                                             
                                                               
     
  void arm_q15_to_q7(
  const q15_t * pSrc,
        q7_t * pDst,
        uint32_t blockSize);


     
                                                                             
                                            
                                             
                                                               
     
  void arm_q7_to_float(
  const q7_t * pSrc,
        float32_t * pDst,
        uint32_t blockSize);


     
                                                                  
                                         
                                          
                                                        
     
  void arm_q7_to_q31(
  const q7_t * pSrc,
        q31_t * pDst,
        uint32_t blockSize);


     
                                                                  
                                         
                                          
                                                        
     
  void arm_q7_to_q15(
  const q7_t * pSrc,
        q15_t * pDst,
        uint32_t blockSize);


     
                                
     

     
                                                         
    
                                                                                                      
                                                                                                            
                                               
                                                                                                                                 
                                                                                
                                                                                                                     
    
                     
         
                                                                                                                
                                                              
          
                     
        
                          
                          
                          
                                        
           
    
         
                                                                          
                                                                       
                                                                                           
                                                                                                                       
                                                                                                              
    
         
                                                                                   
          
                      
                      
           
         
                                                  
          
                                                   
                                                
                                                
                                              
           
                                                                                
                                                                               
                                                               
    
         
                                                                                            
     


     
                                    
       
     

     
                                                  
                                                                           
                                               
                                               
                                   
    
  __STATIC_FORCEINLINE float32_t arm_bilinear_interp_f32(
  const arm_bilinear_interp_instance_f32 * S,
  float32_t X,
  float32_t Y)
  {
    float32_t out;
    float32_t f00, f01, f10, f11;
    float32_t *pData = S->pData;
    int32_t xIndex, yIndex, index;
    float32_t xdiff, ydiff;
    float32_t b1, b2, b3, b4;

    xIndex = (int32_t) X;
    yIndex = (int32_t) Y;

                                               
                                                                    
    if (xIndex < 0 || xIndex > (S->numRows - 1) || yIndex < 0 || yIndex > (S->numCols - 1))
    {
      return (0);
    }

                                                                    
    index = (xIndex - 1) + (yIndex - 1) * S->numCols;


                                                
    f00 = pData[index];
    f01 = pData[index + 1];

                                                                    
    index = (xIndex - 1) + (yIndex) * S->numCols;


                                                
    f10 = pData[index];
    f11 = pData[index + 1];

                                            
    b1 = f00;
    b2 = f01 - f00;
    b3 = f10 - f00;
    b4 = f00 - f01 - f10 + f11;

                                             
    xdiff = X - xIndex;

                                             
    ydiff = Y - yIndex;

                                                      
    out = b1 + b2 * xdiff + b3 * ydiff + b4 * xdiff * ydiff;

                               
    return (out);
  }


     
                                       
                                                                           
                                                               
                                                               
                                   
    
  __STATIC_FORCEINLINE q31_t arm_bilinear_interp_q31(
  arm_bilinear_interp_instance_q31 * S,
  q31_t X,
  q31_t Y)
  {
    q31_t out;                                                         
    q31_t acc = 0;                                           
    q31_t xfract, yfract;                                                   
    q31_t x1, x2, y1, y2;                                                   
    int32_t rI, cI;                                                          
    q31_t *pYData = S->pData;                                                        
    uint32_t nCols = S->numCols;                                  

                                  
                                     
                                 
    rI = ((X & (q31_t)0xFFF00000) >> 20);

                                  
                                     
                                 
    cI = ((Y & (q31_t)0xFFF00000) >> 20);

                                               
                                                                    
    if (rI < 0 || rI > (S->numRows - 1) || cI < 0 || cI > (S->numCols - 1))
    {
      return (0);
    }

                                         
                                                     
    xfract = (X & 0x000FFFFF) << 11U;

                                                       
    x1 = pYData[(rI) + (int32_t)nCols * (cI)    ];
    x2 = pYData[(rI) + (int32_t)nCols * (cI) + 1];

                                         
                                                     
    yfract = (Y & 0x000FFFFF) << 11U;

                                                       
    y1 = pYData[(rI) + (int32_t)nCols * (cI + 1)    ];
    y2 = pYData[(rI) + (int32_t)nCols * (cI + 1) + 1];

                                                                                     
    out = ((q31_t) (((q63_t) x1  * (0x7FFFFFFF - xfract)) >> 32));
    acc = ((q31_t) (((q63_t) out * (0x7FFFFFFF - yfract)) >> 32));

                                                                    
    out = ((q31_t) ((q63_t) x2 * (0x7FFFFFFF - yfract) >> 32));
    acc += ((q31_t) ((q63_t) out * (xfract) >> 32));

                                                                      
    out = ((q31_t) ((q63_t) y1 * (0x7FFFFFFF - xfract) >> 32));
    acc += ((q31_t) ((q63_t) out * (yfract) >> 32));

                                                                  
    out = ((q31_t) ((q63_t) y2 * (xfract) >> 32));
    acc += ((q31_t) ((q63_t) out * (yfract) >> 32));

                                         
    return ((q31_t)(acc << 2));
  }


     
                                       
                                                                           
                                                               
                                                               
                                   
    
  __STATIC_FORCEINLINE q15_t arm_bilinear_interp_q15(
  arm_bilinear_interp_instance_q15 * S,
  q31_t X,
  q31_t Y)
  {
    q63_t acc = 0;                                           
    q31_t out;                                                         
    q15_t x1, x2, y1, y2;                                                   
    q31_t xfract, yfract;                                                   
    int32_t rI, cI;                                                          
    q15_t *pYData = S->pData;                                                        
    uint32_t nCols = S->numCols;                                  

                                  
                                     
                                 
    rI = ((X & (q31_t)0xFFF00000) >> 20);

                                  
                                     
                                 
    cI = ((Y & (q31_t)0xFFF00000) >> 20);

                                               
                                                                    
    if (rI < 0 || rI > (S->numRows - 1) || cI < 0 || cI > (S->numCols - 1))
    {
      return (0);
    }

                                         
                                          
    xfract = (X & 0x000FFFFF);

                                                       
    x1 = pYData[((uint32_t)rI) + nCols * ((uint32_t)cI)    ];
    x2 = pYData[((uint32_t)rI) + nCols * ((uint32_t)cI) + 1];

                                         
                                          
    yfract = (Y & 0x000FFFFF);

                                                       
    y1 = pYData[((uint32_t)rI) + nCols * ((uint32_t)cI + 1)    ];
    y2 = pYData[((uint32_t)rI) + nCols * ((uint32_t)cI + 1) + 1];

                                                                                 

                                                                               
                                                                      
    out = (q31_t) (((q63_t) x1 * (0xFFFFF - xfract)) >> 4U);
    acc = ((q63_t) out * (0xFFFFF - yfract));

                                                               
    out = (q31_t) (((q63_t) x2 * (0xFFFFF - yfract)) >> 4U);
    acc += ((q63_t) out * (xfract));

                                                                 
    out = (q31_t) (((q63_t) y1 * (0xFFFFF - xfract)) >> 4U);
    acc += ((q63_t) out * (yfract));

                                                             
    out = (q31_t) (((q63_t) y2 * (xfract)) >> 4U);
    acc += ((q63_t) out * (yfract));

                                                               
                                    
    return ((q15_t)(acc >> 36));
  }


     
                                      
                                                                           
                                                               
                                                               
                                   
    
  __STATIC_FORCEINLINE q7_t arm_bilinear_interp_q7(
  arm_bilinear_interp_instance_q7 * S,
  q31_t X,
  q31_t Y)
  {
    q63_t acc = 0;                                           
    q31_t out;                                                         
    q31_t xfract, yfract;                                                   
    q7_t x1, x2, y1, y2;                                                    
    int32_t rI, cI;                                                          
    q7_t *pYData = S->pData;                                                         
    uint32_t nCols = S->numCols;                                  

                                  
                                     
                                 
    rI = ((X & (q31_t)0xFFF00000) >> 20);

                                  
                                     
                                 
    cI = ((Y & (q31_t)0xFFF00000) >> 20);

                                               
                                                                    
    if (rI < 0 || rI > (S->numRows - 1) || cI < 0 || cI > (S->numCols - 1))
    {
      return (0);
    }

                                         
                                          
    xfract = (X & (q31_t)0x000FFFFF);

                                                       
    x1 = pYData[((uint32_t)rI) + nCols * ((uint32_t)cI)    ];
    x2 = pYData[((uint32_t)rI) + nCols * ((uint32_t)cI) + 1];

                                         
                                          
    yfract = (Y & (q31_t)0x000FFFFF);

                                                       
    y1 = pYData[((uint32_t)rI) + nCols * ((uint32_t)cI + 1)    ];
    y2 = pYData[((uint32_t)rI) + nCols * ((uint32_t)cI + 1) + 1];

                                                                                 
    out = ((x1 * (0xFFFFF - xfract)));
    acc = (((q63_t) out * (0xFFFFF - yfract)));

                                                               
    out = ((x2 * (0xFFFFF - yfract)));
    acc += (((q63_t) out * (xfract)));

                                                                 
    out = ((y1 * (0xFFFFF - xfract)));
    acc += (((q63_t) out * (yfract)));

                                                             
    out = ((y2 * (yfract)));
    acc += (((q63_t) out * (xfract)));

                                                                           
    return ((q7_t)(acc >> 40));
  }

     
                                        
     


            
#define multAcc_32x32_keep32_R(a, x, y) \
    a = (q31_t) (((((q63_t) a) << 32) + ((q63_t) x * y) + 0x80000000LL ) >> 32)

            
#define multSub_32x32_keep32_R(a, x, y) \
    a = (q31_t) (((((q63_t) a) << 32) - ((q63_t) x * y) + 0x80000000LL ) >> 32)

            
#define mult_32x32_keep32_R(a, x, y) \
    a = (q31_t) (((q63_t) x * y + 0x80000000LL ) >> 32)

           
#define multAcc_32x32_keep32(a, x, y) \
    a += (q31_t) (((q63_t) x * y) >> 32)

           
#define multSub_32x32_keep32(a, x, y) \
    a -= (q31_t) (((q63_t) x * y) >> 32)

           
#define mult_32x32_keep32(a, x, y) \
    a = (q31_t) (((q63_t) x * y ) >> 32)


#if   defined ( __CC_ARM )
                                                                                
  #if defined( __ARM_ARCH_7EM__ )
    #define LOW_OPTIMIZATION_ENTER \
       _Pragma ("push")         \
       _Pragma ("O1")
  #else
    #define LOW_OPTIMIZATION_ENTER
  #endif

                                                                                      
  #if defined ( __ARM_ARCH_7EM__ )
    #define LOW_OPTIMIZATION_EXIT \
       _Pragma ("pop")
  #else
    #define LOW_OPTIMIZATION_EXIT
  #endif

                                                                                
  #define IAR_ONLY_LOW_OPTIMIZATION_ENTER

                                                                                      
  #define IAR_ONLY_LOW_OPTIMIZATION_EXIT

#elif defined (__ARMCC_VERSION ) && ( __ARMCC_VERSION >= 6010050 )
  #define LOW_OPTIMIZATION_ENTER
  #define LOW_OPTIMIZATION_EXIT
  #define IAR_ONLY_LOW_OPTIMIZATION_ENTER
  #define IAR_ONLY_LOW_OPTIMIZATION_EXIT

#elif defined ( __GNUC__ )
  #define LOW_OPTIMIZATION_ENTER \
       __attribute__(( optimize("-O1") ))
  #define LOW_OPTIMIZATION_EXIT
  #define IAR_ONLY_LOW_OPTIMIZATION_ENTER
  #define IAR_ONLY_LOW_OPTIMIZATION_EXIT

#elif defined ( __ICCARM__ )
                                                                                
  #if defined ( __ARM_ARCH_7EM__ )
    #define LOW_OPTIMIZATION_ENTER \
       _Pragma ("optimize=low")
  #else
    #define LOW_OPTIMIZATION_ENTER
  #endif

                                                                                      
  #define LOW_OPTIMIZATION_EXIT

                                                                                
  #if defined ( __ARM_ARCH_7EM__ )
    #define IAR_ONLY_LOW_OPTIMIZATION_ENTER \
       _Pragma ("optimize=low")
  #else
    #define IAR_ONLY_LOW_OPTIMIZATION_ENTER
  #endif

                                                                                      
  #define IAR_ONLY_LOW_OPTIMIZATION_EXIT

#elif defined ( __TI_ARM__ )
  #define LOW_OPTIMIZATION_ENTER
  #define LOW_OPTIMIZATION_EXIT
  #define IAR_ONLY_LOW_OPTIMIZATION_ENTER
  #define IAR_ONLY_LOW_OPTIMIZATION_EXIT

#elif defined ( __CSMC__ )
  #define LOW_OPTIMIZATION_ENTER
  #define LOW_OPTIMIZATION_EXIT
  #define IAR_ONLY_LOW_OPTIMIZATION_ENTER
  #define IAR_ONLY_LOW_OPTIMIZATION_EXIT

#elif defined ( __TASKING__ )
  #define LOW_OPTIMIZATION_ENTER
  #define LOW_OPTIMIZATION_EXIT
  #define IAR_ONLY_LOW_OPTIMIZATION_ENTER
  #define IAR_ONLY_LOW_OPTIMIZATION_EXIT

#endif


#ifdef   __cplusplus
}
#endif

                                             
#if   defined ( __CC_ARM )

#elif defined ( __ARMCC_VERSION ) && ( __ARMCC_VERSION >= 6010050 )

#elif defined ( __GNUC__ )
#pragma GCC diagnostic pop

#elif defined ( __ICCARM__ )

#elif defined ( __TI_ARM__ )

#elif defined ( __CSMC__ )

#elif defined ( __TASKING__ )

#elif defined ( _MSC_VER )

#else
  #error Unknown compiler
#endif

#endif                  

   
  
               
   
