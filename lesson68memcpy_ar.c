#include <stdio.h>
#include <stdlib.h> // to use funcs malloc() and free();
#include <string.h> // to use func memcpy();

// Heap. Allocating (func malloc()) and freeing (func free()) the memory;
// Memory manager;

void *append(short *data, size_t *length, size_t *capacity, short value)
{
    if(*length >= *capacity) { // condition for comparing of size of current length of array with size of defined capacity (10);
        (*capacity) *= 2;
//      short *ar = malloc(sizeof(short) * *capacity); // creating new temp array 'ar', malloc for it and doubling it;
        
        short *ar = realloc(data, sizeof(short) * *capacity);

        if(ar == NULL) // if malloc will not be performed than
            return data; // return value data;
        data = ar;

//      memcpy(ar, data, *length * sizeof(short));
/*
        for(int i = 0; i < *length; ++i) // iterating the array 'data' and
            ar[i] = data[i]; // copying values from prior array 'data' to temp array 'ar';
        free(data); // freeing  up the heap for prior array 'data';
*/
/*
        data = ar; // copying the new address from temp array 'ar' to array 'data';
*/   
    }

    data[*length] = value; // assigning the last added (new) values to allready doubled array 'data';
    (*length)++; // incrementation of *length;
    return data; // returning the (perhaps changed) address of array 'data'(after using func 'append()');
}

int main(void)
{
/*
    char *ar = malloc(10); // return NULL or memory allocating (malloc) for 10 bytes from Heap (main memory section);
    int *ptr_int = malloc(sizeof(int)); // return NULL or memory allocating (malloc) for size value of datatype 'int' (4 bytes) from Heap (main memory section);
    short * ptr_short = malloc(7 * (sizeof(short))); // return NULL or memory allocating  (malloc) for 7 elements of value of datatype short (2 bytes) = 14 bytes from Heap (main memory section);

    free(ar); // freeing up the Heap for *ar;
    free(ptr_int); // freeing up the Heap for *ptr_int;
    free(ptr_short); // freeing up the Heap for *ptr_short;
*/
// Memory leak;

// Dynamical array:

    size_t capacity = 10;
    size_t length = 0;

    short *data = malloc(sizeof(short) * capacity);

    for(int i = 0; i < 11; ++i)
    //for(int i = 0; i < 9; ++i)
        data = append(data, &length, &capacity, rand() % 40 - 20); // func 'append()' passes new values to array '*data';
    printf("length = %lu, capacity = %lu\n", length, capacity);

    for(int i = 0; i < length; ++i) // iterate a new values to output their (11) additionaliy;
        printf("%d ", data[i]);
    free(data);

    return 0;
}

/*
stdlib.h:

void* calloc(size_t nmemb, size_t size); // allocates a memory for elements 'nmemb', where each element has a 'size' and fills it with '0';
void* realloc(void *ptr, size_t length); // changes a size of previosly allocated memory to which the pointer '*ptr' points, defines a new size with the pstsm 'length' and frees up the Heap automatically;

string.h:

void* memcpy(void* restrict dts, const void* restrict src, size_t length); // copies one string into the other, where keyword restrict defines the pointers 'dst' and 'src' as unique and each of them leads to an separate non-overlapping memory section in the Heap;
void* memmove(void* dts, const void* src, size_t length); // transfers a fagment from one string into the other;

*/