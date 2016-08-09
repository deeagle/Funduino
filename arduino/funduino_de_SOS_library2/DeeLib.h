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
  DeeLib();
  void digOn(int port);
  void digOff(int port);
private:
};

#endif

