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
 * Filename: Type4067Mux.cpp
 * Version: 2.0
 * Author: Stefano Chizzolini
 */

#include "Type4067Mux.h"

Type4067Mux::Type4067Mux(uint8_t selectionPin0, int8_t selectionPin1,
    int8_t selectionPin2, int8_t selectionPin3, int8_t enablePin) :
    Series4000Mux(new int8_t[4] { selectionPin0, selectionPin1, selectionPin2,
        selectionPin3 }, 4, enablePin) {
}

Type4067Mux::Type4067Mux(uint8_t signalPin, uint8_t signalMode,
    uint8_t signalType, uint8_t selectionPin0, int8_t selectionPin1,
    int8_t selectionPin2, int8_t selectionPin3, int8_t enablePin) :
    Type4067Mux(selectionPin0, selectionPin1, selectionPin2, selectionPin3,
        enablePin) {
  setSignalPin(signalPin, signalMode, signalType);
}
