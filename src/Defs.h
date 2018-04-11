/**
 * Project: arduino-ad-mux-lib
 * Source: https://github.com/stechio/arduino-ad-mux-lib.git
 *
 * Copyright (c) 2018 Stefano Chizzolini
 *
 * License:
 *    This library is licensed under the MIT license
 *    http://www.opensource.org/licenses/mit-license.php
 *
 * Filename: Defs.h
 * Version: 2.0
 * Author: Stefano Chizzolini
 */

#ifndef arduino_ad_mux_lib_Defs_h
#define arduino_ad_mux_lib_Defs_h

#define ANALOG 0
#define DIGITAL 1

#define DISABLED 0
#define ENABLED 1

/*
 * Undefined value.
 */
#define UNDEFINED -1

/*
 * Macro: whether value argument is defined (assuming natural integers as valid
 * domain).
 */
#define IS_DEFINED(x) x >= 0

#endif
