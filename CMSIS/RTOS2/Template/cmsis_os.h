/*
 * Copyright (c) 2013-2018 Arm Limited. All rights reserved.
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
 *
 * ----------------------------------------------------------------------
 *
 * $Date:        18. June 2018
 * $Revision:    V2.1.3
 *
 * Project:      CMSIS-RTOS API
 * Title:        cmsis_os.h template header file
 *
 * Version 0.02
 *    Initial Proposal Phase
 * Version 0.03
 *    osKernelStart added, optional feature: main started as thread
 *    osSemaphores have standard behavior
 *    osTimerCreate does not start the timer, added osTimerStart
 *    osThreadPass is renamed to osThreadYield
 * Version 1.01
 *    Support for C++ interface
 *     - const attribute removed from the osXxxxDef_t typedefs
 *     - const attribute added to the osXxxxDef macros
 *    Added: osTimerDelete, osMutexDelete, osSemaphoreDelete
 *    Added: osKernelInitialize
 * Version 1.02
 *    Control functions for short timeouts in microsecond resolution:
 *    Added: osKernelSysTick, osKernelSysTickFrequency, osKernelSysTickMicroSec
 *    Removed: osSignalGet 
 * Version 2.0.0
 *    OS objects creation without macros (dynamic creation and resource allocation):
 *     - added: osXxxxNew functions which replace osXxxxCreate
 *     - added: osXxxxAttr_t structures
 *     - deprecated: osXxxxCreate functions, osXxxxDef_t structures
 *     - deprecated: osXxxxDef and osXxxx macros
 *    osStatus codes simplified and renamed to osStatus_t
 *    osEvent return structure deprecated
 *    Kernel:
 *     - added: osKernelInfo_t and osKernelGetInfo
 *     - added: osKernelState_t and osKernelGetState (replaces osKernelRunning)
 *     - added: osKernelLock, osKernelUnlock
 *     - added: osKernelSuspend, osKernelResume
 *     - added: osKernelGetTickCount, osKernelGetTickFreq
 *     - renamed osKernelSysTick to osKernelGetSysTimerCount
 *     - replaced osKernelSysTickFrequency with osKernelGetSysTimerFreq
 *     - deprecated osKernelSysTickMicroSec
 *    Thread:
 *     - extended number of thread priorities
 *     - renamed osPrioriry to osPrioriry_t
 *     - replaced osThreadCreate with osThreadNew
 *     - added: osThreadGetName
 *     - added: osThreadState_t and osThreadGetState
 *     - added: osThreadGetStackSize, osThreadGetStackSpace
 *     - added: osThreadSuspend, osThreadResume
 *     - added: osThreadJoin, osThreadDetach, osThreadExit
 *     - added: osThreadGetCount, osThreadEnumerate
 *     - added: Thread Flags (moved from Signals) 
 *    Signals:
 *     - renamed osSignals to osThreadFlags (moved to Thread Flags)
 *     - changed return value of Set/Clear/Wait functions
 *     - Clear function limited to current running thread
 *     - extended Wait function (options)
 *     - added: osThreadFlagsGet
 *    Event Flags:
 *     - added new independent object for handling Event Flags
 *    Delay and Wait functions:
 *     - added: osDelayUntil
 *     - deprecated: osWait
 *    Timer:
 *     - replaced osTimerCreate with osTimerNew
 *     - added: osTimerGetName, osTimerIsRunning
 *    Mutex:
 *     - extended: attributes (Recursive, Priority Inherit, Robust)
 *     - replaced osMutexCreate with osMutexNew
 *     - renamed osMutexWait to osMutexAcquire
 *     - added: osMutexGetName, osMutexGetOwner
 *    Semaphore:
 *     - extended: maximum and initial token count
 *     - replaced osSemaphoreCreate with osSemaphoreNew
 *     - renamed osSemaphoreWait to osSemaphoreAcquire (changed return value)
 *     - added: osSemaphoreGetName, osSemaphoreGetCount
 *    Memory Pool:
 *     - using osMemoryPool prefix instead of osPool
 *     - replaced osPoolCreate with osMemoryPoolNew
 *     - extended osMemoryPoolAlloc (timeout)
 *     - added: osMemoryPoolGetName
 *     - added: osMemoryPoolGetCapacity, osMemoryPoolGetBlockSize
 *     - added: osMemoryPoolGetCount, osMemoryPoolGetSpace
 *     - added: osMemoryPoolDelete
 *     - deprecated: osPoolCAlloc
 *    Message Queue:
 *     - extended: fixed size message instead of a single 32-bit value
 *     - using osMessageQueue prefix instead of osMessage
 *     - replaced osMessageCreate with osMessageQueueNew
 *     - updated: osMessageQueuePut, osMessageQueueGet
 *     - added: osMessageQueueGetName
 *     - added: osMessageQueueGetCapacity, osMessageQueueGetMsgSize
 *     - added: osMessageQueueGetCount, osMessageQueueGetSpace
 *     - added: osMessageQueueReset, osMessageQueueDelete
 *    Mail Queue: 
 *     - deprecated (superseded by extended Message Queue functionality)
 * Version 2.1.0
 *    Support for critical and uncritical sections (nesting safe):
 *    - updated: osKernelLock, osKernelUnlock
 *    - added: osKernelRestoreLock
 *    Updated Thread and Event Flags:
 *    - changed flags parameter and return type from int32_t to uint32_t
 * Version 2.1.1
 *    Additional functions allowed to be called from Interrupt Service Routines:
 *    - osKernelGetTickCount, osKernelGetTickFreq
 *    Changed Kernel Tick type to uint32_t:
 *    - updated: osKernelGetTickCount, osDelayUntil
 * Version 2.1.2
 *    Additional functions allowed to be called from Interrupt Service Routines:
 *    - osKernelGetInfo, osKernelGetState
 * Version 2.1.3
 *    Additional functions allowed to be called from Interrupt Service Routines:
 *    - osThreadGetId
 *---------------------------------------------------------------------------*/
 
#ifndef CMSIS_OS_H_
#define CMSIS_OS_H_
 
                                                     
#define osCMSIS             0x20001U                                            
 
                                                                                                     
#define osCMSIS_KERNEL      0x10000U                                                                
 
                                                                                    
#define osKernelSystemId "KERNEL V1.0"                                 
 
                                                                    
#define osFeature_MainThread  0                                                                    
#define osFeature_Signals     16U                                                               
#define osFeature_Semaphore   65535U                                                          
#define osFeature_Wait        0                                                           
#define osFeature_SysTick     1                                                                     
#define osFeature_Pool        1                                                           
#define osFeature_MessageQ    1                                                           
#define osFeature_MailQ       1                                                           
 
#if (osCMSIS >= 0x20000U)
#include "cmsis_os2.h"
#else
#include <stdint.h>
#include <stddef.h>
#endif
 
#ifdef  __cplusplus
extern "C"
{
#endif
 
 
                                              
 
                    
#if (osCMSIS < 0x20000U)
typedef enum {
  osPriorityIdle          = -3,                                     
  osPriorityLow           = -2,                           
  osPriorityBelowNormal   = -1,                                    
  osPriorityNormal        =  0,                                        
  osPriorityAboveNormal   = +1,                                    
  osPriorityHigh          = +2,                            
  osPriorityRealtime      = +3,                                          
  osPriorityError         = 0x84,                                                                 
  osPriorityReserved      = 0x7FFFFFFF                                                     
} osPriority;
#else
#define osPriority osPriority_t
#endif

                            
typedef void (*os_pthread) (void const *argument);
 
                                              
typedef void (*os_ptimer) (void const *argument);
 
               
#if (osCMSIS < 0x20000U)
typedef enum {
  osTimerOnce             = 0,                              
  osTimerPeriodic         = 1                                
} os_timer_type;
#else
#define os_timer_type osTimerType_t
#endif
 
                  
#define osWaitForever       0xFFFFFFFFU                                 
 
                                                        
#if (osCMSIS < 0x20000U)
typedef enum {
  osOK                    =    0,                                                           
  osEventSignal           = 0x08,                                                      
  osEventMessage          = 0x10,                                                       
  osEventMail             = 0x20,                                                    
  osEventTimeout          = 0x40,                                                 
  osErrorParameter        = 0x80,                                                                                                
  osErrorResource         = 0x81,                                                                           
  osErrorTimeoutResource  = 0xC1,                                                                                                                       
  osErrorISR              = 0x82,                                                                                                      
  osErrorISRRecursive     = 0x83,                                                                     
  osErrorPriority         = 0x84,                                                                            
  osErrorNoMemory         = 0x85,                                                                                                       
  osErrorValue            = 0x86,                                                 
  osErrorOS               = 0xFF,                                                                                   
  osStatusReserved        = 0x7FFFFFFF                                                     
} osStatus;
#else
typedef int32_t                  osStatus;
#define osEventSignal           (0x08)
#define osEventMessage          (0x10)
#define osEventMail             (0x20)
#define osEventTimeout          (0x40)
#define osErrorOS               osError
#define osErrorTimeoutResource  osErrorTimeout
#define osErrorISRRecursive     (-126)
#define osErrorValue            (-127)
#define osErrorPriority         (-128)
#endif
 
 
                                                                                 
 
                                    
                                                                         
#if (osCMSIS < 0x20000U)
typedef void *osThreadId;
#else
#define osThreadId osThreadId_t
#endif
 
                                  
                                                                         
#if (osCMSIS < 0x20000U)
typedef void *osTimerId;
#else
#define osTimerId osTimerId_t
#endif
 
                                  
                                                                         
#if (osCMSIS < 0x20000U)
typedef void *osMutexId;
#else
#define osMutexId osMutexId_t
#endif
 
                                          
                                                                         
#if (osCMSIS < 0x20000U)
typedef void *osSemaphoreId;
#else
#define osSemaphoreId osSemaphoreId_t
#endif
 
                                       
                                                                         
typedef void *osPoolId;
 
                                            
                                                                         
typedef void *osMessageQId;
 
                                      
                                                                         
typedef void *osMailQId;
 
 
                                                                         
                                                                                          
#if (osCMSIS < 0x20000U)
typedef struct os_thread_def {
  os_pthread                 pthread;                                        
  osPriority               tpriority;                               
  uint32_t                 instances;                                                           
  uint32_t                 stacksize;                                                                 
} osThreadDef_t;
#else
typedef struct os_thread_def {
  os_pthread                 pthread;                                        
  osThreadAttr_t                attr;                         
} osThreadDef_t;
#endif
 
                                                         
                                                                                         
#if (osCMSIS < 0x20000U)
typedef struct os_timer_def {
  os_ptimer                   ptimer;                                         
} osTimerDef_t;
#else
typedef struct os_timer_def {
  os_ptimer                   ptimer;                                         
  osTimerAttr_t                 attr;                        
} osTimerDef_t;
#endif
 
                                                                      
                                                                                         
#if (osCMSIS < 0x20000U)
typedef struct os_mutex_def {
  uint32_t                     dummy;                   
} osMutexDef_t;
#else
#define osMutexDef_t osMutexAttr_t
#endif
 
                                                                              
                                                                                             
#if (osCMSIS < 0x20000U)
typedef struct os_semaphore_def {
  uint32_t                     dummy;                   
} osSemaphoreDef_t;
#else
#define osSemaphoreDef_t osSemaphoreAttr_t
#endif
 
                                                     
                                                                                        
#if (osCMSIS < 0x20000U)
typedef struct os_pool_def {
  uint32_t                   pool_sz;                                              
  uint32_t                   item_sz;                       
  void                         *pool;                                  
} osPoolDef_t;
#else
typedef struct os_pool_def {
  uint32_t                   pool_sz;                                              
  uint32_t                   item_sz;                       
  osMemoryPoolAttr_t            attr;                              
} osPoolDef_t;
#endif
 
                                           
                                                                                            
#if (osCMSIS < 0x20000U)
typedef struct os_messageQ_def {
  uint32_t                  queue_sz;                                       
  void                         *pool;                                 
} osMessageQDef_t;
#else
typedef struct os_messageQ_def {
  uint32_t                  queue_sz;                                       
  osMessageQueueAttr_t          attr;                                
} osMessageQDef_t;
#endif
 
                                        
                                                                                         
#if (osCMSIS < 0x20000U)
typedef struct os_mailQ_def {
  uint32_t                  queue_sz;                                       
  uint32_t                   item_sz;                       
  void                         *pool;                             
} osMailQDef_t;
#else
typedef struct os_mailQ_def {
  uint32_t                  queue_sz;                                       
  uint32_t                   item_sz;                       
  void                         *mail;                       
  osMemoryPoolAttr_t         mp_attr;                              
  osMessageQueueAttr_t       mq_attr;                                
} osMailQDef_t;
#endif
 
 
                                                                 
typedef struct {
  osStatus                    status;                                               
  union {
    uint32_t                       v;                               
    void                          *p;                                       
    int32_t                  signals;                    
  } value;                                              
  union {
    osMailQId                mail_id;                                             
    osMessageQId          message_id;                                                   
  } def;                                                     
} osEvent;
 
 
                                         
 
                                                    
                                                                            
#if (osCMSIS < 0x20000U)
osStatus osKernelInitialize (void);
#endif
 
                                    
                                                                            
#if (osCMSIS < 0x20000U)
osStatus osKernelStart (void);
#endif
 
                                                
                                                     
#if (osCMSIS < 0x20000U)
int32_t osKernelRunning(void);
#endif
 
#if (defined(osFeature_SysTick) && (osFeature_SysTick != 0))                           
 
                                             
                                                     
#if (osCMSIS < 0x20000U)
uint32_t osKernelSysTick (void);
#else
#define  osKernelSysTick osKernelGetSysTimerCount
#endif
 
                                                 
                                                                                             
#if (osCMSIS < 0x20000U)
#define osKernelSysTickFrequency 100000000
#endif
 
                                                                     
                                                           
                                                                      
#if (osCMSIS < 0x20000U)
#define osKernelSysTickMicroSec(microsec) (((uint64_t)microsec * (osKernelSysTickFrequency)) / 1000000)
#else
#define osKernelSysTickMicroSec(microsec) (((uint64_t)microsec *  osKernelGetSysTimerFreq()) / 1000000)
#endif
 
#endif                           
 
 
                                         
 
                                                                               
                                                             
                                                                         
                                                                     
                                                                                            
                                                                                      
                                                                    
#if defined (osObjectsExternal)                       
#define osThreadDef(name, priority, instances, stacksz) \
extern const osThreadDef_t os_thread_def_##name
#else                                                
#if (osCMSIS < 0x20000U)
#define osThreadDef(name, priority, instances, stacksz) \
const osThreadDef_t os_thread_def_##name = \
{ (name), (priority), (instances), (stacksz) }
#else
#define osThreadDef(name, priority, instances, stacksz) \
const osThreadDef_t os_thread_def_##name = \
{ (name), \
  { NULL, osThreadDetached, NULL, 0U, NULL, 8*((stacksz+7)/8), (priority), 0U, 0U } }
#endif
#endif
 
                               
                                                                      
                                                                                  
                                                                    
#define osThread(name) \
&os_thread_def_##name
 
                                                                           
                                                                                 
                                                                                                 
                                                                                
osThreadId osThreadCreate (const osThreadDef_t *thread_def, void *argument);
 
                                                       
                                                                                
#if (osCMSIS < 0x20000U)
osThreadId osThreadGetId (void);
#endif
 
                                
                                                                                                 
                                                                            
                                                                            
#if (osCMSIS < 0x20000U)
osStatus osThreadSetPriority (osThreadId thread_id, osPriority priority);
#endif
 
                                     
                                                                                                 
                                                           
#if (osCMSIS < 0x20000U)
osPriority osThreadGetPriority (osThreadId thread_id);
#endif
 
                                                          
                                                                            
#if (osCMSIS < 0x20000U)
osStatus osThreadYield (void);
#endif
 
                                    
                                                                                                 
                                                                            
#if (osCMSIS < 0x20000U)
osStatus osThreadTerminate (osThreadId thread_id);
#endif
 
 
                               
 
                                                       
                                                                                                 
                                                                                             
                                                                                                        
int32_t osSignalSet (osThreadId thread_id, int32_t signals);
 
                                                         
                                                                                                 
                                                                                                
                                                                                                                         
int32_t osSignalClear (osThreadId thread_id, int32_t signals);
 
                                                                                           
                                                                                                           
                                                                                          
                                                 
osEvent osSignalWait (int32_t signals, uint32_t millisec);
 
 
                                    
 
                                  
                                                                                
                                                                            
#if (osCMSIS < 0x20000U)
osStatus osDelay (uint32_t millisec);
#endif
 
#if (defined (osFeature_Wait) && (osFeature_Wait != 0))                           
 
                                               
                                                                                         
                                                                                   
osEvent osWait (uint32_t millisec);
 
#endif                           
 
 
                                        
 
                          
                                                          
                                                                      
                                                                                    
                                                                    
#if defined (osObjectsExternal)                       
#define osTimerDef(name, function) \
extern const osTimerDef_t os_timer_def_##name
#else                                                
#if (osCMSIS < 0x20000U)
#define osTimerDef(name, function) \
const osTimerDef_t os_timer_def_##name = { (function) }
#else
#define osTimerDef(name, function) \
const osTimerDef_t os_timer_def_##name = \
{ (function), { NULL, 0U, NULL, 0U } }
#endif
#endif
 
                              
                                                          
                                                                                 
                                                                    
#define osTimer(name) \
&os_timer_def_##name
 
                                  
                                                                           
                                                                                                   
                                                                          
                                                                               
osTimerId osTimerCreate (const osTimerDef_t *timer_def, os_timer_type type, void *argument);
 
                             
                                                                         
                                                                                              
                                                                            
#if (osCMSIS < 0x20000U)
osStatus osTimerStart (osTimerId timer_id, uint32_t millisec);
#endif
 
                 
                                                                         
                                                                            
#if (osCMSIS < 0x20000U)
osStatus osTimerStop (osTimerId timer_id);
#endif
 
                   
                                                                         
                                                                            
#if (osCMSIS < 0x20000U)
osStatus osTimerDelete (osTimerId timer_id);
#endif
 
 
                                        
 
                   
                                                          
                                                                                    
                                                                    
#if defined (osObjectsExternal)                       
#define osMutexDef(name) \
extern const osMutexDef_t os_mutex_def_##name
#else                                                
#if (osCMSIS < 0x20000U)
#define osMutexDef(name) \
const osMutexDef_t os_mutex_def_##name = { 0 }
#else
#define osMutexDef(name) \
const osMutexDef_t os_mutex_def_##name = \
{ NULL, osMutexRecursive | osMutexPrioInherit | osMutexRobust, NULL, 0U }
#endif
#endif
 
                              
                                                          
                                                                                 
                                                                    
#define osMutex(name) \
&os_mutex_def_##name
 
                                         
                                                                               
                                                                               
osMutexId osMutexCreate (const osMutexDef_t *mutex_def);
 
                                         
                                                                         
                                                                                          
                                                                            
#if (osCMSIS < 0x20000U)
osStatus osMutexWait (osMutexId mutex_id, uint32_t millisec);
#else
#define  osMutexWait osMutexAcquire
#endif
 
                                                          
                                                                         
                                                                            
#if (osCMSIS < 0x20000U)
osStatus osMutexRelease (osMutexId mutex_id);
#endif
 
                          
                                                                         
                                                                            
#if (osCMSIS < 0x20000U)
osStatus osMutexDelete (osMutexId mutex_id);
#endif
 
 
                                            
 
#if (defined (osFeature_Semaphore) && (osFeature_Semaphore != 0U))                        
 
                              
                                                              
                                                                                        
                                                                    
#if defined (osObjectsExternal)                       
#define osSemaphoreDef(name) \
extern const osSemaphoreDef_t os_semaphore_def_##name
#else                                                
#if (osCMSIS < 0x20000U)
#define osSemaphoreDef(name) \
const osSemaphoreDef_t os_semaphore_def_##name = { 0 }
#else
#define osSemaphoreDef(name) \
const osSemaphoreDef_t os_semaphore_def_##name = \
{ NULL, 0U, NULL, 0U }
#endif
#endif
 
                                  
                                                              
                                                                                     
                                                                    
#define osSemaphore(name) \
&os_semaphore_def_##name
 
                                             
                                                                                       
                                                                                
                                                                                   
osSemaphoreId osSemaphoreCreate (const osSemaphoreDef_t *semaphore_def, int32_t count);
 
                                                   
                                                                                         
                                                                                          
                                                                              
int32_t osSemaphoreWait (osSemaphoreId semaphore_id, uint32_t millisec);
 
                              
                                                                                         
                                                                            
#if (osCMSIS < 0x20000U)
osStatus osSemaphoreRelease (osSemaphoreId semaphore_id);
#endif
 
                              
                                                                                         
                                                                            
#if (osCMSIS < 0x20000U)
osStatus osSemaphoreDelete (osSemaphoreId semaphore_id);
#endif
 
#endif                        
 
 
                                              
 
#if (defined(osFeature_Pool) && (osFeature_Pool != 0))                          
 
                                
                                                         
                                                                                       
                                                                      
                                                                                   
                                                                    
#if defined (osObjectsExternal)                       
#define osPoolDef(name, no, type) \
extern const osPoolDef_t os_pool_def_##name
#else                                                
#if (osCMSIS < 0x20000U)
#define osPoolDef(name, no, type) \
const osPoolDef_t os_pool_def_##name = \
{ (no), sizeof(type), NULL }
#else
#define osPoolDef(name, no, type) \
const osPoolDef_t os_pool_def_##name = \
{ (no), sizeof(type), { NULL, 0U, NULL, 0U, NULL, 0U } }
#endif
#endif
 
                                           
                                                        
                                                                                
                                                                    
#define osPool(name) \
&os_pool_def_##name
 
                                               
                                                                                    
                                                                                     
osPoolId osPoolCreate (const osPoolDef_t *pool_def);
 
                                               
                                                                                         
                                                                                         
void *osPoolAlloc (osPoolId pool_id);
 
                                                                            
                                                                                         
                                                                                         
void *osPoolCAlloc (osPoolId pool_id);
 
                                                           
                                                                                         
                                                                                                         
                                                                            
osStatus osPoolFree (osPoolId pool_id, void *block);
 
#endif                          
 
 
                                                
 
#if (defined(osFeature_MessageQ) && (osFeature_MessageQ != 0))                            
  
                                             
                                                   
                                                                         
                                                                                      
                                                                                       
                                                                    
#if defined (osObjectsExternal)                       
#define osMessageQDef(name, queue_sz, type) \
extern const osMessageQDef_t os_messageQ_def_##name
#else                                                
#if (osCMSIS < 0x20000U)
#define osMessageQDef(name, queue_sz, type) \
const osMessageQDef_t os_messageQ_def_##name = \
{ (queue_sz), NULL }
#else
#define osMessageQDef(name, queue_sz, type) \
const osMessageQDef_t os_messageQ_def_##name = \
{ (queue_sz), { NULL, 0U, NULL, 0U, NULL, 0U } }
#endif
#endif
 
                                             
                                                  
                                                                                    
                                                                    
#define osMessageQ(name) \
&os_messageQ_def_##name
 
                                                 
                                                                                          
                                                                                                           
                                                                                       
osMessageQId osMessageCreate (const osMessageQDef_t *queue_def, osThreadId thread_id);
 
                             
                                                                                     
                                                     
                                                                                          
                                                                            
osStatus osMessagePut (osMessageQId queue_id, uint32_t info, uint32_t millisec);
 
                                                            
                                                                                     
                                                                                          
                                                        
osEvent osMessageGet (osMessageQId queue_id, uint32_t millisec);
 
#endif                            
 
 
                                             
 
#if (defined(osFeature_MailQ) && (osFeature_MailQ != 0))                         
 
                                          
                                                   
                                                                      
                                                                    
                                                                                    
                                                                    
#if defined (osObjectsExternal)                       
#define osMailQDef(name, queue_sz, type) \
extern const osMailQDef_t os_mailQ_def_##name
#else                                                
#if (osCMSIS < 0x20000U)
#define osMailQDef(name, queue_sz, type) \
const osMailQDef_t os_mailQ_def_##name = \
{ (queue_sz), sizeof(type), NULL }
#else
#define osMailQDef(name, queue_sz, type) \
static void *os_mail_p_##name[2]; \
const osMailQDef_t os_mailQ_def_##name = \
{ (queue_sz), sizeof(type), (&os_mail_p_##name), \
  { NULL, 0U, NULL, 0U, NULL, 0U }, \
  { NULL, 0U, NULL, 0U, NULL, 0U } }
#endif
#endif
 
                                          
                                                  
                                                                                 
                                                                    
#define osMailQ(name) \
&os_mailQ_def_##name
 
                                              
                                                                                    
                                                                                                           
                                                                                    
osMailQId osMailCreate (const osMailQDef_t *queue_def, osThreadId thread_id);
 
                                                             
                                                                               
                                                                                         
                                                                                          
void *osMailAlloc (osMailQId queue_id, uint32_t millisec);
 
                                                                                          
                                                                               
                                                                                         
                                                                                          
void *osMailCAlloc (osMailQId queue_id, uint32_t millisec);
 
                            
                                                                               
                                                                                 
                                                                            
osStatus osMailPut (osMailQId queue_id, const void *mail);
 
                                                         
                                                                               
                                                                                          
                                                        
osEvent osMailGet (osMailQId queue_id, uint32_t millisec);
 
                                                              
                                                                               
                                                                                               
                                                                            
osStatus osMailFree (osMailQId queue_id, void *mail);
 
#endif                         
 
 
#ifdef  __cplusplus
}
#endif
 
#endif                
