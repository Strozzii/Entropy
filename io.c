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
	// Implementierung der Initialisierung des Ausgabepuffers
}

void get_out_buffer(char text[]) {
	// Implementierung, um den Ausgabepuffer zu kopieren
}

bool has_next_char(void) {
	// Implementierung, um zu prüfen, ob weitere Zeichen im Eingabepuffer vorhanden sind
}

unsigned char read_char(void) {
	// Implementierung, um ein Zeichen aus dem Eingabepuffer zu lesen
}

void write_char(unsigned char c) {
	// Implementierung, um ein Zeichen in den Ausgabepuffer zu schreiben
}

bool has_next_bit(void) {
	// Implementierung, um zu prüfen, ob weitere Bits im Eingabepuffer vorhanden sind
}

BIT read_bit(void) {
	// Implementierung, um ein Bit aus dem Eingabepuffer zu lesen
}

void write_bit(BIT c) {
	// Implementierung, um ein Bit in den Ausgabepuffer zu schreiben
}
