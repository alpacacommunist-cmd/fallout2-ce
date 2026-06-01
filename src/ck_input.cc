#include "ck_input.h"
#include "kb.h"

static int ck_to_scancode(fallout::CkKey key) {
    switch (key) {

    case fallout::CK_KEY_R:
        return SDL_SCANCODE_R;

    case fallout::CK_KEY_E:
        return SDL_SCANCODE_E;

    case fallout::CK_KEY_P:
        return SDL_SCANCODE_P;

    case fallout::CK_KEY_F9:
        return SDL_SCANCODE_F9;

    default:
        return SDL_SCANCODE_UNKNOWN;
    }
}

bool fallout::ck_input_pressed(CkKey key) {
    int scancode = ck_to_scancode(key);

    if (scancode == SDL_SCANCODE_UNKNOWN) return false;

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
