// ensure this  is only included once
#ifndef _DISPLAY_H_
#define _DISPLAY_H_

#include <LiquidCrystal_I2C.h>

#define COLUMNS 20
#define ROWS 4
#define I2C_ADDRESS 0x3f // LCD address to 0x27

#define LCD_COLUMN_1 5
#define LCD_COLUMN_2 12

class Display
{
  struct DisplayData
  {
    float volt = 0;
    float amps = 0;
    float power = 0;
    float outVolt = 0;
    float outAmps = 0;
    float outPower = 0;
    unsigned long wattHours = 0;
    unsigned long wattHours_oneDayAgo = 0;
    unsigned long wattHours_twoDaysAgo = 0;
    unsigned long wattHours_threeDaysAgo = 0;
  };

public:
  static DisplayData data;

  Display();
  void update(void);
  void setUpUI(void);

private:
  LiquidCrystal_I2C lcd;
};

#endif