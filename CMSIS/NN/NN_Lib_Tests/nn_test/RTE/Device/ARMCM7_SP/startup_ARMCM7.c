                                                                               
                             
                                               
                                 
                  
                           
                                                                                
/*
 * Copyright (c) 2009-2016 ARM Limited. All rights reserved.
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

#include <stdint.h>


                                                                              
                          
                                                                                
extern uint32_t __etext;
extern uint32_t __data_start__;
extern uint32_t __data_end__;
extern uint32_t __copy_table_start__;
extern uint32_t __copy_table_end__;
extern uint32_t __zero_table_start__;
extern uint32_t __zero_table_end__;
extern uint32_t __bss_start__;
extern uint32_t __bss_end__;
extern uint32_t __StackTop;

                                                                              
                                                  
                                                                                
typedef void( *pFunc )( void );


                                                                              
                     
                                                                                
#ifndef __START
extern void  _start(void) __attribute__((noreturn));                                          
#else
extern int  __START(void) __attribute__((noreturn));                          
#endif

#ifndef __NO_SYSTEM_INIT
extern void SystemInit (void);                                                  
#endif


                                                                              
                     
                                                                                
void Default_Handler(void);                                                     
void Reset_Handler(void);                                               


                                                                              
                           
                                                                                
#ifndef __STACK_SIZE
  #define	__STACK_SIZE  0x00000400
#endif
static uint8_t stack[__STACK_SIZE] __attribute__ ((aligned(8), used, section(".stack")));

#ifndef __HEAP_SIZE
  #define	__HEAP_SIZE   0x00000C00
#endif
#if __HEAP_SIZE > 0
static uint8_t heap[__HEAP_SIZE]   __attribute__ ((aligned(8), used, section(".heap")));
#endif


                                                                              
                               
                                                                                
                                    
void NMI_Handler         (void) __attribute__ ((weak, alias("Default_Handler")));
void HardFault_Handler   (void) __attribute__ ((weak, alias("Default_Handler")));
void MemManage_Handler   (void) __attribute__ ((weak, alias("Default_Handler")));
void BusFault_Handler    (void) __attribute__ ((weak, alias("Default_Handler")));
void UsageFault_Handler  (void) __attribute__ ((weak, alias("Default_Handler")));
void SVC_Handler         (void) __attribute__ ((weak, alias("Default_Handler")));
void DebugMon_Handler    (void) __attribute__ ((weak, alias("Default_Handler")));
void PendSV_Handler      (void) __attribute__ ((weak, alias("Default_Handler")));
void SysTick_Handler     (void) __attribute__ ((weak, alias("Default_Handler")));

                                
void WDT_IRQHandler      (void) __attribute__ ((weak, alias("Default_Handler")));
void RTC_IRQHandler      (void) __attribute__ ((weak, alias("Default_Handler")));
void TIM0_IRQHandler     (void) __attribute__ ((weak, alias("Default_Handler")));
void TIM2_IRQHandler     (void) __attribute__ ((weak, alias("Default_Handler")));
void MCIA_IRQHandler     (void) __attribute__ ((weak, alias("Default_Handler")));
void MCIB_IRQHandler     (void) __attribute__ ((weak, alias("Default_Handler")));
void UART0_IRQHandler    (void) __attribute__ ((weak, alias("Default_Handler")));
void UART1_IRQHandler    (void) __attribute__ ((weak, alias("Default_Handler")));
void UART2_IRQHandler    (void) __attribute__ ((weak, alias("Default_Handler")));
void UART4_IRQHandler    (void) __attribute__ ((weak, alias("Default_Handler")));
void AACI_IRQHandler     (void) __attribute__ ((weak, alias("Default_Handler")));
void CLCD_IRQHandler     (void) __attribute__ ((weak, alias("Default_Handler")));
void ENET_IRQHandler     (void) __attribute__ ((weak, alias("Default_Handler")));
void USBDC_IRQHandler    (void) __attribute__ ((weak, alias("Default_Handler")));
void USBHC_IRQHandler    (void) __attribute__ ((weak, alias("Default_Handler")));
void CHLCD_IRQHandler    (void) __attribute__ ((weak, alias("Default_Handler")));
void FLEXRAY_IRQHandler  (void) __attribute__ ((weak, alias("Default_Handler")));
void CAN_IRQHandler      (void) __attribute__ ((weak, alias("Default_Handler")));
void LIN_IRQHandler      (void) __attribute__ ((weak, alias("Default_Handler")));
void I2C_IRQHandler      (void) __attribute__ ((weak, alias("Default_Handler")));
void CPU_CLCD_IRQHandler (void) __attribute__ ((weak, alias("Default_Handler")));
void UART3_IRQHandler    (void) __attribute__ ((weak, alias("Default_Handler")));
void SPI_IRQHandler      (void) __attribute__ ((weak, alias("Default_Handler")));


                                                                              
                                    
                                                                                
const pFunc __Vectors[] __attribute__ ((section(".vectors"))) = {
                                    
  (pFunc)((uint32_t)&__StackTop),                                               
  Reset_Handler,                                                                
  NMI_Handler,                                                                  
  HardFault_Handler,                                                            
  MemManage_Handler,                                                            
  BusFault_Handler,                                                             
  UsageFault_Handler,                                                           
  0,                                                                            
  0,                                                                            
  0,                                                                            
  0,                                                                            
  SVC_Handler,                                                                  
  DebugMon_Handler,                                                             
  0,                                                                            
  PendSV_Handler,                                                               
  SysTick_Handler,                                                              

                           
  WDT_IRQHandler,                                                               
  RTC_IRQHandler,                                                               
  TIM0_IRQHandler,                                                              
  TIM2_IRQHandler,                                                              
  MCIA_IRQHandler,                                                              
  MCIB_IRQHandler,                                                              
  UART0_IRQHandler,                                                             
  UART1_IRQHandler,                                                             
  UART2_IRQHandler,                                                             
  UART4_IRQHandler,                                                             
  AACI_IRQHandler,                                                              
  CLCD_IRQHandler,                                                              
  ENET_IRQHandler,                                                              
  USBDC_IRQHandler,                                                             
  USBHC_IRQHandler,                                                             
  CHLCD_IRQHandler,                                                             
  FLEXRAY_IRQHandler,                                                           
  CAN_IRQHandler,                                                               
  LIN_IRQHandler,                                                               
  I2C_IRQHandler,                                                               
  0,                                                                            
  0,                                                                            
  0,                                                                            
  0,                                                                            
  0,                                                                            
  0,                                                                            
  0,                                                                            
  0,                                                                            
  CPU_CLCD_IRQHandler,                                                          
  0,                                                                            
  UART3_IRQHandler,                                                             
  SPI_IRQHandler                                                                
};


                                                                              
                                          
                                                                                
void Reset_Handler(void) {
  uint32_t *pSrc, *pDest;
  uint32_t *pTable __attribute__((unused));

                                                                              
                                                                       
                                                                         
                                      
                                                                            

#ifdef __STARTUP_COPY_MULTIPLE
                             
  
                                                                       
                                                       
                                                      
                                                    
                                                                  
  
                                                      
   
  pTable = &__copy_table_start__;

  for (; pTable < &__copy_table_end__; pTable = pTable + 3) {
		pSrc  = (uint32_t*)*(pTable + 0);
		pDest = (uint32_t*)*(pTable + 1);
		for (; pDest < (uint32_t*)(*(pTable + 1) + *(pTable + 2)) ; ) {
      *pDest++ = *pSrc++;
		}
	}
#else
                          
  
                                                                 
                                                                            
                                                            
                                                        
  
                                                      
   
  pSrc  = &__etext;
  pDest = &__data_start__;

  for ( ; pDest < &__data_end__ ; ) {
    *pDest++ = *pSrc++;
  }
#endif                             

                                                                           
                                                   
  
                                                                           
                                                                          
           
  
                                                                   
                                                                  
   
#ifdef __STARTUP_CLEAR_BSS_MULTIPLE
                             
  
                                                                       
                                         
                                      
                                                               
   
  pTable = &__zero_table_start__;

  for (; pTable < &__zero_table_end__; pTable = pTable + 2) {
		pDest = (uint32_t*)*(pTable + 0);
		for (; pDest < (uint32_t*)(*(pTable + 0) + *(pTable + 1)) ; ) {
      *pDest++ = 0;
		}
	}
#elif defined (__STARTUP_CLEAR_BSS)
                              
  
                                                     
                                              
                                          
  
                                                       
   
  pDest = &__bss_start__;

  for ( ; pDest < &__bss_end__ ; ) {
    *pDest++ = 0UL;
  }
#endif                                                          

#ifndef __NO_SYSTEM_INIT
	SystemInit();
#endif

#ifndef __START
#define __START _start
#endif
	__START();

}


                                                                              
                                             
                                                                                
void Default_Handler(void) {

	while(1);
}
