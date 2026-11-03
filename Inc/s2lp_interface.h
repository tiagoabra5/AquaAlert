#ifndef __S2LP_INTERFACE_H
#define __S2LP_INTERFACE_H


                                                                                
#include "S2LP_Gpio.h"
#include "S2LP_Radio.h"
#include "S2LP_Util.h"
#include "S2LP_Regs.h"
#include "S2LP_Types.h"
#ifdef __cplusplus
  "C" { 
#endif


   
                             
     
   
    
typedef struct 
{
  uint16_t nS2LP_Version;
}S2LP_VersionMap;
   
#define CUT_MAX_NO 3
#define CUT_2_1v3 0x0103
#define CUT_2_1v4 0x0104
#define CUT_3_0   0x0130


   
                                     
     
   
void S2LP_ManagementIdentificationRFBoard(void);

RangeExtType S2LP_ManagementGetRangeExtender(void);
void S2LP_ManagementSetRangeExtender(RangeExtType xRangeType);
void S2LP_ManagementRangeExtInit(void);
void S2LP_ManagementSetBand(uint8_t value);
uint8_t S2LP_ManagementGetBand(void);

uint8_t SdkEvalGetHasEeprom(void);

void S2LP_InterfaceInit(void);
void S2LPInterfaceInit(void);
void S2LPGpioIrqInit(S2LPIrqs *pGpioIRQ);
void S2LP_RadioInit(SRadioInit *pRadioInit);
void S2LP_PacketConfig(void);
void S2LP_SetPayloadlength(uint8_t length);
void S2LP_SetDestinationAddress(uint8_t address);
void S2LP_EnableTxIrq(void);
void S2LP_EnableRxIrq(void);
void S2LP_DisableIrq(void);
void S2LP_SetRxTimeout(float cRxTimeOut);
void S2LP_EnableSQI(void);
void S2LP_SetRssiTH(int dbmValue);
float S2LP_GetRssiTH(void);
void S2LP_StartRx(void);
void S2LP_GetRxPacket(uint8_t *buffer, uint8_t *size );
void S2LP_StartTx(uint8_t *buffer, uint8_t size);


void SdkEvalSetHasEeprom(uint8_t eeprom);
   
    
  

   
    
  

   
    
  

#ifdef __cplusplus
}
#endif


#endif

