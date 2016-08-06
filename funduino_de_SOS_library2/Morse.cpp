/**
 * Morse.cpp - Library for flashing Morse code.
 * Created by David A. Mellis, November 2, 2007.
 * Released into the public domain.
 */

#include "Arduino.h"
#include "./Morse.h"
#include "./DeeLib.h"

Morse::Morse(int pin)
{
  pinMode(pin, OUTPUT);
  _pin = pin;
  _deeLib = DeeLib();
}

void Morse::dot()
{
  _deeLib.digOn(_pin);
  delay(250);
  _deeLib.digOff(_pin);
  delay(250);  
}

void Morse::dash()
{
  _deeLib.digOn(_pin);
  delay(1000);
  _deeLib.digOff(_pin);
  delay(250);
}
