#include <Wire.h>
#include <Adafruit_MCP4725.h>
#include <LiquidCrystal_I2C.h>

#define CurrPin  A6
#define VoltPin1 A2
#define VoltPin2 A3
#define LSB 4.8828125  //Spannung pro LSB in mV
#define StepSize 10


LiquidCrystal_I2C lcd(0x3f,20,4);  // set the LCD address to 0x27 for a 20 chars and 4 line display

Adafruit_MCP4725 dac;

static int VoltSet = 3360;
  float Volt = 0;
  float Amps = 0;
  float Power = 0;
float altVolt = 0;
float altAmps = 0;
float altPower = 0;
float outVolt = 0;
float outAmps = 0;
float outPower = 0;
int UpDn = 0;
int i=0;
int Alt_milli = 0;
int New_Milli = 0;
unsigned long WattHours =0;

void setup() {
  // put your setup code here, to run once:
  //Pins Definieren
  pinMode(CurrPin, INPUT);
  pinMode(VoltPin1, INPUT);
  pinMode(VoltPin2, INPUT);
  pinMode(13,OUTPUT);
  int j=0;

  dac.begin(0x62);
  dac.setVoltage(VoltSet, true);
  digitalWrite(13,HIGH);
  delay(500);
  digitalWrite(13,LOW);
  delay(500);
  //Initialisieren des LCD
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("Input:");
  lcd.setCursor(6,1);
  lcd.print("V");
  lcd.setCursor(6,2);
  lcd.print("A");
  lcd.setCursor(6,3);
  lcd.print("W");

    lcd.setCursor(10,0);
  lcd.print("Output:");
  lcd.setCursor(16,1);
  lcd.print("V");
  lcd.setCursor(16,2);
  lcd.print("A");
  lcd.setCursor(16,3);
  lcd.print("Wh");
delay(100);
j = getCurrent();
RefreshLCD();
while ( ((j + 40) > getCurrent()) && (VoltSet >=500))
{
  VoltSet-= StepSize;
  dac.setVoltage(VoltSet,false);
  delay(10);
  //j = getCurrent();

}
RefreshLCD();
digitalWrite(13,HIGH);
delay(500);
digitalWrite(13,LOW);
delay(500);
digitalWrite(13,HIGH);
delay(500);
digitalWrite(13,LOW);
delay(500);
digitalWrite(13,HIGH);
delay(500);
digitalWrite(13,LOW);
delay(500);
}

void loop() {
  // put your main code here, to run repeatedly
  //Aktuelle Werte für diesen Durchgang
  

  //Delta gegen letzten Durchgang
  float DeltaR = 0.0;
  float DeltaLi = 0.0;
  float DeltaRe = 0.0;
  float Resistance = 0.0;
  

//MPPT Hit and Miss

  altVolt = Volt;
  altAmps = Amps;
  altPower = Power;
  Volt = getVoltage();
  Amps = getCurrent();
  Power = Volt * Amps;
/*
  if ( Power <= altPower )
  {
    UpDn ^= 1;
  }
    if ( UpDn == 0)
    {
      VoltSet-= StepSize;
      digitalWrite(13,LOW);
    }
    if (UpDn == 1)
    {
    VoltSet+= StepSize;
    digitalWrite(13,HIGH);
    }
  */
  
 /* 
  dVolt = getVoltage() - Volt; //Delta berechnen
  Volt+= dVolt;                 //Aktuellen Wert abspeichern
  dAmps = getCurrent() - Amps;  //Delta berechnen
  Amps+= dAmps;                 //Aktuellen Wert abspeichern
  dPower = Volt * Amps - Power; //Delta berechnen
  Power = Volt * Amps;         //Aktuellen Wert abspeichern
  */
  
//MPPT schleife Diff Conductitiy

  DeltaR = (Amps-altAmps) / (Volt-altVolt) + (Amps/Volt);
 // DeltaLi = (Amps - altAmps) * Volt;
 // DeltaRe = -(Volt - altVolt) * Amps;
  //DeltaLi = (Amps-altAmps) / (Volt-altVolt);
  //DeltaRe = -(Amps/Volt);

  if (DeltaR < 0)
  {
    VoltSet-= StepSize;
    digitalWrite(13,LOW);
  }
  if (DeltaR > 0)
  {
    VoltSet+= StepSize;
    digitalWrite(13,HIGH);
  }


  
  if(VoltSet<=1000)
{
  VoltSet = 1000;
}
if (VoltSet >= 3360)
 {
  VoltSet = 3360;
 }

//Ende MPPT

 dac.setVoltage(VoltSet, false);
 if(i>=2)
 {
  outVolt = getOutVoltage();
  outAmps = getOutCurrent();
  outPower = outVolt * outAmps;

  
  New_Milli = millis();
  WattHours += ((outPower / 1000.0) * ((float) (New_Milli - Alt_milli) / 1000.0)) ;
  Alt_milli = New_Milli;
  RefreshLCD();
  i=0;
 }
 i++;
 delay(200);
 digitalWrite(13,LOW);
}



int getCurrent( void )
{
  int i;
  int Current = 0;
  //const float ACurrent = 6032/677 + 1;  //Verstärkung von der OPAmp Schaltung
  for ( i=0; i<=7; i++)
  {
    Current += analogRead(CurrPin);
  }
  return (Current * 5.51 / 8) ;  //Analog Wert umwandeln und Strom in Milliampere zurückgeben
  
}

int getOutCurrent( void )
{
  int i;
  int Current = 0;
  //const float ACurrent = 6032/677 + 1;  //Verstärkung von der OPAmp Schaltung
  for ( i=0; i<=7; i++)
  {
    Current += analogRead(A1);
  }
  return (Current * 3.62 / 8 + 71) ;  //Analog Wert umwandeln und Strom in Milliampere zurückgeben
  
}


int getVoltage ( void )
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
     for ( i=0; i<=7; i++)
  {
    Volts += analogRead(VoltPin1);
  }
  Volts = Volts * 24.1 / 8;
  
  return (Volts) ;  //Analog Wert umwandeln und Strom in Milliampere zurückgeben
   

}

int getOutVoltage ( void )
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
     for ( i=0; i<=7; i++)
  {
    Volts += analogRead(A3);
  }
  Volts = Volts * 13.84 / 8;
  
  return (Volts) ;  //Analog Wert umwandeln und Strom in Milliampere zurückgeben
   

}

void RefreshLCD()
{
  //Update Input Voltage
    lcd.setCursor(0,1);
    lcd.print("     ");
    lcd.setCursor(0,1);
    lcd.print((Volt/1000),3);
    //Update Input Current
    lcd.setCursor(0,2);
    lcd.print("     ");
    lcd.setCursor(0,2);
    lcd.print((Amps/1000),3);
    //Update Input Power
    lcd.setCursor(0,3);
    lcd.print("     ");
    lcd.setCursor(0,3);
    lcd.print((Power/1000000),3);

     lcd.setCursor(10,1);
    lcd.print("     ");
    lcd.setCursor(10,1);
    lcd.print((outVolt/1000),3);
    //Update Input Current
    lcd.setCursor(10,2);
    lcd.print("     ");
    lcd.setCursor(10,2);
    lcd.print((outAmps/1000),3);
    //Update Input Power
    lcd.setCursor(10,3);
    lcd.print("     ");
    lcd.setCursor(10,3);
    lcd.print((WattHours/3600000.0),3);
    
}

