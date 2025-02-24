#include "custom_avr.h"
#include <string.h>

void serial::serialInit(uint16_t baud) {
    uint16_t ubrr = (F_CPU / (16UL * baud)) - 1;
    UBRR0L = ubrr & 0xFF; 
    UBRR0H = (ubrr >> 8) & 0xFF; 
    
    UCSR0B |= (1 << RXEN0); // Povolení rx
    UCSR0B |= (1 << TXEN0); // povolení tx
    UCSR0C |= (1 << 1); // 8 bitový přenos
    UCSR0C |= (1 << 2); // 8 bitový přenos
}


void serial::serialSend(char data[]) {
  for (uint8_t i = 0; i < strlen(data); i++) {
    while((UCSR0A & 0x20) == 0); //UDRE0 bit
    UDR0 = data[i];
  }  
}

void serial::serialSendln(char data[]) {
  for (uint8_t i = 0; i < strlen(data); i++) {
    while((UCSR0A & 0x20) == 0); //UDRE0 bit
    UDR0 = data[i];
  }  
  while((UCSR0A & 0x20) == 0); //UDRE0 bit
  UDR0 = '\n';
}

char* serial::serialReceive() {
  uint8_t i = 0;
  static char buffer[255] = "";
  
  while(1) {
    while((UCSR0A & 0x80) == 0);
    char c = UDR0;
    buffer[i] = c;
    if(c == '\n') break; //CR
    i++;
  }
  return buffer; 
}