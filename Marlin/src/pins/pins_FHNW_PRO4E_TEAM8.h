/**
 * Marlin 3D Printer Firmware
 * Copyright (C) 2019 MarlinFirmware [https://github.com/MarlinFirmware/Marlin]
 *
 * Based on Sprinter and grbl.
 * Copyright (C) 2011 Camiel Gubbels / Erik van der Zalm
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

/**
 * FHNW pro4E Team8 (STM32F130ZET6, TMC2660 drivers) board pin assignments
 * loosely based on the MKS Robin, changes made by Dominik Mueller
 * 
 * Note: SPI2 interface is used. Maple core has to be configured accordingly:
 *       Change `SPIClass SPI(1);` to `SPIClass SPI(2);` in `SPI.cpp` file
 */

#ifndef __STM32F1__
  #error "Oops! Select an STM32F1 board in 'Tools > Board.'"
#endif

/**
 * Expansion board
 */
// #define EXPANSION_BOARD

#if defined(EXPANSION_BOARD)
  #define MAX_HOTENDS 3
#else
  #define MAX_HOTENDS 1
#endif

#if HOTENDS > MAX_HOTENDS || E_STEPPERS > MAX_HOTENDS
  #error "More extruders configured than supported by this board."
#endif

/**
 * Board name
 */
#define BOARD_NAME "FHNW pro4E Team8"

/**
 * Disables JTAG and SWD
 * (to get more GPIO pins)
 */
// #define DISABLE_DEBUG

/**
 * Display (EXP3, wrongly labeled as EXT3 on the board)
 * Creality LCD (128 x 64 dot matrix)
 */
#define BEEPER_PIN          PE3     // EXP3-1 (J202-1) [LCD_Beeper]

#define BTN_EN1             PE4     // EXP3-5 (J202-5) [LCD_Encoder_A]
#define BTN_EN2             PE5     // EXP3-3 (J202-3) [LCD_Encoder_B]
#define BTN_ENC             PE6     // EXP3-2 (J202-2) [LCD_Encoder_BTN]

#define LCD_PINS_RS         PF1     // J3-9 EXP3-7 (J202-7) [LCD_CS]
#define LCD_PINS_ENABLE     PF2     // EXP3-8 (J202-8) [LCD_MOSI]
#define LCD_PINS_D4         PF3     // EXP3-6 (J202-6) [LCD_SCK]

/**
 * Servos (enables BLTouch support)
 * only two servo headers are present on the board
 * (two more can be configured through the expansion board)
 */
#define SERVO0_PIN          PC3
#define SERVO1_PIN          PA1
// #define SERVO2_PIN          -1
// #define SERVO3_PIN          -1

/**
 * Endstops
 */
#define X_MIN_PIN           -1
#define X_MAX_PIN           -1
#define Y_MIN_PIN           PC5
#define Y_MAX_PIN           -1
#define Z_MIN_PIN           PA4
#define Z_MAX_PIN           -1

/**
 * Steppers
 */
#define X_ENABLE_PIN        PB9
#define X_STEP_PIN          PB8
#define X_DIR_PIN           PB5
#define X_CS_PIN            PB12

#define Y_ENABLE_PIN        PB4
#define Y_STEP_PIN          PG15
#define Y_DIR_PIN           PG10
#define Y_CS_PIN            -1

#define Z_ENABLE_PIN        PD7
#define Z_STEP_PIN          PD3
#define Z_DIR_PIN           PG14
#define Z_CS_PIN            -1

#if defined(EXPANSION_BOARD)
  // #define Z3_ENABLE_PIN       PD7
  // #define Z3_STEP_PIN         PD3
  // #define Z3_DIR_PIN          PG14
  // #define Z3_CS_PIN           -1
#endif

#define E0_ENABLE_PIN       PG13
#define E0_STEP_PIN         PG8
#define E0_DIR_PIN          PA15
#define E0_CS_PIN           -1

#if defined(EXPANSION_BOARD)
  // #define E1_ENABLE_PIN       PA12
  // #define E1_STEP_PIN         PA11
  // #define E1_DIR_PIN          PA8
  // #define E1_CS_PIN           -1

  // #define E2_ENABLE_PIN       PA12
  // #define E2_STEP_PIN         PA11
  // #define E2_DIR_PIN          PA8
  // #define E2_CS_PIN           -1
#endif

/**
 * Temperature sensors
 */
#define TEMP_0_PIN          PC1 // TH1
#if defined(EXPANSION_BOARD)
  // #define TEMP_1_PIN          -1 // TH2
  // #define TEMP_2_PIN          -1 // TH2
#endif
#define TEMP_BED_PIN        PC0 // TB1

/**
 * Heaters / Fans
 */
#define HEATER_0_PIN        PC7 // HEATER1
#if defined(EXPANSION_BOARD)
  // #define HEATER_1_PIN        -1 // HEATER2
  // #define HEATER_2_PIN        -1
#endif
#define HEATER_BED_PIN      PC6 // HOT BED

#define FAN_PIN            PB1 // PA7   // FAN
#if defined(EXPANSION_BOARD)
#endif
// More FANs?
// CONTROLLER_FAN_PIN for the PCB-FAN (PCB-FAN of the expansion board)
// E0_AUTO_FAN_PIN / E1_AUTO_FAN_PIN / E2_AUTO_FAN_PIN
// CHAMBER_AUTO_FAN_PIN

// ToDo: remove unused macros

// #define POWER_LOSS_PIN     -1   // PW_DET
// #define PS_ON_PIN          -1   // PW_OFF

#define FIL_RUNOUT_PIN     PF11  // MT_DET
#if defined(EXPANSION_BOARD)
#endif
// FIL_RUNOUT2_PIN / FIL_RUNOUT3_PIN

#define LED_PIN            PE2


/**
 * SD card (uSD)
 */
#define SD_DETECT_PIN      PF12
#define SDSS               -1 // not required, SDIO interface is used
// #define LCD_SDSS           -1 // not present

/**
 * MKS Robin TFT
 * (FHNW pro4E Team8 board doesn't support this at the moment!)
 * 
 * Note: MKS Robin TFT screens may have different TFT controllers
 * If the screen stays white, disable 'LCD_RESET_PIN' to rely on the bootloader to do screen initialization.
 * 
 * Enabling 'LCD_RESET_PIN' causes flickering when entering the LCD menu due to LCD controller reset.
 * Reset feature was designed to "revive the LCD if static electricity killed it."
 */
#if defined(MKS_ROBIN_TFT)
  // Pin usage (32 pin connector, including supply and NC pins):
  // Data D0-D15 (PD14, PD15, PD0, PD1, PE7-PE15, PD8-PD10)
  // NOE: Read operation (PD4) / NWE: Write operation (PD5)
  // SPI2 (PB13, PB14, PB15) / Unknown (PB1, PC13)
  #define LCD_RESET_PIN       PF6     // Reset
  #define LCD_BACKLIGHT_PIN   PG11    // Backlight
  #define FSMC_CS_PIN         PG12    // NE4 (Chip Select)
  #define FSMC_RS_PIN         PF0     // A0 (LCD Register Select)
#endif
