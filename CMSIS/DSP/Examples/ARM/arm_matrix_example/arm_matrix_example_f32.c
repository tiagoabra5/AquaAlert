/* ----------------------------------------------------------------------
* Copyright (C) 2010-2012 ARM Limited. All rights reserved.
*
* $Date:         17. January 2013
* $Revision:     V1.4.0
*
* Project:       CMSIS DSP Library
* Title:         arm_matrix_example_f32.c
*
* Description:   Example code demonstrating least square fit to data
*                using matrix functions
*
* Target Processor: Cortex-M4/Cortex-M3
*
* Redistribution and use in source and binary forms, with or without
* modification, are permitted provided that the following conditions
* are met:
*   - Redistributions of source code must retain the above copyright
*     notice, this list of conditions and the following disclaimer.
*   - Redistributions in binary form must reproduce the above copyright
*     notice, this list of conditions and the following disclaimer in
*     the documentation and/or other materials provided with the
*     distribution.
*   - Neither the name of ARM LIMITED nor the names of its contributors
*     may be used to endorse or promote products derived from this
*     software without specific prior written permission.
*
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
* "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
* LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
* FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
* COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
* INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
* BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
* LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
* CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
* LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
* ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
* POSSIBILITY OF SUCH DAMAGE.
 * -------------------------------------------------------------------- */

   
                         
   

   
                                         
  
                    
       
                                                                                     
                                                                                   
                                                                                 
                                                                        
  
                  
       
                                                                 
       
                                                                               
                    
       
                                                                      
       
                                                                   
  
                      
       
                                
  
                              
       
                                                               
                                                                
                                                                           
  
                                                  
       
                       
                        
                       
                          
  
                  
                                          
  
   


                                     
    

#include "arm_math.h"
#include "math_helper.h"

#define SNR_THRESHOLD   90

                                                                                   
                                                                                    
             
                                                                                      

const float32_t B_f32[4] =
{
  782.0, 7577.0, 470.0, 4505.0
};

                                                                                   
                                                                                  
                                                                                     

const float32_t A_f32[16] =
{
                                                          
  1.0,     32.0,      4.0,     128.0,
  1.0,     32.0,     64.0,    2048.0,
  1.0,     16.0,      4.0,      64.0,
  1.0,     16.0,     64.0,    1024.0,
};


                                                                         
                                                    
                                                                        
                           
float32_t AT_f32[16];
                                 
float32_t ATMA_f32[16];
                                         
float32_t ATMAI_f32[16];
                        
float32_t X_f32[4];

                                                                         
                                                            
                                                                        
const float32_t xRef_f32[4] = {73.0, 8.0, 21.25, 2.875};

float32_t snr;


                                                                         
                            
                                                                        

int32_t main(void)
{

  arm_matrix_instance_f32 A;                             
  arm_matrix_instance_f32 AT;                                          
  arm_matrix_instance_f32 ATMA;                                                  
  arm_matrix_instance_f32 ATMAI;                                              
  arm_matrix_instance_f32 B;                             
  arm_matrix_instance_f32 X;                                             

  uint32_t srcRows, srcColumns;                           
  arm_status status;

                                                                                
  srcRows = 4;
  srcColumns = 4;
  arm_mat_init_f32(&A, srcRows, srcColumns, (float32_t *)A_f32);

                                                                                  
  srcRows = 4;
  srcColumns = 4;
  arm_mat_init_f32(&AT, srcRows, srcColumns, AT_f32);

                                  
  status = arm_mat_trans_f32(&A, &AT);


                                                                                      
  srcRows = 4;
  srcColumns = 4;
  arm_mat_init_f32(&ATMA, srcRows, srcColumns, ATMA_f32);

                                         
  status = arm_mat_mult_f32(&AT, &A, &ATMA);

                                                                                        
  srcRows = 4;
  srcColumns = 4;
  arm_mat_init_f32(&ATMAI, srcRows, srcColumns, ATMAI_f32);

                                                 
  status = arm_mat_inverse_f32(&ATMA, &ATMAI);

                                                                    
  status = arm_mat_mult_f32(&ATMAI, &AT, &ATMA);

                                                                                
  srcRows = 4;
  srcColumns = 1;
  arm_mat_init_f32(&B, srcRows, srcColumns, (float32_t *)B_f32);

                                                                                
  srcRows = 4;
  srcColumns = 1;
  arm_mat_init_f32(&X, srcRows, srcColumns, X_f32);

                                                                       
  status = arm_mat_mult_f32(&ATMA, &B, &X);

                                                
  snr = arm_snr_f32((float32_t *)xRef_f32, X_f32, 4);

                                                                                  
                                                              
                                                                                   
  if ( snr > SNR_THRESHOLD)
  {
    status = ARM_MATH_SUCCESS;
  }
  else
  {
    status = ARM_MATH_TEST_FAILURE;
  }


                                                                           
                                                  
                                
                                                                           
  if ( status != ARM_MATH_SUCCESS)
  {
    while (1);
  }

  while (1);                                                                
}

                
