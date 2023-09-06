#include <stdio.h>

#define SIZE 13

int main(void)
{
// Keyword 'const':

    /*Keyword 'const' blocks variable or elements of arrey 
    or pointer's addresses of arrey or arrays completely 
    when it is inserted before their directly.*/

    short ar[] = {4, 3, 2, 1, 5, 6, 7};
    //const short ar[] = {4, 3, 2, 1, 5, 6, 7};
    const short *ptr_1 = ar; // !array address (the first cell) is const (not changeable) at pointer level only (not at cell level), and can be read-only;
    short *const ptr_ar = ar; // !address of element 'ptr_ar' is const (not changeable) at pointer level only, and can be read-only; 
    //ptr_ar = ar; // can not change;
    //ptr_ar[0] = 10; // !error, becouse 'ptr_ar' is declared as constanta!;
    short x = ptr_1[0]; // 4;
    ptr_1++; // 3;
    short *ptr_2 = ar; // !short *ptr_2 = ptr_1 is not avalable;
    ptr_2[0] = 10;
    int a = ptr_1[0];

    const int code = 13; //code = 13 = const and is not to change;
    char str[SIZE]; // not 'code'

    return 0;
}
