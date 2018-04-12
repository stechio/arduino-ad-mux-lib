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
 * Filename: GenericMux.cpp
 * Version: 2.0
 * Author: Stefano Chizzolini
 */

#include "GenericMux.h"

GenericMux::GenericMux(uint8_t selectionPin0, int8_t selectionPin1,
    int8_t selectionPin2, int8_t selectionPin3) :
    Mux(new int8_t[4] { selectionPin0, selectionPin1, selectionPin2,
        selectionPin3 }, 4) {
}

GenericMux::GenericMux(uint8_t signalPin, uint8_t signalMode,
    uint8_t signalType, uint8_t selectionPin0, int8_t selectionPin1,
    int8_t selectionPin2, int8_t selectionPin3) :
    GenericMux(selectionPin0, selectionPin1, selectionPin2, selectionPin3) {
  setSignalPin(signalPin, signalMode, signalType);
}

int8_t GenericMux::setEnabled(bool value) {
  /* NOOP: Unsupported operation. */
  return -1;
}
