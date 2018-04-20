#include "DAConverter.h"

void DAConverter::initialize(void)
{
    //Init Dac and set to Upper Limit
    DataContainer::mpptData.voltSetpoint = UPPER_LIMIT;
    dac.begin(0x62);
    dac.setVoltage(DataContainer::mpptData.voltSetpoint, false);
}

void DAConverter::setControllerVoltage(void)
{
    dac.setVoltage(DataContainer::mpptData.voltSetpoint, false);
}