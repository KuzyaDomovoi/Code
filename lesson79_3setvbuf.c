#include <stdio.h>

/* setvbuf() is the func that creats an own iobuffer while some file is opened by the func 'fopen()';

int setvbuf(FILE * restrict stream, char * restrict buf, int mode, size_t size);

The pointer buf – is an address of memory cell for buffer (if it is NULL, 
then buffer is created automatically);
mode – buffer operating mode; 
size – buffer size in bytes. 

Buffer operating modes are defined by the fillowing constants:
    _IOFBF – full buffering (cleaning after buffer is full);
    _IOLBF – line buffering (cleaning by line break);
    _IONBF – no buffering;

The func setvbuf() must be called after creating a stream but befor
using any write/read data opetation from this stream;*/

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

    if(setvbuf(fp, buffer, _IOFBF, buffer_size) != 0) { // if the func 'setvbuf()' return 1 (!= 0) then is performed
        puts("Incorrect type or size of buffer"); // an output a message about error; else - transfer to the next statement;
        return 2;
    }
 
    fgets(data, sizeof(data), fp); // reading a current string from file 'fp' by the func 'fgets()';
    puts(buffer); // output all data currently contained in the buffer;
    puts("----------------"); // sepatate line;
    puts(data); // output the current string from the file 'fp') read by the func 'fgets()';
 
    fclose(fp); 
    return 0;
}
