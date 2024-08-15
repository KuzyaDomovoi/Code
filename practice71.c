#include <stdio.h>
#include <stdlib.h>

#define MARKS {1, 2, 3, 4, 5, 6, 7, 8, 9};

void* append(short* data, size_t *length, size_t *capacity, short value)
{
    if(*length >= *capacity) {
        short* ar = malloc(sizeof(short) * 2 * *capacity);
        if(ar == NULL)
            return data;
            
        (*capacity) *= 2;
        for(int i = 0;i < *length;++i)
            ar[i] = data[i];
        
        free(data);
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
    short marks[] = MARKS;

    for(int i = 0; i < sizeof(marks) / sizeof(*marks); ++i)
        data = append(data, &length, &capacity, marks[i]);
 
    printf("length = %lu, capacity = %lu\n", length, capacity);
 
    for(int i = 0; i < length; ++i)
        printf("%d ", data[i]);
    free(data);

    return 0;
}
