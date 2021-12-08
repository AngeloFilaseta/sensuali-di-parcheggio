#ifndef SENSUALI_DI_PARCHEGGIO_ORGASM_STATE_H
#define SENSUALI_DI_PARCHEGGIO_ORGASM_STATE_H

enum class OrgasmState { Relaxed = 0, Excited = 1, Almost = 2, Cumming = 3 };

OrgasmState map_from_distance(int distance) {
    if(distance < 70) {
        return OrgasmState::Cumming;
    } else if(distance >=70 && distance < 140) {
        return OrgasmState::Almost;
    } else if(distance >=140 && distance < 210) {
        return OrgasmState::Excited;
    }
    return OrgasmState::Relaxed;
}

#endif // SENSUALI_DI_PARCHEGGIO_ORGASM_STATE_H