/* ----------------------------------------------------------------------
 * $Date:        5. February 2013
 * $Revision:    V1.02
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
 *     - const attribute removed from the osXxxxDef_t typedef's
 *     - const attribute added to the osXxxxDef macros
 *    Added: osTimerDelete, osMutexDelete, osSemaphoreDelete
 *    Added: osKernelInitialize
 * Version 1.02
 *    Control functions for short timeouts in microsecond resolution:
 *    Added: osKernelSysTick, osKernelSysTickFrequency, osKernelSysTickMicroSec
 *    Removed: osSignalGet 
 *----------------------------------------------------------------------------
 *
 * Copyright (c) 2013-2017 ARM LIMITED
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
 *---------------------------------------------------------------------------*/
 
 
#ifndef _CMSIS_OS_H
#define _CMSIS_OS_H
 
                                                                                  
#define osCMSIS           0x10002                                                 
 
                                                                                                     
#define osCMSIS_KERNEL    0x10000	                                                                  
 
                                                                                             
#define osKernelSystemId "KERNEL V1.00"                                  
 
                                                                                          
#define osFeature_MainThread   1                                                                  
#define osFeature_Pool         1                                                         
#define osFeature_MailQ        1                                                         
#define osFeature_MessageQ     1                                                         
#define osFeature_Signals      8                                                               
#define osFeature_Semaphore    30                                                            
#define osFeature_Wait         1                                                         
#define osFeature_SysTick      1                                                                   
 
#include <stdint.h>
#include <stddef.h>
 
#ifdef  __cplusplus
extern "C"
{
#endif
 
 
                                             
 
                                     
                                                                                       
typedef enum  {
  osPriorityIdle          = -3,                                      
  osPriorityLow           = -2,                            
  osPriorityBelowNormal   = -1,                                     
  osPriorityNormal        =  0,                                         
  osPriorityAboveNormal   = +1,                                     
  osPriorityHigh          = +2,                             
  osPriorityRealtime      = +3,                                           
  osPriorityError         =  0x84                                                                            
} osPriority;
 
                  
                                                                                          
#define osWaitForever     0xFFFFFFFF                                    
 
                                                        
                                                                                     
typedef enum  {
  osOK                    =     0,                                                           
  osEventSignal           =  0x08,                                                      
  osEventMessage          =  0x10,                                                       
  osEventMail             =  0x20,                                                    
  osEventTimeout          =  0x40,                                                 
  osErrorParameter        =  0x80,                                                                                                
  osErrorResource         =  0x81,                                                                           
  osErrorTimeoutResource  =  0xC1,                                                                                                                       
  osErrorISR              =  0x82,                                                                                                      
  osErrorISRRecursive     =  0x83,                                                                     
  osErrorPriority         =  0x84,                                                                            
  osErrorNoMemory         =  0x85,                                                                                                       
  osErrorValue            =  0x86,                                                 
  osErrorOS               =  0xFF,                                                                                   
  os_status_reserved      =  0x7FFFFFFF                                                         
} osStatus;
 
 
                                              
                                                                                          
typedef enum  {
  osTimerOnce             =     0,                          
  osTimerPeriodic         =     1                            
} os_timer_type;
 
                            
                                                                                       
typedef void (*os_pthread) (void const *argument);
 
                                              
                                                                                      
typedef void (*os_ptimer) (void const *argument);
 
                                                                                    
 
                                                                        
                                                                                         
typedef struct os_thread_cb *osThreadId;
 
                                                                     
                                                                                        
typedef struct os_timer_cb *osTimerId;
 
                                                                     
                                                                                        
typedef struct os_mutex_cb *osMutexId;
 
                                                                                 
                                                                                            
typedef struct os_semaphore_cb *osSemaphoreId;
 
                                                                                
                                                                                       
typedef struct os_pool_cb *osPoolId;
 
                                                                                       
                                                                                           
typedef struct os_messageQ_cb *osMessageQId;
 
                                                                              
                                                                                        
typedef struct os_mailQ_cb *osMailQId;
 
 
                                                                         
                                                                                          
typedef struct os_thread_def  {
  os_pthread               pthread;                                         
  osPriority             tpriority;                                
  uint32_t               instances;                                                            
  uint32_t               stacksize;                                                                  
} osThreadDef_t;
 
                                                         
                                                                                         
typedef struct os_timer_def  {
  os_ptimer                 ptimer;                                          
} osTimerDef_t;
 
                                                                      
                                                                                         
typedef struct os_mutex_def  {
  uint32_t                   dummy;                     
} osMutexDef_t;
 
                                                                              
                                                                                             
typedef struct os_semaphore_def  {
  uint32_t                   dummy;                     
} osSemaphoreDef_t;
 
                                                     
                                                                                        
typedef struct os_pool_def  {
  uint32_t                 pool_sz;                                               
  uint32_t                 item_sz;                        
  void                       *pool;                                   
} osPoolDef_t;
 
                                           
                                                                                            
typedef struct os_messageQ_def  {
  uint32_t                queue_sz;                                        
  uint32_t                 item_sz;                        
  void                       *pool;                                  
} osMessageQDef_t;
 
                                        
                                                                                         
typedef struct os_mailQ_def  {
  uint32_t                queue_sz;                                        
  uint32_t                 item_sz;                        
  void                       *pool;                              
} osMailQDef_t;
 
                                                                 
                                                                                     
                                                        
typedef struct  {
  osStatus                 status;                                                 
  union  {
    uint32_t                    v;                                 
    void                       *p;                                         
    int32_t               signals;                      
  } value;                                             
  union  {
    osMailQId             mail_id;                                               
    osMessageQId       message_id;                                                     
  } def;                                                    
} osEvent;
 
 
                                      
 
                                                    
                                                                            
                                                                                               
osStatus osKernelInitialize (void);
 
                          
                                                                            
                                                                                          
osStatus osKernelStart (void);
 
                                                
                                                                                            
                                                     
int32_t osKernelRunning(void);
 
#if (defined (osFeature_SysTick)  &&  (osFeature_SysTick != 0))                              
 
                                             
                                                                                            
                                                     
uint32_t osKernelSysTick (void);
 
                                                
                                                                                             
#define osKernelSysTickFrequency 100000000
 
                                                                     
                                                           
                                                                      
#define osKernelSysTickMicroSec(microsec) (((uint64_t)microsec * (osKernelSysTickFrequency)) / 1000000)
 
#endif                             
 
                               
 
                                                                               
                                                            
                                                                        
                                                                    
                                                                                           
                                                                                      
                                                                    
#if defined (osObjectsExternal)                       
#define osThreadDef(name, priority, instances, stacksz)  \
extern const osThreadDef_t os_thread_def_##name
#else                                                
#define osThreadDef(name, priority, instances, stacksz)  \
const osThreadDef_t os_thread_def_##name = \
{ (name), (priority), (instances), (stacksz)  }
#endif
 
                               
                                                                      
                                                                                  
                                                                    
#define osThread(name)  \
&os_thread_def_##name
 
                                                                           
                                                                                 
                                                                                                 
                                                                                
                                                                                           
osThreadId osThreadCreate (const osThreadDef_t *thread_def, void *argument);
 
                                                       
                                                                                
                                                                                          
osThreadId osThreadGetId (void);
 
                                                                      
                                                                                               
                                                                            
                                                                                              
osStatus osThreadTerminate (osThreadId thread_id);
 
                                                          
                                                                            
                                                                                          
osStatus osThreadYield (void);
 
                                        
                                                                                                 
                                                                            
                                                                            
                                                                                                
osStatus osThreadSetPriority (osThreadId thread_id, osPriority priority);
 
                                             
                                                                                                 
                                                          
                                                                                                
osPriority osThreadGetPriority (osThreadId thread_id);
 
 
                                    
 
                                  
                                                                                
                                                                            
osStatus osDelay (uint32_t millisec);
 
#if (defined (osFeature_Wait)  &&  (osFeature_Wait != 0))                              
 
                                               
                                                                                         
                                                                                   
                                                                                   
osEvent osWait (uint32_t millisec);
 
#endif                           
 
 
                                        
                          
                                                          
                                                                      
                                                                                    
                                                                    
#if defined (osObjectsExternal)                       
#define osTimerDef(name, function)  \
extern const osTimerDef_t os_timer_def_##name
#else                                                
#define osTimerDef(name, function)  \
const osTimerDef_t os_timer_def_##name = \
{ (function) }
#endif
 
                              
                                                          
                                                                                 
                                                                    
#define osTimer(name) \
&os_timer_def_##name
 
                   
                                                                           
                                                                                                   
                                                                          
                                                                               
                                                                                          
osTimerId osTimerCreate (const osTimerDef_t *timer_def, os_timer_type type, void *argument);
 
                             
                                                                         
                                                                                              
                                                                            
                                                                                         
osStatus osTimerStart (osTimerId timer_id, uint32_t millisec);
 
                   
                                                                         
                                                                            
                                                                                        
osStatus osTimerStop (osTimerId timer_id);
 
                                                          
                                                                         
                                                                            
                                                                                          
osStatus osTimerDelete (osTimerId timer_id);
 
 
                               
 
                                                       
                                                                                                 
                                                                                             
                                                                                                        
                                                                                        
int32_t osSignalSet (osThreadId thread_id, int32_t signals);
 
                                                         
                                                                                                 
                                                                                                
                                                                                                                         
                                                                                          
int32_t osSignalClear (osThreadId thread_id, int32_t signals);
 
                                                                                           
                                                                                                           
                                                                                          
                                                 
                                                                                         
osEvent osSignalWait (int32_t signals, uint32_t millisec);
 
 
                              
 
                   
                                                          
                                                                                    
                                                                    
#if defined (osObjectsExternal)                       
#define osMutexDef(name)  \
extern const osMutexDef_t os_mutex_def_##name
#else                                                
#define osMutexDef(name)  \
const osMutexDef_t os_mutex_def_##name = { 0 }
#endif
 
                              
                                                          
                                                                                 
                                                                    
#define osMutex(name)  \
&os_mutex_def_##name
 
                                         
                                                                               
                                                                               
                                                                                          
osMutexId osMutexCreate (const osMutexDef_t *mutex_def);
 
                                         
                                                                         
                                                                                          
                                                                            
                                                                                        
osStatus osMutexWait (osMutexId mutex_id, uint32_t millisec);
 
                                                          
                                                                         
                                                                            
                                                                                           
osStatus osMutexRelease (osMutexId mutex_id);
 
                                                          
                                                                         
                                                                            
                                                                                          
osStatus osMutexDelete (osMutexId mutex_id);
 
 
                                            
 
#if (defined (osFeature_Semaphore)  &&  (osFeature_Semaphore != 0))                           
 
                              
                                                              
                                                                                        
                                                                    
#if defined (osObjectsExternal)                       
#define osSemaphoreDef(name)  \
extern const osSemaphoreDef_t os_semaphore_def_##name
#else                                                
#define osSemaphoreDef(name)  \
const osSemaphoreDef_t os_semaphore_def_##name = { 0 }
#endif
 
                                  
                                                              
                                                                                     
                                                                    
#define osSemaphore(name)  \
&os_semaphore_def_##name
 
                                                                         
                                                                                       
                                                               
                                                                                   
                                                                                              
osSemaphoreId osSemaphoreCreate (const osSemaphoreDef_t *semaphore_def, int32_t count);
 
                                                   
                                                                                         
                                                                                          
                                                                              
                                                                                            
int32_t osSemaphoreWait (osSemaphoreId semaphore_id, uint32_t millisec);
 
                              
                                                                                         
                                                                            
                                                                                               
osStatus osSemaphoreRelease (osSemaphoreId semaphore_id);
 
                                                                  
                                                                                         
                                                                            
                                                                                              
osStatus osSemaphoreDelete (osSemaphoreId semaphore_id);
 
#endif                           
 
 
                                              
 
#if (defined (osFeature_Pool)  &&  (osFeature_Pool != 0))                                     
 
                                
                                                         
                                                                                       
                                                                      
                                                                                   
                                                                    
#if defined (osObjectsExternal)                       
#define osPoolDef(name, no, type)   \
extern const osPoolDef_t os_pool_def_##name
#else                                                
#define osPoolDef(name, no, type)   \
const osPoolDef_t os_pool_def_##name = \
{ (no), sizeof(type), NULL }
#endif
 
                                           
                                                        
                                                                                
                                                                    
#define osPool(name) \
&os_pool_def_##name
 
                                        
                                                                                    
                                                                                     
                                                                                         
osPoolId osPoolCreate (const osPoolDef_t *pool_def);
 
                                               
                                                                                         
                                                                                         
                                                                                        
void *osPoolAlloc (osPoolId pool_id);
 
                                                                            
                                                                                         
                                                                                         
                                                                                         
void *osPoolCAlloc (osPoolId pool_id);
 
                                                                    
                                                                                         
                                                                                                           
                                                                            
                                                                                       
osStatus osPoolFree (osPoolId pool_id, void *block);
 
#endif                                      
 
 
                                                
 
#if (defined (osFeature_MessageQ)  &&  (osFeature_MessageQ != 0))                                
 
                                             
                                                   
                                                                         
                                                                                      
                                                                                       
                                                                    
#if defined (osObjectsExternal)                       
#define osMessageQDef(name, queue_sz, type)   \
extern const osMessageQDef_t os_messageQ_def_##name
#else                                                
#define osMessageQDef(name, queue_sz, type)   \
const osMessageQDef_t os_messageQ_def_##name = \
{ (queue_sz), sizeof (type)  }
#endif
 
                                             
                                                  
                                                                                    
                                                                    
#define osMessageQ(name) \
&os_messageQ_def_##name
 
                                          
                                                                                  
                                                                                                           
                                                                                       
                                                                                            
osMessageQId osMessageCreate (const osMessageQDef_t *queue_def, osThreadId thread_id);
 
                             
                                                                                     
                                                     
                                                                                          
                                                                            
                                                                                         
osStatus osMessagePut (osMessageQId queue_id, uint32_t info, uint32_t millisec);
 
                                                     
                                                                                     
                                                                                          
                                                        
                                                                                         
osEvent osMessageGet (osMessageQId queue_id, uint32_t millisec);
 
#endif                                
 
 
                                             
 
#if (defined (osFeature_MailQ)  &&  (osFeature_MailQ != 0))                             
 
                                          
                                                  
                                                                    
                                                                      
                                                                                    
                                                                    
#if defined (osObjectsExternal)                       
#define osMailQDef(name, queue_sz, type) \
extern const osMailQDef_t os_mailQ_def_##name
#else                                                
#define osMailQDef(name, queue_sz, type) \
const osMailQDef_t os_mailQ_def_##name =  \
{ (queue_sz), sizeof (type) }
#endif
 
                                          
                                                  
                                                                                 
                                                                    
#define osMailQ(name)  \
&os_mailQ_def_##name
 
                                     
                                                                                                
                                                                                                           
                                                                                    
                                                                                         
osMailQId osMailCreate (const osMailQDef_t *queue_def, osThreadId thread_id);
 
                                        
                                                                               
                                                                                         
                                                                                          
                                                                                        
void *osMailAlloc (osMailQId queue_id, uint32_t millisec);
 
                                                                     
                                                                               
                                                                                         
                                                                                          
                                                                                         
void *osMailCAlloc (osMailQId queue_id, uint32_t millisec);
 
                          
                                                                               
                                                                                                              
                                                                            
                                                                                      
osStatus osMailPut (osMailQId queue_id, void *mail);
 
                            
                                                                               
                                                                                         
                                                               
                                                                                      
osEvent osMailGet (osMailQId queue_id, uint32_t millisec);
 
                                    
                                                                               
                                                                                                   
                                                                            
                                                                                       
osStatus osMailFree (osMailQId queue_id, void *mail);
 
#endif                          
 
 
#ifdef  __cplusplus
}
#endif
 
#endif                
