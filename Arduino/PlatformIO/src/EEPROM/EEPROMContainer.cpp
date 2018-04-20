// Header file
#include "EEPROMContainer.h"

EEPROMContainer::EEPROMContainer(void)
{
    Wh_stored = false;

    EEPROM.get(CURRENT_WATTHOURS, DataContainer::wattHours.oneDayAgo);
    EEPROM.get(WATTHOURS_1_DAY_AGO, DataContainer::wattHours.twoDaysAgo);
    EEPROM.get(WATTHOURS_2_DAYS_AGO, DataContainer::wattHours.threeDaysAgo);
}

void EEPROMContainer::saveCurrentWH(void)
{
    //Detect end of Day
    //Safe Wh into EEPROM
    //InputVoltage <= 9,8V
    //Min Regulation 10V
    if ((DataContainer::mpptData.volt <= (UNDERVOLT_LOCKOUT_EEPROM_SAFE - 200)))
    {
        if (!Wh_stored)
        {
            //Safe Wh in EEPROM
            //Throw out oldest Value
            //EEPROM.get(sizeof(unsigned long),WattHoursPreYesterday);
            EEPROM.put(WATTHOURS_2_DAYS_AGO, DataContainer::wattHours.twoDaysAgo);
            EEPROM.put(WATTHOURS_1_DAY_AGO, DataContainer::wattHours.oneDayAgo);
            EEPROM.put(CURRENT_WATTHOURS, DataContainer::wattHours.current);
            Wh_stored = true;
        }
        else if (Wh_stored)
        {
            unsigned long WhTemp = DataContainer::wattHours.current;
            if ((WhTemp + 36000) <= DataContainer::wattHours.current)
            {
                EEPROM.put(CURRENT_WATTHOURS, DataContainer::wattHours.current);
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
}