// ensure this  is only included once
#ifndef _DATACONTAINER_H_
#define _DATACONTAINER_H_

class DataContainer
{
    struct WattHours
    {
        unsigned long current = 0;
        unsigned long oneDayAgo = 0;
        unsigned long twoDaysAgo = 0;
        unsigned long threeDaysAgo = 0;
    };

    struct MPPTData
    {
        float volt = 0;
        float amps = 0;
        float power = 0;
        float outVolt = 0;
        float outAmps = 0;
        float outPower = 0;
    };

    struct Controller
    {
        int outCurrent = 0;
        int outVoltage = 0;
    };

    struct SolarPanel
    {
        int inCurrent = 0;
        int inVoltage = 0;
    };

  public:
    static WattHours wattHours;
    static MPPTData mpptData;
    static Controller controller;
    static SolarPanel solarPanel;
};

#endif