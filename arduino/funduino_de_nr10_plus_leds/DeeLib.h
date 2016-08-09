/**
 * DeeLib.h - Library for own functions
 * 
 * @autor deeagle <code@deeagle.de>
 */

#ifndef DeeLib_h
#define DeeLib_h

#include "Arduino.h"

class DeeLib
{
public:
  /**
   * Default constructor.
   */
  DeeLib();

  /**
   * Let the LED blink one time.
   *
   * @param pinPort The pin port of the LED
   */
  void blinkOne(int pinPort);

  /**
   * Set the power to {@code HIGH} on given port.
   *
   * @param pinPort The pin port of the LED
   */
  void digOn(int pinPort);

  /**
   * Set the power to {@code LOW} on given port.
   *
   * @param pinPort The pin port of the LED
   */
  void digOff(int pinPort);

  /**
   * Returns the state of the button.
   * <p>
   * Don't forget to declare the input button in the setup.
   * 
   * @param pinPort The input port of the button
   * @return {@code true} when the button is pressed, otherwise {@code false}
   */
  boolean isButtonPressed(int pinPort);

private:
};

#endif




