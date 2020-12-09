
#ifndef __TIMER_H__
#define __TIMER_H__

#include <stdbool.h>

// Ticks
extern volatile uint32_t sys_tick;

// Init TIM4 as SysTick timer
void InitSysTick(void);
// Delay TIM2
void delay_ms(uint32_t ms);
void delay_us(uint16_t ms); // max 60000us

// Init TIM2 as us counter (max 500ms)
void InitTim2Delay(uint16_t ms);
inline bool IfDelayTim2Passed(void)
{
    return (TIM2->SR1 & TIM2_SR1_UIF);
}

// Init TIM4 as us counter
void InitTim4(void);
// Start counting
inline void DelayTim4(uint8_t us)
{
    TIM4->CNTR = 0;
    TIM4->CR1 |= TIM4_CR1_CEN;
    while (TIM4->CNTR < us)
        ;
}



#endif