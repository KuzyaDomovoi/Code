#include <stdio.h>
#include <stdlib.h>
#include <string.h>

size_t mbslen(const char *str) {
    size_t len = strlen(str);
    size_t mb_len = 0;
    for (size_t offset = 0; offset < len; mb_len++,
            offset += mblen(str + offset, len - offset));
    return mb_len;
}

#define SWIDTH(W, STR) (int)(strlen(STR) - mbslen(STR) + W)

int main() 
{
    const char str1[] = "Привет";
    const char str2[] = "Привет мир!";

    printf("%*s\n", SWIDTH(18, str1), str1);
    printf("%*s\n", SWIDTH(18, str2), str2);

    return 0;
}
