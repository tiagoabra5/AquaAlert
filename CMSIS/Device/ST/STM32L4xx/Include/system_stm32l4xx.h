/**
  ******************************************************************************
  * @file    system_stm32l4xx.h
  * @author  MCD Application Team
  * @brief   CMSIS Cortex-M4 Device System Source File for STM32L4xx devices.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2017 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */

                     
      
    

                                
      
    

   
                                                
    
#ifndef __SYSTEM_STM32L4XX_H
#define __SYSTEM_STM32L4XX_H

#ifdef __cplusplus
 extern "C" {
#endif

                                         
      
    

   
      
    


                                                   
      
    
                                                           
                                                          
                                                              
                                                                                          
                                                                                 
                                                                                           
                                                 
    
extern uint32_t SystemCoreClock;                                                       

extern const uint8_t  AHBPrescTable[16];                                       
extern const uint8_t  APBPrescTable[8];                                        
extern const uint32_t MSIRangeTable[12];                                       

   
      
    

                                                   
      
    

   
      
    

                                                
      
    

   
      
    

                                                   
      
    

extern void SystemInit(void);
extern void SystemCoreClockUpdate(void);
   
      
    

#ifdef __cplusplus
}
#endif

#endif                          

   
      
    

   
      
    

