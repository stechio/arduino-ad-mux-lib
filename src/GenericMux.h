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
 * Filename: GenericMux.h
 * Version: 2.0
 * Author: Stefano Chizzolini
 */

#ifndef GenericMux_h
#define GenericMux_h

#include <Arduino.h>
#include <Mux.h>

class GenericMux: public Mux {
public:
  /*
   * Creates a GenericMux instance.
   *
   * Arguments:
   *    selectionPin0 - MCU pin to which the mux selection pin S0 connects.
   *    selectionPin1-selectionPin3 - (Optional) MCU pins to which the mux
   *        selection pins S1-S3 connect.
   */
  GenericMux(uint8_t selectionPin0, int8_t selectionPin1 = UNDEFINED,
      int8_t selectionPin2 = UNDEFINED, int8_t selectionPin3 = UNDEFINED);

  /*
   * Creates a GenericMux instance.
   *
   * Arguments:
   *    signalPin - MCU pin to which the mux signal pin Z connects.
   *    signalMode - {INPUT, OUTPUT, INPUT_PULLUP}
   *    signalType - {DIGITAL, ANALOG}
   *    selectionPin0 - MCU pin to which the mux selection pin S0 connects.
   *    selectionPin1-selectionPin3 - (Optional) MCU pins to which the mux
   *        selection pins S1-S3 connect.
   */
  GenericMux(uint8_t signalPin, uint8_t signalMode, uint8_t signalType,
      uint8_t selectionPin0, int8_t selectionPin1 = UNDEFINED,
      int8_t selectionPin2 = UNDEFINED, int8_t selectionPin3 = UNDEFINED);

  // (Override)
  int8_t setEnabled(bool value);

private:
};

#endif
