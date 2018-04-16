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
 * Filename: Series4000Mux.cpp
 * Version: 2.0.1
 * Author: Stefano Chizzolini
 */

#include "Series4000Mux.h"

Series4000Mux::Series4000Mux(int8_t selectionPins[],
    uint8_t selectionPinsLength, int8_t enablePin) :
    Mux(selectionPins, selectionPinsLength, enablePin) {
}

Series4000Mux::Series4000Mux(uint8_t signalPin, uint8_t signalMode,
    uint8_t signalType, int8_t selectionPins[], uint8_t selectionPinsLength,
    int8_t enablePin) :
    Mux(signalPin, signalMode, signalType, selectionPins, selectionPinsLength,
        enablePin) {
}

int8_t Series4000Mux::setEnabled(bool value) {
  if (IS_DEFINED(enablePin)) {
    digitalWrite(enablePin, enabled = value ? LOW : HIGH);
  }
  return 0;
}
