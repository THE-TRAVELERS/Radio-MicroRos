#include "RF24.h"
#include "nRF24L01.h"
#include <Arduino.h>
#include <SPI.h>

int compteur = 0;

RF24 radio(4, 5);
const uint64_t addresse = 0x1111111111;
const int taille = 32;
char message[taille + 1];

void setup(void) {
  Serial.begin(115200);
  Serial.println("Emetteur de donnees");
  radio.begin();
  radio.openWritingPipe(addresse);
}

void loop(void) {
  compteur++;
  itoa(compteur, message, 10);
  Serial.print("J'envoie maintenant "); // pour débogage
  Serial.println(message);

  radio.write(message, taille); // émission du message via nRF24L01

  delay(5000);
}
