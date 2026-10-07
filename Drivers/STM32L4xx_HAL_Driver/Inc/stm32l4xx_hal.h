/**
  ******************************************************************************
  * @file    stm32l4xx_hal.h
  * @author  MCD Application Team
  * @brief   This file contains all the functions prototypes for the HAL
  *          module driver.
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

                                                                                
#ifndef STM32L4xx_HAL_H
#define STM32L4xx_HAL_H

#ifdef __cplusplus
 extern "C" {
#endif

                                                                                
#include "stm32l4xx_hal_conf.h"

                                    
      
    

                   
      
    

                                                                                
                                                   
      
    

                                          
      
    
typedef enum
{
  HAL_TICK_FREQ_10HZ         = 100U,
  HAL_TICK_FREQ_100HZ        = 10U,
  HAL_TICK_FREQ_1KHZ         = 1U,
  HAL_TICK_FREQ_DEFAULT      = HAL_TICK_FREQ_1KHZ
} HAL_TickFreqTypeDef;
   
      
    

   
      
    

                                                                                

                                                           
      
    

                                                                 
      
    

                                       
      
    
#define SYSCFG_BOOT_MAINFLASH          0U
#define SYSCFG_BOOT_SYSTEMFLASH        SYSCFG_MEMRMP_MEM_MODE_0

#if defined (STM32L471xx) || defined (STM32L475xx) || defined (STM32L476xx) || defined (STM32L485xx) || defined (STM32L486xx) || \
    defined (STM32L496xx) || defined (STM32L4A6xx) || \
    defined (STM32L4P5xx) || defined (STM32L4Q5xx) || \
    defined (STM32L4R5xx) || defined (STM32L4R7xx) || defined (STM32L4R9xx) || defined (STM32L4S5xx) || defined (STM32L4S7xx) || defined (STM32L4S9xx)
#define SYSCFG_BOOT_FMC                SYSCFG_MEMRMP_MEM_MODE_1
#endif                                                                                 
                                          
                                          
                                                                                                   

#define SYSCFG_BOOT_SRAM               (SYSCFG_MEMRMP_MEM_MODE_1 | SYSCFG_MEMRMP_MEM_MODE_0)

#if defined (STM32L4P5xx) || defined (STM32L4Q5xx) || defined (STM32L4R5xx) || defined (STM32L4R7xx) || defined (STM32L4R9xx) || defined (STM32L4S5xx) || defined (STM32L4S7xx) || defined (STM32L4S9xx)
#define SYSCFG_BOOT_OCTOPSPI1          (SYSCFG_MEMRMP_MEM_MODE_2)
#define SYSCFG_BOOT_OCTOPSPI2          (SYSCFG_MEMRMP_MEM_MODE_2 | SYSCFG_MEMRMP_MEM_MODE_0)
#else
#define SYSCFG_BOOT_QUADSPI            (SYSCFG_MEMRMP_MEM_MODE_2 | SYSCFG_MEMRMP_MEM_MODE_1)
#endif                                                                                                                           

   
      
    

                                                  
      
    
#define SYSCFG_IT_FPU_IOC              SYSCFG_CFGR1_FPU_IE_0                                                         
#define SYSCFG_IT_FPU_DZC              SYSCFG_CFGR1_FPU_IE_1                                                      
#define SYSCFG_IT_FPU_UFC              SYSCFG_CFGR1_FPU_IE_2                                                 
#define SYSCFG_IT_FPU_OFC              SYSCFG_CFGR1_FPU_IE_3                                                
#define SYSCFG_IT_FPU_IDC              SYSCFG_CFGR1_FPU_IE_4                                                      
#define SYSCFG_IT_FPU_IXC              SYSCFG_CFGR1_FPU_IE_5                                               

   
      
    

                                                                   
      
    
#define SYSCFG_SRAM2WRP_PAGE0          SYSCFG_SWPR_PAGE0                                      
#define SYSCFG_SRAM2WRP_PAGE1          SYSCFG_SWPR_PAGE1                                      
#define SYSCFG_SRAM2WRP_PAGE2          SYSCFG_SWPR_PAGE2                                      
#define SYSCFG_SRAM2WRP_PAGE3          SYSCFG_SWPR_PAGE3                                      
#define SYSCFG_SRAM2WRP_PAGE4          SYSCFG_SWPR_PAGE4                                      
#define SYSCFG_SRAM2WRP_PAGE5          SYSCFG_SWPR_PAGE5                                      
#define SYSCFG_SRAM2WRP_PAGE6          SYSCFG_SWPR_PAGE6                                      
#define SYSCFG_SRAM2WRP_PAGE7          SYSCFG_SWPR_PAGE7                                      
#define SYSCFG_SRAM2WRP_PAGE8          SYSCFG_SWPR_PAGE8                                      
#define SYSCFG_SRAM2WRP_PAGE9          SYSCFG_SWPR_PAGE9                                      
#define SYSCFG_SRAM2WRP_PAGE10         SYSCFG_SWPR_PAGE10                                       
#define SYSCFG_SRAM2WRP_PAGE11         SYSCFG_SWPR_PAGE11                                       
#define SYSCFG_SRAM2WRP_PAGE12         SYSCFG_SWPR_PAGE12                                       
#define SYSCFG_SRAM2WRP_PAGE13         SYSCFG_SWPR_PAGE13                                       
#define SYSCFG_SRAM2WRP_PAGE14         SYSCFG_SWPR_PAGE14                                       
#define SYSCFG_SRAM2WRP_PAGE15         SYSCFG_SWPR_PAGE15                                       
#if defined(SYSCFG_SWPR_PAGE31)
#define SYSCFG_SRAM2WRP_PAGE16         SYSCFG_SWPR_PAGE16                                       
#define SYSCFG_SRAM2WRP_PAGE17         SYSCFG_SWPR_PAGE17                                       
#define SYSCFG_SRAM2WRP_PAGE18         SYSCFG_SWPR_PAGE18                                       
#define SYSCFG_SRAM2WRP_PAGE19         SYSCFG_SWPR_PAGE19                                       
#define SYSCFG_SRAM2WRP_PAGE20         SYSCFG_SWPR_PAGE20                                       
#define SYSCFG_SRAM2WRP_PAGE21         SYSCFG_SWPR_PAGE21                                       
#define SYSCFG_SRAM2WRP_PAGE22         SYSCFG_SWPR_PAGE22                                       
#define SYSCFG_SRAM2WRP_PAGE23         SYSCFG_SWPR_PAGE23                                       
#define SYSCFG_SRAM2WRP_PAGE24         SYSCFG_SWPR_PAGE24                                       
#define SYSCFG_SRAM2WRP_PAGE25         SYSCFG_SWPR_PAGE25                                       
#define SYSCFG_SRAM2WRP_PAGE26         SYSCFG_SWPR_PAGE26                                       
#define SYSCFG_SRAM2WRP_PAGE27         SYSCFG_SWPR_PAGE27                                       
#define SYSCFG_SRAM2WRP_PAGE28         SYSCFG_SWPR_PAGE28                                       
#define SYSCFG_SRAM2WRP_PAGE29         SYSCFG_SWPR_PAGE29                                       
#define SYSCFG_SRAM2WRP_PAGE30         SYSCFG_SWPR_PAGE30                                       
#define SYSCFG_SRAM2WRP_PAGE31         SYSCFG_SWPR_PAGE31                                       
#endif                         

   
      
    

#if defined(SYSCFG_SWPR2_PAGE63)
                                                                          
      
    
#define SYSCFG_SRAM2WRP_PAGE32         SYSCFG_SWPR2_PAGE32                                       
#define SYSCFG_SRAM2WRP_PAGE33         SYSCFG_SWPR2_PAGE33                                       
#define SYSCFG_SRAM2WRP_PAGE34         SYSCFG_SWPR2_PAGE34                                       
#define SYSCFG_SRAM2WRP_PAGE35         SYSCFG_SWPR2_PAGE35                                       
#define SYSCFG_SRAM2WRP_PAGE36         SYSCFG_SWPR2_PAGE36                                       
#define SYSCFG_SRAM2WRP_PAGE37         SYSCFG_SWPR2_PAGE37                                       
#define SYSCFG_SRAM2WRP_PAGE38         SYSCFG_SWPR2_PAGE38                                       
#define SYSCFG_SRAM2WRP_PAGE39         SYSCFG_SWPR2_PAGE39                                       
#define SYSCFG_SRAM2WRP_PAGE40         SYSCFG_SWPR2_PAGE40                                       
#define SYSCFG_SRAM2WRP_PAGE41         SYSCFG_SWPR2_PAGE41                                       
#define SYSCFG_SRAM2WRP_PAGE42         SYSCFG_SWPR2_PAGE42                                       
#define SYSCFG_SRAM2WRP_PAGE43         SYSCFG_SWPR2_PAGE43                                       
#define SYSCFG_SRAM2WRP_PAGE44         SYSCFG_SWPR2_PAGE44                                       
#define SYSCFG_SRAM2WRP_PAGE45         SYSCFG_SWPR2_PAGE45                                       
#define SYSCFG_SRAM2WRP_PAGE46         SYSCFG_SWPR2_PAGE46                                       
#define SYSCFG_SRAM2WRP_PAGE47         SYSCFG_SWPR2_PAGE47                                       
#define SYSCFG_SRAM2WRP_PAGE48         SYSCFG_SWPR2_PAGE48                                       
#define SYSCFG_SRAM2WRP_PAGE49         SYSCFG_SWPR2_PAGE49                                       
#define SYSCFG_SRAM2WRP_PAGE50         SYSCFG_SWPR2_PAGE50                                       
#define SYSCFG_SRAM2WRP_PAGE51         SYSCFG_SWPR2_PAGE51                                       
#define SYSCFG_SRAM2WRP_PAGE52         SYSCFG_SWPR2_PAGE52                                       
#define SYSCFG_SRAM2WRP_PAGE53         SYSCFG_SWPR2_PAGE53                                       
#define SYSCFG_SRAM2WRP_PAGE54         SYSCFG_SWPR2_PAGE54                                       
#define SYSCFG_SRAM2WRP_PAGE55         SYSCFG_SWPR2_PAGE55                                       
#define SYSCFG_SRAM2WRP_PAGE56         SYSCFG_SWPR2_PAGE56                                       
#define SYSCFG_SRAM2WRP_PAGE57         SYSCFG_SWPR2_PAGE57                                       
#define SYSCFG_SRAM2WRP_PAGE58         SYSCFG_SWPR2_PAGE58                                       
#define SYSCFG_SRAM2WRP_PAGE59         SYSCFG_SWPR2_PAGE59                                       
#define SYSCFG_SRAM2WRP_PAGE60         SYSCFG_SWPR2_PAGE60                                       
#define SYSCFG_SRAM2WRP_PAGE61         SYSCFG_SWPR2_PAGE61                                       
#define SYSCFG_SRAM2WRP_PAGE62         SYSCFG_SWPR2_PAGE62                                       
#define SYSCFG_SRAM2WRP_PAGE63         SYSCFG_SWPR2_PAGE63                                       

   
      
    
#endif                          

#if defined(VREFBUF)
                                                               
      
    
#define SYSCFG_VREFBUF_VOLTAGE_SCALE0  0U                                                            
#define SYSCFG_VREFBUF_VOLTAGE_SCALE1  VREFBUF_CSR_VRS                                               

   
      
    

                                                                 
      
    
#define SYSCFG_VREFBUF_HIGH_IMPEDANCE_DISABLE  0U                                                                                               
#define SYSCFG_VREFBUF_HIGH_IMPEDANCE_ENABLE   VREFBUF_CSR_HIZ                                         

   
      
    
#endif              

                                           
      
    

#define SYSCFG_FLAG_SRAM2_PE            SYSCFG_CFGR2_SPF                                 
#define SYSCFG_FLAG_SRAM2_BUSY          SYSCFG_SCSR_SRAM2BSY                                        

   
      
    

                                                             
      
    

                                                                
    
#define SYSCFG_FASTMODEPLUS_PB6        SYSCFG_CFGR1_I2C_PB6_FMP                                      
#define SYSCFG_FASTMODEPLUS_PB7        SYSCFG_CFGR1_I2C_PB7_FMP                                      
#if defined(SYSCFG_CFGR1_I2C_PB8_FMP)
#define SYSCFG_FASTMODEPLUS_PB8        SYSCFG_CFGR1_I2C_PB8_FMP                                      
#endif                               
#if defined(SYSCFG_CFGR1_I2C_PB9_FMP)
#define SYSCFG_FASTMODEPLUS_PB9        SYSCFG_CFGR1_I2C_PB9_FMP                                      
#endif                               

   
     
   

   
      
    

   
      
    

                                                                                
                                                     
      
    

                                                           
      
    

                                                     
    
#if defined(DBGMCU_APB1FZR1_DBG_TIM2_STOP)
#define __HAL_DBGMCU_FREEZE_TIM2()           SET_BIT(DBGMCU->APB1FZR1, DBGMCU_APB1FZR1_DBG_TIM2_STOP)
#define __HAL_DBGMCU_UNFREEZE_TIM2()         CLEAR_BIT(DBGMCU->APB1FZR1, DBGMCU_APB1FZR1_DBG_TIM2_STOP)
#endif

#if defined(DBGMCU_APB1FZR1_DBG_TIM3_STOP)
#define __HAL_DBGMCU_FREEZE_TIM3()           SET_BIT(DBGMCU->APB1FZR1, DBGMCU_APB1FZR1_DBG_TIM3_STOP)
#define __HAL_DBGMCU_UNFREEZE_TIM3()         CLEAR_BIT(DBGMCU->APB1FZR1, DBGMCU_APB1FZR1_DBG_TIM3_STOP)
#endif

#if defined(DBGMCU_APB1FZR1_DBG_TIM4_STOP)
#define __HAL_DBGMCU_FREEZE_TIM4()           SET_BIT(DBGMCU->APB1FZR1, DBGMCU_APB1FZR1_DBG_TIM4_STOP)
#define __HAL_DBGMCU_UNFREEZE_TIM4()         CLEAR_BIT(DBGMCU->APB1FZR1, DBGMCU_APB1FZR1_DBG_TIM4_STOP)
#endif

#if defined(DBGMCU_APB1FZR1_DBG_TIM5_STOP)
#define __HAL_DBGMCU_FREEZE_TIM5()           SET_BIT(DBGMCU->APB1FZR1, DBGMCU_APB1FZR1_DBG_TIM5_STOP)
#define __HAL_DBGMCU_UNFREEZE_TIM5()         CLEAR_BIT(DBGMCU->APB1FZR1, DBGMCU_APB1FZR1_DBG_TIM5_STOP)
#endif

#if defined(DBGMCU_APB1FZR1_DBG_TIM6_STOP)
#define __HAL_DBGMCU_FREEZE_TIM6()           SET_BIT(DBGMCU->APB1FZR1, DBGMCU_APB1FZR1_DBG_TIM6_STOP)
#define __HAL_DBGMCU_UNFREEZE_TIM6()         CLEAR_BIT(DBGMCU->APB1FZR1, DBGMCU_APB1FZR1_DBG_TIM6_STOP)
#endif

#if defined(DBGMCU_APB1FZR1_DBG_TIM7_STOP)
#define __HAL_DBGMCU_FREEZE_TIM7()           SET_BIT(DBGMCU->APB1FZR1, DBGMCU_APB1FZR1_DBG_TIM7_STOP)
#define __HAL_DBGMCU_UNFREEZE_TIM7()         CLEAR_BIT(DBGMCU->APB1FZR1, DBGMCU_APB1FZR1_DBG_TIM7_STOP)
#endif

#if defined(DBGMCU_APB1FZR1_DBG_RTC_STOP)
#define __HAL_DBGMCU_FREEZE_RTC()            SET_BIT(DBGMCU->APB1FZR1, DBGMCU_APB1FZR1_DBG_RTC_STOP)
#define __HAL_DBGMCU_UNFREEZE_RTC()          CLEAR_BIT(DBGMCU->APB1FZR1, DBGMCU_APB1FZR1_DBG_RTC_STOP)
#endif

#if defined(DBGMCU_APB1FZR1_DBG_WWDG_STOP)
#define __HAL_DBGMCU_FREEZE_WWDG()           SET_BIT(DBGMCU->APB1FZR1, DBGMCU_APB1FZR1_DBG_WWDG_STOP)
#define __HAL_DBGMCU_UNFREEZE_WWDG()         CLEAR_BIT(DBGMCU->APB1FZR1, DBGMCU_APB1FZR1_DBG_WWDG_STOP)
#endif

#if defined(DBGMCU_APB1FZR1_DBG_IWDG_STOP)
#define __HAL_DBGMCU_FREEZE_IWDG()           SET_BIT(DBGMCU->APB1FZR1, DBGMCU_APB1FZR1_DBG_IWDG_STOP)
#define __HAL_DBGMCU_UNFREEZE_IWDG()         CLEAR_BIT(DBGMCU->APB1FZR1, DBGMCU_APB1FZR1_DBG_IWDG_STOP)
#endif

#if defined(DBGMCU_APB1FZR1_DBG_I2C1_STOP)
#define __HAL_DBGMCU_FREEZE_I2C1_TIMEOUT()   SET_BIT(DBGMCU->APB1FZR1, DBGMCU_APB1FZR1_DBG_I2C1_STOP)
#define __HAL_DBGMCU_UNFREEZE_I2C1_TIMEOUT() CLEAR_BIT(DBGMCU->APB1FZR1, DBGMCU_APB1FZR1_DBG_I2C1_STOP)
#endif

#if defined(DBGMCU_APB1FZR1_DBG_I2C2_STOP)
#define __HAL_DBGMCU_FREEZE_I2C2_TIMEOUT()   SET_BIT(DBGMCU->APB1FZR1, DBGMCU_APB1FZR1_DBG_I2C2_STOP)
#define __HAL_DBGMCU_UNFREEZE_I2C2_TIMEOUT() CLEAR_BIT(DBGMCU->APB1FZR1, DBGMCU_APB1FZR1_DBG_I2C2_STOP)
#endif

#if defined(DBGMCU_APB1FZR1_DBG_I2C3_STOP)
#define __HAL_DBGMCU_FREEZE_I2C3_TIMEOUT()   SET_BIT(DBGMCU->APB1FZR1, DBGMCU_APB1FZR1_DBG_I2C3_STOP)
#define __HAL_DBGMCU_UNFREEZE_I2C3_TIMEOUT() CLEAR_BIT(DBGMCU->APB1FZR1, DBGMCU_APB1FZR1_DBG_I2C3_STOP)
#endif

#if defined(DBGMCU_APB1FZR2_DBG_I2C4_STOP)
#define __HAL_DBGMCU_FREEZE_I2C4_TIMEOUT()   SET_BIT(DBGMCU->APB1FZR2, DBGMCU_APB1FZR2_DBG_I2C4_STOP)
#define __HAL_DBGMCU_UNFREEZE_I2C4_TIMEOUT() CLEAR_BIT(DBGMCU->APB1FZR2, DBGMCU_APB1FZR2_DBG_I2C4_STOP)
#endif

#if defined(DBGMCU_APB1FZR1_DBG_CAN_STOP)
#define __HAL_DBGMCU_FREEZE_CAN1()           SET_BIT(DBGMCU->APB1FZR1, DBGMCU_APB1FZR1_DBG_CAN_STOP)
#define __HAL_DBGMCU_UNFREEZE_CAN1()         CLEAR_BIT(DBGMCU->APB1FZR1, DBGMCU_APB1FZR1_DBG_CAN_STOP)
#endif

#if defined(DBGMCU_APB1FZR1_DBG_CAN2_STOP)
#define __HAL_DBGMCU_FREEZE_CAN2()           SET_BIT(DBGMCU->APB1FZR1, DBGMCU_APB1FZR1_DBG_CAN2_STOP)
#define __HAL_DBGMCU_UNFREEZE_CAN2()         CLEAR_BIT(DBGMCU->APB1FZR1, DBGMCU_APB1FZR1_DBG_CAN2_STOP)
#endif

#if defined(DBGMCU_APB1FZR1_DBG_LPTIM1_STOP)
#define __HAL_DBGMCU_FREEZE_LPTIM1()         SET_BIT(DBGMCU->APB1FZR1, DBGMCU_APB1FZR1_DBG_LPTIM1_STOP)
#define __HAL_DBGMCU_UNFREEZE_LPTIM1()       CLEAR_BIT(DBGMCU->APB1FZR1, DBGMCU_APB1FZR1_DBG_LPTIM1_STOP)
#endif

#if defined(DBGMCU_APB1FZR2_DBG_LPTIM2_STOP)
#define __HAL_DBGMCU_FREEZE_LPTIM2()         SET_BIT(DBGMCU->APB1FZR2, DBGMCU_APB1FZR2_DBG_LPTIM2_STOP)
#define __HAL_DBGMCU_UNFREEZE_LPTIM2()       CLEAR_BIT(DBGMCU->APB1FZR2, DBGMCU_APB1FZR2_DBG_LPTIM2_STOP)
#endif

#if defined(DBGMCU_APB2FZ_DBG_TIM1_STOP)
#define __HAL_DBGMCU_FREEZE_TIM1()           SET_BIT(DBGMCU->APB2FZ, DBGMCU_APB2FZ_DBG_TIM1_STOP)
#define __HAL_DBGMCU_UNFREEZE_TIM1()         CLEAR_BIT(DBGMCU->APB2FZ, DBGMCU_APB2FZ_DBG_TIM1_STOP)
#endif

#if defined(DBGMCU_APB2FZ_DBG_TIM8_STOP)
#define __HAL_DBGMCU_FREEZE_TIM8()           SET_BIT(DBGMCU->APB2FZ, DBGMCU_APB2FZ_DBG_TIM8_STOP)
#define __HAL_DBGMCU_UNFREEZE_TIM8()         CLEAR_BIT(DBGMCU->APB2FZ, DBGMCU_APB2FZ_DBG_TIM8_STOP)
#endif

#if defined(DBGMCU_APB2FZ_DBG_TIM15_STOP)
#define __HAL_DBGMCU_FREEZE_TIM15()          SET_BIT(DBGMCU->APB2FZ, DBGMCU_APB2FZ_DBG_TIM15_STOP)
#define __HAL_DBGMCU_UNFREEZE_TIM15()        CLEAR_BIT(DBGMCU->APB2FZ, DBGMCU_APB2FZ_DBG_TIM15_STOP)
#endif

#if defined(DBGMCU_APB2FZ_DBG_TIM16_STOP)
#define __HAL_DBGMCU_FREEZE_TIM16()          SET_BIT(DBGMCU->APB2FZ, DBGMCU_APB2FZ_DBG_TIM16_STOP)
#define __HAL_DBGMCU_UNFREEZE_TIM16()        CLEAR_BIT(DBGMCU->APB2FZ, DBGMCU_APB2FZ_DBG_TIM16_STOP)
#endif

#if defined(DBGMCU_APB2FZ_DBG_TIM17_STOP)
#define __HAL_DBGMCU_FREEZE_TIM17()          SET_BIT(DBGMCU->APB2FZ, DBGMCU_APB2FZ_DBG_TIM17_STOP)
#define __HAL_DBGMCU_UNFREEZE_TIM17()        CLEAR_BIT(DBGMCU->APB2FZ, DBGMCU_APB2FZ_DBG_TIM17_STOP)
#endif

   
      
    

                                                           
      
    

                                                   
    
#define __HAL_SYSCFG_REMAPMEMORY_FLASH()       CLEAR_BIT(SYSCFG->MEMRMP, SYSCFG_MEMRMP_MEM_MODE)

                                                     
    
#define __HAL_SYSCFG_REMAPMEMORY_SYSTEMFLASH() MODIFY_REG(SYSCFG->MEMRMP, SYSCFG_MEMRMP_MEM_MODE, SYSCFG_MEMRMP_MEM_MODE_0)

                                               
    
#define __HAL_SYSCFG_REMAPMEMORY_SRAM()        MODIFY_REG(SYSCFG->MEMRMP, SYSCFG_MEMRMP_MEM_MODE, (SYSCFG_MEMRMP_MEM_MODE_1|SYSCFG_MEMRMP_MEM_MODE_0))

#if defined (STM32L471xx) || defined (STM32L475xx) || defined (STM32L476xx) || defined (STM32L485xx) || defined (STM32L486xx) || \
    defined (STM32L496xx) || defined (STM32L4A6xx) || \
    defined (STM32L4P5xx) || defined (STM32L4Q5xx) || \
    defined (STM32L4R5xx) || defined (STM32L4R7xx) || defined (STM32L4R9xx) || defined (STM32L4S5xx) || defined (STM32L4S7xx) || defined (STM32L4S9xx)

                                                               
    
#define __HAL_SYSCFG_REMAPMEMORY_FMC()         MODIFY_REG(SYSCFG->MEMRMP, SYSCFG_MEMRMP_MEM_MODE, SYSCFG_MEMRMP_MEM_MODE_1)

#endif                                                                                 
                                          
                                          
                                                                                                   

#if defined (STM32L4P5xx) || defined (STM32L4Q5xx) || defined (STM32L4R5xx) || defined (STM32L4R7xx) || defined (STM32L4R9xx) || defined (STM32L4S5xx) || defined (STM32L4S7xx) || defined (STM32L4S9xx)

                                         
    
#define __HAL_SYSCFG_REMAPMEMORY_OCTOSPI1()    MODIFY_REG(SYSCFG->MEMRMP, SYSCFG_MEMRMP_MEM_MODE, (SYSCFG_MEMRMP_MEM_MODE_2))
#define __HAL_SYSCFG_REMAPMEMORY_OCTOSPI2()    MODIFY_REG(SYSCFG->MEMRMP, SYSCFG_MEMRMP_MEM_MODE, (SYSCFG_MEMRMP_MEM_MODE_2|SYSCFG_MEMRMP_MEM_MODE_0))

#else

                                         
    
#define __HAL_SYSCFG_REMAPMEMORY_QUADSPI()     MODIFY_REG(SYSCFG->MEMRMP, SYSCFG_MEMRMP_MEM_MODE, (SYSCFG_MEMRMP_MEM_MODE_2|SYSCFG_MEMRMP_MEM_MODE_1))

#endif                                                                                                                           

   
                                                       
                                                                              
                                    
                                             
                                               
                 
                                       
        
                                        
                 
                                           
        
                 
                                           
        
                 
                                           
        
                 
                                           
        
    
#define __HAL_SYSCFG_GET_BOOT_MODE()           READ_BIT(SYSCFG->MEMRMP, SYSCFG_MEMRMP_MEM_MODE)

                                                            
                                                                                               
                                                                   
    
#define __HAL_SYSCFG_SRAM2_WRP_1_31_ENABLE(__SRAM2WRP__)    do {assert_param(IS_SYSCFG_SRAM2WRP_PAGE((__SRAM2WRP__)));\
                                                                SET_BIT(SYSCFG->SWPR, (__SRAM2WRP__));\
                                                            }while(0)

#if defined(SYSCFG_SWPR2_PAGE63)
                                                             
                                                                                                     
                                                                   
    
#define __HAL_SYSCFG_SRAM2_WRP_32_63_ENABLE(__SRAM2WRP__)   do {assert_param(IS_SYSCFG_SRAM2WRP_PAGE((__SRAM2WRP__)));\
                                                                SET_BIT(SYSCFG->SWPR2, (__SRAM2WRP__));\
                                                            }while(0)
#endif                          

                                                             
                                                                
    
#define __HAL_SYSCFG_SRAM2_WRP_UNLOCK()      do {SYSCFG->SKR = 0xCA;\
                                                 SYSCFG->SKR = 0x53;\
                                                }while(0)

                       
                                                                                       
    
#define __HAL_SYSCFG_SRAM2_ERASE()           SET_BIT(SYSCFG->SCSR, SYSCFG_SCSR_SRAM2ER)

                                                               
                                                                                     
    
#define __HAL_SYSCFG_FPU_INTERRUPT_ENABLE(__INTERRUPT__)    do {assert_param(IS_SYSCFG_FPU_INTERRUPT((__INTERRUPT__)));\
                                                                SET_BIT(SYSCFG->CFGR1, (__INTERRUPT__));\
                                                            }while(0)

#define __HAL_SYSCFG_FPU_INTERRUPT_DISABLE(__INTERRUPT__)   do {assert_param(IS_SYSCFG_FPU_INTERRUPT((__INTERRUPT__)));\
                                                                CLEAR_BIT(SYSCFG->CFGR1, (__INTERRUPT__));\
                                                            }while(0)

                                  
                                                                                                        
                                                                                          
    
#define __HAL_SYSCFG_BREAK_ECC_LOCK()        SET_BIT(SYSCFG->CFGR2, SYSCFG_CFGR2_ECCL)

                                               
                                                                                                                 
                                                                                          
    
#define __HAL_SYSCFG_BREAK_LOCKUP_LOCK()     SET_BIT(SYSCFG->CFGR2, SYSCFG_CFGR2_CLL)

                                  
                                                                                                                                          
                                                                                          
    
#define __HAL_SYSCFG_BREAK_PVD_LOCK()        SET_BIT(SYSCFG->CFGR2, SYSCFG_CFGR2_PVDL)

                                           
                                                                                                    
                                                                                     
    
#define __HAL_SYSCFG_BREAK_SRAM2PARITY_LOCK()  SET_BIT(SYSCFG->CFGR2, SYSCFG_CFGR2_SPL)

                                            
                                                  
                                                              
                                                                       
                                                                   
                                                      
    
#define __HAL_SYSCFG_GET_FLAG(__FLAG__)      ((((((__FLAG__) == SYSCFG_SCSR_SRAM2BSY)? SYSCFG->SCSR : SYSCFG->CFGR2) & (__FLAG__))!= 0U) ? 1U : 0U)

                                                                
    
#define __HAL_SYSCFG_CLEAR_FLAG()            SET_BIT(SYSCFG->CFGR2, SYSCFG_CFGR2_SPF)

                                                                   
                                                               
                                                                                             
                                                                                             
                                                                                             
                                                                                             
    
#define __HAL_SYSCFG_FASTMODEPLUS_ENABLE(__FASTMODEPLUS__)  do {assert_param(IS_SYSCFG_FASTMODEPLUS((__FASTMODEPLUS__)));\
                                                                SET_BIT(SYSCFG->CFGR1, (__FASTMODEPLUS__));\
                                                               }while(0)

#define __HAL_SYSCFG_FASTMODEPLUS_DISABLE(__FASTMODEPLUS__) do {assert_param(IS_SYSCFG_FASTMODEPLUS((__FASTMODEPLUS__)));\
                                                                CLEAR_BIT(SYSCFG->CFGR1, (__FASTMODEPLUS__));\
                                                               }while(0)

   
      
    

   
      
    

                                                                                
                                                   
      
    

                                                         
      
    

#define IS_SYSCFG_FPU_INTERRUPT(__INTERRUPT__) ((((__INTERRUPT__) & SYSCFG_IT_FPU_IOC) == SYSCFG_IT_FPU_IOC) || \
                                                (((__INTERRUPT__) & SYSCFG_IT_FPU_DZC) == SYSCFG_IT_FPU_DZC) || \
                                                (((__INTERRUPT__) & SYSCFG_IT_FPU_UFC) == SYSCFG_IT_FPU_UFC) || \
                                                (((__INTERRUPT__) & SYSCFG_IT_FPU_OFC) == SYSCFG_IT_FPU_OFC) || \
                                                (((__INTERRUPT__) & SYSCFG_IT_FPU_IDC) == SYSCFG_IT_FPU_IDC) || \
                                                (((__INTERRUPT__) & SYSCFG_IT_FPU_IXC) == SYSCFG_IT_FPU_IXC))

#define IS_SYSCFG_BREAK_CONFIG(__CONFIG__) (((__CONFIG__) == SYSCFG_BREAK_ECC)           || \
                                            ((__CONFIG__) == SYSCFG_BREAK_PVD)           || \
                                            ((__CONFIG__) == SYSCFG_BREAK_SRAM2_PARITY)  || \
                                            ((__CONFIG__) == SYSCFG_BREAK_LOCKUP))

#define IS_SYSCFG_SRAM2WRP_PAGE(__PAGE__)   (((__PAGE__) > 0U) && ((__PAGE__) <= 0xFFFFFFFFUL))

#if defined(VREFBUF)
#define IS_SYSCFG_VREFBUF_VOLTAGE_SCALE(__SCALE__)  (((__SCALE__) == SYSCFG_VREFBUF_VOLTAGE_SCALE0) || \
                                                     ((__SCALE__) == SYSCFG_VREFBUF_VOLTAGE_SCALE1))

#define IS_SYSCFG_VREFBUF_HIGH_IMPEDANCE(__VALUE__)  (((__VALUE__) == SYSCFG_VREFBUF_HIGH_IMPEDANCE_DISABLE) || \
                                                      ((__VALUE__) == SYSCFG_VREFBUF_HIGH_IMPEDANCE_ENABLE))

#define IS_SYSCFG_VREFBUF_TRIMMING(__VALUE__)  (((__VALUE__) > 0U) && ((__VALUE__) <= VREFBUF_CCR_TRIM))
#endif              

#if defined(SYSCFG_FASTMODEPLUS_PB8) && defined(SYSCFG_FASTMODEPLUS_PB9)
#define IS_SYSCFG_FASTMODEPLUS(__PIN__) ((((__PIN__) & SYSCFG_FASTMODEPLUS_PB6) == SYSCFG_FASTMODEPLUS_PB6) || \
                                         (((__PIN__) & SYSCFG_FASTMODEPLUS_PB7) == SYSCFG_FASTMODEPLUS_PB7) || \
                                         (((__PIN__) & SYSCFG_FASTMODEPLUS_PB8) == SYSCFG_FASTMODEPLUS_PB8) || \
                                         (((__PIN__) & SYSCFG_FASTMODEPLUS_PB9) == SYSCFG_FASTMODEPLUS_PB9))
#elif defined(SYSCFG_FASTMODEPLUS_PB8)
#define IS_SYSCFG_FASTMODEPLUS(__PIN__) ((((__PIN__) & SYSCFG_FASTMODEPLUS_PB6) == SYSCFG_FASTMODEPLUS_PB6) || \
                                         (((__PIN__) & SYSCFG_FASTMODEPLUS_PB7) == SYSCFG_FASTMODEPLUS_PB7) || \
                                         (((__PIN__) & SYSCFG_FASTMODEPLUS_PB8) == SYSCFG_FASTMODEPLUS_PB8))
#elif defined(SYSCFG_FASTMODEPLUS_PB9)
#define IS_SYSCFG_FASTMODEPLUS(__PIN__) ((((__PIN__) & SYSCFG_FASTMODEPLUS_PB6) == SYSCFG_FASTMODEPLUS_PB6) || \
                                         (((__PIN__) & SYSCFG_FASTMODEPLUS_PB7) == SYSCFG_FASTMODEPLUS_PB7) || \
                                         (((__PIN__) & SYSCFG_FASTMODEPLUS_PB9) == SYSCFG_FASTMODEPLUS_PB9))
#else
#define IS_SYSCFG_FASTMODEPLUS(__PIN__) ((((__PIN__) & SYSCFG_FASTMODEPLUS_PB6) == SYSCFG_FASTMODEPLUS_PB6) || \
                                         (((__PIN__) & SYSCFG_FASTMODEPLUS_PB7) == SYSCFG_FASTMODEPLUS_PB7))
#endif
   
      
    

   
      
    

                                                                                

                                      
      
    
extern __IO uint32_t uwTick;
extern uint32_t uwTickPrio;
extern HAL_TickFreqTypeDef uwTickFreq;
   
      
    

                                                                                

                                      
      
    

                                             
      
    

                                                                                  
HAL_StatusTypeDef HAL_Init(void);
HAL_StatusTypeDef HAL_DeInit(void);
void              HAL_MspInit(void);
void              HAL_MspDeInit(void);
HAL_StatusTypeDef HAL_InitTick (uint32_t TickPriority);

   
      
    

                                             
      
    

                                                                                  
void               HAL_IncTick(void);
void               HAL_Delay(uint32_t Delay);
uint32_t           HAL_GetTick(void);
uint32_t           HAL_GetTickPrio(void);
HAL_StatusTypeDef  HAL_SetTickFreq(HAL_TickFreqTypeDef Freq);
HAL_TickFreqTypeDef HAL_GetTickFreq(void);
void               HAL_SuspendTick(void);
void               HAL_ResumeTick(void);
uint32_t           HAL_GetHalVersion(void);
uint32_t           HAL_GetREVID(void);
uint32_t           HAL_GetDEVID(void);
uint32_t           HAL_GetUIDw0(void);
uint32_t           HAL_GetUIDw1(void);
uint32_t           HAL_GetUIDw2(void);

   
      
    

                                             
      
    

                                                                                  
void              HAL_DBGMCU_EnableDBGSleepMode(void);
void              HAL_DBGMCU_DisableDBGSleepMode(void);
void              HAL_DBGMCU_EnableDBGStopMode(void);
void              HAL_DBGMCU_DisableDBGStopMode(void);
void              HAL_DBGMCU_EnableDBGStandbyMode(void);
void              HAL_DBGMCU_DisableDBGStandbyMode(void);

   
      
    

                                             
      
    

                                                                                  
void              HAL_SYSCFG_SRAM2Erase(void);
void              HAL_SYSCFG_EnableMemorySwappingBank(void);
void              HAL_SYSCFG_DisableMemorySwappingBank(void);

#if defined(VREFBUF)
void              HAL_SYSCFG_VREFBUF_VoltageScalingConfig(uint32_t VoltageScaling);
void              HAL_SYSCFG_VREFBUF_HighImpedanceConfig(uint32_t Mode);
void              HAL_SYSCFG_VREFBUF_TrimmingConfig(uint32_t TrimmingValue);
HAL_StatusTypeDef HAL_SYSCFG_EnableVREFBUF(void);
void              HAL_SYSCFG_DisableVREFBUF(void);
#endif              

void              HAL_SYSCFG_EnableIOAnalogSwitchBooster(void);
void              HAL_SYSCFG_DisableIOAnalogSwitchBooster(void);

   
      
    

   
      
    

   
      
    

   
      
    

#ifdef __cplusplus
}
#endif

#endif                      
