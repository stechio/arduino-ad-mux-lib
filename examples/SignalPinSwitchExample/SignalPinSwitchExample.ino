/**
 * This example demonstrates how to combine reading inputs and writing outputs,
 * whether they are digital or analog.
 *
 * It assumes there are 2 push buttons with pullup resistors connected to
 * channels C0 and C1, 2 potentiometers connected to channels C2 and C3, and 4
 * LEDs+resistors with the positive lead of the LEDs connected to channels C4
 * to C7.
 *
 * PIN A0 is used for reading the inputs and should connect to the SIG pin; PIN
 * 3 is used for writing the outputs and should connect to the SIG pin.
 *
 * NOTE: Connecting both PIN A0 and PIN 3 to the SIG pin won't create a problem
 * because setSignalPin() method takes care to declare unused pins as inputs
 * putting them in a high impedance state.
 * 
 * ------------------------------------------------------------
 * Project: arduino-ad-mux-lib
 * Source: https://github.com/stechio/arduino-ad-mux-lib.git
 *
 * Filename: SignalPinSwitchExample.ino
 * Version: 1.0
 * Author: Nick Lamprianidis (adaptation by Stefano Chizzolini)
 */

#include "Type4067Mux.h"

/*
 * Creates a Type4067Mux instance.
 *
 * 1st-3rd arguments are the Arduino PINs to which the S0-S2 pins connect: only
 * channels C0-C7 are used, so pin S3 should connect to GND.
 */
Type4067Mux mux(7, 8, 9);

void setup() {
}

/*
 * Reads the state of the push buttons and the potentiometers and outputs to
 * the LEDs a corresponding value:
 *   * HIGH is the buttons are pressed, LOW otherwise;
 *   * PWM signal with duty cycle that depends on the potentiometers' position.
 */
void loop() {
  int data[4];

  // Reads the 2 push buttons at channels C0 and C1.
  mux.setSignalPin(A0, INPUT, DIGITAL);
  for (byte i = 0; i < 2; ++i) {
    data[i] = mux.read(i);
  }

  // Reads the 2 potentiometers at channels C2 and C3.
  mux.setSignalPin(A0, INPUT, ANALOG);
  for (byte i = 2; i < 4; ++i) {
    data[i] = mux.read(i);
  }

  // Writes to the 2 LEDs at channels C4 and C5 HIGH or LOW according to the state of the push buttons.
  mux.setSignalPin(3, OUTPUT, DIGITAL);
  for (byte i = 0; i < 2; ++i) {
    mux.write(!data[i], i + 4);
    delay(300);
  }

  // Outputs a PWM signal to the 2 LEDs at channels C6 and C7 according to the position of the potentiometers.
  mux.setSignalPin(3, OUTPUT, ANALOG);
  for (byte i = 2; i < 4; ++i) {
    mux.write(data[i], i + 4);
    delay(300);
  }
}
