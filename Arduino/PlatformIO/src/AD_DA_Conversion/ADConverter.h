#ifndef _ADCONVERTER_H_
#define _ADCONVERTER_H_

#include <Adafruit_MCP4725.h>
#include "../Util/pins.h"
#include "../Util/config.h"
#include "../Util/DataContainer.h"

class ADConverter
{
public:
  // Solar Panel
  static void readSolarPanelInput(void);
  static void readSolarPanelVoltage(void);
  static void readSolarPanelCurrent(void);
  // MPPT Controller
  static void reADConverterontrollerOutput(void);
  static void reADConverterontrollerVoltage(void);
  static void reADConverterontrollerCurrent(void);

private:
  // Behave like a static class: no instanciation possible
  ADConverter();
};

#endif