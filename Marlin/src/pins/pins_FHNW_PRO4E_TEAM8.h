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
 */

#ifndef __STM32F1__
  #error "Oops! Select an STM32F1 board in 'Tools > Board.'"
#endif

#if HOTENDS > 2 || E_STEPPERS > 2
  #error "Max. 2 extruders supported."
#endif

#define BOARD_NAME "FHNW pro4E Team8"

//
// Release PB4 (Y_ENABLE_PIN) from JTAG NRST role
//
// #define DISABLE_DEBUG

//
// Servos
//
#define SERVO0_PIN         PC3   // XS1 - 5
#define SERVO1_PIN         PA1   // XS1 - 6
#define SERVO2_PIN         PF9   // XS2 - 5
#define SERVO3_PIN         PF8   // XS2 - 6

//
// Limit Switches
//
#define X_MIN_PIN          -1 // PB12
#define X_MAX_PIN          PB0
#define Y_MIN_PIN          PC5
#define Y_MAX_PIN          PC4
#define Z_MIN_PIN          PA4
#define Z_MAX_PIN          PF7

//
// Steppers
//
#define X_ENABLE_PIN       PB9
#define X_STEP_PIN         PB8
#define X_DIR_PIN          PB5
#define X_CS_PIN           PB12 // PD8

#define Y_ENABLE_PIN       PB4
#define Y_STEP_PIN         PG15
#define Y_DIR_PIN          PG10
//#define Y_CS_PIN           PC2

#define Z_ENABLE_PIN       PD7
#define Z_STEP_PIN         PD3
#define Z_DIR_PIN          PG14
//#define Z_CS_PIN           PC2

// #define Z3_ENABLE_PIN      PD7
// #define Z3_STEP_PIN        PD3
// #define Z3_DIR_PIN         PG14
// #define Z3_CS_PIN          

#define E0_ENABLE_PIN      PG13
#define E0_STEP_PIN        PG8
#define E0_DIR_PIN         PA15
//#define E0_CS_PIN          PC2

// #define E1_ENABLE_PIN      PA12
// #define E1_STEP_PIN        PA11
// #define E1_DIR_PIN         PA8
// #define E1_CS_PIN          

//
// Temperature Sensors
//
#define TEMP_0_PIN         PC1   // TH1
// #define TEMP_1_PIN         PC2   // TH2
#define TEMP_BED_PIN       PC0   // TB1

//
// Heaters / Fans
//
#define HEATER_0_PIN       PC7   // HEATER1
// #define HEATER_1_PIN       PA6   // HEATER2
#define HEATER_BED_PIN     PC6   // HOT BED

#define FAN_PIN            PB1 // PA7   // FAN
// second FAN?

// ToDo: remove unused macros

/**
 * Note: MKS Robin board is using SPI2 interface. Make sure your stm32duino library is configured accordingly
 */
//#define MAX6675_SS_PIN     PE5  // TC1 - CS1
//#define MAX6675_SS_PIN     PE6  // TC2 - CS2

// #define POWER_LOSS_PIN     PA2   // PW_DET
// #define PS_ON_PIN          PA3   // PW_OFF
#define FIL_RUNOUT_PIN     PF11  // MT_DET

#define BEEPER_PIN         PC13
#define LED_PIN            PE2

/**
 * Note: MKS Robin TFT screens may have different TFT controllers
 * If the screen stays white, disable 'LCD_RESET_PIN' to rely on the bootloader to do screen initialization.
 *
 * Enabling 'LCD_RESET_PIN' causes flickering when entering the LCD menu due to LCD controller reset.
 * Reset feature was designed to "revive the LCD if static electricity killed it."
 */
//#define LCD_RESET_PIN      PF6
//#define LCD_BACKLIGHT_PIN  PG11
//#define FSMC_CS_PIN        PG12  // NE4
//#define FSMC_RS_PIN        PF0   // A0

//#define SD_DETECT_PIN      PF12
//#define SDSS               -1
