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

   
                    
   

   
                     
     
   

   
                                                         
                                                        
                                                         
                                                         
                                                                
                                                          
                                                                                
                                                     
                                                     
                                               
                                               
                                                     
                                                     
                                                
                                                              
                                                                 
                                                         
                                                          
                                                          
                                                                   
                                                                   
                                          
                                                                                                              
  
                                                                               
                   
                              
                               
   

arm_status arm_convolve_HWC_q7_fast_nonsquare(const q7_t * Im_in,
                                              const uint16_t dim_im_in_x,
                                              const uint16_t dim_im_in_y,
                                              const uint16_t ch_im_in,
                                              const q7_t * wt,
                                              const uint16_t ch_im_out,
                                              const uint16_t dim_kernel_x,
                                              const uint16_t dim_kernel_y,
                                              const uint16_t padding_x,
                                              const uint16_t padding_y,
                                              const uint16_t stride_x,
                                              const uint16_t stride_y,
                                              const q7_t * bias,
                                              const uint16_t bias_shift,
                                              const uint16_t out_shift,
                                              q7_t * Im_out,
                                              const uint16_t dim_im_out_x,
                                              const uint16_t dim_im_out_y, 
                                              q15_t * bufferA, 
                                              q7_t * bufferB)
{

#if defined (ARM_MATH_DSP)
                                                            

    int16_t   i_out_y, i_out_x, i_ker_y, i_ker_x;

                              
                                                                                        
                                                                 
       

    q15_t    *pBuffer = bufferA;
    q7_t     *pOut = Im_out;

    if (ch_im_in % 4 != 0 || ch_im_out % 2 != 0)
    {
                                                                
        return ARM_MATH_SIZE_MISMATCH;
    }

      
                                                                                             
                                            
                                                           
                                                              
       

                  
    for (i_out_y = 0; i_out_y < padding_y; i_out_y++)
    {
        for (i_out_x = 0; i_out_x < dim_im_out_x; i_out_x++)
        {
                                                          
            for (i_ker_y = i_out_y * stride_y - padding_y; i_ker_y < i_out_y * stride_y - padding_y + dim_kernel_y;
                 i_ker_y++)
            {
                for (i_ker_x = i_out_x * stride_x - padding_x; i_ker_x < i_out_x * stride_x - padding_x + dim_kernel_x;
                     i_ker_x++)
                {
                    if (i_ker_y < 0 || i_ker_y >= dim_im_in_y || i_ker_x < 0 || i_ker_x >= dim_im_in_x)
                    {
                                                                 
                        memset(pBuffer, 0, sizeof(q15_t)*ch_im_in);
                    } else
                    {
                        arm_q7_to_q15_reordered_no_shift((q7_t *) Im_in + (i_ker_y * dim_im_in_x + i_ker_x) * ch_im_in,
                                                         pBuffer, ch_im_in);
                    }
                    pBuffer += ch_im_in;
                }
            }

            if (pBuffer == bufferA + 2 * ch_im_in * dim_kernel_x * dim_kernel_y)
            {
                pOut =
                    arm_nn_mat_mult_kernel_q7_q15_reordered(wt, bufferA, ch_im_out, ch_im_in * dim_kernel_x * dim_kernel_y,
                                                  bias_shift, out_shift, bias, pOut);
                                   
                pBuffer = bufferA;
            }
        }
    }

                                                                         
    for (; i_out_y < dim_im_out_y - padding_y; i_out_y++)
    {

                       
        for (i_out_x = 0; i_out_x < padding_x; i_out_x++)
        {
                                                          
            for (i_ker_y = i_out_y * stride_y - padding_y; i_ker_y < i_out_y * stride_y - padding_y + dim_kernel_y;
                 i_ker_y++)
            {
                for (i_ker_x = i_out_x * stride_x - padding_x; i_ker_x < i_out_x * stride_x - padding_x + dim_kernel_x;
                     i_ker_x++)
                {
                    if (i_ker_x < 0 || i_ker_x >= dim_im_in_x)
                    {
                                                                 
                        memset(pBuffer, 0, sizeof(q15_t)*ch_im_in);
                    } else
                    {
                        arm_q7_to_q15_reordered_no_shift((q7_t *) Im_in + (i_ker_y * dim_im_in_x + i_ker_x) * ch_im_in,
                                                         pBuffer, ch_im_in);
                    }
                    pBuffer += ch_im_in;
                }
            }

            if (pBuffer == bufferA + 2 * ch_im_in * dim_kernel_x * dim_kernel_y)
            {
                pOut =
                    arm_nn_mat_mult_kernel_q7_q15_reordered(wt, bufferA, ch_im_out, ch_im_in * dim_kernel_x * dim_kernel_y,
                                                  bias_shift, out_shift, bias, pOut);
                                   
                pBuffer = bufferA;
            }
        }

                      
        for (; i_out_x < dim_im_out_x - padding_x; i_out_x++)
        {
                                                          
            for (i_ker_y = i_out_y * stride_y - padding_y; i_ker_y < i_out_y * stride_y - padding_y + dim_kernel_y;
                 i_ker_y++)
            {
                arm_q7_to_q15_reordered_no_shift((q7_t *) Im_in +
                                                 (i_ker_y * dim_im_in_x + i_out_x * stride_x - padding_x) * ch_im_in,
                                                 pBuffer, ch_im_in * dim_kernel_x);
                pBuffer += ch_im_in * dim_kernel_x;
            }

            if (pBuffer == bufferA + 2 * ch_im_in * dim_kernel_x * dim_kernel_y)
            {
                pOut =
                    arm_nn_mat_mult_kernel_q7_q15_reordered(wt, bufferA, ch_im_out, ch_im_in * dim_kernel_x * dim_kernel_y,
                                                  bias_shift, out_shift, bias, pOut);
                                   
                pBuffer = bufferA;
            }
        }

                        
        for (; i_out_x < dim_im_out_x; i_out_x++)
        {
                                                          
            for (i_ker_y = i_out_y * stride_y - padding_y; i_ker_y < i_out_y * stride_y - padding_y + dim_kernel_y;
                 i_ker_y++)
            {
                for (i_ker_x = i_out_x * stride_x - padding_x; i_ker_x < i_out_x * stride_x - padding_x + dim_kernel_x;
                     i_ker_x++)
                {
                    if (i_ker_x < 0 || i_ker_x >= dim_im_in_x)
                    {
                                                                 
                        memset(pBuffer, 0, sizeof(q15_t)*ch_im_in);
                    } else
                    {
                        arm_q7_to_q15_reordered_no_shift((q7_t *) Im_in + (i_ker_y * dim_im_in_x + i_ker_x) * ch_im_in,
                                                         pBuffer, ch_im_in);
                    }
                    pBuffer += ch_im_in;
                }
            }

            if (pBuffer == bufferA + 2 * ch_im_in * dim_kernel_x * dim_kernel_y)
            {
                pOut =
                    arm_nn_mat_mult_kernel_q7_q15_reordered(wt, bufferA, ch_im_out, ch_im_in * dim_kernel_x * dim_kernel_y,
                                                  bias_shift, out_shift, bias, pOut);
                                   
                pBuffer = bufferA;
            }
        }
    }

    for (; i_out_y < dim_im_out_y; i_out_y++)
    {
        for (i_out_x = 0; i_out_x < dim_im_out_x; i_out_x++)
        {
                                                          
            for (i_ker_y = i_out_y * stride_y - padding_y; i_ker_y < i_out_y * stride_y - padding_y + dim_kernel_y;
                 i_ker_y++)
            {
                for (i_ker_x = i_out_x * stride_x - padding_x; i_ker_x < i_out_x * stride_x - padding_x + dim_kernel_x;
                     i_ker_x++)
                {
                    if (i_ker_y < 0 || i_ker_y >= dim_im_in_y || i_ker_x < 0 || i_ker_x >= dim_im_in_x)
                    {
                                                                 
                        memset(pBuffer, 0, sizeof(q15_t)*ch_im_in);
                    } else
                    {
                        arm_q7_to_q15_reordered_no_shift((q7_t *) Im_in + (i_ker_y * dim_im_in_x + i_ker_x) * ch_im_in,
                                                         pBuffer, ch_im_in);
                    }
                    pBuffer += ch_im_in;
                }
            }

            if (pBuffer == bufferA + 2 * ch_im_in * dim_kernel_x * dim_kernel_y)
            {
                pOut =
                    arm_nn_mat_mult_kernel_q7_q15_reordered(wt, bufferA, ch_im_out, ch_im_in * dim_kernel_x * dim_kernel_y,
                                                  bias_shift, out_shift, bias, pOut);
                                   
                pBuffer = bufferA;
            }
        }
    }

                                                 
    if (pBuffer != bufferA)
    {
        const q7_t *pA = wt;
        int       i;
        for (i = 0; i < ch_im_out; i++)
        {
            q31_t     sum = ((q31_t)(bias[i]) << bias_shift) + NN_ROUND(out_shift);
            q15_t    *pB = bufferA;
                                                          
            uint16_t  colCnt = ch_im_in * dim_kernel_x * dim_kernel_y >> 2;

            while (colCnt)
            {

                q31_t     inA1, inA2;
                q31_t     inB1, inB2;

                pA = (const q7_t *)read_and_pad_reordered((void *)pA, &inA1, &inA2);

                inB1 = *__SIMD32(pB)++;
                sum = __SMLAD(inA1, inB1, sum);
                inB2 = *__SIMD32(pB)++;
                sum = __SMLAD(inA2, inB2, sum);

                colCnt--;
            }
            colCnt = (ch_im_in * dim_kernel_y * dim_kernel_x) & 0x3;
            while (colCnt)
            {
                q7_t      inA1 = *pA++;
                q15_t     inB1 = *pB++;
                sum += inA1 * inB1;
                colCnt--;
            }
            *pOut = (q7_t) __SSAT((sum >> out_shift), 8);
            pOut++;

        }

    }

#else
                                                                                        
    int       i, j, k, l, m, n;
    int       conv_out;
    int       in_row, in_col;

    if (ch_im_in % 4 != 0 || ch_im_out % 2 != 0)
    {
                                                                
        return ARM_MATH_SIZE_MISMATCH;
    }

    for (i = 0; i < ch_im_out; i++)
    {
        for (j = 0; j < dim_im_out_y; j++)
        {
            for (k = 0; k < dim_im_out_x; k++)
            {
                conv_out = ((q31_t)(bias[i]) << bias_shift) + NN_ROUND(out_shift);
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
                                conv_out += Im_in[(in_row * dim_im_in_x + in_col) * ch_im_in + l] *
                                    wt[i * ch_im_in * dim_kernel_y * dim_kernel_x + (m * dim_kernel_x + n) * ch_im_in + l];      
                            }
                        }
                    }
                }
                Im_out[i + (j * dim_im_out_x + k) * ch_im_out] = (q7_t) __SSAT((conv_out >> out_shift), 8);
            }
        }
    }


#endif                                            

                               
    return ARM_MATH_SUCCESS;
}

   
                         
   
