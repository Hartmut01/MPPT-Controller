// ensure this  is only included once
#ifndef _PINS_H_
#define _PINS_H_

#include "../Util/config.h"

// I²C devices
#define LCD_ADDRESS 0x3f
#define MPC4725_ADDRESS 0x62

#define INCURRENT_PIN A6
#define INVOLTAGE_PIN A2
#define OUTCURRENT_PIN A1
#define OUTVOLTAGE_PIN A3
#define DEBUG_LED_PIN 13
#define POWER_SMPS_PIN 4
#define NEIGHBOR_DEBUG_PIN 8
#define DEBUG_ENABLE_PIN 7

class IOSetup
{
  public:
    static void initialize()
    { //Pins Definieren
        pinMode(INCURRENT_PIN, INPUT);
        pinMode(INVOLTAGE_PIN, INPUT);
        pinMode(OUTVOLTAGE_PIN, INPUT);
        pinMode(OUTCURRENT_PIN, INPUT);
        pinMode(DEBUG_LED_PIN, OUTPUT);
        pinMode(DEBUG_ENABLE_PIN, INPUT_PULLUP);
        pinMode(NEIGHBOR_DEBUG_PIN, OUTPUT);
        pinMode(POWER_SMPS_PIN, OUTPUT);

        //Init Set OutPut Pins
        digitalWrite(NEIGHBOR_DEBUG_PIN, LOW);
        digitalWrite(DEBUG_LED_PIN, LOW);
        digitalWrite(POWER_SMPS_PIN, LOW);
    }
};

#endif