//#define F_CPU 16000000UL
#include <stdio.h>
#include <stdlib.h>
#include <avr/io.h>
#include <unistd.h>
#include <string.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "custom_avr/custom_avr.h"
#include "font.h"

MatrixDisplay *disp = new MatrixDisplay(CON_1);

int main (void)
{
	serial::Init(9600);
	//TCCR0A = 0x02; // režim porovnání
	TCCR0A = 0x02; // režim přetečení
	TCCR0B = 0x02; // předdělička 256
	TIMSK0 = 0x02; // povolení přetečení
	OCR0A = 50; // nastavení hodnoty OCR0A pro porovnání

	sei();
	disp->appendText("Hello World! ");

	while(1) {
	}
}





ISR(TIMER0_COMPA_vect) {
  disp->run();
}


