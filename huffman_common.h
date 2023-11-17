// huffman_common.h

#ifndef HUFFMAN_COMMON_H
#define HUFFMAN_COMMON_H

typedef enum {
	ZERO,
	ONE
} BIT;

#define DEBUG 1 // Set to 0 to disable debug output

#if DEBUG
#define DEBUG_PRINT(fmt, ...) fprintf(stderr, fmt, __VA_ARGS__)
#else
#define DEBUG_PRINT(fmt, ...)
#endif

#endif // HUFFMAN_COMMON_H
