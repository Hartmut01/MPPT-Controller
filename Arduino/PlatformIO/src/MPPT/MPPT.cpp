// Header file
#include "MPPT.h"

void MPPT::calculate(void)
{
    //MPPT schleife Diff Conductitiy
    altVolt = DataContainer::mpptData.volt;
    altAmps = DataContainer::mpptData.amps;

    DeltaR = (DataContainer::mpptData.amps - altAmps) 
    / (DataContainer::mpptData.volt - altVolt) + (DataContainer::mpptData.amps / DataContainer::mpptData.volt);
    //Alternative ohne Division hat nicht so gut funktioniert.
    //Geschwindigkeitsvorteil?!?
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

    //Ende MPPT
}