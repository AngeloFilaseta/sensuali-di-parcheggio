#ifndef SENSUALI_DI_PARCHEGGIO_ACCURATESONAR_H
#define SENSUALI_DI_PARCHEGGIO_ACCURATESONAR_H

#include "HwComponent.h"

#define REP 20 // Number of readings done for a single distance() call
#define SOUND_SPEED 66381 // 20 is the temperature of the air in C°.

/**
 * @brief Sonar class that executes serveral reads and return an average value.
 */
class AccurateSonar : public HwComponent {
public:

    /**
     * @brief Construct a new Accurate Sonar object.
     * 
     * @param trigPin the trigger pin.
     * @param echoPin the echo pin.
     */
    AccurateSonar(char trigPin, char echoPin);

    /**
     * @brief returns the distance (mm) detected by the Sonar.
     */
    int distance();

private:

    char _echoPin;

    /**
     * @brief The single read executed by the Sonar.
     * 
     * @return unsigned long the value read.
     */
    unsigned long singleRead();

};

#endif //SENSUALI_DI_PARCHEGGIO_ACCURATESONAR_H
