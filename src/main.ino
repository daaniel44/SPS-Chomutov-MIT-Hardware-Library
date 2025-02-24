#define F_CPU 16000000UL
#include <stdio.h>
#include <stdlib.h>
#include <avr/io.h>
#include <unistd.h>
#include <string.h>
#include <util/delay.h>
#include "custom_avr.h"
#include <avr/interrupt.h>
#include <Arduino.h>

#define I2C_DELAY 25


volatile uint16_t value = 0;

I2C *i2c = new I2C(PORT_D, 0, 1);

int main (void)
{
  

  // DDRA = 0xFF;
  // DDRC = 0xFF;

  // TCCR0A = 0x02; // režim porovnání
  // TCCR0B = 0x04; // předdělička 256
  // TIMSK0 = 0x02; // povolení přetečení
  // OCR0A = 50; // nastavení hodnoty OCR0A pro porovnání

  // sei();
  //serial::serialInit(9600);
  
  Serial.begin(9600);

  read_memory();

}

void read_memory() {
  uint8_t adress = 0x50;

  for(uint8_t i = 0; i < 80; i++) {
    i2c->Start(adress);
    i2c->write(0x00);
    i2c->write(i);
    i2c->receiveFrom(adress);
    i2c->stop();
    uint8_t result = i2c->read();

    Serial.print((char)result);
    PORTB = result;
  }
}
