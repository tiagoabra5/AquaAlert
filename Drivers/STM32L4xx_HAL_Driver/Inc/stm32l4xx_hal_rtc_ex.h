/**
  ******************************************************************************
  * @file    stm32l4xx_hal_rtc_ex.h
  * @author  MCD Application Team
  * @brief   Header file of RTC HAL Extended module.
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

                                                                                
#ifndef STM32L4xx_HAL_RTC_EX_H
#define STM32L4xx_HAL_RTC_EX_H

#ifdef __cplusplus
extern "C" {
#endif

                                                                                
#include "stm32l4xx_hal_def.h"

                                    
      
    

                         
      
    

                                                                                
                                                       
      
    

                                                                                 
      
    
typedef struct
{
  uint32_t Tamper;                                                    
                                                                                                                   

  uint32_t Interrupt;                                                       
                                                                                                                         

  uint32_t Trigger;                                                       
                                                                                                                      

  uint32_t NoErase;                                                             
                                                                                                                          

  uint32_t MaskFlag;                                                           
                                                                                                                         

  uint32_t Filter;                                                            
                                                                                                                     

  uint32_t SamplingFrequency;                                                 
                                                                                                                                   

  uint32_t PrechargeDuration;                                                  
                                                                                                                                     

  uint32_t TamperPullUp;                                                  
                                                                                                                      

  uint32_t TimeStampOnTamperDetection;                                                
                                                                                                                                         
} RTC_TamperTypeDef;
   
      
    

   
      
    

                                                                                

                                                               
      
    

                                                                                
                                                                                
                                                                                

                                                                                   
   
      
    
#define RTC_TIMESTAMPEDGE_RISING        0x00000000u
#define RTC_TIMESTAMPEDGE_FALLING       RTC_CR_TSEDGE
   
      
    

                                                                         
      
    
#define RTC_TIMESTAMPPIN_DEFAULT              0x00000000u
   
      
    

                                                                                
                                                                                
                                                                                

                                                                           
      
    
#define RTC_WAKEUPCLOCK_RTCCLK_DIV16        0x00000000u
#define RTC_WAKEUPCLOCK_RTCCLK_DIV8         RTC_CR_WUCKSEL_0
#define RTC_WAKEUPCLOCK_RTCCLK_DIV4         RTC_CR_WUCKSEL_1
#define RTC_WAKEUPCLOCK_RTCCLK_DIV2         (RTC_CR_WUCKSEL_0 | RTC_CR_WUCKSEL_1)
#define RTC_WAKEUPCLOCK_CK_SPRE_16BITS      RTC_CR_WUCKSEL_2
#define RTC_WAKEUPCLOCK_CK_SPRE_17BITS      (RTC_CR_WUCKSEL_1 | RTC_CR_WUCKSEL_2)
   
      
    

                                                                                
                                                                                
                                                                                

                                                                                         
      
    
#define RTC_SMOOTHCALIB_PERIOD_32SEC   0x00000000u                                                           
                                                                                                                 
#define RTC_SMOOTHCALIB_PERIOD_16SEC   RTC_CALR_CALW16                                                       
                                                                                                                
#define RTC_SMOOTHCALIB_PERIOD_8SEC    RTC_CALR_CALW8                                                        
                                                                                                               
   
      
    

                                                                                                   
      
    
#define RTC_SMOOTHCALIB_PLUSPULSES_SET    RTC_CALR_CALP                                               
                                                                                                              
                                                                                                                 
#define RTC_SMOOTHCALIB_PLUSPULSES_RESET  0x00000000u                                                      
                                                                                                             
   
      
    

#if defined(STM32L412xx) || defined(STM32L422xx) || defined (STM32L4P5xx) || defined (STM32L4Q5xx)
                                                                                               
      
    
#define RTC_LPCAL_SET                     RTC_CALR_LPCAL                                               
                                                                                                            
                                                                                                   
#define RTC_LPCAL_RESET                   0x00000000u                                                 
                                                                                                      
                                                                                                           
                                                                                                                
   
      
    
#endif                                                                                                         

                                                                                               
      
    
#define RTC_CALIBOUTPUT_512HZ            0x00000000u
#define RTC_CALIBOUTPUT_1HZ              RTC_CR_COSEL
   
      
    

                                                                                             
      
    
#define RTC_SHIFTADD1S_RESET      0x00000000u
#define RTC_SHIFTADD1S_SET        RTC_SHIFTR_ADD1S
   
      
    


                                                                                
                                                                                
                                                                                

                                                                         
      
    
#if defined(STM32L412xx) || defined(STM32L422xx) || defined (STM32L4P5xx) || defined (STM32L4Q5xx)
#if defined(RTC_TAMPER1_SUPPORT)
#define RTC_TAMPER_1                        TAMP_CR1_TAMP1E
#endif                          
#define RTC_TAMPER_2                        TAMP_CR1_TAMP2E
#if defined(RTC_TAMPER3_SUPPORT)
#define RTC_TAMPER_3                        TAMP_CR1_TAMP3E
#endif                          
#if defined(RTC_TAMPER3_SUPPORT)
#define RTC_TAMPER_ALL                      (TAMP_CR1_TAMP1E | TAMP_CR1_TAMP2E | TAMP_CR1_TAMP3E)
#else
#define RTC_TAMPER_ALL                      (TAMP_CR1_TAMP1E | TAMP_CR1_TAMP2E)
#endif
#else                                                                                                         
#if defined(RTC_TAMPER1_SUPPORT)
#define RTC_TAMPER_1                        RTC_TAMPCR_TAMP1E
#endif                          
#define RTC_TAMPER_2                        RTC_TAMPCR_TAMP2E
#if defined(RTC_TAMPER3_SUPPORT)
#define RTC_TAMPER_3                        RTC_TAMPCR_TAMP3E
#endif                          
#endif                                                                                                         
   
      
    

                                                                                
      
    
#if defined(STM32L412xx) || defined(STM32L422xx) || defined (STM32L4P5xx) || defined (STM32L4Q5xx)
#define RTC_TAMPERTRIGGER_RISINGEDGE        0x00u                                                           
#define RTC_TAMPERTRIGGER_FALLINGEDGE       0x01u                                                           
#define RTC_TAMPERTRIGGER_LOWLEVEL          0x02u                                                               
#define RTC_TAMPERTRIGGER_HIGHLEVEL         0x03u                                                               
#else
#define RTC_TAMPERTRIGGER_RISINGEDGE        ((uint32_t)0x00000000)
#define RTC_TAMPERTRIGGER_FALLINGEDGE       ((uint32_t)0x00000002)
#define RTC_TAMPERTRIGGER_LOWLEVEL          RTC_TAMPERTRIGGER_RISINGEDGE
#define RTC_TAMPERTRIGGER_HIGHLEVEL         RTC_TAMPERTRIGGER_FALLINGEDGE
#endif
   
      
    

                                                                                  
      
    
#if defined(STM32L412xx) || defined(STM32L422xx) || defined (STM32L4P5xx) || defined (STM32L4Q5xx)
#define RTC_TAMPERMASK_FLAG_DISABLE         0x00u
#define RTC_TAMPERMASK_FLAG_ENABLE          0x01u
#else
#define RTC_TAMPERMASK_FLAG_DISABLE         0x00000000u
#define RTC_TAMPERMASK_FLAG_ENABLE          0x00040000u
#endif
   
      
    

                                                                                       
    
  
#if defined(STM32L412xx) || defined(STM32L422xx) || defined (STM32L4P5xx) || defined (STM32L4Q5xx)
#define RTC_TAMPER_ERASE_BACKUP_ENABLE      0x00u
#define RTC_TAMPER_ERASE_BACKUP_DISABLE     0x01u
#else
#define RTC_TAMPER_ERASE_BACKUP_ENABLE      0x00000000u
#define RTC_TAMPER_ERASE_BACKUP_DISABLE     0x00020000u
#endif
   
      
    

                                                                             
      
    
#if defined(STM32L412xx) || defined(STM32L422xx) || defined (STM32L4P5xx) || defined (STM32L4Q5xx)
#define RTC_TAMPERFILTER_DISABLE           0x00000000U                                              

#define RTC_TAMPERFILTER_2SAMPLE           TAMP_FLTCR_TAMPFLT_0                                    
                                                                                                                   
#define RTC_TAMPERFILTER_4SAMPLE           TAMP_FLTCR_TAMPFLT_1                                    
                                                                                                                   
#define RTC_TAMPERFILTER_8SAMPLE           TAMP_FLTCR_TAMPFLT                                      
                                                                                                                   
#else                                                                                                         
#define RTC_TAMPERFILTER_DISABLE           0x00000000u                                              

#define RTC_TAMPERFILTER_2SAMPLE           RTC_TAMPCR_TAMPFLT_0                                    
                                                                                                                  
#define RTC_TAMPERFILTER_4SAMPLE           RTC_TAMPCR_TAMPFLT_1                                    
                                                                                                                   
#define RTC_TAMPERFILTER_8SAMPLE           RTC_TAMPCR_TAMPFLT                                      
                                                                                                                    
#endif                                                                                                        

   
      
    

                                                                                                         
      
    
#if defined(STM32L412xx) || defined(STM32L422xx) || defined (STM32L4P5xx) || defined (STM32L4Q5xx)
#define RTC_TAMPERSAMPLINGFREQ_RTCCLK_DIV32768  0x00000000U                                                                               
                                                                                                                                           
#define RTC_TAMPERSAMPLINGFREQ_RTCCLK_DIV16384  TAMP_FLTCR_TAMPFREQ_0                                                                     
                                                                                                                                           
#define RTC_TAMPERSAMPLINGFREQ_RTCCLK_DIV8192   TAMP_FLTCR_TAMPFREQ_1                                                                     
                                                                                                                                           
#define RTC_TAMPERSAMPLINGFREQ_RTCCLK_DIV4096   (TAMP_FLTCR_TAMPFREQ_0 | TAMP_FLTCR_TAMPFREQ_1)                                           
                                                                                                                                           
#define RTC_TAMPERSAMPLINGFREQ_RTCCLK_DIV2048   TAMP_FLTCR_TAMPFREQ_2                                                                     
                                                                                                                                           
#define RTC_TAMPERSAMPLINGFREQ_RTCCLK_DIV1024   (TAMP_FLTCR_TAMPFREQ_0 | TAMP_FLTCR_TAMPFREQ_2)                                           
                                                                                                                                           
#define RTC_TAMPERSAMPLINGFREQ_RTCCLK_DIV512    (TAMP_FLTCR_TAMPFREQ_1 | TAMP_FLTCR_TAMPFREQ_2)                                           
                                                                                                                                           
#define RTC_TAMPERSAMPLINGFREQ_RTCCLK_DIV256    TAMP_FLTCR_TAMPFREQ                                                                       
                                                                                                                                           
#define RTC_TAMPERSAMPLINGFREQ_RTCCLK_MASK      TAMP_FLTCR_TAMPFREQ                                                                  
                                                                                                                           
#else                                                                                                         

#define RTC_TAMPERSAMPLINGFREQ_RTCCLK_DIV32768  0x00000000u                                                                               
                                                                                                                                           
#define RTC_TAMPERSAMPLINGFREQ_RTCCLK_DIV16384  RTC_TAMPCR_TAMPFREQ_0                                                                     
                                                                                                                                           
#define RTC_TAMPERSAMPLINGFREQ_RTCCLK_DIV8192   RTC_TAMPCR_TAMPFREQ_1                                                                     
                                                                                                                                           
#define RTC_TAMPERSAMPLINGFREQ_RTCCLK_DIV4096   (RTC_TAMPCR_TAMPFREQ_0 | RTC_TAMPCR_TAMPFREQ_1)                                           
                                                                                                                                           
#define RTC_TAMPERSAMPLINGFREQ_RTCCLK_DIV2048   RTC_TAMPCR_TAMPFREQ_2                                                                     
                                                                                                                                           
#define RTC_TAMPERSAMPLINGFREQ_RTCCLK_DIV1024   (RTC_TAMPCR_TAMPFREQ_0 | RTC_TAMPCR_TAMPFREQ_2)                                            
                                                                                                                                           
#define RTC_TAMPERSAMPLINGFREQ_RTCCLK_DIV512    (RTC_TAMPCR_TAMPFREQ_1 | RTC_TAMPCR_TAMPFREQ_2)                                            
                                                                                                                                           
#define RTC_TAMPERSAMPLINGFREQ_RTCCLK_DIV256    RTC_TAMPCR_TAMPFREQ                                                                        
                                                                                                                                           
#define RTC_TAMPERSAMPLINGFREQ_RTCCLK_MASK      RTC_TAMPCR_TAMPFREQ                                                                  
                                                                                                                           
#endif                                                                                                         
   
      
    

                                                                                                             
      
    
#if defined(STM32L412xx) || defined(STM32L422xx) || defined (STM32L4P5xx) || defined (STM32L4Q5xx)
#define RTC_TAMPERPRECHARGEDURATION_1RTCCLK     0x00000000U                                                                              
                                                                                                                                          
#define RTC_TAMPERPRECHARGEDURATION_2RTCCLK     TAMP_FLTCR_TAMPPRCH_0                                                                    
                                                                                                                                          
#define RTC_TAMPERPRECHARGEDURATION_4RTCCLK     TAMP_FLTCR_TAMPPRCH_1                                                                    
                                                                                                                                          
#define RTC_TAMPERPRECHARGEDURATION_8RTCCLK     TAMP_FLTCR_TAMPPRCH                                            
                                                                                                           
#else                                                                                                         

#define RTC_TAMPERPRECHARGEDURATION_1RTCCLK     0x00000000u                                                    
                                                                                                                
#define RTC_TAMPERPRECHARGEDURATION_2RTCCLK     RTC_TAMPCR_TAMPPRCH_0                                          
                                                                                                                
#define RTC_TAMPERPRECHARGEDURATION_4RTCCLK     RTC_TAMPCR_TAMPPRCH_1                                          
                                                                                                                
#define RTC_TAMPERPRECHARGEDURATION_8RTCCLK     RTC_TAMPCR_TAMPPRCH                                            
                                                                                                                
#define RTC_TAMPERPRECHARGEDURATION_MASK        RTC_TAMPCR_TAMPPRCH                                          
                                                                                                    
#endif                                                                                                         
   
      
    

                                                                               
      
    
#if defined(STM32L412xx) || defined(STM32L422xx) || defined (STM32L4P5xx) || defined (STM32L4Q5xx)
#define RTC_TAMPER_PULLUP_ENABLE           0x00000000u                                                              
#define RTC_TAMPER_PULLUP_DISABLE          TAMP_FLTCR_TAMPPUDIS                                                     
#else
#define RTC_TAMPER_PULLUP_ENABLE           0x00000000u                                                                   
#define RTC_TAMPER_PULLUP_DISABLE          RTC_TAMPCR_TAMPPUDIS                                                          
#endif

   
      
    

                                                                                                                        
      
    
#if defined(STM32L412xx) || defined(STM32L422xx) || defined (STM32L4P5xx) || defined (STM32L4Q5xx)
#define RTC_TIMESTAMPONTAMPERDETECTION_DISABLE  0x00000000u                                                            
#define RTC_TIMESTAMPONTAMPERDETECTION_ENABLE   RTC_CR_TAMPTS                                                          
#else
#define RTC_TIMESTAMPONTAMPERDETECTION_DISABLE  0x00000000u                                                                
#define RTC_TIMESTAMPONTAMPERDETECTION_ENABLE   RTC_TAMPCR_TAMPTS                                                          
#endif
   
      
    

                                                                                  
      
    

#if defined(STM32L412xx) || defined(STM32L422xx)
#define RTC_IT_TAMP1                        TAMP_IER_TAMP1IE                             
#define RTC_IT_TAMP2                        TAMP_IER_TAMP2IE                             
#define RTC_IT_TAMP                         (TAMP_IER_TAMP1IE | TAMP_IER_TAMP2IE)                                     
#elif defined (STM32L4P5xx) || defined (STM32L4Q5xx)
#define RTC_IT_TAMP1                        TAMP_IER_TAMP1IE                             
#define RTC_IT_TAMP2                        TAMP_IER_TAMP2IE                             
#define RTC_IT_TAMP3                        TAMP_IER_TAMP3IE                             
#define RTC_IT_TAMP                         (TAMP_IER_TAMP1IE | TAMP_IER_TAMP2IE | TAMP_IER_TAMP3IE)                                     
#else
#define RTC_IT_TAMP                         RTC_TAMPCR_TAMPIE                                      
#define RTC_IT_TAMP1                        RTC_TAMPCR_TAMP1IE                                      
#define RTC_IT_TAMP2                        RTC_TAMPCR_TAMP2IE                                      
#define RTC_IT_TAMP3                        RTC_TAMPCR_TAMP3IE                                      
#endif
#define RTC_IT_TAMPALL                      RTC_IT_TAMP
   
      
    

                                      
      
    
#if defined(STM32L412xx) || defined(STM32L422xx)
#define RTC_FLAG_TAMP1F                     TAMP_SR_TAMP1F
#define RTC_FLAG_TAMP2F                     TAMP_SR_TAMP2F
#define RTC_FLAG_TAMPALL                   (RTC_FLAG_TAMP1F | RTC_FLAG_TAMP2F)
#elif defined (STM32L4P5xx) || defined (STM32L4Q5xx)
#define RTC_FLAG_TAMP1F                     TAMP_SR_TAMP1F
#define RTC_FLAG_TAMP2F                     TAMP_SR_TAMP2F
#define RTC_FLAG_TAMP3F                     TAMP_SR_TAMP3F
#define RTC_FLAG_TAMPALL                   (RTC_FLAG_TAMP1F | RTC_FLAG_TAMP2F | RTC_FLAG_TAMP3F)
#else
#define RTC_FLAG_TAMP1F                     RTC_ISR_TAMP1F
#define RTC_FLAG_TAMP2F                     RTC_ISR_TAMP2F
#define RTC_FLAG_TAMP3F                     RTC_ISR_TAMP3F
#endif
   
      
    

                                                                                
                                                                                
                                                                                

                                                                                                         
      
    
#if defined(RTC_BKP_NUMBER)
#define BKP_REG_NUMBER                       RTC_BKP_NUMBER
#endif                     
#if defined(TAMP_BKP_NUMBER)
#define BKP_REG_NUMBER                       TAMP_BKP_NUMBER
#endif                      
   
      
    

                                                                                             
      
    
#define RTC_BKP_DR0                       0x00u
#define RTC_BKP_DR1                       0x01u
#define RTC_BKP_DR2                       0x02u
#define RTC_BKP_DR3                       0x03u
#define RTC_BKP_DR4                       0x04u
#define RTC_BKP_DR5                       0x05u
#define RTC_BKP_DR6                       0x06u
#define RTC_BKP_DR7                       0x07u
#define RTC_BKP_DR8                       0x08u
#define RTC_BKP_DR9                       0x09u
#define RTC_BKP_DR10                      0x0Au
#define RTC_BKP_DR11                      0x0Bu
#define RTC_BKP_DR12                      0x0Cu
#define RTC_BKP_DR13                      0x0Du
#define RTC_BKP_DR14                      0x0Eu
#define RTC_BKP_DR15                      0x0Fu
#define RTC_BKP_DR16                      0x10u
#define RTC_BKP_DR17                      0x11u
#define RTC_BKP_DR18                      0x12u
#define RTC_BKP_DR19                      0x13u
#define RTC_BKP_DR20                      0x14u
#define RTC_BKP_DR21                      0x15u
#define RTC_BKP_DR22                      0x16u
#define RTC_BKP_DR23                      0x17u
#define RTC_BKP_DR24                      0x18u
#define RTC_BKP_DR25                      0x19u
#define RTC_BKP_DR26                      0x1Au
#define RTC_BKP_DR27                      0x1Bu
#define RTC_BKP_DR28                      0x1Cu
#define RTC_BKP_DR29                      0x1Du
#define RTC_BKP_DR30                      0x1Eu
#define RTC_BKP_DR31                      0x1Fu
   
      
    




                                                                                  
      
    
#if defined(STM32L412xx) || defined(STM32L422xx)
#define RTC_TAMPER1_INTERRUPT              TAMP_IER_TAMP1IE
#define RTC_TAMPER2_INTERRUPT              TAMP_IER_TAMP2IE
#define RTC_ALL_TAMPER_INTERRUPT           (TAMP_IER_TAMP1IE | TAMP_IER_TAMP2IE)
#elif defined (STM32L4P5xx) || defined (STM32L4Q5xx)
#define RTC_TAMPER1_INTERRUPT              TAMP_IER_TAMP1IE
#define RTC_TAMPER2_INTERRUPT              TAMP_IER_TAMP2IE
#define RTC_TAMPER3_INTERRUPT              TAMP_IER_TAMP3IE
#define RTC_ALL_TAMPER_INTERRUPT           (TAMP_IER_TAMP1IE | TAMP_IER_TAMP2IE | TAMP_IER_TAMP3IE)
#else                                                       
#if defined(RTC_TAMPER1_SUPPORT)
#define RTC_TAMPER1_INTERRUPT              RTC_TAMPCR_TAMP1IE
#endif                          
#define RTC_TAMPER2_INTERRUPT              RTC_TAMPCR_TAMP2IE
#if defined(RTC_TAMPER3_SUPPORT)
#define RTC_TAMPER3_INTERRUPT              RTC_TAMPCR_TAMP3IE
#endif                          
#define RTC_ALL_TAMPER_INTERRUPT           RTC_TAMPCR_TAMPIE
#endif                                                       


#if defined (STM32L4P5xx) || defined (STM32L4Q5xx)
                                                                                            
                                                                                                                     
      
    
#define RTC_BINARY_NONE                     0x00000000u                                                                    
#define RTC_BINARY_ONLY                     RTC_ICSR_BIN_0                                                       
#define RTC_BINARY_MIX                      RTC_ICSR_BIN_1                                                     
   
      
    

                                                                                                                                                  
      
    
#define RTC_BINARY_MIX_BCDU_0  0x00000000u                                                                                            
#define RTC_BINARY_MIX_BCDU_1  (0x1UL << RTC_ICSR_BCDU_Pos)                                                                           
#define RTC_BINARY_MIX_BCDU_2  (0x2UL << RTC_ICSR_BCDU_Pos)                                                                           
#define RTC_BINARY_MIX_BCDU_3  (0x3UL << RTC_ICSR_BCDU_Pos)                                                                            
#define RTC_BINARY_MIX_BCDU_4  (0x4UL << RTC_ICSR_BCDU_Pos)                                                                            
#define RTC_BINARY_MIX_BCDU_5  (0x5UL << RTC_ICSR_BCDU_Pos)                                                                            
#define RTC_BINARY_MIX_BCDU_6  (0x6UL << RTC_ICSR_BCDU_Pos)                                                                            
#define RTC_BINARY_MIX_BCDU_7  (0x7UL << RTC_ICSR_BCDU_Pos)                                                                            
   
      
    

                                                                                                                       
      
    
#define RTC_ALARMSUBSECONDBINMASK_ALL           0x00000000u                                                                                                 
                                                                                                                                                                            
#define RTC_ALARMSUBSECONDBINMASK_SS31_1        (1UL << RTC_ALRMASSR_MASKSS_Pos)                                                                             
                                                                                                                                                                   
#define RTC_ALARMSUBSECONDBINMASK_SS31_2        (2UL << RTC_ALRMASSR_MASKSS_Pos)                                                                             
                                                                                                                                                                   
#define RTC_ALARMSUBSECONDBINMASK_SS31_3        (3UL << RTC_ALRMASSR_MASKSS_Pos)                                                                             
                                                                                                                                                                   
#define RTC_ALARMSUBSECONDBINMASK_SS31_4        (4UL << RTC_ALRMASSR_MASKSS_Pos)                                                                             
                                                                                                                                                                   
#define RTC_ALARMSUBSECONDBINMASK_SS31_5        (5UL << RTC_ALRMASSR_MASKSS_Pos)                                                                             
                                                                                                                                                                   
#define RTC_ALARMSUBSECONDBINMASK_SS31_6        (6UL << RTC_ALRMASSR_MASKSS_Pos)                                                                             
                                                                                                                                                                   
#define RTC_ALARMSUBSECONDBINMASK_SS31_7        (7UL << RTC_ALRMASSR_MASKSS_Pos)                                                                             
                                                                                                                                                                   
#define RTC_ALARMSUBSECONDBINMASK_SS31_8        (8UL << RTC_ALRMASSR_MASKSS_Pos)                                                                             
                                                                                                                                                                   
#define RTC_ALARMSUBSECONDBINMASK_SS31_9        (9UL << RTC_ALRMASSR_MASKSS_Pos)                                                                             
                                                                                                                                                                   
#define RTC_ALARMSUBSECONDBINMASK_SS31_10      (10UL << RTC_ALRMASSR_MASKSS_Pos)                                                                              
                                                                                                                                                                   
#define RTC_ALARMSUBSECONDBINMASK_SS31_11      (11UL << RTC_ALRMASSR_MASKSS_Pos)                                                                              
                                                                                                                                                                   
#define RTC_ALARMSUBSECONDBINMASK_SS31_12      (12UL << RTC_ALRMASSR_MASKSS_Pos)                                                                              
                                                                                                                                                                   
#define RTC_ALARMSUBSECONDBINMASK_SS31_13      (13UL << RTC_ALRMASSR_MASKSS_Pos)                                                                              
                                                                                                                                                                   
#define RTC_ALARMSUBSECONDBINMASK_SS31_14      (14UL << RTC_ALRMASSR_MASKSS_Pos)                                                                              
                                                                                                                                                                   
#define RTC_ALARMSUBSECONDBINMASK_SS31_15      (15UL << RTC_ALRMASSR_MASKSS_Pos)                                                                              
                                                                                                                                                                   
#define RTC_ALARMSUBSECONDBINMASK_SS31_16      (16UL << RTC_ALRMASSR_MASKSS_Pos)                                                                              
                                                                                                                                                                   
#define RTC_ALARMSUBSECONDBINMASK_SS31_17      (17UL << RTC_ALRMASSR_MASKSS_Pos)                                                                              
                                                                                                                                                                   
#define RTC_ALARMSUBSECONDBINMASK_SS31_18      (18UL << RTC_ALRMASSR_MASKSS_Pos)                                                                              
                                                                                                                                                                   
#define RTC_ALARMSUBSECONDBINMASK_SS31_19      (19UL << RTC_ALRMASSR_MASKSS_Pos)                                                                              
                                                                                                                                                                   
#define RTC_ALARMSUBSECONDBINMASK_SS31_20      (20UL << RTC_ALRMASSR_MASKSS_Pos)                                                                              
                                                                                                                                                                   
#define RTC_ALARMSUBSECONDBINMASK_SS31_21      (21UL << RTC_ALRMASSR_MASKSS_Pos)                                                                              
                                                                                                                                                                   
#define RTC_ALARMSUBSECONDBINMASK_SS31_22      (22UL << RTC_ALRMASSR_MASKSS_Pos)                                                                              
                                                                                                                                                                   
#define RTC_ALARMSUBSECONDBINMASK_SS31_23      (23UL << RTC_ALRMASSR_MASKSS_Pos)                                                                              
                                                                                                                                                                   
#define RTC_ALARMSUBSECONDBINMASK_SS31_24      (24UL << RTC_ALRMASSR_MASKSS_Pos)                                                                              
                                                                                                                                                                   
#define RTC_ALARMSUBSECONDBINMASK_SS31_25      (25UL << RTC_ALRMASSR_MASKSS_Pos)                                                                              
                                                                                                                                                                   
#define RTC_ALARMSUBSECONDBINMASK_SS31_26      (26UL << RTC_ALRMASSR_MASKSS_Pos)                                                                              
                                                                                                                                                                   
#define RTC_ALARMSUBSECONDBINMASK_SS31_27      (27UL << RTC_ALRMASSR_MASKSS_Pos)                                                                              
                                                                                                                                                                   
#define RTC_ALARMSUBSECONDBINMASK_SS31_28      (28UL << RTC_ALRMASSR_MASKSS_Pos)                                                                              
                                                                                                                                                                   
#define RTC_ALARMSUBSECONDBINMASK_SS31_29      (29UL << RTC_ALRMASSR_MASKSS_Pos)                                                                              
                                                                                                                                                                   
#define RTC_ALARMSUBSECONDBINMASK_SS31_30      (30UL << RTC_ALRMASSR_MASKSS_Pos)                                                                              
                                                                                                                                                                   
#define RTC_ALARMSUBSECONDBINMASK_SS31         (31UL << RTC_ALRMASSR_MASKSS_Pos)                                                                          
                                                                                                                                                                    
#define RTC_ALARMSUBSECONDBINMASK_NONE         (32UL << RTC_ALRMASSR_MASKSS_Pos)                                                                                                       
   
      
    

                                                                                                                            
      
    
#define RTC_ALARMSUBSECONDBIN_AUTOCLR_NO    0UL                                                                                                
#define RTC_ALARMSUBSECONDBIN_AUTOCLR_YES   RTC_ALRMASSR_SSCLR                                                                                            
                                                                                                                                                        
                                                                                                                    
   
      
    
#endif                                                         


   
      
    

                                                                                
                                                         
      
    

#if defined(STM32L412xx) || defined(STM32L422xx) || defined (STM32L4P5xx) || defined (STM32L4Q5xx)
                                                 
                                                
                                                 
                                                                           
                                                                                    
                                                                                    
                                                                           
                                                                             
                                                                        
                                                                        
                
    
#define __HAL_RTC_CLEAR_FLAG(__HANDLE__, __FLAG__)   ((__HANDLE__)->Instance->SCR = (__FLAG__))

                                                               
                                                
                                                 
                                                                           
                                                                                
                                                                         
                                                                                    
                                                                                
                                                                                  
                                                                             
                                                                        
                                                                        
                                                                              
                                                                              
                                                                     
                                                                       
                                                                  
                                                                  
                
    
#define __HAL_RTC_GET_FLAG(__HANDLE__, __FLAG__)    (((((__FLAG__)) >> 8U) == 1U) ? ((__HANDLE__)->Instance->ICSR & (1U << (((uint16_t)(__FLAG__)) & RTC_FLAG_MASK))) : \
                                                     ((__HANDLE__)->Instance->SR & (1U << (((uint16_t)(__FLAG__)) & RTC_FLAG_MASK))))
#endif                                                                                                        

                                                                                  
                                                 
      
    
   
                                                   
                                                
                
    
#define __HAL_RTC_WAKEUPTIMER_ENABLE(__HANDLE__)                      ((__HANDLE__)->Instance->CR |= (RTC_CR_WUTE))

   
                                                    
                                                
                
    
#define __HAL_RTC_WAKEUPTIMER_DISABLE(__HANDLE__)                     ((__HANDLE__)->Instance->CR &= ~(RTC_CR_WUTE))

   
                                                 
                                                
                                                                                        
                                  
                                                         
                
    
#define __HAL_RTC_WAKEUPTIMER_ENABLE_IT(__HANDLE__, __INTERRUPT__)    ((__HANDLE__)->Instance->CR |= (__INTERRUPT__))

   
                                                  
                                                
                                                                                         
                                  
                                                         
                
    
#define __HAL_RTC_WAKEUPTIMER_DISABLE_IT(__HANDLE__, __INTERRUPT__)   ((__HANDLE__)->Instance->CR &= ~(__INTERRUPT__))


   
                                                                                      
                                                
                                                                                   
                                  
                                                          
                
    
#if defined(STM32L412xx) || defined(STM32L422xx) || defined (STM32L4P5xx) || defined (STM32L4Q5xx)
#define __HAL_RTC_WAKEUPTIMER_GET_IT(__HANDLE__, __INTERRUPT__)       (((((__HANDLE__)->Instance->MISR) & ((__INTERRUPT__) >> 12)) != 0U) ? 1U : 0U)
#else
#define __HAL_RTC_WAKEUPTIMER_GET_IT(__HANDLE__, __INTERRUPT__)       (((((__HANDLE__)->Instance->ISR) & ((__INTERRUPT__) >> 4)) != 0U) ? 1U : 0U)
#endif

   
                                                                                            
                                                
                                                                                     
                                  
                                                          
                
    
#define __HAL_RTC_WAKEUPTIMER_GET_IT_SOURCE(__HANDLE__, __INTERRUPT__)   (((((__HANDLE__)->Instance->CR) & (__INTERRUPT__)) != 0U) ? 1U : 0U)

   
                                                           
                                                
                                                                          
                                   
                                       
                                        
                       
    
#if defined(STM32L412xx) || defined(STM32L422xx) || defined (STM32L4P5xx) || defined (STM32L4Q5xx)
#define __HAL_RTC_WAKEUPTIMER_GET_FLAG(__HANDLE__, __FLAG__)   (__HAL_RTC_GET_FLAG((__HANDLE__), (__FLAG__)))
#else
#define __HAL_RTC_WAKEUPTIMER_GET_FLAG(__HANDLE__, __FLAG__)   (((((__HANDLE__)->Instance->ISR) & (__FLAG__)) != 0U) ? 1U : 0U)
#endif

   
                                                       
                                                
                                                                 
                                  
                                      
                
    
#if defined(STM32L412xx) || defined(STM32L422xx) || defined (STM32L4P5xx) || defined (STM32L4Q5xx)
#define __HAL_RTC_WAKEUPTIMER_CLEAR_FLAG(__HANDLE__, __FLAG__)     (__HAL_RTC_CLEAR_FLAG((__HANDLE__), RTC_CLEAR_WUTF))
#else
#define __HAL_RTC_WAKEUPTIMER_CLEAR_FLAG(__HANDLE__, __FLAG__) ((__HANDLE__)->Instance->ISR) = (~((__FLAG__) | RTC_ISR_INIT)|((__HANDLE__)->Instance->ISR & RTC_ISR_INIT))
#endif


                        
                        
   
                                                                          
                
    
#define __HAL_RTC_WAKEUPTIMER_EXTI_ENABLE_IT()       (EXTI->IMR1 |= RTC_EXTI_LINE_WAKEUPTIMER_EVENT)

   
                                                                           
                
    
#define __HAL_RTC_WAKEUPTIMER_EXTI_DISABLE_IT()      (EXTI->IMR1 &= ~(RTC_EXTI_LINE_WAKEUPTIMER_EVENT))

   
                                                                      
                
    
#define __HAL_RTC_WAKEUPTIMER_EXTI_ENABLE_EVENT()    (EXTI->EMR1 |= RTC_EXTI_LINE_WAKEUPTIMER_EVENT)

   
                                                                       
                
    
#define __HAL_RTC_WAKEUPTIMER_EXTI_DISABLE_EVENT()   (EXTI->EMR1 &= ~(RTC_EXTI_LINE_WAKEUPTIMER_EVENT))

   
                                                                                     
                
    
#define __HAL_RTC_WAKEUPTIMER_EXTI_ENABLE_FALLING_EDGE()   (EXTI->FTSR1 |= RTC_EXTI_LINE_WAKEUPTIMER_EVENT)

   
                                                                                      
                
    
#define __HAL_RTC_WAKEUPTIMER_EXTI_DISABLE_FALLING_EDGE()  (EXTI->FTSR1 &= ~(RTC_EXTI_LINE_WAKEUPTIMER_EVENT))

   
                                                                                    
                
    
#define __HAL_RTC_WAKEUPTIMER_EXTI_ENABLE_RISING_EDGE()    (EXTI->RTSR1 |= RTC_EXTI_LINE_WAKEUPTIMER_EVENT)

   
                                                                                     
                
    
#define __HAL_RTC_WAKEUPTIMER_EXTI_DISABLE_RISING_EDGE()   (EXTI->RTSR1 &= ~(RTC_EXTI_LINE_WAKEUPTIMER_EVENT))

   
                                                                                              
                
    
#define __HAL_RTC_WAKEUPTIMER_EXTI_ENABLE_RISING_FALLING_EDGE()  do { \
                                                                   __HAL_RTC_WAKEUPTIMER_EXTI_ENABLE_RISING_EDGE();  \
                                                                   __HAL_RTC_WAKEUPTIMER_EXTI_ENABLE_FALLING_EDGE(); \
                                                                 } while(0)

   
                                                                                               
                          
                
    
#define __HAL_RTC_WAKEUPTIMER_EXTI_DISABLE_RISING_FALLING_EDGE()  do { \
                                                                   __HAL_RTC_WAKEUPTIMER_EXTI_DISABLE_RISING_EDGE();  \
                                                                   __HAL_RTC_WAKEUPTIMER_EXTI_DISABLE_FALLING_EDGE(); \
                                                                  } while(0)

   
                                                                                                
                        
    
#define __HAL_RTC_WAKEUPTIMER_EXTI_GET_FLAG()              (EXTI->PR1 & RTC_EXTI_LINE_WAKEUPTIMER_EVENT)

   
                                                                
                
    
#define __HAL_RTC_WAKEUPTIMER_EXTI_CLEAR_FLAG()            (EXTI->PR1 = RTC_EXTI_LINE_WAKEUPTIMER_EVENT)

   
                                                                                      
                
    
#define __HAL_RTC_WAKEUPTIMER_EXTI_GENERATE_SWIT()         (EXTI->SWIER1 |= RTC_EXTI_LINE_WAKEUPTIMER_EVENT)

   
      
    

                                                                                
                                           
      
    
   
                                                
                                                
                
    
#define __HAL_RTC_TIMESTAMP_ENABLE(__HANDLE__)                       ((__HANDLE__)->Instance->CR |= (RTC_CR_TSE))

   
                                                 
                                                
                
    
#define __HAL_RTC_TIMESTAMP_DISABLE(__HANDLE__)                      ((__HANDLE__)->Instance->CR &= ~(RTC_CR_TSE))

   
                                               
                                                
                                                                                     
                                  
                                                      
                
    
#define __HAL_RTC_TIMESTAMP_ENABLE_IT(__HANDLE__, __INTERRUPT__)     ((__HANDLE__)->Instance->CR |= (__INTERRUPT__))

   
                                                
                                                
                                                                                      
                                  
                                                      
                
    
#define __HAL_RTC_TIMESTAMP_DISABLE_IT(__HANDLE__, __INTERRUPT__)    ((__HANDLE__)->Instance->CR &= ~(__INTERRUPT__))

   
                                                                                    
                                                
                                                                                
                                  
                                                      
                
    
#if defined(STM32L412xx) || defined(STM32L422xx) || defined (STM32L4P5xx) || defined (STM32L4Q5xx)
#define __HAL_RTC_TIMESTAMP_GET_IT(__HANDLE__, __INTERRUPT__)        (((((__HANDLE__)->Instance->MISR) & ((__INTERRUPT__) >> 12)) != 0U) ? 1U : 0U)
#else
#define __HAL_RTC_TIMESTAMP_GET_IT(__HANDLE__, __INTERRUPT__)        (((((__HANDLE__)->Instance->ISR) & ((__INTERRUPT__) >> 4)) != 0U) ? 1U : 0U)
#endif
   
                                                                                         
                                                
                                                                                 
                                  
                                                      
                
    
#define __HAL_RTC_TIMESTAMP_GET_IT_SOURCE(__HANDLE__, __INTERRUPT__)     (((((__HANDLE__)->Instance->CR) & (__INTERRUPT__)) != 0U) ? 1U : 0U)

   
                                                         
                                                
                                                                        
                                  
                                     
                                       
                       
    
#if defined(STM32L412xx) || defined(STM32L422xx) || defined (STM32L4P5xx) || defined (STM32L4Q5xx)
#define __HAL_RTC_TIMESTAMP_GET_FLAG(__HANDLE__, __FLAG__)     (__HAL_RTC_GET_FLAG((__HANDLE__),(__FLAG__)))
#else
#define __HAL_RTC_TIMESTAMP_GET_FLAG(__HANDLE__, __FLAG__)     (((((__HANDLE__)->Instance->ISR) & (__FLAG__)) != 0U) ? 1U : 0U)
#endif

   
                                                    
                                                
                                                               
                                   
                                      
                                        
                
    
#if defined(STM32L412xx) || defined(STM32L422xx) || defined (STM32L4P5xx) || defined (STM32L4Q5xx)
#define __HAL_RTC_TIMESTAMP_CLEAR_FLAG(__HANDLE__, __FLAG__)   (__HAL_RTC_CLEAR_FLAG((__HANDLE__), (__FLAG__)))
#else
#define __HAL_RTC_TIMESTAMP_CLEAR_FLAG(__HANDLE__, __FLAG__)   ((__HANDLE__)->Instance->ISR) = (~((__FLAG__) | RTC_ISR_INIT)|((__HANDLE__)->Instance->ISR & RTC_ISR_INIT))
#endif

   
                                                         
                                                
                
    
#define __HAL_RTC_INTERNAL_TIMESTAMP_ENABLE(__HANDLE__)                ((__HANDLE__)->Instance->CR |= (RTC_CR_ITSE))

   
                                                          
                                                
                
    
#define __HAL_RTC_INTERNAL_TIMESTAMP_DISABLE(__HANDLE__)               ((__HANDLE__)->Instance->CR &= ~(RTC_CR_ITSE))

   
                                                                  
                                                
                                                                                  
                                  
                                      
                
    
#if defined(STM32L412xx) || defined(STM32L422xx) || defined (STM32L4P5xx) || defined (STM32L4Q5xx)
#define __HAL_RTC_INTERNAL_TIMESTAMP_GET_FLAG(__HANDLE__, __FLAG__)     (__HAL_RTC_GET_FLAG((__HANDLE__),(__FLAG__)))
#else
#define __HAL_RTC_INTERNAL_TIMESTAMP_GET_FLAG(__HANDLE__, __FLAG__)    (((((__HANDLE__)->Instance->ISR) & (__FLAG__)) != 0U) ? 1U : 0U)
#endif

   
                                                             
                                                
                                                                                
                          
                                       
                
    
#if defined(STM32L412xx) || defined(STM32L422xx) || defined (STM32L4P5xx) || defined (STM32L4Q5xx)
#define __HAL_RTC_INTERNAL_TIMESTAMP_CLEAR_FLAG(__HANDLE__, __FLAG__)     (__HAL_RTC_CLEAR_FLAG((__HANDLE__), RTC_CLEAR_ITSF))
#else
#define __HAL_RTC_INTERNAL_TIMESTAMP_CLEAR_FLAG(__HANDLE__, __FLAG__)  ((__HANDLE__)->Instance->ISR) = (~((__FLAG__) | RTC_ISR_INIT)|((__HANDLE__)->Instance->ISR & RTC_ISR_INIT))
#endif


#if defined(STM32L412xx) || defined(STM32L422xx) || defined (STM32L4P5xx) || defined (STM32L4Q5xx)
   
                                                         
                                                
                
    
#define __HAL_RTC_TAMPTS_ENABLE(__HANDLE__)                       ((__HANDLE__)->Instance->CR |= (RTC_CR_TAMPTS))

   
                                                          
                                                
                
    
#define __HAL_RTC_TAMPTS_DISABLE(__HANDLE__)                      ((__HANDLE__)->Instance->CR &= ~(RTC_CR_TAMPTS))

   
                                                   
                                                
                
    
#define __HAL_RTC_TAMPOE_ENABLE(__HANDLE__)                       ((__HANDLE__)->Instance->CR |= (RTC_CR_TAMPOE))

   
                                                    
                                                
                
    
#define __HAL_RTC_TAMPOE_DISABLE(__HANDLE__)                      ((__HANDLE__)->Instance->CR &= ~(RTC_CR_TAMPOE))


   
      
    
#endif                                                                                                         

                                                                                
                                               
      
    

   
                                              
                                                
                
    
#define __HAL_RTC_CALIBRATION_OUTPUT_ENABLE(__HANDLE__)               ((__HANDLE__)->Instance->CR |= (RTC_CR_COE))

   
                                           
                                                
                
    
#define __HAL_RTC_CALIBRATION_OUTPUT_DISABLE(__HANDLE__)              ((__HANDLE__)->Instance->CR &= ~(RTC_CR_COE))

   
                                                 
                                                
                
    
#define __HAL_RTC_CLOCKREF_DETECTION_ENABLE(__HANDLE__)               ((__HANDLE__)->Instance->CR |= (RTC_CR_REFCKON))

   
                                                  
                                                
                
    
#define __HAL_RTC_CLOCKREF_DETECTION_DISABLE(__HANDLE__)              ((__HANDLE__)->Instance->CR &= ~(RTC_CR_REFCKON))

   
                                                               
                                                
                                                                              
                                   
                                       
                
    
#if defined(STM32L412xx) || defined(STM32L422xx) || defined (STM32L4P5xx) || defined (STM32L4Q5xx)
#define __HAL_RTC_SHIFT_GET_FLAG(__HANDLE__, __FLAG__)                (__HAL_RTC_GET_FLAG((__HANDLE__), (__FLAG__)))
#else
#define __HAL_RTC_SHIFT_GET_FLAG(__HANDLE__, __FLAG__)         (((((__HANDLE__)->Instance->ISR) & (__FLAG__)) != 0U) ? 1U : 0U)
#endif

   
      
    


                                                                           
                                       
      
    
#if defined(RTC_TAMPER1_SUPPORT)
   
                                                   
                                                
                
    
#if defined(STM32L412xx) || defined(STM32L422xx) || defined (STM32L4P5xx) || defined (STM32L4Q5xx)
#define __HAL_RTC_TAMPER1_ENABLE(__HANDLE__)           (((TAMP_TypeDef *)((uint32_t)((__HANDLE__)->Instance) + (__HANDLE__)->TampOffset))->CR1 |= (TAMP_CR1_TAMP1E))
#else
#define __HAL_RTC_TAMPER1_ENABLE(__HANDLE__)           ((__HANDLE__)->Instance->TAMPCR |= (RTC_TAMPCR_TAMP1E))
#endif

   
                                                    
                                                
                
    
#if defined(STM32L412xx) || defined(STM32L422xx) || defined (STM32L4P5xx) || defined (STM32L4Q5xx)
#define __HAL_RTC_TAMPER1_DISABLE(__HANDLE__)          (((TAMP_TypeDef *)((uint32_t)((__HANDLE__)->Instance) + (__HANDLE__)->TampOffset))->CR1 &= ~(RTC_TAMPCR_TAMP1E))
#else
#define __HAL_RTC_TAMPER1_DISABLE(__HANDLE__)          ((__HANDLE__)->Instance->TAMPCR &= ~(RTC_TAMPCR_TAMP1E))
#endif
#endif                          

   
                                                   
                                                
                
    
#if defined(STM32L412xx) || defined(STM32L422xx) || defined (STM32L4P5xx) || defined (STM32L4Q5xx)
#define __HAL_RTC_TAMPER2_ENABLE(__HANDLE__)           (((TAMP_TypeDef *)((uint32_t)((__HANDLE__)->Instance) + (__HANDLE__)->TampOffset))->CR1 |= (TAMP_CR1_TAMP2E))
#else
#define __HAL_RTC_TAMPER2_ENABLE(__HANDLE__)           ((__HANDLE__)->Instance->TAMPCR |= (RTC_TAMPCR_TAMP2E))
#endif

   
                                                    
                                                
                
    
#if defined(STM32L412xx) || defined(STM32L422xx) || defined (STM32L4P5xx) || defined (STM32L4Q5xx)
#define __HAL_RTC_TAMPER2_DISABLE(__HANDLE__)          (((TAMP_TypeDef *)((uint32_t)((__HANDLE__)->Instance) + (__HANDLE__)->TampOffset))->CR1 &= ~(RTC_TAMPCR_TAMP2E))
#else
#define __HAL_RTC_TAMPER2_DISABLE(__HANDLE__)          ((__HANDLE__)->Instance->TAMPCR &= ~(RTC_TAMPCR_TAMP2E))
#endif

#if defined(RTC_TAMPER3_SUPPORT)
   
                                                   
                                                
                
    
#define __HAL_RTC_TAMPER3_ENABLE(__HANDLE__)                         ((__HANDLE__)->Instance->TAMPCR |= (RTC_TAMPCR_TAMP3E))

   
                                                    
                                                
                
    
#define __HAL_RTC_TAMPER3_DISABLE(__HANDLE__)                        ((__HANDLE__)->Instance->TAMPCR &= ~(RTC_TAMPCR_TAMP3E))
#endif                          

                                                                                                    
   
                                             
                                                
                                                                                   
                                                                           
                                                            
                                                     
                                                     
                                                     
                
    
#if defined(STM32L412xx) || defined(STM32L422xx) || defined (STM32L4P5xx) || defined (STM32L4Q5xx)
#define __HAL_RTC_TAMPER_ENABLE_IT(__HANDLE__, __INTERRUPT__)        (((TAMP_TypeDef *)((uint32_t)((__HANDLE__)->Instance) + (__HANDLE__)->TampOffset))->IER |= (__INTERRUPT__))
#else
#define __HAL_RTC_TAMPER_ENABLE_IT(__HANDLE__, __INTERRUPT__)        ((__HANDLE__)->Instance->TAMPCR |= (__INTERRUPT__))
#endif
   
                                              
                                                
                                                                                    
                                                                          
                                                           
                                                    
                                                    
                                                    
                
    
#if defined(STM32L412xx) || defined(STM32L422xx) || defined (STM32L4P5xx) || defined (STM32L4Q5xx)
#define __HAL_RTC_TAMPER_DISABLE_IT(__HANDLE__, __INTERRUPT__)       (((TAMP_TypeDef *)((uint32_t)((__HANDLE__)->Instance) + (__HANDLE__)->TampOffset))->IER &= ~(__INTERRUPT__))
#else
#define __HAL_RTC_TAMPER_DISABLE_IT(__HANDLE__, __INTERRUPT__)       ((__HANDLE__)->Instance->TAMPCR &= ~(__INTERRUPT__))
#endif


                                                                                                    
   
                                                                                 
                                                
                                                                      
                                  
                                                           
                                                    
                                                    
                                                    
                
    
#if defined(STM32L412xx) || defined(STM32L422xx) || defined (STM32L4P5xx) || defined (STM32L4Q5xx)
#define __HAL_RTC_TAMPER_GET_IT(__HANDLE__, __INTERRUPT__)     ((((((TAMP_TypeDef *)((uint32_t)((__HANDLE__)->Instance) + (__HANDLE__)->TampOffset))->MISR) & (__INTERRUPT__)) != 0U) ? 1U : 0U)
#else                                                                                                         
#define __HAL_RTC_TAMPER_GET_IT(__HANDLE__, __INTERRUPT__)     (((((__HANDLE__)->Instance->ISR) & (__INTERRUPT__)) != 0U) ? 1U : 0U)
#endif                                                                                                         
   
                                                                                     
                                                
                                                                             
                                  
                                                           
                                                    
                                                    
                                                    
                
    
#if defined(STM32L412xx) || defined(STM32L422xx) || defined (STM32L4P5xx) || defined (STM32L4Q5xx)
#define __HAL_RTC_TAMPER_GET_IT_SOURCE(__HANDLE__, __INTERRUPT__)    ((((((TAMP_TypeDef *)((uint32_t)((__HANDLE__)->Instance) + (__HANDLE__)->TampOffset))->IER) & (__INTERRUPT__)) != 0U) ? 1U : 0U)
#else
#define __HAL_RTC_TAMPER_GET_IT_SOURCE(__HANDLE__, __INTERRUPT__)    (((((__HANDLE__)->Instance->TAMPCR) & (__INTERRUPT__)) != 0U) ? 1U : 0U)
#endif

   
                                                      
                                                
                                                                     
                                   
                                                  
                                                  
                                                  
                
    
#if defined(STM32L412xx) || defined(STM32L422xx) || defined (STM32L4P5xx) || defined (STM32L4Q5xx)
#define __HAL_RTC_TAMPER_GET_FLAG(__HANDLE__, __FLAG__)        (((((TAMP_TypeDef *)((uint32_t)((__HANDLE__)->Instance) + (__HANDLE__)->TampOffset))->SR) & (__FLAG__)) != 0U)
#else
#define __HAL_RTC_TAMPER_GET_FLAG(__HANDLE__, __FLAG__)        (((((__HANDLE__)->Instance->ISR) & (__FLAG__)) != 0U) ? 1U : 0U)
#endif
   
                                                 
                                                
                                                            
                                   
                                                  
                                                  
                                                  
                
    
#if defined(STM32L412xx) || defined(STM32L422xx) || defined (STM32L4P5xx) || defined (STM32L4Q5xx)
#define __HAL_RTC_TAMPER_CLEAR_FLAG(__HANDLE__, __FLAG__)      ((((TAMP_TypeDef *)((uint32_t)((__HANDLE__)->Instance) + (__HANDLE__)->TampOffset))->SCR) = (__FLAG__))
#else
#define __HAL_RTC_TAMPER_CLEAR_FLAG(__HANDLE__, __FLAG__)      ((__HANDLE__)->Instance->ISR) = (~((__FLAG__) | RTC_ISR_INIT)|((__HANDLE__)->Instance->ISR & RTC_ISR_INIT))
#endif

   
                                                                                  
                
    
#define __HAL_RTC_TAMPER_TIMESTAMP_EXTI_ENABLE_IT()        (EXTI->IMR1 |= RTC_EXTI_LINE_TAMPER_TIMESTAMP_EVENT)

   
                                                                                   
                
    
#define __HAL_RTC_TAMPER_TIMESTAMP_EXTI_DISABLE_IT()       (EXTI->IMR1 &= ~(RTC_EXTI_LINE_TAMPER_TIMESTAMP_EVENT))

   
                                                                              
                
    
#define __HAL_RTC_TAMPER_TIMESTAMP_EXTI_ENABLE_EVENT()    (EXTI->EMR1 |= RTC_EXTI_LINE_TAMPER_TIMESTAMP_EVENT)

   
                                                                               
                
    
#define __HAL_RTC_TAMPER_TIMESTAMP_EXTI_DISABLE_EVENT()   (EXTI->EMR1 &= ~(RTC_EXTI_LINE_TAMPER_TIMESTAMP_EVENT))

   
                                                                                             
                
    
#define __HAL_RTC_TAMPER_TIMESTAMP_EXTI_ENABLE_FALLING_EDGE()   (EXTI->FTSR1 |= RTC_EXTI_LINE_TAMPER_TIMESTAMP_EVENT)

   
                                                                                              
                
    
#define __HAL_RTC_TAMPER_TIMESTAMP_EXTI_DISABLE_FALLING_EDGE()  (EXTI->FTSR1 &= ~(RTC_EXTI_LINE_TAMPER_TIMESTAMP_EVENT))

   
                                                                                            
                
    
#define __HAL_RTC_TAMPER_TIMESTAMP_EXTI_ENABLE_RISING_EDGE()    (EXTI->RTSR1 |= RTC_EXTI_LINE_TAMPER_TIMESTAMP_EVENT)

   
                                                                                             
                
    
#define __HAL_RTC_TAMPER_TIMESTAMP_EXTI_DISABLE_RISING_EDGE()   (EXTI->RTSR1 &= ~(RTC_EXTI_LINE_TAMPER_TIMESTAMP_EVENT))

   
                                                                                                      
                
    
#define __HAL_RTC_TAMPER_TIMESTAMP_EXTI_ENABLE_RISING_FALLING_EDGE()  do { \
                                                                        __HAL_RTC_TAMPER_TIMESTAMP_EXTI_ENABLE_RISING_EDGE();  \
                                                                        __HAL_RTC_TAMPER_TIMESTAMP_EXTI_ENABLE_FALLING_EDGE(); \
                                                                      } while(0)

   
                                                                                                       
                
    
#define __HAL_RTC_TAMPER_TIMESTAMP_EXTI_DISABLE_RISING_FALLING_EDGE()  do { \
                                                                        __HAL_RTC_TAMPER_TIMESTAMP_EXTI_DISABLE_RISING_EDGE();  \
                                                                        __HAL_RTC_TAMPER_TIMESTAMP_EXTI_DISABLE_FALLING_EDGE(); \
                                                                       } while(0)

   
                                                                                                        
                        
    
#define __HAL_RTC_TAMPER_TIMESTAMP_EXTI_GET_FLAG()         (EXTI->PR1 & RTC_EXTI_LINE_TAMPER_TIMESTAMP_EVENT)

   
                                                                        
                
    
#define __HAL_RTC_TAMPER_TIMESTAMP_EXTI_CLEAR_FLAG()       (EXTI->PR1 = RTC_EXTI_LINE_TAMPER_TIMESTAMP_EVENT)

   
                                                                                             
                
    
#define __HAL_RTC_TAMPER_TIMESTAMP_EXTI_GENERATE_SWIT()    (EXTI->SWIER1 |= RTC_EXTI_LINE_TAMPER_TIMESTAMP_EVENT)

   
      
    

#if defined (STM32L4P5xx) || defined (STM32L4Q5xx)
                                                                                      
                                                   
      
    

   
                                          
                                                
                                                                                 
                                  
                                                   
                
    
#define __HAL_RTC_SSRU_ENABLE_IT(__HANDLE__, __INTERRUPT__)    (RTC->CR |= (__INTERRUPT__))

   
                                           
                                                
                                                                                  
                                  
                                                   
                
    
#define __HAL_RTC_SSRU_DISABLE_IT(__HANDLE__, __INTERRUPT__)   (RTC->CR &= ~(__INTERRUPT__))


   
                                                                               
                                                
                                                                    
                                  
                                                    
                
    
#define __HAL_RTC_SSRU_GET_IT(__HANDLE__, __INTERRUPT__)       ((((RTC->MISR) & ((__INTERRUPT__) >> 1) != 0U) ? 1U : 0U)
   
                                                                                            
                                                
                                                                                     
                                  
                                                    
                
    
#define __HAL_RTC_SSRU_GET_IT_SOURCE(__HANDLE__, __INTERRUPT__)   ((((RTC->CR) & (__INTERRUPT__)) != 0U) ? 1U : 0U)

   
                                                    
                                                
                                                                   
                                   
                                        
                                         
                
    
#define __HAL_RTC_SSRU_GET_FLAG(__HANDLE__, __FLAG__)   (__HAL_RTC_GET_FLAG((__HANDLE__), (__FLAG__)))

   
                                                        
                                                
                                                          
                                  
                                       
                
    
#define __HAL_RTC_SSRU_CLEAR_FLAG(__HANDLE__, __FLAG__)     (__HAL_RTC_CLEAR_FLAG((__HANDLE__), RTC_CLEAR_SSRUF))

                        
                        
   
                                                                           
                
    
#define __HAL_RTC_SSRU_EXTI_ENABLE_IT()       (EXTI->IMR1 |= RTC_EXTI_LINE_SSRU_EVENT)

   
                                                                            
                
    
#define __HAL_RTC_SSRU_EXTI_DISABLE_IT()      (EXTI->IMR1 &= ~(RTC_EXTI_LINE_SSRU_EVENT))

   
                                                                       
                
    
#define __HAL_RTC_SSRU_EXTI_ENABLE_EVENT()    (EXTI->EMR1 |= RTC_EXTI_LINE_SSRU_EVENT)

   
                                                                        
                
    
#define __HAL_RTC_SSRU_EXTI_DISABLE_EVENT()   (EXTI->EMR1 &= ~(RTC_EXTI_LINE_SSRU_EVENT))

   
      
    

#endif                                                         

   
      
    

                                                                                

                                                               
      
    

                                                                                
                                                                                
                                                                                

                                                                                

                                                                              
      
    
HAL_StatusTypeDef HAL_RTCEx_SetTimeStamp(RTC_HandleTypeDef *hrtc, uint32_t TimeStampEdge, uint32_t RTC_TimeStampPin);
HAL_StatusTypeDef HAL_RTCEx_SetTimeStamp_IT(RTC_HandleTypeDef *hrtc, uint32_t TimeStampEdge, uint32_t RTC_TimeStampPin);
HAL_StatusTypeDef HAL_RTCEx_DeactivateTimeStamp(RTC_HandleTypeDef *hrtc);
HAL_StatusTypeDef HAL_RTCEx_SetInternalTimeStamp(RTC_HandleTypeDef *hrtc);
HAL_StatusTypeDef HAL_RTCEx_DeactivateInternalTimeStamp(RTC_HandleTypeDef *hrtc);
HAL_StatusTypeDef HAL_RTCEx_GetTimeStamp(RTC_HandleTypeDef *hrtc, RTC_TimeTypeDef *sTimeStamp, RTC_DateTypeDef *sTimeStampDate, uint32_t Format);
void              HAL_RTCEx_TamperTimeStampIRQHandler(RTC_HandleTypeDef *hrtc);
void              HAL_RTCEx_TimeStampEventCallback(RTC_HandleTypeDef *hrtc);
HAL_StatusTypeDef HAL_RTCEx_PollForTimeStampEvent(RTC_HandleTypeDef *hrtc, uint32_t Timeout);
   
      
    

                                                                                
                                                                                
                                                                                

                                                                                

                                                                            
     
   
HAL_StatusTypeDef HAL_RTCEx_SetWakeUpTimer(RTC_HandleTypeDef *hrtc, uint32_t WakeUpCounter, uint32_t WakeUpClock);
#if defined(STM32L412xx) || defined(STM32L422xx) || defined (STM32L4P5xx) || defined (STM32L4Q5xx)
HAL_StatusTypeDef HAL_RTCEx_SetWakeUpTimer_IT(RTC_HandleTypeDef *hrtc, uint32_t WakeUpCounter, uint32_t WakeUpClock, uint32_t WakeUpAutoClr);
#else
HAL_StatusTypeDef HAL_RTCEx_SetWakeUpTimer_IT(RTC_HandleTypeDef *hrtc, uint32_t WakeUpCounter, uint32_t WakeUpClock);
#endif
HAL_StatusTypeDef HAL_RTCEx_DeactivateWakeUpTimer(RTC_HandleTypeDef *hrtc);
uint32_t          HAL_RTCEx_GetWakeUpTimer(RTC_HandleTypeDef *hrtc);
void              HAL_RTCEx_WakeUpTimerIRQHandler(RTC_HandleTypeDef *hrtc);
void              HAL_RTCEx_WakeUpTimerEventCallback(RTC_HandleTypeDef *hrtc);
HAL_StatusTypeDef HAL_RTCEx_PollForWakeUpTimerEvent(RTC_HandleTypeDef *hrtc, uint32_t Timeout);
   
      
    

                                                                                
                                                                                
                                                                                

                                                                                

                                                                                   
     
   
HAL_StatusTypeDef HAL_RTCEx_SetSmoothCalib(RTC_HandleTypeDef *hrtc, uint32_t SmoothCalibPeriod, uint32_t SmoothCalibPlusPulses, uint32_t SmoothCalibMinusPulsesValue);
#if defined(STM32L412xx) || defined(STM32L422xx) || defined (STM32L4P5xx) || defined (STM32L4Q5xx)
HAL_StatusTypeDef HAL_RTCEx_SetLowPowerCalib(RTC_HandleTypeDef *hrtc, uint32_t LowPowerCalib);
#endif
HAL_StatusTypeDef HAL_RTCEx_SetSynchroShift(RTC_HandleTypeDef *hrtc, uint32_t ShiftAdd1S, uint32_t ShiftSubFS);
HAL_StatusTypeDef HAL_RTCEx_SetCalibrationOutPut(RTC_HandleTypeDef *hrtc, uint32_t CalibOutput);
HAL_StatusTypeDef HAL_RTCEx_DeactivateCalibrationOutPut(RTC_HandleTypeDef *hrtc);
HAL_StatusTypeDef HAL_RTCEx_SetRefClock(RTC_HandleTypeDef *hrtc);
HAL_StatusTypeDef HAL_RTCEx_DeactivateRefClock(RTC_HandleTypeDef *hrtc);
HAL_StatusTypeDef HAL_RTCEx_EnableBypassShadow(RTC_HandleTypeDef *hrtc);
HAL_StatusTypeDef HAL_RTCEx_DisableBypassShadow(RTC_HandleTypeDef *hrtc);
#if defined (STM32L4P5xx) || defined (STM32L4Q5xx)
HAL_StatusTypeDef HAL_RTCEx_SetSSRU_IT(RTC_HandleTypeDef *hrtc);
HAL_StatusTypeDef HAL_RTCEx_DeactivateSSRU(RTC_HandleTypeDef *hrtc);
void              HAL_RTCEx_SSRUIRQHandler(RTC_HandleTypeDef *hrtc);
void              HAL_RTCEx_SSRUEventCallback(RTC_HandleTypeDef *hrtc);
#endif
   
      
    

                                                                               
                                                                         
      
    

void              HAL_RTCEx_AlarmBEventCallback(RTC_HandleTypeDef *hrtc);
HAL_StatusTypeDef HAL_RTCEx_PollForAlarmBEvent(RTC_HandleTypeDef *hrtc, uint32_t Timeout);
   
      
    

                                                                           
      
    
HAL_StatusTypeDef HAL_RTCEx_SetTamper(RTC_HandleTypeDef *hrtc, RTC_TamperTypeDef *sTamper);
HAL_StatusTypeDef HAL_RTCEx_SetTamper_IT(RTC_HandleTypeDef *hrtc, RTC_TamperTypeDef *sTamper);
HAL_StatusTypeDef HAL_RTCEx_DeactivateTamper(RTC_HandleTypeDef *hrtc, uint32_t Tamper);

#if defined(RTC_TAMPER1_SUPPORT)
HAL_StatusTypeDef HAL_RTCEx_PollForTamper1Event(RTC_HandleTypeDef *hrtc, uint32_t Timeout);
#endif                          
HAL_StatusTypeDef HAL_RTCEx_PollForTamper2Event(RTC_HandleTypeDef *hrtc, uint32_t Timeout);
#if defined(RTC_TAMPER3_SUPPORT)
HAL_StatusTypeDef HAL_RTCEx_PollForTamper3Event(RTC_HandleTypeDef *hrtc, uint32_t Timeout);
#endif                          

#if defined(RTC_TAMPER1_SUPPORT)
void              HAL_RTCEx_Tamper1EventCallback(RTC_HandleTypeDef *hrtc);
#endif                          
void              HAL_RTCEx_Tamper2EventCallback(RTC_HandleTypeDef *hrtc);
#if defined(RTC_TAMPER3_SUPPORT)
void              HAL_RTCEx_Tamper3EventCallback(RTC_HandleTypeDef *hrtc);
#endif                          


   
      
    

                                                                                    
     
   
void              HAL_RTCEx_BKUPWrite(RTC_HandleTypeDef *hrtc, uint32_t BackupRegister, uint32_t Data);
uint32_t          HAL_RTCEx_BKUPRead(RTC_HandleTypeDef *hrtc, uint32_t BackupRegister);
   
      
    

   
      
    

                                                                                
                                                                                
                                                                                
                                                             
      
    
#if defined (STM32L4P5xx) || defined (STM32L4Q5xx)
#define RTC_EXTI_LINE_SSRU_EVENT              EXTI_IMR1_IM18                                                                              
#endif

#define RTC_EXTI_LINE_TAMPER_TIMESTAMP_EVENT  EXTI_IMR1_IM19                                                                                      

#define RTC_EXTI_LINE_WAKEUPTIMER_EVENT       EXTI_IMR1_IM20                                                                      

   
      
    

                                                                                
                                                       
      
    

                                                                               
      
    
#define IS_TIMESTAMP_EDGE(EDGE) (((EDGE) == RTC_TIMESTAMPEDGE_RISING) || \
                                 ((EDGE) == RTC_TIMESTAMPEDGE_FALLING))

#define IS_RTC_TAMPER_INTERRUPT(INTERRUPT) ((((INTERRUPT) & 0xFFB6FFFBU) == 0x00U) && ((INTERRUPT) != 0U))

#define IS_RTC_TIMESTAMP_PIN(PIN)  (((PIN) == RTC_TIMESTAMPPIN_DEFAULT))

#define IS_RTC_WAKEUP_CLOCK(CLOCK) (((CLOCK) == RTC_WAKEUPCLOCK_RTCCLK_DIV16)   || \
                                    ((CLOCK) == RTC_WAKEUPCLOCK_RTCCLK_DIV8)    || \
                                    ((CLOCK) == RTC_WAKEUPCLOCK_RTCCLK_DIV4)    || \
                                    ((CLOCK) == RTC_WAKEUPCLOCK_RTCCLK_DIV2)    || \
                                    ((CLOCK) == RTC_WAKEUPCLOCK_CK_SPRE_16BITS) || \
                                    ((CLOCK) == RTC_WAKEUPCLOCK_CK_SPRE_17BITS))

#define IS_RTC_WAKEUP_COUNTER(COUNTER)  ((COUNTER) <= RTC_WUTR_WUT)

#define IS_RTC_SMOOTH_CALIB_PERIOD(PERIOD) (((PERIOD) == RTC_SMOOTHCALIB_PERIOD_32SEC) || \
                                            ((PERIOD) == RTC_SMOOTHCALIB_PERIOD_16SEC) || \
                                            ((PERIOD) == RTC_SMOOTHCALIB_PERIOD_8SEC))

#define IS_RTC_SMOOTH_CALIB_PLUS(PLUS) (((PLUS) == RTC_SMOOTHCALIB_PLUSPULSES_SET) || \
                                        ((PLUS) == RTC_SMOOTHCALIB_PLUSPULSES_RESET))

#define IS_RTC_SMOOTH_CALIB_MINUS(VALUE) ((VALUE) <= RTC_CALR_CALM)

#if defined(STM32L412xx) || defined(STM32L422xx) || defined (STM32L4P5xx) || defined (STM32L4Q5xx)
#define IS_RTC_LOW_POWER_CALIB(LPCAL) (((LPCAL) == RTC_LPCAL_SET) || \
                                       ((LPCAL) == RTC_LPCAL_RESET))
#endif

#if defined(STM32L412xx) || defined(STM32L422xx) || defined (STM32L4P5xx) || defined (STM32L4Q5xx)
#define IS_RTC_TAMPER(__TAMPER__)                ((((__TAMPER__) & RTC_TAMPER_ALL) != 0x00U) && \
                                                  (((__TAMPER__) & ~RTC_TAMPER_ALL) == 0x00U))
#else
#define IS_RTC_TAMPER(TAMPER) ((((TAMPER) & 0xFFFFFFD6U) == 0x00U) && ((TAMPER) != 0U))
#endif


#define IS_RTC_TAMPER_TRIGGER(__TRIGGER__)       (((__TRIGGER__) == RTC_TAMPERTRIGGER_RISINGEDGE)  || \
                                                  ((__TRIGGER__) == RTC_TAMPERTRIGGER_FALLINGEDGE) || \
                                                  ((__TRIGGER__) == RTC_TAMPERTRIGGER_LOWLEVEL)    || \
                                                  ((__TRIGGER__) == RTC_TAMPERTRIGGER_HIGHLEVEL))

#define IS_RTC_TAMPER_ERASE_MODE(__MODE__)       (((__MODE__) == RTC_TAMPER_ERASE_BACKUP_ENABLE) || \
                                                  ((__MODE__) == RTC_TAMPER_ERASE_BACKUP_DISABLE))

#define IS_RTC_TAMPER_MASKFLAG_STATE(__STATE__)  (((__STATE__) == RTC_TAMPERMASK_FLAG_ENABLE) || \
                                                  ((__STATE__) == RTC_TAMPERMASK_FLAG_DISABLE))

#define IS_RTC_TAMPER_FILTER(__FILTER__)         (((__FILTER__) == RTC_TAMPERFILTER_DISABLE)  || \
                                                  ((__FILTER__) == RTC_TAMPERFILTER_2SAMPLE) || \
                                                  ((__FILTER__) == RTC_TAMPERFILTER_4SAMPLE) || \
                                                  ((__FILTER__) == RTC_TAMPERFILTER_8SAMPLE))

#define IS_RTC_TAMPER_SAMPLING_FREQ(__FREQ__)    (((__FREQ__) == RTC_TAMPERSAMPLINGFREQ_RTCCLK_DIV32768)|| \
                                                  ((__FREQ__) == RTC_TAMPERSAMPLINGFREQ_RTCCLK_DIV16384)|| \
                                                  ((__FREQ__) == RTC_TAMPERSAMPLINGFREQ_RTCCLK_DIV8192) || \
                                                  ((__FREQ__) == RTC_TAMPERSAMPLINGFREQ_RTCCLK_DIV4096) || \
                                                  ((__FREQ__) == RTC_TAMPERSAMPLINGFREQ_RTCCLK_DIV2048) || \
                                                  ((__FREQ__) == RTC_TAMPERSAMPLINGFREQ_RTCCLK_DIV1024) || \
                                                  ((__FREQ__) == RTC_TAMPERSAMPLINGFREQ_RTCCLK_DIV512)  || \
                                                  ((__FREQ__) == RTC_TAMPERSAMPLINGFREQ_RTCCLK_DIV256))

#define IS_RTC_TAMPER_PRECHARGE_DURATION(__DURATION__)   (((__DURATION__) == RTC_TAMPERPRECHARGEDURATION_1RTCCLK) || \
                                                          ((__DURATION__) == RTC_TAMPERPRECHARGEDURATION_2RTCCLK) || \
                                                          ((__DURATION__) == RTC_TAMPERPRECHARGEDURATION_4RTCCLK) || \
                                                          ((__DURATION__) == RTC_TAMPERPRECHARGEDURATION_8RTCCLK))

#define IS_RTC_TAMPER_PULLUP_STATE(__STATE__)    (((__STATE__) == RTC_TAMPER_PULLUP_ENABLE) || \
                                                  ((__STATE__) == RTC_TAMPER_PULLUP_DISABLE))

#define IS_RTC_TAMPER_TIMESTAMPONTAMPER_DETECTION(DETECTION) (((DETECTION) == RTC_TIMESTAMPONTAMPERDETECTION_ENABLE) || \
                                                              ((DETECTION) == RTC_TIMESTAMPONTAMPERDETECTION_DISABLE))

#define IS_RTC_BKP(__BKP__)   ((__BKP__) < RTC_BKP_NUMBER)

#define IS_RTC_SHIFT_ADD1S(SEL) (((SEL) == RTC_SHIFTADD1S_RESET) || \
                                 ((SEL) == RTC_SHIFTADD1S_SET))

#define IS_RTC_SHIFT_SUBFS(FS) ((FS) <= RTC_SHIFTR_SUBFS)

#define IS_RTC_CALIB_OUTPUT(OUTPUT)  (((OUTPUT) == RTC_CALIBOUTPUT_512HZ) || \
                                      ((OUTPUT) == RTC_CALIBOUTPUT_1HZ))

#if defined (STM32L4P5xx) || defined (STM32L4Q5xx)
#define IS_RTC_BINARY_MODE(MODE) (((MODE) == RTC_BINARY_NONE) || \
                                  ((MODE) == RTC_BINARY_ONLY) || \
                                   ((MODE) == RTC_BINARY_MIX ))

#define IS_RTC_BINARY_MIX_BCDU(BDCU) (((BDCU) == RTC_BINARY_MIX_BCDU_0) || \
                                      ((BDCU) == RTC_BINARY_MIX_BCDU_1) || \
                                      ((BDCU) == RTC_BINARY_MIX_BCDU_2) || \
                                      ((BDCU) == RTC_BINARY_MIX_BCDU_3) || \
                                      ((BDCU) == RTC_BINARY_MIX_BCDU_4) || \
                                      ((BDCU) == RTC_BINARY_MIX_BCDU_5) || \
                                      ((BDCU) == RTC_BINARY_MIX_BCDU_6) || \
                                      ((BDCU) == RTC_BINARY_MIX_BCDU_7))

#define IS_RTC_ALARM_SUB_SECOND_BINARY_MASK(MASK)   (((MASK) == 0U) || \
                                                    (((MASK) >= RTC_ALARMSUBSECONDBINMASK_SS31_1) && ((MASK) <= RTC_ALARMSUBSECONDBINMASK_NONE)))

#define IS_RTC_ALARMSUBSECONDBIN_AUTOCLR(SEL) (((SEL) == RTC_ALARMSUBSECONDBIN_AUTOCLR_NO) || \
                                               ((SEL) == RTC_ALARMSUBSECONDBIN_AUTOCLR_YES))
#endif                                                         
   
      
    

   
      
    

   
      
    

   
      
    

#ifdef __cplusplus
}
#endif                  

#endif                             
