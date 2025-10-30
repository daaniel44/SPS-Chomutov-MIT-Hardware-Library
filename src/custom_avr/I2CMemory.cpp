#include "custom_avr.h"
#include <string.h>


I2CMemory::I2CMemory(I2C *_i2c, uint8_t _address) {
    this->address = _address;
    this->i2c = _i2c;
}

char *I2CMemory::read() {
    char *result = new char[256];
    uint8_t success = 0;

    for(uint8_t j = 0; j < 3; j++) {
        success += i2c->Start(this->address);
        success += i2c->write(0x00);
        success += i2c->write(j*64);
        success += i2c->receiveFrom(this->address);
        for(uint8_t i = 0; i < 64; i++) { 
            char c = i2c->readAndIncrement();
            result[j*64 + i] = c;
        }
        i2c->stop();
        _delay_ms(10);
    }
    i2c->stop();
    return result;
}
  
bool I2CMemory::write(char data[]) {
    uint8_t success = 0;
    for(uint8_t i = 0; i < 3; i++) {
        success += i2c->Start(this->address);
        success += i2c->write(0x00);
        success += i2c->write(i*64);
        for (uint8_t j = 0; j < 64; j++) {
            if ((i*64 + j) > (uint8_t)strlen(data)) break;
            success += i2c->write(data[i*64 + j]);
        }
        i2c->stop();
        _delay_ms(10);
    }
    i2c->stop();
    return success;
}

bool I2CMemory::erase() {
    uint8_t success = 0;
    for (uint8_t i = 0; i < 3; i++) {
        success += i2c->Start(this->address);
        success += i2c->write(0x00);
        success += i2c->write(i*64);
        for (uint8_t j = 0; j < 64; j++) {
            success += i2c->write(0xFF);
        }
        i2c->stop();
    }
    i2c->stop();
    return success;
}