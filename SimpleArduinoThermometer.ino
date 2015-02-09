#include <SevSeg.h>
SevSeg sevseg; // Instantiate a seven segment object

int TMP35 = 5;
int valueTMP35 = 0;

unsigned long interval = 10000; // The time we need to wait
unsigned long previousMillis = millis();

void setup() {
  
  byte numDigits = 4;
  byte digitPins[] = {10, 11, 12, 13};
  byte segmentPins[] = {2, 3, 4, 5, 6, 7, 8, 9};
  sevseg.begin(COMMON_CATHODE, numDigits, digitPins, segmentPins);
  
  valueTMP35 = analogRead(TMP35);
}

void loop() {
    
    if((unsigned long)(millis() - previousMillis) >= interval) { 
      valueTMP35 = analogRead(TMP35);
      previousMillis = millis();
    }
    
    sevseg.setNumber(readTMP35(valueTMP35), 2); // Displays '3.141'
    sevseg.refreshDisplay();
    
}

float readTMP35(int analogValue) {
   float temperature = (5.0 * analogValue * 100) / 1024;
   return temperature;
}
