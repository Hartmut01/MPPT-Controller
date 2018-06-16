// ensure this  is only included once
#ifndef _EEPROMCONTAINER_H_
#define _EEPROMCONTAINER_H_

#include "../Util/config.h"

#define CURRENT_WATTHOURS 0
#define WATTHOURS_1_DAY_AGO 4
#define WATTHOURS_2_DAYS_AGO 8

class EEPROMContainer
{
public:
  EEPROMContainer(void);
  void initialize(void);
  void saveCurrentWH(void);
  void checkDebugging(void);

private:
  uint8_t wattHoursStored;
};

#endif