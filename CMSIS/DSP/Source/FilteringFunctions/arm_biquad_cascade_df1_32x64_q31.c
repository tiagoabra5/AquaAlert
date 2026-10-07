                                                                         
                                  
                                                   
                                                                             
  
                               
                       
  
                                   
                                                                          
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

   
                       
   

   
                                                                           

                                                                                   
                                                                                      
                                                                                     
                                             
                                                                              
                                                                                  
                                                

                                                          
                                                                                
                                                                                       
                                               

                          
                                                                                                    
       
                                                                              
        
                                                                                                         
                                                                      
                                                                                                                                                            
                                                                                                                                                                  
                                                                                  
                                                                
       
                                                                              
        
                                                                                                                                                   
      
                                                                                           
                                                                                           
                                                                                                                        
                                                                                                    
                                                                                                         
                                                                                                 
                                                             
      
                                                                           
                                                                                                                                                                                    
                                                                    
       
                                      
        
      
                                                                                                                  
                                                                                                                
                                                                                                                         

                                   
                                                                                                                       
                                                                                 
                                                                                                                         

                              
                                                                                                               
                                                                      
                                                              
                                                                                                                                
                                                                                                       

      
                                                                  
                                                                                                                                           
                                                                                                                                 
                                                                                            
                                                                                          
       
                                                                                    
        
                                                                                             
                                                                          
                                                                                 
                                                                                                 
                                     
                                                                                       
                                                       
                                            
                                
                                            

      
                                                                               
                                                                       
                                                                                                     
                                                                                                 
                                                                                                                                        
                                                                                                                      
                                                                                               
                                                           
       
                                
        
                                                
       
                                  
        
                                                   
      
                                                                                   
                                                                                               
                                                                                                
                                                                         
                                                                                                     
                                                                                                   
                                                                                                          
                                                                                                                            
      
                                                                                                                     
                                                                                  
   

   
                                    
    
   

   
                                                                             
                                                                                                
                                                            
                                                             
                                                       
                     

                        
                                                                                    
                                                                                                                                                                  
                                                                                              
                                                                                                                                            
                                                                                                                                                             
                                                             
      
                                                                               
                                                                                                                                                       
                                                                                                                                                            
   

void arm_biquad_cas_df1_32x64_q31(
  const arm_biquad_cas_df1_32x64_ins_q31 * S,
        q31_t * pSrc,
        q31_t * pDst,
        uint32_t blockSize)
{
        q31_t *pIn = pSrc;                                                               
        q31_t *pOut = pDst;                                                               
        q63_t *pState = S->pState;                                                       
  const q31_t *pCoeffs = S->pCoeffs;                                                     
        q63_t acc;                                                      
        q31_t Xn1, Xn2;                                                                  
        q63_t Yn1, Yn2;                                                                   
        q31_t b0, b1, b2, a1, a2;                                               
        q31_t Xn;                                                           
        int32_t shift = (int32_t) S->postShift + 1;                                           
        uint32_t sample, stage = S->numStages;                            
        q31_t acc_l, acc_h;                                                  
        uint32_t uShift = ((uint32_t) S->postShift + 1U);
        uint32_t lShift = 32U - uShift;                                                       

  do
  {
                                  
    b0 = *pCoeffs++;
    b1 = *pCoeffs++;
    b2 = *pCoeffs++;
    a1 = *pCoeffs++;
    a2 = *pCoeffs++;

                                  
    Xn1 = (q31_t) (pState[0]);
    Xn2 = (q31_t) (pState[1]);
    Yn1 = pState[2];
    Yn2 = pState[3];

#if defined (ARM_MATH_LOOPUNROLL)

                                                                          
                                                                                             
                                                                               
       

                                                     
    sample = blockSize >> 2U;

    while (sample > 0U)
    {
                          
      Xn = *pIn++;

                                                                                    

                            
      acc = (q63_t) Xn * b0;

                               
      acc += (q63_t) Xn1 * b1;

                                 
      acc += (q63_t) Xn2 * b2;

                               
      acc += mult32x64(Yn1, a1);

                               
      acc += mult32x64(Yn2, a2);

                                                                    
      Yn2 = acc << shift;

                                  
      acc_l = acc & 0xffffffff;

                                  
      acc_h = (acc >> 32) & 0xffffffff;

                                                                   
      acc_h = (uint32_t) acc_l >> lShift | acc_h << uShift;

                                                                      
      *pOut = acc_h;

                                                              
      Xn2 = *pIn++;

                                                                                    

                               
      acc = (q63_t) Xn * b1;

                            
      acc += (q63_t) Xn2 * b0;

                                 
      acc += (q63_t) Xn1 * b2;

                               
      acc += mult32x64(Yn2, a1);

                               
      acc += mult32x64(Yn1, a2);

                                                                   
      Yn1 = acc << shift;

                                  
      acc_l = acc & 0xffffffff;

                                  
      acc_h = (acc >> 32) & 0xffffffff;

                                                                   
      acc_h = (uint32_t) acc_l >> lShift | acc_h << uShift;

                                                             
      Xn1 = *pIn++;

                                           
                                                       
      *(pOut + 1U) = acc_h;

                                                                                    

                            
      acc = (q63_t) Xn1 * b0;

                               
      acc += (q63_t) Xn2 * b1;

                                 
      acc += (q63_t) Xn * b2;

                               
      acc += mult32x64(Yn1, a1);

                               
      acc += mult32x64(Yn2, a2);

                                                                    
      Yn2 = acc << shift;

                                  
      acc_l = acc & 0xffffffff;

                                  
      acc_h = (acc >> 32) & 0xffffffff;

                                                                   
      acc_h = (uint32_t) acc_l >> lShift | acc_h << uShift;

                                                                      
      *(pOut + 2U) = acc_h;

                                                             
      Xn = *pIn++;

                                                                                    
                            
      acc = (q63_t) Xn * b0;

                               
      acc += (q63_t) Xn1 * b1;

                                 
      acc += (q63_t) Xn2 * b2;

                               
      acc += mult32x64(Yn2, a1);

                               
      acc += mult32x64(Yn1, a2);

                                                                    
      Yn1 = acc << shift;

                                  
      acc_l = acc & 0xffffffff;

                                  
      acc_h = (acc >> 32) & 0xffffffff;

                                                                   
      acc_h = (uint32_t) acc_l >> lShift | acc_h << uShift;

                                                                      
      *(pOut + 3U) = acc_h;

                                                                            
                                            
                     
                     
                     
                     
      Xn2 = Xn1;
      Xn1 = Xn;

                                 
      pOut += 4U;

                                  
      sample--;
    }

                                                   
    sample = blockSize & 0x3U;

#else

                                                  
    sample = blockSize;

#endif                                        

    while (sample > 0U)
    {
                          
      Xn = *pIn++;

                                                                                    

                            
      acc = (q63_t) Xn * b0;
                               
      acc += (q63_t) Xn1 * b1;
                                 
      acc += (q63_t) Xn2 * b2;
                               
      acc += mult32x64(Yn1, a1);
                               
      acc += mult32x64(Yn2, a2);

                                                                            
                                            
                     
                     
                     
                     
      Xn2 = Xn1;
      Xn1 = Xn;
      Yn2 = Yn1;

                                                                    
      Yn1 = acc << shift;

                                  
      acc_l = acc & 0xffffffff;

                                  
      acc_h = (acc >> 32) & 0xffffffff;

                                                                   
      acc_h = (uint32_t) acc_l >> lShift | acc_h << uShift;

                                                                      
      *pOut++ = acc_h;
                               

                                                                      
                                                  

                                  
      sample--;
    }

                                                                       
    pIn = pDst;

                                                     
    pOut = pDst;

                                                                       
    *pState++ = (q63_t) Xn1;
    *pState++ = (q63_t) Xn2;
    *pState++ = Yn1;
    *pState++ = Yn2;

  } while (--stage);

}

   
                                        
   
