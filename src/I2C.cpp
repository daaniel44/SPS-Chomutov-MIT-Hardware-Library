#include "custom_avr.h"

#define I2C_DELAY 2500

I2C::I2C(portAddress_t port, uint8_t sda_pin, uint8_t scl_pin) {
    this->portAddress = port;
    this->scl_pin = scl_pin;
    this->sda_pin = sda_pin;
}

bool I2C::Start(uint8_t adress) {
    adress <<= 1; //write bit       
    setDDR(true, true);
    _SFR_IO8(portAddress) = 0x03;

    // Start condition
    setSDA(false);
    _delay_us(I2C_DELAY);
    setSCL(false);

    return write(adress);
}


bool I2C::write(uint8_t byte) {
    setDDR(true, true);
    for (uint8_t i = 0; i < 8; i++) {
        _delay_us(I2C_DELAY);
        if((byte & 0x80) == 0) 
            setSDA(false);
        else 
            setSDA(true);
        
        byte <<= 1;
        _delay_us(I2C_DELAY);
        
        setSCL(true);
        _delay_us(I2C_DELAY);
        setSCL(false);
    }
    return getACK();
}

bool I2C::getACK() {
    setDDR(0, 1);
    _delay_us(I2C_DELAY);
    _delay_us(I2C_DELAY);

    setSCL(true);
    _delay_us(I2C_DELAY);
    bool result = (PIND & 0x01);
    DDRD = 0x03;
    setSCL(false);
    return result;
}

bool I2C::receiveFrom(uint8_t address) {
    address <<= 1;
    address += 1; //read bit

    _delay_us(I2C_DELAY);
    setDDR(true, true);
    setSDA(true);
    setSCL(true);
    _delay_us(I2C_DELAY);

    // Start condition
    setSDA(false);
    _delay_us(I2C_DELAY);
    setSCL(false);

    return (write(address));
}

uint8_t I2C::read() {
    uint8_t result = 0;
    setDDR(false, true);
    for (uint8_t i = 0; i < 8; i++) {
        _delay_us(I2C_DELAY);
        _delay_us(I2C_DELAY);
        
        setSCL(true);
        _delay_us(I2C_DELAY);
        setSCL(false);
        if ((_SFR_IO8(portAddress-1) & sda_pin)==0); else result = result + (1 << (7-i));
    }
    return result;
}

void I2C::stop() {
    _delay_us(I2C_DELAY);
    setSDA(true);
    _delay_us(I2C_DELAY);
    setSCL(true);
    _delay_us(I2C_DELAY);
}


void I2C::setSDA(bool state) {
    if (state)
        _SFR_IO8(portAddress) |= (1 << sda_pin);
    else 
        _SFR_IO8(portAddress) &= ~(1 << sda_pin);
}

void I2C::setSCL(bool state) {
    if (state)
        _SFR_IO8(portAddress) |= (1 << scl_pin);
    else 
        _SFR_IO8(portAddress) &= ~(1 << scl_pin);
}

void I2C::setDDR(bool sda, bool sck) {
    _SFR_IO8(portAddress-1) = sda ? (1 << sda_pin) : (0 << sda_pin) | sck ? (1 << scl_pin) : (0 << scl_pin);
}
