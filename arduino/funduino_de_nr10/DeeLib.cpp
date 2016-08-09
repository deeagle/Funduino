/**
 * DeeLib.cpp - Library for own functions
 * 
 * @autor deeagle <code@deeagle.de>
 */

#include "Arduino.h"
#include "DeeLib.h"


DeeLib::DeeLib()
{
}


void DeeLib::blinkOne(int pinPort)
{
  digOn(pinPort);
  delay(500);
  digOff(pinPort);
}


void DeeLib::digOn(int pinPort)
{
  digitalWrite(pinPort, HIGH);
}


void DeeLib::digOff(int pinPort)
{
  digitalWrite(pinPort, LOW);
}


boolean DeeLib::isButtonPressed(int pinPort)
{
  boolean isButtonSignal = false;

  int button_state = digitalRead(pinPort);
  if( HIGH == button_state )
  {
    isButtonSignal = true;
  }

  return isButtonSignal;
}

