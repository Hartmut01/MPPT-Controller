#include "DAConverter.h"

Adafruit_MCP4725 DAConverter::dac;

void DAConverter::initialize(void)
{
    //Init Dac and set to Upper Limit
    dataContainer.mpptData.voltageSetpoint = UPPER_DAC_LIMIT;
    dac.begin(0x62);
    dac.setVoltage(dataContainer.mpptData.voltageSetpoint, false);
}

void DAConverter::setControllerVoltage(void)
{
    dac.setVoltage(dataContainer.mpptData.voltageSetpoint, false);
}