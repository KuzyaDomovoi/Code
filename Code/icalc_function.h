#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>

#define NUMBER 1000
#define STEAKSIZE 100
#define SIZE 100
#define SIN 9 // because in according with the table ASCI number '10' means the '\0';
#define COS 20
#define SQRT 30
#define POW 40
#define CLEAN 50

// convertation string to number:
int str_to_int(char str[]) { // the func converts a string to a number;
    int num = 0;
    int i = 0;
    int sign = (str[i] == '-') ? -1 : 1; // if a current char has the sign minus ('-') then it is equal as '-1' esle as '1';
    if(str[i] == '-') // if the sign is negative then
        i++; // go to next char in the str[];
    for(; str[i] != '\0'; i++) // incase the current char is not EOF
        num = num * 10 + (str[i] - '0'); // transfers a char to a number;
        return num * sign; // returns the sign to number (num * (-1) = -num);
}

// users input of stream of symbols:
int get_symb(char symb[]) { // the func reads operators or operands;
    int ch = 0; // var for the symbol storing;
    static int remember = 0; // the var 'remember' is set to '0' initially and then stores a current value entered by the func get_symb();
    int i = 0; // the counter for the string symb[];
    if(remember != 0) { // checking if the var 'remember' receives some value (not 0) then
        ch = remember; // to the var 'ch' is assigned a value of the var 'remember';
        remember = 0; // and then the var 'remember' will be reset to 0 again;
    } 
    else
        ch = getchar(); // if the var 'remember' is '0' then to the var 'ch' is assigned a symbol read by the func getchar();
    if(ch == '-') {
        symb[i] = ch; // incase the first symb is minus then it will be writted in the string symb[] as '-';
        if(isdigit(symb[++i] = (ch = getchar()))) { // if the next char is number then it is a negative number supposedly and is assigned to ch;
            while(isdigit(symb[++i] = (ch = getchar()))) // while the current var 'ch' is a number the loop is continue and the number is writted to the string symb[];
                ;
            remember = ch; // a value of the var 'ch' is assigned to the var 'remember';
            symb[i] = '\0'; // and 'no terminated sign' is writted at the end of the srting symb[]; 
            return NUMBER; // return a negative number in the string symb[];
        } 
        else // if the var 'ch' is no digit
            return ch; // then var 'ch' will be return as an operator '-'(arithmetic sign);
    } 
    while(ch == ' ' || ch == '\t') { // the loop skips the indentation or tabulation at beginn incase the var 'ch' is a spacesymbol;
        ch = getchar();
    }        
    if(ch >= 97 && ch <= 122) { // from the table ASCI the numbers 65 and 90 are for uppercase letters and 97 and 122 for the lowercase letters;
        symb[i++] = ch;
        for(; i < SIZE && (ch = getchar()) != ' ' && ch != '\n' && !isdigit(ch); i++)
            symb[i] = ch; // filling the string symb[] with current chars;
        symb[i] = '\0';
        if(sin_check(symb)) // check if is called the comman SIN;
            return SIN;
        if(cos_check(symb)) // check if is called the comman COS;
            return COS;
        if(sqrt_check(symb)) // check if is called the comman SQRT;
            return SQRT;
        if(pow_check(symb)) // check if is called the comman POW;
            return POW;
        if(clean_check(symb)) // check if is called the comman CLEAN;
            return CLEAN;
    }
    if(isdigit(ch)) { // check if var 'ch' is a number;
        symb[i] = ch; // write the current number to the string symb[]:
        while(isdigit(symb[++i] = (ch = getchar()))) // while the current var 'ch' is a number the loop is continue and the number is writted to the string symb[];
            ;
        remember = ch; // a value of the var 'ch' is assigned to the var 'remember';
        symb[i] = '\0'; // and 'no terminated sign' is writted at the end of the srting symb[]; 
        return NUMBER; // return a positive number in the string symb[];
    }
    else 
        return ch; // returns others arithmetic signs;
}

// steak:
int steak[STEAKSIZE]; // the array for the steak creating with a size 'STEAKSIZE 100';
int free_si = 0; // checking a free memory cell in the steak;

void push(int n) { // the func puts the var 'n' to the steak;
    if(free_si < STEAKSIZE) // size comparision of the var 'n' and the steak(100):
        steak[free_si++] = n; // if a free memory cell is available the value 'n' will put to the steak;
    else {
        printf("Error! Steak is overflow!");
        exit(1);
    }
}
int get(void) { // returns the last saved number from the steak;
    if(free_si > 0) // if the steak has some value(is not empty) then
        return steak[--free_si]; // ('--free_si' is a previous index in steak because the index free_si itself points to the last memory cell in the steak) is returned the last saved number from the steak; 
    else {
        printf("Error! Steak is empty!");
        exit(1);
    }
}

//commands:
char sin_symb[] = "sin";
char cos_symb[] = "cos";
char sqrt_symb[] = "sqrt";
char pow_symb[] = "pow";
char clean[] = "clean";

// checking the string 1 and string 2 to coincidence (string comparation(cmpstr)):
int check_strings(char str_1[], char str_2[]) {
    int i, j;
    for(i = 0, j = 0; str_1[i] != '\0' && str_2[j] != '\0'; i++, j++) {
        if(str_1[i] != str_2[j]) 
            return 0; // the strings are not equal;
    }
    if(str_1[i] != '\0' || str_2[j] != '\0') // if the stings are equal initially then go to check the EOF coincidence by the srtings:
        return 0; // the strings are not equal by EOF only;

    return 1; // the strings are fully equal;
}

// cheking the strings to their coincidence with commands:
int sin_check(char s[]) {
    return check_strings(sin_symb, s); // ... input str s with the command sin_symb;
}
int cos_check(char s[]) {
    return check_strings(cos_symb, s); // ... input str s with the command cos_symb;
}
int sqrt_check(char s[]) {
    return check_strings(sqrt_symb, s); // ... input str s with the command sqrt_symb;
}
int pow_check(char s[]) {
    return check_strings(pow_symb, s); // ...  input str s with the command pow_symb;
}
int clean_check(char s[]) {
    return check_strings(clean, s); // ... input str s with the command clean;
}

void clean_steak_command(void) { // cleaning of the steak;
    int free_si = 0;
    printf("Steak is cleaned\n");
    return;
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
                if((op2 = str_to_int(oper)) != 0);
            else {
                printf("There must be a number or it is ZeroDevisionError!\n");
                exit(1);
            }
            push(get() / op2);
            break;
        case '\n':
            printf("Result = %d\n", get());
            break;
        case SIN:
            if((op = get_symb(oper)) == NUMBER)
                op = str_to_int(oper);
            else {
                printf("There must be a number\n");
                exit(1);
            }
            printf("Result = %f\n", sin(op));
            exit(0);
            break;
        case COS:
            if((op = get_symb(oper)) == NUMBER)
                op = str_to_int(oper);
            else {
                printf("There must be a number\n");
                exit(1);
            }
            printf("Result = %f\n", cos(op));
            exit(0);
            break;
        case SQRT:
            if((op = get_symb(oper)) == NUMBER)
                op = str_to_int(oper);
            else {
                printf("There must be a number\n");
                exit(1);
            }
            push(sqrt(op));
            break;
        case POW:
            if((op2 = get_symb(oper)) == NUMBER)
                op2 = str_to_int(oper);
            else {
                printf("There must be a number\n");
                exit(1);
            }
            push(pow(get(), op2));
            break;
        case CLEAN:
            clean_steak_command();
            break;    
        default:    
            printf("Unknown operator or operand\n");
            exit(1);
            break;
        }
    }

    return 0;
}
