/* keyboards/gmmk/gmmk3/p65/ansi/keymaps/vial/config.h */
#pragma once

// Fix bootmagic settings - remove redefinitions
#undef BOOTMAGIC_LITE_ROW
#undef BOOTMAGIC_LITE_COLUMN

// VIAL-specific configuration
#define VIAL_KEYBOARD_UID {0xB1, 0x2F, 0x4C, 0xD9, 0x65, 0xE8, 0x47, 0x92}
#define VIAL_UNLOCK_COMBO_ROWS { 9, 9 }
#define VIAL_UNLOCK_COMBO_COLS { 0, 5 }
#define DYNAMIC_KEYMAP_LAYER_COUNT 3
#define VIAL_COMBO_ENTRIES 4
#define VIAL_KEY_OVERRIDE_ENTRIES 4

// Mac-specific keyboard settings
#define APPLE_FN_ENABLE

// Other necessary configs for WB32 microcontroller
#define WEAR_LEVELING_BACKING_SIZE 4096

// RGB matrix configuration
#define RGB_MATRIX_KEYPRESSES
#define RGB_MATRIX_MAXIMUM_BRIGHTNESS 180
#define RGB_MATRIX_STARTUP_MODE RGB_MATRIX_SOLID_COLOR
#define RGB_MATRIX_STARTUP_HUE 170
#define RGB_MATRIX_STARTUP_SAT 255
#define RGB_MATRIX_STARTUP_VAL 180

/* keyboards/gmmk/gmmk3/p65/ansi/keymaps/vial/config.h */
#pragma once

// Enable rotary encoder support that works with VIAL
#define ENCODER_RESOLUTION 4
#define AUDIO_CLICKY
