#include <stdio.h> // fputs(), fgets();
#include <string.h> // strchr();

int main(void)
{
    const char* str[] = {
        "- Скажи-ка, дядя, ведь не даром",
        "Я Python, Си учил с каналом",
        "Балакирев что раздавал?"
    };
    
    char buffer[100];

    FILE* fp = fopen("my_file3.txt", "w");
    if(fp == NULL) {
        perror("my_file3.txt");
        return 1;
    }

    for(int i = 0; i < sizeof(str) / sizeof(*str); ++i) {
        fputs(str[i], fp);
        fputc('\n', fp);
    }
    
    fclose(fp);

    FILE* fr = fopen("my_file3.txt", "r");
    if(fr == NULL) {
        perror("my_file3.txt");
        return 1;
    }

    while(fgets(buffer, sizeof(buffer), fr)) { // the func fgets() reads data from the 'buffer' correctly until 'sizeof(buffer) - 1' in the stream 'fr' because it appends the symbol '\n' to the end of the string automatically and returns the NULL at the end of reading;
        char *ptr = strchr(buffer, '\n'); // the func strchr() finds and changes the char '\n'(str brake) which was been added by the func 'fgets()' to char '\0'(EOF) in the 'buffer' in each string read;
        if(ptr != NULL) // the func strchr() is in action while the pointer will be not equaled the NULL (that is the end of each current string);
            *ptr = '\0'; // and to pointer is assigned the char '\0';
        puts(buffer); // puts the string from the 'buffer' without empty strings finally;
    }

    fclose(fr);

    return 0;
}
