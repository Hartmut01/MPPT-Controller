#ifndef _DACONVERTER_H_
#define _DACONVERTER_H_

#include "../Util/config.h"

class DAConverter
{
  public:
    static void initialize(void);
    static void setControllerVoltage(void);

  private:
    // Behave like a static class: no instanciation possible
    DAConverter(void);
    static Adafruit_MCP4725 dac;
};

#endif