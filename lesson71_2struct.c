#include <stdio.h>
#include <string.h>

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

struct tag_array {
    int marks[b_length];
};

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

    printf("name: %s, last: %s\n", p.fio.name, p.fio.last);
    printf("sex: %c, birstday_date: %s\n", p.sex, p.birstday_date);
    printf("old: %d\n", p.old);

    struct tag_array marks_1 = {4, 5, 5, 4, 5, 5};
    struct tag_array marks_2;
    marks_2 = marks_1;
    for(int i = 0; i < sizeof(marks_2.marks) / sizeof(*marks_2.marks); ++i)
        printf("%d", marks_2.marks[i]);

    return 0;
}
