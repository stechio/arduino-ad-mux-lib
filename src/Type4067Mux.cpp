/**
 * Project: arduino-ad-mux-lib
 * Version: 1.0
 * Source: https://github.com/stechio/arduino-ad-mux-lib.git
 *
 * Copyright (c) 2018 Stefano Chizzolini
 *
 * License:
 *    This library is licensed under the MIT license
 *    http://www.opensource.org/licenses/mit-license.php
 *
 * Filename: Type4067Mux.cpp
 * Author: Stefano Chizzolini
 */

#include "Type4067Mux.h"

Type4067Mux::Type4067Mux(uint8_t selectionPin0, int8_t selectionPin1,
    int8_t selectionPin2, int8_t selectionPin3) :
    Mux(new int8_t[4] { selectionPin0, selectionPin1, selectionPin2,
        selectionPin3 }, 4) {
}

Type4067Mux::Type4067Mux(uint8_t signalPin, uint8_t signalMode,
    uint8_t signalType, uint8_t selectionPin0, int8_t selectionPin1,
    int8_t selectionPin2, int8_t selectionPin3) :
    Type4067Mux(selectionPin0, selectionPin1, selectionPin2, selectionPin3) {
  setSignalPin(signalPin, signalMode, signalType);
}
