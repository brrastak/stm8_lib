
#ifndef __WDT_H__
#define __WDT_H__


// Key register values
// Enable watchgog
#define KEY_ENABLE      0xCC
// Refresh watchdog
#define KEY_REFRESH     0xAA
// Access to control registers
#define KEY_ACCESS      0x55


// Init watchdog timer
void InitWdt(void);
// Reset watchdog timer
inline void ResetWdt(void)
{
    IWDG->KR = KEY_REFRESH;
}


#endif