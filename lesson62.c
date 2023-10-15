#include <stdio.h>
#define N 5

void show_field_0(const char (*gf)[N]) // represented as 2D-array auxiliary func dysplays the game field;
{
    for(int i = 0; i < N; ++i) { // iterate the rows of game field;
        for(int j = 0; j < N; ++j) // iterate the cols of game field;
            printf("%c ", (gf[i][j] == 0) ? '#' : '0'); // output sing '#' if the urrent cell of game_field is closed(== 0) else - sign '0';
        putchar('\n'); // transfers the current char in loop to next row;
    }
}

void open_zeros(const char (*gf)[N], char (*pf)[N], int i, int j) // the rcs func opens cells ([i], [j]) of game feld which have value '0';
{
    if(gf[i][j] != 0 || pf[i][j] == 1) 
        return; // returns no action if current cell by game_field has not value '0' or it is already opened(== 1) by play_field;
    pf[i][j] = 1; // else (taht is current cell has value '0' and closed(0) now) it shold be open(1) by rcs func:
    if(i - 1 >= 0 && gf[i - 1][j] == 0) open_zeros(gf, pf, i - 1, j); // check neighboring cells to 1 cell left direction for value zero and it to open;
    if(i + 1 <  N && gf[i + 1][j] == 0) open_zeros(gf, pf, i + 1, j); // check neighboring cells to 1 cell right direction for value zero and it to open;
    if(j - 1 >= 0 && gf[i][j - 1] == 0) open_zeros(gf, pf, i, j - 1); // check neighboring cells to 1 cell up direction for value zero and it to open;
    if(j + 1 <  N && gf[i][j + 1] == 0) open_zeros(gf, pf, i, j + 1); // check neighboring cells to 1 cell down direction for value zero and it to open;
}

void show_field_1(const char (*gf)[N])
{
    for(int i = 0; i < N; ++i) { 
        for(int j = 0; j < N; ++j)
            printf("%c ", (gf[i][j] == 0) ? '#' : '1'); // output sing '#' if the urrent cell of game_field is closed(== 0) else - sign '1';
        putchar('\n');
    }
}

void open_ones(const char (*gf)[N], char (*pf)[N], int i, int j) // the rcs func opens cells ([i], [j]) of game feld which have value '1';
{
    if(gf[i][j] != 1 || pf[i][j] == 1) 
        return; // returns no action if current cell by game_field has not value '1' or it is already opened(== 1) by play_field;
    pf[i][j] = 1; // else (taht is current cell has value '1' and closed(0) now) it shold be open(1) by rcs func:
    if(i - 1 >= 0 && gf[i - 1][j] == 1) open_ones(gf, pf, i - 1, j); 
    if(i + 1 <  N && gf[i + 1][j] == 1) open_ones(gf, pf, i + 1, j); 
    if(j - 1 >= 0 && gf[i][j - 1] == 1) open_ones(gf, pf, i, j - 1); 
    if(j + 1 <  N && gf[i][j + 1] == 1) open_ones(gf, pf, i, j + 1); 
}

void show_all(const char (*gf)[N])
{
    for(int i = 0; i < N; ++i) { 
        for(int j = 0; j < N; ++j)
            printf("%d ", (gf[i][j]));
        putchar('\n');
    }
}

int main(void)
{
    char game_field[N][N] = { // the array define a situation on the game field by size N x N;
                            {1, 1, 1, 1, 1},
                            {1, 1, 0, 1, 1},
                            {0, 0, 0, 0, 1},
                            {1, 1, 0, 0, 0},
                            {1, 1, 0, 1, 1},
    };

    char play_field[N][N] = {0}; // the array define whether cells are opened (1) or cloused (0), in this case ( ... = {0}) all cells are closed to show; 
    show_field_0(play_field); // call the func with all closed cells in game field initially, that is with symb '#';
    open_zeros(game_field, play_field, 3, 3); // 3, 3 are indexes of cell which will be opened firstly;
    puts("---------"); // print delimeter;
    show_field_0(play_field); // show the game field after recursive check of cells of game field;
    open_ones(game_field, play_field, 2, 2);
    puts("---------");
    show_field_1(play_field);
    puts("---------");
    show_all(game_field);

    return 0;
}
