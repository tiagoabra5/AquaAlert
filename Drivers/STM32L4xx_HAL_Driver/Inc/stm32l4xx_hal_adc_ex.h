/**
  ******************************************************************************
  * @file    stm32l4xx_hal_adc_ex.h
  * @author  MCD Application Team
  * @brief   Header file of ADC HAL extended module.
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

                                                                                
#ifndef STM32L4xx_HAL_ADC_EX_H
#define STM32L4xx_HAL_ADC_EX_H

#ifdef __cplusplus
extern "C" {
#endif

                                                                                
#include "stm32l4xx_hal_def.h"

                                    
      
    

                     
      
    

                                                                                
                                                              
      
    

   
                                                                     
    
typedef struct
{
  uint32_t Ratio;                                                                
                                                                                                            

  uint32_t RightBitShift;                                                                              
                                                                                                            
} ADC_InjOversamplingTypeDef;

   
                                                                                                     
                                                                    
                                                                                                       
                                                   
                                                                                                          
                                             
                                                                                                        
                                                        
                                                                                                                      
                                    
                                                                                                        
                                    
                                                                                                                       
                                                             
                                                                                                                   
                                                                                      
                                                                                                                    
                                                                                     
                                                  
                                                                                                                  
                                                                                                                    
                                                                           
    
typedef struct
{
  uint32_t InjectedChannel;                                                                               
                                                                                                       
                                                                                                                     
                                                                                                                    
                                                                              

  uint32_t InjectedRank;                                                                              
                                                                                                        
                                                                                                                  
                                                                                                                     
                                                                                                                
                                                                 

  uint32_t InjectedSamplingTime;                                                                      
                                                                      
                                                                                                                   
                                                                                                                        
                                                                                           
                                                                                                                     
                                                                                                                 
                                                                                                                      
                                                                                                                      
                                                                                                                      
                                                                                                                  
                                                                                                               

  uint32_t InjectedSingleDiff;                                                                 
                                                                                                                     
                                                                                                               
                                                                                                                 
                                                             
                                                                                
                                                                                          
                                                                                                                 
                                                                                                             
                                                                                                                
                                                                                    
                                                                                                                     
                                                                                    
                                                                                                                     
                                                                                                    
                                                                                                                  
                                                                                                               
                                                                              

  uint32_t InjectedOffsetNumber;                                         
                                                                                                          
                                                                                                              
                                                                                       

  uint32_t InjectedOffset;                                                                                     
                                                                                      
                                                                                                               
                                                                                                                        
                                                                                
                                                                                                                   
                                                                                                                      
                                                                                                                    
                                                                    

  uint32_t InjectedNbrOfConversion;                                                                                     
                                                                  
                                                                                                                       
                                                                              
                                                                                                                     
                                                                                                                  
                                                                                                                  
                                                                                                                       
                                                      

  FunctionalState InjectedDiscontinuousConvMode;                                                                      
                                                                                                       
                                                                                              
                                                                                                                 
                                                                                                                      
                                                                                                                     
                                                                                              
                                                                                                                     
                                                                                              
                                                                                                                 
                                                                                                         
                                                                                                                  
                                                                                                    
                                                                                                            
                                                                                                          

  FunctionalState AutoInjectedConv;                                                                                    
                                                                
                                                                                              
                                                                                                                  
                                                                                             
                                                                                                    
                                                                                                                  
                                                                                                              
                                                                                 
                                                                                                                 
                                                                                                                      
                                                              
                                                                                                                
                                                                   
                                                                                                                  
                                                                                                                        
                                                                                                                        
                                                                          

  FunctionalState QueueInjectedContext;                                                               
                                                                                              
                                                                                                                      
                                                                                   
                                                                                                                    
                                                                                
                                                                                         
                                                                                                                  
                                                                                         
                                                                                                           
                                                                                                
                                                                                            
                                                                                                                  
                                                                                                    
                                                                                                            
                                                                                                       
                                                                                                                     
                                                                                                       

  uint32_t ExternalTrigInjecConv;                                                                                
                                                              
                                                                                                                    
                                                                                    
                                                                               
                                                                                         
                                                                                                                  
                                                                                                                        
                                                                                                                        
                                                                          

  uint32_t ExternalTrigInjecConvEdge;                                                              
                                                                                                                        
                                                                                                                      
                                                            
                                                                                                                  
                                                                                                    
                                                                                                            
                                                                                                          

  FunctionalState InjecOversamplingMode;                                                                                
                                                                                                     
                                                                                                              
                                                                                                                   

  ADC_InjOversamplingTypeDef  InjecOversampling;                                            
                                                                                                                
                                                                                                             
                                                                                                              
                                                                                                                        
} ADC_InjectionConfTypeDef;

#if defined(ADC_MULTIMODE_SUPPORT)
   
                                                 
                                                                                                                       
                                         
                                                        
    
typedef struct
{
  uint32_t Mode;                                                                             
                                                                                                  

  uint32_t DMAAccessMode;                                                    
                                                                                                                        
                                                                                     
                                                                                                                     

  uint32_t TwoSamplingDelay;                                                      
                                                                                                       
                                                                              
                                                                                                                 
                                                                                                                    
} ADC_MultiModeTypeDef;
#endif                            

   
      
    

                                                                                

                                                                      
      
    

                                                                                    
      
    
                                                             
#define ADC_INJECTED_SOFTWARE_START        (LL_ADC_INJ_TRIG_SOFTWARE)                                              
                                                                    
#define ADC_EXTERNALTRIGINJEC_T1_TRGO      (LL_ADC_INJ_TRIG_EXT_TIM1_TRGO)                                         
                                                                                          
#define ADC_EXTERNALTRIGINJEC_T1_TRGO2     (LL_ADC_INJ_TRIG_EXT_TIM1_TRGO2)                                        
                                                                                           
#define ADC_EXTERNALTRIGINJEC_T1_CC4       (LL_ADC_INJ_TRIG_EXT_TIM1_CH4)                                          
                                                                                                                       
#define ADC_EXTERNALTRIGINJEC_T2_TRGO      (LL_ADC_INJ_TRIG_EXT_TIM2_TRGO)                                         
                                                                                          
#define ADC_EXTERNALTRIGINJEC_T2_CC1       (LL_ADC_INJ_TRIG_EXT_TIM2_CH1)                                          
                                                                                                                       
#define ADC_EXTERNALTRIGINJEC_T3_TRGO      (LL_ADC_INJ_TRIG_EXT_TIM3_TRGO)                                         
                                                                                          
#define ADC_EXTERNALTRIGINJEC_T3_CC1       (LL_ADC_INJ_TRIG_EXT_TIM3_CH1)                                          
                                                                                                                       
#define ADC_EXTERNALTRIGINJEC_T3_CC3       (LL_ADC_INJ_TRIG_EXT_TIM3_CH3)                                          
                                                                                                                       
#define ADC_EXTERNALTRIGINJEC_T3_CC4       (LL_ADC_INJ_TRIG_EXT_TIM3_CH4)                                          
                                                                                                                       
#define ADC_EXTERNALTRIGINJEC_T4_TRGO      (LL_ADC_INJ_TRIG_EXT_TIM4_TRGO)                                         
                                                                                          
#define ADC_EXTERNALTRIGINJEC_T6_TRGO      (LL_ADC_INJ_TRIG_EXT_TIM6_TRGO)                                         
                                                                                          
#define ADC_EXTERNALTRIGINJEC_T8_CC4       (LL_ADC_INJ_TRIG_EXT_TIM8_CH4)                                          
                                                                                                                       
#define ADC_EXTERNALTRIGINJEC_T8_TRGO      (LL_ADC_INJ_TRIG_EXT_TIM8_TRGO)                                         
                                                                                          
#define ADC_EXTERNALTRIGINJEC_T8_TRGO2     (LL_ADC_INJ_TRIG_EXT_TIM8_TRGO2)                                        
                                                                                           
#define ADC_EXTERNALTRIGINJEC_T15_TRGO     (LL_ADC_INJ_TRIG_EXT_TIM15_TRGO)                                        
                                                                                           
#define ADC_EXTERNALTRIGINJEC_EXT_IT15     (LL_ADC_INJ_TRIG_EXT_EXTI_LINE15)                                       
                                                                                                           
   
      
    

                                                                                                                    
      
    
#define ADC_EXTERNALTRIGINJECCONV_EDGE_NONE           (0x00000000UL)                                         
                                                                           
#define ADC_EXTERNALTRIGINJECCONV_EDGE_RISING         (ADC_JSQR_JEXTEN_0)                                    
                                                                                    
#define ADC_EXTERNALTRIGINJECCONV_EDGE_FALLING        (ADC_JSQR_JEXTEN_1)                                    
                                                                                     
#define ADC_EXTERNALTRIGINJECCONV_EDGE_RISINGFALLING  (ADC_JSQR_JEXTEN)                                      
                                                                                                      
   
      
    

                                                                                            
      
    
#define ADC_SINGLE_ENDED                (LL_ADC_SINGLE_ENDED)                                                       
#define ADC_DIFFERENTIAL_ENDED          (LL_ADC_DIFFERENTIAL_ENDED)                                                 
   
      
    

                                                                
      
    
#define ADC_OFFSET_NONE              (ADC_OFFSET_4 + 1U)                                                                
                                                   
#define ADC_OFFSET_1                 (LL_ADC_OFFSET_1)                                                                
                                                                                                           
                                                                               
#define ADC_OFFSET_2                 (LL_ADC_OFFSET_2)                                                                
                                                                                                           
                                                                               
#define ADC_OFFSET_3                 (LL_ADC_OFFSET_3)                                                                
                                                                                                           
                                                                               
#define ADC_OFFSET_4                 (LL_ADC_OFFSET_4)                                                                
                                                                                                           
                                                                               
   
      
    

                                                                     
      
    
#define ADC_INJECTED_RANK_1                (LL_ADC_INJ_RANK_1)                                            
#define ADC_INJECTED_RANK_2                (LL_ADC_INJ_RANK_2)                                            
#define ADC_INJECTED_RANK_3                (LL_ADC_INJ_RANK_3)                                            
#define ADC_INJECTED_RANK_4                (LL_ADC_INJ_RANK_4)                                            
   
      
    

#if defined(ADC_MULTIMODE_SUPPORT)
                                                     
      
    
#define ADC_MODE_INDEPENDENT               (LL_ADC_MULTI_INDEPENDENT)                                     
                                                                    
#define ADC_DUALMODE_REGSIMULT             (LL_ADC_MULTI_DUAL_REG_SIMULT)                                               
                                                          
#define ADC_DUALMODE_INTERL                (LL_ADC_MULTI_DUAL_REG_INTERL)                                          
                                                                       
#define ADC_DUALMODE_INJECSIMULT           (LL_ADC_MULTI_DUAL_INJ_SIMULT)                                       
                                                                   
#define ADC_DUALMODE_ALTERTRIG             (LL_ADC_MULTI_DUAL_INJ_ALTERN)                                       
                                                                                                                      
                                                       
#define ADC_DUALMODE_REGSIMULT_INJECSIMULT (LL_ADC_MULTI_DUAL_REG_SIM_INJ_SIM)                                     
                                                                                                      
#define ADC_DUALMODE_REGSIMULT_ALTERTRIG   (LL_ADC_MULTI_DUAL_REG_SIM_INJ_ALT)                                     
                                                                                                           
#define ADC_DUALMODE_REGINTERL_INJECSIMULT (LL_ADC_MULTI_DUAL_REG_INT_INJ_SIM)                                     
                                                                                                     

                                                                                                                 
      
    
#define ADC_DMAACCESSMODE_DISABLED         (0x00000000UL)                                                       
                                                         
#define ADC_DMAACCESSMODE_12_10_BITS       (ADC_CCR_MDMA_1)                                                            
                                                                                              
#define ADC_DMAACCESSMODE_8_6_BITS         (ADC_CCR_MDMA)                                                              
                                                                                            
   
      
    

                                                                                          
      
    
#define ADC_TWOSAMPLINGDELAY_1CYCLE        (LL_ADC_MULTI_TWOSMP_DELAY_1CYCLE)                                        
                                                                                
#define ADC_TWOSAMPLINGDELAY_2CYCLES       (LL_ADC_MULTI_TWOSMP_DELAY_2CYCLES)                                       
                                                                                 
#define ADC_TWOSAMPLINGDELAY_3CYCLES       (LL_ADC_MULTI_TWOSMP_DELAY_3CYCLES)                                       
                                                                                 
#define ADC_TWOSAMPLINGDELAY_4CYCLES       (LL_ADC_MULTI_TWOSMP_DELAY_4CYCLES)                                       
                                                                                 
#define ADC_TWOSAMPLINGDELAY_5CYCLES       (LL_ADC_MULTI_TWOSMP_DELAY_5CYCLES)                                       
                                                                                 
#define ADC_TWOSAMPLINGDELAY_6CYCLES       (LL_ADC_MULTI_TWOSMP_DELAY_6CYCLES)                                       
                                                                                 
#define ADC_TWOSAMPLINGDELAY_7CYCLES       (LL_ADC_MULTI_TWOSMP_DELAY_7CYCLES)                                       
                                                                                 
#define ADC_TWOSAMPLINGDELAY_8CYCLES       (LL_ADC_MULTI_TWOSMP_DELAY_8CYCLES)                                       
                                                                                 
#define ADC_TWOSAMPLINGDELAY_9CYCLES       (LL_ADC_MULTI_TWOSMP_DELAY_9CYCLES)                                       
                                                                                 
#define ADC_TWOSAMPLINGDELAY_10CYCLES      (LL_ADC_MULTI_TWOSMP_DELAY_10CYCLES)                                      
                                                                                  
#define ADC_TWOSAMPLINGDELAY_11CYCLES      (LL_ADC_MULTI_TWOSMP_DELAY_11CYCLES)                                      
                                                                                  
#define ADC_TWOSAMPLINGDELAY_12CYCLES      (LL_ADC_MULTI_TWOSMP_DELAY_12CYCLES)                                      
                                                                                  
   
      
    

   
      
    
#endif                            

                                                      
      
    
#define ADC_REGULAR_GROUP                  (LL_ADC_GROUP_REGULAR)                                              
                                                                                                     
#define ADC_INJECTED_GROUP                 (LL_ADC_GROUP_INJECTED)                                                  
                                                                                                     
#define ADC_REGULAR_INJECTED_GROUP         (LL_ADC_GROUP_REGULAR_INJECTED)                                             
   
      
    

                                              
      
    
#if defined(ADC_CFGR_DFSDMCFG) &&defined(DFSDM1_Channel0)
#define ADC_CFGR_FIELDS    (ADC_CFGR_AWD1CH  | ADC_CFGR_JAUTO    | ADC_CFGR_JAWD1EN |\
                            ADC_CFGR_AWD1EN  | ADC_CFGR_AWD1SGL  | ADC_CFGR_JQM     |\
                            ADC_CFGR_JDISCEN | ADC_CFGR_DISCNUM  | ADC_CFGR_DISCEN  |\
                            ADC_CFGR_AUTDLY  | ADC_CFGR_CONT     | ADC_CFGR_OVRMOD  |\
                            ADC_CFGR_EXTEN   | ADC_CFGR_EXTSEL   | ADC_CFGR_ALIGN   |\
                            ADC_CFGR_RES     | ADC_CFGR_DFSDMCFG | ADC_CFGR_DMACFG  | ADC_CFGR_DMAEN)
#else
#define ADC_CFGR_FIELDS    (ADC_CFGR_AWD1CH  | ADC_CFGR_JAUTO   | ADC_CFGR_JAWD1EN |\
                            ADC_CFGR_AWD1EN  | ADC_CFGR_AWD1SGL | ADC_CFGR_JQM     |\
                            ADC_CFGR_JDISCEN | ADC_CFGR_DISCNUM | ADC_CFGR_DISCEN  |\
                            ADC_CFGR_AUTDLY  | ADC_CFGR_CONT    | ADC_CFGR_OVRMOD  |\
                            ADC_CFGR_EXTEN   | ADC_CFGR_EXTSEL  | ADC_CFGR_ALIGN   |\
                            ADC_CFGR_RES     | ADC_CFGR_DMACFG  | ADC_CFGR_DMAEN   )
#endif                        
   
      
    

                                                
      
    
#if defined(ADC_SMPR1_SMPPLUS)
#define ADC_SMPR1_FIELDS    (ADC_SMPR1_SMP9 | ADC_SMPR1_SMP8 | ADC_SMPR1_SMP7 |\
                             ADC_SMPR1_SMP6 | ADC_SMPR1_SMP5 | ADC_SMPR1_SMP4 |\
                             ADC_SMPR1_SMP3 | ADC_SMPR1_SMP2 | ADC_SMPR1_SMP1 |\
                             ADC_SMPR1_SMP0 | ADC_SMPR1_SMPPLUS)
#else
#define ADC_SMPR1_FIELDS    (ADC_SMPR1_SMP9 | ADC_SMPR1_SMP8 | ADC_SMPR1_SMP7 |\
                             ADC_SMPR1_SMP6 | ADC_SMPR1_SMP5 | ADC_SMPR1_SMP4 |\
                             ADC_SMPR1_SMP3 | ADC_SMPR1_SMP2 | ADC_SMPR1_SMP1 |\
                             ADC_SMPR1_SMP0)
#endif                        
   
      
    

                                                    
      
    
                                                                       
                                                 
#if defined(ADC_CFGR_DFSDMCFG) &&defined(DFSDM1_Channel0)
#define ADC_CFGR_FIELDS_2  ((ADC_CFGR_DMACFG | ADC_CFGR_AUTDLY | ADC_CFGR_DFSDMCFG))
#else
#define ADC_CFGR_FIELDS_2  ((ADC_CFGR_DMACFG | ADC_CFGR_AUTDLY))
#endif                        
   
      
    

#if defined(ADC_CFGR_DFSDMCFG) &&defined(DFSDM1_Channel0)
                                                                                                     
      
    
#define ADC_DFSDM_MODE_DISABLE             (0x00000000UL)                                                             
                                                       
#define ADC_DFSDM_MODE_ENABLE              (LL_ADC_REG_DFSDM_TRANSFER_ENABLE)                                         
                                                                                                                      
                                                                                               
                                                                                                       
   
      
    
#endif                        

   
      
    

                                                                                

#if defined(ADC_MULTIMODE_SUPPORT)
                                                               
      
    

                                                                                 
                                                                             
                                                                      
                                                               
                                                                       
                                                       
                                                                             
                                                                    
                                                                     
                                                                    
                            
                                 
                
    
#define ADC_FORCE_MODE_INDEPENDENT(__HANDLE__)                                 \
  LL_ADC_SetMultimode(__LL_ADC_COMMON_INSTANCE((__HANDLE__)->Instance), LL_ADC_MULTI_INDEPENDENT)

   
      
    
#endif                            

                                                                                

                                                                                 
      
    
                                                                                
                                                                                

   
                                                                         
                               
                                 
                                                             
    
#define ADC_IS_SOFTWARE_START_INJECTED(__HANDLE__)                             \
  (((__HANDLE__)->Instance->JSQR & ADC_JSQR_JEXTEN) == 0UL)

   
                                                                         
                                 
                                                                              
    
#define ADC_IS_CONVERSION_ONGOING_REGULAR_INJECTED(__HANDLE__)                       \
  (( (((__HANDLE__)->Instance->CR) & (ADC_CR_ADSTART | ADC_CR_JADSTART)) == 0UL \
   ) ? RESET : SET)

   
                                                             
                                 
                                                                                       
    
#define ADC_IS_CONVERSION_ONGOING_INJECTED(__HANDLE__)                         \
  (LL_ADC_INJ_IsConversionOngoing((__HANDLE__)->Instance))

   
                                                   
                                 
                                                                                 
                                                           
    
#if defined (STM32L471xx) || defined (STM32L475xx) || defined (STM32L476xx) || defined (STM32L485xx) || defined (STM32L486xx) || defined (STM32L496xx) || defined (STM32L4A6xx)
#define ADC_IS_INDEPENDENT(__HANDLE__)    \
  ( ( ( ((__HANDLE__)->Instance) == ADC3) \
    )?                                    \
     SET                                  \
     :                                    \
     RESET                                \
  )
#elif defined (STM32L431xx) || defined (STM32L432xx) || defined (STM32L433xx) || defined (STM32L442xx) || defined (STM32L443xx) || defined (STM32L451xx) || defined (STM32L452xx) || defined (STM32L462xx) || defined (STM32L4R5xx) || defined (STM32L4R7xx) || defined (STM32L4R9xx) || defined (STM32L4S5xx) || defined (STM32L4S7xx) || defined (STM32L4S9xx)
#define ADC_IS_INDEPENDENT(__HANDLE__)   (SET)
#elif defined (STM32L412xx) || defined (STM32L422xx) || defined (STM32L4P5xx) || defined (STM32L4Q5xx)
#define ADC_IS_INDEPENDENT(__HANDLE__)   (RESET)
#endif                                                                                                       
                                                                                    

   
                                                  
                                        
                                  
                
    
#define ADC_JSQR_RK(__CHANNELNB__, __RANKNB__) \
  ((((__CHANNELNB__) & ADC_CHANNEL_ID_NUMBER_MASK) >> ADC_CHANNEL_ID_NUMBER_BITOFFSET_POS) \
   << ((__RANKNB__) & ADC_INJ_RANK_ID_JSQR_MASK))

   
                                               
                                                                     
                
    
#define ADC_CFGR_INJECT_CONTEXT_QUEUE(__INJECT_CONTEXT_QUEUE_MODE__) \
  ((__INJECT_CONTEXT_QUEUE_MODE__) << ADC_CFGR_JQM_Pos)

   
                                                                         
                                                                     
                
    
#define ADC_CFGR_INJECT_DISCCONTINUOUS(__INJECT_DISCONTINUOUS_MODE__) \
  ((__INJECT_DISCONTINUOUS_MODE__) <<  ADC_CFGR_JDISCEN_Pos)

   
                                                                        
                                                                 
                
    
#define ADC_CFGR_REG_DISCONTINUOUS(__REG_DISCONTINUOUS_MODE__) \
  ((__REG_DISCONTINUOUS_MODE__) << ADC_CFGR_DISCEN_Pos)

   
                                                                               
                                                                          
                
    
#define ADC_CFGR_DISCONTINUOUS_NUM(__NBR_DISCONTINUOUS_CONV__) \
  (((__NBR_DISCONTINUOUS_CONV__) - 1UL) << ADC_CFGR_DISCNUM_Pos)

   
                                             
                                                         
                
    
#define ADC_CFGR_AUTOWAIT(__AUTOWAIT__) ((__AUTOWAIT__) << ADC_CFGR_AUTDLY_Pos)

   
                                                    
                                               
                
    
#define ADC_CFGR_CONTINUOUS(__CONTINUOUS_MODE__) ((__CONTINUOUS_MODE__) << ADC_CFGR_CONT_Pos)

   
                                                    
                                                           
                
    
#define ADC_CFGR_DMACONTREQ(__DMACONTREQ_MODE__) ((__DMACONTREQ_MODE__) <<  ADC_CFGR_DMACFG_Pos)

   
                                                                  
                                   
                
    
#define ADC_OFR_CHANNEL(__CHANNEL__) ((__CHANNEL__) << ADC_OFR1_OFFSET1_CH_Pos)

   
                                                                                  
                                   
                
    
#define ADC_DIFSEL_CHANNEL(__CHANNEL__) (1UL << (__CHANNEL__))

   
                                                                                                 
                                                           
                
    
#define ADC_CALFACT_DIFF_SET(__CALIBRATION_FACTOR__) \
  (((__CALIBRATION_FACTOR__) & (ADC_CALFACT_CALFACT_D_Pos >> ADC_CALFACT_CALFACT_D_Pos) ) << ADC_CALFACT_CALFACT_D_Pos)

   
                                                                                             
                                                           
                
    
#define ADC_CALFACT_DIFF_GET(__CALIBRATION_FACTOR__) ((__CALIBRATION_FACTOR__) >> ADC_CALFACT_CALFACT_D_Pos)

   
                                                                                       
                                         
                
    
#define ADC_TRX_HIGHTHRESHOLD(__THRESHOLD__) ((__THRESHOLD__) << 16UL)

#if defined(ADC_MULTIMODE_SUPPORT)
   
                                                                      
                                                           
                
    
#define ADC_CCR_MULTI_DMACONTREQ(__DMACONTREQ_MODE__) ((__DMACONTREQ_MODE__) << ADC_CCR_DMACFG_Pos)
#endif                            

   
                                                                        
                                                                                       
                                            
                                                                
                                                               
                                                               
                                                                                    
                                
                                         
                
    
#define ADC_OFFSET_SHIFT_RESOLUTION(__HANDLE__, __OFFSET__) \
  ((__OFFSET__) << ((((__HANDLE__)->Instance->CFGR & ADC_CFGR_RES) >> 3UL) * 2UL))

   
                                                                                
                                                                                           
                                           
                                                               
                                                              
                                                              
                                                                                   
                                
                                            
                
    
#define ADC_AWD1THRESHOLD_SHIFT_RESOLUTION(__HANDLE__, __THRESHOLD__) \
  ((__THRESHOLD__) << ((((__HANDLE__)->Instance->CFGR & ADC_CFGR_RES) >> 3UL) * 2UL))

   
                                                                                         
                                                       
                                                                                          
                                                                                          
                                          
                                                                                       
                                
                                            
                
    
#define ADC_AWD23THRESHOLD_SHIFT_RESOLUTION(__HANDLE__, __THRESHOLD__)                                       \
  ((((__HANDLE__)->Instance->CFGR & ADC_CFGR_RES) != (ADC_CFGR_RES_1 | ADC_CFGR_RES_0))                    ? \
   ((__THRESHOLD__) >> ((4UL - ((((__HANDLE__)->Instance->CFGR & ADC_CFGR_RES) >> 3UL) * 2UL)) & 0x1FUL)) : \
   ((__THRESHOLD__) << 2UL)                                                                                 \
  )

   
                                         
                                 
                
    
#if defined(ADC_MULTIMODE_SUPPORT)
#define ADC_CLEAR_COMMON_CONTROL_REGISTER(__HANDLE__) CLEAR_BIT(__LL_ADC_COMMON_INSTANCE((__HANDLE__)->Instance)->CCR, \
                                                                ADC_CCR_CKMODE | \
                                                                ADC_CCR_PRESC  | \
                                                                ADC_CCR_VBATEN | \
                                                                ADC_CCR_TSEN   | \
                                                                ADC_CCR_VREFEN | \
                                                                ADC_CCR_MDMA   | \
                                                                ADC_CCR_DMACFG | \
                                                                ADC_CCR_DELAY  | \
                                                                ADC_CCR_DUAL)
#else
#define ADC_CLEAR_COMMON_CONTROL_REGISTER(__HANDLE__) CLEAR_BIT(__LL_ADC_COMMON_INSTANCE((__HANDLE__)->Instance)->CCR, \
                                                                ADC_CCR_CKMODE | \
                                                                ADC_CCR_PRESC  | \
                                                                ADC_CCR_VBATEN | \
                                                                ADC_CCR_TSEN   | \
                                                                ADC_CCR_VREFEN)

#endif                            

#if defined (STM32L412xx) || defined (STM32L422xx) || defined (STM32L471xx) || defined (STM32L475xx) || defined (STM32L476xx) || defined (STM32L485xx) || defined (STM32L486xx) || defined (STM32L496xx) || defined (STM32L4A6xx) || defined (STM32L4P5xx) || defined (STM32L4Q5xx)
   
                                                                             
                                               
                                             
                                                                                                               
                      
                
    
#define ADC_MULTI_SLAVE(__HANDLE_MASTER__, __HANDLE_SLAVE__)             \
  ( (((__HANDLE_MASTER__)->Instance == ADC1)) ? \
    ((__HANDLE_SLAVE__)->Instance = ADC2) : ((__HANDLE_SLAVE__)->Instance = NULL) )
#endif                                                                                                       
                                                                                    


   
                                                                       
                                 
                                                                          
    
#if defined (STM32L412xx) || defined (STM32L422xx) || defined (STM32L431xx) || defined (STM32L432xx) || defined (STM32L433xx) || defined (STM32L442xx) || defined (STM32L443xx) || defined (STM32L451xx) || defined (STM32L452xx) || defined (STM32L462xx) || defined (STM32L4P5xx) || defined (STM32L4Q5xx) || defined (STM32L4R5xx) || defined (STM32L4R7xx) || defined (STM32L4R9xx) || defined (STM32L4S5xx) || defined (STM32L4S7xx) || defined (STM32L4S9xx)
                                                                                
#define ADC_TEMPERATURE_SENSOR_INSTANCE(__HANDLE__)  (((__HANDLE__)->Instance) == ADC1)
#elif defined (STM32L471xx) || defined (STM32L475xx) || defined (STM32L476xx) || defined (STM32L485xx) || defined (STM32L486xx) || defined (STM32L496xx) || defined (STM32L4A6xx)
                                                                                         
#define ADC_TEMPERATURE_SENSOR_INSTANCE(__HANDLE__)  ((((__HANDLE__)->Instance) == ADC1)\
                                                      || (((__HANDLE__)->Instance) == ADC3))
#endif                                                                                                       
                                                                                                             
                                                                                                             
                                                                                                             
                                                           

   
                                                                         
                                 
                                                                          
    
#if defined (STM32L412xx) || defined (STM32L422xx) || defined (STM32L431xx) || defined (STM32L432xx) || defined (STM32L433xx) || defined (STM32L442xx) || defined (STM32L443xx) || defined (STM32L451xx) || defined (STM32L452xx) || defined (STM32L462xx) || defined (STM32L4P5xx) || defined (STM32L4Q5xx) || defined (STM32L4R5xx) || defined (STM32L4R7xx) || defined (STM32L4R9xx) || defined (STM32L4S5xx) || defined (STM32L4S7xx) || defined (STM32L4S9xx)
                                                                             
#define ADC_BATTERY_VOLTAGE_INSTANCE(__HANDLE__)  (((__HANDLE__)->Instance) == ADC1)
#elif defined (STM32L471xx) || defined (STM32L475xx) || defined (STM32L476xx) || defined (STM32L485xx) || defined (STM32L486xx) || defined (STM32L496xx) || defined (STM32L4A6xx)
                                                                                      
#define ADC_BATTERY_VOLTAGE_INSTANCE(__HANDLE__)  ((((__HANDLE__)->Instance) == ADC1)\
                                                   || (((__HANDLE__)->Instance) == ADC3))
#endif                                                                                                       
                                                                                                             
                                                                                                             
                                                                                                             
                                                           

   
                                                                                       
                                 
                                                                          
    
                                                                                                
#define ADC_VREFINT_INSTANCE(__HANDLE__)  (((__HANDLE__)->Instance) == ADC1)

   
                                                                     
                                                       
                                                                                                       
                                                      
    
#define IS_ADC_INJECTED_NB_CONV(__LENGTH__) (((__LENGTH__) >= (1U)) && ((__LENGTH__) <= (4U)))

   
                                                                 
                                                           
                                                                                                                     
    
#define IS_ADC_CALFACT(__CALIBRATION_FACTOR__) ((__CALIBRATION_FACTOR__) <= (0x7FU))


   
                                          
                                 
                                              
                                                                        
    
#if defined (STM32L431xx) || defined (STM32L432xx) || defined (STM32L433xx) || defined (STM32L442xx) || defined (STM32L443xx) || defined (STM32L451xx) || defined (STM32L452xx) || defined (STM32L462xx) || defined (STM32L4R5xx) || defined (STM32L4R7xx) || defined (STM32L4R9xx) || defined (STM32L4S5xx) || defined (STM32L4S7xx) || defined (STM32L4S9xx)
#define IS_ADC_CHANNEL(__HANDLE__, __CHANNEL__) ((((__HANDLE__)->Instance) == ADC1)  && \
                                                 (((__CHANNEL__) == ADC_CHANNEL_1)           || \
                                                  ((__CHANNEL__) == ADC_CHANNEL_2)           || \
                                                  ((__CHANNEL__) == ADC_CHANNEL_3)           || \
                                                  ((__CHANNEL__) == ADC_CHANNEL_4)           || \
                                                  ((__CHANNEL__) == ADC_CHANNEL_5)           || \
                                                  ((__CHANNEL__) == ADC_CHANNEL_6)           || \
                                                  ((__CHANNEL__) == ADC_CHANNEL_7)           || \
                                                  ((__CHANNEL__) == ADC_CHANNEL_8)           || \
                                                  ((__CHANNEL__) == ADC_CHANNEL_9)           || \
                                                  ((__CHANNEL__) == ADC_CHANNEL_10)          || \
                                                  ((__CHANNEL__) == ADC_CHANNEL_11)          || \
                                                  ((__CHANNEL__) == ADC_CHANNEL_12)          || \
                                                  ((__CHANNEL__) == ADC_CHANNEL_13)          || \
                                                  ((__CHANNEL__) == ADC_CHANNEL_14)          || \
                                                  ((__CHANNEL__) == ADC_CHANNEL_15)          || \
                                                  ((__CHANNEL__) == ADC_CHANNEL_16)          || \
                                                  ((__CHANNEL__) == ADC_CHANNEL_17)          || \
                                                  ((__CHANNEL__) == ADC_CHANNEL_18)          || \
                                                  ((__CHANNEL__) == ADC_CHANNEL_VREFINT)     || \
                                                  ((__CHANNEL__) == ADC_CHANNEL_TEMPSENSOR)  || \
                                                  ((__CHANNEL__) == ADC_CHANNEL_VBAT)        || \
                                                  ((__CHANNEL__) == ADC_CHANNEL_DAC1CH1)     || \
                                                  ((__CHANNEL__) == ADC_CHANNEL_DAC1CH2)))
#elif defined (STM32L412xx) || defined (STM32L422xx)
#define IS_ADC_CHANNEL(__HANDLE__, __CHANNEL__)  (((((__HANDLE__)->Instance) == ADC1)  && \
                                                   (((__CHANNEL__) == ADC_CHANNEL_1)           || \
                                                    ((__CHANNEL__) == ADC_CHANNEL_2)           || \
                                                    ((__CHANNEL__) == ADC_CHANNEL_3)           || \
                                                    ((__CHANNEL__) == ADC_CHANNEL_4)           || \
                                                    ((__CHANNEL__) == ADC_CHANNEL_5)           || \
                                                    ((__CHANNEL__) == ADC_CHANNEL_6)           || \
                                                    ((__CHANNEL__) == ADC_CHANNEL_7)           || \
                                                    ((__CHANNEL__) == ADC_CHANNEL_8)           || \
                                                    ((__CHANNEL__) == ADC_CHANNEL_9)           || \
                                                    ((__CHANNEL__) == ADC_CHANNEL_10)          || \
                                                    ((__CHANNEL__) == ADC_CHANNEL_11)          || \
                                                    ((__CHANNEL__) == ADC_CHANNEL_12)          || \
                                                    ((__CHANNEL__) == ADC_CHANNEL_13)          || \
                                                    ((__CHANNEL__) == ADC_CHANNEL_14)          || \
                                                    ((__CHANNEL__) == ADC_CHANNEL_15)          || \
                                                    ((__CHANNEL__) == ADC_CHANNEL_16)          || \
                                                    ((__CHANNEL__) == ADC_CHANNEL_VREFINT)     || \
                                                    ((__CHANNEL__) == ADC_CHANNEL_TEMPSENSOR)  || \
                                                    ((__CHANNEL__) == ADC_CHANNEL_VBAT)))      || \
                                                  ((((__HANDLE__)->Instance) == ADC2)  && \
                                                   (((__CHANNEL__) == ADC_CHANNEL_1)           || \
                                                    ((__CHANNEL__) == ADC_CHANNEL_2)           || \
                                                    ((__CHANNEL__) == ADC_CHANNEL_3)           || \
                                                    ((__CHANNEL__) == ADC_CHANNEL_4)           || \
                                                    ((__CHANNEL__) == ADC_CHANNEL_7)           || \
                                                    ((__CHANNEL__) == ADC_CHANNEL_8)           || \
                                                    ((__CHANNEL__) == ADC_CHANNEL_9)           || \
                                                    ((__CHANNEL__) == ADC_CHANNEL_10)          || \
                                                    ((__CHANNEL__) == ADC_CHANNEL_11)          || \
                                                    ((__CHANNEL__) == ADC_CHANNEL_12)          || \
                                                    ((__CHANNEL__) == ADC_CHANNEL_13)          || \
                                                    ((__CHANNEL__) == ADC_CHANNEL_14)          || \
                                                    ((__CHANNEL__) == ADC_CHANNEL_15)          || \
                                                    ((__CHANNEL__) == ADC_CHANNEL_16)  )))
#elif defined (STM32L4P5xx) || defined (STM32L4Q5xx)
#define IS_ADC_CHANNEL(__HANDLE__, __CHANNEL__)  (((((__HANDLE__)->Instance) == ADC1)  && \
                                                   (((__CHANNEL__) == ADC_CHANNEL_1)           || \
                                                    ((__CHANNEL__) == ADC_CHANNEL_2)           || \
                                                    ((__CHANNEL__) == ADC_CHANNEL_3)           || \
                                                    ((__CHANNEL__) == ADC_CHANNEL_4)           || \
                                                    ((__CHANNEL__) == ADC_CHANNEL_5)           || \
                                                    ((__CHANNEL__) == ADC_CHANNEL_6)           || \
                                                    ((__CHANNEL__) == ADC_CHANNEL_7)           || \
                                                    ((__CHANNEL__) == ADC_CHANNEL_8)           || \
                                                    ((__CHANNEL__) == ADC_CHANNEL_9)           || \
                                                    ((__CHANNEL__) == ADC_CHANNEL_10)          || \
                                                    ((__CHANNEL__) == ADC_CHANNEL_11)          || \
                                                    ((__CHANNEL__) == ADC_CHANNEL_12)          || \
                                                    ((__CHANNEL__) == ADC_CHANNEL_13)          || \
                                                    ((__CHANNEL__) == ADC_CHANNEL_14)          || \
                                                    ((__CHANNEL__) == ADC_CHANNEL_15)          || \
                                                    ((__CHANNEL__) == ADC_CHANNEL_16)          || \
                                                    ((__CHANNEL__) == ADC_CHANNEL_17)          || \
                                                    ((__CHANNEL__) == ADC_CHANNEL_18)          || \
                                                    ((__CHANNEL__) == ADC_CHANNEL_VREFINT)     || \
                                                    ((__CHANNEL__) == ADC_CHANNEL_TEMPSENSOR)  || \
                                                    ((__CHANNEL__) == ADC_CHANNEL_VBAT)))      || \
                                                  ((((__HANDLE__)->Instance) == ADC2)  && \
                                                   (((__CHANNEL__) == ADC_CHANNEL_1)           || \
                                                    ((__CHANNEL__) == ADC_CHANNEL_2)           || \
                                                    ((__CHANNEL__) == ADC_CHANNEL_3)           || \
                                                    ((__CHANNEL__) == ADC_CHANNEL_4)           || \
                                                    ((__CHANNEL__) == ADC_CHANNEL_5)           || \
                                                    ((__CHANNEL__) == ADC_CHANNEL_6)           || \
                                                    ((__CHANNEL__) == ADC_CHANNEL_7)           || \
                                                    ((__CHANNEL__) == ADC_CHANNEL_8)           || \
                                                    ((__CHANNEL__) == ADC_CHANNEL_9)           || \
                                                    ((__CHANNEL__) == ADC_CHANNEL_10)          || \
                                                    ((__CHANNEL__) == ADC_CHANNEL_11)          || \
                                                    ((__CHANNEL__) == ADC_CHANNEL_12)          || \
                                                    ((__CHANNEL__) == ADC_CHANNEL_13)          || \
                                                    ((__CHANNEL__) == ADC_CHANNEL_14)          || \
                                                    ((__CHANNEL__) == ADC_CHANNEL_15)          || \
                                                    ((__CHANNEL__) == ADC_CHANNEL_16)          || \
                                                    ((__CHANNEL__) == ADC_CHANNEL_17)          || \
                                                    ((__CHANNEL__) == ADC_CHANNEL_18)          || \
                                                    ((__CHANNEL__) == ADC_CHANNEL_DAC1CH1_ADC2)|| \
                                                    ((__CHANNEL__) == ADC_CHANNEL_DAC1CH2_ADC2)  )))
#elif defined (STM32L471xx) || defined (STM32L475xx) || defined (STM32L476xx) || defined (STM32L485xx) || defined (STM32L486xx) || defined (STM32L496xx) || defined (STM32L4A6xx)
#define IS_ADC_CHANNEL(__HANDLE__, __CHANNEL__)  (((((__HANDLE__)->Instance) == ADC1)  && \
                                                   (((__CHANNEL__) == ADC_CHANNEL_1)           || \
                                                    ((__CHANNEL__) == ADC_CHANNEL_2)           || \
                                                    ((__CHANNEL__) == ADC_CHANNEL_3)           || \
                                                    ((__CHANNEL__) == ADC_CHANNEL_4)           || \
                                                    ((__CHANNEL__) == ADC_CHANNEL_5)           || \
                                                    ((__CHANNEL__) == ADC_CHANNEL_6)           || \
                                                    ((__CHANNEL__) == ADC_CHANNEL_7)           || \
                                                    ((__CHANNEL__) == ADC_CHANNEL_8)           || \
                                                    ((__CHANNEL__) == ADC_CHANNEL_9)           || \
                                                    ((__CHANNEL__) == ADC_CHANNEL_10)          || \
                                                    ((__CHANNEL__) == ADC_CHANNEL_11)          || \
                                                    ((__CHANNEL__) == ADC_CHANNEL_12)          || \
                                                    ((__CHANNEL__) == ADC_CHANNEL_13)          || \
                                                    ((__CHANNEL__) == ADC_CHANNEL_14)          || \
                                                    ((__CHANNEL__) == ADC_CHANNEL_15)          || \
                                                    ((__CHANNEL__) == ADC_CHANNEL_16)          || \
                                                    ((__CHANNEL__) == ADC_CHANNEL_VREFINT)     || \
                                                    ((__CHANNEL__) == ADC_CHANNEL_TEMPSENSOR)  || \
                                                    ((__CHANNEL__) == ADC_CHANNEL_VBAT)))      || \
                                                  ((((__HANDLE__)->Instance) == ADC2)  && \
                                                   (((__CHANNEL__) == ADC_CHANNEL_1)           || \
                                                    ((__CHANNEL__) == ADC_CHANNEL_2)           || \
                                                    ((__CHANNEL__) == ADC_CHANNEL_3)           || \
                                                    ((__CHANNEL__) == ADC_CHANNEL_4)           || \
                                                    ((__CHANNEL__) == ADC_CHANNEL_5)           || \
                                                    ((__CHANNEL__) == ADC_CHANNEL_6)           || \
                                                    ((__CHANNEL__) == ADC_CHANNEL_7)           || \
                                                    ((__CHANNEL__) == ADC_CHANNEL_8)           || \
                                                    ((__CHANNEL__) == ADC_CHANNEL_9)           || \
                                                    ((__CHANNEL__) == ADC_CHANNEL_10)          || \
                                                    ((__CHANNEL__) == ADC_CHANNEL_11)          || \
                                                    ((__CHANNEL__) == ADC_CHANNEL_12)          || \
                                                    ((__CHANNEL__) == ADC_CHANNEL_13)          || \
                                                    ((__CHANNEL__) == ADC_CHANNEL_14)          || \
                                                    ((__CHANNEL__) == ADC_CHANNEL_15)          || \
                                                    ((__CHANNEL__) == ADC_CHANNEL_16)          || \
                                                    ((__CHANNEL__) == ADC_CHANNEL_17)          || \
                                                    ((__CHANNEL__) == ADC_CHANNEL_18)          || \
                                                    ((__CHANNEL__) == ADC_CHANNEL_DAC1CH1_ADC2)   || \
                                                    ((__CHANNEL__) == ADC_CHANNEL_DAC1CH2_ADC2))) || \
                                                  ((((__HANDLE__)->Instance) == ADC3)  && \
                                                   (((__CHANNEL__) == ADC_CHANNEL_1)           || \
                                                    ((__CHANNEL__) == ADC_CHANNEL_2)           || \
                                                    ((__CHANNEL__) == ADC_CHANNEL_3)           || \
                                                    ((__CHANNEL__) == ADC_CHANNEL_4)           || \
                                                    ((__CHANNEL__) == ADC_CHANNEL_6)           || \
                                                    ((__CHANNEL__) == ADC_CHANNEL_7)           || \
                                                    ((__CHANNEL__) == ADC_CHANNEL_8)           || \
                                                    ((__CHANNEL__) == ADC_CHANNEL_9)           || \
                                                    ((__CHANNEL__) == ADC_CHANNEL_10)          || \
                                                    ((__CHANNEL__) == ADC_CHANNEL_11)          || \
                                                    ((__CHANNEL__) == ADC_CHANNEL_12)          || \
                                                    ((__CHANNEL__) == ADC_CHANNEL_13)          || \
                                                    ((__CHANNEL__) == ADC_CHANNEL_14)          || \
                                                    ((__CHANNEL__) == ADC_CHANNEL_15)          || \
                                                    ((__CHANNEL__) == ADC_CHANNEL_TEMPSENSOR)  || \
                                                    ((__CHANNEL__) == ADC_CHANNEL_VBAT)        || \
                                                    ((__CHANNEL__) == ADC_CHANNEL_DAC1CH1_ADC3) || \
                                                    ((__CHANNEL__) == ADC_CHANNEL_DAC1CH2_ADC3)  )))
#endif                                                                                                       
                                                                                                             
                                                                                                             
                                                           

   
                                                               
                                 
                                              
                                                                        
    
#if defined (STM32L412xx) || defined (STM32L422xx) || defined (STM32L431xx) || defined (STM32L432xx) || defined (STM32L433xx) || defined (STM32L442xx) || defined (STM32L443xx) || defined (STM32L451xx) || defined (STM32L452xx) || defined (STM32L462xx) || defined (STM32L4P5xx) || defined (STM32L4Q5xx) || defined (STM32L4R5xx) || defined (STM32L4R7xx) || defined (STM32L4R9xx) || defined (STM32L4S5xx) || defined (STM32L4S7xx) || defined (STM32L4S9xx)
#define IS_ADC_DIFF_CHANNEL(__HANDLE__, __CHANNEL__) (((__CHANNEL__) == ADC_CHANNEL_1)      || \
                                                      ((__CHANNEL__) == ADC_CHANNEL_2)      || \
                                                      ((__CHANNEL__) == ADC_CHANNEL_3)      || \
                                                      ((__CHANNEL__) == ADC_CHANNEL_4)      || \
                                                      ((__CHANNEL__) == ADC_CHANNEL_5)      || \
                                                      ((__CHANNEL__) == ADC_CHANNEL_6)      || \
                                                      ((__CHANNEL__) == ADC_CHANNEL_7)      || \
                                                      ((__CHANNEL__) == ADC_CHANNEL_8)      || \
                                                      ((__CHANNEL__) == ADC_CHANNEL_9)      || \
                                                      ((__CHANNEL__) == ADC_CHANNEL_10)     || \
                                                      ((__CHANNEL__) == ADC_CHANNEL_11)     || \
                                                      ((__CHANNEL__) == ADC_CHANNEL_12)     || \
                                                      ((__CHANNEL__) == ADC_CHANNEL_13)     || \
                                                      ((__CHANNEL__) == ADC_CHANNEL_14)     || \
                                                      ((__CHANNEL__) == ADC_CHANNEL_15)       )
#elif defined (STM32L471xx) || defined (STM32L475xx) || defined (STM32L476xx) || defined (STM32L485xx) || defined (STM32L486xx) || defined (STM32L496xx) || defined (STM32L4A6xx)
                                                                          
                                                                                 
                                                                            
                                                                                 
#define IS_ADC_DIFF_CHANNEL(__HANDLE__, __CHANNEL__)  ((((((__HANDLE__)->Instance) == ADC1)   || \
                                                         (((__HANDLE__)->Instance) == ADC2))  && \
                                                        (((__CHANNEL__) == ADC_CHANNEL_1)    || \
                                                         ((__CHANNEL__) == ADC_CHANNEL_2)    || \
                                                         ((__CHANNEL__) == ADC_CHANNEL_3)    || \
                                                         ((__CHANNEL__) == ADC_CHANNEL_4)    || \
                                                         ((__CHANNEL__) == ADC_CHANNEL_5)    || \
                                                         ((__CHANNEL__) == ADC_CHANNEL_6)    || \
                                                         ((__CHANNEL__) == ADC_CHANNEL_7)    || \
                                                         ((__CHANNEL__) == ADC_CHANNEL_8)    || \
                                                         ((__CHANNEL__) == ADC_CHANNEL_9)    || \
                                                         ((__CHANNEL__) == ADC_CHANNEL_10)   || \
                                                         ((__CHANNEL__) == ADC_CHANNEL_11)   || \
                                                         ((__CHANNEL__) == ADC_CHANNEL_12)   || \
                                                         ((__CHANNEL__) == ADC_CHANNEL_13)   || \
                                                         ((__CHANNEL__) == ADC_CHANNEL_14)   || \
                                                         ((__CHANNEL__) == ADC_CHANNEL_15))) || \
                                                       ((((__HANDLE__)->Instance) == ADC3)  && \
                                                        (((__CHANNEL__) == ADC_CHANNEL_1)   || \
                                                         ((__CHANNEL__) == ADC_CHANNEL_2)   || \
                                                         ((__CHANNEL__) == ADC_CHANNEL_3)   || \
                                                         ((__CHANNEL__) == ADC_CHANNEL_6)   || \
                                                         ((__CHANNEL__) == ADC_CHANNEL_7)   || \
                                                         ((__CHANNEL__) == ADC_CHANNEL_8)   || \
                                                         ((__CHANNEL__) == ADC_CHANNEL_9)   || \
                                                         ((__CHANNEL__) == ADC_CHANNEL_10)  || \
                                                         ((__CHANNEL__) == ADC_CHANNEL_11)  || \
                                                         ((__CHANNEL__) == ADC_CHANNEL_12)   )))
#endif                                                                                                       
                                                                                                             
                                                                                                             
                                                                                                             
                                                           

   
                                                                          
                                                    
                                                                            
    
#define IS_ADC_SINGLE_DIFFERENTIAL(__SING_DIFF__) (((__SING_DIFF__) == ADC_SINGLE_ENDED)      || \
                                                   ((__SING_DIFF__) == ADC_DIFFERENTIAL_ENDED)  )

   
                                                    
                                                   
                                                                                    
    
#define IS_ADC_OFFSET_NUMBER(__OFFSET_NUMBER__) (((__OFFSET_NUMBER__) == ADC_OFFSET_NONE) || \
                                                 ((__OFFSET_NUMBER__) == ADC_OFFSET_1)    || \
                                                 ((__OFFSET_NUMBER__) == ADC_OFFSET_2)    || \
                                                 ((__OFFSET_NUMBER__) == ADC_OFFSET_3)    || \
                                                 ((__OFFSET_NUMBER__) == ADC_OFFSET_4)      )

   
                                                   
                                                       
                                                                        
    
#define IS_ADC_INJECTED_RANK(__CHANNEL__) (((__CHANNEL__) == ADC_INJECTED_RANK_1) || \
                                           ((__CHANNEL__) == ADC_INJECTED_RANK_2) || \
                                           ((__CHANNEL__) == ADC_INJECTED_RANK_3) || \
                                           ((__CHANNEL__) == ADC_INJECTED_RANK_4)   )

   
                                                                
                                 
                                                                            
                                                                                
    
#define IS_ADC_EXTTRIGINJEC(__HANDLE__, __INJTRIG__) (((__INJTRIG__) == ADC_EXTERNALTRIGINJEC_T1_TRGO)     || \
                                                      ((__INJTRIG__) == ADC_EXTERNALTRIGINJEC_T1_CC4)      || \
                                                      ((__INJTRIG__) == ADC_EXTERNALTRIGINJEC_T2_TRGO)     || \
                                                      ((__INJTRIG__) == ADC_EXTERNALTRIGINJEC_T2_CC1)      || \
                                                      ((__INJTRIG__) == ADC_EXTERNALTRIGINJEC_T3_CC4)      || \
                                                      ((__INJTRIG__) == ADC_EXTERNALTRIGINJEC_T4_TRGO)     || \
                                                      ((__INJTRIG__) == ADC_EXTERNALTRIGINJEC_EXT_IT15)    || \
                                                      ((__INJTRIG__) == ADC_EXTERNALTRIGINJEC_T8_CC4)      || \
                                                      ((__INJTRIG__) == ADC_EXTERNALTRIGINJEC_T1_TRGO2)    || \
                                                      ((__INJTRIG__) == ADC_EXTERNALTRIGINJEC_T8_TRGO)     || \
                                                      ((__INJTRIG__) == ADC_EXTERNALTRIGINJEC_T8_TRGO2)    || \
                                                      ((__INJTRIG__) == ADC_EXTERNALTRIGINJEC_T3_CC3)      || \
                                                      ((__INJTRIG__) == ADC_EXTERNALTRIGINJEC_T3_TRGO)     || \
                                                      ((__INJTRIG__) == ADC_EXTERNALTRIGINJEC_T3_CC1)      || \
                                                      ((__INJTRIG__) == ADC_EXTERNALTRIGINJEC_T6_TRGO)     || \
                                                      ((__INJTRIG__) == ADC_EXTERNALTRIGINJEC_T15_TRGO)    || \
                                                      ((__INJTRIG__) == ADC_INJECTED_SOFTWARE_START)       )

   
                                                                  
                                                        
                                                                          
    
#define IS_ADC_EXTTRIGINJEC_EDGE(__EDGE__) (((__EDGE__) == ADC_EXTERNALTRIGINJECCONV_EDGE_NONE)         || \
                                            ((__EDGE__) == ADC_EXTERNALTRIGINJECCONV_EDGE_RISING)       || \
                                            ((__EDGE__) == ADC_EXTERNALTRIGINJECCONV_EDGE_FALLING)      || \
                                            ((__EDGE__) == ADC_EXTERNALTRIGINJECCONV_EDGE_RISINGFALLING) )

#if defined(ADC_MULTIMODE_SUPPORT)
   
                                            
                                                     
                                                                  
    
#define IS_ADC_MULTIMODE(__MODE__) (((__MODE__) == ADC_MODE_INDEPENDENT)               || \
                                    ((__MODE__) == ADC_DUALMODE_REGSIMULT_INJECSIMULT) || \
                                    ((__MODE__) == ADC_DUALMODE_REGSIMULT_ALTERTRIG)   || \
                                    ((__MODE__) == ADC_DUALMODE_REGINTERL_INJECSIMULT) || \
                                    ((__MODE__) == ADC_DUALMODE_INJECSIMULT)           || \
                                    ((__MODE__) == ADC_DUALMODE_REGSIMULT)             || \
                                    ((__MODE__) == ADC_DUALMODE_INTERL)                || \
                                    ((__MODE__) == ADC_DUALMODE_ALTERTRIG)               )

   
                                                       
                                                                
                                                                  
    
#define IS_ADC_DMA_ACCESS_MULTIMODE(__MODE__) (((__MODE__) == ADC_DMAACCESSMODE_DISABLED)   || \
                                               ((__MODE__) == ADC_DMAACCESSMODE_12_10_BITS) || \
                                               ((__MODE__) == ADC_DMAACCESSMODE_8_6_BITS)     )

   
                                                  
                                                            
                                                                            
    
#define IS_ADC_SAMPLING_DELAY(__DELAY__) (((__DELAY__) == ADC_TWOSAMPLINGDELAY_1CYCLE)   || \
                                          ((__DELAY__) == ADC_TWOSAMPLINGDELAY_2CYCLES)  || \
                                          ((__DELAY__) == ADC_TWOSAMPLINGDELAY_3CYCLES)  || \
                                          ((__DELAY__) == ADC_TWOSAMPLINGDELAY_4CYCLES)  || \
                                          ((__DELAY__) == ADC_TWOSAMPLINGDELAY_5CYCLES)  || \
                                          ((__DELAY__) == ADC_TWOSAMPLINGDELAY_6CYCLES)  || \
                                          ((__DELAY__) == ADC_TWOSAMPLINGDELAY_7CYCLES)  || \
                                          ((__DELAY__) == ADC_TWOSAMPLINGDELAY_8CYCLES)  || \
                                          ((__DELAY__) == ADC_TWOSAMPLINGDELAY_9CYCLES)  || \
                                          ((__DELAY__) == ADC_TWOSAMPLINGDELAY_10CYCLES) || \
                                          ((__DELAY__) == ADC_TWOSAMPLINGDELAY_11CYCLES) || \
                                          ((__DELAY__) == ADC_TWOSAMPLINGDELAY_12CYCLES)   )
#endif                            

   
                                                  
                                                               
                                                                          
    
#define IS_ADC_ANALOG_WATCHDOG_NUMBER(__WATCHDOG__) (((__WATCHDOG__) == ADC_ANALOGWATCHDOG_1) || \
                                                     ((__WATCHDOG__) == ADC_ANALOGWATCHDOG_2) || \
                                                     ((__WATCHDOG__) == ADC_ANALOGWATCHDOG_3)   )

   
                                                       
                                                                         
                                                                                    
    
#define IS_ADC_ANALOG_WATCHDOG_MODE(__WATCHDOG_MODE__) (((__WATCHDOG_MODE__) == ADC_ANALOGWATCHDOG_NONE)            || \
                                                        ((__WATCHDOG_MODE__) == ADC_ANALOGWATCHDOG_SINGLE_REG)      || \
                                                        ((__WATCHDOG_MODE__) == ADC_ANALOGWATCHDOG_SINGLE_INJEC)    || \
                                                        ((__WATCHDOG_MODE__) == ADC_ANALOGWATCHDOG_SINGLE_REGINJEC) || \
                                                        ((__WATCHDOG_MODE__) == ADC_ANALOGWATCHDOG_ALL_REG)         || \
                                                        ((__WATCHDOG_MODE__) == ADC_ANALOGWATCHDOG_ALL_INJEC)       || \
                                                        ((__WATCHDOG_MODE__) == ADC_ANALOGWATCHDOG_ALL_REGINJEC)      )

   
                                                                   
                                               
                                                                              
    
#define IS_ADC_CONVERSION_GROUP(__CONVERSION__) (((__CONVERSION__) == ADC_REGULAR_GROUP)         || \
                                                 ((__CONVERSION__) == ADC_INJECTED_GROUP)        || \
                                                 ((__CONVERSION__) == ADC_REGULAR_INJECTED_GROUP)  )

   
                                     
                               
                                                                    
    
#define IS_ADC_EVENT_TYPE(__EVENT__) (((__EVENT__) == ADC_EOSMP_EVENT)  || \
                                      ((__EVENT__) == ADC_AWD_EVENT)    || \
                                      ((__EVENT__) == ADC_AWD2_EVENT)   || \
                                      ((__EVENT__) == ADC_AWD3_EVENT)   || \
                                      ((__EVENT__) == ADC_OVR_EVENT)    || \
                                      ((__EVENT__) == ADC_JQOVF_EVENT)  )

   
                                             
                                                       
                                                                            
    
#define IS_ADC_OVERSAMPLING_RATIO(__RATIO__)      (((__RATIO__) == ADC_OVERSAMPLING_RATIO_2   ) || \
                                                   ((__RATIO__) == ADC_OVERSAMPLING_RATIO_4   ) || \
                                                   ((__RATIO__) == ADC_OVERSAMPLING_RATIO_8   ) || \
                                                   ((__RATIO__) == ADC_OVERSAMPLING_RATIO_16  ) || \
                                                   ((__RATIO__) == ADC_OVERSAMPLING_RATIO_32  ) || \
                                                   ((__RATIO__) == ADC_OVERSAMPLING_RATIO_64  ) || \
                                                   ((__RATIO__) == ADC_OVERSAMPLING_RATIO_128 ) || \
                                                   ((__RATIO__) == ADC_OVERSAMPLING_RATIO_256 ))

   
                                             
                                                       
                                                                            
    
#define IS_ADC_RIGHT_BIT_SHIFT(__SHIFT__)        (((__SHIFT__) == ADC_RIGHTBITSHIFT_NONE) || \
                                                  ((__SHIFT__) == ADC_RIGHTBITSHIFT_1   ) || \
                                                  ((__SHIFT__) == ADC_RIGHTBITSHIFT_2   ) || \
                                                  ((__SHIFT__) == ADC_RIGHTBITSHIFT_3   ) || \
                                                  ((__SHIFT__) == ADC_RIGHTBITSHIFT_4   ) || \
                                                  ((__SHIFT__) == ADC_RIGHTBITSHIFT_5   ) || \
                                                  ((__SHIFT__) == ADC_RIGHTBITSHIFT_6   ) || \
                                                  ((__SHIFT__) == ADC_RIGHTBITSHIFT_7   ) || \
                                                  ((__SHIFT__) == ADC_RIGHTBITSHIFT_8   ))

   
                                                      
                                                               
                                                                  
    
#define IS_ADC_TRIGGERED_OVERSAMPLING_MODE(__MODE__) (((__MODE__) == ADC_TRIGGEREDMODE_SINGLE_TRIGGER) || \
                                                      ((__MODE__) == ADC_TRIGGEREDMODE_MULTI_TRIGGER) )

   
                                                                                    
                                                                                             
                                                                  
    
#define IS_ADC_REGOVERSAMPLING_MODE(__MODE__) (((__MODE__) == ADC_REGOVERSAMPLING_CONTINUED_MODE) || \
                                               ((__MODE__) == ADC_REGOVERSAMPLING_RESUMED_MODE) )

   
                                               
                                 
                                                                                               
                                                                                               
                  
                                                                                                  
    
#if defined(ADC_CFGR_DFSDMCFG) &&defined(DFSDM1_Channel0)
#define IS_ADC_DFSDMCFG_MODE(__HANDLE__) (((__HANDLE__)->Init.DFSDMConfig == ADC_DFSDM_MODE_DISABLE) || \
                                          ((__HANDLE__)->Init.DFSDMConfig == ADC_DFSDM_MODE_ENABLE) )
#else
#define IS_ADC_DFSDMCFG_MODE(__HANDLE__) (SET)
#endif                        

   
                                               
                                 
                                                                                                          
                                                                                                    
                   
                                    
    
#if defined(ADC_CFGR_DFSDMCFG) &&defined(DFSDM1_Channel0)
#define ADC_CFGR_DFSDM(__HANDLE__) ((__HANDLE__)->Init.DFSDMConfig)
#else
#define ADC_CFGR_DFSDM(__HANDLE__) (0x0UL)
#endif                        

   
      
    


                                                                                
                                        
      
    

                                               
      
    
                                                                                

                     
HAL_StatusTypeDef       HAL_ADCEx_Calibration_Start(ADC_HandleTypeDef *hadc, uint32_t SingleDiff);
uint32_t                HAL_ADCEx_Calibration_GetValue(const ADC_HandleTypeDef *hadc, uint32_t SingleDiff);
HAL_StatusTypeDef       HAL_ADCEx_Calibration_SetValue(ADC_HandleTypeDef *hadc, uint32_t SingleDiff,
                                                       uint32_t CalibrationFactor);

                            
HAL_StatusTypeDef       HAL_ADCEx_InjectedStart(ADC_HandleTypeDef *hadc);
HAL_StatusTypeDef       HAL_ADCEx_InjectedStop(ADC_HandleTypeDef *hadc);
HAL_StatusTypeDef       HAL_ADCEx_InjectedPollForConversion(ADC_HandleTypeDef *hadc, uint32_t Timeout);

                                     
HAL_StatusTypeDef       HAL_ADCEx_InjectedStart_IT(ADC_HandleTypeDef *hadc);
HAL_StatusTypeDef       HAL_ADCEx_InjectedStop_IT(ADC_HandleTypeDef *hadc);

#if defined(ADC_MULTIMODE_SUPPORT)
                   
HAL_StatusTypeDef       HAL_ADCEx_MultiModeStart_DMA(ADC_HandleTypeDef *hadc, uint32_t *pData, uint32_t Length);
HAL_StatusTypeDef       HAL_ADCEx_MultiModeStop_DMA(ADC_HandleTypeDef *hadc);
uint32_t                HAL_ADCEx_MultiModeGetValue(const ADC_HandleTypeDef *hadc);
#endif                            

                                                                                    
uint32_t                HAL_ADCEx_InjectedGetValue(const ADC_HandleTypeDef *hadc, uint32_t InjectedRank);

                                                                            
void                    HAL_ADCEx_InjectedConvCpltCallback(ADC_HandleTypeDef *hadc);
void                    HAL_ADCEx_InjectedQueueOverflowCallback(ADC_HandleTypeDef *hadc);
void                    HAL_ADCEx_LevelOutOfWindow2Callback(ADC_HandleTypeDef *hadc);
void                    HAL_ADCEx_LevelOutOfWindow3Callback(ADC_HandleTypeDef *hadc);
void                    HAL_ADCEx_EndOfSamplingCallback(ADC_HandleTypeDef *hadc);

                                        
HAL_StatusTypeDef       HAL_ADCEx_RegularStop(ADC_HandleTypeDef *hadc);
HAL_StatusTypeDef       HAL_ADCEx_RegularStop_IT(ADC_HandleTypeDef *hadc);
HAL_StatusTypeDef       HAL_ADCEx_RegularStop_DMA(ADC_HandleTypeDef *hadc);
#if defined(ADC_MULTIMODE_SUPPORT)
HAL_StatusTypeDef       HAL_ADCEx_RegularMultiModeStop_DMA(ADC_HandleTypeDef *hadc);
#endif                            

   
      
    

                                               
      
    
                                                                                
HAL_StatusTypeDef       HAL_ADCEx_InjectedConfigChannel(ADC_HandleTypeDef *hadc,
                                                        const ADC_InjectionConfTypeDef *pConfigInjected);
#if defined(ADC_MULTIMODE_SUPPORT)
HAL_StatusTypeDef       HAL_ADCEx_MultiModeConfigChannel(ADC_HandleTypeDef *hadc,
                                                         const ADC_MultiModeTypeDef *pMultimode);
#endif                            

HAL_StatusTypeDef       HAL_ADCEx_EnableInjectedQueue(ADC_HandleTypeDef *hadc);
HAL_StatusTypeDef       HAL_ADCEx_DisableInjectedQueue(ADC_HandleTypeDef *hadc);
HAL_StatusTypeDef       HAL_ADCEx_DisableVoltageRegulator(ADC_HandleTypeDef *hadc);
HAL_StatusTypeDef       HAL_ADCEx_EnterADCDeepPowerDownMode(ADC_HandleTypeDef *hadc);

   
      
    

   
      
    

   
      
    

   
      
    

#ifdef __cplusplus
}
#endif

#endif                             
