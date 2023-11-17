#ifndef HUFFMAN_COMMON_H
#define HUFFMAN_COMMON_H

// Enumeration for the representation of bit states
typedef enum {
	BIT_0 = 0,
	BIT_1 = 1
} BIT;

// Macro for debugging output
#ifdef DEBUG
#define DEBUG_PRINT(fmt, ...) fprintf(stderr, fmt, __VA_ARGS__)
#else
#define DEBUG_PRINT(fmt, ...) do {} while (0)
#endif

#endif /* HUFFMAN_COMMON_H */
