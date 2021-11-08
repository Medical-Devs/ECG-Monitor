#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include "HeartSpeed.h"

RF24 radio(7, 8);
const int heartPin = A1;
const byte address[6] = "00001";

void setup() {
  Serial.begin(115200);
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MIN);
  radio.stopListening();
}

void loop() {
  int heartValue = analogRead(heartPin);
  Serial.println(heartValue);
  radio.write(&heartValue, sizeof(heartValue));
  delay(5);
}
