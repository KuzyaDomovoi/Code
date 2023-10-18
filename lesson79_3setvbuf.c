#include <stdio.h>

// setvbuf() is the func that creats an own iobuffer while some file is opened by the func 'fopen()';
/*
int setvbuf(FILE * restrict stream, char * restrict buf, int mode, size_t size);
Здесь указатель buf – это адрес области памяти для буфера (если равен NULL, 
то буфер создается автоматически); mode – режим работы буфера; 
size – размер буфера в байтах. Режимы определены следующими константами:

    _IOFBF – полная буферизация (очистка после заполнения буфера);
    _IOLBF – построчная буферизация (очистка по символу переноса строки);
    _IONBF – выключение буферизации.
    
Функция setvbuf() должна вызываться после создания потока, но перед 
использованием какой-либо операции записи/чтения данных из этого потока;
*/
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
