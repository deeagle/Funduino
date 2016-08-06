/** 
 * file: funduino_de_nr01 
 * date: 05.08.2016 15:30 Uhr
 * 
 * <h1>Nr.01 Blinkende LED</h1>
 * 
 * Sketch Nr.1: Eine blinkende LED
 * 
 * Aufgabe: Eine Leuchtdiode soll blinken.
 * 
 * Material:
 * 
 * Nur das Mikrocontrollerboard mit dem USB-Kabel!
 * 
 * Auf dem Arduino ist an Pin 13 bereits eine LED eingebaut (für Testzwecke). Häufig blinkt diese Lampe schon, wenn man ein neues Arduino-Board anschließt, da das Blink-Programm zum Testen des Boards je nach Hersteller bereits vorab installiert ist. Wir werden dieses Blinken jetzt selbst programmieren.  * 
 * 
 * @autor deeagle <code@deeagle.de>
 * 
 */

/**
 * Runs only once 
 */
void setup()
{
  pinMode(13, OUTPUT);
}


/**
 * The main loop which will be used after init {@see this#setup()}
 */
void loop()
{
  digOn(13);
  setDelay(1000);
  digOff(13);
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
