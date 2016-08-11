/**
 * file: funduino_de_nr14_plus_temperature
 * date: 10.08.2016 23:25 Uhr
 *
 * <h1>Measure temperature and show on LCD</h1>
 *
 * It's quite simple: we combine project 10 and 14.
 * 
 * @author deeagle <code@deeagle.de>
 */

#include <LiquidCrystal.h>
#include "DeeLib.h"

const int TMP36 = A0;
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
const int MAX_ROW_SIZE = 16;

const int MEASUREMENT_SERIES_INTERVAL = 1000;
const int MEASUREMENT_INTERVAL = 10000;

int temperature = 0;
const int TEMP_LENGTH = 10;
int temp[TEMP_LENGTH];
int tempIndex = 0;

DeeLib deeLib = DeeLib();

void setup()
{
  lcd.begin(16, 2);
}

void loop()
{
  temp[tempIndex] = readAndTransformTemperature();
  tempIndex = (tempIndex + 1) % TEMP_LENGTH;
  delay(MEASUREMENT_SERIES_INTERVAL);

  // is last index of the array?
  if( (TEMP_LENGTH - 1) == tempIndex )
  {
    temperature = calcMean();

    // send to display
    printTemperatureOnDisplay(temperature);


    delay(MEASUREMENT_INTERVAL);
  }
}

int readAndTransformTemperature()
{
  return map(analogRead(TMP36), 0, 410, -50, 150);
}

int calcMean()
{
  int result = 0;

  for( int i = 0; i < TEMP_LENGTH; i++ )
  {
    result += temp[i];
  }

  result /= TEMP_LENGTH;

  return result; 
}

void printTemperatureOnDisplay(const int temp)
{
  lcd.clear();
  lcd.setCursor(3, 0);
  lcd.print("Temperatur");
  lcd.setCursor(4, 1);
  lcd.print("ung. ");
  lcd.print(temp);
  lcd.print(" C");
}



