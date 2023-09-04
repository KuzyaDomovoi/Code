#include <stdio.h>

int main(void)
{
    char a[] = {-3, 5, 0, -8, 1, 10};
    int size = sizeof(a) / sizeof(a[0]);
    int pos; // variable for saving the index of a minimal value;
    
    for(int i = 0; i < size - 1; ++i) {
        pos = i; // define the position of first minimal value;
        for(int j = i + 1; j < size; ++j) {
            if(a[pos] > a[j]) // searching a minimal value within the array from 'i+1' ('j') to 'size' (to get values in ascending order, if '>' change to '<' than get values in descending order);
                pos = j; // saving the index of minimal value;
        }
            if(pos != i) { // in case when variable 'pos' (-8) is different from variable 'i' (-3, the first element of array) than
                int t = a[i]; // variable 'i' (-3) is entered to temporary variable 't',
                a[i] = a[pos]; // the minimal value (-8) from variable 'pos' is entered into the variable 'i' and
                a[pos] = t; // than the value '-3' (from temporary variable 't') is entered into the variable 'pos' (array index instead of the value '-8');
        }
    }
    for(int i = 0; i < size; ++i)
        printf("%d ", a[i]);
    
    return 0;
}
