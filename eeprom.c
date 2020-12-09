// STM8S103F3
#include "stm8s.h"

//user
#include "eeprom.h"

#define EEPROM_START_ADDRESS    0x004000ul
#define EEPROM_KEY1             0xAE
#define EEPROM_KEY2             0x56

// EEPROM variable address
uint8_t* eeprom_value = (uint8_t*)EEPROM_START_ADDRESS;

// Local functions
// Enable EEPROM erasing and writing
void EnableEeprom(void);
// Disable EEPROM erasing and writing
void DisableEeprom(void);
// Wait while EEPROM erasing operation performing
void WaitEeprom(void);

// Save 8-bit value into EEPROM
void SaveToEeprom(uint8_t val)
{
    EnableEeprom();
    
    // Erase previous value
    *eeprom_value = 0;
    WaitEeprom();
    
    // Write new value
    *eeprom_value = val;
    
    DisableEeprom();
}
// Get previously saved value from EEPROM
uint8_t GetFromEeprom(void)
{
    return (*eeprom_value);
}

// Enable EEPROM erasing and writing
void EnableEeprom(void)
{
    // writing enable key values
    FLASH->DUKR = EEPROM_KEY1;
    FLASH->DUKR = EEPROM_KEY2;
}
// Disable EEPROM erasing and writing
void DisableEeprom(void)
{
    FLASH->IAPSR &= ~FLASH_IAPSR_DUL;
}
// Wait while EEPROM erasing operation performing
void WaitEeprom(void)
{
    while ((FLASH->IAPSR & FLASH_IAPSR_EOP) == 0)
        ;
}

