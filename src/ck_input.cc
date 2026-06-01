#include "ck_input.h"
#include "kb.h"

static int ck_to_scancode(fallout::CkKey key) {
    switch (key) {

        case fallout::CK_KEY_MINUS:     return 45; // -
        case fallout::CK_KEY_EQUALS:    return 46; // =
        case fallout::CK_KEY_COMMA:     return 54; // ,
        case fallout::CK_KEY_PERIOD:    return 55; // .

        default:                        return 0; // SDL_SCANCODE_UNKNOWN;
    }
}

bool fallout::ck_input_pressed(CkKey key) {
    int scancode = ck_to_scancode(key);

    if (scancode == 0) return false;

    return gPressedPhysicalKeys[scancode] != KEY_STATE_UP;
}

bool fallout::ck_input_shift() {
    return gPressedPhysicalKeys[SDL_SCANCODE_LSHIFT] || gPressedPhysicalKeys[SDL_SCANCODE_RSHIFT];
}

bool fallout::ck_input_ctrl() {
    return gPressedPhysicalKeys[SDL_SCANCODE_LCTRL] || gPressedPhysicalKeys[SDL_SCANCODE_RCTRL];
}

bool fallout::ck_input_alt() {
    return gPressedPhysicalKeys[SDL_SCANCODE_LALT] || gPressedPhysicalKeys[SDL_SCANCODE_RALT];
}
