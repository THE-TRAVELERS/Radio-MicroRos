#include "Arduino.h"
#include "RF24.h"
#include "nRF24L01.h"
#include <SPI.h>

RF24 radio(4, 5);
const uint64_t adresse = 0x1111111111;

// Define the same struct to receive data
struct DataPacket {
  int8_t value1;
  int8_t value2;
};

void setup() {
  Serial.begin(115200);
  Serial.println("Récepteur RF24");
  radio.begin();
  radio.openReadingPipe(1, adresse);
  radio.startListening();
}

void loop() {
  if (radio.available()) {
    DataPacket data;
    radio.read(&data, sizeof(data));

    Serial.print("Reçu: ");
    Serial.print(data.value1);
    Serial.print(", ");
    Serial.println(data.value2);
  }
}
