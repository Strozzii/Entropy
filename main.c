// main.c

#include <stdio.h>

#include "huffman.h"



int main() {

	char in[] = "aAbBcCdDeEfFgGhHiIjJkKlLmMnNoOpPqQrRsStTuUvVwWxX";
	char out[50] = {0};

	test_rd_chars_wr_bits(in, out);

	printf("%s", out);

	//printf("%d\n", strcmp(out, "####"));



	return 0;
}
