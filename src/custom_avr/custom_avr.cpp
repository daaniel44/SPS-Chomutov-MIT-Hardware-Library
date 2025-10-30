#include "custom_avr.h"
#include <string.h>




inline void digiWrite(volatile uint8_t *port, uint8_t pin, uint8_t state) {
  *port = (*port & ~(1 << pin)) | ((state & 0x01) << pin);
}


inline uint8_t digiRead(volatile uint8_t *port, uint8_t pin) {
  return *port & (1 << pin);
}

//PORT F
uint16_t analRead(uint8_t pin) {
  uint16_t value = 0;

  ADCSRA |= (1 << ADEN); //Enable ADC
  ADMUX |= 1 << REFS0; // interni reference Ucc
  ADMUX = ((ADMUX & ~0x1F) | (pin & 0x1F)); //Zapsání pinu do MUX


  ADCSRA |= 0x07; //ADPS - prescaler 125kHz
  ADCSRA |= (1 << ADSC); //Start conversion

  _delay_ms(1);
  while((ADCSRA & 1 << ADSC) != 0);
  value = ADCL;
  value |= (ADCH << 8);

  //ADCSRA &= ~(1 << ADEN); //Disable ADCs

  return (value);
}


uint8_t pickPort(connectorType_t connector, volatile uint8_t **port_a, volatile uint8_t **ddr_a, volatile uint8_t **pin_a, volatile uint8_t **port_b, volatile uint8_t **ddr_b, volatile uint8_t **pin_b) {
  //port_a is always on the outside
  switch (connector)
  {
  case CON_1:
    *port_a = &PORTK;
    *ddr_a = &DDRK;
    *pin_a = &PINK;
    *port_b = &PORTF;
    *ddr_b = &DDRF;
    *pin_b = &PINF;
    break;
  case CON_2:
    *port_a = &PORTB;
    *ddr_a = &DDRB;
    *pin_a = &PINB;
    *port_b = &PORTL;
    *ddr_b = &DDRL;
    *pin_b = &PINL;
    break;
  case CON_3:
    *port_a = &PORTA;
    *ddr_a = &DDRA;
    *pin_a = &PINA;
    *port_b = &PORTC;
    *ddr_b = &DDRC;
    *pin_b = &PINC;
    break;
  case CON_4:
    //here there are ports H,D,E,J,G so unusable
    break;  
  default:
    break;
  }
  return 0;
}



