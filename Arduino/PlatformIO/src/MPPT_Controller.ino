
#include "Util/config.h"

/************* REFACTORING ***************/

IOSetup ios;
MPPT mppt;
EEPROMContainer eeprom;
Display display;

void setup()
{
  // initialize io
  ios.initialize();
  
  eeprom.checkDebugging();

  //Init Dac and set to Upper Limit
  DAConverter::initialize();

  //Wait until Inputpower is high enough to currentPower the SMPS
  mppt.waitForInputPower();

  //Initialisieren des LCD
  display.setUpUI();
  

  //Lower DAC Output until Inputvoltage Decreases by 40mV
  //Detect the upper Limit of the Solarpanel Voltage
  mppt.detectUpperSolarPanelVoltage();
}

void loop()
{
  mppt.updateData();

  eeprom.saveCurrentWH();

  mppt.calculateAndSetVoltage();

  display.update();

  delay(200);
  digitalWrite(DEBUG_LED_PIN, LOW);
}