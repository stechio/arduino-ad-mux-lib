/**
 * Project: arduino-ad-mux-lib
 * Version: 1.0
 * Source: https://github.com/stechio/arduino-ad-mux-lib.git
 *
 * Copyright (c) 2018 Stefano Chizzolini (arduino-ad-mux-lib)
 * Copyright (c) 2014 Nick Lamprianidis (MUX74HC4067)
 *
 * License:
 *    This library is licensed under the MIT license
 *    http://www.opensource.org/licenses/mit-license.php
 *
 * Filename: Mux.h
 * Author: Stefano Chizzolini, Nick Lamprianidis
 */

#ifndef Mux_h
#define Mux_h

#include <Arduino.h>

#define ANALOG 0
#define DIGITAL 1

/*
 * Undefined index value.
 */
#define UNDEFINED -1

/*
 * Macro: whether index value is defined (assuming natural integers as valid domain).
 */
#define IS_VALID_INDEX(x) x >= 0

class Mux {
public:
  /*
   * Creates a Mux instance.
   *
   * Arguments:
   *    selectionPins - MCU pins to which the mux selection pins connect.
   *    selectionPinsLength - MCU pins array size.
   */
  Mux(int8_t selectionPins[], uint8_t selectionPinsLength);

  /*
   * Creates a Mux instance.
   *
   * Arguments:
   *    signalPin - MCU pin to which the mux signal pin connects.
   *    signalMode - {INPUT, OUTPUT, INPUT_PULLUP}
   *    signalType - {DIGITAL, ANALOG}
   *    selectionPins - MCU pins to which the mux selection pins connect.
   *    selectionPinsLength - MCU pins array size.
   */
  Mux(uint8_t signalPin, uint8_t signalMode, uint8_t signalType,
      int8_t selectionPins[], uint8_t selectionPinsLength);

  /*
   * Reads from the given channel.
   *
   * Arguments:
   *    channel - (Optional) Channel to read from. Default: current channel.
   *
   * Returns:
   *    {HIGH, LOW} - if the signal pin was set to DIGITAL.
   *    ADC value - if the signal pin was set to ANALOG.
   *    {-1} - if the signal pin wasn't set.
   *
   *  Side effects: in case the channel argument is defined, it becomes the current one
   *  (same as invoking setChannel method).
   */
  int16_t read(int8_t channel = UNDEFINED);

  /*
   * Selects the given channel.
   *
   * Arguments:
   *    value - Channel to select.
   */
  void setChannel(uint8_t value);

  /*
   * Configures the signal pin.
   *
   * As the same mux can be physically connected to multiple (mutually-exclusive)
   * signal pins at once, this function takes care to electrically exclude
   * previously-assigned signal pins.
   *
   * Arguments:
   *    pin - MCU pin to which the mux signal pin connects.
   *    mode - {INPUT, OUTPUT, INPUT_PULLUP}
   *    type - {DIGITAL, ANALOG}
   */
  void setSignalPin(uint8_t pin, uint8_t mode, uint8_t type);

  /*
   * Writes to the given channel.
   *
   * Arguments:
   *    data - Data to write to channel:
   *      {HIGH, LOW} - if the signal pin was set to DIGITAL.
   *      PWM value - if the signal pin was set to ANALOG.
   *    channel - (Optional) Channel to write to. Default: current channel.
   *
   *  Returns:
   *    {0} - if write succeeded.
   *    {-1} - if signal pin wasn't set to OUTPUT mode.
   *
   *  Side effects: in case the channel argument is defined, it becomes the current one
   *  (same as invoking setChannel method).
   */
  uint8_t write(uint8_t data, int8_t channel = UNDEFINED);

private:
  /*
   * Current mux channel.
   */
  int8_t channel = UNDEFINED;
  /*
   * MCU selection pins.
   */
  /*
   * NOTE: Fixed size, as dynamic allocation's overhead exceeds possible memory gains;
   * the actual number of pins is defined by selectionPinsCount field.
   */
  uint8_t selectionPins[4];
  /*
   * MCU selection pins count.
   */
  uint8_t selectionPinsCount;
  /*
   * MCU signal mode ({INPUT, OUTPUT, INPUT_PULLUP}).
   */
  int8_t signalMode = UNDEFINED;
  /*
   * MCU signal pin.
   */
  int8_t signalPin = UNDEFINED;
  /*
   * MCU signal type ({DIGITAL, ANALOG}).
   */
  int8_t signalType = UNDEFINED;
};

#endif
