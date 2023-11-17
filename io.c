// io.c

#include "io.h"
#include <stdio.h>

unsigned char in_buffer[BUF_SIZE];
unsigned char out_buffer[BUF_SIZE];
int in_pos, out_pos, in_fill, out_fill;

void init_in(char text[]) {
	// Kopiere den Text in den Eingabepuffer (in_buffer)
	int text_length = strlen(text);
	for (int i = 0; i < text_length; ++i) {
		in_buffer[i] = text[i];
	}

	// Setze die Positionen und Füllstände entsprechend zurück
	in_pos = 0;
	in_fill = text_length;
}

void init_out() {
	// Setze die Positionen und Füllstände des Ausgabepuffers zurück
	out_pos = 0;
	out_fill = 0;
}

void get_out_buffer(char text[]) {
	// Kopiere den Inhalt des Ausgabepuffers in den übergebenen Text
	for(int i = 0; i < out_fill; i++)
	{
		text[i] = out_buffer[i];
	}
	text[out_fill] = '\0';
}

bool has_next_char(void) {
	return in_pos < in_fill;
}

unsigned char read_char(void) {
	return in_buffer[in_pos++];
}

void write_char(unsigned char c) {
	out_buffer[out_pos++] = c;
	out_fill++;
}

bool has_next_bit(void) {
	return true;
}

BIT read_bit(void) {
	return ZERO;
}

void write_bit(BIT c) {

}
