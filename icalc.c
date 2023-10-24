#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#define NUMBER 1000
#define STEAKSIZE 100
#define SIZE 100

int str_to_int(char str[]) { // the func converts the string to a number;
    int num = 0;
    int i;
    for(int i = 0; str[i] != '\0'; i++)
        num = num * 10 + (str[i] - '0');
    return num;
}

int get_symb(char symb[]) { // the func reads operators or operands;
    int ch = 0; // var for the symbol storing;
    static int remember = 0; // the var 'remember' is set to '0' initially and then stores a current value entered by the func get_symb();
    int i = 0; // the counter for the string symb[];
    if(remember != 0) { // checking if the var 'remember' receives some value (not 0) then
        ch = remember; // to the var 'ch' is assigned a value of the var 'remember';
        remember = 0; // and then the var 'remember' will be reset to 0 again;
    }else
        ch = getchar(); // if the var 'remember' is '0' then to the var 'ch' is assigned a symbol read by the func getchar();

    while(ch == ' ' || ch == '\t') { // the loop skips the indentation or tabulation at beginn incase the var 'ch' is a spacesymbol;
        ch = getchar();
    }
    if(!isdigit(ch)) // if the var 'ch' is not a digit then 
        return ch; // is returned a symbol or the '\n' from var 'ch';
    
    if(isdigit(ch)) { // check if var 'ch' is a number;
        symb[i] = ch; // write the current number to str:
        while(isdigit(symb[++i] = (ch = getchar()))) // while the each next var 'ch' is a number the loop is continue and the number is writted to the string symb[];
            ;
        remember = ch; // a value of the var 'ch' is assigned to the var 'remember';
        symb[i] = '\0'; // and 'no terminated sign' is writted at the end; 
        
        return NUMBER; // return the number in the string symb[];
    }
}

int steak[STEAKSIZE]; // the array for the steak creating with a size 'STEAKSIZE 100';
int free_si = 0; // checking a free memory cell in the steak;

void push(int n) { // the func puts the var 'n' to the steak;
    if(free_si < STEAKSIZE) // size comparision of the var 'n' and the steak(100):
        steak[free_si++] = n; // if a free memory cell is available the value 'n' will put to the steak;
    else
        printf("Error! Steak is overflow!");
}

int get(void) { // returns the last saved number from the steak;
    if(free_si > 0) // if the steak has some value(is not empty) then
        return steak[--free_si]; // ('--free_si' is a previous index in steak because the index free_si itself points to the last memory cell in the steak) is returned the last saved number from the steak; 
    else
        printf("Error! Steak is empty!");
}

int main(void)
{
    char oper[SIZE]; // the string for operators and is an argument for the func get_symb();
    int op, op2; // the vars for the operands;
    while((op = get_symb(oper)) != 'x') { // if 'x' - exit program;
        switch(op) { // cheking the var op;
        case NUMBER: // if 'op' is a number
            push(str_to_int(oper)); // then push the number in steak;
            break;
        case '+':
            if((op2 = get_symb(oper)) == NUMBER) // if the func get_symb() returns a number
                op2 = str_to_int(oper); // to the var op2 is assigned the second operand(number) from the func str_to_int();
            else {
                printf("There must be a number\n");
                exit(1); // returns 1 (in stdlib.h) and exit;
            }
            push(get() + op2); // the operands will be calculated and pushed in the steak initially;
            break;
        case '-':
            if((op2 = get_symb(oper)) == NUMBER) 
                op2 = str_to_int(oper); 
            else {
                printf("There must be a number\n");
                exit(1); 
            }
            push(get() - op2);
            break;
        case '*':
            if((op2 = get_symb(oper)) == NUMBER) 
                op2 = str_to_int(oper); 
            else {
                printf("There must be a number\n");
                exit(1);
            }
            push(get() * op2);
            break;
        case '/':
            if((op2 = get_symb(oper)) == NUMBER) 
                op2 = str_to_int(oper);
            else {
                printf("There must be a number\n");
                exit(1);
            }
            push(get() / op2);
            break;
        default:    
            printf("Unknown operator or operand\n");
            exit(1);
            break;
        }
    }

    return 0;
}
