#include "custom_avr.h"
#include <string.h>

void serial::Init(uint16_t baud) {
    uint16_t ubrr = (F_CPU / (16UL * baud)) - 1;
    UBRR0L = ubrr & 0xFF; 
    UBRR0H = (ubrr >> 8) & 0xFF; 
    
    UCSR0B |= (1 << RXEN0); // Povolení rx
    UCSR0B |= (1 << TXEN0); // povolení tx
    UCSR0C |= (1 << 1); // 8 bitový přenos
    UCSR0C |= (1 << 2); // 8 bitový přenos
}

void serial::SetParity(bool active, bool evenParity) {
  if(active) {
    if (evenParity) {
      UCSR0C |= (1 << 5); //povolit sudou paritu;
    }
    else {
      UCSR0C |= (1 << 4);
      UCSR0C |= (1 << 5); //povolit lichou paritu;
    }
  }
  else {
    UCSR0C &= ~(1 << 4);
    UCSR0C &= ~(1 << 5);
  }
}

void serial::Send(const char data[]) {
  for (uint8_t i = 0; i < strlen(data); i++) {
    while((UCSR0A & 0x20) == 0); //UDRE0 bit
    UDR0 = data[i];
  }  
}

void serial::Sendln(const char data[]) {
  for (uint8_t i = 0; i < strlen(data); i++) {
    while((UCSR0A & 0x20) == 0); //UDRE0 bit
    UDR0 = data[i];
  }  
  while((UCSR0A & 0x20) == 0); //UDRE0 bit
  UDR0 = '\r';
  while((UCSR0A & 0x20) == 0); //UDRE0 bit
  UDR0 = '\n';
}

char* serial::Receive() {
  uint8_t i = 0;
  static char buffer[255] = "";
  
  while(1) {
    while((UCSR0A & 0x80) == 0);
    char c = UDR0;
    if(c == '\n') break; //CR
    buffer[i] = c;
    i++;
  }
  //buffer[i] = '\0';
  return buffer; 
}