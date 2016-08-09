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


/**
 * Set the power to {@code HIGH} on given port.
 */
void DeeLib::digOn(int outputPort)
{
  digitalWrite(outputPort, HIGH);
}


/**
 * Set the power to {@code LOW} on given port.
 */
void DeeLib::digOff(int outputPort)
{
  digitalWrite(outputPort, LOW);
}

