#include "custom_avr.h"

muxLed::muxLed(connectorType_t connector)
{
  //pickPort(connector, port_a, ddr_a, pin_a, port_b, ddr_b, pin_b);
}

// PORTC and PORTA
// led - 0 - 32
void muxLed::show(uint8_t led)
{
  *ddr_a = 0xFF;
  *ddr_b = 0xFF;
  *port_b = led / 8;           // nastavit skupinu
  *port_a = 1 << (led & 0x07); // nastavit pozici maskováním pouze hodnot do osmi
  _delay_us(500);
}
