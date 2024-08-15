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
                     "4. COTAN\n"
                     "5. ASIN\n"
                     "6. ACOS\n"
                     "7. ATAN\n"
                     "8. SQRT\n"
                     "9. POW\n"
                     "0. Exit\n");
            printf("   Select function for calculation: ");
            if(scanf("%d", &calc_item) != 1) {
                printf("\nError input!\n");
                return 0;
            }
            switch(calc_item) {
            case 1:
                printf("\nEnter a value for SIN: ");
                if(scanf("%lf", &a) != 1 ) {
                    printf("\nError input!\n");
                    return 0;
                }
                printf("\nSin(%lf°) = %lf° = %lf rad\n", a, sin(a * RAD), sin(a));
                return 0;
            case 2:
                printf("\nEnter a value for COS: ");
                if(scanf("%lf", &a) != 1 ) {
                    printf("\nError input!\n");
                    return 0;
                }
                printf("\nCos(%lf°) = %lf° = %lf rad\n", a, cos(a * RAD), cos(a));
                return 0;
            case 3:
                printf("\nEnter a value for TAN: ");
                if(scanf("%lf", &a) != 1 ) {
                    printf("\nError input!\n");
                    return 0;
                }
                printf("\nTan(%lf°) = %lf° = %lf rad\n", a, tan(a * RAD), tan(a));
                return 0;
            case 4:
                printf("\nEnter a value for COTAN: ");
                if(scanf("%lf", &a) != 1 ) {
                    printf("\nError input!\n");
                    return 0;
                }
                printf("\nCoTan(%lf°) = %lf° = %lf rad\n", a, -tan(M_PI / 2 - a * RAD), -tan(M_PI / 2 - a));
                return 0; 
            case 5:
                printf("\nEnter a value for ASIN in rad: ");
                if(scanf("%lf", &a) != 1 ) {
                    printf("\nError input!\n");
                    return 0;
                }
                printf("\nASin(%lf rad) = %lf rad\n", a, asin(a));
                return 0;
            case 6:
                printf("\nEnter a value for ACOS in rad: ");
                if(scanf("%lf", &a) != 1 ) {
                    printf("\nError input!\n");
                    return 0;
                }
                printf("\nACos(%lf rad) = %lf rad\n", a, acos(a));
                return 0;
            case 7:
                printf("\nEnter a value for ATAN in rad: ");
                if(scanf("%lf", &a) != 1 ) {
                    printf("\nError input!\n");
                    return 0;
                }
                printf("\nATan(%lf rad) = %lf rad\n", a, atan(a));
                return 0;       
            case 8:
                printf("\nEnter a value for SQRT: ");
                if(scanf("%lf", &a) != 1 ) {
                    printf("\nError input!\n");
                    return 0;
                }
                printf("\nSqrt%lf = %lf\n", a, sqrt(a));
                return 0;
            case 9:
                printf("\nEnter a number and the value separated by space to raise it to POW: ");
                if(scanf("%lf %lf", &a, &b) != 2 ) {
                    printf("\nError input!\n");
                    return 0;
                }
                printf("\n%fpow %lf = %lf\n", a, b, pow(a, b));
                return 0;
            case 0:
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
