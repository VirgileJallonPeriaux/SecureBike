#include <IRremote.h>
int RECV_PIN = 2; 
IRrecv irrecv(RECV_PIN);
decode_results results;

#include <ChainableLED.h>
ChainableLED leds(7, 8, 1);

#include <Wire.h>
#include "rgb_lcd.h"
rgb_lcd lcd;

#include <SPI.h>
#include <SD.h>
File myFile;

void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn();

  leds.init();

  lcd.begin(16, 2);
}

void loop()
{
  if (irrecv.decode(&results))
  {
    //Serial.print(results.value); Serial.print("\n");
    irrecv.resume();
    if(results.value==16582903){lcd.clear(); leds.setColorRGB(0,255,0,0); lcd.setRGB(255,0,0); lcd.print("Red Enabled");}
    if(results.value==16615543){lcd.clear(); leds.setColorRGB(0,0,255,0); lcd.setRGB(0,255,0); lcd.print("Green Enabled");}
    if(results.value==16599223){lcd.clear(); leds.setColorRGB(0,0,0,255); lcd.setRGB(0,0,255); lcd.print("Blue Enabled");}
    if(results.value==16617583)
    {
      for(int K=0; K<5; K++)
      {
      delay(150);
      leds.setColorRGB(0,255,93,0);
      delay(150);
      leds.setColorRGB(0,0,0,0);
      }
    }
    
  }
      
}
