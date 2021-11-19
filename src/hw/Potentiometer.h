#ifndef SENSUALI_DI_PARCHEGGIO_POTENTIOMETER_H
#define SENSUALI_DI_PARCHEGGIO_POTENTIOMETER_H

#include "HwComponent.h"

#define MAX_POTENTIOMETER_VALUE 1024

class Potentiometer : public HwComponent {
public:
    explicit Potentiometer(char pin);

    int value();
};

#endif //SENSUALI_DI_PARCHEGGIO_POTENTIOMETER_H
