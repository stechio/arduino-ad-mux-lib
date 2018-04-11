/**
 * This example demonstrates how to write digital signals.
 *
 * It assumes there are LEDs+resistors with the positive lead of the LEDs
 * connected to the 16 channels of the 74HC4067 mux, respectively.
 * 
 * ------------------------------------------------------------
 * Project: arduino-ad-mux-lib
 * Source: https://github.com/stechio/arduino-ad-mux-lib.git
 *
 * Filename: DigitalSignalWriteExample.ino
 * Version: 1.0
 * Author: Nick Lamprianidis (adaptation by Stefano Chizzolini)
 */

#include "Type4067Mux.h"

/*
 * Creates a Type4067Mux instance.
 *
 * 1st-3rd arguments initialize SIG pin (digital output on Arduino PIN 3).
 * 4th-7th arguments are the Arduino PINs to which the S0-S3 pins connect.
 */
Type4067Mux mux(3, OUTPUT, DIGITAL, 8, 9, 10, 11);

void setup() {
}

/*
 * Writes to the 16 channels a HIGH value, one after the other.
 */
void loop() {
  for (byte i = 0; i < 16; ++i) {
    // Connects to channel i and writes HIGH.
    mux.write(HIGH, i);
    delay(25);
  }

  delay(800);
}
