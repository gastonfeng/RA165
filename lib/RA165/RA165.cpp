#include <RA165.h>

RA165::RA165(int clockPin, int dataPin) {
    _reg = 0;
    _clockPin = clockPin;
    _dataPin = dataPin;
    pinMode(_clockPin, OUTPUT);
    pinMode(_dataPin, INPUT);
}

void RA165::read(RAORDER byteOrder) {
    int _L = 0;
    switch(byteOrder) {
        case MSB: {_L = 1;}
        case LSB: {_L = 0;}
    }
    _reg = shiftIn(_dataPin, _clockPin, _L);
}

byte RA165::readByte(RAORDER byteOrder) {
    read(byteOrder);
    return _reg;
}

int RA165::getBit(int bitToGet) {
    return bitRead(_reg, bitToGet);
}
