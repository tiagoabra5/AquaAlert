/**
* @file    SPIRIT_SDK_EEPROM.c
* @author  VMA division - AMS
* @version 3.2.0
* @date    May 1, 2016
* @brief   SDK EVAL eeprom management
* @details 
*
* THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
* WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
* TIME. AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY
* DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
* FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
* CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
*
* THIS SOURCE CODE IS PROTECTED BY A LICENSE.
* FOR MORE INFORMATION PLEASE CAREFULLY READ THE LICENSE AGREEMENT FILE LOCATED
* IN THE ROOT DIRECTORY OF THIS FIRMWARE PACKAGE.
*
* <h2><center>&copy; COPYRIGHT 2016 STMicroelectronics</center></h2>
*/  

                                                                                
#include "radio_eeprom.h"
#include "S2LP_Config.h"
#include "radio_spi.h"
   
                             
    
  


   
                                                         
    
  


                                   
    
  

static SPI_HandleTypeDef EepromSpiHandle;
static uint8_t s_eeprom = 0;



#define EepromSPICSLow()        HAL_GPIO_WritePin(EEPROM_SPI_PERIPH_CS_PORT, EEPROM_SPI_PERIPH_CS_PIN, GPIO_PIN_RESET)
#define EepromSPICSHigh()       HAL_GPIO_WritePin(EEPROM_SPI_PERIPH_CS_PORT, EEPROM_SPI_PERIPH_CS_PIN, GPIO_PIN_SET)


   
                                             
                                                                     
                                                                       
                                  
              
              
  
void EepromSpiInitialization(void)
{ 
  GPIO_InitTypeDef GPIO_InitStructure;
  
                                                                 
  EEPROM_SPI_PERIPH_RCC();
  EEPROM_SPI_PERIPH_MOSI_RCC();
  EEPROM_SPI_PERIPH_MISO_RCC();
  EEPROM_SPI_PERIPH_SCLK_RCC();
  EEPROM_SPI_PERIPH_CS_RCC();
  
  
                                                         
  GPIO_InitStructure.Pin       = EEPROM_SPI_PERIPH_SCLK_PIN;
  GPIO_InitStructure.Mode      = GPIO_MODE_AF_PP;
  GPIO_InitStructure.Pull      = GPIO_PULLUP;
  GPIO_InitStructure.Speed     = GPIO_SPEED_HIGH;
  GPIO_InitStructure.Alternate = EEPROM_SPI_PERIPH_SCLK_AF;
  HAL_GPIO_Init(EEPROM_SPI_PERIPH_SCLK_PORT, &GPIO_InitStructure);
  
  GPIO_InitStructure.Pin = EEPROM_SPI_PERIPH_MISO_PIN;
  GPIO_InitStructure.Alternate = EEPROM_SPI_PERIPH_MISO_AF;
  HAL_GPIO_Init(EEPROM_SPI_PERIPH_MISO_PORT, &GPIO_InitStructure);
  
  GPIO_InitStructure.Pin = EEPROM_SPI_PERIPH_MOSI_PIN;
  GPIO_InitStructure.Alternate = EEPROM_SPI_PERIPH_MOSI_AF;
  HAL_GPIO_Init(EEPROM_SPI_PERIPH_MOSI_PORT, &GPIO_InitStructure);
  
  GPIO_InitStructure.Pin = EEPROM_SPI_PERIPH_CS_PIN;
  GPIO_InitStructure.Mode = GPIO_MODE_OUTPUT_PP;
  HAL_GPIO_Init(EEPROM_SPI_PERIPH_CS_PORT, &GPIO_InitStructure);
  
  
                                
  if(HAL_SPI_GetState(&EepromSpiHandle) == HAL_SPI_STATE_RESET)
  {  
                                
    EepromSpiHandle.Instance               = EEPROM_SPI_PERIPH_NB;
    EepromSpiHandle.Init.Mode              = SPI_MODE_MASTER;
    /* Mesmo SPI1 do radio: manter 5 MHz com APB2 de 80 MHz no L476. */
    EepromSpiHandle.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_16;
    
    EepromSpiHandle.Init.Direction         = SPI_DIRECTION_2LINES;
    EepromSpiHandle.Init.CLKPhase          = SPI_PHASE_1EDGE;
    EepromSpiHandle.Init.CLKPolarity       = SPI_POLARITY_LOW;
    EepromSpiHandle.Init.CRCCalculation    = SPI_CRCCALCULATION_DISABLED;
    EepromSpiHandle.Init.CRCPolynomial     = 7;
    EepromSpiHandle.Init.DataSize          = SPI_DATASIZE_8BIT;
    EepromSpiHandle.Init.FirstBit          = SPI_FIRSTBIT_MSB;
    EepromSpiHandle.Init.NSS               = SPI_NSS_SOFT;
    EepromSpiHandle.Init.TIMode            = SPI_TIMODE_DISABLED;
    
    if(HAL_SPI_Init(&EepromSpiHandle) != HAL_OK) {
      return;
    } 
    __HAL_SPI_ENABLE(&EepromSpiHandle);    
  }
  
  EepromSPICSHigh();
}

   
                                                      
                                                                          
              
              
  
void EepromCsPinInitialization(void)
{
  GPIO_InitTypeDef GPIO_InitStructure;
  
                             
  GPIO_InitStructure.Pin = EEPROM_SPI_PERIPH_CS_PIN;
  GPIO_InitStructure.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStructure.Pull = GPIO_PULLUP;
  GPIO_InitStructure.Speed = GPIO_SPEED_HIGH;
  HAL_GPIO_Init(EEPROM_SPI_PERIPH_CS_PORT, &GPIO_InitStructure);
  
                            
  EEPROM_SPI_PERIPH_CS_RCC();
  
                                                           
  EepromSPICSHigh();
}


   
                                                                    
                                                            
              
              
  
void EepromWaitEndWriteOperation(void)
{
  uint8_t cmd = EEPROM_CMD_RDSR;
  uint8_t dummy = 0xFF;
  uint8_t status;
  
                                                            
  EepromSPICSLow();
  
                    
  HAL_SPI_TransmitReceive(&EepromSpiHandle, &cmd, &status, 1, 1000);
  
                                  
  do{
    HAL_SPI_TransmitReceive(&EepromSpiHandle, &dummy, &status, 1, 1000);
  }while(status&EEPROM_STATUS_WIP);
  
                                                           
  EepromSPICSHigh();
  
}


   
                                   
              
                
  
uint8_t EepromStatus(void)
{
  uint8_t status[2];
  uint8_t cmd[] = {EEPROM_CMD_RDSR, 0xFF};
  
                                                            
  EepromSPICSLow();
  
                    
  HAL_SPI_TransmitReceive(&EepromSpiHandle, cmd, status, 2, 1000);
  
                                                           
  EepromSPICSHigh();
  
  return status[1];
  
}

   
                                  
              
                
  
uint8_t EepromSetSrwd(void)
{
  uint8_t status[2];
  uint8_t cmd[] = {EEPROM_CMD_WRSR, EEPROM_STATUS_SRWD};
  
                                                            
  EepromSPICSLow();
  
                    
  HAL_SPI_TransmitReceive(&EepromSpiHandle, cmd, status, 2, 1000);
  
                                                           
  EepromSPICSHigh();
  
  
  return status[1];
}

   
                                    
              
                
  
uint8_t EepromResetSrwd(void)
{
  uint8_t status[2];
  uint8_t cmd[] = {EEPROM_CMD_WRSR, 0};                      
  
  EepromWriteEnable();
  EepromWaitEndWriteOperation();
                                                            
  EepromSPICSLow();
  
                    
  HAL_SPI_TransmitReceive(&EepromSpiHandle, cmd, status, 2, 1000);
  
                                                           
  EepromSPICSHigh();
  EepromWaitEndWriteOperation();
  
  return status[1];
}

   
                                                             
              
              
  
void EepromWriteEnable(void)
{
  uint8_t cmd = EEPROM_CMD_WREN;
  uint8_t status;
  
                                                            
  EepromSPICSLow();
  
                    
  HAL_SPI_TransmitReceive(&EepromSpiHandle, &cmd, &status, 1, 1000);
  
                                                           
  EepromSPICSHigh();
  
}


   
                                    
                                  
                            
                                
                                
             
                                  
              
              
  
void EepromRead(uint16_t nAddress, uint8_t cNbBytes, uint8_t* pcBuffer)
{
  uint8_t cmd[3];
  uint8_t dummy[255];
  cmd[0] = EEPROM_CMD_READ;
  
  for(uint8_t k=0; k<2; k++) {
    cmd[k+1] = (uint8_t)(nAddress>>((1-k)*8));
  }  
  
                                                  
  EepromWaitEndWriteOperation();
  
                                                            
  EepromSPICSLow();
  
                                                               
  HAL_SPI_TransmitReceive(&EepromSpiHandle, cmd, dummy, 3, 1000);
  
                                                           
  HAL_SPI_TransmitReceive(&EepromSpiHandle, dummy, pcBuffer, cNbBytes, 1000);
  
                                                           
  EepromSPICSHigh();
  
}


   
                                     
                                  
                            
                                
                                
             
                                  
                                                                             
                                                                              
                    
              
              
  
void EepromWrite(uint16_t nAddress, uint8_t cNbBytes, uint8_t* pcBuffer)
{
  uint8_t cmd = EEPROM_CMD_WRITE, tmp[255];
  uint8_t address[2];
  
                                                  
  EepromWaitEndWriteOperation();
  
                         
  EepromWriteEnable();
  
  for(uint8_t k=0; k<2; k++) {
    address[k] = (uint8_t)(nAddress>>((1-k)*8));
  }
                                  
  
                                                            
  EepromSPICSLow();
  
                                                               
  HAL_SPI_TransmitReceive(&EepromSpiHandle, &cmd, tmp, 1, 1000);
  
  HAL_SPI_TransmitReceive(&EepromSpiHandle, address, tmp, 2, 1000);
  
  HAL_SPI_TransmitReceive(&EepromSpiHandle, pcBuffer, tmp, cNbBytes, 1000);
  
                                                           
  EepromSPICSHigh();
  
}

   
                                                                
              
                            
  
uint8_t RadioGetHasEeprom(void)
{
  return s_eeprom;
}


   
                                                              
                            
              
  
void RadioSetHasEeprom(uint8_t eeprom)
{
  s_eeprom = eeprom;
}


   
    
  

   
    
  


/******************* (C) COPYRIGHT 2016 STMicroelectronics *****END OF FILE****/
