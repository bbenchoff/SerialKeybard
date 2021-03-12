#include <Wire.h>
#include <Adafruit_Keypad.h>
#include <Adafruit_Keypad_Ringbuffer.h>
#include <Adafruit_GFX.h>
#include "Adafruit_LEDBackpack.h"
#include "Adafruit_MCP23017.h"

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

Adafruit_MCP23017 mcp;


int value = NULL;

void setup()
{
  keypad.begin();
  alpha.begin(0x70);
}

void loop() 
{
  keypad.tick();

  KeypadLoop();
  delay(40);
}

void SetupSerial(void)
{
  /*  
  int mcpPins[] = {1,2,3,4,5,6,7,8,9,10,14,15};
  long baudValue[] = {115200,57600,19200,9600,2400,1200,300};
  char parityValue[] = {'N','E','O'};

  long baudRate;
  char parity;
  int stopBit = 1;
  
  mcp.begin();
  mcp.pinMode(1, INPUT);
  mcp.pinMode(2, INPUT);
  mcp.pinMode(3, INPUT);
  mcp.pinMode(4, INPUT);
  mcp.pinMode(5, INPUT);
  mcp.pinMode(6, INPUT);
  mcp.pinMode(7, INPUT);
  mcp.pinMode(8, INPUT);
  mcp.pinMode(9, INPUT);
  mcp.pinMode(10, INPUT);
  mcp.pinMode(14, INPUT);
  mcp.pinMode(15, INPUT);
  
  mcp.pullUp(1, HIGH);
  mcp.pullUp(2, HIGH);
  mcp.pullUp(3, HIGH);
  mcp.pullUp(4, HIGH);
  mcp.pullUp(5, HIGH);
  mcp.pullUp(6, HIGH);
  mcp.pullUp(7, HIGH);
  mcp.pullUp(8, HIGH);
  mcp.pullUp(9, HIGH);
  mcp.pullUp(10, HIGH);
  mcp.pullUp(14, HIGH);
  mcp.pullUp(15, HIGH);


  //read the baud rate dial
  for(int i = 0 ; i < 7 ; i++)
  {
    if(mcp.digitalRead(mcpPins[i]) == HIGH)
      baudRate = baudValue[i];
  }

  //read the parity
  for(int i = 7 ; i < 10 ; i++)
  {
    if(mcp.digitalRead(mcpPins[i]) == HIGH)
      parity = parityValue[(i-7)];
  }

  //read the stop bits
  if(mcp.digitalRead(14) == HIGH)
    stopBit = 1;
  else
    stopBit = 2;
    
  //put it all together
  if(stopBit == 1 && parity == 'N')
    Serial1.begin(baudRate, SERIAL_8N1);
  else if(stopBit == 1 && parity == 'E')
    Serial1.begin(baudRate, SERIAL_8E1);
  else if(stopBit == 1 && parity == 'O')
    Serial1.begin(baudRate, SERIAL_8O1);
  else if(stopBit == 2 && parity == 'N')
    Serial1.begin(baudRate, SERIAL_8N2);
  else if(stopBit == 2 && parity == 'E')
    Serial1.begin(baudRate, SERIAL_8E2);
  else if(stopBit == 2 && parity == 'O')
    Serial1.begin(baudRate, SERIAL_8O2);

  //comment the below lines out when you're done testing
  Serial.begin(9600);
  Serial.print("Baud: ");
  Serial.print(baudRate);
  Serial.print(" Parity: ");
  Serial.print(parity);
  Serial.print(" Stop: ");
  Serial.print(stopBit);
  Serial.print("  \n\r");
  */

  Serial1.begin(9600);
}

void TransmitValue(int value)
{
  SetupSerial();
  Serial1.print(char(value));

  //Serial1.end();
}

void KeypadLoop(void)
{
    char currentKey;  
  
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
}

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
