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
    int x, y;

    printf("\n1. simple calc\n"
             "2. i_calc\n");
    printf("Select mode of calculation: ");
    if(scanf("%d", &calc_mode) != 1) {
        printf("\nError input!\n");
        return 0;
    }
    switch(calc_mode) {
    case 1:        
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
        printf("Select action of calculation: ");

        if(scanf("%d", &calc_action) != 1) {
            printf("\nError input!\n");
            return 0;
        }
        switch(calc_action) {
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
    case 2:
        printf("Input a number for calculation: ");
        while(scanf("%lf %lf", &x, &y) != 1) {
            printf("\nError input!\n");
            return 0;
        }
        printf("\n1. SIN\n"
                 "2. COS\n"
                 "3. SQRT\n"
                 "4. POW\n"
                 "5. exit\n");
        printf("Select function for calculation: ");
        
        if(scanf("%d", &calc_func) != 1) {
            printf("\nError input!\n");
            return 0;
        }
        switch(calc_func) {
        case 1:
            printf("\nSIN:\n");
            double res_sin= sin(x);
            printf("sin%d = %f\n", x, res_sin);
            return 0;
        case 2:
            printf("\nCOS:\n");
            double res_cos = cos(x);
            printf("cos%d = %f\n", x, res_cos);
            return 0;
        case 3:
            printf("\nSQRT:\n");
            double res_sqrt = sqrt(x);
            printf("sqrt%d = %f\n", x, res_sqrt);
            return 0;
        case 4:
            printf("\nPOW:\n");
            double res_pow = pow(x, y);
            printf("%d pow%d = %f\n", x, y, res_pow);
            return 0;
        case 5:
            printf("\nExit.\n");
            return 0;
        default:
            printf("\nIncorrect symbol!\n");
            return 0;
        }
    }
    return 0;
}
