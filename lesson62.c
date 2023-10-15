#include <stdio.h>
#define N 5

void show_field_0(const char (*gf)[N]) // represents as 2D-array auxiliary func dysplays the game_field;
{
    for(int i = 0; i < N; ++i) { // iterate the rows of the game_field;
        for(int j = 0; j < N; ++j) // iterate the cols of the ame_field;
            printf("%c ", (gf[i][j] == 0) ? '#' : '0'); // output the sing '#' when the current cell of the game_field is closed(== 0) else - the sign '0';
        putchar('\n'); // transfers the current char in the loop to the next row;
    }
}

void open_zeros(const char (*gf)[N], char (*pf)[N], int i, int j) // the rcs func opens cells ([i], [j]) of the game_field which have value '0';
{
    if(gf[i][j] != 0 || pf[i][j] == 1) 
        return; // returns no action when the current cell by the game_field has not value '0' or it is already opened(== 1) by the play_field;
    pf[i][j] = 1; // else (taht is current cell has value '0' and closed(0) now) it shold be open(1) by rcs func:
    if(i - 1 >= 0 && gf[i - 1][j] == 0) open_zeros(gf, pf, i - 1, j); // checks one step left direction neighboring cells of the game_field for the value '0' and opens it;
    if(i + 1 <  N && gf[i + 1][j] == 0) open_zeros(gf, pf, i + 1, j); // checks one step right direction neighboring cells of the game_fieldfor the alue '0' and opens it;
    if(j - 1 >= 0 && gf[i][j - 1] == 0) open_zeros(gf, pf, i, j - 1); // checks one step up direction neighboring cells of the game_field for the value '0' and opens it;
    if(j + 1 <  N && gf[i][j + 1] == 0) open_zeros(gf, pf, i, j + 1); // checks one step down direction neighboring cells of the game_field for the value '0' and opens it;
}

void show_field_1(const char (*gf)[N])
{
    for(int i = 0; i < N; ++i) { 
        for(int j = 0; j < N; ++j)
            printf("%c ", (gf[i][j] == 0) ? '#' : '1'); // output the sing '#' when the current cell of the game_field is closed(== 0) else - the sign '1';
        putchar('\n');
    }
}

void open_ones(const char (*gf)[N], char (*pf)[N], int i, int j) // the rcs func opens cells ([i], [j]) of the game_field which have value '1';
{
    if(gf[i][j] != 1 || pf[i][j] == 1) 
        return; // returns no action when the current cell by the game_field has not value '1' or it is already opened(== 1) by the play_field;
    pf[i][j] = 1; // else (taht is current cell has value '1' and closed(0) now) it shold be open(1) by rcs func:
    if(i - 1 >= 0 && gf[i - 1][j] == 1) open_ones(gf, pf, i - 1, j); // checks one step left direction neighboring cells of the game_field for the value '1' and opens it;
    if(i + 1 <  N && gf[i + 1][j] == 1) open_ones(gf, pf, i + 1, j); // checks one step right direction neighboring cells of the game_fieldfor the value '1' and opens it;
    if(j - 1 >= 0 && gf[i][j - 1] == 1) open_ones(gf, pf, i, j - 1); // checks one step up direction neighboring cells of the game_field for the value '1' and opens it;
    if(j + 1 <  N && gf[i][j + 1] == 1) open_ones(gf, pf, i, j + 1); // checks one step down direction neighboring cells of the game_field for the value '1' and opens it;
}

void show_all(const char (*gf)[N])
{
    for(int i = 0; i < N; ++i) { 
        for(int j = 0; j < N; ++j)
            printf("%d ", (gf[i][j])); // outputs a value of the current cell of the game_field;
        putchar('\n');
    }
}

int main(void)
{
    char game_field[N][N] = { // the array defines a situation on the game_field by size N x N;
                            {1, 1, 1, 1, 1},
                            {1, 1, 0, 1, 1},
                            {0, 0, 0, 0, 1},
                            {1, 1, 0, 0, 0},
                            {1, 1, 0, 1, 1},
    };

    char play_field[N][N] = {0}; // the array defines whether cells are opened(1) or cloused(0); in this case the all cells are closed; 
    show_field_0(play_field); // calls the func with all closed cells in the game_field initially, that is with the sign '#';
    open_zeros(game_field, play_field, 3, 3); // 3, 3 are indexes of cell which will be opened firstly;
    puts("---------"); // print delimeter;
    show_field_0(play_field); // shows the game_field after recursive check of cells of the game_field;
    open_ones(game_field, play_field, 2, 2);
    puts("---------");
    show_field_1(play_field);
    puts("---------");
    show_all(game_field);

    return 0;
}
