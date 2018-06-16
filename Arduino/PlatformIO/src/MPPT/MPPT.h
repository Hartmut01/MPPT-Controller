// ensure this  is only included once
#ifndef _MPPT_H_
#define _MPPT_H_

#include "../Util/config.h"

class MPPT
{
public:
  void waitForInputPower(void);
  void detectUpperSolarPanelVoltage(void);
  void calculateAndSetVoltage(void);
  void updateData(void);

private:
};

#endif