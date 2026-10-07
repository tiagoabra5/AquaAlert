/**
 * @file    S2LP_Types.c
 * @author  LowPower RF BU - AMG
 * @version 1.3.0
 * @date    10-July-2017
 * @brief   This file provides functions to manage S2-LP debug.
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

                                                                                
#include "S2LP_Types.h"
#include "S2LP_Regs.h"
#include "MCU_Interface.h"


                              
     
   


                          
     
   


                                                                               
     
   


   
     
   



                                                                     
     
   


   
     
   



                                                                     
     
   


   
     
   



                                                                         
     
   

   
                                       
                                                                                           
                                             
   
volatile S2LPStatus g_xStatus;

   
     
   



                                                                                     
     
   



   
     
   



                                                                             
     
   

#ifdef  S2LP_USE_FULL_ASSERT
   
                                                                         
                                                     
                                               
                                                     
                 
   
void s_assert_failed(uint8_t* file, uint32_t line)
{
                                                                                   
  printf("Wrong parameters value: file %s on line %d\r\n", file, line);

                     
  while (1)
  {
  }
}
#endif


   
                                                                                          
                                                 
               
               
   
void S2LPRefreshStatus(void)
{
  uint8_t tempRegValue;
  do
  {
                                                              
    g_xStatus = S2LPSpiReadRegisters(MC_STATE0_ADDR, 1, &tempRegValue);
  }
  while((tempRegValue>>1)!=g_xStatus.MC_STATE);  
}

   
     
   



   
     
   



   
     
   



/******************* (C) COPYRIGHT 2016 STMicroelectronics *****END OF FILE****/
