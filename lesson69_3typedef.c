#include <stdio.h>

// Typedef directive:

//#define BYTE unsigned char // is processed by preprocessor;
//typedef unsigned char BYTE; // unlike the '#define' directive the 'typedef' statement is processed by the complier itself;

#define PTR_INT int* // declaration the pointer PTR in '#define' directive;

typedef int* PTR; // declaration the pointer PTR in 'typedef' directive;

typedef enum { // so it is a composite typedata, that is after the keyword 'enum' its name is not to assign;
    buffer_size = 2048,
    element_size = 12,
    window_size = 400
} SIZE_CONSTS; // declaration a new datatype of enum for var; name change for enum {...} with using the 'typedef' directive;

int main(void)
{
    //BYTE byte; // BYTE is define here as unsigned char datatype and refers to a var 'byte';
    //BYTE ch, var_ch = '\0'; // is equal the unsigned char ch, var_ch = '\0', which is defined in the block above;
    
    PTR_INT a, b; // with using the '#define' directive are here pointer 'int* a' and var 'b' only (not 'int* b');
    PTR ptr_a, ptr_b; // with using the 'typedef' directive both vars are pointers: int *ptr_a and int *ptr_b;
    
    SIZE_CONSTS sizes = window_size; // var 'sizes' has here the datatype enum {...};
    printf("%d\n", sizes);
    printf("%d\n", buffer_size);

    return 0;
}

/*
void* malloc(size_t size);

'size_t' is here a redefined name with typedef:

typedef unsigned int size_t; // for 32 bit OS; 
typedef unsigned long long size_t; // for 64 bit OS;

the typedef statement can be used to simplify the writing of complex datatypes or multi-dimentional arrays;
*/