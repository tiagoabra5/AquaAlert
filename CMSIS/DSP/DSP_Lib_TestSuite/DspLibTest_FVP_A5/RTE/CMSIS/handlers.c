/*
 * Copyright (c) 2013-2017 ARM Limited. All rights reserved.
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
 * Project:     CMSIS-RTOS RTX
 * Title:       Exception handlers (C functions)
 *
 * -----------------------------------------------------------------------------
 */
#include "RTE_Components.h"
#include CMSIS_device_header


                                               
#define FSR_ALIGNMENT_FAULT                  0x01                                     
#define FSR_INSTRUCTION_CACHE_MAINTENANCE    0x04                               
#define FSR_SYNC_EXT_TTB_WALK_FIRST          0x0c                  
#define FSR_SYNC_EXT_TTB_WALK_SECOND         0x0e                  
#define FSR_SYNC_PARITY_TTB_WALK_FIRST       0x1c                  
#define FSR_SYNC_PARITY_TTB_WALK_SECOND      0x1e                  
#define FSR_TRANSLATION_FAULT_FIRST          0x05                         
#define FSR_TRANSLATION_FAULT_SECOND         0x07                         
#define FSR_ACCESS_FLAG_FAULT_FIRST          0x03                         
#define FSR_ACCESS_FLAG_FAULT_SECOND         0x06                         
#define FSR_DOMAIN_FAULT_FIRST               0x09                         
#define FSR_DOMAIN_FAULT_SECOND              0x0b                         
#define FSR_PERMISSION_FAULT_FIRST           0x0f                         
#define FSR_PERMISSION_FAULT_SECOND          0x0d                         
#define FSR_DEBUG_EVENT                      0x02             
#define FSR_SYNC_EXT_ABORT                   0x08                  
#define FSR_TLB_CONFLICT_ABORT               0x10                  
#define FSR_LOCKDOWN                         0x14             
#define FSR_COPROCESSOR_ABORT                0x1a             
#define FSR_SYNC_PARITY_ERROR                0x19                  
#define FSR_ASYNC_EXTERNAL_ABORT             0x16                               
#define FSR_ASYNC_PARITY_ERROR               0x18                               

void CDAbtHandler(uint32_t DFSR, uint32_t DFAR, uint32_t LR) {
    uint32_t FS = (DFSR & (1 << 10)) >> 6 | (DFSR & 0x0f);                     

    switch(FS) {
                                           
        case FSR_SYNC_PARITY_ERROR:
        case FSR_SYNC_PARITY_TTB_WALK_FIRST:
        case FSR_SYNC_PARITY_TTB_WALK_SECOND:
            return;

                                                                           
        case FSR_ALIGNMENT_FAULT:
        case FSR_INSTRUCTION_CACHE_MAINTENANCE:
        case FSR_SYNC_EXT_TTB_WALK_FIRST:
        case FSR_SYNC_EXT_TTB_WALK_SECOND:
        case FSR_TRANSLATION_FAULT_FIRST:
        case FSR_TRANSLATION_FAULT_SECOND:
        case FSR_ACCESS_FLAG_FAULT_FIRST:
        case FSR_ACCESS_FLAG_FAULT_SECOND:
        case FSR_DOMAIN_FAULT_FIRST:
        case FSR_DOMAIN_FAULT_SECOND:
        case FSR_PERMISSION_FAULT_FIRST:
        case FSR_PERMISSION_FAULT_SECOND:
        case FSR_DEBUG_EVENT:
        case FSR_SYNC_EXT_ABORT:
        case FSR_TLB_CONFLICT_ABORT:
        case FSR_LOCKDOWN:
        case FSR_COPROCESSOR_ABORT:
        case FSR_ASYNC_EXTERNAL_ABORT:               
        case FSR_ASYNC_PARITY_ERROR:                 
        default:
            while(1);
    }
}

void CPAbtHandler(uint32_t IFSR, uint32_t IFAR, uint32_t LR) {
    uint32_t FS = (IFSR & (1 << 10)) >> 6 | (IFSR & 0x0f);                     

    switch(FS) {
                                           
        case FSR_SYNC_PARITY_ERROR:
        case FSR_SYNC_PARITY_TTB_WALK_FIRST:
        case FSR_SYNC_PARITY_TTB_WALK_SECOND:
            return;

                                                                           
        case FSR_SYNC_EXT_TTB_WALK_FIRST:
        case FSR_SYNC_EXT_TTB_WALK_SECOND:
        case FSR_TRANSLATION_FAULT_FIRST:
        case FSR_TRANSLATION_FAULT_SECOND:
        case FSR_ACCESS_FLAG_FAULT_FIRST:
        case FSR_ACCESS_FLAG_FAULT_SECOND:
        case FSR_DOMAIN_FAULT_FIRST:
        case FSR_DOMAIN_FAULT_SECOND:
        case FSR_PERMISSION_FAULT_FIRST:
        case FSR_PERMISSION_FAULT_SECOND:
        case FSR_DEBUG_EVENT:               
        case FSR_SYNC_EXT_ABORT:
        case FSR_TLB_CONFLICT_ABORT:
        case FSR_LOCKDOWN:
        case FSR_COPROCESSOR_ABORT:
        default:
            while(1);
    }
}


                                   
                                                                                               
                                                                                                                
                                                                                                                
uint32_t CUndefHandler(uint32_t opcode, uint32_t state, uint32_t LR) {
    const int THUMB = 2;
    const int ARM = 4;
                                                

                                                              
                                                                       
                                                                          
                                                                                 
    if ((state == ARM   && ((opcode & 0x0C000000) >> 26 == 0x03)) ||
        (state == THUMB && ((opcode & 0xEC000000) >> 26 == 0x3B))) {
        if (((opcode & 0x00000E00) >> 9) == 5) {
            __FPU_Enable();
            return state;
        }
    }

                                                               
    if ((state == ARM   && ((opcode & 0xFE000000) >> 24 == 0xF2)) ||
        (state == THUMB && ((opcode & 0xEF000000) >> 24 == 0xEF)) ||
                                                          
        (state == ARM   && ((opcode >> 24) == 0xF4)) ||
        (state == THUMB && ((opcode >> 24) == 0xF9))) {
            __FPU_Enable();
            return state;
    }

                                         
    while(1);
}
