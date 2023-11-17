#include "io.h"

// Private global variables
static unsigned char in_buffer[BUF_SIZE];
static unsigned char out_buffer[BUF_SIZE];
static int in_position = 0;
static int out_position = 0;
static int in_fill = 0;
static int out_fill = 0;

// Private macros
#define GET_BIT(BYTE, POS) (((BYTE) >> (POS)) & 1)
#define PUT_BIT(BYTE, BIT, POS) ((BYTE) = ((BYTE) & ~(1 << (POS))) | ((BIT) << (POS)))

// Public functions
void init_in(char text[]) {
	// Kopiere den Text in den Eingabepuffer (in_buffer)
	int text_length = strlen(text);
	for (int i = 0; i < text_length; ++i) {
		in_buffer[i] = text[i];
	}
	// Setze die Positionen und Füllstände entsprechend zurück
	in_position = 0;
	in_fill = text_length;
}

void init_out() {
	// Setze die Positionen und Füllstände des Ausgabepuffers zurück
	out_position = 0;
	out_fill = 0;
}

void get_out_buffer(char text[]) {
	// Kopiere den Inhalt des Ausgabepuffers in den übergebenen Text
	int text_length = (out_fill > 0) ? out_position / 8 + 1 : out_position / 8;
	for (int i = 0; i < text_length; ++i) {
		text[i] = out_buffer[i];
	}
	text[text_length] = '\0'; // Setze das Nullzeichen am Ende
}

bool has_next_char(void) {
	return in_position < in_fill;
}

unsigned char read_char(void) {
	return in_buffer[in_position++];
}

void write_char(unsigned char c) {
	out_buffer[out_position++] = c;
	out_fill++;
}

bool has_next_bit(void) {
	return (in_position < in_fill) || (in_position == in_fill && in_position < 8);
}

BIT read_bit(void) {
	if (in_position == in_fill) {
		in_fill = 0;
		// Hier sollten Sie den Eingabepuffer (in_buffer) aus einer Quelle (z.B., Datei) nachladen
		// ...
	}
	return GET_BIT(in_buffer[in_position / 8], in_position % 8);
}

void write_bit(BIT c) {
	if (out_fill == 8) {
		// Hier sollten Sie den Ausgabepuffer (out_buffer) in das Ziel (z.B., Datei) schreiben
		// ...
		out_fill = 0;
	}
	PUT_BIT(out_buffer[out_position / 8], c, out_position % 8);
	out_position++;
	out_fill++;
}
