
/**
 * file: funduion_de_SOS
 * date: 06.08.2016 13:21 Uhr
 *
 * <h1>SOS morse signal LED</h1>
 *
 * For more information {@see https://www.arduino.cc/en/Hacking/LibraryTutorial}.
 * 
 * @autor deeagle <code@deeagle.de>
 *
 */
 
 #include "Morse.h"

int LED = 13;
Morse morse(LED);

/**
 * Runs only once 
 */
void setup()
{}


/**
 * The main loop which will be used after init {@see this#setup()}
 */
void loop()
{
  morse.dot();
  morse.dot();
  morse.dot();
  morse.dash();
  morse.dash();
  morse.dash();
  morse.dot();
  morse.dot();
  morse.dot();
  delay(3000);
}



