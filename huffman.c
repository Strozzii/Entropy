#include "huffman.h"

void test_rd_chars_wr_bits(char in[], char out[]) {
	// Initialize input buffer with the given text
	init_in(in);

	// Process input buffer byte by byte
	while (has_next_char()) {
		unsigned char c = read_char();

		// Modify and write bits to the output buffer
		for (int i = 7; i >= 0; --i) {
			BIT bit = (c & (1 << i)) ? BIT_1 : BIT_0;
			write_bit(bit);
		}
	}

	// Get the content of the output buffer
	get_out_buffer(out);
}

void test_rd_bits_wr_chars(char in[], char out[]) {
	// Initialize input buffer with the given text
	init_in(in);

	// Process input buffer bit by bit
	while (has_next_bit()) {
		BIT bit = read_bit();

		// Modify and write characters to the output buffer
		char c = (bit == BIT_1) ? '1' : '0';
		write_char(c);
	}

	// Get the content of the output buffer
	get_out_buffer(out);
}
