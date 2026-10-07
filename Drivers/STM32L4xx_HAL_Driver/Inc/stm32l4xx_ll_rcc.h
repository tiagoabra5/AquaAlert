/**
  ******************************************************************************
  * @file    stm32l4xx_ll_rcc.h
  * @author  MCD Application Team
  * @brief   Header file of RCC LL module.
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

                                                                                
#ifndef STM32L4xx_LL_RCC_H
#define STM32L4xx_LL_RCC_H

#ifdef __cplusplus
extern "C" {
#endif

                                                                                
#include "stm32l4xx.h"

                                   
      
    

#if defined(RCC)

                        
      
    

                                                                                
                                                                                
                                                                                
                                                            
      
    
                                    
                                                                 
#define RCC_OFFSET_CCIPR        0U
#define RCC_OFFSET_CCIPR2       0x14U

   
      
    

                                                                                
#if defined(USE_FULL_LL_DRIVER)
                                                      
      
    
   
      
    
#endif                       

                                                                                
#if defined(USE_FULL_LL_DRIVER)
                                                      
      
    

                                                         
      
    

   
                                          
    
typedef struct
{
  uint32_t SYSCLK_Frequency;                                      
  uint32_t HCLK_Frequency;                                      
  uint32_t PCLK1_Frequency;                                      
  uint32_t PCLK2_Frequency;                                      
} LL_RCC_ClocksTypeDef;

   
      
    

   
      
    
#endif                         

                                                                                
                                                              
      
    

                                                               
                                                                   
                                                                                 
                        
      
    
#if !defined  (HSE_VALUE)
#define HSE_VALUE    8000000U                                            
#endif                

#if !defined  (HSI_VALUE)
#define HSI_VALUE    16000000U                                           
#endif                

#if !defined  (LSE_VALUE)
#define LSE_VALUE    32768U                                              
#endif                

#if !defined  (LSI_VALUE)
#define LSI_VALUE    32000U                                              
#endif                
#if defined(RCC_HSI48_SUPPORT)

#if !defined  (HSI48_VALUE)
#define HSI48_VALUE  48000000U                                             
#endif                  
#endif                        

#if !defined  (EXTERNAL_SAI1_CLOCK_VALUE)
#define EXTERNAL_SAI1_CLOCK_VALUE    48000U                                                           
#endif                                

#if !defined  (EXTERNAL_SAI2_CLOCK_VALUE)
#define EXTERNAL_SAI2_CLOCK_VALUE    48000U                                                           
#endif                                
   
      
    

                                                      
                                                                           
      
    
#define LL_RCC_CICR_LSIRDYC                RCC_CICR_LSIRDYC                                      
#define LL_RCC_CICR_LSERDYC                RCC_CICR_LSERDYC                                      
#define LL_RCC_CICR_MSIRDYC                RCC_CICR_MSIRDYC                                      
#define LL_RCC_CICR_HSIRDYC                RCC_CICR_HSIRDYC                                      
#define LL_RCC_CICR_HSERDYC                RCC_CICR_HSERDYC                                      
#define LL_RCC_CICR_PLLRDYC                RCC_CICR_PLLRDYC                                      
#if defined(RCC_HSI48_SUPPORT)
#define LL_RCC_CICR_HSI48RDYC              RCC_CICR_HSI48RDYC                                      
#endif                        
#if defined(RCC_PLLSAI1_SUPPORT)
#define LL_RCC_CICR_PLLSAI1RDYC            RCC_CICR_PLLSAI1RDYC                                      
#endif                          
#if defined(RCC_PLLSAI2_SUPPORT)
#define LL_RCC_CICR_PLLSAI2RDYC            RCC_CICR_PLLSAI2RDYC                                      
#endif                          
#define LL_RCC_CICR_LSECSSC                RCC_CICR_LSECSSC                                                      
#define LL_RCC_CICR_CSSC                   RCC_CICR_CSSC                                                     
   
      
    

                                                  
                                                                          
      
    
#define LL_RCC_CIFR_LSIRDYF                RCC_CIFR_LSIRDYF                                     
#define LL_RCC_CIFR_LSERDYF                RCC_CIFR_LSERDYF                                     
#define LL_RCC_CIFR_MSIRDYF                RCC_CIFR_MSIRDYF                                     
#define LL_RCC_CIFR_HSIRDYF                RCC_CIFR_HSIRDYF                                     
#define LL_RCC_CIFR_HSERDYF                RCC_CIFR_HSERDYF                                     
#define LL_RCC_CIFR_PLLRDYF                RCC_CIFR_PLLRDYF                                     
#if defined(RCC_HSI48_SUPPORT)
#define LL_RCC_CIFR_HSI48RDYF              RCC_CIFR_HSI48RDYF                                     
#endif                        
#if defined(RCC_PLLSAI1_SUPPORT)
#define LL_RCC_CIFR_PLLSAI1RDYF            RCC_CIFR_PLLSAI1RDYF                                     
#endif                          
#if defined(RCC_PLLSAI2_SUPPORT)
#define LL_RCC_CIFR_PLLSAI2RDYF            RCC_CIFR_PLLSAI2RDYF                                     
#endif                          
#define LL_RCC_CIFR_LSECSSF                RCC_CIFR_LSECSSF                                                     
#define LL_RCC_CIFR_CSSF                   RCC_CIFR_CSSF                                                    
#define LL_RCC_CSR_FWRSTF                  RCC_CSR_FWRSTF                                
#define LL_RCC_CSR_LPWRRSTF                RCC_CSR_LPWRRSTF                               
#define LL_RCC_CSR_OBLRSTF                 RCC_CSR_OBLRSTF                          
#define LL_RCC_CSR_PINRSTF                 RCC_CSR_PINRSTF                          
#define LL_RCC_CSR_SFTRSTF                 RCC_CSR_SFTRSTF                               
#define LL_RCC_CSR_IWDGRSTF                RCC_CSR_IWDGRSTF                                          
#define LL_RCC_CSR_WWDGRSTF                RCC_CSR_WWDGRSTF                                     
#define LL_RCC_CSR_BORRSTF                 RCC_CSR_BORRSTF                          
   
      
    

                                     
                                                                                             
      
    
#define LL_RCC_CIER_LSIRDYIE               RCC_CIER_LSIRDYIE                                        
#define LL_RCC_CIER_LSERDYIE               RCC_CIER_LSERDYIE                                        
#define LL_RCC_CIER_MSIRDYIE               RCC_CIER_MSIRDYIE                                        
#define LL_RCC_CIER_HSIRDYIE               RCC_CIER_HSIRDYIE                                        
#define LL_RCC_CIER_HSERDYIE               RCC_CIER_HSERDYIE                                        
#define LL_RCC_CIER_PLLRDYIE               RCC_CIER_PLLRDYIE                                        
#if defined(RCC_HSI48_SUPPORT)
#define LL_RCC_CIER_HSI48RDYIE             RCC_CIER_HSI48RDYIE                                        
#endif                        
#if defined(RCC_PLLSAI1_SUPPORT)
#define LL_RCC_CIER_PLLSAI1RDYIE           RCC_CIER_PLLSAI1RDYIE                                        
#endif                          
#if defined(RCC_PLLSAI2_SUPPORT)
#define LL_RCC_CIER_PLLSAI2RDYIE           RCC_CIER_PLLSAI2RDYIE                                        
#endif                          
#define LL_RCC_CIER_LSECSSIE               RCC_CIER_LSECSSIE                                      
   
      
    

                                                                 
      
    
#define LL_RCC_LSEDRIVE_LOW                0x00000000U                                                       
#define LL_RCC_LSEDRIVE_MEDIUMLOW          RCC_BDCR_LSEDRV_0                                                      
#define LL_RCC_LSEDRIVE_MEDIUMHIGH         RCC_BDCR_LSEDRV_1                                                       
#define LL_RCC_LSEDRIVE_HIGH               RCC_BDCR_LSEDRV                                                    
   
      
    

                                                  
      
    
#define LL_RCC_MSIRANGE_0                  RCC_CR_MSIRANGE_0                        
#define LL_RCC_MSIRANGE_1                  RCC_CR_MSIRANGE_1                        
#define LL_RCC_MSIRANGE_2                  RCC_CR_MSIRANGE_2                        
#define LL_RCC_MSIRANGE_3                  RCC_CR_MSIRANGE_3                        
#define LL_RCC_MSIRANGE_4                  RCC_CR_MSIRANGE_4                        
#define LL_RCC_MSIRANGE_5                  RCC_CR_MSIRANGE_5                        
#define LL_RCC_MSIRANGE_6                  RCC_CR_MSIRANGE_6                        
#define LL_RCC_MSIRANGE_7                  RCC_CR_MSIRANGE_7                        
#define LL_RCC_MSIRANGE_8                  RCC_CR_MSIRANGE_8                        
#define LL_RCC_MSIRANGE_9                  RCC_CR_MSIRANGE_9                        
#define LL_RCC_MSIRANGE_10                 RCC_CR_MSIRANGE_10                       
#define LL_RCC_MSIRANGE_11                 RCC_CR_MSIRANGE_11                       
   
      
    

                                                               
      
    
#define LL_RCC_MSISRANGE_4                 RCC_CSR_MSISRANGE_1                        
#define LL_RCC_MSISRANGE_5                 RCC_CSR_MSISRANGE_2                        
#define LL_RCC_MSISRANGE_6                 RCC_CSR_MSISRANGE_4                        
#define LL_RCC_MSISRANGE_7                 RCC_CSR_MSISRANGE_8                        
   
      
    

                                                      
      
    
#define LL_RCC_LSCO_CLKSOURCE_LSI          0x00000000U                                                           
#define LL_RCC_LSCO_CLKSOURCE_LSE          RCC_BDCR_LSCOSEL                                                
   
      
    

                                                          
      
    
#define LL_RCC_SYS_CLKSOURCE_MSI           RCC_CFGR_SW_MSI                                         
#define LL_RCC_SYS_CLKSOURCE_HSI           RCC_CFGR_SW_HSI                                         
#define LL_RCC_SYS_CLKSOURCE_HSE           RCC_CFGR_SW_HSE                                         
#define LL_RCC_SYS_CLKSOURCE_PLL           RCC_CFGR_SW_PLL                                         
   
      
    

                                                                        
      
    
#define LL_RCC_SYS_CLKSOURCE_STATUS_MSI    RCC_CFGR_SWS_MSI                                   
#define LL_RCC_SYS_CLKSOURCE_STATUS_HSI    RCC_CFGR_SWS_HSI                                   
#define LL_RCC_SYS_CLKSOURCE_STATUS_HSE    RCC_CFGR_SWS_HSE                                   
#define LL_RCC_SYS_CLKSOURCE_STATUS_PLL    RCC_CFGR_SWS_PLL                                   
   
      
    

                                                 
      
    
#define LL_RCC_SYSCLK_DIV_1                RCC_CFGR_HPRE_DIV1                             
#define LL_RCC_SYSCLK_DIV_2                RCC_CFGR_HPRE_DIV2                              
#define LL_RCC_SYSCLK_DIV_4                RCC_CFGR_HPRE_DIV4                              
#define LL_RCC_SYSCLK_DIV_8                RCC_CFGR_HPRE_DIV8                              
#define LL_RCC_SYSCLK_DIV_16               RCC_CFGR_HPRE_DIV16                              
#define LL_RCC_SYSCLK_DIV_64               RCC_CFGR_HPRE_DIV64                              
#define LL_RCC_SYSCLK_DIV_128              RCC_CFGR_HPRE_DIV128                              
#define LL_RCC_SYSCLK_DIV_256              RCC_CFGR_HPRE_DIV256                              
#define LL_RCC_SYSCLK_DIV_512              RCC_CFGR_HPRE_DIV512                              
   
      
    

                                                                
      
    
#define LL_RCC_APB1_DIV_1                  RCC_CFGR_PPRE1_DIV1                          
#define LL_RCC_APB1_DIV_2                  RCC_CFGR_PPRE1_DIV2                           
#define LL_RCC_APB1_DIV_4                  RCC_CFGR_PPRE1_DIV4                           
#define LL_RCC_APB1_DIV_8                  RCC_CFGR_PPRE1_DIV8                           
#define LL_RCC_APB1_DIV_16                 RCC_CFGR_PPRE1_DIV16                           
   
      
    

                                                                 
      
    
#define LL_RCC_APB2_DIV_1                  RCC_CFGR_PPRE2_DIV1                          
#define LL_RCC_APB2_DIV_2                  RCC_CFGR_PPRE2_DIV2                           
#define LL_RCC_APB2_DIV_4                  RCC_CFGR_PPRE2_DIV4                           
#define LL_RCC_APB2_DIV_8                  RCC_CFGR_PPRE2_DIV8                           
#define LL_RCC_APB2_DIV_16                 RCC_CFGR_PPRE2_DIV16                           
   
      
    

                                                                                         
      
    
#define LL_RCC_STOP_WAKEUPCLOCK_MSI        0x00000000U                                                          
#define LL_RCC_STOP_WAKEUPCLOCK_HSI        RCC_CFGR_STOPWUCK                                                    
   
      
    

                                                         
      
    
#define LL_RCC_MCO1SOURCE_NOCLOCK          0x00000000U                                                                        
#define LL_RCC_MCO1SOURCE_SYSCLK           RCC_CFGR_MCOSEL_0                                                             
#define LL_RCC_MCO1SOURCE_MSI              RCC_CFGR_MCOSEL_1                                                          
#define LL_RCC_MCO1SOURCE_HSI              (RCC_CFGR_MCOSEL_0| RCC_CFGR_MCOSEL_1)                                       
#define LL_RCC_MCO1SOURCE_HSE              RCC_CFGR_MCOSEL_2                                                          
#define LL_RCC_MCO1SOURCE_PLLCLK           (RCC_CFGR_MCOSEL_0|RCC_CFGR_MCOSEL_2)                                           
#define LL_RCC_MCO1SOURCE_LSI              (RCC_CFGR_MCOSEL_1|RCC_CFGR_MCOSEL_2)                                      
#define LL_RCC_MCO1SOURCE_LSE              (RCC_CFGR_MCOSEL_0|RCC_CFGR_MCOSEL_1|RCC_CFGR_MCOSEL_2)                                     
#if defined(RCC_HSI48_SUPPORT)
#define LL_RCC_MCO1SOURCE_HSI48            RCC_CFGR_MCOSEL_3                                                            
#endif                        
   
      
    

                                                
      
    
#define LL_RCC_MCO1_DIV_1                  RCC_CFGR_MCOPRE_DIV1                              
#define LL_RCC_MCO1_DIV_2                  RCC_CFGR_MCOPRE_DIV2                               
#define LL_RCC_MCO1_DIV_4                  RCC_CFGR_MCOPRE_DIV4                               
#define LL_RCC_MCO1_DIV_8                  RCC_CFGR_MCOPRE_DIV8                               
#define LL_RCC_MCO1_DIV_16                 RCC_CFGR_MCOPRE_DIV16                               
   
      
    

#if defined(USE_FULL_LL_DRIVER)
                                                                   
      
    
#define LL_RCC_PERIPH_FREQUENCY_NO         0x00000000U                                                                       
#define LL_RCC_PERIPH_FREQUENCY_NA         0xFFFFFFFFU                                                                       
   
      
    
#endif                         

                                                                                 
      
    
#define LL_RCC_USART1_CLKSOURCE_PCLK2      (RCC_CCIPR_USART1SEL << 16U)                                                                          
#define LL_RCC_USART1_CLKSOURCE_SYSCLK     ((RCC_CCIPR_USART1SEL << 16U) | RCC_CCIPR_USART1SEL_0)                                                 
#define LL_RCC_USART1_CLKSOURCE_HSI        ((RCC_CCIPR_USART1SEL << 16U) | RCC_CCIPR_USART1SEL_1)                                              
#define LL_RCC_USART1_CLKSOURCE_LSE        ((RCC_CCIPR_USART1SEL << 16U) | RCC_CCIPR_USART1SEL)                                                
#define LL_RCC_USART2_CLKSOURCE_PCLK1      (RCC_CCIPR_USART2SEL << 16U)                                                                          
#define LL_RCC_USART2_CLKSOURCE_SYSCLK     ((RCC_CCIPR_USART2SEL << 16U) | RCC_CCIPR_USART2SEL_0)                                                 
#define LL_RCC_USART2_CLKSOURCE_HSI        ((RCC_CCIPR_USART2SEL << 16U) | RCC_CCIPR_USART2SEL_1)                                              
#define LL_RCC_USART2_CLKSOURCE_LSE        ((RCC_CCIPR_USART2SEL << 16U) | RCC_CCIPR_USART2SEL)                                                
#if defined(RCC_CCIPR_USART3SEL)
#define LL_RCC_USART3_CLKSOURCE_PCLK1      (RCC_CCIPR_USART3SEL << 16U)                                                                          
#define LL_RCC_USART3_CLKSOURCE_SYSCLK     ((RCC_CCIPR_USART3SEL << 16U) | RCC_CCIPR_USART3SEL_0)                                                 
#define LL_RCC_USART3_CLKSOURCE_HSI        ((RCC_CCIPR_USART3SEL << 16U) | RCC_CCIPR_USART3SEL_1)                                              
#define LL_RCC_USART3_CLKSOURCE_LSE        ((RCC_CCIPR_USART3SEL << 16U) | RCC_CCIPR_USART3SEL)                                                
#endif                          
   
      
    

#if defined(RCC_CCIPR_UART4SEL) || defined(RCC_CCIPR_UART5SEL)
                                                                               
      
    
#if defined(RCC_CCIPR_UART4SEL)
#define LL_RCC_UART4_CLKSOURCE_PCLK1       (RCC_CCIPR_UART4SEL << 16U)                                                                         
#define LL_RCC_UART4_CLKSOURCE_SYSCLK      ((RCC_CCIPR_UART4SEL << 16U) | RCC_CCIPR_UART4SEL_0)                                                 
#define LL_RCC_UART4_CLKSOURCE_HSI         ((RCC_CCIPR_UART4SEL << 16U) | RCC_CCIPR_UART4SEL_1)                                              
#define LL_RCC_UART4_CLKSOURCE_LSE         ((RCC_CCIPR_UART4SEL << 16U) | RCC_CCIPR_UART4SEL)                                                
#endif                         
#if defined(RCC_CCIPR_UART5SEL)
#define LL_RCC_UART5_CLKSOURCE_PCLK1       (RCC_CCIPR_UART5SEL << 16U)                                                                         
#define LL_RCC_UART5_CLKSOURCE_SYSCLK      ((RCC_CCIPR_UART5SEL << 16U) | RCC_CCIPR_UART5SEL_0)                                                 
#define LL_RCC_UART5_CLKSOURCE_HSI         ((RCC_CCIPR_UART5SEL << 16U) | RCC_CCIPR_UART5SEL_1)                                              
#define LL_RCC_UART5_CLKSOURCE_LSE         ((RCC_CCIPR_UART5SEL << 16U) | RCC_CCIPR_UART5SEL)                                                
#endif                         
   
      
    
#endif                                               

                                                                                   
      
    
#define LL_RCC_LPUART1_CLKSOURCE_PCLK1     0x00000000U                                                                     
#define LL_RCC_LPUART1_CLKSOURCE_SYSCLK    RCC_CCIPR_LPUART1SEL_0                                                           
#define LL_RCC_LPUART1_CLKSOURCE_HSI       RCC_CCIPR_LPUART1SEL_1                                                        
#define LL_RCC_LPUART1_CLKSOURCE_LSE       RCC_CCIPR_LPUART1SEL                                                          
   
      
    

                                                                             
      
    
#define LL_RCC_I2C1_CLKSOURCE_PCLK1        (((uint32_t)RCC_OFFSET_CCIPR << 24U) | ((uint32_t)RCC_CCIPR_I2C1SEL_Pos << 16U))                                                                                               
#define LL_RCC_I2C1_CLKSOURCE_SYSCLK       (((uint32_t)RCC_OFFSET_CCIPR << 24U) | ((uint32_t)RCC_CCIPR_I2C1SEL_Pos << 16U) | (RCC_CCIPR_I2C1SEL_0 >> RCC_CCIPR_I2C1SEL_Pos))                                               
#define LL_RCC_I2C1_CLKSOURCE_HSI          (((uint32_t)RCC_OFFSET_CCIPR << 24U) | ((uint32_t)RCC_CCIPR_I2C1SEL_Pos << 16U) | (RCC_CCIPR_I2C1SEL_1 >> RCC_CCIPR_I2C1SEL_Pos))                                            
#if defined(RCC_CCIPR_I2C2SEL)
#define LL_RCC_I2C2_CLKSOURCE_PCLK1        (((uint32_t)RCC_OFFSET_CCIPR << 24U) | ((uint32_t)RCC_CCIPR_I2C2SEL_Pos << 16U))                                                                                               
#define LL_RCC_I2C2_CLKSOURCE_SYSCLK       (((uint32_t)RCC_OFFSET_CCIPR << 24U) | ((uint32_t)RCC_CCIPR_I2C2SEL_Pos << 16U) | (RCC_CCIPR_I2C2SEL_0 >> RCC_CCIPR_I2C2SEL_Pos))                                               
#define LL_RCC_I2C2_CLKSOURCE_HSI          (((uint32_t)RCC_OFFSET_CCIPR << 24U) | ((uint32_t)RCC_CCIPR_I2C2SEL_Pos << 16U) | (RCC_CCIPR_I2C2SEL_1 >> RCC_CCIPR_I2C2SEL_Pos))                                            
#endif                        
#define LL_RCC_I2C3_CLKSOURCE_PCLK1        (((uint32_t)RCC_OFFSET_CCIPR << 24U) | ((uint32_t)RCC_CCIPR_I2C3SEL_Pos << 16U))                                                                                               
#define LL_RCC_I2C3_CLKSOURCE_SYSCLK       (((uint32_t)RCC_OFFSET_CCIPR << 24U) | ((uint32_t)RCC_CCIPR_I2C3SEL_Pos << 16U) | (RCC_CCIPR_I2C3SEL_0 >> RCC_CCIPR_I2C3SEL_Pos))                                               
#define LL_RCC_I2C3_CLKSOURCE_HSI          (((uint32_t)RCC_OFFSET_CCIPR << 24U) | ((uint32_t)RCC_CCIPR_I2C3SEL_Pos << 16U) | (RCC_CCIPR_I2C3SEL_1 >> RCC_CCIPR_I2C3SEL_Pos))                                            
#if defined(RCC_CCIPR2_I2C4SEL)
#define LL_RCC_I2C4_CLKSOURCE_PCLK1        (((uint32_t)RCC_OFFSET_CCIPR2 << 24U) | ((uint32_t)RCC_CCIPR2_I2C4SEL_Pos << 16U))                                                                                                 
#define LL_RCC_I2C4_CLKSOURCE_SYSCLK       (((uint32_t)RCC_OFFSET_CCIPR2 << 24U) | ((uint32_t)RCC_CCIPR2_I2C4SEL_Pos << 16U) | (RCC_CCIPR2_I2C4SEL_0 >> RCC_CCIPR2_I2C4SEL_Pos))                                               
#define LL_RCC_I2C4_CLKSOURCE_HSI          (((uint32_t)RCC_OFFSET_CCIPR2 << 24U) | ((uint32_t)RCC_CCIPR2_I2C4SEL_Pos << 16U) | (RCC_CCIPR2_I2C4SEL_1 >> RCC_CCIPR2_I2C4SEL_Pos))                                            
#endif                         
   
      
    

                                                                                 
      
    
#define LL_RCC_LPTIM1_CLKSOURCE_PCLK1      RCC_CCIPR_LPTIM1SEL                                                                                   
#define LL_RCC_LPTIM1_CLKSOURCE_LSI        (RCC_CCIPR_LPTIM1SEL | (RCC_CCIPR_LPTIM1SEL_0 >> 16U))                                              
#define LL_RCC_LPTIM1_CLKSOURCE_HSI        (RCC_CCIPR_LPTIM1SEL | (RCC_CCIPR_LPTIM1SEL_1 >> 16U))                                              
#define LL_RCC_LPTIM1_CLKSOURCE_LSE        (RCC_CCIPR_LPTIM1SEL | (RCC_CCIPR_LPTIM1SEL >> 16U))                                                
#define LL_RCC_LPTIM2_CLKSOURCE_PCLK1      RCC_CCIPR_LPTIM2SEL                                                                                   
#define LL_RCC_LPTIM2_CLKSOURCE_LSI        (RCC_CCIPR_LPTIM2SEL | (RCC_CCIPR_LPTIM2SEL_0 >> 16U))                                              
#define LL_RCC_LPTIM2_CLKSOURCE_HSI        (RCC_CCIPR_LPTIM2SEL | (RCC_CCIPR_LPTIM2SEL_1 >> 16U))                                              
#define LL_RCC_LPTIM2_CLKSOURCE_LSE        (RCC_CCIPR_LPTIM2SEL | (RCC_CCIPR_LPTIM2SEL >> 16U))                                                
   
      
    

                                                                             
      
    
#if defined(RCC_CCIPR2_SAI1SEL)
#define LL_RCC_SAI1_CLKSOURCE_PLLSAI1      (RCC_CCIPR2_SAI1SEL << 16U)                                                                                      
#define LL_RCC_SAI1_CLKSOURCE_PLLSAI2      ((RCC_CCIPR2_SAI1SEL << 16U) | RCC_CCIPR2_SAI1SEL_0)                                                             
#define LL_RCC_SAI1_CLKSOURCE_PLL          ((RCC_CCIPR2_SAI1SEL << 16U) | RCC_CCIPR2_SAI1SEL_1)                                                         
#define LL_RCC_SAI1_CLKSOURCE_PIN          ((RCC_CCIPR2_SAI1SEL << 16U) | (RCC_CCIPR2_SAI1SEL_1 | RCC_CCIPR2_SAI1SEL_0))                                                        
#define LL_RCC_SAI1_CLKSOURCE_HSI          ((RCC_CCIPR2_SAI1SEL << 16U) | RCC_CCIPR2_SAI1SEL_2)                                            
#elif defined(RCC_CCIPR_SAI1SEL)
#define LL_RCC_SAI1_CLKSOURCE_PLLSAI1      RCC_CCIPR_SAI1SEL                                                                                   
#if defined(RCC_PLLSAI2_SUPPORT)
#define LL_RCC_SAI1_CLKSOURCE_PLLSAI2      (RCC_CCIPR_SAI1SEL | (RCC_CCIPR_SAI1SEL_0 >> 16U))                                                  
#endif                          
#define LL_RCC_SAI1_CLKSOURCE_PLL          (RCC_CCIPR_SAI1SEL | (RCC_CCIPR_SAI1SEL_1 >> 16U))                                              
#define LL_RCC_SAI1_CLKSOURCE_PIN          (RCC_CCIPR_SAI1SEL | (RCC_CCIPR_SAI1SEL >> 16U))                                                           
#endif                         

#if defined(RCC_CCIPR2_SAI2SEL)
#define LL_RCC_SAI2_CLKSOURCE_PLLSAI1      (RCC_CCIPR2_SAI2SEL << 16U)                                                                                      
#define LL_RCC_SAI2_CLKSOURCE_PLLSAI2      ((RCC_CCIPR2_SAI2SEL << 16U) | RCC_CCIPR2_SAI2SEL_0)                                                             
#define LL_RCC_SAI2_CLKSOURCE_PLL          ((RCC_CCIPR2_SAI2SEL << 16U) | RCC_CCIPR2_SAI2SEL_1)                                                         
#define LL_RCC_SAI2_CLKSOURCE_PIN          ((RCC_CCIPR2_SAI2SEL << 16U) | (RCC_CCIPR2_SAI2SEL_1 | RCC_CCIPR2_SAI2SEL_0))                                                        
#define LL_RCC_SAI2_CLKSOURCE_HSI          ((RCC_CCIPR2_SAI2SEL << 16U) | RCC_CCIPR2_SAI2SEL_2)                                            
#elif defined(RCC_CCIPR_SAI2SEL)
#define LL_RCC_SAI2_CLKSOURCE_PLLSAI1      RCC_CCIPR_SAI2SEL                                                                                   
#if defined(RCC_PLLSAI2_SUPPORT)
#define LL_RCC_SAI2_CLKSOURCE_PLLSAI2      (RCC_CCIPR_SAI2SEL | (RCC_CCIPR_SAI2SEL_0 >> 16U))                                                  
#endif                          
#define LL_RCC_SAI2_CLKSOURCE_PLL          (RCC_CCIPR_SAI2SEL | (RCC_CCIPR_SAI2SEL_1 >> 16U))                                              
#define LL_RCC_SAI2_CLKSOURCE_PIN          (RCC_CCIPR_SAI2SEL | (RCC_CCIPR_SAI2SEL >> 16U))                                                           
#endif                         
   
      
    

#if defined(RCC_CCIPR2_SDMMCSEL)
                                                                                              
      
    
#define LL_RCC_SDMMC1_KERNELCLKSOURCE_48CLK  0x00000000U                                                                                   
#define LL_RCC_SDMMC1_KERNELCLKSOURCE_PLLP   RCC_CCIPR2_SDMMCSEL                                                      
   
      
    
#endif                          

#if defined(SDMMC1)
                                                                                 
      
    
#if defined(RCC_HSI48_SUPPORT)
#define LL_RCC_SDMMC1_CLKSOURCE_HSI48      0x00000000U                                                         
#else
#define LL_RCC_SDMMC1_CLKSOURCE_NONE       0x00000000U                                                      
#endif
#if defined(RCC_PLLSAI1_SUPPORT)
#define LL_RCC_SDMMC1_CLKSOURCE_PLLSAI1    RCC_CCIPR_CLK48SEL_0                                                  
#endif                          
#define LL_RCC_SDMMC1_CLKSOURCE_PLL        RCC_CCIPR_CLK48SEL_1                                              
#define LL_RCC_SDMMC1_CLKSOURCE_MSI        RCC_CCIPR_CLK48SEL                                                
   
      
    
#endif             

                                                                            
      
    
#if defined(RCC_HSI48_SUPPORT)
#define LL_RCC_RNG_CLKSOURCE_HSI48         0x00000000U                                                      
#else
#define LL_RCC_RNG_CLKSOURCE_NONE          0x00000000U                                                   
#endif
#if defined(RCC_PLLSAI1_SUPPORT)
#define LL_RCC_RNG_CLKSOURCE_PLLSAI1       RCC_CCIPR_CLK48SEL_0                                               
#endif                          
#define LL_RCC_RNG_CLKSOURCE_PLL           RCC_CCIPR_CLK48SEL_1                                           
#define LL_RCC_RNG_CLKSOURCE_MSI           RCC_CCIPR_CLK48SEL                                             
   
      
    

#if defined(USB_OTG_FS) || defined(USB)
                                                                            
      
    
#if defined(RCC_HSI48_SUPPORT)
#define LL_RCC_USB_CLKSOURCE_HSI48         0x00000000U                                                      
#else
#define LL_RCC_USB_CLKSOURCE_NONE          0x00000000U                                                   
#endif
#if defined(RCC_PLLSAI1_SUPPORT)
#define LL_RCC_USB_CLKSOURCE_PLLSAI1       RCC_CCIPR_CLK48SEL_0                                               
#endif                          
#define LL_RCC_USB_CLKSOURCE_PLL           RCC_CCIPR_CLK48SEL_1                                           
#define LL_RCC_USB_CLKSOURCE_MSI           RCC_CCIPR_CLK48SEL                                             
   
      
    

#endif                        

                                                                            
      
    
#define LL_RCC_ADC_CLKSOURCE_NONE          0x00000000U                                                   
#if defined(RCC_PLLSAI1_SUPPORT)
#define LL_RCC_ADC_CLKSOURCE_PLLSAI1       RCC_CCIPR_ADCSEL_0                                                 
#endif                          
#if defined(RCC_PLLSAI2_SUPPORT) && !defined(LTDC)
#define LL_RCC_ADC_CLKSOURCE_PLLSAI2       RCC_CCIPR_ADCSEL_1                                                 
#endif                          
#if defined(RCC_CCIPR_ADCSEL)
#define LL_RCC_ADC_CLKSOURCE_SYSCLK        RCC_CCIPR_ADCSEL                                                  
#else
#define LL_RCC_ADC_CLKSOURCE_SYSCLK        0x30000000U                                                       
#endif
   
      
    

#if defined(SWPMI1)
                                                                                  
      
    
#define LL_RCC_SWPMI1_CLKSOURCE_PCLK1      0x00000000U                                                   
#define LL_RCC_SWPMI1_CLKSOURCE_HSI        RCC_CCIPR_SWPMI1SEL                                         
   
      
    
#endif             

#if defined(DFSDM1_Channel0)
#if defined(RCC_CCIPR2_ADFSDM1SEL)
                                                                                              
      
    
#define LL_RCC_DFSDM1_AUDIO_CLKSOURCE_SAI1 0x00000000U                                                          
#define LL_RCC_DFSDM1_AUDIO_CLKSOURCE_HSI  RCC_CCIPR2_ADFSDM1SEL_0                                             
#define LL_RCC_DFSDM1_AUDIO_CLKSOURCE_MSI  RCC_CCIPR2_ADFSDM1SEL_1                                             
   
      
    
#endif                            

                                                                                  
      
    
#if defined(RCC_CCIPR2_DFSDM1SEL)
#define LL_RCC_DFSDM1_CLKSOURCE_PCLK2      0x00000000U                                                   
#define LL_RCC_DFSDM1_CLKSOURCE_SYSCLK     RCC_CCIPR2_DFSDM1SEL                                           
#else
#define LL_RCC_DFSDM1_CLKSOURCE_PCLK2      0x00000000U                                                   
#define LL_RCC_DFSDM1_CLKSOURCE_SYSCLK     RCC_CCIPR_DFSDM1SEL                                            
#endif                           
   
      
    
#endif                      

#if defined(DSI)
                                                                            
      
    
#define LL_RCC_DSI_CLKSOURCE_PHY          0x00000000U                                                                   
#define LL_RCC_DSI_CLKSOURCE_PLL          RCC_CCIPR2_DSISEL                                                         
   
      
    
#endif          

#if defined(LTDC)
                                                                              
      
    
#define LL_RCC_LTDC_CLKSOURCE_PLLSAI2R_DIV2  0x00000000U                                                                        
#define LL_RCC_LTDC_CLKSOURCE_PLLSAI2R_DIV4  RCC_CCIPR2_PLLSAI2DIVR_0                                                           
#define LL_RCC_LTDC_CLKSOURCE_PLLSAI2R_DIV8  RCC_CCIPR2_PLLSAI2DIVR_1                                                           
#define LL_RCC_LTDC_CLKSOURCE_PLLSAI2R_DIV16 RCC_CCIPR2_PLLSAI2DIVR                                                              
   
      
    
#endif           

#if defined(OCTOSPI1)
                                                                    
      
    
#define LL_RCC_OCTOSPI_CLKSOURCE_SYSCLK    0x00000000U                                                      
#define LL_RCC_OCTOSPI_CLKSOURCE_MSI       RCC_CCIPR2_OSPISEL_0                                          
#define LL_RCC_OCTOSPI_CLKSOURCE_PLL       RCC_CCIPR2_OSPISEL_1                                          
   
      
    
#endif               

                                                                
      
    
#define LL_RCC_USART1_CLKSOURCE            RCC_CCIPR_USART1SEL                                      
#define LL_RCC_USART2_CLKSOURCE            RCC_CCIPR_USART2SEL                                      
#if defined(RCC_CCIPR_USART3SEL)
#define LL_RCC_USART3_CLKSOURCE            RCC_CCIPR_USART3SEL                                      
#endif                          
   
      
    

#if defined(RCC_CCIPR_UART4SEL) || defined(RCC_CCIPR_UART5SEL)
                                                              
      
    
#if defined(RCC_CCIPR_UART4SEL)
#define LL_RCC_UART4_CLKSOURCE             RCC_CCIPR_UART4SEL                                     
#endif                         
#if defined(RCC_CCIPR_UART5SEL)
#define LL_RCC_UART5_CLKSOURCE             RCC_CCIPR_UART5SEL                                     
#endif                         
   
      
    
#endif                                               

                                                                  
      
    
#define LL_RCC_LPUART1_CLKSOURCE           RCC_CCIPR_LPUART1SEL                                       
   
      
    

                                                            
      
    
#define LL_RCC_I2C1_CLKSOURCE              (((uint32_t)RCC_OFFSET_CCIPR << 24U) | ((uint32_t)RCC_CCIPR_I2C1SEL_Pos << 16U) | (RCC_CCIPR_I2C1SEL >> RCC_CCIPR_I2C1SEL_Pos))                                    
#if defined(RCC_CCIPR_I2C2SEL)
#define LL_RCC_I2C2_CLKSOURCE              (((uint32_t)RCC_OFFSET_CCIPR << 24U) | ((uint32_t)RCC_CCIPR_I2C2SEL_Pos << 16U) | (RCC_CCIPR_I2C2SEL >> RCC_CCIPR_I2C2SEL_Pos))                                    
#endif                        
#define LL_RCC_I2C3_CLKSOURCE              (((uint32_t)RCC_OFFSET_CCIPR << 24U) | ((uint32_t)RCC_CCIPR_I2C3SEL_Pos << 16U) | (RCC_CCIPR_I2C3SEL >> RCC_CCIPR_I2C3SEL_Pos))                                    
#if defined(RCC_CCIPR2_I2C4SEL)
#define LL_RCC_I2C4_CLKSOURCE              (((uint32_t)RCC_OFFSET_CCIPR2 << 24U) | ((uint32_t)RCC_CCIPR2_I2C4SEL_Pos << 16U) | (RCC_CCIPR2_I2C4SEL >> RCC_CCIPR2_I2C4SEL_Pos))                                    
#endif                         
   
      
    

                                                                
      
    
#define LL_RCC_LPTIM1_CLKSOURCE            RCC_CCIPR_LPTIM1SEL                                      
#define LL_RCC_LPTIM2_CLKSOURCE            RCC_CCIPR_LPTIM2SEL                                      
   
      
    

#if defined(RCC_CCIPR_SAI1SEL) || defined(RCC_CCIPR2_SAI1SEL)
                                                             
      
    
#if defined(RCC_CCIPR2_SAI1SEL)
#define LL_RCC_SAI1_CLKSOURCE              RCC_CCIPR2_SAI1SEL                                    
#else
#define LL_RCC_SAI1_CLKSOURCE              RCC_CCIPR_SAI1SEL                                    
#endif                         
#if defined(RCC_CCIPR2_SAI2SEL)
#define LL_RCC_SAI2_CLKSOURCE              RCC_CCIPR2_SAI2SEL                                    
#elif defined(RCC_CCIPR_SAI2SEL)
#define LL_RCC_SAI2_CLKSOURCE              RCC_CCIPR_SAI2SEL                                    
#endif                         
   
      
    
#endif                                              

#if defined(SDMMC1)
#if defined(RCC_CCIPR2_SDMMCSEL)
                                                                               
      
    
#define LL_RCC_SDMMC1_KERNELCLKSOURCE      RCC_CCIPR2_SDMMCSEL                                             
   
      
    
#endif                          

                                                                 
      
    
#define LL_RCC_SDMMC1_CLKSOURCE            RCC_CCIPR_CLK48SEL                                      
   
      
    
#endif             

                                                            
      
    
#define LL_RCC_RNG_CLKSOURCE               RCC_CCIPR_CLK48SEL                                   
   
      
    

#if defined(USB_OTG_FS) || defined(USB)
                                                            
      
    
#define LL_RCC_USB_CLKSOURCE               RCC_CCIPR_CLK48SEL                                   
   
      
    
#endif                        

                                                            
      
    
#if defined(RCC_CCIPR_ADCSEL)
#define LL_RCC_ADC_CLKSOURCE               RCC_CCIPR_ADCSEL                                   
#else
#define LL_RCC_ADC_CLKSOURCE               0x30000000U                                   
#endif
   
      
    

#if defined(SWPMI1)
                                                                  
      
    
#define LL_RCC_SWPMI1_CLKSOURCE            RCC_CCIPR_SWPMI1SEL                                      
   
      
    
#endif             

#if defined(DFSDM1_Channel0)
#if defined(RCC_CCIPR2_ADFSDM1SEL)
                                                                              
      
    
#define LL_RCC_DFSDM1_AUDIO_CLKSOURCE      RCC_CCIPR2_ADFSDM1SEL                                          
   
      
    

#endif                            
                                                                  
      
    
#if defined(RCC_CCIPR2_DFSDM1SEL)
#define LL_RCC_DFSDM1_CLKSOURCE            RCC_CCIPR2_DFSDM1SEL                                      
#else
#define LL_RCC_DFSDM1_CLKSOURCE            RCC_CCIPR_DFSDM1SEL                                      
#endif                           
   
      
    
#endif                      

#if defined(DSI)
                                                            
      
    
#define LL_RCC_DSI_CLKSOURCE               RCC_CCIPR2_DSISEL                                        
   
      
    
#endif          

#if defined(LTDC)
                                                              
      
    
#define LL_RCC_LTDC_CLKSOURCE              RCC_CCIPR2_PLLSAI2DIVR                                    
   
      
    
#endif           

#if defined(OCTOSPI1)
                                                                    
      
    
#define LL_RCC_OCTOSPI_CLKSOURCE           RCC_CCIPR2_OSPISEL                                          
   
      
    
#endif               


                                                                 
      
    
#define LL_RCC_RTC_CLKSOURCE_NONE          0x00000000U                                                     
#define LL_RCC_RTC_CLKSOURCE_LSE           RCC_BDCR_RTCSEL_0                                                     
#define LL_RCC_RTC_CLKSOURCE_LSI           RCC_BDCR_RTCSEL_1                                                     
#define LL_RCC_RTC_CLKSOURCE_HSE_DIV32     RCC_BDCR_RTCSEL                                                                     
   
      
    


                                                                              
      
    
#define LL_RCC_PLLSOURCE_NONE              0x00000000U                             
#define LL_RCC_PLLSOURCE_MSI               RCC_PLLCFGR_PLLSRC_MSI                                                      
#define LL_RCC_PLLSOURCE_HSI               RCC_PLLCFGR_PLLSRC_HSI                                                        
#define LL_RCC_PLLSOURCE_HSE               RCC_PLLCFGR_PLLSRC_HSE                                                      
   
      
    

                                                     
      
    
#define LL_RCC_PLLM_DIV_1                  0x00000000U                                                                                                        
#define LL_RCC_PLLM_DIV_2                  (RCC_PLLCFGR_PLLM_0)                                                                                               
#define LL_RCC_PLLM_DIV_3                  (RCC_PLLCFGR_PLLM_1)                                                                                               
#define LL_RCC_PLLM_DIV_4                  (RCC_PLLCFGR_PLLM_1 | RCC_PLLCFGR_PLLM_0)                                                                          
#define LL_RCC_PLLM_DIV_5                  (RCC_PLLCFGR_PLLM_2)                                                                                               
#define LL_RCC_PLLM_DIV_6                  (RCC_PLLCFGR_PLLM_2 | RCC_PLLCFGR_PLLM_0)                                                                          
#define LL_RCC_PLLM_DIV_7                  (RCC_PLLCFGR_PLLM_2 | RCC_PLLCFGR_PLLM_1)                                                                          
#define LL_RCC_PLLM_DIV_8                  (RCC_PLLCFGR_PLLM_2 | RCC_PLLCFGR_PLLM_1 | RCC_PLLCFGR_PLLM_0)                                                     
#if defined(RCC_PLLM_DIV_1_16_SUPPORT)
#define LL_RCC_PLLM_DIV_9                  (RCC_PLLCFGR_PLLM_3)                                                                                               
#define LL_RCC_PLLM_DIV_10                 (RCC_PLLCFGR_PLLM_3 | RCC_PLLCFGR_PLLM_0)                                                                           
#define LL_RCC_PLLM_DIV_11                 (RCC_PLLCFGR_PLLM_3 | RCC_PLLCFGR_PLLM_1)                                                                           
#define LL_RCC_PLLM_DIV_12                 (RCC_PLLCFGR_PLLM_3 | RCC_PLLCFGR_PLLM_1 | RCC_PLLCFGR_PLLM_0)                                                      
#define LL_RCC_PLLM_DIV_13                 (RCC_PLLCFGR_PLLM_3 | RCC_PLLCFGR_PLLM_2)                                                                           
#define LL_RCC_PLLM_DIV_14                 (RCC_PLLCFGR_PLLM_3 | RCC_PLLCFGR_PLLM_2 | RCC_PLLCFGR_PLLM_0)                                                      
#define LL_RCC_PLLM_DIV_15                 (RCC_PLLCFGR_PLLM_3 | RCC_PLLCFGR_PLLM_2 | RCC_PLLCFGR_PLLM_1)                                                      
#define LL_RCC_PLLM_DIV_16                 (RCC_PLLCFGR_PLLM_3 | RCC_PLLCFGR_PLLM_2 | RCC_PLLCFGR_PLLM_1 | RCC_PLLCFGR_PLLM_0)                                                      
#endif                                
   
      
    

                                                            
      
    
#define LL_RCC_PLLR_DIV_2                  0x00000000U                                                                           
#define LL_RCC_PLLR_DIV_4                  (RCC_PLLCFGR_PLLR_0)                                                                  
#define LL_RCC_PLLR_DIV_6                  (RCC_PLLCFGR_PLLR_1)                                                                  
#define LL_RCC_PLLR_DIV_8                  (RCC_PLLCFGR_PLLR)                                                                    
   
      
    

#if defined(RCC_PLLP_SUPPORT)
                                                            
      
    
#if defined(RCC_PLLP_DIV_2_31_SUPPORT)
#define LL_RCC_PLLP_DIV_2                  (RCC_PLLCFGR_PLLPDIV_1)                                                                                                   
#define LL_RCC_PLLP_DIV_3                  (RCC_PLLCFGR_PLLPDIV_1|RCC_PLLCFGR_PLLPDIV_0)                                                                             
#define LL_RCC_PLLP_DIV_4                  (RCC_PLLCFGR_PLLPDIV_2)                                                                                                   
#define LL_RCC_PLLP_DIV_5                  (RCC_PLLCFGR_PLLPDIV_2|RCC_PLLCFGR_PLLPDIV_0)                                                                             
#define LL_RCC_PLLP_DIV_6                  (RCC_PLLCFGR_PLLPDIV_2|RCC_PLLCFGR_PLLPDIV_1)                                                                             
#define LL_RCC_PLLP_DIV_7                  (RCC_PLLCFGR_PLLPDIV_2|RCC_PLLCFGR_PLLPDIV_1|RCC_PLLCFGR_PLLPDIV_0)                                                       
#define LL_RCC_PLLP_DIV_8                  (RCC_PLLCFGR_PLLPDIV_3)                                                                                                   
#define LL_RCC_PLLP_DIV_9                  (RCC_PLLCFGR_PLLPDIV_3|RCC_PLLCFGR_PLLPDIV_0)                                                                             
#define LL_RCC_PLLP_DIV_10                 (RCC_PLLCFGR_PLLPDIV_3|RCC_PLLCFGR_PLLPDIV_1)                                                                              
#define LL_RCC_PLLP_DIV_11                 (RCC_PLLCFGR_PLLPDIV_3|RCC_PLLCFGR_PLLPDIV_1|RCC_PLLCFGR_PLLPDIV_0)                                                        
#define LL_RCC_PLLP_DIV_12                 (RCC_PLLCFGR_PLLPDIV_3|RCC_PLLCFGR_PLLPDIV_2)                                                                              
#define LL_RCC_PLLP_DIV_13                 (RCC_PLLCFGR_PLLPDIV_3|RCC_PLLCFGR_PLLPDIV_2|RCC_PLLCFGR_PLLPDIV_0)                                                        
#define LL_RCC_PLLP_DIV_14                 (RCC_PLLCFGR_PLLPDIV_3|RCC_PLLCFGR_PLLPDIV_2|RCC_PLLCFGR_PLLPDIV_1)                                                        
#define LL_RCC_PLLP_DIV_15                 (RCC_PLLCFGR_PLLPDIV_3|RCC_PLLCFGR_PLLPDIV_2|RCC_PLLCFGR_PLLPDIV_1|RCC_PLLCFGR_PLLPDIV_0)                                                       
#define LL_RCC_PLLP_DIV_16                 (RCC_PLLCFGR_PLLPDIV_4)                                                                                                    
#define LL_RCC_PLLP_DIV_17                 (RCC_PLLCFGR_PLLPDIV_4|RCC_PLLCFGR_PLLPDIV_0)                                                                              
#define LL_RCC_PLLP_DIV_18                 (RCC_PLLCFGR_PLLPDIV_4|RCC_PLLCFGR_PLLPDIV_1)                                                                              
#define LL_RCC_PLLP_DIV_19                 (RCC_PLLCFGR_PLLPDIV_4|RCC_PLLCFGR_PLLPDIV_1|RCC_PLLCFGR_PLLPDIV_0)                                                        
#define LL_RCC_PLLP_DIV_20                 (RCC_PLLCFGR_PLLPDIV_4|RCC_PLLCFGR_PLLPDIV_2)                                                                              
#define LL_RCC_PLLP_DIV_21                 (RCC_PLLCFGR_PLLPDIV_4|RCC_PLLCFGR_PLLPDIV_2|RCC_PLLCFGR_PLLPDIV_0)                                                        
#define LL_RCC_PLLP_DIV_22                 (RCC_PLLCFGR_PLLPDIV_4|RCC_PLLCFGR_PLLPDIV_2|RCC_PLLCFGR_PLLPDIV_1)                                                        
#define LL_RCC_PLLP_DIV_23                 (RCC_PLLCFGR_PLLPDIV_4|RCC_PLLCFGR_PLLPDIV_2|RCC_PLLCFGR_PLLPDIV_1|RCC_PLLCFGR_PLLPDIV_0)                                                       
#define LL_RCC_PLLP_DIV_24                 (RCC_PLLCFGR_PLLPDIV_4|RCC_PLLCFGR_PLLPDIV_3)                                                                              
#define LL_RCC_PLLP_DIV_25                 (RCC_PLLCFGR_PLLPDIV_4|RCC_PLLCFGR_PLLPDIV_3|RCC_PLLCFGR_PLLPDIV_0)                                                        
#define LL_RCC_PLLP_DIV_26                 (RCC_PLLCFGR_PLLPDIV_4|RCC_PLLCFGR_PLLPDIV_3|RCC_PLLCFGR_PLLPDIV_1)                                                        
#define LL_RCC_PLLP_DIV_27                 (RCC_PLLCFGR_PLLPDIV_4|RCC_PLLCFGR_PLLPDIV_3|RCC_PLLCFGR_PLLPDIV_1|RCC_PLLCFGR_PLLPDIV_0)                                                       
#define LL_RCC_PLLP_DIV_28                 (RCC_PLLCFGR_PLLPDIV_4|RCC_PLLCFGR_PLLPDIV_3|RCC_PLLCFGR_PLLPDIV_2)                                                        
#define LL_RCC_PLLP_DIV_29                 (RCC_PLLCFGR_PLLPDIV_4|RCC_PLLCFGR_PLLPDIV_3|RCC_PLLCFGR_PLLPDIV_2|RCC_PLLCFGR_PLLPDIV_0)                                                       
#define LL_RCC_PLLP_DIV_30                 (RCC_PLLCFGR_PLLPDIV_4|RCC_PLLCFGR_PLLPDIV_3|RCC_PLLCFGR_PLLPDIV_2|RCC_PLLCFGR_PLLPDIV_1)                                                       
#define LL_RCC_PLLP_DIV_31                 (RCC_PLLCFGR_PLLPDIV_4|RCC_PLLCFGR_PLLPDIV_3|RCC_PLLCFGR_PLLPDIV_2|RCC_PLLCFGR_PLLPDIV_1|RCC_PLLCFGR_PLLPDIV_0)                                                       
#else
#define LL_RCC_PLLP_DIV_7                  0x00000000U                                                                 
#define LL_RCC_PLLP_DIV_17                 (RCC_PLLCFGR_PLLP)                                                           
#endif                                
   
      
    
#endif                       

                                                            
      
    
#define LL_RCC_PLLQ_DIV_2                  0x00000000U                                                                  
#define LL_RCC_PLLQ_DIV_4                  (RCC_PLLCFGR_PLLQ_0)                                                         
#define LL_RCC_PLLQ_DIV_6                  (RCC_PLLCFGR_PLLQ_1)                                                         
#define LL_RCC_PLLQ_DIV_8                  (RCC_PLLCFGR_PLLQ)                                                           
   
      
    

#if defined(RCC_PLLSAI1M_DIV_1_16_SUPPORT)
                                                                    
      
    
#define LL_RCC_PLLSAI1M_DIV_1              0x00000000U                                                                                                    
#define LL_RCC_PLLSAI1M_DIV_2              (RCC_PLLSAI1CFGR_PLLSAI1M_0)                                                                                   
#define LL_RCC_PLLSAI1M_DIV_3              (RCC_PLLSAI1CFGR_PLLSAI1M_1)                                                                                   
#define LL_RCC_PLLSAI1M_DIV_4              (RCC_PLLSAI1CFGR_PLLSAI1M_1|RCC_PLLSAI1CFGR_PLLSAI1M_0)                                                        
#define LL_RCC_PLLSAI1M_DIV_5              (RCC_PLLSAI1CFGR_PLLSAI1M_2)                                                                                   
#define LL_RCC_PLLSAI1M_DIV_6              (RCC_PLLSAI1CFGR_PLLSAI1M_2|RCC_PLLSAI1CFGR_PLLSAI1M_0)                                                        
#define LL_RCC_PLLSAI1M_DIV_7              (RCC_PLLSAI1CFGR_PLLSAI1M_2|RCC_PLLSAI1CFGR_PLLSAI1M_1)                                                        
#define LL_RCC_PLLSAI1M_DIV_8              (RCC_PLLSAI1CFGR_PLLSAI1M_2|RCC_PLLSAI1CFGR_PLLSAI1M_1|RCC_PLLSAI1CFGR_PLLSAI1M_0)                                                        
#define LL_RCC_PLLSAI1M_DIV_9              (RCC_PLLSAI1CFGR_PLLSAI1M_3)                                                                                   
#define LL_RCC_PLLSAI1M_DIV_10             (RCC_PLLSAI1CFGR_PLLSAI1M_3|RCC_PLLSAI1CFGR_PLLSAI1M_0)                                                         
#define LL_RCC_PLLSAI1M_DIV_11             (RCC_PLLSAI1CFGR_PLLSAI1M_3|RCC_PLLSAI1CFGR_PLLSAI1M_1)                                                         
#define LL_RCC_PLLSAI1M_DIV_12             (RCC_PLLSAI1CFGR_PLLSAI1M_3|RCC_PLLSAI1CFGR_PLLSAI1M_1|RCC_PLLSAI1CFGR_PLLSAI1M_0)                                                         
#define LL_RCC_PLLSAI1M_DIV_13             (RCC_PLLSAI1CFGR_PLLSAI1M_3|RCC_PLLSAI1CFGR_PLLSAI1M_2)                                                         
#define LL_RCC_PLLSAI1M_DIV_14             (RCC_PLLSAI1CFGR_PLLSAI1M_3|RCC_PLLSAI1CFGR_PLLSAI1M_2|RCC_PLLSAI1CFGR_PLLSAI1M_0)                                                         
#define LL_RCC_PLLSAI1M_DIV_15             (RCC_PLLSAI1CFGR_PLLSAI1M_3|RCC_PLLSAI1CFGR_PLLSAI1M_2|RCC_PLLSAI1CFGR_PLLSAI1M_1)                                                         
#define LL_RCC_PLLSAI1M_DIV_16             (RCC_PLLSAI1CFGR_PLLSAI1M_3|RCC_PLLSAI1CFGR_PLLSAI1M_2|RCC_PLLSAI1CFGR_PLLSAI1M_1|RCC_PLLSAI1CFGR_PLLSAI1M_0)                                                         
   
      
    
#endif                                    

#if defined(RCC_PLLSAI1_SUPPORT)
                                                                    
      
    
#define LL_RCC_PLLSAI1Q_DIV_2              0x00000000U                                                                          
#define LL_RCC_PLLSAI1Q_DIV_4              (RCC_PLLSAI1CFGR_PLLSAI1Q_0)                                                         
#define LL_RCC_PLLSAI1Q_DIV_6              (RCC_PLLSAI1CFGR_PLLSAI1Q_1)                                                         
#define LL_RCC_PLLSAI1Q_DIV_8              (RCC_PLLSAI1CFGR_PLLSAI1Q)                                                           
   
      
    

                                                                    
      
    
#if defined(RCC_PLLSAI1P_DIV_2_31_SUPPORT)
#define LL_RCC_PLLSAI1P_DIV_2              (RCC_PLLSAI1CFGR_PLLSAI1PDIV_1)                                                                                       
#define LL_RCC_PLLSAI1P_DIV_3              (RCC_PLLSAI1CFGR_PLLSAI1PDIV_1|RCC_PLLSAI1CFGR_PLLSAI1PDIV_0)                                                         
#define LL_RCC_PLLSAI1P_DIV_4              (RCC_PLLSAI1CFGR_PLLSAI1PDIV_2)                                                                                       
#define LL_RCC_PLLSAI1P_DIV_5              (RCC_PLLSAI1CFGR_PLLSAI1PDIV_2|RCC_PLLSAI1CFGR_PLLSAI1PDIV_0)                                                         
#define LL_RCC_PLLSAI1P_DIV_6              (RCC_PLLSAI1CFGR_PLLSAI1PDIV_2|RCC_PLLSAI1CFGR_PLLSAI1PDIV_1)                                                         
#define LL_RCC_PLLSAI1P_DIV_7              (RCC_PLLSAI1CFGR_PLLSAI1PDIV_2|RCC_PLLSAI1CFGR_PLLSAI1PDIV_1|RCC_PLLSAI1CFGR_PLLSAI1PDIV_0)                                                         
#define LL_RCC_PLLSAI1P_DIV_8              (RCC_PLLSAI1CFGR_PLLSAI1PDIV_3)                                                                                       
#define LL_RCC_PLLSAI1P_DIV_9              (RCC_PLLSAI1CFGR_PLLSAI1PDIV_3|RCC_PLLSAI1CFGR_PLLSAI1PDIV_0)                                                         
#define LL_RCC_PLLSAI1P_DIV_10             (RCC_PLLSAI1CFGR_PLLSAI1PDIV_3|RCC_PLLSAI1CFGR_PLLSAI1PDIV_1)                                                          
#define LL_RCC_PLLSAI1P_DIV_11             (RCC_PLLSAI1CFGR_PLLSAI1PDIV_3|RCC_PLLSAI1CFGR_PLLSAI1PDIV_1|RCC_PLLSAI1CFGR_PLLSAI1PDIV_0)                                                         
#define LL_RCC_PLLSAI1P_DIV_12             (RCC_PLLSAI1CFGR_PLLSAI1PDIV_3|RCC_PLLSAI1CFGR_PLLSAI1PDIV_2)                                                          
#define LL_RCC_PLLSAI1P_DIV_13             (RCC_PLLSAI1CFGR_PLLSAI1PDIV_3|RCC_PLLSAI1CFGR_PLLSAI1PDIV_2|RCC_PLLSAI1CFGR_PLLSAI1PDIV_0)                                                          
#define LL_RCC_PLLSAI1P_DIV_14             (RCC_PLLSAI1CFGR_PLLSAI1PDIV_3|RCC_PLLSAI1CFGR_PLLSAI1PDIV_2|RCC_PLLSAI1CFGR_PLLSAI1PDIV_1)                                                          
#define LL_RCC_PLLSAI1P_DIV_15             (RCC_PLLSAI1CFGR_PLLSAI1PDIV_3|RCC_PLLSAI1CFGR_PLLSAI1PDIV_2|RCC_PLLSAI1CFGR_PLLSAI1PDIV_1|RCC_PLLSAI1CFGR_PLLSAI1PDIV_0)                                                          
#define LL_RCC_PLLSAI1P_DIV_16             (RCC_PLLSAI1CFGR_PLLSAI1PDIV_4)                                                                                        
#define LL_RCC_PLLSAI1P_DIV_17             (RCC_PLLSAI1CFGR_PLLSAI1PDIV_4|RCC_PLLSAI1CFGR_PLLSAI1PDIV_0)                                                          
#define LL_RCC_PLLSAI1P_DIV_18             (RCC_PLLSAI1CFGR_PLLSAI1PDIV_4|RCC_PLLSAI1CFGR_PLLSAI1PDIV_1)                                                          
#define LL_RCC_PLLSAI1P_DIV_19             (RCC_PLLSAI1CFGR_PLLSAI1PDIV_4|RCC_PLLSAI1CFGR_PLLSAI1PDIV_1|RCC_PLLSAI1CFGR_PLLSAI1PDIV_0)                                                          
#define LL_RCC_PLLSAI1P_DIV_20             (RCC_PLLSAI1CFGR_PLLSAI1PDIV_4|RCC_PLLSAI1CFGR_PLLSAI1PDIV_2)                                                          
#define LL_RCC_PLLSAI1P_DIV_21             (RCC_PLLSAI1CFGR_PLLSAI1PDIV_4|RCC_PLLSAI1CFGR_PLLSAI1PDIV_2|RCC_PLLSAI1CFGR_PLLSAI1PDIV_0)                                                         
#define LL_RCC_PLLSAI1P_DIV_22             (RCC_PLLSAI1CFGR_PLLSAI1PDIV_4|RCC_PLLSAI1CFGR_PLLSAI1PDIV_2|RCC_PLLSAI1CFGR_PLLSAI1PDIV_1)                                                          
#define LL_RCC_PLLSAI1P_DIV_23             (RCC_PLLSAI1CFGR_PLLSAI1PDIV_4|RCC_PLLSAI1CFGR_PLLSAI1PDIV_2|RCC_PLLSAI1CFGR_PLLSAI1PDIV_1|RCC_PLLSAI1CFGR_PLLSAI1PDIV_0)                                                          
#define LL_RCC_PLLSAI1P_DIV_24             (RCC_PLLSAI1CFGR_PLLSAI1PDIV_4|RCC_PLLSAI1CFGR_PLLSAI1PDIV_3)                                                          
#define LL_RCC_PLLSAI1P_DIV_25             (RCC_PLLSAI1CFGR_PLLSAI1PDIV_4|RCC_PLLSAI1CFGR_PLLSAI1PDIV_3|RCC_PLLSAI1CFGR_PLLSAI1PDIV_0)                                                          
#define LL_RCC_PLLSAI1P_DIV_26             (RCC_PLLSAI1CFGR_PLLSAI1PDIV_4|RCC_PLLSAI1CFGR_PLLSAI1PDIV_3|RCC_PLLSAI1CFGR_PLLSAI1PDIV_1)                                                          
#define LL_RCC_PLLSAI1P_DIV_27             (RCC_PLLSAI1CFGR_PLLSAI1PDIV_4|RCC_PLLSAI1CFGR_PLLSAI1PDIV_3|RCC_PLLSAI1CFGR_PLLSAI1PDIV_1|RCC_PLLSAI1CFGR_PLLSAI1PDIV_0)                                                          
#define LL_RCC_PLLSAI1P_DIV_28             (RCC_PLLSAI1CFGR_PLLSAI1PDIV_4|RCC_PLLSAI1CFGR_PLLSAI1PDIV_3|RCC_PLLSAI1CFGR_PLLSAI1PDIV_2)                                                          
#define LL_RCC_PLLSAI1P_DIV_29             (RCC_PLLSAI1CFGR_PLLSAI1PDIV_4|RCC_PLLSAI1CFGR_PLLSAI1PDIV_3|RCC_PLLSAI1CFGR_PLLSAI1PDIV_2|RCC_PLLSAI1CFGR_PLLSAI1PDIV_0)                                                          
#define LL_RCC_PLLSAI1P_DIV_30             (RCC_PLLSAI1CFGR_PLLSAI1PDIV_4|RCC_PLLSAI1CFGR_PLLSAI1PDIV_3|RCC_PLLSAI1CFGR_PLLSAI1PDIV_2|RCC_PLLSAI1CFGR_PLLSAI1PDIV_1)                                                          
#define LL_RCC_PLLSAI1P_DIV_31             (RCC_PLLSAI1CFGR_PLLSAI1PDIV_4|RCC_PLLSAI1CFGR_PLLSAI1PDIV_3|RCC_PLLSAI1CFGR_PLLSAI1PDIV_2|RCC_PLLSAI1CFGR_PLLSAI1PDIV_1|RCC_PLLSAI1CFGR_PLLSAI1PDIV_0)                                                          
#else
#define LL_RCC_PLLSAI1P_DIV_7              0x00000000U                                                                        
#define LL_RCC_PLLSAI1P_DIV_17             (RCC_PLLSAI1CFGR_PLLSAI1P)                                                          
#endif                                    
   
      
    

                                                                    
      
    
#define LL_RCC_PLLSAI1R_DIV_2              0x00000000U                                                                          
#define LL_RCC_PLLSAI1R_DIV_4              (RCC_PLLSAI1CFGR_PLLSAI1R_0)                                                         
#define LL_RCC_PLLSAI1R_DIV_6              (RCC_PLLSAI1CFGR_PLLSAI1R_1)                                                         
#define LL_RCC_PLLSAI1R_DIV_8              (RCC_PLLSAI1CFGR_PLLSAI1R)                                                           
   
      
    
#endif                          

#if defined(RCC_PLLSAI2_SUPPORT)
#if defined(RCC_PLLSAI2M_DIV_1_16_SUPPORT)
                                                                    
      
    
#define LL_RCC_PLLSAI2M_DIV_1              0x00000000U                                                                                                    
#define LL_RCC_PLLSAI2M_DIV_2              (RCC_PLLSAI2CFGR_PLLSAI2M_0)                                                                                   
#define LL_RCC_PLLSAI2M_DIV_3              (RCC_PLLSAI2CFGR_PLLSAI2M_1)                                                                                   
#define LL_RCC_PLLSAI2M_DIV_4              (RCC_PLLSAI2CFGR_PLLSAI2M_1|RCC_PLLSAI2CFGR_PLLSAI2M_0)                                                        
#define LL_RCC_PLLSAI2M_DIV_5              (RCC_PLLSAI2CFGR_PLLSAI2M_2)                                                                                   
#define LL_RCC_PLLSAI2M_DIV_6              (RCC_PLLSAI2CFGR_PLLSAI2M_2|RCC_PLLSAI2CFGR_PLLSAI2M_0)                                                        
#define LL_RCC_PLLSAI2M_DIV_7              (RCC_PLLSAI2CFGR_PLLSAI2M_2|RCC_PLLSAI2CFGR_PLLSAI2M_1)                                                        
#define LL_RCC_PLLSAI2M_DIV_8              (RCC_PLLSAI2CFGR_PLLSAI2M_2|RCC_PLLSAI2CFGR_PLLSAI2M_1|RCC_PLLSAI2CFGR_PLLSAI2M_0)                                                        
#define LL_RCC_PLLSAI2M_DIV_9              (RCC_PLLSAI2CFGR_PLLSAI2M_3)                                                                                   
#define LL_RCC_PLLSAI2M_DIV_10             (RCC_PLLSAI2CFGR_PLLSAI2M_3|RCC_PLLSAI2CFGR_PLLSAI2M_0)                                                         
#define LL_RCC_PLLSAI2M_DIV_11             (RCC_PLLSAI2CFGR_PLLSAI2M_3|RCC_PLLSAI2CFGR_PLLSAI2M_1)                                                         
#define LL_RCC_PLLSAI2M_DIV_12             (RCC_PLLSAI2CFGR_PLLSAI2M_3|RCC_PLLSAI2CFGR_PLLSAI2M_1|RCC_PLLSAI2CFGR_PLLSAI2M_0)                                                         
#define LL_RCC_PLLSAI2M_DIV_13             (RCC_PLLSAI2CFGR_PLLSAI2M_3|RCC_PLLSAI2CFGR_PLLSAI2M_2)                                                         
#define LL_RCC_PLLSAI2M_DIV_14             (RCC_PLLSAI2CFGR_PLLSAI2M_3|RCC_PLLSAI2CFGR_PLLSAI2M_2|RCC_PLLSAI2CFGR_PLLSAI2M_0)                                                         
#define LL_RCC_PLLSAI2M_DIV_15             (RCC_PLLSAI2CFGR_PLLSAI2M_3|RCC_PLLSAI2CFGR_PLLSAI2M_2|RCC_PLLSAI2CFGR_PLLSAI2M_1)                                                         
#define LL_RCC_PLLSAI2M_DIV_16             (RCC_PLLSAI2CFGR_PLLSAI2M_3|RCC_PLLSAI2CFGR_PLLSAI2M_2|RCC_PLLSAI2CFGR_PLLSAI2M_1|RCC_PLLSAI2CFGR_PLLSAI2M_0)                                                         
   
      
    
#endif                                    

#if defined(RCC_PLLSAI2Q_DIV_SUPPORT)
                                                                    
      
    
#define LL_RCC_PLLSAI2Q_DIV_2              0x00000000U                                                                          
#define LL_RCC_PLLSAI2Q_DIV_4              (RCC_PLLSAI2CFGR_PLLSAI2Q_0)                                                         
#define LL_RCC_PLLSAI2Q_DIV_6              (RCC_PLLSAI2CFGR_PLLSAI2Q_1)                                                         
#define LL_RCC_PLLSAI2Q_DIV_8              (RCC_PLLSAI2CFGR_PLLSAI2Q)                                                           
   
      
    
#endif                               

                                                                    
      
    
#if defined(RCC_PLLSAI2P_DIV_2_31_SUPPORT)
#define LL_RCC_PLLSAI2P_DIV_2              (RCC_PLLSAI2CFGR_PLLSAI2PDIV_1)                                                                                       
#define LL_RCC_PLLSAI2P_DIV_3              (RCC_PLLSAI2CFGR_PLLSAI2PDIV_1|RCC_PLLSAI2CFGR_PLLSAI2PDIV_0)                                                         
#define LL_RCC_PLLSAI2P_DIV_4              (RCC_PLLSAI2CFGR_PLLSAI2PDIV_2)                                                                                       
#define LL_RCC_PLLSAI2P_DIV_5              (RCC_PLLSAI2CFGR_PLLSAI2PDIV_2|RCC_PLLSAI2CFGR_PLLSAI2PDIV_0)                                                         
#define LL_RCC_PLLSAI2P_DIV_6              (RCC_PLLSAI2CFGR_PLLSAI2PDIV_2|RCC_PLLSAI2CFGR_PLLSAI2PDIV_1)                                                         
#define LL_RCC_PLLSAI2P_DIV_7              (RCC_PLLSAI2CFGR_PLLSAI2PDIV_2|RCC_PLLSAI2CFGR_PLLSAI2PDIV_1|RCC_PLLSAI2CFGR_PLLSAI2PDIV_0)                                                         
#define LL_RCC_PLLSAI2P_DIV_8              (RCC_PLLSAI2CFGR_PLLSAI2PDIV_3)                                                                                       
#define LL_RCC_PLLSAI2P_DIV_9              (RCC_PLLSAI2CFGR_PLLSAI2PDIV_3|RCC_PLLSAI2CFGR_PLLSAI2PDIV_0)                                                         
#define LL_RCC_PLLSAI2P_DIV_10             (RCC_PLLSAI2CFGR_PLLSAI2PDIV_3|RCC_PLLSAI2CFGR_PLLSAI2PDIV_1)                                                          
#define LL_RCC_PLLSAI2P_DIV_11             (RCC_PLLSAI2CFGR_PLLSAI2PDIV_3|RCC_PLLSAI2CFGR_PLLSAI2PDIV_1|RCC_PLLSAI2CFGR_PLLSAI2PDIV_0)                                                         
#define LL_RCC_PLLSAI2P_DIV_12             (RCC_PLLSAI2CFGR_PLLSAI2PDIV_3|RCC_PLLSAI2CFGR_PLLSAI2PDIV_2)                                                          
#define LL_RCC_PLLSAI2P_DIV_13             (RCC_PLLSAI2CFGR_PLLSAI2PDIV_3|RCC_PLLSAI2CFGR_PLLSAI2PDIV_2|RCC_PLLSAI2CFGR_PLLSAI2PDIV_0)                                                          
#define LL_RCC_PLLSAI2P_DIV_14             (RCC_PLLSAI2CFGR_PLLSAI2PDIV_3|RCC_PLLSAI2CFGR_PLLSAI2PDIV_2|RCC_PLLSAI2CFGR_PLLSAI2PDIV_1)                                                          
#define LL_RCC_PLLSAI2P_DIV_15             (RCC_PLLSAI2CFGR_PLLSAI2PDIV_3|RCC_PLLSAI2CFGR_PLLSAI2PDIV_2|RCC_PLLSAI2CFGR_PLLSAI2PDIV_1|RCC_PLLSAI2CFGR_PLLSAI2PDIV_0)                                                          
#define LL_RCC_PLLSAI2P_DIV_16             (RCC_PLLSAI2CFGR_PLLSAI2PDIV_4)                                                                                        
#define LL_RCC_PLLSAI2P_DIV_17             (RCC_PLLSAI2CFGR_PLLSAI2PDIV_4|RCC_PLLSAI2CFGR_PLLSAI2PDIV_0)                                                          
#define LL_RCC_PLLSAI2P_DIV_18             (RCC_PLLSAI2CFGR_PLLSAI2PDIV_4|RCC_PLLSAI2CFGR_PLLSAI2PDIV_1)                                                          
#define LL_RCC_PLLSAI2P_DIV_19             (RCC_PLLSAI2CFGR_PLLSAI2PDIV_4|RCC_PLLSAI2CFGR_PLLSAI2PDIV_1|RCC_PLLSAI2CFGR_PLLSAI2PDIV_0)                                                          
#define LL_RCC_PLLSAI2P_DIV_20             (RCC_PLLSAI2CFGR_PLLSAI2PDIV_4|RCC_PLLSAI2CFGR_PLLSAI2PDIV_2)                                                          
#define LL_RCC_PLLSAI2P_DIV_21             (RCC_PLLSAI2CFGR_PLLSAI2PDIV_4|RCC_PLLSAI2CFGR_PLLSAI2PDIV_2|RCC_PLLSAI2CFGR_PLLSAI2PDIV_0)                                                         
#define LL_RCC_PLLSAI2P_DIV_22             (RCC_PLLSAI2CFGR_PLLSAI2PDIV_4|RCC_PLLSAI2CFGR_PLLSAI2PDIV_2|RCC_PLLSAI2CFGR_PLLSAI2PDIV_1)                                                          
#define LL_RCC_PLLSAI2P_DIV_23             (RCC_PLLSAI2CFGR_PLLSAI2PDIV_4|RCC_PLLSAI2CFGR_PLLSAI2PDIV_2|RCC_PLLSAI2CFGR_PLLSAI2PDIV_1|RCC_PLLSAI2CFGR_PLLSAI2PDIV_0)                                                          
#define LL_RCC_PLLSAI2P_DIV_24             (RCC_PLLSAI2CFGR_PLLSAI2PDIV_4|RCC_PLLSAI2CFGR_PLLSAI2PDIV_3)                                                          
#define LL_RCC_PLLSAI2P_DIV_25             (RCC_PLLSAI2CFGR_PLLSAI2PDIV_4|RCC_PLLSAI2CFGR_PLLSAI2PDIV_3|RCC_PLLSAI2CFGR_PLLSAI2PDIV_0)                                                          
#define LL_RCC_PLLSAI2P_DIV_26             (RCC_PLLSAI2CFGR_PLLSAI2PDIV_4|RCC_PLLSAI2CFGR_PLLSAI2PDIV_3|RCC_PLLSAI2CFGR_PLLSAI2PDIV_1)                                                          
#define LL_RCC_PLLSAI2P_DIV_27             (RCC_PLLSAI2CFGR_PLLSAI2PDIV_4|RCC_PLLSAI2CFGR_PLLSAI2PDIV_3|RCC_PLLSAI2CFGR_PLLSAI2PDIV_1|RCC_PLLSAI2CFGR_PLLSAI2PDIV_0)                                                          
#define LL_RCC_PLLSAI2P_DIV_28             (RCC_PLLSAI2CFGR_PLLSAI2PDIV_4|RCC_PLLSAI2CFGR_PLLSAI2PDIV_3|RCC_PLLSAI2CFGR_PLLSAI2PDIV_2)                                                          
#define LL_RCC_PLLSAI2P_DIV_29             (RCC_PLLSAI2CFGR_PLLSAI2PDIV_4|RCC_PLLSAI2CFGR_PLLSAI2PDIV_3|RCC_PLLSAI2CFGR_PLLSAI2PDIV_2|RCC_PLLSAI2CFGR_PLLSAI2PDIV_0)                                                          
#define LL_RCC_PLLSAI2P_DIV_30             (RCC_PLLSAI2CFGR_PLLSAI2PDIV_4|RCC_PLLSAI2CFGR_PLLSAI2PDIV_3|RCC_PLLSAI2CFGR_PLLSAI2PDIV_2|RCC_PLLSAI2CFGR_PLLSAI2PDIV_1)                                                          
#define LL_RCC_PLLSAI2P_DIV_31             (RCC_PLLSAI2CFGR_PLLSAI2PDIV_4|RCC_PLLSAI2CFGR_PLLSAI2PDIV_3|RCC_PLLSAI2CFGR_PLLSAI2PDIV_2|RCC_PLLSAI2CFGR_PLLSAI2PDIV_1|RCC_PLLSAI2CFGR_PLLSAI2PDIV_0)                                                          
#else
#define LL_RCC_PLLSAI2P_DIV_7              0x00000000U                                                                        
#define LL_RCC_PLLSAI2P_DIV_17             (RCC_PLLSAI2CFGR_PLLSAI2P)                                                          
#endif                                    
   
      
    

                                                                    
      
    
#define LL_RCC_PLLSAI2R_DIV_2              0x00000000U                                                                          
#define LL_RCC_PLLSAI2R_DIV_4              (RCC_PLLSAI2CFGR_PLLSAI2R_0)                                                         
#define LL_RCC_PLLSAI2R_DIV_6              (RCC_PLLSAI2CFGR_PLLSAI2R_1)                                                         
#define LL_RCC_PLLSAI2R_DIV_8              (RCC_PLLSAI2CFGR_PLLSAI2R)                                                           
   
      
    

#if defined(RCC_CCIPR2_PLLSAI2DIVR)
                                                                              
      
    
#define LL_RCC_PLLSAI2DIVR_DIV_2           0x00000000U                                                                                
#define LL_RCC_PLLSAI2DIVR_DIV_4           RCC_CCIPR2_PLLSAI2DIVR_0                                                                   
#define LL_RCC_PLLSAI2DIVR_DIV_8           RCC_CCIPR2_PLLSAI2DIVR_1                                                                   
#define LL_RCC_PLLSAI2DIVR_DIV_16          (RCC_CCIPR2_PLLSAI2DIVR_1 | RCC_CCIPR2_PLLSAI2DIVR_0)                                                             
   
      
    
#endif                             
#endif                          

                                                              
      
    
#define LL_RCC_MSIRANGESEL_STANDBY         0U                                                            
#define LL_RCC_MSIRANGESEL_RUN             1U                                                           
   
      
    

#if defined(RCC_CSR_LSIPREDIV)
                                                      
      
    
#define LL_RCC_LSI_PREDIV_1                0x00000000U                                           
#define LL_RCC_LSI_PREDIV_128              RCC_CSR_LSIPREDIV                                     
   
      
    
#endif                        

                                                
       
  
#if defined(DFSDM1_Channel0)
#define LL_RCC_DFSDM1_CLKSOURCE_PCLK       LL_RCC_DFSDM1_CLKSOURCE_PCLK2
#define LL_RCC_DFSDM_CLKSOURCE_PCLK        LL_RCC_DFSDM1_CLKSOURCE_PCLK2
#define LL_RCC_DFSDM_CLKSOURCE_SYSCLK      LL_RCC_DFSDM1_CLKSOURCE_SYSCLK
#define LL_RCC_DFSDM_CLKSOURCE             LL_RCC_DFSDM1_CLKSOURCE
#endif                      
#if defined(SWPMI1)
#define LL_RCC_SWPMI1_CLKSOURCE_PCLK       LL_RCC_SWPMI1_CLKSOURCE_PCLK1
#endif             
   
        
    

   
      
    

                                                                                
                                                        
      
    

                                                                         
      
    

   
                                         
                                          
                                                         
                
    
#define LL_RCC_WriteReg(__REG__, __VALUE__) WRITE_REG(RCC->__REG__, (__VALUE__))

   
                                        
                                       
                          
    
#define LL_RCC_ReadReg(__REG__) READ_REG(RCC->__REG__)
   
      
    

                                                       
      
    

   
                                                                           
                                                                                      
                                                                  
                                                                    
                                                                       
                                       
                                       
                                       
                                       
                                       
                                       
                                       
                                       
                                           
                                            
                                            
                                            
                                            
                                            
                                            
                                            
   
                                                 
                                                                 
                                                                       
                                       
                                       
                                       
                                       
                                       
    
#define __LL_RCC_CALC_PLLCLK_FREQ(__INPUTFREQ__, __PLLM__, __PLLN__, __PLLR__) ((__INPUTFREQ__) / ((((__PLLM__)>> RCC_PLLCFGR_PLLM_Pos) + 1U)) * (__PLLN__) / \
                   ((((__PLLR__) >> RCC_PLLCFGR_PLLR_Pos) + 1U) * 2U))

#if defined(RCC_PLLSAI1_SUPPORT)
#if defined(RCC_PLLP_DIV_2_31_SUPPORT)
   
                                                                             
                                                                                          
                                                                  
                                                                    
                                                                       
                                       
                                       
                                       
                                       
                                       
                                       
                                       
                                       
                                           
                                            
                                            
                                            
                                            
                                            
                                            
                                            
   
                                                 
                                                                 
                                                                       
                                       
                                       
                                       
                                       
                                       
                                       
                                       
                                       
                                        
                                        
                                        
                                        
                                        
                                        
                                        
                                        
                                        
                                        
                                        
                                        
                                        
                                        
                                        
                                        
                                        
                                        
                                        
                                        
                                        
                                        
                                       
    
#define __LL_RCC_CALC_PLLCLK_SAI_FREQ(__INPUTFREQ__, __PLLM__, __PLLN__, __PLLP__) ((__INPUTFREQ__) / ((((__PLLM__)>> RCC_PLLCFGR_PLLM_Pos) + 1U)) * (__PLLN__) / \
                   ((__PLLP__) >> RCC_PLLCFGR_PLLPDIV_Pos))

#else
   
                                                                             
                                                                                          
                                                                  
                                                                    
                                                                       
                                       
                                       
                                       
                                       
                                       
                                       
                                       
                                       
                                     
                                                                       
                                       
                                        
                                       
    
#define __LL_RCC_CALC_PLLCLK_SAI_FREQ(__INPUTFREQ__, __PLLM__, __PLLN__, __PLLP__) ((__INPUTFREQ__) / ((((__PLLM__)>> RCC_PLLCFGR_PLLM_Pos) + 1U)) * (__PLLN__) / \
                   (((__PLLP__) == LL_RCC_PLLP_DIV_7) ? 7U : 17U))

#endif                                
#endif                          

   
                                                                             
                                                                                          
                                                                  
                                                                    
                                                                       
                                       
                                       
                                       
                                       
                                       
                                       
                                       
                                       
                                           
                                            
                                            
                                            
                                            
                                            
                                            
                                            
   
                                                 
                                                                 
                                                                       
                                       
                                       
                                       
                                       
                                       
    
#define __LL_RCC_CALC_PLLCLK_48M_FREQ(__INPUTFREQ__, __PLLM__, __PLLN__, __PLLQ__) ((__INPUTFREQ__) / ((((__PLLM__)>> RCC_PLLCFGR_PLLM_Pos) + 1U)) * (__PLLN__) / \
                   ((((__PLLQ__) >> RCC_PLLCFGR_PLLQ_Pos) + 1U) << 1U))

#if defined(RCC_PLLSAI1_SUPPORT)
#if defined(RCC_PLLSAI1M_DIV_1_16_SUPPORT) && defined(RCC_PLLSAI1P_DIV_2_31_SUPPORT)
   
                                                                               
                                                                                               
                                                                          
                                                                    
                                                                           
                                           
                                           
                                           
                                           
                                           
                                           
                                           
                                           
                                           
                                            
                                            
                                            
                                            
                                            
                                            
                                            
                                                                     
                                                                           
                                           
                                           
                                           
                                           
                                           
                                           
                                           
                                           
                                            
                                            
                                            
                                            
                                            
                                            
                                            
                                            
                                            
                                            
                                            
                                            
                                            
                                            
                                            
                                            
                                            
                                            
                                            
                                            
                                            
                                            
                                           
    
#define __LL_RCC_CALC_PLLSAI1_SAI_FREQ(__INPUTFREQ__, __PLLSAI1M__, __PLLSAI1N__, __PLLSAI1P__) \
                   ((__INPUTFREQ__) / ((((__PLLSAI1M__) >> RCC_PLLSAI1CFGR_PLLSAI1M_Pos) + 1U)) * (__PLLSAI1N__) / \
                    ((__PLLSAI1P__) >> RCC_PLLSAI1CFGR_PLLSAI1PDIV_Pos))

#elif defined(RCC_PLLSAI1P_DIV_2_31_SUPPORT)
   
                                                                               
                                                                                           
                                                                          
                                                                    
                                                                       
                                       
                                       
                                       
                                       
                                       
                                       
                                       
                                       
                                                                     
                                                                           
                                           
                                           
                                           
                                           
                                           
                                           
                                           
                                           
                                            
                                            
                                            
                                            
                                            
                                            
                                            
                                            
                                            
                                            
                                            
                                            
                                            
                                            
                                            
                                            
                                            
                                            
                                            
                                            
                                            
                                            
                                           
    
#define __LL_RCC_CALC_PLLSAI1_SAI_FREQ(__INPUTFREQ__, __PLLM__, __PLLSAI1N__, __PLLSAI1P__) \
                   ((__INPUTFREQ__) / ((((__PLLM__)>> RCC_PLLCFGR_PLLM_Pos) + 1U)) * (__PLLSAI1N__) / \
                    ((__PLLSAI1P__) >> RCC_PLLSAI1CFGR_PLLSAI1PDIV_Pos))

#else
   
                                                                               
                                                                                           
                                                                          
                                                                    
                                                                       
                                       
                                       
                                       
                                       
                                       
                                       
                                       
                                       
                                         
                                                                           
                                           
                                            
                                           
    
#define __LL_RCC_CALC_PLLSAI1_SAI_FREQ(__INPUTFREQ__, __PLLM__, __PLLSAI1N__, __PLLSAI1P__) \
                   ((__INPUTFREQ__) / ((((__PLLM__)>> RCC_PLLCFGR_PLLM_Pos) + 1U)) * (__PLLSAI1N__) / \
                    (((__PLLSAI1P__) == LL_RCC_PLLSAI1P_DIV_7) ? 7U : 17U))

#endif                                    

#if defined(RCC_PLLSAI1M_DIV_1_16_SUPPORT)
   
                                                                              
                                                                                               
                                                                          
                                                                    
                                                                           
                                           
                                           
                                           
                                           
                                           
                                           
                                           
                                           
                                           
                                            
                                            
                                            
                                            
                                            
                                            
                                            
                                                                     
                                                                           
                                           
                                           
                                           
                                           
                                           
    
#define __LL_RCC_CALC_PLLSAI1_48M_FREQ(__INPUTFREQ__, __PLLSAI1M__, __PLLSAI1N__, __PLLSAI1Q__) \
                   ((__INPUTFREQ__) / ((((__PLLSAI1M__) >> RCC_PLLSAI1CFGR_PLLSAI1M_Pos) + 1U)) * (__PLLSAI1N__) / \
                    ((((__PLLSAI1Q__) >> RCC_PLLSAI1CFGR_PLLSAI1Q_Pos) + 1U) << 1U))

#else
   
                                                                              
                                                                                           
                                                                          
                                                                    
                                                                       
                                       
                                       
                                       
                                       
                                       
                                       
                                       
                                       
                                         
                                                                           
                                           
                                           
                                           
                                           
                                           
    
#define __LL_RCC_CALC_PLLSAI1_48M_FREQ(__INPUTFREQ__, __PLLM__, __PLLSAI1N__, __PLLSAI1Q__) \
                   ((__INPUTFREQ__) / ((((__PLLM__)>> RCC_PLLCFGR_PLLM_Pos) + 1U)) * (__PLLSAI1N__) / \
                    ((((__PLLSAI1Q__) >> RCC_PLLSAI1CFGR_PLLSAI1Q_Pos) + 1U) << 1U))

#endif                                    

#if defined(RCC_PLLSAI1M_DIV_1_16_SUPPORT)
   
                                                                              
                                                                                               
                                                                          
                                                                    
                                                                           
                                           
                                           
                                           
                                           
                                           
                                           
                                           
                                           
                                           
                                            
                                            
                                            
                                            
                                            
                                            
                                            
                                                                     
                                                                           
                                           
                                           
                                           
                                           
                                           
    
#define __LL_RCC_CALC_PLLSAI1_ADC_FREQ(__INPUTFREQ__, __PLLSAI1M__, __PLLSAI1N__, __PLLSAI1R__) \
                   ((__INPUTFREQ__) / ((((__PLLSAI1M__) >> RCC_PLLSAI1CFGR_PLLSAI1M_Pos) + 1U)) * (__PLLSAI1N__) / \
                    ((((__PLLSAI1R__) >> RCC_PLLSAI1CFGR_PLLSAI1R_Pos) + 1U) << 1U))

#else
   
                                                                              
                                                                                           
                                                                          
                                                                    
                                                                       
                                       
                                       
                                       
                                       
                                       
                                       
                                       
                                       
                                         
                                                                           
                                           
                                           
                                           
                                           
                                           
    
#define __LL_RCC_CALC_PLLSAI1_ADC_FREQ(__INPUTFREQ__, __PLLM__, __PLLSAI1N__, __PLLSAI1R__) \
                   ((__INPUTFREQ__) / ((((__PLLM__)>> RCC_PLLCFGR_PLLM_Pos) + 1U)) * (__PLLSAI1N__) / \
                    ((((__PLLSAI1R__) >> RCC_PLLSAI1CFGR_PLLSAI1R_Pos) + 1U) << 1U))

#endif                                    
#endif                          

#if defined(RCC_PLLSAI2M_DIV_1_16_SUPPORT) && defined(RCC_PLLSAI2P_DIV_2_31_SUPPORT)
   
                                                                               
                                                                                               
                                                                          
                                                                    
                                                                           
                                           
                                           
                                           
                                           
                                           
                                           
                                           
                                           
                                           
                                            
                                            
                                            
                                            
                                            
                                            
                                            
                                                                     
                                                                           
                                           
                                           
                                           
                                           
                                           
                                           
                                           
                                           
                                            
                                            
                                            
                                            
                                            
                                            
                                            
                                            
                                            
                                            
                                            
                                            
                                            
                                            
                                            
                                            
                                            
                                            
                                            
                                            
                                            
                                            
                                           
    
#define __LL_RCC_CALC_PLLSAI2_SAI_FREQ(__INPUTFREQ__, __PLLSAI2M__, __PLLSAI2N__, __PLLSAI2P__) \
                   ((__INPUTFREQ__) / ((((__PLLSAI2M__) >> RCC_PLLSAI2CFGR_PLLSAI2M_Pos) + 1U)) * (__PLLSAI2N__) / \
                    ((__PLLSAI2P__) >> RCC_PLLSAI2CFGR_PLLSAI2PDIV_Pos))

#elif defined(RCC_PLLSAI2P_DIV_2_31_SUPPORT)
   
                                                                               
                                                                                           
                                                                          
                                                                    
                                                                       
                                       
                                       
                                       
                                       
                                       
                                       
                                       
                                       
                                                                     
                                                                           
                                           
                                           
                                           
                                           
                                           
                                           
                                           
                                           
                                            
                                            
                                            
                                            
                                            
                                            
                                            
                                            
                                            
                                            
                                            
                                            
                                            
                                            
                                            
                                            
                                            
                                            
                                            
                                            
                                            
                                            
                                           
    
#define __LL_RCC_CALC_PLLSAI2_SAI_FREQ(__INPUTFREQ__, __PLLM__, __PLLSAI2N__, __PLLSAI2P__) \
                   ((__INPUTFREQ__) / ((((__PLLM__)>> RCC_PLLCFGR_PLLM_Pos) + 1U)) * (__PLLSAI2N__) / \
                    ((__PLLSAI2P__) >> RCC_PLLSAI2CFGR_PLLSAI2PDIV_Pos))

#else
   
                                                                               
                                                                                           
                                                                          
                                                                    
                                                                       
                                       
                                       
                                       
                                       
                                       
                                       
                                       
                                       
                                         
                                                                           
                                           
                                            
                                           
    
#define __LL_RCC_CALC_PLLSAI2_SAI_FREQ(__INPUTFREQ__, __PLLM__, __PLLSAI2N__, __PLLSAI2P__) \
                   ((__INPUTFREQ__) / ((((__PLLM__)>> RCC_PLLCFGR_PLLM_Pos) + 1)) * (__PLLSAI2N__) / \
                    (((__PLLSAI2P__) == LL_RCC_PLLSAI2P_DIV_7) ? 7U : 17U))

#endif                                    

#if defined(LTDC)
   
                                                                                
                                                                                                
                                                                                                          
                                                                    
                                                                           
                                           
                                           
                                           
                                           
                                           
                                           
                                           
                                           
                                           
                                            
                                            
                                            
                                            
                                            
                                            
                                            
                                          
                                                                           
                                           
                                           
                                           
                                           
                                                                              
                                              
                                              
                                              
                                               
                                           
    
#define __LL_RCC_CALC_PLLSAI2_LTDC_FREQ(__INPUTFREQ__, __PLLSAI2M__, __PLLSAI2N__, __PLLSAI2R__, __PLLSAI2DIVR__) \
                   (((__INPUTFREQ__) / (((__PLLSAI2M__)>> RCC_PLLSAI2CFGR_PLLSAI2M_Pos) + 1U)) * (__PLLSAI2N__) / \
                    (((((__PLLSAI2R__) >> RCC_PLLSAI2CFGR_PLLSAI2R_Pos ) + 1U) << 1U) * (2UL << ((__PLLSAI2DIVR__) >> RCC_CCIPR2_PLLSAI2DIVR_Pos))))
#elif defined(RCC_PLLSAI2_SUPPORT)
   
                                                                              
                                                                                           
                                                                          
                                                                    
                                                                       
                                       
                                       
                                       
                                       
                                       
                                       
                                       
                                       
                                         
                                                                           
                                           
                                           
                                           
                                           
                                           
    
#define __LL_RCC_CALC_PLLSAI2_ADC_FREQ(__INPUTFREQ__, __PLLM__, __PLLSAI2N__, __PLLSAI2R__) \
                   ((__INPUTFREQ__) / ((((__PLLM__)>> RCC_PLLCFGR_PLLM_Pos) + 1U)) * (__PLLSAI2N__) / \
                    ((((__PLLSAI2R__) >> RCC_PLLSAI2CFGR_PLLSAI2R_Pos ) + 1U) << 1U))

#endif           

#if defined(DSI)
   
                                                                         
                                                                                               
                                                                          
                                                                    
                                                                           
                                           
                                           
                                           
                                           
                                           
                                           
                                           
                                           
                                           
                                            
                                            
                                            
                                            
                                            
                                            
                                            
                                          
                                                                           
                                           
                                           
                                           
                                           
                                       
    
#define __LL_RCC_CALC_PLLSAI2_DSI_FREQ(__INPUTFREQ__, __PLLSAI2M__, __PLLSAI2N__, __PLLSAI2Q__) \
                   ((__INPUTFREQ__) / ((((__PLLSAI2M__) >> RCC_PLLSAI2CFGR_PLLSAI2M_Pos) + 1U)) * (__PLLSAI2N__) / \
                    ((((__PLLSAI2Q__) >> RCC_PLLSAI2CFGR_PLLSAI2Q_Pos) + 1U) << 1U))
#endif          



   
                                                        
                                                                         
                                                                               
                                         
                                         
                                         
                                         
                                          
                                          
                                           
                                           
                                           
                                        
    
#define __LL_RCC_CALC_HCLK_FREQ(__SYSCLKFREQ__, __AHBPRESCALER__) ((__SYSCLKFREQ__) >> AHBPrescTable[((__AHBPRESCALER__) & RCC_CFGR_HPRE) >>  RCC_CFGR_HPRE_Pos])

   
                                                                
                                       
                                                                                
                                       
                                       
                                       
                                       
                                        
                                         
    
#define __LL_RCC_CALC_PCLK1_FREQ(__HCLKFREQ__, __APB1PRESCALER__) ((__HCLKFREQ__) >> APBPrescTable[(__APB1PRESCALER__) >>  RCC_CFGR_PPRE1_Pos])

   
                                                                
                                       
                                                                                
                                       
                                       
                                       
                                       
                                        
                                         
    
#define __LL_RCC_CALC_PCLK2_FREQ(__HCLKFREQ__, __APB2PRESCALER__) ((__HCLKFREQ__) >> APBPrescTable[(__APB2PRESCALER__) >>  RCC_CFGR_PPRE2_Pos])

   
                                                               
                                                                                          
                                                               
                                                                            
                                        
                                                                        
                                                    
                                        
                                                     
                                                                         
                                                
                                            
                                                                           
                                       
                                       
                                       
                                       
                                       
                                       
                                       
                                       
                                       
                                       
                                        
                                        
                                        
                                        
                                        
                                        
                                       
    
#define __LL_RCC_CALC_MSI_FREQ(__MSISEL__, __MSIRANGE__)   (((__MSISEL__) == LL_RCC_MSIRANGESEL_STANDBY) ? \
                           (MSIRangeTable[(__MSIRANGE__) >> 8U]) : \
                           (MSIRangeTable[(__MSIRANGE__) >> 4U]))

   
      
    

   
      
    

                                                                                
                                                              
      
    

                               
      
    

   
                                             
                                                           
                
    
__STATIC_INLINE void LL_RCC_HSE_EnableCSS(void)
{
  SET_BIT(RCC->CR, RCC_CR_CSSON);
}

   
                                                       
                                                              
                
    
__STATIC_INLINE void LL_RCC_HSE_EnableBypass(void)
{
  SET_BIT(RCC->CR, RCC_CR_HSEBYP);
}

   
                                                        
                                                               
                
    
__STATIC_INLINE void LL_RCC_HSE_DisableBypass(void)
{
  CLEAR_BIT(RCC->CR, RCC_CR_HSEBYP);
}

   
                                                  
                                                        
                
    
__STATIC_INLINE void LL_RCC_HSE_Enable(void)
{
  SET_BIT(RCC->CR, RCC_CR_HSEON);
}

   
                                                   
                                                         
                
    
__STATIC_INLINE void LL_RCC_HSE_Disable(void)
{
  CLEAR_BIT(RCC->CR, RCC_CR_HSEON);
}

   
                                         
                                                         
                                  
    
__STATIC_INLINE uint32_t LL_RCC_HSE_IsReady(void)
{
  return ((READ_BIT(RCC->CR, RCC_CR_HSERDY) == RCC_CR_HSERDY) ? 1UL : 0UL);
}

   
      
    

                               
      
    

   
                                        
                                                       
                                                                  
                
    
__STATIC_INLINE void LL_RCC_HSI_EnableInStopMode(void)
{
  SET_BIT(RCC->CR, RCC_CR_HSIKERON);
}

   
                                    
                                                                   
                
    
__STATIC_INLINE void LL_RCC_HSI_DisableInStopMode(void)
{
  CLEAR_BIT(RCC->CR, RCC_CR_HSIKERON);
}

   
                                                
                                                                       
                                  
    
__STATIC_INLINE uint32_t LL_RCC_HSI_IsEnabledInStopMode(void)
{
  return ((READ_BIT(RCC->CR, RCC_CR_HSIKERON) == RCC_CR_HSIKERON) ? 1UL : 0UL);
}

   
                                 
                                                        
                
    
__STATIC_INLINE void LL_RCC_HSI_Enable(void)
{
  SET_BIT(RCC->CR, RCC_CR_HSION);
}

   
                                  
                                                         
                
    
__STATIC_INLINE void LL_RCC_HSI_Disable(void)
{
  CLEAR_BIT(RCC->CR, RCC_CR_HSION);
}

   
                                       
                                                         
                                  
    
__STATIC_INLINE uint32_t LL_RCC_HSI_IsReady(void)
{
  return ((READ_BIT(RCC->CR, RCC_CR_HSIRDY) == RCC_CR_HSIRDY) ? 1UL : 0UL);
}

   
                                               
                                                                    
                
    
__STATIC_INLINE void LL_RCC_HSI_EnableAutoFromStop(void)
{
  SET_BIT(RCC->CR, RCC_CR_HSIASFS);
}

   
                                                
                                                                     
                
    
__STATIC_INLINE void LL_RCC_HSI_DisableAutoFromStop(void)
{
  CLEAR_BIT(RCC->CR, RCC_CR_HSIASFS);
}
   
                                     
                                                                    
                                            
                                                                
                                                       
    
__STATIC_INLINE uint32_t LL_RCC_HSI_GetCalibration(void)
{
  return (uint32_t)(READ_BIT(RCC->ICSCR, RCC_ICSCR_HSICAL) >> RCC_ICSCR_HSICAL_Pos);
}

   
                                        
                                                                      
                                                                                                
                                                                                      
                                                                  
                                                                                                      
                                                                          
                
    
__STATIC_INLINE void LL_RCC_HSI_SetCalibTrimming(uint32_t Value)
{
  MODIFY_REG(RCC->ICSCR, RCC_ICSCR_HSITRIM, Value << RCC_ICSCR_HSITRIM_Pos);
}

   
                                        
                                                                  
                                                                                                
                                                                    
    
__STATIC_INLINE uint32_t LL_RCC_HSI_GetCalibTrimming(void)
{
  return (uint32_t)(READ_BIT(RCC->ICSCR, RCC_ICSCR_HSITRIM) >> RCC_ICSCR_HSITRIM_Pos);
}

   
      
    

#if defined(RCC_HSI48_SUPPORT)
                                   
      
    

   
                        
                                                            
                
    
__STATIC_INLINE void LL_RCC_HSI48_Enable(void)
{
  SET_BIT(RCC->CRRCR, RCC_CRRCR_HSI48ON);
}

   
                         
                                                             
                
    
__STATIC_INLINE void LL_RCC_HSI48_Disable(void)
{
  CLEAR_BIT(RCC->CRRCR, RCC_CRRCR_HSI48ON);
}

   
                                           
                                                             
                                  
    
__STATIC_INLINE uint32_t LL_RCC_HSI48_IsReady(void)
{
  return ((READ_BIT(RCC->CRRCR, RCC_CRRCR_HSI48RDY) == RCC_CRRCR_HSI48RDY) ? 1UL : 0UL);
}

   
                                       
                                                                    
                                                        
    
__STATIC_INLINE uint32_t LL_RCC_HSI48_GetCalibration(void)
{
  return (uint32_t)(READ_BIT(RCC->CRRCR, RCC_CRRCR_HSI48CAL) >> RCC_CRRCR_HSI48CAL_Pos);
}

   
      
    
#endif                        

                               
      
    

   
                                                     
                                                        
                
    
__STATIC_INLINE void LL_RCC_LSE_Enable(void)
{
  SET_BIT(RCC->BDCR, RCC_BDCR_LSEON);
}

   
                                                      
                                                         
                
    
__STATIC_INLINE void LL_RCC_LSE_Disable(void)
{
  CLEAR_BIT(RCC->BDCR, RCC_BDCR_LSEON);
}

   
                                                      
                                                              
                
    
__STATIC_INLINE void LL_RCC_LSE_EnableBypass(void)
{
  SET_BIT(RCC->BDCR, RCC_BDCR_LSEBYP);
}

   
                                                       
                                                               
                
    
__STATIC_INLINE void LL_RCC_LSE_DisableBypass(void)
{
  CLEAR_BIT(RCC->BDCR, RCC_BDCR_LSEBYP);
}

   
                                               
                                                                       
                                                                    
                                                                       
                                         
                                               
                                                
                                          
                
    
__STATIC_INLINE void LL_RCC_LSE_SetDriveCapability(uint32_t LSEDrive)
{
  MODIFY_REG(RCC->BDCR, RCC_BDCR_LSEDRV, LSEDrive);
}

   
                                               
                                                                    
                                                              
                                         
                                               
                                                
                                          
    
__STATIC_INLINE uint32_t LL_RCC_LSE_GetDriveCapability(void)
{
  return (uint32_t)(READ_BIT(RCC->BDCR, RCC_BDCR_LSEDRV));
}

   
                                                
                                                           
                
    
__STATIC_INLINE void LL_RCC_LSE_EnableCSS(void)
{
  SET_BIT(RCC->BDCR, RCC_BDCR_LSECSSON);
}

   
                                                 
                                                                
                                                                          
                                                            
                
    
__STATIC_INLINE void LL_RCC_LSE_DisableCSS(void)
{
  CLEAR_BIT(RCC->BDCR, RCC_BDCR_LSECSSON);
}

   
                                         
                                                         
                                  
    
__STATIC_INLINE uint32_t LL_RCC_LSE_IsReady(void)
{
  return ((READ_BIT(RCC->BDCR, RCC_BDCR_LSERDY) == RCC_BDCR_LSERDY) ? 1UL : 0UL);
}

   
                                                 
                                                               
                                  
    
__STATIC_INLINE uint32_t LL_RCC_LSE_IsCSSDetected(void)
{
  return ((READ_BIT(RCC->BDCR, RCC_BDCR_LSECSSD) == RCC_BDCR_LSECSSD) ? 1UL : 0UL);
}

#if defined(RCC_BDCR_LSESYSDIS)
   
                                              
                                                                                           
                                                                                      
                                                                    
                
    
__STATIC_INLINE void LL_RCC_LSE_DisablePropagation(void)
{
  SET_BIT(RCC->BDCR, RCC_BDCR_LSESYSDIS);
}

   
                                             
                                                                                        
                                                                   
                
    
__STATIC_INLINE void LL_RCC_LSE_EnablePropagation(void)
{
  CLEAR_BIT(RCC->BDCR, RCC_BDCR_LSESYSDIS);
}

   
                                                          
                                                                      
                                  
    
__STATIC_INLINE uint32_t LL_RCC_LSE_IsPropagationEnabled(void)
{
  return ((READ_BIT(RCC->BDCR, RCC_BDCR_LSESYSDIS) == 0U) ? 1UL : 0UL);
}
#endif                         
   
      
    

                               
      
    

   
                                 
                                                        
                
    
__STATIC_INLINE void LL_RCC_LSI_Enable(void)
{
  SET_BIT(RCC->CSR, RCC_CSR_LSION);
}

   
                                  
                                                         
                
    
__STATIC_INLINE void LL_RCC_LSI_Disable(void)
{
  CLEAR_BIT(RCC->CSR, RCC_CSR_LSION);
}

   
                                 
                                                         
                                  
    
__STATIC_INLINE uint32_t LL_RCC_LSI_IsReady(void)
{
  return ((READ_BIT(RCC->CSR, RCC_CSR_LSIRDY) == RCC_CSR_LSIRDY) ? 1UL : 0UL);
}

#if defined(RCC_CSR_LSIPREDIV)
   
                                   
                                                           
                                                                         
                                         
                                           
                
    
__STATIC_INLINE void LL_RCC_LSI_SetPrediv(uint32_t LSI_PREDIV)
{
  MODIFY_REG(RCC->CSR, RCC_CSR_LSIPREDIV, LSI_PREDIV);
}

   
                                   
                                                           
                                                              
                                         
                                           
    
__STATIC_INLINE uint32_t LL_RCC_LSI_GetPrediv(void)
{
  return (READ_BIT(RCC->CSR, RCC_CSR_LSIPREDIV));
}
#endif                        

   
      
    

                               
      
    

   
                                 
                                                        
                
    
__STATIC_INLINE void LL_RCC_MSI_Enable(void)
{
  SET_BIT(RCC->CR, RCC_CR_MSION);
}

   
                                  
                                                         
                
    
__STATIC_INLINE void LL_RCC_MSI_Disable(void)
{
  CLEAR_BIT(RCC->CR, RCC_CR_MSION);
}

   
                                         
                                                         
                                  
    
__STATIC_INLINE uint32_t LL_RCC_MSI_IsReady(void)
{
  return ((READ_BIT(RCC->CR, RCC_CR_MSIRDY) == RCC_CR_MSIRDY) ? 1UL : 0UL);
}

   
                                                                    
                                                                       
                                            
                                                                      
               
                                                               
                
    
__STATIC_INLINE void LL_RCC_MSI_EnablePLLMode(void)
{
  SET_BIT(RCC->CR, RCC_CR_MSIPLLEN);
}

   
                                
                                                                      
                                                                
                                                                
                
    
__STATIC_INLINE void LL_RCC_MSI_DisablePLLMode(void)
{
  CLEAR_BIT(RCC->CR, RCC_CR_MSIPLLEN);
}

   
                                                                   
                                                           
                                                                 
                   
                                                                      
                
    
__STATIC_INLINE void LL_RCC_MSI_EnableRangeSelection(void)
{
  SET_BIT(RCC->CR, RCC_CR_MSIRGSEL);
}

   
                                                                       
                                                                      
                                  
    
__STATIC_INLINE uint32_t LL_RCC_MSI_IsEnabledRangeSelect(void)
{
  return ((READ_BIT(RCC->CR, RCC_CR_MSIRGSEL) == RCC_CR_MSIRGSEL) ? 1UL : 0UL);
}

   
                                                                                        
                                                          
                                                                    
                                       
                                       
                                       
                                       
                                       
                                       
                                       
                                       
                                       
                                       
                                        
                                        
                
    
__STATIC_INLINE void LL_RCC_MSI_SetRange(uint32_t Range)
{
  MODIFY_REG(RCC->CR, RCC_CR_MSIRANGE, Range);
}

   
                                                                                  
                                                          
                                                              
                                       
                                       
                                       
                                       
                                       
                                       
                                       
                                       
                                       
                                       
                                        
                                        
    
__STATIC_INLINE uint32_t LL_RCC_MSI_GetRange(void)
{
  return (uint32_t)(READ_BIT(RCC->CR, RCC_CR_MSIRANGE));
}

   
                                                  
                                                                      
                                                                    
                                        
                                        
                                        
                                        
                
    
__STATIC_INLINE void LL_RCC_MSI_SetRangeAfterStandby(uint32_t Range)
{
  MODIFY_REG(RCC->CSR, RCC_CSR_MSISRANGE, Range);
}

   
                                            
                                                                      
                                                              
                                        
                                        
                                        
                                        
    
__STATIC_INLINE uint32_t LL_RCC_MSI_GetRangeAfterStandby(void)
{
  return (uint32_t)(READ_BIT(RCC->CSR, RCC_CSR_MSISRANGE));
}

   
                                     
                                                                    
                                            
                                                                
                                                   
    
__STATIC_INLINE uint32_t LL_RCC_MSI_GetCalibration(void)
{
  return (uint32_t)(READ_BIT(RCC->ICSCR, RCC_ICSCR_MSICAL) >> RCC_ICSCR_MSICAL_Pos);
}

   
                                        
                                                                      
                                                                  
                                                         
                
    
__STATIC_INLINE void LL_RCC_MSI_SetCalibTrimming(uint32_t Value)
{
  MODIFY_REG(RCC->ICSCR, RCC_ICSCR_MSITRIM, Value << RCC_ICSCR_MSITRIM_Pos);
}

   
                                        
                                                                  
                             
    
__STATIC_INLINE uint32_t LL_RCC_MSI_GetCalibTrimming(void)
{
  return (uint32_t)(READ_BIT(RCC->ICSCR, RCC_ICSCR_MSITRIM) >> RCC_ICSCR_MSITRIM_Pos);
}

   
      
    

                                 
      
    

   
                                  
                                                         
                
    
__STATIC_INLINE void LL_RCC_LSCO_Enable(void)
{
  SET_BIT(RCC->BDCR, RCC_BDCR_LSCOEN);
}

   
                                   
                                                          
                
    
__STATIC_INLINE void LL_RCC_LSCO_Disable(void)
{
  CLEAR_BIT(RCC->BDCR, RCC_BDCR_LSCOEN);
}

   
                                               
                                                            
                                                                     
                                               
                                               
                
    
__STATIC_INLINE void LL_RCC_LSCO_SetSource(uint32_t Source)
{
  MODIFY_REG(RCC->BDCR, RCC_BDCR_LSCOSEL, Source);
}

   
                                         
                                                            
                                                              
                                               
                                               
    
__STATIC_INLINE uint32_t LL_RCC_LSCO_GetSource(void)
{
  return (uint32_t)(READ_BIT(RCC->BDCR, RCC_BDCR_LSCOSEL));
}

   
      
    

                                     
      
    

   
                                             
                                                             
                                                                     
                                              
                                              
                                              
                                              
                
    
__STATIC_INLINE void LL_RCC_SetSysClkSource(uint32_t Source)
{
  MODIFY_REG(RCC->CFGR, RCC_CFGR_SW, Source);
}

   
                                       
                                                             
                                                              
                                                     
                                                     
                                                     
                                                     
    
__STATIC_INLINE uint32_t LL_RCC_GetSysClkSource(void)
{
  return (uint32_t)(READ_BIT(RCC->CFGR, RCC_CFGR_SWS));
}

   
                             
                                                             
                                                                        
                                         
                                         
                                         
                                         
                                          
                                          
                                           
                                           
                                           
                
    
__STATIC_INLINE void LL_RCC_SetAHBPrescaler(uint32_t Prescaler)
{
  MODIFY_REG(RCC->CFGR, RCC_CFGR_HPRE, Prescaler);
}

   
                              
                                                              
                                                                        
                                       
                                       
                                       
                                       
                                        
                
    
__STATIC_INLINE void LL_RCC_SetAPB1Prescaler(uint32_t Prescaler)
{
  MODIFY_REG(RCC->CFGR, RCC_CFGR_PPRE1, Prescaler);
}

   
                              
                                                              
                                                                        
                                       
                                       
                                       
                                       
                                        
                
    
__STATIC_INLINE void LL_RCC_SetAPB2Prescaler(uint32_t Prescaler)
{
  MODIFY_REG(RCC->CFGR, RCC_CFGR_PPRE2, Prescaler);
}

   
                             
                                                             
                                                              
                                         
                                         
                                         
                                         
                                          
                                          
                                           
                                           
                                           
    
__STATIC_INLINE uint32_t LL_RCC_GetAHBPrescaler(void)
{
  return (uint32_t)(READ_BIT(RCC->CFGR, RCC_CFGR_HPRE));
}

   
                              
                                                              
                                                              
                                       
                                       
                                       
                                       
                                        
    
__STATIC_INLINE uint32_t LL_RCC_GetAPB1Prescaler(void)
{
  return (uint32_t)(READ_BIT(RCC->CFGR, RCC_CFGR_PPRE1));
}

   
                              
                                                              
                                                              
                                       
                                       
                                       
                                       
                                        
    
__STATIC_INLINE uint32_t LL_RCC_GetAPB2Prescaler(void)
{
  return (uint32_t)(READ_BIT(RCC->CFGR, RCC_CFGR_PPRE2));
}

   
                                                  
                                                                     
                                                                    
                                                 
                                                 
                
    
__STATIC_INLINE void LL_RCC_SetClkAfterWakeFromStop(uint32_t Clock)
{
  MODIFY_REG(RCC->CFGR, RCC_CFGR_STOPWUCK, Clock);
}

   
                                                  
                                                                     
                                                              
                                                 
                                                 
    
__STATIC_INLINE uint32_t LL_RCC_GetClkAfterWakeFromStop(void)
{
  return (uint32_t)(READ_BIT(RCC->CFGR, RCC_CFGR_STOPWUCK));
}

   
      
    

                               
      
    

   
                          
                                                         
                                                       
                                                                         
                                               
                                              
                                           
                                           
                                           
                                                 
                                              
                                           
                                           
   
                                                 
                                                                            
                                       
                                       
                                       
                                       
                                        
                
    
__STATIC_INLINE void LL_RCC_ConfigMCO(uint32_t MCOxSource, uint32_t MCOxPrescaler)
{
  MODIFY_REG(RCC->CFGR, RCC_CFGR_MCOSEL | RCC_CFGR_MCOPRE, MCOxSource | MCOxPrescaler);
}

   
      
    

                                                                       
      
    

   
                                         
                                                                 
                                                                           
                                                   
                                                    
                                                 
                                                 
                                                   
                                                    
                                                 
                                                 
                                                       
                                                        
                                                     
                                                     
   
                                                 
                
    
__STATIC_INLINE void LL_RCC_SetUSARTClockSource(uint32_t USARTxSource)
{
  MODIFY_REG(RCC->CCIPR, (USARTxSource >> 16U), (USARTxSource & 0x0000FFFFU));
}

#if defined(UART4) || defined(UART5)
   
                                        
                                                                
                                                                          
                                                  
                                                   
                                                
                                                
                                                  
                                                   
                                                
                                                
                
    
__STATIC_INLINE void LL_RCC_SetUARTClockSource(uint32_t UARTxSource)
{
  MODIFY_REG(RCC->CCIPR, (UARTxSource >> 16U), (UARTxSource & 0x0000FFFFU));
}
#endif                     

   
                                           
                                                                  
                                                                            
                                                    
                                                     
                                                  
                                                  
                
    
__STATIC_INLINE void LL_RCC_SetLPUARTClockSource(uint32_t LPUARTxSource)
{
  MODIFY_REG(RCC->CCIPR, RCC_CCIPR_LPUART1SEL, LPUARTxSource);
}

   
                                       
                                                               
                                                                         
                                                 
                                                  
                                               
                                                     
                                                      
                                                   
                                                 
                                                  
                                               
                                                     
                                                      
                                                   
   
                                                 
                
    
__STATIC_INLINE void LL_RCC_SetI2CClockSource(uint32_t I2CxSource)
{
  __IO uint32_t *reg = (__IO uint32_t *)(uint32_t)(RCC_BASE + 0x88U + (I2CxSource >> 24U));
  MODIFY_REG(*reg, 3UL << ((I2CxSource & 0x001F0000U) >> 16U), ((I2CxSource & 0x000000FFU) << ((I2CxSource & 0x001F0000U) >> 16U)));
}

   
                                         
                                                                 
                                                                           
                                                   
                                                 
                                                 
                                                 
                                                   
                                                 
                                                 
                                                 
                
    
__STATIC_INLINE void LL_RCC_SetLPTIMClockSource(uint32_t LPTIMxSource)
{
  MODIFY_REG(RCC->CCIPR, (LPTIMxSource & 0xFFFF0000U), (LPTIMxSource << 16U));
}

#if defined(RCC_CCIPR_SAI1SEL) || defined(RCC_CCIPR2_SAI1SEL)
   
                                       
                 
                                                               
       
                                                               
        
                                                                         
                                                   
                                                       
                                               
                                               
                                                       
                                                       
                                                   
                                                   
   
                                                 
                
    
__STATIC_INLINE void LL_RCC_SetSAIClockSource(uint32_t SAIxSource)
{
#if defined(RCC_CCIPR2_SAI1SEL)
  MODIFY_REG(RCC->CCIPR2, (SAIxSource >> 16U), (SAIxSource & 0x0000FFFFU));
#else
  MODIFY_REG(RCC->CCIPR, (SAIxSource & 0xFFFF0000U), (SAIxSource << 16U));
#endif                         
}
#endif                                              

#if defined(RCC_CCIPR2_SDMMCSEL)
   
                                                
                                                                       
                                                                           
                                                             
                                                            
   
                                                 
                
    
__STATIC_INLINE void LL_RCC_SetSDMMCKernelClockSource(uint32_t SDMMCxSource)
{
  MODIFY_REG(RCC->CCIPR2, RCC_CCIPR2_SDMMCSEL, SDMMCxSource);
}
#endif                          

   
                                         
                                                                 
                                                                           
                                                      
                                                       
                                                         
                                                 
                                                     
   
                                                 
                
    
__STATIC_INLINE void LL_RCC_SetSDMMCClockSource(uint32_t SDMMCxSource)
{
  MODIFY_REG(RCC->CCIPR, RCC_CCIPR_CLK48SEL, SDMMCxSource);
}

   
                                      
                                                               
                                                                         
                                                   
                                                    
                                                      
                                              
                                              
   
                                                 
                
    
__STATIC_INLINE void LL_RCC_SetRNGClockSource(uint32_t RNGxSource)
{
  MODIFY_REG(RCC->CCIPR, RCC_CCIPR_CLK48SEL, RNGxSource);
}

#if defined(USB_OTG_FS) || defined(USB)
   
                                      
                                                               
                                                                         
                                                   
                                                    
                                                      
                                              
                                              
   
                                                 
                
    
__STATIC_INLINE void LL_RCC_SetUSBClockSource(uint32_t USBxSource)
{
  MODIFY_REG(RCC->CCIPR, RCC_CCIPR_CLK48SEL, USBxSource);
}
#endif                        

#if defined(RCC_CCIPR_ADCSEL)
   
                                      
                                                               
                                                                         
                                               
                                                      
                                                      
                                                 
   
                                                 
                
    
__STATIC_INLINE void LL_RCC_SetADCClockSource(uint32_t ADCxSource)
{
  MODIFY_REG(RCC->CCIPR, RCC_CCIPR_ADCSEL, ADCxSource);
}
#endif                       

#if defined(SWPMI1)
   
                                        
                                                                 
                                                                           
                                                   
                                                 
                
    
__STATIC_INLINE void LL_RCC_SetSWPMIClockSource(uint32_t SWPMIxSource)
{
  MODIFY_REG(RCC->CCIPR, RCC_CCIPR_SWPMI1SEL, SWPMIxSource);
}
#endif             

#if defined(DFSDM1_Channel0)
#if defined(RCC_CCIPR2_ADFSDM1SEL)
   
                                              
                                                                           
                                                                     
                                                        
                                                       
                                                       
                
    
__STATIC_INLINE void LL_RCC_SetDFSDMAudioClockSource(uint32_t Source)
{
  MODIFY_REG(RCC->CCIPR2, RCC_CCIPR2_ADFSDM1SEL, Source);
}
#endif                            

   
                                               
                 
                                                                 
       
                                                                 
        
                                                                           
                                                   
                                                    
                
    
__STATIC_INLINE void LL_RCC_SetDFSDMClockSource(uint32_t DFSDMxSource)
{
#if defined(RCC_CCIPR2_DFSDM1SEL)
  MODIFY_REG(RCC->CCIPR2, RCC_CCIPR2_DFSDM1SEL, DFSDMxSource);
#else
  MODIFY_REG(RCC->CCIPR, RCC_CCIPR_DFSDM1SEL, DFSDMxSource);
#endif                           
}
#endif                      

#if defined(DSI)
   
                                      
                                                                 
                                                                     
                                              
                                              
                
    
__STATIC_INLINE void LL_RCC_SetDSIClockSource(uint32_t Source)
{
  MODIFY_REG(RCC->CCIPR2, RCC_CCIPR2_DSISEL, Source);
}
#endif          

#if defined(LTDC)
   
                                       
                                                                       
                                                                     
                                                         
                                                         
                                                         
                                                          
                
   
__STATIC_INLINE void LL_RCC_SetLTDCClockSource(uint32_t Source)
{
  MODIFY_REG(RCC->CCIPR2, RCC_CCIPR2_PLLSAI2DIVR, Source);
}
#endif           

#if defined(OCTOSPI1)
   
                                          
                                                                      
                                                                     
                                                     
                                                  
                                                  
                
    
__STATIC_INLINE void LL_RCC_SetOCTOSPIClockSource(uint32_t Source)
{
  MODIFY_REG(RCC->CCIPR2, RCC_CCIPR2_OSPISEL, Source);
}
#endif               

   
                                   
                                                                 
                                                                     
                                             
                                             
                                                 
   
                                                 
                                                              
                                                   
                                                    
                                                 
                                                 
                                                   
                                                    
                                                 
                                                 
                                                       
                                                        
                                                     
                                                     
   
                                                 
    
__STATIC_INLINE uint32_t LL_RCC_GetUSARTClockSource(uint32_t USARTx)
{
  return (uint32_t)(READ_BIT(RCC->CCIPR, USARTx) | (USARTx << 16U));
}

#if defined(UART4) || defined(UART5)
   
                                  
                                                                
                                                                    
                                            
                                            
                                                              
                                                  
                                                   
                                                
                                                
                                                  
                                                   
                                                
                                                
    
__STATIC_INLINE uint32_t LL_RCC_GetUARTClockSource(uint32_t UARTx)
{
  return (uint32_t)(READ_BIT(RCC->CCIPR, UARTx) | (UARTx << 16U));
}
#endif                     

   
                                    
                                                                  
                                                                      
                                              
                                                              
                                                    
                                                     
                                                  
                                                  
    
__STATIC_INLINE uint32_t LL_RCC_GetLPUARTClockSource(uint32_t LPUARTx)
{
  return (uint32_t)(READ_BIT(RCC->CCIPR, LPUARTx));
}

   
                                 
                                                               
                                                                   
                                           
                                               
                                           
                                               
   
                                                 
                                                              
                                                 
                                                  
                                               
                                                     
                                                      
                                                   
                                                 
                                                  
                                               
                                                     
                                                      
                                                   
   
                                                 
   
__STATIC_INLINE uint32_t LL_RCC_GetI2CClockSource(uint32_t I2Cx)
{
  __IO const uint32_t *reg = (__IO uint32_t *)(uint32_t)(RCC_BASE + 0x88U + (I2Cx >> 24U));
  return (uint32_t)((READ_BIT(*reg, 3UL << ((I2Cx & 0x001F0000U) >> 16U)) >> ((I2Cx & 0x001F0000U) >> 16U)) | (I2Cx & 0xFFFF0000U));
}

   
                                   
                                                                 
                                                                     
                                             
                                             
                                                              
                                                   
                                                 
                                                 
                                                 
                                                   
                                                 
                                                 
                                                 
    
__STATIC_INLINE uint32_t LL_RCC_GetLPTIMClockSource(uint32_t LPTIMx)
{
  return (uint32_t)((READ_BIT(RCC->CCIPR, LPTIMx) >> 16U) | LPTIMx);
}

#if defined(RCC_CCIPR_SAI1SEL) || defined(RCC_CCIPR2_SAI1SEL)
   
                                 
                 
                                                               
       
                                                               
        
                                                                   
                                           
                                               
   
                                                 
                                                              
                                                   
                                                       
                                               
                                               
                                                       
                                                       
                                                   
                                                   
   
                                                 
    
__STATIC_INLINE uint32_t LL_RCC_GetSAIClockSource(uint32_t SAIx)
{
#if defined(RCC_CCIPR2_SAI1SEL)
  return (uint32_t)(READ_BIT(RCC->CCIPR2, SAIx) | (SAIx << 16U));
#else
  return (uint32_t)(READ_BIT(RCC->CCIPR, SAIx) >> 16U | SAIx);
#endif                         
}
#endif                                              

#if defined(SDMMC1)
#if defined(RCC_CCIPR2_SDMMCSEL)
   
                                          
                                                                       
                                                                     
                                                   
                                                              
                                                             
                                                           
   
                                                 
    
__STATIC_INLINE uint32_t LL_RCC_GetSDMMCKernelClockSource(uint32_t SDMMCx)
{
  return (uint32_t)(READ_BIT(RCC->CCIPR2, SDMMCx));
}
#endif                          

   
                                   
                                                                 
                                                                     
                                             
                                                              
                                                      
                                                       
                                                         
                                                 
                                                     
   
                                                 
    
__STATIC_INLINE uint32_t LL_RCC_GetSDMMCClockSource(uint32_t SDMMCx)
{
  return (uint32_t)(READ_BIT(RCC->CCIPR, SDMMCx));
}
#endif             

   
                                 
                                                               
                                                                   
                                          
                                                              
                                                   
                                                    
                                                      
                                              
                                              
   
                                                 
    
__STATIC_INLINE uint32_t LL_RCC_GetRNGClockSource(uint32_t RNGx)
{
  return (uint32_t)(READ_BIT(RCC->CCIPR, RNGx));
}

#if defined(USB_OTG_FS) || defined(USB)
   
                                 
                                                               
                                                                   
                                          
                                                              
                                                   
                                                    
                                                      
                                              
                                              
   
                                                 
    
__STATIC_INLINE uint32_t LL_RCC_GetUSBClockSource(uint32_t USBx)
{
  return (uint32_t)(READ_BIT(RCC->CCIPR, USBx));
}
#endif                        

   
                                 
                                                               
                                                                   
                                          
                                                              
                                               
                                                      
                                                      
                                                 
   
                                                 
    
__STATIC_INLINE uint32_t LL_RCC_GetADCClockSource(uint32_t ADCx)
{
#if defined(RCC_CCIPR_ADCSEL)
  return (uint32_t)(READ_BIT(RCC->CCIPR, ADCx));
#else
  (void)ADCx;              
  return ((READ_BIT(RCC->AHB2ENR, RCC_AHB2ENR_ADCEN) != 0U) ? LL_RCC_ADC_CLKSOURCE_SYSCLK : LL_RCC_ADC_CLKSOURCE_NONE);
#endif                       
}

#if defined(SWPMI1)
   
                                   
                                                                 
                                                                     
                                             
                                                              
                                                   
                                                 
    
__STATIC_INLINE uint32_t LL_RCC_GetSWPMIClockSource(uint32_t SPWMIx)
{
  return (uint32_t)(READ_BIT(RCC->CCIPR, SPWMIx));
}
#endif             

#if defined(DFSDM1_Channel0)
#if defined(RCC_CCIPR2_ADFSDM1SEL)
   
                                        
                                                                            
                                                                     
                                                   
                                                              
                                                        
                                                       
                                                       
    
__STATIC_INLINE uint32_t LL_RCC_GetDFSDMAudioClockSource(uint32_t DFSDMx)
{
  return (uint32_t)(READ_BIT(RCC->CCIPR2, DFSDMx));
}
#endif                            

   
                                          
                 
                                                                 
       
                                                                 
        
                                                                     
                                             
                                                              
                                                   
                                                    
    
__STATIC_INLINE uint32_t LL_RCC_GetDFSDMClockSource(uint32_t DFSDMx)
{
#if defined(RCC_CCIPR2_DFSDM1SEL)
  return (uint32_t)(READ_BIT(RCC->CCIPR2, DFSDMx));
#else
  return (uint32_t)(READ_BIT(RCC->CCIPR, DFSDMx));
#endif                           
}
#endif                      

#if defined(DSI)
   
                                
                                                                 
                                                                   
                                          
                                                              
                                              
                                              
    
__STATIC_INLINE uint32_t LL_RCC_GetDSIClockSource(uint32_t DSIx)
{
  return (uint32_t)(READ_BIT(RCC->CCIPR2, DSIx));
}
#endif          

#if defined(LTDC)
   
                                 
                                                                       
                                                                    
                                           
                                                              
                                                         
                                                         
                                                         
                                                          
    
__STATIC_INLINE uint32_t LL_RCC_GetLTDCClockSource(uint32_t LTDCx)
{
  return (uint32_t)(READ_BIT(RCC->CCIPR2, LTDCx));
}
#endif           

#if defined(OCTOSPI1)
   
                                    
                                                                      
                                                                       
                                              
                                                              
                                                     
                                                  
                                                  
    
__STATIC_INLINE uint32_t LL_RCC_GetOCTOSPIClockSource(uint32_t OCTOSPIx)
{
  return (uint32_t)(READ_BIT(RCC->CCIPR2, OCTOSPIx));
}
#endif               
   
      
    

                               
      
    

   
                                
                                                                                          
                                                                                        
                                                        
                                                               
                                                                     
                                               
                                              
                                              
                                                    
                
    
__STATIC_INLINE void LL_RCC_SetRTCClockSource(uint32_t Source)
{
  MODIFY_REG(RCC->BDCR, RCC_BDCR_RTCSEL, Source);
}

   
                                
                                                               
                                                              
                                               
                                              
                                              
                                                    
    
__STATIC_INLINE uint32_t LL_RCC_GetRTCClockSource(void)
{
  return (uint32_t)(READ_BIT(RCC->BDCR, RCC_BDCR_RTCSEL));
}

   
                      
                                                       
                
    
__STATIC_INLINE void LL_RCC_EnableRTC(void)
{
  SET_BIT(RCC->BDCR, RCC_BDCR_RTCEN);
}

   
                       
                                                        
                
    
__STATIC_INLINE void LL_RCC_DisableRTC(void)
{
  CLEAR_BIT(RCC->BDCR, RCC_BDCR_RTCEN);
}

   
                                                
                                                          
                                  
    
__STATIC_INLINE uint32_t LL_RCC_IsEnabledRTC(void)
{
  return ((READ_BIT(RCC->BDCR, RCC_BDCR_RTCEN) == RCC_BDCR_RTCEN) ? 1UL : 0UL);
}

   
                                         
                                                                    
                
    
__STATIC_INLINE void LL_RCC_ForceBackupDomainReset(void)
{
  SET_BIT(RCC->BDCR, RCC_BDCR_BDRST);
}

   
                                           
                                                                      
                
    
__STATIC_INLINE void LL_RCC_ReleaseBackupDomainReset(void)
{
  CLEAR_BIT(RCC->BDCR, RCC_BDCR_BDRST);
}

   
      
    


                               
      
    

   
                      
                                                        
                
    
__STATIC_INLINE void LL_RCC_PLL_Enable(void)
{
  SET_BIT(RCC->CR, RCC_CR_PLLON);
}

   
                       
                                                                         
                                                         
                
    
__STATIC_INLINE void LL_RCC_PLL_Disable(void)
{
  CLEAR_BIT(RCC->CR, RCC_CR_PLLON);
}

   
                              
                                                         
                                  
    
__STATIC_INLINE uint32_t LL_RCC_PLL_IsReady(void)
{
  return ((READ_BIT(RCC->CR, RCC_CR_PLLRDY) == RCC_CR_PLLRDY) ? 1UL : 0UL);
}

   
                                                
                                                                   
                                               
                                                             
                                                                    
                                                                    
                                                                    
                                                                  
                                                                     
                                           
                                          
                                          
                                          
                                                                   
                                       
                                       
                                       
                                       
                                       
                                       
                                       
                                       
                                           
                                            
                                            
                                            
                                            
                                            
                                            
                                            
   
                                                 
                                                             
                                                                   
                                       
                                       
                                       
                                       
                
    
__STATIC_INLINE void LL_RCC_PLL_ConfigDomain_SYS(uint32_t Source, uint32_t PLLM, uint32_t PLLN, uint32_t PLLR)
{
  MODIFY_REG(RCC->PLLCFGR, RCC_PLLCFGR_PLLSRC | RCC_PLLCFGR_PLLM | RCC_PLLCFGR_PLLN | RCC_PLLCFGR_PLLR,
             Source | PLLM | (PLLN << RCC_PLLCFGR_PLLN_Pos) | PLLR);
}

#if defined(RCC_PLLP_SUPPORT)
#if defined(RCC_PLLP_DIV_2_31_SUPPORT)
   
                                                   
                                                                   
                                               
                                                             
                                                    
                                                                    
                                                                    
                                                                    
                                                                  
                                                                     
                                           
                                          
                                          
                                          
                                                                   
                                       
                                       
                                       
                                       
                                       
                                       
                                       
                                       
                                           
                                            
                                            
                                            
                                            
                                            
                                            
                                            
   
                                                 
                                                             
                                                                   
                                       
                                       
                                       
                                       
                                       
                                       
                                       
                                       
                                        
                                        
                                        
                                        
                                        
                                        
                                        
                                        
                                        
                                        
                                        
                                        
                                        
                                        
                                        
                                        
                                        
                                        
                                        
                                        
                                        
                                        
                
    
#else
   
                                                   
                                                                     
                                                 
                                                               
                                                      
                                                                    
                                                                    
                                                                    
                                                                  
                                                                     
                                           
                                          
                                          
                                          
                                                                   
                                       
                                       
                                       
                                       
                                       
                                       
                                       
                                       
                                 
                                                                   
                                       
                                        
                
    
#endif                                
__STATIC_INLINE void LL_RCC_PLL_ConfigDomain_SAI(uint32_t Source, uint32_t PLLM, uint32_t PLLN, uint32_t PLLP)
{
#if defined(RCC_PLLP_DIV_2_31_SUPPORT)
  MODIFY_REG(RCC->PLLCFGR, RCC_PLLCFGR_PLLSRC | RCC_PLLCFGR_PLLM | RCC_PLLCFGR_PLLN | RCC_PLLCFGR_PLLPDIV,
             Source | PLLM | (PLLN << RCC_PLLCFGR_PLLN_Pos) | PLLP);
#else
  MODIFY_REG(RCC->PLLCFGR, RCC_PLLCFGR_PLLSRC | RCC_PLLCFGR_PLLM | RCC_PLLCFGR_PLLN | RCC_PLLCFGR_PLLP,
             Source | PLLM | (PLLN << RCC_PLLCFGR_PLLN_Pos) | PLLP);
#endif                                
}
#endif                       

   
                                                     
                                                                   
                                               
                                                             
                                                   
                                                                    
                                                                    
                                                                    
                                                                  
                                                                     
                                           
                                          
                                          
                                          
                                                                   
                                       
                                       
                                       
                                       
                                       
                                       
                                       
                                       
                                           
                                            
                                            
                                            
                                            
                                            
                                            
                                            
   
                                                 
                                                             
                                                                   
                                       
                                       
                                       
                                       
                
    
__STATIC_INLINE void LL_RCC_PLL_ConfigDomain_48M(uint32_t Source, uint32_t PLLM, uint32_t PLLN, uint32_t PLLQ)
{
  MODIFY_REG(RCC->PLLCFGR, RCC_PLLCFGR_PLLSRC | RCC_PLLCFGR_PLLM | RCC_PLLCFGR_PLLN | RCC_PLLCFGR_PLLQ,
             Source | PLLM | (PLLN << RCC_PLLCFGR_PLLN_Pos) | PLLQ);
}

   
                                      
                                                               
                                                                        
                                           
                                          
                                          
                                          
                
    
__STATIC_INLINE void LL_RCC_PLL_SetMainSource(uint32_t PLLSource)
{
  MODIFY_REG(RCC->PLLCFGR, RCC_PLLCFGR_PLLSRC, PLLSource);
}

   
                                                        
                                                               
                                                              
                                           
                                          
                                          
                                          
    
__STATIC_INLINE uint32_t LL_RCC_PLL_GetMainSource(void)
{
  return (uint32_t)(READ_BIT(RCC->PLLCFGR, RCC_PLLCFGR_PLLSRC));
}

   
                                                      
                                                      
                                                        
    
__STATIC_INLINE uint32_t LL_RCC_PLL_GetN(void)
{
  return (uint32_t)(READ_BIT(RCC->PLLCFGR, RCC_PLLCFGR_PLLN) >>  RCC_PLLCFGR_PLLN_Pos);
}

#if defined(RCC_PLLP_SUPPORT)
#if defined(RCC_PLLP_DIV_2_31_SUPPORT)
   
                                                 
                                                   
                                                      
                                                              
                                       
                                       
                                       
                                       
                                       
                                       
                                       
                                       
                                        
                                        
                                        
                                        
                                        
                                        
                                        
                                        
                                        
                                        
                                        
                                        
                                        
                                        
                                        
                                        
                                        
                                        
                                        
                                        
                                        
                                        
    
__STATIC_INLINE uint32_t LL_RCC_PLL_GetP(void)
{
  return (uint32_t)(READ_BIT(RCC->PLLCFGR, RCC_PLLCFGR_PLLPDIV));
}
#else
   
                                                 
                                                   
                                                      
                                                              
                                       
                                        
    
__STATIC_INLINE uint32_t LL_RCC_PLL_GetP(void)
{
  return (uint32_t)(READ_BIT(RCC->PLLCFGR, RCC_PLLCFGR_PLLP));
}
#endif                                
#endif                       

   
                                                 
                                                                         
                                                      
                                                              
                                       
                                       
                                       
                                       
    
__STATIC_INLINE uint32_t LL_RCC_PLL_GetQ(void)
{
  return (uint32_t)(READ_BIT(RCC->PLLCFGR, RCC_PLLCFGR_PLLQ));
}

   
                                                 
                                        
                                                      
                                                              
                                       
                                       
                                       
                                       
    
__STATIC_INLINE uint32_t LL_RCC_PLL_GetR(void)
{
  return (uint32_t)(READ_BIT(RCC->PLLCFGR, RCC_PLLCFGR_PLLR));
}

   
                                                              
                                                            
                                                              
                                       
                                       
                                       
                                       
                                       
                                       
                                       
                                       
                                           
                                            
                                            
                                            
                                            
                                            
                                            
                                            
   
                                                 
    
__STATIC_INLINE uint32_t LL_RCC_PLL_GetDivider(void)
{
  return (uint32_t)(READ_BIT(RCC->PLLCFGR, RCC_PLLCFGR_PLLM));
}

#if defined(RCC_PLLP_SUPPORT)
   
                                                        
                                                                  
                
    
__STATIC_INLINE void LL_RCC_PLL_EnableDomain_SAI(void)
{
  SET_BIT(RCC->PLLCFGR, RCC_PLLCFGR_PLLPEN);
}

   
                                                         
                                                                   
               
                                                                
                                
                                                                   
                
    
__STATIC_INLINE void LL_RCC_PLL_DisableDomain_SAI(void)
{
  CLEAR_BIT(RCC->PLLCFGR, RCC_PLLCFGR_PLLPEN);
}

   
                                                                     
                                                                     
                                  
    
__STATIC_INLINE uint32_t LL_RCC_PLL_IsEnabledDomain_SAI(void)
{
  return ((READ_BIT(RCC->PLLCFGR, RCC_PLLCFGR_PLLPEN) == (RCC_PLLCFGR_PLLPEN)) ? 1UL : 0UL);
}

#endif                       

   
                                                          
                                                                  
                
    
__STATIC_INLINE void LL_RCC_PLL_EnableDomain_48M(void)
{
  SET_BIT(RCC->PLLCFGR, RCC_PLLCFGR_PLLQEN);
}

   
                                                           
                                                                   
               
                                                                
                                
                                                                   
                
    
__STATIC_INLINE void LL_RCC_PLL_DisableDomain_48M(void)
{
  CLEAR_BIT(RCC->PLLCFGR, RCC_PLLCFGR_PLLQEN);
}

   
                                                                       
                                                                     
                                  
    
__STATIC_INLINE uint32_t LL_RCC_PLL_IsEnabledDomain_48M(void)
{
  return ((READ_BIT(RCC->PLLCFGR, RCC_PLLCFGR_PLLQEN) == (RCC_PLLCFGR_PLLQEN)) ? 1UL : 0UL);
}

   
                                                     
                                                                  
                
    
__STATIC_INLINE void LL_RCC_PLL_EnableDomain_SYS(void)
{
  SET_BIT(RCC->PLLCFGR, RCC_PLLCFGR_PLLREN);
}

   
                                                      
                                                                   
               
                                                                
                                         
                                                                   
                
    
__STATIC_INLINE void LL_RCC_PLL_DisableDomain_SYS(void)
{
  CLEAR_BIT(RCC->PLLCFGR, RCC_PLLCFGR_PLLREN);
}

   
                                                                        
                                                                     
                                  
    
__STATIC_INLINE uint32_t LL_RCC_PLL_IsEnabledDomain_SYS(void)
{
  return ((READ_BIT(RCC->PLLCFGR, RCC_PLLCFGR_PLLREN) == (RCC_PLLCFGR_PLLREN)) ? 1UL : 0UL);
}

   
      
    

#if defined(RCC_PLLSAI1_SUPPORT)
                                       
      
    

   
                          
                                                            
                
    
__STATIC_INLINE void LL_RCC_PLLSAI1_Enable(void)
{
  SET_BIT(RCC->CR, RCC_CR_PLLSAI1ON);
}

   
                           
                                                             
                
    
__STATIC_INLINE void LL_RCC_PLLSAI1_Disable(void)
{
  CLEAR_BIT(RCC->CR, RCC_CR_PLLSAI1ON);
}

   
                                  
                                                             
                                  
    
__STATIC_INLINE uint32_t LL_RCC_PLLSAI1_IsReady(void)
{
  return ((READ_BIT(RCC->CR, RCC_CR_PLLSAI1RDY) == RCC_CR_PLLSAI1RDY) ? 1UL : 0UL);
}

#if defined(RCC_PLLSAI1M_DIV_1_16_SUPPORT)
   
                                                         
                                                                                        
                                                                                  
                                                   
                                                                        
                                                                        
                                                                        
                                                                      
                                                                     
                                           
                                          
                                          
                                          
                                                                   
                                           
                                           
                                           
                                           
                                           
                                           
                                           
                                           
                                           
                                            
                                            
                                            
                                            
                                            
                                            
                                            
                                                             
                                                                   
                                           
                                           
                                           
                                           
                
    
__STATIC_INLINE void LL_RCC_PLLSAI1_ConfigDomain_48M(uint32_t Source, uint32_t PLLM, uint32_t PLLN, uint32_t PLLQ)
{
  MODIFY_REG(RCC->PLLCFGR, RCC_PLLCFGR_PLLSRC, Source);
  MODIFY_REG(RCC->PLLSAI1CFGR, RCC_PLLSAI1CFGR_PLLSAI1M | RCC_PLLSAI1CFGR_PLLSAI1N | RCC_PLLSAI1CFGR_PLLSAI1Q,
             PLLM | (PLLN << RCC_PLLSAI1CFGR_PLLSAI1N_Pos) | PLLQ);
}
#else
   
                                                         
                                                                   
                                               
                                                                         
                                                   
                                                                        
                                                                        
                                                                        
                                                                      
                                                                     
                                           
                                          
                                          
                                          
                                                                   
                                       
                                       
                                       
                                       
                                       
                                       
                                       
                                       
                                                             
                                                                   
                                           
                                           
                                           
                                           
                
    
__STATIC_INLINE void LL_RCC_PLLSAI1_ConfigDomain_48M(uint32_t Source, uint32_t PLLM, uint32_t PLLN, uint32_t PLLQ)
{
  MODIFY_REG(RCC->PLLCFGR, RCC_PLLCFGR_PLLSRC | RCC_PLLCFGR_PLLM, Source | PLLM);
  MODIFY_REG(RCC->PLLSAI1CFGR, RCC_PLLSAI1CFGR_PLLSAI1N | RCC_PLLSAI1CFGR_PLLSAI1Q, PLLN << RCC_PLLSAI1CFGR_PLLSAI1N_Pos | PLLQ);
}
#endif                                    

#if defined(RCC_PLLSAI1M_DIV_1_16_SUPPORT) && defined(RCC_PLLSAI1P_DIV_2_31_SUPPORT)
   
                                                       
                                                                                        
                                                                                     
                                                
                                                                        
                                                                        
                                                                        
                                                                      
                                                                     
                                           
                                          
                                          
                                          
                                                                   
                                           
                                           
                                           
                                           
                                           
                                           
                                           
                                           
                                           
                                            
                                            
                                            
                                            
                                            
                                            
                                            
                                                             
                                                                   
                                           
                                           
                                           
                                           
                                           
                                           
                                           
                                           
                                            
                                            
                                            
                                            
                                            
                                            
                                            
                                            
                                            
                                            
                                            
                                            
                                            
                                            
                                            
                                            
                                            
                                            
                                            
                                            
                                            
                                            
                
    
__STATIC_INLINE void LL_RCC_PLLSAI1_ConfigDomain_SAI(uint32_t Source, uint32_t PLLM, uint32_t PLLN, uint32_t PLLP)
{
  MODIFY_REG(RCC->PLLCFGR, RCC_PLLCFGR_PLLSRC, Source);
  MODIFY_REG(RCC->PLLSAI1CFGR, RCC_PLLSAI1CFGR_PLLSAI1M | RCC_PLLSAI1CFGR_PLLSAI1N | RCC_PLLSAI1CFGR_PLLSAI1PDIV,
             PLLM | (PLLN << RCC_PLLSAI1CFGR_PLLSAI1N_Pos) | PLLP);
}
#elif defined(RCC_PLLSAI1P_DIV_2_31_SUPPORT)
   
                                                       
                                                                   
                                               
                                                                            
                                                    
                                                                        
                                                                        
                                                                        
                                                                      
                                                                     
                                           
                                          
                                          
                                          
                                                                   
                                       
                                       
                                       
                                       
                                       
                                       
                                       
                                       
                                                             
                                                                   
                                           
                                           
                                           
                                           
                                           
                                           
                                           
                                           
                                            
                                            
                                            
                                            
                                            
                                            
                                            
                                            
                                            
                                            
                                            
                                            
                                            
                                            
                                            
                                            
                                            
                                            
                                            
                                            
                                            
                                            
                
    
__STATIC_INLINE void LL_RCC_PLLSAI1_ConfigDomain_SAI(uint32_t Source, uint32_t PLLM, uint32_t PLLN, uint32_t PLLP)
{
  MODIFY_REG(RCC->PLLCFGR, RCC_PLLCFGR_PLLSRC | RCC_PLLCFGR_PLLM, Source | PLLM);
  MODIFY_REG(RCC->PLLSAI1CFGR, RCC_PLLSAI1CFGR_PLLSAI1N | RCC_PLLSAI1CFGR_PLLSAI1PDIV,
             PLLN << RCC_PLLSAI1CFGR_PLLSAI1N_Pos | PLLP);
}
#else
   
                                                       
                                                                   
                                               
                                                                         
                                                    
                                                                        
                                                                        
                                                                        
                                                                      
                                                                     
                                           
                                          
                                          
                                          
                                                                   
                                       
                                       
                                       
                                       
                                       
                                       
                                       
                                       
                                 
                                                                   
                                           
                                            
                
    
__STATIC_INLINE void LL_RCC_PLLSAI1_ConfigDomain_SAI(uint32_t Source, uint32_t PLLM, uint32_t PLLN, uint32_t PLLP)
{
  MODIFY_REG(RCC->PLLCFGR, RCC_PLLCFGR_PLLSRC | RCC_PLLCFGR_PLLM, Source | PLLM);
  MODIFY_REG(RCC->PLLSAI1CFGR, RCC_PLLSAI1CFGR_PLLSAI1N | RCC_PLLSAI1CFGR_PLLSAI1P, PLLN << RCC_PLLSAI1CFGR_PLLSAI1N_Pos | PLLP);
}
#endif                                                                     

#if defined(RCC_PLLSAI1M_DIV_1_16_SUPPORT)
   
                                                       
                                                                                        
                                                                                  
                                       
                                                                        
                                                                        
                                                                        
                                                                      
                                                                     
                                           
                                          
                                          
                                          
                                                                   
                                           
                                           
                                           
                                           
                                           
                                           
                                           
                                           
                                           
                                            
                                            
                                            
                                            
                                            
                                            
                                            
                                                             
                                                                   
                                           
                                           
                                           
                                           
                
    
__STATIC_INLINE void LL_RCC_PLLSAI1_ConfigDomain_ADC(uint32_t Source, uint32_t PLLM, uint32_t PLLN, uint32_t PLLR)
{
  MODIFY_REG(RCC->PLLCFGR, RCC_PLLCFGR_PLLSRC, Source);
  MODIFY_REG(RCC->PLLSAI1CFGR, RCC_PLLSAI1CFGR_PLLSAI1M | RCC_PLLSAI1CFGR_PLLSAI1N | RCC_PLLSAI1CFGR_PLLSAI1R,
             PLLM | (PLLN << RCC_PLLSAI1CFGR_PLLSAI1N_Pos) | PLLR);
}
#else
   
                                                       
                                                                   
                                               
                                                                 
                                       
                                                                        
                                                                        
                                                                        
                                                                      
                                                                     
                                           
                                          
                                          
                                          
                                                                   
                                       
                                       
                                       
                                       
                                       
                                       
                                       
                                       
                                                             
                                                                   
                                           
                                           
                                           
                                           
                
    
__STATIC_INLINE void LL_RCC_PLLSAI1_ConfigDomain_ADC(uint32_t Source, uint32_t PLLM, uint32_t PLLN, uint32_t PLLR)
{
  MODIFY_REG(RCC->PLLCFGR, RCC_PLLCFGR_PLLSRC | RCC_PLLCFGR_PLLM, Source | PLLM);
  MODIFY_REG(RCC->PLLSAI1CFGR, RCC_PLLSAI1CFGR_PLLSAI1N | RCC_PLLSAI1CFGR_PLLSAI1R, PLLN << RCC_PLLSAI1CFGR_PLLSAI1N_Pos | PLLR);
}
#endif                                    

   
                                                     
                                                          
                                                        
    
__STATIC_INLINE uint32_t LL_RCC_PLLSAI1_GetN(void)
{
  return (uint32_t)(READ_BIT(RCC->PLLSAI1CFGR, RCC_PLLSAI1CFGR_PLLSAI1N) >> RCC_PLLSAI1CFGR_PLLSAI1N_Pos);
}

#if defined(RCC_PLLSAI1P_DIV_2_31_SUPPORT)
   
                                                    
                                                       
                                                             
                                                              
                                           
                                           
                                           
                                           
                                           
                                           
                                           
                                           
                                            
                                            
                                            
                                            
                                            
                                            
                                            
                                            
                                            
                                            
                                            
                                            
                                            
                                            
                                            
                                            
                                            
                                            
                                            
                                            
                                            
                                            
    
__STATIC_INLINE uint32_t LL_RCC_PLLSAI1_GetP(void)
{
  return (uint32_t)(READ_BIT(RCC->PLLSAI1CFGR, RCC_PLLSAI1CFGR_PLLSAI1PDIV));
}
#else
   
                                                    
                                                       
                                                          
                                                              
                                           
                                            
    
__STATIC_INLINE uint32_t LL_RCC_PLLSAI1_GetP(void)
{
  return (uint32_t)(READ_BIT(RCC->PLLSAI1CFGR, RCC_PLLSAI1CFGR_PLLSAI1P));
}
#endif                                    

   
                                                    
                                                                     
                                                          
                                                              
                                           
                                           
                                           
                                           
    
__STATIC_INLINE uint32_t LL_RCC_PLLSAI1_GetQ(void)
{
  return (uint32_t)(READ_BIT(RCC->PLLSAI1CFGR, RCC_PLLSAI1CFGR_PLLSAI1Q));
}

   
                                                   
                                         
                                                          
                                                              
                                           
                                           
                                           
                                           
    
__STATIC_INLINE uint32_t LL_RCC_PLLSAI1_GetR(void)
{
  return (uint32_t)(READ_BIT(RCC->PLLSAI1CFGR, RCC_PLLSAI1CFGR_PLLSAI1R));
}

#if  defined(RCC_PLLSAI1M_DIV_1_16_SUPPORT)
   
                                               
                                                                
                                                              
                                           
                                           
                                           
                                           
                                           
                                           
                                           
                                           
                                           
                                            
                                            
                                            
                                            
                                            
                                            
                                            
    
__STATIC_INLINE uint32_t LL_RCC_PLLSAI1_GetDivider(void)
{
  return (uint32_t)(READ_BIT(RCC->PLLSAI1CFGR, RCC_PLLSAI1CFGR_PLLSAI1M));
}
#endif                                    

   
                                                            
                                                                      
                
    
__STATIC_INLINE void LL_RCC_PLLSAI1_EnableDomain_SAI(void)
{
  SET_BIT(RCC->PLLSAI1CFGR, RCC_PLLSAI1CFGR_PLLSAI1PEN);
}

   
                                                             
                                                         
                                
                                                                       
                
    
__STATIC_INLINE void LL_RCC_PLLSAI1_DisableDomain_SAI(void)
{
  CLEAR_BIT(RCC->PLLSAI1CFGR, RCC_PLLSAI1CFGR_PLLSAI1PEN);
}

   
                                                                         
                                                                                 
                                  
    
__STATIC_INLINE uint32_t LL_RCC_PLLSAI1_IsEnabledDomain_SAI(void)
{
  return ((READ_BIT(RCC->PLLSAI1CFGR, RCC_PLLSAI1CFGR_PLLSAI1PEN) == (RCC_PLLSAI1CFGR_PLLSAI1PEN)) ? 1UL : 0UL);
}

   
                                                              
                                                                      
                
    
__STATIC_INLINE void LL_RCC_PLLSAI1_EnableDomain_48M(void)
{
  SET_BIT(RCC->PLLSAI1CFGR, RCC_PLLSAI1CFGR_PLLSAI1QEN);
}

   
                                                               
                                                         
                                
                                                                       
                
    
__STATIC_INLINE void LL_RCC_PLLSAI1_DisableDomain_48M(void)
{
  CLEAR_BIT(RCC->PLLSAI1CFGR, RCC_PLLSAI1CFGR_PLLSAI1QEN);
}

   
                                                                         
                                                                                 
                                  
    
__STATIC_INLINE uint32_t LL_RCC_PLLSAI1_IsEnabledDomain_48M(void)
{
  return ((READ_BIT(RCC->PLLSAI1CFGR, RCC_PLLSAI1CFGR_PLLSAI1QEN) == (RCC_PLLSAI1CFGR_PLLSAI1QEN)) ? 1UL : 0UL);
}

   
                                                            
                                                                      
                
    
__STATIC_INLINE void LL_RCC_PLLSAI1_EnableDomain_ADC(void)
{
  SET_BIT(RCC->PLLSAI1CFGR, RCC_PLLSAI1CFGR_PLLSAI1REN);
}

   
                                                             
                                                         
                                             
                                                                       
                
    
__STATIC_INLINE void LL_RCC_PLLSAI1_DisableDomain_ADC(void)
{
  CLEAR_BIT(RCC->PLLSAI1CFGR, RCC_PLLSAI1CFGR_PLLSAI1REN);
}

   
                                                                         
                                                                                 
                                  
    
__STATIC_INLINE uint32_t LL_RCC_PLLSAI1_IsEnabledDomain_ADC(void)
{
  return ((READ_BIT(RCC->PLLSAI1CFGR, RCC_PLLSAI1CFGR_PLLSAI1REN) == (RCC_PLLSAI1CFGR_PLLSAI1REN)) ? 1UL : 0UL);
}

   
      
    
#endif                          

#if defined(RCC_PLLSAI2_SUPPORT)
                                       
      
    

   
                          
                                                            
                
    
__STATIC_INLINE void LL_RCC_PLLSAI2_Enable(void)
{
  SET_BIT(RCC->CR, RCC_CR_PLLSAI2ON);
}

   
                           
                                                             
                
    
__STATIC_INLINE void LL_RCC_PLLSAI2_Disable(void)
{
  CLEAR_BIT(RCC->CR, RCC_CR_PLLSAI2ON);
}

   
                                  
                                                             
                                  
    
__STATIC_INLINE uint32_t LL_RCC_PLLSAI2_IsReady(void)
{
  return ((READ_BIT(RCC->CR, RCC_CR_PLLSAI2RDY) == RCC_CR_PLLSAI2RDY) ? 1UL : 0UL);
}

#if defined(RCC_PLLSAI2M_DIV_1_16_SUPPORT) && defined(RCC_PLLSAI2P_DIV_2_31_SUPPORT)
   
                                                       
                                                                                        
                                                                                     
                                                
                                                                        
                                                                        
                                                                        
                                                                      
                                                                     
                                           
                                          
                                          
                                          
                                                                   
                                           
                                           
                                           
                                           
                                           
                                           
                                           
                                           
                                           
                                            
                                            
                                            
                                            
                                            
                                            
                                            
                                                             
                                                                   
                                           
                                           
                                           
                                           
                                           
                                           
                                           
                                           
                                            
                                            
                                            
                                            
                                            
                                            
                                            
                                            
                                            
                                            
                                            
                                            
                                            
                                            
                                            
                                            
                                            
                                            
                                            
                                            
                                            
                                            
                
    
__STATIC_INLINE void LL_RCC_PLLSAI2_ConfigDomain_SAI(uint32_t Source, uint32_t PLLM, uint32_t PLLN, uint32_t PLLP)
{
  MODIFY_REG(RCC->PLLCFGR, RCC_PLLCFGR_PLLSRC, Source);
  MODIFY_REG(RCC->PLLSAI2CFGR, RCC_PLLSAI2CFGR_PLLSAI2M | RCC_PLLSAI2CFGR_PLLSAI2N | RCC_PLLSAI2CFGR_PLLSAI2PDIV,
             PLLM | (PLLN << RCC_PLLSAI2CFGR_PLLSAI2N_Pos) | PLLP);
}
#elif defined(RCC_PLLSAI2P_DIV_2_31_SUPPORT)
   
                                                       
                                                                   
                                           
                                                                            
                                                
                                                                        
                                                                        
                                                                        
                                                                      
                                                                     
                                           
                                          
                                          
                                          
                                                                   
                                       
                                       
                                       
                                       
                                       
                                       
                                       
                                       
                                                             
                                                                   
                                           
                                           
                                           
                                           
                                           
                                           
                                           
                                           
                                            
                                            
                                            
                                            
                                            
                                            
                                            
                                            
                                            
                                            
                                            
                                            
                                            
                                            
                                            
                                            
                                            
                                            
                                            
                                            
                                            
                                            
                
    
__STATIC_INLINE void LL_RCC_PLLSAI2_ConfigDomain_SAI(uint32_t Source, uint32_t PLLM, uint32_t PLLN, uint32_t PLLP)
{
  MODIFY_REG(RCC->PLLCFGR, RCC_PLLCFGR_PLLSRC | RCC_PLLCFGR_PLLM, Source | PLLM);
  MODIFY_REG(RCC->PLLSAI2CFGR, RCC_PLLSAI2CFGR_PLLSAI2N | RCC_PLLSAI2CFGR_PLLSAI2PDIV, PLLN << RCC_PLLSAI2CFGR_PLLSAI2N_Pos | PLLP);
}
#else
   
                                                       
                                                                   
                                           
                                                                         
                                                
                                                                        
                                                                        
                                                                        
                                                                      
                                                                     
                                           
                                          
                                          
                                          
                                                                   
                                       
                                       
                                       
                                       
                                       
                                       
                                       
                                       
                                 
                                                                   
                                           
                                            
                
    
__STATIC_INLINE void LL_RCC_PLLSAI2_ConfigDomain_SAI(uint32_t Source, uint32_t PLLM, uint32_t PLLN, uint32_t PLLP)
{
  MODIFY_REG(RCC->PLLCFGR, RCC_PLLCFGR_PLLSRC | RCC_PLLCFGR_PLLM, Source | PLLM);
  MODIFY_REG(RCC->PLLSAI2CFGR, RCC_PLLSAI2CFGR_PLLSAI2N | RCC_PLLSAI2CFGR_PLLSAI2P, PLLN << RCC_PLLSAI2CFGR_PLLSAI2N_Pos | PLLP);
}
#endif                                                                     

#if defined(DSI)
   
                                                       
                                                                                        
                                                                                  
                                       
                                                                        
                                                                        
                                                                        
                                                                      
                                                                     
                                           
                                          
                                          
                                          
                                                                   
                                           
                                           
                                           
                                           
                                           
                                           
                                           
                                           
                                           
                                            
                                            
                                            
                                            
                                            
                                            
                                            
                                  
                                                                   
                                           
                                           
                                           
                                           
                
    
__STATIC_INLINE void LL_RCC_PLLSAI2_ConfigDomain_DSI(uint32_t Source, uint32_t PLLM, uint32_t PLLN, uint32_t PLLQ)
{
  MODIFY_REG(RCC->PLLCFGR, RCC_PLLCFGR_PLLSRC, Source);
  MODIFY_REG(RCC->PLLSAI2CFGR, RCC_PLLSAI2CFGR_PLLSAI2M | RCC_PLLSAI2CFGR_PLLSAI2N | RCC_PLLSAI2CFGR_PLLSAI2Q,
             (PLLN << RCC_PLLSAI2CFGR_PLLSAI2N_Pos) | PLLQ | PLLM);
}
#endif          

#if defined(LTDC)
   
                                                        
                                                                                        
                                                                                  
                                        
                                                                         
                                                                         
                                                                         
                                                                         
                                                                       
                                                                     
                                           
                                          
                                          
                                          
                                                                   
                                           
                                           
                                           
                                           
                                           
                                           
                                           
                                           
                                           
                                            
                                            
                                            
                                            
                                            
                                            
                                            
                                  
                                                                   
                                           
                                           
                                           
                                           
                                                                      
                                              
                                              
                                              
                                               
                
    
__STATIC_INLINE void LL_RCC_PLLSAI2_ConfigDomain_LTDC(uint32_t Source, uint32_t PLLM, uint32_t PLLN, uint32_t PLLR, uint32_t PLLDIVR)
{
  MODIFY_REG(RCC->PLLCFGR, RCC_PLLCFGR_PLLSRC, Source);
  MODIFY_REG(RCC->PLLSAI2CFGR, RCC_PLLSAI2CFGR_PLLSAI2M | RCC_PLLSAI2CFGR_PLLSAI2N | RCC_PLLSAI2CFGR_PLLSAI2R,
             (PLLN << RCC_PLLSAI2CFGR_PLLSAI2N_Pos) | PLLR | PLLM);
  MODIFY_REG(RCC->CCIPR2, RCC_CCIPR2_PLLSAI2DIVR, PLLDIVR);
}
#else
   
                                                       
                                                                   
                                           
                                                                         
                                       
                                                                        
                                                                        
                                                                        
                                                                      
                                                                     
                                           
                                          
                                          
                                          
                                                                   
                                       
                                       
                                       
                                       
                                       
                                       
                                       
                                       
                                 
                                                                   
                                           
                                           
                                           
                                           
                
    
__STATIC_INLINE void LL_RCC_PLLSAI2_ConfigDomain_ADC(uint32_t Source, uint32_t PLLM, uint32_t PLLN, uint32_t PLLR)
{
  MODIFY_REG(RCC->PLLCFGR, RCC_PLLCFGR_PLLSRC | RCC_PLLCFGR_PLLM, Source | PLLM);
  MODIFY_REG(RCC->PLLSAI2CFGR, RCC_PLLSAI2CFGR_PLLSAI2N | RCC_PLLSAI2CFGR_PLLSAI2R, PLLN << RCC_PLLSAI2CFGR_PLLSAI2N_Pos | PLLR);
}
#endif           

   
                                                     
                                                          
                                                        
    
__STATIC_INLINE uint32_t LL_RCC_PLLSAI2_GetN(void)
{
  return (uint32_t)(READ_BIT(RCC->PLLSAI2CFGR, RCC_PLLSAI2CFGR_PLLSAI2N) >> RCC_PLLSAI2CFGR_PLLSAI2N_Pos);
}

#if defined(RCC_PLLSAI2P_DIV_2_31_SUPPORT)
   
                                                    
                                                   
                                                           
                                                              
                                           
                                           
                                           
                                           
                                           
                                           
                                           
                                           
                                            
                                            
                                            
                                            
                                            
                                            
                                            
                                            
                                            
                                            
                                            
                                            
                                            
                                            
                                            
                                            
                                            
                                            
                                            
                                            
                                            
                                            
    
__STATIC_INLINE uint32_t LL_RCC_PLLSAI2_GetP(void)
{
  return (uint32_t)(READ_BIT(RCC->PLLSAI2CFGR, RCC_PLLSAI2CFGR_PLLSAI2PDIV));
}
#else
   
                                                    
                                                   
                                                          
                                                              
                                           
                                            
    
__STATIC_INLINE uint32_t LL_RCC_PLLSAI2_GetP(void)
{
  return (uint32_t)(READ_BIT(RCC->PLLSAI2CFGR, RCC_PLLSAI2CFGR_PLLSAI2P));
}
#endif                                    

#if defined(RCC_PLLSAI2Q_DIV_SUPPORT)
   
                                            
                                        
                                                          
                                                              
                                           
                                           
                                           
                                           
    
__STATIC_INLINE uint32_t LL_RCC_PLLSAI2_GetQ(void)
{
  return (uint32_t)(READ_BIT(RCC->PLLSAI2CFGR, RCC_PLLSAI2CFGR_PLLSAI2Q));
}
#endif                               

   
                                                    
                                                                                        
                                                          
                                                              
                                           
                                           
                                           
                                           
    
__STATIC_INLINE uint32_t LL_RCC_PLLSAI2_GetR(void)
{
  return (uint32_t)(READ_BIT(RCC->PLLSAI2CFGR, RCC_PLLSAI2CFGR_PLLSAI2R));
}

#if  defined(RCC_PLLSAI2M_DIV_1_16_SUPPORT)
   
                                               
                                                                
                                                              
                                           
                                           
                                           
                                           
                                           
                                           
                                           
                                           
                                           
                                            
                                            
                                            
                                            
                                            
                                            
                                            
    
__STATIC_INLINE uint32_t LL_RCC_PLLSAI2_GetDivider(void)
{
  return (uint32_t)(READ_BIT(RCC->PLLSAI2CFGR, RCC_PLLSAI2CFGR_PLLSAI2M));
}
#endif                                    

#if defined(RCC_CCIPR2_PLLSAI2DIVR)
   
                                                       
                                    
                                                           
                                                              
                                              
                                              
                                              
                                               
    
__STATIC_INLINE uint32_t LL_RCC_PLLSAI2_GetDIVR(void)
{
  return (uint32_t)(READ_BIT(RCC->CCIPR2, RCC_CCIPR2_PLLSAI2DIVR));
}
#endif                             

   
                                                            
                                                                      
                
    
__STATIC_INLINE void LL_RCC_PLLSAI2_EnableDomain_SAI(void)
{
  SET_BIT(RCC->PLLSAI2CFGR, RCC_PLLSAI2CFGR_PLLSAI2PEN);
}

   
                                                             
                                                         
                                
                                                                       
                
    
__STATIC_INLINE void LL_RCC_PLLSAI2_DisableDomain_SAI(void)
{
  CLEAR_BIT(RCC->PLLSAI2CFGR, RCC_PLLSAI2CFGR_PLLSAI2PEN);
}

   
                                                                         
                                                                                 
                                  
    
__STATIC_INLINE uint32_t LL_RCC_PLLSAI2_IsEnabledDomain_SAI(void)
{
  return ((READ_BIT(RCC->PLLSAI2CFGR, RCC_PLLSAI2CFGR_PLLSAI2PEN) == (RCC_PLLSAI2CFGR_PLLSAI2PEN)) ? 1UL : 0UL);
}

#if defined(DSI)
   
                                                            
                                                                      
                
    
__STATIC_INLINE void LL_RCC_PLLSAI2_EnableDomain_DSI(void)
{
  SET_BIT(RCC->PLLSAI2CFGR, RCC_PLLSAI2CFGR_PLLSAI2QEN);
}

   
                                                             
                                                         
                                             
                                                                       
                
    
__STATIC_INLINE void LL_RCC_PLLSAI2_DisableDomain_DSI(void)
{
  CLEAR_BIT(RCC->PLLSAI2CFGR, RCC_PLLSAI2CFGR_PLLSAI2QEN);
}

   
                                                                         
                                                                                 
                                  
    
__STATIC_INLINE uint32_t LL_RCC_PLLSAI2_IsEnabledDomain_DSI(void)
{
  return ((READ_BIT(RCC->PLLSAI2CFGR, RCC_PLLSAI2CFGR_PLLSAI2QEN) == (RCC_PLLSAI2CFGR_PLLSAI2QEN)) ? 1UL : 0UL);
}
#endif          

#if defined(LTDC)
   
                                                             
                                                                       
                
    
__STATIC_INLINE void LL_RCC_PLLSAI2_EnableDomain_LTDC(void)
{
  SET_BIT(RCC->PLLSAI2CFGR, RCC_PLLSAI2CFGR_PLLSAI2REN);
}

   
                                                              
                                                         
                                             
                                                                        
                
    
__STATIC_INLINE void LL_RCC_PLLSAI2_DisableDomain_LTDC(void)
{
  CLEAR_BIT(RCC->PLLSAI2CFGR, RCC_PLLSAI2CFGR_PLLSAI2REN);
}

   
                                                                          
                                                                                  
                                  
    
__STATIC_INLINE uint32_t LL_RCC_PLLSAI2_IsEnabledDomain_LTDC(void)
{
  return ((READ_BIT(RCC->PLLSAI2CFGR, RCC_PLLSAI2CFGR_PLLSAI2REN) == (RCC_PLLSAI2CFGR_PLLSAI2REN)) ? 1UL : 0UL);
}
#else
   
                                                            
                                                                      
                
    
__STATIC_INLINE void LL_RCC_PLLSAI2_EnableDomain_ADC(void)
{
  SET_BIT(RCC->PLLSAI2CFGR, RCC_PLLSAI2CFGR_PLLSAI2REN);
}

   
                                                             
                                                         
                                             
                                                                       
                
    
__STATIC_INLINE void LL_RCC_PLLSAI2_DisableDomain_ADC(void)
{
  CLEAR_BIT(RCC->PLLSAI2CFGR, RCC_PLLSAI2CFGR_PLLSAI2REN);
}

   
                                                                         
                                                                                 
                                  
    
__STATIC_INLINE uint32_t LL_RCC_PLLSAI2_IsEnabledDomain_ADC(void)
{
  return ((READ_BIT(RCC->PLLSAI2CFGR, RCC_PLLSAI2CFGR_PLLSAI2REN) == (RCC_PLLSAI2CFGR_PLLSAI2REN)) ? 1UL : 0UL);
}
#endif           

   
      
    
#endif                          

#if defined(OCTOSPI1)
                                       
      
    

   
                                        
                                                                          
                                                     
                
    
__STATIC_INLINE void LL_RCC_OCTOSPI1_DelayConfig(uint32_t Delay)
{
  MODIFY_REG(RCC->DLYCFGR, RCC_DLYCFGR_OCTOSPI1_DLY, Delay);
}

#if defined(OCTOSPI2)
   
                                        
                                                                          
                                                     
                
    
__STATIC_INLINE void LL_RCC_OCTOSPI2_DelayConfig(uint32_t Delay)
{
  MODIFY_REG(RCC->DLYCFGR, RCC_DLYCFGR_OCTOSPI2_DLY, (Delay << RCC_DLYCFGR_OCTOSPI2_DLY_Pos));
}
#endif               

   
      
    
#endif               

                                                       
      
    

   
                                          
                                                              
                
    
__STATIC_INLINE void LL_RCC_ClearFlag_LSIRDY(void)
{
  SET_BIT(RCC->CICR, RCC_CICR_LSIRDYC);
}

   
                                          
                                                              
                
    
__STATIC_INLINE void LL_RCC_ClearFlag_LSERDY(void)
{
  SET_BIT(RCC->CICR, RCC_CICR_LSERDYC);
}

   
                                          
                                                              
                
    
__STATIC_INLINE void LL_RCC_ClearFlag_MSIRDY(void)
{
  SET_BIT(RCC->CICR, RCC_CICR_MSIRDYC);
}

   
                                          
                                                              
                
    
__STATIC_INLINE void LL_RCC_ClearFlag_HSIRDY(void)
{
  SET_BIT(RCC->CICR, RCC_CICR_HSIRDYC);
}

   
                                          
                                                              
                
    
__STATIC_INLINE void LL_RCC_ClearFlag_HSERDY(void)
{
  SET_BIT(RCC->CICR, RCC_CICR_HSERDYC);
}

   
                                          
                                                              
                
    
__STATIC_INLINE void LL_RCC_ClearFlag_PLLRDY(void)
{
  SET_BIT(RCC->CICR, RCC_CICR_PLLRDYC);
}

#if defined(RCC_HSI48_SUPPORT)
   
                                            
                                                                 
                
    
__STATIC_INLINE void LL_RCC_ClearFlag_HSI48RDY(void)
{
  SET_BIT(RCC->CICR, RCC_CICR_HSI48RDYC);
}
#endif                        

#if defined(RCC_PLLSAI1_SUPPORT)
   
                                              
                                                                  
                
    
__STATIC_INLINE void LL_RCC_ClearFlag_PLLSAI1RDY(void)
{
  SET_BIT(RCC->CICR, RCC_CICR_PLLSAI1RDYC);
}
#endif                          

#if defined(RCC_PLLSAI2_SUPPORT)
   
                                              
                                                                  
                
    
__STATIC_INLINE void LL_RCC_ClearFlag_PLLSAI2RDY(void)
{
  SET_BIT(RCC->CICR, RCC_CICR_PLLSAI2RDYC);
}
#endif                          

   
                                                      
                                                              
                
    
__STATIC_INLINE void LL_RCC_ClearFlag_HSECSS(void)
{
  SET_BIT(RCC->CICR, RCC_CICR_CSSC);
}

   
                                                          
                                                              
                
    
__STATIC_INLINE void LL_RCC_ClearFlag_LSECSS(void)
{
  SET_BIT(RCC->CICR, RCC_CICR_LSECSSC);
}

   
                                                        
                                                                 
                                  
    
__STATIC_INLINE uint32_t LL_RCC_IsActiveFlag_LSIRDY(void)
{
  return ((READ_BIT(RCC->CIFR, RCC_CIFR_LSIRDYF) == RCC_CIFR_LSIRDYF) ? 1UL : 0UL);
}

   
                                                        
                                                                 
                                  
    
__STATIC_INLINE uint32_t LL_RCC_IsActiveFlag_LSERDY(void)
{
  return ((READ_BIT(RCC->CIFR, RCC_CIFR_LSERDYF) == RCC_CIFR_LSERDYF) ? 1UL : 0UL);
}

   
                                                        
                                                                 
                                  
    
__STATIC_INLINE uint32_t LL_RCC_IsActiveFlag_MSIRDY(void)
{
  return ((READ_BIT(RCC->CIFR, RCC_CIFR_MSIRDYF) == RCC_CIFR_MSIRDYF) ? 1UL : 0UL);
}

   
                                                        
                                                                 
                                  
    
__STATIC_INLINE uint32_t LL_RCC_IsActiveFlag_HSIRDY(void)
{
  return ((READ_BIT(RCC->CIFR, RCC_CIFR_HSIRDYF) == RCC_CIFR_HSIRDYF) ? 1UL : 0UL);
}

   
                                                        
                                                                 
                                  
    
__STATIC_INLINE uint32_t LL_RCC_IsActiveFlag_HSERDY(void)
{
  return ((READ_BIT(RCC->CIFR, RCC_CIFR_HSERDYF) == RCC_CIFR_HSERDYF) ? 1UL : 0UL);
}

   
                                                        
                                                                 
                                  
    
__STATIC_INLINE uint32_t LL_RCC_IsActiveFlag_PLLRDY(void)
{
  return ((READ_BIT(RCC->CIFR, RCC_CIFR_PLLRDYF) == RCC_CIFR_PLLRDYF) ? 1UL : 0UL);
}

#if defined(RCC_HSI48_SUPPORT)
   
                                                          
                                                                   
                                  
    
__STATIC_INLINE uint32_t LL_RCC_IsActiveFlag_HSI48RDY(void)
{
  return ((READ_BIT(RCC->CIFR, RCC_CIFR_HSI48RDYF) == RCC_CIFR_HSI48RDYF) ? 1UL : 0UL);
}
#endif                        

#if defined(RCC_PLLSAI1_SUPPORT)
   
                                                            
                                                                     
                                  
    
__STATIC_INLINE uint32_t LL_RCC_IsActiveFlag_PLLSAI1RDY(void)
{
  return ((READ_BIT(RCC->CIFR, RCC_CIFR_PLLSAI1RDYF) == RCC_CIFR_PLLSAI1RDYF) ? 1UL : 0UL);
}
#endif                          

#if defined(RCC_PLLSAI2_SUPPORT)
   
                                                            
                                                                     
                                  
    
__STATIC_INLINE uint32_t LL_RCC_IsActiveFlag_PLLSAI2RDY(void)
{
  return ((READ_BIT(RCC->CIFR, RCC_CIFR_PLLSAI2RDYF) == RCC_CIFR_PLLSAI2RDYF) ? 1UL : 0UL);
}
#endif                          

   
                                                                    
                                                                 
                                  
    
__STATIC_INLINE uint32_t LL_RCC_IsActiveFlag_HSECSS(void)
{
  return ((READ_BIT(RCC->CIFR, RCC_CIFR_CSSF) == RCC_CIFR_CSSF) ? 1UL : 0UL);
}

   
                                                                        
                                                                 
                                  
    
__STATIC_INLINE uint32_t LL_RCC_IsActiveFlag_LSECSS(void)
{
  return ((READ_BIT(RCC->CIFR, RCC_CIFR_LSECSSF) == RCC_CIFR_LSECSSF) ? 1UL : 0UL);
}

   
                                                     
                                                                
                                  
    
__STATIC_INLINE uint32_t LL_RCC_IsActiveFlag_FWRST(void)
{
  return ((READ_BIT(RCC->CSR, RCC_CSR_FWRSTF) == RCC_CSR_FWRSTF) ? 1UL : 0UL);
}

   
                                                                       
                                                                  
                                  
    
__STATIC_INLINE uint32_t LL_RCC_IsActiveFlag_IWDGRST(void)
{
  return ((READ_BIT(RCC->CSR, RCC_CSR_IWDGRSTF) == RCC_CSR_IWDGRSTF) ? 1UL : 0UL);
}

   
                                                            
                                                                  
                                  
    
__STATIC_INLINE uint32_t LL_RCC_IsActiveFlag_LPWRRST(void)
{
  return ((READ_BIT(RCC->CSR, RCC_CSR_LPWRRSTF) == RCC_CSR_LPWRRSTF) ? 1UL : 0UL);
}

   
                                            
                                                                 
                                  
    
__STATIC_INLINE uint32_t LL_RCC_IsActiveFlag_OBLRST(void)
{
  return ((READ_BIT(RCC->CSR, RCC_CSR_OBLRSTF) == RCC_CSR_OBLRSTF) ? 1UL : 0UL);
}

   
                                                      
                                                                 
                                  
    
__STATIC_INLINE uint32_t LL_RCC_IsActiveFlag_PINRST(void)
{
  return ((READ_BIT(RCC->CSR, RCC_CSR_PINRSTF) == RCC_CSR_PINRSTF) ? 1UL : 0UL);
}

   
                                                           
                                                                 
                                  
    
__STATIC_INLINE uint32_t LL_RCC_IsActiveFlag_SFTRST(void)
{
  return ((READ_BIT(RCC->CSR, RCC_CSR_SFTRSTF) == RCC_CSR_SFTRSTF) ? 1UL : 0UL);
}

   
                                                                  
                                                                  
                                  
    
__STATIC_INLINE uint32_t LL_RCC_IsActiveFlag_WWDGRST(void)
{
  return ((READ_BIT(RCC->CSR, RCC_CSR_WWDGRSTF) == RCC_CSR_WWDGRSTF) ? 1UL : 0UL);
}

   
                                                      
                                                                 
                                  
    
__STATIC_INLINE uint32_t LL_RCC_IsActiveFlag_BORRST(void)
{
  return ((READ_BIT(RCC->CSR, RCC_CSR_BORRSTF) == RCC_CSR_BORRSTF) ? 1UL : 0UL);
}

   
                                                  
                                                             
                
    
__STATIC_INLINE void LL_RCC_ClearResetFlags(void)
{
  SET_BIT(RCC->CSR, RCC_CSR_RMVF);
}

   
      
    

                                                   
      
    

   
                                      
                                                             
                
    
__STATIC_INLINE void LL_RCC_EnableIT_LSIRDY(void)
{
  SET_BIT(RCC->CIER, RCC_CIER_LSIRDYIE);
}

   
                                      
                                                             
                
    
__STATIC_INLINE void LL_RCC_EnableIT_LSERDY(void)
{
  SET_BIT(RCC->CIER, RCC_CIER_LSERDYIE);
}

   
                                      
                                                             
                
    
__STATIC_INLINE void LL_RCC_EnableIT_MSIRDY(void)
{
  SET_BIT(RCC->CIER, RCC_CIER_MSIRDYIE);
}

   
                                      
                                                             
                
    
__STATIC_INLINE void LL_RCC_EnableIT_HSIRDY(void)
{
  SET_BIT(RCC->CIER, RCC_CIER_HSIRDYIE);
}

   
                                      
                                                             
                
    
__STATIC_INLINE void LL_RCC_EnableIT_HSERDY(void)
{
  SET_BIT(RCC->CIER, RCC_CIER_HSERDYIE);
}

   
                                      
                                                             
                
    
__STATIC_INLINE void LL_RCC_EnableIT_PLLRDY(void)
{
  SET_BIT(RCC->CIER, RCC_CIER_PLLRDYIE);
}

#if defined(RCC_HSI48_SUPPORT)
   
                                        
                                                                
                
    
__STATIC_INLINE void LL_RCC_EnableIT_HSI48RDY(void)
{
  SET_BIT(RCC->CIER, RCC_CIER_HSI48RDYIE);
}
#endif                        

#if defined(RCC_PLLSAI1_SUPPORT)
   
                                          
                                                                 
                
    
__STATIC_INLINE void LL_RCC_EnableIT_PLLSAI1RDY(void)
{
  SET_BIT(RCC->CIER, RCC_CIER_PLLSAI1RDYIE);
}
#endif                          

#if defined(RCC_PLLSAI2_SUPPORT)
   
                                          
                                                                 
                
    
__STATIC_INLINE void LL_RCC_EnableIT_PLLSAI2RDY(void)
{
  SET_BIT(RCC->CIER, RCC_CIER_PLLSAI2RDYIE);
}
#endif                          

   
                                                      
                                                             
                
    
__STATIC_INLINE void LL_RCC_EnableIT_LSECSS(void)
{
  SET_BIT(RCC->CIER, RCC_CIER_LSECSSIE);
}

   
                                       
                                                              
                
    
__STATIC_INLINE void LL_RCC_DisableIT_LSIRDY(void)
{
  CLEAR_BIT(RCC->CIER, RCC_CIER_LSIRDYIE);
}

   
                                       
                                                              
                
    
__STATIC_INLINE void LL_RCC_DisableIT_LSERDY(void)
{
  CLEAR_BIT(RCC->CIER, RCC_CIER_LSERDYIE);
}

   
                                       
                                                              
                
    
__STATIC_INLINE void LL_RCC_DisableIT_MSIRDY(void)
{
  CLEAR_BIT(RCC->CIER, RCC_CIER_MSIRDYIE);
}

   
                                       
                                                              
                
    
__STATIC_INLINE void LL_RCC_DisableIT_HSIRDY(void)
{
  CLEAR_BIT(RCC->CIER, RCC_CIER_HSIRDYIE);
}

   
                                       
                                                              
                
    
__STATIC_INLINE void LL_RCC_DisableIT_HSERDY(void)
{
  CLEAR_BIT(RCC->CIER, RCC_CIER_HSERDYIE);
}

   
                                       
                                                              
                
    
__STATIC_INLINE void LL_RCC_DisableIT_PLLRDY(void)
{
  CLEAR_BIT(RCC->CIER, RCC_CIER_PLLRDYIE);
}

#if defined(RCC_HSI48_SUPPORT)
   
                                         
                                                                 
                
    
__STATIC_INLINE void LL_RCC_DisableIT_HSI48RDY(void)
{
  CLEAR_BIT(RCC->CIER, RCC_CIER_HSI48RDYIE);
}
#endif                        

#if defined(RCC_PLLSAI1_SUPPORT)
   
                                           
                                                                  
                
    
__STATIC_INLINE void LL_RCC_DisableIT_PLLSAI1RDY(void)
{
  CLEAR_BIT(RCC->CIER, RCC_CIER_PLLSAI1RDYIE);
}
#endif                          

#if defined(RCC_PLLSAI2_SUPPORT)
   
                                           
                                                                  
                
    
__STATIC_INLINE void LL_RCC_DisableIT_PLLSAI2RDY(void)
{
  CLEAR_BIT(RCC->CIER, RCC_CIER_PLLSAI2RDYIE);
}
#endif                          

   
                                                       
                                                              
                
    
__STATIC_INLINE void LL_RCC_DisableIT_LSECSS(void)
{
  CLEAR_BIT(RCC->CIER, RCC_CIER_LSECSSIE);
}

   
                                                                        
                                                                
                                  
    
__STATIC_INLINE uint32_t LL_RCC_IsEnabledIT_LSIRDY(void)
{
  return ((READ_BIT(RCC->CIER, RCC_CIER_LSIRDYIE) == RCC_CIER_LSIRDYIE) ? 1UL : 0UL);
}

   
                                                                        
                                                                
                                  
    
__STATIC_INLINE uint32_t LL_RCC_IsEnabledIT_LSERDY(void)
{
  return ((READ_BIT(RCC->CIER, RCC_CIER_LSERDYIE) == RCC_CIER_LSERDYIE) ? 1UL : 0UL);
}

   
                                                                        
                                                                
                                  
    
__STATIC_INLINE uint32_t LL_RCC_IsEnabledIT_MSIRDY(void)
{
  return ((READ_BIT(RCC->CIER, RCC_CIER_MSIRDYIE) == RCC_CIER_MSIRDYIE) ? 1UL : 0UL);
}

   
                                                                        
                                                                
                                  
    
__STATIC_INLINE uint32_t LL_RCC_IsEnabledIT_HSIRDY(void)
{
  return ((READ_BIT(RCC->CIER, RCC_CIER_HSIRDYIE) == RCC_CIER_HSIRDYIE) ? 1UL : 0UL);
}

   
                                                                        
                                                                
                                  
    
__STATIC_INLINE uint32_t LL_RCC_IsEnabledIT_HSERDY(void)
{
  return ((READ_BIT(RCC->CIER, RCC_CIER_HSERDYIE) == RCC_CIER_HSERDYIE) ? 1UL : 0UL);
}

   
                                                                        
                                                                
                                  
    
__STATIC_INLINE uint32_t LL_RCC_IsEnabledIT_PLLRDY(void)
{
  return ((READ_BIT(RCC->CIER, RCC_CIER_PLLRDYIE) == RCC_CIER_PLLRDYIE) ? 1UL : 0UL);
}

#if defined(RCC_HSI48_SUPPORT)
   
                                                                          
                                                                   
                                  
    
__STATIC_INLINE uint32_t LL_RCC_IsEnabledIT_HSI48RDY(void)
{
  return ((READ_BIT(RCC->CIER, RCC_CIER_HSI48RDYIE) == RCC_CIER_HSI48RDYIE) ? 1UL : 0UL);
}
#endif                        

#if defined(RCC_PLLSAI1_SUPPORT)
   
                                                                            
                                                                    
                                  
    
__STATIC_INLINE uint32_t LL_RCC_IsEnabledIT_PLLSAI1RDY(void)
{
  return ((READ_BIT(RCC->CIER, RCC_CIER_PLLSAI1RDYIE) == RCC_CIER_PLLSAI1RDYIE) ? 1UL : 0UL);
}
#endif                          

#if defined(RCC_PLLSAI2_SUPPORT)
   
                                                                            
                                                                    
                                  
    
__STATIC_INLINE uint32_t LL_RCC_IsEnabledIT_PLLSAI2RDY(void)
{
  return ((READ_BIT(RCC->CIER, RCC_CIER_PLLSAI2RDYIE) == RCC_CIER_PLLSAI2RDYIE) ? 1UL : 0UL);
}
#endif                          

   
                                                                     
                                                                
                                  
    
__STATIC_INLINE uint32_t LL_RCC_IsEnabledIT_LSECSS(void)
{
  return ((READ_BIT(RCC->CIER, RCC_CIER_LSECSSIE) == RCC_CIER_LSECSSIE) ? 1UL : 0UL);
}

   
      
    

#if defined(USE_FULL_LL_DRIVER)
                                                       
      
    
ErrorStatus LL_RCC_DeInit(void);
   
      
    

                                                                                      
      
    
void        LL_RCC_GetSystemClocksFreq(LL_RCC_ClocksTypeDef *RCC_Clocks);
uint32_t    LL_RCC_GetUSARTClockFreq(uint32_t USARTxSource);
#if defined(UART4) || defined(UART5)
uint32_t    LL_RCC_GetUARTClockFreq(uint32_t UARTxSource);
#endif                     
uint32_t    LL_RCC_GetI2CClockFreq(uint32_t I2CxSource);
uint32_t    LL_RCC_GetLPUARTClockFreq(uint32_t LPUARTxSource);
uint32_t    LL_RCC_GetLPTIMClockFreq(uint32_t LPTIMxSource);
#if defined(SAI1)
uint32_t    LL_RCC_GetSAIClockFreq(uint32_t SAIxSource);
#endif           
#if defined(SDMMC1)
#if defined(RCC_CCIPR2_SDMMCSEL)
uint32_t    LL_RCC_GetSDMMCKernelClockFreq(uint32_t SDMMCxSource);
#endif
uint32_t    LL_RCC_GetSDMMCClockFreq(uint32_t SDMMCxSource);
#endif             
uint32_t    LL_RCC_GetRNGClockFreq(uint32_t RNGxSource);
#if defined(USB_OTG_FS) || defined(USB)
uint32_t    LL_RCC_GetUSBClockFreq(uint32_t USBxSource);
#endif                        
uint32_t    LL_RCC_GetADCClockFreq(uint32_t ADCxSource);
#if defined(SWPMI1)
uint32_t    LL_RCC_GetSWPMIClockFreq(uint32_t SWPMIxSource);
#endif             
#if defined(DFSDM1_Channel0)
uint32_t    LL_RCC_GetDFSDMClockFreq(uint32_t DFSDMxSource);
#if defined(RCC_CCIPR2_DFSDM1SEL)
uint32_t    LL_RCC_GetDFSDMAudioClockFreq(uint32_t DFSDMxSource);
#endif                           
#endif                      
#if defined(LTDC)
uint32_t    LL_RCC_GetLTDCClockFreq(uint32_t LTDCxSource);
#endif           
#if defined(DSI)
uint32_t    LL_RCC_GetDSIClockFreq(uint32_t DSIxSource);
#endif          
#if defined(OCTOSPI1)
uint32_t    LL_RCC_GetOCTOSPIClockFreq(uint32_t OCTOSPIxSource);
#endif               
   
      
    
#endif                         

   
      
    

   
      
    

#endif                   

   
      
    

#ifdef __cplusplus
}
#endif

#endif                         

