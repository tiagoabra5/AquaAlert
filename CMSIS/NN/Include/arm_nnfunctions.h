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

                                                                         
                                 
                                  
                                                        
  
                              
                        
  
                                    
                                                                          

/**
   \mainpage CMSIS NN Software Library
   *
   * Introduction
   * ------------
   *
   * This user manual describes the CMSIS NN software library,
   * a collection of efficient neural network kernels developed to maximize the
   * performance and minimize the memory footprint of neural networks on Cortex-M processor cores.
   *
   * The library is divided into a number of functions each covering a specific category:
   * - Neural Network Convolution Functions
   * - Neural Network Activation Functions
   * - Fully-connected Layer Functions
   * - Neural Network Pooling Functions
   * - Softmax Functions
   * - Neural Network Support Functions
   *
   * The library has separate functions for operating on different weight and activation data
   * types including 8-bit integers (q7_t) and 16-bit integers (q15_t). The descrition of the
   * kernels are included in the function description. The implementation details are also
   * described in this paper [1].
   *
   * Block Diagram
   * --------
   * \image html CMSIS-NN-OVERVIEW.PNG
   *
   * Examples
   * --------
   *
   * The library ships with a number of examples which demonstrate how to use the library functions.
   *
   * Pre-processor Macros
   * ------------
   *
   * Each library project have differant pre-processor macros.
   *
   * - ARM_MATH_DSP:
   *
   * Define macro ARM_MATH_DSP, If the silicon supports DSP instructions.
   *
   * - ARM_MATH_BIG_ENDIAN:
   *
   * Define macro ARM_MATH_BIG_ENDIAN to build the library for big endian targets. By default library builds for little endian targets.
   *
   * - ARM_NN_TRUNCATE:
   *
   * Define macro ARM_NN_TRUNCATE to use floor instead of round-to-the-nearest-int for the computation.
   *
   * Copyright Notice
   * ------------
   *
   * Copyright (C) 2010-2018 Arm Limited. All rights reserved.
   *
   * [1] CMSIS-NN: Efficient Neural Network Kernels for Arm Cortex-M CPUs https://arxiv.org/abs/1801.06601
   */

   
                                             
                                                                      
   

#ifndef _ARM_NNFUNCTIONS_H
#define _ARM_NNFUNCTIONS_H

#include "arm_nnsupportfunctions.h"
#include "arm_nn_tables.h"

#define USE_INTRINSIC

                                                                                                   

#ifdef __cplusplus
extern    "C"
{
#endif

   
                                                        
  
                            
  
                                                             
  
                                                                  
                                                                       
                  
  
                                                                     
                                                                      
                                                                          
  
   

     
                                         
                                                         
                                                        
                                                                 
                                                           
                                                                                 
                                                    
                                               
                                                    
                                                 
                                                               
                                                                  
                                                          
                                                         
                                                                   
                                                                    
                                                                   
    
     

    arm_status arm_convolve_HWC_q7_basic(const q7_t * Im_in,
                                         const uint16_t dim_im_in,
                                         const uint16_t ch_im_in,
                                         const q7_t * wt,
                                         const uint16_t ch_im_out,
                                         const uint16_t dim_kernel,
                                         const uint16_t padding,
                                         const uint16_t stride,
                                         const q7_t * bias,
                                         const uint16_t bias_shift,
                                         const uint16_t out_shift,
                                         q7_t * Im_out,
                                         const uint16_t dim_im_out,
                                         q15_t * bufferA,
                                         q7_t * bufferB);

     
                                                            
                                                          
                                                           
                                                           
                                                                  
                                                            
                                                                                  
                                                       
                                                       
                                                 
                                                 
                                                       
                                                       
                                                  
                                                                
                                                                   
                                                           
                                                            
                                                            
                                                                    
                                                                     
                                                                   
     

    arm_status arm_convolve_HWC_q7_basic_nonsquare(const q7_t * Im_in,
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
                                                  q7_t * bufferB);

     
                                          
                                                         
                                                        
                                                                 
                                                           
                                                                                 
                                                    
                                               
                                                    
                                                 
                                                               
                                                                  
                                                          
                                                         
                                                                   
                                                                    
                                                                   
    
     

    arm_status arm_convolve_HWC_q15_basic(const q15_t * Im_in,
                                          const uint16_t dim_im_in,
                                          const uint16_t ch_im_in,
                                          const q15_t * wt,
                                          const uint16_t ch_im_out,
                                          const uint16_t dim_kernel,
                                          const uint16_t padding,
                                          const uint16_t stride,
                                          const q15_t * bias,
                                          const uint16_t bias_shift,
                                          const uint16_t out_shift,
                                          q15_t * Im_out,
                                          const uint16_t dim_im_out,
                                          q15_t * bufferA,
                                          q7_t * bufferB);

     
                                        
                                                         
                                                        
                                                                 
                                                           
                                                                                 
                                                    
                                               
                                                    
                                                 
                                                               
                                                                  
                                                          
                                                         
                                                                   
                                                                    
                                            
                                                                                                                
    
                                                                                 
                     
                                
                                 
     

    arm_status arm_convolve_HWC_q7_fast(const q7_t * Im_in,
                                        const uint16_t dim_im_in,
                                        const uint16_t ch_im_in,
                                        const q7_t * wt,
                                        const uint16_t ch_im_out,
                                        const uint16_t dim_kernel,
                                        const uint16_t padding,
                                        const uint16_t stride,
                                        const q7_t * bias,
                                        const uint16_t bias_shift,
                                        const uint16_t out_shift,
                                        q7_t * Im_out,
                                        const uint16_t dim_im_out,
                                        q15_t * bufferA,
                                        q7_t * bufferB);

     
                                                           
                                                          
                                                           
                                                           
                                                                  
                                                            
                                                                                  
                                                       
                                                       
                                                 
                                                 
                                                       
                                                       
                                                  
                                                                
                                                                   
                                                           
                                                            
                                                            
                                                                    
                                                                     
                                            
                                                                                                                
    
                                                                                 
                     
                                
                                 
     

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
                                                  q7_t * bufferB);

     
                                                                 
                                                          
                                                           
                                                           
                                                                  
                                                            
                                                                                  
                                                       
                                                       
                                                 
                                                 
                                                       
                                                       
                                                  
                                                                
                                                                   
                                                           
                                                            
                                                            
                                                                    
                                                                     
                                            
                                                                                                                
    
                                                                                   
                                            
                                                                     
    
                                                                                 
                     
                                
                                 
     
    arm_status arm_convolve_1x1_HWC_q7_fast_nonsquare(const q7_t * Im_in,
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
                                                      q7_t * bufferB);

     
                                                   
                                                         
                                                        
                                                                 
                                                           
                                                                                 
                                                    
                                               
                                                    
                                                 
                                                               
                                                                  
                                                          
                                                         
                                                                   
                                                                    
                                            
                                                                                                                
    
                                                                     
                                                                      
                           
     

    arm_status arm_convolve_HWC_q7_RGB(const q7_t * Im_in,
                                       const uint16_t dim_im_in,
                                       const uint16_t ch_im_in,
                                       const q7_t * wt,
                                       const uint16_t ch_im_out,
                                       const uint16_t dim_kernel,
                                       const uint16_t padding,
                                       const uint16_t stride,
                                       const q7_t * bias,
                                       const uint16_t bias_shift,
                                       const uint16_t out_shift,
                                       q7_t * Im_out,
                                       const uint16_t dim_im_out,
                                       q15_t * bufferA,
                                       q7_t * bufferB);

     
                                         
                                                         
                                                        
                                                                 
                                                           
                                                                                 
                                                    
                                               
                                                    
                                                 
                                                               
                                                                  
                                                          
                                                         
                                                                   
                                                                    
                                            
                                                                                                                
    
                                                                                 
                     
                                
                                 
     

    arm_status arm_convolve_HWC_q15_fast(const q15_t * Im_in,
                                         const uint16_t dim_im_in,
                                         const uint16_t ch_im_in,
                                         const q15_t * wt,
                                         const uint16_t ch_im_out,
                                         const uint16_t dim_kernel,
                                         const uint16_t padding,
                                         const uint16_t stride,
                                         const q15_t * bias,
                                         const uint16_t bias_shift,
                                         const uint16_t out_shift,
                                         q15_t * Im_out,
                                         const uint16_t dim_im_out,
                                         q15_t * bufferA,
                                         q7_t * bufferB);

     
                                                            
                                                          
                                                           
                                                           
                                                                  
                                                            
                                                                                  
                                                       
                                                       
                                                 
                                                 
                                                       
                                                       
                                                  
                                                                
                                                                   
                                                           
                                                            
                                                            
                                                                    
                                                                     
                                            
                                                                                                                
    
             
    
                        
    
                                                   
    
                    
    
                                        
    
                              
    
                              
    
     

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
                              q7_t * bufferB);

     
                                                       
                                                         
                                                        
                                                                 
                                                           
                                                                                 
                                                    
                                               
                                                    
                                                 
                                                               
                                                                  
                                                          
                                                         
                                                                   
                                                                    
                                            
                                                                                                                
    
                                                                                 
                     
                                
                                 
     

    arm_status arm_depthwise_separable_conv_HWC_q7(const q7_t * Im_in,
                                                   const uint16_t dim_im_in,
                                                   const uint16_t ch_im_in,
                                                   const q7_t * wt,
                                                   const uint16_t ch_im_out,
                                                   const uint16_t dim_kernel,
                                                   const uint16_t padding,
                                                   const uint16_t stride,
                                                   const q7_t * bias,
                                                   const uint16_t bias_shift,
                                                   const uint16_t out_shift,
                                                   q7_t * Im_out,
                                                   const uint16_t dim_im_out,
                                                   q15_t * bufferA,
                                                   q7_t * bufferB);

     
                                                                          
                                                           
                                                            
                                                            
                                                                   
                                                             
                                                                                   
                                                        
                                                        
                                                   
                                                   
                                                        
                                                        
                                                   
                                                                 
                                                                    
                                                            
                                                             
                                                             
                                                                     
                                                                      
                                            
                                                                                                                
    
                                                                                 
                     
                                
                                 
     
    arm_status arm_depthwise_separable_conv_HWC_q7_nonsquare(const q7_t * Im_in,
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
                                                             q7_t * bufferB);


   
                                               
  
                                
  
                                                                    
                                                                    
                                                                       
                                                                 
  
                                                                 
                                                                         
                                                
  
   

     
                                                   
                                                         
                                                           
                                                      
                                                                 
                                                               
                                                                  
                                                 
                                                          
                                                                   
                                                                   
    
     

    arm_status arm_fully_connected_q7(const q7_t * pV,
                                      const q7_t * pM,
                                      const uint16_t dim_vec,
                                      const uint16_t num_of_rows,
                                      const uint16_t bias_shift,
                                      const uint16_t out_shift,
                                      const q7_t * bias,
                                      q7_t * pOut,
                                      q15_t * vec_buffer);

     
                                                 
                                                         
                                                           
                                                      
                                                                 
                                                               
                                                                  
                                                 
                                                          
                                                                   
                                                                   
    
     

    arm_status arm_fully_connected_q7_opt(const q7_t * pV,
                                          const q7_t * pM,
                                          const uint16_t dim_vec,
                                          const uint16_t num_of_rows,
                                          const uint16_t bias_shift,
                                          const uint16_t out_shift,
                                          const q7_t * bias,
                                          q7_t * pOut,
                                          q15_t * vec_buffer);

     
                                                    
                                                         
                                                           
                                                      
                                                                 
                                                               
                                                                  
                                                 
                                                          
                                                                   
                                                                   
    
     

    arm_status arm_fully_connected_q15(const q15_t * pV,
                                       const q15_t * pM,
                                       const uint16_t dim_vec,
                                       const uint16_t num_of_rows,
                                       const uint16_t bias_shift,
                                       const uint16_t out_shift,
                                       const q15_t * bias,
                                       q15_t * pOut,
                                       q15_t * vec_buffer);

     
                                                  
                                                         
                                                           
                                                      
                                                                 
                                                               
                                                                  
                                                 
                                                          
                                                                   
                                                                   
    
     

    arm_status arm_fully_connected_q15_opt(const q15_t * pV,
                                           const q15_t * pM,
                                           const uint16_t dim_vec,
                                           const uint16_t num_of_rows,
                                           const uint16_t bias_shift,
                                           const uint16_t out_shift,
                                           const q15_t * bias,
                                           q15_t * pOut,
                                           q15_t * vec_buffer);

     
                                                       
                                                         
                                                           
                                                      
                                                                 
                                                               
                                                                  
                                                 
                                                          
                                                                   
                                                                   
    
     

    arm_status arm_fully_connected_mat_q7_vec_q15(const q15_t * pV,
                                                  const q7_t * pM,
                                                  const uint16_t dim_vec,
                                                  const uint16_t num_of_rows,
                                                  const uint16_t bias_shift,
                                                  const uint16_t out_shift,
                                                  const q7_t * bias,
                                                  q15_t * pOut,
                                                  q15_t * vec_buffer);

     
                                                           
                                                         
                                                           
                                                      
                                                                 
                                                               
                                                                  
                                                 
                                                          
                                                                   
                                                                   
    
     

    arm_status arm_fully_connected_mat_q7_vec_q15_opt(const q15_t * pV,
                                                      const q7_t * pM,
                                                      const uint16_t dim_vec,
                                                      const uint16_t num_of_rows,
                                                      const uint16_t bias_shift,
                                                      const uint16_t out_shift,
                                                      const q7_t * bias,
                                                      q15_t * pOut,
                                                      q15_t * vec_buffer);

   
                                                       
  
                                                                  
                         
  
                                                                    
                                                                  
                                         
  
   

     
                                                          
                                                      
                                                                                     
                                             
                                             
                                                               
                                                                  
                                          
                                                   
                                                                    
     

    q7_t     *arm_nn_mat_mult_kernel_q7_q15(const q7_t * pA,
                                            const q15_t * pInBuffer,
                                            const uint16_t ch_im_out,
                                            const uint16_t numCol_A,
                                            const uint16_t bias_shift,
                                            const uint16_t out_shift,
                                            const q7_t * bias,
                                            q7_t * pOut);

     
                                                                                 
                                                      
                                                                                     
                                             
                                             
                                                               
                                                                  
                                          
                                                   
                                                                    
     

    q7_t     *arm_nn_mat_mult_kernel_q7_q15_reordered(const q7_t * pA,
                                                      const q15_t * pInBuffer,
                                                      const uint16_t ch_im_out,
                                                      const uint16_t numCol_A,
                                                      const uint16_t bias_shift,
                                                      const uint16_t out_shift,
                                                      const q7_t * bias,
                                                      q7_t * pOut);

#ifdef __cplusplus
}
#endif

  
                   
                                                  
                                          
   

#ifdef __cplusplus
extern    "C"
{
#endif

   
                                                     
  
                                                                     
                   
  
   

     
                            
                                                  
                                                    
                  
     

    void      arm_relu_q7(q7_t * data, uint16_t size);

     
                             
                                                  
                                                    
                  
     

    void      arm_relu_q15(q15_t * data, uint16_t size);

     
                                                                            
                                                  
                                                    
                                                                                            
                                                              
                  
     

    void      arm_nn_activations_direct_q7(q7_t * data, uint16_t size, uint16_t int_width,
                                           arm_nn_activation_type type);

     
                                                                             
                                                  
                                                    
                                                                                            
                                                              
                  
     

    void      arm_nn_activations_direct_q15(q15_t * data, uint16_t size, uint16_t int_width,
                                            arm_nn_activation_type type);

   
                                                     
  
                                                                       
  
   

     
                                   
                                                         
                                                        
                                                                 
                                                    
                                               
                                                    
                                                         
                                                                   
                                                          
                  
    
     

    void      arm_maxpool_q7_HWC(q7_t * Im_in,
                                 const uint16_t dim_im_in,
                                 const uint16_t ch_im_in,
                                 const uint16_t dim_kernel,
                                 const uint16_t padding,
                                 const uint16_t stride,
                                 const uint16_t dim_im_out,
                                 q7_t * bufferA,
                                 q7_t * Im_out);

     
                                       
                                                         
                                                        
                                                                 
                                                    
                                               
                                                    
                                                         
                                                                   
                                                          
                  
    
     

    void      arm_avepool_q7_HWC(q7_t * Im_in,
                                 const uint16_t dim_im_in,
                                 const uint16_t ch_im_in,
                                 const uint16_t dim_kernel,
                                 const uint16_t padding,
                                 const uint16_t stride,
                                 const uint16_t dim_im_out,
                                 q7_t * bufferA,
                                 q7_t * Im_out);

   
                                      
  
                                
  
   

     
                               
                                                         
                                                        
                                                          
                  
    
     

    void      arm_softmax_q7(const q7_t * vec_in, const uint16_t dim_vec, q7_t * p_out);

     
                                
                                                         
                                                        
                                                          
                  
    
     

    void      arm_softmax_q15(const q15_t * vec_in, const uint16_t dim_vec, q15_t * p_out);

     
                                                                                                                   
                                                                                    
    
                                                     
                                                   
                                                    
                                                      
                                                       
                                             
                                              
                                                          
                                             
                                             
                                                                
                                                                 
                                                                                                  
                                                                                                   
                                                                             
                                                         
                                                          
                                                           
                                                           
                                                          
                                                    
                                                     
                                                                                                  
                                                                                                  
                                                               
                                                                   
                                                             
                                                                                            
                                                                        
                                                                                       
    
                              
                              
                              
    
     
    arm_status arm_depthwise_conv_u8_basic_ver1(const uint8_t *input,
                                                const uint16_t input_x,
                                                const uint16_t input_y,
                                                const uint16_t input_ch,
                                                const uint8_t *kernel,
                                                const uint16_t kernel_x,
                                                const uint16_t kernel_y,
                                                const int16_t ch_mult,
                                                const int16_t pad_x,
                                                const int16_t pad_y,
                                                const int16_t stride_x,
                                                const int16_t stride_y,
                                                const int16_t dilation_x,
                                                const int16_t dilation_y,
                                                const int32_t *bias,
                                                const int32_t input_offset,
                                                const int32_t filter_offset,
                                                const int32_t output_offset,
                                                uint8_t *output,
                                                const uint16_t output_x,
                                                const uint16_t output_y,
                                                const int32_t output_activation_min,
                                                const int32_t output_activation_max,
                                                const int32_t out_shift,
                                                const int32_t out_mult);
#ifdef __cplusplus
}
#endif

#endif
