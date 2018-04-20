#ifndef _ADCONVERTER_H_
#define _ADCONVERTER_H_

#include <Adafruit_MCP4725.h>
#include "../Util/pins.h"
#include "../Util/config.h"
#include "../Util/DataContainer.h"

class ADConverter
{
public:
  ADConverter();
  // Solar Panel
  void readSolarPanelInput(void);
  void readSolarPanelVoltage(void);
  void readSolarPanelCurrent(void);
  // MPPT Controller
  void reADConverterontrollerOutput(void);
  void reADConverterontrollerVoltage(void);
  void reADConverterontrollerCurrent(void);

private:
  Adafruit_MCP4725 dac;
};

#endif