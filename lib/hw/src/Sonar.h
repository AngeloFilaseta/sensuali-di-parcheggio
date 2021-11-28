#ifndef SENSUALI_DI_PARCHEGGIO_SONAR_H
#define SENSUALI_DI_PARCHEGGIO_SONAR_H

#define DELTA_SONAR_ON 10   //delta time (milliseconds) that the sonar will stay on

#include "HwComponent.h"

class Sonar : public HwComponent {
    public:

        Sonar(char trig_pin, char echo_pin);

        //returns the distance (cm) detected by the sonar
        int distance();

    private:
        char echo_pin;
};

#endif //SENSUALI_DI_PARCHEGGIO_SONAR_H
