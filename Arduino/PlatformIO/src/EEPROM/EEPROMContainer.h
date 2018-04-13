// Arduino EEPROM lib
#include <EEPROM.h>

// ensure this  is only included once
#ifndef _EEPROMCONTAINER_H_
#define _EEPROMCONTAINER_H_

#define CURRENT_WATTHOURS 0
#define WATTHOURS_1_DAY_AGO 4
#define WATTHOURS_2_DAYS_AGO 8
#define WATTHOURS_3_DAYS_AGO 12

class EEPROMContainer
{
  public:
    void initialize(void);
    void saveCurrentWH(unsigned long *currentWH);

    // Getter
    unsigned long getWH_currently(void);
    unsigned long getWH_oneDayAgo(void);
    unsigned long getWH_twoDaysAgo(void);
    unsigned long getWH_threeDaysAgo(void);

  private:
    bool Wh_stored;
};

#endif