                                                                               
                             
                                                                            
                  
                             
  
        
  
                                                                                
/*
 * Copyright (c) 2009-2018 Arm Limited. All rights reserved.
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

#include <ARMCA5.h>

                                                                              
             
                                                                                
#define USR_MODE 0x10                        
#define FIQ_MODE 0x11                                          
#define IRQ_MODE 0x12                                     
#define SVC_MODE 0x13                              
#define ABT_MODE 0x17                         
#define UND_MODE 0x1B                                         
#define SYS_MODE 0x1F                          

                                                                              
                     
                                                                                
void Vectors       (void) __attribute__ ((naked, section("RESET")));
void Reset_Handler (void) __attribute__ ((naked));

                                                                              
                               
                                                                                
void Undef_Handler (void) __attribute__ ((weak, alias("Default_Handler")));
void SVC_Handler   (void) __attribute__ ((weak, alias("Default_Handler")));
void PAbt_Handler  (void) __attribute__ ((weak, alias("Default_Handler")));
void DAbt_Handler  (void) __attribute__ ((weak, alias("Default_Handler")));
void IRQ_Handler   (void) __attribute__ ((weak, alias("Default_Handler")));
void FIQ_Handler   (void) __attribute__ ((weak, alias("Default_Handler")));

                                                                              
                                    
                                                                                
void Vectors(void) {
  __ASM volatile(
  "LDR    PC, =Reset_Handler                        \n"
  "LDR    PC, =Undef_Handler                        \n"
  "LDR    PC, =SVC_Handler                          \n"
  "LDR    PC, =PAbt_Handler                         \n"
  "LDR    PC, =DAbt_Handler                         \n"
  "NOP                                              \n"
  "LDR    PC, =IRQ_Handler                          \n"
  "LDR    PC, =FIQ_Handler                          \n"
  );
}

                                                                              
                                          
                                                                                
void Reset_Handler(void) {
  __ASM volatile(

                    
  "CPSID   if                                      \n"

                                        
  "MRC     p15, 0, R0, c0, c0, 5                   \n"               
  "ANDS    R0, R0, #3                              \n"
  "goToSleep:                                      \n"
  "WFINE                                           \n"
  "BNE     goToSleep                               \n"

                         
  "MRC     p15, 0, R0, c1, c0, 0                   \n"                                      
  "BIC     R0, R0, #(0x1 << 12)                    \n"                                      
  "BIC     R0, R0, #(0x1 <<  2)                    \n"                                      
  "BIC     R0, R0, #0x1                            \n"                                  
  "BIC     R0, R0, #(0x1 << 11)                    \n"                                                
  "BIC     R0, R0, #(0x1 << 13)                    \n"                                     
  "MCR     p15, 0, R0, c1, c0, 0                   \n"                                                     
  "ISB                                             \n"

                    
  "MRC     p15, 0, r0, c1, c0, 1                   \n"                                         
  "ORR     r0, r0, #(1 <<  1)                      \n"                                                
  "MCR     p15, 0, r0, c1, c0, 1                   \n"                                          

                                                                                        
  "LDR    R0, =Vectors                             \n"
  "MCR    p15, 0, R0, c12, c0, 0                   \n"

                                          
  "CPS    #0x11                                    \n"
  "LDR    SP, =Image$$FIQ_STACK$$ZI$$Limit         \n"
  "CPS    #0x12                                    \n"
  "LDR    SP, =Image$$IRQ_STACK$$ZI$$Limit         \n"
  "CPS    #0x13                                    \n"
  "LDR    SP, =Image$$SVC_STACK$$ZI$$Limit         \n"
  "CPS    #0x17                                    \n"
  "LDR    SP, =Image$$ABT_STACK$$ZI$$Limit         \n"
  "CPS    #0x1B                                    \n"
  "LDR    SP, =Image$$UND_STACK$$ZI$$Limit         \n"
  "CPS    #0x1F                                    \n"
  "LDR    SP, =Image$$ARM_LIB_STACK$$ZI$$Limit     \n"

                    
  "BL     SystemInit                               \n"

                      
  "CPSIE  if                                       \n"

                
  "BL     __main                                   \n"
  );
}

                                                                              
                                             
                                                                                
void Default_Handler(void) {
  while(1);
}
