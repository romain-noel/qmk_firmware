 /* Copyright 2021 Dane Evans
  *
  * This program is free software: you can redistribute it and/or modify
  * it under the terms of the GNU General Public License as published by
  * the Free Software Foundation, either version 2 of the License, or
  * (at your option) any later version.
  *
  * This program is distributed in the hope that it will be useful,
  * but WITHOUT ANY WARRANTY; without even the implied warranty of
  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  * GNU General Public License for more details.,f
  *
  * You should have received a copy of the GNU General Public License
  * along with this program.  If not, see <http://www.gnu.org/licenses/>.
  */
  // SOFLE RGB
#include <stdio.h>

#include QMK_KEYBOARD_H

enum sofle_layers {
    _QWERTY = 0,
    _LOWER,
    _RAISE,
    _ADJUST,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  `   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | TAB  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  | Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LShift|   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------| PLAY/F|    | VOL+/-|------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  | DEL  |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | Bspc | WIN  |LOWER | Enter| /Space  /       \Enter \  |SPACE |RAISE | RAtl | RAISE|
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `-----------------------------------'           '------''---------------------------'
 */
[_QWERTY] = LAYOUT(
    KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5,   KC_6, KC_7, KC_8, KC_9, KC_0, KC_BSPC, 
    KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T,   KC_Y, KC_U, KC_I, KC_O, KC_P, KC_MINS, 
    KC_GRV, KC_A, KC_S, KC_D, KC_F, KC_G,   KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, 
    KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_MUTE,   KC_MPLY, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, 
    TT(_LOWER), KC_LALT, KC_LGUI, KC_LCTL, KC_SPC, KC_ENT, KC_RALT, KC_APP, KC_RCTL, TT(_RAISE)
),

/* LOWER
 * ,----------------------------------------.                     ,-----------------------------------------.
 * |  Esc |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      | Ins  | Pscr | Menu |      |      |                    |      | PWrd |  Up  | NWrd | DLine| Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  | LAt  | LCtl |LShift|      | Caps |-------.    ,-------|      | Left | Down | Rigth|  Del | Bspc |
 * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
 * |Shift | Undo |  Cut | Copy | Paste|      |-------|    |-------|      | LStr |      | LEnd |      | Shift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR |LOWER | /Enter  /       \Space \  |RAISE | RCTR | RAlt | RGUI |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `-----------------------------------'           '------''---------------------------'
 */
[_LOWER] = LAYOUT(
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO, KC_NO, KC_MRWD, KC_MPLY, KC_MFFD, KC_PGUP, KC_NO, KC_UP, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_NO, KC_NO, KC_VOLD, KC_MUTE, KC_VOLU, KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_NO, KC_DEL, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_MSTP, KC_NO, KC_TRNS, KC_TRNS, KC_NO, KC_HOME, KC_NO, KC_END, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
),

/* RAISE
 * ,----------------------------------------.                     ,-----------------------------------------.
 * |  Esc |  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  | F10  | F11  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      | Ins  | Pscr | Menu |      |      |                    |      | PWrd |  Up  | NWrd | DLine| Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  | LAt  | LCtl |LShift|      | Caps |-------.    ,-------|      | Left | Down | Rigth|  Del | Bspc |
 * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
 * |Shift | Undo |  Cut | Copy | Paste|      |-------|    |-------|      | LStr |      | LEnd |      | Shift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR |LOWER | /Enter  /       \Space \  |RAISE | RCTR | RAlt | RGUI |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `-----------------------------------'           '------''---------------------------'
 */
[_RAISE] = LAYOUT(
    KC_TRNS, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_TRNS, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_F12, KC_GRV, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_NO, KC_SCLN, KC_DEL, KC_TRNS, KC_EQL, KC_MINS, KC_PLUS, KC_LPRN, KC_RPRN, KC_TRNS, KC_TRNS, KC_LBRC, KC_RBRC, KC_LCBR, KC_RCBR, KC_BSLS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
),

/* ADJUST
 * ,----------------------------------------.                     ,-----------------------------------------.
 * |  Esc |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      | Ins  | Pscr | Menu |      |      |                    |      | PWrd |  Up  | NWrd | DLine| Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  | LAt  | LCtl |LShift|      | Caps |-------.    ,-------|      | Left | Down | Rigth|  Del | Bspc |
 * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
 * |Shift | Undo |  Cut | Copy | Paste|      |-------|    |-------|      | LStr |      | LEnd |      | Shift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR |LOWER | /Enter  /       \Space \  |RAISE | RCTR | RAlt | RGUI |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `-----------------------------------'           '------''---------------------------'
 */
[_ADJUST] = LAYOUT(
    KC_NO, TO(1), TO(2), TO(3), TO(4), KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_INS, KC_NO, KC_PSCR, KC_NO, KC_NO, RM_TOGG, RM_HUEU, RM_SATU, RM_VALU, KC_NO, KC_NO, KC_PAUS, KC_SCRL, KC_CAPS, KC_NO, KC_NO, KC_NO, RM_NEXT, RM_HUED, RM_SATD, RM_VALD, KC_NO, KC_TRNS, KC_TRNS, KC_NUM, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
),

};

// Enable RGB led.
void keyboard_post_init_user(void) {
	rgb_matrix_enable();
	rgb_matrix_mode(RGB_MATRIX_SOLID_COLOR);
	rgb_matrix_sethsv(0,0,255); // white
}

layer_state_t layer_state_set_user(layer_state_t state) {
    // Get the highest active layer.
    uint8_t layer = get_highest_layer(state);
    
    // Adapt color to the layer.
    switch (layer) {
        case _QWERTY:
            rgb_matrix_sethsv(240, 0, 255); // white
            break;
        case _LOWER:
            rgb_matrix_sethsv(0, 255, 255); // red
            break;
        case _RAISE:
            rgb_matrix_sethsv(168, 255, 255); // blue
            break;
        case _ADJUST:
            rgb_matrix_sethsv(84, 255, 255); // green
            break;
        default:
            // For any other layer, you might want a default behavior
            break;
    }

    // When both LOWER and RAISE are active, turn on ADJUST layer.
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
    // return state
}

// Function to render the status of the keyboard: layer, locks etc.
void render_status(void) {
    // Print layer
    oled_write_P(PSTR("L: "), false); // layer
    switch (get_highest_layer(layer_state)) {
        case _QWERTY:
            oled_write_ln_P(PSTR("Base"), false);
            break;
        case _LOWER:
            oled_write_ln_P(PSTR("lower"), false);
            break;
        case _RAISE:
            oled_write_ln_P(PSTR("raise"), false);
            break;
        case _ADJUST:
            oled_write_ln_P(PSTR("adjust"), false);
            break;
        default:
            oled_write_ln_P(PSTR("Unknown"), false);
	}
    
    // Print Lock Keys
    oled_write_P(PSTR("C: "), false); // caps
    oled_write_ln_P(host_keyboard_led_state().caps_lock ? PSTR("ON") : PSTR("OFF"), false);
    
    oled_write_P(PSTR("S: "), false); // scroll
    oled_write_ln_P(host_keyboard_led_state().scroll_lock ? PSTR("ON") : PSTR("OFF"), false);
    
    oled_write_P(PSTR("N: "), false);
    oled_write_ln_P(host_keyboard_led_state().num_lock ? PSTR("ON") : PSTR("OFF"), false);
}


#ifdef OLED_ENABLE
// Initialize the oled display, rotating the rendered output based on the define passed in.
// Returns true if the OLED was initialized successfully
bool oled_init(oled_rotation_t OLED_ROTATION_180);

// Called at the start of oled_init, weak function overridable by the user
// rotation - the value passed into oled_init
// Return new oled_rotation_t if you want to override default rotation
oled_rotation_t oled_init_kb(oled_rotation_t OLED_ROTATION_180);
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_left()) {
        return OLED_ROTATION_180; 
    } else {
        return OLED_ROTATION_0;
    }
}


bool oled_task_user(void) {
    if (is_keyboard_left()) { // left  or is_keyboard_master()	
        render_status();
    } else { // right 
        oled_write_ln_P(PSTR("totoz"), false); // Renders the current keyboard state (layer, lock, caps, scroll, etc)
    }
    return false;
}
#endif


#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT) },
    { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT) },
    { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT) },
    { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT) },
};
#endif
