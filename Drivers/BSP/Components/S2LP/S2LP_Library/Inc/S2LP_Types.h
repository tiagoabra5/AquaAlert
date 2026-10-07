/**
 * @file    S2LP_Types.h
 * @author  LowPower RF BU - AMG
 * @version 1.3.0
 * @date    April 12, 2017
 * @brief   Header file for S2-LP types.
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
 * This module provide some types definitions which will be used in
 * all the modules of this library. Here is defined also the global
 * variable @ref g_xStatus which contains the status of S2-LP and
 * is updated every time an SPI transaction occurs.
 *
 *
 * <h2><center>&copy; COPYRIGHT 2019 STMicroelectronics</center></h2>
 */


                                                                                
#ifndef __S2LP_GENERICTYPES_H
#define __S2LP_GENERICTYPES_H


                                                                                

                                           
#include <stdint.h>
#include <stdio.h>



#ifdef __cplusplus
 extern "C" {
#endif


   
                             
     
   


   
                                   
                                           
                                                                     
     
   

   
                                                            
     
   

   
                                                                              
   
typedef enum {
  S_DISABLE = 0,
  S_ENABLE = !S_DISABLE
} SFunctionalState;


   
                                                                 
   
typedef enum {
  S_RESET = 0,
  S_SET = !S_RESET
} SFlagStatus;


   
                                    
   
typedef enum {
  S_FALSE = 0,
  S_TRUE  = !S_FALSE
} SBool;


   
                                   
   
typedef enum {
  MC_STATE_READY             =0x00,               
  MC_STATE_SLEEP_NOFIFO      =0x01,                                 
  MC_STATE_STANDBY           =0x02,                 
  MC_STATE_SLEEP             =0x03,               
  MC_STATE_LOCKON            =0x0C,                
  MC_STATE_RX                =0x30,            
  MC_STATE_LOCK_ST           =0x14,                 
  MC_STATE_TX                =0x5C,            
  MC_STATE_SYNTH_SETUP       =0x50                      
} S2LPState;


   
                                                                              
                                                                                        
                                                                                       
                                   
                                                                                              
                                                                                     
                                                                                         
                                                                              
   
typedef struct {
  uint8_t XO_ON:1;                                        
  S2LPState MC_STATE: 7;                                                                    
  uint8_t ERROR_LOCK: 1;                                  
  uint8_t RX_FIFO_EMPTY: 1;                          
  uint8_t TX_FIFO_FULL: 1;                          
  uint8_t ANT_SELECT: 1;                                       
  uint8_t RCCAL_OK: 1;                                          
  uint8_t : 3;                                                                    
}S2LPStatus;


   
     
   


   
                                                                
     
   


   
     
   

   
                                                                
     
   

extern volatile S2LPStatus g_xStatus;

   
     
   

   
                                                                     
     
   

#define IS_SFUNCTIONAL_STATE(STATE)   (STATE == S_DISABLE || STATE == S_ENABLE)
#define IS_SFLAG_STATUS(STATUS)   (STATUS == S_RESET || STATUS == S_SET)
#define IS_SBOOL(STATUS)   (STATUS == S_FALSE || STATUS == S_TRUE)

#define S_ABS(a) ((a)>0?(a):-(a))

   
     
   


   
                                                                
     
   

#ifdef  S2LP_USE_FULL_ASSERT
    
                                                                              
                                                                                 
                                                                               
                                                               
                 
     
  #define s_assert_param(expr) ((expr) ? (void)0 : s_assert_failed((uint8_t *)__FILE__, __LINE__))
  void s_assert_failed(uint8_t* file, uint32_t line);
#elif  S2LP_USE_VCOM_ASSERT
     
                                                                              
                                                                                  
                                                                               
                                                               
                 
     
  #define s_assert_param(expr) ((expr) ? (void)0 : s_assert_failed((uint8_t *)__FILE__, __LINE__,#expr))
  void s_assert_failed(uint8_t* file, uint32_t line, char* expression);
#else
  #define s_assert_param(expr)        {}
#endif

   
    
   

   
     
   


   
     
   


#ifdef __cplusplus
}
#endif

#endif

/******************* (C) COPYRIGHT 2016 STMicroelectronics *****END OF FILE****/
