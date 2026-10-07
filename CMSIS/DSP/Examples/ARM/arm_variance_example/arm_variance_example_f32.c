/* ----------------------------------------------------------------------
* Copyright (C) 2010-2012 ARM Limited. All rights reserved.
*
* $Date:         17. January 2013
* $Revision:     V1.4.0
*
* Project:       CMSIS DSP Library
* Title:         arm_variance_example_f32.c
*
* Description:   Example code demonstrating variance calculation of input sequence.
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

   
                         
   

   
                                             
  
                    
       
                                                                                           
                                                                                      
  
                  
       
                                                                                                 
       
                                             
                                                                                                                                 
                                                                                                     
                                                                              
       
                                                
                                                    
  
                      
       
                           
  
  
                              
       
                                                
                                                    
                                                         
                                                 
  
                                                  
       
                       
                   
                  
                   
                   
  
                  
                                            
  
   


                                       
    

#include <math.h>
#include "arm_math.h"

                                                                         
                                     
                                                                        
#define MAX_BLOCKSIZE   32
#define DELTA           (0.000001f)


                                                                         
                     
                                                                        
float32_t wire1[MAX_BLOCKSIZE];
float32_t wire2[MAX_BLOCKSIZE];
float32_t wire3[MAX_BLOCKSIZE];

                                                                         
                                                                      
                                          
                                                                        

float32_t testInput_f32[32] =
{
  -0.432564811528221,  -1.665584378238097,   0.125332306474831,   0.287676420358549,
  -1.146471350681464,   1.190915465642999,   1.189164201652103,  -0.037633276593318,
   0.327292361408654,   0.174639142820925,  -0.186708577681439,   0.725790548293303,
  -0.588316543014189,   2.183185818197101,  -0.136395883086596,   0.113931313520810,
   1.066768211359189,   0.059281460523605,  -0.095648405483669,  -0.832349463650022,
   0.294410816392640,  -1.336181857937804,   0.714324551818952,   1.623562064446271,
  -0.691775701702287,   0.857996672828263,   1.254001421602532,  -1.593729576447477,
  -1.440964431901020,   0.571147623658178,  -0.399885577715363,   0.689997375464345

};

                                                                         
                          
                                                                        
uint32_t blockSize = 32;
float32_t  refVarianceOut = 0.903941793931839;

                                                                         
                           
                                                                        

int32_t main(void)
{
  arm_status status;
  float32_t mean, oneByBlockSize;
  float32_t variance;
  float32_t diff;

  status = ARM_MATH_SUCCESS;

#if defined(FILEIO)
  printf("START\n");
#endif

 
                                          

                                                                  

                                        
  arm_fill_f32(1.0,  wire1, blockSize);

                                                    
                                              
  arm_dot_prod_f32(testInput_f32, wire1, blockSize, &mean);

                                  
  oneByBlockSize = 1.0 / (blockSize);

                                                              
  arm_mult_f32(&mean, &oneByBlockSize, &mean, 1);


                                              

                                                                                                                   

                                     
  arm_fill_f32(mean,  wire2, blockSize);

                             
  arm_sub_f32(testInput_f32, wire2, wire3, blockSize);

                             
  arm_copy_f32(wire3, wire2, blockSize);

                                                                                                   
  arm_dot_prod_f32(wire2, wire3, blockSize, &variance);

                                    
  oneByBlockSize = 1.0 / (blockSize - 1);

                               
  arm_mult_f32(&variance, &oneByBlockSize, &variance, 1);

                                                         
  diff = fabsf(refVarianceOut - variance);

                                                   
  
  if (diff > DELTA)
  {
    status = ARM_MATH_TEST_FAILURE;
  }


#if !defined(FILEIO)
  if ( status != ARM_MATH_SUCCESS)
  {
    while (1);
  }

  while (1);                                                               
#else
  if (status == ARM_MATH_SUCCESS)
  {
     printf("SUCCESS\n");
  }
  else
  {
     printf("FAILURE\n");
  }
#endif
}

                


