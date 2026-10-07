/**
  ******************************************************************************
  * @file    stm32l4xx_hal_spi.c
  * @author  MCD Application Team
  * @brief   SPI HAL module driver.
  *          This file provides firmware functions to manage the following
  *          functionalities of the Serial Peripheral Interface (SPI) peripheral:
  *           + Initialization and de-initialization functions
  *           + IO operation functions
  *           + Peripheral Control functions
  *           + Peripheral State functions
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
                        ##### How to use this driver #####
  ==============================================================================
    [..]
      The SPI HAL driver can be used as follows:

      (#) Declare a SPI_HandleTypeDef handle structure, for example:
          SPI_HandleTypeDef  hspi;

      (#)Initialize the SPI low level resources by implementing the HAL_SPI_MspInit() API:
          (##) Enable the SPIx interface clock
          (##) SPI pins configuration
              (+++) Enable the clock for the SPI GPIOs
              (+++) Configure these SPI pins as alternate function push-pull
          (##) NVIC configuration if you need to use interrupt process
              (+++) Configure the SPIx interrupt priority
              (+++) Enable the NVIC SPI IRQ handle
          (##) DMA Configuration if you need to use DMA process
              (+++) Declare a DMA_HandleTypeDef handle structure for the transmit or receive Stream/Channel
              (+++) Enable the DMAx clock
              (+++) Configure the DMA handle parameters
              (+++) Configure the DMA Tx or Rx Stream/Channel
              (+++) Associate the initialized hdma_tx(or _rx)  handle to the hspi DMA Tx or Rx handle
              (+++) Configure the priority and enable the NVIC for the transfer complete interrupt on the DMA Tx
                    or Rx Stream/Channel

      (#) Program the Mode, BidirectionalMode , Data size, Baudrate Prescaler, NSS
          management, Clock polarity and phase, FirstBit and CRC configuration in the hspi Init structure.

      (#) Initialize the SPI registers by calling the HAL_SPI_Init() API:
          (++) This API configures also the low level Hardware GPIO, CLOCK, CORTEX...etc)
              by calling the customized HAL_SPI_MspInit() API.
     [..]
       Circular mode restriction:
      (#) The DMA circular mode cannot be used when the SPI is configured in these modes:
          (##) Master 2Lines RxOnly
          (##) Master 1Line Rx
      (#) The CRC feature is not managed when the DMA circular mode is enabled
      (#) When the SPI DMA Pause/Stop features are used, we must use the following APIs
          the HAL_SPI_DMAPause()/ HAL_SPI_DMAStop() only under the SPI callbacks
     [..]
       Master Receive mode restriction:
      (#) In Master unidirectional receive-only mode (MSTR =1, BIDIMODE=0, RXONLY=1) or
          bidirectional receive mode (MSTR=1, BIDIMODE=1, BIDIOE=0), to ensure that the SPI
          does not initiate a new transfer the following procedure has to be respected:
          (##) HAL_SPI_DeInit()
          (##) HAL_SPI_Init()
     [..]
       Callback registration:

      (#) The compilation flag USE_HAL_SPI_REGISTER_CALLBACKS when set to 1U
          allows the user to configure dynamically the driver callbacks.
          Use Functions HAL_SPI_RegisterCallback() to register an interrupt callback.

          Function HAL_SPI_RegisterCallback() allows to register following callbacks:
            (++) TxCpltCallback        : SPI Tx Completed callback
            (++) RxCpltCallback        : SPI Rx Completed callback
            (++) TxRxCpltCallback      : SPI TxRx Completed callback
            (++) TxHalfCpltCallback    : SPI Tx Half Completed callback
            (++) RxHalfCpltCallback    : SPI Rx Half Completed callback
            (++) TxRxHalfCpltCallback  : SPI TxRx Half Completed callback
            (++) ErrorCallback         : SPI Error callback
            (++) AbortCpltCallback     : SPI Abort callback
            (++) MspInitCallback       : SPI Msp Init callback
            (++) MspDeInitCallback     : SPI Msp DeInit callback
          This function takes as parameters the HAL peripheral handle, the Callback ID
          and a pointer to the user callback function.


      (#) Use function HAL_SPI_UnRegisterCallback to reset a callback to the default
          weak function.
          HAL_SPI_UnRegisterCallback takes as parameters the HAL peripheral handle,
          and the Callback ID.
          This function allows to reset following callbacks:
            (++) TxCpltCallback        : SPI Tx Completed callback
            (++) RxCpltCallback        : SPI Rx Completed callback
            (++) TxRxCpltCallback      : SPI TxRx Completed callback
            (++) TxHalfCpltCallback    : SPI Tx Half Completed callback
            (++) RxHalfCpltCallback    : SPI Rx Half Completed callback
            (++) TxRxHalfCpltCallback  : SPI TxRx Half Completed callback
            (++) ErrorCallback         : SPI Error callback
            (++) AbortCpltCallback     : SPI Abort callback
            (++) MspInitCallback       : SPI Msp Init callback
            (++) MspDeInitCallback     : SPI Msp DeInit callback

       [..]
       By default, after the HAL_SPI_Init() and when the state is HAL_SPI_STATE_RESET
       all callbacks are set to the corresponding weak functions:
       examples HAL_SPI_MasterTxCpltCallback(), HAL_SPI_MasterRxCpltCallback().
       Exception done for MspInit and MspDeInit functions that are
       reset to the legacy weak functions in the HAL_SPI_Init()/ HAL_SPI_DeInit() only when
       these callbacks are null (not registered beforehand).
       If MspInit or MspDeInit are not null, the HAL_SPI_Init()/ HAL_SPI_DeInit()
       keep and use the user MspInit/MspDeInit callbacks (registered beforehand) whatever the state.

       [..]
       Callbacks can be registered/unregistered in HAL_SPI_STATE_READY state only.
       Exception done MspInit/MspDeInit functions that can be registered/unregistered
       in HAL_SPI_STATE_READY or HAL_SPI_STATE_RESET state,
       thus registered (user) MspInit/DeInit callbacks can be used during the Init/DeInit.
       Then, the user first registers the MspInit/MspDeInit user callbacks
       using HAL_SPI_RegisterCallback() before calling HAL_SPI_DeInit()
       or HAL_SPI_Init() function.

       [..]
       When the compilation define USE_HAL_PPP_REGISTER_CALLBACKS is set to 0 or
       not defined, the callback registering feature is not available
       and weak (surcharged) callbacks are used.

     [..]
       Using the HAL it is not possible to reach all supported SPI frequency with the different SPI Modes,
       the following table resume the max SPI frequency reached with data size 8bits/16bits,
         according to frequency of the APBx Peripheral Clock (fPCLK) used by the SPI instance.

  @endverbatim

  Additional table :

       DataSize = SPI_DATASIZE_8BIT:
       +----------------------------------------------------------------------------------------------+
       |         |                | 2Lines Fullduplex   |     2Lines RxOnly    |         1Line        |
       | Process | Transfer mode  |---------------------|----------------------|----------------------|
       |         |                |  Master  |  Slave   |  Master   |  Slave   |  Master   |  Slave   |
       |==============================================================================================|
       |    T    |     Polling    | Fpclk/4  | Fpclk/8  |    NA     |    NA    |    NA     |   NA     |
       |    X    |----------------|----------|----------|-----------|----------|-----------|----------|
       |    /    |     Interrupt  | Fpclk/4  | Fpclk/16 |    NA     |    NA    |    NA     |   NA     |
       |    R    |----------------|----------|----------|-----------|----------|-----------|----------|
       |    X    |       DMA      | Fpclk/2  | Fpclk/2  |    NA     |    NA    |    NA     |   NA     |
       |=========|================|==========|==========|===========|==========|===========|==========|
       |         |     Polling    | Fpclk/4  | Fpclk/8  | Fpclk/16  | Fpclk/8  | Fpclk/8   | Fpclk/8  |
       |         |----------------|----------|----------|-----------|----------|-----------|----------|
       |    R    |     Interrupt  | Fpclk/8  | Fpclk/16 | Fpclk/8   | Fpclk/8  | Fpclk/8   | Fpclk/4  |
       |    X    |----------------|----------|----------|-----------|----------|-----------|----------|
       |         |       DMA      | Fpclk/4  | Fpclk/2  | Fpclk/2   | Fpclk/16 | Fpclk/2   | Fpclk/16 |
       |=========|================|==========|==========|===========|==========|===========|==========|
       |         |     Polling    | Fpclk/8  | Fpclk/2  |     NA    |    NA    | Fpclk/8   | Fpclk/8  |
       |         |----------------|----------|----------|-----------|----------|-----------|----------|
       |    T    |     Interrupt  | Fpclk/2  | Fpclk/4  |     NA    |    NA    | Fpclk/16  | Fpclk/8  |
       |    X    |----------------|----------|----------|-----------|----------|-----------|----------|
       |         |       DMA      | Fpclk/2  | Fpclk/2  |     NA    |    NA    | Fpclk/8   | Fpclk/16 |
       +----------------------------------------------------------------------------------------------+

       DataSize = SPI_DATASIZE_16BIT:
       +----------------------------------------------------------------------------------------------+
       |         |                | 2Lines Fullduplex   |     2Lines RxOnly    |         1Line        |
       | Process | Transfer mode  |---------------------|----------------------|----------------------|
       |         |                |  Master  |  Slave   |  Master   |  Slave   |  Master   |  Slave   |
       |==============================================================================================|
       |    T    |     Polling    | Fpclk/4  | Fpclk/8  |    NA     |    NA    |    NA     |   NA     |
       |    X    |----------------|----------|----------|-----------|----------|-----------|----------|
       |    /    |     Interrupt  | Fpclk/4  | Fpclk/16 |    NA     |    NA    |    NA     |   NA     |
       |    R    |----------------|----------|----------|-----------|----------|-----------|----------|
       |    X    |       DMA      | Fpclk/2  | Fpclk/2  |    NA     |    NA    |    NA     |   NA     |
       |=========|================|==========|==========|===========|==========|===========|==========|
       |         |     Polling    | Fpclk/4  | Fpclk/8  | Fpclk/16  | Fpclk/8  | Fpclk/8   | Fpclk/8  |
       |         |----------------|----------|----------|-----------|----------|-----------|----------|
       |    R    |     Interrupt  | Fpclk/8  | Fpclk/16 | Fpclk/8   | Fpclk/8  | Fpclk/8   | Fpclk/4  |
       |    X    |----------------|----------|----------|-----------|----------|-----------|----------|
       |         |       DMA      | Fpclk/4  | Fpclk/2  | Fpclk/2   | Fpclk/16 | Fpclk/2   | Fpclk/16 |
       |=========|================|==========|==========|===========|==========|===========|==========|
       |         |     Polling    | Fpclk/8  | Fpclk/2  |     NA    |    NA    | Fpclk/8   | Fpclk/8  |
       |         |----------------|----------|----------|-----------|----------|-----------|----------|
       |    T    |     Interrupt  | Fpclk/2  | Fpclk/4  |     NA    |    NA    | Fpclk/16  | Fpclk/8  |
       |    X    |----------------|----------|----------|-----------|----------|-----------|----------|
       |         |       DMA      | Fpclk/2  | Fpclk/2  |     NA    |    NA    | Fpclk/8   | Fpclk/16 |
       +----------------------------------------------------------------------------------------------+
       @note The max SPI frequency depend on SPI data size (4bits, 5bits,..., 8bits,...15bits, 16bits),
             SPI mode(2 Lines fullduplex, 2 lines RxOnly, 1 line TX/RX) and Process mode (Polling, IT, DMA).
       @note
            (#) TX/RX processes are HAL_SPI_TransmitReceive(), HAL_SPI_TransmitReceive_IT() and
                HAL_SPI_TransmitReceive_DMA()
            (#) RX processes are HAL_SPI_Receive(), HAL_SPI_Receive_IT() and HAL_SPI_Receive_DMA()
            (#) TX processes are HAL_SPI_Transmit(), HAL_SPI_Transmit_IT() and HAL_SPI_Transmit_DMA()

  */

                                                                                
#include "stm32l4xx_hal.h"

                                    
      
    

                     
                                
      
    
#ifdef HAL_SPI_MODULE_ENABLED

                                                                                
                                                                                
                                                         
      
    
#define SPI_DEFAULT_TIMEOUT 100U
   
      
    

                                                                                
                                                                                
                                                                                
                                                         
      
    
static void SPI_DMATransmitCplt(DMA_HandleTypeDef *hdma);
static void SPI_DMAReceiveCplt(DMA_HandleTypeDef *hdma);
static void SPI_DMATransmitReceiveCplt(DMA_HandleTypeDef *hdma);
static void SPI_DMAHalfTransmitCplt(DMA_HandleTypeDef *hdma);
static void SPI_DMAHalfReceiveCplt(DMA_HandleTypeDef *hdma);
static void SPI_DMAHalfTransmitReceiveCplt(DMA_HandleTypeDef *hdma);
static void SPI_DMAError(DMA_HandleTypeDef *hdma);
static void SPI_DMAAbortOnError(DMA_HandleTypeDef *hdma);
static void SPI_DMATxAbortCallback(DMA_HandleTypeDef *hdma);
static void SPI_DMARxAbortCallback(DMA_HandleTypeDef *hdma);
static HAL_StatusTypeDef SPI_WaitFlagStateUntilTimeout(SPI_HandleTypeDef *hspi, uint32_t Flag, FlagStatus State,
                                                       uint32_t Timeout, uint32_t Tickstart);
static HAL_StatusTypeDef SPI_WaitFifoStateUntilTimeout(SPI_HandleTypeDef *hspi, uint32_t Fifo, uint32_t State,
                                                       uint32_t Timeout, uint32_t Tickstart);
static void SPI_TxISR_8BIT(struct __SPI_HandleTypeDef *hspi);
static void SPI_TxISR_16BIT(struct __SPI_HandleTypeDef *hspi);
static void SPI_RxISR_8BIT(struct __SPI_HandleTypeDef *hspi);
static void SPI_RxISR_16BIT(struct __SPI_HandleTypeDef *hspi);
static void SPI_2linesRxISR_8BIT(struct __SPI_HandleTypeDef *hspi);
static void SPI_2linesTxISR_8BIT(struct __SPI_HandleTypeDef *hspi);
static void SPI_2linesTxISR_16BIT(struct __SPI_HandleTypeDef *hspi);
static void SPI_2linesRxISR_16BIT(struct __SPI_HandleTypeDef *hspi);
#if (USE_SPI_CRC != 0U)
static void SPI_RxISR_8BITCRC(struct __SPI_HandleTypeDef *hspi);
static void SPI_RxISR_16BITCRC(struct __SPI_HandleTypeDef *hspi);
static void SPI_2linesRxISR_8BITCRC(struct __SPI_HandleTypeDef *hspi);
static void SPI_2linesRxISR_16BITCRC(struct __SPI_HandleTypeDef *hspi);
#endif                  
static void SPI_AbortRx_ISR(SPI_HandleTypeDef *hspi);
static void SPI_AbortTx_ISR(SPI_HandleTypeDef *hspi);
static void SPI_CloseRxTx_ISR(SPI_HandleTypeDef *hspi);
static void SPI_CloseRx_ISR(SPI_HandleTypeDef *hspi);
static void SPI_CloseTx_ISR(SPI_HandleTypeDef *hspi);
static HAL_StatusTypeDef SPI_EndRxTransaction(SPI_HandleTypeDef *hspi, uint32_t Timeout, uint32_t Tickstart);
static HAL_StatusTypeDef SPI_EndRxTxTransaction(SPI_HandleTypeDef *hspi, uint32_t Timeout, uint32_t Tickstart);
   
      
    

                                                                                
                                                           
      
    

                                                                                          
                                                         
   
         
                                                                                
                                                                        
                                                                                
                                                                                
                                            

                                                                               
                                                                             

                                                                                
                                     
                 
                      
                      
                                     
                           
                               
                     
                   
                            
                                          
                                                        
                                     

                                                                                 
                                          

            
      
    

   
                                                                    
                                                                        
                                                                       
                                                               
                      
    
HAL_StatusTypeDef HAL_SPI_Init(SPI_HandleTypeDef *hspi)
{
  uint32_t frxth;

                                       
  if (hspi == NULL)
  {
    return HAL_ERROR;
  }

                            
  assert_param(IS_SPI_ALL_INSTANCE(hspi->Instance));
  assert_param(IS_SPI_MODE(hspi->Init.Mode));
  assert_param(IS_SPI_DIRECTION(hspi->Init.Direction));
  assert_param(IS_SPI_DATASIZE(hspi->Init.DataSize));
  assert_param(IS_SPI_NSS(hspi->Init.NSS));
  assert_param(IS_SPI_NSSP(hspi->Init.NSSPMode));
  assert_param(IS_SPI_BAUDRATE_PRESCALER(hspi->Init.BaudRatePrescaler));
  assert_param(IS_SPI_FIRST_BIT(hspi->Init.FirstBit));
  assert_param(IS_SPI_TIMODE(hspi->Init.TIMode));
  if (hspi->Init.TIMode == SPI_TIMODE_DISABLE)
  {
    assert_param(IS_SPI_CPOL(hspi->Init.CLKPolarity));
    assert_param(IS_SPI_CPHA(hspi->Init.CLKPhase));

    if (hspi->Init.Mode == SPI_MODE_MASTER)
    {
      assert_param(IS_SPI_BAUDRATE_PRESCALER(hspi->Init.BaudRatePrescaler));
    }
    else
    {
                                                                                      
      hspi->Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_2;
    }
  }
  else
  {
    assert_param(IS_SPI_BAUDRATE_PRESCALER(hspi->Init.BaudRatePrescaler));

                                                               
    hspi->Init.CLKPolarity = SPI_POLARITY_LOW;
    hspi->Init.CLKPhase    = SPI_PHASE_1EDGE;
  }
#if (USE_SPI_CRC != 0U)
  assert_param(IS_SPI_CRC_CALCULATION(hspi->Init.CRCCalculation));
  if (hspi->Init.CRCCalculation == SPI_CRCCALCULATION_ENABLE)
  {
    assert_param(IS_SPI_CRC_POLYNOMIAL(hspi->Init.CRCPolynomial));
    assert_param(IS_SPI_CRC_LENGTH(hspi->Init.CRCLength));
  }
#else
  hspi->Init.CRCCalculation = SPI_CRCCALCULATION_DISABLE;
#endif                  

  if (hspi->State == HAL_SPI_STATE_RESET)
  {
                                                  
    hspi->Lock = HAL_UNLOCKED;

#if (USE_HAL_SPI_REGISTER_CALLBACKS == 1U)
                                        
    hspi->TxCpltCallback       = HAL_SPI_TxCpltCallback;                                             
    hspi->RxCpltCallback       = HAL_SPI_RxCpltCallback;                                             
    hspi->TxRxCpltCallback     = HAL_SPI_TxRxCpltCallback;                                           
    hspi->TxHalfCpltCallback   = HAL_SPI_TxHalfCpltCallback;                                         
    hspi->RxHalfCpltCallback   = HAL_SPI_RxHalfCpltCallback;                                         
    hspi->TxRxHalfCpltCallback = HAL_SPI_TxRxHalfCpltCallback;                                       
    hspi->ErrorCallback        = HAL_SPI_ErrorCallback;                                              
    hspi->AbortCpltCallback    = HAL_SPI_AbortCpltCallback;                                          

    if (hspi->MspInitCallback == NULL)
    {
      hspi->MspInitCallback = HAL_SPI_MspInit;                           
    }

                                                            
    hspi->MspInitCallback(hspi);
#else
                                                            
    HAL_SPI_MspInit(hspi);
#endif                                     
  }

  hspi->State = HAL_SPI_STATE_BUSY;

                                           
  __HAL_SPI_DISABLE(hspi);

                                                               
  if (hspi->Init.DataSize > SPI_DATASIZE_8BIT)
  {
    frxth = SPI_RXFIFO_THRESHOLD_HF;
  }
  else
  {
    frxth = SPI_RXFIFO_THRESHOLD_QF;
  }

                                                         
  if ((hspi->Init.DataSize != SPI_DATASIZE_16BIT) && (hspi->Init.DataSize != SPI_DATASIZE_8BIT))
  {
                              
    hspi->Init.CRCCalculation = SPI_CRCCALCULATION_DISABLE;
  }

                                                                                
                                                                                        
                                                             
  WRITE_REG(hspi->Instance->CR1, ((hspi->Init.Mode & (SPI_CR1_MSTR | SPI_CR1_SSI)) |
                                  (hspi->Init.Direction & (SPI_CR1_RXONLY | SPI_CR1_BIDIMODE)) |
                                  (hspi->Init.CLKPolarity & SPI_CR1_CPOL) |
                                  (hspi->Init.CLKPhase & SPI_CR1_CPHA) |
                                  (hspi->Init.NSS & SPI_CR1_SSM) |
                                  (hspi->Init.BaudRatePrescaler & SPI_CR1_BR_Msk) |
                                  (hspi->Init.FirstBit  & SPI_CR1_LSBFIRST) |
                                  (hspi->Init.CRCCalculation & SPI_CR1_CRCEN)));
#if (USE_SPI_CRC != 0U)
                                                                              
  if (hspi->Init.CRCCalculation == SPI_CRCCALCULATION_ENABLE)
  {
                                               
    if (hspi->Init.CRCLength == SPI_CRC_LENGTH_DATASIZE)
    {
                                                                      
      if (hspi->Init.DataSize > SPI_DATASIZE_8BIT)
      {
        hspi->Init.CRCLength = SPI_CRC_LENGTH_16BIT;
      }
      else
      {
        hspi->Init.CRCLength = SPI_CRC_LENGTH_8BIT;
      }
    }

                                
    if (hspi->Init.CRCLength == SPI_CRC_LENGTH_16BIT)
    {
      SET_BIT(hspi->Instance->CR1, SPI_CR1_CRCL);
    }
  }
#endif                  

                                                                                       
  WRITE_REG(hspi->Instance->CR2, (((hspi->Init.NSS >> 16U) & SPI_CR2_SSOE) |
                                  (hspi->Init.TIMode & SPI_CR2_FRF) |
                                  (hspi->Init.NSSPMode & SPI_CR2_NSSP) |
                                  (hspi->Init.DataSize & SPI_CR2_DS_Msk) |
                                  (frxth & SPI_CR2_FRXTH)));

#if (USE_SPI_CRC != 0U)
                                                                                
                                  
  if (hspi->Init.CRCCalculation == SPI_CRCCALCULATION_ENABLE)
  {
    WRITE_REG(hspi->Instance->CRCPR, (hspi->Init.CRCPolynomial & SPI_CRCPR_CRCPOLY_Msk));
  }
#endif                  

#if defined(SPI_I2SCFGR_I2SMOD)
                                                                                      
  CLEAR_BIT(hspi->Instance->I2SCFGR, SPI_I2SCFGR_I2SMOD);
#endif                         

  hspi->ErrorCode = HAL_SPI_ERROR_NONE;
  hspi->State     = HAL_SPI_STATE_READY;

  return HAL_OK;
}

   
                                             
                                                                       
                                                               
                      
    
HAL_StatusTypeDef HAL_SPI_DeInit(SPI_HandleTypeDef *hspi)
{
                                       
  if (hspi == NULL)
  {
    return HAL_ERROR;
  }

                                    
  assert_param(IS_SPI_ALL_INSTANCE(hspi->Instance));

  hspi->State = HAL_SPI_STATE_BUSY;

                                        
  __HAL_SPI_DISABLE(hspi);

#if (USE_HAL_SPI_REGISTER_CALLBACKS == 1U)
  if (hspi->MspDeInitCallback == NULL)
  {
    hspi->MspDeInitCallback = HAL_SPI_MspDeInit;                             
  }

                                                           
  hspi->MspDeInitCallback(hspi);
#else
                                                           
  HAL_SPI_MspDeInit(hspi);
#endif                                     

  hspi->ErrorCode = HAL_SPI_ERROR_NONE;
  hspi->State = HAL_SPI_STATE_RESET;

                    
  __HAL_UNLOCK(hspi);

  return HAL_OK;
}

   
                                   
                                                                       
                                                               
                
    
__weak void HAL_SPI_MspInit(SPI_HandleTypeDef *hspi)
{
                                                      
  UNUSED(hspi);

                                                                              
                                                                      
     
}

   
                                      
                                                                       
                                                               
                
    
__weak void HAL_SPI_MspDeInit(SPI_HandleTypeDef *hspi)
{
                                                      
  UNUSED(hspi);

                                                                              
                                                                        
     
}

#if (USE_HAL_SPI_REGISTER_CALLBACKS == 1U)
   
                                        
                                                              
                                                                       
                                                                       
                                                          
                                                      
                      
    
HAL_StatusTypeDef HAL_SPI_RegisterCallback(SPI_HandleTypeDef *hspi, HAL_SPI_CallbackIDTypeDef CallbackID,
                                           pSPI_CallbackTypeDef pCallback)
{
  HAL_StatusTypeDef status = HAL_OK;

  if (pCallback == NULL)
  {
                               
    hspi->ErrorCode |= HAL_SPI_ERROR_INVALID_CALLBACK;

    return HAL_ERROR;
  }
                      
  __HAL_LOCK(hspi);

  if (HAL_SPI_STATE_READY == hspi->State)
  {
    switch (CallbackID)
    {
      case HAL_SPI_TX_COMPLETE_CB_ID :
        hspi->TxCpltCallback = pCallback;
        break;

      case HAL_SPI_RX_COMPLETE_CB_ID :
        hspi->RxCpltCallback = pCallback;
        break;

      case HAL_SPI_TX_RX_COMPLETE_CB_ID :
        hspi->TxRxCpltCallback = pCallback;
        break;

      case HAL_SPI_TX_HALF_COMPLETE_CB_ID :
        hspi->TxHalfCpltCallback = pCallback;
        break;

      case HAL_SPI_RX_HALF_COMPLETE_CB_ID :
        hspi->RxHalfCpltCallback = pCallback;
        break;

      case HAL_SPI_TX_RX_HALF_COMPLETE_CB_ID :
        hspi->TxRxHalfCpltCallback = pCallback;
        break;

      case HAL_SPI_ERROR_CB_ID :
        hspi->ErrorCallback = pCallback;
        break;

      case HAL_SPI_ABORT_CB_ID :
        hspi->AbortCpltCallback = pCallback;
        break;

      case HAL_SPI_MSPINIT_CB_ID :
        hspi->MspInitCallback = pCallback;
        break;

      case HAL_SPI_MSPDEINIT_CB_ID :
        hspi->MspDeInitCallback = pCallback;
        break;

      default :
                                   
        SET_BIT(hspi->ErrorCode, HAL_SPI_ERROR_INVALID_CALLBACK);

                                 
        status =  HAL_ERROR;
        break;
    }
  }
  else if (HAL_SPI_STATE_RESET == hspi->State)
  {
    switch (CallbackID)
    {
      case HAL_SPI_MSPINIT_CB_ID :
        hspi->MspInitCallback = pCallback;
        break;

      case HAL_SPI_MSPDEINIT_CB_ID :
        hspi->MspDeInitCallback = pCallback;
        break;

      default :
                                   
        SET_BIT(hspi->ErrorCode, HAL_SPI_ERROR_INVALID_CALLBACK);

                                 
        status =  HAL_ERROR;
        break;
    }
  }
  else
  {
                               
    SET_BIT(hspi->ErrorCode, HAL_SPI_ERROR_INVALID_CALLBACK);

                             
    status =  HAL_ERROR;
  }

                    
  __HAL_UNLOCK(hspi);
  return status;
}

   
                                      
                                                                      
                                                                       
                                                                       
                                                            
                      
    
HAL_StatusTypeDef HAL_SPI_UnRegisterCallback(SPI_HandleTypeDef *hspi, HAL_SPI_CallbackIDTypeDef CallbackID)
{
  HAL_StatusTypeDef status = HAL_OK;

                      
  __HAL_LOCK(hspi);

  if (HAL_SPI_STATE_READY == hspi->State)
  {
    switch (CallbackID)
    {
      case HAL_SPI_TX_COMPLETE_CB_ID :
        hspi->TxCpltCallback = HAL_SPI_TxCpltCallback;                                                   
        break;

      case HAL_SPI_RX_COMPLETE_CB_ID :
        hspi->RxCpltCallback = HAL_SPI_RxCpltCallback;                                                   
        break;

      case HAL_SPI_TX_RX_COMPLETE_CB_ID :
        hspi->TxRxCpltCallback = HAL_SPI_TxRxCpltCallback;                                               
        break;

      case HAL_SPI_TX_HALF_COMPLETE_CB_ID :
        hspi->TxHalfCpltCallback = HAL_SPI_TxHalfCpltCallback;                                           
        break;

      case HAL_SPI_RX_HALF_COMPLETE_CB_ID :
        hspi->RxHalfCpltCallback = HAL_SPI_RxHalfCpltCallback;                                           
        break;

      case HAL_SPI_TX_RX_HALF_COMPLETE_CB_ID :
        hspi->TxRxHalfCpltCallback = HAL_SPI_TxRxHalfCpltCallback;                                       
        break;

      case HAL_SPI_ERROR_CB_ID :
        hspi->ErrorCallback = HAL_SPI_ErrorCallback;                                                     
        break;

      case HAL_SPI_ABORT_CB_ID :
        hspi->AbortCpltCallback = HAL_SPI_AbortCpltCallback;                                             
        break;

      case HAL_SPI_MSPINIT_CB_ID :
        hspi->MspInitCallback = HAL_SPI_MspInit;                                                         
        break;

      case HAL_SPI_MSPDEINIT_CB_ID :
        hspi->MspDeInitCallback = HAL_SPI_MspDeInit;                                                     
        break;

      default :
                                   
        SET_BIT(hspi->ErrorCode, HAL_SPI_ERROR_INVALID_CALLBACK);

                                 
        status =  HAL_ERROR;
        break;
    }
  }
  else if (HAL_SPI_STATE_RESET == hspi->State)
  {
    switch (CallbackID)
    {
      case HAL_SPI_MSPINIT_CB_ID :
        hspi->MspInitCallback = HAL_SPI_MspInit;                                                         
        break;

      case HAL_SPI_MSPDEINIT_CB_ID :
        hspi->MspDeInitCallback = HAL_SPI_MspDeInit;                                                     
        break;

      default :
                                   
        SET_BIT(hspi->ErrorCode, HAL_SPI_ERROR_INVALID_CALLBACK);

                                 
        status =  HAL_ERROR;
        break;
    }
  }
  else
  {
                               
    SET_BIT(hspi->ErrorCode, HAL_SPI_ERROR_INVALID_CALLBACK);

                             
    status =  HAL_ERROR;
  }

                    
  __HAL_UNLOCK(hspi);
  return status;
}
#endif                                     
   
      
    

                                                                  
                                      
   
         
                                                                                
                                                        
                                                                                
     
                                                                          
                   

                                                 

                                        
                                                                          
                                                                                  
                                     
                                                                             
                                                     
                                                                        
                                                                           
                           
                                                                                                                
                                                                                       
                                                                                                            

                                                                                                                   
                                                                 

            
      
    

   
                                                        
                                                                       
                                                               
                                                                  
                                                               
                                          
                      
    
HAL_StatusTypeDef HAL_SPI_Transmit(SPI_HandleTypeDef *hspi, const uint8_t *pData, uint16_t Size, uint32_t Timeout)
{
  uint32_t tickstart;
  uint16_t initial_TxXferCount;

                                 
  assert_param(IS_SPI_DIRECTION_2LINES_OR_1LINE(hspi->Init.Direction));

                                            
  tickstart = HAL_GetTick();
  initial_TxXferCount = Size;

  if (hspi->State != HAL_SPI_STATE_READY)
  {
    return HAL_BUSY;
  }

  if ((pData == NULL) || (Size == 0U))
  {
    return HAL_ERROR;
  }

                      
  __HAL_LOCK(hspi);

                                       
  hspi->State       = HAL_SPI_STATE_BUSY_TX;
  hspi->ErrorCode   = HAL_SPI_ERROR_NONE;
  hspi->pTxBuffPtr  = (const uint8_t *)pData;
  hspi->TxXferSize  = Size;
  hspi->TxXferCount = Size;

                                            
  hspi->pRxBuffPtr  = (uint8_t *)NULL;
  hspi->RxXferSize  = 0U;
  hspi->RxXferCount = 0U;
  hspi->TxISR       = NULL;
  hspi->RxISR       = NULL;

                                                 
  if (hspi->Init.Direction == SPI_DIRECTION_1LINE)
  {
                                                                        
    __HAL_SPI_DISABLE(hspi);
    SPI_1LINE_TX(hspi);
  }

#if (USE_SPI_CRC != 0U)
                             
  if (hspi->Init.CRCCalculation == SPI_CRCCALCULATION_ENABLE)
  {
    SPI_RESET_CRC(hspi);
  }
#endif                  

                                           
  if ((hspi->Instance->CR1 & SPI_CR1_SPE) != SPI_CR1_SPE)
  {
                               
    __HAL_SPI_ENABLE(hspi);
  }

                                    
  if (hspi->Init.DataSize > SPI_DATASIZE_8BIT)
  {
    if ((hspi->Init.Mode == SPI_MODE_SLAVE) || (initial_TxXferCount == 0x01U))
    {
      hspi->Instance->DR = *((const uint16_t *)hspi->pTxBuffPtr);
      hspi->pTxBuffPtr += sizeof(uint16_t);
      hspi->TxXferCount--;
    }
                                      
    while (hspi->TxXferCount > 0U)
    {
                                                   
      if (__HAL_SPI_GET_FLAG(hspi, SPI_FLAG_TXE))
      {
        hspi->Instance->DR = *((const uint16_t *)hspi->pTxBuffPtr);
        hspi->pTxBuffPtr += sizeof(uint16_t);
        hspi->TxXferCount--;
      }
      else
      {
                                
        if ((((HAL_GetTick() - tickstart) >=  Timeout) && (Timeout != HAL_MAX_DELAY)) || (Timeout == 0U))
        {
          hspi->State = HAL_SPI_STATE_READY;
          __HAL_UNLOCK(hspi);
          return HAL_TIMEOUT;
        }
      }
    }
  }
                                   
  else
  {
    if ((hspi->Init.Mode == SPI_MODE_SLAVE) || (initial_TxXferCount == 0x01U))
    {
      if (hspi->TxXferCount > 1U)
      {
                                                        
        hspi->Instance->DR = *((const uint16_t *)hspi->pTxBuffPtr);
        hspi->pTxBuffPtr += sizeof(uint16_t);
        hspi->TxXferCount -= 2U;
      }
      else
      {
        *((__IO uint8_t *)&hspi->Instance->DR) = *((const uint8_t *)hspi->pTxBuffPtr);
        hspi->pTxBuffPtr ++;
        hspi->TxXferCount--;
      }
    }
    while (hspi->TxXferCount > 0U)
    {
                                                   
      if (__HAL_SPI_GET_FLAG(hspi, SPI_FLAG_TXE))
      {
        if (hspi->TxXferCount > 1U)
        {
                                                          
          hspi->Instance->DR = *((const uint16_t *)hspi->pTxBuffPtr);
          hspi->pTxBuffPtr += sizeof(uint16_t);
          hspi->TxXferCount -= 2U;
        }
        else
        {
          *((__IO uint8_t *)&hspi->Instance->DR) = *((const uint8_t *)hspi->pTxBuffPtr);
          hspi->pTxBuffPtr++;
          hspi->TxXferCount--;
        }
      }
      else
      {
                                
        if ((((HAL_GetTick() - tickstart) >=  Timeout) && (Timeout != HAL_MAX_DELAY)) || (Timeout == 0U))
        {
          hspi->State = HAL_SPI_STATE_READY;
          __HAL_UNLOCK(hspi);
          return HAL_TIMEOUT;
        }
      }
    }
  }
#if (USE_SPI_CRC != 0U)
                               
  if (hspi->Init.CRCCalculation == SPI_CRCCALCULATION_ENABLE)
  {
    SET_BIT(hspi->Instance->CR1, SPI_CR1_CRCNEXT);
  }
#endif                  

                                        
  if (SPI_EndRxTxTransaction(hspi, Timeout, tickstart) != HAL_OK)
  {
    hspi->ErrorCode = HAL_SPI_ERROR_FLAG;
  }

                                                                                     
  if (hspi->Init.Direction == SPI_DIRECTION_2LINES)
  {
    __HAL_SPI_CLEAR_OVRFLAG(hspi);
  }

  hspi->State = HAL_SPI_STATE_READY;
                        
  __HAL_UNLOCK(hspi);

  if (hspi->ErrorCode != HAL_SPI_ERROR_NONE)
  {
    return HAL_ERROR;
  }
  else
  {
    return HAL_OK;
  }
}

   
                                                       
                                                                       
                                                               
                                                                  
                                                                   
                                          
                      
                                                                           
                                                                           
                                         
    
HAL_StatusTypeDef HAL_SPI_Receive(SPI_HandleTypeDef *hspi, uint8_t *pData, uint16_t Size, uint32_t Timeout)
{
#if (USE_SPI_CRC != 0U)
  __IO uint32_t tmpreg = 0U;
  __IO uint8_t  *ptmpreg8;
  __IO uint8_t  tmpreg8 = 0;
#endif                  
  uint32_t tickstart;

  if (hspi->State != HAL_SPI_STATE_READY)
  {
    return HAL_BUSY;
  }

  if ((pData == NULL) || (Size == 0U))
  {
    return HAL_ERROR;
  }

  if ((hspi->Init.Mode == SPI_MODE_MASTER) && (hspi->Init.Direction == SPI_DIRECTION_2LINES))
  {
    hspi->State = HAL_SPI_STATE_BUSY_RX;
                                                                                                     
    return HAL_SPI_TransmitReceive(hspi, pData, pData, Size, Timeout);
  }

                                            
  tickstart = HAL_GetTick();

                      
  __HAL_LOCK(hspi);

                                       
  hspi->State       = HAL_SPI_STATE_BUSY_RX;
  hspi->ErrorCode   = HAL_SPI_ERROR_NONE;
  hspi->pRxBuffPtr  = (uint8_t *)pData;
  hspi->RxXferSize  = Size;
  hspi->RxXferCount = Size;

                                            
  hspi->pTxBuffPtr  = (uint8_t *)NULL;
  hspi->TxXferSize  = 0U;
  hspi->TxXferCount = 0U;
  hspi->RxISR       = NULL;
  hspi->TxISR       = NULL;

#if (USE_SPI_CRC != 0U)
                             
  if (hspi->Init.CRCCalculation == SPI_CRCCALCULATION_ENABLE)
  {
    SPI_RESET_CRC(hspi);
                                                                   
    hspi->RxXferCount--;
  }
#endif                  

                                 
  if (hspi->Init.DataSize > SPI_DATASIZE_8BIT)
  {
                                                                          
    CLEAR_BIT(hspi->Instance->CR2, SPI_RXFIFO_THRESHOLD);
  }
  else
  {
                                                                         
    SET_BIT(hspi->Instance->CR2, SPI_RXFIFO_THRESHOLD);
  }

                                                
  if (hspi->Init.Direction == SPI_DIRECTION_1LINE)
  {
                                                                        
    __HAL_SPI_DISABLE(hspi);
    SPI_1LINE_RX(hspi);
  }

                                           
  if ((hspi->Instance->CR1 & SPI_CR1_SPE) != SPI_CR1_SPE)
  {
                               
    __HAL_SPI_ENABLE(hspi);
  }

                                  
  if (hspi->Init.DataSize <= SPI_DATASIZE_8BIT)
  {
                       
    while (hspi->RxXferCount > 0U)
    {
                               
      if (__HAL_SPI_GET_FLAG(hspi, SPI_FLAG_RXNE))
      {
                                    
        (* (uint8_t *)hspi->pRxBuffPtr) = *(__IO uint8_t *)&hspi->Instance->DR;
        hspi->pRxBuffPtr += sizeof(uint8_t);
        hspi->RxXferCount--;
      }
      else
      {
                                
        if ((((HAL_GetTick() - tickstart) >=  Timeout) && (Timeout != HAL_MAX_DELAY)) || (Timeout == 0U))
        {
          hspi->State = HAL_SPI_STATE_READY;
          __HAL_UNLOCK(hspi);
          return HAL_TIMEOUT;
        }
      }
    }
  }
  else
  {
                       
    while (hspi->RxXferCount > 0U)
    {
                               
      if (__HAL_SPI_GET_FLAG(hspi, SPI_FLAG_RXNE))
      {
        *((uint16_t *)hspi->pRxBuffPtr) = (uint16_t)hspi->Instance->DR;
        hspi->pRxBuffPtr += sizeof(uint16_t);
        hspi->RxXferCount--;
      }
      else
      {
                                
        if ((((HAL_GetTick() - tickstart) >=  Timeout) && (Timeout != HAL_MAX_DELAY)) || (Timeout == 0U))
        {
          hspi->State = HAL_SPI_STATE_READY;
          __HAL_UNLOCK(hspi);
          return HAL_TIMEOUT;
        }
      }
    }
  }

#if (USE_SPI_CRC != 0U)
                                   
  if (hspi->Init.CRCCalculation == SPI_CRCCALCULATION_ENABLE)
  {
                                               
    SET_BIT(hspi->Instance->CR1, SPI_CR1_CRCNEXT);

                              
    if (SPI_WaitFlagStateUntilTimeout(hspi, SPI_FLAG_RXNE, SET, Timeout, tickstart) != HAL_OK)
    {
                                                 
      __HAL_UNLOCK(hspi);
      return HAL_TIMEOUT;
    }

                                          
    if (hspi->Init.DataSize > SPI_DATASIZE_8BIT)
    {
      *((uint16_t *)hspi->pRxBuffPtr) = (uint16_t)hspi->Instance->DR;
    }
                                         
    else
    {
      (*(uint8_t *)hspi->pRxBuffPtr) = *(__IO uint8_t *)&hspi->Instance->DR;
    }

                           
    if (SPI_WaitFlagStateUntilTimeout(hspi, SPI_FLAG_RXNE, SET, Timeout, tickstart) != HAL_OK)
    {
      SET_BIT(hspi->ErrorCode, HAL_SPI_ERROR_CRC);
      hspi->State = HAL_SPI_STATE_READY;
      __HAL_UNLOCK(hspi);
      return HAL_TIMEOUT;
    }

                                            
    if (hspi->Init.DataSize == SPI_DATASIZE_16BIT)
    {
                          
      tmpreg = READ_REG(hspi->Instance->DR);
                                
      UNUSED(tmpreg);
    }
    else
    {
                                                 
      ptmpreg8 = (__IO uint8_t *)&hspi->Instance->DR;
                         
      tmpreg8 = *ptmpreg8;
                                
      UNUSED(tmpreg8);

      if ((hspi->Init.DataSize == SPI_DATASIZE_8BIT) && (hspi->Init.CRCLength == SPI_CRC_LENGTH_16BIT))
      {
        if (SPI_WaitFlagStateUntilTimeout(hspi, SPI_FLAG_RXNE, SET, Timeout, tickstart) != HAL_OK)
        {
                                          
          SET_BIT(hspi->ErrorCode, HAL_SPI_ERROR_CRC);
          hspi->State = HAL_SPI_STATE_READY;
          __HAL_UNLOCK(hspi);
          return HAL_TIMEOUT;
        }
                                                                        
        tmpreg8 = *ptmpreg8;
                                  
        UNUSED(tmpreg8);
      }
    }
  }
#endif                  

                                        
  if (SPI_EndRxTransaction(hspi, Timeout, tickstart) != HAL_OK)
  {
    hspi->ErrorCode = HAL_SPI_ERROR_FLAG;
  }

#if (USE_SPI_CRC != 0U)
                                   
  if (__HAL_SPI_GET_FLAG(hspi, SPI_FLAG_CRCERR))
  {
    SET_BIT(hspi->ErrorCode, HAL_SPI_ERROR_CRC);
    __HAL_SPI_CLEAR_CRCERRFLAG(hspi);
  }
#endif                  

  hspi->State = HAL_SPI_STATE_READY;
                          
  __HAL_UNLOCK(hspi);
  if (hspi->ErrorCode != HAL_SPI_ERROR_NONE)
  {
    return HAL_ERROR;
  }
  else
  {
    return HAL_OK;
  }
}

   
                                                                    
                                                                       
                                                               
                                                                                 
                                                                              
                                                                            
                                          
                      
    
HAL_StatusTypeDef HAL_SPI_TransmitReceive(SPI_HandleTypeDef *hspi, const uint8_t *pTxData, uint8_t *pRxData,
                                          uint16_t Size, uint32_t Timeout)
{
  uint16_t             initial_TxXferCount;
  uint16_t             initial_RxXferCount;
  uint32_t             tmp_mode;
  HAL_SPI_StateTypeDef tmp_state;
  uint32_t             tickstart;
#if (USE_SPI_CRC != 0U)
  __IO uint32_t tmpreg = 0U;
  uint32_t             spi_cr1;
  uint32_t             spi_cr2;
  __IO uint8_t  *ptmpreg8;
  __IO uint8_t  tmpreg8 = 0;
#endif                  

                                                            
  uint32_t             txallowed = 1U;

                                 
  assert_param(IS_SPI_DIRECTION_2LINES(hspi->Init.Direction));

                                            
  tickstart = HAL_GetTick();

                                
  tmp_state           = hspi->State;
  tmp_mode            = hspi->Init.Mode;
  initial_TxXferCount = Size;
  initial_RxXferCount = Size;
#if (USE_SPI_CRC != 0U)
  spi_cr1             = READ_REG(hspi->Instance->CR1);
  spi_cr2             = READ_REG(hspi->Instance->CR2);
#endif                  

  if (!((tmp_state == HAL_SPI_STATE_READY) || \
        ((tmp_mode == SPI_MODE_MASTER) && (hspi->Init.Direction == SPI_DIRECTION_2LINES) &&
         (tmp_state == HAL_SPI_STATE_BUSY_RX))))
  {
    return HAL_BUSY;
  }

  if ((pTxData == NULL) || (pRxData == NULL) || (Size == 0U))
  {
    return HAL_ERROR;
  }

                      
  __HAL_LOCK(hspi);

                                                        
  if (hspi->State != HAL_SPI_STATE_BUSY_RX)
  {
    hspi->State = HAL_SPI_STATE_BUSY_TX_RX;
  }

                                       
  hspi->ErrorCode   = HAL_SPI_ERROR_NONE;
  hspi->pRxBuffPtr  = (uint8_t *)pRxData;
  hspi->RxXferCount = Size;
  hspi->RxXferSize  = Size;
  hspi->pTxBuffPtr  = (const uint8_t *)pTxData;
  hspi->TxXferCount = Size;
  hspi->TxXferSize  = Size;

                                            
  hspi->RxISR       = NULL;
  hspi->TxISR       = NULL;

#if (USE_SPI_CRC != 0U)
                             
  if (hspi->Init.CRCCalculation == SPI_CRCCALCULATION_ENABLE)
  {
    SPI_RESET_CRC(hspi);
  }
#endif                  

                                 
  if ((hspi->Init.DataSize > SPI_DATASIZE_8BIT) || (initial_RxXferCount > 1U))
  {
                                                                        
    CLEAR_BIT(hspi->Instance->CR2, SPI_RXFIFO_THRESHOLD);
  }
  else
  {
                                                                       
    SET_BIT(hspi->Instance->CR2, SPI_RXFIFO_THRESHOLD);
  }

                                           
  if ((hspi->Instance->CR1 & SPI_CR1_SPE) != SPI_CR1_SPE)
  {
                               
    __HAL_SPI_ENABLE(hspi);
  }

                                                
  if (hspi->Init.DataSize > SPI_DATASIZE_8BIT)
  {
    if ((hspi->Init.Mode == SPI_MODE_SLAVE) || (initial_TxXferCount == 0x01U))
    {
      hspi->Instance->DR = *((const uint16_t *)hspi->pTxBuffPtr);
      hspi->pTxBuffPtr += sizeof(uint16_t);
      hspi->TxXferCount--;

#if (USE_SPI_CRC != 0U)
                                   
      if ((hspi->TxXferCount == 0U) && (hspi->Init.CRCCalculation == SPI_CRCCALCULATION_ENABLE))
      {
                                                                                               
        if ((READ_BIT(spi_cr1, SPI_CR1_MSTR) == 0U) && (READ_BIT(spi_cr2, SPI_CR2_NSSP) == SPI_CR2_NSSP))
        {
          SET_BIT(hspi->Instance->CR1, SPI_CR1_SSM);
        }
        SET_BIT(hspi->Instance->CR1, SPI_CR1_CRCNEXT);
      }
#endif                  

    }
    while ((hspi->TxXferCount > 0U) || (hspi->RxXferCount > 0U))
    {
                          
      if ((__HAL_SPI_GET_FLAG(hspi, SPI_FLAG_TXE)) && (hspi->TxXferCount > 0U) && (txallowed == 1U))
      {
        hspi->Instance->DR = *((const uint16_t *)hspi->pTxBuffPtr);
        hspi->pTxBuffPtr += sizeof(uint16_t);
        hspi->TxXferCount--;
                                                           
        txallowed = 0U;

#if (USE_SPI_CRC != 0U)
                                     
        if ((hspi->TxXferCount == 0U) && (hspi->Init.CRCCalculation == SPI_CRCCALCULATION_ENABLE))
        {
                                                                                                 
          if ((READ_BIT(spi_cr1, SPI_CR1_MSTR) == 0U) && (READ_BIT(spi_cr2, SPI_CR2_NSSP) == SPI_CR2_NSSP))
          {
            SET_BIT(hspi->Instance->CR1, SPI_CR1_SSM);
          }
          SET_BIT(hspi->Instance->CR1, SPI_CR1_CRCNEXT);
        }
#endif                  
      }

                           
      if ((__HAL_SPI_GET_FLAG(hspi, SPI_FLAG_RXNE)) && (hspi->RxXferCount > 0U))
      {
        *((uint16_t *)hspi->pRxBuffPtr) = (uint16_t)hspi->Instance->DR;
        hspi->pRxBuffPtr += sizeof(uint16_t);
        hspi->RxXferCount--;
                                                             
        txallowed = 1U;
      }
      if (((HAL_GetTick() - tickstart) >=  Timeout) && (Timeout != HAL_MAX_DELAY))
      {
        hspi->State = HAL_SPI_STATE_READY;
        __HAL_UNLOCK(hspi);
        return HAL_TIMEOUT;
      }
    }
  }
                                               
  else
  {
    if ((hspi->Init.Mode == SPI_MODE_SLAVE) || (initial_TxXferCount == 0x01U))
    {
      if (hspi->TxXferCount > 1U)
      {
        hspi->Instance->DR = *((const uint16_t *)hspi->pTxBuffPtr);
        hspi->pTxBuffPtr += sizeof(uint16_t);
        hspi->TxXferCount -= 2U;
      }
      else
      {
        *(__IO uint8_t *)&hspi->Instance->DR = *((const uint8_t *)hspi->pTxBuffPtr);
        hspi->pTxBuffPtr++;
        hspi->TxXferCount--;

#if (USE_SPI_CRC != 0U)
                                     
        if ((hspi->TxXferCount == 0U) && (hspi->Init.CRCCalculation == SPI_CRCCALCULATION_ENABLE))
        {
                                                                                                 
          if ((READ_BIT(spi_cr1, SPI_CR1_MSTR) == 0U) && (READ_BIT(spi_cr2, SPI_CR2_NSSP) == SPI_CR2_NSSP))
          {
            SET_BIT(hspi->Instance->CR1, SPI_CR1_SSM);
          }
          SET_BIT(hspi->Instance->CR1, SPI_CR1_CRCNEXT);
        }
#endif                  
      }
    }
    while ((hspi->TxXferCount > 0U) || (hspi->RxXferCount > 0U))
    {
                          
      if ((__HAL_SPI_GET_FLAG(hspi, SPI_FLAG_TXE)) && (hspi->TxXferCount > 0U) && (txallowed == 1U))
      {
        if (hspi->TxXferCount > 1U)
        {
          hspi->Instance->DR = *((const uint16_t *)hspi->pTxBuffPtr);
          hspi->pTxBuffPtr += sizeof(uint16_t);
          hspi->TxXferCount -= 2U;
        }
        else
        {
          *(__IO uint8_t *)&hspi->Instance->DR = *((const uint8_t *)hspi->pTxBuffPtr);
          hspi->pTxBuffPtr++;
          hspi->TxXferCount--;
        }
                                                           
        txallowed = 0U;

#if (USE_SPI_CRC != 0U)
                                     
        if ((hspi->TxXferCount == 0U) && (hspi->Init.CRCCalculation == SPI_CRCCALCULATION_ENABLE))
        {
                                                                                                 
          if ((READ_BIT(spi_cr1, SPI_CR1_MSTR) == 0U) && (READ_BIT(spi_cr2, SPI_CR2_NSSP) == SPI_CR2_NSSP))
          {
            SET_BIT(hspi->Instance->CR1, SPI_CR1_SSM);
          }
          SET_BIT(hspi->Instance->CR1, SPI_CR1_CRCNEXT);
        }
#endif                  
      }

                                         
      if ((__HAL_SPI_GET_FLAG(hspi, SPI_FLAG_RXNE)) && (hspi->RxXferCount > 0U))
      {
        if (hspi->RxXferCount > 1U)
        {
          *((uint16_t *)hspi->pRxBuffPtr) = (uint16_t)hspi->Instance->DR;
          hspi->pRxBuffPtr += sizeof(uint16_t);
          hspi->RxXferCount -= 2U;
          if (hspi->RxXferCount <= 1U)
          {
                                                                           
            SET_BIT(hspi->Instance->CR2, SPI_RXFIFO_THRESHOLD);
          }
        }
        else
        {
          (*(uint8_t *)hspi->pRxBuffPtr) = *(__IO uint8_t *)&hspi->Instance->DR;
          hspi->pRxBuffPtr++;
          hspi->RxXferCount--;
        }
                                                             
        txallowed = 1U;
      }
      if ((((HAL_GetTick() - tickstart) >=  Timeout) && ((Timeout != HAL_MAX_DELAY))) || (Timeout == 0U))
      {
        hspi->State = HAL_SPI_STATE_READY;
        __HAL_UNLOCK(hspi);
        return HAL_TIMEOUT;
      }
    }
  }

#if (USE_SPI_CRC != 0U)
                                                         
  if (hspi->Init.CRCCalculation == SPI_CRCCALCULATION_ENABLE)
  {
                             
    if (SPI_WaitFlagStateUntilTimeout(hspi, SPI_FLAG_RXNE, SET, Timeout, tickstart) != HAL_OK)
    {
                                      
      SET_BIT(hspi->ErrorCode, HAL_SPI_ERROR_CRC);
      hspi->State = HAL_SPI_STATE_READY;
      __HAL_UNLOCK(hspi);
      return HAL_TIMEOUT;
    }
                  
    if (hspi->Init.DataSize == SPI_DATASIZE_16BIT)
    {
                          
      tmpreg = READ_REG(hspi->Instance->DR);
                                
      UNUSED(tmpreg);
    }
    else
    {
                                                 
      ptmpreg8 = (__IO uint8_t *)&hspi->Instance->DR;
                         
      tmpreg8 = *ptmpreg8;
                                
      UNUSED(tmpreg8);

      if (hspi->Init.CRCLength == SPI_CRC_LENGTH_16BIT)
      {
        if (SPI_WaitFlagStateUntilTimeout(hspi, SPI_FLAG_RXNE, SET, Timeout, tickstart) != HAL_OK)
        {
                                          
          SET_BIT(hspi->ErrorCode, HAL_SPI_ERROR_CRC);
          hspi->State = HAL_SPI_STATE_READY;
          __HAL_UNLOCK(hspi);
          return HAL_TIMEOUT;
        }
                                                                        
        tmpreg8 = *ptmpreg8;
                                  
        UNUSED(tmpreg8);
      }
    }
  }

                                   
  if (__HAL_SPI_GET_FLAG(hspi, SPI_FLAG_CRCERR))
  {
    SET_BIT(hspi->ErrorCode, HAL_SPI_ERROR_CRC);
                        
    __HAL_SPI_CLEAR_CRCERRFLAG(hspi);
    __HAL_UNLOCK(hspi);
    return HAL_ERROR;
  }
#endif                  

                                        
  if (SPI_EndRxTxTransaction(hspi, Timeout, tickstart) != HAL_OK)
  {
    hspi->ErrorCode = HAL_SPI_ERROR_FLAG;
    __HAL_UNLOCK(hspi);
    return HAL_ERROR;
  }


  hspi->State = HAL_SPI_STATE_READY;
                          
  __HAL_UNLOCK(hspi);

  if (hspi->ErrorCode != HAL_SPI_ERROR_NONE)
  {
    return HAL_ERROR;
  }
  else
  {
    return HAL_OK;
  }
}

   
                                                                           
                                                                       
                                                               
                                                                  
                                                               
                      
    
HAL_StatusTypeDef HAL_SPI_Transmit_IT(SPI_HandleTypeDef *hspi, const uint8_t *pData, uint16_t Size)
{

                                 
  assert_param(IS_SPI_DIRECTION_2LINES_OR_1LINE(hspi->Init.Direction));


  if ((pData == NULL) || (Size == 0U))
  {
    return HAL_ERROR;
  }

  if (hspi->State != HAL_SPI_STATE_READY)
  {
    return HAL_BUSY;
  }

                      
  __HAL_LOCK(hspi);

                                       
  hspi->State       = HAL_SPI_STATE_BUSY_TX;
  hspi->ErrorCode   = HAL_SPI_ERROR_NONE;
  hspi->pTxBuffPtr  = (const uint8_t *)pData;
  hspi->TxXferSize  = Size;
  hspi->TxXferCount = Size;

                                             
  hspi->pRxBuffPtr  = (uint8_t *)NULL;
  hspi->RxXferSize  = 0U;
  hspi->RxXferCount = 0U;
  hspi->RxISR       = NULL;

                                         
  if (hspi->Init.DataSize > SPI_DATASIZE_8BIT)
  {
    hspi->TxISR = SPI_TxISR_16BIT;
  }
  else
  {
    hspi->TxISR = SPI_TxISR_8BIT;
  }

                                                 
  if (hspi->Init.Direction == SPI_DIRECTION_1LINE)
  {
                                                                        
    __HAL_SPI_DISABLE(hspi);
    SPI_1LINE_TX(hspi);
  }

#if (USE_SPI_CRC != 0U)
                             
  if (hspi->Init.CRCCalculation == SPI_CRCCALCULATION_ENABLE)
  {
    SPI_RESET_CRC(hspi);
  }
#endif                  

                                           
  if ((hspi->Instance->CR1 & SPI_CR1_SPE) != SPI_CR1_SPE)
  {
                               
    __HAL_SPI_ENABLE(hspi);
  }

                        
  __HAL_UNLOCK(hspi);
                                    
  __HAL_SPI_ENABLE_IT(hspi, (SPI_IT_TXE | SPI_IT_ERR));

  return HAL_OK;
}

   
                                                                          
                                                                       
                                                               
                                                                  
                                                                   
                      
    
HAL_StatusTypeDef HAL_SPI_Receive_IT(SPI_HandleTypeDef *hspi, uint8_t *pData, uint16_t Size)
{

  if (hspi->State != HAL_SPI_STATE_READY)
  {
    return HAL_BUSY;
  }

  if ((pData == NULL) || (Size == 0U))
  {
    return HAL_ERROR;
  }

  if ((hspi->Init.Direction == SPI_DIRECTION_2LINES) && (hspi->Init.Mode == SPI_MODE_MASTER))
  {
    hspi->State = HAL_SPI_STATE_BUSY_RX;
                                                                                                     
    return HAL_SPI_TransmitReceive_IT(hspi, pData, pData, Size);
  }


                      
  __HAL_LOCK(hspi);

                                       
  hspi->State       = HAL_SPI_STATE_BUSY_RX;
  hspi->ErrorCode   = HAL_SPI_ERROR_NONE;
  hspi->pRxBuffPtr  = (uint8_t *)pData;
  hspi->RxXferSize  = Size;
  hspi->RxXferCount = Size;

                                             
  hspi->pTxBuffPtr  = (uint8_t *)NULL;
  hspi->TxXferSize  = 0U;
  hspi->TxXferCount = 0U;
  hspi->TxISR       = NULL;

                                                                                           
  if (hspi->Init.DataSize > SPI_DATASIZE_8BIT)
  {
                                                                           
    CLEAR_BIT(hspi->Instance->CR2, SPI_RXFIFO_THRESHOLD);
    hspi->RxISR = SPI_RxISR_16BIT;
  }
  else
  {
                                                                          
    SET_BIT(hspi->Instance->CR2, SPI_RXFIFO_THRESHOLD);
    hspi->RxISR = SPI_RxISR_8BIT;
  }

                                                 
  if (hspi->Init.Direction == SPI_DIRECTION_1LINE)
  {
                                                                        
    __HAL_SPI_DISABLE(hspi);
    SPI_1LINE_RX(hspi);
  }

#if (USE_SPI_CRC != 0U)
                             
  if (hspi->Init.CRCCalculation == SPI_CRCCALCULATION_ENABLE)
  {
    hspi->CRCSize = 1U;
    if ((hspi->Init.DataSize <= SPI_DATASIZE_8BIT) && (hspi->Init.CRCLength == SPI_CRC_LENGTH_16BIT))
    {
      hspi->CRCSize = 2U;
    }
    SPI_RESET_CRC(hspi);
  }
  else
  {
    hspi->CRCSize = 0U;
  }
#endif                  

                                                                   
                                                                              
                             

                                           
  if ((hspi->Instance->CR1 & SPI_CR1_SPE) != SPI_CR1_SPE)
  {
                               
    __HAL_SPI_ENABLE(hspi);
  }

                        
  __HAL_UNLOCK(hspi);
                                     
  __HAL_SPI_ENABLE_IT(hspi, (SPI_IT_RXNE | SPI_IT_ERR));

  return HAL_OK;
}

   
                                                                                       
                                                                       
                                                               
                                                                                 
                                                                              
                                                                            
                      
    
HAL_StatusTypeDef HAL_SPI_TransmitReceive_IT(SPI_HandleTypeDef *hspi, const uint8_t *pTxData, uint8_t *pRxData,
                                             uint16_t Size)
{
  uint32_t             tmp_mode;
  HAL_SPI_StateTypeDef tmp_state;

                                 
  assert_param(IS_SPI_DIRECTION_2LINES(hspi->Init.Direction));

                                
  tmp_state           = hspi->State;
  tmp_mode            = hspi->Init.Mode;

  if (!((tmp_state == HAL_SPI_STATE_READY) || \
        ((tmp_mode == SPI_MODE_MASTER) && (hspi->Init.Direction == SPI_DIRECTION_2LINES) &&
         (tmp_state == HAL_SPI_STATE_BUSY_RX))))
  {
    return HAL_BUSY;
  }

  if ((pTxData == NULL) || (pRxData == NULL) || (Size == 0U))
  {
    return HAL_ERROR;
  }

                      
  __HAL_LOCK(hspi);

                                                        
  if (hspi->State != HAL_SPI_STATE_BUSY_RX)
  {
    hspi->State = HAL_SPI_STATE_BUSY_TX_RX;
  }

                                       
  hspi->ErrorCode   = HAL_SPI_ERROR_NONE;
  hspi->pTxBuffPtr  = (const uint8_t *)pTxData;
  hspi->TxXferSize  = Size;
  hspi->TxXferCount = Size;
  hspi->pRxBuffPtr  = (uint8_t *)pRxData;
  hspi->RxXferSize  = Size;
  hspi->RxXferCount = Size;

                                         
  if (hspi->Init.DataSize > SPI_DATASIZE_8BIT)
  {
    hspi->RxISR     = SPI_2linesRxISR_16BIT;
    hspi->TxISR     = SPI_2linesTxISR_16BIT;
  }
  else
  {
    hspi->RxISR     = SPI_2linesRxISR_8BIT;
    hspi->TxISR     = SPI_2linesTxISR_8BIT;
  }

#if (USE_SPI_CRC != 0U)
                             
  if (hspi->Init.CRCCalculation == SPI_CRCCALCULATION_ENABLE)
  {
    hspi->CRCSize = 1U;
    if ((hspi->Init.DataSize <= SPI_DATASIZE_8BIT) && (hspi->Init.CRCLength == SPI_CRC_LENGTH_16BIT))
    {
      hspi->CRCSize = 2U;
    }
    SPI_RESET_CRC(hspi);
  }
  else
  {
    hspi->CRCSize = 0U;
  }
#endif                  

                                                                                    
  if ((hspi->Init.DataSize > SPI_DATASIZE_8BIT) || (Size >= 2U))
  {
                                                                           
    CLEAR_BIT(hspi->Instance->CR2, SPI_RXFIFO_THRESHOLD);
  }
  else
  {
                                                                          
    SET_BIT(hspi->Instance->CR2, SPI_RXFIFO_THRESHOLD);
  }


                                           
  if ((hspi->Instance->CR1 & SPI_CR1_SPE) != SPI_CR1_SPE)
  {
                               
    __HAL_SPI_ENABLE(hspi);
  }

                        
  __HAL_UNLOCK(hspi);
                                          
  __HAL_SPI_ENABLE_IT(hspi, (SPI_IT_TXE | SPI_IT_RXNE | SPI_IT_ERR));

  return HAL_OK;
}

   
                                                                     
                                                                       
                                                               
                                                                   
                                                               
                      
    
HAL_StatusTypeDef HAL_SPI_Transmit_DMA(SPI_HandleTypeDef *hspi, const uint8_t *pData, uint16_t Size)
{

                           
  assert_param(IS_SPI_DMA_HANDLE(hspi->hdmatx));

                                 
  assert_param(IS_SPI_DIRECTION_2LINES_OR_1LINE(hspi->Init.Direction));

  if (hspi->State != HAL_SPI_STATE_READY)
  {
    return HAL_BUSY;
  }

  if ((pData == NULL) || (Size == 0U))
  {
    return HAL_ERROR;
  }

                      
  __HAL_LOCK(hspi);

                                       
  hspi->State       = HAL_SPI_STATE_BUSY_TX;
  hspi->ErrorCode   = HAL_SPI_ERROR_NONE;
  hspi->pTxBuffPtr  = (const uint8_t *)pData;
  hspi->TxXferSize  = Size;
  hspi->TxXferCount = Size;

                                             
  hspi->pRxBuffPtr  = (uint8_t *)NULL;
  hspi->TxISR       = NULL;
  hspi->RxISR       = NULL;
  hspi->RxXferSize  = 0U;
  hspi->RxXferCount = 0U;

                                                 
  if (hspi->Init.Direction == SPI_DIRECTION_1LINE)
  {
                                                                        
    __HAL_SPI_DISABLE(hspi);
    SPI_1LINE_TX(hspi);
  }

#if (USE_SPI_CRC != 0U)
                             
  if (hspi->Init.CRCCalculation == SPI_CRCCALCULATION_ENABLE)
  {
    SPI_RESET_CRC(hspi);
  }
#endif                  

                                                         
  hspi->hdmatx->XferHalfCpltCallback = SPI_DMAHalfTransmitCplt;

                                                    
  hspi->hdmatx->XferCpltCallback = SPI_DMATransmitCplt;

                                  
  hspi->hdmatx->XferErrorCallback = SPI_DMAError;

                                     
  hspi->hdmatx->XferAbortCallback = NULL;

  CLEAR_BIT(hspi->Instance->CR2, SPI_CR2_LDMATX);
                                                                  
  if ((hspi->Init.DataSize <= SPI_DATASIZE_8BIT) && (hspi->hdmatx->Init.MemDataAlignment == DMA_MDATAALIGN_HALFWORD))
  {
                                                              
    if ((hspi->TxXferCount & 0x1U) == 0U)
    {
      CLEAR_BIT(hspi->Instance->CR2, SPI_CR2_LDMATX);
      hspi->TxXferCount = (hspi->TxXferCount >> 1U);
    }
    else
    {
      SET_BIT(hspi->Instance->CR2, SPI_CR2_LDMATX);
      hspi->TxXferCount = (hspi->TxXferCount >> 1U) + 1U;
    }
  }

                                        
  if (HAL_OK != HAL_DMA_Start_IT(hspi->hdmatx, (uint32_t)hspi->pTxBuffPtr, (uint32_t)&hspi->Instance->DR,
                                 hspi->TxXferCount))
  {
                               
    SET_BIT(hspi->ErrorCode, HAL_SPI_ERROR_DMA);
                          
    __HAL_UNLOCK(hspi);
    return HAL_ERROR;
  }

                                           
  if ((hspi->Instance->CR1 & SPI_CR1_SPE) != SPI_CR1_SPE)
  {
                               
    __HAL_SPI_ENABLE(hspi);
  }

                        
  __HAL_UNLOCK(hspi);

                                          
  __HAL_SPI_ENABLE_IT(hspi, (SPI_IT_ERR));

                             
  SET_BIT(hspi->Instance->CR2, SPI_CR2_TXDMAEN);

  return HAL_OK;
}

   
                                                                    
                                                                                               
                                                                       
                                                               
                                                                  
                                                                              
                                                                   
                      
    
HAL_StatusTypeDef HAL_SPI_Receive_DMA(SPI_HandleTypeDef *hspi, uint8_t *pData, uint16_t Size)
{
                           
  assert_param(IS_SPI_DMA_HANDLE(hspi->hdmarx));

  if (hspi->State != HAL_SPI_STATE_READY)
  {
    return HAL_BUSY;
  }

  if ((pData == NULL) || (Size == 0U))
  {
    return HAL_ERROR;
  }

  if ((hspi->Init.Direction == SPI_DIRECTION_2LINES) && (hspi->Init.Mode == SPI_MODE_MASTER))
  {
    hspi->State = HAL_SPI_STATE_BUSY_RX;

                             
    assert_param(IS_SPI_DMA_HANDLE(hspi->hdmatx));

                                                                                                     
    return HAL_SPI_TransmitReceive_DMA(hspi, pData, pData, Size);
  }

                      
  __HAL_LOCK(hspi);

                                       
  hspi->State       = HAL_SPI_STATE_BUSY_RX;
  hspi->ErrorCode   = HAL_SPI_ERROR_NONE;
  hspi->pRxBuffPtr  = (uint8_t *)pData;
  hspi->RxXferSize  = Size;
  hspi->RxXferCount = Size;

                                            
  hspi->RxISR       = NULL;
  hspi->TxISR       = NULL;
  hspi->TxXferSize  = 0U;
  hspi->TxXferCount = 0U;

                                                 
  if (hspi->Init.Direction == SPI_DIRECTION_1LINE)
  {
                                                                        
    __HAL_SPI_DISABLE(hspi);
    SPI_1LINE_RX(hspi);
  }

#if (USE_SPI_CRC != 0U)
                             
  if (hspi->Init.CRCCalculation == SPI_CRCCALCULATION_ENABLE)
  {
    SPI_RESET_CRC(hspi);
  }
#endif                  


  CLEAR_BIT(hspi->Instance->CR2, SPI_CR2_LDMARX);
  if (hspi->Init.DataSize > SPI_DATASIZE_8BIT)
  {
                                                                          
    CLEAR_BIT(hspi->Instance->CR2, SPI_RXFIFO_THRESHOLD);
  }
  else
  {
                                                                         
    SET_BIT(hspi->Instance->CR2, SPI_RXFIFO_THRESHOLD);

    if (hspi->hdmarx->Init.MemDataAlignment == DMA_MDATAALIGN_HALFWORD)
    {
                                                                            
      CLEAR_BIT(hspi->Instance->CR2, SPI_RXFIFO_THRESHOLD);

      if ((hspi->RxXferCount & 0x1U) == 0x0U)
      {
        CLEAR_BIT(hspi->Instance->CR2, SPI_CR2_LDMARX);
        hspi->RxXferCount = hspi->RxXferCount >> 1U;
      }
      else
      {
        SET_BIT(hspi->Instance->CR2, SPI_CR2_LDMARX);
        hspi->RxXferCount = (hspi->RxXferCount >> 1U) + 1U;
      }
    }
  }

                                                         
  hspi->hdmarx->XferHalfCpltCallback = SPI_DMAHalfReceiveCplt;

                                                     
  hspi->hdmarx->XferCpltCallback = SPI_DMAReceiveCplt;

                                  
  hspi->hdmarx->XferErrorCallback = SPI_DMAError;

                                     
  hspi->hdmarx->XferAbortCallback = NULL;

                                         
  if (HAL_OK != HAL_DMA_Start_IT(hspi->hdmarx, (uint32_t)&hspi->Instance->DR, (uint32_t)hspi->pRxBuffPtr,
                                 hspi->RxXferCount))
  {
                               
    SET_BIT(hspi->ErrorCode, HAL_SPI_ERROR_DMA);
                          
    __HAL_UNLOCK(hspi);
    return HAL_ERROR;
  }

                                           
  if ((hspi->Instance->CR1 & SPI_CR1_SPE) != SPI_CR1_SPE)
  {
                               
    __HAL_SPI_ENABLE(hspi);
  }

                        
  __HAL_UNLOCK(hspi);

                                          
  __HAL_SPI_ENABLE_IT(hspi, (SPI_IT_ERR));

                             
  SET_BIT(hspi->Instance->CR2, SPI_CR2_RXDMAEN);

  return HAL_OK;
}

   
                                                                                 
                                                                       
                                                               
                                                                                 
                                                                              
                                                                               
                                                                            
                      
    
HAL_StatusTypeDef HAL_SPI_TransmitReceive_DMA(SPI_HandleTypeDef *hspi, const uint8_t *pTxData, uint8_t *pRxData,
                                              uint16_t Size)
{
  uint32_t             tmp_mode;
  HAL_SPI_StateTypeDef tmp_state;

                                 
  assert_param(IS_SPI_DMA_HANDLE(hspi->hdmarx));
  assert_param(IS_SPI_DMA_HANDLE(hspi->hdmatx));

                                 
  assert_param(IS_SPI_DIRECTION_2LINES(hspi->Init.Direction));

                                
  tmp_state           = hspi->State;
  tmp_mode            = hspi->Init.Mode;

  if (!((tmp_state == HAL_SPI_STATE_READY) ||
        ((tmp_mode == SPI_MODE_MASTER) && (hspi->Init.Direction == SPI_DIRECTION_2LINES) &&
         (tmp_state == HAL_SPI_STATE_BUSY_RX))))
  {
    return HAL_BUSY;
  }

  if ((pTxData == NULL) || (pRxData == NULL) || (Size == 0U))
  {
    return HAL_ERROR;
  }

                      
  __HAL_LOCK(hspi);

                                                        
  if (hspi->State != HAL_SPI_STATE_BUSY_RX)
  {
    hspi->State = HAL_SPI_STATE_BUSY_TX_RX;
  }

                                       
  hspi->ErrorCode   = HAL_SPI_ERROR_NONE;
  hspi->pTxBuffPtr  = (const uint8_t *)pTxData;
  hspi->TxXferSize  = Size;
  hspi->TxXferCount = Size;
  hspi->pRxBuffPtr  = (uint8_t *)pRxData;
  hspi->RxXferSize  = Size;
  hspi->RxXferCount = Size;

                                             
  hspi->RxISR       = NULL;
  hspi->TxISR       = NULL;

#if (USE_SPI_CRC != 0U)
                             
  if (hspi->Init.CRCCalculation == SPI_CRCCALCULATION_ENABLE)
  {
    SPI_RESET_CRC(hspi);
  }
#endif                  

                               
  CLEAR_BIT(hspi->Instance->CR2, SPI_CR2_LDMATX | SPI_CR2_LDMARX);

                                                                                              
  if (hspi->Init.DataSize > SPI_DATASIZE_8BIT)
  {
                                                                        
    CLEAR_BIT(hspi->Instance->CR2, SPI_RXFIFO_THRESHOLD);
  }
  else
  {
                                                                         
    SET_BIT(hspi->Instance->CR2, SPI_RXFIFO_THRESHOLD);

    if (hspi->hdmatx->Init.MemDataAlignment == DMA_MDATAALIGN_HALFWORD)
    {
      if ((hspi->TxXferSize & 0x1U) == 0x0U)
      {
        CLEAR_BIT(hspi->Instance->CR2, SPI_CR2_LDMATX);
        hspi->TxXferCount = hspi->TxXferCount >> 1U;
      }
      else
      {
        SET_BIT(hspi->Instance->CR2, SPI_CR2_LDMATX);
        hspi->TxXferCount = (hspi->TxXferCount >> 1U) + 1U;
      }
    }

    if (hspi->hdmarx->Init.MemDataAlignment == DMA_MDATAALIGN_HALFWORD)
    {
                                                                            
      CLEAR_BIT(hspi->Instance->CR2, SPI_RXFIFO_THRESHOLD);

      if ((hspi->RxXferCount & 0x1U) == 0x0U)
      {
        CLEAR_BIT(hspi->Instance->CR2, SPI_CR2_LDMARX);
        hspi->RxXferCount = hspi->RxXferCount >> 1U;
      }
      else
      {
        SET_BIT(hspi->Instance->CR2, SPI_CR2_LDMARX);
        hspi->RxXferCount = (hspi->RxXferCount >> 1U) + 1U;
      }
    }
  }

                                                                                                    
  if (hspi->State == HAL_SPI_STATE_BUSY_RX)
  {
                                                            
    hspi->hdmarx->XferHalfCpltCallback = SPI_DMAHalfReceiveCplt;
    hspi->hdmarx->XferCpltCallback     = SPI_DMAReceiveCplt;
  }
  else
  {
                                                               
    hspi->hdmarx->XferHalfCpltCallback = SPI_DMAHalfTransmitReceiveCplt;
    hspi->hdmarx->XferCpltCallback     = SPI_DMATransmitReceiveCplt;
  }

                                  
  hspi->hdmarx->XferErrorCallback = SPI_DMAError;

                                     
  hspi->hdmarx->XferAbortCallback = NULL;

                                         
  if (HAL_OK != HAL_DMA_Start_IT(hspi->hdmarx, (uint32_t)&hspi->Instance->DR, (uint32_t)hspi->pRxBuffPtr,
                                 hspi->RxXferCount))
  {
                               
    SET_BIT(hspi->ErrorCode, HAL_SPI_ERROR_DMA);
                          
    __HAL_UNLOCK(hspi);
    return HAL_ERROR;
  }

                             
  SET_BIT(hspi->Instance->CR2, SPI_CR2_RXDMAEN);

                                                                                            
                                                     
  hspi->hdmatx->XferHalfCpltCallback = NULL;
  hspi->hdmatx->XferCpltCallback     = NULL;
  hspi->hdmatx->XferErrorCallback    = NULL;
  hspi->hdmatx->XferAbortCallback    = NULL;

                                         
  if (HAL_OK != HAL_DMA_Start_IT(hspi->hdmatx, (uint32_t)hspi->pTxBuffPtr, (uint32_t)&hspi->Instance->DR,
                                 hspi->TxXferCount))
  {
                               
    SET_BIT(hspi->ErrorCode, HAL_SPI_ERROR_DMA);
                          
    __HAL_UNLOCK(hspi);
    return HAL_ERROR;
  }

                                           
  if ((hspi->Instance->CR1 & SPI_CR1_SPE) != SPI_CR1_SPE)
  {
                               
    __HAL_SPI_ENABLE(hspi);
  }

                        
  __HAL_UNLOCK(hspi);

                                          
  __HAL_SPI_ENABLE_IT(hspi, (SPI_IT_ERR));

                             
  SET_BIT(hspi->Instance->CR2, SPI_CR2_TXDMAEN);

  return HAL_OK;
}

   
                                                   
                            
                                                                                       
                                             
                                                          
                                                                        
                                                                                
                                                                                             
                                         
                                                                                                                  
                      
    
HAL_StatusTypeDef HAL_SPI_Abort(SPI_HandleTypeDef *hspi)
{
  HAL_StatusTypeDef errorcode;
  __IO uint32_t count;
  __IO uint32_t resetcount;

                                   
  errorcode = HAL_OK;
  resetcount = SPI_DEFAULT_TIMEOUT * (SystemCoreClock / 24U / 1000U);
  count = resetcount;

                                                                                         
  CLEAR_BIT(hspi->Instance->CR2, SPI_CR2_ERRIE);

                                                                                                   
  if (HAL_IS_BIT_SET(hspi->Instance->CR2, SPI_CR2_TXEIE))
  {
    hspi->TxISR = SPI_AbortTx_ISR;
                                        
    do
    {
      if (count == 0U)
      {
        SET_BIT(hspi->ErrorCode, HAL_SPI_ERROR_ABORT);
        break;
      }
      count--;
    } while (hspi->State != HAL_SPI_STATE_ABORT);
                               
    count = resetcount;
  }

  if (HAL_IS_BIT_SET(hspi->Instance->CR2, SPI_CR2_RXNEIE))
  {
    hspi->RxISR = SPI_AbortRx_ISR;
                                        
    do
    {
      if (count == 0U)
      {
        SET_BIT(hspi->ErrorCode, HAL_SPI_ERROR_ABORT);
        break;
      }
      count--;
    } while (hspi->State != HAL_SPI_STATE_ABORT);
                               
    count = resetcount;
  }

                                                 
  if (HAL_IS_BIT_SET(hspi->Instance->CR2, SPI_CR2_TXDMAEN))
  {
                                                                                        
    if (hspi->hdmatx != NULL)
    {
                                         
                                                                                    
      hspi->hdmatx->XferAbortCallback = NULL;

                                                        
      if (HAL_DMA_Abort(hspi->hdmatx) != HAL_OK)
      {
        hspi->ErrorCode = HAL_SPI_ERROR_ABORT;
      }

                                  
      CLEAR_BIT(hspi->Instance->CR2, (SPI_CR2_TXDMAEN));

      if (SPI_EndRxTxTransaction(hspi, SPI_DEFAULT_TIMEOUT, HAL_GetTick()) != HAL_OK)
      {
        hspi->ErrorCode = HAL_SPI_ERROR_ABORT;
      }

                                  
      __HAL_SPI_DISABLE(hspi);

                                
      if (SPI_WaitFifoStateUntilTimeout(hspi, SPI_FLAG_FRLVL, SPI_FRLVL_EMPTY, SPI_DEFAULT_TIMEOUT,
                                        HAL_GetTick()) != HAL_OK)
      {
        hspi->ErrorCode = HAL_SPI_ERROR_ABORT;
      }
    }
  }

                                                 
  if (HAL_IS_BIT_SET(hspi->Instance->CR2, SPI_CR2_RXDMAEN))
  {
                                                                                        
    if (hspi->hdmarx != NULL)
    {
                                         
                                                                                    
      hspi->hdmarx->XferAbortCallback = NULL;

                                                        
      if (HAL_DMA_Abort(hspi->hdmarx) != HAL_OK)
      {
        hspi->ErrorCode = HAL_SPI_ERROR_ABORT;
      }

                              
      __HAL_SPI_DISABLE(hspi);

                                
      if (SPI_WaitFlagStateUntilTimeout(hspi, SPI_FLAG_BSY, RESET, SPI_DEFAULT_TIMEOUT, HAL_GetTick()) != HAL_OK)
      {
        hspi->ErrorCode = HAL_SPI_ERROR_ABORT;
      }

                                
      if (SPI_WaitFifoStateUntilTimeout(hspi, SPI_FLAG_FRLVL, SPI_FRLVL_EMPTY, SPI_DEFAULT_TIMEOUT,
                                        HAL_GetTick()) != HAL_OK)
      {
        hspi->ErrorCode = HAL_SPI_ERROR_ABORT;
      }

                                  
      CLEAR_BIT(hspi->Instance->CR2, (SPI_CR2_RXDMAEN));
    }
  }
                                         
  hspi->RxXferCount = 0U;
  hspi->TxXferCount = 0U;

                                          
  if (hspi->ErrorCode == HAL_SPI_ERROR_ABORT)
  {
                                                                  
    errorcode = HAL_ERROR;
  }
  else
  {
                         
    hspi->ErrorCode = HAL_SPI_ERROR_NONE;
  }

                                                
  __HAL_SPI_CLEAR_OVRFLAG(hspi);
  __HAL_SPI_CLEAR_FREFLAG(hspi);

                                    
  hspi->State = HAL_SPI_STATE_READY;

  return errorcode;
}

   
                                                    
                            
                                                                                       
                                             
                                                          
                                                                        
                                                                                
                                                                                                
                                         
                                                                      
                                                                                               
                                                                                                                   
                      
    
HAL_StatusTypeDef HAL_SPI_Abort_IT(SPI_HandleTypeDef *hspi)
{
  HAL_StatusTypeDef errorcode;
  uint32_t abortcplt ;
  __IO uint32_t count;
  __IO uint32_t resetcount;

                                   
  errorcode = HAL_OK;
  abortcplt = 1U;
  resetcount = SPI_DEFAULT_TIMEOUT * (SystemCoreClock / 24U / 1000U);
  count = resetcount;

                                                                                         
  CLEAR_BIT(hspi->Instance->CR2, SPI_CR2_ERRIE);

                                                                                  
  if (HAL_IS_BIT_SET(hspi->Instance->CR2, SPI_CR2_TXEIE))
  {
    hspi->TxISR = SPI_AbortTx_ISR;
                                        
    do
    {
      if (count == 0U)
      {
        SET_BIT(hspi->ErrorCode, HAL_SPI_ERROR_ABORT);
        break;
      }
      count--;
    } while (hspi->State != HAL_SPI_STATE_ABORT);
                               
    count = resetcount;
  }

  if (HAL_IS_BIT_SET(hspi->Instance->CR2, SPI_CR2_RXNEIE))
  {
    hspi->RxISR = SPI_AbortRx_ISR;
                                        
    do
    {
      if (count == 0U)
      {
        SET_BIT(hspi->ErrorCode, HAL_SPI_ERROR_ABORT);
        break;
      }
      count--;
    } while (hspi->State != HAL_SPI_STATE_ABORT);
                               
    count = resetcount;
  }

                                                                                                                     
                                              
                              
  if (hspi->hdmatx != NULL)
  {
                                                                         
                                   
    if (HAL_IS_BIT_SET(hspi->Instance->CR2, SPI_CR2_TXDMAEN))
    {
      hspi->hdmatx->XferAbortCallback = SPI_DMATxAbortCallback;
    }
    else
    {
      hspi->hdmatx->XferAbortCallback = NULL;
    }
  }
                              
  if (hspi->hdmarx != NULL)
  {
                                                                         
                                   
    if (HAL_IS_BIT_SET(hspi->Instance->CR2, SPI_CR2_RXDMAEN))
    {
      hspi->hdmarx->XferAbortCallback = SPI_DMARxAbortCallback;
    }
    else
    {
      hspi->hdmarx->XferAbortCallback = NULL;
    }
  }

                                                 
  if (HAL_IS_BIT_SET(hspi->Instance->CR2, SPI_CR2_TXDMAEN))
  {
                                             
    if (hspi->hdmatx != NULL)
    {
                                                        
      if (HAL_DMA_Abort_IT(hspi->hdmatx) != HAL_OK)
      {
        hspi->hdmatx->XferAbortCallback = NULL;
        hspi->ErrorCode = HAL_SPI_ERROR_ABORT;
      }
      else
      {
        abortcplt = 0U;
      }
    }
  }
                                                 
  if (HAL_IS_BIT_SET(hspi->Instance->CR2, SPI_CR2_RXDMAEN))
  {
                                             
    if (hspi->hdmarx != NULL)
    {
                                                        
      if (HAL_DMA_Abort_IT(hspi->hdmarx) !=  HAL_OK)
      {
        hspi->hdmarx->XferAbortCallback = NULL;
        hspi->ErrorCode = HAL_SPI_ERROR_ABORT;
      }
      else
      {
        abortcplt = 0U;
      }
    }
  }

  if (abortcplt == 1U)
  {
                                           
    hspi->RxXferCount = 0U;
    hspi->TxXferCount = 0U;

                                            
    if (hspi->ErrorCode == HAL_SPI_ERROR_ABORT)
    {
                                                                    
      errorcode = HAL_ERROR;
    }
    else
    {
                           
      hspi->ErrorCode = HAL_SPI_ERROR_NONE;
    }

                                                  
    __HAL_SPI_CLEAR_OVRFLAG(hspi);
    __HAL_SPI_CLEAR_FREFLAG(hspi);

                                      
    hspi->State = HAL_SPI_STATE_READY;

                                                                             
#if (USE_HAL_SPI_REGISTER_CALLBACKS == 1U)
    hspi->AbortCpltCallback(hspi);
#else
    HAL_SPI_AbortCpltCallback(hspi);
#endif                                     
  }

  return errorcode;
}

   
                                   
                                                                       
                                                                             
                      
    
HAL_StatusTypeDef HAL_SPI_DMAPause(SPI_HandleTypeDef *hspi)
{
                      
  __HAL_LOCK(hspi);

                                            
  CLEAR_BIT(hspi->Instance->CR2, SPI_CR2_TXDMAEN | SPI_CR2_RXDMAEN);

                        
  __HAL_UNLOCK(hspi);

  return HAL_OK;
}

   
                                    
                                                                       
                                                                             
                      
    
HAL_StatusTypeDef HAL_SPI_DMAResume(SPI_HandleTypeDef *hspi)
{
                      
  __HAL_LOCK(hspi);

                                           
  SET_BIT(hspi->Instance->CR2, SPI_CR2_TXDMAEN | SPI_CR2_RXDMAEN);

                        
  __HAL_UNLOCK(hspi);

  return HAL_OK;
}

   
                                  
                                                                       
                                                                             
                      
    
HAL_StatusTypeDef HAL_SPI_DMAStop(SPI_HandleTypeDef *hspi)
{
  HAL_StatusTypeDef errorcode = HAL_OK;
                                                                          
                                                                                                    
                                
                                                                                            
                                                                                                     
                               
       

                                            
  if (hspi->hdmatx != NULL)
  {
    if (HAL_OK != HAL_DMA_Abort(hspi->hdmatx))
    {
      SET_BIT(hspi->ErrorCode, HAL_SPI_ERROR_DMA);
      errorcode = HAL_ERROR;
    }
  }
                                            
  if (hspi->hdmarx != NULL)
  {
    if (HAL_OK != HAL_DMA_Abort(hspi->hdmarx))
    {
      SET_BIT(hspi->ErrorCode, HAL_SPI_ERROR_DMA);
      errorcode = HAL_ERROR;
    }
  }

                                            
  CLEAR_BIT(hspi->Instance->CR2, SPI_CR2_TXDMAEN | SPI_CR2_RXDMAEN);
  hspi->State = HAL_SPI_STATE_READY;
  return errorcode;
}

   
                                         
                                                                       
                                                                             
                
    
void HAL_SPI_IRQHandler(SPI_HandleTypeDef *hspi)
{
  uint32_t itsource = hspi->Instance->CR2;
  uint32_t itflag   = hspi->Instance->SR;

                                                                                
  if ((SPI_CHECK_FLAG(itflag, SPI_FLAG_OVR) == RESET) &&
      (SPI_CHECK_FLAG(itflag, SPI_FLAG_RXNE) != RESET) && (SPI_CHECK_IT_SOURCE(itsource, SPI_IT_RXNE) != RESET))
  {
    hspi->RxISR(hspi);
    return;
  }

                                                                                
  if ((SPI_CHECK_FLAG(itflag, SPI_FLAG_TXE) != RESET) && (SPI_CHECK_IT_SOURCE(itsource, SPI_IT_TXE) != RESET))
  {
    hspi->TxISR(hspi);
    return;
  }

                                                                                
  if (((SPI_CHECK_FLAG(itflag, SPI_FLAG_MODF) != RESET) || (SPI_CHECK_FLAG(itflag, SPI_FLAG_OVR) != RESET)
       || (SPI_CHECK_FLAG(itflag, SPI_FLAG_FRE) != RESET)) && (SPI_CHECK_IT_SOURCE(itsource, SPI_IT_ERR) != RESET))
  {
                                                                                
    if (SPI_CHECK_FLAG(itflag, SPI_FLAG_OVR) != RESET)
    {
      if (hspi->State != HAL_SPI_STATE_BUSY_TX)
      {
        SET_BIT(hspi->ErrorCode, HAL_SPI_ERROR_OVR);
        __HAL_SPI_CLEAR_OVRFLAG(hspi);
      }
      else
      {
        __HAL_SPI_CLEAR_OVRFLAG(hspi);
        return;
      }
    }

                                                                                
    if (SPI_CHECK_FLAG(itflag, SPI_FLAG_MODF) != RESET)
    {
      SET_BIT(hspi->ErrorCode, HAL_SPI_ERROR_MODF);
      __HAL_SPI_CLEAR_MODFFLAG(hspi);
    }

                                                                                
    if (SPI_CHECK_FLAG(itflag, SPI_FLAG_FRE) != RESET)
    {
      SET_BIT(hspi->ErrorCode, HAL_SPI_ERROR_FRE);
      __HAL_SPI_CLEAR_FREFLAG(hspi);
    }

    if (hspi->ErrorCode != HAL_SPI_ERROR_NONE)
    {
                                  
      __HAL_SPI_DISABLE_IT(hspi, SPI_IT_RXNE | SPI_IT_TXE | SPI_IT_ERR);

      hspi->State = HAL_SPI_STATE_READY;
                                                   
      if ((HAL_IS_BIT_SET(itsource, SPI_CR2_TXDMAEN)) || (HAL_IS_BIT_SET(itsource, SPI_CR2_RXDMAEN)))
      {
        CLEAR_BIT(hspi->Instance->CR2, (SPI_CR2_TXDMAEN | SPI_CR2_RXDMAEN));

                                          
        if (hspi->hdmarx != NULL)
        {
                                             
                                                                                    
          hspi->hdmarx->XferAbortCallback = SPI_DMAAbortOnError;
          if (HAL_OK != HAL_DMA_Abort_IT(hspi->hdmarx))
          {
            SET_BIT(hspi->ErrorCode, HAL_SPI_ERROR_ABORT);
          }
        }
                                          
        if (hspi->hdmatx != NULL)
        {
                                             
                                                                                    
          hspi->hdmatx->XferAbortCallback = SPI_DMAAbortOnError;
          if (HAL_OK != HAL_DMA_Abort_IT(hspi->hdmatx))
          {
            SET_BIT(hspi->ErrorCode, HAL_SPI_ERROR_ABORT);
          }
        }
      }
      else
      {
                                      
#if (USE_HAL_SPI_REGISTER_CALLBACKS == 1U)
        hspi->ErrorCallback(hspi);
#else
        HAL_SPI_ErrorCallback(hspi);
#endif                                     
      }
    }
    return;
  }
}

   
                                           
                                                                       
                                                               
                
    
__weak void HAL_SPI_TxCpltCallback(SPI_HandleTypeDef *hspi)
{
                                                      
  UNUSED(hspi);

                                                                              
                                                                             
     
}

   
                                           
                                                                       
                                                               
                
    
__weak void HAL_SPI_RxCpltCallback(SPI_HandleTypeDef *hspi)
{
                                                      
  UNUSED(hspi);

                                                                              
                                                                             
     
}

   
                                                  
                                                                       
                                                               
                
    
__weak void HAL_SPI_TxRxCpltCallback(SPI_HandleTypeDef *hspi)
{
                                                      
  UNUSED(hspi);

                                                                              
                                                                               
     
}

   
                                                
                                                                       
                                                               
                
    
__weak void HAL_SPI_TxHalfCpltCallback(SPI_HandleTypeDef *hspi)
{
                                                      
  UNUSED(hspi);

                                                                              
                                                                                 
     
}

   
                                                
                                                                       
                                                               
                
    
__weak void HAL_SPI_RxHalfCpltCallback(SPI_HandleTypeDef *hspi)
{
                                                      
  UNUSED(hspi);

                                                                              
                                                                                   
     
}

   
                                             
                                                                       
                                                               
                
    
__weak void HAL_SPI_TxRxHalfCpltCallback(SPI_HandleTypeDef *hspi)
{
                                                      
  UNUSED(hspi);

                                                                              
                                                                                     
     
}

   
                               
                                                                       
                                                               
                
    
__weak void HAL_SPI_ErrorCallback(SPI_HandleTypeDef *hspi)
{
                                                      
  UNUSED(hspi);

                                                                              
                                                                            
     
                                                                                      
                                                                                      
     
}

   
                                        
                            
                
    
__weak void HAL_SPI_AbortCpltCallback(SPI_HandleTypeDef *hspi)
{
                                                      
  UNUSED(hspi);

                                                                              
                                                                              
     
}

   
      
    

                                                                                 
                                  
   
         
                                                                                
                                                                       
                                                                                
        
                                                                            
                                                                                                   
                                                                                   
            
      
    

   
                                        
                                                                       
                                                               
                     
    
HAL_SPI_StateTypeDef HAL_SPI_GetState(const SPI_HandleTypeDef *hspi)
{
                               
  return hspi->State;
}

   
                                      
                                                                       
                                                               
                                           
    
uint32_t HAL_SPI_GetError(const SPI_HandleTypeDef *hspi)
{
                            
  return hspi->ErrorCode;
}

   
      
    

   
      
    

                                     
                              
      
    

   
                                                       
                                                                       
                                                                             
                
    
static void SPI_DMATransmitCplt(DMA_HandleTypeDef *hdma)
{
  SPI_HandleTypeDef *hspi = (SPI_HandleTypeDef *)(((DMA_HandleTypeDef *)hdma)->Parent);
  uint32_t tickstart;

                                            
  tickstart = HAL_GetTick();

                       
  if ((hdma->Instance->CCR & DMA_CCR_CIRC) != DMA_CCR_CIRC)
  {
                               
    __HAL_SPI_DISABLE_IT(hspi, SPI_IT_ERR);

                                
    CLEAR_BIT(hspi->Instance->CR2, SPI_CR2_TXDMAEN);

                                          
    if (SPI_EndRxTxTransaction(hspi, SPI_DEFAULT_TIMEOUT, tickstart) != HAL_OK)
    {
      SET_BIT(hspi->ErrorCode, HAL_SPI_ERROR_FLAG);
    }

                                                                                            
    if (hspi->Init.Direction == SPI_DIRECTION_2LINES)
    {
      __HAL_SPI_CLEAR_OVRFLAG(hspi);
    }

    hspi->TxXferCount = 0U;
    hspi->State = HAL_SPI_STATE_READY;

    if (hspi->ErrorCode != HAL_SPI_ERROR_NONE)
    {
                                    
#if (USE_HAL_SPI_REGISTER_CALLBACKS == 1U)
      hspi->ErrorCallback(hspi);
#else
      HAL_SPI_ErrorCallback(hspi);
#endif                                     
      return;
    }
  }
                                      
#if (USE_HAL_SPI_REGISTER_CALLBACKS == 1U)
  hspi->TxCpltCallback(hspi);
#else
  HAL_SPI_TxCpltCallback(hspi);
#endif                                     
}

   
                                                      
                                                                       
                                                                             
                
    
static void SPI_DMAReceiveCplt(DMA_HandleTypeDef *hdma)
{
  SPI_HandleTypeDef *hspi = (SPI_HandleTypeDef *)(((DMA_HandleTypeDef *)hdma)->Parent);
  uint32_t tickstart;
#if (USE_SPI_CRC != 0U)
  __IO uint32_t tmpreg = 0U;
  __IO uint8_t  *ptmpreg8;
  __IO uint8_t  tmpreg8 = 0;
#endif                  

                                            
  tickstart = HAL_GetTick();

                       
  if ((hdma->Instance->CCR & DMA_CCR_CIRC) != DMA_CCR_CIRC)
  {
                               
    __HAL_SPI_DISABLE_IT(hspi, SPI_IT_ERR);

#if (USE_SPI_CRC != 0U)
                      
    if (hspi->Init.CRCCalculation == SPI_CRCCALCULATION_ENABLE)
    {
                                
      if (SPI_WaitFlagStateUntilTimeout(hspi, SPI_FLAG_RXNE, SET, SPI_DEFAULT_TIMEOUT, tickstart) != HAL_OK)
      {
                                        
        SET_BIT(hspi->ErrorCode, HAL_SPI_ERROR_CRC);
      }
                    
      if (hspi->Init.DataSize > SPI_DATASIZE_8BIT)
      {
                            
        tmpreg = READ_REG(hspi->Instance->DR);
                                  
        UNUSED(tmpreg);
      }
      else
      {
                                                   
        ptmpreg8 = (__IO uint8_t *)&hspi->Instance->DR;
                           
        tmpreg8 = *ptmpreg8;
                                  
        UNUSED(tmpreg8);

        if (hspi->Init.CRCLength == SPI_CRC_LENGTH_16BIT)
        {
          if (SPI_WaitFlagStateUntilTimeout(hspi, SPI_FLAG_RXNE, SET, SPI_DEFAULT_TIMEOUT, tickstart) != HAL_OK)
          {
                                            
            SET_BIT(hspi->ErrorCode, HAL_SPI_ERROR_CRC);
          }
                                                                          
          tmpreg8 = *ptmpreg8;
                                    
          UNUSED(tmpreg8);
        }
      }
    }
#endif                  

                                                  
    if ((hspi->Init.Direction == SPI_DIRECTION_2LINES) && (hspi->Init.Mode == SPI_MODE_MASTER))
    {
                                                                                                      
      CLEAR_BIT(hspi->Instance->CR2, SPI_CR2_TXDMAEN | SPI_CR2_RXDMAEN);
    }
    else
    {
                       
      CLEAR_BIT(hspi->Instance->CR2, SPI_CR2_RXDMAEN);
    }

                                          
    if (SPI_EndRxTransaction(hspi, SPI_DEFAULT_TIMEOUT, tickstart) != HAL_OK)
    {
      hspi->ErrorCode = HAL_SPI_ERROR_FLAG;
    }

    hspi->RxXferCount = 0U;
    hspi->State = HAL_SPI_STATE_READY;

#if (USE_SPI_CRC != 0U)
                                     
    if (__HAL_SPI_GET_FLAG(hspi, SPI_FLAG_CRCERR))
    {
      SET_BIT(hspi->ErrorCode, HAL_SPI_ERROR_CRC);
      __HAL_SPI_CLEAR_CRCERRFLAG(hspi);
    }
#endif                  

    if (hspi->ErrorCode != HAL_SPI_ERROR_NONE)
    {
                                    
#if (USE_HAL_SPI_REGISTER_CALLBACKS == 1U)
      hspi->ErrorCallback(hspi);
#else
      HAL_SPI_ErrorCallback(hspi);
#endif                                     
      return;
    }
  }
                                      
#if (USE_HAL_SPI_REGISTER_CALLBACKS == 1U)
  hspi->RxCpltCallback(hspi);
#else
  HAL_SPI_RxCpltCallback(hspi);
#endif                                     
}

   
                                                               
                                                                       
                                                                             
                
    
static void SPI_DMATransmitReceiveCplt(DMA_HandleTypeDef *hdma)
{
  SPI_HandleTypeDef *hspi = (SPI_HandleTypeDef *)(((DMA_HandleTypeDef *)hdma)->Parent);
  uint32_t tickstart;
#if (USE_SPI_CRC != 0U)
  __IO uint32_t tmpreg = 0U;
  __IO uint8_t  *ptmpreg8;
  __IO uint8_t  tmpreg8 = 0;
#endif                  

                                            
  tickstart = HAL_GetTick();

                       
  if ((hdma->Instance->CCR & DMA_CCR_CIRC) != DMA_CCR_CIRC)
  {
                               
    __HAL_SPI_DISABLE_IT(hspi, SPI_IT_ERR);

#if (USE_SPI_CRC != 0U)
                      
    if (hspi->Init.CRCCalculation == SPI_CRCCALCULATION_ENABLE)
    {
      if ((hspi->Init.DataSize == SPI_DATASIZE_8BIT) && (hspi->Init.CRCLength == SPI_CRC_LENGTH_8BIT))
      {
        if (SPI_WaitFifoStateUntilTimeout(hspi, SPI_FLAG_FRLVL, SPI_FRLVL_QUARTER_FULL, SPI_DEFAULT_TIMEOUT,
                                          tickstart) != HAL_OK)
        {
                                          
          SET_BIT(hspi->ErrorCode, HAL_SPI_ERROR_CRC);
        }
                                                   
        ptmpreg8 = (__IO uint8_t *)&hspi->Instance->DR;
                           
        tmpreg8 = *ptmpreg8;
                                  
        UNUSED(tmpreg8);
      }
      else
      {
        if (SPI_WaitFifoStateUntilTimeout(hspi, SPI_FLAG_FRLVL, SPI_FRLVL_HALF_FULL, SPI_DEFAULT_TIMEOUT,
                                          tickstart) != HAL_OK)
        {
                                          
          SET_BIT(hspi->ErrorCode, HAL_SPI_ERROR_CRC);
        }
                                                
        tmpreg = READ_REG(hspi->Instance->DR);
                                  
        UNUSED(tmpreg);
      }
    }
#endif                  

                                          
    if (SPI_EndRxTxTransaction(hspi, SPI_DEFAULT_TIMEOUT, tickstart) != HAL_OK)
    {
      SET_BIT(hspi->ErrorCode, HAL_SPI_ERROR_FLAG);
    }

                                   
    CLEAR_BIT(hspi->Instance->CR2, SPI_CR2_TXDMAEN | SPI_CR2_RXDMAEN);

    hspi->TxXferCount = 0U;
    hspi->RxXferCount = 0U;
    hspi->State = HAL_SPI_STATE_READY;

#if (USE_SPI_CRC != 0U)
                                     
    if (__HAL_SPI_GET_FLAG(hspi, SPI_FLAG_CRCERR))
    {
      SET_BIT(hspi->ErrorCode, HAL_SPI_ERROR_CRC);
      __HAL_SPI_CLEAR_CRCERRFLAG(hspi);
    }
#endif                  

    if (hspi->ErrorCode != HAL_SPI_ERROR_NONE)
    {
                                    
#if (USE_HAL_SPI_REGISTER_CALLBACKS == 1U)
      hspi->ErrorCallback(hspi);
#else
      HAL_SPI_ErrorCallback(hspi);
#endif                                     
      return;
    }
  }
                                        
#if (USE_HAL_SPI_REGISTER_CALLBACKS == 1U)
  hspi->TxRxCpltCallback(hspi);
#else
  HAL_SPI_TxRxCpltCallback(hspi);
#endif                                     
}

   
                                                            
                                                                       
                                                                             
                
    
static void SPI_DMAHalfTransmitCplt(DMA_HandleTypeDef *hdma)
{
  SPI_HandleTypeDef *hspi = (SPI_HandleTypeDef *)(((DMA_HandleTypeDef *)hdma)->Parent);

                                           
#if (USE_HAL_SPI_REGISTER_CALLBACKS == 1U)
  hspi->TxHalfCpltCallback(hspi);
#else
  HAL_SPI_TxHalfCpltCallback(hspi);
#endif                                     
}

   
                                                          
                                                                       
                                                                             
                
    
static void SPI_DMAHalfReceiveCplt(DMA_HandleTypeDef *hdma)
{
  SPI_HandleTypeDef *hspi = (SPI_HandleTypeDef *)(((DMA_HandleTypeDef *)hdma)->Parent);

                                           
#if (USE_HAL_SPI_REGISTER_CALLBACKS == 1U)
  hspi->RxHalfCpltCallback(hspi);
#else
  HAL_SPI_RxHalfCpltCallback(hspi);
#endif                                     
}

   
                                                                    
                                                                       
                                                                             
                
    
static void SPI_DMAHalfTransmitReceiveCplt(DMA_HandleTypeDef *hdma)
{
  SPI_HandleTypeDef *hspi = (SPI_HandleTypeDef *)(((DMA_HandleTypeDef *)hdma)->Parent);

                                             
#if (USE_HAL_SPI_REGISTER_CALLBACKS == 1U)
  hspi->TxRxHalfCpltCallback(hspi);
#else
  HAL_SPI_TxRxHalfCpltCallback(hspi);
#endif                                     
}

   
                                                 
                                                                       
                                                                             
                
    
static void SPI_DMAError(DMA_HandleTypeDef *hdma)
{
  SPI_HandleTypeDef *hspi = (SPI_HandleTypeDef *)(((DMA_HandleTypeDef *)hdma)->Parent);

                                                 
  CLEAR_BIT(hspi->Instance->CR2, SPI_CR2_TXDMAEN | SPI_CR2_RXDMAEN);

  SET_BIT(hspi->ErrorCode, HAL_SPI_ERROR_DMA);
  hspi->State = HAL_SPI_STATE_READY;
                                
#if (USE_HAL_SPI_REGISTER_CALLBACKS == 1U)
  hspi->ErrorCallback(hspi);
#else
  HAL_SPI_ErrorCallback(hspi);
#endif                                     
}

   
                                                                                         
                                                                                    
                            
                
    
static void SPI_DMAAbortOnError(DMA_HandleTypeDef *hdma)
{
  SPI_HandleTypeDef *hspi = (SPI_HandleTypeDef *)(((DMA_HandleTypeDef *)hdma)->Parent);
  hspi->RxXferCount = 0U;
  hspi->TxXferCount = 0U;

                                
#if (USE_HAL_SPI_REGISTER_CALLBACKS == 1U)
  hspi->ErrorCallback(hspi);
#else
  HAL_SPI_ErrorCallback(hspi);
#endif                                     
}

   
                                                                           
                                                                                         
                                                                                              
                                                  
                            
                
    
static void SPI_DMATxAbortCallback(DMA_HandleTypeDef *hdma)
{
  SPI_HandleTypeDef *hspi = (SPI_HandleTypeDef *)(((DMA_HandleTypeDef *)hdma)->Parent);

  hspi->hdmatx->XferAbortCallback = NULL;

                              
  CLEAR_BIT(hspi->Instance->CR2, SPI_CR2_TXDMAEN);

  if (SPI_EndRxTxTransaction(hspi, SPI_DEFAULT_TIMEOUT, HAL_GetTick()) != HAL_OK)
  {
    hspi->ErrorCode = HAL_SPI_ERROR_ABORT;
  }

                              
  __HAL_SPI_DISABLE(hspi);

                            
  if (SPI_WaitFifoStateUntilTimeout(hspi, SPI_FLAG_FRLVL, SPI_FRLVL_EMPTY, SPI_DEFAULT_TIMEOUT,
                                    HAL_GetTick()) != HAL_OK)
  {
    hspi->ErrorCode = HAL_SPI_ERROR_ABORT;
  }

                                                  
  if (hspi->hdmarx != NULL)
  {
    if (hspi->hdmarx->XferAbortCallback != NULL)
    {
      return;
    }
  }

                                                                                                              
  hspi->RxXferCount = 0U;
  hspi->TxXferCount = 0U;

                                             
  if (hspi->ErrorCode != HAL_SPI_ERROR_ABORT)
  {
                         
    hspi->ErrorCode = HAL_SPI_ERROR_NONE;
  }

                                                
  __HAL_SPI_CLEAR_OVRFLAG(hspi);
  __HAL_SPI_CLEAR_FREFLAG(hspi);

                                    
  hspi->State  = HAL_SPI_STATE_READY;

                                         
#if (USE_HAL_SPI_REGISTER_CALLBACKS == 1U)
  hspi->AbortCpltCallback(hspi);
#else
  HAL_SPI_AbortCpltCallback(hspi);
#endif                                     
}

   
                                                                           
                                                                                         
                                                                                              
                                                  
                            
                
    
static void SPI_DMARxAbortCallback(DMA_HandleTypeDef *hdma)
{
  SPI_HandleTypeDef *hspi = (SPI_HandleTypeDef *)(((DMA_HandleTypeDef *)hdma)->Parent);

                              
  __HAL_SPI_DISABLE(hspi);

  hspi->hdmarx->XferAbortCallback = NULL;

                              
  CLEAR_BIT(hspi->Instance->CR2, SPI_CR2_RXDMAEN);

                            
  if (SPI_WaitFlagStateUntilTimeout(hspi, SPI_FLAG_BSY, RESET, SPI_DEFAULT_TIMEOUT, HAL_GetTick()) != HAL_OK)
  {
    hspi->ErrorCode = HAL_SPI_ERROR_ABORT;
  }

                            
  if (SPI_WaitFifoStateUntilTimeout(hspi, SPI_FLAG_FRLVL, SPI_FRLVL_EMPTY, SPI_DEFAULT_TIMEOUT,
                                    HAL_GetTick()) != HAL_OK)
  {
    hspi->ErrorCode = HAL_SPI_ERROR_ABORT;
  }

                                                  
  if (hspi->hdmatx != NULL)
  {
    if (hspi->hdmatx->XferAbortCallback != NULL)
    {
      return;
    }
  }

                                                                                                              
  hspi->RxXferCount = 0U;
  hspi->TxXferCount = 0U;

                                             
  if (hspi->ErrorCode != HAL_SPI_ERROR_ABORT)
  {
                         
    hspi->ErrorCode = HAL_SPI_ERROR_NONE;
  }

                                                
  __HAL_SPI_CLEAR_OVRFLAG(hspi);
  __HAL_SPI_CLEAR_FREFLAG(hspi);

                                    
  hspi->State  = HAL_SPI_STATE_READY;

                                         
#if (USE_HAL_SPI_REGISTER_CALLBACKS == 1U)
  hspi->AbortCpltCallback(hspi);
#else
  HAL_SPI_AbortCpltCallback(hspi);
#endif                                     
}

   
                                                                        
                                                                       
                                                               
                
    
static void SPI_2linesRxISR_8BIT(struct __SPI_HandleTypeDef *hspi)
{
                                    
  if (hspi->RxXferCount > 1U)
  {
    *((uint16_t *)hspi->pRxBuffPtr) = (uint16_t)(hspi->Instance->DR);
    hspi->pRxBuffPtr += sizeof(uint16_t);
    hspi->RxXferCount -= 2U;
    if (hspi->RxXferCount == 1U)
    {
                                                                           
      SET_BIT(hspi->Instance->CR2, SPI_RXFIFO_THRESHOLD);
    }
  }
                                  
  else
  {
    *hspi->pRxBuffPtr = *((__IO uint8_t *)&hspi->Instance->DR);
    hspi->pRxBuffPtr++;
    hspi->RxXferCount--;
  }

                                  
  if (hspi->RxXferCount == 0U)
  {
#if (USE_SPI_CRC != 0U)
    if (hspi->Init.CRCCalculation == SPI_CRCCALCULATION_ENABLE)
    {
      SET_BIT(hspi->Instance->CR2, SPI_RXFIFO_THRESHOLD);
      hspi->RxISR =  SPI_2linesRxISR_8BITCRC;
      return;
    }
#endif                  

                                         
    __HAL_SPI_DISABLE_IT(hspi, (SPI_IT_RXNE | SPI_IT_ERR));

    if (hspi->TxXferCount == 0U)
    {
      SPI_CloseRxTx_ISR(hspi);
    }
  }
}

#if (USE_SPI_CRC != 0U)
   
                                                                        
                                                                       
                                                               
                
    
static void SPI_2linesRxISR_8BITCRC(struct __SPI_HandleTypeDef *hspi)
{
  __IO uint8_t  *ptmpreg8;
  __IO uint8_t  tmpreg8 = 0;

                                             
  ptmpreg8 = (__IO uint8_t *)&hspi->Instance->DR;
                                            
  tmpreg8 = *ptmpreg8;
                            
  UNUSED(tmpreg8);

  hspi->CRCSize--;

                                  
  if (hspi->CRCSize == 0U)
  {
                                        
    __HAL_SPI_DISABLE_IT(hspi, (SPI_IT_RXNE | SPI_IT_ERR));

    if (hspi->TxXferCount == 0U)
    {
      SPI_CloseRxTx_ISR(hspi);
    }
  }
}
#endif                  

   
                                                                        
                                                                       
                                                               
                
    
static void SPI_2linesTxISR_8BIT(struct __SPI_HandleTypeDef *hspi)
{
                                         
  if (hspi->TxXferCount >= 2U)
  {
    hspi->Instance->DR = *((const uint16_t *)hspi->pTxBuffPtr);
    hspi->pTxBuffPtr += sizeof(uint16_t);
    hspi->TxXferCount -= 2U;
  }
                                   
  else
  {
    *(__IO uint8_t *)&hspi->Instance->DR = *((const uint8_t *)hspi->pTxBuffPtr);
    hspi->pTxBuffPtr++;
    hspi->TxXferCount--;
  }

                                         
  if (hspi->TxXferCount == 0U)
  {
#if (USE_SPI_CRC != 0U)
    if (hspi->Init.CRCCalculation == SPI_CRCCALCULATION_ENABLE)
    {
                                        
      SET_BIT(hspi->Instance->CR1, SPI_CR1_CRCNEXT);
                                 
      __HAL_SPI_DISABLE_IT(hspi, SPI_IT_TXE);
      return;
    }
#endif                  

                               
    __HAL_SPI_DISABLE_IT(hspi, SPI_IT_TXE);

    if (hspi->RxXferCount == 0U)
    {
      SPI_CloseRxTx_ISR(hspi);
    }
  }
}

   
                                                                         
                                                                       
                                                               
                
    
static void SPI_2linesRxISR_16BIT(struct __SPI_HandleTypeDef *hspi)
{
                                   
  *((uint16_t *)hspi->pRxBuffPtr) = (uint16_t)(hspi->Instance->DR);
  hspi->pRxBuffPtr += sizeof(uint16_t);
  hspi->RxXferCount--;

  if (hspi->RxXferCount == 0U)
  {
#if (USE_SPI_CRC != 0U)
    if (hspi->Init.CRCCalculation == SPI_CRCCALCULATION_ENABLE)
    {
      hspi->RxISR =  SPI_2linesRxISR_16BITCRC;
      return;
    }
#endif                  

                                
    __HAL_SPI_DISABLE_IT(hspi, SPI_IT_RXNE);

    if (hspi->TxXferCount == 0U)
    {
      SPI_CloseRxTx_ISR(hspi);
    }
  }
}

#if (USE_SPI_CRC != 0U)
   
                                                                                     
                                                                       
                                                               
                
    
static void SPI_2linesRxISR_16BITCRC(struct __SPI_HandleTypeDef *hspi)
{
  __IO uint32_t tmpreg = 0U;

                                             
  tmpreg = READ_REG(hspi->Instance->DR);
                            
  UNUSED(tmpreg);

                              
  __HAL_SPI_DISABLE_IT(hspi, SPI_IT_RXNE);

  SPI_CloseRxTx_ISR(hspi);
}
#endif                  

   
                                                                         
                                                                       
                                                               
                
    
static void SPI_2linesTxISR_16BIT(struct __SPI_HandleTypeDef *hspi)
{
                                    
  hspi->Instance->DR = *((const uint16_t *)hspi->pTxBuffPtr);
  hspi->pTxBuffPtr += sizeof(uint16_t);
  hspi->TxXferCount--;

                               
  if (hspi->TxXferCount == 0U)
  {
#if (USE_SPI_CRC != 0U)
    if (hspi->Init.CRCCalculation == SPI_CRCCALCULATION_ENABLE)
    {
                                        
      SET_BIT(hspi->Instance->CR1, SPI_CR1_CRCNEXT);
                                 
      __HAL_SPI_DISABLE_IT(hspi, SPI_IT_TXE);
      return;
    }
#endif                  

                               
    __HAL_SPI_DISABLE_IT(hspi, SPI_IT_TXE);

    if (hspi->RxXferCount == 0U)
    {
      SPI_CloseRxTx_ISR(hspi);
    }
  }
}

#if (USE_SPI_CRC != 0U)
   
                                                              
                                                                       
                                                               
                
    
static void SPI_RxISR_8BITCRC(struct __SPI_HandleTypeDef *hspi)
{
  __IO uint8_t  *ptmpreg8;
  __IO uint8_t  tmpreg8 = 0;

                                             
  ptmpreg8 = (__IO uint8_t *)&hspi->Instance->DR;
                                            
  tmpreg8 = *ptmpreg8;
                            
  UNUSED(tmpreg8);

  hspi->CRCSize--;

  if (hspi->CRCSize == 0U)
  {
    SPI_CloseRx_ISR(hspi);
  }
}
#endif                  

   
                                                          
                                                                       
                                                               
                
    
static void SPI_RxISR_8BIT(struct __SPI_HandleTypeDef *hspi)
{
  *hspi->pRxBuffPtr = (*(__IO uint8_t *)&hspi->Instance->DR);
  hspi->pRxBuffPtr++;
  hspi->RxXferCount--;

#if (USE_SPI_CRC != 0U)
                               
  if ((hspi->RxXferCount == 1U) && (hspi->Init.CRCCalculation == SPI_CRCCALCULATION_ENABLE))
  {
    SET_BIT(hspi->Instance->CR1, SPI_CR1_CRCNEXT);
  }
#endif                  

  if (hspi->RxXferCount == 0U)
  {
#if (USE_SPI_CRC != 0U)
    if (hspi->Init.CRCCalculation == SPI_CRCCALCULATION_ENABLE)
    {
      hspi->RxISR =  SPI_RxISR_8BITCRC;
      return;
    }
#endif                  
    SPI_CloseRx_ISR(hspi);
  }
}

#if (USE_SPI_CRC != 0U)
   
                                                               
                                                                       
                                                               
                
    
static void SPI_RxISR_16BITCRC(struct __SPI_HandleTypeDef *hspi)
{
  __IO uint32_t tmpreg = 0U;

                                             
  tmpreg = READ_REG(hspi->Instance->DR);
                            
  UNUSED(tmpreg);

                                      
  __HAL_SPI_DISABLE_IT(hspi, (SPI_IT_RXNE | SPI_IT_ERR));

  SPI_CloseRx_ISR(hspi);
}
#endif                  

   
                                                           
                                                                       
                                                               
                
    
static void SPI_RxISR_16BIT(struct __SPI_HandleTypeDef *hspi)
{
  *((uint16_t *)hspi->pRxBuffPtr) = (uint16_t)(hspi->Instance->DR);
  hspi->pRxBuffPtr += sizeof(uint16_t);
  hspi->RxXferCount--;

#if (USE_SPI_CRC != 0U)
                               
  if ((hspi->RxXferCount == 1U) && (hspi->Init.CRCCalculation == SPI_CRCCALCULATION_ENABLE))
  {
    SET_BIT(hspi->Instance->CR1, SPI_CR1_CRCNEXT);
  }
#endif                  

  if (hspi->RxXferCount == 0U)
  {
#if (USE_SPI_CRC != 0U)
    if (hspi->Init.CRCCalculation == SPI_CRCCALCULATION_ENABLE)
    {
      hspi->RxISR = SPI_RxISR_16BITCRC;
      return;
    }
#endif                  
    SPI_CloseRx_ISR(hspi);
  }
}

   
                                                             
                                                                       
                                                               
                
    
static void SPI_TxISR_8BIT(struct __SPI_HandleTypeDef *hspi)
{
  *(__IO uint8_t *)&hspi->Instance->DR = *((const uint8_t *)hspi->pTxBuffPtr);
  hspi->pTxBuffPtr++;
  hspi->TxXferCount--;

  if (hspi->TxXferCount == 0U)
  {
#if (USE_SPI_CRC != 0U)
    if (hspi->Init.CRCCalculation == SPI_CRCCALCULATION_ENABLE)
    {
                                   
      SET_BIT(hspi->Instance->CR1, SPI_CR1_CRCNEXT);
    }
#endif                  
    SPI_CloseTx_ISR(hspi);
  }
}

   
                                                              
                                                                       
                                                               
                
    
static void SPI_TxISR_16BIT(struct __SPI_HandleTypeDef *hspi)
{
                                    
  hspi->Instance->DR = *((const uint16_t *)hspi->pTxBuffPtr);
  hspi->pTxBuffPtr += sizeof(uint16_t);
  hspi->TxXferCount--;

  if (hspi->TxXferCount == 0U)
  {
#if (USE_SPI_CRC != 0U)
    if (hspi->Init.CRCCalculation == SPI_CRCCALCULATION_ENABLE)
    {
                                   
      SET_BIT(hspi->Instance->CR1, SPI_CR1_CRCNEXT);
    }
#endif                  
    SPI_CloseTx_ISR(hspi);
  }
}

   
                                             
                                                                       
                                                              
                                  
                                     
                                    
                                      
                      
    
static HAL_StatusTypeDef SPI_WaitFlagStateUntilTimeout(SPI_HandleTypeDef *hspi, uint32_t Flag, FlagStatus State,
                                                       uint32_t Timeout, uint32_t Tickstart)
{
  __IO uint32_t count;
  uint32_t tmp_timeout;
  uint32_t tmp_tickstart;

                                                        
  tmp_timeout   = Timeout - (HAL_GetTick() - Tickstart);
  tmp_tickstart = HAL_GetTick();

                                                                                                 
  count = tmp_timeout * ((SystemCoreClock * 32U) >> 20U);

  while ((__HAL_SPI_GET_FLAG(hspi, Flag) ? SET : RESET) != State)
  {
    if (Timeout != HAL_MAX_DELAY)
    {
      if (((HAL_GetTick() - tmp_tickstart) >= tmp_timeout) || (tmp_timeout == 0U))
      {
                                                                             
                                                                              
                                                            

                                                                            
        __HAL_SPI_DISABLE_IT(hspi, (SPI_IT_TXE | SPI_IT_RXNE | SPI_IT_ERR));

        if ((hspi->Init.Mode == SPI_MODE_MASTER) && ((hspi->Init.Direction == SPI_DIRECTION_1LINE)
                                                     || (hspi->Init.Direction == SPI_DIRECTION_2LINES_RXONLY)))
        {
                                      
          __HAL_SPI_DISABLE(hspi);
        }

                                   
        if (hspi->Init.CRCCalculation == SPI_CRCCALCULATION_ENABLE)
        {
          SPI_RESET_CRC(hspi);
        }

        hspi->State = HAL_SPI_STATE_READY;

                              
        __HAL_UNLOCK(hspi);

        return HAL_TIMEOUT;
      }
                                                                                                         
      if (count == 0U)
      {
        tmp_timeout = 0U;
      }
      else
      {
        count--;
      }
    }
  }

  return HAL_OK;
}

   
                                                  
                                                                       
                                                              
                              
                                     
                                    
                                      
                      
    
static HAL_StatusTypeDef SPI_WaitFifoStateUntilTimeout(SPI_HandleTypeDef *hspi, uint32_t Fifo, uint32_t State,
                                                       uint32_t Timeout, uint32_t Tickstart)
{
  __IO uint32_t count;
  uint32_t tmp_timeout;
  uint32_t tmp_tickstart;
  __IO const uint8_t  *ptmpreg8;
  __IO uint8_t  tmpreg8 = 0;

                                                        
  tmp_timeout = Timeout - (HAL_GetTick() - Tickstart);
  tmp_tickstart = HAL_GetTick();

                                             
  ptmpreg8 = (__IO uint8_t *)&hspi->Instance->DR;

                                                                                                 
  count = tmp_timeout * ((SystemCoreClock * 35U) >> 20U);

  while ((hspi->Instance->SR & Fifo) != State)
  {
    if ((Fifo == SPI_SR_FRLVL) && (State == SPI_FRLVL_EMPTY))
    {
                                               
      tmpreg8 = *ptmpreg8;
                                
      UNUSED(tmpreg8);
    }

    if (Timeout != HAL_MAX_DELAY)
    {
      if (((HAL_GetTick() - tmp_tickstart) >= tmp_timeout) || (tmp_timeout == 0U))
      {
                                                                             
                                                                              
                                                            

                                                                            
        __HAL_SPI_DISABLE_IT(hspi, (SPI_IT_TXE | SPI_IT_RXNE | SPI_IT_ERR));

        if ((hspi->Init.Mode == SPI_MODE_MASTER) && ((hspi->Init.Direction == SPI_DIRECTION_1LINE)
                                                     || (hspi->Init.Direction == SPI_DIRECTION_2LINES_RXONLY)))
        {
                                      
          __HAL_SPI_DISABLE(hspi);
        }

                                   
        if (hspi->Init.CRCCalculation == SPI_CRCCALCULATION_ENABLE)
        {
          SPI_RESET_CRC(hspi);
        }

        hspi->State = HAL_SPI_STATE_READY;

                              
        __HAL_UNLOCK(hspi);

        return HAL_TIMEOUT;
      }
                                                                                                         
      if (count == 0U)
      {
        tmp_timeout = 0U;
      }
      else
      {
        count--;
      }
    }
  }

  return HAL_OK;
}

   
                                                            
                                                                       
                                                               
                                    
                                      
                      
    
static HAL_StatusTypeDef SPI_EndRxTransaction(SPI_HandleTypeDef *hspi,  uint32_t Timeout, uint32_t Tickstart)
{
  if ((hspi->Init.Mode == SPI_MODE_MASTER) && ((hspi->Init.Direction == SPI_DIRECTION_1LINE)
                                               || (hspi->Init.Direction == SPI_DIRECTION_2LINES_RXONLY)))
  {
                                
    __HAL_SPI_DISABLE(hspi);
  }

                            
  if (SPI_WaitFlagStateUntilTimeout(hspi, SPI_FLAG_BSY, RESET, Timeout, Tickstart) != HAL_OK)
  {
    SET_BIT(hspi->ErrorCode, HAL_SPI_ERROR_FLAG);
    return HAL_TIMEOUT;
  }

  if ((hspi->Init.Mode == SPI_MODE_MASTER) && ((hspi->Init.Direction == SPI_DIRECTION_1LINE)
                                               || (hspi->Init.Direction == SPI_DIRECTION_2LINES_RXONLY)))
  {
                              
    if (SPI_WaitFifoStateUntilTimeout(hspi, SPI_FLAG_FRLVL, SPI_FRLVL_EMPTY, Timeout, Tickstart) != HAL_OK)
    {
      SET_BIT(hspi->ErrorCode, HAL_SPI_ERROR_FLAG);
      return HAL_TIMEOUT;
    }
  }
  return HAL_OK;
}

   
                                                                    
                           
                                    
                                      
                      
    
static HAL_StatusTypeDef SPI_EndRxTxTransaction(SPI_HandleTypeDef *hspi, uint32_t Timeout, uint32_t Tickstart)
{
                                       
  if (SPI_WaitFifoStateUntilTimeout(hspi, SPI_FLAG_FTLVL, SPI_FTLVL_EMPTY, Timeout, Tickstart) != HAL_OK)
  {
    SET_BIT(hspi->ErrorCode, HAL_SPI_ERROR_FLAG);
    return HAL_TIMEOUT;
  }

                            
  if (SPI_WaitFlagStateUntilTimeout(hspi, SPI_FLAG_BSY, RESET, Timeout, Tickstart) != HAL_OK)
  {
    SET_BIT(hspi->ErrorCode, HAL_SPI_ERROR_FLAG);
    return HAL_TIMEOUT;
  }

                                       
  if (SPI_WaitFifoStateUntilTimeout(hspi, SPI_FLAG_FRLVL, SPI_FRLVL_EMPTY, Timeout, Tickstart) != HAL_OK)
  {
    SET_BIT(hspi->ErrorCode, HAL_SPI_ERROR_FLAG);
    return HAL_TIMEOUT;
  }

  return HAL_OK;
}

   
                                                   
                                                                       
                                                               
                
    
static void SPI_CloseRxTx_ISR(SPI_HandleTypeDef *hspi)
{
  uint32_t tickstart;

                                             
  tickstart = HAL_GetTick();

                             
  __HAL_SPI_DISABLE_IT(hspi, SPI_IT_ERR);

                                        
  if (SPI_EndRxTxTransaction(hspi, SPI_DEFAULT_TIMEOUT, tickstart) != HAL_OK)
  {
    SET_BIT(hspi->ErrorCode, HAL_SPI_ERROR_FLAG);
  }

#if (USE_SPI_CRC != 0U)
                                   
  if (__HAL_SPI_GET_FLAG(hspi, SPI_FLAG_CRCERR) != RESET)
  {
    hspi->State = HAL_SPI_STATE_READY;
    SET_BIT(hspi->ErrorCode, HAL_SPI_ERROR_CRC);
    __HAL_SPI_CLEAR_CRCERRFLAG(hspi);
                                  
#if (USE_HAL_SPI_REGISTER_CALLBACKS == 1U)
    hspi->ErrorCallback(hspi);
#else
    HAL_SPI_ErrorCallback(hspi);
#endif                                     
  }
  else
  {
#endif                  
    if (hspi->ErrorCode == HAL_SPI_ERROR_NONE)
    {
      if (hspi->State == HAL_SPI_STATE_BUSY_RX)
      {
        hspi->State = HAL_SPI_STATE_READY;
                                            
#if (USE_HAL_SPI_REGISTER_CALLBACKS == 1U)
        hspi->RxCpltCallback(hspi);
#else
        HAL_SPI_RxCpltCallback(hspi);
#endif                                     
      }
      else
      {
        hspi->State = HAL_SPI_STATE_READY;
                                              
#if (USE_HAL_SPI_REGISTER_CALLBACKS == 1U)
        hspi->TxRxCpltCallback(hspi);
#else
        HAL_SPI_TxRxCpltCallback(hspi);
#endif                                     
      }
    }
    else
    {
      hspi->State = HAL_SPI_STATE_READY;
                                    
#if (USE_HAL_SPI_REGISTER_CALLBACKS == 1U)
      hspi->ErrorCallback(hspi);
#else
      HAL_SPI_ErrorCallback(hspi);
#endif                                     
    }
#if (USE_SPI_CRC != 0U)
  }
#endif                  
}

   
                                                 
                                                                       
                                                               
                
    
static void SPI_CloseRx_ISR(SPI_HandleTypeDef *hspi)
{
                                      
  __HAL_SPI_DISABLE_IT(hspi, (SPI_IT_RXNE | SPI_IT_ERR));

                                        
  if (SPI_EndRxTransaction(hspi, SPI_DEFAULT_TIMEOUT, HAL_GetTick()) != HAL_OK)
  {
    SET_BIT(hspi->ErrorCode, HAL_SPI_ERROR_FLAG);
  }
  hspi->State = HAL_SPI_STATE_READY;

#if (USE_SPI_CRC != 0U)
                                   
  if (__HAL_SPI_GET_FLAG(hspi, SPI_FLAG_CRCERR) != RESET)
  {
    SET_BIT(hspi->ErrorCode, HAL_SPI_ERROR_CRC);
    __HAL_SPI_CLEAR_CRCERRFLAG(hspi);
                                  
#if (USE_HAL_SPI_REGISTER_CALLBACKS == 1U)
    hspi->ErrorCallback(hspi);
#else
    HAL_SPI_ErrorCallback(hspi);
#endif                                     
  }
  else
  {
#endif                  
    if (hspi->ErrorCode == HAL_SPI_ERROR_NONE)
    {
                                          
#if (USE_HAL_SPI_REGISTER_CALLBACKS == 1U)
      hspi->RxCpltCallback(hspi);
#else
      HAL_SPI_RxCpltCallback(hspi);
#endif                                     
    }
    else
    {
                                    
#if (USE_HAL_SPI_REGISTER_CALLBACKS == 1U)
      hspi->ErrorCallback(hspi);
#else
      HAL_SPI_ErrorCallback(hspi);
#endif                                     
    }
#if (USE_SPI_CRC != 0U)
  }
#endif                  
}

   
                                                 
                                                                       
                                                               
                
    
static void SPI_CloseTx_ISR(SPI_HandleTypeDef *hspi)
{
  uint32_t tickstart;

                                            
  tickstart = HAL_GetTick();

                                     
  __HAL_SPI_DISABLE_IT(hspi, (SPI_IT_TXE | SPI_IT_ERR));

                                        
  if (SPI_EndRxTxTransaction(hspi, SPI_DEFAULT_TIMEOUT, tickstart) != HAL_OK)
  {
    SET_BIT(hspi->ErrorCode, HAL_SPI_ERROR_FLAG);
  }

                                                                                     
  if (hspi->Init.Direction == SPI_DIRECTION_2LINES)
  {
    __HAL_SPI_CLEAR_OVRFLAG(hspi);
  }

  hspi->State = HAL_SPI_STATE_READY;
  if (hspi->ErrorCode != HAL_SPI_ERROR_NONE)
  {
                                  
#if (USE_HAL_SPI_REGISTER_CALLBACKS == 1U)
    hspi->ErrorCallback(hspi);
#else
    HAL_SPI_ErrorCallback(hspi);
#endif                                     
  }
  else
  {
                                        
#if (USE_HAL_SPI_REGISTER_CALLBACKS == 1U)
    hspi->TxCpltCallback(hspi);
#else
    HAL_SPI_TxCpltCallback(hspi);
#endif                                     
  }
}

   
                                          
                                                                       
                                                               
                
    
static void SPI_AbortRx_ISR(SPI_HandleTypeDef *hspi)
{
  __IO uint32_t count;

                              
  __HAL_SPI_DISABLE(hspi);

  count = SPI_DEFAULT_TIMEOUT * (SystemCoreClock / 24U / 1000U);

                                
  CLEAR_BIT(hspi->Instance->CR2, (SPI_CR2_RXNEIE));

                                
  do
  {
    if (count == 0U)
    {
      SET_BIT(hspi->ErrorCode, HAL_SPI_ERROR_ABORT);
      break;
    }
    count--;
  } while (HAL_IS_BIT_SET(hspi->Instance->CR2, SPI_CR2_RXNEIE));

                            
  if (SPI_WaitFlagStateUntilTimeout(hspi, SPI_FLAG_BSY, RESET, SPI_DEFAULT_TIMEOUT, HAL_GetTick()) != HAL_OK)
  {
    hspi->ErrorCode = HAL_SPI_ERROR_ABORT;
  }

                            
  if (SPI_WaitFifoStateUntilTimeout(hspi, SPI_FLAG_FRLVL, SPI_FRLVL_EMPTY, SPI_DEFAULT_TIMEOUT,
                                    HAL_GetTick()) != HAL_OK)
  {
    hspi->ErrorCode = HAL_SPI_ERROR_ABORT;
  }

  hspi->State = HAL_SPI_STATE_ABORT;
}

   
                                                   
                                                                       
                                                               
                
    
static void SPI_AbortTx_ISR(SPI_HandleTypeDef *hspi)
{
  __IO uint32_t count;

  count = SPI_DEFAULT_TIMEOUT * (SystemCoreClock / 24U / 1000U);

                               
  CLEAR_BIT(hspi->Instance->CR2, (SPI_CR2_TXEIE));

                               
  do
  {
    if (count == 0U)
    {
      SET_BIT(hspi->ErrorCode, HAL_SPI_ERROR_ABORT);
      break;
    }
    count--;
  } while (HAL_IS_BIT_SET(hspi->Instance->CR2, SPI_CR2_TXEIE));

  if (SPI_EndRxTxTransaction(hspi, SPI_DEFAULT_TIMEOUT, HAL_GetTick()) != HAL_OK)
  {
    hspi->ErrorCode = HAL_SPI_ERROR_ABORT;
  }

                              
  __HAL_SPI_DISABLE(hspi);

                            
  if (SPI_WaitFifoStateUntilTimeout(hspi, SPI_FLAG_FRLVL, SPI_FRLVL_EMPTY, SPI_DEFAULT_TIMEOUT,
                                    HAL_GetTick()) != HAL_OK)
  {
    hspi->ErrorCode = HAL_SPI_ERROR_ABORT;
  }

                                                                            
  if (HAL_IS_BIT_SET(hspi->Instance->CR2, SPI_CR2_RXNEIE))
  {
                                  
    CLEAR_BIT(hspi->Instance->CR2, (SPI_CR2_RXNEIE));

                                  
    do
    {
      if (count == 0U)
      {
        SET_BIT(hspi->ErrorCode, HAL_SPI_ERROR_ABORT);
        break;
      }
      count--;
    } while (HAL_IS_BIT_SET(hspi->Instance->CR2, SPI_CR2_RXNEIE));

                              
    if (SPI_WaitFlagStateUntilTimeout(hspi, SPI_FLAG_BSY, RESET, SPI_DEFAULT_TIMEOUT, HAL_GetTick()) != HAL_OK)
    {
      hspi->ErrorCode = HAL_SPI_ERROR_ABORT;
    }

                              
    if (SPI_WaitFifoStateUntilTimeout(hspi, SPI_FLAG_FRLVL, SPI_FRLVL_EMPTY, SPI_DEFAULT_TIMEOUT,
                                      HAL_GetTick()) != HAL_OK)
    {
      hspi->ErrorCode = HAL_SPI_ERROR_ABORT;
    }
  }
  hspi->State = HAL_SPI_STATE_ABORT;
}

   
      
    

#endif                             

   
      
    

   
      
    

