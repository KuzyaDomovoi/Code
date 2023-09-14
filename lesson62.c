#include <stdio.h>

#define N 5

void show_feld_0(const char (*gf)[N]) // auxiliary func represented as 2D-array to dysplaying the game feld;
{
    for(int i = 0; i < N; ++i) { // iterate the rows of game feld;
        for(int j = 0; j < N; ++j) // terate the cols of game feld;
            printf("%c ", (gf[i][j] == 0) ? '#' : '0'); // output sing '#' if current value is '0' (closed) or sign '0' if current value is '1' (opened);
        putchar('\n'); // transfer the current char in loop to next row;
    }
}

void open_zeros(const char (*gf)[N], char (*pf)[N], int i, int j) // is rcs func and it opens cells ([i], [j]) of game feld which have value 0;
{
    if(gf[i][j] != 0 || pf[i][j] == 1) // if current cell is not zero or (||) is already opened than return (no action);
        return;
    pf[i][j] = 1; // else if current cell is zero and is closed now then it shold be open by rcs func:
    if(i - 1 >= 0 && f[i - 1][j] == 0) open_zeros(gf, pf, i - 1, j); // check neighboring cells to 1 cell left direction for value zero and it to open;
    if(i + 1 <  N && f[i + 1][j] == 0) open_zeros(gf, pf, i + 1, j); // check neighboring cells to 1 cell right direction for value zero and it to open;
    if(j - 1 >= 0 && f[i][j - 1] == 0) open_zeros(gf, pf, i, j - 1); // check neighboring cells to 1 cell up direction for value zero and it to open;
    if(j + 1 <  N && f[i][j + 1] == 0) open_zeros(gf, pf, i, j + 1); // check neighboring cells to 1 cell down direction for value zero and it to open;
}

void show_feld_1(const char (*gf)[N])
{
    for(int i = 0; i < N; ++i) { 
        for(int j = 0; j < N; ++j)
            printf("%c ", (gf[i][j] == 1) ? '#' : '1');
        putchar('\n');
    }
}

void open_ones(const char (*gf)[N], char (*pf)[N], int i, int j) // is rcs func and it opens cells ([i], [j]) of game feld which have value 1;
{
    if(gf[i][j] != 1 || pf[i][j] == 1) // if current cell is not one or (||) is already opened than return (no action);
        return;
    pf[i][j] = 1; // else if current cell is one and is closed now then it shold be open by rcs func:
    if(i - 1 >= 0 && gf[i - 1][j] == 1) open_ones(gf, pf, i - 1, j); // check neighboring cells to 1 cell left direction for value one and it to open;
    if(i + 1 <  N && gf[i + 1][j] == 1) open_ones(gf, pf, i + 1, j); // check neighboring cells to 1 cell right direction for value one and it to open;
    if(j - 1 >= 0 && gf[i][j - 1] == 1) open_ones(gf, pf, i, j - 1); // check neighboring cells to 1 cell up direction for value one and it to open;
    if(j + 1 <  N && gf[i][j + 1] == 1) open_ones(gf, pf, i, j + 1); // check neighboring cells to 1 cell down direction for value one and it to open;
}


int main(void)
{
    char game_feld[N][N] = { // the array define a situation on the game feld by size N x N;
                            {1, 1, 1, 1, 1},
                            {1, 1, 0, 1, 1},
                            {0, 0, 0, 0, 1},
                            {1, 1, 0, 0, 0},
                            {1, 1, 0, 1, 1},
    };

    char play_feld[N][N] = {0}; // the array define whether cells are opened (1) or cloused (0), in this case ( = {0}) all cells are closed to show; 
    show_feld_0(play_feld); // call the func with all closed cells in game feld initially, that is with symb '#';
    open_zeros(game_feld, play_feld, 3, 3); // 2, 2 are indexes of cell which will be opened firstly;
    puts("---------------"); // delimeter;
    show_feld_0(play_feld); // show the game feld after recursive check of cells of game feld;
    open_ones(game_feld, play_feld, 2, 2);
    puts("---------------");
    show_feld_1(play_feld);

    return 0;
}
