#include <stdio.h>

// Typedef:

//#define BYTE unsigned char // is processed by preprocessor;
//typedef unsigned char BYTE; // unlike the '#define' directive the 'typedef' statement is processed by the complier itself;

#define PTR_INT int* // directive define;

typedef int* PTR; // typedef statement;

typedef enum {
    buffer_size = 2048,
    element_size = 12,
    window_size = 400
} SIZE_CONSTS;

int main(void)
{
    //BYTE byte;
    //BYTE ch, var_ch = '\0';
    
    PTR_INT a, b; // with using the '#define' sdirective are here pointer 'int* a' and var 'b' only (not 'int* b');
    PTR ptr_a, ptr_b; // with using the 'typedef' statement both vars are pointers: int *ptr_a and int *ptr_b;
    
    SIZE_CONSTS sizes = window_size; // var 'sizes' has here the datatype enum;
    printf("%d\n", sizes);
    printf("%d\n", buffer_size);

    return 0;
}

/*
void* malloc(size_t size);

typedef unsigned int size_t; // for 32 bit OS;
typedef unsigned long long size_t; // for 64 bit OS;

the typedef statement can be used to simplify the writing of complex datatypes or multi-dimentional arrays;
*/