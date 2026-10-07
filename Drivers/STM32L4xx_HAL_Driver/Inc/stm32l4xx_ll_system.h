/**
  ******************************************************************************
  * @file    stm32l4xx_ll_system.h
  * @author  MCD Application Team
  * @brief   Header file of SYSTEM LL module.
  *
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
  @verbatim
  ==============================================================================
                     ##### How to use this driver #####
  ==============================================================================
    [..]
    The LL SYSTEM driver contains a set of generic APIs that can be
    used by user:
      (+) Some of the FLASH features need to be handled in the SYSTEM file.
      (+) Access to DBGCMU registers
      (+) Access to SYSCFG registers
      (+) Access to VREFBUF registers

  @endverbatim
  ******************************************************************************
  */

                                                                                
#ifndef STM32L4xx_LL_SYSTEM_H
#define STM32L4xx_LL_SYSTEM_H

#ifdef __cplusplus
extern "C" {
#endif

                                                                                
#include "stm32l4xx.h"

                                   
      
    

#if defined (FLASH) || defined (SYSCFG) || defined (DBGMCU) || defined (VREFBUF)

                              
      
    

                                                                                
                                                                                

                                                                                
                                                                  
      
    

#define LL_EXTI_REGISTER_PINPOS_SHFT        16U                                                               

   
                                          
   
#define FLASH_PDKEY1                  0x04152637U                              
#define FLASH_PDKEY2                  0xFAFBFCFDU                                                   
                                                                                               

   
      
    

                                                                                

                                                                                
                                                                                
                                                                    
      
    

                                             
    
  
#define LL_SYSCFG_REMAP_FLASH              0x00000000U                                                                                                      
#define LL_SYSCFG_REMAP_SYSTEMFLASH        SYSCFG_MEMRMP_MEM_MODE_0                                                                                         
#define LL_SYSCFG_REMAP_SRAM               (SYSCFG_MEMRMP_MEM_MODE_1 | SYSCFG_MEMRMP_MEM_MODE_0)                                                            
#if defined(FMC_Bank1_R)
#define LL_SYSCFG_REMAP_FMC                SYSCFG_MEMRMP_MEM_MODE_1                                                                                         
#endif                  
#define LL_SYSCFG_REMAP_QUADSPI            (SYSCFG_MEMRMP_MEM_MODE_2 | SYSCFG_MEMRMP_MEM_MODE_1)                                                            
   
      
    

#if defined(SYSCFG_MEMRMP_FB_MODE)
                                                    
      
    
#define LL_SYSCFG_BANKMODE_BANK1           0x00000000U                                                                              
                                                                                                                                         
#define LL_SYSCFG_BANKMODE_BANK2           SYSCFG_MEMRMP_FB_MODE                                                                    
                                                                                                                                         
   
      
    

#endif                            
                                                                   
      
    
#define LL_SYSCFG_I2C_FASTMODEPLUS_PB6     SYSCFG_CFGR1_I2C_PB6_FMP                                            
#define LL_SYSCFG_I2C_FASTMODEPLUS_PB7     SYSCFG_CFGR1_I2C_PB7_FMP                                            
#if defined(SYSCFG_CFGR1_I2C_PB8_FMP)
#define LL_SYSCFG_I2C_FASTMODEPLUS_PB8     SYSCFG_CFGR1_I2C_PB8_FMP                                            
#endif                               
#if defined(SYSCFG_CFGR1_I2C_PB9_FMP)
#define LL_SYSCFG_I2C_FASTMODEPLUS_PB9     SYSCFG_CFGR1_I2C_PB9_FMP                                            
#endif                               
#define LL_SYSCFG_I2C_FASTMODEPLUS_I2C1    SYSCFG_CFGR1_I2C1_FMP                                               
#if defined(I2C2)
#define LL_SYSCFG_I2C_FASTMODEPLUS_I2C2    SYSCFG_CFGR1_I2C2_FMP                                               
#endif           
#define LL_SYSCFG_I2C_FASTMODEPLUS_I2C3    SYSCFG_CFGR1_I2C3_FMP                                               
#if defined(I2C4)
#define LL_SYSCFG_I2C_FASTMODEPLUS_I2C4    SYSCFG_CFGR1_I2C4_FMP                                               
#endif           
   
      
    

                                                     
      
    
#define LL_SYSCFG_EXTI_PORTA               0U                                                                  
#define LL_SYSCFG_EXTI_PORTB               1U                                                                  
#define LL_SYSCFG_EXTI_PORTC               2U                                                                  
#define LL_SYSCFG_EXTI_PORTD               3U                                                                  
#define LL_SYSCFG_EXTI_PORTE               4U                                                                  
#if defined(GPIOF)
#define LL_SYSCFG_EXTI_PORTF               5U                                                                  
#endif            
#if defined(GPIOG)
#define LL_SYSCFG_EXTI_PORTG               6U                                                                  
#endif            
#define LL_SYSCFG_EXTI_PORTH               7U                                                                  
#if defined(GPIOI)
#define LL_SYSCFG_EXTI_PORTI               8U                                                                  
#endif            
   
      
    

                                                     
      
    
#define LL_SYSCFG_EXTI_LINE0               (uint32_t)((0x000FU << LL_EXTI_REGISTER_PINPOS_SHFT) | 0U)                                       
#define LL_SYSCFG_EXTI_LINE1               (uint32_t)((0x00F0U << LL_EXTI_REGISTER_PINPOS_SHFT) | 0U)                                       
#define LL_SYSCFG_EXTI_LINE2               (uint32_t)((0x0F00U << LL_EXTI_REGISTER_PINPOS_SHFT) | 0U)                                       
#define LL_SYSCFG_EXTI_LINE3               (uint32_t)((0xF000U << LL_EXTI_REGISTER_PINPOS_SHFT) | 0U)                                       
#define LL_SYSCFG_EXTI_LINE4               (uint32_t)((0x000FU << LL_EXTI_REGISTER_PINPOS_SHFT) | 1U)                                       
#define LL_SYSCFG_EXTI_LINE5               (uint32_t)((0x00F0U << LL_EXTI_REGISTER_PINPOS_SHFT) | 1U)                                       
#define LL_SYSCFG_EXTI_LINE6               (uint32_t)((0x0F00U << LL_EXTI_REGISTER_PINPOS_SHFT) | 1U)                                       
#define LL_SYSCFG_EXTI_LINE7               (uint32_t)((0xF000U << LL_EXTI_REGISTER_PINPOS_SHFT) | 1U)                                       
#define LL_SYSCFG_EXTI_LINE8               (uint32_t)((0x000FU << LL_EXTI_REGISTER_PINPOS_SHFT) | 2U)                                       
#define LL_SYSCFG_EXTI_LINE9               (uint32_t)((0x00F0U << LL_EXTI_REGISTER_PINPOS_SHFT) | 2U)                                       
#define LL_SYSCFG_EXTI_LINE10              (uint32_t)((0x0F00U << LL_EXTI_REGISTER_PINPOS_SHFT) | 2U)                                       
#define LL_SYSCFG_EXTI_LINE11              (uint32_t)((0xF000U << LL_EXTI_REGISTER_PINPOS_SHFT) | 2U)                                       
#define LL_SYSCFG_EXTI_LINE12              (uint32_t)((0x000FU << LL_EXTI_REGISTER_PINPOS_SHFT) | 3U)                                       
#define LL_SYSCFG_EXTI_LINE13              (uint32_t)((0x00F0U << LL_EXTI_REGISTER_PINPOS_SHFT) | 3U)                                       
#define LL_SYSCFG_EXTI_LINE14              (uint32_t)((0x0F00U << LL_EXTI_REGISTER_PINPOS_SHFT) | 3U)                                       
#define LL_SYSCFG_EXTI_LINE15              (uint32_t)((0xF000U << LL_EXTI_REGISTER_PINPOS_SHFT) | 3U)                                       
   
      
    

                                                      
      
    
#define LL_SYSCFG_TIMBREAK_ECC             SYSCFG_CFGR2_ECCL                                             
                                                                                                                                   
#define LL_SYSCFG_TIMBREAK_PVD             SYSCFG_CFGR2_PVDL                                           
                                                                                                   
                                                                                                                                   
#define LL_SYSCFG_TIMBREAK_SRAM2_PARITY    SYSCFG_CFGR2_SPL                                                       
                                                                                                                                   
#define LL_SYSCFG_TIMBREAK_LOCKUP          SYSCFG_CFGR2_CLL                                                       
                                                                                                                                   
   
      
    

                                                    
      
    
#define LL_SYSCFG_SRAM2WRP_PAGE0           SYSCFG_SWPR_PAGE0                                        
#define LL_SYSCFG_SRAM2WRP_PAGE1           SYSCFG_SWPR_PAGE1                                        
#define LL_SYSCFG_SRAM2WRP_PAGE2           SYSCFG_SWPR_PAGE2                                        
#define LL_SYSCFG_SRAM2WRP_PAGE3           SYSCFG_SWPR_PAGE3                                        
#define LL_SYSCFG_SRAM2WRP_PAGE4           SYSCFG_SWPR_PAGE4                                        
#define LL_SYSCFG_SRAM2WRP_PAGE5           SYSCFG_SWPR_PAGE5                                        
#define LL_SYSCFG_SRAM2WRP_PAGE6           SYSCFG_SWPR_PAGE6                                        
#define LL_SYSCFG_SRAM2WRP_PAGE7           SYSCFG_SWPR_PAGE7                                        
#define LL_SYSCFG_SRAM2WRP_PAGE8           SYSCFG_SWPR_PAGE8                                        
#define LL_SYSCFG_SRAM2WRP_PAGE9           SYSCFG_SWPR_PAGE9                                        
#define LL_SYSCFG_SRAM2WRP_PAGE10          SYSCFG_SWPR_PAGE10                                       
#define LL_SYSCFG_SRAM2WRP_PAGE11          SYSCFG_SWPR_PAGE11                                       
#define LL_SYSCFG_SRAM2WRP_PAGE12          SYSCFG_SWPR_PAGE12                                       
#define LL_SYSCFG_SRAM2WRP_PAGE13          SYSCFG_SWPR_PAGE13                                       
#define LL_SYSCFG_SRAM2WRP_PAGE14          SYSCFG_SWPR_PAGE14                                       
#define LL_SYSCFG_SRAM2WRP_PAGE15          SYSCFG_SWPR_PAGE15                                       
#if defined(SYSCFG_SWPR_PAGE31)
#define LL_SYSCFG_SRAM2WRP_PAGE16          SYSCFG_SWPR_PAGE16                                       
#define LL_SYSCFG_SRAM2WRP_PAGE17          SYSCFG_SWPR_PAGE17                                       
#define LL_SYSCFG_SRAM2WRP_PAGE18          SYSCFG_SWPR_PAGE18                                       
#define LL_SYSCFG_SRAM2WRP_PAGE19          SYSCFG_SWPR_PAGE19                                       
#define LL_SYSCFG_SRAM2WRP_PAGE20          SYSCFG_SWPR_PAGE20                                       
#define LL_SYSCFG_SRAM2WRP_PAGE21          SYSCFG_SWPR_PAGE21                                       
#define LL_SYSCFG_SRAM2WRP_PAGE22          SYSCFG_SWPR_PAGE22                                       
#define LL_SYSCFG_SRAM2WRP_PAGE23          SYSCFG_SWPR_PAGE23                                       
#define LL_SYSCFG_SRAM2WRP_PAGE24          SYSCFG_SWPR_PAGE24                                       
#define LL_SYSCFG_SRAM2WRP_PAGE25          SYSCFG_SWPR_PAGE25                                       
#define LL_SYSCFG_SRAM2WRP_PAGE26          SYSCFG_SWPR_PAGE26                                       
#define LL_SYSCFG_SRAM2WRP_PAGE27          SYSCFG_SWPR_PAGE27                                       
#define LL_SYSCFG_SRAM2WRP_PAGE28          SYSCFG_SWPR_PAGE28                                       
#define LL_SYSCFG_SRAM2WRP_PAGE29          SYSCFG_SWPR_PAGE29                                       
#define LL_SYSCFG_SRAM2WRP_PAGE30          SYSCFG_SWPR_PAGE30                                       
#define LL_SYSCFG_SRAM2WRP_PAGE31          SYSCFG_SWPR_PAGE31                                       
#endif                         
#if defined(SYSCFG_SWPR2_PAGE63)
#define LL_SYSCFG_SRAM2WRP_PAGE32          SYSCFG_SWPR2_PAGE32                                       
#define LL_SYSCFG_SRAM2WRP_PAGE33          SYSCFG_SWPR2_PAGE33                                       
#define LL_SYSCFG_SRAM2WRP_PAGE34          SYSCFG_SWPR2_PAGE34                                       
#define LL_SYSCFG_SRAM2WRP_PAGE35          SYSCFG_SWPR2_PAGE35                                       
#define LL_SYSCFG_SRAM2WRP_PAGE36          SYSCFG_SWPR2_PAGE36                                       
#define LL_SYSCFG_SRAM2WRP_PAGE37          SYSCFG_SWPR2_PAGE37                                       
#define LL_SYSCFG_SRAM2WRP_PAGE38          SYSCFG_SWPR2_PAGE38                                       
#define LL_SYSCFG_SRAM2WRP_PAGE39          SYSCFG_SWPR2_PAGE39                                       
#define LL_SYSCFG_SRAM2WRP_PAGE40          SYSCFG_SWPR2_PAGE40                                       
#define LL_SYSCFG_SRAM2WRP_PAGE41          SYSCFG_SWPR2_PAGE41                                       
#define LL_SYSCFG_SRAM2WRP_PAGE42          SYSCFG_SWPR2_PAGE42                                       
#define LL_SYSCFG_SRAM2WRP_PAGE43          SYSCFG_SWPR2_PAGE43                                       
#define LL_SYSCFG_SRAM2WRP_PAGE44          SYSCFG_SWPR2_PAGE44                                       
#define LL_SYSCFG_SRAM2WRP_PAGE45          SYSCFG_SWPR2_PAGE45                                       
#define LL_SYSCFG_SRAM2WRP_PAGE46          SYSCFG_SWPR2_PAGE46                                       
#define LL_SYSCFG_SRAM2WRP_PAGE47          SYSCFG_SWPR2_PAGE47                                       
#define LL_SYSCFG_SRAM2WRP_PAGE48          SYSCFG_SWPR2_PAGE48                                       
#define LL_SYSCFG_SRAM2WRP_PAGE49          SYSCFG_SWPR2_PAGE49                                       
#define LL_SYSCFG_SRAM2WRP_PAGE50          SYSCFG_SWPR2_PAGE50                                       
#define LL_SYSCFG_SRAM2WRP_PAGE51          SYSCFG_SWPR2_PAGE51                                       
#define LL_SYSCFG_SRAM2WRP_PAGE52          SYSCFG_SWPR2_PAGE52                                       
#define LL_SYSCFG_SRAM2WRP_PAGE53          SYSCFG_SWPR2_PAGE53                                       
#define LL_SYSCFG_SRAM2WRP_PAGE54          SYSCFG_SWPR2_PAGE54                                       
#define LL_SYSCFG_SRAM2WRP_PAGE55          SYSCFG_SWPR2_PAGE55                                       
#define LL_SYSCFG_SRAM2WRP_PAGE56          SYSCFG_SWPR2_PAGE56                                       
#define LL_SYSCFG_SRAM2WRP_PAGE57          SYSCFG_SWPR2_PAGE57                                       
#define LL_SYSCFG_SRAM2WRP_PAGE58          SYSCFG_SWPR2_PAGE58                                       
#define LL_SYSCFG_SRAM2WRP_PAGE59          SYSCFG_SWPR2_PAGE59                                       
#define LL_SYSCFG_SRAM2WRP_PAGE60          SYSCFG_SWPR2_PAGE60                                       
#define LL_SYSCFG_SRAM2WRP_PAGE61          SYSCFG_SWPR2_PAGE61                                       
#define LL_SYSCFG_SRAM2WRP_PAGE62          SYSCFG_SWPR2_PAGE62                                       
#define LL_SYSCFG_SRAM2WRP_PAGE63          SYSCFG_SWPR2_PAGE63                                       
#endif                          
   
      
    

                                                            
      
    
#define LL_DBGMCU_TRACE_NONE               0x00000000U                                                                                    
#define LL_DBGMCU_TRACE_ASYNCH             DBGMCU_CR_TRACE_IOEN                                                                              
#define LL_DBGMCU_TRACE_SYNCH_SIZE1        (DBGMCU_CR_TRACE_IOEN | DBGMCU_CR_TRACE_MODE_0)                                                                             
#define LL_DBGMCU_TRACE_SYNCH_SIZE2        (DBGMCU_CR_TRACE_IOEN | DBGMCU_CR_TRACE_MODE_1)                                                                             
#define LL_DBGMCU_TRACE_SYNCH_SIZE4        (DBGMCU_CR_TRACE_IOEN | DBGMCU_CR_TRACE_MODE)                                                                               
   
      
    

                                                                     
      
    
#define LL_DBGMCU_APB1_GRP1_TIM2_STOP      DBGMCU_APB1FZR1_DBG_TIM2_STOP                                                                      
#if defined(TIM3)
#define LL_DBGMCU_APB1_GRP1_TIM3_STOP      DBGMCU_APB1FZR1_DBG_TIM3_STOP                                                                      
#endif           
#if defined(TIM4)
#define LL_DBGMCU_APB1_GRP1_TIM4_STOP      DBGMCU_APB1FZR1_DBG_TIM4_STOP                                                                      
#endif           
#if defined(TIM5)
#define LL_DBGMCU_APB1_GRP1_TIM5_STOP      DBGMCU_APB1FZR1_DBG_TIM5_STOP                                                                      
#endif           
#define LL_DBGMCU_APB1_GRP1_TIM6_STOP      DBGMCU_APB1FZR1_DBG_TIM6_STOP                                                                      
#if defined(TIM7)
#define LL_DBGMCU_APB1_GRP1_TIM7_STOP      DBGMCU_APB1FZR1_DBG_TIM7_STOP                                                                      
#endif           
#define LL_DBGMCU_APB1_GRP1_RTC_STOP       DBGMCU_APB1FZR1_DBG_RTC_STOP                                                                          
#define LL_DBGMCU_APB1_GRP1_WWDG_STOP      DBGMCU_APB1FZR1_DBG_WWDG_STOP                                                                              
#define LL_DBGMCU_APB1_GRP1_IWDG_STOP      DBGMCU_APB1FZR1_DBG_IWDG_STOP                                                                                   
#define LL_DBGMCU_APB1_GRP1_I2C1_STOP      DBGMCU_APB1FZR1_DBG_I2C1_STOP                                          
#if defined(I2C2)
#define LL_DBGMCU_APB1_GRP1_I2C2_STOP      DBGMCU_APB1FZR1_DBG_I2C2_STOP                                          
#endif           
#define LL_DBGMCU_APB1_GRP1_I2C3_STOP      DBGMCU_APB1FZR1_DBG_I2C3_STOP                                          
#define LL_DBGMCU_APB1_GRP1_CAN_STOP       DBGMCU_APB1FZR1_DBG_CAN_STOP                                                 
#if defined(CAN2)
#define LL_DBGMCU_APB1_GRP1_CAN2_STOP      DBGMCU_APB1FZR1_DBG_CAN2_STOP                                                 
#endif           
#define LL_DBGMCU_APB1_GRP1_LPTIM1_STOP    DBGMCU_APB1FZR1_DBG_LPTIM1_STOP                                                                      
   
      
    

                                                                     
      
    
#if defined(I2C4)
#define LL_DBGMCU_APB1_GRP2_I2C4_STOP      DBGMCU_APB1FZR2_DBG_I2C4_STOP                                          
#endif           
#define LL_DBGMCU_APB1_GRP2_LPTIM2_STOP    DBGMCU_APB1FZR2_DBG_LPTIM2_STOP                                                                      
   
      
    

                                                                     
      
    
#define LL_DBGMCU_APB2_GRP1_TIM1_STOP      DBGMCU_APB2FZ_DBG_TIM1_STOP                                                                        
#if defined(TIM8)
#define LL_DBGMCU_APB2_GRP1_TIM8_STOP      DBGMCU_APB2FZ_DBG_TIM8_STOP                                                                        
#endif           
#define LL_DBGMCU_APB2_GRP1_TIM15_STOP     DBGMCU_APB2FZ_DBG_TIM15_STOP                                                                        
#define LL_DBGMCU_APB2_GRP1_TIM16_STOP     DBGMCU_APB2FZ_DBG_TIM16_STOP                                                                        
#if defined(TIM17)
#define LL_DBGMCU_APB2_GRP1_TIM17_STOP     DBGMCU_APB2FZ_DBG_TIM17_STOP                                                                        
#endif            
   
      
    

#if defined(VREFBUF)
                                                  
      
    
#define LL_VREFBUF_VOLTAGE_SCALE0          ((uint32_t)0x00000000)                                              
#define LL_VREFBUF_VOLTAGE_SCALE1          VREFBUF_CSR_VRS                                                     
   
      
    
#endif              

                                                
      
    
#define LL_FLASH_LATENCY_0                 FLASH_ACR_LATENCY_0WS                                
#define LL_FLASH_LATENCY_1                 FLASH_ACR_LATENCY_1WS                               
#define LL_FLASH_LATENCY_2                 FLASH_ACR_LATENCY_2WS                                
#define LL_FLASH_LATENCY_3                 FLASH_ACR_LATENCY_3WS                                  
#define LL_FLASH_LATENCY_4                 FLASH_ACR_LATENCY_4WS                                 
#if defined(FLASH_ACR_LATENCY_5WS)
#define LL_FLASH_LATENCY_5                 FLASH_ACR_LATENCY_5WS                                
#define LL_FLASH_LATENCY_6                 FLASH_ACR_LATENCY_6WS                               
#define LL_FLASH_LATENCY_7                 FLASH_ACR_LATENCY_7WS                                  
#define LL_FLASH_LATENCY_8                 FLASH_ACR_LATENCY_8WS                                  
#define LL_FLASH_LATENCY_9                 FLASH_ACR_LATENCY_9WS                                 
#define LL_FLASH_LATENCY_10                FLASH_ACR_LATENCY_10WS                               
#define LL_FLASH_LATENCY_11                FLASH_ACR_LATENCY_11WS                                  
#define LL_FLASH_LATENCY_12                FLASH_ACR_LATENCY_12WS                                  
#define LL_FLASH_LATENCY_13                FLASH_ACR_LATENCY_13WS                                    
#define LL_FLASH_LATENCY_14                FLASH_ACR_LATENCY_14WS                                    
#define LL_FLASH_LATENCY_15                FLASH_ACR_LATENCY_15WS                                   
#endif
   
      
    

   
      
    

                                                                                

                                                                                
                                                                    
      
    

                                        
      
    

   
                                                    
                                                                
                                                                     
                                           
                                                 
                                          
                                             
                                             
   
                                                
                
    
__STATIC_INLINE void LL_SYSCFG_SetRemapMemory(uint32_t Memory)
{
  MODIFY_REG(SYSCFG->MEMRMP, SYSCFG_MEMRMP_MEM_MODE, Memory);
}

   
                                                    
                                                                
                                                              
                                           
                                                 
                                          
                                             
                                             
   
                                                
    
__STATIC_INLINE uint32_t LL_SYSCFG_GetRemapMemory(void)
{
  return (uint32_t)(READ_BIT(SYSCFG->MEMRMP, SYSCFG_MEMRMP_MEM_MODE));
}

#if defined(SYSCFG_MEMRMP_FB_MODE)
   
                                                               
                                                                  
                                                                   
                                              
                                              
                
    
__STATIC_INLINE void LL_SYSCFG_SetFlashBankMode(uint32_t Bank)
{
  MODIFY_REG(SYSCFG->MEMRMP, SYSCFG_MEMRMP_FB_MODE, Bank);
}

   
                                                            
                                                                  
                                                              
                                              
                                              
    
__STATIC_INLINE uint32_t LL_SYSCFG_GetFlashBankMode(void)
{
  return (uint32_t)(READ_BIT(SYSCFG->MEMRMP, SYSCFG_MEMRMP_FB_MODE));
}
#endif                            

   
                                       
                                                               
                
    
__STATIC_INLINE void LL_SYSCFG_EnableFirewall(void)
{
  CLEAR_BIT(SYSCFG->CFGR1, SYSCFG_CFGR1_FWDIS);
}

   
                                                          
                                                                  
                                  
    
__STATIC_INLINE uint32_t LL_SYSCFG_IsEnabledFirewall(void)
{
  return !(READ_BIT(SYSCFG->CFGR1, SYSCFG_CFGR1_FWDIS) == SYSCFG_CFGR1_FWDIS);
}

   
                                                     
                                                                             
                                                                          
                                                                          
                                                                             
                                                        
                                                                    
                                                                    
                                                                 
                           
                                                                    
                
    
__STATIC_INLINE void LL_SYSCFG_EnableAnalogBooster(void)
{
  SET_BIT(SYSCFG->CFGR1, SYSCFG_CFGR1_BOOSTEN);
}

   
                                                      
                                                                             
                                                                          
                                                                          
                                                                             
                                                        
                                                                    
                                                                    
                                                                 
                           
                                                                     
                
    
__STATIC_INLINE void LL_SYSCFG_DisableAnalogBooster(void)
{
  CLEAR_BIT(SYSCFG->CFGR1, SYSCFG_CFGR1_BOOSTEN);
}

   
                                                             
                                                                     
                                                                   
                                                                                           
                                                    
                                                    
                                                        
                                                        
                                                     
                                                         
                                                     
                                                         
   
                                                
                
    
__STATIC_INLINE void LL_SYSCFG_EnableFastModePlus(uint32_t ConfigFastModePlus)
{
  SET_BIT(SYSCFG->CFGR1, ConfigFastModePlus);
}

   
                                                              
                                                                      
                                                                    
                                                                                           
                                                    
                                                    
                                                        
                                                        
                                                     
                                                         
                                                     
                                                         
   
                                                
                
    
__STATIC_INLINE void LL_SYSCFG_DisableFastModePlus(uint32_t ConfigFastModePlus)
{
  CLEAR_BIT(SYSCFG->CFGR1, ConfigFastModePlus);
}

   
                                                                  
                                                                 
                
    
__STATIC_INLINE void LL_SYSCFG_EnableIT_FPU_IOC(void)
{
  SET_BIT(SYSCFG->CFGR1, SYSCFG_CFGR1_FPU_IE_0);
}

   
                                                               
                                                                 
                
    
__STATIC_INLINE void LL_SYSCFG_EnableIT_FPU_DZC(void)
{
  SET_BIT(SYSCFG->CFGR1, SYSCFG_CFGR1_FPU_IE_1);
}

   
                                                          
                                                                 
                
    
__STATIC_INLINE void LL_SYSCFG_EnableIT_FPU_UFC(void)
{
  SET_BIT(SYSCFG->CFGR1, SYSCFG_CFGR1_FPU_IE_2);
}

   
                                                         
                                                                 
                
    
__STATIC_INLINE void LL_SYSCFG_EnableIT_FPU_OFC(void)
{
  SET_BIT(SYSCFG->CFGR1, SYSCFG_CFGR1_FPU_IE_3);
}

   
                                                               
                                                                 
                
    
__STATIC_INLINE void LL_SYSCFG_EnableIT_FPU_IDC(void)
{
  SET_BIT(SYSCFG->CFGR1, SYSCFG_CFGR1_FPU_IE_4);
}

   
                                                        
                                                                 
                
    
__STATIC_INLINE void LL_SYSCFG_EnableIT_FPU_IXC(void)
{
  SET_BIT(SYSCFG->CFGR1, SYSCFG_CFGR1_FPU_IE_5);
}

   
                                                                   
                                                                  
                
    
__STATIC_INLINE void LL_SYSCFG_DisableIT_FPU_IOC(void)
{
  CLEAR_BIT(SYSCFG->CFGR1, SYSCFG_CFGR1_FPU_IE_0);
}

   
                                                                
                                                                  
                
    
__STATIC_INLINE void LL_SYSCFG_DisableIT_FPU_DZC(void)
{
  CLEAR_BIT(SYSCFG->CFGR1, SYSCFG_CFGR1_FPU_IE_1);
}

   
                                                           
                                                                  
                
    
__STATIC_INLINE void LL_SYSCFG_DisableIT_FPU_UFC(void)
{
  CLEAR_BIT(SYSCFG->CFGR1, SYSCFG_CFGR1_FPU_IE_2);
}

   
                                                          
                                                                  
                
    
__STATIC_INLINE void LL_SYSCFG_DisableIT_FPU_OFC(void)
{
  CLEAR_BIT(SYSCFG->CFGR1, SYSCFG_CFGR1_FPU_IE_3);
}

   
                                                                
                                                                  
                
    
__STATIC_INLINE void LL_SYSCFG_DisableIT_FPU_IDC(void)
{
  CLEAR_BIT(SYSCFG->CFGR1, SYSCFG_CFGR1_FPU_IE_4);
}

   
                                                         
                                                                  
                
    
__STATIC_INLINE void LL_SYSCFG_DisableIT_FPU_IXC(void)
{
  CLEAR_BIT(SYSCFG->CFGR1, SYSCFG_CFGR1_FPU_IE_5);
}

   
                                                                                                   
                                                                    
                                  
    
__STATIC_INLINE uint32_t LL_SYSCFG_IsEnabledIT_FPU_IOC(void)
{
  return (READ_BIT(SYSCFG->CFGR1, SYSCFG_CFGR1_FPU_IE_0) == (SYSCFG_CFGR1_FPU_IE_0));
}

   
                                                                                                
                                                                    
                                  
    
__STATIC_INLINE uint32_t LL_SYSCFG_IsEnabledIT_FPU_DZC(void)
{
  return (READ_BIT(SYSCFG->CFGR1, SYSCFG_CFGR1_FPU_IE_1) == (SYSCFG_CFGR1_FPU_IE_1));
}

   
                                                                                           
                                                                    
                                  
    
__STATIC_INLINE uint32_t LL_SYSCFG_IsEnabledIT_FPU_UFC(void)
{
  return (READ_BIT(SYSCFG->CFGR1, SYSCFG_CFGR1_FPU_IE_2) == (SYSCFG_CFGR1_FPU_IE_2));
}

   
                                                                                          
                                                                    
                                  
    
__STATIC_INLINE uint32_t LL_SYSCFG_IsEnabledIT_FPU_OFC(void)
{
  return (READ_BIT(SYSCFG->CFGR1, SYSCFG_CFGR1_FPU_IE_3) == (SYSCFG_CFGR1_FPU_IE_3));
}

   
                                                                                                
                                                                    
                                  
    
__STATIC_INLINE uint32_t LL_SYSCFG_IsEnabledIT_FPU_IDC(void)
{
  return (READ_BIT(SYSCFG->CFGR1, SYSCFG_CFGR1_FPU_IE_4) == (SYSCFG_CFGR1_FPU_IE_4));
}

   
                                                                                         
                                                                    
                                  
    
__STATIC_INLINE uint32_t LL_SYSCFG_IsEnabledIT_FPU_IXC(void)
{
  return (READ_BIT(SYSCFG->CFGR1, SYSCFG_CFGR1_FPU_IE_5) == (SYSCFG_CFGR1_FPU_IE_5));
}

   
                                                                   
                                                                  
                                                                  
                                                                  
                                                                
                                                                   
                                          
                                          
                                          
                                          
                                          
                                              
                                              
                                          
                                              
   
                                                
                                                                   
                                          
                                          
                                          
                                          
                                          
                                          
                                          
                                          
                                          
                                          
                                           
                                           
                                           
                                           
                                           
                                           
                
    
__STATIC_INLINE void LL_SYSCFG_SetEXTISource(uint32_t Port, uint32_t Line)
{
  MODIFY_REG(SYSCFG->EXTICR[Line & 0x03U], (Line >> LL_EXTI_REGISTER_PINPOS_SHFT), Port << POSITION_VAL((Line >> LL_EXTI_REGISTER_PINPOS_SHFT)));
}

   
                                                             
                                                                  
                                                                  
                                                                  
                                                                
                                                                   
                                          
                                          
                                          
                                          
                                          
                                          
                                          
                                          
                                          
                                          
                                           
                                           
                                           
                                           
                                           
                                           
                                                              
                                          
                                          
                                          
                                          
                                          
                                              
                                              
                                          
                                              
   
                                                
    
__STATIC_INLINE uint32_t LL_SYSCFG_GetEXTISource(uint32_t Line)
{
  return (uint32_t)(READ_BIT(SYSCFG->EXTICR[Line & 0x03U], (Line >> LL_EXTI_REGISTER_PINPOS_SHFT)) >> POSITION_VAL(Line >> LL_EXTI_REGISTER_PINPOS_SHFT));
}

   
                                                                                    
                                                                   
                                                                                  
                                                                                    
                               
                                                                 
                
    
__STATIC_INLINE void LL_SYSCFG_EnableSRAM2Erase(void)
{
                                              
  SET_BIT(SYSCFG->SCSR, SYSCFG_SCSR_SRAM2ER);
}

   
                                                      
                                                                    
                                  
    
__STATIC_INLINE uint32_t LL_SYSCFG_IsSRAM2EraseOngoing(void)
{
  return (READ_BIT(SYSCFG->SCSR, SYSCFG_SCSR_SRAM2BSY) == (SYSCFG_SCSR_SRAM2BSY));
}

   
                                                           
                                                                    
                                                                    
                                                                    
                                                                  
                                                                              
                                            
                                            
                                                     
                                               
                
    
__STATIC_INLINE void LL_SYSCFG_SetTIMBreakInputs(uint32_t Break)
{
  MODIFY_REG(SYSCFG->CFGR2, SYSCFG_CFGR2_CLL | SYSCFG_CFGR2_SPL | SYSCFG_CFGR2_PVDL | SYSCFG_CFGR2_ECCL, Break);
}

   
                                                           
                                                                    
                                                                    
                                                                    
                                                                  
                                                                               
                                            
                                            
                                                     
                                               
    
__STATIC_INLINE uint32_t LL_SYSCFG_GetTIMBreakInputs(void)
{
  return (uint32_t)(READ_BIT(SYSCFG->CFGR2, SYSCFG_CFGR2_CLL | SYSCFG_CFGR2_SPL | SYSCFG_CFGR2_PVDL | SYSCFG_CFGR2_ECCL));
}

   
                                                
                                                                
                                  
    
__STATIC_INLINE uint32_t LL_SYSCFG_IsActiveFlag_SP(void)
{
  return (READ_BIT(SYSCFG->CFGR2, SYSCFG_CFGR2_SPF) == (SYSCFG_CFGR2_SPF));
}

   
                                         
                                                             
                
    
__STATIC_INLINE void LL_SYSCFG_ClearFlag_SP(void)
{
  SET_BIT(SYSCFG->CFGR2, SYSCFG_CFGR2_SPF);
}

   
                                                                         
                                                            
                                                                       
                                                                                 
                                              
                                              
                                              
                                              
                                              
                                              
                                              
                                              
                                              
                                              
                                               
                                               
                                               
                                               
                                               
                                               
                                                   
                                                   
                                                   
                                                   
                                                   
                                                   
                                                   
                                                   
                                                   
                                                   
                                                   
                                                   
                                                   
                                                   
                                                   
                                                   
   
                                                
                
    
                   
#define LL_SYSCFG_EnableSRAM2PageWRP    LL_SYSCFG_EnableSRAM2PageWRP_0_31
__STATIC_INLINE void LL_SYSCFG_EnableSRAM2PageWRP_0_31(uint32_t SRAM2WRP)
{
  SET_BIT(SYSCFG->SWPR, SRAM2WRP);
}

#if defined(SYSCFG_SWPR2_PAGE63)
   
                                                                          
                                                            
                                                                         
                                                                                 
                                                   
                                                   
                                                   
                                                   
                                                   
                                                   
                                                   
                                                   
                                                   
                                                   
                                                   
                                                   
                                                   
                                                   
                                                   
                                                   
                                                   
                                                   
                                                   
                                                   
                                                   
                                                   
                                                   
                                                   
                                                   
                                                   
                                                   
                                                   
                                                   
                                                   
                                                   
                                                   
   
                                                
                
    
__STATIC_INLINE void LL_SYSCFG_EnableSRAM2PageWRP_32_63(uint32_t SRAM2WRP)
{
  SET_BIT(SYSCFG->SWPR2, SRAM2WRP);
}
#endif                          

   
                                                           
                                                             
                
    
__STATIC_INLINE void LL_SYSCFG_LockSRAM2WRP(void)
{
                                                            
  WRITE_REG(SYSCFG->SKR, 0x00);
}

   
                                                             
                                                               
                
    
__STATIC_INLINE void LL_SYSCFG_UnlockSRAM2WRP(void)
{
                                                      
  WRITE_REG(SYSCFG->SKR, 0xCA);
  WRITE_REG(SYSCFG->SKR, 0x53);
}

   
      
    


                                        
      
    

   
                                        
                                                             
                                                                                      
    
__STATIC_INLINE uint32_t LL_DBGMCU_GetDeviceID(void)
{
  return (uint32_t)(READ_BIT(DBGMCU->IDCODE, DBGMCU_IDCODE_DEV_ID));
}

   
                                                 
                                                          
                                                               
                                                            
    
__STATIC_INLINE uint32_t LL_DBGMCU_GetRevisionID(void)
{
  return (uint32_t)(READ_BIT(DBGMCU->IDCODE, DBGMCU_IDCODE_REV_ID) >> DBGMCU_IDCODE_REV_ID_Pos);
}

   
                                                     
                                                                   
                
    
__STATIC_INLINE void LL_DBGMCU_EnableDBGSleepMode(void)
{
  SET_BIT(DBGMCU->CR, DBGMCU_CR_DBG_SLEEP);
}

   
                                                      
                                                                    
                
    
__STATIC_INLINE void LL_DBGMCU_DisableDBGSleepMode(void)
{
  CLEAR_BIT(DBGMCU->CR, DBGMCU_CR_DBG_SLEEP);
}

   
                                                    
                                                                  
                
    
__STATIC_INLINE void LL_DBGMCU_EnableDBGStopMode(void)
{
  SET_BIT(DBGMCU->CR, DBGMCU_CR_DBG_STOP);
}

   
                                                     
                                                                   
                
    
__STATIC_INLINE void LL_DBGMCU_DisableDBGStopMode(void)
{
  CLEAR_BIT(DBGMCU->CR, DBGMCU_CR_DBG_STOP);
}

   
                                                       
                                                                     
                
    
__STATIC_INLINE void LL_DBGMCU_EnableDBGStandbyMode(void)
{
  SET_BIT(DBGMCU->CR, DBGMCU_CR_DBG_STANDBY);
}

   
                                                        
                                                                      
                
    
__STATIC_INLINE void LL_DBGMCU_DisableDBGStandbyMode(void)
{
  CLEAR_BIT(DBGMCU->CR, DBGMCU_CR_DBG_STANDBY);
}

   
                                            
                                                                        
                                                                      
                                                                            
                                          
                                            
                                                 
                                                 
                                                 
                
    
__STATIC_INLINE void LL_DBGMCU_SetTracePinAssignment(uint32_t PinAssignment)
{
  MODIFY_REG(DBGMCU->CR, DBGMCU_CR_TRACE_IOEN | DBGMCU_CR_TRACE_MODE, PinAssignment);
}

   
                                            
                                                                        
                                                                      
                                                              
                                          
                                            
                                                 
                                                 
                                                 
    
__STATIC_INLINE uint32_t LL_DBGMCU_GetTracePinAssignment(void)
{
  return (uint32_t)(READ_BIT(DBGMCU->CR, DBGMCU_CR_TRACE_IOEN | DBGMCU_CR_TRACE_MODE));
}

   
                                                        
                                                                           
                                                                                
                                                   
                                                       
                                                       
                                                       
                                                   
                                                       
                                                  
                                                   
                                                   
                                                   
                                                       
                                                   
                                                  
                                                       
                                                     
   
                                                 
                
    
__STATIC_INLINE void LL_DBGMCU_APB1_GRP1_FreezePeriph(uint32_t Periphs)
{
  SET_BIT(DBGMCU->APB1FZR1, Periphs);
}

   
                                                        
                                                                           
                                                                                
                                                       
                                                     
   
                                                 
                
    
__STATIC_INLINE void LL_DBGMCU_APB1_GRP2_FreezePeriph(uint32_t Periphs)
{
  SET_BIT(DBGMCU->APB1FZR2, Periphs);
}

   
                                                          
                                                                             
                                                                                
                                                   
                                                       
                                                       
                                                       
                                                   
                                                       
                                                  
                                                   
                                                   
                                                   
                                                       
                                                   
                                                  
                                                       
                                                     
   
                                                 
                
    
__STATIC_INLINE void LL_DBGMCU_APB1_GRP1_UnFreezePeriph(uint32_t Periphs)
{
  CLEAR_BIT(DBGMCU->APB1FZR1, Periphs);
}

   
                                                          
                                                                             
                                                                                
                                                       
                                                     
   
                                                 
                
    
__STATIC_INLINE void LL_DBGMCU_APB1_GRP2_UnFreezePeriph(uint32_t Periphs)
{
  CLEAR_BIT(DBGMCU->APB1FZR2, Periphs);
}

   
                                   
                                                                         
                                                                                
                                                   
                                                       
                                                    
                                                    
                                                        
   
                                                 
                
    
__STATIC_INLINE void LL_DBGMCU_APB2_GRP1_FreezePeriph(uint32_t Periphs)
{
  SET_BIT(DBGMCU->APB2FZ, Periphs);
}

   
                                     
                                                                           
                                                                                
                                                   
                                                       
                                                    
                                                    
                                                        
   
                                                 
                
    
__STATIC_INLINE void LL_DBGMCU_APB2_GRP1_UnFreezePeriph(uint32_t Periphs)
{
  CLEAR_BIT(DBGMCU->APB2FZ, Periphs);
}

   
      
    

#if defined(VREFBUF)
                                          
      
    

   
                                             
                                                        
                
    
__STATIC_INLINE void LL_VREFBUF_Enable(void)
{
  SET_BIT(VREFBUF->CSR, VREFBUF_CSR_ENVR);
}

   
                                              
                                                         
                
    
__STATIC_INLINE void LL_VREFBUF_Disable(void)
{
  CLEAR_BIT(VREFBUF->CSR, VREFBUF_CSR_ENVR);
}

   
                                                              
                                                           
                
    
__STATIC_INLINE void LL_VREFBUF_EnableHIZ(void)
{
  SET_BIT(VREFBUF->CSR, VREFBUF_CSR_HIZ);
}

   
                                                                                                            
                                                            
                
    
__STATIC_INLINE void LL_VREFBUF_DisableHIZ(void)
{
  CLEAR_BIT(VREFBUF->CSR, VREFBUF_CSR_HIZ);
}

   
                                           
                                                                   
                                                                    
                                               
                                               
                
    
__STATIC_INLINE void LL_VREFBUF_SetVoltageScaling(uint32_t Scale)
{
  MODIFY_REG(VREFBUF->CSR, VREFBUF_CSR_VRS, Scale);
}

   
                                           
                                                                   
                                                              
                                               
                                               
    
__STATIC_INLINE uint32_t LL_VREFBUF_GetVoltageScaling(void)
{
  return (uint32_t)(READ_BIT(VREFBUF->CSR, VREFBUF_CSR_VRS));
}

   
                                                      
                                                             
                                  
    
__STATIC_INLINE uint32_t LL_VREFBUF_IsVREFReady(void)
{
  return (READ_BIT(VREFBUF->CSR, VREFBUF_CSR_VRR) == (VREFBUF_CSR_VRR));
}

   
                                                         
                                                             
                              
    
__STATIC_INLINE uint32_t LL_VREFBUF_GetTrimming(void)
{
  return (uint32_t)(READ_BIT(VREFBUF->CCR, VREFBUF_CCR_TRIM));
}

   
                                                                                                      
                                                             
                                    
                
    
__STATIC_INLINE void LL_VREFBUF_SetTrimming(uint32_t Value)
{
  WRITE_REG(VREFBUF->CCR, Value);
}

   
      
    
#endif              

                                      
      
    

   
                             
                                                          
                                                                      
                                        
                                        
                                        
                                        
                                        
                                            
                                            
                                            
                                            
                                            
                                             
                                             
                                             
                                             
                                             
                                             
   
                                                 
                
    
__STATIC_INLINE void LL_FLASH_SetLatency(uint32_t Latency)
{
  MODIFY_REG(FLASH->ACR, FLASH_ACR_LATENCY, Latency);
}

   
                             
                                                          
                                                              
                                        
                                        
                                        
                                        
                                        
                                            
                                            
                                            
                                            
                                            
                                             
                                             
                                             
                                             
                                             
                                             
   
                                                 
    
__STATIC_INLINE uint32_t LL_FLASH_GetLatency(void)
{
  return (uint32_t)(READ_BIT(FLASH->ACR, FLASH_ACR_LATENCY));
}

   
                           
                                                              
                
    
__STATIC_INLINE void LL_FLASH_EnablePrefetch(void)
{
  SET_BIT(FLASH->ACR, FLASH_ACR_PRFTEN);
}

   
                            
                                                               
                
    
__STATIC_INLINE void LL_FLASH_DisablePrefetch(void)
{
  CLEAR_BIT(FLASH->ACR, FLASH_ACR_PRFTEN);
}

   
                                               
                                                                 
                                  
    
__STATIC_INLINE uint32_t LL_FLASH_IsPrefetchEnabled(void)
{
  return (READ_BIT(FLASH->ACR, FLASH_ACR_PRFTEN) == (FLASH_ACR_PRFTEN));
}

   
                                    
                                                               
                
    
__STATIC_INLINE void LL_FLASH_EnableInstCache(void)
{
  SET_BIT(FLASH->ACR, FLASH_ACR_ICEN);
}

   
                                     
                                                                
                
    
__STATIC_INLINE void LL_FLASH_DisableInstCache(void)
{
  CLEAR_BIT(FLASH->ACR, FLASH_ACR_ICEN);
}

   
                             
                                                               
                
    
__STATIC_INLINE void LL_FLASH_EnableDataCache(void)
{
  SET_BIT(FLASH->ACR, FLASH_ACR_DCEN);
}

   
                              
                                                                
                
    
__STATIC_INLINE void LL_FLASH_DisableDataCache(void)
{
  CLEAR_BIT(FLASH->ACR, FLASH_ACR_DCEN);
}

   
                                          
                                                                         
                                                                    
                
    
__STATIC_INLINE void LL_FLASH_EnableInstCacheReset(void)
{
  SET_BIT(FLASH->ACR, FLASH_ACR_ICRST);
}

   
                                           
                                                                     
                
    
__STATIC_INLINE void LL_FLASH_DisableInstCacheReset(void)
{
  CLEAR_BIT(FLASH->ACR, FLASH_ACR_ICRST);
}

   
                                   
                                                                 
                                                                    
                
    
__STATIC_INLINE void LL_FLASH_EnableDataCacheReset(void)
{
  SET_BIT(FLASH->ACR, FLASH_ACR_DCRST);
}

   
                                    
                                                                     
                
    
__STATIC_INLINE void LL_FLASH_DisableDataCacheReset(void)
{
  CLEAR_BIT(FLASH->ACR, FLASH_ACR_DCRST);
}

   
                                                                              
                                                                                   
                  
                                                               
                                                                                   
                     
                                                                    
                                                                    
                                                                  
                
    
__STATIC_INLINE void LL_FLASH_EnableRunPowerDown(void)
{
                                                                               
                 
  WRITE_REG(FLASH->PDKEYR, FLASH_PDKEY1);
  WRITE_REG(FLASH->PDKEYR, FLASH_PDKEY2);
  SET_BIT(FLASH->ACR, FLASH_ACR_RUN_PD);
}

   
                                                                               
                                                                     
                                                                     
                                                                   
                
    
__STATIC_INLINE void LL_FLASH_DisableRunPowerDown(void)
{
                                                                               
                 
  WRITE_REG(FLASH->PDKEYR, FLASH_PDKEY1);
  WRITE_REG(FLASH->PDKEYR, FLASH_PDKEY2);
  CLEAR_BIT(FLASH->ACR, FLASH_ACR_RUN_PD);
}

   
                                                                             
                                                                                   
                     
                                                                    
                
    
__STATIC_INLINE void LL_FLASH_EnableSleepPowerDown(void)
{
  SET_BIT(FLASH->ACR, FLASH_ACR_SLEEP_PD);
}

   
                                                                              
                                                                     
                
    
__STATIC_INLINE void LL_FLASH_DisableSleepPowerDown(void)
{
  CLEAR_BIT(FLASH->ACR, FLASH_ACR_SLEEP_PD);
}

   
      
    

   
      
    

   
      
    

#endif                                                                                   

   
      
    

#ifdef __cplusplus
}
#endif

#endif                            
