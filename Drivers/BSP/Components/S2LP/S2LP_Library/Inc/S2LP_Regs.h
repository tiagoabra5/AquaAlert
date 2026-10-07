/**
 * @file S2LP_Regs.h
 * @author  LowPower RF BU - AMG
 * @version 1.3.0
 * @date    10-July-2017
 * @brief This file  contains all the registers address and masks.
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



   
                             
        
                 
                      
                                                                      
                
                                                                                                                   
           
   
#define GPIO0_CONF_ADDR			((uint8_t)0x00)

#define GPIO_SELECT_REGMASK			((uint8_t)0xF8)
#define GPIO_MODE_REGMASK			((uint8_t)0x03)


   
                             
        
                 
                      
                                                                              
                
                                                                                                                   
           
   
#define GPIO1_CONF_ADDR			((uint8_t)0x01)

#define GPIO_SELECT_REGMASK			((uint8_t)0xF8)
#define GPIO_MODE_REGMASK			((uint8_t)0x03)


   
                             
        
                 
                      
                                                                              
                
                                                                                                                   
           
   
#define GPIO2_CONF_ADDR			((uint8_t)0x02)

#define GPIO_SELECT_REGMASK			((uint8_t)0xF8)
#define GPIO_MODE_REGMASK			((uint8_t)0x03)


   
                             
        
                 
                      
                                                                              
                
                                                                                                                                 
           
   
#define GPIO3_CONF_ADDR			((uint8_t)0x03)

#define GPIO_SELECT_REGMASK			((uint8_t)0xF8)
#define GPIO_MODE_REGMASK			((uint8_t)0x03)


   
                              
        
                 
                      
                                                                                                                                  
                                                                                                                                                                                                                          
                                                
                                                                  
           
   
#define MCU_CK_CONF_ADDR			((uint8_t)0x04)

#define EN_MCU_CLK_REGMASK			((uint8_t)0x80)
#define CLOCK_TAIL_REGMASK			((uint8_t)0x60)
#define XO_RATIO_REGMASK			((uint8_t)0x1E)
#define RCO_RATIO_REGMASK			((uint8_t)0x01)


   
                        
        
                 
                      
                                                                                
                                                                                                                                                                                               
                                                            
           
   
#define SYNT3_ADDR			((uint8_t)0x05)

#define PLL_CP_ISEL_REGMASK			((uint8_t)0xE0)
#define BS_REGMASK			((uint8_t)0x10)
#define SYNT_27_24_REGMASK			((uint8_t)0x0F)


   
                        
        
                 
                      
                                                                      
           
   
#define SYNT2_ADDR			((uint8_t)0x06)

#define SYNT_23_16_REGMASK			((uint8_t)0xFF)


   
                        
        
                 
                      
                                                                     
           
   
#define SYNT1_ADDR			((uint8_t)0x07)

#define SYNT_15_8_REGMASK			((uint8_t)0xFF)


   
                        
        
                 
                      
                                                           
           
   
#define SYNT0_ADDR			((uint8_t)0x08)

#define SYNT_7_0_REGMASK			((uint8_t)0xFF)


   
                                
        
                 
                      
                                                                                                     
           
   
#define IF_OFFSET_ANA_ADDR			((uint8_t)0x09)

#define IF_OFFSET_ANA_REGMASK			((uint8_t)0xFF)


   
                                
        
                 
                      
                                                                                                                  
           
   
#define IF_OFFSET_DIG_ADDR			((uint8_t)0x0A)

#define IF_OFFSET_DIG_REGMASK			((uint8_t)0xFF)


   
                           
        
                 
                      
                                                                                        
           
   
#define CH_SPACE_ADDR			((uint8_t)0x0C)

#define CH_SPACE_REGMASK			((uint8_t)0xFF)


   
                        
        
                 
                      
                                                                                                                                                                       
           
   
#define CHNUM_ADDR			((uint8_t)0x0D)

#define CH_NUM_REGMASK			((uint8_t)0xFF)


   
                       
        
                 
                      
                                                                                                    
           
   
#define MOD4_ADDR			((uint8_t)0x0E)

#define DATARATE_M_15_8_REGMASK			((uint8_t)0xFF)


   
                       
        
                 
                      
                                                                                                   
           
   
#define MOD3_ADDR			((uint8_t)0x0F)

#define DATARATE_M_7_0_REGMASK			((uint8_t)0xFF)


   
                       
        
                 
                      
                                                                                                                                                               
                                                                                   
           
   
#define MOD2_ADDR			((uint8_t)0x10)

#define MOD_TYPE_REGMASK			((uint8_t)0xF0)
#define DATARATE_E_REGMASK			((uint8_t)0x0F)


   
                       
        
                 
                      
                                                   
                                                    
                                                                
                                                                                      
           
   
#define MOD1_ADDR			((uint8_t)0x11)

#define PA_INTERP_EN_REGMASK			((uint8_t)0x80)
#define MOD_INTERP_EN_REGMASK			((uint8_t)0x40)
#define G4FSK_CONST_MAP_REGMASK			((uint8_t)0x30)
#define FDEV_E_REGMASK			((uint8_t)0x0F)


   
                       
        
                 
                      
                                                                                      
           
   
#define MOD0_ADDR			((uint8_t)0x12)

#define FDEV_M_REGMASK			((uint8_t)0xFF)


   
                        
        
                 
                      
                                                                                   
                                                                                   
           
   
#define CHFLT_ADDR			((uint8_t)0x13)

#define CHFLT_M_REGMASK			((uint8_t)0xF0)
#define CHFLT_E_REGMASK			((uint8_t)0x0F)


   
                       
        
                 
                      
                                                                                      
                                               
                                                                                                               
                  
           
   
#define AFC2_ADDR			((uint8_t)0x14)

#define AFC_FREEZE_ON_SYNC_REGMASK			((uint8_t)0x80)
#define AFC_ENABLED_REGMASK			((uint8_t)0x40)
#define AFC_MODE_REGMASK			((uint8_t)0x20)


   
                       
        
                 
                      
                                                          
           
   
#define AFC1_ADDR			((uint8_t)0x15)

#define AFC_FAST_PERIOD_REGMASK			((uint8_t)0xFF)


   
                       
        
                 
                      
                                                               
                                                               
           
   
#define AFC0_ADDR			((uint8_t)0x16)

#define AFC_FAST_GAIN_REGMASK			((uint8_t)0xF0)
#define AFC_SLOW_GAIN_REGMASK			((uint8_t)0x0F)


   
                           
        
                 
                      
                                         
                                                                                                                                                                                              
                  
           
   
#define RSSI_FLT_ADDR			((uint8_t)0x17)

#define RSSI_FLT_REGMASK			((uint8_t)0xF0)
#define CS_MODE_REGMASK			((uint8_t)0x0C)


   
                          
        
                 
                      
                                                                                              
           
   
#define RSSI_TH_ADDR			((uint8_t)0x18)

#define RSSI_TH_REGMASK			((uint8_t)0xFF)


   
                                  
        
                 
                      
                
                                                                                                                                     
                                                                                
                                                
                                              
           
   
#define ANT_SELECT_CONF_ADDR			((uint8_t)0x1F)

#define EQU_CTRL_REGMASK			((uint8_t)0x60)
#define CS_BLANKING_REGMASK			((uint8_t)0x10)
#define AS_ENABLE_REGMASK			((uint8_t)0x08)
#define AS_MEAS_TIME_REGMASK			((uint8_t)0x07)


   
                            
        
                 
                      
                                                                 
                                                                                   
                                                                                                  
           
   
#define CLOCKREC1_ADDR			((uint8_t)0x20)

#define CLK_REC_P_GAIN_SLOW_REGMASK			((uint8_t)0xE0)
#define CLK_REC_ALGO_SEL_REGMASK			((uint8_t)0x10)
#define CLK_REC_I_GAIN_SLOW_REGMASK			((uint8_t)0x0F)


   
                            
        
                 
                      
                                                                 
                                                                            
                                                                                                   
           
   
#define CLOCKREC0_ADDR			((uint8_t)0x21)

#define CLK_REC_P_GAIN_FAST_REGMASK			((uint8_t)0xE0)
#define PSTFLT_LEN_REGMASK			((uint8_t)0x10)
#define CLK_REC_I_GAIN_FAST_REGMASK			((uint8_t)0x0F)


   
                            
        
                 
                      
                                                                          
                                                                                            
           
   
#define PCKTCTRL6_ADDR			((uint8_t)0x2B)

#define SYNC_LEN_REGMASK			((uint8_t)0xFC)
#define PREAMBLE_LEN_9_8_REGMASK			((uint8_t)0x03)


   
                            
        
                 
                      
                                                                                             
           
   
#define PCKTCTRL5_ADDR			((uint8_t)0x2C)

#define PREAMBLE_LEN_7_0_REGMASK			((uint8_t)0xFF)


   
                            
        
                 
                      
                                                                                   
                  
                                                             
                  
           
   
#define PCKTCTRL4_ADDR			((uint8_t)0x2D)

#define LEN_WID_REGMASK			((uint8_t)0x80)
#define ADDRESS_LEN_REGMASK			((uint8_t)0x08)


   
                            
        
                 
                      
                                                                     
                                                                                           
                                                          
                                                                  
                                                                       
           
   
#define PCKTCTRL3_ADDR			((uint8_t)0x2E)

#define PCKT_FRMT_REGMASK			((uint8_t)0xC0)
#define RX_MODE_REGMASK			((uint8_t)0x30)
#define FSK4_SYM_SWAP_REGMASK			((uint8_t)0x08)
#define BYTE_SWAP_REGMASK			((uint8_t)0x04)
#define PREAMBLE_SEL_REGMASK			((uint8_t)0x03)


   
                            
        
                 
                      
                  
                                                               
                                                                            
                                                               
                                                              
                                                               
                                                                                                                                            
           
   
#define PCKTCTRL2_ADDR			((uint8_t)0x2F)

#define FCS_TYPE_4G_REGMASK			((uint8_t)0x20)
#define FEC_TYPE_4G_REGMASK			((uint8_t)0x10)
#define INT_EN_4G_REGMASK			((uint8_t)0x08)
#define MBUS_3OF6_EN_REGMASK			((uint8_t)0x04)
#define MANCHESTER_EN_REGMASK			((uint8_t)0x02)
#define FIX_VAR_LEN_REGMASK			((uint8_t)0x01)


   
                            
        
                 
                      
                                                                                                                                                         
                                           
                                                                                                            
                                                                                                                                                          
                                                                            
           
   
#define PCKTCTRL1_ADDR			((uint8_t)0x30)

#define CRC_MODE_REGMASK			((uint8_t)0xE0)
#define WHIT_EN_REGMASK			((uint8_t)0x10)
#define TXSOURCE_REGMASK			((uint8_t)0x0C)
#define SECOND_SYNC_SEL_REGMASK			((uint8_t)0x02)
#define FEC_EN_REGMASK			((uint8_t)0x01)


   
                           
        
                 
                      
                                                  
           
   
#define PCKTLEN1_ADDR			((uint8_t)0x31)

#define PCKTLEN1_REGMASK			((uint8_t)0xFF)


   
                           
        
                 
                      
                                                  
           
   
#define PCKTLEN0_ADDR			((uint8_t)0x32)

#define PCKTLEN0_REGMASK			((uint8_t)0xFF)


   
                        
        
                 
                      
                               
           
   
#define SYNC3_ADDR			((uint8_t)0x33)

#define SYNC3_REGMASK			((uint8_t)0xFF)


   
                        
        
                 
                      
                               
           
   
#define SYNC2_ADDR			((uint8_t)0x34)

#define SYNC2_REGMASK			((uint8_t)0xFF)


   
                        
        
                 
                      
                               
           
   
#define SYNC1_ADDR			((uint8_t)0x35)

#define SYNC1_REGMASK			((uint8_t)0xFF)


   
                        
        
                 
                      
                               
           
   
#define SYNC0_ADDR			((uint8_t)0x36)

#define SYNC0_REGMASK			((uint8_t)0xFF)


   
                     
        
                 
                      
                             
                             
                                     
           
   
#define QI_ADDR			((uint8_t)0x37)

#define SQI_TH_REGMASK			((uint8_t)0xE0)
#define PQI_TH_REGMASK			((uint8_t)0x1E)
#define SQI_EN_REGMASK			((uint8_t)0x01)


   
                              
        
                 
                      
                                                    
           
   
#define PCKT_PSTMBL_ADDR			((uint8_t)0x38)

#define PCKT_PSTMBL_REGMASK			((uint8_t)0xFF)


   
                            
        
                 
                      
                                                                              
                                                                                
                                                                                
                                                                                                                  
                                                                                                                                      
                                                                                               
           
   
#define PROTOCOL2_ADDR			((uint8_t)0x39)

#define CS_TIMEOUT_MASK_REGMASK			((uint8_t)0x80)
#define SQI_TIMEOUT_MASK_REGMASK			((uint8_t)0x40)
#define PQI_TIMEOUT_MASK_REGMASK			((uint8_t)0x20)
#define TX_SEQ_NUM_RELOAD_REGMASK			((uint8_t)0x18)
#define FIFO_GPIO_OUT_MUX_SEL_REGMASK			((uint8_t)0x04)
#define LDC_TIMER_MULT_REGMASK			((uint8_t)0x03)


   
                            
        
                 
                      
                                                 
                                                             
                                              
                                                   
                                                                                                                            
                                                    
                                                                          
                                                                     
           
   
#define PROTOCOL1_ADDR			((uint8_t)0x3A)

#define LDC_MODE_REGMASK			((uint8_t)0x80)
#define LDC_RELOAD_ON_SYNC_REGMASK			((uint8_t)0x40)
#define PIGGYBACKING_REGMASK			((uint8_t)0x20)
#define FAST_CS_TERM_EN_REGMASK			((uint8_t)0x10)
#define SEED_RELOAD_REGMASK			((uint8_t)0x08)
#define CSMA_ON_REGMASK			((uint8_t)0x04)
#define CSMA_PERS_ON_REGMASK			((uint8_t)0x02)
#define AUTO_PCKT_FLT_REGMASK			((uint8_t)0x01)


   
                            
        
                 
                      
                                                                                           
                                                      
                                                                                  
                                               
                
           
   
#define PROTOCOL0_ADDR			((uint8_t)0x3B)

#define NMAX_RETX_REGMASK			((uint8_t)0xF0)
#define NACK_TX_REGMASK			((uint8_t)0x08)
#define AUTO_ACK_REGMASK			((uint8_t)0x04)
#define PERS_RX_REGMASK			((uint8_t)0x02)


   
                               
        
                 
                      
                
                                                       
           
   
#define FIFO_CONFIG3_ADDR			((uint8_t)0x3C)

#define RX_AFTHR_REGMASK			((uint8_t)0x7F)


   
                               
        
                 
                      
                
                                                        
           
   
#define FIFO_CONFIG2_ADDR			((uint8_t)0x3D)

#define RX_AETHR_REGMASK			((uint8_t)0x7F)


   
                               
        
                 
                      
                
                                                       
           
   
#define FIFO_CONFIG1_ADDR			((uint8_t)0x3E)

#define TX_AFTHR_REGMASK			((uint8_t)0x7F)


   
                               
        
                 
                      
                
                                                        
           
   
#define FIFO_CONFIG0_ADDR			((uint8_t)0x3F)

#define TX_AETHR_REGMASK			((uint8_t)0x7F)


   
                                   
        
                 
                      
                
                                                                                                 
                
                                                                                                    
                                                                                                            
                                                                                                                   
                                                                                                                
                                                      
           
   
#define PCKT_FLT_OPTIONS_ADDR			((uint8_t)0x40)

#define RX_TIMEOUT_AND_OR_SEL_REGMASK			((uint8_t)0x40)
#define SOURCE_ADDR_FLT_REGMASK			((uint8_t)0x10)
#define DEST_VS_BROADCAST_ADDR_REGMASK			((uint8_t)0x08)
#define DEST_VS_MULTICAST_ADDR_REGMASK			((uint8_t)0x04)
#define DEST_VS_SOURCE_ADDR_REGMASK			((uint8_t)0x02)
#define CRC_FLT_REGMASK			((uint8_t)0x01)


   
                                  
        
                 
                      
                                                                                                                                          
           
   
#define PCKT_FLT_GOALS4_ADDR			((uint8_t)0x41)

#define RX_SOURCE_MASK_DUAL_SYNC3_REGMASK			((uint8_t)0xFF)


   
                                  
        
                 
                      
                                                                                                                                               
           
   
#define PCKT_FLT_GOALS3_ADDR			((uint8_t)0x42)

#define RX_SOURCE_ADDR_DUAL_SYNC2_REGMASK			((uint8_t)0xFF)


   
                                  
        
                 
                      
                                                                                                       
           
   
#define PCKT_FLT_GOALS2_ADDR			((uint8_t)0x43)

#define BROADCAST_ADDR_DUAL_SYNC1_REGMASK			((uint8_t)0xFF)


   
                                  
        
                 
                      
                                                                                                       
           
   
#define PCKT_FLT_GOALS1_ADDR			((uint8_t)0x44)

#define MULTICAST_ADDR_DUAL_SYNC0_REGMASK			((uint8_t)0xFF)


   
                                  
        
                 
                      
                                                                       
           
   
#define PCKT_FLT_GOALS0_ADDR			((uint8_t)0x45)

#define TX_SOURCE_ADDR_REGMASK			((uint8_t)0xFF)


   
                          
        
                 
                      
                                           
           
   
#define TIMERS5_ADDR			((uint8_t)0x46)

#define RX_TIMER_CNTR_REGMASK			((uint8_t)0xFF)


   
                          
        
                 
                      
                                              
           
   
#define TIMERS4_ADDR			((uint8_t)0x47)

#define RX_TIMER_PRESC_REGMASK			((uint8_t)0xFF)


   
                          
        
                 
                      
                                                    
           
   
#define TIMERS3_ADDR			((uint8_t)0x48)

#define LDC_TIMER_PRESC_REGMASK			((uint8_t)0xFF)


   
                          
        
                 
                      
                                                 
           
   
#define TIMERS2_ADDR			((uint8_t)0x49)

#define LDC_TIMER_CNTR_REGMASK			((uint8_t)0xFF)


   
                          
        
                 
                      
                                                                              
           
   
#define TIMERS1_ADDR			((uint8_t)0x4A)

#define LDC_RELOAD_PRSC_REGMASK			((uint8_t)0xFF)


   
                          
        
                 
                      
                                                                            
           
   
#define TIMERS0_ADDR			((uint8_t)0x4B)

#define LDC_RELOAD_CNTR_REGMASK			((uint8_t)0xFF)


   
                             
        
                 
                      
                                                                                                          
           
   
#define CSMA_CONF3_ADDR			((uint8_t)0x4C)

#define BU_CNTR_SEED_14_8_REGMASK			((uint8_t)0xFF)


   
                             
        
                 
                      
                                                                                                         
           
   
#define CSMA_CONF2_ADDR			((uint8_t)0x4D)

#define BU_CNTR_SEED_7_0_REGMASK			((uint8_t)0xFF)


   
                             
        
                 
                      
                                                         
                                                 
           
   
#define CSMA_CONF1_ADDR			((uint8_t)0x4E)

#define BU_PRSC_REGMASK			((uint8_t)0xFC)
#define CCA_PERIOD_REGMASK			((uint8_t)0x03)


   
                             
        
                 
                      
                                                                              
                
                                                   
           
   
#define CSMA_CONF0_ADDR			((uint8_t)0x4F)

#define CCA_LEN_REGMASK			((uint8_t)0xF0)
#define NBACKOFF_MAX_REGMASK			((uint8_t)0x07)


   
                            
        
                 
                      
                                                                                            
           
   
#define IRQ_MASK3_ADDR			((uint8_t)0x50)

#define INT_MASK_31_24_REGMASK			((uint8_t)0xFF)


   
                            
        
                 
                      
                                                                                            
           
   
#define IRQ_MASK2_ADDR			((uint8_t)0x51)

#define INT_MASK_23_16_REGMASK			((uint8_t)0xFF)


   
                            
        
                 
                      
                                                                                           
           
   
#define IRQ_MASK1_ADDR			((uint8_t)0x52)

#define INT_MASK_15_8_REGMASK			((uint8_t)0xFF)


   
                            
        
                 
                      
                                                                                          
           
   
#define IRQ_MASK0_ADDR			((uint8_t)0x53)

#define INT_MASK_7_0_REGMASK			((uint8_t)0xFF)


   
                                
        
                 
                      
                                                                                              
                                           
           
   
#define FAST_RX_TIMER_ADDR			((uint8_t)0x54)

#define RSSI_SETTLING_LIMIT			((uint8_t)0xFF)


   
                            
        
                 
                      
                
                                                  
           
   
#define PA_POWER8_ADDR			((uint8_t)0x5A)

#define PA_LEVEL8_REGMASK			((uint8_t)0x7F)


   
                            
        
                 
                      
                
                                                   
           
   
#define PA_POWER7_ADDR			((uint8_t)0x5B)

#define PA_LEVEL_7_REGMASK			((uint8_t)0x7F)


   
                            
        
                 
                      
                
                                                   
           
   
#define PA_POWER6_ADDR			((uint8_t)0x5C)

#define PA_LEVEL_6_REGMASK			((uint8_t)0x7F)


   
                            
        
                 
                      
                
                                                   
           
   
#define PA_POWER5_ADDR			((uint8_t)0x5D)

#define PA_LEVEL_5_REGMASK			((uint8_t)0x7F)


   
                            
        
                 
                      
                
                                                   
           
   
#define PA_POWER4_ADDR			((uint8_t)0x5E)

#define PA_LEVEL_4_REGMASK			((uint8_t)0x7F)


   
                            
        
                 
                      
                
                                                   
           
   
#define PA_POWER3_ADDR			((uint8_t)0x5F)

#define PA_LEVEL_3_REGMASK			((uint8_t)0x7F)


   
                            
        
                 
                      
                
                                                   
           
   
#define PA_POWER2_ADDR			((uint8_t)0x60)

#define PA_LEVEL_2_REGMASK			((uint8_t)0x7F)


   
                            
        
                 
                      
                
                                                   
           
   
#define PA_POWER1_ADDR			((uint8_t)0x61)

#define PA_LEVEL_1_REGMASK			((uint8_t)0x7F)


   
                            
        
                 
                      
                                                                                                          
                                                                 
                                            
                                                                      
                                                                                      
           
   
#define PA_POWER0_ADDR			((uint8_t)0x62)

#define DIG_SMOOTH_EN_REGMASK			((uint8_t)0x80)
#define PA_MAXDBM_REGMASK			((uint8_t)0x40)
#define PA_RAMP_EN_REGMASK			((uint8_t)0x20)
#define PA_RAMP_STEP_LEN_REGMASK			((uint8_t)0x18)
#define PA_LEVEL_MAX_IDX_REGMASK			((uint8_t)0x07)


   
                             
        
                 
                      
                  
                                                                            
                                                                                 
                           
                
           
   
#define PA_CONFIG1_ADDR			((uint8_t)0x63)

#define LIN_NLOG_REGMASK			((uint8_t)0x10)
#define FIR_CFG_REGMASK			((uint8_t)0xC0)
#define FIR_EN_REGMASK			((uint8_t)0x02)


   
                                
        
                 
                      
                
                
                
                  
                                                                                              
                  
           
   
#define SYNTH_CONFIG2_ADDR			((uint8_t)0x65)

#define PLL_PFD_SPLIT_EN_REGMASK			((uint8_t)0x04)


   
                             
        
                 
                      
                  
                                                                                                                 
                                                                                                                  
                
                  
           
   
#define VCO_CONFIG_ADDR			((uint8_t)0x68)

#define VCO_CALAMP_EXT_SEL_REGMASK			((uint8_t)0x20)
#define VCO_CALFREQ_EXT_SEL_REGMASK			((uint8_t)0x20)


   
                                 
        
                 
                      
                                                                                                                                
                                                                                                                                
           
   
#define VCO_CALIBR_IN2_ADDR			((uint8_t)0x69)

#define VCO_CALAMP_TX_REGMASK			((uint8_t)0xF0)
#define VCO_CALAMP_RX_REGMASK			((uint8_t)0x0F)


   
                                 
        
                 
                      
                
                                                                             
           
   
#define VCO_CALIBR_IN1_ADDR			((uint8_t)0x6A)

#define VCO_CALFREQ_TX_REGMASK			((uint8_t)0x7F)


   
                                 
        
                 
                      
                
                                                                             
           
   
#define VCO_CALIBR_IN0_ADDR			((uint8_t)0x6B)

#define VCO_CALFREQ_RX_REGMASK			((uint8_t)0x7F)


   
                               
        
                 
                      
                  
                
                                                                                                             
                  
                  
           
   
#define XO_RCO_CONF1_ADDR			((uint8_t)0x6C)

#define PD_CLKDIV_REGMASK			((uint8_t)0x10)


   
                               
        
                 
                      
                                                                                    
                                                        
                                                       
                
                                                                        
                                                              
           
   
#define XO_RCO_CONF0_ADDR			((uint8_t)0x6D)

#define EXT_REF_REGMASK			((uint8_t)0x80)
#define GM_CONF_REGMASK			((uint8_t)0x70)
#define REFDIV_REGMASK			((uint8_t)0x08)
#define EXT_RCO_OSC_REGMASK			((uint8_t)0x02)
#define RCO_CALIBRATION_REGMASK			((uint8_t)0x01)


   
                                   
        
                 
                      
                                          
                                                      
           
   
#define RCO_CALIBR_CONF3_ADDR			((uint8_t)0x6E)

#define RWT_IN_REGMASK			((uint8_t)0xF0)
#define RFB_IN_4_1_REGMASK			((uint8_t)0x0F)


   
                                   
        
                 
                      
                                                   
                  
                  
                
                  
           
   
#define RCO_CALIBR_CONF2_ADDR			((uint8_t)0x6F)

#define RFB_IN_0_REGMASK			((uint8_t)0x80)


   
                           
        
                 
                      
                                                      
                                                                               
                                            
                
                
                
                  
           
   
#define PM_CONF4_ADDR			((uint8_t)0x75)

#define TEMP_SENSOR_EN_REGMASK			((uint8_t)0x80)
#define TEMP_SENS_BUFF_EN_REGMASK			((uint8_t)0x40)
#define EXT_SMPS_REGMASK			((uint8_t)0x20)


   
                           
        
                 
                      
                                                                                                                                                             
                                                                                          
           
   
#define PM_CONF3_ADDR			((uint8_t)0x76)

#define KRM_EN_REGMASK			((uint8_t)0x80)
#define KRM_14_8_REGMASK			((uint8_t)0x7F)


   
                           
        
                 
                      
                                                                                          
           
   
#define PM_CONF2_ADDR			((uint8_t)0x77)

#define KRM_7_0_REGMASK			((uint8_t)0xFF)


   
                           
        
                 
                      
                
                                                              
                                                                                     
                
                
                
                
           
   
#define PM_CONF1_ADDR			((uint8_t)0x78)

#define BATTERY_LVL_EN_REGMASK			((uint8_t)0x40)
#define SET_BLD_TH_REGMASK			((uint8_t)0x30)


   
                           
        
                 
                      
                
                                                                                                                                                                                                                                                                                    
                  
                
                                                                                   
           
   
#define PM_CONF0_ADDR			((uint8_t)0x79)

#define SET_SMPS_LVL_REGMASK			((uint8_t)0x70)
#define SLEEP_MODE_SEL_REGMASK			((uint8_t)0x01)


   
                            
        
            
                      
                  
                                                        
                                         
                                      
                                        
                                         
           
   
#define MC_STATE1_ADDR			((uint8_t)0x8D)

#define RCO_CAL_OK_REGMASK			((uint8_t)0x10)
#define ANT_SEL_REGMASK			((uint8_t)0x08)
#define TX_FIFO_FULL_REGMASK			((uint8_t)0x04)
#define RX_FIFO_EMPTY_REGMASK			((uint8_t)0x02)
#define ERROR_LOCK_REGMASK			((uint8_t)0x01)


   
                            
        
            
                      
                            
                               
           
   
#define MC_STATE0_ADDR			((uint8_t)0x8E)

#define STATE_REGMASK			((uint8_t)0xFE)
#define XO_ON_REGMASK			((uint8_t)0x01)


   
                                 
        
            
                      
                
                                                   
           
   
#define TX_FIFO_STATUS_ADDR			((uint8_t)0x8F)

#define NELEM_TXFIFO_REGMASK			((uint8_t)0x7F)


   
                                 
        
            
                      
                
                                                   
           
   
#define RX_FIFO_STATUS_ADDR			((uint8_t)0x90)

#define NELEM_RXFIFO_REGMASK			((uint8_t)0x7F)


   
                                  
        
            
                      
                                                      
                                                                
           
   
#define RCO_CALIBR_OUT4_ADDR			((uint8_t)0x94)

#define RWT_OUT_REGMASK			((uint8_t)0xF0)
#define RFB_OUT_4_1_REGMASK			((uint8_t)0x0F)


   
                                  
        
            
                      
                                                             
                  
           
   
#define RCO_CALIBR_OUT3_ADDR			((uint8_t)0x95)

#define RFB_OUT_0_REGMASK			((uint8_t)0x80)


   
                                  
        
            
                      
                  
                                                                                                                            
           
   
#define VCO_CALIBR_OUT1_ADDR			((uint8_t)0x99)

#define VCO_CAL_AMP_OUT_REGMASK			((uint8_t)0x0F)


   
                                  
        
            
                      
                
                                                                                                                                   
           
   
#define VCO_CALIBR_OUT0_ADDR			((uint8_t)0x9A)

#define VCO_CAL_FREQ_OUT_REGMASK			((uint8_t)0x7F)


   
                               
        
            
                      
                  
                                                     
                                                                      
           
   
#define TX_PCKT_INFO_ADDR			((uint8_t)0x9C)

#define TX_SEQ_NUM_REGMASK			((uint8_t)0x30)
#define N_RETX_REGMASK			((uint8_t)0x0F)


   
                               
        
            
                      
                  
                                                
                                                          
           
   
#define RX_PCKT_INFO_ADDR			((uint8_t)0x9D)

#define NACK_RX_REGMASK			((uint8_t)0x04)
#define RX_SEQ_NUM_REGMASK			((uint8_t)0x03)


   
                           
        
            
                      
                                     
           
   
#define AFC_CORR_ADDR			((uint8_t)0x9E)

#define AFC_CORR_REGMASK			((uint8_t)0xFF)


   
                               
        
            
                      
                                             
           
   
#define LINK_QUALIF2_ADDR			((uint8_t)0x9F)

#define PQI_REGMASK			((uint8_t)0xFF)


   
                               
        
            
                      
                                  
                                            
           
   
#define LINK_QUALIF1_ADDR			((uint8_t)0xA0)

#define CS_REGMASK			((uint8_t)0x80)
#define SQI_REGMASK			((uint8_t)0x7F)


   
                             
        
            
                      
                                                                                                    
           
   
#define RSSI_LEVEL_ADDR			((uint8_t)0xA2)

#define RSSI_LEVEL_REGMASK			((uint8_t)0xFF)


   
                               
        
            
                      
                                                                        
           
   
#define RX_PCKT_LEN1_ADDR			((uint8_t)0xA4)

#define RX_PCKT_LEN_14_8_REGMASK			((uint8_t)0xFF)


   
                               
        
            
                      
                                                                       
           
   
#define RX_PCKT_LEN0_ADDR			((uint8_t)0xA5)

#define RX_PCKT_LEN_7_0_REGMASK			((uint8_t)0xFF)


   
                             
        
            
                      
                                                      
           
   
#define CRC_FIELD3_ADDR			((uint8_t)0xA6)

#define CRC_FIELD3_REGMASK			((uint8_t)0xFF)


   
                             
        
            
                      
                                                      
           
   
#define CRC_FIELD2_ADDR			((uint8_t)0xA7)

#define CRC_FIELD2_REGMASK			((uint8_t)0xFF)


   
                             
        
            
                      
                                                      
           
   
#define CRC_FIELD1_ADDR			((uint8_t)0xA8)

#define CRC_FIELD1_REGMASK			((uint8_t)0xFF)


   
                             
        
            
                      
                                                      
           
   
#define CRC_FIELD0_ADDR			((uint8_t)0xA9)

#define CRC_FIELD0_REGMASK			((uint8_t)0xFF)


   
                                  
        
            
                      
                                                                    
           
   
#define RX_ADDRE_FIELD1_ADDR			((uint8_t)0xAA)

#define RX_ADDRE_FIELD1_REGMASK			((uint8_t)0xFF)


   
                                  
        
            
                      
                                                                         
           
   
#define RX_ADDRE_FIELD0_ADDR			((uint8_t)0xAB)

#define RX_ADDRE_FIELD0_REGMASK			((uint8_t)0xFF)


   
                                 
        
            
                      
                                                                                                    
           
   
#define RSSI_LEVEL_RUN_ADDR			((uint8_t)0xEF)

#define RSSI_LEVEL_RUN_REGMASK			((uint8_t)0xFF)


   
                               
        
            
                      
                                 
           
   
#define DEVICE_INFO1_ADDR			((uint8_t)0xF0)

#define PARTNUM_REGMASK			((uint8_t)0xFF)


   
                               
        
            
                      
                                       
           
   
#define DEVICE_INFO0_ADDR			((uint8_t)0xF1)

#define RSSI_LEVEL_REGMASK			((uint8_t)0xFF)


   
                              
        
            
                      
                                                    
           
   
#define IRQ_STATUS3_ADDR			((uint8_t)0xFA)

#define INT_LEVEL_31_24_REGMASK			((uint8_t)0xFF)


   
                              
        
            
                      
                                                    
           
   
#define IRQ_STATUS2_ADDR			((uint8_t)0xFB)

#define INT_LEVEL_23_16_REGMASK			((uint8_t)0xFF)


   
                              
        
            
                      
                                                   
           
   
#define IRQ_STATUS1_ADDR			((uint8_t)0xFC)

#define INT_LEVEL_15_8_REGMASK			((uint8_t)0xFF)


   
                              
        
            
                      
                                                  
           
   
#define IRQ_STATUS0_ADDR			((uint8_t)0xFD)

#define INT_LEVEL_7_0_REGMASK			((uint8_t)0xFF)


/******************* (C) COPYRIGHT 2015 STMicroelectronics *****END OF FILE****/
