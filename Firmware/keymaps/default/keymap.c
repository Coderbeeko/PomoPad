// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum layers {
    _BASE,
    _FOCUS
};

enum custom_keycodes {
    SME = SAFE_RANGE,
    PAPA,
    GMAIL,
    GDOCS,
    FOCUS_TOGGLE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_BASE] = LAYOUT_ortho_3x3(
        SME,        PAPA,       GMAIL,
        KC_COPY,    KC_PASTE,   FOCUS_TOGGLE,
        GDOCS,      KC_NO,      KC_NO
    ),

    [_FOCUS] = LAYOUT_ortho_3x3(
        KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, FOCUS_TOGGLE,
        KC_NO, KC_NO, KC_NO
    )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

    if (!record->event.pressed) {
        return true;
    }

    switch (keycode) {

        case SME:
            SEND_STRING("open -a \"Safari\" https://www.savemyexams.com\n");
            return false;

        case PAPA:
            SEND_STRING("open -a \"Safari\" https://www.papacambridge.com\n");
            return false;

        case GMAIL:
            SEND_STRING("open -a \"Google Chrome\" https://mail.google.com\n");
            return false;

        case GDOCS:
            SEND_STRING("open -a \"Google Chrome\" https://docs.google.com\n");
            return false;

        case FOCUS_TOGGLE:
            if (layer_state_is(_FOCUS)) {
                layer_off(_FOCUS);
            } else {
                layer_on(_FOCUS);
            }
            return false;
    }

    return true;
}

layer_state_t layer_state_set_user(layer_state_t state) {

    if (layer_state_cmp(state, _FOCUS)) {
        rgblight_setrgb(255, 0, 0);  // Red
    } else {
        rgblight_setrgb(0, 0, 255);  // Blue
    }

    return state;
}

#ifdef OLED_ENABLE
bool oled_task_user(void) {

    oled_clear();

    if (layer_state_is(_FOCUS)) {
        oled_write_ln_P(PSTR("Focus Mode"), false);
        oled_write_ln_P(PSTR("Stay Locked In"), false);
    } else {
        oled_write_ln_P(PSTR("StudyPad"), false);
        oled_write_ln_P(PSTR("Ready"), false);
    }

    return false;
}
#endif

bool encoder_update_user(uint8_t index, bool clockwise) {

    if (clockwise) {
        tap_code(KC_VOLU);
    } else {
        tap_code(KC_VOLD);
    }

    return false;
}
