#include <stdio.h>

// Enumeration: 'enum'; The keyword enum is using to enumeration vars which are integer constants whlie the compilation is started;

enum colors {red, green, blue}; // enum is a keyword; colors is a name of enum; red, green and blue are integer constants of enum;
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
    
    enum keys k_var = vk_enter + 2 - vk_space; // the (int) 'k_var' is a var of 'enum keys' datatype and can take any value;

    return 0;
}
