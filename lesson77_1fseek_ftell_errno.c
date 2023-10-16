#include <stdio.h> // funcs: stderr, fseek, ftell;
#include <errno.h> // to use func errno;

int main(void)
{
    char buff[100]; 

    FILE* in = fopen("my_file.txt", "r"); 
    if(in == NULL) { 
        printf("errno: %d\n", errno);
        perror("my_file3.txt");
        return 1;
    }
    
    fseek(in, 0, SEEK_END); // seeks to a certain position on stream;
    int length = ftell(in); // returns current file-position of stream from whence(SEEK_END);

    for(int i = 1; i <= length; ++i) { // read all bytes from stream(file 'in');
        fseek(in, -i, SEEK_END); // sets the file position in stream from end(SEEK_END) to beginning(-i) of file 'in';
        putchar(fgetc(in)); // reads and outputs on dysplay the current char in file 'in';
    }
    
    putchar('\n');
    fclose(in); 
    
    return 0;
}
