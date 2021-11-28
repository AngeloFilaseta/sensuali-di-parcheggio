#include "Potentiometer.h"
#include <Arduino.h>

Potentiometer::Potentiometer(char pin) : HwComponent(pin) { }

int Potentiometer::value() {
    return analogRead(this -> pin());
}