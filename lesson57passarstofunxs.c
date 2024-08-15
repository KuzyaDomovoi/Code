#include <stdio.h>
#define COLS 3
#define ROWS 2

    int sum_ar(const short arr[], int lehgth) // int sum_ar(const short *arr, int lehgth)
    {
        int res = 0;
        for(int i = 0; i < lehgth; ++i)
            res += arr[i];
        
        return res;
    }

    const char *find_space(const char *buf)
    {
        while(*buf != '\0') { // iterate until the current char is '\0' (EOF) in str;
            if(*buf == ' ') // check if the current char *buf is symb 'space' or not,
                return buf; // if yes - return value buf,
            buf++; // if no - the pointer '*buf' will be incremented;
        }
    }

void show_ar2D(const short (*ar_1)[COLS], int rows)
{
    for(int i = 0; i < rows; ++i) {
        for(int j = 0; j < COLS; ++j)
            printf("%d ", ar_1[i][j]);
        putchar('\n');
    }
}

void show_ar1Dto2D(const short (*ar_2))
{
    short res_ij[ROWS][COLS];
    for(int i = 0; i < ROWS; ++i) { 
        for(int j = 0; j < COLS; ++j) {
            res_ij[i][j] = ar_2[i * COLS + j];
            printf("%d ", res_ij[i][j]);
        }
        putchar('\n');
    }   

}

int main(void)
{

// Passing arrays to funcs:

/*short ar[5] is an array that is as a pointer to continuous memory
fragment, where its elements are stored;
*/
    short ar[] = {1, 2, 3, 4, 5};
    int res = sum_ar(ar, sizeof(ar) / sizeof(*ar)); // ar = const short arr[] (*arr); int length = sizeof(ar) / sizeof(*ar); // 5;
    printf("res = %d\n", res);

    char str[] = "Hallo World!";
    const char *res_1 = find_space(str);
    printf("res_1 = %p\n", res_1);

    short ar_1[][COLS] = {{1, 2, 3}, {4, 5, 6}};
    show_ar2D(ar_1, sizeof(ar_1) / sizeof(*ar_1));

    short ar_2[] = {1, 2, 3, 4, 5, 6};
    show_ar1Dto2D(ar_2);

    return 0;
}
