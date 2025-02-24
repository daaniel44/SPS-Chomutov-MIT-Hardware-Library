#include "custom_avr.h"
#include <string.h>




void digiWrite(portAddress_t port, uint8_t pin, uint8_t state) {
  _SFR_IO8(port + 2) = (state) ? (_SFR_IO8(port) | (1 << pin)) : (_SFR_IO8(port) & ~(1 << pin));
}


uint8_t digiRead(portAddress_t port, uint8_t pin) {
  return (_SFR_IO8(port) & (1 << pin)) != 0;
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


portAddress_t pickPortA(connectorType_t connector) {
  switch (connector)
  {
  case CON_1:
    return PORT_A;
    break;
  case CON_2:
    return PORT_A;
    break;
  case CON_3:
    return PORT_K;
    break;
  case CON_4:
    return PORT_A;
    break;
  default:
    return PORT_A;
    break;
  }
}

portAddress_t pickPortB(connectorType_t connector) {
  switch (connector)
  {
  case CON_1:
    return PORT_C;
    break;
  case CON_2:
    return PORT_C;
    break;
  case CON_3:
    return PORT_F;
    break;
  case CON_4:
    return PORT_B;
    break;
  default:
    return PORT_A;
    break;
  }
}



