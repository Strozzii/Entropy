// main.c

#include "huffman.h"
#include "huffman_common.h"
#include "io.h"
#include <stdio.h>

int main() {

	char in[] = "aAbBcCdDeEfFgGhHiIjJkKlLmMnNoOpPqQrRsStTuUvVwWxX";
	char out[50] = {0};

	test_rd_chars_wr_bits(in, out);

	printf("%d\n", strcmp(out, "UUUUUU"));

	char in_2[] = "UUUUUU";
	char out_2[] = {0};

	test_rd_bits_wr_chars(in_2, out_2);

	printf("Input: %s\n", in_2);
	printf("Output: %s\n", out_2);


	return 0;
}
