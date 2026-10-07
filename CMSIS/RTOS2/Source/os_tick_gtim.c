                                                                               
                           
                                                           
                   
                              
                                                                                
/*
 * Copyright (c) 2017 ARM Limited. All rights reserved.
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

#include "os_tick.h"
#include "irq_ctrl.h"

#include "RTE_Components.h"
#include CMSIS_device_header

#ifndef GTIM_IRQ_PRIORITY
#define GTIM_IRQ_PRIORITY           0xFFU
#endif

#ifndef GTIM_IRQ_NUM
#define GTIM_IRQ_NUM                SecurePhyTimer_IRQn
#endif

                               
static uint8_t GTIM_PendIRQ;

                       
static uint32_t GTIM_Clock;

                   
static uint32_t GTIM_Load;

                 
int32_t OS_Tick_Setup (uint32_t freq, IRQHandler_t handler) {
  uint32_t prio, bits;

  if (freq == 0U) {
    return (-1);
  }

  GTIM_PendIRQ = 0U;

                    
#ifdef SCTR_BASE
  GTIM_Clock = *(uint32_t*)(SCTR_BASE+0x20);
#else
                                 
  GTIM_Clock = 100000000UL;
#endif

  PL1_SetCounterFrequency(GTIM_Clock);

                         
  GTIM_Load = (GTIM_Clock / freq) - 1U;

                                             
  PL1_SetControl(0U);
  PL1_SetLoadValue(GTIM_Load);

                              
  IRQ_Disable(GTIM_IRQ_NUM);
  IRQ_ClearPending(GTIM_IRQ_NUM);

                                                  
  IRQ_SetPriority(GTIM_IRQ_NUM, 0xFFU);

  prio = IRQ_GetPriority(GTIM_IRQ_NUM);

                                            
  if ((prio & 0xF0U) == 0U) {
    return (-1);
  }

  for (bits = 0; bits < 4; bits++) {
    if ((prio & 0x01) != 0) {
      break;
    }
    prio >>= 1;
  }
  
                                                                          
  prio = (GTIM_IRQ_PRIORITY << bits) & 0xFFUL;

                                         
  IRQ_SetPriority(GTIM_IRQ_NUM, prio-1U);

                           
  IRQ_SetMode(GTIM_IRQ_NUM, IRQ_MODE_TRIG_EDGE);

                                             
  IRQ_SetHandler(GTIM_IRQ_NUM, handler);

                                   
  IRQ_Enable(GTIM_IRQ_NUM);

                                            
#ifdef SCTR_BASE
  *(uint32_t*)SCTR_BASE |= 3U;
#endif

                         
  PL1_SetControl(1U);

  return (0);
}

                   
void OS_Tick_Enable (void) {
  uint32_t ctrl;

                                      
  if (GTIM_PendIRQ != 0U) {
    GTIM_PendIRQ = 0U;
    IRQ_SetPending (GTIM_IRQ_NUM);
  }

                            
  ctrl = PL1_GetControl();
                          
  ctrl |= 1U;
  PL1_SetControl(ctrl);
}

                    
void OS_Tick_Disable (void) {
  uint32_t ctrl;

                           
  ctrl = PL1_GetControl();
                            
  ctrl &= ~1U;
  PL1_SetControl(ctrl);

                                    
  if (IRQ_GetPending(GTIM_IRQ_NUM) != 0) {
    IRQ_ClearPending(GTIM_IRQ_NUM);
    GTIM_PendIRQ = 1U;
  }
}

                           
void OS_Tick_AcknowledgeIRQ (void) {
  IRQ_ClearPending (GTIM_IRQ_NUM);
  PL1_SetLoadValue(GTIM_Load);
}

                          
int32_t  OS_Tick_GetIRQn (void) {
  return (GTIM_IRQ_NUM);
}

                     
uint32_t OS_Tick_GetClock (void) {
  return (GTIM_Clock);
}

                        
uint32_t OS_Tick_GetInterval (void) {
  return (GTIM_Load + 1U);
}

                           
uint32_t OS_Tick_GetCount (void) {
  return (GTIM_Load - PL1_GetCurrentValue());
}

                               
uint32_t OS_Tick_GetOverflow (void) {
  CNTP_CTL_Type cntp_ctl;
  cntp_ctl.w = PL1_GetControl();
  return (cntp_ctl.b.ISTATUS);
}
