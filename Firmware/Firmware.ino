#include <Wire.h>
#include <Adafruit_Keypad.h>
#include <Adafruit_Keypad_Ringbuffer.h>
#include <Adafruit_GFX.h>
#include "Adafruit_LEDBackpack.h"

const byte ROWS = 4;
const byte COLS = 5;

char keys[ROWS][COLS] = {
  {'C','D','E','F','K'},
  {'8','9','A','B','T'},
  {'4','5','6','7',   },
  {'0','1','2','3',   }
};
byte rowPins[ROWS] = {6,10,11,12};
byte colPins[COLS] = {18,17,16,15,14};

Adafruit_AlphaNum4 alpha = Adafruit_AlphaNum4();
Adafruit_Keypad keypad = Adafruit_Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

int value = NULL;

void WriteToDisplay(int value)
{

  
  if(value == NULL)
  {
    alpha.writeDigitAscii(0, 0xFF);
    alpha.writeDigitAscii(1, 0xFF);
  }
  else
  {
        String hexString = String(value, HEX);
        hexString.toUpperCase();
        alpha.writeDigitAscii(0, hexString[0]);
        if(hexString[1] == NULL)
        {
          alpha.writeDigitAscii(1, hexString[0]);
          alpha.writeDigitAscii(0, '0');
        }
        else
        {
          alpha.writeDigitAscii(0, hexString[0]);
          alpha.writeDigitAscii(1, hexString[1]);
        }
  }
  alpha.writeDisplay();
}

void TransmitValue(int value)
{
  Serial1.print(char(value));
}
void setup()
{
  Serial1.begin(9600);
  keypad.begin();
  alpha.begin(0x70);
}

void loop() 
{

  char currentKey;

  
  keypad.tick();

  /*
  for(int i = 0 ; i < 255 ; i++)
  {
    WriteToDisplay(i);
    delay(50);
  }
  */


  while(keypad.available())
  {
    keypadEvent e = keypad.read();
    if(e.bit.EVENT == KEY_JUST_PRESSED) 
    {
      currentKey = (char)e.bit.KEY;
    }

    if(value == NULL)
    {
      switch(currentKey)
      {
        case '0':
          value = 0;
        break;
        case '1':
          value = 1;
        break;
        case '2':
          value = 2;
        break;
        case '3':
          value = 3;
        break;
        case '4':
          value = 4;
        break;
        case '5':
          value = 5;
        break;
        case '6':
          value = 6;
        break;
        case '7':
          value = 7;
        break;
        case '8':
          value = 8;
        break;
        case '9':
          value = 9;
        break;
        case 'A':
          value = 10;
        break;
        case 'B':
          value = 11;
        break;
        case 'C':
          value = 12;
        break;
        case 'D':
          value = 13;
        break;
        case 'E':
          value = 14;
        break;
        case 'F':
          value = 15;
        break;
      }
    }
    else
    {
      switch(currentKey)
      {
        case '0':
          value = value * 16;
        break;
        case '1':
          value = value * 16 + 1;
        break;
        case '2':
          value = value * 16 + 2;
        break;
        case '3':
          value = value * 16 + 3;
        break;
        case '4':
          value = value * 16 + 4;
        break;
        case '5':
          value = value * 16 + 5;
        break;
        case '6':
          value = value * 16 + 6;
        break;
        case '7':
          value = value * 16 + 7;
        break;
        case '8':
          value = value * 16 + 8;
        break;
        case '9':
          value = value * 16 + 9;
        break;
        case 'A':
          value = value * 16 + 10;
        break;
        case 'B':
          value = value * 16 + 11;
        break;
        case 'C':
          value = value * 16 + 12;
        break;
        case 'D':
          value = value * 16 + 13;
        break;
        case 'E':
          value = value * 16 + 14;
        break;
        case 'F':
          value = value * 16 + 15;
        break;
        case 'K':
          value = NULL;
        break;
        case 'T':
          TransmitValue(value);
          value = NULL;
        break;
         
        }
      }

      WriteToDisplay(value);
    }
    delay(40);
}
