/* Copyright 2024 VIAL Contributor
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

 /*
 * Mac Layout
 *
 * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┬───┐
 * │Esc│ 1 │ 2 │ 3 │ 4 │ 5 │ 6 │ 7 │ 8 │ 9 │ 0 │ - │ = │Backsp │Mut│
 * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┼───┘
 * │ Tab │ Q │ W │ E │ R │ T │ Y │ U │ I │ O │ P │ [ │ ] │  \  │
 * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┼───┐
 * │ Caps │ A │ S │ D │ F │ G │ H │ J │ K │ L │ ; │ ' │ Enter  │PgU│
 * ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────┬───┼───┤
 * │ Shift  │ Z │ X │ C │ V │ B │ N │ M │ , │ . │ / │ Shift│ ↑ │PgD│
 * ├────┬───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴───┼───┴┬─┬───┼───┼───┤
 * │Ctl │Opt │Cmd │         Space          │Cmd │ Fn │ │ ← │ ↓ │ → │
 * └────┴────┴────┴────────────────────────┴────┴────┘ └───┴───┴───┘
 */

 // Each layer gets a name for readability
 enum layer_names {
     _BASE,      // Default layer
     _FN,        // Function layer
     _EXTRA      // Extra layer for user customization
 };

 // Custom keycodes for RGB control and additional functionality
 enum custom_keycodes {
     RGB_TOG_VAL = QK_USER, // Toggle RGB on/off by value
     RGB_TOG_ALL,           // Toggle all RGB effects
     RGBM_MOD,              // Cycle through RGB modes
     RGBM_TOGGLE            // Toggle between OpenRGB and local control mode
 };

 const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
     /* Base Layer (Default Layer) with Mac Layout */
     [_BASE] = LAYOUT(
         KC_ESC,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,  KC_MUTE,
         KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,
         KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,            KC_ENT,   KC_PGUP,
         KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,  KC_UP,    KC_PGDN,
         KC_LCTL,  KC_LOPT,  KC_LCMD,                                KC_SPC,                       KC_RCMD,  MO(_FN),          KC_LEFT,  KC_DOWN,  KC_RGHT
     ),

     /* Function Layer for Mac */
     [_FN] = LAYOUT(
         KC_GRV,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_DEL,   _______,
         _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  RGBM_TOGGLE, KC_PSCR,  KC_SCRL,  KC_PAUS,  KC_INS,
         _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,  KC_HOME,
         _______,            RGB_SAD,  RGB_SAI,  RGB_SPD,  RGB_SPI,  KC_MUTE,  KC_VOLD,  KC_VOLU,  KC_MPRV,  KC_MPLY,  KC_MNXT,  _______,  RGB_VAI,  KC_END,
         _______,  _______,  _______,                                _______,                      _______,  _______,            RGB_RMOD, RGB_VAD,  RGB_MOD
     ),

     /* Extra Layer for user customization */
     [_EXTRA] = LAYOUT(
         _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
         _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
         _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,  _______,
         _______,            _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
         _______,  _______,  _______,                                _______,                      _______,  _______,            _______,  _______,  _______
     )
 };

 #ifdef RGB_MATRIX_ENABLE
 // RGB Matrix animation speed for certain modes
 uint8_t rgb_matrix_mode_speed = 170;

 // Custom handler for toggling between OpenRGB and local RGB control
 #ifdef OPENRGB_ENABLE
 bool rgb_is_openrgb_mode = true;
 #endif

 bool process_record_user(uint16_t keycode, keyrecord_t *record) {
     switch (keycode) {
         case RGBM_TOGGLE:
             if (record->event.pressed) {
                 #ifdef OPENRGB_ENABLE
                 rgb_is_openrgb_mode = !rgb_is_openrgb_mode;
                 if (rgb_is_openrgb_mode) {
                     rgb_matrix_set_color_all(0, 255, 0); // Green indicator for OpenRGB mode
                 } else {
                     rgb_matrix_set_color_all(0, 0, 255); // Blue indicator for local control mode
                 }
                 #endif
             }
             return false;

         case RGB_TOG_VAL:
             if (record->event.pressed) {
                 rgb_matrix_toggle_noeeprom();
             }
             return false;

         case RGB_TOG_ALL:
             if (record->event.pressed) {
                 rgb_matrix_toggle();
             }
             return false;

         case RGBM_MOD:
             if (record->event.pressed) {
                 rgb_matrix_step_noeeprom();
             }
             return false;
     }
     return true;
 }
 #endif

 #if defined(ENCODER_MAP_ENABLE)
 const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
     [_BASE] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
     [_FN] = { ENCODER_CCW_CW(RGB_VAD, RGB_VAI)},
     [_EXTRA] = { ENCODER_CCW_CW(RGB_HUD, RGB_HUI)},
 };
 #endif // ENCODER_MAP_ENABLE
