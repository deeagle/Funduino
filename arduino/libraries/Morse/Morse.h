/**
 * Morse.h - Library for flashing Morse code.
 * Created by David A. Mellis, November 2, 2007.
 * Released into the public domain.
 */
#ifndef Morse_h
#define Morse_h

#if ARDUINO >= 100
    #include "Arduino.h"
#else
    #include "WProgram.h"
    #include "pins_arduino.h"
    #include "WConstants.h"
#endif

class Morse
{
  public:
    Morse(int pin);
    void dot();
    void dash();
  private:
    int _pin;
 };

#endif
