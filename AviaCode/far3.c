#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/mman.h>
#include <stdlib.h>

typedef struct node_s *node_t;

struct node_s {
    char    *label;
    double  value;
    node_t  next;
};

int main(void)
{
    int size = 0;
    char *file;
    int fr = open("gpsd.txt", O_RDONLY);
    if(fr < 0)
        return 1;
    size = lseek(fr, 0L, SEEK_END);
    lseek(fr, 0L, SEEK_SET);
    file = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_PRIVATE, fr, 0);
    size -= 4;
    file += 2;
    node_t table = malloc(sizeof *table);
    node_t save_table = table;
    for(char *curr = file; curr < file + size;) {
        char *buff;
        strtok(curr, "\"");
        table->label = strtok(NULL, "\"");
        curr = strtok(NULL, " ") + 2;
        table->value = strtod(curr, &buff);
        if(buff == curr)
            break ;
        curr = buff;
        table->next = malloc(sizeof *table);
        table = table->next;
    }
    table->next = NULL;
    table = save_table;
    while(table->next) {
        printf("%s: %f\n", table->label, table->value);
        table = table->next;
    }
    for(table = save_table; table;) {
        node_t buff = table->next;
        free(table);
        table = buff;
    }
    close(fr);
    munmap(file - 2, size + 4);
    
    return 0;
}
