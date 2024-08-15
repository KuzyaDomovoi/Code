#include <stdio.h>
#define SIZE 13

void filter(int dst[], size_t size_dst, 
            const int src[], size_t size_src,
            int (*is_correct)(int))
{
    for(long unsigned int i = 0; i < size_dst; ++i) 
        dst[i] = 0; 
    for(long unsigned int  i = 0, j = 0; i < size_src; ++i)
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
    case 1:
        printf("select even values from:\n");
        break;
    case 2:
        printf("select odd values from:\n");
        break;
    case 3:
        printf("select positive values from:\n");
        break;
    case 4:
        printf("select negative values from:\n");
        break;
    case 5:
        printf("selected exit\n");
        return 0;
    default:
        printf("Incorrect symbol!\n");
        return 0;
    }

    int digits[] = {-3, 4, 10, 11, -5, 3, 7, 8, -9, -6, 5, 6, -4};
    int position; // variable for saving the index of a minimal value;
    for(int i = 0; i < (int)(sizeof(digits) / sizeof(*digits)) - 1; ++i) { // irerate array elements from '0' to 'sizeof(digits) / sizeof(*digits)-1';
        position = i; // definition of the position of the first value;
        for(int j = i + 1; j < (int)(sizeof(digits) / sizeof(*digits)); ++j) { // iterate array elements from 'i+1' to 'sizeof(digits) / sizeof(*digits)' and
            if(digits[position] > digits[j]) // search of a minimal value within the array from 'i+1' to 'sizeof(digits) / sizeof(*digits)' (to get a values in ascending order; if '>' change to '<' than get a values in descending order);
                position = j; // saving the index of minimal value to the variable 'pos';
        }
            if(position != i) { // in case when variable 'pos' is different from variable 'i' (-3, the first element of array) than
                int t = digits[i]; // variable 'i' is saved to temporary variable 't',
                digits[i] = digits[position]; // the minimal value from variable 'pos' is saved to the variable 'i' and
                digits[position] = t; // than the value '-3' (from temporary variable 't') is saved to the variable 'pos' (array index instead of minimal value);
            }
    }
    for(int i = 0; i < SIZE; ++i)
        printf("%d ", digits[i]);
    printf("\n");

    int (*criterials[])(int) = {is_even, is_odd, is_positive, is_negative};
    int result[SIZE];
    int index = item -1;
    filter(result, SIZE, digits, sizeof(digits) / sizeof(*digits), criterials[index]);
    int pos; 
    for(int i = 0; i < SIZE - 1; ++i) { 
        pos = i; 
        for(int j = i + 1; j < SIZE; ++j) { 
            if(result[pos] > result[j]) 
                pos = j; 
        }
            if(pos != i) { 
                int t = result[i]; 
                result[i] = result[pos];
                result[pos] = t;
            }
    }
    printf("From in ascending ordered array are selected next values:\n");
    for(int i = 0; i < SIZE; ++i)
        printf("%d ", result[i]);

    return 0;
}
