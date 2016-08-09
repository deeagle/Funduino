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

const int MAX_ROW_SIZE = 16;

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);


void setup()
{
  lcd.begin(16, 2);
}


void loop()
{
  //printHelloWorld();
  //printSwitchingRows();
  //runningArrows();
  runningArrowsPlusPercent();

  lcd.clear();
  delay(1000);
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


void printSwitchingRows()
{
  lcd.setCursor(0, 0);
  lcd.print("Oben");
  delay (2000);
  lcd.clear();
  lcd.setCursor(5, 1);
  lcd.print("unten");
  delay (2000);
  lcd.clear();
}


void runningArrows()
{
  String head = ">";
  String tail = "-";
  String arrow = "";

  lcd.setCursor(0, 0);

  for( int i = 0; i < MAX_ROW_SIZE; i++ )
  {
    arrow += tail;

    lcd.clear();
    lcd.print(arrow + head);
    delay(500);
  }  
}


void runningArrowsPlusPercent()
{
  String head = ">";
  String tail = "-";
  String arrow = "";
  int percent = 0;

  for( int i = 0; i < MAX_ROW_SIZE; i++ )
  {
    arrow += tail;
    percent = 100 / MAX_ROW_SIZE * (i + 1);

    lcd.clear();
    // 1st row
    lcd.setCursor(0, 0);
    lcd.print(arrow + head);

    // 2nd row
    lcd.setCursor(7, 1);
    lcd.print(percent);
    lcd.print("%");  

    delay(500);
  }  
}


