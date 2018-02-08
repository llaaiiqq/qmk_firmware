/* Copyright 2017 REPLACE_WITH_YOUR_NAME
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
#include "v60_type_r.h"

#define _____ KC_TRNS
#define XXXXX KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Keymap 0: Dvorak */
    [0] = KEYMAP(
        KC_GESC,          KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_LBRC, KC_RBRC,  XXXXX, KC_BSPC,   \
        KC_TAB,           KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,    KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_SLSH, KC_EQL,   KC_BSLS,          \
        MO(1),            KC_A,    KC_O,    KC_E,    KC_U,    KC_I,    KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_MINS, KC_ENT,                     \
        KC_LSFT,          XXXXX,   KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,    KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    KC_RSFT,  XXXXX,            \
        KC_LCTL,          KC_LGUI, KC_LALT, KC_SPC,                                               MO(2),   KC_RGUI, KC_RALT, KC_RCTL                    ),
    /* Keymap 1: FN Layer
     */
    [1] = KEYMAP(
        KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _____,  KC_DEL, \
        _____,   _____,   _____,   _____,   _____,   _____,   _____, KC_PGUP, KC_UP,   KC_PGDN, KC_PSCR, KC_SLCK, KC_PAUS,          _____, \
        _____,   _____,   _____,   _____,   _____,   _____, KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT, KC_END,  KC_PGUP,           _____,          \
        _____,   _____,   _____,   _____,   _____,   _____,   _____, KC_MUTE, KC_VOLD, KC_VOLU, KC_END,  KC_PGDN,           _____,  _____,  \
        _____,   _____,   _____,               _____,                                                    _____,   _____,  _____,  _____),
    /* Keymap 3: LED Modification Layer
     * ,-----------------------------------------------------------.
     * |   |BLT|BLC|UGT|UGP|UGB|UGR|   |   |   |   |   |   |       |
     * |-----------------------------------------------------------|
     * |     |RD+|GN+|BL+|HU+|SA+|VA+|   |   |   |   |   |   |     |
     * |-----------------------------------------------------------|
     * |      |RD-|GN-|BL-|HU-|SA-|VA-|   |   |   |   |   |        |
     * |-----------------------------------------------------------|
     * |        |   |   |   |   |   |   |   |   |   |   |          |
     * |-----------------------------------------------------------|
     * |    |    |    |                        |    |    |    |    |
     * `-----------------------------------------------------------'
     */
    [2] = KEYMAP(
        _____, BL_TOGG, BL_STEP, RGB_TOG, RGB_M_P, RGB_M_B, RGB_M_R,   _____,   _____,   _____,   _____,   _____,   _____,  _____,  _____, \
        _____, RGB_RI,  RGB_GI,  RGB_BI,  RGB_HUI, RGB_SAI, RGB_VAI,   _____,   _____,   _____,   _____,   _____,   _____,          _____, \
        _____, RGB_RD,  RGB_GD,  RGB_BD,  RGB_HUD, RGB_SAD, RGB_VAD,   _____,   _____,   _____,   _____,   _____,           _____,          \
        _____,   _____,   _____,   _____,   _____,   _____,   _____,   _____,   _____,   _____,   _____,   _____,           _____,  _____,  \
        _____,   _____,   _____,               _____,                                                      _____,   _____,  _____,  _____),
};

void led_set_user(uint8_t usb_led) {
    uint32_t layer = layer_state;
    if (layer & (1<<1)) {
        // output low
        DDRE  |=  (1<<PE6);
        PORTE &= ~(1<<PE6);
    }
    else {
        // Hi-Z
        DDRE  &= ~(1<<PE6);
        PORTE &= ~(1<<PE6);
    }
}
