/**
 * @file    S2LP_PktBasic.h
 * @author  LowPower RF BU - AMG
 * @version 1.3.0
 * @date    10-July-2017
 * @brief   Configuration and management of S2-LP Basic packets.
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
 * This module can be used to manage the configuration of S2LP Basic
 * packets.
 * The user can obtain a packet configuration filling the structure
 * <i>@ref PktBasicInit</i>, defining in it some general parameters
 * for the S2-LP Basic packet format.
 * Another structure the user can fill is <i>@ref PktBasicAddressesInit</i>
 * to define the addresses which will be used during the communication.
 * Moreover, functions to set the payload length and the destination address
 * are provided.
 *
 * <b>Example:</b>
 * @code
 *
 * PktBasicInit basicInit={
 *   32,       // preamble length in bits
 *   32,            // sync word length in bits
 *   0x88888888,                        // sync word
 *   S_ENABLE,                          // variable or fixed payload length
 *   S_DISABLE,                         // extended length field width (used only for variable length)
 *   PKT_NO_CRC,                        // CRC mode
 *   S_ENABLE,                          // address field
 *   S_DISABLE,                         // FEC
 *   S_ENABLE                           // whitening
 * };
 *
 * PktBasicAddressesInit addressInit={
 *   S_ENABLE,                          // enable/disable filtering on my address
 *   0x34,                              // my address (address of the current node)
 *   S_DISABLE,                         // enable/disable filtering on multicast address
 *   0xEE,                              // multicast address
 *   S_DISABLE,                         // enable/disable filtering on broadcast address
 *   0xFF                               // broadcast address
 * };
 *
 * ...
 *
 * S2LPPktBasicInit(&basicInit);
 * S2LPPktBasicAddressesInit(&addressInit);
 *
 * ...
 *
 * S2LPPktBasicSetPayloadLength(20);
 * S2LPPktBasicSetDestinationAddress(0x44);
 *
 * ...
 *
 * @endcode
 *
 * The module provides some other functions that can be used to modify
 * or read only some configuration parameters.
 *
 * <h2><center>&copy; COPYRIGHT 2019 STMicroelectronics</center></h2>
 */

                                                                                
#ifndef __S2LP_PKT_BASIC_H
#define __S2LP_PKT_BASIC_H

                                                                                

#include "S2LP_Regs.h"
#include "S2LP_Types.h"
#include "S2LP_PacketHandler.h"

#ifdef __cplusplus
 extern "C" {
#endif


   
                             
     
   


   
                                       
                                                             
                                                                      
     
   

   
                                                                
     
   


   
                                           
   
typedef PktCrcMode       BasicCrcMode;



   
                                                       
   
typedef struct {
  uint16_t           xPreambleLength;                                                                                 
  uint8_t            xSyncLength;                                                                                   
  uint32_t           lSyncWords;                                                
  SFunctionalState   xFixVarLength;                                                   
  SFunctionalState   cExtendedPktLenField;                                                                                      
  BasicCrcMode       xCrcMode;                                                           
  SFunctionalState   xAddressField;                                                        
  SFunctionalState   xFec;                                                   
  SFunctionalState   xDataWhitening;                                            
} PktBasicInit;


   
                                                                                                 
                                                                                          
   
typedef struct {
  SFunctionalState   xFilterOnMyAddress;                                                                                              
  uint8_t            cMyAddress;                                           
  SFunctionalState   xFilterOnMulticastAddress;                                                                                              
  uint8_t            cMulticastAddress;                                           
  SFunctionalState   xFilterOnBroadcastAddress;                                                                                              
  uint8_t            cBroadcastAddress;                                           
} PktBasicAddressesInit;


   
    
   


   
                                                                 
     
   

   
                                                                 
                                                             
                                                                       
                
   
#define S2LPPktBasicSetPreambleLength(xPreambleLength)                S2LPSetPreambleLength(xPreambleLength)


   
                                                                         
                
                                                  
   
#define S2LPPktBasicGetPreambleLength()                               S2LPGetPreambleLength()


   
                                                             
                                                     
                                                                   
                
   
#define S2LPPktBasicSetSyncLength(xSyncLength)                        S2LPSetSyncLength((PktSyncLength)xSyncLength)


   
                                                                
                
                                              
   
#define S2LPPktBasicGetSyncLength()                                   S2LPGetSyncLength()


   
                                                 
                                             
                                                       
                
   
#define S2LPPktBasicFilterOnCrc(xNewState)                            S2LPPktCommonFilterOnCrc(xNewState)


   
                                                          
                                                  
                                                       
                
   
#define S2LPPktBasicWhitening(xNewState)                               S2LPWhitening(xNewState)


   
                                                          
                                            
                                                       
                
   
#define S2LPPktBasicFec(xNewState)                                     S2LPFec(xNewState)



   
                                                           
                                                                                    
                                        
                                                                                                                     
                                                                    
                                                    
                
   
#define S2LPPktBasicSetSyncWords(lSyncWords, xSyncLength)              S2LPSetSyncWords(lSyncWords, xSyncLength)


   
    
   


   
                                                                            
     
   

void S2LPPktBasicInit(PktBasicInit* pxPktBasicInit);
void S2LPPktBasicGetInfo(PktBasicInit* pxPktBasicInit);
void S2LPPktBasicAddressesInit(PktBasicAddressesInit* pxPktBasicAddresses);
void S2LPPktBasicGetAddressesInfo(PktBasicAddressesInit* pxPktBasicAddresses);
void S2LPPktBasicSetFormat(void);
void S2LPPktBasicAddressField(SFunctionalState xAddressField);
SFunctionalState S2LPPktBasicGetAddressField(void);
void S2LPPktBasicSetPayloadLength(uint16_t nPayloadLength);
uint16_t S2LPPktBasicGetPayloadLength(void);
uint16_t S2LPPktBasicGetReceivedPktLength(void);

   
    
   

   
    
   


   
    
   

#ifdef __cplusplus
}
#endif

#endif

/******************* (C) COPYRIGHT 2016 STMicroelectronics *****END OF FILE****/
