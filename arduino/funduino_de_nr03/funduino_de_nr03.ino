/**
 * file: funduino_de_nr03
 * date; 05.08.2016 20:38 Uhr
 *
 * <h1>Nr.03 Licht und Ton</h1>
 *
 * Sketch Nr.3: Gleichzeitiges Licht- und Tonsignal
 *
 * Aufgabe: Eine LED und ein Piezo-Lautsprecher sollen kontinuierlich blinken bzw. piepen.
 *
 * Material: Arduino / eine LED / Ein Widerstand mit 200 Ohm / Ein Piezo-Speaker / Breadboard / Kabel
 *
 * @autor deeagle <code@deeagle.de>
 *
 */
 

int LED = 4;
int PIEP = 5;


/**
 * Runs only once 
 */
void setup()
{
  pinMode(LED, OUTPUT);
  pinMode(PIEP, OUTPUT);
}


/**
 * The main loop which will be used after init {@see this#setup()}
 */
void loop()
{
  digOn(LED);
  digOn(PIEP);
  setDelay(1000);
  digOff(LED);
  digOff(PIEP);
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
