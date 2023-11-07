#include <stdio.h>

int main(void)
{
// Pointers of 2d arrays:

    char game_pole[3][3] = {1, 2, 3, 4, 5, 6, 7, 8, 9}; // 2d array is 3 strings in 3 columns;
    char *p_row = game_pole[1]; // index '[1]' is the second string of 2d array: 4, 5, 6; 
    printf("%d\n", *p_row); // 4 is an address (the first element of string) of the second 1d array string;
    printf("%d\n", *(p_row - 2)); // 2 ('-' is a shift by two elements to the left);

    char (*p_ar)[3] = game_pole; // parentheses are required here, because it is the pointer to an element with index '[3]' of 2d array (game_pole);
    /* char *ptr[3]; // is not 2d array pointer! If no parentheses hier it is the array of three ([3]) pointers, because priority of index '[3]' is
    higher than priority of '*'; */

    char x = p_ar[0][1]; 
    printf("x = %d\n", x); // x = 2, the variable x saves a value '2' (the second element of first array row '1, 2, 3' (1d array));

    return 0;
}
