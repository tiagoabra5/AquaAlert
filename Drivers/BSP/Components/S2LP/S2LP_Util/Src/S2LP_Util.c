 /**
 * @file    S2LP_Util.c
 * @author  LowPower RF BU - AMG
 * @version 1.1.0
 * @date    July 1, 2016
 * @brief   Identification functions for S2-LP DK.
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
*
 * <h2><center>&copy; COPYRIGHT 2019 STMicroelectronics</center></h2>
 */  


                                                                                
#include "S2LP_Util.h"
#include "MCU_Interface.h"


   
                                               
    
  


   
                                                                
    
  




   
                                                                                        
  
static volatile FlagStatus s_xTIMChCompareModeRaised = RESET;

#define XTAL_FREQUENCY          50000000 


   
                                                                                        
  
static uint8_t s_RfModuleBand = 0, s_Tcxo=0;
static int32_t s_RfModuleOffset=0;
static TIM_HandleTypeDef  TimHandle;
static RangeExtType s_RangeExtType = RANGE_EXT_NONE;
static S2LPCutType s_S2LPCut = S2LP_CUT_2_1;

   
                                                                          
    
  

   
                                                                                      
    
  
void S2LPRadioSetXtalFrequency(uint32_t lXtalFrequency);
uint8_t SpiritQiGetLqi(void);
   
                                                    
              
               
  
void TIM3_IRQHandler(void)
{
  HAL_TIM_IRQHandler(&TimHandle);
}

void HAL_TIM_IC_CaptureCallback(TIM_HandleTypeDef *htim) 
{
  s_xTIMChCompareModeRaised = SET;
}


void S2LPManagementEnableTcxo(void)
{
  __GPIOC_CLK_ENABLE();
  HAL_GPIO_Init(GPIOC, &(GPIO_InitTypeDef){GPIO_PIN_7, GPIO_MODE_OUTPUT_PP, GPIO_NOPULL, GPIO_SPEED_HIGH });
  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_7, GPIO_PIN_SET);
}

void S2LPManagementRangeExtInit(void)
{
 
  if(s_RangeExtType==RANGE_EXT_SKYWORKS_868)
  {
    uint8_t tmp[3]={0x92,0x52,0x2A};
    S2LPSpiWriteRegisters(0x00, 3, tmp);
  }
}

RangeExtType S2LPManagementGetRangeExtender(void)
{
  return s_RangeExtType;
}

S2LPCutType S2LPManagementGetCut(void)
{
  return s_S2LPCut;
}

           void S2LPManagementSetRangeExtender(RangeExtType xRangeType)
{
  s_RangeExtType = xRangeType;
}

           void S2LPManagementSetTcxo(uint8_t tcxo)
{
  s_Tcxo = tcxo;
}

uint8_t S2LPManagementGetTcxo(void)
{
  return s_Tcxo;
}

void S2LPManagementTcxoInit(void)
{
  if(s_Tcxo)
  {
    S2LPManagementEnableTcxo();
    
    uint8_t tmp;
    S2LPSpiReadRegisters(0x6D, 1, &tmp);
    tmp|=0x80;
    S2LPSpiWriteRegisters(0x6D, 1, &tmp);
  }
}

   
                                                                                                 
                                                                       
               
               
  
uint32_t S2LPManagementComputeXtalFrequency(void)
{   
  uint32_t lMeasuredXtalFrequency;
  
  
#if defined(USE_STM32L0XX_NUCLEO) || defined(USE_STM32F0XX_NUCLEO)|| defined(USE_STM32L1XX_NUCLEO) || defined(USE_STM32F4XX_NUCLEO)
  lMeasuredXtalFrequency=50000000;
#else
  uint8_t tmp;
  
#define N_SAMPLES 20
#define SETTLING_PERIODS 40
#define A 0.4
  
  GPIO_TypeDef *pGpioPeriph;
  GPIO_InitTypeDef GPIO_InitStructure;
  TIM_IC_InitTypeDef     sICConfig;
  
  
  TimHandle.Instance = TIM3;
  pGpioPeriph=GPIOB;
                         
  __HAL_RCC_TIM3_CLK_ENABLE();
                          
  __GPIOB_CLK_ENABLE();
      
                                                                 
  uint8_t CaptureNumber=0;
  uint16_t IC3ReadValue1=0,IC3ReadValue2=0,Capture=0;
  volatile uint16_t cWtchdg = 0;
  uint32_t TIMFreq=0,lXoFreq=0;
  float fXoFreqRounded;

                                                
  GPIO_InitStructure.Mode  = GPIO_MODE_AF_PP;
  GPIO_InitStructure.Speed = GPIO_SPEED_HIGH;
  GPIO_InitStructure.Pull  = GPIO_PULLUP;
  GPIO_InitStructure.Pin   = GPIO_PIN_0;

  GPIO_InitStructure.Alternate   = GPIO_AF2_TIM3;
  
  HAL_GPIO_Init(pGpioPeriph, &GPIO_InitStructure);
    
                                                                 
  sICConfig.ICPolarity  = TIM_ICPOLARITY_RISING;
  
                                       
  sICConfig.ICSelection = TIM_ICSELECTION_DIRECTTI;
   
                                                                                                                                           
  sICConfig.ICPrescaler = TIM_ICPSC_DIV8;
  
                                            
  sICConfig.ICFilter = 0x0;

                            
  HAL_TIM_IC_ConfigChannel(&TimHandle, &sICConfig, TIM_CHANNEL_3);
  
                          
  HAL_TIM_IC_Start_IT(&TimHandle, TIM_CHANNEL_3);
        
  HAL_NVIC_SetPriority(TIM3_IRQn, 0x0F, 0x0F);
  HAL_NVIC_EnableIRQ(TIM3_IRQn);
 
  
                                                                            
                                  
  tmp=0x55;
  S2LPSpiWriteRegisters(0x6C, 1, &tmp);
    
                                 
                                                                                                           
  tmp=0x88|0x02;
  S2LPSpiWriteRegisters(0x02, 1, &tmp);
  
  S2LPSpiReadRegisters(0xF1, 1, &tmp);
  if((tmp&0x80)==0)
  {             
    tmp=0x9E;
  }
  else
  {
    tmp=0x90;
  }
  S2LPSpiWriteRegisters(0x04, 1, &tmp);

                                  
  
  
                                                                                                           
  for(uint32_t i=0;i<2*(N_SAMPLES+SETTLING_PERIODS);i++) {
                                                            
    while(!s_xTIMChCompareModeRaised && (cWtchdg!=0xFFFF)) {
      cWtchdg++;    
    }
    
    if(cWtchdg==0xFFFF) {
      break;
    }
    else {
      cWtchdg=0;
    }
    
                                   
    s_xTIMChCompareModeRaised = RESET;
    
                                         
    if(i>=SETTLING_PERIODS*2) {
                               
      if(CaptureNumber == 0)
      {
                                         
        IC3ReadValue1 = HAL_TIM_ReadCapturedValue(&TimHandle, TIM_CHANNEL_3);
        CaptureNumber = 1;
      }
                                
      else if(CaptureNumber == 1)
      {
                                         
        IC3ReadValue2 = HAL_TIM_ReadCapturedValue(&TimHandle, TIM_CHANNEL_3);
        
                                 
        if (IC3ReadValue2 > IC3ReadValue1)
        {
                                                                                                                                                                    
          Capture = (IC3ReadValue2 - IC3ReadValue1) - 1;
        }
        else
        {
                                                                                            
          Capture = ((0xFFFF - IC3ReadValue1) + IC3ReadValue2) - 1;
        }
        
                                            
        TIMFreq = (uint32_t) SystemCoreClock / Capture;
        
                                            
     
   lXoFreq =(uint32_t)(A*(float)lXoFreq+(1.0-A)*(float)TIMFreq);

        CaptureNumber = 0;
      }
    }
  }
                 
  
                                                                                         

  S2LPSpiReadRegisters(0xF1, 1, &tmp);
               
  if((tmp&0x80)==0)
  {
    lXoFreq *=(192*8);
  }
               
  else
  {
    lXoFreq *=(256*8);
  }
  
                                
  tmp=0x00;
  S2LPSpiWriteRegisters(0x04, 1, &tmp);
                                   
  
                           
  HAL_TIM_IC_Stop(&TimHandle, TIM_CHANNEL_3);
    
  RadioGpioInit(RADIO_GPIO_2, RADIO_MODE_GPIO_IN);
  
                                                
  tmp=0xA2;
  S2LPSpiWriteRegisters(0x02, 1, &tmp);
                                       

                                 
  tmp=0x45;
  S2LPSpiWriteRegisters(0x6C, 1, &tmp);
    
                                                                           
  fXoFreqRounded = (float)lXoFreq/1e6;
  
  if( fXoFreqRounded-(float)((uint32_t)fXoFreqRounded)>0.5)
  {
    lMeasuredXtalFrequency = (((uint32_t)fXoFreqRounded+1)*1000000);
  }
  else
  {
    lMeasuredXtalFrequency = (((uint32_t)fXoFreqRounded)*1000000);
  }
  
#endif  
  
  S2LPRadioSetXtalFrequency(lMeasuredXtalFrequency);

  return lMeasuredXtalFrequency;
}


uint32_t S2LPManagementComputeXtalFrequencyGpio2(void)
{
  return S2LPManagementComputeXtalFrequency();
}




uint32_t S2LPManagementComputeRcoFrequency(void)
{   
  uint32_t lMeasuredRcoFrequency;
  
#if defined(USE_STM32L0XX_NUCLEO)  || defined(USE_STM32F0XX_NUCLEO)
  lMeasuredRcoFrequency=33330;
#else
  uint8_t tmp;
  
#define RCO_SETTLING_PERIODS            4000
#define RCO_N_SAMPLES                   10000
  
  HAL_NVIC_DisableIRQ(TIM2_IRQn);
  
  GPIO_TypeDef *pGpioPeriph;
  GPIO_InitTypeDef GPIO_InitStructure;
  TIM_IC_InitTypeDef     sICConfig;
  
 
  TimHandle.Instance = TIM3;
  pGpioPeriph=GPIOB;
  __HAL_RCC_TIM3_CLK_ENABLE();
  __GPIOB_CLK_ENABLE();
 

                                                                 
  uint8_t CaptureNumber=0;
  uint16_t IC3ReadValue1=0,IC3ReadValue2=0,Capture=0;
  volatile uint16_t cWtchdg = 0;
  uint32_t TIMFreq=0,lXoFreq=0;

  
 
  GPIO_InitStructure.Mode  = GPIO_MODE_AF_PP;
  GPIO_InitStructure.Speed = GPIO_SPEED_HIGH;
  GPIO_InitStructure.Pull  = GPIO_PULLUP;
  GPIO_InitStructure.Pin   = GPIO_PIN_0;

  GPIO_InitStructure.Alternate   = GPIO_AF2_TIM3;
 
  HAL_GPIO_Init(pGpioPeriph, &GPIO_InitStructure);
    
                                                                 
  sICConfig.ICPolarity  = TIM_ICPOLARITY_RISING;
  
                                       
  sICConfig.ICSelection = TIM_ICSELECTION_DIRECTTI;
   
                                                                                                                                           
  sICConfig.ICPrescaler = TIM_ICPSC_DIV1;
  
                                            
  sICConfig.ICFilter = 0x0;

                            
  HAL_TIM_IC_ConfigChannel(&TimHandle, &sICConfig, TIM_CHANNEL_3);
  
                          
  HAL_TIM_IC_Start_IT(&TimHandle, TIM_CHANNEL_3);
        
  
  HAL_NVIC_SetPriority(TIM3_IRQn, 0x0F, 0x0F);
  HAL_NVIC_EnableIRQ(TIM3_IRQn);
  
  
                                                                            
                                  
  tmp=0x55;
  S2LPSpiWriteRegisters(0x6C, 1, &tmp);
  
  S2LPSpiReadRegisters(0xF1, 1, &tmp);
  tmp=0x88|0x02;
  S2LPSpiWriteRegisters(0x02, 1, &tmp);
  
  S2LPSpiReadRegisters(0xF1, 1, &tmp);
  if((tmp&0x80)==0)
  {             
    tmp=0x9E;
  }
  else
  {
    tmp=0x90;
  }
  S2LPSpiWriteRegisters(0x04, 1, &tmp);
    
                
  S2LPCmdStrobeSleep();
  
  
  uint32_t n=0;
  
                                                                                                           
  for(uint32_t i=0;i<2*(RCO_N_SAMPLES+RCO_SETTLING_PERIODS);i++) {
                                                            
    while(!s_xTIMChCompareModeRaised && (cWtchdg!=0xFFFF)) {
      cWtchdg++;    
    }
    HAL_TIM_IRQHandler(&TimHandle);
    
    if(cWtchdg==0xFFFF) {
      break;
    }
    else {
      cWtchdg=0;
    }
    
                                   
    s_xTIMChCompareModeRaised = RESET;
    
                                         
    if(i>=RCO_SETTLING_PERIODS*2) {
                               
      if(CaptureNumber == 0)
      {
                                         
        IC3ReadValue1 = HAL_TIM_ReadCapturedValue(&TimHandle, TIM_CHANNEL_3);
        CaptureNumber = 1;
      }
                                
      else if(CaptureNumber == 1)
      {
                                         
        IC3ReadValue2 = HAL_TIM_ReadCapturedValue(&TimHandle, TIM_CHANNEL_3);
        
                                 
        if (IC3ReadValue2 > IC3ReadValue1)
        {
                                                                                                                                                                    
          Capture = (IC3ReadValue2 - IC3ReadValue1) - 1;
        }
        else
        {
                                                                                            
          Capture = ((0xFFFF - IC3ReadValue1) + IC3ReadValue2) - 1;
        }
        
                                            
        TIMFreq = (uint32_t) SystemCoreClock / Capture;
        
        lXoFreq+=TIMFreq;
        n++;
        
        CaptureNumber = 0;
      }
    }
  }
  
                                                                                         
  
  lXoFreq/=n;
  
  
                                
  tmp=0x00;
  S2LPSpiWriteRegisters(0x04, 1, &tmp);
                                   
  
  
                           
  HAL_TIM_IC_Stop(&TimHandle, TIM_CHANNEL_3);
    
  RadioGpioInit(RADIO_GPIO_2, RADIO_MODE_GPIO_IN);
  
                                               
                                       
  tmp=0xA2;
  S2LPSpiWriteRegisters(0x02, 1, &tmp);
  
                                 
  tmp=0x45;
  S2LPSpiWriteRegisters(0x6C, 1, &tmp);
  
                                                            
  
  lMeasuredRcoFrequency=lXoFreq;
  
  HAL_NVIC_EnableIRQ(TIM2_IRQn);
  S2LPCmdStrobeReady();
  
#endif
  
  return lMeasuredRcoFrequency;
}


   
                                   
              
                
  
uint8_t EepromIdentification(void)
{
  uint8_t status;
  
                                           
  status = EepromStatus();
  
  if((status&0xF0) == EEPROM_STATUS_SRWD) {
                                                                                 
    status=1;
  }
  else
  {
    EepromWriteEnable();
    SdkDelayMs(10);
                                                                                   
    status = EepromSetSrwd();
    SdkDelayMs(10);
                   
    status = EepromStatus();
    if((status&0xF0) == EEPROM_STATUS_SRWD) {                          
                                                                                   
      status=1;
    }
    else
    {
                                     
      status = 0;
    }
  }
  return status;
}


void S2LPManagementSetBand(uint8_t value)
{
  s_RfModuleBand = value;
}

uint8_t S2LPManagementGetBand(void)
{
  return s_RfModuleBand;
}

void S2LPManagementSetOffset(int32_t value)
{
  s_RfModuleOffset=value;
}

int32_t S2LPManagementGetOffset(void)
{
  return s_RfModuleOffset;
}



#if defined(NO_EEPROM) && (USE_WMBUS)
   
                                                         
              
                
  
void S2LPManagementIdentificationRFBoard(void)
{
  do{
                                    
    for(volatile uint8_t i=0; i!=0xFF; i++);
    
                                      
    S2LPRefreshStatus();
  }while(g_xStatus.MC_STATE!=MC_STATE_READY);

    S2LPRadioSetXtalFrequency(XTAL_FREQUENCY);        
}
#else

void S2LPManagementIdentificationRFBoard(void)
{
  uint8_t tmp;
  StatusBytes status;
  
  do{
                                    
    for(volatile uint8_t i=0; i!=0xFF; i++);
    
                                      
    status = S2LPSpiReadRegisters(0x8E, 1, &tmp);
  }  while(status.MC_STATE!=MC_STATE_READY);

  RadioSpiReadRegisters(0xF1, 1, &tmp);
  
    
  s_S2LPCut=(S2LPCutType)tmp;
  
  if((s_S2LPCut==S2LP_CUT_2_0) || (s_S2LPCut==S2LP_CUT_2_1))
  {
    
    S2LPEnterShutdown();
  }

  RadioSetHasEeprom(EepromIdentification());

  if(!RadioGetHasEeprom())                         
  {
    S2LPExitShutdown();
    if(S2LPManagementComputeXtalFrequency()==0)
    {
                                         
      S2LPRadioSetXtalFrequency(50000000);
    }
  }
  else                 
  {
                                          
    uint8_t tmpBuffer[32];
    EepromRead(0x0000, 32, tmpBuffer);
    uint32_t xtal;
    float foffset=0;
    if(tmpBuffer[0]==0 || tmpBuffer[0]==0xFF) {
                                                                             
      S2LPManagementEnableTcxo();
      if((s_S2LPCut==S2LP_CUT_2_0) || (s_S2LPCut==S2LP_CUT_2_1))
      {
        S2LPExitShutdown();
      }
      S2LPManagementComputeXtalFrequency();
      return;
    }
    switch(tmpBuffer[1]) {
    case 0:
      xtal = 24000000;
      S2LPRadioSetXtalFrequency(xtal);
      break;
    case 1:
      xtal = 25000000;
      S2LPRadioSetXtalFrequency(xtal);
      break;
    case 2:
      xtal = 26000000;
      S2LPRadioSetXtalFrequency(xtal);
      break;
    case 3:
      xtal = 48000000;
      S2LPRadioSetXtalFrequency(xtal);
      break;
    case 4:
      xtal = 50000000;
      S2LPRadioSetXtalFrequency(xtal);
      break;
    case 5:
      xtal = 52000000;
      S2LPRadioSetXtalFrequency(xtal);
      break;
    case 0xff:
                                    
      for(uint8_t i=0;i<4;i++)
      {
        ((uint8_t*)&xtal)[i]=tmpBuffer[30-i];
      }
      S2LPRadioSetXtalFrequency(xtal);
      break;
    default:
      S2LPManagementComputeXtalFrequency();
      break;
    }
        
                    
    if(tmpBuffer[31]==1)
    {
      S2LPManagementSetTcxo(1);
    }
    
    S2LPManagementSetBand(tmpBuffer[3]);
    
    S2LPManagementSetRangeExtender((RangeExtType)tmpBuffer[5]);    
    
    EepromRead(0x0021,4,tmpBuffer);
    for(uint8_t i=0;i<4;i++)
    {
      ((uint8_t*)&foffset)[i]=tmpBuffer[3-i];
    }
  
    S2LPManagementSetOffset((int32_t)foffset);
  }
  
  if((s_S2LPCut==S2LP_CUT_2_0) || (s_S2LPCut==S2LP_CUT_2_1))
  {
    S2LPExitShutdown();
  }
  
  
  
  
}
#endif

void S2LPManagementRcoCalibration(void)
{
  uint8_t tmp[2],tmp2;
                                        
  S2LPSpiReadRegisters(0x6D, 1, &tmp2);
  tmp2 |= 0x01;
  S2LPSpiWriteRegisters(0x6D, 1, &tmp2);  

  S2LPCmdStrobeStandby();
  SdkDelayMs(100);
  S2LPCmdStrobeReady();

  do
  {
    S2LPSpiReadRegisters(0x8D, 1, tmp);
  }
  while((tmp[0]&0x10)==0);
  
  
  
  S2LPSpiReadRegisters(0x94, 2, tmp);
  S2LPSpiReadRegisters(0x6F, 1, &tmp2);
  tmp[1]=(tmp[1]&0x80)|(tmp2&0x7F);
  
  S2LPSpiWriteRegisters(0x6E, 2, tmp);
  
  S2LPSpiReadRegisters(0x6D, 1, &tmp2);
  tmp2 &= 0xFE;
  S2LPSpiWriteRegisters(0x6D, 1, &tmp2);

}



   
                                 
                
                             
   
uint8_t S2LPQiGetLqi(void)
{
  uint8_t tempRegValue;

                                             
  g_xStatus = S2LPSpiReadRegisters(LINK_QUALIF2_ADDR, 1, &tempRegValue);

                                        
  return ((tempRegValue & 0xF0)>> 4);

}

   
                                           
                                              
                               
               
  
void Config_RangeExt(PA_OperationType operation,RangeExtType rangeExtType)
{

  switch (operation)
  {
  case PA_SHUTDOWN:
    {
	if(rangeExtType == RANGE_EXT_SKYWORKS_SKY66420)
	{
	                                   
	  HAL_GPIO_WritePin(PA_CSD_PORT, PA_CSD_PIN, GPIO_PIN_RESET);

	                                                  
	  HAL_GPIO_WritePin(PA_CTX_PORT, PA_CTX_PIN, GPIO_PIN_SET);

	                                        
	  HAL_GPIO_WritePin(PA_CPS_PORT, PA_CPS_PIN, GPIO_PIN_RESET);
	}

	break;
    }
  case PA_TX_BYPASS:
    {
	if(rangeExtType == RANGE_EXT_SKYWORKS_SKY66420)
	{
	                          
	  HAL_GPIO_WritePin(PA_CPS_PORT, PA_CPS_PIN, GPIO_PIN_RESET);

	                                   
	  HAL_GPIO_WritePin(PA_CSD_PORT, PA_CSD_PIN, GPIO_PIN_SET);

	                                       
	  HAL_GPIO_WritePin(PA_CTX_PORT, PA_CTX_PIN, GPIO_PIN_SET);
	}

	break;
    }
  case PA_TX:
    {
	if(rangeExtType == RANGE_EXT_SKYWORKS_SKY66420)
	{
	                         
                        
                                                                  
         
	  HAL_GPIO_WritePin(PA_CPS_PORT, PA_CPS_PIN, GPIO_PIN_SET);

	                                   
	  HAL_GPIO_WritePin(PA_CSD_PORT, PA_CSD_PIN, GPIO_PIN_SET);

	                                       
	  HAL_GPIO_WritePin(PA_CTX_PORT, PA_CTX_PIN, GPIO_PIN_SET);
	}

	break;
    }
  case PA_RX:
    {
	if(rangeExtType == RANGE_EXT_SKYWORKS_SKY66420)
	{
	                                   
	  HAL_GPIO_WritePin(PA_CSD_PORT, PA_CSD_PIN, GPIO_PIN_SET);

	                    
	  HAL_GPIO_WritePin(PA_CTX_PORT, PA_CTX_PIN, GPIO_PIN_RESET);

	                                        
	  HAL_GPIO_WritePin(PA_CPS_PORT, PA_CPS_PIN, GPIO_PIN_SET);
	}

	break;
    }
  default:
               
    break;
  }
}  
   
    
  



   
    
  


   
    
  

   
    
  


/******************* (C) COPYRIGHT 2016 STMicroelectronics *****END OF FILE****/
