// Header file
#include "EEPROMContainer.h"
#include <EEPROM.h>

EEPROMContainer::EEPROMContainer(void)
{
    wattHoursStored = 0;

    EEPROM.get(CURRENT_WATTHOURS, dataContainer.wattHours.oneDayAgo);
    EEPROM.get(WATTHOURS_1_DAY_AGO, dataContainer.wattHours.twoDaysAgo);
    EEPROM.get(WATTHOURS_2_DAYS_AGO, dataContainer.wattHours.threeDaysAgo);
}

void EEPROMContainer::saveCurrentWH(void)
{
    //Detect end of Day
    //Safe Wh into EEPROM
    //InputVoltage <= 9,8V
    //Min Regulation 10V
    if ((dataContainer.controller.outVoltage <= (UNDERVOLT_LOCKOUT_EEPROM_SAFE - 200)))
    {
        if (wattHoursStored == 0)
        {
            //Safe Wh in EEPROM
            //Throw out oldest Value
            //EEPROM.get(sizeof(unsigned long),WattHoursPreYesterday);
            EEPROM.put(WATTHOURS_2_DAYS_AGO, dataContainer.wattHours.twoDaysAgo);
            EEPROM.put(WATTHOURS_1_DAY_AGO, dataContainer.wattHours.oneDayAgo);
            EEPROM.put(CURRENT_WATTHOURS, dataContainer.wattHours.current);
            wattHoursStored = 1;
        }
        else if (wattHoursStored == 1)
        {
            unsigned long WhTemp = dataContainer.wattHours.current;
            if ((WhTemp + 36000) <= dataContainer.wattHours.current)
            {
                EEPROM.put(CURRENT_WATTHOURS, dataContainer.wattHours.current);
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

void EEPROMContainer::checkDebugging(void)
{
    if ((digitalRead(DEBUG_ENABLE_PIN)) == 1)
    {
        wattHoursStored = 2; //Never reach EEPROM Safe Condition
    }
}