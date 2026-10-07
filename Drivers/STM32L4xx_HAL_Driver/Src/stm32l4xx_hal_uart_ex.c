/**
  ******************************************************************************
  * @file    stm32l4xx_hal_uart_ex.c
  * @author  MCD Application Team
  * @brief   Extended UART HAL module driver.
  *          This file provides firmware functions to manage the following extended
  *          functionalities of the Universal Asynchronous Receiver Transmitter Peripheral (UART).
  *           + Initialization and de-initialization functions
  *           + Peripheral Control functions
  *
  *
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
  @verbatim
  ==============================================================================
               ##### UART peripheral extended features  #####
  ==============================================================================
  [..]
    (#) Declare a UART_HandleTypeDef handle structure.

    (#) For the UART RS485 Driver Enable mode, initialize the UART registers
        by calling the HAL_RS485Ex_Init() API.

    (#) FIFO mode enabling/disabling and RX/TX FIFO threshold programming.

        -@- When UART operates in FIFO mode, FIFO mode must be enabled prior
            starting RX/TX transfers. Also RX/TX FIFO thresholds must be
            configured prior starting RX/TX transfers.

  @endverbatim
  ******************************************************************************
  */

                                                                                
#include "stm32l4xx_hal.h"

                                    
      
    

                           
                                          
      
    

#ifdef HAL_UART_MODULE_ENABLED

                                                                                
                                                                                
#if defined(USART_CR1_FIFOEN)
                                                               
      
    
                        
#define RX_FIFO_DEPTH 8U

                        
#define TX_FIFO_DEPTH 8U
   
      
    
#endif                       

                                                                                
                                                                                
                                                                                
                                                               
      
    
static void UARTEx_Wakeup_AddressConfig(UART_HandleTypeDef *huart, UART_WakeUpTypeDef WakeUpSelection);
#if defined(USART_CR1_FIFOEN)
static void UARTEx_SetNbDataToProcess(UART_HandleTypeDef *huart);
#endif                       
   
      
    

                                                                                

                                                                  
      
    

                                                                                             
                                                                 
   
         
                                                                               
                                                                  
                                                                                
        
                                                                                              
                         
                                                                           
                      
                        
                     
                                                                                   
                                                                                  
                                  
                                       
                                 
                                    
                                                                                               
                                             
                                         
                                
                                           
                                      
                                            
                                     
        
                                                                        
                                                                               

            

                                                                     
                                                              
                  

                               
                                                                             
                                                                             
                                                                             
                                                                             
                                                                             
                                                                             
                                                                             
                                                                             
                                                                             
                                                                             
                                                                             
                                                                             
                                                                             
                                                                             
                                                                             

      
    

   
                                                                                
                                                                                 
                                        
                                                              
                                                               
                                                                     
                                                                    
                                                         
                                                                                        
                                                                                   
                                                                          
                                                           
                                                                                  
                                                                                      
                                                                                      
                             
                      
    
HAL_StatusTypeDef HAL_RS485Ex_Init(UART_HandleTypeDef *huart, uint32_t Polarity, uint32_t AssertionTime,
                                   uint32_t DeassertionTime)
{
  uint32_t temp;

                                        
  if (huart == NULL)
  {
    return HAL_ERROR;
  }
                                             
  assert_param(IS_UART_DRIVER_ENABLE_INSTANCE(huart->Instance));

                                        
  assert_param(IS_UART_DE_POLARITY(Polarity));

                                              
  assert_param(IS_UART_ASSERTIONTIME(AssertionTime));

                                                
  assert_param(IS_UART_DEASSERTIONTIME(DeassertionTime));

  if (huart->gState == HAL_UART_STATE_RESET)
  {
                                                  
    huart->Lock = HAL_UNLOCKED;

#if (USE_HAL_UART_REGISTER_CALLBACKS == 1)
    UART_InitCallbacksToDefault(huart);

    if (huart->MspInitCallback == NULL)
    {
      huart->MspInitCallback = HAL_UART_MspInit;
    }

                                     
    huart->MspInitCallback(huart);
#else
                                                           
    HAL_UART_MspInit(huart);
#endif                                        
  }

  huart->gState = HAL_UART_STATE_BUSY;

                              
  __HAL_UART_DISABLE(huart);

                                               
                                                                                      
  if (huart->AdvancedInit.AdvFeatureInit != UART_ADVFEATURE_NO_INIT)
  {
    UART_AdvFeatureConfig(huart);
  }

                                             
  if (UART_SetConfig(huart) == HAL_ERROR)
  {
    return HAL_ERROR;
  }

                                                                                
  SET_BIT(huart->Instance->CR3, USART_CR3_DEM);

                                      
  MODIFY_REG(huart->Instance->CR3, USART_CR3_DEP, Polarity);

                                                             
  temp = (AssertionTime << UART_CR1_DEAT_ADDRESS_LSB_POS);
  temp |= (DeassertionTime << UART_CR1_DEDT_ADDRESS_LSB_POS);
  MODIFY_REG(huart->Instance->CR1, (USART_CR1_DEDT | USART_CR1_DEAT), temp);

                             
  __HAL_UART_ENABLE(huart);

                                                                                           
  return (UART_CheckIdleState(huart));
}

   
      
    

                                                                     
                              
   
         
                                                                                
                                                        
                                                                                
        
                                                                                      
                                       
                                        
                              
                                            
                                             
            
      
    

   
                                               
                             
                
    
__weak void HAL_UARTEx_WakeupCallback(UART_HandleTypeDef *huart)
{
                                                      
  UNUSED(huart);

                                                                              
                                                                              
     
}

#if defined(USART_CR1_FIFOEN)
   
                                       
                              
                
    
__weak void HAL_UARTEx_RxFifoFullCallback(UART_HandleTypeDef *huart)
{
                                                      
  UNUSED(huart);

                                                                              
                                                                                  
     
}

   
                                        
                              
                
    
__weak void HAL_UARTEx_TxFifoEmptyCallback(UART_HandleTypeDef *huart)
{
                                                      
  UNUSED(huart);

                                                                              
                                                                                   
     
}
#endif                       

   
      
    

                                                                           
                                                   
   
         
                                                                                
                                                              
                                                                                
                                                       
                                                                                                       
                                                                               
                                                                                           
                                                                                      
                                                                                       
                                                                        
                                                                                           
                                                                          
                                                              
                                                                
                                                                       
                                                                       

                                                                                                 
                                                                                         
                                                    

                                                                                      
                                                                                                       
                                                             
                                                                                            
                                                                                                               
                                                          
                                                                               
                                                                 
                                                                  

                                        
                                                                                                                        
                                                                                          
                                                                                                                        
                                                             
                                                                                  
                                             
                                                                       
                                                                                           
                                                                                                 
                                                                                                         

                          
                                       

                                             
                                          

                                       
                                           

            
      
    

#if defined(USART_CR3_UCESM)
   
                                                      
                                                                                                      
                                                                                               
                                                                                                
                                                                                                             
                              
                      
    
HAL_StatusTypeDef HAL_UARTEx_EnableClockStopMode(UART_HandleTypeDef *huart)
{
                      
  __HAL_LOCK(huart);

                     
  ATOMIC_SET_BIT(huart->Instance->CR3, USART_CR3_UCESM);

                        
  __HAL_UNLOCK(huart);

  return HAL_OK;
}

   
                                                 
                              
                      
    
HAL_StatusTypeDef HAL_UARTEx_DisableClockStopMode(UART_HandleTypeDef *huart)
{
                      
  __HAL_LOCK(huart);

                       
  ATOMIC_CLEAR_BIT(huart->Instance->CR3, USART_CR3_UCESM);

                        
  __HAL_UNLOCK(huart);

  return HAL_OK;
}

#endif                      
   
                                                                            
                                                                                 
                                                                                
                 
                                                                                       
                                                                                                  
                                     
                                                                           
                                                                
                                                                          
                      
    
HAL_StatusTypeDef HAL_MultiProcessorEx_AddressLength_Set(UART_HandleTypeDef *huart, uint32_t AddressLength)
{
                                        
  if (huart == NULL)
  {
    return HAL_ERROR;
  }

                                          
  assert_param(IS_UART_ADDRESSLENGTH_DETECT(AddressLength));

  huart->gState = HAL_UART_STATE_BUSY;

                              
  __HAL_UART_DISABLE(huart);

                              
  MODIFY_REG(huart->Instance->CR2, USART_CR2_ADDM7, AddressLength);

                             
  __HAL_UART_ENABLE(huart);

                                                                        
  return (UART_CheckIdleState(huart));
}

   
                                                              
                                                                              
                                                                     
                                       
                                                                                       
                                                               
                                             
                                              
                                                       
                      
    
HAL_StatusTypeDef HAL_UARTEx_StopModeWakeUpSourceConfig(UART_HandleTypeDef *huart, UART_WakeUpTypeDef WakeUpSelection)
{
  HAL_StatusTypeDef status = HAL_OK;
  uint32_t tickstart;

                                                      
  assert_param(IS_UART_WAKEUP_FROMSTOP_INSTANCE(huart->Instance));
                                             
  assert_param(IS_UART_WAKEUP_SELECTION(WakeUpSelection.WakeUpEvent));

                      
  __HAL_LOCK(huart);

  huart->gState = HAL_UART_STATE_BUSY;

                              
  __HAL_UART_DISABLE(huart);

                                        
  MODIFY_REG(huart->Instance->CR3, USART_CR3_WUS, WakeUpSelection.WakeUpEvent);

  if (WakeUpSelection.WakeUpEvent == UART_WAKEUP_ON_ADDRESS)
  {
    UARTEx_Wakeup_AddressConfig(huart, WakeUpSelection);
  }

                             
  __HAL_UART_ENABLE(huart);

                                             
  tickstart = HAL_GetTick();

                                    
  if (UART_WaitOnFlagUntilTimeout(huart, USART_ISR_REACK, RESET, tickstart, HAL_UART_TIMEOUT_VALUE) != HAL_OK)
  {
    status = HAL_TIMEOUT;
  }
  else
  {
                                   
    huart->gState = HAL_UART_STATE_READY;
  }

                        
  __HAL_UNLOCK(huart);

  return status;
}

   
                                 
                                                                                                   
                             
                      
    
HAL_StatusTypeDef HAL_UARTEx_EnableStopMode(UART_HandleTypeDef *huart)
{
                      
  __HAL_LOCK(huart);

                    
  ATOMIC_SET_BIT(huart->Instance->CR1, USART_CR1_UESM);

                        
  __HAL_UNLOCK(huart);

  return HAL_OK;
}

   
                                  
                             
                      
    
HAL_StatusTypeDef HAL_UARTEx_DisableStopMode(UART_HandleTypeDef *huart)
{
                      
  __HAL_LOCK(huart);

                      
  ATOMIC_CLEAR_BIT(huart->Instance->CR1, USART_CR1_UESM);

                        
  __HAL_UNLOCK(huart);

  return HAL_OK;
}

#if defined(USART_CR1_FIFOEN)
   
                                 
                                  
                      
    
HAL_StatusTypeDef HAL_UARTEx_EnableFifoMode(UART_HandleTypeDef *huart)
{
  uint32_t tmpcr1;

                        
  assert_param(IS_UART_FIFO_INSTANCE(huart->Instance));

                      
  __HAL_LOCK(huart);

  huart->gState = HAL_UART_STATE_BUSY;

                                      
  tmpcr1 = READ_REG(huart->Instance->CR1);

                    
  __HAL_UART_DISABLE(huart);

                        
  SET_BIT(tmpcr1, USART_CR1_FIFOEN);
  huart->FifoMode = UART_FIFOMODE_ENABLE;

                                  
  WRITE_REG(huart->Instance->CR1, tmpcr1);

                                                                          
  UARTEx_SetNbDataToProcess(huart);

  huart->gState = HAL_UART_STATE_READY;

                        
  __HAL_UNLOCK(huart);

  return HAL_OK;
}

   
                                  
                                  
                      
    
HAL_StatusTypeDef HAL_UARTEx_DisableFifoMode(UART_HandleTypeDef *huart)
{
  uint32_t tmpcr1;

                        
  assert_param(IS_UART_FIFO_INSTANCE(huart->Instance));

                      
  __HAL_LOCK(huart);

  huart->gState = HAL_UART_STATE_BUSY;

                                      
  tmpcr1 = READ_REG(huart->Instance->CR1);

                    
  __HAL_UART_DISABLE(huart);

                         
  CLEAR_BIT(tmpcr1, USART_CR1_FIFOEN);
  huart->FifoMode = UART_FIFOMODE_DISABLE;

                                  
  WRITE_REG(huart->Instance->CR1, tmpcr1);

  huart->gState = HAL_UART_STATE_READY;

                        
  __HAL_UNLOCK(huart);

  return HAL_OK;
}

   
                                     
                                  
                                             
                                                               
                                                  
                                                  
                                                  
                                                  
                                                  
                                                  
                      
    
HAL_StatusTypeDef HAL_UARTEx_SetTxFifoThreshold(UART_HandleTypeDef *huart, uint32_t Threshold)
{
  uint32_t tmpcr1;

                        
  assert_param(IS_UART_FIFO_INSTANCE(huart->Instance));
  assert_param(IS_UART_TXFIFO_THRESHOLD(Threshold));

                      
  __HAL_LOCK(huart);

  huart->gState = HAL_UART_STATE_BUSY;

                                      
  tmpcr1 = READ_REG(huart->Instance->CR1);

                    
  __HAL_UART_DISABLE(huart);

                                         
  MODIFY_REG(huart->Instance->CR3, USART_CR3_TXFTCFG, Threshold);

                                                                          
  UARTEx_SetNbDataToProcess(huart);

                                  
  WRITE_REG(huart->Instance->CR1, tmpcr1);

  huart->gState = HAL_UART_STATE_READY;

                        
  __HAL_UNLOCK(huart);

  return HAL_OK;
}

   
                                     
                                  
                                             
                                                               
                                                  
                                                  
                                                  
                                                  
                                                  
                                                  
                      
    
HAL_StatusTypeDef HAL_UARTEx_SetRxFifoThreshold(UART_HandleTypeDef *huart, uint32_t Threshold)
{
  uint32_t tmpcr1;

                            
  assert_param(IS_UART_FIFO_INSTANCE(huart->Instance));
  assert_param(IS_UART_RXFIFO_THRESHOLD(Threshold));

                      
  __HAL_LOCK(huart);

  huart->gState = HAL_UART_STATE_BUSY;

                                      
  tmpcr1 = READ_REG(huart->Instance->CR1);

                    
  __HAL_UART_DISABLE(huart);

                                         
  MODIFY_REG(huart->Instance->CR3, USART_CR3_RXFTCFG, Threshold);

                                                                          
  UARTEx_SetNbDataToProcess(huart);

                                  
  WRITE_REG(huart->Instance->CR1, tmpcr1);

  huart->gState = HAL_UART_STATE_READY;

                        
  __HAL_UNLOCK(huart);

  return HAL_OK;
}

#endif                       
   
                                                                                             
                                               
                                                                                                   
                                                                                                                
                                                                                                       
                                                                                                           
                                                                                                         
                                               
                                                                                
                                                                                
                                                                      
                                                
                               
                                                                              
                                                                                
                                                           
                                                                                   
                                                                                          
                      
    
HAL_StatusTypeDef HAL_UARTEx_ReceiveToIdle(UART_HandleTypeDef *huart, uint8_t *pData, uint16_t Size, uint16_t *RxLen,
                                           uint32_t Timeout)
{
  uint8_t  *pdata8bits;
  uint16_t *pdata16bits;
  uint16_t uhMask;
  uint32_t tickstart;

                                                      
  if (huart->RxState == HAL_UART_STATE_READY)
  {
    if ((pData == NULL) || (Size == 0U))
    {
      return  HAL_ERROR;
    }

    huart->ErrorCode = HAL_UART_ERROR_NONE;
    huart->RxState = HAL_UART_STATE_BUSY_RX;
    huart->ReceptionType = HAL_UART_RECEPTION_TOIDLE;
    huart->RxEventType = HAL_UART_RXEVENT_TC;

                                               
    tickstart = HAL_GetTick();

    huart->RxXferSize  = Size;
    huart->RxXferCount = Size;

                                                           
    UART_MASK_COMPUTATION(huart);
    uhMask = huart->Mask;

                                                                                                
    if ((huart->Init.WordLength == UART_WORDLENGTH_9B) && (huart->Init.Parity == UART_PARITY_NONE))
    {
      pdata8bits  = NULL;
      pdata16bits = (uint16_t *) pData;
    }
    else
    {
      pdata8bits  = pData;
      pdata16bits = NULL;
    }

                                                       
    *RxLen = 0U;

                                             
    while (huart->RxXferCount > 0U)
    {
                                     
      if (__HAL_UART_GET_FLAG(huart, UART_FLAG_IDLE))
      {
                                    
        __HAL_UART_CLEAR_FLAG(huart, UART_CLEAR_IDLEF);

                                                                                
                                                                                                        
        if (*RxLen > 0U)
        {
          huart->RxEventType = HAL_UART_RXEVENT_IDLE;
          huart->RxState = HAL_UART_STATE_READY;

          return HAL_OK;
        }
      }

                                     
      if (__HAL_UART_GET_FLAG(huart, UART_FLAG_RXNE))
      {
        if (pdata8bits == NULL)
        {
          *pdata16bits = (uint16_t)(huart->Instance->RDR & uhMask);
          pdata16bits++;
        }
        else
        {
          *pdata8bits = (uint8_t)(huart->Instance->RDR & (uint8_t)uhMask);
          pdata8bits++;
        }
                                                   
        *RxLen += 1U;
        huart->RxXferCount--;
      }

                                 
      if (Timeout != HAL_MAX_DELAY)
      {
        if (((HAL_GetTick() - tickstart) > Timeout) || (Timeout == 0U))
        {
          huart->RxState = HAL_UART_STATE_READY;

          return HAL_TIMEOUT;
        }
      }
    }

                                                                     
    *RxLen = huart->RxXferSize - huart->RxXferCount;
                                                               
    huart->RxState = HAL_UART_STATE_READY;

    return HAL_OK;
  }
  else
  {
    return HAL_BUSY;
  }
}

   
                                                                                              
                                               
                                                                                                         
                                                                                                               
                                            
                                                                                                           
                                                                                                         
                                               
                             
                                                                            
                                                                              
                      
    
HAL_StatusTypeDef HAL_UARTEx_ReceiveToIdle_IT(UART_HandleTypeDef *huart, uint8_t *pData, uint16_t Size)
{
  HAL_StatusTypeDef status = HAL_OK;

                                                      
  if (huart->RxState == HAL_UART_STATE_READY)
  {
    if ((pData == NULL) || (Size == 0U))
    {
      return HAL_ERROR;
    }

                                                        
    huart->ReceptionType = HAL_UART_RECEPTION_TOIDLE;
    huart->RxEventType = HAL_UART_RXEVENT_TC;

    (void)UART_Start_Receive_IT(huart, pData, Size);

    if (huart->ReceptionType == HAL_UART_RECEPTION_TOIDLE)
    {
      __HAL_UART_CLEAR_FLAG(huart, UART_CLEAR_IDLEF);
      ATOMIC_SET_BIT(huart->Instance->CR1, USART_CR1_IDLEIE);
    }
    else
    {
                                                                     
                                                                                
                                      
                                                                                      
      status = HAL_ERROR;
    }

    return status;
  }
  else
  {
    return HAL_BUSY;
  }
}

   
                                                                                
                                                       
                                                                                                         
                                                                                                          
                                                                                                            
                                                                                                                     
                                                                               
                                         
                                                                                                           
                                                                                                         
                                               
                             
                                                                            
                                                                              
                      
    
HAL_StatusTypeDef HAL_UARTEx_ReceiveToIdle_DMA(UART_HandleTypeDef *huart, uint8_t *pData, uint16_t Size)
{
  HAL_StatusTypeDef status;

                                                      
  if (huart->RxState == HAL_UART_STATE_READY)
  {
    if ((pData == NULL) || (Size == 0U))
    {
      return HAL_ERROR;
    }

                                                        
    huart->ReceptionType = HAL_UART_RECEPTION_TOIDLE;
    huart->RxEventType = HAL_UART_RXEVENT_TC;

    status =  UART_Start_Receive_DMA(huart, pData, Size);

                                                        
    if (status == HAL_OK)
    {
      if (huart->ReceptionType == HAL_UART_RECEPTION_TOIDLE)
      {
        __HAL_UART_CLEAR_FLAG(huart, UART_CLEAR_IDLEF);
        ATOMIC_SET_BIT(huart->Instance->CR1, USART_CR1_IDLEIE);
      }
      else
      {
                                                                       
                                                                                  
                                        
                                                                                        
        status = HAL_ERROR;
      }
    }

    return status;
  }
  else
  {
    return HAL_BUSY;
  }
}

   
                                                                             
                                                                                                        
                                                                                                                 
                                                                                                                    
                                                                                                                 
                                          
                                                                                                      
                                                  
                             
                                                                                                             
                                                                                                 
                       
                                                                                                             
                                                                                      
                                                                                                 
                                                                       
                                                                                           
                                                                                                       
                              
                                                                                        
    
HAL_UART_RxEventTypeTypeDef HAL_UARTEx_GetRxEventType(const UART_HandleTypeDef *huart)
{
                                                            
  return (huart->RxEventType);
}

   
      
    

   
      
    

                                        
      
    

   
                                                                                                     
                                       
                                                                  
                
    
static void UARTEx_Wakeup_AddressConfig(UART_HandleTypeDef *huart, UART_WakeUpTypeDef WakeUpSelection)
{
  assert_param(IS_UART_ADDRESSLENGTH_DETECT(WakeUpSelection.AddressLength));

                                    
  MODIFY_REG(huart->Instance->CR2, USART_CR2_ADDM7, WakeUpSelection.AddressLength);

                                  
  MODIFY_REG(huart->Instance->CR2, USART_CR2_ADD, ((uint32_t)WakeUpSelection.Address << UART_CR2_ADDRESS_LSB_POS));
}

#if defined(USART_CR1_FIFOEN)
   
                                                                
                                                                   
                                           
                             
                
    
static void UARTEx_SetNbDataToProcess(UART_HandleTypeDef *huart)
{
  uint8_t rx_fifo_depth;
  uint8_t tx_fifo_depth;
  uint8_t rx_fifo_threshold;
  uint8_t tx_fifo_threshold;
  static const uint8_t numerator[] = {1U, 1U, 1U, 3U, 7U, 1U, 0U, 0U};
  static const uint8_t denominator[] = {8U, 4U, 2U, 4U, 8U, 1U, 1U, 1U};

  if (huart->FifoMode == UART_FIFOMODE_DISABLE)
  {
    huart->NbTxDataToProcess = 1U;
    huart->NbRxDataToProcess = 1U;
  }
  else
  {
    rx_fifo_depth = RX_FIFO_DEPTH;
    tx_fifo_depth = TX_FIFO_DEPTH;
    rx_fifo_threshold = (uint8_t)(READ_BIT(huart->Instance->CR3, USART_CR3_RXFTCFG) >> USART_CR3_RXFTCFG_Pos);
    tx_fifo_threshold = (uint8_t)(READ_BIT(huart->Instance->CR3, USART_CR3_TXFTCFG) >> USART_CR3_TXFTCFG_Pos);
    huart->NbTxDataToProcess = ((uint16_t)tx_fifo_depth * numerator[tx_fifo_threshold]) /
                               (uint16_t)denominator[tx_fifo_threshold];
    huart->NbRxDataToProcess = ((uint16_t)rx_fifo_depth * numerator[rx_fifo_threshold]) /
                               (uint16_t)denominator[rx_fifo_threshold];
  }
}
#endif                       
   
      
    

#endif                              

   
      
    

   
      
    

