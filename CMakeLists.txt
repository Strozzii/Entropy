cmake_minimum_required(VERSION 3.26)
project(Entropy C)

set(CMAKE_C_STANDARD 11)

add_executable(Entropy main.c
        huffman_common.c
        huffman_common.h
        io.c
        io.h
        huffman.c
        huffman.h
)
