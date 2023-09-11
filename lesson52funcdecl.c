#include <stdio.h>

int get_per(int width, int height) /* func declar with
two params: width and height;*/
{
    int p = 2*(width + height); // calc of func get_per;
    return p; // result of var p is returned;
}

int main(void)
{
    int w = 2, h = 5;
/*while the func is called it must have the two arg 
because it had two param by declaration;*/
    
    get_per(w, h);
    /* func is called for a side effect without to save
    the value of var p anywhere (to check);*/
    
    int per_1 = get_per(w + 1, h - 4);
    /* func is called with arguments (w+1 (3) and h-4 (1))
    because they parameters (width and height) have a 
    values now;*/
    
    int per_2 = get_per(w, 3);
    int per_3 = get_per(1, 3);

    printf("%d %d %d\n", per_1, per_2, per_3);

    return 0;
}
