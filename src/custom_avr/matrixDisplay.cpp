#include <stdio.h>
#include <stdlib.h>
#include <avr/io.h>
#include <unistd.h>
#include <string.h>
#include "custom_avr.h"
#include "../font.h"


MatrixDisplay::MatrixDisplay(connectorType_t connector)
{
    pickPort(connector, &port_a, &ddr_a, &pin_a, &port_b, &ddr_b, &pin_b);

    *ddr_a = 0xFF; //Rows
	*ddr_b = 0xFF; //Columns
}

void MatrixDisplay::appendChar(char c) {
    uint16_t glyph_id = c - 32 + 1;
	glyph_desc_t desc = glyph_desc[glyph_id];
	const uint8_t *bitmap = &glyph_bitmap[desc.bitmap_index];
	for (uint8_t y = 0; y < desc.box_h; y++) {
    	for (uint8_t x = 0; x < desc.box_w; x++) {
			uint16_t bit_index = y * desc.box_w + x;
        	uint8_t byte = bitmap[bit_index >> 3];
	        uint8_t bit = 7 - (bit_index & 7);  // MSB-first
			bool pixelOn = (byte >> bit) & 1;

			uint8_t my = cursor_pos + x + desc.ofs_x; 
			uint8_t mx = ((1 << (8-desc.box_h+y)) + desc.ofs_y);
	        if (pixelOn) {
				buffer[my] |= mx;
			}
			else {
				buffer[my] &= ~mx;
			}
		}
	}
    text_length += desc.box_w + desc.ofs_x;
	//cursor_pos += desc.box_w + (desc.adv_w >> 4);
	cursor_pos += desc.box_w + desc.ofs_x;
}


void MatrixDisplay::appendText(char *text) {
	for(uint8_t i = 0; i < strlen(text); i++) {
		char c = text[i];
		if (c < 32 || c > 126) continue; // ignorovat neplatné znaky
		appendChar(c);
	}
}

void MatrixDisplay::clear() {
    text_length = 0;
    cursor_pos = 0;
    scroll_offset = 0;
    going_right = false;
    for (uint8_t i = 0; i < 32; i++) {
        buffer[i] = 0;
        current_matrix[i] = 0;
    }
    *port_a = 0;
    *port_b = 0;
}

void MatrixDisplay::setCursor(uint8_t pos) {
    cursor_pos = pos;
}

// Interrupt settings:
// TCCR0A = 0x02;
// TCCR0B = 0x02;
// TIMSK0 = 0x02;
// OCR0A = 50;
void MatrixDisplay::run() {
    *port_b = index;
    *port_a = current_matrix[index];
    index++;
    if (index >= 32) index = 0;

    if(timer >= 10000) { // Adjust scrolling speed here
        // Shift current_matrix left by copying from buffer with offset
        for(uint8_t i = 0; i < 32; i++) {
            current_matrix[i] = buffer[i + scroll_offset];
        }

        if(text_length <= 32) {
            scroll_offset = 0; // No scrolling needed
            timer = 0;
            return;
        }
        else {
            if(going_right) scroll_offset--;
            else scroll_offset++;
            if(scroll_offset >= text_length - 32 || scroll_offset == 0) going_right = !going_right; // Reset when reaching end
        }
        
        timer = 0;
    }
    timer++;
}