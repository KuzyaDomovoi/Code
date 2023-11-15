#include <stdio.h>
#include <math.h>

#define ADD(A, B) ((A) + (B))
#define SUB(A, B) ((A) - (B))
#define MUL(A, B) ((A) * (B))
#define DIV(A, B) ((A) / (B))

#define M_PI 3.14159265358979323846
#define RAD  M_PI / 180.0
#define DEG  180.0 / M_PI

int main(void)
{
    int calc_item;
    double a, b;
    int x;
    
        printf("\n1. Simple_calc\n"
                 "2. i-Calc\n"
                 "3. Exit\n");
        printf("   Select the mode of calculation: ");
        if(scanf("%d", &calc_item) != 1) {
            printf("\nError input!\n");
            return 0;
        }
        switch(calc_item) {
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

            if(scanf("%d", &calc_item) != 1) {
                printf("\nError input!\n");
                return 0;
            }
            switch(calc_item) {
            case 1:
                printf("\n%f + %f = %f\n", a, b, ADD(a, b));
                return 0;
            case 2:
                printf("\n%f - %f = %f\n", a, b, SUB(a, b));
                return 0;
            case 3:
                printf("\n%f * %f = %f\n", a, b, MUL(a, b));
                return 0;
            case 4:
                if(b == 0) {
                    printf("\nZeroDivisionError!\n");
                    return 0;
                }
                printf("\n%f / %f = %f\n", a, b, DIV(a, b));
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
                     "3. TAN\n"
                     "4. ASIN\n"
                     "5. ACOS\n"
                     "6. ATAN\n"
                     "7. SQRT\n"
                     "8. POW\n"
                     "9. Exit\n");
            printf("   Select function for calculation: ");
            if(scanf("%d", &calc_item) != 1) {
                printf("\nError input!\n");
                return 0;
            }
            switch(calc_item) {
            case 1:
                printf("\nEnter a value for SIN: ");
                if(scanf("%d", &x) != 1 ) {
                    printf("\nError input!\n");
                    return 0;
                }
                printf("\nSin%d° = %f\n", x, sin(x * RAD));
                return 0;
            case 2:
                printf("\nEnter a value for COS: ");
                if(scanf("%d", &x) != 1 ) {
                    printf("\nError input!\n");
                    return 0;
                }
                printf("\nCos%d° = %f\n", x, cos(x * RAD));
                return 0;
            case 3:
                printf("\nEnter a value for TAN: ");
                if(scanf("%d", &x) != 1 ) {
                    printf("\nError input!\n");
                    return 0;
                }
                printf("\nTan%d° = %f\n", x, tan(x * RAD));
                return 0; 
            case 4:
                printf("\nEnter a value for ASIN: ");
                if(scanf("%d", &x) != 1 ) {
                    printf("\nError input!\n");
                    return 0;
                }
                printf("\nASin%d° = %f\n", x, asin(x * RAD));
                return 0;
            case 5:
                printf("\nEnter a value for COS: ");
                if(scanf("%d", &x) != 1 ) {
                    printf("\nError input!\n");
                    return 0;
                }
                printf("\nACos%d° = %f\n", x, acos(x * RAD));
                return 0;
            case 6:
                printf("\nEnter a value for TAN: ");
                if(scanf("%d", &x) != 1 ) {
                    printf("\nError input!\n");
                    return 0;
                }
                printf("\nATan%d° = %f\n", x, atan(x * RAD));
                return 0;       
            case 7:
                printf("\nEnter a value for SQRT: ");
                if(scanf("%d", &x) != 1 ) {
                    printf("\nError input!\n");
                    return 0;
                }
                printf("\nSqrt%d = %f\n", x, sqrt(x));
                return 0;
            case 8:
                printf("\nEnter a number and the value to raise it to POW separated by space: ");
                if(scanf("%lf %lf", &a, &b) != 2 ) {
                    printf("\nError input!\n");
                    return 0;
                }
                printf("\n%fpow %f = %f\n", a, b, pow(a, b));
                return 0;
            case 9:
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
