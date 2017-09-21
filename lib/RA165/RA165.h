#define RA165_h
#ifdef RA165_h
#include <Arduino.h>

enum RAORDER {LSB, MSB};

class RA165 {
    public:
        RA165(int clockPin, int dataPin);
        byte readByte(RAORDER byteOrder);
        void read(RAORDER byteOrder);
        int getBit(int bitToGet);
    protected:
        int             _clockPin;
        int             _dataPin;
        byte            _reg;
    private:
};
#endif
