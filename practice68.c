#include <stdio.h>
#include <stdlib.h>

void* append(short* data, size_t *length, size_t *capacity, short value)
{
    if(*length >= *capacity) {
        short* ar = realloc(data, sizeof(short) * 2 * *capacity);
        if(ar == NULL)
            return data;
        (*capacity) *= 2;
        data = ar;
    }
 
    data[*length] = value;
    (*length)++;
    
    return data;
}
 
int main(void) 
{
    size_t capacity = 10;
    size_t length = 0;
 
    short* data = malloc(sizeof(short) * capacity);
 
    for(int i = 0; i < 11; ++i)
        data = append(data, &length, &capacity, rand() % 40 - 20);
 
    printf("length = %lu, capacity = %lu\n", length, capacity);
 
    for(int i = 0;i < length; ++i)
        printf("%d ", data[i]);
    free(data);

    return 0;
}
