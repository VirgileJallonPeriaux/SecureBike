#if 0
#include <SPI.h>
#include <PN532_SPI.h>
#include <PN532.h>
#include <NfcAdapter.h>

PN532_SPI pn532spi(SPI, 10);
NfcAdapter nfc = NfcAdapter(pn532spi);
#else

#include <Wire.h>
#include <PN532_I2C.h>
#include <PN532.h>
#include <NfcAdapter.h>

PN532_I2C pn532_i2c(Wire);
NfcAdapter nfc = NfcAdapter(pn532_i2c);
#endif

//#include <Wire.h>
//#include "rgb_lcd.h"
//rgb_lcd lcd;

String TagUidS, Tus1, Tus2, Tus3, Tus4, Tus5, Tus6, TagUidFinal;
void setup()
{
  Serial.begin(9600);
  nfc.begin();
 // lcd.begin(16, 2);
}

void loop()
{
  Serial.println("\nScan a NFC tag\n");

  if (nfc.tagPresent())
  {
    NfcTag tag = nfc.read();
    TagUidS=tag.getUidString();
    //Serial.print("Before:"+TagUidS);
//    TagUidS.replace("A", "");
//    TagUidS.replace("B", "");
//    TagUidS.replace("C", "");
//    TagUidS.replace("D", "");
//    TagUidS.replace("E", "");
//    TagUidS.replace("F", "");
    TagUidS.replace(" ", "");
    //Serial.print("After:"+TagUidS);
    Tus1=TagUidS.substring(0,1);
    Tus2=TagUidS.substring(1,2);
    Tus3=TagUidS.substring(2,3);
    Tus4=TagUidS.substring(3,4);
    Tus5=TagUidS.substring(4,5);
    Tus6=TagUidS.substring(5,6);
    TagUidFinal=Tus1+Tus2+Tus3+Tus4+Tus5;
    Serial.print(Tus1+Tus2+Tus3+Tus4+Tus5);
    
  }
  delay(3000);
}
