#ifndef STM32L4XX_IT_H
#define STM32L4XX_IT_H

#ifdef __cplusplus
extern "C" {
#endif

void SysTick_Handler(void);
void EXTI0_IRQHandler(void);
void EXTI15_10_IRQHandler(void);

#ifdef __cplusplus
}
#endif

#endif
