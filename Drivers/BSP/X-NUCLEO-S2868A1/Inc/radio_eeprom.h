/**
* @file    SPIRIT_SDK_EEPROM.h
* @author  AMG - RF Application team
* @version 3.2.1
* @date    26-September-2016
* @brief   SDK EVAL eeprom management
* @details This module exports API to manage the EEPROM of the eval boards.
*          Data stored in the EEPROM are mainly some manifacturing infos,
*          and informations that can be useful when developing applications 
*          with the daughter board. Some of them are the RF band, the offset
*          of the carrier from the nominal frequency and the XTAL frequency.
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

                                                                                
#ifndef SPIRIT_SDK_EEPROM_H_
#define SPIRIT_SDK_EEPROM_H_


                                                                                
#include "cube_hal.h"


#ifdef __cplusplus
  "C" {
#endif


   
                              
     
   


   
                       
                                                                   
                                                                        
     
   
    
    
    
                         
#define EEPROM_CMD_WREN    0x06                   
#define EEPROM_CMD_WRDI    0x04                    
#define EEPROM_CMD_RDSR    0x05                           
#define EEPROM_CMD_WRSR    0x01                            
#define EEPROM_CMD_READ    0x03                             
#define EEPROM_CMD_WRITE   0x02                               

                       
#define EEPROM_STATUS_SRWD    0x80                                       
#define EEPROM_STATUS_BP      0x0C                       
#define EEPROM_STATUS_WEL     0x02                         
#define EEPROM_STATUS_WIP     0x01                           


void EepromSpiInitialization(void);
void EepromCsPinInitialization(void);

uint8_t EepromStatus(void);
void EepromRead(uint16_t nAddress, uint8_t cNbBytes, uint8_t* pcBuffer);
void EepromWrite(uint16_t nAddress, uint8_t cNbBytes, uint8_t* pcBuffer);
uint8_t EepromResetSrwd(void);
uint8_t EepromSetSrwd(void);

void EepromWriteEnable(void);
uint8_t RadioGetHasEeprom(void);
void RadioSetHasEeprom(uint8_t eeprom);

   
    
  

   
    
  

#ifdef __cplusplus
}
#endif


#endif


 /******************* (C) COPYRIGHT 2016 STMicroelectronics *****END OF FILE****/

