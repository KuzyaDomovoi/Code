#include <stdio.h>

int main(void)
{
// n-dimentional arrays:

    char game_pole_1[3][3] = {1, 2, 3, 4}; // two-dimentional array which elements are listed in sequential order;
    char game_pole_2[3][3] = {{1, 2}, {3, 4}}; // two-dimentional array which elements are listed in string order;
    double ar_3d[3][4][5]; // 3d-array;
    short ar_4d[5][2][10][3][]; // 4d-array;

    double val = ar_3d[1][0][1]; // acces to 3d-array elements (indices);
    short res = ar_4d[0][1][5][2]; // acces to 4d-array elements (indices);

/*In the programming praactice it is better to avoid using of 
multidimentional arrays*/

    for(int i = 0; i < 3; ++i) {
        for(int j = 0; j < 3; ++j)
            printf("%d ", game_pole_1[i][j]);
        printf("\n"); /* 1 2 3 
                         4 0 0 
                         0 0 0;*/
    }

    for(int i = 0; i < 3; ++i) {
        for(int j = 0; j < 3; ++j)
            printf("%d ", game_pole_2[i][j]);
        printf("\n");

    }

    return 0;
}
