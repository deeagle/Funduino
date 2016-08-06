/**
 * file: TeaTimer
 * date: 06.08.2016 19:52 Uhr
 *
 * <h1>TeaTimer</h1>
 *
 * A five minute tea timer.
 *
 * <h2>Arduino-Kit</h2>
 * <ul>
 * <li>Arduino UNO</li>
 * <li>4x blue LED</li>
 * <li>1x green LED</li>
 * <li>5x 100 Ohm resistor</li>
 * <li>1x 1k Ohm resistor</li>
 * <li>1x button</li>
 * </ul>
 *
 * @autor deeagle <code@deeagle.de>
 */

#include "DeeLib.h"


/**
 * Declare input/output pins.
 */
int BUTTON = 13;
int LED_1 = 12;
int LED_2 = 8;
int LED_3 = 7;
int LED_4 = 4;
int LED_5 = 2;


/**
 * Some timer stuff.
 */
int TIMER_STATE_OFF = 0;
int TIMER_STATE_ON = 1;
int timerState = TIMER_STATE_OFF;
boolean isTimerFinished = false;
int TIMER_ZERO = 0;
int TIMER_MAX = 5;
int timerCounter = TIMER_ZERO;
int TIMER_INTERVAL = 60; // 60 -> 60 sec -> 1 min

/**
 * Lib objects.
 */
DeeLib deeLib = DeeLib();


/**
 * Runs only once 
 */
void setup()
{
  pinMode(LED_1, OUTPUT);
  pinMode(LED_2, OUTPUT);
  pinMode(LED_3, OUTPUT);
  pinMode(LED_4, OUTPUT);
  pinMode(LED_5, OUTPUT);

  pinMode(BUTTON, INPUT);

  testLeds();
}


/**
 * The main loop which will be used after init {@see this#setup()}
 */
void loop()
{
  if( TIMER_STATE_ON == timerState )
  {
    timerLoop();
  }
  else
  {
    if( deeLib.isButtonPressed(BUTTON) )
    {
      startTimer();
    }
  }
}


/**
 * The loop for the timer.
 */
void timerLoop()
{
  if( !isTimerFinished )
  {
    if( TIMER_ZERO == timerCounter )
    {
      blinkFor(LED_1, TIMER_INTERVAL);
    }
    else if ( 1 == timerCounter )
    {
      deeLib.digOn(LED_1);
      blinkFor(LED_2, TIMER_INTERVAL);
    }
    else if ( 2 == timerCounter )
    {
      deeLib.digOn(LED_2);
      blinkFor(LED_3, TIMER_INTERVAL);
    }
    else if ( 3 == timerCounter )
    {
      deeLib.digOn(LED_3);
      blinkFor(LED_4, TIMER_INTERVAL);
    }
    else if ( 4 == timerCounter )
    {
      deeLib.digOn(LED_4);
      blinkFor(LED_5, TIMER_INTERVAL);
    }
    else if ( TIMER_MAX == timerCounter )
    {
      deeLib.digOn(LED_5);
      isTimerFinished = true;
    }

    timerCounter++;
  }
  else
  {
    // check the reset button
    if( deeLib.isButtonPressed(BUTTON) )
    {
      deeLib.digOff(LED_1);
      deeLib.digOff(LED_2);
      deeLib.digOff(LED_3);
      deeLib.digOff(LED_4);
      deeLib.digOff(LED_5);

      resetTimer();
    }
  }
}





/**
 * Starts the timer.
 */
void startTimer()
{
  timerCounter = TIMER_ZERO;
  timerState = TIMER_STATE_ON;
  isTimerFinished = false;
  delay(1000);
}


/**
 * Resets the timer.
 */
void resetTimer()
{
  timerCounter = TIMER_ZERO;
  timerState = TIMER_STATE_OFF;
  isTimerFinished = true;
  delay(1000);
}


/**
 * Let all LED blink one time.
 */
void testLeds()
{
  deeLib.blinkOne(LED_1);
  deeLib.blinkOne(LED_2);
  deeLib.blinkOne(LED_3);
  deeLib.blinkOne(LED_4);
  deeLib.blinkOne(LED_5);
}


/**
 * Let a LED blink for the given interval in seconds.
 * 
 * @param led The pin port of the led
 * @param seconds The blink duration
 */
int blinkFor(int led, int seconds)
{
  for( int i = 0; i < seconds; i++ )
  {
    deeLib.blinkOne(led);
    delay(500);
  }

  return 0;
}








