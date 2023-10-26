#include <stdio.h>
#include <math.h>

#define ADD(A, B) ((A) + (B))
#define SUB(A, B) ((A) - (B))
#define MUL(A, B) ((A) * (B))
#define DIV(A, B) ((A) / (B))

int main(void)
{
    int calc_mode;
    int calc_action;
    int calc_func;
    double a, b;
    int x;
    
        printf("\n1. Simple_calc\n"
                 "2. i-Calc\n"
                 "3. Exit\n");
        printf("   Select the mode of calculation: ");
        if(scanf("%d", &calc_mode) != 1) {
            printf("\nError input!\n");
            return 0;
        }
        switch(calc_mode) {
        case 1:  

            printf("\nEnter the first number for calculation: ");
            while(scanf("%lf", &a) != 1) {
                printf("\nError input!\n");
                return 0;
            }
            printf("Enter the second number for calculation: ");
            while(scanf("%lf", &b) != 1) {
                printf("\nError input!\n");
                return 0; 
            }
            printf("\n1. Addition\n"
                     "2. Substraction\n"
                     "3. Multiplication\n"
                     "4. Division\n"
                     "5. Exit\n");
            printf("   Select action of calculation: ");

            if(scanf("%d", &calc_action) != 1) {
                printf("\nError input!\n");
                return 0;
            }
            switch(calc_action) {
            case 1:
                double res_add = ADD(a, b);
                printf("\n%f + %f = %f\n", a, b, res_add);
                return 0;
            case 2:
                double res_sub = SUB(a, b);
                printf("\n%f - %f = %f\n", a, b, res_sub);
                return 0;
            case 3:
                double res_mul = MUL(a, b);
                printf("\n%f * %f = %f\n", a, b, res_mul);
                return 0;
            case 4:
                if(b == 0) {
                    printf("\nZeroDivisionError!\n");
                    return 0;
                }
                double res_div = DIV(a, b);
                printf("\n%f / %f = %f\n", a, b, res_div);
                return 0;
            case 5:
                printf("\nEnd of program.\n");
                return 0;
            default:
                printf("\nIncorrect symbol!\n");
                return 0;
            }
        case 2:
            printf("\n1. SIN\n"
                     "2. COS\n"
                     "3. SQRT\n"
                     "4. POW\n"
                     "5. Exit\n");
            printf("   Select function for calculation: ");
            if(scanf("%d", &calc_func) != 1) {
                printf("\nError input!\n");
                return 0;
            }
            switch(calc_func) {
            case 1:
                printf("\nEnter a value for SIN: ");
                while(scanf("%d", &x) != 1 ) {
                    printf("\nError input!\n");
                    return 0;
                }
                double res_sin= sin(x);
                printf("\nSin%d = %f\n", x, res_sin);
                return 0;
            case 2:
                printf("\nEnter a value for COS: ");
                while(scanf("%d", &x) != 1 ) {
                    printf("\nError input!\n");
                    return 0;
                }
                double res_cos = cos(x);
                printf("\nCos%d = %f\n", x, res_cos);
                return 0;
            case 3:
                printf("\nEnter a value for SQRT: ");
                while(scanf("%d", &x) != 1 ) {
                    printf("\nError input!\n");
                    return 0;
                }
                double res_sqrt = sqrt(x);
                printf("\nSqrt%d = %f\n", x, res_sqrt);
                return 0;
            case 4:
                printf("\nEnter a number and the value to raise it to POW separated by space: ");
                while(scanf("%lf %lf", &a, &b) != 2 ) {
                    printf("\nError input!\n");
                    return 0;
                }
                double res_pow = pow(a, b);
                printf("\n%f pow%f = %f\n", a, b, res_pow);
                return 0;
            case 5:
                printf("\nEnd of program.\n");
                return 0;
            default:
                printf("\nIncorrect symbol!\n");
                return 0;
            }
        case 3:
            printf("End of program.\n");
            return 0;    
        default:
            printf("\nIncorrect symbol!\n");
            return 0;
        }
        
    return 0;
}
