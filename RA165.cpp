#include <RA165.h>

RA165::RA165(int clockPin, int dataPin) {
    m_reg = 0;
    m_clockPin = clockPin;
    m_dataPin = dataPin;
    pinMode(m_clockPin, OUTPUT);
    pinMode(m_dataPin, INPUT);
}

void RA165::read(RAORDER byteOrder) {
    int m_L = 0;
    switch(byteOrder) {
        case MSB: {m_L = 1;}
        case LSB: {m_L = 0;}
    }
    m_reg = shiftIn(m_dataPin, m_clockPin, m_L);
}

byte RA165::readByte(RAORDER byteOrder) {
    read(byteOrder);
    return m_reg;
}

int RA165::getBit(int bitToGet) {
    return bitRead(m_reg, bitToGet);
}
