// ensure this  is only included once
#ifndef _DISPLAY_H_
#define _DISPLAY_H_

#include "../Util/config.h"

#define COLUMNS 20
#define ROWS 4

#define LCD_COLUMN_1 5
#define LCD_COLUMN_2 12

#define REFRESH_UI_TIME_MILLIS 1000

class Display
{
public:
  Display();
  void update(void);
  void setUpUI(void);

private:
  LiquidCrystal_I2C lcd;
  unsigned long currentMillis = 0;
  unsigned long previousMillis = 0;
};

#endif