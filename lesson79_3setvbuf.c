#include <stdio.h>

// setvbuf() is the func that creats iobuffer

#include <stdio.h>
 
enum {buffer_size = 512, data_size = 100};
 
int main(void)
{
    char buffer[buffer_size] = {0};
    char data[data_size];
 
    FILE* fp = fopen("data_rubusd_2.csv", "r");
    if(fp == NULL) {
        perror("data_rubusd_2.csv");
        return 1;
    }
 
    if(setvbuf(fp, buffer, _IOFBF, buffer_size) != 0) {
        puts("Incorrect type or size of buffer");
        return 2;
    }
 
    fgets(data, sizeof(data), fp);
    puts(buffer);
    puts("----------------");
    puts(data);
 
    fclose(fp);
    return 0;
}
