                                                                         
                                  
                               
                                                        
  
                               
                       
  
                                   
                                                                          
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

   
                          
   

   
                                            

                                                                                                  
                                                                                              
                                                                             
                                                                                                                      
                                                                           
                                                                                                                     
                                                                                                                    
  
                                                                                         
                                                                             
                                                                      
                                                                                                                                
  
                                                                                                                                                 
                                                                                                                                
                                                              
                     
                        
                                                                                         
  
                                                       
                                                            
 
                          
                                                                                                      
                                               
                                                           
      
                                                     
                                                
                                                           
      
                                                                                                                                             
                                                                                                          
                                                                   
                                                                                                                                   
 
                                                    
                                                                                                         
                                                                                                       

                                   
                                                                                                                                             
                                                                                    
                                                                                                             
                 
                                         
                                                                                          
                                                                                 
                                                                      
                                                                                                                                  
      
                                                                  
                                                                                                                                           
                                                                                                                                 
                                                                         
       
                                                                                         
                                                                                         
                                                                                         
        
                                                                                                   
                                                                                                  
                                                                  
                                                               
                                                            
                                                               
                                                                                                            
                                                                                               
 
                                     
                                                                                                          
                                                                                                                                   
                                                                                           
   

    
                        
    
   

   
                                                                       
                                                                                               
                                                     
                                                                             
                     
   

void arm_dct4_f32(
  const arm_dct4_instance_f32 * S,
        float32_t * pState,
        float32_t * pInlineBuffer)
{
  const float32_t *weights = S->pTwiddle;                                                
  const float32_t *cosFact = S->pCosFactor;                                                  
        float32_t *pS1, *pS2, *pbuff;                                                                             
        float32_t in;                                                          
        uint32_t i;                                                      


                                                                    
                                                        
                                                     
                                                                   
                                                
                        
                                                    
                                                                         
                                                                   
                                                                           
                                                                     
                                                                                           
                                                                                              
                                                                 
                                  
                                                                     
                                                                      
     

                                          
                                                                                      
  arm_scale_f32(pInlineBuffer, 2.0f, pInlineBuffer, S->N);
  arm_mult_f32(pInlineBuffer, cosFact, pInlineBuffer, S->N);

                                                                     
                                                   
                                                    
                                                                        
                                                                          

                                 
  pS1 = pState;

                                                                                       
  pS2 = pState + (S->N - 1U);

                                         
  pbuff = pInlineBuffer;


#if defined (ARM_MATH_LOOPUNROLL)

                                                                         
  i = S->Nby2 >> 2U;

                                                                                    
                                                                   
  do
  {
                                              
                                         
    *pS1++ = *pbuff++;
                                              
    *pS2-- = *pbuff++;

    *pS1++ = *pbuff++;
    *pS2-- = *pbuff++;

    *pS1++ = *pbuff++;
    *pS2-- = *pbuff++;

    *pS1++ = *pbuff++;
    *pS2-- = *pbuff++;

                                
    i--;
  } while (i > 0U);

                                         
  pbuff = pInlineBuffer;

                                 
  pS1 = pState;

                                                                            
  i = S->N >> 2U;

                                                                         
                                   
  do
  {
                                                                    
    *pbuff++ = *pS1++;
    *pbuff++ = *pS1++;
    *pbuff++ = *pS1++;
    *pbuff++ = *pS1++;

                                    
    i--;
  } while (i > 0U);


                                                              
                                                
                                                                  
                                                                                           
  arm_rfft_f32 (S->pRfft, pInlineBuffer, pState);

                                                                          
                                                      
                                                                            
  arm_cmplx_mult_cmplx_f32 (pState, weights, pState, S->N);

                                              
                                                        
                                                     
                                     
                                                                       

                                                                       
  i = (S->N - 1U) >> 2U;

                                          
  pbuff = pInlineBuffer;

                                 
  pS1 = pState;

                                                          
  in = *pS1++ * (float32_t) 0.5;
                                                                                      
  *pbuff++ = in;

                                                                                                     
  pS1++;

                                                                                    
                                                                   
  do
  {
                                                                                     
                                                                                                             
    in = *pS1++ - in;
    *pbuff++ = in;
                                       
    pS1++;

    in = *pS1++ - in;
    *pbuff++ = in;
    pS1++;

    in = *pS1++ - in;
    *pbuff++ = in;
    pS1++;

    in = *pS1++ - in;
    *pbuff++ = in;
    pS1++;

                                    
    i--;
  } while (i > 0U);

                                                                                        
                                   
  i = (S->N - 1U) % 0x4U;

  while (i > 0U)
  {
                                                                                     
                                                                                                             
    in = *pS1++ - in;
    *pbuff++ = in;

                                       
    pS1++;

                                    
    i--;
  }


                                                                                               

                                                                            
  i = S->N >> 2U;

                                                                              
  pbuff = pInlineBuffer;

                                                                                                         
  do
  {
                                                                         
    in = *pbuff;
    *pbuff++ = in * S->normalize;

    in = *pbuff;
    *pbuff++ = in * S->normalize;

    in = *pbuff;
    *pbuff++ = in * S->normalize;

    in = *pbuff;
    *pbuff++ = in * S->normalize;

                                    
    i--;
  } while (i > 0U);


#else

                                            
  i = S->Nby2;

  do
  {
                                              
                                         
    *pS1++ = *pbuff++;
                                              
    *pS2-- = *pbuff++;

                                    
    i--;
  } while (i > 0U);

                                         
  pbuff = pInlineBuffer;

                                 
  pS1 = pState;

                                     
  i = S->N;

  do
  {
                                                                    
    *pbuff++ = *pS1++;

                                    
    i--;
  } while (i > 0U);


                                                              
                                                
                                                                  
                                                                                           
  arm_rfft_f32 (S->pRfft, pInlineBuffer, pState);

                                                                          
                                                      
                                                                            
  arm_cmplx_mult_cmplx_f32 (pState, weights, pState, S->N);

                                              
                                                        
                                                     
                                     
                                                                       

                                          
  pbuff = pInlineBuffer;

                                 
  pS1 = pState;

                                                          
  in = *pS1++ * (float32_t) 0.5;
                                                                                      
  *pbuff++ = in;

                                                                                                     
  pS1++;

                                     
  i = (S->N - 1U);

  do
  {
                                                                                     
                                                                                                             
    in = *pS1++ - in;
    *pbuff++ = in;

                                       
    pS1++;

                                
    i--;
  } while (i > 0U);

                                                                                               

                                 
  i = S->N;

                                                                               
  pbuff = pInlineBuffer;

  do
  {
                                                                         
    in = *pbuff;
    *pbuff++ = in * S->normalize;

                                
    i--;
  } while (i > 0U);

#endif                                        

}

   
                            
   
