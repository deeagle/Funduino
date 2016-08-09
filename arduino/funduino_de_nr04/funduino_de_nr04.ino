/**
 * file: funduino_de_nr04
 * date: 05.08.2016 20:49 Uhr
 *
 * <h1>Nr.04 Pulsierende LED</h1>
 *
 * Sketch Nr.4: Eine LED pulsieren lassen
 *
 * Aufgabe: Eine LED soll pulsierend heller und dunkler werden. (Auch als engl. „faden“ bezeichnet)
 * 
 * Material: Arduino / eine LED (blau) / Ein Widerstand mit 100 Ohm / Breadboard / Kabel
 *
 * @autor deeagle <code@deeagle.de>
 *
 */

int LED = 9;
int BRIGHTNESS_MIN = 0;
int BRIGHTNESS_MAX = 255;
int BRIGHTNESS_STEP = 5;

int brightness = BRIGHTNESS_MIN;

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
  analogWrite(LED, brightness);
  brightness += BRIGHTNESS_STEP;
  
  delay(25);
  if( BRIGHTNESS_MIN >= brightness || BRIGHTNESS_MAX <= brightness )
  {
    BRIGHTNESS_STEP *= -1;
  }
}
