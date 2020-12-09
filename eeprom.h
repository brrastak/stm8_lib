
#ifndef __EEPROM_H__
#define __EEPROM_H__


// Save 8-bit value into EEPROM
void SaveToEeprom(uint8_t val);
// Get previously saved value from EEPROM
uint8_t GetFromEeprom(void);


#endif