#include "huffman.h"
#include <stdio.h>
#include <string.h>

int main() {
	// Test case 1: test_rd_chars_wr_bits
	char in1[] = "aAbBcCdDeEfFgGhHiIjJkKlLmMnNoOpPqQrRsStTuUvVwWxX";
	char out1[50] = {0};
	test_rd_chars_wr_bits(in1, out1);

	printf("Test 1: %s\n", strcmp(out1, "UUUUUU") == 0 ? "Passed" : "Failed");

	// Test case 2: test_rd_bits_wr_chars
	char in2[] = "aAbBcCdDeEfFgGhHiIjJkKlLmMnNoOpPqQrRsStTuUvVwWxX";
	char out2[50] = {0};
	test_rd_bits_wr_chars(in2, out2);

	printf("Test 2: %s\n", strcmp(out2, "01010101010101010101010101010101010101010101010101010") == 0 ? "Passed" : "Failed");

	return 0;
}
