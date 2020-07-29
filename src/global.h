/**
 * Project: arduino-ad-mux-lib
 * Source: https://github.com/stechio/arduino-ad-mux-lib.git
 *
 * Copyright (c) 2018 Stefano Chizzolini
 *
 * License:
 *    This library is licensed under the MIT license
 *    http://www.opensource.org/licenses/mit-license.php
 */

#ifndef arduino_ad_mux_lib_global_h
#define arduino_ad_mux_lib_global_h

/*
 * Undefined value.
 */
#define UNDEFINED -1

/*
 * Macro: whether value argument is defined (assuming natural integers as valid
 * domain).
 */
#define IS_DEFINED(x) x > UNDEFINED

// @formatter:off
namespace admux {

const int ERROR_SUCCESS = 0;
const int ERROR_WRONG_SIGNAL_MODE = -1;
const int ERROR_UNHANDLED_OPERATION = -2;
const int ERROR_OUT_OF_RANGE = -3;
const int ERROR_UNDEFINED_PIN = -4;

typedef enum {
  Input = INPUT,
  InputPullup = INPUT_PULLUP,
  Output = OUTPUT
} PinMode;

typedef enum {
  Analog,
  Digital
} PinType;

typedef struct Pin {
  PinMode mode;
  int8_t pin;
  PinType type;

  Pin() : Pin(UNDEFINED, Output, Digital) {
  }

  Pin(int8_t pin, PinMode mode, PinType type)
      : pin(pin), mode(mode), type(type) {
  }
} Pin;

} // @formatter:on

#endif // arduino_ad_mux_lib_global_h
