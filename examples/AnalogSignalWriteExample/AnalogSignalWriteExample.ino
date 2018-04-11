/**
 * This example demonstrates how to write PWM signals.
 *
 * It assumes there are LEDs+resistors with the positive lead of the LEDs
 * connected to the 16 channels of the 74HC4067 mux, respectively.
 * 
 * ------------------------------------------------------------
 * Project: arduino-ad-mux-lib
 * Source: https://github.com/stechio/arduino-ad-mux-lib.git
 *
 * Filename: AnalogSignalWriteExample.ino
 * Version: 1.0
 * Author: Nick Lamprianidis (adaptation by Stefano Chizzolini)
 */

#include "Type4067Mux.h"

/*
 * Creates a Type4067Mux instance.
 *
 * 1st-3rd arguments initialize SIG pin (analog output on Arduino PIN 3).
 * 4th-7th arguments are the Arduino PINs to which the S0-S3 pins connect.
 */
Type4067Mux mux(3, OUTPUT, ANALOG, 8, 9, 10, 11);

void setup() {
}

/*
 * Writes to the 16 channels a PWM output, one after the other (at each next
 * channel, the duty cycle of the PWM increases).
 */
void loop() {
  for (byte i = 0; i < 16; ++i) {
    // Connects to channel i and outputs a PWM signal.
    mux.write(i * 16 + 1, i);
    delay(200);
  }

  delay(1000);
}
