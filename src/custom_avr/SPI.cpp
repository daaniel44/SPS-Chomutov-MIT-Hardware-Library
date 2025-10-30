#include "custom_avr.h"

#define SPI_DELAY 1000 //uS

SPI::SPI(volatile uint8_t *_port, volatile uint8_t *_pin, volatile uint8_t *_ddr, uint8_t _cs, uint8_t _di, uint8_t _clk) {
    port = _port;
    pin = _pin;
    ddr = _ddr;
    cs = _cs;
    di = _di;
    clk = _clk;

    // Set the pins as output
    *ddr |= (1 << cs) | (1 << di) | (1 << clk);
}


void SPI::start() {
    // Set CS low to start communication
    *port &= ~(1 << cs);
    _delay_us(SPI_DELAY);
}

void SPI::stop() {
    // Set CS high to end communication
    *port |= (1 << cs);
    _delay_us(SPI_DELAY);
}

void SPI::send(uint8_t data) {

    // Send the data byte
    for (uint8_t i = 0; i < 8; i++) {
        // Set DI to the value of the current bit
        if ((data & 0x80)==0) {
            *port &= ~(1 << di); // Set DI low
            serial::Send("0");
        } 
        else {
            *port |= (1 << di); // Set DI high
            serial::Send("1");
        }
        data <<= 1;

        // Pulse the clock pin
        _delay_us(SPI_DELAY);
        *port |= (1 << clk); // Set CLK high
        _delay_us(SPI_DELAY); // Small delay for clock pulse
        *port &= ~(1 << clk); // Set CLK low
        _delay_us(SPI_DELAY);
        //serial::Send("C");
    }
    serial::Sendln("");
}


uint8_t SPI::receive() {
    uint8_t data = 0;

    // Receive the data byte
    for (uint8_t i = 0; i < 8; i++) {
        // Pulse the clock pin
        _delay_us(SPI_DELAY);
        *port |= (1 << clk); // Set CLK high
        _delay_us(SPI_DELAY); // Small delay for clock pulse

        // Read the value from DI and shift it into the data byte
        if ((*pin & (1 << di)) != 0) {
            data |= (1 << (7 - i)); // Set the corresponding bit in data
            serial::Send("1");
        } else {
            serial::Send("0");
        }

        *port &= ~(1 << clk); // Set CLK low
        _delay_us(SPI_DELAY);
    }
    serial::Sendln("");
    return data;
}