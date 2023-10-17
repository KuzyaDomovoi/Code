#include <stdio.h> // fputs(), fgets();

int main(void)
{
    const char* str[] = {
        "- Скажи-ка, дядя, ведь не даром",
        "Я Python, Си учил с каналом",
        "Балакирев что раздавал?"
    };

    FILE* fp = fopen("my_file3.txt", "w");
    if(fp = NULL) {
        perror("my_file3.txt");
        return 1;
    }

    for(int i = 0; i < sizeof(str) / sizeof(*str); ++i)
        fputs(str[i], fp);

    fclose(fp);

    return 0;
}
