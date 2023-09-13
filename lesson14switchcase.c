#include <stdio.h>

int main(void)
{
    int item; //char; coorection sumbol to upper(lower) register': a' to 'A';

    printf("1. qwertz\n" //none;
           "2. qwerty\n" //none;
           "3. exit\n"); //none;

    if(scanf("%d", &item) != 1) { //"%c";
        printf("Error input\n");
        return 0;
    }
    
    switch(item) {
    case 1: //case 'a':
            //case 'A':
        printf("qwertz\n");
        return 0; //break;
    case 2: //case 'b':
            //case 'B':
        printf("qwerty\n");
        return 0; //break;
    case 3: //case 'c':
            //case 'C':
        printf("exit\n");
        return 0; //break;
    
    default:
        printf("incorrect symbol\n");
        return 0;
    }

    return 0;
}
