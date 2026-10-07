/**
  ******************************************************************************
  * @file    stm32l4xx_ll_bus.h
  * @author  MCD Application Team
  * @brief   Header file of BUS LL module.

  @verbatim
                      ##### RCC Limitations #####
  ==============================================================================
    [..]
      A delay between an RCC peripheral clock enable and the effective peripheral
      enabling should be taken into account in order to manage the peripheral read/write
      from/to registers.
      (+) This delay depends on the peripheral mapping.
        (++) AHB & APB peripherals, 1 dummy read is necessary

    [..]
      Workarounds:
      (#) For AHB & APB peripherals, a dummy read to the peripheral register has been
          inserted in each LL_{BUS}_GRP{x}_EnableClock() function.

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

                                                                                
#ifndef STM32L4xx_LL_BUS_H
#define STM32L4xx_LL_BUS_H

#ifdef __cplusplus
extern "C" {
#endif

                                                                                
#include "stm32l4xx.h"

                                   
      
    

#if defined(RCC)

                        
      
    

                                                                                
                                                                                

                                                                                

                                                                                

                                                                                
                                                                                
                                                              
      
    

                                                          
      
    
#define LL_AHB1_GRP1_PERIPH_ALL            0xFFFFFFFFU
#define LL_AHB1_GRP1_PERIPH_DMA1           RCC_AHB1ENR_DMA1EN
#define LL_AHB1_GRP1_PERIPH_DMA2           RCC_AHB1ENR_DMA2EN
#if defined(DMAMUX1)
#define LL_AHB1_GRP1_PERIPH_DMAMUX1        RCC_AHB1ENR_DMAMUX1EN
#endif              
#define LL_AHB1_GRP1_PERIPH_FLASH          RCC_AHB1ENR_FLASHEN
#define LL_AHB1_GRP1_PERIPH_CRC            RCC_AHB1ENR_CRCEN
#define LL_AHB1_GRP1_PERIPH_TSC            RCC_AHB1ENR_TSCEN
#if defined(DMA2D)
#define LL_AHB1_GRP1_PERIPH_DMA2D          RCC_AHB1ENR_DMA2DEN
#endif            
#if defined(GFXMMU)
#define LL_AHB1_GRP1_PERIPH_GFXMMU         RCC_AHB1ENR_GFXMMUEN
#endif             
#define LL_AHB1_GRP1_PERIPH_SRAM1          RCC_AHB1SMENR_SRAM1SMEN
   
      
    

                                                          
      
    
#define LL_AHB2_GRP1_PERIPH_ALL            0xFFFFFFFFU
#define LL_AHB2_GRP1_PERIPH_GPIOA          RCC_AHB2ENR_GPIOAEN
#define LL_AHB2_GRP1_PERIPH_GPIOB          RCC_AHB2ENR_GPIOBEN
#define LL_AHB2_GRP1_PERIPH_GPIOC          RCC_AHB2ENR_GPIOCEN
#if defined(GPIOD)
#define LL_AHB2_GRP1_PERIPH_GPIOD          RCC_AHB2ENR_GPIODEN
#endif          
#if defined(GPIOE)
#define LL_AHB2_GRP1_PERIPH_GPIOE          RCC_AHB2ENR_GPIOEEN
#endif          
#if defined(GPIOF)
#define LL_AHB2_GRP1_PERIPH_GPIOF          RCC_AHB2ENR_GPIOFEN
#endif            
#if defined(GPIOG)
#define LL_AHB2_GRP1_PERIPH_GPIOG          RCC_AHB2ENR_GPIOGEN
#endif            
#define LL_AHB2_GRP1_PERIPH_GPIOH          RCC_AHB2ENR_GPIOHEN
#if defined(GPIOI)
#define LL_AHB2_GRP1_PERIPH_GPIOI          RCC_AHB2ENR_GPIOIEN
#endif            
#if defined(USB_OTG_FS)
#define LL_AHB2_GRP1_PERIPH_OTGFS          RCC_AHB2ENR_OTGFSEN
#endif                 
#define LL_AHB2_GRP1_PERIPH_ADC            RCC_AHB2ENR_ADCEN
#if defined(DCMI)
#define LL_AHB2_GRP1_PERIPH_DCMI           RCC_AHB2ENR_DCMIEN
#endif           
#if defined(AES)
#define LL_AHB2_GRP1_PERIPH_AES            RCC_AHB2ENR_AESEN
#endif          
#if defined(HASH)
#define LL_AHB2_GRP1_PERIPH_HASH           RCC_AHB2ENR_HASHEN
#endif           
#define LL_AHB2_GRP1_PERIPH_RNG            RCC_AHB2ENR_RNGEN
#if defined(OCTOSPIM)
#define LL_AHB2_GRP1_PERIPH_OSPIM          RCC_AHB2ENR_OSPIMEN
#endif               
#if defined(PKA)
#define LL_AHB2_GRP1_PERIPH_PKA            RCC_AHB2ENR_PKAEN
#endif          
#if defined(SDMMC1) && defined(RCC_AHB2ENR_SDMMC1EN)
#define LL_AHB2_GRP1_PERIPH_SDMMC1         RCC_AHB2ENR_SDMMC1EN
#endif                                     
#define LL_AHB2_GRP1_PERIPH_SRAM2          RCC_AHB2SMENR_SRAM2SMEN
#if defined(SRAM3_BASE)
#define LL_AHB2_GRP1_PERIPH_SRAM3          RCC_AHB2SMENR_SRAM3SMEN
#endif                 
   
      
    

                                                          
      
    
#define LL_AHB3_GRP1_PERIPH_ALL            0xFFFFFFFFU
#if defined(FMC_Bank1_R)
#define LL_AHB3_GRP1_PERIPH_FMC            RCC_AHB3ENR_FMCEN
#endif                  
#if defined(QUADSPI)
#define LL_AHB3_GRP1_PERIPH_QSPI           RCC_AHB3ENR_QSPIEN
#endif              
#if defined(OCTOSPI1)
#define LL_AHB3_GRP1_PERIPH_OSPI1          RCC_AHB3ENR_OSPI1EN
#endif               
#if defined(OCTOSPI2)
#define LL_AHB3_GRP1_PERIPH_OSPI2          RCC_AHB3ENR_OSPI2EN
#endif               
   
      
    

                                                          
      
    
#define LL_APB1_GRP1_PERIPH_ALL            0xFFFFFFFFU
#define LL_APB1_GRP1_PERIPH_TIM2           RCC_APB1ENR1_TIM2EN
#if defined(TIM3)
#define LL_APB1_GRP1_PERIPH_TIM3           RCC_APB1ENR1_TIM3EN
#endif           
#if defined(TIM4)
#define LL_APB1_GRP1_PERIPH_TIM4           RCC_APB1ENR1_TIM4EN
#endif           
#if defined(TIM5)
#define LL_APB1_GRP1_PERIPH_TIM5           RCC_APB1ENR1_TIM5EN
#endif           
#define LL_APB1_GRP1_PERIPH_TIM6           RCC_APB1ENR1_TIM6EN
#define LL_APB1_GRP1_PERIPH_TIM7           RCC_APB1ENR1_TIM7EN
#if defined(LCD)
#define LL_APB1_GRP1_PERIPH_LCD            RCC_APB1ENR1_LCDEN
#endif          
#if defined(RCC_APB1ENR1_RTCAPBEN)
#define LL_APB1_GRP1_PERIPH_RTCAPB         RCC_APB1ENR1_RTCAPBEN
#endif                            
#define LL_APB1_GRP1_PERIPH_WWDG           RCC_APB1ENR1_WWDGEN
#if defined(SPI2)
#define LL_APB1_GRP1_PERIPH_SPI2           RCC_APB1ENR1_SPI2EN
#endif           
#define LL_APB1_GRP1_PERIPH_SPI3           RCC_APB1ENR1_SPI3EN
#define LL_APB1_GRP1_PERIPH_USART2         RCC_APB1ENR1_USART2EN
#if defined(USART3)
#define LL_APB1_GRP1_PERIPH_USART3         RCC_APB1ENR1_USART3EN
#endif             
#if defined(UART4)
#define LL_APB1_GRP1_PERIPH_UART4          RCC_APB1ENR1_UART4EN
#endif            
#if defined(UART5)
#define LL_APB1_GRP1_PERIPH_UART5          RCC_APB1ENR1_UART5EN
#endif            
#define LL_APB1_GRP1_PERIPH_I2C1           RCC_APB1ENR1_I2C1EN
#if defined(I2C2)
#define LL_APB1_GRP1_PERIPH_I2C2           RCC_APB1ENR1_I2C2EN
#endif           
#define LL_APB1_GRP1_PERIPH_I2C3           RCC_APB1ENR1_I2C3EN
#if defined(CRS)
#define LL_APB1_GRP1_PERIPH_CRS            RCC_APB1ENR1_CRSEN
#endif          
#define LL_APB1_GRP1_PERIPH_CAN1           RCC_APB1ENR1_CAN1EN
#if defined(CAN2)
#define LL_APB1_GRP1_PERIPH_CAN2           RCC_APB1ENR1_CAN2EN
#endif           
#if defined(USB)
#define LL_APB1_GRP1_PERIPH_USB            RCC_APB1ENR1_USBFSEN
#endif          
#define LL_APB1_GRP1_PERIPH_PWR            RCC_APB1ENR1_PWREN
#define LL_APB1_GRP1_PERIPH_DAC1           RCC_APB1ENR1_DAC1EN
#define LL_APB1_GRP1_PERIPH_OPAMP          RCC_APB1ENR1_OPAMPEN
#define LL_APB1_GRP1_PERIPH_LPTIM1         RCC_APB1ENR1_LPTIM1EN
   
      
    


                                                          
      
    
#define LL_APB1_GRP2_PERIPH_ALL            0xFFFFFFFFU
#define LL_APB1_GRP2_PERIPH_LPUART1        RCC_APB1ENR2_LPUART1EN
#if defined(I2C4)
#define LL_APB1_GRP2_PERIPH_I2C4           RCC_APB1ENR2_I2C4EN
#endif           
#if defined(SWPMI1)
#define LL_APB1_GRP2_PERIPH_SWPMI1         RCC_APB1ENR2_SWPMI1EN
#endif             
#define LL_APB1_GRP2_PERIPH_LPTIM2         RCC_APB1ENR2_LPTIM2EN
   
      
    

                                                          
      
    
#define LL_APB2_GRP1_PERIPH_ALL            0xFFFFFFFFU
#define LL_APB2_GRP1_PERIPH_SYSCFG         RCC_APB2ENR_SYSCFGEN
#define LL_APB2_GRP1_PERIPH_FW             RCC_APB2ENR_FWEN
#if defined(SDMMC1) && defined(RCC_APB2ENR_SDMMC1EN)
#define LL_APB2_GRP1_PERIPH_SDMMC1         RCC_APB2ENR_SDMMC1EN
#endif                                     
#define LL_APB2_GRP1_PERIPH_TIM1           RCC_APB2ENR_TIM1EN
#define LL_APB2_GRP1_PERIPH_SPI1           RCC_APB2ENR_SPI1EN
#if defined(TIM8)
#define LL_APB2_GRP1_PERIPH_TIM8           RCC_APB2ENR_TIM8EN
#endif           
#define LL_APB2_GRP1_PERIPH_USART1         RCC_APB2ENR_USART1EN
#define LL_APB2_GRP1_PERIPH_TIM15          RCC_APB2ENR_TIM15EN
#define LL_APB2_GRP1_PERIPH_TIM16          RCC_APB2ENR_TIM16EN
#if defined(TIM17)
#define LL_APB2_GRP1_PERIPH_TIM17          RCC_APB2ENR_TIM17EN
#endif            
#define LL_APB2_GRP1_PERIPH_SAI1           RCC_APB2ENR_SAI1EN
#if defined(SAI2)
#define LL_APB2_GRP1_PERIPH_SAI2           RCC_APB2ENR_SAI2EN
#endif           
#if defined(DFSDM1_Channel0)
#define LL_APB2_GRP1_PERIPH_DFSDM1         RCC_APB2ENR_DFSDM1EN
#endif                      
#if defined(LTDC)
#define LL_APB2_GRP1_PERIPH_LTDC           RCC_APB2ENR_LTDCEN
#endif           
#if defined(DSI)
#define LL_APB2_GRP1_PERIPH_DSI            RCC_APB2ENR_DSIEN
#endif          
   
      
    

                                                
       
  
#if defined(DFSDM1_Channel0)
#define LL_APB2_GRP1_PERIPH_DFSDM          LL_APB2_GRP1_PERIPH_DFSDM1
#endif                      
   
        
    

   
      
    

                                                                                
                                                                                
                                                              
      
    

                                 
      
    

   
                                          
                                                                 
                                                                 
                                                                 
                                                                 
                                                                 
                                                                 
                                                                 
                                                               
                                                                                
                                              
                                              
                                                     
                                               
                                             
                                             
                                                   
                                                    
   
                                                 
                
  
__STATIC_INLINE void LL_AHB1_GRP1_EnableClock(uint32_t Periphs)
{
  __IO uint32_t tmpreg;
  SET_BIT(RCC->AHB1ENR, Periphs);
                                                    
  tmpreg = READ_BIT(RCC->AHB1ENR, Periphs);
  (void)tmpreg;
}

   
                                                            
                                                                    
                                                                    
                                                                    
                                                                    
                                                                    
                                                                    
                                                                    
                                                                  
                                                                                
                                              
                                              
                                                     
                                               
                                             
                                             
                                                   
                                                    
   
                                                 
                                      
  
__STATIC_INLINE uint32_t LL_AHB1_GRP1_IsEnabledClock(uint32_t Periphs)
{
  return ((READ_BIT(RCC->AHB1ENR, Periphs) == Periphs) ? 1UL : 0UL);
}

   
                                           
                                                                  
                                                                  
                                                                  
                                                                  
                                                                  
                                                                  
                                                                  
                                                                
                                                                                
                                              
                                              
                                                     
                                               
                                             
                                             
                                                   
                                                    
   
                                                 
                
  
__STATIC_INLINE void LL_AHB1_GRP1_DisableClock(uint32_t Periphs)
{
  CLEAR_BIT(RCC->AHB1ENR, Periphs);
}

   
                                         
                                                                
                                                                
                                                                 
                                                                
                                                                
                                                                
                                                                
                                                              
                                                                                
                                             
                                              
                                              
                                                     
                                               
                                             
                                             
                                                   
                                                    
   
                                                 
                
  
__STATIC_INLINE void LL_AHB1_GRP1_ForceReset(uint32_t Periphs)
{
  SET_BIT(RCC->AHB1RSTR, Periphs);
}

   
                                           
                                                                  
                                                                  
                                                                   
                                                                  
                                                                  
                                                                  
                                                                  
                                                                
                                                                                
                                             
                                              
                                              
                                                     
                                               
                                             
                                             
                                                   
                                                    
   
                                                 
                
  
__STATIC_INLINE void LL_AHB1_GRP1_ReleaseReset(uint32_t Periphs)
{
  CLEAR_BIT(RCC->AHB1RSTR, Periphs);
}

   
                                                                 
                                                                          
                                                                          
                                                                          
                                                                          
                                                                          
                                                                          
                                                                          
                                                                          
                                                                        
                                                                                
                                              
                                              
                                                     
                                               
                                               
                                             
                                             
                                                   
                                                    
   
                                                 
                
  
__STATIC_INLINE void LL_AHB1_GRP1_EnableClockStopSleep(uint32_t Periphs)
{
  __IO uint32_t tmpreg;
  SET_BIT(RCC->AHB1SMENR, Periphs);
                                                    
  tmpreg = READ_BIT(RCC->AHB1SMENR, Periphs);
  (void)tmpreg;
}

   
                                                                  
                                                                           
                                                                           
                                                                           
                                                                           
                                                                           
                                                                           
                                                                           
                                                                           
                                                                         
                                                                                
                                              
                                              
                                                     
                                               
                                               
                                             
                                             
                                                   
                                                    
   
                                                 
                
  
__STATIC_INLINE void LL_AHB1_GRP1_DisableClockStopSleep(uint32_t Periphs)
{
  CLEAR_BIT(RCC->AHB1SMENR, Periphs);
}

   
      
    

                                 
      
    

   
                                          
                                                                 
                                                                 
                                                                 
                                                                 
                                                                 
                                                                 
                                                                 
                                                                 
                                                                 
                                                                 
                                                                 
                                                                 
                                                                 
                                                                 
                                                                 
                                                                 
                                                               
                                                                                
                                               
                                               
                                               
                                                   
                                                   
                                                   
                                                   
                                               
                                                   
                                                   
                                             
                                                  
                                                 
                                                  
                                             
                                                   
                                                    
   
                                                 
                
  
__STATIC_INLINE void LL_AHB2_GRP1_EnableClock(uint32_t Periphs)
{
  __IO uint32_t tmpreg;
  SET_BIT(RCC->AHB2ENR, Periphs);
                                                    
  tmpreg = READ_BIT(RCC->AHB2ENR, Periphs);
  (void)tmpreg;
}

   
                                                            
                                                                    
                                                                    
                                                                    
                                                                    
                                                                    
                                                                    
                                                                    
                                                                    
                                                                    
                                                                    
                                                                    
                                                                    
                                                                    
                                                                    
                                                                    
                                                                    
                                                                  
                                                                                
                                               
                                               
                                               
                                                   
                                                   
                                                   
                                                   
                                               
                                                   
                                                   
                                             
                                                  
                                                 
                                                  
                                             
                                                   
                                                    
   
                                                 
                                      
  
__STATIC_INLINE uint32_t LL_AHB2_GRP1_IsEnabledClock(uint32_t Periphs)
{
  return ((READ_BIT(RCC->AHB2ENR, Periphs) == Periphs) ? 1UL : 0UL);
}

   
                                           
                                                                  
                                                                  
                                                                  
                                                                  
                                                                  
                                                                  
                                                                  
                                                                  
                                                                  
                                                                  
                                                                  
                                                                  
                                                                  
                                                                  
                                                                  
                                                                  
                                                                
                                                                                
                                               
                                               
                                               
                                                   
                                                   
                                                   
                                                   
                                               
                                                   
                                                   
                                             
                                                  
                                                 
                                                  
                                             
                                                   
                                                    
   
                                                 
                
  
__STATIC_INLINE void LL_AHB2_GRP1_DisableClock(uint32_t Periphs)
{
  CLEAR_BIT(RCC->AHB2ENR, Periphs);
}

   
                                         
                                                                
                                                                
                                                                
                                                                
                                                                
                                                                
                                                                
                                                                
                                                                
                                                                
                                                                
                                                                
                                                                
                                                                
                                                                
                                                                
                                                              
                                                                                
                                             
                                               
                                               
                                               
                                                   
                                                   
                                                   
                                                   
                                               
                                                   
                                                   
                                             
                                                  
                                                 
                                                  
                                             
                                                   
                                                    
   
                                                 
                
  
__STATIC_INLINE void LL_AHB2_GRP1_ForceReset(uint32_t Periphs)
{
  SET_BIT(RCC->AHB2RSTR, Periphs);
}

   
                                           
                                                                  
                                                                  
                                                                  
                                                                  
                                                                  
                                                                  
                                                                  
                                                                  
                                                                  
                                                                  
                                                                  
                                                                  
                                                                  
                                                                  
                                                                  
                                                                  
                                                                
                                                                                
                                             
                                               
                                               
                                               
                                                   
                                                   
                                                   
                                                   
                                               
                                                   
                                                   
                                             
                                                  
                                                 
                                                  
                                             
                                                   
                                                    
   
                                                 
                
  
__STATIC_INLINE void LL_AHB2_GRP1_ReleaseReset(uint32_t Periphs)
{
  CLEAR_BIT(RCC->AHB2RSTR, Periphs);
}

   
                                                                 
                                                                          
                                                                          
                                                                          
                                                                          
                                                                          
                                                                          
                                                                          
                                                                          
                                                                          
                                                                          
                                                                          
                                                                          
                                                                          
                                                                          
                                                                          
                                                                          
                                                                          
                                                                          
                                                                        
                                                                                
                                               
                                               
                                               
                                                   
                                                   
                                                   
                                                   
                                               
                                                   
                                               
                                                   
                                                   
                                             
                                                  
                                                 
                                                  
                                             
                                                   
                                                    
   
                                                 
                
  
__STATIC_INLINE void LL_AHB2_GRP1_EnableClockStopSleep(uint32_t Periphs)
{
  __IO uint32_t tmpreg;
  SET_BIT(RCC->AHB2SMENR, Periphs);
                                                    
  tmpreg = READ_BIT(RCC->AHB2SMENR, Periphs);
  (void)tmpreg;
}

   
                                                                  
                                                                           
                                                                           
                                                                           
                                                                           
                                                                           
                                                                           
                                                                           
                                                                           
                                                                           
                                                                           
                                                                           
                                                                           
                                                                           
                                                                           
                                                                           
                                                                           
                                                                           
                                                                           
                                                                         
                                                                                
                                               
                                               
                                               
                                                   
                                                   
                                                   
                                                   
                                               
                                                   
                                               
                                                   
                                                   
                                             
                                                  
                                                 
                                                  
                                             
                                                   
                                                    
   
                                                 
                
  
__STATIC_INLINE void LL_AHB2_GRP1_DisableClockStopSleep(uint32_t Periphs)
{
  CLEAR_BIT(RCC->AHB2SMENR, Periphs);
}

   
      
    

                                 
      
    

   
                                          
                                                                 
                                                                 
                                                                 
                                                               
                                                                                
                                                 
                                                  
                                                   
                                                   
   
                                                 
                
  
__STATIC_INLINE void LL_AHB3_GRP1_EnableClock(uint32_t Periphs)
{
  __IO uint32_t tmpreg;
  SET_BIT(RCC->AHB3ENR, Periphs);
                                                    
  tmpreg = READ_BIT(RCC->AHB3ENR, Periphs);
  (void)tmpreg;
}

   
                                                            
                                                                    
                                                                    
                                                                    
                                                                  
                                                                                
                                                 
                                                  
                                                   
                                                   
   
                                                 
                                      
  
__STATIC_INLINE uint32_t LL_AHB3_GRP1_IsEnabledClock(uint32_t Periphs)
{
  return ((READ_BIT(RCC->AHB3ENR, Periphs) == Periphs) ? 1UL : 0UL);
}

   
                                           
                                                                  
                                                                  
                                                                  
                                                                
                                                                                
                                                 
                                                  
                                                   
                                                   
   
                                                 
                
  
__STATIC_INLINE void LL_AHB3_GRP1_DisableClock(uint32_t Periphs)
{
  CLEAR_BIT(RCC->AHB3ENR, Periphs);
}

   
                                         
                                                                
                                                                
                                                                
                                                              
                                                                                
                                             
                                                 
                                                  
                                                   
                                                   
   
                                                 
                
  
__STATIC_INLINE void LL_AHB3_GRP1_ForceReset(uint32_t Periphs)
{
  SET_BIT(RCC->AHB3RSTR, Periphs);
}

   
                                           
                                                                  
                                                                  
                                                                  
                                                                
                                                                                
                                             
                                                 
                                                  
                                                   
                                                   
   
                                                 
                
  
__STATIC_INLINE void LL_AHB3_GRP1_ReleaseReset(uint32_t Periphs)
{
  CLEAR_BIT(RCC->AHB3RSTR, Periphs);
}

   
                                                                 
                                                                          
                                                                          
                                                                          
                                                                        
                                                                                
                                                 
                                                  
                                                   
                                                   
   
                                                 
                
  
__STATIC_INLINE void LL_AHB3_GRP1_EnableClockStopSleep(uint32_t Periphs)
{
  __IO uint32_t tmpreg;
  SET_BIT(RCC->AHB3SMENR, Periphs);
                                                    
  tmpreg = READ_BIT(RCC->AHB3SMENR, Periphs);
  (void)tmpreg;
}

   
                                                                  
                                                                           
                                                                           
                                                                           
                                                                           
                                                                                
                                                 
                                                  
                                                   
                                                   
   
                                                 
                
  
__STATIC_INLINE void LL_AHB3_GRP1_DisableClockStopSleep(uint32_t Periphs)
{
  CLEAR_BIT(RCC->AHB3SMENR, Periphs);
}

   
      
    

                                 
      
    

   
                                          
                                                                 
                                                                 
                                                                 
                                                                 
                                                                 
                                                                 
                                                                 
                                                                 
                                                                 
                                                                 
                                                                 
                                                                 
                                                                 
                                                                 
                                                                 
                                                                 
                                                                 
                                                                 
                                                                 
                                                                 
                                                                 
                                                                 
                                                                 
                                                                 
                                                                 
                                                               
                                                                                
                                              
                                                  
                                                  
                                                  
                                              
                                              
                                                 
                                                    
                                              
                                                  
                                              
                                                
                                                    
                                                   
                                                   
                                              
                                                  
                                              
                                                 
                                              
                                                  
                                                 
                                             
                                              
                                               
                                                
   
                                                 
                
  
__STATIC_INLINE void LL_APB1_GRP1_EnableClock(uint32_t Periphs)
{
  __IO uint32_t tmpreg;
  SET_BIT(RCC->APB1ENR1, Periphs);
                                                    
  tmpreg = READ_BIT(RCC->APB1ENR1, Periphs);
  (void)tmpreg;
}

   
                                          
                                                                 
                                                                 
                                                                 
                                                               
                                                                                
                                                 
                                                  
                                                    
                                                
   
                                                 
                
  
__STATIC_INLINE void LL_APB1_GRP2_EnableClock(uint32_t Periphs)
{
  __IO uint32_t tmpreg;
  SET_BIT(RCC->APB1ENR2, Periphs);
                                                    
  tmpreg = READ_BIT(RCC->APB1ENR2, Periphs);
  (void)tmpreg;
}

   
                                                            
                                                                    
                                                                    
                                                                    
                                                                    
                                                                    
                                                                    
                                                                    
                                                                    
                                                                    
                                                                    
                                                                    
                                                                    
                                                                    
                                                                    
                                                                    
                                                                    
                                                                    
                                                                    
                                                                    
                                                                    
                                                                    
                                                                    
                                                                    
                                                                    
                                                                    
                                                                  
                                                                                
                                              
                                                  
                                                  
                                                  
                                              
                                              
                                                 
                                                    
                                              
                                                  
                                              
                                                
                                                    
                                                   
                                                   
                                              
                                                  
                                              
                                                 
                                              
                                                  
                                                 
                                             
                                              
                                               
                                                
   
                                                 
                                      
  
__STATIC_INLINE uint32_t LL_APB1_GRP1_IsEnabledClock(uint32_t Periphs)
{
  return ((READ_BIT(RCC->APB1ENR1, Periphs) == Periphs) ? 1UL : 0UL);
}

   
                                                            
                                                                    
                                                                    
                                                                    
                                                                  
                                                                                
                                                 
                                                  
                                                    
                                                
   
                                                 
                                      
  
__STATIC_INLINE uint32_t LL_APB1_GRP2_IsEnabledClock(uint32_t Periphs)
{
  return ((READ_BIT(RCC->APB1ENR2, Periphs) == Periphs) ? 1UL : 0UL);
}

   
                                           
                                                                  
                                                                  
                                                                  
                                                                  
                                                                  
                                                                  
                                                                  
                                                                  
                                                                  
                                                                  
                                                                  
                                                                  
                                                                  
                                                                  
                                                                  
                                                                  
                                                                  
                                                                  
                                                                  
                                                                  
                                                                  
                                                                  
                                                                  
                                                                  
                                                                  
                                                                
                                                                                
                                              
                                                  
                                                  
                                                  
                                              
                                              
                                                 
                                                    
                                              
                                                  
                                              
                                                
                                                    
                                                   
                                                   
                                              
                                                  
                                              
                                                 
                                              
                                                  
                                                 
                                             
                                              
                                               
                                                
   
                                                 
                
  
__STATIC_INLINE void LL_APB1_GRP1_DisableClock(uint32_t Periphs)
{
  CLEAR_BIT(RCC->APB1ENR1, Periphs);
}

   
                                           
                                                                  
                                                                  
                                                                  
                                                                
                                                                                
                                                 
                                                  
                                                    
                                                
   
                                                 
                
  
__STATIC_INLINE void LL_APB1_GRP2_DisableClock(uint32_t Periphs)
{
  CLEAR_BIT(RCC->APB1ENR2, Periphs);
}

   
                                         
                                                                
                                                                
                                                                
                                                                
                                                                
                                                                
                                                                
                                                                
                                                                
                                                                
                                                                
                                                                
                                                                
                                                                
                                                                
                                                                
                                                                
                                                                
                                                                
                                                                
                                                                
                                                                
                                                                
                                                              
                                                                                
                                             
                                              
                                                  
                                                  
                                                  
                                              
                                              
                                                 
                                                  
                                              
                                                
                                                    
                                                   
                                                   
                                              
                                                  
                                              
                                                 
                                              
                                                  
                                                 
                                             
                                              
                                               
                                                
   
                                                 
                
  
__STATIC_INLINE void LL_APB1_GRP1_ForceReset(uint32_t Periphs)
{
  SET_BIT(RCC->APB1RSTR1, Periphs);
}

   
                                         
                                                                
                                                                
                                                                
                                                              
                                                                                
                                             
                                                 
                                                  
                                                    
                                                
   
                                                 
                
  
__STATIC_INLINE void LL_APB1_GRP2_ForceReset(uint32_t Periphs)
{
  SET_BIT(RCC->APB1RSTR2, Periphs);
}

   
                                           
                                                                  
                                                                  
                                                                  
                                                                  
                                                                  
                                                                  
                                                                  
                                                                  
                                                                  
                                                                  
                                                                  
                                                                  
                                                                  
                                                                  
                                                                  
                                                                  
                                                                  
                                                                  
                                                                  
                                                                  
                                                                  
                                                                  
                                                                  
                                                                
                                                                                
                                             
                                              
                                                  
                                                  
                                                  
                                              
                                              
                                                 
                                                  
                                              
                                                
                                                    
                                                   
                                                   
                                              
                                                  
                                              
                                                 
                                              
                                                  
                                                 
                                             
                                              
                                               
                                                
   
                                                 
                
  
__STATIC_INLINE void LL_APB1_GRP1_ReleaseReset(uint32_t Periphs)
{
  CLEAR_BIT(RCC->APB1RSTR1, Periphs);
}

   
                                           
                                                                  
                                                                  
                                                                  
                                                                
                                                                                
                                             
                                                 
                                                  
                                                    
                                                
   
                                                 
                
  
__STATIC_INLINE void LL_APB1_GRP2_ReleaseReset(uint32_t Periphs)
{
  CLEAR_BIT(RCC->APB1RSTR2, Periphs);
}

   
                                                                 
                                                                          
                                                                          
                                                                          
                                                                          
                                                                          
                                                                          
                                                                          
                                                                          
                                                                          
                                                                          
                                                                          
                                                                          
                                                                          
                                                                          
                                                                          
                                                                          
                                                                          
                                                                          
                                                                          
                                                                          
                                                                          
                                                                          
                                                                          
                                                                          
                                                                          
                                                                        
                                                                                
                                              
                                                  
                                                  
                                                  
                                              
                                              
                                                 
                                                    
                                              
                                                  
                                              
                                                
                                                    
                                                   
                                                   
                                              
                                                  
                                              
                                                 
                                              
                                                  
                                                 
                                             
                                              
                                               
                                                
   
                                                 
                
  
__STATIC_INLINE void LL_APB1_GRP1_EnableClockStopSleep(uint32_t Periphs)
{
  __IO uint32_t tmpreg;
  SET_BIT(RCC->APB1SMENR1, Periphs);
                                                    
  tmpreg = READ_BIT(RCC->APB1SMENR1, Periphs);
  (void)tmpreg;
}

   
                                                                 
                                                                          
                                                                          
                                                                          
                                                                        
                                                                                
                                                 
                                                  
                                                    
                                                
   
                                                 
                
  
__STATIC_INLINE void LL_APB1_GRP2_EnableClockStopSleep(uint32_t Periphs)
{
  __IO uint32_t tmpreg;
  SET_BIT(RCC->APB1SMENR2, Periphs);
                                                    
  tmpreg = READ_BIT(RCC->APB1SMENR2, Periphs);
  (void)tmpreg;
}

   
                                                                  
                                                                           
                                                                           
                                                                           
                                                                           
                                                                           
                                                                           
                                                                           
                                                                           
                                                                           
                                                                           
                                                                           
                                                                           
                                                                           
                                                                           
                                                                           
                                                                           
                                                                           
                                                                           
                                                                           
                                                                           
                                                                           
                                                                           
                                                                           
                                                                           
                                                                           
                                                                         
                                                                                
                                              
                                                  
                                                  
                                                  
                                              
                                              
                                                 
                                                    
                                              
                                                  
                                              
                                                
                                                    
                                                   
                                                   
                                              
                                                  
                                              
                                                 
                                              
                                                  
                                                 
                                             
                                              
                                               
                                                
   
                                                 
                
  
__STATIC_INLINE void LL_APB1_GRP1_DisableClockStopSleep(uint32_t Periphs)
{
  CLEAR_BIT(RCC->APB1SMENR1, Periphs);
}

   
                                                                  
                                                                           
                                                                           
                                                                           
                                                                         
                                                                                
                                                 
                                                  
                                                    
                                                
   
                                                 
                
  
__STATIC_INLINE void LL_APB1_GRP2_DisableClockStopSleep(uint32_t Periphs)
{
  CLEAR_BIT(RCC->APB1SMENR2, Periphs);
}

   
      
    

                                 
      
    

   
                                          
                                                                 
                                                                 
                                                                 
                                                                 
                                                                 
                                                                 
                                                                 
                                                                 
                                                                 
                                                                 
                                                                 
                                                                 
                                                                 
                                                                 
                                                               
                                                                                
                                                
                                            
                                                    
                                              
                                              
                                                  
                                                
                                               
                                               
                                                   
                                              
                                                  
                                                    
                                                  
                                                 
   
                                                 
                
  
__STATIC_INLINE void LL_APB2_GRP1_EnableClock(uint32_t Periphs)
{
  __IO uint32_t tmpreg;
  SET_BIT(RCC->APB2ENR, Periphs);
                                                    
  tmpreg = READ_BIT(RCC->APB2ENR, Periphs);
  (void)tmpreg;
}

   
                                                            
                                                                    
                                                                    
                                                                    
                                                                    
                                                                    
                                                                    
                                                                    
                                                                    
                                                                    
                                                                    
                                                                    
                                                                    
                                                                    
                                                                    
                                                                  
                                                                                
                                                
                                            
                                                    
                                              
                                              
                                                  
                                                
                                               
                                               
                                                   
                                              
                                                  
                                                    
                                                  
                                                 
   
                                                 
                                      
  
__STATIC_INLINE uint32_t LL_APB2_GRP1_IsEnabledClock(uint32_t Periphs)
{
  return ((READ_BIT(RCC->APB2ENR, Periphs) == Periphs) ? 1UL : 0UL);
}

   
                                           
                                                                  
                                                                  
                                                                  
                                                                  
                                                                  
                                                                  
                                                                  
                                                                  
                                                                  
                                                                  
                                                                  
                                                                  
                                                                  
                                                                
                                                                                
                                                
                                                    
                                              
                                              
                                                  
                                                
                                               
                                               
                                                   
                                              
                                                  
                                                    
                                                  
                                                 
   
                                                 
                
  
__STATIC_INLINE void LL_APB2_GRP1_DisableClock(uint32_t Periphs)
{
  CLEAR_BIT(RCC->APB2ENR, Periphs);
}

   
                                         
                                                                
                                                                
                                                                
                                                                
                                                                
                                                                
                                                                
                                                                
                                                                
                                                                
                                                                
                                                                
                                                                
                                                              
                                                                                
                                             
                                                
                                                    
                                              
                                              
                                                  
                                                
                                               
                                               
                                                   
                                              
                                                  
                                                    
                                                  
                                                 
   
                                                 
                
  
__STATIC_INLINE void LL_APB2_GRP1_ForceReset(uint32_t Periphs)
{
  SET_BIT(RCC->APB2RSTR, Periphs);
}

   
                                           
                                                                  
                                                                  
                                                                  
                                                                  
                                                                  
                                                                  
                                                                  
                                                                  
                                                                  
                                                                  
                                                                  
                                                                  
                                                                  
                                                                
                                                                                
                                             
                                                
                                                    
                                              
                                              
                                                  
                                                
                                               
                                               
                                                   
                                              
                                                  
                                                    
                                                  
                                                 
   
                                                 
                
  
__STATIC_INLINE void LL_APB2_GRP1_ReleaseReset(uint32_t Periphs)
{
  CLEAR_BIT(RCC->APB2RSTR, Periphs);
}

   
                                                                 
                                                                          
                                                                          
                                                                          
                                                                          
                                                                          
                                                                          
                                                                          
                                                                          
                                                                          
                                                                          
                                                                          
                                                                          
                                                                          
                                                                        
                                                                                
                                                
                                                    
                                              
                                              
                                                  
                                                
                                               
                                               
                                                   
                                              
                                                  
                                                    
                                                  
                                                 
   
                                                 
                
  
__STATIC_INLINE void LL_APB2_GRP1_EnableClockStopSleep(uint32_t Periphs)
{
  __IO uint32_t tmpreg;
  SET_BIT(RCC->APB2SMENR, Periphs);
                                                    
  tmpreg = READ_BIT(RCC->APB2SMENR, Periphs);
  (void)tmpreg;
}

   
                                                                  
                                                                           
                                                                           
                                                                           
                                                                           
                                                                           
                                                                           
                                                                           
                                                                           
                                                                           
                                                                           
                                                                           
                                                                           
                                                                           
                                                                         
                                                                                
                                                
                                                    
                                              
                                              
                                                  
                                                
                                               
                                               
                                                   
                                              
                                                  
                                                    
                                                  
                                                 
   
                                                 
                
  
__STATIC_INLINE void LL_APB2_GRP1_DisableClockStopSleep(uint32_t Periphs)
{
  CLEAR_BIT(RCC->APB2SMENR, Periphs);
}

   
      
    


   
      
    

   
      
    

#endif                   

   
      
    

#ifdef __cplusplus
}
#endif

#endif                         

