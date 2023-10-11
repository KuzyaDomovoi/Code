#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MARKS {4, 5, 5, 5, 5, 4, 5, 4, 5, 5, 5, 5, 5, 5, 5};

enum {name_length = 50, b_length = 20};

struct tag_fio { 
    char name[name_length];
    char last[name_length];
};

struct tag_person { 
    struct tag_fio fio;
    char sex;
    unsigned short old;
    char birstday_date[b_length];
};

//struct tag_array {
    //int marks[b_length];
//};

void* append(short* data, size_t *length, size_t *capacity, short value)
{
    if(*length >= *capacity) {
        short* ar = malloc(sizeof(short) * 2 * *capacity);
        if(ar == NULL)
            return data;
            
        (*capacity) *= 2;
        for(int i = 0;i < *length;++i)
            ar[i] = data[i];
        
        free(data);
        data = ar;
    }
 
    data[*length] = value;
    (*length)++;
    
    return data;
}

int main(void)
{
    struct tag_person person = {
        {"Vasily", "Shtanko"},
        'M',
        98,
        "32.06.1925"
    };

    person.old = 43;
    strcpy(person.birstday_date, "04.06.1980"); // one-dim array;

    struct tag_person p;
    p = person;

    printf("name: %s\nlast: %s\n", p.fio.name, p.fio.last);
    printf("sex: %c\nbirstday_date: %s\n", p.sex, p.birstday_date);
    printf("old: %d\n", p.old);
    printf("marks: ");

    //struct tag_array marks_1 = {4, 5, 5, 4, 5, 5, 4, 5, 5, 5, 5, 4, 5, 5};
    //struct tag_array marks_2;
    //marks_2 = marks_1;
    //for(int i = 0; i < sizeof(marks_2.marks) / sizeof(*marks_2.marks); ++i)
        //printf("%d ", marks_2.marks[i]);

    size_t capacity = 10;
    size_t length = 0;
 
    short* data = malloc(sizeof(short) * capacity);
    short marks[] = MARKS;

    for(int i = 0; i < sizeof(marks) / sizeof(*marks); ++i)
        data = append(data, &length, &capacity, marks[i]);

    for(int i = 0; i < length; ++i)
        printf("%d ", data[i]);
    free(data);

    return 0;
}
