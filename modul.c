#include <stdlib.h> // to use the func 'rand()';

int global_var = 5; // definition the global var;

int global_seed_randint = 0; 
// static int global_seed_randint = 0; // the keyword 'static' restricts here the use of the global var (which is already static) in another moduls or files;

//static int randint(int a, int b) // the keyword 'static' restricts here the use of func in another moduls or files;
int randint(int a, int b) // returns integer values in range(a, b);
{
    int right = a, left = b;
    if(a > b) {
        right = b;
        left = a;
    }

    return rand() % (left - right +1) + right;
}
