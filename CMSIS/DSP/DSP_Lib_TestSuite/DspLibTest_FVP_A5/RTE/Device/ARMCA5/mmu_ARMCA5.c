                                                                               
                         
                                                              
                   
                              
  
        
  
                                                                                
/*
 * Copyright (c) 2009-2018 Arm Limited. All rights reserved.
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed under the Apache License, Version 2.0 (the License); you may
 * not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an AS IS BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

                                                                                            

                                                                
                                                                
                                                                 
                                                                
                                                            
                                                                
                                                             
                                       
                                       
                                       
                                       
                                                                
                                                             
                                                                
                                                             
                                                                
                                                             
                                                                
                                                             
                                                                
                                                             
                                                                
                                                             
                                                                
                                                             
                                                                
                                                             
                                                                
                                                             
                                                                
                                                             
                                                                
                                                               
                                                                
                                                            
                                       
                                                                
                                                            
                                       
                                                                
                                                                
                                                                
                                                            
                                       
                                                                
                                                                     
                                                            
                                       
  

                                                                                    
                                        
                                
                                     
                                      

                                                         
                                                                                                                                                                     
                                                                                                                                                                                                         
                                                                                                                                   

                                                                                                                                                                 
                                                                                            
                                                                                        


                                         
                                                                                                                   
                                                                                                                     
                                      
                                                 

#include "ARMCA5.h"


                    
                                          
#define PRIVATE_TABLE_L2_BASE_4k       (0x80504000)                               
#define SYNC_FLAGS_TABLE_L2_BASE_4k    (0x80504C00)                              
#define PERIPHERAL_A_TABLE_L2_BASE_64k (0x80504400)                                                 
#define PERIPHERAL_B_TABLE_L2_BASE_64k (0x80504800)                                                 

                                                       
#define PERIPHERAL_A_FAULT (0x00000000 + 0x1c000000)                             
#define PERIPHERAL_B_FAULT (0x00100000 + 0x1c000000)                             

                                                       
#define FLAG_SYNC     0xFFFFF000
#define F_SYNC_BASE   0xFFF00000              

                            
extern uint32_t Image$$VECTORS$$Base;
extern uint32_t Image$$RW_DATA$$Base;
extern uint32_t Image$$ZI_DATA$$Base;
extern uint32_t Image$$TTB$$ZI$$Base;

static uint32_t Sect_Normal;                                                                                
static uint32_t Sect_Normal_Cod;                                                                            
static uint32_t Sect_Normal_RO;                                          
static uint32_t Sect_Normal_RW;                                                        
static uint32_t Sect_Device_RO;                                                                    
static uint32_t Sect_Device_RW;                                    

                               
static uint32_t Page_L1_4k  = 0x0;           
static uint32_t Page_L1_64k = 0x0;           
static uint32_t Page_4k_Device_RW;                                               
static uint32_t Page_64k_Device_RW;                                              

void MMU_CreateTranslationTable(void)
{
    mmu_region_attributes_Type region;

                                    
    MMU_TTSection (&Image$$TTB$$ZI$$Base, 0, 4096, DESCRIPTOR_FAULT);

      
                                                                                   
      
       
                                                         
    section_normal(Sect_Normal, region);
    section_normal_cod(Sect_Normal_Cod, region);
    section_normal_ro(Sect_Normal_RO, region);
    section_normal_rw(Sect_Normal_RW, region);
                                        
    section_device_ro(Sect_Device_RO, region);
    section_device_rw(Sect_Device_RW, region);
                                      
    page64k_device_rw(Page_L1_64k, Page_64k_Device_RW, region);
                                     
    page4k_device_rw(Page_L1_4k, Page_4k_Device_RW, region);


      
                                                  
      
       

                  
    MMU_TTSection (&Image$$TTB$$ZI$$Base, (uint32_t)&Image$$VECTORS$$Base, 2, Sect_Normal_Cod);
    MMU_TTSection (&Image$$TTB$$ZI$$Base, (uint32_t)&Image$$RW_DATA$$Base, 1, Sect_Normal_RW);
    MMU_TTSection (&Image$$TTB$$ZI$$Base, (uint32_t)&Image$$ZI_DATA$$Base, 1, Sect_Normal_RW);

                                                                                                      
    MMU_TTSection (&Image$$TTB$$ZI$$Base, (uint32_t)&Image$$TTB$$ZI$$Base, 2043, Sect_Normal);

                                                           
    MMU_TTSection (&Image$$TTB$$ZI$$Base, VE_A5_MP_FLASH_BASE0    , 64, Sect_Device_RO);
    MMU_TTSection (&Image$$TTB$$ZI$$Base, VE_A5_MP_FLASH_BASE1    , 64, Sect_Device_RO);
    MMU_TTSection (&Image$$TTB$$ZI$$Base, VE_A5_MP_SRAM_BASE      , 64, Sect_Device_RW);
    MMU_TTSection (&Image$$TTB$$ZI$$Base, VE_A5_MP_VRAM_BASE      , 32, Sect_Device_RW);
    MMU_TTSection (&Image$$TTB$$ZI$$Base, VE_A5_MP_ETHERNET_BASE  , 16, Sect_Device_RW);
    MMU_TTSection (&Image$$TTB$$ZI$$Base, VE_A5_MP_USB_BASE       , 16, Sect_Device_RW);

                                                                                             
    MMU_TTPage64k(&Image$$TTB$$ZI$$Base, PERIPHERAL_A_FAULT      , 16, Page_L1_64k, (uint32_t *)PERIPHERAL_A_TABLE_L2_BASE_64k, DESCRIPTOR_FAULT);
                                                    
    MMU_TTPage64k(&Image$$TTB$$ZI$$Base, VE_A5_MP_DAP_BASE       ,  1, Page_L1_64k, (uint32_t *)PERIPHERAL_A_TABLE_L2_BASE_64k, Page_64k_Device_RW);
    MMU_TTPage64k(&Image$$TTB$$ZI$$Base, VE_A5_MP_SYSTEM_REG_BASE,  1, Page_L1_64k, (uint32_t *)PERIPHERAL_A_TABLE_L2_BASE_64k, Page_64k_Device_RW);
    MMU_TTPage64k(&Image$$TTB$$ZI$$Base, VE_A5_MP_SERIAL_BASE    ,  1, Page_L1_64k, (uint32_t *)PERIPHERAL_A_TABLE_L2_BASE_64k, Page_64k_Device_RW);
    MMU_TTPage64k(&Image$$TTB$$ZI$$Base, VE_A5_MP_AACI_BASE      ,  1, Page_L1_64k, (uint32_t *)PERIPHERAL_A_TABLE_L2_BASE_64k, Page_64k_Device_RW);
    MMU_TTPage64k(&Image$$TTB$$ZI$$Base, VE_A5_MP_MMCI_BASE      ,  1, Page_L1_64k, (uint32_t *)PERIPHERAL_A_TABLE_L2_BASE_64k, Page_64k_Device_RW);
    MMU_TTPage64k(&Image$$TTB$$ZI$$Base, VE_A5_MP_KMI0_BASE      ,  2, Page_L1_64k, (uint32_t *)PERIPHERAL_A_TABLE_L2_BASE_64k, Page_64k_Device_RW);
    MMU_TTPage64k(&Image$$TTB$$ZI$$Base, VE_A5_MP_UART_BASE      ,  4, Page_L1_64k, (uint32_t *)PERIPHERAL_A_TABLE_L2_BASE_64k, Page_64k_Device_RW);
    MMU_TTPage64k(&Image$$TTB$$ZI$$Base, VE_A5_MP_WDT_BASE       ,  1, Page_L1_64k, (uint32_t *)PERIPHERAL_A_TABLE_L2_BASE_64k, Page_64k_Device_RW);

                                                                                             
    MMU_TTPage64k(&Image$$TTB$$ZI$$Base, PERIPHERAL_B_FAULT      , 16, Page_L1_64k, (uint32_t *)PERIPHERAL_B_TABLE_L2_BASE_64k, DESCRIPTOR_FAULT);
                                                    
    MMU_TTPage64k(&Image$$TTB$$ZI$$Base, VE_A5_MP_TIMER_BASE     ,  2, Page_L1_64k, (uint32_t *)PERIPHERAL_B_TABLE_L2_BASE_64k, Page_64k_Device_RW);
    MMU_TTPage64k(&Image$$TTB$$ZI$$Base, VE_A5_MP_DVI_BASE       ,  1, Page_L1_64k, (uint32_t *)PERIPHERAL_B_TABLE_L2_BASE_64k, Page_64k_Device_RW);
    MMU_TTPage64k(&Image$$TTB$$ZI$$Base, VE_A5_MP_RTC_BASE       ,  1, Page_L1_64k, (uint32_t *)PERIPHERAL_B_TABLE_L2_BASE_64k, Page_64k_Device_RW);
    MMU_TTPage64k(&Image$$TTB$$ZI$$Base, VE_A5_MP_UART4_BASE     ,  1, Page_L1_64k, (uint32_t *)PERIPHERAL_B_TABLE_L2_BASE_64k, Page_64k_Device_RW);
    MMU_TTPage64k(&Image$$TTB$$ZI$$Base, VE_A5_MP_CLCD_BASE      ,  1, Page_L1_64k, (uint32_t *)PERIPHERAL_B_TABLE_L2_BASE_64k, Page_64k_Device_RW);

                                                                                                                 
    MMU_TTPage4k (&Image$$TTB$$ZI$$Base, __get_CBAR()            ,256,  Page_L1_4k, (uint32_t *)PRIVATE_TABLE_L2_BASE_4k, DESCRIPTOR_FAULT);
                                          
    MMU_TTPage4k (&Image$$TTB$$ZI$$Base, __get_CBAR()            ,  3,  Page_L1_4k, (uint32_t *)PRIVATE_TABLE_L2_BASE_4k, Page_4k_Device_RW);
                                                        
                                                                                                                                                   

                                                                                                                                     
    MMU_TTPage4k (&Image$$TTB$$ZI$$Base, F_SYNC_BASE , 256, Page_L1_4k, (uint32_t *)SYNC_FLAGS_TABLE_L2_BASE_4k, DESCRIPTOR_FAULT);
                                          
    MMU_TTPage4k (&Image$$TTB$$ZI$$Base, FLAG_SYNC   ,   1, Page_L1_4k, (uint32_t *)SYNC_FLAGS_TABLE_L2_BASE_4k, Page_4k_Device_RW);

                                         
                                                                                    
                 
                                        
                                       
                                        
                                                   
                                       
                                           
    __set_TTBR0(((uint32_t)&Image$$TTB$$ZI$$Base) | 0x48);
    __ISB();

                                            
                                                                   
                                                       
    __set_DACR(1);
    __ISB();
}
