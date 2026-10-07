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

                                                                         
                                 
                                            
                                                
  
                             
                        
  
                                    
  
                                                                          

#include "arm_math.h"
#include "arm_nnfunctions.h"

   
                    
   

   
                     
     
   

     
                                                            
                                                          
                                                           
                                                           
                                                                  
                                                            
                                                                                  
                                                       
                                                       
                                                 
                                                 
                                                       
                                                       
                                                  
                                                                
                                                                   
                                                           
                                                            
                                                            
                                                                     
                                                                     
                                            
                                                                                                                
    
             
    
                        
    
                                                   
    
                    
    
                                        
    
                               
    
                              
    
     

arm_status
arm_convolve_HWC_q15_fast_nonsquare(const q15_t * Im_in,
                                    const uint16_t dim_im_in_x,
                                    const uint16_t dim_im_in_y,
                                    const uint16_t ch_im_in,
                                    const q15_t * wt,
                                    const uint16_t ch_im_out,
                                    const uint16_t dim_kernel_x,
                                    const uint16_t dim_kernel_y,
                                    const uint16_t padding_x,
                                    const uint16_t padding_y,
                                    const uint16_t stride_x,
                                    const uint16_t stride_y,
                                    const q15_t * bias,
                                    const uint16_t bias_shift,
                                    const uint16_t out_shift,
                                    q15_t * Im_out,
                                    const uint16_t dim_im_out_x,
                                    const uint16_t dim_im_out_y, 
                                    q15_t * bufferA, 
                                    q7_t * bufferB)
{

#if defined (ARM_MATH_DSP)
    int16_t   i_out_y, i_out_x, i_ker_y, i_ker_x;

    q15_t    *pBuffer = bufferA;
    q15_t    *im_buffer = bufferA;
    q15_t    *pOut = Im_out;

    if (ch_im_in % 2 != 0 || ch_im_out % 2 != 0)
    {
                                                                
        return ARM_MATH_SIZE_MISMATCH;
    }

                                                            

                                                  
    for (i_out_y = 0; i_out_y < dim_im_out_y; i_out_y++)
    {
        for (i_out_x = 0; i_out_x < dim_im_out_x; i_out_x++)
        {
            for (i_ker_y = i_out_y * stride_y - padding_y; i_ker_y < i_out_y * stride_y - padding_y + dim_kernel_y; i_ker_y++)
            {
                for (i_ker_x = i_out_x * stride_x - padding_x; i_ker_x < i_out_x * stride_x - padding_x + dim_kernel_x; i_ker_x++)
                {
                    if (i_ker_y < 0 || i_ker_y >= dim_im_in_y || i_ker_x < 0 || i_ker_x >= dim_im_in_x)
                    {
                                                                 
                        memset(pBuffer, 0, sizeof(q15_t)*ch_im_in);
                    } else
                    {
                                                                                                                              
                        memcpy(pBuffer, (q15_t *) Im_in + (i_ker_y * dim_im_in_x + i_ker_x) * ch_im_in, sizeof(q15_t)*ch_im_in);
                    }
                    pBuffer += ch_im_in;
                }
            }

            if (i_out_x & 0x1)
            {
                int       i;
                                                          
                const q15_t *pA = wt;

                                                       
                q15_t    *pOut2 = pOut + ch_im_out;

                                              
                for (i = 0; i < ch_im_out; i += 2)
                {
                                              
                    q15_t    *pB = im_buffer;
                    const q15_t *pB2 = pB + ch_im_in * dim_kernel_y * dim_kernel_x;

                                                        
                    const q15_t *pA2 = pA + ch_im_in * dim_kernel_y * dim_kernel_x;

                                                
                    q31_t     sum =  ((q31_t)bias[i] << bias_shift) + NN_ROUND(out_shift);
                    q31_t     sum2 = ((q31_t)bias[i] << bias_shift) + NN_ROUND(out_shift);
                    q31_t     sum3 = ((q31_t)bias[i + 1] << bias_shift) + NN_ROUND(out_shift);
                    q31_t     sum4 = ((q31_t)bias[i + 1] << bias_shift) + NN_ROUND(out_shift);

                    uint16_t  colCnt = ch_im_in * dim_kernel_y * dim_kernel_x >> 1;
                                                    
                    while (colCnt)
                    {
                        q31_t     inA1 = *__SIMD32(pA)++;
                        q31_t     inB1 = *__SIMD32(pB)++;
                        q31_t     inA2 = *__SIMD32(pA2)++;
                        q31_t     inB2 = *__SIMD32(pB2)++;

                        sum = __SMLAD(inA1, inB1, sum);
                        sum2 = __SMLAD(inA1, inB2, sum2);
                        sum3 = __SMLAD(inA2, inB1, sum3);
                        sum4 = __SMLAD(inA2, inB2, sum4);

                        colCnt--;
                    }                                  
                    colCnt = ch_im_in * dim_kernel_y * dim_kernel_x & 0x1;
                    while (colCnt)
                    {
                        q15_t     inA1 = *pA++;
                        q15_t     inB1 = *pB++;
                        q15_t     inA2 = *pA2++;
                        q15_t     inB2 = *pB2++;

                        sum += inA1 * inB1;
                        sum2 += inA1 * inB2;
                        sum3 += inA2 * inB1;
                        sum4 += inA2 * inB2;
                        colCnt--;
                    }                                  
                    *pOut++ = (q15_t) __SSAT(sum >> out_shift, 16);
                    *pOut++ = (q15_t) __SSAT(sum3 >> out_shift, 16);
                    *pOut2++ = (q15_t) __SSAT(sum2 >> out_shift, 16);
                    *pOut2++ = (q15_t) __SSAT(sum4 >> out_shift, 16);

                                                       
                    pA += ch_im_in * dim_kernel_y * dim_kernel_x;
                }                                       

                pOut += ch_im_out;
                                   
                pBuffer = im_buffer;
            }
        }
    }

#else
                                                                                        
    uint16_t  i, j, k, l, m, n;
    int       conv_out;
    signed char in_row, in_col;

    if (ch_im_in % 2 != 0 || ch_im_out % 2 != 0)
    {
                                                                
        return ARM_MATH_SIZE_MISMATCH;
    }

    for (i = 0; i < ch_im_out; i++)
    {
        for (j = 0; j < dim_im_out_y; j++)
        {
            for (k = 0; k < dim_im_out_x; k++)
            {
                conv_out = ((q31_t)bias[i] << bias_shift) + NN_ROUND(out_shift);
                for (m = 0; m < dim_kernel_y; m++)
                {
                    for (n = 0; n < dim_kernel_x; n++)
                    {
                        in_row = stride_y * j + m - padding_y;
                        in_col = stride_x * k + n - padding_x;
                        if (in_row >= 0 && in_col >= 0 && in_row < dim_im_in_y && in_col < dim_im_in_x)
                        {
                            for (l = 0; l < ch_im_in; l++)
                            {
                                conv_out +=
                                    Im_in[(in_row * dim_im_in_x + in_col) * ch_im_in +
                                          l] * wt[i * ch_im_in * dim_kernel_x * dim_kernel_y + (m * dim_kernel_x +
                                                                                            n) * ch_im_in + l];
                            }
                        }
                    }
                }
                Im_out[i + (j * dim_im_out_x + k) * ch_im_out] = (q15_t) __SSAT((conv_out >> out_shift), 16);
            }
        }
    }

#endif                                            

                               
    return ARM_MATH_SUCCESS;
}

   
                         
   
