/**
  ******************************************************************************
  * @file    stm32l4xx_hal.c
  * @author  MCD Application Team
  * @brief   HAL module driver.
  *          This is the common part of the HAL initialization
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
    The common HAL driver contains a set of generic and common APIs that can be
    used by the PPP peripheral drivers and the user to start using the HAL.
    [..]
    The HAL contains two APIs' categories:
         (+) Common HAL APIs
         (+) Services HAL APIs

  @endverbatim
  ******************************************************************************
  */

                                                                                
#include "stm32l4xx_hal.h"

                                    
      
    

                     
                            
      
    

#ifdef HAL_MODULE_ENABLED

                                                                                
                                                                                
   
                                             
     
#define STM32L4XX_HAL_VERSION_MAIN   (0x01UL)                             
#define STM32L4XX_HAL_VERSION_SUB1   (0x0DUL)                             
#define STM32L4XX_HAL_VERSION_SUB2   (0x06UL)                             
#define STM32L4XX_HAL_VERSION_RC     (0x00U)                                 
#define STM32L4XX_HAL_VERSION        ((STM32L4XX_HAL_VERSION_MAIN  << 24U)\
                                      |(STM32L4XX_HAL_VERSION_SUB1 << 16U)\
                                      |(STM32L4XX_HAL_VERSION_SUB2 << 8U)\
                                      |(STM32L4XX_HAL_VERSION_RC))

#if defined(VREFBUF)
#define VREFBUF_TIMEOUT_VALUE     10U                                
#endif              

                                                                                
#define SYSCFG_OFFSET             (SYSCFG_BASE - PERIPH_BASE)
                             
                                       
#define MEMRMP_OFFSET             SYSCFG_OFFSET
#define FB_MODE_BitNumber         8U
#define FB_MODE_BB                (PERIPH_BB_BASE + (MEMRMP_OFFSET * 32U) + (FB_MODE_BitNumber * 4U))

                          
                                       
#define SCSR_OFFSET               (SYSCFG_OFFSET + 0x18U)
#define BRER_BitNumber            0U
#define SCSR_SRAM2ER_BB           (PERIPH_BB_BASE + (SCSR_OFFSET * 32U) + (BRER_BitNumber * 4U))

                                                                                
                                                                                
                                                                                

                                                                                

                                                           
      
    
__IO uint32_t uwTick;
uint32_t uwTickPrio = (1UL << __NVIC_PRIO_BITS);                       
HAL_TickFreqTypeDef uwTickFreq = HAL_TICK_FREQ_DEFAULT;            
   
      
    

                                                                                

                                                           
      
    

                                                                                          
                                                            
  
         
                                                                                
                                                                        
                                                                                
                                                      
                                                                                   
                              
                                               
                                                                               
                                  
                                                                              
                                                                                    
                                                                                    
                                                                                 
                                           
                                                                                       
                                                                                     
                                                                
                                                                                 
                                                                               
                                                                                      
                                                                                   
                                        
                                                                               
                                                                                        
            
      
    

   
                                                                          
                                                                                 
                                                                                                
                                
   
                                                                                            
                                    
   
                                                                                                    
                                                                                
                                                                                            
                                                                                                   
                                                                
   
                      
    
HAL_StatusTypeDef HAL_Init(void)
{
  HAL_StatusTypeDef  status = HAL_OK;

                                                               
                                                               
                                                               
                                                               
                                                               
#if (INSTRUCTION_CACHE_ENABLE == 0)
   __HAL_FLASH_INSTRUCTION_CACHE_DISABLE();
#endif                               

#if (DATA_CACHE_ENABLE == 0)
   __HAL_FLASH_DATA_CACHE_DISABLE();
#endif                        

#if (PREFETCH_ENABLE != 0)
  __HAL_FLASH_PREFETCH_BUFFER_ENABLE();
#endif                      

                                    
  HAL_NVIC_SetPriorityGrouping(NVIC_PRIORITYGROUP_4);

                                                                                                 
  if (HAL_InitTick(TICK_INT_PRIORITY) != HAL_OK)
  {
    status = HAL_ERROR;
  }
  else
  {
                                     
    HAL_MspInit();
  }

                              
  return status;
}

   
                                                                                 
                                    
                      
    
HAL_StatusTypeDef HAL_DeInit(void)
{
                                
  __HAL_RCC_APB1_FORCE_RESET();
  __HAL_RCC_APB1_RELEASE_RESET();

  __HAL_RCC_APB2_FORCE_RESET();
  __HAL_RCC_APB2_RELEASE_RESET();

  __HAL_RCC_AHB1_FORCE_RESET();
  __HAL_RCC_AHB1_RELEASE_RESET();

  __HAL_RCC_AHB2_FORCE_RESET();
  __HAL_RCC_AHB2_RELEASE_RESET();

  __HAL_RCC_AHB3_FORCE_RESET();
  __HAL_RCC_AHB3_RELEASE_RESET();

                                      
  HAL_MspDeInit();

                              
  return HAL_OK;
}

   
                               
                
    
__weak void HAL_MspInit(void)
{
                                                                              
                                                                 
     
}

   
                                 
                
    
__weak void HAL_MspDeInit(void)
{
                                                                              
                                                                   
     
}

   
                                                                
                                                                               
                                   
                                                                                  
                                                                                                  
                                                                                  
                                                                      
                                                                                    
                                                                             
                                                                                          
                                                                                 
                                       
                                                 
                      
    
__weak HAL_StatusTypeDef HAL_InitTick(uint32_t TickPriority)
{
  HAL_StatusTypeDef  status = HAL_OK;

                                                                                                            
  if ((uint32_t)uwTickFreq != 0U)
  {
                                                                 
    if (HAL_SYSTICK_Config(SystemCoreClock / (1000U / (uint32_t)uwTickFreq)) == 0U)
    {
                                              
      if (TickPriority < (1UL << __NVIC_PRIO_BITS))
      {
        HAL_NVIC_SetPriority(SysTick_IRQn, TickPriority, 0U);
        uwTickPrio = TickPriority;
      }
      else
      {
        status = HAL_ERROR;
      }
    }
    else
    {
      status = HAL_ERROR;
    }
  }
  else
  {
    status = HAL_ERROR;
  }

                              
  return status;
}

   
      
    

                                                                 
                                   
  
         
                                                                                
                                                       
                                                                                
                                                      
                                             
                                                 
                                                
                                               
                                        
                                   
                                            

            
      
    

   
                                                                          
                                         
                                                                              
                         
                                                                               
                                      
                
    
__weak void HAL_IncTick(void)
{
  uwTick += (uint32_t)uwTickFreq;
}

   
                                               
                                                                                
                                       
                      
    
__weak uint32_t HAL_GetTick(void)
{
  return uwTick;
}

   
                                                 
                         
    
uint32_t HAL_GetTickPrio(void)
{
  return uwTickPrio;
}

   
                             
                              
                      
    
HAL_StatusTypeDef HAL_SetTickFreq(HAL_TickFreqTypeDef Freq)
{
  HAL_StatusTypeDef status  = HAL_OK;
  HAL_TickFreqTypeDef prevTickFreq;

  if (uwTickFreq != Freq)
  {
                                      
    prevTickFreq = uwTickFreq;

                                                                  
    uwTickFreq = Freq;

                                  
    status = HAL_InitTick(uwTickPrio);
    if (status != HAL_OK)
    {
                                           
      uwTickFreq = prevTickFreq;
    }
  }

  return status;
}

   
                                 
                           
                                              
    
HAL_TickFreqTypeDef HAL_GetTickFreq(void)
{
  return uwTickFreq;
}

   
                                                                       
                                   
                                                                                   
                                                                                  
                         
                                                                                
                                       
                                                                   
                
    
__weak void HAL_Delay(uint32_t Delay)
{
  uint32_t tickstart = HAL_GetTick();
  uint32_t wait = Delay;

                                             
  if (wait < HAL_MAX_DELAY)
  {
    wait += (uint32_t)uwTickFreq;
  }

  while ((HAL_GetTick() - tickstart) < wait)
  {
  }
}

   
                                  
                                                                                         
                                                                                       
                                                                                 
                       
                                                                                
                                       
                
    
__weak void HAL_SuspendTick(void)
{
                                 
  SysTick->CTRL &= ~SysTick_CTRL_TICKINT_Msk;
}

   
                                 
                                                                                         
                                                                                      
                                                                                
                     
                                                                                
                                       
                
    
__weak void HAL_ResumeTick(void)
{
                                
  SysTick->CTRL  |= SysTick_CTRL_TICKINT_Msk;
}

   
                                    
                                                               
    
uint32_t HAL_GetHalVersion(void)
{
  return STM32L4XX_HAL_VERSION;
}

   
                                                  
                                      
    
uint32_t HAL_GetREVID(void)
{
  return((DBGMCU->IDCODE & DBGMCU_IDCODE_REV_ID) >> 16);
}

   
                                         
                             
    
uint32_t HAL_GetDEVID(void)
{
  return(DBGMCU->IDCODE & DBGMCU_IDCODE_DEV_ID);
}

   
                                                                                        
                             
    
uint32_t HAL_GetUIDw0(void)
{
  return(READ_REG(*((uint32_t *)UID_BASE)));
}

   
                                                                                         
                             
    
uint32_t HAL_GetUIDw1(void)
{
  return(READ_REG(*((uint32_t *)(UID_BASE + 4U))));
}

   
                                                                                        
                             
    
uint32_t HAL_GetUIDw2(void)
{
  return(READ_REG(*((uint32_t *)(UID_BASE + 8U))));
}

   
      
    

                                                               
                                 
  
         
                                                                                
                                                     
                                                                                
                                                      
                                                       
                                                                    
                                                         

            
      
    

   
                                                      
                
    
void HAL_DBGMCU_EnableDBGSleepMode(void)
{
  SET_BIT(DBGMCU->CR, DBGMCU_CR_DBG_SLEEP);
}

   
                                                       
                
    
void HAL_DBGMCU_DisableDBGSleepMode(void)
{
  CLEAR_BIT(DBGMCU->CR, DBGMCU_CR_DBG_SLEEP);
}

   
                                                                   
                
    
void HAL_DBGMCU_EnableDBGStopMode(void)
{
  SET_BIT(DBGMCU->CR, DBGMCU_CR_DBG_STOP);
}

   
                                                                    
                
    
void HAL_DBGMCU_DisableDBGStopMode(void)
{
  CLEAR_BIT(DBGMCU->CR, DBGMCU_CR_DBG_STOP);
}

   
                                                        
                
    
void HAL_DBGMCU_EnableDBGStandbyMode(void)
{
  SET_BIT(DBGMCU->CR, DBGMCU_CR_DBG_STANDBY);
}

   
                                                         
                
    
void HAL_DBGMCU_DisableDBGStandbyMode(void)
{
  CLEAR_BIT(DBGMCU->CR, DBGMCU_CR_DBG_STANDBY);
}

   
      
    

                                                                              
                                                
  
         
                                                                                
                                                                    
                                                                                
                                                      
                                                
                                                         
                                                
                                                     
                                                              

            
      
    

   
                                                   
                                                                       
                                                                                    
                
    
void HAL_SYSCFG_SRAM2Erase(void)
{
                                                      
  SYSCFG->SKR = 0xCA;
  SYSCFG->SKR = 0x53;
                                              
  *(__IO uint32_t *) SCSR_SRAM2ER_BB = 0x00000001UL;
}

   
                                                    
   
                                                                 
   
                                                                      
                                                                            
   
                
    
void HAL_SYSCFG_EnableMemorySwappingBank(void)
{
  *(__IO uint32_t *)FB_MODE_BB = 0x00000001UL;
}

   
                                                     
   
                                                                 
   
                                                                                           
                                                                            
   
                
    
void HAL_SYSCFG_DisableMemorySwappingBank(void)
{

  *(__IO uint32_t *)FB_MODE_BB = 0x00000000UL;
}

#if defined(VREFBUF)
   
                                                                         
                                                                  
                                                               
                                                                            
                                                                                                    
                                                                          
                                                                                                    
                
    
void HAL_SYSCFG_VREFBUF_VoltageScalingConfig(uint32_t VoltageScaling)
{
                            
  assert_param(IS_SYSCFG_VREFBUF_VOLTAGE_SCALE(VoltageScaling));

  MODIFY_REG(VREFBUF->CSR, VREFBUF_CSR_VRS, VoltageScaling);
}

   
                                                                               
                                                  
                                                               
                                                                                                             
                                                                                      
                
    
void HAL_SYSCFG_VREFBUF_HighImpedanceConfig(uint32_t Mode)
{
                            
  assert_param(IS_SYSCFG_VREFBUF_HIGH_IMPEDANCE(Mode));

  MODIFY_REG(VREFBUF->CSR, VREFBUF_CSR_HIZ, Mode);
}

   
                                                                 
                
    
void HAL_SYSCFG_VREFBUF_TrimmingConfig(uint32_t TrimmingValue)
{
                            
  assert_param(IS_SYSCFG_VREFBUF_TRIMMING(TrimmingValue));

  MODIFY_REG(VREFBUF->CCR, VREFBUF_CCR_TRIM, TrimmingValue);
}

   
                                                                   
                              
    
HAL_StatusTypeDef HAL_SYSCFG_EnableVREFBUF(void)
{
  uint32_t  tickstart;

  SET_BIT(VREFBUF->CSR, VREFBUF_CSR_ENVR);

                     
  tickstart = HAL_GetTick();

                         
  while(READ_BIT(VREFBUF->CSR, VREFBUF_CSR_VRR) == 0U)
  {
    if((HAL_GetTick() - tickstart) > VREFBUF_TIMEOUT_VALUE)
    {
      return HAL_TIMEOUT;
    }
  }

  return HAL_OK;
}

   
                                                                    
   
                
    
void HAL_SYSCFG_DisableVREFBUF(void)
{
  CLEAR_BIT(VREFBUF->CSR, VREFBUF_CSR_ENVR);
}
#endif              

   
                                                        
   
                
    
void HAL_SYSCFG_EnableIOAnalogSwitchBooster(void)
{
  SET_BIT(SYSCFG->CFGR1, SYSCFG_CFGR1_BOOSTEN);
}

   
                                                         
   
                
    
void HAL_SYSCFG_DisableIOAnalogSwitchBooster(void)
{
  CLEAR_BIT(SYSCFG->CFGR1, SYSCFG_CFGR1_BOOSTEN);
}

   
      
    

   
      
    

#endif                         
   
      
    

   
      
    
