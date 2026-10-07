                                                                               
                            
                                                                            
                   
                              
  
        
  
                                                                                
/*
 * Copyright (c) 2009-2019 Arm Limited. All rights reserved.
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

#include "RTE_Components.h"
#include CMSIS_device_header
#include "irq_ctrl.h"

#define  SYSTEM_CLOCK  12000000U

                                                                              
                            
                                                                                
uint32_t SystemCoreClock = SYSTEM_CLOCK;

                                                                              
                                   
                                                                                
void SystemCoreClockUpdate (void)
{
  SystemCoreClock = SYSTEM_CLOCK;
}

                                                                              
                       
                                                                                
void SystemInit (void)
{
                                                                     
                                                                           

                                  
  __set_TLBIALL(0);

                                             
  __set_BPIALL(0);
  __DSB();
  __ISB();

                                                                
  __set_ICIALLU(0);
  __DSB();
  __ISB();

                           
  L1C_InvalidateDCacheAll();

#if ((__FPU_PRESENT == 1) && (__FPU_USED == 1))
               
  __FPU_Enable();
#endif

                             
  MMU_CreateTranslationTable();

               
  MMU_Enable();

                  
  L1C_EnableCaches();
  L1C_EnableBTAC();

#if (__L2C_PRESENT == 1) 
               
  L2C_Enable();
#endif

                   
  IRQ_Initialize();
}
