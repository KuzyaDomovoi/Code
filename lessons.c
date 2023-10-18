//my first program;

#include <stdio.h> /* <standart input output.header>
                    (int printf(...));*/

int main(void) /* int - integer datatype; 
                main - function(parameter);
                (if no one parameter specified,
                the keyword "viod" must be inserted);*/
{ //start of program body;
    char byte_memory; // char is a keyword of the datatype; byte_memory is a variable;
    byte_memory = 100; // 100 is a value of the variable;
    char a; // a is a variable;
    a = byte_memory; // one variable copies the value of another variable;
    
    printf("Hello, world!\n"); /* printf("") - print formated
                                is a statement for data output on display;
                                \n - after this symbol the next statement translats to a new line;
                                (Sequence of the statements from top to bottom);*/
    return 0; /* end of function main with exit[code] == "0"(no errors);*/
} //end of program body;
  
// gcc -std=c99 -o outputfiie sourcefile.c