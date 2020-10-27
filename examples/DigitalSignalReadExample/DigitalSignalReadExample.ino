/**
 * This example demonstrates how to read digital signals.
 *
 * It assumes there are push buttons with pullup resistors connected to the 16
 * channels of the 74HC4067 mux.
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
 * 1st argument is the SIG (signal) pin (Arduino digital input pin 3).
 * 2nd argument is the S0-S3 (channel control) pins (Arduino pins 8, 9, 10, 11).
 */
Mux mux(Pin(3, INPUT, PinType::Digital), Pinset(8, 9, 10, 11));

void setup() {
  // Initializes serial port.
  Serial.begin(9600);
  // Waits for serial port to connect (needed for Leonardo only).
  while (!Serial)
    ;
}

/*
 * Reads the 16 channels and reports on the serial monitor if the corresponding
 * push button is pressed.
 */
void loop() {
  byte data;
  for (byte i = 0; i < mux.channelCount(); ++i) {
    // Reads from channel i and returns HIGH or LOW.
    data = mux.read(i);

    Serial.print("Push button at channel ");
    Serial.print(i);
    Serial.print(" is ");
    if (data == HIGH) {
      Serial.println("not pressed");
    } else if (data == LOW) {
      Serial.println("pressed");
    }
  }
  Serial.println();

  delay(1500);
}
