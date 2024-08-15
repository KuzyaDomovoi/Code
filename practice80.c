#include <stdio.h>

enum {name_size = 50}; 
enum {name_size_r = 50, max_rows = 200};

typedef struct
{
    char name[name_size];
    int x;
} ROW; 
 
int main(void)
{
        ROW contact[] = {
        {"Аверьянов A.A.",    1234567890},
        {"Акименко A.A.",     1234567890},
        {"Андроненкова A.A.", 1234567890},
        {"Антипова A.A.",     1234567890},
        {"Антишкин A.A.",     1234567890},
        {"Артемьев A.A.",     1234567890},
        {"Артюшенков A.A.",   1234567890},
        {"Ателье A.A.",       1234567890},
        {"Бабенко A.A.",      1234567890},
        {"Белоусов A.A.",     1234567890},
        {"Бобырин A.A.",      1234567890},
        {"Боев A.A.",         1234567890},
        {"Браженис A.A.",     1234567890},
        {"Вадим A.A.",        1234567890},
        {"Валдемар A.A.",     1234567890},
        {"Вергун A.A.",       1234567890},
        {"Виталий A.A.",      1234567890},
        {"Владимир A.A.",     1234567890},
        {"Вовк A.A.",         1234567890},
        {"Вовкодав A.A.",     1234567890},
        {"Военкомат A.A.",    1234567890},
        {"Волхв A.A.",        1234567890},
        {"Воронков A.A.",     1234567890},
        {"ВУНЦ",              1234567890},
        {"Вытовтов A.A.",     1234567890},
    };
 
    FILE* fp = fopen("/home/kuzya/Documents/k/google_1.csv", "wb");
    if(fp == NULL) {
        perror("google_1.csv");
        return 1;
    }
 
    int res = fwrite(contact, sizeof(ROW), sizeof(contact) / sizeof(*contact), fp); 
    
    fclose(fp);
 
    printf("contacts_number = %d\n", res);

    ROW r_contact[max_rows];
    int length = 0; 
 
    FILE* fr = fopen("/home/kuzya/Documents/k/google_1.csv", "rb"); 
    if(fr == NULL) {
        perror("google_1.csv");
        return 1;
    }
 
    while(fread(&r_contact[length], sizeof(ROW), 1, fr) == 1) 
        length++;
 
    fclose(fr);
 
    for(int i = 0; i < length; ++i)
        printf("%s: %d\n", r_contact[i].name, r_contact[i].x);
 
    return 0;
}
