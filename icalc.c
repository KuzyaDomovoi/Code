#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#define NUMBER 1000
#define STEAKSIZE 1000
#define SIZE 100

int str_to_int(char str[]){ // the func converts the string to a number;
    int num = 0;
    int i;
    for(int i = 0; str[i] != '\0'; i++)
        num = num * 10 + (str[i] - '0');
    return num;
}

int get_op(char op[]) { // the func reads operators or operands;
    int c = 0; // var for the symbol storing;
    int i = 0; // the counter for the string op[];
    static int remember = 0; // the var 'remember' is set to '0' initially and then stores a current value entered by the func get_op();
    if(remember != 0) { // checking if the var 'remember' receives some value (not 0) then
        c = remember; // to the var 'c' is assigned a value of the var 'remember';
        remember = 0; // and then the var 'remember' will be reset to 0 again;
    }
    else
        c = getchar(); // if the var 'remember' is '0' then to the var 'c' is assigned a symbol read by the func getchar();
    
    while(c == ' ' || c == '\t') { // the loop skips the indentation or tabulation at beginn incase the var 'c' is a spacesymbol;
        c = getchar();
    }
    if(!isdigit(c)) // if the var 'c' is not a digit then 
        return c; // is returned a symbol or the '\n' from var 'c';
    
    if(isdigit(c)) { // check if var 'c' is a number;
        op[i] = c; // write the current number to str:
        while(isdigit(op[++i] = (c = getchar()))) // while the each next var 'c' is a number the loop is continue and the number is writted to the string op[];
            ;
        remember = c; // if the var 'c' has not digit(char) then to var 'remember' is assigned this symbol(char);
        op[i] = '\0'; // and 'no terminated sign' is writted at the end; 
        
        return NUMBER; // return the number in thr string op[];
    }
}

/*
typedef struct tag_obj {
    int data; // stored data (objects) in stack;
    struct tag_obj* next; // pointer next refers to the next following object in the stack;
    } OBJ; // new datatype of struct tag_obj;

OBJ* push(OBJ* top, int data) // the func push a new object in the stack
{
    OBJ* ptr = malloc(sizeof(OBJ)); // OBJ* ptr is a temporary pointer referring to allocated in HEAP the memory cells for a new object in stack;
    ptr->data = data; // using the temporary pointer copying a value of current data;
    printf("Added: %d\n", data); // for look up the currently added object to the stack;
    ptr->next = top; // pointer 'next' copies the address, that is, refers to next (top) object added via func push of the stack currently;
    return ptr; // via ptr is returned the address of a new added object in the stack;
}

OBJ* pop(OBJ* top) // the func pop pulls the current top object out the stack;
{
    if(top == NULL)
        return top;
    printf("Deleted: %d\n", top->data); // for look up the currently pulled object out the stack;
    OBJ* ptr_next = top->next; // assigning the address of the next lower object to the current top object;
    free(top); // makes free the allocated memory cells for the pulled current top object out the stack (deletes the current value of the top object);
    return ptr_next; // returns the address of the next lower object or the value NULL when no more object exists in the stack already;
}

void show(const OBJ* top) // the func shows the all objects in the stack;
{
    const OBJ* current = top; // temporary pointer for iterating the objs of stack; initially it refers to the top object;
    while (current != NULL) // loop while itarate the values until the current value will be equaled NULL;
    {
        printf("%d\n", current->data); // output the current object in the stack;
        current = current->next; // go to the next lower object in the stack or to the value NULL (than the loop will be end);
    }
}
*/

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
    char oper[SIZE]; // the string for operands or operators and is an argument for the func get_op();
    
    // code for checking the correct operation of the funcs added to the file 'functions.c':
    /*int result = get_op(op); // assigning a number or an arithmetic sign to the var 'result' wich are returned by the func get_op();
    printf("result of get_op = %d\n", result);
    printf("op[] = %s\n", op);
    printf("(int) result: %d", str_to_int(op));*/

    int op; // the var for the first operand or for an operator;
    int op2; // the var for the second operand;
    while((op = get_op(oper)) != 'x') { // if the char 'x' is entered the loop will end;
        switch(op) { // cheking the var op;
        case NUMBER: // if 'op' is a number
            push(str_to_int(oper)); // then push the number in steak;
            break;
        case '+':
            if((op2 = get_op(oper)) == NUMBER) // if the func get_op() returns a number
                op2 = str_to_int(oper); // to the var op2 is assigned the second operand(number) from the func str_to_int();
            else {
                printf("There must be a number\n");
                exit(1); // returns 1 (in stdlib.h) and exit;
            }
            push(get() + op2); // the operands will be calculated and pushed in the steak initially;
            break;
        case '-':
            if((op2 = get_op(oper)) == NUMBER) // if the func get_op() returns a number
                op2 = str_to_int(oper); // to the var op2 is assigned the second operand(number) from the func str_to_int();
            else {
                printf("There must be a number\n");
                exit(1); // returns 1 (in stdlib.h) and exit;
            }
            push(get() - op2); // the operands will be calculated and pushed in the steak initially;
            break;
        case '*':
            if((op2 = get_op(oper)) == NUMBER) // if the func get_op() returns a number
                op2 = str_to_int(oper); // to the var op2 is assigned the second operand(number) from the func str_to_int();
            else {
                printf("There must be a number\n");
                exit(1); // returns 1 (in stdlib.h) and exit;
            }
            push(get() * op2); // the operands will be calculated and pushed in the steak initially;
            break;
        case '/':
            if((op2 = get_op(oper)) == NUMBER) // if the func get_op() returns a number
                op2 = str_to_int(oper); // to the var op2 is assigned the second operand(number) from the func str_to_int();
            else {
                printf("There must be a number\n");
                exit(1); // returns 1 (in stdlib.h) and exit;
            }
            push(get() / op2); // the operands will be calculated and pushed in the steak initially;
            break;
        default:    
            printf("Unknown an operator or an operand\n");
            exit(1);
            break;
        }
    }
    
    return 0;
}
