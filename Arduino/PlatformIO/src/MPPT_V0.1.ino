#include <Wire.h>
#include <Adafruit_MCP4725.h>
#include <LiquidCrystal_I2C.h>
#include <EEPROM.h>


//Globale Definitionen
//Pins
#define INCURRENTPIN A6
#define INVOLTPIN A2
#define OUTCURRENTPIN A1
#define OUTVOLTPIN A3
#define DEBUG_LED 13
#define POWER_SMPS 4
#define NEIGHBOR_DEBUG 10
#define DEBUG_ENABLE 7



//Variables
#define LSB 4.8828125 //Spannung pro LSB in mV
#define STEPSIZE_MPPT 10
#define UPPER_LIMIT 3360  //Upper Limit DAC Output ~19,6V
#define LOWER_LIMIT 1700  //Lower Limit DAC Output ~10V
#define UNDERVOLT_LOCKOUT_LOADLESS 15000 //Voltage in mV before which the Controller doesnt od anything


LiquidCrystal_I2C lcd(0x3f, 20, 4); // set the LCD address to 0x27 for a 20 chars and 4 line display

Adafruit_MCP4725 dac;

int VoltSet = UPPER_LIMIT;
float Volt = 0;
float Amps = 0;
float Power = 0;
float altVolt = 0;
float altAmps = 0;
float altPower = 0;
float outVolt = 0;
float outAmps = 0;
float outPower = 0;
int i = 0;
int Wh_Safed = 0;
int Alt_milli = 0;
int New_Milli = 0;
unsigned long WattHours = 0;
unsigned long WattHoursYesterday = 0;
unsigned long WattHoursPreYesterday = 0;
unsigned long WattHoursPrePreYesterday = 0;

void setup()
{
  // put your setup code here, to run once:
  //Pins Definieren
  pinMode(INCURRENTPIN, INPUT);
  pinMode(INVOLTPIN, INPUT);
  pinMode(OUTVOLTPIN, INPUT);
  pinMode(OUTCURRENTPIN, INPUT);
  pinMode(DEBUG_LED, OUTPUT);
  pinMode(DEBUG_ENABLE, INPUT_PULLUP);
  pinMode(NEIGHBOR_DEBUG, OUTPUT);
  pinMode(POWER_SMPS, OUTPUT);
  //Temp Variables Setup 
  int j = 0;

  //Init Set OutPut Pins
  digitalWrite(NEIGHBOR_DEBUG, LOW);
  digitalWrite(DEBUG_LED, LOW);
  digitalWrite(POWER_SMPS, LOW);
  
  
  //Enable DEBUG MODE
  //DO not Safe Values into EEPROM
  if (digitalRead(DEBUG_ENABLE) == true)
  {
    Wh_Safed = 2; //Never reach EEPROM Safe Condition
  }

  //Init Dac and set to Upper Limit 
  dac.begin(0x62);
  dac.setVoltage(VoltSet, false);

  //Wait until Inputpower is high enough to power the SMPS
  while ( getVoltage() <= UNDERVOLT_LOCKOUT_LOADLESS)
  {
    delay(1000);
  }

  digitalWrite(POWER_SMPS, HIGH); //Switch on SMPS

  while( getVoltage() <= UNDERVOLT_LOCKOUT_LOADLESS)
  {
    digitalWrite(POWER_SMPS, LOW); //Switch off SMPS
    delay(10000);                   //Wait 10 Sec before next try
    digitalWrite(POWER_SMPS, HIGH); //Switch on SMPS
    delay(300);                     //Wait for Input Voltage to settle
  }

  //Initialisieren des LCD
  lcd.init();
  lcd.backlight();
  LCD_Write_Text();
  

  //Update Wh Values from EEPROM
  EEPROM.get(0,WattHoursYesterday);
  EEPROM.get(4,WattHoursPreYesterday);
  EEPROM.get(8,WattHoursPrePreYesterday);


  //Lower DAC Output until Inputvoltage Decreases by 40mV
  //Detect the upper Limit of the Solarpanel Voltage
  j = getVoltage();

  while (((j - 40) <= getVoltage()) && (VoltSet >= LOWER_LIMIT))
  {
    VoltSet -= STEPSIZE_MPPT;
    dac.setVoltage(VoltSet, false);
    delay(100);
  }

}


void loop()
{
  // put your main code here, to run repeatedly
  //Aktuelle Werte für diesen Durchgang

  //Delta gegen letzten Durchgang
  float DeltaR = 0.0;
  unsigned long WatthoursTemp = 0;
  //float DeltaLi = 0.0;
  //float DeltaRe = 0.0;
  //float Resistance = 0.0;


  altVolt = Volt;
  altAmps = Amps;
  altPower = Power;
  Volt = getVoltage();
  Amps = getCurrent();
  Power = Volt * Amps;
 
  //Detect end of Day
  //Safe Wh into EEPROM
  //InputVoltage <= 9,8V
  //Min Regulation 10V
  if ((Volt <= (LOWER_LIMIT - 200)))
  {
    if (Wh_Safed == 0)
    {
      //Safe Wh in EEPROM
      //Throw out oldest Value
      //EEPROM.get(sizeof(unsigned long),WattHoursPreYesterday);
      EEPROM.put( 8, WattHoursPreYesterday);
      EEPROM.put( 4, WattHoursYesterday);
      EEPROM.put( 0, WattHours);
      Wh_Safed = 1;


    }
    else if (Wh_Safed == 1)
    {
      EEPROM.get(0,WatthoursTemp);

      if ( (WatthoursTemp + 1000000) <= WattHours)
      {
        EEPROM.put( 0, WattHours);
       /* digitalWrite(13, HIGH);
      delay(500);
      digitalWrite(13, LOW);
      delay(500);
      digitalWrite(13, HIGH);
      delay(500);
      digitalWrite(13, LOW);
      */
      }
      //Check if Wh have changed more than 1Wh
      //otherwise do not safe anything
    }
  }



  //MPPT schleife Diff Conductitiy

  DeltaR = (Amps - altAmps) / (Volt - altVolt) + (Amps / Volt);
  //Alternative ohne Division hat nicht so gut funktioniert.
  //Geschwindigkeitsvorteil?!?
  // DeltaLi = (Amps - altAmps) * Volt;
  // DeltaRe = -(Volt - altVolt) * Amps;
  //DeltaLi = (Amps-altAmps) / (Volt-altVolt);
  //DeltaRe = -(Amps/Volt);

  if (DeltaR < 0)
  {
    VoltSet -= STEPSIZE_MPPT;
    //digitalWrite(13, LOW);
  }
  else if (DeltaR > 0)
  {
    VoltSet += STEPSIZE_MPPT;
    //digitalWrite(13, HIGH);
  }

  if (VoltSet <= LOWER_LIMIT)
  {
    VoltSet = LOWER_LIMIT;
  }
  else if (VoltSet >= UPPER_LIMIT)
  {
    VoltSet = UPPER_LIMIT;
  }

  //Ende MPPT

  dac.setVoltage(VoltSet, false);
  if (i >= 3)
  {
    outVolt = getOutVoltage();
    outAmps = getOutCurrent();
    outPower = outVolt * outAmps;

    New_Milli = millis();
    WattHours += ((outPower / 3600.0) * ((float)(New_Milli - Alt_milli) / 1000.0));
    Alt_milli = New_Milli;
    RefreshLCD();
    i = 0;
  }
  i++;
  delay(200);
  digitalWrite(13, LOW);
}

int getCurrent(void)
{
  int i;
  int Current = 0;
  //const float ACurrent = 6032/677 + 1;  //Verstärkung von der OPAmp Schaltung
  for (i = 0; i <= 7; i++)
  {
    Current += analogRead(INCURRENTPIN);
  }
  return (Current * 5.51 / 8); //Analog Wert umwandeln und Strom in Milliampere zurückgeben
}

int getOutCurrent(void)
{
  int i;
  int Current = 0;
  //const float ACurrent = 6032/677 + 1;  //Verstärkung von der OPAmp Schaltung
  for (i = 0; i <= 7; i++)
  {
    Current += analogRead(OUTCURRENTPIN);
  }
  return (Current * 3.62 / 8 + 71); //Analog Wert umwandeln und Strom in Milliampere zurückgeben
}

int getVoltage(void)
{
  int Volts = 0.0;
  int R1 = 4708;
  int R2 = 1190;
  int i = 0;
  //Volts = analogRead ( VoltPin1) * LSB / R2 * ( R1 + R2 ); //Ausgabe der Spannung in mV aus dem Spannungsteiler. Auflösung:24,4mV

  /* if ( 15800 <= Volts <= 18800)  // zwischen 15,6 und 18,8V Genauer messung Möglich
   {
    Volts = analogRead (VoltPin2 ) * LSB * 776.529 + 14947;
   }
   */
  for (i = 0; i <= 7; i++)
  {
    Volts += analogRead(INVOLTPIN);
  }
  Volts = Volts * 24.1 / 8;

  return (Volts); //Analog Wert umwandeln und Strom in Milliampere zurückgeben
}

int getOutVoltage(void)
{
  int Volts = 0.0;
  int R1 = 4708;
  int R2 = 1190;
  int i = 0;
  //Volts = analogRead ( VoltPin1) * LSB / R2 * ( R1 + R2 ); //Ausgabe der Spannung in mV aus dem Spannungsteiler. Auflösung:24,4mV

  /* if ( 15800 <= Volts <= 18800)  // zwischen 15,6 und 18,8V Genauer messung Möglich
   {
    Volts = analogRead (VoltPin2 ) * LSB * 776.529 + 14947;
   }
   */
  for (i = 0; i <= 7; i++)
  {
    Volts += analogRead(OUTVOLTPIN);
  }
  Volts = Volts * 13.84 / 8;

  return (Volts); //Analog Wert umwandeln und Strom in Milliampere zurückgeben
}

//Write Text on Display
//Text doesn't get updated
void LCD_Write_Text ( void )
{
  #define LCD_COLUMN_1 5
  #define LCD_COLUMN_2 12

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
void RefreshLCD()
{
//Column 1
  //Update Input Voltage
  lcd.setCursor(4, 1);
  lcd.print(" ");
  lcd.setCursor(0, 1);
  lcd.print((Volt / 1000.0), 2);

  //Update Input Current
  //Not necesarry Current never reaches 10A
  //lcd.setCursor(4, 2);
  //lcd.print(" ");
  lcd.setCursor(0, 2);
  lcd.print((Amps / 1000.0), 3);

  //Update Input Power
  lcd.setCursor(4, 3);
  lcd.print(" ");
  lcd.setCursor(0, 3);
  lcd.print((Power / 1000000.0), 2);

//Column 2
  //Update Output Voltage
  lcd.setCursor(11, 1);
  lcd.print(" ");
  lcd.setCursor(7, 1);
  lcd.print((outVolt / 1000.0), 2);
  //Update Output Current
  //lcd.setCursor(11, 2);
  //lcd.print(" ");
  lcd.setCursor(7, 2);
  lcd.print((outAmps / 1000.0), 3);
  //Update Output WattHours
  lcd.setCursor(11, 3);
  lcd.print(" ");
  lcd.setCursor(7, 3);
  lcd.print((outPower / 1000000.0), 2);

  //Column 3
  //Update Watthours
  //lcd.setCursor(11, 0);
  //lcd.print(" ");
  lcd.setCursor(14, 0);
  lcd.print((WattHours / 1000000.0), 2);
//Update Watthours Yesterday
  //lcd.setCursor(11, 0);
  //lcd.print(" ");
  lcd.setCursor(14, 1);
  lcd.print((WattHoursYesterday / 1000000.0), 2);
  //Update Watthours Pre Yesterday
  //lcd.setCursor(11, 2);
  //lcd.print(" ");
  lcd.setCursor(14, 2);
  lcd.print((WattHoursPreYesterday / 1000000.0), 2);
  //Update Watthours PrePre Yesterday
  //lcd.setCursor(11, 3);
  //lcd.print(" ");
  lcd.setCursor(14, 3);
  lcd.print((WattHoursPrePreYesterday / 1000000.0), 2);
}
