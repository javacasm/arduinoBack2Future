#include "LedControl.h"  // puede controlar MAX72XX

/*
 Conectamos 
 pin 7 a DataIn 
 pin 6 a CLK 
 pin 5 a LOAD 
 We have only a single MAX72XX.
 */
#define pinDataIn 7
#define pinCLK 6
#define pinLoad 5
#define nChips 1
 
LedControl lc=LedControl(pinDataIn,pinCLK,pinLoad,nChips);

// wait between upddates
unsigned long delaytime=100;

void setup() {
  lc.shutdown(0,false); // wakeup chip
  lc.setIntensity(0,8); // medium bright
  lc.clearDisplay(0);   // clear
}


/*
 This method will display the characters for the
 word "Arduino" one after the other on digit 0. 
 */
// The 0 digit is at the rightest 
void writeArduinoOn7Segment() {
  lc.setChar(0,7,'a',false);
  delay(delaytime/5);
  lc.setRow(0,6,0x05);
  delay(delaytime/5);
  lc.setChar(0,5,'d',false);
  delay(delaytime/5);
  lc.setRow(0,4,0x1c);
  delay(delaytime/5);
  lc.setRow(0,3,B00010000);
  delay(delaytime/5);  
  lc.setRow(0,2,0x15);
  delay(delaytime/5);
  lc.setRow(0,1,0x1D);
  delay(delaytime*10);
  lc.clearDisplay(0);
  delay(delaytime);
} 

/*
  This method will scroll all the hexa-decimal
 numbers and letters on the display. You will need at least
 four 7-Segment digits. otherwise it won't really look that good.
 */
void scrollDigits() {
  for(int i=0;i<13;i++) {
    for(int j=0;j<8;j++)
    {   
      lc.setDigit(0,7-j,i+j,false);

    }
    delay(delaytime);    
  }
  lc.clearDisplay(0);
  delay(delaytime);
}

void loop() { 
  writeArduinoOn7Segment();
  scrollDigits();
}
