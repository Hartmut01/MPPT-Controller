#ifndef _ADCONVERTER_H_
#define _ADCONVERTER_H_

#include "../Util/config.h"

class ADConverter
{
public:
  // Solar Panel
  static void readSolarPanelInput(void);
  static void readSolarPanelVoltage(void);
  static void readSolarPanelCurrent(void);
  // MPPT Controller
  static void readControllerOutput(void);
  static void readControllerVoltage(void);
  static void readControllerCurrent(void);

private:
  // Behave like a static class: no instanciation possible
  ADConverter();
};

#endif