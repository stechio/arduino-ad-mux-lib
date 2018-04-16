/**
 * Project: arduino-ad-mux-lib
 * Source: https://github.com/stechio/arduino-ad-mux-lib.git
 *
 * Copyright (c) 2018 Stefano Chizzolini (arduino-ad-mux-lib)
 * Copyright (c) 2014 Nick Lamprianidis (MUX74HC4067)
 *
 * License:
 *    This library is licensed under the MIT license
 *    http://www.opensource.org/licenses/mit-license.php
 *
 * Filename: Mux.cpp
 * Version: 2.0.1
 * Author: Stefano Chizzolini, Nick Lamprianidis
 */

#include "Mux.h"

Mux::Mux(int8_t selectionPins[], uint8_t selectionPinsLength,
    int8_t enablePin) {
  selectionPinsCount = selectionPinsLength;
  for (uint8_t i = 0; i < selectionPinsLength; i++) {
    if (IS_DEFINED(selectionPins[i])) {
      pinMode(this->selectionPins[i] = selectionPins[i], OUTPUT);
    } else {
      selectionPinsCount = i;
      break;
    }
  }
  this->enablePin = enablePin;
}

Mux::Mux(uint8_t signalPin, uint8_t signalMode, uint8_t signalType,
    int8_t selectionPins[], uint8_t selectionPinsLength, int8_t enablePin) :
    Mux::Mux(selectionPins, selectionPinsLength, enablePin) {
  Mux::setSignalPin(signalPin, signalMode, signalType);
}

int16_t Mux::read(int8_t channel) {
  if (IS_DEFINED(channel)) {
    setChannel(channel);
  }

  switch (signalType) {
  case ANALOG:
    return analogRead(signalPin);
  case DIGITAL:
    return digitalRead(signalPin);
  default:
    return -1;
  }
}

int8_t Mux::setChannel(uint8_t value) {
  if (value != channel) {
    channel = value;
    for (uint8_t i = 0; i < selectionPinsCount; i++) {
      digitalWrite(selectionPins[i], value >> i & 0x01);
    }
  }
  return 0;
}

int8_t Mux::setSignalPin(uint8_t pin, uint8_t mode, uint8_t type) {
  // Another pin already assigned to signal?
  /*
   * NOTE: The same mux can be physically connected to multiple (mutually-
   * exclusive) signal pins at once; this function takes care to electrically
   * exclude previously-selected pins.
   */
  if (IS_DEFINED(this->signalPin) && this->signalPin != pin) {
    // Put the old signal pin in high impedance state!
    if (this->signalMode == OUTPUT) {
      digitalWrite(this->signalPin, LOW);
    }
    pinMode(this->signalPin, INPUT);
  }

  switch (mode) {
  case INPUT:
    // Disable pullup!
    /* SEE: https://www.arduino.cc/en/Tutorial/DigitalPins */
    digitalWrite(pin, LOW);
    break;
  case INPUT_PULLUP:
    /* NOOP */
    break;
  case OUTPUT:
    /* NOOP */
    break;
  default:
    mode = OUTPUT;
    break;
  }
  pinMode(this->signalPin = pin, this->signalMode = mode);

  switch (type) {
  case ANALOG:
  case DIGITAL:
    /* NOOP */
    break;
  default:
    type = DIGITAL;
    break;
  }
  this->signalType = type;

  return 0;
}

int8_t Mux::write(uint8_t data, int8_t channel) {
  if (signalMode != OUTPUT)
    return -1;

  if (IS_DEFINED(channel)) {
    setChannel(channel);
  }

  switch (signalType) {
  case ANALOG:
    analogWrite(signalPin, data);
    break;
  case DIGITAL:
    digitalWrite(signalPin, data);
    break;
  }
  return 0;
}
