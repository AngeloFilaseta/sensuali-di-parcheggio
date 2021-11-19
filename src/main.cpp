#include <Arduino.h>
#include <SoftwareSerial.h>

#include <hw/Potentiometer.h>
#include <hw/Sonar.h>
#include "../.pio/libdeps/esp12e/DFPlayerMini_Fast/src/DFPlayerMini_Fast.h"

//PINS
#define POTENTIOMETER_PIN A0

#define SONAR_TRIG_PIN 5
#define SONAR_ECHO_PIN 4

#define RX_PIN 10
#define TX_PIN 11

//CONSTANTS
#define MAX_VOLUME 30

SoftwareSerial mp3Serial(RX_PIN, TX_PIN); // RX, TX
DFPlayerMini_Fast mp3;

Potentiometer* potentiometer = new Potentiometer(POTENTIOMETER_PIN);
Sonar* sonar = new Sonar(SONAR_TRIG_PIN, SONAR_ECHO_PIN);

void setup() {
    pinMode(SONAR_TRIG_PIN, OUTPUT);
    pinMode(SONAR_ECHO_PIN, INPUT);
    Serial.begin(9600);
    mp3Serial.begin(9600);
    mp3.begin(mp3Serial, true);
    mp3.volume(30);
    mp3.loop(1);
}

void setVolume(){
    int newVolume = (int)map(potentiometer->value(), 0, MAX_POTENTIOMETER_VALUE, 0, MAX_VOLUME);
    mp3.volume(newVolume);
}

void playAudio(){
    if(!mp3.isPlaying()){
        int distance = sonar->distance();
        int trackToPlay;
        if(distance > 10) {
            trackToPlay = 1;
        } else {
            trackToPlay = 2;
        }
        mp3.play(trackToPlay);
    }
}

void loop() {
    //setVolume();
    //playAudio();
    //Serial.println((String)"Potentiometer: " + potentiometer->value());
    //Serial.println((String)"Sonar: " + sonar->distance());
    //delay(1000);
}


