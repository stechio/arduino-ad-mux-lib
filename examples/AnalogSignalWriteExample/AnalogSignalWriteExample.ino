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
 * Author: Nick Lamprianidis (adaptation by Stefano Chizzolini)
 */

#include "Mux.h"

using namespace admux;

/*
 * Creates a Mux instance.
 *
 * 1st argument is the SIG pin (analog output on Arduino PIN 3).
 * 2nd argument is the Arduino PINs to which channel control pins S0-S3 connect.
 */
Mux mux(Pin(3, Output, Analog), { 8, 9, 10, 11 });

void setup() {
}

/*
 * Writes to the 16 channels a PWM output, one after the other (at each next
 * channel, the duty cycle of the PWM increases).
 */
void loop() {
  for (byte i = 0; i < mux.channelCount(); ++i) {
    // Connects to channel i and outputs a PWM signal.
    mux.write(i * 16 + 1, i);
    delay(200);
  }

  delay(1000);
}
