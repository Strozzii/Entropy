// huffman.c

#include "huffman.h"

void test_rd_chars_wr_bits(char in[], char out[])
{
	init_in(in);
	init_out();

	unsigned char c;

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

void test_rd_bits_wr_chars(char in[], char out[])
{
	init_in(in);
	init_out();

	BIT b;

	while (has_next_bit())
	{
		b = read_bit();

		if (b > 0)
		{
			write_char('1');
		}
		else
		{
			write_char('0');
		}


	}

	get_out_buffer(out);
}




