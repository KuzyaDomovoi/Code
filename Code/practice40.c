#include <stdio.h>

int main(void)
{
    char ar[] = {8, 4, 1, 3, 6, 7, 9, 0, 2, 6};
    int size = sizeof(ar) / sizeof(ar[0]);
    int repit;
    int pos;
    
    for(int i = 0; i < size; ++i) {
        repit = i;
        for(int j = i + 1; j < size; ++j) {
            if(ar[repit] != ar[j])
                repit = i; 
            else
                for(int k = repit; k < size; ++k) {
                    ar[k] = ar[k + 1];
                }
        }
    }

    for(int i = 0; i < size; ++i)
        printf("%d ", ar[i]);
        printf("\n");

    int ins = 9;
    ar[ins] = 5;
          
    for(int i = 0; i < size; ++i)
        printf("%d ", ar[i]);
        printf("\n");

    for(int i = 0; i < size; ++i) {
        pos = i;
        for(int j = i + 1; j < size; ++j) {
            if(ar[pos] > ar[j])
                pos = j;
        }       
            if(pos != i) {
                int t = ar[i];
                ar[i] = ar[pos];
                ar[pos] = t;
            }
    }
    for(int i = 0; i < size; ++i)
        printf("%d ", ar[i]);

    return 0;
}
