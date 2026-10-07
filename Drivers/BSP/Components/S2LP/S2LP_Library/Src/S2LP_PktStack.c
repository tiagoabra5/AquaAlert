/**
 * @file    S2LP_PktStack.c
 * @author  LowPower RF BU - AMG
 * @version 1.3.0
 * @date    10-July-2017
 * @brief   Configuration and management of S2-LP STack packets.
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


                                                                                
#include "S2LP_PktStack.h"
#include "MCU_Interface.h"
#include "S2LP_PktWMbus.h"


   
                             
     
   


   
                            
     
   

   
                                                                                 
     
   
#define PKT_FORMAT_STACK_CODE           (uint8_t)3

   
    
   


   
                                                                                
     
   


#define IS_STACK_PREAMBLE_LENGTH           IS_PREAMBLE_LEN
#define IS_STACK_SYNC_LENGTH               IS_SYNC_LEN
#define IS_STACK_PKT_LEN_FIELD_WID         IS_PKT_LEN_FIELD_WID
#define IS_STACK_CRC_MODE                  IS_PKT_CRC_MODE
#define IS_STACK_NMAX_RETX(NRETX)          (NRETX<=15)
#define IS_STACK_SEQNUM_RELOAD_VAL(VAL)    (VAL<=3)

   
    
   


   
                                                                                   
     
   


   
                                                                      
                                          
                                                      
                                                            
                
   
void S2LPPktStackInit(PktStackInit* pxPktStackInit)
{
  uint8_t tmpBuffer[6];

                            
  s_assert_param(IS_STACK_PREAMBLE_LENGTH(pxPktStackInit->xPreambleLength));
  s_assert_param(IS_STACK_SYNC_LENGTH(pxPktStackInit->xSyncLength));
  s_assert_param(IS_STACK_CRC_MODE(pxPktStackInit->xCrcMode));
  s_assert_param(IS_SFUNCTIONAL_STATE(pxPktStackInit->cExtendedPktLenField));
  s_assert_param(IS_SFUNCTIONAL_STATE(pxPktStackInit->xFixVarLength));
  s_assert_param(IS_SFUNCTIONAL_STATE(pxPktStackInit->xFec));
  s_assert_param(IS_SFUNCTIONAL_STATE(pxPktStackInit->xDataWhitening));

  S2LPPktWMbusSetSubmode(WMBUS_SUBMODE_NOT_CONFIGURED);
  
                                                 
  S2LPSpiReadRegisters(PROTOCOL1_ADDR, 1, &tmpBuffer[0]);
  tmpBuffer[0] |= AUTO_PCKT_FLT_REGMASK;
  S2LPSpiWriteRegisters(PROTOCOL1_ADDR, 1, &tmpBuffer[0]);

  tmpBuffer[0] = ((pxPktStackInit->xSyncLength)<<2) | (uint8_t)((pxPktStackInit->xPreambleLength)>>8);
  tmpBuffer[1] = (uint8_t)(pxPktStackInit->xPreambleLength);
  tmpBuffer[2] = ((uint8_t)pxPktStackInit->cExtendedPktLenField)<<7 | ADDRESS_LEN_REGMASK;
  
  S2LPSpiReadRegisters(PCKTCTRL3_ADDR, 1, &tmpBuffer[3]);
  tmpBuffer[3] &= ~(PCKT_FRMT_REGMASK | RX_MODE_REGMASK);
  tmpBuffer[3] |= PKT_FORMAT_STACK_CODE<<6;
  
  S2LPSpiReadRegisters(PCKTCTRL2_ADDR, 2, &tmpBuffer[4]);
  
  if(pxPktStackInit->xFixVarLength == S_ENABLE) {
     tmpBuffer[4] |= FIX_VAR_LEN_REGMASK;
  }
  else {
     tmpBuffer[4] &= ~FIX_VAR_LEN_REGMASK;
  }
  tmpBuffer[4] &= ~(MANCHESTER_EN_REGMASK | MBUS_3OF6_EN_REGMASK);
  
  tmpBuffer[5] &= ~(CRC_MODE_REGMASK | TXSOURCE_REGMASK);
  tmpBuffer[5] |= (uint8_t)pxPktStackInit->xCrcMode;
  
  if(pxPktStackInit->xDataWhitening == S_ENABLE) {
     tmpBuffer[5] |= WHIT_EN_REGMASK;
  }
  else {
     tmpBuffer[5] &= ~WHIT_EN_REGMASK;
  }

  if(pxPktStackInit->xFec == S_ENABLE) {
     tmpBuffer[5] |= FEC_EN_REGMASK;
  }
  else {
     tmpBuffer[5] &= ~FEC_EN_REGMASK;
  }
  
  S2LPSpiWriteRegisters(PCKTCTRL6_ADDR, 6, tmpBuffer);  

                 
  for(uint8_t i=0 ; i<4 ; i++) {
    tmpBuffer[i] = (uint8_t)(pxPktStackInit->lSyncWords>>(8*i));
  }
  g_xStatus = S2LPSpiWriteRegisters(SYNC3_ADDR, 4, tmpBuffer);
  
                          
  if(pxPktStackInit->xCrcMode == PKT_NO_CRC) {
    S2LPPktStackFilterOnCrc(S_DISABLE);
  }
  else {
    S2LPPktStackFilterOnCrc(S_ENABLE);
  }
                                   
  S2LPSpiReadRegisters(MOD1_ADDR, 1, tmpBuffer);
  tmpBuffer[0] &= ~G4FSK_CONST_MAP_REGMASK;
  S2LPSpiWriteRegisters(MOD1_ADDR, 1, tmpBuffer); 
}


   
                                                                                                         
                                                      
                                                            
                
   
void S2LPPktStackGetInfo(PktStackInit* pxPktStackInit)
{
  uint8_t tmpBuffer[6];

  S2LPSpiReadRegisters(PCKTCTRL6_ADDR, 6, tmpBuffer);
  
                   
  pxPktStackInit->xSyncLength = ((tmpBuffer[0] & SYNC_LEN_REGMASK)>>2);
  
                       
  pxPktStackInit->xPreambleLength = (((uint16_t)(tmpBuffer[0] & PREAMBLE_LEN_9_8_REGMASK))<<8) | ((uint16_t)tmpBuffer[1]);
  
                    
  pxPktStackInit->cExtendedPktLenField = (SFunctionalState)((tmpBuffer[2] & LEN_WID_REGMASK)>>7);

                      
  pxPktStackInit->xFixVarLength = (SFunctionalState)(tmpBuffer[4] & FIX_VAR_LEN_REGMASK);

                
  pxPktStackInit->xCrcMode = (StackCrcMode)(tmpBuffer[5] & CRC_MODE_REGMASK);
  
                 
  pxPktStackInit->xDataWhitening = (SFunctionalState)((tmpBuffer[5] & WHIT_EN_REGMASK)>> 4);

           
  pxPktStackInit->xFec = (SFunctionalState)(tmpBuffer[5] & FEC_EN_REGMASK);
  
  g_xStatus = S2LPSpiReadRegisters(SYNC3_ADDR, 4, tmpBuffer);
  
                 
  pxPktStackInit->lSyncWords = 0;
  for(uint8_t i=0 ; i<4 ; i++) {
    pxPktStackInit->lSyncWords |= ((uint32_t)tmpBuffer[3-i])<<(8*i);
  }
  
}


   
                                                                                
                                                      
                                                                     
                                                                      
                
   
void S2LPPktStackAddressesInit(PktStackAddressesInit* pxPktStackAddresses)
{
  uint8_t tmpBuffer[3];
  s_assert_param(IS_SFUNCTIONAL_STATE(pxPktStackAddresses->xFilterOnMyAddress));
  s_assert_param(IS_SFUNCTIONAL_STATE(pxPktStackAddresses->xFilterOnMulticastAddress));
  s_assert_param(IS_SFUNCTIONAL_STATE(pxPktStackAddresses->xFilterOnBroadcastAddress));

                                           
  S2LPSpiReadRegisters(PCKT_FLT_OPTIONS_ADDR, 1, &tmpBuffer[0]);
  
                                                   
  if(pxPktStackAddresses->xFilterOnMyAddress == S_ENABLE) {
    tmpBuffer[0] |= DEST_VS_SOURCE_ADDR_REGMASK;
  }
  else {
    tmpBuffer[0] &= ~DEST_VS_SOURCE_ADDR_REGMASK;
  }
  
                                                          
  if(pxPktStackAddresses->xFilterOnMulticastAddress == S_ENABLE) {
    tmpBuffer[0] |= DEST_VS_MULTICAST_ADDR_REGMASK;
  }
  else {
    tmpBuffer[0] &= ~DEST_VS_MULTICAST_ADDR_REGMASK;
  }
  
                                                          
  if(pxPktStackAddresses->xFilterOnBroadcastAddress == S_ENABLE) {
    tmpBuffer[0] |= DEST_VS_BROADCAST_ADDR_REGMASK;
  }
  else {
    tmpBuffer[0] &= ~DEST_VS_BROADCAST_ADDR_REGMASK;
  }
  
  S2LPSpiWriteRegisters(PCKT_FLT_OPTIONS_ADDR, 1, &tmpBuffer[0]);
  
                                                                  
  tmpBuffer[2] = pxPktStackAddresses->cMyAddress;
  tmpBuffer[0] = pxPktStackAddresses->cBroadcastAddress;
  tmpBuffer[1] = pxPktStackAddresses->cMulticastAddress;
  g_xStatus = S2LPSpiWriteRegisters(PCKT_FLT_GOALS2_ADDR, 3, tmpBuffer);
}


   
                                                                                     
                                      
                                                                    
                                                                
               
  
void S2LPPktStackGetAddressesInfo(PktStackAddressesInit* pxPktStackAddresses)
{
  uint8_t tmpBuffer[3];

  S2LPSpiReadRegisters(PCKT_FLT_GOALS3_ADDR, 3, tmpBuffer);
  pxPktStackAddresses->cMyAddress = tmpBuffer[0];
  pxPktStackAddresses->cBroadcastAddress = tmpBuffer[1];
  pxPktStackAddresses->cMulticastAddress = tmpBuffer[2];
  
  g_xStatus = S2LPSpiReadRegisters(PCKT_FLT_OPTIONS_ADDR, 1, &tmpBuffer[0]);
  pxPktStackAddresses->xFilterOnBroadcastAddress = (SFunctionalState)((tmpBuffer[0] & DEST_VS_BROADCAST_ADDR_REGMASK) >> 3);
  pxPktStackAddresses->xFilterOnMulticastAddress = (SFunctionalState)((tmpBuffer[0] & DEST_VS_MULTICAST_ADDR_REGMASK) >> 2);
  pxPktStackAddresses->xFilterOnMyAddress = (SFunctionalState)((tmpBuffer[0] & DEST_VS_SOURCE_ADDR_REGMASK) >> 1);
}


   
                                                      
                
                
   
void S2LPPktStackSetFormat(void)
{
  uint8_t tmp;
  
  S2LPSpiReadRegisters(PCKTCTRL3_ADDR, 1, &tmp);
  
                                                                  
  tmp &= ~(PCKT_FRMT_REGMASK | RX_MODE_REGMASK);
  tmp |= PKT_FORMAT_STACK_CODE;
  S2LPSpiWriteRegisters(PCKTCTRL3_ADDR, 1, &tmp);

  S2LPSpiReadRegisters(PCKTCTRL1_ADDR, 1, &tmp);
  
                                        
  tmp &= ~TXSOURCE_REGMASK;
  g_xStatus = S2LPSpiWriteRegisters(PCKTCTRL1_ADDR, 1, &tmp);

  S2LPPktWMbusSetSubmode(WMBUS_SUBMODE_NOT_CONFIGURED);
}



   
                                                                                 
                                                                     
                                                                                      
                                                                                 
                                                  
                                                       
                
   
void S2LPPktStackSetPayloadLength(uint16_t nPayloadLength)
{
  uint8_t tmpBuffer[2];

  nPayloadLength+=2;
  tmpBuffer[0] = (uint8_t)(nPayloadLength>>8);
  tmpBuffer[1] = (uint8_t)nPayloadLength;
  g_xStatus = S2LPSpiWriteRegisters(PCKTLEN1_ADDR, 2, tmpBuffer);
}


   
                                                                      
                                                                 
                                                            
                                                                     
                          
                
                                   
   
uint16_t S2LPPktStackGetPayloadLength(void)
{
  uint8_t tmpBuffer[2];
  uint16_t nPayloadLength;

  g_xStatus = S2LPSpiReadRegisters(PCKTLEN1_ADDR, 2, tmpBuffer);
  nPayloadLength = (((uint16_t)tmpBuffer[0])<<8) | ((uint16_t)tmpBuffer[1]);
  nPayloadLength-=2;

  return nPayloadLength;
}


   
                                                                 
                
                                  
   
uint16_t S2LPPktStackGetReceivedPktLength(void)
{
  uint8_t tmpBuffer[2];
  uint16_t nPayloadLength;

  g_xStatus = S2LPSpiReadRegisters(RX_PCKT_LEN1_ADDR, 2, tmpBuffer);
  nPayloadLength = (((uint16_t)tmpBuffer[0])<<8) | ((uint16_t)tmpBuffer[1]);
    nPayloadLength--;

  return nPayloadLength;
}


   
                                               
                                                                                                                                      
               
  
void S2LPPktStackAutoAck(SFunctionalState xNewState)
{
  uint8_t tmp;
  s_assert_param(IS_SFUNCTIONAL_STATE(xNewState));

  S2LPSpiReadRegisters(PROTOCOL0_ADDR, 1, &tmp);
  if(xNewState == S_ENABLE) {
    tmp |= AUTO_ACK_REGMASK;
  }
  else {
    tmp &= ~AUTO_ACK_REGMASK;
  }
  g_xStatus = S2LPSpiWriteRegisters(PROTOCOL0_ADDR, 1, &tmp);

}


   
                                                                           
                                          
               
  
void S2LPPktStackNRetx(uint8_t nRetx)
{
  uint8_t tmp;
  s_assert_param(IS_STACK_NMAX_RETX(nRetx));
  
  S2LPSpiReadRegisters(PROTOCOL0_ADDR, 1, &tmp);
  tmp &= ~NMAX_RETX_REGMASK;
  tmp |= (nRetx<<4);
  g_xStatus = S2LPSpiWriteRegisters(PROTOCOL0_ADDR, 1, &tmp);

}


   
                             
               
                                                                                          
  
SFlagStatus S2LPPktStackGetTXAckRequest(void)
{
  uint8_t tmp;
  
  S2LPSpiReadRegisters(RX_PCKT_INFO_ADDR, 1, &tmp);
  tmp &= NACK_RX_REGMASK;
  tmp >>= 2;
  return (SFlagStatus)tmp;
}

   
                                                            
                                                                                                             
                                                                                                          
               
  
void S2LPPktStackAckRequest(SFunctionalState xNewState)
{
  uint8_t tmp;
  s_assert_param(IS_SFUNCTIONAL_STATE(xNewState));

  S2LPSpiReadRegisters(PROTOCOL0_ADDR, 1, &tmp);
  if(xNewState == S_ENABLE) {
    tmp &= ~NACK_TX_REGMASK;
  }
  else {
    tmp |= NACK_TX_REGMASK;
  }
  g_xStatus = S2LPSpiWriteRegisters(PROTOCOL0_ADDR, 1, &tmp);

}


   
                                             
                                      
               
  
void S2LPPktStackPiggybacking(SFunctionalState xNewState)
{
  uint8_t tmp;
  s_assert_param(IS_SFUNCTIONAL_STATE(xNewState));

  S2LPSpiReadRegisters(PROTOCOL1_ADDR, 1, &tmp);
  if(xNewState == S_ENABLE) {
    tmp |= PIGGYBACKING_REGMASK;
  }
  else {
    tmp &= ~PIGGYBACKING_REGMASK;
  }
  g_xStatus = S2LPSpiWriteRegisters(PROTOCOL1_ADDR, 1, &tmp);

}


   
                                                      
                                                                                                   
                                    
               
  
void S2LPPktStackSeqNumForReload(uint8_t cReloadValue)
{
  uint8_t tmp;
  s_assert_param(IS_STACK_SEQNUM_RELOAD_VAL(cReloadValue));
  
  S2LPSpiReadRegisters(PROTOCOL2_ADDR, 1, &tmp);
  tmp &= ~TX_SEQ_NUM_RELOAD_REGMASK;
  tmp |= (cReloadValue<<3);
  g_xStatus = S2LPSpiWriteRegisters(PROTOCOL2_ADDR, 1, &tmp);
}

   
                                                                               
                
                                                            
   
uint8_t S2LPPktStackGetNReTx(void)
{
  uint8_t tempRetValue;

                                             
  g_xStatus = S2LPSpiReadRegisters(TX_PCKT_INFO_ADDR, 1, &tempRetValue);

                                                             
  return (tempRetValue & 0x0F);

}


   
    
   

   
    
   


   
    
   



/******************* (C) COPYRIGHT 2016 STMicroelectronics *****END OF FILE****/
