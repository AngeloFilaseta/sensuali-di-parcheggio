#include "HwComponent.h"

//constructor: pin(pin number where component is wired)
HwComponent::HwComponent(char pin){
    this -> pin_ = pin;
}

//returns the pin which this hardware component is wired to
char HwComponent::pin() {
    return this -> pin_;
}
