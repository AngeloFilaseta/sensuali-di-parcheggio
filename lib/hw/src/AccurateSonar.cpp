#include <Arduino.h>
#include "AccurateSonar.h"

AccurateSonar::AccurateSonar(char trigPin, char echoPin) : HwComponent(trigPin) {
    _echoPin = echoPin;
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
}

int AccurateSonar::distance() {
    int distance[REP];
    long sum = 0;
    char elements = REP;
    for(int i = 0; i < REP; i++) {
        distance[i] = (SOUND_SPEED * (int) singleRead()) / 20000;
        if(distance[i] >= 0) {
            sum += distance[i];
        } else {
            elements--;
        }
    }
    return sum / elements;
}

unsigned long AccurateSonar::singleRead() {
    digitalWrite(pin(), LOW);
    delayMicroseconds(3);
    digitalWrite(pin(), HIGH);
    delayMicroseconds(12);
    return(pulseIn(_echoPin, HIGH, 35000)); // microseconds of (total) sound travel
}
