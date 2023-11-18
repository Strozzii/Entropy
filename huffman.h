/**
 * @file
 * In diesem Modul werden die Komprimierung und Dekomprimierung realisiert.
 * Dieses verwendet das Modul io als Zugriffsschicht auf Dateien.
 *
 * @author  Dennis Stroz
 * @date    2023-11-18
 */

/* ------------------------------------------------------------------------ */
#ifndef HUFFMAN_H
#define HUFFMAN_H
/* ------------------------------------------------------------------------ */


/* ===========================================================================
 * Funktionsprototypen
 * ======================================================================== */

/**
 * Diese Funktion soll byteweise aus dem Eingabepuffer lesen und für jedes
 * gelesene Zeichen, dessen ASCII-Wert kleiner 'a' ist, ein 1-Bit in den
 * Ausgabepuffer schreiben. Abschließend wird das Ergebnis in einen Vektor
 * abgespeichert.
 *
 * @param in: Zeichenkette, womit der Eingabepuffer initialisiert wird.
 * @param out: Vektor, wo der Inhalt des Ausgabepuffers reinkopiert wird.
 */
extern void test_rd_chars_wr_bits(char in[], char out[]);

/**
 * Diese Funktion soll bitweise aus dem Eingabepuffer lesen und für jedes
 * gelesene 1-Bit das Zeichen '1' und für jedes gelesene 0-Bit das Zeichen
 * '0' in den Ausgabepuffer schreiben. Abschließend wird das Ergebnis in
 * einen Vektor abgespeichert.
 *
 * @param in: Zeichenkette, womit der Eingabepuffer initialisiert wird.
 * @param out: Vektor, wo der Inhalt des Ausgabepuffers reinkopiert wird.
 */
extern void test_rd_bits_wr_chars(char in[], char out[]);

/* ------------------------------------------------------------------------ */
#endif // HUFFMAN_H
