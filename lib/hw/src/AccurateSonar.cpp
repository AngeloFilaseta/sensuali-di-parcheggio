#include <Arduino.h>
#include "AccurateSonar.h"

AccurateSonar::AccurateSonar(char trigPin, char echoPin) : HwComponent(trigPin) {
    this -> echoPin = echoPin;
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
}

int AccurateSonar::distance() {
    long unsigned distance[REP];
    int sum = 0;
    for(int i = 0; i < REP; i++){
        distance[i] = ((SOUND_SPEED/100) * singleRead()) /20000;
        sum += distance[i];
    }
    return (sum/REP)/100;
}

unsigned long AccurateSonar::singleRead() {
    digitalWrite(pin(), LOW);
    delayMicroseconds(3);
    digitalWrite(pin(), HIGH);
    delayMicroseconds(12);
    return(pulseIn(this -> echoPin, HIGH, 35000)); // microseconds of (total) sound travel
}
