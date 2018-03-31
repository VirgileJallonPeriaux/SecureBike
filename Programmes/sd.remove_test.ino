///Bibliothèques///
//IR Receiver + Remote//
#include <IRremote.h>
int RECV_PIN = 2; 
IRrecv irrecv(RECV_PIN);
decode_results results;
////////////////////////
#include <ChainableLED.h>
ChainableLED leds(7, 8, 1);

#include <Wire.h>
#include "rgb_lcd.h"
rgb_lcd lcd;

#include "DS1307.h"
DS1307 clock;

#include <SPI.h>
#include <SD.h>

File myFile;
String TPPass;
int Port;

void setup()
{
  Serial.begin(9600);
  
  irrecv.enableIRIn();
  leds.init();
  lcd.begin(16, 2);
  
  /////clock/////
  clock.begin();
  clock.fillByYMD(2016,1,14);
  clock.fillByHMS(20,01,0);
  clock.fillDayOfWeek(THU);
  clock.setTime();

  if (!SD.begin(4))
  {
    Serial.println("initialization failed!");
    return;
  }
}


void loop()
{
  if (irrecv.decode(&results))
  {
    irrecv.resume();
    if(results.value==16582903){
      lcd.clear(); lcd.print("Creating file");
      TPPass="test";
      SD.remove(TPPass+".txt");
      }
  }
}
