#include <stdio.h>
#define SIZE 15

void filter(int dst[], size_t size_dst, 
            const int src[], size_t size_src,
            int (*is_correct)(int))
{
    for(int i = 0; i < size_dst; ++i) 
        dst[i] = 0; 
    for(int i = 0, j = 0; i < size_src; ++i)
        if(is_correct(src[i]))
            dst[j++] = src[i];
}

int is_even(int x) 
{
    return x % 2 == 0; 
}

int is_positive(int x)
{
    return x > 0;
}

int is_odd(int x)
{
    return x % 2 != 0;
}

int is_negative(int x)
{
    return x < 0;
}

int main(void)
{
    int item;
    int select_id;
    printf("Hier is an array: -3, 4, 10, 11, -5, 3, 7, 8, -9, -6, 5, 6, -4;\n");
    printf("1. select_even_values;\n"
           "2. select_odd_values;\n"
           "3. select_positive_values;\n"
           "4. select_negative_values;\n"
           "5. exit.\n");

    if(scanf("%d", &item) != 1) {
        printf("Error input!\n");
        return 0;
    }
    
    switch(item) 
    {
    case 1: '1';
        printf("select_even_values:\n");
        break;
    case 2: '2';
        printf("select_odd_values:\n");
        break;
    case 3: '3';
        printf("select_positive_values:\n");
        break;
    case 4: '4';
        printf("select_negative_values:\n");
        break;
    case 5:
        printf("exit\n");
        return 0;
    default:
        printf("incorrect symbol!\n");
        return 0;
    }

    int digits[] = {-3, 4, 10, 11, -5, 3, 7, 8, -9, -6, 5, 6, -4};
    int (*criterials[])(int) = {is_even, is_odd, is_positive, is_negative};
    int result[SIZE];
    select_id = item;
    int index = select_id -1;
    filter(result, SIZE, digits, sizeof(digits) / sizeof(*digits), criterials[index]);
    for(int i = 0; i < SIZE; ++i)
        printf("%d ", result[i]);

    return 0;
}
