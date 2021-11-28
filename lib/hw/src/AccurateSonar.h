#ifndef SENSUALI_DI_PARCHEGGIO_ACCURATESONAR_H
#define SENSUALI_DI_PARCHEGGIO_ACCURATESONAR_H

#include "HwComponent.h"

#define REP 20 // Number of readings done for a single distance() call
#define SOUND_SPEED 331300 + 606 * 20 // 20 is the temperature of the air in C°.

class AccurateSonar : public HwComponent {
public:

    AccurateSonar(char trigPin, char echoPin);

    //returns the distance (mm) detected by the sonar
    int distance();

private:

    char echoPin;

    unsigned long singleRead();

};

#endif //SENSUALI_DI_PARCHEGGIO_ACCURATESONAR_H
