#include <Arduino.h>
#include "Sonar.h"

Sonar::Sonar(char trig_pin, char echo_pin) : HwComponent(trig_pin) {
    this -> echo_pin = echo_pin;
}

int Sonar::distance() {
    unsigned long duration;
    digitalWrite(this -> pin(), LOW);
    digitalWrite(this -> pin(), HIGH);
    delayMicroseconds(DELTA_SONAR_ON);
    digitalWrite(this -> pin(), LOW);
    duration = pulseIn(this -> echo_pin, HIGH); //Reads the echoPin, returns the sound wave travel time in microseconds
    Serial.println(duration);
    return int(double(duration)*0.034)/2;               //Calculating the distance
}