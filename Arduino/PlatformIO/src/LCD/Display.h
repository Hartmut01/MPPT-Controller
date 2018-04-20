// ensure this  is only included once
#ifndef _DISPLAY_H_
#define _DISPLAY_H_

#include <LiquidCrystal_I2C.h>
#include "../Util/pins.h"
#include "../Util/DataContainer.h"

#define COLUMNS 20
#define ROWS 4

#define LCD_COLUMN_1 5
#define LCD_COLUMN_2 12


class Display
{
public:
  Display();
  void update(void);
  void setUpUI(void);

private:
  LiquidCrystal_I2C lcd;
};

#endif