                                                                               
                           
                                                           
                   
                           
                                                                                
/*
 * Copyright (c) 2017-2018 Arm Limited. All rights reserved.
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

#if defined(PTIM)

#include "os_tick.h"
#include "irq_ctrl.h"

#ifndef PTIM_IRQ_PRIORITY
#define PTIM_IRQ_PRIORITY           0xFFU
#endif

static uint8_t PTIM_PendIRQ;                                       

                 
int32_t OS_Tick_Setup (uint32_t freq, IRQHandler_t handler) {
  uint32_t load;
  uint32_t prio;
  uint32_t bits;

  if (freq == 0U) {
    return (-1);
  }

  PTIM_PendIRQ = 0U;

                                                 
  load = (SystemCoreClock / freq) - 1U;

                                             
  PTIM_SetControl   (0U);
  PTIM_SetLoadValue (load);

                              
  IRQ_Disable     (PrivTimer_IRQn);
  IRQ_ClearPending(PrivTimer_IRQn);

                                                  
  IRQ_SetPriority (PrivTimer_IRQn, 0xFFU);

  prio = IRQ_GetPriority (PrivTimer_IRQn);

                                            
  if ((prio & 0xF0U) == 0U) {
    return (-1);
  }

  for (bits = 0; bits < 4; bits++) {
    if ((prio & 0x01) != 0) {
      break;
    }
    prio >>= 1;
  }

                                                                          
  prio = (PTIM_IRQ_PRIORITY << bits) & 0xFFUL;

                                         
  IRQ_SetPriority(PrivTimer_IRQn, prio-1U);

                           
  IRQ_SetMode(PrivTimer_IRQn, IRQ_MODE_TRIG_EDGE);

                                             
  IRQ_SetHandler(PrivTimer_IRQn, handler);

                                   
  IRQ_Enable (PrivTimer_IRQn);

                                         
  PTIM_SetControl (0x06U);

  return (0);
}

                   
void OS_Tick_Enable (void) {
  uint32_t ctrl;

                                      
  if (PTIM_PendIRQ != 0U) {
    PTIM_PendIRQ = 0U;
    IRQ_SetPending (PrivTimer_IRQn);
  }

                            
  ctrl  = PTIM_GetControl();
                          
  ctrl |= 1U;
  PTIM_SetControl (ctrl);
}

                    
void OS_Tick_Disable (void) {
  uint32_t ctrl;

                           
  ctrl  = PTIM_GetControl();
                            
  ctrl &= ~1U;
  PTIM_SetControl (ctrl);

                                    
  if (IRQ_GetPending(PrivTimer_IRQn) != 0) {
    IRQ_ClearPending (PrivTimer_IRQn);
    PTIM_PendIRQ = 1U;
  }
}

                           
void OS_Tick_AcknowledgeIRQ (void) {
  PTIM_ClearEventFlag();
}

                          
int32_t  OS_Tick_GetIRQn (void) {
  return (PrivTimer_IRQn);
}

                     
uint32_t OS_Tick_GetClock (void) {
  return (SystemCoreClock);
}

                        
uint32_t OS_Tick_GetInterval (void) {
  return (PTIM_GetLoadValue() + 1U);
}

                           
uint32_t OS_Tick_GetCount (void) {
  uint32_t load = PTIM_GetLoadValue();
  return  (load - PTIM_GetCurrentValue());
}

                               
uint32_t OS_Tick_GetOverflow (void) {
  return (PTIM->ISR & 1);
}

#endif         
