
#include "Util/config.h"

IOSetup ioSetup;
MPPT mppt;
EEPROMContainer eeprom;
Display display;

void setup()
{
  // initialize I/O
  ioSetup.initialize();

  // check if eeprom debugging is enabled
  eeprom.checkDebugging();

  // initialize the DAC and set to upper voltage limit
  DAConverter::initialize();

  // wait until the input power is high enough to power the SMPS
  mppt.waitForInputPower();

  // intialize the LCD
  display.setUpUI();

  // lower the DAC output until the input voltage decreases by 40mV
  // detect the upper limit of the solarpanel voltage
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