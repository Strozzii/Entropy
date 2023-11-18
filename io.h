/**
 * @file
 * In diesem Modul werden die Funktionen zum byte- sowie bitweisen Lesen und Schreiben
 * zur Verfügung gestellt.
 *
 * @author  Dennis Stroz
 * @date    2023-11-18
 */

/* ------------------------------------------------------------------------ */
#ifndef IO_H
#define IO_H
/* ------------------------------------------------------------------------ */


/* ===========================================================================
 * Header-Dateien einbinden
 * ======================================================================== */

#include <stdbool.h>

#include "huffman_common.h"


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
 * Funktionsprototypen
 * ======================================================================== */

/**
 * Diese Funktion initialisiert den Eingabepuffer mit einer übergebenen Zeichenkette
 * und setzt den Positionszähler, sowie Füllstand zurück.
 *
 * @param text: Übergebene Zeichenkette, die in den Eingabepuffer geladen wird.
 */
extern void init_in(char text[]);

/**
 * Diese Funktion initialisiert einen leeren Ausgabepuffer.
 */
extern void init_out();

/**
 * Diese Funktion kopiert den Inhalt des Ausgabepuffers in einen Vektor.
 *
 * @param text: Vektor, der als Kopie des Ausgabepuffers fungiert.
 */
extern void get_out_buffer(char text[]);

/**
 * Diese Funktion gibt an, ob noch Zeichen im Eingabepuffer gelesen werden können.
 *
 * @return True, wenn mindestens 1 Zeichen gelesen werden kann. Sonst false.
 */
extern bool has_next_char(void);

/**
 * Liest das aktuelle Zeichen im Eingabepuffer und positioniert den Zeiger auf das nächste Zeichen.
 *
 * @return Aktuelles Zeichen im Eingabepuffer.
 */
extern unsigned char read_char(void);

/**
 * Schreibt ein Zeichen an die nächste Position im Ausgabepuffer.
 *
 * @param c: Zeichen, was in den Ausgabepuffer geschrieben werden soll.
 */
extern void write_char(unsigned char c);

/**
 * Diese Funktion gibt an, ob noch Bits im Eingabepuffer gelesen werden können.
 *
 * @return True, wenn mindestens 1 Bit gelesen werden kann. Sonst false.
 */
extern bool has_next_bit(void);

/**
 * Liest das aktuelle Bit im Eingabepuffer und positioniert den Zeiger auf das nächste Bit.
 *
 * @return Aktuelles Bit im Eingabepuffer.
 */
extern BIT read_bit(void);

/**
 * Schreibt ein Bit an die nächste Bit-Position im Ausgabepuffer.
 *
 * @param c: Bit, was in den Ausgabepuffer geschrieben werden soll.
 */
extern void write_bit(BIT c);

/* ------------------------------------------------------------------------ */
#endif // IO_H
