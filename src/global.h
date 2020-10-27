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

#ifndef ADMUX_GLOBAL_H
#define ADMUX_GLOBAL_H

namespace admux {

const int ERROR_SUCCESS = 0;
const int ERROR_WRONG_SIGNAL_MODE = -1;
const int ERROR_UNHANDLED_OPERATION = -2;
const int ERROR_OUT_OF_RANGE = -3;
const int ERROR_UNDEFINED_PIN = -4;

const int8_t UNDEFINED = -1;

inline bool isDefined(int8_t value) {
  return value > UNDEFINED;
}

enum class PinType {
  ANALOG,
  DIGITAL
};

typedef struct Pin {
  int8_t pin;
  uint8_t mode;
  PinType type;

  Pin() :
      Pin(UNDEFINED, OUTPUT, PinType::DIGITAL) {
  }

  Pin(int8_t pin, uint8_t mode, PinType type) :
      pin(pin), mode(mode), type(type) {
  }
} Pin;

typedef struct Pinset {
// @formatter:off
  /*
   * Horribly clumsy constructor, I know, but, willing to support even legacy
   * MCUs, more elegant solutions like std::initializer_list aren't available,
   * alas.
   */
  Pinset(
      uint8_t pin0,
      int8_t pin1 = UNDEFINED,
      int8_t pin2 = UNDEFINED,
      int8_t pin3 = UNDEFINED,
      int8_t pin4 = UNDEFINED,
      int8_t pin5 = UNDEFINED,
      int8_t pin6 = UNDEFINED,
      int8_t pin7 = UNDEFINED
      ){
    pins[0] = pin0;
    pins[1] = pin1;
    pins[2] = pin2;
    pins[3] = pin3;
    pins[4] = pin4;
    pins[5] = pin5;
    pins[6] = pin6;
    pins[7] = pin7;
    for(int i = 0; i < MAX_SIZE; i++) {
      if (!isDefined(pins[i])) {
        m_size = i;
        return;
      }
    }
    m_size = MAX_SIZE;
  }
// @formatter:on

  int8_t operator[](uint8_t index) {
    return pins[index];
  }

  uint8_t size() {
    return m_size;
  }

private:
  static const uint8_t MAX_SIZE = 8;

  int8_t pins[MAX_SIZE];
  uint8_t m_size;
} Pinset;

}

#endif // ADMUX_GLOBAL_H
