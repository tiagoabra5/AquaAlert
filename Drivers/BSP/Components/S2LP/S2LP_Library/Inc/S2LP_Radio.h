/**
 * @file    S2LP_Radio.h
 * @author  LowPower RF BU - AMG
 * @version 1.3.0
 * @date    10-July-2017
 * @brief   Configuration and management of S2-LP RF Analog and Digital part.
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
 * In order to configure the Radio main parameters, the user can
 * fit <i>SRadioInit</i> structure the and call the <i>S2LPRadioInit()</i>
 * function passing its pointer as an argument.
 *
 * <b>Example:</b>
 * @code
 *
 * SRadioInit radioInit = {
 *     433400000,                 // base frequency
 *     MOD_2FSK,                     // modulation select
 *     38400,                   // datarate
 *     20000,                     // frequency deviation
 *     100000                     // channel filter bandwidth
 * };
 *
 * ...
 *
 * S2LPRadioInit(&radioInit);
 * @endcode
 *
 * Another important parameter for the radio configuration is the
 * transmission power.
 * The user is allowed to configure it using the function <i>S2LPRadioSetPALeveldBm()</i>
 * which sets the PA LEVEL specified by the first argument to the
 * power expressed in dBm by the second parameter.
 *
 * <b>Example:</b>
 * @code
 *
 *  S2LPRadioSetPALeveldBm(0 , 10.0);
 *
 * @endcode
 *
 *
 * @note The effective power that is set can be a little different from the
 * passed argument in dBm because the function performs an approximation.
 *
 * <h2><center>&copy; COPYRIGHT 2019 STMicroelectronics</center></h2>
 */


                                                                                
#ifndef __S2LP_RADIO_H
#define __S2LP_RADIO_H


                                                                                
#include "S2LP_Regs.h"
#include "S2LP_Types.h"


#ifdef __cplusplus
extern "C" {
#endif


                              
     
   


                                       
                                                                          
                                                                   
     
   



                                                            
     
   


   
                                      
   
typedef enum {
  MOD_NO_MOD       = 0x70,                               
  MOD_2FSK         = 0x00,                                  
  MOD_4FSK         = 0x10,                                  
  MOD_2GFSK_BT05   = 0xA0,                                                
  MOD_2GFSK_BT1    = 0x20,                                              
  MOD_4GFSK_BT05   = 0xB0,                                                
  MOD_4GFSK_BT1    = 0x30,                                              
  MOD_ASK_OOK      = 0x50,                                 
  MOD_POLAR        = 0x60,                                 
} ModulationSelect;


   
                                               
   
typedef struct {
  uint32_t          lFrequencyBase;                                                       
                                                                                 
                                                                                             
                                                                          
                                                                               
  ModulationSelect  xModulationSelect;                                                        
  uint32_t          lDatarate;                                                       
                                                                          
                                                                       
  uint32_t          lFreqDev;                                                                  
                                                                            
                                                                           
  uint32_t          lBandwidth;                                                    
                                                                              
                                                                                  
} SRadioInit;


   
                                    
   
typedef enum {
  AFC_MODE_LOOP_CLOSED_ON_SLICER = 0,                                
  AFC_MODE_LOOP_CLOSED_ON_2ND_CONV_STAGE                                           
} SAfcMode;


   
                                             
   
typedef struct {
  SFunctionalState  xAfcEnable;                         
  SFunctionalState  xAfcFreezeOnSync;                                                  
  SAfcMode          xAfcMode;                                                    
  uint8_t          cAfcFastPeriod;                                
  uint8_t          cAfcFastGain;                                        
  uint8_t          cAfcSlowGain;                                        
} SAfcInit;


   
                                                 
   
typedef enum {
  ISI_EQUALIZATION_DISABLED = 0,                   
  ISI_EQUALIZATION_SINGLE_PASS,                                         
  ISI_EQUALIZATION_DUAL_PASS                                              
} SIsiEqu;


   
                                               
   
typedef enum {
  CLKREC_DLL_MODE = 0,               
  CLKREC_PLL_MODE,                   
} SClkRecMode;


   
                                                        
   
typedef struct {
  SClkRecMode      xSClkRecMode;                                                                  
  uint8_t          cClkRecPGainSlow;                                                 
  uint8_t          cClkRecPGainFast;                                                 
  uint8_t          cClkRecIGainSlow;                                                  
  uint8_t          cClkRecIGainFast;                                                  
  SFunctionalState cClkRec16SymPostFlt;                                                                  
} SSymClkRecInit;


   
     
   



                                                                                        
     
   

uint8_t S2LPRadioInit(SRadioInit* pxSRadioInitStruct);
void S2LPRadioGetInfo(SRadioInit* pxSRadioInitStruct);
void S2LPRadioSetSynthWord(uint32_t lSynthWord);
uint32_t S2LPRadioGetSynthWord(void);
void S2LPRadioSetChannel(uint8_t cChannel);
uint8_t S2LPRadioGetChannel(void);
void S2LPRadioSetRefDiv(SFunctionalState xNewState);
SFunctionalState S2LPRadioGetRefDiv(void);
void S2LPRadioSetDigDiv(SFunctionalState xNewState);
SFunctionalState S2LPRadioGetDigDiv(void);
void S2LPRadioSetChannelSpace(uint32_t lChannelSpace);
uint32_t S2LPRadioGetChannelSpace(void);
uint8_t S2LPRadioSetFrequencyBase(uint32_t lFBase);
uint32_t S2LPRadioGetFrequencyBase(void);
void S2LPRadioSetDatarate(uint32_t lDatarate);
uint32_t S2LPRadioGetDatarate(void);
void S2LPRadioSetFrequencyDev(uint32_t lFDev);
uint32_t S2LPRadioGetFrequencyDev(void);
void S2LPRadioSetChannelBW(uint32_t lBandwidth);
uint32_t S2LPRadioGetChannelBW(void);
void S2LPRadioSetModulation(ModulationSelect xModulation);
ModulationSelect S2LPRadioGetModulation(void);
void S2LPRadioSetXtalFrequency(uint32_t lXtalFrequency);
uint32_t S2LPRadioGetXtalFrequency(void);
void S2LPRadioSetIsiEqualizationMode(SIsiEqu xSIsiMode);
SIsiEqu S2LPRadioGetIsiEqualizationMode(void);
void S2LPRadioCalibrationVco(SFunctionalState xAmplitudeCalibration, SFunctionalState xFrequencyCalibration);
void S2LPRadioSetTxCalibVcoAmpWord(uint8_t value);
void S2LPRadioSetRxCalibVcoAmpWord(uint8_t value);
void S2LPRadioSetTxCalibVcoFreqWord(uint8_t value);
void S2LPRadioSetRxCalibVcoFreqWord(uint8_t value);

void S2LPRadioSetMaxPALevel(SFunctionalState xNewState);
void S2LPRadioSetPALeveldBm(uint8_t cIndex, int32_t wPowerdBm);
int32_t S2LPRadioGetPALeveldBm(uint8_t cIndex);
uint8_t S2LPRadioGetPALevelMaxIndex(void);
void S2LPRadioSetPALevelMaxIndex(uint8_t cIndex);
void S2LPRadioSetManualRampingMode(SFunctionalState xNewState);
void S2LPRadioSetAutoRampingMode(SFunctionalState xNewState);

void S2LPRadioAfcInit(SAfcInit* xSAfcInit);
void S2LPRadioGetAfcInfo(SAfcInit* xSAfcInit);
void S2LPRadioSymClkRecoverInit(SSymClkRecInit* xSSymClkRecInit);
void S2LPRadioGetSymClkRecoverInfo(SSymClkRecInit* xSSymClkRecInit);


   
     
   

   
     
   


   
     
   



#ifdef __cplusplus
}
#endif

#endif

/******************* (C) COPYRIGHT 2016 STMicroelectronics *****END OF FILE****/
