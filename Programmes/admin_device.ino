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

///
String YearS, MinuteS, DayOfMonthS, MonthS, HourS, GeneratedPass;
int Year, Minute, DayOfMonth, Month, Hour;


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
  
}


void loop()
{
  if (irrecv.decode(&results))
  {
    irrecv.resume();
    if(results.value==16582903){passGenerate();}
  }
}
//
void passGenerate()
{
  clock.getTime();
  YearS=String(clock.year, DEC);
  MinuteS=String(clock.minute, DEC);
  DayOfMonthS=String(clock.dayOfMonth, DEC);
  MonthS=String(clock.month, DEC);
  HourS=String(clock.hour, DEC);
  
  ///2 char ajust///
  if(MinuteS.length()<2) {MinuteS="0"+MinuteS;}
  if(DayOfMonthS.length()<2) {DayOfMonthS="0"+DayOfMonthS;}
  if(MonthS.length()<2) {MonthS="0"+MonthS;}
  if(HourS.length()<2) {HourS="0"+HourS;}
  //////////////////
  
  GeneratedPass=YearS+" "+MinuteS+" "+DayOfMonthS+" "+MonthS+" "+HourS;
  lcd.clear();
  lcd.print(GeneratedPass);
  //DEBUGSerial.print("Generating code : "+GeneratedPass+"\n");
}
