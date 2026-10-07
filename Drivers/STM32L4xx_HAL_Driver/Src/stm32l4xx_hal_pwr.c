/**
  ******************************************************************************
  * @file    stm32l4xx_hal_pwr.c
  * @author  MCD Application Team
  * @brief   PWR HAL module driver.
  *          This file provides firmware functions to manage the following
  *          functionalities of the Power Controller (PWR) peripheral:
  *           + Initialization/de-initialization functions
  *           + Peripheral Control functions
  *
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2019 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */

                                                                                
#include "stm32l4xx_hal.h"

                                    
      
    

                     
                                
      
    

#ifdef HAL_PWR_MODULE_ENABLED

                                                                                
                                                                                

                                                     
      
    

                                                 
      
    
#define PVD_MODE_IT               ((uint32_t)0x00010000)                                                                 
#define PVD_MODE_EVT              ((uint32_t)0x00020000)                                                                 
#define PVD_RISING_EDGE           ((uint32_t)0x00000001)                                                                 
#define PVD_FALLING_EDGE          ((uint32_t)0x00000002)                                                                 
   
      
    

   
      
    

                                                                                
                                                                                
                                                                                
                                                                                

                                                           
      
    

                                                                                          
                                                             
   
         
                                                                                
                                                                        
                                                                                
        

            
      
    

   
                                                                                       
                
    
void HAL_PWR_DeInit(void)
{
  __HAL_RCC_PWR_FORCE_RESET();
  __HAL_RCC_PWR_RELEASE_RESET();
}

   
                                             
                                                      
                                                              
                                            
                                                                                        
                                                                                    
                    
                                                                                    
                          
                
    
void HAL_PWR_EnableBkUpAccess(void)
{
  SET_BIT(PWR->CR1, PWR_CR1_DBP);
}

   
                                              
                                                      
                
    
void HAL_PWR_DisableBkUpAccess(void)
{
  CLEAR_BIT(PWR->CR1, PWR_CR1_DBP);
}




   
      
    



                                                                        
                                                   
   
         

                                                                                
                                                         
                                                                                

         
                              
                             
        
                                                                              
                                                                                  

                                                                           
                                                                                
                                                                               
                                           
                                             


                                    
                                    
        
                                                                                       
                                                                                    
                                                          



                                         
                                         
        
                                            
                                                                                                           
                                                                                                         
                                                                                                                             
                                                                                                   
                                                                                                             
                                                                                                                                                                   
                                                                                                                                                  
                                                                                                                   
                                                                                              


                             
                             
        
                                     
                                                                                                                        

               
                                                                                                                
                                                                          


                                            
                                            
        
                
                                                                                               
                                                                                                                             
                                                                         
                                                                                       
                                                                                                         
                                                                        
                                                                        

                   
                                                                                   
                                                    

                   
                                                                             

                                                                                              
                                              

                                          
                                  
        
                
                                                                                     
                                                                                                                                             
                                                     
                                                                         
                                   
                                       
                                                                                 
                                                                      
                                                                      

                   
                                                                                 
                                                                                      
                                              
                   
                                                                             

           
                                                                                                      
                                           
                                                           

                       
                       
         
                                          
                                                                                                               
                                                                                                                  
                              
                                                                                                         
                                                                                              
                              

                 
                                                                                   
                                                                                                  
                                                                                                            
                                                                                                          
                               

                
                                                                                          
                                                       

                                                                                                             


                         
                         
         
                       
                                                                                         
                                                                                

                
                                                                                 

               
                                                                                         
                                          

                                                                                                              


                                                
                                                
        
                                                                               
                                                                              
                                               

                                                                         


                                                                                      
                                                                                                  

                                                                                     
                                                                                                 
                                                                               

                                                                                       
                                                                                                                  

            
      
    



   
                                                                                        
                                                                                  
                                     
                                                                              
                                                                           
                            
                
    
HAL_StatusTypeDef HAL_PWR_ConfigPVD(PWR_PVDTypeDef *sConfigPVD)
{
                            
  assert_param(IS_PWR_PVD_LEVEL(sConfigPVD->PVDLevel));
  assert_param(IS_PWR_PVD_MODE(sConfigPVD->Mode));

                                                
  MODIFY_REG(PWR->CR2, PWR_CR2_PLS, sConfigPVD->PVDLevel);

                                                                                   
  __HAL_PWR_PVD_EXTI_DISABLE_EVENT();
  __HAL_PWR_PVD_EXTI_DISABLE_IT();
  __HAL_PWR_PVD_EXTI_DISABLE_FALLING_EDGE();
  __HAL_PWR_PVD_EXTI_DISABLE_RISING_EDGE();

                                
  if((sConfigPVD->Mode & PVD_MODE_IT) == PVD_MODE_IT)
  {
    __HAL_PWR_PVD_EXTI_ENABLE_IT();
  }

                            
  if((sConfigPVD->Mode & PVD_MODE_EVT) == PVD_MODE_EVT)
  {
    __HAL_PWR_PVD_EXTI_ENABLE_EVENT();
  }

                          
  if((sConfigPVD->Mode & PVD_RISING_EDGE) == PVD_RISING_EDGE)
  {
    __HAL_PWR_PVD_EXTI_ENABLE_RISING_EDGE();
  }

  if((sConfigPVD->Mode & PVD_FALLING_EDGE) == PVD_FALLING_EDGE)
  {
    __HAL_PWR_PVD_EXTI_ENABLE_FALLING_EDGE();
  }

  return HAL_OK;
}


   
                                                   
                
    
void HAL_PWR_EnablePVD(void)
{
  SET_BIT(PWR->CR2, PWR_CR2_PVDE);
}

   
                                                    
                
    
void HAL_PWR_DisablePVD(void)
{
  CLEAR_BIT(PWR->CR2, PWR_CR2_PVDE);
}




   
                                                
                                                                    
                                                                                                   
                                                       
                                                                                                           
   
                                                                                                   
                                
                                                                   
                                                                   
                                                                   
                                                                   
                                                                   
                                                                   
                
    
void HAL_PWR_EnableWakeUpPin(uint32_t WakeUpPinPolarity)
{
  assert_param(IS_PWR_WAKEUP_PIN(WakeUpPinPolarity));

                                                               
                               
  MODIFY_REG(PWR->CR4, (PWR_CR3_EWUP & WakeUpPinPolarity), (WakeUpPinPolarity >> PWR_WUP_POLARITY_SHIFT));

                          
  SET_BIT(PWR->CR3, (PWR_CR3_EWUP & WakeUpPinPolarity));


}

   
                                                 
                                                                  
                                                              
                                                                                                           
                
    
void HAL_PWR_DisableWakeUpPin(uint32_t WakeUpPinx)
{
  assert_param(IS_PWR_WAKEUP_PIN(WakeUpPinx));

  CLEAR_BIT(PWR->CR3, (PWR_CR3_EWUP & WakeUpPinx));
}


   
                                               
                                                                                          
                                                                                  
                                                               
                                                                                 
                                                                                                    
                                                                                         
                                                                                           
                                                                             
                                                                                       
                                                                         
                                                                                             
                                                               
                                                                                          
                                                                                    
                                                                                      
                                                                
                                                                                                    
                                                                                                    
                                                                                       
                                        
                
    
void HAL_PWR_EnterSLEEPMode(uint32_t Regulator, uint8_t SLEEPEntry)
{
                            
  assert_param(IS_PWR_REGULATOR(Regulator));
  assert_param(IS_PWR_SLEEP_ENTRY(SLEEPEntry));

                               
  if (Regulator == PWR_MAINREGULATOR_ON)
  {
                                                         
    if (HAL_IS_BIT_SET(PWR->SR2, PWR_SR2_REGLPF))
    {
      if (HAL_PWREx_DisableLowPowerRunMode() != HAL_OK)
      {
        return ;
      }
    }
                                     
  }
  else
  {
                                                        
                                                                       
    if (HAL_IS_BIT_SET(PWR->SR2, PWR_SR2_REGLPF) == RESET)
    {
      HAL_PWREx_EnableLowPowerRunMode();
    }
  }

                                                             
  CLEAR_BIT(SCB->SCR, ((uint32_t)SCB_SCR_SLEEPDEEP_Msk));

                                                                                
  if(SLEEPEntry == PWR_SLEEPENTRY_WFI)
  {
                                    
    __WFI();
  }
  else
  {
                                
    __SEV();
    __WFE();
    __WFE();
  }

}


   
                          
                                                                                                   
                                                                                              
                                                                         
                                                                        
                                                                                                    
                                                                                                     
                                                                                                           
                                                
                                                            
                                
                                                                                                        
                                                                                        
                                                                                                  
                                                                          
                                                                                        
                                                     
                                                                                           
                                                           
                                                                 
                                                               
                                                                              
                                                                                       
                                                                                             
                                                               
                                                                                             
                                                                                             
                
    
void HAL_PWR_EnterSTOPMode(uint32_t Regulator, uint8_t STOPEntry)
{
                            
  assert_param(IS_PWR_REGULATOR(Regulator));

  if(Regulator == PWR_LOWPOWERREGULATOR_ON)
  {
    HAL_PWREx_EnterSTOP1Mode(STOPEntry);
  }
  else
  {
    HAL_PWREx_EnterSTOP0Mode(STOPEntry);
  }
}

   
                              
                                                                                          
                                                                                         
                                                            
                                                                                             
                                                                                                       
                                                                                                     
                          
                                
                                                                                                        
                                                                                                          
                                                                                                         
                
                                                                                    
                                                      
                
    
void HAL_PWR_EnterSTANDBYMode(void)
{
                         
  MODIFY_REG(PWR->CR1, PWR_CR1_LPMS, PWR_CR1_LPMS_STANDBY);

                                                           
  SET_BIT(SCB->SCR, ((uint32_t)SCB_SCR_SLEEPDEEP_Msk));

                                                                       
#if defined ( __CC_ARM)
  __force_stores();
#endif
                                  
  __WFI();
}



   
                                                                                  
                                                                                  
                                                                     
                                                                                  
                                 
                
    
void HAL_PWR_EnableSleepOnExit(void)
{
                                                             
  SET_BIT(SCB->SCR, ((uint32_t)SCB_SCR_SLEEPONEXIT_Msk));
}


   
                                                                                         
                                                                                    
                                                                     
                
    
void HAL_PWR_DisableSleepOnExit(void)
{
                                                               
  CLEAR_BIT(SCB->SCR, ((uint32_t)SCB_SCR_SLEEPONEXIT_Msk));
}



   
                                          
                                                                              
                                                                         
                
    
void HAL_PWR_EnableSEVOnPend(void)
{
                                                           
  SET_BIT(SCB->SCR, ((uint32_t)SCB_SCR_SEVONPEND_Msk));
}


   
                                           
                                                                                
                                                                         
                
    
void HAL_PWR_DisableSEVOnPend(void)
{
                                                             
  CLEAR_BIT(SCB->SCR, ((uint32_t)SCB_SCR_SEVONPEND_Msk));
}





   
                                     
                
    
__weak void HAL_PWR_PVDCallback(void)
{
                                                                              
                                                                       
     
}

   
      
    

   
      
    

#endif                             
   
      
    

   
      
    
