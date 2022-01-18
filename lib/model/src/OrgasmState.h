#ifndef SENSUALI_DI_PARCHEGGIO_ORGASM_STATE_H
#define SENSUALI_DI_PARCHEGGIO_ORGASM_STATE_H

#include <Arduino.h>

#define LOW_DISTANCE 1000
#define MED_DISTANCE 2000
#define BIG_DISTANCE 4000

enum class OrgasmState { Relaxed = 0, Excited = 1, Almost = 2, Cumming = 3 };

/**
 * @brief Map the distance to an orgasm state.
 * 
 * @param distance the distance in input.
 * @return OrgasmState the corresponding orgasm state.
 */
OrgasmState map_from_distance(int distance) {
    if(distance < LOW_DISTANCE) {
        return OrgasmState::Cumming;
    } else if(distance >= LOW_DISTANCE && distance < MED_DISTANCE) {
        return OrgasmState::Almost;
    } else if(distance >= MED_DISTANCE && distance < BIG_DISTANCE) {
        return OrgasmState::Excited;
    }
    return OrgasmState::Relaxed;
}

/**
 * @brief Return the OrgasmState corresponding string.
 * 
 * @param o the orgasmState.
 * @return String the corresponding string.
 */
String orgasm_as_string(OrgasmState o) {
    switch (o) {
        case OrgasmState::Cumming:
            return "Cumming";
        case OrgasmState::Almost:
            return "Almost";
        case OrgasmState::Excited:
            return "Excited";
        case OrgasmState::Relaxed:
            return "Relaxed";
        default:
            return "";
    }
}

/**
 * @brief Map the OrgasmState to a volume.
 * 
 * @param o the OrgasmState.
 * @return int the value representing the volume to use.
 */
int orgasm_as_volume(OrgasmState o) {
    switch (o) {
        case OrgasmState::Cumming:
            return 30;
        case OrgasmState::Almost:
            return 20;
        case OrgasmState::Excited:
            return 15;
        default:
            return 15;
    }
}

#endif // SENSUALI_DI_PARCHEGGIO_ORGASM_STATE_H