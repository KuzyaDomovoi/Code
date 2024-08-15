#include <stdio.h>

int main(void)
{
    long l;
    float fp;
    char s[15];
    char c;

    FILE *stream = fopen("data.txt", "w+");
    if(!stream) return !0;
    fprintf(stream, "%s %d %f %c", "a-string", 65000, 3.14159, 'x');
    fseek(stream, 0L, SEEK_SET);
    fscanf(stream, "%s %ld %f %c", s, &l, &fp, &c);
    printf("%s\n%ld\n%f\n%c\n", s, l, fp, c);
    fclose(stream);
}
