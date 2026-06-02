#include <stdio.h>

int main(void)
{
// n-dimentional arrays:

    char game_pole_1[3][3] = {1, 2, 3, 4}; // 2d array which elements are listed in sequential order;
    char game_pole_2[3][3] = {{1, 2}, {3, 4}}; // 2d array which elements are listed in string order;
    double ar_3d[3][4][5] = {{1}, {2}, {3}}; // 3d array is 3 blocks of 4 strings in 5 columns;
    short ar_4d[5][2][10][3]; // 4d array;

    double val = ar_3d[1][0][1]; // acces to 3d array elements (indices);
    short res = ar_4d[0][1][5][2]; // acces to 4d array elements (indices);

/*In programming practice is better to avoid using of 
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
        printf("\n"); /*1 2 0 
                        3 4 0 
                        0 0 0;*/
    }

    for(int i = 0; i < 3; ++i) {
        for(int j = 0; j < 4; ++j) {
            for(int k = 0; k < 5; ++k)
                printf("%.f ", ar_3d[i][j][k]);
            printf("\n");   
        }    
    }

    return 0;
}
