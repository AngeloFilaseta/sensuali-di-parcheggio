#include <Arduino.h>
#include <hw/Potentiometer.h>

#define POTENTIOMETER_PIN A0

Potentiometer* potentiometer = new Potentiometer(POTENTIOMETER_PIN);

void setup() {
    Serial.begin(9600);
}

void loop() {
    int value = potentiometer->value();
    Serial.println(value);
}