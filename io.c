/* ===========================================================================
 * Header-Dateien einbinden
 * ======================================================================== */

#include <string.h>
#include <stdio.h>

#include "io.h"


/* ===========================================================================
 * Symbolische Konstanten
 * ======================================================================== */

/**
 * Größe des Eingabe-/Ausgabepuffers.
 */
#define BUF_SIZE 4096


/* ===========================================================================
 * Makros zur Bit-Manipulation
 * ======================================================================== */

/**
 * Privates Makro, um den Zustand eines Bits innerhalb eines Bytes an der übergebenen Position zu erhalten.
 */
#define GET_BIT(BYTE, POS) (((BYTE) & (1 << (7 - POS))))

/**
 * Privates Makro, um an einer beliebigen Stelle eines Bytes einen Bit zu setzen.
 */
#define PUT_BIT(BYTE, BIT, POS) ((BYTE) = ((BYTE) & ~(1 << (7 - POS))) | ((BIT) << (7 - POS)))


/* ===========================================================================
 * Globale Variablen
 * ======================================================================== */

/**
 * Eingabepuffer
 */
static unsigned char in_buffer[BUF_SIZE];

/**
 * Ausgabepuffer
 */
static unsigned char out_buffer[BUF_SIZE];

/**
 * Zeiger Position im Eingabepuffer
 */
static int in_pos;

/**
 * Zeiger Position im Ausgabepuffer
 */
static int out_pos;

/**
 * Füllstand des Eingabepuffers
 */
static int in_fill;

/**
 * Füllstand des Ausgabepuffers
 */
static int out_fill;


/* ===========================================================================
 * Funktionsdefinitionen (extern)
 * ======================================================================== */

/* ---------------------------------------------------------------------------
 * Funktion: init_in
 * ------------------------------------------------------------------------ */
extern void init_in(char text[])
{
	int text_length;
	int i;

	/* Vorsicht! Hier implizite Typ-Konvertierung (Unsigned Long Long -> Int) */
	text_length = strlen(text);

	/* Setzt Position zurück und den Füllstand auf die Länge des Textes */
	in_pos = 0;
	in_fill = text_length;

	/* Zeichenweises Schreiben der Zeichen aus text in den Eingabepuffer */
	for (i = 0; i < text_length; i++)
	{
		in_buffer[i] = text[i];
	}

}

/* ---------------------------------------------------------------------------
 * Funktion: init_out
 * ------------------------------------------------------------------------ */
extern void init_out()
{
	/* Setzt die Position und den Füllstand des Ausgabepuffers zurück */
	out_pos = 0;
	out_fill = 0;
}

/* ---------------------------------------------------------------------------
 * Funktion: get_out_buffer
 * ------------------------------------------------------------------------ */
extern void get_out_buffer(char text[])
{
	for (int i = 0; i < out_fill; i++)
	{
		text[i] = out_buffer[i];
	}
	text[out_fill] = '\0';
}

/* ---------------------------------------------------------------------------
 * Funktion: has_next_char
 * ------------------------------------------------------------------------ */
extern bool has_next_char(void)
{
	return in_pos < in_fill;
}

/* ---------------------------------------------------------------------------
 * Funktion: read_char
 * ------------------------------------------------------------------------ */
extern unsigned char read_char(void)
{
	/* Nach jedem Lesen wird der Zeiger verschoben */
	return in_buffer[in_pos++];
}

/* ---------------------------------------------------------------------------
 * Funktion: write_char
 * ------------------------------------------------------------------------ */
extern void write_char(unsigned char c)
{
	/* Nach jedem Schreiben wird der Zeiger verschoben und der Füllstand erhöht */
	out_buffer[out_pos++] = c;
	out_fill++;
}

/* ---------------------------------------------------------------------------
 * Funktion: has_next_bit
 * ------------------------------------------------------------------------ */
extern bool has_next_bit(void)
{
	/* Der Füllstand beschreibt nur ganze Byte und muss in Bit umgerechnet werden */
	return (in_pos < in_fill * 8);
}

/* ---------------------------------------------------------------------------
 * Funktion: read_bit
 * ------------------------------------------------------------------------ */
extern BIT read_bit(void)
{
	char b;

	/* Inkrementieren innerhalb des Makro-Aufrufs hat Anomalien verursacht */
	b = GET_BIT(in_buffer[in_pos / 8], in_pos % 8);
	in_pos++;

	return b > 0 ? ONE : ZERO;
}

/* ---------------------------------------------------------------------------
 * Funktion: write_bit
 * ------------------------------------------------------------------------ */
extern void write_bit(BIT c)
{
	/* Inkrementieren innerhalb des Makro-Aufrufs hat Anomalien verursacht */
	PUT_BIT(out_buffer[out_pos / 8], c, out_pos % 8);
	out_pos++;
	out_fill = (out_pos / 8) + (out_pos % 8 == 0 ? 0 : 1);
}
