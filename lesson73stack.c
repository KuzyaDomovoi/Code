#include <stdio.h>
#include <stdlib.h>

// stack (LIFO - last in first out);

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

int main(void)
{
    OBJ* top = NULL; // pointer OBJ refers to an initial (or top) object in the stack; if it is equall NULL than stack is empty or it refers to the end of the stack;
    top = push(top, 1); // assigning (adding) the address of new object; 
    top = push(top, 2);
    top = push(top, 3);
    top = push(top, 4);

    show(top);

    while(top)
        top = pop(top);
   
    return 0;
}
