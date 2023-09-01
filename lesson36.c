#include <stdio.h>

int main(void)
{
    short ar[] = {4, 3, 2, 1, 5, 6, 7};

    short a_1 = *ar; // 4
    short a_4 = *(ar + 3); // 1
    //printf("a_1 = %d, a_4 = %d\n", a_1, a_4);

    for(int i = 0; i < sizeof(ar) / sizeof(*ar); ++i)
        printf("%d ", *(ar + i)); // 4 3 2 1 5 6 7;
    
    printf("\n");

/*- the sizeof operation  returns a numbers of bytes
occupied by the array in the device's memory to array 
pointer.
- the array pointer address is formed at the moment of 
its declaration and remains constant while program is 
running.*/

    short *ptr_ar;
    ptr_ar = ar; // ptr _ar = &ar[0];
    short x = *ptr_ar; // 4;
    *(ptr_ar + 1) = -3; // -3;
    //printf("x1 = %d , x2 = %d\n", x, *(ptr_ar +1));

    size_t len_1 = sizeof(ar); // variable len_ 1 stores the size of all array elements;
    size_t len_2 = sizeof(ptr_ar); // variable len_ 3 stores the size of element 'ptr_ar' in array only;

    // ar++; // !the address of pointer 'ar' is not changeable;
    //ptr_ar++; // but the address of pointer 'ptr_ar' only is changeable;

    short z = ptr_ar[2]; // ar[index] = *(ar + index);
    //short c = 2[ptr_ar]; // is equal to 'ptr_ar[2]', but the '2[ptr_ar]' construction is not to use in C-language;
    printf("z = %d\n", z); // 2;

    return 0;
}
