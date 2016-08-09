/**
 * file: funduino_de_nr02
 * date; 05.08.2016 20:10 Uhr
 *
 * <h1>Nr.02 Wechselblinker</h1>
 *
 * Sketch Nr.2: Der Wechselblinker
 *
 * Aufgabe: Zwei Leuchtdioden sollen abwechselnd blinken.
 *
 * Material: Arduino / zwei Leuchtdioden (blau) / Zwei Widerstände mit 100 Ohm / Breadboard / Kabel
 *
 * @autor deeagle <code@deeagle.de>
 *
 */

/**
 * Runs only once 
 */
void setup()
{
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
}


/**
 * The main loop which will be used after init {@see this#setup()}
 */
void loop()
{
  digOn(7);
  setDelay(1000);
  digOff(7);
  setDelay(1000);
  digOn(8);
  setDelay(1000);
  digOff(8);
  setDelay(1000);
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


/**
 * Waits a delay.
 * <p>
 * The given delay must be between <strong>0</strong> and <strong>2000</strong>
 */
void setDelay(int newDelay)
{
  if( 0 < newDelay && 2000 >= newDelay )
  {
    delay(newDelay);
  }
}
