#include "custom_avr.h"

muxLed::muxLed(connectorType_t connector)
{
  this->portAddress_a = pickPortA(connector);
  this->portAddress_b = pickPortB(connector);
}

// PORTC and PORTA
// led - 0 - 32
void muxLed::show(uint8_t led)
{
  _SFR_MEM8(portAddress_a - 1) = 0xFF;
  _SFR_MEM8(portAddress_b - 1) = 0xFF;
  _SFR_MEM8(portAddress_b) = led / 8;           // nastavit skupinu
  _SFR_MEM8(portAddress_a) = 1 << (led & 0x07); // nastavit pozici maskováním pouze hodnot do osmi
  _delay_us(500);
}
