/* Copyright 2024 Glorious, LLC
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

 #include "quantum.h"

 #ifdef VIA_OPENRGB_HYBRID
      uint8_t is_orgb_mode = true; //Default value of the hybrid switch mode
 #endif

 #ifdef RGB_MATRIX_ENABLE
 #define __ NO_LED

 /* Refer to AW20216S manual for these locations
  *   driver
  *   |     R location
  *   |     |          G location
  *   |     |          |          B location
  *   |     |          |          | */
 const aw20216s_led_t PROGMEM g_aw20216s_leds[AW20216S_LED_COUNT] = {
     {0, SW1_CS4, SW1_CS5, SW1_CS6},        // 0 ESC - UPDATED FROM SW1_CS1, SW1_CS2, SW1_CS3
     {0, SW2_CS4, SW2_CS5, SW2_CS6},        // 1 1
     {0, SW3_CS4, SW3_CS5, SW3_CS6},        // 2 2
     {0, SW4_CS4, SW4_CS5, SW4_CS6},        // 3 3
     {0, SW5_CS4, SW5_CS5, SW5_CS6},        // 4 4
     {0, SW6_CS4, SW6_CS5, SW6_CS6},        // 5 5
     {0, SW7_CS4, SW7_CS5, SW7_CS6},        // 6 6
     {0, SW8_CS4, SW8_CS5, SW8_CS6},        // 7 7
     {0, SW9_CS4, SW9_CS5, SW9_CS6},        // 8 8
     {0, SW10_CS4, SW10_CS5, SW10_CS6},     // 9 9
     {0, SW11_CS4, SW11_CS5, SW11_CS6},     // 10 0
     {0, SW12_CS4, SW12_CS5, SW12_CS6},     // 11 -
     {1, SW5_CS1, SW5_CS2, SW5_CS3},        // 12 =
     {1, SW7_CS1, SW7_CS2, SW7_CS3},        // 13 BS

     {0, SW1_CS7, SW1_CS8, SW1_CS9},        // 14 TAB
     {0, SW2_CS7, SW2_CS8, SW2_CS9},        // 15 Q
     {0, SW3_CS7, SW3_CS8, SW3_CS9},        // 16 W
     {0, SW4_CS7, SW4_CS8, SW4_CS9},        // 17 E
     {0, SW5_CS7, SW5_CS8, SW5_CS9},        // 18 R
     {0, SW6_CS7, SW6_CS8, SW6_CS9},        // 19 T
     {0, SW7_CS7, SW7_CS8, SW7_CS9},        // 20 Y
     {0, SW8_CS7, SW8_CS8, SW8_CS9},        // 21 U
     {0, SW9_CS7, SW9_CS8, SW9_CS9},        // 22 I
     {0, SW10_CS7, SW10_CS8, SW10_CS9},     // 23 O
     {0, SW11_CS7, SW11_CS8, SW11_CS9},     // 24 P
     {0, SW12_CS7, SW12_CS8, SW12_CS9},     // 25 [
     {1, SW8_CS1, SW8_CS2, SW8_CS3},        // 26 ]
     {1, SW9_CS1, SW9_CS2, SW9_CS3},        // 27 (\)

     {0, SW1_CS10, SW1_CS11, SW1_CS12},     // 28 CAPS
     {0, SW2_CS10, SW2_CS11, SW2_CS12},     // 29 A
     {0, SW3_CS10, SW3_CS11, SW3_CS12},     // 30 S
     {0, SW4_CS10, SW4_CS11, SW4_CS12},     // 31 D
     {0, SW5_CS10, SW5_CS11, SW5_CS12},     // 32 F
     {0, SW6_CS10, SW6_CS11, SW6_CS12},     // 33 G
     {0, SW7_CS10, SW7_CS11, SW7_CS12},     // 34 H
     {0, SW8_CS10, SW8_CS11, SW8_CS12},     // 35 J
     {0, SW9_CS10, SW9_CS11, SW9_CS12},     // 36 K
     {0, SW10_CS10, SW10_CS11, SW10_CS12},  // 37 L
     {0, SW11_CS10, SW11_CS11, SW11_CS12},  // 38 ;
     {0, SW12_CS10, SW12_CS11, SW12_CS12},  // 39 '
     {1, SW11_CS1, SW11_CS2, SW11_CS3},     // 40 ENTER
     {1, SW7_CS4, SW7_CS5, SW7_CS6},        // 41 PGUP

     {0, SW1_CS13, SW1_CS14, SW1_CS15},     // 42 L_SHIFT
     {0, SW2_CS13, SW2_CS14, SW2_CS15},     // 43 Z
     {0, SW3_CS13, SW3_CS14, SW3_CS15},     // 44 X
     {0, SW4_CS13, SW4_CS14, SW4_CS15},     // 45 C
     {0, SW5_CS13, SW5_CS14, SW5_CS15},     // 46 V
     {0, SW6_CS13, SW6_CS14, SW6_CS15},     // 47 B
     {0, SW7_CS13, SW7_CS14, SW7_CS15},     // 48 N
     {0, SW8_CS13, SW8_CS14, SW8_CS15},     // 49 M
     {0, SW9_CS13, SW9_CS14, SW9_CS15},     // 50 ,
     {0, SW10_CS13, SW10_CS14, SW10_CS15},  // 51 .
     {0, SW11_CS13, SW11_CS14, SW11_CS15},  // 52 /
     {1, SW8_CS4, SW8_CS5, SW8_CS6},        // 53 R_SHIFT
     {1, SW9_CS4, SW9_CS5, SW9_CS6},        // 54 UP
     {1, SW2_CS1, SW2_CS2, SW2_CS3},        // 55 PGDN

     {0, SW1_CS16, SW1_CS17, SW1_CS18},     // 56 L_CTRL
     {0, SW2_CS16, SW2_CS17, SW2_CS18},     // 57 L_OPT (Mac)
     {0, SW3_CS16, SW3_CS17, SW3_CS18},     // 58 L_CMD (Mac)
     {0, SW6_CS16, SW6_CS17, SW6_CS18},     // 59 SPACE
     {0, SW9_CS16, SW9_CS17, SW9_CS18},     // 60 R_CMD (Mac)
     {0, SW10_CS16, SW10_CS17, SW10_CS18},  // 61 FN
     {1, SW10_CS4, SW10_CS5, SW10_CS6},     // 62 LEFT
     {1, SW11_CS4, SW11_CS5, SW11_CS6},     // 63 DOWN
     {1, SW5_CS10, SW5_CS11, SW5_CS12},     // 64 RIGHT

     {1, SW1_CS13, SW1_CS14, SW1_CS15},     // 65 SLED1
     {1, SW2_CS13, SW2_CS14, SW2_CS15},     // 66 SLED2
     {1, SW3_CS13, SW3_CS14, SW3_CS15},     // 67 SLED3
     {1, SW4_CS13, SW4_CS14, SW4_CS15},     // 68 SLED4
     {1, SW5_CS13, SW5_CS14, SW5_CS15},     // 69 SLED5
     {1, SW6_CS13, SW6_CS14, SW6_CS15},     // 70 SLED6
     {1, SW7_CS13, SW7_CS14, SW7_CS15},     // 71 SLED7
     {1, SW8_CS13, SW8_CS14, SW8_CS15},     // 72 SLED8
     {1, SW9_CS13, SW9_CS14, SW9_CS15},     // 73 SLED9
     {1, SW10_CS13, SW10_CS14, SW10_CS15},  // 74 SLED10

     {1, SW1_CS16, SW1_CS17, SW1_CS18},     // 75 SLED11
     {1, SW2_CS16, SW2_CS17, SW2_CS18},     // 76 SLED12
     {1, SW3_CS16, SW3_CS17, SW3_CS18},     // 77 SLED13
     {1, SW4_CS16, SW4_CS17, SW4_CS18},     // 78 SLED14
     {1, SW5_CS16, SW5_CS17, SW5_CS18},     // 79 SLED15
     {1, SW6_CS16, SW6_CS17, SW6_CS18},     // 80 SLED16
     {1, SW7_CS16, SW7_CS17, SW7_CS18},     // 81 SLED17
     {1, SW8_CS16, SW8_CS17, SW8_CS18},     // 82 SLED18
     {1, SW9_CS16, SW9_CS17, SW9_CS18},     // 83 SLED19
     {1, SW10_CS16, SW10_CS17, SW10_CS18},  // 84 SLED20
     {1, SW10_CS1, SW10_CS2, SW10_CS3},     // 85 BADGE
 };

/* Portion of ansi.c that needs to be updated */

/* The main issue appears to be in the LED matrix configuration */
/* We need to fix the matrix configuration to correctly map the PG UP LED */

led_config_t g_led_config = {
     {
         { 42, __, __, 62, __, 64, 56, __},
         { 15, 14, 29, 0,  43, 41, 0,  1 },  // PG UP LED (41) is in position [1, 5]
         { 16, 28, 30, __, 44, 55, __, 2 },
         { 17, __, 31, __, 45, 54, __, 3 },
         { 18, 19, 32, 33, 46, 47, 5,  4 },
         { 21, 20, 35, 34, 49, 48, 6,  7 },
         { 22, 26, 36, __, 50, __, 12, 8 },
         { 23, __, 37, 63, 51, __, __, 9 },
         { 24, 25, 38, 39, __, 52, 11, 10 },
         { 57, 53, 61, 58, 59, 60, __, __},  // Mac layout: L_OPT, R_SHIFT, FN, L_CMD, SPACE, R_CMD
         { __, 13, 27, __, 40, __, __, __},
         { __, __, __, __, __, __, 55, __},
         { __, __, __, __, __, __, __, __},
         { __, __, __, __, __, __, __, __},
     },
     {
         {0,0},   {15,0},  {30,0},  {45,0},  {60,0},  {75,0},  {90,0},   {105,0},  {120,0},   {135,0},  {150,0},  {165,0},  {180,0},  {195,0},
         {7,16},  {22,16}, {37,16}, {52,16}, {67,16}, {82,16}, {97,16},  {112,16}, {127,16},  {142,16}, {157,16}, {172,16}, {187,16}, {202,16},
         {11,32}, {26,32}, {41,32}, {56,32}, {71,32}, {86,32}, {101,32}, {116,32}, {131,32},  {146,32}, {161,32}, {176,32},           {200,32}, {224,32},
         {17,48},          {33,48}, {48,48}, {63,48}, {78,48}, {93,48},  {108,48}, {123,48},  {138,48}, {153,48}, {168,48}, {189,48}, {210,48}, {224,48},
         {4,64},  {22,64}, {39,64},                            {97,64},                                 {150,64}, {170,64}, {195,64}, {210,64}, {224,64},
         // Left and right side lights
         {0, 15},  {0, 20},  {0, 25},  {0, 30},  {0, 35},  {0, 40},  {0, 45},  {0, 50},  {0, 55},  {0, 60},
         {224, 15},  {224, 20},  {224, 25},  {224, 30},  {224, 35},  {224, 40},  {224, 45},  {224, 50},  {224, 55},  {224, 60},
         // BADGE
         {214, 0},
     },
     {
         // Keyboard RGB Matrix
         4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
         4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
         4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,    4, 4,
         4,    4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
         4, 4, 4,          4,          4, 4, 4, 4, 4,
         // Left and right side lights
         2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
         2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
         //BADGE
         8,
     }
 };
 #endif // RGB_MATRIX_ENABLE

 #ifdef EEPROM_ENABLE

 #include "spi_master.h"

 void spi_init(void) {
     static bool is_initialised = false;
     if (!is_initialised) {
         is_initialised = true;

         // Try releasing special pins for a short time
         setPinInput(SPI_SCK_PIN);
         setPinInput(SPI_MOSI_PIN);
         setPinInput(SPI_MISO_PIN);

         chThdSleepMilliseconds(10);

         palSetPadMode(PAL_PORT(SPI_SCK_PIN), PAL_PAD(SPI_SCK_PIN), PAL_MODE_ALTERNATE(SPI_SCK_PAL_MODE) | PAL_OUTPUT_TYPE_PUSHPULL | PAL_OUTPUT_SPEED_HIGHEST | PAL_WB32_CURRENT_LEVEL3);
         palSetPadMode(PAL_PORT(SPI_MOSI_PIN), PAL_PAD(SPI_MOSI_PIN), PAL_MODE_ALTERNATE(SPI_MOSI_PAL_MODE) | PAL_OUTPUT_TYPE_PUSHPULL | PAL_OUTPUT_SPEED_HIGHEST);
         palSetPadMode(PAL_PORT(SPI_MISO_PIN), PAL_PAD(SPI_MISO_PIN), PAL_MODE_ALTERNATE(SPI_MISO_PAL_MODE) | PAL_OUTPUT_TYPE_PUSHPULL | PAL_OUTPUT_SPEED_HIGHEST);
     }
 }

 #endif
