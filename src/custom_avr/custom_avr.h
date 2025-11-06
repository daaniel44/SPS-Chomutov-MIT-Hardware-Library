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
        void Show(uint32_t num);
        static uint8_t KeytoNumber(keytype_t key);
        uint8_t scan();
        uint32_t readNumber();
        keytype_t readKey();

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
        static void Init(uint16_t baud);
        static void Send(const char data[]);
        static void Sendln(const char data[]);
        static char* Receive();
        static void SetParity(bool active, bool evenParity);
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
        inline uint8_t read() { return read(false); }
        inline uint8_t readAndIncrement() { return read(true); };
        void stop();
        
    private:
        volatile uint8_t *port = 0;
        volatile uint8_t *ddr = 0;
        volatile uint8_t *pin = 0;
        volatile uint8_t sda_pin = 0;
        volatile uint8_t scl_pin = 0;

        uint8_t read(bool readNext);
        inline bool getACK();
        inline void setSDA(bool state);
        inline void setSCL(bool state);
        inline void setDDR(bool sda, bool sck);
};

class SPI {
    public:
        SPI(volatile uint8_t *_port, volatile uint8_t *_pin, volatile uint8_t *_ddr, uint8_t _cs, uint8_t _di, uint8_t _clk);
        void start();
        void stop();
        void send(uint8_t data);
        uint8_t receive();
    private:
        volatile uint8_t *port = 0;
        volatile uint8_t *pin = 0;
        volatile uint8_t *ddr = 0;
        uint8_t cs = 0;
        uint8_t di = 0;
        uint8_t clk = 0;
};



class I2CMemory {
    public:
        I2CMemory(I2C *_i2c, uint8_t _address);
        char *read();
        bool write(char data[]);
        bool erase();

    private:
        uint8_t address = 0;
        I2C *i2c;
};


class MatrixDisplay {
    public:
        MatrixDisplay(connectorType_t connector);
        void writeText(char *text);
        void appendChar(char c);
        void appendText(char *text);
        void clear();
        void setCursor(uint8_t pos);
        void enableScrolling(bool enable);
        void run();
    private:
        volatile uint8_t *port_a = 0;
        volatile uint8_t *ddr_a = 0;
        volatile uint8_t *pin_a = 0;
        volatile uint8_t *port_b = 0;
        volatile uint8_t *ddr_b = 0;
        volatile uint8_t *pin_b = 0;

        volatile uint8_t current_matrix[32] = {0};
        volatile uint8_t buffer[255] = {0};
        volatile uint8_t index = 0;
        volatile uint8_t cursor_pos = 0;

        volatile bool enable_scroll = false;
        volatile uint32_t timer = 0;
        volatile uint8_t scroll_offset = 0;
        volatile bool going_right = false;
        volatile uint8_t text_length = 0;
};

inline void digiWrite(uint8_t port, uint8_t pin, uint8_t state);

inline uint8_t digiRead(uint8_t port, uint8_t pin);

uint16_t analRead(uint8_t pin);

uint8_t pickPort(connectorType_t connector, volatile uint8_t **port_a, volatile uint8_t **ddr_a, volatile uint8_t **pin_a, volatile uint8_t **port_b, volatile uint8_t **ddr_b, volatile uint8_t **pin_b);

#endif