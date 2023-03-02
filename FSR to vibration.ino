#include <Wire.h>
#include <Adafruit_DRV2605.h>

// Pins definition
#define FSR_PIN A0

// Global variables
Adafruit_DRV2605 drv;
int fsrReading;
int vibrationStrength;

void setup() {
  // Initialize serial communication
  Serial.begin(9600);

  // Initialize the DRV2605 library
  drv.begin();
  drv.selectLibrary(1);
  drv.setMode(DRV2605_MODE_INTTRIG);

  // Wait a bit before starting
  delay(100);
}

void loop() {
  // Read the FSR reading
  fsrReading = analogRead(FSR_PIN);

  // Convert the FSR reading to vibration strength
  vibrationStrength = map(fsrReading, 0, 1023, 0, 255);

  // Send the vibration strength to the DRV2605 output pin
  drv.setWaveform(0, vibrationStrength);
  drv.go();

  // Display the FSR reading and the vibration strength
  Serial.print("FSR Reading: ");
  Serial.print(fsrReading);
  Serial.print(" - Vibration Strength: ");
  Serial.println(vibrationStrength);

  // Wait a bit before the next reading
  delay(1000);
}
