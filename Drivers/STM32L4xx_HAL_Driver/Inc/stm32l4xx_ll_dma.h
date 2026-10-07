/**
  ******************************************************************************
  * @file    stm32l4xx_ll_dma.h
  * @author  MCD Application Team
  * @brief   Header file of DMA LL module.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2017 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */

                                                                                
#ifndef STM32L4xx_LL_DMA_H
#define STM32L4xx_LL_DMA_H

#ifdef __cplusplus
extern "C" {
#endif

                                                                                
#include "stm32l4xx.h"
#if defined(DMAMUX1)
#include "stm32l4xx_ll_dmamux.h"
#endif              

                                   
      
    

#if defined (DMA1) || defined (DMA2)

                        
      
    

                                                                                
                                                                                
                                                            
      
    
                                                                                             
static const uint8_t CHANNEL_OFFSET_TAB[] =
{
  (uint8_t)(DMA1_Channel1_BASE - DMA1_BASE),
  (uint8_t)(DMA1_Channel2_BASE - DMA1_BASE),
  (uint8_t)(DMA1_Channel3_BASE - DMA1_BASE),
  (uint8_t)(DMA1_Channel4_BASE - DMA1_BASE),
  (uint8_t)(DMA1_Channel5_BASE - DMA1_BASE),
  (uint8_t)(DMA1_Channel6_BASE - DMA1_BASE),
  (uint8_t)(DMA1_Channel7_BASE - DMA1_BASE),
};
   
      
    

                                                                                
#if defined(DMAMUX1)
#else
                                                            
      
    
                                              
#define DMA_CSELR_OFFSET                  (uint32_t)(DMA1_CSELR_BASE - DMA1_BASE)

                                                                           
#define DMA_POSITION_CSELR_CXS            POSITION_VAL(DMA_CSELR_C1S << (Channel*4U))
   
      
    
#endif              
                                                                                
#if defined(DMAMUX1)

                                                      
      
    
   
                                                                         
                                                                    
                                                                     
                                 
                                                   
    
#define __LL_DMA_INSTANCE_TO_DMAMUX_CHANNEL(__DMA_INSTANCE__)   \
  (((uint32_t)(__DMA_INSTANCE__) == ((uint32_t)DMA1)) ? 0 : LL_DMA_CHANNEL_7)
   
      
    
#else
#if defined(USE_FULL_LL_DRIVER)
                                                      
      
    
   
      
    
#endif                       
#endif              
                                                                                
#if defined(USE_FULL_LL_DRIVER)
                                                        
      
    
typedef struct
{
  uint32_t PeriphOrM2MSrcAddress;                                                             
                                                                                                                 

                                                                                                                         

  uint32_t MemoryOrM2MDstAddress;                                                         
                                                                                                                      

                                                                                                                         

  uint32_t Direction;                                                                                       
                                                                                           
                                                                                                 

                                                                                                                                                 

  uint32_t Mode;                                                                        
                                                                                            
                                                                                                              
                                                                                                            

                                                                                                                                

  uint32_t PeriphOrM2MSrcIncMode;                                                                                                                
                                                              
                                                                                              

                                                                                                                                         

  uint32_t MemoryOrM2MDstIncMode;                                                                                                                 
                                                              
                                                                                              

                                                                                                                                         

  uint32_t PeriphOrM2MSrcDataSize;                                                                                                        
                                                                                       
                                                                                                  

                                                                                                                                      

  uint32_t MemoryOrM2MDstDataSize;                                                                                                         
                                                                                       
                                                                                                  

                                                                                                                                      

  uint32_t NbData;                                                                             
                                                                                                                       
                                                                                                     
                                                                                                                     

                                                                                                                                      

#if defined(DMAMUX1)
  uint32_t PeriphRequest;                                                
                                                                                                  

                                                                                                                                         
#else
  uint32_t PeriphRequest;                                                
                                                                                               

                                                                                                                                         
#endif              

  uint32_t Priority;                                                         
                                                                                                

                                                                                                                                                

} LL_DMA_InitTypeDef;
   
      
    
#endif                       

                                                                                
                                                              
      
    
                                                      
                                                                           
      
    
#define LL_DMA_IFCR_CGIF1                 DMA_IFCR_CGIF1                                                
#define LL_DMA_IFCR_CTCIF1                DMA_IFCR_CTCIF1                                               
#define LL_DMA_IFCR_CHTIF1                DMA_IFCR_CHTIF1                                               
#define LL_DMA_IFCR_CTEIF1                DMA_IFCR_CTEIF1                                               
#define LL_DMA_IFCR_CGIF2                 DMA_IFCR_CGIF2                                                
#define LL_DMA_IFCR_CTCIF2                DMA_IFCR_CTCIF2                                               
#define LL_DMA_IFCR_CHTIF2                DMA_IFCR_CHTIF2                                               
#define LL_DMA_IFCR_CTEIF2                DMA_IFCR_CTEIF2                                               
#define LL_DMA_IFCR_CGIF3                 DMA_IFCR_CGIF3                                                
#define LL_DMA_IFCR_CTCIF3                DMA_IFCR_CTCIF3                                               
#define LL_DMA_IFCR_CHTIF3                DMA_IFCR_CHTIF3                                               
#define LL_DMA_IFCR_CTEIF3                DMA_IFCR_CTEIF3                                               
#define LL_DMA_IFCR_CGIF4                 DMA_IFCR_CGIF4                                                
#define LL_DMA_IFCR_CTCIF4                DMA_IFCR_CTCIF4                                               
#define LL_DMA_IFCR_CHTIF4                DMA_IFCR_CHTIF4                                               
#define LL_DMA_IFCR_CTEIF4                DMA_IFCR_CTEIF4                                               
#define LL_DMA_IFCR_CGIF5                 DMA_IFCR_CGIF5                                                
#define LL_DMA_IFCR_CTCIF5                DMA_IFCR_CTCIF5                                               
#define LL_DMA_IFCR_CHTIF5                DMA_IFCR_CHTIF5                                               
#define LL_DMA_IFCR_CTEIF5                DMA_IFCR_CTEIF5                                               
#define LL_DMA_IFCR_CGIF6                 DMA_IFCR_CGIF6                                                
#define LL_DMA_IFCR_CTCIF6                DMA_IFCR_CTCIF6                                               
#define LL_DMA_IFCR_CHTIF6                DMA_IFCR_CHTIF6                                               
#define LL_DMA_IFCR_CTEIF6                DMA_IFCR_CTEIF6                                               
#define LL_DMA_IFCR_CGIF7                 DMA_IFCR_CGIF7                                                
#define LL_DMA_IFCR_CTCIF7                DMA_IFCR_CTCIF7                                               
#define LL_DMA_IFCR_CHTIF7                DMA_IFCR_CHTIF7                                               
#define LL_DMA_IFCR_CTEIF7                DMA_IFCR_CTEIF7                                               
   
      
    

                                                  
                                                                          
      
    
#define LL_DMA_ISR_GIF1                   DMA_ISR_GIF1                                                  
#define LL_DMA_ISR_TCIF1                  DMA_ISR_TCIF1                                                 
#define LL_DMA_ISR_HTIF1                  DMA_ISR_HTIF1                                                 
#define LL_DMA_ISR_TEIF1                  DMA_ISR_TEIF1                                                 
#define LL_DMA_ISR_GIF2                   DMA_ISR_GIF2                                                  
#define LL_DMA_ISR_TCIF2                  DMA_ISR_TCIF2                                                 
#define LL_DMA_ISR_HTIF2                  DMA_ISR_HTIF2                                                 
#define LL_DMA_ISR_TEIF2                  DMA_ISR_TEIF2                                                 
#define LL_DMA_ISR_GIF3                   DMA_ISR_GIF3                                                  
#define LL_DMA_ISR_TCIF3                  DMA_ISR_TCIF3                                                 
#define LL_DMA_ISR_HTIF3                  DMA_ISR_HTIF3                                                 
#define LL_DMA_ISR_TEIF3                  DMA_ISR_TEIF3                                                 
#define LL_DMA_ISR_GIF4                   DMA_ISR_GIF4                                                  
#define LL_DMA_ISR_TCIF4                  DMA_ISR_TCIF4                                                 
#define LL_DMA_ISR_HTIF4                  DMA_ISR_HTIF4                                                 
#define LL_DMA_ISR_TEIF4                  DMA_ISR_TEIF4                                                 
#define LL_DMA_ISR_GIF5                   DMA_ISR_GIF5                                                  
#define LL_DMA_ISR_TCIF5                  DMA_ISR_TCIF5                                                 
#define LL_DMA_ISR_HTIF5                  DMA_ISR_HTIF5                                                 
#define LL_DMA_ISR_TEIF5                  DMA_ISR_TEIF5                                                 
#define LL_DMA_ISR_GIF6                   DMA_ISR_GIF6                                                  
#define LL_DMA_ISR_TCIF6                  DMA_ISR_TCIF6                                                 
#define LL_DMA_ISR_HTIF6                  DMA_ISR_HTIF6                                                 
#define LL_DMA_ISR_TEIF6                  DMA_ISR_TEIF6                                                 
#define LL_DMA_ISR_GIF7                   DMA_ISR_GIF7                                                  
#define LL_DMA_ISR_TCIF7                  DMA_ISR_TCIF7                                                 
#define LL_DMA_ISR_HTIF7                  DMA_ISR_HTIF7                                                 
#define LL_DMA_ISR_TEIF7                  DMA_ISR_TEIF7                                                 
   
      
    

                                     
                                                                                             
      
    
#define LL_DMA_CCR_TCIE                   DMA_CCR_TCIE                                             
#define LL_DMA_CCR_HTIE                   DMA_CCR_HTIE                                             
#define LL_DMA_CCR_TEIE                   DMA_CCR_TEIE                                             
   
      
    

                                       
      
    
#define LL_DMA_CHANNEL_1                  0x00000000U                      
#define LL_DMA_CHANNEL_2                  0x00000001U                      
#define LL_DMA_CHANNEL_3                  0x00000002U                      
#define LL_DMA_CHANNEL_4                  0x00000003U                      
#define LL_DMA_CHANNEL_5                  0x00000004U                      
#define LL_DMA_CHANNEL_6                  0x00000005U                      
#define LL_DMA_CHANNEL_7                  0x00000006U                      
#if defined(USE_FULL_LL_DRIVER)
#define LL_DMA_CHANNEL_ALL                0xFFFF0000U                                                                      
#endif                       
   
      
    

                                                    
      
    
#define LL_DMA_DIRECTION_PERIPH_TO_MEMORY 0x00000000U                                                   
#define LL_DMA_DIRECTION_MEMORY_TO_PERIPH DMA_CCR_DIR                                                   
#define LL_DMA_DIRECTION_MEMORY_TO_MEMORY DMA_CCR_MEM2MEM                                               
   
      
    

                                          
      
    
#define LL_DMA_MODE_NORMAL                0x00000000U                                                 
#define LL_DMA_MODE_CIRCULAR              DMA_CCR_CIRC                                                
   
      
    

                                                        
      
    
#define LL_DMA_PERIPH_INCREMENT           DMA_CCR_PINC                                                    
#define LL_DMA_PERIPH_NOINCREMENT         0x00000000U                                                      
   
      
    

                                                    
      
    
#define LL_DMA_MEMORY_INCREMENT           DMA_CCR_MINC                                                 
#define LL_DMA_MEMORY_NOINCREMENT         0x00000000U                                                  
   
      
    

                                                            
      
    
#define LL_DMA_PDATAALIGN_BYTE            0x00000000U                                                         
#define LL_DMA_PDATAALIGN_HALFWORD        DMA_CCR_PSIZE_0                                                     
#define LL_DMA_PDATAALIGN_WORD            DMA_CCR_PSIZE_1                                                     
   
      
    

                                                        
      
    
#define LL_DMA_MDATAALIGN_BYTE            0x00000000U                                                     
#define LL_DMA_MDATAALIGN_HALFWORD        DMA_CCR_MSIZE_0                                                 
#define LL_DMA_MDATAALIGN_WORD            DMA_CCR_MSIZE_1                                                 
   
      
    

                                                        
      
    
#define LL_DMA_PRIORITY_LOW               0x00000000U                                               
#define LL_DMA_PRIORITY_MEDIUM            DMA_CCR_PL_0                                              
#define LL_DMA_PRIORITY_HIGH              DMA_CCR_PL_1                                              
#define LL_DMA_PRIORITY_VERYHIGH          DMA_CCR_PL                                                
   
      
    

#if !defined(DMAMUX1)
                                                           
      
    
#define LL_DMA_REQUEST_0                  0x00000000U                                  
#define LL_DMA_REQUEST_1                  0x00000001U                                  
#define LL_DMA_REQUEST_2                  0x00000002U                                  
#define LL_DMA_REQUEST_3                  0x00000003U                                  
#define LL_DMA_REQUEST_4                  0x00000004U                                  
#define LL_DMA_REQUEST_5                  0x00000005U                                  
#define LL_DMA_REQUEST_6                  0x00000006U                                  
#define LL_DMA_REQUEST_7                  0x00000007U                                  
   
      
    
#endif                       
   
      
    

                                                                                
                                                        
      
    

                                                                         
      
    
   
                                         
                                     
                                          
                                                         
                
    
#define LL_DMA_WriteReg(__INSTANCE__, __REG__, __VALUE__) WRITE_REG(__INSTANCE__->__REG__, (__VALUE__))

   
                                        
                                     
                                       
                          
    
#define LL_DMA_ReadReg(__INSTANCE__, __REG__) READ_REG(__INSTANCE__->__REG__)
   
      
    

                                                                 
      
    
   
                                           
                                              
                
    
#define __LL_DMA_GET_INSTANCE(__CHANNEL_INSTANCE__)   \
  (((uint32_t)(__CHANNEL_INSTANCE__) > ((uint32_t)DMA1_Channel7)) ?  DMA2 : DMA1)

   
                                                       
                                              
                            
    
#define __LL_DMA_GET_CHANNEL(__CHANNEL_INSTANCE__)   \
  (((uint32_t)(__CHANNEL_INSTANCE__) == ((uint32_t)DMA1_Channel1)) ? LL_DMA_CHANNEL_1 : \
   ((uint32_t)(__CHANNEL_INSTANCE__) == ((uint32_t)DMA2_Channel1)) ? LL_DMA_CHANNEL_1 : \
   ((uint32_t)(__CHANNEL_INSTANCE__) == ((uint32_t)DMA1_Channel2)) ? LL_DMA_CHANNEL_2 : \
   ((uint32_t)(__CHANNEL_INSTANCE__) == ((uint32_t)DMA2_Channel2)) ? LL_DMA_CHANNEL_2 : \
   ((uint32_t)(__CHANNEL_INSTANCE__) == ((uint32_t)DMA1_Channel3)) ? LL_DMA_CHANNEL_3 : \
   ((uint32_t)(__CHANNEL_INSTANCE__) == ((uint32_t)DMA2_Channel3)) ? LL_DMA_CHANNEL_3 : \
   ((uint32_t)(__CHANNEL_INSTANCE__) == ((uint32_t)DMA1_Channel4)) ? LL_DMA_CHANNEL_4 : \
   ((uint32_t)(__CHANNEL_INSTANCE__) == ((uint32_t)DMA2_Channel4)) ? LL_DMA_CHANNEL_4 : \
   ((uint32_t)(__CHANNEL_INSTANCE__) == ((uint32_t)DMA1_Channel5)) ? LL_DMA_CHANNEL_5 : \
   ((uint32_t)(__CHANNEL_INSTANCE__) == ((uint32_t)DMA2_Channel5)) ? LL_DMA_CHANNEL_5 : \
   ((uint32_t)(__CHANNEL_INSTANCE__) == ((uint32_t)DMA1_Channel6)) ? LL_DMA_CHANNEL_6 : \
   ((uint32_t)(__CHANNEL_INSTANCE__) == ((uint32_t)DMA2_Channel6)) ? LL_DMA_CHANNEL_6 : \
   LL_DMA_CHANNEL_7)

   
                                                                             
                                 
                                        
                         
    
#define __LL_DMA_GET_CHANNEL_INSTANCE(__DMA_INSTANCE__, __CHANNEL__)   \
  ((((uint32_t)(__DMA_INSTANCE__) == ((uint32_t)DMA1)) && ((uint32_t)(__CHANNEL__) == ((uint32_t)LL_DMA_CHANNEL_1))) ? DMA1_Channel1 : \
   (((uint32_t)(__DMA_INSTANCE__) == ((uint32_t)DMA2)) && ((uint32_t)(__CHANNEL__) == ((uint32_t)LL_DMA_CHANNEL_1))) ? DMA2_Channel1 : \
   (((uint32_t)(__DMA_INSTANCE__) == ((uint32_t)DMA1)) && ((uint32_t)(__CHANNEL__) == ((uint32_t)LL_DMA_CHANNEL_2))) ? DMA1_Channel2 : \
   (((uint32_t)(__DMA_INSTANCE__) == ((uint32_t)DMA2)) && ((uint32_t)(__CHANNEL__) == ((uint32_t)LL_DMA_CHANNEL_2))) ? DMA2_Channel2 : \
   (((uint32_t)(__DMA_INSTANCE__) == ((uint32_t)DMA1)) && ((uint32_t)(__CHANNEL__) == ((uint32_t)LL_DMA_CHANNEL_3))) ? DMA1_Channel3 : \
   (((uint32_t)(__DMA_INSTANCE__) == ((uint32_t)DMA2)) && ((uint32_t)(__CHANNEL__) == ((uint32_t)LL_DMA_CHANNEL_3))) ? DMA2_Channel3 : \
   (((uint32_t)(__DMA_INSTANCE__) == ((uint32_t)DMA1)) && ((uint32_t)(__CHANNEL__) == ((uint32_t)LL_DMA_CHANNEL_4))) ? DMA1_Channel4 : \
   (((uint32_t)(__DMA_INSTANCE__) == ((uint32_t)DMA2)) && ((uint32_t)(__CHANNEL__) == ((uint32_t)LL_DMA_CHANNEL_4))) ? DMA2_Channel4 : \
   (((uint32_t)(__DMA_INSTANCE__) == ((uint32_t)DMA1)) && ((uint32_t)(__CHANNEL__) == ((uint32_t)LL_DMA_CHANNEL_5))) ? DMA1_Channel5 : \
   (((uint32_t)(__DMA_INSTANCE__) == ((uint32_t)DMA2)) && ((uint32_t)(__CHANNEL__) == ((uint32_t)LL_DMA_CHANNEL_5))) ? DMA2_Channel5 : \
   (((uint32_t)(__DMA_INSTANCE__) == ((uint32_t)DMA1)) && ((uint32_t)(__CHANNEL__) == ((uint32_t)LL_DMA_CHANNEL_6))) ? DMA1_Channel6 : \
   (((uint32_t)(__DMA_INSTANCE__) == ((uint32_t)DMA2)) && ((uint32_t)(__CHANNEL__) == ((uint32_t)LL_DMA_CHANNEL_6))) ? DMA2_Channel6 : \
   (((uint32_t)(__DMA_INSTANCE__) == ((uint32_t)DMA1)) && ((uint32_t)(__CHANNEL__) == ((uint32_t)LL_DMA_CHANNEL_7))) ? DMA1_Channel7 : \
   DMA2_Channel7)

   
      
    

   
      
    

                                                                                
                                                              
      
    

                                                   
      
    
   
                               
                                                           
                              
                                                                      
                                      
                                      
                                      
                                      
                                      
                                      
                                      
                
    
__STATIC_INLINE void LL_DMA_EnableChannel(const DMA_TypeDef *DMAx, uint32_t Channel)
{
  uint32_t dma_base_addr = (uint32_t)DMAx;
  SET_BIT(((DMA_Channel_TypeDef *)(dma_base_addr + CHANNEL_OFFSET_TAB[Channel]))->CCR, DMA_CCR_EN);
}

   
                                
                                                            
                              
                                                                      
                                      
                                      
                                      
                                      
                                      
                                      
                                      
                
    
__STATIC_INLINE void LL_DMA_DisableChannel(const DMA_TypeDef *DMAx, uint32_t Channel)
{
  uint32_t dma_base_addr = (uint32_t)DMAx;
  CLEAR_BIT(((DMA_Channel_TypeDef *)(dma_base_addr + CHANNEL_OFFSET_TAB[Channel]))->CCR, DMA_CCR_EN);
}

   
                                                        
                                                              
                              
                                                                      
                                      
                                      
                                      
                                      
                                      
                                      
                                      
                                  
    
__STATIC_INLINE uint32_t LL_DMA_IsEnabledChannel(const DMA_TypeDef *DMAx, uint32_t Channel)
{
  uint32_t dma_base_addr = (uint32_t)DMAx;
  return ((READ_BIT(((DMA_Channel_TypeDef *)(dma_base_addr + CHANNEL_OFFSET_TAB[Channel]))->CCR,
                    DMA_CCR_EN) == (DMA_CCR_EN)) ? 1UL : 0UL);
}

   
                                                          
                                                              
                                                              
                                                              
                                                              
                                                              
                                                              
                                                              
                                                            
                              
                                                                      
                                      
                                      
                                      
                                      
                                      
                                      
                                      
                                                                                           
                                                                                                                                           
                                                                     
                                                                               
                                                                               
                                                                                                              
                                                                                                              
                                                                                                                                      
                
    
__STATIC_INLINE void LL_DMA_ConfigTransfer(const DMA_TypeDef *DMAx, uint32_t Channel, uint32_t Configuration)
{
  uint32_t dma_base_addr = (uint32_t)DMAx;
  MODIFY_REG(((DMA_Channel_TypeDef *)(dma_base_addr + CHANNEL_OFFSET_TAB[Channel]))->CCR,
             DMA_CCR_DIR | DMA_CCR_MEM2MEM | DMA_CCR_CIRC | DMA_CCR_PINC | DMA_CCR_MINC | DMA_CCR_PSIZE | DMA_CCR_MSIZE | DMA_CCR_PL,
             Configuration);
}

   
                                                                              
                                                                        
                                                                      
                              
                                                                      
                                      
                                      
                                      
                                      
                                      
                                      
                                      
                                                                        
                                                       
                                                       
                                                       
                
    
__STATIC_INLINE void LL_DMA_SetDataTransferDirection(const DMA_TypeDef *DMAx, uint32_t Channel, uint32_t Direction)
{
  uint32_t dma_base_addr = (uint32_t)DMAx;
  MODIFY_REG(((DMA_Channel_TypeDef *)(dma_base_addr + CHANNEL_OFFSET_TAB[Channel]))->CCR,
             DMA_CCR_DIR | DMA_CCR_MEM2MEM, Direction);
}

   
                                                                              
                                                                        
                                                                      
                              
                                                                      
                                      
                                      
                                      
                                      
                                      
                                      
                                      
                                                              
                                                       
                                                       
                                                       
    
__STATIC_INLINE uint32_t LL_DMA_GetDataTransferDirection(const DMA_TypeDef *DMAx, uint32_t Channel)
{
  uint32_t dma_base_addr = (uint32_t)DMAx;
  return (READ_BIT(((DMA_Channel_TypeDef *)(dma_base_addr + CHANNEL_OFFSET_TAB[Channel]))->CCR,
                   DMA_CCR_DIR | DMA_CCR_MEM2MEM));
}

   
                                            
                                                                         
                                                        
                                                     
                              
                                                                      
                                      
                                      
                                      
                                      
                                      
                                      
                                      
                                                                   
                                        
                                          
                
    
__STATIC_INLINE void LL_DMA_SetMode(const DMA_TypeDef *DMAx, uint32_t Channel, uint32_t Mode)
{
  uint32_t dma_base_addr = (uint32_t)DMAx;
  MODIFY_REG(((DMA_Channel_TypeDef *)(dma_base_addr + CHANNEL_OFFSET_TAB[Channel]))->CCR, DMA_CCR_CIRC,
             Mode);
}

   
                                            
                                                     
                              
                                                                      
                                      
                                      
                                      
                                      
                                      
                                      
                                      
                                                              
                                        
                                          
    
__STATIC_INLINE uint32_t LL_DMA_GetMode(const DMA_TypeDef *DMAx, uint32_t Channel)
{
  uint32_t dma_base_addr = (uint32_t)DMAx;
  return (READ_BIT(((DMA_Channel_TypeDef *)(dma_base_addr + CHANNEL_OFFSET_TAB[Channel]))->CCR,
                   DMA_CCR_CIRC));
}

   
                                          
                                                              
                              
                                                                      
                                      
                                      
                                      
                                      
                                      
                                      
                                      
                                                                                    
                                             
                                               
                
    
__STATIC_INLINE void LL_DMA_SetPeriphIncMode(const DMA_TypeDef *DMAx, uint32_t Channel, uint32_t PeriphOrM2MSrcIncMode)
{
  uint32_t dma_base_addr = (uint32_t)DMAx;
  MODIFY_REG(((DMA_Channel_TypeDef *)(dma_base_addr + CHANNEL_OFFSET_TAB[Channel]))->CCR, DMA_CCR_PINC,
             PeriphOrM2MSrcIncMode);
}

   
                                          
                                                              
                              
                                                                      
                                      
                                      
                                      
                                      
                                      
                                      
                                      
                                                              
                                             
                                               
    
__STATIC_INLINE uint32_t LL_DMA_GetPeriphIncMode(const DMA_TypeDef *DMAx, uint32_t Channel)
{
  uint32_t dma_base_addr = (uint32_t)DMAx;
  return (READ_BIT(((DMA_Channel_TypeDef *)(dma_base_addr + CHANNEL_OFFSET_TAB[Channel]))->CCR,
                   DMA_CCR_PINC));
}

   
                                      
                                                              
                              
                                                                      
                                      
                                      
                                      
                                      
                                      
                                      
                                      
                                                                                    
                                             
                                               
                
    
__STATIC_INLINE void LL_DMA_SetMemoryIncMode(const DMA_TypeDef *DMAx, uint32_t Channel, uint32_t MemoryOrM2MDstIncMode)
{
  uint32_t dma_base_addr = (uint32_t)DMAx;
  MODIFY_REG(((DMA_Channel_TypeDef *)(dma_base_addr + CHANNEL_OFFSET_TAB[Channel]))->CCR, DMA_CCR_MINC,
             MemoryOrM2MDstIncMode);
}

   
                                      
                                                              
                              
                                                                      
                                      
                                      
                                      
                                      
                                      
                                      
                                      
                                                              
                                             
                                               
    
__STATIC_INLINE uint32_t LL_DMA_GetMemoryIncMode(const DMA_TypeDef *DMAx, uint32_t Channel)
{
  uint32_t dma_base_addr = (uint32_t)DMAx;
  return (READ_BIT(((DMA_Channel_TypeDef *)(dma_base_addr + CHANNEL_OFFSET_TAB[Channel]))->CCR,
                   DMA_CCR_MINC));
}

   
                                
                                                           
                              
                                                                      
                                      
                                      
                                      
                                      
                                      
                                      
                                      
                                                                                     
                                            
                                                
                                            
                
    
__STATIC_INLINE void LL_DMA_SetPeriphSize(const DMA_TypeDef *DMAx, uint32_t Channel, uint32_t PeriphOrM2MSrcDataSize)
{
  uint32_t dma_base_addr = (uint32_t)DMAx;
  MODIFY_REG(((DMA_Channel_TypeDef *)(dma_base_addr + CHANNEL_OFFSET_TAB[Channel]))->CCR, DMA_CCR_PSIZE,
             PeriphOrM2MSrcDataSize);
}

   
                                
                                                           
                              
                                                                      
                                      
                                      
                                      
                                      
                                      
                                      
                                      
                                                              
                                            
                                                
                                            
    
__STATIC_INLINE uint32_t LL_DMA_GetPeriphSize(const DMA_TypeDef *DMAx, uint32_t Channel)
{
  uint32_t dma_base_addr = (uint32_t)DMAx;
  return (READ_BIT(((DMA_Channel_TypeDef *)(dma_base_addr + CHANNEL_OFFSET_TAB[Channel]))->CCR,
                   DMA_CCR_PSIZE));
}

   
                            
                                                           
                              
                                                                      
                                      
                                      
                                      
                                      
                                      
                                      
                                      
                                                                                     
                                            
                                                
                                            
                
    
__STATIC_INLINE void LL_DMA_SetMemorySize(const DMA_TypeDef *DMAx, uint32_t Channel, uint32_t MemoryOrM2MDstDataSize)
{
  uint32_t dma_base_addr = (uint32_t)DMAx;
  MODIFY_REG(((DMA_Channel_TypeDef *)(dma_base_addr + CHANNEL_OFFSET_TAB[Channel]))->CCR, DMA_CCR_MSIZE,
             MemoryOrM2MDstDataSize);
}

   
                            
                                                           
                              
                                                                      
                                      
                                      
                                      
                                      
                                      
                                      
                                      
                                                              
                                            
                                                
                                            
    
__STATIC_INLINE uint32_t LL_DMA_GetMemorySize(const DMA_TypeDef *DMAx, uint32_t Channel)
{
  uint32_t dma_base_addr = (uint32_t)DMAx;
  return (READ_BIT(((DMA_Channel_TypeDef *)(dma_base_addr + CHANNEL_OFFSET_TAB[Channel]))->CCR,
                   DMA_CCR_MSIZE));
}

   
                                       
                                                                     
                              
                                                                      
                                      
                                      
                                      
                                      
                                      
                                      
                                      
                                                                       
                                         
                                            
                                          
                                              
                
    
__STATIC_INLINE void LL_DMA_SetChannelPriorityLevel(const DMA_TypeDef *DMAx, uint32_t Channel, uint32_t Priority)
{
  uint32_t dma_base_addr = (uint32_t)DMAx;
  MODIFY_REG(((DMA_Channel_TypeDef *)(dma_base_addr + CHANNEL_OFFSET_TAB[Channel]))->CCR, DMA_CCR_PL,
             Priority);
}

   
                                       
                                                                     
                              
                                                                      
                                      
                                      
                                      
                                      
                                      
                                      
                                      
                                                              
                                         
                                            
                                          
                                              
    
__STATIC_INLINE uint32_t LL_DMA_GetChannelPriorityLevel(const DMA_TypeDef *DMAx, uint32_t Channel)
{
  uint32_t dma_base_addr = (uint32_t)DMAx;
  return (READ_BIT(((DMA_Channel_TypeDef *)(dma_base_addr + CHANNEL_OFFSET_TAB[Channel]))->CCR,
                   DMA_CCR_PL));
}

   
                                           
                                        
                               
                                                           
                              
                                                                      
                                      
                                      
                                      
                                      
                                      
                                      
                                      
                                                                 
                
    
__STATIC_INLINE void LL_DMA_SetDataLength(const DMA_TypeDef *DMAx, uint32_t Channel, uint32_t NbData)
{
  uint32_t dma_base_addr = (uint32_t)DMAx;
  MODIFY_REG(((DMA_Channel_TypeDef *)(dma_base_addr + CHANNEL_OFFSET_TAB[Channel]))->CNDTR,
             DMA_CNDTR_NDT, NbData);
}

   
                                           
                                                                      
                                              
                                                           
                              
                                                                      
                                      
                                      
                                      
                                      
                                      
                                      
                                      
                                                          
    
__STATIC_INLINE uint32_t LL_DMA_GetDataLength(const DMA_TypeDef *DMAx, uint32_t Channel)
{
  uint32_t dma_base_addr = (uint32_t)DMAx;
  return (READ_BIT(((DMA_Channel_TypeDef *)(dma_base_addr + CHANNEL_OFFSET_TAB[Channel]))->CNDTR,
                   DMA_CNDTR_NDT));
}

   
                                                           
                                                                        
                                                                                                                   
                                                               
                                                             
                              
                                                                      
                                      
                                      
                                      
                                      
                                      
                                      
                                      
                                                                     
                                                                     
                                                                        
                                                       
                                                       
                                                       
                
    
__STATIC_INLINE void LL_DMA_ConfigAddresses(const DMA_TypeDef *DMAx, uint32_t Channel, uint32_t SrcAddress,
                                            uint32_t DstAddress, uint32_t Direction)
{
  uint32_t dma_base_addr = (uint32_t)DMAx;
                                  
  if (Direction == LL_DMA_DIRECTION_MEMORY_TO_PERIPH)
  {
    WRITE_REG(((DMA_Channel_TypeDef *)(dma_base_addr + CHANNEL_OFFSET_TAB[Channel]))->CMAR, SrcAddress);
    WRITE_REG(((DMA_Channel_TypeDef *)(dma_base_addr + CHANNEL_OFFSET_TAB[Channel]))->CPAR, DstAddress);
  }
                                                       
  else
  {
    WRITE_REG(((DMA_Channel_TypeDef *)(dma_base_addr + CHANNEL_OFFSET_TAB[Channel]))->CPAR, SrcAddress);
    WRITE_REG(((DMA_Channel_TypeDef *)(dma_base_addr + CHANNEL_OFFSET_TAB[Channel]))->CMAR, DstAddress);
  }
}

   
                                   
                                                                                                                     
                                                                        
                                                              
                              
                                                                      
                                      
                                      
                                      
                                      
                                      
                                      
                                      
                                                                        
                
    
__STATIC_INLINE void LL_DMA_SetMemoryAddress(const DMA_TypeDef *DMAx, uint32_t Channel, uint32_t MemoryAddress)
{
  uint32_t dma_base_addr = (uint32_t)DMAx;
  WRITE_REG(((DMA_Channel_TypeDef *)(dma_base_addr + CHANNEL_OFFSET_TAB[Channel]))->CMAR, MemoryAddress);
}

   
                                       
                                                                                                                     
                                                                        
                                                              
                              
                                                                      
                                      
                                      
                                      
                                      
                                      
                                      
                                      
                                                                        
                
    
__STATIC_INLINE void LL_DMA_SetPeriphAddress(const DMA_TypeDef *DMAx, uint32_t Channel, uint32_t PeriphAddress)
{
  uint32_t dma_base_addr = (uint32_t)DMAx;
  WRITE_REG(((DMA_Channel_TypeDef *)(dma_base_addr + CHANNEL_OFFSET_TAB[Channel]))->CPAR, PeriphAddress);
}

   
                               
                                                                                                                     
                                                              
                              
                                                                      
                                      
                                      
                                      
                                      
                                      
                                      
                                      
                                                          
    
__STATIC_INLINE uint32_t LL_DMA_GetMemoryAddress(const DMA_TypeDef *DMAx, uint32_t Channel)
{
  uint32_t dma_base_addr = (uint32_t)DMAx;
  return (READ_REG(((DMA_Channel_TypeDef *)(dma_base_addr + CHANNEL_OFFSET_TAB[Channel]))->CMAR));
}

   
                                   
                                                                                                                     
                                                              
                              
                                                                      
                                      
                                      
                                      
                                      
                                      
                                      
                                      
                                                          
    
__STATIC_INLINE uint32_t LL_DMA_GetPeriphAddress(const DMA_TypeDef *DMAx, uint32_t Channel)
{
  uint32_t dma_base_addr = (uint32_t)DMAx;
  return (READ_REG(((DMA_Channel_TypeDef *)(dma_base_addr + CHANNEL_OFFSET_TAB[Channel]))->CPAR));
}

   
                                                    
                                                                                
                                                                        
                                                              
                              
                                                                      
                                      
                                      
                                      
                                      
                                      
                                      
                                      
                                                                        
                
    
__STATIC_INLINE void LL_DMA_SetM2MSrcAddress(const DMA_TypeDef *DMAx, uint32_t Channel, uint32_t MemoryAddress)
{
  uint32_t dma_base_addr = (uint32_t)DMAx;
  WRITE_REG(((DMA_Channel_TypeDef *)(dma_base_addr + CHANNEL_OFFSET_TAB[Channel]))->CPAR, MemoryAddress);
}

   
                                                         
                                                                                
                                                                        
                                                              
                              
                                                                      
                                      
                                      
                                      
                                      
                                      
                                      
                                      
                                                                        
                
    
__STATIC_INLINE void LL_DMA_SetM2MDstAddress(const DMA_TypeDef *DMAx, uint32_t Channel, uint32_t MemoryAddress)
{
  uint32_t dma_base_addr = (uint32_t)DMAx;
  WRITE_REG(((DMA_Channel_TypeDef *)(dma_base_addr + CHANNEL_OFFSET_TAB[Channel]))->CMAR, MemoryAddress);
}

   
                                                    
                                                                                
                                                              
                              
                                                                      
                                      
                                      
                                      
                                      
                                      
                                      
                                      
                                                          
    
__STATIC_INLINE uint32_t LL_DMA_GetM2MSrcAddress(const DMA_TypeDef *DMAx, uint32_t Channel)
{
  uint32_t dma_base_addr = (uint32_t)DMAx;
  return (READ_REG(((DMA_Channel_TypeDef *)(dma_base_addr + CHANNEL_OFFSET_TAB[Channel]))->CPAR));
}

   
                                                         
                                                                                
                                                              
                              
                                                                      
                                      
                                      
                                      
                                      
                                      
                                      
                                      
                                                          
    
__STATIC_INLINE uint32_t LL_DMA_GetM2MDstAddress(const DMA_TypeDef *DMAx, uint32_t Channel)
{
  uint32_t dma_base_addr = (uint32_t)DMAx;
  return (READ_REG(((DMA_Channel_TypeDef *)(dma_base_addr + CHANNEL_OFFSET_TAB[Channel]))->CMAR));
}

#if defined(DMAMUX1)
   
                                                                 
                                                                    
                                                                     
                                                              
                              
                                                                      
                                      
                                      
                                      
                                      
                                      
                                      
                                      
                                                                      
                                           
                                              
                                              
                                              
                                              
                                        
                                        
                                            
                                            
                                           
                                           
                                           
                                           
                                           
                                           
                                           
                                           
                                           
                                           
                                           
                                           
                                           
                                           
                                           
                                           
                                             
                                             
                                             
                                             
                                             
                                             
                                            
                                            
                                            
                                            
                                              
                                              
                                          
                                          
                                          
                                          
                                         
                                         
                                            
                                            
                                            
                                            
                                           
                                             
                                            
                                            
                                            
                                            
                                            
                                           
                                             
                                            
                                            
                                            
                                            
                                            
                                           
                                            
                                            
                                            
                                            
                                           
                                             
                                            
                                            
                                            
                                            
                                           
                                            
                                            
                                            
                                            
                                           
                                             
                                             
                                            
                                              
                                             
                                             
                                            
                                             
                                            
                                               
                                               
                                               
                                               
                                        
                                             
                                          
                                           
                                           
                
    
__STATIC_INLINE void LL_DMA_SetPeriphRequest(const DMA_TypeDef *DMAx, uint32_t Channel, uint32_t Request)
{
  uint32_t dmamux_ccr_offset = ((((uint32_t)DMAx ^ (uint32_t)DMA1) >> 10U) * 7U);
  MODIFY_REG((DMAMUX1_Channel0 + Channel + dmamux_ccr_offset)->CCR, DMAMUX_CxCR_DMAREQ_ID, Request);
}

   
                                                                 
                                                                    
                                                                     
                                                              
                              
                                                                      
                                      
                                      
                                      
                                      
                                      
                                      
                                      
                                                              
                                           
                                              
                                              
                                              
                                              
                                        
                                        
                                            
                                            
                                           
                                           
                                           
                                           
                                           
                                           
                                           
                                           
                                           
                                           
                                           
                                           
                                           
                                           
                                           
                                           
                                             
                                             
                                             
                                             
                                             
                                             
                                            
                                            
                                            
                                            
                                              
                                              
                                          
                                          
                                          
                                          
                                         
                                         
                                            
                                            
                                            
                                            
                                           
                                             
                                            
                                            
                                            
                                            
                                            
                                           
                                             
                                            
                                            
                                            
                                            
                                            
                                           
                                            
                                            
                                            
                                            
                                           
                                             
                                            
                                            
                                            
                                            
                                           
                                            
                                            
                                            
                                            
                                           
                                             
                                             
                                            
                                              
                                             
                                             
                                            
                                             
                                            
                                               
                                               
                                               
                                               
                                        
                                             
                                          
                                           
                                           
    
__STATIC_INLINE uint32_t LL_DMA_GetPeriphRequest(const DMA_TypeDef *DMAx, uint32_t Channel)
{
  uint32_t dmamux_ccr_offset = ((((uint32_t)DMAx ^ (uint32_t)DMA1) >> 10U) * 7U);
  return (READ_BIT((DMAMUX1_Channel0 + Channel + dmamux_ccr_offset)->CCR, DMAMUX_CxCR_DMAREQ_ID));
}

#else
   
                                                          
                                                                                                                     
                                                                
                                                                
                                                                
                                                                
                                                                
                                                                
                                                              
                              
                                                                      
                                      
                                      
                                      
                                      
                                      
                                      
                                      
                                                                            
                                      
                                      
                                      
                                      
                                      
                                      
                                      
                                      
                
    
__STATIC_INLINE void LL_DMA_SetPeriphRequest(DMA_TypeDef *DMAx, uint32_t Channel, uint32_t PeriphRequest)
{
  MODIFY_REG(((DMA_Request_TypeDef *)((uint32_t)((uint32_t)DMAx + DMA_CSELR_OFFSET)))->CSELR,
             DMA_CSELR_C1S << ((Channel) * 4U), PeriphRequest << DMA_POSITION_CSELR_CXS);
}

   
                                                          
                                                                
                                                                
                                                                
                                                                
                                                                
                                                                
                                                              
                              
                                                                      
                                      
                                      
                                      
                                      
                                      
                                      
                                      
                                                              
                                      
                                      
                                      
                                      
                                      
                                      
                                      
                                      
    
__STATIC_INLINE uint32_t LL_DMA_GetPeriphRequest(const DMA_TypeDef *DMAx, uint32_t Channel)
{
  return (READ_BIT(((DMA_Request_TypeDef *)((uint32_t)((uint32_t)DMAx + DMA_CSELR_OFFSET)))->CSELR,
                   DMA_CSELR_C1S << ((Channel) * 4U)) >> DMA_POSITION_CSELR_CXS);
}

#endif              
   
      
    

                                                       
      
    

   
                                                
                                                              
                              
                                  
    
__STATIC_INLINE uint32_t LL_DMA_IsActiveFlag_GI1(const DMA_TypeDef *DMAx)
{
  return ((READ_BIT(DMAx->ISR, DMA_ISR_GIF1) == (DMA_ISR_GIF1)) ? 1UL : 0UL);
}

   
                                                
                                                              
                              
                                  
    
__STATIC_INLINE uint32_t LL_DMA_IsActiveFlag_GI2(const DMA_TypeDef *DMAx)
{
  return ((READ_BIT(DMAx->ISR, DMA_ISR_GIF2) == (DMA_ISR_GIF2)) ? 1UL : 0UL);
}

   
                                                
                                                              
                              
                                  
    
__STATIC_INLINE uint32_t LL_DMA_IsActiveFlag_GI3(const DMA_TypeDef *DMAx)
{
  return ((READ_BIT(DMAx->ISR, DMA_ISR_GIF3) == (DMA_ISR_GIF3)) ? 1UL : 0UL);
}

   
                                                
                                                              
                              
                                  
    
__STATIC_INLINE uint32_t LL_DMA_IsActiveFlag_GI4(const DMA_TypeDef *DMAx)
{
  return ((READ_BIT(DMAx->ISR, DMA_ISR_GIF4) == (DMA_ISR_GIF4)) ? 1UL : 0UL);
}

   
                                                
                                                              
                              
                                  
    
__STATIC_INLINE uint32_t LL_DMA_IsActiveFlag_GI5(const DMA_TypeDef *DMAx)
{
  return ((READ_BIT(DMAx->ISR, DMA_ISR_GIF5) == (DMA_ISR_GIF5)) ? 1UL : 0UL);
}

   
                                                
                                                              
                              
                                  
    
__STATIC_INLINE uint32_t LL_DMA_IsActiveFlag_GI6(const DMA_TypeDef *DMAx)
{
  return ((READ_BIT(DMAx->ISR, DMA_ISR_GIF6) == (DMA_ISR_GIF6)) ? 1UL : 0UL);
}

   
                                                
                                                              
                              
                                  
    
__STATIC_INLINE uint32_t LL_DMA_IsActiveFlag_GI7(const DMA_TypeDef *DMAx)
{
  return ((READ_BIT(DMAx->ISR, DMA_ISR_GIF7) == (DMA_ISR_GIF7)) ? 1UL : 0UL);
}

   
                                                 
                                                              
                              
                                  
    
__STATIC_INLINE uint32_t LL_DMA_IsActiveFlag_TC1(const DMA_TypeDef *DMAx)
{
  return ((READ_BIT(DMAx->ISR, DMA_ISR_TCIF1) == (DMA_ISR_TCIF1)) ? 1UL : 0UL);
}

   
                                                 
                                                              
                              
                                  
    
__STATIC_INLINE uint32_t LL_DMA_IsActiveFlag_TC2(const DMA_TypeDef *DMAx)
{
  return ((READ_BIT(DMAx->ISR, DMA_ISR_TCIF2) == (DMA_ISR_TCIF2)) ? 1UL : 0UL);
}

   
                                                 
                                                              
                              
                                  
    
__STATIC_INLINE uint32_t LL_DMA_IsActiveFlag_TC3(const DMA_TypeDef *DMAx)
{
  return ((READ_BIT(DMAx->ISR, DMA_ISR_TCIF3) == (DMA_ISR_TCIF3)) ? 1UL : 0UL);
}

   
                                                 
                                                              
                              
                                  
    
__STATIC_INLINE uint32_t LL_DMA_IsActiveFlag_TC4(const DMA_TypeDef *DMAx)
{
  return ((READ_BIT(DMAx->ISR, DMA_ISR_TCIF4) == (DMA_ISR_TCIF4)) ? 1UL : 0UL);
}

   
                                                 
                                                              
                              
                                  
    
__STATIC_INLINE uint32_t LL_DMA_IsActiveFlag_TC5(const DMA_TypeDef *DMAx)
{
  return ((READ_BIT(DMAx->ISR, DMA_ISR_TCIF5) == (DMA_ISR_TCIF5)) ? 1UL : 0UL);
}

   
                                                 
                                                              
                              
                                  
    
__STATIC_INLINE uint32_t LL_DMA_IsActiveFlag_TC6(const DMA_TypeDef *DMAx)
{
  return ((READ_BIT(DMAx->ISR, DMA_ISR_TCIF6) == (DMA_ISR_TCIF6)) ? 1UL : 0UL);
}

   
                                                 
                                                              
                              
                                  
    
__STATIC_INLINE uint32_t LL_DMA_IsActiveFlag_TC7(const DMA_TypeDef *DMAx)
{
  return ((READ_BIT(DMAx->ISR, DMA_ISR_TCIF7) == (DMA_ISR_TCIF7)) ? 1UL : 0UL);
}

   
                                             
                                                              
                              
                                  
    
__STATIC_INLINE uint32_t LL_DMA_IsActiveFlag_HT1(const DMA_TypeDef *DMAx)
{
  return ((READ_BIT(DMAx->ISR, DMA_ISR_HTIF1) == (DMA_ISR_HTIF1)) ? 1UL : 0UL);
}

   
                                             
                                                              
                              
                                  
    
__STATIC_INLINE uint32_t LL_DMA_IsActiveFlag_HT2(const DMA_TypeDef *DMAx)
{
  return ((READ_BIT(DMAx->ISR, DMA_ISR_HTIF2) == (DMA_ISR_HTIF2)) ? 1UL : 0UL);
}

   
                                             
                                                              
                              
                                  
    
__STATIC_INLINE uint32_t LL_DMA_IsActiveFlag_HT3(const DMA_TypeDef *DMAx)
{
  return ((READ_BIT(DMAx->ISR, DMA_ISR_HTIF3) == (DMA_ISR_HTIF3)) ? 1UL : 0UL);
}

   
                                             
                                                              
                              
                                  
    
__STATIC_INLINE uint32_t LL_DMA_IsActiveFlag_HT4(const DMA_TypeDef *DMAx)
{
  return ((READ_BIT(DMAx->ISR, DMA_ISR_HTIF4) == (DMA_ISR_HTIF4)) ? 1UL : 0UL);
}

   
                                             
                                                              
                              
                                  
    
__STATIC_INLINE uint32_t LL_DMA_IsActiveFlag_HT5(const DMA_TypeDef *DMAx)
{
  return ((READ_BIT(DMAx->ISR, DMA_ISR_HTIF5) == (DMA_ISR_HTIF5)) ? 1UL : 0UL);
}

   
                                             
                                                              
                              
                                  
    
__STATIC_INLINE uint32_t LL_DMA_IsActiveFlag_HT6(const DMA_TypeDef *DMAx)
{
  return ((READ_BIT(DMAx->ISR, DMA_ISR_HTIF6) == (DMA_ISR_HTIF6)) ? 1UL : 0UL);
}

   
                                             
                                                              
                              
                                  
    
__STATIC_INLINE uint32_t LL_DMA_IsActiveFlag_HT7(const DMA_TypeDef *DMAx)
{
  return ((READ_BIT(DMAx->ISR, DMA_ISR_HTIF7) == (DMA_ISR_HTIF7)) ? 1UL : 0UL);
}

   
                                              
                                                              
                              
                                  
    
__STATIC_INLINE uint32_t LL_DMA_IsActiveFlag_TE1(const DMA_TypeDef *DMAx)
{
  return ((READ_BIT(DMAx->ISR, DMA_ISR_TEIF1) == (DMA_ISR_TEIF1)) ? 1UL : 0UL);
}

   
                                              
                                                              
                              
                                  
    
__STATIC_INLINE uint32_t LL_DMA_IsActiveFlag_TE2(const DMA_TypeDef *DMAx)
{
  return ((READ_BIT(DMAx->ISR, DMA_ISR_TEIF2) == (DMA_ISR_TEIF2)) ? 1UL : 0UL);
}

   
                                              
                                                              
                              
                                  
    
__STATIC_INLINE uint32_t LL_DMA_IsActiveFlag_TE3(const DMA_TypeDef *DMAx)
{
  return ((READ_BIT(DMAx->ISR, DMA_ISR_TEIF3) == (DMA_ISR_TEIF3)) ? 1UL : 0UL);
}

   
                                              
                                                              
                              
                                  
    
__STATIC_INLINE uint32_t LL_DMA_IsActiveFlag_TE4(const DMA_TypeDef *DMAx)
{
  return ((READ_BIT(DMAx->ISR, DMA_ISR_TEIF4) == (DMA_ISR_TEIF4)) ? 1UL : 0UL);
}

   
                                              
                                                              
                              
                                  
    
__STATIC_INLINE uint32_t LL_DMA_IsActiveFlag_TE5(const DMA_TypeDef *DMAx)
{
  return ((READ_BIT(DMAx->ISR, DMA_ISR_TEIF5) == (DMA_ISR_TEIF5)) ? 1UL : 0UL);
}

   
                                              
                                                              
                              
                                  
    
__STATIC_INLINE uint32_t LL_DMA_IsActiveFlag_TE6(const DMA_TypeDef *DMAx)
{
  return ((READ_BIT(DMAx->ISR, DMA_ISR_TEIF6) == (DMA_ISR_TEIF6)) ? 1UL : 0UL);
}

   
                                              
                                                              
                              
                                  
    
__STATIC_INLINE uint32_t LL_DMA_IsActiveFlag_TE7(const DMA_TypeDef *DMAx)
{
  return ((READ_BIT(DMAx->ISR, DMA_ISR_TEIF7) == (DMA_ISR_TEIF7)) ? 1UL : 0UL);
}

   
                                                  
                                                                              
                                                                            
                                                               
                                                               
                                                           
                              
                
    
__STATIC_INLINE void LL_DMA_ClearFlag_GI1(DMA_TypeDef *DMAx)
{
  WRITE_REG(DMAx->IFCR, DMA_IFCR_CGIF1);
}

   
                                                  
                                                                              
                                                                            
                                                               
                                                               
                                                           
                              
                
    
__STATIC_INLINE void LL_DMA_ClearFlag_GI2(DMA_TypeDef *DMAx)
{
  WRITE_REG(DMAx->IFCR, DMA_IFCR_CGIF2);
}

   
                                                  
                                                                              
                                                                            
                                                               
                                                               
                                                           
                              
                
    
__STATIC_INLINE void LL_DMA_ClearFlag_GI3(DMA_TypeDef *DMAx)
{
  WRITE_REG(DMAx->IFCR, DMA_IFCR_CGIF3);
}

   
                                                  
                                                                              
                                                                            
                                                               
                                                               
                                                           
                              
                
    
__STATIC_INLINE void LL_DMA_ClearFlag_GI4(DMA_TypeDef *DMAx)
{
  WRITE_REG(DMAx->IFCR, DMA_IFCR_CGIF4);
}

   
                                                  
                                                                              
                                                                            
                                                               
                                                               
                                                           
                              
                
    
__STATIC_INLINE void LL_DMA_ClearFlag_GI5(DMA_TypeDef *DMAx)
{
  WRITE_REG(DMAx->IFCR, DMA_IFCR_CGIF5);
}

   
                                                  
                                                                              
                                                                            
                                                               
                                                               
                                                           
                              
                
    
__STATIC_INLINE void LL_DMA_ClearFlag_GI6(DMA_TypeDef *DMAx)
{
  WRITE_REG(DMAx->IFCR, DMA_IFCR_CGIF6);
}

   
                                                  
                                                                              
                                                                            
                                                               
                                                               
                                                           
                              
                
    
__STATIC_INLINE void LL_DMA_ClearFlag_GI7(DMA_TypeDef *DMAx)
{
  WRITE_REG(DMAx->IFCR, DMA_IFCR_CGIF7);
}

   
                                                    
                                                           
                              
                
    
__STATIC_INLINE void LL_DMA_ClearFlag_TC1(DMA_TypeDef *DMAx)
{
  WRITE_REG(DMAx->IFCR, DMA_IFCR_CTCIF1);
}

   
                                                    
                                                           
                              
                
    
__STATIC_INLINE void LL_DMA_ClearFlag_TC2(DMA_TypeDef *DMAx)
{
  WRITE_REG(DMAx->IFCR, DMA_IFCR_CTCIF2);
}

   
                                                    
                                                           
                              
                
    
__STATIC_INLINE void LL_DMA_ClearFlag_TC3(DMA_TypeDef *DMAx)
{
  WRITE_REG(DMAx->IFCR, DMA_IFCR_CTCIF3);
}

   
                                                    
                                                           
                              
                
    
__STATIC_INLINE void LL_DMA_ClearFlag_TC4(DMA_TypeDef *DMAx)
{
  WRITE_REG(DMAx->IFCR, DMA_IFCR_CTCIF4);
}

   
                                                    
                                                           
                              
                
    
__STATIC_INLINE void LL_DMA_ClearFlag_TC5(DMA_TypeDef *DMAx)
{
  WRITE_REG(DMAx->IFCR, DMA_IFCR_CTCIF5);
}

   
                                                    
                                                           
                              
                
    
__STATIC_INLINE void LL_DMA_ClearFlag_TC6(DMA_TypeDef *DMAx)
{
  WRITE_REG(DMAx->IFCR, DMA_IFCR_CTCIF6);
}

   
                                                    
                                                           
                              
                
    
__STATIC_INLINE void LL_DMA_ClearFlag_TC7(DMA_TypeDef *DMAx)
{
  WRITE_REG(DMAx->IFCR, DMA_IFCR_CTCIF7);
}

   
                                                
                                                           
                              
                
    
__STATIC_INLINE void LL_DMA_ClearFlag_HT1(DMA_TypeDef *DMAx)
{
  WRITE_REG(DMAx->IFCR, DMA_IFCR_CHTIF1);
}

   
                                                
                                                           
                              
                
    
__STATIC_INLINE void LL_DMA_ClearFlag_HT2(DMA_TypeDef *DMAx)
{
  WRITE_REG(DMAx->IFCR, DMA_IFCR_CHTIF2);
}

   
                                                
                                                           
                              
                
    
__STATIC_INLINE void LL_DMA_ClearFlag_HT3(DMA_TypeDef *DMAx)
{
  WRITE_REG(DMAx->IFCR, DMA_IFCR_CHTIF3);
}

   
                                                
                                                           
                              
                
    
__STATIC_INLINE void LL_DMA_ClearFlag_HT4(DMA_TypeDef *DMAx)
{
  WRITE_REG(DMAx->IFCR, DMA_IFCR_CHTIF4);
}

   
                                                
                                                           
                              
                
    
__STATIC_INLINE void LL_DMA_ClearFlag_HT5(DMA_TypeDef *DMAx)
{
  WRITE_REG(DMAx->IFCR, DMA_IFCR_CHTIF5);
}

   
                                                
                                                           
                              
                
    
__STATIC_INLINE void LL_DMA_ClearFlag_HT6(DMA_TypeDef *DMAx)
{
  WRITE_REG(DMAx->IFCR, DMA_IFCR_CHTIF6);
}

   
                                                
                                                           
                              
                
    
__STATIC_INLINE void LL_DMA_ClearFlag_HT7(DMA_TypeDef *DMAx)
{
  WRITE_REG(DMAx->IFCR, DMA_IFCR_CHTIF7);
}

   
                                                
                                                           
                              
                
    
__STATIC_INLINE void LL_DMA_ClearFlag_TE1(DMA_TypeDef *DMAx)
{
  WRITE_REG(DMAx->IFCR, DMA_IFCR_CTEIF1);
}

   
                                                
                                                           
                              
                
    
__STATIC_INLINE void LL_DMA_ClearFlag_TE2(DMA_TypeDef *DMAx)
{
  WRITE_REG(DMAx->IFCR, DMA_IFCR_CTEIF2);
}

   
                                                
                                                           
                              
                
    
__STATIC_INLINE void LL_DMA_ClearFlag_TE3(DMA_TypeDef *DMAx)
{
  WRITE_REG(DMAx->IFCR, DMA_IFCR_CTEIF3);
}

   
                                                
                                                           
                              
                
    
__STATIC_INLINE void LL_DMA_ClearFlag_TE4(DMA_TypeDef *DMAx)
{
  WRITE_REG(DMAx->IFCR, DMA_IFCR_CTEIF4);
}

   
                                                
                                                           
                              
                
    
__STATIC_INLINE void LL_DMA_ClearFlag_TE5(DMA_TypeDef *DMAx)
{
  WRITE_REG(DMAx->IFCR, DMA_IFCR_CTEIF5);
}

   
                                                
                                                           
                              
                
    
__STATIC_INLINE void LL_DMA_ClearFlag_TE6(DMA_TypeDef *DMAx)
{
  WRITE_REG(DMAx->IFCR, DMA_IFCR_CTEIF6);
}

   
                                                
                                                           
                              
                
    
__STATIC_INLINE void LL_DMA_ClearFlag_TE7(DMA_TypeDef *DMAx)
{
  WRITE_REG(DMAx->IFCR, DMA_IFCR_CTEIF7);
}

   
      
    

                                                   
      
    
   
                                               
                                                         
                              
                                                                      
                                      
                                      
                                      
                                      
                                      
                                      
                                      
                
    
__STATIC_INLINE void LL_DMA_EnableIT_TC(const DMA_TypeDef *DMAx, uint32_t Channel)
{
  uint32_t dma_base_addr = (uint32_t)DMAx;
  SET_BIT(((DMA_Channel_TypeDef *)(dma_base_addr + CHANNEL_OFFSET_TAB[Channel]))->CCR, DMA_CCR_TCIE);
}

   
                                           
                                                         
                              
                                                                      
                                      
                                      
                                      
                                      
                                      
                                      
                                      
                
    
__STATIC_INLINE void LL_DMA_EnableIT_HT(const DMA_TypeDef *DMAx, uint32_t Channel)
{
  uint32_t dma_base_addr = (uint32_t)DMAx;
  SET_BIT(((DMA_Channel_TypeDef *)(dma_base_addr + CHANNEL_OFFSET_TAB[Channel]))->CCR, DMA_CCR_HTIE);
}

   
                                            
                                                         
                              
                                                                      
                                      
                                      
                                      
                                      
                                      
                                      
                                      
                
    
__STATIC_INLINE void LL_DMA_EnableIT_TE(const DMA_TypeDef *DMAx, uint32_t Channel)
{
  uint32_t dma_base_addr = (uint32_t)DMAx;
  SET_BIT(((DMA_Channel_TypeDef *)(dma_base_addr + CHANNEL_OFFSET_TAB[Channel]))->CCR, DMA_CCR_TEIE);
}

   
                                                
                                                          
                              
                                                                      
                                      
                                      
                                      
                                      
                                      
                                      
                                      
                
    
__STATIC_INLINE void LL_DMA_DisableIT_TC(const DMA_TypeDef *DMAx, uint32_t Channel)
{
  uint32_t dma_base_addr = (uint32_t)DMAx;
  CLEAR_BIT(((DMA_Channel_TypeDef *)(dma_base_addr + CHANNEL_OFFSET_TAB[Channel]))->CCR, DMA_CCR_TCIE);
}

   
                                            
                                                          
                              
                                                                      
                                      
                                      
                                      
                                      
                                      
                                      
                                      
                
    
__STATIC_INLINE void LL_DMA_DisableIT_HT(const DMA_TypeDef *DMAx, uint32_t Channel)
{
  uint32_t dma_base_addr = (uint32_t)DMAx;
  CLEAR_BIT(((DMA_Channel_TypeDef *)(dma_base_addr + CHANNEL_OFFSET_TAB[Channel]))->CCR, DMA_CCR_HTIE);
}

   
                                             
                                                          
                              
                                                                      
                                      
                                      
                                      
                                      
                                      
                                      
                                      
                
    
__STATIC_INLINE void LL_DMA_DisableIT_TE(const DMA_TypeDef *DMAx, uint32_t Channel)
{
  uint32_t dma_base_addr = (uint32_t)DMAx;
  CLEAR_BIT(((DMA_Channel_TypeDef *)(dma_base_addr + CHANNEL_OFFSET_TAB[Channel]))->CCR, DMA_CCR_TEIE);
}

   
                                                            
                                                            
                              
                                                                      
                                      
                                      
                                      
                                      
                                      
                                      
                                      
                                  
    
__STATIC_INLINE uint32_t LL_DMA_IsEnabledIT_TC(const DMA_TypeDef *DMAx, uint32_t Channel)
{
  uint32_t dma_base_addr = (uint32_t)DMAx;
  return ((READ_BIT(((DMA_Channel_TypeDef *)(dma_base_addr + CHANNEL_OFFSET_TAB[Channel]))->CCR,
                    DMA_CCR_TCIE) == (DMA_CCR_TCIE)) ? 1UL : 0UL);
}

   
                                                        
                                                            
                              
                                                                      
                                      
                                      
                                      
                                      
                                      
                                      
                                      
                                  
    
__STATIC_INLINE uint32_t LL_DMA_IsEnabledIT_HT(const DMA_TypeDef *DMAx, uint32_t Channel)
{
  uint32_t dma_base_addr = (uint32_t)DMAx;
  return ((READ_BIT(((DMA_Channel_TypeDef *)(dma_base_addr + CHANNEL_OFFSET_TAB[Channel]))->CCR,
                    DMA_CCR_HTIE) == (DMA_CCR_HTIE)) ? 1UL : 0UL);
}

   
                                                         
                                                            
                              
                                                                      
                                      
                                      
                                      
                                      
                                      
                                      
                                      
                                  
    
__STATIC_INLINE uint32_t LL_DMA_IsEnabledIT_TE(const DMA_TypeDef *DMAx, uint32_t Channel)
{
  uint32_t dma_base_addr = (uint32_t)DMAx;
  return ((READ_BIT(((DMA_Channel_TypeDef *)(dma_base_addr + CHANNEL_OFFSET_TAB[Channel]))->CCR,
                    DMA_CCR_TEIE) == (DMA_CCR_TEIE)) ? 1UL : 0UL);
}

   
      
    

#if defined(USE_FULL_LL_DRIVER)
                                                                           
      
    
ErrorStatus LL_DMA_Init(DMA_TypeDef *DMAx, uint32_t Channel, LL_DMA_InitTypeDef *DMA_InitStruct);
ErrorStatus LL_DMA_DeInit(DMA_TypeDef *DMAx, uint32_t Channel);
void LL_DMA_StructInit(LL_DMA_InitTypeDef *DMA_InitStruct);

   
      
    
#endif                         

   
      
    

   
      
    

#endif                   

   
      
    

#ifdef __cplusplus
}
#endif

#endif                         

