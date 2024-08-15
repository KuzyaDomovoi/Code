#include <stdio.h>

int main(void)
{
    int count = 1;
    double var_d = 10.0;
    short p = 2;


    //count = count + 3;
    count -= 3 - 5; // 1 - (- 2) = 3;
    var_d /= 3.0 + p; //10 / (3.0 + 2) = 2.00;
    p *= 20 - 5; //2 * (20 - 5) = 30;

    printf("count = %d, var_d = %.2f, p = %d\n", count, var_d, p);

    //ar[get_index()] = ar[get_index()] + 1;
    //ar[get_index()] += 1;

    return 0;
}
// calculation ptiority in C:
// -- and ++ 1;
// % and %=  1;
// / and /=  2;
// * and *=  2;
// - and -=  3;
// + and +=  3;
