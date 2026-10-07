/**
  ******************************************************************************
  * @file    stm32l4xx_ll_dma2d.h
  * @author  MCD Application Team
  * @brief   Header file of DMA2D LL module.
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

                                                                                
#ifndef STM32L4xx_LL_DMA2D_H
#define STM32L4xx_LL_DMA2D_H

#ifdef __cplusplus
extern "C" {
#endif

                                                                                
#include "stm32l4xx.h"

                                   
      
    

#if defined (DMA2D)

                            
      
    

                                                                                
                                                                                
                                                                                
                                                                                
#if defined(USE_FULL_LL_DRIVER)
                                                          
      
    

   
      
    
#endif                       

                                                                                
#if defined(USE_FULL_LL_DRIVER)
                                                                    
      
    

   
                                             
    
typedef struct
{
  uint32_t Mode;                                                        
                                                                                                 

                                                                                
                                                                                        

  uint32_t ColorMode;                                                                
                                                                                                              

                                                                                      
                                                                                             

  uint32_t OutputBlue;                                                             
                                                                                
                                                                                                               
                                                                                
                                                                                                             
                                                                                
                                                                                                             
                                                                                
                                                                                                               
                                                                                
                                                                                                               

                                                                                
                                                                                                            
                                                                                    

  uint32_t OutputGreen;                                                             
                                                                                
                                                                                                               
                                                                                
                                                                                                             
                                                                                
                                                                                                             
                                                                                
                                                                                                               
                                                                                
                                                                                                               

                                                                               
                                                                                                            
                                                                                    

  uint32_t OutputRed;                                                             
                                                                                
                                                                                                               
                                                                                
                                                                                                             
                                                                                
                                                                                                             
                                                                                
                                                                                                               
                                                                                
                                                                                                               

                                                                               
                                                                                                            
                                                                                    

  uint32_t OutputAlpha;                                                               
                                                                                
                                                                                                               
                                                                                
                                                                                                               
                                                                                
                                                                                                               
                                                                                                                    

                                                                                      
                                                                                                      
                                                                                    

  uint32_t OutputMemoryAddress;                                    
                                                                                
                                                                                    

                                                                                
                                                                                                 

#if defined(DMA2D_OUTPUT_TWO_BY_TWO_SWAP_SUPPORT)
  uint32_t OutputSwapMode;                                                                                  
                                                                                                             

                                                                                
                                                                                                  
#endif                                           

#if defined(DMA2D_LINE_OFFSET_MODE_SUPPORT)
  uint32_t LineOffsetMode;                                                  
                                                                                                             

                                                                                
                                                                                                  
#endif                                     

  uint32_t LineOffset;                                                       
                                                                                
                                                                                        
                                                                                      
                                                                                                            

                                                                                
                                                                                              

  uint32_t NbrOfLines;                                                                            
                                                                                
                                                                                

                                                                                
                                                                                              

  uint32_t NbrOfPixelsPerLines;                                                                              
                                                                                                                        

                                                                                      
                                                                                                 

  uint32_t AlphaInversionMode;                                                  
                                                                                                            

                                                                                
                                                                                                      

  uint32_t RBSwapMode;                                                        
                                                                                                          

                                                                                
                                                                                                    

} LL_DMA2D_InitTypeDef;

   
                                                            
    
typedef struct
{
  uint32_t MemoryAddress;                                                                   
                                                                                
                                                                                    

                                                                                                       
                                                                                             
                                                                                                

  uint32_t LineOffset;                                                                         
                                                                                                                        

                                                                                                       
                                                                                                
                                                                                                   

  uint32_t ColorMode;                                                                   
                                                                                                             

                                                                                                       
                                                                                               
                                                                                                  

  uint32_t CLUTColorMode;                                                                    
                                                                                                             

                                                                                                       
                                                                                                   
                                                                                                      

  uint32_t CLUTSize;                                                                   
                                                                                                                    

                                                                                                       
                                                                                              
                                                                                                 

  uint32_t AlphaMode;                                                                   
                                                                                                        

                                                                                                       
                                                                                               
                                                                                                  

  uint32_t Alpha;                                                                        
                                                                                                                    

                                                                                                       
                                                                                           
                                                                                              

  uint32_t Blue;                                                                              
                                                                                                                    

                                                                                                       
                                                                                               
                                                                                                  

  uint32_t Green;                                                                              
                                                                                                                    

                                                                                                       
                                                                                                
                                                                                                   

  uint32_t Red;                                                                              
                                                                                                                    

                                                                                                       
                                                                                              
                                                                                                 

  uint32_t CLUTMemoryAddress;                                                                    
                                                                                
                                                                                    

                                                                                                       
                                                                                                 
                                                                                                    

  uint32_t AlphaInversionMode;                                                                    
                                                                                                            

                                                                                                       
                                                                                                  
                                                                                                     

  uint32_t RBSwapMode;                                                                          
                                                                                                         

                                                                                                       
                                                                                                
                                                                                                   


} LL_DMA2D_LayerCfgTypeDef;

   
                                                     
    
typedef struct
{
  uint32_t ColorMode;                                                                
                                                                                                              

                                                                                     
                                                                           

  uint32_t OutputBlue;                                                             
                                                                                
                                                                                                               
                                                                                
                                                                                                             
                                                                                
                                                                                                             
                                                                                
                                                                                                               
                                                                                
                                                                                                               

                                                                                      
                                                                                                      
                                                                                    

  uint32_t OutputGreen;                                                             
                                                                                
                                                                                                               
                                                                               
                                                                                                             
                                                                                
                                                                                                             
                                                                                
                                                                                                               
                                                                                
                                                                                                               

                                                                                
                                                                                                            
                                                                                    

  uint32_t OutputRed;                                                             
                                                                                
                                                                                                               
                                                                                
                                                                                                             
                                                                                
                                                                                                             
                                                                                
                                                                                                               
                                                                                
                                                                                                               

                                                                                
                                                                                                            
                                                                                    

  uint32_t OutputAlpha;                                                               
                                                                                
                                                                                                               
                                                                                
                                                                                                               
                                                                                
                                                                                                               
                                                                                                                    

                                                                                
                                                                                                            
                                                                                    

} LL_DMA2D_ColorTypeDef;

   
      
    
#endif                         

                                                                                
                                                                  
      
    

                                                    
                                                                            
      
    
#define LL_DMA2D_FLAG_CEIF          DMA2D_ISR_CEIF                                               
#define LL_DMA2D_FLAG_CTCIF         DMA2D_ISR_CTCIF                                                 
#define LL_DMA2D_FLAG_CAEIF         DMA2D_ISR_CAEIF                                            
#define LL_DMA2D_FLAG_TWIF          DMA2D_ISR_TWIF                                              
#define LL_DMA2D_FLAG_TCIF          DMA2D_ISR_TCIF                                             
#define LL_DMA2D_FLAG_TEIF          DMA2D_ISR_TEIF                                          
   
      
    

                                       
                                                                                                 
      
    
#define LL_DMA2D_IT_CEIE             DMA2D_CR_CEIE                                         
#define LL_DMA2D_IT_CTCIE            DMA2D_CR_CTCIE                                           
#define LL_DMA2D_IT_CAEIE            DMA2D_CR_CAEIE                                      
#define LL_DMA2D_IT_TWIE             DMA2D_CR_TWIE                                        
#define LL_DMA2D_IT_TCIE             DMA2D_CR_TCIE                                       
#define LL_DMA2D_IT_TEIE             DMA2D_CR_TEIE                                    
   
      
    

                                   
      
    
#define LL_DMA2D_MODE_M2M                       0x00000000U                                                                   
#define LL_DMA2D_MODE_M2M_PFC                   DMA2D_CR_MODE_0                                                                                            
#define LL_DMA2D_MODE_M2M_BLEND                 DMA2D_CR_MODE_1                                                                             
#define LL_DMA2D_MODE_R2M                       (DMA2D_CR_MODE_0|DMA2D_CR_MODE_1)                                               
#if defined(DMA2D_M2M_BLEND_FIXED_COLOR_FG_BG_SUPPORT)
#define LL_DMA2D_MODE_M2M_BLEND_FIXED_COLOR_FG  DMA2D_CR_MODE_2                                                                                                        
#define LL_DMA2D_MODE_M2M_BLEND_FIXED_COLOR_BG  (DMA2D_CR_MODE_0|DMA2D_CR_MODE_2)                                                                                      
#endif                                                
   
      
    

                                                             
      
    
#define LL_DMA2D_OUTPUT_MODE_ARGB8888     0x00000000U                                           
#define LL_DMA2D_OUTPUT_MODE_RGB888       DMA2D_OPFCCR_CM_0                                     
#define LL_DMA2D_OUTPUT_MODE_RGB565       DMA2D_OPFCCR_CM_1                                     
#define LL_DMA2D_OUTPUT_MODE_ARGB1555     (DMA2D_OPFCCR_CM_0|DMA2D_OPFCCR_CM_1)                 
#define LL_DMA2D_OUTPUT_MODE_ARGB4444     DMA2D_OPFCCR_CM_2                                     
   
      
    

                                                           
      
    
#define LL_DMA2D_INPUT_MODE_ARGB8888      0x00000000U                                                                
#define LL_DMA2D_INPUT_MODE_RGB888        DMA2D_FGPFCCR_CM_0                                                         
#define LL_DMA2D_INPUT_MODE_RGB565        DMA2D_FGPFCCR_CM_1                                                         
#define LL_DMA2D_INPUT_MODE_ARGB1555      (DMA2D_FGPFCCR_CM_0|DMA2D_FGPFCCR_CM_1)                                    
#define LL_DMA2D_INPUT_MODE_ARGB4444      DMA2D_FGPFCCR_CM_2                                                         
#define LL_DMA2D_INPUT_MODE_L8            (DMA2D_FGPFCCR_CM_0|DMA2D_FGPFCCR_CM_2)                                    
#define LL_DMA2D_INPUT_MODE_AL44          (DMA2D_FGPFCCR_CM_1|DMA2D_FGPFCCR_CM_2)                                    
#define LL_DMA2D_INPUT_MODE_AL88          (DMA2D_FGPFCCR_CM_0|DMA2D_FGPFCCR_CM_1|DMA2D_FGPFCCR_CM_2)                 
#define LL_DMA2D_INPUT_MODE_L4            DMA2D_FGPFCCR_CM_3                                                         
#define LL_DMA2D_INPUT_MODE_A8            (DMA2D_FGPFCCR_CM_0|DMA2D_FGPFCCR_CM_3)                                    
#define LL_DMA2D_INPUT_MODE_A4            (DMA2D_FGPFCCR_CM_1|DMA2D_FGPFCCR_CM_3)                                    
   
      
    

                                               
      
    
#define LL_DMA2D_ALPHA_MODE_NO_MODIF       0x00000000U                                                               
#define LL_DMA2D_ALPHA_MODE_REPLACE        DMA2D_FGPFCCR_AM_0                                                  
                                                                                                                     
#define LL_DMA2D_ALPHA_MODE_COMBINE        DMA2D_FGPFCCR_AM_1                                                  
                                                                                                    
                                                                                                                     
   
      
    

#if defined(DMA2D_OUTPUT_TWO_BY_TWO_SWAP_SUPPORT)
                                                    
      
    
#define LL_DMA2D_SWAP_MODE_REGULAR        0x00000000U                                           
#define LL_DMA2D_SWAP_MODE_TWO_BY_TWO     DMA2D_OPFCCR_SB                                                  
   
      
    
#endif                                           

                                                     
      
    
#define LL_DMA2D_RB_MODE_REGULAR          0x00000000U                                         
#define LL_DMA2D_RB_MODE_SWAP             DMA2D_FGPFCCR_RBS                                   
   
      
    

                                                         
      
    
#define LL_DMA2D_ALPHA_REGULAR          0x00000000U                                           
#define LL_DMA2D_ALPHA_INVERTED         DMA2D_FGPFCCR_AI                                      
   
      
    


#if defined(DMA2D_LINE_OFFSET_MODE_SUPPORT)
                                                           
      
    
#define LL_DMA2D_LINE_OFFSET_PIXELS     0x00000000U                                                                  
#define LL_DMA2D_LINE_OFFSET_BYTES      DMA2D_CR_LOM                                                                 
   
      
    
#endif                                     

                                                         
      
    
#define LL_DMA2D_CLUT_COLOR_MODE_ARGB8888          0x00000000U                                     
#define LL_DMA2D_CLUT_COLOR_MODE_RGB888            DMA2D_FGPFCCR_CCM                               
   
      
    


   
      
    

                                                                                
                                                            
      
    

                                                                           
      
    

   
                                            
                                       
                                          
                                                         
                
    
#define LL_DMA2D_WriteReg(__INSTANCE__, __REG__, __VALUE__) WRITE_REG((__INSTANCE__)->__REG__, (__VALUE__))

   
                                           
                                       
                                       
                          
    
#define LL_DMA2D_ReadReg(__INSTANCE__, __REG__) READ_REG((__INSTANCE__)->__REG__)
   
      
    

   
      
    

                                                                                
                                                                  
      
    

                                                               
      
    

   
                                   
                                                       
                                 
                
    
__STATIC_INLINE void LL_DMA2D_Start(DMA2D_TypeDef *DMA2Dx)
{
  SET_BIT(DMA2Dx->CR, DMA2D_CR_START);
}

   
                                                    
                                                                   
                                 
                                  
    
__STATIC_INLINE uint32_t LL_DMA2D_IsTransferOngoing(const DMA2D_TypeDef *DMA2Dx)
{
  return ((READ_BIT(DMA2Dx->CR, DMA2D_CR_START) == (DMA2D_CR_START)) ? 1UL : 0UL);
}

   
                                   
                                                                                            
                                                        
                                 
                
    
__STATIC_INLINE void LL_DMA2D_Suspend(DMA2D_TypeDef *DMA2Dx)
{
  MODIFY_REG(DMA2Dx->CR, DMA2D_CR_SUSP | DMA2D_CR_START, DMA2D_CR_SUSP);
}

   
                                  
                                                                                           
                                                       
                                 
                
    
__STATIC_INLINE void LL_DMA2D_Resume(DMA2D_TypeDef *DMA2Dx)
{
  CLEAR_BIT(DMA2Dx->CR, DMA2D_CR_SUSP | DMA2D_CR_START);
}

   
                                                    
                                                                                   
                                                 
                                                            
                                 
                                  
    
__STATIC_INLINE uint32_t LL_DMA2D_IsSuspended(const DMA2D_TypeDef *DMA2Dx)
{
  return ((READ_BIT(DMA2Dx->CR, DMA2D_CR_SUSP) == (DMA2D_CR_SUSP)) ? 1UL : 0UL);
}

   
                                 
                                                                                          
                                                       
                                 
                
    
__STATIC_INLINE void LL_DMA2D_Abort(DMA2D_TypeDef *DMA2Dx)
{
  MODIFY_REG(DMA2Dx->CR, DMA2D_CR_ABORT | DMA2D_CR_START, DMA2D_CR_ABORT);
}

   
                                                  
                                                                                   
                                               
                                                           
                                 
                                  
    
__STATIC_INLINE uint32_t LL_DMA2D_IsAborted(const DMA2D_TypeDef *DMA2Dx)
{
  return ((READ_BIT(DMA2Dx->CR, DMA2D_CR_ABORT) == (DMA2D_CR_ABORT)) ? 1UL : 0UL);
}

   
                           
                                                      
                                 
                                                                   
                                       
                                           
                                             
                                       
                                                                
                                                                
   
                                                 
                
    
__STATIC_INLINE void LL_DMA2D_SetMode(DMA2D_TypeDef *DMA2Dx, uint32_t Mode)
{
  MODIFY_REG(DMA2Dx->CR, DMA2D_CR_MODE, Mode);
}

   
                             
                                                     
                                 
                                                              
                                       
                                           
                                             
                                       
                                                                
                                                                
   
                                                 
    
__STATIC_INLINE uint32_t LL_DMA2D_GetMode(const DMA2D_TypeDef *DMA2Dx)
{
  return (uint32_t)(READ_BIT(DMA2Dx->CR, DMA2D_CR_MODE));
}

   
                                        
                                                                   
                                 
                                                                        
                                                   
                                                 
                                                 
                                                   
                                                   
                
    
__STATIC_INLINE void LL_DMA2D_SetOutputColorMode(DMA2D_TypeDef *DMA2Dx, uint32_t ColorMode)
{
  MODIFY_REG(DMA2Dx->OPFCCR, DMA2D_OPFCCR_CM, ColorMode);
}

   
                                           
                                                                  
                                 
                                                              
                                                   
                                                 
                                                 
                                                   
                                                   
    
__STATIC_INLINE uint32_t LL_DMA2D_GetOutputColorMode(const DMA2D_TypeDef *DMA2Dx)
{
  return (uint32_t)(READ_BIT(DMA2Dx->OPFCCR, DMA2D_OPFCCR_CM));
}

   
                                                
                                                                     
                                 
                                                                         
                                              
                                           
                
    
__STATIC_INLINE void LL_DMA2D_SetOutputRBSwapMode(DMA2D_TypeDef *DMA2Dx, uint32_t RBSwapMode)
{
  MODIFY_REG(DMA2Dx->OPFCCR, DMA2D_OPFCCR_RBS, RBSwapMode);
}

   
                                                   
                                                                    
                                 
                                                              
                                              
                                           
    
__STATIC_INLINE uint32_t LL_DMA2D_GetOutputRBSwapMode(const DMA2D_TypeDef *DMA2Dx)
{
  return (uint32_t)(READ_BIT(DMA2Dx->OPFCCR, DMA2D_OPFCCR_RBS));
}

   
                                                  
                                                                      
                                 
                                                                                 
                                            
                                             
                
    
__STATIC_INLINE void LL_DMA2D_SetOutputAlphaInvMode(DMA2D_TypeDef *DMA2Dx, uint32_t AlphaInversionMode)
{
  MODIFY_REG(DMA2Dx->OPFCCR, DMA2D_OPFCCR_AI, AlphaInversionMode);
}

   
                                                     
                                                                     
                                 
                                                              
                                            
                                             
    
__STATIC_INLINE uint32_t LL_DMA2D_GetOutputAlphaInvMode(const DMA2D_TypeDef *DMA2Dx)
{
  return (uint32_t)(READ_BIT(DMA2Dx->OPFCCR, DMA2D_OPFCCR_AI));
}


#if defined(DMA2D_OUTPUT_TWO_BY_TWO_SWAP_SUPPORT)
   
                                       
                                                                  
                                 
                                                                             
                                                
                                                   
                
    
__STATIC_INLINE void LL_DMA2D_SetOutputSwapMode(DMA2D_TypeDef *DMA2Dx, uint32_t OutputSwapMode)
{
  MODIFY_REG(DMA2Dx->OPFCCR, DMA2D_OPFCCR_SB, OutputSwapMode);
}

   
                                          
                                                                 
                                 
                                                              
                                                
                                                   
    
__STATIC_INLINE uint32_t LL_DMA2D_GetOutputSwapMode(DMA2D_TypeDef *DMA2Dx)
{
  return (uint32_t)(READ_BIT(DMA2Dx->OPFCCR, DMA2D_OPFCCR_SB));
}
#endif                                           

#if defined(DMA2D_LINE_OFFSET_MODE_SUPPORT)
   
                                       
                                                               
                                 
                                                                             
                                                 
                                                
                
    
__STATIC_INLINE void LL_DMA2D_SetLineOffsetMode(DMA2D_TypeDef *DMA2Dx, uint32_t LineOffsetMode)
{
  MODIFY_REG(DMA2Dx->CR, DMA2D_CR_LOM, LineOffsetMode);
}

   
                                          
                                                              
                                 
                                                              
                                                 
                                                
    
__STATIC_INLINE uint32_t LL_DMA2D_GetLineOffsetMode(const DMA2D_TypeDef *DMA2Dx)
{
  return (uint32_t)(READ_BIT(DMA2Dx->CR, DMA2D_CR_LOM));
}
#endif                                     

   
                                                                      
                                                           
                                 
                                    
                                                                   
       
                                                                   
        
                
    
__STATIC_INLINE void LL_DMA2D_SetLineOffset(DMA2D_TypeDef *DMA2Dx, uint32_t LineOffset)
{
  MODIFY_REG(DMA2Dx->OOR, DMA2D_OOR_LO, LineOffset);
}

   
                                                                         
                                                          
                                 
                                    
                                                                    
       
                                                                    
        
    
__STATIC_INLINE uint32_t LL_DMA2D_GetLineOffset(const DMA2D_TypeDef *DMA2Dx)
{
  return (uint32_t)(READ_BIT(DMA2Dx->OOR, DMA2D_OOR_LO));
}

   
                                                                                     
                                                                    
                                 
                                                                            
                
    
__STATIC_INLINE void LL_DMA2D_SetNbrOfPixelsPerLines(DMA2D_TypeDef *DMA2Dx, uint32_t NbrOfPixelsPerLines)
{
  MODIFY_REG(DMA2Dx->NLR, DMA2D_NLR_PL, (NbrOfPixelsPerLines << DMA2D_NLR_PL_Pos));
}

   
                                                                                       
                                                                    
                                 
                                                                                   
    
__STATIC_INLINE uint32_t LL_DMA2D_GetNbrOfPixelsPerLines(const DMA2D_TypeDef *DMA2Dx)
{
  return (uint32_t)(READ_BIT(DMA2Dx->NLR, DMA2D_NLR_PL) >> DMA2D_NLR_PL_Pos);
}

   
                                                                          
                                                           
                                 
                                                                   
                
    
__STATIC_INLINE void LL_DMA2D_SetNbrOfLines(DMA2D_TypeDef *DMA2Dx, uint32_t NbrOfLines)
{
  MODIFY_REG(DMA2Dx->NLR, DMA2D_NLR_NL, NbrOfLines);
}

   
                                                                             
                                                           
                                 
                                                                        
    
__STATIC_INLINE uint32_t LL_DMA2D_GetNbrOfLines(const DMA2D_TypeDef *DMA2Dx)
{
  return (uint32_t)(READ_BIT(DMA2Dx->NLR, DMA2D_NLR_NL));
}

   
                                                                                
                                                               
                                 
                                                                                
                
    
__STATIC_INLINE void LL_DMA2D_SetOutputMemAddr(DMA2D_TypeDef *DMA2Dx, uint32_t OutputMemoryAddress)
{
  LL_DMA2D_WriteReg(DMA2Dx, OMAR, OutputMemoryAddress);
}

   
                                                                                
                                                               
                                 
                                                                                  
    
__STATIC_INLINE uint32_t LL_DMA2D_GetOutputMemAddr(const DMA2D_TypeDef *DMA2Dx)
{
  return (uint32_t)(LL_DMA2D_ReadReg(DMA2Dx, OMAR));
}

   
                                                                       
                                                                               
                                         
                                                                                          
                                                                  
                                                              
                                                              
                                                              
                                                            
                                 
                                                                        
                
    
__STATIC_INLINE void LL_DMA2D_SetOutputColor(DMA2D_TypeDef *DMA2Dx, uint32_t OutputColor)
{
  WRITE_REG(DMA2Dx->OCOLR, OutputColor);
}

   
                                                                       
                                                                                               
                                                                                                  
                                                       
                                                              
                                                              
                                                              
                                                            
                                 
                                                                         
    
__STATIC_INLINE uint32_t LL_DMA2D_GetOutputColor(const DMA2D_TypeDef *DMA2Dx)
{
  return (uint32_t)(READ_BIT(DMA2Dx->OCOLR, \
                             (DMA2D_OCOLR_BLUE_1 | DMA2D_OCOLR_GREEN_1 | DMA2D_OCOLR_RED_1 | DMA2D_OCOLR_ALPHA_1)));
}

   
                                                                         
                                                              
                                 
                                                                      
                
    
__STATIC_INLINE void LL_DMA2D_SetLineWatermark(DMA2D_TypeDef *DMA2Dx, uint32_t LineWatermark)
{
  MODIFY_REG(DMA2Dx->LWR, DMA2D_LWR_LW, LineWatermark);
}

   
                                                                            
                                                              
                                 
                                                                       
    
__STATIC_INLINE uint32_t LL_DMA2D_GetLineWatermark(const DMA2D_TypeDef *DMA2Dx)
{
  return (uint32_t)(READ_BIT(DMA2Dx->LWR, DMA2D_LWR_LW));
}

   
                                                                  
                                                           
                                 
                                                               
                
    
__STATIC_INLINE void LL_DMA2D_SetDeadTime(DMA2D_TypeDef *DMA2Dx, uint32_t DeadTime)
{
  MODIFY_REG(DMA2Dx->AMTCR, DMA2D_AMTCR_DT, (DeadTime << DMA2D_AMTCR_DT_Pos));
}

   
                                                                     
                                                           
                                 
                                                                
    
__STATIC_INLINE uint32_t LL_DMA2D_GetDeadTime(const DMA2D_TypeDef *DMA2Dx)
{
  return (uint32_t)(READ_BIT(DMA2Dx->AMTCR, DMA2D_AMTCR_DT) >> DMA2D_AMTCR_DT_Pos);
}

   
                                                 
                                                                
                                 
                
    
__STATIC_INLINE void LL_DMA2D_EnableDeadTime(DMA2D_TypeDef *DMA2Dx)
{
  SET_BIT(DMA2Dx->AMTCR, DMA2D_AMTCR_EN);
}

   
                                                  
                                                                 
                                 
                
    
__STATIC_INLINE void LL_DMA2D_DisableDeadTime(DMA2D_TypeDef *DMA2Dx)
{
  CLEAR_BIT(DMA2Dx->AMTCR, DMA2D_AMTCR_EN);
}

   
                                                                 
                                                                   
                                 
                                  
    
__STATIC_INLINE uint32_t LL_DMA2D_IsEnabledDeadTime(const DMA2D_TypeDef *DMA2Dx)
{
  return ((READ_BIT(DMA2Dx->AMTCR, DMA2D_AMTCR_EN) == (DMA2D_AMTCR_EN)) ? 1UL : 0UL);
}

                                                                               
      
    

   
                                                                                    
                                                               
                                 
                                                                          
                
    
__STATIC_INLINE void LL_DMA2D_FGND_SetMemAddr(DMA2D_TypeDef *DMA2Dx, uint32_t MemoryAddress)
{
  LL_DMA2D_WriteReg(DMA2Dx, FGMAR, MemoryAddress);
}

   
                                                                                    
                                                               
                                 
                                                                                      
    
__STATIC_INLINE uint32_t LL_DMA2D_FGND_GetMemAddr(const DMA2D_TypeDef *DMA2Dx)
{
  return (uint32_t)(LL_DMA2D_ReadReg(DMA2Dx, FGMAR));
}

   
                                                 
                                                                          
                                 
                
    
__STATIC_INLINE void LL_DMA2D_FGND_EnableCLUTLoad(DMA2D_TypeDef *DMA2Dx)
{
  SET_BIT(DMA2Dx->FGPFCCR, DMA2D_FGPFCCR_START);
}

   
                                                                 
                                                                             
                                 
                                  
    
__STATIC_INLINE uint32_t LL_DMA2D_FGND_IsEnabledCLUTLoad(const DMA2D_TypeDef *DMA2Dx)
{
  return ((READ_BIT(DMA2Dx->FGPFCCR, DMA2D_FGPFCCR_START) == (DMA2D_FGPFCCR_START)) ? 1UL : 0UL);
}

   
                                            
                                                                   
                                 
                                                                        
                                                  
                                                
                                                
                                                  
                                                  
                                            
                                              
                                              
                                            
                                            
                                            
                
    
__STATIC_INLINE void LL_DMA2D_FGND_SetColorMode(DMA2D_TypeDef *DMA2Dx, uint32_t ColorMode)
{
  MODIFY_REG(DMA2Dx->FGPFCCR, DMA2D_FGPFCCR_CM, ColorMode);
}

   
                                               
                                                                  
                                 
                                                              
                                                  
                                                
                                                
                                                  
                                                  
                                            
                                              
                                              
                                            
                                            
                                            
    
__STATIC_INLINE uint32_t LL_DMA2D_FGND_GetColorMode(const DMA2D_TypeDef *DMA2Dx)
{
  return (uint32_t)(READ_BIT(DMA2Dx->FGPFCCR, DMA2D_FGPFCCR_CM));
}

   
                                            
                                                                   
                                 
                                                                       
                                                  
                                                 
                                                 
                
    
__STATIC_INLINE void LL_DMA2D_FGND_SetAlphaMode(DMA2D_TypeDef *DMA2Dx, uint32_t AphaMode)
{
  MODIFY_REG(DMA2Dx->FGPFCCR, DMA2D_FGPFCCR_AM, AphaMode);
}

   
                                               
                                                                  
                                 
                                                              
                                                  
                                                 
                                                 
    
__STATIC_INLINE uint32_t LL_DMA2D_FGND_GetAlphaMode(const DMA2D_TypeDef *DMA2Dx)
{
  return (uint32_t)(READ_BIT(DMA2Dx->FGPFCCR, DMA2D_FGPFCCR_AM));
}

   
                                                                               
                                                                  
                                 
                                                            
                
    
__STATIC_INLINE void LL_DMA2D_FGND_SetAlpha(DMA2D_TypeDef *DMA2Dx, uint32_t Alpha)
{
  MODIFY_REG(DMA2Dx->FGPFCCR, DMA2D_FGPFCCR_ALPHA, (Alpha << DMA2D_FGPFCCR_ALPHA_Pos));
}

   
                                                                                  
                                                                 
                                 
                                                            
    
__STATIC_INLINE uint32_t LL_DMA2D_FGND_GetAlpha(const DMA2D_TypeDef *DMA2Dx)
{
  return (uint32_t)(READ_BIT(DMA2Dx->FGPFCCR, DMA2D_FGPFCCR_ALPHA) >> DMA2D_FGPFCCR_ALPHA_Pos);
}

   
                                                    
                                                                     
                                 
                                                                         
                                              
                                           
                
    
__STATIC_INLINE void LL_DMA2D_FGND_SetRBSwapMode(DMA2D_TypeDef *DMA2Dx, uint32_t RBSwapMode)
{
  MODIFY_REG(DMA2Dx->FGPFCCR, DMA2D_FGPFCCR_RBS, RBSwapMode);
}

   
                                                       
                                                                    
                                 
                                                              
                                              
                                           
    
__STATIC_INLINE uint32_t LL_DMA2D_FGND_GetRBSwapMode(const DMA2D_TypeDef *DMA2Dx)
{
  return (uint32_t)(READ_BIT(DMA2Dx->FGPFCCR, DMA2D_FGPFCCR_RBS));
}

   
                                                      
                                                                      
                                 
                                                                                 
                                            
                                             
                
    
__STATIC_INLINE void LL_DMA2D_FGND_SetAlphaInvMode(DMA2D_TypeDef *DMA2Dx, uint32_t AlphaInversionMode)
{
  MODIFY_REG(DMA2Dx->FGPFCCR, DMA2D_FGPFCCR_AI, AlphaInversionMode);
}

   
                                                         
                                                                     
                                 
                                                              
                                            
                                             
    
__STATIC_INLINE uint32_t LL_DMA2D_FGND_GetAlphaInvMode(const DMA2D_TypeDef *DMA2Dx)
{
  return (uint32_t)(READ_BIT(DMA2Dx->FGPFCCR, DMA2D_FGPFCCR_AI));
}

   
                                                                                 
                                                                 
                                 
                                                                  
                
    
__STATIC_INLINE void LL_DMA2D_FGND_SetLineOffset(DMA2D_TypeDef *DMA2Dx, uint32_t LineOffset)
{
  MODIFY_REG(DMA2Dx->FGOR, DMA2D_FGOR_LO, LineOffset);
}

   
                                                                                    
                                                                
                                 
                                                                              
    
__STATIC_INLINE uint32_t LL_DMA2D_FGND_GetLineOffset(const DMA2D_TypeDef *DMA2Dx)
{
  return (uint32_t)(READ_BIT(DMA2Dx->FGOR, DMA2D_FGOR_LO));
}

   
                                                                                  
                                                               
                                                               
                                                               
                                 
                                                            
                                                            
                                                            
                
    
__STATIC_INLINE void LL_DMA2D_FGND_SetColor(DMA2D_TypeDef *DMA2Dx, uint32_t Red, uint32_t Green, uint32_t Blue)
{
  MODIFY_REG(DMA2Dx->FGCOLR, (DMA2D_FGCOLR_RED | DMA2D_FGCOLR_GREEN | DMA2D_FGCOLR_BLUE), \
             ((Red << DMA2D_FGCOLR_RED_Pos) | (Green << DMA2D_FGCOLR_GREEN_Pos) | Blue));
}

   
                                                                                   
                                                                  
                                 
                                                          
                
    
__STATIC_INLINE void LL_DMA2D_FGND_SetRedColor(DMA2D_TypeDef *DMA2Dx, uint32_t Red)
{
  MODIFY_REG(DMA2Dx->FGCOLR, DMA2D_FGCOLR_RED, (Red << DMA2D_FGCOLR_RED_Pos));
}

   
                                                                                      
                                                                 
                                 
                                                                
    
__STATIC_INLINE uint32_t LL_DMA2D_FGND_GetRedColor(const DMA2D_TypeDef *DMA2Dx)
{
  return (uint32_t)(READ_BIT(DMA2Dx->FGCOLR, DMA2D_FGCOLR_RED) >> DMA2D_FGCOLR_RED_Pos);
}

   
                                                                                     
                                                                      
                                 
                                                            
                
    
__STATIC_INLINE void LL_DMA2D_FGND_SetGreenColor(DMA2D_TypeDef *DMA2Dx, uint32_t Green)
{
  MODIFY_REG(DMA2Dx->FGCOLR, DMA2D_FGCOLR_GREEN, (Green << DMA2D_FGCOLR_GREEN_Pos));
}

   
                                                                                        
                                                                     
                                 
                                                                  
    
__STATIC_INLINE uint32_t LL_DMA2D_FGND_GetGreenColor(const DMA2D_TypeDef *DMA2Dx)
{
  return (uint32_t)(READ_BIT(DMA2Dx->FGCOLR, DMA2D_FGCOLR_GREEN) >> DMA2D_FGCOLR_GREEN_Pos);
}

   
                                                                                    
                                                                    
                                 
                                                           
                
    
__STATIC_INLINE void LL_DMA2D_FGND_SetBlueColor(DMA2D_TypeDef *DMA2Dx, uint32_t Blue)
{
  MODIFY_REG(DMA2Dx->FGCOLR, DMA2D_FGCOLR_BLUE, Blue);
}

   
                                                                                       
                                                                   
                                 
                                                                 
    
__STATIC_INLINE uint32_t LL_DMA2D_FGND_GetBlueColor(const DMA2D_TypeDef *DMA2Dx)
{
  return (uint32_t)(READ_BIT(DMA2Dx->FGCOLR, DMA2D_FGCOLR_BLUE));
}

   
                                                                                         
                                                                    
                                 
                                                                              
                
    
__STATIC_INLINE void LL_DMA2D_FGND_SetCLUTMemAddr(DMA2D_TypeDef *DMA2Dx, uint32_t CLUTMemoryAddress)
{
  LL_DMA2D_WriteReg(DMA2Dx, FGCMAR, CLUTMemoryAddress);
}

   
                                                                                         
                                                                    
                                 
                                                                                           
    
__STATIC_INLINE uint32_t LL_DMA2D_FGND_GetCLUTMemAddr(const DMA2D_TypeDef *DMA2Dx)
{
  return (uint32_t)(LL_DMA2D_ReadReg(DMA2Dx, FGCMAR));
}

   
                                                                             
                                                                  
                                 
                                                               
                
    
__STATIC_INLINE void LL_DMA2D_FGND_SetCLUTSize(DMA2D_TypeDef *DMA2Dx, uint32_t CLUTSize)
{
  MODIFY_REG(DMA2Dx->FGPFCCR, DMA2D_FGPFCCR_CS, (CLUTSize << DMA2D_FGPFCCR_CS_Pos));
}

   
                                                                             
                                                                  
                                 
                                                                           
    
__STATIC_INLINE uint32_t LL_DMA2D_FGND_GetCLUTSize(const DMA2D_TypeDef *DMA2Dx)
{
  return (uint32_t)(READ_BIT(DMA2Dx->FGPFCCR, DMA2D_FGPFCCR_CS) >> DMA2D_FGPFCCR_CS_Pos);
}

   
                                                 
                                                                        
                                 
                                                                            
                                                       
                                                     
                
    
__STATIC_INLINE void LL_DMA2D_FGND_SetCLUTColorMode(DMA2D_TypeDef *DMA2Dx, uint32_t CLUTColorMode)
{
  MODIFY_REG(DMA2Dx->FGPFCCR, DMA2D_FGPFCCR_CCM, CLUTColorMode);
}

   
                                                    
                                                                       
                                 
                                                              
                                                       
                                                     
    
__STATIC_INLINE uint32_t LL_DMA2D_FGND_GetCLUTColorMode(const DMA2D_TypeDef *DMA2Dx)
{
  return (uint32_t)(READ_BIT(DMA2Dx->FGPFCCR, DMA2D_FGPFCCR_CCM));
}

   
      
    

                                                                               
      
    

   
                                                                                    
                                                               
                                 
                                                                          
                
    
__STATIC_INLINE void LL_DMA2D_BGND_SetMemAddr(DMA2D_TypeDef *DMA2Dx, uint32_t MemoryAddress)
{
  LL_DMA2D_WriteReg(DMA2Dx, BGMAR, MemoryAddress);
}

   
                                                                                    
                                                               
                                 
                                                                                      
    
__STATIC_INLINE uint32_t LL_DMA2D_BGND_GetMemAddr(const DMA2D_TypeDef *DMA2Dx)
{
  return (uint32_t)(LL_DMA2D_ReadReg(DMA2Dx, BGMAR));
}

   
                                                 
                                                                          
                                 
                
    
__STATIC_INLINE void LL_DMA2D_BGND_EnableCLUTLoad(DMA2D_TypeDef *DMA2Dx)
{
  SET_BIT(DMA2Dx->BGPFCCR, DMA2D_BGPFCCR_START);
}

   
                                                                 
                                                                             
                                 
                                  
    
__STATIC_INLINE uint32_t LL_DMA2D_BGND_IsEnabledCLUTLoad(const DMA2D_TypeDef *DMA2Dx)
{
  return ((READ_BIT(DMA2Dx->BGPFCCR, DMA2D_BGPFCCR_START) == (DMA2D_BGPFCCR_START)) ? 1UL : 0UL);
}

   
                                            
                                                                   
                                 
                                                                        
                                                  
                                                
                                                
                                                  
                                                  
                                            
                                              
                                              
                                            
                                            
                                            
                
    
__STATIC_INLINE void LL_DMA2D_BGND_SetColorMode(DMA2D_TypeDef *DMA2Dx, uint32_t ColorMode)
{
  MODIFY_REG(DMA2Dx->BGPFCCR, DMA2D_BGPFCCR_CM, ColorMode);
}

   
                                               
                                                                   
                                 
                                                              
                                                  
                                                
                                                
                                                  
                                                  
                                            
                                              
                                              
                                            
                                            
                                            
    
__STATIC_INLINE uint32_t  LL_DMA2D_BGND_GetColorMode(const DMA2D_TypeDef *DMA2Dx)
{
  return (uint32_t)(READ_BIT(DMA2Dx->BGPFCCR, DMA2D_BGPFCCR_CM));
}

   
                                            
                                                                  
                                 
                                                                       
                                                  
                                                 
                                                 
                
    
__STATIC_INLINE void LL_DMA2D_BGND_SetAlphaMode(DMA2D_TypeDef *DMA2Dx, uint32_t AphaMode)
{
  MODIFY_REG(DMA2Dx->BGPFCCR, DMA2D_BGPFCCR_AM, AphaMode);
}

   
                                               
                                                                   
                                 
                                                              
                                                  
                                                 
                                                 
    
__STATIC_INLINE uint32_t  LL_DMA2D_BGND_GetAlphaMode(const DMA2D_TypeDef *DMA2Dx)
{
  return (uint32_t)(READ_BIT(DMA2Dx->BGPFCCR, DMA2D_BGPFCCR_AM));
}

   
                                                                               
                                                                 
                                 
                                                            
                
    
__STATIC_INLINE void LL_DMA2D_BGND_SetAlpha(DMA2D_TypeDef *DMA2Dx, uint32_t Alpha)
{
  MODIFY_REG(DMA2Dx->BGPFCCR, DMA2D_BGPFCCR_ALPHA, (Alpha << DMA2D_BGPFCCR_ALPHA_Pos));
}

   
                                                                                  
                                                                  
                                 
                                                            
    
__STATIC_INLINE uint32_t  LL_DMA2D_BGND_GetAlpha(const DMA2D_TypeDef *DMA2Dx)
{
  return (uint32_t)(READ_BIT(DMA2Dx->BGPFCCR, DMA2D_BGPFCCR_ALPHA) >> DMA2D_BGPFCCR_ALPHA_Pos);
}

   
                                                    
                                                                    
                                 
                                                                         
                                              
                                           
                
    
__STATIC_INLINE void LL_DMA2D_BGND_SetRBSwapMode(DMA2D_TypeDef *DMA2Dx, uint32_t RBSwapMode)
{
  MODIFY_REG(DMA2Dx->BGPFCCR, DMA2D_BGPFCCR_RBS, RBSwapMode);
}

   
                                                       
                                                                     
                                 
                                                              
                                              
                                           
    
__STATIC_INLINE uint32_t  LL_DMA2D_BGND_GetRBSwapMode(const DMA2D_TypeDef *DMA2Dx)
{
  return (uint32_t)(READ_BIT(DMA2Dx->BGPFCCR, DMA2D_BGPFCCR_RBS));
}

   
                                                      
                                                                     
                                 
                                                                                 
                                            
                                             
                
    
__STATIC_INLINE void LL_DMA2D_BGND_SetAlphaInvMode(DMA2D_TypeDef *DMA2Dx, uint32_t AlphaInversionMode)
{
  MODIFY_REG(DMA2Dx->BGPFCCR, DMA2D_BGPFCCR_AI, AlphaInversionMode);
}

   
                                                         
                                                                      
                                 
                                                              
                                            
                                             
    
__STATIC_INLINE uint32_t  LL_DMA2D_BGND_GetAlphaInvMode(const DMA2D_TypeDef *DMA2Dx)
{
  return (uint32_t)(READ_BIT(DMA2Dx->BGPFCCR, DMA2D_BGPFCCR_AI));
}

   
                                                                                 
                                                                
                                 
                                                                  
                
    
__STATIC_INLINE void LL_DMA2D_BGND_SetLineOffset(DMA2D_TypeDef *DMA2Dx, uint32_t LineOffset)
{
  MODIFY_REG(DMA2Dx->BGOR, DMA2D_BGOR_LO, LineOffset);
}

   
                                                                                    
                                                                 
                                 
                                                                              
    
__STATIC_INLINE uint32_t  LL_DMA2D_BGND_GetLineOffset(const DMA2D_TypeDef *DMA2Dx)
{
  return (uint32_t)(READ_BIT(DMA2Dx->BGOR, DMA2D_BGOR_LO));
}

   
                                                                                  
                                                               
                                                               
                                                               
                                 
                                                            
                                                            
                                                            
                
    
__STATIC_INLINE void LL_DMA2D_BGND_SetColor(DMA2D_TypeDef *DMA2Dx, uint32_t Red, uint32_t Green, uint32_t Blue)
{
  MODIFY_REG(DMA2Dx->BGCOLR, (DMA2D_BGCOLR_RED | DMA2D_BGCOLR_GREEN | DMA2D_BGCOLR_BLUE), \
             ((Red << DMA2D_BGCOLR_RED_Pos) | (Green << DMA2D_BGCOLR_GREEN_Pos) | Blue));
}

   
                                                                                   
                                                                 
                                 
                                                          
                
    
__STATIC_INLINE void LL_DMA2D_BGND_SetRedColor(DMA2D_TypeDef *DMA2Dx, uint32_t Red)
{
  MODIFY_REG(DMA2Dx->BGCOLR, DMA2D_BGCOLR_RED, (Red << DMA2D_BGCOLR_RED_Pos));
}

   
                                                                                      
                                                                  
                                 
                                                                
    
__STATIC_INLINE uint32_t  LL_DMA2D_BGND_GetRedColor(const DMA2D_TypeDef *DMA2Dx)
{
  return (uint32_t)(READ_BIT(DMA2Dx->BGCOLR, DMA2D_BGCOLR_RED) >> DMA2D_BGCOLR_RED_Pos);
}

   
                                                                                     
                                                                     
                                 
                                                            
                
    
__STATIC_INLINE void LL_DMA2D_BGND_SetGreenColor(DMA2D_TypeDef *DMA2Dx, uint32_t Green)
{
  MODIFY_REG(DMA2Dx->BGCOLR, DMA2D_BGCOLR_GREEN, (Green << DMA2D_BGCOLR_GREEN_Pos));
}

   
                                                                                        
                                                                      
                                 
                                                                  
    
__STATIC_INLINE uint32_t  LL_DMA2D_BGND_GetGreenColor(const DMA2D_TypeDef *DMA2Dx)
{
  return (uint32_t)(READ_BIT(DMA2Dx->BGCOLR, DMA2D_BGCOLR_GREEN) >> DMA2D_BGCOLR_GREEN_Pos);
}

   
                                                                                    
                                                                   
                                 
                                                           
                
    
__STATIC_INLINE void LL_DMA2D_BGND_SetBlueColor(DMA2D_TypeDef *DMA2Dx, uint32_t Blue)
{
  MODIFY_REG(DMA2Dx->BGCOLR, DMA2D_BGCOLR_BLUE, Blue);
}

   
                                                                                       
                                                                    
                                 
                                                                 
    
__STATIC_INLINE uint32_t  LL_DMA2D_BGND_GetBlueColor(const DMA2D_TypeDef *DMA2Dx)
{
  return (uint32_t)(READ_BIT(DMA2Dx->BGCOLR, DMA2D_BGCOLR_BLUE));
}

   
                                                                                         
                                                                   
                                 
                                                                              
                
    
__STATIC_INLINE void LL_DMA2D_BGND_SetCLUTMemAddr(DMA2D_TypeDef *DMA2Dx, uint32_t CLUTMemoryAddress)
{
  LL_DMA2D_WriteReg(DMA2Dx, BGCMAR, CLUTMemoryAddress);
}

   
                                                                                         
                                                                     
                                 
                                                                                           
    
__STATIC_INLINE uint32_t  LL_DMA2D_BGND_GetCLUTMemAddr(const DMA2D_TypeDef *DMA2Dx)
{
  return (uint32_t)(LL_DMA2D_ReadReg(DMA2Dx, BGCMAR));
}

   
                                                                             
                                                                 
                                 
                                                               
                
    
__STATIC_INLINE void LL_DMA2D_BGND_SetCLUTSize(DMA2D_TypeDef *DMA2Dx, uint32_t CLUTSize)
{
  MODIFY_REG(DMA2Dx->BGPFCCR, DMA2D_BGPFCCR_CS, (CLUTSize << DMA2D_BGPFCCR_CS_Pos));
}

   
                                                                             
                                                                   
                                 
                                                                           
    
__STATIC_INLINE uint32_t  LL_DMA2D_BGND_GetCLUTSize(const DMA2D_TypeDef *DMA2Dx)
{
  return (uint32_t)(READ_BIT(DMA2Dx->BGPFCCR, DMA2D_BGPFCCR_CS) >> DMA2D_BGPFCCR_CS_Pos);
}

   
                                                 
                                                                       
                                 
                                                                            
                                                       
                                                     
                
    
__STATIC_INLINE void LL_DMA2D_BGND_SetCLUTColorMode(DMA2D_TypeDef *DMA2Dx, uint32_t CLUTColorMode)
{
  MODIFY_REG(DMA2Dx->BGPFCCR, DMA2D_BGPFCCR_CCM, CLUTColorMode);
}

   
                                                    
                                                                        
                                 
                                                              
                                                       
                                                     
    
__STATIC_INLINE uint32_t  LL_DMA2D_BGND_GetCLUTColorMode(const DMA2D_TypeDef *DMA2Dx)
{
  return (uint32_t)(READ_BIT(DMA2Dx->BGPFCCR, DMA2D_BGPFCCR_CCM));
}

   
      
    

   
      
    


                                                         
      
    

   
                                                                               
                                                                 
                                 
                                  
    
__STATIC_INLINE uint32_t LL_DMA2D_IsActiveFlag_CE(const DMA2D_TypeDef *DMA2Dx)
{
  return ((READ_BIT(DMA2Dx->ISR, DMA2D_ISR_CEIF) == (DMA2D_ISR_CEIF)) ? 1UL : 0UL);
}

   
                                                                                  
                                                                   
                                 
                                  
    
__STATIC_INLINE uint32_t LL_DMA2D_IsActiveFlag_CTC(const DMA2D_TypeDef *DMA2Dx)
{
  return ((READ_BIT(DMA2Dx->ISR, DMA2D_ISR_CTCIF) == (DMA2D_ISR_CTCIF)) ? 1UL : 0UL);
}

   
                                                                             
                                                                   
                                 
                                  
    
__STATIC_INLINE uint32_t LL_DMA2D_IsActiveFlag_CAE(const DMA2D_TypeDef *DMA2Dx)
{
  return ((READ_BIT(DMA2Dx->ISR, DMA2D_ISR_CAEIF) == (DMA2D_ISR_CAEIF)) ? 1UL : 0UL);
}

   
                                                                              
                                                                 
                                 
                                  
    
__STATIC_INLINE uint32_t LL_DMA2D_IsActiveFlag_TW(const DMA2D_TypeDef *DMA2Dx)
{
  return ((READ_BIT(DMA2Dx->ISR, DMA2D_ISR_TWIF) == (DMA2D_ISR_TWIF)) ? 1UL : 0UL);
}

   
                                                                             
                                                                 
                                 
                                  
    
__STATIC_INLINE uint32_t LL_DMA2D_IsActiveFlag_TC(const DMA2D_TypeDef *DMA2Dx)
{
  return ((READ_BIT(DMA2Dx->ISR, DMA2D_ISR_TCIF) == (DMA2D_ISR_TCIF)) ? 1UL : 0UL);
}

   
                                                                          
                                                                 
                                 
                                  
    
__STATIC_INLINE uint32_t LL_DMA2D_IsActiveFlag_TE(const DMA2D_TypeDef *DMA2Dx)
{
  return ((READ_BIT(DMA2Dx->ISR, DMA2D_ISR_TEIF) == (DMA2D_ISR_TEIF)) ? 1UL : 0UL);
}

   
                                                          
                                                              
                                 
                
    
__STATIC_INLINE void LL_DMA2D_ClearFlag_CE(DMA2D_TypeDef *DMA2Dx)
{
  WRITE_REG(DMA2Dx->IFCR, DMA2D_IFCR_CCEIF);
}

   
                                                             
                                                                
                                 
                
    
__STATIC_INLINE void LL_DMA2D_ClearFlag_CTC(DMA2D_TypeDef *DMA2Dx)
{
  WRITE_REG(DMA2Dx->IFCR, DMA2D_IFCR_CCTCIF);
}

   
                                                        
                                                                
                                 
                
    
__STATIC_INLINE void LL_DMA2D_ClearFlag_CAE(DMA2D_TypeDef *DMA2Dx)
{
  WRITE_REG(DMA2Dx->IFCR, DMA2D_IFCR_CAECIF);
}

   
                                                         
                                                              
                                 
                
    
__STATIC_INLINE void LL_DMA2D_ClearFlag_TW(DMA2D_TypeDef *DMA2Dx)
{
  WRITE_REG(DMA2Dx->IFCR, DMA2D_IFCR_CTWIF);
}

   
                                                        
                                                              
                                 
                
    
__STATIC_INLINE void LL_DMA2D_ClearFlag_TC(DMA2D_TypeDef *DMA2Dx)
{
  WRITE_REG(DMA2Dx->IFCR, DMA2D_IFCR_CTCIF);
}

   
                                                     
                                                              
                                 
                
    
__STATIC_INLINE void LL_DMA2D_ClearFlag_TE(DMA2D_TypeDef *DMA2Dx)
{
  WRITE_REG(DMA2Dx->IFCR, DMA2D_IFCR_CTEIF);
}

   
      
    

                                                               
      
    

   
                                                
                                                        
                                 
                
    
__STATIC_INLINE void LL_DMA2D_EnableIT_CE(DMA2D_TypeDef *DMA2Dx)
{
  SET_BIT(DMA2Dx->CR, DMA2D_CR_CEIE);
}

   
                                                   
                                                          
                                 
                
    
__STATIC_INLINE void LL_DMA2D_EnableIT_CTC(DMA2D_TypeDef *DMA2Dx)
{
  SET_BIT(DMA2Dx->CR, DMA2D_CR_CTCIE);
}

   
                                              
                                                          
                                 
                
    
__STATIC_INLINE void LL_DMA2D_EnableIT_CAE(DMA2D_TypeDef *DMA2Dx)
{
  SET_BIT(DMA2Dx->CR, DMA2D_CR_CAEIE);
}

   
                                               
                                                        
                                 
                
    
__STATIC_INLINE void LL_DMA2D_EnableIT_TW(DMA2D_TypeDef *DMA2Dx)
{
  SET_BIT(DMA2Dx->CR, DMA2D_CR_TWIE);
}

   
                                              
                                                        
                                 
                
    
__STATIC_INLINE void LL_DMA2D_EnableIT_TC(DMA2D_TypeDef *DMA2Dx)
{
  SET_BIT(DMA2Dx->CR, DMA2D_CR_TCIE);
}

   
                                           
                                                        
                                 
                
    
__STATIC_INLINE void LL_DMA2D_EnableIT_TE(DMA2D_TypeDef *DMA2Dx)
{
  SET_BIT(DMA2Dx->CR, DMA2D_CR_TEIE);
}

   
                                                 
                                                         
                                 
                
    
__STATIC_INLINE void LL_DMA2D_DisableIT_CE(DMA2D_TypeDef *DMA2Dx)
{
  CLEAR_BIT(DMA2Dx->CR, DMA2D_CR_CEIE);
}

   
                                                    
                                                           
                                 
                
    
__STATIC_INLINE void LL_DMA2D_DisableIT_CTC(DMA2D_TypeDef *DMA2Dx)
{
  CLEAR_BIT(DMA2Dx->CR, DMA2D_CR_CTCIE);
}

   
                                               
                                                           
                                 
                
    
__STATIC_INLINE void LL_DMA2D_DisableIT_CAE(DMA2D_TypeDef *DMA2Dx)
{
  CLEAR_BIT(DMA2Dx->CR, DMA2D_CR_CAEIE);
}

   
                                                
                                                         
                                 
                
    
__STATIC_INLINE void LL_DMA2D_DisableIT_TW(DMA2D_TypeDef *DMA2Dx)
{
  CLEAR_BIT(DMA2Dx->CR, DMA2D_CR_TWIE);
}

   
                                               
                                                         
                                 
                
    
__STATIC_INLINE void LL_DMA2D_DisableIT_TC(DMA2D_TypeDef *DMA2Dx)
{
  CLEAR_BIT(DMA2Dx->CR, DMA2D_CR_TCIE);
}

   
                                            
                                                         
                                 
                
    
__STATIC_INLINE void LL_DMA2D_DisableIT_TE(DMA2D_TypeDef *DMA2Dx)
{
  CLEAR_BIT(DMA2Dx->CR, DMA2D_CR_TEIE);
}

   
                                                                                           
                                                           
                                 
                                  
    
__STATIC_INLINE uint32_t LL_DMA2D_IsEnabledIT_CE(const DMA2D_TypeDef *DMA2Dx)
{
  return ((READ_BIT(DMA2Dx->CR, DMA2D_CR_CEIE) == (DMA2D_CR_CEIE)) ? 1UL : 0UL);
}

   
                                                                                              
                                                             
                                 
                                  
    
__STATIC_INLINE uint32_t LL_DMA2D_IsEnabledIT_CTC(const DMA2D_TypeDef *DMA2Dx)
{
  return ((READ_BIT(DMA2Dx->CR, DMA2D_CR_CTCIE) == (DMA2D_CR_CTCIE)) ? 1UL : 0UL);
}

   
                                                                                         
                                                             
                                 
                                  
    
__STATIC_INLINE uint32_t LL_DMA2D_IsEnabledIT_CAE(const DMA2D_TypeDef *DMA2Dx)
{
  return ((READ_BIT(DMA2Dx->CR, DMA2D_CR_CAEIE) == (DMA2D_CR_CAEIE)) ? 1UL : 0UL);
}

   
                                                                                          
                                                           
                                 
                                  
    
__STATIC_INLINE uint32_t LL_DMA2D_IsEnabledIT_TW(const DMA2D_TypeDef *DMA2Dx)
{
  return ((READ_BIT(DMA2Dx->CR, DMA2D_CR_TWIE) == (DMA2D_CR_TWIE)) ? 1UL : 0UL);
}

   
                                                                                         
                                                           
                                 
                                  
    
__STATIC_INLINE uint32_t LL_DMA2D_IsEnabledIT_TC(const DMA2D_TypeDef *DMA2Dx)
{
  return ((READ_BIT(DMA2Dx->CR, DMA2D_CR_TCIE) == (DMA2D_CR_TCIE)) ? 1UL : 0UL);
}

   
                                                                                      
                                                           
                                 
                                  
    
__STATIC_INLINE uint32_t LL_DMA2D_IsEnabledIT_TE(const DMA2D_TypeDef *DMA2Dx)
{
  return ((READ_BIT(DMA2Dx->CR, DMA2D_CR_TEIE) == (DMA2D_CR_TEIE)) ? 1UL : 0UL);
}



   
      
    

#if defined(USE_FULL_LL_DRIVER)
                                                                                       
      
    

ErrorStatus LL_DMA2D_DeInit(const DMA2D_TypeDef *DMA2Dx);
ErrorStatus LL_DMA2D_Init(DMA2D_TypeDef *DMA2Dx, LL_DMA2D_InitTypeDef *DMA2D_InitStruct);
void LL_DMA2D_StructInit(LL_DMA2D_InitTypeDef *DMA2D_InitStruct);
void LL_DMA2D_ConfigLayer(DMA2D_TypeDef *DMA2Dx, LL_DMA2D_LayerCfgTypeDef *DMA2D_LayerCfg, uint32_t LayerIdx);
void LL_DMA2D_LayerCfgStructInit(LL_DMA2D_LayerCfgTypeDef *DMA2D_LayerCfg);
void LL_DMA2D_ConfigOutputColor(DMA2D_TypeDef *DMA2Dx, LL_DMA2D_ColorTypeDef *DMA2D_ColorStruct);
uint32_t LL_DMA2D_GetOutputBlueColor(const DMA2D_TypeDef *DMA2Dx, uint32_t ColorMode);
uint32_t LL_DMA2D_GetOutputGreenColor(const DMA2D_TypeDef *DMA2Dx, uint32_t ColorMode);
uint32_t LL_DMA2D_GetOutputRedColor(const DMA2D_TypeDef *DMA2Dx, uint32_t ColorMode);
uint32_t LL_DMA2D_GetOutputAlphaColor(const DMA2D_TypeDef *DMA2Dx, uint32_t ColorMode);
void LL_DMA2D_ConfigSize(DMA2D_TypeDef *DMA2Dx, uint32_t NbrOfLines, uint32_t NbrOfPixelsPerLines);

   
      
    
#endif                         

   
      
    

   
      
    

#endif                      

   
      
    

#ifdef __cplusplus
}
#endif

#endif                           
