/**
 * This example demonstrates how to read digital signals
 * It assumes there are push buttons with pullup resistors
 * connected to the 16 channels of the 74HC4067 mux/demux
 * 
 * Author: Nick Lamprianidis (adaptation by Stefano Chizzolini)
 * Project: arduino-ad-mux-lib
 * Version: 1.0
 * Source: https://github.com/stechio/arduino-ad-mux-lib.git
 */

#include "Type4067Mux.h"

// Creates a Type4067Mux instance
// 1st-3rd arguments initialize SIG pin (PIN 3 on the Arduino as digital input).
// 4th-7th arguments are the Arduino PINs to which the S0-S3 pins connect.
Type4067Mux mux(3, INPUT, DIGITAL, 8, 9, 10, 11);

void setup() {
  Serial.begin(9600);  // Initializes serial port
  // Waits for serial port to connect. Needed for Leonardo only
  while (!Serial)
    ;
}

// Reads the 16 channels and reports on the serial monitor
// if the corresponding push button is pressed
void loop() {
  byte data;

  for (byte i = 0; i < 16; ++i) {
    // Reads from channel i and returns HIGH or LOW
    data = mux.read(i);

    Serial.print("Push button at channel ");
    Serial.print(i);
    Serial.print(" is ");
    if (data == HIGH)
      Serial.println("not pressed");
    else if (data == LOW)
      Serial.println("pressed");
  }
  Serial.println();

  delay(1500);
}
