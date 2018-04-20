// Header file
#include "Display.h"
#include <LiquidCrystal_I2C.h>

Display::Display() : lcd(I2C_ADDRESS, COLUMNS, ROWS)
{
    lcd.init();
    lcd.backlight();
}

//Write Text on Display
//Text doesn't get updated
void Display::setUpUI(void)
{
    lcd.setCursor(0, 0);
    lcd.print("In:");
    lcd.setCursor(LCD_COLUMN_1, 1);
    lcd.print("V");
    lcd.setCursor(LCD_COLUMN_1, 2);
    lcd.print("A");
    lcd.setCursor(LCD_COLUMN_1, 3);
    lcd.print("W");

    lcd.setCursor(LCD_COLUMN_2 - 5, 0);
    lcd.print("Out:");
    lcd.setCursor(LCD_COLUMN_2, 1);
    lcd.print("V");
    lcd.setCursor(LCD_COLUMN_2, 2);
    lcd.print("A");
    lcd.setCursor(LCD_COLUMN_2, 3);
    lcd.print("W");
}

void Display::update(void)
{

    //Column 1
    //Update Input Voltage
    lcd.setCursor(4, 1);
    lcd.print(" ");
    lcd.setCursor(0, 1);
    lcd.print((Display::data.volt / 1000.0), 2);

    //Update Input Current
    //Not necesarry Current never reaches 10A
    //lcd.setCursor(4, 2);
    //lcd.print(" ");
    lcd.setCursor(0, 2);
    lcd.print((Display::data.amps / 1000.0), 3);

    //Update Input Power
    lcd.setCursor(4, 3);
    lcd.print(" ");
    lcd.setCursor(0, 3);
    lcd.print((Display::data.power / 1000000.0), 2);

    //Column 2
    //Update Output Voltage
    lcd.setCursor(11, 1);
    lcd.print(" ");
    lcd.setCursor(7, 1);
    lcd.print((Display::data.outVolt / 1000.0), 2);
    //Update Output Current
    //lcd.setCursor(11, 2);
    //lcd.print(" ");
    lcd.setCursor(7, 2);
    lcd.print((Display::data.outAmps / 1000.0), 3);
    //Update Output WattHours
    lcd.setCursor(11, 3);
    lcd.print(" ");
    lcd.setCursor(7, 3);
    lcd.print((Display::data.outPower / 1000000.0), 2);

    //Column 3
    //Update Watthours
    //lcd.setCursor(11, 0);
    //lcd.print(" ");
    lcd.setCursor(14, 0);
    lcd.print((Display::data.wattHours / 1000000.0), 2);
    //Update Watthours Yesterday
    //lcd.setCursor(11, 0);
    //lcd.print(" ");
    lcd.setCursor(14, 1);
    lcd.print((Display::data.wattHours_oneDayAgo / 1000000.0), 2);
    //Update Watthours Pre Yesterday
    //lcd.setCursor(11, 2);
    //lcd.print(" ");
    lcd.setCursor(14, 2);
    lcd.print((Display::data.wattHours_twoDaysAgo / 1000000.0), 2);
    //Update Watthours PrePre Yesterday
    //lcd.setCursor(11, 3);
    //lcd.print(" ");
    lcd.setCursor(14, 3);
    lcd.print((Display::data.wattHours_threeDaysAgo / 1000000.0), 2);
}