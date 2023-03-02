// Marche dans un sens mais les vibrations sont plus fortes et peuvent être contrôlées 

#include <Wire.h>
#include <Adafruit_DRV2605.h>

Adafruit_DRV2605 drv;

void setup() {
  Wire.begin();
  drv.begin();
  drv.selectLibrary(1);
  drv.setMode(DRV2605_MODE_INTTRIG);
  Serial.begin(9600);
}

void loop() {
  int piezoReading = analogRead(A0);
  Serial.println(piezoReading);
  int strength = map(piezoReading, 0, 1023, 0, 10); // à la place du 10 : 127 mais les vibrations sont plus fortes quand l'on se rapproche de 0 
  drv.setWaveform(0, strength);
  drv.go();

  //Serial.print("Piezo strength: ");
  //Serial.println(strength);

  delay(10);
}
