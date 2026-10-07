/*
 * Copyright (c) 2013-2019 Arm Limited. All rights reserved.
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
 * -----------------------------------------------------------------------------
 *
 * $Revision:   V5.5.0
 *
 * Project:     CMSIS-RTOS RTX
 * Title:       RTX Configuration definitions
 *
 * -----------------------------------------------------------------------------
 */
 
#ifndef RTX_CONFIG_H_
#define RTX_CONFIG_H_
 
#ifdef   _RTE_
#include "RTE_Components.h"
#ifdef    RTE_RTX_CONFIG_H
#include  RTE_RTX_CONFIG_H
#endif
#endif
 
                                                                                
 
                          
                          
 
                                                           
                                                         
                      
#ifndef OS_DYNAMIC_MEM_SIZE
#define OS_DYNAMIC_MEM_SIZE         4096
#endif
 
                                              
                                                        
                                 
#ifndef OS_TICK_FREQ
#define OS_TICK_FREQ                1000
#endif
 
                                    
                                              
#ifndef OS_ROBIN_ENABLE
#define OS_ROBIN_ENABLE             1
#endif
 
                                      
                                                                               
                     
#ifndef OS_ROBIN_TIMEOUT
#define OS_ROBIN_TIMEOUT            5
#endif
 
         
 
                       
                                                                                   
                                                                                   
                                                                                   
                                                                      
                            
#ifndef OS_ISR_FIFO_QUEUE
#define OS_ISR_FIFO_QUEUE           16
#endif
 
                                    
                                                                            
#ifndef OS_OBJ_MEM_USAGE
#define OS_OBJ_MEM_USAGE            0
#endif
 
       
 
                          
                          
 
                                         
                                                   
#ifndef OS_THREAD_OBJ_MEM
#define OS_THREAD_OBJ_MEM           0
#endif
 
                                         
                                                                                      
                                                                                  
#ifndef OS_THREAD_NUM
#define OS_THREAD_NUM               1
#endif
 
                                                                 
                                                                          
                                                                  
#ifndef OS_THREAD_DEF_STACK_NUM
#define OS_THREAD_DEF_STACK_NUM     0
#endif
 
                                                                                                  
                                                                                          
                                                                                                      
                     
#ifndef OS_THREAD_USER_STACK_SIZE
#define OS_THREAD_USER_STACK_SIZE   0
#endif
 
         
 
                                                           
                                                                       
                     
#ifndef OS_STACK_SIZE
#define OS_STACK_SIZE               512
#endif
 
                                                        
                                            
                     
#ifndef OS_IDLE_THREAD_STACK_SIZE
#define OS_IDLE_THREAD_STACK_SIZE   512
#endif
 
                                               
                                                                
                                                         
                              
#ifndef OS_IDLE_THREAD_TZ_MOD_ID
#define OS_IDLE_THREAD_TZ_MOD_ID    0
#endif
 
                              
                                                      
                                                                                       
#ifndef OS_STACK_CHECK
#define OS_STACK_CHECK              1
#endif
 
                             
                                                                                   
                                                                                            
#ifndef OS_STACK_WATERMARK
#define OS_STACK_WATERMARK          0
#endif
 
                                            
                              
                           
                                 
#ifndef OS_PRIVILEGE_MODE
#define OS_PRIVILEGE_MODE           1
#endif
 
       
 
                         
                         
 
                                         
                                                   
#ifndef OS_TIMER_OBJ_MEM
#define OS_TIMER_OBJ_MEM            0
#endif
 
                                          
                                                                                 
                                                                             
#ifndef OS_TIMER_NUM
#define OS_TIMER_NUM                1
#endif
 
         
 
                             
                
                                                           
                 
                     
                                          
                      
#ifndef OS_TIMER_THREAD_PRIO
#define OS_TIMER_THREAD_PRIO        40
#endif
 
                                                        
                                             
                                                  
                     
#ifndef OS_TIMER_THREAD_STACK_SIZE
#define OS_TIMER_THREAD_STACK_SIZE  256
#endif
 
                                                
                                                                
                                                         
                              
#ifndef OS_TIMER_THREAD_TZ_MOD_ID
#define OS_TIMER_THREAD_TZ_MOD_ID   0
#endif
 
                                            
                                                              
                                                  
                   
#ifndef OS_TIMER_CB_QUEUE
#define OS_TIMER_CB_QUEUE           4
#endif
 
       
 
                               
                               
 
                                         
                                                   
#ifndef OS_EVFLAGS_OBJ_MEM
#define OS_EVFLAGS_OBJ_MEM          0
#endif
 
                                                
                                                                                 
                                                                             
#ifndef OS_EVFLAGS_NUM
#define OS_EVFLAGS_NUM              1
#endif
 
         
 
       
 
                         
                         
 
                                         
                                                   
#ifndef OS_MUTEX_OBJ_MEM
#define OS_MUTEX_OBJ_MEM            0
#endif
 
                                          
                                                                                 
                                                                             
#ifndef OS_MUTEX_NUM
#define OS_MUTEX_NUM                1
#endif
 
         
 
       
 
                             
                             
 
                                         
                                                   
#ifndef OS_SEMAPHORE_OBJ_MEM
#define OS_SEMAPHORE_OBJ_MEM        0
#endif
 
                                              
                                                                                 
                                                                             
#ifndef OS_SEMAPHORE_NUM
#define OS_SEMAPHORE_NUM            1
#endif
 
         
 
       
 
                               
                               
 
                                         
                                                   
#ifndef OS_MEMPOOL_OBJ_MEM
#define OS_MEMPOOL_OBJ_MEM          0
#endif
 
                                                
                                                                                 
                                                                             
#ifndef OS_MEMPOOL_NUM
#define OS_MEMPOOL_NUM              1
#endif
 
                                                           
                                                         
                                                                           
                     
#ifndef OS_MEMPOOL_DATA_SIZE
#define OS_MEMPOOL_DATA_SIZE        0
#endif
 
         
 
       
 
                                 
                                 
 
                                         
                                                   
#ifndef OS_MSGQUEUE_OBJ_MEM
#define OS_MSGQUEUE_OBJ_MEM         0
#endif
 
                                                  
                                                                                 
                                                                             
#ifndef OS_MSGQUEUE_NUM
#define OS_MSGQUEUE_NUM             1
#endif
 
                                                           
                                                         
                                                                           
                     
#ifndef OS_MSGQUEUE_DATA_SIZE
#define OS_MSGQUEUE_DATA_SIZE       0
#endif
 
         
 
       
 
                                  
                                  
 
                             
                                                               
#ifndef OS_EVR_INIT
#define OS_EVR_INIT                 0
#endif
 
                         
                                                      
#ifndef OS_EVR_START
#define OS_EVR_START                1
#endif
 
                                   
                                                             
                          
                                      
                              
                                       
           
#ifndef OS_EVR_LEVEL
#define OS_EVR_LEVEL                0x00U
#endif
 
                                 
                                               
                                                                                
 
                             
                                                          
                            
                                        
                                
                                         
             
#ifndef OS_EVR_MEMORY_LEVEL 
#define OS_EVR_MEMORY_LEVEL         0x01U
#endif
 
                  
                                               
                            
                                        
                                
                                         
             
#ifndef OS_EVR_KERNEL_LEVEL 
#define OS_EVR_KERNEL_LEVEL         0x01U
#endif
 
                  
                                               
                            
                                        
                                
                                         
             
#ifndef OS_EVR_THREAD_LEVEL 
#define OS_EVR_THREAD_LEVEL         0x05U
#endif
 
                        
                                                     
                            
                                        
                                
                                         
             
#ifndef OS_EVR_WAIT_LEVEL 
#define OS_EVR_WAIT_LEVEL           0x01U
#endif
 
                        
                                                     
                            
                                        
                                
                                         
             
#ifndef OS_EVR_THFLAGS_LEVEL 
#define OS_EVR_THFLAGS_LEVEL        0x01U
#endif
 
                       
                                                    
                            
                                        
                                
                                         
             
#ifndef OS_EVR_EVFLAGS_LEVEL 
#define OS_EVR_EVFLAGS_LEVEL        0x01U
#endif
 
                 
                                              
                            
                                        
                                
                                         
             
#ifndef OS_EVR_TIMER_LEVEL 
#define OS_EVR_TIMER_LEVEL          0x01U
#endif
 
                 
                                              
                            
                                        
                                
                                         
             
#ifndef OS_EVR_MUTEX_LEVEL 
#define OS_EVR_MUTEX_LEVEL          0x01U
#endif
 
                     
                                                  
                            
                                        
                                
                                         
             
#ifndef OS_EVR_SEMAPHORE_LEVEL 
#define OS_EVR_SEMAPHORE_LEVEL      0x01U
#endif
 
                       
                                                    
                            
                                        
                                
                                         
             
#ifndef OS_EVR_MEMPOOL_LEVEL 
#define OS_EVR_MEMPOOL_LEVEL        0x01U
#endif
 
                         
                                                      
                            
                                        
                                
                                         
             
#ifndef OS_EVR_MSGQUEUE_LEVEL 
#define OS_EVR_MSGQUEUE_LEVEL       0x01U
#endif
 
           
 
         
 
                             
                                                                                   
 
                           
                                                      
#ifndef OS_EVR_MEMORY
#define OS_EVR_MEMORY               1
#endif
 
                
                                           
#ifndef OS_EVR_KERNEL
#define OS_EVR_KERNEL               1
#endif
 
                
                                           
#ifndef OS_EVR_THREAD
#define OS_EVR_THREAD               1
#endif
 
                      
                                                 
#ifndef OS_EVR_WAIT
#define OS_EVR_WAIT                 1
#endif
 
                      
                                                 
#ifndef OS_EVR_THFLAGS
#define OS_EVR_THFLAGS              1
#endif
 
                     
                                                
#ifndef OS_EVR_EVFLAGS
#define OS_EVR_EVFLAGS              1
#endif
 
               
                                          
#ifndef OS_EVR_TIMER
#define OS_EVR_TIMER                1
#endif
 
               
                                          
#ifndef OS_EVR_MUTEX
#define OS_EVR_MUTEX                1
#endif
 
                   
                                              
#ifndef OS_EVR_SEMAPHORE
#define OS_EVR_SEMAPHORE            1
#endif
 
                     
                                                
#ifndef OS_EVR_MEMPOOL
#define OS_EVR_MEMPOOL              1
#endif
 
                       
                                                  
#ifndef OS_EVR_MSGQUEUE
#define OS_EVR_MSGQUEUE             1
#endif
 
         
 
       
 
                                                              
                                                        
#if (OS_THREAD_OBJ_MEM == 0)
#define OS_THREAD_LIBSPACE_NUM      4
#else
#define OS_THREAD_LIBSPACE_NUM      OS_THREAD_NUM
#endif
 
                                                                                
 
#endif                  
