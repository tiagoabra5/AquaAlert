/* ----------------------------------------------------------------------
* Copyright (C) 2010-2012 ARM Limited. All rights reserved.
*
* $Date:        17. January 2013
* $Revision: 	V1.4.0  b
*
* Project: 	    CMSIS DSP Library
*
* Title:	    math_helper.c
*
* Description:	Definition of all helper functions required.
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

                                                                         
                                
                                                                         
#include<math.h>

                                                                         
                               
                                                                         
#include "math_helper.h"

   
                             
                                                    
                                               
                                               
                  
                                                                         
                  
   

float arm_snr_f32(float *pRef, float *pTest, uint32_t buffSize)
{
  float EnergySignal = 0.0, EnergyError = 0.0;
  uint32_t i;
  float SNR;
  int temp;
  int *test;

  for (i = 0; i < buffSize; i++)
    {
 	                                              
	  test =   (int *)(&pRef[i]);
      temp =  *test;

	  if (temp == 0x7FC00000)
	  {
	  		return(0);
	  }

	                                               
	  test =   (int *)(&pTest[i]);
      temp =  *test;

	  if (temp == 0x7FC00000)
	  {
	  		return(0);
	  }
      EnergySignal += pRef[i] * pRef[i];
      EnergyError += (pRef[i] - pTest[i]) * (pRef[i] - pTest[i]);
    }

	                                             
	test =   (int *)(&EnergyError);
    temp =  *test;

    if (temp == 0x7FC00000)
    {
  		return(0);
    }


  SNR = 10 * log10 (EnergySignal / EnergyError);

  return (SNR);

}


   
                                              
                                                      
                                         
                                         
               
                                                      
                    
   

void arm_provide_guard_bits_q15 (q15_t * input_buf, uint32_t blockSize,
                            uint32_t guard_bits)
{
  uint32_t i;

  for (i = 0; i < blockSize; i++)
    {
      input_buf[i] = input_buf[i] >> guard_bits;
    }
}

   
                                                   
                                                  
                                                  
                                                                
               
                                                                            
   

void arm_float_to_q12_20(float *pIn, q31_t * pOut, uint32_t numSamples)
{
  uint32_t i;

  for (i = 0; i < numSamples; i++)
    {
	                                            
      pOut[i] = (q31_t) (pIn[i] * 1048576.0f);

      pOut[i] += pIn[i] > 0 ? 0.5 : -0.5;

      if (pIn[i] == (float) 1.0)
        {
          pOut[i] = 0x000FFFFF;
        }
    }
}

   
                                                              
                                                
                                                 
                                                          
                             
   

uint32_t arm_compare_fixed_q15(q15_t *pIn, q15_t *pOut, uint32_t numSamples)
{
  uint32_t i;
  int32_t diff, diffCrnt = 0;
  uint32_t maxDiff = 0;

  for (i = 0; i < numSamples; i++)
  {
  	diff = pIn[i] - pOut[i];
  	diffCrnt = (diff > 0) ? diff : -diff;

	if (diffCrnt > maxDiff)
	{
		maxDiff = diffCrnt;
	}
  }

  return(maxDiff);
}

   
                                                              
                                                
                                                 
                                                         
                             
   

uint32_t arm_compare_fixed_q31(q31_t *pIn, q31_t * pOut, uint32_t numSamples)
{
  uint32_t i;
  int32_t diff, diffCrnt = 0;
  uint32_t maxDiff = 0;

  for (i = 0; i < numSamples; i++)
  {
  	diff = pIn[i] - pOut[i];
  	diffCrnt = (diff > 0) ? diff : -diff;

	if (diffCrnt > maxDiff)
	{
		maxDiff = diffCrnt;
	}
  }

  return(maxDiff);
}

   
                                              
                                                      
                                         
                                         
               
                                                      
                    
   

void arm_provide_guard_bits_q31 (q31_t * input_buf,
								 uint32_t blockSize,
                                 uint32_t guard_bits)
{
  uint32_t i;

  for (i = 0; i < blockSize; i++)
    {
      input_buf[i] = input_buf[i] >> guard_bits;
    }
}

   
                                              
                                                      
                                         
                                         
               
                                                      
                    
   

void arm_provide_guard_bits_q7 (q7_t * input_buf,
								uint32_t blockSize,
                                uint32_t guard_bits)
{
  uint32_t i;

  for (i = 0; i < blockSize; i++)
    {
      input_buf[i] = input_buf[i] >> guard_bits;
    }
}



   
                                          
                                            
                     
                                                   
                           
   

uint32_t arm_calc_guard_bits (uint32_t num_adds)
{
  uint32_t i = 1, j = 0;

  if (num_adds == 1)
    {
      return (0);
    }

  while (i < num_adds)
    {
      i = i * 2;
      j++;
    }

  return (j);
}

   
                                     
                                                      
                                                                    
                                         
               
   

void arm_apply_guard_bits (float32_t *pIn,
						   uint32_t numSamples,
						   uint32_t guard_bits)
{
  uint32_t i;

  for (i = 0; i < numSamples; i++)
    {
      pIn[i] = pIn[i] * arm_calc_2pow(guard_bits);
    }
}

   
                                       
                                          
                            
   
uint32_t arm_calc_2pow(uint32_t numShifts)
{

  uint32_t i, val = 1;

  for (i = 0; i < numShifts; i++)
    {
      val = val * 2;
    }

  return(val);
}



   
                                      
                                                  
                                                   
                                                          
               
                                                                    
   

void arm_float_to_q14 (float *pIn, q15_t *pOut, uint32_t numSamples)
{
  uint32_t i;

  for (i = 0; i < numSamples; i++)
    {
	                                          
      pOut[i] = (q15_t) (pIn[i] * 16384.0f);

      pOut[i] += pIn[i] > 0 ? 0.5 : -0.5;

      if (pIn[i] == (float) 2.0)
        {
          pOut[i] = 0x7FFF;
        }

    }

}


   
                                             
                                                  
                                                   
                                                          
               
                                                                    
   

void arm_float_to_q30 (float *pIn, q31_t * pOut, uint32_t numSamples)
{
  uint32_t i;

  for (i = 0; i < numSamples; i++)
    {
	                                               
      pOut[i] = (q31_t) (pIn[i] * 1073741824.0f);

      pOut[i] += pIn[i] > 0 ? 0.5 : -0.5;

      if (pIn[i] == (float) 2.0)
        {
          pOut[i] = 0x7FFFFFFF;
        }
    }
}

   
                                             
                                                  
                                                   
                                                          
               
                                                                    
   

void arm_float_to_q29 (float *pIn, q31_t *pOut, uint32_t numSamples)
{
  uint32_t i;

  for (i = 0; i < numSamples; i++)
    {
	                                               
      pOut[i] = (q31_t) (pIn[i] * 536870912.0f);

      pOut[i] += pIn[i] > 0 ? 0.5 : -0.5;

      if (pIn[i] == (float) 4.0)
        {
          pOut[i] = 0x7FFFFFFF;
        }
    }
}


   
                                             
                                                  
                                                   
                                                          
               
                                                                    
   

void arm_float_to_q28 (float *pIn, q31_t *pOut, uint32_t numSamples)
{
  uint32_t i;

  for (i = 0; i < numSamples; i++)
    {
	                                            
      pOut[i] = (q31_t) (pIn[i] * 268435456.0f);

      pOut[i] += pIn[i] > 0 ? 0.5 : -0.5;

      if (pIn[i] == (float) 8.0)
        {
          pOut[i] = 0x7FFFFFFF;
        }
    }
}

   
                                         
                                             
                                                                
               
                                                                    
   

void arm_clip_f32 (float *pIn, uint32_t numSamples)
{
  uint32_t i;

  for (i = 0; i < numSamples; i++)
    {
      if (pIn[i] > 1.0f)
	  {
	    pIn[i] = 1.0;
	  }
	  else if ( pIn[i] < -1.0f)
	  {
	    pIn[i] = -1.0;
	  }

    }
}




