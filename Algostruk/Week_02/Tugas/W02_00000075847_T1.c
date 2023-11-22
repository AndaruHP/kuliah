#include<stdio.h>
#include<stdlib.h>

struct student {
    char nama[50];
    char major[50];
    float gpa;
};

void add(struct student mahasiswa[], int *data){
    system("cls");
    if(*data < 20){
        printf("\tInsert Student Information\n");
        printf("-----------------------------------------\n");
        printf("Nama\t: "); scanf("%[^\n]", mahasiswa[*data].nama);
        printf("Jurusan\t: "); scanf("%s", mahasiswa[*data].major);
        printf("IPK\t: "); scanf("%f", &mahasiswa[*data].gpa);
        (*data)++;
        getchar();
    } else {
        printf("Kapasitas penuh\n");
    }
}

void show(struct student mahasiswa[], int *data){
    system("cls");
    printf("\t\tList of Student Information\n");
    printf("----------------------------------------------------------------------------\n");
    printf("| No. |              Name               |           Major           | GPA  |\n");
    printf("----------------------------------------------------------------------------\n");
    for(int i = 0; i < *data; i++){
        printf("|%4d | %-31s | %-25s | %4.2f |\n", i + 1, mahasiswa[i].nama, mahasiswa[i].major, mahasiswa[i].gpa);
    }
}

int main(){
    int pilihan = 0 , data = 0;
    struct student mahasiswa[20];

    while(pilihan != 3){
        //system("cls");
        printf("Welcome to simple student database (%d/20)\n", data);
        printf("1. Show all students\n2. Input new student\n3. Exit\nChoose: ");
        scanf("%d", &pilihan);
        getchar();
        switch(pilihan){
            case 1:

                show(mahasiswa, &data);
                break;
            case 2:

                add(mahasiswa, &data);
                break;
            case 3:

                printf("Program Selesai\n");
                break;
            default:
                break;
        }
    }
    return 0;
}
