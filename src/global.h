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
#define IS_DEFINED(x) (x > UNDEFINED)

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

typedef struct Pinset {
  static const int MAX_SIZE = 8;

  int8_t pins[MAX_SIZE];
  uint8_t size;

  /*
   * Horribly clumsy, I know, but, willing to support even legacy MCUs, more
   * elegant solutions like std::initializer_list aren't available, alas.
   */
  Pinset(
      uint8_t pin0,
      int8_t pin1 = UNDEFINED,
      int8_t pin2 = UNDEFINED,
      int8_t pin3 = UNDEFINED,
      int8_t pin4 = UNDEFINED,
      int8_t pin5 = UNDEFINED,
      int8_t pin6 = UNDEFINED,
      int8_t pin7 = UNDEFINED,
      int8_t pin8 = UNDEFINED
      ){
    pins[0] = pin0;
    pins[1] = pin1;
    pins[2] = pin2;
    pins[3] = pin3;
    pins[4] = pin4;
    pins[5] = pin5;
    pins[6] = pin6;
    pins[7] = pin7;
    pins[8] = pin8;
    for(int i = 0; i < MAX_SIZE; i++) {
      if (!IS_DEFINED(pins[i])) {
        size = i;
        return;
      }
    }
    size = MAX_SIZE;
  }

  uint8_t operator[](int index) {
    return pins[index];
  }
} Pinset;

}
// @formatter:on

#endif // arduino_ad_mux_lib_global_h
