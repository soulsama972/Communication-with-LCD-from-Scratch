#include"lcdComm.h"



void LCD::setupPins(int d7, int d6, int d5, int d4, int en, int rs)
{
    data.d4 = d4;
    data.d5 = d5;
    data.d6 = d6;
    data.d7 = d7;
    data.rs = rs;
    data.en = en;

    pinMode(data.en, OUTPUT);
    pinMode(data.d7, OUTPUT);
    pinMode(data.d6, OUTPUT);
    pinMode(data.d5, OUTPUT);
    pinMode(data.d4, OUTPUT);
    pinMode(data.rs, OUTPUT);

    digitalWrite(data.en, LOW);
    digitalWrite(data.rs, LOW);

    // set 4bit mode 1 line
    writeData(0, 0, 1 ,0, false); 

    // display no curosr
    writeData(0, 0 ,0 ,0, false); 
    writeData(1, 1 ,0 ,0, false);
}


void LCD::ReturnHome()
{
    writeData(0, 0 ,0 ,0, false); 
    writeData(0, 0 ,1 ,0, false);
}

void LCD::clearScreen()
{
    writeData(0, 0 ,0 ,0, false); 
    writeData(0, 0 ,0 ,1, false);
}


void LCD::writeData(bool d7, bool d6, bool d5, bool d4, bool rs)
{
    //setup the data before enable the enable pin
    digitalWrite(data.rs, rs);
    digitalWrite(data.d7, d7);
    digitalWrite(data.d6, d6);
    digitalWrite(data.d5, d5);
    digitalWrite(data.d4, d4);


    // enable and disable the pin for writing into lcd memory
    digitalWrite(data.en, HIGH);
    delay(100); // the mininum "wait" for lcd memory to write the read
    digitalWrite(data.en, LOW);
}



void LCD::writeLetter(char letter)
{
    //writeData(0, 1 ,0 ,0, true); // print latter h
   // writeData(1, 0 ,0 ,0, true);
    writeData(letter >> 7, (letter >> 6) & 1, (letter >> 5) & 1, (letter >> 4) & 1, true );
    writeData((letter >> 3) & 1, (letter >> 2) & 1, (letter >> 1) & 1, letter & 1, true );
}

void LCD::writeString(char * str)
{
    int len = strlen(str);
    if(len > 16) // max length of the screen
        len = 16;

    for(int i = 0; i < len; i++)
        writeLetter(str[i]);
}