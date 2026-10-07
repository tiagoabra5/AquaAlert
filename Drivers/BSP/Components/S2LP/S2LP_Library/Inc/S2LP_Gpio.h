/**
 * @file    S2LP_Gpio.h
 * @author  LowPower RF BU - AMG
 * @version 1.3.0
 * @date    10-July-2017
 * @brief   Configuration and management of S2-LP GPIO.
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; COPYRIGHT(c) 2019 STMicroelectronics</center></h2>
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *   1. Redistributions of source code must retain the above copyright notice,
 *      this list of conditions and the following disclaimer.
 *   2. Redistributions in binary form must reproduce the above copyright notice,
 *      this list of conditions and the following disclaimer in the documentation
 *      and/or other materials provided with the distribution.
 *   3. Neither the name of STMicroelectronics nor the names of its contributors 
 *      may be used to endorse or promote products derived from this software
 *      without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE 
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * This module can be used to configure the S2-LP GPIO pins to perform
 * specific functions.
 * The structure <i>@ref gpioIRQ</i> can be used to specify these features for
 * one of the four S2-LP Gpio pin.
 * The following example shows how to configure a pin (GPIO 3) to be used as an IRQ source
 * for a microcontroller using the <i>@ref S2LPGpioInit()</i> function.
 *
 * <b>Example:</b>
 * @code
 *
 * SGpioInit gpioIRQ={
 *   S2LP_GPIO_3,
 *   S2LP_GPIO_MODE_DIGITAL_OUTPUT_LP,
 *   S2LP_GPIO_DIG_OUT_IRQ
 * };
 *
 * ...
 *
 * S2LPGpioInit(&gpioIRQ);
 *
 * @endcode
 *
 * @note Please read the functions documentation for the other GPIO features.
 *
 * <h2><center>&copy; COPYRIGHT 2019 STMicroelectronics</center></h2>
 */


                                                                                
#ifndef __S2LP_GPIO_H
#define __S2LP_GPIO_H


                                                                                
#include "S2LP_Regs.h"
#include "S2LP_Types.h"


#ifdef __cplusplus
extern "C" {
#endif


                              
     
   


                                  
                                                    
                                                                  
     
   



                                                           
     
   

   
                                     
   
typedef enum {
  S2LP_GPIO_0  = GPIO0_CONF_ADDR,                        
  S2LP_GPIO_1  = GPIO1_CONF_ADDR,                        
  S2LP_GPIO_2  = GPIO2_CONF_ADDR,                        
  S2LP_GPIO_3  = GPIO3_CONF_ADDR                         
} S2LPGpioPin;


   
                                      
   
typedef enum {
  S2LP_GPIO_MODE_DIGITAL_INPUT      = 0x01,                              
  S2LP_GPIO_MODE_DIGITAL_OUTPUT_LP ,                                                    
  S2LP_GPIO_MODE_DIGITAL_OUTPUT_HP                                                       
} S2LPGpioMode;



   
                                          
   
typedef enum {
  S2LP_GPIO_DIG_OUT_IRQ                               = 0x00,                                                                               
  S2LP_GPIO_DIG_OUT_POR_INV                           = 0x08,                                  
  S2LP_GPIO_DIG_OUT_WUT_EXP                           = 0x10,                                                           
  S2LP_GPIO_DIG_OUT_LBD                               = 0x18,                                                                           
  S2LP_GPIO_DIG_OUT_TX_DATA                           = 0x20,                                                                                     
  S2LP_GPIO_DIG_OUT_TX_STATE                          = 0x28,                                                                       
  S2LP_GPIO_DIG_OUT_TXRX_FIFO_ALMOST_EMPTY            = 0x30,                                     
  S2LP_GPIO_DIG_OUT_TXRX_FIFO_ALMOST_FULL             = 0x38,                                    
  S2LP_GPIO_DIG_OUT_RX_DATA                           = 0x40,                       
  S2LP_GPIO_DIG_OUT_RX_CLOCK                          = 0x48,                                                       
  S2LP_GPIO_DIG_OUT_RX_STATE                          = 0x50,                                                        
  S2LP_GPIO_DIG_OUT_NOT_STANDBY_SLEEP                 = 0x58,                                                       
  S2LP_GPIO_DIG_OUT_STANDBY                           = 0x60,                                      
  S2LP_GPIO_DIG_OUT_ANTENNA_SWITCH                    = 0x68,                                                   
  S2LP_GPIO_DIG_OUT_VALID_PREAMBLE                    = 0x70,                                     
  S2LP_GPIO_DIG_OUT_SYNC_DETECTED                     = 0x78,                                         
  S2LP_GPIO_DIG_OUT_RSSI_THRESHOLD                    = 0x80,                             
  S2LP_GPIO_DIG_OUT_MCU_CLOCK                         = 0x88,                  
  S2LP_GPIO_DIG_OUT_TX_RX_MODE                        = 0x90,                                                                       
  S2LP_GPIO_DIG_OUT_VDD                               = 0x98,                                                                            
  S2LP_GPIO_DIG_OUT_GND                               = 0xA0,                                                                            
  S2LP_GPIO_DIG_OUT_SMPS_EXT                          = 0xA8,                                                  
  S2LP_GPIO_DIG_OUT_SLEEP                             = 0xB0,                                      
  S2LP_GPIO_DIG_OUT_READY                             = 0xB8,                                      
  S2LP_GPIO_DIG_OUT_LOCK                              = 0xC0,                                     
  S2LP_GPIO_DIG_OUT_WAIT_FOR_LOCK_SIG                 = 0xC8,                                              
  S2LP_GPIO_DIG_OUT_TX_DATA_OOK_SIGNAL                = 0xD0,
  S2LP_GPIO_DIG_OUT_WAIT_FOR_READY2_SIG               = 0xD8,
  S2LP_GPIO_DIG_OUT_WAIT_FOR_TIMER_FOR_PM_SET         = 0xE0,
  S2LP_GPIO_DIG_OUT_WAIT_VCO_CALIBRATION              = 0xE8,
  S2LP_GPIO_DIG_OUT_ENABLE_SYNTH_FULL_CIRCUIT         = 0xF0,

  S2LP_GPIO_DIG_IN_TX_COMMAND                         = 0x00,
  S2LP_GPIO_DIG_IN_RX_COMMAND                         = 0x08,
  S2LP_GPIO_DIG_IN_TX_DATA_INPUT_FOR_DIRECTRF         = 0x10,
  S2LP_GPIO_DIG_IN_DATA_WAKEUP                        = 0x18,
  S2LP_GPIO_DIG_IN_EXT_CLOCK_AT_34_7KHZ               = 0x20
} S2LPGpioIO;


   
                                        
   
typedef enum {
  LOW = 0,
  HIGH = !LOW
} OutputLevel;


   
                                               
   
typedef struct {
  S2LPGpioPin xS2LPGpioPin;                                                                   
  S2LPGpioMode xS2LPGpioMode;                                                       
  S2LPGpioIO xS2LPGpioIO;                                                                
} SGpioInit;


   
                                                      
   
typedef enum {
 XO_RATIO_1     = 0x00,                                                               
 XO_RATIO_1_2   = 0x02,                                                               
 XO_RATIO_1_4	= 0x04,                                                               
 XO_RATIO_1_8	= 0x06,                                                               
 XO_RATIO_1_16	= 0x08,                                                               
 XO_RATIO_1_32	= 0x0A,                                                               
 XO_RATIO_1_64	= 0x0C,                                                               
 XO_RATIO_1_128	= 0x0E,                                                               
 XO_RATIO_1_256	= 0x10                                                                
} ClockOutputXOPrescaler;


   
                                                       
   

typedef enum {
 RCO_RATIO_1        = 0x00,                                                                  
 RCO_RATIO_1_128	                                                                             
} ClockOutputRCOPrescaler;


   
                                             
   
typedef enum {
EXTRA_CLOCK_CYCLES_0	  = 0x00,                                                                                     
EXTRA_CLOCK_CYCLES_128	= 0x20,                                                                                      
EXTRA_CLOCK_CYCLES_256	= 0x40,                                                                                     
EXTRA_CLOCK_CYCLES_512	= 0x60                                                                                      
} ExtraClockCycles;


   
                                                                 
   
typedef struct {
  ClockOutputXOPrescaler   xClockOutputXOPrescaler;                                                       
  ClockOutputRCOPrescaler  xClockOutputRCOPrescaler;                                                        
  ExtraClockCycles         xExtraClockCycles;                                                                                                          
} ClockOutputInit;


   
                                                                                                      
                                                                                                               
                                                                                                                  
                                                                                                               
                                                      
                                                                                     
                                                                                         
                                                                              
   
typedef struct {
  SFlagStatus  IRQ_RX_DATA_READY:1;                                      
  SFlagStatus  IRQ_RX_DATA_DISC:1;                                                            
  SFlagStatus  IRQ_TX_DATA_SENT:1;                                      
  SFlagStatus  IRQ_MAX_RE_TX_REACH:1;                                        
  SFlagStatus  IRQ_CRC_ERROR:1;                                      
  SFlagStatus  IRQ_TX_FIFO_ERROR:1;                                                         
  SFlagStatus  IRQ_RX_FIFO_ERROR:1;                                                         
  SFlagStatus  IRQ_TX_FIFO_ALMOST_FULL:1;                                      

  SFlagStatus  IRQ_TX_FIFO_ALMOST_EMPTY:1;                                      
  SFlagStatus  IRQ_RX_FIFO_ALMOST_FULL:1;                                      
  SFlagStatus  IRQ_RX_FIFO_ALMOST_EMPTY:1;                                       
  SFlagStatus  IRQ_MAX_BO_CCA_REACH:1;                                                       
  SFlagStatus  IRQ_VALID_PREAMBLE:1;                                               
  SFlagStatus  IRQ_VALID_SYNC:1;                                              
  SFlagStatus  IRQ_RSSI_ABOVE_TH:1;                                             
  SFlagStatus  IRQ_WKUP_TOUT_LDC:1;                                                    

  SFlagStatus  IRQ_READY:1;                                            
  SFlagStatus  IRQ_STANDBY_DELAYED:1;                                                                                
  SFlagStatus  IRQ_LOW_BATT_LVL:1;                                                      
  SFlagStatus  IRQ_POR:1;                                                 
  SFlagStatus  IRQ_BOR:1;                                                                                
  SFlagStatus  IRQ_LOCK:1;                                            
  SFlagStatus  IRQ_VCO_CALIBRATION_END:1;                                                   
  SFlagStatus  IRQ_PA_CALIBRATION_END:1;                                                   
  
  SFlagStatus  IRQ_PM_COUNT_EXPIRED:1;                                                                                                                
  SFlagStatus  IRQ_XO_COUNT_EXPIRED:1;                                                                                      
  SFlagStatus  IRQ_TX_START_TIME:1;                                                                                        
  SFlagStatus  IRQ_RX_START_TIME:1;                                                                                        
  SFlagStatus  IRQ_RX_TIMEOUT:1;                                                
  SFlagStatus  IRQ_RX_SNIFF_TIMEOUT:1;                                                
  SFlagStatus  :2;                                                 
} S2LPIrqs;


   
                                                                                        
                        
   
typedef enum {
  RX_DATA_READY = 0x00000001,                                     
  RX_DATA_DISC = 0x00000002,                                                           
  TX_DATA_SENT = 0x00000004,                                     
  MAX_RE_TX_REACH = 0x00000008,                                       
  CRC_ERROR = 0x00000010,                                     
  TX_FIFO_ERROR = 0x00000020,                                                        
  RX_FIFO_ERROR = 0x00000040,                                                        
  TX_FIFO_ALMOST_FULL = 0x00000080,                                     
  TX_FIFO_ALMOST_EMPTY = 0x00000100,                                     
  RX_FIFO_ALMOST_FULL = 0x00000200,                                     
  RX_FIFO_ALMOST_EMPTY = 0x00000400,                                      
  MAX_BO_CCA_REACH = 0x00000800,                                                      
  VALID_PREAMBLE = 0x00001000,                                              
  VALID_SYNC = 0x00002000,                                             
  RSSI_ABOVE_TH = 0x00004000,                                            
  WKUP_TOUT_LDC = 0x00008000,                                                   
  READY = 0x00010000,                                           
  STANDBY_DELAYED = 0x00020000,                                                                               
  LOW_BATT_LVL = 0x00040000,                                                     
  POR = 0x00080000,                                                
  BOR = 0x00100000,                                                                               
  LOCK = 0x00200000,                                           
  VCO_CALIBRATION_END = 0x00400000,                                                                                                               
  PA_CALIBRATION_END = 0x00800000,                                                                                     
  PM_COUNT_EXPIRED = 0x01000000,                                                                                                               
  XO_COUNT_EXPIRED = 0x02000000,                                                                                     
  TX_START_TIME = 0x04000000,	                                                                                    
  RX_START_TIME = 0x08000000,	                                                                                    
  RX_TIMEOUT = 0x10000000,	                                         
  RX_SNIFF_TIMEOUT = 0x20000000,                                                        
  ALL_IRQ = 0x7FFFFFFF			                                    
} IrqList;


   
     
   



                                                               
     
   

void S2LPGpioInit(SGpioInit* pxGpioInitStruct);
void S2LPGpioSetLevel(S2LPGpioPin xGpioX, OutputLevel xLevel);
OutputLevel S2LPGpioGetLevel(S2LPGpioPin xGpioX);
void S2LPGpioClockOutput(SFunctionalState xNewState);
void S2LPGpioClockOutputInit(ClockOutputInit* pxClockOutputInitStruct);
void S2LPGpioSetXOPrescaler(ClockOutputXOPrescaler xXOPrescaler);
ClockOutputXOPrescaler S2LPGpioGetXOPrescaler(void);
void S2LPGpioSetRCOPrescaler(ClockOutputRCOPrescaler xRCOPrescaler);
ClockOutputRCOPrescaler S2LPGpioGetRCOPrescaler(void);
void S2LPGpioSetExtraClockCycles(ExtraClockCycles xExtraCycles);
ExtraClockCycles S2LPGpioGetExtraClockCycles(void);

void S2LPGpioIrqDeInit(S2LPIrqs* pxIrqInit);
void S2LPGpioIrqInit(S2LPIrqs* pxIrqInit);
void S2LPGpioIrqConfig(IrqList xIrq, SFunctionalState xNewState);
void S2LPGpioIrqGetMask(S2LPIrqs* pxIrqMask);
void S2LPGpioIrqGetStatus(S2LPIrqs* pxIrqStatus);
void S2LPGpioIrqClearStatus(void);
SBool S2LPGpioIrqCheckFlag(IrqList xFlag);

   
     
   

   
     
   


   
     
   



#ifdef __cplusplus
}
#endif

#endif

/******************* (C) COPYRIGHT 2016 STMicroelectronics *****END OF FILE****/
