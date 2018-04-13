// Header file
#include "EEPROMContainer.h"

void EEPROMContainer::initialize(void)
{
    Wh_stored = false;
}

void EEPROMContainer::saveCurrentWH(unsigned long *currentWH)
{
    if (!Wh_stored)
    {
        //Safe Wh in EEPROM
        //Throw out oldest Value
        //EEPROM.get(sizeof(unsigned long),WattHoursPreYesterday);
        EEPROM.put(WATTHOURS_3_DAYS_AGO, EEPROMContainer::getWH_twoDaysAgo());
        EEPROM.put(WATTHOURS_2_DAYS_AGO, EEPROMContainer::getWH_oneDayAgo());
        EEPROM.put(WATTHOURS_1_DAY_AGO, EEPROMContainer::getWH_currently());
        EEPROM.put(CURRENT_WATTHOURS, currentWH);
        Wh_stored = true;
    }
    else if (Wh_stored)
    {
        unsigned long WhTemp = EEPROMContainer::getWH_currently();
        if ((WhTemp + 36000) <= *currentWH)
        {
            EEPROM.put(CURRENT_WATTHOURS, currentWH);
            /*digitalWrite(13, HIGH);
            delay(500);
            digitalWrite(13, LOW);
            delay(500);
            digitalWrite(13, HIGH);
            delay(500);
            digitalWrite(13, LOW);*/
        }
        //Check if Wh have changed more than 0.01Wh
        //otherwise do not safe anything
    }
}

// Getter

unsigned long EEPROMContainer::getWH_currently(void)
{
    return EEPROM.read(CURRENT_WATTHOURS);
}

unsigned long EEPROMContainer::getWH_oneDayAgo(void)
{
    return EEPROM.read(WATTHOURS_1_DAY_AGO);
}

unsigned long EEPROMContainer::getWH_twoDaysAgo(void)
{
    return EEPROM.read(WATTHOURS_2_DAYS_AGO);
}

unsigned long EEPROMContainer::getWH_threeDaysAgo(void)
{
    return EEPROM.read(WATTHOURS_3_DAYS_AGO);
}
