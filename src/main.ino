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

I2C *i2c = new I2C(&PORTD, &DDRD, &PIND, 0, 1);


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
  DDRB = 0xFF;
  Serial.begin(9600);

  //writeMemory();
  _delay_ms(1000);
  read_memory();

}

void read_memory() {
  uint8_t adress = 0x50;

  for(uint8_t i = 0; i < 100; i++) {
    i2c->Start(adress);
    i2c->write(0x00);
    i2c->write(i);
    i2c->receiveFrom(adress);
    uint8_t result = i2c->read();
    i2c->stop();
    Serial.print((char)result);
    PORTB = result;
  }
}

void writeMemory() {
  char data[] = "Nazdarek";
  uint8_t adress = 0x50;
  for (uint8_t i = 0; i < strlen(data); i++) {
    i2c->Start(adress);
    i2c->write(0x00);
    i2c->write(i);
    i2c->write(data[i]);
    Serial.print(data[i]);
    i2c->stop();
  }
}
