// ensure this  is only included once
#ifndef _DATACONTAINER_H_
#define _DATACONTAINER_H_

#include "../Util/config.h"

class DataContainer
{
  public:
    struct WattHours
    {
        unsigned long current = 0;
        unsigned long oneDayAgo = 0;
        unsigned long twoDaysAgo = 0;
        unsigned long threeDaysAgo = 0;
    };

    struct MPPTData
    {
        float lastVoltage = 0;
        float lastCurrent = 0;
        float lastPower = 0;
        float deltaResistance = 0;
        unsigned int voltageSetpoint = 0;
    };

    struct Controller
    {
        unsigned int outCurrent = 0;
        unsigned int outVoltage = 0;
        unsigned int outPower = outCurrent * outVoltage;
    };

    struct SolarPanel
    {
        unsigned int inCurrent = 0;
        unsigned int inVoltage = 0;
        unsigned int inPower = inCurrent * inVoltage;
    };

    struct DAConverterSetpoint
    {
        unsigned int currentSetpoint = 0;
        unsigned int voltageSetpoint = 0;
    };

    WattHours wattHours;
    MPPTData mpptData;
    Controller controller;
    SolarPanel solarPanel;
    DAConverterSetpoint dacSetpoint;
};
static DataContainer dataContainer;
#endif