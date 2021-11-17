#ifndef SENSUALI_DI_PARCHEGGIO_POTENTIOMETER_H
#define SENSUALI_DI_PARCHEGGIO_POTENTIOMETER_H

#include "HwComponent.h"

#define DELTA_POTENTIOMETER_TIME 128    //the delta to check when potentiometer value is changed

class Potentiometer : public HwComponent {
public:
    Potentiometer(char pin);

    int value();
};

#endif //SENSUALI_DI_PARCHEGGIO_POTENTIOMETER_H
