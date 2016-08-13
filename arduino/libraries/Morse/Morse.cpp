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
  digitalWrite(_pin, HIGH);
  delay(250);
  digitalWrite(_pin, LOW);
  delay(250);  
}

void Morse::dash()
{
  digitalWrite(_pin, HIGH);
  delay(1000);
  digitalWrite(_pin, LOW);
  delay(250);
}

///**
// * Set the power to {@code HIGH} on given port.
// */
//void Morse::digOn(int outputPort)
//{
//  digitalWrite(outputPort, HIGH);
//}
//
//
///**
// * Set the power to {@code LOW} on given port.
// */
//void Morse::digOff(int outputPort)
//{
//  digitalWrite(outputPort, LOW);
//}
