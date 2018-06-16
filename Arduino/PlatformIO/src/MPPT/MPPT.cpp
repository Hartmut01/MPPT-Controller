// Header file
#include "MPPT.h"

void MPPT::waitForInputPower(void)
{
    //Wait until Inputpower is high enough to currentPower the SMPS
    ADConverter::readSolarPanelVoltage();
    while (dataContainer.solarPanel.inVoltage <= UNDERVOLT_LOCKOUT_LOADLESS)
    {
        delay(1000);
    }

    digitalWrite(POWER_SMPS_PIN, HIGH); //Switch on SMPS
    ADConverter::readSolarPanelVoltage();
    while (dataContainer.solarPanel.inVoltage <= UNDERVOLT_LOCKOUT_LOADLESS)
    {
        digitalWrite(POWER_SMPS_PIN, LOW);  //Switch off SMPS
        delay(10000);                       //Wait 10 Sec before next try
        digitalWrite(POWER_SMPS_PIN, HIGH); //Switch on SMPS
        delay(300);                         //Wait for Input Voltage to settle
    }
}

void MPPT::detectUpperSolarPanelVoltage(void)
{
    ADConverter::readSolarPanelVoltage();
    unsigned int solarPanelVoltage = dataContainer.solarPanel.inVoltage;

    while (((solarPanelVoltage - 40) <= dataContainer.solarPanel.inVoltage) && (dataContainer.mpptData.voltageSetpoint >= LOWER_DAC_LIMIT))
    {
        dataContainer.mpptData.voltageSetpoint -= STEPSIZE_MPPT;
        DAConverter::setControllerVoltage();
        ADConverter::readSolarPanelVoltage();
        delay(100);
    }
}

void MPPT::calculateAndSetVoltage(void)
{
    dataContainer.mpptData.deltaResistance =
        (dataContainer.solarPanel.inCurrent - dataContainer.mpptData.lastCurrent) / (dataContainer.solarPanel.inVoltage - dataContainer.mpptData.lastVoltage) + (dataContainer.mpptData.lastCurrent / dataContainer.mpptData.lastVoltage);
    // alternative calculation does not work yet, worth continuing for speed improvements?
    // DeltaLi = (Amps - altAmps) * Volt;
    // DeltaRe = -(Volt - altVolt) * Amps;
    //DeltaLi = (Amps-altAmps) / (Volt-altVolt);
    //DeltaRe = -(Amps/Volt);

    if (dataContainer.mpptData.deltaResistance < 0)
    {
        dataContainer.mpptData.voltageSetpoint -= STEPSIZE_MPPT;
        //digitalWrite(13, LOW);
    }
    else if (dataContainer.mpptData.deltaResistance > 0)
    {
        dataContainer.mpptData.voltageSetpoint += STEPSIZE_MPPT;
        //digitalWrite(13, HIGH);
    }

    if (dataContainer.mpptData.voltageSetpoint <= LOWER_DAC_LIMIT)
    {
        dataContainer.mpptData.voltageSetpoint = LOWER_DAC_LIMIT;
    }
    else if (dataContainer.mpptData.voltageSetpoint >= UPPER_DAC_LIMIT)
    {
        dataContainer.mpptData.voltageSetpoint = UPPER_DAC_LIMIT;
    }

    DAConverter::setControllerVoltage();
}

void MPPT::updateData(void)
{
    dataContainer.mpptData.lastVoltage = dataContainer.solarPanel.inVoltage;
    dataContainer.mpptData.lastCurrent = dataContainer.solarPanel.inCurrent;
    dataContainer.mpptData.lastPower = dataContainer.solarPanel.inPower;
    ADConverter::readControllerOutput();
}