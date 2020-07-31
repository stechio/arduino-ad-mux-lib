/**
 * This example demonstrates how to read analog signals.
 *
 * It assumes there are potentiometers connected to the 16 channels of the
 * 74HC4067 mux.
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
 * 1st argument is the SIG (signal) pin (Arduino analog input pin A0).
 * 2nd argument is the S0-S3 (channel control) pins (Arduino pins 8, 9, 10, 11).
 */
Mux mux(Pin(A0, Input, Analog), Pinset(8, 9, 10, 11));

void setup() {
  // Initializes serial port.
  Serial.begin(9600);
  // Waits for serial port to connect (needed for Leonardo only).
  while (!Serial)
    ;
}

/*
 * Reads the 16 channels and reports on the serial monitor the corresponding
 * value read by the A/D converter.
 */
void loop() {
  int data;
  for (byte i = 0; i < mux.channelCount(); ++i) {
    // Reads from channel i (returns a value from 0 to 1023).
    data = mux.read(i);

    Serial.print("Potentiometer at channel ");
    Serial.print(i);
    Serial.print(" is at ");
    Serial.print((double) (data) * 100 / 1023);
    Serial.println("%%");
  }
  Serial.println();

  delay(1500);
}
