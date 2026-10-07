/**
  ******************************************************************************
  * @file    stm32l4xx_nucleo.c
  * @author  MCD Application Team
  * @brief   This file provides set of firmware functions to manage:
  *          - LEDs and push-button available on STM32L4XX-Nucleo Kit
  *            from STMicroelectronics
  *          - LCD, joystick and microSD available on Adafruit 1.8" TFT LCD
  *            shield (reference ID 802), external SMPS
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2015 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */

                                                                                
#include "stm32l4xx_nucleo.h"

                   
      
    

                                        
                                                                                      
                                                                     
                                                                               
                                                          
      
    


                                                                  
      
    

   
                                                     
    
#define __STM32L4XX_NUCLEO_BSP_VERSION_MAIN   (0x02)                             
#define __STM32L4XX_NUCLEO_BSP_VERSION_SUB1   (0x01)                             
#define __STM32L4XX_NUCLEO_BSP_VERSION_SUB2   (0x08)                             
#define __STM32L4XX_NUCLEO_BSP_VERSION_RC     (0x00)                                 
#define __STM32L4XX_NUCLEO_BSP_VERSION       ((__STM32L4XX_NUCLEO_BSP_VERSION_MAIN << 24)\
                                             |(__STM32L4XX_NUCLEO_BSP_VERSION_SUB1 << 16)\
                                             |(__STM32L4XX_NUCLEO_BSP_VERSION_SUB2 << 8 )\
                                             |(__STM32L4XX_NUCLEO_BSP_VERSION_RC))

   
                       
    
#define SD_DUMMY_BYTE            0xFF
#define SD_NO_RESPONSE_EXPECTED  0x80


#ifdef USE_STM32L4XX_NUCLEO_64_SMPS

   
               
    


#ifdef USE_ADP5301ACBZ                           

                                                                              
                                                                              
                                                                              
                                                                              
                                                                              

                                                                              
                                                                              
                                                                              

#endif                                           

   
      
    

#endif                                   

                                                                  
      
    
#ifdef USE_STM32L4XX_NUCLEO_64_SMPS
GPIO_TypeDef *GPIO_PORT[LEDn] = {LED4_GPIO_PORT};
const uint16_t GPIO_PIN[LEDn] = {LED4_PIN};
#else
GPIO_TypeDef *GPIO_PORT[LEDn] = {LED2_GPIO_PORT};
const uint16_t GPIO_PIN[LEDn] = {LED2_PIN};
#endif

GPIO_TypeDef  *BUTTON_PORT[BUTTONn] = {USER_BUTTON_GPIO_PORT};
const uint16_t BUTTON_PIN[BUTTONn] = {USER_BUTTON_PIN};
const uint16_t BUTTON_IRQn[BUTTONn] = {USER_BUTTON_EXTI_IRQn};

   
                       
   

#ifdef HAL_SPI_MODULE_ENABLED
uint32_t hnucleo_SpixTimeout = NUCLEO_SPIx_TIMEOUT_MAX;                                                             
static SPI_HandleTypeDef hnucleo_Spi;
#endif                             

#ifdef HAL_ADC_MODULE_ENABLED
static ADC_HandleTypeDef hnucleo_Adc;
                                                     
static ADC_ChannelConfTypeDef hnucleo_AdcChannelConfig;
#endif                             

   
      
    

                                 
#ifdef HAL_SPI_MODULE_ENABLED
static void               SPIx_Init(void);
static void               SPIx_MspInit(void);
static void               SPIx_Write(uint8_t Value);
static void               SPIx_WriteReadData(const uint8_t *DataIn, uint8_t *DataOut, uint16_t DataLength);
static void               SPIx_Error(void);
#endif                             

#ifdef HAL_ADC_MODULE_ENABLED
static HAL_StatusTypeDef  ADCx_Init(void);
static void               ADCx_DeInit(void);
static void               ADCx_MspInit(ADC_HandleTypeDef *hadc);
static void               ADCx_MspDeInit(ADC_HandleTypeDef *hadc);
#endif                             

#ifdef HAL_SPI_MODULE_ENABLED
                     
void                      SD_IO_Init(void);
void                      SD_IO_CSState(uint8_t state);
void                      SD_IO_WriteReadData(const uint8_t *DataIn, uint8_t *DataOut, uint16_t DataLength);
uint8_t                   SD_IO_WriteByte(uint8_t Data);

                      
void                      LCD_IO_Init(void);
void                      LCD_IO_WriteMultipleData(uint8_t *pData, uint32_t Size);
void                      LCD_IO_WriteReg(uint8_t LCDReg);
void                      LCD_Delay(uint32_t delay);
#endif                             

                                                                    
      
    

   
                                                                        
                                                               
    
uint32_t BSP_GetVersion(void)
{
  return __STM32L4XX_NUCLEO_BSP_VERSION;
}

                                                          
      
    

   
                               
                                      
                                                              
                                                                 
                
    
void BSP_LED_Init(Led_TypeDef Led)
{
  GPIO_InitTypeDef  GPIO_InitStruct = {0};

                                 
  LEDx_GPIO_CLK_ENABLE(Led);

                                  
  GPIO_InitStruct.Pin   = GPIO_PIN[Led];
  GPIO_InitStruct.Mode  = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull  = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
  HAL_GPIO_Init(GPIO_PORT[Led], &GPIO_InitStruct);
}

   
                                  
                                         
                                                              
                                                                 
                                                          
                
    
void BSP_LED_DeInit(Led_TypeDef Led)
{
  GPIO_InitTypeDef  GPIO_InitStruct;

                    
  HAL_GPIO_WritePin(GPIO_PORT[Led], GPIO_PIN[Led], GPIO_PIN_RESET);
                               
  GPIO_InitStruct.Pin = GPIO_PIN[Led];
  HAL_GPIO_DeInit(GPIO_PORT[Led], GPIO_InitStruct.Pin);
}

   
                                 
                                                
                                                        
                                                                 
                
    
void BSP_LED_On(Led_TypeDef Led)
{
  HAL_GPIO_WritePin(GPIO_PORT[Led], GPIO_PIN[Led], GPIO_PIN_SET);
}

   
                                  
                                                 
                                                        
                                                                 
                
    
void BSP_LED_Off(Led_TypeDef Led)
{
  HAL_GPIO_WritePin(GPIO_PORT[Led], GPIO_PIN[Led], GPIO_PIN_RESET);
}

   
                                    
                                                 
                                                        
                                                                 
                
    
void BSP_LED_Toggle(Led_TypeDef Led)
{
  HAL_GPIO_TogglePin(GPIO_PORT[Led], GPIO_PIN[Led]);
}

   
      
    

                                                                
      
    

   
                                                
                                                          
                                           
                                              
                                                        
                                                               
                                                                                   
                                                    
                
    
void BSP_PB_Init(Button_TypeDef Button, ButtonMode_TypeDef ButtonMode)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

                               
  BUTTONx_GPIO_CLK_ENABLE(Button);

  if (ButtonMode == BUTTON_MODE_GPIO)
  {
                                       
    GPIO_InitStruct.Pin    = BUTTON_PIN[Button];
    GPIO_InitStruct.Mode   = GPIO_MODE_INPUT;
    GPIO_InitStruct.Pull   = GPIO_NOPULL;
    GPIO_InitStruct.Speed  = GPIO_SPEED_FREQ_HIGH;

    HAL_GPIO_Init(BUTTON_PORT[Button], &GPIO_InitStruct);
  }
  else if (ButtonMode == BUTTON_MODE_EXTI)
  {
                                                               
    GPIO_InitStruct.Pin    = BUTTON_PIN[Button];
    GPIO_InitStruct.Mode   = GPIO_MODE_IT_FALLING;
    GPIO_InitStruct.Pull   = GPIO_NOPULL;
    GPIO_InitStruct.Speed  = GPIO_SPEED_FREQ_HIGH;
    HAL_GPIO_Init(BUTTON_PORT[Button], &GPIO_InitStruct);

                                                                     
    HAL_NVIC_SetPriority((IRQn_Type)(BUTTON_IRQn[Button]), 0x0F, 0);
    HAL_NVIC_EnableIRQ((IRQn_Type)(BUTTON_IRQn[Button]));
  }
}

   
                                     
                                           
                                           
                                                         
                
    
void BSP_PB_DeInit(Button_TypeDef Button)
{
  GPIO_InitTypeDef GPIO_InitStruct;

  GPIO_InitStruct.Pin = BUTTON_PIN[Button];
  HAL_NVIC_DisableIRQ((IRQn_Type)(BUTTON_IRQn[Button]));
  HAL_GPIO_DeInit(BUTTON_PORT[Button], GPIO_InitStruct.Pin);
}

   
                                             
                                                       
                                           
                         
    
uint32_t BSP_PB_GetState(Button_TypeDef Button)
{
  return HAL_GPIO_ReadPin(BUTTON_PORT[Button], BUTTON_PIN[Button]);
}

#ifdef HAL_ADC_MODULE_ENABLED
   
                                                                    
                                                 
                                                  
    
uint8_t BSP_JOY_Init(void)
{
  if (ADCx_Init() != HAL_OK)
  {
    return (uint8_t) HAL_ERROR;
  }

                                          
  hnucleo_AdcChannelConfig.Channel       = NUCLEO_ADCx_CHANNEL;
  hnucleo_AdcChannelConfig.SamplingTime  = ADC_SAMPLETIME_24CYCLES_5;
  hnucleo_AdcChannelConfig.Rank          = ADC_REGULAR_RANK_1;
  hnucleo_AdcChannelConfig.SingleDiff    = ADC_SINGLE_ENDED;
  hnucleo_AdcChannelConfig.OffsetNumber  = ADC_OFFSET_NONE;

                                             
  return (uint8_t) HAL_ADC_ConfigChannel(&hnucleo_Adc, &hnucleo_AdcChannelConfig);
}

   
                                        
                                                                                                          
                 
    
void BSP_JOY_DeInit(void)
{
  ADCx_DeInit();
}

   
                                            
                                                                               
                                    
                                    
                                      
                                   
                                    
                                     
                                     
                                                               
    
JOYState_TypeDef BSP_JOY_GetState(void)
{
  JOYState_TypeDef state = JOY_NONE;
  uint16_t  keyconvertedvalue = 0;

                                    
  HAL_ADC_Start(&hnucleo_Adc);

                                      
  HAL_ADC_PollForConversion(&hnucleo_Adc, 10);

                                                                         
  if (HAL_ADC_GetState(&hnucleo_Adc) & HAL_ADC_STATE_REG_EOC)
  {
                                                    
    keyconvertedvalue = HAL_ADC_GetValue(&hnucleo_Adc);
  }

  if ((keyconvertedvalue > 1980) && (keyconvertedvalue < 2120))
  {
    state = JOY_UP;
  }
  else if ((keyconvertedvalue > 630) && (keyconvertedvalue < 830))
  {
    state = JOY_RIGHT;
  }
  else if ((keyconvertedvalue > 1210) && (keyconvertedvalue < 1410))
  {
    state = JOY_SEL;
  }
  else if ((keyconvertedvalue > 20) && (keyconvertedvalue < 160))
  {
    state = JOY_DOWN;
  }
  else if ((keyconvertedvalue > 3620) && (keyconvertedvalue < 3820))
  {
    state = JOY_LEFT;
  }
  else
  {
    state = JOY_NONE;
  }

                                                  
  return state;
}

#endif                             
   
      
    


#ifdef USE_STM32L4XX_NUCLEO_64_SMPS
#ifdef USE_ADP5301ACBZ                           

                                                            
      
    

                                                                               
                                           
                                                                                

   
                                                    
                                               
                       
    
uint32_t BSP_SMPS_DeInit(void)
{
  GPIO_InitTypeDef GPIO_InitStruct;

  PWR_AND_CLK_SMPS();

                                                                                               
                                                                                               

                           
  HAL_GPIO_WritePin(PORT_SMPS, PIN_SMPS_SWITCH_ENABLE, GPIO_PIN_RESET);

  HAL_Delay(1);

                    
  HAL_GPIO_WritePin(PORT_SMPS, PIN_SMPS_ENABLE, GPIO_PIN_RESET);

                                                                                               
                                                                                    
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  GPIO_InitStruct.Pull =  GPIO_PULLDOWN;

                                                              
  GPIO_InitStruct.Pin = PIN_SMPS_ENABLE | PIN_SMPS_SWITCH_ENABLE | PIN_SMPS_POWERGOOD;
  HAL_GPIO_Init(PORT_SMPS, &GPIO_InitStruct);

  return SMPS_OK;
}

   
                                                  
                                                      
                                           
                                                              
                                                                    
                       
    
uint32_t BSP_SMPS_Init(uint32_t VoltageRange)
{
  PWR_AND_CLK_SMPS();

  GPIO_InitTypeDef GPIO_InitStruct;

                                                                  
                                                                  
                                                                   
  if (!(READ_BIT(PWR->PWR_PU_REG, PWR_GPIO_ENABLE)))
  {
    HAL_PWREx_EnableGPIOPullDown(PWR_GPIO_SMPS, PWR_GPIO_SWITCH_ENABLE);
    HAL_PWREx_EnableGPIOPullDown(PWR_GPIO_SMPS, PWR_GPIO_ENABLE);

                                                                                
                                                   
    HAL_PWREx_EnableGPIOPullUp(PWR_GPIO_A, GPIO_PIN_2);                 
    HAL_PWREx_EnableGPIOPullUp(PWR_GPIO_A, GPIO_PIN_13);                 
    HAL_PWREx_EnableGPIOPullUp(PWR_GPIO_B, GPIO_PIN_3);                 

                                                                   
                                                                   
                                                              
                                           
  }
                                                                                
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  GPIO_InitStruct.Pull = GPIO_PULLUP;

  GPIO_InitStruct.Pin = PIN_SMPS_POWERGOOD;
  HAL_GPIO_Init(PORT_SMPS, &GPIO_InitStruct);

                                                                                

  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  GPIO_InitStruct.Pull = GPIO_NOPULL;

  GPIO_InitStruct.Pin = PIN_SMPS_ENABLE | PIN_SMPS_SWITCH_ENABLE;
  HAL_GPIO_Init(PORT_SMPS, &GPIO_InitStruct);

                                                                                
                                                                                
                                                   
                                                                                
                                      
                           

                              
                                                   
                                                                
                              
                              
            

       
                              
                              
                              
                              
                                                                  
                                                                                
  return SMPS_OK;
}

   
                                              
                                           
                                                     
                                                          
                           
                       
                                          
                                                  
    
uint32_t BSP_SMPS_Enable(uint32_t Delay, uint32_t Power_Good_Check)
{
  PWR_AND_CLK_SMPS();

  HAL_GPIO_WritePin(PORT_SMPS, PIN_SMPS_ENABLE, GPIO_PIN_SET);

                          
  if (Delay != 0)
  {
    HAL_Delay(Delay);
  }

                               
  if (Power_Good_Check != 0)
  {
    if (GPIO_PIN_RESET == (HAL_GPIO_ReadPin(PORT_SMPS, PIN_SMPS_POWERGOOD)))
    {
                         
      return SMPS_KO;
    }
  }

                    
  return SMPS_OK;
}

   
                                               
                                                  
                       
                                                  
                                                  
   
    
uint32_t BSP_SMPS_Disable(void)
{

  PWR_AND_CLK_SMPS();

                                        
  if (HAL_GPIO_ReadPin(PORT_SMPS, PIN_SMPS_SWITCH_ENABLE) != GPIO_PIN_RESET)
  {
                                            
    return SMPS_KO;
  }

                    
  HAL_GPIO_WritePin(PORT_SMPS, PIN_SMPS_ENABLE, GPIO_PIN_RESET);

                     
  return SMPS_OK;
}

   
                                                     
                                                        
                                                     
                                                        
                       
                                          
                                                  
    
uint32_t BSP_SMPS_Supply_Enable(uint32_t Delay, uint32_t Power_Good_Check)
{
  PWR_AND_CLK_SMPS();

  if (Delay != 0)
  {
    HAL_Delay(Delay);
  }
                               
  if (Power_Good_Check != 0)
  {
    if (GPIO_PIN_RESET == (HAL_GPIO_ReadPin(PORT_SMPS, PIN_SMPS_POWERGOOD)))
    {
                         
      return SMPS_KO;
    }
  }

                          
  HAL_GPIO_WritePin(PORT_SMPS, PIN_SMPS_SWITCH_ENABLE, GPIO_PIN_SET);


  return SMPS_OK;
}

   
                                                      
                       
                                                  
    
uint32_t BSP_SMPS_Supply_Disable(void)
{
  PWR_AND_CLK_SMPS();

                           
  HAL_GPIO_WritePin(PORT_SMPS, PIN_SMPS_SWITCH_ENABLE, GPIO_PIN_RESET);

  return SMPS_OK;
}

#endif                  
#endif                                   

   
      
    

   
      
    

                                                                  
      
    

#ifdef HAL_SPI_MODULE_ENABLED
                                                                               
                                          
                                                                                
   
                               
                
    
static void SPIx_MspInit(void)
{
  GPIO_InitTypeDef  GPIO_InitStruct = {0};

                               
                         
  NUCLEO_SPIx_SCK_GPIO_CLK_ENABLE();
  NUCLEO_SPIx_MISO_MOSI_GPIO_CLK_ENABLE();

                         
  GPIO_InitStruct.Pin        = NUCLEO_SPIx_SCK_PIN;
  GPIO_InitStruct.Mode       = GPIO_MODE_AF_PP;
  GPIO_InitStruct.Pull       = GPIO_PULLUP;
  GPIO_InitStruct.Speed      = GPIO_SPEED_FREQ_VERY_HIGH;
  GPIO_InitStruct.Alternate  = NUCLEO_SPIx_SCK_AF;
  HAL_GPIO_Init(NUCLEO_SPIx_SCK_GPIO_PORT, &GPIO_InitStruct);

                                   
  GPIO_InitStruct.Pin        = NUCLEO_SPIx_MOSI_PIN;
  GPIO_InitStruct.Alternate  = NUCLEO_SPIx_MISO_MOSI_AF;
  GPIO_InitStruct.Pull       = GPIO_PULLDOWN;
  HAL_GPIO_Init(NUCLEO_SPIx_MISO_MOSI_GPIO_PORT, &GPIO_InitStruct);

  GPIO_InitStruct.Pin        = NUCLEO_SPIx_MISO_PIN;
  HAL_GPIO_Init(NUCLEO_SPIx_MISO_MOSI_GPIO_PORT, &GPIO_InitStruct);

                                        
                        
  NUCLEO_SPIx_CLK_ENABLE();
}

   
                               
                
    
static void SPIx_Init(void)
{
  if (HAL_SPI_GetState(&hnucleo_Spi) == HAL_SPI_STATE_RESET)
  {
                    
    hnucleo_Spi.Instance = NUCLEO_SPIx;
                                                                                        
                                 
                                                                                       
                                                                                         
                                          
                                                                    
                                       
       
    hnucleo_Spi.Init.BaudRatePrescaler  = SPI_BAUDRATEPRESCALER_4;
    hnucleo_Spi.Init.Direction          = SPI_DIRECTION_2LINES;
    hnucleo_Spi.Init.CLKPhase           = SPI_PHASE_2EDGE;
    hnucleo_Spi.Init.CLKPolarity        = SPI_POLARITY_HIGH;
    hnucleo_Spi.Init.CRCCalculation     = SPI_CRCCALCULATION_DISABLE;
    hnucleo_Spi.Init.CRCPolynomial      = 7;
    hnucleo_Spi.Init.CRCLength          = SPI_CRC_LENGTH_DATASIZE;
    hnucleo_Spi.Init.DataSize           = SPI_DATASIZE_8BIT;
    hnucleo_Spi.Init.FirstBit           = SPI_FIRSTBIT_MSB;
    hnucleo_Spi.Init.NSS                = SPI_NSS_SOFT;
    hnucleo_Spi.Init.NSSPMode           = SPI_NSS_PULSE_DISABLE;
    hnucleo_Spi.Init.TIMode             = SPI_TIMODE_DISABLE;
    hnucleo_Spi.Init.Mode               = SPI_MODE_MASTER;

    SPIx_MspInit();
    HAL_SPI_Init(&hnucleo_Spi);
  }
}

   
                                       
                                                   
                                                         
                                                
                
    
static void SPIx_WriteReadData(const uint8_t *DataIn, uint8_t *DataOut, uint16_t DataLength)
{
  HAL_StatusTypeDef status = HAL_OK;
  status = HAL_SPI_TransmitReceive(&hnucleo_Spi, (uint8_t *) DataIn, DataOut, DataLength, hnucleo_SpixTimeout);

                                      
  if (status != HAL_OK)
  {
                                       
    SPIx_Error();
  }
}

   
                                      
                                      
                
    
static void SPIx_Write(uint8_t Value)
{
  HAL_StatusTypeDef status = HAL_OK;
  uint8_t data;

  status = HAL_SPI_TransmitReceive(&hnucleo_Spi, (uint8_t *) &Value, &data, 1, hnucleo_SpixTimeout);

                                      
  if (status != HAL_OK)
  {
                                       
    SPIx_Error();
  }
}

   
                                        
                
    
static void SPIx_Error(void)
{
                                               
  HAL_SPI_DeInit(&hnucleo_Spi);

                                              
  SPIx_Init();
}

                                                                               
                                           
                                                                                

                                                                                
   
                                                                           
                           
                
    
void SD_IO_Init(void)
{
  GPIO_InitTypeDef  GPIO_InitStruct = {0};
  uint8_t counter = 0;

                                      
  SD_CS_GPIO_CLK_ENABLE();

                                               
  GPIO_InitStruct.Pin    = SD_CS_PIN;
  GPIO_InitStruct.Mode   = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull   = GPIO_PULLUP;
  GPIO_InitStruct.Speed  = GPIO_SPEED_FREQ_VERY_HIGH;
  HAL_GPIO_Init(SD_CS_GPIO_PORT, &GPIO_InitStruct);

                                                 
  GPIO_InitStruct.Pin   = LCD_CS_PIN;
  GPIO_InitStruct.Mode  = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull  = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
  HAL_GPIO_Init(LCD_CS_GPIO_PORT, &GPIO_InitStruct);
  LCD_CS_HIGH();

                                                  
                     
  SPIx_Init();

                           
  SD_CS_HIGH();

                                                   
                                             
  for (counter = 0; counter <= 9; counter++)
  {
                              
    SD_IO_WriteByte(SD_DUMMY_BYTE);
  }
}

   
                                              
                                          
                
    
void SD_IO_CSState(uint8_t val)
{
  if (val == 1)
  {
    SD_CS_HIGH();
  }
  else
  {
    SD_CS_LOW();
  }
}

   
                                   
                                                   
                                                         
                                                
                
    
void SD_IO_WriteReadData(const uint8_t *DataIn, uint8_t *DataOut, uint16_t DataLength)
{
                     
  SPIx_WriteReadData(DataIn, DataOut, DataLength);
}

   
                                   
                               
                        
    
uint8_t SD_IO_WriteByte(uint8_t Data)
{
  uint8_t tmp;

                     
  SPIx_WriteReadData(&Data, &tmp, 1);
  return tmp;
}

                                                                                
   
                              
                
    
void LCD_IO_Init(void)
{
  GPIO_InitTypeDef  GPIO_InitStruct = {0};

                                                       
  LCD_CS_GPIO_CLK_ENABLE();
  LCD_DC_GPIO_CLK_ENABLE();

                                                 
  GPIO_InitStruct.Pin    = LCD_CS_PIN;
  GPIO_InitStruct.Mode   = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull   = GPIO_NOPULL;
  GPIO_InitStruct.Speed  = GPIO_SPEED_FREQ_VERY_HIGH;
  HAL_GPIO_Init(LCD_CS_GPIO_PORT, &GPIO_InitStruct);

                                                 
  GPIO_InitStruct.Pin    = LCD_DC_PIN;
  HAL_GPIO_Init(LCD_DC_GPIO_PORT, &GPIO_InitStruct);

                            
  LCD_CS_HIGH();

                      
  SPIx_Init();
}

   
                                                     
                                                     
                
    
void LCD_IO_WriteReg(uint8_t LCDReg)
{
                                 
  LCD_CS_LOW();

                                           
  LCD_DC_LOW();

                    
  SPIx_Write(LCDReg);

                                   
  LCD_CS_HIGH();
}

   
                               
                                             
                                                       
              
  
void LCD_IO_WriteMultipleData(uint8_t *pData, uint32_t Size)
{
  uint32_t counter = 0;
  __IO uint32_t data = 0;

                                 
  LCD_CS_LOW();

                                            
  LCD_DC_HIGH();

  if (Size == 1)
  {
                                                                       
                   
    SPIx_Write(*pData);
  }
  else
  {
                                              
                                              
    for (counter = Size; counter != 0; counter--)
    {
      while (((hnucleo_Spi.Instance->SR) & SPI_FLAG_TXE) != SPI_FLAG_TXE)
      {
      }
                                       
      *((__IO uint8_t *)&hnucleo_Spi.Instance->DR) = *(pData + 1);

      while (((hnucleo_Spi.Instance->SR) & SPI_FLAG_TXE) != SPI_FLAG_TXE)
      {
      }
      *((__IO uint8_t *)&hnucleo_Spi.Instance->DR) = *pData;
      counter--;
      pData += 2;
    }

                                                                  
    while (((hnucleo_Spi.Instance->SR) & SPI_FLAG_BSY) != RESET)
    {
    }
  }

                         
  data = *(&hnucleo_Spi.Instance->DR);
  UNUSED(data);                          

                                   
  LCD_CS_HIGH();
}

   
                                
                        
                
    
void LCD_Delay(uint32_t Delay)
{
  HAL_Delay(Delay);
}

#endif                             

#ifdef HAL_ADC_MODULE_ENABLED
                                                                                
   
                               
                           
                
    
static void ADCx_MspInit(ADC_HandleTypeDef *hadc)
{
  GPIO_InitTypeDef  GPIO_InitStruct = {0};
#if defined(RCC_CCIPR_ADCSEL)
  RCC_PeriphCLKInitTypeDef RCC_PeriphCLKInitStruct;
#endif

                               
                         
  NUCLEO_ADCx_GPIO_CLK_ENABLE();

                                               
  GPIO_InitStruct.Pin    = NUCLEO_ADCx_GPIO_PIN ;
  GPIO_InitStruct.Mode   = GPIO_MODE_ANALOG_ADC_CONTROL;
  GPIO_InitStruct.Pull   = GPIO_NOPULL;
  GPIO_InitStruct.Speed  = GPIO_SPEED_FREQ_HIGH;
  HAL_GPIO_Init(NUCLEO_ADCx_GPIO_PORT, &GPIO_InitStruct);

                                        
                        
  NUCLEO_ADCx_CLK_ENABLE();

#if defined(RCC_CCIPR_ADCSEL)
                                                
  RCC_PeriphCLKInitStruct.PeriphClockSelection = RCC_PERIPHCLK_ADC;
  RCC_PeriphCLKInitStruct.AdcClockSelection    = RCC_ADCCLKSOURCE_SYSCLK;
  HAL_RCCEx_PeriphCLKConfig(&RCC_PeriphCLKInitStruct);
#endif
}

   
                                 
                           
                                                          
                
    
static void ADCx_MspDeInit(ADC_HandleTypeDef *hadc)
{
  GPIO_InitTypeDef  GPIO_InitStruct;

                                     
                         
  NUCLEO_ADCx_CLK_DISABLE();

                                                          
  GPIO_InitStruct.Pin = NUCLEO_ADCx_GPIO_PIN ;
  HAL_GPIO_DeInit(NUCLEO_ADCx_GPIO_PORT, GPIO_InitStruct.Pin);

                                                           
                                       
}

   
                               
                
    
static HAL_StatusTypeDef ADCx_Init(void)
{
  if (HAL_ADC_GetState(&hnucleo_Adc) == HAL_ADC_STATE_RESET)
  {
                    
    hnucleo_Adc.Instance                    = NUCLEO_ADCx;
    hnucleo_Adc.Init.ClockPrescaler         = ADC_CLOCK_ASYNC_DIV8;                              
    hnucleo_Adc.Init.Resolution             = ADC_RESOLUTION_12B;
    hnucleo_Adc.Init.DataAlign              = ADC_DATAALIGN_RIGHT;
    hnucleo_Adc.Init.ScanConvMode           = DISABLE;
    hnucleo_Adc.Init.EOCSelection           = ADC_EOC_SINGLE_CONV;
    hnucleo_Adc.Init.LowPowerAutoWait       = ENABLE;
    hnucleo_Adc.Init.ContinuousConvMode     = DISABLE;
    hnucleo_Adc.Init.NbrOfConversion        = 1;
    hnucleo_Adc.Init.DiscontinuousConvMode  = DISABLE;
    hnucleo_Adc.Init.NbrOfDiscConversion    = 1;
    hnucleo_Adc.Init.ExternalTrigConv       = ADC_SOFTWARE_START;
    hnucleo_Adc.Init.ExternalTrigConvEdge   = ADC_EXTERNALTRIGCONVEDGE_NONE;
    hnucleo_Adc.Init.DMAContinuousRequests  = DISABLE;
    hnucleo_Adc.Init.Overrun                = ADC_OVR_DATA_PRESERVED;
    hnucleo_Adc.Init.OversamplingMode       = DISABLE;

    ADCx_MspInit(&hnucleo_Adc);
    if (HAL_ADC_Init(&hnucleo_Adc) != HAL_OK)
    {
      return HAL_ERROR;
    }

    if (HAL_ADCEx_Calibration_Start(&hnucleo_Adc, ADC_SINGLE_ENDED) != HAL_OK)
    {
      return HAL_ERROR;
    }
  }

  return HAL_OK;
}

   
                                 
                
    
static void ADCx_DeInit(void)
{
  hnucleo_Adc.Instance   = NUCLEO_ADCx;

  HAL_ADC_DeInit(&hnucleo_Adc);
  ADCx_MspDeInit(&hnucleo_Adc);
}

#endif                             

   
      
    

   
      
    

   
      
    


