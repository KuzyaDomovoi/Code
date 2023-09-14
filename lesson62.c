#include <stdio.h>

#define N 5

void show_feld(const char (*p)[N])
{
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < N; ++j)
            printf("%c ", (p[i][j] == 0) ? '#' : '0');
        putchar('\n');
    }
}

void open_zeros(const char (*f)[N], char (*pf)[N], int i, int j)
{
    if(f[i][j] != 0 || pf[i][j] == 1)
        return;
    pf[i][j] = 1;
    if(i - 1 >= 0 && f[i - 1][j] == 0) open_zeros(f, pf, i - 1, j);
    if(i + 1 <  N && f[i + 1][j] == 0) open_zeros(f, pf, i + 1, j);
    if(j - 1 >= 0 && f[i][j - 1] == 0) open_zeros(f, pf, i, j - 1);
    if(j + 1 <  N && f[i][j + 1] == 0) open_zeros(f, pf, i, j + 1);
}

int main(void)
{
    char game_feld[N][N] = {
                    {1, 1, 1, 1, 1},
                    {1, 1, 0, 1, 1},
                    {0, 0, 0, 0, 1},
                    {1, 1, 0, 0, 0},
                    {1, 1, 0, 1, 1},
    };

    char pfeld[N][N] = {0};
    show_feld(pfeld);
    open_zeros(game_feld, pfeld, 2, 2);
    puts("---------------");
    show_feld(pfeld);

    return 0;
}
