#include <stdio.h>

#define N 5

void show_feld(const char (*f)[N]) // auxiliary func represented as 2D-array to dysplaying the game feld;
{
    for(int i = 0; i < N; ++i) { // iterate the rows of game feld;
        for(int j = 0; j < N; ++j) // terate the cols game feld;
            printf("%c ", (f[i][j] == 0) ? '#' : '0'); // output sing '#' if current value is '0' (close) or sign '0' if current value is '1' (open);
        putchar('\n'); // transfer the current char in loop to next row;
    }
}

void open_zeros(const char (*f)[N], char (*pf)[N], int i, int j) // is rcs func and it opens cells ([i], [j]) of game feld which have value 0;
{
    if(f[i][j] != 0 || pf[i][j] == 1) // if current cell is not zero or is already open than return (no action);
        return;
    pf[i][j] = 1; // else if current cell is zero and is closed now then it shold be open by rcs func:
    if(i - 1 >= 0 && f[i - 1][j] == 0) open_zeros(f, pf, i - 1, j); // check neighboring cells to left direction for value zero and to open it;
    if(i + 1 <  N && f[i + 1][j] == 0) open_zeros(f, pf, i + 1, j); // check neighboring cells to right direction for value zero and to open it;
    if(j - 1 >= 0 && f[i][j - 1] == 0) open_zeros(f, pf, i, j - 1); // check neighboring cells to up direction for value zero and to open it;
    if(j + 1 <  N && f[i][j + 1] == 0) open_zeros(f, pf, i, j + 1); // check neighboring cells to down direction for value zero and to open it;
}

int main(void)
{
    char game_feld[N][N] = { // the array determines the game feld by size N x N;
                    {1, 1, 1, 1, 1},
                    {1, 1, 0, 1, 1},
                    {0, 0, 0, 0, 1},
                    {1, 1, 0, 0, 0},
                    {1, 1, 0, 1, 1},
    };

    char pfeld[N][N] = {0}; // the array determines whethe the cell is open or cloused; 
    show_feld(pfeld); // call the func with all closed cells in game feld initially, that is with symb '#';
    open_zeros(game_feld, pfeld, 2, 2); // 2, 2 are indexes of cell which will be opened firstly;
    puts("---------------"); // delimeter;
    show_feld(pfeld); // show the game feld after recursive check of cells of game feld;

    return 0;
}
