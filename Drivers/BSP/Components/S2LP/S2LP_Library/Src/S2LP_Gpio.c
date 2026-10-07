/**
 * @file    S2LP_Gpio.c
 * @author  LowPower RF BU - AMG
 * @version 1.3.0
 * @date    10-July-2017
 * @brief   This file provides all the low level API to manage S2-LP GPIO.
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
 * <h2><center>&copy; COPYRIGHT 2019 STMicroelectronics</center></h2>
 * 
 */

                                                                                
#include "S2LP_Gpio.h"
#include "MCU_Interface.h"
#include <string.h>

                              
     
   


                         
     
   




                                                                   
     
   


#define IS_S2LP_GPIO(PIN)  ((PIN == S2LP_GPIO_0) || \
                              (PIN == S2LP_GPIO_1) || \
                              (PIN == S2LP_GPIO_2) || \
                              (PIN == S2LP_GPIO_3))


#define IS_S2LP_GPIO_MODE(MODE)   ((MODE == S2LP_GPIO_MODE_DIGITAL_INPUT) || \
                                   (MODE == S2LP_GPIO_MODE_DIGITAL_OUTPUT_LP) || \
                                   (MODE == S2LP_GPIO_MODE_DIGITAL_OUTPUT_HP))

#define IS_S2LP_GPIO_IO(IO_SEL)        ((IO_SEL == S2LP_GPIO_DIG_OUT_IRQ) || \
                                          (IO_SEL == S2LP_GPIO_DIG_OUT_POR_INV) || \
                                          (IO_SEL == S2LP_GPIO_DIG_OUT_WUT_EXP) || \
                                          (IO_SEL == S2LP_GPIO_DIG_OUT_LBD) || \
                                          (IO_SEL == S2LP_GPIO_DIG_OUT_TX_DATA) || \
                                          (IO_SEL == S2LP_GPIO_DIG_OUT_TX_STATE) || \
                                          (IO_SEL == S2LP_GPIO_DIG_OUT_TXRX_FIFO_ALMOST_EMPTY) || \
                                          (IO_SEL == S2LP_GPIO_DIG_OUT_TXRX_FIFO_ALMOST_FULL) || \
                                          (IO_SEL == S2LP_GPIO_DIG_OUT_RX_DATA) || \
                                          (IO_SEL == S2LP_GPIO_DIG_OUT_RX_CLOCK) || \
                                          (IO_SEL == S2LP_GPIO_DIG_OUT_RX_STATE) || \
                                          (IO_SEL == S2LP_GPIO_DIG_OUT_NOT_STANDBY_SLEEP) || \
                                          (IO_SEL == S2LP_GPIO_DIG_OUT_STANDBY) || \
                                          (IO_SEL == S2LP_GPIO_DIG_OUT_ANTENNA_SWITCH) || \
                                          (IO_SEL == S2LP_GPIO_DIG_OUT_VALID_PREAMBLE) || \
                                          (IO_SEL == S2LP_GPIO_DIG_OUT_SYNC_DETECTED) || \
                                          (IO_SEL == S2LP_GPIO_DIG_OUT_RSSI_THRESHOLD) || \
                                          (IO_SEL == S2LP_GPIO_DIG_OUT_MCU_CLOCK) || \
                                          (IO_SEL == S2LP_GPIO_DIG_OUT_TX_RX_MODE) || \
                                          (IO_SEL == S2LP_GPIO_DIG_OUT_VDD) || \
                                          (IO_SEL == S2LP_GPIO_DIG_OUT_GND) || \
                                          (IO_SEL == S2LP_GPIO_DIG_OUT_SMPS_EXT) ||\
                                          (IO_SEL == S2LP_GPIO_DIG_OUT_SLEEP) ||\
                                          (IO_SEL == S2LP_GPIO_DIG_OUT_READY) ||\
                                          (IO_SEL == S2LP_GPIO_DIG_OUT_LOCK) ||\
                                          (IO_SEL == S2LP_GPIO_DIG_OUT_WAIT_FOR_LOCK_SIG) ||\
                                          (IO_SEL == S2LP_GPIO_DIG_OUT_TX_DATA_OOK_SIGNAL) ||\
                                          (IO_SEL == S2LP_GPIO_DIG_OUT_WAIT_FOR_READY2_SIG) ||\
                                          (IO_SEL == S2LP_GPIO_DIG_OUT_WAIT_FOR_TIMER_FOR_PM_SET) ||\
                                          (IO_SEL == S2LP_GPIO_DIG_OUT_WAIT_VCO_CALIBRATION) ||\
                                          (IO_SEL == S2LP_GPIO_DIG_OUT_ENABLE_SYNTH_FULL_CIRCUIT) ||\
                                          (IO_SEL == S2LP_GPIO_DIG_IN_TX_COMMAND) ||\
                                          (IO_SEL == S2LP_GPIO_DIG_IN_RX_COMMAND) ||\
                                          (IO_SEL == S2LP_GPIO_DIG_IN_TX_DATA_INPUT_FOR_DIRECTRF) ||\
                                          (IO_SEL == S2LP_GPIO_DIG_IN_DATA_WAKEUP) ||\
                                          (IO_SEL == S2LP_GPIO_DIG_IN_EXT_CLOCK_AT_34_7KHZ))


#define IS_S2LP_GPIO_LEVEL(LEVEL)      ((LEVEL == LOW) || \
                                          (LEVEL == HIGH))

#define IS_S2LP_CLOCK_OUTPUT_XO(RATIO) ((RATIO == XO_RATIO_1) || \
                                           (RATIO == XO_RATIO_1_2) || \
                                           (RATIO == XO_RATIO_1_4) || \
                                           (RATIO == XO_RATIO_1_8) || \
                                           (RATIO == XO_RATIO_1_16) || \
                                           (RATIO == XO_RATIO_1_32) || \
                                           (RATIO == XO_RATIO_1_64) || \
                                           (RATIO == XO_RATIO_1_128) || \
                                           (RATIO == XO_RATIO_1_256))

#define IS_S2LP_CLOCK_OUTPUT_RCO(RATIO) ((RATIO == RCO_RATIO_1) || \
                                           (RATIO == RCO_RATIO_1_128))


#define IS_S2LP_CLOCK_OUTPUT_EXTRA_CYCLES(CYCLES) ((CYCLES == EXTRA_CLOCK_CYCLES_0) || \
                                                      (CYCLES == EXTRA_CLOCK_CYCLES_128) || \
                                                      (CYCLES == EXTRA_CLOCK_CYCLES_256) || \
                                                      (CYCLES == EXTRA_CLOCK_CYCLES_512))


#define IS_S2LP_IRQ_LIST(VALUE)   ((VALUE == RX_DATA_READY) || \
                                     (VALUE == RX_DATA_DISC)  || \
                                     (VALUE == TX_DATA_SENT)  || \
                                     (VALUE == MAX_RE_TX_REACH)  || \
                                     (VALUE == CRC_ERROR)  || \
                                     (VALUE == TX_FIFO_ERROR)  || \
                                     (VALUE == RX_FIFO_ERROR)  || \
                                     (VALUE == TX_FIFO_ALMOST_FULL)  || \
                                     (VALUE == TX_FIFO_ALMOST_EMPTY)  || \
                                     (VALUE == RX_FIFO_ALMOST_FULL)  || \
                                     (VALUE == RX_FIFO_ALMOST_EMPTY)  || \
                                     (VALUE == MAX_BO_CCA_REACH)  || \
                                     (VALUE == VALID_PREAMBLE)  || \
                                     (VALUE == VALID_SYNC)  || \
                                     (VALUE == RSSI_ABOVE_TH)  || \
                                     (VALUE == WKUP_TOUT_LDC)  || \
                                     (VALUE == READY)  || \
                                     (VALUE == STANDBY_DELAYED)  || \
                                     (VALUE == LOW_BATT_LVL)  || \
                                     (VALUE == POR)  || \
                                     (VALUE == BOR)  || \
                                     (VALUE == LOCK)  || \
                                     (VALUE == VCO_CALIBRATION_END)  || \
                                     (VALUE == PA_CALIBRATION_END)  || \
                                     (VALUE == PM_COUNT_EXPIRED)  || \
                                     (VALUE == XO_COUNT_EXPIRED)  || \
                                     (VALUE == TX_START_TIME)  || \
                                     (VALUE == RX_START_TIME)  || \
                                     (VALUE == RX_TIMEOUT)  || \
                                     (VALUE == RX_SNIFF_TIMEOUT)   || \
				                              (VALUE == ALL_IRQ ))



   
     
   



                                                                      
     
   

   
                                                               
                                              
                                                                 
                                                                              
                
   
void S2LPGpioInit(SGpioInit* pxGpioInitStruct)
{
  uint8_t tmp;

  s_assert_param(IS_S2LP_GPIO(pxGpioInitStruct->xS2LPGpioPin));
  s_assert_param(IS_S2LP_GPIO_MODE(pxGpioInitStruct->xS2LPGpioMode));
  s_assert_param(IS_S2LP_GPIO_IO(pxGpioInitStruct->xS2LPGpioIO));

  tmp = ((uint8_t)(pxGpioInitStruct->xS2LPGpioMode) | (uint8_t)(pxGpioInitStruct->xS2LPGpioIO));
  g_xStatus = S2LPSpiWriteRegisters(pxGpioInitStruct->xS2LPGpioPin, 1, &tmp);

}



   
                                                                         
                                                      
                                                       
                                    
                                    
                                    
                                    
                                      
                                        
                
   
void S2LPGpioSetLevel(S2LPGpioPin xGpioX, OutputLevel xLevel)
{
  uint8_t tmp;

  s_assert_param(IS_S2LP_GPIO(xGpioX));
  s_assert_param(IS_S2LP_GPIO_LEVEL(xLevel));

                                                                                 
  if(xLevel == HIGH) {
    tmp = (uint8_t)S2LP_GPIO_DIG_OUT_VDD | (uint8_t)S2LP_GPIO_MODE_DIGITAL_OUTPUT_HP;
  }
  else {
    tmp = (uint8_t)S2LP_GPIO_DIG_OUT_GND | (uint8_t)S2LP_GPIO_MODE_DIGITAL_OUTPUT_HP;
  }

  g_xStatus = S2LPSpiWriteRegisters(xGpioX, 1, &tmp);

}


   
                                                                                                    
                                                
                                                             
                                        
                                        
                                        
                                        
                                                                                   
                                              
   
OutputLevel S2LPGpioGetLevel(S2LPGpioPin xGpioX)
{
  uint8_t tmp = 0x00;

  s_assert_param(IS_S2LP_GPIO(xGpioX));

  g_xStatus = S2LPSpiReadRegisters(xGpioX, 1, &tmp);

                                                                  
  tmp &= GPIO_SELECT_REGMASK;
  if(tmp == S2LP_GPIO_DIG_OUT_VDD) {
    return HIGH;
  }
  else {
    return LOW;
  }

}


   
                                                                       
                                                                                      
                                                                                  
                                             
                
   
void S2LPGpioIrqDeInit(S2LPIrqs* pxIrqInit)
{
  uint8_t tmp[4] = {0x00,0x00,0x00,0x00};

  if(pxIrqInit!=NULL) {
	                                                                                       
                                      
    S2LPIrqs tempValue;
    memset(&tempValue, 0x00, sizeof(S2LPIrqs));
    
    *pxIrqInit = (*(S2LPIrqs*)&tempValue);
  }

  g_xStatus = S2LPSpiWriteRegisters(IRQ_MASK3_ADDR, 4, tmp);
}


   
                                                                             
                                                                                   
                                                                                
                                                                                             
        
                            
                                  
                                  
                               
           
                
   
void S2LPGpioIrqInit(S2LPIrqs* pxIrqInit)
{
  uint8_t tmp[4];
  uint8_t* tmpPoint;

  tmpPoint = (uint8_t*)(pxIrqInit);
  for(int i=0; i<4; i++) {
    tmp[3-i]= tmpPoint[i];
  }

  g_xStatus = S2LPSpiWriteRegisters(IRQ_MASK3_ADDR, 4, tmp);

}


   
                                             
                                         
                                                           
                                           
                                                        
                
   
void S2LPGpioIrqConfig(IrqList xIrq, SFunctionalState xNewState)
{
  uint8_t tmpBuffer[4];
  uint32_t tempValue = 0;

  s_assert_param(IS_S2LP_IRQ_LIST(xIrq));
  s_assert_param(IS_SFUNCTIONAL_STATE(xNewState));

  S2LPSpiReadRegisters(IRQ_MASK3_ADDR, 4, tmpBuffer);

                               
  for(int i=0; i<4; i++) {
    tempValue += ((uint32_t)tmpBuffer[i])<<(8*(3-i));
  }
  
                                                      
  if(xNewState == S_DISABLE) {
    tempValue &= (~xIrq);
  }
  else {
    tempValue |= (xIrq);
  }

                                                                   
  for(int j=0; j<4; j++) {
    tmpBuffer[j] = (uint8_t)(tempValue>>(8*(3-j)));
  }
  
  g_xStatus = S2LPSpiWriteRegisters(IRQ_MASK3_ADDR, 4, tmpBuffer);

}


   
                                                                                         
                                                                                   
                                                                                            
                                                                                              
                                                     
                                                                                                   
        
                      
                                
           
       
                                                                   
                                                  
                
   
void S2LPGpioIrqGetMask(S2LPIrqs* pxIrqMask)
{
  uint8_t tmp[4];
  uint8_t* pIrqPointer = (uint8_t*)pxIrqMask;

  g_xStatus = S2LPSpiReadRegisters(IRQ_MASK3_ADDR, 4, tmp);

  for(char i=0; i<4; i++) {
    *pIrqPointer = tmp[3-i];
    pIrqPointer++;
  }

}


   
                                                                                           
                                                                                     
                                                                                               
                                                                               
                                                                                              
                     
        
                        
                                      
           
       
                                                                                  
                                                    
                
   
void S2LPGpioIrqGetStatus(S2LPIrqs* pxIrqStatus)
{
  uint8_t tmp[4];
  uint8_t* pIrqPointer = (uint8_t*)pxIrqStatus;
  
  g_xStatus = S2LPSpiReadRegisters(IRQ_STATUS3_ADDR, 4, tmp);

                                 
  for(uint8_t i=0; i<4; i++) {
    *pIrqPointer = tmp[3-i];
    pIrqPointer++;
  }
}


   
                                          
                
                
   
void S2LPGpioIrqClearStatus(void)
{
  uint8_t tmp[4];
  g_xStatus = S2LPSpiReadRegisters(IRQ_STATUS3_ADDR, 4, tmp);

}


   
                                                        
                                                                                                          
                                        
                                                           
                                   
   
SBool S2LPGpioIrqCheckFlag(IrqList xFlag)
{
  uint8_t tmp[4];
  uint32_t tempValue = 0;
  SBool flag;

  s_assert_param(IS_S2LP_IRQ_LIST(xFlag));

  g_xStatus = S2LPSpiReadRegisters(IRQ_STATUS3_ADDR, 4, tmp);
  for(uint8_t i=0; i<4; i++) {
    tempValue += ((uint32_t)tmp[i])<<(8*(3-i));
  }
  
  if(tempValue & xFlag) {
    flag = S_TRUE;
  }
  else {
    flag = S_FALSE;
  }

  return flag;

}

   
     
   


   
     
   


   
     
   



/******************* (C) COPYRIGHT 2016 STMicroelectronics *****END OF FILE****/
