// ensure this  is only included once
#ifndef _PINS_H_
#define _PINS_H_

#include <Arduino.h>

// I²C devices
#define I2C_ADDRESS 0x3f // LCD address to 0x27
#define MPC4725_ADDRESS 0x62

#define INCURRENTPIN A6
#define INVOLTPIN A2
#define OUTCURRENTPIN A1
#define OUTVOLTPIN A3
#define DEBUG_LED 13
#define POWER_SMPS 4
#define NEIGHBOR_DEBUG 8
#define DEBUG_ENABLE 7

class IOSetup
{
  public:
    static void initialize()
    { //Pins Definieren
        pinMode(INCURRENTPIN, INPUT);
        pinMode(INVOLTPIN, INPUT);
        pinMode(OUTVOLTPIN, INPUT);
        pinMode(OUTCURRENTPIN, INPUT);
        pinMode(DEBUG_LED, OUTPUT);
        pinMode(DEBUG_ENABLE, INPUT_PULLUP);
        pinMode(NEIGHBOR_DEBUG, OUTPUT);
        pinMode(POWER_SMPS, OUTPUT);

        //Init Set OutPut Pins
        digitalWrite(NEIGHBOR_DEBUG, LOW);
        digitalWrite(DEBUG_LED, LOW);
        digitalWrite(POWER_SMPS, LOW);
    }
};

#endif