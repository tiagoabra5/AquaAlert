/**
  ******************************************************************************
  * @file    stm32l4xx_ll_dmamux.h
  * @author  MCD Application Team
  * @brief   Header file of DMAMUX LL module.
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

                                                                                
#ifndef STM32L4xx_LL_DMAMUX_H
#define STM32L4xx_LL_DMAMUX_H

#ifdef __cplusplus
extern "C" {
#endif

                                                                                
#include "stm32l4xx.h"

                                   
      
    

#if defined (DMAMUX1)

                              
      
    

                                                                                
                                                                                
                                                                                
                                                                  
      
    
                                                 
#define DMAMUX_CCR_SIZE                   0x00000004UL

                                                  
#define DMAMUX_RGCR_SIZE                  0x00000004UL
   
      
    

                                                                                
                                                                                
                                                                                
                                                                    
      
    
                                                         
                                                                              
      
    
#define LL_DMAMUX_CFR_CSOF0               DMAMUX_CFR_CSOF0                                                            
#define LL_DMAMUX_CFR_CSOF1               DMAMUX_CFR_CSOF1                                                            
#define LL_DMAMUX_CFR_CSOF2               DMAMUX_CFR_CSOF2                                                            
#define LL_DMAMUX_CFR_CSOF3               DMAMUX_CFR_CSOF3                                                            
#define LL_DMAMUX_CFR_CSOF4               DMAMUX_CFR_CSOF4                                                            
#define LL_DMAMUX_CFR_CSOF5               DMAMUX_CFR_CSOF5                                                            
#define LL_DMAMUX_CFR_CSOF6               DMAMUX_CFR_CSOF6                                                            
#define LL_DMAMUX_CFR_CSOF7               DMAMUX_CFR_CSOF7                                                            
#define LL_DMAMUX_CFR_CSOF8               DMAMUX_CFR_CSOF8                                                            
#define LL_DMAMUX_CFR_CSOF9               DMAMUX_CFR_CSOF9                                                            
#define LL_DMAMUX_CFR_CSOF10              DMAMUX_CFR_CSOF10                                                           
#define LL_DMAMUX_CFR_CSOF11              DMAMUX_CFR_CSOF11                                                           
#define LL_DMAMUX_CFR_CSOF12              DMAMUX_CFR_CSOF12                                                           
#define LL_DMAMUX_CFR_CSOF13              DMAMUX_CFR_CSOF13                                                           
#define LL_DMAMUX_RGCFR_RGCOF0            DMAMUX_RGCFR_COF0                                                            
#define LL_DMAMUX_RGCFR_RGCOF1            DMAMUX_RGCFR_COF1                                                            
#define LL_DMAMUX_RGCFR_RGCOF2            DMAMUX_RGCFR_COF2                                                            
#define LL_DMAMUX_RGCFR_RGCOF3            DMAMUX_RGCFR_COF3                                                            
   
      
    

                                                     
                                                                             
      
    
#define LL_DMAMUX_CSR_SOF0                DMAMUX_CSR_SOF0                                                            
#define LL_DMAMUX_CSR_SOF1                DMAMUX_CSR_SOF1                                                            
#define LL_DMAMUX_CSR_SOF2                DMAMUX_CSR_SOF2                                                            
#define LL_DMAMUX_CSR_SOF3                DMAMUX_CSR_SOF3                                                            
#define LL_DMAMUX_CSR_SOF4                DMAMUX_CSR_SOF4                                                            
#define LL_DMAMUX_CSR_SOF5                DMAMUX_CSR_SOF5                                                            
#define LL_DMAMUX_CSR_SOF6                DMAMUX_CSR_SOF6                                                            
#define LL_DMAMUX_CSR_SOF7                DMAMUX_CSR_SOF7                                                            
#define LL_DMAMUX_CSR_SOF8                DMAMUX_CSR_SOF8                                                            
#define LL_DMAMUX_CSR_SOF9                DMAMUX_CSR_SOF9                                                            
#define LL_DMAMUX_CSR_SOF10               DMAMUX_CSR_SOF10                                                           
#define LL_DMAMUX_CSR_SOF11               DMAMUX_CSR_SOF11                                                           
#define LL_DMAMUX_CSR_SOF12               DMAMUX_CSR_SOF12                                                           
#define LL_DMAMUX_CSR_SOF13               DMAMUX_CSR_SOF13                                                           
#define LL_DMAMUX_RGSR_RGOF0              DMAMUX_RGSR_OF0                                                             
#define LL_DMAMUX_RGSR_RGOF1              DMAMUX_RGSR_OF1                                                             
#define LL_DMAMUX_RGSR_RGOF2              DMAMUX_RGSR_OF2                                                             
#define LL_DMAMUX_RGSR_RGOF3              DMAMUX_RGSR_OF3                                                             
   
      
    

                                        
                                                                                                
      
    
#define LL_DMAMUX_CCR_SOIE                DMAMUX_CxCR_SOIE                                                         
#define LL_DMAMUX_RGCR_RGOIE              DMAMUX_RGxCR_OIE                                                                       
   
      
    

                                                   
      
    
#define LL_DMAMUX_REQ_MEM2MEM          0U                                                                  

#define LL_DMAMUX_REQ_GENERATOR0       1U                                                                  
#define LL_DMAMUX_REQ_GENERATOR1       2U                                                                  
#define LL_DMAMUX_REQ_GENERATOR2       3U                                                                  
#define LL_DMAMUX_REQ_GENERATOR3       4U                                                                  

#define LL_DMAMUX_REQ_ADC1             5U                                                                  

#if defined (STM32L4P5xx) || defined (STM32L4Q5xx)
#define LL_DMAMUX_REQ_ADC2             6U                                                                  
#define LL_DMAMUX_REQ_ADC2_SHIFT       1U
#else
#define LL_DMAMUX_REQ_ADC2_SHIFT       0U
#endif

#define LL_DMAMUX_REQ_DAC1_CH1        ( 6U + LL_DMAMUX_REQ_ADC2_SHIFT)                                     
#define LL_DMAMUX_REQ_DAC1_CH2        ( 7U + LL_DMAMUX_REQ_ADC2_SHIFT)                                     

#define LL_DMAMUX_REQ_TIM6_UP         ( 8U + LL_DMAMUX_REQ_ADC2_SHIFT)                                     
#define LL_DMAMUX_REQ_TIM7_UP         ( 9U + LL_DMAMUX_REQ_ADC2_SHIFT)                                     

#define LL_DMAMUX_REQ_SPI1_RX         (10U + LL_DMAMUX_REQ_ADC2_SHIFT)                                     
#define LL_DMAMUX_REQ_SPI1_TX         (11U + LL_DMAMUX_REQ_ADC2_SHIFT)                                     
#define LL_DMAMUX_REQ_SPI2_RX         (12U + LL_DMAMUX_REQ_ADC2_SHIFT)                                     
#define LL_DMAMUX_REQ_SPI2_TX         (13U + LL_DMAMUX_REQ_ADC2_SHIFT)                                     
#define LL_DMAMUX_REQ_SPI3_RX         (14U + LL_DMAMUX_REQ_ADC2_SHIFT)                                     
#define LL_DMAMUX_REQ_SPI3_TX         (15U + LL_DMAMUX_REQ_ADC2_SHIFT)                                     

#define LL_DMAMUX_REQ_I2C1_RX         (16U + LL_DMAMUX_REQ_ADC2_SHIFT)                                     
#define LL_DMAMUX_REQ_I2C1_TX         (17U + LL_DMAMUX_REQ_ADC2_SHIFT)                                     
#define LL_DMAMUX_REQ_I2C2_RX         (18U + LL_DMAMUX_REQ_ADC2_SHIFT)                                     
#define LL_DMAMUX_REQ_I2C2_TX         (19U + LL_DMAMUX_REQ_ADC2_SHIFT)                                     
#define LL_DMAMUX_REQ_I2C3_RX         (20U + LL_DMAMUX_REQ_ADC2_SHIFT)                                     
#define LL_DMAMUX_REQ_I2C3_TX         (21U + LL_DMAMUX_REQ_ADC2_SHIFT)                                     
#define LL_DMAMUX_REQ_I2C4_RX         (22U + LL_DMAMUX_REQ_ADC2_SHIFT)                                     
#define LL_DMAMUX_REQ_I2C4_TX         (23U + LL_DMAMUX_REQ_ADC2_SHIFT)                                     

#define LL_DMAMUX_REQ_USART1_RX       (24U + LL_DMAMUX_REQ_ADC2_SHIFT)                                     
#define LL_DMAMUX_REQ_USART1_TX       (25U + LL_DMAMUX_REQ_ADC2_SHIFT)                                     
#define LL_DMAMUX_REQ_USART2_RX       (26U + LL_DMAMUX_REQ_ADC2_SHIFT)                                     
#define LL_DMAMUX_REQ_USART2_TX       (27U + LL_DMAMUX_REQ_ADC2_SHIFT)                                     
#define LL_DMAMUX_REQ_USART3_RX       (28U + LL_DMAMUX_REQ_ADC2_SHIFT)                                     
#define LL_DMAMUX_REQ_USART3_TX       (29U + LL_DMAMUX_REQ_ADC2_SHIFT)                                     

#define LL_DMAMUX_REQ_UART4_RX        (30U + LL_DMAMUX_REQ_ADC2_SHIFT)                                     
#define LL_DMAMUX_REQ_UART4_TX        (31U + LL_DMAMUX_REQ_ADC2_SHIFT)                                     
#define LL_DMAMUX_REQ_UART5_RX        (32U + LL_DMAMUX_REQ_ADC2_SHIFT)                                     
#define LL_DMAMUX_REQ_UART5_TX        (33U + LL_DMAMUX_REQ_ADC2_SHIFT)                                     

#define LL_DMAMUX_REQ_LPUART1_RX      (34U + LL_DMAMUX_REQ_ADC2_SHIFT)                                     
#define LL_DMAMUX_REQ_LPUART1_TX      (35U + LL_DMAMUX_REQ_ADC2_SHIFT)                                     

#define LL_DMAMUX_REQ_SAI1_A          (36U + LL_DMAMUX_REQ_ADC2_SHIFT)                                     
#define LL_DMAMUX_REQ_SAI1_B          (37U + LL_DMAMUX_REQ_ADC2_SHIFT)                                     
#define LL_DMAMUX_REQ_SAI2_A          (38U + LL_DMAMUX_REQ_ADC2_SHIFT)                                     
#define LL_DMAMUX_REQ_SAI2_B          (39U + LL_DMAMUX_REQ_ADC2_SHIFT)                                     

#define LL_DMAMUX_REQ_OSPI1           (40U + LL_DMAMUX_REQ_ADC2_SHIFT)                                     
#define LL_DMAMUX_REQ_OSPI2           (41U + LL_DMAMUX_REQ_ADC2_SHIFT)                                     

#define LL_DMAMUX_REQ_TIM1_CH1        (42U + LL_DMAMUX_REQ_ADC2_SHIFT)                                     
#define LL_DMAMUX_REQ_TIM1_CH2        (43U + LL_DMAMUX_REQ_ADC2_SHIFT)                                     
#define LL_DMAMUX_REQ_TIM1_CH3        (44U + LL_DMAMUX_REQ_ADC2_SHIFT)                                     
#define LL_DMAMUX_REQ_TIM1_CH4        (45U + LL_DMAMUX_REQ_ADC2_SHIFT)                                     
#define LL_DMAMUX_REQ_TIM1_UP         (46U + LL_DMAMUX_REQ_ADC2_SHIFT)                                     
#define LL_DMAMUX_REQ_TIM1_TRIG       (47U + LL_DMAMUX_REQ_ADC2_SHIFT)                                     
#define LL_DMAMUX_REQ_TIM1_COM        (48U + LL_DMAMUX_REQ_ADC2_SHIFT)                                     

#define LL_DMAMUX_REQ_TIM8_CH1        (49U + LL_DMAMUX_REQ_ADC2_SHIFT)                                     
#define LL_DMAMUX_REQ_TIM8_CH2        (50U + LL_DMAMUX_REQ_ADC2_SHIFT)                                     
#define LL_DMAMUX_REQ_TIM8_CH3        (51U + LL_DMAMUX_REQ_ADC2_SHIFT)                                     
#define LL_DMAMUX_REQ_TIM8_CH4        (52U + LL_DMAMUX_REQ_ADC2_SHIFT)                                     
#define LL_DMAMUX_REQ_TIM8_UP         (53U + LL_DMAMUX_REQ_ADC2_SHIFT)                                     
#define LL_DMAMUX_REQ_TIM8_TRIG       (54U + LL_DMAMUX_REQ_ADC2_SHIFT)                                     
#define LL_DMAMUX_REQ_TIM8_COM        (55U + LL_DMAMUX_REQ_ADC2_SHIFT)                                     

#define LL_DMAMUX_REQ_TIM2_CH1        (56U + LL_DMAMUX_REQ_ADC2_SHIFT)                                     
#define LL_DMAMUX_REQ_TIM2_CH2        (57U + LL_DMAMUX_REQ_ADC2_SHIFT)                                     
#define LL_DMAMUX_REQ_TIM2_CH3        (58U + LL_DMAMUX_REQ_ADC2_SHIFT)                                     
#define LL_DMAMUX_REQ_TIM2_CH4        (59U + LL_DMAMUX_REQ_ADC2_SHIFT)                                     
#define LL_DMAMUX_REQ_TIM2_UP         (60U + LL_DMAMUX_REQ_ADC2_SHIFT)                                     

#define LL_DMAMUX_REQ_TIM3_CH1        (61U + LL_DMAMUX_REQ_ADC2_SHIFT)                                     
#define LL_DMAMUX_REQ_TIM3_CH2        (62U + LL_DMAMUX_REQ_ADC2_SHIFT)                                     
#define LL_DMAMUX_REQ_TIM3_CH3        (63U + LL_DMAMUX_REQ_ADC2_SHIFT)                                     
#define LL_DMAMUX_REQ_TIM3_CH4        (64U + LL_DMAMUX_REQ_ADC2_SHIFT)                                     
#define LL_DMAMUX_REQ_TIM3_UP         (65U + LL_DMAMUX_REQ_ADC2_SHIFT)                                     
#define LL_DMAMUX_REQ_TIM3_TRIG       (66U + LL_DMAMUX_REQ_ADC2_SHIFT)                                     

#define LL_DMAMUX_REQ_TIM4_CH1        (67U + LL_DMAMUX_REQ_ADC2_SHIFT)                                     
#define LL_DMAMUX_REQ_TIM4_CH2        (68U + LL_DMAMUX_REQ_ADC2_SHIFT)                                     
#define LL_DMAMUX_REQ_TIM4_CH3        (69U + LL_DMAMUX_REQ_ADC2_SHIFT)                                     
#define LL_DMAMUX_REQ_TIM4_CH4        (70U + LL_DMAMUX_REQ_ADC2_SHIFT)                                     
#define LL_DMAMUX_REQ_TIM4_UP         (71U + LL_DMAMUX_REQ_ADC2_SHIFT)                                     

#define LL_DMAMUX_REQ_TIM5_CH1        (72U + LL_DMAMUX_REQ_ADC2_SHIFT)                                     
#define LL_DMAMUX_REQ_TIM5_CH2        (73U + LL_DMAMUX_REQ_ADC2_SHIFT)                                     
#define LL_DMAMUX_REQ_TIM5_CH3        (74U + LL_DMAMUX_REQ_ADC2_SHIFT)                                     
#define LL_DMAMUX_REQ_TIM5_CH4        (75U + LL_DMAMUX_REQ_ADC2_SHIFT)                                     
#define LL_DMAMUX_REQ_TIM5_UP         (76U + LL_DMAMUX_REQ_ADC2_SHIFT)                                     
#define LL_DMAMUX_REQ_TIM5_TRIG       (77U + LL_DMAMUX_REQ_ADC2_SHIFT)                                     

#define LL_DMAMUX_REQ_TIM15_CH1       (78U + LL_DMAMUX_REQ_ADC2_SHIFT)                                     
#define LL_DMAMUX_REQ_TIM15_UP        (79U + LL_DMAMUX_REQ_ADC2_SHIFT)                                     
#define LL_DMAMUX_REQ_TIM15_TRIG      (80U + LL_DMAMUX_REQ_ADC2_SHIFT)                                     
#define LL_DMAMUX_REQ_TIM15_COM       (81U + LL_DMAMUX_REQ_ADC2_SHIFT)                                     

#define LL_DMAMUX_REQ_TIM16_CH1       (82U + LL_DMAMUX_REQ_ADC2_SHIFT)                                     
#define LL_DMAMUX_REQ_TIM16_UP        (83U + LL_DMAMUX_REQ_ADC2_SHIFT)                                     
#define LL_DMAMUX_REQ_TIM17_CH1       (84U + LL_DMAMUX_REQ_ADC2_SHIFT)                                     
#define LL_DMAMUX_REQ_TIM17_UP        (85U + LL_DMAMUX_REQ_ADC2_SHIFT)                                     

#define LL_DMAMUX_REQ_DFSDM1_FLT0     (86U + LL_DMAMUX_REQ_ADC2_SHIFT)                                     
#define LL_DMAMUX_REQ_DFSDM1_FLT1     (87U + LL_DMAMUX_REQ_ADC2_SHIFT)                                     
#define LL_DMAMUX_REQ_DFSDM1_FLT2     (88U + LL_DMAMUX_REQ_ADC2_SHIFT)                                     
#define LL_DMAMUX_REQ_DFSDM1_FLT3     (89U + LL_DMAMUX_REQ_ADC2_SHIFT)                                     

#define LL_DMAMUX_REQ_DCMI            (90U + LL_DMAMUX_REQ_ADC2_SHIFT)                                     
#if defined(PSSI)
#define LL_DMAMUX_REQ_DCMI_PSSI       (90U + LL_DMAMUX_REQ_ADC2_SHIFT)                                     
#endif

#define LL_DMAMUX_REQ_AES_IN          (91U + LL_DMAMUX_REQ_ADC2_SHIFT)                                     
#define LL_DMAMUX_REQ_AES_OUT         (92U + LL_DMAMUX_REQ_ADC2_SHIFT)                                     

#define LL_DMAMUX_REQ_HASH_IN         (93U + LL_DMAMUX_REQ_ADC2_SHIFT)                                     

#define LL_DMAMUX_MAX_REQ             LL_DMAMUX_REQ_HASH_IN

                  
#if defined(PSSI)
#define LL_DMAMUX_REQ_PSSI            LL_DMAMUX_REQ_DCMI_PSSI
#endif
   
      
    

                                                 
      
    
#define LL_DMAMUX_CHANNEL_0               0x00000000U                                                                    
#define LL_DMAMUX_CHANNEL_1               0x00000001U                                                                    
#define LL_DMAMUX_CHANNEL_2               0x00000002U                                                                    
#define LL_DMAMUX_CHANNEL_3               0x00000003U                                                                    
#define LL_DMAMUX_CHANNEL_4               0x00000004U                                                                    
#define LL_DMAMUX_CHANNEL_5               0x00000005U                                                                    
#define LL_DMAMUX_CHANNEL_6               0x00000006U                                                                    
#define LL_DMAMUX_CHANNEL_7               0x00000007U                                                                    
#define LL_DMAMUX_CHANNEL_8               0x00000008U                                                                    
#define LL_DMAMUX_CHANNEL_9               0x00000009U                                                                    
#define LL_DMAMUX_CHANNEL_10              0x0000000AU                                                                    
#define LL_DMAMUX_CHANNEL_11              0x0000000BU                                                                    
#define LL_DMAMUX_CHANNEL_12              0x0000000CU                                                                    
#define LL_DMAMUX_CHANNEL_13              0x0000000DU                                                                    
   
      
    

                                                                  
      
    
#define LL_DMAMUX_SYNC_NO_EVENT            0x00000000U                                                                 
#define LL_DMAMUX_SYNC_POL_RISING          DMAMUX_CxCR_SPOL_0                                                                       
#define LL_DMAMUX_SYNC_POL_FALLING         DMAMUX_CxCR_SPOL_1                                                                        
#define LL_DMAMUX_SYNC_POL_RISING_FALLING  (DMAMUX_CxCR_SPOL_0 | DMAMUX_CxCR_SPOL_1)                                                            
   
      
    

                                                                
      
    
#define LL_DMAMUX_SYNC_EXTI_LINE0         0x00000000U                                                                                                                                    
#define LL_DMAMUX_SYNC_EXTI_LINE1         DMAMUX_CxCR_SYNC_ID_0                                                                                                                          
#define LL_DMAMUX_SYNC_EXTI_LINE2         DMAMUX_CxCR_SYNC_ID_1                                                                                                                          
#define LL_DMAMUX_SYNC_EXTI_LINE3         (DMAMUX_CxCR_SYNC_ID_1 | DMAMUX_CxCR_SYNC_ID_0)                                                                                                
#define LL_DMAMUX_SYNC_EXTI_LINE4         DMAMUX_CxCR_SYNC_ID_2                                                                                                                          
#define LL_DMAMUX_SYNC_EXTI_LINE5         (DMAMUX_CxCR_SYNC_ID_2 | DMAMUX_CxCR_SYNC_ID_0)                                                                                                
#define LL_DMAMUX_SYNC_EXTI_LINE6         (DMAMUX_CxCR_SYNC_ID_2 | DMAMUX_CxCR_SYNC_ID_1)                                                                                                
#define LL_DMAMUX_SYNC_EXTI_LINE7         (DMAMUX_CxCR_SYNC_ID_2 | DMAMUX_CxCR_SYNC_ID_1 | DMAMUX_CxCR_SYNC_ID_0)                                                                        
#define LL_DMAMUX_SYNC_EXTI_LINE8         DMAMUX_CxCR_SYNC_ID_3                                                                                                                          
#define LL_DMAMUX_SYNC_EXTI_LINE9         (DMAMUX_CxCR_SYNC_ID_3 | DMAMUX_CxCR_SYNC_ID_0)                                                                                                
#define LL_DMAMUX_SYNC_EXTI_LINE10        (DMAMUX_CxCR_SYNC_ID_3 | DMAMUX_CxCR_SYNC_ID_1)                                                                                                
#define LL_DMAMUX_SYNC_EXTI_LINE11        (DMAMUX_CxCR_SYNC_ID_3 | DMAMUX_CxCR_SYNC_ID_1 | DMAMUX_CxCR_SYNC_ID_0)                                                                        
#define LL_DMAMUX_SYNC_EXTI_LINE12        (DMAMUX_CxCR_SYNC_ID_3 | DMAMUX_CxCR_SYNC_ID_2)                                                                                                
#define LL_DMAMUX_SYNC_EXTI_LINE13        (DMAMUX_CxCR_SYNC_ID_3 | DMAMUX_CxCR_SYNC_ID_2 | DMAMUX_CxCR_SYNC_ID_0)                                                                        
#define LL_DMAMUX_SYNC_EXTI_LINE14        (DMAMUX_CxCR_SYNC_ID_3 | DMAMUX_CxCR_SYNC_ID_2 | DMAMUX_CxCR_SYNC_ID_1)                                                                        
#define LL_DMAMUX_SYNC_EXTI_LINE15        (DMAMUX_CxCR_SYNC_ID_3 | DMAMUX_CxCR_SYNC_ID_2 | DMAMUX_CxCR_SYNC_ID_1 | DMAMUX_CxCR_SYNC_ID_0)                                                
#define LL_DMAMUX_SYNC_DMAMUX_CH0         DMAMUX_CxCR_SYNC_ID_4                                                                                                                                    
#define LL_DMAMUX_SYNC_DMAMUX_CH1         (DMAMUX_CxCR_SYNC_ID_4 | DMAMUX_CxCR_SYNC_ID_0)                                                                                                          
#define LL_DMAMUX_SYNC_DMAMUX_CH2         (DMAMUX_CxCR_SYNC_ID_4 | DMAMUX_CxCR_SYNC_ID_1)                                                                                                          
#define LL_DMAMUX_SYNC_DMAMUX_CH3         (DMAMUX_CxCR_SYNC_ID_4 | DMAMUX_CxCR_SYNC_ID_1 | DMAMUX_CxCR_SYNC_ID_0)                                                                                  
#define LL_DMAMUX_SYNC_LPTIM1_OUT         (DMAMUX_CxCR_SYNC_ID_4 | DMAMUX_CxCR_SYNC_ID_2)                                                                                                  
#define LL_DMAMUX_SYNC_LPTIM2_OUT         (DMAMUX_CxCR_SYNC_ID_4 | DMAMUX_CxCR_SYNC_ID_2 | DMAMUX_CxCR_SYNC_ID_0)                                                                          
#define LL_DMAMUX_SYNC_DSI_TE             (DMAMUX_CxCR_SYNC_ID_4 | DMAMUX_CxCR_SYNC_ID_2 | DMAMUX_CxCR_SYNC_ID_1)                                                                               
#define LL_DMAMUX_SYNC_DSI_REFRESH_END    (DMAMUX_CxCR_SYNC_ID_4 | DMAMUX_CxCR_SYNC_ID_2 | DMAMUX_CxCR_SYNC_ID_1 | DMAMUX_CxCR_SYNC_ID_0)                                                       
#define LL_DMAMUX_SYNC_DMA2D_TX_END       (DMAMUX_CxCR_SYNC_ID_4 | DMAMUX_CxCR_SYNC_ID_3)                                                                                                          
#define LL_DMAMUX_SYNC_LTDC_LINE_IT       (DMAMUX_CxCR_SYNC_ID_4 | DMAMUX_CxCR_SYNC_ID_3 | DMAMUX_CxCR_SYNC_ID_0)                                                                                  
   
      
    

                                                                      
      
    
#define LL_DMAMUX_REQ_GEN_0               0x00000000U
#define LL_DMAMUX_REQ_GEN_1               0x00000001U
#define LL_DMAMUX_REQ_GEN_2               0x00000002U
#define LL_DMAMUX_REQ_GEN_3               0x00000003U
   
      
    

                                                                                           
      
    
#define LL_DMAMUX_REQ_GEN_NO_EVENT             0x00000000U                                                                             
#define LL_DMAMUX_REQ_GEN_POL_RISING           DMAMUX_RGxCR_GPOL_0                                                                                         
#define LL_DMAMUX_REQ_GEN_POL_FALLING          DMAMUX_RGxCR_GPOL_1                                                                                          
#define LL_DMAMUX_REQ_GEN_POL_RISING_FALLING   (DMAMUX_RGxCR_GPOL_0 | DMAMUX_RGxCR_GPOL_1)                                                                    
   
      
    

                                                                         
      
    
#define LL_DMAMUX_REQ_GEN_EXTI_LINE0      0x00000000U                                                                                                                                        
#define LL_DMAMUX_REQ_GEN_EXTI_LINE1      DMAMUX_RGxCR_SIG_ID_0                                                                                                                              
#define LL_DMAMUX_REQ_GEN_EXTI_LINE2      DMAMUX_RGxCR_SIG_ID_1                                                                                                                              
#define LL_DMAMUX_REQ_GEN_EXTI_LINE3      (DMAMUX_RGxCR_SIG_ID_1 |DMAMUX_RGxCR_SIG_ID_0)                                                                                                     
#define LL_DMAMUX_REQ_GEN_EXTI_LINE4      DMAMUX_RGxCR_SIG_ID_2                                                                                                                              
#define LL_DMAMUX_REQ_GEN_EXTI_LINE5      (DMAMUX_RGxCR_SIG_ID_2 | DMAMUX_RGxCR_SIG_ID_0)                                                                                                    
#define LL_DMAMUX_REQ_GEN_EXTI_LINE6      (DMAMUX_RGxCR_SIG_ID_2 | DMAMUX_RGxCR_SIG_ID_1)                                                                                                    
#define LL_DMAMUX_REQ_GEN_EXTI_LINE7      (DMAMUX_RGxCR_SIG_ID_2 | DMAMUX_RGxCR_SIG_ID_1 | DMAMUX_RGxCR_SIG_ID_0)                                                                            
#define LL_DMAMUX_REQ_GEN_EXTI_LINE8      DMAMUX_RGxCR_SIG_ID_3                                                                                                                              
#define LL_DMAMUX_REQ_GEN_EXTI_LINE9      (DMAMUX_RGxCR_SIG_ID_3 | DMAMUX_RGxCR_SIG_ID_0)                                                                                                    
#define LL_DMAMUX_REQ_GEN_EXTI_LINE10     (DMAMUX_RGxCR_SIG_ID_3 | DMAMUX_RGxCR_SIG_ID_1)                                                                                                    
#define LL_DMAMUX_REQ_GEN_EXTI_LINE11     (DMAMUX_RGxCR_SIG_ID_3 | DMAMUX_RGxCR_SIG_ID_1 | DMAMUX_RGxCR_SIG_ID_0)                                                                            
#define LL_DMAMUX_REQ_GEN_EXTI_LINE12     (DMAMUX_RGxCR_SIG_ID_3 | DMAMUX_RGxCR_SIG_ID_2)                                                                                                    
#define LL_DMAMUX_REQ_GEN_EXTI_LINE13     (DMAMUX_RGxCR_SIG_ID_3 | DMAMUX_RGxCR_SIG_ID_2 | DMAMUX_RGxCR_SIG_ID_0)                                                                            
#define LL_DMAMUX_REQ_GEN_EXTI_LINE14     (DMAMUX_RGxCR_SIG_ID_3 | DMAMUX_RGxCR_SIG_ID_2 | DMAMUX_RGxCR_SIG_ID_1)                                                                            
#define LL_DMAMUX_REQ_GEN_EXTI_LINE15     (DMAMUX_RGxCR_SIG_ID_3 | DMAMUX_RGxCR_SIG_ID_2 | DMAMUX_RGxCR_SIG_ID_1 | DMAMUX_RGxCR_SIG_ID_0)                                                    
#define LL_DMAMUX_REQ_GEN_DMAMUX_CH0      DMAMUX_RGxCR_SIG_ID_4                                                                                                                                        
#define LL_DMAMUX_REQ_GEN_DMAMUX_CH1      (DMAMUX_RGxCR_SIG_ID_4 | DMAMUX_RGxCR_SIG_ID_0)                                                                                                              
#define LL_DMAMUX_REQ_GEN_DMAMUX_CH2      (DMAMUX_RGxCR_SIG_ID_4 | DMAMUX_RGxCR_SIG_ID_1)                                                                                                              
#define LL_DMAMUX_REQ_GEN_DMAMUX_CH3      (DMAMUX_RGxCR_SIG_ID_4 | DMAMUX_RGxCR_SIG_ID_1 | DMAMUX_RGxCR_SIG_ID_0)                                                                                      
#define LL_DMAMUX_REQ_GEN_LPTIM1_OUT      (DMAMUX_RGxCR_SIG_ID_4 | DMAMUX_RGxCR_SIG_ID_2)                                                                                                      
#define LL_DMAMUX_REQ_GEN_LPTIM2_OUT      (DMAMUX_RGxCR_SIG_ID_4 | DMAMUX_RGxCR_SIG_ID_2  | DMAMUX_RGxCR_SIG_ID_0)                                                                             
#define LL_DMAMUX_REQ_GEN_DSI_TE          (DMAMUX_RGxCR_SIG_ID_4 | DMAMUX_RGxCR_SIG_ID_2  | DMAMUX_RGxCR_SIG_ID_1)                                                                                  
#define LL_DMAMUX_REQ_GEN_DSI_REFRESH_END (DMAMUX_RGxCR_SIG_ID_4 | DMAMUX_RGxCR_SIG_ID_2  | DMAMUX_RGxCR_SIG_ID_1 | DMAMUX_RGxCR_SIG_ID_0)                                                          
#define LL_DMAMUX_REQ_GEN_DMA2D_TX_END    (DMAMUX_RGxCR_SIG_ID_4 | DMAMUX_RGxCR_SIG_ID_3)                                                                                                              
#define LL_DMAMUX_REQ_GEN_LTDC_LINE_IT    (DMAMUX_RGxCR_SIG_ID_4 | DMAMUX_RGxCR_SIG_ID_3  | DMAMUX_RGxCR_SIG_ID_0)                                                                                     
   
      
    

   
      
    

                                                                                
                                                              
      
    

                                                                            
      
    
   
                                            
                                        
                                          
                                                         
                
    
#define LL_DMAMUX_WriteReg(__INSTANCE__, __REG__, __VALUE__) WRITE_REG(__INSTANCE__->__REG__, (__VALUE__))

   
                                           
                                        
                                       
                          
    
#define LL_DMAMUX_ReadReg(__INSTANCE__, __REG__) READ_REG(__INSTANCE__->__REG__)
   
      
    

   
      
    

                                                                                
                                                                    
      
    

                                                      
      
    
   
                                                       
                                                                    
                                                                     
                                                             
                                    
                                                                      
                                         
                                         
                                         
                                         
                                         
                                         
                                         
                                         
                                         
                                         
                                          
                                          
                                          
                                          
                                                                      
                                           
                                              
                                              
                                              
                                              
                                        
                                        
                                            
                                            
                                           
                                           
                                           
                                           
                                           
                                           
                                           
                                           
                                           
                                           
                                           
                                           
                                           
                                           
                                           
                                           
                                             
                                             
                                             
                                             
                                             
                                             
                                            
                                            
                                            
                                            
                                              
                                              
                                          
                                          
                                          
                                          
                                         
                                         
                                            
                                            
                                            
                                            
                                           
                                             
                                            
                                            
                                            
                                            
                                            
                                           
                                             
                                            
                                            
                                            
                                            
                                            
                                           
                                            
                                            
                                            
                                            
                                           
                                             
                                            
                                            
                                            
                                            
                                           
                                            
                                            
                                            
                                            
                                           
                                             
                                             
                                            
                                              
                                             
                                             
                                            
                                             
                                            
                                               
                                               
                                               
                                               
                                        
                                             
                                          
                                           
                                           
                
    
__STATIC_INLINE void LL_DMAMUX_SetRequestID(const DMAMUX_Channel_TypeDef *DMAMUXx, uint32_t Channel, uint32_t Request)
{
  (void)(DMAMUXx);
  MODIFY_REG((DMAMUX1_Channel0 + Channel)->CCR, DMAMUX_CxCR_DMAREQ_ID, Request);
}

   
                                                       
                                                                    
                                                                     
                                                             
                                    
                                                                      
                                         
                                         
                                         
                                         
                                         
                                         
                                         
                                         
                                         
                                         
                                          
                                          
                                          
                                          
                                                              
                                           
                                              
                                              
                                              
                                              
                                        
                                        
                                            
                                            
                                           
                                           
                                           
                                           
                                           
                                           
                                           
                                           
                                           
                                           
                                           
                                           
                                           
                                           
                                           
                                           
                                             
                                             
                                             
                                             
                                             
                                             
                                            
                                            
                                            
                                            
                                              
                                              
                                          
                                          
                                          
                                          
                                         
                                         
                                            
                                            
                                            
                                            
                                           
                                             
                                            
                                            
                                            
                                            
                                            
                                           
                                             
                                            
                                            
                                            
                                            
                                            
                                           
                                            
                                            
                                            
                                            
                                           
                                             
                                            
                                            
                                            
                                            
                                           
                                            
                                            
                                            
                                            
                                           
                                             
                                             
                                            
                                              
                                             
                                             
                                            
                                             
                                            
                                               
                                               
                                               
                                               
                                        
                                             
                                          
                                           
                                           
    
__STATIC_INLINE uint32_t LL_DMAMUX_GetRequestID(const DMAMUX_Channel_TypeDef *DMAMUXx, uint32_t Channel)
{
  (void)(DMAMUXx);
  return (uint32_t)(READ_BIT((DMAMUX1_Channel0 + Channel)->CCR, DMAMUX_CxCR_DMAREQ_ID));
}

   
                                                                                                                                                            
                                                                    
                                                                     
                                                                 
                                    
                                                                      
                                         
                                         
                                         
                                         
                                         
                                         
                                         
                                         
                                         
                                         
                                          
                                          
                                          
                                          
                                                                                            
                
    
__STATIC_INLINE void LL_DMAMUX_SetSyncRequestNb(const DMAMUX_Channel_TypeDef *DMAMUXx, uint32_t Channel, uint32_t RequestNb)
{
  (void)(DMAMUXx);
  MODIFY_REG((DMAMUX1_Channel0 + Channel)->CCR, DMAMUX_CxCR_NBREQ, ((RequestNb - 1U) << DMAMUX_CxCR_NBREQ_Pos));
}

   
                                                                                                                                                            
                                                                    
                                                                     
                                                                 
                                    
                                                                      
                                         
                                         
                                         
                                         
                                         
                                         
                                         
                                         
                                         
                                         
                                          
                                          
                                          
                                          
                                                  
    
__STATIC_INLINE uint32_t LL_DMAMUX_GetSyncRequestNb(const DMAMUX_Channel_TypeDef *DMAMUXx, uint32_t Channel)
{
  (void)(DMAMUXx);
  return (uint32_t)(((READ_BIT((DMAMUX1_Channel0 + Channel)->CCR, DMAMUX_CxCR_NBREQ)) >> DMAMUX_CxCR_NBREQ_Pos) + 1U);
}

   
                                                                                    
                                                                    
                                                                     
                                                                
                                    
                                                                      
                                         
                                         
                                         
                                         
                                         
                                         
                                         
                                         
                                         
                                         
                                          
                                          
                                          
                                          
                                                                       
                                             
                                               
                                                
                                                       
                
    
__STATIC_INLINE void LL_DMAMUX_SetSyncPolarity(const DMAMUX_Channel_TypeDef *DMAMUXx, uint32_t Channel, uint32_t Polarity)
{
  (void)(DMAMUXx);
  MODIFY_REG((DMAMUX1_Channel0 + Channel)->CCR, DMAMUX_CxCR_SPOL, Polarity);
}

   
                                                                                    
                                                                    
                                                                     
                                                                
                                    
                                                                      
                                         
                                         
                                         
                                         
                                         
                                         
                                         
                                         
                                         
                                         
                                          
                                          
                                          
                                          
                                                              
                                             
                                               
                                                
                                                       
    
__STATIC_INLINE uint32_t LL_DMAMUX_GetSyncPolarity(const DMAMUX_Channel_TypeDef *DMAMUXx, uint32_t Channel)
{
  (void)(DMAMUXx);
  return (uint32_t)(READ_BIT((DMAMUX1_Channel0 + Channel)->CCR, DMAMUX_CxCR_SPOL));
}

   
                                                            
                                                                    
                                                                     
                                                                      
                                    
                                                                      
                                         
                                         
                                         
                                         
                                         
                                         
                                         
                                         
                                         
                                         
                                          
                                          
                                          
                                          
                
    
__STATIC_INLINE void LL_DMAMUX_EnableEventGeneration(const DMAMUX_Channel_TypeDef *DMAMUXx, uint32_t Channel)
{
  (void)(DMAMUXx);
  SET_BIT((DMAMUX1_Channel0 + Channel)->CCR, DMAMUX_CxCR_EGE);
}

   
                                                             
                                                                    
                                                                     
                                                                       
                                    
                                                                      
                                         
                                         
                                         
                                         
                                         
                                         
                                         
                                         
                                         
                                         
                                          
                                          
                                          
                                          
                
    
__STATIC_INLINE void LL_DMAMUX_DisableEventGeneration(const DMAMUX_Channel_TypeDef *DMAMUXx, uint32_t Channel)
{
  (void)(DMAMUXx);
  CLEAR_BIT((DMAMUX1_Channel0 + Channel)->CCR, DMAMUX_CxCR_EGE);
}

   
                                                                                     
                                                                    
                                                                     
                                                                         
                                    
                                                                      
                                         
                                         
                                         
                                         
                                         
                                         
                                         
                                         
                                         
                                         
                                          
                                          
                                          
                                          
                                  
    
__STATIC_INLINE uint32_t LL_DMAMUX_IsEnabledEventGeneration(const DMAMUX_Channel_TypeDef *DMAMUXx, uint32_t Channel)
{
  (void)(DMAMUXx);
  return ((READ_BIT((DMAMUX1_Channel0 + Channel)->CCR, DMAMUX_CxCR_EGE) == (DMAMUX_CxCR_EGE)) ? 1UL : 0UL);
}

   
                                            
                                                                    
                                                                     
                                                           
                                    
                                                                      
                                         
                                         
                                         
                                         
                                         
                                         
                                         
                                         
                                         
                                         
                                          
                                          
                                          
                                          
                
    
__STATIC_INLINE void LL_DMAMUX_EnableSync(const DMAMUX_Channel_TypeDef *DMAMUXx, uint32_t Channel)
{
  (void)(DMAMUXx);
  SET_BIT((DMAMUX1_Channel0 + Channel)->CCR, DMAMUX_CxCR_SE);
}

   
                                             
                                                                    
                                                                     
                                                            
                                    
                                                                      
                                         
                                         
                                         
                                         
                                         
                                         
                                         
                                         
                                         
                                         
                                          
                                          
                                          
                                          
                
    
__STATIC_INLINE void LL_DMAMUX_DisableSync(const DMAMUX_Channel_TypeDef *DMAMUXx, uint32_t Channel)
{
  (void)(DMAMUXx);
  CLEAR_BIT((DMAMUX1_Channel0 + Channel)->CCR, DMAMUX_CxCR_SE);
}

   
                                                                     
                                                                    
                                                                     
                                                              
                                    
                                                                      
                                         
                                         
                                         
                                         
                                         
                                         
                                         
                                         
                                         
                                         
                                          
                                          
                                          
                                          
                                  
    
__STATIC_INLINE uint32_t LL_DMAMUX_IsEnabledSync(const DMAMUX_Channel_TypeDef *DMAMUXx, uint32_t Channel)
{
  (void)(DMAMUXx);
  return ((READ_BIT((DMAMUX1_Channel0 + Channel)->CCR, DMAMUX_CxCR_SE) == (DMAMUX_CxCR_SE)) ? 1UL : 0UL);
}

   
                                                               
                                                                    
                                                                     
                                                          
                                    
                                                                      
                                         
                                         
                                         
                                         
                                         
                                         
                                         
                                         
                                         
                                         
                                          
                                          
                                          
                                          
                                                                     
                                               
                                               
                                               
                                               
                                               
                                               
                                               
                                               
                                               
                                               
                                                
                                                
                                                
                                                
                                                
                                                
                                               
                                               
                                               
                                               
                                               
                                               
                                           
                                                    
                                                 
                                                 
                
    
__STATIC_INLINE void LL_DMAMUX_SetSyncID(const DMAMUX_Channel_TypeDef *DMAMUXx, uint32_t Channel, uint32_t SyncID)
{
  (void)(DMAMUXx);
  MODIFY_REG((DMAMUX1_Channel0 + Channel)->CCR, DMAMUX_CxCR_SYNC_ID, SyncID);
}

   
                                                               
                                                                    
                                                                     
                                                          
                                    
                                                                      
                                         
                                         
                                         
                                         
                                         
                                         
                                         
                                         
                                         
                                         
                                          
                                          
                                          
                                          
                                                              
                                               
                                               
                                               
                                               
                                               
                                               
                                               
                                               
                                               
                                               
                                                
                                                
                                                
                                                
                                                
                                                
                                               
                                               
                                               
                                               
                                               
                                               
                                           
                                                    
                                                 
                                                 
    
__STATIC_INLINE uint32_t LL_DMAMUX_GetSyncID(const DMAMUX_Channel_TypeDef *DMAMUXx, uint32_t Channel)
{
  (void)(DMAMUXx);
  return (uint32_t)(READ_BIT((DMAMUX1_Channel0 + Channel)->CCR, DMAMUX_CxCR_SYNC_ID));
}

   
                                         
                                                                 
                                    
                                                                                
                                         
                                         
                                         
                                         
                
    
__STATIC_INLINE void LL_DMAMUX_EnableRequestGen(const DMAMUX_Channel_TypeDef *DMAMUXx, uint32_t RequestGenChannel)
{
  (void)(DMAMUXx);
  SET_BIT(((DMAMUX_RequestGen_TypeDef *)((uint32_t)((uint32_t)DMAMUX1_RequestGenerator0 + (DMAMUX_RGCR_SIZE *
                                                    (RequestGenChannel)))))->RGCR, DMAMUX_RGxCR_GE);
}

   
                                          
                                                                  
                                    
                                                                                
                                         
                                         
                                         
                                         
                
    
__STATIC_INLINE void LL_DMAMUX_DisableRequestGen(const DMAMUX_Channel_TypeDef *DMAMUXx, uint32_t RequestGenChannel)
{
  (void)(DMAMUXx);
  CLEAR_BIT(((DMAMUX_RequestGen_TypeDef *)((uint32_t)((uint32_t)DMAMUX1_RequestGenerator0 + (DMAMUX_RGCR_SIZE *
                                                      (RequestGenChannel)))))->RGCR, DMAMUX_RGxCR_GE);
}

   
                                                                  
                                                                    
                                    
                                                                                
                                         
                                         
                                         
                                         
                                  
    
__STATIC_INLINE uint32_t LL_DMAMUX_IsEnabledRequestGen(const DMAMUX_Channel_TypeDef *DMAMUXx, uint32_t RequestGenChannel)
{
  (void)(DMAMUXx);
  return ((READ_BIT(((DMAMUX_RequestGen_TypeDef *)((uint32_t)((uint32_t)DMAMUX1_RequestGenerator0 + (DMAMUX_RGCR_SIZE *
                                                              (RequestGenChannel)))))->RGCR, DMAMUX_RGxCR_GE) == (DMAMUX_RGxCR_GE)) ? 1UL : 0UL);
}

   
                                                                                 
                                                                      
                                    
                                                                                
                                         
                                         
                                         
                                         
                                                                       
                                                
                                                  
                                                   
                                                          
                
    
__STATIC_INLINE void LL_DMAMUX_SetRequestGenPolarity(const DMAMUX_Channel_TypeDef *DMAMUXx, uint32_t RequestGenChannel,
                                                     uint32_t Polarity)
{
  (void)(DMAMUXx);
  MODIFY_REG(((DMAMUX_RequestGen_TypeDef *)((uint32_t)((uint32_t)DMAMUX1_RequestGenerator0 + (DMAMUX_RGCR_SIZE *
                                                       (RequestGenChannel)))))->RGCR, DMAMUX_RGxCR_GPOL, Polarity);
}

   
                                                                                 
                                                                      
                                    
                                                                                
                                         
                                         
                                         
                                         
                                                              
                                                
                                                  
                                                   
                                                          
    
__STATIC_INLINE uint32_t LL_DMAMUX_GetRequestGenPolarity(const DMAMUX_Channel_TypeDef *DMAMUXx, uint32_t RequestGenChannel)
{
  (void)(DMAMUXx);
  return (uint32_t)(READ_BIT(((DMAMUX_RequestGen_TypeDef *)((uint32_t)((uint32_t)DMAMUX1_RequestGenerator0 +
                                                            (DMAMUX_RGCR_SIZE * (RequestGenChannel)))))->RGCR, DMAMUX_RGxCR_GPOL));
}

   
                                                                                          
                                                                      
                                                                
                                    
                                                                                
                                         
                                         
                                         
                                         
                                                                                            
                
    
__STATIC_INLINE void LL_DMAMUX_SetGenRequestNb(const DMAMUX_Channel_TypeDef *DMAMUXx, uint32_t RequestGenChannel,
                                               uint32_t RequestNb)
{
  (void)(DMAMUXx);
  MODIFY_REG(((DMAMUX_RequestGen_TypeDef *)((uint32_t)((uint32_t)DMAMUX1_RequestGenerator0 + (DMAMUX_RGCR_SIZE *
                                                       (RequestGenChannel)))))->RGCR, DMAMUX_RGxCR_GNBREQ, (RequestNb - 1U) << DMAMUX_RGxCR_GNBREQ_Pos);
}

   
                                                                                          
                                                                
                                    
                                                                                
                                         
                                         
                                         
                                         
                                                  
    
__STATIC_INLINE uint32_t LL_DMAMUX_GetGenRequestNb(const DMAMUX_Channel_TypeDef *DMAMUXx, uint32_t RequestGenChannel)
{
  (void)(DMAMUXx);
  return (uint32_t)((READ_BIT(((DMAMUX_RequestGen_TypeDef *)((uint32_t)((uint32_t)DMAMUX1_RequestGenerator0 +
                                                             (DMAMUX_RGCR_SIZE * (RequestGenChannel)))))->RGCR, DMAMUX_RGxCR_GNBREQ) >> DMAMUX_RGxCR_GNBREQ_Pos) + 1U);
}

   
                                                                                                       
                                                                   
                                    
                                                                                
                                         
                                         
                                         
                                         
                                                                              
                                                  
                                                  
                                                  
                                                  
                                                  
                                                  
                                                  
                                                  
                                                  
                                                  
                                                   
                                                   
                                                   
                                                   
                                                   
                                                   
                                                  
                                                  
                                                  
                                                  
                                                  
                                                  
                                              
                                                       
                                                    
                                                    
                
    
__STATIC_INLINE void LL_DMAMUX_SetRequestSignalID(const DMAMUX_Channel_TypeDef *DMAMUXx, uint32_t RequestGenChannel,
                                                  uint32_t RequestSignalID)
{
  (void)(DMAMUXx);
  MODIFY_REG(((DMAMUX_RequestGen_TypeDef *)((uint32_t)((uint32_t)DMAMUX1_RequestGenerator0 + (DMAMUX_RGCR_SIZE *
                                                       (RequestGenChannel)))))->RGCR, DMAMUX_RGxCR_SIG_ID, RequestSignalID);
}

   
                                                                          
                                                                   
                                    
                                                                                
                                         
                                         
                                         
                                         
                                                              
                                                  
                                                  
                                                  
                                                  
                                                  
                                                  
                                                  
                                                  
                                                  
                                                  
                                                   
                                                   
                                                   
                                                   
                                                   
                                                   
                                                  
                                                  
                                                  
                                                  
                                                  
                                                  
                                              
                                                       
                                                    
                                                    
    
__STATIC_INLINE uint32_t LL_DMAMUX_GetRequestSignalID(const DMAMUX_Channel_TypeDef *DMAMUXx, uint32_t RequestGenChannel)
{
  (void)(DMAMUXx);
  return (uint32_t)(READ_BIT(((DMAMUX_RequestGen_TypeDef *)((uint32_t)((uint32_t)DMAMUX1_RequestGenerator0 +
                                                            (DMAMUX_RGCR_SIZE * (RequestGenChannel)))))->RGCR, DMAMUX_RGxCR_SIG_ID));
}

   
      
    

                                                          
      
    

   
                                                             
                                                                 
                                            
                                  
    
__STATIC_INLINE uint32_t LL_DMAMUX_IsActiveFlag_SO0(const DMAMUX_Channel_TypeDef *DMAMUXx)
{
  (void)(DMAMUXx);
  return ((READ_BIT(DMAMUX1_ChannelStatus->CSR, DMAMUX_CSR_SOF0) == (DMAMUX_CSR_SOF0)) ? 1UL : 0UL);
}

   
                                                             
                                                                 
                                            
                                  
    
__STATIC_INLINE uint32_t LL_DMAMUX_IsActiveFlag_SO1(const DMAMUX_Channel_TypeDef *DMAMUXx)
{
  (void)(DMAMUXx);
  return ((READ_BIT(DMAMUX1_ChannelStatus->CSR, DMAMUX_CSR_SOF1) == (DMAMUX_CSR_SOF1)) ? 1UL : 0UL);
}

   
                                                             
                                                                 
                                            
                                  
    
__STATIC_INLINE uint32_t LL_DMAMUX_IsActiveFlag_SO2(const DMAMUX_Channel_TypeDef *DMAMUXx)
{
  (void)(DMAMUXx);
  return ((READ_BIT(DMAMUX1_ChannelStatus->CSR, DMAMUX_CSR_SOF2) == (DMAMUX_CSR_SOF2)) ? 1UL : 0UL);
}

   
                                                             
                                                                 
                                            
                                  
    
__STATIC_INLINE uint32_t LL_DMAMUX_IsActiveFlag_SO3(const DMAMUX_Channel_TypeDef *DMAMUXx)
{
  (void)(DMAMUXx);
  return ((READ_BIT(DMAMUX1_ChannelStatus->CSR, DMAMUX_CSR_SOF3) == (DMAMUX_CSR_SOF3)) ? 1UL : 0UL);
}

   
                                                             
                                                                 
                                            
                                  
    
__STATIC_INLINE uint32_t LL_DMAMUX_IsActiveFlag_SO4(const DMAMUX_Channel_TypeDef *DMAMUXx)
{
  (void)(DMAMUXx);
  return ((READ_BIT(DMAMUX1_ChannelStatus->CSR, DMAMUX_CSR_SOF4) == (DMAMUX_CSR_SOF4)) ? 1UL : 0UL);
}

   
                                                             
                                                                 
                                            
                                  
    
__STATIC_INLINE uint32_t LL_DMAMUX_IsActiveFlag_SO5(const DMAMUX_Channel_TypeDef *DMAMUXx)
{
  (void)(DMAMUXx);
  return ((READ_BIT(DMAMUX1_ChannelStatus->CSR, DMAMUX_CSR_SOF5) == (DMAMUX_CSR_SOF5)) ? 1UL : 0UL);
}

   
                                                             
                                                                 
                                            
                                  
    
__STATIC_INLINE uint32_t LL_DMAMUX_IsActiveFlag_SO6(const DMAMUX_Channel_TypeDef *DMAMUXx)
{
  (void)(DMAMUXx);
  return ((READ_BIT(DMAMUX1_ChannelStatus->CSR, DMAMUX_CSR_SOF6) == (DMAMUX_CSR_SOF6)) ? 1UL : 0UL);
}

   
                                                             
                                                                 
                                            
                                  
    
__STATIC_INLINE uint32_t LL_DMAMUX_IsActiveFlag_SO7(const DMAMUX_Channel_TypeDef *DMAMUXx)
{
  (void)(DMAMUXx);
  return ((READ_BIT(DMAMUX1_ChannelStatus->CSR, DMAMUX_CSR_SOF7) == (DMAMUX_CSR_SOF7)) ? 1UL : 0UL);
}

   
                                                             
                                                                 
                                            
                                  
    
__STATIC_INLINE uint32_t LL_DMAMUX_IsActiveFlag_SO8(const DMAMUX_Channel_TypeDef *DMAMUXx)
{
  (void)(DMAMUXx);
  return ((READ_BIT(DMAMUX1_ChannelStatus->CSR, DMAMUX_CSR_SOF8) == (DMAMUX_CSR_SOF8)) ? 1UL : 0UL);
}

   
                                                             
                                                                 
                                            
                                  
    
__STATIC_INLINE uint32_t LL_DMAMUX_IsActiveFlag_SO9(const DMAMUX_Channel_TypeDef *DMAMUXx)
{
  (void)(DMAMUXx);
  return ((READ_BIT(DMAMUX1_ChannelStatus->CSR, DMAMUX_CSR_SOF9) == (DMAMUX_CSR_SOF9)) ? 1UL : 0UL);
}

   
                                                              
                                                                  
                                            
                                  
    
__STATIC_INLINE uint32_t LL_DMAMUX_IsActiveFlag_SO10(const DMAMUX_Channel_TypeDef *DMAMUXx)
{
  (void)(DMAMUXx);
  return ((READ_BIT(DMAMUX1_ChannelStatus->CSR, DMAMUX_CSR_SOF10) == (DMAMUX_CSR_SOF10)) ? 1UL : 0UL);
}

   
                                                              
                                                                  
                                            
                                  
    
__STATIC_INLINE uint32_t LL_DMAMUX_IsActiveFlag_SO11(const DMAMUX_Channel_TypeDef *DMAMUXx)
{
  (void)(DMAMUXx);
  return ((READ_BIT(DMAMUX1_ChannelStatus->CSR, DMAMUX_CSR_SOF11) == (DMAMUX_CSR_SOF11)) ? 1UL : 0UL);
}

   
                                                              
                                                                  
                                            
                                  
    
__STATIC_INLINE uint32_t LL_DMAMUX_IsActiveFlag_SO12(const DMAMUX_Channel_TypeDef *DMAMUXx)
{
  (void)(DMAMUXx);
  return ((READ_BIT(DMAMUX1_ChannelStatus->CSR, DMAMUX_CSR_SOF12) == (DMAMUX_CSR_SOF12)) ? 1UL : 0UL);
}

   
                                                              
                                                                  
                                            
                                  
    
__STATIC_INLINE uint32_t LL_DMAMUX_IsActiveFlag_SO13(const DMAMUX_Channel_TypeDef *DMAMUXx)
{
  (void)(DMAMUXx);
  return ((READ_BIT(DMAMUX1_ChannelStatus->CSR, DMAMUX_CSR_SOF13) == (DMAMUX_CSR_SOF13)) ? 1UL : 0UL);
}

   
                                                               
                                                                  
                                            
                                  
    
__STATIC_INLINE uint32_t LL_DMAMUX_IsActiveFlag_RGO0(const DMAMUX_Channel_TypeDef *DMAMUXx)
{
  (void)(DMAMUXx);
  return ((READ_BIT(DMAMUX1_RequestGenStatus->RGSR, DMAMUX_RGSR_OF0) == (DMAMUX_RGSR_OF0)) ? 1UL : 0UL);
}

   
                                                               
                                                                  
                                            
                                  
    
__STATIC_INLINE uint32_t LL_DMAMUX_IsActiveFlag_RGO1(const DMAMUX_Channel_TypeDef *DMAMUXx)
{
  (void)(DMAMUXx);
  return ((READ_BIT(DMAMUX1_RequestGenStatus->RGSR, DMAMUX_RGSR_OF1) == (DMAMUX_RGSR_OF1)) ? 1UL : 0UL);
}

   
                                                               
                                                                  
                                            
                                  
    
__STATIC_INLINE uint32_t LL_DMAMUX_IsActiveFlag_RGO2(const DMAMUX_Channel_TypeDef *DMAMUXx)
{
  (void)(DMAMUXx);
  return ((READ_BIT(DMAMUX1_RequestGenStatus->RGSR, DMAMUX_RGSR_OF2) == (DMAMUX_RGSR_OF2)) ? 1UL : 0UL);
}

   
                                                               
                                                                  
                                            
                                  
    
__STATIC_INLINE uint32_t LL_DMAMUX_IsActiveFlag_RGO3(const DMAMUX_Channel_TypeDef *DMAMUXx)
{
  (void)(DMAMUXx);
  return ((READ_BIT(DMAMUX1_RequestGenStatus->RGSR, DMAMUX_RGSR_OF3) == (DMAMUX_RGSR_OF3)) ? 1UL : 0UL);
}

   
                                                               
                                                              
                                            
                
    
__STATIC_INLINE void LL_DMAMUX_ClearFlag_SO0(const DMAMUX_Channel_TypeDef *DMAMUXx)
{
  (void)(DMAMUXx);
  SET_BIT(DMAMUX1_ChannelStatus->CFR, DMAMUX_CFR_CSOF0);
}

   
                                                               
                                                              
                                            
                
    
__STATIC_INLINE void LL_DMAMUX_ClearFlag_SO1(const DMAMUX_Channel_TypeDef *DMAMUXx)
{
  (void)(DMAMUXx);
  SET_BIT(DMAMUX1_ChannelStatus->CFR, DMAMUX_CFR_CSOF1);
}

   
                                                               
                                                              
                                            
                
    
__STATIC_INLINE void LL_DMAMUX_ClearFlag_SO2(const DMAMUX_Channel_TypeDef *DMAMUXx)
{
  (void)(DMAMUXx);
  SET_BIT(DMAMUX1_ChannelStatus->CFR, DMAMUX_CFR_CSOF2);
}

   
                                                               
                                                              
                                            
                
    
__STATIC_INLINE void LL_DMAMUX_ClearFlag_SO3(const DMAMUX_Channel_TypeDef *DMAMUXx)
{
  (void)(DMAMUXx);
  SET_BIT(DMAMUX1_ChannelStatus->CFR, DMAMUX_CFR_CSOF3);
}

   
                                                               
                                                              
                                            
                
    
__STATIC_INLINE void LL_DMAMUX_ClearFlag_SO4(const DMAMUX_Channel_TypeDef *DMAMUXx)
{
  (void)(DMAMUXx);
  SET_BIT(DMAMUX1_ChannelStatus->CFR, DMAMUX_CFR_CSOF4);
}

   
                                                               
                                                              
                                            
                
    
__STATIC_INLINE void LL_DMAMUX_ClearFlag_SO5(const DMAMUX_Channel_TypeDef *DMAMUXx)
{
  (void)(DMAMUXx);
  SET_BIT(DMAMUX1_ChannelStatus->CFR, DMAMUX_CFR_CSOF5);
}

   
                                                               
                                                              
                                            
                
    
__STATIC_INLINE void LL_DMAMUX_ClearFlag_SO6(const DMAMUX_Channel_TypeDef *DMAMUXx)
{
  (void)(DMAMUXx);
  SET_BIT(DMAMUX1_ChannelStatus->CFR, DMAMUX_CFR_CSOF6);
}

   
                                                               
                                                              
                                            
                
    
__STATIC_INLINE void LL_DMAMUX_ClearFlag_SO7(const DMAMUX_Channel_TypeDef *DMAMUXx)
{
  (void)(DMAMUXx);
  SET_BIT(DMAMUX1_ChannelStatus->CFR, DMAMUX_CFR_CSOF7);
}

   
                                                               
                                                              
                                            
                
    
__STATIC_INLINE void LL_DMAMUX_ClearFlag_SO8(const DMAMUX_Channel_TypeDef *DMAMUXx)
{
  (void)(DMAMUXx);
  SET_BIT(DMAMUX1_ChannelStatus->CFR, DMAMUX_CFR_CSOF8);
}

   
                                                               
                                                              
                                            
                
    
__STATIC_INLINE void LL_DMAMUX_ClearFlag_SO9(const DMAMUX_Channel_TypeDef *DMAMUXx)
{
  (void)(DMAMUXx);
  SET_BIT(DMAMUX1_ChannelStatus->CFR, DMAMUX_CFR_CSOF9);
}

   
                                                                
                                                               
                                            
                
    
__STATIC_INLINE void LL_DMAMUX_ClearFlag_SO10(const DMAMUX_Channel_TypeDef *DMAMUXx)
{
  (void)(DMAMUXx);
  SET_BIT(DMAMUX1_ChannelStatus->CFR, DMAMUX_CFR_CSOF10);
}

   
                                                                
                                                               
                                            
                
    
__STATIC_INLINE void LL_DMAMUX_ClearFlag_SO11(const DMAMUX_Channel_TypeDef *DMAMUXx)
{
  (void)(DMAMUXx);
  SET_BIT(DMAMUX1_ChannelStatus->CFR, DMAMUX_CFR_CSOF11);
}

   
                                                                
                                                               
                                            
                
    
__STATIC_INLINE void LL_DMAMUX_ClearFlag_SO12(const DMAMUX_Channel_TypeDef *DMAMUXx)
{
  (void)(DMAMUXx);
  SET_BIT(DMAMUX1_ChannelStatus->CFR, DMAMUX_CFR_CSOF12);
}

   
                                                                
                                                               
                                            
                
    
__STATIC_INLINE void LL_DMAMUX_ClearFlag_SO13(const DMAMUX_Channel_TypeDef *DMAMUXx)
{
  (void)(DMAMUXx);
  SET_BIT(DMAMUX1_ChannelStatus->CFR, DMAMUX_CFR_CSOF13);
}

   
                                                                 
                                                               
                                            
                
    
__STATIC_INLINE void LL_DMAMUX_ClearFlag_RGO0(const DMAMUX_Channel_TypeDef *DMAMUXx)
{
  (void)(DMAMUXx);
  SET_BIT(DMAMUX1_RequestGenStatus->RGCFR, DMAMUX_RGCFR_COF0);
}

   
                                                                 
                                                               
                                            
                
    
__STATIC_INLINE void LL_DMAMUX_ClearFlag_RGO1(const DMAMUX_Channel_TypeDef *DMAMUXx)
{
  (void)(DMAMUXx);
  SET_BIT(DMAMUX1_RequestGenStatus->RGCFR, DMAMUX_RGCFR_COF1);
}

   
                                                                 
                                                               
                                            
                
    
__STATIC_INLINE void LL_DMAMUX_ClearFlag_RGO2(const DMAMUX_Channel_TypeDef *DMAMUXx)
{
  (void)(DMAMUXx);
  SET_BIT(DMAMUX1_RequestGenStatus->RGCFR, DMAMUX_RGCFR_COF2);
}

   
                                                                 
                                                               
                                            
                
    
__STATIC_INLINE void LL_DMAMUX_ClearFlag_RGO3(const DMAMUX_Channel_TypeDef *DMAMUXx)
{
  (void)(DMAMUXx);
  SET_BIT(DMAMUX1_RequestGenStatus->RGCFR, DMAMUX_RGCFR_COF3);
}

   
      
    

                                                      
      
    

   
                                                                                   
                                                                    
                                                                     
                                                            
                                    
                                                                      
                                         
                                         
                                         
                                         
                                         
                                         
                                         
                                         
                                         
                                         
                                          
                                          
                                          
                                          
                
    
__STATIC_INLINE void LL_DMAMUX_EnableIT_SO(const DMAMUX_Channel_TypeDef *DMAMUXx, uint32_t Channel)
{
  (void)(DMAMUXx);
  SET_BIT((DMAMUX1_Channel0 + Channel)->CCR, DMAMUX_CxCR_SOIE);
}

   
                                                                                    
                                                                    
                                                                     
                                                             
                                    
                                                                      
                                         
                                         
                                         
                                         
                                         
                                         
                                         
                                         
                                         
                                         
                                          
                                          
                                          
                                          
                
    
__STATIC_INLINE void LL_DMAMUX_DisableIT_SO(const DMAMUX_Channel_TypeDef *DMAMUXx, uint32_t Channel)
{
  (void)(DMAMUXx);
  CLEAR_BIT((DMAMUX1_Channel0 + Channel)->CCR, DMAMUX_CxCR_SOIE);
}

   
                                                                                                            
                                                                    
                                                                     
                                                               
                                    
                                                                      
                                         
                                         
                                         
                                         
                                         
                                         
                                         
                                         
                                         
                                         
                                          
                                          
                                          
                                          
                                  
    
__STATIC_INLINE uint32_t LL_DMAMUX_IsEnabledIT_SO(const DMAMUX_Channel_TypeDef *DMAMUXx, uint32_t Channel)
{
  (void)(DMAMUXx);
  return (((READ_BIT((DMAMUX1_Channel0 + Channel)->CCR, DMAMUX_CxCR_SOIE)) == (DMAMUX_CxCR_SOIE)) ? 1UL : 0UL);
}

   
                                                                                              
                                                             
                                    
                                                                                
                                         
                                         
                                         
                                         
                
    
__STATIC_INLINE void LL_DMAMUX_EnableIT_RGO(const DMAMUX_Channel_TypeDef *DMAMUXx, uint32_t RequestGenChannel)
{
  (void)(DMAMUXx);
  SET_BIT((DMAMUX1_RequestGenerator0 + RequestGenChannel)->RGCR, DMAMUX_RGxCR_OIE);
}

   
                                                                                               
                                                              
                                    
                                                                                
                                         
                                         
                                         
                                         
                
    
__STATIC_INLINE void LL_DMAMUX_DisableIT_RGO(const DMAMUX_Channel_TypeDef *DMAMUXx, uint32_t RequestGenChannel)
{
  (void)(DMAMUXx);
  CLEAR_BIT((DMAMUX1_RequestGenerator0 + RequestGenChannel)->RGCR, DMAMUX_RGxCR_OIE);
}

   
                                                                                                                       
                                                                
                                    
                                                                                
                                         
                                         
                                         
                                         
                                  
    
__STATIC_INLINE uint32_t LL_DMAMUX_IsEnabledIT_RGO(const DMAMUX_Channel_TypeDef *DMAMUXx, uint32_t RequestGenChannel)
{
  (void)(DMAMUXx);
  return ((READ_BIT((DMAMUX1_RequestGenerator0 + RequestGenChannel)->RGCR, DMAMUX_RGxCR_OIE) == (DMAMUX_RGxCR_OIE)) ? 1UL : 0UL);
}

   
      
    

   
      
    

   
      
    

#endif              

   
      
    

#ifdef __cplusplus
}
#endif

#endif                            

