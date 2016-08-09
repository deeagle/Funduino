/**
 * file: funduino_de_nr14
 * date: 09.08.2016 22:54 Uhr
 *
 * <h1>Nr.14 LCD Display</h1>
 *
 * Ein LCD Display per Arduino ansteuern
 *
 * @author deeagle <code@deeagle.de>
 */

#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup()
{
  lcd.begin(16, 2);
}

void loop()
{
  printHelloWorld();
}


/**
 * Example 1
 */
void printHelloWorld()
{
  lcd.setCursor(0, 0);
  lcd.print("hello world");
  lcd.setCursor(0, 1);
  lcd.print("Foo vs. Bar");
}

