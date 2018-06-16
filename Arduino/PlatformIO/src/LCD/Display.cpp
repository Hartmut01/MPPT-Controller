// Header file
#include "Display.h"
#include <LiquidCrystal_I2C.h>

Display::Display() : lcd(LCD_ADDRESS, COLUMNS, ROWS)
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

    previousMillis = millis();
}

void Display::update(void)
{
    currentMillis = millis();

    if (currentMillis - previousMillis >= REFRESH_UI_TIME_MILLIS)
    {
        ADConverter::readControllerOutput();

        dataContainer.wattHours.current += ((dataContainer.controller.outPower / 3600.0) * ((float)(currentMillis - previousMillis) / 1000.0));
        previousMillis = currentMillis;

        //Column 1
        //Update Input Voltage
        lcd.setCursor(4, 1);
        lcd.print(" ");
        lcd.setCursor(0, 1);
        lcd.print((dataContainer.solarPanel.inVoltage / 1000.0), 2);

        //Update Input Current
        //Not necesarry Current never reaches 10A
        //lcd.setCursor(4, 2);
        //lcd.print(" ");
        lcd.setCursor(0, 2);
        lcd.print((dataContainer.solarPanel.inCurrent / 1000.0), 3);

        //Update Input Power
        lcd.setCursor(4, 3);
        lcd.print(" ");
        lcd.setCursor(0, 3);
        lcd.print((dataContainer.solarPanel.inPower / 1000000.0), 2);

        //Column 2
        //Update Output Voltage
        lcd.setCursor(11, 1);
        lcd.print(" ");
        lcd.setCursor(7, 1);
        lcd.print((dataContainer.controller.outVoltage / 1000.0), 2);
        //Update Output Current
        //lcd.setCursor(11, 2);
        //lcd.print(" ");
        lcd.setCursor(7, 2);
        lcd.print((dataContainer.controller.outCurrent / 1000.0), 3);
        //Update Output WattHours
        lcd.setCursor(11, 3);
        lcd.print(" ");
        lcd.setCursor(7, 3);
        lcd.print((dataContainer.controller.outPower / 1000000.0), 2);

        //Column 3
        //Update Watthours
        //lcd.setCursor(11, 0);
        //lcd.print(" ");
        lcd.setCursor(14, 0);
        lcd.print((dataContainer.wattHours.current / 1000000.0), 2);
        //Update Watthours Yesterday
        //lcd.setCursor(11, 0);
        //lcd.print(" ");
        lcd.setCursor(14, 1);
        lcd.print((dataContainer.wattHours.oneDayAgo / 1000000.0), 2);
        //Update Watthours Pre Yesterday
        //lcd.setCursor(11, 2);
        //lcd.print(" ");
        lcd.setCursor(14, 2);
        lcd.print((dataContainer.wattHours.twoDaysAgo / 1000000.0), 2);
        //Update Watthours PrePre Yesterday
        //lcd.setCursor(11, 3);
        //lcd.print(" ");
        lcd.setCursor(14, 3);
        lcd.print((dataContainer.wattHours.threeDaysAgo / 1000000.0), 2);
    }
}