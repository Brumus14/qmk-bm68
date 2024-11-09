/* Copyright 2022 bdtc123
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H
enum my_keycodes {
    RGB_TOG = SAFE_RANGE,
    RGB_MOD,
    RGB_HUI,
    RGB_HUD,
    RGB_SAI,
    RGB_SAD,
    RGB_VAI,
    RGB_VAD,
    RGB_SPI,
    RGB_SPD
};

bool is_shift_pressed(void) {
    return keyboard_report->mods & (MOD_BIT(KC_LSFT) | MOD_BIT(KC_RSFT));
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case RGB_TOG:
        if (record->event.pressed) {
            rgb_matrix_toggle();
        }
        return false;
    case RGB_MOD:
        if (record->event.pressed) {
            if (is_shift_pressed()) {
                rgb_matrix_step();
            } else {
                rgb_matrix_step_reverse();
            }
        }
        return false;
    case RGB_HUI:
        if (record->event.pressed) {
            if (is_shift_pressed()) {
                rgb_matrix_decrease_hue();
            } else {
                rgb_matrix_increase_hue();
            }
        }
        return false;
    case RGB_HUD:
        if (record->event.pressed) {
            if (is_shift_pressed()) {
                rgb_matrix_increase_hue();
            } else {
                rgb_matrix_decrease_hue();
            }
        }
        return false;
    case RGB_SAI:
        if (record->event.pressed) {
            if (is_shift_pressed()) {
                rgb_matrix_decrease_sat();
            } else {
                rgb_matrix_increase_sat();
            }
        }
        return false;
    case RGB_SAD:
        if (record->event.pressed) {
            if (is_shift_pressed()) {
                rgb_matrix_increase_sat();
            } else {
                rgb_matrix_decrease_sat();
            }
        }
        return false;
    case RGB_VAI:
        if (record->event.pressed) {
            if (is_shift_pressed()) {
                rgb_matrix_decrease_val();
            } else {
                rgb_matrix_increase_val();
            }
        }
        return false;
    case RGB_VAD:
        if (record->event.pressed) {
            if (is_shift_pressed()) {
                rgb_matrix_increase_val();
            } else {
                rgb_matrix_decrease_val();
            }
        }
        return false;
    case RGB_SPI:
        if (record->event.pressed) {
            if (is_shift_pressed()) {
                rgb_matrix_decrease_speed();
            } else {
                rgb_matrix_increase_speed();
            }
        }
        return false;
    case RGB_SPD:
        if (record->event.pressed) {
            if (is_shift_pressed()) {
                rgb_matrix_increase_speed();
            } else {
                rgb_matrix_decrease_speed();
            }
        }
        return false;
    default:
        return true;
    }
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // clang-format off
    [0] = LAYOUT_65_ansi(
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_HOME,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, KC_PGUP,
        KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,  KC_PGDN,
        KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_UP,   KC_END,
        KC_LCTL, KC_LGUI, KC_LALT,                            KC_SPC,                    KC_RALT, MO(1),   KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT
    ),
    [1] = LAYOUT_65_ansi(
        QK_BOOT, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,  _______,
        _______, RGB_TOG, RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI, RGB_SPI, _______, _______, _______, _______, _______, _______, _______, _______,
        KC_TILD, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______,
        KC_GRV,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______,                            _______,                   _______, _______, _______, _______, _______, _______
    ),
    [2] = LAYOUT_65_ansi(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______,
        _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______,                            _______,                   _______, _______, _______, _______, _______, _______
    ),
    [3] = LAYOUT_65_ansi(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______,
        _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______,                            _______,                   _______, _______, _______, _______, _______, _______
    )
    // clang-format on
};

/*bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {*/
/*    if (get_highest_layer(layer_state) > 0) {*/
/*        uint8_t layer = get_highest_layer(layer_state);*/
/**/
/*        for (uint8_t row = 0; row < MATRIX_ROWS; ++row) {*/
/*            for (uint8_t col = 0; col < MATRIX_COLS; ++col) {*/
/*                uint8_t index = g_led_config.matrix_co[row][col];*/
/**/
/*                if (index >= led_min && index < led_max && index != NO_LED
 * &&*/
/*                keymap_key_to_keycode(layer, (keypos_t){col,row}) > KC_TRNS)
 * {*/
/*                    rgb_matrix_set_color(index, RGB_GREEN);*/
/*                }*/
/*            }*/
/*        }*/
/*    }*/
/*    return false;*/
/*}*/
