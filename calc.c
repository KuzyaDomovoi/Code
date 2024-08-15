#include <stdio.h>

#define ADD(A, B) ((A) + (B))
#define SUB(A, B) ((A) - (B))
#define MUL(A, B) ((A) * (B))
#define DIV(A, B) ((A) / (B))

int main(void)
{
    int calc_mode;
    double a, b;
    
    printf("Input the first number for calculation: ");
    while(scanf("%lf", &a) != 1) {
            printf("\nError input!\n");
            return 0;
        }
    printf("Input the second number for calculation: ");
    while(scanf("%lf", &b) != 1) {
            printf("\nError input!\n");
            return 0; 
        }

    printf("\n1. addition\n"
             "2. substraction\n"
             "3. multiplication\n"
             "4. division\n"
             "5. exit\n");
    printf("Select the mode of calculation: ");

    if(scanf("%d", &calc_mode) != 1) {
        printf("\nError input!\n");
        return 0;
    }
    switch(calc_mode) {
    case 1:
        printf("\nAddition:\n");
        double res_add = ADD(a, b);
        printf("%f + %f = %f\n", a, b, res_add);
        return 0;
    case 2:
        printf("\nSubstraction:\n");
        double res_sub = SUB(a, b);
        printf("%f - %f = %f\n", a, b, res_sub);
        return 0;
    case 3:
        printf("\nMultiplication:\n");
        double res_mul = MUL(a, b);
        printf("%f * %f = %f\n", a, b, res_mul);
        return 0;
    case 4:
        printf("\nDivision:\n");
        if(b == 0) {
            printf("\nError! Division to '0'.\n");
            return 0;
        }
        double res_div = DIV(a, b);
        printf("%f / %f = %f\n", a, b, res_div);
        return 0;
    case 5:
        printf("\nExit.\n");
        return 0;
    default:
        printf("\nIncorrect symbol!\n");
        return 0;
    }

    return 0;
}
