#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <printf.h>

int print_centered_string_to_stream(FILE *stream, const char *s, unsigned int width) {
    const size_t len = strlen(s);

    /* If the length of the string is greater than the width
     * just print the original string. */
    if (len >= width)
        return fprintf(stream, "%s\n", s);

    /* Calculate the padding. */
    const unsigned int p = (len >= width) ? 0 : (width - len) / 2;

    return fprintf(stream, "%*.*s%s%*.*s", p, p, " ", s, p, p, " ");
}

int printf_centered_string(FILE *stream, const struct printf_info *info, const void *const *args) {
    const char *s = *((const char **) (args[0]));
    return print_centered_string_to_stream(stream, s, info->width);
}

int printf_centered_string_arginfo(const struct printf_info *info, size_t n, int *argtypes, int *size) {
    if (n > 0)
        argtypes[0] = PA_POINTER;

    return 1;
}

int main(void)
{
    register_printf_specifier('Q', printf_centered_string, printf_centered_string_arginfo);

    const char str1[] = "Привет, мир";

    printf("|%50Q|\n", str1);
    printf("|%80Q|\n", str1);
    printf("|%25Q|\n", str1);

    return 0;
}