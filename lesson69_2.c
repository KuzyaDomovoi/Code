#include <stdio.h>

enum colors {red, green, blue} wnd_colors;
enum keys {vk_enter = 27, vk_space, vk_del = 30};
enum {
    go = 0x1f00,
    stop = 0x0001,
    forward = go,
    run = 0x00a2,
    back = run - 1
} actions, commands;

int main(void)
{
    enum keys k_var; // int;

    return 0;
}
