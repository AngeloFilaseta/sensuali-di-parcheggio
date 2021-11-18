#include <Arduino.h>
#include <hw/Potentiometer.h>
#include <hw/Sonar.h>

#define POTENTIOMETER_PIN A0

#define SONAR_TRIG_PIN 5
#define SONAR_ECHO_PIN 4

Potentiometer* potentiometer = new Potentiometer(POTENTIOMETER_PIN);
Sonar* sonar = new Sonar(SONAR_TRIG_PIN, SONAR_ECHO_PIN);

void setup() {
    pinMode(SONAR_TRIG_PIN, OUTPUT);
    pinMode(SONAR_ECHO_PIN, INPUT);
    Serial.begin(9600);
}

void loop() {
    Serial.println((String) "Potentiometer: " + potentiometer->value());
    Serial.println((String) "Sonar: " + sonar->distance());
    delay(5000);
}