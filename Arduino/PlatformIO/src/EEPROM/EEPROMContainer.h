// Arduino EEPROM lib
#include <EEPROM.h>
#include "../Util/DataContainer.h"
#include "../Util/config.h"

// ensure this  is only included once
#ifndef _EEPROMCONTAINER_H_
#define _EEPROMCONTAINER_H_

#define CURRENT_WATTHOURS 0
#define WATTHOURS_1_DAY_AGO 4
#define WATTHOURS_2_DAYS_AGO 8

class EEPROMContainer
{
public:
  EEPROMContainer(void);
  void initialize(void);
  void saveCurrentWH(void);

private:
  bool Wh_stored;
};

#endif