#include <stdio.h>

int main(void)
{
// Size calculation of n-dimentional arrays:

    int game_pole[5][3]; // 2d array;

    size_t elem_bytes = sizeof(game_pole[0][0]); // size of one element (int) = 4 bytes;
    size_t array_bytes = sizeof(game_pole); // array size (15 elements) = 4 bytes (int) * 5 (strs) * 3 (cols) = 60 bytes;
    size_t row_bytes = sizeof(game_pole[0]); // row size (3 elements) = 60 bytes (array size) / 5 (strs) = 12 bytes;
    size_t rows = sizeof(game_pole) / sizeof(game_pole[0]); // number of strings = 60 bytes / 12 bytes = 5;
    size_t cols = sizeof(game_pole[0]) / sizeof(game_pole[0][0]); // number of columns = 12 bytes / 4 bytes (int) = 3;

    return 0;
}
