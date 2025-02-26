#ifndef CUSTOM_AVR_H
#define CUSTOM_AVR_H

#include <stdio.h>
#include <avr/io.h>
#include <util/delay.h>

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
        volatile uint8_t *port_a = 0;
        volatile uint8_t *ddr_a = 0;
        volatile uint8_t *pin_a = 0;
        volatile uint8_t *port_b = 0;
        volatile uint8_t *ddr_b = 0;
        volatile uint8_t *pin_b = 0;
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

        volatile uint8_t *port_a = 0;
        volatile uint8_t *ddr_a = 0;
        volatile uint8_t *pin_a = 0;
        volatile uint8_t *port_b = 0;
        volatile uint8_t *ddr_b = 0;
        volatile uint8_t *pin_b = 0;
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
        volatile uint8_t *port_a = 0;
        volatile uint8_t *ddr_a = 0;
        volatile uint8_t *pin_a = 0;
        volatile uint8_t *port_b = 0;
        volatile uint8_t *ddr_b = 0;
        volatile uint8_t *pin_b = 0;
};

class I2C {
    public:
        I2C(volatile uint8_t *_port, volatile uint8_t *_ddr, volatile uint8_t *_pin, uint8_t sda_pin, uint8_t scl_pin);
        bool Start(uint8_t address);
        bool write(uint8_t byte);
        bool receiveFrom(uint8_t address);
        uint8_t read();
        void stop();
        
    private:
        volatile uint8_t *port = 0;
        volatile uint8_t *ddr = 0;
        volatile uint8_t *pin = 0;
        volatile uint8_t sda_pin = 0;
        volatile uint8_t scl_pin = 0;

        inline bool getACK();
        inline void setSDA(bool state);
        inline void setSCL(bool state);
        inline void setDDR(bool sda, bool sck);
};

inline void digiWrite(uint8_t port, uint8_t pin, uint8_t state);

inline uint8_t digiRead(uint8_t port, uint8_t pin);

uint16_t analRead(uint8_t pin);

uint8_t pickPort(connectorType_t connector, volatile uint8_t *port_a, volatile uint8_t *ddr_a, volatile uint8_t *pin_a, volatile uint8_t *port_b, volatile uint8_t *ddr_b, volatile uint8_t *pin_b);

#endif