/*
Copyright 2018 Mattia Dal Ben <matthewdibi@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#define PERMISSIVE_HOLD // helps with quick tap/hold actions
#define DOUBLE_TAP_SHIFT_TURNS_ON_CAPS_WORD // double tap shift for caps word
#define UNICODE_SELECTED_MODES UNICODE_MODE_MACOS

//#define SPLIT_USB_DETECT

/* Use I2C or Serial, not both */
#define USE_SERIAL // Just use this one for the Falbatech Redox
/* #define USE_I2C */

/* Select hand configuration */
/* #define MASTER_LEFT */
/* #define MASTER_RIGHT */
#define EE_HANDS

/* This should help with Mac M1 not recognising the board after sleep */
#define USB_SUSPEND_WAKEUP_DELAY 200

#undef RGBLED_NUM
#define RGBLIGHT_ANIMATIONS
#define RGBLED_NUM 14
#define RGBLIGHT_HUE_STEP 8
#define RGBLIGHT_SAT_STEP 8
#define RGBLIGHT_VAL_STEP 8
