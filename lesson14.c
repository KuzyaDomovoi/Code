#include <stdio.h>

int main(void)
{
    int item;

    printf("1. qwertz\n"
           "2. qwerty\n"
           "3. exit\n");

    if(scanf("%d", &item) != 1) {
        printf("Error input");
        return 0;
    }
    
    switch(item) {
    case 1:
        printf("qwertz\n");
        return 0;
    case 2:
        printf("qwerty\n");
        return 0;
    case 3:
        printf("exit\n");
        return 0;
    
    default:
        printf("incorrect symbol");
        return 0;
    }

    return 0;
}
