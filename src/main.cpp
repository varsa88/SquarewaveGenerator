/*
 * File: main.cpp
 * Project: SquarewaveGenerator
 * Description: This program generates a square wave signal using Timer1 on an Arduino.
 *              The frequency of the square wave can be adjusted via serial input.
 * Author: Daniel Ohlsson
 */

#include <Arduino.h>
#include <TimerOne.h>

// Pin configuration and constants
#define OUTPUT_PIN 9                // Pin used for PWM output
#define MULTIPLIER 1                // Multiplier for frequency adjustment
#define INIT_US 10000               // Initial period in microseconds
#define MICROSECONDS_PER_SECOND 1000000 // Constant for microseconds in a second
#define MIN_FREQUENCY 1             // Minimum allowed frequency
#define MAX_FREQUENCY 10000         // Maximum allowed frequency (example)

int incomingByte = 5;               // Variable to store incoming serial data
unsigned long k = 512;              // PWM duty cycle (0-1023)

void setup() {
  Serial.begin(9600);               // Initialize serial communication at 9600 baud
  pinMode(OUTPUT_PIN, OUTPUT);      // Set OUTPUT_PIN as output
  Timer1.initialize(INIT_US);       // Initialize Timer1 with initial period
  Timer1.pwm(OUTPUT_PIN, k);        // Start PWM on OUTPUT_PIN with duty cycle k
}

void loop() {
  unsigned long us;                 // Variable for microseconds (period)
  float freq;                       // Variable for frequency in Hz

  if (Serial.available() > 0) {     // Check if data is available on serial
    incomingByte = Serial.parseInt(); // Parse integer from serial input

    // Validate the input frequency
    if (incomingByte < MIN_FREQUENCY || incomingByte > MAX_FREQUENCY) {
      Serial.println("Error: Frequency out of range. Enter a value between 1 and 10000 Hz.");
      return;
    }

    // Calculate frequency and period based on incoming data
    freq = incomingByte * MULTIPLIER;
    us = MICROSECONDS_PER_SECOND / freq;

    // Print received data and calculated values to serial monitor
    Serial.print("Received frequency: ");
    Serial.println(freq, 2);
    Serial.print("Calculated period (us): ");
    Serial.println(us);

    if (incomingByte == 0) {        // Stop PWM if input is 0
      Timer1.stop();                // Stop Timer1
      digitalWrite(OUTPUT_PIN, HIGH); // Set OUTPUT_PIN to HIGH
    } else {                        // Update Timer1 with new period and restart PWM
      Timer1.initialize(us);        // Set new period in microseconds
      Timer1.pwm(OUTPUT_PIN, k);    // Restart PWM with duty cycle k
    }
  }
}