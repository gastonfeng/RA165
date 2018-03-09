#define RA165_h
#ifdef RA165_h
#include <Arduino.h>

/*
by Mike Romans of RomansAudio

Simple Oop class for the 165 shiftin register.
*/

enum RAORDER {LSB, MSB};

class RA165 {
    public:
        // Setup the object with the clock and data pins
        RA165(int clockPin, int dataPin);
        // Read a byte from the register
        byte readByte(RAORDER byteOrder);
        // Read the byte from the register to the internal byte
        void read(RAORDER byteOrder);
        // Get a bit from the interal byte after a read
        int getBit(int bitToGet);
    protected:
        int             m_clockPin;
        int             m_dataPin;
        byte            m_reg;
    private:
};
#endif
