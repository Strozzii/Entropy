#ifndef IO_H
#define IO_H

#include <stdbool.h>
#include <string.h>
#include "huffman_common.h"

#define BUF_SIZE 4096

// Public functions
void init_in(char text[]);
void init_out();
void get_out_buffer(char text[]);
bool has_next_char(void);
unsigned char read_char(void);
void write_char(unsigned char c);
bool has_next_bit(void);
BIT read_bit(void);
void write_bit(BIT c);

#endif /* IO_H */
