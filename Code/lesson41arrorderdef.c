#include <stdio.h>

int main(void)
{
    char a[] = {-3, 5, 0, -8, 1, 10}; // char data type for array;
    int size = sizeof(a) / sizeof(a[0]); // array size define;
    int pos; // variable for saving the index of a minimal value;
    
    for(int i = 0; i < size - 1; ++i) { // irerate array elements from '0' to 'size-1';
        pos = i; // definition of the position of the first value;
        for(int j = i + 1; j < size; ++j) { // iterate array elements from 'i+1' to 'size' and
            if(a[pos] > a[j]) // search of a minimal value within the array from 'i+1' to 'size' (to get a values in ascending order; if '>' change to '<' than get a values in descending order);
                pos = j; // saving the index of minimal value (-8) to the variable 'pos';
        }
            if(pos != i) { // in case when variable 'pos' (-8) is different from variable 'i' (-3, the first element of array) than
                int t = a[i]; // variable 'i' (-3) is saved to temporary variable 't',
                a[i] = a[pos]; // the minimal value (-8) from variable 'pos' is saved to the variable 'i' and
                a[pos] = t; // than the value '-3' (from temporary variable 't') is saved to the variable 'pos' (array index instead of the value '-8');
            }
    }
    for(int i = 0; i < size; ++i) // iterate (read) the elements in the array and
        printf("%d ", a[i]); // output the new array values in ascending order ;
    
    return 0;
}
