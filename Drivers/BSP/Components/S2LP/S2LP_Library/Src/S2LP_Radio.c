/**
 * @file    S2LP_Radio.c
 * @author  LowPower RF BU - AMG
 * @version 1.3.0
 * @date    10-July-2017
 * @brief   This file provides all the low level API to manage Analog and Digital
 *          radio part of S2-LP.
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
 *
 */

                                                                                
#include "S2LP_Radio.h"
#include "S2LP_Config.h"
#include "MCU_Interface.h"


                              
    
  


                          
    
  


                                                                             
    
  

#define MAX_PA_VALUE                    14
#define MIN_PA_VALUE                    -31

#define VCO_CENTER_FREQ                 3600000000                                             

#define HIGH_BAND_FACTOR      4                                                                         
#define MIDDLE_BAND_FACTOR    8                                                                            

#define HIGH_BAND_LOWER_LIMIT         860000000                                                
#define HIGH_BAND_UPPER_LIMIT         940000000                                                
#define MIDDLE_BAND_LOWER_LIMIT       430000000                                                  
#define MIDDLE_BAND_UPPER_LIMIT       470000000                                                  

#define MINIMUM_DATARATE                 100                                                    
#define MAXIMUM_DATARATE                 250000                                                     


   
    
  


                                                                            
    
  

#define IS_PA_MAX_INDEX(INDEX)       ((INDEX)<=7)
#define IS_PAPOWER_DBM(PATABLE)      ((PATABLE)>= (MIN_PA_VALUE) && (PATABLE)<=(MAX_PA_VALUE))
#define IS_PAPOWER(PATABLE)          ((PATABLE)<=90)
#define IS_PA_STEP_WIDTH(WIDTH)      ((WIDTH)>=1 && (WIDTH)<=4)

#define IS_MODULATION(MOD) (((MOD) == MOD_NO_MOD) || \
                             ((MOD) == MOD_2FSK) || \
                             ((MOD) == MOD_4FSK) || \
                             ((MOD) == MOD_2GFSK_BT05) || \
                             ((MOD) == MOD_2GFSK_BT1) || \
                             ((MOD) == MOD_4GFSK_BT05) || \
                             ((MOD) == MOD_4GFSK_BT1) || \
                             ((MOD) == MOD_ASK_OOK) || \
                             ((MOD) == MOD_POLAR))

#define IS_AFC_MODE(MODE)       (MODE<=1)
#define IS_AFC_GAIN(GAIN)       (GAIN<=15)
#define IS_ISI_EQU(MODE)        (MODE<=2)
#define IS_CLKREC_MODE(MODE)    (MODE<=1)
#define IS_CLKREC_P_GAIN(GAIN)  (GAIN<=7)
#define IS_CLKREC_I_GAIN(GAIN)  (GAIN<=15)


#define IS_FREQUENCY_BAND_HIGH(FREQUENCY) ((FREQUENCY)>=HIGH_BAND_LOWER_LIMIT && \
                                           (FREQUENCY)<=HIGH_BAND_UPPER_LIMIT)

#define IS_FREQUENCY_BAND_MIDDLE(FREQUENCY) ((FREQUENCY)>=MIDDLE_BAND_LOWER_LIMIT && \
                                             (FREQUENCY)<=MIDDLE_BAND_UPPER_LIMIT)

#define IS_FREQUENCY_BAND(FREQUENCY) (IS_FREQUENCY_BAND_HIGH(FREQUENCY) || \
                                      IS_FREQUENCY_BAND_MIDDLE(FREQUENCY))

#define IS_CHANNEL_SPACE(CHANNELSPACE, F_Xo)    (CHANNELSPACE<=(F_Xo/32768*255))


#define IS_DATARATE(DATARATE, F_CLK)      (DATARATE>=MINIMUM_DATARATE && DATARATE<=((uint64_t)MAXIMUM_DATARATE*F_CLK/1000000)/26)


#define F_DEV_LOWER_LIMIT(F_Xo)		(F_Xo>>22)
#define F_DEV_UPPER_LIMIT(F_Xo)		(((uint64_t)787109*F_Xo/1000000)/26)
#define IS_F_DEV(FDEV,F_Xo)        (FDEV>=F_DEV_LOWER_LIMIT(F_Xo) && FDEV<=F_DEV_UPPER_LIMIT(F_Xo))

#define CH_BW_LOWER_LIMIT(F_CLK)      (((uint64_t)1100*F_CLK/1000000)/26)                                                       
#define CH_BW_UPPER_LIMIT(F_CLK)    (((uint64_t)800100*F_CLK/1000000)/26)                                                       

#define IS_CH_BW(BW,F_Xo)         ((BW)>=CH_BW_LOWER_LIMIT(F_Xo) && (BW)<=CH_BW_UPPER_LIMIT(F_Xo))

   
    
  


                                                                               
    
  

   
                                                                                
  
static uint32_t s_lXtalFrequency=50000000;


   
                                                                                 
                                                                                            
                                                                        
  
static const uint16_t s_vectnBandwidth26M[90]=
{
  8001, 7951, 7684, 7368, 7051, 6709, 6423, 5867, 5414, \
    4509, 4259, 4032, 3808, 3621, 3417, 3254, 2945, 2703, \
      2247, 2124, 2015, 1900, 1807, 1706, 1624, 1471, 1350, \
        1123, 1062, 1005,  950,  903,  853,  812,  735,  675, \
          561,  530,  502,  474,  451,  426,  406,  367,  337, \
            280,  265,  251,  237,  226,  213,  203,  184,  169, \
              140,  133,  126,  119,  113,  106,  101,   92,   84, \
                70,   66,   63,   59,   56,   53,   51,   46,   42, \
                  35,   33,   31,   30,   28,   27,   25,   23,   21, \
                    18,   17,   16,   15,   14,   13,   13,   12,   11
};


   
    
  


                                                                                         
    
  
uint32_t S2LPRadioComputeDatarate(uint16_t cM, uint8_t cE);
void S2LPRadioSearchDatarateME(uint32_t lDatarate, uint16_t* pcM, uint8_t* pcE);
void S2LPRadioSearchFreqDevME(uint32_t lFDev, uint8_t* pcM, uint8_t* pcE);
void S2LPRadioSearchChannelBwME(uint32_t lBandwidth, uint8_t* pcM, uint8_t* pcE);
uint32_t S2LPRadioComputeDatarate(uint16_t cM, uint8_t cE);
uint32_t S2LPRadioComputeFreqDeviation(uint8_t cM, uint8_t cE, uint8_t bs, uint8_t refdiv);
uint32_t S2LPRadioComputeChannelFilterBw(uint8_t cM, uint8_t cE);
uint32_t S2LPRadioComputeFrequencyBase(uint32_t lSynthWord, uint8_t bs, uint8_t refdiv);
uint32_t S2LPRadioComputeSynthWord(uint32_t frequency, uint8_t refdiv);
uint8_t S2LPRadioComputeChannelSpacingRegValue(uint32_t lChannelSpace);
uint32_t S2LPRadioComputeChannelSpacing(uint8_t cChSpaceRegVal);
void S2LPRadioSearchWCP(uint8_t* cp_isel, uint8_t* pfd_split, uint32_t lFc, uint8_t refdiv);
void S2LPRadioComputeIF(uint32_t nIF, uint8_t* pcAnaIf, uint8_t* pcPcDigIf);              

   
    
  


                                                                                
    
  

   
                                                                                     
                                                                    
                                                                                             
                                                     
                                                     
               
  
void S2LPRadioSearchDatarateME(uint32_t lDatarate, uint16_t* pcM, uint8_t* pcE)
{
  uint32_t lDatarateTmp, f_dig=s_lXtalFrequency;
  uint8_t uDrE;
  uint64_t tgt1,tgt2,tgt;
  
  if(f_dig>DIG_DOMAIN_XTAL_THRESH) {
    f_dig >>= 1;
  }
  
                                 
  for(uDrE = 0; uDrE != 12; uDrE++) {
    lDatarateTmp = S2LPRadioComputeDatarate(0xFFFF, uDrE);
    if(lDatarate<=lDatarateTmp) 
      break;
  }
  (*pcE) = (uint8_t)uDrE;
  
  if(uDrE==0) {
    tgt=((uint64_t)lDatarate)<<32;
    (*pcM) = (uint16_t)(tgt/f_dig);
    tgt1=(uint64_t)f_dig*(*pcM);
    tgt2=(uint64_t)f_dig*((*pcM)+1);
  }
  else {
    tgt=((uint64_t)lDatarate)<<(33-uDrE);
    (*pcM) = (uint16_t)((tgt/f_dig)-65536);
    tgt1=(uint64_t)f_dig*((*pcM)+65536);
    tgt2=(uint64_t)f_dig*((*pcM)+1+65536);
  }
    
       
  (*pcM)=((tgt2-tgt)<(tgt-tgt1))?((*pcM)+1):(*pcM);
  
}

   
                                                                                                
                                                                                             
                                                                                                                              
                                                     
                                                     
               
  
void S2LPRadioSearchFreqDevME(uint32_t lFDev, uint8_t* pcM, uint8_t* pcE)
{
  uint8_t uFDevE, tmp, bs = MIDDLE_BAND_FACTOR, refdiv = 1;
  uint32_t lFDevTmp;
  uint64_t tgt1,tgt2,tgt;
  
  s_assert_param(IS_F_DEV(lFDev, s_lXtalFrequency));  
  
  S2LPSpiReadRegisters(SYNT3_ADDR, 1, &tmp);
  if((tmp&BS_REGMASK) == 0) {
    bs = HIGH_BAND_FACTOR;
  }
  
  if(S2LPRadioGetRefDiv()) {
    refdiv = 2;
  }
  
                                                            
  for(uFDevE = 0; uFDevE != 12; uFDevE++) {
    lFDevTmp = S2LPRadioComputeFreqDeviation(255, uFDevE, bs, refdiv);
    if(lFDev<lFDevTmp) 
      break;
  }
  (*pcE) = (uint8_t)uFDevE;
    
  if(uFDevE==0)
  {
    tgt=((uint64_t)lFDev)<<22;
    (*pcM)=(uint32_t)(tgt/s_lXtalFrequency);
    tgt1=(uint64_t)s_lXtalFrequency*(*pcM);
    tgt2=(uint64_t)s_lXtalFrequency*((*pcM)+1);
  }
  else
  {
    tgt=((uint64_t)lFDev)<<(23-uFDevE);
    (*pcM)=(uint32_t)(tgt/s_lXtalFrequency)-256;
    tgt1=(uint64_t)s_lXtalFrequency*((*pcM)+256);
    tgt2=(uint64_t)s_lXtalFrequency*((*pcM)+1+256);
  }

  (*pcM)=((tgt2-tgt)<(tgt-tgt1))?((*pcM)+1):(*pcM);
}


   
                                                                  
                                                                                             
                                                                                    
                                                                                                                     
                             
                                                                                               
                                                     
                                                     
               
  
void S2LPRadioSearchChannelBwME(uint32_t lBandwidth, uint8_t* pcM, uint8_t* pcE)
{
  int8_t i, i_tmp;
  uint32_t f_dig=s_lXtalFrequency;
  int32_t chfltCalculation[3];
  
      
  if(f_dig>DIG_DOMAIN_XTAL_THRESH) {
    f_dig >>= 1;
  }
  
  s_assert_param(IS_CH_BW(lBandwidth,f_dig));
  
                                                       
  for(i=0;i<90 && (lBandwidth<(uint32_t)(((uint64_t)s_vectnBandwidth26M[i]*f_dig)/260000));i++);
  
  if(i!=0) {
                                                                                  
    i_tmp = i;
    
    for(uint8_t j=0;j<3;j++) {
      if(((i_tmp+j-1)>=0) && ((i_tmp+j-1)<=89)) {
        chfltCalculation[j] = (int32_t)lBandwidth - (int32_t)(((uint64_t)s_vectnBandwidth26M[i_tmp+j-1]*f_dig)/260000);
      }
      else {
        chfltCalculation[j] = 0x7FFFFFFF;
      }
    }
    uint32_t chfltDelta = 0xFFFFFFFF;
    
    for(uint8_t j=0;j<3;j++) {
      if(S_ABS(chfltCalculation[j])<chfltDelta) {
        chfltDelta = S_ABS(chfltCalculation[j]);
        i=i_tmp+j-1;
      }    
    }
  }
  (*pcE) = (uint8_t)(i/9);
  (*pcM) = (uint8_t)(i%9);
  
}

   
                                                                                     
                                                                    
                                                                                             
                                                     
                                                     
               
  
uint32_t S2LPRadioComputeDatarate(uint16_t cM, uint8_t cE)
{
  uint32_t f_dig=s_lXtalFrequency;
  uint64_t dr;
  
  if(f_dig>DIG_DOMAIN_XTAL_THRESH) {
    f_dig >>= 1;
  }  
  
  if(cE==0) {
    dr=((uint64_t)f_dig*cM);
    return (uint32_t)(dr>>32);
  }
  
  dr=((uint64_t)f_dig)*((uint64_t)cM+65536);
  
  return (uint32_t)(dr>>(33-cE));
}

   
                                                                                     
                                                                    
                                                                                             
                                                     
                                                     
               
  
uint32_t S2LPRadioComputeFreqDeviation(uint8_t cM, uint8_t cE, uint8_t bs, uint8_t refdiv)
{
  uint32_t f_xo=s_lXtalFrequency;
  
  if(cE==0) {
    return (uint32_t)(((uint64_t)f_xo*cM)>>22);
  }
  
  return (uint32_t)(((uint64_t)f_xo*(256+cM))>>(23-cE));
}


   
                                                                                
                            
                            
                                                  
  
uint32_t S2LPRadioComputeChannelFilterBw(uint8_t cM, uint8_t cE)
{
  uint32_t f_dig=s_lXtalFrequency;
  
  if(f_dig>DIG_DOMAIN_XTAL_THRESH) {
    f_dig >>= 1;
  }
  
  return (uint32_t)((uint64_t)100*s_vectnBandwidth26M[cM+(cE*9)]*f_dig/26000000);
  
}


   
                                                       
                                          
                                      
                                                                       
                                                         
  
uint32_t S2LPRadioComputeFrequencyBase(uint32_t lSynthWord, uint8_t bs, uint8_t refdiv)
{
  return (uint32_t)((((uint64_t)s_lXtalFrequency*lSynthWord)>>19)/bs/refdiv);
}


   
                                                         
                                                           
                                                                       
                              
  
uint32_t S2LPRadioComputeSynthWord(uint32_t frequency, uint8_t refdiv)
{
  uint8_t band;
  
  if(IS_FREQUENCY_BAND_HIGH(frequency)) {
    band = HIGH_BAND_FACTOR;
  }
  else {
    band = MIDDLE_BAND_FACTOR;
  }

  uint64_t tgt1,tgt2,tgt;
  uint32_t synth;
  
  tgt = (((uint64_t)frequency)<<19)*(band*refdiv);
  synth=(uint32_t)(tgt/s_lXtalFrequency);
  tgt1 = (uint64_t)s_lXtalFrequency*(synth);
  tgt2 = (uint64_t)s_lXtalFrequency*(synth+1);
  
  synth=((tgt2-tgt)<(tgt-tgt1))?(synth+1):(synth);
  
  return synth;
}


   
                                                                                         
                                                 
                                                            
                                                      
  
uint8_t S2LPRadioComputeChannelSpacingRegValue(uint32_t lChannelSpace)
{
  return (uint32_t)(((uint64_t)lChannelSpace)<<15)/s_lXtalFrequency;
}


   
                                                                                    
                                                 
                                                     
                                                   
  
uint32_t S2LPRadioComputeChannelSpacing(uint8_t cChSpaceRegVal)
{
  return (uint32_t)(((uint64_t)s_lXtalFrequency*cChSpaceRegVal)>>15);
}


   
                                                                                              
                       
                                                                                       
                                                       
                                                        
               
  
void S2LPRadioComputeIF(uint32_t nIF, uint8_t* pcAnaIf, uint8_t* pcDigIf)
{
  uint32_t f_dig=s_lXtalFrequency;
  
  if(f_dig>DIG_DOMAIN_XTAL_THRESH) {
    f_dig >>= 1;
  }
  
  (*pcAnaIf)=(uint8_t)((((uint64_t)nIF)<<13)*3/s_lXtalFrequency-100);
  (*pcDigIf)=(uint8_t)((((uint64_t)nIF)<<13)*3/f_dig-100);
}


   
                                                                 
                                                            
                                                      
                                                       
                                                                           
                                                       
                                                         
                                                                       
                                   
  
void S2LPRadioSearchWCP(uint8_t* cp_isel, uint8_t* pfd_split, uint32_t lFc, uint8_t refdiv)
{
  uint32_t vcofreq, lFRef;
  uint8_t BFactor = MIDDLE_BAND_FACTOR;
  
  s_assert_param(IS_FREQUENCY_BAND(lFc));
  
                                 
  if(IS_FREQUENCY_BAND_HIGH(lFc)) {
    BFactor = HIGH_BAND_FACTOR;
  }
  
                                                    
  vcofreq = lFc*BFactor;
  
                                                
  lFRef = s_lXtalFrequency/refdiv;
  
                                        
  if(vcofreq>=VCO_CENTER_FREQ) {
    if(lFRef>DIG_DOMAIN_XTAL_THRESH) {
      *cp_isel = 0x02;
      *pfd_split = 0;
    }
    else {
      *cp_isel = 0x01;
      *pfd_split = 1;
    }
  }
  else {
    if(lFRef>DIG_DOMAIN_XTAL_THRESH) {
      *cp_isel = 0x03;
      *pfd_split = 0;
    }
    else {
      *cp_isel = 0x02;
      *pfd_split = 1;
    }
  }
  
}


   
    
  


                                                                              
    
  


   
                                                                                       
                                               
                                                                   
                                                                                   
                                                                    
  
uint8_t S2LPRadioInit(SRadioInit* pxSRadioInitStruct)
{
  uint8_t tmpBuffer[6], tmp8, dr_e, fdev_m, fdev_e, bw_m, bw_e;
  uint16_t dr_m;
  SFunctionalState xState;
  
  s_assert_param(IS_FREQUENCY_BAND(pxSRadioInitStruct->lFrequencyBase));
  s_assert_param(IS_MODULATION(pxSRadioInitStruct->xModulationSelect));
  s_assert_param(IS_DATARATE(pxSRadioInitStruct->lDatarate,s_lXtalFrequency));
  s_assert_param(IS_F_DEV(pxSRadioInitStruct->lFreqDev,s_lXtalFrequency));
    
                                                                
  xState = S2LPRadioGetDigDiv();
  if(((s_lXtalFrequency<DIG_DOMAIN_XTAL_THRESH) && (xState==S_ENABLE)) || ((s_lXtalFrequency>DIG_DOMAIN_XTAL_THRESH) && (xState==S_DISABLE))) {
    S2LPSpiCommandStrobes(CMD_STANDBY);    
    do{
      for(volatile uint8_t i=0; i!=0xFF; i++);
      S2LPRefreshStatus();                                        
    }while(g_xStatus.MC_STATE!=MC_STATE_STANDBY);
    
    xState = (SFunctionalState)!xState;
    S2LPRadioSetDigDiv(xState); 
    
    S2LPSpiCommandStrobes(CMD_READY);
    do{
      for(volatile uint8_t i=0; i!=0xFF; i++);
      S2LPRefreshStatus();                                        
    }while(g_xStatus.MC_STATE!=MC_STATE_READY);
  }  
  
  if(xState==S_ENABLE) {
    s_assert_param(IS_CH_BW(pxSRadioInitStruct->lBandwidth,(s_lXtalFrequency>>1)));
  }
  else {
    s_assert_param(IS_CH_BW(pxSRadioInitStruct->lBandwidth,s_lXtalFrequency));
  }
  
                                        
  S2LPRadioComputeIF(300000, &tmpBuffer[0], &tmpBuffer[1]);
  S2LPSpiWriteRegisters(IF_OFFSET_ANA_ADDR, 2, tmpBuffer);

                                               
  S2LPRadioSearchDatarateME(pxSRadioInitStruct->lDatarate, &dr_m, &dr_e);
  tmpBuffer[0] = (uint8_t)(dr_m>>8);
  tmpBuffer[1] = (uint8_t)dr_m;
  tmpBuffer[2] = (uint8_t)(pxSRadioInitStruct->xModulationSelect | dr_e);

  
  
                                                          
  S2LPRadioSearchFreqDevME(pxSRadioInitStruct->lFreqDev, &fdev_m, &fdev_e);
  S2LPSpiReadRegisters(MOD1_ADDR, 1, &tmpBuffer[3]);
  tmpBuffer[3] &= ~FDEV_E_REGMASK;
  tmpBuffer[3] |= fdev_e;  
  tmpBuffer[4] = fdev_m;
  
                                                     
  S2LPRadioSearchChannelBwME(pxSRadioInitStruct->lBandwidth, &bw_m, &bw_e);
  tmpBuffer[5] = (bw_m<<4) | bw_e;  
  
                                      
  S2LPSpiWriteRegisters(MOD4_ADDR, 6, tmpBuffer);
  
  S2LPSpiReadRegisters(PA_POWER0_ADDR, 3, &tmpBuffer[0]);
  
                                                          
  if((pxSRadioInitStruct->xModulationSelect)!=MOD_ASK_OOK)
  {
    tmpBuffer[0] &= 0x7F;
    tmpBuffer[1] &= 0xFD;
  }
  else
  {
    tmpBuffer[0] |= 0x80;
    tmpBuffer[1] |= 0x02;
  }
  
  
  tmpBuffer[2]&=0xFC;
  
                            
  if(pxSRadioInitStruct->lDatarate<16000)
  {
    tmpBuffer[2]|=0x00;
  }
  else if(pxSRadioInitStruct->lDatarate<32000)
  {
    tmpBuffer[2]|=0x01;
  }
  else if(pxSRadioInitStruct->lDatarate<62500)
  {
    tmpBuffer[2]|=0x02;
  }
  else
  {
    tmpBuffer[2]|=0x03;
  }
  S2LPSpiWriteRegisters(PA_POWER0_ADDR, 3, &tmpBuffer[0]);
  
                                                              
  S2LPSpiReadRegisters(AFC2_ADDR, 1, &tmp8);
  tmp8 |= AFC_FREEZE_ON_SYNC_REGMASK; S2LPSpiWriteRegisters(AFC2_ADDR, 1, &tmp8);
  
  return S2LPRadioSetFrequencyBase(pxSRadioInitStruct->lFrequencyBase);
  
}


   
                                                                                               
                                                                   
                                                                                   
               
  
void S2LPRadioGetInfo(SRadioInit* pxSRadioInitStruct)
{
  uint8_t tmpBuffer[6];
  uint8_t band, cRefDiv, dr_e, fdev_m, fdev_e, bw_e, bw_m;
  uint16_t dr_m;
  uint32_t tmp32;
  
  S2LPSpiReadRegisters(SYNT3_ADDR, 4, tmpBuffer);  
  
                                                                
  if(tmpBuffer[0] & BS_REGMASK) {
    band = MIDDLE_BAND_FACTOR;
  }
  else {
    band = HIGH_BAND_FACTOR;
  }
  
                               
  tmp32 = (((uint32_t)(tmpBuffer[0] & SYNT_27_24_REGMASK))<<24) | (((uint32_t)tmpBuffer[1])<<16) | (((uint32_t)tmpBuffer[2])<<8) | ((uint32_t)tmpBuffer[3]);
  
                                     
  cRefDiv = (uint8_t)S2LPRadioGetRefDiv() + 1;
  
  pxSRadioInitStruct->lFrequencyBase = S2LPRadioComputeFrequencyBase(tmp32, band, cRefDiv);
  
                                 
  g_xStatus = S2LPSpiReadRegisters(MOD4_ADDR, 6, tmpBuffer);
  
                         
  pxSRadioInitStruct->xModulationSelect = (ModulationSelect)(tmpBuffer[2] & MOD_TYPE_REGMASK);
  
                                                               
  fdev_m = tmpBuffer[4];
  fdev_e = tmpBuffer[3] & FDEV_E_REGMASK;
  
                                                                   
  bw_m = (tmpBuffer[5] & CHFLT_M_REGMASK)>>4;
  bw_e = tmpBuffer[5] & CHFLT_E_REGMASK;
  
                                                              
  dr_m = ((uint16_t)tmpBuffer[0]<<8) | ((uint16_t)tmpBuffer[1]);
  dr_e = tmpBuffer[2] & DATARATE_E_REGMASK;
  
                               
  pxSRadioInitStruct->lDatarate = S2LPRadioComputeDatarate(dr_m, dr_e);
  
                                          
  pxSRadioInitStruct->lFreqDev = S2LPRadioComputeFreqDeviation(fdev_m, fdev_e, band, cRefDiv);
  
                                                                               
  pxSRadioInitStruct->lBandwidth = S2LPRadioComputeChannelFilterBw(bw_m, bw_e);
  
}


   
                                   
                                                                         
               
  
void S2LPRadioSetSynthWord(uint32_t lSynthWord)
{
  uint8_t tmpBuffer[4];
  uint8_t tmp;
  
  S2LPSpiReadRegisters(SYNT3_ADDR, 1, &tmp);
  tmp &= ~SYNT_27_24_REGMASK;
  
                                           
  tmpBuffer[0] = (((uint8_t)(lSynthWord>>24)) & SYNT_27_24_REGMASK) | tmp;
  tmpBuffer[1] = (uint8_t)(lSynthWord>>16);
  tmpBuffer[2] = (uint8_t)(lSynthWord>>8);
  tmpBuffer[3] = (uint8_t)lSynthWord;
  
  g_xStatus = S2LPSpiWriteRegisters(SYNT3_ADDR, 4, tmpBuffer);
}


   
                                 
               
                              
  
uint32_t S2LPRadioGetSynthWord(void)
{
  uint8_t tmpBuffer[4];
  g_xStatus = S2LPSpiReadRegisters(SYNT3_ADDR, 4, tmpBuffer);
  return ((((uint32_t)(tmpBuffer[0] & SYNT_27_24_REGMASK))<<24) | (((uint32_t)tmpBuffer[1])<<16) | (((uint32_t)tmpBuffer[2])<<8) | ((uint32_t)tmpBuffer[3]));
}


   
                                  
                                      
               
  
void S2LPRadioSetChannel(uint8_t cChannel)
{
  g_xStatus = S2LPSpiWriteRegisters(CHNUM_ADDR, 1, &cChannel);
}


   
                                            
               
                                        
  
uint8_t S2LPRadioGetChannel(void)
{
  uint8_t tmp;
  g_xStatus = S2LPSpiReadRegisters(CHNUM_ADDR, 1, &tmp);
  return tmp;
}


   
                                          
                                                                                           
               
  
void S2LPRadioSetRefDiv(SFunctionalState xNewState)
{
  uint8_t tmp;
  
  s_assert_param(IS_SFUNCTIONAL_STATE(xNewState));
  
  S2LPSpiReadRegisters(XO_RCO_CONF0_ADDR, 1, &tmp);
  
  if(xNewState == S_ENABLE) {
    tmp |= REFDIV_REGMASK;
  } else {
    tmp &= ~REFDIV_REGMASK;
  }
  g_xStatus = S2LPSpiWriteRegisters(XO_RCO_CONF0_ADDR, 1, &tmp);
}


   
                                                                   
               
                                                             
  
SFunctionalState S2LPRadioGetRefDiv(void)
{
  uint8_t tmp;
  
  g_xStatus = S2LPSpiReadRegisters(XO_RCO_CONF0_ADDR, 1, &tmp);
  
  if(tmp & REFDIV_REGMASK) {
    return S_ENABLE;
  } else {
    return S_DISABLE;
  }
}


   
                                   
                                                                                       
               
  
void S2LPRadioSetDigDiv(SFunctionalState xNewState)
{
  uint8_t tmp;
  
  s_assert_param(IS_SFUNCTIONAL_STATE(xNewState));
  
  S2LPSpiReadRegisters(XO_RCO_CONF1_ADDR, 1, &tmp);
  
  if(xNewState == S_ENABLE) {
    tmp &= ~PD_CLKDIV_REGMASK;
  } else {
    tmp |= PD_CLKDIV_REGMASK;
  }
  g_xStatus = S2LPSpiWriteRegisters(XO_RCO_CONF1_ADDR, 1, &tmp);
}


   
                                   
                                                                                              
  
SFunctionalState S2LPRadioGetDigDiv(void)
{
  uint8_t tmp;
  
  g_xStatus = S2LPSpiReadRegisters(XO_RCO_CONF1_ADDR, 1, &tmp);
  
  if(tmp & PD_CLKDIV_REGMASK) {
    return S_DISABLE;
  } else {
    return S_ENABLE;
  }
}


   
                                                                 
                                                             
                                                          
               
  
void S2LPRadioSetChannelSpace(uint32_t lChannelSpace)
{
  uint8_t tmp;
  tmp = S2LPRadioComputeChannelSpacingRegValue(lChannelSpace);
  g_xStatus = S2LPSpiWriteRegisters(CH_SPACE_ADDR, 1, &tmp);
}


   
                                            
               
                                                                                                      
                                                                   
  
uint32_t S2LPRadioGetChannelSpace(void)
{
  uint8_t tmp;
  g_xStatus = S2LPSpiReadRegisters(CH_SPACE_ADDR, 1, &tmp);
  return S2LPRadioComputeChannelSpacing(tmp);
}


   
                                                                                                      
                                                             
                                                                                 
                                                                             
                                                                    
  
uint8_t S2LPRadioSetFrequencyBase(uint32_t lFBase)
{
  uint32_t tmp32;
  uint8_t tmpBuffer[4], cp_isel, bs = 1, pfd_split, tmp, cRefDiv;
  
  s_assert_param(IS_FREQUENCY_BAND(lFBase));
  
  tmp32 = S2LPRadioComputeSynthWord(lFBase, ((uint8_t)S2LPRadioGetRefDiv()+1));
  
  if(IS_FREQUENCY_BAND_HIGH(lFBase)) {
    bs = 0;
  }
  
  cRefDiv = (uint8_t)S2LPRadioGetRefDiv() + 1;

                                                                          
  S2LPRadioSearchWCP(&cp_isel, &pfd_split, lFBase, cRefDiv);
  
  S2LPSpiReadRegisters(SYNTH_CONFIG2_ADDR, 1, &tmp);
  tmp &= ~PLL_PFD_SPLIT_EN_REGMASK;
  tmp |= (pfd_split<<2);
  S2LPSpiWriteRegisters(SYNTH_CONFIG2_ADDR, 1, &tmp);
    
                                                               
  tmpBuffer[0] = (((uint8_t)(tmp32>>24)) & SYNT_27_24_REGMASK) | cp_isel<<5 | (bs<<4) ;
  tmpBuffer[1] = (uint8_t)(tmp32>>16);
  tmpBuffer[2] = (uint8_t)(tmp32>>8);
  tmpBuffer[3] = (uint8_t)tmp32;
  
  g_xStatus = S2LPSpiWriteRegisters(SYNT3_ADDR, 4, tmpBuffer);
  
  return 0;
}


   
                                            
               
                                                                           
  
uint32_t S2LPRadioGetFrequencyBase(void)
{
  uint8_t tmpBuffer[4];
  uint32_t tmp32;
  uint8_t cRefDiv, band;
    
                                 
  g_xStatus = S2LPSpiReadRegisters(SYNT3_ADDR, 4, tmpBuffer);  
  
                                                                
  if(tmpBuffer[0] & BS_REGMASK) {
    band = MIDDLE_BAND_FACTOR;
  }
  else {
    band = HIGH_BAND_FACTOR;
  }
  cRefDiv = (uint8_t)S2LPRadioGetRefDiv() + 1;
  
                               
  tmp32 = (((uint32_t)(tmpBuffer[0] & SYNT_27_24_REGMASK))<<24) | (((uint32_t)tmpBuffer[1])<<16) | (((uint32_t)tmpBuffer[2])<<8) | ((uint32_t)tmpBuffer[3]);
  
                                                   
  return S2LPRadioComputeFrequencyBase(tmp32, band, cRefDiv);
}


   
                           
                                                                               
                       
               
  
void S2LPRadioSetDatarate(uint32_t lDatarate)
{
  uint8_t dr_e, tmpBuffer[3];
  uint16_t dr_m;
  
  if(s_lXtalFrequency>DIG_DOMAIN_XTAL_THRESH) {
    s_assert_param(IS_DATARATE(lDatarate,s_lXtalFrequency/2));
  }
  else {    
    s_assert_param(IS_DATARATE(lDatarate,s_lXtalFrequency));
  }  
  
                                                     
  S2LPRadioSearchDatarateME(lDatarate, &dr_m, &dr_e);
  
                               
  S2LPSpiReadRegisters(MOD4_ADDR, 3, tmpBuffer);
  
                                                           
  tmpBuffer[0] = (uint8_t)(dr_m>>8);
  tmpBuffer[1] = (uint8_t)dr_m;
  tmpBuffer[2] &= ~DATARATE_E_REGMASK;
  tmpBuffer[2] |= dr_e;
  
                                     
  g_xStatus = S2LPSpiWriteRegisters(MOD4_ADDR, 3, tmpBuffer);
  
}


   
                              
               
                                                     
  
uint32_t S2LPRadioGetDatarate(void)
{
  uint8_t tmpBuffer[3], dr_e;
  uint16_t dr_m;
  
  g_xStatus = S2LPSpiReadRegisters(MOD4_ADDR, 3, tmpBuffer);
  dr_m = (((uint16_t)tmpBuffer[0])<<8) | ((uint16_t)tmpBuffer[1]);
  dr_e = tmpBuffer[2]&DATARATE_E_REGMASK;

  return S2LPRadioComputeDatarate(dr_m, dr_e);
}


   
                                      
                                                                            
                                                                   
               
  
void S2LPRadioSetFrequencyDev(uint32_t lFDev)
{
  uint8_t uFDevM, uFDevE, tmpBuffer[2];
  
  s_assert_param(IS_F_DEV(lFDev, s_lXtalFrequency));
  
                                                                
  S2LPRadioSearchFreqDevME(lFDev, &uFDevM, &uFDevE);
  
  S2LPSpiReadRegisters(MOD1_ADDR, 2, tmpBuffer);
  tmpBuffer[0] &= ~FDEV_E_REGMASK;
  tmpBuffer[0] |= uFDevE;
  tmpBuffer[1] = uFDevM;
  g_xStatus = S2LPSpiWriteRegisters(MOD1_ADDR, 2, tmpBuffer);
}


   
                                         
               
                                                             
                                                                           
  
uint32_t S2LPRadioGetFrequencyDev(void)
{
  uint8_t tmpBuffer[2], uFDevE, tmp, refdiv, cBs = HIGH_BAND_FACTOR;  

  refdiv = (uint8_t)S2LPRadioGetRefDiv() + 1;
  g_xStatus = S2LPSpiReadRegisters(SYNT3_ADDR, 1, &tmp);
  if((tmp&BS_REGMASK) == 0) {
    cBs = MIDDLE_BAND_FACTOR;
  }
  
                                                                        
  S2LPSpiReadRegisters(MOD1_ADDR, 2, tmpBuffer);
  uFDevE = tmpBuffer[0] & FDEV_E_REGMASK;
  
                                                        
  return S2LPRadioComputeFreqDeviation(tmpBuffer[1], uFDevE, cBs, refdiv);
}


   
                                           
                                                                                                                 
                                                                                             
                                                                                         
                                                                                                                        
                                                                
               
  
void S2LPRadioSetChannelBW(uint32_t lBandwidth)
{
  uint8_t uBwM, uBwE, tmpBuffer;
  
                                                                       
  if(s_lXtalFrequency>DIG_DOMAIN_XTAL_THRESH) {
    s_assert_param(IS_CH_BW(lBandwidth,(s_lXtalFrequency>>1)));
  }
  else {
    s_assert_param(IS_CH_BW(lBandwidth,(s_lXtalFrequency)));
  } 
  
                                                              
  S2LPRadioSearchChannelBwME(lBandwidth, &uBwM, &uBwE);
  tmpBuffer = (uBwM<<4)|(uBwE);
  
                                          
  g_xStatus = S2LPSpiWriteRegisters(CHFLT_ADDR, 1, &tmpBuffer);
  
}

   
                                              
               
                                                            
  
uint32_t S2LPRadioGetChannelBW(void)
{
  uint8_t tmpBuffer, uBwM, uBwE;
  
                                                                   
  g_xStatus = S2LPSpiReadRegisters(CHFLT_ADDR, 1, &tmpBuffer);
  uBwM = (tmpBuffer&0xF0)>>4;
  uBwE = tmpBuffer&0x0F;
  
  return S2LPRadioComputeChannelFilterBw(uBwM, uBwE);
  
}


   
                                  
                                        
                                                                 
               
  
void S2LPRadioSetModulation(ModulationSelect xModulation)
{
  uint8_t tmpBuffer;
  s_assert_param(IS_MODULATION(xModulation));
  
  S2LPSpiReadRegisters(MOD2_ADDR, 1, &tmpBuffer);
  tmpBuffer &= ~MOD_TYPE_REGMASK;
  tmpBuffer |= xModulation;
  g_xStatus = S2LPSpiWriteRegisters(MOD2_ADDR, 1, &tmpBuffer);
}


   
                                          
               
                                                   
  
ModulationSelect S2LPRadioGetModulation(void)
{
  uint8_t tmpBuffer;
  
  g_xStatus = S2LPSpiReadRegisters(MOD2_ADDR, 1, &tmpBuffer);
  return (ModulationSelect)(tmpBuffer&MOD_TYPE_REGMASK);
  
}


   
                                 
                                                              
                                  
               
  
void S2LPRadioSetXtalFrequency(uint32_t lXtalFrequency)
{
  s_lXtalFrequency = lXtalFrequency; 
}


   
                                    
               
                                  
  
uint32_t S2LPRadioGetXtalFrequency(void)
{
  return s_lXtalFrequency; 
}


   
                                                                                
                                                                                   
               
  
void S2LPRadioSetMaxPALevel(SFunctionalState xNewState)
{
  uint8_t tmp;
  
  S2LPSpiReadRegisters(PA_POWER0_ADDR, 1, &tmp);
  
  if(xNewState == S_ENABLE) {
    tmp |= PA_MAXDBM_REGMASK;
  } else {
    tmp &= ~PA_MAXDBM_REGMASK;
  }
  
  g_xStatus = S2LPSpiWriteRegisters(PA_POWER0_ADDR, 1, &tmp);
}


   
                                                                       
                                                                             
                                                                                           
                                                              
               
                                                                                       
                    
  
void S2LPRadioSetPALeveldBm(uint8_t cIndex, int32_t lPowerdBm)
{
  uint8_t address, paLevelValue;
  s_assert_param(IS_PA_MAX_INDEX(cIndex));
  s_assert_param(IS_PAPOWER_DBM(lPowerdBm));
  
  if(lPowerdBm> 14)
  {
    paLevelValue = 1;
  }
  else {
    paLevelValue = (uint8_t)((int32_t)29-2*lPowerdBm);
  }
  
  address = PA_POWER8_ADDR + 7 - cIndex;
  
  g_xStatus = S2LPSpiWriteRegisters(address, 1, &paLevelValue);
}


   
                                                                         
                                                                             
                                                               
                                                                
                                              
                                                                                       
                    
  
int32_t S2LPRadioGetPALeveldBm(uint8_t cIndex)
{
  uint8_t address, paLevelValue;
  s_assert_param(IS_PA_MAX_INDEX(cIndex));
  
  address = PA_POWER8_ADDR + 7 - cIndex;
  
  g_xStatus = S2LPSpiReadRegisters(address, 1, &paLevelValue);

  return ((int32_t)29-paLevelValue)/2;
}


   
                                             
                                                                                       
              
  
void S2LPRadioSetPALevelMaxIndex(uint8_t cIndex)
{
  uint8_t tmp;
  s_assert_param(IS_PA_MAX_INDEX(cIndex));
  
  S2LPSpiReadRegisters(PA_POWER0_ADDR, 1, &tmp);
  tmp &= (~PA_LEVEL_MAX_IDX_REGMASK);
  tmp |= cIndex;
  g_xStatus = S2LPSpiWriteRegisters(PA_POWER0_ADDR, 1, &tmp);
}


   
                                                
               
                                                                                       
  
uint8_t S2LPRadioGetPALevelMaxIndex(void)
{
  uint8_t tmp;
  g_xStatus = S2LPSpiReadRegisters(PA_POWER0_ADDR, 1, &tmp);
  return (tmp & PA_LEVEL_MAX_IDX_REGMASK);
}



   
                                   
                   
                                       
                                               
                                          
                     
                                             
               
  
void S2LPRadioSetAutoRampingMode(SFunctionalState xNewState)
{
  uint8_t tmpBuffer[2];
  
  S2LPSpiReadRegisters(PA_POWER0_ADDR, 2, tmpBuffer);
  
  if(xNewState == S_ENABLE) {
    tmpBuffer[0] &= ~PA_MAXDBM_REGMASK;
    tmpBuffer[0] &= ~PA_RAMP_EN_REGMASK;
    tmpBuffer[1] |= FIR_EN_REGMASK;
  } else {
    tmpBuffer[1] &= ~FIR_EN_REGMASK;
  }
  
  g_xStatus = S2LPSpiWriteRegisters(PA_POWER0_ADDR, 2, tmpBuffer);
}



   
                                      
                                       
                                              
                                           
                     
                                                
               
  
void S2LPRadioSetManualRampingMode(SFunctionalState xNewState)
{
  uint8_t tmpBuffer[2];
  
  S2LPSpiReadRegisters(PA_POWER0_ADDR, 2, tmpBuffer);
  
  if(xNewState == S_ENABLE) {
    tmpBuffer[0] &= ~PA_MAXDBM_REGMASK;
    tmpBuffer[0] |= PA_RAMP_EN_REGMASK;
    tmpBuffer[1] &= ~FIR_EN_REGMASK;
  } else {
    tmpBuffer[0] &= ~PA_RAMP_EN_REGMASK;
  }
  
  g_xStatus = S2LPSpiWriteRegisters(PA_POWER0_ADDR, 2, tmpBuffer);
}


   
                                                                    
                                                                                          
                                                                                          
               
  
void S2LPRadioCalibrationVco(SFunctionalState xAmplitudeCalibration, SFunctionalState xFrequencyCalibration)
{
  uint8_t tmp;  
  s_assert_param(IS_SFUNCTIONAL_STATE(xAmplitudeCalibration));
  s_assert_param(IS_SFUNCTIONAL_STATE(xFrequencyCalibration));
  
  S2LPSpiReadRegisters(VCO_CONFIG_ADDR, 1, &tmp);
  
  if(xAmplitudeCalibration == S_ENABLE) {
    tmp |= VCO_CALAMP_EXT_SEL_REGMASK;
  } else {
    tmp &= ~VCO_CALAMP_EXT_SEL_REGMASK;
  }
  
  if(xFrequencyCalibration == S_ENABLE) {
    tmp |= VCO_CALFREQ_EXT_SEL_REGMASK;
  } else {
    tmp &= ~VCO_CALFREQ_EXT_SEL_REGMASK;
  }
  g_xStatus = S2LPSpiWriteRegisters(VCO_CONFIG_ADDR, 1, &tmp);
}

   
                                                     
                                                        
               
  
void S2LPRadioSetTxCalibVcoAmpWord(uint8_t value)
{
  value <<= 4;  
  g_xStatus = S2LPSpiWriteRegisters(VCO_CALIBR_IN2_ADDR, 1, &value);
}

   
                                                     
                                                        
               
  
void S2LPRadioSetRxCalibVcoAmpWord(uint8_t value)
{
  value &= VCO_CALAMP_RX_REGMASK;  
  g_xStatus = S2LPSpiWriteRegisters(VCO_CALIBR_IN2_ADDR, 1, &value);
}

   
                                                      
                                                        
               
  
void S2LPRadioSetTxCalibVcoFreqWord(uint8_t value)
{
  g_xStatus = S2LPSpiWriteRegisters(VCO_CALIBR_IN1_ADDR, 1, &value);
}

   
                                                      
                                                        
               
  
void S2LPRadioSetRxCalibVcoFreqWord(uint8_t value)
{
  g_xStatus = S2LPSpiWriteRegisters(VCO_CALIBR_IN0_ADDR, 1, &value);
}


   
                                                                      
                                                                                           
               
  
void S2LPRadioAfcInit(SAfcInit* xSAfcInit)
{
  uint8_t tmpBuffer[3];
  s_assert_param(IS_SFUNCTIONAL_STATE(xSAfcInit->xAfcEnable));
  s_assert_param(IS_SFUNCTIONAL_STATE(xSAfcInit->xAfcFreezeOnSync));
  s_assert_param(IS_AFC_MODE(xSAfcInit->xAfcMode));
  s_assert_param(IS_AFC_GAIN(xSAfcInit->cAfcFastGain));
  s_assert_param(IS_AFC_GAIN(xSAfcInit->cAfcSlowGain));
  
                                           
  S2LPSpiReadRegisters(AFC2_ADDR, 1, &tmpBuffer[0]);
  
                                                   
  if(xSAfcInit->xAfcEnable == S_ENABLE) {
    tmpBuffer[0] |= AFC_ENABLED_REGMASK;
  }
  else {
    tmpBuffer[0] &= ~AFC_ENABLED_REGMASK;
  }
  
                                                          
  if(xSAfcInit->xAfcFreezeOnSync == S_ENABLE) {
    tmpBuffer[0] |= AFC_FREEZE_ON_SYNC_REGMASK;
  }
  else {
    tmpBuffer[0] &= ~AFC_FREEZE_ON_SYNC_REGMASK;
  }
  
                                                          
  if(xSAfcInit->xAfcMode == AFC_MODE_LOOP_CLOSED_ON_SLICER) {
    tmpBuffer[0] &= ~AFC_MODE_REGMASK;
  }
  else {
    tmpBuffer[0] |= AFC_MODE_REGMASK;
  }
  
  tmpBuffer[1] = xSAfcInit->cAfcFastPeriod;  
  tmpBuffer[2] = (xSAfcInit->cAfcFastGain<<4) | xSAfcInit->cAfcSlowGain;
  
  g_xStatus = S2LPSpiWriteRegisters(AFC2_ADDR, 3, tmpBuffer);
}


   
                                                                                             
                                                                                      
               
  
void S2LPRadioGetAfcInfo(SAfcInit* xSAfcInit)
{
  uint8_t tmpBuffer[3];

  S2LPSpiReadRegisters(AFC2_ADDR, 3, tmpBuffer);
  
  xSAfcInit->xAfcFreezeOnSync = (SFunctionalState)((tmpBuffer[0]&AFC_FREEZE_ON_SYNC_REGMASK)>>7);
  xSAfcInit->xAfcEnable = (SFunctionalState)((tmpBuffer[0]&AFC_ENABLED_REGMASK)>>6);
  xSAfcInit->xAfcMode = (SAfcMode)(tmpBuffer[0]&AFC_MODE_REGMASK);
  
  xSAfcInit->cAfcFastPeriod = tmpBuffer[1];
  xSAfcInit->cAfcFastGain = (tmpBuffer[2] & AFC_FAST_GAIN_REGMASK)>>4;
  xSAfcInit->cAfcSlowGain = (tmpBuffer[2] & AFC_SLOW_GAIN_REGMASK);
  
}


   
                                
                                                                
               
  
void S2LPRadioSetIsiEqualizationMode(SIsiEqu xSIsiMode)
{
  uint8_t tmp;
  s_assert_param(IS_ISI_EQU(xSIsiMode));
  
  S2LPSpiReadRegisters(ANT_SELECT_CONF_ADDR, 1, &tmp);
  tmp &= ~EQU_CTRL_REGMASK;
  tmp |= (((uint8_t)xSIsiMode)<<5);
  g_xStatus = S2LPSpiWriteRegisters(ANT_SELECT_CONF_ADDR, 1, &tmp);
}


   
                                     
               
                                                                
  
SIsiEqu S2LPRadioGetIsiEqualizationMode(void)
{
  uint8_t tmp;
  
  g_xStatus = S2LPSpiReadRegisters(ANT_SELECT_CONF_ADDR, 1, &tmp);
  return (SIsiEqu)((tmp&EQU_CTRL_REGMASK)>>5);
  
}


   
                                      
                                                                                                     
               
  
void S2LPRadioSymClkRecoverInit(SSymClkRecInit* xSSymClkRecInit)
{
  uint8_t tmpBuffer[2] = {0x00, 0x00};
  s_assert_param(IS_CLKREC_MODE(xSSymClkRecInit->xSClkRecMode));
  s_assert_param(IS_SFUNCTIONAL_STATE(xSSymClkRecInit->cClkRec16SymPostFlt));
  s_assert_param(IS_CLKREC_I_GAIN(xSSymClkRecInit->cClkRecIGainFast));
  s_assert_param(IS_CLKREC_I_GAIN(xSSymClkRecInit->cClkRecIGainSlow));
  s_assert_param(IS_CLKREC_P_GAIN(xSSymClkRecInit->cClkRecPGainFast));
  s_assert_param(IS_CLKREC_P_GAIN(xSSymClkRecInit->cClkRecPGainSlow));
  
                                                   
  if(xSSymClkRecInit->xSClkRecMode == CLKREC_PLL_MODE) {
    tmpBuffer[0] |= CLK_REC_ALGO_SEL_REGMASK;
  }
  tmpBuffer[0] |= xSSymClkRecInit->cClkRecIGainSlow;
  tmpBuffer[0] |= (xSSymClkRecInit->cClkRecPGainSlow<<5);
  
                                                   
  if(xSSymClkRecInit->cClkRec16SymPostFlt == S_ENABLE) {
    tmpBuffer[1] |= PSTFLT_LEN_REGMASK;
  }
  tmpBuffer[1] |= xSSymClkRecInit->cClkRecIGainFast;
  tmpBuffer[1] |= (xSSymClkRecInit->cClkRecPGainFast<<5);
  
  g_xStatus = S2LPSpiWriteRegisters(CLOCKREC1_ADDR, 2, tmpBuffer);
}


   
                                                 
                                                                                                                         
               
  
void S2LPRadioGetSymClkRecoverInfo(SSymClkRecInit* xSSymClkRecInit)
{
  uint8_t tmpBuffer[2];

  S2LPSpiReadRegisters(CLOCKREC1_ADDR, 2, tmpBuffer);
  
  xSSymClkRecInit->xSClkRecMode = (SClkRecMode)((tmpBuffer[0]&CLK_REC_ALGO_SEL_REGMASK)>>4);
  xSSymClkRecInit->cClkRecIGainSlow = tmpBuffer[0]&CLK_REC_I_GAIN_SLOW_REGMASK;
  xSSymClkRecInit->cClkRecPGainSlow = (tmpBuffer[0]&CLK_REC_P_GAIN_SLOW_REGMASK)>>5;
    
  xSSymClkRecInit->cClkRec16SymPostFlt = (SFunctionalState)((tmpBuffer[0]&CLK_REC_ALGO_SEL_REGMASK)>>4);
  xSSymClkRecInit->cClkRecIGainFast = tmpBuffer[0]&CLK_REC_I_GAIN_FAST_REGMASK;
  xSSymClkRecInit->cClkRecPGainFast = (tmpBuffer[0]&CLK_REC_P_GAIN_FAST_REGMASK)>>5;
  
}



   
    
  


   
    
  


   
    
  



/******************* (C) COPYRIGHT 2016 STMicroelectronics *****END OF FILE****/

