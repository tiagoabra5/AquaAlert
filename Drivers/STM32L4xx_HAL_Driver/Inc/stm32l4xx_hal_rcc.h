/**
  ******************************************************************************
  * @file    stm32l4xx_hal_rcc.h
  * @author  MCD Application Team
  * @brief   Header file of RCC HAL module.
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

                                                                                
#ifndef STM32L4xx_HAL_RCC_H
#define STM32L4xx_HAL_RCC_H

#ifdef __cplusplus
 extern "C" {
#endif

                                                                                
#include "stm32l4xx_hal_def.h"

                                    
      
    

                   
      
    

                                                                                
                                                   
      
    

   
                                                      
    
typedef struct
{
  uint32_t PLLState;                                 
                                                                                                        

  uint32_t PLLSource;                                             
                                                                                                        

  uint32_t PLLM;                                                          
                                                                                                                                  
                                                                                                                         

  uint32_t PLLN;                                                                 
                                                                                                        

#if defined(RCC_PLLP_SUPPORT)
  uint32_t PLLP;                                                
                                                                                                        
#endif                       

  uint32_t PLLQ;                                                                 
                                                                                                        

  uint32_t PLLR;                                                     
                                                                                                            
                                                                                           
                                                                                                        

}RCC_PLLInitTypeDef;

   
                                                                                                            
    
typedef struct
{
  uint32_t OscillatorType;                                             
                                                                                                                    

  uint32_t HSEState;                                           
                                                                                                                    

  uint32_t LSEState;                                           
                                                                                                                    

  uint32_t HSIState;                                           
                                                                                                                    

  uint32_t HSICalibrationValue;                                                                              
                                                                                                               
                                                                                      
                                                                                                                
                                                          

  uint32_t LSIState;                                           
                                                                                                                    
#if defined(RCC_CSR_LSIPREDIV)

  uint32_t LSIDiv;                                                   
                                                                                                                    
#endif                        

  uint32_t MSIState;                                           
                                                                                             

  uint32_t MSICalibrationValue;                                                                              
                                                                                                                    

  uint32_t MSIClockRange;                                     
                                                                                                   

  uint32_t HSI48State;                                                                                                                  
                                                                                                 

  RCC_PLLInitTypeDef PLL;                                                                                           

}RCC_OscInitTypeDef;

   
                                                                                   
    
typedef struct
{
  uint32_t ClockType;                                             
                                                                                                          

  uint32_t SYSCLKSource;                                                              
                                                                                                          

  uint32_t AHBCLKDivider;                                                                                                 
                                                                                                          

  uint32_t APB1CLKDivider;                                                                                             
                                                                                                          

  uint32_t APB2CLKDivider;                                                                                             
                                                                                                          

}RCC_ClkInitTypeDef;

   
      
    

                                                                                
                                                           
      
    

                                              
      
    
#define RCC_DBP_TIMEOUT_VALUE          2U                                         
#define RCC_LSE_TIMEOUT_VALUE          LSE_STARTUP_TIMEOUT
   
      
    

                                                 
      
    
#define RCC_OSCILLATORTYPE_NONE        0x00000000U                                             
#define RCC_OSCILLATORTYPE_HSE         0x00000001U                           
#define RCC_OSCILLATORTYPE_HSI         0x00000002U                           
#define RCC_OSCILLATORTYPE_LSE         0x00000004U                           
#define RCC_OSCILLATORTYPE_LSI         0x00000008U                           
#define RCC_OSCILLATORTYPE_MSI         0x00000010U                           
#if defined(RCC_HSI48_SUPPORT)
#define RCC_OSCILLATORTYPE_HSI48       0x00000020U                             
#endif                        
   
      
    

                                       
      
    
#define RCC_HSE_OFF                    0x00000000U                                                  
#define RCC_HSE_ON                     RCC_CR_HSEON                                               
#define RCC_HSE_BYPASS                 (RCC_CR_HSEBYP | RCC_CR_HSEON)                                            
   
      
    

                                       
      
    
#define RCC_LSE_OFF                    0x00000000U                                                         
#define RCC_LSE_ON                     RCC_BDCR_LSEON                                                    
#define RCC_LSE_BYPASS                 (RCC_BDCR_LSEBYP | RCC_BDCR_LSEON)                                               
#if defined(RCC_BDCR_LSESYSDIS)
#define RCC_LSE_ON_RTC_ONLY            (RCC_BDCR_LSESYSDIS | RCC_BDCR_LSEON)                                                           
#define RCC_LSE_BYPASS_RTC_ONLY        (RCC_BDCR_LSEBYP | RCC_BDCR_LSESYSDIS | RCC_BDCR_LSEON)                                                                          
#endif                         
   
      
    

                                       
      
    
#define RCC_HSI_OFF                    0x00000000U                                 
#define RCC_HSI_ON                     RCC_CR_HSION                              

#if defined(RCC_ICSCR_HSITRIM_6)
#define RCC_HSICALIBRATION_DEFAULT     0x40U                                                                                                                        
#else
#define RCC_HSICALIBRATION_DEFAULT     0x10U                                                                                                             
#endif                          
   
      
    

                                       
      
    
#define RCC_LSI_OFF                    0x00000000U                                 
#define RCC_LSI_ON                     RCC_CSR_LSION                             
   
      
    
#if defined(RCC_CSR_LSIPREDIV)

                                 
      
    
#define RCC_LSI_DIV1                   0x00000000U                                       
#define RCC_LSI_DIV128                 RCC_CSR_LSIPREDIV                                 
   
      
    
#endif                        

                                       
      
    
#define RCC_MSI_OFF                    0x00000000U                                 
#define RCC_MSI_ON                     RCC_CR_MSION                              

#define RCC_MSICALIBRATION_DEFAULT     0U                                                          
   
      
    

#if defined(RCC_HSI48_SUPPORT)
                                           
      
    
#define RCC_HSI48_OFF                  0x00000000U                                       
#define RCC_HSI48_ON                   RCC_CRRCR_HSI48ON                               
   
      
    
#else
                                           
      
    
#define RCC_HSI48_OFF                  0x00000000U                                   
   
      
    
#endif                        

                                       
      
    
#define RCC_PLL_NONE                   0x00000000U                                      
#define RCC_PLL_OFF                    0x00000001U                           
#define RCC_PLL_ON                     0x00000002U                         
   
      
    

#if defined(RCC_PLLP_SUPPORT)
                                                       
      
    
#if defined(RCC_PLLP_DIV_2_31_SUPPORT)
#define RCC_PLLP_DIV2                  0x00000002U                                    
#define RCC_PLLP_DIV3                  0x00000003U                                    
#define RCC_PLLP_DIV4                  0x00000004U                                    
#define RCC_PLLP_DIV5                  0x00000005U                                    
#define RCC_PLLP_DIV6                  0x00000006U                                    
#define RCC_PLLP_DIV7                  0x00000007U                                    
#define RCC_PLLP_DIV8                  0x00000008U                                    
#define RCC_PLLP_DIV9                  0x00000009U                                    
#define RCC_PLLP_DIV10                 0x0000000AU                                    
#define RCC_PLLP_DIV11                 0x0000000BU                                    
#define RCC_PLLP_DIV12                 0x0000000CU                                    
#define RCC_PLLP_DIV13                 0x0000000DU                                    
#define RCC_PLLP_DIV14                 0x0000000EU                                    
#define RCC_PLLP_DIV15                 0x0000000FU                                    
#define RCC_PLLP_DIV16                 0x00000010U                                    
#define RCC_PLLP_DIV17                 0x00000011U                                    
#define RCC_PLLP_DIV18                 0x00000012U                                    
#define RCC_PLLP_DIV19                 0x00000013U                                    
#define RCC_PLLP_DIV20                 0x00000014U                                    
#define RCC_PLLP_DIV21                 0x00000015U                                    
#define RCC_PLLP_DIV22                 0x00000016U                                    
#define RCC_PLLP_DIV23                 0x00000017U                                    
#define RCC_PLLP_DIV24                 0x00000018U                                    
#define RCC_PLLP_DIV25                 0x00000019U                                    
#define RCC_PLLP_DIV26                 0x0000001AU                                    
#define RCC_PLLP_DIV27                 0x0000001BU                                    
#define RCC_PLLP_DIV28                 0x0000001CU                                    
#define RCC_PLLP_DIV29                 0x0000001DU                                    
#define RCC_PLLP_DIV30                 0x0000001EU                                    
#define RCC_PLLP_DIV31                 0x0000001FU                                    
#else
#define RCC_PLLP_DIV7                  0x00000007U                                    
#define RCC_PLLP_DIV17                 0x00000011U                                    
#endif                                
   
      
    
#endif                       

                                                       
      
    
#define RCC_PLLQ_DIV2                  0x00000002U                                   
#define RCC_PLLQ_DIV4                  0x00000004U                                   
#define RCC_PLLQ_DIV6                  0x00000006U                                   
#define RCC_PLLQ_DIV8                  0x00000008U                                   
   
      
    

                                                       
      
    
#define RCC_PLLR_DIV2                  0x00000002U                                   
#define RCC_PLLR_DIV4                  0x00000004U                                   
#define RCC_PLLR_DIV6                  0x00000006U                                   
#define RCC_PLLR_DIV8                  0x00000008U                                   
   
      
    

                                                   
      
    
#define RCC_PLLSOURCE_NONE             0x00000000U                                                                 
#define RCC_PLLSOURCE_MSI              RCC_PLLCFGR_PLLSRC_MSI                                                      
#define RCC_PLLSOURCE_HSI              RCC_PLLCFGR_PLLSRC_HSI                                                      
#define RCC_PLLSOURCE_HSE              RCC_PLLCFGR_PLLSRC_HSE                                                      
   
      
    

                                                   
      
    
#if defined(RCC_PLLSAI2_SUPPORT)
#define RCC_PLL_SAI3CLK                RCC_PLLCFGR_PLLPEN                                                                           
#elif defined(RCC_PLLSAI1_SUPPORT)
#define RCC_PLL_SAI2CLK                RCC_PLLCFGR_PLLPEN                                                                              
#endif                          
#define RCC_PLL_48M1CLK                RCC_PLLCFGR_PLLQEN                                                
#define RCC_PLL_SYSCLK                 RCC_PLLCFGR_PLLREN                                            
   
      
    
#if defined(RCC_PLLSAI1_SUPPORT)

                                                           
      
    
#define RCC_PLLSAI1_SAI1CLK            RCC_PLLSAI1CFGR_PLLSAI1PEN                                          
#define RCC_PLLSAI1_48M2CLK            RCC_PLLSAI1CFGR_PLLSAI1QEN                                          
#define RCC_PLLSAI1_ADC1CLK            RCC_PLLSAI1CFGR_PLLSAI1REN                                          
   
      
    
#endif                          

#if defined(RCC_PLLSAI2_SUPPORT)

                                                           
      
    
#define RCC_PLLSAI2_SAI2CLK            RCC_PLLSAI2CFGR_PLLSAI2PEN                                          
#if defined(RCC_PLLSAI2Q_DIV_SUPPORT)
#define RCC_PLLSAI2_DSICLK             RCC_PLLSAI2CFGR_PLLSAI2QEN                                          
#endif                               
#if defined(STM32L471xx) || defined(STM32L475xx) || defined(STM32L476xx) || defined(STM32L485xx) || defined(STM32L486xx) || defined(STM32L496xx) || defined(STM32L4A6xx)
#define RCC_PLLSAI2_ADC2CLK            RCC_PLLSAI2CFGR_PLLSAI2REN                                          
#else
#define RCC_PLLSAI2_LTDCCLK            RCC_PLLSAI2CFGR_PLLSAI2REN                                          
#endif                                                                                                            
   
      
    

#endif                          

                                                 
      
    
#define RCC_MSIRANGE_0                 RCC_CR_MSIRANGE_0                        
#define RCC_MSIRANGE_1                 RCC_CR_MSIRANGE_1                        
#define RCC_MSIRANGE_2                 RCC_CR_MSIRANGE_2                        
#define RCC_MSIRANGE_3                 RCC_CR_MSIRANGE_3                        
#define RCC_MSIRANGE_4                 RCC_CR_MSIRANGE_4                        
#define RCC_MSIRANGE_5                 RCC_CR_MSIRANGE_5                        
#define RCC_MSIRANGE_6                 RCC_CR_MSIRANGE_6                        
#define RCC_MSIRANGE_7                 RCC_CR_MSIRANGE_7                        
#define RCC_MSIRANGE_8                 RCC_CR_MSIRANGE_8                        
#define RCC_MSIRANGE_9                 RCC_CR_MSIRANGE_9                        
#define RCC_MSIRANGE_10                RCC_CR_MSIRANGE_10                       
#define RCC_MSIRANGE_11                RCC_CR_MSIRANGE_11                       
   
      
    

                                                     
      
    
#define RCC_CLOCKTYPE_SYSCLK           0x00000001U                              
#define RCC_CLOCKTYPE_HCLK             0x00000002U                            
#define RCC_CLOCKTYPE_PCLK1            0x00000004U                             
#define RCC_CLOCKTYPE_PCLK2            0x00000008U                             
   
      
    

                                                         
      
    
#define RCC_SYSCLKSOURCE_MSI           RCC_CFGR_SW_MSI                                         
#define RCC_SYSCLKSOURCE_HSI           RCC_CFGR_SW_HSI                                         
#define RCC_SYSCLKSOURCE_HSE           RCC_CFGR_SW_HSE                                         
#define RCC_SYSCLKSOURCE_PLLCLK        RCC_CFGR_SW_PLL                                         
   
      
    

                                                                       
      
    
#define RCC_SYSCLKSOURCE_STATUS_MSI    RCC_CFGR_SWS_MSI                                   
#define RCC_SYSCLKSOURCE_STATUS_HSI    RCC_CFGR_SWS_HSI                                   
#define RCC_SYSCLKSOURCE_STATUS_HSE    RCC_CFGR_SWS_HSE                                   
#define RCC_SYSCLKSOURCE_STATUS_PLLCLK RCC_CFGR_SWS_PLL                                   
   
      
    

                                                   
      
    
#define RCC_SYSCLK_DIV1                RCC_CFGR_HPRE_DIV1                             
#define RCC_SYSCLK_DIV2                RCC_CFGR_HPRE_DIV2                              
#define RCC_SYSCLK_DIV4                RCC_CFGR_HPRE_DIV4                              
#define RCC_SYSCLK_DIV8                RCC_CFGR_HPRE_DIV8                              
#define RCC_SYSCLK_DIV16               RCC_CFGR_HPRE_DIV16                              
#define RCC_SYSCLK_DIV64               RCC_CFGR_HPRE_DIV64                              
#define RCC_SYSCLK_DIV128              RCC_CFGR_HPRE_DIV128                              
#define RCC_SYSCLK_DIV256              RCC_CFGR_HPRE_DIV256                              
#define RCC_SYSCLK_DIV512              RCC_CFGR_HPRE_DIV512                              
   
      
    

                                                               
      
    
#define RCC_HCLK_DIV1                  RCC_CFGR_PPRE1_DIV1                          
#define RCC_HCLK_DIV2                  RCC_CFGR_PPRE1_DIV2                           
#define RCC_HCLK_DIV4                  RCC_CFGR_PPRE1_DIV4                           
#define RCC_HCLK_DIV8                  RCC_CFGR_PPRE1_DIV8                           
#define RCC_HCLK_DIV16                 RCC_CFGR_PPRE1_DIV16                           
   
      
    

                                                   
      
    
#define RCC_RTCCLKSOURCE_NONE          0x00000000U                                            
#define RCC_RTCCLKSOURCE_LSE           RCC_BDCR_RTCSEL_0                                                  
#define RCC_RTCCLKSOURCE_LSI           RCC_BDCR_RTCSEL_1                                                  
#define RCC_RTCCLKSOURCE_HSE_DIV32     RCC_BDCR_RTCSEL                                                                  
   
      
    

                                     
      
    
#define RCC_MCO1                       0x00000000U
#define RCC_MCO                        RCC_MCO1                                                                 
   
      
    

                                                     
      
    
#define RCC_MCO1SOURCE_NOCLOCK         0x00000000U                                                                          
#define RCC_MCO1SOURCE_SYSCLK          RCC_CFGR_MCOSEL_0                                                             
#define RCC_MCO1SOURCE_MSI             RCC_CFGR_MCOSEL_1                                                          
#define RCC_MCO1SOURCE_HSI             (RCC_CFGR_MCOSEL_0| RCC_CFGR_MCOSEL_1)                                     
#define RCC_MCO1SOURCE_HSE             RCC_CFGR_MCOSEL_2                                                          
#define RCC_MCO1SOURCE_PLLCLK          (RCC_CFGR_MCOSEL_0|RCC_CFGR_MCOSEL_2)                                         
#define RCC_MCO1SOURCE_LSI             (RCC_CFGR_MCOSEL_1|RCC_CFGR_MCOSEL_2)                                      
#define RCC_MCO1SOURCE_LSE             (RCC_CFGR_MCOSEL_0|RCC_CFGR_MCOSEL_1|RCC_CFGR_MCOSEL_2)                                     
#if defined(RCC_HSI48_SUPPORT)
#define RCC_MCO1SOURCE_HSI48           RCC_CFGR_MCOSEL_3                                                                                          
#endif                        
   
      
    

                                                           
      
    
#define RCC_MCODIV_1                   RCC_CFGR_MCOPRE_DIV1                             
#define RCC_MCODIV_2                   RCC_CFGR_MCOPRE_DIV2                             
#define RCC_MCODIV_4                   RCC_CFGR_MCOPRE_DIV4                             
#define RCC_MCODIV_8                   RCC_CFGR_MCOPRE_DIV8                             
#define RCC_MCODIV_16                  RCC_CFGR_MCOPRE_DIV16                             
   
      
    

                                      
      
    
#define RCC_IT_LSIRDY                  RCC_CIFR_LSIRDYF                                      
#define RCC_IT_LSERDY                  RCC_CIFR_LSERDYF                                      
#define RCC_IT_MSIRDY                  RCC_CIFR_MSIRDYF                                      
#define RCC_IT_HSIRDY                  RCC_CIFR_HSIRDYF                                        
#define RCC_IT_HSERDY                  RCC_CIFR_HSERDYF                                      
#define RCC_IT_PLLRDY                  RCC_CIFR_PLLRDYF                                      
#if defined(RCC_PLLSAI1_SUPPORT)
#define RCC_IT_PLLSAI1RDY              RCC_CIFR_PLLSAI1RDYF                                      
#endif                          
#if defined(RCC_PLLSAI2_SUPPORT)
#define RCC_IT_PLLSAI2RDY              RCC_CIFR_PLLSAI2RDYF                                      
#endif                          
#define RCC_IT_CSS                     RCC_CIFR_CSSF                                                    
#define RCC_IT_LSECSS                  RCC_CIFR_LSECSSF                                                     
#if defined(RCC_HSI48_SUPPORT)
#define RCC_IT_HSI48RDY                RCC_CIFR_HSI48RDYF                                     
#endif                        
   
      
    

                            
                                                
                                                      
                                     
                                      
                                        
                                       
                                         
      
    
                              
#define RCC_FLAG_MSIRDY                ((CR_REG_INDEX << 5U) | RCC_CR_MSIRDY_Pos)                       
#define RCC_FLAG_HSIRDY                ((CR_REG_INDEX << 5U) | RCC_CR_HSIRDY_Pos)                       
#define RCC_FLAG_HSERDY                ((CR_REG_INDEX << 5U) | RCC_CR_HSERDY_Pos)                       
#define RCC_FLAG_PLLRDY                ((CR_REG_INDEX << 5U) | RCC_CR_PLLRDY_Pos)                       
#if defined(RCC_PLLSAI1_SUPPORT)
#define RCC_FLAG_PLLSAI1RDY            ((CR_REG_INDEX << 5U) | RCC_CR_PLLSAI1RDY_Pos)                           
#endif                          
#if defined(RCC_PLLSAI2_SUPPORT)
#define RCC_FLAG_PLLSAI2RDY            ((CR_REG_INDEX << 5U) | RCC_CR_PLLSAI2RDY_Pos)                           
#endif                          

                                
#define RCC_FLAG_LSERDY                ((BDCR_REG_INDEX << 5U) | RCC_BDCR_LSERDY_Pos)                        
#define RCC_FLAG_LSECSSD               ((BDCR_REG_INDEX << 5U) | RCC_BDCR_LSECSSD_Pos)                                                 

                               
#define RCC_FLAG_LSIRDY                ((CSR_REG_INDEX << 5U) | RCC_CSR_LSIRDY_Pos)                          
#define RCC_FLAG_FWRST                 ((CSR_REG_INDEX << 5U) | RCC_CSR_FWRSTF_Pos)                               
#define RCC_FLAG_OBLRST                ((CSR_REG_INDEX << 5U) | RCC_CSR_OBLRSTF_Pos)                                        
#define RCC_FLAG_PINRST                ((CSR_REG_INDEX << 5U) | RCC_CSR_PINRSTF_Pos)                         
#define RCC_FLAG_BORRST                ((CSR_REG_INDEX << 5U) | RCC_CSR_BORRSTF_Pos)                         
#define RCC_FLAG_SFTRST                ((CSR_REG_INDEX << 5U) | RCC_CSR_SFTRSTF_Pos)                              
#define RCC_FLAG_IWDGRST               ((CSR_REG_INDEX << 5U) | RCC_CSR_IWDGRSTF_Pos)                                         
#define RCC_FLAG_WWDGRST               ((CSR_REG_INDEX << 5U) | RCC_CSR_WWDGRSTF_Pos)                                    
#define RCC_FLAG_LPWRRST               ((CSR_REG_INDEX << 5U) | RCC_CSR_LPWRRSTF_Pos)                              

#if defined(RCC_HSI48_SUPPORT)
                                 
#define RCC_FLAG_HSI48RDY              ((CRRCR_REG_INDEX << 5U) | RCC_CRRCR_HSI48RDY_Pos)                         
#endif                        
   
      
    

                                                  
      
    
#define RCC_LSEDRIVE_LOW                 0x00000000U                                         
#define RCC_LSEDRIVE_MEDIUMLOW           RCC_BDCR_LSEDRV_0                                          
#define RCC_LSEDRIVE_MEDIUMHIGH          RCC_BDCR_LSEDRV_1                                           
#define RCC_LSEDRIVE_HIGH                RCC_BDCR_LSEDRV                                      
   
      
    

                                                          
      
    
#define RCC_STOP_WAKEUPCLOCK_MSI       0x00000000U                                                        
#define RCC_STOP_WAKEUPCLOCK_HSI       RCC_CFGR_STOPWUCK                                                  
   
      
    

   
      
    

                                                                                

                                                     
      
    

                                                                                           
                                                        
                                                                                    
                                                                                    
                     
      
    

#define __HAL_RCC_DMA1_CLK_ENABLE()            do { \
                                                 __IO uint32_t tmpreg; \
                                                 SET_BIT(RCC->AHB1ENR, RCC_AHB1ENR_DMA1EN); \
                                                                                                    \
                                                 tmpreg = READ_BIT(RCC->AHB1ENR, RCC_AHB1ENR_DMA1EN); \
                                                 UNUSED(tmpreg); \
                                               } while(0)

#define __HAL_RCC_DMA2_CLK_ENABLE()            do { \
                                                 __IO uint32_t tmpreg; \
                                                 SET_BIT(RCC->AHB1ENR, RCC_AHB1ENR_DMA2EN); \
                                                                                                    \
                                                 tmpreg = READ_BIT(RCC->AHB1ENR, RCC_AHB1ENR_DMA2EN); \
                                                 UNUSED(tmpreg); \
                                               } while(0)

#if defined(DMAMUX1)
#define __HAL_RCC_DMAMUX1_CLK_ENABLE()         do { \
                                                 __IO uint32_t tmpreg; \
                                                 SET_BIT(RCC->AHB1ENR, RCC_AHB1ENR_DMAMUX1EN); \
                                                                                                    \
                                                 tmpreg = READ_BIT(RCC->AHB1ENR, RCC_AHB1ENR_DMAMUX1EN); \
                                                 UNUSED(tmpreg); \
                                               } while(0)
#endif              

#define __HAL_RCC_FLASH_CLK_ENABLE()           do { \
                                                 __IO uint32_t tmpreg; \
                                                 SET_BIT(RCC->AHB1ENR, RCC_AHB1ENR_FLASHEN); \
                                                                                                    \
                                                 tmpreg = READ_BIT(RCC->AHB1ENR, RCC_AHB1ENR_FLASHEN); \
                                                 UNUSED(tmpreg); \
                                               } while(0)

#define __HAL_RCC_CRC_CLK_ENABLE()             do { \
                                                 __IO uint32_t tmpreg; \
                                                 SET_BIT(RCC->AHB1ENR, RCC_AHB1ENR_CRCEN); \
                                                                                                    \
                                                 tmpreg = READ_BIT(RCC->AHB1ENR, RCC_AHB1ENR_CRCEN); \
                                                 UNUSED(tmpreg); \
                                               } while(0)

#define __HAL_RCC_TSC_CLK_ENABLE()             do { \
                                                 __IO uint32_t tmpreg; \
                                                 SET_BIT(RCC->AHB1ENR, RCC_AHB1ENR_TSCEN); \
                                                                                                    \
                                                 tmpreg = READ_BIT(RCC->AHB1ENR, RCC_AHB1ENR_TSCEN); \
                                                 UNUSED(tmpreg); \
                                               } while(0)

#if defined(DMA2D)
#define __HAL_RCC_DMA2D_CLK_ENABLE()           do { \
                                                 __IO uint32_t tmpreg; \
                                                 SET_BIT(RCC->AHB1ENR, RCC_AHB1ENR_DMA2DEN); \
                                                                                                    \
                                                 tmpreg = READ_BIT(RCC->AHB1ENR, RCC_AHB1ENR_DMA2DEN); \
                                                 UNUSED(tmpreg); \
                                               } while(0)
#endif            

#if defined(GFXMMU)
#define __HAL_RCC_GFXMMU_CLK_ENABLE()          do { \
                                                 __IO uint32_t tmpreg; \
                                                 SET_BIT(RCC->AHB1ENR, RCC_AHB1ENR_GFXMMUEN); \
                                                                                                    \
                                                 tmpreg = READ_BIT(RCC->AHB1ENR, RCC_AHB1ENR_GFXMMUEN); \
                                                 UNUSED(tmpreg); \
                                               } while(0)
#endif             


#define __HAL_RCC_DMA1_CLK_DISABLE()           CLEAR_BIT(RCC->AHB1ENR, RCC_AHB1ENR_DMA1EN)

#define __HAL_RCC_DMA2_CLK_DISABLE()           CLEAR_BIT(RCC->AHB1ENR, RCC_AHB1ENR_DMA2EN)

#if defined(DMAMUX1)
#define __HAL_RCC_DMAMUX1_CLK_DISABLE()        CLEAR_BIT(RCC->AHB1ENR, RCC_AHB1ENR_DMAMUX1EN)
#endif              

#define __HAL_RCC_FLASH_CLK_DISABLE()          CLEAR_BIT(RCC->AHB1ENR, RCC_AHB1ENR_FLASHEN)

#define __HAL_RCC_CRC_CLK_DISABLE()            CLEAR_BIT(RCC->AHB1ENR, RCC_AHB1ENR_CRCEN)

#define __HAL_RCC_TSC_CLK_DISABLE()            CLEAR_BIT(RCC->AHB1ENR, RCC_AHB1ENR_TSCEN)

#if defined(DMA2D)
#define __HAL_RCC_DMA2D_CLK_DISABLE()          CLEAR_BIT(RCC->AHB1ENR, RCC_AHB1ENR_DMA2DEN)
#endif            

#if defined(GFXMMU)
#define __HAL_RCC_GFXMMU_CLK_DISABLE()         CLEAR_BIT(RCC->AHB1ENR, RCC_AHB1ENR_GFXMMUEN)
#endif             

   
      
    

                                                                                           
                                                        
                                                                                    
                                                                                    
                     
      
    

#define __HAL_RCC_GPIOA_CLK_ENABLE()           do { \
                                                 __IO uint32_t tmpreg; \
                                                 SET_BIT(RCC->AHB2ENR, RCC_AHB2ENR_GPIOAEN); \
                                                                                                    \
                                                 tmpreg = READ_BIT(RCC->AHB2ENR, RCC_AHB2ENR_GPIOAEN); \
                                                 UNUSED(tmpreg); \
                                               } while(0)

#define __HAL_RCC_GPIOB_CLK_ENABLE()           do { \
                                                 __IO uint32_t tmpreg; \
                                                 SET_BIT(RCC->AHB2ENR, RCC_AHB2ENR_GPIOBEN); \
                                                                                                    \
                                                 tmpreg = READ_BIT(RCC->AHB2ENR, RCC_AHB2ENR_GPIOBEN); \
                                                 UNUSED(tmpreg); \
                                               } while(0)

#define __HAL_RCC_GPIOC_CLK_ENABLE()           do { \
                                                 __IO uint32_t tmpreg; \
                                                 SET_BIT(RCC->AHB2ENR, RCC_AHB2ENR_GPIOCEN); \
                                                                                                    \
                                                 tmpreg = READ_BIT(RCC->AHB2ENR, RCC_AHB2ENR_GPIOCEN); \
                                                 UNUSED(tmpreg); \
                                               } while(0)

#if defined(GPIOD)
#define __HAL_RCC_GPIOD_CLK_ENABLE()           do { \
                                                 __IO uint32_t tmpreg; \
                                                 SET_BIT(RCC->AHB2ENR, RCC_AHB2ENR_GPIODEN); \
                                                                                                    \
                                                 tmpreg = READ_BIT(RCC->AHB2ENR, RCC_AHB2ENR_GPIODEN); \
                                                 UNUSED(tmpreg); \
                                               } while(0)
#endif            

#if defined(GPIOE)
#define __HAL_RCC_GPIOE_CLK_ENABLE()           do { \
                                                 __IO uint32_t tmpreg; \
                                                 SET_BIT(RCC->AHB2ENR, RCC_AHB2ENR_GPIOEEN); \
                                                                                                    \
                                                 tmpreg = READ_BIT(RCC->AHB2ENR, RCC_AHB2ENR_GPIOEEN); \
                                                 UNUSED(tmpreg); \
                                               } while(0)
#endif            

#if defined(GPIOF)
#define __HAL_RCC_GPIOF_CLK_ENABLE()           do { \
                                                 __IO uint32_t tmpreg; \
                                                 SET_BIT(RCC->AHB2ENR, RCC_AHB2ENR_GPIOFEN); \
                                                                                                    \
                                                 tmpreg = READ_BIT(RCC->AHB2ENR, RCC_AHB2ENR_GPIOFEN); \
                                                 UNUSED(tmpreg); \
                                               } while(0)
#endif            

#if defined(GPIOG)
#define __HAL_RCC_GPIOG_CLK_ENABLE()           do { \
                                                 __IO uint32_t tmpreg; \
                                                 SET_BIT(RCC->AHB2ENR, RCC_AHB2ENR_GPIOGEN); \
                                                                                                    \
                                                 tmpreg = READ_BIT(RCC->AHB2ENR, RCC_AHB2ENR_GPIOGEN); \
                                                 UNUSED(tmpreg); \
                                               } while(0)
#endif            

#define __HAL_RCC_GPIOH_CLK_ENABLE()           do { \
                                                 __IO uint32_t tmpreg; \
                                                 SET_BIT(RCC->AHB2ENR, RCC_AHB2ENR_GPIOHEN); \
                                                                                                    \
                                                 tmpreg = READ_BIT(RCC->AHB2ENR, RCC_AHB2ENR_GPIOHEN); \
                                                 UNUSED(tmpreg); \
                                               } while(0)

#if defined(GPIOI)
#define __HAL_RCC_GPIOI_CLK_ENABLE()           do { \
                                                 __IO uint32_t tmpreg; \
                                                 SET_BIT(RCC->AHB2ENR, RCC_AHB2ENR_GPIOIEN); \
                                                                                                    \
                                                 tmpreg = READ_BIT(RCC->AHB2ENR, RCC_AHB2ENR_GPIOIEN); \
                                                 UNUSED(tmpreg); \
                                               } while(0)
#endif            

#if defined(USB_OTG_FS)
#define __HAL_RCC_USB_OTG_FS_CLK_ENABLE()      do { \
                                                 __IO uint32_t tmpreg; \
                                                 SET_BIT(RCC->AHB2ENR, RCC_AHB2ENR_OTGFSEN); \
                                                                                                    \
                                                 tmpreg = READ_BIT(RCC->AHB2ENR, RCC_AHB2ENR_OTGFSEN); \
                                                 UNUSED(tmpreg); \
                                               } while(0)
#endif                 

#define __HAL_RCC_ADC_CLK_ENABLE()             do { \
                                                 __IO uint32_t tmpreg; \
                                                 SET_BIT(RCC->AHB2ENR, RCC_AHB2ENR_ADCEN); \
                                                                                                    \
                                                 tmpreg = READ_BIT(RCC->AHB2ENR, RCC_AHB2ENR_ADCEN); \
                                                 UNUSED(tmpreg); \
                                               } while(0)

#if defined(DCMI)
#define __HAL_RCC_DCMI_CLK_ENABLE()            do { \
                                                 __IO uint32_t tmpreg; \
                                                 SET_BIT(RCC->AHB2ENR, RCC_AHB2ENR_DCMIEN); \
                                                                                                    \
                                                 tmpreg = READ_BIT(RCC->AHB2ENR, RCC_AHB2ENR_DCMIEN); \
                                                 UNUSED(tmpreg); \
                                               } while(0)
#endif           

#if defined(PKA)
#define __HAL_RCC_PKA_CLK_ENABLE()             do { \
                                                 __IO uint32_t tmpreg; \
                                                 SET_BIT(RCC->AHB2ENR, RCC_AHB2ENR_PKAEN); \
                                                                                                    \
                                                 tmpreg = READ_BIT(RCC->AHB2ENR, RCC_AHB2ENR_PKAEN); \
                                                 UNUSED(tmpreg); \
                                               } while(0)
#endif          

#if defined(AES)
#define __HAL_RCC_AES_CLK_ENABLE()             do { \
                                                 __IO uint32_t tmpreg; \
                                                 SET_BIT(RCC->AHB2ENR, RCC_AHB2ENR_AESEN); \
                                                                                                    \
                                                 tmpreg = READ_BIT(RCC->AHB2ENR, RCC_AHB2ENR_AESEN); \
                                                 UNUSED(tmpreg); \
                                               } while(0)
#endif          

#if defined(HASH)
#define __HAL_RCC_HASH_CLK_ENABLE()             do { \
                                                 __IO uint32_t tmpreg; \
                                                 SET_BIT(RCC->AHB2ENR, RCC_AHB2ENR_HASHEN); \
                                                                                                    \
                                                 tmpreg = READ_BIT(RCC->AHB2ENR, RCC_AHB2ENR_HASHEN); \
                                                 UNUSED(tmpreg); \
                                               } while(0)
#endif           

#define __HAL_RCC_RNG_CLK_ENABLE()             do { \
                                                 __IO uint32_t tmpreg; \
                                                 SET_BIT(RCC->AHB2ENR, RCC_AHB2ENR_RNGEN); \
                                                                                                    \
                                                 tmpreg = READ_BIT(RCC->AHB2ENR, RCC_AHB2ENR_RNGEN); \
                                                 UNUSED(tmpreg); \
                                               } while(0)

#if defined(OCTOSPIM)
#define __HAL_RCC_OSPIM_CLK_ENABLE()           do { \
                                                 __IO uint32_t tmpreg; \
                                                 SET_BIT(RCC->AHB2ENR, RCC_AHB2ENR_OSPIMEN); \
                                                                                                    \
                                                 tmpreg = READ_BIT(RCC->AHB2ENR, RCC_AHB2ENR_OSPIMEN); \
                                                 UNUSED(tmpreg); \
                                               } while(0)
#endif               

#if defined(SDMMC1) && defined(RCC_AHB2ENR_SDMMC1EN)
#define __HAL_RCC_SDMMC1_CLK_ENABLE()          do { \
                                                 __IO uint32_t tmpreg; \
                                                 SET_BIT(RCC->AHB2ENR, RCC_AHB2ENR_SDMMC1EN); \
                                                                                                    \
                                                 tmpreg = READ_BIT(RCC->AHB2ENR, RCC_AHB2ENR_SDMMC1EN); \
                                                 UNUSED(tmpreg); \
                                               } while(0)
#endif                                     

#if defined(SDMMC2)
#define __HAL_RCC_SDMMC2_CLK_ENABLE()          do { \
                                                 __IO uint32_t tmpreg; \
                                                 SET_BIT(RCC->AHB2ENR, RCC_AHB2ENR_SDMMC2EN); \
                                                                                                    \
                                                 tmpreg = READ_BIT(RCC->AHB2ENR, RCC_AHB2ENR_SDMMC2EN); \
                                                 UNUSED(tmpreg); \
                                               } while(0)
#endif             


#define __HAL_RCC_GPIOA_CLK_DISABLE()          CLEAR_BIT(RCC->AHB2ENR, RCC_AHB2ENR_GPIOAEN)

#define __HAL_RCC_GPIOB_CLK_DISABLE()          CLEAR_BIT(RCC->AHB2ENR, RCC_AHB2ENR_GPIOBEN)

#define __HAL_RCC_GPIOC_CLK_DISABLE()          CLEAR_BIT(RCC->AHB2ENR, RCC_AHB2ENR_GPIOCEN)

#if defined(GPIOD)
#define __HAL_RCC_GPIOD_CLK_DISABLE()          CLEAR_BIT(RCC->AHB2ENR, RCC_AHB2ENR_GPIODEN)
#endif            

#if defined(GPIOE)
#define __HAL_RCC_GPIOE_CLK_DISABLE()          CLEAR_BIT(RCC->AHB2ENR, RCC_AHB2ENR_GPIOEEN)
#endif            

#if defined(GPIOF)
#define __HAL_RCC_GPIOF_CLK_DISABLE()          CLEAR_BIT(RCC->AHB2ENR, RCC_AHB2ENR_GPIOFEN)
#endif            

#if defined(GPIOG)
#define __HAL_RCC_GPIOG_CLK_DISABLE()          CLEAR_BIT(RCC->AHB2ENR, RCC_AHB2ENR_GPIOGEN)
#endif            

#define __HAL_RCC_GPIOH_CLK_DISABLE()          CLEAR_BIT(RCC->AHB2ENR, RCC_AHB2ENR_GPIOHEN)

#if defined(GPIOI)
#define __HAL_RCC_GPIOI_CLK_DISABLE()          CLEAR_BIT(RCC->AHB2ENR, RCC_AHB2ENR_GPIOIEN)
#endif            

#if defined(USB_OTG_FS)
#define __HAL_RCC_USB_OTG_FS_CLK_DISABLE()     CLEAR_BIT(RCC->AHB2ENR, RCC_AHB2ENR_OTGFSEN);
#endif                 

#define __HAL_RCC_ADC_CLK_DISABLE()            CLEAR_BIT(RCC->AHB2ENR, RCC_AHB2ENR_ADCEN)

#if defined(DCMI)
#define __HAL_RCC_DCMI_CLK_DISABLE()           CLEAR_BIT(RCC->AHB2ENR, RCC_AHB2ENR_DCMIEN)
#endif           

#if defined(PKA)
#define __HAL_RCC_PKA_CLK_DISABLE()            CLEAR_BIT(RCC->AHB2ENR, RCC_AHB2ENR_PKAEN)
#endif          

#if defined(AES)
#define __HAL_RCC_AES_CLK_DISABLE()            CLEAR_BIT(RCC->AHB2ENR, RCC_AHB2ENR_AESEN);
#endif          

#if defined(HASH)
#define __HAL_RCC_HASH_CLK_DISABLE()           CLEAR_BIT(RCC->AHB2ENR, RCC_AHB2ENR_HASHEN)
#endif           

#define __HAL_RCC_RNG_CLK_DISABLE()            CLEAR_BIT(RCC->AHB2ENR, RCC_AHB2ENR_RNGEN)

#if defined(OCTOSPIM)
#define __HAL_RCC_OSPIM_CLK_DISABLE()          CLEAR_BIT(RCC->AHB2ENR, RCC_AHB2ENR_OSPIMEN)
#endif               

#if defined(SDMMC1) && defined(RCC_AHB2ENR_SDMMC1EN)
#define __HAL_RCC_SDMMC1_CLK_DISABLE()         CLEAR_BIT(RCC->AHB2ENR, RCC_AHB2ENR_SDMMC1EN)
#endif                                     

#if defined(SDMMC2)
#define __HAL_RCC_SDMMC2_CLK_DISABLE()         CLEAR_BIT(RCC->AHB2ENR, RCC_AHB2ENR_SDMMC2EN)
#endif             

   
      
    

                                                                                
                                                        
                                                                                    
                                                                                    
                     
      
    

#if defined(FMC_BANK1)
#define __HAL_RCC_FMC_CLK_ENABLE()             do { \
                                                 __IO uint32_t tmpreg; \
                                                 SET_BIT(RCC->AHB3ENR, RCC_AHB3ENR_FMCEN); \
                                                                                                    \
                                                 tmpreg = READ_BIT(RCC->AHB3ENR, RCC_AHB3ENR_FMCEN); \
                                                 UNUSED(tmpreg); \
                                               } while(0)
#endif                

#if defined(QUADSPI)
#define __HAL_RCC_QSPI_CLK_ENABLE()            do { \
                                                 __IO uint32_t tmpreg; \
                                                 SET_BIT(RCC->AHB3ENR, RCC_AHB3ENR_QSPIEN); \
                                                                                                    \
                                                 tmpreg = READ_BIT(RCC->AHB3ENR, RCC_AHB3ENR_QSPIEN); \
                                                 UNUSED(tmpreg); \
                                               } while(0)
#endif              

#if defined(OCTOSPI1)
#define __HAL_RCC_OSPI1_CLK_ENABLE()           do { \
                                                 __IO uint32_t tmpreg; \
                                                 SET_BIT(RCC->AHB3ENR, RCC_AHB3ENR_OSPI1EN); \
                                                                                                    \
                                                 tmpreg = READ_BIT(RCC->AHB3ENR, RCC_AHB3ENR_OSPI1EN); \
                                                 UNUSED(tmpreg); \
                                               } while(0)
#endif               

#if defined(OCTOSPI2)
#define __HAL_RCC_OSPI2_CLK_ENABLE()           do { \
                                                 __IO uint32_t tmpreg; \
                                                 SET_BIT(RCC->AHB3ENR, RCC_AHB3ENR_OSPI2EN); \
                                                                                                    \
                                                 tmpreg = READ_BIT(RCC->AHB3ENR, RCC_AHB3ENR_OSPI2EN); \
                                                 UNUSED(tmpreg); \
                                               } while(0)
#endif               

#if defined(FMC_BANK1)
#define __HAL_RCC_FMC_CLK_DISABLE()            CLEAR_BIT(RCC->AHB3ENR, RCC_AHB3ENR_FMCEN)
#endif                

#if defined(QUADSPI)
#define __HAL_RCC_QSPI_CLK_DISABLE()           CLEAR_BIT(RCC->AHB3ENR, RCC_AHB3ENR_QSPIEN)
#endif              

#if defined(OCTOSPI1)
#define __HAL_RCC_OSPI1_CLK_DISABLE()          CLEAR_BIT(RCC->AHB3ENR, RCC_AHB3ENR_OSPI1EN)
#endif               

#if defined(OCTOSPI2)
#define __HAL_RCC_OSPI2_CLK_DISABLE()          CLEAR_BIT(RCC->AHB3ENR, RCC_AHB3ENR_OSPI2EN)
#endif               

   
      
    

                                                                                
                                                        
                                                                                    
                                                                                    
                     
      
    

#define __HAL_RCC_TIM2_CLK_ENABLE()            do { \
                                                 __IO uint32_t tmpreg; \
                                                 SET_BIT(RCC->APB1ENR1, RCC_APB1ENR1_TIM2EN); \
                                                                                                    \
                                                 tmpreg = READ_BIT(RCC->APB1ENR1, RCC_APB1ENR1_TIM2EN); \
                                                 UNUSED(tmpreg); \
                                               } while(0)

#if defined(TIM3)
#define __HAL_RCC_TIM3_CLK_ENABLE()            do { \
                                                 __IO uint32_t tmpreg; \
                                                 SET_BIT(RCC->APB1ENR1, RCC_APB1ENR1_TIM3EN); \
                                                                                                    \
                                                 tmpreg = READ_BIT(RCC->APB1ENR1, RCC_APB1ENR1_TIM3EN); \
                                                 UNUSED(tmpreg); \
                                               } while(0)
#endif           

#if defined(TIM4)
#define __HAL_RCC_TIM4_CLK_ENABLE()            do { \
                                                 __IO uint32_t tmpreg; \
                                                 SET_BIT(RCC->APB1ENR1, RCC_APB1ENR1_TIM4EN); \
                                                                                                    \
                                                 tmpreg = READ_BIT(RCC->APB1ENR1, RCC_APB1ENR1_TIM4EN); \
                                                 UNUSED(tmpreg); \
                                               } while(0)
#endif           

#if defined(TIM5)
#define __HAL_RCC_TIM5_CLK_ENABLE()            do { \
                                                 __IO uint32_t tmpreg; \
                                                 SET_BIT(RCC->APB1ENR1, RCC_APB1ENR1_TIM5EN); \
                                                                                                    \
                                                 tmpreg = READ_BIT(RCC->APB1ENR1, RCC_APB1ENR1_TIM5EN); \
                                                 UNUSED(tmpreg); \
                                               } while(0)
#endif           

#define __HAL_RCC_TIM6_CLK_ENABLE()            do { \
                                                 __IO uint32_t tmpreg; \
                                                 SET_BIT(RCC->APB1ENR1, RCC_APB1ENR1_TIM6EN); \
                                                                                                    \
                                                 tmpreg = READ_BIT(RCC->APB1ENR1, RCC_APB1ENR1_TIM6EN); \
                                                 UNUSED(tmpreg); \
                                               } while(0)

#if defined(TIM7)
#define __HAL_RCC_TIM7_CLK_ENABLE()            do { \
                                                 __IO uint32_t tmpreg; \
                                                 SET_BIT(RCC->APB1ENR1, RCC_APB1ENR1_TIM7EN); \
                                                                                                    \
                                                 tmpreg = READ_BIT(RCC->APB1ENR1, RCC_APB1ENR1_TIM7EN); \
                                                 UNUSED(tmpreg); \
                                               } while(0)
#endif           

#if defined(LCD)
#define __HAL_RCC_LCD_CLK_ENABLE()             do { \
                                                 __IO uint32_t tmpreg; \
                                                 SET_BIT(RCC->APB1ENR1, RCC_APB1ENR1_LCDEN); \
                                                                                                    \
                                                 tmpreg = READ_BIT(RCC->APB1ENR1, RCC_APB1ENR1_LCDEN); \
                                                 UNUSED(tmpreg); \
                                               } while(0)
#endif          

#if defined(RCC_APB1ENR1_RTCAPBEN)
#define __HAL_RCC_RTCAPB_CLK_ENABLE()          do { \
                                                 __IO uint32_t tmpreg; \
                                                 SET_BIT(RCC->APB1ENR1, RCC_APB1ENR1_RTCAPBEN); \
                                                                                                    \
                                                 tmpreg = READ_BIT(RCC->APB1ENR1, RCC_APB1ENR1_RTCAPBEN); \
                                                 UNUSED(tmpreg); \
                                               } while(0)
#endif                            

#define __HAL_RCC_WWDG_CLK_ENABLE()            do { \
                                                 __IO uint32_t tmpreg; \
                                                 SET_BIT(RCC->APB1ENR1, RCC_APB1ENR1_WWDGEN); \
                                                                                                    \
                                                 tmpreg = READ_BIT(RCC->APB1ENR1, RCC_APB1ENR1_WWDGEN); \
                                                 UNUSED(tmpreg); \
                                               } while(0)

#if defined(SPI2)
#define __HAL_RCC_SPI2_CLK_ENABLE()            do { \
                                                 __IO uint32_t tmpreg; \
                                                 SET_BIT(RCC->APB1ENR1, RCC_APB1ENR1_SPI2EN); \
                                                                                                    \
                                                 tmpreg = READ_BIT(RCC->APB1ENR1, RCC_APB1ENR1_SPI2EN); \
                                                 UNUSED(tmpreg); \
                                               } while(0)
#endif           

#if defined(SPI3)
#define __HAL_RCC_SPI3_CLK_ENABLE()            do { \
                                                 __IO uint32_t tmpreg; \
                                                 SET_BIT(RCC->APB1ENR1, RCC_APB1ENR1_SPI3EN); \
                                                                                                    \
                                                 tmpreg = READ_BIT(RCC->APB1ENR1, RCC_APB1ENR1_SPI3EN); \
                                                 UNUSED(tmpreg); \
                                               } while(0)
#endif           

#define __HAL_RCC_USART2_CLK_ENABLE()          do { \
                                                 __IO uint32_t tmpreg; \
                                                 SET_BIT(RCC->APB1ENR1, RCC_APB1ENR1_USART2EN); \
                                                                                                    \
                                                 tmpreg = READ_BIT(RCC->APB1ENR1, RCC_APB1ENR1_USART2EN); \
                                                 UNUSED(tmpreg); \
                                               } while(0)

#if defined(USART3)
#define __HAL_RCC_USART3_CLK_ENABLE()          do { \
                                                 __IO uint32_t tmpreg; \
                                                 SET_BIT(RCC->APB1ENR1, RCC_APB1ENR1_USART3EN); \
                                                                                                    \
                                                 tmpreg = READ_BIT(RCC->APB1ENR1, RCC_APB1ENR1_USART3EN); \
                                                 UNUSED(tmpreg); \
                                               } while(0)
#endif             

#if defined(UART4)
#define __HAL_RCC_UART4_CLK_ENABLE()           do { \
                                                 __IO uint32_t tmpreg; \
                                                 SET_BIT(RCC->APB1ENR1, RCC_APB1ENR1_UART4EN); \
                                                                                                    \
                                                 tmpreg = READ_BIT(RCC->APB1ENR1, RCC_APB1ENR1_UART4EN); \
                                                 UNUSED(tmpreg); \
                                               } while(0)
#endif            

#if defined(UART5)
#define __HAL_RCC_UART5_CLK_ENABLE()           do { \
                                                 __IO uint32_t tmpreg; \
                                                 SET_BIT(RCC->APB1ENR1, RCC_APB1ENR1_UART5EN); \
                                                                                                    \
                                                 tmpreg = READ_BIT(RCC->APB1ENR1, RCC_APB1ENR1_UART5EN); \
                                                 UNUSED(tmpreg); \
                                               } while(0)
#endif            

#define __HAL_RCC_I2C1_CLK_ENABLE()            do { \
                                                 __IO uint32_t tmpreg; \
                                                 SET_BIT(RCC->APB1ENR1, RCC_APB1ENR1_I2C1EN); \
                                                                                                    \
                                                 tmpreg = READ_BIT(RCC->APB1ENR1, RCC_APB1ENR1_I2C1EN); \
                                                 UNUSED(tmpreg); \
                                               } while(0)

#if defined(I2C2)
#define __HAL_RCC_I2C2_CLK_ENABLE()            do { \
                                                 __IO uint32_t tmpreg; \
                                                 SET_BIT(RCC->APB1ENR1, RCC_APB1ENR1_I2C2EN); \
                                                                                                    \
                                                 tmpreg = READ_BIT(RCC->APB1ENR1, RCC_APB1ENR1_I2C2EN); \
                                                 UNUSED(tmpreg); \
                                               } while(0)
#endif           

#define __HAL_RCC_I2C3_CLK_ENABLE()            do { \
                                                 __IO uint32_t tmpreg; \
                                                 SET_BIT(RCC->APB1ENR1, RCC_APB1ENR1_I2C3EN); \
                                                                                                    \
                                                 tmpreg = READ_BIT(RCC->APB1ENR1, RCC_APB1ENR1_I2C3EN); \
                                                 UNUSED(tmpreg); \
                                               } while(0)

#if defined(I2C4)
#define __HAL_RCC_I2C4_CLK_ENABLE()            do { \
                                                 __IO uint32_t tmpreg; \
                                                 SET_BIT(RCC->APB1ENR2, RCC_APB1ENR2_I2C4EN); \
                                                                                                    \
                                                 tmpreg = READ_BIT(RCC->APB1ENR2, RCC_APB1ENR2_I2C4EN); \
                                                 UNUSED(tmpreg); \
                                               } while(0)
#endif           

#if defined(CRS)
#define __HAL_RCC_CRS_CLK_ENABLE()             do { \
                                                 __IO uint32_t tmpreg; \
                                                 SET_BIT(RCC->APB1ENR1, RCC_APB1ENR1_CRSEN); \
                                                                                                    \
                                                 tmpreg = READ_BIT(RCC->APB1ENR1, RCC_APB1ENR1_CRSEN); \
                                                 UNUSED(tmpreg); \
                                               } while(0)
#endif          

#if defined(CAN1)
#define __HAL_RCC_CAN1_CLK_ENABLE()            do { \
                                                 __IO uint32_t tmpreg; \
                                                 SET_BIT(RCC->APB1ENR1, RCC_APB1ENR1_CAN1EN); \
                                                                                                    \
                                                 tmpreg = READ_BIT(RCC->APB1ENR1, RCC_APB1ENR1_CAN1EN); \
                                                 UNUSED(tmpreg); \
                                               } while(0)
#endif           

#if defined(CAN2)
#define __HAL_RCC_CAN2_CLK_ENABLE()            do { \
                                                 __IO uint32_t tmpreg; \
                                                 SET_BIT(RCC->APB1ENR1, RCC_APB1ENR1_CAN2EN); \
                                                                                                    \
                                                 tmpreg = READ_BIT(RCC->APB1ENR1, RCC_APB1ENR1_CAN2EN); \
                                                 UNUSED(tmpreg); \
                                               } while(0)
#endif           

#if defined(USB)
#define __HAL_RCC_USB_CLK_ENABLE()             do { \
                                                 __IO uint32_t tmpreg; \
                                                 SET_BIT(RCC->APB1ENR1, RCC_APB1ENR1_USBFSEN); \
                                                                                                    \
                                                 tmpreg = READ_BIT(RCC->APB1ENR1, RCC_APB1ENR1_USBFSEN); \
                                                 UNUSED(tmpreg); \
                                               } while(0)
#endif          

#define __HAL_RCC_PWR_CLK_ENABLE()             do { \
                                                 __IO uint32_t tmpreg; \
                                                 SET_BIT(RCC->APB1ENR1, RCC_APB1ENR1_PWREN); \
                                                                                                    \
                                                 tmpreg = READ_BIT(RCC->APB1ENR1, RCC_APB1ENR1_PWREN); \
                                                 UNUSED(tmpreg); \
                                               } while(0)

#if defined(DAC1)
#define __HAL_RCC_DAC1_CLK_ENABLE()            do { \
                                                 __IO uint32_t tmpreg; \
                                                 SET_BIT(RCC->APB1ENR1, RCC_APB1ENR1_DAC1EN); \
                                                                                                    \
                                                 tmpreg = READ_BIT(RCC->APB1ENR1, RCC_APB1ENR1_DAC1EN); \
                                                 UNUSED(tmpreg); \
                                               } while(0)
#endif           

#define __HAL_RCC_OPAMP_CLK_ENABLE()           do { \
                                                 __IO uint32_t tmpreg; \
                                                 SET_BIT(RCC->APB1ENR1, RCC_APB1ENR1_OPAMPEN); \
                                                                                                    \
                                                 tmpreg = READ_BIT(RCC->APB1ENR1, RCC_APB1ENR1_OPAMPEN); \
                                                 UNUSED(tmpreg); \
                                               } while(0)

#define __HAL_RCC_LPTIM1_CLK_ENABLE()          do { \
                                                 __IO uint32_t tmpreg; \
                                                 SET_BIT(RCC->APB1ENR1, RCC_APB1ENR1_LPTIM1EN); \
                                                                                                    \
                                                 tmpreg = READ_BIT(RCC->APB1ENR1, RCC_APB1ENR1_LPTIM1EN); \
                                                 UNUSED(tmpreg); \
                                               } while(0)

#define __HAL_RCC_LPUART1_CLK_ENABLE()         do { \
                                                 __IO uint32_t tmpreg; \
                                                 SET_BIT(RCC->APB1ENR2, RCC_APB1ENR2_LPUART1EN); \
                                                                                                    \
                                                 tmpreg = READ_BIT(RCC->APB1ENR2, RCC_APB1ENR2_LPUART1EN); \
                                                 UNUSED(tmpreg); \
                                               } while(0)

#if defined(SWPMI1)
#define __HAL_RCC_SWPMI1_CLK_ENABLE()          do { \
                                                 __IO uint32_t tmpreg; \
                                                 SET_BIT(RCC->APB1ENR2, RCC_APB1ENR2_SWPMI1EN); \
                                                                                                    \
                                                 tmpreg = READ_BIT(RCC->APB1ENR2, RCC_APB1ENR2_SWPMI1EN); \
                                                 UNUSED(tmpreg); \
                                               } while(0)
#endif             

#define __HAL_RCC_LPTIM2_CLK_ENABLE()          do { \
                                                 __IO uint32_t tmpreg; \
                                                 SET_BIT(RCC->APB1ENR2, RCC_APB1ENR2_LPTIM2EN); \
                                                                                                    \
                                                 tmpreg = READ_BIT(RCC->APB1ENR2, RCC_APB1ENR2_LPTIM2EN); \
                                                 UNUSED(tmpreg); \
                                               } while(0)


#define __HAL_RCC_TIM2_CLK_DISABLE()           CLEAR_BIT(RCC->APB1ENR1, RCC_APB1ENR1_TIM2EN)

#if defined(TIM3)
#define __HAL_RCC_TIM3_CLK_DISABLE()           CLEAR_BIT(RCC->APB1ENR1, RCC_APB1ENR1_TIM3EN)
#endif           

#if defined(TIM4)
#define __HAL_RCC_TIM4_CLK_DISABLE()           CLEAR_BIT(RCC->APB1ENR1, RCC_APB1ENR1_TIM4EN)
#endif           

#if defined(TIM5)
#define __HAL_RCC_TIM5_CLK_DISABLE()           CLEAR_BIT(RCC->APB1ENR1, RCC_APB1ENR1_TIM5EN)
#endif           

#define __HAL_RCC_TIM6_CLK_DISABLE()           CLEAR_BIT(RCC->APB1ENR1, RCC_APB1ENR1_TIM6EN)

#if defined(TIM7)
#define __HAL_RCC_TIM7_CLK_DISABLE()           CLEAR_BIT(RCC->APB1ENR1, RCC_APB1ENR1_TIM7EN)
#endif           

#if defined(LCD)
#define __HAL_RCC_LCD_CLK_DISABLE()            CLEAR_BIT(RCC->APB1ENR1, RCC_APB1ENR1_LCDEN);
#endif          

#if defined(RCC_APB1ENR1_RTCAPBEN)
#define __HAL_RCC_RTCAPB_CLK_DISABLE()         CLEAR_BIT(RCC->APB1ENR1, RCC_APB1ENR1_RTCAPBEN);
#endif                            

#if defined(SPI2)
#define __HAL_RCC_SPI2_CLK_DISABLE()           CLEAR_BIT(RCC->APB1ENR1, RCC_APB1ENR1_SPI2EN)
#endif           

#if defined(SPI3)
#define __HAL_RCC_SPI3_CLK_DISABLE()           CLEAR_BIT(RCC->APB1ENR1, RCC_APB1ENR1_SPI3EN)
#endif           

#define __HAL_RCC_USART2_CLK_DISABLE()         CLEAR_BIT(RCC->APB1ENR1, RCC_APB1ENR1_USART2EN)

#if defined(USART3)
#define __HAL_RCC_USART3_CLK_DISABLE()         CLEAR_BIT(RCC->APB1ENR1, RCC_APB1ENR1_USART3EN)
#endif             

#if defined(UART4)
#define __HAL_RCC_UART4_CLK_DISABLE()          CLEAR_BIT(RCC->APB1ENR1, RCC_APB1ENR1_UART4EN)
#endif            

#if defined(UART5)
#define __HAL_RCC_UART5_CLK_DISABLE()          CLEAR_BIT(RCC->APB1ENR1, RCC_APB1ENR1_UART5EN)
#endif            

#define __HAL_RCC_I2C1_CLK_DISABLE()           CLEAR_BIT(RCC->APB1ENR1, RCC_APB1ENR1_I2C1EN)

#if defined(I2C2)
#define __HAL_RCC_I2C2_CLK_DISABLE()           CLEAR_BIT(RCC->APB1ENR1, RCC_APB1ENR1_I2C2EN)
#endif           

#define __HAL_RCC_I2C3_CLK_DISABLE()           CLEAR_BIT(RCC->APB1ENR1, RCC_APB1ENR1_I2C3EN)

#if defined(I2C4)
#define __HAL_RCC_I2C4_CLK_DISABLE()           CLEAR_BIT(RCC->APB1ENR2, RCC_APB1ENR2_I2C4EN)
#endif           

#if defined(CRS)
#define __HAL_RCC_CRS_CLK_DISABLE()            CLEAR_BIT(RCC->APB1ENR1, RCC_APB1ENR1_CRSEN);
#endif          

#if defined(CAN1)
#define __HAL_RCC_CAN1_CLK_DISABLE()           CLEAR_BIT(RCC->APB1ENR1, RCC_APB1ENR1_CAN1EN)
#endif           

#if defined(CAN2)
#define __HAL_RCC_CAN2_CLK_DISABLE()           CLEAR_BIT(RCC->APB1ENR1, RCC_APB1ENR1_CAN2EN)
#endif           

#if defined(USB)
#define __HAL_RCC_USB_CLK_DISABLE()            CLEAR_BIT(RCC->APB1ENR1, RCC_APB1ENR1_USBFSEN);
#endif          

#define __HAL_RCC_PWR_CLK_DISABLE()            CLEAR_BIT(RCC->APB1ENR1, RCC_APB1ENR1_PWREN)

#if defined(DAC1)
#define __HAL_RCC_DAC1_CLK_DISABLE()           CLEAR_BIT(RCC->APB1ENR1, RCC_APB1ENR1_DAC1EN)
#endif           

#define __HAL_RCC_OPAMP_CLK_DISABLE()          CLEAR_BIT(RCC->APB1ENR1, RCC_APB1ENR1_OPAMPEN)

#define __HAL_RCC_LPTIM1_CLK_DISABLE()         CLEAR_BIT(RCC->APB1ENR1, RCC_APB1ENR1_LPTIM1EN)

#define __HAL_RCC_LPUART1_CLK_DISABLE()        CLEAR_BIT(RCC->APB1ENR2, RCC_APB1ENR2_LPUART1EN)

#if defined(SWPMI1)
#define __HAL_RCC_SWPMI1_CLK_DISABLE()         CLEAR_BIT(RCC->APB1ENR2, RCC_APB1ENR2_SWPMI1EN)
#endif             

#define __HAL_RCC_LPTIM2_CLK_DISABLE()         CLEAR_BIT(RCC->APB1ENR2, RCC_APB1ENR2_LPTIM2EN)

   
      
    

                                                                                
                                                        
                                                                                    
                                                                                    
                     
      
    

#define __HAL_RCC_SYSCFG_CLK_ENABLE()          do { \
                                                 __IO uint32_t tmpreg; \
                                                 SET_BIT(RCC->APB2ENR, RCC_APB2ENR_SYSCFGEN); \
                                                                                                    \
                                                 tmpreg = READ_BIT(RCC->APB2ENR, RCC_APB2ENR_SYSCFGEN); \
                                                 UNUSED(tmpreg); \
                                               } while(0)

#define __HAL_RCC_FIREWALL_CLK_ENABLE()        do { \
                                                 __IO uint32_t tmpreg; \
                                                 SET_BIT(RCC->APB2ENR, RCC_APB2ENR_FWEN); \
                                                                                                    \
                                                 tmpreg = READ_BIT(RCC->APB2ENR, RCC_APB2ENR_FWEN); \
                                                 UNUSED(tmpreg); \
                                               } while(0)

#if defined(SDMMC1) && defined(RCC_APB2ENR_SDMMC1EN)
#define __HAL_RCC_SDMMC1_CLK_ENABLE()          do { \
                                                 __IO uint32_t tmpreg; \
                                                 SET_BIT(RCC->APB2ENR, RCC_APB2ENR_SDMMC1EN); \
                                                                                                    \
                                                 tmpreg = READ_BIT(RCC->APB2ENR, RCC_APB2ENR_SDMMC1EN); \
                                                 UNUSED(tmpreg); \
                                               } while(0)
#endif                                     

#define __HAL_RCC_TIM1_CLK_ENABLE()            do { \
                                                 __IO uint32_t tmpreg; \
                                                 SET_BIT(RCC->APB2ENR, RCC_APB2ENR_TIM1EN); \
                                                                                                    \
                                                 tmpreg = READ_BIT(RCC->APB2ENR, RCC_APB2ENR_TIM1EN); \
                                                 UNUSED(tmpreg); \
                                               } while(0)

#define __HAL_RCC_SPI1_CLK_ENABLE()            do { \
                                                 __IO uint32_t tmpreg; \
                                                 SET_BIT(RCC->APB2ENR, RCC_APB2ENR_SPI1EN); \
                                                                                                    \
                                                 tmpreg = READ_BIT(RCC->APB2ENR, RCC_APB2ENR_SPI1EN); \
                                                 UNUSED(tmpreg); \
                                               } while(0)

#if defined(TIM8)
#define __HAL_RCC_TIM8_CLK_ENABLE()            do { \
                                                 __IO uint32_t tmpreg; \
                                                 SET_BIT(RCC->APB2ENR, RCC_APB2ENR_TIM8EN); \
                                                                                                    \
                                                 tmpreg = READ_BIT(RCC->APB2ENR, RCC_APB2ENR_TIM8EN); \
                                                 UNUSED(tmpreg); \
                                               } while(0)
#endif           

#define __HAL_RCC_USART1_CLK_ENABLE()          do { \
                                                 __IO uint32_t tmpreg; \
                                                 SET_BIT(RCC->APB2ENR, RCC_APB2ENR_USART1EN); \
                                                                                                    \
                                                 tmpreg = READ_BIT(RCC->APB2ENR, RCC_APB2ENR_USART1EN); \
                                                 UNUSED(tmpreg); \
                                               } while(0)


#define __HAL_RCC_TIM15_CLK_ENABLE()           do { \
                                                 __IO uint32_t tmpreg; \
                                                 SET_BIT(RCC->APB2ENR, RCC_APB2ENR_TIM15EN); \
                                                                                                    \
                                                 tmpreg = READ_BIT(RCC->APB2ENR, RCC_APB2ENR_TIM15EN); \
                                                 UNUSED(tmpreg); \
                                               } while(0)

#define __HAL_RCC_TIM16_CLK_ENABLE()           do { \
                                                 __IO uint32_t tmpreg; \
                                                 SET_BIT(RCC->APB2ENR, RCC_APB2ENR_TIM16EN); \
                                                                                                    \
                                                 tmpreg = READ_BIT(RCC->APB2ENR, RCC_APB2ENR_TIM16EN); \
                                                 UNUSED(tmpreg); \
                                               } while(0)

#if defined(TIM17)
#define __HAL_RCC_TIM17_CLK_ENABLE()           do { \
                                                 __IO uint32_t tmpreg; \
                                                 SET_BIT(RCC->APB2ENR, RCC_APB2ENR_TIM17EN); \
                                                                                                    \
                                                 tmpreg = READ_BIT(RCC->APB2ENR, RCC_APB2ENR_TIM17EN); \
                                                 UNUSED(tmpreg); \
                                               } while(0)
#endif            

#if defined(SAI1)
#define __HAL_RCC_SAI1_CLK_ENABLE()            do { \
                                                 __IO uint32_t tmpreg; \
                                                 SET_BIT(RCC->APB2ENR, RCC_APB2ENR_SAI1EN); \
                                                                                                    \
                                                 tmpreg = READ_BIT(RCC->APB2ENR, RCC_APB2ENR_SAI1EN); \
                                                 UNUSED(tmpreg); \
                                               } while(0)
#endif           

#if defined(SAI2)
#define __HAL_RCC_SAI2_CLK_ENABLE()            do { \
                                                 __IO uint32_t tmpreg; \
                                                 SET_BIT(RCC->APB2ENR, RCC_APB2ENR_SAI2EN); \
                                                                                                    \
                                                 tmpreg = READ_BIT(RCC->APB2ENR, RCC_APB2ENR_SAI2EN); \
                                                 UNUSED(tmpreg); \
                                               } while(0)
#endif           

#if defined(DFSDM1_Filter0)
#define __HAL_RCC_DFSDM1_CLK_ENABLE()          do { \
                                                 __IO uint32_t tmpreg; \
                                                 SET_BIT(RCC->APB2ENR, RCC_APB2ENR_DFSDM1EN); \
                                                                                                    \
                                                 tmpreg = READ_BIT(RCC->APB2ENR, RCC_APB2ENR_DFSDM1EN); \
                                                 UNUSED(tmpreg); \
                                               } while(0)
#endif                     

#if defined(LTDC)
#define __HAL_RCC_LTDC_CLK_ENABLE()            do { \
                                                 __IO uint32_t tmpreg; \
                                                 SET_BIT(RCC->APB2ENR, RCC_APB2ENR_LTDCEN); \
                                                                                                    \
                                                 tmpreg = READ_BIT(RCC->APB2ENR, RCC_APB2ENR_LTDCEN); \
                                                 UNUSED(tmpreg); \
                                               } while(0)
#endif           

#if defined(DSI)
#define __HAL_RCC_DSI_CLK_ENABLE()             do { \
                                                 __IO uint32_t tmpreg; \
                                                 SET_BIT(RCC->APB2ENR, RCC_APB2ENR_DSIEN); \
                                                                                                    \
                                                 tmpreg = READ_BIT(RCC->APB2ENR, RCC_APB2ENR_DSIEN); \
                                                 UNUSED(tmpreg); \
                                               } while(0)
#endif          


#define __HAL_RCC_SYSCFG_CLK_DISABLE()         CLEAR_BIT(RCC->APB2ENR, RCC_APB2ENR_SYSCFGEN)

#if defined(SDMMC1) && defined(RCC_APB2ENR_SDMMC1EN)
#define __HAL_RCC_SDMMC1_CLK_DISABLE()         CLEAR_BIT(RCC->APB2ENR, RCC_APB2ENR_SDMMC1EN)
#endif                                     

#define __HAL_RCC_TIM1_CLK_DISABLE()           CLEAR_BIT(RCC->APB2ENR, RCC_APB2ENR_TIM1EN)

#define __HAL_RCC_SPI1_CLK_DISABLE()           CLEAR_BIT(RCC->APB2ENR, RCC_APB2ENR_SPI1EN)

#if defined(TIM8)
#define __HAL_RCC_TIM8_CLK_DISABLE()           CLEAR_BIT(RCC->APB2ENR, RCC_APB2ENR_TIM8EN)
#endif           

#define __HAL_RCC_USART1_CLK_DISABLE()         CLEAR_BIT(RCC->APB2ENR, RCC_APB2ENR_USART1EN)

#define __HAL_RCC_TIM15_CLK_DISABLE()          CLEAR_BIT(RCC->APB2ENR, RCC_APB2ENR_TIM15EN)

#define __HAL_RCC_TIM16_CLK_DISABLE()          CLEAR_BIT(RCC->APB2ENR, RCC_APB2ENR_TIM16EN)

#if defined(TIM17)
#define __HAL_RCC_TIM17_CLK_DISABLE()          CLEAR_BIT(RCC->APB2ENR, RCC_APB2ENR_TIM17EN)
#endif            

#if defined(SAI1)
#define __HAL_RCC_SAI1_CLK_DISABLE()           CLEAR_BIT(RCC->APB2ENR, RCC_APB2ENR_SAI1EN)
#endif           

#if defined(SAI2)
#define __HAL_RCC_SAI2_CLK_DISABLE()           CLEAR_BIT(RCC->APB2ENR, RCC_APB2ENR_SAI2EN)
#endif           

#if defined(DFSDM1_Filter0)
#define __HAL_RCC_DFSDM1_CLK_DISABLE()         CLEAR_BIT(RCC->APB2ENR, RCC_APB2ENR_DFSDM1EN)
#endif                     

#if defined(LTDC)
#define __HAL_RCC_LTDC_CLK_DISABLE()           CLEAR_BIT(RCC->APB2ENR, RCC_APB2ENR_LTDCEN)
#endif           

#if defined(DSI)
#define __HAL_RCC_DSI_CLK_DISABLE()            CLEAR_BIT(RCC->APB2ENR, RCC_APB2ENR_DSIEN)
#endif          

   
      
    

                                                                                                              
                                                                      
                                                                                    
                                                                                    
                     
      
    

#define __HAL_RCC_DMA1_IS_CLK_ENABLED()        (READ_BIT(RCC->AHB1ENR, RCC_AHB1ENR_DMA1EN) != 0U)

#define __HAL_RCC_DMA2_IS_CLK_ENABLED()        (READ_BIT(RCC->AHB1ENR, RCC_AHB1ENR_DMA2EN) != 0U)

#if defined(DMAMUX1)
#define __HAL_RCC_DMAMUX1_IS_CLK_ENABLED()     (READ_BIT(RCC->AHB1ENR, RCC_AHB1ENR_DMAMUX1EN) != 0U)
#endif              

#define __HAL_RCC_FLASH_IS_CLK_ENABLED()       (READ_BIT(RCC->AHB1ENR, RCC_AHB1ENR_FLASHEN) != 0U)

#define __HAL_RCC_CRC_IS_CLK_ENABLED()         (READ_BIT(RCC->AHB1ENR, RCC_AHB1ENR_CRCEN) != 0U)

#define __HAL_RCC_TSC_IS_CLK_ENABLED()         (READ_BIT(RCC->AHB1ENR, RCC_AHB1ENR_TSCEN) != 0U)

#if defined(DMA2D)
#define __HAL_RCC_DMA2D_IS_CLK_ENABLED()       (READ_BIT(RCC->AHB1ENR, RCC_AHB1ENR_DMA2DEN) != 0U)
#endif            

#if defined(GFXMMU)
#define __HAL_RCC_GFXMMU_IS_CLK_ENABLED()      (READ_BIT(RCC->AHB1ENR, RCC_AHB1ENR_GFXMMUEN) != 0U)
#endif             


#define __HAL_RCC_DMA1_IS_CLK_DISABLED()       (READ_BIT(RCC->AHB1ENR, RCC_AHB1ENR_DMA1EN) == 0U)

#define __HAL_RCC_DMA2_IS_CLK_DISABLED()       (READ_BIT(RCC->AHB1ENR, RCC_AHB1ENR_DMA2EN) == 0U)

#if defined(DMAMUX1)
#define __HAL_RCC_DMAMUX1_IS_CLK_DISABLED()    (READ_BIT(RCC->AHB1ENR, RCC_AHB1ENR_DMAMUX1EN) == 0U)
#endif              

#define __HAL_RCC_FLASH_IS_CLK_DISABLED()      (READ_BIT(RCC->AHB1ENR, RCC_AHB1ENR_FLASHEN) == 0U)

#define __HAL_RCC_CRC_IS_CLK_DISABLED()        (READ_BIT(RCC->AHB1ENR, RCC_AHB1ENR_CRCEN) == 0U)

#define __HAL_RCC_TSC_IS_CLK_DISABLED()        (READ_BIT(RCC->AHB1ENR, RCC_AHB1ENR_TSCEN) == 0U)

#if defined(DMA2D)
#define __HAL_RCC_DMA2D_IS_CLK_DISABLED()      (READ_BIT(RCC->AHB1ENR, RCC_AHB1ENR_DMA2DEN) == 0U)
#endif            

#if defined(GFXMMU)
#define __HAL_RCC_GFXMMU_IS_CLK_DISABLED()     (READ_BIT(RCC->AHB1ENR, RCC_AHB1ENR_GFXMMUEN) == 0U)
#endif             

   
      
    

                                                                                                   
                                                                      
                                                                                    
                                                                                    
                     
      
    

#define __HAL_RCC_GPIOA_IS_CLK_ENABLED()       (READ_BIT(RCC->AHB2ENR, RCC_AHB2ENR_GPIOAEN) != 0U)

#define __HAL_RCC_GPIOB_IS_CLK_ENABLED()       (READ_BIT(RCC->AHB2ENR, RCC_AHB2ENR_GPIOBEN) != 0U)

#define __HAL_RCC_GPIOC_IS_CLK_ENABLED()       (READ_BIT(RCC->AHB2ENR, RCC_AHB2ENR_GPIOCEN) != 0U)

#if defined(GPIOD)
#define __HAL_RCC_GPIOD_IS_CLK_ENABLED()       (READ_BIT(RCC->AHB2ENR, RCC_AHB2ENR_GPIODEN) != 0U)
#endif            

#if defined(GPIOE)
#define __HAL_RCC_GPIOE_IS_CLK_ENABLED()       (READ_BIT(RCC->AHB2ENR, RCC_AHB2ENR_GPIOEEN) != 0U)
#endif            

#if defined(GPIOF)
#define __HAL_RCC_GPIOF_IS_CLK_ENABLED()       (READ_BIT(RCC->AHB2ENR, RCC_AHB2ENR_GPIOFEN) != 0U)
#endif            

#if defined(GPIOG)
#define __HAL_RCC_GPIOG_IS_CLK_ENABLED()       (READ_BIT(RCC->AHB2ENR, RCC_AHB2ENR_GPIOGEN) != 0U)
#endif            

#define __HAL_RCC_GPIOH_IS_CLK_ENABLED()       (READ_BIT(RCC->AHB2ENR, RCC_AHB2ENR_GPIOHEN) != 0U)

#if defined(GPIOI)
#define __HAL_RCC_GPIOI_IS_CLK_ENABLED()       (READ_BIT(RCC->AHB2ENR, RCC_AHB2ENR_GPIOIEN) != 0U)
#endif            

#if defined(USB_OTG_FS)
#define __HAL_RCC_USB_OTG_FS_IS_CLK_ENABLED()  (READ_BIT(RCC->AHB2ENR, RCC_AHB2ENR_OTGFSEN) != 0U)
#endif                 

#define __HAL_RCC_ADC_IS_CLK_ENABLED()         (READ_BIT(RCC->AHB2ENR, RCC_AHB2ENR_ADCEN) != 0U)

#if defined(DCMI)
#define __HAL_RCC_DCMI_IS_CLK_ENABLED()        (READ_BIT(RCC->AHB2ENR, RCC_AHB2ENR_DCMIEN) != 0U)
#endif           

#if defined(PKA)
#define __HAL_RCC_PKA_IS_CLK_ENABLED()         (READ_BIT(RCC->AHB2ENR, RCC_AHB2ENR_PKAEN) != 0U)
#endif          

#if defined(AES)
#define __HAL_RCC_AES_IS_CLK_ENABLED()         (READ_BIT(RCC->AHB2ENR, RCC_AHB2ENR_AESEN) != 0U)
#endif          

#if defined(HASH)
#define __HAL_RCC_HASH_IS_CLK_ENABLED()        (READ_BIT(RCC->AHB2ENR, RCC_AHB2ENR_HASHEN) != 0U)
#endif           

#define __HAL_RCC_RNG_IS_CLK_ENABLED()         (READ_BIT(RCC->AHB2ENR, RCC_AHB2ENR_RNGEN) != 0U)

#if defined(OCTOSPIM)
#define __HAL_RCC_OSPIM_IS_CLK_ENABLED()       (READ_BIT(RCC->AHB2ENR, RCC_AHB2ENR_OSPIMEN) != 0U)
#endif               

#if defined(SDMMC1) && defined(RCC_AHB2ENR_SDMMC1EN)
#define __HAL_RCC_SDMMC1_IS_CLK_ENABLED()      (READ_BIT(RCC->AHB2ENR, RCC_AHB2ENR_SDMMC1EN) != 0U)
#endif                                     

#if defined(SDMMC2)
#define __HAL_RCC_SDMMC2_IS_CLK_ENABLED()      (READ_BIT(RCC->AHB2ENR, RCC_AHB2ENR_SDMMC2EN) != 0U)
#endif             


#define __HAL_RCC_GPIOA_IS_CLK_DISABLED()      (READ_BIT(RCC->AHB2ENR, RCC_AHB2ENR_GPIOAEN) == 0U)

#define __HAL_RCC_GPIOB_IS_CLK_DISABLED()      (READ_BIT(RCC->AHB2ENR, RCC_AHB2ENR_GPIOBEN) == 0U)

#define __HAL_RCC_GPIOC_IS_CLK_DISABLED()      (READ_BIT(RCC->AHB2ENR, RCC_AHB2ENR_GPIOCEN) == 0U)

#if defined(GPIOD)
#define __HAL_RCC_GPIOD_IS_CLK_DISABLED()      (READ_BIT(RCC->AHB2ENR, RCC_AHB2ENR_GPIODEN) == 0U)
#endif            

#if defined(GPIOE)
#define __HAL_RCC_GPIOE_IS_CLK_DISABLED()      (READ_BIT(RCC->AHB2ENR, RCC_AHB2ENR_GPIOEEN) == 0U)
#endif            

#if defined(GPIOF)
#define __HAL_RCC_GPIOF_IS_CLK_DISABLED()      (READ_BIT(RCC->AHB2ENR, RCC_AHB2ENR_GPIOFEN) == 0U)
#endif            

#if defined(GPIOG)
#define __HAL_RCC_GPIOG_IS_CLK_DISABLED()      (READ_BIT(RCC->AHB2ENR, RCC_AHB2ENR_GPIOGEN) == 0U)
#endif            

#define __HAL_RCC_GPIOH_IS_CLK_DISABLED()      (READ_BIT(RCC->AHB2ENR, RCC_AHB2ENR_GPIOHEN) == 0U)

#if defined(GPIOI)
#define __HAL_RCC_GPIOI_IS_CLK_DISABLED()      (READ_BIT(RCC->AHB2ENR, RCC_AHB2ENR_GPIOIEN) == 0U)
#endif            

#if defined(USB_OTG_FS)
#define __HAL_RCC_USB_OTG_FS_IS_CLK_DISABLED() (READ_BIT(RCC->AHB2ENR, RCC_AHB2ENR_OTGFSEN) == 0U)
#endif                 

#define __HAL_RCC_ADC_IS_CLK_DISABLED()        (READ_BIT(RCC->AHB2ENR, RCC_AHB2ENR_ADCEN) == 0U)

#if defined(DCMI)
#define __HAL_RCC_DCMI_IS_CLK_DISABLED()       (READ_BIT(RCC->AHB2ENR, RCC_AHB2ENR_DCMIEN) == 0U)
#endif           

#if defined(PKA)
#define __HAL_RCC_PKA_IS_CLK_DISABLED()        (READ_BIT(RCC->AHB2ENR, RCC_AHB2ENR_PKAEN) == 0U)
#endif          

#if defined(AES)
#define __HAL_RCC_AES_IS_CLK_DISABLED()        (READ_BIT(RCC->AHB2ENR, RCC_AHB2ENR_AESEN) == 0U)
#endif          

#if defined(HASH)
#define __HAL_RCC_HASH_IS_CLK_DISABLED()       (READ_BIT(RCC->AHB2ENR, RCC_AHB2ENR_HASHEN) == 0U)
#endif           

#define __HAL_RCC_RNG_IS_CLK_DISABLED()        (READ_BIT(RCC->AHB2ENR, RCC_AHB2ENR_RNGEN) == 0U)

#if defined(OCTOSPIM)
#define __HAL_RCC_OSPIM_IS_CLK_DISABLED()      (READ_BIT(RCC->AHB2ENR, RCC_AHB2ENR_OSPIMEN) == 0U)
#endif               

#if defined(SDMMC1) && defined(RCC_AHB2ENR_SDMMC1EN)
#define __HAL_RCC_SDMMC1_IS_CLK_DISABLED()     (READ_BIT(RCC->AHB2ENR, RCC_AHB2ENR_SDMMC1EN) == 0U)
#endif                                     

#if defined(SDMMC2)
#define __HAL_RCC_SDMMC2_IS_CLK_DISABLED()     (READ_BIT(RCC->AHB2ENR, RCC_AHB2ENR_SDMMC2EN) == 0U)
#endif             

   
      
    

                                                                                                   
                                                                      
                                                                                    
                                                                                    
                     
      
    

#if defined(FMC_BANK1)
#define __HAL_RCC_FMC_IS_CLK_ENABLED()         (READ_BIT(RCC->AHB3ENR, RCC_AHB3ENR_FMCEN) != 0U)
#endif                

#if defined(QUADSPI)
#define __HAL_RCC_QSPI_IS_CLK_ENABLED()        (READ_BIT(RCC->AHB3ENR, RCC_AHB3ENR_QSPIEN) != 0U)
#endif              

#if defined(OCTOSPI1)
#define __HAL_RCC_OSPI1_IS_CLK_ENABLED()       (READ_BIT(RCC->AHB3ENR, RCC_AHB3ENR_OSPI1EN) != 0U)
#endif               

#if defined(OCTOSPI2)
#define __HAL_RCC_OSPI2_IS_CLK_ENABLED()       (READ_BIT(RCC->AHB3ENR, RCC_AHB3ENR_OSPI2EN) != 0U)
#endif               

#if defined(FMC_BANK1)
#define __HAL_RCC_FMC_IS_CLK_DISABLED()        (READ_BIT(RCC->AHB3ENR, RCC_AHB3ENR_FMCEN) == 0U)
#endif                

#if defined(QUADSPI)
#define __HAL_RCC_QSPI_IS_CLK_DISABLED()       (READ_BIT(RCC->AHB3ENR, RCC_AHB3ENR_QSPIEN) == 0U)
#endif              

#if defined(OCTOSPI1)
#define __HAL_RCC_OSPI1_IS_CLK_DISABLED()      (READ_BIT(RCC->AHB3ENR, RCC_AHB3ENR_OSPI1EN) == 0U)
#endif               

#if defined(OCTOSPI2)
#define __HAL_RCC_OSPI2_IS_CLK_DISABLED()      (READ_BIT(RCC->AHB3ENR, RCC_AHB3ENR_OSPI2EN) == 0U)
#endif               

   
      
    

                                                                                                   
                                                                      
                                                                                    
                                                                                    
                     
      
    

#define __HAL_RCC_TIM2_IS_CLK_ENABLED()        (READ_BIT(RCC->APB1ENR1, RCC_APB1ENR1_TIM2EN) != 0U)

#if defined(TIM3)
#define __HAL_RCC_TIM3_IS_CLK_ENABLED()        (READ_BIT(RCC->APB1ENR1, RCC_APB1ENR1_TIM3EN) != 0U)
#endif           

#if defined(TIM4)
#define __HAL_RCC_TIM4_IS_CLK_ENABLED()        (READ_BIT(RCC->APB1ENR1, RCC_APB1ENR1_TIM4EN) != 0U)
#endif           

#if defined(TIM5)
#define __HAL_RCC_TIM5_IS_CLK_ENABLED()        (READ_BIT(RCC->APB1ENR1, RCC_APB1ENR1_TIM5EN) != 0U)
#endif           

#define __HAL_RCC_TIM6_IS_CLK_ENABLED()        (READ_BIT(RCC->APB1ENR1, RCC_APB1ENR1_TIM6EN) != 0U)

#if defined(TIM7)
#define __HAL_RCC_TIM7_IS_CLK_ENABLED()        (READ_BIT(RCC->APB1ENR1, RCC_APB1ENR1_TIM7EN) != 0U)
#endif           

#if defined(LCD)
#define __HAL_RCC_LCD_IS_CLK_ENABLED()         (READ_BIT(RCC->APB1ENR1, RCC_APB1ENR1_LCDEN) != 0U)
#endif          

#if defined(RCC_APB1ENR1_RTCAPBEN)
#define __HAL_RCC_RTCAPB_IS_CLK_ENABLED()      (READ_BIT(RCC->APB1ENR1, RCC_APB1ENR1_RTCAPBEN) != 0U)
#endif                            

#define __HAL_RCC_WWDG_IS_CLK_ENABLED()        (READ_BIT(RCC->APB1ENR1, RCC_APB1ENR1_WWDGEN) != 0U)

#if defined(SPI2)
#define __HAL_RCC_SPI2_IS_CLK_ENABLED()        (READ_BIT(RCC->APB1ENR1, RCC_APB1ENR1_SPI2EN) != 0U)
#endif           

#if defined(SPI3)
#define __HAL_RCC_SPI3_IS_CLK_ENABLED()        (READ_BIT(RCC->APB1ENR1, RCC_APB1ENR1_SPI3EN) != 0U)
#endif           

#define __HAL_RCC_USART2_IS_CLK_ENABLED()      (READ_BIT(RCC->APB1ENR1, RCC_APB1ENR1_USART2EN) != 0U)

#if defined(USART3)
#define __HAL_RCC_USART3_IS_CLK_ENABLED()      (READ_BIT(RCC->APB1ENR1, RCC_APB1ENR1_USART3EN) != 0U)
#endif             

#if defined(UART4)
#define __HAL_RCC_UART4_IS_CLK_ENABLED()       (READ_BIT(RCC->APB1ENR1, RCC_APB1ENR1_UART4EN) != 0U)
#endif            

#if defined(UART5)
#define __HAL_RCC_UART5_IS_CLK_ENABLED()       (READ_BIT(RCC->APB1ENR1, RCC_APB1ENR1_UART5EN) != 0U)
#endif            

#define __HAL_RCC_I2C1_IS_CLK_ENABLED()        (READ_BIT(RCC->APB1ENR1, RCC_APB1ENR1_I2C1EN) != 0U)

#if defined(I2C2)
#define __HAL_RCC_I2C2_IS_CLK_ENABLED()        (READ_BIT(RCC->APB1ENR1, RCC_APB1ENR1_I2C2EN) != 0U)
#endif           

#define __HAL_RCC_I2C3_IS_CLK_ENABLED()        (READ_BIT(RCC->APB1ENR1, RCC_APB1ENR1_I2C3EN) != 0U)

#if defined(I2C4)
#define __HAL_RCC_I2C4_IS_CLK_ENABLED()        (READ_BIT(RCC->APB1ENR2, RCC_APB1ENR2_I2C4EN) != 0U)
#endif           

#if defined(CRS)
#define __HAL_RCC_CRS_IS_CLK_ENABLED()         (READ_BIT(RCC->APB1ENR1, RCC_APB1ENR1_CRSEN) != 0U)
#endif          

#if defined(CAN1)
#define __HAL_RCC_CAN1_IS_CLK_ENABLED()        (READ_BIT(RCC->APB1ENR1, RCC_APB1ENR1_CAN1EN) != 0U)
#endif           

#if defined(CAN2)
#define __HAL_RCC_CAN2_IS_CLK_ENABLED()        (READ_BIT(RCC->APB1ENR1, RCC_APB1ENR1_CAN2EN) != 0U)
#endif           

#if defined(USB)
#define __HAL_RCC_USB_IS_CLK_ENABLED()         (READ_BIT(RCC->APB1ENR1, RCC_APB1ENR1_USBFSEN) != 0U)
#endif          

#define __HAL_RCC_PWR_IS_CLK_ENABLED()         (READ_BIT(RCC->APB1ENR1, RCC_APB1ENR1_PWREN) != 0U)

#if defined(DAC1)
#define __HAL_RCC_DAC1_IS_CLK_ENABLED()        (READ_BIT(RCC->APB1ENR1, RCC_APB1ENR1_DAC1EN) != 0U)
#endif           

#define __HAL_RCC_OPAMP_IS_CLK_ENABLED()       (READ_BIT(RCC->APB1ENR1, RCC_APB1ENR1_OPAMPEN) != 0U)

#define __HAL_RCC_LPTIM1_IS_CLK_ENABLED()      (READ_BIT(RCC->APB1ENR1, RCC_APB1ENR1_LPTIM1EN) != 0U)

#define __HAL_RCC_LPUART1_IS_CLK_ENABLED()     (READ_BIT(RCC->APB1ENR2, RCC_APB1ENR2_LPUART1EN) != 0U)

#if defined(SWPMI1)
#define __HAL_RCC_SWPMI1_IS_CLK_ENABLED()      (READ_BIT(RCC->APB1ENR2, RCC_APB1ENR2_SWPMI1EN) != 0U)
#endif             

#define __HAL_RCC_LPTIM2_IS_CLK_ENABLED()      (READ_BIT(RCC->APB1ENR2, RCC_APB1ENR2_LPTIM2EN) != 0U)


#define __HAL_RCC_TIM2_IS_CLK_DISABLED()       (READ_BIT(RCC->APB1ENR1, RCC_APB1ENR1_TIM2EN) == 0U)

#if defined(TIM3)
#define __HAL_RCC_TIM3_IS_CLK_DISABLED()       (READ_BIT(RCC->APB1ENR1, RCC_APB1ENR1_TIM3EN) == 0U)
#endif           

#if defined(TIM4)
#define __HAL_RCC_TIM4_IS_CLK_DISABLED()       (READ_BIT(RCC->APB1ENR1, RCC_APB1ENR1_TIM4EN) == 0U)
#endif           

#if defined(TIM5)
#define __HAL_RCC_TIM5_IS_CLK_DISABLED()       (READ_BIT(RCC->APB1ENR1, RCC_APB1ENR1_TIM5EN) == 0U)
#endif           

#define __HAL_RCC_TIM6_IS_CLK_DISABLED()       (READ_BIT(RCC->APB1ENR1, RCC_APB1ENR1_TIM6EN) == 0U)

#if defined(TIM7)
#define __HAL_RCC_TIM7_IS_CLK_DISABLED()       (READ_BIT(RCC->APB1ENR1, RCC_APB1ENR1_TIM7EN) == 0U)
#endif           

#if defined(LCD)
#define __HAL_RCC_LCD_IS_CLK_DISABLED()        (READ_BIT(RCC->APB1ENR1, RCC_APB1ENR1_LCDEN) == 0U)
#endif          

#if defined(RCC_APB1ENR1_RTCAPBEN)
#define __HAL_RCC_RTCAPB_IS_CLK_DISABLED()     (READ_BIT(RCC->APB1ENR1, RCC_APB1ENR1_RTCAPBEN) == 0U)
#endif                            

#define __HAL_RCC_WWDG_IS_CLK_DISABLED()       (READ_BIT(RCC->APB1ENR1, RCC_APB1ENR1_WWDGEN) == 0U)

#if defined(SPI2)
#define __HAL_RCC_SPI2_IS_CLK_DISABLED()       (READ_BIT(RCC->APB1ENR1, RCC_APB1ENR1_SPI2EN) == 0U)
#endif           

#if defined(SPI3)
#define __HAL_RCC_SPI3_IS_CLK_DISABLED()       (READ_BIT(RCC->APB1ENR1, RCC_APB1ENR1_SPI3EN) == 0U)
#endif           

#define __HAL_RCC_USART2_IS_CLK_DISABLED()     (READ_BIT(RCC->APB1ENR1, RCC_APB1ENR1_USART2EN) == 0U)

#if defined(USART3)
#define __HAL_RCC_USART3_IS_CLK_DISABLED()     (READ_BIT(RCC->APB1ENR1, RCC_APB1ENR1_USART3EN) == 0U)
#endif             

#if defined(UART4)
#define __HAL_RCC_UART4_IS_CLK_DISABLED()      (READ_BIT(RCC->APB1ENR1, RCC_APB1ENR1_UART4EN) == 0U)
#endif            

#if defined(UART5)
#define __HAL_RCC_UART5_IS_CLK_DISABLED()      (READ_BIT(RCC->APB1ENR1, RCC_APB1ENR1_UART5EN) == 0U)
#endif            

#define __HAL_RCC_I2C1_IS_CLK_DISABLED()       (READ_BIT(RCC->APB1ENR1, RCC_APB1ENR1_I2C1EN) == 0U)

#if defined(I2C2)
#define __HAL_RCC_I2C2_IS_CLK_DISABLED()       (READ_BIT(RCC->APB1ENR1, RCC_APB1ENR1_I2C2EN) == 0U)
#endif           

#define __HAL_RCC_I2C3_IS_CLK_DISABLED()       (READ_BIT(RCC->APB1ENR1, RCC_APB1ENR1_I2C3EN) == 0U)

#if defined(I2C4)
#define __HAL_RCC_I2C4_IS_CLK_DISABLED()       (READ_BIT(RCC->APB1ENR2, RCC_APB1ENR2_I2C4EN) == 0U)
#endif           

#if defined(CRS)
#define __HAL_RCC_CRS_IS_CLK_DISABLED()        (READ_BIT(RCC->APB1ENR1, RCC_APB1ENR1_CRSEN) == 0U)
#endif          

#if defined(CAN1)
#define __HAL_RCC_CAN1_IS_CLK_DISABLED()       (READ_BIT(RCC->APB1ENR1, RCC_APB1ENR1_CAN1EN) == 0U)
#endif           

#if defined(CAN2)
#define __HAL_RCC_CAN2_IS_CLK_DISABLED()       (READ_BIT(RCC->APB1ENR1, RCC_APB1ENR1_CAN2EN) == 0U)
#endif           

#if defined(USB)
#define __HAL_RCC_USB_IS_CLK_DISABLED()        (READ_BIT(RCC->APB1ENR1, RCC_APB1ENR1_USBFSEN) == 0U)
#endif          

#define __HAL_RCC_PWR_IS_CLK_DISABLED()        (READ_BIT(RCC->APB1ENR1, RCC_APB1ENR1_PWREN) == 0U)

#if defined(DAC1)
#define __HAL_RCC_DAC1_IS_CLK_DISABLED()       (READ_BIT(RCC->APB1ENR1, RCC_APB1ENR1_DAC1EN) == 0U)
#endif           

#define __HAL_RCC_OPAMP_IS_CLK_DISABLED()      (READ_BIT(RCC->APB1ENR1, RCC_APB1ENR1_OPAMPEN) == 0U)

#define __HAL_RCC_LPTIM1_IS_CLK_DISABLED()     (READ_BIT(RCC->APB1ENR1, RCC_APB1ENR1_LPTIM1EN) == 0U)

#define __HAL_RCC_LPUART1_IS_CLK_DISABLED()    (READ_BIT(RCC->APB1ENR2, RCC_APB1ENR2_LPUART1EN) == 0U)

#if defined(SWPMI1)
#define __HAL_RCC_SWPMI1_IS_CLK_DISABLED()     (READ_BIT(RCC->APB1ENR2, RCC_APB1ENR2_SWPMI1EN) == 0U)
#endif             

#define __HAL_RCC_LPTIM2_IS_CLK_DISABLED()     (READ_BIT(RCC->APB1ENR2, RCC_APB1ENR2_LPTIM2EN) == 0U)

   
      
    

                                                                                                   
                                                                      
                                                                                    
                                                                                    
                     
      
    

#define __HAL_RCC_SYSCFG_IS_CLK_ENABLED()      (READ_BIT(RCC->APB2ENR, RCC_APB2ENR_SYSCFGEN) != 0U)

#define __HAL_RCC_FIREWALL_IS_CLK_ENABLED()    (READ_BIT(RCC->APB2ENR, RCC_APB2ENR_FWEN) != 0U)

#if defined(SDMMC1) && defined(RCC_APB2ENR_SDMMC1EN)
#define __HAL_RCC_SDMMC1_IS_CLK_ENABLED()      (READ_BIT(RCC->APB2ENR, RCC_APB2ENR_SDMMC1EN) != 0U)
#endif                                     

#define __HAL_RCC_TIM1_IS_CLK_ENABLED()        (READ_BIT(RCC->APB2ENR, RCC_APB2ENR_TIM1EN) != 0U)

#define __HAL_RCC_SPI1_IS_CLK_ENABLED()        (READ_BIT(RCC->APB2ENR, RCC_APB2ENR_SPI1EN) != 0U)

#if defined(TIM8)
#define __HAL_RCC_TIM8_IS_CLK_ENABLED()        (READ_BIT(RCC->APB2ENR, RCC_APB2ENR_TIM8EN) != 0U)
#endif           

#define __HAL_RCC_USART1_IS_CLK_ENABLED()      (READ_BIT(RCC->APB2ENR, RCC_APB2ENR_USART1EN) != 0U)

#define __HAL_RCC_TIM15_IS_CLK_ENABLED()       (READ_BIT(RCC->APB2ENR, RCC_APB2ENR_TIM15EN) != 0U)

#define __HAL_RCC_TIM16_IS_CLK_ENABLED()       (READ_BIT(RCC->APB2ENR, RCC_APB2ENR_TIM16EN) != 0U)

#if defined(TIM17)
#define __HAL_RCC_TIM17_IS_CLK_ENABLED()       (READ_BIT(RCC->APB2ENR, RCC_APB2ENR_TIM17EN) != 0U)
#endif            

#if defined(SAI1)
#define __HAL_RCC_SAI1_IS_CLK_ENABLED()        (READ_BIT(RCC->APB2ENR, RCC_APB2ENR_SAI1EN) != 0U)
#endif           

#if defined(SAI2)
#define __HAL_RCC_SAI2_IS_CLK_ENABLED()        (READ_BIT(RCC->APB2ENR, RCC_APB2ENR_SAI2EN) != 0U)
#endif           

#if defined(DFSDM1_Filter0)
#define __HAL_RCC_DFSDM1_IS_CLK_ENABLED()      (READ_BIT(RCC->APB2ENR, RCC_APB2ENR_DFSDM1EN) != 0U)
#endif                     

#if defined(LTDC)
#define __HAL_RCC_LTDC_IS_CLK_ENABLED()        (READ_BIT(RCC->APB2ENR, RCC_APB2ENR_LTDCEN) != 0U)
#endif           

#if defined(DSI)
#define __HAL_RCC_DSI_IS_CLK_ENABLED()         (READ_BIT(RCC->APB2ENR, RCC_APB2ENR_DSIEN) != 0U)
#endif          


#define __HAL_RCC_SYSCFG_IS_CLK_DISABLED()     (READ_BIT(RCC->APB2ENR, RCC_APB2ENR_SYSCFGEN) == 0U)

#if defined(SDMMC1) && defined(RCC_APB2ENR_SDMMC1EN)
#define __HAL_RCC_SDMMC1_IS_CLK_DISABLED()     (READ_BIT(RCC->APB2ENR, RCC_APB2ENR_SDMMC1EN) == 0U)
#endif                                     

#define __HAL_RCC_TIM1_IS_CLK_DISABLED()       (READ_BIT(RCC->APB2ENR, RCC_APB2ENR_TIM1EN) == 0U)

#define __HAL_RCC_SPI1_IS_CLK_DISABLED()       (READ_BIT(RCC->APB2ENR, RCC_APB2ENR_SPI1EN) == 0U)

#if defined(TIM8)
#define __HAL_RCC_TIM8_IS_CLK_DISABLED()       (READ_BIT(RCC->APB2ENR, RCC_APB2ENR_TIM8EN) == 0U)
#endif           

#define __HAL_RCC_USART1_IS_CLK_DISABLED()     (READ_BIT(RCC->APB2ENR, RCC_APB2ENR_USART1EN) == 0U)

#define __HAL_RCC_TIM15_IS_CLK_DISABLED()      (READ_BIT(RCC->APB2ENR, RCC_APB2ENR_TIM15EN) == 0U)

#define __HAL_RCC_TIM16_IS_CLK_DISABLED()      (READ_BIT(RCC->APB2ENR, RCC_APB2ENR_TIM16EN) == 0U)

#if defined(TIM17)
#define __HAL_RCC_TIM17_IS_CLK_DISABLED()      (READ_BIT(RCC->APB2ENR, RCC_APB2ENR_TIM17EN) == 0U)
#endif            

#if defined(SAI1)
#define __HAL_RCC_SAI1_IS_CLK_DISABLED()       (READ_BIT(RCC->APB2ENR, RCC_APB2ENR_SAI1EN) == 0U)
#endif           

#if defined(SAI2)
#define __HAL_RCC_SAI2_IS_CLK_DISABLED()       (READ_BIT(RCC->APB2ENR, RCC_APB2ENR_SAI2EN) == 0U)
#endif           

#if defined(DFSDM1_Filter0)
#define __HAL_RCC_DFSDM1_IS_CLK_DISABLED()     (READ_BIT(RCC->APB2ENR, RCC_APB2ENR_DFSDM1EN) == 0U)
#endif                     

#if defined(LTDC)
#define __HAL_RCC_LTDC_IS_CLK_DISABLED()       (READ_BIT(RCC->APB2ENR, RCC_APB2ENR_LTDCEN) == 0U)
#endif           

#if defined(DSI)
#define __HAL_RCC_DSI_IS_CLK_DISABLED()        (READ_BIT(RCC->APB2ENR, RCC_APB2ENR_DSIEN) == 0U)
#endif          

   
      
    

                                                                              
                                                   
      
    
#define __HAL_RCC_AHB1_FORCE_RESET()           WRITE_REG(RCC->AHB1RSTR, 0xFFFFFFFFUL)

#define __HAL_RCC_DMA1_FORCE_RESET()           SET_BIT(RCC->AHB1RSTR, RCC_AHB1RSTR_DMA1RST)

#define __HAL_RCC_DMA2_FORCE_RESET()           SET_BIT(RCC->AHB1RSTR, RCC_AHB1RSTR_DMA2RST)

#if defined(DMAMUX1)
#define __HAL_RCC_DMAMUX1_FORCE_RESET()        SET_BIT(RCC->AHB1RSTR, RCC_AHB1RSTR_DMAMUX1RST)
#endif              

#define __HAL_RCC_FLASH_FORCE_RESET()          SET_BIT(RCC->AHB1RSTR, RCC_AHB1RSTR_FLASHRST)

#define __HAL_RCC_CRC_FORCE_RESET()            SET_BIT(RCC->AHB1RSTR, RCC_AHB1RSTR_CRCRST)

#define __HAL_RCC_TSC_FORCE_RESET()            SET_BIT(RCC->AHB1RSTR, RCC_AHB1RSTR_TSCRST)

#if defined(DMA2D)
#define __HAL_RCC_DMA2D_FORCE_RESET()          SET_BIT(RCC->AHB1RSTR, RCC_AHB1RSTR_DMA2DRST)
#endif            

#if defined(GFXMMU)
#define __HAL_RCC_GFXMMU_FORCE_RESET()         SET_BIT(RCC->AHB1RSTR, RCC_AHB1RSTR_GFXMMURST)
#endif             


#define __HAL_RCC_AHB1_RELEASE_RESET()         WRITE_REG(RCC->AHB1RSTR, 0x00000000UL)

#define __HAL_RCC_DMA1_RELEASE_RESET()         CLEAR_BIT(RCC->AHB1RSTR, RCC_AHB1RSTR_DMA1RST)

#define __HAL_RCC_DMA2_RELEASE_RESET()         CLEAR_BIT(RCC->AHB1RSTR, RCC_AHB1RSTR_DMA2RST)

#if defined(DMAMUX1)
#define __HAL_RCC_DMAMUX1_RELEASE_RESET()      CLEAR_BIT(RCC->AHB1RSTR, RCC_AHB1RSTR_DMAMUX1RST)
#endif              

#define __HAL_RCC_FLASH_RELEASE_RESET()        CLEAR_BIT(RCC->AHB1RSTR, RCC_AHB1RSTR_FLASHRST)

#define __HAL_RCC_CRC_RELEASE_RESET()          CLEAR_BIT(RCC->AHB1RSTR, RCC_AHB1RSTR_CRCRST)

#define __HAL_RCC_TSC_RELEASE_RESET()          CLEAR_BIT(RCC->AHB1RSTR, RCC_AHB1RSTR_TSCRST)

#if defined(DMA2D)
#define __HAL_RCC_DMA2D_RELEASE_RESET()        CLEAR_BIT(RCC->AHB1RSTR, RCC_AHB1RSTR_DMA2DRST)
#endif            

#if defined(GFXMMU)
#define __HAL_RCC_GFXMMU_RELEASE_RESET()       CLEAR_BIT(RCC->AHB1RSTR, RCC_AHB1RSTR_GFXMMURST)
#endif             

   
      
    

                                                                              
                                                   
      
    
#define __HAL_RCC_AHB2_FORCE_RESET()           WRITE_REG(RCC->AHB2RSTR, 0xFFFFFFFFUL)

#define __HAL_RCC_GPIOA_FORCE_RESET()          SET_BIT(RCC->AHB2RSTR, RCC_AHB2RSTR_GPIOARST)

#define __HAL_RCC_GPIOB_FORCE_RESET()          SET_BIT(RCC->AHB2RSTR, RCC_AHB2RSTR_GPIOBRST)

#define __HAL_RCC_GPIOC_FORCE_RESET()          SET_BIT(RCC->AHB2RSTR, RCC_AHB2RSTR_GPIOCRST)

#if defined(GPIOD)
#define __HAL_RCC_GPIOD_FORCE_RESET()          SET_BIT(RCC->AHB2RSTR, RCC_AHB2RSTR_GPIODRST)
#endif            

#if defined(GPIOE)
#define __HAL_RCC_GPIOE_FORCE_RESET()          SET_BIT(RCC->AHB2RSTR, RCC_AHB2RSTR_GPIOERST)
#endif            

#if defined(GPIOF)
#define __HAL_RCC_GPIOF_FORCE_RESET()          SET_BIT(RCC->AHB2RSTR, RCC_AHB2RSTR_GPIOFRST)
#endif            

#if defined(GPIOG)
#define __HAL_RCC_GPIOG_FORCE_RESET()          SET_BIT(RCC->AHB2RSTR, RCC_AHB2RSTR_GPIOGRST)
#endif            

#define __HAL_RCC_GPIOH_FORCE_RESET()          SET_BIT(RCC->AHB2RSTR, RCC_AHB2RSTR_GPIOHRST)

#if defined(GPIOI)
#define __HAL_RCC_GPIOI_FORCE_RESET()          SET_BIT(RCC->AHB2RSTR, RCC_AHB2RSTR_GPIOIRST)
#endif            

#if defined(USB_OTG_FS)
#define __HAL_RCC_USB_OTG_FS_FORCE_RESET()     SET_BIT(RCC->AHB2RSTR, RCC_AHB2RSTR_OTGFSRST)
#endif                 

#define __HAL_RCC_ADC_FORCE_RESET()            SET_BIT(RCC->AHB2RSTR, RCC_AHB2RSTR_ADCRST)

#if defined(DCMI)
#define __HAL_RCC_DCMI_FORCE_RESET()           SET_BIT(RCC->AHB2RSTR, RCC_AHB2RSTR_DCMIRST)
#endif           

#if defined(PKA)
#define __HAL_RCC_PKA_FORCE_RESET()            SET_BIT(RCC->AHB2RSTR, RCC_AHB2RSTR_PKARST)
#endif          

#if defined(AES)
#define __HAL_RCC_AES_FORCE_RESET()            SET_BIT(RCC->AHB2RSTR, RCC_AHB2RSTR_AESRST)
#endif          

#if defined(HASH)
#define __HAL_RCC_HASH_FORCE_RESET()           SET_BIT(RCC->AHB2RSTR, RCC_AHB2RSTR_HASHRST)
#endif           

#define __HAL_RCC_RNG_FORCE_RESET()            SET_BIT(RCC->AHB2RSTR, RCC_AHB2RSTR_RNGRST)

#if defined(OCTOSPIM)
#define __HAL_RCC_OSPIM_FORCE_RESET()          SET_BIT(RCC->AHB2RSTR, RCC_AHB2RSTR_OSPIMRST)
#endif               

#if defined(SDMMC1) && defined(RCC_AHB2RSTR_SDMMC1RST)
#define __HAL_RCC_SDMMC1_FORCE_RESET()         SET_BIT(RCC->AHB2RSTR, RCC_AHB2RSTR_SDMMC1RST)
#endif                                       

#if defined(SDMMC2)
#define __HAL_RCC_SDMMC2_FORCE_RESET()         SET_BIT(RCC->AHB2RSTR, RCC_AHB2RSTR_SDMMC2RST)
#endif             


#define __HAL_RCC_AHB2_RELEASE_RESET()         WRITE_REG(RCC->AHB2RSTR, 0x00000000UL)

#define __HAL_RCC_GPIOA_RELEASE_RESET()        CLEAR_BIT(RCC->AHB2RSTR, RCC_AHB2RSTR_GPIOARST)

#define __HAL_RCC_GPIOB_RELEASE_RESET()        CLEAR_BIT(RCC->AHB2RSTR, RCC_AHB2RSTR_GPIOBRST)

#define __HAL_RCC_GPIOC_RELEASE_RESET()        CLEAR_BIT(RCC->AHB2RSTR, RCC_AHB2RSTR_GPIOCRST)

#if defined(GPIOD)
#define __HAL_RCC_GPIOD_RELEASE_RESET()        CLEAR_BIT(RCC->AHB2RSTR, RCC_AHB2RSTR_GPIODRST)
#endif            

#if defined(GPIOE)
#define __HAL_RCC_GPIOE_RELEASE_RESET()        CLEAR_BIT(RCC->AHB2RSTR, RCC_AHB2RSTR_GPIOERST)
#endif            

#if defined(GPIOF)
#define __HAL_RCC_GPIOF_RELEASE_RESET()        CLEAR_BIT(RCC->AHB2RSTR, RCC_AHB2RSTR_GPIOFRST)
#endif            

#if defined(GPIOG)
#define __HAL_RCC_GPIOG_RELEASE_RESET()        CLEAR_BIT(RCC->AHB2RSTR, RCC_AHB2RSTR_GPIOGRST)
#endif            

#define __HAL_RCC_GPIOH_RELEASE_RESET()        CLEAR_BIT(RCC->AHB2RSTR, RCC_AHB2RSTR_GPIOHRST)

#if defined(GPIOI)
#define __HAL_RCC_GPIOI_RELEASE_RESET()        CLEAR_BIT(RCC->AHB2RSTR, RCC_AHB2RSTR_GPIOIRST)
#endif            

#if defined(USB_OTG_FS)
#define __HAL_RCC_USB_OTG_FS_RELEASE_RESET()   CLEAR_BIT(RCC->AHB2RSTR, RCC_AHB2RSTR_OTGFSRST)
#endif                 

#define __HAL_RCC_ADC_RELEASE_RESET()          CLEAR_BIT(RCC->AHB2RSTR, RCC_AHB2RSTR_ADCRST)

#if defined(DCMI)
#define __HAL_RCC_DCMI_RELEASE_RESET()         CLEAR_BIT(RCC->AHB2RSTR, RCC_AHB2RSTR_DCMIRST)
#endif           

#if defined(PKA)
#define __HAL_RCC_PKA_RELEASE_RESET()          CLEAR_BIT(RCC->AHB2RSTR, RCC_AHB2RSTR_PKARST)
#endif          

#if defined(AES)
#define __HAL_RCC_AES_RELEASE_RESET()          CLEAR_BIT(RCC->AHB2RSTR, RCC_AHB2RSTR_AESRST)
#endif          

#if defined(HASH)
#define __HAL_RCC_HASH_RELEASE_RESET()         CLEAR_BIT(RCC->AHB2RSTR, RCC_AHB2RSTR_HASHRST)
#endif           

#define __HAL_RCC_RNG_RELEASE_RESET()          CLEAR_BIT(RCC->AHB2RSTR, RCC_AHB2RSTR_RNGRST)

#if defined(OCTOSPIM)
#define __HAL_RCC_OSPIM_RELEASE_RESET()        CLEAR_BIT(RCC->AHB2RSTR, RCC_AHB2RSTR_OSPIMRST)
#endif               

#if defined(SDMMC1) && defined(RCC_AHB2RSTR_SDMMC1RST)
#define __HAL_RCC_SDMMC1_RELEASE_RESET()       CLEAR_BIT(RCC->AHB2RSTR, RCC_AHB2RSTR_SDMMC1RST)
#endif                                       

#if defined(SDMMC2)
#define __HAL_RCC_SDMMC2_RELEASE_RESET()       CLEAR_BIT(RCC->AHB2RSTR, RCC_AHB2RSTR_SDMMC2RST)
#endif             

   
      
    

                                                                              
                                                   
      
    
#define __HAL_RCC_AHB3_FORCE_RESET()           WRITE_REG(RCC->AHB3RSTR, 0xFFFFFFFFUL)

#if defined(FMC_BANK1)
#define __HAL_RCC_FMC_FORCE_RESET()            SET_BIT(RCC->AHB3RSTR, RCC_AHB3RSTR_FMCRST)
#endif                

#if defined(QUADSPI)
#define __HAL_RCC_QSPI_FORCE_RESET()           SET_BIT(RCC->AHB3RSTR, RCC_AHB3RSTR_QSPIRST)
#endif              

#if defined(OCTOSPI1)
#define __HAL_RCC_OSPI1_FORCE_RESET()          SET_BIT(RCC->AHB3RSTR, RCC_AHB3RSTR_OSPI1RST)
#endif               

#if defined(OCTOSPI2)
#define __HAL_RCC_OSPI2_FORCE_RESET()          SET_BIT(RCC->AHB3RSTR, RCC_AHB3RSTR_OSPI2RST)
#endif               

#define __HAL_RCC_AHB3_RELEASE_RESET()         WRITE_REG(RCC->AHB3RSTR, 0x00000000UL)

#if defined(FMC_BANK1)
#define __HAL_RCC_FMC_RELEASE_RESET()          CLEAR_BIT(RCC->AHB3RSTR, RCC_AHB3RSTR_FMCRST)
#endif                

#if defined(QUADSPI)
#define __HAL_RCC_QSPI_RELEASE_RESET()         CLEAR_BIT(RCC->AHB3RSTR, RCC_AHB3RSTR_QSPIRST)
#endif              

#if defined(OCTOSPI1)
#define __HAL_RCC_OSPI1_RELEASE_RESET()        CLEAR_BIT(RCC->AHB3RSTR, RCC_AHB3RSTR_OSPI1RST)
#endif               

#if defined(OCTOSPI2)
#define __HAL_RCC_OSPI2_RELEASE_RESET()        CLEAR_BIT(RCC->AHB3RSTR, RCC_AHB3RSTR_OSPI2RST)
#endif               

   
      
    

                                                                              
                                                   
      
    
#define __HAL_RCC_APB1_FORCE_RESET()           do { \
                                                 WRITE_REG(RCC->APB1RSTR1, 0xFFFFFFFFUL); \
                                                 WRITE_REG(RCC->APB1RSTR2, 0xFFFFFFFFUL); \
                                               } while(0)

#define __HAL_RCC_TIM2_FORCE_RESET()           SET_BIT(RCC->APB1RSTR1, RCC_APB1RSTR1_TIM2RST)

#if defined(TIM3)
#define __HAL_RCC_TIM3_FORCE_RESET()           SET_BIT(RCC->APB1RSTR1, RCC_APB1RSTR1_TIM3RST)
#endif           

#if defined(TIM4)
#define __HAL_RCC_TIM4_FORCE_RESET()           SET_BIT(RCC->APB1RSTR1, RCC_APB1RSTR1_TIM4RST)
#endif           

#if defined(TIM5)
#define __HAL_RCC_TIM5_FORCE_RESET()           SET_BIT(RCC->APB1RSTR1, RCC_APB1RSTR1_TIM5RST)
#endif           

#define __HAL_RCC_TIM6_FORCE_RESET()           SET_BIT(RCC->APB1RSTR1, RCC_APB1RSTR1_TIM6RST)

#if defined(TIM7)
#define __HAL_RCC_TIM7_FORCE_RESET()           SET_BIT(RCC->APB1RSTR1, RCC_APB1RSTR1_TIM7RST)
#endif           

#if defined(LCD)
#define __HAL_RCC_LCD_FORCE_RESET()            SET_BIT(RCC->APB1RSTR1, RCC_APB1RSTR1_LCDRST)
#endif          

#if defined(SPI2)
#define __HAL_RCC_SPI2_FORCE_RESET()           SET_BIT(RCC->APB1RSTR1, RCC_APB1RSTR1_SPI2RST)
#endif           

#if defined(SPI3)
#define __HAL_RCC_SPI3_FORCE_RESET()           SET_BIT(RCC->APB1RSTR1, RCC_APB1RSTR1_SPI3RST)
#endif           

#define __HAL_RCC_USART2_FORCE_RESET()         SET_BIT(RCC->APB1RSTR1, RCC_APB1RSTR1_USART2RST)

#if defined(USART3)
#define __HAL_RCC_USART3_FORCE_RESET()         SET_BIT(RCC->APB1RSTR1, RCC_APB1RSTR1_USART3RST)
#endif             

#if defined(UART4)
#define __HAL_RCC_UART4_FORCE_RESET()          SET_BIT(RCC->APB1RSTR1, RCC_APB1RSTR1_UART4RST)
#endif            

#if defined(UART5)
#define __HAL_RCC_UART5_FORCE_RESET()          SET_BIT(RCC->APB1RSTR1, RCC_APB1RSTR1_UART5RST)
#endif            

#define __HAL_RCC_I2C1_FORCE_RESET()           SET_BIT(RCC->APB1RSTR1, RCC_APB1RSTR1_I2C1RST)

#if defined(I2C2)
#define __HAL_RCC_I2C2_FORCE_RESET()           SET_BIT(RCC->APB1RSTR1, RCC_APB1RSTR1_I2C2RST)
#endif           

#define __HAL_RCC_I2C3_FORCE_RESET()           SET_BIT(RCC->APB1RSTR1, RCC_APB1RSTR1_I2C3RST)

#if defined(I2C4)
#define __HAL_RCC_I2C4_FORCE_RESET()           SET_BIT(RCC->APB1RSTR2, RCC_APB1RSTR2_I2C4RST)
#endif           

#if defined(CRS)
#define __HAL_RCC_CRS_FORCE_RESET()            SET_BIT(RCC->APB1RSTR1, RCC_APB1RSTR1_CRSRST)
#endif          

#if defined(CAN1)
#define __HAL_RCC_CAN1_FORCE_RESET()           SET_BIT(RCC->APB1RSTR1, RCC_APB1RSTR1_CAN1RST)
#endif           

#if defined(CAN2)
#define __HAL_RCC_CAN2_FORCE_RESET()           SET_BIT(RCC->APB1RSTR1, RCC_APB1RSTR1_CAN2RST)
#endif           

#if defined(USB)
#define __HAL_RCC_USB_FORCE_RESET()            SET_BIT(RCC->APB1RSTR1, RCC_APB1RSTR1_USBFSRST)
#endif          

#define __HAL_RCC_PWR_FORCE_RESET()            SET_BIT(RCC->APB1RSTR1, RCC_APB1RSTR1_PWRRST)

#if defined(DAC1)
#define __HAL_RCC_DAC1_FORCE_RESET()           SET_BIT(RCC->APB1RSTR1, RCC_APB1RSTR1_DAC1RST)
#endif           

#define __HAL_RCC_OPAMP_FORCE_RESET()          SET_BIT(RCC->APB1RSTR1, RCC_APB1RSTR1_OPAMPRST)

#define __HAL_RCC_LPTIM1_FORCE_RESET()         SET_BIT(RCC->APB1RSTR1, RCC_APB1RSTR1_LPTIM1RST)

#define __HAL_RCC_LPUART1_FORCE_RESET()        SET_BIT(RCC->APB1RSTR2, RCC_APB1RSTR2_LPUART1RST)

#if defined(SWPMI1)
#define __HAL_RCC_SWPMI1_FORCE_RESET()         SET_BIT(RCC->APB1RSTR2, RCC_APB1RSTR2_SWPMI1RST)
#endif             

#define __HAL_RCC_LPTIM2_FORCE_RESET()         SET_BIT(RCC->APB1RSTR2, RCC_APB1RSTR2_LPTIM2RST)


#define __HAL_RCC_APB1_RELEASE_RESET()         do { \
                                                 WRITE_REG(RCC->APB1RSTR1, 0x00000000UL); \
                                                 WRITE_REG(RCC->APB1RSTR2, 0x00000000UL); \
                                               } while(0)

#define __HAL_RCC_TIM2_RELEASE_RESET()         CLEAR_BIT(RCC->APB1RSTR1, RCC_APB1RSTR1_TIM2RST)

#if defined(TIM3)
#define __HAL_RCC_TIM3_RELEASE_RESET()         CLEAR_BIT(RCC->APB1RSTR1, RCC_APB1RSTR1_TIM3RST)
#endif           

#if defined(TIM4)
#define __HAL_RCC_TIM4_RELEASE_RESET()         CLEAR_BIT(RCC->APB1RSTR1, RCC_APB1RSTR1_TIM4RST)
#endif           

#if defined(TIM5)
#define __HAL_RCC_TIM5_RELEASE_RESET()         CLEAR_BIT(RCC->APB1RSTR1, RCC_APB1RSTR1_TIM5RST)
#endif           

#define __HAL_RCC_TIM6_RELEASE_RESET()         CLEAR_BIT(RCC->APB1RSTR1, RCC_APB1RSTR1_TIM6RST)

#if defined(TIM7)
#define __HAL_RCC_TIM7_RELEASE_RESET()         CLEAR_BIT(RCC->APB1RSTR1, RCC_APB1RSTR1_TIM7RST)
#endif           

#if defined(LCD)
#define __HAL_RCC_LCD_RELEASE_RESET()          CLEAR_BIT(RCC->APB1RSTR1, RCC_APB1RSTR1_LCDRST)
#endif          

#if defined(SPI2)
#define __HAL_RCC_SPI2_RELEASE_RESET()         CLEAR_BIT(RCC->APB1RSTR1, RCC_APB1RSTR1_SPI2RST)
#endif           

#if defined(SPI3)
#define __HAL_RCC_SPI3_RELEASE_RESET()         CLEAR_BIT(RCC->APB1RSTR1, RCC_APB1RSTR1_SPI3RST)
#endif           

#define __HAL_RCC_USART2_RELEASE_RESET()       CLEAR_BIT(RCC->APB1RSTR1, RCC_APB1RSTR1_USART2RST)

#if defined(USART3)
#define __HAL_RCC_USART3_RELEASE_RESET()       CLEAR_BIT(RCC->APB1RSTR1, RCC_APB1RSTR1_USART3RST)
#endif             

#if defined(UART4)
#define __HAL_RCC_UART4_RELEASE_RESET()        CLEAR_BIT(RCC->APB1RSTR1, RCC_APB1RSTR1_UART4RST)
#endif            

#if defined(UART5)
#define __HAL_RCC_UART5_RELEASE_RESET()        CLEAR_BIT(RCC->APB1RSTR1, RCC_APB1RSTR1_UART5RST)
#endif            

#define __HAL_RCC_I2C1_RELEASE_RESET()         CLEAR_BIT(RCC->APB1RSTR1, RCC_APB1RSTR1_I2C1RST)

#if defined(I2C2)
#define __HAL_RCC_I2C2_RELEASE_RESET()         CLEAR_BIT(RCC->APB1RSTR1, RCC_APB1RSTR1_I2C2RST)
#endif           

#define __HAL_RCC_I2C3_RELEASE_RESET()         CLEAR_BIT(RCC->APB1RSTR1, RCC_APB1RSTR1_I2C3RST)

#if defined(I2C4)
#define __HAL_RCC_I2C4_RELEASE_RESET()         CLEAR_BIT(RCC->APB1RSTR2, RCC_APB1RSTR2_I2C4RST)
#endif           

#if defined(CRS)
#define __HAL_RCC_CRS_RELEASE_RESET()          CLEAR_BIT(RCC->APB1RSTR1, RCC_APB1RSTR1_CRSRST)
#endif          

#if defined(CAN1)
#define __HAL_RCC_CAN1_RELEASE_RESET()         CLEAR_BIT(RCC->APB1RSTR1, RCC_APB1RSTR1_CAN1RST)
#endif           

#if defined(CAN2)
#define __HAL_RCC_CAN2_RELEASE_RESET()         CLEAR_BIT(RCC->APB1RSTR1, RCC_APB1RSTR1_CAN2RST)
#endif           

#if defined(USB)
#define __HAL_RCC_USB_RELEASE_RESET()          CLEAR_BIT(RCC->APB1RSTR1, RCC_APB1RSTR1_USBFSRST)
#endif          

#define __HAL_RCC_PWR_RELEASE_RESET()          CLEAR_BIT(RCC->APB1RSTR1, RCC_APB1RSTR1_PWRRST)

#if defined(DAC1)
#define __HAL_RCC_DAC1_RELEASE_RESET()         CLEAR_BIT(RCC->APB1RSTR1, RCC_APB1RSTR1_DAC1RST)
#endif           

#define __HAL_RCC_OPAMP_RELEASE_RESET()        CLEAR_BIT(RCC->APB1RSTR1, RCC_APB1RSTR1_OPAMPRST)

#define __HAL_RCC_LPTIM1_RELEASE_RESET()       CLEAR_BIT(RCC->APB1RSTR1, RCC_APB1RSTR1_LPTIM1RST)

#define __HAL_RCC_LPUART1_RELEASE_RESET()      CLEAR_BIT(RCC->APB1RSTR2, RCC_APB1RSTR2_LPUART1RST)

#if defined(SWPMI1)
#define __HAL_RCC_SWPMI1_RELEASE_RESET()       CLEAR_BIT(RCC->APB1RSTR2, RCC_APB1RSTR2_SWPMI1RST)
#endif             

#define __HAL_RCC_LPTIM2_RELEASE_RESET()       CLEAR_BIT(RCC->APB1RSTR2, RCC_APB1RSTR2_LPTIM2RST)

   
      
    

                                                                              
                                                   
      
    
#define __HAL_RCC_APB2_FORCE_RESET()           WRITE_REG(RCC->APB2RSTR, 0xFFFFFFFFUL)

#define __HAL_RCC_SYSCFG_FORCE_RESET()         SET_BIT(RCC->APB2RSTR, RCC_APB2RSTR_SYSCFGRST)

#if defined(SDMMC1) && defined(RCC_APB2RSTR_SDMMC1RST)
#define __HAL_RCC_SDMMC1_FORCE_RESET()         SET_BIT(RCC->APB2RSTR, RCC_APB2RSTR_SDMMC1RST)
#endif                                       

#define __HAL_RCC_TIM1_FORCE_RESET()           SET_BIT(RCC->APB2RSTR, RCC_APB2RSTR_TIM1RST)

#define __HAL_RCC_SPI1_FORCE_RESET()           SET_BIT(RCC->APB2RSTR, RCC_APB2RSTR_SPI1RST)

#if defined(TIM8)
#define __HAL_RCC_TIM8_FORCE_RESET()           SET_BIT(RCC->APB2RSTR, RCC_APB2RSTR_TIM8RST)
#endif           

#define __HAL_RCC_USART1_FORCE_RESET()         SET_BIT(RCC->APB2RSTR, RCC_APB2RSTR_USART1RST)

#define __HAL_RCC_TIM15_FORCE_RESET()          SET_BIT(RCC->APB2RSTR, RCC_APB2RSTR_TIM15RST)

#define __HAL_RCC_TIM16_FORCE_RESET()          SET_BIT(RCC->APB2RSTR, RCC_APB2RSTR_TIM16RST)

#if defined(TIM17)
#define __HAL_RCC_TIM17_FORCE_RESET()          SET_BIT(RCC->APB2RSTR, RCC_APB2RSTR_TIM17RST)
#endif            

#if defined(SAI1)
#define __HAL_RCC_SAI1_FORCE_RESET()           SET_BIT(RCC->APB2RSTR, RCC_APB2RSTR_SAI1RST)
#endif           

#if defined(SAI2)
#define __HAL_RCC_SAI2_FORCE_RESET()           SET_BIT(RCC->APB2RSTR, RCC_APB2RSTR_SAI2RST)
#endif           

#if defined(DFSDM1_Filter0)
#define __HAL_RCC_DFSDM1_FORCE_RESET()         SET_BIT(RCC->APB2RSTR, RCC_APB2RSTR_DFSDM1RST)
#endif                     

#if defined(LTDC)
#define __HAL_RCC_LTDC_FORCE_RESET()           SET_BIT(RCC->APB2RSTR, RCC_APB2RSTR_LTDCRST)
#endif           

#if defined(DSI)
#define __HAL_RCC_DSI_FORCE_RESET()            SET_BIT(RCC->APB2RSTR, RCC_APB2RSTR_DSIRST)
#endif          


#define __HAL_RCC_APB2_RELEASE_RESET()         WRITE_REG(RCC->APB2RSTR, 0x00000000UL)

#define __HAL_RCC_SYSCFG_RELEASE_RESET()       CLEAR_BIT(RCC->APB2RSTR, RCC_APB2RSTR_SYSCFGRST)

#if defined(SDMMC1) && defined(RCC_APB2RSTR_SDMMC1RST)
#define __HAL_RCC_SDMMC1_RELEASE_RESET()       CLEAR_BIT(RCC->APB2RSTR, RCC_APB2RSTR_SDMMC1RST)
#endif                                       

#define __HAL_RCC_TIM1_RELEASE_RESET()         CLEAR_BIT(RCC->APB2RSTR, RCC_APB2RSTR_TIM1RST)

#define __HAL_RCC_SPI1_RELEASE_RESET()         CLEAR_BIT(RCC->APB2RSTR, RCC_APB2RSTR_SPI1RST)

#if defined(TIM8)
#define __HAL_RCC_TIM8_RELEASE_RESET()         CLEAR_BIT(RCC->APB2RSTR, RCC_APB2RSTR_TIM8RST)
#endif           

#define __HAL_RCC_USART1_RELEASE_RESET()       CLEAR_BIT(RCC->APB2RSTR, RCC_APB2RSTR_USART1RST)

#define __HAL_RCC_TIM15_RELEASE_RESET()        CLEAR_BIT(RCC->APB2RSTR, RCC_APB2RSTR_TIM15RST)

#define __HAL_RCC_TIM16_RELEASE_RESET()        CLEAR_BIT(RCC->APB2RSTR, RCC_APB2RSTR_TIM16RST)

#if defined(TIM17)
#define __HAL_RCC_TIM17_RELEASE_RESET()        CLEAR_BIT(RCC->APB2RSTR, RCC_APB2RSTR_TIM17RST)
#endif            

#if defined(SAI1)
#define __HAL_RCC_SAI1_RELEASE_RESET()         CLEAR_BIT(RCC->APB2RSTR, RCC_APB2RSTR_SAI1RST)
#endif           

#if defined(SAI2)
#define __HAL_RCC_SAI2_RELEASE_RESET()         CLEAR_BIT(RCC->APB2RSTR, RCC_APB2RSTR_SAI2RST)
#endif           

#if defined(DFSDM1_Filter0)
#define __HAL_RCC_DFSDM1_RELEASE_RESET()       CLEAR_BIT(RCC->APB2RSTR, RCC_APB2RSTR_DFSDM1RST)
#endif                     

#if defined(LTDC)
#define __HAL_RCC_LTDC_RELEASE_RESET()         CLEAR_BIT(RCC->APB2RSTR, RCC_APB2RSTR_LTDCRST)
#endif           

#if defined(DSI)
#define __HAL_RCC_DSI_RELEASE_RESET()          CLEAR_BIT(RCC->APB2RSTR, RCC_APB2RSTR_DSIRST)
#endif          

   
      
    

                                                                                            
                                                                                      
                                                                               
                              
                                                                                
                                                                            
      
    

#define __HAL_RCC_DMA1_CLK_SLEEP_ENABLE()      SET_BIT(RCC->AHB1SMENR, RCC_AHB1SMENR_DMA1SMEN)

#define __HAL_RCC_DMA2_CLK_SLEEP_ENABLE()      SET_BIT(RCC->AHB1SMENR, RCC_AHB1SMENR_DMA2SMEN)

#if defined(DMAMUX1)
#define __HAL_RCC_DMAMUX1_CLK_SLEEP_ENABLE()   SET_BIT(RCC->AHB1SMENR, RCC_AHB1SMENR_DMAMUX1SMEN)
#endif              

#define __HAL_RCC_FLASH_CLK_SLEEP_ENABLE()     SET_BIT(RCC->AHB1SMENR, RCC_AHB1SMENR_FLASHSMEN)

#define __HAL_RCC_SRAM1_CLK_SLEEP_ENABLE()     SET_BIT(RCC->AHB1SMENR, RCC_AHB1SMENR_SRAM1SMEN)

#define __HAL_RCC_CRC_CLK_SLEEP_ENABLE()       SET_BIT(RCC->AHB1SMENR, RCC_AHB1SMENR_CRCSMEN)

#define __HAL_RCC_TSC_CLK_SLEEP_ENABLE()       SET_BIT(RCC->AHB1SMENR, RCC_AHB1SMENR_TSCSMEN)

#if defined(DMA2D)
#define __HAL_RCC_DMA2D_CLK_SLEEP_ENABLE()     SET_BIT(RCC->AHB1SMENR, RCC_AHB1SMENR_DMA2DSMEN)
#endif            

#if defined(GFXMMU)
#define __HAL_RCC_GFXMMU_CLK_SLEEP_ENABLE()    SET_BIT(RCC->AHB1SMENR, RCC_AHB1SMENR_GFXMMUSMEN)
#endif             


#define __HAL_RCC_DMA1_CLK_SLEEP_DISABLE()     CLEAR_BIT(RCC->AHB1SMENR, RCC_AHB1SMENR_DMA1SMEN)

#define __HAL_RCC_DMA2_CLK_SLEEP_DISABLE()     CLEAR_BIT(RCC->AHB1SMENR, RCC_AHB1SMENR_DMA2SMEN)

#if defined(DMAMUX1)
#define __HAL_RCC_DMAMUX1_CLK_SLEEP_DISABLE()  CLEAR_BIT(RCC->AHB1SMENR, RCC_AHB1SMENR_DMAMUX1SMEN)
#endif              

#define __HAL_RCC_FLASH_CLK_SLEEP_DISABLE()    CLEAR_BIT(RCC->AHB1SMENR, RCC_AHB1SMENR_FLASHSMEN)

#define __HAL_RCC_SRAM1_CLK_SLEEP_DISABLE()    CLEAR_BIT(RCC->AHB1SMENR, RCC_AHB1SMENR_SRAM1SMEN)

#define __HAL_RCC_CRC_CLK_SLEEP_DISABLE()      CLEAR_BIT(RCC->AHB1SMENR, RCC_AHB1SMENR_CRCSMEN)

#define __HAL_RCC_TSC_CLK_SLEEP_DISABLE()      CLEAR_BIT(RCC->AHB1SMENR, RCC_AHB1SMENR_TSCSMEN)

#if defined(DMA2D)
#define __HAL_RCC_DMA2D_CLK_SLEEP_DISABLE()    CLEAR_BIT(RCC->AHB1SMENR, RCC_AHB1SMENR_DMA2DSMEN)
#endif            

#if defined(GFXMMU)
#define __HAL_RCC_GFXMMU_CLK_SLEEP_DISABLE()   CLEAR_BIT(RCC->AHB1SMENR, RCC_AHB1SMENR_GFXMMUSMEN)
#endif             

   
      
    

                                                                                            
                                                                                      
                                                                               
                              
                                                                                
                                                                            
      
    

#define __HAL_RCC_GPIOA_CLK_SLEEP_ENABLE()     SET_BIT(RCC->AHB2SMENR, RCC_AHB2SMENR_GPIOASMEN)

#define __HAL_RCC_GPIOB_CLK_SLEEP_ENABLE()     SET_BIT(RCC->AHB2SMENR, RCC_AHB2SMENR_GPIOBSMEN)

#define __HAL_RCC_GPIOC_CLK_SLEEP_ENABLE()     SET_BIT(RCC->AHB2SMENR, RCC_AHB2SMENR_GPIOCSMEN)

#if defined(GPIOD)
#define __HAL_RCC_GPIOD_CLK_SLEEP_ENABLE()     SET_BIT(RCC->AHB2SMENR, RCC_AHB2SMENR_GPIODSMEN)
#endif            

#if defined(GPIOE)
#define __HAL_RCC_GPIOE_CLK_SLEEP_ENABLE()     SET_BIT(RCC->AHB2SMENR, RCC_AHB2SMENR_GPIOESMEN)
#endif            

#if defined(GPIOF)
#define __HAL_RCC_GPIOF_CLK_SLEEP_ENABLE()     SET_BIT(RCC->AHB2SMENR, RCC_AHB2SMENR_GPIOFSMEN)
#endif            

#if defined(GPIOG)
#define __HAL_RCC_GPIOG_CLK_SLEEP_ENABLE()     SET_BIT(RCC->AHB2SMENR, RCC_AHB2SMENR_GPIOGSMEN)
#endif            

#define __HAL_RCC_GPIOH_CLK_SLEEP_ENABLE()     SET_BIT(RCC->AHB2SMENR, RCC_AHB2SMENR_GPIOHSMEN)

#if defined(GPIOI)
#define __HAL_RCC_GPIOI_CLK_SLEEP_ENABLE()     SET_BIT(RCC->AHB2SMENR, RCC_AHB2SMENR_GPIOISMEN)
#endif            

#define __HAL_RCC_SRAM2_CLK_SLEEP_ENABLE()     SET_BIT(RCC->AHB2SMENR, RCC_AHB2SMENR_SRAM2SMEN)

#if defined(SRAM3)
#define __HAL_RCC_SRAM3_CLK_SLEEP_ENABLE()     SET_BIT(RCC->AHB2SMENR, RCC_AHB2SMENR_SRAM3SMEN)
#endif            

#if defined(USB_OTG_FS)
#define __HAL_RCC_USB_OTG_FS_CLK_SLEEP_ENABLE()  SET_BIT(RCC->AHB2SMENR, RCC_AHB2SMENR_OTGFSSMEN)
#endif                 

#define __HAL_RCC_ADC_CLK_SLEEP_ENABLE()       SET_BIT(RCC->AHB2SMENR, RCC_AHB2SMENR_ADCSMEN)

#if defined(DCMI)
#define __HAL_RCC_DCMI_CLK_SLEEP_ENABLE()      SET_BIT(RCC->AHB2SMENR, RCC_AHB2SMENR_DCMISMEN)
#endif           

#if defined(PKA)
#define __HAL_RCC_PKA_CLK_SLEEP_ENABLE()       SET_BIT(RCC->AHB2SMENR, RCC_AHB2SMENR_PKASMEN)
#endif          

#if defined(AES)
#define __HAL_RCC_AES_CLK_SLEEP_ENABLE()       SET_BIT(RCC->AHB2SMENR, RCC_AHB2SMENR_AESSMEN)
#endif          

#if defined(HASH)
#define __HAL_RCC_HASH_CLK_SLEEP_ENABLE()      SET_BIT(RCC->AHB2SMENR, RCC_AHB2SMENR_HASHSMEN)
#endif           

#define __HAL_RCC_RNG_CLK_SLEEP_ENABLE()       SET_BIT(RCC->AHB2SMENR, RCC_AHB2SMENR_RNGSMEN)

#if defined(OCTOSPIM)
#define __HAL_RCC_OSPIM_CLK_SLEEP_ENABLE()     SET_BIT(RCC->AHB2SMENR, RCC_AHB2SMENR_OSPIMSMEN)
#endif               

#if defined(SDMMC1) && defined(RCC_AHB2SMENR_SDMMC1SMEN)
#define __HAL_RCC_SDMMC1_CLK_SLEEP_ENABLE()    SET_BIT(RCC->AHB2SMENR, RCC_AHB2SMENR_SDMMC1SMEN)
#endif                                         

#if defined(SDMMC2)
#define __HAL_RCC_SDMMC2_CLK_SLEEP_ENABLE()    SET_BIT(RCC->AHB2SMENR, RCC_AHB2SMENR_SDMMC2SMEN)
#endif             


#define __HAL_RCC_GPIOA_CLK_SLEEP_DISABLE()    CLEAR_BIT(RCC->AHB2SMENR, RCC_AHB2SMENR_GPIOASMEN)

#define __HAL_RCC_GPIOB_CLK_SLEEP_DISABLE()    CLEAR_BIT(RCC->AHB2SMENR, RCC_AHB2SMENR_GPIOBSMEN)

#define __HAL_RCC_GPIOC_CLK_SLEEP_DISABLE()    CLEAR_BIT(RCC->AHB2SMENR, RCC_AHB2SMENR_GPIOCSMEN)

#if defined(GPIOD)
#define __HAL_RCC_GPIOD_CLK_SLEEP_DISABLE()    CLEAR_BIT(RCC->AHB2SMENR, RCC_AHB2SMENR_GPIODSMEN)
#endif            

#if defined(GPIOE)
#define __HAL_RCC_GPIOE_CLK_SLEEP_DISABLE()    CLEAR_BIT(RCC->AHB2SMENR, RCC_AHB2SMENR_GPIOESMEN)
#endif            

#if defined(GPIOF)
#define __HAL_RCC_GPIOF_CLK_SLEEP_DISABLE()    CLEAR_BIT(RCC->AHB2SMENR, RCC_AHB2SMENR_GPIOFSMEN)
#endif            

#if defined(GPIOG)
#define __HAL_RCC_GPIOG_CLK_SLEEP_DISABLE()    CLEAR_BIT(RCC->AHB2SMENR, RCC_AHB2SMENR_GPIOGSMEN)
#endif            

#define __HAL_RCC_GPIOH_CLK_SLEEP_DISABLE()    CLEAR_BIT(RCC->AHB2SMENR, RCC_AHB2SMENR_GPIOHSMEN)

#if defined(GPIOI)
#define __HAL_RCC_GPIOI_CLK_SLEEP_DISABLE()    CLEAR_BIT(RCC->AHB2SMENR, RCC_AHB2SMENR_GPIOISMEN)
#endif            

#define __HAL_RCC_SRAM2_CLK_SLEEP_DISABLE()    CLEAR_BIT(RCC->AHB2SMENR, RCC_AHB2SMENR_SRAM2SMEN)

#if defined(SRAM3)
#define __HAL_RCC_SRAM3_IS_CLK_SLEEP_DISABLE()    CLEAR_BIT(RCC->AHB2SMENR, RCC_AHB2SMENR_SRAM3SMEN)
#endif            

#if defined(USB_OTG_FS)
#define __HAL_RCC_USB_OTG_FS_CLK_SLEEP_DISABLE() CLEAR_BIT(RCC->AHB2SMENR, RCC_AHB2SMENR_OTGFSSMEN)
#endif                 

#define __HAL_RCC_ADC_CLK_SLEEP_DISABLE()      CLEAR_BIT(RCC->AHB2SMENR, RCC_AHB2SMENR_ADCSMEN)

#if defined(DCMI)
#define __HAL_RCC_DCMI_CLK_SLEEP_DISABLE()     CLEAR_BIT(RCC->AHB2SMENR, RCC_AHB2SMENR_DCMISMEN)
#endif           

#if defined(PKA)
#define __HAL_RCC_PKA_CLK_SLEEP_DISABLE()      CLEAR_BIT(RCC->AHB2SMENR, RCC_AHB2SMENR_PKASMEN)
#endif          

#if defined(AES)
#define __HAL_RCC_AES_CLK_SLEEP_DISABLE()      CLEAR_BIT(RCC->AHB2SMENR, RCC_AHB2SMENR_AESSMEN)
#endif          

#if defined(HASH)
#define __HAL_RCC_HASH_CLK_SLEEP_DISABLE()     CLEAR_BIT(RCC->AHB2SMENR, RCC_AHB2SMENR_HASHSMEN)
#endif           

#define __HAL_RCC_RNG_CLK_SLEEP_DISABLE()      CLEAR_BIT(RCC->AHB2SMENR, RCC_AHB2SMENR_RNGSMEN)

#if defined(OCTOSPIM)
#define __HAL_RCC_OSPIM_CLK_SLEEP_DISABLE()    CLEAR_BIT(RCC->AHB2SMENR, RCC_AHB2SMENR_OSPIMSMEN)
#endif               

#if defined(SDMMC1) && defined(RCC_AHB2SMENR_SDMMC1SMEN)
#define __HAL_RCC_SDMMC1_CLK_SLEEP_DISABLE()   CLEAR_BIT(RCC->AHB2SMENR, RCC_AHB2SMENR_SDMMC1SMEN)
#endif                                         

#if defined(SDMMC2)
#define __HAL_RCC_SDMMC2_CLK_SLEEP_DISABLE()   CLEAR_BIT(RCC->AHB2SMENR, RCC_AHB2SMENR_SDMMC2SMEN)
#endif             

   
      
    

                                                                                            
                                                                                      
                                                                               
                              
                                                                                
                                                                            
      
    

#if defined(QUADSPI)
#define __HAL_RCC_QSPI_CLK_SLEEP_ENABLE()      SET_BIT(RCC->AHB3SMENR, RCC_AHB3SMENR_QSPISMEN)
#endif              

#if defined(OCTOSPI1)
#define __HAL_RCC_OSPI1_CLK_SLEEP_ENABLE()     SET_BIT(RCC->AHB3SMENR, RCC_AHB3SMENR_OSPI1SMEN)
#endif               

#if defined(OCTOSPI2)
#define __HAL_RCC_OSPI2_CLK_SLEEP_ENABLE()     SET_BIT(RCC->AHB3SMENR, RCC_AHB3SMENR_OSPI2SMEN)
#endif               

#if defined(FMC_BANK1)
#define __HAL_RCC_FMC_CLK_SLEEP_ENABLE()       SET_BIT(RCC->AHB3SMENR, RCC_AHB3SMENR_FMCSMEN)
#endif                

#if defined(QUADSPI)
#define __HAL_RCC_QSPI_CLK_SLEEP_DISABLE()     CLEAR_BIT(RCC->AHB3SMENR, RCC_AHB3SMENR_QSPISMEN)
#endif              

#if defined(OCTOSPI1)
#define __HAL_RCC_OSPI1_CLK_SLEEP_DISABLE()    CLEAR_BIT(RCC->AHB3SMENR, RCC_AHB3SMENR_OSPI1SMEN)
#endif               

#if defined(OCTOSPI2)
#define __HAL_RCC_OSPI2_CLK_SLEEP_DISABLE()    CLEAR_BIT(RCC->AHB3SMENR, RCC_AHB3SMENR_OSPI2SMEN)
#endif               

#if defined(FMC_BANK1)
#define __HAL_RCC_FMC_CLK_SLEEP_DISABLE()      CLEAR_BIT(RCC->AHB3SMENR, RCC_AHB3SMENR_FMCSMEN)
#endif                

   
      
    

                                                                                            
                                                                                      
                                                                               
                              
                                                                                
                                                                            
      
    

#define __HAL_RCC_TIM2_CLK_SLEEP_ENABLE()      SET_BIT(RCC->APB1SMENR1, RCC_APB1SMENR1_TIM2SMEN)

#if defined(TIM3)
#define __HAL_RCC_TIM3_CLK_SLEEP_ENABLE()      SET_BIT(RCC->APB1SMENR1, RCC_APB1SMENR1_TIM3SMEN)
#endif           

#if defined(TIM4)
#define __HAL_RCC_TIM4_CLK_SLEEP_ENABLE()      SET_BIT(RCC->APB1SMENR1, RCC_APB1SMENR1_TIM4SMEN)
#endif           

#if defined(TIM5)
#define __HAL_RCC_TIM5_CLK_SLEEP_ENABLE()      SET_BIT(RCC->APB1SMENR1, RCC_APB1SMENR1_TIM5SMEN)
#endif           

#define __HAL_RCC_TIM6_CLK_SLEEP_ENABLE()      SET_BIT(RCC->APB1SMENR1, RCC_APB1SMENR1_TIM6SMEN)

#if defined(TIM7)
#define __HAL_RCC_TIM7_CLK_SLEEP_ENABLE()      SET_BIT(RCC->APB1SMENR1, RCC_APB1SMENR1_TIM7SMEN)
#endif           

#if defined(LCD)
#define __HAL_RCC_LCD_CLK_SLEEP_ENABLE()       SET_BIT(RCC->APB1SMENR1, RCC_APB1SMENR1_LCDSMEN)
#endif          

#if defined(RCC_APB1SMENR1_RTCAPBSMEN)
#define __HAL_RCC_RTCAPB_CLK_SLEEP_ENABLE()    SET_BIT(RCC->APB1SMENR1, RCC_APB1SMENR1_RTCAPBSMEN)
#endif                                

#define __HAL_RCC_WWDG_CLK_SLEEP_ENABLE()      SET_BIT(RCC->APB1SMENR1, RCC_APB1SMENR1_WWDGSMEN)

#if defined(SPI2)
#define __HAL_RCC_SPI2_CLK_SLEEP_ENABLE()      SET_BIT(RCC->APB1SMENR1, RCC_APB1SMENR1_SPI2SMEN)
#endif           

#if defined(SPI3)
#define __HAL_RCC_SPI3_CLK_SLEEP_ENABLE()      SET_BIT(RCC->APB1SMENR1, RCC_APB1SMENR1_SPI3SMEN)
#endif           

#define __HAL_RCC_USART2_CLK_SLEEP_ENABLE()    SET_BIT(RCC->APB1SMENR1, RCC_APB1SMENR1_USART2SMEN)

#if defined(USART3)
#define __HAL_RCC_USART3_CLK_SLEEP_ENABLE()    SET_BIT(RCC->APB1SMENR1, RCC_APB1SMENR1_USART3SMEN)
#endif             

#if defined(UART4)
#define __HAL_RCC_UART4_CLK_SLEEP_ENABLE()     SET_BIT(RCC->APB1SMENR1, RCC_APB1SMENR1_UART4SMEN)
#endif            

#if defined(UART5)
#define __HAL_RCC_UART5_CLK_SLEEP_ENABLE()     SET_BIT(RCC->APB1SMENR1, RCC_APB1SMENR1_UART5SMEN)
#endif            

#define __HAL_RCC_I2C1_CLK_SLEEP_ENABLE()      SET_BIT(RCC->APB1SMENR1, RCC_APB1SMENR1_I2C1SMEN)

#if defined(I2C2)
#define __HAL_RCC_I2C2_CLK_SLEEP_ENABLE()      SET_BIT(RCC->APB1SMENR1, RCC_APB1SMENR1_I2C2SMEN)
#endif           

#define __HAL_RCC_I2C3_CLK_SLEEP_ENABLE()      SET_BIT(RCC->APB1SMENR1, RCC_APB1SMENR1_I2C3SMEN)

#if defined(I2C4)
#define __HAL_RCC_I2C4_CLK_SLEEP_ENABLE()      SET_BIT(RCC->APB1SMENR2, RCC_APB1SMENR2_I2C4SMEN)
#endif           

#if defined(CRS)
#define __HAL_RCC_CRS_CLK_SLEEP_ENABLE()       SET_BIT(RCC->APB1SMENR1, RCC_APB1SMENR1_CRSSMEN)
#endif          

#if defined(CAN1)
#define __HAL_RCC_CAN1_CLK_SLEEP_ENABLE()      SET_BIT(RCC->APB1SMENR1, RCC_APB1SMENR1_CAN1SMEN)
#endif           

#if defined(CAN2)
#define __HAL_RCC_CAN2_CLK_SLEEP_ENABLE()      SET_BIT(RCC->APB1SMENR1, RCC_APB1SMENR1_CAN2SMEN)
#endif           

#if defined(USB)
#define __HAL_RCC_USB_CLK_SLEEP_ENABLE()       SET_BIT(RCC->APB1SMENR1, RCC_APB1SMENR1_USBFSSMEN)
#endif          

#define __HAL_RCC_PWR_CLK_SLEEP_ENABLE()       SET_BIT(RCC->APB1SMENR1, RCC_APB1SMENR1_PWRSMEN)

#if defined(DAC1)
#define __HAL_RCC_DAC1_CLK_SLEEP_ENABLE()      SET_BIT(RCC->APB1SMENR1, RCC_APB1SMENR1_DAC1SMEN)
#endif           

#define __HAL_RCC_OPAMP_CLK_SLEEP_ENABLE()     SET_BIT(RCC->APB1SMENR1, RCC_APB1SMENR1_OPAMPSMEN)

#define __HAL_RCC_LPTIM1_CLK_SLEEP_ENABLE()    SET_BIT(RCC->APB1SMENR1, RCC_APB1SMENR1_LPTIM1SMEN)

#define __HAL_RCC_LPUART1_CLK_SLEEP_ENABLE()   SET_BIT(RCC->APB1SMENR2, RCC_APB1SMENR2_LPUART1SMEN)

#if defined(SWPMI1)
#define __HAL_RCC_SWPMI1_CLK_SLEEP_ENABLE()    SET_BIT(RCC->APB1SMENR2, RCC_APB1SMENR2_SWPMI1SMEN)
#endif             

#define __HAL_RCC_LPTIM2_CLK_SLEEP_ENABLE()    SET_BIT(RCC->APB1SMENR2, RCC_APB1SMENR2_LPTIM2SMEN)


#define __HAL_RCC_TIM2_CLK_SLEEP_DISABLE()     CLEAR_BIT(RCC->APB1SMENR1, RCC_APB1SMENR1_TIM2SMEN)

#if defined(TIM3)
#define __HAL_RCC_TIM3_CLK_SLEEP_DISABLE()     CLEAR_BIT(RCC->APB1SMENR1, RCC_APB1SMENR1_TIM3SMEN)
#endif           

#if defined(TIM4)
#define __HAL_RCC_TIM4_CLK_SLEEP_DISABLE()     CLEAR_BIT(RCC->APB1SMENR1, RCC_APB1SMENR1_TIM4SMEN)
#endif           

#if defined(TIM5)
#define __HAL_RCC_TIM5_CLK_SLEEP_DISABLE()     CLEAR_BIT(RCC->APB1SMENR1, RCC_APB1SMENR1_TIM5SMEN)
#endif           

#define __HAL_RCC_TIM6_CLK_SLEEP_DISABLE()     CLEAR_BIT(RCC->APB1SMENR1, RCC_APB1SMENR1_TIM6SMEN)

#if defined(TIM7)
#define __HAL_RCC_TIM7_CLK_SLEEP_DISABLE()     CLEAR_BIT(RCC->APB1SMENR1, RCC_APB1SMENR1_TIM7SMEN)
#endif           

#if defined(LCD)
#define __HAL_RCC_LCD_CLK_SLEEP_DISABLE()      CLEAR_BIT(RCC->APB1SMENR1, RCC_APB1SMENR1_LCDSMEN)
#endif          

#if defined(RCC_APB1SMENR1_RTCAPBSMEN)
#define __HAL_RCC_RTCAPB_CLK_SLEEP_DISABLE()   CLEAR_BIT(RCC->APB1SMENR1, RCC_APB1SMENR1_RTCAPBSMEN)
#endif                                

#define __HAL_RCC_WWDG_CLK_SLEEP_DISABLE()     CLEAR_BIT(RCC->APB1SMENR1, RCC_APB1SMENR1_WWDGSMEN)

#if defined(SPI2)
#define __HAL_RCC_SPI2_CLK_SLEEP_DISABLE()     CLEAR_BIT(RCC->APB1SMENR1, RCC_APB1SMENR1_SPI2SMEN)
#endif           

#if defined(SPI3)
#define __HAL_RCC_SPI3_CLK_SLEEP_DISABLE()     CLEAR_BIT(RCC->APB1SMENR1, RCC_APB1SMENR1_SPI3SMEN)
#endif           

#define __HAL_RCC_USART2_CLK_SLEEP_DISABLE()   CLEAR_BIT(RCC->APB1SMENR1, RCC_APB1SMENR1_USART2SMEN)

#if defined(USART3)
#define __HAL_RCC_USART3_CLK_SLEEP_DISABLE()   CLEAR_BIT(RCC->APB1SMENR1, RCC_APB1SMENR1_USART3SMEN)
#endif             

#if defined(UART4)
#define __HAL_RCC_UART4_CLK_SLEEP_DISABLE()    CLEAR_BIT(RCC->APB1SMENR1, RCC_APB1SMENR1_UART4SMEN)
#endif            

#if defined(UART5)
#define __HAL_RCC_UART5_CLK_SLEEP_DISABLE()    CLEAR_BIT(RCC->APB1SMENR1, RCC_APB1SMENR1_UART5SMEN)
#endif            

#define __HAL_RCC_I2C1_CLK_SLEEP_DISABLE()     CLEAR_BIT(RCC->APB1SMENR1, RCC_APB1SMENR1_I2C1SMEN)

#if defined(I2C2)
#define __HAL_RCC_I2C2_CLK_SLEEP_DISABLE()     CLEAR_BIT(RCC->APB1SMENR1, RCC_APB1SMENR1_I2C2SMEN)
#endif           

#define __HAL_RCC_I2C3_CLK_SLEEP_DISABLE()     CLEAR_BIT(RCC->APB1SMENR1, RCC_APB1SMENR1_I2C3SMEN)

#if defined(I2C4)
#define __HAL_RCC_I2C4_CLK_SLEEP_DISABLE()     CLEAR_BIT(RCC->APB1SMENR2, RCC_APB1SMENR2_I2C4SMEN)
#endif           

#if defined(CRS)
#define __HAL_RCC_CRS_CLK_SLEEP_DISABLE()      CLEAR_BIT(RCC->APB1SMENR1, RCC_APB1SMENR1_CRSSMEN)
#endif          

#if defined(CAN1)
#define __HAL_RCC_CAN1_CLK_SLEEP_DISABLE()     CLEAR_BIT(RCC->APB1SMENR1, RCC_APB1SMENR1_CAN1SMEN)
#endif           

#if defined(CAN2)
#define __HAL_RCC_CAN2_CLK_SLEEP_DISABLE()     CLEAR_BIT(RCC->APB1SMENR1, RCC_APB1SMENR1_CAN2SMEN)
#endif           

#if defined(USB)
#define __HAL_RCC_USB_CLK_SLEEP_DISABLE()      CLEAR_BIT(RCC->APB1SMENR1, RCC_APB1SMENR1_USBFSSMEN)
#endif          

#define __HAL_RCC_PWR_CLK_SLEEP_DISABLE()      CLEAR_BIT(RCC->APB1SMENR1, RCC_APB1SMENR1_PWRSMEN)

#if defined(DAC1)
#define __HAL_RCC_DAC1_CLK_SLEEP_DISABLE()     CLEAR_BIT(RCC->APB1SMENR1, RCC_APB1SMENR1_DAC1SMEN)
#endif           

#define __HAL_RCC_OPAMP_CLK_SLEEP_DISABLE()    CLEAR_BIT(RCC->APB1SMENR1, RCC_APB1SMENR1_OPAMPSMEN)

#define __HAL_RCC_LPTIM1_CLK_SLEEP_DISABLE()   CLEAR_BIT(RCC->APB1SMENR1, RCC_APB1SMENR1_LPTIM1SMEN)

#define __HAL_RCC_LPUART1_CLK_SLEEP_DISABLE()  CLEAR_BIT(RCC->APB1SMENR2, RCC_APB1SMENR2_LPUART1SMEN)

#if defined(SWPMI1)
#define __HAL_RCC_SWPMI1_CLK_SLEEP_DISABLE()   CLEAR_BIT(RCC->APB1SMENR2, RCC_APB1SMENR2_SWPMI1SMEN)
#endif             

#define __HAL_RCC_LPTIM2_CLK_SLEEP_DISABLE()   CLEAR_BIT(RCC->APB1SMENR2, RCC_APB1SMENR2_LPTIM2SMEN)

   
      
    

                                                                                            
                                                                                      
                                                                               
                              
                                                                                
                                                                            
      
    

#define __HAL_RCC_SYSCFG_CLK_SLEEP_ENABLE()    SET_BIT(RCC->APB2SMENR, RCC_APB2SMENR_SYSCFGSMEN)

#if defined(SDMMC1) && defined(RCC_APB2SMENR_SDMMC1SMEN)
#define __HAL_RCC_SDMMC1_CLK_SLEEP_ENABLE()    SET_BIT(RCC->APB2SMENR, RCC_APB2SMENR_SDMMC1SMEN)
#endif                                         

#define __HAL_RCC_TIM1_CLK_SLEEP_ENABLE()      SET_BIT(RCC->APB2SMENR, RCC_APB2SMENR_TIM1SMEN)

#define __HAL_RCC_SPI1_CLK_SLEEP_ENABLE()      SET_BIT(RCC->APB2SMENR, RCC_APB2SMENR_SPI1SMEN)

#if defined(TIM8)
#define __HAL_RCC_TIM8_CLK_SLEEP_ENABLE()      SET_BIT(RCC->APB2SMENR, RCC_APB2SMENR_TIM8SMEN)
#endif           

#define __HAL_RCC_USART1_CLK_SLEEP_ENABLE()    SET_BIT(RCC->APB2SMENR, RCC_APB2SMENR_USART1SMEN)

#define __HAL_RCC_TIM15_CLK_SLEEP_ENABLE()     SET_BIT(RCC->APB2SMENR, RCC_APB2SMENR_TIM15SMEN)

#define __HAL_RCC_TIM16_CLK_SLEEP_ENABLE()     SET_BIT(RCC->APB2SMENR, RCC_APB2SMENR_TIM16SMEN)

#if defined(TIM17)
#define __HAL_RCC_TIM17_CLK_SLEEP_ENABLE()     SET_BIT(RCC->APB2SMENR, RCC_APB2SMENR_TIM17SMEN)
#endif            

#if defined(SAI1)
#define __HAL_RCC_SAI1_CLK_SLEEP_ENABLE()      SET_BIT(RCC->APB2SMENR, RCC_APB2SMENR_SAI1SMEN)
#endif           

#if defined(SAI2)
#define __HAL_RCC_SAI2_CLK_SLEEP_ENABLE()      SET_BIT(RCC->APB2SMENR, RCC_APB2SMENR_SAI2SMEN)
#endif           

#if defined(DFSDM1_Filter0)
#define __HAL_RCC_DFSDM1_CLK_SLEEP_ENABLE()    SET_BIT(RCC->APB2SMENR, RCC_APB2SMENR_DFSDM1SMEN)
#endif                     

#if defined(LTDC)
#define __HAL_RCC_LTDC_CLK_SLEEP_ENABLE()      SET_BIT(RCC->APB2SMENR, RCC_APB2SMENR_LTDCSMEN)
#endif           

#if defined(DSI)
#define __HAL_RCC_DSI_CLK_SLEEP_ENABLE()       SET_BIT(RCC->APB2SMENR, RCC_APB2SMENR_DSISMEN)
#endif          


#define __HAL_RCC_SYSCFG_CLK_SLEEP_DISABLE()   CLEAR_BIT(RCC->APB2SMENR, RCC_APB2SMENR_SYSCFGSMEN)

#if defined(SDMMC1) && defined(RCC_APB2SMENR_SDMMC1SMEN)
#define __HAL_RCC_SDMMC1_CLK_SLEEP_DISABLE()   CLEAR_BIT(RCC->APB2SMENR, RCC_APB2SMENR_SDMMC1SMEN)
#endif                                         

#define __HAL_RCC_TIM1_CLK_SLEEP_DISABLE()     CLEAR_BIT(RCC->APB2SMENR, RCC_APB2SMENR_TIM1SMEN)

#define __HAL_RCC_SPI1_CLK_SLEEP_DISABLE()     CLEAR_BIT(RCC->APB2SMENR, RCC_APB2SMENR_SPI1SMEN)

#if defined(TIM8)
#define __HAL_RCC_TIM8_CLK_SLEEP_DISABLE()     CLEAR_BIT(RCC->APB2SMENR, RCC_APB2SMENR_TIM8SMEN)
#endif           

#define __HAL_RCC_USART1_CLK_SLEEP_DISABLE()   CLEAR_BIT(RCC->APB2SMENR, RCC_APB2SMENR_USART1SMEN)

#define __HAL_RCC_TIM15_CLK_SLEEP_DISABLE()    CLEAR_BIT(RCC->APB2SMENR, RCC_APB2SMENR_TIM15SMEN)

#define __HAL_RCC_TIM16_CLK_SLEEP_DISABLE()    CLEAR_BIT(RCC->APB2SMENR, RCC_APB2SMENR_TIM16SMEN)

#if defined(TIM17)
#define __HAL_RCC_TIM17_CLK_SLEEP_DISABLE()    CLEAR_BIT(RCC->APB2SMENR, RCC_APB2SMENR_TIM17SMEN)
#endif            

#if defined(SAI1)
#define __HAL_RCC_SAI1_CLK_SLEEP_DISABLE()     CLEAR_BIT(RCC->APB2SMENR, RCC_APB2SMENR_SAI1SMEN)
#endif           

#if defined(SAI2)
#define __HAL_RCC_SAI2_CLK_SLEEP_DISABLE()     CLEAR_BIT(RCC->APB2SMENR, RCC_APB2SMENR_SAI2SMEN)
#endif           

#if defined(DFSDM1_Filter0)
#define __HAL_RCC_DFSDM1_CLK_SLEEP_DISABLE()   CLEAR_BIT(RCC->APB2SMENR, RCC_APB2SMENR_DFSDM1SMEN)
#endif                     

#if defined(LTDC)
#define __HAL_RCC_LTDC_CLK_SLEEP_DISABLE()     CLEAR_BIT(RCC->APB2SMENR, RCC_APB2SMENR_LTDCSMEN)
#endif           

#if defined(DSI)
#define __HAL_RCC_DSI_CLK_SLEEP_DISABLE()      CLEAR_BIT(RCC->APB2SMENR, RCC_APB2SMENR_DSISMEN)
#endif          

   
      
    

                                                                                                               
                                                                                                    
                                                                               
                              
                                                                                
                                                                            
      
    

#define __HAL_RCC_DMA1_IS_CLK_SLEEP_ENABLED()    (READ_BIT(RCC->AHB1SMENR, RCC_AHB1SMENR_DMA1SMEN) != 0U)

#define __HAL_RCC_DMA2_IS_CLK_SLEEP_ENABLED()    (READ_BIT(RCC->AHB1SMENR, RCC_AHB1SMENR_DMA2SMEN) != 0U)

#if defined(DMAMUX1)
#define __HAL_RCC_DMAMUX1_IS_CLK_SLEEP_ENABLED() (READ_BIT(RCC->AHB1SMENR, RCC_AHB1SMENR_DMAMUX1SMEN) != 0U)
#endif              

#define __HAL_RCC_FLASH_IS_CLK_SLEEP_ENABLED()   (READ_BIT(RCC->AHB1SMENR, RCC_AHB1SMENR_FLASHSMEN) != 0U)

#define __HAL_RCC_SRAM1_IS_CLK_SLEEP_ENABLED()   (READ_BIT(RCC->AHB1SMENR, RCC_AHB1SMENR_SRAM1SMEN) != 0U)

#define __HAL_RCC_CRC_IS_CLK_SLEEP_ENABLED()     (READ_BIT(RCC->AHB1SMENR, RCC_AHB1SMENR_CRCSMEN) != 0U)

#define __HAL_RCC_TSC_IS_CLK_SLEEP_ENABLED()     (READ_BIT(RCC->AHB1SMENR, RCC_AHB1SMENR_TSCSMEN) != 0U)

#if defined(DMA2D)
#define __HAL_RCC_DMA2D_IS_CLK_SLEEP_ENABLED()   (READ_BIT(RCC->AHB1SMENR, RCC_AHB1SMENR_DMA2DSMEN) != 0U)
#endif            

#if defined(GFXMMU)
#define __HAL_RCC_GFXMMU_IS_CLK_SLEEP_ENABLED()  (READ_BIT(RCC->AHB1SMENR, RCC_AHB1SMENR_GFXMMUSMEN) != 0U)
#endif             


#define __HAL_RCC_DMA1_IS_CLK_SLEEP_DISABLED()   (READ_BIT(RCC->AHB1SMENR, RCC_AHB1SMENR_DMA1SMEN) == 0U)

#define __HAL_RCC_DMA2_IS_CLK_SLEEP_DISABLED()   (READ_BIT(RCC->AHB1SMENR, RCC_AHB1SMENR_DMA2SMEN) == 0U)

#if defined(DMAMUX1)
#define __HAL_RCC_DMAMUX1_IS_CLK_SLEEP_DISABLED() (READ_BIT(RCC->AHB1SMENR, RCC_AHB1SMENR_DMAMUX1SMEN) == 0U)
#endif              

#define __HAL_RCC_FLASH_IS_CLK_SLEEP_DISABLED()  (READ_BIT(RCC->AHB1SMENR, RCC_AHB1SMENR_FLASHSMEN) == 0U)

#define __HAL_RCC_SRAM1_IS_CLK_SLEEP_DISABLED()  (READ_BIT(RCC->AHB1SMENR, RCC_AHB1SMENR_SRAM1SMEN) == 0U)

#define __HAL_RCC_CRC_IS_CLK_SLEEP_DISABLED()    (READ_BIT(RCC->AHB1SMENR, RCC_AHB1SMENR_CRCSMEN) == 0U)

#define __HAL_RCC_TSC_IS_CLK_SLEEP_DISABLED()    (READ_BIT(RCC->AHB1SMENR, RCC_AHB1SMENR_TSCSMEN) == 0U)

#if defined(DMA2D)
#define __HAL_RCC_DMA2D_IS_CLK_SLEEP_DISABLED()  (READ_BIT(RCC->AHB1SMENR, RCC_AHB1SMENR_DMA2DSMEN) == 0U)
#endif            

#if defined(GFXMMU)
#define __HAL_RCC_GFXMMU_IS_CLK_SLEEP_DISABLED() (READ_BIT(RCC->AHB1SMENR, RCC_AHB1SMENR_GFXMMUSMEN) == 0U)
#endif             

   
      
    

                                                                                                               
                                                                                                    
                                                                               
                              
                                                                                
                                                                            
      
    

#define __HAL_RCC_GPIOA_IS_CLK_SLEEP_ENABLED()   (READ_BIT(RCC->AHB2SMENR, RCC_AHB2SMENR_GPIOASMEN) != 0U)

#define __HAL_RCC_GPIOB_IS_CLK_SLEEP_ENABLED()   (READ_BIT(RCC->AHB2SMENR, RCC_AHB2SMENR_GPIOBSMEN) != 0U)

#define __HAL_RCC_GPIOC_IS_CLK_SLEEP_ENABLED()   (READ_BIT(RCC->AHB2SMENR, RCC_AHB2SMENR_GPIOCSMEN) != 0U)

#if defined(GPIOD)
#define __HAL_RCC_GPIOD_IS_CLK_SLEEP_ENABLED()   (READ_BIT(RCC->AHB2SMENR, RCC_AHB2SMENR_GPIODSMEN) != 0U)
#endif            

#if defined(GPIOE)
#define __HAL_RCC_GPIOE_IS_CLK_SLEEP_ENABLED()   (READ_BIT(RCC->AHB2SMENR, RCC_AHB2SMENR_GPIOESMEN) != 0U)
#endif            

#if defined(GPIOF)
#define __HAL_RCC_GPIOF_IS_CLK_SLEEP_ENABLED()   (READ_BIT(RCC->AHB2SMENR, RCC_AHB2SMENR_GPIOFSMEN) != 0U)
#endif            

#if defined(GPIOG)
#define __HAL_RCC_GPIOG_IS_CLK_SLEEP_ENABLED()   (READ_BIT(RCC->AHB2SMENR, RCC_AHB2SMENR_GPIOGSMEN) != 0U)
#endif            

#define __HAL_RCC_GPIOH_IS_CLK_SLEEP_ENABLED()   (READ_BIT(RCC->AHB2SMENR, RCC_AHB2SMENR_GPIOHSMEN) != 0U)

#if defined(GPIOI)
#define __HAL_RCC_GPIOI_IS_CLK_SLEEP_ENABLED()   (READ_BIT(RCC->AHB2SMENR, RCC_AHB2SMENR_GPIOISMEN) != 0U)
#endif            

#define __HAL_RCC_SRAM2_IS_CLK_SLEEP_ENABLED()   (READ_BIT(RCC->AHB2SMENR, RCC_AHB2SMENR_SRAM2SMEN) != 0U)

#if defined(SRAM3)
#define __HAL_RCC_SRAM3_IS_CLK_SLEEP_ENABLED()   (READ_BIT(RCC->AHB2SMENR, RCC_AHB2SMENR_SRAM3SMEN) != 0U)
#endif            

#if defined(USB_OTG_FS)
#define __HAL_RCC_USB_OTG_FS_IS_CLK_SLEEP_ENABLED()  (READ_BIT(RCC->AHB2SMENR, RCC_AHB2SMENR_OTGFSSMEN) != 0U)
#endif                 

#define __HAL_RCC_ADC_IS_CLK_SLEEP_ENABLED()     (READ_BIT(RCC->AHB2SMENR, RCC_AHB2SMENR_ADCSMEN) != 0U)

#if defined(DCMI)
#define __HAL_RCC_DCMI_IS_CLK_SLEEP_ENABLED()    (READ_BIT(RCC->AHB2SMENR, RCC_AHB2SMENR_DCMISMEN) != 0U)
#endif           

#if defined(PKA)
#define __HAL_RCC_PKA_IS_CLK_SLEEP_ENABLED()     (READ_BIT(RCC->AHB2SMENR, RCC_AHB2SMENR_PKASMEN) != 0U)
#endif          

#if defined(AES)
#define __HAL_RCC_AES_IS_CLK_SLEEP_ENABLED()     (READ_BIT(RCC->AHB2SMENR, RCC_AHB2SMENR_AESSMEN) != 0U)
#endif          

#if defined(HASH)
#define __HAL_RCC_HASH_IS_CLK_SLEEP_ENABLED()    (READ_BIT(RCC->AHB2SMENR, RCC_AHB2SMENR_HASHSMEN) != 0U)
#endif           

#define __HAL_RCC_RNG_IS_CLK_SLEEP_ENABLED()     (READ_BIT(RCC->AHB2SMENR, RCC_AHB2SMENR_RNGSMEN) != 0U)

#if defined(OCTOSPIM)
#define __HAL_RCC_OSPIM_IS_CLK_SLEEP_ENABLED()   (READ_BIT(RCC->AHB2SMENR, RCC_AHB2SMENR_OSPIMSMEN) != 0U)
#endif               

#if defined(SDMMC1) && defined(RCC_AHB2SMENR_SDMMC1SMEN)
#define __HAL_RCC_SDMMC1_IS_CLK_SLEEP_ENABLED()  (READ_BIT(RCC->AHB2SMENR, RCC_AHB2SMENR_SDMMC1SMEN) != 0U)
#endif                                         

#if defined(SDMMC2)
#define __HAL_RCC_SDMMC2_IS_CLK_SLEEP_ENABLED()  (READ_BIT(RCC->AHB2SMENR, RCC_AHB2SMENR_SDMMC2SMEN) != 0U)
#endif             


#define __HAL_RCC_GPIOA_IS_CLK_SLEEP_DISABLED()  (READ_BIT(RCC->AHB2SMENR, RCC_AHB2SMENR_GPIOASMEN) == 0U)

#define __HAL_RCC_GPIOB_IS_CLK_SLEEP_DISABLED()  (READ_BIT(RCC->AHB2SMENR, RCC_AHB2SMENR_GPIOBSMEN) == 0U)

#define __HAL_RCC_GPIOC_IS_CLK_SLEEP_DISABLED()  (READ_BIT(RCC->AHB2SMENR, RCC_AHB2SMENR_GPIOCSMEN) == 0U)

#if defined(GPIOD)
#define __HAL_RCC_GPIOD_IS_CLK_SLEEP_DISABLED()  (READ_BIT(RCC->AHB2SMENR, RCC_AHB2SMENR_GPIODSMEN) == 0U)
#endif            

#if defined(GPIOE)
#define __HAL_RCC_GPIOE_IS_CLK_SLEEP_DISABLED()  (READ_BIT(RCC->AHB2SMENR, RCC_AHB2SMENR_GPIOESMEN) == 0U)
#endif            

#if defined(GPIOF)
#define __HAL_RCC_GPIOF_IS_CLK_SLEEP_DISABLED()  (READ_BIT(RCC->AHB2SMENR, RCC_AHB2SMENR_GPIOFSMEN) == 0U)
#endif            

#if defined(GPIOG)
#define __HAL_RCC_GPIOG_IS_CLK_SLEEP_DISABLED()  (READ_BIT(RCC->AHB2SMENR, RCC_AHB2SMENR_GPIOGSMEN) == 0U)
#endif            

#define __HAL_RCC_GPIOH_IS_CLK_SLEEP_DISABLED()  (READ_BIT(RCC->AHB2SMENR, RCC_AHB2SMENR_GPIOHSMEN) == 0U)

#if defined(GPIOI)
#define __HAL_RCC_GPIOI_IS_CLK_SLEEP_DISABLED()  (READ_BIT(RCC->AHB2SMENR, RCC_AHB2SMENR_GPIOISMEN) == 0U)
#endif            

#define __HAL_RCC_SRAM2_IS_CLK_SLEEP_DISABLED()  (READ_BIT(RCC->AHB2SMENR, RCC_AHB2SMENR_SRAM2SMEN) == 0U)

#if defined(SRAM3)
#define __HAL_RCC_SRAM3_IS_CLK_SLEEP_DISABLED()  (READ_BIT(RCC->AHB2SMENR, RCC_AHB2SMENR_SRAM3SMEN) == 0U)
#endif            

#if defined(USB_OTG_FS)
#define __HAL_RCC_USB_OTG_FS_IS_CLK_SLEEP_DISABLED() (READ_BIT(RCC->AHB2SMENR, RCC_AHB2SMENR_OTGFSSMEN) == 0U)
#endif                 

#define __HAL_RCC_ADC_IS_CLK_SLEEP_DISABLED()    (READ_BIT(RCC->AHB2SMENR, RCC_AHB2SMENR_ADCSMEN) == 0U)

#if defined(DCMI)
#define __HAL_RCC_DCMI_IS_CLK_SLEEP_DISABLED()   (READ_BIT(RCC->AHB2SMENR, RCC_AHB2SMENR_DCMISMEN) == 0U)
#endif           

#if defined(PKA)
#define __HAL_RCC_PKA_IS_CLK_SLEEP_DISABLED()    (READ_BIT(RCC->AHB2SMENR, RCC_AHB2SMENR_PKASMEN) == 0U)
#endif          

#if defined(AES)
#define __HAL_RCC_AES_IS_CLK_SLEEP_DISABLED()    (READ_BIT(RCC->AHB2SMENR, RCC_AHB2SMENR_AESSMEN) == 0U)
#endif          

#if defined(HASH)
#define __HAL_RCC_HASH_IS_CLK_SLEEP_DISABLED()   (READ_BIT(RCC->AHB2SMENR, RCC_AHB2SMENR_HASHSMEN) == 0U)
#endif           

#define __HAL_RCC_RNG_IS_CLK_SLEEP_DISABLED()    (READ_BIT(RCC->AHB2SMENR, RCC_AHB2SMENR_RNGSMEN) == 0U)

#if defined(OCTOSPIM)
#define __HAL_RCC_OSPIM_IS_CLK_SLEEP_DISABLED()  (READ_BIT(RCC->AHB2SMENR, RCC_AHB2SMENR_OSPIMSMEN) == 0U)
#endif               

#if defined(SDMMC1) && defined(RCC_AHB2SMENR_SDMMC1SMEN)
#define __HAL_RCC_SDMMC1_IS_CLK_SLEEP_DISABLED() (READ_BIT(RCC->AHB2SMENR, RCC_AHB2SMENR_SDMMC1SMEN) == 0U)
#endif                                         

#if defined(SDMMC2)
#define __HAL_RCC_SDMMC2_IS_CLK_SLEEP_DISABLED() (READ_BIT(RCC->AHB2SMENR, RCC_AHB2SMENR_SDMMC2SMEN) == 0U)
#endif             

   
      
    

                                                                                                               
                                                                                                    
                                                                               
                              
                                                                                
                                                                            
      
    

#if defined(QUADSPI)
#define __HAL_RCC_QSPI_IS_CLK_SLEEP_ENABLED()    (READ_BIT(RCC->AHB3SMENR, RCC_AHB3SMENR_QSPISMEN) != 0U)
#endif              

#if defined(OCTOSPI1)
#define __HAL_RCC_OSPI1_IS_CLK_SLEEP_ENABLED()   (READ_BIT(RCC->AHB3SMENR, RCC_AHB3SMENR_OSPI1SMEN) != 0U)
#endif               

#if defined(OCTOSPI2)
#define __HAL_RCC_OSPI2_IS_CLK_SLEEP_ENABLED()   (READ_BIT(RCC->AHB3SMENR, RCC_AHB3SMENR_OSPI2SMEN) != 0U)
#endif               

#if defined(FMC_BANK1)
#define __HAL_RCC_FMC_IS_CLK_SLEEP_ENABLED()     (READ_BIT(RCC->AHB3SMENR, RCC_AHB3SMENR_FMCSMEN) != 0U)
#endif                


#if defined(QUADSPI)
#define __HAL_RCC_QSPI_IS_CLK_SLEEP_DISABLED()   (READ_BIT(RCC->AHB3SMENR, RCC_AHB3SMENR_QSPISMEN) == 0U)
#endif              

#if defined(OCTOSPI1)
#define __HAL_RCC_OSPI1_IS_CLK_SLEEP_DISABLED()  (READ_BIT(RCC->AHB3SMENR, RCC_AHB3SMENR_OSPI1SMEN) == 0U)
#endif               

#if defined(OCTOSPI2)
#define __HAL_RCC_OSPI2_IS_CLK_SLEEP_DISABLED()  (READ_BIT(RCC->AHB3SMENR, RCC_AHB3SMENR_OSPI2SMEN) == 0U)
#endif               

#if defined(FMC_BANK1)
#define __HAL_RCC_FMC_IS_CLK_SLEEP_DISABLED()    (READ_BIT(RCC->AHB3SMENR, RCC_AHB3SMENR_FMCSMEN) == 0U)
#endif                

   
      
    

                                                                                                               
                                                                                                    
                                                                               
                              
                                                                                
                                                                            
      
    

#define __HAL_RCC_TIM2_IS_CLK_SLEEP_ENABLED()      (READ_BIT(RCC->APB1SMENR1, RCC_APB1SMENR1_TIM2SMEN) != 0U)

#if defined(TIM3)
#define __HAL_RCC_TIM3_IS_CLK_SLEEP_ENABLED()      (READ_BIT(RCC->APB1SMENR1, RCC_APB1SMENR1_TIM3SMEN) != 0U)
#endif           

#if defined(TIM4)
#define __HAL_RCC_TIM4_IS_CLK_SLEEP_ENABLED()      (READ_BIT(RCC->APB1SMENR1, RCC_APB1SMENR1_TIM4SMEN) != 0U)
#endif           

#if defined(TIM5)
#define __HAL_RCC_TIM5_IS_CLK_SLEEP_ENABLED()      (READ_BIT(RCC->APB1SMENR1, RCC_APB1SMENR1_TIM5SMEN) != 0U)
#endif           

#define __HAL_RCC_TIM6_IS_CLK_SLEEP_ENABLED()      (READ_BIT(RCC->APB1SMENR1, RCC_APB1SMENR1_TIM6SMEN) != 0U)

#if defined(TIM7)
#define __HAL_RCC_TIM7_IS_CLK_SLEEP_ENABLED()      (READ_BIT(RCC->APB1SMENR1, RCC_APB1SMENR1_TIM7SMEN) != 0U)
#endif           

#if defined(LCD)
#define __HAL_RCC_LCD_IS_CLK_SLEEP_ENABLED()       (READ_BIT(RCC->APB1SMENR1, RCC_APB1SMENR1_LCDSMEN) != 0U)
#endif          

#if defined(RCC_APB1SMENR1_RTCAPBSMEN)
#define __HAL_RCC_RTCAPB_IS_CLK_SLEEP_ENABLED()    (READ_BIT(RCC->APB1SMENR1, RCC_APB1SMENR1_RTCAPBSMEN) != 0U)
#endif                                

#define __HAL_RCC_WWDG_IS_CLK_SLEEP_ENABLED()      (READ_BIT(RCC->APB1SMENR1, RCC_APB1SMENR1_WWDGSMEN) != 0U)

#if defined(SPI2)
#define __HAL_RCC_SPI2_IS_CLK_SLEEP_ENABLED()      (READ_BIT(RCC->APB1SMENR1, RCC_APB1SMENR1_SPI2SMEN) != 0U)
#endif           

#if defined(SPI3)
#define __HAL_RCC_SPI3_IS_CLK_SLEEP_ENABLED()      (READ_BIT(RCC->APB1SMENR1, RCC_APB1SMENR1_SPI3SMEN) != 0U)
#endif           

#define __HAL_RCC_USART2_IS_CLK_SLEEP_ENABLED()    (READ_BIT(RCC->APB1SMENR1, RCC_APB1SMENR1_USART2SMEN) != 0U)

#if defined(USART3)
#define __HAL_RCC_USART3_IS_CLK_SLEEP_ENABLED()    (READ_BIT(RCC->APB1SMENR1, RCC_APB1SMENR1_USART3SMEN) != 0U)
#endif             

#if defined(UART4)
#define __HAL_RCC_UART4_IS_CLK_SLEEP_ENABLED()     (READ_BIT(RCC->APB1SMENR1, RCC_APB1SMENR1_UART4SMEN) != 0U)
#endif            

#if defined(UART5)
#define __HAL_RCC_UART5_IS_CLK_SLEEP_ENABLED()     (READ_BIT(RCC->APB1SMENR1, RCC_APB1SMENR1_UART5SMEN) != 0U)
#endif            

#define __HAL_RCC_I2C1_IS_CLK_SLEEP_ENABLED()      (READ_BIT(RCC->APB1SMENR1, RCC_APB1SMENR1_I2C1SMEN) != 0U)

#if defined(I2C2)
#define __HAL_RCC_I2C2_IS_CLK_SLEEP_ENABLED()      (READ_BIT(RCC->APB1SMENR1, RCC_APB1SMENR1_I2C2SMEN) != 0U)
#endif           

#define __HAL_RCC_I2C3_IS_CLK_SLEEP_ENABLED()      (READ_BIT(RCC->APB1SMENR1, RCC_APB1SMENR1_I2C3SMEN) != 0U)

#if defined(I2C4)
#define __HAL_RCC_I2C4_IS_CLK_SLEEP_ENABLED()      (READ_BIT(RCC->APB1SMENR2, RCC_APB1SMENR2_I2C4SMEN) != 0U)
#endif           

#if defined(CRS)
#define __HAL_RCC_CRS_IS_CLK_SLEEP_ENABLED()       (READ_BIT(RCC->APB1SMENR1, RCC_APB1SMENR1_CRSSMEN) != 0U)
#endif          

#if defined(CAN1)
#define __HAL_RCC_CAN1_IS_CLK_SLEEP_ENABLED()      (READ_BIT(RCC->APB1SMENR1, RCC_APB1SMENR1_CAN1SMEN) != 0U)
#endif           

#if defined(CAN2)
#define __HAL_RCC_CAN2_IS_CLK_SLEEP_ENABLED()      (READ_BIT(RCC->APB1SMENR1, RCC_APB1SMENR1_CAN2SMEN) != 0U)
#endif           

#if defined(USB)
#define __HAL_RCC_USB_IS_CLK_SLEEP_ENABLED()       (READ_BIT(RCC->APB1SMENR1, RCC_APB1SMENR1_USBFSSMEN) != 0U)
#endif          

#define __HAL_RCC_PWR_IS_CLK_SLEEP_ENABLED()       (READ_BIT(RCC->APB1SMENR1, RCC_APB1SMENR1_PWRSMEN) != 0U)

#if defined(DAC1)
#define __HAL_RCC_DAC1_IS_CLK_SLEEP_ENABLED()      (READ_BIT(RCC->APB1SMENR1, RCC_APB1SMENR1_DAC1SMEN) != 0U)
#endif           

#define __HAL_RCC_OPAMP_IS_CLK_SLEEP_ENABLED()     (READ_BIT(RCC->APB1SMENR1, RCC_APB1SMENR1_OPAMPSMEN) != 0U)

#define __HAL_RCC_LPTIM1_IS_CLK_SLEEP_ENABLED()    (READ_BIT(RCC->APB1SMENR1, RCC_APB1SMENR1_LPTIM1SMEN) != 0U)

#define __HAL_RCC_LPUART1_IS_CLK_SLEEP_ENABLED()   (READ_BIT(RCC->APB1SMENR2, RCC_APB1SMENR2_LPUART1SMEN) != 0U)

#if defined(SWPMI1)
#define __HAL_RCC_SWPMI1_IS_CLK_SLEEP_ENABLED()    (READ_BIT(RCC->APB1SMENR2, RCC_APB1SMENR2_SWPMI1SMEN) != 0U)
#endif             

#define __HAL_RCC_LPTIM2_IS_CLK_SLEEP_ENABLED()    (READ_BIT(RCC->APB1SMENR2, RCC_APB1SMENR2_LPTIM2SMEN) != 0U)


#define __HAL_RCC_TIM2_IS_CLK_SLEEP_DISABLED()     (READ_BIT(RCC->APB1SMENR1, RCC_APB1SMENR1_TIM2SMEN) == 0U)

#if defined(TIM3)
#define __HAL_RCC_TIM3_IS_CLK_SLEEP_DISABLED()     (READ_BIT(RCC->APB1SMENR1, RCC_APB1SMENR1_TIM3SMEN) == 0U)
#endif           

#if defined(TIM4)
#define __HAL_RCC_TIM4_IS_CLK_SLEEP_DISABLED()     (READ_BIT(RCC->APB1SMENR1, RCC_APB1SMENR1_TIM4SMEN) == 0U)
#endif           

#if defined(TIM5)
#define __HAL_RCC_TIM5_IS_CLK_SLEEP_DISABLED()     (READ_BIT(RCC->APB1SMENR1, RCC_APB1SMENR1_TIM5SMEN) == 0U)
#endif           

#define __HAL_RCC_TIM6_IS_CLK_SLEEP_DISABLED()     (READ_BIT(RCC->APB1SMENR1, RCC_APB1SMENR1_TIM6SMEN) == 0U)

#if defined(TIM7)
#define __HAL_RCC_TIM7_IS_CLK_SLEEP_DISABLED()     (READ_BIT(RCC->APB1SMENR1, RCC_APB1SMENR1_TIM7SMEN) == 0U)
#endif           

#if defined(LCD)
#define __HAL_RCC_LCD_IS_CLK_SLEEP_DISABLED()      (READ_BIT(RCC->APB1SMENR1, RCC_APB1SMENR1_LCDSMEN) == 0U)
#endif          

#if defined(RCC_APB1SMENR1_RTCAPBSMEN)
#define __HAL_RCC_RTCAPB_IS_CLK_SLEEP_DISABLED()   (READ_BIT(RCC->APB1SMENR1, RCC_APB1SMENR1_RTCAPBSMEN) == 0U)
#endif                                

#define __HAL_RCC_WWDG_IS_CLK_SLEEP_DISABLED()     (READ_BIT(RCC->APB1SMENR1, RCC_APB1SMENR1_WWDGSMEN) == 0U)

#if defined(SPI2)
#define __HAL_RCC_SPI2_IS_CLK_SLEEP_DISABLED()     (READ_BIT(RCC->APB1SMENR1, RCC_APB1SMENR1_SPI2SMEN) == 0U)
#endif           

#if defined(SPI3)
#define __HAL_RCC_SPI3_IS_CLK_SLEEP_DISABLED()     (READ_BIT(RCC->APB1SMENR1, RCC_APB1SMENR1_SPI3SMEN) == 0U)
#endif           

#define __HAL_RCC_USART2_IS_CLK_SLEEP_DISABLED()   (READ_BIT(RCC->APB1SMENR1, RCC_APB1SMENR1_USART2SMEN) == 0U)

#if defined(USART3)
#define __HAL_RCC_USART3_IS_CLK_SLEEP_DISABLED()   (READ_BIT(RCC->APB1SMENR1, RCC_APB1SMENR1_USART3SMEN) == 0U)
#endif             

#if defined(UART4)
#define __HAL_RCC_UART4_IS_CLK_SLEEP_DISABLED()    (READ_BIT(RCC->APB1SMENR1, RCC_APB1SMENR1_UART4SMEN) == 0U)
#endif            

#if defined(UART5)
#define __HAL_RCC_UART5_IS_CLK_SLEEP_DISABLED()    (READ_BIT(RCC->APB1SMENR1, RCC_APB1SMENR1_UART5SMEN) == 0U)
#endif            

#define __HAL_RCC_I2C1_IS_CLK_SLEEP_DISABLED()     (READ_BIT(RCC->APB1SMENR1, RCC_APB1SMENR1_I2C1SMEN) == 0U)

#if defined(I2C2)
#define __HAL_RCC_I2C2_IS_CLK_SLEEP_DISABLED()     (READ_BIT(RCC->APB1SMENR1, RCC_APB1SMENR1_I2C2SMEN) == 0U)
#endif           

#define __HAL_RCC_I2C3_IS_CLK_SLEEP_DISABLED()     (READ_BIT(RCC->APB1SMENR1, RCC_APB1SMENR1_I2C3SMEN) == 0U)

#if defined(I2C4)
#define __HAL_RCC_I2C4_IS_CLK_SLEEP_DISABLED()     (READ_BIT(RCC->APB1SMENR2, RCC_APB1SMENR2_I2C4SMEN) == 0U)
#endif           

#if defined(CRS)
#define __HAL_RCC_CRS_IS_CLK_SLEEP_DISABLED()      (READ_BIT(RCC->APB1SMENR1, RCC_APB1SMENR1_CRSSMEN) == 0U)
#endif          

#if defined(CAN1)
#define __HAL_RCC_CAN1_IS_CLK_SLEEP_DISABLED()     (READ_BIT(RCC->APB1SMENR1, RCC_APB1SMENR1_CAN1SMEN) == 0U)
#endif           

#if defined(CAN2)
#define __HAL_RCC_CAN2_IS_CLK_SLEEP_DISABLED()     (READ_BIT(RCC->APB1SMENR1, RCC_APB1SMENR1_CAN2SMEN) == 0U)
#endif           

#if defined(USB)
#define __HAL_RCC_USB_IS_CLK_SLEEP_DISABLED()      (READ_BIT(RCC->APB1SMENR1, RCC_APB1SMENR1_USBFSSMEN) == 0U)
#endif          

#define __HAL_RCC_PWR_IS_CLK_SLEEP_DISABLED()      (READ_BIT(RCC->APB1SMENR1, RCC_APB1SMENR1_PWRSMEN) == 0U)

#if defined(DAC1)
#define __HAL_RCC_DAC1_IS_CLK_SLEEP_DISABLED()     (READ_BIT(RCC->APB1SMENR1, RCC_APB1SMENR1_DAC1SMEN) == 0U)
#endif           

#define __HAL_RCC_OPAMP_IS_CLK_SLEEP_DISABLED()    (READ_BIT(RCC->APB1SMENR1, RCC_APB1SMENR1_OPAMPSMEN) == 0U)

#define __HAL_RCC_LPTIM1_IS_CLK_SLEEP_DISABLED()   (READ_BIT(RCC->APB1SMENR1, RCC_APB1SMENR1_LPTIM1SMEN) == 0U)

#define __HAL_RCC_LPUART1_IS_CLK_SLEEP_DISABLED()  (READ_BIT(RCC->APB1SMENR2, RCC_APB1SMENR2_LPUART1SMEN) == 0U)

#if defined(SWPMI1)
#define __HAL_RCC_SWPMI1_IS_CLK_SLEEP_DISABLED()   (READ_BIT(RCC->APB1SMENR2, RCC_APB1SMENR2_SWPMI1SMEN) == 0U)
#endif             

#define __HAL_RCC_LPTIM2_IS_CLK_SLEEP_DISABLED()   (READ_BIT(RCC->APB1SMENR2, RCC_APB1SMENR2_LPTIM2SMEN) == 0U)

   
      
    

                                                                                                               
                                                                                                    
                                                                               
                              
                                                                                
                                                                            
      
    

#define __HAL_RCC_SYSCFG_IS_CLK_SLEEP_ENABLED()    (READ_BIT(RCC->APB2SMENR, RCC_APB2SMENR_SYSCFGSMEN) != 0U)

#if defined(SDMMC1) && defined(RCC_APB2SMENR_SDMMC1SMEN)
#define __HAL_RCC_SDMMC1_IS_CLK_SLEEP_ENABLED()    (READ_BIT(RCC->APB2SMENR, RCC_APB2SMENR_SDMMC1SMEN) != 0U)
#endif                                         

#define __HAL_RCC_TIM1_IS_CLK_SLEEP_ENABLED()      (READ_BIT(RCC->APB2SMENR, RCC_APB2SMENR_TIM1SMEN) != 0U)

#define __HAL_RCC_SPI1_IS_CLK_SLEEP_ENABLED()      (READ_BIT(RCC->APB2SMENR, RCC_APB2SMENR_SPI1SMEN) != 0U)

#if defined(TIM8)
#define __HAL_RCC_TIM8_IS_CLK_SLEEP_ENABLED()      (READ_BIT(RCC->APB2SMENR, RCC_APB2SMENR_TIM8SMEN) != 0U)
#endif           

#define __HAL_RCC_USART1_IS_CLK_SLEEP_ENABLED()    (READ_BIT(RCC->APB2SMENR, RCC_APB2SMENR_USART1SMEN) != 0U)

#define __HAL_RCC_TIM15_IS_CLK_SLEEP_ENABLED()     (READ_BIT(RCC->APB2SMENR, RCC_APB2SMENR_TIM15SMEN) != 0U)

#define __HAL_RCC_TIM16_IS_CLK_SLEEP_ENABLED()     (READ_BIT(RCC->APB2SMENR, RCC_APB2SMENR_TIM16SMEN) != 0U)

#if defined(TIM17)
#define __HAL_RCC_TIM17_IS_CLK_SLEEP_ENABLED()     (READ_BIT(RCC->APB2SMENR, RCC_APB2SMENR_TIM17SMEN) != 0U)
#endif            

#if defined(SAI1)
#define __HAL_RCC_SAI1_IS_CLK_SLEEP_ENABLED()      (READ_BIT(RCC->APB2SMENR, RCC_APB2SMENR_SAI1SMEN) != 0U)
#endif           

#if defined(SAI2)
#define __HAL_RCC_SAI2_IS_CLK_SLEEP_ENABLED()      (READ_BIT(RCC->APB2SMENR, RCC_APB2SMENR_SAI2SMEN) != 0U)
#endif           

#if defined(DFSDM1_Filter0)
#define __HAL_RCC_DFSDM1_IS_CLK_SLEEP_ENABLED()    (READ_BIT(RCC->APB2SMENR, RCC_APB2SMENR_DFSDM1SMEN) != 0U)
#endif                     

#if defined(LTDC)
#define __HAL_RCC_LTDC_IS_CLK_SLEEP_ENABLED()      (READ_BIT(RCC->APB2SMENR, RCC_APB2SMENR_LTDCSMEN) != 0U)
#endif           

#if defined(DSI)
#define __HAL_RCC_DSI_IS_CLK_SLEEP_ENABLED()       (READ_BIT(RCC->APB2SMENR, RCC_APB2SMENR_DSISMEN) != 0U)
#endif          


#define __HAL_RCC_SYSCFG_IS_CLK_SLEEP_DISABLED()   (READ_BIT(RCC->APB2SMENR, RCC_APB2SMENR_SYSCFGSMEN) == 0U)

#if defined(SDMMC1) && defined(RCC_APB2SMENR_SDMMC1SMEN)
#define __HAL_RCC_SDMMC1_IS_CLK_SLEEP_DISABLED()   (READ_BIT(RCC->APB2SMENR, RCC_APB2SMENR_SDMMC1SMEN) == 0U)
#endif                                         

#define __HAL_RCC_TIM1_IS_CLK_SLEEP_DISABLED()     (READ_BIT(RCC->APB2SMENR, RCC_APB2SMENR_TIM1SMEN) == 0U)

#define __HAL_RCC_SPI1_IS_CLK_SLEEP_DISABLED()     (READ_BIT(RCC->APB2SMENR, RCC_APB2SMENR_SPI1SMEN) == 0U)

#if defined(TIM8)
#define __HAL_RCC_TIM8_IS_CLK_SLEEP_DISABLED()     (READ_BIT(RCC->APB2SMENR, RCC_APB2SMENR_TIM8SMEN) == 0U)
#endif           

#define __HAL_RCC_USART1_IS_CLK_SLEEP_DISABLED()   (READ_BIT(RCC->APB2SMENR, RCC_APB2SMENR_USART1SMEN) == 0U)

#define __HAL_RCC_TIM15_IS_CLK_SLEEP_DISABLED()    (READ_BIT(RCC->APB2SMENR, RCC_APB2SMENR_TIM15SMEN) == 0U)

#define __HAL_RCC_TIM16_IS_CLK_SLEEP_DISABLED()    (READ_BIT(RCC->APB2SMENR, RCC_APB2SMENR_TIM16SMEN) == 0U)

#if defined(TIM17)
#define __HAL_RCC_TIM17_IS_CLK_SLEEP_DISABLED()    (READ_BIT(RCC->APB2SMENR, RCC_APB2SMENR_TIM17SMEN) == 0U)
#endif            

#if defined(SAI1)
#define __HAL_RCC_SAI1_IS_CLK_SLEEP_DISABLED()     (READ_BIT(RCC->APB2SMENR, RCC_APB2SMENR_SAI1SMEN) == 0U)
#endif           

#if defined(SAI2)
#define __HAL_RCC_SAI2_IS_CLK_SLEEP_DISABLED()     (READ_BIT(RCC->APB2SMENR, RCC_APB2SMENR_SAI2SMEN) == 0U)
#endif           

#if defined(DFSDM1_Filter0)
#define __HAL_RCC_DFSDM1_IS_CLK_SLEEP_DISABLED()   (READ_BIT(RCC->APB2SMENR, RCC_APB2SMENR_DFSDM1SMEN) == 0U)
#endif                     

#if defined(LTDC)
#define __HAL_RCC_LTDC_IS_CLK_SLEEP_DISABLED()     (READ_BIT(RCC->APB2SMENR, RCC_APB2SMENR_LTDCSMEN) == 0U)
#endif           

#if defined(DSI)
#define __HAL_RCC_DSI_IS_CLK_SLEEP_DISABLED()      (READ_BIT(RCC->APB2SMENR, RCC_APB2SMENR_DSISMEN) == 0U)
#endif          

   
      
    

                                                             
      
    

                                                               
                                                                                    
                                                                   
                                                      
                
    
#define __HAL_RCC_BACKUPRESET_FORCE()   SET_BIT(RCC->BDCR, RCC_BDCR_BDRST)

#define __HAL_RCC_BACKUPRESET_RELEASE() CLEAR_BIT(RCC->BDCR, RCC_BDCR_BDRST)

   
      
    

                                                                     
      
    

                                                      
                                                                            
                                                                          
                                                                           
                                          
                                                                              
                
    
#define __HAL_RCC_RTC_ENABLE()         SET_BIT(RCC->BDCR, RCC_BDCR_RTCEN)

#define __HAL_RCC_RTC_DISABLE()        CLEAR_BIT(RCC->BDCR, RCC_BDCR_RTCEN)

   
      
    

                                                                                       
                                                                                
                                                                                 
                                                                                
                                                                                
                                            
                                                                                      
                                                                                    
                                                                                  
                                                                                 
                                
                                                     
                                                                                
                         
                
    
#define __HAL_RCC_HSI_ENABLE()  SET_BIT(RCC->CR, RCC_CR_HSION)

#define __HAL_RCC_HSI_DISABLE() CLEAR_BIT(RCC->CR, RCC_CR_HSION)

                                                                                             
                                                                               
                                                                                
                                                                            
                                                    
                                                                                                       
                                                  
                
    
#define __HAL_RCC_HSI_CALIBRATIONVALUE_ADJUST(__HSICALIBRATIONVALUE__) \
                  MODIFY_REG(RCC->ICSCR, RCC_ICSCR_HSITRIM, (__HSICALIBRATIONVALUE__) << RCC_ICSCR_HSITRIM_Pos)

   
                                                                                             
                                                                                             
                                                                          
                                                       
                
    
#define __HAL_RCC_HSIAUTOMATIC_START_ENABLE()   SET_BIT(RCC->CR, RCC_CR_HSIASFS)

#define __HAL_RCC_HSIAUTOMATIC_START_DISABLE()  CLEAR_BIT(RCC->CR, RCC_CR_HSIASFS)

   
                                                                                               
                                                                                       
                                                                                            
                                                    
                                                                          
                                                       
                
    
#define __HAL_RCC_HSISTOP_ENABLE()     SET_BIT(RCC->CR, RCC_CR_HSIKERON)

#define __HAL_RCC_HSISTOP_DISABLE()    CLEAR_BIT(RCC->CR, RCC_CR_HSIKERON)

   
                                                                                  
                                                                                  
                                                                           
                                                                               
                                                                               
                                                            
                                                                          
                                                                           
                                      
                                                                             
                                                                               
                                             
                                                                                
                         
                
    
#define __HAL_RCC_MSI_ENABLE()  SET_BIT(RCC->CR, RCC_CR_MSION)

#define __HAL_RCC_MSI_DISABLE() CLEAR_BIT(RCC->CR, RCC_CR_MSION)

                                                                                      
                                                                               
                                                                                
                                                                           
                              
                                                                            
                                                    
                                                              
                
    
#define __HAL_RCC_MSI_CALIBRATIONVALUE_ADJUST(__MSICALIBRATIONVALUE__) \
                  MODIFY_REG(RCC->ICSCR, RCC_ICSCR_MSITRIM, (__MSICALIBRATIONVALUE__) << RCC_ICSCR_MSITRIM_Pos)

   
                                                                                              
                                                                       
                                                                             
                                                                                   
                                                                                  
                                
                                                                                     
                        
                                                                        
                                                            
                                                               
                                                                    
                                                                    
                                                                    
                                                                    
                                                                  
                                                                  
                                                                                        
                                                                  
                                                                   
                                                                   
                                                                    
                                                                    
                
    
#define __HAL_RCC_MSI_RANGE_CONFIG(__MSIRANGEVALUE__) \
                  do {                                                         \
                    SET_BIT(RCC->CR, RCC_CR_MSIRGSEL);                         \
                    MODIFY_REG(RCC->CR, RCC_CR_MSIRANGE, (__MSIRANGEVALUE__)); \
                  } while(0)

   
                                                                                                     
                                                                                                     
                                                            
                                                               
                                                                  
                                                                  
                                                                                        
                                                                  
                
    
#define __HAL_RCC_MSI_STANDBY_RANGE_CONFIG(__MSIRANGEVALUE__) \
                  MODIFY_REG(RCC->CSR, RCC_CSR_MSISRANGE, (__MSIRANGEVALUE__) << 4U)

                                                                                          
                            
                                                               
                                                                    
                                                                    
                                                                    
                                                                    
                                                                  
                                                                  
                                                                                        
                                                                  
                                                                   
                                                                   
                                                                    
                                                                    
    
#define __HAL_RCC_GET_MSI_RANGE()                                              \
                  ((READ_BIT(RCC->CR, RCC_CR_MSIRGSEL) != 0U) ?             \
                   READ_BIT(RCC->CR, RCC_CR_MSIRANGE) :                        \
                   (READ_BIT(RCC->CSR, RCC_CSR_MSISRANGE) >> 4U))

                                                                                
                                                                           
                                                                             
                                                     
                                                           
                                                                                
                         
                
    
#define __HAL_RCC_LSI_ENABLE()         SET_BIT(RCC->CSR, RCC_CSR_LSION)

#define __HAL_RCC_LSI_DISABLE()        CLEAR_BIT(RCC->CSR, RCC_CSR_LSION)

   
                                                                        
                                                                            
                                                                                
                                                
                                                                                  
                                                                                   
                                                                           
                                                                              
                                                                                
                                                                           
                                                                                
                                                                                   
                                                                                 
                     
                                                         
                                                              
                                                                                             
                                                               
                                                                
                                                                                     
                
    
#define __HAL_RCC_HSE_CONFIG(__STATE__)                      \
                    do {                                     \
                      if((__STATE__) == RCC_HSE_ON)          \
                      {                                      \
                        SET_BIT(RCC->CR, RCC_CR_HSEON);      \
                      }                                      \
                      else if((__STATE__) == RCC_HSE_BYPASS) \
                      {                                      \
                        SET_BIT(RCC->CR, RCC_CR_HSEBYP);     \
                        SET_BIT(RCC->CR, RCC_CR_HSEON);      \
                      }                                      \
                      else                                   \
                      {                                      \
                        CLEAR_BIT(RCC->CR, RCC_CR_HSEON);    \
                        CLEAR_BIT(RCC->CR, RCC_CR_HSEBYP);   \
                      }                                      \
                    } while(0)

   
                                                                       
                                                                             
                                                                                
                                                
                                                                            
                                                                          
                                                                           
                                          
                                                                                  
                                                                                   
                                                       
                                                         
                                                              
                                                                                             
                                                               
                                                                
                                                                                     
                
    
#define __HAL_RCC_LSE_CONFIG(__STATE__)                        \
                    do {                                       \
                      if((__STATE__) == RCC_LSE_ON)            \
                      {                                        \
                        SET_BIT(RCC->BDCR, RCC_BDCR_LSEON);    \
                      }                                        \
                      else if((__STATE__) == RCC_LSE_BYPASS)   \
                      {                                        \
                        SET_BIT(RCC->BDCR, RCC_BDCR_LSEBYP);   \
                        SET_BIT(RCC->BDCR, RCC_BDCR_LSEON);    \
                      }                                        \
                      else                                     \
                      {                                        \
                        CLEAR_BIT(RCC->BDCR, RCC_BDCR_LSEON);  \
                        CLEAR_BIT(RCC->BDCR, RCC_BDCR_LSEBYP); \
                      }                                        \
                    } while(0)

#if defined(RCC_HSI48_SUPPORT)

                                                                                         
                                                                                  
                                                                                      
                                                                 
                                                     
                
    
#define __HAL_RCC_HSI48_ENABLE()  SET_BIT(RCC->CRRCR, RCC_CRRCR_HSI48ON)

#define __HAL_RCC_HSI48_DISABLE() CLEAR_BIT(RCC->CRRCR, RCC_CRRCR_HSI48ON)

#endif                        

                                                       
                                                                                  
                                                                                 
                                                                          
                                                               
                                                                            
                                                                                   
                                   
   
                                                             
                                                              
                                                                               
                                                                         
                                                                         
                                                                                     
   
                                                                               
                                                                             
                                                                            
                                                     
                                                                                
                              
                
    
#define __HAL_RCC_RTC_CONFIG(__RTC_CLKSOURCE__)  \
                  MODIFY_REG( RCC->BDCR, RCC_BDCR_RTCSEL, (__RTC_CLKSOURCE__))


                                              
                                                           
                                                                               
                                                                         
                                                                         
                                                                                     
    
#define  __HAL_RCC_GET_RTC_SOURCE() (READ_BIT(RCC->BDCR, RCC_BDCR_RTCSEL))

                                                     
                                                                                
                                                                             
                                           
                                                                                 
                                                                                      
                
    
#define __HAL_RCC_PLL_ENABLE()         SET_BIT(RCC->CR, RCC_CR_PLLON)

#define __HAL_RCC_PLL_DISABLE()        CLEAR_BIT(RCC->CR, RCC_CR_PLLON)

                                                    
                                                                          
                                                               
                                                              
                                                                                 
                                                                                            
                                                                                            
                                                                                            
                                                                                             
                
   
    
#define __HAL_RCC_PLL_PLLSOURCE_CONFIG(__PLLSOURCE__) \
                  MODIFY_REG(RCC->PLLCFGR, RCC_PLLCFGR_PLLSRC, (__PLLSOURCE__))

                                                                
                                                                          
                                                                          
                                                                                                                  
                                                                                                   
                                                                                     
                                                                                      
                                          
                
   
    
#define __HAL_RCC_PLL_PLLM_CONFIG(__PLLM__) \
                  MODIFY_REG(RCC->PLLCFGR, RCC_PLLCFGR_PLLM, ((__PLLM__) - 1) << 4U)

   
                                                                                              
                                                                          
   
                                                               
                                                               
                                                                                 
                                                                                            
                                                                                            
                                                                                            
                                                                                             
   
                                                                           
                                                                                                                   
                                                                                                    
                                                                                     
                                                                                      
                                          
   
                                                                                  
                                                              
                                                                               
                                                       
   
                                                                                              
                                                                                           
                            
   
                                                                                     
                                                                
                                                                              
                                                                               
                                                                                     
                      
                                                                             
                                                                             
                                                                
                
    
#if defined(RCC_PLLP_DIV_2_31_SUPPORT)

#define __HAL_RCC_PLL_CONFIG(__PLLSOURCE__, __PLLM__, __PLLN__, __PLLP__, __PLLQ__,__PLLR__ ) \
                  MODIFY_REG(RCC->PLLCFGR, \
                             (RCC_PLLCFGR_PLLSRC | RCC_PLLCFGR_PLLM | RCC_PLLCFGR_PLLN | \
                              RCC_PLLCFGR_PLLQ | RCC_PLLCFGR_PLLR | RCC_PLLCFGR_PLLP | RCC_PLLCFGR_PLLPDIV), \
                             ((__PLLSOURCE__) | \
                              (((__PLLM__) - 1U) << RCC_PLLCFGR_PLLM_Pos) | \
                              ((__PLLN__) << RCC_PLLCFGR_PLLN_Pos) | \
                              ((((__PLLQ__) >> 1U) - 1U) << RCC_PLLCFGR_PLLQ_Pos) | \
                              ((((__PLLR__) >> 1U) - 1U) << RCC_PLLCFGR_PLLR_Pos) | \
                              ((uint32_t)(__PLLP__) << RCC_PLLCFGR_PLLPDIV_Pos)))

#elif defined(RCC_PLLP_SUPPORT)

#define __HAL_RCC_PLL_CONFIG(__PLLSOURCE__, __PLLM__, __PLLN__, __PLLP__, __PLLQ__,__PLLR__ ) \
                  MODIFY_REG(RCC->PLLCFGR, \
                             (RCC_PLLCFGR_PLLSRC | RCC_PLLCFGR_PLLM | RCC_PLLCFGR_PLLN | \
                              RCC_PLLCFGR_PLLQ | RCC_PLLCFGR_PLLR | RCC_PLLCFGR_PLLP), \
                             ((__PLLSOURCE__) | \
                              (((__PLLM__) - 1U) << RCC_PLLCFGR_PLLM_Pos) | \
                              ((__PLLN__) << RCC_PLLCFGR_PLLN_Pos) | \
                              ((((__PLLQ__) >> 1U) - 1U) << RCC_PLLCFGR_PLLQ_Pos) | \
                              ((((__PLLR__) >> 1U) - 1U) << RCC_PLLCFGR_PLLR_Pos) | \
                              (((__PLLP__) >> 4U) << RCC_PLLCFGR_PLLP_Pos)))

#else

#define __HAL_RCC_PLL_CONFIG(__PLLSOURCE__, __PLLM__, __PLLN__, __PLLQ__,__PLLR__ ) \
                  MODIFY_REG(RCC->PLLCFGR, \
                             (RCC_PLLCFGR_PLLSRC | RCC_PLLCFGR_PLLM | RCC_PLLCFGR_PLLN | \
                              RCC_PLLCFGR_PLLQ | RCC_PLLCFGR_PLLR), \
                             ((__PLLSOURCE__) | \
                              (((__PLLM__) - 1U) << RCC_PLLCFGR_PLLM_Pos) | \
                              ((__PLLN__) << RCC_PLLCFGR_PLLN_Pos) | \
                              ((((__PLLQ__) >> 1U) - 1U) << RCC_PLLCFGR_PLLQ_Pos) | \
                              ((((__PLLR__) >> 1U) - 1U) << RCC_PLLCFGR_PLLR_Pos)))

#endif                                

                                                                 
                                                                                  
                             
                                                                                 
                                                                                 
                                                                                 
                                                                                 
    
#define __HAL_RCC_GET_PLL_OSCSOURCE() (READ_BIT(RCC->PLLCFGR, RCC_PLLCFGR_PLLSRC))

   
                                                                                                  
                                                                                                       
                                                                                              
                                               
                                                                 
                                                                                
                                                                                                     
                                                                                              
                                                                                                               
                                                                                                        
                                                                                                                 
                
    
#define __HAL_RCC_PLLCLKOUT_ENABLE(__PLLCLOCKOUT__)   SET_BIT(RCC->PLLCFGR, (__PLLCLOCKOUT__))

#define __HAL_RCC_PLLCLKOUT_DISABLE(__PLLCLOCKOUT__)  CLEAR_BIT(RCC->PLLCFGR, (__PLLCLOCKOUT__))

   
                                                                                             
                                                                         
                                                               
                                                                                                     
                                                                                              
                                                                                                               
                                                                                                        
                                                                                                                 
                       
    
#define __HAL_RCC_GET_PLLCLKOUT_CONFIG(__PLLCLOCKOUT__)  READ_BIT(RCC->PLLCFGR, (__PLLCLOCKOUT__))

   
                                                       
                                                               
                                                               
                                                                                       
                                                                                       
                                                                                       
                                                                                      
                
    
#define __HAL_RCC_SYSCLK_CONFIG(__SYSCLKSOURCE__) \
                  MODIFY_REG(RCC->CFGR, RCC_CFGR_SW, (__SYSCLKSOURCE__))

                                                               
                                                                                
                             
                                                                         
                                                                         
                                                                         
                                                                            
    
#define __HAL_RCC_GET_SYSCLK_SOURCE() (READ_BIT(RCC->CFGR, RCC_CFGR_SWS))

   
                                                                                        
                                                                            
                                                                          
                                                                           
                                          
                                                                             
                                                               
                                                                               
                                                                                            
                                                                                              
                                                                                 
                
    
#define __HAL_RCC_LSEDRIVE_CONFIG(__LSEDRIVE__) \
                  MODIFY_REG(RCC->BDCR, RCC_BDCR_LSEDRV, (__LSEDRIVE__))

   
                                                           
                                                                                  
                                                              
                                                                                      
                                                                                      
                
    
#define __HAL_RCC_WAKEUPSTOP_CLK_CONFIG(__STOPWUCLK__) \
                  MODIFY_REG(RCC->CFGR, RCC_CFGR_STOPWUCK, (__STOPWUCLK__))


                                             
                                                            
                                                               
                                                                    
                                                                                    
                                                                             
                                                                             
                                                                             
                                                                                     
                                                                             
                                                                             
                 
                                                                                                        
        
                 
                                                                                                        
        
                                                         
                                                               
                                                                        
                                                                        
                                                                        
                                                                        
                                                                         
    
#define __HAL_RCC_MCO1_CONFIG(__MCOCLKSOURCE__, __MCODIV__) \
                 MODIFY_REG(RCC->CFGR, (RCC_CFGR_MCOSEL | RCC_CFGR_MCOPRE), ((__MCOCLKSOURCE__) | (__MCODIV__)))

                                                                         
                                                                   
      
    

                                    
                                                                              
                                                                          
                                                           
                                                           
                                                           
                                                           
                                                           
                                                                
                                                                                            
                                                                                            
                                                                           
                 
                                                                                      
        
                 
                                                                                      
        
                
    
#define __HAL_RCC_ENABLE_IT(__INTERRUPT__) SET_BIT(RCC->CIER, (__INTERRUPT__))

                                    
                                                                               
                                                                          
                                                           
                                                           
                                                           
                                                           
                                                           
                                                                
                                                                                            
                                                                                            
                                                                           
                 
                                                                                      
        
                 
                                                                                      
        
                
    
#define __HAL_RCC_DISABLE_IT(__INTERRUPT__) CLEAR_BIT(RCC->CIER, (__INTERRUPT__))

                                                   
                                                                       
                                                                          
                                                           
                                                           
                                                           
                                                           
                                                           
                                                                
                                                                                            
                                                                                            
                                                                        
                                                                           
                 
                                                                                      
        
                 
                                                                                      
        
                
    
#define __HAL_RCC_CLEAR_IT(__INTERRUPT__) WRITE_REG(RCC->CICR, (__INTERRUPT__))

                                                                
                                                                      
                                                              
                                                           
                                                           
                                                           
                                                           
                                                           
                                                                
                                                                                            
                                                                                            
                                                                        
                                                                           
                 
                                                                                     
        
                 
                                                                                     
        
                                                           
    
#define __HAL_RCC_GET_IT(__INTERRUPT__) (READ_BIT(RCC->CIFR, (__INTERRUPT__)) == (__INTERRUPT__))

                                                 
                                                                                                   
                                                                                    
                
   
#define __HAL_RCC_CLEAR_RESET_FLAGS() SET_BIT(RCC->CSR, RCC_CSR_RMVF)

                                                              
                                                 
                                                              
                                                                    
                                                                    
                                                                    
                                                              
                                                                                          
                                                                                          
                 
                                                                                    
        
                 
                                                                                    
        
                                                                    
                                                                                                    
                                                                    
                                                   
                                                      
                                                   
                                                       
                                                        
                                                                     
                                                                
                                                          
                                                      
    
#if defined(RCC_HSI48_SUPPORT)
#define __HAL_RCC_GET_FLAG(__FLAG__) (((((((__FLAG__) >> 5U) == 1U) ? RCC->CR :                    \
                                        ((((__FLAG__) >> 5U) == 4U) ? RCC->CRRCR :                 \
                                        ((((__FLAG__) >> 5U) == 2U) ? RCC->BDCR :                  \
                                        ((((__FLAG__) >> 5U) == 3U) ? RCC->CSR : RCC->CIFR)))) &   \
                                          (1U << ((__FLAG__) & RCC_FLAG_MASK))) != 0U) ? 1U : 0U)
#else
#define __HAL_RCC_GET_FLAG(__FLAG__) (((((((__FLAG__) >> 5U) == 1U) ? RCC->CR :                    \
                                        ((((__FLAG__) >> 5U) == 2U) ? RCC->BDCR :                  \
                                        ((((__FLAG__) >> 5U) == 3U) ? RCC->CSR : RCC->CIFR))) &    \
                                          (1U << ((__FLAG__) & RCC_FLAG_MASK))) != 0U) ? 1U : 0U)
#endif                        

   
      
    

   
      
    

                                                                                
                                                         
      
    
                            
#define CR_REG_INDEX              1U
#define BDCR_REG_INDEX            2U
#define CSR_REG_INDEX             3U
#if defined(RCC_HSI48_SUPPORT)
#define CRRCR_REG_INDEX           4U
#endif                        

#define RCC_FLAG_MASK             0x1FU

                              
#if defined(RCC_HSI48_SUPPORT)
#define RCC_OSCILLATORTYPE_ALL          (RCC_OSCILLATORTYPE_HSE | RCC_OSCILLATORTYPE_HSI | RCC_OSCILLATORTYPE_HSI48 | RCC_OSCILLATORTYPE_MSI | RCC_OSCILLATORTYPE_LSI | RCC_OSCILLATORTYPE_LSE)                                     
#else
#define RCC_OSCILLATORTYPE_ALL          (RCC_OSCILLATORTYPE_HSE | RCC_OSCILLATORTYPE_HSI | RCC_OSCILLATORTYPE_MSI | RCC_OSCILLATORTYPE_LSI | RCC_OSCILLATORTYPE_LSE)                                     
#endif                        

                                       
      
    
#define RCC_RESET_FLAG_OBL             RCC_CSR_OBLRSTF                                         
#define RCC_RESET_FLAG_PIN             RCC_CSR_PINRSTF                          
#define RCC_RESET_FLAG_PWR             RCC_CSR_BORRSTF                                     
#define RCC_RESET_FLAG_SW              RCC_CSR_SFTRSTF                               
#define RCC_RESET_FLAG_IWDG            RCC_CSR_IWDGRSTF                                          
#define RCC_RESET_FLAG_WWDG            RCC_CSR_WWDGRSTF                                     
#define RCC_RESET_FLAG_LPWR            RCC_CSR_LPWRRSTF                               
#define RCC_RESET_FLAG_ALL             (RCC_RESET_FLAG_OBL | RCC_RESET_FLAG_PIN | RCC_RESET_FLAG_PWR | \
                                        RCC_RESET_FLAG_SW | RCC_RESET_FLAG_IWDG | RCC_RESET_FLAG_WWDG | \
                                        RCC_RESET_FLAG_LPWR)
   
      
    

   
      
    

                                                                                
                                  
      
    

#define IS_RCC_OSCILLATORTYPE(__OSCILLATOR__)  (((__OSCILLATOR__) == RCC_OSCILLATORTYPE_NONE) || \
                                                (((__OSCILLATOR__) & ~RCC_OSCILLATORTYPE_ALL) == 0x00U))

#define IS_RCC_HSE(__HSE__)  (((__HSE__) == RCC_HSE_OFF) || ((__HSE__) == RCC_HSE_ON) || \
                              ((__HSE__) == RCC_HSE_BYPASS))

#if defined(RCC_BDCR_LSESYSDIS)
#define IS_RCC_LSE(__LSE__)  (((__LSE__) == RCC_LSE_OFF) || ((__LSE__) == RCC_LSE_ON) || ((__LSE__) == RCC_LSE_BYPASS_RTC_ONLY) || \
                              ((__LSE__) == RCC_LSE_ON_RTC_ONLY) || ((__LSE__) == RCC_LSE_BYPASS))
#else
#define IS_RCC_LSE(__LSE__)  (((__LSE__) == RCC_LSE_OFF) || ((__LSE__) == RCC_LSE_ON) || \
                              ((__LSE__) == RCC_LSE_BYPASS))
#endif                         

#define IS_RCC_HSI(__HSI__)  (((__HSI__) == RCC_HSI_OFF) || ((__HSI__) == RCC_HSI_ON))

#define IS_RCC_HSI_CALIBRATION_VALUE(__VALUE__) ((__VALUE__) <= (RCC_ICSCR_HSITRIM >> RCC_ICSCR_HSITRIM_Pos))

#define IS_RCC_LSI(__LSI__)  (((__LSI__) == RCC_LSI_OFF) || ((__LSI__) == RCC_LSI_ON))

#if defined(RCC_CSR_LSIPREDIV)
#define IS_RCC_LSIDIV(__LSIDIV__)  (((__LSIDIV__) == RCC_LSI_DIV1) || ((__LSIDIV__) == RCC_LSI_DIV128))
#endif                        

#define IS_RCC_MSI(__MSI__)  (((__MSI__) == RCC_MSI_OFF) || ((__MSI__) == RCC_MSI_ON))

#define IS_RCC_MSICALIBRATION_VALUE(__VALUE__) ((__VALUE__) <= 255U)

#if defined(RCC_HSI48_SUPPORT)
#define IS_RCC_HSI48(__HSI48__)  (((__HSI48__) == RCC_HSI48_OFF) || ((__HSI48__) == RCC_HSI48_ON))
#endif                        

#define IS_RCC_PLL(__PLL__) (((__PLL__) == RCC_PLL_NONE) ||((__PLL__) == RCC_PLL_OFF) || \
                             ((__PLL__) == RCC_PLL_ON))

#define IS_RCC_PLLSOURCE(__SOURCE__) (((__SOURCE__) == RCC_PLLSOURCE_NONE) || \
                                      ((__SOURCE__) == RCC_PLLSOURCE_MSI)  || \
                                      ((__SOURCE__) == RCC_PLLSOURCE_HSI)  || \
                                      ((__SOURCE__) == RCC_PLLSOURCE_HSE))

#if defined(RCC_PLLM_DIV_1_16_SUPPORT)
#define IS_RCC_PLLM_VALUE(__VALUE__) ((1U <= (__VALUE__)) && ((__VALUE__) <= 16U))
#else
#define IS_RCC_PLLM_VALUE(__VALUE__) ((1U <= (__VALUE__)) && ((__VALUE__) <= 8U))
#endif                               

#define IS_RCC_PLLN_VALUE(__VALUE__) ((8U <= (__VALUE__)) && ((__VALUE__) <= 86U))

#if defined(RCC_PLLP_DIV_2_31_SUPPORT)
#define IS_RCC_PLLP_VALUE(__VALUE__) (((__VALUE__) >= 2U) && ((__VALUE__) <= 31U))
#else
#define IS_RCC_PLLP_VALUE(__VALUE__) (((__VALUE__) == 7U) || ((__VALUE__) == 17U))
#endif                               

#define IS_RCC_PLLQ_VALUE(__VALUE__) (((__VALUE__) == 2U) || ((__VALUE__) == 4U) || \
                                      ((__VALUE__) == 6U) || ((__VALUE__) == 8U))

#define IS_RCC_PLLR_VALUE(__VALUE__) (((__VALUE__) == 2U) || ((__VALUE__) == 4U) || \
                                      ((__VALUE__) == 6U) || ((__VALUE__) == 8U))

#if defined(RCC_PLLSAI1_SUPPORT)
#define IS_RCC_PLLSAI1CLOCKOUT_VALUE(__VALUE__) (((((__VALUE__) & RCC_PLLSAI1_SAI1CLK) == RCC_PLLSAI1_SAI1CLK)  || \
                                                  (((__VALUE__) & RCC_PLLSAI1_48M2CLK) == RCC_PLLSAI1_48M2CLK)  || \
                                                  (((__VALUE__) & RCC_PLLSAI1_ADC1CLK) == RCC_PLLSAI1_ADC1CLK)) && \
                                                 (((__VALUE__) & ~(RCC_PLLSAI1_SAI1CLK|RCC_PLLSAI1_48M2CLK|RCC_PLLSAI1_ADC1CLK)) == 0U))
#endif                          

#if defined(RCC_PLLSAI2_SUPPORT)
#if defined(STM32L471xx) || defined(STM32L475xx) || defined(STM32L476xx) || defined(STM32L485xx) || defined(STM32L486xx) || defined(STM32L496xx) || defined(STM32L4A6xx)
#define IS_RCC_PLLSAI2CLOCKOUT_VALUE(__VALUE__) (((((__VALUE__) & RCC_PLLSAI2_SAI2CLK) == RCC_PLLSAI2_SAI2CLK)  || \
                                                  (((__VALUE__) & RCC_PLLSAI2_ADC2CLK) == RCC_PLLSAI2_ADC2CLK)) && \
                                                 (((__VALUE__) & ~(RCC_PLLSAI2_SAI2CLK|RCC_PLLSAI2_ADC2CLK)) == 0U))
#elif defined(STM32L4P5xx) || defined(STM32L4Q5xx) || defined(STM32L4R5xx) || defined(STM32L4R7xx) || defined(STM32L4R9xx) || defined(STM32L4S5xx) || defined(STM32L4S7xx) || defined(STM32L4S9xx)
#define IS_RCC_PLLSAI2CLOCKOUT_VALUE(__VALUE__) (((((__VALUE__) & RCC_PLLSAI2_SAI2CLK) == RCC_PLLSAI2_SAI2CLK)  || \
                                                  (((__VALUE__) & RCC_PLLSAI2_DSICLK)  == RCC_PLLSAI2_DSICLK)   || \
                                                  (((__VALUE__) & RCC_PLLSAI2_LTDCCLK) == RCC_PLLSAI2_LTDCCLK)) && \
                                                 (((__VALUE__) & ~(RCC_PLLSAI2_SAI2CLK|RCC_PLLSAI2_DSICLK|RCC_PLLSAI2_LTDCCLK)) == 0U))
#endif                                                                                                            
#endif                          

#define IS_RCC_MSI_CLOCK_RANGE(__RANGE__) (((__RANGE__) == RCC_MSIRANGE_0)  || \
                                           ((__RANGE__) == RCC_MSIRANGE_1)  || \
                                           ((__RANGE__) == RCC_MSIRANGE_2)  || \
                                           ((__RANGE__) == RCC_MSIRANGE_3)  || \
                                           ((__RANGE__) == RCC_MSIRANGE_4)  || \
                                           ((__RANGE__) == RCC_MSIRANGE_5)  || \
                                           ((__RANGE__) == RCC_MSIRANGE_6)  || \
                                           ((__RANGE__) == RCC_MSIRANGE_7)  || \
                                           ((__RANGE__) == RCC_MSIRANGE_8)  || \
                                           ((__RANGE__) == RCC_MSIRANGE_9)  || \
                                           ((__RANGE__) == RCC_MSIRANGE_10) || \
                                           ((__RANGE__) == RCC_MSIRANGE_11))

#define IS_RCC_MSI_STANDBY_CLOCK_RANGE(__RANGE__) (((__RANGE__) == RCC_MSIRANGE_4)  || \
                                                   ((__RANGE__) == RCC_MSIRANGE_5)  || \
                                                   ((__RANGE__) == RCC_MSIRANGE_6)  || \
                                                   ((__RANGE__) == RCC_MSIRANGE_7))

#define IS_RCC_CLOCKTYPE(__CLK__)  ((1U <= (__CLK__)) && ((__CLK__) <= 15U))

#define IS_RCC_SYSCLKSOURCE(__SOURCE__) (((__SOURCE__) == RCC_SYSCLKSOURCE_MSI) || \
                                         ((__SOURCE__) == RCC_SYSCLKSOURCE_HSI) || \
                                         ((__SOURCE__) == RCC_SYSCLKSOURCE_HSE) || \
                                         ((__SOURCE__) == RCC_SYSCLKSOURCE_PLLCLK))

#define IS_RCC_HCLK(__HCLK__) (((__HCLK__) == RCC_SYSCLK_DIV1)   || ((__HCLK__) == RCC_SYSCLK_DIV2)   || \
                               ((__HCLK__) == RCC_SYSCLK_DIV4)   || ((__HCLK__) == RCC_SYSCLK_DIV8)   || \
                               ((__HCLK__) == RCC_SYSCLK_DIV16)  || ((__HCLK__) == RCC_SYSCLK_DIV64)  || \
                               ((__HCLK__) == RCC_SYSCLK_DIV128) || ((__HCLK__) == RCC_SYSCLK_DIV256) || \
                               ((__HCLK__) == RCC_SYSCLK_DIV512))

#define IS_RCC_PCLK(__PCLK__) (((__PCLK__) == RCC_HCLK_DIV1) || ((__PCLK__) == RCC_HCLK_DIV2) || \
                               ((__PCLK__) == RCC_HCLK_DIV4) || ((__PCLK__) == RCC_HCLK_DIV8) || \
                               ((__PCLK__) == RCC_HCLK_DIV16))

#define IS_RCC_RTCCLKSOURCE(__SOURCE__) (((__SOURCE__) == RCC_RTCCLKSOURCE_NONE)   || \
                                         ((__SOURCE__) == RCC_RTCCLKSOURCE_LSE)    || \
                                         ((__SOURCE__) == RCC_RTCCLKSOURCE_LSI)    || \
                                         ((__SOURCE__) == RCC_RTCCLKSOURCE_HSE_DIV32))

#define IS_RCC_MCO(__MCOX__) ((__MCOX__) == RCC_MCO1)

#if defined(RCC_HSI48_SUPPORT)
#define IS_RCC_MCO1SOURCE(__SOURCE__) (((__SOURCE__) == RCC_MCO1SOURCE_NOCLOCK) || \
                                       ((__SOURCE__) == RCC_MCO1SOURCE_SYSCLK) || \
                                       ((__SOURCE__) == RCC_MCO1SOURCE_MSI) || \
                                       ((__SOURCE__) == RCC_MCO1SOURCE_HSI) || \
                                       ((__SOURCE__) == RCC_MCO1SOURCE_HSE) || \
                                       ((__SOURCE__) == RCC_MCO1SOURCE_PLLCLK) || \
                                       ((__SOURCE__) == RCC_MCO1SOURCE_LSI) || \
                                       ((__SOURCE__) == RCC_MCO1SOURCE_LSE) || \
                                       ((__SOURCE__) == RCC_MCO1SOURCE_HSI48))
#else
#define IS_RCC_MCO1SOURCE(__SOURCE__) (((__SOURCE__) == RCC_MCO1SOURCE_NOCLOCK) || \
                                       ((__SOURCE__) == RCC_MCO1SOURCE_SYSCLK) || \
                                       ((__SOURCE__) == RCC_MCO1SOURCE_MSI) || \
                                       ((__SOURCE__) == RCC_MCO1SOURCE_HSI) || \
                                       ((__SOURCE__) == RCC_MCO1SOURCE_HSE) || \
                                       ((__SOURCE__) == RCC_MCO1SOURCE_PLLCLK) || \
                                       ((__SOURCE__) == RCC_MCO1SOURCE_LSI) || \
                                       ((__SOURCE__) == RCC_MCO1SOURCE_LSE))
#endif                        

#define IS_RCC_MCODIV(__DIV__) (((__DIV__) == RCC_MCODIV_1) || ((__DIV__) == RCC_MCODIV_2) || \
                                ((__DIV__) == RCC_MCODIV_4) || ((__DIV__) == RCC_MCODIV_8) || \
                                ((__DIV__) == RCC_MCODIV_16))

#define IS_RCC_LSE_DRIVE(__DRIVE__) (((__DRIVE__) == RCC_LSEDRIVE_LOW)        || \
                                     ((__DRIVE__) == RCC_LSEDRIVE_MEDIUMLOW)  || \
                                     ((__DRIVE__) == RCC_LSEDRIVE_MEDIUMHIGH) || \
                                     ((__DRIVE__) == RCC_LSEDRIVE_HIGH))

#define IS_RCC_STOP_WAKEUPCLOCK(__SOURCE__) (((__SOURCE__) == RCC_STOP_WAKEUPCLOCK_MSI) || \
                                             ((__SOURCE__) == RCC_STOP_WAKEUPCLOCK_HSI))
   
      
    

                                     
#include "stm32l4xx_hal_rcc_ex.h"

                                                                                
                                      
      
    


                                             
      
    

                                                                                  
HAL_StatusTypeDef HAL_RCC_DeInit(void);
HAL_StatusTypeDef HAL_RCC_OscConfig(RCC_OscInitTypeDef *RCC_OscInitStruct);
HAL_StatusTypeDef HAL_RCC_ClockConfig(const RCC_ClkInitTypeDef *RCC_ClkInitStruct, uint32_t FLatency);

   
      
    

                                             
      
    

                                                                                  
void              HAL_RCC_MCOConfig(uint32_t RCC_MCOx, uint32_t RCC_MCOSource, uint32_t RCC_MCODiv);
void              HAL_RCC_EnableCSS(void);
uint32_t          HAL_RCC_GetSysClockFreq(void);
uint32_t          HAL_RCC_GetHCLKFreq(void);
uint32_t          HAL_RCC_GetPCLK1Freq(void);
uint32_t          HAL_RCC_GetPCLK2Freq(void);
void              HAL_RCC_GetOscConfig(RCC_OscInitTypeDef *RCC_OscInitStruct);
void              HAL_RCC_GetClockConfig(RCC_ClkInitTypeDef *RCC_ClkInitStruct, uint32_t *pFLatency);
                         
void              HAL_RCC_NMI_IRQHandler(void);
                                                   
void              HAL_RCC_CSSCallback(void);

uint32_t          HAL_RCC_GetResetSource(void);
   
      
    

   
      
    

   
      
    

   
      
    

#ifdef __cplusplus
}
#endif

#endif                          

