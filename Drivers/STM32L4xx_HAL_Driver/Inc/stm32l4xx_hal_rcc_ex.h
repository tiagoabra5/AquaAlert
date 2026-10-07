/**
  ******************************************************************************
  * @file    stm32l4xx_hal_rcc_ex.h
  * @author  MCD Application Team
  * @brief   Header file of RCC HAL Extended module.
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

                                                                                
#ifndef STM32L4xx_HAL_RCC_EX_H
#define STM32L4xx_HAL_RCC_EX_H

#ifdef __cplusplus
 extern "C" {
#endif

                                                                                
#include "stm32l4xx_hal_def.h"

                                    
      
    

                     
      
    

                                                                                

                                                       
      
    

#if defined(RCC_PLLSAI1_SUPPORT)
   
                                              
    
typedef struct
{

  uint32_t PLLSAI1Source;                                                   
                                                                                                

#if defined(RCC_PLLSAI1M_DIV_1_16_SUPPORT)
  uint32_t PLLSAI1M;                                                                              
                                                                                                           
#else
  uint32_t PLLSAI1M;                                                                              
                                                                                                          
#endif

  uint32_t PLLSAI1N;                                                                                         
                                                                                                                  

  uint32_t PLLSAI1P;                                                                    
                                                                                                  

  uint32_t PLLSAI1Q;                                                                               
                                                                                                  

  uint32_t PLLSAI1R;                                                                    
                                                                                                  

  uint32_t PLLSAI1ClockOut;                                                                    
                                                                                                    
}RCC_PLLSAI1InitTypeDef;
#endif                          

#if defined(RCC_PLLSAI2_SUPPORT)
   
                                              
    
typedef struct
{

  uint32_t PLLSAI2Source;                                                   
                                                                                                

#if defined(RCC_PLLSAI2M_DIV_1_16_SUPPORT)
  uint32_t PLLSAI2M;                                                                              
                                                                                                           
#else
  uint32_t PLLSAI2M;                                                                              
                                                                                                          
#endif

  uint32_t PLLSAI2N;                                                                                         
                                                                                                                  

  uint32_t PLLSAI2P;                                                                    
                                                                                                  

#if defined(RCC_PLLSAI2Q_DIV_SUPPORT)
  uint32_t PLLSAI2Q;                                                                    
                                                                                                  
#endif

  uint32_t PLLSAI2R;                                                                    
                                                                                                  

  uint32_t PLLSAI2ClockOut;                                                                    
                                                                                                    
}RCC_PLLSAI2InitTypeDef;

#endif                          

   
                                                    
    
typedef struct
{
  uint32_t PeriphClockSelection;                                            
                                                                                                             
#if defined(RCC_PLLSAI1_SUPPORT)

  RCC_PLLSAI1InitTypeDef PLLSAI1;                                    
                                                                                                                                                    
#endif                          
#if defined(RCC_PLLSAI2_SUPPORT)

  RCC_PLLSAI2InitTypeDef PLLSAI2;                                    
                                                                                                                                    

#endif                          

  uint32_t Usart1ClockSelection;                                      
                                                                                                          

  uint32_t Usart2ClockSelection;                                      
                                                                                                          

#if defined(USART3)

  uint32_t Usart3ClockSelection;                                      
                                                                                                          

#endif             

#if defined(UART4)

  uint32_t Uart4ClockSelection;                                      
                                                                                                         

#endif            

#if defined(UART5)

  uint32_t Uart5ClockSelection;                                      
                                                                                                         

#endif            

  uint32_t Lpuart1ClockSelection;                                      
                                                                                                           

  uint32_t I2c1ClockSelection;                                      
                                                                                                        

#if defined(I2C2)

  uint32_t I2c2ClockSelection;                                      
                                                                                                        

#endif           

  uint32_t I2c3ClockSelection;                                      
                                                                                                        

#if defined(I2C4)

  uint32_t I2c4ClockSelection;                                      
                                                                                                        

#endif           

  uint32_t Lptim1ClockSelection;                                      
                                                                                                          

  uint32_t Lptim2ClockSelection;                                      
                                                                                                          
#if defined(SAI1)

  uint32_t Sai1ClockSelection;                                      
                                                                                                        
#endif           

#if defined(SAI2)

  uint32_t Sai2ClockSelection;                                      
                                                                                                        

#endif           

#if defined(USB_OTG_FS) || defined(USB)

  uint32_t UsbClockSelection;                                                                                
                                                                                                       

#endif                        

#if defined(SDMMC1)

  uint32_t Sdmmc1ClockSelection;                                                                             
                                                                                                          

#endif             

  uint32_t RngClockSelection;                                                                                
                                                                                                       

#if !defined(STM32L412xx) && !defined(STM32L422xx)
  uint32_t AdcClockSelection;                                                
                                                                                                       
#endif                                   

#if defined(SWPMI1)

  uint32_t Swpmi1ClockSelection;                                      
                                                                                                          

#endif             

#if defined(DFSDM1_Filter0)

  uint32_t Dfsdm1ClockSelection;                                      
                                                                                                          

#if defined(STM32L4P5xx) || defined(STM32L4Q5xx) || defined(STM32L4R5xx) || defined(STM32L4R7xx) || defined(STM32L4R9xx) || defined(STM32L4S5xx) || defined(STM32L4S7xx) || defined(STM32L4S9xx)
  uint32_t Dfsdm1AudioClockSelection;                                          
                                                                                                                

#endif                                                                                                                           

#endif                     

#if defined(LTDC)

  uint32_t LtdcClockSelection;                                      
                                                                                                        

#endif           

#if defined(DSI)

  uint32_t DsiClockSelection;                                      
                                                                                                       

#endif          

#if defined(OCTOSPI1) || defined(OCTOSPI2)

  uint32_t OspiClockSelection;                                         
                                                                                                        

#endif

  uint32_t RTCClockSelection;                                      
                                                                                                     
}RCC_PeriphCLKInitTypeDef;

#if defined(CRS)

   
                                            
    
typedef struct
{
  uint32_t Prescaler;                                                                   
                                                                                                      

  uint32_t Source;                                                      
                                                                                                     

  uint32_t Polarity;                                                                           
                                                                                                       

  uint32_t ReloadValue;                                                                                                     
                                                                                                                                     
                                                                                                                                             

  uint32_t ErrorLimitValue;                                                                                          
                                                                                                                                         

  uint32_t HSI48CalibrationValue;                                                                           
                                                                                                                                             
                                                                                            

}RCC_CRSInitTypeDef;

   
                                                       
    
typedef struct
{
  uint32_t ReloadValue;                                                                       
                                                                                            

  uint32_t HSI48CalibrationValue;                                                                 
                                                                                                                                               

  uint32_t FreqErrorCapture;                                                                                
                                                                                                                     
                                                                                           

  uint32_t FreqErrorDirection;                                                                                
                                                                                                                                       
                                                                                                                                       
                                                                                                         

}RCC_CRSSynchroInfoTypeDef;

#endif          
   
      
    

                                                                                
                                                               
      
    

                                                            
      
    
#define RCC_LSCOSOURCE_LSI             0x00000000U                                                         
#define RCC_LSCOSOURCE_LSE             RCC_BDCR_LSCOSEL                                                    
   
      
    

                                                                 
      
    
#define RCC_PERIPHCLK_USART1           0x00000001U
#define RCC_PERIPHCLK_USART2           0x00000002U
#if defined(USART3)
#define RCC_PERIPHCLK_USART3           0x00000004U
#endif
#if defined(UART4)
#define RCC_PERIPHCLK_UART4            0x00000008U
#endif
#if defined(UART5)
#define RCC_PERIPHCLK_UART5            0x00000010U
#endif
#define RCC_PERIPHCLK_LPUART1          0x00000020U
#define RCC_PERIPHCLK_I2C1             0x00000040U
#if defined(I2C2)
#define RCC_PERIPHCLK_I2C2             0x00000080U
#endif
#define RCC_PERIPHCLK_I2C3             0x00000100U
#define RCC_PERIPHCLK_LPTIM1           0x00000200U
#define RCC_PERIPHCLK_LPTIM2           0x00000400U
#if defined(SAI1)
#define RCC_PERIPHCLK_SAI1             0x00000800U
#endif
#if defined(SAI2)
#define RCC_PERIPHCLK_SAI2             0x00001000U
#endif
#if defined(USB_OTG_FS) || defined(USB)
#define RCC_PERIPHCLK_USB              0x00002000U
#endif
#define RCC_PERIPHCLK_ADC              0x00004000U
#if defined(SWPMI1)
#define RCC_PERIPHCLK_SWPMI1           0x00008000U
#endif
#if defined(DFSDM1_Filter0)
#define RCC_PERIPHCLK_DFSDM1           0x00010000U
#if defined(STM32L4P5xx) || defined(STM32L4Q5xx) || defined(STM32L4R5xx) || defined(STM32L4R7xx) || defined(STM32L4R9xx) || defined(STM32L4S5xx) || defined(STM32L4S7xx) || defined(STM32L4S9xx)
#define RCC_PERIPHCLK_DFSDM1AUDIO      0x00200000U
#endif                                                                                                                           
#endif
#define RCC_PERIPHCLK_RTC              0x00020000U
#define RCC_PERIPHCLK_RNG              0x00040000U
#if defined(SDMMC1)
#define RCC_PERIPHCLK_SDMMC1           0x00080000U
#endif
#if defined(I2C4)
#define RCC_PERIPHCLK_I2C4             0x00100000U
#endif
#if defined(LTDC)
#define RCC_PERIPHCLK_LTDC             0x00400000U
#endif
#if defined(DSI)
#define RCC_PERIPHCLK_DSI              0x00800000U
#endif
#if defined(OCTOSPI1) || defined(OCTOSPI2)
#define RCC_PERIPHCLK_OSPI             0x01000000U
#endif
   
      
    


                                                           
      
    
#define RCC_USART1CLKSOURCE_PCLK2      0x00000000U
#define RCC_USART1CLKSOURCE_SYSCLK     RCC_CCIPR_USART1SEL_0
#define RCC_USART1CLKSOURCE_HSI        RCC_CCIPR_USART1SEL_1
#define RCC_USART1CLKSOURCE_LSE        (RCC_CCIPR_USART1SEL_0 | RCC_CCIPR_USART1SEL_1)
   
      
    

                                                           
      
    
#define RCC_USART2CLKSOURCE_PCLK1      0x00000000U
#define RCC_USART2CLKSOURCE_SYSCLK     RCC_CCIPR_USART2SEL_0
#define RCC_USART2CLKSOURCE_HSI        RCC_CCIPR_USART2SEL_1
#define RCC_USART2CLKSOURCE_LSE        (RCC_CCIPR_USART2SEL_0 | RCC_CCIPR_USART2SEL_1)
   
      
    

#if defined(USART3)
                                                           
      
    
#define RCC_USART3CLKSOURCE_PCLK1      0x00000000U
#define RCC_USART3CLKSOURCE_SYSCLK     RCC_CCIPR_USART3SEL_0
#define RCC_USART3CLKSOURCE_HSI        RCC_CCIPR_USART3SEL_1
#define RCC_USART3CLKSOURCE_LSE        (RCC_CCIPR_USART3SEL_0 | RCC_CCIPR_USART3SEL_1)
   
      
    
#endif             

#if defined(UART4)
                                                         
      
    
#define RCC_UART4CLKSOURCE_PCLK1       0x00000000U
#define RCC_UART4CLKSOURCE_SYSCLK      RCC_CCIPR_UART4SEL_0
#define RCC_UART4CLKSOURCE_HSI         RCC_CCIPR_UART4SEL_1
#define RCC_UART4CLKSOURCE_LSE         (RCC_CCIPR_UART4SEL_0 | RCC_CCIPR_UART4SEL_1)
   
      
    
#endif            

#if defined(UART5)
                                                         
      
    
#define RCC_UART5CLKSOURCE_PCLK1       0x00000000U
#define RCC_UART5CLKSOURCE_SYSCLK      RCC_CCIPR_UART5SEL_0
#define RCC_UART5CLKSOURCE_HSI         RCC_CCIPR_UART5SEL_1
#define RCC_UART5CLKSOURCE_LSE         (RCC_CCIPR_UART5SEL_0 | RCC_CCIPR_UART5SEL_1)
   
      
    
#endif            

                                                             
      
    
#define RCC_LPUART1CLKSOURCE_PCLK1     0x00000000U
#define RCC_LPUART1CLKSOURCE_SYSCLK    RCC_CCIPR_LPUART1SEL_0
#define RCC_LPUART1CLKSOURCE_HSI       RCC_CCIPR_LPUART1SEL_1
#define RCC_LPUART1CLKSOURCE_LSE       (RCC_CCIPR_LPUART1SEL_0 | RCC_CCIPR_LPUART1SEL_1)
   
      
    

                                                       
      
    
#define RCC_I2C1CLKSOURCE_PCLK1        0x00000000U
#define RCC_I2C1CLKSOURCE_SYSCLK       RCC_CCIPR_I2C1SEL_0
#define RCC_I2C1CLKSOURCE_HSI          RCC_CCIPR_I2C1SEL_1
   
      
    

#if defined(I2C2)
                                                       
      
    
#define RCC_I2C2CLKSOURCE_PCLK1        0x00000000U
#define RCC_I2C2CLKSOURCE_SYSCLK       RCC_CCIPR_I2C2SEL_0
#define RCC_I2C2CLKSOURCE_HSI          RCC_CCIPR_I2C2SEL_1
   
      
    
#endif           

                                                       
      
    
#define RCC_I2C3CLKSOURCE_PCLK1        0x00000000U
#define RCC_I2C3CLKSOURCE_SYSCLK       RCC_CCIPR_I2C3SEL_0
#define RCC_I2C3CLKSOURCE_HSI          RCC_CCIPR_I2C3SEL_1
   
      
    

#if defined(I2C4)
                                                       
      
    
#define RCC_I2C4CLKSOURCE_PCLK1        0x00000000U
#define RCC_I2C4CLKSOURCE_SYSCLK       RCC_CCIPR2_I2C4SEL_0
#define RCC_I2C4CLKSOURCE_HSI          RCC_CCIPR2_I2C4SEL_1
   
      
    
#endif           

#if defined(SAI1)
                                                       
      
    
#define RCC_SAI1CLKSOURCE_PLLSAI1      0x00000000U
#if defined(RCC_PLLSAI2_SUPPORT)
#if defined(STM32L4P5xx) || defined(STM32L4Q5xx) || defined(STM32L4R5xx) || defined(STM32L4R7xx) || defined(STM32L4R9xx) || defined(STM32L4S5xx) || defined(STM32L4S7xx) || defined(STM32L4S9xx)
#define RCC_SAI1CLKSOURCE_PLLSAI2      RCC_CCIPR2_SAI1SEL_0
#else
#define RCC_SAI1CLKSOURCE_PLLSAI2      RCC_CCIPR_SAI1SEL_0
#endif                                                                                                                           
#endif                          
#if defined(STM32L4P5xx) || defined(STM32L4Q5xx) || defined(STM32L4R5xx) || defined(STM32L4R7xx) || defined(STM32L4R9xx) || defined(STM32L4S5xx) || defined(STM32L4S7xx) || defined(STM32L4S9xx)
#define RCC_SAI1CLKSOURCE_PLL          RCC_CCIPR2_SAI1SEL_1
#define RCC_SAI1CLKSOURCE_PIN          (RCC_CCIPR2_SAI1SEL_1 | RCC_CCIPR2_SAI1SEL_0)
#define RCC_SAI1CLKSOURCE_HSI          RCC_CCIPR2_SAI1SEL_2
#else
#define RCC_SAI1CLKSOURCE_PLL          RCC_CCIPR_SAI1SEL_1
#define RCC_SAI1CLKSOURCE_PIN          RCC_CCIPR_SAI1SEL
#endif                                                                                                                           
   
      
    
#endif           

#if defined(SAI2)
                                                       
      
    
#define RCC_SAI2CLKSOURCE_PLLSAI1      0x00000000U
#if defined(STM32L4P5xx) || defined(STM32L4Q5xx) || defined(STM32L4R5xx) || defined(STM32L4R7xx) || defined(STM32L4R9xx) || defined(STM32L4S5xx) || defined(STM32L4S7xx) || defined(STM32L4S9xx)
#define RCC_SAI2CLKSOURCE_PLLSAI2      RCC_CCIPR2_SAI2SEL_0
#define RCC_SAI2CLKSOURCE_PLL          RCC_CCIPR2_SAI2SEL_1
#define RCC_SAI2CLKSOURCE_PIN          (RCC_CCIPR2_SAI2SEL_1 | RCC_CCIPR2_SAI2SEL_0)
#define RCC_SAI2CLKSOURCE_HSI          RCC_CCIPR2_SAI2SEL_2
#else
#define RCC_SAI2CLKSOURCE_PLLSAI2      RCC_CCIPR_SAI2SEL_0
#define RCC_SAI2CLKSOURCE_PLL          RCC_CCIPR_SAI2SEL_1
#define RCC_SAI2CLKSOURCE_PIN          RCC_CCIPR_SAI2SEL
#endif                                                                                                                           
   
      
    
#endif           

                                                           
      
    
#define RCC_LPTIM1CLKSOURCE_PCLK1      0x00000000U
#define RCC_LPTIM1CLKSOURCE_LSI        RCC_CCIPR_LPTIM1SEL_0
#define RCC_LPTIM1CLKSOURCE_HSI        RCC_CCIPR_LPTIM1SEL_1
#define RCC_LPTIM1CLKSOURCE_LSE        RCC_CCIPR_LPTIM1SEL
   
      
    

                                                           
      
    
#define RCC_LPTIM2CLKSOURCE_PCLK1      0x00000000U
#define RCC_LPTIM2CLKSOURCE_LSI        RCC_CCIPR_LPTIM2SEL_0
#define RCC_LPTIM2CLKSOURCE_HSI        RCC_CCIPR_LPTIM2SEL_1
#define RCC_LPTIM2CLKSOURCE_LSE        RCC_CCIPR_LPTIM2SEL
   
      
    

#if defined(SDMMC1)
                                                           
      
    
#if defined(RCC_HSI48_SUPPORT)
#define RCC_SDMMC1CLKSOURCE_HSI48      0x00000000U                                                       
#else
#define RCC_SDMMC1CLKSOURCE_NONE       0x00000000U                                                       
#endif                        
#define RCC_SDMMC1CLKSOURCE_PLLSAI1    RCC_CCIPR_CLK48SEL_0                                                          
#define RCC_SDMMC1CLKSOURCE_PLL        RCC_CCIPR_CLK48SEL_1                                                          
#define RCC_SDMMC1CLKSOURCE_MSI        RCC_CCIPR_CLK48SEL                                                            
#if defined(RCC_CCIPR2_SDMMCSEL)
#define RCC_SDMMC1CLKSOURCE_PLLP       RCC_CCIPR2_SDMMCSEL                                                           
#endif                          
   
      
    
#endif             

                                                     
      
    
#if defined(RCC_HSI48_SUPPORT)
#define RCC_RNGCLKSOURCE_HSI48         0x00000000U
#else
#define RCC_RNGCLKSOURCE_NONE          0x00000000U
#endif                        
#if defined(RCC_PLLSAI1_SUPPORT)
#define RCC_RNGCLKSOURCE_PLLSAI1       RCC_CCIPR_CLK48SEL_0
#endif                          
#define RCC_RNGCLKSOURCE_PLL           RCC_CCIPR_CLK48SEL_1
#define RCC_RNGCLKSOURCE_MSI           RCC_CCIPR_CLK48SEL
   
      
    

#if defined(USB_OTG_FS) || defined(USB)
                                                     
      
    
#if defined(RCC_HSI48_SUPPORT)
#define RCC_USBCLKSOURCE_HSI48         0x00000000U
#else
#define RCC_USBCLKSOURCE_NONE          0x00000000U
#endif                        
#if defined(RCC_PLLSAI1_SUPPORT)
#define RCC_USBCLKSOURCE_PLLSAI1       RCC_CCIPR_CLK48SEL_0
#endif                          
#define RCC_USBCLKSOURCE_PLL           RCC_CCIPR_CLK48SEL_1
#define RCC_USBCLKSOURCE_MSI           RCC_CCIPR_CLK48SEL
   
      
    
#endif                        

                                                     
      
    
#define RCC_ADCCLKSOURCE_NONE         0x00000000U
#if defined(RCC_PLLSAI1_SUPPORT)
#define RCC_ADCCLKSOURCE_PLLSAI1      RCC_CCIPR_ADCSEL_0
#endif                          
#if defined(STM32L471xx) || defined(STM32L475xx) || defined(STM32L476xx) || defined(STM32L485xx) || defined(STM32L486xx) || defined(STM32L496xx) || defined(STM32L4A6xx)
#define RCC_ADCCLKSOURCE_PLLSAI2      RCC_CCIPR_ADCSEL_1
#endif                                                                                                            
#if defined(RCC_CCIPR_ADCSEL)
#define RCC_ADCCLKSOURCE_SYSCLK       RCC_CCIPR_ADCSEL
#else
#define RCC_ADCCLKSOURCE_SYSCLK       0x30000000U
#endif                       
   
      
    

#if defined(SWPMI1)
                                                           
      
    
#define RCC_SWPMI1CLKSOURCE_PCLK1      0x00000000U
#define RCC_SWPMI1CLKSOURCE_HSI        RCC_CCIPR_SWPMI1SEL
   
      
    
#endif             

#if defined(DFSDM1_Filter0)
                                                           
      
    
#define RCC_DFSDM1CLKSOURCE_PCLK2      0x00000000U
#if defined(STM32L4P5xx) || defined(STM32L4Q5xx) || defined(STM32L4R5xx) || defined(STM32L4R7xx) || defined(STM32L4R9xx) || defined(STM32L4S5xx) || defined(STM32L4S7xx) || defined(STM32L4S9xx)
#define RCC_DFSDM1CLKSOURCE_SYSCLK     RCC_CCIPR2_DFSDM1SEL
#else
#define RCC_DFSDM1CLKSOURCE_SYSCLK     RCC_CCIPR_DFSDM1SEL
#endif                                                                                                                           
   
      
    

#if defined(STM32L4P5xx) || defined(STM32L4Q5xx) || defined(STM32L4R5xx) || defined(STM32L4R7xx) || defined(STM32L4R9xx) || defined(STM32L4S5xx) || defined(STM32L4S7xx) || defined(STM32L4S9xx)
                                                                       
      
    
#define RCC_DFSDM1AUDIOCLKSOURCE_SAI1   0x00000000U
#define RCC_DFSDM1AUDIOCLKSOURCE_HSI    RCC_CCIPR2_ADFSDM1SEL_0
#define RCC_DFSDM1AUDIOCLKSOURCE_MSI    RCC_CCIPR2_ADFSDM1SEL_1
   
      
    
#endif                                                                                                                           
#endif                     

#if defined(LTDC)
                                                       
      
    
#define RCC_LTDCCLKSOURCE_PLLSAI2_DIV2  0x00000000U
#define RCC_LTDCCLKSOURCE_PLLSAI2_DIV4  RCC_CCIPR2_PLLSAI2DIVR_0
#define RCC_LTDCCLKSOURCE_PLLSAI2_DIV8  RCC_CCIPR2_PLLSAI2DIVR_1
#define RCC_LTDCCLKSOURCE_PLLSAI2_DIV16 RCC_CCIPR2_PLLSAI2DIVR
   
      
    
#endif           

#if defined(DSI)
                                                     
      
    
#define RCC_DSICLKSOURCE_DSIPHY        0x00000000U
#define RCC_DSICLKSOURCE_PLLSAI2       RCC_CCIPR2_DSISEL
   
      
    
#endif          

#if defined(OCTOSPI1) || defined(OCTOSPI2)
                                                          
      
    
#define RCC_OSPICLKSOURCE_SYSCLK    0x00000000U
#define RCC_OSPICLKSOURCE_MSI       RCC_CCIPR2_OSPISEL_0
#define RCC_OSPICLKSOURCE_PLL       RCC_CCIPR2_OSPISEL_1
   
      
    
#endif                           

                                                                         
      
    
#define RCC_EXTI_LINE_LSECSS           EXTI_IMR1_IM19                                                                             
   
      
    

#if defined(CRS)

                                               
      
    
#define RCC_CRS_NONE                   0x00000000U
#define RCC_CRS_TIMEOUT                0x00000001U
#define RCC_CRS_SYNCOK                 0x00000002U
#define RCC_CRS_SYNCWARN               0x00000004U
#define RCC_CRS_SYNCERR                0x00000008U
#define RCC_CRS_SYNCMISS               0x00000010U
#define RCC_CRS_TRIMOVF                0x00000020U
   
      
    

                                                             
      
    
#define RCC_CRS_SYNC_SOURCE_GPIO       0x00000000U                                               
#define RCC_CRS_SYNC_SOURCE_LSE        CRS_CFGR_SYNCSRC_0                                       
#define RCC_CRS_SYNC_SOURCE_USB        CRS_CFGR_SYNCSRC_1                                                    
   
      
    

                                                               
      
    
#define RCC_CRS_SYNC_DIV1        0x00000000U                                                                           
#define RCC_CRS_SYNC_DIV2        CRS_CFGR_SYNCDIV_0                                                           
#define RCC_CRS_SYNC_DIV4        CRS_CFGR_SYNCDIV_1                                                           
#define RCC_CRS_SYNC_DIV8        (CRS_CFGR_SYNCDIV_1 | CRS_CFGR_SYNCDIV_0)                                    
#define RCC_CRS_SYNC_DIV16       CRS_CFGR_SYNCDIV_2                                                            
#define RCC_CRS_SYNC_DIV32       (CRS_CFGR_SYNCDIV_2 | CRS_CFGR_SYNCDIV_0)                                     
#define RCC_CRS_SYNC_DIV64       (CRS_CFGR_SYNCDIV_2 | CRS_CFGR_SYNCDIV_1)                                     
#define RCC_CRS_SYNC_DIV128      CRS_CFGR_SYNCDIV                                                               
   
      
    

                                                                 
      
    
#define RCC_CRS_SYNC_POLARITY_RISING   0x00000000U                                                        
#define RCC_CRS_SYNC_POLARITY_FALLING  CRS_CFGR_SYNCPOL                                          
   
      
    

                                                                       
      
    
#define RCC_CRS_RELOADVALUE_DEFAULT    0x0000BB7FU                                                       
                                                                                                                                                                   
   
      
    

                                                                     
      
    
#define RCC_CRS_ERRORLIMIT_DEFAULT     0x00000022U                                        
   
      
    

                                                                                 
      
    
#if defined(STM32L412xx) || defined(STM32L422xx)
#define RCC_CRS_HSI48CALIBRATION_DEFAULT 0x00000040U                                                                                        
                                                                                                                                      
                                                                                                     
#else
#define RCC_CRS_HSI48CALIBRATION_DEFAULT 0x00000020U                                                                                        
                                                                                                                                      
                                                                                                     
#endif
   
      
    

                                                                       
      
    
#define RCC_CRS_FREQERRORDIR_UP        0x00000000U                                                                         
#define RCC_CRS_FREQERRORDIR_DOWN      CRS_ISR_FEDIR                                                                         
   
      
    

                                                                     
      
    
#define RCC_CRS_IT_SYNCOK              CRS_CR_SYNCOKIE                            
#define RCC_CRS_IT_SYNCWARN            CRS_CR_SYNCWARNIE                         
#define RCC_CRS_IT_ERR                 CRS_CR_ERRIE                       
#define RCC_CRS_IT_ESYNC               CRS_CR_ESYNCIE                             
#define RCC_CRS_IT_SYNCERR             CRS_CR_ERRIE                            
#define RCC_CRS_IT_SYNCMISS            CRS_CR_ERRIE                             
#define RCC_CRS_IT_TRIMOVF             CRS_CR_ERRIE                                                 

   
      
    

                                             
      
    
#define RCC_CRS_FLAG_SYNCOK            CRS_ISR_SYNCOKF                                     
#define RCC_CRS_FLAG_SYNCWARN          CRS_ISR_SYNCWARNF                                   
#define RCC_CRS_FLAG_ERR               CRS_ISR_ERRF                                   
#define RCC_CRS_FLAG_ESYNC             CRS_ISR_ESYNCF                                      
#define RCC_CRS_FLAG_SYNCERR           CRS_ISR_SYNCERR                         
#define RCC_CRS_FLAG_SYNCMISS          CRS_ISR_SYNCMISS                        
#define RCC_CRS_FLAG_TRIMOVF           CRS_ISR_TRIMOVF                                             

   
      
    

#endif          

   
      
    

                                                                                
                                                         
     
   

#if defined(RCC_PLLSAI1_SUPPORT)

   
                                                                                     
   
                                                                         
                                                                                
                                         
   
                 
                                                                              
                                                                                   
   
        
                                                                                          
                                                                                         
                                                                                   
                                                       
                                                                       
   
                                                                     
                                                                                         
                           
                                                        
   
                                                                                
                                                               
                                                                  
   
                                                                         
                                                               
                                                       
   
                
    
#if defined(RCC_PLLSAI1M_DIV_1_16_SUPPORT)

#if defined(RCC_PLLSAI1P_DIV_2_31_SUPPORT)

#define __HAL_RCC_PLLSAI1_CONFIG(__PLLSAI1M__, __PLLSAI1N__, __PLLSAI1P__, __PLLSAI1Q__, __PLLSAI1R__) \
                  MODIFY_REG(RCC->PLLSAI1CFGR, \
                             (RCC_PLLSAI1CFGR_PLLSAI1M | RCC_PLLSAI1CFGR_PLLSAI1N | RCC_PLLSAI1CFGR_PLLSAI1P | \
                              RCC_PLLSAI1CFGR_PLLSAI1Q | RCC_PLLSAI1CFGR_PLLSAI1R | RCC_PLLSAI1CFGR_PLLSAI1PDIV), \
                             ((((__PLLSAI1M__) - 1U) << RCC_PLLSAI1CFGR_PLLSAI1M_Pos) | \
                              ((__PLLSAI1N__) << RCC_PLLSAI1CFGR_PLLSAI1N_Pos) | \
                              ((((__PLLSAI1Q__) >> 1U) - 1U) << RCC_PLLSAI1CFGR_PLLSAI1Q_Pos) | \
                              ((((__PLLSAI1R__) >> 1U) - 1U) << RCC_PLLSAI1CFGR_PLLSAI1R_Pos) | \
                              ((uint32_t)(__PLLSAI1P__) << RCC_PLLSAI1CFGR_PLLSAI1PDIV_Pos)))

#else

#define __HAL_RCC_PLLSAI1_CONFIG(__PLLSAI1M__, __PLLSAI1N__, __PLLSAI1P__, __PLLSAI1Q__, __PLLSAI1R__) \
                  MODIFY_REG(RCC->PLLSAI1CFGR, \
                             (RCC_PLLSAI1CFGR_PLLSAI1M | RCC_PLLSAI1CFGR_PLLSAI1N | RCC_PLLSAI1CFGR_PLLSAI1P | \
                              RCC_PLLSAI1CFGR_PLLSAI1Q | RCC_PLLSAI1CFGR_PLLSAI1R), \
                             ((((__PLLSAI1M__) - 1U) << RCC_PLLSAI1CFGR_PLLSAI1M_Pos) | \
                              ((__PLLSAI1N__) << RCC_PLLSAI1CFGR_PLLSAI1N_Pos) | \
                              ((((__PLLSAI1Q__) >> 1U) - 1U) << RCC_PLLSAI1CFGR_PLLSAI1Q_Pos) | \
                              ((((__PLLSAI1R__) >> 1U) - 1U) << RCC_PLLSAI1CFGR_PLLSAI1R_Pos) | \
                              (((__PLLSAI1P__) >> 4U) << RCC_PLLSAI1CFGR_PLLSAI1P_Pos)))

#endif                                    

#else

#if defined(RCC_PLLSAI1P_DIV_2_31_SUPPORT)

#define __HAL_RCC_PLLSAI1_CONFIG(__PLLSAI1N__, __PLLSAI1P__, __PLLSAI1Q__, __PLLSAI1R__) \
                  MODIFY_REG(RCC->PLLSAI1CFGR, \
                             (RCC_PLLSAI1CFGR_PLLSAI1N | RCC_PLLSAI1CFGR_PLLSAI1P | \
                              RCC_PLLSAI1CFGR_PLLSAI1Q | RCC_PLLSAI1CFGR_PLLSAI1R | RCC_PLLSAI1CFGR_PLLSAI1PDIV), \
                             (((__PLLSAI1N__) << RCC_PLLSAI1CFGR_PLLSAI1N_Pos) | \
                              ((((__PLLSAI1Q__) >> 1U) - 1U) << RCC_PLLSAI1CFGR_PLLSAI1Q_Pos) | \
                              ((((__PLLSAI1R__) >> 1U) - 1U) << RCC_PLLSAI1CFGR_PLLSAI1R_Pos) | \
                              ((uint32_t)(__PLLSAI1P__) << RCC_PLLSAI1CFGR_PLLSAI1PDIV_Pos)))

#else

#define __HAL_RCC_PLLSAI1_CONFIG(__PLLSAI1N__, __PLLSAI1P__, __PLLSAI1Q__, __PLLSAI1R__) \
                  MODIFY_REG(RCC->PLLSAI1CFGR, \
                             (RCC_PLLSAI1CFGR_PLLSAI1N | RCC_PLLSAI1CFGR_PLLSAI1P | \
                              RCC_PLLSAI1CFGR_PLLSAI1Q | RCC_PLLSAI1CFGR_PLLSAI1R), \
                             (((__PLLSAI1N__) << RCC_PLLSAI1CFGR_PLLSAI1N_Pos) | \
                              ((((__PLLSAI1Q__) >> 1U) - 1U) << RCC_PLLSAI1CFGR_PLLSAI1Q_Pos) | \
                              ((((__PLLSAI1R__) >> 1U) - 1U) << RCC_PLLSAI1CFGR_PLLSAI1R_Pos) | \
                              (((__PLLSAI1P__) >> 4U) << RCC_PLLSAI1CFGR_PLLSAI1P_Pos)))

#endif                                    

#endif                                    

   
                                                                         
   
                                                                         
                                                                                
                                         
   
                                                                                          
                                                                                          
                                                                                   
                                                       
                                                                                  
   
                
    
#define __HAL_RCC_PLLSAI1_MULN_CONFIG(__PLLSAI1N__) \
                  MODIFY_REG(RCC->PLLSAI1CFGR, RCC_PLLSAI1CFGR_PLLSAI1N, (__PLLSAI1N__) << RCC_PLLSAI1CFGR_PLLSAI1N_Pos)

#if defined(RCC_PLLSAI1M_DIV_1_16_SUPPORT)

                                                                         
   
                                                                         
                                                                                
                                         
   
                                                                         
                                                                                   
   
                
    

#define __HAL_RCC_PLLSAI1_DIVM_CONFIG(__PLLSAI1M__) \
                  MODIFY_REG(RCC->PLLSAI1CFGR, RCC_PLLSAI1CFGR_PLLSAI1M, ((__PLLSAI1M__) - 1U) << RCC_PLLSAI1CFGR_PLLSAI1M_Pos)

#endif                                    

                                                                   
   
                                                                         
                                                                                
                                         
   
                                                                     
                                                                                         
                           
                                                                   
   
                
    
#if defined(RCC_PLLSAI1P_DIV_2_31_SUPPORT)

#define __HAL_RCC_PLLSAI1_DIVP_CONFIG(__PLLSAI1P__) \
                  MODIFY_REG(RCC->PLLSAI1CFGR, RCC_PLLSAI1CFGR_PLLSAI1PDIV, (__PLLSAI1P__) << RCC_PLLSAI1CFGR_PLLSAI1PDIV_Pos)

#else

#define __HAL_RCC_PLLSAI1_DIVP_CONFIG(__PLLSAI1P__) \
                  MODIFY_REG(RCC->PLLSAI1CFGR, RCC_PLLSAI1CFGR_PLLSAI1P, ((__PLLSAI1P__) >> 4U) << RCC_PLLSAI1CFGR_PLLSAI1P_Pos)

#endif                                    

                                                                   
   
                                                                         
                                                                                
                                         
   
                                                                                
                                                               
                                                                             
   
                
    
#define __HAL_RCC_PLLSAI1_DIVQ_CONFIG(__PLLSAI1Q__) \
                  MODIFY_REG(RCC->PLLSAI1CFGR, RCC_PLLSAI1CFGR_PLLSAI1Q, (((__PLLSAI1Q__) >> 1U) - 1U) << RCC_PLLSAI1CFGR_PLLSAI1Q_Pos)

                                                                   
   
                                                                         
                                                                                
                                         
   
                                                                     
                                                              
                                                                  
   
                
    
#define __HAL_RCC_PLLSAI1_DIVR_CONFIG(__PLLSAI1R__) \
                  MODIFY_REG(RCC->PLLSAI1CFGR, RCC_PLLSAI1CFGR_PLLSAI1R, (((__PLLSAI1R__) >> 1U) - 1U) << RCC_PLLSAI1CFGR_PLLSAI1R_Pos)

   
                                                    
                                                                                     
                
    

#define __HAL_RCC_PLLSAI1_ENABLE()  SET_BIT(RCC->CR, RCC_CR_PLLSAI1ON)

#define __HAL_RCC_PLLSAI1_DISABLE() CLEAR_BIT(RCC->CR, RCC_CR_PLLSAI1ON)

   
                                                                                                        
                                                                                             
                                              
                                                                          
                                                                               
                                                                                                         
                                                                                              
                                                                                                                   
                                                                                                      
                                                                                 
                
    

#define __HAL_RCC_PLLSAI1CLKOUT_ENABLE(__PLLSAI1_CLOCKOUT__)   SET_BIT(RCC->PLLSAI1CFGR, (__PLLSAI1_CLOCKOUT__))

#define __HAL_RCC_PLLSAI1CLKOUT_DISABLE(__PLLSAI1_CLOCKOUT__)  CLEAR_BIT(RCC->PLLSAI1CFGR, (__PLLSAI1_CLOCKOUT__))

   
                                                                                                  
                                                                          
                                                              
                                                                                                         
                                                                                              
                                                                                                                   
                                                                                                      
                                                                                 
                       
    
#define __HAL_RCC_GET_PLLSAI1CLKOUT_CONFIG(__PLLSAI1_CLOCKOUT__)  READ_BIT(RCC->PLLSAI1CFGR, (__PLLSAI1_CLOCKOUT__))

#endif                          

#if defined(RCC_PLLSAI2_SUPPORT)

   
                                                                                     
   
                                                                         
                                                                                
                                         
   
                 
                                                                              
                                                                                   
   
        
                                                                                          
                                                              
                                                                                   
                                                       
   
                                                                     
                                                                                         
                           
                                                        
   
                 
                                                                     
                                                               
                                                       
   
        
                                                                         
                                                               
   
                
    

#if defined(RCC_PLLSAI2M_DIV_1_16_SUPPORT)

# if defined(RCC_PLLSAI2P_DIV_2_31_SUPPORT) && defined(RCC_PLLSAI2Q_DIV_SUPPORT)

#define __HAL_RCC_PLLSAI2_CONFIG(__PLLSAI2M__, __PLLSAI2N__, __PLLSAI2P__, __PLLSAI2Q__, __PLLSAI2R__) \
                  MODIFY_REG(RCC->PLLSAI2CFGR, \
                             (RCC_PLLSAI2CFGR_PLLSAI2M | RCC_PLLSAI2CFGR_PLLSAI2N | RCC_PLLSAI2CFGR_PLLSAI2P | \
                              RCC_PLLSAI2CFGR_PLLSAI2Q | RCC_PLLSAI2CFGR_PLLSAI2R | RCC_PLLSAI2CFGR_PLLSAI2PDIV), \
                             ((((__PLLSAI2M__) - 1U) << RCC_PLLSAI2CFGR_PLLSAI2M_Pos) | \
                              ((__PLLSAI2N__) << RCC_PLLSAI2CFGR_PLLSAI2N_Pos) | \
                              ((((__PLLSAI2Q__) >> 1U) - 1U) << RCC_PLLSAI2CFGR_PLLSAI2Q_Pos) | \
                              ((((__PLLSAI2R__) >> 1U) - 1U) << RCC_PLLSAI2CFGR_PLLSAI2R_Pos) | \
                              ((uint32_t)(__PLLSAI2P__) << RCC_PLLSAI2CFGR_PLLSAI2PDIV_Pos)))

# elif defined(RCC_PLLSAI2P_DIV_2_31_SUPPORT)

#define __HAL_RCC_PLLSAI2_CONFIG(__PLLSAI2M__, __PLLSAI2N__, __PLLSAI2P__, __PLLSAI2R__) \
                  MODIFY_REG(RCC->PLLSAI2CFGR, \
                             (RCC_PLLSAI2CFGR_PLLSAI2M | RCC_PLLSAI2CFGR_PLLSAI2N | RCC_PLLSAI2CFGR_PLLSAI2P | \
                              RCC_PLLSAI2CFGR_PLLSAI2R | RCC_PLLSAI2CFGR_PLLSAI2PDIV), \
                             ((((__PLLSAI2M__) - 1U) << RCC_PLLSAI2CFGR_PLLSAI2M_Pos) | \
                              ((__PLLSAI2N__) << RCC_PLLSAI2CFGR_PLLSAI2N_Pos) | \
                              ((((__PLLSAI2R__) >> 1U) - 1U) << RCC_PLLSAI2CFGR_PLLSAI2R_Pos) | \
                              ((uint32_t)(__PLLSAI2P__) << RCC_PLLSAI2CFGR_PLLSAI2PDIV_Pos)))

# else

#define __HAL_RCC_PLLSAI2_CONFIG(__PLLSAI2M__, __PLLSAI2N__, __PLLSAI2P__, __PLLSAI2R__) \
                  MODIFY_REG(RCC->PLLSAI2CFGR, \
                             (RCC_PLLSAI2CFGR_PLLSAI2M | RCC_PLLSAI2CFGR_PLLSAI2N | RCC_PLLSAI2CFGR_PLLSAI2P | \
                              RCC_PLLSAI2CFGR_PLLSAI2R), \
                             ((((__PLLSAI2M__) - 1U) << RCC_PLLSAI2CFGR_PLLSAI2M_Pos) | \
                              ((__PLLSAI2N__) << RCC_PLLSAI2CFGR_PLLSAI2N_Pos) | \
                              ((((__PLLSAI2R__) >> 1U) - 1U) << RCC_PLLSAI2CFGR_PLLSAI2R_Pos) | \
                              (((__PLLSAI2P__) >> 4U) << RCC_PLLSAI2CFGR_PLLSAI2P_Pos)))

# endif                                                                

#else

#  if defined(RCC_PLLSAI2P_DIV_2_31_SUPPORT) && defined(RCC_PLLSAI2Q_DIV_SUPPORT)

#define __HAL_RCC_PLLSAI2_CONFIG(__PLLSAI2N__, __PLLSAI2P__, __PLLSAI2Q__, __PLLSAI2R__) \
                  MODIFY_REG(RCC->PLLSAI2CFGR, \
                             (RCC_PLLSAI2CFGR_PLLSAI2N | RCC_PLLSAI2CFGR_PLLSAI2P | \
                              RCC_PLLSAI2CFGR_PLLSAI2Q | RCC_PLLSAI2CFGR_PLLSAI2R | RCC_PLLSAI2CFGR_PLLSAI2PDIV), \
                             (((__PLLSAI2N__) << RCC_PLLSAI2CFGR_PLLSAI2N_Pos) | \
                              ((((__PLLSAI2Q__) >> 1U) - 1U) << RCC_PLLSAI2CFGR_PLLSAI2Q_Pos) | \
                              ((((__PLLSAI2R__) >> 1U) - 1U) << RCC_PLLSAI2CFGR_PLLSAI2R_Pos) | \
                              ((uint32_t)(__PLLSAI2P__) << RCC_PLLSAI2CFGR_PLLSAI2PDIV_Pos)))

# elif defined(RCC_PLLSAI2P_DIV_2_31_SUPPORT)

#define __HAL_RCC_PLLSAI2_CONFIG(__PLLSAI2N__, __PLLSAI2P__, __PLLSAI2R__) \
                  MODIFY_REG(RCC->PLLSAI2CFGR, \
                             (RCC_PLLSAI2CFGR_PLLSAI2N | RCC_PLLSAI2CFGR_PLLSAI2P | \
                              RCC_PLLSAI2CFGR_PLLSAI2R | RCC_PLLSAI2CFGR_PLLSAI2PDIV), \
                             (((__PLLSAI2N__) << RCC_PLLSAI2CFGR_PLLSAI2N_Pos) | \
                              ((((__PLLSAI2R__) >> 1U) - 1U) << RCC_PLLSAI2CFGR_PLLSAI2R_Pos) | \
                              ((uint32_t)(__PLLSAI2P__) << RCC_PLLSAI2CFGR_PLLSAI2PDIV_Pos)))

# else

#define __HAL_RCC_PLLSAI2_CONFIG(__PLLSAI2N__, __PLLSAI2P__, __PLLSAI2R__) \
                  MODIFY_REG(RCC->PLLSAI2CFGR, \
                             (RCC_PLLSAI2CFGR_PLLSAI2N | RCC_PLLSAI2CFGR_PLLSAI2P | \
                              RCC_PLLSAI2CFGR_PLLSAI2R), \
                             (((__PLLSAI2N__) << RCC_PLLSAI2CFGR_PLLSAI2N_Pos) | \
                              ((((__PLLSAI2R__) >> 1U) - 1U) << RCC_PLLSAI2CFGR_PLLSAI2R_Pos) | \
                              (((__PLLSAI2P__) >> 4U) << RCC_PLLSAI2CFGR_PLLSAI2P_Pos)))

# endif                                                                

#endif                                    


   
                                                                         
   
                                                                         
                                                                                
                                         
   
                                                                                          
                                                              
                                                                                   
                                                       
                                                                       
   
                
    
#define __HAL_RCC_PLLSAI2_MULN_CONFIG(__PLLSAI2N__) \
                  MODIFY_REG(RCC->PLLSAI2CFGR, RCC_PLLSAI2CFGR_PLLSAI2N, (__PLLSAI2N__) << RCC_PLLSAI2CFGR_PLLSAI2N_Pos)

#if defined(RCC_PLLSAI2M_DIV_1_16_SUPPORT)

                                                                         
   
                                                                         
                                                                                
                                         
   
                                                                         
                                                                                   
   
                
    

#define __HAL_RCC_PLLSAI2_DIVM_CONFIG(__PLLSAI2M__) \
                  MODIFY_REG(RCC->PLLSAI2CFGR, RCC_PLLSAI2CFGR_PLLSAI2M,  ((__PLLSAI2M__) - 1U) << RCC_PLLSAI2CFGR_PLLSAI2M_Pos)

#endif                                    

                                                                   
   
                                                                         
                                                                                
                                         
   
                                                       
                                                                   
                                                                       
   
                
    
#define __HAL_RCC_PLLSAI2_DIVP_CONFIG(__PLLSAI2P__) \
                  MODIFY_REG(RCC->PLLSAI2CFGR, RCC_PLLSAI2CFGR_PLLSAI2P, ((__PLLSAI2P__) >> 4U) << RCC_PLLSAI2CFGR_PLLSAI2P_Pos)

#if defined(RCC_PLLSAI2Q_DIV_SUPPORT)

                                                                   
   
                                                                         
                                                                                
                                         
   
                                                                                
                                                               
                                                                             
   
                
    
#define __HAL_RCC_PLLSAI2_DIVQ_CONFIG(__PLLSAI2Q__) \
                  MODIFY_REG(RCC->PLLSAI2CFGR, RCC_PLLSAI2CFGR_PLLSAI2Q, (((__PLLSAI2Q__) >> 1U) - 1U) << RCC_PLLSAI2CFGR_PLLSAI2Q_Pos)

#endif                               

                                                                   
   
                                                                         
                                                                                
                                         
   
                                                       
                                                               
                                                                      
   
                
    
#define __HAL_RCC_PLLSAI2_DIVR_CONFIG(__PLLSAI2R__) \
                  MODIFY_REG(RCC->PLLSAI2CFGR, RCC_PLLSAI2CFGR_PLLSAI2R, (((__PLLSAI2R__) >> 1U) - 1U) << RCC_PLLSAI2CFGR_PLLSAI2R_Pos)

   
                                                    
                                                                                     
                
    

#define __HAL_RCC_PLLSAI2_ENABLE()  SET_BIT(RCC->CR, RCC_CR_PLLSAI2ON)

#define __HAL_RCC_PLLSAI2_DISABLE() CLEAR_BIT(RCC->CR, RCC_CR_PLLSAI2ON)

   
                                                                                                              
                                                                                             
                                              
                                                                          
                                                                               
                 
                                                                                                         
                                                                                                      
                                                                                 
        
                 
                                                                                                         
                                                                                                      
                                                                                 
        
                 
                                                                                                         
                                                                                                      
                                                                                 
        
                
    

#define __HAL_RCC_PLLSAI2CLKOUT_ENABLE(__PLLSAI2_CLOCKOUT__)  SET_BIT(RCC->PLLSAI2CFGR, (__PLLSAI2_CLOCKOUT__))

#define __HAL_RCC_PLLSAI2CLKOUT_DISABLE(__PLLSAI2_CLOCKOUT__) CLEAR_BIT(RCC->PLLSAI2CFGR, (__PLLSAI2_CLOCKOUT__))

   
                                                                                                        
                                                                          
                                                               
                 
                                                                                                         
                                                                                                      
                                                                                 
        
                 
                                                                                                         
                                                                                                      
                                                                                 
        
                 
                                                                                                         
                                                                                                      
                                                                                 
        
                       
    
#define __HAL_RCC_GET_PLLSAI2CLKOUT_CONFIG(__PLLSAI2_CLOCKOUT__)  READ_BIT(RCC->PLLSAI2CFGR, (__PLLSAI2_CLOCKOUT__))

#endif                          

#if defined(SAI1)

   
                                                     
                                                                                   
                                                                                     
                                                               
                                                                                                
                 
                                                                                                                         
        
                                                                                                                            
                                                                                          
                 
                                                                   
        
   
                 
                                                                                                             
        
   
                
    
#if defined(STM32L4P5xx) || defined(STM32L4Q5xx) || defined(STM32L4R5xx) || defined(STM32L4R7xx) || defined(STM32L4R9xx) || defined(STM32L4S5xx) || defined(STM32L4S7xx) || defined(STM32L4S9xx)
#define __HAL_RCC_SAI1_CONFIG(__SAI1_CLKSOURCE__)\
                  MODIFY_REG(RCC->CCIPR2, RCC_CCIPR2_SAI1SEL, (__SAI1_CLKSOURCE__))
#else
#define __HAL_RCC_SAI1_CONFIG(__SAI1_CLKSOURCE__)\
                  MODIFY_REG(RCC->CCIPR, RCC_CCIPR_SAI1SEL, (__SAI1_CLKSOURCE__))
#endif                                                                                                                           

                                               
                                                                
                                                                                                
                 
                                                                                                                         
        
                                                                                                                            
                                                                                          
   
                                                                                                                         
                                                                           
   
    
#if defined(STM32L4P5xx) || defined(STM32L4Q5xx) || defined(STM32L4R5xx) || defined(STM32L4R7xx) || defined(STM32L4R9xx) || defined(STM32L4S5xx) || defined(STM32L4S7xx) || defined(STM32L4S9xx)
#define __HAL_RCC_GET_SAI1_SOURCE() (READ_BIT(RCC->CCIPR2, RCC_CCIPR2_SAI1SEL))
#else
#define __HAL_RCC_GET_SAI1_SOURCE() (READ_BIT(RCC->CCIPR, RCC_CCIPR_SAI1SEL))
#endif                                                                                                                           

#endif           

#if defined(SAI2)

   
                                                     
                                                                                   
                                                                                     
                                                               
                                                                                                
                                                                                                
                                                                                         
                                                                                          
                 
                                                                   
        
   
                
    
#if defined(STM32L4P5xx) || defined(STM32L4Q5xx) || defined(STM32L4R5xx) || defined(STM32L4R7xx) || defined(STM32L4R9xx) || defined(STM32L4S5xx) || defined(STM32L4S7xx) || defined(STM32L4S9xx)
#define __HAL_RCC_SAI2_CONFIG(__SAI2_CLKSOURCE__ )\
                  MODIFY_REG(RCC->CCIPR2, RCC_CCIPR2_SAI2SEL, (__SAI2_CLKSOURCE__))
#else
#define __HAL_RCC_SAI2_CONFIG(__SAI2_CLKSOURCE__ )\
                  MODIFY_REG(RCC->CCIPR, RCC_CCIPR_SAI2SEL, (__SAI2_CLKSOURCE__))
#endif                                                                                                                           

                                               
                                                                
                                                                                                
                                                                                                
                                                                                         
                                                                                          
    
#if defined(STM32L4P5xx) || defined(STM32L4Q5xx) || defined(STM32L4R5xx) || defined(STM32L4R7xx) || defined(STM32L4R9xx) || defined(STM32L4S5xx) || defined(STM32L4S7xx) || defined(STM32L4S9xx)
#define __HAL_RCC_GET_SAI2_SOURCE() (READ_BIT(RCC->CCIPR2, RCC_CCIPR2_SAI2SEL))
#else
#define __HAL_RCC_GET_SAI2_SOURCE() (READ_BIT(RCC->CCIPR, RCC_CCIPR_SAI2SEL))
#endif                                                                                                                           

#endif           

                                                        
   
                                                               
                                                               
                                                                              
                                                                          
                                                                                      
                
    
#define __HAL_RCC_I2C1_CONFIG(__I2C1_CLKSOURCE__) \
                  MODIFY_REG(RCC->CCIPR, RCC_CCIPR_I2C1SEL, (__I2C1_CLKSOURCE__))

                                               
                                                                
                                                                              
                                                                          
                                                                                      
    
#define __HAL_RCC_GET_I2C1_SOURCE() (READ_BIT(RCC->CCIPR, RCC_CCIPR_I2C1SEL))

#if defined(I2C2)

                                                        
   
                                                               
                                                               
                                                                              
                                                                          
                                                                                      
                
    
#define __HAL_RCC_I2C2_CONFIG(__I2C2_CLKSOURCE__) \
                  MODIFY_REG(RCC->CCIPR, RCC_CCIPR_I2C2SEL, (__I2C2_CLKSOURCE__))

                                               
                                                                
                                                                              
                                                                          
                                                                                      
    
#define __HAL_RCC_GET_I2C2_SOURCE() (READ_BIT(RCC->CCIPR, RCC_CCIPR_I2C2SEL))

#endif           

                                                        
   
                                                               
                                                               
                                                                              
                                                                          
                                                                                      
                
    
#define __HAL_RCC_I2C3_CONFIG(__I2C3_CLKSOURCE__) \
                  MODIFY_REG(RCC->CCIPR, RCC_CCIPR_I2C3SEL, (__I2C3_CLKSOURCE__))

                                               
                                                                
                                                                              
                                                                          
                                                                                      
    
#define __HAL_RCC_GET_I2C3_SOURCE() (READ_BIT(RCC->CCIPR, RCC_CCIPR_I2C3SEL))

#if defined(I2C4)

                                                        
   
                                                               
                                                               
                                                                              
                                                                          
                                                                                      
                
    
#define __HAL_RCC_I2C4_CONFIG(__I2C4_CLKSOURCE__) \
                  MODIFY_REG(RCC->CCIPR2, RCC_CCIPR2_I2C4SEL, (__I2C4_CLKSOURCE__))

                                               
                                                                
                                                                              
                                                                          
                                                                                      
    
#define __HAL_RCC_GET_I2C4_SOURCE() (READ_BIT(RCC->CCIPR2, RCC_CCIPR2_I2C4SEL))

#endif           


                                                            
   
                                                                   
                                                               
                                                                                  
                                                                              
                                                                                          
                                                                             
                
    
#define __HAL_RCC_USART1_CONFIG(__USART1_CLKSOURCE__) \
                  MODIFY_REG(RCC->CCIPR, RCC_CCIPR_USART1SEL, (__USART1_CLKSOURCE__))

                                                 
                                                                
                                                                                  
                                                                              
                                                                                          
                                                                              
    
#define __HAL_RCC_GET_USART1_SOURCE() (READ_BIT(RCC->CCIPR, RCC_CCIPR_USART1SEL))

                                                            
   
                                                                   
                                                               
                                                                                  
                                                                              
                                                                                          
                                                                              
                
    
#define __HAL_RCC_USART2_CONFIG(__USART2_CLKSOURCE__) \
                  MODIFY_REG(RCC->CCIPR, RCC_CCIPR_USART2SEL, (__USART2_CLKSOURCE__))

                                                 
                                                                
                                                                                  
                                                                              
                                                                                          
                                                                              
    
#define __HAL_RCC_GET_USART2_SOURCE() (READ_BIT(RCC->CCIPR, RCC_CCIPR_USART2SEL))

#if defined(USART3)

                                                            
   
                                                                   
                                                               
                                                                                  
                                                                              
                                                                                          
                                                                              
                
    
#define __HAL_RCC_USART3_CONFIG(__USART3_CLKSOURCE__) \
                  MODIFY_REG(RCC->CCIPR, RCC_CCIPR_USART3SEL, (__USART3_CLKSOURCE__))

                                                 
                                                                
                                                                                  
                                                                              
                                                                                          
                                                                              
    
#define __HAL_RCC_GET_USART3_SOURCE() (READ_BIT(RCC->CCIPR, RCC_CCIPR_USART3SEL))

#endif             

#if defined(UART4)

                                                          
   
                                                                 
                                                               
                                                                                
                                                                            
                                                                                        
                                                                            
                
    
#define __HAL_RCC_UART4_CONFIG(__UART4_CLKSOURCE__) \
                  MODIFY_REG(RCC->CCIPR, RCC_CCIPR_UART4SEL, (__UART4_CLKSOURCE__))

                                                
                                                                
                                                                                
                                                                            
                                                                                        
                                                                            
    
#define __HAL_RCC_GET_UART4_SOURCE() (READ_BIT(RCC->CCIPR, RCC_CCIPR_UART4SEL))

#endif            

#if defined(UART5)

                                                          
   
                                                                 
                                                               
                                                                                
                                                                            
                                                                                        
                                                                            
                
    
#define __HAL_RCC_UART5_CONFIG(__UART5_CLKSOURCE__) \
                  MODIFY_REG(RCC->CCIPR, RCC_CCIPR_UART5SEL, (__UART5_CLKSOURCE__))

                                                
                                                                
                                                                                
                                                                            
                                                                                        
                                                                            
    
#define __HAL_RCC_GET_UART5_SOURCE() (READ_BIT(RCC->CCIPR, RCC_CCIPR_UART5SEL))

#endif            

                                                              
   
                                                                     
                                                               
                                                                                    
                                                                                
                                                                                            
                                                                                
                
    
#define __HAL_RCC_LPUART1_CONFIG(__LPUART1_CLKSOURCE__) \
                  MODIFY_REG(RCC->CCIPR, RCC_CCIPR_LPUART1SEL, (__LPUART1_CLKSOURCE__))

                                                  
                                                                
                                                                                    
                                                                                
                                                                                            
                                                                                
    
#define __HAL_RCC_GET_LPUART1_SOURCE() (READ_BIT(RCC->CCIPR, RCC_CCIPR_LPUART1SEL))

                                                            
   
                                                                   
                                                               
                                                                                  
                                                                              
                                                                              
                                                                              
                
    
#define __HAL_RCC_LPTIM1_CONFIG(__LPTIM1_CLKSOURCE__) \
                  MODIFY_REG(RCC->CCIPR, RCC_CCIPR_LPTIM1SEL, (__LPTIM1_CLKSOURCE__))

                                                 
                                                                
                                                                                   
                                                                               
                                                                                        
                                                                               
    
#define __HAL_RCC_GET_LPTIM1_SOURCE() (READ_BIT(RCC->CCIPR, RCC_CCIPR_LPTIM1SEL))

                                                            
   
                                                                   
                                                               
                                                                                  
                                                                              
                                                                              
                                                                              
                
    
#define __HAL_RCC_LPTIM2_CONFIG(__LPTIM2_CLKSOURCE__) \
                  MODIFY_REG(RCC->CCIPR, RCC_CCIPR_LPTIM2SEL, (__LPTIM2_CLKSOURCE__))

                                                 
                                                                
                                                                                   
                                                                               
                                                                                        
                                                                               
    
#define __HAL_RCC_GET_LPTIM2_SOURCE() (READ_BIT(RCC->CCIPR, RCC_CCIPR_LPTIM2SEL))

#if defined(SDMMC1)

                                                
   
                 
                                                                             
        
   
                 
                                                                             
        
   
                                                                   
                                                              
                 
                                                                                                              
                                                                              
                                                                                                
        
                 
                                                                                                         
                                                                              
                                                                                                
        
                 
                                                                                                         
                                                                              
                                                                                                
                                                                                         
        
                                                                                        
                
    
#if defined(RCC_CCIPR2_SDMMCSEL)
#define __HAL_RCC_SDMMC1_CONFIG(__SDMMC1_CLKSOURCE__) \
                  do \
                  {  \
                    if((__SDMMC1_CLKSOURCE__) == RCC_SDMMC1CLKSOURCE_PLLP) \
                    { \
                      SET_BIT(RCC->CCIPR2, RCC_CCIPR2_SDMMCSEL); \
                    } \
                    else \
                    { \
                      CLEAR_BIT(RCC->CCIPR2, RCC_CCIPR2_SDMMCSEL); \
                      MODIFY_REG(RCC->CCIPR, RCC_CCIPR_CLK48SEL, (__SDMMC1_CLKSOURCE__)); \
                    } \
                  } while(0)
#else
#define __HAL_RCC_SDMMC1_CONFIG(__SDMMC1_CLKSOURCE__) \
                  MODIFY_REG(RCC->CCIPR, RCC_CCIPR_CLK48SEL, (__SDMMC1_CLKSOURCE__))
#endif                          

                                          
                                                                
                 
                                                                                                              
                                                                              
                                                                                                             
        
                 
                                                                                                         
                                                                              
                                                                                                             
        
                 
                                                                                                         
                                                                              
                                                                                                             
                                                                                                             
        
                                                                                                     
    
#if defined(RCC_CCIPR2_SDMMCSEL)
#define __HAL_RCC_GET_SDMMC1_SOURCE() \
                  ((READ_BIT(RCC->CCIPR2, RCC_CCIPR2_SDMMCSEL) != 0U) ? RCC_SDMMC1CLKSOURCE_PLLP : (READ_BIT(RCC->CCIPR, RCC_CCIPR_CLK48SEL)))
#else
#define __HAL_RCC_GET_SDMMC1_SOURCE() \
                  (READ_BIT(RCC->CCIPR, RCC_CCIPR_CLK48SEL))
#endif                          

#endif             

                                             
   
                                                                             
   
                                                             
                                                              
                 
                                                                                                        
        
                 
                                                                                                         
        
                                                                        
                                                                                      
                                                                              
                
    
#define __HAL_RCC_RNG_CONFIG(__RNG_CLKSOURCE__) \
                  MODIFY_REG(RCC->CCIPR, RCC_CCIPR_CLK48SEL, (__RNG_CLKSOURCE__))

                                       
                                                                
                 
                                                                                                        
        
                 
                                                                                                         
        
                                                                        
                                                                                                       
                                                                                               
    
#define __HAL_RCC_GET_RNG_SOURCE() (READ_BIT(RCC->CCIPR, RCC_CCIPR_CLK48SEL))

#if defined(USB_OTG_FS) || defined(USB)

                                                      
   
                                                                             
   
                                                             
                                                              
                 
                                                                                                          
        
                 
                                                                                                     
        
                                                                        
                                                                                                       
                                                                                               
                
    
#define __HAL_RCC_USB_CONFIG(__USB_CLKSOURCE__) \
                  MODIFY_REG(RCC->CCIPR, RCC_CCIPR_CLK48SEL, (__USB_CLKSOURCE__))

                                              
                                                                
                 
                                                                                                          
        
                 
                                                                                                     
        
                                                                        
                                                                                                       
                                                                                               
    
#define __HAL_RCC_GET_USB_SOURCE() (READ_BIT(RCC->CCIPR, RCC_CCIPR_CLK48SEL))

#endif                        

#if defined(RCC_CCIPR_ADCSEL)

                                                       
                                                                               
                                                              
                                                                              
                                                                                      
                 
                                                                                                                                          
        
                                                                                    
                
    
#define __HAL_RCC_ADC_CONFIG(__ADC_CLKSOURCE__) \
                  MODIFY_REG(RCC->CCIPR, RCC_CCIPR_ADCSEL, (__ADC_CLKSOURCE__))

                                              
                                                                
                                                                              
                                                                                      
                 
                                                                                                                                          
        
                                                                                    
    
#define __HAL_RCC_GET_ADC_SOURCE() (READ_BIT(RCC->CCIPR, RCC_CCIPR_ADCSEL))
#else

                                              
                                                                
                                                                              
                                                                                    
    
#define __HAL_RCC_GET_ADC_SOURCE() ((__HAL_RCC_ADC_IS_CLK_ENABLED() != 0U) ? RCC_ADCCLKSOURCE_SYSCLK : RCC_ADCCLKSOURCE_NONE)

#endif                       

#if defined(SWPMI1)

                                                
                                                                   
                                                              
                                                                                        
                                                                                    
                
    
#define __HAL_RCC_SWPMI1_CONFIG(__SWPMI1_CLKSOURCE__) \
                  MODIFY_REG(RCC->CCIPR, RCC_CCIPR_SWPMI1SEL, (__SWPMI1_CLKSOURCE__))

                                                 
                                                                
                                                                                        
                                                                                    
    
#define __HAL_RCC_GET_SWPMI1_SOURCE() (READ_BIT(RCC->CCIPR, RCC_CCIPR_SWPMI1SEL))

#endif             

#if defined(DFSDM1_Filter0)
                                                
                                                                   
                                                              
                                                                                        
                                                                                          
                
    
#if defined(STM32L4P5xx) || defined(STM32L4Q5xx) || defined(STM32L4R5xx) || defined(STM32L4R7xx) || defined(STM32L4R9xx) || defined(STM32L4S5xx) || defined(STM32L4S7xx) || defined(STM32L4S9xx)
#define __HAL_RCC_DFSDM1_CONFIG(__DFSDM1_CLKSOURCE__) \
                  MODIFY_REG(RCC->CCIPR2, RCC_CCIPR2_DFSDM1SEL, (__DFSDM1_CLKSOURCE__))
#else
#define __HAL_RCC_DFSDM1_CONFIG(__DFSDM1_CLKSOURCE__) \
                  MODIFY_REG(RCC->CCIPR, RCC_CCIPR_DFSDM1SEL, (__DFSDM1_CLKSOURCE__))
#endif                                                                                                                           

                                                 
                                                                
                                                                                        
                                                                                          
    
#if defined(STM32L4P5xx) || defined(STM32L4Q5xx) || defined(STM32L4R5xx) || defined(STM32L4R7xx) || defined(STM32L4R9xx) || defined(STM32L4S5xx) || defined(STM32L4S7xx) || defined(STM32L4S9xx)
#define __HAL_RCC_GET_DFSDM1_SOURCE() (READ_BIT(RCC->CCIPR2, RCC_CCIPR2_DFSDM1SEL))
#else
#define __HAL_RCC_GET_DFSDM1_SOURCE() (READ_BIT(RCC->CCIPR, RCC_CCIPR_DFSDM1SEL))
#endif                                                                                                                           

#if defined(STM32L4P5xx) || defined(STM32L4Q5xx) || defined(STM32L4R5xx) || defined(STM32L4R7xx) || defined(STM32L4R9xx) || defined(STM32L4S5xx) || defined(STM32L4S7xx) || defined(STM32L4S9xx)

                                                      
                                                                              
                                                              
                                                                                                 
                                                                                                
                                                                                                
                
    
#define __HAL_RCC_DFSDM1AUDIO_CONFIG(__DFSDM1AUDIO_CLKSOURCE__) \
                  MODIFY_REG(RCC->CCIPR2, RCC_CCIPR2_ADFSDM1SEL, (__DFSDM1AUDIO_CLKSOURCE__))

                                                       
                                                                
                                                                                                 
                                                                                                
                                                                                                
    
#define __HAL_RCC_GET_DFSDM1AUDIO_SOURCE() (READ_BIT(RCC->CCIPR2, RCC_CCIPR2_ADFSDM1SEL))

#endif                                                                                                                           

#endif                     

#if defined(LTDC)

                                              
                                                               
                                                              
                                                                                                                     
                                                                                                                     
                                                                                                                     
                                                                                                                      
                
    
#define __HAL_RCC_LTDC_CONFIG(__LTDC_CLKSOURCE__) \
                  MODIFY_REG(RCC->CCIPR2, RCC_CCIPR2_PLLSAI2DIVR, (__LTDC_CLKSOURCE__))

                                               
                                                                
                                                                                                                     
                                                                                                                     
                                                                                                                     
                                                                                                                      
    
#define __HAL_RCC_GET_LTDC_SOURCE() (READ_BIT(RCC->CCIPR2, RCC_CCIPR2_PLLSAI2DIVR))

#endif           

#if defined(DSI )

                                             
                                                             
                                                              
                                                                                     
                                                                                               
                
    
#define __HAL_RCC_DSI_CONFIG(__DSI_CLKSOURCE__) \
                  MODIFY_REG(RCC->CCIPR2, RCC_CCIPR2_DSISEL, (__DSI_CLKSOURCE__))

                                              
                                                                
                                                                                     
                                                                                               
    
#define __HAL_RCC_GET_DSI_SOURCE() (READ_BIT(RCC->CCIPR2, RCC_CCIPR2_DSISEL))

#endif          

#if defined(OCTOSPI1) || defined(OCTOSPI2)

                                                 
                                                                  
                                                              
                                                                                         
                                                                                      
                                                                                                
                
    
#define __HAL_RCC_OSPI_CONFIG(__OSPI_CLKSOURCE__) \
                  MODIFY_REG(RCC->CCIPR2, RCC_CCIPR2_OSPISEL, (__OSPI_CLKSOURCE__))

                                                  
                                                                
                                                                                         
                                                                                      
                                                                                                
    
#define __HAL_RCC_GET_OSPI_SOURCE() (READ_BIT(RCC->CCIPR2, RCC_CCIPR2_OSPISEL))

#endif                           

                                                                           
                                                                   
      
    
#if defined(RCC_PLLSAI1_SUPPORT)

                                       
                
    
#define __HAL_RCC_PLLSAI1_ENABLE_IT()  SET_BIT(RCC->CIER, RCC_CIER_PLLSAI1RDYIE)

                                        
                
    
#define __HAL_RCC_PLLSAI1_DISABLE_IT() CLEAR_BIT(RCC->CIER, RCC_CIER_PLLSAI1RDYIE)

                                                      
                
    
#define __HAL_RCC_PLLSAI1_CLEAR_IT()   WRITE_REG(RCC->CICR, RCC_CICR_PLLSAI1RDYC)

                                                                  
                          
    
#define __HAL_RCC_PLLSAI1_GET_IT_SOURCE()     (READ_BIT(RCC->CIFR, RCC_CIFR_PLLSAI1RDYF) == RCC_CIFR_PLLSAI1RDYF)

                                                            
                          
    
#define __HAL_RCC_PLLSAI1_GET_FLAG()   (READ_BIT(RCC->CR, RCC_CR_PLLSAI1RDY) == (RCC_CR_PLLSAI1RDY))

#endif                          

#if defined(RCC_PLLSAI2_SUPPORT)

                                       
                
    
#define __HAL_RCC_PLLSAI2_ENABLE_IT()  SET_BIT(RCC->CIER, RCC_CIER_PLLSAI2RDYIE)

                                        
                
    
#define __HAL_RCC_PLLSAI2_DISABLE_IT() CLEAR_BIT(RCC->CIER, RCC_CIER_PLLSAI2RDYIE)

                                                      
                
    
#define __HAL_RCC_PLLSAI2_CLEAR_IT()   WRITE_REG(RCC->CICR, RCC_CICR_PLLSAI2RDYC)

                                                                      
                          
    
#define __HAL_RCC_PLLSAI2_GET_IT_SOURCE()     (READ_BIT(RCC->CIFR, RCC_CIFR_PLLSAI2RDYF) == RCC_CIFR_PLLSAI2RDYF)

                                                            
                          
    
#define __HAL_RCC_PLLSAI2_GET_FLAG()   (READ_BIT(RCC->CR, RCC_CR_PLLSAI2RDY) == (RCC_CR_PLLSAI2RDY))

#endif                          


   
                                                          
                
    
#define __HAL_RCC_LSECSS_EXTI_ENABLE_IT()      SET_BIT(EXTI->IMR1, RCC_EXTI_LINE_LSECSS)

   
                                                           
                
    
#define __HAL_RCC_LSECSS_EXTI_DISABLE_IT()     CLEAR_BIT(EXTI->IMR1, RCC_EXTI_LINE_LSECSS)

   
                                             
                 
    
#define __HAL_RCC_LSECSS_EXTI_ENABLE_EVENT()   SET_BIT(EXTI->EMR1, RCC_EXTI_LINE_LSECSS)

   
                                              
                 
    
#define __HAL_RCC_LSECSS_EXTI_DISABLE_EVENT()  CLEAR_BIT(EXTI->EMR1, RCC_EXTI_LINE_LSECSS)


   
                                                                      
                 
    
#define __HAL_RCC_LSECSS_EXTI_ENABLE_FALLING_EDGE()  SET_BIT(EXTI->FTSR1, RCC_EXTI_LINE_LSECSS)


   
                                                                      
                 
    
#define __HAL_RCC_LSECSS_EXTI_DISABLE_FALLING_EDGE()  CLEAR_BIT(EXTI->FTSR1, RCC_EXTI_LINE_LSECSS)


   
                                                                     
                 
    
#define __HAL_RCC_LSECSS_EXTI_ENABLE_RISING_EDGE()   SET_BIT(EXTI->RTSR1, RCC_EXTI_LINE_LSECSS)

   
                                                                     
                 
    
#define __HAL_RCC_LSECSS_EXTI_DISABLE_RISING_EDGE()  CLEAR_BIT(EXTI->RTSR1, RCC_EXTI_LINE_LSECSS)

   
                                                                              
                 
    
#define __HAL_RCC_LSECSS_EXTI_ENABLE_RISING_FALLING_EDGE()  \
  do {                                                      \
    __HAL_RCC_LSECSS_EXTI_ENABLE_RISING_EDGE();             \
    __HAL_RCC_LSECSS_EXTI_ENABLE_FALLING_EDGE();            \
  } while(0)

   
                                                                               
                 
    
#define __HAL_RCC_LSECSS_EXTI_DISABLE_RISING_FALLING_EDGE()  \
  do {                                                       \
    __HAL_RCC_LSECSS_EXTI_DISABLE_RISING_EDGE();             \
    __HAL_RCC_LSECSS_EXTI_DISABLE_FALLING_EDGE();            \
  } while(0)

   
                                                                                     
                                         
    
#define __HAL_RCC_LSECSS_EXTI_GET_FLAG()       (READ_BIT(EXTI->PR1, RCC_EXTI_LINE_LSECSS) == RCC_EXTI_LINE_LSECSS)

   
                                           
                 
    
#define __HAL_RCC_LSECSS_EXTI_CLEAR_FLAG()     WRITE_REG(EXTI->PR1, RCC_EXTI_LINE_LSECSS)

   
                                                                      
                 
    
#define __HAL_RCC_LSECSS_EXTI_GENERATE_SWIT()  SET_BIT(EXTI->SWIER1, RCC_EXTI_LINE_LSECSS)


#if defined(CRS)

   
                                                
                                                                            
                                                                           
                                                                     
                                                                      
                                                                                      
                                                                    
                
    
#define __HAL_RCC_CRS_ENABLE_IT(__INTERRUPT__)   SET_BIT(CRS->CR, (__INTERRUPT__))

   
                                                 
                                                                             
                                                                           
                                                                     
                                                                      
                                                                                      
                                                                    
                
    
#define __HAL_RCC_CRS_DISABLE_IT(__INTERRUPT__)  CLEAR_BIT(CRS->CR, (__INTERRUPT__))

                                                                
                                                                      
                                                              
                                                                     
                                                                      
                                                                                      
                                                                    
                                                          
    
#define __HAL_RCC_CRS_GET_IT_SOURCE(__INTERRUPT__)  ((READ_BIT(CRS->CR, (__INTERRUPT__)) != 0U) ? SET : RESET)

                                                
                                                                       
                                                                          
                                                                     
                                                                      
                                                                                      
                                                                    
                                                                                       
                                                                   
                                                                     
    
                       
#define  RCC_CRS_IT_ERROR_MASK                 (RCC_CRS_IT_TRIMOVF | RCC_CRS_IT_SYNCERR | RCC_CRS_IT_SYNCMISS)

#define __HAL_RCC_CRS_CLEAR_IT(__INTERRUPT__)  do { \
                                                 if(((__INTERRUPT__) & RCC_CRS_IT_ERROR_MASK) != 0U) \
                                                 { \
                                                   WRITE_REG(CRS->ICR, CRS_ICR_ERRC | ((__INTERRUPT__) & ~RCC_CRS_IT_ERROR_MASK)); \
                                                 } \
                                                 else \
                                                 { \
                                                   WRITE_REG(CRS->ICR, (__INTERRUPT__)); \
                                                 } \
                                               } while(0)

   
                                                               
                                                 
                                                               
                                                             
                                                              
                                                  
                                                            
                                                                               
                                                           
                                                             
                                                    
    
#define __HAL_RCC_CRS_GET_FLAG(__FLAG__)  (READ_BIT(CRS->ISR, (__FLAG__)) == (__FLAG__))

   
                                         
                                                
                                                               
                                                             
                                                              
                                                  
                                                            
                                                                               
                                                           
                                                             
                                                                                                                                     
                
    

                         
#define RCC_CRS_FLAG_ERROR_MASK                (RCC_CRS_FLAG_TRIMOVF | RCC_CRS_FLAG_SYNCERR | RCC_CRS_FLAG_SYNCMISS)

#define __HAL_RCC_CRS_CLEAR_FLAG(__FLAG__)     do { \
                                                 if(((__FLAG__) & RCC_CRS_FLAG_ERROR_MASK) != 0U) \
                                                 { \
                                                   WRITE_REG(CRS->ICR, CRS_ICR_ERRC | ((__FLAG__) & ~RCC_CRS_FLAG_ERROR_MASK)); \
                                                 } \
                                                 else \
                                                 { \
                                                   WRITE_REG(CRS->ICR, (__FLAG__)); \
                                                 } \
                                               } while(0)

#endif          

   
      
    

#if defined(CRS)

                                                                     
      
    
   
                                                                    
                                                                                  
                
    
#define __HAL_RCC_CRS_FREQ_ERROR_COUNTER_ENABLE()  SET_BIT(CRS->CR, CRS_CR_CEN)

   
                                                                     
                
    
#define __HAL_RCC_CRS_FREQ_ERROR_COUNTER_DISABLE() CLEAR_BIT(CRS->CR, CRS_CR_CEN)

   
                                                                  
                                                                                         
                
    
#define __HAL_RCC_CRS_AUTOMATIC_CALIB_ENABLE()     SET_BIT(CRS->CR, CRS_CR_AUTOTRIMEN)

   
                                                                             
                
    
#define __HAL_RCC_CRS_AUTOMATIC_CALIB_DISABLE()    CLEAR_BIT(CRS->CR, CRS_CR_AUTOTRIMEN)

   
                                                                                                              
                                                                                                                     
                                                                                                       
                                                                                                   
                                             
                                                      
                                                                    
                
    
#define __HAL_RCC_CRS_RELOADVALUE_CALCULATE(__FTARGET__, __FSYNC__)  (((__FTARGET__) / (__FSYNC__)) - 1U)

   
      
    

#endif          

#if defined(PSSI)

                                                                 
      
    

#define __HAL_RCC_PSSI_CLK_ENABLE()             __HAL_RCC_DCMI_CLK_ENABLE()

#define __HAL_RCC_PSSI_CLK_DISABLE()            __HAL_RCC_DCMI_CLK_DISABLE()

#define __HAL_RCC_PSSI_IS_CLK_ENABLED()         __HAL_RCC_DCMI_IS_CLK_ENABLED()

#define __HAL_RCC_PSSI_IS_CLK_DISABLED()        __HAL_RCC_DCMI_IS_CLK_DISABLED()

#define __HAL_RCC_PSSI_FORCE_RESET()            __HAL_RCC_DCMI_FORCE_RESET()

#define __HAL_RCC_PSSI_RELEASE_RESET()          __HAL_RCC_DCMI_RELEASE_RESET()

#define __HAL_RCC_PSSI_CLK_SLEEP_ENABLE()       __HAL_RCC_DCMI_CLK_SLEEP_ENABLE()

#define __HAL_RCC_PSSI_CLK_SLEEP_DISABLE()      __HAL_RCC_DCMI_CLK_SLEEP_DISABLE()

#define __HAL_RCC_PSSI_IS_CLK_SLEEP_ENABLED()    __HAL_RCC_DCMI_IS_CLK_SLEEP_ENABLED()

#define __HAL_RCC_PSSI_IS_CLK_SLEEP_DISABLED()  __HAL_RCC_DCMI_IS_CLK_SLEEP_DISABLED()

   
      
    

#endif           

   
      
    

                                                                                
                                        
      
    

                                               
      
    

HAL_StatusTypeDef HAL_RCCEx_PeriphCLKConfig(RCC_PeriphCLKInitTypeDef  *PeriphClkInit);
void              HAL_RCCEx_GetPeriphCLKConfig(RCC_PeriphCLKInitTypeDef  *PeriphClkInit);
uint32_t          HAL_RCCEx_GetPeriphCLKFreq(uint32_t PeriphClk);

   
      
    

                                               
      
    
#if defined(RCC_PLLSAI1_SUPPORT)

HAL_StatusTypeDef HAL_RCCEx_EnablePLLSAI1(RCC_PLLSAI1InitTypeDef  *PLLSAI1Init);
HAL_StatusTypeDef HAL_RCCEx_DisablePLLSAI1(void);

#endif                          

#if defined(RCC_PLLSAI2_SUPPORT)

HAL_StatusTypeDef HAL_RCCEx_EnablePLLSAI2(RCC_PLLSAI2InitTypeDef  *PLLSAI2Init);
HAL_StatusTypeDef HAL_RCCEx_DisablePLLSAI2(void);

#endif                          

void              HAL_RCCEx_WakeUpStopCLKConfig(uint32_t WakeUpClk);
void              HAL_RCCEx_StandbyMSIRangeConfig(uint32_t MSIRange);
void              HAL_RCCEx_EnableLSECSS(void);
void              HAL_RCCEx_DisableLSECSS(void);
void              HAL_RCCEx_EnableLSECSS_IT(void);
void              HAL_RCCEx_LSECSS_IRQHandler(void);
void              HAL_RCCEx_LSECSS_Callback(void);
void              HAL_RCCEx_EnableLSCO(uint32_t LSCOSource);
void              HAL_RCCEx_DisableLSCO(void);
void              HAL_RCCEx_EnableMSIPLLMode(void);
void              HAL_RCCEx_DisableMSIPLLMode(void);
#if defined (OCTOSPI1) && defined (OCTOSPI2)
void              HAL_RCCEx_OCTOSPIDelayConfig(uint32_t Delay1, uint32_t Delay2);
#endif                           

   
      
    

#if defined(CRS)

                                               
      
    

void              HAL_RCCEx_CRSConfig(RCC_CRSInitTypeDef *pInit);
void              HAL_RCCEx_CRSSoftwareSynchronizationGenerate(void);
void              HAL_RCCEx_CRSGetSynchronizationInfo(RCC_CRSSynchroInfoTypeDef *pSynchroInfo);
uint32_t          HAL_RCCEx_CRSWaitSynchronization(uint32_t Timeout);
void              HAL_RCCEx_CRS_IRQHandler(void);
void              HAL_RCCEx_CRS_SyncOkCallback(void);
void              HAL_RCCEx_CRS_SyncWarnCallback(void);
void              HAL_RCCEx_CRS_ExpectedSyncCallback(void);
void              HAL_RCCEx_CRS_ErrorCallback(uint32_t Error);

   
      
    

#endif          

   
      
    

                                                                                
                                       
      
    
                                           
#if defined(STM32L412xx) || defined(STM32L422xx)
#define RCC_PERIPHCLOCK_ALL             (RCC_PERIPHCLK_USART1 | RCC_PERIPHCLK_USART2 | RCC_PERIPHCLK_USART3 | \
                                         RCC_PERIPHCLK_LPUART1 | \
                                         RCC_PERIPHCLK_I2C1 | RCC_PERIPHCLK_I2C2 | RCC_PERIPHCLK_I2C3 | \
                                         RCC_PERIPHCLK_LPTIM1 | RCC_PERIPHCLK_LPTIM2 | \
                                         RCC_PERIPHCLK_USB | RCC_PERIPHCLK_ADC | RCC_PERIPHCLK_RTC | \
                                         RCC_PERIPHCLK_RNG)
#elif defined(STM32L431xx)
#define RCC_PERIPHCLOCK_ALL             (RCC_PERIPHCLK_USART1 | RCC_PERIPHCLK_USART2 | RCC_PERIPHCLK_USART3 | \
                                         RCC_PERIPHCLK_LPUART1 | \
                                         RCC_PERIPHCLK_I2C1 | RCC_PERIPHCLK_I2C2 | RCC_PERIPHCLK_I2C3 | \
                                         RCC_PERIPHCLK_LPTIM1 | RCC_PERIPHCLK_LPTIM2 | \
                                         RCC_PERIPHCLK_SAI1 | \
                                         RCC_PERIPHCLK_ADC | RCC_PERIPHCLK_SWPMI1 | \
                                         RCC_PERIPHCLK_RTC | RCC_PERIPHCLK_RNG | RCC_PERIPHCLK_SDMMC1)
#elif defined(STM32L432xx) || defined(STM32L442xx)
#define RCC_PERIPHCLOCK_ALL             (RCC_PERIPHCLK_USART1 | RCC_PERIPHCLK_USART2 | \
                                         RCC_PERIPHCLK_LPUART1 | \
                                         RCC_PERIPHCLK_I2C1 | RCC_PERIPHCLK_I2C3 | \
                                         RCC_PERIPHCLK_LPTIM1 | RCC_PERIPHCLK_LPTIM2 | \
                                         RCC_PERIPHCLK_SAI1 | \
                                         RCC_PERIPHCLK_USB | RCC_PERIPHCLK_ADC | \
                                         RCC_PERIPHCLK_SWPMI1 | RCC_PERIPHCLK_RTC | RCC_PERIPHCLK_RNG)
#elif defined(STM32L433xx) || defined(STM32L443xx)
#define RCC_PERIPHCLOCK_ALL             (RCC_PERIPHCLK_USART1 | RCC_PERIPHCLK_USART2 | RCC_PERIPHCLK_USART3 |\
                                         RCC_PERIPHCLK_LPUART1 | \
                                         RCC_PERIPHCLK_I2C1 | RCC_PERIPHCLK_I2C2 | RCC_PERIPHCLK_I2C3 | \
                                         RCC_PERIPHCLK_LPTIM1 | RCC_PERIPHCLK_LPTIM2 | \
                                         RCC_PERIPHCLK_SAI1 | \
                                         RCC_PERIPHCLK_USB | RCC_PERIPHCLK_ADC | RCC_PERIPHCLK_SWPMI1 | \
                                         RCC_PERIPHCLK_RTC | RCC_PERIPHCLK_RNG | RCC_PERIPHCLK_SDMMC1)
#elif defined(STM32L451xx)
#define RCC_PERIPHCLOCK_ALL             (RCC_PERIPHCLK_USART1 | RCC_PERIPHCLK_USART2 | RCC_PERIPHCLK_USART3 |\
                                         RCC_PERIPHCLK_UART4 | \
                                         RCC_PERIPHCLK_LPUART1 | \
                                         RCC_PERIPHCLK_I2C1 | RCC_PERIPHCLK_I2C2 | RCC_PERIPHCLK_I2C3 | \
                                         RCC_PERIPHCLK_I2C4 | \
                                         RCC_PERIPHCLK_LPTIM1 | RCC_PERIPHCLK_LPTIM2 | \
                                         RCC_PERIPHCLK_SAI1 | \
                                         RCC_PERIPHCLK_ADC | RCC_PERIPHCLK_DFSDM1 | \
                                         RCC_PERIPHCLK_RTC | RCC_PERIPHCLK_RNG | RCC_PERIPHCLK_SDMMC1)
#elif defined(STM32L452xx) || defined(STM32L462xx)
#define RCC_PERIPHCLOCK_ALL             (RCC_PERIPHCLK_USART1 | RCC_PERIPHCLK_USART2 | RCC_PERIPHCLK_USART3 |\
                                         RCC_PERIPHCLK_UART4 | \
                                         RCC_PERIPHCLK_LPUART1 | \
                                         RCC_PERIPHCLK_I2C1 | RCC_PERIPHCLK_I2C2 | RCC_PERIPHCLK_I2C3 | \
                                         RCC_PERIPHCLK_I2C4 | \
                                         RCC_PERIPHCLK_LPTIM1 | RCC_PERIPHCLK_LPTIM2 | \
                                         RCC_PERIPHCLK_SAI1 | \
                                         RCC_PERIPHCLK_USB | RCC_PERIPHCLK_ADC | RCC_PERIPHCLK_DFSDM1 | \
                                         RCC_PERIPHCLK_RTC | RCC_PERIPHCLK_RNG | RCC_PERIPHCLK_SDMMC1)
#elif defined(STM32L471xx)
#define RCC_PERIPHCLOCK_ALL             (RCC_PERIPHCLK_USART1 | RCC_PERIPHCLK_USART2 | RCC_PERIPHCLK_USART3 | \
                                         RCC_PERIPHCLK_UART4 | RCC_PERIPHCLK_UART5 | \
                                         RCC_PERIPHCLK_LPUART1 | \
                                         RCC_PERIPHCLK_I2C1 | RCC_PERIPHCLK_I2C2 | RCC_PERIPHCLK_I2C3 | \
                                         RCC_PERIPHCLK_LPTIM1 | RCC_PERIPHCLK_LPTIM2 | \
                                         RCC_PERIPHCLK_SAI1 | RCC_PERIPHCLK_SAI2 | \
                                         RCC_PERIPHCLK_ADC | RCC_PERIPHCLK_SWPMI1 | RCC_PERIPHCLK_DFSDM1 | \
                                         RCC_PERIPHCLK_RTC | RCC_PERIPHCLK_RNG | RCC_PERIPHCLK_SDMMC1)
#elif defined(STM32L496xx) || defined(STM32L4A6xx)
#define RCC_PERIPHCLOCK_ALL             (RCC_PERIPHCLK_USART1 | RCC_PERIPHCLK_USART2 | RCC_PERIPHCLK_USART3 | \
                                         RCC_PERIPHCLK_UART4 | RCC_PERIPHCLK_UART5 | \
                                         RCC_PERIPHCLK_LPUART1 | \
                                         RCC_PERIPHCLK_I2C1 | RCC_PERIPHCLK_I2C2 | RCC_PERIPHCLK_I2C3 | \
                                         RCC_PERIPHCLK_I2C4 | \
                                         RCC_PERIPHCLK_LPTIM1 | RCC_PERIPHCLK_LPTIM2 | \
                                         RCC_PERIPHCLK_SAI1 | RCC_PERIPHCLK_SAI2 | \
                                         RCC_PERIPHCLK_USB | \
                                         RCC_PERIPHCLK_ADC | RCC_PERIPHCLK_SWPMI1 | RCC_PERIPHCLK_DFSDM1 | \
                                         RCC_PERIPHCLK_RTC | RCC_PERIPHCLK_RNG | RCC_PERIPHCLK_SDMMC1)
#elif defined(STM32L4P5xx) || defined(STM32L4Q5xx)
#define RCC_PERIPHCLOCK_ALL             (RCC_PERIPHCLK_USART1 | RCC_PERIPHCLK_USART2 | RCC_PERIPHCLK_USART3 | \
                                         RCC_PERIPHCLK_UART4 | RCC_PERIPHCLK_UART5 | \
                                         RCC_PERIPHCLK_LPUART1 | \
                                         RCC_PERIPHCLK_I2C1 | RCC_PERIPHCLK_I2C2 | RCC_PERIPHCLK_I2C3 | \
                                         RCC_PERIPHCLK_I2C4 | \
                                         RCC_PERIPHCLK_LPTIM1 | RCC_PERIPHCLK_LPTIM2 | \
                                         RCC_PERIPHCLK_SAI1 | RCC_PERIPHCLK_SAI2 | \
                                         RCC_PERIPHCLK_USB | \
                                         RCC_PERIPHCLK_ADC | RCC_PERIPHCLK_DFSDM1 | RCC_PERIPHCLK_DFSDM1AUDIO | \
                                         RCC_PERIPHCLK_RTC | RCC_PERIPHCLK_RNG | RCC_PERIPHCLK_SDMMC1 | \
                                         RCC_PERIPHCLK_OSPI | RCC_PERIPHCLK_LTDC)
#elif defined(STM32L4R5xx) || defined(STM32L4S5xx)
#define RCC_PERIPHCLOCK_ALL             (RCC_PERIPHCLK_USART1 | RCC_PERIPHCLK_USART2 | RCC_PERIPHCLK_USART3 | \
                                         RCC_PERIPHCLK_UART4 | RCC_PERIPHCLK_UART5 | \
                                         RCC_PERIPHCLK_LPUART1 | \
                                         RCC_PERIPHCLK_I2C1 | RCC_PERIPHCLK_I2C2 | RCC_PERIPHCLK_I2C3 | \
                                         RCC_PERIPHCLK_I2C4 | \
                                         RCC_PERIPHCLK_LPTIM1 | RCC_PERIPHCLK_LPTIM2 | \
                                         RCC_PERIPHCLK_SAI1 | RCC_PERIPHCLK_SAI2 | \
                                         RCC_PERIPHCLK_USB | \
                                         RCC_PERIPHCLK_ADC | RCC_PERIPHCLK_DFSDM1 | RCC_PERIPHCLK_DFSDM1AUDIO | \
                                         RCC_PERIPHCLK_RTC | RCC_PERIPHCLK_RNG | RCC_PERIPHCLK_SDMMC1 | \
                                         RCC_PERIPHCLK_OSPI)
#elif defined(STM32L4R7xx) || defined(STM32L4S7xx)
#define RCC_PERIPHCLOCK_ALL             (RCC_PERIPHCLK_USART1 | RCC_PERIPHCLK_USART2 | RCC_PERIPHCLK_USART3 | \
                                         RCC_PERIPHCLK_UART4 | RCC_PERIPHCLK_UART5 | \
                                         RCC_PERIPHCLK_LPUART1 | \
                                         RCC_PERIPHCLK_I2C1 | RCC_PERIPHCLK_I2C2 | RCC_PERIPHCLK_I2C3 | \
                                         RCC_PERIPHCLK_I2C4 | \
                                         RCC_PERIPHCLK_LPTIM1 | RCC_PERIPHCLK_LPTIM2 | \
                                         RCC_PERIPHCLK_SAI1 | RCC_PERIPHCLK_SAI2 | \
                                         RCC_PERIPHCLK_USB | \
                                         RCC_PERIPHCLK_ADC | RCC_PERIPHCLK_DFSDM1 | RCC_PERIPHCLK_DFSDM1AUDIO | \
                                         RCC_PERIPHCLK_RTC | RCC_PERIPHCLK_RNG | RCC_PERIPHCLK_SDMMC1 | \
                                         RCC_PERIPHCLK_OSPI | RCC_PERIPHCLK_LTDC)
#elif defined(STM32L4R9xx) || defined(STM32L4S9xx)
#define RCC_PERIPHCLOCK_ALL             (RCC_PERIPHCLK_USART1 | RCC_PERIPHCLK_USART2 | RCC_PERIPHCLK_USART3 | \
                                         RCC_PERIPHCLK_UART4 | RCC_PERIPHCLK_UART5 | \
                                         RCC_PERIPHCLK_LPUART1 | \
                                         RCC_PERIPHCLK_I2C1 | RCC_PERIPHCLK_I2C2 | RCC_PERIPHCLK_I2C3 | \
                                         RCC_PERIPHCLK_I2C4 | \
                                         RCC_PERIPHCLK_LPTIM1 | RCC_PERIPHCLK_LPTIM2 | \
                                         RCC_PERIPHCLK_SAI1 | RCC_PERIPHCLK_SAI2 | \
                                         RCC_PERIPHCLK_USB | \
                                         RCC_PERIPHCLK_ADC | RCC_PERIPHCLK_DFSDM1 | RCC_PERIPHCLK_DFSDM1AUDIO | \
                                         RCC_PERIPHCLK_RTC | RCC_PERIPHCLK_RNG | RCC_PERIPHCLK_SDMMC1 | \
                                         RCC_PERIPHCLK_OSPI | RCC_PERIPHCLK_LTDC | RCC_PERIPHCLK_DSI)
#else
#define RCC_PERIPHCLOCK_ALL             (RCC_PERIPHCLK_USART1 | RCC_PERIPHCLK_USART2 | RCC_PERIPHCLK_USART3 | \
                                         RCC_PERIPHCLK_UART4 | RCC_PERIPHCLK_UART5 | \
                                         RCC_PERIPHCLK_LPUART1 | \
                                         RCC_PERIPHCLK_I2C1 | RCC_PERIPHCLK_I2C2 | RCC_PERIPHCLK_I2C3 | \
                                         RCC_PERIPHCLK_LPTIM1 | RCC_PERIPHCLK_LPTIM2 | \
                                         RCC_PERIPHCLK_SAI1 | RCC_PERIPHCLK_SAI2 | \
                                         RCC_PERIPHCLK_USB | \
                                         RCC_PERIPHCLK_ADC | RCC_PERIPHCLK_SWPMI1 | RCC_PERIPHCLK_DFSDM1 | \
                                         RCC_PERIPHCLK_RTC | RCC_PERIPHCLK_RNG | RCC_PERIPHCLK_SDMMC1)
#endif                                 

   
      
    

                                                                                
                                    
      
    

#define IS_RCC_LSCOSOURCE(__SOURCE__) (((__SOURCE__) == RCC_LSCOSOURCE_LSI) || \
                                       ((__SOURCE__) == RCC_LSCOSOURCE_LSE))

#define IS_RCC_PERIPHCLOCK(__SELECTION__)   ((((__SELECTION__) & RCC_PERIPHCLOCK_ALL) != 0x00u) && \
                                             (((__SELECTION__) & ~RCC_PERIPHCLOCK_ALL) == 0x00u))

#define IS_RCC_USART1CLKSOURCE(__SOURCE__)  \
               (((__SOURCE__) == RCC_USART1CLKSOURCE_PCLK2)  || \
                ((__SOURCE__) == RCC_USART1CLKSOURCE_SYSCLK) || \
                ((__SOURCE__) == RCC_USART1CLKSOURCE_LSE)    || \
                ((__SOURCE__) == RCC_USART1CLKSOURCE_HSI))

#define IS_RCC_USART2CLKSOURCE(__SOURCE__)  \
               (((__SOURCE__) == RCC_USART2CLKSOURCE_PCLK1)  || \
                ((__SOURCE__) == RCC_USART2CLKSOURCE_SYSCLK) || \
                ((__SOURCE__) == RCC_USART2CLKSOURCE_LSE)    || \
                ((__SOURCE__) == RCC_USART2CLKSOURCE_HSI))

#if defined(USART3)

#define IS_RCC_USART3CLKSOURCE(__SOURCE__)  \
               (((__SOURCE__) == RCC_USART3CLKSOURCE_PCLK1)  || \
                ((__SOURCE__) == RCC_USART3CLKSOURCE_SYSCLK) || \
                ((__SOURCE__) == RCC_USART3CLKSOURCE_LSE)    || \
                ((__SOURCE__) == RCC_USART3CLKSOURCE_HSI))

#endif             

#if defined(UART4)

#define IS_RCC_UART4CLKSOURCE(__SOURCE__)  \
               (((__SOURCE__) == RCC_UART4CLKSOURCE_PCLK1)  || \
                ((__SOURCE__) == RCC_UART4CLKSOURCE_SYSCLK) || \
                ((__SOURCE__) == RCC_UART4CLKSOURCE_LSE)    || \
                ((__SOURCE__) == RCC_UART4CLKSOURCE_HSI))

#endif            

#if defined(UART5)

#define IS_RCC_UART5CLKSOURCE(__SOURCE__)  \
               (((__SOURCE__) == RCC_UART5CLKSOURCE_PCLK1)  || \
                ((__SOURCE__) == RCC_UART5CLKSOURCE_SYSCLK) || \
                ((__SOURCE__) == RCC_UART5CLKSOURCE_LSE)    || \
                ((__SOURCE__) == RCC_UART5CLKSOURCE_HSI))

#endif            

#define IS_RCC_LPUART1CLKSOURCE(__SOURCE__)  \
               (((__SOURCE__) == RCC_LPUART1CLKSOURCE_PCLK1)  || \
                ((__SOURCE__) == RCC_LPUART1CLKSOURCE_SYSCLK) || \
                ((__SOURCE__) == RCC_LPUART1CLKSOURCE_LSE)    || \
                ((__SOURCE__) == RCC_LPUART1CLKSOURCE_HSI))

#define IS_RCC_I2C1CLKSOURCE(__SOURCE__)   \
               (((__SOURCE__) == RCC_I2C1CLKSOURCE_PCLK1) || \
                ((__SOURCE__) == RCC_I2C1CLKSOURCE_SYSCLK)|| \
                ((__SOURCE__) == RCC_I2C1CLKSOURCE_HSI))

#if defined(I2C2)

#define IS_RCC_I2C2CLKSOURCE(__SOURCE__)   \
               (((__SOURCE__) == RCC_I2C2CLKSOURCE_PCLK1) || \
                ((__SOURCE__) == RCC_I2C2CLKSOURCE_SYSCLK)|| \
                ((__SOURCE__) == RCC_I2C2CLKSOURCE_HSI))

#endif           

#define IS_RCC_I2C3CLKSOURCE(__SOURCE__)   \
               (((__SOURCE__) == RCC_I2C3CLKSOURCE_PCLK1) || \
                ((__SOURCE__) == RCC_I2C3CLKSOURCE_SYSCLK)|| \
                ((__SOURCE__) == RCC_I2C3CLKSOURCE_HSI))

#if defined(I2C4)

#define IS_RCC_I2C4CLKSOURCE(__SOURCE__)   \
               (((__SOURCE__) == RCC_I2C4CLKSOURCE_PCLK1) || \
                ((__SOURCE__) == RCC_I2C4CLKSOURCE_SYSCLK)|| \
                ((__SOURCE__) == RCC_I2C4CLKSOURCE_HSI))

#endif           

#if defined(RCC_PLLSAI2_SUPPORT)

#if defined(STM32L4P5xx) || defined(STM32L4Q5xx) || defined(STM32L4R5xx) || defined(STM32L4R7xx) || defined(STM32L4R9xx) || defined(STM32L4S5xx) || defined(STM32L4S7xx) || defined(STM32L4S9xx)
#define IS_RCC_SAI1CLK(__SOURCE__)   \
               (((__SOURCE__) == RCC_SAI1CLKSOURCE_PLLSAI1) || \
                ((__SOURCE__) == RCC_SAI1CLKSOURCE_PLLSAI2) || \
                ((__SOURCE__) == RCC_SAI1CLKSOURCE_PLL)     || \
                ((__SOURCE__) == RCC_SAI1CLKSOURCE_PIN)     || \
                ((__SOURCE__) == RCC_SAI1CLKSOURCE_HSI))
#else
#define IS_RCC_SAI1CLK(__SOURCE__)   \
               (((__SOURCE__) == RCC_SAI1CLKSOURCE_PLLSAI1) || \
                ((__SOURCE__) == RCC_SAI1CLKSOURCE_PLLSAI2) || \
                ((__SOURCE__) == RCC_SAI1CLKSOURCE_PLL)     || \
                ((__SOURCE__) == RCC_SAI1CLKSOURCE_PIN))
#endif                                                                                                                           

#elif defined(RCC_PLLSAI1_SUPPORT)

#define IS_RCC_SAI1CLK(__SOURCE__)   \
               (((__SOURCE__) == RCC_SAI1CLKSOURCE_PLLSAI1) || \
                ((__SOURCE__) == RCC_SAI1CLKSOURCE_PLL)     || \
                ((__SOURCE__) == RCC_SAI1CLKSOURCE_PIN))

#endif                          

#if defined(RCC_PLLSAI2_SUPPORT)

#if defined(STM32L4P5xx) || defined(STM32L4Q5xx) || defined(STM32L4R5xx) || defined(STM32L4R7xx) || defined(STM32L4R9xx) || defined(STM32L4S5xx) || defined(STM32L4S7xx) || defined(STM32L4S9xx)
#define IS_RCC_SAI2CLK(__SOURCE__)   \
               (((__SOURCE__) == RCC_SAI2CLKSOURCE_PLLSAI1) || \
                ((__SOURCE__) == RCC_SAI2CLKSOURCE_PLLSAI2) || \
                ((__SOURCE__) == RCC_SAI2CLKSOURCE_PLL)     || \
                ((__SOURCE__) == RCC_SAI2CLKSOURCE_PIN)     || \
                ((__SOURCE__) == RCC_SAI2CLKSOURCE_HSI))
#else
#define IS_RCC_SAI2CLK(__SOURCE__)   \
               (((__SOURCE__) == RCC_SAI2CLKSOURCE_PLLSAI1) || \
                ((__SOURCE__) == RCC_SAI2CLKSOURCE_PLLSAI2) || \
                ((__SOURCE__) == RCC_SAI2CLKSOURCE_PLL)     || \
                ((__SOURCE__) == RCC_SAI2CLKSOURCE_PIN))
#endif                                                                                                                           

#endif                          

#define IS_RCC_LPTIM1CLK(__SOURCE__)  \
               (((__SOURCE__) == RCC_LPTIM1CLKSOURCE_PCLK1) || \
                ((__SOURCE__) == RCC_LPTIM1CLKSOURCE_LSI)   || \
                ((__SOURCE__) == RCC_LPTIM1CLKSOURCE_HSI)   || \
                ((__SOURCE__) == RCC_LPTIM1CLKSOURCE_LSE))

#define IS_RCC_LPTIM2CLK(__SOURCE__)  \
               (((__SOURCE__) == RCC_LPTIM2CLKSOURCE_PCLK1) || \
                ((__SOURCE__) == RCC_LPTIM2CLKSOURCE_LSI)   || \
                ((__SOURCE__) == RCC_LPTIM2CLKSOURCE_HSI)   || \
                ((__SOURCE__) == RCC_LPTIM2CLKSOURCE_LSE))

#if defined(SDMMC1)
#if defined(RCC_HSI48_SUPPORT) && defined(RCC_CCIPR2_SDMMCSEL)

#define IS_RCC_SDMMC1CLKSOURCE(__SOURCE__)  \
               (((__SOURCE__) == RCC_SDMMC1CLKSOURCE_PLLP)    || \
                ((__SOURCE__) == RCC_SDMMC1CLKSOURCE_HSI48)   || \
                ((__SOURCE__) == RCC_SDMMC1CLKSOURCE_PLLSAI1) || \
                ((__SOURCE__) == RCC_SDMMC1CLKSOURCE_PLL)     || \
                ((__SOURCE__) == RCC_SDMMC1CLKSOURCE_MSI))

#elif defined(RCC_HSI48_SUPPORT)

#define IS_RCC_SDMMC1CLKSOURCE(__SOURCE__)  \
               (((__SOURCE__) == RCC_SDMMC1CLKSOURCE_HSI48)   || \
                ((__SOURCE__) == RCC_SDMMC1CLKSOURCE_PLLSAI1) || \
                ((__SOURCE__) == RCC_SDMMC1CLKSOURCE_PLL)     || \
                ((__SOURCE__) == RCC_SDMMC1CLKSOURCE_MSI))
#else

#define IS_RCC_SDMMC1CLKSOURCE(__SOURCE__)  \
               (((__SOURCE__) == RCC_SDMMC1CLKSOURCE_NONE)    || \
                ((__SOURCE__) == RCC_SDMMC1CLKSOURCE_PLLSAI1) || \
                ((__SOURCE__) == RCC_SDMMC1CLKSOURCE_PLL)     || \
                ((__SOURCE__) == RCC_SDMMC1CLKSOURCE_MSI))

#endif                        
#endif             

#if defined(RCC_HSI48_SUPPORT)

#if defined(RCC_PLLSAI1_SUPPORT)
#define IS_RCC_RNGCLKSOURCE(__SOURCE__)  \
               (((__SOURCE__) == RCC_RNGCLKSOURCE_HSI48)   || \
                ((__SOURCE__) == RCC_RNGCLKSOURCE_PLLSAI1) || \
                ((__SOURCE__) == RCC_RNGCLKSOURCE_PLL)     || \
                ((__SOURCE__) == RCC_RNGCLKSOURCE_MSI))
#else
#define IS_RCC_RNGCLKSOURCE(__SOURCE__)  \
               (((__SOURCE__) == RCC_RNGCLKSOURCE_HSI48)   || \
                ((__SOURCE__) == RCC_RNGCLKSOURCE_PLL)     || \
                ((__SOURCE__) == RCC_RNGCLKSOURCE_MSI))
#endif                          

#else

#define IS_RCC_RNGCLKSOURCE(__SOURCE__)  \
               (((__SOURCE__) == RCC_RNGCLKSOURCE_NONE)    || \
                ((__SOURCE__) == RCC_RNGCLKSOURCE_PLLSAI1) || \
                ((__SOURCE__) == RCC_RNGCLKSOURCE_PLL)     || \
                ((__SOURCE__) == RCC_RNGCLKSOURCE_MSI))

#endif                        

#if defined(USB_OTG_FS) || defined(USB)
#if defined(RCC_HSI48_SUPPORT)

#if defined(RCC_PLLSAI1_SUPPORT)
#define IS_RCC_USBCLKSOURCE(__SOURCE__)  \
               (((__SOURCE__) == RCC_USBCLKSOURCE_HSI48)   || \
                ((__SOURCE__) == RCC_USBCLKSOURCE_PLLSAI1) || \
                ((__SOURCE__) == RCC_USBCLKSOURCE_PLL)     || \
                ((__SOURCE__) == RCC_USBCLKSOURCE_MSI))
#else
#define IS_RCC_USBCLKSOURCE(__SOURCE__)  \
               (((__SOURCE__) == RCC_USBCLKSOURCE_HSI48)   || \
                ((__SOURCE__) == RCC_USBCLKSOURCE_PLL)     || \
                ((__SOURCE__) == RCC_USBCLKSOURCE_MSI))
#endif                          

#else

#define IS_RCC_USBCLKSOURCE(__SOURCE__)  \
               (((__SOURCE__) == RCC_USBCLKSOURCE_NONE)    || \
                ((__SOURCE__) == RCC_USBCLKSOURCE_PLLSAI1) || \
                ((__SOURCE__) == RCC_USBCLKSOURCE_PLL)     || \
                ((__SOURCE__) == RCC_USBCLKSOURCE_MSI))

#endif                        
#endif                        

#if defined(STM32L471xx) || defined(STM32L475xx) || defined(STM32L476xx) || defined(STM32L485xx) || defined(STM32L486xx) || defined(STM32L496xx) || defined(STM32L4A6xx)

#define IS_RCC_ADCCLKSOURCE(__SOURCE__)  \
               (((__SOURCE__) == RCC_ADCCLKSOURCE_NONE)    || \
                ((__SOURCE__) == RCC_ADCCLKSOURCE_PLLSAI1) || \
                ((__SOURCE__) == RCC_ADCCLKSOURCE_PLLSAI2) || \
                ((__SOURCE__) == RCC_ADCCLKSOURCE_SYSCLK))

#else

#if defined(RCC_PLLSAI1_SUPPORT)
#define IS_RCC_ADCCLKSOURCE(__SOURCE__)  \
               (((__SOURCE__) == RCC_ADCCLKSOURCE_NONE)    || \
                ((__SOURCE__) == RCC_ADCCLKSOURCE_PLLSAI1) || \
                ((__SOURCE__) == RCC_ADCCLKSOURCE_SYSCLK))
#else
#define IS_RCC_ADCCLKSOURCE(__SOURCE__)  \
               (((__SOURCE__) == RCC_ADCCLKSOURCE_NONE)    || \
                ((__SOURCE__) == RCC_ADCCLKSOURCE_SYSCLK))
#endif                          

#endif                                                                                                            

#if defined(SWPMI1)

#define IS_RCC_SWPMI1CLKSOURCE(__SOURCE__)  \
               (((__SOURCE__) == RCC_SWPMI1CLKSOURCE_PCLK1) || \
                ((__SOURCE__) == RCC_SWPMI1CLKSOURCE_HSI))

#endif             

#if defined(DFSDM1_Filter0)

#define IS_RCC_DFSDM1CLKSOURCE(__SOURCE__)  \
               (((__SOURCE__) == RCC_DFSDM1CLKSOURCE_PCLK2) || \
                ((__SOURCE__) == RCC_DFSDM1CLKSOURCE_SYSCLK))

#if defined(STM32L4P5xx) || defined(STM32L4Q5xx) || defined(STM32L4R5xx) || defined(STM32L4R7xx) || defined(STM32L4R9xx) || defined(STM32L4S5xx) || defined(STM32L4S7xx) || defined(STM32L4S9xx)

#define IS_RCC_DFSDM1AUDIOCLKSOURCE(__SOURCE__)  \
               (((__SOURCE__) == RCC_DFSDM1AUDIOCLKSOURCE_SAI1) || \
                ((__SOURCE__) == RCC_DFSDM1AUDIOCLKSOURCE_HSI) || \
                ((__SOURCE__) == RCC_DFSDM1AUDIOCLKSOURCE_MSI))

#endif                                                                                                                           

#endif                     

#if defined(LTDC)

#define IS_RCC_LTDCCLKSOURCE(__SOURCE__)  \
               (((__SOURCE__) == RCC_LTDCCLKSOURCE_PLLSAI2_DIV2) || \
                ((__SOURCE__) == RCC_LTDCCLKSOURCE_PLLSAI2_DIV4) || \
                ((__SOURCE__) == RCC_LTDCCLKSOURCE_PLLSAI2_DIV8) || \
                ((__SOURCE__) == RCC_LTDCCLKSOURCE_PLLSAI2_DIV16))

#endif           

#if defined(DSI)

#define IS_RCC_DSICLKSOURCE(__SOURCE__)  \
               (((__SOURCE__) == RCC_DSICLKSOURCE_DSIPHY) || \
                ((__SOURCE__) == RCC_DSICLKSOURCE_PLLSAI2))

#endif          

#if defined(OCTOSPI1) || defined(OCTOSPI2)

#define IS_RCC_OSPICLKSOURCE(__SOURCE__)  \
               (((__SOURCE__) == RCC_OSPICLKSOURCE_SYSCLK) || \
                ((__SOURCE__) == RCC_OSPICLKSOURCE_MSI) || \
                ((__SOURCE__) == RCC_OSPICLKSOURCE_PLL))

#endif                           

#if defined(RCC_PLLSAI1_SUPPORT)

#define IS_RCC_PLLSAI1SOURCE(__VALUE__)    IS_RCC_PLLSOURCE(__VALUE__)

#if defined(RCC_PLLSAI1M_DIV_1_16_SUPPORT)
#define IS_RCC_PLLSAI1M_VALUE(__VALUE__)   ((1U <= (__VALUE__)) && ((__VALUE__) <= 16U))
#else
#define IS_RCC_PLLSAI1M_VALUE(__VALUE__)   ((1U <= (__VALUE__)) && ((__VALUE__) <= 8U))
#endif                                    

#if defined(RCC_PLLSAI1N_MUL_8_127_SUPPORT)
#define IS_RCC_PLLSAI1N_VALUE(__VALUE__)   ((8U <= (__VALUE__)) && ((__VALUE__) <= 127U))
#else
#define IS_RCC_PLLSAI1N_VALUE(__VALUE__)   ((8U <= (__VALUE__)) && ((__VALUE__) <= 86U))
#endif                                     

#if defined(RCC_PLLSAI1P_DIV_2_31_SUPPORT)
#define IS_RCC_PLLSAI1P_VALUE(__VALUE__)   (((__VALUE__) >= 2U) && ((__VALUE__) <= 31U))
#else
#define IS_RCC_PLLSAI1P_VALUE(__VALUE__)   (((__VALUE__) == 7U) || ((__VALUE__) == 17U))
#endif                                    

#define IS_RCC_PLLSAI1Q_VALUE(__VALUE__)   (((__VALUE__) == 2U) || ((__VALUE__) == 4U) || \
                                            ((__VALUE__) == 6U) || ((__VALUE__) == 8U))

#define IS_RCC_PLLSAI1R_VALUE(__VALUE__)   (((__VALUE__) == 2U) || ((__VALUE__) == 4U) || \
                                            ((__VALUE__) == 6U) || ((__VALUE__) == 8U))

#endif                          

#if defined(RCC_PLLSAI2_SUPPORT)

#define IS_RCC_PLLSAI2SOURCE(__VALUE__)    IS_RCC_PLLSOURCE(__VALUE__)

#if defined(RCC_PLLSAI2M_DIV_1_16_SUPPORT)
#define IS_RCC_PLLSAI2M_VALUE(__VALUE__)   ((1U <= (__VALUE__)) && ((__VALUE__) <= 16U))
#else
#define IS_RCC_PLLSAI2M_VALUE(__VALUE__)   ((1U <= (__VALUE__)) && ((__VALUE__) <= 8U))
#endif                                    

#if defined(RCC_PLLSAI2N_MUL_8_127_SUPPORT)
#define IS_RCC_PLLSAI2N_VALUE(__VALUE__)   ((8U <= (__VALUE__)) && ((__VALUE__) <= 127U))
#else
#define IS_RCC_PLLSAI2N_VALUE(__VALUE__)   ((8U <= (__VALUE__)) && ((__VALUE__) <= 86U))
#endif                                     

#if defined(RCC_PLLSAI2P_DIV_2_31_SUPPORT)
#define IS_RCC_PLLSAI2P_VALUE(__VALUE__)   (((__VALUE__) >= 2U) && ((__VALUE__) <= 31U))
#else
#define IS_RCC_PLLSAI2P_VALUE(__VALUE__)   (((__VALUE__) == 7U) || ((__VALUE__) == 17U))
#endif                                    

#if defined(RCC_PLLSAI2Q_DIV_SUPPORT)
#define IS_RCC_PLLSAI2Q_VALUE(__VALUE__)   (((__VALUE__) == 2U) || ((__VALUE__) == 4U) || \
                                            ((__VALUE__) == 6U) || ((__VALUE__) == 8U))
#endif                               

#define IS_RCC_PLLSAI2R_VALUE(__VALUE__)   (((__VALUE__) == 2U) || ((__VALUE__) == 4U) || \
                                            ((__VALUE__) == 6U) || ((__VALUE__) == 8U))

#endif                          

#if defined (OCTOSPI1) && defined (OCTOSPI2)
#define IS_RCC_OCTOSPIDELAY(__DELAY__)     (((__DELAY__) <= 0xFU))
#endif                           

#if defined(CRS)

#define IS_RCC_CRS_SYNC_SOURCE(__SOURCE__) (((__SOURCE__) == RCC_CRS_SYNC_SOURCE_GPIO) || \
                                            ((__SOURCE__) == RCC_CRS_SYNC_SOURCE_LSE)  || \
                                            ((__SOURCE__) == RCC_CRS_SYNC_SOURCE_USB))

#define IS_RCC_CRS_SYNC_DIV(__DIV__)       (((__DIV__) == RCC_CRS_SYNC_DIV1)  || ((__DIV__) == RCC_CRS_SYNC_DIV2)  || \
                                            ((__DIV__) == RCC_CRS_SYNC_DIV4)  || ((__DIV__) == RCC_CRS_SYNC_DIV8)  || \
                                            ((__DIV__) == RCC_CRS_SYNC_DIV16) || ((__DIV__) == RCC_CRS_SYNC_DIV32) || \
                                            ((__DIV__) == RCC_CRS_SYNC_DIV64) || ((__DIV__) == RCC_CRS_SYNC_DIV128))

#define IS_RCC_CRS_SYNC_POLARITY(__POLARITY__) (((__POLARITY__) == RCC_CRS_SYNC_POLARITY_RISING) || \
                                                ((__POLARITY__) == RCC_CRS_SYNC_POLARITY_FALLING))

#define IS_RCC_CRS_RELOADVALUE(__VALUE__)  (((__VALUE__) <= 0xFFFFU))

#define IS_RCC_CRS_ERRORLIMIT(__VALUE__)   (((__VALUE__) <= 0xFFU))

#if defined(STM32L412xx) || defined(STM32L422xx)
#define IS_RCC_CRS_HSI48CALIBRATION(__VALUE__) (((__VALUE__) <= 0x7FU))
#else
#define IS_RCC_CRS_HSI48CALIBRATION(__VALUE__) (((__VALUE__) <= 0x3FU))
#endif                                 

#define IS_RCC_CRS_FREQERRORDIR(__DIR__)   (((__DIR__) == RCC_CRS_FREQERRORDIR_UP) || \
                                            ((__DIR__) == RCC_CRS_FREQERRORDIR_DOWN))

#endif          

   
      
    

   
      
    

   
      
    

#ifdef __cplusplus
}
#endif

#endif                             

