/* ----------------------------------------------------------------------
* Copyright (C) 2010-2012 ARM Limited. All rights reserved.
*
* $Date:         17. January 2013
* $Revision:     V1.4.0
*
* Project:       CMSIS DSP Library
* Title:         arm_signal_converge_example_f32.c
*
* Description:   Example code demonstrating convergence of an adaptive
*                filter.
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

                                                                         
                                    
                                                                        

#define TEST_LENGTH_SAMPLES 1536
#define NUMTAPS               32
#define BLOCKSIZE             32
#define DELTA_ERROR         0.000001f
#define DELTA_COEFF         0.0001f
#define MU                  0.5f

#define NUMFRAMES (TEST_LENGTH_SAMPLES / BLOCKSIZE)

                                                                         
                                         
                                                                        

float32_t firStateF32[NUMTAPS + BLOCKSIZE];
arm_fir_instance_f32 LPF_instance;

                                                                         
                                             
                                                                        

float32_t lmsStateF32[NUMTAPS + BLOCKSIZE];
float32_t errOutput[TEST_LENGTH_SAMPLES];
arm_lms_norm_instance_f32 lmsNorm_instance;


                                                                         
                                                      
                                                                        

arm_status test_signal_converge_example( void );


                                                                         
                    
                                                                        
arm_status test_signal_converge(float32_t* err_signal,
                        uint32_t blockSize);

void getinput(float32_t* input,
     uint32_t fr_cnt,
          uint32_t blockSize);

                                                                         
                                               
                                                                        
extern float32_t testInput_f32[TEST_LENGTH_SAMPLES];
extern float32_t lmsNormCoeff_f32[32];
extern const float32_t FIRCoeff_f32[32];
extern arm_lms_norm_instance_f32 lmsNorm_instance;

                                                                         
                     
                                                                        

float32_t wire1[BLOCKSIZE];
float32_t wire2[BLOCKSIZE];
float32_t wire3[BLOCKSIZE];
float32_t err_signal[BLOCKSIZE];

                                                                         
                      
                                                                        

int32_t main(void)
{
  uint32_t i;
  arm_status status;
  uint32_t index;
  float32_t minValue;

                                             
  arm_lms_norm_init_f32(&lmsNorm_instance, NUMTAPS, lmsNormCoeff_f32, lmsStateF32, MU, BLOCKSIZE);

                                         
  arm_fir_init_f32(&LPF_instance, NUMTAPS, (float32_t *)FIRCoeff_f32, firStateF32, BLOCKSIZE);

                                                                           
                                                                   
                            
                                                                          

  for(i=0; i < NUMFRAMES; i++)
  {
                                                                               
    arm_copy_f32(testInput_f32 + (i * BLOCKSIZE), wire1, BLOCKSIZE);

                                                                            
    arm_fir_f32(&LPF_instance, wire1, wire2, BLOCKSIZE);

                                                 

    arm_lms_norm_f32(&lmsNorm_instance,                       
         wire1,                                           
         wire2,                                               
         wire3,                                               
         err_signal,                                                                                      
         BLOCKSIZE);                                   

                            
    arm_scale_f32(wire3, 5, wire3, BLOCKSIZE);                        
  }

  status = ARM_MATH_SUCCESS;

                                                                                    
                                                        
                                                                                    

  arm_abs_f32(err_signal, err_signal, BLOCKSIZE);
  arm_min_f32(err_signal, BLOCKSIZE, &minValue, &index);

  if (minValue > DELTA_ERROR)
  {
    status = ARM_MATH_TEST_FAILURE;
  }

                                                                           
                                                        
                                                                          

  arm_sub_f32((float32_t *)FIRCoeff_f32, lmsNormCoeff_f32, lmsNormCoeff_f32, NUMTAPS);

  arm_abs_f32(lmsNormCoeff_f32, lmsNormCoeff_f32, NUMTAPS);
  arm_min_f32(lmsNormCoeff_f32, NUMTAPS, &minValue, &index);

  if (minValue > DELTA_COEFF)
  {
    status = ARM_MATH_TEST_FAILURE;
  }

                                                                           
                                                                
                               
                                                                          

  if ( status != ARM_MATH_SUCCESS)
  {
    while (1);
  }

  while (1);                                                                
}

                
