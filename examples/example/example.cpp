#include <Arduino.h>
#include <RA165.h>

// Setup your shiftin register
// RA165(int clockPin, int dataPin);
RA165 shiftRegIn(12,11);

void setup() {
    Serial.begin(9600);
}

void loop() {
    // Read the values and print them over serial
    shiftRegIn.read(MSB);
    for (size_t i = 0; i < 8; i++) {
        Serial.print("Bit ");
        Serial.print(i);
        Serial.print(" = ");
        Serial.println(shiftRegIn.getBit(i));
        delay(100);
    }
}
