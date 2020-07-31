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

#include "Mux.h"

using namespace admux;

Mux::Mux(Pinset channelPins, int8_t enablePin, int8_t writePin) :
    m_channelPins(channelPins), m_enablePin(enablePin), m_writePin(writePin) {
  for (int i = 0; i < m_channelPins.size; i++) {
    pinMode(m_channelPins[i], Output);
  }
  m_channelCount = 1 << m_channelPins.size;

  if (IS_DEFINED(enablePin)) {
    pinMode(m_enablePin, Output);
  }
  if (IS_DEFINED(writePin)) {
    pinMode(m_writePin, Output);
  }
}

Mux::Mux(Pin signalPin, Pinset channelPins, int8_t enablePin, int8_t writePin) :
    Mux::Mux(channelPins, enablePin, writePin) {
  Mux::signalPin(signalPin);
}

int16_t Mux::read(int8_t channel) {
  if (IS_DEFINED(channel)) {
    this->channel(channel);
  }

  switch (m_signalPin.type) {
    case Analog:
      return analogRead(m_signalPin.pin);
    case Digital:
      return digitalRead(m_signalPin.pin);
    default:
      return ERROR_UNHANDLED_OPERATION;
  }
}

int8_t Mux::channel(int8_t value) {
  if (value == m_channel)
    return ERROR_SUCCESS;
  else if (value > m_channelCount)
    return ERROR_OUT_OF_RANGE;

  /*
   * NOTE: When WR is low, the channel control pins control which state the
   * switches are in. On the rising edge of WR, the channel control data is
   * latched (see ADG726/ADG732).
   */
  if (IS_DEFINED(m_writePin)) {
    digitalWrite(m_writePin, LOW);
  }
  m_channel = value;
  for (uint8_t i = 0; i < m_channelPins.size; i++) {
    digitalWrite(m_channelPins[i], bitRead(value, i));
  }
  if (IS_DEFINED(m_writePin)) {
    digitalWrite(m_writePin, HIGH);
  }
  return ERROR_SUCCESS;
}

int8_t Mux::enabled(bool value) {
  if (!IS_DEFINED(m_enablePin))
    return ERROR_UNDEFINED_PIN;

  digitalWrite(m_enablePin, m_enabled = value ? LOW : HIGH);
  return ERROR_SUCCESS;
}

int8_t Mux::signalPin(Pin value) {
  // Another pin already assigned to signal?
  /*
   * NOTE: The same mux can be physically connected to multiple (mutually-
   * exclusive) signal pins at once; this function takes care to electrically
   * exclude previously-selected pins.
   */
  if (IS_DEFINED(m_signalPin.pin) && m_signalPin.pin != value.pin) {
    // Put the old signal pin in high impedance state!
    if (m_signalPin.mode == Output) {
      digitalWrite(m_signalPin.pin, LOW);
    }
    pinMode(m_signalPin.pin, Input);
  }

  m_signalPin = value;
  if (m_signalPin.mode == Input) {
    // Disable pullup!
    /* SEE: https://www.arduino.cc/en/Tutorial/DigitalPins */
    digitalWrite(m_signalPin.pin, LOW);
  }
  pinMode(m_signalPin.pin, m_signalPin.mode);
  return ERROR_SUCCESS;
}

int8_t Mux::write(uint8_t data, int8_t channel) {
  if (m_signalPin.mode != Output)
    return ERROR_WRONG_SIGNAL_MODE;

  if (IS_DEFINED(channel)) {
    this->channel(channel);
  }

  switch (m_signalPin.type) {
    case Analog:
#if defined(ARDUINO_ARCH_ESP32)
      ledcWrite(m_signalPin.pin, data);
#else
      analogWrite(m_signalPin.pin, data);
#endif
      break;
    case Digital:
      digitalWrite(m_signalPin.pin, data);
      break;
  }
  return ERROR_SUCCESS;
}
