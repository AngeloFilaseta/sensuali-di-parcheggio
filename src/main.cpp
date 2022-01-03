#include "Arduino.h"
#include "SoftwareSerial.h"
#include "DFRobotDFPlayerMini.h"

SoftwareSerial mySoftwareSerial(10, 11);
DFRobotDFPlayerMini myDFPlayer;

void setup() {
  mySoftwareSerial.begin(9600);
  Serial.begin(9600);
  
  Serial.println();
  Serial.println(F("Sensuali di Parcheggio"));
  Serial.println(F("Booting up... (May take 3~5 seconds)"));
  
  if (!myDFPlayer.begin(mySoftwareSerial)) {
    Serial.println(F("Error during initialization."));
    while(true);
  }
  Serial.println(F("Sensuali di Parcheggio is now online."));
  
  myDFPlayer.volume(15);
  myDFPlayer.play(1);
}

void loop() {

}

