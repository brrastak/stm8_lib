
// user
#include "init.h"
#include "main.h"
#include "gpio.h"


// Init interrupts
void InitInterrupt(void)
{
    EnableInterrupt();
}
void EnableInterrupt(void)
{
    asm("rim");     // interrupt enable
}
void DisableInterrupt(void)
{
    asm("sim");     // interrupt disable
}
// Init GPIO
void InitGpio(void)
{
    InitPinAsOpp(H1_PORT, H1_PIN);
    InitPinAsOpp(H2_PORT, H2_PIN);
    
    // Deinit unused pins
    InitPinAsOpp(GPIOD, 6);
    ResetPin(GPIOD, 6);
    
    InitPinAsOpp(GPIOA, 2);
    ResetPin(GPIOA, 2);
    InitPinAsOpp(GPIOB, 0);
    ResetPin(GPIOB, 0);
    InitPinAsOpp(GPIOB, 1);
    ResetPin(GPIOB, 1);
    InitPinAsOpp(GPIOB, 2);
    ResetPin(GPIOB, 2);
    InitPinAsOpp(GPIOB, 3);
    ResetPin(GPIOB, 3);
    InitPinAsOpp(GPIOB, 6);
    ResetPin(GPIOB, 6);
    InitPinAsOpp(GPIOB, 7);
    ResetPin(GPIOB, 7);
    InitPinAsOpp(GPIOC, 1);
    ResetPin(GPIOC, 1);
    InitPinAsOpp(GPIOC, 2);
    ResetPin(GPIOC, 2);
    InitPinAsOpp(GPIOC, 7);
    ResetPin(GPIOC, 7);
    InitPinAsOpp(GPIOD, 0);
    ResetPin(GPIOD, 0);
    InitPinAsOpp(GPIOD, 2);
    ResetPin(GPIOD, 2);
    InitPinAsOpp(GPIOD, 4);
    ResetPin(GPIOD, 4);
    InitPinAsOpp(GPIOD, 7);
    ResetPin(GPIOD, 7);
    InitPinAsOpp(GPIOE, 5);
    ResetPin(GPIOE, 5);
    InitPinAsOpp(GPIOF, 4);
    ResetPin(GPIOF, 4);
}

// Init clock
void InitRcc(void)
{
    // Default f_master value = 2MHz
    
    // f_master = f_HSI (16MHz)
    //CLK->CKDIVR = 0;
}

// Deinit unused modules
void DeinitPeriph(void)
{
    
}

