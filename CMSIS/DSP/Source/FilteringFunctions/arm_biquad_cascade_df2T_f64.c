                                                                         
                                  
                                              
                                                                                                       
  
                               
                       
  
                                   
                                                                          
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

   
                       
  

   
                                                                                                    

                                                                                                                       
                                                                           
                                                                                                           
                                        

                                                                                        
                                                              
                                                         
                                                       
                                                    

                          
                                                                                                    
       
                          
                                    
                               
        
                                                                  
      
                                                                                              
                                                                                                
                                                                                                                                                             
                                                                                                                                                                  
                                                                                  
                                                                                
       
                           
                                     
                                
        
                                                                                                                                                   
      
                                                                                           
                                                                                           
                                                                                                                        
                                                                                                                  
                                                                                                                                   
      
                                                                          
                                                                                               
                                                                                        
       
                               
        
                                                                                                
                                                                                        
                                                                                         
                                                                                                                         
      
                                                                                                                 
                                                                                                                                 
                                                                                           
                                                                                                                                                                         
                                                                                                                     
                                                                                                                                                        

                                   
                                                                                                                       
                                                                                 
                                                                                                                         

                               
                                                                       
                                                                             
                                                                      
                                                              
                                                                                                                                
                                                                                            
      
                                                                  
                                                                                                                                           
                                                                                                                                 
                                                                                            
                                                                                   
       
                                                                             
                                                                             
        
                                                                                             
                                                                          
                                                                                 
  

   
                               
    
   

   
                                                                                                            
                                                                             
                                                            
                                                             
                                                       
                     
   

LOW_OPTIMIZATION_ENTER
void arm_biquad_cascade_df2T_f64(
  const arm_biquad_cascade_df2T_instance_f64 * S,
        float64_t * pSrc,
        float64_t * pDst,
        uint32_t blockSize)
{

        float64_t *pIn = pSrc;                                             
        float64_t *pOut = pDst;                                                 
        float64_t *pState = S->pState;                                    
        float64_t *pCoeffs = S->pCoeffs;                                        
        float64_t acc1;                                                 
        float64_t b0, b1, b2, a1, a2;                                           
        float64_t Xn1;                                                      
        float64_t d1, d2;                                                   
        uint32_t sample, stage = S->numStages;                            


   do
   {
                                    
      b0 = pCoeffs[0];
      b1 = pCoeffs[1];
      b2 = pCoeffs[2];
      a1 = pCoeffs[3];
      a2 = pCoeffs[4];

                                    
      d1 = pState[0];
      d2 = pState[1];

      pCoeffs += 5U;

#if defined (ARM_MATH_LOOPUNROLL)

                                                      
      sample = blockSize >> 4U;

      while (sample > 0U) {

                                    
                                              
                                         

        
         Xn1 = *pIn++;

         acc1 = b0 * Xn1 + d1;

         d1 = b1 * Xn1 + d2;
         d1 += a1 * acc1;

         d2 = b2 * Xn1;
         d2 += a2 * acc1;

         *pOut++ = acc1;


        
         Xn1 = *pIn++;

         acc1 = b0 * Xn1 + d1;

         d1 = b1 * Xn1 + d2;
         d1 += a1 * acc1;

         d2 = b2 * Xn1;
         d2 += a2 * acc1;

         *pOut++ = acc1;

        
         Xn1 = *pIn++;

         acc1 = b0 * Xn1 + d1;

         d1 = b1 * Xn1 + d2;
         d1 += a1 * acc1;

         d2 = b2 * Xn1;
         d2 += a2 * acc1;

         *pOut++ = acc1;

        
         Xn1 = *pIn++;

         acc1 = b0 * Xn1 + d1;

         d1 = b1 * Xn1 + d2;
         d1 += a1 * acc1;

         d2 = b2 * Xn1;
         d2 += a2 * acc1;

         *pOut++ = acc1;

        
         Xn1 = *pIn++;

         acc1 = b0 * Xn1 + d1;

         d1 = b1 * Xn1 + d2;
         d1 += a1 * acc1;

         d2 = b2 * Xn1;
         d2 += a2 * acc1;

         *pOut++ = acc1;

        
         Xn1 = *pIn++;

         acc1 = b0 * Xn1 + d1;

         d1 = b1 * Xn1 + d2;
         d1 += a1 * acc1;

         d2 = b2 * Xn1;
         d2 += a2 * acc1;

         *pOut++ = acc1;

        
         Xn1 = *pIn++;

         acc1 = b0 * Xn1 + d1;

         d1 = b1 * Xn1 + d2;
         d1 += a1 * acc1;

         d2 = b2 * Xn1;
         d2 += a2 * acc1;

         *pOut++ = acc1;

        
         Xn1 = *pIn++;

         acc1 = b0 * Xn1 + d1;

         d1 = b1 * Xn1 + d2;
         d1 += a1 * acc1;

         d2 = b2 * Xn1;
         d2 += a2 * acc1;

         *pOut++ = acc1;

        
         Xn1 = *pIn++;

         acc1 = b0 * Xn1 + d1;

         d1 = b1 * Xn1 + d2;
         d1 += a1 * acc1;

         d2 = b2 * Xn1;
         d2 += a2 * acc1;

         *pOut++ = acc1;

        
         Xn1 = *pIn++;

         acc1 = b0 * Xn1 + d1;

         d1 = b1 * Xn1 + d2;
         d1 += a1 * acc1;

         d2 = b2 * Xn1;
         d2 += a2 * acc1;

         *pOut++ = acc1;

        
         Xn1 = *pIn++;

         acc1 = b0 * Xn1 + d1;

         d1 = b1 * Xn1 + d2;
         d1 += a1 * acc1;

         d2 = b2 * Xn1;
         d2 += a2 * acc1;

         *pOut++ = acc1;

        
         Xn1 = *pIn++;

         acc1 = b0 * Xn1 + d1;

         d1 = b1 * Xn1 + d2;
         d1 += a1 * acc1;

         d2 = b2 * Xn1;
         d2 += a2 * acc1;

         *pOut++ = acc1;

        
         Xn1 = *pIn++;

         acc1 = b0 * Xn1 + d1;

         d1 = b1 * Xn1 + d2;
         d1 += a1 * acc1;

         d2 = b2 * Xn1;
         d2 += a2 * acc1;

         *pOut++ = acc1;

        
         Xn1 = *pIn++;

         acc1 = b0 * Xn1 + d1;

         d1 = b1 * Xn1 + d2;
         d1 += a1 * acc1;

         d2 = b2 * Xn1;
         d2 += a2 * acc1;

         *pOut++ = acc1;

        
         Xn1 = *pIn++;

         acc1 = b0 * Xn1 + d1;

         d1 = b1 * Xn1 + d2;
         d1 += a1 * acc1;

         d2 = b2 * Xn1;
         d2 += a2 * acc1;

         *pOut++ = acc1;

        
         Xn1 = *pIn++;

         acc1 = b0 * Xn1 + d1;

         d1 = b1 * Xn1 + d2;
         d1 += a1 * acc1;

         d2 = b2 * Xn1;
         d2 += a2 * acc1;

         *pOut++ = acc1;

                                     
         sample--;
      }

                                                   
      sample = blockSize & 0xFU;

#else

                                                  
    sample = blockSize;

#endif                                        

      while (sample > 0U) {
         Xn1 = *pIn++;

         acc1 = b0 * Xn1 + d1;

         d1 = b1 * Xn1 + d2;
         d1 += a1 * acc1;

         d2 = b2 * Xn1;
         d2 += a2 * acc1;

         *pOut++ = acc1;

                                     
         sample--;
      }

                                                                       
      pState[0] = d1;
      pState[1] = d2;

      pState += 2U;

                                                                            
      pIn = pDst;

                                            
      pOut = pDst;

                                  
      stage--;

   } while (stage > 0U);

}
LOW_OPTIMIZATION_EXIT

   
                                   
   
