int enablePin = 13;
int registerSelect = 6;
int data7 = 8;
int data6 = 9;
int data5 = 10;
int data4 = 11;





void writeData(bool d7, bool d6, bool d5, bool d4, bool rs)
{
    //setup the data before enable the enable pin
    digitalWrite(registerSelect, rs);
    digitalWrite(data7, d7);
    digitalWrite(data6, d6);
    digitalWrite(data5, d5);
    digitalWrite(data4, d4);


    // enable and disable the pin for writing into lcd memory
    digitalWrite(enablePin, HIGH);
    delay(100); // the mininum "wait" for lcd memory to write the read
    digitalWrite(enablePin, LOW);
}


void setupPins()
{
    pinMode(enablePin, OUTPUT);
    pinMode(data7, OUTPUT);
    pinMode(data6, OUTPUT);
    pinMode(data5, OUTPUT);
    pinMode(data4, OUTPUT);
    pinMode(registerSelect, OUTPUT);

    digitalWrite(enablePin, LOW);
    digitalWrite(registerSelect, LOW);

    // set 4bit mode 1 line
    writeData(0, 0, 1 ,0, false); 

    // display no curosr
    writeData(0, 0 ,0 ,0, false); 
    writeData(1, 1 ,0 ,0, false);

}

// clear display
void clearScreen()
{
    writeData(0, 0 ,0 ,0, false); 
    writeData(0, 0 ,0 ,1, false);
}

// setting the posistion back to zero
// calling this function in the loop if you want to redraw text
void ReturnHome()
{
    writeData(0, 0 ,0 ,0, false); 
    writeData(0, 0 ,1 ,0, false);
}

void writeLetter(char letter)
{
    //writeData(0, 1 ,0 ,0, true); // print latter h
   // writeData(1, 0 ,0 ,0, true);
    writeData(letter >> 7, (letter >> 6) & 1, (letter >> 5) & 1, (letter >> 4) & 1, true );
    writeData((letter >> 3) & 1, (letter >> 2) & 1, (letter >> 1) & 1, letter & 1, true );
}

void writeString(char * str)
{
    int len = strlen(str);
    if(len > 16) // max length of the screen
        len = 16;

    for(int i = 0; i < len; i++)
        writeLetter(str[i]);
}


void setup()
{
    setupPins();
}


void loop()
{

    clearScreen();
    ReturnHome();
    writeString("Hello World");

    delay(100);

    clearScreen();
    ReturnHome();
    writeString("Open for work :)");



}


