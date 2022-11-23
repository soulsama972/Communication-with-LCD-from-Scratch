
#include"lcdComm.h"


LCD lcd;

void setup()
{
    lcd.setupPins(8,9,10,11, 13, 6);
}


void loop()
{

    lcd.clearScreen();
    lcd.ReturnHome();
    lcd.writeString("Hello World");

    delay(100);

    lcd.clearScreen();
    lcd.ReturnHome();
    lcd.writeString("Open for work :)");



}


