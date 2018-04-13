// Arduino EEPROM lib
#include <EEPROM.h>

// ensure this  is only included once
#ifndef _EEPROMCONTAINER_H_
#define _EEPROMCONTAINER_H_

#define CURRENT_WATTHOURS 0
#define WATTHOURS_1_DAY_AGO 3
#define WATTHOURS_2_DAYS_AGO 6
#define WATTHOURS_3_DAYS_AGO 9

class EEPROMContainer
{
  public:
    void initialize(void);
    void saveCurrentWH(long *currentWH);

    // Getter
    long getWH_currently(void);
    long getWH_oneDayAgo(void);
    long getWH_twoDaysAgo(void);
    long getWH_threeDaysAgo(void);

  private:
    bool Wh_stored;
};

#endif