/**
 * @mainpage Huffman-Kodierung
 *
 * Dieses Projekt realisiert die Huffman-Kompression und Dekompression.
 *
 * @author  Dennis Stroz
 * @date    2023-11-18
 */

/**
 * @file
 *
 * Dieses Modul startet das Huffman-Programm.
 *
 * @author  Dennis Stroz
 * @date    2023-11-18
 */

/* ===========================================================================
 * Header-Dateien einbinden
 * ======================================================================== */

#include <stdio.h>
#include <string.h>

#include "huffman.h"


/* ===========================================================================
 * Funktionsdefinitionen
 * ======================================================================== */

/**
 * Realisiert Testfälle um Ergebnisse auf Richtigkeit zu überprüfen.
 *
 * @return Status der Terminierung
 */
int main()
{

	char in[] = "aAbBcCdDeEfFgGhHiIjJkKlLmMnNoOpPqQrRsStTuUvVwWxX";
	char out[50] = { 0 };

	test_rd_chars_wr_bits(in, out);

	printf("%s\n", out);

	char in2[] = "abCdefGHijKlmnOPqrStuvWXyzAbcdEF";
	char out2[50] = { 0 };

	test_rd_chars_wr_bits(in2, out2);

	printf("%s\n", out2);

	printf("%d\n", strcmp(out2, "####"));

	return 0;
}
