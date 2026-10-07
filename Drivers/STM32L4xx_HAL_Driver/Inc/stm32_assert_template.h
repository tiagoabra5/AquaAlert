/**
  ******************************************************************************
  * @file    stm32_assert.h
  * @author  MCD Application Team
  * @brief   STM32 assert template file.
  *          This file should be copied to the application folder and renamed
  *          to stm32_assert.h.
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

                                                                                
#ifndef STM32_ASSERT_H
#define STM32_ASSERT_H

#ifdef __cplusplus
 extern "C" {
#endif

                                                                                
                                                                                
                                                                                
                                                                                
#ifdef  USE_FULL_ASSERT
   
                                                                           
                                                                   
                                                                    
                                                
                                                 
                
    
  #define assert_param(expr) ((expr) ? (void)0U : assert_failed((char *)__FILE__, __LINE__))
                                                                                
  void assert_failed(char *file, uint32_t line);
#else
  #define assert_param(expr) ((void)0U)
#endif                      

#ifdef __cplusplus
}
#endif

#endif                     
