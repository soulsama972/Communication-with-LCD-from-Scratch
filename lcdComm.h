
#pragma once
#include<Arduino.h>




class LCD
{
public:
    /*
    \param d7 the pin number connected to the lcd data7
    \param d6 the pin number connected to the lcd data6
    \param d5 the pin number connected to the lcd data5
    \param d4 the pin number connected to the lcd data4
    \param en the pin number connected to the lcd enable pin
    \param rs the pin number connected to the lcd resgister selectet
    */
    void setupPins(int d7, int d6, int d5, int d4, int en, int rs);
    

    /*
        write to letter to the least postion in the lcd
    */
    void writeLetter(char letter);
     /*
        write to string to the least postion in the lcd
    */   
    void writeString(char * str);

    // setting the posistion back to zero
    // calling this function in the loop if you want to redraw text
    void ReturnHome();
    
    // clear display
    void clearScreen();

private:
    void writeData(bool d7, bool d6, bool d5, bool d4, bool rs);
    struct Data
    {
        uint32_t d7 : 4;
        uint32_t d6 : 4;
        uint32_t d5 : 4;
        uint32_t d4 : 4;
        uint32_t rs : 4;
        uint32_t en : 4;
        
    }data;
    
};