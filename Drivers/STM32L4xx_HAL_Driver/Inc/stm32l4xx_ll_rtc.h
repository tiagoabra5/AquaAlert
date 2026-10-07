/**
  ******************************************************************************
  * @file    stm32l4xx_ll_rtc.h
  * @author  MCD Application Team
  * @brief   Header file of RTC LL module.
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

                                                                                
#ifndef STM32L4xx_LL_RTC_H
#define STM32L4xx_LL_RTC_H

#ifdef __cplusplus
extern "C" {
#endif

                                                                                
#include "stm32l4xx.h"

                                   
      
    

#if defined(RTC)

                        
      
    

                                                                                
                                                                                
                                                                                
                                                            
      
    
                      
#define RTC_LL_INIT_MASK              0xFFFFFFFFU
#define RTC_LL_RSF_MASK               0xFFFFFF5FU

                              
#define RTC_WRITE_PROTECTION_DISABLE  0xFFU
#define RTC_WRITE_PROTECTION_ENABLE_1 0xCAU
#define RTC_WRITE_PROTECTION_ENABLE_2 0x53U

                                         
#define RTC_OFFSET_WEEKDAY            24U
#define RTC_OFFSET_DAY                16U
#define RTC_OFFSET_MONTH              8U
#define RTC_OFFSET_HOUR               16U
#define RTC_OFFSET_MINUTE             8U

   
      
    

                                                                                
#if defined(USE_FULL_LL_DRIVER)
                                                      
      
    
   
      
    
#endif                       

                                                                                
#if defined(USE_FULL_LL_DRIVER)
                                                        
      
    

   
                                          
    
typedef struct
{
  uint32_t HourFormat;                                       
                                                                                        

                                                                                            
                                                             

  uint32_t AsynchPrescaler;                                                      
                                                                                                         

                                                                                            
                                                                  

  uint32_t SynchPrescaler;                                                      
                                                                                                           

                                                                                            
                                                                 
} LL_RTC_InitTypeDef;

   
                                         
    
typedef struct
{
  uint32_t TimeFormat;                                   
                                                                                       

                                                                                                                           

  uint8_t Hours;                                         
                                                                                                                                                 
                                                                                                                                                       

                                                                                                                         

  uint8_t Minutes;                                         
                                                                                                  

                                                                                                                           

  uint8_t Seconds;                                         
                                                                                                  

                                                                                                                           
} LL_RTC_TimeTypeDef;

   
                                         
    
typedef struct
{
  uint8_t WeekDay;                                      
                                                                                

                                                                                                                         

  uint8_t Month;                                      
                                                                              

                                                                                                                       

  uint8_t Day;                                      
                                                                                               

                                                                                                                     

  uint8_t Year;                                      
                                                                                               

                                                                                                                      
} LL_RTC_DateTypeDef;

   
                                          
    
typedef struct
{
  LL_RTC_TimeTypeDef AlarmTime;                                               

  uint32_t AlarmMask;                                               
                                                                                                                                                    

                                                                                                                                           
                                                                               
                                   

  uint32_t AlarmDateWeekDaySel;                                                    
                                                                                                                                                                             

                                                                                                                                                                          
                                                                                                                                      
                                   

  uint8_t AlarmDateWeekDay;                                               
                                                                                                                                                 

                                                                                                                              
                                                                                           

                                                                                                                                     

                                                                                                                                  
                                                                                               
                                   
} LL_RTC_AlarmTypeDef;

   
      
    
#endif                         

                                                                                
                                                              
      
    

#if defined(USE_FULL_LL_DRIVER)
                                     
      
    
#define LL_RTC_FORMAT_BIN                  0x00000000U                           
#define LL_RTC_FORMAT_BCD                  0x00000001U                        
   
      
    

                                                                       
      
    
#define LL_RTC_ALMA_DATEWEEKDAYSEL_DATE    0x00000000U                                             
#define LL_RTC_ALMA_DATEWEEKDAYSEL_WEEKDAY RTC_ALRMAR_WDSEL                                           
   
      
    

                                                                       
      
    
#define LL_RTC_ALMB_DATEWEEKDAYSEL_DATE    0x00000000U                                             
#define LL_RTC_ALMB_DATEWEEKDAYSEL_WEEKDAY RTC_ALRMBR_WDSEL                                           
   
      
    

#endif                         

                                                  
                                                                          
      
    
#if defined(STM32L412xx) || defined(STM32L422xx) || defined (STM32L4P5xx) || defined (STM32L4Q5xx)
#define LL_RTC_SCR_ITSF                    RTC_SCR_CITSF
#define LL_RTC_SCR_TSOVF                   RTC_SCR_CTSOVF
#define LL_RTC_SCR_TSF                     RTC_SCR_CTSF
#define LL_RTC_SCR_WUTF                    RTC_SCR_CWUTF
#define LL_RTC_SCR_ALRBF                   RTC_SCR_CALRBF
#define LL_RTC_SCR_ALRAF                   RTC_SCR_CALRAF

#define LL_RTC_ICSR_RECALPF                RTC_ICSR_RECALPF
#define LL_RTC_ICSR_INITF                  RTC_ICSR_INITF
#define LL_RTC_ICSR_RSF                    RTC_ICSR_RSF
#define LL_RTC_ICSR_INITS                  RTC_ICSR_INITS
#define LL_RTC_ICSR_SHPF                   RTC_ICSR_SHPF
#define LL_RTC_ICSR_WUTWF                  RTC_ICSR_WUTWF
#else                                                                                                         
#define LL_RTC_ISR_ITSF                    RTC_ISR_ITSF
#define LL_RTC_ISR_RECALPF                 RTC_ISR_RECALPF
#define LL_RTC_ISR_TAMP3F                  RTC_ISR_TAMP3F
#define LL_RTC_ISR_TAMP2F                  RTC_ISR_TAMP2F
#define LL_RTC_ISR_TAMP1F                  RTC_ISR_TAMP1F
#define LL_RTC_ISR_TSOVF                   RTC_ISR_TSOVF
#define LL_RTC_ISR_TSF                     RTC_ISR_TSF
#define LL_RTC_ISR_WUTF                    RTC_ISR_WUTF
#define LL_RTC_ISR_ALRBF                   RTC_ISR_ALRBF
#define LL_RTC_ISR_ALRAF                   RTC_ISR_ALRAF
#define LL_RTC_ISR_INITF                   RTC_ISR_INITF
#define LL_RTC_ISR_RSF                     RTC_ISR_RSF
#define LL_RTC_ISR_INITS                   RTC_ISR_INITS
#define LL_RTC_ISR_SHPF                    RTC_ISR_SHPF
#define LL_RTC_ISR_WUTWF                   RTC_ISR_WUTWF
#define LL_RTC_ISR_ALRBWF                  RTC_ISR_ALRBWF
#define LL_RTC_ISR_ALRAWF                  RTC_ISR_ALRAWF
#endif                                                                                                         
   
      
    

                                     
                                                                                             
      
    
#define LL_RTC_CR_TSIE                     RTC_CR_TSIE
#define LL_RTC_CR_WUTIE                    RTC_CR_WUTIE
#define LL_RTC_CR_ALRBIE                   RTC_CR_ALRBIE
#define LL_RTC_CR_ALRAIE                   RTC_CR_ALRAIE
#if defined(STM32L412xx) || defined(STM32L422xx) || defined (STM32L4P5xx) || defined (STM32L4Q5xx)
#else                                                                                                         
#define LL_RTC_TAMPCR_TAMP3IE              RTC_TAMPCR_TAMP3IE
#define LL_RTC_TAMPCR_TAMP2IE              RTC_TAMPCR_TAMP2IE
#define LL_RTC_TAMPCR_TAMP1IE              RTC_TAMPCR_TAMP1IE
#define LL_RTC_TAMPCR_TAMPIE               RTC_TAMPCR_TAMPIE
#endif                                                                                                         
   
      
    

                                         
      
    
#define LL_RTC_WEEKDAY_MONDAY              (uint8_t)0x01                  
#define LL_RTC_WEEKDAY_TUESDAY             (uint8_t)0x02                  
#define LL_RTC_WEEKDAY_WEDNESDAY           (uint8_t)0x03                  
#define LL_RTC_WEEKDAY_THURSDAY            (uint8_t)0x04                  
#define LL_RTC_WEEKDAY_FRIDAY              (uint8_t)0x05                  
#define LL_RTC_WEEKDAY_SATURDAY            (uint8_t)0x06                  
#define LL_RTC_WEEKDAY_SUNDAY              (uint8_t)0x07                  
   
      
    

                                    
      
    
#define LL_RTC_MONTH_JANUARY               (uint8_t)0x01                   
#define LL_RTC_MONTH_FEBRUARY              (uint8_t)0x02                   
#define LL_RTC_MONTH_MARCH                 (uint8_t)0x03                   
#define LL_RTC_MONTH_APRIL                 (uint8_t)0x04                   
#define LL_RTC_MONTH_MAY                   (uint8_t)0x05                   
#define LL_RTC_MONTH_JUNE                  (uint8_t)0x06                   
#define LL_RTC_MONTH_JULY                  (uint8_t)0x07                   
#define LL_RTC_MONTH_AUGUST                (uint8_t)0x08                   
#define LL_RTC_MONTH_SEPTEMBER             (uint8_t)0x09                   
#define LL_RTC_MONTH_OCTOBER               (uint8_t)0x10                   
#define LL_RTC_MONTH_NOVEMBER              (uint8_t)0x11                   
#define LL_RTC_MONTH_DECEMBER              (uint8_t)0x12                   
   
      
    

                                               
      
    
#define LL_RTC_HOURFORMAT_24HOUR           0x00000000U                                     
#define LL_RTC_HOURFORMAT_AMPM             RTC_CR_FMT                                     
   
      
    

                                              
      
    
#define LL_RTC_ALARMOUT_DISABLE            0x00000000U                                    
#define LL_RTC_ALARMOUT_ALMA               RTC_CR_OSEL_0                                         
#define LL_RTC_ALARMOUT_ALMB               RTC_CR_OSEL_1                                         
#define LL_RTC_ALARMOUT_WAKEUP             RTC_CR_OSEL                                          
   
      
    

                                                           
      
    
#if defined(STM32L412xx) || defined(STM32L422xx) || defined (STM32L4P5xx) || defined (STM32L4Q5xx)
#define LL_RTC_ALARM_OUTPUTTYPE_OPENDRAIN  RTC_CR_TAMPALRM_TYPE                                         
#define LL_RTC_ALARM_OUTPUTTYPE_PUSHPULL   0x00000000U                                                 
#else                                                                                                         
#define LL_RTC_ALARM_OUTPUTTYPE_OPENDRAIN  0x00000000U                                                  
#define LL_RTC_ALARM_OUTPUTTYPE_PUSHPULL   RTC_OR_ALARMOUTTYPE                                                               
#endif                                                                                                         
   
      
    

                                                               
      
    
#define LL_RTC_OUTPUTPOLARITY_PIN_HIGH     0x00000000U                                                                                   
#define LL_RTC_OUTPUTPOLARITY_PIN_LOW      RTC_CR_POL                                                                                    
   
      
    

                                               
      
    
#define LL_RTC_TIME_FORMAT_AM_OR_24        0x00000000U                                       
#define LL_RTC_TIME_FORMAT_PM              RTC_TR_PM                       
   
      
    

                                                  
      
    
#define LL_RTC_SHIFT_SECOND_DELAY          0x00000000U                                                         
#define LL_RTC_SHIFT_SECOND_ADVANCE        RTC_SHIFTR_ADD1S                                                              
   
      
    

                                              
      
    
#define LL_RTC_ALMA_MASK_NONE              0x00000000U                                               
#define LL_RTC_ALMA_MASK_DATEWEEKDAY       RTC_ALRMAR_MSK4                                                           
#define LL_RTC_ALMA_MASK_HOURS             RTC_ALRMAR_MSK3                                                        
#define LL_RTC_ALMA_MASK_MINUTES           RTC_ALRMAR_MSK2                                                          
#define LL_RTC_ALMA_MASK_SECONDS           RTC_ALRMAR_MSK1                                                          
#define LL_RTC_ALMA_MASK_ALL               (RTC_ALRMAR_MSK4 | RTC_ALRMAR_MSK3 | RTC_ALRMAR_MSK2 | RTC_ALRMAR_MSK1)                  
   
      
    

                                                            
      
    
#define LL_RTC_ALMA_TIME_FORMAT_AM         0x00000000U                                       
#define LL_RTC_ALMA_TIME_FORMAT_PM         RTC_ALRMAR_PM                   
   
      
    

#if defined (STM32L4P5xx) || defined (STM32L4Q5xx)
                                                                                                                                                            
      
    
#define LL_RTC_ALMA_SUBSECONDBIN_AUTOCLR_NO    0UL                                                                                                
#define LL_RTC_ALMA_SUBSECONDBIN_AUTOCLR_YES   RTC_ALRMASSR_SSCLR                                                                                            
                                                                                                                                                        
                                                                                                                     
   
      
    
#endif                                                         

                                              
      
    
#define LL_RTC_ALMB_MASK_NONE              0x00000000U                                               
#define LL_RTC_ALMB_MASK_DATEWEEKDAY       RTC_ALRMBR_MSK4                                                           
#define LL_RTC_ALMB_MASK_HOURS             RTC_ALRMBR_MSK3                                                        
#define LL_RTC_ALMB_MASK_MINUTES           RTC_ALRMBR_MSK2                                                          
#define LL_RTC_ALMB_MASK_SECONDS           RTC_ALRMBR_MSK1                                                          
#define LL_RTC_ALMB_MASK_ALL               (RTC_ALRMBR_MSK4 | RTC_ALRMBR_MSK3 | RTC_ALRMBR_MSK2 | RTC_ALRMBR_MSK1)                  
   
      
    

                                                            
      
    
#define LL_RTC_ALMB_TIME_FORMAT_AM         0x00000000U                                       
#define LL_RTC_ALMB_TIME_FORMAT_PM         RTC_ALRMBR_PM                   
   
      
    

#if defined (STM32L4P5xx) || defined (STM32L4Q5xx)
                                                                                                                                                            
      
    
#define LL_RTC_ALMB_SUBSECONDBIN_AUTOCLR_NO    0UL                                                                                                
#define LL_RTC_ALMB_SUBSECONDBIN_AUTOCLR_YES   RTC_ALRMBSSR_SSCLR                                                                                            
                                                                                                                                                        
                                                                                                                     
   
      
    

                                                                                                             
                                                                                                        
      
    
#define LL_RTC_ALMB_FLAG_AUTOCLR_NO    0UL                          
#define LL_RTC_ALMB_FLAG_AUTOCLR_YES   RTC_CR_ALRBMSK               
   
      
    
#endif                                                         

                                                      
      
    
#define LL_RTC_TIMESTAMP_EDGE_RISING       0x00000000U                                                                        
#define LL_RTC_TIMESTAMP_EDGE_FALLING      RTC_CR_TSEDGE                                                                      
   
      
    

                                                             
      
    
#define LL_RTC_TS_TIME_FORMAT_AM           0x00000000U                                       
#define LL_RTC_TS_TIME_FORMAT_PM           RTC_TSTR_PM                     
   
      
    

#if defined(STM32L412xx) || defined(STM32L422xx) || defined (STM32L4P5xx) || defined (STM32L4Q5xx)
                                      
      
    
#define LL_RTC_TAMPER_1                    TAMP_CR1_TAMP1E                                 
#define LL_RTC_TAMPER_2                    TAMP_CR1_TAMP2E                                 
#if defined (STM32L4P5xx) || defined (STM32L4Q5xx)
#define LL_RTC_TAMPER_3                    TAMP_CR1_TAMP3E                                 
#endif
   
      
    

                                                
      
    
#define LL_RTC_TAMPER_MASK_TAMPER1         TAMP_CR2_TAMP1MSK                                                                                                                                          
#define LL_RTC_TAMPER_MASK_TAMPER2         TAMP_CR2_TAMP2MSK                                                                                                                                            
#if defined (STM32L4P5xx) || defined (STM32L4Q5xx)
#define LL_RTC_TAMPER_MASK_TAMPER3         TAMP_CR2_TAMP3MSK                                                                                                                                            
#endif
   
      
    

                                                       
      
    
#define LL_RTC_TAMPER_NOERASE_TAMPER1      TAMP_CR2_TAMP1NOERASE                                                            
#define LL_RTC_TAMPER_NOERASE_TAMPER2      TAMP_CR2_TAMP2NOERASE                                                            
#if defined (STM32L4P5xx) || defined (STM32L4Q5xx)
#define LL_RTC_TAMPER_NOERASE_TAMPER3      TAMP_CR2_TAMP3NOERASE                                                            
#endif
   
      
    

                                                        
      
    
#define LL_RTC_TAMPER_DURATION_1RTCCLK     0x00000000U                                                                                      
#define LL_RTC_TAMPER_DURATION_2RTCCLK     TAMP_FLTCR_TAMPPRCH_0                                                                            
#define LL_RTC_TAMPER_DURATION_4RTCCLK     TAMP_FLTCR_TAMPPRCH_1                                                                            
#define LL_RTC_TAMPER_DURATION_8RTCCLK     TAMP_FLTCR_TAMPPRCH                                                                              
   
      
    

                                                    
      
    
#define LL_RTC_TAMPER_FILTER_DISABLE       0x00000000U                                              
#define LL_RTC_TAMPER_FILTER_2SAMPLE       TAMP_FLTCR_TAMPFLT_0                                                                               
#define LL_RTC_TAMPER_FILTER_4SAMPLE       TAMP_FLTCR_TAMPFLT_1                                                                               
#define LL_RTC_TAMPER_FILTER_8SAMPLE       TAMP_FLTCR_TAMPFLT                                                                                  
   
      
    

                                                                              
      
    
#define LL_RTC_TAMPER_SAMPLFREQDIV_32768   0x00000000U                                                                                                                     
#define LL_RTC_TAMPER_SAMPLFREQDIV_16384   TAMP_FLTCR_TAMPFREQ_0                                                                                                           
#define LL_RTC_TAMPER_SAMPLFREQDIV_8192    TAMP_FLTCR_TAMPFREQ_1                                                                                                          
#define LL_RTC_TAMPER_SAMPLFREQDIV_4096    (TAMP_FLTCR_TAMPFREQ_1 | TAMP_FLTCR_TAMPFREQ_0)                                                                                
#define LL_RTC_TAMPER_SAMPLFREQDIV_2048    TAMP_FLTCR_TAMPFREQ_2                                                                                                          
#define LL_RTC_TAMPER_SAMPLFREQDIV_1024    (TAMP_FLTCR_TAMPFREQ_2 | TAMP_FLTCR_TAMPFREQ_0)                                                                                
#define LL_RTC_TAMPER_SAMPLFREQDIV_512     (TAMP_FLTCR_TAMPFREQ_2 | TAMP_FLTCR_TAMPFREQ_1)                                                                               
#define LL_RTC_TAMPER_SAMPLFREQDIV_256     TAMP_FLTCR_TAMPFREQ                                                                                                           
   
      
    

                                                               
      
    
#define LL_RTC_TAMPER_ACTIVELEVEL_TAMP1    TAMP_CR2_TAMP1TRG                                                                                                                           
#define LL_RTC_TAMPER_ACTIVELEVEL_TAMP2    TAMP_CR2_TAMP2TRG                                                                                                                           
#if defined (STM32L4P5xx) || defined (STM32L4Q5xx)
#define LL_RTC_TAMPER_ACTIVELEVEL_TAMP3    TAMP_CR2_TAMP3TRG                                                                                                                           
#endif
   
      
    

#else                                                                                                         

                                      
      
    
#if defined(RTC_TAMPER1_SUPPORT)
#define LL_RTC_TAMPER_1                    RTC_TAMPCR_TAMP1E                                  
#endif                          
#if defined(RTC_TAMPER2_SUPPORT)
#define LL_RTC_TAMPER_2                    RTC_TAMPCR_TAMP2E                                  
#endif                          
#if defined(RTC_TAMPER3_SUPPORT)
#define LL_RTC_TAMPER_3                    RTC_TAMPCR_TAMP3E                                  
#endif                          
   
      
    

                                                
      
    
#if defined(RTC_TAMPER1_SUPPORT)
#define LL_RTC_TAMPER_MASK_TAMPER1         RTC_TAMPCR_TAMP1MF                                                                                                                                          
#endif                          
#if defined(RTC_TAMPER2_SUPPORT)
#define LL_RTC_TAMPER_MASK_TAMPER2         RTC_TAMPCR_TAMP2MF                                                                                                                                            
#endif                          
#if defined(RTC_TAMPER3_SUPPORT)
#define LL_RTC_TAMPER_MASK_TAMPER3         RTC_TAMPCR_TAMP3MF                                                                                                                                           
#endif                          
   
      
    

                                                       
      
    
#if defined(RTC_TAMPER1_SUPPORT)
#define LL_RTC_TAMPER_NOERASE_TAMPER1      RTC_TAMPCR_TAMP1NOERASE                                                            
#endif                          
#if defined(RTC_TAMPER2_SUPPORT)
#define LL_RTC_TAMPER_NOERASE_TAMPER2      RTC_TAMPCR_TAMP2NOERASE                                                            
#endif                          
#if defined(RTC_TAMPER3_SUPPORT)
#define LL_RTC_TAMPER_NOERASE_TAMPER3      RTC_TAMPCR_TAMP3NOERASE                                                            
#endif                          
   
      
    

#if defined(RTC_TAMPCR_TAMPPRCH)
                                                        
      
    
#define LL_RTC_TAMPER_DURATION_1RTCCLK     0x00000000U                                                                                                       
#define LL_RTC_TAMPER_DURATION_2RTCCLK     RTC_TAMPCR_TAMPPRCH_0                                                                            
#define LL_RTC_TAMPER_DURATION_4RTCCLK     RTC_TAMPCR_TAMPPRCH_1                                                                            
#define LL_RTC_TAMPER_DURATION_8RTCCLK     RTC_TAMPCR_TAMPPRCH                                                                              
   
      
    
#endif                          

#if defined(RTC_TAMPCR_TAMPFLT)
                                                    
      
    
#define LL_RTC_TAMPER_FILTER_DISABLE       0x00000000U                                                               
#define LL_RTC_TAMPER_FILTER_2SAMPLE       RTC_TAMPCR_TAMPFLT_0                                                                               
#define LL_RTC_TAMPER_FILTER_4SAMPLE       RTC_TAMPCR_TAMPFLT_1                                                                               
#define LL_RTC_TAMPER_FILTER_8SAMPLE       RTC_TAMPCR_TAMPFLT                                                                                  
   
      
    
#endif                         

#if defined(RTC_TAMPCR_TAMPFREQ)
                                                                              
      
    
#define LL_RTC_TAMPER_SAMPLFREQDIV_32768   0x00000000U                                                                                                                                      
#define LL_RTC_TAMPER_SAMPLFREQDIV_16384   RTC_TAMPCR_TAMPFREQ_0                                                                                                           
#define LL_RTC_TAMPER_SAMPLFREQDIV_8192    RTC_TAMPCR_TAMPFREQ_1                                                                                                          
#define LL_RTC_TAMPER_SAMPLFREQDIV_4096    (RTC_TAMPCR_TAMPFREQ_1 | RTC_TAMPCR_TAMPFREQ_0)                                                                                
#define LL_RTC_TAMPER_SAMPLFREQDIV_2048    RTC_TAMPCR_TAMPFREQ_2                                                                                                          
#define LL_RTC_TAMPER_SAMPLFREQDIV_1024    (RTC_TAMPCR_TAMPFREQ_2 | RTC_TAMPCR_TAMPFREQ_0)                                                                                
#define LL_RTC_TAMPER_SAMPLFREQDIV_512     (RTC_TAMPCR_TAMPFREQ_2 | RTC_TAMPCR_TAMPFREQ_1)                                                                               
#define LL_RTC_TAMPER_SAMPLFREQDIV_256     RTC_TAMPCR_TAMPFREQ                                                                                                           
   
      
    
#endif                          

                                                               
      
    
#if defined(RTC_TAMPER1_SUPPORT)
#define LL_RTC_TAMPER_ACTIVELEVEL_TAMP1    RTC_TAMPCR_TAMP1TRG                                                                                                                           
#endif                          
#if defined(RTC_TAMPER2_SUPPORT)
#define LL_RTC_TAMPER_ACTIVELEVEL_TAMP2    RTC_TAMPCR_TAMP2TRG                                                                                                                           
#endif                          
#if defined(RTC_TAMPER3_SUPPORT)
#define LL_RTC_TAMPER_ACTIVELEVEL_TAMP3    RTC_TAMPCR_TAMP3TRG                                                                                                                           
#endif                          
   
      
    

#endif                                                                                                         

                                                         
      
    
#define LL_RTC_WAKEUPCLOCK_DIV_16          0x00000000U                                                           
#define LL_RTC_WAKEUPCLOCK_DIV_8           RTC_CR_WUCKSEL_0                                                     
#define LL_RTC_WAKEUPCLOCK_DIV_4           RTC_CR_WUCKSEL_1                                                     
#define LL_RTC_WAKEUPCLOCK_DIV_2           (RTC_CR_WUCKSEL_1 | RTC_CR_WUCKSEL_0)                                
#define LL_RTC_WAKEUPCLOCK_CKSPRE          RTC_CR_WUCKSEL_2                                                                      
#define LL_RTC_WAKEUPCLOCK_CKSPRE_WUT      (RTC_CR_WUCKSEL_2 | RTC_CR_WUCKSEL_1)                                                                                             
   
      
    

#if defined(RTC_BACKUP_SUPPORT)
                                   
      
    
#define LL_RTC_BKP_DR0                     0x00000000U
#define LL_RTC_BKP_DR1                     0x00000001U
#define LL_RTC_BKP_DR2                     0x00000002U
#define LL_RTC_BKP_DR3                     0x00000003U
#define LL_RTC_BKP_DR4                     0x00000004U
#if RTC_BKP_NUMBER > 5
#define LL_RTC_BKP_DR5                     0x00000005U
#define LL_RTC_BKP_DR6                     0x00000006U
#define LL_RTC_BKP_DR7                     0x00000007U
#define LL_RTC_BKP_DR8                     0x00000008U
#define LL_RTC_BKP_DR9                     0x00000009U
#define LL_RTC_BKP_DR10                    0x0000000AU
#define LL_RTC_BKP_DR11                    0x0000000BU
#define LL_RTC_BKP_DR12                    0x0000000CU
#define LL_RTC_BKP_DR13                    0x0000000DU
#define LL_RTC_BKP_DR14                    0x0000000EU
#define LL_RTC_BKP_DR15                    0x0000000FU
#endif                         

#if RTC_BKP_NUMBER > 16
#define LL_RTC_BKP_DR16                    0x00000010U
#define LL_RTC_BKP_DR17                    0x00000011U
#define LL_RTC_BKP_DR18                    0x00000012U
#define LL_RTC_BKP_DR19                    0x00000013U
#endif                          

#if RTC_BKP_NUMBER > 20
#define LL_RTC_BKP_DR20                    0x00000014U
#define LL_RTC_BKP_DR21                    0x00000015U
#define LL_RTC_BKP_DR22                    0x00000016U
#define LL_RTC_BKP_DR23                    0x00000017U
#define LL_RTC_BKP_DR24                    0x00000018U
#define LL_RTC_BKP_DR25                    0x00000019U
#define LL_RTC_BKP_DR26                    0x0000001AU
#define LL_RTC_BKP_DR27                    0x0000001BU
#define LL_RTC_BKP_DR28                    0x0000001CU
#define LL_RTC_BKP_DR29                    0x0000001DU
#define LL_RTC_BKP_DR30                    0x0000001EU
#define LL_RTC_BKP_DR31                    0x0000001FU
#endif                          
   
      
    
#endif                         

                                                        
      
    
#define LL_RTC_CALIB_OUTPUT_NONE           0x00000000U                                                    
#define LL_RTC_CALIB_OUTPUT_1HZ            (RTC_CR_COE | RTC_CR_COSEL)                                   
#define LL_RTC_CALIB_OUTPUT_512HZ           RTC_CR_COE                                                     
   
      
    

                                                                      
      
    
#define LL_RTC_CALIB_INSERTPULSE_NONE      0x00000000U                                             
#define LL_RTC_CALIB_INSERTPULSE_SET       RTC_CALR_CALP                                                                                                                
   
      
    

                                                        
      
    
#define LL_RTC_CALIB_PERIOD_32SEC          0x00000000U                                                           
#define LL_RTC_CALIB_PERIOD_16SEC          RTC_CALR_CALW16                                                       
#define LL_RTC_CALIB_PERIOD_8SEC           RTC_CALR_CALW8                                                       
   
      
    

#if defined (STM32L4P5xx) || defined (STM32L4Q5xx)
                                                             
      
    
#define LL_RTC_CALIB_LOWPOWER_NONE         0x00000000U                                  
#define LL_RTC_CALIB_LOWPOWER_SET          RTC_CALR_LPCAL                              
   
      
    

                                                                      
      
    
#define LL_RTC_BINARY_NONE  0x00000000U                                                                   
#define LL_RTC_BINARY_ONLY  RTC_ICSR_BIN_0                                                      
#define LL_RTC_BINARY_MIX   RTC_ICSR_BIN_1                                                          
   
      
    

                                                                                          
      
    
#define LL_RTC_BINARY_MIX_BCDU_0  0x00000000u                                                                                     
#define LL_RTC_BINARY_MIX_BCDU_1  (0x1UL << RTC_ICSR_BCDU_Pos)                                                                    
#define LL_RTC_BINARY_MIX_BCDU_2  (0x2UL << RTC_ICSR_BCDU_Pos)                                                                    
#define LL_RTC_BINARY_MIX_BCDU_3  (0x3UL << RTC_ICSR_BCDU_Pos)                                                                     
#define LL_RTC_BINARY_MIX_BCDU_4  (0x4UL << RTC_ICSR_BCDU_Pos)                                                                     
#define LL_RTC_BINARY_MIX_BCDU_5  (0x5UL << RTC_ICSR_BCDU_Pos)                                                                     
#define LL_RTC_BINARY_MIX_BCDU_6  (0x6UL << RTC_ICSR_BCDU_Pos)                                                                     
#define LL_RTC_BINARY_MIX_BCDU_7  (0x7UL << RTC_ICSR_BCDU_Pos)                                                                     
   
      
    
#endif                                                         

   
      
    

                                                                                
                                                        
      
    

                                                                         
      
    

   
                                         
                                     
                                          
                                                         
                
    
#define LL_RTC_WriteReg(__INSTANCE__, __REG__, __VALUE__) WRITE_REG(__INSTANCE__->__REG__, (__VALUE__))

   
                                        
                                     
                                       
                          
    
#define LL_RTC_ReadReg(__INSTANCE__, __REG__) READ_REG(__INSTANCE__->__REG__)
   
      
    

                                                     
      
    

   
                                                                                     
                                          
                          
    
#define __LL_RTC_CONVERT_BIN2BCD(__VALUE__) (uint8_t)((((__VALUE__) / 10U) << 4U) | ((__VALUE__) % 10U))

   
                                                                                     
                                               
                          
    
#define __LL_RTC_CONVERT_BCD2BIN(__VALUE__) (uint8_t)(((uint8_t)((__VALUE__) & (uint8_t)0xF0U) >> (uint8_t)0x4U) * 10U + ((__VALUE__) & (uint8_t)0x0FU))

   
      
    

                                               
      
    

   
                                             
                                                                         
                                                              
                                           
                                            
                                              
                                             
                                           
                                             
                                           
    
#define __LL_RTC_GET_WEEKDAY(__RTC_DATE__) (((__RTC_DATE__) >> RTC_OFFSET_WEEKDAY) & 0x000000FFU)

   
                                                       
                                                                
                                                
    
#define __LL_RTC_GET_YEAR(__RTC_DATE__) ((__RTC_DATE__) & 0x000000FFU)

   
                                                        
                                                                
                                                              
                                          
                                           
                                        
                                        
                                      
                                       
                                       
                                         
                                            
                                          
                                           
                                           
    
#define __LL_RTC_GET_MONTH(__RTC_DATE__) (((__RTC_DATE__) >>RTC_OFFSET_MONTH) & 0x000000FFU)

   
                                                      
                                                                
                                               
    
#define __LL_RTC_GET_DAY(__RTC_DATE__) (((__RTC_DATE__) >>RTC_OFFSET_DAY) & 0x000000FFU)

   
      
    

                                               
      
    

   
                                                       
                                                                           
                                                                                          
    
#define __LL_RTC_GET_HOUR(__RTC_TIME__) (((__RTC_TIME__) >> RTC_OFFSET_HOUR) & 0x000000FFU)

   
                                                         
                                                                           
                                                 
    
#define __LL_RTC_GET_MINUTE(__RTC_TIME__) (((__RTC_TIME__) >> RTC_OFFSET_MINUTE) & 0x000000FFU)

   
                                                         
                                                                           
                                              
    
#define __LL_RTC_GET_SECOND(__RTC_TIME__) ((__RTC_TIME__) & 0x000000FFU)

   
      
    

   
      
    

                                                                                
                                                              
      
    

                                                   
      
    

   
                                                               
                                                                                                        
                                                                                               
                                                               
                             
                                                                         
                                              
                                            
                
    
__STATIC_INLINE void LL_RTC_SetHourFormat(RTC_TypeDef *RTCx, uint32_t HourFormat)
{
  MODIFY_REG(RTCx->CR, RTC_CR_FMT, HourFormat);
}

   
                                                               
                                                               
                             
                                                              
                                              
                                            
    
__STATIC_INLINE uint32_t LL_RTC_GetHourFormat(RTC_TypeDef *RTCx)
{
  return (uint32_t)(READ_BIT(RTCx->CR, RTC_CR_FMT));
}

   
                                                            
                                                                                                        
                                                                  
                             
                                                                          
                                             
                                          
                                          
                                            
                
    
__STATIC_INLINE void LL_RTC_SetAlarmOutEvent(RTC_TypeDef *RTCx, uint32_t AlarmOutput)
{
  MODIFY_REG(RTCx->CR, RTC_CR_OSEL, AlarmOutput);
}

   
                                                         
                                                                  
                             
                                                              
                                             
                                          
                                          
                                            
    
__STATIC_INLINE uint32_t LL_RTC_GetAlarmOutEvent(RTC_TypeDef *RTCx)
{
  return (uint32_t)(READ_BIT(RTCx->CR, RTC_CR_OSEL));
}

#if defined(STM32L412xx) || defined(STM32L422xx) || defined (STM32L4P5xx) || defined (STM32L4Q5xx)
   
                                                                               
                                                                             
                             
                                                                     
                                                       
                                                      
                
    
__STATIC_INLINE void LL_RTC_SetAlarmOutputType(RTC_TypeDef *RTCx, uint32_t Output)
{
  MODIFY_REG(RTCx->CR, RTC_CR_TAMPALRM_TYPE, Output);
}

   
                                                                               
                                                                             
                             
                                                              
                                                       
                                                      
    
__STATIC_INLINE uint32_t LL_RTC_GetAlarmOutputType(RTC_TypeDef *RTCx)
{
  return (uint32_t)(READ_BIT(RTCx->CR, RTC_CR_TAMPALRM_TYPE));
}

   
                                      
                                                                                             
                                              
                                                                                          
                                                                 
                             
                
    
__STATIC_INLINE void LL_RTC_EnableInitMode(RTC_TypeDef *RTCx)
{
                                   
  SET_BIT(RTCx->ICSR, RTC_ICSR_INIT);
}

   
                                                           
                                                                  
                             
                
    
__STATIC_INLINE void LL_RTC_DisableInitMode(RTC_TypeDef *RTCx)
{
                                
  CLEAR_BIT(RTCx->ICSR, RTC_ICSR_INIT);
}

#else                                                                                                         

   
                                                                               
                                                      
                                                             
                             
                                                                     
                                                       
                                                      
                
    
__STATIC_INLINE void LL_RTC_SetAlarmOutputType(RTC_TypeDef *RTCx, uint32_t Output)
{
  MODIFY_REG(RTCx->OR, RTC_OR_ALARMOUTTYPE, Output);
}

   
                                                                               
                                                      
                                                             
                             
                                                              
                                                       
                                                      
    
__STATIC_INLINE uint32_t LL_RTC_GetAlarmOutputType(RTC_TypeDef *RTCx)
{
  return (uint32_t)(READ_BIT(RTCx->OR, RTC_OR_ALARMOUTTYPE));
}

   
                                      
                                                                                             
                                              
                                                                                          
                                                            
                             
                
    
__STATIC_INLINE void LL_RTC_EnableInitMode(RTC_TypeDef *RTCx)
{
                                   
  WRITE_REG(RTCx->ISR, RTC_LL_INIT_MASK);
}

   
                                                           
                                                             
                             
                
    
__STATIC_INLINE void LL_RTC_DisableInitMode(RTC_TypeDef *RTCx)
{
                                
  WRITE_REG(RTCx->ISR, (uint32_t)~RTC_ISR_INIT);
}
#endif                                                                                                         


#if defined (STM32L4P5xx) || defined (STM32L4Q5xx)
   
                                                 
                                                                                                        
                                                                                                
                                                                 
                             
                                                          
                                        
                                        
                                              
                
    
__STATIC_INLINE void LL_RTC_SetBinaryMode(RTC_TypeDef *RTCx, uint32_t BinaryMode)
{
  MODIFY_REG(RTCx->ICSR, RTC_ICSR_BIN, BinaryMode);
}

   
                                                 
                                                                 
                             
                                                              
                                        
                                        
                                              
                
    
__STATIC_INLINE uint32_t LL_RTC_GetBinaryMode(RTC_TypeDef *RTCx)
{
  return (uint32_t)(READ_BIT(RTCx->ICSR, RTC_ICSR_BIN));
}

   
                                    
                                                                                                        
                                                                                                
                                                                 
                             
                                                          
                                              
                                              
                                              
                                              
                                              
                                              
                                              
                                              
                
    
__STATIC_INLINE void LL_RTC_SetBinMixBCDU(RTC_TypeDef *RTCx, uint32_t BinMixBcdU)
{
  MODIFY_REG(RTCx->ICSR, RTC_ICSR_BCDU, BinMixBcdU);
}

   
                                    
                                                                 
                             
                                                              
                                              
                                              
                                              
                                              
                                              
                                              
                                              
                                              
                
    
__STATIC_INLINE uint32_t LL_RTC_GetBinMixBCDU(RTC_TypeDef *RTCx)
{
  return (uint32_t)(READ_BIT(RTCx->ICSR, RTC_ICSR_BCDU));
}
#endif                                                         


   
                                                                              
                                                                                                        
                                                                   
                             
                                                                       
                                                    
                                                   
                
    
__STATIC_INLINE void LL_RTC_SetOutputPolarity(RTC_TypeDef *RTCx, uint32_t Polarity)
{
  MODIFY_REG(RTCx->CR, RTC_CR_POL, Polarity);
}

   
                               
                                                                   
                             
                                                              
                                                    
                                                   
    
__STATIC_INLINE uint32_t LL_RTC_GetOutputPolarity(RTC_TypeDef *RTCx)
{
  return (uint32_t)(READ_BIT(RTCx->CR, RTC_CR_POL));
}

   
                                              
                                                                                                        
                                                                       
                             
                
    
__STATIC_INLINE void LL_RTC_EnableShadowRegBypass(RTC_TypeDef *RTCx)
{
  SET_BIT(RTCx->CR, RTC_CR_BYPSHAD);
}

   
                                               
                                                                        
                             
                
    
__STATIC_INLINE void LL_RTC_DisableShadowRegBypass(RTC_TypeDef *RTCx)
{
  CLEAR_BIT(RTCx->CR, RTC_CR_BYPSHAD);
}

   
                                                               
                                                                          
                             
                                  
    
__STATIC_INLINE uint32_t LL_RTC_IsShadowRegBypassEnabled(RTC_TypeDef *RTCx)
{
  return (READ_BIT(RTCx->CR, RTC_CR_BYPSHAD) == (RTC_CR_BYPSHAD));
}

   
                                                                    
                                                                                                        
                                                                                               
                                                                
                             
                
    
__STATIC_INLINE void LL_RTC_EnableRefClock(RTC_TypeDef *RTCx)
{
  SET_BIT(RTCx->CR, RTC_CR_REFCKON);
}

   
                                                                     
                                                                                                        
                                                                                               
                                                                 
                             
                
    
__STATIC_INLINE void LL_RTC_DisableRefClock(RTC_TypeDef *RTCx)
{
  CLEAR_BIT(RTCx->CR, RTC_CR_REFCKON);
}

   
                                             
                                                                    
                             
                                                                          
                
    
__STATIC_INLINE void LL_RTC_SetAsynchPrescaler(RTC_TypeDef *RTCx, uint32_t AsynchPrescaler)
{
  MODIFY_REG(RTCx->PRER, RTC_PRER_PREDIV_A, AsynchPrescaler << RTC_PRER_PREDIV_A_Pos);
}

   
                                            
                                                                   
                             
                                                                           
                
    
__STATIC_INLINE void LL_RTC_SetSynchPrescaler(RTC_TypeDef *RTCx, uint32_t SynchPrescaler)
{
  MODIFY_REG(RTCx->PRER, RTC_PRER_PREDIV_S, SynchPrescaler);
}

   
                                             
                                                                    
                             
                                                          
    
__STATIC_INLINE uint32_t LL_RTC_GetAsynchPrescaler(RTC_TypeDef *RTCx)
{
  return (uint32_t)(READ_BIT(RTCx->PRER, RTC_PRER_PREDIV_A) >> RTC_PRER_PREDIV_A_Pos);
}

   
                                            
                                                                   
                             
                                                            
    
__STATIC_INLINE uint32_t LL_RTC_GetSynchPrescaler(RTC_TypeDef *RTCx)
{
  return (uint32_t)(READ_BIT(RTCx->PRER, RTC_PRER_PREDIV_S));
}

   
                                                          
                                                                       
                             
                
    
__STATIC_INLINE void LL_RTC_EnableWriteProtection(RTC_TypeDef *RTCx)
{
  WRITE_REG(RTCx->WPR, RTC_WRITE_PROTECTION_DISABLE);
}

   
                                                           
                                                                        
                             
                
    
__STATIC_INLINE void LL_RTC_DisableWriteProtection(RTC_TypeDef *RTCx)
{
  WRITE_REG(RTCx->WPR, RTC_WRITE_PROTECTION_ENABLE_1);
  WRITE_REG(RTCx->WPR, RTC_WRITE_PROTECTION_ENABLE_2);
}

#if defined(STM32L412xx) || defined(STM32L422xx) || defined (STM32L4P5xx) || defined (STM32L4Q5xx)
   
                                 
                                                                                   
                                                     
                                                                   
                             
                
    
__STATIC_INLINE void LL_RTC_EnableTamperOutput(RTC_TypeDef *RTCx)
{
  SET_BIT(RTCx->CR, RTC_CR_TAMPOE);
}

   
                                  
                                                                    
                             
                
    
__STATIC_INLINE void LL_RTC_DisableTamperOutput(RTC_TypeDef *RTCx)
{
  CLEAR_BIT(RTCx->CR, RTC_CR_TAMPOE);
}

   
                                                     
                                                                      
                             
                                  
    
__STATIC_INLINE uint32_t LL_RTC_IsTamperOutputEnabled(RTC_TypeDef *RTCx)
{
  return (READ_BIT(RTCx->CR, RTC_CR_TAMPOE) == (RTC_CR_TAMPOE));
}

   
                                                   
                                                                       
                             
                
    
__STATIC_INLINE void LL_RTC_EnableAlarmPullUp(RTC_TypeDef *RTCx)
{
  SET_BIT(RTCx->CR, RTC_CR_TAMPALRM_PU);
}

   
                                                    
                                                                       
                             
                
    
__STATIC_INLINE void LL_RTC_DisableAlarmPullUp(RTC_TypeDef *RTCx)
{
  CLEAR_BIT(RTCx->CR, RTC_CR_TAMPALRM_PU);
}

   
                                                                       
                                                                          
                             
                                  
    
__STATIC_INLINE uint32_t LL_RTC_IsAlarmPullUpEnabled(RTC_TypeDef *RTCx)
{
  return (READ_BIT(RTCx->CR, RTC_CR_TAMPALRM_PU) == (RTC_CR_TAMPALRM_PU));
}

   
                                  
                                                                              
                                                           
                                                 
                                                              
                             
                
    
__STATIC_INLINE void LL_RTC_EnableOutput2(RTC_TypeDef *RTCx)
{
  SET_BIT(RTCx->CR, RTC_CR_OUT2EN);
}

   
                                   
                                                               
                             
                
    
__STATIC_INLINE void LL_RTC_DisableOutput2(RTC_TypeDef *RTCx)
{
  CLEAR_BIT(RTCx->CR, RTC_CR_OUT2EN);
}

   
                                                       
                                                                 
                             
                                  
    
__STATIC_INLINE uint32_t LL_RTC_IsOutput2Enabled(RTC_TypeDef *RTCx)
{
  return (READ_BIT(RTCx->CR, RTC_CR_OUT2EN) == (RTC_CR_OUT2EN));
}

#else                                                                                                         

   
                                
                                                            
                             
                
    
__STATIC_INLINE void LL_RTC_EnableOutRemap(RTC_TypeDef *RTCx)
{
  SET_BIT(RTCx->OR, RTC_OR_OUT_RMP);
}

   
                                 
                                                             
                             
                
    
__STATIC_INLINE void LL_RTC_DisableOutRemap(RTC_TypeDef *RTCx)
{
  CLEAR_BIT(RTCx->OR, RTC_OR_OUT_RMP);
}
#endif                                                                                                         

   
      
    

                                 
      
    

   
                                                       
                                                                                                        
                                                                                               
                                                                
                             
                                                                         
                                                 
                                           
                
    
__STATIC_INLINE void LL_RTC_TIME_SetFormat(RTC_TypeDef *RTCx, uint32_t TimeFormat)
{
  MODIFY_REG(RTCx->TR, RTC_TR_PM, TimeFormat);
}

   
                                               
                                                                                                
                                 
                                                                                     
                                                                          
                                                                
                             
                                                              
                                                 
                                           
    
__STATIC_INLINE uint32_t LL_RTC_TIME_GetFormat(RTC_TypeDef *RTCx)
{
  return (uint32_t)(READ_BIT(RTCx->TR, RTC_TR_PM));
}

   
                                   
                                                                                                        
                                                                                               
                                                                                                      
                                                                
                                                              
                             
                                                                                                          
                
    
__STATIC_INLINE void LL_RTC_TIME_SetHour(RTC_TypeDef *RTCx, uint32_t Hours)
{
  MODIFY_REG(RTCx->TR, (RTC_TR_HT | RTC_TR_HU),
             (((Hours & 0xF0U) << (RTC_TR_HT_Pos - 4U)) | ((Hours & 0x0FU) << RTC_TR_HU_Pos)));
}

   
                                   
                                                                                                
                                 
                                                                                     
                                                                          
                                                                                        
                       
                                                                
                                                              
                             
                                                                                                    
    
__STATIC_INLINE uint32_t LL_RTC_TIME_GetHour(RTC_TypeDef *RTCx)
{
  return ((READ_BIT(RTCx->TR, (RTC_TR_HT | RTC_TR_HU))) >> RTC_TR_HU_Pos);
}

   
                                     
                                                                                                        
                                                                                               
                                                                                                         
                                                                  
                                                                
                             
                                                                 
                
    
__STATIC_INLINE void LL_RTC_TIME_SetMinute(RTC_TypeDef *RTCx, uint32_t Minutes)
{
  MODIFY_REG(RTCx->TR, (RTC_TR_MNT | RTC_TR_MNU),
             (((Minutes & 0xF0U) << (RTC_TR_MNT_Pos - 4U)) | ((Minutes & 0x0FU) << RTC_TR_MNU_Pos)));
}

   
                                     
                                                                                                
                                 
                                                                                     
                                                                          
                                                                                       
                          
                                                                  
                                                                
                             
                                                         
    
__STATIC_INLINE uint32_t LL_RTC_TIME_GetMinute(RTC_TypeDef *RTCx)
{
  return ((READ_BIT(RTCx->TR, (RTC_TR_MNT | RTC_TR_MNU))) >> RTC_TR_MNU_Pos);
}

   
                                     
                                                                                                        
                                                                                               
                                                                                                         
                                                                  
                                                                
                             
                                                                 
                
    
__STATIC_INLINE void LL_RTC_TIME_SetSecond(RTC_TypeDef *RTCx, uint32_t Seconds)
{
  MODIFY_REG(RTCx->TR, (RTC_TR_ST | RTC_TR_SU),
             (((Seconds & 0xF0U) << (RTC_TR_ST_Pos - 4U)) | ((Seconds & 0x0FU) << RTC_TR_SU_Pos)));
}

   
                                     
                                                                                                
                                 
                                                                                     
                                                                          
                                                                                        
                          
                                                                  
                                                                
                             
                                                         
    
__STATIC_INLINE uint32_t LL_RTC_TIME_GetSecond(RTC_TypeDef *RTCx)
{
  return ((READ_BIT(RTCx->TR, (RTC_TR_ST | RTC_TR_SU))) >> RTC_TR_SU_Pos);
}

   
                                                            
                                                                                                        
                                                                                               
                                                            
                                                               
                                                               
                                                               
                                                               
                                                               
                                                               
                                                             
                             
                                                                          
                                                 
                                           
                                                                                                          
                                                                 
                                                                 
                
    
__STATIC_INLINE void LL_RTC_TIME_Config(RTC_TypeDef *RTCx, uint32_t Format12_24, uint32_t Hours, uint32_t Minutes, uint32_t Seconds)
{
  uint32_t temp = 0U;

  temp = Format12_24                                                                                    | \
         (((Hours & 0xF0U) << (RTC_TR_HT_Pos - 4U)) | ((Hours & 0x0FU) << RTC_TR_HU_Pos))     | \
         (((Minutes & 0xF0U) << (RTC_TR_MNT_Pos - 4U)) | ((Minutes & 0x0FU) << RTC_TR_MNU_Pos)) | \
         (((Seconds & 0xF0U) << (RTC_TR_ST_Pos - 4U)) | ((Seconds & 0x0FU) << RTC_TR_SU_Pos));
  MODIFY_REG(RTCx->TR, (RTC_TR_PM | RTC_TR_HT | RTC_TR_HU | RTC_TR_MNT | RTC_TR_MNU | RTC_TR_ST | RTC_TR_SU), temp);
}

   
                                                            
                                                                                                
                                 
                                                                                     
                                                                          
                                                                                      
                                                            
                                                            
                                                            
                                                            
                                                            
                                                            
                                                          
                             
                                                                           
    
__STATIC_INLINE uint32_t LL_RTC_TIME_Get(RTC_TypeDef *RTCx)
{
  uint32_t temp = 0U;

  temp = READ_BIT(RTCx->TR, (RTC_TR_HT | RTC_TR_HU | RTC_TR_MNT | RTC_TR_MNU | RTC_TR_ST | RTC_TR_SU));
  return (uint32_t)((((((temp & RTC_TR_HT) >> RTC_TR_HT_Pos) << 4U) | ((temp & RTC_TR_HU) >> RTC_TR_HU_Pos)) << RTC_OFFSET_HOUR) |  \
                    (((((temp & RTC_TR_MNT) >> RTC_TR_MNT_Pos) << 4U) | ((temp & RTC_TR_MNU) >> RTC_TR_MNU_Pos)) << RTC_OFFSET_MINUTE) | \
                    ((((temp & RTC_TR_ST) >> RTC_TR_ST_Pos) << 4U) | ((temp & RTC_TR_SU) >> RTC_TR_SU_Pos)));
}

   
                                                                               
                                                                                                        
                                                                          
                             
                
    
__STATIC_INLINE void LL_RTC_TIME_EnableDayLightStore(RTC_TypeDef *RTCx)
{
  SET_BIT(RTCx->CR, RTC_CR_BKP);
}

   
                                                                                            
                                                                                                        
                                                                           
                             
                
    
__STATIC_INLINE void LL_RTC_TIME_DisableDayLightStore(RTC_TypeDef *RTCx)
{
  CLEAR_BIT(RTCx->CR, RTC_CR_BKP);
}

   
                                                                                  
                                                                             
                             
                                  
    
__STATIC_INLINE uint32_t LL_RTC_TIME_IsDayLightStoreEnabled(RTC_TypeDef *RTCx)
{
  return (READ_BIT(RTCx->CR, RTC_CR_BKP) == (RTC_CR_BKP));
}

   
                                                
                                                                                                        
                                                              
                             
                
    
__STATIC_INLINE void LL_RTC_TIME_DecHour(RTC_TypeDef *RTCx)
{
  SET_BIT(RTCx->CR, RTC_CR_SUB1H);
}

   
                                           
                                                                                                        
                                                              
                             
                
    
__STATIC_INLINE void LL_RTC_TIME_IncHour(RTC_TypeDef *RTCx)
{
  SET_BIT(RTCx->CR, RTC_CR_ADD1H);
}

   
                                                                      
                                                                                 
                                                                                
                                                                             
                           
                                                                                                                 
                                                                                 
                                            
                                                                   
                             
                                                                                  
                                                                   
    
__STATIC_INLINE uint32_t LL_RTC_TIME_GetSubSecond(RTC_TypeDef *RTCx)
{
  return (uint32_t)(READ_BIT(RTCx->SSR, RTC_SSR_SS));
}

   
                                                                          
                                                                                                              
                                                                                                        
                                                                                   
                                                                    
                                                                  
                             
                                                                          
                                               
                                                 
                                                                             
                
    
__STATIC_INLINE void LL_RTC_TIME_Synchronize(RTC_TypeDef *RTCx, uint32_t ShiftSecond, uint32_t Fraction)
{
  WRITE_REG(RTCx->SHIFTR, ShiftSecond | Fraction);
}

   
      
    

                                 
      
    

   
                                  
                                                                                                      
                                                                
                                                              
                             
                                                              
                
    
__STATIC_INLINE void LL_RTC_DATE_SetYear(RTC_TypeDef *RTCx, uint32_t Year)
{
  MODIFY_REG(RTCx->DR, (RTC_DR_YT | RTC_DR_YU),
             (((Year & 0xF0U) << (RTC_DR_YT_Pos - 4U)) | ((Year & 0x0FU) << RTC_DR_YU_Pos)));
}

   
                                  
                                                                                                
                                 
                                                                                                      
                                                                
                                                              
                             
                                                         
    
__STATIC_INLINE uint32_t LL_RTC_DATE_GetYear(RTC_TypeDef *RTCx)
{
  return ((READ_BIT(RTCx->DR, (RTC_DR_YT | RTC_DR_YU))) >> RTC_DR_YU_Pos);
}

   
                        
                                                                 
                             
                                                                      
                                           
                                            
                                              
                                             
                                           
                                             
                                           
                
    
__STATIC_INLINE void LL_RTC_DATE_SetWeekDay(RTC_TypeDef *RTCx, uint32_t WeekDay)
{
  MODIFY_REG(RTCx->DR, RTC_DR_WDU, WeekDay << RTC_DR_WDU_Pos);
}

   
                        
                                                                                                
                                 
                                                                 
                             
                                                              
                                           
                                            
                                              
                                             
                                           
                                             
                                           
    
__STATIC_INLINE uint32_t LL_RTC_DATE_GetWeekDay(RTC_TypeDef *RTCx)
{
  return (uint32_t)(READ_BIT(RTCx->DR, RTC_DR_WDU) >> RTC_DR_WDU_Pos);
}

   
                                   
                                                                                                       
                                                                 
                                                               
                             
                                                                    
                                          
                                           
                                        
                                        
                                      
                                       
                                       
                                         
                                            
                                          
                                           
                                           
                
    
__STATIC_INLINE void LL_RTC_DATE_SetMonth(RTC_TypeDef *RTCx, uint32_t Month)
{
  MODIFY_REG(RTCx->DR, (RTC_DR_MT | RTC_DR_MU),
             (((Month & 0xF0U) << (RTC_DR_MT_Pos - 4U)) | ((Month & 0x0FU) << RTC_DR_MU_Pos)));
}

   
                                   
                                                                                                
                                 
                                                                                                       
                                                                 
                                                               
                             
                                                              
                                          
                                           
                                        
                                        
                                      
                                       
                                       
                                         
                                            
                                          
                                           
                                           
    
__STATIC_INLINE uint32_t LL_RTC_DATE_GetMonth(RTC_TypeDef *RTCx)
{
  return ((READ_BIT(RTCx->DR, (RTC_DR_MT | RTC_DR_MU))) >> RTC_DR_MU_Pos);
}

   
                                 
                                                                                                     
                                                               
                                                             
                             
                                                             
                
    
__STATIC_INLINE void LL_RTC_DATE_SetDay(RTC_TypeDef *RTCx, uint32_t Day)
{
  MODIFY_REG(RTCx->DR, (RTC_DR_DT | RTC_DR_DU),
             (((Day & 0xF0U) << (RTC_DR_DT_Pos - 4U)) | ((Day & 0x0FU) << RTC_DR_DU_Pos)));
}

   
                                 
                                                                                                
                                 
                                                                                                     
                                                               
                                                             
                             
                                                         
    
__STATIC_INLINE uint32_t LL_RTC_DATE_GetDay(RTC_TypeDef *RTCx)
{
  return ((READ_BIT(RTCx->DR, (RTC_DR_DT | RTC_DR_DU))) >> RTC_DR_DU_Pos);
}

   
                                                                 
                                                               
                                                               
                                                               
                                                               
                                                               
                                                               
                                                             
                             
                                                                      
                                           
                                            
                                              
                                             
                                           
                                             
                                           
                                                             
                                                                    
                                          
                                           
                                        
                                        
                                      
                                       
                                       
                                         
                                            
                                          
                                           
                                           
                                                              
                
    
__STATIC_INLINE void LL_RTC_DATE_Config(RTC_TypeDef *RTCx, uint32_t WeekDay, uint32_t Day, uint32_t Month, uint32_t Year)
{
  uint32_t temp = 0U;

  temp = (WeekDay << RTC_DR_WDU_Pos)                                                        | \
         (((Year & 0xF0U) << (RTC_DR_YT_Pos - 4U)) | ((Year & 0x0FU) << RTC_DR_YU_Pos))   | \
         (((Month & 0xF0U) << (RTC_DR_MT_Pos - 4U)) | ((Month & 0x0FU) << RTC_DR_MU_Pos)) | \
         (((Day & 0xF0U) << (RTC_DR_DT_Pos - 4U)) | ((Day & 0x0FU) << RTC_DR_DU_Pos));

  MODIFY_REG(RTCx->DR, (RTC_DR_WDU | RTC_DR_MT | RTC_DR_MU | RTC_DR_DT | RTC_DR_DU | RTC_DR_YT | RTC_DR_YU), temp);
}

   
                                                                 
                                                                                                
                                 
                                                                                    
                                                                           
                                                            
                                                            
                                                            
                                                            
                                                            
                                                            
                                                          
                             
                                                                             
    
__STATIC_INLINE uint32_t LL_RTC_DATE_Get(RTC_TypeDef *RTCx)
{
  uint32_t temp = 0U;

  temp = READ_BIT(RTCx->DR, (RTC_DR_WDU | RTC_DR_MT | RTC_DR_MU | RTC_DR_DT | RTC_DR_DU | RTC_DR_YT | RTC_DR_YU));
  return (uint32_t)((((temp & RTC_DR_WDU) >> RTC_DR_WDU_Pos) << RTC_OFFSET_WEEKDAY) | \
                    (((((temp & RTC_DR_DT) >> RTC_DR_DT_Pos) << 4U) | ((temp & RTC_DR_DU) >> RTC_DR_DU_Pos)) << RTC_OFFSET_DAY) | \
                    (((((temp & RTC_DR_MT) >> RTC_DR_MT_Pos) << 4U) | ((temp & RTC_DR_MU) >> RTC_DR_MU_Pos)) << RTC_OFFSET_MONTH) | \
                    ((((temp & RTC_DR_YT) >> RTC_DR_YT_Pos) << 4U) | ((temp & RTC_DR_YU) >> RTC_DR_YU_Pos)));
}

   
      
    

                                     
      
    

   
                          
                                                                                                        
                                                             
                             
                
    
__STATIC_INLINE void LL_RTC_ALMA_Enable(RTC_TypeDef *RTCx)
{
  SET_BIT(RTCx->CR, RTC_CR_ALRAE);
}

   
                           
                                                                                                        
                                                              
                             
                
    
__STATIC_INLINE void LL_RTC_ALMA_Disable(RTC_TypeDef *RTCx)
{
  CLEAR_BIT(RTCx->CR, RTC_CR_ALRAE);
}

   
                                      
                                                                
                                                                
                                                                
                                                              
                             
                                                                             
                                           
                                                  
                                            
                                              
                                              
                                          
                
    
__STATIC_INLINE void LL_RTC_ALMA_SetMask(RTC_TypeDef *RTCx, uint32_t Mask)
{
  MODIFY_REG(RTCx->ALRMAR, RTC_ALRMAR_MSK4 | RTC_ALRMAR_MSK3 | RTC_ALRMAR_MSK2 | RTC_ALRMAR_MSK1, Mask);
}

   
                                  
                                                                
                                                                
                                                                
                                                              
                             
                                                                               
                                           
                                                  
                                            
                                              
                                              
                                          
    
__STATIC_INLINE uint32_t LL_RTC_ALMA_GetMask(RTC_TypeDef *RTCx)
{
  return (uint32_t)(READ_BIT(RTCx->ALRMAR, RTC_ALRMAR_MSK4 | RTC_ALRMAR_MSK3 | RTC_ALRMAR_MSK2 | RTC_ALRMAR_MSK1));
}

   
                                                                                                      
                                                                    
                             
                
    
__STATIC_INLINE void LL_RTC_ALMA_EnableWeekday(RTC_TypeDef *RTCx)
{
  SET_BIT(RTCx->ALRMAR, RTC_ALRMAR_WDSEL);
}

   
                                                                            
                                                                     
                             
                
    
__STATIC_INLINE void LL_RTC_ALMA_DisableWeekday(RTC_TypeDef *RTCx)
{
  CLEAR_BIT(RTCx->ALRMAR, RTC_ALRMAR_WDSEL);
}

   
                                         
                                                                                                     
                                                               
                                                             
                             
                                                             
                
    
__STATIC_INLINE void LL_RTC_ALMA_SetDay(RTC_TypeDef *RTCx, uint32_t Day)
{
  MODIFY_REG(RTCx->ALRMAR, (RTC_ALRMAR_DT | RTC_ALRMAR_DU),
             (((Day & 0xF0U) << (RTC_ALRMAR_DT_Pos - 4U)) | ((Day & 0x0FU) << RTC_ALRMAR_DU_Pos)));
}

   
                                         
                                                                                                     
                                                               
                                                             
                             
                                                         
    
__STATIC_INLINE uint32_t LL_RTC_ALMA_GetDay(RTC_TypeDef *RTCx)
{
  return ((READ_BIT(RTCx->ALRMAR, (RTC_ALRMAR_DT | RTC_ALRMAR_DU))) >> RTC_ALRMAR_DU_Pos);
}

   
                               
                                                                 
                             
                                                                      
                                           
                                            
                                              
                                             
                                           
                                             
                                           
                
    
__STATIC_INLINE void LL_RTC_ALMA_SetWeekDay(RTC_TypeDef *RTCx, uint32_t WeekDay)
{
  MODIFY_REG(RTCx->ALRMAR, RTC_ALRMAR_DU, WeekDay << RTC_ALRMAR_DU_Pos);
}

   
                               
                                                                 
                             
                                                              
                                           
                                            
                                              
                                             
                                           
                                             
                                           
    
__STATIC_INLINE uint32_t LL_RTC_ALMA_GetWeekDay(RTC_TypeDef *RTCx)
{
  return (uint32_t)(READ_BIT(RTCx->ALRMAR, RTC_ALRMAR_DU) >> RTC_ALRMAR_DU_Pos);
}

   
                                                               
                                                                    
                             
                                                                         
                                                
                                                
                
    
__STATIC_INLINE void LL_RTC_ALMA_SetTimeFormat(RTC_TypeDef *RTCx, uint32_t TimeFormat)
{
  MODIFY_REG(RTCx->ALRMAR, RTC_ALRMAR_PM, TimeFormat);
}

   
                                                       
                                                                    
                             
                                                              
                                                
                                                
    
__STATIC_INLINE uint32_t LL_RTC_ALMA_GetTimeFormat(RTC_TypeDef *RTCx)
{
  return (uint32_t)(READ_BIT(RTCx->ALRMAR, RTC_ALRMAR_PM));
}

   
                                           
                                                                                                       
                                                                
                                                              
                             
                                                                                                          
                
    
__STATIC_INLINE void LL_RTC_ALMA_SetHour(RTC_TypeDef *RTCx, uint32_t Hours)
{
  MODIFY_REG(RTCx->ALRMAR, (RTC_ALRMAR_HT | RTC_ALRMAR_HU),
             (((Hours & 0xF0U) << (RTC_ALRMAR_HT_Pos - 4U)) | ((Hours & 0x0FU) << RTC_ALRMAR_HU_Pos)));
}

   
                                           
                                                                                                       
                                                                
                                                              
                             
                                                                                                    
    
__STATIC_INLINE uint32_t LL_RTC_ALMA_GetHour(RTC_TypeDef *RTCx)
{
  return ((READ_BIT(RTCx->ALRMAR, (RTC_ALRMAR_HT | RTC_ALRMAR_HU))) >> RTC_ALRMAR_HU_Pos);
}

   
                                             
                                                                                                         
                                                                  
                                                                
                             
                                                                 
                
    
__STATIC_INLINE void LL_RTC_ALMA_SetMinute(RTC_TypeDef *RTCx, uint32_t Minutes)
{
  MODIFY_REG(RTCx->ALRMAR, (RTC_ALRMAR_MNT | RTC_ALRMAR_MNU),
             (((Minutes & 0xF0U) << (RTC_ALRMAR_MNT_Pos - 4U)) | ((Minutes & 0x0FU) << RTC_ALRMAR_MNU_Pos)));
}

   
                                             
                                                                                                         
                                                                  
                                                                
                             
                                                         
    
__STATIC_INLINE uint32_t LL_RTC_ALMA_GetMinute(RTC_TypeDef *RTCx)
{
  return ((READ_BIT(RTCx->ALRMAR, (RTC_ALRMAR_MNT | RTC_ALRMAR_MNU))) >> RTC_ALRMAR_MNU_Pos);
}

   
                                             
                                                                                                         
                                                                  
                                                                
                             
                                                                 
                
    
__STATIC_INLINE void LL_RTC_ALMA_SetSecond(RTC_TypeDef *RTCx, uint32_t Seconds)
{
  MODIFY_REG(RTCx->ALRMAR, (RTC_ALRMAR_ST | RTC_ALRMAR_SU),
             (((Seconds & 0xF0U) << (RTC_ALRMAR_ST_Pos - 4U)) | ((Seconds & 0x0FU) << RTC_ALRMAR_SU_Pos)));
}

   
                                             
                                                                                                         
                                                                  
                                                                
                             
                                                         
    
__STATIC_INLINE uint32_t LL_RTC_ALMA_GetSecond(RTC_TypeDef *RTCx)
{
  return ((READ_BIT(RTCx->ALRMAR, (RTC_ALRMAR_ST | RTC_ALRMAR_SU))) >> RTC_ALRMAR_SU_Pos);
}

   
                                                                    
                                                                   
                                                                   
                                                                   
                                                                   
                                                                   
                                                                   
                                                                 
                             
                                                                          
                                                
                                                
                                                                                                          
                                                                 
                                                                 
                
    
__STATIC_INLINE void LL_RTC_ALMA_ConfigTime(RTC_TypeDef *RTCx, uint32_t Format12_24, uint32_t Hours, uint32_t Minutes, uint32_t Seconds)
{
  uint32_t temp = 0U;

  temp = Format12_24 | (((Hours & 0xF0U) << (RTC_ALRMAR_HT_Pos - 4U)) | ((Hours & 0x0FU) << RTC_ALRMAR_HU_Pos))    | \
         (((Minutes & 0xF0U) << (RTC_ALRMAR_MNT_Pos - 4U)) | ((Minutes & 0x0FU) << RTC_ALRMAR_MNU_Pos)) | \
         (((Seconds & 0xF0U) << (RTC_ALRMAR_ST_Pos - 4U)) | ((Seconds & 0x0FU) << RTC_ALRMAR_SU_Pos));

  MODIFY_REG(RTCx->ALRMAR, RTC_ALRMAR_PM | RTC_ALRMAR_HT | RTC_ALRMAR_HU | RTC_ALRMAR_MNT | RTC_ALRMAR_MNU | RTC_ALRMAR_ST | RTC_ALRMAR_SU, temp);
}

   
                                                                    
                                                                                      
                                                      
                                                                
                                                                
                                                                
                                                                
                                                                
                                                              
                             
                                                      
    
__STATIC_INLINE uint32_t LL_RTC_ALMA_GetTime(RTC_TypeDef *RTCx)
{
  return (uint32_t)((LL_RTC_ALMA_GetHour(RTCx) << RTC_OFFSET_HOUR) | (LL_RTC_ALMA_GetMinute(RTCx) << RTC_OFFSET_MINUTE) | LL_RTC_ALMA_GetSecond(RTCx));
}

   
                                                                           
                                                                                   
                                    
                                                                       
                             
                                                                                    
                                                                  
                
    
__STATIC_INLINE void LL_RTC_ALMA_SetSubSecondMask(RTC_TypeDef *RTCx, uint32_t Mask)
{
  MODIFY_REG(RTCx->ALRMASSR, RTC_ALRMASSR_MASKSS, Mask << RTC_ALRMASSR_MASKSS_Pos);
}

   
                                                                           
                                                                       
                             
                                                                               
                                                             
    
__STATIC_INLINE uint32_t LL_RTC_ALMA_GetSubSecondMask(RTC_TypeDef *RTCx)
{
  return (uint32_t)(READ_BIT(RTCx->ALRMASSR, RTC_ALRMASSR_MASKSS) >> RTC_ALRMASSR_MASKSS_Pos);
}

#if defined (STM32L4P5xx) || defined (STM32L4Q5xx)
   
                                              
                                                                                   
                                    
                                                                   
                             
                                                                            
                                                         
                                                          
                
    
__STATIC_INLINE void LL_RTC_ALMA_SetBinAutoClr(RTC_TypeDef *RTCx, uint32_t BinaryAutoClr)
{
  MODIFY_REG(RTCx->ALRMASSR, RTC_ALRMASSR_SSCLR, BinaryAutoClr);
}

   
                                              
                                                                   
                             
                                                  
                                                         
                                                          
    
__STATIC_INLINE uint32_t LL_RTC_ALMA_GetBinAutoClr(RTC_TypeDef *RTCx)
{
  return (uint32_t)(READ_BIT(RTCx->ALRMASSR, RTC_ALRMASSR_SSCLR));
}

   
                                         
                                                                    
                             
                                                                                             
                                                                              
                
    
__STATIC_INLINE void LL_RTC_ALMA_SetSubSecond(RTC_TypeDef *RTCx, uint32_t Subsecond)
{
  MODIFY_REG(RTCx->ALRABINR, RTC_ALRABINR_SS, Subsecond);
}

   
                                         
                                                                    
                             
                                                                                  
                                                                   
    
__STATIC_INLINE uint32_t LL_RTC_ALMA_GetSubSecond(RTC_TypeDef *RTCx)
{
  return (uint32_t)(READ_BIT(RTCx->ALRABINR, RTC_ALRABINR_SS));
}
#else                                                         

   
                                         
                                                                   
                             
                                                                     
                
    
__STATIC_INLINE void LL_RTC_ALMA_SetSubSecond(RTC_TypeDef *RTCx, uint32_t Subsecond)
{
  MODIFY_REG(RTCx->ALRMASSR, RTC_ALRMASSR_SS, Subsecond);
}

   
                                         
                                                                   
                             
                                                           
    
__STATIC_INLINE uint32_t LL_RTC_ALMA_GetSubSecond(RTC_TypeDef *RTCx)
{
  return (uint32_t)(READ_BIT(RTCx->ALRMASSR, RTC_ALRMASSR_SS));
}
#endif                                                         

   
      
    

                                     
      
    

   
                          
                                                                                                        
                                                             
                             
                
    
__STATIC_INLINE void LL_RTC_ALMB_Enable(RTC_TypeDef *RTCx)
{
  SET_BIT(RTCx->CR, RTC_CR_ALRBE);
}

   
                           
                                                                                                        
                                                              
                             
                
    
__STATIC_INLINE void LL_RTC_ALMB_Disable(RTC_TypeDef *RTCx)
{
  CLEAR_BIT(RTCx->CR, RTC_CR_ALRBE);
}

   
                                      
                                                                
                                                                
                                                                
                                                              
                             
                                                                             
                                           
                                                  
                                            
                                              
                                              
                                          
                
    
__STATIC_INLINE void LL_RTC_ALMB_SetMask(RTC_TypeDef *RTCx, uint32_t Mask)
{
  MODIFY_REG(RTCx->ALRMBR, RTC_ALRMBR_MSK4 | RTC_ALRMBR_MSK3 | RTC_ALRMBR_MSK2 | RTC_ALRMBR_MSK1, Mask);
}

   
                                  
                                                                
                                                                
                                                                
                                                              
                             
                                                                               
                                           
                                                  
                                            
                                              
                                              
                                          
    
__STATIC_INLINE uint32_t LL_RTC_ALMB_GetMask(RTC_TypeDef *RTCx)
{
  return (uint32_t)(READ_BIT(RTCx->ALRMBR, RTC_ALRMBR_MSK4 | RTC_ALRMBR_MSK3 | RTC_ALRMBR_MSK2 | RTC_ALRMBR_MSK1));
}

   
                                                                                                      
                                                                    
                             
                
    
__STATIC_INLINE void LL_RTC_ALMB_EnableWeekday(RTC_TypeDef *RTCx)
{
  SET_BIT(RTCx->ALRMBR, RTC_ALRMBR_WDSEL);
}

   
                                                                            
                                                                     
                             
                
    
__STATIC_INLINE void LL_RTC_ALMB_DisableWeekday(RTC_TypeDef *RTCx)
{
  CLEAR_BIT(RTCx->ALRMBR, RTC_ALRMBR_WDSEL);
}

   
                                         
                                                                                                     
                                                               
                                                             
                             
                                                             
                
    
__STATIC_INLINE void LL_RTC_ALMB_SetDay(RTC_TypeDef *RTCx, uint32_t Day)
{
  MODIFY_REG(RTCx->ALRMBR, (RTC_ALRMBR_DT | RTC_ALRMBR_DU),
             (((Day & 0xF0U) << (RTC_ALRMBR_DT_Pos - 4U)) | ((Day & 0x0FU) << RTC_ALRMBR_DU_Pos)));
}

   
                                         
                                                                                                     
                                                               
                                                             
                             
                                                         
    
__STATIC_INLINE uint32_t LL_RTC_ALMB_GetDay(RTC_TypeDef *RTCx)
{
  return ((READ_BIT(RTCx->ALRMBR, (RTC_ALRMBR_DT | RTC_ALRMBR_DU))) >> RTC_ALRMBR_DU_Pos);
}

   
                               
                                                                 
                             
                                                                      
                                           
                                            
                                              
                                             
                                           
                                             
                                           
                
    
__STATIC_INLINE void LL_RTC_ALMB_SetWeekDay(RTC_TypeDef *RTCx, uint32_t WeekDay)
{
  MODIFY_REG(RTCx->ALRMBR, RTC_ALRMBR_DU, WeekDay << RTC_ALRMBR_DU_Pos);
}

   
                               
                                                                 
                             
                                                              
                                           
                                            
                                              
                                             
                                           
                                             
                                           
    
__STATIC_INLINE uint32_t LL_RTC_ALMB_GetWeekDay(RTC_TypeDef *RTCx)
{
  return (uint32_t)(READ_BIT(RTCx->ALRMBR, RTC_ALRMBR_DU) >> RTC_ALRMBR_DU_Pos);
}

   
                                                               
                                                                    
                             
                                                                         
                                                
                                                
                
    
__STATIC_INLINE void LL_RTC_ALMB_SetTimeFormat(RTC_TypeDef *RTCx, uint32_t TimeFormat)
{
  MODIFY_REG(RTCx->ALRMBR, RTC_ALRMBR_PM, TimeFormat);
}

   
                                                       
                                                                    
                             
                                                              
                                                
                                                
    
__STATIC_INLINE uint32_t LL_RTC_ALMB_GetTimeFormat(RTC_TypeDef *RTCx)
{
  return (uint32_t)(READ_BIT(RTCx->ALRMBR, RTC_ALRMBR_PM));
}

   
                                           
                                                                                                       
                                                                
                                                              
                             
                                                                                                          
                
    
__STATIC_INLINE void LL_RTC_ALMB_SetHour(RTC_TypeDef *RTCx, uint32_t Hours)
{
  MODIFY_REG(RTCx->ALRMBR, (RTC_ALRMBR_HT | RTC_ALRMBR_HU),
             (((Hours & 0xF0U) << (RTC_ALRMBR_HT_Pos - 4U)) | ((Hours & 0x0FU) << RTC_ALRMBR_HU_Pos)));
}

   
                                           
                                                                                                       
                                                                
                                                              
                             
                                                                                                    
    
__STATIC_INLINE uint32_t LL_RTC_ALMB_GetHour(RTC_TypeDef *RTCx)
{
  return ((READ_BIT(RTCx->ALRMBR, (RTC_ALRMBR_HT | RTC_ALRMBR_HU))) >> RTC_ALRMBR_HU_Pos);
}

   
                                             
                                                                                                         
                                                                  
                                                                
                             
                                                           
                
    
__STATIC_INLINE void LL_RTC_ALMB_SetMinute(RTC_TypeDef *RTCx, uint32_t Minutes)
{
  MODIFY_REG(RTCx->ALRMBR, (RTC_ALRMBR_MNT | RTC_ALRMBR_MNU),
             (((Minutes & 0xF0U) << (RTC_ALRMBR_MNT_Pos - 4U)) | ((Minutes & 0x0FU) << RTC_ALRMBR_MNU_Pos)));
}

   
                                             
                                                                                                         
                                                                  
                                                                
                             
                                                         
    
__STATIC_INLINE uint32_t LL_RTC_ALMB_GetMinute(RTC_TypeDef *RTCx)
{
  return ((READ_BIT(RTCx->ALRMBR, (RTC_ALRMBR_MNT | RTC_ALRMBR_MNU))) >> RTC_ALRMBR_MNU_Pos);
}

   
                                             
                                                                                                         
                                                                  
                                                                
                             
                                                                 
                
    
__STATIC_INLINE void LL_RTC_ALMB_SetSecond(RTC_TypeDef *RTCx, uint32_t Seconds)
{
  MODIFY_REG(RTCx->ALRMBR, (RTC_ALRMBR_ST | RTC_ALRMBR_SU),
             (((Seconds & 0xF0U) << (RTC_ALRMBR_ST_Pos - 4U)) | ((Seconds & 0x0FU) << RTC_ALRMBR_SU_Pos)));
}

   
                                             
                                                                                                         
                                                                  
                                                                
                             
                                                         
    
__STATIC_INLINE uint32_t LL_RTC_ALMB_GetSecond(RTC_TypeDef *RTCx)
{
  return ((READ_BIT(RTCx->ALRMBR, (RTC_ALRMBR_ST | RTC_ALRMBR_SU))) >> RTC_ALRMBR_SU_Pos);
}

   
                                                                    
                                                                   
                                                                   
                                                                   
                                                                   
                                                                   
                                                                   
                                                                 
                             
                                                                          
                                                
                                                
                                                                                                          
                                                                 
                                                                 
                
    
__STATIC_INLINE void LL_RTC_ALMB_ConfigTime(RTC_TypeDef *RTCx, uint32_t Format12_24, uint32_t Hours, uint32_t Minutes, uint32_t Seconds)
{
  uint32_t temp = 0U;

  temp = Format12_24 | (((Hours & 0xF0U) << (RTC_ALRMBR_HT_Pos - 4U)) | ((Hours & 0x0FU) << RTC_ALRMBR_HU_Pos))    | \
         (((Minutes & 0xF0U) << (RTC_ALRMBR_MNT_Pos - 4U)) | ((Minutes & 0x0FU) << RTC_ALRMBR_MNU_Pos)) | \
         (((Seconds & 0xF0U) << (RTC_ALRMBR_ST_Pos - 4U)) | ((Seconds & 0x0FU) << RTC_ALRMBR_SU_Pos));

  MODIFY_REG(RTCx->ALRMBR, RTC_ALRMBR_PM | RTC_ALRMBR_HT | RTC_ALRMBR_HU | RTC_ALRMBR_MNT | RTC_ALRMBR_MNU | RTC_ALRMBR_ST | RTC_ALRMBR_SU, temp);
}

   
                                                                    
                                                                                      
                                                      
                                                                
                                                                
                                                                
                                                                
                                                                
                                                              
                             
                                                      
    
__STATIC_INLINE uint32_t LL_RTC_ALMB_GetTime(RTC_TypeDef *RTCx)
{
  return (uint32_t)((LL_RTC_ALMB_GetHour(RTCx) << RTC_OFFSET_HOUR) | (LL_RTC_ALMB_GetMinute(RTCx) << RTC_OFFSET_MINUTE) | LL_RTC_ALMB_GetSecond(RTCx));
}

   
                                                                           
                                                                                   
                                    
                                                                       
                             
                                                                                    
                                                                  
                
    
__STATIC_INLINE void LL_RTC_ALMB_SetSubSecondMask(RTC_TypeDef *RTCx, uint32_t Mask)
{
  MODIFY_REG(RTCx->ALRMBSSR, RTC_ALRMBSSR_MASKSS, Mask << RTC_ALRMBSSR_MASKSS_Pos);
}

   
                                                                           
                                                                       
                             
                                                                               
                                                             
    
__STATIC_INLINE uint32_t LL_RTC_ALMB_GetSubSecondMask(RTC_TypeDef *RTCx)
{
  return (uint32_t)(READ_BIT(RTCx->ALRMBSSR, RTC_ALRMBSSR_MASKSS) >> RTC_ALRMBSSR_MASKSS_Pos);
}

#if defined (STM32L4P5xx) || defined (STM32L4Q5xx)
   
                                              
                                                                                   
                                    
                                                                   
                             
                                                                            
                                                         
                                                          
                
    
__STATIC_INLINE void LL_RTC_ALMB_SetBinAutoClr(RTC_TypeDef *RTCx, uint32_t BinaryAutoClr)
{
  MODIFY_REG(RTCx->ALRMBSSR, RTC_ALRMBSSR_SSCLR, BinaryAutoClr);
}

   
                                              
                                                                   
                             
                                                  
                                                         
                                                          
    
__STATIC_INLINE uint32_t LL_RTC_ALMB_GetBinAutoClr(RTC_TypeDef *RTCx)
{
  return (uint32_t)(READ_BIT(RTCx->ALRMBSSR, RTC_ALRMBSSR_SSCLR));
}

   
                                         
                                                                    
                             
                                                                                             
                                                                              
                
    
__STATIC_INLINE void LL_RTC_ALMB_SetSubSecond(RTC_TypeDef *RTCx, uint32_t Subsecond)
{
  MODIFY_REG(RTCx->ALRBBINR, RTC_ALRBBINR_SS, Subsecond);
}

   
                                         
                                                                    
                             
                                                                                  
                                                                   
    
__STATIC_INLINE uint32_t LL_RTC_ALMB_GetSubSecond(RTC_TypeDef *RTCx)
{
  return (uint32_t)(READ_BIT(RTCx->ALRBBINR, RTC_ALRBBINR_SS));
}
#else                                                         

   
                                         
                                                                   
                             
                                                                     
                
    
__STATIC_INLINE void LL_RTC_ALMB_SetSubSecond(RTC_TypeDef *RTCx, uint32_t Subsecond)
{
  MODIFY_REG(RTCx->ALRMBSSR, RTC_ALRMBSSR_SS, Subsecond);
}

   
                                         
                                                                   
                             
                                                           
    
__STATIC_INLINE uint32_t LL_RTC_ALMB_GetSubSecond(RTC_TypeDef *RTCx)
{
  return (uint32_t)(READ_BIT(RTCx->ALRMBSSR, RTC_ALRMBSSR_SS));
}
#endif                                                         

   
      
    

                                           
      
    

   
                                           
                                                                                                        
                                                                        
                             
                
    
__STATIC_INLINE void LL_RTC_TS_EnableInternalEvent(RTC_TypeDef *RTCx)
{
  SET_BIT(RTCx->CR, RTC_CR_ITSE);
}

   
                                            
                                                                                                        
                                                                         
                             
                
    
__STATIC_INLINE void LL_RTC_TS_DisableInternalEvent(RTC_TypeDef *RTCx)
{
  CLEAR_BIT(RTCx->CR, RTC_CR_ITSE);
}

   
                            
                                                                                                        
                                                            
                             
                
    
__STATIC_INLINE void LL_RTC_TS_Enable(RTC_TypeDef *RTCx)
{
  SET_BIT(RTCx->CR, RTC_CR_TSE);
}

   
                             
                                                                                                        
                                                             
                             
                
    
__STATIC_INLINE void LL_RTC_TS_Disable(RTC_TypeDef *RTCx)
{
  CLEAR_BIT(RTCx->CR, RTC_CR_TSE);
}

   
                                            
                                                                                                        
                                                                                
                                                                   
                             
                                                                   
                                                  
                                                   
                
    
__STATIC_INLINE void LL_RTC_TS_SetActiveEdge(RTC_TypeDef *RTCx, uint32_t Edge)
{
  MODIFY_REG(RTCx->CR, RTC_CR_TSEDGE, Edge);
}

   
                                            
                                                                                                        
                                                                   
                             
                                                              
                                                  
                                                   
    
__STATIC_INLINE uint32_t LL_RTC_TS_GetActiveEdge(RTC_TypeDef *RTCx)
{
  return (uint32_t)(READ_BIT(RTCx->CR, RTC_CR_TSEDGE));
}

   
                                                               
                                                                  
                             
                                                              
                                              
                                              
    
__STATIC_INLINE uint32_t LL_RTC_TS_GetTimeFormat(RTC_TypeDef *RTCx)
{
  return (uint32_t)(READ_BIT(RTCx->TSTR, RTC_TSTR_PM));
}

   
                                             
                                                                                                       
                                                              
                                                            
                             
                                                                                                    
    
__STATIC_INLINE uint32_t LL_RTC_TS_GetHour(RTC_TypeDef *RTCx)
{
  return (uint32_t)(READ_BIT(RTCx->TSTR, RTC_TSTR_HT | RTC_TSTR_HU) >> RTC_TSTR_HU_Pos);
}

   
                                               
                                                                                                         
                                                                
                                                             
                             
                                                         
    
__STATIC_INLINE uint32_t LL_RTC_TS_GetMinute(RTC_TypeDef *RTCx)
{
  return (uint32_t)(READ_BIT(RTCx->TSTR, RTC_TSTR_MNT | RTC_TSTR_MNU) >> RTC_TSTR_MNU_Pos);
}

   
                                               
                                                                                                         
                                                                
                                                              
                             
                                                         
    
__STATIC_INLINE uint32_t LL_RTC_TS_GetSecond(RTC_TypeDef *RTCx)
{
  return (uint32_t)(READ_BIT(RTCx->TSTR, RTC_TSTR_ST | RTC_TSTR_SU));
}

   
                                                                      
                                                                                      
                                                      
                                                              
                                                              
                                                              
                                                              
                                                              
                                                            
                             
                                                      
    
__STATIC_INLINE uint32_t LL_RTC_TS_GetTime(RTC_TypeDef *RTCx)
{
  return (uint32_t)(READ_BIT(RTCx->TSTR,
                             RTC_TSTR_HT | RTC_TSTR_HU | RTC_TSTR_MNT | RTC_TSTR_MNU | RTC_TSTR_ST | RTC_TSTR_SU));
}

   
                                  
                                                               
                             
                                                              
                                           
                                            
                                              
                                             
                                           
                                             
                                           
    
__STATIC_INLINE uint32_t LL_RTC_TS_GetWeekDay(RTC_TypeDef *RTCx)
{
  return (uint32_t)(READ_BIT(RTCx->TSDR, RTC_TSDR_WDU) >> RTC_TSDR_WDU_Pos);
}

   
                                             
                                                                                                       
                                                               
                                                             
                             
                                                              
                                          
                                           
                                        
                                        
                                      
                                       
                                       
                                         
                                            
                                          
                                           
                                           
    
__STATIC_INLINE uint32_t LL_RTC_TS_GetMonth(RTC_TypeDef *RTCx)
{
  return (uint32_t)(READ_BIT(RTCx->TSDR, RTC_TSDR_MT | RTC_TSDR_MU) >> RTC_TSDR_MU_Pos);
}

   
                                           
                                                                                                     
                                                             
                                                           
                             
                                                         
    
__STATIC_INLINE uint32_t LL_RTC_TS_GetDay(RTC_TypeDef *RTCx)
{
  return (uint32_t)(READ_BIT(RTCx->TSDR, RTC_TSDR_DT | RTC_TSDR_DU));
}

   
                                                                     
                                                                 
                                                                           
                                                              
                                                              
                                                              
                                                              
                                                            
                             
                                                 
    
__STATIC_INLINE uint32_t LL_RTC_TS_GetDate(RTC_TypeDef *RTCx)
{
  return (uint32_t)(READ_BIT(RTCx->TSDR, RTC_TSDR_WDU | RTC_TSDR_MT | RTC_TSDR_MU | RTC_TSDR_DT | RTC_TSDR_DU));
}

   
                                           
                                                                  
                             
                                                                                  
                                                                   
    
__STATIC_INLINE uint32_t LL_RTC_TS_GetSubSecond(RTC_TypeDef *RTCx)
{
  return (uint32_t)(READ_BIT(RTCx->TSSSR, RTC_TSSSR_SS));
}

   
      
    

#if defined(RTC_WAKEUP_SUPPORT)
                                     
      
    

   
                               
                                                                                                        
                                                               
                             
                
    
__STATIC_INLINE void LL_RTC_WAKEUP_Enable(RTC_TypeDef *RTCx)
{
  SET_BIT(RTCx->CR, RTC_CR_WUTE);
}

   
                                
                                                                                                        
                                                                
                             
                
    
__STATIC_INLINE void LL_RTC_WAKEUP_Disable(RTC_TypeDef *RTCx)
{
  CLEAR_BIT(RTCx->CR, RTC_CR_WUTE);
}

   
                                                   
                                                                  
                             
                                  
    
__STATIC_INLINE uint32_t LL_RTC_WAKEUP_IsEnabled(RTC_TypeDef *RTCx)
{
  return (READ_BIT(RTCx->CR, RTC_CR_WUTE) == (RTC_CR_WUTE));
}

   
                               
                                                                                                        
                                                                                    
                                                                 
                             
                                                                          
                                               
                                              
                                              
                                              
                                               
                                                   
                
    
__STATIC_INLINE void LL_RTC_WAKEUP_SetClock(RTC_TypeDef *RTCx, uint32_t WakeupClock)
{
  MODIFY_REG(RTCx->CR, RTC_CR_WUCKSEL, WakeupClock);
}

   
                            
                                                                 
                             
                                                              
                                               
                                              
                                              
                                              
                                               
                                                   
    
__STATIC_INLINE uint32_t LL_RTC_WAKEUP_GetClock(RTC_TypeDef *RTCx)
{
  return (uint32_t)(READ_BIT(RTCx->CR, RTC_CR_WUCKSEL));
}

   
                                        
                                                                   
                                                                      
                             
                                                                 
                
    
__STATIC_INLINE void LL_RTC_WAKEUP_SetAutoReload(RTC_TypeDef *RTCx, uint32_t Value)
{
  MODIFY_REG(RTCx->WUTR, RTC_WUTR_WUT, Value);
}

   
                                        
                                                                      
                             
                                                           
    
__STATIC_INLINE uint32_t LL_RTC_WAKEUP_GetAutoReload(RTC_TypeDef *RTCx)
{
  return (uint32_t)(READ_BIT(RTCx->WUTR, RTC_WUTR_WUT));
}

#if defined(STM32L412xx) || defined(STM32L422xx) || defined (STM32L4P5xx) || defined (STM32L4Q5xx)
   
                                       
                                                                   
                                                                       
                             
                                                                 
                
    
__STATIC_INLINE void LL_RTC_WAKEUP_SetAutoClr(RTC_TypeDef *RTCx, uint32_t Value)
{
  MODIFY_REG(RTCx->WUTR, RTC_WUTR_WUTOCLR, (Value << RTC_WUTR_WUTOCLR_Pos));
}

   
                                       
                                                                       
                             
                                                           
    
__STATIC_INLINE uint32_t LL_RTC_WAKEUP_GetAutoClr(RTC_TypeDef *RTCx)
{
  return (uint32_t)((READ_BIT(RTCx->WUTR, RTC_WUTR_WUTOCLR)) >> RTC_WUTR_WUTOCLR_Pos);
}
#endif                                                                                                     

   
      
    
#endif                         

                                               
      
    

   
                                                             
                                                                                                        
                                                                     
                                                                   
                             
                                                                        
                                              
                                             
                                               
                
    
__STATIC_INLINE void LL_RTC_CAL_SetOutputFreq(RTC_TypeDef *RTCx, uint32_t Frequency)
{
  MODIFY_REG(RTCx->CR, RTC_CR_COE | RTC_CR_COSEL, Frequency);
}

   
                                                             
                                                                     
                                                                   
                             
                                                              
                                              
                                             
                                               
    
__STATIC_INLINE uint32_t LL_RTC_CAL_GetOutputFreq(RTC_TypeDef *RTCx)
{
  return (uint32_t)(READ_BIT(RTCx->CR, RTC_CR_COE | RTC_CR_COSEL));
}

   
                                                                                                 
                                                                                                        
                                                          
                                                              
                             
                                                                    
                                                   
                                                  
                
    
__STATIC_INLINE void LL_RTC_CAL_SetPulse(RTC_TypeDef *RTCx, uint32_t Pulse)
{
  MODIFY_REG(RTCx->CALR, RTC_CALR_CALP, Pulse);
}

   
                                                                                                               
                                                                     
                             
                                  
    
__STATIC_INLINE uint32_t LL_RTC_CAL_IsPulseInserted(RTC_TypeDef *RTCx)
{
  return (READ_BIT(RTCx->CALR, RTC_CALR_CALP) == (RTC_CALR_CALP));
}

   
                                            
                                                                                                        
                                                            
                                                                 
                                                               
                             
                                                                     
                                               
                                               
                                              
                
    
__STATIC_INLINE void LL_RTC_CAL_SetPeriod(RTC_TypeDef *RTCx, uint32_t Period)
{
  MODIFY_REG(RTCx->CALR, RTC_CALR_CALW8 | RTC_CALR_CALW16, Period);
}

   
                                            
                                                                 
                                                               
                             
                                                              
                                               
                                               
                                              
    
__STATIC_INLINE uint32_t LL_RTC_CAL_GetPeriod(RTC_TypeDef *RTCx)
{
  return (uint32_t)(READ_BIT(RTCx->CALR, RTC_CALR_CALW8 | RTC_CALR_CALW16));
}

   
                                 
                                                                                                        
                                                            
                                                              
                             
                                                                     
                
    
__STATIC_INLINE void LL_RTC_CAL_SetMinus(RTC_TypeDef *RTCx, uint32_t CalibMinus)
{
  MODIFY_REG(RTCx->CALR, RTC_CALR_CALM, CalibMinus);
}

   
                                 
                                                              
                             
                                                           
    
__STATIC_INLINE uint32_t LL_RTC_CAL_GetMinus(RTC_TypeDef *RTCx)
{
  return (uint32_t)(READ_BIT(RTCx->CALR, RTC_CALR_CALM));
}

#if defined(STM32L412xx) || defined(STM32L422xx) || defined (STM32L4P5xx) || defined (STM32L4Q5xx)
   
                                        
                                                                                                        
                                                            
                                                                      
                             
                
    
__STATIC_INLINE void LL_RTC_CAL_LowPower_Enable(RTC_TypeDef *RTCx)
{
  SET_BIT(RTCx->CALR, RTC_CALR_LPCAL);
}

   
                                         
                                                                                                        
                                                            
                                                                       
                             
                
    
__STATIC_INLINE void LL_RTC_CAL_LowPower_Disable(RTC_TypeDef *RTCx)
{
  CLEAR_BIT(RTCx->CALR, RTC_CALR_LPCAL);
}

   
                                                            
                                                                         
                             
                                  
    
__STATIC_INLINE uint32_t LL_RTC_CAL_LowPower_IsEnabled(RTC_TypeDef *RTCx)
{
  return (READ_BIT(RTCx->CALR, RTC_CALR_LPCAL) == (RTC_CALR_LPCAL));
}
#endif                                                                                                         
   
      
    


#if defined(STM32L412xx) || defined(STM32L422xx) || defined (STM32L4P5xx) || defined (STM32L4Q5xx)
   
                                                        
                                                               
                             
                
    
__STATIC_INLINE void LL_RTC_TS_EnableOnTamper(RTC_TypeDef *RTCx)
{
  SET_BIT(RTCx->CR, RTC_CR_TAMPTS);
}

   
                                                       
                                                                
                             
                
    
__STATIC_INLINE void LL_RTC_TS_DisableOnTamper(RTC_TypeDef *RTCx)
{
  CLEAR_BIT(RTCx->CR, RTC_CR_TAMPTS);
}

                                     
      
    

   
                                        
                                                               
                                                             
                               
                                                                               
                                     
                                     
   
                
    
__STATIC_INLINE void LL_RTC_TAMPER_Enable(TAMP_TypeDef *TAMPx, uint32_t Tamper)
{
  SET_BIT(TAMPx->CR1, Tamper);
}

   
                                       
                                                                
                                                              
                               
                                                                               
                                     
                                     
   
                
    
__STATIC_INLINE void LL_RTC_TAMPER_Disable(TAMP_TypeDef *TAMPx, uint32_t Tamper)
{
  CLEAR_BIT(TAMPx->CR1, Tamper);
}

   
                                   
                                                                        
                                                                   
                                                                 
                               
                                                                             
                                                
                                                
   
                
    
__STATIC_INLINE void LL_RTC_TAMPER_EnableMask(TAMP_TypeDef *TAMPx, uint32_t Mask)
{
  SET_BIT(TAMPx->CR2, Mask);
}

   
                                    
                                                                    
                                                                  
                               
                                                                             
                                                
                                                
   
                
    
__STATIC_INLINE void LL_RTC_TAMPER_DisableMask(TAMP_TypeDef *TAMPx, uint32_t Mask)
{
  CLEAR_BIT(TAMPx->CR2, Mask);
}

   
                                                                     
                                                                       
                                                                     
                               
                                                                               
                                                   
                                                   
   
                
    
__STATIC_INLINE void LL_RTC_TAMPER_EnableEraseBKP(TAMP_TypeDef *TAMPx, uint32_t Tamper)
{
  CLEAR_BIT(TAMPx->CR2, Tamper);
}

   
                                                                      
                                                                        
                                                                      
                               
                                                                               
                                                   
                                                   
   
                
    
__STATIC_INLINE void LL_RTC_TAMPER_DisableEraseBKP(TAMP_TypeDef *TAMPx, uint32_t Tamper)
{
  SET_BIT(TAMPx->CR2, Tamper);
}

   
                                                                                   
                                                                      
                               
                
    
__STATIC_INLINE void LL_RTC_TAMPER_DisablePullUp(TAMP_TypeDef *TAMPx)
{
  SET_BIT(TAMPx->FLTCR, TAMP_FLTCR_TAMPPUDIS);
}

   
                                                                                        
                                                                     
                               
                
    
__STATIC_INLINE void LL_RTC_TAMPER_EnablePullUp(TAMP_TypeDef *TAMPx)
{
  CLEAR_BIT(TAMPx->FLTCR, TAMP_FLTCR_TAMPPUDIS);
}

   
                                            
                                                                     
                               
                                                                       
                                                    
                                                    
                                                    
                                                    
                
    
__STATIC_INLINE void LL_RTC_TAMPER_SetPrecharge(TAMP_TypeDef *TAMPx, uint32_t Duration)
{
  MODIFY_REG(TAMPx->FLTCR, TAMP_FLTCR_TAMPPRCH, Duration);
}

   
                                            
                                                                     
                               
                                                              
                                                    
                                                    
                                                    
                                                    
    
__STATIC_INLINE uint32_t LL_RTC_TAMPER_GetPrecharge(TAMP_TypeDef *TAMPx)
{
  return (uint32_t)(READ_BIT(TAMPx->FLTCR, TAMP_FLTCR_TAMPPRCH));
}

   
                                      
                                                                       
                               
                                                                          
                                                  
                                                  
                                                  
                                                  
                
    
__STATIC_INLINE void LL_RTC_TAMPER_SetFilterCount(TAMP_TypeDef *TAMPx, uint32_t FilterCount)
{
  MODIFY_REG(TAMPx->FLTCR, TAMP_FLTCR_TAMPFLT, FilterCount);
}

   
                                      
                                                                       
                               
                                                              
                                                  
                                                  
                                                  
                                                  
    
__STATIC_INLINE uint32_t LL_RTC_TAMPER_GetFilterCount(TAMP_TypeDef *TAMPx)
{
  return (uint32_t)(READ_BIT(TAMPx->FLTCR, TAMP_FLTCR_TAMPFLT));
}

   
                                         
                                                                        
                               
                                                                           
                                                      
                                                      
                                                     
                                                     
                                                     
                                                     
                                                    
                                                    
                
    
__STATIC_INLINE void LL_RTC_TAMPER_SetSamplingFreq(TAMP_TypeDef *TAMPx, uint32_t SamplingFreq)
{
  MODIFY_REG(TAMPx->FLTCR, TAMP_FLTCR_TAMPFREQ, SamplingFreq);
}

   
                                         
                                                                        
                               
                                                              
                                                      
                                                      
                                                     
                                                     
                                                     
                                                     
                                                    
                                                    
    
__STATIC_INLINE uint32_t LL_RTC_TAMPER_GetSamplingFreq(TAMP_TypeDef *TAMPx)
{
  return (uint32_t)(READ_BIT(TAMPx->FLTCR, TAMP_FLTCR_TAMPFREQ));
}

   
                                                
                                                                          
                                                                        
                               
                                                                               
                                                     
                                                     
   
                
    
__STATIC_INLINE void LL_RTC_TAMPER_EnableActiveLevel(TAMP_TypeDef *TAMPx, uint32_t Tamper)
{
  SET_BIT(TAMPx->CR2, Tamper);
}

   
                                                 
                                                                           
                                                                         
                               
                                                                               
                                                     
                                                     
   
                
    
__STATIC_INLINE void LL_RTC_TAMPER_DisableActiveLevel(TAMP_TypeDef *TAMPx, uint32_t Tamper)
{
  CLEAR_BIT(TAMPx->CR2, Tamper);
}

   
      
    

                                                         
      
    

   
                                                              
                                                                  
                              
                                                                             
                                    
                                    
                                    
                                    
                                    
                                                                    
                
    
__STATIC_INLINE void LL_RTC_BKP_SetRegister(TAMP_TypeDef *TAMPx, uint32_t BackupRegister, uint32_t Data)
{
  uint32_t tmp = 0U;

  tmp = (uint32_t)(&(TAMPx->BKP0R));
  tmp += (BackupRegister * 4U);

                                    
  *(__IO uint32_t *)tmp = (uint32_t)Data;
}

   
                                                                   
                                                                  
                              
                                                                             
                                    
                                    
                                    
                                    
                                    
                                                               
    
__STATIC_INLINE uint32_t LL_RTC_BKP_GetRegister(TAMP_TypeDef *TAMPx, uint32_t BackupRegister)
{
  uint32_t tmp = 0U;

  tmp = (uint32_t)(&(TAMPx->BKP0R));
  tmp += (BackupRegister * 4U);

                                   
  return (*(__IO uint32_t *)tmp);
}

   
      
    

                                                       
      
    

   
                                        
                                                                 
                             
                                  
    
__STATIC_INLINE uint32_t LL_RTC_IsActiveFlag_ITS(RTC_TypeDef *RTCx)
{
  return (READ_BIT(RTCx->SR, RTC_SR_ITSF) == (RTC_SR_ITSF));
}

   
                                          
                                                                      
                             
                                  
    
__STATIC_INLINE uint32_t LL_RTC_IsActiveFlag_RECALP(RTC_TypeDef *RTCx)
{
  return (READ_BIT(RTCx->ICSR, RTC_ICSR_RECALPF) == (RTC_ICSR_RECALPF));
}

   
                                        
                                                                  
                             
                                  
    
__STATIC_INLINE uint32_t LL_RTC_IsActiveFlag_TSOV(RTC_TypeDef *RTCx)
{
  return (READ_BIT(RTCx->SR, RTC_SR_TSOVF) == (RTC_SR_TSOVF));
}

   
                               
                                                                
                             
                                  
    
__STATIC_INLINE uint32_t LL_RTC_IsActiveFlag_TS(RTC_TypeDef *RTCx)
{
  return (READ_BIT(RTCx->SR, RTC_SR_TSF) == (RTC_SR_TSF));
}

   
                                 
                                                                 
                             
                                  
    
__STATIC_INLINE uint32_t LL_RTC_IsActiveFlag_WUT(RTC_TypeDef *RTCx)
{
  return (READ_BIT(RTCx->SR, RTC_SR_WUTF) == (RTC_SR_WUTF));
}

   
                            
                                                                  
                             
                                  
    
__STATIC_INLINE uint32_t LL_RTC_IsActiveFlag_ALRB(RTC_TypeDef *RTCx)
{
  return (READ_BIT(RTCx->SR, RTC_SR_ALRBF) == (RTC_SR_ALRBF));
}

   
                            
                                                                  
                             
                                  
    
__STATIC_INLINE uint32_t LL_RTC_IsActiveFlag_ALRA(RTC_TypeDef *RTCx)
{
  return (READ_BIT(RTCx->SR, RTC_SR_ALRAF) == (RTC_SR_ALRAF));
}

#if defined (STM32L4P5xx) || defined (STM32L4Q5xx)
   
                                  
                                                                  
                             
                                  
    
__STATIC_INLINE uint32_t LL_RTC_IsActiveFlag_SSRU(RTC_TypeDef *RTCx)
{
  return ((READ_BIT(RTCx->SR, RTC_SR_SSRUF) == (RTC_SR_SSRUF)) ? 1U : 0U);
}
#endif

   
                                          
                                                                
                             
                
    
__STATIC_INLINE void LL_RTC_ClearFlag_ITS(RTC_TypeDef *RTCx)
{
  SET_BIT(RTCx->SCR, RTC_SCR_CITSF);
}

   
                                          
                                                                 
                             
                
    
__STATIC_INLINE void LL_RTC_ClearFlag_TSOV(RTC_TypeDef *RTCx)
{
  SET_BIT(RTCx->SCR, RTC_SCR_CTSOVF);
}

   
                                 
                                                               
                             
                
    
__STATIC_INLINE void LL_RTC_ClearFlag_TS(RTC_TypeDef *RTCx)
{
  SET_BIT(RTCx->SCR, RTC_SCR_CTSF);
}

   
                                   
                                                                
                             
                
    
__STATIC_INLINE void LL_RTC_ClearFlag_WUT(RTC_TypeDef *RTCx)
{
  SET_BIT(RTCx->SCR, RTC_SCR_CWUTF);
}

   
                              
                                                                 
                             
                
    
__STATIC_INLINE void LL_RTC_ClearFlag_ALRB(RTC_TypeDef *RTCx)
{
  SET_BIT(RTCx->SCR, RTC_SCR_CALRBF);
}

   
                              
                                                                 
                             
                
    
__STATIC_INLINE void LL_RTC_ClearFlag_ALRA(RTC_TypeDef *RTCx)
{
  SET_BIT(RTCx->SCR, RTC_SCR_CALRAF);
}

#if defined (STM32L4P5xx) || defined (STM32L4Q5xx)
   
                                    
                                                                 
                             
                
    
__STATIC_INLINE void LL_RTC_ClearFlag_SSRU(RTC_TypeDef *RTCx)
{
  WRITE_REG(RTCx->SCR, RTC_SCR_CSSRUF);
}
#endif                                                         


   
                                   
                                                                    
                             
                                  
    
__STATIC_INLINE uint32_t LL_RTC_IsActiveFlag_INIT(RTC_TypeDef *RTCx)
{
  return (READ_BIT(RTCx->ICSR, RTC_ICSR_INITF) == (RTC_ICSR_INITF));
}

   
                                              
                                                                  
                             
                                  
    
__STATIC_INLINE uint32_t LL_RTC_IsActiveFlag_RS(RTC_TypeDef *RTCx)
{
  return (READ_BIT(RTCx->ICSR, RTC_ICSR_RSF) == (RTC_ICSR_RSF));
}

   
                                                
                                                               
                             
                
    
__STATIC_INLINE void LL_RTC_ClearFlag_RS(RTC_TypeDef *RTCx)
{
  WRITE_REG(RTCx->ICSR, (~((RTC_ICSR_RSF | RTC_ICSR_INIT) & 0x000000FFU) | (RTCx->ICSR & RTC_ICSR_INIT)));
}

   
                                          
                                                                     
                             
                                  
    
__STATIC_INLINE uint32_t LL_RTC_IsActiveFlag_INITS(RTC_TypeDef *RTCx)
{
  return (READ_BIT(RTCx->ICSR, RTC_ICSR_INITS) == (RTC_ICSR_INITS));
}

   
                                            
                                                                   
                             
                                  
    
__STATIC_INLINE uint32_t LL_RTC_IsActiveFlag_SHP(RTC_TypeDef *RTCx)
{
  return (READ_BIT(RTCx->ICSR, RTC_ICSR_SHPF) == (RTC_ICSR_SHPF));
}

   
                                       
                                                                    
                             
                                  
    
__STATIC_INLINE uint32_t LL_RTC_IsActiveFlag_WUTW(RTC_TypeDef *RTCx)
{
  return (READ_BIT(RTCx->ICSR, RTC_ICSR_WUTWF) == (RTC_ICSR_WUTWF));
}

   
                                    
                                                                     
                             
                                  
    
__STATIC_INLINE uint32_t LL_RTC_IsActiveFlag_ALRAM(RTC_TypeDef *RTCx)
{
  return (READ_BIT(RTCx->MISR, RTC_MISR_ALRAMF) == (RTC_MISR_ALRAMF));
}

#if defined (STM32L4P5xx) || defined (STM32L4Q5xx)
   
                                          
                                                                     
                             
                                  
    
__STATIC_INLINE uint32_t LL_RTC_IsActiveFlag_SSRUM(RTC_TypeDef *RTCx)
{
  return ((READ_BIT(RTCx->MISR, RTC_MISR_SSRUMF) == (RTC_MISR_SSRUMF)) ? 1U : 0U);
}
#endif

   
                                    
                                                                     
                             
                                  
    
__STATIC_INLINE uint32_t LL_RTC_IsActiveFlag_ALRBM(RTC_TypeDef *RTCx)
{
  return (READ_BIT(RTCx->MISR, RTC_MISR_ALRBMF) == (RTC_MISR_ALRBMF));
}

   
                                         
                                                                   
                             
                                  
    
__STATIC_INLINE uint32_t LL_RTC_IsActiveFlag_WUTM(RTC_TypeDef *RTCx)
{
  return (READ_BIT(RTCx->MISR, RTC_MISR_WUTMF) == (RTC_MISR_WUTMF));
}

   
                                       
                                                                 
                             
                                  
    
__STATIC_INLINE uint32_t LL_RTC_IsActiveFlag_TSM(RTC_TypeDef *RTCx)
{
  return (READ_BIT(RTCx->MISR, RTC_MISR_TSMF) == (RTC_MISR_TSMF));
}

   
                                                
                                                                     
                             
                                  
    
__STATIC_INLINE uint32_t LL_RTC_IsActiveFlag_TSOVM(RTC_TypeDef *RTCx)
{
  return (READ_BIT(RTCx->MISR, RTC_MISR_TSOVMF) == (RTC_MISR_TSOVMF));
}

   
                                                
                                                                   
                             
                                  
    
__STATIC_INLINE uint32_t LL_RTC_IsActiveFlag_ITSM(RTC_TypeDef *RTCx)
{
  return (READ_BIT(RTCx->MISR, RTC_MISR_ITSMF) == (RTC_MISR_ITSMF));
}

   
                                        
                                                                    
                               
                                  
    
__STATIC_INLINE uint32_t LL_RTC_IsActiveFlag_TAMP1(TAMP_TypeDef *TAMPx)
{
  return (READ_BIT(TAMPx->SR, TAMP_SR_TAMP1F) == (TAMP_SR_TAMP1F));
}

   
                                        
                                                                    
                               
                                  
    
__STATIC_INLINE uint32_t LL_RTC_IsActiveFlag_TAMP2(TAMP_TypeDef *TAMPx)
{
  return (READ_BIT(TAMPx->SR, TAMP_SR_TAMP2F) == (TAMP_SR_TAMP2F));
}

#if defined(RTC_TAMPER3_SUPPORT)
   
                                        
                                                                    
                               
                                  
    
__STATIC_INLINE uint32_t LL_RTC_IsActiveFlag_TAMP3(TAMP_TypeDef *TAMPx)
{
  return (READ_BIT(TAMPx->SR, TAMP_SR_TAMP3F) == (TAMP_SR_TAMP3F));
}
#endif

   
                                               
                                                                        
                               
                                  
    
__STATIC_INLINE uint32_t LL_RTC_IsActiveFlag_TAMP1M(TAMP_TypeDef *TAMPx)
{
  return (READ_BIT(TAMPx->MISR, TAMP_MISR_TAMP1MF) == (TAMP_MISR_TAMP1MF));
}

   
                                               
                                                                        
                               
                                  
    
__STATIC_INLINE uint32_t LL_RTC_IsActiveFlag_TAMP2M(TAMP_TypeDef *TAMPx)
{
  return (READ_BIT(TAMPx->MISR, TAMP_MISR_TAMP2MF) == (TAMP_MISR_TAMP2MF));
}

#if defined(RTC_TAMPER3_SUPPORT)
   
                                               
                                                                        
                               
                                  
    
__STATIC_INLINE uint32_t LL_RTC_IsActiveFlag_TAMP3M(TAMP_TypeDef *TAMPx)
{
  return (READ_BIT(TAMPx->MISR, TAMP_MISR_TAMP3MF) == (TAMP_MISR_TAMP3MF));
}
#endif


   
                                          
                                                                    
                               
                
    
__STATIC_INLINE void LL_RTC_ClearFlag_TAMP1(TAMP_TypeDef *TAMPx)
{
  SET_BIT(TAMPx->SCR, TAMP_SCR_CTAMP1F);
}

   
                                          
                                                                    
                               
                
    
__STATIC_INLINE void LL_RTC_ClearFlag_TAMP2(TAMP_TypeDef *TAMPx)
{
  SET_BIT(TAMPx->SCR, TAMP_SCR_CTAMP2F);
}

#if defined(RTC_TAMPER3_SUPPORT)
   
                                          
                                                                    
                               
                
    
__STATIC_INLINE void LL_RTC_ClearFlag_TAMP3(TAMP_TypeDef *TAMPx)
{
  SET_BIT(TAMPx->SCR, TAMP_SCR_CTAMP3F);
}
#endif

   
      
    

                                                   
      
    

   
                                       
                                                                                                        
                                                           
                             
                
    
__STATIC_INLINE void LL_RTC_EnableIT_TS(RTC_TypeDef *RTCx)
{
  SET_BIT(RTCx->CR, RTC_CR_TSIE);
}

   
                                        
                                                                                                        
                                                            
                             
                
    
__STATIC_INLINE void LL_RTC_DisableIT_TS(RTC_TypeDef *RTCx)
{
  CLEAR_BIT(RTCx->CR, RTC_CR_TSIE);
}

   
                                         
                                                                                                        
                                                             
                             
                
    
__STATIC_INLINE void LL_RTC_EnableIT_WUT(RTC_TypeDef *RTCx)
{
  SET_BIT(RTCx->CR, RTC_CR_WUTIE);
}

   
                                          
                                                                                                        
                                                              
                             
                
    
__STATIC_INLINE void LL_RTC_DisableIT_WUT(RTC_TypeDef *RTCx)
{
  CLEAR_BIT(RTCx->CR, RTC_CR_WUTIE);
}

   
                                    
                                                                                                        
                                                               
                             
                
    
__STATIC_INLINE void LL_RTC_EnableIT_ALRB(RTC_TypeDef *RTCx)
{
  SET_BIT(RTCx->CR, RTC_CR_ALRBIE);
}

   
                                     
                                                                                                        
                                                                
                             
                
    
__STATIC_INLINE void LL_RTC_DisableIT_ALRB(RTC_TypeDef *RTCx)
{
  CLEAR_BIT(RTCx->CR, RTC_CR_ALRBIE);
}

   
                                    
                                                                                                        
                                                               
                             
                
    
__STATIC_INLINE void LL_RTC_EnableIT_ALRA(RTC_TypeDef *RTCx)
{
  SET_BIT(RTCx->CR, RTC_CR_ALRAIE);
}

   
                                     
                                                                                                        
                                                                
                             
                
    
__STATIC_INLINE void LL_RTC_DisableIT_ALRA(RTC_TypeDef *RTCx)
{
  CLEAR_BIT(RTCx->CR, RTC_CR_ALRAIE);
}

#if defined (STM32L4P5xx) || defined (STM32L4Q5xx)
   
                                          
                                                                                                        
                                                               
                             
                
    
__STATIC_INLINE void LL_RTC_EnableIT_SSRU(RTC_TypeDef *RTCx)
{
  SET_BIT(RTCx->CR, RTC_CR_SSRUIE);
}

   
                                           
                                                                                                        
                                                                
                             
                
    
__STATIC_INLINE void LL_RTC_DisableIT_SSRU(RTC_TypeDef *RTCx)
{
  CLEAR_BIT(RTCx->CR, RTC_CR_SSRUIE);
}

   
                                                              
                                                                  
                             
                                  
    
__STATIC_INLINE uint32_t LL_RTC_IsEnabledIT_SSRU(RTC_TypeDef *RTCx)
{
  return ((READ_BIT(RTCx->CR, RTC_CR_SSRUIE) == (RTC_CR_SSRUIE)) ? 1U : 0U);
}
#endif                                                         

   
                                                           
                                                                
                             
                                  
    
__STATIC_INLINE uint32_t LL_RTC_IsEnabledIT_TS(RTC_TypeDef *RTCx)
{
  return (READ_BIT(RTCx->CR, RTC_CR_TSIE) == (RTC_CR_TSIE));
}

   
                                                             
                                                                 
                             
                                  
    
__STATIC_INLINE uint32_t LL_RTC_IsEnabledIT_WUT(RTC_TypeDef *RTCx)
{
  return (READ_BIT(RTCx->CR, RTC_CR_WUTIE) == (RTC_CR_WUTIE));
}

   
                                                        
                                                                  
                             
                                  
    
__STATIC_INLINE uint32_t LL_RTC_IsEnabledIT_ALRB(RTC_TypeDef *RTCx)
{
  return (READ_BIT(RTCx->CR, RTC_CR_ALRBIE) == (RTC_CR_ALRBIE));
}

   
                                                        
                                                                  
                             
                                  
    
__STATIC_INLINE uint32_t LL_RTC_IsEnabledIT_ALRA(RTC_TypeDef *RTCx)
{
  return (READ_BIT(RTCx->CR, RTC_CR_ALRAIE) == (RTC_CR_ALRAIE));
}

   
                                      
                                                                     
                               
                
    
__STATIC_INLINE void LL_RTC_EnableIT_TAMP1(TAMP_TypeDef *TAMPx)
{
  SET_BIT(TAMPx->IER, TAMP_IER_TAMP1IE);
}

   
                                       
                                                                      
                               
                
    
__STATIC_INLINE void LL_RTC_DisableIT_TAMP1(TAMP_TypeDef *TAMPx)
{
  CLEAR_BIT(TAMPx->IER, TAMP_IER_TAMP1IE);
}

   
                                      
                                                                     
                               
                
    
__STATIC_INLINE void LL_RTC_EnableIT_TAMP2(TAMP_TypeDef *TAMPx)
{
  SET_BIT(TAMPx->IER, TAMP_IER_TAMP2IE);
}

   
                                       
                                                                      
                               
                
    
__STATIC_INLINE void LL_RTC_DisableIT_TAMP2(TAMP_TypeDef *TAMPx)
{
  CLEAR_BIT(TAMPx->IER, TAMP_IER_TAMP2IE);
}

   
                                                          
                                                                      
                               
                                  
    
__STATIC_INLINE uint32_t LL_RTC_IsEnabledIT_TAMP1(TAMP_TypeDef *TAMPx)
{
  return (READ_BIT(TAMPx->IER, TAMP_IER_TAMP1IE) == (TAMP_IER_TAMP1IE));
}

   
                                                          
                                                                      
                               
                                  
    
__STATIC_INLINE uint32_t LL_RTC_IsEnabledIT_TAMP2(TAMP_TypeDef *TAMPx)
{
  return (READ_BIT(TAMPx->IER, TAMP_IER_TAMP2IE) == (TAMP_IER_TAMP2IE));
}

#if defined(RTC_TAMPER3_SUPPORT)
   
                                      
                                                                     
                               
                
    
__STATIC_INLINE void LL_RTC_EnableIT_TAMP3(TAMP_TypeDef *TAMPx)
{
  SET_BIT(TAMPx->IER, TAMP_IER_TAMP3IE);
}

   
                                       
                                                                      
                               
                
    
__STATIC_INLINE void LL_RTC_DisableIT_TAMP3(TAMP_TypeDef *TAMPx)
{
  CLEAR_BIT(TAMPx->IER, TAMP_IER_TAMP3IE);
}

   
                                                          
                                                                      
                               
                                  
    
__STATIC_INLINE uint32_t LL_RTC_IsEnabledIT_TAMP3(TAMP_TypeDef *TAMPx)
{
  return (READ_BIT(TAMPx->IER, TAMP_IER_TAMP3IE) == (TAMP_IER_TAMP3IE));
}
#endif

   
      
    

#else                                                                                                         

#if defined(RTC_TAMPCR_TAMPTS)
   
                                                        
                                                               
                             
                
    
__STATIC_INLINE void LL_RTC_TS_EnableOnTamper(RTC_TypeDef *RTCx)
{
  SET_BIT(RTCx->TAMPCR, RTC_TAMPCR_TAMPTS);
}

   
                                                       
                                                                
                             
                
    
__STATIC_INLINE void LL_RTC_TS_DisableOnTamper(RTC_TypeDef *RTCx)
{
  CLEAR_BIT(RTCx->TAMPCR, RTC_TAMPCR_TAMPTS);
}
#endif                        

                                     
      
    

   
                                            
                                                             
                                                             
                                                           
                             
                                                                               
                                     
                                     
                                     
   
                
    
__STATIC_INLINE void LL_RTC_TAMPER_Enable(RTC_TypeDef *RTCx, uint32_t Tamper)
{
  SET_BIT(RTCx->TAMPCR, Tamper);
}

   
                                           
                                                              
                                                              
                                                            
                             
                                                                               
                                     
                                     
                                     
   
                
    
__STATIC_INLINE void LL_RTC_TAMPER_Disable(RTC_TypeDef *RTCx, uint32_t Tamper)
{
  CLEAR_BIT(RTCx->TAMPCR, Tamper);
}

   
                                   
                                                                        
                                                                 
                                                                 
                                                               
                             
                                                                             
                                                
                                                
                                                
   
                
    
__STATIC_INLINE void LL_RTC_TAMPER_EnableMask(RTC_TypeDef *RTCx, uint32_t Mask)
{
  SET_BIT(RTCx->TAMPCR, Mask);
}

   
                                    
                                                                  
                                                                  
                                                                
                             
                                                                             
                                                
                                                
                                                
   
                
    
__STATIC_INLINE void LL_RTC_TAMPER_DisableMask(RTC_TypeDef *RTCx, uint32_t Mask)
{
  CLEAR_BIT(RTCx->TAMPCR, Mask);
}

   
                                                                     
                                                                     
                                                                     
                                                                   
                             
                                                                               
                                                   
                                                   
                                                   
   
                
    
__STATIC_INLINE void LL_RTC_TAMPER_EnableEraseBKP(RTC_TypeDef *RTCx, uint32_t Tamper)
{
  CLEAR_BIT(RTCx->TAMPCR, Tamper);
}

   
                                                                      
                                                                      
                                                                      
                                                                    
                             
                                                                               
                                                   
                                                   
                                                   
   
                
    
__STATIC_INLINE void LL_RTC_TAMPER_DisableEraseBKP(RTC_TypeDef *RTCx, uint32_t Tamper)
{
  SET_BIT(RTCx->TAMPCR, Tamper);
}

#if defined(RTC_TAMPCR_TAMPPUDIS)
   
                                                                                   
                                                                  
                             
                
    
__STATIC_INLINE void LL_RTC_TAMPER_DisablePullUp(RTC_TypeDef *RTCx)
{
  SET_BIT(RTCx->TAMPCR, RTC_TAMPCR_TAMPPUDIS);
}

   
                                                                                        
                                                                 
                             
                
    
__STATIC_INLINE void LL_RTC_TAMPER_EnablePullUp(RTC_TypeDef *RTCx)
{
  CLEAR_BIT(RTCx->TAMPCR, RTC_TAMPCR_TAMPPUDIS);
}
#endif                           

#if defined(RTC_TAMPCR_TAMPPRCH)
   
                                            
                                                                 
                             
                                                                       
                                                    
                                                    
                                                    
                                                    
                
    
__STATIC_INLINE void LL_RTC_TAMPER_SetPrecharge(RTC_TypeDef *RTCx, uint32_t Duration)
{
  MODIFY_REG(RTCx->TAMPCR, RTC_TAMPCR_TAMPPRCH, Duration);
}

   
                                            
                                                                 
                             
                                                              
                                                    
                                                    
                                                    
                                                    
    
__STATIC_INLINE uint32_t LL_RTC_TAMPER_GetPrecharge(RTC_TypeDef *RTCx)
{
  return (uint32_t)(READ_BIT(RTCx->TAMPCR, RTC_TAMPCR_TAMPPRCH));
}
#endif                          

#if defined(RTC_TAMPCR_TAMPFLT)
   
                                      
                                                                   
                             
                                                                          
                                                  
                                                  
                                                  
                                                  
                
    
__STATIC_INLINE void LL_RTC_TAMPER_SetFilterCount(RTC_TypeDef *RTCx, uint32_t FilterCount)
{
  MODIFY_REG(RTCx->TAMPCR, RTC_TAMPCR_TAMPFLT, FilterCount);
}

   
                                      
                                                                   
                             
                                                              
                                                  
                                                  
                                                  
                                                  
    
__STATIC_INLINE uint32_t LL_RTC_TAMPER_GetFilterCount(RTC_TypeDef *RTCx)
{
  return (uint32_t)(READ_BIT(RTCx->TAMPCR, RTC_TAMPCR_TAMPFLT));
}
#endif                         

#if defined(RTC_TAMPCR_TAMPFREQ)
   
                                         
                                                                    
                             
                                                                           
                                                      
                                                      
                                                     
                                                     
                                                     
                                                     
                                                    
                                                    
                
    
__STATIC_INLINE void LL_RTC_TAMPER_SetSamplingFreq(RTC_TypeDef *RTCx, uint32_t SamplingFreq)
{
  MODIFY_REG(RTCx->TAMPCR, RTC_TAMPCR_TAMPFREQ, SamplingFreq);
}

   
                                         
                                                                    
                             
                                                              
                                                      
                                                      
                                                     
                                                     
                                                     
                                                     
                                                    
                                                    
    
__STATIC_INLINE uint32_t LL_RTC_TAMPER_GetSamplingFreq(RTC_TypeDef *RTCx)
{
  return (uint32_t)(READ_BIT(RTCx->TAMPCR, RTC_TAMPCR_TAMPFREQ));
}
#endif                          

   
                                                
                                                                        
                                                                        
                                                                      
                             
                                                                               
                                                     
                                                     
                                                     
   
                
    
__STATIC_INLINE void LL_RTC_TAMPER_EnableActiveLevel(RTC_TypeDef *RTCx, uint32_t Tamper)
{
  SET_BIT(RTCx->TAMPCR, Tamper);
}

   
                                                 
                                                                         
                                                                         
                                                                       
                             
                                                                               
                                                     
                                                     
                                                     
   
                
    
__STATIC_INLINE void LL_RTC_TAMPER_DisableActiveLevel(RTC_TypeDef *RTCx, uint32_t Tamper)
{
  CLEAR_BIT(RTCx->TAMPCR, Tamper);
}

   
      
    

#if defined(RTC_BACKUP_SUPPORT)
                                                         
      
    

   
                                                                  
                                                             
                             
                                                                             
                                    
                                    
                                    
                                    
                                    
                                    
                                    
                                    
                                    
                                    
                                     
                                     
                                     
                                     
                                     
                                     
                                     
                                     
                                     
                                     
                                     
                                     
                                     
                                     
                                     
                                     
                                     
                                     
                                     
                                     
                                     
                                     
                                                                    
                
    
__STATIC_INLINE void LL_RTC_BAK_SetRegister(RTC_TypeDef *RTCx, uint32_t BackupRegister, uint32_t Data)
{
  uint32_t tmp = 0U;

  tmp = (uint32_t)(&(RTCx->BKP0R));
  tmp += (BackupRegister * 4U);

                                    
  *(__IO uint32_t *)tmp = (uint32_t)Data;
}

   
                                                                   
                                                             
                             
                                                                             
                                    
                                    
                                    
                                    
                                    
                                    
                                    
                                    
                                    
                                    
                                     
                                     
                                     
                                     
                                     
                                     
                                     
                                     
                                     
                                     
                                     
                                     
                                     
                                     
                                     
                                     
                                     
                                     
                                     
                                     
                                     
                                     
                                                               
    
__STATIC_INLINE uint32_t LL_RTC_BAK_GetRegister(RTC_TypeDef *RTCx, uint32_t BackupRegister)
{
  uint32_t tmp = 0U;

  tmp = (uint32_t)(&(RTCx->BKP0R));
  tmp += (BackupRegister * 4U);

                                   
  return (*(__IO uint32_t *)tmp);
}

   
      
    
#endif                         

                                                       
      
    

   
                                        
                                                                 
                             
                                  
    
__STATIC_INLINE uint32_t LL_RTC_IsActiveFlag_ITS(RTC_TypeDef *RTCx)
{
  return (READ_BIT(RTCx->ISR, RTC_ISR_ITSF) == (RTC_ISR_ITSF));
}

   
                                          
                                                                 
                             
                                  
    
__STATIC_INLINE uint32_t LL_RTC_IsActiveFlag_RECALP(RTC_TypeDef *RTCx)
{
  return (READ_BIT(RTCx->ISR, RTC_ISR_RECALPF) == (RTC_ISR_RECALPF));
}

#if defined(RTC_TAMPER3_SUPPORT)
   
                                        
                                                                
                             
                                  
    
__STATIC_INLINE uint32_t LL_RTC_IsActiveFlag_TAMP3(RTC_TypeDef *RTCx)
{
  return (READ_BIT(RTCx->ISR, RTC_ISR_TAMP3F) == (RTC_ISR_TAMP3F));
}
#endif                          

#if defined(RTC_TAMPER2_SUPPORT)
   
                                        
                                                                
                             
                                  
    
__STATIC_INLINE uint32_t LL_RTC_IsActiveFlag_TAMP2(RTC_TypeDef *RTCx)
{
  return (READ_BIT(RTCx->ISR, RTC_ISR_TAMP2F) == (RTC_ISR_TAMP2F));
}
#endif                          

#if defined(RTC_TAMPER1_SUPPORT)
   
                                        
                                                                
                             
                                  
    
__STATIC_INLINE uint32_t LL_RTC_IsActiveFlag_TAMP1(RTC_TypeDef *RTCx)
{
  return (READ_BIT(RTCx->ISR, RTC_ISR_TAMP1F) == (RTC_ISR_TAMP1F));
}
#endif                          

   
                                        
                                                               
                             
                                  
    
__STATIC_INLINE uint32_t LL_RTC_IsActiveFlag_TSOV(RTC_TypeDef *RTCx)
{
  return (READ_BIT(RTCx->ISR, RTC_ISR_TSOVF) == (RTC_ISR_TSOVF));
}

   
                               
                                                             
                             
                                  
    
__STATIC_INLINE uint32_t LL_RTC_IsActiveFlag_TS(RTC_TypeDef *RTCx)
{
  return (READ_BIT(RTCx->ISR, RTC_ISR_TSF) == (RTC_ISR_TSF));
}

#if defined(RTC_WAKEUP_SUPPORT)
   
                                 
                                                              
                             
                                  
    
__STATIC_INLINE uint32_t LL_RTC_IsActiveFlag_WUT(RTC_TypeDef *RTCx)
{
  return (READ_BIT(RTCx->ISR, RTC_ISR_WUTF) == (RTC_ISR_WUTF));
}
#endif                         

   
                            
                                                               
                             
                                  
    
__STATIC_INLINE uint32_t LL_RTC_IsActiveFlag_ALRB(RTC_TypeDef *RTCx)
{
  return (READ_BIT(RTCx->ISR, RTC_ISR_ALRBF) == (RTC_ISR_ALRBF));
}

   
                            
                                                               
                             
                                  
    
__STATIC_INLINE uint32_t LL_RTC_IsActiveFlag_ALRA(RTC_TypeDef *RTCx)
{
  return (READ_BIT(RTCx->ISR, RTC_ISR_ALRAF) == (RTC_ISR_ALRAF));
}

   
                                          
                                                           
                             
                
    
__STATIC_INLINE void LL_RTC_ClearFlag_ITS(RTC_TypeDef *RTCx)
{
  WRITE_REG(RTCx->ISR, (~((RTC_ISR_ITSF | RTC_ISR_INIT) & 0x0000FFFFU) | (RTCx->ISR & RTC_ISR_INIT)));
}

#if defined(RTC_TAMPER3_SUPPORT)
   
                                          
                                                             
                             
                
    
__STATIC_INLINE void LL_RTC_ClearFlag_TAMP3(RTC_TypeDef *RTCx)
{
  WRITE_REG(RTCx->ISR, (~((RTC_ISR_TAMP3F | RTC_ISR_INIT) & 0x0000FFFFU) | (RTCx->ISR & RTC_ISR_INIT)));
}
#endif                          

#if defined(RTC_TAMPER2_SUPPORT)
   
                                          
                                                             
                             
                
    
__STATIC_INLINE void LL_RTC_ClearFlag_TAMP2(RTC_TypeDef *RTCx)
{
  WRITE_REG(RTCx->ISR, (~((RTC_ISR_TAMP2F | RTC_ISR_INIT) & 0x0000FFFFU) | (RTCx->ISR & RTC_ISR_INIT)));
}
#endif                          

#if defined(RTC_TAMPER1_SUPPORT)
   
                                          
                                                             
                             
                
    
__STATIC_INLINE void LL_RTC_ClearFlag_TAMP1(RTC_TypeDef *RTCx)
{
  WRITE_REG(RTCx->ISR, (~((RTC_ISR_TAMP1F | RTC_ISR_INIT) & 0x0000FFFFU) | (RTCx->ISR & RTC_ISR_INIT)));
}
#endif                          

   
                                          
                                                            
                             
                
    
__STATIC_INLINE void LL_RTC_ClearFlag_TSOV(RTC_TypeDef *RTCx)
{
  WRITE_REG(RTCx->ISR, (~((RTC_ISR_TSOVF | RTC_ISR_INIT) & 0x0000FFFFU) | (RTCx->ISR & RTC_ISR_INIT)));
}

   
                                 
                                                          
                             
                
    
__STATIC_INLINE void LL_RTC_ClearFlag_TS(RTC_TypeDef *RTCx)
{
  WRITE_REG(RTCx->ISR, (~((RTC_ISR_TSF | RTC_ISR_INIT) & 0x0000FFFFU) | (RTCx->ISR & RTC_ISR_INIT)));
}

#if defined(RTC_WAKEUP_SUPPORT)
   
                                   
                                                           
                             
                
    
__STATIC_INLINE void LL_RTC_ClearFlag_WUT(RTC_TypeDef *RTCx)
{
  WRITE_REG(RTCx->ISR, (~((RTC_ISR_WUTF | RTC_ISR_INIT) & 0x0000FFFFU) | (RTCx->ISR & RTC_ISR_INIT)));
}
#endif                         

   
                              
                                                            
                             
                
    
__STATIC_INLINE void LL_RTC_ClearFlag_ALRB(RTC_TypeDef *RTCx)
{
  WRITE_REG(RTCx->ISR, (~((RTC_ISR_ALRBF | RTC_ISR_INIT) & 0x0000FFFFU) | (RTCx->ISR & RTC_ISR_INIT)));
}

   
                              
                                                            
                             
                
    
__STATIC_INLINE void LL_RTC_ClearFlag_ALRA(RTC_TypeDef *RTCx)
{
  WRITE_REG(RTCx->ISR, (~((RTC_ISR_ALRAF | RTC_ISR_INIT) & 0x0000FFFFU) | (RTCx->ISR & RTC_ISR_INIT)));
}

   
                                   
                                                               
                             
                                  
    
__STATIC_INLINE uint32_t LL_RTC_IsActiveFlag_INIT(RTC_TypeDef *RTCx)
{
  return (READ_BIT(RTCx->ISR, RTC_ISR_INITF) == (RTC_ISR_INITF));
}

   
                                              
                                                             
                             
                                  
    
__STATIC_INLINE uint32_t LL_RTC_IsActiveFlag_RS(RTC_TypeDef *RTCx)
{
  return (READ_BIT(RTCx->ISR, RTC_ISR_RSF) == (RTC_ISR_RSF));
}

   
                                                
                                                          
                             
                
    
__STATIC_INLINE void LL_RTC_ClearFlag_RS(RTC_TypeDef *RTCx)
{
  WRITE_REG(RTCx->ISR, (~((RTC_ISR_RSF | RTC_ISR_INIT) & 0x0000FFFFU) | (RTCx->ISR & RTC_ISR_INIT)));
}

   
                                          
                                                                
                             
                                  
    
__STATIC_INLINE uint32_t LL_RTC_IsActiveFlag_INITS(RTC_TypeDef *RTCx)
{
  return (READ_BIT(RTCx->ISR, RTC_ISR_INITS) == (RTC_ISR_INITS));
}

   
                                            
                                                              
                             
                                  
    
__STATIC_INLINE uint32_t LL_RTC_IsActiveFlag_SHP(RTC_TypeDef *RTCx)
{
  return (READ_BIT(RTCx->ISR, RTC_ISR_SHPF) == (RTC_ISR_SHPF));
}

#if defined(RTC_WAKEUP_SUPPORT)
   
                                       
                                                               
                             
                                  
    
__STATIC_INLINE uint32_t LL_RTC_IsActiveFlag_WUTW(RTC_TypeDef *RTCx)
{
  return (READ_BIT(RTCx->ISR, RTC_ISR_WUTWF) == (RTC_ISR_WUTWF));
}
#endif                         

   
                                  
                                                                
                             
                                  
    
__STATIC_INLINE uint32_t LL_RTC_IsActiveFlag_ALRBW(RTC_TypeDef *RTCx)
{
  return (READ_BIT(RTCx->ISR, RTC_ISR_ALRBWF) == (RTC_ISR_ALRBWF));
}

   
                                  
                                                                
                             
                                  
    
__STATIC_INLINE uint32_t LL_RTC_IsActiveFlag_ALRAW(RTC_TypeDef *RTCx)
{
  return (READ_BIT(RTCx->ISR, RTC_ISR_ALRAWF) == (RTC_ISR_ALRAWF));
}

   
      
    

                                                   
      
    

   
                                       
                                                                                                        
                                                           
                             
                
    
__STATIC_INLINE void LL_RTC_EnableIT_TS(RTC_TypeDef *RTCx)
{
  SET_BIT(RTCx->CR, RTC_CR_TSIE);
}

   
                                        
                                                                                                        
                                                            
                             
                
    
__STATIC_INLINE void LL_RTC_DisableIT_TS(RTC_TypeDef *RTCx)
{
  CLEAR_BIT(RTCx->CR, RTC_CR_TSIE);
}

#if defined(RTC_WAKEUP_SUPPORT)
   
                                         
                                                                                                        
                                                             
                             
                
    
__STATIC_INLINE void LL_RTC_EnableIT_WUT(RTC_TypeDef *RTCx)
{
  SET_BIT(RTCx->CR, RTC_CR_WUTIE);
}

   
                                          
                                                                                                        
                                                              
                             
                
    
__STATIC_INLINE void LL_RTC_DisableIT_WUT(RTC_TypeDef *RTCx)
{
  CLEAR_BIT(RTCx->CR, RTC_CR_WUTIE);
}
#endif                         

   
                                    
                                                                                                        
                                                               
                             
                
    
__STATIC_INLINE void LL_RTC_EnableIT_ALRB(RTC_TypeDef *RTCx)
{
  SET_BIT(RTCx->CR, RTC_CR_ALRBIE);
}

   
                                     
                                                                                                        
                                                                
                             
                
    
__STATIC_INLINE void LL_RTC_DisableIT_ALRB(RTC_TypeDef *RTCx)
{
  CLEAR_BIT(RTCx->CR, RTC_CR_ALRBIE);
}

   
                                    
                                                                                                        
                                                               
                             
                
    
__STATIC_INLINE void LL_RTC_EnableIT_ALRA(RTC_TypeDef *RTCx)
{
  SET_BIT(RTCx->CR, RTC_CR_ALRAIE);
}

   
                                     
                                                                                                        
                                                                
                             
                
    
__STATIC_INLINE void LL_RTC_DisableIT_ALRA(RTC_TypeDef *RTCx)
{
  CLEAR_BIT(RTCx->CR, RTC_CR_ALRAIE);
}


#if defined(RTC_TAMPER3_SUPPORT)
   
                                     
                                                            
                             
                
    
__STATIC_INLINE void LL_RTC_EnableIT_TAMP3(RTC_TypeDef *RTCx)
{
  SET_BIT(RTCx->TAMPCR, RTC_TAMPCR_TAMP3IE);
}

   
                                      
                                                             
                             
                
    
__STATIC_INLINE void LL_RTC_DisableIT_TAMP3(RTC_TypeDef *RTCx)
{
  CLEAR_BIT(RTCx->TAMPCR, RTC_TAMPCR_TAMP3IE);
}
#endif                          

#if defined(RTC_TAMPER2_SUPPORT)
   
                                     
                                                            
                             
                
    
__STATIC_INLINE void LL_RTC_EnableIT_TAMP2(RTC_TypeDef *RTCx)
{
  SET_BIT(RTCx->TAMPCR, RTC_TAMPCR_TAMP2IE);
}

   
                                      
                                                             
                             
                
    
__STATIC_INLINE void LL_RTC_DisableIT_TAMP2(RTC_TypeDef *RTCx)
{
  CLEAR_BIT(RTCx->TAMPCR, RTC_TAMPCR_TAMP2IE);
}
#endif                          

#if defined(RTC_TAMPER1_SUPPORT)
   
                                     
                                                            
                             
                
    
__STATIC_INLINE void LL_RTC_EnableIT_TAMP1(RTC_TypeDef *RTCx)
{
  SET_BIT(RTCx->TAMPCR, RTC_TAMPCR_TAMP1IE);
}

   
                                      
                                                             
                             
                
    
__STATIC_INLINE void LL_RTC_DisableIT_TAMP1(RTC_TypeDef *RTCx)
{
  CLEAR_BIT(RTCx->TAMPCR, RTC_TAMPCR_TAMP1IE);
}
#endif                          

   
                                       
                                                           
                             
                
    
__STATIC_INLINE void LL_RTC_EnableIT_TAMP(RTC_TypeDef *RTCx)
{
  SET_BIT(RTCx->TAMPCR, RTC_TAMPCR_TAMPIE);
}

   
                                        
                                                            
                             
                
    
__STATIC_INLINE void LL_RTC_DisableIT_TAMP(RTC_TypeDef *RTCx)
{
  CLEAR_BIT(RTCx->TAMPCR, RTC_TAMPCR_TAMPIE);
}

   
                                                            
                                                            
                             
                                  
    
__STATIC_INLINE uint32_t LL_RTC_IsEnabledIT_TS(RTC_TypeDef *RTCx)
{
  return (READ_BIT(RTCx->CR, RTC_CR_TSIE) == (RTC_CR_TSIE));
}

#if defined(RTC_WAKEUP_SUPPORT)
   
                                                              
                                                             
                             
                                  
    
__STATIC_INLINE uint32_t LL_RTC_IsEnabledIT_WUT(RTC_TypeDef *RTCx)
{
  return (READ_BIT(RTCx->CR, RTC_CR_WUTIE) == (RTC_CR_WUTIE));
}
#endif                         

   
                                                         
                                                              
                             
                                  
    
__STATIC_INLINE uint32_t LL_RTC_IsEnabledIT_ALRB(RTC_TypeDef *RTCx)
{
  return (READ_BIT(RTCx->CR, RTC_CR_ALRBIE) == (RTC_CR_ALRBIE));
}

   
                                                         
                                                              
                             
                                  
    
__STATIC_INLINE uint32_t LL_RTC_IsEnabledIT_ALRA(RTC_TypeDef *RTCx)
{
  return (READ_BIT(RTCx->CR, RTC_CR_ALRAIE) == (RTC_CR_ALRAIE));
}

#if defined(RTC_TAMPER3_SUPPORT)
   
                                                          
                                                               
                             
                                  
    
__STATIC_INLINE uint32_t LL_RTC_IsEnabledIT_TAMP3(RTC_TypeDef *RTCx)
{
  return (READ_BIT(RTCx->TAMPCR,
                   RTC_TAMPCR_TAMP3IE) == (RTC_TAMPCR_TAMP3IE));
}
#endif                          

#if defined(RTC_TAMPER2_SUPPORT)
   
                                                          
                                                               
                             
                                  
    
__STATIC_INLINE uint32_t LL_RTC_IsEnabledIT_TAMP2(RTC_TypeDef *RTCx)
{
  return (READ_BIT(RTCx->TAMPCR,
                   RTC_TAMPCR_TAMP2IE) == (RTC_TAMPCR_TAMP2IE));

}
#endif                          

#if defined(RTC_TAMPER1_SUPPORT)
   
                                                          
                                                               
                             
                                  
    
__STATIC_INLINE uint32_t LL_RTC_IsEnabledIT_TAMP1(RTC_TypeDef *RTCx)
{
  return (READ_BIT(RTCx->TAMPCR,
                   RTC_TAMPCR_TAMP1IE) == (RTC_TAMPCR_TAMP1IE));
}
#endif                          

   
                                                                 
                                                              
                             
                                  
    
__STATIC_INLINE uint32_t LL_RTC_IsEnabledIT_TAMP(RTC_TypeDef *RTCx)
{
  return (READ_BIT(RTCx->TAMPCR,
                   RTC_TAMPCR_TAMPIE) == (RTC_TAMPCR_TAMPIE));
}

   
      
    

#endif                                                                                                         

#if defined(USE_FULL_LL_DRIVER)
                                                                           
      
    

ErrorStatus LL_RTC_DeInit(RTC_TypeDef *RTCx);
ErrorStatus LL_RTC_Init(RTC_TypeDef *RTCx, LL_RTC_InitTypeDef *RTC_InitStruct);
void        LL_RTC_StructInit(LL_RTC_InitTypeDef *RTC_InitStruct);
ErrorStatus LL_RTC_TIME_Init(RTC_TypeDef *RTCx, uint32_t RTC_Format, LL_RTC_TimeTypeDef *RTC_TimeStruct);
void        LL_RTC_TIME_StructInit(LL_RTC_TimeTypeDef *RTC_TimeStruct);
ErrorStatus LL_RTC_DATE_Init(RTC_TypeDef *RTCx, uint32_t RTC_Format, LL_RTC_DateTypeDef *RTC_DateStruct);
void        LL_RTC_DATE_StructInit(LL_RTC_DateTypeDef *RTC_DateStruct);
ErrorStatus LL_RTC_ALMA_Init(RTC_TypeDef *RTCx, uint32_t RTC_Format, LL_RTC_AlarmTypeDef *RTC_AlarmStruct);
ErrorStatus LL_RTC_ALMB_Init(RTC_TypeDef *RTCx, uint32_t RTC_Format, LL_RTC_AlarmTypeDef *RTC_AlarmStruct);
void        LL_RTC_ALMA_StructInit(LL_RTC_AlarmTypeDef *RTC_AlarmStruct);
void        LL_RTC_ALMB_StructInit(LL_RTC_AlarmTypeDef *RTC_AlarmStruct);
ErrorStatus LL_RTC_EnterInitMode(RTC_TypeDef *RTCx);
ErrorStatus LL_RTC_ExitInitMode(RTC_TypeDef *RTCx);
ErrorStatus LL_RTC_WaitForSynchro(RTC_TypeDef *RTCx);

   
      
    
#endif                         

   
      
    

   
      
    

#endif                   

   
      
    

#ifdef __cplusplus
}
#endif

#endif                         
