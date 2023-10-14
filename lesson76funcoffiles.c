#include <stdio.h>

// func of files: fopen(), fclouse(), fgetc(), fputc();

// "r", "w", "a", "r+", "w+", "a+"; fopen() with acces to fileactions;
// "rb", "wb", "ab", "rb+", "wb+", "ab+"; fopen() with (..b)binary acces to faleactions;

int main(void)
{
    char str[] = "Function fputc() in action.";
    char buff[100]; // decl var buff for 100 chars;

    FILE* fp = fopen("my_file.txt", "w"); // create a FILE my_file.txt with w-acces;
    if(fp == NULL) // checking fileopening for errors; 
        return 1; // off func;
    for(int i = 0; i < str[i]; ++i) // iterate i-data(chars) to reading the str;
        fputc(str[i], fp); // put the chars of str in FILE;
    fclose(fp); // clouse the FILE 'fp' and store its data in file stream buffer;
    
    FILE* in = fopen("my_file.txt", "r"); // read the FILE my_file.txt with r-acces;
    if(in == NULL) // checking fileopening for errors;
        return 2; 
    
    char ch; // decl a new tenmorary variable ch;
    int i = 0; // decl a new temporary variable i = 0 (counter);
    while((ch = fgetc(in)) != EOF) // byte reading FILE 'in' until EOF using temp var ch;
        buff[i++] = ch; // put current char 'ch' of FILE 'in' to var buff[100];
    buff[i] = '\0'; // put char EOF;
    
    puts(buff); // output values of var buff[100];

    fclose(in); // clouse the FILE 'in' and store its data in file stream buffer;
    //fclose(fp);
    
    return 0;
}
