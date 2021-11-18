#ifndef SENSUALI_DI_PARCHEGGIO_POTENTIOMETER_H
#define SENSUALI_DI_PARCHEGGIO_POTENTIOMETER_H

#include "HwComponent.h"


class Potentiometer : public HwComponent {
public:
    explicit Potentiometer(char pin);

    int value();
};

#endif //SENSUALI_DI_PARCHEGGIO_POTENTIOMETER_H
