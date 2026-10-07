/**
  ******************************************************************************
  * @file    stm32l4xx_hal_rtc.h
  * @author  MCD Application Team
  * @brief   Header file of RTC HAL module.
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

                                                                                
#ifndef STM32L4xx_HAL_RTC_H
#define STM32L4xx_HAL_RTC_H

#ifdef __cplusplus
extern "C" {
#endif

                                                                                
#include "stm32l4xx_hal_def.h"

                                    
      
    

                     
      
    

                                                                                
                                                   
      
    

   
                                           
    
typedef enum
{
  HAL_RTC_STATE_RESET             = 0x00U,                                             
  HAL_RTC_STATE_READY             = 0x01U,                                             
  HAL_RTC_STATE_BUSY              = 0x02U,                                             
  HAL_RTC_STATE_TIMEOUT           = 0x03U,                                             
  HAL_RTC_STATE_ERROR             = 0x04U                                              

} HAL_RTCStateTypeDef;

   
                                                  
    
typedef struct
{
  uint32_t HourFormat;                                         
                                                                                          

  uint32_t AsynchPrediv;                                                         
                                                                                                               

  uint32_t SynchPrediv;                                                         
                                                                                                                 

  uint32_t OutPut;                                                                       
                                                                                                            

  uint32_t OutPutRemap;                                             
                                                                                                     

  uint32_t OutPutPolarity;                                                   
                                                                                                         

  uint32_t OutPutType;                                             
                                                                                                   
#if defined(STM32L412xx) || defined(STM32L422xx) || defined (STM32L4P5xx) || defined (STM32L4Q5xx)
  uint32_t OutPutPullUp;                                               
                                                                                                     
#endif

#if defined (STM32L4P5xx) || defined (STM32L4Q5xx)
  uint32_t BinMode;                                            
                                                                                           

  uint32_t BinMixBcdU;                                                                                     
                                                                                               
#endif
} RTC_InitTypeDef;

   
                                         
    
typedef struct
{
  uint8_t Hours;                                             
                                                                                                                                             
                                                                                                                                               

  uint8_t Minutes;                                              
                                                                                                          

  uint8_t Seconds;                                              
                                                                                                          

  uint8_t TimeFormat;                                         
                                                                                               

#if defined (STM32L4P5xx) || defined (STM32L4Q5xx)
  uint32_t SubSeconds;                                                                 
                                                                           
                                                                                                       
                                                                                                                                                       
                                     
                                                                                                       
#else
  uint32_t SubSeconds;                                                                 
                                                                                                     
                                                                                
#endif

  uint32_t SecondFraction;                                                                        
                                                                                                
                                                                                                     
                                                                              
                                                                                            

  uint32_t DayLightSaving;                                                                                                            

  uint32_t StoreOperation;                                                                                                            
} RTC_TimeTypeDef;

   
                                         
    
typedef struct
{
  uint8_t WeekDay;                                      
                                                                                         

  uint8_t Month;                                                      
                                                                                            

  uint8_t Date;                                 
                                                                                                  

  uint8_t Year;                                      
                                                                                                  

} RTC_DateTypeDef;

   
                                          
    
typedef struct
{
  RTC_TimeTypeDef AlarmTime;                                                 

  uint32_t AlarmMask;                                               
                                                                                                        

#if defined (STM32L4P5xx) || defined (STM32L4Q5xx)
  uint32_t SubSeconds;                                                                      
                                                                                
                                                                                                             
                                                                                                                                                             
                                           
                                                                                                             
  uint32_t BinaryAutoClr;                                                                   
                                                                                                                           
                                                                                                                               
#else
  uint32_t SubSeconds;                                                                         
#endif

  uint32_t AlarmSubSecondMask;                                                 
                                                                                                                      

  uint32_t AlarmDateWeekDaySel;                                                     
                                                                                                              

  uint8_t AlarmDateWeekDay;                                                
                                                                                                                             
                                                                                                                                        

  uint32_t Alarm;                                          
                                                                                                     
} RTC_AlarmTypeDef;

   
                                           
    
#if (USE_HAL_RTC_REGISTER_CALLBACKS == 1)
typedef struct __RTC_HandleTypeDef
#else
typedef struct
#endif                                       
{
  RTC_TypeDef               *Instance;                                  

#if defined(STM32L412xx) || defined(STM32L422xx) || defined (STM32L4P5xx) || defined (STM32L4Q5xx)
  uint32_t                  TampOffset;                                 
#endif
  RTC_InitTypeDef           Init;                                       

  HAL_LockTypeDef           Lock;                                       

  __IO HAL_RTCStateTypeDef  State;                                      

#if (USE_HAL_RTC_REGISTER_CALLBACKS == 1)
  void (* AlarmAEventCallback)(struct __RTC_HandleTypeDef *hrtc);                                                                 
  void (* AlarmBEventCallback)(struct __RTC_HandleTypeDef *hrtc);                                                                 
  void (* TimeStampEventCallback)(struct __RTC_HandleTypeDef *hrtc);                                                              
  void (* WakeUpTimerEventCallback)(struct __RTC_HandleTypeDef *hrtc);                                                            
#if defined (STM32L4P5xx) || defined (STM32L4Q5xx)
  void (* SSRUEventCallback)(struct __RTC_HandleTypeDef *hrtc);                                                                   
#endif
#if defined(RTC_TAMPER1_SUPPORT)
  void (* Tamper1EventCallback)(struct __RTC_HandleTypeDef *hrtc);                                                                
#endif                          
  void (* Tamper2EventCallback)(struct __RTC_HandleTypeDef *hrtc);                                                                
#if defined(RTC_TAMPER3_SUPPORT)
  void (* Tamper3EventCallback)(struct __RTC_HandleTypeDef *hrtc);                                                                
#endif                          
  void (* MspInitCallback)(struct __RTC_HandleTypeDef *hrtc);                                                                     
  void (* MspDeInitCallback)(struct __RTC_HandleTypeDef *hrtc);                                                                   
#endif                                            

} RTC_HandleTypeDef;

#if (USE_HAL_RTC_REGISTER_CALLBACKS == 1)
   
                                                      
    
typedef enum
{
  HAL_RTC_ALARM_A_EVENT_CB_ID            =  0u,                                                               
  HAL_RTC_ALARM_B_EVENT_CB_ID            =  1u,                                                               
  HAL_RTC_TIMESTAMP_EVENT_CB_ID          =  2u,                                                               
  HAL_RTC_WAKEUPTIMER_EVENT_CB_ID        =  3u,                                                               
#if defined (STM32L4P5xx) || defined (STM32L4Q5xx)
  HAL_RTC_SSRU_EVENT_CB_ID               =  4u                                                                
#endif
#if defined(RTC_TAMPER1_SUPPORT)
  HAL_RTC_TAMPER1_EVENT_CB_ID            =  5u,                                                               
#endif                          
  HAL_RTC_TAMPER2_EVENT_CB_ID            =  6u,                                                               
#if defined(RTC_TAMPER3_SUPPORT)
  HAL_RTC_TAMPER3_EVENT_CB_ID            =  7u,                                                               
#endif                          
  HAL_RTC_MSPINIT_CB_ID                  =  8u,                                                               
  HAL_RTC_MSPDEINIT_CB_ID                =  9u                                                                
} HAL_RTC_CallbackIDTypeDef;

   
                                               
    
typedef  void (*pRTC_CallbackTypeDef)(RTC_HandleTypeDef *hrtc);                                             
#endif                                            

   
      
    

                                                                                
                                                           
      
    

                                                                       
      
    
#define RTC_HOURFORMAT_24                   0x00000000u
#define RTC_HOURFORMAT_12                   RTC_CR_FMT
   
      
    

                                                                                   
      
    
#define RTC_OUTPUT_DISABLE                  0x00000000u
#define RTC_OUTPUT_ALARMA                   RTC_CR_OSEL_0
#define RTC_OUTPUT_ALARMB                   RTC_CR_OSEL_1
#define RTC_OUTPUT_WAKEUP                   RTC_CR_OSEL
#if defined(STM32L412xx) || defined(STM32L422xx) || defined (STM32L4P5xx) || defined (STM32L4Q5xx)
#define RTC_OUTPUT_TAMPER                   RTC_CR_TAMPOE
#endif
   
      
    

                                                                             
      
    
#define RTC_OUTPUT_POLARITY_HIGH            0x00000000u
#define RTC_OUTPUT_POLARITY_LOW             RTC_CR_POL
   
      
    

                                                                 
      
    
#if defined(STM32L412xx) || defined(STM32L422xx) || defined (STM32L4P5xx) || defined (STM32L4Q5xx)
#define RTC_OUTPUT_TYPE_PUSHPULL            0x00000000u
#define RTC_OUTPUT_TYPE_OPENDRAIN           RTC_CR_TAMPALRM_TYPE
#else
#define RTC_OUTPUT_TYPE_PUSHPULL            RTC_OR_ALARMOUTTYPE
#define RTC_OUTPUT_TYPE_OPENDRAIN           0x00000000u
#endif
   
      
    

                                                                      
      
    
#if defined(STM32L412xx) || defined(STM32L422xx) || defined (STM32L4P5xx) || defined (STM32L4Q5xx)
#define RTC_OUTPUT_PULLUP_NONE              0x00000000u
#define RTC_OUTPUT_PULLUP_ON                RTC_CR_TAMPALRM_PU
#endif
   
      
    

                                                                   
      
    
#if defined(STM32L412xx) || defined(STM32L422xx) || defined (STM32L4P5xx) || defined (STM32L4Q5xx)
#define RTC_OUTPUT_REMAP_NONE               0x00000000u
#define RTC_OUTPUT_REMAP_POS1               RTC_CR_OUT2EN
#else
#define RTC_OUTPUT_REMAP_NONE               0x00000000u
#define RTC_OUTPUT_REMAP_POS1               RTC_OR_OUT_RMP
#endif
   
      
    

                                                         
      
    
#define RTC_HOURFORMAT12_AM            ((uint8_t)0x00)
#define RTC_HOURFORMAT12_PM            ((uint8_t)0x01)
   
      
    

                                                                           
      
    
#define RTC_DAYLIGHTSAVING_SUB1H            RTC_CR_SUB1H
#define RTC_DAYLIGHTSAVING_ADD1H            RTC_CR_ADD1H
#define RTC_DAYLIGHTSAVING_NONE             0x00000000u
   
      
    

                                                                           
      
    
#define RTC_STOREOPERATION_RESET            0x00000000u
#define RTC_STOREOPERATION_SET              RTC_CR_BKP
   
      
    

#if defined (STM32L4P5xx) || defined (STM32L4Q5xx)
                                                                                                                                                        
                                                                                              
      
    
#define RTC_FORMAT_BIN                      0x00000000u                                                                                                     
                                                                                                                                    

#define RTC_FORMAT_BCD                      0x00000001u                                     
                                                                                                                                    
   
      
    
#else

                                                                                           
      
    
#define RTC_FORMAT_BIN                      0x00000000u
#define RTC_FORMAT_BCD                      0x00000001u
   
      
    
#endif

                                                                                   
      
    

                         
#define RTC_MONTH_JANUARY                   ((uint8_t)0x01U)
#define RTC_MONTH_FEBRUARY                  ((uint8_t)0x02U)
#define RTC_MONTH_MARCH                     ((uint8_t)0x03U)
#define RTC_MONTH_APRIL                     ((uint8_t)0x04U)
#define RTC_MONTH_MAY                       ((uint8_t)0x05U)
#define RTC_MONTH_JUNE                      ((uint8_t)0x06U)
#define RTC_MONTH_JULY                      ((uint8_t)0x07U)
#define RTC_MONTH_AUGUST                    ((uint8_t)0x08U)
#define RTC_MONTH_SEPTEMBER                 ((uint8_t)0x09U)
#define RTC_MONTH_OCTOBER                   ((uint8_t)0x10U)
#define RTC_MONTH_NOVEMBER                  ((uint8_t)0x11U)
#define RTC_MONTH_DECEMBER                  ((uint8_t)0x12U)

   
      
    

                                                             
      
    
#define RTC_WEEKDAY_MONDAY                  ((uint8_t)0x01U)
#define RTC_WEEKDAY_TUESDAY                 ((uint8_t)0x02U)
#define RTC_WEEKDAY_WEDNESDAY               ((uint8_t)0x03U)
#define RTC_WEEKDAY_THURSDAY                ((uint8_t)0x04U)
#define RTC_WEEKDAY_FRIDAY                  ((uint8_t)0x05U)
#define RTC_WEEKDAY_SATURDAY                ((uint8_t)0x06U)
#define RTC_WEEKDAY_SUNDAY                  ((uint8_t)0x07U)

   
      
    

                                                                               
      
    
#define RTC_ALARMDATEWEEKDAYSEL_DATE        0x00000000u
#define RTC_ALARMDATEWEEKDAYSEL_WEEKDAY     RTC_ALRMAR_WDSEL

   
      
    

                                                                 
      
    
#define RTC_ALARMMASK_NONE                  0x00000000u
#define RTC_ALARMMASK_DATEWEEKDAY           RTC_ALRMAR_MSK4
#define RTC_ALARMMASK_HOURS                 RTC_ALRMAR_MSK3
#define RTC_ALARMMASK_MINUTES               RTC_ALRMAR_MSK2
#define RTC_ALARMMASK_SECONDS               RTC_ALRMAR_MSK1
#define RTC_ALARMMASK_ALL                   (RTC_ALARMMASK_DATEWEEKDAY | RTC_ALARMMASK_HOURS  | \
                                             RTC_ALARMMASK_MINUTES | RTC_ALARMMASK_SECONDS)

   
      
    

                                                           
      
    
#define RTC_ALARM_A                         RTC_CR_ALRAE
#define RTC_ALARM_B                         RTC_CR_ALRBE

   
      
    


                                                                                             
      
    
#define RTC_ALARMSUBSECONDMASK_ALL          0x00000000u                                                                                                  
                                                                                                                                                               
                                                                                                                                      
#define RTC_ALARMSUBSECONDMASK_SS14_1       RTC_ALRMASSR_MASKSS_0                                                                                         
                                                                                                                                                                   
#define RTC_ALARMSUBSECONDMASK_SS14_2       RTC_ALRMASSR_MASKSS_1                                                                                         
                                                                                                                                                                   
#define RTC_ALARMSUBSECONDMASK_SS14_3       (RTC_ALRMASSR_MASKSS_0 | RTC_ALRMASSR_MASKSS_1)                                                               
                                                                                                                                                                   
#define RTC_ALARMSUBSECONDMASK_SS14_4       RTC_ALRMASSR_MASKSS_2                                                                                         
                                                                                                                                                                   
#define RTC_ALARMSUBSECONDMASK_SS14_5       (RTC_ALRMASSR_MASKSS_0 | RTC_ALRMASSR_MASKSS_2)                                                               
                                                                                                                                                                   
#define RTC_ALARMSUBSECONDMASK_SS14_6       (RTC_ALRMASSR_MASKSS_1 | RTC_ALRMASSR_MASKSS_2)                                                               
                                                                                                                                                                   
#define RTC_ALARMSUBSECONDMASK_SS14_7       (RTC_ALRMASSR_MASKSS_0 | RTC_ALRMASSR_MASKSS_1 | RTC_ALRMASSR_MASKSS_2)                                       
                                                                                                                                                                   
#define RTC_ALARMSUBSECONDMASK_SS14_8       RTC_ALRMASSR_MASKSS_3                                                                                         
                                                                                                                                                                   
#define RTC_ALARMSUBSECONDMASK_SS14_9       (RTC_ALRMASSR_MASKSS_0 | RTC_ALRMASSR_MASKSS_3)                                                               
                                                                                                                                                                   
#define RTC_ALARMSUBSECONDMASK_SS14_10      (RTC_ALRMASSR_MASKSS_1 | RTC_ALRMASSR_MASKSS_3)                                                                
                                                                                                                                                                   
#define RTC_ALARMSUBSECONDMASK_SS14_11      (RTC_ALRMASSR_MASKSS_0 | RTC_ALRMASSR_MASKSS_1 | RTC_ALRMASSR_MASKSS_3)                                        
                                                                                                                                                                   
#define RTC_ALARMSUBSECONDMASK_SS14_12      (RTC_ALRMASSR_MASKSS_2 | RTC_ALRMASSR_MASKSS_3)                                                                
                                                                                                                                                                   
#define RTC_ALARMSUBSECONDMASK_SS14_13      (RTC_ALRMASSR_MASKSS_0 | RTC_ALRMASSR_MASKSS_2 | RTC_ALRMASSR_MASKSS_3)                                        
                                                                                                                                                                   
#define RTC_ALARMSUBSECONDMASK_SS14         (RTC_ALRMASSR_MASKSS_1 | RTC_ALRMASSR_MASKSS_2 | RTC_ALRMASSR_MASKSS_3)                                    
                                                                                                                                                                   
#define RTC_ALARMSUBSECONDMASK_NONE         RTC_ALRMASSR_MASKSS                                                                                               
                                                                                                                                               
   
      
    

                                                                   
      
    
#define RTC_IT_TS                           RTC_CR_TSIE                                             
#define RTC_IT_WUT                          RTC_CR_WUTIE                                            
#if defined (STM32L4P5xx) || defined (STM32L4Q5xx)
#define RTC_IT_SSRU                         RTC_CR_SSRUIE                                            
#endif
#define RTC_IT_ALRA                         RTC_CR_ALRAIE                                           
#define RTC_IT_ALRB                         RTC_CR_ALRBIE                                           
   
      
    

#if defined(STM32L412xx) || defined(STM32L422xx) || defined (STM32L4P5xx) || defined (STM32L4Q5xx)
                                                                                      
      
    
#define RTC_FLAG_MASK                       0x001Fu                                          
   
      
    

                                                         
                                                        
                                                                           
                                                       
                                       
                                                              
      
    
#define RTC_FLAG_RECALPF                    (0x00000100U | RTC_ICSR_RECALPF_Pos)                                   
#define RTC_FLAG_INITF                      (0x00000100U | RTC_ICSR_INITF_Pos)                              
#define RTC_FLAG_RSF                        (0x00000100U | RTC_ICSR_RSF_Pos)                                           
#define RTC_FLAG_INITS                      (0x00000100U | RTC_ICSR_INITS_Pos)                                     
#define RTC_FLAG_SHPF                       (0x00000100U | RTC_ICSR_SHPF_Pos)                                        
#define RTC_FLAG_WUTWF                      (0x00000100U | RTC_ICSR_WUTWF_Pos)                                  
#if defined (STM32L4P5xx) || defined (STM32L4Q5xx)
#define RTC_FLAG_SSRUF                      (0x00000200U | RTC_SR_SSRUF_Pos)                               
#endif
#define RTC_FLAG_ITSF                       (0x00000200U | RTC_SR_ITSF_Pos)                                      
#define RTC_FLAG_TSOVF                      (0x00000200U | RTC_SR_TSOVF_Pos)                                     
#define RTC_FLAG_TSF                        (0x00000200U | RTC_SR_TSF_Pos)                              
#define RTC_FLAG_WUTF                       (0x00000200U | RTC_SR_WUTF_Pos)                               
#define RTC_FLAG_ALRBF                      (0x00000200U | RTC_SR_ALRBF_Pos)                         
#define RTC_FLAG_ALRAF                      (0x00000200U | RTC_SR_ALRAF_Pos)                         
   
      
    

                                                                     
      
    
#if defined (STM32L4P5xx) || defined (STM32L4Q5xx)
#define RTC_CLEAR_SSRUF                     RTC_SCR_CSSRUF                                   
#endif
#define RTC_CLEAR_ITSF                      RTC_SCR_CITSF                                          
#define RTC_CLEAR_TSOVF                     RTC_SCR_CTSOVF                                         
#define RTC_CLEAR_TSF                       RTC_SCR_CTSF                                  
#define RTC_CLEAR_WUTF                      RTC_SCR_CWUTF                                   
#define RTC_CLEAR_ALRBF                     RTC_SCR_CALRBF                             
#define RTC_CLEAR_ALRAF                     RTC_SCR_CALRAF                             

   
      
    

#else                                                                                                         

                                                         
      
    
#define RTC_FLAG_RECALPF                    RTC_ISR_RECALPF
#define RTC_FLAG_TSOVF                      RTC_ISR_TSOVF
#define RTC_FLAG_TSF                        RTC_ISR_TSF
#define RTC_FLAG_ITSF                       RTC_ISR_ITSF
#define RTC_FLAG_WUTF                       RTC_ISR_WUTF
#define RTC_FLAG_ALRBF                      RTC_ISR_ALRBF
#define RTC_FLAG_ALRAF                      RTC_ISR_ALRAF
#define RTC_FLAG_INITF                      RTC_ISR_INITF
#define RTC_FLAG_RSF                        RTC_ISR_RSF
#define RTC_FLAG_INITS                      RTC_ISR_INITS
#define RTC_FLAG_SHPF                       RTC_ISR_SHPF
#define RTC_FLAG_WUTWF                      RTC_ISR_WUTWF
#define RTC_FLAG_ALRBWF                     RTC_ISR_ALRBWF
#define RTC_FLAG_ALRAWF                     RTC_ISR_ALRAWF
   
      
    
#endif                                                                                                         

   
      
    

                                                                                
                                                     
      
    

                                 
                                  
                
    
#if (USE_HAL_RTC_REGISTER_CALLBACKS == 1)
#define __HAL_RTC_RESET_HANDLE_STATE(__HANDLE__) do{\
                                                      (__HANDLE__)->State = HAL_RTC_STATE_RESET;\
                                                      (__HANDLE__)->MspInitCallback = NULL;\
                                                      (__HANDLE__)->MspDeInitCallback = NULL;\
                                                     }while(0u)
#else
#define __HAL_RTC_RESET_HANDLE_STATE(__HANDLE__) ((__HANDLE__)->State = HAL_RTC_STATE_RESET)
#endif                                     

   
                                                           
                                                
                
    
#define __HAL_RTC_WRITEPROTECTION_DISABLE(__HANDLE__)             \
                        do{                                       \
                            (__HANDLE__)->Instance->WPR = 0xCAU;   \
                            (__HANDLE__)->Instance->WPR = 0x53U;   \
                          } while(0u)

   
                                                          
                                                
                
    
#define __HAL_RTC_WRITEPROTECTION_ENABLE(__HANDLE__)              \
                        do{                                       \
                            (__HANDLE__)->Instance->WPR = 0xFFU;   \
                          } while(0u)

   
                                                             
                                                
                
    
#if defined(STM32L412xx) || defined(STM32L422xx) || defined (STM32L4P5xx) || defined (STM32L4Q5xx)
#define __HAL_RTC_IS_CALENDAR_INITIALIZED(__HANDLE__)  ((((RTC->ICSR) & (RTC_ICSR_INITS)) == RTC_ICSR_INITS) ? 1U : 0U)
#else
#define __HAL_RTC_IS_CALENDAR_INITIALIZED(__HANDLE__)  (((((__HANDLE__)->Instance->ISR) & (RTC_FLAG_INITS)) == RTC_FLAG_INITS) ? 1U : 0U)
#endif                                                                                                         

#if defined (STM32L4P5xx) || defined (STM32L4Q5xx)
   
                                
                                                
                                                                                               
    
#define __HAL_RTC_GET_BINARY_MODE(__HANDLE__) (READ_REG(RTC->ICSR & RTC_ICSR_BIN))
#endif                                                         

   
                                            
                                         
                                                                                
                                                
                          
                                  
                                                 
                                               
                
    
#define __HAL_RTC_DAYLIGHT_SAVING_TIME_ADD1H(__HANDLE__, __BKP__)                         \
                        do {                                                              \
                            __HAL_RTC_WRITEPROTECTION_DISABLE(__HANDLE__);                \
                            SET_BIT((__HANDLE__)->Instance->CR, RTC_CR_ADD1H);            \
                            MODIFY_REG((__HANDLE__)->Instance->CR, RTC_CR_BKP , (__BKP__)); \
                            __HAL_RTC_WRITEPROTECTION_ENABLE(__HANDLE__);                 \
                        } while(0u);

   
                                                 
                                         
                                                                                
                                                
                          
                                  
                                                 
                                               
                
    
#define __HAL_RTC_DAYLIGHT_SAVING_TIME_SUB1H(__HANDLE__, __BKP__)                         \
                        do {                                                              \
                            __HAL_RTC_WRITEPROTECTION_DISABLE(__HANDLE__);                \
                            SET_BIT((__HANDLE__)->Instance->CR, RTC_CR_SUB1H);            \
                            MODIFY_REG((__HANDLE__)->Instance->CR, RTC_CR_BKP , (__BKP__)); \
                            __HAL_RTC_WRITEPROTECTION_ENABLE(__HANDLE__);                 \
                        } while(0u);

   
                                            
                                               
               
   
#define __HAL_RTC_ALARMA_ENABLE(__HANDLE__)  ((__HANDLE__)->Instance->CR |= (RTC_CR_ALRAE))

   
                                              
                                                
                
    
#define __HAL_RTC_ALARMA_DISABLE(__HANDLE__)  ((__HANDLE__)->Instance->CR &= ~(RTC_CR_ALRAE))

   
                                             
                                                
                
    
#define __HAL_RTC_ALARMB_ENABLE(__HANDLE__)   ((__HANDLE__)->Instance->CR |= (RTC_CR_ALRBE))

   
                                              
                                                
                
    
#define __HAL_RTC_ALARMB_DISABLE(__HANDLE__)  ((__HANDLE__)->Instance->CR &= ~(RTC_CR_ALRBE))

   
                                           
                                                
                                                                                              
                                                                           
                                                       
                                                       
                
    
#define __HAL_RTC_ALARM_ENABLE_IT(__HANDLE__, __INTERRUPT__)   ((__HANDLE__)->Instance->CR |= (__INTERRUPT__))

   
                                            
                                                
                                                                                              
                                                                          
                                                      
                                                      
                
    
#define __HAL_RTC_ALARM_DISABLE_IT(__HANDLE__, __INTERRUPT__) ((__HANDLE__)->Instance->CR &= ~(__INTERRUPT__))

   
                                                                                
                                                
                                                                             
                                  
                                                      
                                                      
                
    
#if defined(STM32L412xx) || defined(STM32L422xx) || defined (STM32L4P5xx) || defined (STM32L4Q5xx)
#define __HAL_RTC_ALARM_GET_IT(__HANDLE__, __INTERRUPT__) (((((__HANDLE__)->Instance->MISR)& (__INTERRUPT__ >> 12)) != 0U)? 1U : 0U)
#else
#define __HAL_RTC_ALARM_GET_IT(__HANDLE__, __INTERRUPT__) (((((__HANDLE__)->Instance->ISR)& (__INTERRUPT__ >> 4)) != 0U)? 1U : 0U)
#endif
   
                                                                                    
                                                
                                                                             
                                  
                                                      
                                                      
                
    
#define __HAL_RTC_ALARM_GET_IT_SOURCE(__HANDLE__, __INTERRUPT__)     (((((__HANDLE__)->Instance->CR) & (__INTERRUPT__)) != 0U) ? 1U : 0U)

#if defined(STM32L412xx) || defined(STM32L422xx) || defined (STM32L4P5xx) || defined (STM32L4Q5xx)
   
                                                     
                                                
                                                                   
                                  
                                       
                                       
                
    
#define __HAL_RTC_ALARM_GET_FLAG(__HANDLE__, __FLAG__)   (__HAL_RTC_GET_FLAG((__HANDLE__), (__FLAG__)))

#else                                                                                                         

   
                                                     
                                                
                                                                   
                                  
                                       
                                       
                                        
                                        
                
    
#define __HAL_RTC_ALARM_GET_FLAG(__HANDLE__, __FLAG__)  (((((__HANDLE__)->Instance->ISR) & (__FLAG__)) != 0U) ? 1U : 0U)
#endif                                                                                                         

   
                                                
                                                
                                                                   
                                   
                                        
                                        
                
    
#if defined(STM32L412xx) || defined(STM32L422xx) || defined (STM32L4P5xx) || defined (STM32L4Q5xx)
#define __HAL_RTC_ALARM_CLEAR_FLAG(__HANDLE__, __FLAG__)   (((__FLAG__) == RTC_FLAG_ALRAF) ? (((__HANDLE__)->Instance->SCR = (RTC_CLEAR_ALRAF))) : \
                                                           ((__HANDLE__)->Instance->SCR = (RTC_CLEAR_ALRBF)))
#else
#define __HAL_RTC_ALARM_CLEAR_FLAG(__HANDLE__, __FLAG__)  ((__HANDLE__)->Instance->ISR = (~((__FLAG__) | RTC_ISR_INIT)|((__HANDLE__)->Instance->ISR & RTC_ISR_INIT)))
#endif

   
                                                                   
                
    
#define __HAL_RTC_ALARM_EXTI_ENABLE_IT()            (EXTI->IMR1 |= RTC_EXTI_LINE_ALARM_EVENT)

   
                                                                    
                
    
#define __HAL_RTC_ALARM_EXTI_DISABLE_IT()           (EXTI->IMR1 &= ~(RTC_EXTI_LINE_ALARM_EVENT))

   
                                                               
                 
    
#define __HAL_RTC_ALARM_EXTI_ENABLE_EVENT()         (EXTI->EMR1 |= RTC_EXTI_LINE_ALARM_EVENT)

   
                                                                
                 
    
#define __HAL_RTC_ALARM_EXTI_DISABLE_EVENT()         (EXTI->EMR1 &= ~(RTC_EXTI_LINE_ALARM_EVENT))

   
                                                                              
                
    
#define __HAL_RTC_ALARM_EXTI_ENABLE_FALLING_EDGE()   (EXTI->FTSR1 |= RTC_EXTI_LINE_ALARM_EVENT)

   
                                                                               
                
    
#define __HAL_RTC_ALARM_EXTI_DISABLE_FALLING_EDGE()  (EXTI->FTSR1 &= ~(RTC_EXTI_LINE_ALARM_EVENT))

   
                                                                             
                
    
#define __HAL_RTC_ALARM_EXTI_ENABLE_RISING_EDGE()    (EXTI->RTSR1 |= RTC_EXTI_LINE_ALARM_EVENT)

   
                                                                              
                
    
#define __HAL_RTC_ALARM_EXTI_DISABLE_RISING_EDGE()   (EXTI->RTSR1 &= ~(RTC_EXTI_LINE_ALARM_EVENT))

   
                                                                                       
                
    
#define __HAL_RTC_ALARM_EXTI_ENABLE_RISING_FALLING_EDGE()  do { \
                                                             __HAL_RTC_ALARM_EXTI_ENABLE_RISING_EDGE();  \
                                                             __HAL_RTC_ALARM_EXTI_ENABLE_FALLING_EDGE(); \
                                                           } while(0u)

   
                                                                                        
                
    
#define __HAL_RTC_ALARM_EXTI_DISABLE_RISING_FALLING_EDGE() do { \
                                                             __HAL_RTC_ALARM_EXTI_DISABLE_RISING_EDGE();  \
                                                             __HAL_RTC_ALARM_EXTI_DISABLE_FALLING_EDGE(); \
                                                           } while(0u)

   
                                                                                         
                        
    
#define __HAL_RTC_ALARM_EXTI_GET_FLAG()              (EXTI->PR1 & RTC_EXTI_LINE_ALARM_EVENT)

   
                                                         
                
    
#define __HAL_RTC_ALARM_EXTI_CLEAR_FLAG()            (EXTI->PR1 = RTC_EXTI_LINE_ALARM_EVENT)

   
                                                                           
                
    
#define __HAL_RTC_ALARM_EXTI_GENERATE_SWIT()         (EXTI->SWIER1 |= RTC_EXTI_LINE_ALARM_EVENT)

   
      
    

                                     
#include "stm32l4xx_hal_rtc_ex.h"

                                                                                
                                                           
      
    

                                                                                          
      
    
                                                                                
HAL_StatusTypeDef HAL_RTC_Init(RTC_HandleTypeDef *hrtc);
HAL_StatusTypeDef HAL_RTC_DeInit(RTC_HandleTypeDef *hrtc);

void HAL_RTC_MspInit(RTC_HandleTypeDef *hrtc);
void HAL_RTC_MspDeInit(RTC_HandleTypeDef *hrtc);

                                                                                
#if (USE_HAL_RTC_REGISTER_CALLBACKS == 1)
HAL_StatusTypeDef HAL_RTC_RegisterCallback(RTC_HandleTypeDef *hrtc, HAL_RTC_CallbackIDTypeDef CallbackID, pRTC_CallbackTypeDef pCallback);
HAL_StatusTypeDef HAL_RTC_UnRegisterCallback(RTC_HandleTypeDef *hrtc, HAL_RTC_CallbackIDTypeDef CallbackID);
#endif                                            
   
      
    

                                                                       
      
    
                                                                                
HAL_StatusTypeDef HAL_RTC_SetTime(RTC_HandleTypeDef *hrtc, RTC_TimeTypeDef *sTime, uint32_t Format);
HAL_StatusTypeDef HAL_RTC_GetTime(RTC_HandleTypeDef *hrtc, RTC_TimeTypeDef *sTime, uint32_t Format);
HAL_StatusTypeDef HAL_RTC_SetDate(RTC_HandleTypeDef *hrtc, RTC_DateTypeDef *sDate, uint32_t Format);
HAL_StatusTypeDef HAL_RTC_GetDate(RTC_HandleTypeDef *hrtc, RTC_DateTypeDef *sDate, uint32_t Format);
void              HAL_RTC_DST_Add1Hour(RTC_HandleTypeDef *hrtc);
void              HAL_RTC_DST_Sub1Hour(RTC_HandleTypeDef *hrtc);
void              HAL_RTC_DST_SetStoreOperation(RTC_HandleTypeDef *hrtc);
void              HAL_RTC_DST_ClearStoreOperation(RTC_HandleTypeDef *hrtc);
uint32_t          HAL_RTC_DST_ReadStoreOperation(RTC_HandleTypeDef *hrtc);
   
      
    

                                                               
      
    
                                                                                
HAL_StatusTypeDef HAL_RTC_SetAlarm(RTC_HandleTypeDef *hrtc, RTC_AlarmTypeDef *sAlarm, uint32_t Format);
HAL_StatusTypeDef HAL_RTC_SetAlarm_IT(RTC_HandleTypeDef *hrtc, RTC_AlarmTypeDef *sAlarm, uint32_t Format);
HAL_StatusTypeDef HAL_RTC_DeactivateAlarm(RTC_HandleTypeDef *hrtc, uint32_t Alarm);
HAL_StatusTypeDef HAL_RTC_GetAlarm(RTC_HandleTypeDef *hrtc, RTC_AlarmTypeDef *sAlarm, uint32_t Alarm, uint32_t Format);
void              HAL_RTC_AlarmIRQHandler(RTC_HandleTypeDef *hrtc);
void              HAL_RTC_AlarmAEventCallback(RTC_HandleTypeDef *hrtc);
HAL_StatusTypeDef HAL_RTC_PollForAlarmAEvent(RTC_HandleTypeDef *hrtc, uint32_t Timeout);
   
      
    

                                                                         
      
    
                                                                                
HAL_StatusTypeDef   HAL_RTC_WaitForSynchro(RTC_HandleTypeDef *hrtc);
   
      
    

                                                                      
      
    
                                                                                
HAL_RTCStateTypeDef HAL_RTC_GetState(RTC_HandleTypeDef *hrtc);
   
      
    

   
      
    

                                                                                
                                                                                
                                                                                
                                                         
      
    
                      
#define RTC_TR_RESERVED_MASK                (RTC_TR_PM | RTC_TR_HT | RTC_TR_HU | \
                                            RTC_TR_MNT | RTC_TR_MNU| RTC_TR_ST | \
                                            RTC_TR_SU)

#define RTC_DR_RESERVED_MASK                (RTC_DR_YT | RTC_DR_YU | RTC_DR_WDU | \
                                            RTC_DR_MT | RTC_DR_MU | RTC_DR_DT  | \
                                            RTC_DR_DU)

#define RTC_INIT_MASK                       0xFFFFFFFFu

#if defined(STM32L412xx) || defined(STM32L422xx)
#define RTC_ICSR_RESERVED_MASK              0x000100FCu
#define RTC_RSF_MASK                        (~(RTC_ICSR_INIT | RTC_ICSR_RSF))
#elif defined (STM32L4P5xx) || defined (STM32L4Q5xx)
#define RTC_ICSR_RESERVED_MASK              0x00011FFCu
#define RTC_RSF_MASK                        (~(RTC_ICSR_INIT | RTC_ICSR_RSF))
#else
#define RTC_ISR_RESERVED_MASK               0x0003FFFFu
#define RTC_RSF_MASK                        (~(RTC_ISR_INIT | RTC_ISR_RSF))
#endif

#define RTC_TIMEOUT_VALUE                   1000u

#define RTC_EXTI_LINE_ALARM_EVENT           EXTI_IMR1_IM18                                                                     

   
      
    

                                                                                
                                                   
      
    

                                                                                 
      
    
#if defined(STM32L412xx) || defined(STM32L422xx) || defined (STM32L4P5xx) || defined (STM32L4Q5xx)
#define IS_RTC_OUTPUT(OUTPUT) (((OUTPUT) == RTC_OUTPUT_DISABLE) || \
                                ((OUTPUT) == RTC_OUTPUT_ALARMA)  || \
                                ((OUTPUT) == RTC_OUTPUT_ALARMB)  || \
                                ((OUTPUT) == RTC_OUTPUT_WAKEUP)  || \
                                ((OUTPUT) == RTC_OUTPUT_TAMPER))
#else
#define IS_RTC_OUTPUT(OUTPUT) (((OUTPUT) == RTC_OUTPUT_DISABLE) || \
                               ((OUTPUT) == RTC_OUTPUT_ALARMA)  || \
                               ((OUTPUT) == RTC_OUTPUT_ALARMB)  || \
                               ((OUTPUT) == RTC_OUTPUT_WAKEUP))
#endif

#define IS_RTC_HOUR_FORMAT(FORMAT)     (((FORMAT) == RTC_HOURFORMAT_12) || \
                                        ((FORMAT) == RTC_HOURFORMAT_24))

#define IS_RTC_OUTPUT_POL(POL) (((POL) == RTC_OUTPUT_POLARITY_HIGH) || \
                                ((POL) == RTC_OUTPUT_POLARITY_LOW))

#define IS_RTC_OUTPUT_TYPE(TYPE) (((TYPE) == RTC_OUTPUT_TYPE_OPENDRAIN) || \
                                  ((TYPE) == RTC_OUTPUT_TYPE_PUSHPULL))

#if defined(STM32L412xx) || defined(STM32L422xx) || defined (STM32L4P5xx) || defined (STM32L4Q5xx)
#define IS_RTC_OUTPUT_PULLUP(TYPE) (((TYPE) == RTC_OUTPUT_PULLUP_NONE) || \
                                    ((TYPE) == RTC_OUTPUT_PULLUP_ON))
#endif

#define IS_RTC_OUTPUT_REMAP(REMAP)   (((REMAP) == RTC_OUTPUT_REMAP_NONE) || \
                                      ((REMAP) == RTC_OUTPUT_REMAP_POS1))

#define IS_RTC_HOURFORMAT12(PM)  (((PM) == RTC_HOURFORMAT12_AM) || \
                                  ((PM) == RTC_HOURFORMAT12_PM))

#define IS_RTC_DAYLIGHT_SAVING(SAVE) (((SAVE) == RTC_DAYLIGHTSAVING_SUB1H) || \
                                      ((SAVE) == RTC_DAYLIGHTSAVING_ADD1H) || \
                                      ((SAVE) == RTC_DAYLIGHTSAVING_NONE))

#define IS_RTC_STORE_OPERATION(OPERATION) (((OPERATION) == RTC_STOREOPERATION_RESET) || \
                                           ((OPERATION) == RTC_STOREOPERATION_SET))

#define IS_RTC_FORMAT(FORMAT) (((FORMAT) == RTC_FORMAT_BIN) || \
                               ((FORMAT) == RTC_FORMAT_BCD))

#define IS_RTC_YEAR(YEAR)              ((YEAR) <= 99u)

#define IS_RTC_MONTH(MONTH)            (((MONTH) >= 1u) && ((MONTH) <= 12u))

#define IS_RTC_DATE(DATE)              (((DATE) >= 1u) && ((DATE) <= 31u))

#define IS_RTC_WEEKDAY(WEEKDAY) (((WEEKDAY) == RTC_WEEKDAY_MONDAY)    || \
                                 ((WEEKDAY) == RTC_WEEKDAY_TUESDAY)   || \
                                 ((WEEKDAY) == RTC_WEEKDAY_WEDNESDAY) || \
                                 ((WEEKDAY) == RTC_WEEKDAY_THURSDAY)  || \
                                 ((WEEKDAY) == RTC_WEEKDAY_FRIDAY)    || \
                                 ((WEEKDAY) == RTC_WEEKDAY_SATURDAY)  || \
                                 ((WEEKDAY) == RTC_WEEKDAY_SUNDAY))

#define IS_RTC_ALARM_DATE_WEEKDAY_DATE(DATE) (((DATE) >0u) && ((DATE) <= 31u))

#define IS_RTC_ALARM_DATE_WEEKDAY_WEEKDAY(WEEKDAY) (((WEEKDAY) == RTC_WEEKDAY_MONDAY)    || \
                                                    ((WEEKDAY) == RTC_WEEKDAY_TUESDAY)   || \
                                                    ((WEEKDAY) == RTC_WEEKDAY_WEDNESDAY) || \
                                                    ((WEEKDAY) == RTC_WEEKDAY_THURSDAY)  || \
                                                    ((WEEKDAY) == RTC_WEEKDAY_FRIDAY)    || \
                                                    ((WEEKDAY) == RTC_WEEKDAY_SATURDAY)  || \
                                                    ((WEEKDAY) == RTC_WEEKDAY_SUNDAY))

#define IS_RTC_ALARM_DATE_WEEKDAY_SEL(SEL) (((SEL) == RTC_ALARMDATEWEEKDAYSEL_DATE) || \
                                            ((SEL) == RTC_ALARMDATEWEEKDAYSEL_WEEKDAY))

#define IS_RTC_ALARM_MASK(MASK)  (((MASK) & ~(RTC_ALARMMASK_ALL)) == 0U)

#define IS_RTC_ALARM(ALARM)      (((ALARM) == RTC_ALARM_A) || \
                                  ((ALARM) == RTC_ALARM_B))

#define IS_RTC_ALARM_SUB_SECOND_VALUE(VALUE) ((VALUE) <= RTC_ALRMASSR_SS)

#define IS_RTC_ALARM_SUB_SECOND_MASK(MASK)          (((MASK) == 0u) || \
                                                    (((MASK) >= RTC_ALARMSUBSECONDMASK_SS14_1) && ((MASK) <= RTC_ALARMSUBSECONDMASK_NONE)))

#define IS_RTC_ASYNCH_PREDIV(PREDIV)   ((PREDIV) <= (RTC_PRER_PREDIV_A >> RTC_PRER_PREDIV_A_Pos))

#define IS_RTC_SYNCH_PREDIV(PREDIV)    ((PREDIV) <= (RTC_PRER_PREDIV_S >> RTC_PRER_PREDIV_S_Pos))

#define IS_RTC_HOUR12(HOUR)            (((HOUR) > 0u) && ((HOUR) <= 12u))

#define IS_RTC_HOUR24(HOUR)            ((HOUR) <= 23u)

#define IS_RTC_MINUTES(MINUTES)        ((MINUTES) <= 59u)

#define IS_RTC_SECONDS(SECONDS)        ((SECONDS) <= 59u)

   
      
    

   
      
    

                                                                                    
                                                         
      
    
HAL_StatusTypeDef  RTC_EnterInitMode(RTC_HandleTypeDef *hrtc);
HAL_StatusTypeDef  RTC_ExitInitMode(RTC_HandleTypeDef *hrtc);
uint8_t            RTC_ByteToBcd2(uint8_t Value);
uint8_t            RTC_Bcd2ToByte(uint8_t Value);
   
      
    


   
      
    

   
      
    

   
      
    

#ifdef __cplusplus
}
#endif

#endif                          
