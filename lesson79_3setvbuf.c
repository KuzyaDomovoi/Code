#include <stdio.h>

// setvbuf() is the func that creats an own iobuffer while some file is opened by the func 'fopen()';
/*
int setvbuf(FILE * restrict stream, char * restrict buf, int mode, size_t size);

Здесь указатель buf – это адрес области памяти для буфера (если равен NULL, 
то буфер создается автоматически); mode – режим работы буфера; 
size – размер буфера в байтах. 

Режимы определены следующими константами:
    _IOFBF – полная буферизация (очистка после заполнения буфера);
    _IOLBF – построчная буферизация (очистка по символу переноса строки);
    _IONBF – выключение буферизации.

Функция setvbuf() должна вызываться после создания потока, но перед 
использованием какой-либо операции записи/чтения данных из этого потока;
*/

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

    if(setvbuf(fp, buffer, _IOFBF, buffer_size) != 0) { // condition for errors: if the func 'setvbuf()' return 1 (!= 0) then
        puts("Incorrect type or size of buffer"); // output a message about error; else transfer to the next statement;
        return 2;
    }
 
    fgets(data, sizeof(data), fp); // reading a current string from file 'fp' by the func 'fgets()';
    puts(buffer); // output all data currently contained in the buffer;
    puts("----------------"); // sepatate line;
    puts(data); // output the current string from the file 'fp') read by the func 'fgets()';
 
    fclose(fp); 
    return 0;
}
