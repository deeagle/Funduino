/**
 * Morse.cpp - Library for flashing Morse code.
 * Created by David A. Mellis, November 2, 2007.
 * Released into the public domain.
 */

#include "Arduino.h"
#include "./Morse.h"

Morse::Morse(int pin)
{
  pinMode(pin, OUTPUT);
  _pin = pin;
}

void Morse::dot()
{
  digOn(_pin);
  delay(250);
  digOff(_pin);
  delay(250);  
}

void Morse::dash()
{
  digOn(_pin);
  delay(1000);
  digOff(_pin);
  delay(250);
}

/**
 * Set the power to {@code HIGH} on given port.
 */
void Morse::digOn(int outputPort)
{
  digitalWrite(outputPort, HIGH);
}


/**
 * Set the power to {@code LOW} on given port.
 */
void Morse::digOff(int outputPort)
{
  digitalWrite(outputPort, LOW);
}
