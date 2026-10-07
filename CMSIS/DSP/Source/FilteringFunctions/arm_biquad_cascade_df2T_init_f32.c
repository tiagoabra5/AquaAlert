                                                                         
                                  
                                                   
                                                                                                           
  
                               
                       
  
                                   
                                                                          
/*
 * Copyright (C) 2010-2019 ARM Limited or its affiliates. All rights reserved.
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

   
                       
   

   
                               
    
   

   
                                                                                                                
                                                                                
                                                                      
                                                               
                                                        
                     

                                               
                                                                                                       
                                           
       
                                                             
        
                   
      
                                                                                                        
                                                                                                   
                                                                                                                  

                                                                                                          
                             
                                                                
                                                                                
                                                            

                                                                        

                                                             
       
                                                                                             
                                                                                     
        

                                                                                      
                                               

       
                                                             
        


      
                                                                       
                                                                                                
                                                                                                                  
                                                                                         
                                                                                                                         
   

#if defined(ARM_MATH_NEON) 
  

                                                      
                              
                                                                 

                                                                        
                                                                           

  
void arm_biquad_cascade_df2T_compute_coefs_f32(
  arm_biquad_cascade_df2T_instance_f32 * S,
  uint8_t numStages,
  float32_t * pCoeffs)
{
   uint8_t cnt;
   float32_t *pDstCoeffs;
   float32_t b0[4],b1[4],b2[4],a1[4],a2[4];

   pDstCoeffs = S->pCoeffs;

   cnt = numStages >> 2; 
   while(cnt > 0)
   {
      for(int i=0;i<4;i++)
      {
        b0[i] = pCoeffs[0];
        b1[i] = pCoeffs[1];
        b2[i] = pCoeffs[2];
        a1[i] = pCoeffs[3];
        a2[i] = pCoeffs[4];
        pCoeffs += 5;
      }

                 
      *pDstCoeffs++ = 0;
      *pDstCoeffs++ = b0[1];
      *pDstCoeffs++ = b0[2];
      *pDstCoeffs++ = b0[3];

                 
      *pDstCoeffs++ = 0;
      *pDstCoeffs++ = 0;
      *pDstCoeffs++ = b0[1] * b0[2];
      *pDstCoeffs++ = b0[2] * b0[3];

                 
      *pDstCoeffs++ = 0;
      *pDstCoeffs++ = 0;
      *pDstCoeffs++ = 0;
      *pDstCoeffs++ = b0[1] * b0[2] * b0[3];
      
                 
      *pDstCoeffs++ = b0[0];
      *pDstCoeffs++ = b0[0] * b0[1];
      *pDstCoeffs++ = b0[0] * b0[1] * b0[2];
      *pDstCoeffs++ = b0[0] * b0[1] * b0[2] * b0[3];

                 
      *pDstCoeffs++ = b1[0];
      *pDstCoeffs++ = b1[1];
      *pDstCoeffs++ = b1[2];
      *pDstCoeffs++ = b1[3];

                 
      *pDstCoeffs++ = b2[0];
      *pDstCoeffs++ = b2[1];
      *pDstCoeffs++ = b2[2];
      *pDstCoeffs++ = b2[3];

                 
      *pDstCoeffs++ = a1[0];
      *pDstCoeffs++ = a1[1];
      *pDstCoeffs++ = a1[2];
      *pDstCoeffs++ = a1[3];

                 
      *pDstCoeffs++ = a2[0];
      *pDstCoeffs++ = a2[1];
      *pDstCoeffs++ = a2[2];
      *pDstCoeffs++ = a2[3];

      cnt--;
   }

   cnt = numStages & 0x3;
   while(cnt > 0)
   {
      *pDstCoeffs++ = *pCoeffs++;
      *pDstCoeffs++ = *pCoeffs++;
      *pDstCoeffs++ = *pCoeffs++;
      *pDstCoeffs++ = *pCoeffs++;
      *pDstCoeffs++ = *pCoeffs++;
      cnt--;
   }

}
#endif 

void arm_biquad_cascade_df2T_init_f32(
        arm_biquad_cascade_df2T_instance_f32 * S,
        uint8_t numStages,
  const float32_t * pCoeffs,
        float32_t * pState)
{
                            
  S->numStages = numStages;

                                  
  S->pCoeffs = pCoeffs;

                                                           
  memset(pState, 0, (2U * (uint32_t) numStages) * sizeof(float32_t));

                            
  S->pState = pState;
}

   
                                   
   
