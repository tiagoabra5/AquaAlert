/**
  ******************************************************************************
  * @file    stm32l4xx_hal_flash_ex.c
  * @author  MCD Application Team
  * @brief   Extended FLASH HAL module driver.
  *          This file provides firmware functions to manage the following
  *          functionalities of the FLASH extended peripheral:
  *           + Extended programming operations functions
  *
 @verbatim
 ==============================================================================
                   ##### Flash Extended features #####
  ==============================================================================

  [..] Comparing to other previous devices, the FLASH interface for STM32L4xx
       devices contains the following additional features

       (+) Capacity up to 2 Mbyte with dual bank architecture supporting read-while-write
           capability (RWW)
       (+) Dual bank memory organization
       (+) PCROP protection for all banks

                        ##### How to use this driver #####
 ==============================================================================
  [..] This driver provides functions to configure and program the FLASH memory
       of all STM32L4xx devices. It includes
      (#) Flash Memory Erase functions:
           (++) Lock and Unlock the FLASH interface using HAL_FLASH_Unlock() and
                HAL_FLASH_Lock() functions
           (++) Erase function: Erase page, erase all sectors
           (++) There are two modes of erase :
             (+++) Polling Mode using HAL_FLASHEx_Erase()
             (+++) Interrupt Mode using HAL_FLASHEx_Erase_IT()

      (#) Option Bytes Programming function: Use HAL_FLASHEx_OBProgram() to :
        (++) Set/Reset the write protection
        (++) Set the Read protection Level
        (++) Program the user Option Bytes
        (++) Configure the PCROP protection

      (#) Get Option Bytes Configuration function: Use HAL_FLASHEx_OBGetConfig() to :
        (++) Get the value of a write protection area
        (++) Know if the read protection is activated
        (++) Get the value of the user Option Bytes
        (++) Get the value of a PCROP area

 @endverbatim
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2017 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file in
  * the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  ******************************************************************************
  */

                                                                                
#include "stm32l4xx_hal.h"

                                    
      
    

                             
                                           
      
    

#ifdef HAL_FLASH_MODULE_ENABLED

                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                 
     
   
static void              FLASH_MassErase(uint32_t Banks);
static HAL_StatusTypeDef FLASH_OB_WRPConfig(uint32_t WRPArea, uint32_t WRPStartOffset, uint32_t WRDPEndOffset);
static HAL_StatusTypeDef FLASH_OB_RDPConfig(uint32_t RDPLevel);
static HAL_StatusTypeDef FLASH_OB_UserConfig(uint32_t UserType, uint32_t UserConfig);
static HAL_StatusTypeDef FLASH_OB_PCROPConfig(uint32_t PCROPConfig, uint32_t PCROPStartAddr, uint32_t PCROPEndAddr);
static void              FLASH_OB_GetWRP(uint32_t WRPArea, uint32_t * WRPStartOffset, uint32_t * WRDPEndOffset);
static uint32_t          FLASH_OB_GetRDP(void);
static uint32_t          FLASH_OB_GetUser(void);
static void              FLASH_OB_GetPCROP(uint32_t * PCROPConfig, uint32_t * PCROPStartAddr, uint32_t * PCROPEndAddr);
   
      
    

                                                                               
                                                                   
      
    

                                                                               
                                            
  
         
                                                                                
                                                                    
                                                                                
        
                                                                                     
                                      

            
      
    
   
                                                                           
                                                                               
                                                                   
   
                                                                                 
                                                                                  
                                                 
   
                      
    
HAL_StatusTypeDef HAL_FLASHEx_Erase(FLASH_EraseInitTypeDef *pEraseInit, uint32_t *PageError)
{
  HAL_StatusTypeDef status;
  uint32_t page_index;

                      
  __HAL_LOCK(&pFlash);

                            
  assert_param(IS_FLASH_TYPEERASE(pEraseInit->TypeErase));

                                               
  status = FLASH_WaitForLastOperation((uint32_t)FLASH_TIMEOUT_VALUE);

  if (status == HAL_OK)
  {
    pFlash.ErrorCode = HAL_FLASH_ERROR_NONE;

                                                                              
    if(READ_BIT(FLASH->ACR, FLASH_ACR_ICEN) != 0U)
    {
      if(READ_BIT(FLASH->ACR, FLASH_ACR_DCEN) != 0U)
      {
                                 
        __HAL_FLASH_DATA_CACHE_DISABLE();
        pFlash.CacheToReactivate = FLASH_CACHE_ICACHE_DCACHE_ENABLED;
      }
      else
      {
        pFlash.CacheToReactivate = FLASH_CACHE_ICACHE_ENABLED;
      }
    }
    else if(READ_BIT(FLASH->ACR, FLASH_ACR_DCEN) != 0U)
    {
                               
      __HAL_FLASH_DATA_CACHE_DISABLE();
      pFlash.CacheToReactivate = FLASH_CACHE_DCACHE_ENABLED;
    }
    else
    {
      pFlash.CacheToReactivate = FLASH_CACHE_DISABLED;
    }

    if (pEraseInit->TypeErase == FLASH_TYPEERASE_MASSERASE)
    {
                                 
      FLASH_MassErase(pEraseInit->Banks);

                                                   
      status = FLASH_WaitForLastOperation((uint32_t)FLASH_TIMEOUT_VALUE);

#if defined (STM32L471xx) || defined (STM32L475xx) || defined (STM32L476xx) || defined (STM32L485xx) || defined (STM32L486xx) || \
    defined (STM32L496xx) || defined (STM32L4A6xx) || \
    defined (STM32L4P5xx) || defined (STM32L4Q5xx) || \
    defined (STM32L4R5xx) || defined (STM32L4R7xx) || defined (STM32L4R9xx) || defined (STM32L4S5xx) || defined (STM32L4S7xx) || defined (STM32L4S9xx)
                                                                               
      CLEAR_BIT(FLASH->CR, (FLASH_CR_MER1 | FLASH_CR_MER2));
#else
                                                                     
      CLEAR_BIT(FLASH->CR, (FLASH_CR_MER1));
#endif
    }
    else
    {
                                              
      *PageError = 0xFFFFFFFFU;

      for(page_index = pEraseInit->Page; page_index < (pEraseInit->Page + pEraseInit->NbPages); page_index++)
      {
        FLASH_PageErase(page_index, pEraseInit->Banks);

                                                     
        status = FLASH_WaitForLastOperation((uint32_t)FLASH_TIMEOUT_VALUE);

                                                                      
        CLEAR_BIT(FLASH->CR, (FLASH_CR_PER | FLASH_CR_PNB));

        if (status != HAL_OK)
        {
                                                                                    
          *PageError = page_index;
          break;
        }
      }
    }

                                                             
    FLASH_FlushCaches();
  }

                        
  __HAL_UNLOCK(&pFlash);

  return status;
}

   
                                                                                                  
                                                                          
                                                                   
   
                      
    
HAL_StatusTypeDef HAL_FLASHEx_Erase_IT(FLASH_EraseInitTypeDef *pEraseInit)
{
  HAL_StatusTypeDef status = HAL_OK;

                      
  __HAL_LOCK(&pFlash);

                            
  assert_param(IS_FLASH_TYPEERASE(pEraseInit->TypeErase));

  pFlash.ErrorCode = HAL_FLASH_ERROR_NONE;

                                                                            
  if(READ_BIT(FLASH->ACR, FLASH_ACR_ICEN) != 0U)
  {
    if(READ_BIT(FLASH->ACR, FLASH_ACR_DCEN) != 0U)
    {
                               
      __HAL_FLASH_DATA_CACHE_DISABLE();
      pFlash.CacheToReactivate = FLASH_CACHE_ICACHE_DCACHE_ENABLED;
    }
    else
    {
      pFlash.CacheToReactivate = FLASH_CACHE_ICACHE_ENABLED;
    }
  }
  else if(READ_BIT(FLASH->ACR, FLASH_ACR_DCEN) != 0U)
  {
                             
    __HAL_FLASH_DATA_CACHE_DISABLE();
    pFlash.CacheToReactivate = FLASH_CACHE_DCACHE_ENABLED;
  }
  else
  {
    pFlash.CacheToReactivate = FLASH_CACHE_DISABLED;
  }

                                                    
  __HAL_FLASH_ENABLE_IT(FLASH_IT_EOP | FLASH_IT_OPERR);

  pFlash.Bank = pEraseInit->Banks;

  if (pEraseInit->TypeErase == FLASH_TYPEERASE_MASSERASE)
  {
                               
    pFlash.ProcedureOnGoing = FLASH_PROC_MASS_ERASE;
    FLASH_MassErase(pEraseInit->Banks);
  }
  else
  {
                                  
    pFlash.ProcedureOnGoing = FLASH_PROC_PAGE_ERASE;
    pFlash.NbPagesToErase = pEraseInit->NbPages;
    pFlash.Page = pEraseInit->Page;

                                       
    FLASH_PageErase(pEraseInit->Page, pEraseInit->Banks);
  }

  return status;
}

   
                                 
                                                                   
                                                                       
   
                      
    
HAL_StatusTypeDef HAL_FLASHEx_OBProgram(FLASH_OBProgramInitTypeDef *pOBInit)
{
  HAL_StatusTypeDef status = HAL_OK;

                      
  __HAL_LOCK(&pFlash);

                            
  assert_param(IS_OPTIONBYTE(pOBInit->OptionType));

  pFlash.ErrorCode = HAL_FLASH_ERROR_NONE;

                                      
  if((pOBInit->OptionType & OPTIONBYTE_WRP) != 0U)
  {
                                                            
    if(FLASH_OB_WRPConfig(pOBInit->WRPArea, pOBInit->WRPStartOffset, pOBInit->WRPEndOffset) != HAL_OK)
    {
      status = HAL_ERROR;
    }

  }

                                     
  if((pOBInit->OptionType & OPTIONBYTE_RDP) != 0U)
  {
                                             
    if(FLASH_OB_RDPConfig(pOBInit->RDPLevel) != HAL_OK)
    {
      status = HAL_ERROR;
    }
  }

                          
  if((pOBInit->OptionType & OPTIONBYTE_USER) != 0U)
  {
                                         
    if(FLASH_OB_UserConfig(pOBInit->USERType, pOBInit->USERConfig) != HAL_OK)
    {
      status = HAL_ERROR;
    }
  }

                           
  if((pOBInit->OptionType & OPTIONBYTE_PCROP) != 0U)
  {
    if (pOBInit->PCROPStartAddr != pOBInit->PCROPEndAddr)
    {
                                                             
      if(FLASH_OB_PCROPConfig(pOBInit->PCROPConfig, pOBInit->PCROPStartAddr, pOBInit->PCROPEndAddr) != HAL_OK)
      {
        status = HAL_ERROR;
      }
    }
  }

                        
  __HAL_UNLOCK(&pFlash);

  return status;
}

   
                                               
                                                                                
                                               
                                                                                
                                                                                               
   
                
    
void HAL_FLASHEx_OBGetConfig(FLASH_OBProgramInitTypeDef *pOBInit)
{
  pOBInit->OptionType = (OPTIONBYTE_RDP | OPTIONBYTE_USER);

#if defined (STM32L471xx) || defined (STM32L475xx) || defined (STM32L476xx) || defined (STM32L485xx) || defined (STM32L486xx) || \
    defined (STM32L496xx) || defined (STM32L4A6xx) || \
    defined (STM32L4P5xx) || defined (STM32L4Q5xx) || \
    defined (STM32L4R5xx) || defined (STM32L4R7xx) || defined (STM32L4R9xx) || defined (STM32L4S5xx) || defined (STM32L4S7xx) || defined (STM32L4S9xx)
  if((pOBInit->WRPArea == OB_WRPAREA_BANK1_AREAA) || (pOBInit->WRPArea == OB_WRPAREA_BANK1_AREAB) ||
     (pOBInit->WRPArea == OB_WRPAREA_BANK2_AREAA) || (pOBInit->WRPArea == OB_WRPAREA_BANK2_AREAB))
#else
  if((pOBInit->WRPArea == OB_WRPAREA_BANK1_AREAA) || (pOBInit->WRPArea == OB_WRPAREA_BANK1_AREAB))
#endif
  {
    pOBInit->OptionType |= OPTIONBYTE_WRP;
                                                   
    FLASH_OB_GetWRP(pOBInit->WRPArea, &(pOBInit->WRPStartOffset), &(pOBInit->WRPEndOffset));
  }

                                 
  pOBInit->RDPLevel = FLASH_OB_GetRDP();

                                 
  pOBInit->USERConfig = FLASH_OB_GetUser();

#if defined (STM32L471xx) || defined (STM32L475xx) || defined (STM32L476xx) || defined (STM32L485xx) || defined (STM32L486xx) || \
    defined (STM32L496xx) || defined (STM32L4A6xx) || \
    defined (STM32L4P5xx) || defined (STM32L4Q5xx) || \
    defined (STM32L4R5xx) || defined (STM32L4R7xx) || defined (STM32L4R9xx) || defined (STM32L4S5xx) || defined (STM32L4S7xx) || defined (STM32L4S9xx)
  if((pOBInit->PCROPConfig == FLASH_BANK_1) || (pOBInit->PCROPConfig == FLASH_BANK_2))
#else
  if(pOBInit->PCROPConfig == FLASH_BANK_1)
#endif
  {
    pOBInit->OptionType |= OPTIONBYTE_PCROP;
                                                     
    FLASH_OB_GetPCROP(&(pOBInit->PCROPConfig), &(pOBInit->PCROPStartAddr), &(pOBInit->PCROPEndAddr));
  }
}

   
      
    

#if defined (FLASH_CFGR_LVEN)
                                                                                         
                                                      
  
         
                                                                                
                                                                     
                                                                                
        
                                                                                     
                            

            
      
    

   
                                                                                  
                                                              
                                                   
                                                                   
                                                                                        
                                                                                                
   
                                                                                 
                                                                                     
   
                      
    
HAL_StatusTypeDef HAL_FLASHEx_ConfigLVEPin(uint32_t ConfigLVE)
{
  HAL_StatusTypeDef status;

                      
  __HAL_LOCK(&pFlash);

                            
  assert_param(IS_FLASH_LVE_PIN(ConfigLVE));

                                               
  status = FLASH_WaitForLastOperation((uint32_t)FLASH_TIMEOUT_VALUE);

  if (status == HAL_OK)
  {
                                                   
    if (HAL_PWREx_GetVoltageRange() == PWR_REGULATOR_VOLTAGE_SCALE2)
    {
                                  
      MODIFY_REG(FLASH->CFGR, FLASH_CFGR_LVEN, ConfigLVE);

                                                            
      if (READ_BIT(FLASH->CFGR, FLASH_CFGR_LVEN) != ConfigLVE)
      {
        status = HAL_ERROR;
      }
    }
    else
    {
                                                                      
      status = HAL_ERROR;
    }
  }

                        
  __HAL_UNLOCK(&pFlash);

  return status;
}

   
      
    
#endif                      

   
      
    

                                                                                

                                         
      
    
   
                                       
                                    
                                                               
                                                    
                                                    
                                                                 
                
    
static void FLASH_MassErase(uint32_t Banks)
{
#if defined (STM32L4P5xx) || defined (STM32L4Q5xx) || defined (STM32L4R5xx) || defined (STM32L4R7xx) || defined (STM32L4R9xx) || defined (STM32L4S5xx) || defined (STM32L4S7xx) || defined (STM32L4S9xx)
  if (READ_BIT(FLASH->OPTR, FLASH_OPTR_DBANK) != 0U)
#endif
  {
                              
    assert_param(IS_FLASH_BANK(Banks));

                                                            
    if((Banks & FLASH_BANK_1) != 0U)
    {
      SET_BIT(FLASH->CR, FLASH_CR_MER1);
    }

#if defined (STM32L471xx) || defined (STM32L475xx) || defined (STM32L476xx) || defined (STM32L485xx) || defined (STM32L486xx) || \
    defined (STM32L496xx) || defined (STM32L4A6xx) || \
    defined (STM32L4P5xx) || defined (STM32L4Q5xx) || \
    defined (STM32L4R5xx) || defined (STM32L4R7xx) || defined (STM32L4R9xx) || defined (STM32L4S5xx) || defined (STM32L4S7xx) || defined (STM32L4S9xx)
                                                            
    if((Banks & FLASH_BANK_2) != 0U)
    {
      SET_BIT(FLASH->CR, FLASH_CR_MER2);
    }
#endif
  }
#if defined (STM32L4P5xx) || defined (STM32L4Q5xx) || defined (STM32L4R5xx) || defined (STM32L4R7xx) || defined (STM32L4R9xx) || defined (STM32L4S5xx) || defined (STM32L4S7xx) || defined (STM32L4S9xx)
  else
  {
    SET_BIT(FLASH->CR, (FLASH_CR_MER1 | FLASH_CR_MER2));
  }
#endif

                                    
  SET_BIT(FLASH->CR, FLASH_CR_STRT);
}

   
                                                  
                                    
                                                                                              
                                                       
                                                               
                                                             
                                                             
                
    
void FLASH_PageErase(uint32_t Page, uint32_t Banks)
{
                            
  assert_param(IS_FLASH_PAGE(Page));

#if defined (STM32L471xx) || defined (STM32L475xx) || defined (STM32L476xx) || defined (STM32L485xx) || defined (STM32L486xx) || \
    defined (STM32L496xx) || defined (STM32L4A6xx) || \
    defined (STM32L4P5xx) || defined (STM32L4Q5xx) || \
    defined (STM32L4R5xx) || defined (STM32L4R7xx) || defined (STM32L4R9xx) || defined (STM32L4S5xx) || defined (STM32L4S7xx) || defined (STM32L4S9xx)
#if defined (STM32L4P5xx) || defined (STM32L4Q5xx) || defined (STM32L4R5xx) || defined (STM32L4R7xx) || defined (STM32L4R9xx) || defined (STM32L4S5xx) || defined (STM32L4S7xx) || defined (STM32L4S9xx)
  if(READ_BIT(FLASH->OPTR, FLASH_OPTR_DBANK) == 0U)
  {
    CLEAR_BIT(FLASH->CR, FLASH_CR_BKER);
  }
  else
#endif
  {
    assert_param(IS_FLASH_BANK_EXCLUSIVE(Banks));

    if((Banks & FLASH_BANK_1) != 0U)
    {
      CLEAR_BIT(FLASH->CR, FLASH_CR_BKER);
    }
    else
    {
      SET_BIT(FLASH->CR, FLASH_CR_BKER);
    }
  }
#else
                                                      
  UNUSED(Banks);
#endif

                                 
  MODIFY_REG(FLASH->CR, FLASH_CR_PNB, ((Page & 0xFFU) << FLASH_CR_PNB_Pos));
  SET_BIT(FLASH->CR, FLASH_CR_PER);
  SET_BIT(FLASH->CR, FLASH_CR_STRT);
}

   
                                                  
                
    
void FLASH_FlushCaches(void)
{
  FLASH_CacheTypeDef cache = pFlash.CacheToReactivate;

                                
  if((cache == FLASH_CACHE_ICACHE_ENABLED) ||
     (cache == FLASH_CACHE_ICACHE_DCACHE_ENABLED))
  {
                                   
    __HAL_FLASH_INSTRUCTION_CACHE_DISABLE();
                                 
    __HAL_FLASH_INSTRUCTION_CACHE_RESET();
                                  
    __HAL_FLASH_INSTRUCTION_CACHE_ENABLE();
  }

                        
  if((cache == FLASH_CACHE_DCACHE_ENABLED) ||
     (cache == FLASH_CACHE_ICACHE_DCACHE_ENABLED))
  {
                          
    __HAL_FLASH_DATA_CACHE_RESET();
                           
    __HAL_FLASH_DATA_CACHE_ENABLE();
  }

                               
  pFlash.CacheToReactivate = FLASH_CACHE_DISABLED;
}

   
                                                                
   
                                                                              
                                                                                
                                                                              
                                                                            
                                                                             
                                                                        
                                                                          
                                                                   
   
                                                        
                                                               
                                                               
                                                               
                                                                                                              
                                                                                                              
   
                                                                               
                                                                                                  
   
                                                                            
                                                                                                               
   
                      
    
static HAL_StatusTypeDef FLASH_OB_WRPConfig(uint32_t WRPArea, uint32_t WRPStartOffset, uint32_t WRDPEndOffset)
{
  HAL_StatusTypeDef status;

                            
  assert_param(IS_OB_WRPAREA(WRPArea));
  assert_param(IS_FLASH_PAGE(WRPStartOffset));
  assert_param(IS_FLASH_PAGE(WRDPEndOffset));

                                               
  status = FLASH_WaitForLastOperation((uint32_t)FLASH_TIMEOUT_VALUE);

  if(status == HAL_OK)
  {
                                            
    if(WRPArea == OB_WRPAREA_BANK1_AREAA)
    {
      MODIFY_REG(FLASH->WRP1AR, (FLASH_WRP1AR_WRP1A_STRT | FLASH_WRP1AR_WRP1A_END),
                 (WRPStartOffset | (WRDPEndOffset << 16)));
    }
    else if(WRPArea == OB_WRPAREA_BANK1_AREAB)
    {
      MODIFY_REG(FLASH->WRP1BR, (FLASH_WRP1BR_WRP1B_STRT | FLASH_WRP1BR_WRP1B_END),
                 (WRPStartOffset | (WRDPEndOffset << 16)));
    }
#if defined (STM32L471xx) || defined (STM32L475xx) || defined (STM32L476xx) || defined (STM32L485xx) || defined (STM32L486xx) || \
    defined (STM32L496xx) || defined (STM32L4A6xx) || \
    defined (STM32L4P5xx) || defined (STM32L4Q5xx) || \
    defined (STM32L4R5xx) || defined (STM32L4R7xx) || defined (STM32L4R9xx) || defined (STM32L4S5xx) || defined (STM32L4S7xx) || defined (STM32L4S9xx)
    else if(WRPArea == OB_WRPAREA_BANK2_AREAA)
    {
      MODIFY_REG(FLASH->WRP2AR, (FLASH_WRP2AR_WRP2A_STRT | FLASH_WRP2AR_WRP2A_END),
                 (WRPStartOffset | (WRDPEndOffset << 16)));
    }
    else if(WRPArea == OB_WRPAREA_BANK2_AREAB)
    {
      MODIFY_REG(FLASH->WRP2BR, (FLASH_WRP2BR_WRP2B_STRT | FLASH_WRP2BR_WRP2B_END),
                 (WRPStartOffset | (WRDPEndOffset << 16)));
    }
#endif
    else
    {
                         
    }

                         
    SET_BIT(FLASH->CR, FLASH_CR_OPTSTRT);

                                                 
    status = FLASH_WaitForLastOperation((uint32_t)FLASH_TIMEOUT_VALUE);

                                                                                    
    CLEAR_BIT(FLASH->CR, FLASH_CR_OPTSTRT);
  }

  return status;
}

   
                                          
   
                                                                           
                                                                        
                                                                        
                                                                   
                                                                            
                                          
   
                                                         
                                                              
                                                 
                                                                 
                                                        
   
                      
    
static HAL_StatusTypeDef FLASH_OB_RDPConfig(uint32_t RDPLevel)
{
  HAL_StatusTypeDef status;

                            
  assert_param(IS_OB_RDP_LEVEL(RDPLevel));

                                               
  status = FLASH_WaitForLastOperation((uint32_t)FLASH_TIMEOUT_VALUE);

  if(status == HAL_OK)
  {
                                                              
    MODIFY_REG(FLASH->OPTR, FLASH_OPTR_RDP, RDPLevel);

                         
    SET_BIT(FLASH->CR, FLASH_CR_OPTSTRT);

                                                 
    status = FLASH_WaitForLastOperation((uint32_t)FLASH_TIMEOUT_VALUE);

                                                                                    
    CLEAR_BIT(FLASH->CR, FLASH_CR_OPTSTRT);
  }

  return status;
}

   
                                               
   
                                                                                
                                                                           
                                                                                
                                                                   
   
                                                               
                                                          
                                                                                  
                                                                             
                                                                                 
   
                      
    
static HAL_StatusTypeDef FLASH_OB_UserConfig(uint32_t UserType, uint32_t UserConfig)
{
  uint32_t optr_reg_val = 0;
  uint32_t optr_reg_mask = 0;
  HAL_StatusTypeDef status;

                            
  assert_param(IS_OB_USER_TYPE(UserType));

                                               
  status = FLASH_WaitForLastOperation((uint32_t)FLASH_TIMEOUT_VALUE);

  if(status == HAL_OK)
  {
    if((UserType & OB_USER_BOR_LEV) != 0U)
    {
                                                    
      assert_param(IS_OB_USER_BOR_LEVEL(UserConfig & FLASH_OPTR_BOR_LEV));

                                                        
      optr_reg_val |= (UserConfig & FLASH_OPTR_BOR_LEV);
      optr_reg_mask |= FLASH_OPTR_BOR_LEV;
    }

    if((UserType & OB_USER_nRST_STOP) != 0U)
    {
                                                    
      assert_param(IS_OB_USER_STOP(UserConfig & FLASH_OPTR_nRST_STOP));

                                                        
      optr_reg_val |= (UserConfig & FLASH_OPTR_nRST_STOP);
      optr_reg_mask |= FLASH_OPTR_nRST_STOP;
    }

    if((UserType & OB_USER_nRST_STDBY) != 0U)
    {
                                                     
      assert_param(IS_OB_USER_STANDBY(UserConfig & FLASH_OPTR_nRST_STDBY));

                                                         
      optr_reg_val |= (UserConfig & FLASH_OPTR_nRST_STDBY);
      optr_reg_mask |= FLASH_OPTR_nRST_STDBY;
    }

    if((UserType & OB_USER_nRST_SHDW) != 0U)
    {
                                                    
      assert_param(IS_OB_USER_SHUTDOWN(UserConfig & FLASH_OPTR_nRST_SHDW));

                                                        
      optr_reg_val |= (UserConfig & FLASH_OPTR_nRST_SHDW);
      optr_reg_mask |= FLASH_OPTR_nRST_SHDW;
    }

    if((UserType & OB_USER_IWDG_SW) != 0U)
    {
                                                  
      assert_param(IS_OB_USER_IWDG(UserConfig & FLASH_OPTR_IWDG_SW));

                                                      
      optr_reg_val |= (UserConfig & FLASH_OPTR_IWDG_SW);
      optr_reg_mask |= FLASH_OPTR_IWDG_SW;
    }

    if((UserType & OB_USER_IWDG_STOP) != 0U)
    {
                                                    
      assert_param(IS_OB_USER_IWDG_STOP(UserConfig & FLASH_OPTR_IWDG_STOP));

                                                        
      optr_reg_val |= (UserConfig & FLASH_OPTR_IWDG_STOP);
      optr_reg_mask |= FLASH_OPTR_IWDG_STOP;
    }

    if((UserType & OB_USER_IWDG_STDBY) != 0U)
    {
                                                     
      assert_param(IS_OB_USER_IWDG_STDBY(UserConfig & FLASH_OPTR_IWDG_STDBY));

                                                         
      optr_reg_val |= (UserConfig & FLASH_OPTR_IWDG_STDBY);
      optr_reg_mask |= FLASH_OPTR_IWDG_STDBY;
    }

    if((UserType & OB_USER_WWDG_SW) != 0U)
    {
                                                  
      assert_param(IS_OB_USER_WWDG(UserConfig & FLASH_OPTR_WWDG_SW));

                                                      
      optr_reg_val |= (UserConfig & FLASH_OPTR_WWDG_SW);
      optr_reg_mask |= FLASH_OPTR_WWDG_SW;
    }

#if defined (STM32L471xx) || defined (STM32L475xx) || defined (STM32L476xx) || defined (STM32L485xx) || defined (STM32L486xx) || \
    defined (STM32L496xx) || defined (STM32L4A6xx) || \
    defined (STM32L4P5xx) || defined (STM32L4Q5xx) || \
    defined (STM32L4R5xx) || defined (STM32L4R7xx) || defined (STM32L4R9xx) || defined (STM32L4S5xx) || defined (STM32L4S7xx) || defined (STM32L4S9xx)
    if((UserType & OB_USER_BFB2) != 0U)
    {
                                               
      assert_param(IS_OB_USER_BFB2(UserConfig & FLASH_OPTR_BFB2));

                                                   
      optr_reg_val |= (UserConfig & FLASH_OPTR_BFB2);
      optr_reg_mask |= FLASH_OPTR_BFB2;
    }

    if((UserType & OB_USER_DUALBANK) != 0U)
    {
#if defined (STM32L4P5xx) || defined (STM32L4Q5xx) || defined (STM32L4R5xx) || defined (STM32L4R7xx) || defined (STM32L4R9xx) || defined (STM32L4S5xx) || defined (STM32L4S7xx) || defined (STM32L4S9xx)
                                                   
      assert_param(IS_OB_USER_DUALBANK(UserConfig & FLASH_OPTR_DB1M));

                                                       
      optr_reg_val |= (UserConfig & FLASH_OPTR_DB1M);
      optr_reg_mask |= FLASH_OPTR_DB1M;
#else
                                                   
      assert_param(IS_OB_USER_DUALBANK(UserConfig & FLASH_OPTR_DUALBANK));

                                                       
      optr_reg_val |= (UserConfig & FLASH_OPTR_DUALBANK);
      optr_reg_mask |= FLASH_OPTR_DUALBANK;
#endif
    }
#endif

    if((UserType & OB_USER_nBOOT1) != 0U)
    {
                                                 
      assert_param(IS_OB_USER_BOOT1(UserConfig & FLASH_OPTR_nBOOT1));

                                                     
      optr_reg_val |= (UserConfig & FLASH_OPTR_nBOOT1);
      optr_reg_mask |= FLASH_OPTR_nBOOT1;
    }

    if((UserType & OB_USER_SRAM2_PE) != 0U)
    {
                                                   
      assert_param(IS_OB_USER_SRAM2_PARITY(UserConfig & FLASH_OPTR_SRAM2_PE));

                                                       
      optr_reg_val |= (UserConfig & FLASH_OPTR_SRAM2_PE);
      optr_reg_mask |= FLASH_OPTR_SRAM2_PE;
    }

    if((UserType & OB_USER_SRAM2_RST) != 0U)
    {
                                                    
      assert_param(IS_OB_USER_SRAM2_RST(UserConfig & FLASH_OPTR_SRAM2_RST));

                                                        
      optr_reg_val |= (UserConfig & FLASH_OPTR_SRAM2_RST);
      optr_reg_mask |= FLASH_OPTR_SRAM2_RST;
    }

#if defined (STM32L412xx) || defined (STM32L422xx) || defined (STM32L431xx) || defined (STM32L432xx) || defined (STM32L433xx) || \
    defined (STM32L442xx) || defined (STM32L443xx) || defined (STM32L451xx) || defined (STM32L452xx) || defined (STM32L462xx) || \
    defined (STM32L496xx) || defined (STM32L4A6xx) || \
    defined (STM32L4P5xx) || defined (STM32L4Q5xx) || \
    defined (STM32L4R5xx) || defined (STM32L4R7xx) || defined (STM32L4R9xx) || defined (STM32L4S5xx) || defined (STM32L4S7xx) || defined (STM32L4S9xx)
    if((UserType & OB_USER_nSWBOOT0) != 0U)
    {
                                                   
      assert_param(IS_OB_USER_SWBOOT0(UserConfig & FLASH_OPTR_nSWBOOT0));

                                                       
      optr_reg_val |= (UserConfig & FLASH_OPTR_nSWBOOT0);
      optr_reg_mask |= FLASH_OPTR_nSWBOOT0;
    }

    if((UserType & OB_USER_nBOOT0) != 0U)
    {
                                                 
      assert_param(IS_OB_USER_BOOT0(UserConfig & FLASH_OPTR_nBOOT0));

                                                     
      optr_reg_val |= (UserConfig & FLASH_OPTR_nBOOT0);
      optr_reg_mask |= FLASH_OPTR_nBOOT0;
    }
#endif

                                             
    MODIFY_REG(FLASH->OPTR, optr_reg_mask, optr_reg_val);

                         
    SET_BIT(FLASH->CR, FLASH_CR_OPTSTRT);

                                                 
    status = FLASH_WaitForLastOperation((uint32_t)FLASH_TIMEOUT_VALUE);

                                                                                    
    CLEAR_BIT(FLASH->CR, FLASH_CR_OPTSTRT);
  }

  return status;
}

   
                                                                                       
   
                                                                               
                                                                        
                                                                            
                                                                   
   
                                                                                                 
                                                                                 
                                                              
   
                                                                                                 
                                                                               
   
                                                                                             
                                                                                        
   
                      
    
static HAL_StatusTypeDef FLASH_OB_PCROPConfig(uint32_t PCROPConfig, uint32_t PCROPStartAddr, uint32_t PCROPEndAddr)
{
  HAL_StatusTypeDef status;
  uint32_t reg_value;
  uint32_t bank1_addr;
#if defined (STM32L471xx) || defined (STM32L475xx) || defined (STM32L476xx) || defined (STM32L485xx) || defined (STM32L486xx) || \
    defined (STM32L496xx) || defined (STM32L4A6xx) || \
    defined (STM32L4P5xx) || defined (STM32L4Q5xx) || \
    defined (STM32L4R5xx) || defined (STM32L4R7xx) || defined (STM32L4R9xx) || defined (STM32L4S5xx) || defined (STM32L4S7xx) || defined (STM32L4S9xx)
  uint32_t bank2_addr;
#endif

                            
  assert_param(IS_FLASH_BANK_EXCLUSIVE(PCROPConfig & FLASH_BANK_BOTH));
  assert_param(IS_OB_PCROP_RDP(PCROPConfig & FLASH_PCROP1ER_PCROP_RDP));
  assert_param(IS_FLASH_MAIN_MEM_ADDRESS(PCROPStartAddr));
  assert_param(IS_FLASH_MAIN_MEM_ADDRESS(PCROPEndAddr));

                                               
  status = FLASH_WaitForLastOperation((uint32_t)FLASH_TIMEOUT_VALUE);

  if(status == HAL_OK)
  {
#if defined (STM32L471xx) || defined (STM32L475xx) || defined (STM32L476xx) || defined (STM32L485xx) || defined (STM32L486xx) || \
    defined (STM32L496xx) || defined (STM32L4A6xx) || \
    defined (STM32L4P5xx) || defined (STM32L4Q5xx) || \
    defined (STM32L4R5xx) || defined (STM32L4R7xx) || defined (STM32L4R9xx) || defined (STM32L4S5xx) || defined (STM32L4S7xx) || defined (STM32L4S9xx)
                                                     
    if (READ_BIT(SYSCFG->MEMRMP, SYSCFG_MEMRMP_FB_MODE) == 0U)
    {
      bank1_addr = FLASH_BASE;
      bank2_addr = FLASH_BASE + FLASH_BANK_SIZE;
    }
    else
    {
      bank1_addr = FLASH_BASE + FLASH_BANK_SIZE;
      bank2_addr = FLASH_BASE;
    }
#else
    bank1_addr = FLASH_BASE;
#endif

#if defined (STM32L4P5xx) || defined (STM32L4Q5xx) || defined (STM32L4R5xx) || defined (STM32L4R7xx) || defined (STM32L4R9xx) || defined (STM32L4S5xx) || defined (STM32L4S7xx) || defined (STM32L4S9xx)
    if (READ_BIT(FLASH->OPTR, FLASH_OPTR_DBANK) == 0U)
    {
                                                             
      if((PCROPConfig & FLASH_BANK_BOTH) == FLASH_BANK_1)
      {
        reg_value = ((PCROPStartAddr - FLASH_BASE) >> 4);
        MODIFY_REG(FLASH->PCROP1SR, FLASH_PCROP1SR_PCROP1_STRT, reg_value);

        reg_value = ((PCROPEndAddr - FLASH_BASE) >> 4);
        MODIFY_REG(FLASH->PCROP1ER, FLASH_PCROP1ER_PCROP1_END, reg_value);
      }
      else if((PCROPConfig & FLASH_BANK_BOTH) == FLASH_BANK_2)
      {
        reg_value = ((PCROPStartAddr - FLASH_BASE) >> 4);
        MODIFY_REG(FLASH->PCROP2SR, FLASH_PCROP2SR_PCROP2_STRT, reg_value);

        reg_value = ((PCROPEndAddr - FLASH_BASE) >> 4);
        MODIFY_REG(FLASH->PCROP2ER, FLASH_PCROP2ER_PCROP2_END, reg_value);
      }
      else
      {
                           
      }
    }
    else
#endif
    {
                                                             
      if((PCROPConfig & FLASH_BANK_BOTH) == FLASH_BANK_1)
      {
        reg_value = ((PCROPStartAddr - bank1_addr) >> 3);
        MODIFY_REG(FLASH->PCROP1SR, FLASH_PCROP1SR_PCROP1_STRT, reg_value);

        reg_value = ((PCROPEndAddr - bank1_addr) >> 3);
        MODIFY_REG(FLASH->PCROP1ER, FLASH_PCROP1ER_PCROP1_END, reg_value);
      }
#if defined (STM32L471xx) || defined (STM32L475xx) || defined (STM32L476xx) || defined (STM32L485xx) || defined (STM32L486xx) || \
    defined (STM32L496xx) || defined (STM32L4A6xx) || \
    defined (STM32L4P5xx) || defined (STM32L4Q5xx) || \
    defined (STM32L4R5xx) || defined (STM32L4R7xx) || defined (STM32L4R9xx) || defined (STM32L4S5xx) || defined (STM32L4S7xx) || defined (STM32L4S9xx)
      else if((PCROPConfig & FLASH_BANK_BOTH) == FLASH_BANK_2)
      {
        reg_value = ((PCROPStartAddr - bank2_addr) >> 3);
        MODIFY_REG(FLASH->PCROP2SR, FLASH_PCROP2SR_PCROP2_STRT, reg_value);

        reg_value = ((PCROPEndAddr - bank2_addr) >> 3);
        MODIFY_REG(FLASH->PCROP2ER, FLASH_PCROP2ER_PCROP2_END, reg_value);
      }
#endif
      else
      {
                           
      }
    }

    MODIFY_REG(FLASH->PCROP1ER, FLASH_PCROP1ER_PCROP_RDP, (PCROPConfig & FLASH_PCROP1ER_PCROP_RDP));

                         
    SET_BIT(FLASH->CR, FLASH_CR_OPTSTRT);

                                                 
    status = FLASH_WaitForLastOperation((uint32_t)FLASH_TIMEOUT_VALUE);

                                                                                    
    CLEAR_BIT(FLASH->CR, FLASH_CR_OPTSTRT);
  }

  return status;
}

   
                                                                 
   
                                                           
                                                               
                                                               
                                                               
                                                                                                            
                                                                                                            
   
                                                                                     
                                                       
   
                                                                                     
                                                   
   
                
    
static void FLASH_OB_GetWRP(uint32_t WRPArea, uint32_t * WRPStartOffset, uint32_t * WRDPEndOffset)
{
                                                         
  if(WRPArea == OB_WRPAREA_BANK1_AREAA)
  {
    *WRPStartOffset = READ_BIT(FLASH->WRP1AR, FLASH_WRP1AR_WRP1A_STRT);
    *WRDPEndOffset = (READ_BIT(FLASH->WRP1AR, FLASH_WRP1AR_WRP1A_END) >> 16);
  }
  else if(WRPArea == OB_WRPAREA_BANK1_AREAB)
  {
    *WRPStartOffset = READ_BIT(FLASH->WRP1BR, FLASH_WRP1BR_WRP1B_STRT);
    *WRDPEndOffset = (READ_BIT(FLASH->WRP1BR, FLASH_WRP1BR_WRP1B_END) >> 16);
  }
#if defined (STM32L471xx) || defined (STM32L475xx) || defined (STM32L476xx) || defined (STM32L485xx) || defined (STM32L486xx) || \
    defined (STM32L496xx) || defined (STM32L4A6xx) || \
    defined (STM32L4P5xx) || defined (STM32L4Q5xx) || \
    defined (STM32L4R5xx) || defined (STM32L4R7xx) || defined (STM32L4R9xx) || defined (STM32L4S5xx) || defined (STM32L4S7xx) || defined (STM32L4S9xx)
  else if(WRPArea == OB_WRPAREA_BANK2_AREAA)
  {
    *WRPStartOffset = READ_BIT(FLASH->WRP2AR, FLASH_WRP2AR_WRP2A_STRT);
    *WRDPEndOffset = (READ_BIT(FLASH->WRP2AR, FLASH_WRP2AR_WRP2A_END) >> 16);
  }
  else if(WRPArea == OB_WRPAREA_BANK2_AREAB)
  {
    *WRPStartOffset = READ_BIT(FLASH->WRP2BR, FLASH_WRP2BR_WRP2B_STRT);
    *WRDPEndOffset = (READ_BIT(FLASH->WRP2BR, FLASH_WRP2BR_WRP2B_END) >> 16);
  }
#endif
  else
  {
                       
  }
}

   
                                                   
                                            
                                                                 
                                                 
                                                                 
                                                        
    
static uint32_t FLASH_OB_GetRDP(void)
{
  uint32_t rdp_level = READ_BIT(FLASH->OPTR, FLASH_OPTR_RDP);

  if ((rdp_level != OB_RDP_LEVEL_0) && (rdp_level != OB_RDP_LEVEL_2))
  {
    return (OB_RDP_LEVEL_1);
  }
  else
  {
    return (READ_BIT(FLASH->OPTR, FLASH_OPTR_RDP));
  }
}

   
                                                    
                                               
                                          
                                                                                    
                                                                                
                                                                                              
                                          
                                                                                    
                                                                                
                                                                                                
    
static uint32_t FLASH_OB_GetUser(void)
{
  uint32_t user_config = READ_REG(FLASH->OPTR);
  CLEAR_BIT(user_config, FLASH_OPTR_RDP);

  return user_config;
}

   
                                                                 
   
                                                                                                         
                                                                                 
                                                              
   
                                                                                        
                                                                      
   
                                                                                       
                                                                 
   
                
    
static void FLASH_OB_GetPCROP(uint32_t * PCROPConfig, uint32_t * PCROPStartAddr, uint32_t * PCROPEndAddr)
{
  uint32_t reg_value;
  uint32_t bank1_addr;
#if defined (STM32L471xx) || defined (STM32L475xx) || defined (STM32L476xx) || defined (STM32L485xx) || defined (STM32L486xx) || \
    defined (STM32L496xx) || defined (STM32L4A6xx) || \
    defined (STM32L4P5xx) || defined (STM32L4Q5xx) || \
    defined (STM32L4R5xx) || defined (STM32L4R7xx) || defined (STM32L4R9xx) || defined (STM32L4S5xx) || defined (STM32L4S7xx) || defined (STM32L4S9xx)
  uint32_t bank2_addr;
#endif

#if defined (STM32L471xx) || defined (STM32L475xx) || defined (STM32L476xx) || defined (STM32L485xx) || defined (STM32L486xx) || \
    defined (STM32L496xx) || defined (STM32L4A6xx) || \
    defined (STM32L4P5xx) || defined (STM32L4Q5xx) || \
    defined (STM32L4R5xx) || defined (STM32L4R7xx) || defined (STM32L4R9xx) || defined (STM32L4S5xx) || defined (STM32L4S7xx) || defined (STM32L4S9xx)
                                                   
  if (READ_BIT(SYSCFG->MEMRMP, SYSCFG_MEMRMP_FB_MODE) == 0U)
  {
    bank1_addr = FLASH_BASE;
    bank2_addr = FLASH_BASE + FLASH_BANK_SIZE;
  }
  else
  {
    bank1_addr = FLASH_BASE + FLASH_BANK_SIZE;
    bank2_addr = FLASH_BASE;
  }
#else
  bank1_addr = FLASH_BASE;
#endif

#if defined (STM32L4P5xx) || defined (STM32L4Q5xx) || defined (STM32L4R5xx) || defined (STM32L4R7xx) || defined (STM32L4R9xx) || defined (STM32L4S5xx) || defined (STM32L4S7xx) || defined (STM32L4S9xx)
  if (READ_BIT(FLASH->OPTR, FLASH_OPTR_DBANK) == 0U)
  {
    if(((*PCROPConfig) & FLASH_BANK_BOTH) == FLASH_BANK_1)
    {
      reg_value       = (READ_REG(FLASH->PCROP1SR) & FLASH_PCROP1SR_PCROP1_STRT);
      *PCROPStartAddr = (reg_value << 4) + FLASH_BASE;

      reg_value     = (READ_REG(FLASH->PCROP1ER) & FLASH_PCROP1ER_PCROP1_END);
      *PCROPEndAddr = (reg_value << 4) + FLASH_BASE + 0xFU;
    }
    else if(((*PCROPConfig) & FLASH_BANK_BOTH) == FLASH_BANK_2)
    {
      reg_value       = (READ_REG(FLASH->PCROP2SR) & FLASH_PCROP2SR_PCROP2_STRT);
      *PCROPStartAddr = (reg_value << 4) + FLASH_BASE;

      reg_value     = (READ_REG(FLASH->PCROP2ER) & FLASH_PCROP2ER_PCROP2_END);
      *PCROPEndAddr = (reg_value << 4) + FLASH_BASE + 0xFU;;
    }
    else
    {
                         
    }
  }
  else
#endif
  {
    if(((*PCROPConfig) & FLASH_BANK_BOTH) == FLASH_BANK_1)
    {
      reg_value       = (READ_REG(FLASH->PCROP1SR) & FLASH_PCROP1SR_PCROP1_STRT);
      *PCROPStartAddr = (reg_value << 3) + bank1_addr;

      reg_value     = (READ_REG(FLASH->PCROP1ER) & FLASH_PCROP1ER_PCROP1_END);
      *PCROPEndAddr = (reg_value << 3) + bank1_addr + 0x7U;
    }
#if defined (STM32L471xx) || defined (STM32L475xx) || defined (STM32L476xx) || defined (STM32L485xx) || defined (STM32L486xx) || \
    defined (STM32L496xx) || defined (STM32L4A6xx) || \
    defined (STM32L4P5xx) || defined (STM32L4Q5xx) || \
    defined (STM32L4R5xx) || defined (STM32L4R7xx) || defined (STM32L4R9xx) || defined (STM32L4S5xx) || defined (STM32L4S7xx) || defined (STM32L4S9xx)
    else if(((*PCROPConfig) & FLASH_BANK_BOTH) == FLASH_BANK_2)
    {
      reg_value       = (READ_REG(FLASH->PCROP2SR) & FLASH_PCROP2SR_PCROP2_STRT);
      *PCROPStartAddr = (reg_value << 3) + bank2_addr;

      reg_value     = (READ_REG(FLASH->PCROP2ER) & FLASH_PCROP2ER_PCROP2_END);
      *PCROPEndAddr = (reg_value << 3) + bank2_addr + 0x7U;
    }
#endif
    else
    {
                         
    }
  }

  *PCROPConfig |= (READ_REG(FLASH->PCROP1ER) & FLASH_PCROP1ER_PCROP_RDP);
}
   
      
    

   
      
    

#endif                               

   
      
    

   
      
    

