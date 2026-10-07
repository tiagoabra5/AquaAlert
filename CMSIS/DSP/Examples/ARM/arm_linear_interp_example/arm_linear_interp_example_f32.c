/* ----------------------------------------------------------------------
* Copyright (C) 2010-2012 ARM Limited. All rights reserved.
*
* $Date:         17. January 2013
* $Revision:     V1.4.0
*
* Project:       CMSIS DSP Library
* Title:         arm_linear_interp_example_f32.c
*
* Description:   Example code demonstrating usage of sin function
*                and uses linear interpolation to get higher precision
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

#define SNR_THRESHOLD           90
#define TEST_LENGTH_SAMPLES     10
#define XSPACING               (0.00005f)

                                                                         
                                      
                                         
                   
                                                             
                                                                        
float32_t testInputSin_f32[TEST_LENGTH_SAMPLES] =
{
   -0.649716504673081170, -2.501723745497831200,
    0.188250329003310100,  0.432092748487532540,
   -1.722010988459680800,  1.788766476323060600,
    1.786136060975809500, -0.056525543169408797,
    0.491596272728153760,  0.262309671126153390
};

                                                                                
                                                        
                                        
                                                                                 
float32_t testRefSinOutput32_f32[TEST_LENGTH_SAMPLES] =
{
   -0.604960695383043530, -0.597090287967934840,
    0.187140422442966500,  0.418772124875992690,
   -0.988588831792106880,  0.976338412038794010,
    0.976903856413481100, -0.056495446835214236,
    0.472033731854734240,  0.259311907228582830
};

                                                                                
                                                                
                                                                                 
float32_t testOutput[TEST_LENGTH_SAMPLES];

                                                                                
                                                                 
                                                                                 
float32_t testLinIntOutput[TEST_LENGTH_SAMPLES];

                                                                                
                                               
                                                                                 
extern float arm_linear_interep_table[188495];

                                                                         
                                                               
                                                                        
float32_t snr1;
float32_t snr2;

                                                                               
                                                                              
                                                                                 
int32_t main(void)
{
  uint32_t i;
  arm_status status;

  arm_linear_interp_instance_f32 S = {188495, -3.141592653589793238, XSPACING, &arm_linear_interep_table[0]};

                                                                                  
                                                           
                                                                                   
  for(i=0; i< TEST_LENGTH_SAMPLES; i++)
  {
    testOutput[i] = arm_sin_f32(testInputSin_f32[i]);
  }

                                                                                  
                                                                                    
                                                                                   

  for(i=0; i< TEST_LENGTH_SAMPLES; i++)
  {
      testLinIntOutput[i] = arm_linear_interp_f32(&S, testInputSin_f32[i]);
  }

                                                                                  
                                           
                                                                                   
  snr1 = arm_snr_f32(testRefSinOutput32_f32, testOutput, 2);

                                                                                  
                                           
                                                                                   
  snr2 = arm_snr_f32(testRefSinOutput32_f32, testLinIntOutput, 2);

                                                                                  
                                                              
                                                                                   
  if ( snr2 > snr1)
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

                
