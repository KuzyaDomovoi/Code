#include <stdio.h>
#define SIZE 13

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
    printf("Hier is an array of 13 elements: -3, 4, 10, 11, -5, 3, 7, 8, -9, -6, 5, 6, -4;\n");
    printf("1. select even values;\n"
           "2. select odd values;\n"
           "3. select positive values;\n"
           "4. select negative values;\n"
           "5. exit.\n");

    if(scanf("%d", &item) != 1) {
        printf("Error input!\n");
        return 0;
    }
    
    switch(item) 
    {
    case 1: '1';
        printf("selected even values:\n");
        break;
    case 2: '2';
        printf("selected odd values:\n");
        break;
    case 3: '3';
        printf("selected positive values:\n");
        break;
    case 4: '4';
        printf("selected negative values:\n");
        break;
    case 5:
        printf("selected exit\n");
        return 0;
    default:
        printf("incorrect symbol!\n");
        return 0;
    }

    int digits[] = {-3, 4, 10, 11, -5, 3, 7, 8, -9, -6, 5, 6, -4};
    int (*criterials[])(int) = {is_even, is_odd, is_positive, is_negative};
    int result[SIZE];
    int index = item -1;
    filter(result, SIZE, digits, sizeof(digits) / sizeof(*digits), criterials[index]);
    //for(int i = 0; i < SIZE; ++i)
        //printf("%d ", result[i]);
    
    int pos; // variable for saving the index of a minimal value;
    for(int i = 0; i < SIZE - 1; ++i) { // irerate array elements from '0' to 'size-1';
        pos = i; // definition of the position of the first value;
        for(int j = i + 1; j < SIZE; ++j) { // iterate array elements from 'i+1' to 'size' and
            if(result[pos] > result[j]) // search of a minimal value within the array from 'i+1' to 'size' (to get a values in ascending order; if '>' change to '<' than get a values in descending order);
                pos = j; // saving the index of minimal value (-8) to the variable 'pos';
        }
            if(pos != i) { // in case when variable 'pos' (-8) is different from variable 'i' (-3, the first element of array) than
                int t = result[i]; // variable 'i' (-3) is saved to temporary variable 't',
                result[i] = result[pos]; // the minimal value (-8) from variable 'pos' is saved to the variable 'i' and
                result[pos] = t; // than the value '-3' (from temporary variable 't') is saved to the variable 'pos' (array index instead of the value '-8');
            }
    }
    for(int i = 0; i < SIZE; ++i) // iterete (read) the elements in the array and
        printf("%d ", result[i]); // output the new array values in ascending order ;

    return 0;
}
