// Header file
#include "MPPT.h"

void MPPT::calculate(void)
{
    //MPPT control loop
    altVolt = DataContainer::mpptData.volt;
    altAmps = DataContainer::mpptData.amps;

    DeltaR = (DataContainer::mpptData.amps - altAmps) 
    / (DataContainer::mpptData.volt - altVolt) + (DataContainer::mpptData.amps / DataContainer::mpptData.volt);
    // alternative calculation does not work yet, worth continuing for speed improvements?
    // DeltaLi = (Amps - altAmps) * Volt;
    // DeltaRe = -(Volt - altVolt) * Amps;
    //DeltaLi = (Amps-altAmps) / (Volt-altVolt);
    //DeltaRe = -(Amps/Volt);

    if (DeltaR < 0)
    {
        VoltSet -= STEPSIZE_MPPT;
        //digitalWrite(13, LOW);
    }
    else if (DeltaR > 0)
    {
        VoltSet += STEPSIZE_MPPT;
        //digitalWrite(13, HIGH);
    }

    if (VoltSet <= LOWER_LIMIT)
    {
        VoltSet = LOWER_LIMIT;
    }
    else if (VoltSet >= UPPER_LIMIT)
    {
        VoltSet = UPPER_LIMIT;
    }

    //end MPPT
}