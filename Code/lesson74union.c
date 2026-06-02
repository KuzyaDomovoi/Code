#include <stdio.h>

// union is a keyword for storing of only the last saved volume in the memory cells with single cell's address for each variable;
// the keyword allows to save memory space when the large volumes of vars are used;

union tag_var {
    char var_ch;
    int var_i;
    double var_d;
};

typedef enum {
    union_var_none, union_var_ch, union_var_i, union_var_d
} TYPE_VAR;

typedef struct {
    union  tag_var var;
    TYPE_VAR type;
} VAR;

//void show_var(union  tag_var v, TYPE_VAR type)
void show_var(VAR v)
{
    //switch(type) {
    switch(v.type) {
    case union_var_ch:
        //printf("var_ch = %c\n", v.var_ch);
        printf("var_ch = %c\n", v.var.var_ch);
        break;
    case union_var_i:
        //printf("var_i = %d\n", v.var_i);
        printf("var_i = %d\n", v.var.var_i);
        break;
    case union_var_d:
        //printf("var_d = %.2f\n", v.var_d);
        printf("var_d = %.2f\n", v.var.var_d);
        break;
    case union_var_none:
        printf("Undefined type var");
        break;
    }
}

int main(void)
{
    //union tag_var var;
    VAR var;

    //var.var_ch = 'c';
    //var.var_i = 45;
    var.var.var_ch = 'c';
    var.type = union_var_ch;
    
    //show_var(var, union_var_i);
    //show_var(var, union_var_ch);
    show_var(var);
    
    return 0;
}
