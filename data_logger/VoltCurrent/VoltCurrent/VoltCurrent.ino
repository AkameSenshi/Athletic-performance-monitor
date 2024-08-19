#include<SPI.h>
#include<SD.h>
#include <Wire.h>
#include <ds3231.h>

File dataFile;
struct ts t; 
//#define ANALOG_IN_PIN A0
 
// Floats for ADC voltage & Input voltage
float adc_voltage = 0.0;
float in_voltage = 0.0;
// Floats for resistor values in divider (in ohms)
float R1 = 30000.0;
float R2 = 7500.0;  
// Float for Reference Voltage
float ref_voltage = 5.0; 
// Integer for ADC value
int adc_value = 0;

void setup()
{
   // Setup Serial Monitor
   Serial.begin(9600);
   while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
   }
   Serial.print("Initializing SD card...");

   if (!SD.begin(4)) {
    Serial.println("initialization failed!");
    while (1);
   }
   Serial.println("initialization done.");
   Wire.begin();
   DS3231_init(DS3231_CONTROL_INTCN);
   /*----------------------------------------------------------------------------
   In order to synchronise your clock module, insert timetable values below !
   ----------------------------------------------------------------------------*/
   t.hour=14; 
   t.min=04;
   t.sec=0;
   t.mday=31;
   t.mon=5;
   t.year=2022;
   
   DS3231_set(t);
   Serial.println("DC Voltage and Current Test");
}

uint16_t line = 1;
 
void loop(){
  //timeGet();
  DS3231_get(&t);
  dataFile = SD.open("POWER.txt", FILE_WRITE);
  float v = voltageRead();
  float i = currentRead();
  if (dataFile) 
  {
    Serial.print(line);
    Serial.print(". Date: ");
    Serial.print(t.mday);
    Serial.print("/");
    Serial.print(t.mon);
    Serial.print("/");
    Serial.print(t.year);
    Serial.print(" Hour: ");
    Serial.print(t.hour);
    Serial.print(":");
    Serial.print(t.min);
    Serial.print(".");
    Serial.print(t.sec);
    Serial.print("  ||  Voltage = ");
    Serial.print(v);
    Serial.print("V Current = ");
    Serial.print(i);
    Serial.println("A"); 
    // Write data to SD card file (POWER.txt)
    dataFile.print(line++);
    dataFile.print(". Date: ");
    dataFile.print(t.mday);
    dataFile.print("/");
    dataFile.print(t.mon);
    dataFile.print("/");
    dataFile.print(t.year);
    dataFile.print(" Hour: ");
    dataFile.print(t.hour);
    dataFile.print(":");
    dataFile.print(t.min);
    dataFile.print(".");
    dataFile.print(t.sec);
    dataFile.print("  ||  Voltage = ");
    dataFile.print(v);
    dataFile.print("V Current = ");
    dataFile.print(i);
    dataFile.println("A");
    dataFile.close();
    
  }
  // if the file didn't open, print an error:
  else
    Serial.println("  Error opening POWER.txt");
    delay(1000);
}
