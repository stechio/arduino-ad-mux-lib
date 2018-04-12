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
 * Filename: Series4000Mux.h
 * Version: 2.0
 * Author: Stefano Chizzolini
 */

#ifndef Series4000Mux_h
#define Series4000Mux_h

#include <Arduino.h>
#include <Mux.h>

class Series4000Mux: public Mux {
public:
  /*
   * Creates a Series4000Mux instance.
   *
   * Arguments:
   *    selectionPins - MCU pins to which the mux selection pins connect.
   *    selectionPinsLength - MCU pins array size.
   *    enablePin - (Optional) MCU pin to which the mux enable pin connects.
   */
  Series4000Mux(int8_t selectionPins[], uint8_t selectionPinsLength,
      int8_t enablePin = UNDEFINED);

  /*
   * Creates a Series4000Mux instance.
   *
   * Arguments:
   *    signalPin - MCU pin to which the mux signal pin connects.
   *    signalMode - {INPUT, OUTPUT, INPUT_PULLUP}
   *    signalType - {DIGITAL, ANALOG}
   *    selectionPins - MCU pins to which the mux selection pins connect.
   *    selectionPinsLength - MCU pins array size.
   *    enablePin - (Optional) MCU pin to which the mux enable pin connects.
   */
  Series4000Mux(uint8_t signalPin, uint8_t signalMode, uint8_t signalType,
      int8_t selectionPins[], uint8_t selectionPinsLength, int8_t enablePin =
      UNDEFINED);

  // (Override)
  int8_t setEnabled(bool value);

private:
};

#endif
