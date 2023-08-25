#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    //double x = 5.67;
    //int var_i = 7;
    //bool fl_view = x < 10;       // true;
    //bool res_1 = 5 > 7;          // false;
    //bool res_2 = x + 2 >= 10.56; // false;
    //bool res_3 = var_i == 7;     // true;
    //bool res_4 = var_i != 7;     // false;

    /*int digit;
    scanf("%d", &digit);
    bool even = digit % 2 == 0;
    printf("%d\n", even);*/
    
    double x = 10.23;
    bool is_range = x >= -2 && x <= 5; //&& mean "and";
    bool is_not_range = !is_not_range; //bool is_not_range = x <= -2 || x >= 5; //|| mean "or";
    printf("%d, %d\n", is_range, is_not_range);
    
    int y = 15;
    bool is_correct = (y % 2 == 0 || y % 3 == 0) && y > 5;
    printf("%d\n", is_correct);
    
    return 0;
    }

/*signs priorety:
    "not" !   1;
    "and" &&  2;
    "or"  ||  3;*/
