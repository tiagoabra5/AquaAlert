/**
 * @file    S2LP_PktWMbus.h
 * @author  LowPower RF BU - AMG
 * @version 1.3.0
 * @date    10-July-2017
 * @brief   Configuration and management of S2-LP WMbus packets.
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
 * This module can be used to manage the configuration of S2-LP WMbus
 * packets.
 * The user can obtain a packet configuration filling the structure
 * <i>@ref PktWMbusInit</i>, defining in it some general parameters
 * for the S2-LP WMbus packet format.
 * Since the WMbus protocol is a standard, the configuration of a WMbus
 * packet is very simple to do.
 *
 * <b>Example:</b>
 * @code
 *
 * PktWMbusInit mbusInit={
 *   WMbus_SUBMODE_S1_S2_LONG_HEADER,    // WMbus submode selection
 *   36,                                // added "01" chips on preamble
 *   16                                 // postamble length in "01" chips
 * };
 *
 * ...
 *
 * S2LPPktWMbusInit(&mbusInit);
 *
 * ...
 *
 * @endcode
 * <h2><center>&copy; COPYRIGHT 2019 STMicroelectronics</center></h2>
 */

                                                                                
#ifndef __S2LP_PACKET_WMBUS_H
#define __S2LP_PACKET_WMBUS_H


                                                                                

#include "S2LP_Regs.h"
#include "S2LP_Types.h"
#include "S2LP_PacketHandler.h"

#ifdef __cplusplus
 extern "C" {
#endif



   
                             
     
   


   
                                        
                                                             
                                                                      
     
   

   
                                                                 
     
   



   
                                     
   

typedef enum {
  WMBUS_SUBMODE_NOT_CONFIGURED            = 0,                                                                                                                                                
  WMBUS_SUBMODE_S1_S2_LONG_HEADER,                                                                                                                                                            
  WMBUS_SUBMODE_S1_M_S2_T2_OTHER_TO_METER,                                                                                                                                                           
  WMBUS_SUBMODE_T1_T2_METER_TO_OTHER,                                                                                                                                                         
  WMBUS_SUBMODE_R2_SHORT_HEADER,                                                                                                                                                        
} WMbusSubmode;


   
                                                      
   
typedef struct {
  WMbusSubmode   xWMbusSubmode;                                                      
  uint8_t        cPreambleLength;                                                    
  uint8_t        cPostambleLength;                                                    
} PktWMbusInit;

   
    
   



   
                                                                                     
     
   

   
                                                                 
                                                             
                                                                       
                
   
#define S2LPPktWMbusSetPreambleLength(xPreambleLength)                S2LPPktCommonSetPreambleLength((PktPreambleLength)xPreambleLength)


   
                                                                         
                
                                                  
   
#define S2LPPktWMbusGetPreambleLength()                               S2LPPktCommonGetPreambleLength()


void S2LPPktWMbusInit(PktWMbusInit* pxPktWMbusInit);
void S2LPPktWMbusGetInfo(PktWMbusInit* pxPktWMbusInit);
void S2LPPktWMbusSetFormat(void);
void S2LPPktWMbusSetPostamble(uint8_t cPostamble);
uint8_t S2LPPktWMbusGetPostamble(void);
void S2LPPktWMbusSetPostamblePattern(uint8_t cPostamble);
uint8_t S2LPPktWMbusGetPostamblePattern(void);
void S2LPPktWMbusSetSubmode(WMbusSubmode xWMbusSubmode);
WMbusSubmode S2LPPktWMbusGetSubmode(void);
void S2LPPktWMbusSetPayloadLength(uint16_t nPayloadLength);
uint16_t S2LPPktWMbusGetPayloadLength(void);


   
    
   

   
    
   


   
    
   


#ifdef __cplusplus
}
#endif

#endif

/******************* (C) COPYRIGHT 2016 STMicroelectronics *****END OF FILE****/
