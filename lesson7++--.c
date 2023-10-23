#include <stdio.h>

int main(void)
{
    int count = 0, size = 5;

    int current = count++; //the variable count is unary and incremented after math calculations: 0 = 0; ++ = 1;
    int wight = ++size; //the variable size is unary and decremented before math calculations: 5 ++ = 6;

    int p = 2 * size++; //the variable size is unary and incremented after math calcutations: = 2 * 6; 6 ++ = 7;
    int r = 3 * --wight; //the variable wight is unary and decremented before math calculations: 3 * (6 -- = 5); 5;
    
    int wight1 = 5;
    --wight1; //5 -- = 4;
    int size1 = wight1 * wight1 + (10 + wight1); //the variable size1 = 4 * 4 + (10 +4) = 30;
    wight1++; // 4 ++ = 5;

    printf("count = %d, size = %d, current = %d, wight = %d, wight1 = %d\n", count, size, current, wight, wight1);
    
    printf("p = %d, r = %d\n", p, r);

    printf("size1 = %d\n", size1);
    
    return 0;
}
