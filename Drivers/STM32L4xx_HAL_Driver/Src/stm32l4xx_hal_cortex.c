/**
  ******************************************************************************
  * @file    stm32l4xx_hal_cortex.c
  * @author  MCD Application Team
  * @brief   CORTEX HAL module driver.
  *          This file provides firmware functions to manage the following
  *          functionalities of the CORTEX:
  *           + Initialization and Configuration functions
  *           + Peripheral Control functions
  *
  @verbatim
  ==============================================================================
                        ##### How to use this driver #####
  ==============================================================================

    [..]
    *** How to configure Interrupts using CORTEX HAL driver ***
    ===========================================================
    [..]
    This section provides functions allowing to configure the NVIC interrupts (IRQ).
    The Cortex-M4 exceptions are managed by CMSIS functions.

    (#) Configure the NVIC Priority Grouping using HAL_NVIC_SetPriorityGrouping() function.
    (#) Configure the priority of the selected IRQ Channels using HAL_NVIC_SetPriority().
    (#) Enable the selected IRQ Channels using HAL_NVIC_EnableIRQ().

     -@- When the NVIC_PRIORITYGROUP_0 is selected, IRQ pre-emption is no more possible.
         The pending IRQ priority will be managed only by the sub priority.

     -@- IRQ priority order (sorted by highest to lowest priority):
        (+@) Lowest pre-emption priority
        (+@) Lowest sub priority
        (+@) Lowest hardware priority (IRQ number)

    [..]
    *** How to configure SysTick using CORTEX HAL driver ***
    ========================================================
    [..]
    Setup SysTick Timer for time base.

   (+) The HAL_SYSTICK_Config() function calls the SysTick_Config() function which
       is a CMSIS function that:
        (++) Configures the SysTick Reload register with value passed as function parameter.
        (++) Configures the SysTick IRQ priority to the lowest value (0x0F).
        (++) Resets the SysTick Counter register.
        (++) Configures the SysTick Counter clock source to be Core Clock Source (HCLK).
        (++) Enables the SysTick Interrupt.
        (++) Starts the SysTick Counter.

   (+) You can change the SysTick Clock source to be HCLK_Div8 by calling the macro
       __HAL_CORTEX_SYSTICKCLK_CONFIG(SYSTICK_CLKSOURCE_HCLK_DIV8) just after the
       HAL_SYSTICK_Config() function call. The __HAL_CORTEX_SYSTICKCLK_CONFIG() macro is defined
       inside the stm32l4xx_hal_cortex.h file.

   (+) You can change the SysTick IRQ priority by calling the
       HAL_NVIC_SetPriority(SysTick_IRQn,...) function just after the HAL_SYSTICK_Config() function
       call. The HAL_NVIC_SetPriority() call the NVIC_SetPriority() function which is a CMSIS function.

   (+) To adjust the SysTick time base, use the following formula:

       Reload Value = SysTick Counter Clock (Hz) x  Desired Time base (s)
       (++) Reload Value is the parameter to be passed for HAL_SYSTICK_Config() function
       (++) Reload Value should not exceed 0xFFFFFF

  @endverbatim
  ******************************************************************************

  The table below gives the allowed values of the pre-emption priority and subpriority according
  to the Priority Grouping configuration performed by HAL_NVIC_SetPriorityGrouping() function.
  
    ==========================================================================================================================
      NVIC_PriorityGroup   | NVIC_IRQChannelPreemptionPriority | NVIC_IRQChannelSubPriority  |       Description
    ==========================================================================================================================
     NVIC_PRIORITYGROUP_0  |                0                  |            0-15             | 0 bit for pre-emption priority
                           |                                   |                             | 4 bits for subpriority
    --------------------------------------------------------------------------------------------------------------------------
     NVIC_PRIORITYGROUP_1  |                0-1                |            0-7              | 1 bit for pre-emption priority
                           |                                   |                             | 3 bits for subpriority
    --------------------------------------------------------------------------------------------------------------------------    
     NVIC_PRIORITYGROUP_2  |                0-3                |            0-3              | 2 bits for pre-emption priority
                           |                                   |                             | 2 bits for subpriority
    --------------------------------------------------------------------------------------------------------------------------    
     NVIC_PRIORITYGROUP_3  |                0-7                |            0-1              | 3 bits for pre-emption priority
                           |                                   |                             | 1 bit for subpriority
    --------------------------------------------------------------------------------------------------------------------------    
     NVIC_PRIORITYGROUP_4  |                0-15               |            0                | 4 bits for pre-emption priority
                           |                                   |                             | 0 bit for subpriority                       
    ==========================================================================================================================

  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2017 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file in
  * the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */

                                                                                
#include "stm32l4xx_hal.h"

                                    
      
    

                      
      
    

#ifdef HAL_CORTEX_MODULE_ENABLED

                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                

                                         
      
    


                                                
                                                        
  
         
                                                                                
                                                                    
                                                                                
        
                                                                                            
                             

            
      
    


   
                                                                                  
                                               
                                                             
                                                              
                                                                       
                                                             
                                                                       
                                                             
                                                                       
                                                             
                                                                       
                                                             
                                                                       
                                                             
                                                                                           
                                                                             
                
    
void HAL_NVIC_SetPriorityGrouping(uint32_t PriorityGroup)
{
                            
  assert_param(IS_NVIC_PRIORITY_GROUP(PriorityGroup));

                                                                                  
  NVIC_SetPriorityGrouping(PriorityGroup);
}

   
                                             
                                            
                                                                        
                                                                                                                                 
                                                                           
                                                          
                                                              
                                                                   
                                                          
                                                               
                
    
void HAL_NVIC_SetPriority(IRQn_Type IRQn, uint32_t PreemptPriority, uint32_t SubPriority)
{
  uint32_t prioritygroup = 0x00;

                            
  assert_param(IS_NVIC_SUB_PRIORITY(SubPriority));
  assert_param(IS_NVIC_PREEMPTION_PRIORITY(PreemptPriority));

  prioritygroup = NVIC_GetPriorityGrouping();

  NVIC_SetPriority(IRQn, NVIC_EncodePriority(prioritygroup, PreemptPriority, SubPriority));
}

   
                                                                                
                                                                                      
                                             
                                           
                                                                        
                                                                                                                                 
                
    
void HAL_NVIC_EnableIRQ(IRQn_Type IRQn)
{
                            
  assert_param(IS_NVIC_DEVICE_IRQ(IRQn));
  
                        
  NVIC_EnableIRQ(IRQn);
}

   
                                                                                 
                                           
                                                                        
                                                                                                                                 
                
    
void HAL_NVIC_DisableIRQ(IRQn_Type IRQn)
{
                            
  assert_param(IS_NVIC_DEVICE_IRQ(IRQn));
  
                         
  NVIC_DisableIRQ(IRQn);
}

   
                                                             
                
    
void HAL_NVIC_SystemReset(void)
{
                    
  NVIC_SystemReset();
}

   
                                                                                                          
                                                                            
                                                                                  
                                             
                                          
    
uint32_t HAL_SYSTICK_Config(uint32_t TicksNumb)
{
   return SysTick_Config(TicksNumb);
}
   
      
    

                                                
                                     
  
         
                                                                                
                                                              
                                                                                
        
                                                                                
                                           


            
      
    

   
                                                                               
                                                                      
    
uint32_t HAL_NVIC_GetPriorityGrouping(void)
{
                                          
  return NVIC_GetPriorityGrouping();
}

   
                                             
                                            
                                                                        
                                                                                                                                 
                                                              
                                                              
                                                                        
                                                               
                                                                        
                                                               
                                                                         
                                                               
                                                                         
                                                              
                                                                         
                                                              
                                                                                         
                                                                             
                
    
void HAL_NVIC_GetPriority(IRQn_Type IRQn, uint32_t PriorityGroup, uint32_t *pPreemptPriority, uint32_t *pSubPriority)
{
                            
  assert_param(IS_NVIC_PRIORITY_GROUP(PriorityGroup));
                                                                     
  NVIC_DecodePriority(NVIC_GetPriority(IRQn), PriorityGroup, pPreemptPriority, pSubPriority);
}

   
                                                     
                                          
                                                                        
                                                                                                                                 
                
    
void HAL_NVIC_SetPendingIRQ(IRQn_Type IRQn)
{
                            
  assert_param(IS_NVIC_DEVICE_IRQ(IRQn));
  
                             
  NVIC_SetPendingIRQ(IRQn);
}

   
                                                                        
                                                                    
                                           
                                                                         
                                                                                                                                 
                                                         
                                                     
    
uint32_t HAL_NVIC_GetPendingIRQ(IRQn_Type IRQn)
{
                            
  assert_param(IS_NVIC_DEVICE_IRQ(IRQn));
  
                                  
  return NVIC_GetPendingIRQ(IRQn);
}

   
                                                           
                                           
                                                                        
                                                                                                                                 
                
    
void HAL_NVIC_ClearPendingIRQ(IRQn_Type IRQn)
{
                            
  assert_param(IS_NVIC_DEVICE_IRQ(IRQn));
  
                               
  NVIC_ClearPendingIRQ(IRQn);
}

   
                                                                                             
                                         
                                                                        
                                                                                                                                 
                                                         
                                                     
    
uint32_t HAL_NVIC_GetActive(IRQn_Type IRQn)
{
                                 
  return NVIC_GetActive(IRQn);
}

   
                                               
                                                          
                                                               
                                                                                                          
                                                                                        
                
    
void HAL_SYSTICK_CLKSourceConfig(uint32_t CLKSource)
{
                            
  assert_param(IS_SYSTICK_CLK_SOURCE(CLKSource));
  if (CLKSource == SYSTICK_CLKSOURCE_HCLK)
  {
    SysTick->CTRL |= SYSTICK_CLKSOURCE_HCLK;
  }
  else
  {
    SysTick->CTRL &= ~SYSTICK_CLKSOURCE_HCLK;
  }
}

   
                                             
                
    
void HAL_SYSTICK_IRQHandler(void)
{
  HAL_SYSTICK_Callback();
}

   
                             
                
    
__weak void HAL_SYSTICK_Callback(void)
{
                                                                              
                                                                          
     
}

#if (__MPU_PRESENT == 1)
   
                           
                                                                                  
                                                                       
                                                               
                                          
                                     
                                          
                                     
                
    
void HAL_MPU_Enable(uint32_t MPU_Control)
{
                      
  MPU->CTRL = (MPU_Control | MPU_CTRL_ENABLE_Msk);

                                       
  __DSB();
  __ISB();
}


   
                            
                
    
void HAL_MPU_Disable(void)
{
                                                
  __DMB();

                                                     
  MPU->CTRL  = 0;
}

   
                                  
                
    
void HAL_MPU_EnableRegion(uint32_t RegionNumber)
{
                            
  assert_param(IS_MPU_REGION_NUMBER(RegionNumber));

                             
  MPU->RNR = RegionNumber;

                         
  SET_BIT(MPU->RASR, MPU_RASR_ENABLE_Msk);
}

   
                                   
                
    
void HAL_MPU_DisableRegion(uint32_t RegionNumber)
{
                            
  assert_param(IS_MPU_REGION_NUMBER(RegionNumber));

                             
  MPU->RNR = RegionNumber;

                          
  CLEAR_BIT(MPU->RASR, MPU_RASR_ENABLE_Msk);
}

   
                                                                               
                                                                                 
                                                                    
                
    
void HAL_MPU_ConfigRegion(MPU_Region_InitTypeDef *MPU_Init)
{
                            
  assert_param(IS_MPU_REGION_NUMBER(MPU_Init->Number));
  assert_param(IS_MPU_REGION_ENABLE(MPU_Init->Enable));
  assert_param(IS_MPU_INSTRUCTION_ACCESS(MPU_Init->DisableExec));
  assert_param(IS_MPU_REGION_PERMISSION_ATTRIBUTE(MPU_Init->AccessPermission));
  assert_param(IS_MPU_TEX_LEVEL(MPU_Init->TypeExtField));
  assert_param(IS_MPU_ACCESS_SHAREABLE(MPU_Init->IsShareable));
  assert_param(IS_MPU_ACCESS_CACHEABLE(MPU_Init->IsCacheable));
  assert_param(IS_MPU_ACCESS_BUFFERABLE(MPU_Init->IsBufferable));
  assert_param(IS_MPU_SUB_REGION_DISABLE(MPU_Init->SubRegionDisable));
  assert_param(IS_MPU_REGION_SIZE(MPU_Init->Size));
                             
  MPU->RNR = MPU_Init->Number;

                        
  CLEAR_BIT(MPU->RASR, MPU_RASR_ENABLE_Msk);

                           
  MPU->RBAR = MPU_Init->BaseAddress;
  MPU->RASR = ((uint32_t)MPU_Init->DisableExec             << MPU_RASR_XN_Pos)   |
              ((uint32_t)MPU_Init->AccessPermission        << MPU_RASR_AP_Pos)   |
              ((uint32_t)MPU_Init->TypeExtField            << MPU_RASR_TEX_Pos)  |
              ((uint32_t)MPU_Init->IsShareable             << MPU_RASR_S_Pos)    |
              ((uint32_t)MPU_Init->IsCacheable             << MPU_RASR_C_Pos)    |
              ((uint32_t)MPU_Init->IsBufferable            << MPU_RASR_B_Pos)    |
              ((uint32_t)MPU_Init->SubRegionDisable        << MPU_RASR_SRD_Pos)  |
              ((uint32_t)MPU_Init->Size                    << MPU_RASR_SIZE_Pos) |
              ((uint32_t)MPU_Init->Enable                  << MPU_RASR_ENABLE_Pos);
}
#endif                    

   
      
    

   
      
    

#endif                                
   
      
    

   
      
    

