#include "HwComponent.h"

HwComponent::HwComponent(char pin){
    this -> pin_ = pin;
}

char HwComponent::pin() const {
    return this -> pin_;
}
