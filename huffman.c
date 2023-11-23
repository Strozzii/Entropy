/* ===========================================================================
 * Header-Dateien einbinden
 * ======================================================================== */

#include "io.h"
#include "huffman.h"


/* ===========================================================================
 * Funktionsdefinitionen (extern)
 * ======================================================================== */

/* ---------------------------------------------------------------------------
 * Funktion: test_rd_chars_wr_bits
 * ------------------------------------------------------------------------ */
extern void test_rd_chars_wr_bits(char in[], char out[])
{
	unsigned char c;

	/* Initialisieren des Eingabe-/Ausgabepuffers */
	init_in(in);
	init_out();

	/* Solange Zeichen vorhanden schreibe Bit in den Ausgabepuffer */
	while (has_next_char())
	{
		c = read_char();

		if (c < 'a')
		{
			write_bit(ONE);
		}
		else
		{
			write_bit(ZERO);
		}
	}

	get_out_buffer(out);
}

/* --------------------------------------------------------------------------
 * Funktion: test_rd_bits_wr_chars
 * ------------------------------------------------------------------------ */
extern void test_rd_bits_wr_chars(char in[], char out[])
{
	BIT b;

	/* Initialisieren des Eingabe-/Ausgabepuffers */
	init_in(in);
	init_out();

	/* Solange Bit vorhanden schreibe Zeichen in den Ausgabepuffer */
	while (has_next_bit())
	{
		b = read_bit();

		if (b == ONE)
		{
			write_char('1');
		}
		else if (b == ZERO)
		{
			write_char('0');
		}

	}
	write_char('\0');

	get_out_buffer(out);
}




