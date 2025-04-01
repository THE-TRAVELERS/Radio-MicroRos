#include "RF24.h"
#include "nRF24L01.h"
#include <Arduino.h>
#include <SPI.h>

RF24 radio(4, 5);
const uint64_t adresse = 0x1111111111;

// Define a struct with two int8_t variables
struct DataPacket {
  int8_t value1;
  int8_t value2;
};

void setup() {
  Serial.begin(115200);
  Serial.println("Émetteur RF24");
  radio.begin();
  radio.openWritingPipe(adresse);
}

void loop() {
  static int8_t compteur1 = 0;
  static int8_t compteur2 = 100; // Example values

  DataPacket data = {compteur1++,
                     compteur2--}; // Increment and decrement values

  Serial.print("Envoi: ");
  Serial.print(data.value1);
  Serial.print(", ");
  Serial.println(data.value2);

  radio.write(&data, sizeof(data)); // Send struct data

  delay(5000);
}
