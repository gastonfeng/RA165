#include <Arduino.h>
#include <RA165.h>

RA165 shiftRegIn(12,11);

void setup() {
    Serial.begin(9600);
}

void loop() {
    shiftRegIn.read(MSB);
    for (size_t i = 0; i < 8; i++) {
        Serial.println(shiftRegIn.getBit(i));
        delay(100);
    }
}
