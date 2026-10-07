/**
 * @file    S2LP_PktBasic.c
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
 * <h2><center>&copy; COPYRIGHT 2019 STMicroelectronics</center></h2>
 */


                                                                                
#include "S2LP_PktBasic.h"
#include "MCU_Interface.h"
#include "S2LP_PktWMbus.h"


   
                             
     
   


   
                            
     
   



   
                                                                         
     
   

#define PKT_FORMAT_BASIC_CODE                   0x00
  
   
    
   


   
                                                                        
     
   

#define IS_BASIC_PREAMBLE_LENGTH           IS_PREAMBLE_LEN
#define IS_BASIC_SYNC_LENGTH               IS_SYNC_LEN
#define IS_BASIC_PKT_LEN_FIELD_WID         IS_PKT_LEN_FIELD_WID
#define IS_BASIC_CRC_MODE                  IS_PKT_CRC_MODE
  
   
    
   



   
                                                                                   
     
   

   
                                                                                                             
                                                                                                                                
                                                      
                                                            
                
   
void S2LPPktBasicInit(PktBasicInit* pxPktBasicInit)
{
  uint8_t tmpBuffer[6];

                            
  s_assert_param(IS_BASIC_PREAMBLE_LENGTH(pxPktBasicInit->xPreambleLength));
  s_assert_param(IS_BASIC_SYNC_LENGTH(pxPktBasicInit->xSyncLength));
  s_assert_param(IS_BASIC_CRC_MODE(pxPktBasicInit->xCrcMode));
  s_assert_param(IS_SFUNCTIONAL_STATE(pxPktBasicInit->cExtendedPktLenField));
  s_assert_param(IS_SFUNCTIONAL_STATE(pxPktBasicInit->xFixVarLength));
  s_assert_param(IS_SFUNCTIONAL_STATE(pxPktBasicInit->xAddressField));
  s_assert_param(IS_SFUNCTIONAL_STATE(pxPktBasicInit->xFec));
  s_assert_param(IS_SFUNCTIONAL_STATE(pxPktBasicInit->xDataWhitening));

  S2LPPktWMbusSetSubmode(WMBUS_SUBMODE_NOT_CONFIGURED);
  
                                                 
  S2LPSpiReadRegisters(PROTOCOL1_ADDR, 1, &tmpBuffer[0]);
  tmpBuffer[0] |= AUTO_PCKT_FLT_REGMASK;
  S2LPSpiWriteRegisters(PROTOCOL1_ADDR, 1, &tmpBuffer[0]);

  tmpBuffer[0] = ((pxPktBasicInit->xSyncLength)<<2) | (uint8_t)((pxPktBasicInit->xPreambleLength)>>8);
  tmpBuffer[1] = (uint8_t)(pxPktBasicInit->xPreambleLength);
  tmpBuffer[2] = (((uint8_t)pxPktBasicInit->xAddressField)<<3);
  
  if((pxPktBasicInit->cExtendedPktLenField)==S_ENABLE)
  {
    tmpBuffer[2]|=0x80;
  }
  
  S2LPSpiReadRegisters(PCKTCTRL3_ADDR, 1, &tmpBuffer[3]);
  tmpBuffer[3] &= ~(PCKT_FRMT_REGMASK | RX_MODE_REGMASK);
  tmpBuffer[3] |= PKT_FORMAT_BASIC_CODE;
  
  S2LPSpiReadRegisters(PCKTCTRL2_ADDR, 2, &tmpBuffer[4]);
  
  if(pxPktBasicInit->xFixVarLength == S_ENABLE) {
     tmpBuffer[4] |= FIX_VAR_LEN_REGMASK;
  }
  else {
     tmpBuffer[4] &= ~FIX_VAR_LEN_REGMASK;
  }
  tmpBuffer[4] &= ~(MANCHESTER_EN_REGMASK | MBUS_3OF6_EN_REGMASK);
  
  tmpBuffer[5] &= ~(CRC_MODE_REGMASK | TXSOURCE_REGMASK);
  tmpBuffer[5] |= (uint8_t)pxPktBasicInit->xCrcMode;
  
  if(pxPktBasicInit->xDataWhitening == S_ENABLE) {
     tmpBuffer[5] |= WHIT_EN_REGMASK;
  }
  else {
     tmpBuffer[5] &= ~WHIT_EN_REGMASK;
  }

  if(pxPktBasicInit->xFec == S_ENABLE)
  {
     tmpBuffer[5] |= FEC_EN_REGMASK;
  }
  else {
     tmpBuffer[5] &= ~FEC_EN_REGMASK;
  }
  
  S2LPSpiWriteRegisters(PCKTCTRL6_ADDR, 6, tmpBuffer);  
  
                 
  for(uint8_t i=0 ; i<4 ; i++) {
    tmpBuffer[i] = (uint8_t)(pxPktBasicInit->lSyncWords>>(8*i));
  }
  g_xStatus = S2LPSpiWriteRegisters(SYNC3_ADDR, 4, tmpBuffer);
  
                          
  if(pxPktBasicInit->xCrcMode == PKT_NO_CRC) {
    S2LPPktBasicFilterOnCrc(S_DISABLE);
  }
  else {
    S2LPPktBasicFilterOnCrc(S_ENABLE);
  }
  
                                   
  S2LPSpiReadRegisters(MOD1_ADDR, 1, tmpBuffer);
  tmpBuffer[0] &= ~G4FSK_CONST_MAP_REGMASK;
  S2LPSpiWriteRegisters(MOD1_ADDR, 1, tmpBuffer); 
}


   
                                                                                                         
                                                      
                                                            
                
   
void S2LPPktBasicGetInfo(PktBasicInit* pxPktBasicInit)
{
  uint8_t tmpBuffer[6];

  S2LPSpiReadRegisters(PCKTCTRL6_ADDR, 6, tmpBuffer);
  
                   
  pxPktBasicInit->xSyncLength = ((tmpBuffer[0] & SYNC_LEN_REGMASK)>>2);
  
                       
  pxPktBasicInit->xPreambleLength = (((uint16_t)(tmpBuffer[0] & PREAMBLE_LEN_9_8_REGMASK))<<8) | ((uint16_t)tmpBuffer[1]);
  
                    
  pxPktBasicInit->cExtendedPktLenField = (SFunctionalState)((tmpBuffer[2] & LEN_WID_REGMASK)>>7);
  
                     
  pxPktBasicInit->xAddressField = (SFunctionalState)((tmpBuffer[2] & ADDRESS_LEN_REGMASK)>>3);

                      
  pxPktBasicInit->xFixVarLength = (SFunctionalState)(tmpBuffer[4] & FIX_VAR_LEN_REGMASK);

                
  pxPktBasicInit->xCrcMode = (BasicCrcMode)(tmpBuffer[5] & CRC_MODE_REGMASK);
  
                 
  pxPktBasicInit->xDataWhitening = (SFunctionalState)((tmpBuffer[5] & WHIT_EN_REGMASK)>> 4);

           
  pxPktBasicInit->xFec = (SFunctionalState)(tmpBuffer[5] & FEC_EN_REGMASK);
  
  g_xStatus = S2LPSpiReadRegisters(SYNC3_ADDR, 4, tmpBuffer);
  
                 
  pxPktBasicInit->lSyncWords = 0;
  for(uint8_t i=0 ; i<4 ; i++) {
    pxPktBasicInit->lSyncWords |= ((uint32_t)tmpBuffer[i])<<(8*i);
  }
}


   
                                                                                
                                                          
                                                                     
                                                                 
                
   
void S2LPPktBasicAddressesInit(PktBasicAddressesInit* pxPktBasicAddresses)
{
  uint8_t tmpBuffer[3];
  s_assert_param(IS_SFUNCTIONAL_STATE(pxPktBasicAddresses->xFilterOnMyAddress));
  s_assert_param(IS_SFUNCTIONAL_STATE(pxPktBasicAddresses->xFilterOnMulticastAddress));
  s_assert_param(IS_SFUNCTIONAL_STATE(pxPktBasicAddresses->xFilterOnBroadcastAddress));

                                           
  S2LPSpiReadRegisters(PCKT_FLT_OPTIONS_ADDR, 1, &tmpBuffer[0]);
  
                                                   
  if(pxPktBasicAddresses->xFilterOnMyAddress == S_ENABLE) {
    tmpBuffer[0] |= DEST_VS_SOURCE_ADDR_REGMASK;
  }
  else {
    tmpBuffer[0] &= ~DEST_VS_SOURCE_ADDR_REGMASK;
  }
  
                                                          
  if(pxPktBasicAddresses->xFilterOnMulticastAddress == S_ENABLE) {
    tmpBuffer[0] |= DEST_VS_MULTICAST_ADDR_REGMASK;
  }
  else {
    tmpBuffer[0] &= ~DEST_VS_MULTICAST_ADDR_REGMASK;
  }
  
                                                          
  if(pxPktBasicAddresses->xFilterOnBroadcastAddress == S_ENABLE) {
    tmpBuffer[0] |= DEST_VS_BROADCAST_ADDR_REGMASK;
  }
  else {
    tmpBuffer[0] &= ~DEST_VS_BROADCAST_ADDR_REGMASK;
  }
  
  S2LPSpiWriteRegisters(PCKT_FLT_OPTIONS_ADDR, 1, &tmpBuffer[0]);

                                                                  
  tmpBuffer[0] = pxPktBasicAddresses->cBroadcastAddress;
  tmpBuffer[1] = pxPktBasicAddresses->cMulticastAddress;
  tmpBuffer[2] = pxPktBasicAddresses->cMyAddress;

  g_xStatus = S2LPSpiWriteRegisters(PCKT_FLT_GOALS2_ADDR, 3, tmpBuffer);
}


   
                                                                                      
                                       
                                                                     
                                                                 
                
   
void S2LPPktBasicGetAddressesInfo(PktBasicAddressesInit* pxPktBasicAddresses)
{
  uint8_t tmpBuffer[3];

  S2LPSpiReadRegisters(PCKT_FLT_GOALS2_ADDR, 3, tmpBuffer);
  pxPktBasicAddresses->cBroadcastAddress = tmpBuffer[0];
  pxPktBasicAddresses->cMulticastAddress = tmpBuffer[1];
  pxPktBasicAddresses->cMyAddress = tmpBuffer[2];
  
  g_xStatus = S2LPSpiReadRegisters(PCKT_FLT_OPTIONS_ADDR, 1, &tmpBuffer[0]);
  pxPktBasicAddresses->xFilterOnBroadcastAddress = (SFunctionalState)((tmpBuffer[0] & DEST_VS_BROADCAST_ADDR_REGMASK) >> 3);
  pxPktBasicAddresses->xFilterOnMulticastAddress = (SFunctionalState)((tmpBuffer[0] & DEST_VS_MULTICAST_ADDR_REGMASK) >> 2);
  pxPktBasicAddresses->xFilterOnMyAddress = (SFunctionalState)((tmpBuffer[0] & DEST_VS_SOURCE_ADDR_REGMASK) >> 1);
}


   
                                                                    
                
                
   
void S2LPPktBasicSetFormat(void)
{
  uint8_t tmp;
  
  S2LPSpiReadRegisters(PCKTCTRL3_ADDR, 1, &tmp);
  
                                                                  
  tmp &= ~(PCKT_FRMT_REGMASK | RX_MODE_REGMASK);
  tmp |= PKT_FORMAT_BASIC_CODE;
  S2LPSpiWriteRegisters(PCKTCTRL3_ADDR, 1, &tmp);

  S2LPSpiReadRegisters(PCKTCTRL1_ADDR, 1, &tmp);
  
                                        
  tmp &= ~TXSOURCE_REGMASK;
  g_xStatus = S2LPSpiWriteRegisters(PCKTCTRL1_ADDR, 1, &tmp);

  S2LPPktWMbusSetSubmode(WMBUS_SUBMODE_NOT_CONFIGURED);
}


   
                                                         
                                                    
                                                        
                
   
void S2LPPktBasicAddressField(SFunctionalState xAddressField)
{
  uint8_t tmp;
  s_assert_param(IS_SFUNCTIONAL_STATE(xAddressField));

  S2LPSpiReadRegisters(PCKTCTRL4_ADDR, 1, &tmp);
  if(xAddressField==S_ENABLE) {
    tmp |= ADDRESS_LEN_REGMASK;
  }
  else {
    tmp &= ADDRESS_LEN_REGMASK;
  }
  g_xStatus = S2LPSpiWriteRegisters(PCKTCTRL4_ADDR, 1, &tmp);

}


   
                                                                                      
                
                                                                                 
   
SFunctionalState S2LPPktBasicGetAddressField(void)
{
  uint8_t tmp;

  g_xStatus = S2LPSpiReadRegisters(PCKTCTRL4_ADDR, 1, &tmp);
  if(tmp & ADDRESS_LEN_REGMASK) {
    return S_ENABLE;
  }
  else {
    return S_DISABLE;
  }

}


   
                                                                                 
                                                                    
                                                                           
                                                   
                                                  
                                         
                
   
void S2LPPktBasicSetPayloadLength(uint16_t nPayloadLength)
{
  uint8_t tmpBuffer[2];
  
  if(S2LPPktBasicGetAddressField()) {
    nPayloadLength++;
  }
  tmpBuffer[0] = (uint8_t)(nPayloadLength>>8);
  tmpBuffer[1] = (uint8_t)nPayloadLength;
  g_xStatus = S2LPSpiWriteRegisters(PCKTLEN1_ADDR, 2, tmpBuffer);
}


   
                                                                      
                                                                 
                                                            
                                                                     
                          
                
                                            
   
uint16_t S2LPPktBasicGetPayloadLength(void)
{
  uint8_t tmpBuffer[2];
  uint16_t nPayloadLength;

  g_xStatus = S2LPSpiReadRegisters(PCKTLEN1_ADDR, 2, tmpBuffer);
  nPayloadLength = (((uint16_t)tmpBuffer[0])<<8) | ((uint16_t)tmpBuffer[1]);
  
  if(S2LPPktBasicGetAddressField()) {
    nPayloadLength--;
  }
  return nPayloadLength;
}

   
                                                                 
                
                                  
   
uint16_t S2LPPktBasicGetReceivedPktLength(void)
{
  uint8_t tmpBuffer[2];
  uint16_t nPayloadLength;

  g_xStatus = S2LPSpiReadRegisters(RX_PCKT_LEN1_ADDR, 2, tmpBuffer);
  nPayloadLength = (((uint16_t)tmpBuffer[0])<<8) | ((uint16_t)tmpBuffer[1]);
  
  if(S2LPPktBasicGetAddressField()) {
    nPayloadLength--;
  }
  return nPayloadLength;
}


   
    
   

   
    
   


   
    
   



/******************* (C) COPYRIGHT 2016 STMicroelectronics *****END OF FILE****/
