// ensure this  is only included once
#ifndef _DISPLAY_H_
#define _DISPLAY_H_

#include <LiquidCrystal_I2C.h>

#define COLUMNS 20
#define ROWS 4
#define I2C_ADDRESS 0x3f // LCD address to 0x27

#define LCD_COLUMN_1 5
#define LCD_COLUMN_2 12

#include "../Util/Datacontainer.h"

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