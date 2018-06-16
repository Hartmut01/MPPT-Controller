#include "ADConverter.h"

// Solar Panel
void ADConverter::readSolarPanelInput(void)
{
    ADConverter::readSolarPanelVoltage();
    ADConverter::readSolarPanelCurrent();
    dataContainer.solarPanel.inPower = dataContainer.solarPanel.inCurrent * dataContainer.solarPanel.inVoltage;
}

void ADConverter::readSolarPanelCurrent(void)
{

    int i;
    int Current = 0;
    //const float ACurrent = 6032/677 + 1;  //Verstärkung von der OPAmp Schaltung
    for (i = 0; i <= 7; i++)
    {
        Current += analogRead(INCURRENT_PIN);
    }
    dataContainer.solarPanel.inCurrent = (Current * 5.51 / 8); //Analog Wert umwandeln und Strom in Milliampere zurückgeben
}

void ADConverter::readSolarPanelVoltage(void)
{
    int Volts = 0.0;
    // int R1 = 4708;
    // int R2 = 1190;
    //Volts = analogRead ( VoltPin1) * LSB / R2 * ( R1 + R2 ); //Ausgabe der Spannung in mV aus dem Spannungsteiler. Auflösung:24,4mV

    /* if ( 15800 <= Volts <= 18800)  // zwischen 15,6 und 18,8V Genauer messung Möglich
   {
    Volts = analogRead (VoltPin2 ) * LSB * 776.529 + 14947;
   }
   */
    for (int i = 0; i <= 7; i++)
    {
        Volts += analogRead(INVOLTAGE_PIN);
    }
    dataContainer.solarPanel.inVoltage = Volts * 24.1 / 8;
}

// MPPT Controller
void ADConverter::readControllerOutput(void)
{
    readControllerVoltage();
    readControllerCurrent();
    dataContainer.controller.outPower = dataContainer.controller.outCurrent * dataContainer.controller.outVoltage;
}

void ADConverter::readControllerCurrent(void)
{
    int i;
    int Current = 0;
    //const float ACurrent = 6032/677 + 1;  //Verstärkung von der OPAmp Schaltung
    for (i = 0; i <= 7; i++)
    {
        Current += analogRead(OUTCURRENT_PIN);
    }
    dataContainer.controller.outCurrent = (Current * 3.62 / 8 + 71); //Analog Wert umwandeln und Strom in Milliampere zurückgeben
}

void ADConverter::readControllerVoltage(void)
{
    int Volts = 0.0;
    // int R1 = 4708;
    // int R2 = 1190;
    //Volts = analogRead ( VoltPin1) * LSB / R2 * ( R1 + R2 ); //Ausgabe der Spannung in mV aus dem Spannungsteiler. Auflösung:24,4mV

    /* if ( 15800 <= Volts <= 18800)  // zwischen 15,6 und 18,8V Genauer messung Möglich
   {
    Volts = analogRead (VoltPin2 ) * LSB * 776.529 + 14947;
   }
   */
    for (int i = 0; i <= 7; i++)
    {
        Volts += analogRead(OUTVOLTAGE_PIN);
    }
    dataContainer.controller.outVoltage = Volts * 13.84 / 8;
}