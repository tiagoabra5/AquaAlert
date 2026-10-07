                                                                               
                         
                                                     
                   
                             
                                                                                
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

#if   defined ( __ICCARM__ )
  #pragma system_include                                                                
#elif defined (__clang__)
  #pragma clang system_header                                          
#endif

#ifndef TZ_CONTEXT_H
#define TZ_CONTEXT_H
 
#include <stdint.h>
 
#ifndef TZ_MODULEID_T
#define TZ_MODULEID_T
                                                                                   
typedef uint32_t TZ_ModuleId_t;
#endif
 
                                                              
typedef uint32_t TZ_MemoryId_t;
  
                                           
                                                   
uint32_t TZ_InitContextSystem_S (void);
 
                                                                            
                                                                                
                                                          
                                                            
TZ_MemoryId_t TZ_AllocModuleContext_S (TZ_ModuleId_t module);
 
                                                                                       
                                                    
                                                   
uint32_t TZ_FreeModuleContext_S (TZ_MemoryId_t id);
 
                                                              
                                                    
                                                   
uint32_t TZ_LoadContext_S (TZ_MemoryId_t id);
 
                                                               
                                                    
                                                   
uint32_t TZ_StoreContext_S (TZ_MemoryId_t id);
 
#endif                 
