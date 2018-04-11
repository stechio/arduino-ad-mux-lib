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
 * Filename: AnalogSignalReadExample.ino
 * Version: 1.0
 * Author: Nick Lamprianidis (adaptation by Stefano Chizzolini)
 */

#include "Type4067Mux.h"

/*
 * Creates a Type4067Mux instance.
 *
 * 1st-3rd arguments initialize SIG pin (analog input on Arduino PIN A0).
 * 4th-7th arguments are the Arduino PINs to which the S0-S3 pins connect.
 */
Type4067Mux mux(A0, INPUT, ANALOG, 8, 9, 10, 11);

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
  for (byte i = 0; i < 16; ++i) {
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
