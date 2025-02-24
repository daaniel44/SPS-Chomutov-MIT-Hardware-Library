#ifndef CUSTOM_AVR_H
#define CUSTOM_AVR_H

#include <stdio.h>
#include <avr/io.h>
#include <util/delay.h>

// PORT definitions
typedef enum {
    PORT_A = 0x02,
    PORT_B = 0x05,
    PORT_C = 0x08,
    PORT_D = 0x0B,
    PORT_E = 0x0E, 
    PORT_F = 0x11,
    PORT_G = 0x14,
    PORT_H = 0x17,
    PORT_J = 0x1A,
    PORT_K = 0x1D,
    PORT_L = 0x20
} portAddress_t;


enum connectorType_t {
    CON_1,
    CON_2,
    CON_3,
    CON_4,
};

enum keytype_t {
    KEY_NOTHING,
    KEY_1,
    KEY_2,
    KEY_3,
    KEY_ESC,
    KEY_4,
    KEY_5,
    KEY_6,
    KEY_F1,
    KEY_7,
    KEY_8,
    KEY_9,
    KEY_F2,
    KEY_STAR,
    KEY_0,
    KEY_CROSS,
    KEY_ENTER
};


class kbLedDisp {
    public:
        kbLedDisp(connectorType_t connector);
        void kbLedDisp_Show(uint32_t num);
        static uint8_t kbLedDisp_KeytoNumber(keytype_t key);
        uint8_t kbLedDispl_scan();
        uint32_t kbLedDisp_readNumber();
        keytype_t kbLedDisp_readDigit();

    private:
        volatile portAddress_t portAddress_a;
        volatile portAddress_t portAddress_b;
};

class muxSegmentDisplay {
    public:

        muxSegmentDisplay(connectorType_t connector);
        void Set(uint8_t pos, float number, uint8_t zeros);
        void Run();

    private:
        volatile uint8_t dispPublicPos = 0;
        volatile float dispPublicNumber = 0;;
        volatile uint8_t dispPublicZeros = 0;

        volatile portAddress_t portAddress_a;
        volatile portAddress_t portAddress_b;

};

class serial {
    public:
        static void serialInit(uint16_t baud);
        static void serialSend(char data[]);
        static void serialSendln(char data[]);
        static char* serialReceive();
};

class muxLed {
    public:
        muxLed(connectorType_t connector);
        void show(uint8_t led);
    private:
        volatile portAddress_t portAddress_a;
        volatile portAddress_t portAddress_b;
};

class I2C {
    public:
        I2C(portAddress_t port, uint8_t sda_pin, uint8_t scl_pin);
        bool Start(uint8_t address);
        bool write(uint8_t byte);
        bool receiveFrom(uint8_t address);
        uint8_t read();
        void stop();
        
    private:
        volatile portAddress_t portAddress;
        volatile uint8_t sda_pin;
        volatile uint8_t scl_pin;

        bool getACK();
        void setSDA(bool state);
        void setSCL(bool state);
        void setDDR(bool sda, bool sck);
};

void digiWrite(uint8_t port, uint8_t pin, uint8_t state);

uint8_t digiRead(uint8_t port, uint8_t pin);

uint16_t analRead(uint8_t pin);

portAddress_t pickPortA(connectorType_t connector);
portAddress_t pickPortB(connectorType_t connector);

#endif