#include <stdio.h>

// Enumeration: 'enum'; The keyword enum is using to enumeration vars which are integer const data type whlie the compilation is started;

enum colors {red, green, blue};
enum keys {vk_enter = 27, vk_space, vk_del = 30};
enum {
    go = 0x1f00,
    stop = 0x0001,
    forward = go,
    run = 0x00a2,
    back = run - 1
};

int main(void)
{
    printf("red = %d, green = %d, blue = %d\n", red, green, blue);
    
    enum keys k_var = vk_enter + 2 - vk_space * 100; // the var 'k_var' is an int datatype while the compilation and can take any value;

    switch (k_var) {
    case vk_enter:
        puts("vk_enter");
        break;
    case vk_space:
        puts("vk_space");
        break;
    case vk_del:
        puts("vk_del");
        break;
    }

    return 0;
}
