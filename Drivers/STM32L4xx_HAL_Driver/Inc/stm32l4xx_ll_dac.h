/**
  ******************************************************************************
  * @file    stm32l4xx_ll_dac.h
  * @author  MCD Application Team
  * @brief   Header file of DAC LL module.
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

                                                                                
#ifndef STM32L4xx_LL_DAC_H
#define STM32L4xx_LL_DAC_H

#ifdef __cplusplus
extern "C" {
#endif

                                                                                
#include "stm32l4xx.h"

                                   
      
    

#if defined (DAC1)

                        
      
    

                                                                                
                                                                                

                                                                                
                                                            
      
    

                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
#define DAC_CR_CH1_BITOFFSET           0U                                                                                       
#define DAC_CR_CH2_BITOFFSET           16U                                                                                      
#define DAC_CR_CHX_BITOFFSET_MASK      (DAC_CR_CH1_BITOFFSET | DAC_CR_CH2_BITOFFSET)

#define DAC_SWTR_CH1                   (DAC_SWTRIGR_SWTRIG1)                                                      
#if defined(DAC_CHANNEL2_SUPPORT)
#define DAC_SWTR_CH2                   (DAC_SWTRIGR_SWTRIG2)                                                      
#define DAC_SWTR_CHX_MASK              (DAC_SWTR_CH1 | DAC_SWTR_CH2)
#else
#define DAC_SWTR_CHX_MASK              (DAC_SWTR_CH1)
#endif                           

#define DAC_REG_DHR12R1_REGOFFSET      0x00000000U                                                                
#define DAC_REG_DHR12L1_REGOFFSET      0x00100000U                                                                                                          
#define DAC_REG_DHR8R1_REGOFFSET       0x02000000U                                                                                                          
#if defined(DAC_CHANNEL2_SUPPORT)
#define DAC_REG_DHR12R2_REGOFFSET      0x30000000U                                                                                                          
#define DAC_REG_DHR12L2_REGOFFSET      0x00400000U                                                                                                          
#define DAC_REG_DHR8R2_REGOFFSET       0x05000000U                                                                                                          
#endif                           
#define DAC_REG_DHR12RX_REGOFFSET_MASK 0xF0000000U
#define DAC_REG_DHR12LX_REGOFFSET_MASK 0x00F00000U
#define DAC_REG_DHR8RX_REGOFFSET_MASK  0x0F000000U
#define DAC_REG_DHRX_REGOFFSET_MASK    (DAC_REG_DHR12RX_REGOFFSET_MASK | DAC_REG_DHR12LX_REGOFFSET_MASK | DAC_REG_DHR8RX_REGOFFSET_MASK)

#define DAC_REG_DOR1_REGOFFSET         0x00000000U                                                             
#if defined(DAC_CHANNEL2_SUPPORT)
#define DAC_REG_DOR2_REGOFFSET         0x00000020U                                                                                                   
#define DAC_REG_DORX_REGOFFSET_MASK    (DAC_REG_DOR1_REGOFFSET | DAC_REG_DOR2_REGOFFSET)
#else
#define DAC_REG_DORX_REGOFFSET_MASK    (DAC_REG_DOR1_REGOFFSET)
#endif                           

#define DAC_REG_SHSR1_REGOFFSET        0x00000000U                                                              
#if defined(DAC_CHANNEL2_SUPPORT)
#define DAC_REG_SHSR2_REGOFFSET        0x00000040U                                                                                                     
#define DAC_REG_SHSRX_REGOFFSET_MASK   (DAC_REG_SHSR1_REGOFFSET | DAC_REG_SHSR2_REGOFFSET)
#else
#define DAC_REG_SHSRX_REGOFFSET_MASK   (DAC_REG_SHSR1_REGOFFSET)
#endif                           

#define DAC_REG_DHR_REGOFFSET_MASK_POSBIT0         0x0000000FU                                                                                                     
#define DAC_REG_DORX_REGOFFSET_MASK_POSBIT0        0x00000001U                                                                
#define DAC_REG_SHSRX_REGOFFSET_MASK_POSBIT0       0x00000001U                                                                 

#define DAC_REG_DHR12RX_REGOFFSET_BITOFFSET_POS           28U                                                                                                                      
#define DAC_REG_DHR12LX_REGOFFSET_BITOFFSET_POS           20U                                                                                                                      
#define DAC_REG_DHR8RX_REGOFFSET_BITOFFSET_POS            24U                                                                                                                      
#define DAC_REG_DORX_REGOFFSET_BITOFFSET_POS               5U                                                                                                               
#define DAC_REG_SHSRX_REGOFFSET_BITOFFSET_POS              6U                                                                                                                 

                                  
#if defined(DAC_CHANNEL2_SUPPORT)
#define DAC_DHR12RD_DACC2DHR_BITOFFSET_POS                DAC_DHR12RD_DACC2DHR_Pos
#define DAC_DHR12LD_DACC2DHR_BITOFFSET_POS                DAC_DHR12LD_DACC2DHR_Pos
#define DAC_DHR8RD_DACC2DHR_BITOFFSET_POS                 DAC_DHR8RD_DACC2DHR_Pos
#endif                           

                        
#define DAC_DIGITAL_SCALE_12BITS                        4095U                                                                                                                                                                

   
      
    


                                                                                
                                                      
      
    

   
                                                                    
                                                                 
                       
                                                                    
                                                                             
                                       
  
#define __DAC_PTR_REG_OFFSET(__REG__, __REG_OFFFSET__)                         \
 ((uint32_t *)((uint32_t) ((uint32_t)(&(__REG__)) + ((__REG_OFFFSET__) << 2U))))

   
      
    


                                                                                
#if defined(USE_FULL_LL_DRIVER)
                                                        
      
    

   
                                                                  
    
typedef struct
{
  uint32_t TriggerSource;                                                                                                                                                                           
                                                                                                           

                                                                                                                                              

  uint32_t WaveAutoGeneration;                                                                                       
                                                                                                                      

                                                                                                                                                   

  uint32_t WaveAutoGenerationConfig;                                                                                 
                                                                                                                                                                               
                                                                                                                                                                              
                                                                                                                                  

                                                                                                                                                                                  
                                                                                                    

  uint32_t OutputBuffer;                                                                        
                                                                                                          

                                                                                                                                             

  uint32_t OutputConnection;                                                                        
                                                                                                              

                                                                                                                                                 

  uint32_t OutputMode;                                                                                                  
                                                                                                        

                                                                                                                                           
} LL_DAC_InitTypeDef;

   
      
    
#endif                         

                                                                                
                                                              
      
    

                                          
                                                                          
      
    
                         
#define LL_DAC_FLAG_DMAUDR1                (DAC_SR_DMAUDR1)                                          
#define LL_DAC_FLAG_CAL1                   (DAC_SR_CAL_FLAG1)                                                     
#define LL_DAC_FLAG_BWST1                  (DAC_SR_BWST1)                                                        

#if defined(DAC_CHANNEL2_SUPPORT)
                         
#define LL_DAC_FLAG_DMAUDR2                (DAC_SR_DMAUDR2)                                          
#define LL_DAC_FLAG_CAL2                   (DAC_SR_CAL_FLAG2)                                                     
#define LL_DAC_FLAG_BWST2                  (DAC_SR_BWST2)                                                        
#endif                           
   
      
    

                                            
                                                                                             
      
    
#define LL_DAC_IT_DMAUDRIE1                (DAC_CR_DMAUDRIE1)                                                
#if defined(DAC_CHANNEL2_SUPPORT)
#define LL_DAC_IT_DMAUDRIE2                (DAC_CR_DMAUDRIE2)                                                
#endif                           
   
      
    

                                            
      
    
#define LL_DAC_CHANNEL_1                   (DAC_REG_SHSR1_REGOFFSET | DAC_REG_DOR1_REGOFFSET | DAC_REG_DHR12R1_REGOFFSET | DAC_REG_DHR12L1_REGOFFSET | DAC_REG_DHR8R1_REGOFFSET | DAC_CR_CH1_BITOFFSET | DAC_SWTR_CH1)                      
#if defined(DAC_CHANNEL2_SUPPORT)
#define LL_DAC_CHANNEL_2                   (DAC_REG_SHSR2_REGOFFSET | DAC_REG_DOR2_REGOFFSET | DAC_REG_DHR12R2_REGOFFSET | DAC_REG_DHR12L2_REGOFFSET | DAC_REG_DHR8R2_REGOFFSET | DAC_CR_CH2_BITOFFSET | DAC_SWTR_CH2)                      
#endif                           
   
      
    
#if defined (DAC_CR_HFSEL)                                    

                                                                             
                                                                                                                                     
      
    
#define LL_DAC_HIGH_FREQ_MODE_DISABLE         0x00000000U                                                      
#define LL_DAC_HIGH_FREQ_MODE_ABOVE_80MHZ     (DAC_CR_HFSEL)                                                                          
   
      
    
#endif                                    

                                                         
      
    
#define LL_DAC_MODE_NORMAL_OPERATION       0x00000000U                                                         
#define LL_DAC_MODE_CALIBRATION            (DAC_CR_CEN1)                                                  
   
      
    

                                                         
      
    
#if defined (DAC_CR_TSEL1_3)
#define LL_DAC_TRIG_EXT_TIM1_TRGO          (                                                   DAC_CR_TSEL1_0)                                                                    
#define LL_DAC_TRIG_EXT_TIM2_TRGO          (                                  DAC_CR_TSEL1_1                 )                                                                    
#define LL_DAC_TRIG_EXT_TIM4_TRGO          (                                  DAC_CR_TSEL1_1 | DAC_CR_TSEL1_0)                                                                    
#define LL_DAC_TRIG_EXT_TIM5_TRGO          (                 DAC_CR_TSEL1_2                                  )                                                                    
#define LL_DAC_TRIG_EXT_TIM6_TRGO          (                 DAC_CR_TSEL1_2 |                  DAC_CR_TSEL1_0)                                                                    
#define LL_DAC_TRIG_EXT_TIM7_TRGO          (                 DAC_CR_TSEL1_2 | DAC_CR_TSEL1_1                 )                                                                    
#define LL_DAC_TRIG_EXT_TIM8_TRGO          (                 DAC_CR_TSEL1_2 | DAC_CR_TSEL1_1 | DAC_CR_TSEL1_0)                                                                    
#define LL_DAC_TRIG_EXT_TIM15_TRGO         (DAC_CR_TSEL1_3                                                   )                                                                     
#define LL_DAC_TRIG_EXT_LPTIM1_OUT         (DAC_CR_TSEL1_3                  | DAC_CR_TSEL1_1 | DAC_CR_TSEL1_0)                                                                      
#define LL_DAC_TRIG_EXT_LPTIM2_OUT         (DAC_CR_TSEL1_3 | DAC_CR_TSEL1_2                                  )                                                                      
#define LL_DAC_TRIG_EXT_EXTI_LINE9         (DAC_CR_TSEL1_3 | DAC_CR_TSEL1_2                  | DAC_CR_TSEL1_0)                                                                                     
#define LL_DAC_TRIG_SOFTWARE               0x00000000U                                                                                                                   
#else
#define LL_DAC_TRIG_SOFTWARE               (DAC_CR_TSEL1_2 | DAC_CR_TSEL1_1 | DAC_CR_TSEL1_0)                                                                            
#define LL_DAC_TRIG_EXT_TIM2_TRGO          (DAC_CR_TSEL1_2                                  )                                                                                     
#define LL_DAC_TRIG_EXT_TIM4_TRGO          (DAC_CR_TSEL1_2                  | DAC_CR_TSEL1_0)                                                                                     
#define LL_DAC_TRIG_EXT_TIM5_TRGO          (                 DAC_CR_TSEL1_1 | DAC_CR_TSEL1_0)                                                                                     
#define LL_DAC_TRIG_EXT_TIM6_TRGO          0x00000000U                                                                                                                            
#define LL_DAC_TRIG_EXT_TIM7_TRGO          (                 DAC_CR_TSEL1_1                 )                                                                                     
#define LL_DAC_TRIG_EXT_TIM8_TRGO          (                                  DAC_CR_TSEL1_0)                                                                                     
#define LL_DAC_TRIG_EXT_EXTI_LINE9         (DAC_CR_TSEL1_2 | DAC_CR_TSEL1_1                 )                                                                                                     
#endif

   
      
    

                                                                                        
      
    
#define LL_DAC_WAVE_AUTO_GENERATION_NONE     0x00000000U                                                                            
#define LL_DAC_WAVE_AUTO_GENERATION_NOISE    (               DAC_CR_WAVE1_0)                                                                                     
#define LL_DAC_WAVE_AUTO_GENERATION_TRIANGLE (DAC_CR_WAVE1_1               )                                                                                        
   
      
    

                                                                                                
      
    
#define LL_DAC_NOISE_LFSR_UNMASK_BIT0      0x00000000U                                                                                                                                      
#define LL_DAC_NOISE_LFSR_UNMASK_BITS1_0   (                                                   DAC_CR_MAMP1_0)                                                                                   
#define LL_DAC_NOISE_LFSR_UNMASK_BITS2_0   (                                  DAC_CR_MAMP1_1                 )                                                                                   
#define LL_DAC_NOISE_LFSR_UNMASK_BITS3_0   (                                  DAC_CR_MAMP1_1 | DAC_CR_MAMP1_0)                                                                                   
#define LL_DAC_NOISE_LFSR_UNMASK_BITS4_0   (                 DAC_CR_MAMP1_2                                  )                                                                                   
#define LL_DAC_NOISE_LFSR_UNMASK_BITS5_0   (                 DAC_CR_MAMP1_2                  | DAC_CR_MAMP1_0)                                                                                   
#define LL_DAC_NOISE_LFSR_UNMASK_BITS6_0   (                 DAC_CR_MAMP1_2 | DAC_CR_MAMP1_1                 )                                                                                   
#define LL_DAC_NOISE_LFSR_UNMASK_BITS7_0   (                 DAC_CR_MAMP1_2 | DAC_CR_MAMP1_1 | DAC_CR_MAMP1_0)                                                                                   
#define LL_DAC_NOISE_LFSR_UNMASK_BITS8_0   (DAC_CR_MAMP1_3                                                   )                                                                                   
#define LL_DAC_NOISE_LFSR_UNMASK_BITS9_0   (DAC_CR_MAMP1_3                                   | DAC_CR_MAMP1_0)                                                                                   
#define LL_DAC_NOISE_LFSR_UNMASK_BITS10_0  (DAC_CR_MAMP1_3                  | DAC_CR_MAMP1_1                 )                                                                                    
#define LL_DAC_NOISE_LFSR_UNMASK_BITS11_0  (DAC_CR_MAMP1_3                  | DAC_CR_MAMP1_1 | DAC_CR_MAMP1_0)                                                                                    
   
      
    

                                                                                        
      
    
#define LL_DAC_TRIANGLE_AMPLITUDE_1        0x00000000U                                                                                                                                                               
#define LL_DAC_TRIANGLE_AMPLITUDE_3        (                                                   DAC_CR_MAMP1_0)                                                                                                       
#define LL_DAC_TRIANGLE_AMPLITUDE_7        (                                  DAC_CR_MAMP1_1                 )                                                                                                       
#define LL_DAC_TRIANGLE_AMPLITUDE_15       (                                  DAC_CR_MAMP1_1 | DAC_CR_MAMP1_0)                                                                                                        
#define LL_DAC_TRIANGLE_AMPLITUDE_31       (                 DAC_CR_MAMP1_2                                  )                                                                                                        
#define LL_DAC_TRIANGLE_AMPLITUDE_63       (                 DAC_CR_MAMP1_2                  | DAC_CR_MAMP1_0)                                                                                                        
#define LL_DAC_TRIANGLE_AMPLITUDE_127      (                 DAC_CR_MAMP1_2 | DAC_CR_MAMP1_1                 )                                                                                                         
#define LL_DAC_TRIANGLE_AMPLITUDE_255      (                 DAC_CR_MAMP1_2 | DAC_CR_MAMP1_1 | DAC_CR_MAMP1_0)                                                                                                         
#define LL_DAC_TRIANGLE_AMPLITUDE_511      (DAC_CR_MAMP1_3                                                   )                                                                                                         
#define LL_DAC_TRIANGLE_AMPLITUDE_1023     (DAC_CR_MAMP1_3                                   | DAC_CR_MAMP1_0)                                                                                                          
#define LL_DAC_TRIANGLE_AMPLITUDE_2047     (DAC_CR_MAMP1_3                  | DAC_CR_MAMP1_1                 )                                                                                                          
#define LL_DAC_TRIANGLE_AMPLITUDE_4095     (DAC_CR_MAMP1_3                  | DAC_CR_MAMP1_1 | DAC_CR_MAMP1_0)                                                                                                          
   
      
    

                                                           
      
    
#define LL_DAC_OUTPUT_MODE_NORMAL          0x00000000U                                                                       
#define LL_DAC_OUTPUT_MODE_SAMPLE_AND_HOLD (DAC_MCR_MODE1_2)                                                                                                                                                                                                                           
   
      
    

                                                               
      
    
#define LL_DAC_OUTPUT_BUFFER_ENABLE        0x00000000U                                                                                                                                      
#define LL_DAC_OUTPUT_BUFFER_DISABLE       (DAC_MCR_MODE1_1)                                                                                                                                  
   
      
    

                                                                       
      
    
#define LL_DAC_OUTPUT_CONNECT_GPIO         0x00000000U                                                                                 
#define LL_DAC_OUTPUT_CONNECT_INTERNAL     (DAC_MCR_MODE1_0)                                                                                                                                                                                                                                                                                           
   
      
    

                                                                 
      
    
#define LL_DAC_RESOLUTION_12B              0x00000000U                                                   
#define LL_DAC_RESOLUTION_8B               0x00000002U                                                  
   
      
    

                                                                                
      
    
                                                                                
                                                                                
                                                                                
#define LL_DAC_DMA_REG_DATA_12BITS_RIGHT_ALIGNED  DAC_REG_DHR12RX_REGOFFSET_BITOFFSET_POS                                                                
#define LL_DAC_DMA_REG_DATA_12BITS_LEFT_ALIGNED   DAC_REG_DHR12LX_REGOFFSET_BITOFFSET_POS                                                               
#define LL_DAC_DMA_REG_DATA_8BITS_RIGHT_ALIGNED   DAC_REG_DHR8RX_REGOFFSET_BITOFFSET_POS                                                                
   
      
    

                                                                                 
                                                                              
                               
                                                                              
                                          
      
    

                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
#define LL_DAC_DELAY_STARTUP_VOLTAGE_SETTLING_US             8U                                                                                                                  


                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
#define LL_DAC_DELAY_VOLTAGE_SETTLING_US                     3U                                                     

   
      
    

   
      
    

                                                                                
                                                        
      
    

                                                                         
      
    

   
                                         
                                     
                                          
                                                         
                
    
#define LL_DAC_WriteReg(__INSTANCE__, __REG__, __VALUE__) WRITE_REG(__INSTANCE__->__REG__, (__VALUE__))

   
                                        
                                     
                                       
                          
    
#define LL_DAC_ReadReg(__INSTANCE__, __REG__) READ_REG(__INSTANCE__->__REG__)

   
      
    

                                                     
      
    

   
                                                                    
                                           
                    
                                                               
                                              
                                                                   
                               
                                                                          
                                      
                                      
                 
    
#define __LL_DAC_CHANNEL_TO_DECIMAL_NB(__CHANNEL__)                            \
  ((__CHANNEL__) & DAC_SWTR_CHX_MASK)

   
                                                                              
                                          
                    
                                               
                                                                  
                                                                       
                                        
                                
                                                              
                                      
                                      
    
#if defined(DAC_CHANNEL2_SUPPORT)
#define __LL_DAC_DECIMAL_NB_TO_CHANNEL(__DECIMAL_NB__)                         \
  (((__DECIMAL_NB__) == 1U)                                                    \
    ? (                                                                        \
       LL_DAC_CHANNEL_1                                                        \
      )                                                                        \
      :                                                                        \
      (((__DECIMAL_NB__) == 2U)                                                \
        ? (                                                                    \
           LL_DAC_CHANNEL_2                                                    \
          )                                                                    \
          :                                                                    \
          (                                                                    \
           0U                                                                  \
          )                                                                    \
      )                                                                        \
  )
#else
#define __LL_DAC_DECIMAL_NB_TO_CHANNEL(__DECIMAL_NB__)                         \
  (((__DECIMAL_NB__) == 1U)                                                    \
    ? (                                                                        \
       LL_DAC_CHANNEL_1                                                        \
      )                                                                        \
      :                                                                        \
      (                                                                        \
       0U                                                                      \
      )                                                                        \
  )
#endif                            

   
                                                                             
                                                               
                                                                       
                                                                   
                                        
                                                                                 
                                           
                                          
                                                                      
    
#define __LL_DAC_DIGITAL_SCALE(__DAC_RESOLUTION__)                             \
  ((0x00000FFFU) >> ((__DAC_RESOLUTION__) << 1U))

   
                                                                            
                                                            
                                                                          
                                      
                                                    
                                                    
                                                                      
                                                                             
                                                                         
                                                                      
                                                                  
                                          
                                                                                 
                                           
                                          
                                                     
    
#define __LL_DAC_CALC_VOLTAGE_TO_DATA(__VREFANALOG_VOLTAGE__,\
                                      __DAC_VOLTAGE__,\
                                      __DAC_RESOLUTION__)                      \
  ((__DAC_VOLTAGE__) * __LL_DAC_DIGITAL_SCALE(__DAC_RESOLUTION__)              \
   / (__VREFANALOG_VOLTAGE__)                                                  \
  )

   
      
    

   
      
    


                                                                                
                                                              
      
    

#if defined (DAC_CR_HFSEL)                                    

                                                                                                 
      
    
   
                                                                               
                                                               
                             
                                                                           
                                                   
                                                       
                
    
__STATIC_INLINE void LL_DAC_SetHighFrequencyMode(DAC_TypeDef *DACx, uint32_t HighFreqMode)
{
  MODIFY_REG(DACx->CR, DAC_CR_HFSEL, HighFreqMode);
}

   
                                                                               
                                                               
                             
                                                              
                                                   
                                                       
    
__STATIC_INLINE uint32_t LL_DAC_GetHighFrequencyMode(DAC_TypeDef *DACx)
{
  return (uint32_t)(READ_BIT(DACx->CR, DAC_CR_HFSEL));
}
   
      
    

#endif                                    

                                                                   
      
    

   
                                                                
                                                 
                                                    
                                                  
                             
                                                                          
                                      
                                      
                                                                          
                                                  
                                             
                
    
__STATIC_INLINE void LL_DAC_SetMode(DAC_TypeDef *DACx, uint32_t DAC_Channel, uint32_t ChannelMode)
{
  MODIFY_REG(DACx->CR,
             DAC_CR_CEN1 << (DAC_Channel & DAC_CR_CHX_BITOFFSET_MASK),
             ChannelMode << (DAC_Channel & DAC_CR_CHX_BITOFFSET_MASK));
}

   
                                                                
                                                 
                                                    
                                                  
                             
                                                                          
                                      
                                      
                                                              
                                                  
                                             
    
__STATIC_INLINE uint32_t LL_DAC_GetMode(DAC_TypeDef *DACx, uint32_t DAC_Channel)
{
  return (uint32_t)(READ_BIT(DACx->CR, DAC_CR_CEN1 << (DAC_Channel & DAC_CR_CHX_BITOFFSET_MASK))
                    >> (DAC_Channel & DAC_CR_CHX_BITOFFSET_MASK)
                   );
}

   
                                                                       
                                                                
                                                                          
                                                             
                                                           
                             
                                                                          
                                      
                                      
                                                                       
                
    
__STATIC_INLINE void LL_DAC_SetTrimmingValue(DAC_TypeDef *DACx, uint32_t DAC_Channel, uint32_t TrimmingValue)
{
  MODIFY_REG(DACx->CCR,
             DAC_CCR_OTRIM1 << (DAC_Channel & DAC_CR_CHX_BITOFFSET_MASK),
             TrimmingValue << (DAC_Channel & DAC_CR_CHX_BITOFFSET_MASK));
}

   
                                                                       
                                                                
                                                                          
                                                             
                                                           
                             
                                                                          
                                      
                                      
                                                                       
    
__STATIC_INLINE uint32_t LL_DAC_GetTrimmingValue(DAC_TypeDef *DACx, uint32_t DAC_Channel)
{
  return (uint32_t)(READ_BIT(DACx->CCR, DAC_CCR_OTRIM1 << (DAC_Channel & DAC_CR_CHX_BITOFFSET_MASK))
                    >> (DAC_Channel & DAC_CR_CHX_BITOFFSET_MASK)
                   );
}

   
                                                                           
                                                                      
                                                                       
                                                                           
                                                
                                                                    
                                                                  
                                                             
                                                           
                             
                                                                          
                                      
                                      
                                                                            
                                          
                                               
                                               
                                               
                                               
                                               
                                               
                                               
                                                
                                                
                                                
                                                
                
    
__STATIC_INLINE void LL_DAC_SetTriggerSource(DAC_TypeDef *DACx, uint32_t DAC_Channel, uint32_t TriggerSource)
{
  MODIFY_REG(DACx->CR,
             DAC_CR_TSEL1 << (DAC_Channel & DAC_CR_CHX_BITOFFSET_MASK),
             TriggerSource << (DAC_Channel & DAC_CR_CHX_BITOFFSET_MASK));
}

   
                                                                           
                                                                      
                                                                       
                                                                    
                                                                  
                                                             
                                                           
                             
                                                                          
                                      
                                          
   
                                                                             
                                                                    
                                                              
                                          
                                               
                                               
                                               
                                               
                                               
                                               
                                               
                                                
                                                
                                                
                                                
    
__STATIC_INLINE uint32_t LL_DAC_GetTriggerSource(DAC_TypeDef *DACx, uint32_t DAC_Channel)
{
  return (uint32_t)(READ_BIT(DACx->CR, DAC_CR_TSEL1 << (DAC_Channel & DAC_CR_CHX_BITOFFSET_MASK))
                    >> (DAC_Channel & DAC_CR_CHX_BITOFFSET_MASK)
                   );
}

   
                                                      
                                         
                                                                  
                                                                
                             
                                                                          
                                      
                                          
   
                                                                             
                                                                    
                                                                                 
                                                      
                                                       
                                                          
                
    
__STATIC_INLINE void LL_DAC_SetWaveAutoGeneration(DAC_TypeDef *DACx, uint32_t DAC_Channel, uint32_t WaveAutoGeneration)
{
  MODIFY_REG(DACx->CR,
             DAC_CR_WAVE1 << (DAC_Channel & DAC_CR_CHX_BITOFFSET_MASK),
             WaveAutoGeneration << (DAC_Channel & DAC_CR_CHX_BITOFFSET_MASK));
}

   
                                                      
                                         
                                                                  
                                                                
                             
                                                                          
                                      
                                          
   
                                                                             
                                                                    
                                                              
                                                      
                                                       
                                                          
    
__STATIC_INLINE uint32_t LL_DAC_GetWaveAutoGeneration(DAC_TypeDef *DACx, uint32_t DAC_Channel)
{
  return (uint32_t)(READ_BIT(DACx->CR, DAC_CR_WAVE1 << (DAC_Channel & DAC_CR_CHX_BITOFFSET_MASK))
                    >> (DAC_Channel & DAC_CR_CHX_BITOFFSET_MASK)
                   );
}

   
                                                                           
                                                                            
                                                            
                                                      
                                                         
                                                                             
                                                          
                                                             
                                                           
                             
                                                                          
                                      
                                          
   
                                                                             
                                                                    
                                                                            
                                                   
                                                      
                                                      
                                                      
                                                      
                                                      
                                                      
                                                      
                                                      
                                                      
                                                       
                                                       
                
    
__STATIC_INLINE void LL_DAC_SetWaveNoiseLFSR(DAC_TypeDef *DACx, uint32_t DAC_Channel, uint32_t NoiseLFSRMask)
{
  MODIFY_REG(DACx->CR,
             DAC_CR_MAMP1 << (DAC_Channel & DAC_CR_CHX_BITOFFSET_MASK),
             NoiseLFSRMask << (DAC_Channel & DAC_CR_CHX_BITOFFSET_MASK));
}

   
                                                                           
                                                                            
                                                             
                                                           
                             
                                                                          
                                      
                                          
   
                                                                             
                                                                    
                                                              
                                                   
                                                      
                                                      
                                                      
                                                      
                                                      
                                                      
                                                      
                                                      
                                                      
                                                       
                                                       
    
__STATIC_INLINE uint32_t LL_DAC_GetWaveNoiseLFSR(DAC_TypeDef *DACx, uint32_t DAC_Channel)
{
  return (uint32_t)(READ_BIT(DACx->CR, DAC_CR_MAMP1 << (DAC_Channel & DAC_CR_CHX_BITOFFSET_MASK))
                    >> (DAC_Channel & DAC_CR_CHX_BITOFFSET_MASK)
                   );
}

   
                                                                              
                                        
                                                            
                                                      
                                                         
                                                                             
                                                          
                                                                     
                                                                   
                             
                                                                          
                                      
                                          
   
                                                                             
                                                                    
                                                                                
                                                 
                                                 
                                                 
                                                  
                                                  
                                                  
                                                   
                                                   
                                                   
                                                    
                                                    
                                                    
                
    
__STATIC_INLINE void LL_DAC_SetWaveTriangleAmplitude(DAC_TypeDef *DACx, uint32_t DAC_Channel,
                                                     uint32_t TriangleAmplitude)
{
  MODIFY_REG(DACx->CR,
             DAC_CR_MAMP1 << (DAC_Channel & DAC_CR_CHX_BITOFFSET_MASK),
             TriangleAmplitude << (DAC_Channel & DAC_CR_CHX_BITOFFSET_MASK));
}

   
                                                                              
                                        
                                                                     
                                                                   
                             
                                                                          
                                      
                                          
   
                                                                             
                                                                    
                                                              
                                                 
                                                 
                                                 
                                                  
                                                  
                                                  
                                                   
                                                   
                                                   
                                                    
                                                    
                                                    
    
__STATIC_INLINE uint32_t LL_DAC_GetWaveTriangleAmplitude(DAC_TypeDef *DACx, uint32_t DAC_Channel)
{
  return (uint32_t)(READ_BIT(DACx->CR, DAC_CR_MAMP1 << (DAC_Channel & DAC_CR_CHX_BITOFFSET_MASK))
                    >> (DAC_Channel & DAC_CR_CHX_BITOFFSET_MASK)
                   );
}

   
                                                        
                                               
                                            
                    
                                                  
                                                             
                                
                                           
                                         
                                               
                                                                          
                                                                
                                                                            
                                                
                                                             
                                                               
                                                                    
                                                              
                                                                  
                                                               
                                                               
                                                                  
                                                                     
                                               
                                                           
                                                         
                                                         
                                                       
                             
                                                                          
                                      
                                          
   
                                                                             
                                                                    
                                                                         
                                               
                                                        
                                                                           
                                                 
                                                  
                                                                               
                                                
                                                    
                
    
__STATIC_INLINE void LL_DAC_ConfigOutput(DAC_TypeDef *DACx, uint32_t DAC_Channel, uint32_t OutputMode,
                                         uint32_t OutputBuffer, uint32_t OutputConnection)
{
  MODIFY_REG(DACx->MCR,
             (DAC_MCR_MODE1_2 | DAC_MCR_MODE1_1 | DAC_MCR_MODE1_0) << (DAC_Channel & DAC_CR_CHX_BITOFFSET_MASK),
             (OutputMode | OutputBuffer | OutputConnection) << (DAC_Channel & DAC_CR_CHX_BITOFFSET_MASK));
}

   
                                                         
                                         
                                                               
                                                                  
                                                                     
                                               
                                                           
                                                         
                                                          
                                                        
                             
                                                                          
                                      
                                          
   
                                                                             
                                                                    
                                                                         
                                               
                                                        
                
    
__STATIC_INLINE void LL_DAC_SetOutputMode(DAC_TypeDef *DACx, uint32_t DAC_Channel, uint32_t OutputMode)
{
  MODIFY_REG(DACx->MCR,
             (uint32_t)DAC_MCR_MODE1_2 << (DAC_Channel & DAC_CR_CHX_BITOFFSET_MASK),
             OutputMode << (DAC_Channel & DAC_CR_CHX_BITOFFSET_MASK));
}

   
                                                                                       
                                                          
                                                        
                             
                                                                          
                                      
                                          
   
                                                                             
                                                                    
                                                              
                                               
                                                        
    
__STATIC_INLINE uint32_t LL_DAC_GetOutputMode(DAC_TypeDef *DACx, uint32_t DAC_Channel)
{
  return (uint32_t)(READ_BIT(DACx->MCR, (uint32_t)DAC_MCR_MODE1_2 << (DAC_Channel & DAC_CR_CHX_BITOFFSET_MASK))
                    >> (DAC_Channel & DAC_CR_CHX_BITOFFSET_MASK)
                   );
}

   
                                                               
                                                                           
                                                              
                                                            
                                           
                                                            
                                                          
                             
                                                                          
                                      
                                          
   
                                                                             
                                                                    
                                                                           
                                                 
                                                  
                
    
__STATIC_INLINE void LL_DAC_SetOutputBuffer(DAC_TypeDef *DACx, uint32_t DAC_Channel, uint32_t OutputBuffer)
{
  MODIFY_REG(DACx->MCR,
             (uint32_t)DAC_MCR_MODE1_1 << (DAC_Channel & DAC_CR_CHX_BITOFFSET_MASK),
             OutputBuffer << (DAC_Channel & DAC_CR_CHX_BITOFFSET_MASK));
}

   
                                                                     
                                                            
                                                          
                             
                                                                          
                                      
                                          
   
                                                                             
                                                                    
                                                              
                                                 
                                                  
    
__STATIC_INLINE uint32_t LL_DAC_GetOutputBuffer(DAC_TypeDef *DACx, uint32_t DAC_Channel)
{
  return (uint32_t)(READ_BIT(DACx->MCR, (uint32_t)DAC_MCR_MODE1_1 << (DAC_Channel & DAC_CR_CHX_BITOFFSET_MASK))
                    >> (DAC_Channel & DAC_CR_CHX_BITOFFSET_MASK)
                   );
}

   
                                                                   
                                                                                     
                                                     
                                                                            
                                                
                                                             
                                                               
                                                                    
                                                              
                                                                  
                                                               
                                                                
                                                              
                             
                                                                          
                                      
                                          
   
                                                                             
                                                                    
                                                                               
                                                
                                                    
                
    
__STATIC_INLINE void LL_DAC_SetOutputConnection(DAC_TypeDef *DACx, uint32_t DAC_Channel, uint32_t OutputConnection)
{
  MODIFY_REG(DACx->MCR,
             (uint32_t)DAC_MCR_MODE1_0 << (DAC_Channel & DAC_CR_CHX_BITOFFSET_MASK),
             OutputConnection << (DAC_Channel & DAC_CR_CHX_BITOFFSET_MASK));
}

   
                                                                   
                                                                                     
                                                     
                                                                            
                                                
                                                             
                                                               
                                                                    
                                                              
                                                                  
                                                               
                                                                
                                                              
                             
                                                                          
                                      
                                          
   
                                                                             
                                                                    
                                                              
                                                
                                                    
    
__STATIC_INLINE uint32_t LL_DAC_GetOutputConnection(DAC_TypeDef *DACx, uint32_t DAC_Channel)
{
  return (uint32_t)(READ_BIT(DACx->MCR, (uint32_t)DAC_MCR_MODE1_0 << (DAC_Channel & DAC_CR_CHX_BITOFFSET_MASK))
                    >> (DAC_Channel & DAC_CR_CHX_BITOFFSET_MASK)
                   );
}

   
                                                                        
                       
                                                                
                                                                         
                                             
                                                                                
                                                                       
                                                                     
                             
                                                                          
                                      
                                          
   
                                                                             
                                                                    
                                                                      
                
    
__STATIC_INLINE void LL_DAC_SetSampleAndHoldSampleTime(DAC_TypeDef *DACx, uint32_t DAC_Channel, uint32_t SampleTime)
{
  __IO uint32_t *preg = __DAC_PTR_REG_OFFSET(DACx->SHSR1, (DAC_Channel >> DAC_REG_SHSRX_REGOFFSET_BITOFFSET_POS) & DAC_REG_SHSRX_REGOFFSET_MASK_POSBIT0);

  MODIFY_REG(*preg,
             DAC_SHSR1_TSAMPLE1,
             SampleTime);
}

   
                                                                        
                       
                                                                       
                                                                     
                             
                                                                          
                                      
                                          
   
                                                                             
                                                                    
                                                           
    
__STATIC_INLINE uint32_t LL_DAC_GetSampleAndHoldSampleTime(DAC_TypeDef *DACx, uint32_t DAC_Channel)
{
  __IO uint32_t const *preg = __DAC_PTR_REG_OFFSET(DACx->SHSR1, (DAC_Channel >> DAC_REG_SHSRX_REGOFFSET_BITOFFSET_POS) & DAC_REG_SHSRX_REGOFFSET_MASK_POSBIT0);

  return (uint32_t) READ_BIT(*preg, DAC_SHSR1_TSAMPLE1);
}

   
                                                                        
                     
                                                                     
                                                                   
                             
                                                                          
                                      
                                          
   
                                                                             
                                                                    
                                                                    
                
    
__STATIC_INLINE void LL_DAC_SetSampleAndHoldHoldTime(DAC_TypeDef *DACx, uint32_t DAC_Channel, uint32_t HoldTime)
{
  MODIFY_REG(DACx->SHHR,
             DAC_SHHR_THOLD1 << (DAC_Channel & DAC_CR_CHX_BITOFFSET_MASK),
             HoldTime << (DAC_Channel & DAC_CR_CHX_BITOFFSET_MASK));
}

   
                                                                        
                     
                                                                     
                                                                   
                             
                                                                          
                                      
                                          
   
                                                                             
                                                                    
                                                           
    
__STATIC_INLINE uint32_t LL_DAC_GetSampleAndHoldHoldTime(DAC_TypeDef *DACx, uint32_t DAC_Channel)
{
  return (uint32_t)(READ_BIT(DACx->SHHR, DAC_SHHR_THOLD1 << (DAC_Channel & DAC_CR_CHX_BITOFFSET_MASK))
                    >> (DAC_Channel & DAC_CR_CHX_BITOFFSET_MASK)
                   );
}

   
                                                                        
                        
                                                                        
                                                                      
                             
                                                                          
                                      
                                          
   
                                                                             
                                                                    
                                                                     
                
    
__STATIC_INLINE void LL_DAC_SetSampleAndHoldRefreshTime(DAC_TypeDef *DACx, uint32_t DAC_Channel, uint32_t RefreshTime)
{
  MODIFY_REG(DACx->SHRR,
             DAC_SHRR_TREFRESH1 << (DAC_Channel & DAC_CR_CHX_BITOFFSET_MASK),
             RefreshTime << (DAC_Channel & DAC_CR_CHX_BITOFFSET_MASK));
}

   
                                                                        
                        
                                                                        
                                                                      
                             
                                                                          
                                      
                                          
   
                                                                             
                                                                    
                                                         
    
__STATIC_INLINE uint32_t LL_DAC_GetSampleAndHoldRefreshTime(DAC_TypeDef *DACx, uint32_t DAC_Channel)
{
  return (uint32_t)(READ_BIT(DACx->SHRR, DAC_SHRR_TREFRESH1 << (DAC_Channel & DAC_CR_CHX_BITOFFSET_MASK))
                    >> (DAC_Channel & DAC_CR_CHX_BITOFFSET_MASK)
                   );
}

   
      
    

                                                     
      
    

   
                                                                    
                                                                 
                                                      
                                                         
                                                       
                             
                                                                          
                                      
                                          
   
                                                                             
                                                                    
                
    
__STATIC_INLINE void LL_DAC_EnableDMAReq(DAC_TypeDef *DACx, uint32_t DAC_Channel)
{
  SET_BIT(DACx->CR,
          DAC_CR_DMAEN1 << (DAC_Channel & DAC_CR_CHX_BITOFFSET_MASK));
}

   
                                                                     
                                                                 
                                                      
                                                          
                                                        
                             
                                                                          
                                      
                                          
   
                                                                             
                                                                    
                
    
__STATIC_INLINE void LL_DAC_DisableDMAReq(DAC_TypeDef *DACx, uint32_t DAC_Channel)
{
  CLEAR_BIT(DACx->CR,
            DAC_CR_DMAEN1 << (DAC_Channel & DAC_CR_CHX_BITOFFSET_MASK));
}

   
                                                                       
                                                                                             
                                                            
                                                          
                             
                                                                          
                                      
                                          
   
                                                                             
                                                                    
                                  
    
__STATIC_INLINE uint32_t LL_DAC_IsDMAReqEnabled(DAC_TypeDef *DACx, uint32_t DAC_Channel)
{
  return ((READ_BIT(DACx->CR,
                   DAC_CR_DMAEN1 << (DAC_Channel & DAC_CR_CHX_BITOFFSET_MASK))
           == (DAC_CR_DMAEN1 << (DAC_Channel & DAC_CR_CHX_BITOFFSET_MASK))) ? 1UL : 0UL);
}

   
                                                                           
                                                                              
                                                                  
                                                           
                                                                          
                                                                         
                                                                          
                                                
                    
                                          
                                                      
                                                                      
                                                                                                                             
                                                                        
                                                           
                                                           
                                                           
                                                           
                                                           
                                                         
                             
                                                                          
                                      
                                          
   
                                                                             
                                                                    
                                                                       
                                                              
                                                             
                                                             
                                
    
__STATIC_INLINE uint32_t LL_DAC_DMA_GetRegAddr(DAC_TypeDef *DACx, uint32_t DAC_Channel, uint32_t Register)
{
                                                                                
                                                                                
  return ((uint32_t)(__DAC_PTR_REG_OFFSET((DACx)->DHR12R1,
                                          ((DAC_Channel >> (Register & 0x1FUL)) & DAC_REG_DHR_REGOFFSET_MASK_POSBIT0))));
}
   
      
    

                                                           
      
    

   
                                        
                                                   
                                                 
                                                                     
                                                           
                                                           
                             
                                                                          
                                      
                                          
   
                                                                             
                                                                    
                
    
__STATIC_INLINE void LL_DAC_Enable(DAC_TypeDef *DACx, uint32_t DAC_Channel)
{
  SET_BIT(DACx->CR,
          DAC_CR_EN1 << (DAC_Channel & DAC_CR_CHX_BITOFFSET_MASK));
}

   
                                         
                                                    
                                                  
                             
                                                                          
                                      
                                          
   
                                                                             
                                                                    
                
    
__STATIC_INLINE void LL_DAC_Disable(DAC_TypeDef *DACx, uint32_t DAC_Channel)
{
  CLEAR_BIT(DACx->CR,
            DAC_CR_EN1 << (DAC_Channel & DAC_CR_CHX_BITOFFSET_MASK));
}

   
                                                         
                                                                   
                                                      
                                                    
                             
                                                                          
                                      
                                          
   
                                                                             
                                                                    
                                  
    
__STATIC_INLINE uint32_t LL_DAC_IsEnabled(DAC_TypeDef *DACx, uint32_t DAC_Channel)
{
  return ((READ_BIT(DACx->CR,
                   DAC_CR_EN1 << (DAC_Channel & DAC_CR_CHX_BITOFFSET_MASK))
           == (DAC_CR_EN1 << (DAC_Channel & DAC_CR_CHX_BITOFFSET_MASK))) ? 1UL : 0UL);
}

   
                                                       
                                                                     
                                                                      
                                                                                 
                                                          
                                                                    
                                                                          
                                         
                                                      
                                                          
                                                        
                             
                                                                          
                                      
                                          
   
                                                                             
                                                                    
                
    
__STATIC_INLINE void LL_DAC_EnableTrigger(DAC_TypeDef *DACx, uint32_t DAC_Channel)
{
  SET_BIT(DACx->CR,
          DAC_CR_TEN1 << (DAC_Channel & DAC_CR_CHX_BITOFFSET_MASK));
}

   
                                                        
                                                           
                                                         
                             
                                                                          
                                      
                                          
   
                                                                             
                                                                    
                
    
__STATIC_INLINE void LL_DAC_DisableTrigger(DAC_TypeDef *DACx, uint32_t DAC_Channel)
{
  CLEAR_BIT(DACx->CR,
            DAC_CR_TEN1 << (DAC_Channel & DAC_CR_CHX_BITOFFSET_MASK));
}

   
                                                          
                                                                   
                                                             
                                                           
                             
                                                                          
                                      
                                          
   
                                                                             
                                                                    
                                  
    
__STATIC_INLINE uint32_t LL_DAC_IsTriggerEnabled(DAC_TypeDef *DACx, uint32_t DAC_Channel)
{
  return ((READ_BIT(DACx->CR,
                   DAC_CR_TEN1 << (DAC_Channel & DAC_CR_CHX_BITOFFSET_MASK))
           == (DAC_CR_TEN1 << (DAC_Channel & DAC_CR_CHX_BITOFFSET_MASK))) ? 1UL : 0UL);
}

   
                                                                         
                                                                      
                          
                                
                                            
                                                     
                                                 
                                                 
                                                                    
                                                                       
                                                      
                                                          
                                                             
                                                           
                             
                                                                                  
                                      
                                          
   
                                                                             
                                                                    
                
    
__STATIC_INLINE void LL_DAC_TrigSWConversion(DAC_TypeDef *DACx, uint32_t DAC_Channel)
{
  SET_BIT(DACx->SWTRIGR,
          (DAC_Channel & DAC_SWTR_CHX_MASK));
}

   
                                                                  
                                                                    
                                         
                                                                      
                                                                    
                             
                                                                          
                                      
                                          
   
                                                                             
                                                                    
                                                                
                
    
__STATIC_INLINE void LL_DAC_ConvertData12RightAligned(DAC_TypeDef *DACx, uint32_t DAC_Channel, uint32_t Data)
{
  __IO uint32_t *preg = __DAC_PTR_REG_OFFSET(DACx->DHR12R1, (DAC_Channel >> DAC_REG_DHR12RX_REGOFFSET_BITOFFSET_POS) & DAC_REG_DHR_REGOFFSET_MASK_POSBIT0);

  MODIFY_REG(*preg,
             DAC_DHR12R1_DACC1DHR,
             Data);
}

   
                                                                  
                                                                     
                                         
                                                                     
                                                                   
                             
                                                                          
                                      
                                          
   
                                                                             
                                                                    
                                                                
                
    
__STATIC_INLINE void LL_DAC_ConvertData12LeftAligned(DAC_TypeDef *DACx, uint32_t DAC_Channel, uint32_t Data)
{
  __IO uint32_t *preg = __DAC_PTR_REG_OFFSET(DACx->DHR12R1, (DAC_Channel >> DAC_REG_DHR12LX_REGOFFSET_BITOFFSET_POS) & DAC_REG_DHR_REGOFFSET_MASK_POSBIT0);

  MODIFY_REG(*preg,
             DAC_DHR12L1_DACC1DHR,
             Data);
}

   
                                                                  
                                                                   
                                         
                                                                     
                                                                   
                             
                                                                          
                                      
                                          
   
                                                                             
                                                                    
                                                              
                
    
__STATIC_INLINE void LL_DAC_ConvertData8RightAligned(DAC_TypeDef *DACx, uint32_t DAC_Channel, uint32_t Data)
{
  __IO uint32_t *preg = __DAC_PTR_REG_OFFSET(DACx->DHR12R1, (DAC_Channel >> DAC_REG_DHR8RX_REGOFFSET_BITOFFSET_POS) & DAC_REG_DHR_REGOFFSET_MASK_POSBIT0);

  MODIFY_REG(*preg,
             DAC_DHR8R1_DACC1DHR,
             Data);
}

#if defined(DAC_CHANNEL2_SUPPORT)
   
                                                                  
                                                                    
                                  
                                                                          
                                                                        
                             
                                                                        
                                                                        
                
    
__STATIC_INLINE void LL_DAC_ConvertDualData12RightAligned(DAC_TypeDef *DACx, uint32_t DataChannel1,
                                                          uint32_t DataChannel2)
{
  MODIFY_REG(DACx->DHR12RD,
             (DAC_DHR12RD_DACC2DHR | DAC_DHR12RD_DACC1DHR),
             ((DataChannel2 << DAC_DHR12RD_DACC2DHR_BITOFFSET_POS) | DataChannel1));
}

   
                                                                  
                                                                     
                                  
                                                                         
                                                                       
                             
                                                                        
                                                                        
                
    
__STATIC_INLINE void LL_DAC_ConvertDualData12LeftAligned(DAC_TypeDef *DACx, uint32_t DataChannel1, uint32_t DataChannel2)
{
                                                                                
                                                                                
                                                                                
  MODIFY_REG(DACx->DHR12LD,
             (DAC_DHR12LD_DACC2DHR | DAC_DHR12LD_DACC1DHR),
             ((DataChannel2 << (DAC_DHR12LD_DACC2DHR_BITOFFSET_POS - 4U)) | DataChannel1));
}

   
                                                                  
                                                                   
                                  
                                                                        
                                                                      
                             
                                                                      
                                                                      
                
    
__STATIC_INLINE void LL_DAC_ConvertDualData8RightAligned(DAC_TypeDef *DACx, uint32_t DataChannel1, uint32_t DataChannel2)
{
  MODIFY_REG(DACx->DHR8RD,
             (DAC_DHR8RD_DACC2DHR | DAC_DHR8RD_DACC1DHR),
             ((DataChannel2 << DAC_DHR8RD_DACC2DHR_BITOFFSET_POS) | DataChannel1));
}

#endif                           
   
                                                                                  
                                                      
                                                                                
                                                          
                                                                               
                                                               
                                                             
                             
                                                                          
                                      
                                          
   
                                                                             
                                                                    
                                                           
    
__STATIC_INLINE uint32_t LL_DAC_RetrieveOutputData(DAC_TypeDef *DACx, uint32_t DAC_Channel)
{
  __IO uint32_t const *preg = __DAC_PTR_REG_OFFSET(DACx->DOR1, (DAC_Channel >> DAC_REG_DORX_REGOFFSET_BITOFFSET_POS) & DAC_REG_DORX_REGOFFSET_MASK_POSBIT0);

  return (uint16_t) READ_BIT(*preg, DAC_DOR1_DACC1DOR);
}

   
      
    

                                                       
      
    
   
                                                             
                                                            
                             
                                  
    
__STATIC_INLINE uint32_t LL_DAC_IsActiveFlag_CAL1(DAC_TypeDef *DACx)
{
  return ((READ_BIT(DACx->SR, LL_DAC_FLAG_CAL1) == (LL_DAC_FLAG_CAL1)) ? 1UL : 0UL);
}

#if defined(DAC_CHANNEL2_SUPPORT)
   
                                                             
                                                            
                             
                                  
    
__STATIC_INLINE uint32_t LL_DAC_IsActiveFlag_CAL2(DAC_TypeDef *DACx)
{
  return ((READ_BIT(DACx->SR, LL_DAC_FLAG_CAL2) == (LL_DAC_FLAG_CAL2)) ? 1UL : 0UL);
}

#endif                           
   
                                                                   
                                                             
                             
                                  
    
__STATIC_INLINE uint32_t LL_DAC_IsActiveFlag_BWST1(DAC_TypeDef *DACx)
{
  return ((READ_BIT(DACx->SR, LL_DAC_FLAG_BWST1) == (LL_DAC_FLAG_BWST1)) ? 1UL : 0UL);
}

#if defined(DAC_CHANNEL2_SUPPORT)
   
                                                                   
                                                             
                             
                                  
    
__STATIC_INLINE uint32_t LL_DAC_IsActiveFlag_BWST2(DAC_TypeDef *DACx)
{
  return ((READ_BIT(DACx->SR, LL_DAC_FLAG_BWST2) == (LL_DAC_FLAG_BWST2)) ? 1UL : 0UL);
}

#endif                           
   
                                                   
                                                               
                             
                                  
    
__STATIC_INLINE uint32_t LL_DAC_IsActiveFlag_DMAUDR1(DAC_TypeDef *DACx)
{
  return ((READ_BIT(DACx->SR, LL_DAC_FLAG_DMAUDR1) == (LL_DAC_FLAG_DMAUDR1)) ? 1UL : 0UL);
}

#if defined(DAC_CHANNEL2_SUPPORT)
   
                                                   
                                                               
                             
                                  
    
__STATIC_INLINE uint32_t LL_DAC_IsActiveFlag_DMAUDR2(DAC_TypeDef *DACx)
{
  return ((READ_BIT(DACx->SR, LL_DAC_FLAG_DMAUDR2) == (LL_DAC_FLAG_DMAUDR2)) ? 1UL : 0UL);
}
#endif                           

   
                                                     
                                                            
                             
                
    
__STATIC_INLINE void LL_DAC_ClearFlag_DMAUDR1(DAC_TypeDef *DACx)
{
  WRITE_REG(DACx->SR, LL_DAC_FLAG_DMAUDR1);
}

#if defined(DAC_CHANNEL2_SUPPORT)
   
                                                     
                                                            
                             
                
    
__STATIC_INLINE void LL_DAC_ClearFlag_DMAUDR2(DAC_TypeDef *DACx)
{
  WRITE_REG(DACx->SR, LL_DAC_FLAG_DMAUDR2);
}
#endif                           

   
      
    

                                                   
      
    

   
                                                           
                                                           
                             
                
    
__STATIC_INLINE void LL_DAC_EnableIT_DMAUDR1(DAC_TypeDef *DACx)
{
  SET_BIT(DACx->CR, LL_DAC_IT_DMAUDRIE1);
}

#if defined(DAC_CHANNEL2_SUPPORT)
   
                                                           
                                                           
                             
                
    
__STATIC_INLINE void LL_DAC_EnableIT_DMAUDR2(DAC_TypeDef *DACx)
{
  SET_BIT(DACx->CR, LL_DAC_IT_DMAUDRIE2);
}
#endif                           

   
                                                            
                                                            
                             
                
    
__STATIC_INLINE void LL_DAC_DisableIT_DMAUDR1(DAC_TypeDef *DACx)
{
  CLEAR_BIT(DACx->CR, LL_DAC_IT_DMAUDRIE1);
}

#if defined(DAC_CHANNEL2_SUPPORT)
   
                                                            
                                                            
                             
                
    
__STATIC_INLINE void LL_DAC_DisableIT_DMAUDR2(DAC_TypeDef *DACx)
{
  CLEAR_BIT(DACx->CR, LL_DAC_IT_DMAUDRIE2);
}
#endif                           

   
                                                        
                                                              
                             
                                  
    
__STATIC_INLINE uint32_t LL_DAC_IsEnabledIT_DMAUDR1(DAC_TypeDef *DACx)
{
  return ((READ_BIT(DACx->CR, LL_DAC_IT_DMAUDRIE1) == (LL_DAC_IT_DMAUDRIE1)) ? 1UL : 0UL);
}

#if defined(DAC_CHANNEL2_SUPPORT)
   
                                                        
                                                              
                             
                                  
    
__STATIC_INLINE uint32_t LL_DAC_IsEnabledIT_DMAUDR2(DAC_TypeDef *DACx)
{
  return ((READ_BIT(DACx->CR, LL_DAC_IT_DMAUDRIE2) == (LL_DAC_IT_DMAUDRIE2)) ? 1UL : 0UL);
}
#endif                           

   
      
    

#if defined(USE_FULL_LL_DRIVER)
                                                                           
      
    

ErrorStatus LL_DAC_DeInit(DAC_TypeDef *DACx);
ErrorStatus LL_DAC_Init(DAC_TypeDef *DACx, uint32_t DAC_Channel, LL_DAC_InitTypeDef *DAC_InitStruct);
void        LL_DAC_StructInit(LL_DAC_InitTypeDef *DAC_InitStruct);

   
      
    
#endif                         

   
      
    

   
      
    

#endif           

   
      
    

#ifdef __cplusplus
}
#endif

#endif                         

