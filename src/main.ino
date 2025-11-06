//#define F_CPU 16000000UL
#include <stdio.h>
#include <stdlib.h>
#include <avr/io.h>
#include <unistd.h>
#include <string.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "custom_avr/custom_avr.h"

MatrixDisplay disp(CON_1);
kbLedDisp kbd(CON_2);

uint8_t mode = 1; // 0 - display mode, 1 - write mode

int main (void)
{
	serial::Init(9600);
	//TCCR0A = 0x02; // režim porovnání
	TCCR0A = 0x02; // režim přetečení
	TCCR0B = 0x02; // předdělička 256
	TIMSK0 = 0x02; // povolení přetečení
	OCR0A = 50; // nastavení hodnoty OCR0A pro porovnání

	sei();
	disp.enableScrolling(true);

	while(1) {
		keytype_t key = kbd.readKey();
		char buffer[2];
		itoa(kbLedDisp::KeytoNumber(key), buffer, 10);

		if(key == KEY_ESC) {
			disp.clear();
			continue;
		}
		if (key == KEY_STAR){
			mode = 1 - mode; // přepnutí módu
			disp.enableScrolling(!mode);
			continue;
		}

		if (mode == 1) 
			disp.appendChar(buffer[0]);
	}
}





ISR(TIMER0_COMPA_vect) {
  disp.run();
}


