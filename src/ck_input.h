#ifndef CK_INPUT_H
#define CK_INPUT_H


namespace fallout {

enum CkKey {
    CK_KEY_R,
    CK_KEY_E,
    CK_KEY_P,

    CK_KEY_F9,

    CK_KEY_COUNT
};

bool ck_input_pressed(CkKey key);

bool ck_input_shift();
bool ck_input_ctrl();
bool ck_input_alt();

}

#endif
