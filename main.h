#ifndef __MAIN_H__
#define __MAIN_H__

#include "Arduino.h"
#define APP_NAME "T2404_edog_master"

typedef enum
{
  EEPROM_ADDR_USER_START  = 0x0000,
  EEPROM_ADDR_USER_END    = 0x017F,
  EEPROM_ADDR_WD_INTERVAL = 0x0180,
  EEPROM_ADDR_SLEEP_TIME  = 0x0184,
  EEPROM_ADDR_LAST        = 0x01FF,
  EEPROM_ADDR_2           = 0x018C,

} eeprom_addr_et;


#endif