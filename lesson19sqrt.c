#include <stdio.h>

//#  ##
#define SQ_PR(A, B) ((A) * (B))
#define TEXT(A, B) "Square of rectangle (" #A ") x (" #B ")\n"
#define X_N(N) x ## N

int main(void)
{
    int x = 3, y = 8;
    int res = SQ_PR(x + 2, y - 3); //((x + 2) * (y - 3));
    printf("res = %d\n", res); //25; 
    
    printf(TEXT(x+2, y-3)); //Square of rectangle (x+2) x (y-3);

    int x1 = 1, x2 = -2, x3 = 10;
    printf("%d\n", X_N(3)); // 10 (x3);

    return 0;
}
