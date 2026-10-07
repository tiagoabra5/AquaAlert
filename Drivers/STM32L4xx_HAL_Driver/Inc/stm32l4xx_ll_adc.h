/**
  ******************************************************************************
  * @file    stm32l4xx_ll_adc.h
  * @author  MCD Application Team
  * @brief   Header file of ADC LL module.
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

                                                                                
#ifndef STM32L4xx_LL_ADC_H
#define STM32L4xx_LL_ADC_H

#ifdef __cplusplus
extern "C" {
#endif

                                                                                
#include "stm32l4xx.h"

                                   
      
    

#if defined (ADC1) || defined (ADC2) || defined (ADC3)

                        
      
    

                                                                                
                                                                                

                                                                                
                                                            
      
    

                                                                                
                                                                                
                                                                                
                                                                                

                                                                            
                                                             
#define ADC_SQR1_REGOFFSET                 (0x00000000UL)
#define ADC_SQR2_REGOFFSET                 (0x00000100UL)
#define ADC_SQR3_REGOFFSET                 (0x00000200UL)
#define ADC_SQR4_REGOFFSET                 (0x00000300UL)

#define ADC_REG_SQRX_REGOFFSET_MASK        (ADC_SQR1_REGOFFSET | ADC_SQR2_REGOFFSET \
                                            | ADC_SQR3_REGOFFSET | ADC_SQR4_REGOFFSET)
#define ADC_SQRX_REGOFFSET_POS             (8UL)                                                                        
#define ADC_REG_RANK_ID_SQRX_MASK          (ADC_CHANNEL_ID_NUMBER_MASK_POSBIT0)

                                                                                
                                                                                
#define ADC_REG_RANK_1_SQRX_BITOFFSET_POS  ( 6UL)                                                                 
#define ADC_REG_RANK_2_SQRX_BITOFFSET_POS  (12UL)                                                                 
#define ADC_REG_RANK_3_SQRX_BITOFFSET_POS  (18UL)                                                                 
#define ADC_REG_RANK_4_SQRX_BITOFFSET_POS  (24UL)                                                                 
#define ADC_REG_RANK_5_SQRX_BITOFFSET_POS  ( 0UL)                                                                 
#define ADC_REG_RANK_6_SQRX_BITOFFSET_POS  ( 6UL)                                                                 
#define ADC_REG_RANK_7_SQRX_BITOFFSET_POS  (12UL)                                                                 
#define ADC_REG_RANK_8_SQRX_BITOFFSET_POS  (18UL)                                                                 
#define ADC_REG_RANK_9_SQRX_BITOFFSET_POS  (24UL)                                                                 
#define ADC_REG_RANK_10_SQRX_BITOFFSET_POS ( 0UL)                                                                  
#define ADC_REG_RANK_11_SQRX_BITOFFSET_POS ( 6UL)                                                                  
#define ADC_REG_RANK_12_SQRX_BITOFFSET_POS (12UL)                                                                  
#define ADC_REG_RANK_13_SQRX_BITOFFSET_POS (18UL)                                                                  
#define ADC_REG_RANK_14_SQRX_BITOFFSET_POS (24UL)                                                                  
#define ADC_REG_RANK_15_SQRX_BITOFFSET_POS ( 0UL)                                                                  
#define ADC_REG_RANK_16_SQRX_BITOFFSET_POS ( 6UL)                                                                  

                                                                                
                                                                                
                                                                                
                                                                                

                                                                   
                                                             
#define ADC_JDR1_REGOFFSET                 (0x00000000UL)
#define ADC_JDR2_REGOFFSET                 (0x00000100UL)
#define ADC_JDR3_REGOFFSET                 (0x00000200UL)
#define ADC_JDR4_REGOFFSET                 (0x00000300UL)

#define ADC_INJ_JDRX_REGOFFSET_MASK        (ADC_JDR1_REGOFFSET | ADC_JDR2_REGOFFSET \
                                            | ADC_JDR3_REGOFFSET | ADC_JDR4_REGOFFSET)
#define ADC_INJ_RANK_ID_JSQR_MASK          (ADC_CHANNEL_ID_NUMBER_MASK_POSBIT0)
#define ADC_JDRX_REGOFFSET_POS             (8UL)                                                                        

                                                                                
                                                                                
#define ADC_INJ_RANK_1_JSQR_BITOFFSET_POS  ( 8UL)                                                                  
#define ADC_INJ_RANK_2_JSQR_BITOFFSET_POS  (14UL)                                                                  
#define ADC_INJ_RANK_3_JSQR_BITOFFSET_POS  (20UL)                                                                  
#define ADC_INJ_RANK_4_JSQR_BITOFFSET_POS  (26UL)                                                                  

                                                                                
                                                                                
                                                                                
                                                                                
#define ADC_REG_TRIG_EXT_EDGE_DEFAULT      (ADC_CFGR_EXTEN_0)                                                        
                                                                                                                  
                                                                                                                

                                                                                
                                                                                
                                                                                
#define ADC_REG_TRIG_SOURCE_MASK           (((LL_ADC_REG_TRIG_SOFTWARE & ADC_CFGR_EXTSEL) << (4U * 0UL)) | \
                                            ((ADC_CFGR_EXTSEL)                            << (4U * 1UL)) | \
                                            ((ADC_CFGR_EXTSEL)                            << (4U * 2UL)) | \
                                            ((ADC_CFGR_EXTSEL)                            << (4U * 3UL))  )

                                                                                
                                                                                
                                                                                
#define ADC_REG_TRIG_EDGE_MASK             (((LL_ADC_REG_TRIG_SOFTWARE & ADC_CFGR_EXTEN) << (4U * 0UL)) | \
                                            ((ADC_REG_TRIG_EXT_EDGE_DEFAULT)             << (4U * 1UL)) | \
                                            ((ADC_REG_TRIG_EXT_EDGE_DEFAULT)             << (4U * 2UL)) | \
                                            ((ADC_REG_TRIG_EXT_EDGE_DEFAULT)             << (4U * 3UL))  )

                                                                                
#define ADC_REG_TRIG_EXTSEL_BITOFFSET_POS  ( 6UL)                                                                    
#define ADC_REG_TRIG_EXTEN_BITOFFSET_POS   (10UL)                                                                   

                                                                                
                                                                                
                                                                                
                                                                                
#define ADC_INJ_TRIG_EXT_EDGE_DEFAULT      (ADC_JSQR_JEXTEN_0)                                                        
                                                                                                                   
                                                                                                                 

                                                                                
                                                                                
                                                                                
#define ADC_INJ_TRIG_SOURCE_MASK           (((LL_ADC_INJ_TRIG_SOFTWARE & ADC_JSQR_JEXTSEL)  << (4U * 0UL)) | \
                                            ((ADC_JSQR_JEXTSEL)                             << (4U * 1UL)) | \
                                            ((ADC_JSQR_JEXTSEL)                             << (4U * 2UL)) | \
                                            ((ADC_JSQR_JEXTSEL)                             << (4U * 3UL))  )

                                                                                
                                                                                
                                                                                
#define ADC_INJ_TRIG_EDGE_MASK             (((LL_ADC_INJ_TRIG_SOFTWARE & ADC_JSQR_JEXTEN) << (4U * 0UL)) | \
                                            ((ADC_INJ_TRIG_EXT_EDGE_DEFAULT)              << (4U * 1UL)) | \
                                            ((ADC_INJ_TRIG_EXT_EDGE_DEFAULT)              << (4U * 2UL)) | \
                                            ((ADC_INJ_TRIG_EXT_EDGE_DEFAULT)              << (4U * 3UL))  )

                                                                                
#define ADC_INJ_TRIG_EXTSEL_BITOFFSET_POS  ( 2UL)                                                                     
#define ADC_INJ_TRIG_EXTEN_BITOFFSET_POS   ( 6UL)                                                                    

                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
#define ADC_CHANNEL_ID_NUMBER_MASK         (ADC_CFGR_AWD1CH)
#define ADC_CHANNEL_ID_BITFIELD_MASK       (ADC_AWD2CR_AWD2CH)
#define ADC_CHANNEL_ID_NUMBER_BITOFFSET_POS (26UL)                                                                    
                                                                                                                        
#define ADC_CHANNEL_ID_MASK                (ADC_CHANNEL_ID_NUMBER_MASK | ADC_CHANNEL_ID_BITFIELD_MASK \
                                            | ADC_CHANNEL_ID_INTERNAL_CH_MASK)
                                                                                
#define ADC_CHANNEL_ID_NUMBER_MASK_POSBIT0 (ADC_SQR2_SQ5)                                                 
                                                                     

                                                                    
#define ADC_CHANNEL_ID_INTERNAL_CH         (0x80000000UL)                                 
#define ADC_CHANNEL_ID_INTERNAL_CH_2       (0x00080000UL)                                                               
                                                                                                                      
                                                                                                 
#define ADC_CHANNEL_ID_INTERNAL_CH_MASK    (ADC_CHANNEL_ID_INTERNAL_CH | ADC_CHANNEL_ID_INTERNAL_CH_2)

                                                                          
                                                             
#define ADC_SMPR1_REGOFFSET                (0x00000000UL)
#define ADC_SMPR2_REGOFFSET                (0x02000000UL)
#define ADC_CHANNEL_SMPRX_REGOFFSET_MASK   (ADC_SMPR1_REGOFFSET | ADC_SMPR2_REGOFFSET)
#define ADC_SMPRX_REGOFFSET_POS            (25UL)                                                  
                                                                                                     

#define ADC_CHANNEL_SMPx_BITOFFSET_MASK    (0x01F00000UL)
#define ADC_CHANNEL_SMPx_BITOFFSET_POS     (20UL)                                                                      
                                                                                      

                                                                                
                                                                                
#define ADC_CHANNEL_0_NUMBER               (0x00000000UL)
#define ADC_CHANNEL_1_NUMBER               (ADC_CFGR_AWD1CH_0)
#define ADC_CHANNEL_2_NUMBER               (ADC_CFGR_AWD1CH_1)
#define ADC_CHANNEL_3_NUMBER               (ADC_CFGR_AWD1CH_1 | ADC_CFGR_AWD1CH_0)
#define ADC_CHANNEL_4_NUMBER               (ADC_CFGR_AWD1CH_2)
#define ADC_CHANNEL_5_NUMBER               (ADC_CFGR_AWD1CH_2 | ADC_CFGR_AWD1CH_0)
#define ADC_CHANNEL_6_NUMBER               (ADC_CFGR_AWD1CH_2 | ADC_CFGR_AWD1CH_1)
#define ADC_CHANNEL_7_NUMBER               (ADC_CFGR_AWD1CH_2 | ADC_CFGR_AWD1CH_1 | ADC_CFGR_AWD1CH_0)
#define ADC_CHANNEL_8_NUMBER               (ADC_CFGR_AWD1CH_3)
#define ADC_CHANNEL_9_NUMBER               (ADC_CFGR_AWD1CH_3 | ADC_CFGR_AWD1CH_0)
#define ADC_CHANNEL_10_NUMBER              (ADC_CFGR_AWD1CH_3 | ADC_CFGR_AWD1CH_1)
#define ADC_CHANNEL_11_NUMBER              (ADC_CFGR_AWD1CH_3 | ADC_CFGR_AWD1CH_1 | ADC_CFGR_AWD1CH_0)
#define ADC_CHANNEL_12_NUMBER              (ADC_CFGR_AWD1CH_3 | ADC_CFGR_AWD1CH_2)
#define ADC_CHANNEL_13_NUMBER              (ADC_CFGR_AWD1CH_3 | ADC_CFGR_AWD1CH_2 | ADC_CFGR_AWD1CH_0)
#define ADC_CHANNEL_14_NUMBER              (ADC_CFGR_AWD1CH_3 | ADC_CFGR_AWD1CH_2 | ADC_CFGR_AWD1CH_1)
#define ADC_CHANNEL_15_NUMBER              (ADC_CFGR_AWD1CH_3 | ADC_CFGR_AWD1CH_2 | \
                                            ADC_CFGR_AWD1CH_1 | ADC_CFGR_AWD1CH_0)
#define ADC_CHANNEL_16_NUMBER              (ADC_CFGR_AWD1CH_4)
#define ADC_CHANNEL_17_NUMBER              (ADC_CFGR_AWD1CH_4 | ADC_CFGR_AWD1CH_0)
#define ADC_CHANNEL_18_NUMBER              (ADC_CFGR_AWD1CH_4 | ADC_CFGR_AWD1CH_1)

                                                                                
                                                                                
#define ADC_CHANNEL_0_BITFIELD             (ADC_AWD2CR_AWD2CH_0)
#define ADC_CHANNEL_1_BITFIELD             (ADC_AWD2CR_AWD2CH_1)
#define ADC_CHANNEL_2_BITFIELD             (ADC_AWD2CR_AWD2CH_2)
#define ADC_CHANNEL_3_BITFIELD             (ADC_AWD2CR_AWD2CH_3)
#define ADC_CHANNEL_4_BITFIELD             (ADC_AWD2CR_AWD2CH_4)
#define ADC_CHANNEL_5_BITFIELD             (ADC_AWD2CR_AWD2CH_5)
#define ADC_CHANNEL_6_BITFIELD             (ADC_AWD2CR_AWD2CH_6)
#define ADC_CHANNEL_7_BITFIELD             (ADC_AWD2CR_AWD2CH_7)
#define ADC_CHANNEL_8_BITFIELD             (ADC_AWD2CR_AWD2CH_8)
#define ADC_CHANNEL_9_BITFIELD             (ADC_AWD2CR_AWD2CH_9)
#define ADC_CHANNEL_10_BITFIELD            (ADC_AWD2CR_AWD2CH_10)
#define ADC_CHANNEL_11_BITFIELD            (ADC_AWD2CR_AWD2CH_11)
#define ADC_CHANNEL_12_BITFIELD            (ADC_AWD2CR_AWD2CH_12)
#define ADC_CHANNEL_13_BITFIELD            (ADC_AWD2CR_AWD2CH_13)
#define ADC_CHANNEL_14_BITFIELD            (ADC_AWD2CR_AWD2CH_14)
#define ADC_CHANNEL_15_BITFIELD            (ADC_AWD2CR_AWD2CH_15)
#define ADC_CHANNEL_16_BITFIELD            (ADC_AWD2CR_AWD2CH_16)
#define ADC_CHANNEL_17_BITFIELD            (ADC_AWD2CR_AWD2CH_17)
#define ADC_CHANNEL_18_BITFIELD            (ADC_AWD2CR_AWD2CH_18)

                                                                                
                                                                                
                                                                                
                                                                                
#define ADC_CHANNEL_0_SMP                  (ADC_SMPR1_REGOFFSET | (( 0UL) << ADC_CHANNEL_SMPx_BITOFFSET_POS))
#define ADC_CHANNEL_1_SMP                  (ADC_SMPR1_REGOFFSET | (( 3UL) << ADC_CHANNEL_SMPx_BITOFFSET_POS))
#define ADC_CHANNEL_2_SMP                  (ADC_SMPR1_REGOFFSET | (( 6UL) << ADC_CHANNEL_SMPx_BITOFFSET_POS))
#define ADC_CHANNEL_3_SMP                  (ADC_SMPR1_REGOFFSET | (( 9UL) << ADC_CHANNEL_SMPx_BITOFFSET_POS))
#define ADC_CHANNEL_4_SMP                  (ADC_SMPR1_REGOFFSET | ((12UL) << ADC_CHANNEL_SMPx_BITOFFSET_POS))
#define ADC_CHANNEL_5_SMP                  (ADC_SMPR1_REGOFFSET | ((15UL) << ADC_CHANNEL_SMPx_BITOFFSET_POS))
#define ADC_CHANNEL_6_SMP                  (ADC_SMPR1_REGOFFSET | ((18UL) << ADC_CHANNEL_SMPx_BITOFFSET_POS))
#define ADC_CHANNEL_7_SMP                  (ADC_SMPR1_REGOFFSET | ((21UL) << ADC_CHANNEL_SMPx_BITOFFSET_POS))
#define ADC_CHANNEL_8_SMP                  (ADC_SMPR1_REGOFFSET | ((24UL) << ADC_CHANNEL_SMPx_BITOFFSET_POS))
#define ADC_CHANNEL_9_SMP                  (ADC_SMPR1_REGOFFSET | ((27UL) << ADC_CHANNEL_SMPx_BITOFFSET_POS))
#define ADC_CHANNEL_10_SMP                 (ADC_SMPR2_REGOFFSET | (( 0UL) << ADC_CHANNEL_SMPx_BITOFFSET_POS))
#define ADC_CHANNEL_11_SMP                 (ADC_SMPR2_REGOFFSET | (( 3UL) << ADC_CHANNEL_SMPx_BITOFFSET_POS))
#define ADC_CHANNEL_12_SMP                 (ADC_SMPR2_REGOFFSET | (( 6UL) << ADC_CHANNEL_SMPx_BITOFFSET_POS))
#define ADC_CHANNEL_13_SMP                 (ADC_SMPR2_REGOFFSET | (( 9UL) << ADC_CHANNEL_SMPx_BITOFFSET_POS))
#define ADC_CHANNEL_14_SMP                 (ADC_SMPR2_REGOFFSET | ((12UL) << ADC_CHANNEL_SMPx_BITOFFSET_POS))
#define ADC_CHANNEL_15_SMP                 (ADC_SMPR2_REGOFFSET | ((15UL) << ADC_CHANNEL_SMPx_BITOFFSET_POS))
#define ADC_CHANNEL_16_SMP                 (ADC_SMPR2_REGOFFSET | ((18UL) << ADC_CHANNEL_SMPx_BITOFFSET_POS))
#define ADC_CHANNEL_17_SMP                 (ADC_SMPR2_REGOFFSET | ((21UL) << ADC_CHANNEL_SMPx_BITOFFSET_POS))
#define ADC_CHANNEL_18_SMP                 (ADC_SMPR2_REGOFFSET | ((24UL) << ADC_CHANNEL_SMPx_BITOFFSET_POS))


                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
#define ADC_SINGLEDIFF_CALIB_START_MASK    (ADC_CR_ADCALDIF)
#define ADC_SINGLEDIFF_CALIB_FACTOR_MASK   (ADC_CALFACT_CALFACT_D | ADC_CALFACT_CALFACT_S)
#define ADC_SINGLEDIFF_CHANNEL_MASK        (ADC_CHANNEL_ID_BITFIELD_MASK)                                      
#define ADC_SINGLEDIFF_CHANNEL_SHIFT_MASK  (ADC_CALFACT_CALFACT_S_4 | ADC_CALFACT_CALFACT_S_3)               
                                                                                                               
                                                                  
#define ADC_SINGLEDIFF_CALIB_F_BIT_D_MASK   (0x00010000UL)                                                         
                                                         
#define ADC_SINGLEDIFF_CALIB_F_BIT_D_POS    (16UL)                                                                 
                                                             
#define ADC_SINGLEDIFF_CALIB_F_BIT_D_SHIFT4 (ADC_SINGLEDIFF_CALIB_F_BIT_D_POS - 4UL)                
                                                                                                        

                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                

                                                                            
#define ADC_AWD_CR1_REGOFFSET              (0x00000000UL)
#define ADC_AWD_CR2_REGOFFSET              (0x00100000UL)
#define ADC_AWD_CR3_REGOFFSET              (0x00200000UL)

                                                                            
                                                                     
#define ADC_AWD_CR12_REGOFFSETGAP_MASK     (ADC_AWD2CR_AWD2CH_0)
#define ADC_AWD_CR12_REGOFFSETGAP_VAL      (0x00000024UL)

#define ADC_AWD_CRX_REGOFFSET_MASK         (ADC_AWD_CR1_REGOFFSET | ADC_AWD_CR2_REGOFFSET | ADC_AWD_CR3_REGOFFSET)

#define ADC_AWD_CR1_CHANNEL_MASK           (ADC_CFGR_AWD1CH | ADC_CFGR_JAWD1EN | ADC_CFGR_AWD1EN | ADC_CFGR_AWD1SGL)
#define ADC_AWD_CR23_CHANNEL_MASK          (ADC_AWD2CR_AWD2CH)
#define ADC_AWD_CR_ALL_CHANNEL_MASK        (ADC_AWD_CR1_CHANNEL_MASK | ADC_AWD_CR23_CHANNEL_MASK)

#define ADC_AWD_CRX_REGOFFSET_POS          (20UL)                                                               
                                                                                                          

                                                                              
#define ADC_AWD_TR1_REGOFFSET              (ADC_AWD_CR1_REGOFFSET)
#define ADC_AWD_TR2_REGOFFSET              (ADC_AWD_CR2_REGOFFSET)
#define ADC_AWD_TR3_REGOFFSET              (ADC_AWD_CR3_REGOFFSET)
#define ADC_AWD_TRX_REGOFFSET_MASK         (ADC_AWD_TR1_REGOFFSET | ADC_AWD_TR2_REGOFFSET | ADC_AWD_TR3_REGOFFSET)
#define ADC_AWD_TRX_REGOFFSET_POS          (ADC_AWD_CRX_REGOFFSET_POS)                                            
                                                                                                               
#define ADC_AWD_TRX_BIT_HIGH_MASK          (0x00010000UL)                                                        
                                                                                                             
#define ADC_AWD_TRX_BIT_HIGH_POS           (16UL)                                                                
                                                                                                                 
#define ADC_AWD_TRX_BIT_HIGH_SHIFT4        (ADC_AWD_TRX_BIT_HIGH_POS - 4UL)                                        
                                                                                                                        

                                                                                
                                                                    
#define ADC_OFR1_REGOFFSET                 (0x00000000UL)
#define ADC_OFR2_REGOFFSET                 (0x00000001UL)
#define ADC_OFR3_REGOFFSET                 (0x00000002UL)
#define ADC_OFR4_REGOFFSET                 (0x00000003UL)
#define ADC_OFRx_REGOFFSET_MASK            (ADC_OFR1_REGOFFSET | ADC_OFR2_REGOFFSET \
                                            | ADC_OFR3_REGOFFSET | ADC_OFR4_REGOFFSET)


                                  
#define ADC_CFGR_RES_BITOFFSET_POS         ( 3UL)                                                                 
#define ADC_CFGR_AWD1SGL_BITOFFSET_POS     (22UL)                                                                     
#define ADC_CFGR_AWD1EN_BITOFFSET_POS      (23UL)                                                                    
#define ADC_CFGR_JAWD1EN_BITOFFSET_POS     (24UL)                                                                     
#define ADC_TR1_HT1_BITOFFSET_POS          (16UL)                                                                


                               
#define ADC_CR_BITS_PROPERTY_RS            (ADC_CR_ADCAL | ADC_CR_ADEN | ADC_CR_ADDIS \
                                            | ADC_CR_JADSTART | ADC_CR_JADSTP \
                                            | ADC_CR_ADSTART | ADC_CR_ADSTP)                                        
                                                                                                       
                                                                                         


                                               
                                        
#define VREFINT_CAL_ADDR                   ((const uint16_t*) (0x1FFF75AAUL))                                          
                                                                                                                      
                                                                                                        
#define VREFINT_CAL_VREF                   ( 3000UL)                                                             
                                                                                               
                                                                              
                        
#define TEMPSENSOR_CAL1_ADDR               ((const uint16_t*) (0x1FFF75A8UL))                                 
                                                                                                           
                                                                                                        
#define TEMPSENSOR_CAL2_ADDR               ((const uint16_t*) (0x1FFF75CAUL))                                 
                                                                                                             
                                                                                                                             
#define TEMPSENSOR_CAL1_TEMP               (( int32_t)   30L)                                                     
                                                                                                               
                                                                                 
#if defined (STM32L471xx) || defined (STM32L475xx) || defined (STM32L476xx) || defined (STM32L485xx) || defined (STM32L486xx)
#define TEMPSENSOR_CAL2_TEMP               (110L)                                                                 
                                                                                                               
                                                                                 
#else
#define TEMPSENSOR_CAL2_TEMP               (130L)                                                                 
                                                                                                               
                                                                                 
#endif                                                                                                                                
#define TEMPSENSOR_CAL_VREFANALOG          (3000UL)                                                              
                                                                                                          
                                                                             

   
      
    

                                                                                
                                                      
      
    

   
                                                                    
                                                                 
                       
                                                                    
                                                                             
                                       
    
#define __ADC_PTR_REG_OFFSET(__REG__, __REG_OFFFSET__)                         \
  ((__IO uint32_t *)((uint32_t) ((uint32_t)(&(__REG__)) + ((__REG_OFFFSET__) << 2UL))))

   
      
    

                                                                                
#if defined(USE_FULL_LL_DRIVER)
                                                        
      
    

   
                                                                          
                         
                                                                          
                                                                                
                                                                    
                                                  
                                                                          
                     
    
typedef struct
{
  uint32_t CommonClock;                                                                                      
                                                                                                                
                                                                                                                        
                                                                                                                 
                                                                             
                                                                                                           
                                                                             

#if defined(ADC_MULTIMODE_SUPPORT)
  uint32_t Multimode;                                                                                                   
                                                                                      
                                                                                                       
                                                                                                           
                                                                           

  uint32_t MultiDMATransfer;                                                                                            
                                                                                                               
                                                                                                           
                                                                                  

  uint32_t MultiTwoSamplingDelay;                                                              
                                                                                                               
                                                                                                           
                                                                                       
#endif                            

} LL_ADC_CommonInitTypeDef;

   
                                                                  
                                                                       
                                                                       
                                                           
                                                         
                                                       
                                                                          
                                        
                                          
                                                                         
                                                                           
                                                                    
                                                                           
                                                      
                                                                          
                                                                        
                                                             
                                     
    
typedef struct
{
  uint32_t Resolution;                                          
                                                                                                       
                                                                                                           
                                                                            

  uint32_t DataAlignment;                                                      
                                                                                                       
                                                                                                           
                                                                               

  uint32_t LowPowerMode;                                            
                                                                                                    
                                                                                                           
                                                                              

} LL_ADC_InitTypeDef;

   
                                                                       
                                                                            
                                                         
                                                          
                                          
                                                                              
                                        
                                          
                                                                         
                                                                           
                                                                    
                                                                           
                                                      
                                                                          
                                                                        
                                                             
                                     
    
typedef struct
{
  uint32_t TriggerSource;                                                                                           
                                                                                                             
                                                                                                               
                                                                                                                        
                                                                                                                        
                                                                                                                    
                                                                  
                                                                                                       
                                                                                    
                                                                                                           
                                                                                   

  uint32_t SequencerLength;                                                         
                                                                                                                
                                                                                                           
                                                                                     

  uint32_t SequencerDiscont;                                                                                        
                                                                                                             
                                                                                                                 
                                                                                                                  
                                                                                             
                                                                                                           
                                                                                      

  uint32_t ContinuousMode;                                                                                       
                                                                                                                        
                                                                                                                     
                                                                         
                                                                                                                
                                                                                                                      
                                                                          
                                                                                                           
                                                                                    

  uint32_t DMATransfer;                                                                                             
                                                                           
                                                                                                             
                                                                                                           
                                                                                 

  uint32_t Overrun;                                                                            
                                                                           
                                                                                                                  
                                                                                                           
                                                                             

} LL_ADC_REG_InitTypeDef;

   
                                                                        
                                                                             
                                                         
                                                          
                                          
                                                                              
                                        
                                          
                                                                         
                                                                           
                                                                    
                                                                           
                                                      
                                                                          
                                                                        
                                                             
                                     
    
typedef struct
{
  uint32_t TriggerSource;                                                                                         
                                                                                                                
                                                                                                               
                                                                                                                        
                                                                                                           
                                                                                                                
                                                                                    
                                                                                                       
                                                                                    
                                                                                                           
                                                                                   

  uint32_t SequencerLength;                                                          
                                                                                                                
                                                                                                           
                                                                                     

  uint32_t SequencerDiscont;                                                                                         
                                                                                                             
                                                                                                                 
                                                                                                                   
                                                                                            
                                                                                                           
                                                                                      

  uint32_t TrigAuto;                                                                                                 
                                                     
                                                                                                          
                                                                                                                       
                                                                                                
                                                                                                           
                                                                              

} LL_ADC_INJ_InitTypeDef;

   
      
    
#endif                         

                                                                                
                                                              
      
    

                                      
                                                                          
      
    
#define LL_ADC_FLAG_ADRDY                  ADC_ISR_ADRDY                                         
#define LL_ADC_FLAG_EOC                    ADC_ISR_EOC                                                      
                                                        
#define LL_ADC_FLAG_EOS                    ADC_ISR_EOS                                                       
                                                         
#define LL_ADC_FLAG_OVR                    ADC_ISR_OVR                                                  
#define LL_ADC_FLAG_EOSMP                  ADC_ISR_EOSMP                                                              
#define LL_ADC_FLAG_JEOC                   ADC_ISR_JEOC                                                      
                                                                                
#define LL_ADC_FLAG_JEOS                   ADC_ISR_JEOS                                                       
                                                                                 
#define LL_ADC_FLAG_JQOVF                  ADC_ISR_JQOVF                                                     
                                                                              
#define LL_ADC_FLAG_AWD1                   ADC_ISR_AWD1                                             
#define LL_ADC_FLAG_AWD2                   ADC_ISR_AWD2                                             
#define LL_ADC_FLAG_AWD3                   ADC_ISR_AWD3                                             
#if defined(ADC_MULTIMODE_SUPPORT)
#define LL_ADC_FLAG_ADRDY_MST              ADC_CSR_ADRDY_MST                                                      
#define LL_ADC_FLAG_ADRDY_SLV              ADC_CSR_ADRDY_SLV                                                     
#define LL_ADC_FLAG_EOC_MST                ADC_CSR_EOC_MST                                                           
                                                                                        
#define LL_ADC_FLAG_EOC_SLV                ADC_CSR_EOC_SLV                                                          
                                                                                        
#define LL_ADC_FLAG_EOS_MST                ADC_CSR_EOS_MST                                                           
                                                                                          
#define LL_ADC_FLAG_EOS_SLV                ADC_CSR_EOS_SLV                                                          
                                                                                          
#define LL_ADC_FLAG_OVR_MST                ADC_CSR_OVR_MST                                                    
                                                                             
#define LL_ADC_FLAG_OVR_SLV                ADC_CSR_OVR_SLV                                                   
                                                                             
#define LL_ADC_FLAG_EOSMP_MST              ADC_CSR_EOSMP_MST                                                         
                                                                                    
#define LL_ADC_FLAG_EOSMP_SLV              ADC_CSR_EOSMP_SLV                                                        
                                                                                    
#define LL_ADC_FLAG_JEOC_MST               ADC_CSR_JEOC_MST                                                           
                                                                                        
#define LL_ADC_FLAG_JEOC_SLV               ADC_CSR_JEOC_SLV                                                          
                                                                                        
#define LL_ADC_FLAG_JEOS_MST               ADC_CSR_JEOS_MST                                                           
                                                                                          
#define LL_ADC_FLAG_JEOS_SLV               ADC_CSR_JEOS_SLV                                                          
                                                                                          
#define LL_ADC_FLAG_JQOVF_MST              ADC_CSR_JQOVF_MST                                                   
                                                                                             
#define LL_ADC_FLAG_JQOVF_SLV              ADC_CSR_JQOVF_SLV                                                  
                                                                                             
#define LL_ADC_FLAG_AWD1_MST               ADC_CSR_AWD1_MST                                                       
                                                                                       
#define LL_ADC_FLAG_AWD1_SLV               ADC_CSR_AWD1_SLV                                                      
                                                                                      
#define LL_ADC_FLAG_AWD2_MST               ADC_CSR_AWD2_MST                                                       
                                                                                       
#define LL_ADC_FLAG_AWD2_SLV               ADC_CSR_AWD2_SLV                                                      
                                                                                      
#define LL_ADC_FLAG_AWD3_MST               ADC_CSR_AWD3_MST                                                       
                                                                                       
#define LL_ADC_FLAG_AWD3_SLV               ADC_CSR_AWD3_SLV                                                      
                                                                                      
#endif                            
   
      
    

                                                                                               
                                                                                             
      
    
#define LL_ADC_IT_ADRDY                    ADC_IER_ADRDYIE                                               
#define LL_ADC_IT_EOC                      ADC_IER_EOCIE                                                            
                                                                                
#define LL_ADC_IT_EOS                      ADC_IER_EOSIE                                                             
                                                                                 
#define LL_ADC_IT_OVR                      ADC_IER_OVRIE                                                        
#define LL_ADC_IT_EOSMP                    ADC_IER_EOSMPIE                                                           
                                                                           
#define LL_ADC_IT_JEOC                     ADC_IER_JEOCIE                                                            
                                                                                
#define LL_ADC_IT_JEOS                     ADC_IER_JEOSIE                                                             
                                                                                 
#define LL_ADC_IT_JQOVF                    ADC_IER_JQOVFIE                                                           
                                                                              
#define LL_ADC_IT_AWD1                     ADC_IER_AWD1IE                                                   
#define LL_ADC_IT_AWD2                     ADC_IER_AWD2IE                                                   
#define LL_ADC_IT_AWD3                     ADC_IER_AWD3IE                                                   
   
      
    

                                                                                
      
    
                                                                                
                                                                                
                                                                                
#define LL_ADC_DMA_REG_REGULAR_DATA        (0x00000000UL)                                                   
                                                                                                                       
                                                                                                       
                                                                                           
                                                                                             
#if defined(ADC_MULTIMODE_SUPPORT)
#define LL_ADC_DMA_REG_REGULAR_DATA_MULTI  (0x00000001UL)                                                   
                                                                                                                      
                                                                                                   
                                                                                                 
                                                                                         
#endif                            
   
      
    

                                                                      
      
    
#define LL_ADC_CLOCK_SYNC_PCLK_DIV1        (ADC_CCR_CKMODE_0)                                                           
                                                                         
#define LL_ADC_CLOCK_SYNC_PCLK_DIV2        (ADC_CCR_CKMODE_1)                                                           
                                                                                    
#define LL_ADC_CLOCK_SYNC_PCLK_DIV4        (ADC_CCR_CKMODE_1 | ADC_CCR_CKMODE_0)                                        
                                                                                    
#define LL_ADC_CLOCK_ASYNC_DIV1            (0x00000000UL)                                                         
                                                       
#define LL_ADC_CLOCK_ASYNC_DIV2            (ADC_CCR_PRESC_0)                                                   
                                                                     
#define LL_ADC_CLOCK_ASYNC_DIV4            (ADC_CCR_PRESC_1)                                                   
                                                                     
#define LL_ADC_CLOCK_ASYNC_DIV6            (ADC_CCR_PRESC_1 | ADC_CCR_PRESC_0)                                 
                                                                     
#define LL_ADC_CLOCK_ASYNC_DIV8            (ADC_CCR_PRESC_2)                                                   
                                                                     
#define LL_ADC_CLOCK_ASYNC_DIV10           (ADC_CCR_PRESC_2 | ADC_CCR_PRESC_0)                                 
                                                                      
#define LL_ADC_CLOCK_ASYNC_DIV12           (ADC_CCR_PRESC_2 | ADC_CCR_PRESC_1)                                 
                                                                      
#define LL_ADC_CLOCK_ASYNC_DIV16           (ADC_CCR_PRESC_2 | ADC_CCR_PRESC_1 \
                                            | ADC_CCR_PRESC_0)                                                  
                                                                       
#define LL_ADC_CLOCK_ASYNC_DIV32           (ADC_CCR_PRESC_3)                                                   
                                                                      
#define LL_ADC_CLOCK_ASYNC_DIV64           (ADC_CCR_PRESC_3 | ADC_CCR_PRESC_0)                                 
                                                                      
#define LL_ADC_CLOCK_ASYNC_DIV128          (ADC_CCR_PRESC_3 | ADC_CCR_PRESC_1)                                 
                                                                       
#define LL_ADC_CLOCK_ASYNC_DIV256          (ADC_CCR_PRESC_3 | ADC_CCR_PRESC_1 \
                                            | ADC_CCR_PRESC_0)                                                  
                                                                       
   
      
    

                                                                                                
      
    
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
#define LL_ADC_PATH_INTERNAL_NONE          (0x00000000UL)                                                 
#define LL_ADC_PATH_INTERNAL_VREFINT       (ADC_CCR_VREFEN)                                                             
#define LL_ADC_PATH_INTERNAL_TEMPSENSOR    (ADC_CCR_TSEN)                                                    
                                                                                          
#define LL_ADC_PATH_INTERNAL_VBAT          (ADC_CCR_VBATEN)                                                          
   
      
    

                                                             
      
    
#define LL_ADC_RESOLUTION_12B              (0x00000000UL)                                                    
#define LL_ADC_RESOLUTION_10B              (                 ADC_CFGR_RES_0)                                 
#define LL_ADC_RESOLUTION_8B               (ADC_CFGR_RES_1                 )                                 
#define LL_ADC_RESOLUTION_6B               (ADC_CFGR_RES_1 | ADC_CFGR_RES_0)                                 
   
      
    

                                                                 
      
    
#define LL_ADC_DATA_ALIGN_RIGHT            (0x00000000UL)                                                      
                                                                                   
#define LL_ADC_DATA_ALIGN_LEFT             (ADC_CFGR_ALIGN)                                                   
                                                                                    
   
      
    

                                                              
      
    
#define LL_ADC_LP_MODE_NONE                (0x00000000UL)                                            
#define LL_ADC_LP_AUTOWAIT                 (ADC_CFGR_AUTDLY)                                                       
                                                                                                  
                                                                                       
                                                                                                          
   
      
    

                                                                 
      
    
#define LL_ADC_OFFSET_1                    ADC_OFR1_REGOFFSET                                                         
                                                                                                                   
                                                                                      
#define LL_ADC_OFFSET_2                    ADC_OFR2_REGOFFSET                                                         
                                                                                                                   
                                                                                      
#define LL_ADC_OFFSET_3                    ADC_OFR3_REGOFFSET                                                         
                                                                                                                   
                                                                                      
#define LL_ADC_OFFSET_4                    ADC_OFR4_REGOFFSET                                                         
                                                                                                                   
                                                                                      
   
      
    

                                                                
      
    
#define LL_ADC_OFFSET_DISABLE              (0x00000000UL)                                 
                                                                            
#define LL_ADC_OFFSET_ENABLE               (ADC_OFR1_OFFSET1_EN)                         
                                                                            
   
      
    

                                                     
      
    
#define LL_ADC_GROUP_REGULAR               (0x00000001UL)                                                               
#define LL_ADC_GROUP_INJECTED              (0x00000002UL)                                                        
                                                     
#define LL_ADC_GROUP_REGULAR_INJECTED      (0x00000003UL)                                                 
   
      
    

                                                              
      
    
#define LL_ADC_CHANNEL_0                   (ADC_CHANNEL_0_NUMBER  | ADC_CHANNEL_0_SMP \
                                            | ADC_CHANNEL_0_BITFIELD)                                                   
#define LL_ADC_CHANNEL_1                   (ADC_CHANNEL_1_NUMBER  | ADC_CHANNEL_1_SMP \
                                            | ADC_CHANNEL_1_BITFIELD)                                                   
#define LL_ADC_CHANNEL_2                   (ADC_CHANNEL_2_NUMBER  | ADC_CHANNEL_2_SMP \
                                            | ADC_CHANNEL_2_BITFIELD)                                                   
#define LL_ADC_CHANNEL_3                   (ADC_CHANNEL_3_NUMBER  | ADC_CHANNEL_3_SMP \
                                            | ADC_CHANNEL_3_BITFIELD)                                                   
#define LL_ADC_CHANNEL_4                   (ADC_CHANNEL_4_NUMBER  | ADC_CHANNEL_4_SMP \
                                            | ADC_CHANNEL_4_BITFIELD)                                                   
#define LL_ADC_CHANNEL_5                   (ADC_CHANNEL_5_NUMBER  | ADC_CHANNEL_5_SMP \
                                            | ADC_CHANNEL_5_BITFIELD)                                                   
#define LL_ADC_CHANNEL_6                   (ADC_CHANNEL_6_NUMBER  | ADC_CHANNEL_6_SMP \
                                            | ADC_CHANNEL_6_BITFIELD)                                                   
#define LL_ADC_CHANNEL_7                   (ADC_CHANNEL_7_NUMBER  | ADC_CHANNEL_7_SMP \
                                            | ADC_CHANNEL_7_BITFIELD)                                                   
#define LL_ADC_CHANNEL_8                   (ADC_CHANNEL_8_NUMBER  | ADC_CHANNEL_8_SMP \
                                            | ADC_CHANNEL_8_BITFIELD)                                                   
#define LL_ADC_CHANNEL_9                   (ADC_CHANNEL_9_NUMBER  | ADC_CHANNEL_9_SMP \
                                            | ADC_CHANNEL_9_BITFIELD)                                                   
#define LL_ADC_CHANNEL_10                  (ADC_CHANNEL_10_NUMBER | ADC_CHANNEL_10_SMP \
                                            | ADC_CHANNEL_10_BITFIELD)                                                   
#define LL_ADC_CHANNEL_11                  (ADC_CHANNEL_11_NUMBER | ADC_CHANNEL_11_SMP \
                                            | ADC_CHANNEL_11_BITFIELD)                                                   
#define LL_ADC_CHANNEL_12                  (ADC_CHANNEL_12_NUMBER | ADC_CHANNEL_12_SMP \
                                            | ADC_CHANNEL_12_BITFIELD)                                                   
#define LL_ADC_CHANNEL_13                  (ADC_CHANNEL_13_NUMBER | ADC_CHANNEL_13_SMP \
                                            | ADC_CHANNEL_13_BITFIELD)                                                   
#define LL_ADC_CHANNEL_14                  (ADC_CHANNEL_14_NUMBER | ADC_CHANNEL_14_SMP \
                                            | ADC_CHANNEL_14_BITFIELD)                                                   
#define LL_ADC_CHANNEL_15                  (ADC_CHANNEL_15_NUMBER | ADC_CHANNEL_15_SMP \
                                            | ADC_CHANNEL_15_BITFIELD)                                                   
#define LL_ADC_CHANNEL_16                  (ADC_CHANNEL_16_NUMBER | ADC_CHANNEL_16_SMP | \
                                           ADC_CHANNEL_16_BITFIELD)                                                     
#define LL_ADC_CHANNEL_17                  (ADC_CHANNEL_17_NUMBER | ADC_CHANNEL_17_SMP | \
                                           ADC_CHANNEL_17_BITFIELD)                                                     
#define LL_ADC_CHANNEL_18                  (ADC_CHANNEL_18_NUMBER | ADC_CHANNEL_18_SMP | \
                                           ADC_CHANNEL_18_BITFIELD)                                                     
#define LL_ADC_CHANNEL_VREFINT             (LL_ADC_CHANNEL_0  | ADC_CHANNEL_ID_INTERNAL_CH)                          
                                                                                            
                                                                                                           
#define LL_ADC_CHANNEL_TEMPSENSOR          (LL_ADC_CHANNEL_17 | ADC_CHANNEL_ID_INTERNAL_CH)                          
                                                                                    
                                                                                                                  
#define LL_ADC_CHANNEL_VBAT                (LL_ADC_CHANNEL_18 | ADC_CHANNEL_ID_INTERNAL_CH)                          
                                                                                                                   
                                                                                     
                                                                                                                  
#if defined(ADC1) && !defined(ADC2)
#define LL_ADC_CHANNEL_DAC1CH1             (LL_ADC_CHANNEL_17 | ADC_CHANNEL_ID_INTERNAL_CH | \
                                           ADC_CHANNEL_ID_INTERNAL_CH_2)                                               
                                                                                                                 
                                                                                                                     
                                                                                                                     
#define LL_ADC_CHANNEL_DAC1CH2             (LL_ADC_CHANNEL_18 | ADC_CHANNEL_ID_INTERNAL_CH | \
                                           ADC_CHANNEL_ID_INTERNAL_CH_2)                                               
                                                                                                                 
                                                                                              
                                                                                                                     
#elif defined(ADC2)
#define LL_ADC_CHANNEL_DAC1CH1_ADC2        (LL_ADC_CHANNEL_17 | ADC_CHANNEL_ID_INTERNAL_CH | \
                                           ADC_CHANNEL_ID_INTERNAL_CH_2)                                               
                                                                                                   
#define LL_ADC_CHANNEL_DAC1CH2_ADC2        (LL_ADC_CHANNEL_18 | ADC_CHANNEL_ID_INTERNAL_CH | \
                                           ADC_CHANNEL_ID_INTERNAL_CH_2)                                               
                                                                                                   
#if defined(ADC3)
#define LL_ADC_CHANNEL_DAC1CH1_ADC3        (LL_ADC_CHANNEL_14 | ADC_CHANNEL_ID_INTERNAL_CH)                          
                                                                                                   
#define LL_ADC_CHANNEL_DAC1CH2_ADC3        (LL_ADC_CHANNEL_15 | ADC_CHANNEL_ID_INTERNAL_CH)                          
                                                                                                   
#endif           
#endif                    
   
      
    

                                                                              
      
    
#define LL_ADC_REG_TRIG_SOFTWARE           (0x00000000UL)                                                              
                                                                                    
#define LL_ADC_REG_TRIG_EXT_TIM1_TRGO      (ADC_CFGR_EXTSEL_3 | ADC_CFGR_EXTSEL_0 | \
                                           ADC_REG_TRIG_EXT_EDGE_DEFAULT)                                              
                                                                                                                      
                                                                            
#define LL_ADC_REG_TRIG_EXT_TIM1_TRGO2     (ADC_CFGR_EXTSEL_3 | ADC_CFGR_EXTSEL_1 | \
                                           ADC_REG_TRIG_EXT_EDGE_DEFAULT)                                              
                                                                                                                       
                                                                            
#define LL_ADC_REG_TRIG_EXT_TIM1_CH1       (ADC_REG_TRIG_EXT_EDGE_DEFAULT)                                             
                                                                                                                     
                                                                                                                     
                                                                
#define LL_ADC_REG_TRIG_EXT_TIM1_CH2       (ADC_CFGR_EXTSEL_0 | ADC_REG_TRIG_EXT_EDGE_DEFAULT)                         
                                                                                                                     
                                                                                                                     
                                                                
#define LL_ADC_REG_TRIG_EXT_TIM1_CH3       (ADC_CFGR_EXTSEL_1 | ADC_REG_TRIG_EXT_EDGE_DEFAULT)                         
                                                                                                                     
                                                                                                                     
                                                                
#define LL_ADC_REG_TRIG_EXT_TIM2_TRGO      (ADC_CFGR_EXTSEL_3 | ADC_CFGR_EXTSEL_1 | \
                                           ADC_CFGR_EXTSEL_0 | ADC_REG_TRIG_EXT_EDGE_DEFAULT)                          
                                                                                                                      
                                                                            
#define LL_ADC_REG_TRIG_EXT_TIM2_CH2       (ADC_CFGR_EXTSEL_1 | ADC_CFGR_EXTSEL_0 | \
                                           ADC_REG_TRIG_EXT_EDGE_DEFAULT)                                              
                                                                                                                     
                                                                                                                     
                                                                
#define LL_ADC_REG_TRIG_EXT_TIM3_TRGO      (ADC_CFGR_EXTSEL_2 | ADC_REG_TRIG_EXT_EDGE_DEFAULT)                         
                                                                                                                      
                                                                            
#define LL_ADC_REG_TRIG_EXT_TIM3_CH4       (ADC_CFGR_EXTSEL_3 | ADC_CFGR_EXTSEL_2 | \
                                           ADC_CFGR_EXTSEL_1 | ADC_CFGR_EXTSEL_0 | \
                                           ADC_REG_TRIG_EXT_EDGE_DEFAULT)                                              
                                                                                                                     
                                                                                                                     
                                                                
#define LL_ADC_REG_TRIG_EXT_TIM4_TRGO      (ADC_CFGR_EXTSEL_3 | ADC_CFGR_EXTSEL_2 | \
                                           ADC_REG_TRIG_EXT_EDGE_DEFAULT)                                              
                                                                                                                      
                                                                            
#define LL_ADC_REG_TRIG_EXT_TIM4_CH4       (ADC_CFGR_EXTSEL_2 | ADC_CFGR_EXTSEL_0 | \
                                           ADC_REG_TRIG_EXT_EDGE_DEFAULT)                                              
                                                                                                                     
                                                                                                         
                                                                            
#define LL_ADC_REG_TRIG_EXT_TIM6_TRGO      (ADC_CFGR_EXTSEL_3 | ADC_CFGR_EXTSEL_2 | \
                                           ADC_CFGR_EXTSEL_0 | ADC_REG_TRIG_EXT_EDGE_DEFAULT)                          
                                                                                                                      
                                                                            
#define LL_ADC_REG_TRIG_EXT_TIM8_TRGO      (ADC_CFGR_EXTSEL_2 | ADC_CFGR_EXTSEL_1 | \
                                           ADC_CFGR_EXTSEL_0 | ADC_REG_TRIG_EXT_EDGE_DEFAULT)                          
                                                                                                                      
                                                                            
#define LL_ADC_REG_TRIG_EXT_TIM8_TRGO2     (ADC_CFGR_EXTSEL_3 | ADC_REG_TRIG_EXT_EDGE_DEFAULT)                         
                                                                                                                       
                                                                            
#define LL_ADC_REG_TRIG_EXT_TIM15_TRGO     (ADC_CFGR_EXTSEL_3 | ADC_CFGR_EXTSEL_2 | \
                                           ADC_CFGR_EXTSEL_1 | ADC_REG_TRIG_EXT_EDGE_DEFAULT)                          
                                                                                                                       
                                                                            
#define LL_ADC_REG_TRIG_EXT_EXTI_LINE11    (ADC_CFGR_EXTSEL_2 | ADC_CFGR_EXTSEL_1 | \
                                           ADC_REG_TRIG_EXT_EDGE_DEFAULT)                                              
                                                                                                                   
                                                                                                
   
      
    

                                                                          
      
    
#define LL_ADC_REG_TRIG_EXT_RISING         (ADC_CFGR_EXTEN_0)                                                       
                                                                                 
#define LL_ADC_REG_TRIG_EXT_FALLING        (ADC_CFGR_EXTEN_1)                                                       
                                                                                  
#define LL_ADC_REG_TRIG_EXT_RISINGFALLING  (ADC_CFGR_EXTEN_1 | ADC_CFGR_EXTEN_0)                                    
                                                                                                   
   
      
    

                                                                                
      
    
#define LL_ADC_REG_CONV_SINGLE             (0x00000000UL)                                                   
                                                                        
#define LL_ADC_REG_CONV_CONTINUOUS         (ADC_CFGR_CONT)                                                      
                                                                                                               
                                                           
   
      
    

                                                                                                 
      
    
#define LL_ADC_REG_DMA_TRANSFER_NONE       (0x00000000UL)                                                       
#define LL_ADC_REG_DMA_TRANSFER_LIMITED    (ADC_CFGR_DMAEN)                                                  
                                                                                                                  
                                                                                                               
                                                                                                              
#define LL_ADC_REG_DMA_TRANSFER_UNLIMITED  (ADC_CFGR_DMACFG | ADC_CFGR_DMAEN)                                
                                                                                                                      
                                                                                                               
                                                                                                          
   
      
    

#if defined(ADC_CFGR_DFSDMCFG) &&defined(DFSDM1_Channel0)
                                                                                                    
      
    
#define LL_ADC_REG_DFSDM_TRANSFER_NONE     (0x00000000UL)                                                           
#define LL_ADC_REG_DFSDM_TRANSFER_ENABLE   (ADC_CFGR_DFSDMCFG)                                                      
                                                                                                                    
                                                                                    
                                                                                                       
   
      
    
#endif                        

#if defined(ADC_SMPR1_SMPPLUS)
                                                                                                        
      
    
#define LL_ADC_SAMPLINGTIME_COMMON_DEFAULT      (0x00000000UL)                                                        
#define LL_ADC_SAMPLINGTIME_COMMON_3C5_REPL_2C5 (ADC_SMPR1_SMPPLUS)                                                
                                                                                                                     
                                                                                                                      
                                                                                 
   
      
    
#endif                        

                                                                                                      
      
    
#define LL_ADC_REG_OVR_DATA_PRESERVED      (0x00000000UL)                                                        
                                                                                    
#define LL_ADC_REG_OVR_DATA_OVERWRITTEN    (ADC_CFGR_OVRMOD)                                                     
                                                                                      
   
      
    

                                                                                      
      
    
#define LL_ADC_REG_SEQ_SCAN_DISABLE        (0x00000000UL)                                                         
                                                                                                                   
#define LL_ADC_REG_SEQ_SCAN_ENABLE_2RANKS  (ADC_SQR1_L_0)                                                        
                                                                          
#define LL_ADC_REG_SEQ_SCAN_ENABLE_3RANKS  (ADC_SQR1_L_1)                                                        
                                                                          
#define LL_ADC_REG_SEQ_SCAN_ENABLE_4RANKS  (ADC_SQR1_L_1 | ADC_SQR1_L_0)                                         
                                                                          
#define LL_ADC_REG_SEQ_SCAN_ENABLE_5RANKS  (ADC_SQR1_L_2)                                                        
                                                                          
#define LL_ADC_REG_SEQ_SCAN_ENABLE_6RANKS  (ADC_SQR1_L_2 | ADC_SQR1_L_0)                                         
                                                                          
#define LL_ADC_REG_SEQ_SCAN_ENABLE_7RANKS  (ADC_SQR1_L_2 | ADC_SQR1_L_1)                                        
                                                                          
#define LL_ADC_REG_SEQ_SCAN_ENABLE_8RANKS  (ADC_SQR1_L_2 | ADC_SQR1_L_1 \
                                            | ADC_SQR1_L_0)                                                       
                                                                          
#define LL_ADC_REG_SEQ_SCAN_ENABLE_9RANKS  (ADC_SQR1_L_3)                                                        
                                                                          
#define LL_ADC_REG_SEQ_SCAN_ENABLE_10RANKS (ADC_SQR1_L_3 | ADC_SQR1_L_0)                                         
                                                                           
#define LL_ADC_REG_SEQ_SCAN_ENABLE_11RANKS (ADC_SQR1_L_3 | ADC_SQR1_L_1)                                         
                                                                           
#define LL_ADC_REG_SEQ_SCAN_ENABLE_12RANKS (ADC_SQR1_L_3 | ADC_SQR1_L_1 \
                                            | ADC_SQR1_L_0)                                                       
                                                                           
#define LL_ADC_REG_SEQ_SCAN_ENABLE_13RANKS (ADC_SQR1_L_3 | ADC_SQR1_L_2)                                         
                                                                           
#define LL_ADC_REG_SEQ_SCAN_ENABLE_14RANKS (ADC_SQR1_L_3 | ADC_SQR1_L_2 \
                                            | ADC_SQR1_L_0)                                                       
                                                                           
#define LL_ADC_REG_SEQ_SCAN_ENABLE_15RANKS (ADC_SQR1_L_3 | ADC_SQR1_L_2 \
                                            | ADC_SQR1_L_1)                                                      
                                                                           
#define LL_ADC_REG_SEQ_SCAN_ENABLE_16RANKS (ADC_SQR1_L_3 | ADC_SQR1_L_2 \
                                            | ADC_SQR1_L_1 | ADC_SQR1_L_0)                                        
                                                                                                              
   
      
    

                                                                                              
      
    
#define LL_ADC_REG_SEQ_DISCONT_DISABLE     (0x00000000UL)                                                          
                                                                        
#define LL_ADC_REG_SEQ_DISCONT_1RANK       (ADC_CFGR_DISCEN)                                                       
                                                                                                             
#define LL_ADC_REG_SEQ_DISCONT_2RANKS      (ADC_CFGR_DISCNUM_0 | ADC_CFGR_DISCEN)                                  
                                                                                                                 
#define LL_ADC_REG_SEQ_DISCONT_3RANKS      (ADC_CFGR_DISCNUM_1 | ADC_CFGR_DISCEN)                                  
                                                                                                                
#define LL_ADC_REG_SEQ_DISCONT_4RANKS      (ADC_CFGR_DISCNUM_1 | ADC_CFGR_DISCNUM_0 \
                                            | ADC_CFGR_DISCEN)                                                       
                                                                                                                
#define LL_ADC_REG_SEQ_DISCONT_5RANKS      (ADC_CFGR_DISCNUM_2 | ADC_CFGR_DISCEN)                                   
                                                                                                                
#define LL_ADC_REG_SEQ_DISCONT_6RANKS      (ADC_CFGR_DISCNUM_2 | ADC_CFGR_DISCNUM_0 \
                                            | ADC_CFGR_DISCEN)                                                       
                                                                                                                
#define LL_ADC_REG_SEQ_DISCONT_7RANKS      (ADC_CFGR_DISCNUM_2 | ADC_CFGR_DISCNUM_1 \
                                            | ADC_CFGR_DISCEN)                                                       
                                                                                                                
#define LL_ADC_REG_SEQ_DISCONT_8RANKS      (ADC_CFGR_DISCNUM_2 | ADC_CFGR_DISCNUM_1 \
                                            | ADC_CFGR_DISCNUM_0 | ADC_CFGR_DISCEN)                                  
                                                                                                                
   
      
    

                                                                          
      
    
#define LL_ADC_REG_RANK_1                  (ADC_SQR1_REGOFFSET | ADC_REG_RANK_1_SQRX_BITOFFSET_POS)                
                                                                      
#define LL_ADC_REG_RANK_2                  (ADC_SQR1_REGOFFSET | ADC_REG_RANK_2_SQRX_BITOFFSET_POS)                
                                                                      
#define LL_ADC_REG_RANK_3                  (ADC_SQR1_REGOFFSET | ADC_REG_RANK_3_SQRX_BITOFFSET_POS)                
                                                                      
#define LL_ADC_REG_RANK_4                  (ADC_SQR1_REGOFFSET | ADC_REG_RANK_4_SQRX_BITOFFSET_POS)                
                                                                      
#define LL_ADC_REG_RANK_5                  (ADC_SQR2_REGOFFSET | ADC_REG_RANK_5_SQRX_BITOFFSET_POS)                
                                                                      
#define LL_ADC_REG_RANK_6                  (ADC_SQR2_REGOFFSET | ADC_REG_RANK_6_SQRX_BITOFFSET_POS)                
                                                                      
#define LL_ADC_REG_RANK_7                  (ADC_SQR2_REGOFFSET | ADC_REG_RANK_7_SQRX_BITOFFSET_POS)                
                                                                      
#define LL_ADC_REG_RANK_8                  (ADC_SQR2_REGOFFSET | ADC_REG_RANK_8_SQRX_BITOFFSET_POS)                
                                                                      
#define LL_ADC_REG_RANK_9                  (ADC_SQR2_REGOFFSET | ADC_REG_RANK_9_SQRX_BITOFFSET_POS)                
                                                                      
#define LL_ADC_REG_RANK_10                 (ADC_SQR3_REGOFFSET | ADC_REG_RANK_10_SQRX_BITOFFSET_POS)               
                                                                       
#define LL_ADC_REG_RANK_11                 (ADC_SQR3_REGOFFSET | ADC_REG_RANK_11_SQRX_BITOFFSET_POS)               
                                                                       
#define LL_ADC_REG_RANK_12                 (ADC_SQR3_REGOFFSET | ADC_REG_RANK_12_SQRX_BITOFFSET_POS)               
                                                                       
#define LL_ADC_REG_RANK_13                 (ADC_SQR3_REGOFFSET | ADC_REG_RANK_13_SQRX_BITOFFSET_POS)               
                                                                       
#define LL_ADC_REG_RANK_14                 (ADC_SQR3_REGOFFSET | ADC_REG_RANK_14_SQRX_BITOFFSET_POS)               
                                                                       
#define LL_ADC_REG_RANK_15                 (ADC_SQR4_REGOFFSET | ADC_REG_RANK_15_SQRX_BITOFFSET_POS)               
                                                                       
#define LL_ADC_REG_RANK_16                 (ADC_SQR4_REGOFFSET | ADC_REG_RANK_16_SQRX_BITOFFSET_POS)               
                                                                       
   
      
    

                                                                               
      
    
#define LL_ADC_INJ_TRIG_SOFTWARE           (0x00000000UL)                                                               
                                                                                    
#define LL_ADC_INJ_TRIG_EXT_TIM1_TRGO      (ADC_INJ_TRIG_EXT_EDGE_DEFAULT)                                              
                                                                                                                      
                                                                            
#define LL_ADC_INJ_TRIG_EXT_TIM1_TRGO2     (ADC_JSQR_JEXTSEL_3 | ADC_INJ_TRIG_EXT_EDGE_DEFAULT)                         
                                                                                                                       
                                                                            
#define LL_ADC_INJ_TRIG_EXT_TIM1_CH4       (ADC_JSQR_JEXTSEL_0 | ADC_INJ_TRIG_EXT_EDGE_DEFAULT)                         
                                                                                                                     
                                                                                                                     
                                                                
#define LL_ADC_INJ_TRIG_EXT_TIM2_TRGO      (ADC_JSQR_JEXTSEL_1 | ADC_INJ_TRIG_EXT_EDGE_DEFAULT)                         
                                                                                                                      
                                                                            
#define LL_ADC_INJ_TRIG_EXT_TIM2_CH1       (ADC_JSQR_JEXTSEL_1 | ADC_JSQR_JEXTSEL_0 | \
                                           ADC_INJ_TRIG_EXT_EDGE_DEFAULT)                                               
                                                                                                                     
                                                                                                                     
                                                                
#define LL_ADC_INJ_TRIG_EXT_TIM3_TRGO      (ADC_JSQR_JEXTSEL_3 | ADC_JSQR_JEXTSEL_2 | \
                                           ADC_INJ_TRIG_EXT_EDGE_DEFAULT)                                               
                                                                                                                      
                                                                            
#define LL_ADC_INJ_TRIG_EXT_TIM3_CH1       (ADC_JSQR_JEXTSEL_3 | ADC_JSQR_JEXTSEL_2 | \
                                           ADC_JSQR_JEXTSEL_0 | ADC_INJ_TRIG_EXT_EDGE_DEFAULT)                          
                                                                                                                     
                                                                                                                     
                                                                
#define LL_ADC_INJ_TRIG_EXT_TIM3_CH3       (ADC_JSQR_JEXTSEL_3 | ADC_JSQR_JEXTSEL_1 | \
                                           ADC_JSQR_JEXTSEL_0 | ADC_INJ_TRIG_EXT_EDGE_DEFAULT)                          
                                                                                                                     
                                                                                                                     
                                                                
#define LL_ADC_INJ_TRIG_EXT_TIM3_CH4       (ADC_JSQR_JEXTSEL_2 | ADC_INJ_TRIG_EXT_EDGE_DEFAULT)                         
                                                                                                                     
                                                                                                                     
                                                                
#define LL_ADC_INJ_TRIG_EXT_TIM4_TRGO      (ADC_JSQR_JEXTSEL_2 | ADC_JSQR_JEXTSEL_0 | \
                                           ADC_INJ_TRIG_EXT_EDGE_DEFAULT)                                               
                                                                                                                      
                                                                            
#define LL_ADC_INJ_TRIG_EXT_TIM6_TRGO      (ADC_JSQR_JEXTSEL_3 | ADC_JSQR_JEXTSEL_2 | \
                                           ADC_JSQR_JEXTSEL_1 | ADC_INJ_TRIG_EXT_EDGE_DEFAULT)                          
                                                                                                                      
                                                                            
#define LL_ADC_INJ_TRIG_EXT_TIM8_CH4       (ADC_JSQR_JEXTSEL_2 | ADC_JSQR_JEXTSEL_1 | \
                                           ADC_JSQR_JEXTSEL_0 | ADC_INJ_TRIG_EXT_EDGE_DEFAULT)                          
                                                                                                                     
                                                                                                                     
                                                                
#define LL_ADC_INJ_TRIG_EXT_TIM8_TRGO      (ADC_JSQR_JEXTSEL_3 | ADC_JSQR_JEXTSEL_0 | \
                                           ADC_INJ_TRIG_EXT_EDGE_DEFAULT)                                               
                                                                                                                      
                                                                            
#define LL_ADC_INJ_TRIG_EXT_TIM8_TRGO2     (ADC_JSQR_JEXTSEL_3 | ADC_JSQR_JEXTSEL_1 | \
                                           ADC_INJ_TRIG_EXT_EDGE_DEFAULT)                                               
                                                                                                                       
                                                                            
#define LL_ADC_INJ_TRIG_EXT_TIM15_TRGO     (ADC_JSQR_JEXTSEL_3 | ADC_JSQR_JEXTSEL_2 | \
                                           ADC_JSQR_JEXTSEL_1 | ADC_JSQR_JEXTSEL_0 | \
                                           ADC_INJ_TRIG_EXT_EDGE_DEFAULT)                                               
                                                                                                                       
                                                                            
#define LL_ADC_INJ_TRIG_EXT_EXTI_LINE15    (ADC_JSQR_JEXTSEL_2 | ADC_JSQR_JEXTSEL_1 | \
                                           ADC_INJ_TRIG_EXT_EDGE_DEFAULT)                                               
                                                                                                                   
                                                                                                
   
      
    

                                                                           
      
    
#define LL_ADC_INJ_TRIG_EXT_RISING         (                    ADC_JSQR_JEXTEN_0)                                   
                                                                                 
#define LL_ADC_INJ_TRIG_EXT_FALLING        (ADC_JSQR_JEXTEN_1                    )                                   
                                                                                  
#define LL_ADC_INJ_TRIG_EXT_RISINGFALLING  (ADC_JSQR_JEXTEN_1 | ADC_JSQR_JEXTEN_0)                                   
                                                                                                   
   
      
    

                                                                                  
      
    
#define LL_ADC_INJ_TRIG_INDEPENDENT        (0x00000000UL)                                                            
                                                                                                                    
                                                                  
#define LL_ADC_INJ_TRIG_FROM_GRP_REGULAR   (ADC_CFGR_JAUTO)                                                            
                                                                                                                    
                                                                                                                       
                                                                                                                      
                                                      
   
      
    

                                                                                  
      
    
#define LL_ADC_INJ_QUEUE_2CONTEXTS_LAST_ACTIVE (0x00000000UL)                                                      
                                                                                                                   
                                                                                                      
#define LL_ADC_INJ_QUEUE_2CONTEXTS_END_EMPTY   (ADC_CFGR_JQM)                                                      
                                                                                                                   
                                                                                                          
#define LL_ADC_INJ_QUEUE_DISABLE               (ADC_CFGR_JQDIS)                                                      
                                                                                                          
   
      
    

                                                                                       
      
    
#define LL_ADC_INJ_SEQ_SCAN_DISABLE        (0x00000000UL)                                                           
                                                                                                                   
#define LL_ADC_INJ_SEQ_SCAN_ENABLE_2RANKS  (                ADC_JSQR_JL_0)                                         
                                                                          
#define LL_ADC_INJ_SEQ_SCAN_ENABLE_3RANKS  (ADC_JSQR_JL_1                )                                         
                                                                          
#define LL_ADC_INJ_SEQ_SCAN_ENABLE_4RANKS  (ADC_JSQR_JL_1 | ADC_JSQR_JL_0)                                         
                                                                          
   
      
    

                                                                                               
      
    
#define LL_ADC_INJ_SEQ_DISCONT_DISABLE     (0x00000000UL)                                                         
                                                     
#define LL_ADC_INJ_SEQ_DISCONT_1RANK       (ADC_CFGR_JDISCEN)                                                     
                                                                                          
   
      
    

                                                                           
      
    
#define LL_ADC_INJ_RANK_1                  (ADC_JDR1_REGOFFSET \
                                            | ADC_INJ_RANK_1_JSQR_BITOFFSET_POS)                                        
#define LL_ADC_INJ_RANK_2                  (ADC_JDR2_REGOFFSET \
                                            | ADC_INJ_RANK_2_JSQR_BITOFFSET_POS)                                        
#define LL_ADC_INJ_RANK_3                  (ADC_JDR3_REGOFFSET \
                                            | ADC_INJ_RANK_3_JSQR_BITOFFSET_POS)                                        
#define LL_ADC_INJ_RANK_4                  (ADC_JDR4_REGOFFSET \
                                            | ADC_INJ_RANK_4_JSQR_BITOFFSET_POS)                                        
   
      
    

                                                                     
      
    
#define LL_ADC_SAMPLINGTIME_2CYCLES_5      (0x00000000UL)                                                 
#define LL_ADC_SAMPLINGTIME_6CYCLES_5      (ADC_SMPR2_SMP10_0)                                            
#define LL_ADC_SAMPLINGTIME_12CYCLES_5     (ADC_SMPR2_SMP10_1)                                             
#define LL_ADC_SAMPLINGTIME_24CYCLES_5     (ADC_SMPR2_SMP10_1 \
                                            | ADC_SMPR2_SMP10_0)                                            
#define LL_ADC_SAMPLINGTIME_47CYCLES_5     (ADC_SMPR2_SMP10_2)                                             
#define LL_ADC_SAMPLINGTIME_92CYCLES_5     (ADC_SMPR2_SMP10_2 \
                                            | ADC_SMPR2_SMP10_0)                                            
#define LL_ADC_SAMPLINGTIME_247CYCLES_5    (ADC_SMPR2_SMP10_2 \
                                            | ADC_SMPR2_SMP10_1)                                             
#define LL_ADC_SAMPLINGTIME_640CYCLES_5    (ADC_SMPR2_SMP10_2 \
                                            | ADC_SMPR2_SMP10_1 \
                                            | ADC_SMPR2_SMP10_0)                                             
   
      
    

                                                                                           
      
    
#define LL_ADC_SINGLE_ENDED                (                  ADC_CALFACT_CALFACT_S)                                
                                                                                                             
#define LL_ADC_DIFFERENTIAL_ENDED          (ADC_CR_ADCALDIF | ADC_CALFACT_CALFACT_D)                                
                                                                                                             
#define LL_ADC_BOTH_SINGLE_DIFF_ENDED      (LL_ADC_SINGLE_ENDED | LL_ADC_DIFFERENTIAL_ENDED)                        
                                                                                                              
                                                                  
   
      
    

                                                                           
      
    
#define LL_ADC_AWD1                        (ADC_AWD_CR1_CHANNEL_MASK \
                                            | ADC_AWD_CR1_REGOFFSET)                                     
#define LL_ADC_AWD2                        (ADC_AWD_CR23_CHANNEL_MASK \
                                            | ADC_AWD_CR2_REGOFFSET)                                     
#define LL_ADC_AWD3                        (ADC_AWD_CR23_CHANNEL_MASK \
                                            | ADC_AWD_CR3_REGOFFSET)                                     
   
      
    

                                                                          
      
    
#define LL_ADC_AWD_DISABLE                 (0x00000000UL)                                                              
                                                      
#define LL_ADC_AWD_ALL_CHANNELS_REG        (ADC_AWD_CR23_CHANNEL_MASK \
                                            | ADC_CFGR_AWD1EN)                                                          
                                                                                              
#define LL_ADC_AWD_ALL_CHANNELS_INJ        (ADC_AWD_CR23_CHANNEL_MASK \
                                            | ADC_CFGR_JAWD1EN)                                                         
                                                                                               
#define LL_ADC_AWD_ALL_CHANNELS_REG_INJ    (ADC_AWD_CR23_CHANNEL_MASK \
                                            | ADC_CFGR_JAWD1EN | ADC_CFGR_AWD1EN)                                       
                                                                                                            
#define LL_ADC_AWD_CHANNEL_0_REG           ((LL_ADC_CHANNEL_0  & ADC_CHANNEL_ID_MASK) \
                                            | ADC_CFGR_AWD1EN | ADC_CFGR_AWD1SGL)                                       
                                                                                                      
#define LL_ADC_AWD_CHANNEL_0_INJ           ((LL_ADC_CHANNEL_0  & ADC_CHANNEL_ID_MASK) \
                                            | ADC_CFGR_JAWD1EN | ADC_CFGR_AWD1SGL)                                      
                                                                                                       
#define LL_ADC_AWD_CHANNEL_0_REG_INJ       ((LL_ADC_CHANNEL_0  & ADC_CHANNEL_ID_MASK) \
                                            | ADC_CFGR_JAWD1EN | ADC_CFGR_AWD1EN \
                                            | ADC_CFGR_AWD1SGL)                                                         
                                                                                                                    
#define LL_ADC_AWD_CHANNEL_1_REG           ((LL_ADC_CHANNEL_1  & ADC_CHANNEL_ID_MASK) \
                                            | ADC_CFGR_AWD1EN | ADC_CFGR_AWD1SGL)                                       
                                                                                                      
#define LL_ADC_AWD_CHANNEL_1_INJ           ((LL_ADC_CHANNEL_1  & ADC_CHANNEL_ID_MASK) \
                                            | ADC_CFGR_JAWD1EN | ADC_CFGR_AWD1SGL)                                      
                                                                                                       
#define LL_ADC_AWD_CHANNEL_1_REG_INJ       ((LL_ADC_CHANNEL_1  & ADC_CHANNEL_ID_MASK) \
                                            | ADC_CFGR_JAWD1EN | ADC_CFGR_AWD1EN \
                                            | ADC_CFGR_AWD1SGL)                                                         
                                                                                                                    
#define LL_ADC_AWD_CHANNEL_2_REG           ((LL_ADC_CHANNEL_2  & ADC_CHANNEL_ID_MASK) \
                                            | ADC_CFGR_AWD1EN | ADC_CFGR_AWD1SGL)                                       
                                                                                                      
#define LL_ADC_AWD_CHANNEL_2_INJ           ((LL_ADC_CHANNEL_2  & ADC_CHANNEL_ID_MASK) \
                                            | ADC_CFGR_JAWD1EN | ADC_CFGR_AWD1SGL)                                      
                                                                                                       
#define LL_ADC_AWD_CHANNEL_2_REG_INJ       ((LL_ADC_CHANNEL_2  & ADC_CHANNEL_ID_MASK) \
                                            | ADC_CFGR_JAWD1EN | ADC_CFGR_AWD1EN \
                                            | ADC_CFGR_AWD1SGL)                                                         
                                                                                                                    
#define LL_ADC_AWD_CHANNEL_3_REG           ((LL_ADC_CHANNEL_3  & ADC_CHANNEL_ID_MASK) \
                                            | ADC_CFGR_AWD1EN | ADC_CFGR_AWD1SGL)                                       
                                                                                                      
#define LL_ADC_AWD_CHANNEL_3_INJ           ((LL_ADC_CHANNEL_3  & ADC_CHANNEL_ID_MASK) \
                                            | ADC_CFGR_JAWD1EN | ADC_CFGR_AWD1SGL)                                      
                                                                                                       
#define LL_ADC_AWD_CHANNEL_3_REG_INJ       ((LL_ADC_CHANNEL_3  & ADC_CHANNEL_ID_MASK) \
                                            | ADC_CFGR_JAWD1EN | ADC_CFGR_AWD1EN \
                                            | ADC_CFGR_AWD1SGL)                                                         
                                                                                                                    
#define LL_ADC_AWD_CHANNEL_4_REG           ((LL_ADC_CHANNEL_4  & ADC_CHANNEL_ID_MASK) \
                                            | ADC_CFGR_AWD1EN | ADC_CFGR_AWD1SGL)                                       
                                                                                                      
#define LL_ADC_AWD_CHANNEL_4_INJ           ((LL_ADC_CHANNEL_4  & ADC_CHANNEL_ID_MASK) \
                                            | ADC_CFGR_JAWD1EN | ADC_CFGR_AWD1SGL)                                      
                                                                                                       
#define LL_ADC_AWD_CHANNEL_4_REG_INJ       ((LL_ADC_CHANNEL_4  & ADC_CHANNEL_ID_MASK) \
                                            | ADC_CFGR_JAWD1EN | ADC_CFGR_AWD1EN \
                                            | ADC_CFGR_AWD1SGL)                                                         
                                                                                                                    
#define LL_ADC_AWD_CHANNEL_5_REG           ((LL_ADC_CHANNEL_5  & ADC_CHANNEL_ID_MASK) \
                                            | ADC_CFGR_AWD1EN | ADC_CFGR_AWD1SGL)                                       
                                                                                                      
#define LL_ADC_AWD_CHANNEL_5_INJ           ((LL_ADC_CHANNEL_5  & ADC_CHANNEL_ID_MASK) \
                                            | ADC_CFGR_JAWD1EN | ADC_CFGR_AWD1SGL)                                      
                                                                                                       
#define LL_ADC_AWD_CHANNEL_5_REG_INJ       ((LL_ADC_CHANNEL_5  & ADC_CHANNEL_ID_MASK) \
                                            | ADC_CFGR_JAWD1EN | ADC_CFGR_AWD1EN \
                                            | ADC_CFGR_AWD1SGL)                                                         
                                                                                                                    
#define LL_ADC_AWD_CHANNEL_6_REG           ((LL_ADC_CHANNEL_6  & ADC_CHANNEL_ID_MASK) \
                                            | ADC_CFGR_AWD1EN | ADC_CFGR_AWD1SGL)                                       
                                                                                                      
#define LL_ADC_AWD_CHANNEL_6_INJ           ((LL_ADC_CHANNEL_6  & ADC_CHANNEL_ID_MASK) \
                                            | ADC_CFGR_JAWD1EN | ADC_CFGR_AWD1SGL)                                      
                                                                                                       
#define LL_ADC_AWD_CHANNEL_6_REG_INJ       ((LL_ADC_CHANNEL_6  & ADC_CHANNEL_ID_MASK) \
                                            | ADC_CFGR_JAWD1EN | ADC_CFGR_AWD1EN \
                                            | ADC_CFGR_AWD1SGL)                                                         
                                                                                                                    
#define LL_ADC_AWD_CHANNEL_7_REG           ((LL_ADC_CHANNEL_7  & ADC_CHANNEL_ID_MASK) \
                                            | ADC_CFGR_AWD1EN | ADC_CFGR_AWD1SGL)                                       
                                                                                                      
#define LL_ADC_AWD_CHANNEL_7_INJ           ((LL_ADC_CHANNEL_7  & ADC_CHANNEL_ID_MASK) \
                                            | ADC_CFGR_JAWD1EN | ADC_CFGR_AWD1SGL)                                      
                                                                                                       
#define LL_ADC_AWD_CHANNEL_7_REG_INJ       ((LL_ADC_CHANNEL_7  & ADC_CHANNEL_ID_MASK) \
                                            | ADC_CFGR_JAWD1EN | ADC_CFGR_AWD1EN \
                                            | ADC_CFGR_AWD1SGL)                                                         
                                                                                                                    
#define LL_ADC_AWD_CHANNEL_8_REG           ((LL_ADC_CHANNEL_8  & ADC_CHANNEL_ID_MASK) \
                                            | ADC_CFGR_AWD1EN | ADC_CFGR_AWD1SGL)                                       
                                                                                                      
#define LL_ADC_AWD_CHANNEL_8_INJ           ((LL_ADC_CHANNEL_8  & ADC_CHANNEL_ID_MASK) \
                                            | ADC_CFGR_JAWD1EN | ADC_CFGR_AWD1SGL)                                      
                                                                                                       
#define LL_ADC_AWD_CHANNEL_8_REG_INJ       ((LL_ADC_CHANNEL_8  & ADC_CHANNEL_ID_MASK) \
                                            | ADC_CFGR_JAWD1EN | ADC_CFGR_AWD1EN \
                                            | ADC_CFGR_AWD1SGL)                                                         
                                                                                                                    
#define LL_ADC_AWD_CHANNEL_9_REG           ((LL_ADC_CHANNEL_9  & ADC_CHANNEL_ID_MASK) \
                                            | ADC_CFGR_AWD1EN | ADC_CFGR_AWD1SGL)                                       
                                                                                                      
#define LL_ADC_AWD_CHANNEL_9_INJ           ((LL_ADC_CHANNEL_9  & ADC_CHANNEL_ID_MASK) \
                                            | ADC_CFGR_JAWD1EN | ADC_CFGR_AWD1SGL)                                      
                                                                                                       
#define LL_ADC_AWD_CHANNEL_9_REG_INJ       ((LL_ADC_CHANNEL_9  & ADC_CHANNEL_ID_MASK) \
                                            | ADC_CFGR_JAWD1EN | ADC_CFGR_AWD1EN \
                                            | ADC_CFGR_AWD1SGL)                                                         
                                                                                                                    
#define LL_ADC_AWD_CHANNEL_10_REG          ((LL_ADC_CHANNEL_10 & ADC_CHANNEL_ID_MASK) \
                                            | ADC_CFGR_AWD1EN | ADC_CFGR_AWD1SGL)                                       
                                                                                                       
#define LL_ADC_AWD_CHANNEL_10_INJ          ((LL_ADC_CHANNEL_10 & ADC_CHANNEL_ID_MASK) \
                                            | ADC_CFGR_JAWD1EN | ADC_CFGR_AWD1SGL)                                      
                                                                                                        
#define LL_ADC_AWD_CHANNEL_10_REG_INJ      ((LL_ADC_CHANNEL_10 & ADC_CHANNEL_ID_MASK)\
                                            | ADC_CFGR_JAWD1EN | ADC_CFGR_AWD1EN \
                                            | ADC_CFGR_AWD1SGL)                                                         
                                                                                                                     
#define LL_ADC_AWD_CHANNEL_11_REG          ((LL_ADC_CHANNEL_11 & ADC_CHANNEL_ID_MASK) \
                                            | ADC_CFGR_AWD1EN | ADC_CFGR_AWD1SGL)                                       
                                                                                                       
#define LL_ADC_AWD_CHANNEL_11_INJ          ((LL_ADC_CHANNEL_11 & ADC_CHANNEL_ID_MASK) \
                                            | ADC_CFGR_JAWD1EN | ADC_CFGR_AWD1SGL)                                      
                                                                                                        
#define LL_ADC_AWD_CHANNEL_11_REG_INJ      ((LL_ADC_CHANNEL_11 & ADC_CHANNEL_ID_MASK) \
                                            | ADC_CFGR_JAWD1EN | ADC_CFGR_AWD1EN \
                                            | ADC_CFGR_AWD1SGL)                                                         
                                                                                                                     
#define LL_ADC_AWD_CHANNEL_12_REG          ((LL_ADC_CHANNEL_12 & ADC_CHANNEL_ID_MASK) \
                                            | ADC_CFGR_AWD1EN | ADC_CFGR_AWD1SGL)                                       
                                                                                                       
#define LL_ADC_AWD_CHANNEL_12_INJ          ((LL_ADC_CHANNEL_12 & ADC_CHANNEL_ID_MASK) \
                                            | ADC_CFGR_JAWD1EN | ADC_CFGR_AWD1SGL)                                      
                                                                                                        
#define LL_ADC_AWD_CHANNEL_12_REG_INJ      ((LL_ADC_CHANNEL_12 & ADC_CHANNEL_ID_MASK) \
                                            | ADC_CFGR_JAWD1EN | ADC_CFGR_AWD1EN \
                                            | ADC_CFGR_AWD1SGL)                                                         
                                                                                                                     
#define LL_ADC_AWD_CHANNEL_13_REG          ((LL_ADC_CHANNEL_13 & ADC_CHANNEL_ID_MASK) \
                                            | ADC_CFGR_AWD1EN | ADC_CFGR_AWD1SGL)                                       
                                                                                                       
#define LL_ADC_AWD_CHANNEL_13_INJ          ((LL_ADC_CHANNEL_13 & ADC_CHANNEL_ID_MASK) \
                                            | ADC_CFGR_JAWD1EN | ADC_CFGR_AWD1SGL)                                      
                                                                                                        
#define LL_ADC_AWD_CHANNEL_13_REG_INJ      ((LL_ADC_CHANNEL_13 & ADC_CHANNEL_ID_MASK) \
                                            | ADC_CFGR_JAWD1EN | ADC_CFGR_AWD1EN \
                                            | ADC_CFGR_AWD1SGL)                                                         
                                                                                                                     
#define LL_ADC_AWD_CHANNEL_14_REG          ((LL_ADC_CHANNEL_14 & ADC_CHANNEL_ID_MASK) \
                                            | ADC_CFGR_AWD1EN | ADC_CFGR_AWD1SGL)                                       
                                                                                                       
#define LL_ADC_AWD_CHANNEL_14_INJ          ((LL_ADC_CHANNEL_14 & ADC_CHANNEL_ID_MASK) \
                                            | ADC_CFGR_JAWD1EN | ADC_CFGR_AWD1SGL)                                      
                                                                                               
#define LL_ADC_AWD_CHANNEL_14_REG_INJ      ((LL_ADC_CHANNEL_14 & ADC_CHANNEL_ID_MASK) \
                                            | ADC_CFGR_JAWD1EN | ADC_CFGR_AWD1EN \
                                            | ADC_CFGR_AWD1SGL)                                                         
                                                                                                                     
#define LL_ADC_AWD_CHANNEL_15_REG          ((LL_ADC_CHANNEL_15 & ADC_CHANNEL_ID_MASK) \
                                            | ADC_CFGR_AWD1EN | ADC_CFGR_AWD1SGL)                                       
                                                                                                                  
#define LL_ADC_AWD_CHANNEL_15_INJ          ((LL_ADC_CHANNEL_15 & ADC_CHANNEL_ID_MASK) \
                                            | ADC_CFGR_JAWD1EN | ADC_CFGR_AWD1SGL)                                      
                                                                                                        
#define LL_ADC_AWD_CHANNEL_15_REG_INJ      ((LL_ADC_CHANNEL_15 & ADC_CHANNEL_ID_MASK) \
                                            | ADC_CFGR_JAWD1EN | ADC_CFGR_AWD1EN \
                                            | ADC_CFGR_AWD1SGL)                                                         
                                                                                              
                                                                 
#define LL_ADC_AWD_CHANNEL_16_REG          ((LL_ADC_CHANNEL_16 & ADC_CHANNEL_ID_MASK) \
                                            | ADC_CFGR_AWD1EN | ADC_CFGR_AWD1SGL)                                       
                                                                                                       
#define LL_ADC_AWD_CHANNEL_16_INJ          ((LL_ADC_CHANNEL_16 & ADC_CHANNEL_ID_MASK) \
                                            | ADC_CFGR_JAWD1EN | ADC_CFGR_AWD1SGL)                                      
                                                                                                        
#define LL_ADC_AWD_CHANNEL_16_REG_INJ      ((LL_ADC_CHANNEL_16 & ADC_CHANNEL_ID_MASK) \
                                            | ADC_CFGR_JAWD1EN | ADC_CFGR_AWD1EN \
                                            | ADC_CFGR_AWD1SGL)                                                         
                                                                                                                     
#define LL_ADC_AWD_CHANNEL_17_REG          ((LL_ADC_CHANNEL_17 & ADC_CHANNEL_ID_MASK) \
                                            | ADC_CFGR_AWD1EN | ADC_CFGR_AWD1SGL)                                       
                                                                                                       
 #define LL_ADC_AWD_CHANNEL_17_INJ          ((LL_ADC_CHANNEL_17 & ADC_CHANNEL_ID_MASK) \
                                            | ADC_CFGR_JAWD1EN | ADC_CFGR_AWD1SGL)                                      
                                                                                                        
#define LL_ADC_AWD_CHANNEL_17_REG_INJ      ((LL_ADC_CHANNEL_17 & ADC_CHANNEL_ID_MASK) \
                                            | ADC_CFGR_JAWD1EN | ADC_CFGR_AWD1EN \
                                            | ADC_CFGR_AWD1SGL)                                                         
                                                                                                                     
#define LL_ADC_AWD_CHANNEL_18_REG          ((LL_ADC_CHANNEL_18 & ADC_CHANNEL_ID_MASK) \
                                            | ADC_CFGR_AWD1EN | ADC_CFGR_AWD1SGL)                                       
                                                                                                       
 #define LL_ADC_AWD_CHANNEL_18_INJ          ((LL_ADC_CHANNEL_18 & ADC_CHANNEL_ID_MASK) \
                                            | ADC_CFGR_JAWD1EN | ADC_CFGR_AWD1SGL)                                      
                                                                                                        
#define LL_ADC_AWD_CHANNEL_18_REG_INJ      ((LL_ADC_CHANNEL_18 & ADC_CHANNEL_ID_MASK) \
                                            | ADC_CFGR_JAWD1EN | ADC_CFGR_AWD1EN \
                                            | ADC_CFGR_AWD1SGL)                                                         
                                                                                              
                                                                 
#define LL_ADC_AWD_CH_VREFINT_REG          ((LL_ADC_CHANNEL_VREFINT       & ADC_CHANNEL_ID_MASK) \
                                            | ADC_CFGR_AWD1EN | ADC_CFGR_AWD1SGL)                                       
                                                                                                 
                                                                                                
#define LL_ADC_AWD_CH_VREFINT_INJ          ((LL_ADC_CHANNEL_VREFINT       & ADC_CHANNEL_ID_MASK) \
                                            | ADC_CFGR_JAWD1EN | ADC_CFGR_AWD1SGL)                                      
                                                                                                 
                                                                                                 
#define LL_ADC_AWD_CH_VREFINT_REG_INJ      ((LL_ADC_CHANNEL_VREFINT       & ADC_CHANNEL_ID_MASK) \
                                            | ADC_CFGR_JAWD1EN | ADC_CFGR_AWD1EN \
                                            | ADC_CFGR_AWD1SGL)                                                         
                                                                                                 
                                                                                                              
#define LL_ADC_AWD_CH_TEMPSENSOR_REG       ((LL_ADC_CHANNEL_TEMPSENSOR    & ADC_CHANNEL_ID_MASK) \
                                            | ADC_CFGR_AWD1EN | ADC_CFGR_AWD1SGL)                                       
                                                                                                            
                                                                             
#define LL_ADC_AWD_CH_TEMPSENSOR_INJ       ((LL_ADC_CHANNEL_TEMPSENSOR    & ADC_CHANNEL_ID_MASK) \
                                            | ADC_CFGR_JAWD1EN | ADC_CFGR_AWD1SGL)                                      
                                                                                                            
                                                                              
#define LL_ADC_AWD_CH_TEMPSENSOR_REG_INJ   ((LL_ADC_CHANNEL_TEMPSENSOR    & ADC_CHANNEL_ID_MASK) \
                                            | ADC_CFGR_JAWD1EN | ADC_CFGR_AWD1EN \
                                            | ADC_CFGR_AWD1SGL)                                                         
                                                                                                            
                                                                                           
#define LL_ADC_AWD_CH_VBAT_REG             ((LL_ADC_CHANNEL_VBAT          & ADC_CHANNEL_ID_MASK) \
                                            | ADC_CFGR_AWD1EN | ADC_CFGR_AWD1SGL)                                       
                                                                                            
                                                                                                                 
                                                                                                
#define LL_ADC_AWD_CH_VBAT_INJ             ((LL_ADC_CHANNEL_VBAT          & ADC_CHANNEL_ID_MASK) \
                                            | ADC_CFGR_JAWD1EN | ADC_CFGR_AWD1SGL)                                      
                                                                                            
                                                                                                                 
                                                                                                 
#define LL_ADC_AWD_CH_VBAT_REG_INJ         ((LL_ADC_CHANNEL_VBAT          & ADC_CHANNEL_ID_MASK) \
                                            | ADC_CFGR_JAWD1EN | ADC_CFGR_AWD1EN | ADC_CFGR_AWD1SGL)                
                                                                                            
                                                                                                                 
                                                               
#if defined(ADC1) && !defined(ADC2)
#define LL_ADC_AWD_CH_DAC1CH1_REG          ((LL_ADC_CHANNEL_DAC1CH1       & ADC_CHANNEL_ID_MASK) \
                                            | ADC_CFGR_AWD1EN | ADC_CFGR_AWD1SGL)                                       
                                                                                               
                                                                                                       
#define LL_ADC_AWD_CH_DAC1CH1_INJ          ((LL_ADC_CHANNEL_DAC1CH1       & ADC_CHANNEL_ID_MASK) \
                                            | ADC_CFGR_JAWD1EN | ADC_CFGR_AWD1SGL)                                      
                                                                                               
                                                                                                        
#define LL_ADC_AWD_CH_DAC1CH1_REG_INJ      ((LL_ADC_CHANNEL_DAC1CH1       & ADC_CHANNEL_ID_MASK) \
                                            | ADC_CFGR_JAWD1EN | ADC_CFGR_AWD1EN \
                                            | ADC_CFGR_AWD1SGL)                                                         
                                                                                               
                                                                                                                     
#define LL_ADC_AWD_CH_DAC1CH2_REG          ((LL_ADC_CHANNEL_DAC1CH2       & ADC_CHANNEL_ID_MASK) \
                                            | ADC_CFGR_AWD1EN | ADC_CFGR_AWD1SGL)                                       
                                                                                               
                                                                                                       
#define LL_ADC_AWD_CH_DAC1CH2_INJ          ((LL_ADC_CHANNEL_DAC1CH2       & ADC_CHANNEL_ID_MASK) \
                                            | ADC_CFGR_JAWD1EN | ADC_CFGR_AWD1SGL)                                      
                                                                                               
                                                                                                        
#define LL_ADC_AWD_CH_DAC1CH2_REG_INJ      ((LL_ADC_CHANNEL_DAC1CH2       & ADC_CHANNEL_ID_MASK) \
                                            | ADC_CFGR_JAWD1EN | ADC_CFGR_AWD1EN \
                                            | ADC_CFGR_AWD1SGL)                                                         
                                                                                               
                                                                                                                     
#elif defined(ADC2)
#define LL_ADC_AWD_CH_DAC1CH1_ADC2_REG     ((LL_ADC_CHANNEL_DAC1CH1_ADC2  & ADC_CHANNEL_ID_MASK) \
                                            | ADC_CFGR_AWD1EN | ADC_CFGR_AWD1SGL)                                       
                                                                                               
                                                                                                       
#define LL_ADC_AWD_CH_DAC1CH1_ADC2_INJ     ((LL_ADC_CHANNEL_DAC1CH1_ADC2  & ADC_CHANNEL_ID_MASK) \
                                            | ADC_CFGR_JAWD1EN | ADC_CFGR_AWD1SGL)                                      
                                                                                               
                                                                                                        
#define LL_ADC_AWD_CH_DAC1CH1_ADC2_REG_INJ ((LL_ADC_CHANNEL_DAC1CH1_ADC2  & ADC_CHANNEL_ID_MASK) \
                                            | ADC_CFGR_JAWD1EN | ADC_CFGR_AWD1EN \
                                            | ADC_CFGR_AWD1SGL)                                                         
                                                                                               
                                                                                                                     
#define LL_ADC_AWD_CH_DAC1CH2_ADC2_REG     ((LL_ADC_CHANNEL_DAC1CH2_ADC2  & ADC_CHANNEL_ID_MASK) \
                                            | ADC_CFGR_AWD1EN | ADC_CFGR_AWD1SGL)                                       
                                                                                               
                                                                                                       
#define LL_ADC_AWD_CH_DAC1CH2_ADC2_INJ     ((LL_ADC_CHANNEL_DAC1CH2_ADC2  & ADC_CHANNEL_ID_MASK) \
                                            | ADC_CFGR_JAWD1EN | ADC_CFGR_AWD1SGL)                                      
                                                                                               
                                                                                                        
#define LL_ADC_AWD_CH_DAC1CH2_ADC2_REG_INJ ((LL_ADC_CHANNEL_DAC1CH2_ADC2  & ADC_CHANNEL_ID_MASK) \
                                            | ADC_CFGR_JAWD1EN | ADC_CFGR_AWD1EN \
                                            | ADC_CFGR_AWD1SGL)                                                         
                                                                                               
                                                                                                                     
#if defined(ADC3)
#define LL_ADC_AWD_CH_DAC1CH1_ADC3_REG     ((LL_ADC_CHANNEL_DAC1CH1_ADC3  & ADC_CHANNEL_ID_MASK) \
                                            | ADC_CFGR_AWD1EN | ADC_CFGR_AWD1SGL)                                       
                                                                                               
                                                                                                       
#define LL_ADC_AWD_CH_DAC1CH1_ADC3_INJ     ((LL_ADC_CHANNEL_DAC1CH1_ADC3  & ADC_CHANNEL_ID_MASK) \
                                            | ADC_CFGR_JAWD1EN | ADC_CFGR_AWD1SGL)                                      
                                                                                               
                                                                                                        
#define LL_ADC_AWD_CH_DAC1CH1_ADC3_REG_INJ ((LL_ADC_CHANNEL_DAC1CH1_ADC3  & ADC_CHANNEL_ID_MASK) \
                                            | ADC_CFGR_JAWD1EN | ADC_CFGR_AWD1EN \
                                            | ADC_CFGR_AWD1SGL)                                                         
                                                                                               
                                                                                                                     
#define LL_ADC_AWD_CH_DAC1CH2_ADC3_REG     ((LL_ADC_CHANNEL_DAC1CH2_ADC3  & ADC_CHANNEL_ID_MASK) \
                                            | ADC_CFGR_AWD1EN | ADC_CFGR_AWD1SGL)                                       
                                                                                               
                                                                                                       
#define LL_ADC_AWD_CH_DAC1CH2_ADC3_INJ     ((LL_ADC_CHANNEL_DAC1CH2_ADC3  & ADC_CHANNEL_ID_MASK) \
                                            | ADC_CFGR_JAWD1EN | ADC_CFGR_AWD1SGL)                                      
                                                                                               
                                                                                                        
#define LL_ADC_AWD_CH_DAC1CH2_ADC3_REG_INJ ((LL_ADC_CHANNEL_DAC1CH2_ADC3  & ADC_CHANNEL_ID_MASK) \
                                            | ADC_CFGR_JAWD1EN | ADC_CFGR_AWD1EN \
                                            | ADC_CFGR_AWD1SGL)                                                         
                                                                                               
                                                                                                                     
#endif           
#endif                    
   
      
    

                                                                    
      
    
#define LL_ADC_AWD_THRESHOLD_HIGH          (ADC_TR1_HT1)                                                
#define LL_ADC_AWD_THRESHOLD_LOW           (ADC_TR1_LT1)                                               
#define LL_ADC_AWD_THRESHOLDS_HIGH_LOW     (ADC_TR1_HT1 \
                                            | ADC_TR1_LT1)                                                          
                                                                             
   
      
    

                                                                    
      
    
#define LL_ADC_OVS_DISABLE                 (0x00000000UL)                                                        
#define LL_ADC_OVS_GRP_REGULAR_CONTINUED   (ADC_CFGR2_ROVSE)                                                          
                                                                                                         
                                                                                                                      
                                                                                            
#define LL_ADC_OVS_GRP_REGULAR_RESUMED     (ADC_CFGR2_ROVSM | ADC_CFGR2_ROVSE)                                        
                                                                                                         
                                                                                                                      
                                                                                               
#define LL_ADC_OVS_GRP_INJECTED            (ADC_CFGR2_JOVSE)                                                          
                                                                 
#define LL_ADC_OVS_GRP_INJ_REG_RESUMED     (ADC_CFGR2_JOVSE | ADC_CFGR2_ROVSE)                                        
                                                                                                                     
                                                                                                                       
                                                                                                       
   
      
    

                                                                           
      
    
#define LL_ADC_OVS_REG_CONT                (0x00000000UL)                                                              
                                                                  
#define LL_ADC_OVS_REG_DISCONT             (ADC_CFGR2_TROVS)                                                         
                                                                                                          
   
      
    

                                                       
      
    
#define LL_ADC_OVS_RATIO_2                 (0x00000000UL)                                                        
                                                                                                                      
                                                                      
#define LL_ADC_OVS_RATIO_4                 (ADC_CFGR2_OVSR_0)                                                    
                                                                                                                      
                                                                      
#define LL_ADC_OVS_RATIO_8                 (ADC_CFGR2_OVSR_1)                                                    
                                                                                                                      
                                                                      
#define LL_ADC_OVS_RATIO_16                (ADC_CFGR2_OVSR_1 | ADC_CFGR2_OVSR_0)                                  
                                                                                                                      
                                                                      
#define LL_ADC_OVS_RATIO_32                (ADC_CFGR2_OVSR_2)                                                     
                                                                                                                      
                                                                      
#define LL_ADC_OVS_RATIO_64                (ADC_CFGR2_OVSR_2 | ADC_CFGR2_OVSR_0)                                  
                                                                                                                      
                                                                      
#define LL_ADC_OVS_RATIO_128               (ADC_CFGR2_OVSR_2 | ADC_CFGR2_OVSR_1)                                   
                                                                                                                      
                                                                      
#define LL_ADC_OVS_RATIO_256               (ADC_CFGR2_OVSR_2 | ADC_CFGR2_OVSR_1 \
                                            | ADC_CFGR2_OVSR_0)                                                     
                                                                                                                      
                                                                      
   
      
    

                                                                  
      
    
#define LL_ADC_OVS_SHIFT_NONE              (0x00000000UL)                                                      
                                                                                                                    
                                                              
#define LL_ADC_OVS_SHIFT_RIGHT_1           (ADC_CFGR2_OVSS_0)                                                          
                                                                                                             
                                                                                        
#define LL_ADC_OVS_SHIFT_RIGHT_2           (ADC_CFGR2_OVSS_1)                                                          
                                                                                                             
                                                                                        
#define LL_ADC_OVS_SHIFT_RIGHT_3           (ADC_CFGR2_OVSS_1 | ADC_CFGR2_OVSS_0)                                       
                                                                                                             
                                                                                        
#define LL_ADC_OVS_SHIFT_RIGHT_4           (ADC_CFGR2_OVSS_2)                                                          
                                                                                                              
                                                                                        
#define LL_ADC_OVS_SHIFT_RIGHT_5           (ADC_CFGR2_OVSS_2 | ADC_CFGR2_OVSS_0)                                       
                                                                                                              
                                                                                        
#define LL_ADC_OVS_SHIFT_RIGHT_6           (ADC_CFGR2_OVSS_2 | ADC_CFGR2_OVSS_1)                                       
                                                                                                              
                                                                                        
#define LL_ADC_OVS_SHIFT_RIGHT_7           (ADC_CFGR2_OVSS_2 | ADC_CFGR2_OVSS_1 \
                                            | ADC_CFGR2_OVSS_0)                                                         
                                                                                                               
                                                                                        
#define LL_ADC_OVS_SHIFT_RIGHT_8           (ADC_CFGR2_OVSS_3)                                                          
                                                                                                               
                                                                                        
   
      
    

#if defined(ADC_MULTIMODE_SUPPORT)
                                                    
      
    
#define LL_ADC_MULTI_INDEPENDENT           (0x00000000UL)                                                    
                                                               
#define LL_ADC_MULTI_DUAL_REG_SIMULT       (ADC_CCR_DUAL_2 | ADC_CCR_DUAL_1)                                          
                                                          
#define LL_ADC_MULTI_DUAL_REG_INTERL       (ADC_CCR_DUAL_2 | ADC_CCR_DUAL_1 \
                                            | ADC_CCR_DUAL_0)                                                            
                                                                 
#define LL_ADC_MULTI_DUAL_INJ_SIMULT       (ADC_CCR_DUAL_2 | ADC_CCR_DUAL_0)                                           
                                                          
#define LL_ADC_MULTI_DUAL_INJ_ALTERN       (ADC_CCR_DUAL_3 | ADC_CCR_DUAL_0)                                           
                                                                                                                 
#define LL_ADC_MULTI_DUAL_REG_SIM_INJ_SIM  (ADC_CCR_DUAL_0)                                                            
                                                                                                
#define LL_ADC_MULTI_DUAL_REG_SIM_INJ_ALT  (ADC_CCR_DUAL_1)                                                            
                                                                                                     
#define LL_ADC_MULTI_DUAL_REG_INT_INJ_SIM  (ADC_CCR_DUAL_1 | ADC_CCR_DUAL_0)                                           
                                                                                               
   
      
    

                                                                    
      
    
#define LL_ADC_MULTI_REG_DMA_EACH_ADC        (0x00000000UL)                                                    
                                                                                                                   
                                                                                         
#define LL_ADC_MULTI_REG_DMA_LIMIT_RES12_10B (ADC_CCR_MDMA_1)                                                  
                                                                                                                    
                                                                                                                
                                                                                                                      
                                                                                                           
                                                                                                          
#define LL_ADC_MULTI_REG_DMA_LIMIT_RES8_6B   (ADC_CCR_MDMA_1 | ADC_CCR_MDMA_0)                                 
                                                                                                                    
                                                                                                                
                                                                                                                      
                                                                                                           
                                                                                                        
#define LL_ADC_MULTI_REG_DMA_UNLMT_RES12_10B (ADC_CCR_DMACFG | ADC_CCR_MDMA_1)                                 
                                                                                                                    
                                                                                                                 
                                                                                                                 
                                                                                                         
                                                                                            
#define LL_ADC_MULTI_REG_DMA_UNLMT_RES8_6B   (ADC_CCR_DMACFG | ADC_CCR_MDMA_1 \
                                              | ADC_CCR_MDMA_0)                                                 
                                                                                                                     
                                                                                                                 
                                                                                                                 
                                                                                                         
                                                                                          
   
      
    

                                                                                         
      
    
#define LL_ADC_MULTI_TWOSMP_DELAY_1CYCLE   (0x00000000UL)                                                          
                                                                                
#define LL_ADC_MULTI_TWOSMP_DELAY_2CYCLES  (ADC_CCR_DELAY_0)                                                       
                                                                                 
#define LL_ADC_MULTI_TWOSMP_DELAY_3CYCLES  (ADC_CCR_DELAY_1)                                                       
                                                                                 
#define LL_ADC_MULTI_TWOSMP_DELAY_4CYCLES  (ADC_CCR_DELAY_1 | ADC_CCR_DELAY_0)                                     
                                                                                 
#define LL_ADC_MULTI_TWOSMP_DELAY_5CYCLES  (ADC_CCR_DELAY_2)                                                       
                                                                                 
#define LL_ADC_MULTI_TWOSMP_DELAY_6CYCLES  (ADC_CCR_DELAY_2 | ADC_CCR_DELAY_0)                                     
                                                                                 
#define LL_ADC_MULTI_TWOSMP_DELAY_7CYCLES  (ADC_CCR_DELAY_2 | ADC_CCR_DELAY_1)                                     
                                                                                 
#define LL_ADC_MULTI_TWOSMP_DELAY_8CYCLES  (ADC_CCR_DELAY_2 | ADC_CCR_DELAY_1 \
                                            | ADC_CCR_DELAY_0)                                                      
                                                                                 
#define LL_ADC_MULTI_TWOSMP_DELAY_9CYCLES  (ADC_CCR_DELAY_3)                                                       
                                                                                 
#define LL_ADC_MULTI_TWOSMP_DELAY_10CYCLES (ADC_CCR_DELAY_3 | ADC_CCR_DELAY_0)                                     
                                                                                  
#define LL_ADC_MULTI_TWOSMP_DELAY_11CYCLES (ADC_CCR_DELAY_3 | ADC_CCR_DELAY_1)                                     
                                                                                  
#define LL_ADC_MULTI_TWOSMP_DELAY_12CYCLES (ADC_CCR_DELAY_3 | ADC_CCR_DELAY_1 \
                                            | ADC_CCR_DELAY_0)                                                      
                                                                                  
   
      
    

                                                                           
      
    
#define LL_ADC_MULTI_MASTER                (ADC_CDR_RDATA_MST)                                               
                                                                   
#define LL_ADC_MULTI_SLAVE                 (ADC_CDR_RDATA_SLV)                                               
                                                                  
#define LL_ADC_MULTI_MASTER_SLAVE          (ADC_CDR_RDATA_SLV \
                                            | ADC_CDR_RDATA_MST)                                               
                                                                                      
   
      
    

#endif                            

                                                         
      
    
#define LL_ADC_REG_TRIG_SW_START           (LL_ADC_REG_TRIG_SOFTWARE)
#define LL_ADC_REG_TRIG_EXT_TIM1_CC1       (LL_ADC_REG_TRIG_EXT_TIM1_CH1)
#define LL_ADC_REG_TRIG_EXT_TIM1_CC2       (LL_ADC_REG_TRIG_EXT_TIM1_CH2)
#define LL_ADC_REG_TRIG_EXT_TIM1_CC3       (LL_ADC_REG_TRIG_EXT_TIM1_CH3)
#define LL_ADC_REG_TRIG_EXT_TIM2_CC2       (LL_ADC_REG_TRIG_EXT_TIM2_CH2)
#define LL_ADC_REG_TRIG_EXT_TIM3_CC4       (LL_ADC_REG_TRIG_EXT_TIM3_CH4)
#define LL_ADC_REG_TRIG_EXT_TIM4_CC4       (LL_ADC_REG_TRIG_EXT_TIM4_CH4)

#define LL_ADC_INJ_TRIG_SW_START           (LL_ADC_INJ_TRIG_SOFTWARE)
#define LL_ADC_INJ_TRIG_EXT_TIM1_CC4       (LL_ADC_INJ_TRIG_EXT_TIM1_CH4)
#define LL_ADC_INJ_TRIG_EXT_TIM2_CC1       (LL_ADC_INJ_TRIG_EXT_TIM2_CH1)
#define LL_ADC_INJ_TRIG_EXT_TIM3_CC1       (LL_ADC_INJ_TRIG_EXT_TIM3_CH1)
#define LL_ADC_INJ_TRIG_EXT_TIM3_CC3       (LL_ADC_INJ_TRIG_EXT_TIM3_CH3)
#define LL_ADC_INJ_TRIG_EXT_TIM3_CC4       (LL_ADC_INJ_TRIG_EXT_TIM3_CH4)
#define LL_ADC_INJ_TRIG_EXT_TIM8_CC4       (LL_ADC_INJ_TRIG_EXT_TIM8_CH4)

#define LL_ADC_OVS_DATA_SHIFT_NONE         (LL_ADC_OVS_SHIFT_NONE)
#define LL_ADC_OVS_DATA_SHIFT_1            (LL_ADC_OVS_SHIFT_RIGHT_1)
#define LL_ADC_OVS_DATA_SHIFT_2            (LL_ADC_OVS_SHIFT_RIGHT_2)
#define LL_ADC_OVS_DATA_SHIFT_3            (LL_ADC_OVS_SHIFT_RIGHT_3)
#define LL_ADC_OVS_DATA_SHIFT_4            (LL_ADC_OVS_SHIFT_RIGHT_4)
#define LL_ADC_OVS_DATA_SHIFT_5            (LL_ADC_OVS_SHIFT_RIGHT_5)
#define LL_ADC_OVS_DATA_SHIFT_6            (LL_ADC_OVS_SHIFT_RIGHT_6)
#define LL_ADC_OVS_DATA_SHIFT_7            (LL_ADC_OVS_SHIFT_RIGHT_7)
#define LL_ADC_OVS_DATA_SHIFT_8            (LL_ADC_OVS_SHIFT_RIGHT_8)

   
      
    

                                                                                   
      
    
#define LL_ADC_TEMPERATURE_CALC_ERROR      ((int16_t)0x7FFF)                                                     
                                                                                                                  
                                                                                                                       
                                                                                                                       
                                                                                                         
   
      
    

                                                                                 
                                                                              
                               
                                                                              
                                          
      
    

                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                

                                                                                
                                                                                
                                                                                
                                                                                
#define LL_ADC_DELAY_INTERNAL_REGUL_STAB_US ( 20UL)                                                             
                                                                                         

                                                                                
                                                                                
                                                                                
                                                                                
#define LL_ADC_DELAY_VREFINT_STAB_US           ( 12UL)                                                               
                                                                          

                                                                                
                                                                                
                                                                                
                                                                                
#define LL_ADC_DELAY_TEMPSENSOR_STAB_US        (120UL)                                                               
#define LL_ADC_DELAY_TEMPSENSOR_BUFFER_STAB_US ( 15UL)                                                              
                                                                                                           
                                                                                           

                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
#define LL_ADC_DELAY_CALIB_ENABLE_ADC_CYCLES   (  4UL)                                                          
                                                                                    

   
      
    

   
      
    


                                                                                
                                                        
      
    

                                                                         
      
    

   
                                         
                                     
                                          
                                                         
                
    
#define LL_ADC_WriteReg(__INSTANCE__, __REG__, __VALUE__) WRITE_REG(__INSTANCE__->__REG__, (__VALUE__))

   
                                        
                                     
                                       
                          
    
#define LL_ADC_ReadReg(__INSTANCE__, __REG__) READ_REG(__INSTANCE__->__REG__)
   
      
    

                                                     
      
    

   
                                                                    
                                           
                    
                                                              
                                             
                                                                   
                                                          
                                                        
                                                                          
                                      
                                                     
                                                     
                                                     
                                                     
                                                     
                                      
                                      
                                      
                                      
                                       
                                       
                                       
                                       
                                       
                                       
                                       
                                       
                                       
                                                     
                                                     
                                                     
                                                        
                                                        
                                                        
                                                        
                                                        
                                                        
   
                                                                             
                                                                             
                                                                             
                                                                                    
                                                                                      
                                                                                        
                                                                                                                
                                                                                                                        
                                                    
    
#define __LL_ADC_CHANNEL_TO_DECIMAL_NB(__CHANNEL__)                                        \
  ((((__CHANNEL__) & ADC_CHANNEL_ID_BITFIELD_MASK) == 0UL) ?                               \
   (                                                                                       \
       ((__CHANNEL__) & ADC_CHANNEL_ID_NUMBER_MASK) >> ADC_CHANNEL_ID_NUMBER_BITOFFSET_POS \
   )                                                                                       \
   :                                                                                       \
   (                                                                                       \
       (uint32_t)POSITION_VAL((__CHANNEL__))                                               \
   )                                                                                       \
  )

   
                                                                              
                                          
                    
                                               
                                                                  
                                                                   
                                                              
                                      
                                                     
                                                     
                                                     
                                                     
                                                     
                                      
                                      
                                      
                                      
                                       
                                       
                                       
                                       
                                       
                                       
                                       
                                       
                                       
                                                     
                                                     
                                                     
                                                        
                                                        
                                                        
                                                        
                                                        
                                                        
   
                                                                             
                                                                             
                                                                             
                                                                                    
                                                                                      
                                                                                        
                                                                                                                
                                                                                                           
                              
                                                                     
                                                                              
                                                                                         
    
#define __LL_ADC_DECIMAL_NB_TO_CHANNEL(__DECIMAL_NB__)                                                  \
  (((__DECIMAL_NB__) <= 9UL) ?                                                                          \
   (                                                                                                    \
       ((__DECIMAL_NB__) << ADC_CHANNEL_ID_NUMBER_BITOFFSET_POS)                             |          \
       (ADC_AWD2CR_AWD2CH_0 << (__DECIMAL_NB__))                                              |          \
       (ADC_SMPR1_REGOFFSET | (((3UL * (__DECIMAL_NB__))) << ADC_CHANNEL_SMPx_BITOFFSET_POS))           \
   )                                                                                                    \
   :                                                                                                    \
   (                                                                                                    \
       ((__DECIMAL_NB__) << ADC_CHANNEL_ID_NUMBER_BITOFFSET_POS)                                      | \
       (ADC_AWD2CR_AWD2CH_0 << (__DECIMAL_NB__))                                                       | \
       (ADC_SMPR2_REGOFFSET | (((3UL * ((__DECIMAL_NB__) - 10UL))) << ADC_CHANNEL_SMPx_BITOFFSET_POS))  \
   )                                                                                                    \
  )

   
                                                                  
                                                         
                                                                  
                                   
                                                                    
                                                                     
                                                     
                                                                      
                                                                         
                                            
                                                                           
                                                                        
                                        
                                                                         
                                                                          
                                             
                                                                          
                                      
                                                     
                                                     
                                                     
                                                     
                                                     
                                      
                                      
                                      
                                      
                                       
                                       
                                       
                                       
                                       
                                       
                                       
                                       
                                       
                                                     
                                                     
                                                     
                                                        
                                                        
                                                        
                                                        
                                                        
                                                        
   
                                                                             
                                                                             
                                                                             
                                                                                    
                                                                                      
                                                                                        
                                                                                                                
                                                                                                                        
                                                                                                             
                                               
                                                                                                     
    
#define __LL_ADC_IS_CHANNEL_INTERNAL(__CHANNEL__)                              \
  (((__CHANNEL__) & ADC_CHANNEL_ID_INTERNAL_CH_MASK) != 0UL)

   
                                                                    
                                                                         
                                            
                                                                            
                                                      
                                                                 
                                                                       
                                                                     
                                                        
                                                                          
                                                                        
                               
                                                                          
                                      
                                                     
                                                     
                                                     
                                                     
                                                     
                                      
                                      
                                      
                                      
                                       
                                       
                                       
                                       
                                       
                                       
                                       
                                       
                                       
                                                     
                                                     
                                                     
                                                        
                                                        
                                                        
                                                        
                                                        
                                                        
   
                                                                             
                                                                             
                                                                             
                                                                                    
                                                                                      
                                                                                        
                                                                                                                
                                                                                                                        
                                                              
                                      
                                      
                                      
                                      
                                      
                                      
                                      
                                      
                                      
                                      
                                       
                                       
                                       
                                       
                                       
                                       
                                       
                                       
                                       
    
#define __LL_ADC_CHANNEL_INTERNAL_TO_EXTERNAL(__CHANNEL__)                     \
  ((__CHANNEL__) & ~ADC_CHANNEL_ID_INTERNAL_CH_MASK)

   
                                                                  
                                                               
                                                                        
                                                                         
                                            
                                                                    
                                                                          
                                                               
                                        
                                                                         
                                                                          
                                             
                                         
                                                                          
                                                     
                                                     
                                                     
                                                        
                                                        
                                                        
                                                        
                                                        
                                                        
   
                                                                             
                                                                             
                                                                             
                                                                                    
                                                                                      
                                                                                      
                                                                                                     
                                                                                                 
    
#if defined (ADC1) && defined (ADC2) && defined (ADC3)
#define __LL_ADC_IS_CHANNEL_INTERNAL_AVAILABLE(__ADC_INSTANCE__, __CHANNEL__)  \
  (((__ADC_INSTANCE__) == ADC1) ?                                              \
   (                                                                           \
    ((__CHANNEL__) == LL_ADC_CHANNEL_VREFINT)    ||                            \
    ((__CHANNEL__) == LL_ADC_CHANNEL_TEMPSENSOR) ||                            \
    ((__CHANNEL__) == LL_ADC_CHANNEL_VBAT)                                     \
   )                                                                           \
   :                                                                           \
   ((__ADC_INSTANCE__) == ADC2) ?                                              \
    (                                                                          \
     ((__CHANNEL__) == LL_ADC_CHANNEL_VREFINT)      ||                         \
     ((__CHANNEL__) == LL_ADC_CHANNEL_DAC1CH1_ADC2) ||                         \
     ((__CHANNEL__) == LL_ADC_CHANNEL_DAC1CH2_ADC2)                            \
    )                                                                          \
    :                                                                          \
    ((__ADC_INSTANCE__) == ADC3) ?                                             \
     (                                                                         \
      ((__CHANNEL__) == LL_ADC_CHANNEL_VREFINT)      ||                        \
      ((__CHANNEL__) == LL_ADC_CHANNEL_TEMPSENSOR)   ||                        \
      ((__CHANNEL__) == LL_ADC_CHANNEL_VBAT)         ||                        \
      ((__CHANNEL__) == LL_ADC_CHANNEL_DAC1CH1_ADC3) ||                        \
      ((__CHANNEL__) == LL_ADC_CHANNEL_DAC1CH2_ADC3)                           \
     )                                                                         \
     :                                                                         \
     (0UL)                                                                     \
  )
#elif defined (ADC1) && defined (ADC2)
#define __LL_ADC_IS_CHANNEL_INTERNAL_AVAILABLE(__ADC_INSTANCE__, __CHANNEL__)  \
  (((__ADC_INSTANCE__) == ADC1) ?                                              \
   (                                                                           \
    ((__CHANNEL__) == LL_ADC_CHANNEL_VREFINT)    ||                            \
    ((__CHANNEL__) == LL_ADC_CHANNEL_TEMPSENSOR) ||                            \
    ((__CHANNEL__) == LL_ADC_CHANNEL_VBAT)                                     \
   )                                                                           \
   :                                                                           \
   ((__ADC_INSTANCE__) == ADC2) ?                                              \
    (                                                                          \
     ((__CHANNEL__) == LL_ADC_CHANNEL_VREFINT)      ||                         \
     ((__CHANNEL__) == LL_ADC_CHANNEL_DAC1CH1_ADC2) ||                         \
     ((__CHANNEL__) == LL_ADC_CHANNEL_DAC1CH2_ADC2)                            \
    )                                                                          \
    :                                                                          \
    (0UL)                                                                      \
  )
#elif defined (ADC1)
#define __LL_ADC_IS_CHANNEL_INTERNAL_AVAILABLE(__ADC_INSTANCE__, __CHANNEL__)  \
  (                                                                            \
    ((__CHANNEL__) == LL_ADC_CHANNEL_VREFINT)    ||                            \
    ((__CHANNEL__) == LL_ADC_CHANNEL_TEMPSENSOR) ||                            \
    ((__CHANNEL__) == LL_ADC_CHANNEL_VBAT)       ||                            \
    ((__CHANNEL__) == LL_ADC_CHANNEL_DAC1CH1)    ||                            \
    ((__CHANNEL__) == LL_ADC_CHANNEL_DAC1CH2)                                  \
  )
#endif                                                         

   
                                                                 
                                                                   
                                                         
                                                                            
                    
                                              
                                  
                                                                                       
                                                                          
                                      
                                                     
                                                     
                                                     
                                                     
                                                     
                                      
                                      
                                      
                                      
                                       
                                       
                                       
                                       
                                       
                                       
                                       
                                       
                                       
                                                     
                                                     
                                                     
                                                        
                                                        
                                                        
                                                        
                                                        
                                                        
   
                                                                             
                                                                             
                                                                             
                                                                                    
                                                                                      
                                                                                        
                                                                                                                
                                                                                                           
                              
                                                                     
                                                                              
                                                                                         
                                                                        
                                          
                                           
                                                   
                                                              
                                        
                                                            
                                                            
                                                     
                                                            
                                                            
                                                  
                                                            
                                                            
                                                  
                                                            
                                                            
                                                  
                                                            
                                                            
                                                  
                                                            
                                                            
                                                  
                                                            
                                                            
                                                  
                                                            
                                                            
                                                  
                                                            
                                                            
                                                  
                                                            
                                                            
                                                  
                                                            
                                                            
                                                  
                                                            
                                                            
                                                   
                                                            
                                                            
                                                   
                                                            
                                                            
                                                   
                                                            
                                                            
                                                   
                                                            
                                                            
                                                   
                                                            
                                                            
                                                   
                                                            
                                                            
                                                   
                                                            
                                                            
                                                   
                                                            
                                                            
                                                   
                                                               
                                                               
                                                               
                                                               
                                                               
                                                               
                                                               
                                                               
                                                               
                                                                  
                                                                  
                                                                  
                                                                  
                                                                  
                                                                  
                                                                  
                                                                  
                                                                  
                                                                  
                                                                  
                                                                  
                                                                  
                                                                  
                                                                  
                                                                  
                                                                  
                                                                  
   
                                                                                       
                                                                             
                                                                             
                                                                             
                                                                                  
                                                                                      
                                                                                      
    
#define __LL_ADC_ANALOGWD_CHANNEL_GROUP(__CHANNEL__, __GROUP__)                                           \
  (((__GROUP__) == LL_ADC_GROUP_REGULAR)                                                                  \
   ? (((__CHANNEL__) & ADC_CHANNEL_ID_MASK) | ADC_CFGR_AWD1EN | ADC_CFGR_AWD1SGL)                         \
   :                                                                                                      \
   ((__GROUP__) == LL_ADC_GROUP_INJECTED)                                                                 \
   ? (((__CHANNEL__) & ADC_CHANNEL_ID_MASK) | ADC_CFGR_JAWD1EN | ADC_CFGR_AWD1SGL)                        \
   :                                                                                                      \
   (((__CHANNEL__) & ADC_CHANNEL_ID_MASK) | ADC_CFGR_JAWD1EN | ADC_CFGR_AWD1EN | ADC_CFGR_AWD1SGL)        \
  )

   
                                                                               
                                                                        
                                 
                                                                           
                                                   
                                                                         
                                                       
                                          
                               
                                                                                                          
                 
                                                                                 
                                           
                                           
                                          
                                          
                                                                             
                                                           
    
#define __LL_ADC_ANALOGWD_SET_THRESHOLD_RESOLUTION(__ADC_RESOLUTION__, __AWD_THRESHOLD__) \
  ((__AWD_THRESHOLD__) << ((__ADC_RESOLUTION__) >> (ADC_CFGR_RES_BITOFFSET_POS - 1U )))

   
                                                                               
                                                                        
                                 
                                                                         
                                                                         
                                                       
                                                                                     
                                     
                                                                                     
                 
                                                                                 
                                           
                                           
                                          
                                          
                                                                                     
                                                           
    
#define __LL_ADC_ANALOGWD_GET_THRESHOLD_RESOLUTION(__ADC_RESOLUTION__, __AWD_THRESHOLD_12_BITS__) \
  ((__AWD_THRESHOLD_12_BITS__) >> ((__ADC_RESOLUTION__) >> (ADC_CFGR_RES_BITOFFSET_POS - 1U )))

   
                                                                      
                                                                          
                                                                         
                                                                                       
                                                                                                                 
                                                                                     
                                               
                                              
                                                                                        
                                                           
    
#define __LL_ADC_ANALOGWD_THRESHOLDS_HIGH_LOW(__AWD_THRESHOLD_TYPE__, __AWD_THRESHOLDS__)                            \
  (((__AWD_THRESHOLDS__) >> (((__AWD_THRESHOLD_TYPE__) & ADC_AWD_TRX_BIT_HIGH_MASK) >> ADC_AWD_TRX_BIT_HIGH_SHIFT4)) \
   & LL_ADC_AWD_THRESHOLD_LOW)

   
                                                                                
                                                                    
                                                                        
                                                                    
                                           
                                          
                     
                                                              
                                                                                       
                                                                                       
                                                                     
    
#define __LL_ADC_CALIB_FACTOR_SINGLE_DIFF(__CALIB_FACTOR_SINGLE_ENDED__, __CALIB_FACTOR_DIFFERENTIAL__)        \
  (((__CALIB_FACTOR_DIFFERENTIAL__) << ADC_CALFACT_CALFACT_D_Pos) | (__CALIB_FACTOR_SINGLE_ENDED__))

#if defined(ADC_MULTIMODE_SUPPORT)
   
                                                                               
                                                                                   
                                                                            
                                                                            
                                                                               
                                                                        
                                                                                         
                                         
                                        
                                                                                   
                                                           
    
#define __LL_ADC_MULTI_CONV_DATA_MASTER_SLAVE(__ADC_MULTI_MASTER_SLAVE__, __ADC_MULTI_CONV_DATA__) \
  (((__ADC_MULTI_CONV_DATA__) >> ((ADC_CDR_RDATA_SLV_Pos) & ~(__ADC_MULTI_MASTER_SLAVE__))) & ADC_CDR_RDATA_MST)
#endif                            

#if defined(ADC_MULTIMODE_SUPPORT)
   
                                                                              
                                                                             
                                 
                                                                   
                                                                             
                                                                  
                                                            
                                    
                                 
                                                                                 
    
#if defined(ADC2)
#define __LL_ADC_MULTI_INSTANCE_MASTER(__ADCx__) \
  ((((__ADCx__) == ADC2))?                                                   \
   (ADC1)                                                                    \
   :                                                                         \
   (__ADCx__)                                                                \
  )
#else
#define __LL_ADC_MULTI_INSTANCE_MASTER(__ADCx__) \
  (__ADCx__)
#endif           
#endif                            

   
                                                          
                                                            
                                                         
                                                            
                                                                
                                                                           
                                 
                                        
    
#if defined(ADC1) && defined(ADC2) && defined(ADC3)
#define __LL_ADC_COMMON_INSTANCE(__ADCx__)                                     \
  (ADC123_COMMON)
#elif defined(ADC1) && defined(ADC2)
#define __LL_ADC_COMMON_INSTANCE(__ADCx__)                                     \
  (ADC12_COMMON)
#else
#define __LL_ADC_COMMON_INSTANCE(__ADCx__)                                     \
  (ADC1_COMMON)
#endif                                                      

   
                                                                       
                                             
                                                                           
                      
                                                                       
                                                                           
                                                                               
                                                                           
                                                                 
                                                
                                                                                                                 
                                                                               
                         
                                                                                       
                       
    
#if defined(ADC1) && defined(ADC2) && defined(ADC3)
#define __LL_ADC_IS_ENABLED_ALL_COMMON_INSTANCE(__ADCXY_COMMON__)              \
  (LL_ADC_IsEnabled(ADC1) |                                                    \
   LL_ADC_IsEnabled(ADC2) |                                                    \
   LL_ADC_IsEnabled(ADC3)  )
#elif defined(ADC1) && defined(ADC2)
#define __LL_ADC_IS_ENABLED_ALL_COMMON_INSTANCE(__ADCXY_COMMON__)              \
  (LL_ADC_IsEnabled(ADC1) |                                                    \
   LL_ADC_IsEnabled(ADC2)  )
#else
#define __LL_ADC_IS_ENABLED_ALL_COMMON_INSTANCE(__ADCXY_COMMON__)              \
  (LL_ADC_IsEnabled(ADC1))
#endif                                                      

   
                                                                             
                                                               
                                                                       
                                                                   
                                        
                                                                                 
                                           
                                           
                                          
                                          
                                                                                                     
    
#define __LL_ADC_DIGITAL_SCALE(__ADC_RESOLUTION__)                             \
  (0xFFFUL >> ((__ADC_RESOLUTION__) >> (ADC_CFGR_RES_BITOFFSET_POS - 1UL)))

   
                                                                
                                               
                                                        
                                                                             
                                                              
                                           
                                           
                                          
                                          
                                                                             
                                                              
                                           
                                           
                                          
                                          
                                                           
    
#define __LL_ADC_CONVERT_DATA_RESOLUTION(__DATA__,\
                                         __ADC_RESOLUTION_CURRENT__,\
                                         __ADC_RESOLUTION_TARGET__)          \
(((__DATA__)                                                                 \
  << ((__ADC_RESOLUTION_CURRENT__) >> (ADC_CFGR_RES_BITOFFSET_POS - 1UL)))   \
 >> ((__ADC_RESOLUTION_TARGET__) >> (ADC_CFGR_RES_BITOFFSET_POS - 1UL))      \
)

   
                                                               
                                                                         
                                                                      
                                                                             
                                                                         
                                                                      
                                                                 
                                                
                                                                                 
                                           
                                           
                                          
                                          
                                                                      
    
#define __LL_ADC_CALC_DATA_TO_VOLTAGE(__VREFANALOG_VOLTAGE__,\
                                      __ADC_DATA__,\
                                      __ADC_RESOLUTION__)                    \
((__ADC_DATA__) * (__VREFANALOG_VOLTAGE__)                                   \
 / __LL_ADC_DIGITAL_SCALE(__ADC_RESOLUTION__)                                \
)

                   
#define __LL_ADC_CALC_DATA_VOLTAGE()  __LL_ADC_CALC_DATA_TO_VOLTAGE()

   
                                                                      
                                                                      
                              
                                                          
                                                                      
                                                                         
                                   
                                                                       
                                              
                                                                                
                                                           
                                                                        
                                               
                                                                  
                                           
                                                                         
                                                                        
                                                                                 
                                           
                                           
                                          
                                          
                                               
    
#define __LL_ADC_CALC_VREFANALOG_VOLTAGE(__VREFINT_ADC_DATA__,\
                                         __ADC_RESOLUTION__)                 \
(((uint32_t)(*VREFINT_CAL_ADDR) * VREFINT_CAL_VREF)                          \
 / __LL_ADC_CONVERT_DATA_RESOLUTION((__VREFINT_ADC_DATA__),                  \
                                    (__ADC_RESOLUTION__),                    \
                                    LL_ADC_RESOLUTION_12B)                   \
)

   
                                                                            
                                                                    
                                                                      
                                                                      
                                
                                                    
                                                              
                                                                
                                                                            
                                                  
                                                              
                                                                    
                                                                     
                                                                    
                                                                     
                                                                         
                                                               
                                                                      
                                                                             
                                                           
                                                                                  
                                                                              
                                                                 
                                                                      
                                                                             
                                                                         
                                                                        
                                                   
                                                                        
                               
                                                                  
                                           
                                                                       
                                                                   
                                                                             
                                                                                
                                                                     
                                                              
                                           
                                           
                                          
                                          
                                              
                                                                                                              
    
#define __LL_ADC_CALC_TEMPERATURE(__VREFANALOG_VOLTAGE__,\
                                  __TEMPSENSOR_ADC_DATA__,\
                                  __ADC_RESOLUTION__)\
((((int32_t)*TEMPSENSOR_CAL2_ADDR - (int32_t)*TEMPSENSOR_CAL1_ADDR) != 0) ?       \
 (((( ((int32_t)((__LL_ADC_CONVERT_DATA_RESOLUTION((__TEMPSENSOR_ADC_DATA__),     \
                                                   (__ADC_RESOLUTION__),          \
                                                   LL_ADC_RESOLUTION_12B)         \
                  * (__VREFANALOG_VOLTAGE__))                                     \
                 / TEMPSENSOR_CAL_VREFANALOG)                                     \
       - (int32_t) *TEMPSENSOR_CAL1_ADDR)                                         \
    ) * (int32_t)(TEMPSENSOR_CAL2_TEMP - TEMPSENSOR_CAL1_TEMP)                    \
   ) / (int32_t)((int32_t)*TEMPSENSOR_CAL2_ADDR - (int32_t)*TEMPSENSOR_CAL1_ADDR) \
  ) + TEMPSENSOR_CAL1_TEMP                                                        \
 )                                                                                \
 :                                                                                \
 ((int32_t)LL_ADC_TEMPERATURE_CALC_ERROR)                                         \
)

   
                                                                            
                                                                    
                                                                  
                                        
                                
                                                                                
                                                   
                                                                                 
                                                           
                                                              
                                                               
                                                                         
                                                                      
                                                                               
                                                                           
                                              
                                                                              
                                                                                    
                                                                        
                                                                   
                                                                              
                                                                 
                                                                      
                                                                             
                                                                         
                                                                           
                                                                              
                                                                          
                                                                                                       
                                                                
                                                                                                      
                                                                                                         
                                                                                                            
                                                                                                                    
                                                                                                                
                                                                                           
                                                                                           
                                                                                                                   
                                                                                                                        
                                                              
                                           
                                           
                                          
                                          
                                              
    
#define __LL_ADC_CALC_TEMPERATURE_TYP_PARAMS(__TEMPSENSOR_TYP_AVGSLOPE__,\
                                             __TEMPSENSOR_TYP_CALX_V__,\
                                             __TEMPSENSOR_CALX_TEMP__,\
                                             __VREFANALOG_VOLTAGE__,\
                                             __TEMPSENSOR_ADC_DATA__,\
                                             __ADC_RESOLUTION__)            \
(((((int32_t)((((__TEMPSENSOR_ADC_DATA__) * (__VREFANALOG_VOLTAGE__))       \
               / __LL_ADC_DIGITAL_SCALE(__ADC_RESOLUTION__))                \
              * 1000UL)                                                     \
    -                                                                       \
    (int32_t)(((__TEMPSENSOR_TYP_CALX_V__))                                 \
              * 1000UL)                                                     \
   )                                                                        \
  ) / (int32_t)(__TEMPSENSOR_TYP_AVGSLOPE__)                                \
 ) + (int32_t)(__TEMPSENSOR_CALX_TEMP__)                                    \
)

   
      
    

   
      
    


                                                                                
                                                              
      
    

                                                         
      
    
                                                                                
                                                                                
                                                                                

   
                                                                             
                                                                              
                                                                  
                                                   
                                                                        
                                                 
                                                                          
                                                
                    
                                          
                                                      
                                                                                              
                                                                      
                                                                        
                                                                    
                                                                       
                                                                                
                                                         
                                                           
                                                           
                                                         
                             
                                                                       
                                                 
                                                           
   
                                                                
                                
    
#if defined(ADC_MULTIMODE_SUPPORT)
__STATIC_INLINE uint32_t LL_ADC_DMA_GetRegAddr(const ADC_TypeDef *ADCx, uint32_t Register)
{
  uint32_t data_reg_addr;

  if (Register == LL_ADC_DMA_REG_REGULAR_DATA)
  {
                                         
    data_reg_addr = (uint32_t) &(ADCx->DR);
  }
  else                                                      
  {
                                          
    data_reg_addr = (uint32_t) &((__LL_ADC_COMMON_INSTANCE(ADCx))->CDR);
  }

  return data_reg_addr;
}
#else
__STATIC_INLINE uint32_t LL_ADC_DMA_GetRegAddr(const ADC_TypeDef *ADCx, uint32_t Register)
{
                                                      
  (void)(Register);

                                       
  return (uint32_t) &(ADCx->DR);
}
#endif                            

   
      
    

                                                                                                           
                           
      
    

   
                                                                            
                                                                     
                                                                   
                              
                                      
                                                                           
                      
                                                                       
                                                                                 
                                                              
                                                           
                                                           
                                                         
                                            
                                                                                                                 
                                                                          
                                                 
                                                 
                                                 
                                             
                                             
                                             
                                             
                                             
                                              
                                              
                                              
                                              
                                              
                                               
                                               
                
    
__STATIC_INLINE void LL_ADC_SetCommonClock(ADC_Common_TypeDef *ADCxy_COMMON, uint32_t CommonClock)
{
  MODIFY_REG(ADCxy_COMMON->CCR, ADC_CCR_CKMODE | ADC_CCR_PRESC, CommonClock);
}

   
                                                                            
                                                           
                                                         
                                            
                                                                                                                 
                                                              
                                                 
                                                 
                                                 
                                             
                                             
                                             
                                             
                                             
                                              
                                              
                                              
                                              
                                              
                                               
                                               
    
__STATIC_INLINE uint32_t LL_ADC_GetCommonClock(const ADC_Common_TypeDef *ADCxy_COMMON)
{
  return (uint32_t)(READ_BIT(ADCxy_COMMON->CCR, ADC_CCR_CKMODE | ADC_CCR_PRESC));
}

   
                                                                    
                                                                 
                                                                  
                                                  
                                                    
                                                      
                                                                   
                                                                       
                                                                          
                                                                  
                                                  
                                      
                                                               
                                                                   
                                                        
                                                          
                                                    
                                                      
                                      
                                                                    
                                                                    
                                                                  
                                            
                                                                                                                 
                                                                                     
                                               
                                                  
                                                     
                                               
                
    
__STATIC_INLINE void LL_ADC_SetCommonPathInternalCh(ADC_Common_TypeDef *ADCxy_COMMON, uint32_t PathInternal)
{
  MODIFY_REG(ADCxy_COMMON->CCR, ADC_CCR_VREFEN | ADC_CCR_TSEN | ADC_CCR_VBATEN, PathInternal);
}

   
                                                                    
                                                                 
                                                   
                                                  
                                                    
                                                      
                                                                       
                                                                          
                                                                  
                                                  
                                      
                                                               
                                                                   
                                                        
                                                          
                                                    
                                                      
                                      
                                                                       
                                                                       
                                                                     
                                            
                                                                                                                 
                                                                                     
                                               
                                                  
                                                     
                                               
                
    
__STATIC_INLINE void LL_ADC_SetCommonPathInternalChAdd(ADC_Common_TypeDef *ADCxy_COMMON, uint32_t PathInternal)
{
  SET_BIT(ADCxy_COMMON->CCR, PathInternal);
}

   
                                                                    
                                                                 
                                                      
                                                  
                                                    
                                                      
                                                                       
                                                                       
                                                                     
                                            
                                                                                                                 
                                                                                     
                                               
                                                  
                                                     
                                               
                
    
__STATIC_INLINE void LL_ADC_SetCommonPathInternalChRem(ADC_Common_TypeDef *ADCxy_COMMON, uint32_t PathInternal)
{
  CLEAR_BIT(ADCxy_COMMON->CCR, PathInternal);
}

   
                                                                             
                                                        
                                                  
                                                    
                                                      
                                                                    
                                                                    
                                                                  
                                            
                                                                                                                 
                                                                        
                                               
                                                  
                                                     
                                               
    
__STATIC_INLINE uint32_t LL_ADC_GetCommonPathInternalCh(const ADC_Common_TypeDef *ADCxy_COMMON)
{
  return (uint32_t)(READ_BIT(ADCxy_COMMON->CCR, ADC_CCR_VREFEN | ADC_CCR_TSEN | ADC_CCR_VBATEN));
}

   
      
    

                                                                                                        
      
    

   
                                                               
                                                                           
                                                                   
                                                             
                                           
                                                         
                                                        
                                               
                                                                   
                                                                         
                                        
                                                                             
                                                                       
                                                          
                                                        
                                                     
                                                                           
                      
                                                                                 
                                      
                                                                 
                                                               
                             
                                                                         
                                         
                                               
                                                   
                                                                           
                
    
__STATIC_INLINE void LL_ADC_SetCalibrationFactor(ADC_TypeDef *ADCx, uint32_t SingleDiff, uint32_t CalibrationFactor)
{
  MODIFY_REG(ADCx->CALFACT,
             SingleDiff & ADC_SINGLEDIFF_CALIB_FACTOR_MASK,
             CalibrationFactor << (((SingleDiff & ADC_SINGLEDIFF_CALIB_F_BIT_D_MASK)
                                    >> ADC_SINGLEDIFF_CALIB_F_BIT_D_SHIFT4)
                                   & ~(SingleDiff & ADC_CALFACT_CALFACT_S)));
}

   
                                                               
                                                                           
                                                                    
                                                                            
                                                         
                                                        
                                               
                                                                 
                                                               
                             
                                                                         
                                         
                                               
                                                         
    
__STATIC_INLINE uint32_t LL_ADC_GetCalibrationFactor(const ADC_TypeDef *ADCx, uint32_t SingleDiff)
{
                                                                                
                                                                                
                                                                                
                                                                                
  return (uint32_t)(READ_BIT(ADCx->CALFACT,
                             (SingleDiff & ADC_SINGLEDIFF_CALIB_FACTOR_MASK))
                    >> ((SingleDiff & ADC_SINGLEDIFF_CALIB_F_BIT_D_MASK) >>
                        ADC_SINGLEDIFF_CALIB_F_BIT_D_SHIFT4));
}

   
                               
                                                            
                                            
                                                                           
                      
                                                                       
                                                 
                                                        
                             
                                                                         
                                           
                                           
                                          
                                          
                
    
__STATIC_INLINE void LL_ADC_SetResolution(ADC_TypeDef *ADCx, uint32_t Resolution)
{
  MODIFY_REG(ADCx->CFGR, ADC_CFGR_RES, Resolution);
}

   
                               
                                                            
                                            
                                                        
                             
                                                              
                                           
                                           
                                          
                                          
    
__STATIC_INLINE uint32_t LL_ADC_GetResolution(const ADC_TypeDef *ADCx)
{
  return (uint32_t)(READ_BIT(ADCx->CFGR, ADC_CFGR_RES));
}

   
                                              
                                                            
                                            
                                                                           
                      
                                                                       
                                                 
                                                           
                             
                                                                            
                                             
                                            
                
    
__STATIC_INLINE void LL_ADC_SetDataAlignment(ADC_TypeDef *ADCx, uint32_t DataAlignment)
{
  MODIFY_REG(ADCx->CFGR, ADC_CFGR_ALIGN, DataAlignment);
}

   
                                              
                                                            
                                            
                                                           
                             
                                                              
                                             
                                            
    
__STATIC_INLINE uint32_t LL_ADC_GetDataAlignment(const ADC_TypeDef *ADCx)
{
  return (uint32_t)(READ_BIT(ADCx->CFGR, ADC_CFGR_ALIGN));
}

   
                                   
                                               
                                                                     
                                                                              
                                                   
                                                              
                                                             
                                                                            
                                                  
                                                                      
                               
                                                                         
                                                                        
                                                                     
                           
                                             
                                                                     
                                                                        
                                                                 
                                                                          
                                                                              
                                                                       
                                                         
                                                                            
                                                                      
                                                                    
                                     
                                                                             
                                                                            
                                               
                                                                        
                                                                   
                        
                                                                           
                      
                                                                       
                                                 
                                                          
                             
                                                                           
                                         
                                        
                
    
__STATIC_INLINE void LL_ADC_SetLowPowerMode(ADC_TypeDef *ADCx, uint32_t LowPowerMode)
{
  MODIFY_REG(ADCx->CFGR, ADC_CFGR_AUTDLY, LowPowerMode);
}

   
                                   
                                               
                                                                     
                                                                              
                                                   
                                                              
                                                             
                                                                            
                                                  
                                                                      
                               
                                                                         
                                                                        
                                                                     
                           
                                             
                                                                     
                                                                        
                                                                 
                                                                          
                                                                              
                                                                       
                                                         
                                                                            
                                                                      
                                                                    
                                     
                                                                             
                                                                            
                                               
                                                                        
                                                                   
                        
                                                          
                             
                                                              
                                         
                                        
    
__STATIC_INLINE uint32_t LL_ADC_GetLowPowerMode(const ADC_TypeDef *ADCx)
{
  return (uint32_t)(READ_BIT(ADCx->CFGR, ADC_CFGR_AUTDLY));
}

   
                                                          
                                                                  
                                                                        
                                                                   
                                
                                                                
                              
                                                                  
                                                                         
                         
                                                                          
                                                                    
                                                                              
                                                                    
                                                                           
                      
                                                                       
                                                 
                                                                            
                                               
                                                      
                                                      
                                                      
                                                      
                                                      
                                                      
                                                      
                                                      
                                                      
                                                      
                                                      
                                                    
                             
                                                                      
                                     
                                     
                                     
                                     
                                                                      
                                      
                                                     
                                                     
                                                     
                                                     
                                                     
                                      
                                      
                                      
                                      
                                       
                                       
                                       
                                       
                                       
                                       
                                       
                                       
                                       
                                                     
                                                     
                                                     
                                                        
                                                        
                                                        
                                                        
                                                        
                                                        
   
                                                                             
                                                                             
                                                                             
                                                                                    
                                                                                      
                                                                                        
                                                                                                                
                                                                                                                        
                                                                       
                
    
__STATIC_INLINE void LL_ADC_SetOffset(ADC_TypeDef *ADCx, uint32_t Offsety, uint32_t Channel, uint32_t OffsetLevel)
{
  __IO uint32_t *preg = __ADC_PTR_REG_OFFSET(ADCx->OFR1, Offsety);

  MODIFY_REG(*preg,
             ADC_OFR1_OFFSET1_EN | ADC_OFR1_OFFSET1_CH | ADC_OFR1_OFFSET1,
             ADC_OFR1_OFFSET1_EN | (Channel & ADC_CHANNEL_ID_NUMBER_MASK) | OffsetLevel);
}

   
                                                                  
                                                                  
                                                                 
                              
                                                 
                                                                        
                                                                                
                                                                            
                                                              
                                                                 
                                                                    
                                                
                                                          
                                                              
                                                    
                                                                            
                                               
                                                             
                                                             
                                                             
                                                           
                             
                                                                      
                                     
                                     
                                     
                                     
                                                              
                                      
                                                     
                                                     
                                                     
                                                     
                                                     
                                      
                                      
                                      
                                      
                                       
                                       
                                       
                                       
                                       
                                       
                                       
                                       
                                       
                                                     
                                                     
                                                     
                                                        
                                                        
                                                        
                                                        
                                                        
                                                        
   
                                                                             
                                                                             
                                                                             
                                                                                    
                                                                                      
                                                                                        
                                                                                                                
                                                                                                           
                              
                                                                     
                                                                              
                                                                                         
    
__STATIC_INLINE uint32_t LL_ADC_GetOffsetChannel(const ADC_TypeDef *ADCx, uint32_t Offsety)
{
  const __IO uint32_t *preg = __ADC_PTR_REG_OFFSET(ADCx->OFR1, Offsety);

  return (uint32_t) READ_BIT(*preg, ADC_OFR1_OFFSET1_CH);
}

   
                                                                  
                                                              
                            
                                                                  
                                                                         
                         
                                                           
                                                           
                                                           
                                                         
                             
                                                                      
                                     
                                     
                                     
                                     
                                                           
    
__STATIC_INLINE uint32_t LL_ADC_GetOffsetLevel(const ADC_TypeDef *ADCx, uint32_t Offsety)
{
  const __IO uint32_t *preg = __ADC_PTR_REG_OFFSET(ADCx->OFR1, Offsety);

  return (uint32_t) READ_BIT(*preg, ADC_OFR1_OFFSET1);
}

   
                                                                  
                                                
                                                             
                                                                       
                                                                                  
                                                                         
                                                                           
                      
                                                                       
                                                 
                                                           
                                                           
                                                           
                                                         
                             
                                                                      
                                     
                                     
                                     
                                     
                                                                          
                                           
                                          
                
    
__STATIC_INLINE void LL_ADC_SetOffsetState(ADC_TypeDef *ADCx, uint32_t Offsety, uint32_t OffsetState)
{
  __IO uint32_t *preg = __ADC_PTR_REG_OFFSET(ADCx->OFR1, Offsety);

  MODIFY_REG(*preg,
             ADC_OFR1_OFFSET1_EN,
             OffsetState);
}

   
                                                                  
                                             
                                                           
                                                           
                                                           
                                                         
                             
                                                                      
                                     
                                     
                                     
                                     
                                                              
                                           
                                          
    
__STATIC_INLINE uint32_t LL_ADC_GetOffsetState(const ADC_TypeDef *ADCx, uint32_t Offsety)
{
  const __IO uint32_t *preg = __ADC_PTR_REG_OFFSET(ADCx->OFR1, Offsety);

  return (uint32_t) READ_BIT(*preg, ADC_OFR1_OFFSET1_EN);
}

#if defined(ADC_SMPR1_SMPPLUS)
   
                                                                
                                                   
                                                                           
                      
                                                                       
                                                 
                                                                      
                             
                                                                                       
                                                        
                                                             
                
    
__STATIC_INLINE void LL_ADC_SetSamplingTimeCommonConfig(ADC_TypeDef *ADCx, uint32_t SamplingTimeCommonConfig)
{
  MODIFY_REG(ADCx->SMPR1, ADC_SMPR1_SMPPLUS, SamplingTimeCommonConfig);
}

   
                                                                
                                                   
                                                                      
                             
                                                              
                                                        
                                                             
    
__STATIC_INLINE uint32_t LL_ADC_GetSamplingTimeCommonConfig(const ADC_TypeDef *ADCx)
{
  return (uint32_t)(READ_BIT(ADCx->SMPR1, ADC_SMPR1_SMPPLUS));
}
#endif                        

   
      
    

                                                                                                              
      
    

   
                                                            
                                                                         
                                     
                                                                            
                                                    
                                                                     
                                                                      
                                                       
                                                      
                                                                    
                                                                  
                                                                           
                      
                                                                       
                             
                                                                 
                                                               
                             
                                                                            
                                              
                                                   
                                                    
                                                  
                                                  
                                                  
                                                   
                                                  
                                                   
                                                  
                                                   
                                                  
                                                   
                                                   
                                                    
                                                    
                                                     
                
    
__STATIC_INLINE void LL_ADC_REG_SetTriggerSource(ADC_TypeDef *ADCx, uint32_t TriggerSource)
{
  MODIFY_REG(ADCx->CFGR, ADC_CFGR_EXTEN | ADC_CFGR_EXTSEL, TriggerSource);
}

   
                                                            
                                                                         
                                     
                                                                
                                                           
                                                                
                          
                                                                                
                                                                
                                                                    
                                                                  
                                                                 
                                                               
                             
                                                              
                                              
                                                   
                                                    
                                                  
                                                  
                                                  
                                                   
                                                  
                                                   
                                                  
                                                   
                                                  
                                                   
                                                   
                                                    
                                                    
                                                     
    
__STATIC_INLINE uint32_t LL_ADC_REG_GetTriggerSource(const ADC_TypeDef *ADCx)
{
  __IO uint32_t trigger_source = READ_BIT(ADCx->CFGR, ADC_CFGR_EXTSEL | ADC_CFGR_EXTEN);

                                                                                
                                                                                
  uint32_t shift_exten = ((trigger_source & ADC_CFGR_EXTEN) >> (ADC_REG_TRIG_EXTEN_BITOFFSET_POS - 2UL));

                                                                                
                                                                                
  return ((trigger_source
           & (ADC_REG_TRIG_SOURCE_MASK >> shift_exten) & ADC_CFGR_EXTSEL)
          | ((ADC_REG_TRIG_EDGE_MASK >> shift_exten) & ADC_CFGR_EXTEN)
         );
}

   
                                                                               
                        
                                                                            
                                                                          
                                                            
                                                                     
                             
                                                        
                                                 
    
__STATIC_INLINE uint32_t LL_ADC_REG_IsTriggerSourceSWStart(const ADC_TypeDef *ADCx)
{
  return ((READ_BIT(ADCx->CFGR, ADC_CFGR_EXTEN) == (LL_ADC_REG_TRIG_SOFTWARE & ADC_CFGR_EXTEN)) ? 1UL : 0UL);
}

   
                                                              
                                                                       
                                                                           
                      
                                                                       
                             
                                                             
                             
                                                                                  
                                                
                                                 
                                                       
                
    
__STATIC_INLINE void LL_ADC_REG_SetTriggerEdge(ADC_TypeDef *ADCx, uint32_t ExternalTriggerEdge)
{
  MODIFY_REG(ADCx->CFGR, ADC_CFGR_EXTEN, ExternalTriggerEdge);
}

   
                                                              
                                                                       
                                                             
                             
                                                              
                                                
                                                 
                                                       
    
__STATIC_INLINE uint32_t LL_ADC_REG_GetTriggerEdge(const ADC_TypeDef *ADCx)
{
  return (uint32_t)(READ_BIT(ADCx->CFGR, ADC_CFGR_EXTEN));
}

   
                                                                      
                                                                
                                                           
                                                                    
                                                                     
                               
                                                      
                                                                      
                                                                             
                                                                  
                                                
                                                        
                                                               
                                                                       
                                                                     
                                            
                                                      
                                                                        
                                                                  
                                                                   
                                                                           
                                                                             
                                                                        
                                        
                                                
                                                           
                                                                    
                                             
                                                                           
                      
                                                                       
                             
                                                                 
                             
                                                                               
                                                 
                                                       
                                                       
                                                       
                                                       
                                                       
                                                       
                                                       
                                                       
                                                        
                                                        
                                                        
                                                        
                                                        
                                                        
                                                        
                
    
__STATIC_INLINE void LL_ADC_REG_SetSequencerLength(ADC_TypeDef *ADCx, uint32_t SequencerNbRanks)
{
  MODIFY_REG(ADCx->SQR1, ADC_SQR1_L, SequencerNbRanks);
}

   
                                                                      
                                                                
                                                           
                                                                    
                                                                     
                               
                                      
                                                                      
                                                                             
                                                                  
                                                
                                                        
                                                               
                                                                       
                                                                     
                                            
                                      
                                                                        
                                                                  
                                                                   
                                                                           
                                                                             
                                                                        
                                        
                                                
                                                           
                                                                    
                                             
                                                                 
                             
                                                              
                                                 
                                                       
                                                       
                                                       
                                                       
                                                       
                                                       
                                                       
                                                       
                                                        
                                                        
                                                        
                                                        
                                                        
                                                        
                                                        
    
__STATIC_INLINE uint32_t LL_ADC_REG_GetSequencerLength(const ADC_TypeDef *ADCx)
{
  return (uint32_t)(READ_BIT(ADCx->SQR1, ADC_SQR1_L));
}

   
                                                               
                                                                               
                            
                                                               
                                                             
                                                                    
                                                               
                                                                           
                      
                                                                       
                             
                                                                    
                                                                  
                             
                                                                         
                                                    
                                                  
                                                   
                                                   
                                                   
                                                   
                                                   
                                                   
                                                   
                
    
__STATIC_INLINE void LL_ADC_REG_SetSequencerDiscont(ADC_TypeDef *ADCx, uint32_t SeqDiscont)
{
  MODIFY_REG(ADCx->CFGR, ADC_CFGR_DISCEN | ADC_CFGR_DISCNUM, SeqDiscont);
}

   
                                                               
                                                                               
                            
                                                                    
                                                                  
                             
                                                              
                                                    
                                                  
                                                   
                                                   
                                                   
                                                   
                                                   
                                                   
                                                   
    
__STATIC_INLINE uint32_t LL_ADC_REG_GetSequencerDiscont(const ADC_TypeDef *ADCx)
{
  return (uint32_t)(READ_BIT(ADCx->CFGR, ADC_CFGR_DISCEN | ADC_CFGR_DISCNUM));
}

   
                                                                   
                               
                                                    
                                                                
                                                                
                                                                
                                                              
                                                      
                                                                                  
                                                                                  
                                                                
                                                                        
                                                                            
                               
                                                                                  
                                                                           
                      
                                                                       
                             
                                                                  
                                                                  
                                                                  
                                                                  
                                                                  
                                                                  
                                                                  
                                                                  
                                                                  
                                                                  
                                                                  
                                                                  
                                                                  
                                                                  
                                                                  
                                                                
                             
                                                                   
                                       
                                       
                                       
                                       
                                       
                                       
                                       
                                       
                                       
                                        
                                        
                                        
                                        
                                        
                                        
                                        
                                                                      
                                      
                                                     
                                                     
                                                     
                                                     
                                                     
                                      
                                      
                                      
                                      
                                       
                                       
                                       
                                       
                                       
                                       
                                       
                                       
                                       
                                                     
                                                     
                                                     
                                                        
                                                        
                                                        
                                                        
                                                        
                                                        
   
                                                                             
                                                                             
                                                                             
                                                                                    
                                                                                      
                                                                                        
                                                                                                                
                                                                                                                        
                
    
__STATIC_INLINE void LL_ADC_REG_SetSequencerRanks(ADC_TypeDef *ADCx, uint32_t Rank, uint32_t Channel)
{
                                                                                
                                                                                
                                                                                
                                                                                
  __IO uint32_t *preg = __ADC_PTR_REG_OFFSET(ADCx->SQR1,
                                             ((Rank & ADC_REG_SQRX_REGOFFSET_MASK) >> ADC_SQRX_REGOFFSET_POS));

  MODIFY_REG(*preg,
             ADC_CHANNEL_ID_NUMBER_MASK_POSBIT0 << (Rank & ADC_REG_RANK_ID_SQRX_MASK),
             ((Channel & ADC_CHANNEL_ID_NUMBER_MASK) >> ADC_CHANNEL_ID_NUMBER_BITOFFSET_POS)
             << (Rank & ADC_REG_RANK_ID_SQRX_MASK));
}

   
                                                                   
                               
                                                                
                                                              
                                                      
                                                                                  
                                                                                  
                                                                
                                                 
                                                                        
                                                                                
                                                                            
                                                              
                                                                 
                                                                    
                                                
                                                          
                                                              
                                                    
                                                                  
                                                                  
                                                                  
                                                                  
                                                                  
                                                                  
                                                                  
                                                                  
                                                                  
                                                                  
                                                                  
                                                                  
                                                                  
                                                                  
                                                                  
                                                                
                             
                                                                   
                                       
                                       
                                       
                                       
                                       
                                       
                                       
                                       
                                       
                                        
                                        
                                        
                                        
                                        
                                        
                                        
                                                              
                                      
                                                     
                                                     
                                                     
                                                     
                                                     
                                      
                                      
                                      
                                      
                                       
                                       
                                       
                                       
                                       
                                       
                                       
                                       
                                       
                                                     
                                                     
                                                     
                                                        
                                                        
                                                        
                                                        
                                                        
                                                        
   
                                                                             
                                                                             
                                                                             
                                                                                    
                                                                                      
                                                                                        
                                                                                                                
                                                                                                           
                              
                                                                     
                                                                              
                                                                                         
    
__STATIC_INLINE uint32_t LL_ADC_REG_GetSequencerRanks(const ADC_TypeDef *ADCx, uint32_t Rank)
{
  const __IO uint32_t *preg = __ADC_PTR_REG_OFFSET(ADCx->SQR1,
                                                   ((Rank & ADC_REG_SQRX_REGOFFSET_MASK) >> ADC_SQRX_REGOFFSET_POS));

  return (uint32_t)((READ_BIT(*preg,
                              ADC_CHANNEL_ID_NUMBER_MASK_POSBIT0 << (Rank & ADC_REG_RANK_ID_SQRX_MASK))
                     >> (Rank & ADC_REG_RANK_ID_SQRX_MASK)) << ADC_CHANNEL_ID_NUMBER_BITOFFSET_POS
                   );
}

   
                                                                    
                                                          
                                                     
                                                                 
                                                              
                                                               
                                                             
                                                                           
                      
                                                                       
                             
                                                                
                             
                                                                         
                                            
                                                
                
    
__STATIC_INLINE void LL_ADC_REG_SetContinuousMode(ADC_TypeDef *ADCx, uint32_t Continuous)
{
  MODIFY_REG(ADCx->CFGR, ADC_CFGR_CONT, Continuous);
}

   
                                                                    
                                                          
                                                     
                                                                 
                                                              
                                                                
                             
                                                              
                                            
                                                
    
__STATIC_INLINE uint32_t LL_ADC_REG_GetContinuousMode(const ADC_TypeDef *ADCx)
{
  return (uint32_t)(READ_BIT(ADCx->CFGR, ADC_CFGR_CONT));
}

   
                                                                          
                                                   
                                                                   
                 
                                                                             
                                                          
                                          
                                                                              
                                                                  
                                                              
                               
                                                                          
                                                                          
                              
                                                                               
                                                                
                                                      
                                                                     
                                                                                    
                                                                 
                                                      
                                                                           
                      
                                                                       
                                                 
                                                               
                                                             
                             
                                                                          
                                                  
                                                     
                                                       
                
    
__STATIC_INLINE void LL_ADC_REG_SetDMATransfer(ADC_TypeDef *ADCx, uint32_t DMATransfer)
{
  MODIFY_REG(ADCx->CFGR, ADC_CFGR_DMAEN | ADC_CFGR_DMACFG, DMATransfer);
}

   
                                                                          
                                                   
                                                                   
                 
                                                                             
                                                          
                                          
                                                                              
                                                                  
                                                              
                               
                                                                          
                                                                          
                              
                                                                               
                                                                
                                                       
                                                                     
                                                                                    
                                                                 
                                                      
                                                               
                                                             
                             
                                                              
                                                  
                                                     
                                                       
    
__STATIC_INLINE uint32_t LL_ADC_REG_GetDMATransfer(const ADC_TypeDef *ADCx)
{
  return (uint32_t)(READ_BIT(ADCx->CFGR, ADC_CFGR_DMAEN | ADC_CFGR_DMACFG));
}

#if defined(ADC_CFGR_DFSDMCFG) &&defined(DFSDM1_Channel0)
   
                                                                    
                                                                     
                                                                   
                                                      
                                                  
                                                                           
                      
                                                                       
                                                 
                                                               
                             
                                                                            
                                                    
                                                      
                
    
__STATIC_INLINE void LL_ADC_REG_SetDFSDMTransfer(ADC_TypeDef *ADCx, uint32_t DFSDMTransfer)
{
  MODIFY_REG(ADCx->CFGR, ADC_CFGR_DFSDMCFG, DFSDMTransfer);
}

   
                                                                    
                                                               
                             
                                                              
                                                    
                                                      
    
__STATIC_INLINE uint32_t LL_ADC_REG_GetDFSDMTransfer(const ADC_TypeDef *ADCx)
{
  return (uint32_t)(READ_BIT(ADCx->CFGR, ADC_CFGR_DFSDMCFG));
}
#endif                        

   
                                                              
                                          
                                                               
                                                              
                                           
                                                             
                                                                    
                                                      
                                                                           
                      
                                                                       
                             
                                                         
                             
                                                                      
                                                   
                                                     
                
    
__STATIC_INLINE void LL_ADC_REG_SetOverrun(ADC_TypeDef *ADCx, uint32_t Overrun)
{
  MODIFY_REG(ADCx->CFGR, ADC_CFGR_OVRMOD, Overrun);
}

   
                                                              
                                          
                                                         
                             
                                                              
                                                   
                                                     
    
__STATIC_INLINE uint32_t LL_ADC_REG_GetOverrun(const ADC_TypeDef *ADCx)
{
  return (uint32_t)(READ_BIT(ADCx->CFGR, ADC_CFGR_OVRMOD));
}

   
      
    

                                                                                                                
      
    

   
                                                             
                                                                         
                                     
                                                                            
                                                    
                                                                     
                                                                      
                                                       
                                                      
                                                                    
                                                                  
                                                                           
                      
                                                                               
                                                          
                                                                 
                                                               
                             
                                                                            
                                              
                                                   
                                                    
                                                  
                                                   
                                                  
                                                   
                                                  
                                                  
                                                  
                                                   
                                                   
                                                  
                                                   
                                                    
                                                    
                                                     
                
    
__STATIC_INLINE void LL_ADC_INJ_SetTriggerSource(ADC_TypeDef *ADCx, uint32_t TriggerSource)
{
  MODIFY_REG(ADCx->JSQR, ADC_JSQR_JEXTSEL | ADC_JSQR_JEXTEN, TriggerSource);
}

   
                                                             
                                                                         
                                     
                                                                 
                                                           
                                                                
                          
                                                                                
                                                                
                                                                    
                                                                  
                                                                 
                                                               
                             
                                                              
                                              
                                                   
                                                    
                                                  
                                                   
                                                  
                                                   
                                                  
                                                  
                                                  
                                                   
                                                   
                                                  
                                                   
                                                    
                                                    
                                                     
    
__STATIC_INLINE uint32_t LL_ADC_INJ_GetTriggerSource(const ADC_TypeDef *ADCx)
{
  __IO uint32_t trigger_source = READ_BIT(ADCx->JSQR, ADC_JSQR_JEXTSEL | ADC_JSQR_JEXTEN);

                                                                                
                                                                                
  uint32_t shift_jexten = ((trigger_source & ADC_JSQR_JEXTEN) >> (ADC_INJ_TRIG_EXTEN_BITOFFSET_POS - 2UL));

                                                                                
                                                                                
  return ((trigger_source
           & (ADC_INJ_TRIG_SOURCE_MASK >> shift_jexten) & ADC_JSQR_JEXTSEL)
          | ((ADC_INJ_TRIG_EDGE_MASK >> shift_jexten) & ADC_JSQR_JEXTEN)
         );
}

   
                                                                                
                       
                                                                             
                                                                          
                                                          
                                                                     
                             
                                                        
                                                 
    
__STATIC_INLINE uint32_t LL_ADC_INJ_IsTriggerSourceSWStart(const ADC_TypeDef *ADCx)
{
  return ((READ_BIT(ADCx->JSQR, ADC_JSQR_JEXTEN) == (LL_ADC_INJ_TRIG_SOFTWARE & ADC_JSQR_JEXTEN)) ? 1UL : 0UL);
}

   
                                                               
                                                                       
                                                                           
                      
                                                                               
                                                          
                                                             
                             
                                                                                  
                                                
                                                 
                                                       
                
    
__STATIC_INLINE void LL_ADC_INJ_SetTriggerEdge(ADC_TypeDef *ADCx, uint32_t ExternalTriggerEdge)
{
  MODIFY_REG(ADCx->JSQR, ADC_JSQR_JEXTEN, ExternalTriggerEdge);
}

   
                                                               
                                                                       
                                                             
                             
                                                              
                                                
                                                 
                                                       
    
__STATIC_INLINE uint32_t LL_ADC_INJ_GetTriggerEdge(const ADC_TypeDef *ADCx)
{
  return (uint32_t)(READ_BIT(ADCx->JSQR, ADC_JSQR_JEXTEN));
}

   
                                                                       
                                                    
                                                                    
                                                                           
                                                                
                                                                    
                                             
                                                                           
                      
                                                                               
                                                          
                                                                 
                             
                                                                               
                                                 
                                                       
                                                       
                                                       
                
    
__STATIC_INLINE void LL_ADC_INJ_SetSequencerLength(ADC_TypeDef *ADCx, uint32_t SequencerNbRanks)
{
  MODIFY_REG(ADCx->JSQR, ADC_JSQR_JL, SequencerNbRanks);
}

   
                                                                       
                                    
                                                                    
                                                                           
                                                                
                                                                    
                                             
                                                                 
                             
                                                              
                                                 
                                                       
                                                       
                                                       
    
__STATIC_INLINE uint32_t LL_ADC_INJ_GetSequencerLength(const ADC_TypeDef *ADCx)
{
  return (uint32_t)(READ_BIT(ADCx->JSQR, ADC_JSQR_JL));
}

   
                                                                
                                                                               
                            
                                                                
                                                                
                                                                  
                             
                                                                         
                                                    
                                                  
                
    
__STATIC_INLINE void LL_ADC_INJ_SetSequencerDiscont(ADC_TypeDef *ADCx, uint32_t SeqDiscont)
{
  MODIFY_REG(ADCx->CFGR, ADC_CFGR_JDISCEN, SeqDiscont);
}

   
                                                                
                                                                               
                            
                                                                  
                             
                                                              
                                                    
                                                  
    
__STATIC_INLINE uint32_t LL_ADC_INJ_GetSequencerDiscont(const ADC_TypeDef *ADCx)
{
  return (uint32_t)(READ_BIT(ADCx->CFGR, ADC_CFGR_JDISCEN));
}

   
                                                                    
                          
                                                                                  
                                                                
                                                                        
                                                                            
                               
                                                                                  
                                                                            
                                               
                                                                           
                      
                                                                               
                                                          
                                                                  
                                                                  
                                                                  
                                                                
                             
                                                                   
                                       
                                       
                                       
                                       
                                                                      
                                      
                                                     
                                                     
                                                     
                                                     
                                                     
                                      
                                      
                                      
                                      
                                       
                                       
                                       
                                       
                                       
                                       
                                       
                                       
                                       
                                                     
                                                     
                                                     
                                                        
                                                        
                                                        
                                                        
                                                        
                                                        
   
                                                                             
                                                                             
                                                                             
                                                                                    
                                                                                      
                                                                                        
                                                                                                                
                                                                                                                        
                
    
__STATIC_INLINE void LL_ADC_INJ_SetSequencerRanks(ADC_TypeDef *ADCx, uint32_t Rank, uint32_t Channel)
{
                                                                                
                                                                                
                                                                                
                                                                                
  MODIFY_REG(ADCx->JSQR,
             (ADC_CHANNEL_ID_NUMBER_MASK >> ADC_CHANNEL_ID_NUMBER_BITOFFSET_POS)
             << (Rank & ADC_INJ_RANK_ID_JSQR_MASK),
             ((Channel & ADC_CHANNEL_ID_NUMBER_MASK) >> ADC_CHANNEL_ID_NUMBER_BITOFFSET_POS)
             << (Rank & ADC_INJ_RANK_ID_JSQR_MASK));
}

   
                                                                    
                          
                                                                                  
                                                                
                                                 
                                                                        
                                                                                
                                                                            
                                                              
                                                                 
                                                                    
                                                
                                                          
                                                              
                                                    
                                                                  
                                                                  
                                                                  
                                                                
                             
                                                                   
                                       
                                       
                                       
                                       
                                                              
                                      
                                                     
                                                     
                                                     
                                                     
                                                     
                                      
                                      
                                      
                                      
                                       
                                       
                                       
                                       
                                       
                                       
                                       
                                       
                                       
                                                     
                                                     
                                                     
                                                        
                                                        
                                                        
                                                        
                                                        
                                                        
   
                                                                             
                                                                             
                                                                             
                                                                                    
                                                                                      
                                                                                        
                                                                                                                
                                                                                                           
                              
                                                                     
                                                                              
                                                                                         
    
__STATIC_INLINE uint32_t LL_ADC_INJ_GetSequencerRanks(const ADC_TypeDef *ADCx, uint32_t Rank)
{
  return (uint32_t)((READ_BIT(ADCx->JSQR,
                              (ADC_CHANNEL_ID_NUMBER_MASK >> ADC_CHANNEL_ID_NUMBER_BITOFFSET_POS)
                              << (Rank & ADC_INJ_RANK_ID_JSQR_MASK))
                     >> (Rank & ADC_INJ_RANK_ID_JSQR_MASK)) << ADC_CHANNEL_ID_NUMBER_BITOFFSET_POS
                   );
}

   
                                                      
                                                  
                                                                    
                                                                  
                                                                             
                                                         
                                                                  
                                  
                                                                      
                                                                 
                                
                                                                       
                                                                      
                                                                           
                                                               
                                   
                                                                
                                                                
                                                                           
                      
                                                                       
                                                 
                                                          
                             
                                                                       
                                                 
                                                      
                
    
__STATIC_INLINE void LL_ADC_INJ_SetTrigAuto(ADC_TypeDef *ADCx, uint32_t TrigAuto)
{
  MODIFY_REG(ADCx->CFGR, ADC_CFGR_JAUTO, TrigAuto);
}

   
                                                      
                                                  
                                                          
                             
                                                              
                                                 
                                                      
    
__STATIC_INLINE uint32_t LL_ADC_INJ_GetTrigAuto(const ADC_TypeDef *ADCx)
{
  return (uint32_t)(READ_BIT(ADCx->CFGR, ADC_CFGR_JAUTO));
}

   
                                                       
                                                               
                                    
                              
                             
                                          
                                               
                                        
                                         
                                            
                                                                               
                                                                             
                                                        
                                                                               
                                                                                 
                                                                       
                                                                   
                                                                        
                                                                           
                              
                                                                        
                                                                          
                                                                  
                                                                              
                                                 
                                                                              
                                                                 
                                                                           
                      
                                                                       
                                                 
                                                             
                                                           
                             
                                                                        
                                              
                                                            
                                                          
                
    
__STATIC_INLINE void LL_ADC_INJ_SetQueueMode(ADC_TypeDef *ADCx, uint32_t QueueMode)
{
  MODIFY_REG(ADCx->CFGR, ADC_CFGR_JQM | ADC_CFGR_JQDIS, QueueMode);
}

   
                                                      
                                                             
                                                           
                             
                                                              
                                              
                                                            
                                                          
    
__STATIC_INLINE uint32_t LL_ADC_INJ_GetQueueMode(const ADC_TypeDef *ADCx)
{
  return (uint32_t)(READ_BIT(ADCx->CFGR, ADC_CFGR_JQM | ADC_CFGR_JQDIS));
}

   
                                                                         
                           
                                                               
                                    
                              
                             
                                                                                
                                                                     
                                                                                
                            
                                                             
                                                                       
                                                                        
                                                   
                                                 
                                                    
                                                                        
                                                                            
                               
                                                                                  
                                                                            
                                               
                                                                           
                      
                                                                               
                                                          
                                                                   
                                                                   
                                                                   
                                                                   
                                                                   
                                                                   
                                                                 
                             
                                                                            
                                              
                                                   
                                                    
                                                  
                                                   
                                                  
                                                   
                                                  
                                                  
                                                  
                                                   
                                                   
                                                  
                                                   
                                                    
                                                    
                                                     
                                                                                  
                                                
                                                 
                                                       
   
                                                                  
                                                                              
                                                                               
                                                 
                                                       
                                                       
                                                       
                                                                            
                                      
                                                     
                                                     
                                                     
                                                     
                                                     
                                      
                                      
                                      
                                      
                                       
                                       
                                       
                                       
                                       
                                       
                                       
                                       
                                       
                                                     
                                                     
                                                     
                                                        
                                                        
                                                        
                                                        
                                                        
                                                        
   
                                                                             
                                                                             
                                                                             
                                                                                    
                                                                                      
                                                                                        
                                                                                                                
                                                                                                                        
                                                                            
                                      
                                                     
                                                     
                                                     
                                                     
                                                     
                                      
                                      
                                      
                                      
                                       
                                       
                                       
                                       
                                       
                                       
                                       
                                       
                                       
                                                     
                                                     
                                                     
                                                        
                                                        
                                                        
                                                        
                                                        
                                                        
   
                                                                             
                                                                             
                                                                             
                                                                                    
                                                                                      
                                                                                        
                                                                                                                
                                                                                                                        
                                                                            
                                      
                                                     
                                                     
                                                     
                                                     
                                                     
                                      
                                      
                                      
                                      
                                       
                                       
                                       
                                       
                                       
                                       
                                       
                                       
                                       
                                                     
                                                     
                                                     
                                                        
                                                        
                                                        
                                                        
                                                        
                                                        
   
                                                                             
                                                                             
                                                                             
                                                                                    
                                                                                      
                                                                                        
                                                                                                                
                                                                                                                        
                                                                            
                                      
                                                     
                                                     
                                                     
                                                     
                                                     
                                      
                                      
                                      
                                      
                                       
                                       
                                       
                                       
                                       
                                       
                                       
                                       
                                       
                                                     
                                                     
                                                     
                                                        
                                                        
                                                        
                                                        
                                                        
                                                        
   
                                                                             
                                                                             
                                                                             
                                                                                    
                                                                                      
                                                                                        
                                                                                                                
                                                                                                                        
                
    
__STATIC_INLINE void LL_ADC_INJ_ConfigQueueContext(ADC_TypeDef *ADCx,
                                                   uint32_t TriggerSource,
                                                   uint32_t ExternalTriggerEdge,
                                                   uint32_t SequencerNbRanks,
                                                   uint32_t Rank1_Channel,
                                                   uint32_t Rank2_Channel,
                                                   uint32_t Rank3_Channel,
                                                   uint32_t Rank4_Channel)
{
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
  uint32_t is_trigger_not_sw = (uint32_t)((TriggerSource != LL_ADC_INJ_TRIG_SOFTWARE) ? 1UL : 0UL);
  MODIFY_REG(ADCx->JSQR,
             ADC_JSQR_JEXTSEL |
             ADC_JSQR_JEXTEN  |
             ADC_JSQR_JSQ4    |
             ADC_JSQR_JSQ3    |
             ADC_JSQR_JSQ2    |
             ADC_JSQR_JSQ1    |
             ADC_JSQR_JL,
             (TriggerSource & ADC_JSQR_JEXTSEL)          |
             (ExternalTriggerEdge * (is_trigger_not_sw)) |
             (((Rank4_Channel & ADC_CHANNEL_ID_NUMBER_MASK) >> ADC_CHANNEL_ID_NUMBER_BITOFFSET_POS)
              << (LL_ADC_INJ_RANK_4 & ADC_INJ_RANK_ID_JSQR_MASK)) |
             (((Rank3_Channel & ADC_CHANNEL_ID_NUMBER_MASK) >> ADC_CHANNEL_ID_NUMBER_BITOFFSET_POS)
              << (LL_ADC_INJ_RANK_3 & ADC_INJ_RANK_ID_JSQR_MASK)) |
             (((Rank2_Channel & ADC_CHANNEL_ID_NUMBER_MASK) >> ADC_CHANNEL_ID_NUMBER_BITOFFSET_POS)
              << (LL_ADC_INJ_RANK_2 & ADC_INJ_RANK_ID_JSQR_MASK)) |
             (((Rank1_Channel & ADC_CHANNEL_ID_NUMBER_MASK) >> ADC_CHANNEL_ID_NUMBER_BITOFFSET_POS)
              << (LL_ADC_INJ_RANK_1 & ADC_INJ_RANK_ID_JSQR_MASK)) |
             SequencerNbRanks
            );
}

   
      
    

                                                                                                
      
    

   
                                                         
                                   
                                                                            
                                                               
                                                                        
                      
                                                                             
                                                                         
                     
                                                                                
                          
                                                                                 
                                                         
                                                             
                                                             
                                                           
                                                           
                                                                   
                                                                   
                        
                                      
                                                                           
                      
                                                                       
                                                 
                                                                   
                                                                   
                                                                   
                                                                   
                                                                   
                                                                   
                                                                   
                                                                   
                                                                   
                                                                   
                                                                   
                                                                   
                                                                   
                                                                   
                                                                   
                                                                   
                                                                   
                                                                   
                                                                 
                             
                                                                      
                                      
                                                     
                                                     
                                                     
                                                     
                                                     
                                      
                                      
                                      
                                      
                                       
                                       
                                       
                                       
                                       
                                       
                                       
                                       
                                       
                                                     
                                                     
                                                     
                                                        
                                                        
                                                        
                                                        
                                                        
                                                        
   
                                                                             
                                                                             
                                                                             
                                                                                    
                                                                                      
                                                                                        
                                                                                                                
                                                                                                                        
                                                                           
                                                         
                                                   
                                                    
                                                    
                                                    
                                                    
                                                     
                                                     
   
                                                                       
                                                        
                                                                            
                
    
__STATIC_INLINE void LL_ADC_SetChannelSamplingTime(ADC_TypeDef *ADCx, uint32_t Channel, uint32_t SamplingTime)
{
                                                                                
                                                                                
                                                                                
                                                                                
  __IO uint32_t *preg = __ADC_PTR_REG_OFFSET(ADCx->SMPR1,
                                             ((Channel & ADC_CHANNEL_SMPRX_REGOFFSET_MASK) >> ADC_SMPRX_REGOFFSET_POS));

  MODIFY_REG(*preg,
             ADC_SMPR1_SMP0 << ((Channel & ADC_CHANNEL_SMPx_BITOFFSET_MASK) >> ADC_CHANNEL_SMPx_BITOFFSET_POS),
             SamplingTime   << ((Channel & ADC_CHANNEL_SMPx_BITOFFSET_MASK) >> ADC_CHANNEL_SMPx_BITOFFSET_POS));
}

   
                                                         
                                   
                                                                            
                                                               
                                                                                 
                                                         
                                                             
                                                             
                                                           
                                                           
                                                                   
                                                                   
                                                                   
                                                                   
                                                                   
                                                                   
                                                                   
                                                                   
                                                                   
                                                                   
                                                                   
                                                                   
                                                                   
                                                                   
                                                                   
                                                                   
                                                                   
                                                                   
                                                                 
                             
                                                                      
                                      
                                                     
                                                     
                                                     
                                                     
                                                     
                                      
                                      
                                      
                                      
                                       
                                       
                                       
                                       
                                       
                                       
                                       
                                       
                                       
                                                     
                                                     
                                                     
                                                        
                                                        
                                                        
                                                        
                                                        
                                                        
   
                                                                             
                                                                             
                                                                             
                                                                                    
                                                                                      
                                                                                        
                                                                                                                
                                                                                                                        
                                                              
                                                         
                                                   
                                                    
                                                    
                                                    
                                                    
                                                     
                                                     
   
                                                                       
                                                        
                                                                            
    
__STATIC_INLINE uint32_t LL_ADC_GetChannelSamplingTime(const ADC_TypeDef *ADCx, uint32_t Channel)
{
  const __IO uint32_t *preg = __ADC_PTR_REG_OFFSET(ADCx->SMPR1, ((Channel & ADC_CHANNEL_SMPRX_REGOFFSET_MASK)
                                                                 >> ADC_SMPRX_REGOFFSET_POS));

  return (uint32_t)(READ_BIT(*preg,
                             ADC_SMPR1_SMP0
                             << ((Channel & ADC_CHANNEL_SMPx_BITOFFSET_MASK) >> ADC_CHANNEL_SMPx_BITOFFSET_POS))
                    >> ((Channel & ADC_CHANNEL_SMPx_BITOFFSET_MASK) >> ADC_CHANNEL_SMPx_BITOFFSET_POS)
                   );
}

   
                                                                       
                        
                                                                               
                                             
                                                                         
                                                                 
                                                                      
                                                                  
                                                                       
                                           
                                                                         
                                               
                                                                
                                                       
                                                                              
                                                                      
                                                                         
                                                   
                                                   
                                                                           
                      
                                     
                                                  
                                                                 
                                                               
                             
                                                                      
                                      
                                      
                                      
                                      
                                      
                                      
                                      
                                      
                                      
                                       
                                       
                                       
                                       
                                       
                                       
                                                                                   
                                         
                                               
                
    
__STATIC_INLINE void LL_ADC_SetChannelSingleDiff(ADC_TypeDef *ADCx, uint32_t Channel, uint32_t SingleDiff)
{
                                                                                
                                                                                
                                                                                
  MODIFY_REG(ADCx->DIFSEL,
             Channel & ADC_SINGLEDIFF_CHANNEL_MASK,
             (Channel & ADC_SINGLEDIFF_CHANNEL_MASK)
             & (ADC_DIFSEL_DIFSEL >> (SingleDiff & ADC_SINGLEDIFF_CHANNEL_SHIFT_MASK)));
}

   
                                                                       
                        
                                                                
                                                       
                                                                              
                                                                             
                                                                               
                                                                     
                                                                       
                                           
                                                                         
                                               
                                                                
                                                       
                                                                              
                                                                      
                                                                          
                                                                      
                                                                 
                                                               
                             
                                                                                
                                      
                                      
                                      
                                      
                                      
                                      
                                      
                                      
                                      
                                       
                                       
                                       
                                       
                                       
                                       
                                                                               
    
__STATIC_INLINE uint32_t LL_ADC_GetChannelSingleDiff(const ADC_TypeDef *ADCx, uint32_t Channel)
{
  return (uint32_t)(READ_BIT(ADCx->DIFSEL, (Channel & ADC_SINGLEDIFF_CHANNEL_MASK)));
}

   
      
    

                                                                                                                
      
    

   
                                                       
                                                                
                                                  
                                                                 
                       
                                                                 
                                                                   
                                                                    
                                                                      
                     
                                           
                                                                          
                                                                     
                                                                     
                                           
                                                  
                                                                                
                                                          
                                                                          
                                         
                                                                                 
                                                                            
                                             
                                                                               
                                                                   
                                                                      
                                                                                 
                                                                           
                                      
                                                                           
                      
                                                                       
                                                 
                                                                     
                                                                     
                                                                     
                                                                     
                                                                     
                                                                   
                             
                                                                   
                                 
                                 
                                 
                                                                              
                                        
                                                            
                                                            
                                                     
                                                            
                                                            
                                                  
                                                            
                                                            
                                                  
                                                            
                                                            
                                                  
                                                            
                                                            
                                                  
                                                            
                                                            
                                                  
                                                            
                                                            
                                                  
                                                            
                                                            
                                                  
                                                            
                                                            
                                                  
                                                            
                                                            
                                                  
                                                            
                                                            
                                                  
                                                            
                                                            
                                                   
                                                            
                                                            
                                                   
                                                            
                                                            
                                                   
                                                            
                                                            
                                                   
                                                            
                                                            
                                                   
                                                            
                                                            
                                                   
                                                            
                                                            
                                                   
                                                            
                                                            
                                                   
                                                            
                                                            
                                                   
                                                               
                                                               
                                                               
                                                               
                                                               
                                                               
                                                               
                                                               
                                                               
                                                                  
                                                                  
                                                                  
                                                                  
                                                                  
                                                                  
                                                                  
                                                                  
                                                                  
                                                                  
                                                                  
                                                                  
                                                                  
                                                                  
                                                                  
                                                                  
                                                                  
                                                                  
   
                                                                                       
                                                                             
                                                                             
                                                                             
                                                                                  
                                                                                      
                                                                                      
                
    
__STATIC_INLINE void LL_ADC_SetAnalogWDMonitChannels(ADC_TypeDef *ADCx, uint32_t AWDy, uint32_t AWDChannelGroup)
{
                                                                                
                                                                                
                                                                                
                                                                                
  __IO uint32_t *preg = __ADC_PTR_REG_OFFSET(ADCx->CFGR,
                                             ((AWDy & ADC_AWD_CRX_REGOFFSET_MASK) >> ADC_AWD_CRX_REGOFFSET_POS)
                                             + ((AWDy & ADC_AWD_CR12_REGOFFSETGAP_MASK)
                                                * ADC_AWD_CR12_REGOFFSETGAP_VAL));

  MODIFY_REG(*preg,
             (AWDy & ADC_AWD_CR_ALL_CHANNEL_MASK),
             AWDChannelGroup & AWDy);
}

   
                                                      
                                                 
                                                                        
                                                                                
                                                                            
                                                              
                                                                 
                                                                    
                                                
                                                          
                                                              
                                                    
                                                                        
                          
                                                                      
                     
                                           
                                                                          
                                                                     
                                                                     
                                           
                                                  
                                                                                
                                                          
                                                                          
                                         
                                                                                 
                                                                            
                                             
                                                                               
                                                                   
                                                                      
                                                                                 
                                                                           
                                      
                                                                           
                      
                                                                       
                                                 
                                                                     
                                                                     
                                                                     
                                                                     
                                                                     
                                                                   
                             
                                                                   
                                 
                                     
                                     
   
                                                                      
                                                                          
                                                                  
                                                               
                            
                                                              
                                        
                                                            
                                                            
                                                     
                                                            
                                                            
                                                  
                                                            
                                                            
                                                  
                                                            
                                                            
                                                  
                                                            
                                                            
                                                  
                                                            
                                                            
                                                  
                                                            
                                                            
                                                  
                                                            
                                                            
                                                  
                                                            
                                                            
                                                  
                                                            
                                                            
                                                  
                                                            
                                                            
                                                  
                                                            
                                                            
                                                   
                                                            
                                                            
                                                   
                                                            
                                                            
                                                   
                                                            
                                                            
                                                   
                                                            
                                                            
                                                   
                                                            
                                                            
                                                   
                                                            
                                                            
                                                   
                                                            
                                                            
                                                   
                                                            
                                                            
                                                   
   
                                                                                     
    
__STATIC_INLINE uint32_t LL_ADC_GetAnalogWDMonitChannels(const ADC_TypeDef *ADCx, uint32_t AWDy)
{
  const __IO uint32_t *preg = __ADC_PTR_REG_OFFSET(ADCx->CFGR,
                                                   ((AWDy & ADC_AWD_CRX_REGOFFSET_MASK) >> ADC_AWD_CRX_REGOFFSET_POS)
                                                   + ((AWDy & ADC_AWD_CR12_REGOFFSETGAP_MASK)
                                                      * ADC_AWD_CR12_REGOFFSETGAP_VAL));

  uint32_t analog_wd_monit_channels = (READ_BIT(*preg, AWDy) & AWDy & ADC_AWD_CR_ALL_CHANNEL_MASK);

                                                                                   
                                                                                
                                                                                
                                                                                
  if (analog_wd_monit_channels != 0UL)
  {
    if (AWDy == LL_ADC_AWD1)
    {
      if ((analog_wd_monit_channels & ADC_CFGR_AWD1SGL) == 0UL)
      {
                                                
        analog_wd_monit_channels = ((analog_wd_monit_channels
                                     | (ADC_AWD_CR23_CHANNEL_MASK)
                                    )
                                    & (~(ADC_CFGR_AWD1CH))
                                   );
      }
      else
      {
                                             
        analog_wd_monit_channels = (analog_wd_monit_channels
                                    | (ADC_AWD2CR_AWD2CH_0 << (analog_wd_monit_channels >> ADC_CFGR_AWD1CH_Pos))
                                   );
      }
    }
    else
    {
      if ((analog_wd_monit_channels & ADC_AWD_CR23_CHANNEL_MASK) == ADC_AWD_CR23_CHANNEL_MASK)
      {
                                                
        analog_wd_monit_channels = (ADC_AWD_CR23_CHANNEL_MASK
                                    | ((ADC_CFGR_JAWD1EN | ADC_CFGR_AWD1EN))
                                   );
      }
      else
      {
                                             
                                                
        analog_wd_monit_channels = (analog_wd_monit_channels
                                    | (ADC_CFGR_JAWD1EN | ADC_CFGR_AWD1EN | ADC_CFGR_AWD1SGL)
                                    | (__LL_ADC_CHANNEL_TO_DECIMAL_NB(analog_wd_monit_channels) << ADC_CFGR_AWD1CH_Pos)
                                   );
      }
    }
  }

  return analog_wd_monit_channels;
}

   
                                                                       
                         
                                                                   
                                                             
                                                           
                                                                     
                                                                               
                                                                      
                     
                                           
                                                                          
                                                                     
                                                                     
                                           
                                                  
                                                                                
                                                          
                                                                          
                                         
                                                                                 
                                                                            
                                             
                                                                               
                                                                   
                                                                      
                                                                                 
                                                                           
                                      
                                                                              
                                                                             
                                                                               
                                                                         
                     
                                                                               
                                                                              
                                                                   
                                                                               
                                                                              
                                                                  
                                                                               
                                                                                 
                                                                                 
                                                                           
                      
                                                                       
                                                 
                                                                     
                                                                     
                                                                     
                                                                     
                                                                     
                                                                   
                             
                                                                   
                                 
                                 
                                 
                                                                                 
                                                                                
                
    
__STATIC_INLINE void LL_ADC_ConfigAnalogWDThresholds(ADC_TypeDef *ADCx, uint32_t AWDy, uint32_t AWDThresholdHighValue,
                                                     uint32_t AWDThresholdLowValue)
{
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
  __IO uint32_t *preg = __ADC_PTR_REG_OFFSET(ADCx->TR1,
                                             ((AWDy & ADC_AWD_TRX_REGOFFSET_MASK) >> ADC_AWD_TRX_REGOFFSET_POS));

  MODIFY_REG(*preg,
             ADC_TR1_HT1 | ADC_TR1_LT1,
             (AWDThresholdHighValue << ADC_TR1_HT1_BITOFFSET_POS) | AWDThresholdLowValue);
}

   
                                                                
                        
                                                                 
                                                                
                                                           
                                                                     
                                                                               
                                                                      
                     
                                           
                                                                          
                                                                     
                                                                     
                                           
                                                  
                                                                                
                                                          
                                                                          
                                         
                                                                                 
                                                                            
                                             
                                                                               
                                                                   
                                                                      
                                                                                 
                                                                           
                                      
                                                                              
                                                                             
                                                                               
                                                                         
                     
                                                                               
                                                                              
                                                                   
                                                                               
                                                                              
                                                                  
                                                                               
                                                                                 
                                                                                 
                                                                           
                      
                                                                       
                                                     
                                                                  
                                                                  
                                                                  
                                                                  
                                                                  
                                                                
                             
                                                                   
                                 
                                 
                                 
                                                                                   
                                               
                                              
                                                                             
                
    
__STATIC_INLINE void LL_ADC_SetAnalogWDThresholds(ADC_TypeDef *ADCx, uint32_t AWDy, uint32_t AWDThresholdsHighLow,
                                                  uint32_t AWDThresholdValue)
{
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
  __IO uint32_t *preg = __ADC_PTR_REG_OFFSET(ADCx->TR1,
                                             ((AWDy & ADC_AWD_TRX_REGOFFSET_MASK) >> ADC_AWD_TRX_REGOFFSET_POS));

  MODIFY_REG(*preg,
             AWDThresholdsHighLow,
             AWDThresholdValue << ((AWDThresholdsHighLow & ADC_AWD_TRX_BIT_HIGH_MASK) >> ADC_AWD_TRX_BIT_HIGH_SHIFT4));
}

   
                                                                      
                                                                      
                         
                                                                      
                                                                  
                               
                                                         
                                                           
                                                                     
                                                                               
                                                                  
                                                                  
                                                                  
                                                                  
                                                                  
                                                                
                             
                                                                   
                                 
                                 
                                 
                                                                                   
                                               
                                              
                                                    
                                                           
    
__STATIC_INLINE uint32_t LL_ADC_GetAnalogWDThresholds(const ADC_TypeDef *ADCx,
                                                      uint32_t AWDy, uint32_t AWDThresholdsHighLow)
{
  const __IO uint32_t *preg = __ADC_PTR_REG_OFFSET(ADCx->TR1,
                                                   ((AWDy & ADC_AWD_TRX_REGOFFSET_MASK) >> ADC_AWD_TRX_REGOFFSET_POS));

  return (uint32_t)(READ_BIT(*preg,
                             (AWDThresholdsHighLow | ADC_TR1_LT1))
                    >> (((AWDThresholdsHighLow & ADC_AWD_TRX_BIT_HIGH_MASK) >> ADC_AWD_TRX_BIT_HIGH_SHIFT4)
                        & ~(AWDThresholdsHighLow & ADC_TR1_LT1)));
}

   
      
    

                                                                                                           
      
    

   
                                                                          
                                                                         
                                                             
                                                               
                                                                
                                                           
                                                                  
                                       
                                                                           
                      
                                                                       
                                                 
                                                                 
                                                                 
                                                               
                             
                                                                       
                                        
                                                      
                                                    
                                             
                                                    
                
    
__STATIC_INLINE void LL_ADC_SetOverSamplingScope(ADC_TypeDef *ADCx, uint32_t OvsScope)
{
  MODIFY_REG(ADCx->CFGR2, ADC_CFGR2_ROVSE | ADC_CFGR2_JOVSE | ADC_CFGR2_ROVSM, OvsScope);
}

   
                                                                          
                                                                         
                                                             
                                                               
                                                                
                                                           
                                                                  
                                       
                                                                 
                                                                 
                                                               
                             
                                                              
                                        
                                                      
                                                    
                                             
                                                    
    
__STATIC_INLINE uint32_t LL_ADC_GetOverSamplingScope(const ADC_TypeDef *ADCx)
{
  return (uint32_t)(READ_BIT(ADCx->CFGR2, ADC_CFGR2_ROVSE | ADC_CFGR2_JOVSE | ADC_CFGR2_ROVSM));
}

   
                                                                    
                                      
                                                                 
                                                                    
                                      
                                                                       
                              
                                                                           
                      
                                                                       
                             
                                                                 
                                                                  
                                                          
                                                                 
                             
                                                                                  
                                         
                                            
                
    
__STATIC_INLINE void LL_ADC_SetOverSamplingDiscont(ADC_TypeDef *ADCx, uint32_t OverSamplingDiscont)
{
  MODIFY_REG(ADCx->CFGR2, ADC_CFGR2_TROVS, OverSamplingDiscont);
}

   
                                                                    
                                      
                                                                 
                                                                    
                                      
                                                                       
                              
                                                                 
                             
                                                              
                                         
                                            
    
__STATIC_INLINE uint32_t LL_ADC_GetOverSamplingDiscont(const ADC_TypeDef *ADCx)
{
  return (uint32_t)(READ_BIT(ADCx->CFGR2, ADC_CFGR2_TROVS));
}

   
                                
                                                            
                                                                        
                   
                   
                                                                           
                      
                                                                       
                                                 
                                                                         
                                                                       
                             
                                                                    
                                        
                                        
                                        
                                         
                                         
                                         
                                          
                                          
                                                                    
                                           
                                              
                                              
                                              
                                              
                                              
                                              
                                              
                                              
                
    
__STATIC_INLINE void LL_ADC_ConfigOverSamplingRatioShift(ADC_TypeDef *ADCx, uint32_t Ratio, uint32_t Shift)
{
  MODIFY_REG(ADCx->CFGR2, (ADC_CFGR2_OVSS | ADC_CFGR2_OVSR), (Shift | Ratio));
}

   
                                      
                                                           
                                                               
                             
                                                                    
                                        
                                        
                                        
                                         
                                         
                                         
                                          
                                          
    
__STATIC_INLINE uint32_t LL_ADC_GetOverSamplingRatio(const ADC_TypeDef *ADCx)
{
  return (uint32_t)(READ_BIT(ADCx->CFGR2, ADC_CFGR2_OVSR));
}

   
                                      
                                                           
                                                               
                             
                                                                    
                                           
                                              
                                              
                                              
                                              
                                              
                                              
                                              
                                              
    
__STATIC_INLINE uint32_t LL_ADC_GetOverSamplingShift(const ADC_TypeDef *ADCx)
{
  return (uint32_t)(READ_BIT(ADCx->CFGR2, ADC_CFGR2_OVSS));
}

   
      
    

                                                                                                      
      
    

#if defined(ADC_MULTIMODE_SUPPORT)
   
                                                                          
                                                                  
                                                                    
                                                         
                                      
                                                                           
                      
                                                                       
                                                                                 
                                                 
                                                           
                                                       
                                            
                                                                                                                 
                                                                        
                                              
                                                  
                                                  
                                                  
                                                  
                                                       
                                                       
                                                       
                
    
__STATIC_INLINE void LL_ADC_SetMultimode(ADC_Common_TypeDef *ADCxy_COMMON, uint32_t Multimode)
{
  MODIFY_REG(ADCxy_COMMON->CCR, ADC_CCR_DUAL, Multimode);
}

   
                                                                          
                                                                  
                                                                    
                                                         
                                      
                                                       
                                            
                                                                                                                 
                                                              
                                              
                                                  
                                                  
                                                  
                                                  
                                                       
                                                       
                                                       
    
__STATIC_INLINE uint32_t LL_ADC_GetMultimode(const ADC_Common_TypeDef *ADCxy_COMMON)
{
  return (uint32_t)(READ_BIT(ADCxy_COMMON->CCR, ADC_CCR_DUAL));
}

   
                                                                   
                               
                                                             
                                                                  
                                  
                                                         
                                                                    
                                            
                                                                             
                                                          
                                          
                                                                              
                                                                  
                                                              
                               
                                                                          
                                                                          
                              
                                                                               
                                                                
                                                       
                                                      
                                                                      
                                                        
                                                                         
                                                                 
                                                              
                                                     
                                                         
                                                                           
                      
                                                                      
                                                                    
                                                                
                                                              
                                            
                                                                                                                 
                                                                               
                                                   
                                                          
                                                        
                                                          
                                                        
                
    
__STATIC_INLINE void LL_ADC_SetMultiDMATransfer(ADC_Common_TypeDef *ADCxy_COMMON, uint32_t MultiDMATransfer)
{
  MODIFY_REG(ADCxy_COMMON->CCR, ADC_CCR_MDMA | ADC_CCR_DMACFG, MultiDMATransfer);
}

   
                                                                   
                               
                                                             
                                                                  
                                  
                                                         
                                                                    
                                            
                                                                             
                                                          
                                          
                                                                              
                                                                  
                                                              
                               
                                                                          
                                                                          
                              
                                                                               
                                                                
                                                       
                                                      
                                                                      
                                                        
                                                                         
                                                                 
                                                              
                                                     
                                                         
                                                                
                                                              
                                            
                                                                                                                 
                                                              
                                                   
                                                          
                                                        
                                                          
                                                        
    
__STATIC_INLINE uint32_t LL_ADC_GetMultiDMATransfer(const ADC_Common_TypeDef *ADCxy_COMMON)
{
  return (uint32_t)(READ_BIT(ADCxy_COMMON->CCR, ADC_CCR_MDMA | ADC_CCR_DMACFG));
}

   
                                                              
                                                               
                                                                         
                                                                         
                                                                         
                                                                         
                                                                           
                      
                                                                       
                                                                                 
                                                              
                                                           
                                                                   
                                            
                                                                                                                 
                                                                                    
                                                      
                                                       
                                                       
                                                       
                                                       
                                                            
                                                            
                                                            
                                                            
                                                            
                                                            
                                                            
   
                                                                                 
                                                                              
                                                                      
                
    
__STATIC_INLINE void LL_ADC_SetMultiTwoSamplingDelay(ADC_Common_TypeDef *ADCxy_COMMON, uint32_t MultiTwoSamplingDelay)
{
  MODIFY_REG(ADCxy_COMMON->CCR, ADC_CCR_DELAY, MultiTwoSamplingDelay);
}

   
                                                              
                                                                   
                                            
                                                                                                                 
                                                              
                                                      
                                                       
                                                       
                                                       
                                                       
                                                            
                                                            
                                                            
                                                            
                                                            
                                                            
                                                            
   
                                                                                 
                                                                              
                                                                      
    
__STATIC_INLINE uint32_t LL_ADC_GetMultiTwoSamplingDelay(const ADC_Common_TypeDef *ADCxy_COMMON)
{
  return (uint32_t)(READ_BIT(ADCxy_COMMON->CCR, ADC_CCR_DELAY));
}
#endif                            

   
      
    
                                                                                                 
      
    
                                                                                
                                                                                
__STATIC_INLINE void LL_ADC_REG_SetTrigSource(ADC_TypeDef *ADCx, uint32_t TriggerSource)
{
  LL_ADC_REG_SetTriggerSource(ADCx, TriggerSource);
}
__STATIC_INLINE void LL_ADC_INJ_SetTrigSource(ADC_TypeDef *ADCx, uint32_t TriggerSource)
{
  LL_ADC_INJ_SetTriggerSource(ADCx, TriggerSource);
}

   
      
    

                                                                                                
      
    

   
                                                      
                                                                                
                                                                              
                                                                                 
                                                                             
                                                                           
                      
                                     
                                                              
                             
                
    
__STATIC_INLINE void LL_ADC_EnableDeepPowerDown(ADC_TypeDef *ADCx)
{
                                                                                
                                                                                
                                                                                
  MODIFY_REG(ADCx->CR,
             ADC_CR_BITS_PROPERTY_RS,
             ADC_CR_DEEPPWD);
}

   
                                             
                                                                                
                                                                              
                                                                                 
                                                                             
                                                                           
                      
                                     
                                                               
                             
                
    
__STATIC_INLINE void LL_ADC_DisableDeepPowerDown(ADC_TypeDef *ADCx)
{
                                                                                
                                                                                
                                                                                
  CLEAR_BIT(ADCx->CR, (ADC_CR_DEEPPWD | ADC_CR_BITS_PROPERTY_RS));
}

   
                                                                
                                                                 
                             
                                                                          
    
__STATIC_INLINE uint32_t LL_ADC_IsDeepPowerDownEnabled(const ADC_TypeDef *ADCx)
{
  return ((READ_BIT(ADCx->CR, ADC_CR_DEEPPWD) == (ADC_CR_DEEPPWD)) ? 1UL : 0UL);
}

   
                                                           
                                                                              
                                                                    
                                                                          
                                                               
                                                                      
                                                                           
                      
                                     
                                                                  
                             
                
    
__STATIC_INLINE void LL_ADC_EnableInternalRegulator(ADC_TypeDef *ADCx)
{
                                                                                
                                                                                
                                                                                
  MODIFY_REG(ADCx->CR,
             ADC_CR_BITS_PROPERTY_RS,
             ADC_CR_ADVREGEN);
}

   
                                                   
                                                                           
                      
                                     
                                                                   
                             
                
    
__STATIC_INLINE void LL_ADC_DisableInternalRegulator(ADC_TypeDef *ADCx)
{
  CLEAR_BIT(ADCx->CR, (ADC_CR_ADVREGEN | ADC_CR_BITS_PROPERTY_RS));
}

   
                                                                           
                                                                     
                             
                                                                                
    
__STATIC_INLINE uint32_t LL_ADC_IsInternalRegulatorEnabled(const ADC_TypeDef *ADCx)
{
  return ((READ_BIT(ADCx->CR, ADC_CR_ADVREGEN) == (ADC_CR_ADVREGEN)) ? 1UL : 0UL);
}

   
                                             
                                                               
                                                                             
                                 
                                                       
                                                                               
                                                           
                                                                   
                                                                           
                      
                                                                                
                                                 
                             
                
    
__STATIC_INLINE void LL_ADC_Enable(ADC_TypeDef *ADCx)
{
                                                                                
                                                                                
                                                                                
  MODIFY_REG(ADCx->CR,
             ADC_CR_BITS_PROPERTY_RS,
             ADC_CR_ADEN);
}

   
                                              
                                                                           
                      
                                                                                 
                                                 
                                                  
                             
                
    
__STATIC_INLINE void LL_ADC_Disable(ADC_TypeDef *ADCx)
{
                                                                                
                                                                                
                                                                                
  MODIFY_REG(ADCx->CR,
             ADC_CR_BITS_PROPERTY_RS,
             ADC_CR_ADDIS);
}

   
                                                       
                                                                               
                                                           
                                                                   
                                                    
                             
                                                  
    
__STATIC_INLINE uint32_t LL_ADC_IsEnabled(const ADC_TypeDef *ADCx)
{
  return ((READ_BIT(ADCx->CR, ADC_CR_ADEN) == (ADC_CR_ADEN)) ? 1UL : 0UL);
}

   
                                                        
                                                           
                             
                                               
    
__STATIC_INLINE uint32_t LL_ADC_IsDisableOngoing(const ADC_TypeDef *ADCx)
{
  return ((READ_BIT(ADCx->CR, ADC_CR_ADDIS) == (ADC_CR_ADDIS)) ? 1UL : 0UL);
}

   
                                                          
                                                                           
                                                                      
                                                                       
                                                                       
                                                         
                                                        
                                               
                                                                
                                                                         
                                        
                                                                           
                      
                                     
                                                             
                                                           
                             
                                                                         
                                         
                                               
                
    
__STATIC_INLINE void LL_ADC_StartCalibration(ADC_TypeDef *ADCx, uint32_t SingleDiff)
{
                                                                                
                                                                                
                                                                                
  MODIFY_REG(ADCx->CR,
             ADC_CR_ADCALDIF | ADC_CR_BITS_PROPERTY_RS,
             ADC_CR_ADCAL | (SingleDiff & ADC_SINGLEDIFF_CALIB_START_MASK));
}

   
                                      
                                                               
                             
                                                                
    
__STATIC_INLINE uint32_t LL_ADC_IsCalibrationOnGoing(const ADC_TypeDef *ADCx)
{
  return ((READ_BIT(ADCx->CR, ADC_CR_ADCAL) == (ADC_CR_ADCAL)) ? 1UL : 0UL);
}

   
      
    

                                                                                                      
      
    

   
                                               
                                                                    
                                                             
                                                                           
                                 
                                                                             
                                                                             
                                                         
                                                                           
                      
                                                                             
                                                                      
                                                 
                                                              
                             
                
    
__STATIC_INLINE void LL_ADC_REG_StartConversion(ADC_TypeDef *ADCx)
{
                                                                                
                                                                                
                                                                                
  MODIFY_REG(ADCx->CR,
             ADC_CR_BITS_PROPERTY_RS,
             ADC_CR_ADSTART);
}

   
                                              
                                                                           
                      
                                                                          
                                                 
                                                             
                             
                
    
__STATIC_INLINE void LL_ADC_REG_StopConversion(ADC_TypeDef *ADCx)
{
                                                                                
                                                                                
                                                                                
  MODIFY_REG(ADCx->CR,
             ADC_CR_BITS_PROPERTY_RS,
             ADC_CR_ADSTP);
}

   
                                                   
                                                                  
                             
                                                              
    
__STATIC_INLINE uint32_t LL_ADC_REG_IsConversionOngoing(const ADC_TypeDef *ADCx)
{
  return ((READ_BIT(ADCx->CR, ADC_CR_ADSTART) == (ADC_CR_ADSTART)) ? 1UL : 0UL);
}

   
                                                                  
                                                                      
                             
                                                                              
    
__STATIC_INLINE uint32_t LL_ADC_REG_IsStopConversionOngoing(const ADC_TypeDef *ADCx)
{
  return ((READ_BIT(ADCx->CR, ADC_CR_ADSTP) == (ADC_CR_ADSTP)) ? 1UL : 0UL);
}

   
                                                                
                                                           
                                                              
                                       
                                                                   
                             
                                                                     
    
__STATIC_INLINE uint32_t LL_ADC_REG_ReadConversionData32(const ADC_TypeDef *ADCx)
{
  return (uint32_t)(READ_BIT(ADCx->DR, ADC_DR_RDATA));
}

   
                                                                
                                   
                                                               
                                                                
                                                                
                                                                   
                             
                                                           
    
__STATIC_INLINE uint16_t LL_ADC_REG_ReadConversionData12(const ADC_TypeDef *ADCx)
{
  return (uint16_t)(READ_BIT(ADCx->DR, ADC_DR_RDATA));
}

   
                                                                
                                   
                                                               
                                                                
                                                                
                                                                   
                             
                                                           
    
__STATIC_INLINE uint16_t LL_ADC_REG_ReadConversionData10(const ADC_TypeDef *ADCx)
{
  return (uint16_t)(READ_BIT(ADCx->DR, ADC_DR_RDATA));
}

   
                                                                
                                  
                                                               
                                                                
                                                                
                                                                  
                             
                                                         
    
__STATIC_INLINE uint8_t LL_ADC_REG_ReadConversionData8(const ADC_TypeDef *ADCx)
{
  return (uint8_t)(READ_BIT(ADCx->DR, ADC_DR_RDATA));
}

   
                                                                
                                  
                                                               
                                                                
                                                                
                                                                  
                             
                                                         
    
__STATIC_INLINE uint8_t LL_ADC_REG_ReadConversionData6(const ADC_TypeDef *ADCx)
{
  return (uint8_t)(READ_BIT(ADCx->DR, ADC_DR_RDATA));
}

#if defined(ADC_MULTIMODE_SUPPORT)
   
                                                                      
                                                               
                                                                            
                                                              
                                                     
                                                         
                                                                
                                                                  
                                                                           
                        
                                                                          
                                                                        
                                            
                                                                                                                 
                                                                             
                                         
                                        
                                               
                                                                     
    
__STATIC_INLINE uint32_t LL_ADC_REG_ReadMultiConversionData32(const ADC_Common_TypeDef *ADCxy_COMMON,
                                                              uint32_t ConversionData)
{
  return (uint32_t)(READ_BIT(ADCxy_COMMON->CDR,
                             ConversionData)
                    >> (POSITION_VAL(ConversionData) & 0x1FUL)
                   );
}
#endif                            

   
      
    

                                                                                                        
      
    

   
                                                
                                                                    
                                                             
                                                                           
                                 
                                                                             
                                                                             
                                                         
                                                                           
                      
                                                                              
                                                                       
                                                 
                                                              
                             
                
    
__STATIC_INLINE void LL_ADC_INJ_StartConversion(ADC_TypeDef *ADCx)
{
                                                                                
                                                                                
                                                                                
  MODIFY_REG(ADCx->CR,
             ADC_CR_BITS_PROPERTY_RS,
             ADC_CR_JADSTART);
}

   
                                               
                                                                           
                      
                                                                           
                                                 
                                                             
                             
                
    
__STATIC_INLINE void LL_ADC_INJ_StopConversion(ADC_TypeDef *ADCx)
{
                                                                                
                                                                                
                                                                                
  MODIFY_REG(ADCx->CR,
             ADC_CR_BITS_PROPERTY_RS,
             ADC_CR_JADSTP);
}

   
                                                    
                                                                  
                             
                                                               
    
__STATIC_INLINE uint32_t LL_ADC_INJ_IsConversionOngoing(const ADC_TypeDef *ADCx)
{
  return ((READ_BIT(ADCx->CR, ADC_CR_JADSTART) == (ADC_CR_JADSTART)) ? 1UL : 0UL);
}

   
                                                                   
                                                                      
                             
                                                                               
    
__STATIC_INLINE uint32_t LL_ADC_INJ_IsStopConversionOngoing(const ADC_TypeDef *ADCx)
{
  return ((READ_BIT(ADCx->CR, ADC_CR_JADSTP) == (ADC_CR_JADSTP)) ? 1UL : 0UL);
}

   
                                                                 
                                                           
                                                              
                                       
                                                                     
                                                                     
                                                                     
                                                                   
                             
                                                                   
                                       
                                       
                                       
                                       
                                                                     
    
__STATIC_INLINE uint32_t LL_ADC_INJ_ReadConversionData32(const ADC_TypeDef *ADCx, uint32_t Rank)
{
  const __IO uint32_t *preg = __ADC_PTR_REG_OFFSET(ADCx->JDR1,
                                                   ((Rank & ADC_INJ_JDRX_REGOFFSET_MASK) >> ADC_JDRX_REGOFFSET_POS));

  return (uint32_t)(READ_BIT(*preg,
                             ADC_JDR1_JDATA)
                   );
}

   
                                                                 
                                   
                                                               
                                                                
                                                                
                                                                     
                                                                     
                                                                     
                                                                   
                             
                                                                   
                                       
                                       
                                       
                                       
                                                           
    
__STATIC_INLINE uint16_t LL_ADC_INJ_ReadConversionData12(const ADC_TypeDef *ADCx, uint32_t Rank)
{
  const __IO uint32_t *preg = __ADC_PTR_REG_OFFSET(ADCx->JDR1,
                                                   ((Rank & ADC_INJ_JDRX_REGOFFSET_MASK) >> ADC_JDRX_REGOFFSET_POS));

  return (uint16_t)(READ_BIT(*preg,
                             ADC_JDR1_JDATA)
                   );
}

   
                                                                 
                                   
                                                               
                                                                
                                                                
                                                                     
                                                                     
                                                                     
                                                                   
                             
                                                                   
                                       
                                       
                                       
                                       
                                                           
    
__STATIC_INLINE uint16_t LL_ADC_INJ_ReadConversionData10(const ADC_TypeDef *ADCx, uint32_t Rank)
{
  const __IO uint32_t *preg = __ADC_PTR_REG_OFFSET(ADCx->JDR1,
                                                   ((Rank & ADC_INJ_JDRX_REGOFFSET_MASK) >> ADC_JDRX_REGOFFSET_POS));

  return (uint16_t)(READ_BIT(*preg,
                             ADC_JDR1_JDATA)
                   );
}

   
                                                                 
                                  
                                                               
                                                                
                                                                
                                                                    
                                                                    
                                                                    
                                                                  
                             
                                                                   
                                       
                                       
                                       
                                       
                                                         
    
__STATIC_INLINE uint8_t LL_ADC_INJ_ReadConversionData8(const ADC_TypeDef *ADCx, uint32_t Rank)
{
  const __IO uint32_t *preg = __ADC_PTR_REG_OFFSET(ADCx->JDR1,
                                                   ((Rank & ADC_INJ_JDRX_REGOFFSET_MASK) >> ADC_JDRX_REGOFFSET_POS));

  return (uint8_t)(READ_BIT(*preg,
                            ADC_JDR1_JDATA)
                  );
}

   
                                                                 
                                  
                                                               
                                                                
                                                                
                                                                    
                                                                    
                                                                    
                                                                  
                             
                                                                   
                                       
                                       
                                       
                                       
                                                         
    
__STATIC_INLINE uint8_t LL_ADC_INJ_ReadConversionData6(const ADC_TypeDef *ADCx, uint32_t Rank)
{
  const __IO uint32_t *preg = __ADC_PTR_REG_OFFSET(ADCx->JDR1,
                                                   ((Rank & ADC_INJ_JDRX_REGOFFSET_MASK) >> ADC_JDRX_REGOFFSET_POS));

  return (uint8_t)(READ_BIT(*preg,
                            ADC_JDR1_JDATA)
                  );
}

   
      
    

                                                           
      
    

   
                               
                                                                               
                                                           
                                                                   
                                                             
                             
                                  
    
__STATIC_INLINE uint32_t LL_ADC_IsActiveFlag_ADRDY(const ADC_TypeDef *ADCx)
{
  return ((READ_BIT(ADCx->ISR, LL_ADC_FLAG_ADRDY) == (LL_ADC_FLAG_ADRDY)) ? 1UL : 0UL);
}

   
                                                                 
                                                           
                             
                                  
    
__STATIC_INLINE uint32_t LL_ADC_IsActiveFlag_EOC(const ADC_TypeDef *ADCx)
{
  return ((READ_BIT(ADCx->ISR, ADC_ISR_EOC) == (ADC_ISR_EOC)) ? 1UL : 0UL);
}

   
                                                                   
                                                           
                             
                                  
    
__STATIC_INLINE uint32_t LL_ADC_IsActiveFlag_EOS(const ADC_TypeDef *ADCx)
{
  return ((READ_BIT(ADCx->ISR, LL_ADC_FLAG_EOS) == (LL_ADC_FLAG_EOS)) ? 1UL : 0UL);
}

   
                                               
                                                           
                             
                                  
    
__STATIC_INLINE uint32_t LL_ADC_IsActiveFlag_OVR(const ADC_TypeDef *ADCx)
{
  return ((READ_BIT(ADCx->ISR, LL_ADC_FLAG_OVR) == (LL_ADC_FLAG_OVR)) ? 1UL : 0UL);
}

   
                                                             
                                                             
                             
                                  
    
__STATIC_INLINE uint32_t LL_ADC_IsActiveFlag_EOSMP(const ADC_TypeDef *ADCx)
{
  return ((READ_BIT(ADCx->ISR, LL_ADC_FLAG_EOSMP) == (LL_ADC_FLAG_EOSMP)) ? 1UL : 0UL);
}

   
                                                                  
                                                            
                             
                                  
    
__STATIC_INLINE uint32_t LL_ADC_IsActiveFlag_JEOC(const ADC_TypeDef *ADCx)
{
  return ((READ_BIT(ADCx->ISR, LL_ADC_FLAG_JEOC) == (LL_ADC_FLAG_JEOC)) ? 1UL : 0UL);
}

   
                                                                    
                                                            
                             
                                  
    
__STATIC_INLINE uint32_t LL_ADC_IsActiveFlag_JEOS(const ADC_TypeDef *ADCx)
{
  return ((READ_BIT(ADCx->ISR, LL_ADC_FLAG_JEOS) == (LL_ADC_FLAG_JEOS)) ? 1UL : 0UL);
}

   
                                                                
                                                             
                             
                                  
    
__STATIC_INLINE uint32_t LL_ADC_IsActiveFlag_JQOVF(const ADC_TypeDef *ADCx)
{
  return ((READ_BIT(ADCx->ISR, LL_ADC_FLAG_JQOVF) == (LL_ADC_FLAG_JQOVF)) ? 1UL : 0UL);
}

   
                                               
                                                            
                             
                                  
    
__STATIC_INLINE uint32_t LL_ADC_IsActiveFlag_AWD1(const ADC_TypeDef *ADCx)
{
  return ((READ_BIT(ADCx->ISR, LL_ADC_FLAG_AWD1) == (LL_ADC_FLAG_AWD1)) ? 1UL : 0UL);
}

   
                                           
                                                            
                             
                                  
    
__STATIC_INLINE uint32_t LL_ADC_IsActiveFlag_AWD2(const ADC_TypeDef *ADCx)
{
  return ((READ_BIT(ADCx->ISR, LL_ADC_FLAG_AWD2) == (LL_ADC_FLAG_AWD2)) ? 1UL : 0UL);
}

   
                                           
                                                            
                             
                                  
    
__STATIC_INLINE uint32_t LL_ADC_IsActiveFlag_AWD3(const ADC_TypeDef *ADCx)
{
  return ((READ_BIT(ADCx->ISR, LL_ADC_FLAG_AWD3) == (LL_ADC_FLAG_AWD3)) ? 1UL : 0UL);
}

   
                                 
                                                                               
                                                           
                                                                   
                                                          
                             
                
    
__STATIC_INLINE void LL_ADC_ClearFlag_ADRDY(ADC_TypeDef *ADCx)
{
  WRITE_REG(ADCx->ISR, LL_ADC_FLAG_ADRDY);
}

   
                                                                   
                                                        
                             
                
    
__STATIC_INLINE void LL_ADC_ClearFlag_EOC(ADC_TypeDef *ADCx)
{
  WRITE_REG(ADCx->ISR, LL_ADC_FLAG_EOC);
}

   
                                                                     
                                                        
                             
                
    
__STATIC_INLINE void LL_ADC_ClearFlag_EOS(ADC_TypeDef *ADCx)
{
  WRITE_REG(ADCx->ISR, LL_ADC_FLAG_EOS);
}

   
                                                 
                                                        
                             
                
    
__STATIC_INLINE void LL_ADC_ClearFlag_OVR(ADC_TypeDef *ADCx)
{
  WRITE_REG(ADCx->ISR, LL_ADC_FLAG_OVR);
}

   
                                                               
                                                          
                             
                
    
__STATIC_INLINE void LL_ADC_ClearFlag_EOSMP(ADC_TypeDef *ADCx)
{
  WRITE_REG(ADCx->ISR, LL_ADC_FLAG_EOSMP);
}

   
                                                                    
                                                         
                             
                
    
__STATIC_INLINE void LL_ADC_ClearFlag_JEOC(ADC_TypeDef *ADCx)
{
  WRITE_REG(ADCx->ISR, LL_ADC_FLAG_JEOC);
}

   
                                                                      
                                                         
                             
                
    
__STATIC_INLINE void LL_ADC_ClearFlag_JEOS(ADC_TypeDef *ADCx)
{
  WRITE_REG(ADCx->ISR, LL_ADC_FLAG_JEOS);
}

   
                                                                  
                                                          
                             
                
    
__STATIC_INLINE void LL_ADC_ClearFlag_JQOVF(ADC_TypeDef *ADCx)
{
  WRITE_REG(ADCx->ISR, LL_ADC_FLAG_JQOVF);
}

   
                                             
                                                         
                             
                
    
__STATIC_INLINE void LL_ADC_ClearFlag_AWD1(ADC_TypeDef *ADCx)
{
  WRITE_REG(ADCx->ISR, LL_ADC_FLAG_AWD1);
}

   
                                             
                                                         
                             
                
    
__STATIC_INLINE void LL_ADC_ClearFlag_AWD2(ADC_TypeDef *ADCx)
{
  WRITE_REG(ADCx->ISR, LL_ADC_FLAG_AWD2);
}

   
                                             
                                                         
                             
                
    
__STATIC_INLINE void LL_ADC_ClearFlag_AWD3(ADC_TypeDef *ADCx)
{
  WRITE_REG(ADCx->ISR, LL_ADC_FLAG_AWD3);
}

#if defined(ADC_MULTIMODE_SUPPORT)
   
                                                           
                                                                 
                                            
                                                                                                                 
                                  
    
__STATIC_INLINE uint32_t LL_ADC_IsActiveFlag_MST_ADRDY(const ADC_Common_TypeDef *ADCxy_COMMON)
{
  return ((READ_BIT(ADCxy_COMMON->CSR, LL_ADC_FLAG_ADRDY_MST) == (LL_ADC_FLAG_ADRDY_MST)) ? 1UL : 0UL);
}

   
                                                          
                                                                 
                                            
                                                                                                                 
                                  
    
__STATIC_INLINE uint32_t LL_ADC_IsActiveFlag_SLV_ADRDY(const ADC_Common_TypeDef *ADCxy_COMMON)
{
  return ((READ_BIT(ADCxy_COMMON->CSR, LL_ADC_FLAG_ADRDY_SLV) == (LL_ADC_FLAG_ADRDY_SLV)) ? 1UL : 0UL);
}

   
                                                                                             
                                                               
                                            
                                                                                                                 
                                  
    
__STATIC_INLINE uint32_t LL_ADC_IsActiveFlag_MST_EOC(const ADC_Common_TypeDef *ADCxy_COMMON)
{
  return ((READ_BIT(ADCxy_COMMON->CSR, LL_ADC_FLAG_EOC_SLV) == (LL_ADC_FLAG_EOC_SLV)) ? 1UL : 0UL);
}

   
                                                                                            
                                                               
                                            
                                                                                                                 
                                  
    
__STATIC_INLINE uint32_t LL_ADC_IsActiveFlag_SLV_EOC(const ADC_Common_TypeDef *ADCxy_COMMON)
{
  return ((READ_BIT(ADCxy_COMMON->CSR, LL_ADC_FLAG_EOC_SLV) == (LL_ADC_FLAG_EOC_SLV)) ? 1UL : 0UL);
}

   
                                                                                               
                                                               
                                            
                                                                                                                 
                                  
    
__STATIC_INLINE uint32_t LL_ADC_IsActiveFlag_MST_EOS(const ADC_Common_TypeDef *ADCxy_COMMON)
{
  return ((READ_BIT(ADCxy_COMMON->CSR, LL_ADC_FLAG_EOS_MST) == (LL_ADC_FLAG_EOS_MST)) ? 1UL : 0UL);
}

   
                                                                                              
                                                               
                                            
                                                                                                                 
                                  
    
__STATIC_INLINE uint32_t LL_ADC_IsActiveFlag_SLV_EOS(const ADC_Common_TypeDef *ADCxy_COMMON)
{
  return ((READ_BIT(ADCxy_COMMON->CSR, LL_ADC_FLAG_EOS_SLV) == (LL_ADC_FLAG_EOS_SLV)) ? 1UL : 0UL);
}

   
                                                                           
                                                               
                                            
                                                                                                                 
                                  
    
__STATIC_INLINE uint32_t LL_ADC_IsActiveFlag_MST_OVR(const ADC_Common_TypeDef *ADCxy_COMMON)
{
  return ((READ_BIT(ADCxy_COMMON->CSR, LL_ADC_FLAG_OVR_MST) == (LL_ADC_FLAG_OVR_MST)) ? 1UL : 0UL);
}

   
                                                                          
                                                               
                                            
                                                                                                                 
                                  
    
__STATIC_INLINE uint32_t LL_ADC_IsActiveFlag_SLV_OVR(const ADC_Common_TypeDef *ADCxy_COMMON)
{
  return ((READ_BIT(ADCxy_COMMON->CSR, LL_ADC_FLAG_OVR_SLV) == (LL_ADC_FLAG_OVR_SLV)) ? 1UL : 0UL);
}

   
                                                                                   
                                                                 
                                            
                                                                                                                 
                                  
    
__STATIC_INLINE uint32_t LL_ADC_IsActiveFlag_MST_EOSMP(const ADC_Common_TypeDef *ADCxy_COMMON)
{
  return ((READ_BIT(ADCxy_COMMON->CSR, LL_ADC_FLAG_EOSMP_MST) == (LL_ADC_FLAG_EOSMP_MST)) ? 1UL : 0UL);
}

   
                                                                                  
                                                                 
                                            
                                                                                                                 
                                  
    
__STATIC_INLINE uint32_t LL_ADC_IsActiveFlag_SLV_EOSMP(const ADC_Common_TypeDef *ADCxy_COMMON)
{
  return ((READ_BIT(ADCxy_COMMON->CSR, LL_ADC_FLAG_EOSMP_SLV) == (LL_ADC_FLAG_EOSMP_SLV)) ? 1UL : 0UL);
}

   
                                                                                              
                                                                
                                            
                                                                                                                 
                                  
    
__STATIC_INLINE uint32_t LL_ADC_IsActiveFlag_MST_JEOC(const ADC_Common_TypeDef *ADCxy_COMMON)
{
  return ((READ_BIT(ADCxy_COMMON->CSR, LL_ADC_FLAG_JEOC_MST) == (LL_ADC_FLAG_JEOC_MST)) ? 1UL : 0UL);
}

   
                                                                                             
                                                                
                                            
                                                                                                                 
                                  
    
__STATIC_INLINE uint32_t LL_ADC_IsActiveFlag_SLV_JEOC(const ADC_Common_TypeDef *ADCxy_COMMON)
{
  return ((READ_BIT(ADCxy_COMMON->CSR, LL_ADC_FLAG_JEOC_SLV) == (LL_ADC_FLAG_JEOC_SLV)) ? 1UL : 0UL);
}

   
                                                                                                
                                                                
                                            
                                                                                                                 
                                  
    
__STATIC_INLINE uint32_t LL_ADC_IsActiveFlag_MST_JEOS(const ADC_Common_TypeDef *ADCxy_COMMON)
{
  return ((READ_BIT(ADCxy_COMMON->CSR, LL_ADC_FLAG_JEOS_MST) == (LL_ADC_FLAG_JEOS_MST)) ? 1UL : 0UL);
}

   
                                                                                               
                                                                
                                            
                                                                                                                 
                                  
    
__STATIC_INLINE uint32_t LL_ADC_IsActiveFlag_SLV_JEOS(const ADC_Common_TypeDef *ADCxy_COMMON)
{
  return ((READ_BIT(ADCxy_COMMON->CSR, LL_ADC_FLAG_JEOS_SLV) == (LL_ADC_FLAG_JEOS_SLV)) ? 1UL : 0UL);
}

   
                                                                                           
                                                                 
                                            
                                                                                                                 
                                  
    
__STATIC_INLINE uint32_t LL_ADC_IsActiveFlag_MST_JQOVF(const ADC_Common_TypeDef *ADCxy_COMMON)
{
  return ((READ_BIT(ADCxy_COMMON->CSR, LL_ADC_FLAG_JQOVF_MST) == (LL_ADC_FLAG_JQOVF_MST)) ? 1UL : 0UL);
}

   
                                                                                          
                                                                 
                                            
                                                                                                                 
                                  
    
__STATIC_INLINE uint32_t LL_ADC_IsActiveFlag_SLV_JQOVF(const ADC_Common_TypeDef *ADCxy_COMMON)
{
  return ((READ_BIT(ADCxy_COMMON->CSR, LL_ADC_FLAG_JQOVF_SLV) == (LL_ADC_FLAG_JQOVF_SLV)) ? 1UL : 0UL);
}

   
                                                                       
                                                                
                                            
                                                                                                                 
                                  
    
__STATIC_INLINE uint32_t LL_ADC_IsActiveFlag_MST_AWD1(const ADC_Common_TypeDef *ADCxy_COMMON)
{
  return ((READ_BIT(ADCxy_COMMON->CSR, LL_ADC_FLAG_AWD1_MST) == (LL_ADC_FLAG_AWD1_MST)) ? 1UL : 0UL);
}

   
                                                                  
                                                                
                                            
                                                                                                                 
                                  
    
__STATIC_INLINE uint32_t LL_ADC_IsActiveFlag_SLV_AWD1(const ADC_Common_TypeDef *ADCxy_COMMON)
{
  return ((READ_BIT(ADCxy_COMMON->CSR, LL_ADC_FLAG_AWD1_SLV) == (LL_ADC_FLAG_AWD1_SLV)) ? 1UL : 0UL);
}

   
                                                                       
                                                                
                                            
                                                                                                                 
                                  
    
__STATIC_INLINE uint32_t LL_ADC_IsActiveFlag_MST_AWD2(const ADC_Common_TypeDef *ADCxy_COMMON)
{
  return ((READ_BIT(ADCxy_COMMON->CSR, LL_ADC_FLAG_AWD2_MST) == (LL_ADC_FLAG_AWD2_MST)) ? 1UL : 0UL);
}

   
                                                                      
                                                                
                                            
                                                                                                                 
                                  
    
__STATIC_INLINE uint32_t LL_ADC_IsActiveFlag_SLV_AWD2(const ADC_Common_TypeDef *ADCxy_COMMON)
{
  return ((READ_BIT(ADCxy_COMMON->CSR, LL_ADC_FLAG_AWD2_SLV) == (LL_ADC_FLAG_AWD2_SLV)) ? 1UL : 0UL);
}

   
                                                                       
                                                                
                                            
                                                                                                                 
                                  
    
__STATIC_INLINE uint32_t LL_ADC_IsActiveFlag_MST_AWD3(const ADC_Common_TypeDef *ADCxy_COMMON)
{
  return ((READ_BIT(ADCxy_COMMON->CSR, LL_ADC_FLAG_AWD3_MST) == (LL_ADC_FLAG_AWD3_MST)) ? 1UL : 0UL);
}

   
                                                                      
                                                                
                                            
                                                                                                                 
                                  
    
__STATIC_INLINE uint32_t LL_ADC_IsActiveFlag_SLV_AWD3(const ADC_Common_TypeDef *ADCxy_COMMON)
{
  return ((READ_BIT(ADCxy_COMMON->CSR, LL_ADC_FLAG_AWD3_SLV) == (LL_ADC_FLAG_AWD3_SLV)) ? 1UL : 0UL);
}
#endif                            

   
      
    

                                                       
      
    

   
                             
                                                         
                             
                
    
__STATIC_INLINE void LL_ADC_EnableIT_ADRDY(ADC_TypeDef *ADCx)
{
  SET_BIT(ADCx->IER, LL_ADC_IT_ADRDY);
}

   
                                                                            
                                                       
                             
                
    
__STATIC_INLINE void LL_ADC_EnableIT_EOC(ADC_TypeDef *ADCx)
{
  SET_BIT(ADCx->IER, LL_ADC_IT_EOC);
}

   
                                                                              
                                                       
                             
                
    
__STATIC_INLINE void LL_ADC_EnableIT_EOS(ADC_TypeDef *ADCx)
{
  SET_BIT(ADCx->IER, LL_ADC_IT_EOS);
}

   
                                                          
                                                       
                             
                
    
__STATIC_INLINE void LL_ADC_EnableIT_OVR(ADC_TypeDef *ADCx)
{
  SET_BIT(ADCx->IER, LL_ADC_IT_OVR);
}

   
                                                                  
                                                         
                             
                
    
__STATIC_INLINE void LL_ADC_EnableIT_EOSMP(ADC_TypeDef *ADCx)
{
  SET_BIT(ADCx->IER, LL_ADC_IT_EOSMP);
}

   
                                                                             
                                                        
                             
                
    
__STATIC_INLINE void LL_ADC_EnableIT_JEOC(ADC_TypeDef *ADCx)
{
  SET_BIT(ADCx->IER, LL_ADC_IT_JEOC);
}

   
                                                                               
                                                        
                             
                
    
__STATIC_INLINE void LL_ADC_EnableIT_JEOS(ADC_TypeDef *ADCx)
{
  SET_BIT(ADCx->IER, LL_ADC_IT_JEOS);
}

   
                                                                          
                                                         
                             
                
    
__STATIC_INLINE void LL_ADC_EnableIT_JQOVF(ADC_TypeDef *ADCx)
{
  SET_BIT(ADCx->IER, LL_ADC_IT_JQOVF);
}

   
                                                      
                                                        
                             
                
    
__STATIC_INLINE void LL_ADC_EnableIT_AWD1(ADC_TypeDef *ADCx)
{
  SET_BIT(ADCx->IER, LL_ADC_IT_AWD1);
}

   
                                                      
                                                        
                             
                
    
__STATIC_INLINE void LL_ADC_EnableIT_AWD2(ADC_TypeDef *ADCx)
{
  SET_BIT(ADCx->IER, LL_ADC_IT_AWD2);
}

   
                                                      
                                                        
                             
                
    
__STATIC_INLINE void LL_ADC_EnableIT_AWD3(ADC_TypeDef *ADCx)
{
  SET_BIT(ADCx->IER, LL_ADC_IT_AWD3);
}

   
                                           
                                                          
                             
                
    
__STATIC_INLINE void LL_ADC_DisableIT_ADRDY(ADC_TypeDef *ADCx)
{
  CLEAR_BIT(ADCx->IER, LL_ADC_IT_ADRDY);
}

   
                                                                             
                                                        
                             
                
    
__STATIC_INLINE void LL_ADC_DisableIT_EOC(ADC_TypeDef *ADCx)
{
  CLEAR_BIT(ADCx->IER, LL_ADC_IT_EOC);
}

   
                                                                               
                                                        
                             
                
    
__STATIC_INLINE void LL_ADC_DisableIT_EOS(ADC_TypeDef *ADCx)
{
  CLEAR_BIT(ADCx->IER, LL_ADC_IT_EOS);
}

   
                                                           
                                                        
                             
                
    
__STATIC_INLINE void LL_ADC_DisableIT_OVR(ADC_TypeDef *ADCx)
{
  CLEAR_BIT(ADCx->IER, LL_ADC_IT_OVR);
}

   
                                                                   
                                                          
                             
                
    
__STATIC_INLINE void LL_ADC_DisableIT_EOSMP(ADC_TypeDef *ADCx)
{
  CLEAR_BIT(ADCx->IER, LL_ADC_IT_EOSMP);
}

   
                                                                             
                                                         
                             
                
    
__STATIC_INLINE void LL_ADC_DisableIT_JEOC(ADC_TypeDef *ADCx)
{
  CLEAR_BIT(ADCx->IER, LL_ADC_IT_JEOC);
}

   
                                                                                
                                                         
                             
                
    
__STATIC_INLINE void LL_ADC_DisableIT_JEOS(ADC_TypeDef *ADCx)
{
  CLEAR_BIT(ADCx->IER, LL_ADC_IT_JEOS);
}

   
                                                                           
                                                          
                             
                
    
__STATIC_INLINE void LL_ADC_DisableIT_JQOVF(ADC_TypeDef *ADCx)
{
  CLEAR_BIT(ADCx->IER, LL_ADC_IT_JQOVF);
}

   
                                                       
                                                         
                             
                
    
__STATIC_INLINE void LL_ADC_DisableIT_AWD1(ADC_TypeDef *ADCx)
{
  CLEAR_BIT(ADCx->IER, LL_ADC_IT_AWD1);
}

   
                                                       
                                                         
                             
                
    
__STATIC_INLINE void LL_ADC_DisableIT_AWD2(ADC_TypeDef *ADCx)
{
  CLEAR_BIT(ADCx->IER, LL_ADC_IT_AWD2);
}

   
                                                       
                                                         
                             
                
    
__STATIC_INLINE void LL_ADC_DisableIT_AWD3(ADC_TypeDef *ADCx)
{
  CLEAR_BIT(ADCx->IER, LL_ADC_IT_AWD3);
}

   
                                               
                                                          
                                                            
                             
                                  
    
__STATIC_INLINE uint32_t LL_ADC_IsEnabledIT_ADRDY(const ADC_TypeDef *ADCx)
{
  return ((READ_BIT(ADCx->IER, LL_ADC_IT_ADRDY) == (LL_ADC_IT_ADRDY)) ? 1UL : 0UL);
}

   
                                                                                 
                                                          
                                                          
                             
                                  
    
__STATIC_INLINE uint32_t LL_ADC_IsEnabledIT_EOC(const ADC_TypeDef *ADCx)
{
  return ((READ_BIT(ADCx->IER, LL_ADC_IT_EOC) == (LL_ADC_IT_EOC)) ? 1UL : 0UL);
}

   
                                                                                   
                                                          
                                                          
                             
                                  
    
__STATIC_INLINE uint32_t LL_ADC_IsEnabledIT_EOS(const ADC_TypeDef *ADCx)
{
  return ((READ_BIT(ADCx->IER, LL_ADC_IT_EOS) == (LL_ADC_IT_EOS)) ? 1UL : 0UL);
}

   
                                                               
                                                          
                                                          
                             
                                  
    
__STATIC_INLINE uint32_t LL_ADC_IsEnabledIT_OVR(const ADC_TypeDef *ADCx)
{
  return ((READ_BIT(ADCx->IER, LL_ADC_IT_OVR) == (LL_ADC_IT_OVR)) ? 1UL : 0UL);
}

   
                                                                       
                                                          
                                                            
                             
                                  
    
__STATIC_INLINE uint32_t LL_ADC_IsEnabledIT_EOSMP(const ADC_TypeDef *ADCx)
{
  return ((READ_BIT(ADCx->IER, LL_ADC_IT_EOSMP) == (LL_ADC_IT_EOSMP)) ? 1UL : 0UL);
}

   
                                                                                  
                                                          
                                                           
                             
                                  
    
__STATIC_INLINE uint32_t LL_ADC_IsEnabledIT_JEOC(const ADC_TypeDef *ADCx)
{
  return ((READ_BIT(ADCx->IER, LL_ADC_IT_JEOC) == (LL_ADC_IT_JEOC)) ? 1UL : 0UL);
}

   
                                                                                    
                                                          
                                                           
                             
                                  
    
__STATIC_INLINE uint32_t LL_ADC_IsEnabledIT_JEOS(const ADC_TypeDef *ADCx)
{
  return ((READ_BIT(ADCx->IER, LL_ADC_IT_JEOS) == (LL_ADC_IT_JEOS)) ? 1UL : 0UL);
}

   
                                                                                               
                                                          
                                                            
                             
                                  
    
__STATIC_INLINE uint32_t LL_ADC_IsEnabledIT_JQOVF(const ADC_TypeDef *ADCx)
{
  return ((READ_BIT(ADCx->IER, LL_ADC_IT_JQOVF) == (LL_ADC_IT_JQOVF)) ? 1UL : 0UL);
}

   
                                                           
                                                          
                                                           
                             
                                  
    
__STATIC_INLINE uint32_t LL_ADC_IsEnabledIT_AWD1(const ADC_TypeDef *ADCx)
{
  return ((READ_BIT(ADCx->IER, LL_ADC_IT_AWD1) == (LL_ADC_IT_AWD1)) ? 1UL : 0UL);
}

   
                                                               
                                                          
                                                           
                             
                                  
    
__STATIC_INLINE uint32_t LL_ADC_IsEnabledIT_AWD2(const ADC_TypeDef *ADCx)
{
  return ((READ_BIT(ADCx->IER, LL_ADC_IT_AWD2) == (LL_ADC_IT_AWD2)) ? 1UL : 0UL);
}

   
                                                               
                                                          
                                                           
                             
                                  
    
__STATIC_INLINE uint32_t LL_ADC_IsEnabledIT_AWD3(const ADC_TypeDef *ADCx)
{
  return ((READ_BIT(ADCx->IER, LL_ADC_IT_AWD3) == (LL_ADC_IT_AWD3)) ? 1UL : 0UL);
}

   
      
    

#if defined(USE_FULL_LL_DRIVER)
                                                                           
      
    

                                                                            
ErrorStatus LL_ADC_CommonDeInit(const ADC_Common_TypeDef *ADCxy_COMMON);
ErrorStatus LL_ADC_CommonInit(ADC_Common_TypeDef *ADCxy_COMMON, const LL_ADC_CommonInitTypeDef *pADC_CommonInitStruct);
void        LL_ADC_CommonStructInit(LL_ADC_CommonInitTypeDef *pADC_CommonInitStruct);

                                                                                 
                                                                  
ErrorStatus LL_ADC_DeInit(ADC_TypeDef *ADCx);

                                                     
ErrorStatus LL_ADC_Init(ADC_TypeDef *ADCx, const LL_ADC_InitTypeDef *pADC_InitStruct);
void        LL_ADC_StructInit(LL_ADC_InitTypeDef *pADC_InitStruct);

                                                                           
ErrorStatus LL_ADC_REG_Init(ADC_TypeDef *ADCx, const LL_ADC_REG_InitTypeDef *pADC_RegInitStruct);
void        LL_ADC_REG_StructInit(LL_ADC_REG_InitTypeDef *pADC_RegInitStruct);

                                                                            
ErrorStatus LL_ADC_INJ_Init(ADC_TypeDef *ADCx, const LL_ADC_INJ_InitTypeDef *pADC_InjInitStruct);
void        LL_ADC_INJ_StructInit(LL_ADC_INJ_InitTypeDef *pADC_InjInitStruct);

   
      
    
#endif                         

   
      
    

   
      
    

#endif                           

   
      
    

#ifdef __cplusplus
}
#endif

#endif                         
