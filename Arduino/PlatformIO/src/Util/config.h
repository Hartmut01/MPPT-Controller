// ensure this  is only included once
#ifndef _CONFIG_H_
#define _CONFIG_H_

#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_MCP4725.h>
#include <LiquidCrystal_I2C.h>

#include "../AD_DA_Conversion/ADConverter.h"
#include "../AD_DA_Conversion/DAConverter.h"
#include "../EEPROM/EEPROMContainer.h"
#include "../LCD/Display.h"
#include "../MPPT/MPPT.h"
#include "../Util/DataContainer.h"
#include "../Util/pins.h"

#define LSB 4.8828125 // Voltage per LSB in mV
#define STEPSIZE_MPPT 10
#define UPPER_DAC_LIMIT 3360                 // Upper Limit DAC Output ~19,6V
#define LOWER_DAC_LIMIT 1700                 // Lower Limit DAC Output ~10V
#define UNDERVOLT_LOCKOUT_LOADLESS 15000 // Voltage in mV which has to be reached to activate the Controller
#define UNDERVOLT_LOCKOUT_EEPROM_SAFE 10000

#endif