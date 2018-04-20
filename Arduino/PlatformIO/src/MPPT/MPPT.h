// ensure this  is only included once
#ifndef _MPPT_H_
#define _MPPT_H_

#include "../Util/DataContainer.h"
#include "../Util/config.h"

class MPPT
{
public:
  void calculate(void);

private:
  float DeltaR = 0;
  int VoltSet = UPPER_LIMIT;
  float altVolt = 0;
  float altAmps = 0;
};

#endif