#include "OrgasmState.h"
#include <stdlib.h>

/**
 * @brief Return a random number between min and max (inclusive).
 * 
 * @param min the min number.
 * @param max the max number.
 * @return int the random number.
 */
int custom_rand(int min, int max) {
    return rand() % max + min;;
}

/**
 * @brief Return a random number representing the name of the file to play.
 * 
 * @param s the OrgasmState.
 * @param excited_sound_numbers the number of excipted sounds.
 * @param almost_sound_numbers the number of almost sounds.
 * @param cumming_sound_numbers the number of cumming sounds.
 * @return int a random number representing the name of the file to play.
 */
int random_orgasm(
    OrgasmState s,
    int excited_sound_numbers,
    int almost_sound_numbers,
    int cumming_sound_numbers
) {
    switch (s) {
        case OrgasmState::Excited:
            return custom_rand(1, excited_sound_numbers);
        case OrgasmState::Almost:
            return custom_rand(excited_sound_numbers + 1, almost_sound_numbers);
        case OrgasmState::Cumming:
            return custom_rand(excited_sound_numbers + almost_sound_numbers + 1, cumming_sound_numbers);
        case OrgasmState::Relaxed:
            return 0;
    }
    return 0;
}