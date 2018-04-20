// ensure this  is only included once
#ifndef _CONFIG_H_
#define _CONFIG_H_

#define LSB 4.8828125 // Voltage per LSB in mV
#define STEPSIZE_MPPT 10
#define UPPER_LIMIT 3360                 // Upper Limit DAC Output ~19,6V
#define LOWER_LIMIT 1700                 // Lower Limit DAC Output ~10V
#define UNDERVOLT_LOCKOUT_LOADLESS 15000 // Voltage in mV which has to be reached to activate the Controller
#define UNDERVOLT_LOCKOUT_EEPROM_SAFE 10000

#endif