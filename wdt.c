// STM8S103F3
#include "stm8s.h"

//user
#include "wdt.h"


// Init watchdog timer
void InitWdt(void)
{
    // Enable
    IWDG->KR = KEY_ENABLE;
    // Set refresh time = 600ms
    IWDG->KR = KEY_ACCESS;
    IWDG->PR = 6;           // f = 64kHz / 256 = 250Hz
    IWDG->RLR = 150;         // T = 600ms
    // Refresh
    IWDG->KR = KEY_REFRESH;
}


