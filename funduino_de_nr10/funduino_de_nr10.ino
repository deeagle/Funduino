/**
 * file: funduino_de_nr09
 * date: 08.08.2016 23:35 Uhr
 *
 * @author deeagle <code@deeagle.de>
 *
 */

#include "DeeLib.h"

const int TMP36 = A0;
const int SERIAL_BAUD = 9600;
const int MEASUREMENT_SERIES_INTERVAL = 20;
const int MEASUREMENT_INTERVAL = 1000;

int temperature = 0;
const int TEMP_LENGTH = 10;
int temp[TEMP_LENGTH];
int tempIndex = 0;

DeeLib deeLib = DeeLib();


void setup()
{
  Serial.begin(SERIAL_BAUD);
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

    sendSerial(temperature);

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

void sendSerial(int temperature)
{
  Serial.print(temperature);
  Serial.println(" Grad Celsius");
}



