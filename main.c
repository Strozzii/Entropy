// main.c

#include <stdio.h>

#include "huffman.h"



int main() {

	char in[] = "aAbBcCdDeEfFgGhHiIjJkKlLmMnNoOpPqQrRsStTuUvVwWxX";
	char out[50] = {0};

	test_rd_chars_wr_bits(in, out);

	printf("%s\n", out);

	char in2[] = "abCdefGHijKlmnOPqrStuvWXyzAbcdEF";
	char out2[50] = {0};

	test_rd_chars_wr_bits(in2, out2);

	printf("%s\n", out2);

	//printf("%d\n", strcmp(out, "####"));



	return 0;
}
