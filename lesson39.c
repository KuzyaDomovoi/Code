#include <stdio.h>

int main(void)
{
    float func_1[100] = {2.4, -3.8, 0, 10.2, 11.78, -5.43};
    int func_2[50]; // float; double;

    int size_1 = sizeof(func_1) / sizeof(func_1[0]);
    int size_2 = sizeof(func_2) / sizeof(func_2[0]);
    int size = (size_1 < size_2) ? size_1 : size_2;

    for(int i = 0; i < size; ++i)
        func_2[i] = (int)func_1[i];

    for(int i = 0; i < size; ++i)
        printf("%d ", func_2[i]); // "%.2f ";

    return 0;
}
