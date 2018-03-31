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
String TPPass, YearS, MinuteS, DayOfMonthS, MonthS, HourS;
int TPYear, TPMinute, TPDayOfMonth, TPMonth, TPHour, Year, Minute, DayOfMonth, Month, Hour, Var1, Var2, Var3, Var4, Var5, Var6, Var7, Var8, TPCodeTotal, CodeTotal;


void setup()
{
  Serial.begin(9600);
  
  irrecv.enableIRIn();
  leds.init();
  lcd.begin(16, 2);
  
  /////clock/////
  clock.begin();
  clock.fillByYMD(2016,1,19);
  clock.fillByHMS(20,01,0);
  //clock.fillDayOfWeek(SUN);
  clock.setTime();
  
}


void loop()
{
  if (irrecv.decode(&results))
  {
    irrecv.resume();
    if(results.value==16582903){passUncode("1611210121");}
  }
}


void passUncode(String TPPass)
{
  Var1=0;
  Var2=0;
  Var3=0;
  Var4=0;
  Var5=0;
  Var6=0;
  Var7=0;
  Var8=0;
  ///RTC current values///
  clock.getTime();
  YearS=String(clock.year, DEC);
  MinuteS=String(clock.minute, DEC);
  DayOfMonthS=String(clock.dayOfMonth, DEC);
  MonthS=String(clock.month, DEC);
  HourS=String(clock.hour, DEC);
  ///INT=String.toInt() because of a bug
  Year=YearS.toInt();
  Minute=MinuteS.toInt();
  DayOfMonth=DayOfMonthS.toInt();
  Month=MonthS.toInt();
  Hour=HourS.toInt();
  ////////////////////////
  TPYear=TPPass.substring(0,2).toInt();
  TPMinute=TPPass.substring(2,4).toInt();
  TPDayOfMonth=TPPass.substring(4,6).toInt();
  TPMonth=TPPass.substring(6,8).toInt();
  TPHour=TPPass.substring(8,10).toInt();

  Serial.print(String(TPYear)+String(TPMonth)+String(TPDayOfMonth)+String(TPHour)+String(TPMinute)+"\n");
  Serial.print(String(Year)+String(Month)+String(DayOfMonth)+String(Hour)+String(Minute)+"\n");

  if(TPMonth<9){Var1=10000000;}
  if(TPDayOfMonth<9){Var2=100000;}
  if(TPHour<9){Var3=1000;}
  if(TPMinute<9){Var4=10;}

  if(Month<9){Var5=10000000;}
  if(DayOfMonth<9){Var6=100000;}
  if(Hour<9){Var7=1000;}
  if(Minute<9){Var8=10;}
  
  TPCodeTotal=TPYear+TPMonth+TPDayOfMonth+TPHour+TPMinute+Var1+Var2+Var3+Var4;
  CodeTotal=Year+Month+DayOfMonth+Hour+Minute+Var5+Var6+Var7+Var8;
  Serial.print(String(TPCodeTotal)+"//"+String(CodeTotal));
  //////////////////////////////////////////////
//  if(TPYear<=Year)
//  {
//    if(TPMonth<=Month)
//    {
//      if(TPDayOfMonth<=DayOfMonth & TPDayOfMonth+1>=DayOfMonth)
//      {
//        if(TPHour<=Hour)
//        {
//          if(TPMinute<=Minute)
//          {
//            Serial.print("Code valide !");
//          }
//          else
//          {
//            Serial.print("Code invalide ! (minute)");
//          }
//        }
//        else
//        {
//          Serial.print("Code invalide ! (hour)");
//        }
//      }
//      else
//      {
//        Serial.print("Code invalide ! (dom)");
//      }
//    }
//    else
//    {
//      Serial.print("Code invalide ! (month)");
//    }
//  }
//  else
//  {
//    Serial.print("Code invalide ! (year)");
//  }

}

