#include <stdio.h>                                                                  

struct Example {                                                                                                                                                                                                   
        size_t len;
        char str[];
};
                                                                                                                                                                                                                   
inline int foo(nbr1, nbr2, cmp, eval)                                                                    
void *restrict nbr1, *restrict nbr2;                                                                 
int cmp(), eval();                                                                                                                                                                                                 
{                                                                                                                                                                                                                  
    return cmp(nbr1, nbr2) > 0 ?                                                                                                                                                                               
        foo(nbr2, nbr1, cmp, eval) :                                                                                                                                                                       
        eval(nbr1, nbr2);                                                                                                                                                                                  
}
extern inline int foo();                                                                                                                                                                                           
                                                                                                                                                                                                                   
int sum(int *restrict left, int *restrict right) {                                                                                                                                                                 
    auto int sum = 0;                                                                                   

    for (register int i = *left; i < *right; i++)
        sum += i;                                                                                                                                                                                          
    return sum;
}
                                                                                                                       
int cmp(int *nbr1, int *nbr2) {
    return *nbr1 - *nbr2;
}
                                                                                                                                                                                                                   
int main() 
{                                                                                                                                                                                                       
    printf("%i\n", foo(&(int){20}, &(int){12}, cmp, sum)); 
    return 0;
}
