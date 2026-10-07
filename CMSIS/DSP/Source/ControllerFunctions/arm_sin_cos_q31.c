                                                                         
                                  
                                  
                                                         
  
                               
                       
  
                                   
                                                                          
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
#include "arm_common_tables.h"

   
                          
   

   
                    
    
   

   
                                      
                                                       
                                                         
                                                           
                     

                                                                                                            
   

void arm_sin_cos_q31(
  q31_t theta,
  q31_t * pSinVal,
  q31_t * pCosVal)
{
  q31_t fract;                                                                            
  uint16_t indexS, indexC;                                             
  q31_t f1, f2, d1, d2;                                                           
  q31_t Dn, Df;
  q63_t temp;

                                   
  indexS = (uint32_t)theta >> CONTROLLER_Q31_SHIFT;
  indexC = (indexS + 128) & 0x1ff;

                                       
  fract = (theta - (indexS << CONTROLLER_Q31_SHIFT)) << 8;

                                                                        
  f1 =  sinTable_q31[indexC  ];
  f2 =  sinTable_q31[indexC+1];
  d1 = -sinTable_q31[indexS  ];
  d2 = -sinTable_q31[indexS+1];

  Dn = 0x1921FB5;                                                                                   
  Df = f2 - f1;                                                  

  temp = Dn * ((q63_t)d1 + d2);
  temp = temp - ((q63_t)Df << 32);
  temp = (q63_t)fract * (temp >> 31);
  temp = temp + ((3 * (q63_t)Df << 31) - (d2 + ((q63_t)d1 << 1)) * Dn);
  temp = (q63_t)fract * (temp >> 31);
  temp = temp + (q63_t)d1 * Dn;
  temp = (q63_t)fract * (temp >> 31);

                                   
  *pCosVal = clip_q63_to_q31((temp >> 31) + (q63_t)f1);

                                                                        
  f1 = sinTable_q31[indexS ];
  f2 = sinTable_q31[indexS+1];
  d1 = sinTable_q31[indexC ];
  d2 = sinTable_q31[indexC+1];

  Df = f2 - f1;                                             
  temp = Dn * ((q63_t)d1 + d2);
  temp = temp - ((q63_t)Df << 32);
  temp = (q63_t)fract * (temp >> 31);
  temp = temp + ((3 * (q63_t)Df << 31) - (d2 + ((q63_t)d1 << 1)) * Dn);
  temp = (q63_t)fract * (temp >> 31);
  temp = temp + (q63_t)d1 * Dn;
  temp = (q63_t)fract * (temp >> 31);

                                 
  *pSinVal = clip_q63_to_q31((temp >> 31) + (q63_t)f1);
}

   
                        
   
