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

int LED = 13;

/**
 * Runs only once 
 */
void setup()
{
  pinMode(LED, OUTPUT);
}


/**
 * The main loop which will be used after init {@see this#setup()}
 */
void loop()
{
  dot();
  dot();
  dot();
  dash();
  dash();
  dash();
  dot();
  dot();
  dot();
  delay(3000);
}

void dot()
{
  digOn(LED);
  delay(250);
  digOff(LED);
  delay(250);
}

void dash()
{
  digOn(LED);
  delay(1000);
  digOff(LED);
  delay(250);
}

/**
 * Set the power to {@code HIGH} on given port.
 */
void digOn(int outputPort)
{
  digitalWrite(outputPort, HIGH);
}


/**
 * Set the power to {@code LOW} on given port.
 */
void digOff(int outputPort)
{
  digitalWrite(outputPort, LOW);
}

