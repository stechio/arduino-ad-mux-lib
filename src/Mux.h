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
 */

#ifndef Mux_h
#define Mux_h

#include <Arduino.h>
#include "global.h"

namespace admux {

/**
 * Analog/Digital multiplexer of arbitrary channel size.
 */
class Mux {
public:
  /**
   * Creates a Mux instance.
   *
   * @param channelPins
   *      MCU pins to which the mux control pins (S*) connect.
   * @param enablePin
   *      MCU pin to which the mux enable pin (EN) connects.
   * @param writePin
   *      MCU pin to which the mux write pin (WR) connects.
   */
  Mux(Pinset channelPins, int8_t enablePin = UNDEFINED, int8_t writePin =
      UNDEFINED);

  /**
   * Creates a Mux instance.
   *
   * @param signalPin
   *      MCU pin to which the mux signal pin (SG) connects.
   * @param channelPins
   *      MCU pins to which the mux control pins (Sx) connect.
   * @param enablePin
   *      MCU pin to which the mux enable pin (EN) connects.
   * @param writePin
   *      MCU pin to which the mux write pin (WR) connects.
   */
  Mux(Pin signalPin, Pinset channelPins, int8_t enablePin = UNDEFINED,
      int8_t writePin = UNDEFINED);

  /**
   * Current channel.
   */
  int8_t channel() {
    return m_channel;
  }

  /**
   * @return
   *      <ul>
   *        <li>ERROR_SUCCESS, if success</li>
   *        <li>ERROR_OUT_OF_RANGE, if channel beyond the selectable range</li>
   *      </ul>
   */
  int8_t channel(int8_t value);

  /**
   * Range of selectable channels.
   */
  uint8_t channelCount() {
    return m_channelCount;
  }

  /**
   * Reads from the given channel.
   *
   * <p>Side effects: in case the channel argument is defined, it becomes the
   *    current one (same as invoking channel method).</p>
   *
   * @param channel
   *      Channel to read from. Default: current channel.
   * @return
   *      <ul>
   *        <li>{HIGH, LOW}, if signal pin was set to Digital</li>
   *        <li>ADC value, if signal pin was set to Analog</li>
   *      </ul>
   */
  int16_t read(int8_t channel = UNDEFINED);

  /**
   * Whether the mux signal is enabled.
   */
  bool enabled() {
    return m_enabled;
  }

  /**
   * @return
   *      <ul>
   *        <li>ERROR_SUCCESS, if success</li>
   *        <li>ERROR_UNDEFINED_PIN, if enablePin undefined</li>
   *      </ul>
   */
  int8_t enabled(bool value);

  Pin signalPin() {
    return m_signalPin;
  }

  /**
   * As the same mux can be physically connected to multiple (mutually-
   * exclusive) signal pins at once, this function takes care to electrically
   * exclude previously-assigned signal pins.
   *
   * @return ERROR_SUCCESS, if success.
   */
  int8_t signalPin(Pin value);

  /**
   * As the same mux can be physically connected to multiple (mutually-
   * exclusive) signal pins at once, this function takes care to electrically
   * exclude previously-assigned signal pins.
   *
   * @param pin
   *      MCU pin to which the mux signal pin connects.
   * @param mode
   *      MCU signal mode.
   * @param type
   *      MCU signal type.
   * @return ERROR_SUCCESS, if success.
   */
  int8_t signalPin(int8_t pin, PinMode mode, PinType type) {
    return signalPin(Pin(pin, mode, type));
  }

  /**
   * Writes to the given channel.
   *
   * <p>Side effects: in case the channel argument is defined, it becomes the
   *    current one (same as invoking channel method).</p>
   *
   * @param data
   *      Data to write to channel:
   *      <ul>
   *        <li>{HIGH, LOW}, if signal pin was set to Digital</li>
   *        <li>PWM value, if signal pin was set to Analog</li>
   *      </ul>
   * @param channel
   *      Channel to write to (Default: current channel).
   * @return
   *      <ul>
   *        <li>ERROR_SUCCESS, if success</li>
   *        <li>ERROR_WRONG_SIGNAL_MODE, if signal mode isn't OUTPUT</li>
   *      </ul>
   */
  int8_t write(uint8_t data, int8_t channel = UNDEFINED);

protected:
  int8_t m_channel = UNDEFINED;
  uint8_t m_channelCount;
  Pinset m_channelPins;
  bool m_enabled = true;
  int8_t m_enablePin = UNDEFINED;
  Pin m_signalPin;
  int8_t m_writePin = UNDEFINED;
};

}

#endif // Mux_h
