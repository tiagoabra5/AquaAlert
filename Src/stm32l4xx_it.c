#include "cube_hal.h"

extern void APP_ButtonPressedCallback(void);
extern void APP_RadioIrqCallback(void);

void SysTick_Handler(void)
{
  HAL_IncTick();
  HAL_SYSTICK_IRQHandler();
}

void EXTI0_IRQHandler(void)
{
  HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_0);
  APP_RadioIrqCallback();
}

void EXTI15_10_IRQHandler(void)
{
  HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_13);
  APP_ButtonPressedCallback();
}
