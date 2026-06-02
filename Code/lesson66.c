#include <stdio.h>

int main(void)
{
    int t = 3; // located in boby func main();
    while(t-- > 0) { // loop 'while' creats own data block in which is declared another local 'int var t' and take the first var 'int t';
        int t = 10; // the var 'int t' is located inside the block {...} and is loop's condition independent var;
        t--; // 10 - 1;
        printf("t = %d\n", t); // = 9;
    }    

    printf("main: t = %d\n", t); // result from t = 3 and loop condition 't-- > 0'

    int z = 33; // located in boby func main();
    for(int z = 0; z < 3; ++z) { // loop 'for' creats own data block in which is declared another local 'int var z';
        printf("z = %d\n", z); // 0, 1, 2 are < 3;
    }

    printf("main: z = %d\n", z); // z = 33;

    int p = 1; // var 'p' in which will be saved the result's value of n! calc;
    int n = 7; // var 'n' from which the factorial is calculated;
    for(register int i = 2; i <= n; ++i) // keyword register allows to locate the values to the CPU;
        p *= i; // result of n!;
    printf("p = %d\n", p); // 5040;
    
    return 0;
}
