#include <stdio.h>

// func of files: fopen(), fclouse(), fgetc(), fputc();

// "r", "w", "a", "r+", "w+", "a+"; fopen() with acces to fileactions;
// "rb", "wb", "ab", "rb+", "wb+", "ab+"; fopen() with (..b)binary acces to faleactions;

/*
r 	Read-only. Beginning of the file;
r+ 	Read and write (updating). Beginning of the file;
w 	Write-only (overwrite or create). Beginning of the file;
w+ 	Write and read (overwrite or create). Beginning of the file;
a 	Append-only (append or create). End of the file;
a+ 	Append and read (append or create). End of the file;
*/

int main(void)
{
    char str[] = "Function fputc() in action with w-acces.";
    char str_2[] = "Function fputc() in action with w+-acces.";
    char str_3[] = "Function fputc() in action with a-acces.";
    char str_4[] = "Function fputc() in action with a+-acces.";
    char buff[200]; // decl var buff for 100 chars;
    
    FILE* fp = fopen("my_file.txt", "w"); // create a FILE my_file.txt with w-acces;
    if(fp == NULL) // checking fileopening for errors; 
        return 1; // return if could not open the FILE;
    for(int i = 0; i < str[i]; ++i) // iterate i-data(chars) to reading the var str;
        fputc(str[i], fp); // put the chars of the var str in the FILE 'fp';
    fclose(fp); // clouse the FILE 'fp' and store its data in file stream buffer;

     FILE* fpp = fopen("my_file.txt", "w"); 
    if(fpp == NULL)
        return 2; 
    for(int i = 0; i < str_2[i]; ++i) 
        fputc(str_2[i], fpp);
    fclose(fpp);
    
    FILE* fa = fopen("my_file.txt", "a");
    if(fa == NULL)
        return 3;
    for(int i = 0; i < str_3[i]; ++i)
        fputc(str_3[i], fa);
    fclose(fa);

    FILE* faa = fopen("my_file.txt", "a+");
    if(faa == NULL)
        return 4;
    for(int i = 0; i < str_4[i]; ++i)
        fputc(str_4[i], faa);
    fclose(faa);

    FILE* in = fopen("my_file.txt", "r"); // read the FILE 'my_file.txt' with r-acces;
    if(in == NULL) // checking fileopening for errors;
        return 4;

    char ch; // declaration a new tenmorary variable ch;
    int i = 0; // declaration a new temporary variable i = 0 (counter);
    while((ch = fgetc(in)) != EOF) // byte reading the FILE 'in' until EOF using the temp var ch;
        buff[i++] = ch; // put the current char 'ch' of the FILE 'in' in the var buff[100];
    buff[i] = '\0'; // put the char EOF;
    
    puts(buff); // output values of the var buff[100];
    
    fclose(in); // clouse the FILE 'in' and store its date in file stream buffer;
    //fclose(fp);
    
    return 0;
}
